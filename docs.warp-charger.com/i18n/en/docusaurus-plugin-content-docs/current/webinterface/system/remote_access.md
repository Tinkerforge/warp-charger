---
sidebar_position: 3
---

# Remote Access

## Introduction
With remote access, you can always access a [WARP Charger](/warp_charger/introduction.md) or [WARP Energy Manager](/warp_energy_manager/introduction.md) from anywhere via [my.warp-charger.com](https://my.warp-charger.com).
The apps (iOS and Android) use remote access, so it must also be configured for app usage.

## How it Works and Privacy
In short, every connection via remote access establishes a separate, encrypted VPN. This VPN has only two participants: the device from which remote access is opened and the WARP Charger/WARP Energy Manager being accessed. This ensures that only you can retrieve data from your charger (not even we can!).

All data, except for your email address and your (freely selectable) username, is stored encrypted on our server. In such a way that even we cannot decrypt this data.

A more detailed description that goes deeper technically can be found in our [forum](https://www.tinkerunity.org/topic/12365-fernzugriff-alpha).

## Setup
First, an account at [my.warp-charger.com](https://my.warp-charger.com) is required. This must be created and confirmed.

The device must be restarted after adding the first user. After adding additional users, no restart is necessary.

![image](/img/webinterface/system/warp-system_remote_access.jpeg)

### With Credentials
Open the menu for adding a remote access user via the "+" button, enter the account credentials (the data is not saved)
and click "Add".

### With Authorization Token
Adding an account with an authorization token is faster, as the authorization token already contains all necessary information.

Authorization tokens can be created on the corresponding [subpage](https://my.warp-charger.com/tokens).

To register the device using an authorization token, select the "Authorization token" option in the add menu.
Then copy the authorization token into the corresponding field and click "Add".

## Removing from Remote Access
To temporarily remove a device from remote access, it is sufficient to disable remote access under `System -> Remote Access`.

If a user is to be permanently removed from the device, this can be done via the "Delete" button next to the email address.
The user's access is then already removed. To synchronize this with the server, the device must be restarted.
When removing the last user, the device is automatically deregistered from the server.

Alternatively, there is a button for removal on the remote access overview page.
Note that while the device is removed from the account and all access via remote access is blocked, remote access on the charger itself remains enabled.

## iOS App
Our iOS app is available in the Apple App Store: [WARP Charger iOS App](https://apps.apple.com/us/app/warp-by-tinkerforge/id6736695801)

## Android App
Our Android app is available in the Android Play Store: [WARP Charger Android App](https://play.google.com/store/apps/details?id=com.tinkerforge.warp)

## Recovery Page
The recovery page of the charger/Energy Manager can also be accessed via remote access. A device with a keyboard is required for this.
With the key combination Ctrl + Shift + Alt + R, the recovery page can be loaded while a connection exists. If this does not work,
focus may need to be removed from the web interface by clicking the footer once with the mouse.

## Technical Details

### Ports
Remote access uses an HTTPS connection (port 443/TCP) and a UDP connection on ports 51820-51825.
