/* Copyright (c) 2007 Christopher J. W. Lloyd <cjwl@objc.net>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#include "Starboard.h"
#include "StubReturn.h"
#include "Foundation/NSDateComponents.h"
#include "NSDateComponentsInternal.h"

@implementation NSDateComponents {
    NSInteger _week;
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    if (self = [super init]) {
        _era = NSUndefinedDateComponent;
        _year = NSUndefinedDateComponent;
        _month = NSUndefinedDateComponent;
        _day = NSUndefinedDateComponent;
        _hour = NSUndefinedDateComponent;
        _minute = NSUndefinedDateComponent;
        _second = NSUndefinedDateComponent;
        _nanosecond = NSUndefinedDateComponent;
        _week = NSUndefinedDateComponent;
        _weekday = NSUndefinedDateComponent;
        _weekdayOrdinal = NSUndefinedDateComponent;
        _quarter = NSUndefinedDateComponent;
        _weekOfMonth = NSUndefinedDateComponent;
        _weekOfYear = NSUndefinedDateComponent;
        _yearForWeekOfYear = NSUndefinedDateComponent;
    }
    return self;
}

// A convenience function for checking every component to match
- (BOOL)_componentsMatch:(NSDateComponents*)comp2 forUnits:(NSCalendarUnit)units {
    for (int i = 0; i < _countof(s_NSDateComponentsIndividualFlags); i++) {
        if ((units & s_NSDateComponentsIndividualFlags[i]) != 0) {
            NSUInteger val1 = [self valueForComponent:s_NSDateComponentsIndividualFlags[i]];
            NSUInteger val2 = [comp2 valueForComponent:s_NSDateComponentsIndividualFlags[i]];
            if (val1 != val2) {
                return NO;
            }
        }
    }

    return YES;
}

/**
 @Status Interoperable
*/
- (BOOL)isValidDate {
    if (!_calendar) {
        return NO;
    }
    [_calendar setTimeZone:_timeZone];
    return [self isValidDateInCalendar:_calendar];
}

/**
 @Status Interoperable
*/
- (BOOL)isValidDateInCalendar:(NSCalendar*)calendar {
    NSDate* dateThisIs = [calendar dateFromComponents:self];
    NSDateComponents* otherComponents = [calendar components:s_NSDateComponentsAllFlagOptions fromDate:dateThisIs];
    NSCalendarUnit unitsToCheck = 0;
    for (int i = 0; i < _countof(s_NSDateComponentsIndividualFlags); i++) {
        if ([self valueForComponent:s_NSDateComponentsIndividualFlags[i]] != NSUndefinedDateComponent) {
            unitsToCheck |= s_NSDateComponentsIndividualFlags[i];
        }
    }
    return [self _componentsMatch:otherComponents forUnits:unitsToCheck];
}

/** Interoperable
 @Status Interoperable
*/
- (NSDate*)date {
    if (self.calendar != nil) {
        return [self.calendar dateFromComponents:self];
    }
    return nil;
}

/**
 @Status Interoperable
*/
- (NSInteger)valueForComponent:(NSCalendarUnit)unit {
    switch (unit) {
        case NSCalendarUnitEra:
            return _era;
        case NSCalendarUnitYear:
            return _year;
        case NSCalendarUnitMonth:
            return _month;
        case NSCalendarUnitDay:
            return _day;
        case NSCalendarUnitHour:
            return _hour;
        case NSCalendarUnitMinute:
            return _minute;
        case NSCalendarUnitSecond:
            return _second;
        case NSCalendarUnitWeekday:
            return _weekday;
        case NSCalendarUnitWeekdayOrdinal:
            return _weekdayOrdinal;
        case NSCalendarUnitQuarter:
            return _quarter;
        case NSCalendarUnitWeekOfMonth:
            return _weekOfMonth;
        case NSCalendarUnitWeekOfYear:
            return _weekOfYear;
        case NSCalendarUnitYearForWeekOfYear:
            return _yearForWeekOfYear;
        case NSCalendarUnitNanosecond:
            return _nanosecond;
        default:
            return NSDateComponentUndefined;
    }
}

