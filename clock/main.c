#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "utils/time/sleep.h"
#include "utils/time/timestr.h"

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

/**
 * @brief Print program usage / help message
 */
void help() {
    puts("clock: A small tool for displaying the time");
    puts("\t-i (optional)\tOnly print the time once");
    puts(
        "\nCalling this program with no arguments will update the time every "
        "second");
    puts("This can be stopped by pressing CTRL+C");
}

int main(int argc, char const* argv[]) {
    // Handle program help
    if (argc >= 2 && strcmp(argv[1], "-h") == 0) {
        help();
        return 0;
    }

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
