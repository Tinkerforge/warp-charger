---
sidebar_position: 2
---

# Chargers


:::note

A WARP Charger Smart or Pro can be configured as a charge manager.
Up to 64 WARP Chargers (including the charge manager itself) can thus be
managed by one charger.

The WARP Energy Manager can also be configured as a charge manager for up to 64 WARP Chargers.

:::

![image](/img/webinterface/energy_management/wem2-wallboxes.jpeg)

On this page, the controlled chargers are configured. The settings made here
affect the [charge management](/tutorials/chargemanagement.md) between the chargers.

Type 2 chargers communicate the maximum available charging current to the connected vehicles.
The vehicle decides whether this charging current is fully utilized and whether a charging process is carried out single-phase, two-phase, or three-phase.


For a WARP Charger, the first setting to configure is how the charger is controlled (**External Control**):

 * **Disabled**: No charge management takes place. The charger is completely independent.
 * **Externally Controlled**: The charger is managed by another charge manager. No further settings need to be made.
 * **Charge Manager/PV Excess Charging**: The charger operates as a charge manager. This is also the case when it should only perform the [PV excess charging](/tutorials/pv_excess_charging.md) function independently. Further settings must be made.


## Charge Manager Configuration

If a WARP Charger or WARP Energy Manager is configured as a charge manager, the following settings must be made:

### Maximum Total Current

This is the maximum current of the supply line to the charge-managed chargers. The
charge manager ensures that this current is not exceeded on any phase by never distributing more than this current to the chargers (static load management).

If all chargers have adequately dimensioned separate supply lines, this current can be set high enough that all chargers can safely receive their maximum current. All other components, such as the grid connection,
must then be able to deliver the configured maximum total current. The individual maximum current of each charger remains unaffected.


:::note

This is static load management, which assumes that the set current is available on each phase at all times.
Other consumers besides WARP Chargers that cannot be controlled by the charge manager are not taken into account!

:::


At the end of the page, the *Controlled Chargers* managed by the charge manager are configured and displayed.
Additional chargers can be added by clicking *+*. For this, the display name and IP address or hostname of the
charger must be entered and confirmed by clicking *add*. Automatically detected chargers that are not yet
controlled by the charge manager are displayed as a list. For each charger, the phase rotation can additionally be set. This information is relevant for dynamic load management.


:::note

There is a dedicated tutorial for setting up charge management: [Charge Management](/tutorials/chargemanagement.md)

:::
