# Tyrant Communication Protocol

This directory contains the shared communication protocol definitions used by the Tyrant AUV software stack.

The protocol is shared between:

* Raspberry Pi
* Teensy 4.1
* ESP32-S3
* simulation tools
* Ground Control Station

The protocol specification must remain independent of the physical transport whenever possible.

For example, the same message definition should be usable over UART, USB serial, Ethernet, or another supported transport without changing the semantic meaning of the message.

## Responsibilities

This directory will eventually contain definitions for:

* packet framing
* protocol version
* node identifiers
* message identifiers
* payload schemas
* sequence numbers
* timestamps
* CRC/checksum
* heartbeat messages
* command messages
* telemetry messages
* fault messages
* parameter messages

## Design Principle

There should be one authoritative definition of each Tyrant message.

Firmware and companion software should not independently invent different packet formats.

## Status

Protocol design has not yet been frozen.

Current version:

`TYRANT Protocol v0.1 — development`
