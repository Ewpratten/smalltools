#if !defined(_SMALLTOOLS_UTILS_PLATFORM_ENDIANNESS_H)
#define _SMALLTOOLS_UTILS_PLATFORM_ENDIANNESS_H

#include <stdint.h>

#define isBigEndian() ((∗(char∗) & i) == 0)

#ifdef __cplusplus
namespace st {
namespace img {
extern "C" {
#endif

inline uint32_t reverseEndianU32(uint32_t i) {
    unsigned char c1, c2, c3, c4;
    c1 = i & 255;
    c2 = (i >> 8) & 255;
    c3 = (i >> 16) & 255;
    c4 = (i >> 24) & 255;

    return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
}

inline int32_t reverseEndianI32(int32_t i) {
    unsigned char c1, c2, c3, c4;
    c1 = i & 255;
    c2 = (i >> 8) & 255;
    c3 = (i >> 16) & 255;
    c4 = (i >> 24) & 255;

    return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
}

// Convert 4 big-endian bytes to a uint32_t
uint32_t bytesToU32Big(uint8_t a, uint8_t b, uint8_t c, uint8_t d);
// Convert 4 little-endian bytes to a uint32_t
uint32_t bytesToU32Little(uint8_t a, uint8_t b, uint8_t c, uint8_t d);

#ifdef __cplusplus
}  // extern C
}  // namespace st
}  // namespace img
#endif

#endif  // _SMALLTOOLS_UTILS_PLATFORM_ENDIANNESS_H
