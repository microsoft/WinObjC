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

#import <algorithm>
#import <cctype>
#import <functional>
#import <limits>
#import <vector>

// Helper function for implementing a scan function for a numeric type using a CRT function such as wcstoll
template <typename TNumeric>
static BOOL __scanNumeric(NSScanner* scanner,
                          TNumeric* valuep,
                          std::function<TNumeric(const wchar_t*, wchar_t**)> crtScanFunc, // Should call a crt function like wcstoll
                          bool enforceUnsigned = false) {
    // Skip past the characters in charactersToBeSkipped
    NSUInteger start = [scanner _indexOfNextUnskippedCharacter];
    if (start >= scanner->_stringChars.size() - 1) {
        return NO;
    }

    wchar_t* scanStart = reinterpret_cast<wchar_t*>(scanner->_stringChars.data() + start);
    wchar_t* scanEnd;

    // Early return for certain characters not in charactersToBeSkipped
    // * Whitespace can be removed from charactersToBeSkipped but still skipped by a CRT function
    // * '-' is skipped without failing in unsigned CRT functions
    if (iswspace(*scanStart) || ((enforceUnsigned) && (*scanStart == L'-'))) {
        return NO;
    }

    TNumeric value = crtScanFunc(scanStart, &scanEnd);

    if (!scanEnd || scanEnd == scanStart) {
        return NO;
    }

    if (valuep) {
        *valuep = value;
    }

    scanner.scanLocation = std::min(start + (scanEnd - scanStart), scanner->_stringChars.size() - 1);
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

        _stringChars.resize(_string.length + 1);
        [_string getCharacters:_stringChars.data() range:{ 0, _string.length }];

        // Ensure terminating null char for correct CRT function behavior
        _stringChars[_stringChars.size() - 1] = 0;

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
        for (NSUInteger i = _scanLocation; i < _stringChars.size() - 1; ++i) {
            if (![_charactersToBeSkipped characterIsMember:_stringChars[i]]) {
                return i;
            }
        }
    }

    return _stringChars.size() - 1;
}

/**
 @Status Interoperable
*/
- (BOOL)scanInt:(int*)valuep {
    std::function<long(const wchar_t*, wchar_t**)> scanFunc = [self](const wchar_t* scanStart, wchar_t** scanEnd) {
        return _crtLocale ? _wcstol_l(scanStart, scanEnd, 10, _crtLocale) : wcstol(scanStart, scanEnd, 10);
    };
    return __scanNumeric(self, reinterpret_cast<long*>(valuep), scanFunc);
}

/**
 @Status Interoperable
*/
- (BOOL)scanInteger:(NSInteger*)valuep {
    long longValue;
    std::function<long(const wchar_t*, wchar_t**)> scanFunc = [self](const wchar_t* scanStart, wchar_t** scanEnd) {
        return _crtLocale ? _wcstol_l(scanStart, scanEnd, 10, _crtLocale) : wcstol(scanStart, scanEnd, 10);
    };

    if (!__scanNumeric(self, &longValue, scanFunc)) {
        return NO;
    }

    if (valuep) {
        *valuep = static_cast<NSInteger>(longValue);
    }

    return YES;
}

/**
 @Status Interoperable
*/
- (BOOL)scanLongLong:(long long*)valuep {
    std::function<long long(const wchar_t*, wchar_t**)> scanFunc = [self](const wchar_t* scanStart, wchar_t** scanEnd) {
        return _crtLocale ? _wcstoll_l(scanStart, scanEnd, 10, _crtLocale) : wcstoll(scanStart, scanEnd, 10);
    };
    return __scanNumeric(self, valuep, scanFunc);
}

/**
 @Status Interoperable
*/
- (BOOL)scanFloat:(float*)valuep {
    std::function<float(const wchar_t*, wchar_t**)> scanFunc = [self](const wchar_t* scanStart, wchar_t** scanEnd) {
        return _crtLocale ? _wcstof_l(scanStart, scanEnd, _crtLocale) : wcstof(scanStart, scanEnd);
    };
    return __scanNumeric(self, valuep, scanFunc);
}

/**
 @Status Interoperable
*/
- (BOOL)scanDouble:(double*)valuep {
    std::function<double(const wchar_t*, wchar_t**)> scanFunc = [self](const wchar_t* scanStart, wchar_t** scanEnd) {
        return _crtLocale ? _wcstod_l(scanStart, scanEnd, _crtLocale) : wcstod(scanStart, scanEnd);
    };
    return __scanNumeric(self, valuep, scanFunc);
}

/**
 @Status Interoperable
*/
- (BOOL)scanHexInt:(unsigned int*)valuep {
    std::function<unsigned long(const wchar_t*, wchar_t**)> scanFunc = [self](const wchar_t* scanStart, wchar_t** scanEnd) {
        return _crtLocale ? _wcstoul_l(scanStart, scanEnd, 16, _crtLocale) : wcstoul(scanStart, scanEnd, 16);
    };
    return __scanNumeric(self, reinterpret_cast<unsigned long*>(valuep), scanFunc, true);
}

