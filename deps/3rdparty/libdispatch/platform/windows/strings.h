#ifndef PLATFORM_WINDOWS_STRINGS__H
#define PLATFORM_WINDOWS_STRINGS__H

#ifdef __cplusplus
extern "C" {
#endif

int ffs(int value);
int ffsl(long value);
#ifdef _M_X64
int ffsll(long long value);
#endif

int fls(int value);
int flsl(long value);
#ifdef _M_X64
int flsll(long long value);
#endif

#ifdef __cplusplus
}
#endif

#endif
