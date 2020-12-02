/*
 * Copyright (C) 2020 Erik Fleckstein <erik@tinkerforge.com>
 *
 * Redistribution and use in source and binary forms of this file,
 * with or without modification, are permitted. See the Creative
 * Commons Zero (CC0 1.0) License for more details.
 */

#include "base58.h"

#include "errors.h"

static const char BASE58_ALPHABET[] = \
	"123456789abcdefghijkmnopqrstuvwxyzABCDEFGHJKLMNPQRSTUVWXYZ";

#define TF_BASE58_MAX_STR_SIZE 7

void tf_base58_encode(uint32_t value, char *str) {
	uint32_t mod;
	char reverse_str[TF_BASE58_MAX_STR_SIZE] = {'\0'};
	size_t i = 0;
	size_t k = 0;

	while (value >= 58) {
		mod = value % 58;
		reverse_str[i] = BASE58_ALPHABET[mod];
		value = value / 58;
		++i;
	}

	reverse_str[i] = BASE58_ALPHABET[value];

	for (k = 0; k <= i; k++) {
		str[k] = reverse_str[i - k];
	}

	for (; k < TF_BASE58_MAX_STR_SIZE; k++) {
		str[k] = '\0';
	}
}

// https://www.fefe.de/intof.html
static bool uint32_add(uint32_t a, uint32_t b, uint32_t *c) {
	if (UINT32_MAX - a < b) {
		return false;
	}

	*c = a + b;

	return true;
}

static bool uint32_multiply(uint32_t a, uint32_t b, uint32_t *c) {
	uint32_t a0 = a & UINT16_MAX;
	uint32_t a1 = a >> 16;
	uint32_t b0 = b & UINT16_MAX;
	uint32_t b1 = b >> 16;
	uint32_t c0;
	uint32_t c1;

	if (a1 > 0 && b1 > 0) {
		return false;
	}

	c1 = a1 * b0 + a0 * b1;

	if (c1 > UINT16_MAX) {
		return false;
	}

	c0 = a0 * b0;
	c1 <<= 16;

	return uint32_add(c1, c0, c);
}

int tf_base58_decode(const char *str, uint32_t *ret_value) {
    size_t len = strlen(str);
    if (len > 6)
        return TF_E_UID_TOO_LONG;

    int i = (int)len - 1;
    uint8_t k;
	uint32_t next;
	uint32_t value = 0;
	uint32_t base = 1;

	*ret_value = 0;
    for (; i >= 0; --i) {
		for (k = 0; k < 58; ++k) {
			if (BASE58_ALPHABET[k] == str[i]) {
				break;
			}
		}

		if (k == 58) {
			return TF_E_INVALID_CHAR_IN_UID; // invalid char
		}

		if (!uint32_multiply(k, base, &next))  {
			return TF_E_UID_OVERFLOW; // overflow
		}

		if (!uint32_add(value, next, &value))  {
			return TF_E_UID_OVERFLOW; // overflow
		}

		if (i > 0 && !uint32_multiply(base, 58, &base))  {
			return TF_E_UID_OVERFLOW; // overflow
		}
	}
	*ret_value = value;

	return TF_E_OK;
}
