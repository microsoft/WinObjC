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
#include "Foundation/NSDate.h"
#include "Foundation/NSString.h"
#include "Foundation/NSCalendar.h"
#include "NSCalendarInternal.h"
#include "NSTimeZoneInternal.h"
#include "NSLocaleInternal.h"

#include <unicode/gregocal.h>
#include "LoggingNative.h"

static const wchar_t* TAG = L"NSCalendar";

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

@implementation NSCalendar {
    NSString* _identifier;
    NSTimeZone* _timeZone;
    NSLocale* _locale;
    NSUInteger firstWeekDay, minimumDaysInFirstWeek;
    BOOL firstWeekDaySet, minimumDaysInFirstWeekSet;
    icu::Calendar* _cal;
    BOOL _calendarNeedsRebuilding;
}
- (icu::Calendar*)_getICUCalendar {
    if (_cal == NULL || _calendarNeedsRebuilding) {
        _calendarNeedsRebuilding = FALSE;
        if (_cal)
            delete _cal;

        UErrorCode status = U_ZERO_ERROR;
        icu::Locale* locale = [_locale _createICULocale];
        icu::TimeZone* timeZone = [_timeZone _createICUTimeZone];

        //  No need to delete timeZone - GregorianCalendar adopts it
        _cal = GregorianCalendar::createInstance(timeZone, *locale, status);
        delete locale;

        if (firstWeekDaySet) {
            _cal->setFirstDayOfWeek((UCalendarDaysOfWeek)firstWeekDay);
        }

        if (minimumDaysInFirstWeekSet) {
            _cal->setMinimalDaysInFirstWeek(minimumDaysInFirstWeek);
        }
    }

    return _cal;
}

/**
 @Status Interoperable
*/
- (instancetype)copyWithZone:(NSZone*)zone {
    NSCalendar* result = [NSCalendar alloc];

    result->_identifier = [_identifier copy];
    result->_timeZone = [_timeZone copy];
    result->_locale = [_locale copy];

    return result;
}

- (icu::Calendar*)_createICUCalendar {
    return [self _getICUCalendar]->clone();
}

/**
 @Status Caveat
 @Notes Always returns a gregorian calendar
*/
+ (NSCalendar*)currentCalendar {
    return [[[self alloc] initWithCalendarIdentifier:@"NSGregorianCalendar"] autorelease];
}

/**
 @Status Caveat
 @Notes Identifier parameter unused; always returns Gregorian calendar
*/
- (instancetype)initWithCalendarIdentifier:(NSString*)identifier {
    _identifier = [identifier copy];
    _timeZone = [[NSTimeZone defaultTimeZone] copy];
    _locale = [[NSLocale currentLocale] retain];
    return self;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    [_identifier release];
    [_timeZone release];
    [_locale release];
    if (_cal)
        delete _cal;

    [super dealloc];
}

/**
 @Status Interoperable
*/
- (NSString*)calendarIdentifier {
    return _identifier;
}

/**
 @Status Interoperable
*/
- (NSUInteger)firstWeekday {
    return (NSUInteger)[self _getICUCalendar]->getFirstDayOfWeek();
}

/**
 @Status Interoperable
*/
- (NSUInteger)minimumDaysInFirstWeek {
    return (NSUInteger)[self _getICUCalendar]->getMinimalDaysInFirstWeek();
}

/**
 @Status Interoperable
*/
- (NSTimeZone*)timeZone {
    return _timeZone;
}

/**
 @Status Interoperable
*/
- (NSLocale*)locale {
    return _locale;
}

/**
 @Status Interoperable
*/
- (void)setFirstWeekday:(NSUInteger)weekday {
    firstWeekDay = weekday;
    firstWeekDaySet = TRUE;
    _calendarNeedsRebuilding = TRUE;
}

/**
 @Status Interoperable
*/
- (void)setMinimumDaysInFirstWeek:(NSUInteger)days {
    minimumDaysInFirstWeek = days;
    minimumDaysInFirstWeekSet = TRUE;
    _calendarNeedsRebuilding = TRUE;
}

/**
 @Status Interoperable
*/
- (void)setTimeZone:(NSTimeZone*)timeZone {
    timeZone = [timeZone copy];
    [_timeZone release];
    _timeZone = timeZone;
    _calendarNeedsRebuilding = TRUE;
}

/**
 @Status Interoperable
*/
- (void)setLocale:(NSLocale*)locale {
    locale = [locale copy];
    [_locale release];
    _locale = locale;
    _calendarNeedsRebuilding = TRUE;
}

