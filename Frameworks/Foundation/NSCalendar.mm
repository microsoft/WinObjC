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
#include "Foundation/NSDate.h"
#include "Foundation/NSString.h"
#include "Foundation/NSCalendar.h"
#include "NSCalendarInternal.h"
#include "NSTimeZoneInternal.h"
#include "NSLocaleInternal.h"

#include <unicode/gregocal.h>

NSString* const NSGregorianCalendar = @"NSGregorianCalendar";

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

- (void)dealloc {
    [_identifier release];
    [_timeZone release];
    [_locale release];
    if (_cal)
        delete _cal;

    [super dealloc];
}

/**
 @Status Stub
*/
- (NSString*)calendarIdentifier {
    UNIMPLEMENTED();
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
    EbrDebugLog("ordinalityOfUnit not supported\n");
    return 0;
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
- (BOOL)rangeOfUnit:(NSCalendarUnit)unit startDate:(NSDate**)datep interval:(NSTimeInterval*)timep forDate:(NSDate*)date {
    UNIMPLEMENTED();
    // HACK: implement me!
    *datep = [date retain];
    return NO;
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
    NSRange ret;

    double time = [date timeIntervalSince1970];

    UErrorCode status = U_ZERO_ERROR;
    Calendar* copy = [self _getICUCalendar]->clone();
    copy->setTime(time * 1000.0, status);

    icu::TimeZone* tz = [_timeZone _createICUTimeZone];
    copy->setTimeZone(*tz);
    delete tz;

    UCalendarDateFields icuSmaller = icuFieldFromUnit(smaller);
    ret.location = copy->getActualMinimum(icuSmaller, status);
    ret.length = copy->getActualMaximum(icuSmaller, status) - ret.location + 1;

    if (smaller == NSMonthCalendarUnit) {
        ret.location++;
    }
    delete copy;
    return ret;
}

@end
