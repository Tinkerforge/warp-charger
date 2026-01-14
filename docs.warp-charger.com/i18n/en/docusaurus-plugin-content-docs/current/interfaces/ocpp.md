---
sidebar_position: 3
---

# OCPP

When a charger needs to be integrated into a cloud or a large number of
chargers need to be managed, the OCPP standard is often used.

OCPP (Open Charge Point Protocol) is a standardized
communication protocol between charging stations and a central
management system. The WARP2 and WARP3 Charger support OCPPJ 1.6 Core Profile
and Smart Charging Profile.

## Configuration

To use OCPP, the charger must first be added to the cloud being used.
In this example we use https://ladefoxx.one.
However, the necessary settings must be configured on every cloud or
OCPP server.

![image](/img/interfaces/ocpp/ocpp_configuration_ladefoxx.png)

On ladefoxx.one, the charge point identity is entered in particular
(called "Controller ID" in the screenshot). This is provided by the WARP Charger.

After saving, the cloud provides a password or hex key.
This must be entered in the WARP Charger under `Interfaces` -> `OCPP`
together with the appropriate endpoint URL.

![image](/img/interfaces/ocpp/ocpp_configuration_warp.png)

If the entered password is exactly 40 characters long and consists only of
hexadecimal characters (0-9, A-F, a-f), it is interpreted as a hex key
that encodes a 20-byte key.

It is also possible that no authorization is required, in which
case authorization can be disabled in the WARP Charger.

Under the Debug and Configurations sections, further
information can be found to help diagnose problems when interacting with an
OCPP server.
