// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tyrant_interfaces:msg/VehicleState.idl
// generated code does not contain a copyright notice

#ifndef TYRANT_INTERFACES__MSG__DETAIL__VEHICLE_STATE__BUILDER_HPP_
#define TYRANT_INTERFACES__MSG__DETAIL__VEHICLE_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tyrant_interfaces/msg/detail/vehicle_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tyrant_interfaces
{

namespace msg
{

namespace builder
{

class Init_VehicleState_estimator_status
{
public:
  explicit Init_VehicleState_estimator_status(::tyrant_interfaces::msg::VehicleState & msg)
  : msg_(msg)
  {}
  ::tyrant_interfaces::msg::VehicleState estimator_status(::tyrant_interfaces::msg::VehicleState::_estimator_status_type arg)
  {
    msg_.estimator_status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tyrant_interfaces::msg::VehicleState msg_;
};

class Init_VehicleState_yaw
{
public:
  explicit Init_VehicleState_yaw(::tyrant_interfaces::msg::VehicleState & msg)
  : msg_(msg)
  {}
  Init_VehicleState_estimator_status yaw(::tyrant_interfaces::msg::VehicleState::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_VehicleState_estimator_status(msg_);
  }

private:
  ::tyrant_interfaces::msg::VehicleState msg_;
};

class Init_VehicleState_pitch
{
public:
  explicit Init_VehicleState_pitch(::tyrant_interfaces::msg::VehicleState & msg)
  : msg_(msg)
  {}
  Init_VehicleState_yaw pitch(::tyrant_interfaces::msg::VehicleState::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_VehicleState_yaw(msg_);
  }

private:
  ::tyrant_interfaces::msg::VehicleState msg_;
};

class Init_VehicleState_roll
{
public:
  explicit Init_VehicleState_roll(::tyrant_interfaces::msg::VehicleState & msg)
  : msg_(msg)
  {}
  Init_VehicleState_pitch roll(::tyrant_interfaces::msg::VehicleState::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_VehicleState_pitch(msg_);
  }

private:
  ::tyrant_interfaces::msg::VehicleState msg_;
};

class Init_VehicleState_angular_velocity
{
public:
  explicit Init_VehicleState_angular_velocity(::tyrant_interfaces::msg::VehicleState & msg)
  : msg_(msg)
  {}
  Init_VehicleState_roll angular_velocity(::tyrant_interfaces::msg::VehicleState::_angular_velocity_type arg)
  {
    msg_.angular_velocity = std::move(arg);
    return Init_VehicleState_roll(msg_);
  }

private:
  ::tyrant_interfaces::msg::VehicleState msg_;
};

class Init_VehicleState_linear_velocity
{
public:
  explicit Init_VehicleState_linear_velocity(::tyrant_interfaces::msg::VehicleState & msg)
  : msg_(msg)
  {}
  Init_VehicleState_angular_velocity linear_velocity(::tyrant_interfaces::msg::VehicleState::_linear_velocity_type arg)
  {
    msg_.linear_velocity = std::move(arg);
    return Init_VehicleState_angular_velocity(msg_);
  }

private:
  ::tyrant_interfaces::msg::VehicleState msg_;
};

class Init_VehicleState_position
{
public:
  explicit Init_VehicleState_position(::tyrant_interfaces::msg::VehicleState & msg)
  : msg_(msg)
  {}
  Init_VehicleState_linear_velocity position(::tyrant_interfaces::msg::VehicleState::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_VehicleState_linear_velocity(msg_);
  }

private:
  ::tyrant_interfaces::msg::VehicleState msg_;
};

class Init_VehicleState_header
{
public:
  Init_VehicleState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VehicleState_position header(::tyrant_interfaces::msg::VehicleState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_VehicleState_position(msg_);
  }

private:
  ::tyrant_interfaces::msg::VehicleState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tyrant_interfaces::msg::VehicleState>()
{
  return tyrant_interfaces::msg::builder::Init_VehicleState_header();
}

}  // namespace tyrant_interfaces

#endif  // TYRANT_INTERFACES__MSG__DETAIL__VEHICLE_STATE__BUILDER_HPP_
