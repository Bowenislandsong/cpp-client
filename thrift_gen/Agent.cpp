/**
 * Autogenerated by Thrift Compiler (0.10.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "Agent.h"

namespace uber { namespace jaeger { namespace agent { namespace thrift {


Agent_emitZipkinBatch_args::~Agent_emitZipkinBatch_args() throw() {
}


uint32_t Agent_emitZipkinBatch_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->spans.clear();
            uint32_t _size0;
            ::apache::thrift::protocol::TType _etype3;
            xfer += iprot->readListBegin(_etype3, _size0);
            this->spans.resize(_size0);
            uint32_t _i4;
            for (_i4 = 0; _i4 < _size0; ++_i4)
            {
              xfer += this->spans[_i4].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.spans = true;
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

uint32_t Agent_emitZipkinBatch_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Agent_emitZipkinBatch_args");

  xfer += oprot->writeFieldBegin("spans", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->spans.size()));
    std::vector< ::twitter::zipkin::thrift::Span> ::const_iterator _iter5;
    for (_iter5 = this->spans.begin(); _iter5 != this->spans.end(); ++_iter5)
    {
      xfer += (*_iter5).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


Agent_emitZipkinBatch_pargs::~Agent_emitZipkinBatch_pargs() throw() {
}


uint32_t Agent_emitZipkinBatch_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Agent_emitZipkinBatch_pargs");

  xfer += oprot->writeFieldBegin("spans", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>((*(this->spans)).size()));
    std::vector< ::twitter::zipkin::thrift::Span> ::const_iterator _iter6;
    for (_iter6 = (*(this->spans)).begin(); _iter6 != (*(this->spans)).end(); ++_iter6)
    {
      xfer += (*_iter6).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


Agent_emitBatch_args::~Agent_emitBatch_args() throw() {
}


uint32_t Agent_emitBatch_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->batch.read(iprot);
          this->__isset.batch = true;
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

uint32_t Agent_emitBatch_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Agent_emitBatch_args");

  xfer += oprot->writeFieldBegin("batch", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->batch.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


Agent_emitBatch_pargs::~Agent_emitBatch_pargs() throw() {
}


uint32_t Agent_emitBatch_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Agent_emitBatch_pargs");

  xfer += oprot->writeFieldBegin("batch", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += (*(this->batch)).write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void AgentClient::emitZipkinBatch(const std::vector< ::twitter::zipkin::thrift::Span> & spans)
{
  send_emitZipkinBatch(spans);
}

void AgentClient::send_emitZipkinBatch(const std::vector< ::twitter::zipkin::thrift::Span> & spans)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("emitZipkinBatch", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  Agent_emitZipkinBatch_pargs args;
  args.spans = &spans;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void AgentClient::emitBatch(const  ::uber::jaeger::thrift::Batch& batch)
{
  send_emitBatch(batch);
}

void AgentClient::send_emitBatch(const  ::uber::jaeger::thrift::Batch& batch)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("emitBatch", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  Agent_emitBatch_pargs args;
  args.batch = &batch;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

bool AgentProcessor::dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext) {
  ProcessMap::iterator pfn;
  pfn = processMap_.find(fname);
  if (pfn == processMap_.end()) {
    iprot->skip(::apache::thrift::protocol::T_STRUCT);
    iprot->readMessageEnd();
    iprot->getTransport()->readEnd();
    ::apache::thrift::TApplicationException x(::apache::thrift::TApplicationException::UNKNOWN_METHOD, "Invalid method name: '"+fname+"'");
    oprot->writeMessageBegin(fname, ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return true;
  }
  (this->*(pfn->second))(seqid, iprot, oprot, callContext);
  return true;
}

void AgentProcessor::process_emitZipkinBatch(int32_t, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol*, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("Agent.emitZipkinBatch", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "Agent.emitZipkinBatch");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "Agent.emitZipkinBatch");
  }

  Agent_emitZipkinBatch_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "Agent.emitZipkinBatch", bytes);
  }

  try {
    iface_->emitZipkinBatch(args.spans);
  } catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "Agent.emitZipkinBatch");
    }
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->asyncComplete(ctx, "Agent.emitZipkinBatch");
  }

  return;
}

void AgentProcessor::process_emitBatch(int32_t, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol*, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("Agent.emitBatch", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "Agent.emitBatch");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "Agent.emitBatch");
  }

  Agent_emitBatch_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "Agent.emitBatch", bytes);
  }

  try {
    iface_->emitBatch(args.batch);
  } catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "Agent.emitBatch");
    }
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->asyncComplete(ctx, "Agent.emitBatch");
  }

  return;
}

::boost::shared_ptr< ::apache::thrift::TProcessor > AgentProcessorFactory::getProcessor(const ::apache::thrift::TConnectionInfo& connInfo) {
  ::apache::thrift::ReleaseHandler< AgentIfFactory > cleanup(handlerFactory_);
  ::boost::shared_ptr< AgentIf > handler(handlerFactory_->getHandler(connInfo), cleanup);
  ::boost::shared_ptr< ::apache::thrift::TProcessor > processor(new AgentProcessor(handler));
  return processor;
}

void AgentConcurrentClient::emitZipkinBatch(const std::vector< ::twitter::zipkin::thrift::Span> & spans)
{
  send_emitZipkinBatch(spans);
}

void AgentConcurrentClient::send_emitZipkinBatch(const std::vector< ::twitter::zipkin::thrift::Span> & spans)
{
  int32_t cseqid = 0;
  ::apache::thrift::async::TConcurrentSendSentry sentry(&this->sync_);
  oprot_->writeMessageBegin("emitZipkinBatch", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  Agent_emitZipkinBatch_pargs args;
  args.spans = &spans;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
}

void AgentConcurrentClient::emitBatch(const  ::uber::jaeger::thrift::Batch& batch)
{
  send_emitBatch(batch);
}

void AgentConcurrentClient::send_emitBatch(const  ::uber::jaeger::thrift::Batch& batch)
{
  int32_t cseqid = 0;
  ::apache::thrift::async::TConcurrentSendSentry sentry(&this->sync_);
  oprot_->writeMessageBegin("emitBatch", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  Agent_emitBatch_pargs args;
  args.batch = &batch;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
}

}}}} // namespace

