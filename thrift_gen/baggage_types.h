/**
 * Autogenerated by Thrift Compiler (0.10.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef baggage_TYPES_H
#define baggage_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>


namespace uber { namespace jaeger { namespace thrift {

class BaggageRestriction;


class BaggageRestriction : public virtual ::apache::thrift::TBase {
 public:

  BaggageRestriction(const BaggageRestriction&);
  BaggageRestriction(BaggageRestriction&&);
  BaggageRestriction& operator=(const BaggageRestriction&);
  BaggageRestriction& operator=(BaggageRestriction&&);
  BaggageRestriction() : baggageKey(), maxValueLength(0) {
  }

  virtual ~BaggageRestriction() throw();
  std::string baggageKey;
  int32_t maxValueLength;

  void __set_baggageKey(const std::string& val);

  void __set_maxValueLength(const int32_t val);

  bool operator == (const BaggageRestriction & rhs) const
  {
    if (!(baggageKey == rhs.baggageKey))
      return false;
    if (!(maxValueLength == rhs.maxValueLength))
      return false;
    return true;
  }
  bool operator != (const BaggageRestriction &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const BaggageRestriction & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(BaggageRestriction &a, BaggageRestriction &b);

inline std::ostream& operator<<(std::ostream& out, const BaggageRestriction& obj)
{
  obj.printTo(out);
  return out;
}

}}} // namespace

#endif
