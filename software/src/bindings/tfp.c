/*
 * Copyright (C) 2020 Erik Fleckstein <erik@tinkerforge.com>
 *
 * Redistribution and use in source and binary forms of this file,
 * with or without modification, are permitted. See the Creative
 * Commons Zero (CC0 1.0) License for more details.
 */

#include "tfp.h"

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

#include "endian_convert.h"
#include "packetbuffer.h"
#include "hal_common.h"
#include "errors.h"

// Time in µs to sleep if there is no data available
#define TF_TFP_SLEEP_TIME_US 250

static uint8_t tf_tfp_build_header(TF_TfpContext *tfp, uint8_t *header_buf, uint8_t length, uint8_t function_id, bool response_expected) {
    TF_TfpHeader header = {0};

	uint8_t sequence_number = tfp->next_sequence_number & 0x0F;
    if (sequence_number == 0) {
        sequence_number = 1;
    }
    tfp->next_sequence_number = sequence_number + 1;

	header.uid = tfp->uid;
    header.length = length;
    header.fid = function_id;
    header.seq_num = sequence_number;
    header.response_expected = response_expected;

    write_packet_header(&header, header_buf);

    return sequence_number;
}

static bool tf_tfp_dispatch_packet(TF_TfpContext *tfp, TF_TfpHeader *header, TF_Packetbuffer *packet) {
    TF_HalContext *hal = (TF_HalContext *)tfp->hal;
    TF_HalCommon *common = tf_hal_get_common(hal);

    if(common->net != NULL) {
        // The network layer expects a complete copy of the TFP packet (i.e. with header),
        // however we've already removed the header. Write it back here.
        uint8_t net_buf[TF_TFP_MESSAGE_MAX_LENGTH] = {0};
        write_packet_header(header, net_buf);
        tf_packetbuffer_peek_offset_n(packet, net_buf + 8, header->length - 8, 0);

        // Patch "position" of enumerate and get_identity packets
        // if "connected_uid" is just a null-terminator
        // I.e. the device is attached to us directly
        if ((header->fid == 253 || header->fid == 255) && net_buf[TF_TFP_MESSAGE_MIN_LENGTH + sizeof(char) * 8] == 0) {
            net_buf[TF_TFP_MESSAGE_MIN_LENGTH + sizeof(char) * 16] = tf_hal_get_port_name(hal, tfp->spitfp->port_id);
            net_buf[TF_TFP_MESSAGE_MIN_LENGTH + sizeof(char) * 8] = '0';
            net_buf[TF_TFP_MESSAGE_MIN_LENGTH + sizeof(char) * 9] = '\0';
        }

        tf_net_send_packet(common->net, header, net_buf);
    }

    // We received a non-callback packet that was not expected from the source TFP context.
    // As all getter and setter calls of the uC bindings (i.e. of other TFP contexts) are blocking,
    // we know immediately that the packet is only for the network layer, or is a late response to
    // a timed out request.
    if(header->seq_num != 0) {
        tf_packetbuffer_remove(packet, header->length - 8);
        return true;
    }

    // Handle enumerations
    if(header->fid == 253) {
        return tf_hal_enumerate_handler(hal, tfp->spitfp->port_id, packet);
    }

    // Search tfp context for the received callback
    TF_TfpContext *other_tfp = NULL;
    bool other_tfp_found = false;
    for(uint8_t i = 0; i < common->used; ++i) {
        if(common->uids[i] == header->uid) {
            other_tfp_found = true;
            other_tfp = &common->tfps[i];
            break;
        }
    }

    bool result = false;
    if(other_tfp_found) {
        result = other_tfp->cb_handler(other_tfp->device, header->fid, packet);
    }

    if(!result && common->net != NULL) {
        // We didn't find another tfp context or it had no handler registered to this callback.
        // However we dispatched the callback to the network.
        // Remove the packet and report success.
        tf_packetbuffer_remove(packet, header->length - 8);
        return true;
    }
    return result;
}

