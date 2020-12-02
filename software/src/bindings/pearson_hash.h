/*
 * Copyright (C) 2020 Erik Fleckstein <erik@tinkerforge.com>
 *
 * Redistribution and use in source and binary forms of this file,
 * with or without modification, are permitted. See the Creative
 * Commons Zero (CC0 1.0) License for more details.
 */

#ifndef TF_PEARSON_HASH_H
#define TF_PEARSON_HASH_H

#include <stdint.h>

#define TF_PEARSON_PERMUTATION_SIZE 256

#ifdef __cplusplus
extern "C" {
#endif

extern const uint8_t tf_pearson_permutation[TF_PEARSON_PERMUTATION_SIZE];

#ifdef __cplusplus
}
#endif


#define TF_PEARSON(cur, next) do { cur = tf_pearson_permutation[cur ^ next]; } while(0)

#endif // DAEMONLIB_PEARSON_HASH_H
