// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tyrant_interfaces:msg/ModeRequest.idl
// generated code does not contain a copyright notice

#ifndef TYRANT_INTERFACES__MSG__DETAIL__MODE_REQUEST__STRUCT_H_
#define TYRANT_INTERFACES__MSG__DETAIL__MODE_REQUEST__STRUCT_H_

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
  tyrant_interfaces__msg__ModeRequest__BOOT = 0
};

/// Constant 'IDLE'.
enum
{
  tyrant_interfaces__msg__ModeRequest__IDLE = 1
};

/// Constant 'MANUAL'.
enum
{
  tyrant_interfaces__msg__ModeRequest__MANUAL = 2
};

/// Constant 'AUTO'.
enum
{
  tyrant_interfaces__msg__ModeRequest__AUTO = 3
};

/// Constant 'SAFE'.
enum
{
  tyrant_interfaces__msg__ModeRequest__SAFE = 4
};

/// Constant 'FAULT'.
enum
{
  tyrant_interfaces__msg__ModeRequest__FAULT = 5
};

/// Constant 'EMERGENCY'.
enum
{
  tyrant_interfaces__msg__ModeRequest__EMERGENCY = 6
};

/// Struct defined in msg/ModeRequest in the package tyrant_interfaces.
typedef struct tyrant_interfaces__msg__ModeRequest
{
  uint32_t request_id;
  uint8_t requested_mode;
} tyrant_interfaces__msg__ModeRequest;

// Struct for a sequence of tyrant_interfaces__msg__ModeRequest.
typedef struct tyrant_interfaces__msg__ModeRequest__Sequence
{
  tyrant_interfaces__msg__ModeRequest * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tyrant_interfaces__msg__ModeRequest__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TYRANT_INTERFACES__MSG__DETAIL__MODE_REQUEST__STRUCT_H_
