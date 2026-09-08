// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tyrant_interfaces:msg/SystemHealth.idl
// generated code does not contain a copyright notice

#ifndef TYRANT_INTERFACES__MSG__DETAIL__SYSTEM_HEALTH__TRAITS_HPP_
#define TYRANT_INTERFACES__MSG__DETAIL__SYSTEM_HEALTH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tyrant_interfaces/msg/detail/system_health__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace tyrant_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const SystemHealth & msg,
  std::ostream & out)
{
  out << "{";
  // member: communication_healthy
  {
    out << "communication_healthy: ";
    rosidl_generator_traits::value_to_yaml(msg.communication_healthy, out);
    out << ", ";
  }

  // member: autonomy_ready
  {
    out << "autonomy_ready: ";
    rosidl_generator_traits::value_to_yaml(msg.autonomy_ready, out);
    out << ", ";
  }

  // member: propulsion_allowed
  {
    out << "propulsion_allowed: ";
    rosidl_generator_traits::value_to_yaml(msg.propulsion_allowed, out);
    out << ", ";
  }

  // member: current_mode
  {
    out << "current_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.current_mode, out);
    out << ", ";
  }

  // member: host_heartbeat_age_ms
  {
    out << "host_heartbeat_age_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.host_heartbeat_age_ms, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SystemHealth & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: communication_healthy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "communication_healthy: ";
    rosidl_generator_traits::value_to_yaml(msg.communication_healthy, out);
    out << "\n";
  }

  // member: autonomy_ready
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "autonomy_ready: ";
    rosidl_generator_traits::value_to_yaml(msg.autonomy_ready, out);
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

  // member: current_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.current_mode, out);
    out << "\n";
  }

  // member: host_heartbeat_age_ms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "host_heartbeat_age_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.host_heartbeat_age_ms, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SystemHealth & msg, bool use_flow_style = false)
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
  const tyrant_interfaces::msg::SystemHealth & msg,
  std::ostream & out, size_t indentation = 0)
{
  tyrant_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tyrant_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const tyrant_interfaces::msg::SystemHealth & msg)
{
  return tyrant_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tyrant_interfaces::msg::SystemHealth>()
{
  return "tyrant_interfaces::msg::SystemHealth";
}

template<>
inline const char * name<tyrant_interfaces::msg::SystemHealth>()
{
  return "tyrant_interfaces/msg/SystemHealth";
}

template<>
struct has_fixed_size<tyrant_interfaces::msg::SystemHealth>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<tyrant_interfaces::msg::SystemHealth>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<tyrant_interfaces::msg::SystemHealth>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TYRANT_INTERFACES__MSG__DETAIL__SYSTEM_HEALTH__TRAITS_HPP_
