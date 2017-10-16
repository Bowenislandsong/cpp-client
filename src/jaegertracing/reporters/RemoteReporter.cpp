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

#include "jaegertracing/reporters/RemoteReporter.h"

namespace jaegertracing {
namespace reporters {

RemoteReporter::RemoteReporter(std::unique_ptr<Transport>&& sender,
                               const ReporterOptions& reporterOptions)
    : _reporterOptions(reporterOptions)
    , _sender(std::move(sender))
    , _queue()
    , _queueLength(0)
    , _running(true)
    , _lastFlush(Clock::now())
    , _cv()
    , _mutex()
    , _thread()
{
    _thread = std::thread([this]() { sweepQueue(); });
}

void RemoteReporter::report(const Span& span)
{
    std::unique_lock<std::mutex> lock(_mutex);
    const auto pushed =
        (static_cast<int>(_queue.size()) < _reporterOptions.queueSize());
    if (pushed) {
        _queue.push_back(span);
        lock.unlock();
        _cv.notify_one();
        ++_queueLength;
    }
    else {
        _reporterOptions.metrics()->reporterDropped().inc(1);
    }
}

void RemoteReporter::close()
{
    {
        std::unique_lock<std::mutex> lock(_mutex);
        if (!_running) {
            return;
        }
        _running = false;
        lock.unlock();
        _cv.notify_one();
    }
    _thread.join();
}

void RemoteReporter::sweepQueue()
{
    while (true) {
        std::unique_lock<std::mutex> lock(_mutex);
        _cv.wait(lock, [this]() {
            return !_running || !_queue.empty() || bufferFlushIntervalExpired();
        });

        if (!_running && _queue.empty()) {
            return;
        }

        if (!_queue.empty()) {
            const auto span = _queue.front();
            _queue.pop_front();
            sendSpan(span);
        }
        else if (bufferFlushIntervalExpired()) {
            flush();
        }
    }
}

void RemoteReporter::sendSpan(const Span& span)
{
    --_queueLength;
    try {
        const auto flushed = _sender->append(span);
        if (flushed > 0) {
            _reporterOptions.metrics()->reporterSuccess().inc(flushed);
            _reporterOptions.metrics()->reporterQueueLength().update(
                _queueLength);
        }
    } catch (const Transport::Exception& ex) {
        _reporterOptions.metrics()->reporterFailure().inc(ex.numFailed());
        const auto& logger = _reporterOptions.logger();
        assert(logger);
        logger->error(fmt::format(
            "error reporting span {0}: {1}", span.operationName(), ex.what()));
    }
}

void RemoteReporter::flush()
{
    try {
        const auto flushed = _sender->flush();
        if (flushed > 0) {
            _reporterOptions.metrics()->reporterSuccess().inc(flushed);
        }
    } catch (const Transport::Exception& ex) {
        _reporterOptions.metrics()->reporterFailure().inc(ex.numFailed());
        _reporterOptions.logger()->error(ex.what());
    }

    _lastFlush = Clock::now();
}

}  // namespace reporters
}  // namespace jaegertracing
