/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

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

#include "Starboard.h"
#include "Foundation/NSString.h"
#include "Foundation/NSCharacterSet.h"
#include "Foundation/NSScanner.h"
#include <limits.h>

#include "unicode/uniset.h"

typedef unsigned short unichar;
#define YES 1
#define NO 0

@implementation NSScanner : NSObject
+ (instancetype)scannerWithString:(id)str {
    NSScanner* ret = [self alloc];

    return [[ret initWithString:str] autorelease];
}

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

- (NSString*)string {
    return _string;
}

- (void)dealloc {
    [_string release];
    [_skipSet release];
    [_locale release];
    [super dealloc];
}

- (NSCharacterSet*)charactersToBeSkipped {
    return _skipSet;
}

- (BOOL)caseSensitive {
    return _isCaseSensitive;
}

- (id)locale {
    return _locale;
}

- (void)setCharactersToBeSkipped:(id)set {
    if (set != _skipSet) {
        set = [set retain];
        [_skipSet release];
        _skipSet = set;
    }
}

- (void)setCaseSensitive:(BOOL)flag {
    _isCaseSensitive = flag;
}

- (void)setLocale:(id)locale {
    if (locale != _locale) {
        locale = [locale retain];
        [_locale release];
        _locale = locale;
    }
}

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

- (NSUInteger)scanLocation {
    // return _location < _len ? _location : _len - 1;
    return _location;
}

- (void)setScanLocation:(NSUInteger)pos {
    _location = pos;
}

- (BOOL)scanInt:(int*)valuep {
    long long scanValue = 0;

    // This assumes sizeof(long long) >= sizeof(int).
    if (![self scanLongLong:&scanValue]) {
        return FALSE;
    } else if (NULL != valuep) {
        if (scanValue > INT_MAX)
            *valuep = INT_MAX;
        else if (scanValue < INT_MIN)
            *valuep = INT_MIN;
        else
            *valuep = (int)scanValue;
    }

    return TRUE;
}

- (BOOL)scanInteger:(int*)valuep {
    long long scanValue = 0;

    // This assumes sizeof(long long) >= sizeof(int).
    if (![self scanLongLong:&scanValue]) {
        return FALSE;
    } else if (NULL != valuep) {
        if (scanValue > LONG_MAX)
            *valuep = LONG_MAX;
        else if (scanValue < LONG_MIN)
            *valuep = LONG_MIN;
        else
            *valuep = (int)scanValue;
    }

    return TRUE;
}

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
        if (NULL != valuep) {
            if (sign > 0)
                *valuep = long_long_MAX;
            else
                *valuep = long_long_MIN;
        }

        return TRUE;
    } else if (hasValue) {
        if (NULL != valuep)
            *valuep = sign * value;
        return TRUE;
    }

    return FALSE;
}

- (BOOL)scanFloat:(float*)valuep {
    double d;
    BOOL r;

    r = [self scanDouble:&d];

    if (NULL != valuep)
        *valuep = (float)d;
    return r;
}

- (BOOL)scanDouble:(double*)valuep {
    /*
    // "...returns HUGE_VAL or -HUGE_VAL on overflow, 0.0 on underflow." hmm...
    double value;
    id seperatorString;
    unichar decimalSeperator;
    if( _locale )
    seperatorString = _locale("objectForKey:", @"NSLocaleDecimalSeparator");
    else
    seperatorString = nil;

    decimalSeperator = (seperatorString("length") > 0 ) ? seperatorString("characterAtIndex:", 0) : '.';

    int i;
    int len = _string("length") - _location;
    char *p = (char *) EbrMalloc(len + 1), *q;
    unichar c;

    for (i = 0; i < len; i++)
    {
    c  = _string("characterAtIndex:", i + _location);

    switch ( c ) {
    case '\r':
    break;

    case '\n':
    break;


    if (c == decimalSeperator) c = '.';
    p[i] = (char)c;
    }

    p[i] = '\0';

    value = strtod(p, &q);
    if (NULL != valuep)
    *valuep = value;
    _location += (q - p);
    int ret = (q > p);
    free(p);

    return ret;
    */

    char* pScanStart = (char*)[_string UTF8String];
    char* pScanEnd = NULL;

    pScanStart += _location;

    double val = strtod(pScanStart, &pScanEnd);
    assert(pScanEnd != NULL);

    _location += pScanEnd - pScanStart;

    if (valuep)
        *valuep = val;

    if ((pScanEnd - pScanStart) == 0) {
        return FALSE;
    }

    return TRUE;
}

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
                    if (valuep != NULL)
                        *valuep = value;

                    return YES;
                }
                break;
        }
    }

    if (hasValue) {
        if (valuep != NULL)
            *valuep = value;

        return YES;
    }

    return NO;
}

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
                    if (valuep != NULL)
                        *valuep = value;

                    return YES;
                }
                break;
        }
    }

    if (hasValue) {
        if (valuep != NULL)
            *valuep = value;

        return YES;
    }
    return NO;
}

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
        if ([_string compare:string options:compareOption range:NSMakeRange(range.location, range.length)] == 0) {
            if (stringp != NULL)
                *stringp = string;

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

- (BOOL)scanUpToString:(id)string intoString:(NSString**)stringp {
    int oldLocation = _location;

    UStringHolder s1(_string);
    UnicodeString str1(s1.string(), _location, s1.string().length() - _location);

    int length = str1.length();
    if (_skipSet != nil) {
        NSCharacterSet* charSet = _skipSet;
        UnicodeSet& set = *charSet->_icuSet;

        int pos = set.span(str1, 0, USET_SPAN_CONTAINED);
        if (pos == length) {
            _location += length;
            return NO;
        }
        _location += pos;
    }

    NSRange searchRange = { _location, [_string length] - _location };
    NSRange foundRange;

    int compareOption = 0;
    if (!_isCaseSensitive) {
        compareOption = 1; //  NSCaseInsensitiveSearch
    }

    foundRange = [_string rangeOfString:string options:compareOption range:searchRange];
    if (foundRange.location == searchRange.location) {
        return NO;
    }
    if (foundRange.length > 0) {
        searchRange.length = foundRange.location - _location;
    }

    if (searchRange.length == 0) {
        _location = oldLocation;
        return NO;
    }
    if (stringp) {
        *stringp = [_string substringWithRange:searchRange];
    }
    _location += searchRange.length;

    return TRUE;
}

- (BOOL)scanCharactersFromSet:(id)charset intoString:(NSString**)stringp {
    unsigned int length = (unsigned int)[_string length];
    unichar* result = (unichar*)malloc(length * sizeof(unichar));
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
        if (stringp != NULL) {
            *stringp = [NSString stringWithCharacters:result length:resultLength];
        }
    }

    free(result);

    return scanStarted;
}

- (BOOL)scanUpToCharactersFromSet:(id)charset intoString:(NSString**)stringp {
    unsigned int length = (unsigned int)[_string length];
    unichar* result = (unichar*)malloc(length * sizeof(unichar));
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
        if (stringp != NULL)
            *stringp = [NSString stringWithCharacters:result length:resultLength];

        free(result);
        return YES;
    } else {
        _location = oldLocation;

        free(result);
        return NO;
    }
}

@end
