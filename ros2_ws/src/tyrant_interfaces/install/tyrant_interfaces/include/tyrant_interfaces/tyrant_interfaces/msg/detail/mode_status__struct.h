// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tyrant_interfaces:msg/ModeStatus.idl
// generated code does not contain a copyright notice

#ifndef TYRANT_INTERFACES__MSG__DETAIL__MODE_STATUS__STRUCT_H_
#define TYRANT_INTERFACES__MSG__DETAIL__MODE_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'BOOT'.
enum
{
  tyrant_interfaces__msg__ModeStatus__BOOT = 0
};

/// Constant 'IDLE'.
enum
{
  tyrant_interfaces__msg__ModeStatus__IDLE = 1
};

/// Constant 'MANUAL'.
enum
{
  tyrant_interfaces__msg__ModeStatus__MANUAL = 2
};

/// Constant 'AUTO'.
enum
{
  tyrant_interfaces__msg__ModeStatus__AUTO = 3
};

/// Constant 'SAFE'.
enum
{
  tyrant_interfaces__msg__ModeStatus__SAFE = 4
};

/// Constant 'FAULT'.
enum
{
  tyrant_interfaces__msg__ModeStatus__FAULT = 5
};

/// Constant 'EMERGENCY'.
enum
{
  tyrant_interfaces__msg__ModeStatus__EMERGENCY = 6
};

/// Constant 'REASON_NONE'.
enum
{
  tyrant_interfaces__msg__ModeStatus__REASON_NONE = 0
};

/// Constant 'REASON_REQUEST_ACCEPTED'.
enum
{
  tyrant_interfaces__msg__ModeStatus__REASON_REQUEST_ACCEPTED = 1
};

/// Constant 'REASON_INVALID_MODE'.
enum
{
  tyrant_interfaces__msg__ModeStatus__REASON_INVALID_MODE = 2
};

/// Constant 'REASON_TRANSITION_NOT_ALLOWED'.
enum
{
  tyrant_interfaces__msg__ModeStatus__REASON_TRANSITION_NOT_ALLOWED = 3
};

/// Constant 'REASON_SYSTEM_UNHEALTHY'.
enum
{
  tyrant_interfaces__msg__ModeStatus__REASON_SYSTEM_UNHEALTHY = 4
};

/// Constant 'REASON_AUTONOMY_NOT_READY'.
enum
{
  tyrant_interfaces__msg__ModeStatus__REASON_AUTONOMY_NOT_READY = 5
};

/// Constant 'REASON_COMMUNICATION_TIMEOUT'.
enum
{
  tyrant_interfaces__msg__ModeStatus__REASON_COMMUNICATION_TIMEOUT = 6
};

/// Constant 'REASON_FAULT_LATCHED'.
enum
{
  tyrant_interfaces__msg__ModeStatus__REASON_FAULT_LATCHED = 7
};

/// Constant 'REASON_EMERGENCY_LATCHED'.
enum
{
  tyrant_interfaces__msg__ModeStatus__REASON_EMERGENCY_LATCHED = 8
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/ModeStatus in the package tyrant_interfaces.
typedef struct tyrant_interfaces__msg__ModeStatus
{
  std_msgs__msg__Header header;
  uint32_t request_id;
  uint8_t current_mode;
  uint8_t requested_mode;
  bool request_accepted;
  uint8_t reason;
  bool communication_healthy;
  bool propulsion_allowed;
} tyrant_interfaces__msg__ModeStatus;

// Struct for a sequence of tyrant_interfaces__msg__ModeStatus.
typedef struct tyrant_interfaces__msg__ModeStatus__Sequence
{
  tyrant_interfaces__msg__ModeStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tyrant_interfaces__msg__ModeStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TYRANT_INTERFACES__MSG__DETAIL__MODE_STATUS__STRUCT_H_
