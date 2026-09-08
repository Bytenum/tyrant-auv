// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tyrant_interfaces:msg/VehicleState.idl
// generated code does not contain a copyright notice
#include "tyrant_interfaces/msg/detail/vehicle_state__functions.h"

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
// Member `angular_velocity`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
tyrant_interfaces__msg__VehicleState__init(tyrant_interfaces__msg__VehicleState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    tyrant_interfaces__msg__VehicleState__fini(msg);
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__init(&msg->position)) {
    tyrant_interfaces__msg__VehicleState__fini(msg);
    return false;
  }
  // linear_velocity
  if (!geometry_msgs__msg__Vector3__init(&msg->linear_velocity)) {
    tyrant_interfaces__msg__VehicleState__fini(msg);
    return false;
  }
  // angular_velocity
  if (!geometry_msgs__msg__Vector3__init(&msg->angular_velocity)) {
    tyrant_interfaces__msg__VehicleState__fini(msg);
    return false;
  }
  // roll
  // pitch
  // yaw
  // estimator_status
  return true;
}

void
tyrant_interfaces__msg__VehicleState__fini(tyrant_interfaces__msg__VehicleState * msg)
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
  // angular_velocity
  geometry_msgs__msg__Vector3__fini(&msg->angular_velocity);
  // roll
  // pitch
  // yaw
  // estimator_status
}

bool
tyrant_interfaces__msg__VehicleState__are_equal(const tyrant_interfaces__msg__VehicleState * lhs, const tyrant_interfaces__msg__VehicleState * rhs)
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
  // angular_velocity
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->angular_velocity), &(rhs->angular_velocity)))
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
  // estimator_status
  if (lhs->estimator_status != rhs->estimator_status) {
    return false;
  }
  return true;
}

bool
tyrant_interfaces__msg__VehicleState__copy(
  const tyrant_interfaces__msg__VehicleState * input,
  tyrant_interfaces__msg__VehicleState * output)
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
  // angular_velocity
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->angular_velocity), &(output->angular_velocity)))
  {
    return false;
  }
  // roll
  output->roll = input->roll;
  // pitch
  output->pitch = input->pitch;
  // yaw
  output->yaw = input->yaw;
  // estimator_status
  output->estimator_status = input->estimator_status;
  return true;
}

tyrant_interfaces__msg__VehicleState *
tyrant_interfaces__msg__VehicleState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tyrant_interfaces__msg__VehicleState * msg = (tyrant_interfaces__msg__VehicleState *)allocator.allocate(sizeof(tyrant_interfaces__msg__VehicleState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tyrant_interfaces__msg__VehicleState));
  bool success = tyrant_interfaces__msg__VehicleState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tyrant_interfaces__msg__VehicleState__destroy(tyrant_interfaces__msg__VehicleState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tyrant_interfaces__msg__VehicleState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tyrant_interfaces__msg__VehicleState__Sequence__init(tyrant_interfaces__msg__VehicleState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tyrant_interfaces__msg__VehicleState * data = NULL;

  if (size) {
    data = (tyrant_interfaces__msg__VehicleState *)allocator.zero_allocate(size, sizeof(tyrant_interfaces__msg__VehicleState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tyrant_interfaces__msg__VehicleState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tyrant_interfaces__msg__VehicleState__fini(&data[i - 1]);
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
tyrant_interfaces__msg__VehicleState__Sequence__fini(tyrant_interfaces__msg__VehicleState__Sequence * array)
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
      tyrant_interfaces__msg__VehicleState__fini(&array->data[i]);
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

tyrant_interfaces__msg__VehicleState__Sequence *
tyrant_interfaces__msg__VehicleState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tyrant_interfaces__msg__VehicleState__Sequence * array = (tyrant_interfaces__msg__VehicleState__Sequence *)allocator.allocate(sizeof(tyrant_interfaces__msg__VehicleState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tyrant_interfaces__msg__VehicleState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tyrant_interfaces__msg__VehicleState__Sequence__destroy(tyrant_interfaces__msg__VehicleState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tyrant_interfaces__msg__VehicleState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tyrant_interfaces__msg__VehicleState__Sequence__are_equal(const tyrant_interfaces__msg__VehicleState__Sequence * lhs, const tyrant_interfaces__msg__VehicleState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tyrant_interfaces__msg__VehicleState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tyrant_interfaces__msg__VehicleState__Sequence__copy(
  const tyrant_interfaces__msg__VehicleState__Sequence * input,
  tyrant_interfaces__msg__VehicleState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tyrant_interfaces__msg__VehicleState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tyrant_interfaces__msg__VehicleState * data =
      (tyrant_interfaces__msg__VehicleState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tyrant_interfaces__msg__VehicleState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tyrant_interfaces__msg__VehicleState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tyrant_interfaces__msg__VehicleState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
