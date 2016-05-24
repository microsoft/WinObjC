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

#include "Starboard.h"
#include "StubReturn.h"

#include <CoreFoundation/CFCalendar.h>
#include <CoreFoundation/CFDateFormatter.h>
#include <Foundation/NSDate.h>
#include <Foundation/NSString.h>
#include <Foundation/NSCalendar.h>
#include "NSTimeZoneInternal.h"
#include "NSLocaleInternal.h"

#include "LoggingNative.h"
#include "BridgeHelpers.h"
#include "NSRaise.h"
#include "NSCFCalendar.h"

NSString* const NSCalendarIdentifierGregorian = @"gregorian";
NSString* const NSCalendarIdentifierBuddhist = @"buddhist";
NSString* const NSCalendarIdentifierChinese = @"chinese";
NSString* const NSCalendarIdentifierCoptic = @"coptic";
NSString* const NSCalendarIdentifierEthiopicAmeteMihret = @"ethiopic";
NSString* const NSCalendarIdentifierEthiopicAmeteAlem = @"ethiopic-amete-alem";
NSString* const NSCalendarIdentifierHebrew = @"hebrew";
NSString* const NSCalendarIdentifierISO8601 = @"iso8601";
NSString* const NSCalendarIdentifierIndian = @"indian";
NSString* const NSCalendarIdentifierIslamic = @"islamic";
NSString* const NSCalendarIdentifierIslamicCivil = @"islamic-civil";
NSString* const NSCalendarIdentifierJapanese = @"japanese";
NSString* const NSCalendarIdentifierPersian = @"persian";
NSString* const NSCalendarIdentifierRepublicOfChina = @"roc";
NSString* const NSCalendarIdentifierIslamicTabular = @"islamic-tbla";
NSString* const NSCalendarIdentifierIslamicUmmAlQura = @"islamic-umalqura";
NSString* const NSCalendarDayChangedNotification = @"NSCalendarDayChangedNotification";

static NSArray* _getFormatterSymbols(NSCalendar* self, NSLocale* locale, CFStringRef keyName) {
    woc::unique_cf<CFDateFormatterRef> dateFormatter(CFDateFormatterCreate(kCFAllocatorSystemDefault,
                                                                           static_cast<CFLocaleRef>(locale),
                                                                           kCFDateFormatterNoStyle,
                                                                           kCFDateFormatterNoStyle));
    CFDateFormatterSetProperty(dateFormatter.get(), kCFDateFormatterCalendar, static_cast<CFCalendarRef>(self));
    return static_cast<NSArray*>(CFAutorelease(CFDateFormatterCopyProperty(dateFormatter.get(), keyName)));
}

static NSString* _getFormatterSymbol(NSCalendar* self, NSLocale* locale, CFStringRef keyName) {
    woc::unique_cf<CFDateFormatterRef> dateFormatter(CFDateFormatterCreate(kCFAllocatorSystemDefault,
                                                                           static_cast<CFLocaleRef>(locale),
                                                                           kCFDateFormatterNoStyle,
                                                                           kCFDateFormatterNoStyle));
    CFDateFormatterSetProperty(dateFormatter.get(), kCFDateFormatterCalendar, static_cast<CFCalendarRef>(self));
    return static_cast<NSString*>(CFAutorelease(CFDateFormatterCopyProperty(dateFormatter.get(), keyName)));
}

@implementation NSCalendar

+ ALLOC_PROTOTYPE_SUBCLASS_WITH_ZONE(NSCalendar, NSCalendarPrototype);

/**
 @Status Interoperable
*/
- (instancetype)copyWithZone:(NSZone*)zone {
    NSCalendar* result = [[NSCalendar alloc] initWithCalendarIdentifier:self.calendarIdentifier];
    result.locale = self.locale;
    result.timeZone = self.timeZone;
    result.firstWeekday = self.firstWeekday;
    result.minimumDaysInFirstWeek = self.minimumDaysInFirstWeek;

    return result;
}

