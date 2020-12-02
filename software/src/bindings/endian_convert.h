/*
 * Copyright (C) 2020 Erik Fleckstein <erik@tinkerforge.com>
 *
 * Redistribution and use in source and binary forms of this file,
 * with or without modification, are permitted. See the Creative
 * Commons Zero (CC0 1.0) License for more details.
 */

#ifndef TF_ENDIAN_CONVERT_H
#define TF_ENDIAN_CONVERT_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int16_t tf_leconvert_int16_to(int16_t native);
uint16_t tf_leconvert_uint16_to(uint16_t native);
int32_t tf_leconvert_int32_to(int32_t native);
uint32_t tf_leconvert_uint32_to(uint32_t native);
int64_t tf_leconvert_int64_to(int64_t native);
uint64_t tf_leconvert_uint64_to(uint64_t native);
float tf_leconvert_float_to(float native);
int16_t tf_leconvert_int16_from(int16_t little);
uint16_t tf_leconvert_uint16_from(uint16_t little);
int32_t tf_leconvert_int32_from(int32_t little);
uint32_t tf_leconvert_uint32_from(uint32_t little);
int64_t tf_leconvert_int64_from(int64_t little);
uint64_t tf_leconvert_uint64_from(uint64_t little);
float tf_leconvert_float_from(float little);

#ifdef __cplusplus
}
#endif

#endif
