#include "sleep.h"
#include <unistd.h>

void xsleep(unsigned int seconds) { sleep(seconds); }