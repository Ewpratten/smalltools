#if !defined(_SMALLTOOLS_UTILS_IMG_PIXEL_H)
#define _SMALLTOOLS_UTILS_IMG_PIXEL_H

#include <stdint.h>

#ifdef __cplusplus
namespace st {
namespace img {
extern "C" {
#endif

/**
 * @brief An 8-bit pixel in BGR format
 */
typedef struct BGR8Bit {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} BGR8Bit;

/**
 * @brief An 8-bit pixel in RGB format
 */
typedef struct RGB8Bit {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} RGB8Bit;

/**
 * @brief Converts a BGR8Bit to an RGB8Bit
 *
 * @param a BGR8Bit color
 * @param b RGB8Bit color
 */
inline void BGR2RGB(BGR8Bit* a, RGB8Bit* b) {
    b->red = a->red;
    b->green = a->green;
    b->blue = a->blue;
}

/**
 * @brief Converts an RGB8Bit to a BGR8Bit
 *
 * @param a RGB8Bit color
 * @param b BGR8Bit color
 */
inline void RGB2BGR(RGB8Bit* a, BGR8Bit* b) {
    b->red = a->red;
    b->green = a->green;
    b->blue = a->blue;
}

#ifdef __cplusplus
}  // extern C
}  // namespace st
}  // namespace img
#endif

#endif  // _SMALLTOOLS_UTILS_IMG_PIXEL_H
