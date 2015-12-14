/* Copyright (c) 2006-2007 Christopher J. W. Lloyd <cjwl@objc.net>

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
#include "Foundation/NSNumberFormatter.h"
#include "Foundation/NSMutableString.h"
#include "Foundation/NSNumber.h"
#include "Foundation/NSAttributedString.h"
#include "Etc.h"

#include <stdarg.h>
#include <cmath>

#include <unicode/numfmt.h>
#include <unicode/decimfmt.h>
#include <unicode/unum.h>

static NSNumberFormatterBehavior _defaultFormatterBehavior = NSNumberFormatterBehavior10_4;

#if 0
id kCFNumberNaN;
id kCFNumberPositiveInfinity;
id kCFNumberNegativeInfinity;
#endif

const CFNumberRef kCFNumberNaN = nullptr; // = (CFNumberRef)&_kCFNumberNaN;
const CFNumberRef kCFNumberNegativeInfinity = nullptr; // = (CFNumberRef)&_kCFNumberNegInf;
const CFNumberRef kCFNumberPositiveInfinity = nullptr; // = (CFNumberRef)&_kCFNumberPosInf;

enum {
    _C_ID = '@',
    _C_CHR = 'c',
    _C_UCHR = 'C',
    _C_INT = 'i',
    _C_UINT = 'I',
    _C_FLT = 'f',
    _C_DBL = 'd',
    _C_VOID = 'v',
    _C_UNDEF = '?',
    _C_CLASS = '#',
    _C_SEL = ':',
    _C_CHARPTR = '*',
    _C_SHT = 's',
    _C_USHT = 'S',
    _C_LNG = 'l',
    _C_ULNG = 'L',
    _C_LNGLNG = 'q',
    _C_LNG_LNG = _C_LNGLNG,
    _C_ULNGLNG = 'Q',
    _C_ULNG_LNG = _C_ULNGLNG,
    _C_BFLD = 'b',
    _C_ARY_B = '[',
    _C_STRUCT_B = '{',
    _C_UNION_B = '(',
    _C_ARY_E = ']',
    _C_STRUCT_E = '}',
    _C_UNION_E = ')',
    _C_PTR = '^',
    _C_CONST = 'r',
    _C_IN = 'n',
    _C_INOUT = 'N',
    _C_OUT = 'o',
    _C_BYCOPY = 'R',
    _C_ONEWAY = 'V',
};

@implementation NSNumberFormatter {
    icu::DecimalFormat* _formatter;

    NSNumberFormatterBehavior _behavior;
    // 10.4
    NSNumberFormatterStyle _numberStyle;
    NSUInteger _formatWidth;
    id _locale;
    id _multiplier;

    BOOL _allowsFloats;
    BOOL _alwaysShowsDecimalSeparator;
    BOOL _isLenient;
    BOOL _isPartialStringValidationEnabled;
    BOOL _generatesDecimalNumbers;
    BOOL _usesGroupingSeparator;
    BOOL _usesSignificantDigits;

    NSUInteger _minimumIntegerDigits;
    NSUInteger _minimumFractionDigits;
    NSUInteger _minimumSignificantDigits;
    NSUInteger _maximumIntegerDigits;
    BOOL _customMaximumFractionDigits;
    NSUInteger _maximumFractionDigits;
    NSUInteger _maximumSignificantDigits;

    id _minimum;
    id _maximum;

    id _nilSymbol;
    id _notANumberSymbol;
    id _zeroSymbol;
    id _plusSign;
    id _minusSign;
    id _negativePrefix;
    id _negativeSuffix;
    id _positivePrefix;
    id _positiveSuffix;
    id _negativeInfinitySymbol;
    id _positiveInfinitySymbol;

    id _decimalSeparator;
    id _exponentSymbol;
    id _currencyCode;
    id _currencySymbol;
    id _internationalCurrencySymbol;
    id _currencyDecimalSeparator;
    id _currencyGroupingSeparator;
    id _groupingSeparator;
    NSUInteger _groupingSize;
    NSUInteger _secondaryGroupingSize;
    id _paddingCharacter;
    // NSNumberFormatterPadPosition _paddingPosition;
    id _percentSymbol;
    id _perMillSymbol;
    id _roundingIncrement;
    NSNumberFormatterRoundingMode _roundingMode;
    id _positiveFormat;
    id _negativeFormat;
    id _textAttributesForPositiveValues;
    id _textAttributesForNegativeValues;
    id _textAttributesForNegativeInfinity;
    id _textAttributesForNil;
    id _textAttributesForNotANumber;
    id _textAttributesForPositiveInfinity;
    id _textAttributesForZero;

    // 10.0
    id _attributedStringForNil;
    id _attributedStringForNotANumber;
    id _attributedStringForZero;
    id _roundingBehavior;
    id _thousandSeparator;

    BOOL _hasThousandSeparators;
    BOOL _localizesFormat;
}

/**
 @Status Interoperable
*/
+ (NSNumberFormatterBehavior)defaultFormatterBehavior {
    return _defaultFormatterBehavior;
}