/**
 @Status Interoperable
*/
- (BOOL)scanHexLongLong:(unsigned long long*)valuep {
    std::function<unsigned long long(const wchar_t*, wchar_t**)> scanFunc = [self](const wchar_t* scanStart, wchar_t** scanEnd) {
        return _crtLocale ? _wcstoull_l(scanStart, scanEnd, 16, _crtLocale) : wcstoull(scanStart, scanEnd, 16);
    };
    return __scanNumeric(self, valuep, scanFunc, true);
}

/**
 @Status Interoperable
*/
- (BOOL)scanString:(NSString* _Nonnull)string intoString:(NSString* _Nullable*)stringp {
    const NSUInteger length = string.length;
    if (length == 0) {
        return NO;
    }

    NSStringCompareOptions compareOption = 0;
    NSRange range = { 0, length };

    if (!_caseSensitive) {
        compareOption = NSCaseInsensitiveSearch;
    }

    const NSUInteger selfLength = _string.length;
    NSUInteger i = [self _indexOfNextUnskippedCharacter];
    for (; i < selfLength; ++i) {
        range.location = i;
        if ((selfLength - i) < length) {
            return NO;
        }

        if ([_string compare:string
                     options:static_cast<NSStringCompareOptions>(compareOption)
                       range:NSMakeRange(range.location, range.length)] == 0) {
            if (stringp) {
                *stringp = string;
            }

            i += length;
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
        STATE_SIGN,
        STATE_ZERO,
        STATE_X,
        STATE_MANTISSA,
        STATE_EXPONENT_SIGN,
        STATE_EXPONENT,
    } state = STATE_SIGN;

    const NSUInteger oldScanLocation = _scanLocation;

    // Resets scanLocation once the function exits.
    // In the success case, this is dismissed (not executed) so that scanLocation can properly advance.
    auto resetScanLocationOnExit = wil::ScopeExit([self, oldScanLocation]() { _scanLocation = oldScanLocation; });

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
    bool done = false;
    for (_scanLocation = [self _indexOfNextUnskippedCharacter]; (_scanLocation < length) && (!done); ++_scanLocation) {
        unichar ch = _stringChars[_scanLocation];

        switch (state) {
            case STATE_SIGN:
                if (ch == L'-') {
                    state = STATE_ZERO;
                    mantissaIsNegative = true;
                } else if (ch == L'+') {
                    state = STATE_ZERO;
                } else if (ch == L'0') {
                    state = STATE_X;
                } else {
                    return NO;
                }
                break;

            case STATE_ZERO:
                if (ch == L'0') {
                    state = STATE_X;
                } else {
                    return NO;
                }
                break;

            case STATE_X:
                if (ch == L'x' || ch == L'X') {
                    state = STATE_MANTISSA;
                } else {
                    return NO;
                }
                break;

            case STATE_MANTISSA:
                int charValue;
                if (ch >= '0' && ch <= '9') {
                    charValue = ch - '0';

                } else if (ch >= 'a' && ch <= 'f') {
                    charValue = ch - 'a' + 10;

                } else if (ch >= 'A' && ch <= 'F') {
                    charValue = ch - 'A' + 10;

                } else if (ch == L'p' || ch == L'P') {
                    state = STATE_EXPONENT_SIGN;
                    continue;

                } else if ((ch == L'.') && (!scannedPeriod)) {
                    scannedPeriod = true;
                    continue;

                } else {
                    done = true;
                    --_scanLocation;
                    continue;
                }

                if (scannedPeriod) {
                    mantissa += (mantissaDigitPlace /= 16) * charValue;
                } else {
                    mantissa = (mantissa * 16) + charValue;
                }
                hasValue = true;
                break;

            case STATE_EXPONENT_SIGN:
                if (ch == L'-') {
                    state = STATE_EXPONENT;
                    exponentIsNegative = true;

                } else if (ch == L'+') {
                    state = STATE_EXPONENT;

                } else if (iswdigit(ch)) {
                    state = STATE_EXPONENT;
                    --_scanLocation;
                    continue;

                } else {
                    return NO;
                }
                break;

            case STATE_EXPONENT:
                if (iswdigit(ch) && [self scanInt:&exponent]) {
                    done = true;
                    --_scanLocation;

                } else {
                    return NO;
                }
                break;
        }
    }

    if (hasValue) {
        if (result) {
            if (exponentIsNegative) {
                exponent *= -1;
            }

            *result = mantissaIsNegative ? -ldexp(mantissa, exponent) : ldexp(mantissa, exponent);
        }
        resetScanLocationOnExit.Dismiss();
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
    std::function<unsigned long long(const wchar_t*, wchar_t**)> scanFunc = [self](const wchar_t* scanStart, wchar_t** scanEnd) {
        return _crtLocale ? _wcstoull_l(scanStart, scanEnd, 10, _crtLocale) : wcstoull(scanStart, scanEnd, 10);
    };
    return __scanNumeric(self, valuep, scanFunc, true);
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
