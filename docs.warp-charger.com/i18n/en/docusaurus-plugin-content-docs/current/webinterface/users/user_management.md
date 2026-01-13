---
sidebar_position: 2
---

# User Management

:::note

This configuration is only available for [WARP Charger](/warp_charger/introduction.md).

:::


![image](/img/webinterface/users/warp-users-user_management1.jpeg)


Up to 32 users can be created. A created user to whom an
NFC tag has been assigned (see section [NFC](/webinterface/users/nfc-tags.md)) can have charging processes
assigned by the charge tracker. In the factory setting, three users are created, each of whom
has been assigned one of the included NFC cards. These can be renamed or deleted.

A new user can be added by clicking on *Add User*. This opens
a modal window in which the actual username, the display name (for display in the charge tracker), and
the maximum charging current allowed for the user can be set. Additionally, the user can be given a password
for HTTP login (see following section).

![image](/img/webinterface/users/warp-users-user_management2.jpeg)

If multiple users are to be created, we recommend creating them directly one after another. Afterwards, the
changes must be saved and the wallbox restarted for the changes to take effect.

If only charge authorization via NFC/user authorization is desired, user authorization must be enabled.

## Login

When *Login enabled* is selected, access to the web interface and use of the
HTTP API requires logging in as one of the configured users. HTTP login is
only possible if a password has been configured for the user. The function can only be activated if at least
one user with a configured password exists. Accordingly, users can be created who are only used for
charge tracking via NFC tag, but should not have access to the web interface, by not
giving them a password.

:::note

If the credentials for HTTP login are lost,
access can only be regained via recovery mode
or after a factory reset.

:::

:::note

There is a tutorial that also covers user management including NFC and charge log: [Setting Up the Charge Log](/tutorials/charge_tracking.md)

:::
