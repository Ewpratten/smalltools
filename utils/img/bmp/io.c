#include "io.h"

#include <stdlib.h>

int writeBitmap(BMPHeader* header, BMPInfo* info, BGR8Bit* data_ptr,
                size_t data_len, FILE* stream) {
    // Tracker for number of objects written
    int status = 0;

    // Write the header
    status += fwrite(header, sizeof(BMPHeader), 1, stream);

    // Write the file info
    status += fwrite(info, sizeof(BMPInfo), 1, stream);

    // Write the pixels
    status += fwrite(data_ptr, sizeof(BGR8Bit), data_len, stream);

    return status;
}

int getBitmapDataLength(FILE* stream) {
    // Allocate the header and info data
    BMPHeader* header = (BMPHeader*)malloc(sizeof(BMPHeader));
    BMPInfo* info = (BMPInfo*)malloc(sizeof(BMPInfo));

    // Read in the header
    fread(header, sizeof(BMPHeader), 1, stream);

    // Read in the file info
    fread(info, sizeof(BMPInfo), 1, stream);

    // Get the size of all metadata in the file
    size_t headers_size = 14 + (*info).size;

    // Free the used header and info
    free(header);
    free(info);

    // Return the stated file size, minus the header sizes
    return (*header).size - headers_size;
}

size_t readBitmap(BMPHeader* header, BMPInfo* info, BGR8Bit* data_ptr,
                  size_t data_len, FILE* stream) {
    // Read in the header
    fread(header, sizeof(BMPHeader), 1, stream);

    // Read in the file info
    fread(info, sizeof(BMPInfo), 1, stream);

    // Read in every pixel
    return fread(data_ptr, sizeof(BGR8Bit), data_len, stream);
}