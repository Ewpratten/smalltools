#include "timestr.h"

#include <check.h>
#include <string.h>
#include <time.h>

START_TEST(test_time_within_max_size) {
    // Create a large time
    struct tm time = {.tm_hour = 24,
                      .tm_min = 59,
                      .tm_sec = 59,
                      .tm_mday = 4,
                      .tm_mon = 1,
                      .tm_wday = 4,
                      .tm_year = 1000};

    // Get the time string
    char* time_str = getTimeAsString(&time);

    // Make sure the string is not longer than the max length
    ck_assert_int_eq(strlen(time_str) <= max_time_string_length, 1);
}

int main(void) { return 0; }