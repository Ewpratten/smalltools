#include "utils.h"

#include <stdlib.h>

void initBitmap(BMPHeader* header, BMPInfo* info, uint32_t size, int32_t width,
                int32_t height) {
    // Set the bitmap type. We use the BM type
    (*header).signature[0] = 'B';
    (*header).signature[1] = 'M';

    // Get the header sizes
    size_t header_size = sizeof_BMPHeader;
    size_t info_size = sizeof_BMPInfo;

    // Fill in the file size
    // This includes the pre-known header sizes
    (*header).size = (header_size + info_size) + size;
    (*header).reserved = 0;
    (*header).data_offset = (header_size + info_size);
    (*info).size = info_size;

    // Fill in the file dimensions
    (*info).width = width;
    (*info).height = height;

    // Fill in pre-set image settings. We are only set up to handle the
    // following:
    (*info).color_planes = 1;
    (*info).color_depth = 24;
    (*info).compression = 0;
    (*info).raw_size = 0;

    // Image resolution in pixels per meter
    (*info).horizontal_ppm = 3780;
    (*info).vertical_ppm = 3780;

    // Unused settings
    (*info).color_table = 0;
    (*info).important_colors = 0;
}

void destroyBitmap(BMPHeader* header, BMPInfo* info) {
    free(header);
    free(info);
}