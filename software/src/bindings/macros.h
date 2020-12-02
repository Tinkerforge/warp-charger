/*
 * Copyright (C) 2020 Erik Fleckstein <erik@tinkerforge.com>
 *
 * Redistribution and use in source and binary forms of this file,
 * with or without modification, are permitted. See the Creative
 * Commons Zero (CC0 1.0) License for more details.
 */

#ifndef TF_MACROS_H
#define TF_MACROS_H

#include <stddef.h>

#ifdef __clang__
	#define TF_ATTRIBUTE_NONNULL(...) __attribute__((nonnull (__VA_ARGS__)))
    #define TF_ATTRIBUTE_NONNULL_ALL __attribute__((nonnull))
    #define TF_ATTRIBUTE_WARN_UNUSED_RESULT __attribute__ ((warn_unused_result))
    #define TF_ATTRIBUTE_FALLTHROUGH __attribute__((fallthrough))
#elif defined __GNUC__
	#ifndef __GNUC_PREREQ
		#define __GNUC_PREREQ(major, minor) ((((__GNUC__) << 16) + (__GNUC_MINOR__)) >= (((major) << 16) + (minor)))
	#endif
	#define TF_ATTRIBUTE_NONNULL(...) __attribute__((nonnull (__VA_ARGS__)))
    #define TF_ATTRIBUTE_NONNULL_ALL __attribute__((nonnull))
    #define TF_ATTRIBUTE_WARN_UNUSED_RESULT __attribute__ ((warn_unused_result))
    #if __GNUC_PREREQ(7, 0)
        #define TF_ATTRIBUTE_FALLTHROUGH __attribute__((fallthrough))
    #else
        // see https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-Wimplicit-fallthrough
        #define TF_ATTRIBUTE_FALLTHROUGH /* @fallthrough@ */
    #endif
#else
	#define TF_ATTRIBUTE_NONNULL(...)
    #define TF_ATTRIBUTE_NONNULL_ALL __attribute__((nonnull))
    #define TF_ATTRIBUTE_WARN_UNUSED_RESULT
#endif

#ifndef MIN
	#define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif
#ifndef MAX
	#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif

#define TF_TFP_MESSAGE_MIN_LENGTH 8
#define TF_TFP_MESSAGE_MAX_LENGTH 80

#define TF_SPITFP_HEADER_LENGTH 2 // Length, Sequence numbers
#define TF_SPITFP_FOOTER_LENGTH 1 // Checksum
#define TF_SPITFP_PROTOCOL_OVERHEAD (TF_SPITFP_HEADER_LENGTH + TF_SPITFP_FOOTER_LENGTH) // 3 byte overhead for Brick <-> Bricklet SPI protocol

#define TF_SPITFP_MIN_MESSAGE_LENGTH (TF_TFP_MESSAGE_MIN_LENGTH + TF_SPITFP_PROTOCOL_OVERHEAD)
#define TF_SPITFP_MAX_MESSAGE_LENGTH (TF_TFP_MESSAGE_MAX_LENGTH + TF_SPITFP_PROTOCOL_OVERHEAD)

#endif // TF_MACROS_H
