// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tyrant_interfaces:msg/SystemHealth.idl
// generated code does not contain a copyright notice

#ifndef TYRANT_INTERFACES__MSG__DETAIL__SYSTEM_HEALTH__STRUCT_H_
#define TYRANT_INTERFACES__MSG__DETAIL__SYSTEM_HEALTH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/SystemHealth in the package tyrant_interfaces.
typedef struct tyrant_interfaces__msg__SystemHealth
{
  bool communication_healthy;
  bool autonomy_ready;
  bool propulsion_allowed;
  uint8_t current_mode;
  uint32_t host_heartbeat_age_ms;
} tyrant_interfaces__msg__SystemHealth;

// Struct for a sequence of tyrant_interfaces__msg__SystemHealth.
typedef struct tyrant_interfaces__msg__SystemHealth__Sequence
{
  tyrant_interfaces__msg__SystemHealth * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tyrant_interfaces__msg__SystemHealth__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TYRANT_INTERFACES__MSG__DETAIL__SYSTEM_HEALTH__STRUCT_H_
