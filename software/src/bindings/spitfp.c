/*
 * Copyright (C) 2020 Erik Fleckstein <erik@tinkerforge.com>
 *
 * Redistribution and use in source and binary forms of this file,
 * with or without modification, are permitted. See the Creative
 * Commons Zero (CC0 1.0) License for more details.
 */

#include "spitfp.h"

#include <stddef.h>
#include <string.h>
#include <stdio.h>

#include "macros.h"
#include "tfp.h"
#include "pearson_hash.h"
#include "errors.h"

#include "hal_common.h"

#define STATE_IDLE 0
#define STATE_TRANSCEIVE 1
#define STATE_WAIT_FOR_ACK 2
#define STATE_RECEIVE 3
#define STATE_BUILD_ACK 4

static bool on_receive_packet(TF_SpiTfpContext *spitfp) {
    uint8_t packet_length;
    tf_packetbuffer_pop(&spitfp->recv_buf, &packet_length);

    uint8_t seq_nums;
    tf_packetbuffer_pop(&spitfp->recv_buf, &seq_nums);

    spitfp->last_sequence_number_seen = seq_nums & 0x0F;
    spitfp->last_sequence_number_acked = seq_nums >> 4;
    //TODO: Check that ack packets (seq num == 0) have length of 3

    tf_hal_log_debug("SPITFP packet received: length %d, seq_nums %x, last_seen now %d, last_acked now %d\n", packet_length, seq_nums, seq_nums & 0x0F, seq_nums >> 4);

    if (packet_length == TF_SPITFP_PROTOCOL_OVERHEAD) {
        // Signal, that we processed the packet, as it has no payload.
        tf_spitfp_packet_processed(spitfp);
    }

    return packet_length > TF_SPITFP_PROTOCOL_OVERHEAD;
}

void tf_spitfp_packet_processed(TF_SpiTfpContext *spitfp) {
    // The packet was processed, however the checksum byte is still in the buffer.
    // Remove it too.
    TF_Packetbuffer *buf = &(spitfp->recv_buf);
    tf_packetbuffer_remove(buf, 1);
}

static uint8_t bytes_to_recv(TF_SpiTfpContext *spitfp, uint8_t bytes_missing, uint8_t bytes_to_send) {
    uint8_t result = tf_packetbuffer_get_free(&spitfp->recv_buf);

    if(bytes_missing > 0) {
        if (bytes_to_send > 0) {
            // Send or receive the next packet.
            return MIN(MIN(result, bytes_missing), bytes_to_send);
        }
        else {
            // Receive the next packet
            return MIN(result, bytes_missing);
        }
    }

    if (bytes_to_send > 0) {
        // Send the next packet
        return MIN(result, bytes_to_send);
    }

    // Receive single bytes if we don't have any other information
    return MIN(result, 1);
}

static bool process_packets(TF_SpiTfpContext *spitfp, uint8_t *bytes_missing) {
    TF_Packetbuffer *buf = &(spitfp->recv_buf);
    if(bytes_missing != NULL)
        *bytes_missing = 0;

    while (!tf_packetbuffer_is_empty(buf)) {
        uint8_t packet_len;
        tf_packetbuffer_peek(buf, &packet_len);
        if (packet_len > TF_SPITFP_MAX_MESSAGE_LENGTH || (packet_len < TF_SPITFP_MIN_MESSAGE_LENGTH && packet_len != TF_SPITFP_PROTOCOL_OVERHEAD)) {
            //This can't be the start of a packet.
            if(packet_len != 0)
                ++spitfp->error_count_frame;
            tf_packetbuffer_remove(buf, 1);
            continue;
        }
        uint8_t used = tf_packetbuffer_get_used(buf);
        if (packet_len > tf_packetbuffer_get_used(buf)) {
            //This could be the start of a packet, but we don't have enough bytes received yet.
            if(bytes_missing != NULL)
                *bytes_missing = packet_len - used;
            return false;
        }

        uint8_t packet_checksum;
        tf_packetbuffer_peek_offset(buf, &packet_checksum, packet_len - 1);

        uint8_t real_checksum = 0;
        for (uint8_t i = 0; i < (packet_len - 1); ++i) {
            uint8_t byte;
            tf_packetbuffer_peek_offset(buf, &byte, i);
            TF_PEARSON(real_checksum, byte);
        }

        if (packet_checksum == real_checksum) {
            if(on_receive_packet(spitfp))
                return true;
        } else {
            // checksum was wrong, advance one byte
            tf_packetbuffer_remove(buf, 1);
            ++spitfp->error_count_checksum;
        }
    }
    return false;
}

