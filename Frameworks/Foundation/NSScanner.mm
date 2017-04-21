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

// Helper function for implementing a scan function for a numeric type using a CRT function such as wcstoll
template <typename TNumeric>
static BOOL __scanNumeric(NSScanner* self,
                          TNumeric* valuep,
                          TNumeric (*localeFunc)(const wchar_t*, wchar_t**, int, _locale_t), // eg: _wcstoll_l
                          TNumeric (*nonLocaleFunc)(const wchar_t*, wchar_t**, int), // eg: wcstoll
                          int base,
                          bool enforceUnsigned = false) {
    // Skip past the characters in charactersToBeSkipped
    NSUInteger start = [self _indexOfNextUnskippedCharacter];
    if (start >= self->_stringChars.size()) {
        return NO;
    }

    wchar_t* scanStart = reinterpret_cast<wchar_t*>(self->_stringChars.data() + start);
    wchar_t* scanEnd;

    // Early return for certain characters not in charactersToBeSkipped
    // * Whitespace can be removed from charactersToBeSkipped but still skipped by a CRT function
    // * '-' is skipped without failing in unsigned CRT functions
    if (iswspace(*scanStart) || ((enforceUnsigned) && (*scanStart == '-'))) {
        return NO;
    }

    TNumeric value = self->_crtLocale ? localeFunc(scanStart, &scanEnd, base, self->_crtLocale) : nonLocaleFunc(scanStart, &scanEnd, base);

    if (!scanEnd || scanEnd == scanStart) {
        return NO;
    }

    if (valuep) {
        *valuep = value;
    }

    self.scanLocation = start + (scanEnd - scanStart);
    return YES;
}

// Overload of __scanNumeric for CRT functions that do not take a base parameter
template <typename TNumeric>
static BOOL __scanNumeric(NSScanner* self,
                          TNumeric* valuep,
                          TNumeric (*localeFunc)(const wchar_t*, wchar_t**, _locale_t), // eg: _wcstod_l
                          TNumeric (*nonLocaleFunc)(const wchar_t*, wchar_t**), // eg: wcstod
                          bool enforceUnsigned = false) {
    // Skip past the characters in charactersToBeSkipped
    NSUInteger start = [self _indexOfNextUnskippedCharacter];
    if (start >= self->_stringChars.size()) {
        return NO;
    }

    wchar_t* scanStart = reinterpret_cast<wchar_t*>(self->_stringChars.data() + start);
    wchar_t* scanEnd;

    // Early return for certain characters not in charactersToBeSkipped
    // * Whitespace can be removed from charactersToBeSkipped but still skipped by a CRT function
    // * '-' is skipped without failing in unsigned CRT functions
    if (iswspace(*scanStart) || ((enforceUnsigned) && (*scanStart == '-'))) {
        return NO;
    }

    TNumeric value = self->_crtLocale ? localeFunc(scanStart, &scanEnd, self->_crtLocale) : nonLocaleFunc(scanStart, &scanEnd);

    if (!scanEnd || scanEnd == scanStart) {
        return NO;
    }

    if (valuep) {
        *valuep = value;
    }

    self.scanLocation = start + (scanEnd - scanStart);
    return YES;
}

@implementation NSScanner {
@public
    std::vector<unichar> _stringChars;

    StrongId<NSLocale> _locale;
    _locale_t _crtLocale;
}

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

        _stringChars.resize(_string.length);
        [_string getCharacters:_stringChars.data() range:{ 0, _string.length }];

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

    if (_crtLocale) {
        _free_locale(_crtLocale);
    }

    [super dealloc];
}

/**
 @Status Interoperable
*/
- (id)copyWithZone:(NSZone*)zone {
    NSScanner* ret = [[[self class] alloc] initWithString:_string];
    ret.scanLocation = _scanLocation;
    ret.caseSensitive = _caseSensitive;
    ret.charactersToBeSkipped = _charactersToBeSkipped;
    ret.locale = [[_locale copy] autorelease];

    return ret;
}

/**
 @Status Interoperable
*/
- (NSLocale*)locale {
    @synchronized(self) {
        return [[_locale retain] autorelease];
    }
}

/**
 @Status Interoperable
*/
- (void)setLocale:(NSLocale*)locale {
    @synchronized(self) {
        _locale = locale;

        if (_crtLocale) {
            _free_locale(_crtLocale);
        }

        // create_locale expects "en-US" instead of "en_US"
        std::string localeIdentifier([[_locale objectForKey:NSLocaleLanguageCode] UTF8String]);
        localeIdentifier += "-";
        localeIdentifier += [[_locale objectForKey:NSLocaleCountryCode] UTF8String];
        _crtLocale = _create_locale(LC_ALL, localeIdentifier.data());
    }
}

