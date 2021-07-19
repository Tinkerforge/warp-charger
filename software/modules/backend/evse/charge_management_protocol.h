#include <stdint.h>

#include "Arduino.h"

#include "lwip/err.h"
#include "lwip/sockets.h"
#include "lwip/sys.h"
#include <lwip/netdb.h>

#define CHARGE_MANAGER_PORT 34127
#define CHARGE_MANAGEMENT_PORT CHARGE_MANAGER_PORT + 1

// 4 byte
struct packet_header {
    uint8_t seq_num;
    uint8_t version[3];
} __attribute__ ((packed));

// 4+2=6 byte
struct request_packet {
    packet_header header;

    uint16_t allocated_current;
} __attribute__ ((packed));

// 4+10=14 byte
struct response_packet {
    packet_header header;

    uint8_t iec61851_state;
    uint8_t vehicle_state;
    uint8_t error_state;
    uint8_t charge_release;
    uint32_t uptime;
    uint16_t allowed_charging_current;
} __attribute__ ((packed));


int create_socket(bool manager);
