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
#include "Foundation/NSData.h"
#include "Foundation/NSString.h"
#include "Foundation/NSArray.h"
#include "Etc.h"
#include "Foundation/NSTimeZone.h"
#include "NSTimeZoneInternal.h"

#include <unicode/gregocal.h>
#include <windows.h>

static NSTimeZone* _defaultTimeZone;
static dispatch_once_t _systemTimeZoneInit;
static NSTimeZone* _systemTimeZone;

@implementation NSTimeZone {
    icu::TimeZone* _icuTZ;
}
+ (void)_setTimeZoneToSystemSettings:(icu::TimeZone*)tz {
    /* Implement me! */
}

+ (NSTimeZone*)_getSystemTZ {
    dispatch_once(&_systemTimeZoneInit,
                  ^{
                      _systemTimeZone = [self alloc];
                      _systemTimeZone->_icuTZ = icu_48::TimeZone::createDefault();
                      [self _setTimeZoneToSystemSettings:_systemTimeZone->_icuTZ];
                  });

    return _systemTimeZone;
}

/**
 @Status Stub
*/
+ (instancetype)systemTimeZone {
    UNIMPLEMENTED();
    return [self _getSystemTZ];
}

/**
 @Status Stub
*/
+ (void)resetSystemTimeZone {
    UNIMPLEMENTED();
    [self _setTimeZoneToSystemSettings:[self _getSystemTZ]->_icuTZ];
}

/**
 @Status Stub
*/
+ (instancetype)defaultTimeZone {
    UNIMPLEMENTED();
    NSTimeZone* ret;

    if (_defaultTimeZone != nil) {
        ret = _defaultTimeZone;
    } else {
        ret = [self systemTimeZone];
    }
    return [[ret copy] autorelease];
}

/**
 @Status Interoperable
*/
+ (void)setDefaultTimeZone:(NSTimeZone*)zone {
    zone = [zone retain];
    [_defaultTimeZone release];
    _defaultTimeZone = zone;
}

/**
 @Status Stub
*/
+ (NSArray*)knownTimeZoneNames {
    UNIMPLEMENTED();
    //  TODO
    return [NSArray arrayWithObject:@"America/Los_Angeles"];
}

- (icu::TimeZone*)_createICUTimeZone {
    return _icuTZ->clone();
}

/**
 @Status Interoperable
*/
+ (instancetype)timeZoneForSecondsFromGMT:(NSInteger)seconds {
    NSTimeZone* ret = [self alloc];
    ret->_icuTZ = icu_48::TimeZone::createTimeZone(icu_48::UnicodeString("GMT"));
    ret->_icuTZ->setRawOffset(seconds * 1000);
    return [ret autorelease];
}

/**
 @Status Stub
*/
+ (instancetype)localTimeZone {
    UNIMPLEMENTED();
    if (_defaultTimeZone != nil) {
        return [[_defaultTimeZone retain] autorelease];
    }
    return [self systemTimeZone];
}

+ (instancetype)_gmtTimeZone {
    NSTimeZone* ret = [self alloc];
    ret->_icuTZ = icu_48::TimeZone::getGMT()->clone();
    return [ret autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)timeZoneWithName:(NSString*)name {
    NSTimeZone* ret = [self alloc];
    ret->_icuTZ = icu_48::TimeZone::createTimeZone(icu_48::UnicodeString([name UTF8String]));
    return [ret autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)timeZoneWithAbbreviation:(NSString*)name {
    NSTimeZone* ret = [self alloc];
    const char* nameStr = [name UTF8String];
    icu_48::TimeZone* tz = icu_48::TimeZone::createTimeZone(icu_48::UnicodeString(nameStr));
    int foo = tz->getRawOffset();
    ret->_icuTZ = tz;
    return [ret autorelease];
}

/**
 @Status Interoperable
*/
- (NSString*)name {
    icu_48::UnicodeString n;
    _icuTZ->getDisplayName(n);
    return NSStringFromICU(n);
}

/**
 @Status Interoperable
*/
- (NSString*)abbreviation {
    icu_48::UnicodeString n;
    _icuTZ->getID(n);
    return NSStringFromICU(n);
}

/**
 @Status Interoperable
*/
- (NSString*)description {
    icu_48::UnicodeString n;
    _icuTZ->getDisplayName(n);
    return NSStringFromICU(n);
}

/**
 @Status Stub
*/
- (NSString*)localizedName:(NSTimeZoneNameStyle)name locale:(NSLocale*)locale {
    UNIMPLEMENTED();
    return [self description];
}

/**
 @Status Interoperable
*/
- (NSInteger)secondsFromGMT {
    return _icuTZ->getRawOffset() / 1000;
}

/**
 @Status Stub
*/
- (NSInteger)secondsFromGMTForDate:(NSDate*)date {
    UNIMPLEMENTED();
    assert(0);
    return 0;
}

- (instancetype)copyWithZone:(NSZone*)zone {
    return [self retain];
}

/**
 @Status Interoperable
*/
- (BOOL)isDaylightSavingTimeForDate:(NSDate*)date {
    UErrorCode status = U_ZERO_ERROR;

    return _icuTZ->inDaylightTime([date timeIntervalSince1970] * 1000.0, status);
}

/**
 @Status Interoperable
*/
- (BOOL)isDaylightSavingTime {
    return [self isDaylightSavingTimeForDate:[NSDate date]];
}

- (void)dealloc {
    delete _icuTZ;
    [super dealloc];
}

@end
