// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tyrant_interfaces:msg/SystemHealth.idl
// generated code does not contain a copyright notice

#ifndef TYRANT_INTERFACES__MSG__DETAIL__SYSTEM_HEALTH__BUILDER_HPP_
#define TYRANT_INTERFACES__MSG__DETAIL__SYSTEM_HEALTH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tyrant_interfaces/msg/detail/system_health__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tyrant_interfaces
{

namespace msg
{

namespace builder
{

class Init_SystemHealth_host_heartbeat_age_ms
{
public:
  explicit Init_SystemHealth_host_heartbeat_age_ms(::tyrant_interfaces::msg::SystemHealth & msg)
  : msg_(msg)
  {}
  ::tyrant_interfaces::msg::SystemHealth host_heartbeat_age_ms(::tyrant_interfaces::msg::SystemHealth::_host_heartbeat_age_ms_type arg)
  {
    msg_.host_heartbeat_age_ms = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tyrant_interfaces::msg::SystemHealth msg_;
};

class Init_SystemHealth_current_mode
{
public:
  explicit Init_SystemHealth_current_mode(::tyrant_interfaces::msg::SystemHealth & msg)
  : msg_(msg)
  {}
  Init_SystemHealth_host_heartbeat_age_ms current_mode(::tyrant_interfaces::msg::SystemHealth::_current_mode_type arg)
  {
    msg_.current_mode = std::move(arg);
    return Init_SystemHealth_host_heartbeat_age_ms(msg_);
  }

private:
  ::tyrant_interfaces::msg::SystemHealth msg_;
};

class Init_SystemHealth_propulsion_allowed
{
public:
  explicit Init_SystemHealth_propulsion_allowed(::tyrant_interfaces::msg::SystemHealth & msg)
  : msg_(msg)
  {}
  Init_SystemHealth_current_mode propulsion_allowed(::tyrant_interfaces::msg::SystemHealth::_propulsion_allowed_type arg)
  {
    msg_.propulsion_allowed = std::move(arg);
    return Init_SystemHealth_current_mode(msg_);
  }

private:
  ::tyrant_interfaces::msg::SystemHealth msg_;
};

class Init_SystemHealth_autonomy_ready
{
public:
  explicit Init_SystemHealth_autonomy_ready(::tyrant_interfaces::msg::SystemHealth & msg)
  : msg_(msg)
  {}
  Init_SystemHealth_propulsion_allowed autonomy_ready(::tyrant_interfaces::msg::SystemHealth::_autonomy_ready_type arg)
  {
    msg_.autonomy_ready = std::move(arg);
    return Init_SystemHealth_propulsion_allowed(msg_);
  }

private:
  ::tyrant_interfaces::msg::SystemHealth msg_;
};

class Init_SystemHealth_communication_healthy
{
public:
  Init_SystemHealth_communication_healthy()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SystemHealth_autonomy_ready communication_healthy(::tyrant_interfaces::msg::SystemHealth::_communication_healthy_type arg)
  {
    msg_.communication_healthy = std::move(arg);
    return Init_SystemHealth_autonomy_ready(msg_);
  }

private:
  ::tyrant_interfaces::msg::SystemHealth msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tyrant_interfaces::msg::SystemHealth>()
{
  return tyrant_interfaces::msg::builder::Init_SystemHealth_communication_healthy();
}

}  // namespace tyrant_interfaces

#endif  // TYRANT_INTERFACES__MSG__DETAIL__SYSTEM_HEALTH__BUILDER_HPP_
