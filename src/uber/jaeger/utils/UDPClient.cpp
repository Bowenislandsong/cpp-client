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

#include "uber/jaeger/utils/UDPClient.h"

namespace uber {
namespace jaeger {
namespace utils {

UDPClient::UDPClient(const net::IPAddress& serverAddr, int maxPacketSize)
    : _maxPacketSize(maxPacketSize == 0 ? net::kUDPPacketMaxLength
                                        : maxPacketSize)
    , _buffer(new apache::thrift::transport::TMemoryBuffer(_maxPacketSize))
    , _socket()
    , _serverAddr(serverAddr)
    , _client()
{
    using TProtocolFactory = apache::thrift::protocol::TProtocolFactory;
    using TCompactProtocolFactory =
        apache::thrift::protocol::TCompactProtocolFactory;

    _socket.open(AF_INET, SOCK_DGRAM);
    _socket.connect(_serverAddr);
    boost::shared_ptr<TProtocolFactory> protocolFactory(
        new TCompactProtocolFactory());
    auto protocol = protocolFactory->getProtocol(_buffer);
    _client.reset(new agent::thrift::AgentClient(protocol));
}

}  // namespace utils
}  // namespace jaeger
}  // namespace uber
