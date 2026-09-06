# Mode Messages

## Mode Enumeration

| Value | Mode      |
| ----: | --------- |
|  0x00 | BOOT      |
|  0x01 | IDLE      |
|  0x02 | MANUAL    |
|  0x03 | AUTO      |
|  0x04 | SAFE      |
|  0x05 | FAULT     |
|  0x06 | EMERGENCY |

---

# MODE_COMMAND

Message ID:

`0x0101`

Purpose:

Requests a vehicle operating-mode transition.

## Typical Route

```text
GCS -> Raspberry Pi -> Teensy
```

The Raspberry Pi may request the transition, but the Teensy has final authority over propulsion-related mode changes.

## Payload

| Field          | Type   | Description                                       |
| -------------- | ------ | ------------------------------------------------- |
| requested_mode | uint8  | Requested operating mode                          |
| request_id     | uint16 | Identifier used to correlate command and response |

## Safety

Receiving `MODE_COMMAND` does not imply automatic acceptance.

The Teensy shall validate whether the requested transition is allowed.

---

# MODE_STATUS

Message ID:

`0x0102`

Purpose:

Reports the actual operating mode accepted by the vehicle controller.

## Typical Route

```text
Teensy -> Raspberry Pi -> GCS
```

## Payload

| Field             | Type   | Description                            |
| ----------------- | ------ | -------------------------------------- |
| current_mode      | uint8  | Current authoritative vehicle mode     |
| previous_mode     | uint8  | Previous operating mode                |
| request_id        | uint16 | Associated mode request, if applicable |
| transition_status | uint8  | Result of requested transition         |

## Transition Status

Initial values:

| Value | Meaning          |
| ----: | ---------------- |
|  0x00 | NONE             |
|  0x01 | ACCEPTED         |
|  0x02 | REJECTED         |
|  0x03 | FORCED_BY_SAFETY |
