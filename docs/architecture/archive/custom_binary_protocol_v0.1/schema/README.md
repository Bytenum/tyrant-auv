# Tyrant Message Schemas

This directory defines the payload schema for each Tyrant protocol message.

Each message schema shall define:

* message name
* message ID
* sender(s)
* receiver(s)
* payload fields
* field types
* units
* valid ranges where applicable
* expected update rate
* safety relevance
* notes and constraints

All multi-byte numeric fields shall use a single protocol-wide byte order.

The byte order has not yet been frozen for protocol version 0.1.

Message schemas are currently provisional.
