# Tyrant Communication Protocol Specification

Protocol Version: **0.1**

Status: **Development**

## Purpose

The Tyrant Communication Protocol defines communication between:

* Ground Control Station
* Raspberry Pi
* Teensy 4.1
* ESP32-S3
* simulation and test tools

The protocol is independent of the physical transport whenever possible.

## Packet Structure

Every packet consists of:

```text
HEADER
VERSION
SOURCE
DESTINATION
MSG_ID
SEQUENCE
TIMESTAMP
LENGTH
PAYLOAD
CRC
```

The packet header contains enough information to:

* identify packet boundaries
* identify protocol version
* identify source and destination
* identify message type
* detect lost or repeated packets
* associate data with a time reference
* determine payload length
* detect corrupted packets

## Node Identifiers

|   ID | Node                   |
| ---: | ---------------------- |
| 0x01 | Ground Control Station |
| 0x02 | Raspberry Pi           |
| 0x03 | Teensy                 |
| 0x04 | ESP32-S3               |
| 0xFF | Broadcast              |

## Message Classes

Message identifiers are grouped by function.

| Range         | Class                 |
| ------------- | --------------------- |
| 0x0000–0x00FF | System                |
| 0x0100–0x01FF | Mode and Safety       |
| 0x0200–0x02FF | Command and Reference |
| 0x0300–0x03FF | Vehicle State         |
| 0x0400–0x04FF | Sensors               |
| 0x0500–0x05FF | Control and Thrusters |
| 0x0600–0x06FF | Mission               |
| 0x0700–0x07FF | Payload               |
| 0x0800–0x08FF | Parameters            |
| 0x0900–0x09FF | Fault and Health      |

## Design Requirements

The protocol shall:

* use explicit versioning
* use deterministic binary serialization
* support sequence numbers
* support timestamps
* provide payload length information
* provide packet integrity checking
* support heartbeat messages
* support communication timeout detection
* avoid dependence on a single physical transport
* remain implementable on both microcontrollers and Linux systems

## Safety

Loss of communication with the Raspberry Pi shall be detectable by the Teensy.

Communication timeout handling for propulsion safety shall remain under Teensy authority.

Loss of payload-controller communication shall not automatically disable propulsion unless explicitly classified as a critical fault.

## Status

Exact field encoding, byte order, packet synchronization method, CRC algorithm, maximum payload size, and transport-specific framing remain to be defined.
