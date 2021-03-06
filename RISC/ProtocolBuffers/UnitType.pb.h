// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: UnitType.proto

#ifndef PROTOBUF_UnitType_2eproto__INCLUDED
#define PROTOBUF_UnitType_2eproto__INCLUDED

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
// @@protoc_insertion_point(includes)

namespace Buffers {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_UnitType_2eproto();
void protobuf_AssignDesc_UnitType_2eproto();
void protobuf_ShutdownFile_UnitType_2eproto();

class UnitType;

// ===================================================================

class UnitType : public ::google::protobuf::Message {
 public:
  UnitType();
  virtual ~UnitType();

  UnitType(const UnitType& from);

  inline UnitType& operator=(const UnitType& from) {
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
  static const UnitType& default_instance();

  void Swap(UnitType* other);

  // implements Message ----------------------------------------------

  UnitType* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const UnitType& from);
  void MergeFrom(const UnitType& from);
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

  // required int32 level = 1;
  inline bool has_level() const;
  inline void clear_level();
  static const int kLevelFieldNumber = 1;
  inline ::google::protobuf::int32 level() const;
  inline void set_level(::google::protobuf::int32 value);

  // required string type = 2;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 2;
  inline const ::std::string& type() const;
  inline void set_type(const ::std::string& value);
  inline void set_type(const char* value);
  inline void set_type(const char* value, size_t size);
  inline ::std::string* mutable_type();
  inline ::std::string* release_type();
  inline void set_allocated_type(::std::string* type);

  // required int32 combatBonus = 3;
  inline bool has_combatbonus() const;
  inline void clear_combatbonus();
  static const int kCombatBonusFieldNumber = 3;
  inline ::google::protobuf::int32 combatbonus() const;
  inline void set_combatbonus(::google::protobuf::int32 value);

  // required int32 upgradeCost = 4;
  inline bool has_upgradecost() const;
  inline void clear_upgradecost();
  static const int kUpgradeCostFieldNumber = 4;
  inline ::google::protobuf::int32 upgradecost() const;
  inline void set_upgradecost(::google::protobuf::int32 value);

  // required int32 costToUnlock = 5;
  inline bool has_costtounlock() const;
  inline void clear_costtounlock();
  static const int kCostToUnlockFieldNumber = 5;
  inline ::google::protobuf::int32 costtounlock() const;
  inline void set_costtounlock(::google::protobuf::int32 value);

  // required bool spy = 6;
  inline bool has_spy() const;
  inline void clear_spy();
  static const int kSpyFieldNumber = 6;
  inline bool spy() const;
  inline void set_spy(bool value);

  // required string nextType = 7;
  inline bool has_nexttype() const;
  inline void clear_nexttype();
  static const int kNextTypeFieldNumber = 7;
  inline const ::std::string& nexttype() const;
  inline void set_nexttype(const ::std::string& value);
  inline void set_nexttype(const char* value);
  inline void set_nexttype(const char* value, size_t size);
  inline ::std::string* mutable_nexttype();
  inline ::std::string* release_nexttype();
  inline void set_allocated_nexttype(::std::string* nexttype);

  // required string previousType = 8;
  inline bool has_previoustype() const;
  inline void clear_previoustype();
  static const int kPreviousTypeFieldNumber = 8;
  inline const ::std::string& previoustype() const;
  inline void set_previoustype(const ::std::string& value);
  inline void set_previoustype(const char* value);
  inline void set_previoustype(const char* value, size_t size);
  inline ::std::string* mutable_previoustype();
  inline ::std::string* release_previoustype();
  inline void set_allocated_previoustype(::std::string* previoustype);

  // @@protoc_insertion_point(class_scope:Buffers.UnitType)
 private:
  inline void set_has_level();
  inline void clear_has_level();
  inline void set_has_type();
  inline void clear_has_type();
  inline void set_has_combatbonus();
  inline void clear_has_combatbonus();
  inline void set_has_upgradecost();
  inline void clear_has_upgradecost();
  inline void set_has_costtounlock();
  inline void clear_has_costtounlock();
  inline void set_has_spy();
  inline void clear_has_spy();
  inline void set_has_nexttype();
  inline void clear_has_nexttype();
  inline void set_has_previoustype();
  inline void clear_has_previoustype();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* type_;
  ::google::protobuf::int32 level_;
  ::google::protobuf::int32 combatbonus_;
  ::google::protobuf::int32 upgradecost_;
  ::google::protobuf::int32 costtounlock_;
  ::std::string* nexttype_;
  ::std::string* previoustype_;
  bool spy_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(8 + 31) / 32];

