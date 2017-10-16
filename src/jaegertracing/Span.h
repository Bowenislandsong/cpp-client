/*
 * Copyright (c) 2017 Uber Technologies, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef JAEGERTRACING_SPAN_H
#define JAEGERTRACING_SPAN_H

#include <chrono>
#include <memory>
#include <mutex>

#include <opentracing/span.h>

#include "jaegertracing/LogRecord.h"
#include "jaegertracing/Reference.h"
#include "jaegertracing/SpanContext.h"
#include "jaegertracing/Tag.h"
#include "jaegertracing/thrift-gen/jaeger_types.h"

namespace jaegertracing {

class Tracer;

class Span : public opentracing::Span {
  public:
    using Clock = std::chrono::steady_clock;

    Span(const std::weak_ptr<const Tracer>& tracer,
         const SpanContext& context,
         const std::string& operationName,
         const Clock::time_point& startTime,
         const Clock::duration& duration,
         const std::vector<Tag>& tags,
         const std::vector<Reference>& references,
         bool firstInProcess)
        : _tracer(tracer)
        , _context(context)
        , _operationName(operationName)
        , _startTime(startTime)
        , _duration(duration)
        , _references(references)
    {
    }

    Span(const Span& span)
    {
        std::lock(_mutex, span._mutex);
        std::lock_guard<std::mutex> lock(_mutex, std::adopt_lock);
        std::lock_guard<std::mutex> spanLock(span._mutex, std::adopt_lock);

        _context = span._context;
        _operationName = span._operationName;
        _startTime = span._startTime;
        _duration = span._duration;
        _tags = span._tags;
        _logs = span._logs;
        _references = span._references;
    }

    // Pass-by-value intentional to implement copy-and-swap.
    Span& operator=(Span rhs)
    {
        swap(rhs);
        return *this;
    }

    void swap(Span& span)
    {
        using std::swap;

        std::lock(_mutex, span._mutex);
        std::lock_guard<std::mutex> lock(_mutex, std::adopt_lock);
        std::lock_guard<std::mutex> spanLock(span._mutex, std::adopt_lock);

        swap(_context, span._context);
        swap(_operationName, span._operationName);
        swap(_startTime, span._startTime);
        swap(_duration, span._duration);
        swap(_tags, span._tags);
        swap(_logs, span._logs);
        swap(_references, span._references);
    }

    friend void swap(Span& lhs, Span& rhs) { lhs.swap(rhs); }

    thrift::Span thrift() const
    {
        std::lock_guard<std::mutex> lock(_mutex);
        thrift::Span span;
        span.__set_traceIdHigh(_context.traceID().high());
        span.__set_traceIdLow(_context.traceID().low());
        span.__set_spanId(_context.spanID());
        span.__set_parentSpanId(_context.parentID());
        span.__set_operationName(_operationName);

        std::vector<thrift::SpanRef> refs;
        refs.reserve(_references.size());
        std::transform(std::begin(_references),
                       std::end(_references),
                       std::back_inserter(refs),
                       [](const Reference& ref) { return ref.thrift(); });
        span.__set_references(refs);

        span.__set_flags(_context.flags());
        span.__set_startTime(
            std::chrono::duration_cast<std::chrono::microseconds>(
                _startTime.time_since_epoch())
                .count());
        span.__set_duration(
            std::chrono::duration_cast<std::chrono::microseconds>(_duration)
                .count());

        std::vector<thrift::Tag> tags;
        tags.reserve(_tags.size());
        std::transform(std::begin(_tags),
                       std::end(_tags),
                       std::back_inserter(tags),
                       [](const Tag& tag) { return tag.thrift(); });
        span.__set_tags(tags);

        std::vector<thrift::Log> logs;
        logs.reserve(_logs.size());
        std::transform(std::begin(_logs),
                       std::end(_logs),
                       std::back_inserter(logs),
                       [](const LogRecord& log) { return log.thrift(); });
        span.__set_logs(logs);

        return span;
    }

    template <typename Stream>
    void print(Stream& out) const
    {
        std::lock_guard<std::mutex> lock(_mutex);
        out << _context;
    }

    std::string operationName() const
    {
        std::lock_guard<std::mutex> lock(_mutex);
        return _operationName;
    }

    Clock::time_point startTime() const
    {
        std::lock_guard<std::mutex> lock(_mutex);
        return _startTime;
    }

    Clock::duration duration() const
    {
        std::lock_guard<std::mutex> lock(_mutex);
        return _duration;
    }

    std::vector<Tag> tags() const
    {
        std::lock_guard<std::mutex> lock(_mutex);
        return _tags;
    }

    template <typename... Arg>
    void setOperationName(Arg&&... args)
    {
        SetOperationName(std::forward<Arg>(args)...);
    }

    void FinishWithOptions(const opentracing::FinishSpanOptions&
                               finishSpanOptions) noexcept override;

    void SetOperationName(opentracing::string_view name) noexcept override
    {
        std::lock_guard<std::mutex> lock(_mutex);
        if (isFinished()) {
            return;
        }
        _operationName = name;
    }

    void SetTag(opentracing::string_view key,
                const opentracing::Value& value) noexcept override
    {
        std::lock_guard<std::mutex> lock(_mutex);
        if (isFinished() || !_context.isSampled()) {
            return;
        }
        _tags.push_back(Tag(key, value));
    }

    void SetBaggageItem(opentracing::string_view restrictedKey,
                        opentracing::string_view value) noexcept override;

    std::string BaggageItem(opentracing::string_view restrictedKey) const
        noexcept override
    {
        std::lock_guard<std::mutex> lock(_mutex);
        auto itr = _context.baggage().find(restrictedKey);
        return (itr == std::end(_context.baggage())) ? std::string()
                                                     : itr->second;
    }

    void Log(std::initializer_list<
             std::pair<opentracing::string_view, opentracing::Value>>
                 fieldPairs) noexcept override
    {
        std::lock_guard<std::mutex> lock(_mutex);
        if (!_context.isSampled()) {
            return;
        }

        std::vector<Tag> fields;
        fields.reserve(fieldPairs.size());
        std::transform(
            std::begin(fieldPairs),
            std::end(fieldPairs),
            std::back_inserter(fields),
            [](const std::pair<opentracing::string_view, opentracing::Value>&
                   pair) { return Tag(pair.first, pair.second); });
        logFieldsNoLocking(std::begin(fields), std::end(fields));
    }

    const SpanContext& context() const noexcept override
    {
        std::lock_guard<std::mutex> lock(_mutex);
        return _context;
    }

    const opentracing::Tracer& tracer() const noexcept override;

    std::string serviceName() const noexcept;

  private:
    bool isFinished() const { return _duration != Clock::duration(); }

    template <typename FieldIterator>
    void logFieldsNoLocking(FieldIterator first, FieldIterator last) noexcept
    {
        LogRecord log(Clock::now(), first, last);
        _logs.push_back(log);
    }

    std::weak_ptr<const Tracer> _tracer;
    SpanContext _context;
    std::string _operationName;
    Clock::time_point _startTime;
    Clock::duration _duration;
    std::vector<Tag> _tags;
    std::vector<LogRecord> _logs;
    std::vector<Reference> _references;
    mutable std::mutex _mutex;
};

}  // namespace jaegertracing

inline std::ostream& operator<<(std::ostream& out,
                                const jaegertracing::Span& span)
{
    span.print(out);
    return out;
}

#endif  // JAEGERTRACING_SPAN_H
