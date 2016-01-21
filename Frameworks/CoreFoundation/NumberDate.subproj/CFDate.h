// clang-format off

// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//


/*	CFDate.h
	Copyright (c) 1998 - 2015 Apple Inc. and the Swift project authors
*/

#if !defined(__COREFOUNDATION_CFDATE__)
#define __COREFOUNDATION_CFDATE__ 1

#include <CoreFoundation/CFBase.h>

CF_IMPLICIT_BRIDGING_ENABLED
CF_EXTERN_C_BEGIN

typedef double CFTimeInterval;
typedef CFTimeInterval CFAbsoluteTime;
/* absolute time is the time interval since the reference date */
/* the reference date (epoch) is 00:00:00 1 January 2001. */

CF_EXPORT
CFAbsoluteTime CFAbsoluteTimeGetCurrent(void);

CF_EXPORT
const CFTimeInterval kCFAbsoluteTimeIntervalSince1970;
CF_EXPORT
const CFTimeInterval kCFAbsoluteTimeIntervalSince1904;

typedef const struct CF_BRIDGED_TYPE(NSDate) __CFDate * CFDateRef;

CF_EXPORT
CFTypeID CFDateGetTypeID(void);

CF_EXPORT
CFDateRef CFDateCreate(CFAllocatorRef allocator, CFAbsoluteTime at);

CF_EXPORT
CFAbsoluteTime CFDateGetAbsoluteTime(CFDateRef theDate);

CF_EXPORT
CFTimeInterval CFDateGetTimeIntervalSinceDate(CFDateRef theDate, CFDateRef otherDate);

CF_EXPORT
CFComparisonResult CFDateCompare(CFDateRef theDate, CFDateRef otherDate, void *context);

CF_IMPLICIT_BRIDGING_DISABLED

typedef const struct CF_BRIDGED_TYPE(NSTimeZone) __CFTimeZone * CFTimeZoneRef;


#if !defined(CF_CALENDAR_ENUM_DEPRECATED)
#define CF_CALENDAR_ENUM_DEPRECATED(A, B, C, D, ...) CF_ENUM_DEPRECATED(A, B, C, D, __VA_ARGS__)
#define CF_CALENDAR_DEPRECATED(A, B, C, D, ...) CF_DEPRECATED(A, B, C, D, __VA_ARGS__)
#endif

typedef struct {
    SInt32 year;
    SInt8 month;
    SInt8 day;
    SInt8 hour;
    SInt8 minute;
    double second;
} CFGregorianDate CF_CALENDAR_DEPRECATED(10_4, 10_10, 2_0, 8_0, "Use CFCalendar or NSCalendar API instead");

typedef struct {
    SInt32 years;
    SInt32 months;
    SInt32 days;
    SInt32 hours;
    SInt32 minutes;
    double seconds;
} CFGregorianUnits CF_CALENDAR_DEPRECATED(10_4, 10_10, 2_0, 8_0, "Use CFCalendar or NSCalendar API instead");

typedef CF_OPTIONS(CFOptionFlags, CFGregorianUnitFlags) {
    kCFGregorianUnitsYears CF_CALENDAR_ENUM_DEPRECATED(10_4, 10_10, 2_0, 8_0, "Use CFCalendar or NSCalendar API instead") = (1UL << 0),
    kCFGregorianUnitsMonths CF_CALENDAR_ENUM_DEPRECATED(10_4, 10_10, 2_0, 8_0, "Use CFCalendar or NSCalendar API instead") = (1UL << 1),
    kCFGregorianUnitsDays CF_CALENDAR_ENUM_DEPRECATED(10_4, 10_10, 2_0, 8_0, "Use CFCalendar or NSCalendar API instead") = (1UL << 2),
    kCFGregorianUnitsHours CF_CALENDAR_ENUM_DEPRECATED(10_4, 10_10, 2_0, 8_0, "Use CFCalendar or NSCalendar API instead") = (1UL << 3),
    kCFGregorianUnitsMinutes CF_CALENDAR_ENUM_DEPRECATED(10_4, 10_10, 2_0, 8_0, "Use CFCalendar or NSCalendar API instead") = (1UL << 4),
    kCFGregorianUnitsSeconds CF_CALENDAR_ENUM_DEPRECATED(10_4, 10_10, 2_0, 8_0, "Use CFCalendar or NSCalendar API instead") = (1UL << 5),
    kCFGregorianAllUnits CF_CALENDAR_ENUM_DEPRECATED(10_4, 10_10, 2_0, 8_0, "Use CFCalendar or NSCalendar API instead") = 0x00FFFFFF
};

CF_EXPORT
Boolean CFGregorianDateIsValid(CFGregorianDate gdate, CFOptionFlags unitFlags) CF_CALENDAR_DEPRECATED(10_4, 10_10, 2_0, 8_0, "Use CFCalendar or NSCalendar API instead");

CF_EXPORT
CFAbsoluteTime CFGregorianDateGetAbsoluteTime(CFGregorianDate gdate, CFTimeZoneRef tz) CF_CALENDAR_DEPRECATED(10_4, 10_10, 2_0, 8_0, "Use CFCalendar or NSCalendar API instead");

CF_EXPORT
CFGregorianDate CFAbsoluteTimeGetGregorianDate(CFAbsoluteTime at, CFTimeZoneRef tz) CF_CALENDAR_DEPRECATED(10_4, 10_10, 2_0, 8_0, "Use CFCalendar or NSCalendar API instead");

CF_EXPORT
CFAbsoluteTime CFAbsoluteTimeAddGregorianUnits(CFAbsoluteTime at, CFTimeZoneRef tz, CFGregorianUnits units) CF_CALENDAR_DEPRECATED(10_4, 10_10, 2_0, 8_0, "Use CFCalendar or NSCalendar API instead");

CF_EXPORT
CFGregorianUnits CFAbsoluteTimeGetDifferenceAsGregorianUnits(CFAbsoluteTime at1, CFAbsoluteTime at2, CFTimeZoneRef tz, CFOptionFlags unitFlags) CF_CALENDAR_DEPRECATED(10_4, 10_10, 2_0, 8_0, "Use CFCalendar or NSCalendar API instead");

CF_EXPORT
SInt32 CFAbsoluteTimeGetDayOfWeek(CFAbsoluteTime at, CFTimeZoneRef tz) CF_CALENDAR_DEPRECATED(10_4, 10_10, 2_0, 8_0, "Use CFCalendar or NSCalendar API instead");

CF_EXPORT
SInt32 CFAbsoluteTimeGetDayOfYear(CFAbsoluteTime at, CFTimeZoneRef tz) CF_CALENDAR_DEPRECATED(10_4, 10_10, 2_0, 8_0, "Use CFCalendar or NSCalendar API instead");

CF_EXPORT
SInt32 CFAbsoluteTimeGetWeekOfYear(CFAbsoluteTime at, CFTimeZoneRef tz) CF_CALENDAR_DEPRECATED(10_4, 10_10, 2_0, 8_0, "Use CFCalendar or NSCalendar API instead");

CF_EXTERN_C_END

#endif /* ! __COREFOUNDATION_CFDATE__ */

// clang-format on
