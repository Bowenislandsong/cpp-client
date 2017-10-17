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

#ifndef JAEGERTRACING_BAGGAGE_RESTRICTIONSCONFIG_H
#define JAEGERTRACING_BAGGAGE_RESTRICTIONSCONFIG_H

#include <chrono>
#include <string>

#include "jaegertracing/Constants.h"

#ifdef JAEGERTRACING_WITH_YAML_CPP
#include <yaml-cpp/yaml.h>
#endif  // JAEGERTRACING_WITH_YAML_CPP

namespace jaegertracing {
namespace baggage {

class RestrictionsConfig {
  public:
    using Clock = std::chrono::steady_clock;

#ifdef JAEGERTRACING_WITH_YAML_CPP

    static RestrictionsConfig parse(const YAML::Node& configYAML)
    {
        // TODO
        return RestrictionsConfig();
    }

#endif  // JAEGERTRACING_WITH_YAML_CPP

    RestrictionsConfig() = default;

    RestrictionsConfig(bool denyBaggageOnInitializationFailure,
                       const std::string& hostPort,
                       const Clock::duration& refreshInterval)
        : _denyBaggageOnInitializationFailure(
              denyBaggageOnInitializationFailure)
        , _hostPort(hostPort)
        , _refreshInterval(refreshInterval)
    {
    }

    bool denyBaggageOnInitializationFailure() const
    {
        return _denyBaggageOnInitializationFailure;
    }

    void setDenyBaggageOnInitializationFailure(
        bool denyBaggageOnInitializationFailure)
    {
        _denyBaggageOnInitializationFailure =
            denyBaggageOnInitializationFailure;
    }

    const std::string& hostPort() const { return _hostPort; }

    void setHostPort(const std::string& hostPort) { _hostPort = hostPort; }

    const Clock::duration& refreshInterval() const { return _refreshInterval; }

    void setRefreshInterval(const Clock::duration& refreshInterval)
    {
        _refreshInterval = refreshInterval;
    }

  private:
    bool _denyBaggageOnInitializationFailure;
    std::string _hostPort;
    Clock::duration _refreshInterval;
};

}  // namespace baggage
}  // namespace jaegertracing

#endif  // JAEGERTRACING_BAGGAGE_RESTRICTIONSCONFIG_H