// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tyrant_interfaces:msg/VehicleReference.idl
// generated code does not contain a copyright notice

#ifndef TYRANT_INTERFACES__MSG__DETAIL__VEHICLE_REFERENCE__TRAITS_HPP_
#define TYRANT_INTERFACES__MSG__DETAIL__VEHICLE_REFERENCE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tyrant_interfaces/msg/detail/vehicle_reference__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'position'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'linear_velocity'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace tyrant_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const VehicleReference & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: position
  {
    out << "position: ";
    to_flow_style_yaml(msg.position, out);
    out << ", ";
  }

  // member: linear_velocity
  {
    out << "linear_velocity: ";
    to_flow_style_yaml(msg.linear_velocity, out);
    out << ", ";
  }

  // member: roll
  {
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << ", ";
  }

  // member: pitch
  {
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << ", ";
  }

  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const VehicleReference & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position:\n";
    to_block_style_yaml(msg.position, out, indentation + 2);
  }

  // member: linear_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "linear_velocity:\n";
    to_block_style_yaml(msg.linear_velocity, out, indentation + 2);
  }

  // member: roll
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << "\n";
  }

  // member: pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << "\n";
  }

  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const VehicleReference & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace tyrant_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use tyrant_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tyrant_interfaces::msg::VehicleReference & msg,
  std::ostream & out, size_t indentation = 0)
{
  tyrant_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tyrant_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const tyrant_interfaces::msg::VehicleReference & msg)
{
  return tyrant_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tyrant_interfaces::msg::VehicleReference>()
{
  return "tyrant_interfaces::msg::VehicleReference";
}

template<>
inline const char * name<tyrant_interfaces::msg::VehicleReference>()
{
  return "tyrant_interfaces/msg/VehicleReference";
}

template<>
struct has_fixed_size<tyrant_interfaces::msg::VehicleReference>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value && has_fixed_size<geometry_msgs::msg::Vector3>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<tyrant_interfaces::msg::VehicleReference>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value && has_bounded_size<geometry_msgs::msg::Vector3>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<tyrant_interfaces::msg::VehicleReference>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TYRANT_INTERFACES__MSG__DETAIL__VEHICLE_REFERENCE__TRAITS_HPP_
