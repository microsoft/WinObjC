#ifndef PLATFORM_WINDOWS_STDIO__H
#define PLATFORM_WINDOWS_STDIO__H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdarg.h>

int vasprintf(char **str, const char *fmt, va_list ap);
int asprintf(char **str, const char *fmt, ...);

#ifdef __cplusplus
}
#endif

#endif
