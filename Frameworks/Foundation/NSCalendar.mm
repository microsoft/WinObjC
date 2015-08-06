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

#define U_STATIC_IMPLEMENTATION 1

#include <unicode/gregocal.h>

@implementation NSCalendar {
    NSString *_identifier;
    NSTimeZone *_timeZone;
    NSLocale *_locale;
    icu_48::Calendar *_cal;
}
    -(instancetype) copyWithZone:(NSZone*)zone {
        NSCalendar* result = [NSCalendar alloc];
   
        result->_identifier= [_identifier copy];
        result->_timeZone = [_timeZone copy];
        result->_locale = [_locale copy];
        result->_cal = _cal->clone();
   
        return result;
    }

    +(NSCalendar*) currentCalendar {
        return [[[self alloc] initWithCalendarIdentifier:@"NSGregorianCalendar"] autorelease];
    }

    -(instancetype) initWithCalendarIdentifier:(NSString*)identifier {
        _identifier= [identifier copy];
        _timeZone= [[NSTimeZone defaultTimeZone] copy];
        UErrorCode status = U_ZERO_ERROR;
        _cal = GregorianCalendar::createInstance(status);
        return self;
    }

    -(void) dealloc {
        [_identifier release];
        [_timeZone release];
        [_locale release];
        delete _cal;

        [super dealloc];
    }

    -(NSString*) calendarIdentifier {
        return _identifier;
    }

    -(NSUInteger) firstWeekday {
        return (NSUInteger) _cal->getFirstDayOfWeek();
    }

    -(NSUInteger) minimumDaysInFirstWeek {
        return (NSUInteger) _cal->getMinimalDaysInFirstWeek();
    }

    -(NSTimeZone*) timeZone {
        return _timeZone;
    }

    -(NSLocale*) locale {
        return _locale;
    }

    -(void) setFirstWeekday:(NSUInteger)weekday {
        _cal->setFirstDayOfWeek((UCalendarDaysOfWeek) weekday);
    }

    -(void) setMinimumDaysInFirstWeek:(NSUInteger)days {
        _cal->setMinimalDaysInFirstWeek(days);
    }

    -(void) setTimeZone:(NSTimeZone*)timeZone {
        timeZone = [timeZone retain];
        [_timeZone release];
        _timeZone=timeZone;
    }

    -(void) setLocale:(NSLocale*)locale {
        locale = [locale retain];
        [_locale release];
        _locale=locale;
    }

    -(NSDate*) dateByAddingComponents:(NSDateComponents*)components toDate:(NSDate*)toDate options:(NSUInteger)options {
        double time = [toDate timeIntervalSince1970];

        UErrorCode status = U_ZERO_ERROR;
        Calendar *copy = _cal->clone();
        copy->setTime(time * 1000.0, status);

        NSInteger check;

        if ( (check=[components year]) != NSUndefinedDateComponent ) {
            copy->add(UCAL_YEAR, check, status);
        }
        if ( (check=[components month]) != NSUndefinedDateComponent ) {
            copy->add(UCAL_MONTH, check, status);
        }
        if ( (check=[components day]) != NSUndefinedDateComponent ) {
            copy->add(UCAL_DATE, check, status);
        }
        if ( (check=[components hour]) != NSUndefinedDateComponent ) {
            copy->add(UCAL_HOUR, check, status);
        }
        if ( (check=[components minute])!= NSUndefinedDateComponent ) {
            copy->add(UCAL_MINUTE, check, status);
        }
        if ( (check=[components second]) != NSUndefinedDateComponent ) {
            copy->add(UCAL_SECOND, check, status);
        }
        if ( (check=[components week]) != NSUndefinedDateComponent ) {
            copy->add(UCAL_WEEK_OF_YEAR, check, status);
        }
        if ( (check=[components weekday]) != NSUndefinedDateComponent ) {
            copy->add(UCAL_DAY_OF_WEEK, check, status);
        }

        id ret = nil;

        if ( U_SUCCESS(status) ) {
            UDate unixTime = copy->getTime(status) / 1000.;

            if ( U_SUCCESS(status) ) {
                ret = [NSDate dateWithTimeIntervalSince1970:unixTime];
            }
        }
        delete copy;

        return ret;
    }

    -(NSDate*) dateFromComponents:(NSDateComponents*)components {
        NSInteger check;

        UErrorCode status = U_ZERO_ERROR;
        Calendar *copy = _cal->clone();
        icu::TimeZone* tz;
        [_timeZone _getICUTimezone:&tz];
        copy->setTimeZone(*tz);
        copy->clear();

        if ( (check=[components year]) != NSUndefinedDateComponent )
            copy->set(UCAL_YEAR, check);
        if ( (check=[components month]) != NSUndefinedDateComponent )
            copy->set(UCAL_MONTH, check - 1);
        if ( (check=[components day]) != NSUndefinedDateComponent )
            copy->set(UCAL_DAY_OF_MONTH, check);
        if ( (check=[components hour]) != NSUndefinedDateComponent )
            copy->set(UCAL_HOUR_OF_DAY, check);
        if ( (check=[components minute])!= NSUndefinedDateComponent )
            copy->set(UCAL_MINUTE, check);
        if ( (check=[components second]) != NSUndefinedDateComponent )
            copy->set(UCAL_SECOND, check);
        if ( (check=[components week]) != NSUndefinedDateComponent )
            copy->set(UCAL_WEEK_OF_YEAR, check);
        if ( (check=[components weekday]) != NSUndefinedDateComponent )
            copy->set(UCAL_DAY_OF_WEEK, check);
        id ret = nil;

        if ( U_SUCCESS(status) ) {
            UDate unixTime = copy->getTime(status) / 1000.;

            if ( U_SUCCESS(status) ) {
                ret = [NSDate dateWithTimeIntervalSince1970:unixTime];
            }
        }
        delete copy;

        return ret;
    }

    -(NSDateComponents*) components:(NSUInteger)unitFlags fromDate:(NSDate*)date {
        double time = [date timeIntervalSince1970];

        UErrorCode status = U_ZERO_ERROR;
        Calendar *copy = _cal->clone();
        copy->setTime(time * 1000.0, status);

        icu::TimeZone *tz;
        [_timeZone _getICUTimezone:&tz];
        copy->setTimeZone(*tz);

        id ret = nil;
        if ( U_SUCCESS(status) ) {
            ret = [NSDateComponents new];
            if ( unitFlags & NSDayCalendarUnit ) [ret setDay:copy->get(UCAL_DATE, status)];
            if ( unitFlags & NSMonthCalendarUnit ) [ret setMonth:copy->get(UCAL_MONTH, status) + 1];
            if ( unitFlags & NSYearCalendarUnit ) [ret setYear:copy->get(UCAL_YEAR, status)];
            if ( unitFlags & NSSecondCalendarUnit ) [ret setSecond:copy->get(UCAL_SECOND, status)];
            if ( unitFlags & NSMinuteCalendarUnit ) [ret setMinute:copy->get(UCAL_MINUTE, status)];
            if ( unitFlags & NSHourCalendarUnit ) [ret setHour:copy->get(UCAL_HOUR_OF_DAY, status)];
            if ( unitFlags & NSWeekdayCalendarUnit ) [ret setWeekday:copy->get(UCAL_DAY_OF_WEEK, status)];
        }
        delete copy;

        return [ret autorelease];
    }

    -(NSUInteger) ordinalityOfUnit:(NSCalendarUnit)inUnit inUnit:(NSCalendarUnit)larger forDate:(NSDate*)date {
        EbrDebugLog("ordinalityOfUnit not supported\n");
        return 0;
    }

    -(NSDateComponents*) components:(NSUInteger)unitFlags fromDate:(NSDate*)fromDate toDate:(NSDate*)toDate options:(NSUInteger)options {
        double time = [fromDate timeIntervalSince1970];
        double time2 = [toDate timeIntervalSince1970];

        double diff = time2 - time;
        id ret = nil;

        ret = [NSDateComponents new];

#define SECONDS_PER_MIN     (60.0)
#define SECONDS_PER_HOUR    (SECONDS_PER_MIN * 60.0)
#define SECONDS_PER_DAY     (SECONDS_PER_HOUR * 24.0)
#define SECONDS_PER_WEEK    (SECONDS_PER_DAY * 7.0)

// WARNING: This is a crude approximation of seconds per month and may not yield 
// accurate results for date arithmetic when days of month are at the beginnings
// or ends of months.
#define SECONDS_PER_MONTH   (SECONDS_PER_DAY * 30.42)

#define SECONDS_PER_YEAR    (SECONDS_PER_DAY * 365.0)

        if ( unitFlags & NSYearCalendarUnit ) {
            int timeDiff = (int)(diff / SECONDS_PER_YEAR);
            diff -= ((double) timeDiff) * SECONDS_PER_YEAR;
            [ret setYear:timeDiff];
        }
        if ( unitFlags & NSMonthCalendarUnit ) {
            int timeDiff = (int)(diff / SECONDS_PER_MONTH);
            diff -= ((double) timeDiff) * SECONDS_PER_MONTH;
            [ret setMonth:timeDiff];
        }
        if ( unitFlags & NSWeekCalendarUnit ) {
            int timeDiff = (int)(diff / SECONDS_PER_WEEK);
            diff -= ((double) timeDiff) * SECONDS_PER_WEEK;
            [ret setWeek:timeDiff];
        }
        if ( unitFlags & NSDayCalendarUnit ) {
            int timeDiff = (int)(diff / SECONDS_PER_DAY);
            diff -= ((double) timeDiff) * SECONDS_PER_DAY;
            [ret setDay:timeDiff];
        }
        if ( unitFlags & NSHourCalendarUnit ) {
            int timeDiff = (int)(diff / SECONDS_PER_HOUR);
            diff -= ((double) timeDiff) * SECONDS_PER_HOUR;
            [ret setHour:timeDiff];
        }
        if ( unitFlags & NSMinuteCalendarUnit ) {
            int timeDiff = (int)(diff / SECONDS_PER_MIN);
            diff -= ((double) timeDiff) * SECONDS_PER_MIN;
            [ret setMinute:timeDiff];
        }
        if ( unitFlags & NSSecondCalendarUnit ) {
            int timeDiff = (int)diff;
            diff -= ((double) timeDiff);
            [ret setSecond:timeDiff];
        }

        return [ret autorelease];
    }

    -(BOOL) rangeOfUnit:(NSCalendarUnit)unit startDate:(NSDate* *)datep interval:(NSTimeInterval  *)timep forDate:(NSDate*)date {
        // HACK: implement me!
        *datep = [date retain];
        return NO;
    }

    static UCalendarDateFields icuFieldFromUnit(NSCalendarUnit unit)
    {
        switch ( unit ) {
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

    -(NSRange) rangeOfUnit:(NSCalendarUnit)smaller inUnit:(NSCalendarUnit)larger forDate:(NSDate*)date {
        NSRange ret;

        double time = [date timeIntervalSince1970];

        UErrorCode status = U_ZERO_ERROR;
        Calendar *copy = _cal->clone();
        copy->setTime(time * 1000.0, status);

        icu::TimeZone *tz;
        [_timeZone _getICUTimezone:&tz];
        copy->setTimeZone(*tz);

        UCalendarDateFields icuSmaller = icuFieldFromUnit(smaller);
        ret.location = copy->getActualMinimum(icuSmaller, status);
        ret.length = copy->getActualMaximum(icuSmaller, status) - ret.location + 1;

        if ( smaller == NSMonthCalendarUnit ) {
            ret.location ++;
        }
        delete copy;
        return ret;
    }

    
@end

