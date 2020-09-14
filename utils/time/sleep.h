#if !defined(_SMALLTOOLS_UTILS_TIME_SLEEP_H)
#define _SMALLTOOLS_UTILS_TIME_SLEEP_H

#ifdef __cplusplus
namespace st {
namespace time {
extern "C" {
#endif

/**
 * @brief Cross-platform sleep
 *
 * @param seconds Number of seconds to sleep
 */
void xsleep(unsigned int seconds);

#ifdef __cplusplus
}  // extern C
}  // namespace st
}  // namespace time
#endif

#endif  // _SMALLTOOLS_UTILS_TIME_SLEEP_H
