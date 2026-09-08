// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tyrant_interfaces:msg/SystemHealth.idl
// generated code does not contain a copyright notice

#ifndef TYRANT_INTERFACES__MSG__DETAIL__SYSTEM_HEALTH__STRUCT_HPP_
#define TYRANT_INTERFACES__MSG__DETAIL__SYSTEM_HEALTH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__tyrant_interfaces__msg__SystemHealth __attribute__((deprecated))
#else
# define DEPRECATED__tyrant_interfaces__msg__SystemHealth __declspec(deprecated)
#endif

namespace tyrant_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SystemHealth_
{
  using Type = SystemHealth_<ContainerAllocator>;

  explicit SystemHealth_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->communication_healthy = false;
      this->autonomy_ready = false;
      this->propulsion_allowed = false;
      this->current_mode = 0;
      this->host_heartbeat_age_ms = 0ul;
    }
  }

  explicit SystemHealth_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->communication_healthy = false;
      this->autonomy_ready = false;
      this->propulsion_allowed = false;
      this->current_mode = 0;
      this->host_heartbeat_age_ms = 0ul;
    }
  }

  // field types and members
  using _communication_healthy_type =
    bool;
  _communication_healthy_type communication_healthy;
  using _autonomy_ready_type =
    bool;
  _autonomy_ready_type autonomy_ready;
  using _propulsion_allowed_type =
    bool;
  _propulsion_allowed_type propulsion_allowed;
  using _current_mode_type =
    uint8_t;
  _current_mode_type current_mode;
  using _host_heartbeat_age_ms_type =
    uint32_t;
  _host_heartbeat_age_ms_type host_heartbeat_age_ms;

  // setters for named parameter idiom
  Type & set__communication_healthy(
    const bool & _arg)
  {
    this->communication_healthy = _arg;
    return *this;
  }
  Type & set__autonomy_ready(
    const bool & _arg)
  {
    this->autonomy_ready = _arg;
    return *this;
  }
  Type & set__propulsion_allowed(
    const bool & _arg)
  {
    this->propulsion_allowed = _arg;
    return *this;
  }
  Type & set__current_mode(
    const uint8_t & _arg)
  {
    this->current_mode = _arg;
    return *this;
  }
  Type & set__host_heartbeat_age_ms(
    const uint32_t & _arg)
  {
    this->host_heartbeat_age_ms = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tyrant_interfaces::msg::SystemHealth_<ContainerAllocator> *;
  using ConstRawPtr =
    const tyrant_interfaces::msg::SystemHealth_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tyrant_interfaces::msg::SystemHealth_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tyrant_interfaces::msg::SystemHealth_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tyrant_interfaces::msg::SystemHealth_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tyrant_interfaces::msg::SystemHealth_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tyrant_interfaces::msg::SystemHealth_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tyrant_interfaces::msg::SystemHealth_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tyrant_interfaces::msg::SystemHealth_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tyrant_interfaces::msg::SystemHealth_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tyrant_interfaces__msg__SystemHealth
    std::shared_ptr<tyrant_interfaces::msg::SystemHealth_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tyrant_interfaces__msg__SystemHealth
    std::shared_ptr<tyrant_interfaces::msg::SystemHealth_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SystemHealth_ & other) const
  {
    if (this->communication_healthy != other.communication_healthy) {
      return false;
    }
    if (this->autonomy_ready != other.autonomy_ready) {
      return false;
    }
    if (this->propulsion_allowed != other.propulsion_allowed) {
      return false;
    }
    if (this->current_mode != other.current_mode) {
      return false;
    }
    if (this->host_heartbeat_age_ms != other.host_heartbeat_age_ms) {
      return false;
    }
    return true;
  }
  bool operator!=(const SystemHealth_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SystemHealth_

// alias to use template instance with default allocator
using SystemHealth =
  tyrant_interfaces::msg::SystemHealth_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tyrant_interfaces

#endif  // TYRANT_INTERFACES__MSG__DETAIL__SYSTEM_HEALTH__STRUCT_HPP_