- (id)init {
    [super init];
    _behavior = _defaultFormatterBehavior;
    _numberStyle = NSNumberFormatterNoStyle;

    _thousandSeparator = @",";
    _decimalSeparator = @".";
    _currencyDecimalSeparator = @"";
    /*
    _attributedStringForNil=[[NSAttributedString allocWithZone:nil] initWithString:@"(null)"];
    _attributedStringForNotANumber=[[NSAttributedString allocWithZone:nil] initWithString:@"NaN"];
    _attributedStringForZero=[[NSAttributedString allocWithZone:nil] initWithString:@"0.0"];
    */
    _allowsFloats = YES;

    UErrorCode status = U_ZERO_ERROR;
    _formatter = new icu::DecimalFormat(status);
    // assert(status == U_ZERO_ERROR);

    return self;
}

- (void)dealloc {
    [_attributedStringForNil release];
    [_attributedStringForNotANumber release];
    [_attributedStringForZero release];
    delete _formatter;
    [super dealloc];
}

/**
 @Status Caveat
 @Notes Not thoroughly implemented.
*/
- (void)setNumberStyle:(NSNumberFormatterStyle)value {
    _numberStyle = value;
}

/**
 @Status Interoperable
*/
- (void)setFormatWidth:(NSUInteger)value {
    _formatWidth = value;
}

/**
 @Status Interoperable
*/
- (void)setCurrencyCode:(id)currencyCode {
    id old = _currencyCode;
    _currencyCode = [currencyCode copy];

    [old release];
}

/**
 @Status Caveat
 @Notes Default value doesn't take locale into account.
*/
- (id)currencyCode {
    if (_currencyCode == nil) {
        _currencyCode = @"CAD";
    }
    return _currencyCode;
}

/**
 @Status Stub
*/
- (void)setNegativeFormat:(id)value {
    UNIMPLEMENTED();
    value = [value copy];
    [_negativeFormat release];
    _negativeFormat = value;
}

/**
 @Status Interoperable
*/
- (void)setNotANumberSymbol:(id)value {
    value = [value copy];
    [_notANumberSymbol release];
    _notANumberSymbol = value;
}

/**
 @Status Stub
*/
- (void)setPositiveFormat:(id)value {
    UNIMPLEMENTED();
    value = [value copy];
    [_positiveFormat release];
    _positiveFormat = value;
}

/**
 @Status Interoperable
*/
- (void)setDecimalSeparator:(id)value {
    value = [value copy];
    [_decimalSeparator release];
    _decimalSeparator = value;
}

