// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tyrant_interfaces:msg/VehicleReference.idl
// generated code does not contain a copyright notice

#ifndef TYRANT_INTERFACES__MSG__DETAIL__VEHICLE_REFERENCE__STRUCT_H_
#define TYRANT_INTERFACES__MSG__DETAIL__VEHICLE_REFERENCE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'linear_velocity'
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in msg/VehicleReference in the package tyrant_interfaces.
typedef struct tyrant_interfaces__msg__VehicleReference
{
  std_msgs__msg__Header header;
  geometry_msgs__msg__Point position;
  geometry_msgs__msg__Vector3 linear_velocity;
  float roll;
  float pitch;
  float yaw;
} tyrant_interfaces__msg__VehicleReference;

// Struct for a sequence of tyrant_interfaces__msg__VehicleReference.
typedef struct tyrant_interfaces__msg__VehicleReference__Sequence
{
  tyrant_interfaces__msg__VehicleReference * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tyrant_interfaces__msg__VehicleReference__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TYRANT_INTERFACES__MSG__DETAIL__VEHICLE_REFERENCE__STRUCT_H_
