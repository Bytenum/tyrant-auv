// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tyrant_interfaces:msg/ModeRequest.idl
// generated code does not contain a copyright notice

#ifndef TYRANT_INTERFACES__MSG__DETAIL__MODE_REQUEST__BUILDER_HPP_
#define TYRANT_INTERFACES__MSG__DETAIL__MODE_REQUEST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tyrant_interfaces/msg/detail/mode_request__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tyrant_interfaces
{

namespace msg
{

namespace builder
{

class Init_ModeRequest_requested_mode
{
public:
  explicit Init_ModeRequest_requested_mode(::tyrant_interfaces::msg::ModeRequest & msg)
  : msg_(msg)
  {}
  ::tyrant_interfaces::msg::ModeRequest requested_mode(::tyrant_interfaces::msg::ModeRequest::_requested_mode_type arg)
  {
    msg_.requested_mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tyrant_interfaces::msg::ModeRequest msg_;
};

class Init_ModeRequest_request_id
{
public:
  Init_ModeRequest_request_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ModeRequest_requested_mode request_id(::tyrant_interfaces::msg::ModeRequest::_request_id_type arg)
  {
    msg_.request_id = std::move(arg);
    return Init_ModeRequest_requested_mode(msg_);
  }

private:
  ::tyrant_interfaces::msg::ModeRequest msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tyrant_interfaces::msg::ModeRequest>()
{
  return tyrant_interfaces::msg::builder::Init_ModeRequest_request_id();
}

}  // namespace tyrant_interfaces

#endif  // TYRANT_INTERFACES__MSG__DETAIL__MODE_REQUEST__BUILDER_HPP_
