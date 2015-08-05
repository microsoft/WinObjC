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
#include "Foundation/NSDateComponents.h"

#define NSUndefinedDateComponent 0x7fffffff

@implementation NSDateComponents : NSObject
    -(instancetype) init {
        _era=NSUndefinedDateComponent;
        _year=NSUndefinedDateComponent;
        _quarter=NSUndefinedDateComponent;
        _month=NSUndefinedDateComponent;
        _week=NSUndefinedDateComponent;
        _weekday=NSUndefinedDateComponent;
        _weekdayOrdinal=NSUndefinedDateComponent;
        _day=NSUndefinedDateComponent;
        _hour=NSUndefinedDateComponent;
        _minute=NSUndefinedDateComponent;
        _second=NSUndefinedDateComponent;
        return self;
   }

    -(void) setDay:(NSInteger)day {
        _day = day;
    }

    -(void) setMonth:(NSInteger)month {
        _month = month;
    }

    -(void) setYear:(NSInteger)year {
        _year = year;
    }

    -(void) setSecond:(NSInteger)second {
        _second = second;
    }

    -(void) setMinute:(NSInteger)minute {
        _minute = minute;
    }

    -(void) setHour:(NSInteger)hour {
        _hour = hour;
    }

    -(void) setWeekday:(NSInteger)weekday {
        _weekday = weekday;
    }

    -(void) setWeek:(NSInteger)week {
        _week = week;
    }

    -(NSInteger) weekday {
        return _weekday;
    }

    -(NSInteger) week {
        return _week;
    }

    -(NSInteger) day {
        return _day;
    }

    -(NSInteger) month {
        return _month;
    }

    -(NSInteger) year {
        return _year;
    }

    -(NSInteger) hour {
        return _hour;
    }

    -(NSInteger) minute {
        return _minute;
    }

    -(NSInteger) second {
        return _second;
    }

    
@end

