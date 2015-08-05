/*
******************************************************************************
*
*   Copyright (C) 1997-2011, International Business Machines
*   Corporation and others.  All Rights Reserved.
*
******************************************************************************
*
*  FILE NAME : putilimp.h
*
*   Date        Name        Description
*   10/17/04    grhoten     Move internal functions from putil.h to this file.
******************************************************************************
*/

#ifndef PUTILIMP_H
#define PUTILIMP_H

#include "unicode/utypes.h"
#include "unicode/putil.h"

/*==========================================================================*/
/* Platform utilities                                                       */
/*==========================================================================*/

/**
 * Platform utilities isolates the platform dependencies of the
 * libarary.  For each platform which this code is ported to, these
 * functions may have to be re-implemented.
 */

/**
 * Floating point utility to determine if a double is Not a Number (NaN).
 * @internal
 */
U_INTERNAL UBool   U_EXPORT2 uprv_isNaN(double d);
/**
 * Floating point utility to determine if a double has an infinite value.
 * @internal
 */
U_INTERNAL UBool   U_EXPORT2 uprv_isInfinite(double d);
/**
 * Floating point utility to determine if a double has a positive infinite value.
 * @internal
 */
U_INTERNAL UBool   U_EXPORT2 uprv_isPositiveInfinity(double d);
/**
 * Floating point utility to determine if a double has a negative infinite value.
 * @internal
 */
U_INTERNAL UBool   U_EXPORT2 uprv_isNegativeInfinity(double d);
/**
 * Floating point utility that returns a Not a Number (NaN) value.
 * @internal
 */
U_INTERNAL double  U_EXPORT2 uprv_getNaN(void);
/**
 * Floating point utility that returns an infinite value.
 * @internal
 */
U_INTERNAL double  U_EXPORT2 uprv_getInfinity(void);

/**
 * Floating point utility to truncate a double.
 * @internal
 */
U_INTERNAL double  U_EXPORT2 uprv_trunc(double d);
/**
 * Floating point utility to calculate the floor of a double.
 * @internal
 */
U_INTERNAL double  U_EXPORT2 uprv_floor(double d);
/**
 * Floating point utility to calculate the ceiling of a double.
 * @internal
 */
U_INTERNAL double  U_EXPORT2 uprv_ceil(double d);
/**
 * Floating point utility to calculate the absolute value of a double.
 * @internal
 */
U_INTERNAL double  U_EXPORT2 uprv_fabs(double d);
/**
 * Floating point utility to calculate the fractional and integer parts of a double.
 * @internal
 */
U_INTERNAL double  U_EXPORT2 uprv_modf(double d, double* pinteger);
/**
 * Floating point utility to calculate the remainder of a double divided by another double.
 * @internal
 */
U_INTERNAL double  U_EXPORT2 uprv_fmod(double d, double y);
/**
 * Floating point utility to calculate d to the power of exponent (d^exponent).
 * @internal
 */
U_INTERNAL double  U_EXPORT2 uprv_pow(double d, double exponent);
/**
 * Floating point utility to calculate 10 to the power of exponent (10^exponent).
 * @internal
 */
U_INTERNAL double  U_EXPORT2 uprv_pow10(int32_t exponent);
/**
 * Floating point utility to calculate the maximum value of two doubles.
 * @internal
 */
U_INTERNAL double  U_EXPORT2 uprv_fmax(double d, double y);
/**
 * Floating point utility to calculate the minimum value of two doubles.
 * @internal
 */
U_INTERNAL double  U_EXPORT2 uprv_fmin(double d, double y);
/**
 * Private utility to calculate the maximum value of two integers.
 * @internal
 */
U_INTERNAL int32_t U_EXPORT2 uprv_max(int32_t d, int32_t y);
/**
 * Private utility to calculate the minimum value of two integers.
 * @internal
 */
U_INTERNAL int32_t U_EXPORT2 uprv_min(int32_t d, int32_t y);

#if U_IS_BIG_ENDIAN
#   define uprv_isNegative(number) (*((signed char *)&(number))<0)
#else
#   define uprv_isNegative(number) (*((signed char *)&(number)+sizeof(number)-1)<0)
#endif

