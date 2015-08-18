#include "config/config.h"

#include <sys/time.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define	__DISPATCH_INDIRECT__
#include "src/internal.h"

#include "dispatch_test.h"

int main(void)
{
	test_start("Dispatch Update Timer");

	dispatch_queue_t main_q = dispatch_get_main_queue();
	test_ptr("dispatch_get_main_queue", main_q, dispatch_get_current_queue());

	__block int i = 0;
	struct timeval start_time;

	gettimeofday(&start_time, NULL);
	dispatch_source_attr_t attr = dispatch_source_attr_create();
	dispatch_source_attr_set_finalizer(attr, ^(dispatch_source_t ds) {
		struct timeval end_time;
		gettimeofday(&end_time, NULL);
		// Make sure we actually managed to adjust the interval
		// duration.  Seven one second ticks would blow past
		// this.
		test_long_less_than("total duration", end_time.tv_sec - start_time.tv_sec, 3);
		test_ptr_notnull("finalizer ran", ds);
		test_stop();
	});

	dispatch_source_t s = dispatch_source_timer_create(DISPATCH_TIMER_INTERVAL,
		1000000000ull,
		0,
		attr,
		main_q,
		^(dispatch_event_t ev) {
			long err;
			if (dispatch_event_get_error(ev, &err)) {
				test_errno("dispatch_event_get_error", err, ECANCELED);
				dispatch_release(dispatch_event_get_source(ev));
			} else {
				fprintf(stderr, "%d\n", ++i);
				if (i >= 7) {
					dispatch_cancel(dispatch_event_get_source(ev));
				} else if (i == 1) {
					dispatch_source_timer_set_time(dispatch_event_get_source(ev), 100, 0);
				}
			}
		});
	test_ptr_notnull("dispatch_source_timer_create", s);

	dispatch_release(attr);

	dispatch_main();

	return 0;
}
