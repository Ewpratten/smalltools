#include "timestr.h"

#include <stdio.h>
#include <stdlib.h>

// The longest possible date will be 41 chars + \0
size_t max_time_string_length = 41 + 1;

// A list of all months in order
const char* month_names[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                               "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

// A list of all day names in order
const char* day_names[7] = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                            "Thursday", "Friday", "Saturday"};

char* getTimeAsString(struct tm* time) {
    // Allocate the max needed memory
    char* time_str = (char*)malloc(max_time_string_length * sizeof(char));

    // Write in the time data
    snprintf(time_str, max_time_string_length,
             "It is %s, %s %d, %d. At %d:%d:%d", day_names[(*time).tm_wday],
             month_names[(*time).tm_mon], (*time).tm_mday,
             (*time).tm_year + 1900, (*time).tm_hour, (*time).tm_min,
             (*time).tm_sec);

    // Return this string
    return time_str;
}