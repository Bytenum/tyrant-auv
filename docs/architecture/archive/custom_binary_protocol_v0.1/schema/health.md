# Health and Fault Messages

# HEALTH_STATUS

Message ID:

`0x0901`

Purpose:

Provides a compact health summary for a Tyrant node.

## Payload

| Field         | Type   | Description                         |
| ------------- | ------ | ----------------------------------- |
| health_state  | uint8  | Overall health state                |
| fault_count   | uint8  | Number of currently active faults   |
| warning_flags | uint32 | Bitfield containing active warnings |

## Initial Health States

| Value | Meaning  |
| ----: | -------- |
|  0x00 | UNKNOWN  |
|  0x01 | OK       |
|  0x02 | DEGRADED |
|  0x03 | CRITICAL |

---

# FAULT_REPORT

Message ID:

`0x0902`

Purpose:

Reports a detected system fault.

## Payload

| Field            | Type   | Description                   |
| ---------------- | ------ | ----------------------------- |
| fault_code       | uint16 | Fault identifier              |
| severity         | uint8  | Fault severity                |
| source_component | uint8  | Component reporting the fault |
| occurrence_count | uint16 | Number of occurrences         |
| detail           | uint32 | Fault-specific detail field   |

## Initial Severity Levels

| Value | Meaning  |
| ----: | -------- |
|  0x00 | INFO     |
|  0x01 | WARNING  |
|  0x02 | ERROR    |
|  0x03 | CRITICAL |

## Safety

Critical propulsion-related faults shall be handled locally by the Teensy.

A fault message is telemetry about the event; it must not be the only mechanism responsible for enforcing safety.