  friend void  protobuf_AddDesc_UnitType_2eproto();
  friend void protobuf_AssignDesc_UnitType_2eproto();
  friend void protobuf_ShutdownFile_UnitType_2eproto();

  void InitAsDefaultInstance();
  static UnitType* default_instance_;
};
// ===================================================================


// ===================================================================

// UnitType

// required int32 level = 1;
inline bool UnitType::has_level() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void UnitType::set_has_level() {
  _has_bits_[0] |= 0x00000001u;
}
inline void UnitType::clear_has_level() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void UnitType::clear_level() {
  level_ = 0;
  clear_has_level();
}
inline ::google::protobuf::int32 UnitType::level() const {
  return level_;
}
inline void UnitType::set_level(::google::protobuf::int32 value) {
  set_has_level();
  level_ = value;
}

// required string type = 2;
inline bool UnitType::has_type() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void UnitType::set_has_type() {
  _has_bits_[0] |= 0x00000002u;
}
inline void UnitType::clear_has_type() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void UnitType::clear_type() {
  if (type_ != &::google::protobuf::internal::kEmptyString) {
    type_->clear();
  }
  clear_has_type();
}
inline const ::std::string& UnitType::type() const {
  return *type_;
}
inline void UnitType::set_type(const ::std::string& value) {
  set_has_type();
  if (type_ == &::google::protobuf::internal::kEmptyString) {
    type_ = new ::std::string;
  }
  type_->assign(value);
}
inline void UnitType::set_type(const char* value) {
  set_has_type();
  if (type_ == &::google::protobuf::internal::kEmptyString) {
    type_ = new ::std::string;
  }
  type_->assign(value);
}
inline void UnitType::set_type(const char* value, size_t size) {
  set_has_type();
  if (type_ == &::google::protobuf::internal::kEmptyString) {
    type_ = new ::std::string;
  }
  type_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* UnitType::mutable_type() {
  set_has_type();
  if (type_ == &::google::protobuf::internal::kEmptyString) {
    type_ = new ::std::string;
  }
  return type_;
}
inline ::std::string* UnitType::release_type() {
  clear_has_type();
  if (type_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = type_;
    type_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void UnitType::set_allocated_type(::std::string* type) {
  if (type_ != &::google::protobuf::internal::kEmptyString) {
    delete type_;
  }
  if (type) {
    set_has_type();
    type_ = type;
  } else {
    clear_has_type();
    type_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required int32 combatBonus = 3;
inline bool UnitType::has_combatbonus() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void UnitType::set_has_combatbonus() {
  _has_bits_[0] |= 0x00000004u;
}
inline void UnitType::clear_has_combatbonus() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void UnitType::clear_combatbonus() {
  combatbonus_ = 0;
  clear_has_combatbonus();
}
inline ::google::protobuf::int32 UnitType::combatbonus() const {
  return combatbonus_;
}
inline void UnitType::set_combatbonus(::google::protobuf::int32 value) {
  set_has_combatbonus();
  combatbonus_ = value;
}

// required int32 upgradeCost = 4;
inline bool UnitType::has_upgradecost() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void UnitType::set_has_upgradecost() {
  _has_bits_[0] |= 0x00000008u;
}
inline void UnitType::clear_has_upgradecost() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void UnitType::clear_upgradecost() {
  upgradecost_ = 0;
  clear_has_upgradecost();
}
inline ::google::protobuf::int32 UnitType::upgradecost() const {
  return upgradecost_;
}
inline void UnitType::set_upgradecost(::google::protobuf::int32 value) {
  set_has_upgradecost();
  upgradecost_ = value;
}

// required int32 costToUnlock = 5;
inline bool UnitType::has_costtounlock() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void UnitType::set_has_costtounlock() {
  _has_bits_[0] |= 0x00000010u;
}
inline void UnitType::clear_has_costtounlock() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void UnitType::clear_costtounlock() {
  costtounlock_ = 0;
  clear_has_costtounlock();
}
inline ::google::protobuf::int32 UnitType::costtounlock() const {
  return costtounlock_;
}
inline void UnitType::set_costtounlock(::google::protobuf::int32 value) {
  set_has_costtounlock();
  costtounlock_ = value;
}

// required bool spy = 6;
inline bool UnitType::has_spy() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void UnitType::set_has_spy() {
  _has_bits_[0] |= 0x00000020u;
}
inline void UnitType::clear_has_spy() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void UnitType::clear_spy() {
  spy_ = false;
  clear_has_spy();
}
inline bool UnitType::spy() const {
  return spy_;
}
inline void UnitType::set_spy(bool value) {
  set_has_spy();
  spy_ = value;
}

// required string nextType = 7;
inline bool UnitType::has_nexttype() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void UnitType::set_has_nexttype() {
  _has_bits_[0] |= 0x00000040u;
}
inline void UnitType::clear_has_nexttype() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void UnitType::clear_nexttype() {
  if (nexttype_ != &::google::protobuf::internal::kEmptyString) {
    nexttype_->clear();
  }
  clear_has_nexttype();
}
inline const ::std::string& UnitType::nexttype() const {
  return *nexttype_;
}
inline void UnitType::set_nexttype(const ::std::string& value) {
  set_has_nexttype();
  if (nexttype_ == &::google::protobuf::internal::kEmptyString) {
    nexttype_ = new ::std::string;
  }
  nexttype_->assign(value);
}
inline void UnitType::set_nexttype(const char* value) {
  set_has_nexttype();
  if (nexttype_ == &::google::protobuf::internal::kEmptyString) {
    nexttype_ = new ::std::string;
  }
  nexttype_->assign(value);
}
inline void UnitType::set_nexttype(const char* value, size_t size) {
  set_has_nexttype();
  if (nexttype_ == &::google::protobuf::internal::kEmptyString) {
    nexttype_ = new ::std::string;
  }
  nexttype_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* UnitType::mutable_nexttype() {
  set_has_nexttype();
  if (nexttype_ == &::google::protobuf::internal::kEmptyString) {
    nexttype_ = new ::std::string;
  }
  return nexttype_;
}
inline ::std::string* UnitType::release_nexttype() {
  clear_has_nexttype();
  if (nexttype_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = nexttype_;
    nexttype_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void UnitType::set_allocated_nexttype(::std::string* nexttype) {
  if (nexttype_ != &::google::protobuf::internal::kEmptyString) {
    delete nexttype_;
  }
  if (nexttype) {
    set_has_nexttype();
    nexttype_ = nexttype;
  } else {
    clear_has_nexttype();
    nexttype_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required string previousType = 8;
inline bool UnitType::has_previoustype() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void UnitType::set_has_previoustype() {
  _has_bits_[0] |= 0x00000080u;
}
inline void UnitType::clear_has_previoustype() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void UnitType::clear_previoustype() {
  if (previoustype_ != &::google::protobuf::internal::kEmptyString) {
    previoustype_->clear();
  }
  clear_has_previoustype();
}
inline const ::std::string& UnitType::previoustype() const {
  return *previoustype_;
}
inline void UnitType::set_previoustype(const ::std::string& value) {
  set_has_previoustype();
  if (previoustype_ == &::google::protobuf::internal::kEmptyString) {
    previoustype_ = new ::std::string;
  }
  previoustype_->assign(value);
}
inline void UnitType::set_previoustype(const char* value) {
  set_has_previoustype();
  if (previoustype_ == &::google::protobuf::internal::kEmptyString) {
    previoustype_ = new ::std::string;
  }
  previoustype_->assign(value);
}
inline void UnitType::set_previoustype(const char* value, size_t size) {
  set_has_previoustype();
  if (previoustype_ == &::google::protobuf::internal::kEmptyString) {
    previoustype_ = new ::std::string;
  }
  previoustype_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* UnitType::mutable_previoustype() {
  set_has_previoustype();
  if (previoustype_ == &::google::protobuf::internal::kEmptyString) {
    previoustype_ = new ::std::string;
  }
  return previoustype_;
}
inline ::std::string* UnitType::release_previoustype() {
  clear_has_previoustype();
  if (previoustype_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = previoustype_;
    previoustype_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void UnitType::set_allocated_previoustype(::std::string* previoustype) {
  if (previoustype_ != &::google::protobuf::internal::kEmptyString) {
    delete previoustype_;
  }
  if (previoustype) {
    set_has_previoustype();
    previoustype_ = previoustype;
  } else {
    clear_has_previoustype();
    previoustype_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
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

#endif  // PROTOBUF_UnitType_2eproto__INCLUDED
