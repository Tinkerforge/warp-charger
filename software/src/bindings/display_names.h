/*
 * Copyright (C) 2020 Erik Fleckstein <erik@tinkerforge.com>
 *
 * Redistribution and use in source and binary forms of this file,
 * with or without modification, are permitted. See the Creative
 * Commons Zero (CC0 1.0) License for more details.
 */

#ifndef TF_DISPLAY_NAMES_H
#define TF_DISPLAY_NAMES_H

#include <stdint.h>

#include "config.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef TF_IMPLEMENT_GET_DEVICE_DISPLAY_NAME
const char *tf_get_device_display_name(uint16_t device_id);
#endif

#ifdef __cplusplus
}
#endif

#endif
