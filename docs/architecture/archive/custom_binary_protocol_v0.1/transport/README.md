# Tyrant Transport Layer

The Tyrant transport layer defines how protocol packets are carried between system nodes.

The transport layer is intentionally separated from the Tyrant message protocol.

A message such as `HEARTBEAT`, `MODE_COMMAND`, or `VEHICLE_STATE` must retain the same semantic meaning regardless of whether it is carried over:

* UART
* USB serial
* Ethernet
* a simulated transport
* another supported physical link

## Architecture

```text
Application
    |
Message Encoding
    |
Tyrant Packet
    |
Transport Interface
    |
Physical Transport
```

## Initial System Links

### GCS ↔ Raspberry Pi

Expected transport:

Ethernet over the vehicle tether communication system.

The exact GCS application protocol and socket implementation remain to be defined.

### Raspberry Pi ↔ Teensy 4.1

The physical transport is not yet frozen.

Candidate transports include:

* USB serial
* hardware UART

The final choice shall depend on electrical design, reliability, available interfaces, and integration testing.

### Raspberry Pi ↔ ESP32-S3

The physical transport is not yet frozen.

Candidate transports include:

* USB serial
* hardware UART

The final choice shall depend on electrical design and payload integration requirements.

## Transport Interface

Software modules should interact with transports using a common conceptual interface.

Example:

```text
open()
close()
send(data)
receive()
is_connected()
```

Transport implementations may provide additional diagnostics such as:

```text
bytes_sent
bytes_received
packet_errors
timeouts
reconnect_count
```

## Requirements

The transport architecture shall:

* remain independent from message semantics
* support binary Tyrant packets
* detect link loss
* support communication diagnostics
* avoid blocking real-time control execution
* allow simulated transports during software development
* allow physical transport changes without redesigning message schemas

## Teensy Requirement

Communication processing shall not block the real-time control loop.

Incoming data should be buffered and parsed independently from estimator and controller execution.

## Raspberry Pi Requirement

The Raspberry Pi should maintain separate communication sessions for the Teensy and ESP32-S3.

Message routing between GCS, Teensy, ESP32-S3, and logging services shall remain separate from the physical transport implementation.

## Simulation Requirement

A simulated transport shall be available so the communication stack can be tested without vehicle hardware.

The simulator should be capable of reproducing:

* normal packet flow
* packet delay
* packet loss
* corrupted packets
* communication timeout
* node disconnection

## Status

Physical interfaces and transport-specific parameters remain under development.
