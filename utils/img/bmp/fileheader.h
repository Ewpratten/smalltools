#if !defined(_SMALLTOOLS_UTILS_IMG_BMP_FILEHEADER_H)
#define _SMALLTOOLS_UTILS_IMG_BMP_FILEHEADER_H

#include <stdint.h>

#ifdef __cplusplus
namespace st {
namespace img {
extern "C" {
#endif

/**
 * @brief Bitmap file header
 */
typedef struct BMPHeader {
    // file signature
    char signature[2];

    // File size
    uint32_t size;

    // # of reserved bytes
    uint32_t reserved;

    // Start of image data
    uint32_t data_offset;
} BMPHeader;

/**
 * @brief Bitmap file info data
 */
typedef struct BMPInfo {
    // Header size
    uint32_t size;

    // Image dimensions
    int32_t width;
    int32_t height;

    // Image settings
    uint16_t color_planes;
    uint16_t color_depth;
    uint32_t compression;
    uint32_t raw_size;

    // Resolution in pixels per meter
    int32_t horizontal_ppm;
    int32_t vertical_ppm;

    // Other settings
    uint32_t color_table;
    uint32_t important_colors;
} BMPInfo;

#ifdef __cplusplus
}  // extern C
}  // namespace st
}  // namespace img
#endif

#endif  // _SMALLTOOLS_UTILS_IMG_BMP_FILEHEADER_H
