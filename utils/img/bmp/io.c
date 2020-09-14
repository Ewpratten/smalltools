#include "io.h"

#include <stdlib.h>

#include "utils/platform/endianness.h"

int writeBitmap(BMPHeader* header, BMPInfo* info, BGR8Bit* data_ptr,
                size_t data_len, FILE* stream) {
    // Tracker for number of objects written
    int status = 0;

    // Write the header
    status += fwrite(header, sizeof_BMPHeader, 1, stream);

    // Write the file info
    status += fwrite(info, sizeof_BMPInfo, 1, stream);

    // Write the pixels
    status += fwrite(data_ptr, sizeof(BGR8Bit), data_len, stream);

    return status;
}

void readInMetadata(BMPHeader* header, BMPInfo* info, FILE* stream) {
    // Fill in the header (handling little endian)
    (*header).signature[0] = fgetc(stream);
    (*header).signature[1] = fgetc(stream);
    (*header).size = bytesToU32Little(fgetc(stream), fgetc(stream),
                                      fgetc(stream), fgetc(stream));
    (*header).reserved = bytesToU32Little(fgetc(stream), fgetc(stream),
                                          fgetc(stream), fgetc(stream));
    (*header).data_offset = bytesToU32Little(fgetc(stream), fgetc(stream),
                                             fgetc(stream), fgetc(stream));

    // Read in the file info
    fread(info, sizeof_BMPInfo, 1, stream);
}

uint32_t getBitmapDataLength(FILE* stream) {
    // Allocate the header and info data
    BMPHeader* header = (BMPHeader*)malloc(sizeof_BMPHeader);
    BMPInfo* info = (BMPInfo*)malloc(sizeof_BMPInfo);

    // Read data
    readInMetadata(header, info, stream);

    // Get the position of the first pixel
    uint32_t offset = (*header).data_offset;

    // Get the number of bytes in the file
    uint32_t num_bytes = (*header).size;

    // Free the used header and info
    free(header);
    free(info);

    // Return the number of pixels
    return num_bytes - offset;
}

uint32_t readBitmap(BMPHeader* header, BMPInfo* info, BGR8Bit* data_ptr,
                    size_t data_len, FILE* stream) {
    // Read data
    readInMetadata(header, info, stream);

    // Read in every pixel
    return fread(data_ptr, sizeof(BGR8Bit), data_len, stream);
}