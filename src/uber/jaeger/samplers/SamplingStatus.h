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

#ifndef UBER_JAEGER_SAMPLERS_SAMPLINGSTATUS_H
#define UBER_JAEGER_SAMPLERS_SAMPLINGSTATUS_H

#include <vector>

#include "uber/jaeger/Tag.h"

namespace uber {
namespace jaeger {
namespace samplers {

class SamplingStatus {
  public:
    SamplingStatus(bool isSampled, const std::vector<Tag>& tags)
        : _isSampled(isSampled)
        , _tags(tags)
    {
    }

    bool isSampled() const { return _isSampled; }

    const std::vector<Tag>& tags() const { return _tags; }

  private:
    bool _isSampled;
    std::vector<Tag> _tags;
};

}  // namespace samplers
}  // namespace jaeger
}  // namespace uber

#endif  // UBER_JAEGER_SAMPLERS_SAMPLINGSTATUS_H