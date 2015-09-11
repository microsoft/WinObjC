#ifndef PLATFORM_WINDOWS_SYS_TIME__H
#define PLATFORM_WINDOWS_SYS_TIME__H

#ifdef __cplusplus
extern "C" {
#endif

struct timeval;
struct timezone 
{
	int  tz_minuteswest; /* minutes W of Greenwich */
	int  tz_dsttime;     /* type of dst correction */
};

int gettimeofday(struct timeval* tp, struct timezone* tzp);

#ifdef __cplusplus
}
#endif

#endif