/**
 @Status Interoperable
*/
- (void)setValue:(NSInteger)value forComponent:(NSCalendarUnit)unit {
    switch (unit) {
        case NSCalendarUnitEra:
            _era = value;
            break;
        case NSCalendarUnitYear:
            _year = value;
            break;
        case NSCalendarUnitMonth:
            _month = value;
            break;
        case NSCalendarUnitDay:
            _day = value;
            break;
        case NSCalendarUnitHour:
            _hour = value;
            break;
        case NSCalendarUnitMinute:
            _minute = value;
            break;
        case NSCalendarUnitSecond:
            _second = value;
            break;
        case NSCalendarUnitWeekday:
            _weekday = value;
            break;
        case NSCalendarUnitWeekdayOrdinal:
            _weekdayOrdinal = value;
            break;
        case NSCalendarUnitQuarter:
            _quarter = value;
            break;
        case NSCalendarUnitWeekOfMonth:
            _weekOfMonth = value;
            break;
        case NSCalendarUnitWeekOfYear:
            _weekOfYear = value;
            break;
        case NSCalendarUnitYearForWeekOfYear:
            _yearForWeekOfYear = value;
            break;
        case NSCalendarUnitNanosecond:
            _nanosecond = value;
            break;
        default:
            break;
    }
}

/**
 @Status Interoperable
*/
- (id)copyWithZone:(NSZone*)zone {
    NSDateComponents* newObject = [[[self class] allocWithZone:zone] init];
    if (newObject) {
        newObject.era = self.era;
        newObject.year = self.year;
        newObject.month = self.month;
        newObject.day = self.day;
        newObject.hour = self.hour;
        newObject.minute = self.minute;
        newObject.second = self.second;
        newObject.nanosecond = self.nanosecond;
        newObject.week = self.week;
        newObject.weekday = self.weekday;
        newObject.weekdayOrdinal = self.weekdayOrdinal;
        newObject.quarter = self.quarter;
        newObject.weekOfMonth = self.weekOfMonth;
        newObject.weekOfYear = self.weekOfYear;
        newObject.yearForWeekOfYear = self.yearForWeekOfYear;
        newObject.calendar = [self.calendar copy];
        newObject.timeZone = [self.timeZone copy];
        newObject.leapMonth = self.isLeapMonth;
    }

    return newObject;
}

/**
 @Status Interoperable
*/
+ (BOOL)supportsSecureCoding {
    return YES;
}

/**
 @Status Interoperable
*/
- (id)initWithCoder:(NSCoder*)decoder {
    if (self = [self init]) {
        _era = [decoder decodeIntegerForKey:@"NS.era"];
        _year = [decoder decodeIntegerForKey:@"NS.year"];
        _month = [decoder decodeIntegerForKey:@"NS.month"];
        _day = [decoder decodeIntegerForKey:@"NS.day"];
        _hour = [decoder decodeIntegerForKey:@"NS.hour"];
        _minute = [decoder decodeIntegerForKey:@"NS.minute"];
        _second = [decoder decodeIntegerForKey:@"NS.second"];
        _nanosecond = [decoder decodeIntegerForKey:@"NS.nanosecond"];
        _week = [decoder decodeIntegerForKey:@"NS.week"];
        _weekday = [decoder decodeIntegerForKey:@"NS.weekday"];
        _weekdayOrdinal = [decoder decodeIntegerForKey:@"NS.weekdayordinal"];
        _quarter = [decoder decodeIntegerForKey:@"NS.quarter"];
        _weekOfMonth = [decoder decodeIntegerForKey:@"NS.weekofmonth"];
        _weekOfYear = [decoder decodeIntegerForKey:@"NS.weekofyear"];
        _yearForWeekOfYear = [decoder decodeIntegerForKey:@"NS.yearforweekofyear"];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)encodeWithCoder:(NSCoder*)coder {
    [coder encodeInteger:_era forKey:@"NS.era"];
    [coder encodeInteger:_year forKey:@"NS.year"];
    [coder encodeInteger:_month forKey:@"NS.month"];
    [coder encodeInteger:_day forKey:@"NS.day"];
    [coder encodeInteger:_hour forKey:@"NS.hour"];
    [coder encodeInteger:_minute forKey:@"NS.minute"];
    [coder encodeInteger:_second forKey:@"NS.second"];
    [coder encodeInteger:_nanosecond forKey:@"NS.nanosecond"];
    [coder encodeInteger:_week forKey:@"NS.week"];
    [coder encodeInteger:_weekday forKey:@"NS.weekday"];
    [coder encodeInteger:_weekdayOrdinal forKey:@"NS.weekdayordinal"];
    [coder encodeInteger:_quarter forKey:@"NS.quarter"];
    [coder encodeInteger:_weekOfMonth forKey:@"NS.weekofmonth"];
    [coder encodeInteger:_weekOfYear forKey:@"NS.weekofyear"];
    [coder encodeInteger:_yearForWeekOfYear forKey:@"NS.yearforweekofyear"];
}

- (void)setWeek:(NSInteger)v {
    _week = v;
}

- (NSInteger)week {
    return _week;
}

@end
