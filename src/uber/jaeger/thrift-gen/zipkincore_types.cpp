/**
 * Autogenerated by Thrift Compiler (0.10.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "zipkincore_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace twitter { namespace zipkin { namespace thrift {

int _kAnnotationTypeValues[] = {
  AnnotationType::BOOL,
  AnnotationType::BYTES,
  AnnotationType::I16,
  AnnotationType::I32,
  AnnotationType::I64,
  AnnotationType::DOUBLE,
  AnnotationType::STRING
};
const char* _kAnnotationTypeNames[] = {
  "BOOL",
  "BYTES",
  "I16",
  "I32",
  "I64",
  "DOUBLE",
  "STRING"
};
const std::map<int, const char*> _AnnotationType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(7, _kAnnotationTypeValues, _kAnnotationTypeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));


Endpoint::~Endpoint() throw() {
}


void Endpoint::__set_ipv4(const int32_t val) {
  this->ipv4 = val;
}

void Endpoint::__set_port(const int16_t val) {
  this->port = val;
}

void Endpoint::__set_service_name(const std::string& val) {
  this->service_name = val;
}

void Endpoint::__set_ipv6(const std::string& val) {
  this->ipv6 = val;
__isset.ipv6 = true;
}

uint32_t Endpoint::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->ipv4);
          this->__isset.ipv4 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->port);
          this->__isset.port = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->service_name);
          this->__isset.service_name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->ipv6);
          this->__isset.ipv6 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Endpoint::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Endpoint");

  xfer += oprot->writeFieldBegin("ipv4", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->ipv4);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("port", ::apache::thrift::protocol::T_I16, 2);
  xfer += oprot->writeI16(this->port);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("service_name", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->service_name);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.ipv6) {
    xfer += oprot->writeFieldBegin("ipv6", ::apache::thrift::protocol::T_STRING, 4);
    xfer += oprot->writeBinary(this->ipv6);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Endpoint &a, Endpoint &b) {
  using ::std::swap;
  swap(a.ipv4, b.ipv4);
  swap(a.port, b.port);
  swap(a.service_name, b.service_name);
  swap(a.ipv6, b.ipv6);
  swap(a.__isset, b.__isset);
}

Endpoint::Endpoint(const Endpoint& other0) {
  ipv4 = other0.ipv4;
  port = other0.port;
  service_name = other0.service_name;
  ipv6 = other0.ipv6;
  __isset = other0.__isset;
}
Endpoint::Endpoint( Endpoint&& other1) {
  ipv4 = std::move(other1.ipv4);
  port = std::move(other1.port);
  service_name = std::move(other1.service_name);
  ipv6 = std::move(other1.ipv6);
  __isset = std::move(other1.__isset);
}
Endpoint& Endpoint::operator=(const Endpoint& other2) {
  ipv4 = other2.ipv4;
  port = other2.port;
  service_name = other2.service_name;
  ipv6 = other2.ipv6;
  __isset = other2.__isset;
  return *this;
}
Endpoint& Endpoint::operator=(Endpoint&& other3) {
  ipv4 = std::move(other3.ipv4);
  port = std::move(other3.port);
  service_name = std::move(other3.service_name);
  ipv6 = std::move(other3.ipv6);
  __isset = std::move(other3.__isset);
  return *this;
}
void Endpoint::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "Endpoint(";
  out << "ipv4=" << to_string(ipv4);
  out << ", " << "port=" << to_string(port);
  out << ", " << "service_name=" << to_string(service_name);
  out << ", " << "ipv6="; (__isset.ipv6 ? (out << to_string(ipv6)) : (out << "<null>"));
  out << ")";
}


Annotation::~Annotation() throw() {
}


void Annotation::__set_timestamp(const int64_t val) {
  this->timestamp = val;
}

void Annotation::__set_value(const std::string& val) {
  this->value = val;
}

void Annotation::__set_host(const Endpoint& val) {
  this->host = val;
__isset.host = true;
}

uint32_t Annotation::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->timestamp);
          this->__isset.timestamp = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->value);
          this->__isset.value = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->host.read(iprot);
          this->__isset.host = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Annotation::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Annotation");

  xfer += oprot->writeFieldBegin("timestamp", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->timestamp);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("value", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->value);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.host) {
    xfer += oprot->writeFieldBegin("host", ::apache::thrift::protocol::T_STRUCT, 3);
    xfer += this->host.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Annotation &a, Annotation &b) {
  using ::std::swap;
  swap(a.timestamp, b.timestamp);
  swap(a.value, b.value);
  swap(a.host, b.host);
  swap(a.__isset, b.__isset);
}

Annotation::Annotation(const Annotation& other4) {
  timestamp = other4.timestamp;
  value = other4.value;
  host = other4.host;
  __isset = other4.__isset;
}
Annotation::Annotation( Annotation&& other5) {
  timestamp = std::move(other5.timestamp);
  value = std::move(other5.value);
  host = std::move(other5.host);
  __isset = std::move(other5.__isset);
}
Annotation& Annotation::operator=(const Annotation& other6) {
  timestamp = other6.timestamp;
  value = other6.value;
  host = other6.host;
  __isset = other6.__isset;
  return *this;
}
Annotation& Annotation::operator=(Annotation&& other7) {
  timestamp = std::move(other7.timestamp);
  value = std::move(other7.value);
  host = std::move(other7.host);
  __isset = std::move(other7.__isset);
  return *this;
}
void Annotation::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "Annotation(";
  out << "timestamp=" << to_string(timestamp);
  out << ", " << "value=" << to_string(value);
  out << ", " << "host="; (__isset.host ? (out << to_string(host)) : (out << "<null>"));
  out << ")";
}


BinaryAnnotation::~BinaryAnnotation() throw() {
}


void BinaryAnnotation::__set_key(const std::string& val) {
  this->key = val;
}

void BinaryAnnotation::__set_value(const std::string& val) {
  this->value = val;
}

void BinaryAnnotation::__set_annotation_type(const AnnotationType::type val) {
  this->annotation_type = val;
}

void BinaryAnnotation::__set_host(const Endpoint& val) {
  this->host = val;
__isset.host = true;
}

uint32_t BinaryAnnotation::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->key);
          this->__isset.key = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->value);
          this->__isset.value = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast8;
          xfer += iprot->readI32(ecast8);
          this->annotation_type = (AnnotationType::type)ecast8;
          this->__isset.annotation_type = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->host.read(iprot);
          this->__isset.host = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t BinaryAnnotation::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("BinaryAnnotation");

  xfer += oprot->writeFieldBegin("key", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->key);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("value", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeBinary(this->value);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("annotation_type", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32((int32_t)this->annotation_type);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.host) {
    xfer += oprot->writeFieldBegin("host", ::apache::thrift::protocol::T_STRUCT, 4);
    xfer += this->host.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(BinaryAnnotation &a, BinaryAnnotation &b) {
  using ::std::swap;
  swap(a.key, b.key);
  swap(a.value, b.value);
  swap(a.annotation_type, b.annotation_type);
  swap(a.host, b.host);
  swap(a.__isset, b.__isset);
}

BinaryAnnotation::BinaryAnnotation(const BinaryAnnotation& other9) {
  key = other9.key;
  value = other9.value;
  annotation_type = other9.annotation_type;
  host = other9.host;
  __isset = other9.__isset;
}
BinaryAnnotation::BinaryAnnotation( BinaryAnnotation&& other10) {
  key = std::move(other10.key);
  value = std::move(other10.value);
  annotation_type = std::move(other10.annotation_type);
  host = std::move(other10.host);
  __isset = std::move(other10.__isset);
}
BinaryAnnotation& BinaryAnnotation::operator=(const BinaryAnnotation& other11) {
  key = other11.key;
  value = other11.value;
  annotation_type = other11.annotation_type;
  host = other11.host;
  __isset = other11.__isset;
  return *this;
}
BinaryAnnotation& BinaryAnnotation::operator=(BinaryAnnotation&& other12) {
  key = std::move(other12.key);
  value = std::move(other12.value);
  annotation_type = std::move(other12.annotation_type);
  host = std::move(other12.host);
  __isset = std::move(other12.__isset);
  return *this;
}
void BinaryAnnotation::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "BinaryAnnotation(";
  out << "key=" << to_string(key);
  out << ", " << "value=" << to_string(value);
  out << ", " << "annotation_type=" << to_string(annotation_type);
  out << ", " << "host="; (__isset.host ? (out << to_string(host)) : (out << "<null>"));
  out << ")";
}


Span::~Span() throw() {
}


void Span::__set_trace_id(const int64_t val) {
  this->trace_id = val;
}

void Span::__set_name(const std::string& val) {
  this->name = val;
}

void Span::__set_id(const int64_t val) {
  this->id = val;
}

void Span::__set_parent_id(const int64_t val) {
  this->parent_id = val;
__isset.parent_id = true;
}

void Span::__set_annotations(const std::vector<Annotation> & val) {
  this->annotations = val;
}

void Span::__set_binary_annotations(const std::vector<BinaryAnnotation> & val) {
  this->binary_annotations = val;
}

void Span::__set_debug(const bool val) {
  this->debug = val;
__isset.debug = true;
}

void Span::__set_timestamp(const int64_t val) {
  this->timestamp = val;
__isset.timestamp = true;
}

void Span::__set_duration(const int64_t val) {
  this->duration = val;
__isset.duration = true;
}

void Span::__set_trace_id_high(const int64_t val) {
  this->trace_id_high = val;
__isset.trace_id_high = true;
}

uint32_t Span::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->trace_id);
          this->__isset.trace_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          this->__isset.name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->id);
          this->__isset.id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->parent_id);
          this->__isset.parent_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->annotations.clear();
            uint32_t _size13;
            ::apache::thrift::protocol::TType _etype16;
            xfer += iprot->readListBegin(_etype16, _size13);
            this->annotations.resize(_size13);
            uint32_t _i17;
            for (_i17 = 0; _i17 < _size13; ++_i17)
            {
              xfer += this->annotations[_i17].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.annotations = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->binary_annotations.clear();
            uint32_t _size18;
            ::apache::thrift::protocol::TType _etype21;
            xfer += iprot->readListBegin(_etype21, _size18);
            this->binary_annotations.resize(_size18);
            uint32_t _i22;
            for (_i22 = 0; _i22 < _size18; ++_i22)
            {
              xfer += this->binary_annotations[_i22].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.binary_annotations = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->debug);
          this->__isset.debug = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 10:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->timestamp);
          this->__isset.timestamp = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 11:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->duration);
          this->__isset.duration = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 12:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->trace_id_high);
          this->__isset.trace_id_high = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Span::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Span");

  xfer += oprot->writeFieldBegin("trace_id", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->trace_id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("name", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("id", ::apache::thrift::protocol::T_I64, 4);
  xfer += oprot->writeI64(this->id);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.parent_id) {
    xfer += oprot->writeFieldBegin("parent_id", ::apache::thrift::protocol::T_I64, 5);
    xfer += oprot->writeI64(this->parent_id);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldBegin("annotations", ::apache::thrift::protocol::T_LIST, 6);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->annotations.size()));
    std::vector<Annotation> ::const_iterator _iter23;
    for (_iter23 = this->annotations.begin(); _iter23 != this->annotations.end(); ++_iter23)
    {
      xfer += (*_iter23).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("binary_annotations", ::apache::thrift::protocol::T_LIST, 8);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->binary_annotations.size()));
    std::vector<BinaryAnnotation> ::const_iterator _iter24;
    for (_iter24 = this->binary_annotations.begin(); _iter24 != this->binary_annotations.end(); ++_iter24)
    {
      xfer += (*_iter24).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  if (this->__isset.debug) {
    xfer += oprot->writeFieldBegin("debug", ::apache::thrift::protocol::T_BOOL, 9);
    xfer += oprot->writeBool(this->debug);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.timestamp) {
    xfer += oprot->writeFieldBegin("timestamp", ::apache::thrift::protocol::T_I64, 10);
    xfer += oprot->writeI64(this->timestamp);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.duration) {
    xfer += oprot->writeFieldBegin("duration", ::apache::thrift::protocol::T_I64, 11);
    xfer += oprot->writeI64(this->duration);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.trace_id_high) {
    xfer += oprot->writeFieldBegin("trace_id_high", ::apache::thrift::protocol::T_I64, 12);
    xfer += oprot->writeI64(this->trace_id_high);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Span &a, Span &b) {
  using ::std::swap;
  swap(a.trace_id, b.trace_id);
  swap(a.name, b.name);
  swap(a.id, b.id);
  swap(a.parent_id, b.parent_id);
  swap(a.annotations, b.annotations);
  swap(a.binary_annotations, b.binary_annotations);
  swap(a.debug, b.debug);
  swap(a.timestamp, b.timestamp);
  swap(a.duration, b.duration);
  swap(a.trace_id_high, b.trace_id_high);
  swap(a.__isset, b.__isset);
}

Span::Span(const Span& other25) {
  trace_id = other25.trace_id;
  name = other25.name;
  id = other25.id;
  parent_id = other25.parent_id;
  annotations = other25.annotations;
  binary_annotations = other25.binary_annotations;
  debug = other25.debug;
  timestamp = other25.timestamp;
  duration = other25.duration;
  trace_id_high = other25.trace_id_high;
  __isset = other25.__isset;
}
Span::Span( Span&& other26) {
  trace_id = std::move(other26.trace_id);
  name = std::move(other26.name);
  id = std::move(other26.id);
  parent_id = std::move(other26.parent_id);
  annotations = std::move(other26.annotations);
  binary_annotations = std::move(other26.binary_annotations);
  debug = std::move(other26.debug);
  timestamp = std::move(other26.timestamp);
  duration = std::move(other26.duration);
  trace_id_high = std::move(other26.trace_id_high);
  __isset = std::move(other26.__isset);
}
Span& Span::operator=(const Span& other27) {
  trace_id = other27.trace_id;
  name = other27.name;
  id = other27.id;
  parent_id = other27.parent_id;
  annotations = other27.annotations;
  binary_annotations = other27.binary_annotations;
  debug = other27.debug;
  timestamp = other27.timestamp;
  duration = other27.duration;
  trace_id_high = other27.trace_id_high;
  __isset = other27.__isset;
  return *this;
}
Span& Span::operator=(Span&& other28) {
  trace_id = std::move(other28.trace_id);
  name = std::move(other28.name);
  id = std::move(other28.id);
  parent_id = std::move(other28.parent_id);
  annotations = std::move(other28.annotations);
  binary_annotations = std::move(other28.binary_annotations);
  debug = std::move(other28.debug);
  timestamp = std::move(other28.timestamp);
  duration = std::move(other28.duration);
  trace_id_high = std::move(other28.trace_id_high);
  __isset = std::move(other28.__isset);
  return *this;
}
void Span::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "Span(";
  out << "trace_id=" << to_string(trace_id);
  out << ", " << "name=" << to_string(name);
  out << ", " << "id=" << to_string(id);
  out << ", " << "parent_id="; (__isset.parent_id ? (out << to_string(parent_id)) : (out << "<null>"));
  out << ", " << "annotations=" << to_string(annotations);
  out << ", " << "binary_annotations=" << to_string(binary_annotations);
  out << ", " << "debug="; (__isset.debug ? (out << to_string(debug)) : (out << "<null>"));
  out << ", " << "timestamp="; (__isset.timestamp ? (out << to_string(timestamp)) : (out << "<null>"));
  out << ", " << "duration="; (__isset.duration ? (out << to_string(duration)) : (out << "<null>"));
  out << ", " << "trace_id_high="; (__isset.trace_id_high ? (out << to_string(trace_id_high)) : (out << "<null>"));
  out << ")";
}


Response::~Response() throw() {
}


void Response::__set_ok(const bool val) {
  this->ok = val;
}

uint32_t Response::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_ok = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->ok);
          isset_ok = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_ok)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t Response::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Response");

  xfer += oprot->writeFieldBegin("ok", ::apache::thrift::protocol::T_BOOL, 1);
  xfer += oprot->writeBool(this->ok);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Response &a, Response &b) {
  using ::std::swap;
  swap(a.ok, b.ok);
}

Response::Response(const Response& other29) {
  ok = other29.ok;
}
Response::Response( Response&& other30) {
  ok = std::move(other30.ok);
}
Response& Response::operator=(const Response& other31) {
  ok = other31.ok;
  return *this;
}
Response& Response::operator=(Response&& other32) {
  ok = std::move(other32.ok);
  return *this;
}
void Response::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "Response(";
  out << "ok=" << to_string(ok);
  out << ")";
}

}}} // namespace