#include "time.h"

#include <SDKDDKVer.h>
#include <Windows.h>

void _ulonglong_to_timespec(ULONGLONG when, struct timespec* ts)
{
	when -= EPOCH_DIFFERENCE;
	ts->tv_sec = when / INTERVALS_PER_SEC;
	ts->tv_nsec = (when % INTERVALS_PER_SEC) * NSEC_PER_INTERVAL;
}

void _filetime_to_timespec(FILETIME when, struct timespec* ts)
{
	ULARGE_INTEGER computable_time = {0};
	computable_time.HighPart = when.dwHighDateTime;
	computable_time.LowPart = when.dwLowDateTime;
	_ulonglong_to_timespec(computable_time.QuadPart, ts);
}

int clock_gettime(clockid_t clk_id, struct timespec* now)
{
	switch(clk_id)
	{
	case CLOCK_REALTIME:
		{
			FILETIME current_time = {0};
			GetSystemTimeAsFileTime(&current_time);
			_filetime_to_timespec(current_time, now);
		}
		break;
	case CLOCK_UPTIME:
		{
			ULONGLONG unbiased_time = {0};
			QueryUnbiasedInterruptTime(&unbiased_time);
			_ulonglong_to_timespec(unbiased_time, now);
		}
		break;
	default:
		return -1;
	}
	return 0;
}
