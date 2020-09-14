#if !defined(_SMALLTOOLS_UTILS_IMG_BMP_IO_H)
#define _SMALLTOOLS_UTILS_IMG_BMP_IO_H

#include <stdint.h>
#include <stdio.h>

#include "../pixel.h"
#include "fileheader.h"

#ifdef __cplusplus
namespace st {
namespace img {
extern "C" {
#endif

/**
 * @brief Write a bitmap to a file
 *
 * @param header Bitmap header
 * @param info Bitmap info
 * @param data_ptr Pointer to the first pixel
 * @param data_len Number of pixels to write
 * @param stream Stream to write to
 * @return Number of objects written successfully. Will return data_len + 2 on
 * success
 */
int writeBitmap(BMPHeader* header, BMPInfo* info, BGR8Bit* data_ptr,
                size_t data_len, FILE* stream);

/**
 * @brief Get the length of a bitmap file's data portion in bytes
 *
 * @param stream Input stream
 * @return int Number of bytes
 */
int getBitmapDataLength(FILE* stream);

/**
 * @brief Read a bitmap from a file
 *
 * @param header Bitmap header
 * @param info Bitmap info
 * @param data_ptr Pointer to the first pixel
 * @param data_len Number of pixels to read
 * @param stream Stream to read from
 * @return Number of pixels read from the image
 */
size_t readBitmap(BMPHeader* header, BMPInfo* info, BGR8Bit* data_ptr,
                    size_t data_len, FILE* stream);

#ifdef __cplusplus
}  // extern C
}  // namespace st
}  // namespace img
#endif

#endif  // _SMALLTOOLS_UTILS_IMG_BMP_IO_H
