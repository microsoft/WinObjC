/* Copyright (c) 2006-2007 Christopher J. W. Lloyd
   Copyright (c) Microsoft. All rights reserved.

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

#import <Foundation/NSScanner.h>
#import <Foundation/NSCharacterSet.h>
#import <Foundation/NSDecimalNumber.h>
#import <Foundation/NSString.h>

#import <Starboard.h>

#import <cctype>
#import <limits>
#import <vector>

@implementation NSScanner

/**
 @Status Interoperable
*/
+ (instancetype)scannerWithString:(NSString* _Nonnull)string {
    return [[[self alloc] initWithString:string] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)localizedScannerWithString:(NSString* _Nonnull)string {
    NSScanner* ret = [self scannerWithString:string];
    ret.locale = [NSLocale currentLocale];
    return ret;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithString:(NSString* _Nonnull)string {
    if (self = [super init]) {
        _string = [string copy];

        // Don't need to copy here as whitespaceAndNewlineCharacterSet is a copy property
        _charactersToBeSkipped = [[NSCharacterSet whitespaceAndNewlineCharacterSet] retain];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    [_string release];
    [_charactersToBeSkipped release];
    [_locale release];

    [super dealloc];
}

/**
 @Status Interoperable
*/
- (id)copyWithZone:(NSZone*)zone {
    NSScanner* ret = [[[self class] alloc] initWithString:_string];
    ret->_scanLocation = _scanLocation;
    ret->_caseSensitive = _caseSensitive;
    ret->_charactersToBeSkipped = [_charactersToBeSkipped copy];
    ret->_locale = [_locale copy];

    return ret;
}

// Helper function that returns the index of the next character not in charactersToBeSkipped
// Returns string length if no unskippable characters are found
- (NSUInteger)_indexOfNextUnskippedCharacter {
    const NSUInteger length = _string.length;
    NSUInteger ret = _scanLocation;

    if (_charactersToBeSkipped) {
        for (; ret < length; ++ret) {
            if (![_charactersToBeSkipped characterIsMember:(unichar)[_string characterAtIndex:ret]]) {
                return ret;
            }
        }
    }

    return length;
}

/**
 @Status Interoperable
*/
- (BOOL)scanInt:(int*)valuep {
    long long scanValue = 0;

    // This assumes sizeof(long long) >= sizeof(int).
    if (![self scanLongLong:&scanValue]) {
        return NO;
    } else if (valuep) {
        if (scanValue > INT_MAX) {
            *valuep = INT_MAX;
        } else if (scanValue < INT_MIN) {
            *valuep = INT_MIN;
        } else {
            *valuep = (int)scanValue;
        }
    }

    return YES;
}

/**
 @Status Interoperable
*/
- (BOOL)scanInteger:(int*)valuep {
    long long scanValue = 0;

    // This assumes sizeof(long long) >= sizeof(int).
    if (![self scanLongLong:&scanValue]) {
        return NO;
    } else if (valuep) {
        if (scanValue > LONG_MAX) {
            *valuep = LONG_MAX;
        } else if (scanValue < LONG_MIN) {
            *valuep = LONG_MIN;
        } else {
            *valuep = (int)scanValue;
        }
    }

    return YES;
}

/**
 @Status Interoperable
*/
- (BOOL)scanLongLong:(long long*)valuep {
    int sign = 1;
    BOOL hasSign = NO;
    long long value = 0;
    BOOL hasValue = NO;
    BOOL hasOverflow = NO;

    const long long longLongMax = std::numeric_limits<long long>::max();

    const NSUInteger length = _string.length;
    NSUInteger i = [self _indexOfNextUnskippedCharacter];
    for (; i < length; ++i) {
        unichar unicode = (unichar)[_string characterAtIndex:i];

        if (!hasSign && unicode == '-') {
            sign = -1;
            hasSign = YES;
        } else if (!hasSign && unicode == '+') {
            sign = 1;
            hasSign = YES;
        } else if (unicode >= '0' && unicode <= '9') {
            if (!hasOverflow) {
                int c = unicode - '0';

                // Inspired by http://www.math.utoledo.edu/~dbastos/overflow.html
                if ((longLongMax - c) / 10 < value)
                    hasOverflow = YES;
                else
                    value = (value * 10) + c;
                hasSign = YES;
                hasValue = YES;
            }
        } else
            break;
    }

    if (hasOverflow) {
        if (valuep) {
            if (sign > 0) {
                *valuep = longLongMax;
            } else {
                *valuep = std::numeric_limits<long long>::min();
            }
        }

        _scanLocation = i;
        return YES;
    } else if (hasValue) {
        if (valuep) {
            *valuep = sign * value;
        }

        _scanLocation = i;
        return YES;
    }

    return NO;
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
    NSUInteger startLocation = [self _indexOfNextUnskippedCharacter];
    const NSUInteger length = _string.length;
    if (startLocation >= length) {
        return NO;
    }

    char* pScan = (char*)[_string UTF8String] + startLocation;

    // strtod automatically takes care of spaces (needs to be explicitly specified in charactersToBeSkipped),
    // and only expects '.' as a decimal separator
    // copy a scannable range of the string to a new buffer, adjusting for these constraints
    char decimalSeparator;
    if ((!_locale) ||
        (![[_locale objectForKey:NSLocaleDecimalSeparator] getCString:&decimalSeparator maxLength:1 encoding:NSASCIIStringEncoding])) {
        decimalSeparator = '.';
    }

    std::vector<char> charsToScan;
    charsToScan.reserve(_string.length - startLocation);
    for (NSUInteger i = startLocation; i < length; ++i, ++pScan) {
        if ((*pScan >= '0') && (*pScan <= '9')) {
            charsToScan.push_back(*pScan);

        } else if (*pScan == decimalSeparator) {
            // Add a decimal separator that strtod will accept
            charsToScan.push_back('.');

        } else {
            break;
        }
    }

    if (charsToScan.size() == 0) {
        return NO;
    }

    char* pScanEnd = nullptr;
    double val = strtod(charsToScan.data(), &pScanEnd);

    if ((!pScanEnd) || (pScanEnd == charsToScan.data())) {
        return NO;
    }

    _scanLocation = startLocation + (pScanEnd - charsToScan.data());

    if (valuep) {
        *valuep = val;
    }

    return YES;
}

/**
 @Status Interoperable
*/
- (BOOL)scanHexInt:(unsigned*)valuep {
    enum {
        STATE_START,
        STATE_ZERO,
        STATE_HEX,
    } state = STATE_START;
    unsigned value = 0;
    BOOL hasValue = NO;
    BOOL overflow = NO;

    const NSUInteger length = _string.length;
    NSUInteger i = [self _indexOfNextUnskippedCharacter];
    for (; i < length; ++i) {
        unichar unicode = (unichar)[_string characterAtIndex:i];

        switch (state) {
            case STATE_START:
                if (unicode == '0') {
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
                        if (0xF0000000 & value) {
                            value = std::numeric_limits<unsigned int>::max();
                            overflow = YES;
                        } else {
                            value = value * 16 + (unicode - '0');
                        }
                    }
                } else if (unicode >= 'a' && unicode <= 'f') {
                    if (!overflow) {
                        if (0xF0000000 & value) {
                            value = std::numeric_limits<unsigned int>::max();
                            overflow = YES;
                        } else {
                            value = value * 16 + (unicode - 'a') + 10;
                        }
                    }
                } else if (unicode >= 'A' && unicode <= 'F') {
                    if (!overflow) {
                        if (0xF0000000 & value) {
                            value = std::numeric_limits<unsigned int>::max();
                            overflow = YES;
                        } else {
                            value = value * 16 + (unicode - 'A') + 10;
                        }
                    }
                } else {
                    if (valuep) {
                        *valuep = value;
                    }

                    _scanLocation = i;
                    return YES;
                }
                break;
        }
    }

    if (hasValue) {
        if (valuep) {
            *valuep = value;
        }

        _scanLocation = i;
        return YES;
    }

    return NO;
}

/**
 @Status Interoperable
*/
- (BOOL)scanHexLongLong:(unsigned long long*)valuep {
    enum {
        STATE_START,
        STATE_ZERO,
        STATE_HEX,
    } state = STATE_START;
    unsigned long long value = 0;
    BOOL hasValue = NO;
    BOOL overflow = NO;

    const NSUInteger length = _string.length;
    NSUInteger i = [self _indexOfNextUnskippedCharacter];
    for (; i < length; ++i) {
        unichar unicode = (unichar)[_string characterAtIndex:i];

        switch (state) {
            case STATE_START:
                if (unicode == '0') {
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
                        if (0xF000000000000000 & value) {
                            value = std::numeric_limits<unsigned long long>::max();
                            overflow = YES;
                        } else {
                            value = value * 16 + (unicode - '0');
                        }
                    }
                } else if (unicode >= 'a' && unicode <= 'f') {
                    if (!overflow) {
                        if (0xF000000000000000 & value) {
                            value = std::numeric_limits<unsigned long long>::max();
                            overflow = YES;
                        } else {
                            value = value * 16 + (unicode - 'a') + 10;
                        }
                    }
                } else if (unicode >= 'A' && unicode <= 'F') {
                    if (!overflow) {
                        if (0xF000000000000000 & value) {
                            value = std::numeric_limits<unsigned long long>::max();
                            overflow = YES;
                        } else {
                            value = value * 16 + (unicode - 'A') + 10;
                        }
                    }
                } else {
                    if (valuep) {
                        *valuep = value;
                    }

                    _scanLocation = i;
                    return YES;
                }
                break;
        }
    }

    if (hasValue) {
        if (valuep) {
            *valuep = value;
        }

        _scanLocation = i;
        return YES;
    }
    return NO;
}

/**
 @Status Interoperable
*/
- (BOOL)scanString:(NSString* _Nonnull)string intoString:(NSString* _Nullable*)stringp {
    if (string.length == 0) {
        return NO;
    }

    NSStringCompareOptions compareOption = 0;
    NSRange range = { 0, string.length };
    BOOL result = NO;

    if (!_caseSensitive) {
        compareOption = NSCaseInsensitiveSearch;
    }

    const NSUInteger length = _string.length;
    NSUInteger i = [self _indexOfNextUnskippedCharacter];
    for (; i < length; ++i) {
        unichar unicode = (unichar)[_string characterAtIndex:i];
        range.location = i;
        if ((length - i) < [string length]) {
            result = NO;
            break;
        }

        if ([_string compare:string
                     options:static_cast<NSStringCompareOptions>(compareOption)
                       range:NSMakeRange(range.location, range.length)] == 0) {
            if (stringp) {
                *stringp = string;
            }

            i += [string length];

            result = YES;
            break;
        } else {
            result = NO;
            break;
        }
    }

    if (result) {
        _scanLocation = i;
    }

    return result;
}

/**
 @Status Interoperable
*/
- (BOOL)scanUpToString:(NSString* _Nonnull)string intoString:(NSString* _Nullable*)intoString {
    const NSUInteger length = _string.length;
    const NSStringCompareOptions compareOption = _caseSensitive ? NSCaseInsensitiveSearch : 0;
    const NSUInteger start = [self _indexOfNextUnskippedCharacter];

    NSRange foundRange = [_string rangeOfString:string options:compareOption range:NSMakeRange(start, length - start)];
    if (foundRange.length == 0) {
        foundRange.location = length;
    }

    if (start != foundRange.location) {
        if (intoString) {
            *intoString = [_string substringWithRange:NSMakeRange(start, foundRange.location - start)];
        }

        _scanLocation = foundRange.location;
        return YES;
    }

    return NO;
}

/**
 @Status Interoperable
*/
- (BOOL)scanCharactersFromSet:(NSCharacterSet* _Nonnull)charset intoString:(NSString* _Nullable*)stringp {
    const NSUInteger length = _string.length;
    NSUInteger i = [self _indexOfNextUnskippedCharacter];

    std::vector<unichar> result;
    result.reserve(length - i);
    for (; i < length; ++i) {
        unichar unicode = (unichar)[_string characterAtIndex:i];

        if ([charset characterIsMember:unicode]) {
            result.push_back(unicode);
        } else {
            break;
        }
    }

    if (result.size() > 0) {
        if (stringp) {
            *stringp = [NSString stringWithCharacters:result.data() length:result.size()];
        }

        _scanLocation = i;
        return YES;
    }

    return NO;
}

/**
 @Status Interoperable
*/
- (BOOL)scanUpToCharactersFromSet:(NSCharacterSet* _Nonnull)charset intoString:(NSString* _Nullable*)stringp {
    const NSUInteger length = _string.length;
    NSUInteger i = [self _indexOfNextUnskippedCharacter];

    std::vector<unichar> result;
    result.reserve(length - i);
    for (; i < length; ++i) {
        unichar unicode = (unichar)[_string characterAtIndex:i];

        if ([charset characterIsMember:unicode]) {
            break;
        } else {
            result.push_back(unicode);
        }
    }

    if (result.size() > 0) {
        if (stringp) {
            *stringp = [NSString stringWithCharacters:result.data() length:result.size()];
        }

        _scanLocation = i;
        return YES;
    }

    return NO;
}

/**
 @Status Interoperable
 @Notes
*/
- (BOOL)scanDecimal:(NSDecimal*)decimalValue {
    // TODO #2369: This could probably be made more precise if it scanned directly from string -> NSDecimalNumber
    // but WinObjC does not have [NSDecimalNumber decimalNumberWithString:] yet
    double doubleValue;
    if (![self scanDouble:&doubleValue]) {
        return NO;
    }

    if (decimalValue) {
        *decimalValue = [[NSDecimalNumber numberWithDouble:doubleValue] decimalValue];
    }

    return YES;
}

/**
 @Status Interoperable
 @Notes
*/
- (BOOL)scanHexDouble:(double*)result {
    enum {
        STATE_START,
        STATE_SIGN,
        STATE_ZERO,
        STATE_MANTISSA,
        STATE_P,
        STATE_EXPONENT,
    } state = STATE_START;

    bool mantissaIsNegative = false;
    bool exponentIsNegative = false;
    bool scannedPeriod = false;
    bool hasValue = false;

    double mantissa = 0;
    int exponent = 0;

    // Once a '.' has been scanned, this /= 16 every character, so that each base-16 decimal digit is appropriately placed
    // ie: 1.1ae = 1 + (1 * (mantissaDigitPlace /= 16)) + (a * (mantissaDigitPlace /= 16)) + (e * (mantissaDigitPlace /= 16))
    double mantissaDigitPlace = 1;

    const NSUInteger length = _string.length;
    NSUInteger i = [self _indexOfNextUnskippedCharacter];
    for (; i < length; ++i) {
        unichar unicode = (unichar)[_string characterAtIndex:i];

        switch (state) {
            case STATE_START:
                if (unicode == '-') {
                    state = STATE_SIGN;
                    mantissaIsNegative = true;
                } else if (unicode == '+') {
                    state = STATE_SIGN;
                } else if (unicode == '0') {
                    state = STATE_ZERO;
                } else {
                    return NO;
                }
                break;

            case STATE_SIGN:
                if (unicode == '0') {
                    state = STATE_ZERO;
                } else {
                    return NO;
                }
                break;

            case STATE_ZERO:
                if (unicode == 'x' || unicode == 'X') {
                    state = STATE_MANTISSA;
                } else {
                    return NO;
                }
                break;

            case STATE_MANTISSA:
                if (unicode == '.') {
                    if (!scannedPeriod) {
                        scannedPeriod = true;
                    } else {
                        goto done_scanning_hex_double; // Stop scanning once a second period has been scanned
                    }

                } else if (unicode >= '0' && unicode <= '9') {
                    if (scannedPeriod) {
                        mantissa += (mantissaDigitPlace /= 16) * (unicode - '0');
                    } else {
                        mantissa = (mantissa * 16) + (unicode - '0');
                    }
                    hasValue = true;

                } else if (unicode >= 'a' && unicode <= 'f') {
                    if (scannedPeriod) {
                        mantissa += (mantissaDigitPlace /= 16) * (unicode - 'a' + 10);
                    } else {
                        mantissa = (mantissa * 16) + (unicode - 'a' + 10);
                    }
                    hasValue = true;

                } else if (unicode >= 'A' && unicode <= 'F') {
                    if (scannedPeriod) {
                        mantissa += (mantissaDigitPlace /= 16) * (unicode - 'A' + 10);
                    } else {
                        mantissa = (mantissa * 16) + (unicode - 'A' + 10);
                    }
                    hasValue = true;

                } else if (unicode == 'p' || unicode == 'P') {
                    state = STATE_P;

                } else {
                    goto done_scanning_hex_double;
                }
                break;

            case STATE_P:
                if (!hasValue) {
                    goto done_scanning_hex_double;
                }
                if (unicode == '-') {
                    state = STATE_EXPONENT;
                    exponentIsNegative = true;

                } else if (unicode == '+') {
                    state = STATE_EXPONENT;

                } else if (unicode >= '0' && unicode <= '9') {
                    exponent = (unicode - '0');
                    state = STATE_EXPONENT;

                } else {
                    goto done_scanning_hex_double;
                }
                break;

            case STATE_EXPONENT:
                if (unicode >= '0' && unicode <= '9') {
                    // can stop calculating the change to the exponent once this is false, and let ldexp return 0 or HUGE_VAL
                    if (exponent <= (exponentIsNegative ? 1023 : 1024)) {
                        exponent = exponent * 10 + (unicode - '0');
                    }

                } else {
                    goto done_scanning_hex_double;
                }
                break;
        }
    }

done_scanning_hex_double:; // Allows breaking out of the loop from inside the switch
    if (hasValue) {
        if (result) {
            if (exponentIsNegative) {
                exponent *= -1;
            }

            *result = mantissaIsNegative ? -ldexp(mantissa, exponent) : ldexp(mantissa, exponent);
        }

        _scanLocation = i;
        return YES;
    }

    return NO;
}

/**
 @Status Interoperable
 @Notes
*/
- (BOOL)scanHexFloat:(float*)result {
    double doubleValue;
    if (![self scanHexDouble:&doubleValue]) {
        return NO;
    }

    if (result) {
        *result = static_cast<float>(doubleValue);
    }
    return YES;
}

/**
 @Status Interoperable
 @Notes
*/
- (BOOL)scanUnsignedLongLong:(unsigned long long*)pValue {
    NSUInteger startLocation = [self _indexOfNextUnskippedCharacter];
    if (startLocation >= _string.length) {
        return NO;
    }

    // Scan the string for a base ten positive integer starting at the internally stored position
    const char* pScanStart = (char*)[_string UTF8String] + startLocation;
    char* pScanEnd = nullptr;

    // Reject any negative numbers
    long long signedVal = strtoll(pScanStart, &pScanEnd, 10);
    if (signedVal < 0) {
        return NO;
    }

    // Scan again in unsigned if the number was too big to fit in a signed long long
    unsigned long long val;
    if (signedVal == std::numeric_limits<long long>::max()) {
        val = strtoull(pScanStart, &pScanEnd, 10);
    } else {
        val = static_cast<unsigned long long>(signedVal);
    }
    FAIL_FAST_IF(!pScanEnd);

    // Increment internal position state by the length of the number
    _scanLocation = startLocation + (pScanEnd - pScanStart);

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
 @Status Interoperable
*/
- (BOOL)isAtEnd {
    @synchronized(self) {
        NSUInteger length = [_string length];
        NSUInteger currentLocation = _scanLocation;

        for (; currentLocation < length; currentLocation++) {
            if ([_charactersToBeSkipped characterIsMember:[_string characterAtIndex:currentLocation]] == YES) {
                continue;
            } else {
                return NO;
            }
        }

        return YES;
    }
}

@end