static int tf_spitfp_transceive_buffer(TF_SpiTfpContext *spitfp, uint8_t *send_buffer, uint8_t send_buf_offset, uint8_t length) {
    uint8_t first_len, second_len;
    uint8_t *first_chunk, *second_chunk;
    tf_packetbuffer_free_array_view(&spitfp->recv_buf, length, &first_chunk, &first_len, &second_chunk, &second_len);

    int rc = tf_hal_chip_select(spitfp->hal, spitfp->port_id, true);
    if(rc != TF_E_OK)
        return rc;

    rc = tf_hal_transceive(spitfp->hal, spitfp->port_id, send_buffer + send_buf_offset, first_chunk, first_len);
    if(rc != TF_E_OK) {
        int ignored = tf_hal_chip_select(spitfp->hal, spitfp->port_id, false);
        (void)ignored;
        return rc;
    }

    if(second_chunk != NULL) {
        rc = tf_hal_transceive(spitfp->hal, spitfp->port_id, send_buffer + send_buf_offset + first_len, second_chunk, second_len);
        if(rc != TF_E_OK) {
            int ignored = tf_hal_chip_select(spitfp->hal, spitfp->port_id, false);
            (void)ignored;
            return rc;
        }
    }

    rc = tf_hal_chip_select(spitfp->hal, spitfp->port_id, false);
    return rc;
}

static int tf_spitfp_transceive(TF_SpiTfpContext *spitfp, uint8_t send_buf_offset, uint8_t length) {
    return tf_spitfp_transceive_buffer(spitfp, spitfp->send_buf, send_buf_offset, length);
}

static int tf_spitfp_receive(TF_SpiTfpContext *spitfp, uint8_t length) {
    TF_HalCommon *common = tf_hal_get_common(spitfp->hal);
    return tf_spitfp_transceive_buffer(spitfp, common->empty_buf, 0, length);
}

uint8_t tf_spitfp_build_packet(TF_SpiTfpContext *spitfp, bool retransmission) {
    uint8_t packet_length = spitfp->send_buf[TF_SPITFP_HEADER_LENGTH + TFP_HEADER_LENGTH_OFFSET] + TF_SPITFP_PROTOCOL_OVERHEAD;
    spitfp->send_buf[0] = packet_length;

    uint8_t seq_num;

    if (retransmission) {
        seq_num = spitfp->send_buf[1] & 0x0F;
    } else {
        if (spitfp->last_sequence_number_sent == 0x0F) {
            seq_num = 0x02;
        } else {
            seq_num = spitfp->last_sequence_number_sent + 1;
        }
        spitfp->last_sequence_number_sent = seq_num;
    }

    spitfp->send_buf[1] = seq_num | (uint8_t)(spitfp->last_sequence_number_seen << 4);

    uint8_t checksum = 0;
    for(uint8_t i = 0; i < packet_length - 1; ++i)
        TF_PEARSON(checksum, spitfp->send_buf[i]);

    spitfp->send_buf[packet_length - 1] = checksum;
    return seq_num;
}

#define TRANSCEIVE_PACKET_SENT 1
#define TRANSCEIVE_PACKET_RECEIVED 2
#define TRANSCEIVE_PACKET_ACKED 4
#define TRANSCEIVE_TIMEOUT 8