/**
 @Status Caveat
 @Notes options parameter not supported
*/
- (NSDate*)dateByAddingComponents:(NSDateComponents*)components toDate:(NSDate*)toDate options:(NSUInteger)options {
    double time = [toDate timeIntervalSince1970];

    UErrorCode status = U_ZERO_ERROR;
    Calendar* copy = [self _getICUCalendar]->clone();
    copy->setTime(time * 1000.0, status);

    NSInteger check;

    if ((check = [components year]) != NSUndefinedDateComponent) {
        copy->add(UCAL_YEAR, check, status);
    }
    if ((check = [components month]) != NSUndefinedDateComponent) {
        copy->add(UCAL_MONTH, check, status);
    }
    if ((check = [components day]) != NSUndefinedDateComponent) {
        copy->add(UCAL_DATE, check, status);
    }
    if ((check = [components hour]) != NSUndefinedDateComponent) {
        copy->add(UCAL_HOUR, check, status);
    }
    if ((check = [components minute]) != NSUndefinedDateComponent) {
        copy->add(UCAL_MINUTE, check, status);
    }
    if ((check = [components second]) != NSUndefinedDateComponent) {
        copy->add(UCAL_SECOND, check, status);
    }
    if ((check = [components week]) != NSUndefinedDateComponent) {
        copy->add(UCAL_WEEK_OF_YEAR, check, status);
    }
    if ((check = [components weekday]) != NSUndefinedDateComponent) {
        copy->add(UCAL_DAY_OF_WEEK, check, status);
    }

    id ret = nil;

    if (U_SUCCESS(status)) {
        UDate unixTime = copy->getTime(status) / 1000.;

        if (U_SUCCESS(status)) {
            ret = [NSDate dateWithTimeIntervalSince1970:unixTime];
        }
    }
    delete copy;

    return ret;
}

static Calendar* calendarCopyWithTZ(NSCalendar* self) {
    UErrorCode status = U_ZERO_ERROR;
    Calendar* copy = [self _getICUCalendar]->clone();
    if (self->_timeZone != nil) {
        icu::TimeZone* tz = [self->_timeZone _createICUTimeZone];
        copy->setTimeZone(*tz);
        delete tz;
    }

    return copy;
}

static Calendar* calendarCopyWithTZAndDate(NSCalendar* self, NSDate* date) {
    UErrorCode status = U_ZERO_ERROR;
    Calendar* copy = [self _getICUCalendar]->clone();
    copy->setTime([date timeIntervalSince1970] * 1000.0, status);
    if (U_SUCCESS(status)) {
        if (self->_timeZone != nil) {
            icu::TimeZone* tz = [self->_timeZone _createICUTimeZone];
            copy->setTimeZone(*tz);
            delete tz;
        }

        return copy;
    } else {
        delete copy;
        return NULL;
    }
}

/**
 @Status Interoperable
*/
- (NSDate*)dateFromComponents:(NSDateComponents*)components {
    NSInteger check;

    UErrorCode status = U_ZERO_ERROR;
    Calendar* copy = [self _getICUCalendar]->clone();
    copy->clear();

    if ((check = [components year]) != NSUndefinedDateComponent)
        copy->set(UCAL_YEAR, check);
    if ((check = [components month]) != NSUndefinedDateComponent)
        copy->set(UCAL_MONTH, check - 1);
    if ((check = [components day]) != NSUndefinedDateComponent)
        copy->set(UCAL_DAY_OF_MONTH, check);
    if ((check = [components hour]) != NSUndefinedDateComponent)
        copy->set(UCAL_HOUR_OF_DAY, check);
    if ((check = [components minute]) != NSUndefinedDateComponent)
        copy->set(UCAL_MINUTE, check);
    if ((check = [components second]) != NSUndefinedDateComponent)
        copy->set(UCAL_SECOND, check);
    if ((check = [components week]) != NSUndefinedDateComponent)
        copy->set(UCAL_WEEK_OF_YEAR, check);
    if ((check = [components weekday]) != NSUndefinedDateComponent)
        copy->set(UCAL_DAY_OF_WEEK, check);

    if ([components timeZone] != nil) {
        icu::TimeZone* tz = [[components timeZone] _createICUTimeZone];
        copy->setTimeZone(*tz);
        delete tz;
    }

    id ret = nil;

    if (U_SUCCESS(status)) {
        UDate unixTime = copy->getTime(status) / 1000.;

        if (U_SUCCESS(status)) {
            ret = [NSDate dateWithTimeIntervalSince1970:unixTime];
        }
    }
    delete copy;

    return ret;
}

