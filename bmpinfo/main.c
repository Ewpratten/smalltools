#include <stdio.h>
#include <string.h>

#include "utils/img/bmp/fileheader.h"
#include "utils/img/bmp/io.h"

void help() {
    puts(
        "bmpinfo: a small tool for displaying the header info of a bitmap "
        "file");
    puts("Usage:");
    puts("\tbmpinfo /path/to/file.bmp");
}

int main(int argc, char const* argv[]) {
    // Handle program help
    if (argc >= 2 && strcmp(argv[1], "-h") == 0) {
        help();
        return 0;
    }

    // Handle no input file
    if (!(argc >= 2)) {
        puts("Argument \"infile\" missing.");
        return 1;
    }

    // Get the input filename
    const char* input_file_path = argv[1];

    // Open the requested file
    FILE* bmp_file = fopen(input_file_path, "rb");

    // Handle file issues
    if (bmp_file == NULL) {
        puts("Error opening file");
        return 1;
    }

    // Create file header and info data
    BMPHeader header;
    BMPInfo info;

    // Read the number of pixels stored in the file
    uint32_t num_pixels = getBitmapDataLength(bmp_file);
    fseek(bmp_file, 0, SEEK_SET);

    // Read data from file
    // Tell it to read no pixels
    readBitmap(&header, &info, NULL, 0, bmp_file);

    // Print file info
    printf("Type: %c%c\n", header.signature[0], header.signature[1]);
    printf("Total size: %d\n", header.size);
    printf("Num pixels: %ld\n", num_pixels);
    printf("Num reserved bytes: %d\n", header.reserved);
    printf("Data offset: %d\n", header.data_offset);
    printf("Image width: %d\n", info.width);
    printf("Image height: %d\n", info.height);
    printf("Color planes: %d\n", info.color_planes);
    printf("Color depth: %d\n", info.color_depth);
    printf("Compression: %d\n", info.compression);
    printf("Horizontal pixels/meter: %d\n", info.horizontal_ppm);
    printf("Vertical pixels/meter: %d\n", info.vertical_ppm);
    printf("Color table: %d\n", info.color_table);
    printf("Important colors: %d\n", info.important_colors);

    return 0;
}
