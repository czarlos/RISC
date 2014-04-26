// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MovementOrder.proto

#ifndef PROTOBUF_MovementOrder_2eproto__INCLUDED
#define PROTOBUF_MovementOrder_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "Unit.pb.h"
#include "Location.pb.h"
// @@protoc_insertion_point(includes)

namespace Buffers {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_MovementOrder_2eproto();
void protobuf_AssignDesc_MovementOrder_2eproto();
void protobuf_ShutdownFile_MovementOrder_2eproto();

class MovementOrder;

// ===================================================================

class MovementOrder : public ::google::protobuf::Message {
 public:
  MovementOrder();
  virtual ~MovementOrder();

  MovementOrder(const MovementOrder& from);

  inline MovementOrder& operator=(const MovementOrder& from) {
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
  static const MovementOrder& default_instance();

  void Swap(MovementOrder* other);

  // implements Message ----------------------------------------------

  MovementOrder* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MovementOrder& from);
  void MergeFrom(const MovementOrder& from);
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

  // required .Buffers.Location source = 1;
  inline bool has_source() const;
  inline void clear_source();
  static const int kSourceFieldNumber = 1;
  inline const ::Buffers::Location& source() const;
  inline ::Buffers::Location* mutable_source();
  inline ::Buffers::Location* release_source();
  inline void set_allocated_source(::Buffers::Location* source);

  // required .Buffers.Location destination = 2;
  inline bool has_destination() const;
  inline void clear_destination();
  static const int kDestinationFieldNumber = 2;
  inline const ::Buffers::Location& destination() const;
  inline ::Buffers::Location* mutable_destination();
  inline ::Buffers::Location* release_destination();
  inline void set_allocated_destination(::Buffers::Location* destination);

  // repeated .Buffers.Unit unitList = 3;
  inline int unitlist_size() const;
  inline void clear_unitlist();
  static const int kUnitListFieldNumber = 3;
  inline const ::Buffers::Unit& unitlist(int index) const;
  inline ::Buffers::Unit* mutable_unitlist(int index);
  inline ::Buffers::Unit* add_unitlist();
  inline const ::google::protobuf::RepeatedPtrField< ::Buffers::Unit >&
      unitlist() const;
  inline ::google::protobuf::RepeatedPtrField< ::Buffers::Unit >*
      mutable_unitlist();

  // @@protoc_insertion_point(class_scope:Buffers.MovementOrder)
 private:
  inline void set_has_source();
  inline void clear_has_source();
  inline void set_has_destination();
  inline void clear_has_destination();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::Buffers::Location* source_;
  ::Buffers::Location* destination_;
  ::google::protobuf::RepeatedPtrField< ::Buffers::Unit > unitlist_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_MovementOrder_2eproto();
  friend void protobuf_AssignDesc_MovementOrder_2eproto();
  friend void protobuf_ShutdownFile_MovementOrder_2eproto();

  void InitAsDefaultInstance();
  static MovementOrder* default_instance_;
};
// ===================================================================


// ===================================================================

// MovementOrder

// required .Buffers.Location source = 1;
inline bool MovementOrder::has_source() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void MovementOrder::set_has_source() {
  _has_bits_[0] |= 0x00000001u;
}
inline void MovementOrder::clear_has_source() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void MovementOrder::clear_source() {
  if (source_ != NULL) source_->::Buffers::Location::Clear();
  clear_has_source();
}
inline const ::Buffers::Location& MovementOrder::source() const {
  return source_ != NULL ? *source_ : *default_instance_->source_;
}
inline ::Buffers::Location* MovementOrder::mutable_source() {
  set_has_source();
  if (source_ == NULL) source_ = new ::Buffers::Location;
  return source_;
}
inline ::Buffers::Location* MovementOrder::release_source() {
  clear_has_source();
  ::Buffers::Location* temp = source_;
  source_ = NULL;
  return temp;
}
inline void MovementOrder::set_allocated_source(::Buffers::Location* source) {
  delete source_;
  source_ = source;
  if (source) {
    set_has_source();
  } else {
    clear_has_source();
  }
}

// required .Buffers.Location destination = 2;
inline bool MovementOrder::has_destination() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void MovementOrder::set_has_destination() {
  _has_bits_[0] |= 0x00000002u;
}
inline void MovementOrder::clear_has_destination() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void MovementOrder::clear_destination() {
  if (destination_ != NULL) destination_->::Buffers::Location::Clear();
  clear_has_destination();
}
inline const ::Buffers::Location& MovementOrder::destination() const {
  return destination_ != NULL ? *destination_ : *default_instance_->destination_;
}
inline ::Buffers::Location* MovementOrder::mutable_destination() {
  set_has_destination();
  if (destination_ == NULL) destination_ = new ::Buffers::Location;
  return destination_;
}
inline ::Buffers::Location* MovementOrder::release_destination() {
  clear_has_destination();
  ::Buffers::Location* temp = destination_;
  destination_ = NULL;
  return temp;
}
inline void MovementOrder::set_allocated_destination(::Buffers::Location* destination) {
  delete destination_;
  destination_ = destination;
  if (destination) {
    set_has_destination();
  } else {
    clear_has_destination();
  }
}

// repeated .Buffers.Unit unitList = 3;
inline int MovementOrder::unitlist_size() const {
  return unitlist_.size();
}
inline void MovementOrder::clear_unitlist() {
  unitlist_.Clear();
}
inline const ::Buffers::Unit& MovementOrder::unitlist(int index) const {
  return unitlist_.Get(index);
}
inline ::Buffers::Unit* MovementOrder::mutable_unitlist(int index) {
  return unitlist_.Mutable(index);
}
inline ::Buffers::Unit* MovementOrder::add_unitlist() {
  return unitlist_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::Buffers::Unit >&
MovementOrder::unitlist() const {
  return unitlist_;
}
inline ::google::protobuf::RepeatedPtrField< ::Buffers::Unit >*
MovementOrder::mutable_unitlist() {
  return &unitlist_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Buffers

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_MovementOrder_2eproto__INCLUDED
