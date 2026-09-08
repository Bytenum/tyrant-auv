// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tyrant_interfaces:msg/VehicleReference.idl
// generated code does not contain a copyright notice
#include "tyrant_interfaces/msg/detail/vehicle_reference__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `linear_velocity`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
tyrant_interfaces__msg__VehicleReference__init(tyrant_interfaces__msg__VehicleReference * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    tyrant_interfaces__msg__VehicleReference__fini(msg);
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__init(&msg->position)) {
    tyrant_interfaces__msg__VehicleReference__fini(msg);
    return false;
  }
  // linear_velocity
  if (!geometry_msgs__msg__Vector3__init(&msg->linear_velocity)) {
    tyrant_interfaces__msg__VehicleReference__fini(msg);
    return false;
  }
  // roll
  // pitch
  // yaw
  return true;
}

void
tyrant_interfaces__msg__VehicleReference__fini(tyrant_interfaces__msg__VehicleReference * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // position
  geometry_msgs__msg__Point__fini(&msg->position);
  // linear_velocity
  geometry_msgs__msg__Vector3__fini(&msg->linear_velocity);
  // roll
  // pitch
  // yaw
}

bool
tyrant_interfaces__msg__VehicleReference__are_equal(const tyrant_interfaces__msg__VehicleReference * lhs, const tyrant_interfaces__msg__VehicleReference * rhs)
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
  // position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  // linear_velocity
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->linear_velocity), &(rhs->linear_velocity)))
  {
    return false;
  }
  // roll
  if (lhs->roll != rhs->roll) {
    return false;
  }
  // pitch
  if (lhs->pitch != rhs->pitch) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  return true;
}

bool
tyrant_interfaces__msg__VehicleReference__copy(
  const tyrant_interfaces__msg__VehicleReference * input,
  tyrant_interfaces__msg__VehicleReference * output)
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
  // position
  if (!geometry_msgs__msg__Point__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  // linear_velocity
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->linear_velocity), &(output->linear_velocity)))
  {
    return false;
  }
  // roll
  output->roll = input->roll;
  // pitch
  output->pitch = input->pitch;
  // yaw
  output->yaw = input->yaw;
  return true;
}

tyrant_interfaces__msg__VehicleReference *
tyrant_interfaces__msg__VehicleReference__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tyrant_interfaces__msg__VehicleReference * msg = (tyrant_interfaces__msg__VehicleReference *)allocator.allocate(sizeof(tyrant_interfaces__msg__VehicleReference), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tyrant_interfaces__msg__VehicleReference));
  bool success = tyrant_interfaces__msg__VehicleReference__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tyrant_interfaces__msg__VehicleReference__destroy(tyrant_interfaces__msg__VehicleReference * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tyrant_interfaces__msg__VehicleReference__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tyrant_interfaces__msg__VehicleReference__Sequence__init(tyrant_interfaces__msg__VehicleReference__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tyrant_interfaces__msg__VehicleReference * data = NULL;

  if (size) {
    data = (tyrant_interfaces__msg__VehicleReference *)allocator.zero_allocate(size, sizeof(tyrant_interfaces__msg__VehicleReference), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tyrant_interfaces__msg__VehicleReference__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tyrant_interfaces__msg__VehicleReference__fini(&data[i - 1]);
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
tyrant_interfaces__msg__VehicleReference__Sequence__fini(tyrant_interfaces__msg__VehicleReference__Sequence * array)
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
      tyrant_interfaces__msg__VehicleReference__fini(&array->data[i]);
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

tyrant_interfaces__msg__VehicleReference__Sequence *
tyrant_interfaces__msg__VehicleReference__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tyrant_interfaces__msg__VehicleReference__Sequence * array = (tyrant_interfaces__msg__VehicleReference__Sequence *)allocator.allocate(sizeof(tyrant_interfaces__msg__VehicleReference__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tyrant_interfaces__msg__VehicleReference__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tyrant_interfaces__msg__VehicleReference__Sequence__destroy(tyrant_interfaces__msg__VehicleReference__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tyrant_interfaces__msg__VehicleReference__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tyrant_interfaces__msg__VehicleReference__Sequence__are_equal(const tyrant_interfaces__msg__VehicleReference__Sequence * lhs, const tyrant_interfaces__msg__VehicleReference__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tyrant_interfaces__msg__VehicleReference__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tyrant_interfaces__msg__VehicleReference__Sequence__copy(
  const tyrant_interfaces__msg__VehicleReference__Sequence * input,
  tyrant_interfaces__msg__VehicleReference__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tyrant_interfaces__msg__VehicleReference);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tyrant_interfaces__msg__VehicleReference * data =
      (tyrant_interfaces__msg__VehicleReference *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tyrant_interfaces__msg__VehicleReference__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tyrant_interfaces__msg__VehicleReference__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tyrant_interfaces__msg__VehicleReference__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
