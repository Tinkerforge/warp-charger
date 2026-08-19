#!/usr/bin/env python3
"""Batch firmware upload for WARP chargers and WEMs.

Queries the device type via the HTTP API (GET /info/name -> "type") and
uploads the matching firmware via POST /flash_firmware.
Adjust HOSTNAMES and FIRMWARES below.
"""

import json
import sys
import time
import urllib.error
import urllib.request

HOSTNAMES = [
#    "wem2-garage.localdomain",
    "wem2-west.localdomain",
    "wallbox-west1.localdomain",
    "wallbox-west2.localdomain",
#    "wallbox-hr1.localdomain",
    "wallbox-hr2.localdomain",
    "wallbox-hr3.localdomain",
    "wallbox-hr4.localdomain",
    "wallbox-hr5.localdomain",
    "wallbox-hr6.localdomain",
    "wallbox-cp1.localdomain",
    "wallbox-cp2.localdomain",
    "wallbox-cp3.localdomain",
    "wallbox-cp4.localdomain",
    "wallbox-cp5.localdomain",
    "wallbox-cp6.localdomain",
    "wallbox-cp7.localdomain",
    "wallbox-cp8.localdomain",
]

FIRMWARES = {
    "warp":  "build/warp_firmware_latest_merged.bin",
    "warp2": "build/warp2_firmware_latest_merged.bin",
    "warp3": "build/warp3_firmware_latest_merged.bin",
    "warp4": "build/warp4_firmware_latest_ota.bin",
    "wem":   "build/energy_manager_firmware_latest_merged.bin",
    "wem2":  "build/energy_manager_v2_firmware_latest_merged.bin",
}

FLASH_RETRIES = 5
VALIDATE_TRIES = 45 

VALIDATE = False # directly validate firmware after flash

class ContentTypeRemover(urllib.request.BaseHandler):
    def http_request(self, req):
        if req.has_header("Content-type"):
            req.remove_header("Content-type")
        return req

    https_request = http_request


def get_device_type(host):
    try:
        with urllib.request.urlopen(f"http://{host}/info/name", timeout=5) as f:
            info = json.load(f)
    except (urllib.error.URLError, OSError, json.JSONDecodeError) as e:
        print(f"  ERROR: can't query /info/name: {e}")
        return None

    device_type = info.get("type")
    print(f"  Device: {info.get('display_type', '?')} ({info.get('name', '?')}), type '{device_type}'")
    return device_type


def flash_firmware(host, fw):
    opener = urllib.request.build_opener(ContentTypeRemover())

    for i in range(FLASH_RETRIES):
        try:
            req = urllib.request.Request(f"http://{host}/flash_firmware", fw)
            print(" ", opener.open(req, timeout=120).read().decode())
            return True
        except urllib.error.HTTPError as e:
            body = ""
            try:
                body = e.read().decode("utf-8", "replace")
            except Exception:
                pass
            if e.code == 423:
                print(f"  ERROR: {host} blocked the update (vehicle connected?)")
            else:
                print(f"  ERROR: HTTP {e.code}: {body}")
            return False
        except urllib.error.URLError as e:
            if isinstance(getattr(e, "reason", None), ConnectionResetError):
                print(f"  ERROR: {host} reset the connection (vehicle connected?)")
                return False
            if i != FLASH_RETRIES - 1:
                print(f"  Upload failed ({e}), retrying...")
                time.sleep(3)
            else:
                print(f"  ERROR: can't reach {host}: {e}")
        except OSError as e:
            if i != FLASH_RETRIES - 1:
                print(f"  Upload failed ({e}), retrying...")
                time.sleep(3)
            else:
                print(f"  ERROR: can't reach {host}: {e}")

    return False


def validate(host):
    # Wait for the reboot, then mark the new partition as valid.
    print(f"  Waiting for {host} to reboot and validating", end="", flush=True)
    for _ in range(VALIDATE_TRIES):
        start = time.monotonic()
        try:
            with urllib.request.urlopen(f"http://{host}/firmware_update/validate", timeout=1):
                print(" OK")
                return True
        except Exception:
            pass
        time.sleep(max(0, 1 - (time.monotonic() - start)))
        print(".", end="", flush=True)
    print(" FAILED")
    return False


def main():
    firmware_data = {}
    failed = []

    for hostname in HOSTNAMES:
        print(f"=== {hostname} ===")

        device_type = get_device_type(hostname)
        if device_type is None:
            failed.append(hostname)
            continue

        if device_type not in FIRMWARES:
            print(f"  ERROR: no firmware configured for type '{device_type}'")
            failed.append(hostname)
            continue

        if device_type not in firmware_data:
            try:
                with open(FIRMWARES[device_type], "rb") as f:
                    firmware_data[device_type] = f.read()
            except OSError as e:
                print(f"  ERROR: can't read firmware: {e}")
                failed.append(hostname)
                continue

        if not flash_firmware(hostname, firmware_data[device_type]):
            failed.append(hostname)
            continue

        time.sleep(3)

        if VALIDATE and (not validate(hostname)):
            failed.append(hostname)

    print()
    if failed:
        print("FAILED hosts:", ", ".join(failed))
        return 1

    print("All hosts updated successfully.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
