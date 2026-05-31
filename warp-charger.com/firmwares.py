"""
Firmware changelog loader.

Reads firmware version indexes and changelog text files directly from
the ../firmwares/ directory.
Results are cached per (firmware_type, lang) with mtime-based invalidation.
"""

import re
import html
from pathlib import Path

FIRMWARES_DIR = Path(__file__).parent.parent / "firmwares"

# Firmware types in display order
FIRMWARE_TYPES = [
    {
        "type": "warp3",
        "env_name": "warp3",
        "display_name": {
            "de": "WARP3 Charger",
            "en": "WARP3 Charger",
        },
        "id": "warp3",
    },
    {
        "type": "warp2",
        "env_name": "warp2",
        "display_name": {
            "de": "WARP2 Charger",
            "en": "WARP2 Charger",
        },
        "id": "warp2",
    },
    {
        "type": "warp",
        "env_name": "warp",
        "display_name": {
            "de": "WARP Charger",
            "en": "WARP Charger",
        },
        "id": "warp1",
    },
    {
        "type": "wem2",
        "env_name": "energy_manager_v2",
        "display_name": {
            "de": "WARP Energy Manager 2.0",
            "en": "WARP Energy Manager 2.0",
        },
        "id": "wem2",
    },
    {
        "type": "wem",
        "env_name": "energy_manager",
        "display_name": {
            "de": "WARP Energy Manager",
            "en": "WARP Energy Manager",
        },
        "id": "wem1",
    },
]

# Cache: key = (firmware_type, lang), value = (index_mtime, data)
_cache = {}


def _parse_changelog_line(line):
    """Process a changelog line, converting markup tags to HTML."""
    line = line.strip().removeprefix("- ")
    if not line:
        return None
    line = html.escape(line, quote=False)
    line = re.sub(r'\[a:([^\]]+)\]', r'<a href="\1">', line)
    line = line.replace("[/a]", "</a>")
    line = line.replace("[b]", "<strong>")
    line = line.replace("[/b]", "</strong>")
    # Strip [c]...[/c] color markup (not needed in new design)
    line = re.sub(r'\[c\]', '', line)
    line = re.sub(r'\[/c\]', '', line)
    return line


def _load_firmware_versions(fw_type_info, lang):
    """Load all firmware versions for a given type and language."""
    env_name = fw_type_info["env_name"]
    index_path = FIRMWARES_DIR / f"{env_name}_firmware_v2.txt"

    if not index_path.exists():
        return []

    with open(index_path, "r") as f:
        index_lines = f.readlines()

    versions = []
    for index_line in index_lines:
        index_line = index_line.strip()
        if not index_line:
            continue

        # Parse version+hash format: "2.10.1+69e9e031"
        version_str, hash_str = index_line.split("+", 1)
        index_version = index_line.replace(".", "_").replace("-", "_").replace("+", "_")

        # Build firmware filename
        firmware_filename = f"{env_name}_firmware_{index_version}_merged.bin"

        # Read changelog file
        changelog_path = FIRMWARES_DIR / f"{env_name}_firmware_{index_version}_changelog_{lang}.txt"
        if not changelog_path.exists():
            # Fall back to German if English not available
            changelog_path = FIRMWARES_DIR / f"{env_name}_firmware_{index_version}_changelog_de.txt"
            if not changelog_path.exists():
                continue

        with open(changelog_path, "r") as f:
            changelog_lines = list(f.readlines())

        if not changelog_lines:
            continue

        # Parse first line: "2026-04-23: 2.10.1 (9c0329bc)"
        m = re.match(
            r"^(20[0-9]{2})-([0-9]{2})-([0-9]{2}): ([0-9]+\.[0-9]+\.[0-9]+(?:-beta\.[0-9]+)?)",
            changelog_lines[0],
        )
        if not m:
            continue

        firmware_date = f"{m.group(3)}.{m.group(2)}.{m.group(1)}"
        firmware_version = m.group(4)

        # Parse changelog items
        changelog_items = []
        for cl_line in changelog_lines[1:]:
            item = _parse_changelog_line(cl_line)
            if item:
                changelog_items.append(item)

        versions.append({
            "version": firmware_version,
            "date": firmware_date,
            "filename": firmware_filename,
            "url": f"/firmwares/{firmware_filename}",
            "checksum_url": f"/firmwares/{firmware_filename}.sha256",
            "changelog": changelog_items,
        })

    return versions


def get_all_firmwares(lang):
    """
    Return a list of firmware product dicts, each with id, display_name, versions (list of version dicts)

    Uses mtime-based caching on the index file.
    """
    result = []

    for fw_type_info in FIRMWARE_TYPES:
        env_name = fw_type_info["env_name"]
        index_path = FIRMWARES_DIR / f"{env_name}_firmware_v2.txt"
        cache_key = (fw_type_info["type"], lang)

        # Check cache
        if cache_key in _cache:
            cached_mtime, cached_data = _cache[cache_key]
            if index_path.exists() and index_path.stat().st_mtime == cached_mtime:
                result.append(cached_data)
                continue

        versions = _load_firmware_versions(fw_type_info, lang)
        data = {
            "id": fw_type_info["id"],
            "display_name": fw_type_info["display_name"].get(lang, fw_type_info["display_name"]["de"]),
            "versions": versions,
        }

        if index_path.exists():
            _cache[cache_key] = (index_path.stat().st_mtime, data)

        result.append(data)

    return result
