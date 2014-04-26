// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: AttackOrder.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "AttackOrder.pb.h"

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

namespace Buffers {

namespace {

const ::google::protobuf::Descriptor* AttackOrder_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AttackOrder_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_AttackOrder_2eproto() {
  protobuf_AddDesc_AttackOrder_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "AttackOrder.proto");
  GOOGLE_CHECK(file != NULL);
  AttackOrder_descriptor_ = file->message_type(0);
  static const int AttackOrder_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AttackOrder, source_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AttackOrder, destination_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AttackOrder, unitlist_),
  };
  AttackOrder_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AttackOrder_descriptor_,
      AttackOrder::default_instance_,
      AttackOrder_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AttackOrder, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AttackOrder, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(AttackOrder));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_AttackOrder_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AttackOrder_descriptor_, &AttackOrder::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_AttackOrder_2eproto() {
  delete AttackOrder::default_instance_;
  delete AttackOrder_reflection_;
}

void protobuf_AddDesc_AttackOrder_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::Buffers::protobuf_AddDesc_Location_2eproto();
  ::Buffers::protobuf_AddDesc_Unit_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\021AttackOrder.proto\022\007Buffers\032\016Location.p"
    "roto\032\nUnit.proto\"y\n\013AttackOrder\022!\n\006sourc"
    "e\030\001 \002(\0132\021.Buffers.Location\022&\n\013destinatio"
    "n\030\002 \002(\0132\021.Buffers.Location\022\037\n\010unitList\030\003"
    " \003(\0132\r.Buffers.Unit", 179);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "AttackOrder.proto", &protobuf_RegisterTypes);
  AttackOrder::default_instance_ = new AttackOrder();
  AttackOrder::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_AttackOrder_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_AttackOrder_2eproto {
  StaticDescriptorInitializer_AttackOrder_2eproto() {
    protobuf_AddDesc_AttackOrder_2eproto();
  }
} static_descriptor_initializer_AttackOrder_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int AttackOrder::kSourceFieldNumber;
const int AttackOrder::kDestinationFieldNumber;
const int AttackOrder::kUnitListFieldNumber;
#endif  // !_MSC_VER

AttackOrder::AttackOrder()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void AttackOrder::InitAsDefaultInstance() {
  source_ = const_cast< ::Buffers::Location*>(&::Buffers::Location::default_instance());
  destination_ = const_cast< ::Buffers::Location*>(&::Buffers::Location::default_instance());
}

AttackOrder::AttackOrder(const AttackOrder& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void AttackOrder::SharedCtor() {
  _cached_size_ = 0;
  source_ = NULL;
  destination_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

AttackOrder::~AttackOrder() {
  SharedDtor();
}

void AttackOrder::SharedDtor() {
  if (this != default_instance_) {
    delete source_;
    delete destination_;
  }
}

void AttackOrder::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AttackOrder::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AttackOrder_descriptor_;
}

const AttackOrder& AttackOrder::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_AttackOrder_2eproto();
  return *default_instance_;
}

AttackOrder* AttackOrder::default_instance_ = NULL;

AttackOrder* AttackOrder::New() const {
  return new AttackOrder;
}

void AttackOrder::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_source()) {
      if (source_ != NULL) source_->::Buffers::Location::Clear();
    }
    if (has_destination()) {
      if (destination_ != NULL) destination_->::Buffers::Location::Clear();
    }
  }
  unitlist_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool AttackOrder::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .Buffers.Location source = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_source()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_destination;
        break;
      }

      // required .Buffers.Location destination = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_destination:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_destination()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_unitList;
        break;
      }

      // repeated .Buffers.Unit unitList = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_unitList:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_unitlist()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_unitList;
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void AttackOrder::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required .Buffers.Location source = 1;
  if (has_source()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->source(), output);
  }

  // required .Buffers.Location destination = 2;
  if (has_destination()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->destination(), output);
  }

  // repeated .Buffers.Unit unitList = 3;
  for (int i = 0; i < this->unitlist_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->unitlist(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* AttackOrder::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required .Buffers.Location source = 1;
  if (has_source()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->source(), target);
  }

  // required .Buffers.Location destination = 2;
  if (has_destination()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->destination(), target);
  }

  // repeated .Buffers.Unit unitList = 3;
  for (int i = 0; i < this->unitlist_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->unitlist(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int AttackOrder::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .Buffers.Location source = 1;
    if (has_source()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->source());
    }

    // required .Buffers.Location destination = 2;
    if (has_destination()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->destination());
    }

  }
  // repeated .Buffers.Unit unitList = 3;
  total_size += 1 * this->unitlist_size();
  for (int i = 0; i < this->unitlist_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->unitlist(i));
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

void AttackOrder::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const AttackOrder* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const AttackOrder*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void AttackOrder::MergeFrom(const AttackOrder& from) {
  GOOGLE_CHECK_NE(&from, this);
  unitlist_.MergeFrom(from.unitlist_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_source()) {
      mutable_source()->::Buffers::Location::MergeFrom(from.source());
    }
    if (from.has_destination()) {
      mutable_destination()->::Buffers::Location::MergeFrom(from.destination());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void AttackOrder::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AttackOrder::CopyFrom(const AttackOrder& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AttackOrder::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  if (has_source()) {
    if (!this->source().IsInitialized()) return false;
  }
  if (has_destination()) {
    if (!this->destination().IsInitialized()) return false;
  }
  for (int i = 0; i < unitlist_size(); i++) {
    if (!this->unitlist(i).IsInitialized()) return false;
  }
  return true;
}

void AttackOrder::Swap(AttackOrder* other) {
  if (other != this) {
    std::swap(source_, other->source_);
    std::swap(destination_, other->destination_);
    unitlist_.Swap(&other->unitlist_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata AttackOrder::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = AttackOrder_descriptor_;
  metadata.reflection = AttackOrder_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Buffers

// @@protoc_insertion_point(global_scope)