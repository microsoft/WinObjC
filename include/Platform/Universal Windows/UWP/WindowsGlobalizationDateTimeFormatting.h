//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

// WindowsGlobalizationDateTimeFormatting.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WGDDateTimeFormatter;
@protocol WGDIDateTimeFormatter
, WGDIDateTimeFormatterFactory, WGDIDateTimeFormatterStatics, WGDIDateTimeFormatter2;

// Windows.Globalization.DateTimeFormatting.YearFormat
enum _WGDYearFormat {
    WGDYearFormatNone = 0,
    WGDYearFormatDefault = 1,
    WGDYearFormatAbbreviated = 2,
    WGDYearFormatFull = 3,
};
typedef unsigned WGDYearFormat;

// Windows.Globalization.DateTimeFormatting.MonthFormat
enum _WGDMonthFormat {
    WGDMonthFormatNone = 0,
    WGDMonthFormatDefault = 1,
    WGDMonthFormatAbbreviated = 2,
    WGDMonthFormatFull = 3,
    WGDMonthFormatNumeric = 4,
};
typedef unsigned WGDMonthFormat;

// Windows.Globalization.DateTimeFormatting.DayOfWeekFormat
enum _WGDDayOfWeekFormat {
    WGDDayOfWeekFormatNone = 0,
    WGDDayOfWeekFormatDefault = 1,
    WGDDayOfWeekFormatAbbreviated = 2,
    WGDDayOfWeekFormatFull = 3,
};
typedef unsigned WGDDayOfWeekFormat;

// Windows.Globalization.DateTimeFormatting.DayFormat
enum _WGDDayFormat {
    WGDDayFormatNone = 0,
    WGDDayFormatDefault = 1,
};
typedef unsigned WGDDayFormat;

// Windows.Globalization.DateTimeFormatting.HourFormat
enum _WGDHourFormat {
    WGDHourFormatNone = 0,
    WGDHourFormatDefault = 1,
};
typedef unsigned WGDHourFormat;

// Windows.Globalization.DateTimeFormatting.MinuteFormat
enum _WGDMinuteFormat {
    WGDMinuteFormatNone = 0,
    WGDMinuteFormatDefault = 1,
};
typedef unsigned WGDMinuteFormat;

// Windows.Globalization.DateTimeFormatting.SecondFormat
enum _WGDSecondFormat {
    WGDSecondFormatNone = 0,
    WGDSecondFormatDefault = 1,
};
typedef unsigned WGDSecondFormat;

#include "WindowsFoundationCollections.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Globalization.DateTimeFormatting.DateTimeFormatter
#ifndef __WGDDateTimeFormatter_DEFINED__
#define __WGDDateTimeFormatter_DEFINED__

WINRT_EXPORT
@interface WGDDateTimeFormatter : RTObject
+ (WGDDateTimeFormatter*)createDateTimeFormatter:(NSString*)formatTemplate ACTIVATOR;
+ (WGDDateTimeFormatter*)createDateTimeFormatterLanguages:(NSString*)formatTemplate
                                                languages:(id<NSFastEnumeration> /* NSString * */)languages ACTIVATOR;
+ (WGDDateTimeFormatter*)createDateTimeFormatterContext:(NSString*)formatTemplate
                                              languages:(id<NSFastEnumeration> /* NSString * */)languages
                                       geographicRegion:(NSString*)geographicRegion
                                               calendar:(NSString*)calendar
                                                  clock:(NSString*)clock ACTIVATOR;
+ (WGDDateTimeFormatter*)createDateTimeFormatterDate:(WGDYearFormat)yearFormat
                                         monthFormat:(WGDMonthFormat)monthFormat
                                           dayFormat:(WGDDayFormat)dayFormat
                                     dayOfWeekFormat:(WGDDayOfWeekFormat)dayOfWeekFormat ACTIVATOR;
+ (WGDDateTimeFormatter*)createDateTimeFormatterTime:(WGDHourFormat)hourFormat
                                        minuteFormat:(WGDMinuteFormat)minuteFormat
                                        secondFormat:(WGDSecondFormat)secondFormat ACTIVATOR;
+ (WGDDateTimeFormatter*)createDateTimeFormatterDateTimeLanguages:(WGDYearFormat)yearFormat
                                                      monthFormat:(WGDMonthFormat)monthFormat
                                                        dayFormat:(WGDDayFormat)dayFormat
                                                  dayOfWeekFormat:(WGDDayOfWeekFormat)dayOfWeekFormat
                                                       hourFormat:(WGDHourFormat)hourFormat
                                                     minuteFormat:(WGDMinuteFormat)minuteFormat
                                                     secondFormat:(WGDSecondFormat)secondFormat
                                                        languages:(id<NSFastEnumeration> /* NSString * */)languages ACTIVATOR;
+ (WGDDateTimeFormatter*)createDateTimeFormatterDateTimeContext:(WGDYearFormat)yearFormat
                                                    monthFormat:(WGDMonthFormat)monthFormat
                                                      dayFormat:(WGDDayFormat)dayFormat
                                                dayOfWeekFormat:(WGDDayOfWeekFormat)dayOfWeekFormat
                                                     hourFormat:(WGDHourFormat)hourFormat
                                                   minuteFormat:(WGDMinuteFormat)minuteFormat
                                                   secondFormat:(WGDSecondFormat)secondFormat
                                                      languages:(id<NSFastEnumeration> /* NSString * */)languages
                                               geographicRegion:(NSString*)geographicRegion
                                                       calendar:(NSString*)calendar
                                                          clock:(NSString*)clock ACTIVATOR;
@property (copy) NSString* numeralSystem;
@property (readonly) NSString* clock;
@property (readonly) NSString* geographicRegion;
@property (readonly) WGDDayFormat includeDay;
@property (readonly) WGDDayOfWeekFormat includeDayOfWeek;
@property (readonly) WGDHourFormat includeHour;
@property (readonly) WGDMinuteFormat includeMinute;
@property (readonly) WGDMonthFormat includeMonth;
@property (readonly) WGDSecondFormat includeSecond;
@property (readonly) WGDYearFormat includeYear;
@property (readonly) NSArray* languages;
@property (readonly) NSString* calendar;
@property (readonly) NSArray* patterns;
@property (readonly) NSString* resolvedGeographicRegion;
@property (readonly) NSString* resolvedLanguage;
@property (readonly) NSString* Template;
+ (WGDDateTimeFormatter*)longDate;
+ (WGDDateTimeFormatter*)longTime;
+ (WGDDateTimeFormatter*)shortDate;
+ (WGDDateTimeFormatter*)shortTime;
- (NSString*)format:(WFDateTime*)value;
- (NSString*)formatUsingTimeZone:(WFDateTime*)datetime timeZoneId:(NSString*)timeZoneId;
@end

#endif // __WGDDateTimeFormatter_DEFINED__
