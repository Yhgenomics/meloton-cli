// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageRequestGetToken.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MessageRequestGetToken.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* MessageRequestGetToken_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MessageRequestGetToken_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MessageRequestGetToken_2eproto() {
  protobuf_AddDesc_MessageRequestGetToken_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MessageRequestGetToken.proto");
  GOOGLE_CHECK(file != NULL);
  MessageRequestGetToken_descriptor_ = file->message_type(0);
  static const int MessageRequestGetToken_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessageRequestGetToken, index_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessageRequestGetToken, request_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessageRequestGetToken, block_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessageRequestGetToken, client_id_),
  };
  MessageRequestGetToken_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MessageRequestGetToken_descriptor_,
      MessageRequestGetToken::default_instance_,
      MessageRequestGetToken_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessageRequestGetToken, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessageRequestGetToken, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MessageRequestGetToken));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MessageRequestGetToken_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MessageRequestGetToken_descriptor_, &MessageRequestGetToken::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MessageRequestGetToken_2eproto() {
  delete MessageRequestGetToken::default_instance_;
  delete MessageRequestGetToken_reflection_;
}

void protobuf_AddDesc_MessageRequestGetToken_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\034MessageRequestGetToken.proto\"`\n\026Messag"
    "eRequestGetToken\022\r\n\005index\030\001 \002(\003\022\022\n\nreque"
    "st_id\030\002 \002(\t\022\020\n\010block_id\030\003 \002(\003\022\021\n\tclient_"
    "id\030\004 \002(\003", 128);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MessageRequestGetToken.proto", &protobuf_RegisterTypes);
  MessageRequestGetToken::default_instance_ = new MessageRequestGetToken();
  MessageRequestGetToken::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MessageRequestGetToken_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MessageRequestGetToken_2eproto {
  StaticDescriptorInitializer_MessageRequestGetToken_2eproto() {
    protobuf_AddDesc_MessageRequestGetToken_2eproto();
  }
} static_descriptor_initializer_MessageRequestGetToken_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int MessageRequestGetToken::kIndexFieldNumber;
const int MessageRequestGetToken::kRequestIdFieldNumber;
const int MessageRequestGetToken::kBlockIdFieldNumber;
const int MessageRequestGetToken::kClientIdFieldNumber;
#endif  // !_MSC_VER

MessageRequestGetToken::MessageRequestGetToken()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:MessageRequestGetToken)
}

void MessageRequestGetToken::InitAsDefaultInstance() {
}

MessageRequestGetToken::MessageRequestGetToken(const MessageRequestGetToken& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:MessageRequestGetToken)
}

void MessageRequestGetToken::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  index_ = GOOGLE_LONGLONG(0);
  request_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  block_id_ = GOOGLE_LONGLONG(0);
  client_id_ = GOOGLE_LONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MessageRequestGetToken::~MessageRequestGetToken() {
  // @@protoc_insertion_point(destructor:MessageRequestGetToken)
  SharedDtor();
}

void MessageRequestGetToken::SharedDtor() {
  if (request_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete request_id_;
  }
  if (this != default_instance_) {
  }
}

void MessageRequestGetToken::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MessageRequestGetToken::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MessageRequestGetToken_descriptor_;
}

const MessageRequestGetToken& MessageRequestGetToken::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageRequestGetToken_2eproto();
  return *default_instance_;
}

MessageRequestGetToken* MessageRequestGetToken::default_instance_ = NULL;

MessageRequestGetToken* MessageRequestGetToken::New() const {
  return new MessageRequestGetToken;
}

void MessageRequestGetToken::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<MessageRequestGetToken*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 15) {
    ZR_(block_id_, client_id_);
    index_ = GOOGLE_LONGLONG(0);
    if (has_request_id()) {
      if (request_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        request_id_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MessageRequestGetToken::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:MessageRequestGetToken)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int64 index = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &index_)));
          set_has_index();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_request_id;
        break;
      }

      // required string request_id = 2;
      case 2: {
        if (tag == 18) {
         parse_request_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_request_id()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->request_id().data(), this->request_id().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "request_id");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_block_id;
        break;
      }

      // required int64 block_id = 3;
      case 3: {
        if (tag == 24) {
         parse_block_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &block_id_)));
          set_has_block_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_client_id;
        break;
      }

      // required int64 client_id = 4;
      case 4: {
        if (tag == 32) {
         parse_client_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &client_id_)));
          set_has_client_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:MessageRequestGetToken)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:MessageRequestGetToken)
  return false;
#undef DO_
}

void MessageRequestGetToken::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:MessageRequestGetToken)
  // required int64 index = 1;
  if (has_index()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->index(), output);
  }

  // required string request_id = 2;
  if (has_request_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->request_id().data(), this->request_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "request_id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->request_id(), output);
  }

  // required int64 block_id = 3;
  if (has_block_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(3, this->block_id(), output);
  }

  // required int64 client_id = 4;
  if (has_client_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(4, this->client_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:MessageRequestGetToken)
}

::google::protobuf::uint8* MessageRequestGetToken::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:MessageRequestGetToken)
  // required int64 index = 1;
  if (has_index()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->index(), target);
  }

  // required string request_id = 2;
  if (has_request_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->request_id().data(), this->request_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "request_id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->request_id(), target);
  }

  // required int64 block_id = 3;
  if (has_block_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(3, this->block_id(), target);
  }

  // required int64 client_id = 4;
  if (has_client_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(4, this->client_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:MessageRequestGetToken)
  return target;
}

int MessageRequestGetToken::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int64 index = 1;
    if (has_index()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->index());
    }

    // required string request_id = 2;
    if (has_request_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->request_id());
    }

    // required int64 block_id = 3;
    if (has_block_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->block_id());
    }

    // required int64 client_id = 4;
    if (has_client_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->client_id());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void MessageRequestGetToken::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MessageRequestGetToken* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MessageRequestGetToken*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MessageRequestGetToken::MergeFrom(const MessageRequestGetToken& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_index()) {
      set_index(from.index());
    }
    if (from.has_request_id()) {
      set_request_id(from.request_id());
    }
    if (from.has_block_id()) {
      set_block_id(from.block_id());
    }
    if (from.has_client_id()) {
      set_client_id(from.client_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MessageRequestGetToken::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MessageRequestGetToken::CopyFrom(const MessageRequestGetToken& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MessageRequestGetToken::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000000f) != 0x0000000f) return false;

  return true;
}

void MessageRequestGetToken::Swap(MessageRequestGetToken* other) {
  if (other != this) {
    std::swap(index_, other->index_);
    std::swap(request_id_, other->request_id_);
    std::swap(block_id_, other->block_id_);
    std::swap(client_id_, other->client_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MessageRequestGetToken::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MessageRequestGetToken_descriptor_;
  metadata.reflection = MessageRequestGetToken_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)