static bool tf_tfp_filter_received_packet(TF_TfpContext *tfp, bool remove_interesting, uint8_t *error_code) {
    TF_Packetbuffer *buf = &tfp->spitfp->recv_buf;

    uint8_t used = tf_packetbuffer_get_used(buf);

    if(used < 8) {
        tf_hal_log_debug("Too short!\n");
        tf_packetbuffer_remove(buf, used);
        //tf_tfp_packet_processed(tfp);
        ++tfp->error_count_frame;
        return false;
    }

    TF_TfpHeader header;
    read_packet_header(buf, &header);

    // Compare with <= as behind the tfp packet there has to be the SPITFP checksum
    if(used <= header.length) {
        tf_hal_log_debug("Too short! used (%d) < header.length (%d)\n", used, header.length);
        tf_packetbuffer_remove(buf, used);
        ++tfp->error_count_frame;
        return false;
    }

    bool packet_uninteresting = (tfp->waiting_for_fid == 0) // we could do this before parsing the header, but in this order it's possible to remove the unwanted packet from the buffer.
        || (tfp->uid != 0 && header.uid != tfp->uid)
        || (header.fid != tfp->waiting_for_fid)
        || (header.length != tfp->waiting_for_length)
        || (header.seq_num != tfp->waiting_for_sequence_number);

    if (packet_uninteresting) {
        if(!tf_tfp_dispatch_packet(tfp, &header, buf)) {
            tf_hal_log_debug("Remove unexpected\n");

            if (tfp->waiting_for_fid == 0) {
                tf_hal_log_debug("tfp->waiting_for_fid == 0\n");
            }
            if (tfp->uid != 0 && header.uid != tfp->uid) {
                tf_hal_log_debug("tfp->uid != 0 && header.uid (%d) != tfp->uid (%d)\n", header.uid, tfp->uid);
            }
            if (header.fid != tfp->waiting_for_fid) {
                tf_hal_log_debug("header.fid (%d) != tfp->waiting_for_fid (%d)\n", header.fid, tfp->waiting_for_fid);
            }
            if (header.length != tfp->waiting_for_length) {
                tf_hal_log_debug("header.length (%d) != tfp->waiting_for_length (%d)\n", header.length, tfp->waiting_for_length);
            }
            if (header.seq_num != tfp->waiting_for_sequence_number) {
                tf_hal_log_debug("header.seq_num (%d) != tfp->waiting_for_sequence_number (%d)\n", header.seq_num, tfp->waiting_for_sequence_number);
            }
            tf_packetbuffer_remove(buf, header.length);
            ++tfp->error_count_unexpected;
        }
        tf_tfp_packet_processed(tfp);
        return false;
    }

    if(remove_interesting) {
        tf_hal_log_debug("Remove interesting\n");
        tf_packetbuffer_remove(buf, header.length);
        tf_tfp_packet_processed(tfp);
        ++tfp->error_count_unexpected;
        return false;
    }

    *error_code = header.error_code;
    return true;
}

void tf_tfp_packet_processed(TF_TfpContext *tfp) {
    tf_spitfp_packet_processed(tfp->spitfp);
}

static bool empty_cb_handler(void *device, uint8_t fid, TF_Packetbuffer *payload) {
    (void) device;
    (void) fid;
    (void) payload;
    return false;
}

int tf_tfp_init(TF_TfpContext *tfp, TF_HalContext *hal, uint8_t port_id) {
    memset(tfp, 0, sizeof(TF_TfpContext));
    TF_PortCommon *port_common = tf_hal_get_port_common(hal, port_id);
    tfp->spitfp = &port_common->spitfp;

    /*int rc = tf_spitfp_init(tfp->spitfp, hal, port_id);
    if (rc != TF_E_OK)
        return rc;*/

    tfp->next_sequence_number = 1;
    //tfp->uid = uid;
    tfp->uid = 0;
    tfp->cb_handler = empty_cb_handler;
    tfp->error_count_frame = 0;
    tfp->error_count_unexpected = 0;
    tfp->needs_callback_tick = true;
    tfp->hal = hal;

    return TF_E_OK;
}

