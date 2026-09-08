// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tyrant_interfaces:msg/ModeRequest.idl
// generated code does not contain a copyright notice

#ifndef TYRANT_INTERFACES__MSG__DETAIL__MODE_REQUEST__STRUCT_HPP_
#define TYRANT_INTERFACES__MSG__DETAIL__MODE_REQUEST__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__tyrant_interfaces__msg__ModeRequest __attribute__((deprecated))
#else
# define DEPRECATED__tyrant_interfaces__msg__ModeRequest __declspec(deprecated)
#endif

namespace tyrant_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ModeRequest_
{
  using Type = ModeRequest_<ContainerAllocator>;

  explicit ModeRequest_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->request_id = 0ul;
      this->requested_mode = 0;
    }
  }

  explicit ModeRequest_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->request_id = 0ul;
      this->requested_mode = 0;
    }
  }

  // field types and members
  using _request_id_type =
    uint32_t;
  _request_id_type request_id;
  using _requested_mode_type =
    uint8_t;
  _requested_mode_type requested_mode;

  // setters for named parameter idiom
  Type & set__request_id(
    const uint32_t & _arg)
  {
    this->request_id = _arg;
    return *this;
  }
  Type & set__requested_mode(
    const uint8_t & _arg)
  {
    this->requested_mode = _arg;
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

  // pointer types
  using RawPtr =
    tyrant_interfaces::msg::ModeRequest_<ContainerAllocator> *;
  using ConstRawPtr =
    const tyrant_interfaces::msg::ModeRequest_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tyrant_interfaces::msg::ModeRequest_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tyrant_interfaces::msg::ModeRequest_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tyrant_interfaces::msg::ModeRequest_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tyrant_interfaces::msg::ModeRequest_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tyrant_interfaces::msg::ModeRequest_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tyrant_interfaces::msg::ModeRequest_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tyrant_interfaces::msg::ModeRequest_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tyrant_interfaces::msg::ModeRequest_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tyrant_interfaces__msg__ModeRequest
    std::shared_ptr<tyrant_interfaces::msg::ModeRequest_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tyrant_interfaces__msg__ModeRequest
    std::shared_ptr<tyrant_interfaces::msg::ModeRequest_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ModeRequest_ & other) const
  {
    if (this->request_id != other.request_id) {
      return false;
    }
    if (this->requested_mode != other.requested_mode) {
      return false;
    }
    return true;
  }
  bool operator!=(const ModeRequest_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ModeRequest_

// alias to use template instance with default allocator
using ModeRequest =
  tyrant_interfaces::msg::ModeRequest_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ModeRequest_<ContainerAllocator>::BOOT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ModeRequest_<ContainerAllocator>::IDLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ModeRequest_<ContainerAllocator>::MANUAL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ModeRequest_<ContainerAllocator>::AUTO;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ModeRequest_<ContainerAllocator>::SAFE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ModeRequest_<ContainerAllocator>::FAULT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t ModeRequest_<ContainerAllocator>::EMERGENCY;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace tyrant_interfaces

#endif  // TYRANT_INTERFACES__MSG__DETAIL__MODE_REQUEST__STRUCT_HPP_
