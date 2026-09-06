# PAYLOAD_DATA

Message ID:

`0x0701`

Purpose:

Transfers environmental payload measurements from the ESP32-S3 payload controller.

## Typical Route

```text
ESP32-S3 -> Raspberry Pi -> GCS
```

## Payload

| Field            | Type    | Unit     | Description                  |
| ---------------- | ------- | -------- | ---------------------------- |
| sample_id        | uint32  | -        | Monotonic sample identifier  |
| ph               | float32 | pH       | pH measurement               |
| dissolved_oxygen | float32 | TBD      | Dissolved oxygen measurement |
| temperature      | float32 | degC     | Temperature measurement      |
| sensor_status    | uint16  | bitfield | Payload sensor status        |

## Notes

Exact units and calibration representation for dissolved oxygen remain TBD until the final sensor interface and data sheet are confirmed.

Payload data is not considered propulsion-critical by default.
