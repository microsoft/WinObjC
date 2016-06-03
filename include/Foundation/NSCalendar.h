//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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
#pragma once

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSRange.h>

@class NSString;
@class NSLocale;
@class NSDate;
@class NSTimeZone;
@class NSDateComponents;
@class NSArray;

#import <CoreFoundation/CFCalendar.h>

enum {
    NSCalendarWrapComponents = (1UL << 0),
    NSCalendarMatchStrictly = (1ULL << 1),
    NSCalendarSearchBackwards = (1ULL << 2),
    NSCalendarMatchPreviousTimePreservingSmallerUnits = (1ULL << 8),
    NSCalendarMatchNextTimePreservingSmallerUnits = (1ULL << 9),
    NSCalendarMatchNextTime = (1ULL << 10),
    NSCalendarMatchFirst = (1ULL << 12),
    NSCalendarMatchLast = (1ULL << 13)
};

enum {
    NSWrapCalendarComponents = NSCalendarWrapComponents,
};

enum {
    NSCalendarUnitEra = kCFCalendarUnitEra,
    NSCalendarUnitYear = kCFCalendarUnitYear,
    NSCalendarUnitMonth = kCFCalendarUnitMonth,
    NSCalendarUnitDay = kCFCalendarUnitDay,
    NSCalendarUnitHour = kCFCalendarUnitHour,
    NSCalendarUnitMinute = kCFCalendarUnitMinute,
    NSCalendarUnitSecond = kCFCalendarUnitSecond,
    NSCalendarUnitWeekday = kCFCalendarUnitWeekday,
    NSCalendarUnitWeekdayOrdinal = kCFCalendarUnitWeekdayOrdinal,
    NSCalendarUnitQuarter = kCFCalendarUnitQuarter,
    NSCalendarUnitWeekOfMonth = kCFCalendarUnitWeekOfMonth,
    NSCalendarUnitWeekOfYear = kCFCalendarUnitWeekOfYear,
    NSCalendarUnitYearForWeekOfYear = kCFCalendarUnitYearForWeekOfYear,
    NSCalendarUnitNanosecond = (1 << 15),
    NSCalendarUnitCalendar = (1 << 20),
    NSCalendarUnitTimeZone = (1 << 21),
    NSEraCalendarUnit = kCFCalendarUnitEra,
    NSYearCalendarUnit = kCFCalendarUnitYear,
    NSMonthCalendarUnit = kCFCalendarUnitMonth,
    NSDayCalendarUnit = kCFCalendarUnitDay,
    NSHourCalendarUnit = kCFCalendarUnitHour,
    NSMinuteCalendarUnit = kCFCalendarUnitMinute,
    NSSecondCalendarUnit = kCFCalendarUnitSecond,
    NSWeekCalendarUnit = kCFCalendarUnitWeek,
    NSWeekdayCalendarUnit = kCFCalendarUnitWeekday,
    NSWeekdayOrdinalCalendarUnit = kCFCalendarUnitWeekdayOrdinal,
    NSQuarterCalendarUnit = kCFCalendarUnitQuarter,
    NSWeekOfMonthCalendarUnit = kCFCalendarUnitWeekOfMonth,
    NSWeekOfYearCalendarUnit = kCFCalendarUnitWeekOfYear,
    NSYearForWeekOfYearCalendarUnit = kCFCalendarUnitYearForWeekOfYear,
    NSCalendarCalendarUnit = (1 << 20),
    NSTimeZoneCalendarUnit = (1 << 21),
};

typedef NSUInteger NSCalendarOptions;
typedef NSUInteger NSCalendarUnit;

FOUNDATION_EXPORT NSString* const NSCalendarIdentifierGregorian;

FOUNDATION_EXPORT NSString* const NSCalendarIdentifierBuddhist;
FOUNDATION_EXPORT NSString* const NSCalendarIdentifierChinese;

FOUNDATION_EXPORT NSString* const NSCalendarIdentifierCoptic;
FOUNDATION_EXPORT NSString* const NSCalendarIdentifierEthiopicAmeteMihret;

FOUNDATION_EXPORT NSString* const NSCalendarIdentifierEthiopicAmeteAlem;
FOUNDATION_EXPORT NSString* const NSCalendarIdentifierHebrew;

FOUNDATION_EXPORT NSString* const NSCalendarIdentifierISO8601;
FOUNDATION_EXPORT NSString* const NSCalendarIdentifierIndian;

FOUNDATION_EXPORT NSString* const NSCalendarIdentifierIslamic;
FOUNDATION_EXPORT NSString* const NSCalendarIdentifierIslamicCivil;

