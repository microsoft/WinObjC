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
#include "Foundation/NSDateComponents.h"

#define NSUndefinedDateComponent 0x7fffffff

@implementation NSDateComponents : NSObject
- (instancetype)init {
    _era = NSUndefinedDateComponent;
    _year = NSUndefinedDateComponent;
    _quarter = NSUndefinedDateComponent;
    _month = NSUndefinedDateComponent;
    _week = NSUndefinedDateComponent;
    _weekday = NSUndefinedDateComponent;
    _weekdayOrdinal = NSUndefinedDateComponent;
    _day = NSUndefinedDateComponent;
    _hour = NSUndefinedDateComponent;
    _minute = NSUndefinedDateComponent;
    _second = NSUndefinedDateComponent;
    return self;
}

/**
 @Status Interoperable
*/
- (void)setDay:(NSInteger)day {
    _day = day;
}

/**
 @Status Interoperable
*/
- (void)setMonth:(NSInteger)month {
    _month = month;
}

/**
 @Status Interoperable
*/
- (void)setYear:(NSInteger)year {
    _year = year;
}

/**
 @Status Interoperable
*/
- (void)setSecond:(NSInteger)second {
    _second = second;
}

/**
 @Status Interoperable
*/
- (void)setMinute:(NSInteger)minute {
    _minute = minute;
}

/**
 @Status Interoperable
*/
- (void)setHour:(NSInteger)hour {
    _hour = hour;
}

/**
 @Status Interoperable
*/
- (void)setWeekday:(NSInteger)weekday {
    _weekday = weekday;
}

/**
 @Status Interoperable
*/
- (void)setWeek:(NSInteger)week {
    _week = week;
}

/**
 @Status Interoperable
*/
- (NSInteger)weekday {
    return _weekday;
}

/**
 @Status Interoperable
*/
- (NSInteger)week {
    return _week;
}

/**
 @Status Interoperable
*/
- (NSInteger)day {
    return _day;
}

/**
 @Status Interoperable
*/
- (NSInteger)month {
    return _month;
}

/**
 @Status Interoperable
*/
- (NSInteger)year {
    return _year;
}

/**
 @Status Interoperable
*/
- (NSInteger)hour {
    return _hour;
}

/**
 @Status Interoperable
*/
- (NSInteger)minute {
    return _minute;
}

/**
 @Status Interoperable
*/
- (NSInteger)second {
    return _second;
}

@end
