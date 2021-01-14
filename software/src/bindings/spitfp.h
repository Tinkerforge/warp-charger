/*
 * Copyright (C) 2020 Erik Fleckstein <erik@tinkerforge.com>
 *
 * Redistribution and use in source and binary forms of this file,
 * with or without modification, are permitted. See the Creative
 * Commons Zero (CC0 1.0) License for more details.
 */

#ifndef TF_SPITFP_H
#define TF_SPITFP_H

#include <stdbool.h>
#include <stdint.h>

#include "packetbuffer.h"
#include "macros.h"



#ifdef __cplusplus
extern "C" {
#endif

typedef struct TF_SpiTfpStateMachine {
    uint32_t deadline_us;

    uint8_t state;

    union {
        struct { uint8_t _unused; } idle;

        struct {
            uint8_t seq_num_to_send;
            bool packet_received;
            uint8_t bytes_to_send;
            uint8_t send_buf_offset;
        } transceive;

        struct {
            uint32_t inner_deadline_us;
            uint8_t seq_num;
            bool packet_received;
        } wait_for_ack;

        struct { uint8_t _unused; } receive;

        struct { uint8_t _unused; } build_ack;
    } info;
} TF_SpiTfpStateMachine;

struct TF_HalContext;

typedef struct TF_SpiTfpContext {
    struct TF_HalContext *hal;

    uint8_t port_id;

    uint8_t last_sequence_number_seen;
    uint8_t last_sequence_number_acked;
    uint8_t last_sequence_number_sent;
    uint8_t last_sequence_number_given_to_tfp;

    uint32_t error_count_checksum;
    uint32_t error_count_frame;

    uint8_t send_buf[TF_SPITFP_MAX_MESSAGE_LENGTH];
    TF_Packetbuffer recv_buf;

    struct TF_SpiTfpStateMachine state;
} TF_SpiTfpContext;

int tf_spitfp_init(TF_SpiTfpContext *spitfp, struct TF_HalContext *hal, uint8_t port_id) TF_ATTRIBUTE_NONNULL_ALL TF_ATTRIBUTE_WARN_UNUSED_RESULT;
int tf_spitfp_destroy(TF_SpiTfpContext *spitfp) TF_ATTRIBUTE_NONNULL_ALL TF_ATTRIBUTE_WARN_UNUSED_RESULT;

uint8_t *tf_spitfp_get_payload_buffer(TF_SpiTfpContext *spitfp) TF_ATTRIBUTE_NONNULL_ALL;
uint8_t tf_spitfp_build_packet(TF_SpiTfpContext *spitfp, bool retransmission) TF_ATTRIBUTE_NONNULL_ALL;
void tf_spitfp_packet_processed(TF_SpiTfpContext *spitfp) TF_ATTRIBUTE_NONNULL_ALL;

#define TF_TICK_PACKET_RECEIVED 1
#define TF_TICK_PACKET_SENT 2
#define TF_TICK_AGAIN 4
#define TF_TICK_TIMEOUT 8
#define TF_TICK_SLEEP 16

int tf_spitfp_tick(TF_SpiTfpContext *spitfp, uint32_t deadline_us) TF_ATTRIBUTE_NONNULL_ALL TF_ATTRIBUTE_WARN_UNUSED_RESULT;

#ifdef __cplusplus
}
#endif

#endif