FOUNDATION_EXPORT NSString* const NSCalendarIdentifierJapanese;
FOUNDATION_EXPORT NSString* const NSCalendarIdentifierPersian;

FOUNDATION_EXPORT NSString* const NSCalendarIdentifierRepublicOfChina;
FOUNDATION_EXPORT NSString* const NSCalendarIdentifierIslamicTabular;

FOUNDATION_EXPORT NSString* const NSCalendarIdentifierIslamicUmmAlQura;
FOUNDATION_EXPORT NSString* const NSCalendarDayChangedNotification;

enum { NSDateComponentUndefined = NSIntegerMax, NSUndefinedDateComponent = NSDateComponentUndefined };

FOUNDATION_EXPORT_CLASS
@interface NSCalendar : NSObject <NSCopying, NSSecureCoding>
+ (NSCalendar*)currentCalendar;
+ (NSCalendar*)autoupdatingCurrentCalendar STUB_METHOD;
+ (NSCalendar*)calendarWithIdentifier:(NSString*)calendarIdentifierConstant;
- (id)initWithCalendarIdentifier:(NSString*)string;
@property (readonly, copy) NSString* calendarIdentifier;
@property NSUInteger firstWeekday;
@property (copy) NSLocale* locale;
- (NSRange)maximumRangeOfUnit:(NSCalendarUnit)unit;
@property NSUInteger minimumDaysInFirstWeek;
- (NSRange)minimumRangeOfUnit:(NSCalendarUnit)unit;
- (NSUInteger)ordinalityOfUnit:(NSCalendarUnit)smaller inUnit:(NSCalendarUnit)larger forDate:(NSDate*)date;
- (NSRange)rangeOfUnit:(NSCalendarUnit)smaller inUnit:(NSCalendarUnit)larger forDate:(NSDate*)date;
- (BOOL)rangeOfUnit:(NSCalendarUnit)unit startDate:(NSDate* _Nullable*)datep interval:(NSTimeInterval*)tip forDate:(NSDate*)date;
- (BOOL)rangeOfWeekendStartDate:(NSDate* _Nullable*)datep interval:(NSTimeInterval*)tip containingDate:(NSDate*)date STUB_METHOD;
@property (copy) NSTimeZone* timeZone;
- (NSDate*)dateByAddingComponents:(NSDateComponents*)comps toDate:(NSDate*)date options:(NSCalendarOptions)opts;
- (NSDate*)dateByAddingUnit:(NSCalendarUnit)unit value:(NSInteger)value toDate:(NSDate*)date options:(NSCalendarOptions)options;
- (NSDate*)dateFromComponents:(NSDateComponents*)comps;
- (void)enumerateDatesStartingAfterDate:(NSDate*)start
                     matchingComponents:(NSDateComponents*)comps
                                options:(NSCalendarOptions)opts
                             usingBlock:(void (^)(NSDate*, BOOL, BOOL*))block STUB_METHOD;
- (NSDate*)dateBySettingHour:(NSInteger)h
                      minute:(NSInteger)m
                      second:(NSInteger)s
                      ofDate:(NSDate*)date
                     options:(NSCalendarOptions)opts STUB_METHOD;
- (NSDate*)dateBySettingUnit:(NSCalendarUnit)unit value:(NSInteger)v ofDate:(NSDate*)date options:(NSCalendarOptions)opts STUB_METHOD;
- (NSDate*)dateWithEra:(NSInteger)eraValue
                  year:(NSInteger)yearValue
                 month:(NSInteger)monthValue
                   day:(NSInteger)dayValue
                  hour:(NSInteger)hourValue
                minute:(NSInteger)minuteValue
                second:(NSInteger)secondValue
            nanosecond:(NSInteger)nanosecondValue STUB_METHOD;

- (NSDate*)dateWithEra:(NSInteger)eraValue
     yearForWeekOfYear:(NSInteger)yearValue
            weekOfYear:(NSInteger)weekValue
               weekday:(NSInteger)weekdayValue
                  hour:(NSInteger)hourValue
                minute:(NSInteger)minuteValue
                second:(NSInteger)secondValue
            nanosecond:(NSInteger)nanosecondValue STUB_METHOD;

- (BOOL)date:(NSDate*)date matchesComponents:(NSDateComponents*)comps STUB_METHOD;
- (NSDate*)nextDateAfterDate:(NSDate*)date matchingComponents:(NSDateComponents*)comps options:(NSCalendarOptions)options STUB_METHOD;
- (NSDate*)nextDateAfterDate:(NSDate*)date
                matchingHour:(NSInteger)hourValue
                      minute:(NSInteger)minuteValue
                      second:(NSInteger)secondValue
                     options:(NSCalendarOptions)options STUB_METHOD;
