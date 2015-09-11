#include "dispatch_test.h"

#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <sys/timespec.h>

static const unsigned __int64 intervals_per_second      = 10000000ULL;
static const unsigned __int64 microseconds_per_second   = 1000000ULL;
static const unsigned __int64 intervals_per_microsecond = 10ULL;
static const unsigned __int64 intervals_since_epoch     = 116444736000000000ULL;
static const unsigned __int64 microseconds_since_epoch  = 11644473600000000ULL;

int
gettimeofday(struct timeval* tp, void* tzp)
{
	FILETIME file_time;
	ULARGE_INTEGER ularge;

	UNREFERENCED_PARAMETER(tzp);

	GetSystemTimeAsFileTime(&file_time);
	ularge.LowPart = file_time.dwLowDateTime;
	ularge.HighPart = file_time.dwHighDateTime;
	ularge.QuadPart -= intervals_since_epoch;
	ularge.QuadPart /= intervals_per_microsecond;
	tp->tv_sec = (long) (ularge.QuadPart / microseconds_per_second);
	tp->tv_usec = (long) (ularge.QuadPart % microseconds_per_second);

	return 0;
}

struct timeval start_time;
dispatch_source_t timer;
int i = 0;

static void
cancel_handler(void* context)
{
	struct timeval end_time;
	UNREFERENCED_PARAMETER(context);
	gettimeofday(&end_time, NULL);
	// Make sure we actually managed to adjust the interval
	// duration.  Seven one second ticks would blow past
	// this.
	test_long_less_than("total duration", end_time.tv_sec - start_time.tv_sec, 3);
	test_ptr_notnull("finalizer ran", timer);
	test_stop();
}

static void
event_handler(void* context)
{
	UNREFERENCED_PARAMETER(context);
	++i;
	fprintf(stderr, "%d\n", i);
	if (i >= 7) {
		dispatch_source_cancel(timer);
	} else if (i == 1) {
		dispatch_source_set_timer(timer, 0, 100, 0);
	}
}

int
main(void)
{
	dispatch_queue_t main_q;

	test_start("Dispatch Update Timer");

	main_q = dispatch_get_main_queue();
	test_ptr("dispatch_get_main_queue", main_q, dispatch_get_current_queue());
	
	timer = dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER, 0, 0, main_q);
	dispatch_source_set_timer(timer, 1000000000ull, 0, 0);
	dispatch_source_set_cancel_handler_f(timer, cancel_handler);
	dispatch_source_set_event_handler_f(timer, event_handler);
	test_ptr_notnull("dispatch_source_timer_create", timer);

	gettimeofday(&start_time, NULL);
	dispatch_resume(as_do(timer));

	dispatch_main();
}