static int tf_spitfp_transceive_packet(TF_SpiTfpContext *spitfp, uint8_t bytes_to_send, uint8_t *send_buf_offset) {
    while(*send_buf_offset < bytes_to_send) {
        uint8_t bytes_missing;
        if(process_packets(spitfp, &bytes_missing))
            return TRANSCEIVE_PACKET_RECEIVED;

        uint8_t to_recv = bytes_to_recv(spitfp, bytes_missing, bytes_to_send);

        uint8_t bytes_to_transceive = MIN(bytes_to_send, to_recv);

        int rc = tf_spitfp_transceive(spitfp, *send_buf_offset, bytes_to_transceive);
        if(rc != TF_E_OK)
            return rc;
        *send_buf_offset += bytes_to_transceive;
    }
    return TRANSCEIVE_PACKET_SENT | (process_packets(spitfp, NULL) ? TRANSCEIVE_PACKET_RECEIVED : 0);
}

static void tf_spitfp_build_ack(TF_SpiTfpContext *spitfp) {
    uint8_t packet_length = TF_SPITFP_PROTOCOL_OVERHEAD;
    spitfp->send_buf[0] = packet_length;

    spitfp->send_buf[1] = (uint8_t)(spitfp->last_sequence_number_seen << 4);

    uint8_t checksum = 0;
    for(uint8_t i = 0; i < packet_length - 1; ++i)
        TF_PEARSON(checksum, spitfp->send_buf[i]);

    spitfp->send_buf[packet_length - 1] = checksum;
}

#define RECEIVE_PACKET_RECIEVED 1
#define RECEIVE_PACKET_TIMEOUT 2
static int tf_spitfp_receive_packet(TF_SpiTfpContext *spitfp) {
    uint8_t bytes_missing;
    if(process_packets(spitfp, &bytes_missing))
        return true;

    uint8_t bytes_received = 0;
    do {
        uint8_t to_recv = bytes_to_recv(spitfp, bytes_missing, 0);

        int rc = tf_spitfp_receive(spitfp, to_recv);
        if(rc != TF_E_OK)
            return rc;
        bytes_received += to_recv;
        if(process_packets(spitfp, &bytes_missing))
            return RECEIVE_PACKET_RECIEVED;
    // Allow receiving two complete packets in case the first has a bitflip etc.
    // Immediately abort if the device has no data available.
    } while(bytes_received < 2 * TF_SPITFP_MAX_MESSAGE_LENGTH && bytes_missing > 0);

    return bytes_missing > 0 ? RECEIVE_PACKET_TIMEOUT : 0;
}

static int tf_spitfp_wait_for_ack(TF_SpiTfpContext *spitfp, uint8_t seq_num, uint32_t deadline_us) {
    uint8_t bytes_missing;

    bool packet_received = process_packets(spitfp, &bytes_missing);
    int result = 0;

    if (packet_received)
        result |= TRANSCEIVE_PACKET_RECEIVED;

    // We cant miss any packet here, as only one packet can be "in flight".
    // If process_packets finds multiple packets, they are retransmissions of the same packet.
    // I.e. they acknowledge the same packet
    if(spitfp->last_sequence_number_acked == seq_num)
        result |= TRANSCEIVE_PACKET_ACKED;

    if(result != 0)
        return result;

    do {
        uint8_t to_recv = bytes_to_recv(spitfp, bytes_missing, 0);
        result = tf_spitfp_receive(spitfp, to_recv);
        if(result < 0)
            return result;

        packet_received = process_packets(spitfp, &bytes_missing);


        if (packet_received)
            result |= TRANSCEIVE_PACKET_RECEIVED;

        // We cant miss any packet here, as only one packet can be "in flight".
        // If process_packets finds multiple packets, they are retransmissions of the same packet.
        // I.e. they acknowledge the same packet
        if(spitfp->last_sequence_number_acked == seq_num)
            result |= TRANSCEIVE_PACKET_ACKED;

        if(result != 0)
            return result;
    } while(!tf_hal_deadline_elapsed(spitfp->hal, deadline_us) && bytes_missing > 0);

    return tf_hal_deadline_elapsed(spitfp->hal, deadline_us) ? TRANSCEIVE_TIMEOUT : 0;
}

static int tf_spitfp_filter_duplicates(TF_SpiTfpContext *spitfp) {
    if(spitfp->last_sequence_number_given_to_tfp == spitfp->last_sequence_number_seen) {
        uint8_t packet_len = 0;
        tf_packetbuffer_peek_offset(&spitfp->recv_buf, &packet_len, TFP_HEADER_LENGTH_OFFSET);
        tf_packetbuffer_remove(&spitfp->recv_buf, packet_len + 1);
        return 0;
    }
    spitfp->last_sequence_number_given_to_tfp = spitfp->last_sequence_number_seen;
    return TF_TICK_PACKET_RECEIVED;
}

