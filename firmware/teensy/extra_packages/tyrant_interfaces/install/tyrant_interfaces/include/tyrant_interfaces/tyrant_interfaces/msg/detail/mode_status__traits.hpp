// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tyrant_interfaces:msg/ModeStatus.idl
// generated code does not contain a copyright notice

#ifndef TYRANT_INTERFACES__MSG__DETAIL__MODE_STATUS__TRAITS_HPP_
#define TYRANT_INTERFACES__MSG__DETAIL__MODE_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tyrant_interfaces/msg/detail/mode_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace tyrant_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ModeStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: request_id
  {
    out << "request_id: ";
    rosidl_generator_traits::value_to_yaml(msg.request_id, out);
    out << ", ";
  }

  // member: current_mode
  {
    out << "current_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.current_mode, out);
    out << ", ";
  }

  // member: requested_mode
  {
    out << "requested_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.requested_mode, out);
    out << ", ";
  }

  // member: request_accepted
  {
    out << "request_accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.request_accepted, out);
    out << ", ";
  }

  // member: reason
  {
    out << "reason: ";
    rosidl_generator_traits::value_to_yaml(msg.reason, out);
    out << ", ";
  }

  // member: communication_healthy
  {
    out << "communication_healthy: ";
    rosidl_generator_traits::value_to_yaml(msg.communication_healthy, out);
    out << ", ";
  }

  // member: propulsion_allowed
  {
    out << "propulsion_allowed: ";
    rosidl_generator_traits::value_to_yaml(msg.propulsion_allowed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ModeStatus & msg,
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

  // member: request_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "request_id: ";
    rosidl_generator_traits::value_to_yaml(msg.request_id, out);
    out << "\n";
  }

  // member: current_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.current_mode, out);
    out << "\n";
  }

  // member: requested_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "requested_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.requested_mode, out);
    out << "\n";
  }

  // member: request_accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "request_accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.request_accepted, out);
    out << "\n";
  }

  // member: reason
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reason: ";
    rosidl_generator_traits::value_to_yaml(msg.reason, out);
    out << "\n";
  }

  // member: communication_healthy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "communication_healthy: ";
    rosidl_generator_traits::value_to_yaml(msg.communication_healthy, out);
    out << "\n";
  }

  // member: propulsion_allowed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "propulsion_allowed: ";
    rosidl_generator_traits::value_to_yaml(msg.propulsion_allowed, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ModeStatus & msg, bool use_flow_style = false)
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
  const tyrant_interfaces::msg::ModeStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  tyrant_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tyrant_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const tyrant_interfaces::msg::ModeStatus & msg)
{
  return tyrant_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tyrant_interfaces::msg::ModeStatus>()
{
  return "tyrant_interfaces::msg::ModeStatus";
}

template<>
inline const char * name<tyrant_interfaces::msg::ModeStatus>()
{
  return "tyrant_interfaces/msg/ModeStatus";
}

template<>
struct has_fixed_size<tyrant_interfaces::msg::ModeStatus>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<tyrant_interfaces::msg::ModeStatus>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<tyrant_interfaces::msg::ModeStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TYRANT_INTERFACES__MSG__DETAIL__MODE_STATUS__TRAITS_HPP_
