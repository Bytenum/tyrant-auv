# Tyrant Protocol Wire Format

Protocol Version: **0.1**

Status: **Development Baseline**

## Overview

The Tyrant Communication Protocol uses deterministic binary encoding.

All implementations must produce identical byte sequences for equivalent packets.

This applies to:

* Teensy 4.1 firmware
* ESP32-S3 firmware
* Raspberry Pi software
* simulation tools
* Ground Control Station software

---

## Byte Order

All multi-byte numeric fields use:

**Little-endian byte order**

Examples:

```text
uint16 0x1234
wire bytes:
34 12
```

```text
uint32 0x12345678
wire bytes:
78 56 34 12
```

---

## Integer Representation

The protocol uses fixed-width unsigned integers where possible.

Supported baseline types:

| Type   |    Size |
| ------ | ------: |
| uint8  |  1 byte |
| uint16 | 2 bytes |
| uint32 | 4 bytes |
| int8   |  1 byte |
| int16  | 2 bytes |
| int32  | 4 bytes |

Protocol fields shall not use architecture-dependent C/C++ types such as:

```text
int
long
unsigned long
```

unless their encoded width is explicitly defined.

---

## Floating-Point Representation

Floating-point values use:

**IEEE-754 binary32**

Protocol type:

```text
float32
```

Size:

```text
4 bytes
```

All floating-point fields are encoded using little-endian byte order.

Double-precision values are not part of the baseline protocol unless explicitly required by a future schema.

---

## Packet Magic

Every Tyrant packet begins with two synchronization bytes:

```text
0x54 0x59
```

ASCII representation:

```text
T Y
```

These bytes identify the beginning of a Tyrant packet candidate.

A receiver shall not assume that every occurrence of the magic sequence represents a valid packet.

The remaining header, payload length, and CRC must also validate successfully.

---

## Protocol Version

Protocol version 0.1 is encoded as:

```text
0x01
```

The protocol version field occupies one byte.

Packets containing unsupported protocol versions may be rejected.

---

## Maximum Payload Size

Protocol version 0.1 defines a maximum payload size of:

```text
256 bytes
```

Receivers must reject packets declaring payload lengths greater than this limit.

The maximum may be revised in future protocol versions.

---

## Packet Layout

Baseline packet layout:

| Offset | Field          | Type   | Size |
| -----: | -------------- | ------ | ---: |
|      0 | Magic 0        | uint8  |    1 |
|      1 | Magic 1        | uint8  |    1 |
|      2 | Version        | uint8  |    1 |
|      3 | Source         | uint8  |    1 |
|      4 | Destination    | uint8  |    1 |
|      5 | Message ID     | uint16 |    2 |
|      7 | Sequence       | uint16 |    2 |
|      9 | Timestamp      | uint32 |    4 |
|     13 | Payload Length | uint16 |    2 |
|     15 | Payload        | bytes  |    N |
| 15 + N | CRC            | uint16 |    2 |

Fixed header size before payload:

```text
15 bytes
```

Minimum packet size:

```text
17 bytes
```

Maximum baseline packet size:

```text
273 bytes
```

---

## Timestamp

The packet header timestamp is encoded as:

```text
uint32
```

Unit:

```text
milliseconds
```

The timestamp represents the sender's monotonic runtime clock unless a message explicitly defines another time reference.

It shall not be interpreted as UTC or Unix time by default.

The timestamp will wrap after the maximum `uint32` millisecond value.

Implementations shall handle wraparound correctly.

---

## Sequence Number

Each sending node maintains packet sequence numbers.

Type:

```text
uint16
```

Sequence numbers increment for each transmitted Tyrant packet.

After:

```text
65535
```

the next value wraps to:

```text
0
```

Receivers may use sequence numbers to detect:

* dropped packets
* duplicate packets
* reordered packets

Sequence-number gaps do not automatically indicate a system fault.

---

## CRC

Protocol version 0.1 uses:

**CRC-16/CCITT-FALSE**

Parameters:

```text
Width   : 16
Poly    : 0x1021
Init    : 0xFFFF
RefIn   : false
RefOut  : false
XorOut  : 0x0000
```

Check value for ASCII string:

```text
123456789
```

shall be:

```text
0x29B1
```

The CRC covers:

```text
Version
Source
Destination
Message ID
Sequence
Timestamp
Payload Length
Payload
```

The two magic bytes are excluded from CRC calculation.

The CRC itself is not included in CRC calculation.

The transmitted CRC field uses little-endian byte order.

---

## Packet Validation

A receiver shall consider a packet valid only when all applicable conditions are satisfied:

1. Magic bytes are correct.
2. Protocol version is supported.
3. Payload length is within the allowed limit.
4. The complete declared packet has been received.
5. CRC is valid.
6. Source and destination fields are syntactically valid.
7. Message ID is recognized or safely ignorable.

A malformed packet shall not be passed directly to application logic.

---

## Stream Resynchronization

Serial transports may begin receiving in the middle of a packet or may contain corrupted bytes.

The parser shall therefore support resynchronization.

Baseline strategy:

```text
SEARCH_MAGIC
    |
    v
READ_HEADER
    |
    v
VALIDATE_LENGTH
    |
    v
READ_PAYLOAD_AND_CRC
    |
    v
VALIDATE_CRC
    |
    +---- valid ----> DELIVER_PACKET
    |
    +---- invalid --> SEARCH_MAGIC
```

On framing or CRC failure, the parser returns to searching for the magic sequence.

Parser behavior shall never block the real-time control loop.

---

## Transport Independence

The packet representation defined here is independent from the underlying transport.

Equivalent Tyrant packets may be transported through:

* UART
* USB serial
* Ethernet
* TCP
* UDP
* simulation links
* replay/testing interfaces

Transport-specific framing shall not modify the semantic message payload.

---

## Safety Requirements

Malformed, incomplete, oversized, or CRC-invalid packets shall never directly alter propulsion commands.

Communication validity and control-command validity are separate checks.

The Teensy remains responsible for:

* communication timeout detection
* command freshness checking
* mode validation
* safety-state enforcement
* propulsion authority

---

## Future Considerations

Protocol versions after 0.1 may introduce:

* acknowledgement messages
* fragmentation
* larger payloads
* authentication
* additional timestamp semantics
* protocol capability negotiation

These features are not part of the current baseline.
