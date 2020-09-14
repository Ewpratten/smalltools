#if !defined(_SMALLTOOLS_UTILS_TIME_TIMESTR_H)
#define _SMALLTOOLS_UTILS_TIME_TIMESTR_H

#include <time.h>

#ifdef __cplusplus
namespace st {
namespace time {
extern "C" {
#endif

// A list of all months in order
extern const char* month_names[12];

// A list of all day names in order
extern const char* day_names[7];

// The maximum length of a time string
extern size_t max_time_string_length;

/**
 * @brief Get the Time As String
 *
 * @param time Time
 * @return String
 */
char* getTimeAsString(struct tm* time);

#ifdef __cplusplus
}  // extern C
}  // namespace st
}  // namespace time
#endif

#endif  // _SMALLTOOLS_UTILS_TIME_TIMESTR_H
