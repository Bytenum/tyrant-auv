// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tyrant_interfaces:msg/VehicleReference.idl
// generated code does not contain a copyright notice

#ifndef TYRANT_INTERFACES__MSG__DETAIL__VEHICLE_REFERENCE__BUILDER_HPP_
#define TYRANT_INTERFACES__MSG__DETAIL__VEHICLE_REFERENCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tyrant_interfaces/msg/detail/vehicle_reference__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tyrant_interfaces
{

namespace msg
{

namespace builder
{

class Init_VehicleReference_yaw
{
public:
  explicit Init_VehicleReference_yaw(::tyrant_interfaces::msg::VehicleReference & msg)
  : msg_(msg)
  {}
  ::tyrant_interfaces::msg::VehicleReference yaw(::tyrant_interfaces::msg::VehicleReference::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tyrant_interfaces::msg::VehicleReference msg_;
};

class Init_VehicleReference_pitch
{
public:
  explicit Init_VehicleReference_pitch(::tyrant_interfaces::msg::VehicleReference & msg)
  : msg_(msg)
  {}
  Init_VehicleReference_yaw pitch(::tyrant_interfaces::msg::VehicleReference::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_VehicleReference_yaw(msg_);
  }

private:
  ::tyrant_interfaces::msg::VehicleReference msg_;
};

class Init_VehicleReference_roll
{
public:
  explicit Init_VehicleReference_roll(::tyrant_interfaces::msg::VehicleReference & msg)
  : msg_(msg)
  {}
  Init_VehicleReference_pitch roll(::tyrant_interfaces::msg::VehicleReference::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_VehicleReference_pitch(msg_);
  }

private:
  ::tyrant_interfaces::msg::VehicleReference msg_;
};

class Init_VehicleReference_linear_velocity
{
public:
  explicit Init_VehicleReference_linear_velocity(::tyrant_interfaces::msg::VehicleReference & msg)
  : msg_(msg)
  {}
  Init_VehicleReference_roll linear_velocity(::tyrant_interfaces::msg::VehicleReference::_linear_velocity_type arg)
  {
    msg_.linear_velocity = std::move(arg);
    return Init_VehicleReference_roll(msg_);
  }

private:
  ::tyrant_interfaces::msg::VehicleReference msg_;
};

class Init_VehicleReference_position
{
public:
  explicit Init_VehicleReference_position(::tyrant_interfaces::msg::VehicleReference & msg)
  : msg_(msg)
  {}
  Init_VehicleReference_linear_velocity position(::tyrant_interfaces::msg::VehicleReference::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_VehicleReference_linear_velocity(msg_);
  }

private:
  ::tyrant_interfaces::msg::VehicleReference msg_;
};

class Init_VehicleReference_header
{
public:
  Init_VehicleReference_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VehicleReference_position header(::tyrant_interfaces::msg::VehicleReference::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_VehicleReference_position(msg_);
  }

private:
  ::tyrant_interfaces::msg::VehicleReference msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tyrant_interfaces::msg::VehicleReference>()
{
  return tyrant_interfaces::msg::builder::Init_VehicleReference_header();
}

}  // namespace tyrant_interfaces

#endif  // TYRANT_INTERFACES__MSG__DETAIL__VEHICLE_REFERENCE__BUILDER_HPP_