/**
 @Status Interoperable
*/
+ (NSCalendar*)currentCalendar {
    return [static_cast<NSCalendar*>(CFCalendarCopyCurrent()) autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCalendarIdentifier:(NSString*)identifier {
    // Derived classes are required to implement this initializer.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSString*)calendarIdentifier {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSUInteger)firstWeekday {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSUInteger)minimumDaysInFirstWeek {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSTimeZone*)timeZone {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSLocale*)locale {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (void)setFirstWeekday:(NSUInteger)weekday {
    return NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
- (void)setMinimumDaysInFirstWeek:(NSUInteger)days {
    return NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
- (void)setTimeZone:(NSTimeZone*)timeZone {
    return NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
- (void)setLocale:(NSLocale*)locale {
    return NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
- (NSDate*)dateByAddingComponents:(NSDateComponents*)components toDate:(NSDate*)toDate options:(NSUInteger)options {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSDate*)dateFromComponents:(NSDateComponents*)components {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSDateComponents*)components:(NSUInteger)unitFlags fromDate:(NSDate*)date {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSUInteger)ordinalityOfUnit:(NSCalendarUnit)inUnit inUnit:(NSCalendarUnit)larger forDate:(NSDate*)date {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSDateComponents*)components:(NSUInteger)unitFlags fromDate:(NSDate*)fromDate toDate:(NSDate*)toDate options:(NSUInteger)options {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (BOOL)rangeOfUnit:(NSCalendarUnit)unit startDate:(NSDate* _Nullable*)datep interval:(NSTimeInterval*)timep forDate:(NSDate*)date {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSRange)rangeOfUnit:(NSCalendarUnit)smaller inUnit:(NSCalendarUnit)larger forDate:(NSDate*)date {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
 @Notes
*/
- (NSRange)maximumRangeOfUnit:(NSCalendarUnit)unit {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
 @Notes
*/
- (NSRange)minimumRangeOfUnit:(NSCalendarUnit)unit {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)rangeOfWeekendStartDate:(NSDate* _Nullable*)datep interval:(NSTimeInterval*)tip containingDate:(NSDate*)date {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSDate*)dateByAddingUnit:(NSCalendarUnit)unit value:(NSInteger)value toDate:(NSDate*)date options:(NSCalendarOptions)options {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)enumerateDatesStartingAfterDate:(NSDate*)start
                     matchingComponents:(NSDateComponents*)comps
                                options:(NSCalendarOptions)opts
                             usingBlock:(void (^)(NSDate*, BOOL, BOOL*))block {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (NSDate*)dateBySettingHour:(NSInteger)h minute:(NSInteger)m second:(NSInteger)s ofDate:(NSDate*)date options:(NSCalendarOptions)opts {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSDate*)dateBySettingUnit:(NSCalendarUnit)unit value:(NSInteger)v ofDate:(NSDate*)date options:(NSCalendarOptions)opts {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSDate*)dateWithEra:(NSInteger)eraValue
                  year:(NSInteger)yearValue
                 month:(NSInteger)monthValue
                   day:(NSInteger)dayValue
                  hour:(NSInteger)hourValue
                minute:(NSInteger)minuteValue
                second:(NSInteger)secondValue
            nanosecond:(NSInteger)nanosecondValue {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSDate*)dateWithEra:(NSInteger)eraValue
     yearForWeekOfYear:(NSInteger)yearValue
            weekOfYear:(NSInteger)weekValue
               weekday:(NSInteger)weekdayValue
                  hour:(NSInteger)hourValue
                minute:(NSInteger)minuteValue
                second:(NSInteger)secondValue
            nanosecond:(NSInteger)nanosecondValue {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)date:(NSDate*)date matchesComponents:(NSDateComponents*)comps {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSDate*)nextDateAfterDate:(NSDate*)date matchingComponents:(NSDateComponents*)comps options:(NSCalendarOptions)options {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSDate*)nextDateAfterDate:(NSDate*)date
                matchingHour:(NSInteger)hourValue
                      minute:(NSInteger)minuteValue
                      second:(NSInteger)secondValue
                     options:(NSCalendarOptions)options {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSDate*)nextDateAfterDate:(NSDate*)date matchingUnit:(NSCalendarUnit)unit value:(NSInteger)value options:(NSCalendarOptions)options {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)nextWeekendStartDate:(NSDate* _Nullable*)datep
                    interval:(NSTimeInterval*)tip
                     options:(NSCalendarOptions)options
                   afterDate:(NSDate*)date {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)isDateInToday:(NSDate*)date {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSDate*)startOfDayForDate:(NSDate*)date {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSComparisonResult)compareDate:(NSDate*)date1 toDate:(NSDate*)date2 toUnitGranularity:(NSCalendarUnit)unit {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)isDate:(NSDate*)date1 equalToDate:(NSDate*)date2 toUnitGranularity:(NSCalendarUnit)unit {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)isDate:(NSDate*)date1 inSameDayAsDate:(NSDate*)date2 {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)isDateInTomorrow:(NSDate*)date {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)isDateInWeekend:(NSDate*)date {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)isDateInYesterday:(NSDate*)date {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)getEra:(NSInteger*)eraValuePointer
          year:(NSInteger*)yearValuePointer
         month:(NSInteger*)monthValuePointer
           day:(NSInteger*)dayValuePointer
      fromDate:(NSDate*)date {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)getEra:(NSInteger*)eraValuePointer
    yearForWeekOfYear:(NSInteger*)yearValuePointer
           weekOfYear:(NSInteger*)weekValuePointer
              weekday:(NSInteger*)weekdayValuePointer
             fromDate:(NSDate*)date {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (NSInteger)component:(NSCalendarUnit)unit fromDate:(NSDate*)date {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSDateComponents*)components:(NSCalendarUnit)unitFlags
             fromDateComponents:(NSDateComponents*)startingDateComp
               toDateComponents:(NSDateComponents*)resultDateComp
                        options:(NSCalendarOptions)options {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSDateComponents*)componentsInTimeZone:(NSTimeZone*)timezone fromDate:(NSDate*)date {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)getHour:(NSInteger*)hourValuePointer
         minute:(NSInteger*)minuteValuePointer
         second:(NSInteger*)secondValuePointer
     nanosecond:(NSInteger*)nanosecondValuePointer
       fromDate:(NSDate*)date {
    UNIMPLEMENTED();
}
/**
 @Status Stub
 @Notes
*/
+ (NSCalendar*)autoupdatingCurrentCalendar {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
 @Notes
*/
+ (NSCalendar*)calendarWithIdentifier:(NSString*)calendarIdentifierConstant {
    return [[[NSCalendar alloc] initWithCalendarIdentifier:calendarIdentifierConstant] autorelease];
}

/**
 @Status Stub
 @Notes
*/
+ (BOOL)supportsSecureCoding {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (id)initWithCoder:(NSCoder*)decoder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)encodeWithCoder:(NSCoder*)coder {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
 @Public No
 @Notes CF needs these to exist for derived implementations
*/
- (NSLocale*)_copyLocale {
    return [self.locale copy];
}

/**
 @Status Interoperable
 @Public No
 @Notes CF needs these to exist for derived implementations
*/
- (NSTimeZone*)_copyTimeZone {
    return [self.timeZone copy];
}

/**
 @Status Interoperable
*/
- (NSString*)AMSymbol {
    return _getFormatterSymbol(self, [self locale], kCFDateFormatterAMSymbol);
}

/**
 @Status Interoperable
*/
- (NSString*)PMSymbol {
    return _getFormatterSymbol(self, [self locale], kCFDateFormatterPMSymbol);
}

/**
 @Status Interoperable
*/
- (NSArray*)weekdaySymbols {
    return _getFormatterSymbols(self, [self locale], kCFDateFormatterWeekdaySymbols);
}

/**
 @Status Interoperable
*/
- (NSArray*)shortWeekdaySymbols {
    return _getFormatterSymbols(self, [self locale], kCFDateFormatterShortWeekdaySymbols);
}

/**
 @Status Interoperable
*/
- (NSArray*)veryShortWeekdaySymbols {
    return _getFormatterSymbols(self, [self locale], kCFDateFormatterVeryShortWeekdaySymbols);
}

/**
 @Status Interoperable
*/
- (NSArray*)standaloneWeekdaySymbols {
    return _getFormatterSymbols(self, [self locale], kCFDateFormatterStandaloneWeekdaySymbols);
}

/**
 @Status Interoperable
*/
- (NSArray*)shortStandaloneWeekdaySymbols {
    return _getFormatterSymbols(self, [self locale], kCFDateFormatterShortStandaloneWeekdaySymbols);
}

/**
 @Status Interoperable
*/
- (NSArray*)veryShortStandaloneWeekdaySymbols {
    return _getFormatterSymbols(self, [self locale], kCFDateFormatterVeryShortStandaloneWeekdaySymbols);
}

/**
 @Status Interoperable
*/
- (NSArray*)monthSymbols {
    return _getFormatterSymbols(self, [self locale], kCFDateFormatterMonthSymbols);
}

/**
 @Status Interoperable
*/
- (NSArray*)shortMonthSymbols {
    return _getFormatterSymbols(self, [self locale], kCFDateFormatterShortMonthSymbols);
}

/**
 @Status Interoperable
*/
- (NSArray*)veryShortMonthSymbols {
    return _getFormatterSymbols(self, [self locale], kCFDateFormatterVeryShortMonthSymbols);
}

/**
 @Status Interoperable
*/
- (NSArray*)standaloneMonthSymbols {
    return _getFormatterSymbols(self, [self locale], kCFDateFormatterStandaloneMonthSymbols);
}

/**
 @Status Interoperable
*/
- (NSArray*)shortStandaloneMonthSymbols {
    return _getFormatterSymbols(self, [self locale], kCFDateFormatterShortStandaloneMonthSymbols);
}

/**
 @Status Interoperable
*/
- (NSArray*)veryShortStandaloneMonthSymbols {
    return _getFormatterSymbols(self, [self locale], kCFDateFormatterVeryShortStandaloneMonthSymbols);
}

/**
 @Status Interoperable
*/
- (NSArray*)quarterSymbols {
    return _getFormatterSymbols(self, [self locale], kCFDateFormatterQuarterSymbols);
}

/**
 @Status Interoperable
*/
- (NSArray*)shortQuarterSymbols {
    return _getFormatterSymbols(self, [self locale], kCFDateFormatterShortQuarterSymbols);
}

/**
 @Status Interoperable
*/
- (NSArray*)standaloneQuarterSymbols {
    return _getFormatterSymbols(self, [self locale], kCFDateFormatterStandaloneQuarterSymbols);
}

/**
 @Status Interoperable
*/
- (NSArray*)shortStandaloneQuarterSymbols {
    return _getFormatterSymbols(self, [self locale], kCFDateFormatterShortStandaloneQuarterSymbols);
}

/**
 @Status Interoperable
*/
- (NSArray*)eraSymbols {
    return _getFormatterSymbols(self, [self locale], kCFDateFormatterEraSymbols);
}

/**
 @Status Interoperable
*/
- (NSArray*)longEraSymbols {
    return _getFormatterSymbols(self, [self locale], kCFDateFormatterLongEraSymbols);
}

@end