/**
 * Return the largest positive number that can be represented by an integer
 * type of arbitrary bit length.
 * @internal
 */
U_INTERNAL double  U_EXPORT2 uprv_maxMantissa(void);

/**
 * Floating point utility to calculate the logarithm of a double.
 * @internal
 */
U_INTERNAL double  U_EXPORT2 uprv_log(double d);

/**
 * Does common notion of rounding e.g. uprv_floor(x + 0.5);
 * @param x the double number
 * @return the rounded double
 * @internal
 */
U_INTERNAL double  U_EXPORT2 uprv_round(double x);

#if 0
/**
 * Returns the number of digits after the decimal point in a double number x.
 *
 * @param x the double number
 * @return the number of digits after the decimal point in a double number x.
 * @internal
 */
/*U_INTERNAL int32_t  U_EXPORT2 uprv_digitsAfterDecimal(double x);*/
#endif

/**
 * Time zone utilities
 *
 * Wrappers for C runtime library functions relating to timezones.
 * The t_tzset() function (similar to tzset) uses the current setting
 * of the environment variable TZ to assign values to three global
 * variables: daylight, timezone, and tzname. These variables have the
 * following meanings, and are declared in &lt;time.h&gt;.
 *
 *   daylight   Nonzero if daylight-saving-time zone (DST) is specified
 *              in TZ; otherwise, 0. Default value is 1.
 *   timezone   Difference in seconds between coordinated universal
 *              time and local time. E.g., -28,800 for PST (GMT-8hrs)
 *   tzname(0)  Three-letter time-zone name derived from TZ environment
 *              variable. E.g., "PST".
 *   tzname(1)  Three-letter DST zone name derived from TZ environment
 *              variable.  E.g., "PDT". If DST zone is omitted from TZ,
 *              tzname(1) is an empty string.
 *
 * Notes: For example, to set the TZ environment variable to correspond
 * to the current time zone in Germany, you can use one of the
 * following statements:
 *
 *   set TZ=GST1GDT
 *   set TZ=GST+1GDT
 *
 * If the TZ value is not set, t_tzset() attempts to use the time zone
 * information specified by the operating system. Under Windows NT
 * and Windows 95, this information is specified in the Control Panel's
 * Date/Time application.
 * @internal
 */
U_INTERNAL void     U_EXPORT2 uprv_tzset(void);

/**
 * Difference in seconds between coordinated universal
 * time and local time. E.g., -28,800 for PST (GMT-8hrs)
 * @return the difference in seconds between coordinated universal time and local time.
 * @internal
 */
U_INTERNAL int32_t  U_EXPORT2 uprv_timezone(void);

/**
 *   tzname(0)  Three-letter time-zone name derived from TZ environment
 *              variable. E.g., "PST".
 *   tzname(1)  Three-letter DST zone name derived from TZ environment
 *              variable.  E.g., "PDT". If DST zone is omitted from TZ,
 *              tzname(1) is an empty string.
 * @internal
 */
U_INTERNAL const char* U_EXPORT2 uprv_tzname(int n);

/**
 * Get UTC (GMT) time measured in milliseconds since 0:00 on 1/1/1970.
 * This function is affected by 'faketime' and should be the bottleneck for all user-visible ICU time functions.
 * @return the UTC time measured in milliseconds
 * @internal
 */
U_INTERNAL UDate U_EXPORT2 uprv_getUTCtime(void);

/**
 * Get UTC (GMT) time measured in milliseconds since 0:00 on 1/1/1970.
 * This function is not affected by 'faketime', so it should only be used by low level test functions- not by anything that
 * exposes time to the end user.
 * @return the UTC time measured in milliseconds
 * @internal
 */
U_INTERNAL UDate U_EXPORT2 uprv_getRawUTCtime(void);

/**
 * Determine whether a pathname is absolute or not, as defined by the platform.
 * @param path Pathname to test
 * @return TRUE if the path is absolute
 * @internal (ICU 3.0)
 */
