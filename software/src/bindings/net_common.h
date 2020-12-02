#ifndef TF_NET_COMMON_H
#define TF_NET_COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "net_config.h"

#include "macros.h"
#include "packetbuffer.h"

#include "tfp_header.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct TF_NetContext TF_NetContext;

int tf_net_tick(TF_NetContext *net);
bool tf_net_get_available_packet_header(TF_NetContext *net, TF_TfpHeader *header, int *packet_id);
int tf_net_get_packet(TF_NetContext *net, uint8_t packet_id, uint8_t *buf);
int tf_net_drop_packet(TF_NetContext *net, uint8_t packet_id);
void tf_net_send_packet(TF_NetContext *net, TF_TfpHeader *header, uint8_t *buf);

#ifdef __cplusplus
}
#endif

#endif
