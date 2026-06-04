#!/usr/bin/env python3
"""
Generate the Phasenumschaltung chart for pv-excess-charging page.

Language-neutral chart showing:
- PV surplus over the day (orange).
- EV charging power tracking surplus, clamped to phase modes.
  1-phase region rendered in light blue, 3-phase region in dark blue.
- 1.4 kW and 4.2 kW thresholds = off / 1ph / 3ph cutoffs.
"""
from __future__ import annotations

import os
import subprocess
import tempfile

import matplotlib.pyplot as plt
import matplotlib.patches as patches
import numpy as np

# --------------------------------------------------------------------------- #
# Data: PV surplus over the day, smooth bell with a noon cloud dip.
# --------------------------------------------------------------------------- #
hours = np.linspace(6, 20, 1401)  # 0.01 h resolution

def pv_surplus(t):
    # Bell shape centered at solar noon (~13h), peak ~7.5 kW.
    bell = 7.5 * np.exp(-((t - 13.0) ** 2) / (2 * 2.6 ** 2))
    # Cloud dip around 12.5h.
    dip = 2.6 * np.exp(-((t - 12.5) ** 2) / (2 * 0.45 ** 2))
    surplus = bell - dip
    return np.clip(surplus, 0, None)

pv = pv_surplus(hours)

# --------------------------------------------------------------------------- #
# EV charging power, derived from surplus with phase-switching logic.
# Modes:  off (<1.4 kW)  |  1ph (1.4 - 4.2 kW)  |  3ph (>= 4.2 kW)
# Hysteresis is ignored for clarity; we just clamp.
# --------------------------------------------------------------------------- #
T_OFF = 1.4
T_3PH = 4.2

ev = np.zeros_like(pv)
mask_1ph = (pv >= T_OFF) & (pv < T_3PH)
mask_3ph = pv >= T_3PH
# In each charging mode the EV simply uses all available PV surplus,
# which keeps the chart visually continuous (no yellow gap between the
# EV curve and the PV curve at the phase-switch transition).
ev[mask_1ph] = pv[mask_1ph]
ev[mask_3ph] = pv[mask_3ph]

# --------------------------------------------------------------------------- #
# Plot.
# --------------------------------------------------------------------------- #
W_IN, H_IN = 12.0, 8.0  # 1200 x 800 @ 100 DPI
fig, ax = plt.subplots(figsize=(W_IN, H_IN), dpi=100)

# Colors
PV_COLOR = "#F59E0B"
PV_FACE = "#FFB547"
PV_OFF_COLOR = "#9ca3af"   # grey for PV in the OFF zone
PV_OFF_FACE = "#cbd1d8"
EV_1PH_COLOR = "#60a5fa"   # lighter blue for 1-phase
EV_1PH_FACE = "#93c5fd"
EV_3PH_COLOR = "#1d4ed8"   # darker blue for 3-phase
EV_3PH_FACE = "#3b82f6"
THRESHOLD_COLOR = "#9ca3af"
TEXT_COLOR = "#1f2937"
GRID_COLOR = "#eef0f3"

# Axes background
ax.set_facecolor("#fafbfc")

# Phase zone shading (very subtle)
ax.axhspan(T_OFF, T_3PH, facecolor=EV_1PH_FACE, alpha=0.06, zorder=0)
ax.axhspan(T_3PH, 8, facecolor=EV_3PH_FACE, alpha=0.07, zorder=0)

# Gridlines
ax.set_axisbelow(True)
ax.grid(True, which="major", color=GRID_COLOR, linewidth=1, zorder=1)

# PV surplus area, split by mode:
#   - Grey while charger is OFF (surplus < 1.4 kW): power isn't usable for charging.
#   - Yellow while charger is active (surplus >= 1.4 kW).
mask_off = pv < T_OFF
mask_on = pv >= T_OFF


def extend_mask(mask):
    """Extend mask by one sample at each rising/falling edge so adjacent
    fills overlap by one sample point and render without a visible seam."""
    extended = mask.copy()
    edges = np.diff(mask.astype(int))
    rises = np.where(edges == 1)[0]   # index just before mask becomes True
    falls = np.where(edges == -1)[0]  # last index where mask is True
    extended[rises] = True
    extended[np.clip(falls + 1, 0, len(mask) - 1)] = True
    return extended


mask_off_ext = extend_mask(mask_off)
mask_on_ext = extend_mask(mask_on)

pv_off = np.where(mask_off_ext, pv, np.nan)
pv_on = np.where(mask_on_ext, pv, np.nan)

