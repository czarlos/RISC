// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: AddUnitOrder.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "AddUnitOrder.pb.h"

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

const ::google::protobuf::Descriptor* AddUnitOrder_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AddUnitOrder_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_AddUnitOrder_2eproto() {
  protobuf_AddDesc_AddUnitOrder_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "AddUnitOrder.proto");
  GOOGLE_CHECK(file != NULL);
  AddUnitOrder_descriptor_ = file->message_type(0);
  static const int AddUnitOrder_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AddUnitOrder, destination_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AddUnitOrder, unitlist_),
  };
  AddUnitOrder_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AddUnitOrder_descriptor_,
      AddUnitOrder::default_instance_,
      AddUnitOrder_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AddUnitOrder, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AddUnitOrder, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(AddUnitOrder));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_AddUnitOrder_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AddUnitOrder_descriptor_, &AddUnitOrder::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_AddUnitOrder_2eproto() {
  delete AddUnitOrder::default_instance_;
  delete AddUnitOrder_reflection_;
}

void protobuf_AddDesc_AddUnitOrder_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::Buffers::protobuf_AddDesc_Territory_2eproto();
  ::Buffers::protobuf_AddDesc_Unit_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\022AddUnitOrder.proto\022\007Buffers\032\017Territory"
    ".proto\032\nUnit.proto\"X\n\014AddUnitOrder\022\'\n\013de"
    "stination\030\001 \002(\0132\022.Buffers.Territory\022\037\n\010u"
    "nitList\030\002 \003(\0132\r.Buffers.Unit", 148);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "AddUnitOrder.proto", &protobuf_RegisterTypes);
  AddUnitOrder::default_instance_ = new AddUnitOrder();
  AddUnitOrder::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_AddUnitOrder_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_AddUnitOrder_2eproto {
  StaticDescriptorInitializer_AddUnitOrder_2eproto() {
    protobuf_AddDesc_AddUnitOrder_2eproto();
  }
} static_descriptor_initializer_AddUnitOrder_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int AddUnitOrder::kDestinationFieldNumber;
const int AddUnitOrder::kUnitListFieldNumber;
#endif  // !_MSC_VER

AddUnitOrder::AddUnitOrder()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void AddUnitOrder::InitAsDefaultInstance() {
  destination_ = const_cast< ::Buffers::Territory*>(&::Buffers::Territory::default_instance());
}

AddUnitOrder::AddUnitOrder(const AddUnitOrder& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void AddUnitOrder::SharedCtor() {
  _cached_size_ = 0;
  destination_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

AddUnitOrder::~AddUnitOrder() {
  SharedDtor();
}

void AddUnitOrder::SharedDtor() {
  if (this != default_instance_) {
    delete destination_;
  }
}

void AddUnitOrder::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AddUnitOrder::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AddUnitOrder_descriptor_;
}

const AddUnitOrder& AddUnitOrder::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_AddUnitOrder_2eproto();
  return *default_instance_;
}

AddUnitOrder* AddUnitOrder::default_instance_ = NULL;

AddUnitOrder* AddUnitOrder::New() const {
  return new AddUnitOrder;
}

void AddUnitOrder::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_destination()) {
      if (destination_ != NULL) destination_->::Buffers::Territory::Clear();
    }
  }
  unitlist_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool AddUnitOrder::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .Buffers.Territory destination = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_destination()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_unitList;
        break;
      }

      // repeated .Buffers.Unit unitList = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_unitList:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_unitlist()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_unitList;
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

void AddUnitOrder::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required .Buffers.Territory destination = 1;
  if (has_destination()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->destination(), output);
  }

  // repeated .Buffers.Unit unitList = 2;
  for (int i = 0; i < this->unitlist_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->unitlist(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* AddUnitOrder::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required .Buffers.Territory destination = 1;
  if (has_destination()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->destination(), target);
  }

  // repeated .Buffers.Unit unitList = 2;
  for (int i = 0; i < this->unitlist_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->unitlist(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int AddUnitOrder::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .Buffers.Territory destination = 1;
    if (has_destination()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->destination());
    }

  }
  // repeated .Buffers.Unit unitList = 2;
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

void AddUnitOrder::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const AddUnitOrder* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const AddUnitOrder*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void AddUnitOrder::MergeFrom(const AddUnitOrder& from) {
  GOOGLE_CHECK_NE(&from, this);
  unitlist_.MergeFrom(from.unitlist_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_destination()) {
      mutable_destination()->::Buffers::Territory::MergeFrom(from.destination());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void AddUnitOrder::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AddUnitOrder::CopyFrom(const AddUnitOrder& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AddUnitOrder::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_destination()) {
    if (!this->destination().IsInitialized()) return false;
  }
  for (int i = 0; i < unitlist_size(); i++) {
    if (!this->unitlist(i).IsInitialized()) return false;
  }
  return true;
}

void AddUnitOrder::Swap(AddUnitOrder* other) {
  if (other != this) {
    std::swap(destination_, other->destination_);
    unitlist_.Swap(&other->unitlist_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata AddUnitOrder::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = AddUnitOrder_descriptor_;
  metadata.reflection = AddUnitOrder_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Buffers

// @@protoc_insertion_point(global_scope)
