// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tyrant_interfaces:msg/ModeStatus.idl
// generated code does not contain a copyright notice

#ifndef TYRANT_INTERFACES__MSG__DETAIL__MODE_STATUS__BUILDER_HPP_
#define TYRANT_INTERFACES__MSG__DETAIL__MODE_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tyrant_interfaces/msg/detail/mode_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tyrant_interfaces
{

namespace msg
{

namespace builder
{

class Init_ModeStatus_propulsion_allowed
{
public:
  explicit Init_ModeStatus_propulsion_allowed(::tyrant_interfaces::msg::ModeStatus & msg)
  : msg_(msg)
  {}
  ::tyrant_interfaces::msg::ModeStatus propulsion_allowed(::tyrant_interfaces::msg::ModeStatus::_propulsion_allowed_type arg)
  {
    msg_.propulsion_allowed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tyrant_interfaces::msg::ModeStatus msg_;
};

class Init_ModeStatus_communication_healthy
{
public:
  explicit Init_ModeStatus_communication_healthy(::tyrant_interfaces::msg::ModeStatus & msg)
  : msg_(msg)
  {}
  Init_ModeStatus_propulsion_allowed communication_healthy(::tyrant_interfaces::msg::ModeStatus::_communication_healthy_type arg)
  {
    msg_.communication_healthy = std::move(arg);
    return Init_ModeStatus_propulsion_allowed(msg_);
  }

private:
  ::tyrant_interfaces::msg::ModeStatus msg_;
};

class Init_ModeStatus_reason
{
public:
  explicit Init_ModeStatus_reason(::tyrant_interfaces::msg::ModeStatus & msg)
  : msg_(msg)
  {}
  Init_ModeStatus_communication_healthy reason(::tyrant_interfaces::msg::ModeStatus::_reason_type arg)
  {
    msg_.reason = std::move(arg);
    return Init_ModeStatus_communication_healthy(msg_);
  }

private:
  ::tyrant_interfaces::msg::ModeStatus msg_;
};

class Init_ModeStatus_request_accepted
{
public:
  explicit Init_ModeStatus_request_accepted(::tyrant_interfaces::msg::ModeStatus & msg)
  : msg_(msg)
  {}
  Init_ModeStatus_reason request_accepted(::tyrant_interfaces::msg::ModeStatus::_request_accepted_type arg)
  {
    msg_.request_accepted = std::move(arg);
    return Init_ModeStatus_reason(msg_);
  }

private:
  ::tyrant_interfaces::msg::ModeStatus msg_;
};

class Init_ModeStatus_requested_mode
{
public:
  explicit Init_ModeStatus_requested_mode(::tyrant_interfaces::msg::ModeStatus & msg)
  : msg_(msg)
  {}
  Init_ModeStatus_request_accepted requested_mode(::tyrant_interfaces::msg::ModeStatus::_requested_mode_type arg)
  {
    msg_.requested_mode = std::move(arg);
    return Init_ModeStatus_request_accepted(msg_);
  }

private:
  ::tyrant_interfaces::msg::ModeStatus msg_;
};

class Init_ModeStatus_current_mode
{
public:
  explicit Init_ModeStatus_current_mode(::tyrant_interfaces::msg::ModeStatus & msg)
  : msg_(msg)
  {}
  Init_ModeStatus_requested_mode current_mode(::tyrant_interfaces::msg::ModeStatus::_current_mode_type arg)
  {
    msg_.current_mode = std::move(arg);
    return Init_ModeStatus_requested_mode(msg_);
  }

private:
  ::tyrant_interfaces::msg::ModeStatus msg_;
};

class Init_ModeStatus_request_id
{
public:
  explicit Init_ModeStatus_request_id(::tyrant_interfaces::msg::ModeStatus & msg)
  : msg_(msg)
  {}
  Init_ModeStatus_current_mode request_id(::tyrant_interfaces::msg::ModeStatus::_request_id_type arg)
  {
    msg_.request_id = std::move(arg);
    return Init_ModeStatus_current_mode(msg_);
  }

private:
  ::tyrant_interfaces::msg::ModeStatus msg_;
};

class Init_ModeStatus_header
{
public:
  Init_ModeStatus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ModeStatus_request_id header(::tyrant_interfaces::msg::ModeStatus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ModeStatus_request_id(msg_);
  }

private:
  ::tyrant_interfaces::msg::ModeStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tyrant_interfaces::msg::ModeStatus>()
{
  return tyrant_interfaces::msg::builder::Init_ModeStatus_header();
}

}  // namespace tyrant_interfaces

#endif  // TYRANT_INTERFACES__MSG__DETAIL__MODE_STATUS__BUILDER_HPP_
