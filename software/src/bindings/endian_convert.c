/*
 * Copyright (C) 2020 Erik Fleckstein <erik@tinkerforge.com>
 *
 * Redistribution and use in source and binary forms of this file,
 * with or without modification, are permitted. See the Creative
 * Commons Zero (CC0 1.0) License for more details.
 */

#include "endian_convert.h"

int16_t tf_leconvert_int16_to(int16_t native) {
	return (int16_t)tf_leconvert_uint16_to((uint16_t)native);
}

uint16_t tf_leconvert_uint16_to(uint16_t native) {
	union {
		uint8_t bytes[2];
		uint16_t little;
	} c;

	c.bytes[0] = (native >> 0) & 0xFF;
	c.bytes[1] = (native >> 8) & 0xFF;

	return c.little;
}

int32_t tf_leconvert_int32_to(int32_t native) {
	return (int32_t)tf_leconvert_uint32_to((uint32_t)native);
}

uint32_t tf_leconvert_uint32_to(uint32_t native) {
	union {
		uint8_t bytes[4];
		uint32_t little;
	} c;

	c.bytes[0] = (native >>  0) & 0xFF;
	c.bytes[1] = (native >>  8) & 0xFF;
	c.bytes[2] = (native >> 16) & 0xFF;
	c.bytes[3] = (native >> 24) & 0xFF;

	return c.little;
}

int64_t tf_leconvert_int64_to(int64_t native) {
	return (int64_t)tf_leconvert_uint64_to((uint64_t)native);
}

uint64_t tf_leconvert_uint64_to(uint64_t native) {
	union {
		uint8_t bytes[8];
		uint64_t little;
	} c;

	c.bytes[0] = (native >>  0) & 0xFF;
	c.bytes[1] = (native >>  8) & 0xFF;
	c.bytes[2] = (native >> 16) & 0xFF;
	c.bytes[3] = (native >> 24) & 0xFF;
	c.bytes[4] = (native >> 32) & 0xFF;
	c.bytes[5] = (native >> 40) & 0xFF;
	c.bytes[6] = (native >> 48) & 0xFF;
	c.bytes[7] = (native >> 56) & 0xFF;

	return c.little;
}

float tf_leconvert_float_to(float native) {
	union {
		uint32_t u;
		float f;
	} c;

	c.f = native;
	c.u = tf_leconvert_uint32_to(c.u);

	return c.f;
}

int16_t tf_leconvert_int16_from(int16_t little) {
	return (int16_t)tf_leconvert_uint16_from((uint16_t)little);
}

uint16_t tf_leconvert_uint16_from(uint16_t little) {
	uint8_t *bytes = (uint8_t *)&little;

	return ((uint16_t)((uint16_t)bytes[1] << 8)) |
	        (uint16_t)bytes[0];
}

int32_t tf_leconvert_int32_from(int32_t little) {
	return (int32_t)tf_leconvert_uint32_from((uint32_t)little);
}

uint32_t tf_leconvert_uint32_from(uint32_t little) {
	uint8_t *bytes = (uint8_t *)&little;

	return ((uint32_t)bytes[3] << 24) |
	       ((uint32_t)bytes[2] << 16) |
	       ((uint32_t)bytes[1] <<  8) |
	        (uint32_t)bytes[0];
}

int64_t tf_leconvert_int64_from(int64_t little) {
	return (int64_t)tf_leconvert_uint64_from((uint64_t)little);
}

uint64_t tf_leconvert_uint64_from(uint64_t little) {
	uint8_t *bytes = (uint8_t *)&little;

	return ((uint64_t)bytes[7] << 56) |
	       ((uint64_t)bytes[6] << 48) |
	       ((uint64_t)bytes[5] << 40) |
	       ((uint64_t)bytes[4] << 32) |
	       ((uint64_t)bytes[3] << 24) |
	       ((uint64_t)bytes[2] << 16) |
	       ((uint64_t)bytes[1] <<  8) |
	        (uint64_t)bytes[0];
}

float tf_leconvert_float_from(float little) {
	union {
		uint32_t u;
		float f;
	} c;

	c.f = little;
	c.u = tf_leconvert_uint32_from(c.u);

	return c.f;
}