// See: dot -Tpng spitfp_tick.dot -o spitfp_tick.png && xdg-open spitfp_tick.png
int tf_spitfp_tick(TF_SpiTfpContext *spitfp, uint32_t deadline_us) {
    TF_SpiTfpStateMachine *m = &spitfp->state;

    switch (m->state) {
        case STATE_IDLE: {
            //TODO: Should there be more checks here, so that only valid packets are sent?
            uint8_t bytes_to_send = spitfp->send_buf[0];
            m->deadline_us = deadline_us;

            if (bytes_to_send != 0) {
                m->state = STATE_TRANSCEIVE;
                tf_hal_log_debug("->TRANSCEIVE\n");

                m->info.transceive.seq_num_to_send = spitfp->send_buf[1] & 0x0F;
                m->info.transceive.packet_received = false;
                m->info.transceive.bytes_to_send = bytes_to_send;
                m->info.transceive.send_buf_offset = 0;
            } else {
                m->state = STATE_RECEIVE;
                tf_hal_log_debug("->RECEIVE\n");
            }

            return TF_TICK_AGAIN;
        }

        case STATE_TRANSCEIVE: {
            uint8_t seq_num = m->info.transceive.seq_num_to_send;
            int result = tf_spitfp_transceive_packet(spitfp,  m->info.transceive.bytes_to_send, & m->info.transceive.send_buf_offset);
            if(result < 0)
                return result;

            if ( (result & TRANSCEIVE_PACKET_SENT)
                && (result & TRANSCEIVE_PACKET_RECEIVED)) {
                m->state = STATE_WAIT_FOR_ACK;
                tf_hal_log_debug("->WAIT_FOR_ACK\n");

                m->info.wait_for_ack.seq_num = seq_num;
                m->info.wait_for_ack.packet_received = true;
                m->info.wait_for_ack.inner_deadline_us = MIN(m->deadline_us, tf_hal_current_time_us(spitfp->hal) + 5000);

                return TF_TICK_AGAIN | tf_spitfp_filter_duplicates(spitfp);
            }

            if (result & TRANSCEIVE_PACKET_RECEIVED) {
                m->info.transceive.packet_received = true;
                return TF_TICK_AGAIN | tf_spitfp_filter_duplicates(spitfp);
            }

            if (result & TRANSCEIVE_PACKET_SENT) {
                bool packet_received = m->info.transceive.packet_received;

                m->state = STATE_WAIT_FOR_ACK;
                tf_hal_log_debug("->WAIT_FOR_ACK\n");

                m->info.wait_for_ack.seq_num = seq_num;
                m->info.wait_for_ack.packet_received = packet_received;
                m->info.wait_for_ack.inner_deadline_us = MIN(m->deadline_us, tf_hal_current_time_us(spitfp->hal) + 5000);

                return TF_TICK_AGAIN;
            }

            // unreachable
            break;
        }

        case STATE_WAIT_FOR_ACK: {
            //We don't have to wait for an ack if we send an ack
            if (m->info.wait_for_ack.seq_num == 0) {
                // clear packet length field to not send the ack again if ticked again
                spitfp->send_buf[0] = 0;
                tf_hal_log_debug("ACK sent\n");
                if (m->info.wait_for_ack.packet_received) {
                    m->state = STATE_BUILD_ACK;
                    tf_hal_log_debug("->BUILD_ACK\n");

                    return TF_TICK_AGAIN | tf_spitfp_filter_duplicates(spitfp);
                }
                else {
                    m->state = STATE_IDLE;
                    tf_hal_log_debug("->IDLE\n");

                    return 0;
                }
            }
            int result = tf_spitfp_wait_for_ack(spitfp, m->info.wait_for_ack.seq_num, m->info.wait_for_ack.inner_deadline_us);

            if ((result & TRANSCEIVE_PACKET_ACKED)
                && (result & TRANSCEIVE_PACKET_RECEIVED)) {
                m->state = STATE_BUILD_ACK;
                tf_hal_log_debug("->BUILD_ACK\n");


                return TF_TICK_AGAIN | TF_TICK_PACKET_SENT | tf_spitfp_filter_duplicates(spitfp);
            }

            // If we receive a packet that does not acknowledge our sent packet
            // this has been created before the bricklet has seen our packet
            // In this case we could wait until our or the bricklets timeout
            // triggers a resend that acks the opposite packet.
            // However it is faster if we just resend our packet immediately, thus acking
            // the bricklets packet.
            if (result & TRANSCEIVE_PACKET_RECEIVED) {
                m->state = STATE_IDLE;
                tf_hal_log_debug("->IDLE\n");

                return TF_TICK_AGAIN | TF_TICK_TIMEOUT | tf_spitfp_filter_duplicates(spitfp);
            }

            if (result & TRANSCEIVE_PACKET_ACKED) {
                if (m->info.wait_for_ack.packet_received) {

                    m->state = STATE_BUILD_ACK;
                    tf_hal_log_debug("->BUILD_ACK\n");

                    return TF_TICK_AGAIN | TF_TICK_PACKET_SENT | tf_spitfp_filter_duplicates(spitfp);
                }
                else {

                    m->state = STATE_IDLE;
                    tf_hal_log_debug("->IDLE\n");

                    return TF_TICK_PACKET_SENT;
                }
            }

            if (result & TRANSCEIVE_TIMEOUT) {
                m->state = STATE_IDLE;
                tf_hal_log_debug("->IDLE\n");

                return TF_TICK_TIMEOUT;
            }

            return TF_TICK_SLEEP | TF_TICK_AGAIN;
        }

        case STATE_RECEIVE: {
            int result = tf_spitfp_receive_packet(spitfp);
            if(result < 0)
                return result;

            if (result & RECEIVE_PACKET_RECIEVED) {
                m->state = STATE_BUILD_ACK;
                tf_hal_log_debug("->BUILD_ACK\n");

                return TF_TICK_AGAIN | tf_spitfp_filter_duplicates(spitfp);
            }

            m->state = STATE_IDLE;
            tf_hal_log_debug("->IDLE\n");
            return (result & RECEIVE_PACKET_TIMEOUT )? TF_TICK_TIMEOUT : TF_TICK_SLEEP;
        }

        case STATE_BUILD_ACK: {
            tf_spitfp_build_ack(spitfp);
            m->state = STATE_TRANSCEIVE;
            tf_hal_log_debug("->TRANSCEIVE\n");
            m->info.transceive.seq_num_to_send = 0;
            m->info.transceive.packet_received = false;
            m->info.transceive.send_buf_offset = 0;
            m->info.transceive.bytes_to_send = TF_SPITFP_PROTOCOL_OVERHEAD;

            return TF_TICK_AGAIN;
        }
    }

    // unreachable
    return 0;
}

uint8_t *tf_spitfp_get_payload_buffer(TF_SpiTfpContext *spitfp) {
    // Leave space for spitfp protocol header
    return spitfp->send_buf + TF_SPITFP_HEADER_LENGTH;
}

int tf_spitfp_init(TF_SpiTfpContext *spitfp, struct TF_HalContext *hal, uint8_t port_id) {
    spitfp->hal = hal;
    spitfp->port_id = port_id;
    spitfp->last_sequence_number_seen = 0;
    spitfp->last_sequence_number_acked = 0;
    spitfp->last_sequence_number_sent = 0;
    spitfp->last_sequence_number_given_to_tfp = 0;
    spitfp->state.deadline_us = 0;
    spitfp->state.state = STATE_IDLE;
    spitfp->error_count_checksum = 0;
    spitfp->error_count_frame = 0;

    memset(spitfp->send_buf, 0, sizeof(spitfp->send_buf));
    tf_packetbuffer_init(&spitfp->recv_buf);

    return TF_E_OK;
}

int tf_spitfp_destroy(TF_SpiTfpContext *spitfp){
    (void)spitfp;
    return TF_E_OK;
}
