---
sidebar_position: 3
---

# Automation

:::note

Automation rules exist for both WARP Chargers and the WARP Energy Manager. The configurable conditions and actions differ between different devices.

:::

On this page, rules can be defined that should be
executed automatically. Each rule consists of a condition
(e.g.: *Input 1 closed*) and an action
(e.g.: *Set SG-Ready output 1 to closed*).
Up to 14 rules can be created.

## Example Automations WARP Energy Manager

![image](/img/webinterface/energy_manager/wem2-automation.jpeg)

In this example, three independent rules were defined:

* Daily at 06:43, switch charging mode to PV.
* When MQTT message "Current" is received at topic "/Control/Test", limit the maximum total current to 16A
* When energy is fed into the grid, switch relay 1.

The first two rules set load management configurations of the wallboxes controlled by the Energy Manager in their action, and the third rule switches one of the relays installed in the WARP Energy Manager as an action.

Example screenshot of the modal window for editing the first rule:
![image](/img/webinterface/energy_manager/wem2-automation2.jpeg)


## Example Automations WARP Charger

![image](/img/webinterface/wallbox/warp-automation.png)

In this example, three rules were defined:

* Weekdays at 07:00, limit the allowed charging current to 0A.
* Weekdays at 16:00, limit the allowed charging current to 32A.
* When the front button is pressed, limit the allowed charging current to 32A.

With this list of rules, charging is not allowed on weekdays between 07:00-16:00 (rules 1 and 2), but it is possible to enable charging during this period anyway by pressing the front button (rule 3).

Example screenshot of the modal window for editing the third rule:
![image](/img/webinterface/wallbox/warp-automation-rule.png)
