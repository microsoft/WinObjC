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

// Number of seconds between Jan 1, 1601 UTC (Windows FILETIME) and Jan 1, 1970 UTC (POSIX/Epoch time)
static const int64_t c_windowsToUnixNumSecondsOffset = 11644473600LL;
// Ratio between 100ns (Windows FILETIME unit) and 1s (POSIX/Epoch time unit)
static const int64_t c_windowsToUnixTimeUnitRatio = 10000LL;

/**
 @Status Interoperable
*/
+ (double)timeIntervalSinceReferenceDate {
    return TimeIntervalSinceReferenceDate();
}

/**
 @Status Stub
*/
+ (NSDate*)dateWithString:(NSString*)string {
    UNIMPLEMENTED();
    return [[[self alloc] initWithString:string] autorelease];
}

/**
 @Status Interoperable
*/
- (double)timeIntervalSinceReferenceDate {
    double ret = _curTime;
    return ret;
}

/**
 @Status Interoperable
*/
- (double)timeIntervalSinceNow {
    double ret = [self timeIntervalSinceReferenceDate] - [NSDate timeIntervalSinceReferenceDate];

    return ret;
}

/**
 @Status Interoperable
*/
- (double)timeIntervalSince1970 {
    return [self timeIntervalSinceReferenceDate] + NSTimeIntervalSince1970;
}

/**
 @Status Interoperable
*/
- (double)timeIntervalSinceDate:(id)ref {
    return [self timeIntervalSinceReferenceDate] - [ref timeIntervalSinceReferenceDate];
}

/**
 @Status Interoperable
*/
+ (NSDate*)date {
    return [[[self allocWithZone:nil] initWithTimeIntervalSinceReferenceDate:TimeIntervalSinceReferenceDate()] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSDate*)distantPast {
    static id staticInstance;
    if (!staticInstance) {
        staticInstance = [[self allocWithZone:nil] initWithTimeIntervalSinceReferenceDate:-(2010.0L * 365 * 24 * 60 * 60)];
    }

    return staticInstance;
}

/**
 @Status Interoperable
*/
+ (NSDate*)distantFuture {
    static id staticInstance;
    if (!staticInstance) {
        staticInstance = [[self allocWithZone:nil] initWithTimeIntervalSinceReferenceDate:2010.0L * 365 * 24 * 60 * 60];
    }

    return staticInstance;
}

/**
 @Status Interoperable
*/
+ (NSDate*)dateWithTimeIntervalSinceNow:(double)secondsSinceNow {
    return [[[self allocWithZone:nil] initWithTimeIntervalSinceNow:secondsSinceNow] autorelease];
}

/**
 @Status Interoperable
*/
- (NSDate*)dateByAddingTimeInterval:(double)interval {
    return [[[NSDate allocWithZone:nil] initWithTimeIntervalSinceReferenceDate:_curTime + interval] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSDate*)dateWithTimeIntervalSince1970:(double)secondsSince1970 {
    return
        [[[self allocWithZone:nil] initWithTimeIntervalSinceReferenceDate:-NSTimeIntervalSince1970 + (double)secondsSince1970] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSDate*)dateWithTimeInterval:(double)interval sinceDate:(NSDate*)date {
    return [date dateByAddingTimeInterval:interval];
}

/**
 @Status Interoperable
*/
+ (NSDate*)dateWithTimeIntervalSinceReferenceDate:(double)secondsSinceRef {
    return [[[self allocWithZone:nil] initWithTimeIntervalSinceReferenceDate:secondsSinceRef] autorelease];
}

- (NSDate*)initWithCoder:(NSCoder*)coder {
    EbrDebugLog("NSDate initWithCoder not supported\n");
    return [self init];
}

/**
 @Status Stub
*/
- (NSDate*)initWithString:(NSString*)string {
    UNIMPLEMENTED();
    EbrDebugLog("NSDate initWithString not supported\n");
    [self init];

    return self;
}

/**
 @Status Interoperable
*/
- (NSDate*)initWithTimeIntervalSince1970:(double)secondsSince1970 {
    return [self initWithTimeIntervalSinceReferenceDate:-NSTimeIntervalSince1970 + (double)secondsSince1970];
}

/**
 @Status Interoperable
*/
- (NSDate*)initWithTimeIntervalSinceNow:(double)secondsSinceNow {
    return [self initWithTimeIntervalSinceReferenceDate:TimeIntervalSinceReferenceDate() + secondsSinceNow];
}

/**
 @Status Interoperable
*/
- (NSDate*)initWithTimeIntervalSinceReferenceDate:(double)ref {
    _curTime = ref;
    return self;
}

/**
 @Status Interoperable
*/
- (NSDate*)initWithTimeInterval:(double)seconds sinceDate:(NSDate*)date {
    return [self initWithTimeIntervalSinceReferenceDate:[date timeIntervalSinceReferenceDate] + seconds];
}

/**
 @Status Interoperable
*/
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

/**
 @Status Interoperable
*/
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

/**
 @Status Interoperable
*/
- (NSDate*)earlierDate:(NSDate*)toDate {
    if (_curTime == toDate->_curTime) {
        return self;
    } else if (_curTime > toDate->_curTime) {
        return toDate;
    } else {
        return self;
    }
}

/**
 @Status Interoperable
*/
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

/**
 @Status Interoperable
*/
- (NSDate*)addTimeInterval:(double)seconds {
    NSDate* ret = [[self class] alloc];
    ret->_curTime = _curTime + seconds;

    return ret;
}

/**
 @Status Interoperable
*/
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

/**
 * Converts a Windows Gps epoch to NSDate.
 * @param  {int64_t} windowsFileTime Windows file time
 * @return {NSDate*}
 */
+ (NSDate*)_dateWithWindowsGPSTime:(int64_t)windowsFileTime {
    // First convert Windows Gps epoch to Unix epoch.
    // Note: this corrects for the 10 year base time difference between gps epoch (1980) and  posix epoch (1970)
    int64_t posixEpoch = (windowsFileTime / c_windowsToUnixTimeUnitRatio) - c_windowsToUnixNumSecondsOffset * 1000LL;
    return [NSDate dateWithTimeIntervalSince1970:(double)posixEpoch];
}

@end
