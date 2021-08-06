/* warp-charger
 * Copyright (C) 2020-2021 Erik Fleckstein <erik@tinkerforge.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#pragma once

#include "config.h"
#include "ringbuffer.h"
#include "malloc_tools.h"

// How many hours to keep the coarse history for
#define HISTORY_HOURS 48
// How many minutes to keep the fine history for.
// This also controls the coarseness of the coarse history.
// For example 4 means that we accumulate 4 minutes of samples
// with the maximum rate i.e. ~ 3 samples per second (Querying the state
// takes about 380 ms).
// When we have 4 minutes worth of samples, we take the average
// and add it to the coarse history.
#define HISTORY_MINUTE_INTERVAL 4

#define RING_BUF_SIZE (HISTORY_HOURS * (60 / HISTORY_MINUTE_INTERVAL) + 1)

class EVSEV2Meter {
public:
    EVSEV2Meter();
    void setup();
    bool setupEVSE();
    void register_urls();
    void loop();

    bool initialized = false;
    bool hardware_available = false;

private:
    Config state;
    Config detailed_values;
    Config energy_meter_reset;
    Config error_counters;

    int samples_last_interval = 0;
    int samples_per_interval = -1;
    TF_Ringbuffer<int16_t, 3 * 60 * HISTORY_MINUTE_INTERVAL, uint32_t, malloc_32bit_addressed, heap_caps_free> interval_samples;

    TF_Ringbuffer<int16_t, HISTORY_HOURS * (60 / HISTORY_MINUTE_INTERVAL) + 1, uint32_t, malloc_32bit_addressed, heap_caps_free> power_history;

    char uid[7] = {0};
};
