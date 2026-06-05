#!/usr/bin/env python3
"""Subset the Material Symbols icon font to only the icons the site uses."""
from __future__ import annotations

import re
import subprocess
import sys
from pathlib import Path

from fontTools.ttLib import TTFont

ROOT = Path(__file__).resolve().parent.parent
SRC_FONT = ROOT / "vendor" / "fonts" / "material-symbols-outlined-400.woff2"
OUT_FONT = ROOT / "static" / "fonts" / "material-symbols-outlined-400.woff2"

# Ligature features that may carry the icon substitutions. Kept together with
# --no-layout-closure so only rules covering the retained glyphs are emitted.
LAYOUT_FEATURES = "liga,dlig,calt,rlig,ccmp"

# A literal icon ligature inside a span, e.g.
#   <span class="material-symbols-outlined icon-18 text-primary">mail</span>
TEMPLATE_RE = re.compile(r"material-symbols-outlined[^>]*>\s*([a-z0-9_]+)\s*<", re.I)
# An icon value in a YAML file: icon:/section_icon:/badge_icon: "name"
YAML_RE = re.compile(r'[A-Za-z_]*icon:\s*["\']?([a-z0-9_]+)', re.I)
# The icon text inside a rendered material-symbols span (any classes/order).
RENDERED_RE = re.compile(
    r'class="[^"]*material-symbols-outlined[^"]*"[^>]*>\s*([^<\s][^<]*?)\s*<', re.I
)
ICON_TOKEN = re.compile(r"[a-z0-9_]+")


def scan_sources() -> set[str]:
    """Static scan of templates + translation YAMLs for icon names."""
    names: set[str] = set()
    for path in (ROOT / "templates").rglob("*.html"):
        names |= set(TEMPLATE_RE.findall(path.read_text(encoding="utf-8")))
    for path in (ROOT / "translations").rglob("*.yaml"):
        names |= set(YAML_RE.findall(path.read_text(encoding="utf-8")))
    return names


def render_sources() -> set[str]:
    """Render every page reachable via sitemap.xml and pull the icons used."""
    sys.path.insert(0, str(ROOT))
    try:
        import app  # noqa: WPS433 (import inside function is intentional)
    except Exception as exc:  # pragma: no cover - build-time guard
        print(f"  ! could not import app to render pages: {exc}", file=sys.stderr)
        print("  ! falling back to static scan only", file=sys.stderr)
        return set()

    client = app.app.test_client()
    sitemap = client.get("/sitemap.xml").get_data(as_text=True)
    paths = sorted(set(re.findall(r"https?://[^/]+(/[A-Za-z0-9_\-/]*)", sitemap)))

    names: set[str] = set()
    rendered = 0
    for path in paths:
        resp = client.get(path)
        if resp.status_code != 200:
            continue
        rendered += 1
        for raw in RENDERED_RE.findall(resp.get_data(as_text=True)):
            token = raw.strip()
            if ICON_TOKEN.fullmatch(token):
                names.add(token)
    print(f"  rendered {rendered} page(s)")
    return names


def build_ligature_map(font: TTFont) -> dict[str, str]:
    """Map each icon ligature name -> its target glyph name, from GSUB."""
    reverse_cmap = {glyph: chr(cp) for cp, glyph in font.getBestCmap().items()}
    gsub = font["GSUB"].table
    name_to_glyph: dict[str, str] = {}
    for lookup in gsub.LookupList.Lookup:
        for subtable in lookup.SubTable:
            lookup_type, table = lookup.LookupType, subtable
            if lookup_type == 7:  # Extension substitution
                table, lookup_type = subtable.ExtSubTable, subtable.ExtensionLookupType
            if lookup_type != 4:  # 4 == Ligature substitution
                continue
            for first_glyph, ligatures in table.ligatures.items():
                first_char = reverse_cmap.get(first_glyph)
                if first_char is None:
                    continue
                for lig in ligatures:
                    chars = [first_char]
                    ok = True
                    for component in lig.Component:
                        char = reverse_cmap.get(component)
                        if char is None:
                            ok = False
                            break
                        chars.append(char)
                    if ok:
                        name_to_glyph["".join(chars)] = lig.LigGlyph
    return name_to_glyph


def main() -> int:
    if not SRC_FONT.exists():
        print(f"ERROR: source font missing: {SRC_FONT}", file=sys.stderr)
        return 1

    print("Collecting icon names...")
    names = scan_sources() | render_sources()
    names = {n for n in names if n and not n.isdigit()}
    if len(names) < 30:
        print(
            f"ERROR: only found {len(names)} icon names; scan likely broke. "
            "Refusing to ship a bad subset.",
            file=sys.stderr,
        )
        return 1
    print(f"  {len(names)} unique icon names")

    font = TTFont(SRC_FONT)
    name_to_glyph = build_ligature_map(font)
    glyphs: set[str] = set()
    unresolved: set[str] = set()
    for name in names:
        glyph = name_to_glyph.get(name)
        (glyphs.add(glyph) if glyph else unresolved.add(name))
    if unresolved:
        # Not fatal: these are tokens that look like icon names but aren't real
        # Material Symbols (e.g. a stray YAML value). They'd render nothing
        # anyway, so just leave them out and report.
        print(f"  note: {len(unresolved)} token(s) are not real icons: "
              f"{', '.join(sorted(unresolved))}")
    wanted = names - unresolved
    print(f"  {len(glyphs)} glyphs to keep")

    OUT_FONT.parent.mkdir(parents=True, exist_ok=True)
    text = " ".join(sorted(wanted))
    cmd = [
        sys.executable, "-m", "fontTools.subset", str(SRC_FONT),
        f"--output-file={OUT_FONT}",
        "--flavor=woff2",
        "--no-layout-closure",
        f"--layout-features+={LAYOUT_FEATURES}",
        f"--text={text}",
        "--glyphs=" + ",".join(sorted(glyphs)),
    ]
    print("Subsetting...")
    subprocess.run(cmd, check=True)

    # Verify every wanted ligature survived in the subset.
    subset = TTFont(OUT_FONT)
    kept = set(build_ligature_map(subset))
    lost = sorted(wanted - kept)
    if lost:
        print(f"ERROR: subset dropped {len(lost)} icon(s): {lost}", file=sys.stderr)
        return 1

    before = SRC_FONT.stat().st_size
    after = OUT_FONT.stat().st_size
    print(
        f"Done: {OUT_FONT.relative_to(ROOT)}  "
        f"{before / 1024:.1f} KiB -> {after / 1024:.1f} KiB "
        f"({100 * after / before:.1f}% of original, {len(wanted)} icons)"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
