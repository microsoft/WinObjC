#include "internal.h"

static char _dispatch_build[16];

/*
 * XXXRW: What to do here for !Mac OS X?
 */
static void
_dispatch_bug_init(void *context DISPATCH_UNUSED)
{
#ifdef __APPLE__
	int mib[] = { CTL_KERN, KERN_OSVERSION };
	size_t bufsz = sizeof(_dispatch_build);

	sysctl(mib, 2, _dispatch_build, &bufsz, NULL, 0);
#else
	memset(_dispatch_build, 0, sizeof(_dispatch_build));
#endif
}

void
_dispatch_bug(size_t line, long val)
{
	static dispatch_once_t pred;
	static void *last_seen;
#if !defined( WINOBJC )
	void *ra = __builtin_return_address(0);
#else
	void *ra = NULL;
#endif

	dispatch_once_f(&pred, NULL, _dispatch_bug_init);
	if (last_seen != ra) {
		last_seen = ra;
		_dispatch_log("BUG in libdispatch: %s - %lu - 0x%lx", _dispatch_build, (unsigned long)line, val);
#if TARGET_OS_WIN32 && defined(_DEBUG) && !defined( WINOBJC )
		DebugBreak();
#else
        abort();
#endif
	}
}

void
_dispatch_abort(size_t line, long val)
{
	_dispatch_bug(line, val);
	abort();
}

void
_dispatch_log(const char *msg, ...)
{
	va_list ap;

	va_start(ap, msg);

	_dispatch_logv(msg, ap);

	va_end(ap);
}

void
_dispatch_logv(const char *msg, va_list ap)
{
#if TARGET_OS_WIN32
	size_t len = strlen(msg);
	char* newbuf = calloc(len + 2, 1);
	char* message = NULL;

	sprintf(newbuf, "%s\n", msg);
	vasprintf(&message, newbuf, ap);

	OutputDebugStringA(message);

	free(message);
	free(newbuf);
#elif DISPATCH_DEBUG
	static FILE *logfile;
	FILE *tmp;
	char* newbuf = calloc(strlen(msg) + 2, 1);
	char path[256];

	sprintf(newbuf, "%s\n", msg);

	if (!logfile) {
		snprintf(path, sizeof(path), "/var/tmp/libdispatch.%d.log", getpid());
		tmp = fopen(path, "a");
		assert(tmp);
		if (!dispatch_atomic_cmpxchg(&logfile, NULL, tmp)) {
			fclose(tmp);
		} else {
			struct timeval tv;
			gettimeofday(&tv, NULL);
			fprintf(logfile, "=== log file opened for %s[%u] at %ld.%06u ===\n", getprogname() ? getprogname() : "", getpid(), tv.tv_sec, tv.tv_usec);
		}
	}
	vfprintf(logfile, newbuf, ap);
	fflush(logfile);
	free(newbuf);
#else
	vsyslog(LOG_NOTICE, msg, ap);
#endif
}
