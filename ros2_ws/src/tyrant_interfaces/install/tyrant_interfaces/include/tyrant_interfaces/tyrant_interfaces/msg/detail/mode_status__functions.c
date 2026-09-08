// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tyrant_interfaces:msg/ModeStatus.idl
// generated code does not contain a copyright notice
#include "tyrant_interfaces/msg/detail/mode_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
tyrant_interfaces__msg__ModeStatus__init(tyrant_interfaces__msg__ModeStatus * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    tyrant_interfaces__msg__ModeStatus__fini(msg);
    return false;
  }
  // request_id
  // current_mode
  // requested_mode
  // request_accepted
  // reason
  // communication_healthy
  // propulsion_allowed
  return true;
}

void
tyrant_interfaces__msg__ModeStatus__fini(tyrant_interfaces__msg__ModeStatus * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // request_id
  // current_mode
  // requested_mode
  // request_accepted
  // reason
  // communication_healthy
  // propulsion_allowed
}

bool
tyrant_interfaces__msg__ModeStatus__are_equal(const tyrant_interfaces__msg__ModeStatus * lhs, const tyrant_interfaces__msg__ModeStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // request_id
  if (lhs->request_id != rhs->request_id) {
    return false;
  }
  // current_mode
  if (lhs->current_mode != rhs->current_mode) {
    return false;
  }
  // requested_mode
  if (lhs->requested_mode != rhs->requested_mode) {
    return false;
  }
  // request_accepted
  if (lhs->request_accepted != rhs->request_accepted) {
    return false;
  }
  // reason
  if (lhs->reason != rhs->reason) {
    return false;
  }
  // communication_healthy
  if (lhs->communication_healthy != rhs->communication_healthy) {
    return false;
  }
  // propulsion_allowed
  if (lhs->propulsion_allowed != rhs->propulsion_allowed) {
    return false;
  }
  return true;
}

bool
tyrant_interfaces__msg__ModeStatus__copy(
  const tyrant_interfaces__msg__ModeStatus * input,
  tyrant_interfaces__msg__ModeStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // request_id
  output->request_id = input->request_id;
  // current_mode
  output->current_mode = input->current_mode;
  // requested_mode
  output->requested_mode = input->requested_mode;
  // request_accepted
  output->request_accepted = input->request_accepted;
  // reason
  output->reason = input->reason;
  // communication_healthy
  output->communication_healthy = input->communication_healthy;
  // propulsion_allowed
  output->propulsion_allowed = input->propulsion_allowed;
  return true;
}

tyrant_interfaces__msg__ModeStatus *
tyrant_interfaces__msg__ModeStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tyrant_interfaces__msg__ModeStatus * msg = (tyrant_interfaces__msg__ModeStatus *)allocator.allocate(sizeof(tyrant_interfaces__msg__ModeStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tyrant_interfaces__msg__ModeStatus));
  bool success = tyrant_interfaces__msg__ModeStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tyrant_interfaces__msg__ModeStatus__destroy(tyrant_interfaces__msg__ModeStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tyrant_interfaces__msg__ModeStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tyrant_interfaces__msg__ModeStatus__Sequence__init(tyrant_interfaces__msg__ModeStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tyrant_interfaces__msg__ModeStatus * data = NULL;

  if (size) {
    data = (tyrant_interfaces__msg__ModeStatus *)allocator.zero_allocate(size, sizeof(tyrant_interfaces__msg__ModeStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tyrant_interfaces__msg__ModeStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tyrant_interfaces__msg__ModeStatus__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
tyrant_interfaces__msg__ModeStatus__Sequence__fini(tyrant_interfaces__msg__ModeStatus__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tyrant_interfaces__msg__ModeStatus__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

tyrant_interfaces__msg__ModeStatus__Sequence *
tyrant_interfaces__msg__ModeStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tyrant_interfaces__msg__ModeStatus__Sequence * array = (tyrant_interfaces__msg__ModeStatus__Sequence *)allocator.allocate(sizeof(tyrant_interfaces__msg__ModeStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tyrant_interfaces__msg__ModeStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tyrant_interfaces__msg__ModeStatus__Sequence__destroy(tyrant_interfaces__msg__ModeStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tyrant_interfaces__msg__ModeStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tyrant_interfaces__msg__ModeStatus__Sequence__are_equal(const tyrant_interfaces__msg__ModeStatus__Sequence * lhs, const tyrant_interfaces__msg__ModeStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tyrant_interfaces__msg__ModeStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tyrant_interfaces__msg__ModeStatus__Sequence__copy(
  const tyrant_interfaces__msg__ModeStatus__Sequence * input,
  tyrant_interfaces__msg__ModeStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tyrant_interfaces__msg__ModeStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tyrant_interfaces__msg__ModeStatus * data =
      (tyrant_interfaces__msg__ModeStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tyrant_interfaces__msg__ModeStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tyrant_interfaces__msg__ModeStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tyrant_interfaces__msg__ModeStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
