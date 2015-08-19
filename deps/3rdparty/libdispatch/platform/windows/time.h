#ifndef PLATFORM_WINDOWS_TIME__H
#define PLATFORM_WINDOWS_TIME__H

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <time.h>

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef HAS_TIMESPEC
struct timespec
{
	time_t tv_sec;
	__int32 tv_nsec;
};
#endif

typedef signed __int32 clockid_t;
#define CLOCK_REALTIME 0
#define CLOCK_UPTIME 2

#define MSEC_PER_SEC 1000LL

#define EPOCH_DIFFERENCE 116444736000000000LL  // 100 nsec intervals between NT epoch and Unix epoch
#define NSEC_PER_INTERVAL 100LL
#define INTERVALS_PER_SEC 10000000LL

int clock_gettime(clockid_t clk_id, struct timespec* now);

#ifdef __cplusplus
}
#endif

#endif
