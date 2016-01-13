// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessagePut.proto

#ifndef PROTOBUF_MessagePut_2eproto__INCLUDED
#define PROTOBUF_MessagePut_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_MessagePut_2eproto();
void protobuf_AssignDesc_MessagePut_2eproto();
void protobuf_ShutdownFile_MessagePut_2eproto();

class MessagePut;

// ===================================================================

class MessagePut : public ::google::protobuf::Message {
 public:
  MessagePut();
  virtual ~MessagePut();

  MessagePut(const MessagePut& from);

  inline MessagePut& operator=(const MessagePut& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const MessagePut& default_instance();

  void Swap(MessagePut* other);

  // implements Message ----------------------------------------------

  MessagePut* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MessagePut& from);
  void MergeFrom(const MessagePut& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int64 index = 1;
  inline bool has_index() const;
  inline void clear_index();
  static const int kIndexFieldNumber = 1;
  inline ::google::protobuf::int64 index() const;
  inline void set_index(::google::protobuf::int64 value);

  // required int64 size = 2;
  inline bool has_size() const;
  inline void clear_size();
  static const int kSizeFieldNumber = 2;
  inline ::google::protobuf::int64 size() const;
  inline void set_size(::google::protobuf::int64 value);

  // required int64 offset = 3;
  inline bool has_offset() const;
  inline void clear_offset();
  static const int kOffsetFieldNumber = 3;
  inline ::google::protobuf::int64 offset() const;
  inline void set_offset(::google::protobuf::int64 value);

  // required bytes data = 4;
  inline bool has_data() const;
  inline void clear_data();
  static const int kDataFieldNumber = 4;
  inline const ::std::string& data() const;
  inline void set_data(const ::std::string& value);
  inline void set_data(const char* value);
  inline void set_data(const void* value, size_t size);
  inline ::std::string* mutable_data();
  inline ::std::string* release_data();
  inline void set_allocated_data(::std::string* data);

  // required string token = 5;
  inline bool has_token() const;
  inline void clear_token();
  static const int kTokenFieldNumber = 5;
  inline const ::std::string& token() const;
  inline void set_token(const ::std::string& value);
  inline void set_token(const char* value);
  inline void set_token(const char* value, size_t size);
  inline ::std::string* mutable_token();
  inline ::std::string* release_token();
  inline void set_allocated_token(::std::string* token);

  // @@protoc_insertion_point(class_scope:MessagePut)
 private:
  inline void set_has_index();
  inline void clear_has_index();
  inline void set_has_size();
  inline void clear_has_size();
  inline void set_has_offset();
  inline void clear_has_offset();
  inline void set_has_data();
  inline void clear_has_data();
  inline void set_has_token();
  inline void clear_has_token();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::int64 index_;
  ::google::protobuf::int64 size_;
  ::google::protobuf::int64 offset_;
  ::std::string* data_;
  ::std::string* token_;
  friend void  protobuf_AddDesc_MessagePut_2eproto();
  friend void protobuf_AssignDesc_MessagePut_2eproto();
  friend void protobuf_ShutdownFile_MessagePut_2eproto();

  void InitAsDefaultInstance();
  static MessagePut* default_instance_;
};
// ===================================================================


// ===================================================================

// MessagePut

// required int64 index = 1;
inline bool MessagePut::has_index() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void MessagePut::set_has_index() {
  _has_bits_[0] |= 0x00000001u;
}
inline void MessagePut::clear_has_index() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void MessagePut::clear_index() {
  index_ = GOOGLE_LONGLONG(0);
  clear_has_index();
}
inline ::google::protobuf::int64 MessagePut::index() const {
  // @@protoc_insertion_point(field_get:MessagePut.index)
  return index_;
}
inline void MessagePut::set_index(::google::protobuf::int64 value) {
  set_has_index();
  index_ = value;
  // @@protoc_insertion_point(field_set:MessagePut.index)
}

// required int64 size = 2;
inline bool MessagePut::has_size() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void MessagePut::set_has_size() {
  _has_bits_[0] |= 0x00000002u;
}
inline void MessagePut::clear_has_size() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void MessagePut::clear_size() {
  size_ = GOOGLE_LONGLONG(0);
  clear_has_size();
}
inline ::google::protobuf::int64 MessagePut::size() const {
  // @@protoc_insertion_point(field_get:MessagePut.size)
  return size_;
}
inline void MessagePut::set_size(::google::protobuf::int64 value) {
  set_has_size();
  size_ = value;
  // @@protoc_insertion_point(field_set:MessagePut.size)
}

// required int64 offset = 3;
inline bool MessagePut::has_offset() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void MessagePut::set_has_offset() {
  _has_bits_[0] |= 0x00000004u;
}
inline void MessagePut::clear_has_offset() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void MessagePut::clear_offset() {
  offset_ = GOOGLE_LONGLONG(0);
  clear_has_offset();
}
inline ::google::protobuf::int64 MessagePut::offset() const {
  // @@protoc_insertion_point(field_get:MessagePut.offset)
  return offset_;
}
inline void MessagePut::set_offset(::google::protobuf::int64 value) {
  set_has_offset();
  offset_ = value;
  // @@protoc_insertion_point(field_set:MessagePut.offset)
}

// required bytes data = 4;
inline bool MessagePut::has_data() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void MessagePut::set_has_data() {
  _has_bits_[0] |= 0x00000008u;
}
inline void MessagePut::clear_has_data() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void MessagePut::clear_data() {
  if (data_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    data_->clear();
  }
  clear_has_data();
}
inline const ::std::string& MessagePut::data() const {
  // @@protoc_insertion_point(field_get:MessagePut.data)
  return *data_;
}
inline void MessagePut::set_data(const ::std::string& value) {
  set_has_data();
  if (data_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    data_ = new ::std::string;
  }
  data_->assign(value);
  // @@protoc_insertion_point(field_set:MessagePut.data)
}
inline void MessagePut::set_data(const char* value) {
  set_has_data();
  if (data_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    data_ = new ::std::string;
  }
  data_->assign(value);
  // @@protoc_insertion_point(field_set_char:MessagePut.data)
}
inline void MessagePut::set_data(const void* value, size_t size) {
  set_has_data();
  if (data_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    data_ = new ::std::string;
  }
  data_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:MessagePut.data)
}
inline ::std::string* MessagePut::mutable_data() {
  set_has_data();
  if (data_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    data_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:MessagePut.data)
  return data_;
}
inline ::std::string* MessagePut::release_data() {
  clear_has_data();
  if (data_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = data_;
    data_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void MessagePut::set_allocated_data(::std::string* data) {
  if (data_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete data_;
  }
  if (data) {
    set_has_data();
    data_ = data;
  } else {
    clear_has_data();
    data_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:MessagePut.data)
}

// required string token = 5;
inline bool MessagePut::has_token() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void MessagePut::set_has_token() {
  _has_bits_[0] |= 0x00000010u;
}
inline void MessagePut::clear_has_token() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void MessagePut::clear_token() {
  if (token_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    token_->clear();
  }
  clear_has_token();
}
inline const ::std::string& MessagePut::token() const {
  // @@protoc_insertion_point(field_get:MessagePut.token)
  return *token_;
}
inline void MessagePut::set_token(const ::std::string& value) {
  set_has_token();
  if (token_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    token_ = new ::std::string;
  }
  token_->assign(value);
  // @@protoc_insertion_point(field_set:MessagePut.token)
}
inline void MessagePut::set_token(const char* value) {
  set_has_token();
  if (token_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    token_ = new ::std::string;
  }
  token_->assign(value);
  // @@protoc_insertion_point(field_set_char:MessagePut.token)
}
inline void MessagePut::set_token(const char* value, size_t size) {
  set_has_token();
  if (token_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    token_ = new ::std::string;
  }
  token_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:MessagePut.token)
}
inline ::std::string* MessagePut::mutable_token() {
  set_has_token();
  if (token_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    token_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:MessagePut.token)
  return token_;
}
inline ::std::string* MessagePut::release_token() {
  clear_has_token();
  if (token_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = token_;
    token_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void MessagePut::set_allocated_token(::std::string* token) {
  if (token_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete token_;
  }
  if (token) {
    set_has_token();
    token_ = token;
  } else {
    clear_has_token();
    token_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:MessagePut.token)
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_MessagePut_2eproto__INCLUDED
