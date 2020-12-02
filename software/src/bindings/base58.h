/*
 * Copyright (C) 2020 Erik Fleckstein <erik@tinkerforge.com>
 *
 * Redistribution and use in source and binary forms of this file,
 * with or without modification, are permitted. See the Creative
 * Commons Zero (CC0 1.0) License for more details.
 */

#ifndef TF_BASE58_H
#define TF_BASE58_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

void tf_base58_encode(uint32_t value, char *str) TF_ATTRIBUTE_NONNULL_ALL;
int tf_base58_decode(const char *str, uint32_t *ret_value) TF_ATTRIBUTE_NONNULL_ALL TF_ATTRIBUTE_WARN_UNUSED_RESULT;

#ifdef __cplusplus
}
#endif

#endif
