#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <stdio.h>
#include <stdarg.h>

/**
 * Logging facility
 */
class Logger {
	public:
		int level;

		void operator()(int level, const char *fmt, ...) {
			va_list args;
			va_start(args, fmt);
			FILE* out;
			if(level < 0) out = stderr;
			else out = stdout;
			vfprintf(out, fmt, args);
			va_end(args);
			fprintf(out, "\n");
		}
};

extern Logger logger;

#endif
