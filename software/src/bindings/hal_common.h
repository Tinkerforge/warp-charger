/*
 * Copyright (C) 2020 Erik Fleckstein <erik@tinkerforge.com>
 *
 * Redistribution and use in source and binary forms of this file,
 * with or without modification, are permitted. See the Creative
 * Commons Zero (CC0 1.0) License for more details.
 */

#ifndef TF_HAL_COMMON_H
#define TF_HAL_COMMON_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>

#include "config.h"
#include "packetbuffer.h"
#include "macros.h"

#include "tfp_header.h"
#include "tfp.h"

#include "net_common.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct TF_PortCommon {
    TF_SpiTfpContext spitfp;
} TF_PortCommon;

typedef struct TF_HalCommon {
    //TF_INVENTORY_SIZE + 1 for the unknown bricklet used for device discovery
    uint32_t uids[TF_INVENTORY_SIZE + 1];
    uint8_t port_ids[TF_INVENTORY_SIZE + 1];
    TF_TfpContext tfps[TF_INVENTORY_SIZE + 1];
    uint16_t dids[TF_INVENTORY_SIZE + 1];
    bool send_enumerate_request[TF_INVENTORY_SIZE + 1];

    uint16_t used;
    uint8_t device_overflow_count;

    uint32_t timeout;

    bool locked;
    uint8_t port_count;
    size_t callback_tick_index;

    uint8_t empty_buf[TF_SPITFP_MAX_MESSAGE_LENGTH];

    TF_NetContext *net;
} TF_HalCommon;

typedef struct TF_HalContext TF_HalContext;

void tf_hal_set_timeout(TF_HalContext *hal, uint32_t timeout_us) TF_ATTRIBUTE_NONNULL_ALL;
uint32_t tf_hal_get_timeout(TF_HalContext *hal) TF_ATTRIBUTE_NONNULL_ALL;
int tf_hal_get_device_info(TF_HalContext *hal, size_t index, char ret_uid[7], char *ret_port_name, uint16_t *ret_device_id) TF_ATTRIBUTE_NONNULL(1);
int tf_hal_callback_tick(TF_HalContext *hal, uint32_t timeout_us) TF_ATTRIBUTE_NONNULL_ALL;
int tf_hal_tick(TF_HalContext *hal, uint32_t timeout_us) TF_ATTRIBUTE_NONNULL_ALL;

bool tf_hal_deadline_elapsed(TF_HalContext *hal, uint32_t deadline_us) TF_ATTRIBUTE_NONNULL_ALL;
int tf_hal_get_error_counters(TF_HalContext *hal, char port_name, uint32_t *ret_spitfp_error_count_checksum, uint32_t *ret_spitfp_error_count_frame, uint32_t *ret_tfp_error_count_frame, uint32_t *ret_tfp_error_count_unexpected) TF_ATTRIBUTE_NONNULL(1);
int tf_hal_get_tfp(TF_HalContext *hal, TF_TfpContext **tfp_ptr, uint16_t device_id, uint8_t inventory_index);

#define TF_LOG_LEVEL_NONE 0
#define TF_LOG_LEVEL_ERROR 1
#define TF_LOG_LEVEL_INFO 2
#define TF_LOG_LEVEL_DEBUG 3

#if TF_LOG_LEVEL >= TF_LOG_LEVEL_ERROR
#define tf_hal_log_error(...) tf_hal_printf(__VA_ARGS__)
#else
#define tf_hal_log_error(...)
#endif

#if TF_LOG_LEVEL >= TF_LOG_LEVEL_INFO
#define tf_hal_log_info(...) tf_hal_printf(__VA_ARGS__)
#else
#define tf_hal_log_info(...)
#endif

#if TF_LOG_LEVEL >= TF_LOG_LEVEL_DEBUG
#define tf_hal_log_debug(...) tf_hal_printf(__VA_ARGS__)
#else
#define tf_hal_log_debug(...)
#endif

// Very minimalistic printf: no zero-padding, grouping, l-modifier or similar and no float.
// Newlines (\n) are translated to the platform specific newline character(s).
// To print fixed width integer types use a I[width] prefix, for example %I16x to print
// an uint16_t as hex. Supported are I8, I16, I32 and I64.
// Note that the prefix only specifies the width of the integer, not it's signedness
// (i.e. use %I.. even if you want to print an unsigned integer).
// The signedness is communicated as usual with %[prefix]d or %[prefix]u.
void tf_hal_printf(const char *format, ...) TF_ATTRIBUTE_NONNULL_ALL;

// To be used by HAL implementations
int tf_hal_common_create(TF_HalContext *hal) TF_ATTRIBUTE_NONNULL_ALL TF_ATTRIBUTE_WARN_UNUSED_RESULT;
int tf_hal_common_prepare(TF_HalContext *hal, uint8_t port_count, uint32_t port_discovery_timeout_us) TF_ATTRIBUTE_NONNULL_ALL TF_ATTRIBUTE_WARN_UNUSED_RESULT;
int tf_hal_get_port_id(TF_HalContext *hal, uint32_t uid, uint8_t *port_id, int *inventory_index) TF_ATTRIBUTE_NONNULL_ALL TF_ATTRIBUTE_WARN_UNUSED_RESULT;
bool tf_hal_enumerate_handler(TF_HalContext *hal, uint8_t port_id, TF_Packetbuffer *payload) TF_ATTRIBUTE_NONNULL_ALL TF_ATTRIBUTE_WARN_UNUSED_RESULT;
void tf_hal_set_net(TF_HalContext *hal, TF_NetContext *net);

// BEGIN - To be implemented by the specific HAL
int tf_hal_chip_select(TF_HalContext *hal, uint8_t port_id, bool enable) TF_ATTRIBUTE_NONNULL_ALL TF_ATTRIBUTE_WARN_UNUSED_RESULT;
int tf_hal_transceive(TF_HalContext *hal, uint8_t port_id, const uint8_t *write_buffer, uint8_t *read_buffer, uint32_t length) TF_ATTRIBUTE_NONNULL_ALL TF_ATTRIBUTE_WARN_UNUSED_RESULT;
uint32_t tf_hal_current_time_us(TF_HalContext *hal) TF_ATTRIBUTE_NONNULL_ALL;
void tf_hal_sleep_us(TF_HalContext *hal, uint32_t us) TF_ATTRIBUTE_NONNULL_ALL;
TF_HalCommon *tf_hal_get_common(TF_HalContext *hal) TF_ATTRIBUTE_NONNULL_ALL;
char tf_hal_get_port_name(TF_HalContext *hal, uint8_t port_id) TF_ATTRIBUTE_NONNULL_ALL;
TF_PortCommon *tf_hal_get_port_common(TF_HalContext *hal, uint8_t port_id) TF_ATTRIBUTE_NONNULL_ALL;

// These functions have to work without an initialized HAL to be able to report HAL initialization info/errors, so don't pass the handle here.
void tf_hal_log_message(const char *msg, size_t len) TF_ATTRIBUTE_NONNULL_ALL;
void tf_hal_log_newline(void);

#ifdef TF_IMPLEMENT_STRERROR
const char *tf_hal_strerror(int e_code);
#endif

// END - To be implemented by the specific HAL

#ifdef __cplusplus
}
#endif

#endif