U_INTERNAL UBool U_EXPORT2 uprv_pathIsAbsolute(const char *path);

/**
 * Use U_MAX_PTR instead of this function.
 * @param void pointer to test
 * @return the largest possible pointer greater than the base
 * @internal (ICU 3.8)
 */
U_INTERNAL void * U_EXPORT2 uprv_maximumPtr(void *base);

/**
 * Maximum value of a (void*) - use to indicate the limit of an 'infinite' buffer.
 * In fact, buffer sizes must not exceed 2GB so that the difference between
 * the buffer limit and the buffer start can be expressed in an int32_t.
 *
 * The definition of U_MAX_PTR must fulfill the following conditions:
 * - return the largest possible pointer greater than base
 * - return a valid pointer according to the machine architecture (AS/400, 64-bit, etc.)
 * - avoid wrapping around at high addresses
 * - make sure that the returned pointer is not farther from base than 0x7fffffff bytes
 *
 * @param base The beginning of a buffer to find the maximum offset from
 * @internal
 */
#ifndef U_MAX_PTR
#  if defined(OS390) && !defined(_LP64)
    /* We have 31-bit pointers. */
#    define U_MAX_PTR(base) ((void *)0x7fffffff)
#  elif defined(OS400)
#    define U_MAX_PTR(base) uprv_maximumPtr((void *)base)
#  elif 0
    /*
     * For platforms where pointers are scalar values (which is normal, but unlike i5/OS)
     * but that do not define uintptr_t.
     *
     * However, this does not work on modern compilers:
     * The C++ standard does not define pointer overflow, and allows compilers to
     * assume that p+u>p for any pointer p and any integer u>0.
     * Thus, modern compilers optimize away the ">" comparison.
     * (See ICU tickets #7187 and #8096.)
     */
#    define U_MAX_PTR(base) \
    ((void *)(((char *)(base)+0x7fffffffu) > (char *)(base) \
        ? ((char *)(base)+0x7fffffffu) \
        : (char *)-1))
#  else
    /* Default version. C++ standard compliant for scalar pointers. */
#    define U_MAX_PTR(base) \
    ((void *)(((uintptr_t)(base)+0x7fffffffu) > (uintptr_t)(base) \
        ? ((uintptr_t)(base)+0x7fffffffu) \
        : (uintptr_t)-1))
#  endif
#endif

#if U_ENABLE_DYLOAD
/*  Dynamic Library Functions */

typedef void (UVoidFunction)(void);

/**
 * Load a library
 * @internal (ICU 4.4)
 */
U_INTERNAL void * U_EXPORT2 uprv_dl_open(const char *libName, UErrorCode *status);

/**
 * Close a library
 * @internal (ICU 4.4)
 */
U_INTERNAL void U_EXPORT2 uprv_dl_close( void *lib, UErrorCode *status);

/**
 * Extract a symbol from a library (function)
 * @internal (ICU 4.8)
 */
U_INTERNAL UVoidFunction* U_EXPORT2 uprv_dlsym_func( void *lib, const char *symbolName, UErrorCode *status);

/**
 * Extract a symbol from a library (function)
 * Not implemented, no clients.
 * @internal
 */
/* U_INTERNAL void * U_EXPORT2 uprv_dlsym_data( void *lib, const char *symbolName, UErrorCode *status); */


/**
 * Define malloc and related functions
 * @internal
 */
#if defined(OS400)
# define uprv_default_malloc(x) _C_TS_malloc(x)
# define uprv_default_realloc(x,y) _C_TS_realloc(x,y)
# define uprv_default_free(x) _C_TS_free(x)
/* also _C_TS_calloc(x) */
#else
/* C defaults */
# define uprv_default_malloc(x) malloc(x)
# define uprv_default_realloc(x,y) realloc(x,y)
# define uprv_default_free(x) free(x)
#endif

#else
# define uprv_default_malloc(x) malloc(x)
# define uprv_default_realloc(x,y) realloc(x,y)
# define uprv_default_free(x) free(x)
#endif

#endif
