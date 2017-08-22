/**
 * Autogenerated by Thrift Compiler (0.10.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef aggregation_validator_TYPES_H
#define aggregation_validator_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>


namespace uber { namespace jaeger { namespace thrift {

class ValidateTraceResponse;


class ValidateTraceResponse : public virtual ::apache::thrift::TBase {
 public:

  ValidateTraceResponse(const ValidateTraceResponse&);
  ValidateTraceResponse(ValidateTraceResponse&&);
  ValidateTraceResponse& operator=(const ValidateTraceResponse&);
  ValidateTraceResponse& operator=(ValidateTraceResponse&&);
  ValidateTraceResponse() : ok(0), traceCount(0) {
  }

  virtual ~ValidateTraceResponse() throw();
  bool ok;
  int64_t traceCount;

  void __set_ok(const bool val);

  void __set_traceCount(const int64_t val);

  bool operator == (const ValidateTraceResponse & rhs) const
  {
    if (!(ok == rhs.ok))
      return false;
    if (!(traceCount == rhs.traceCount))
      return false;
    return true;
  }
  bool operator != (const ValidateTraceResponse &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ValidateTraceResponse & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ValidateTraceResponse &a, ValidateTraceResponse &b);

inline std::ostream& operator<<(std::ostream& out, const ValidateTraceResponse& obj)
{
  obj.printTo(out);
  return out;
}

}}} // namespace

#endif
