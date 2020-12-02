#include "tfp_header.h"

#include <string.h>
#include <stdio.h>

#include "endian_convert.h"
#include "base58.h"

void parse_header(TF_TfpHeader *header) {
    header->response_expected = header->seq_num & 0x08;
    header->options = header->seq_num & 0x07;
    header->seq_num >>= 4;

    header->error_code = header->flags & 0xC0 >> 6;
    header->flags &= 0x3F;
}

void read_packet_header(TF_Packetbuffer *buf, TF_TfpHeader *header) {
    header->uid = tf_packetbuffer_read_uint32_t(buf);
    header->length = tf_packetbuffer_read_uint8_t(buf);
    header->fid = tf_packetbuffer_read_uint8_t(buf);
    header->seq_num = tf_packetbuffer_read_uint8_t(buf);
    header->flags = tf_packetbuffer_read_uint8_t(buf);

    parse_header(header);
}

void peek_packet_header(TF_Packetbuffer *buf, TF_TfpHeader *header) {
    header->uid = tf_packetbuffer_peek_uint32_t(buf, 0);
    header->length = tf_packetbuffer_peek_uint8_t(buf, 4);
    header->fid = tf_packetbuffer_peek_uint8_t(buf, 5);
    header->seq_num = tf_packetbuffer_peek_uint8_t(buf, 6);
    header->flags = tf_packetbuffer_peek_uint8_t(buf, 7);

    parse_header(header);
}

void peek_packet_header_plain_buf(uint8_t *buf, TF_TfpHeader *header) {
    uint32_t uid = 0;
    for(int i = 0; i < 4; ++i)
        *(((uint8_t *)&uid) + i) = buf[i];

    header->uid = tf_leconvert_uint32_from(uid);
    header->length = buf[4];
    header->fid = buf[5];
    header->seq_num = buf[6];
    header->flags = buf[7];

    parse_header(header);
}

void write_packet_header(TF_TfpHeader *header, uint8_t buf[8]) {
    uint32_t uid = tf_leconvert_uint32_to(header->uid);
    memcpy(buf, &uid, sizeof(uid));
    buf[4] = header->length;
    buf[5] = header->fid;
    buf[6] = (header->seq_num << 4) | ((header->response_expected ? 1 : 0) << 3) | header->options;
    buf[7] = header->error_code << 6 | header->flags;
}

void print_packet_header(TF_TfpHeader *header) {
    char buf[8] = {0};
    tf_base58_encode(header->uid, buf);
    printf("UID %s Len %u FID %u SeqNum %u RespExp %s Opt %u Err %u Flags %u\n", buf,
        header->length,
        header->fid,
        header->seq_num,
        header->response_expected ? "true" : "false",
        header->options,
        header->error_code,
        header->flags);
}
