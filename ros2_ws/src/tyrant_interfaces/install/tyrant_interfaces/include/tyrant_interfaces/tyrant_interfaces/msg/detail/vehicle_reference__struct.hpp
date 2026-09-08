// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tyrant_interfaces:msg/VehicleReference.idl
// generated code does not contain a copyright notice

#ifndef TYRANT_INTERFACES__MSG__DETAIL__VEHICLE_REFERENCE__STRUCT_HPP_
#define TYRANT_INTERFACES__MSG__DETAIL__VEHICLE_REFERENCE__STRUCT_HPP_

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
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.hpp"
// Member 'linear_velocity'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tyrant_interfaces__msg__VehicleReference __attribute__((deprecated))
#else
# define DEPRECATED__tyrant_interfaces__msg__VehicleReference __declspec(deprecated)
#endif

namespace tyrant_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VehicleReference_
{
  using Type = VehicleReference_<ContainerAllocator>;

  explicit VehicleReference_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    position(_init),
    linear_velocity(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->roll = 0.0f;
      this->pitch = 0.0f;
      this->yaw = 0.0f;
    }
  }

  explicit VehicleReference_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    position(_alloc, _init),
    linear_velocity(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->roll = 0.0f;
      this->pitch = 0.0f;
      this->yaw = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _position_type position;
  using _linear_velocity_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _linear_velocity_type linear_velocity;
  using _roll_type =
    float;
  _roll_type roll;
  using _pitch_type =
    float;
  _pitch_type pitch;
  using _yaw_type =
    float;
  _yaw_type yaw;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__linear_velocity(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->linear_velocity = _arg;
    return *this;
  }
  Type & set__roll(
    const float & _arg)
  {
    this->roll = _arg;
    return *this;
  }
  Type & set__pitch(
    const float & _arg)
  {
    this->pitch = _arg;
    return *this;
  }
  Type & set__yaw(
    const float & _arg)
  {
    this->yaw = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tyrant_interfaces::msg::VehicleReference_<ContainerAllocator> *;
  using ConstRawPtr =
    const tyrant_interfaces::msg::VehicleReference_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tyrant_interfaces::msg::VehicleReference_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tyrant_interfaces::msg::VehicleReference_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tyrant_interfaces::msg::VehicleReference_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tyrant_interfaces::msg::VehicleReference_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tyrant_interfaces::msg::VehicleReference_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tyrant_interfaces::msg::VehicleReference_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tyrant_interfaces::msg::VehicleReference_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tyrant_interfaces::msg::VehicleReference_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tyrant_interfaces__msg__VehicleReference
    std::shared_ptr<tyrant_interfaces::msg::VehicleReference_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tyrant_interfaces__msg__VehicleReference
    std::shared_ptr<tyrant_interfaces::msg::VehicleReference_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VehicleReference_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->linear_velocity != other.linear_velocity) {
      return false;
    }
    if (this->roll != other.roll) {
      return false;
    }
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    return true;
  }
  bool operator!=(const VehicleReference_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VehicleReference_

// alias to use template instance with default allocator
using VehicleReference =
  tyrant_interfaces::msg::VehicleReference_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tyrant_interfaces

#endif  // TYRANT_INTERFACES__MSG__DETAIL__VEHICLE_REFERENCE__STRUCT_HPP_
