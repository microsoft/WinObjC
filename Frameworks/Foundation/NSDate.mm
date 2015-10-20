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

#include <time.h>

#include "Starboard.h"
#include "Foundation/NSDate.h"

extern const NSTimeInterval NSTimeIntervalSince1970 = (NSTimeInterval)978307200.0;

double TimeIntervalSinceReferenceDate() {
    double result;
    struct EbrTimeval tp;

    EbrGetTimeOfDay(&tp);
    result = (((NSTimeInterval)tp.tv_sec) - NSTimeIntervalSince1970);
    result += (((NSTimeInterval)tp.tv_usec) / ((NSTimeInterval)1000000.0));

    return result;
}

@implementation NSDate : NSObject
+ (double)timeIntervalSinceReferenceDate {
    return TimeIntervalSinceReferenceDate();
}

+ (NSDate*)dateWithString:(NSString*)string {
    return [[[self alloc] initWithString:string] autorelease];
}

- (double)timeIntervalSinceReferenceDate {
    double ret = _curTime;
    return ret;
}

- (double)timeIntervalSinceNow {
    double ret = [self timeIntervalSinceReferenceDate] - [NSDate timeIntervalSinceReferenceDate];

    return ret;
}

- (double)timeIntervalSince1970 {
    return [self timeIntervalSinceReferenceDate] + NSTimeIntervalSince1970;
}

- (double)timeIntervalSinceDate:(id)ref {
    return [self timeIntervalSinceReferenceDate] - [ref timeIntervalSinceReferenceDate];
}

+ (NSDate*)date {
    return [[[self allocWithZone:nil] initWithTimeIntervalSinceReferenceDate:TimeIntervalSinceReferenceDate()] autorelease];
}

+ (NSDate*)distantPast {
    static id staticInstance;
    if (!staticInstance) {
        staticInstance = [[self allocWithZone:nil] initWithTimeIntervalSinceReferenceDate:-(2010.0L * 365 * 24 * 60 * 60)];
    }

    return staticInstance;
}

+ (NSDate*)distantFuture {
    static id staticInstance;
    if (!staticInstance) {
        staticInstance = [[self allocWithZone:nil] initWithTimeIntervalSinceReferenceDate:2010.0L * 365 * 24 * 60 * 60];
    }

    return staticInstance;
}

+ (NSDate*)dateWithTimeIntervalSinceNow:(double)secondsSinceNow {
    return [[[self allocWithZone:nil] initWithTimeIntervalSinceNow:secondsSinceNow] autorelease];
}

- (NSDate*)dateByAddingTimeInterval:(double)interval {
    return [[[NSDate allocWithZone:nil] initWithTimeIntervalSinceReferenceDate:_curTime + interval] autorelease];
}

+ (NSDate*)dateWithTimeIntervalSince1970:(double)secondsSince1970 {
    return
        [[[self allocWithZone:nil] initWithTimeIntervalSinceReferenceDate:-NSTimeIntervalSince1970 + (double)secondsSince1970] autorelease];
}

+ (NSDate*)dateWithTimeInterval:(double)interval sinceDate:(NSDate*)date {
    return [date dateByAddingTimeInterval:interval];
}

+ (NSDate*)dateWithTimeIntervalSinceReferenceDate:(double)secondsSinceRef {
    return [[[self allocWithZone:nil] initWithTimeIntervalSinceReferenceDate:secondsSinceRef] autorelease];
}

- (NSDate*)initWithCoder:(NSCoder*)coder {
    EbrDebugLog("NSDate initWithCoder not supported\n");
    return [self init];
}

- (NSDate*)initWithString:(NSString*)string {
    EbrDebugLog("NSDate initWithString not supported\n");
    [self init];

    return self;
}

- (NSDate*)initWithTimeIntervalSince1970:(double)secondsSince1970 {
    return [self initWithTimeIntervalSinceReferenceDate:-NSTimeIntervalSince1970 + (double)secondsSince1970];
}

- (NSDate*)initWithTimeIntervalSinceNow:(double)secondsSinceNow {
    return [self initWithTimeIntervalSinceReferenceDate:TimeIntervalSinceReferenceDate() + secondsSinceNow];
}

- (NSDate*)initWithTimeIntervalSinceReferenceDate:(double)ref {
    _curTime = ref;
    return self;
}

- (NSDate*)initWithTimeInterval:(double)seconds sinceDate:(NSDate*)date {
    return [self initWithTimeIntervalSinceReferenceDate:[date timeIntervalSinceReferenceDate] + seconds];
}

- (NSInteger)compare:(NSDate*)toDate {
    if (toDate == nil) {
        return -1;
    }

    if (_curTime == toDate->_curTime) {
        return 0;
    } else if (_curTime > toDate->_curTime) {
        return 1;
    } else {
        return -1;
    }
}

- (NSInteger)isEqualToDate:(NSDate*)toDate {
    if (![toDate isKindOfClass:[NSDate class]]) {
        return FALSE;
    }

    if (_curTime == toDate->_curTime) {
        return TRUE;
    } else {
        return FALSE;
    }
}

- (BOOL)isEqual:(NSDate*)toDate {
    if (self == toDate) {
        return TRUE;
    }

    if (![toDate isKindOfClass:[NSDate class]]) {
        return FALSE;
    }
    return [self isEqualToDate:(id)toDate];
}

- (NSUInteger)hash {
    NSUInteger hashRet[2];

    memcpy(hashRet, &_curTime, sizeof(double));
    hashRet[0] ^= hashRet[1];

    return hashRet[0];
}

- (NSDate*)earlierDate:(NSDate*)toDate {
    if (_curTime == toDate->_curTime) {
        return self;
    } else if (_curTime > toDate->_curTime) {
        return toDate;
    } else {
        return self;
    }
}

- (NSDate*)laterDate:(NSDate*)toDate {
    if (_curTime == toDate->_curTime) {
        return self;
    } else if (_curTime < toDate->_curTime) {
        return toDate;
    } else {
        return self;
    }
}

- (NSObject*)copyWithZone:(NSZone*)zone {
    return [self retain];
}

- (NSDate*)addTimeInterval:(double)seconds {
    NSDate* ret = [[self class] alloc];
    ret->_curTime = _curTime + seconds;

    return ret;
}

- (NSObject*)init {
    _curTime = TimeIntervalSinceReferenceDate();

    return self;
}

- (void)encodeWithCoder:(NSCoder*)coder {
    EbrDebugLog("NSDate: encodeWithCoder not supported\n");
}

- (NSString*)description {
    static NSDateFormatter* formatter;

    if (formatter == nil) {
        formatter = [[NSDateFormatter alloc] init];
        [formatter setDateFormat:@"yyyy'-'MM'-'dd' 'HH':'mm':'ss Z"];
        [formatter setTimeZone:[[NSTimeZone _gmtTimeZone] retain]];
    }

    NSString* str = [formatter stringForObjectValue:self];

    return str;
}

@end
