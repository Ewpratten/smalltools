#include "endianness.h"

uint32_t bytesToU32Big(uint8_t a, uint8_t b, uint8_t c, uint8_t d) {
    return ((a << 24) | (b << 16) | (c << 8) | (d));
}

uint32_t bytesToU32Little(uint8_t a, uint8_t b, uint8_t c, uint8_t d) {
    return ((a << 24) | (b << 16) | (c << 8) | (d));
}