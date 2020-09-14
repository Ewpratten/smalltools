#if !defined(_SMALLTOOLS_UTILS_IMG_BMP_UTILS_H)
#define _SMALLTOOLS_UTILS_IMG_BMP_UTILS_H

#include <stdint.h>
#include <stdio.h>

#include "fileheader.h"

#ifdef __cplusplus
namespace st {
namespace img {
extern "C" {
#endif

/**
 * @brief Init a Bitmap
 *
 * @param header File header
 * @param info File info
 * @param size Image size
 * @param width Image width
 * @param height Image height
 */
void initBitmap(BMPHeader* header, BMPInfo* info, uint32_t size, int32_t width,
                int32_t height);

/**
 * @brief Destroy a bitmap
 *
 * @param header File header
 * @param info File info
 */
void destroyBitmap(BMPHeader* header, BMPInfo* info);

#ifdef __cplusplus
}  // extern C
}  // namespace st
}  // namespace img
#endif

#endif  // _SMALLTOOLS_UTILS_IMG_BMP_UTILS_H