ax.fill_between(hours, 0, pv_off, color=PV_OFF_FACE, alpha=0.55, zorder=2, label="Off")
ax.fill_between(hours, 0, pv_on, color=PV_FACE, alpha=0.45, zorder=2)
ax.plot(hours, pv_off, color=PV_OFF_COLOR, linewidth=2.5, zorder=3)
ax.plot(hours, pv_on, color=PV_COLOR, linewidth=2.5, zorder=3)

# EV charging areas: split by phase mode so each is colored differently.
mask_1ph_ext = extend_mask(mask_1ph)
mask_3ph_ext = extend_mask(mask_3ph)

ev_1ph = np.where(mask_1ph_ext, ev, np.nan)
ax.fill_between(hours, 0, ev_1ph, color=EV_1PH_FACE, alpha=0.7, zorder=4, label="1ph")
ev_3ph = np.where(mask_3ph_ext, ev, np.nan)
ax.fill_between(hours, 0, ev_3ph, color=EV_3PH_FACE, alpha=0.65, zorder=4, label="3ph")

# Outline lines on top of the fills (skip NaN segments automatically)
ax.plot(hours, ev_1ph, color=EV_1PH_COLOR, linewidth=2.8, zorder=5)
ax.plot(hours, ev_3ph, color=EV_3PH_COLOR, linewidth=3.0, zorder=5)

# Threshold lines
ax.axhline(T_OFF, color=THRESHOLD_COLOR, linewidth=1.5, linestyle=(0, (6, 5)), zorder=6)
ax.axhline(T_3PH, color=THRESHOLD_COLOR, linewidth=1.5, linestyle=(0, (6, 5)), zorder=6)

# Zone labels (left side, inside the plot)
ax.text(6.15, 6.0, "3ph", color=EV_3PH_COLOR, fontsize=14, fontweight="bold", alpha=0.9, va="center")
ax.text(6.15, 2.8, "1ph", color=EV_1PH_COLOR, fontsize=14, fontweight="bold", alpha=0.95, va="center")
ax.text(6.15, 0.7, "Off", color=THRESHOLD_COLOR, fontsize=14, fontweight="bold", va="center")

# Axes ranges
ax.set_xlim(6, 20)
ax.set_ylim(0, 8)

# Y ticks: include thresholds
y_ticks = [0, T_OFF, T_3PH, 6, 8]
y_labels = ["0", "1.4", "4.2", "6", "8"]
ax.set_yticks(y_ticks)
ax.set_yticklabels(y_labels)
# Highlight threshold tick labels
for label, val in zip(ax.get_yticklabels(), y_ticks):
    if val in (T_OFF, T_3PH):
        label.set_fontweight("bold")
        label.set_color(TEXT_COLOR)
    else:
        label.set_color("#374151")

# X ticks every 2 h
ax.set_xticks([6, 8, 10, 12, 14, 16, 18, 20])
ax.tick_params(axis="x", colors="#374151")
ax.tick_params(axis="both", which="major", labelsize=14)

# Axis titles (just units, language-neutral)
ax.set_xlabel("h", fontsize=15, color=TEXT_COLOR, labelpad=6, fontweight="bold")
ax.set_ylabel("kW", fontsize=15, color=TEXT_COLOR, labelpad=6, fontweight="bold", rotation=0, ha="right")
ax.yaxis.set_label_coords(-0.02, 1.02)
ax.xaxis.set_label_coords(1.02, -0.02)

# Spines
for side in ("top", "right"):
    ax.spines[side].set_visible(False)
for side in ("left", "bottom"):
    ax.spines[side].set_color(TEXT_COLOR)
    ax.spines[side].set_linewidth(1.5)

# Legend
legend = ax.legend(loc="upper right", fontsize=14, frameon=True, framealpha=1,
                   edgecolor="#e5e7eb", borderpad=0.6)
legend.get_frame().set_linewidth(1)

plt.tight_layout()

# --------------------------------------------------------------------------- #
# Save as PNG, then convert to WebP via ImageMagick.
# --------------------------------------------------------------------------- #
out_dir = os.path.join(os.path.dirname(__file__), "..", "static", "images")
out_dir = os.path.abspath(out_dir)
out_webp = os.path.join(out_dir, "phase-switching.webp")

with tempfile.NamedTemporaryFile(suffix=".png", delete=False) as tmp:
    tmp_png = tmp.name

fig.savefig(tmp_png, dpi=100, bbox_inches="tight", pad_inches=0.6, facecolor="white")
plt.close(fig)

subprocess.run(
    ["convert", tmp_png, "-quality", "92", out_webp],
    check=True,
)
os.unlink(tmp_png)
print(f"Wrote {out_webp}")