// Helper function that returns the index of the next character not in charactersToBeSkipped
// Returns string length if no unskippable characters are found
- (NSUInteger)_indexOfNextUnskippedCharacter {
    if (_charactersToBeSkipped) {
        for (NSUInteger i = _scanLocation; i < _stringChars.size(); ++i) {
            if (![_charactersToBeSkipped characterIsMember:_stringChars[i]]) {
                return i;
            }
        }
    }

    return _stringChars.size();
}

/**
 @Status Interoperable
*/
- (BOOL)scanInt:(int*)valuep {
    return __scanNumeric(self, reinterpret_cast<long*>(valuep), _wcstol_l, wcstol, 10);
}

/**
 @Status Interoperable
*/
- (BOOL)scanInteger:(NSInteger*)valuep {
    return __scanNumeric(self, reinterpret_cast<long*>(valuep), _wcstol_l, wcstol, 10);
}

/**
 @Status Interoperable
*/
- (BOOL)scanLongLong:(long long*)valuep {
    return __scanNumeric(self, valuep, _wcstoll_l, wcstoll, 10);
}

/**
 @Status Interoperable
*/
- (BOOL)scanFloat:(float*)valuep {
    return __scanNumeric(self, valuep, _wcstof_l, wcstof);
}

/**
 @Status Interoperable
*/
- (BOOL)scanDouble:(double*)valuep {
    return __scanNumeric(self, valuep, _wcstod_l, wcstod);
}

/**
 @Status Interoperable
*/
- (BOOL)scanHexInt:(unsigned int*)valuep {
    return __scanNumeric(self, reinterpret_cast<unsigned long*>(valuep), _wcstoul_l, wcstoul, 16, true);
}

/**
 @Status Interoperable
*/
- (BOOL)scanHexLongLong:(unsigned long long*)valuep {
    return __scanNumeric(self, valuep, _wcstoull_l, wcstoull, 16, true);
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

    if (!_caseSensitive) {
        compareOption = NSCaseInsensitiveSearch;
    }

    const NSUInteger length = _string.length;
    NSUInteger i = [self _indexOfNextUnskippedCharacter];
    for (; i < length; ++i) {
        range.location = i;
        if ((length - i) < [string length]) {
            return NO;
        }

        if ([_string compare:string
                     options:static_cast<NSStringCompareOptions>(compareOption)
                       range:NSMakeRange(range.location, range.length)] == 0) {
            if (stringp) {
                *stringp = string;
            }

            i += [string length];
            break;
        } else {
            return NO;
        }
    }

    _scanLocation = i;
    return YES;
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
    const NSUInteger start = [self _indexOfNextUnskippedCharacter];
    NSUInteger i = start;

    for (; i < length; ++i) {
        if (![charset characterIsMember:_stringChars[i]]) {
            break;
        }
    }

    if (i > start) {
        if (stringp) {
            *stringp = [NSString stringWithCharacters:(_stringChars.data() + start) length:(i - start)];
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
    return [self scanCharactersFromSet:[charset invertedSet] intoString:stringp];
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
        unichar unicode = _stringChars[i];

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
                        goto DONE_SCANNING_HEXDOUBLE; // Stop scanning once a second period has been scanned
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
                    goto DONE_SCANNING_HEXDOUBLE;
                }
                break;

            case STATE_P:
                if (!hasValue) {
                    goto DONE_SCANNING_HEXDOUBLE;
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
                    goto DONE_SCANNING_HEXDOUBLE;
                }
                break;

            case STATE_EXPONENT:
                if (unicode >= '0' && unicode <= '9') {
                    // can stop calculating the change to the exponent once this is false, and let ldexp return 0 or HUGE_VAL
                    if (exponent <= (exponentIsNegative ? 1023 : 1024)) {
                        exponent = exponent * 10 + (unicode - '0');
                    }

                } else {
                    goto DONE_SCANNING_HEXDOUBLE;
                }
                break;
        }
    }

DONE_SCANNING_HEXDOUBLE:; // Allows breaking out of the loop from inside the switch
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
- (BOOL)scanUnsignedLongLong:(unsigned long long*)valuep {
    return __scanNumeric(self, valuep, _wcstoull_l, wcstoull, 10, true);
}

/**
 @Status Interoperable
*/
- (BOOL)isAtEnd {
    @synchronized(self) {
        NSUInteger length = [_string length];
        NSUInteger currentLocation = _scanLocation;

        for (; currentLocation < length; currentLocation++) {
            if ([_charactersToBeSkipped characterIsMember:_stringChars[currentLocation]] == YES) {
                continue;
            } else {
                return NO;
            }
        }

        return YES;
    }
}

@end