int tf_tfp_destroy(TF_TfpContext *tfp) {
    TF_HalCommon *common = tf_hal_get_common((TF_HalContext *)tfp->hal);

    uint8_t port_id;
    int inventory_index;
    int rc = tf_hal_get_port_id((TF_HalContext *)tfp->hal, tfp->uid, &port_id, &inventory_index);
    if (rc < 0) {
        return rc;
    }

    if(&common->tfps[inventory_index] != tfp)
        return TF_E_DEVICE_NOT_FOUND;

    common->tfps[inventory_index].device = NULL;

    return tf_spitfp_destroy(tfp->spitfp);
}

void tf_tfp_prepare_send(TF_TfpContext *tfp, uint8_t fid, uint8_t payload_size, uint8_t response_size, bool response_expected) {
    //TODO: theoretically, all bytes should be rewritten when sending a new packet, so this is not necessary.
    uint8_t *buf = tf_spitfp_get_payload_buffer(tfp->spitfp);
    memset(buf, 0, TF_TFP_MESSAGE_MAX_LENGTH);

    uint8_t tf_tfp_seq_num = tf_tfp_build_header(tfp, buf, payload_size + TF_TFP_MESSAGE_MIN_LENGTH, fid, response_expected);

    if (response_expected) {
        tfp->waiting_for_fid = fid;
        tfp->waiting_for_length = response_size + TF_TFP_MESSAGE_MIN_LENGTH;
        tfp->waiting_for_sequence_number = tf_tfp_seq_num;
    } else {
        tfp->waiting_for_fid = 0;
        tfp->waiting_for_length = 0;
        tfp->waiting_for_sequence_number = 0;
    }
}

uint8_t *tf_tfp_get_payload_buffer(TF_TfpContext *tfp) {
    return tf_spitfp_get_payload_buffer(tfp->spitfp) + TF_TFP_MESSAGE_MIN_LENGTH;
}

void tf_tfp_inject_packet(TF_TfpContext *tfp, TF_TfpHeader *header, uint8_t *packet) {
    uint8_t *buf = tf_spitfp_get_payload_buffer(tfp->spitfp);
    memset(buf, 0, TF_TFP_MESSAGE_MAX_LENGTH);

    memcpy(buf, packet, header->length);

    tfp->waiting_for_fid = 0;
    tfp->waiting_for_length = 0;
    tfp->waiting_for_sequence_number = 0;
    return;
}

static int tf_tfp_transmit_getter(TF_TfpContext *tfp, uint32_t deadline_us, uint8_t *error_code) {
    tf_spitfp_build_packet(tfp->spitfp, false);

    int result = TF_TICK_AGAIN;

    bool packet_received = false;

    uint32_t last_send = tf_hal_current_time_us((TF_HalContext *)tfp->hal);


    while(!tf_hal_deadline_elapsed((TF_HalContext *)tfp->hal, deadline_us) && !packet_received) {
        if (result & TF_TICK_TIMEOUT && tf_hal_deadline_elapsed((TF_HalContext *)tfp->hal, last_send + 5000)) {
            last_send = tf_hal_current_time_us((TF_HalContext *)tfp->hal);
            tf_spitfp_build_packet(tfp->spitfp, true);
        }

        result = tf_spitfp_tick(tfp->spitfp, deadline_us);
        if(result < 0)
            return result;

        if (result & TF_TICK_PACKET_RECEIVED) {
            if (tf_tfp_filter_received_packet(tfp, false, error_code)) {
                tfp->waiting_for_fid = 0;
                tfp->waiting_for_length = 0;
                tfp->waiting_for_sequence_number = 0;
                packet_received = true;
            }
        }
        if (result & TF_TICK_SLEEP) {
            tf_hal_sleep_us((TF_HalContext *)tfp->hal, TF_TFP_SLEEP_TIME_US);
        }
    }

    return (packet_received ? TF_TICK_PACKET_RECEIVED : TF_TICK_TIMEOUT) | (result & TF_TICK_AGAIN);
}

