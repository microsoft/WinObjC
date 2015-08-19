#include "stdio.h"

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4996) // 'vsnprintf': This function or variable may be unsafe. Consider using vsnprintf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.
#endif

int vasprintf(char** str, const char* fmt, va_list ap)
{
	va_list original_ap = ap;
	size_t size = 32;
	int n;
	char* p = NULL;
	char* np = NULL;

	for(;;)
	{
		ap = original_ap;
		if((np = realloc(p, size)) == NULL)
		{
			free(p);
			return -1;
		}
		p = np;
		n = vsnprintf(p, size, fmt, ap);
		va_end(ap);

		if(n > -1 && (size_t)n < size)
		{
			*str = p;
			return n;
		}
		size *= 2;
	}
}

int asprintf(char **str, const char *fmt, ...)
{
	va_list ap;
	int ret;

	*str = NULL;
	va_start(ap, fmt);
	ret = vasprintf(str, fmt, ap);
	va_end(ap);
	return ret;
}

#ifdef _MSC_VER
#pragma warning(pop)
#endif
