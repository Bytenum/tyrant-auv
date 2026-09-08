// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tyrant_interfaces:msg/ModeRequest.idl
// generated code does not contain a copyright notice

#ifndef TYRANT_INTERFACES__MSG__DETAIL__MODE_REQUEST__TRAITS_HPP_
#define TYRANT_INTERFACES__MSG__DETAIL__MODE_REQUEST__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tyrant_interfaces/msg/detail/mode_request__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace tyrant_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ModeRequest & msg,
  std::ostream & out)
{
  out << "{";
  // member: request_id
  {
    out << "request_id: ";
    rosidl_generator_traits::value_to_yaml(msg.request_id, out);
    out << ", ";
  }

  // member: requested_mode
  {
    out << "requested_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.requested_mode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ModeRequest & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: request_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "request_id: ";
    rosidl_generator_traits::value_to_yaml(msg.request_id, out);
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ModeRequest & msg, bool use_flow_style = false)
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
  const tyrant_interfaces::msg::ModeRequest & msg,
  std::ostream & out, size_t indentation = 0)
{
  tyrant_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tyrant_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const tyrant_interfaces::msg::ModeRequest & msg)
{
  return tyrant_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tyrant_interfaces::msg::ModeRequest>()
{
  return "tyrant_interfaces::msg::ModeRequest";
}

template<>
inline const char * name<tyrant_interfaces::msg::ModeRequest>()
{
  return "tyrant_interfaces/msg/ModeRequest";
}

template<>
struct has_fixed_size<tyrant_interfaces::msg::ModeRequest>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<tyrant_interfaces::msg::ModeRequest>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<tyrant_interfaces::msg::ModeRequest>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TYRANT_INTERFACES__MSG__DETAIL__MODE_REQUEST__TRAITS_HPP_