- (NSDate*)nextDateAfterDate:(NSDate*)date
                matchingUnit:(NSCalendarUnit)unit
                       value:(NSInteger)value
                     options:(NSCalendarOptions)options STUB_METHOD;
- (BOOL)nextWeekendStartDate:(NSDate* _Nullable*)datep
                    interval:(NSTimeInterval*)tip
                     options:(NSCalendarOptions)options
                   afterDate:(NSDate*)date STUB_METHOD;
- (NSDate*)startOfDayForDate:(NSDate*)date STUB_METHOD;
- (NSComparisonResult)compareDate:(NSDate*)date1 toDate:(NSDate*)date2 toUnitGranularity:(NSCalendarUnit)unit STUB_METHOD;
- (BOOL)isDate:(NSDate*)date1 equalToDate:(NSDate*)date2 toUnitGranularity:(NSCalendarUnit)unit STUB_METHOD;
- (BOOL)isDate:(NSDate*)date1 inSameDayAsDate:(NSDate*)date2 STUB_METHOD;
- (BOOL)isDateInToday:(NSDate*)date STUB_METHOD;
- (BOOL)isDateInTomorrow:(NSDate*)date STUB_METHOD;
- (BOOL)isDateInWeekend:(NSDate*)date STUB_METHOD;
- (BOOL)isDateInYesterday:(NSDate*)date STUB_METHOD;
- (NSInteger)component:(NSCalendarUnit)unit fromDate:(NSDate*)date STUB_METHOD;
- (NSDateComponents*)components:(NSCalendarUnit)unitFlags fromDate:(NSDate*)date;
- (NSDateComponents*)components:(NSCalendarUnit)unitFlags
                       fromDate:(NSDate*)startingDate
                         toDate:(NSDate*)resultDate
                        options:(NSCalendarOptions)options;
- (NSDateComponents*)components:(NSCalendarUnit)unitFlags
             fromDateComponents:(NSDateComponents*)startingDateComp
               toDateComponents:(NSDateComponents*)resultDateComp
                        options:(NSCalendarOptions)options STUB_METHOD;
- (NSDateComponents*)componentsInTimeZone:(NSTimeZone*)timezone fromDate:(NSDate*)date STUB_METHOD;
- (void)getEra:(NSInteger*)eraValuePointer
          year:(NSInteger*)yearValuePointer
         month:(NSInteger*)monthValuePointer
           day:(NSInteger*)dayValuePointer
      fromDate:(NSDate*)date STUB_METHOD;
- (void)getEra:(NSInteger*)eraValuePointer
    yearForWeekOfYear:(NSInteger*)yearValuePointer
           weekOfYear:(NSInteger*)weekValuePointer
              weekday:(NSInteger*)weekdayValuePointer
             fromDate:(NSDate*)date STUB_METHOD;
- (void)getHour:(NSInteger*)hourValuePointer
         minute:(NSInteger*)minuteValuePointer
         second:(NSInteger*)secondValuePointer
     nanosecond:(NSInteger*)nanosecondValuePointer
       fromDate:(NSDate*)date STUB_METHOD;
@property (readonly, copy) NSString* AMSymbol;
@property (readonly, copy) NSString* PMSymbol;
@property (readonly, copy) NSArray* weekdaySymbols;
@property (readonly, copy) NSArray* shortWeekdaySymbols;
@property (readonly, copy) NSArray* veryShortWeekdaySymbols;
@property (readonly, copy) NSArray* standaloneWeekdaySymbols;
@property (readonly, copy) NSArray* shortStandaloneWeekdaySymbols;
@property (readonly, copy) NSArray* veryShortStandaloneWeekdaySymbols;
@property (readonly, copy) NSArray* monthSymbols;
@property (readonly, copy) NSArray* shortMonthSymbols;
@property (readonly, copy) NSArray* veryShortMonthSymbols;
@property (readonly, copy) NSArray* standaloneMonthSymbols;
@property (readonly, copy) NSArray* shortStandaloneMonthSymbols;
@property (readonly, copy) NSArray* veryShortStandaloneMonthSymbols;
@property (readonly, copy) NSArray* quarterSymbols;
@property (readonly, copy) NSArray* shortQuarterSymbols;
@property (readonly, copy) NSArray* standaloneQuarterSymbols;
@property (readonly, copy) NSArray* shortStandaloneQuarterSymbols;
@property (readonly, copy) NSArray* eraSymbols;
@property (readonly, copy) NSArray* longEraSymbols;
@end
