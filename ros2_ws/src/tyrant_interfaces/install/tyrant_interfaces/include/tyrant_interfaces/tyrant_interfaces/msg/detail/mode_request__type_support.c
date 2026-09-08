// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tyrant_interfaces:msg/ModeRequest.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tyrant_interfaces/msg/detail/mode_request__rosidl_typesupport_introspection_c.h"
#include "tyrant_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tyrant_interfaces/msg/detail/mode_request__functions.h"
#include "tyrant_interfaces/msg/detail/mode_request__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void tyrant_interfaces__msg__ModeRequest__rosidl_typesupport_introspection_c__ModeRequest_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tyrant_interfaces__msg__ModeRequest__init(message_memory);
}

void tyrant_interfaces__msg__ModeRequest__rosidl_typesupport_introspection_c__ModeRequest_fini_function(void * message_memory)
{
  tyrant_interfaces__msg__ModeRequest__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember tyrant_interfaces__msg__ModeRequest__rosidl_typesupport_introspection_c__ModeRequest_message_member_array[2] = {
  {
    "request_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tyrant_interfaces__msg__ModeRequest, request_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "requested_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tyrant_interfaces__msg__ModeRequest, requested_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tyrant_interfaces__msg__ModeRequest__rosidl_typesupport_introspection_c__ModeRequest_message_members = {
  "tyrant_interfaces__msg",  // message namespace
  "ModeRequest",  // message name
  2,  // number of fields
  sizeof(tyrant_interfaces__msg__ModeRequest),
  tyrant_interfaces__msg__ModeRequest__rosidl_typesupport_introspection_c__ModeRequest_message_member_array,  // message members
  tyrant_interfaces__msg__ModeRequest__rosidl_typesupport_introspection_c__ModeRequest_init_function,  // function to initialize message memory (memory has to be allocated)
  tyrant_interfaces__msg__ModeRequest__rosidl_typesupport_introspection_c__ModeRequest_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tyrant_interfaces__msg__ModeRequest__rosidl_typesupport_introspection_c__ModeRequest_message_type_support_handle = {
  0,
  &tyrant_interfaces__msg__ModeRequest__rosidl_typesupport_introspection_c__ModeRequest_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tyrant_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tyrant_interfaces, msg, ModeRequest)() {
  if (!tyrant_interfaces__msg__ModeRequest__rosidl_typesupport_introspection_c__ModeRequest_message_type_support_handle.typesupport_identifier) {
    tyrant_interfaces__msg__ModeRequest__rosidl_typesupport_introspection_c__ModeRequest_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tyrant_interfaces__msg__ModeRequest__rosidl_typesupport_introspection_c__ModeRequest_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
