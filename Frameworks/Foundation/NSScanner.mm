/* Copyright (c) 2006-2007 Christopher J. W. Lloyd
   Copyright (c) 2016 Microsoft Corporation. All rights reserved.

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

// Original - Christopher Lloyd <cjwl@objc.net>
//
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//

#include "Starboard.h"
#include "StubReturn.h"
#include "Foundation/NSString.h"
#include "Foundation/NSCharacterSet.h"
#include "Foundation/NSScanner.h"
#include <limits.h>

#include "unicode/uniset.h"

typedef unsigned short unichar;

@implementation NSScanner

/**
 @Status Interoperable
*/
+ (instancetype)scannerWithString:(id)str {
    NSScanner* ret = [self alloc];

    return [[ret initWithString:str] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithString:(id)string {
    self = [self init];
    _string = [string copy];
    _location = 0;
    _len = [_string length];
    _skipSet = [[NSCharacterSet whitespaceAndNewlineCharacterSet] retain];
    _isCaseSensitive = NO;
    _locale = nil;

    return self;
}

/**
 @Status Interoperable
*/
- (NSString*)string {
    return _string;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    [_string release];
    [_skipSet release];
    [_locale release];
    [super dealloc];
}

/**
 @Status Interoperable
*/
- (NSCharacterSet*)charactersToBeSkipped {
    return _skipSet;
}

/**
 @Status Interoperable
*/
- (BOOL)caseSensitive {
    return _isCaseSensitive;
}

/**
 @Status Interoperable
*/
- (void)setCharactersToBeSkipped:(id)set {
    if (set != _skipSet) {
        set = [set retain];
        [_skipSet release];
        _skipSet = set;
    }
}

/**
 @Status Interoperable
*/
- (void)setCaseSensitive:(BOOL)flag {
    _isCaseSensitive = flag;
}

/**
 @Status Interoperable
*/
- (BOOL)isAtEnd {
    NSUInteger length = [_string length];
    NSUInteger currentLocation = _location;

    for (; currentLocation < length; currentLocation++) {
        if ([_skipSet characterIsMember:[_string characterAtIndex:currentLocation]] == TRUE) {
            continue;
        } else {
            return FALSE;
        }
    }

    return TRUE;
}

/**
 @Status Interoperable
*/
- (NSUInteger)scanLocation {
    // return _location < _len ? _location : _len - 1;
    return _location;
}

/**
 @Status Interoperable
*/
- (void)setScanLocation:(NSUInteger)pos {
    _location = pos;
}

/**
 @Status Interoperable
*/
- (BOOL)scanInt:(int*)valuep {
    long long scanValue = 0;

    // This assumes sizeof(long long) >= sizeof(int).
    if (![self scanLongLong:&scanValue]) {
        return FALSE;
    } else if (valuep) {
        if (scanValue > INT_MAX) {
            *valuep = INT_MAX;
        } else if (scanValue < INT_MIN) {
            *valuep = INT_MIN;
        } else {
            *valuep = (int)scanValue;
        }
    }

    return TRUE;
}

/**
 @Status Interoperable
*/
- (BOOL)scanInteger:(int*)valuep {
    long long scanValue = 0;

    // This assumes sizeof(long long) >= sizeof(int).
    if (![self scanLongLong:&scanValue]) {
        return FALSE;
    } else if (valuep) {
        if (scanValue > LONG_MAX) {
            *valuep = LONG_MAX;
        } else if (scanValue < LONG_MIN) {
            *valuep = LONG_MIN;
        } else {
            *valuep = (int)scanValue;
        }
    }

    return TRUE;
}

/**
 @Status Interoperable
*/
- (BOOL)scanLongLong:(long long*)valuep {
#define long_long_MAX 0x7fffffffffffffffLL
#define long_long_MIN (-0x7fffffffffffffffLL - 1)

    NSUInteger length;
    int sign = 1;
    BOOL hasSign = FALSE;
    long long value = 0;
    BOOL hasValue = FALSE;
    BOOL hasOverflow = FALSE;

    for (length = (NSUInteger)[_string length]; _location < length; _location++) {
        unichar unicode = (unichar)[_string characterAtIndex:_location];

        if (!hasValue && [_skipSet characterIsMember:unicode])
            continue;
        else if (!hasSign && unicode == '-') {
            sign = -1;
            hasSign = TRUE;
        } else if (!hasSign && unicode == '+') {
            sign = 1;
            hasSign = TRUE;
        } else if (unicode >= '0' && unicode <= '9') {
            if (!hasOverflow) {
                int c = unicode - '0';

                // Inspired by http://www.math.utoledo.edu/~dbastos/overflow.html
                if ((long_long_MAX - c) / 10 < value)
                    hasOverflow = TRUE;
                else
                    value = (value * 10) + c;
                hasSign = TRUE;
                hasValue = TRUE;
            }
        } else
            break;
    }

    if (hasOverflow) {
        if (valuep) {
            if (sign > 0) {
                *valuep = long_long_MAX;
            } else {
                *valuep = long_long_MIN;
            }
        }

        return TRUE;
    } else if (hasValue) {
        if (valuep) {
            *valuep = sign * value;
        }
        return TRUE;
    }

    return FALSE;
}

/**
 @Status Interoperable
*/
- (BOOL)scanFloat:(float*)valuep {
    double d;
    BOOL r;

    r = [self scanDouble:&d];

    if (valuep) {
        *valuep = (float)d;
    }
    return r;
}

/**
 @Status Interoperable
*/
- (BOOL)scanDouble:(double*)valuep {
    char* pScanStart = (char*)[_string UTF8String];
    char* pScanEnd = NULL;

    pScanStart += _location;

    double val = strtod(pScanStart, &pScanEnd);
    assert(pScanEnd != NULL);

    _location += pScanEnd - pScanStart;

    if (valuep) {
        *valuep = val;
    }

    if ((pScanEnd - pScanStart) == 0) {
        return FALSE;
    }

    return TRUE;
}

/**
 @Status Interoperable
*/
- (BOOL)scanHexInt:(unsigned*)valuep {
    enum {
        STATE_SPACE,
        STATE_ZERO,
        STATE_HEX,
    } state = STATE_SPACE;
    unsigned value = 0;
    BOOL hasValue = FALSE;
    BOOL overflow = FALSE;

    for (; _location < [_string length]; _location++) {
        unichar unicode = (unichar)[_string characterAtIndex:_location];

        switch (state) {
            case STATE_SPACE:
                if ([_skipSet characterIsMember:unicode])
                    state = STATE_SPACE;
                else if (unicode == '0') {
                    state = STATE_ZERO;
                    hasValue = TRUE;
                } else if (unicode >= '1' && unicode <= '9') {
                    value = value * 16 + (unicode - '0');
                    state = STATE_HEX;
                    hasValue = TRUE;
                } else if (unicode >= 'a' && unicode <= 'f') {
                    value = value * 16 + (unicode - 'a') + 10;
                    state = STATE_HEX;
                    hasValue = TRUE;
                } else if (unicode >= 'A' && unicode <= 'F') {
                    value = value * 16 + (unicode - 'A') + 10;
                    state = STATE_HEX;
                    hasValue = TRUE;
                } else
                    return NO;
                break;

            case STATE_ZERO:
                state = STATE_HEX;
                if (unicode == 'x' || unicode == 'X')
                    break;

            // fallthrough
            case STATE_HEX:
                if (unicode >= '0' && unicode <= '9') {
                    if (!overflow) {
                        unsigned check = value * 16 + (unicode - '0');
                        if (check >= value)
                            value = check;
                        else {
                            value = -1;
                            overflow = YES;
                        }
                    }
                } else if (unicode >= 'a' && unicode <= 'f') {
                    if (!overflow) {
                        unsigned check = value * 16 + (unicode - 'a') + 10;
                        if (check >= value)
                            value = check;
                        else {
                            value = -1;
                            overflow = YES;
                        }
                    }
                } else if (unicode >= 'A' && unicode <= 'F') {
                    if (!overflow) {
                        unsigned check = value * 16 + (unicode - 'A') + 10;

                        if (check >= value)
                            value = check;
                        else {
                            value = -1;
                            overflow = YES;
                        }
                    }
                } else {
                    if (valuep) {
                        *valuep = value;
                    }

                    return YES;
                }
                break;
        }
    }

    if (hasValue) {
        if (valuep) {
            *valuep = value;
        }

        return YES;
    }

    return NO;
}

/**
 @Status Interoperable
*/
- (BOOL)scanHexLongLong:(unsigned long long*)valuep {
    enum {
        STATE_SPACE,
        STATE_ZERO,
        STATE_HEX,
    } state = STATE_SPACE;
    unsigned long long value = 0;
    BOOL hasValue = NO;
    BOOL overflow = NO;

    for (; _location < [_string length]; _location++) {
        unichar unicode = (unichar)[_string characterAtIndex:_location];

        switch (state) {
            case STATE_SPACE:
                if ([_skipSet characterIsMember:unicode])
                    state = STATE_SPACE;
                else if (unicode == '0') {
                    state = STATE_ZERO;
                    hasValue = YES;
                } else if (unicode >= '1' && unicode <= '9') {
                    value = value * 16 + (unicode - '0');
                    state = STATE_HEX;
                    hasValue = YES;
                } else if (unicode >= 'a' && unicode <= 'f') {
                    value = value * 16 + (unicode - 'a') + 10;
                    state = STATE_HEX;
                    hasValue = YES;
                } else if (unicode >= 'A' && unicode <= 'F') {
                    value = value * 16 + (unicode - 'A') + 10;
                    state = STATE_HEX;
                    hasValue = YES;
                } else
                    return NO;
                break;

            case STATE_ZERO:
                state = STATE_HEX;
                if (unicode == 'x' || unicode == 'X')
                    break;

            // fallthrough
            case STATE_HEX:
                if (unicode >= '0' && unicode <= '9') {
                    if (!overflow) {
                        unsigned check = (unsigned)(value * 16 + (unicode - '0'));
                        if (check >= value)
                            value = check;
                        else {
                            value = -1;
                            overflow = YES;
                        }
                    }
                } else if (unicode >= 'a' && unicode <= 'f') {
                    if (!overflow) {
                        unsigned check = (unsigned)(value * 16 + (unicode - 'a') + 10);
                        if (check >= value)
                            value = check;
                        else {
                            value = -1;
                            overflow = YES;
                        }
                    }
                } else if (unicode >= 'A' && unicode <= 'F') {
                    if (!overflow) {
                        unsigned check = (unsigned)(value * 16 + (unicode - 'A') + 10);

                        if (check >= value)
                            value = check;
                        else {
                            value = -1;
                            overflow = YES;
                        }
                    }
                } else {
                    if (valuep) {
                        *valuep = value;
                    }

                    return YES;
                }
                break;
        }
    }

    if (hasValue) {
        if (valuep) {
            *valuep = value;
        }

        return YES;
    }
    return NO;
}

/**
 @Status Interoperable
*/
- (BOOL)scanString:(id)string intoString:(NSString**)stringp {
    unsigned int length = [_string length];
    DWORD compareOption = 0;
    NSRange range;

    range.location = 0;
    range.length = [string length];
    int oldLocation = _location;

    BOOL result = NO;

    if (!_isCaseSensitive) {
        compareOption = 1; // NSCaseInsensitiveSearch
    }

    for (; _location < length; _location++) {
        unichar unicode = (unichar)[_string characterAtIndex:_location];
        range.location = _location;
        if ((_len - _location) < [string length]) {
            result = NO;
            break;
        }

        if ([_skipSet characterIsMember:unicode] == YES) {
            continue;
        }
        if ([_string compare:string
                     options:static_cast<NSStringCompareOptions>(compareOption)
                       range:NSMakeRange(range.location, range.length)] == 0) {
            if (stringp) {
                *stringp = string;
            }

            _location += [string length];

            result = YES;
            break;
        } else {
            result = NO;
            break;
        }
    }

    if (result == NO) {
        _location = oldLocation;
    }

    return result;
}

/**
 @Status Interoperable
*/
- (BOOL)scanUpToString:(NSString*)string intoString:(NSString**)intoString {
    int oldLocation = _location;

    int length = [_string length];
    NSStringCompareOptions compareOption = _isCaseSensitive ? NSCaseInsensitiveSearch : 0;

    if (_skipSet != nil) {
        // skip ahead to first valid character forward in the string.
        NSCharacterSet* invSkipSet = [_skipSet invertedSet];
        NSRange range = [_string rangeOfCharacterFromSet:invSkipSet options:0 range:NSMakeRange(oldLocation, length - oldLocation)];
        oldLocation = range.length > 0 ? range.location : length;
    }

    NSRange foundRange = [_string rangeOfString:string options:compareOption range:NSMakeRange(oldLocation, length - oldLocation)];
    if (foundRange.length == 0) {
        foundRange.location = length;
    }

    if (oldLocation != foundRange.location) {
        if (intoString) {
            *intoString = [_string substringWithRange:NSMakeRange(oldLocation, foundRange.location - oldLocation)];
        }

        _location = foundRange.location;
        return YES;
    }

    return NO;
}

/**
 @Status Interoperable
*/
- (BOOL)scanCharactersFromSet:(id)charset intoString:(NSString**)stringp {
    unsigned int length = (unsigned int)[_string length];
    unichar* result = (unichar*)IwMalloc(length * sizeof(unichar));
    int resultLength = 0;
    BOOL scanStarted = NO;

    for (; _location < length; _location++) {
        unichar unicode = (unichar)[_string characterAtIndex:_location];

        if ([_skipSet characterIsMember:unicode] && (scanStarted == NO)) {
            // do nothing
        } else {
            if ([charset characterIsMember:unicode]) {
                scanStarted = YES;
                result[resultLength++] = unicode;
            } else {
                break; // used to be "return NO";
            }
        }
    }

    if (scanStarted) {
        if (stringp) {
            *stringp = [NSString stringWithCharacters:result length:resultLength];
        }
    }

    IwFree(result);

    return scanStarted;
}

/**
 @Status Interoperable
*/
- (BOOL)scanUpToCharactersFromSet:(id)charset intoString:(NSString**)stringp {
    unsigned int length = (unsigned int)[_string length];
    unichar* result = (unichar*)IwMalloc(length * sizeof(unichar));
    int resultLength = 0;
    BOOL scanStarted = NO;
    int oldLocation = _location;

    for (; _location < length; _location++) {
        unichar unicode = (unichar)[_string characterAtIndex:_location];

        if ([_skipSet characterIsMember:unicode] && scanStarted == NO)
            continue;
        else if ([charset characterIsMember:unicode])
            break;
        else {
            scanStarted = YES;
            result[resultLength++] = unicode;
        }
    }

    if (resultLength > 0) {
        if (stringp) {
            *stringp = [NSString stringWithCharacters:result length:resultLength];
        }

        IwFree(result);
        return YES;
    } else {
        _location = oldLocation;

        IwFree(result);
        return NO;
    }
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)scanDecimal:(NSDecimal*)decimalValue {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)scanHexDouble:(double*)result {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)scanHexFloat:(float*)result {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
 @Notes
*/
- (BOOL)scanUnsignedLongLong:(unsigned long long*)pValue {
    const char* pScanStart = (char*)[_string UTF8String];
    char* pScanEnd = nullptr;

    // Scan the string for a base ten positive integer starting at the internally stored position
    pScanStart += _location;
    unsigned long long val = strtoull(pScanStart, &pScanEnd, 10);
    FAIL_FAST_IF(!pScanEnd);

    // Increment internal position state by the length of the number
    _location += pScanEnd - pScanStart;

    if (pValue) {
        *pValue = val;
    }

    // No digits were read in this case
    if (pScanEnd == pScanStart) {
        return NO;
    }

    return YES;
}

/**
 @Status Stub
 @Notes
*/
+ (id)localizedScannerWithString:(NSString*)aString {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (id)copyWithZone:(NSZone*)zone {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