/**
 @Status Stub
*/
- (void)setUsesSignificantDigits:(BOOL)uses {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setMinimumSignificantDigits:(NSUInteger)min {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setMaximumSignificantDigits:(NSUInteger)min {
    UNIMPLEMENTED();
}

/**
 @Status Caveat
 @Notes Default value doesn't take locale into account.
*/
- (id)decimalSeparator {
    return _decimalSeparator;
}

/**
 @Status Interoperable
*/
- (BOOL)alwaysShowsDecimalSeparator {
    return _alwaysShowsDecimalSeparator;
}

/**
 @Status Stub
*/
- (void)setAlwaysShowsDecimalSeparator:(BOOL)value {
    UNIMPLEMENTED();
    _alwaysShowsDecimalSeparator = value;
}

/**
 @Status Interoperable
*/
- (void)setGroupingSeparator:(id)value {
    value = [value copy];
    [_groupingSeparator release];
    _groupingSeparator = value;

    const DecimalFormatSymbols* orig = _formatter->getDecimalFormatSymbols();
    DecimalFormatSymbols update(*orig);
    update.setSymbol(DecimalFormatSymbols::kGroupingSeparatorSymbol, [value UTF8String]);
    _formatter->setDecimalFormatSymbols(update);
}

/**
 @Status Stub
*/
- (void)setPerMillSymbol:(id)value {
    UNIMPLEMENTED();
    value = [value copy];
    [_perMillSymbol release];
    _perMillSymbol = value;
}

/**
 @Status Caveat
 @Notes Does not respect division when NSNumber derived from string?
*/
- (id)multiplier {
    if (_multiplier == nil && _numberStyle == NSNumberFormatterPercentStyle) {
        return [NSNumber numberWithInt:100];
    }

    return _multiplier;
}

/**
 @Status Interoperable
*/
- (unsigned)maximumFractionDigits {
    if (_customMaximumFractionDigits)
        return _maximumFractionDigits;

    if (_numberStyle == NSNumberFormatterDecimalStyle)
        return 3;

    return 0;
}

/**
 @Status Interoperable
*/
- (id)positivePrefix {
    if (_positivePrefix == nil)
        return @"";

    return _positivePrefix;
}

/**
 @Status Interoperable
*/
- (id)negativePrefix {
    if (_negativePrefix == nil)
        return @"-";

    return _negativePrefix;
}

/**
 @Status Stub
*/
- (id)currencyDecimalSeparator {
    UNIMPLEMENTED();
    return _currencyDecimalSeparator;
}

/**
 @Status Interoperable
*/
- (id)positiveSuffix {
    // Suffixes return the percent symbol if specified

    if (_positiveSuffix == nil) {
        if (_numberStyle == NSNumberFormatterPercentStyle)
            return [self percentSymbol];

        return @"";
    }

    return _positiveSuffix;
}

/**
 @Status Interoperable
*/
- (id)negativeSuffix {
    // Suffixes return the percent symbol if specified

    if (_negativeSuffix == nil) {
        if (_numberStyle == NSNumberFormatterPercentStyle)
            return [self percentSymbol];

        return @"";
    }

    return _negativeSuffix;
}

/**
 @Status Interoperable
*/
- (id)percentSymbol {
    if (_percentSymbol == nil)
        return @"%";

    return _percentSymbol;
}

/**
 @Status Interoperable
*/
- (id)positiveFormat {
    return _positiveFormat;
}

/**
 @Status Interoperable
*/
- (id)negativeFormat {
    return _negativeFormat;
}

/**
 @Status Stub
*/
- (void)setMinimumFractionDigits:(NSUInteger)value {
    UNIMPLEMENTED();
    _minimumFractionDigits = value;
}

/**
 @Status Stub
*/
- (void)setUsesGroupingSeparator:(BOOL)value {
    UNIMPLEMENTED();
    _formatter->setGroupingUsed(value);
    _usesGroupingSeparator = value;
}

/**
 @Status Interoperable
*/
- (void)setMaximumFractionDigits:(NSUInteger)value {
    _formatter->setMaximumFractionDigits(value);
    _customMaximumFractionDigits = YES;
    _maximumFractionDigits = value;
}

/**
 @Status Caveat
 @Notes NSNumberFormatterBehavior10_0 likely crashes.
*/
- (void)setFormatterBehavior:(NSNumberFormatterBehavior)value {
    _behavior = (NSNumberFormatterBehavior)value;
}

/**
 @Status Interoperable
*/
- (id)groupingSeparator {
    if (_groupingSeparator == nil) {
        id check = [_locale objectForKey:NSLocaleGroupingSeparator];

        if (check != nil)
            return check;

        return @",";
    }

    return _groupingSeparator;
}

/**
 @Status Interoperable
*/
- (unsigned)groupingSize {
    return _groupingSize;
}

/**
 @Status Interoperable
*/
- (id)currencySymbol {
    return _currencySymbol;
}

/**
 @Status Caveat
 @Notes Just returns nil.
*/
- (id)nilSymbol {
    return _nilSymbol;
}

/**
 @Status Interoperable
*/
- (void)setGroupingSize:(NSUInteger)value {
    _formatter->setGroupingSize(value);
    _groupingSize = value;
}

/**
 @Status Interoperable
*/
- (void)setCurrencySymbol:(id)value {
    value = [value copy];
    [_currencySymbol release];
    _currencySymbol = value;
}

/**
 @Status Interoperable
*/
- (void)setPaddingCharacter:(id)value {
    value = [value copy];
    [_paddingCharacter release];
    _paddingCharacter = value;
    _formatter->setPadCharacter([value UTF8String]);
}

/**
 @Status Stub
*/
- (void)setRoundingMode:(NSNumberFormatterRoundingMode)value {
    UNIMPLEMENTED();
    _roundingMode = (NSNumberFormatterRoundingMode)value;
}

/**
 @Status Interoperable
*/
- (void)setMinimumIntegerDigits:(NSUInteger)value {
    _formatter->setMinimumIntegerDigits(value);
    _minimumIntegerDigits = value;
}

- (id)stringFromNumberNoStyle:(id)number {
    number = multipliedNumber(number, [self multiplier]);

    id prefix;
    id suffix;
    id format;

    if (numberIsNegative(number)) {
        /*
        prefix = [self negativePrefix];
        suffix = [self negativeSuffix];
        format = [self negativeFormat];
        */
        prefix = @"";
        suffix = @"";
        format = @"";
    } else {
        prefix = [self positivePrefix];
        suffix = [self positiveSuffix];
        format = [self positiveFormat];
    }

    id result;

    result = prefix;
    result = [result stringByAppendingString:[self _stringFromNumber:number]];
    result = [result stringByAppendingString:suffix];

    return result;
}

- (id)stringFromNumber10_4:(id)number {
    switch (_numberStyle) {
        case NSNumberFormatterNoStyle:
            return [self stringFromNumberNoStyle:number];

        case NSNumberFormatterDecimalStyle:
            return [self stringFromNumberNoStyle:number];

        case NSNumberFormatterCurrencyStyle:
            return [self stringFromNumberNoStyle:number];
            break;

        case NSNumberFormatterPercentStyle:
            return [self stringFromNumberNoStyle:number];

        case NSNumberFormatterScientificStyle:
            assert(0);
            break;

        case NSNumberFormatterSpellOutStyle:
            assert(0);
            break;
    }

    return [number description];
}

/**
 @Status Caveat
 @Notes NSNumberFormatterBehavior10_0 likely crashes.
*/
- (id)stringFromNumber:(id)number {
    NSNumberFormatterBehavior check = _behavior;

    if (check == NSNumberFormatterBehaviorDefault)
        check = NSNumberFormatterBehavior10_4;

    if (check == NSNumberFormatterBehavior10_0)
        return [self stringFromNumber10_0:number];
    else
        return [self stringFromNumber10_4:number];
}

/**
 @Status Caveat
 @Notes Not thoroughly implemented.
*/
- (void)setLocale:(id)value {
    value = [value copy];
    [_locale release];
    _locale = value;
}

- (id)_stringFromNumber:(id)number {
    static const WORD kUnicodeInfinity = 0x221E;

    if (number == nil)
        return [self nilSymbol];
    else if (number == kCFNumberNaN)
        return [self notANumberSymbol];
    else if (number == kCFNumberPositiveInfinity) {
        id check = [self positiveInfinitySymbol];
        if (check == nil)
            check = [NSString stringWithCharacters:&kUnicodeInfinity length:1];
        return check;
    } else if (number == kCFNumberNegativeInfinity) {
        id check = [self negativeInfinitySymbol];
        if (check == nil) {
            const WORD codes[2] = { '-', kUnicodeInfinity };
            check = [NSString stringWithCharacters:codes length:2];
        }
        return check;
    }

    const char* objcType = (const char*)[number objCType];

    if (!objcType || strlen(objcType) != 1) {
        if (objcType == NULL) {
            return @"(null)";
        }
        objcType = "?";
    }

    UnicodeString formatted;
    UErrorCode status = U_ZERO_ERROR;

    switch (*objcType) {
        case _C_CHR:
        case _C_SHT:
        case _C_INT:
        case _C_LNG: {
            int val = [number intValue];
            _formatter->format(val, formatted, status);
            break;
        }

        case _C_UCHR:
        case _C_USHT:
        case _C_UINT:
        case _C_ULNG: {
            // note: int64 can hold all 32-bit unsigned integers so use it (icu doesn't support
            // formatting unsigned numbers).
            int64_t val = [number unsignedIntValue];
            _formatter->format(val, formatted, status);
            break;
        }

        case _C_LNGLNG: {
            int64_t val;
            [number _copyInt64Value:&val];
            _formatter->format(val, formatted, status);
            break;
        }

        // This isn't really any good because icu cannot format 128-bit integers, nor can it format unsigned numbers. We
        // could send it as a double
        // but that would likely be a bad idea.
        case _C_ULNGLNG: {
            int64_t val;
            [number _copyInt64Value:&val];
            _formatter->format(val, formatted, status);
            break;
        }

        case _C_FLT: {
            float val = [number floatValue];
            _formatter->format(val, formatted, status);
            break;
        }

        case _C_DBL: {
            double val = [number doubleValue];
            _formatter->format(val, formatted, status);
            break;
        }

        default:
            assert(0);
            // string = [number description];
            break;
    }

    assert(U_SUCCESS(status));

    return NSStringFromICU(formatted);
}

static id multipliedNumber(id number, id multiplier) {
    if (multiplier == nil)
        return number;

    return [NSNumber numberWithDouble:[number doubleValue] * [multiplier doubleValue]];
}

static BOOL numberIsNegative(id number) {
    if (number == nil)
        return NO;

    return [number doubleValue] < 0.0 ? YES : NO;
}

/**
 @Status Caveat
 @Notes Doesn't take all format styles into account.
*/
- (NSNumber*)numberFromString:(id)string {
    if (string == nil)
        return nil;

    // Do special currency formatting for numbers:
    if (_numberStyle == NSNumberFormatterCurrencyStyle) {
        UErrorCode status = U_ZERO_ERROR;
        UNumberFormat* nf = unum_open(UNUM_CURRENCY, NULL, -1, NULL, NULL, &status);
        int offset = 0;
        UChar currency[4];
        double amt = unum_parseDoubleCurrency(nf, (const wchar_t*)[string rawCharacters], [string length], &offset, currency, &status);
        unum_close(nf);
        return [NSNumber numberWithDouble:amt];
    }

    const char* pString = [string UTF8String];
    bool isInt = true;

    if (strstr(pString, ".") != NULL) {
        isInt = false;
    }

    if (isInt) {
        __int64 val;
        char* pEnd;
        val = _strtoi64(pString, &pEnd, 10);
        if (pEnd == pString) {
            return nil;
        }
        if (val == static_cast<__int64>(static_cast<int>(val))) {
            return [NSNumber numberWithInt:(static_cast<int>(val))];
        } else {
            return [NSNumber numberWithLongLong:val];
        }
    } else {
        double val;
        char* pEnd;
        val = strtod(pString, &pEnd);
        if (pEnd == pString) {
            return nil;
        }
        if (val == static_cast<double>(static_cast<float>(val))) {
            return [NSNumber numberWithFloat:static_cast<float>(val)];
        } else {
            return [NSNumber numberWithDouble:val];
        }
    }
}

- (id)stringForObjectValue:(id)obj {
    return [self stringFromNumber:obj];
}

- (BOOL)getObjectValue:(id*)objOut forString:(id)str errorDescription:(NSString**)error {
    const char* pVal = [str UTF8String];

    int val = atoi(pVal);

    *objOut = [NSNumber numberWithInteger:val];

    return TRUE;
}

/**
 @Status Caveat
 @Notes Scientific and SpellOut styles assert, the rest default to NoStyle.
*/
+ (id)localizedStringFromNumber:(id)number numberStyle:(NSNumberFormatterStyle)style {
    id formatter = [self new];
    [formatter setNumberStyle:style];

    id ret = [formatter stringFromNumber:number];
    [formatter release];

    return ret;
}
@end