/**
 @Status Interoperable
*/
- (NSDateComponents*)components:(NSUInteger)unitFlags fromDate:(NSDate*)date {
    double time = [date timeIntervalSince1970];

    UErrorCode status = U_ZERO_ERROR;
    Calendar* copy = calendarCopyWithTZAndDate(self, date);

    NSDateComponents* ret = nil;
    if (copy) {
        ret = [NSDateComponents new];
        if (unitFlags & NSDayCalendarUnit)
            [ret setDay:copy->get(UCAL_DATE, status)];
        if (unitFlags & NSMonthCalendarUnit)
            [ret setMonth:copy->get(UCAL_MONTH, status) + 1];
        if (unitFlags & NSYearCalendarUnit)
            [ret setYear:copy->get(UCAL_YEAR, status)];
        if (unitFlags & NSSecondCalendarUnit)
            [ret setSecond:copy->get(UCAL_SECOND, status)];
        if (unitFlags & NSMinuteCalendarUnit)
            [ret setMinute:copy->get(UCAL_MINUTE, status)];
        if (unitFlags & NSHourCalendarUnit)
            [ret setHour:copy->get(UCAL_HOUR_OF_DAY, status)];
        if (unitFlags & NSWeekdayCalendarUnit)
            [ret setWeekday:copy->get(UCAL_DAY_OF_WEEK, status)];
        delete copy;
    }

    return [ret autorelease];
}

/**
 @Status Stub
*/
- (NSUInteger)ordinalityOfUnit:(NSCalendarUnit)inUnit inUnit:(NSCalendarUnit)larger forDate:(NSDate*)date {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
 @Notes options parameter not supported
*/
- (NSDateComponents*)components:(NSUInteger)unitFlags fromDate:(NSDate*)fromDate toDate:(NSDate*)toDate options:(NSUInteger)options {
    UErrorCode status = U_ZERO_ERROR;
    Calendar* copy = calendarCopyWithTZAndDate(self, fromDate);
    UDate toDateICU = (double)[toDate timeIntervalSince1970] * 1000.0;

    NSDateComponents* ret = nil;
    if (copy) {
        ret = [NSDateComponents new];

        if (unitFlags & NSYearCalendarUnit)
            [ret setYear:copy->fieldDifference(toDateICU, UCAL_YEAR, status)];
        if (unitFlags & NSMonthCalendarUnit)
            [ret setMonth:copy->fieldDifference(toDateICU, UCAL_MONTH, status)];
        if (unitFlags & NSDayCalendarUnit)
            [ret setDay:copy->fieldDifference(toDateICU, UCAL_DATE, status)];
        if (unitFlags & NSHourCalendarUnit)
            [ret setHour:copy->fieldDifference(toDateICU, UCAL_HOUR_OF_DAY, status)];
        if (unitFlags & NSMinuteCalendarUnit)
            [ret setMinute:copy->fieldDifference(toDateICU, UCAL_MINUTE, status)];
        if (unitFlags & NSSecondCalendarUnit)
            [ret setSecond:copy->fieldDifference(toDateICU, UCAL_SECOND, status)];

        delete copy;
    }

    return [ret autorelease];
}

/**
 @Status Stub
*/
- (BOOL)rangeOfUnit:(NSCalendarUnit)unit startDate:(NSDate* _Nullable*)datep interval:(NSTimeInterval*)timep forDate:(NSDate*)date {
    UNIMPLEMENTED();
    return StubReturn();
}

static UCalendarDateFields icuFieldFromUnit(NSCalendarUnit unit) {
    switch (unit) {
        case NSYearCalendarUnit:
            return UCAL_YEAR;

        case NSMonthCalendarUnit:
            return UCAL_MONTH;

        case NSDayCalendarUnit:
            return UCAL_DAY_OF_MONTH;

        case NSHourCalendarUnit:
            return UCAL_HOUR_OF_DAY;

        case NSMinuteCalendarUnit:
            return UCAL_MINUTE;

        case NSSecondCalendarUnit:
            return UCAL_SECOND;

        case NSWeekCalendarUnit:
            return UCAL_WEEK_OF_YEAR;

        case NSWeekdayCalendarUnit:
            return UCAL_DAY_OF_WEEK;

        default:
            assert(0);
            return UCAL_DAY_OF_MONTH;
    }
}

/**
 @Status Stub
*/
- (NSRange)rangeOfUnit:(NSCalendarUnit)smaller inUnit:(NSCalendarUnit)larger forDate:(NSDate*)date {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSRange)maximumRangeOfUnit:(NSCalendarUnit)unit {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSRange)minimumRangeOfUnit:(NSCalendarUnit)unit {
    UNIMPLEMENTED();
    return StubReturn();
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
 @Status Stub
 @Notes
*/
+ (NSCalendar*)calendarWithIdentifier:(NSString*)calendarIdentifierConstant {
    UNIMPLEMENTED();
    return StubReturn();
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

@end
