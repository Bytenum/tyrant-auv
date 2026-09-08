// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from tyrant_interfaces:msg/ModeStatus.idl
// generated code does not contain a copyright notice

#ifndef TYRANT_INTERFACES__MSG__DETAIL__MODE_STATUS__FUNCTIONS_H_
#define TYRANT_INTERFACES__MSG__DETAIL__MODE_STATUS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "tyrant_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "tyrant_interfaces/msg/detail/mode_status__struct.h"

/// Initialize msg/ModeStatus message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * tyrant_interfaces__msg__ModeStatus
 * )) before or use
 * tyrant_interfaces__msg__ModeStatus__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_tyrant_interfaces
bool
tyrant_interfaces__msg__ModeStatus__init(tyrant_interfaces__msg__ModeStatus * msg);

/// Finalize msg/ModeStatus message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tyrant_interfaces
void
tyrant_interfaces__msg__ModeStatus__fini(tyrant_interfaces__msg__ModeStatus * msg);

/// Create msg/ModeStatus message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * tyrant_interfaces__msg__ModeStatus__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tyrant_interfaces
tyrant_interfaces__msg__ModeStatus *
tyrant_interfaces__msg__ModeStatus__create();

/// Destroy msg/ModeStatus message.
/**
 * It calls
 * tyrant_interfaces__msg__ModeStatus__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tyrant_interfaces
void
tyrant_interfaces__msg__ModeStatus__destroy(tyrant_interfaces__msg__ModeStatus * msg);

/// Check for msg/ModeStatus message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tyrant_interfaces
bool
tyrant_interfaces__msg__ModeStatus__are_equal(const tyrant_interfaces__msg__ModeStatus * lhs, const tyrant_interfaces__msg__ModeStatus * rhs);

/// Copy a msg/ModeStatus message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_tyrant_interfaces
bool
tyrant_interfaces__msg__ModeStatus__copy(
  const tyrant_interfaces__msg__ModeStatus * input,
  tyrant_interfaces__msg__ModeStatus * output);

/// Initialize array of msg/ModeStatus messages.
/**
 * It allocates the memory for the number of elements and calls
 * tyrant_interfaces__msg__ModeStatus__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_tyrant_interfaces
bool
tyrant_interfaces__msg__ModeStatus__Sequence__init(tyrant_interfaces__msg__ModeStatus__Sequence * array, size_t size);

/// Finalize array of msg/ModeStatus messages.
/**
 * It calls
 * tyrant_interfaces__msg__ModeStatus__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tyrant_interfaces
void
tyrant_interfaces__msg__ModeStatus__Sequence__fini(tyrant_interfaces__msg__ModeStatus__Sequence * array);

/// Create array of msg/ModeStatus messages.
/**
 * It allocates the memory for the array and calls
 * tyrant_interfaces__msg__ModeStatus__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tyrant_interfaces
tyrant_interfaces__msg__ModeStatus__Sequence *
tyrant_interfaces__msg__ModeStatus__Sequence__create(size_t size);

/// Destroy array of msg/ModeStatus messages.
/**
 * It calls
 * tyrant_interfaces__msg__ModeStatus__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tyrant_interfaces
void
tyrant_interfaces__msg__ModeStatus__Sequence__destroy(tyrant_interfaces__msg__ModeStatus__Sequence * array);

/// Check for msg/ModeStatus message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tyrant_interfaces
bool
tyrant_interfaces__msg__ModeStatus__Sequence__are_equal(const tyrant_interfaces__msg__ModeStatus__Sequence * lhs, const tyrant_interfaces__msg__ModeStatus__Sequence * rhs);

/// Copy an array of msg/ModeStatus messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_tyrant_interfaces
bool
tyrant_interfaces__msg__ModeStatus__Sequence__copy(
  const tyrant_interfaces__msg__ModeStatus__Sequence * input,
  tyrant_interfaces__msg__ModeStatus__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TYRANT_INTERFACES__MSG__DETAIL__MODE_STATUS__FUNCTIONS_H_
