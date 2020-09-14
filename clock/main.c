#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "utils/time/timestr.h"
#include "utils/time/sleep.h"

/**
 * @brief Fetches the local time from the system, and prints it
 */
void printLocalTime() {
    // Get the UTC time object
    time_t utc = time(NULL);

    // Get the local time from UTC
    struct tm local_time = *localtime(&utc);

    // Get the current time as a nice string
    char* time_string = getTimeAsString(&local_time);

    // Print the string
    printf("%s", time_string);

    // Free the string
    free(time_string);
}

int main(int argc, char const* argv[]) {
    // Print the local time info
    printLocalTime();

    // Seek back to the begining of the line in case we need to overwrite it
    // again
    printf("\r");

    // Check if the user only wanted one printout
    if (argc >= 2 && strcmp(argv[1], "-i") == 0) {
        // Move to a new line for the console not to overwrite what we just
        // wrote
        printf("\n");

        // Stop the program
        return 0;
    }

    // If we get here, the user wants to print the time forever.

    // Allocate a string to be used to clear the current line
    char* clear_line = (char*)malloc(max_time_string_length);

    // Fill it will null terminators, then mostly with spaces
    memset(clear_line, 0, max_time_string_length);
    memset(clear_line, 32, max_time_string_length - 1);

    // Loop forever, once per second
    while (1) {
        // Sleep 1 second
        xsleep(1);

        // Clear the line
        printf("\r%s\r", clear_line);

        // Print the date
        printLocalTime();

        // Flush the output
        fflush(stdout);
    }

    return 0;
}
