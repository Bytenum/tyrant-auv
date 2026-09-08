// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tyrant_interfaces:msg/VehicleReference.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tyrant_interfaces/msg/detail/vehicle_reference__rosidl_typesupport_introspection_c.h"
#include "tyrant_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tyrant_interfaces/msg/detail/vehicle_reference__functions.h"
#include "tyrant_interfaces/msg/detail/vehicle_reference__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `position`
#include "geometry_msgs/msg/point.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"
// Member `linear_velocity`
#include "geometry_msgs/msg/vector3.h"
// Member `linear_velocity`
#include "geometry_msgs/msg/detail/vector3__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tyrant_interfaces__msg__VehicleReference__rosidl_typesupport_introspection_c__VehicleReference_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tyrant_interfaces__msg__VehicleReference__init(message_memory);
}

void tyrant_interfaces__msg__VehicleReference__rosidl_typesupport_introspection_c__VehicleReference_fini_function(void * message_memory)
{
  tyrant_interfaces__msg__VehicleReference__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember tyrant_interfaces__msg__VehicleReference__rosidl_typesupport_introspection_c__VehicleReference_message_member_array[6] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tyrant_interfaces__msg__VehicleReference, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tyrant_interfaces__msg__VehicleReference, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "linear_velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tyrant_interfaces__msg__VehicleReference, linear_velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "roll",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tyrant_interfaces__msg__VehicleReference, roll),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pitch",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tyrant_interfaces__msg__VehicleReference, pitch),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "yaw",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tyrant_interfaces__msg__VehicleReference, yaw),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tyrant_interfaces__msg__VehicleReference__rosidl_typesupport_introspection_c__VehicleReference_message_members = {
  "tyrant_interfaces__msg",  // message namespace
  "VehicleReference",  // message name
  6,  // number of fields
  sizeof(tyrant_interfaces__msg__VehicleReference),
  tyrant_interfaces__msg__VehicleReference__rosidl_typesupport_introspection_c__VehicleReference_message_member_array,  // message members
  tyrant_interfaces__msg__VehicleReference__rosidl_typesupport_introspection_c__VehicleReference_init_function,  // function to initialize message memory (memory has to be allocated)
  tyrant_interfaces__msg__VehicleReference__rosidl_typesupport_introspection_c__VehicleReference_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tyrant_interfaces__msg__VehicleReference__rosidl_typesupport_introspection_c__VehicleReference_message_type_support_handle = {
  0,
  &tyrant_interfaces__msg__VehicleReference__rosidl_typesupport_introspection_c__VehicleReference_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tyrant_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tyrant_interfaces, msg, VehicleReference)() {
  tyrant_interfaces__msg__VehicleReference__rosidl_typesupport_introspection_c__VehicleReference_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  tyrant_interfaces__msg__VehicleReference__rosidl_typesupport_introspection_c__VehicleReference_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  tyrant_interfaces__msg__VehicleReference__rosidl_typesupport_introspection_c__VehicleReference_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  if (!tyrant_interfaces__msg__VehicleReference__rosidl_typesupport_introspection_c__VehicleReference_message_type_support_handle.typesupport_identifier) {
    tyrant_interfaces__msg__VehicleReference__rosidl_typesupport_introspection_c__VehicleReference_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tyrant_interfaces__msg__VehicleReference__rosidl_typesupport_introspection_c__VehicleReference_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
