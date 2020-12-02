#ifndef TF_NET_CONFIG_H
#define TF_NET_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

// This is the maximum number of open requests to keep track of in parallel.
// If this many requests are not fulfilled and another one is created by sending
// a packet with response_expected = true, the oldest request will be dropped.
// Note that this does not mean, that a later response to the dropped request will be
// dropped to: As only the mapping to where the request came from is missing, the response
// will be broadcasted to all connected clients.
// NEVER set this to a value larger than 255, as an uint8_t is used to index into the
// open request array.
#define TF_MAX_OPEN_REQUEST_COUNT 10

// This is the maximum number of clients connected in parallel.
// If this number is reached, no new clients can connect until
// one of the connected client closes their connection.
#define TF_MAX_CLIENT_COUNT 4

#ifdef __cplusplus
}
#endif

#endif
