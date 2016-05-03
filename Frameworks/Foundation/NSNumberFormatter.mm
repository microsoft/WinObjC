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

#import "Starboard.h"
#import "StubReturn.h"
#import "Foundation/NSNumberFormatter.h"
#import "Foundation/NSMutableString.h"
#import "Foundation/NSNumber.h"
#import "Foundation/NSAttributedString.h"
#import "Etc.h"
#import <stdarg.h>
#import <cmath>
#import <unicode/numfmt.h>
#import <unicode/decimfmt.h>
#import <unicode/unum.h>

static NSNumberFormatterBehavior _defaultFormatterBehavior = NSNumberFormatterBehavior10_4;

const CFNumberRef kCFNumberNaN = nullptr; // = (CFNumberRef)&_kCFNumberNaN;
const CFNumberRef kCFNumberNegativeInfinity = nullptr; // = (CFNumberRef)&_kCFNumberNegInf;
const CFNumberRef kCFNumberPositiveInfinity = nullptr; // = (CFNumberRef)&_kCFNumberPosInf;

@implementation NSNumberFormatter {
    icu::DecimalFormat* _formatter;

    // 10.4
    NSNumberFormatterStyle _numberStyle;

    id _locale;
    id _multiplier;

    BOOL _alwaysShowsDecimalSeparator;
    BOOL _isLenient;
    BOOL _isPartialStringValidationEnabled;
    BOOL _usesGroupingSeparator;

    NSUInteger _minimumIntegerDigits;
    BOOL _customMaximumFractionDigits;
    NSUInteger _maximumFractionDigits;

    id _nilSymbol;
    id _notANumberSymbol;
    id _negativePrefix;
    id _negativeSuffix;
    id _positivePrefix;
    id _positiveSuffix;

    id _decimalSeparator;
    id _currencyCode;
    id _currencySymbol;
    id _groupingSeparator;
    NSUInteger _groupingSize;
    id _paddingCharacter;
    id _percentSymbol;

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

/**
 @Status Interoperable
*/
- (instancetype)init {
    if (self = [super init]) {
        _formatterBehavior = _defaultFormatterBehavior;
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
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    [_attributedStringForNil release];
    [_attributedStringForNotANumber release];
    [_attributedStringForZero release];
    delete _formatter;
    [super dealloc];
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
        _currencyCode = @"USD";
    }
    return _currencyCode;
}

/**
 @Status Interoperable
*/
- (void)setNotANumberSymbol:(id)value {
    @synchronized(self) {
        if (_notANumberSymbol != value) {
            [_notANumberSymbol autorelease];
            _notANumberSymbol = [value copy];
        }
    }
}

/**
 @Status Interoperable
*/
- (NSString*)notANumberSymbol {
    @synchronized(self) {
        if (_notANumberSymbol == nil) {
            return @"NaN";
        }

        return [[_notANumberSymbol retain] autorelease];
    }
}

/**
 @Status Interoperable
*/
- (void)setDecimalSeparator:(NSString*)value {
    value = [value copy];
    [_decimalSeparator release];
    _decimalSeparator = value;
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
 @Status Interoperable
*/
- (void)setMultiplier:(NSNumber*)number {
    @synchronized(self) {
        if (_multiplier != number) {
            [_multiplier autorelease];
            _multiplier = [number copy];
        }
    }
}

/**
 @Status Caveat
 @Notes Does not respect division when NSNumber derived from string?
*/
- (NSNumber*)multiplier {
    @synchronized(self) {
        if (_multiplier == nil && self.numberStyle == NSNumberFormatterPercentStyle) {
            return [NSNumber numberWithInt:100];
        }

        return [[_multiplier retain] autorelease];
    }
}

/**
 @Status Interoperable
*/
- (unsigned)maximumFractionDigits {
    if (_customMaximumFractionDigits)
        return _maximumFractionDigits;

    if (self.numberStyle == NSNumberFormatterDecimalStyle)
        return 3;

    return 0;
}

/**
 @Status Interoperable
*/
- (void)setPositivePrefix:(NSString*)prefix {
    @synchronized(self) {
        if (_positivePrefix != prefix) {
            [_positivePrefix autorelease];
            _positivePrefix = [prefix copy];
        }
    }
}

/**
 @Status Interoperable
*/
- (NSString*)positivePrefix {
    @synchronized(self) {
        if (_positivePrefix == nil) {
            return @"";
        }

        return [[_positivePrefix retain] autorelease];
    }
}

/**
 @Status Interoperable
*/
- (void)setNegativePrefix:(NSString*)prefix {
    @synchronized(self) {
        if (_negativePrefix != prefix) {
            [_negativePrefix autorelease];
            _negativePrefix = [prefix copy];
        }
    }
}

/**
 @Status Interoperable
*/
- (NSString*)negativePrefix {
    @synchronized(self) {
        if (_negativePrefix == nil) {
            return @"-";
        }

        return [[_negativePrefix retain] autorelease];
    }
}

/**
 @Status Interoperable
*/
- (void)setPositiveSuffix:(NSString*)suffix {
    @synchronized(self) {
        if (_positiveSuffix != suffix) {
            [_positiveSuffix autorelease];
            _positiveSuffix = [suffix copy];
        }
    }
}

/**
 @Status Interoperable
*/
- (NSString*)positiveSuffix {
    // Suffixes return the percent symbol if specified
    @synchronized(self) {
        if (_positiveSuffix == nil) {
            if (self.numberStyle == NSNumberFormatterPercentStyle) {
                return self.percentSymbol;
            }

            return @"";
        }

        return [[_positiveSuffix retain] autorelease];
    }
}

/**
 @Status Interoperable
*/
- (void)setNegativeSuffix:(NSString*)suffix {
    @synchronized(self) {
        if (_negativeSuffix != suffix) {
            [_negativeSuffix autorelease];
            _negativeSuffix = [suffix copy];
        }
    }
}

/**
 @Status Interoperable
*/
- (NSString*)negativeSuffix {
    // Suffixes return the percent symbol if specified
    @synchronized(self) {
        if (_negativeSuffix == nil) {
            if (self.numberStyle == NSNumberFormatterPercentStyle) {
                return self.percentSymbol;
            }

            return @"";
        }

        return [[_negativeSuffix retain] autorelease];
    }
}

/**
 @Status Interoperable
*/
- (void)setPercentSymbol:(NSString*)symbol {
    @synchronized(self) {
        if (_percentSymbol != symbol) {
            [_percentSymbol autorelease];
            _percentSymbol = [symbol copy];
        }
    }
}

/**
 @Status Interoperable
*/
- (NSString*)percentSymbol {
    @synchronized(self) {
        if (_percentSymbol == nil) {
            return @"%";
        }

        return [[_percentSymbol retain] autorelease];
    }
}

/**
 @Status Interoperable
*/
- (void)setUsesGroupingSeparator:(BOOL)value {
    @synchronized(self) {
        _formatter->setGroupingUsed(value);
        _usesGroupingSeparator = value;
    }
}

/**
 @Status Interoperable
*/
- (BOOL)usesGroupingSeparator {
    @synchronized(self) {
        return _usesGroupingSeparator;
    }
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
 @Status Interoperable
*/
- (id)groupingSeparator {
    if (_groupingSeparator == nil) {
        id check = [self.locale objectForKey:NSLocaleGroupingSeparator];

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
 @Status Interoperable
*/
- (void)setNilSymbol:(NSString*)symbol {
    @synchronized(self) {
        if (_nilSymbol != symbol) {
            [_nilSymbol autorelease];
            _nilSymbol = [symbol copy];
        }
    }
}

/**
 @Status Interoperable
*/
- (NSString*)nilSymbol {
    @synchronized(self) {
        if (_nilSymbol == nil) {
            return @"";
        }

        return [[_nilSymbol retain] autorelease];
    }
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
- (void)setPaddingCharacter:(NSString*)value {
    @synchronized(self) {
        if (_paddingCharacter != value) {
            _formatter->setPadCharacter([value UTF8String]);
            [_paddingCharacter autorelease];
            _paddingCharacter = [value copy];
        }
    }
}

/**
 @Status Interoperable
*/
- (NSString*)paddingCharacter {
    @synchronized(self) {
        if (_paddingCharacter == nil) {
            return @"*";
        }

        return [[_paddingCharacter retain] autorelease];
    }
}

/**
 @Status Interoperable
*/
- (void)setMinimumIntegerDigits:(NSUInteger)value {
    @synchronized(self) {
        _formatter->setMinimumIntegerDigits(value);
        _minimumIntegerDigits = value;
    }
}

/**
 @Status Interoperable
*/
- (NSUInteger)minimumIntegerDigits {
    @synchronized(self) {
        return _minimumIntegerDigits;
    }
}

/**
 @Status Interoperable
*/
- (id)stringFromNumberNoStyle:(id)number {
    number = multipliedNumber(number, [self multiplier]);

    id prefix;
    id suffix;

    if (numberIsNegative(number)) {
        /*
        prefix = [self negativePrefix];
        suffix = [self negativeSuffix];
        */
        prefix = @"";
        suffix = @"";
    } else {
        prefix = [self positivePrefix];
        suffix = [self positiveSuffix];
    }

    id result;

    result = prefix;
    result = [result stringByAppendingString:[self _stringFromNumber:number]];
    result = [result stringByAppendingString:suffix];

    return result;
}

/**
 @Status Interoperable
*/
- (id)stringFromNumber10_4:(id)number {
    switch (self.numberStyle) {
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
    NSNumberFormatterBehavior check = self.formatterBehavior;

    if (check == NSNumberFormatterBehaviorDefault)
        check = NSNumberFormatterBehavior10_4;

    // VSO 7016320: Method stringFromNumber10_0 does not exist on NSString.
    if (check == NSNumberFormatterBehavior10_0) {
        return [self stringFromNumber10_0:number];
    } else {
        return [self stringFromNumber10_4:number];
    }
}

/**
 @Status Caveat
 @Notes Not thoroughly implemented.
*/
- (void)setLocale:(NSLocale*)value {
    @synchronized(self) {
        if (_locale != value) {
            [_locale autorelease];
            _locale = [value copy];
        }
    }
}

/**
 @Status Caveat
*/
- (NSLocale*)locale {
    @synchronized(self) {
        if (_locale == nil) {
            UNIMPLEMENTED();
            return StubReturn();
        }

        return [[_locale retain] autorelease];
    }
}

- (id)_stringFromNumber:(id)number {
    static const WORD kUnicodeInfinity = 0x221E;
    CFNumberRef num = static_cast<CFNumberRef>(number);

    if (num == nil)
        return [self nilSymbol];
    else if (num == kCFNumberNaN)
        return [self notANumberSymbol];
    else if (num == kCFNumberPositiveInfinity) {
        id check = [self positiveInfinitySymbol];
        if (check == nil)
            check = [NSString stringWithCharacters:&kUnicodeInfinity length:1];
        return check;
    } else if (num == kCFNumberNegativeInfinity) {
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

        case _C_LNG_LNG: {
            int64_t val = [number longLongValue];
            _formatter->format(val, formatted, status);
            break;
        }

        // This isn't really any good because icu cannot format 128-bit integers, nor can it format unsigned numbers. We
        // could send it as a double
        // but that would likely be a bad idea.
        case _C_ULNG_LNG: {
            int64_t val = [number unsignedLongLongValue];
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

static id multipliedNumber(id number, id multiplierNumber) {
    if (multiplierNumber == nil)
        return number;

    return [NSNumber numberWithDouble:[number doubleValue] * [multiplierNumber doubleValue]];
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
    if (self.numberStyle == NSNumberFormatterCurrencyStyle) {
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

/**
 @Status Interoperable
*/
- (id)stringForObjectValue:(id)obj {
    return [self stringFromNumber:obj];
}

/**
 @Status Interoperable
*/
- (BOOL)getObjectValue:(out id _Nullable*)objOut forString:(id)str errorDescription:(out NSString* _Nullable*)error {
    if (objOut) {
        const char* pVal = [str UTF8String];
        int val = atoi(pVal);
        *objOut = [NSNumber numberWithInteger:val];
    }

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

/**
 @Status Stub
 @Notes
*/
+ (void)setDefaultFormatterBehavior:(NSNumberFormatterBehavior)behavior {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)getObjectValue:(id _Nullable*)anObject forString:(NSString*)aString range:(NSRange*)rangep error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
