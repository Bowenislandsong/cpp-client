/*
 * Copyright (c) 2017, Uber Technologies, Inc
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef UBER_JAEGER_METRICS_INMEMORYSTATSREPORTER_H
#define UBER_JAEGER_METRICS_INMEMORYSTATSREPORTER_H

#include <string>
#include <unordered_map>

#include "uber/jaeger/metrics/StatsReporter.h"

namespace uber {
namespace jaeger {
namespace metrics {

class InMemoryStatsReporter : public StatsReporter {
  public:
    using ValueMap = std::unordered_map<std::string, int64_t>;

    virtual ~InMemoryStatsReporter() = default;

    void incCounter(
        const std::string& name,
        int64_t delta,
        const std::unordered_map<std::string, std::string>& tags) override;

    void recordTimer(
        const std::string& name,
        int64_t time,
        const std::unordered_map<std::string, std::string>& tags) override;

    void updateGauge(
        const std::string& name,
        int64_t time,
        const std::unordered_map<std::string, std::string>& tags) override;

    void reset();

    const ValueMap& counters() const { return _counters; }

    const ValueMap& gauges() const { return _gauges; }

    const ValueMap& timers() const { return _timers; }

  private:
    ValueMap _counters;
    ValueMap _gauges;
    ValueMap _timers;
};

}  // namespace metrics
}  // namespace jaeger
}  // namespace uber

#endif  // UBER_JAEGER_METRICS_INMEMORYSTATSREPORTER_H