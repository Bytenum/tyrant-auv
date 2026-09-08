// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tyrant_interfaces:msg/ModeRequest.idl
// generated code does not contain a copyright notice
#include "tyrant_interfaces/msg/detail/mode_request__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
tyrant_interfaces__msg__ModeRequest__init(tyrant_interfaces__msg__ModeRequest * msg)
{
  if (!msg) {
    return false;
  }
  // request_id
  // requested_mode
  return true;
}

void
tyrant_interfaces__msg__ModeRequest__fini(tyrant_interfaces__msg__ModeRequest * msg)
{
  if (!msg) {
    return;
  }
  // request_id
  // requested_mode
}

bool
tyrant_interfaces__msg__ModeRequest__are_equal(const tyrant_interfaces__msg__ModeRequest * lhs, const tyrant_interfaces__msg__ModeRequest * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // request_id
  if (lhs->request_id != rhs->request_id) {
    return false;
  }
  // requested_mode
  if (lhs->requested_mode != rhs->requested_mode) {
    return false;
  }
  return true;
}

bool
tyrant_interfaces__msg__ModeRequest__copy(
  const tyrant_interfaces__msg__ModeRequest * input,
  tyrant_interfaces__msg__ModeRequest * output)
{
  if (!input || !output) {
    return false;
  }
  // request_id
  output->request_id = input->request_id;
  // requested_mode
  output->requested_mode = input->requested_mode;
  return true;
}

tyrant_interfaces__msg__ModeRequest *
tyrant_interfaces__msg__ModeRequest__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tyrant_interfaces__msg__ModeRequest * msg = (tyrant_interfaces__msg__ModeRequest *)allocator.allocate(sizeof(tyrant_interfaces__msg__ModeRequest), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tyrant_interfaces__msg__ModeRequest));
  bool success = tyrant_interfaces__msg__ModeRequest__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tyrant_interfaces__msg__ModeRequest__destroy(tyrant_interfaces__msg__ModeRequest * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tyrant_interfaces__msg__ModeRequest__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tyrant_interfaces__msg__ModeRequest__Sequence__init(tyrant_interfaces__msg__ModeRequest__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tyrant_interfaces__msg__ModeRequest * data = NULL;

  if (size) {
    data = (tyrant_interfaces__msg__ModeRequest *)allocator.zero_allocate(size, sizeof(tyrant_interfaces__msg__ModeRequest), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tyrant_interfaces__msg__ModeRequest__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tyrant_interfaces__msg__ModeRequest__fini(&data[i - 1]);
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
tyrant_interfaces__msg__ModeRequest__Sequence__fini(tyrant_interfaces__msg__ModeRequest__Sequence * array)
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
      tyrant_interfaces__msg__ModeRequest__fini(&array->data[i]);
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

tyrant_interfaces__msg__ModeRequest__Sequence *
tyrant_interfaces__msg__ModeRequest__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tyrant_interfaces__msg__ModeRequest__Sequence * array = (tyrant_interfaces__msg__ModeRequest__Sequence *)allocator.allocate(sizeof(tyrant_interfaces__msg__ModeRequest__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tyrant_interfaces__msg__ModeRequest__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tyrant_interfaces__msg__ModeRequest__Sequence__destroy(tyrant_interfaces__msg__ModeRequest__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tyrant_interfaces__msg__ModeRequest__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tyrant_interfaces__msg__ModeRequest__Sequence__are_equal(const tyrant_interfaces__msg__ModeRequest__Sequence * lhs, const tyrant_interfaces__msg__ModeRequest__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tyrant_interfaces__msg__ModeRequest__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tyrant_interfaces__msg__ModeRequest__Sequence__copy(
  const tyrant_interfaces__msg__ModeRequest__Sequence * input,
  tyrant_interfaces__msg__ModeRequest__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tyrant_interfaces__msg__ModeRequest);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tyrant_interfaces__msg__ModeRequest * data =
      (tyrant_interfaces__msg__ModeRequest *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tyrant_interfaces__msg__ModeRequest__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tyrant_interfaces__msg__ModeRequest__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tyrant_interfaces__msg__ModeRequest__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