static int tf_tfp_transmit_setter(TF_TfpContext *tfp, uint32_t deadline_us) {
    tf_spitfp_build_packet(tfp->spitfp, false);

    int result = TF_TICK_AGAIN;
    bool packet_sent = false;

    while(!tf_hal_deadline_elapsed((TF_HalContext *)tfp->hal, deadline_us) && !packet_sent) {
        if (result & TF_TICK_TIMEOUT)
            tf_spitfp_build_packet(tfp->spitfp, true);

        result = tf_spitfp_tick(tfp->spitfp, deadline_us);
        if(result < 0)
            return result;

        if (result & TF_TICK_PACKET_RECEIVED) {
            uint8_t error_code;
            tf_tfp_filter_received_packet(tfp, true, &error_code);
        }

        if (result & TF_TICK_PACKET_SENT) {
            packet_sent = true;
        }

        if (result & TF_TICK_SLEEP) {
            tf_hal_sleep_us((TF_HalContext *)tfp->hal, TF_TFP_SLEEP_TIME_US);
        }
    }

    return (packet_sent ? TF_TICK_PACKET_SENT : TF_TICK_TIMEOUT) | (result & TF_TICK_AGAIN);
}


int tf_tfp_transmit_packet(TF_TfpContext *tfp, bool response_expected, uint32_t deadline_us, uint8_t *error_code) {
    return response_expected ? tf_tfp_transmit_getter(tfp, deadline_us, error_code) : tf_tfp_transmit_setter(tfp, deadline_us);
}

int tf_tfp_finish_send(TF_TfpContext *tfp, int previous_result, uint32_t deadline_us) {
    int result = previous_result;

    while(!tf_hal_deadline_elapsed((TF_HalContext *)tfp->hal, deadline_us) && (result & TF_TICK_AGAIN)) {
        result = tf_spitfp_tick(tfp->spitfp, deadline_us);
        if(result < 0)
            return result;
    }

    // Prevent sending the packet again for example in the callback_tick
    tfp->spitfp->send_buf[0] = 0;

    return (result & TF_TICK_AGAIN) ? -1 : 0;
}

int tf_tfp_get_error(uint8_t error_code) {
    switch(error_code) {
        case 1:
            return TF_E_INVALID_PARAMETER;
        case 2:
            return TF_E_NOT_SUPPORTED;
        case 3:
            return TF_E_UNKNOWN_ERROR_CODE;
        case 0:
        default:
            return TF_E_OK;
    }
}

int tf_tfp_callback_tick(TF_TfpContext *tfp, uint32_t deadline_us) {
    int result = TF_TICK_AGAIN;

    if(tfp->spitfp->send_buf[0] != 0) {
        tf_spitfp_build_packet(tfp->spitfp, true);
    }

    do {
        if (result & TF_TICK_SLEEP) {
            tf_hal_sleep_us((TF_HalContext *)tfp->hal, TF_TFP_SLEEP_TIME_US);
        }
        result = tf_spitfp_tick(tfp->spitfp, deadline_us);
        if(result < 0)
            return result;
        if (result & TF_TICK_PACKET_RECEIVED) {
            //handle possible callback packet
            uint8_t error_code;
            tf_tfp_filter_received_packet(tfp, false, &error_code);
        }
        if (result & TF_TICK_PACKET_SENT) {
            tfp->spitfp->send_buf[0] = 0;
        }

    // Allow the state machine to run a bit over the deadline:
    // Result will in the worst case not contain TICK_AGAIN when
    // the state machine has just transmitted an ACK. The then
    // received 3 bytes should not contain a complete packet.
    // (Except an ACK that has not be acked again).
    } while(!tf_hal_deadline_elapsed((TF_HalContext *)tfp->hal, deadline_us) || (result & TF_TICK_AGAIN));
    return TF_E_OK;
}
