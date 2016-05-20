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

#define NSUndefinedDateComponent 0x7fffffff

@implementation NSDateComponents
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

/**
 @Status Stub
 @Notes
*/
- (BOOL)isValidDateInCalendar:(NSCalendar*)calendar {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSInteger)valueForComponent:(NSCalendarUnit)unit {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)setValue:(NSInteger)value forComponent:(NSCalendarUnit)unit {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (id)copyWithZone:(NSZone*)zone {
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
