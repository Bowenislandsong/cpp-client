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

#include <gtest/gtest.h>

#include "jaegertracing/Config.h"

namespace jaegertracing {

#ifdef JAEGERTRACING_WITH_YAML_CPP

TEST(Config, testParse)
{
    constexpr auto kConfigYAML = R"cfg(
disabled: true
sampler:
    type: probabilistic
    param: 0.01
reporter: 4
headers: 5
baggage_restrictions: 6
)cfg";
    const auto config = Config::parse(YAML::Load(kConfigYAML));
    ASSERT_EQ("probabilistic", config.sampler().type());
}

#endif  // JAEGERTRACING_WITH_YAML_CPP

}  // namespace jaegertracing