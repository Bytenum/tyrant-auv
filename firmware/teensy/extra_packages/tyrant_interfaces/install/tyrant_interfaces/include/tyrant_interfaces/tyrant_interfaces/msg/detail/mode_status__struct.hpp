// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tyrant_interfaces:msg/ModeStatus.idl
// generated code does not contain a copyright notice

#ifndef TYRANT_INTERFACES__MSG__DETAIL__MODE_STATUS__STRUCT_HPP_
#define TYRANT_INTERFACES__MSG__DETAIL__MODE_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tyrant_interfaces__msg__ModeStatus __attribute__((deprecated))
#else
# define DEPRECATED__tyrant_interfaces__msg__ModeStatus __declspec(deprecated)
#endif

namespace tyrant_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ModeStatus_
{
  using Type = ModeStatus_<ContainerAllocator>;

  explicit ModeStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->request_id = 0ul;
      this->current_mode = 0;
      this->requested_mode = 0;
      this->request_accepted = false;
      this->reason = 0;
      this->communication_healthy = false;
      this->propulsion_allowed = false;
    }
  }

  explicit ModeStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->request_id = 0ul;
      this->current_mode = 0;
      this->requested_mode = 0;
      this->request_accepted = false;
      this->reason = 0;
      this->communication_healthy = false;
      this->propulsion_allowed = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _request_id_type =
    uint32_t;
  _request_id_type request_id;
  using _current_mode_type =
    uint8_t;
  _current_mode_type current_mode;
  using _requested_mode_type =
    uint8_t;
  _requested_mode_type requested_mode;
  using _request_accepted_type =
    bool;
  _request_accepted_type request_accepted;
  using _reason_type =
    uint8_t;
  _reason_type reason;
  using _communication_healthy_type =
    bool;
  _communication_healthy_type communication_healthy;
  using _propulsion_allowed_type =
    bool;
  _propulsion_allowed_type propulsion_allowed;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__request_id(
    const uint32_t & _arg)
  {
    this->request_id = _arg;
    return *this;
  }
  Type & set__current_mode(
    const uint8_t & _arg)
  {
    this->current_mode = _arg;
    return *this;
  }
  Type & set__requested_mode(
    const uint8_t & _arg)
  {
    this->requested_mode = _arg;
    return *this;
  }
  Type & set__request_accepted(
    const bool & _arg)
  {
    this->request_accepted = _arg;
    return *this;
  }
  Type & set__reason(
    const uint8_t & _arg)
  {
    this->reason = _arg;
    return *this;
  }
  Type & set__communication_healthy(
    const bool & _arg)
  {
    this->communication_healthy = _arg;
    return *this;
  }
  Type & set__propulsion_allowed(
    const bool & _arg)
  {
    this->propulsion_allowed = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t BOOT =
    0u;
  static constexpr uint8_t IDLE =
    1u;
  static constexpr uint8_t MANUAL =
    2u;
  static constexpr uint8_t AUTO =
    3u;
  static constexpr uint8_t SAFE =
    4u;
  static constexpr uint8_t FAULT =
    5u;
  static constexpr uint8_t EMERGENCY =
    6u;
  static constexpr uint8_t REASON_NONE =
    0u;
  static constexpr uint8_t REASON_REQUEST_ACCEPTED =
    1u;
  static constexpr uint8_t REASON_INVALID_MODE =
    2u;
  static constexpr uint8_t REASON_TRANSITION_NOT_ALLOWED =
    3u;
  static constexpr uint8_t REASON_SYSTEM_UNHEALTHY =
    4u;
  static constexpr uint8_t REASON_AUTONOMY_NOT_READY =
    5u;
  static constexpr uint8_t REASON_COMMUNICATION_TIMEOUT =
    6u;
  static constexpr uint8_t REASON_FAULT_LATCHED =
    7u;
  static constexpr uint8_t REASON_EMERGENCY_LATCHED =
    8u;

  // pointer types
  using RawPtr =
    tyrant_interfaces::msg::ModeStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const tyrant_interfaces::msg::ModeStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tyrant_interfaces::msg::ModeStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tyrant_interfaces::msg::ModeStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tyrant_interfaces::msg::ModeStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tyrant_interfaces::msg::ModeStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tyrant_interfaces::msg::ModeStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tyrant_interfaces::msg::ModeStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tyrant_interfaces::msg::ModeStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tyrant_interfaces::msg::ModeStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tyrant_interfaces__msg__ModeStatus
    std::shared_ptr<tyrant_interfaces::msg::ModeStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tyrant_interfaces__msg__ModeStatus
    std::shared_ptr<tyrant_interfaces::msg::ModeStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ModeStatus_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->request_id != other.request_id) {
      return false;
    }
    if (this->current_mode != other.current_mode) {
      return false;
    }
    if (this->requested_mode != other.requested_mode) {
      return false;
    }
    if (this->request_accepted != other.request_accepted) {
      return false;
    }
    if (this->reason != other.reason) {
      return false;
    }
    if (this->communication_healthy != other.communication_healthy) {
      return false;
    }
    if (this->propulsion_allowed != other.propulsion_allowed) {
      return false;
    }
    return true;
  }
  bool operator!=(const ModeStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ModeStatus_

// alias to use template instance with default allocator
using ModeStatus =
  tyrant_interfaces::msg::ModeStatus_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ModeStatus_<ContainerAllocator>::BOOT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ModeStatus_<ContainerAllocator>::IDLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ModeStatus_<ContainerAllocator>::MANUAL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ModeStatus_<ContainerAllocator>::AUTO;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ModeStatus_<ContainerAllocator>::SAFE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ModeStatus_<ContainerAllocator>::FAULT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ModeStatus_<ContainerAllocator>::EMERGENCY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ModeStatus_<ContainerAllocator>::REASON_NONE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ModeStatus_<ContainerAllocator>::REASON_REQUEST_ACCEPTED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ModeStatus_<ContainerAllocator>::REASON_INVALID_MODE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ModeStatus_<ContainerAllocator>::REASON_TRANSITION_NOT_ALLOWED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ModeStatus_<ContainerAllocator>::REASON_SYSTEM_UNHEALTHY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ModeStatus_<ContainerAllocator>::REASON_AUTONOMY_NOT_READY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ModeStatus_<ContainerAllocator>::REASON_COMMUNICATION_TIMEOUT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ModeStatus_<ContainerAllocator>::REASON_FAULT_LATCHED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ModeStatus_<ContainerAllocator>::REASON_EMERGENCY_LATCHED;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace tyrant_interfaces

#endif  // TYRANT_INTERFACES__MSG__DETAIL__MODE_STATUS__STRUCT_HPP_
