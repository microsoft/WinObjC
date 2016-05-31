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

#include <array>

static NSNumberFormatterBehavior _defaultFormatterBehavior = NSNumberFormatterBehavior10_4;

const CFNumberRef kCFNumberNaN = nullptr; // = (CFNumberRef)&_kCFNumberNaN;
const CFNumberRef kCFNumberNegativeInfinity = nullptr; // = (CFNumberRef)&_kCFNumberNegInf;
const CFNumberRef kCFNumberPositiveInfinity = nullptr; // = (CFNumberRef)&_kCFNumberPosInf;

CFStringRef kCFNumberFormatterUsesCharacterDirectionKey = static_cast<CFStringRef>(@"kCFNumberFormatterUsesCharacterDirectionKey");

@implementation NSNumberFormatter {
    woc::unique_cf<CFNumberFormatterRef> _cfNumberFormatter;
    BOOL _wasMaxFractionDigitsSet;
    BOOL _wasMaxIntegerDigitsSet;
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
        _wasMaxFractionDigitsSet = NO;
        _wasMaxIntegerDigitsSet = NO;
        _cfNumberFormatter.reset(
            CFNumberFormatterCreate(nullptr, static_cast<CFLocaleRef>([NSLocale currentLocale]), kCFNumberFormatterNoStyle));
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)setCurrencyCode:(NSString*)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(), kCFNumberFormatterCurrencyCode, reinterpret_cast<CFTypeRef>(value));
}

/**
 @Status Interoperable
*/
- (NSString*)currencyCode {
    return [(NSString*)CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterCurrencyCode) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setNotANumberSymbol:(NSString*)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(), kCFNumberFormatterNaNSymbol, reinterpret_cast<CFTypeRef>(value));
}

/**
 @Status Interoperable
*/
- (NSString*)notANumberSymbol {
    return [(NSString*)CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterNaNSymbol) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setDecimalSeparator:(NSString*)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(), kCFNumberFormatterDecimalSeparator, reinterpret_cast<CFTypeRef>(value));
}

/**
 @Status Interoperable
*/
- (NSString*)decimalSeparator {
    return [(NSString*)CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterDecimalSeparator) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setAlwaysShowsDecimalSeparator:(BOOL)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(),
                                 kCFNumberFormatterAlwaysShowDecimalSeparator,
                                 value ? kCFBooleanTrue : kCFBooleanFalse);
}

/**
 @Status Interoperable
*/
- (BOOL)alwaysShowsDecimalSeparator {
    return CFBooleanGetValue(
        static_cast<CFBooleanRef>(CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterAlwaysShowDecimalSeparator)));
}

/**
 @Status Interoperable
*/
- (void)setGroupingSeparator:(NSString*)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(), kCFNumberFormatterGroupingSeparator, reinterpret_cast<CFTypeRef>(value));
}

/**
 @Status Interoperable
*/
- (NSString*)groupingSeparator {
    return [(NSString*)CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterCurrencyGroupingSeparator) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setMultiplier:(NSNumber*)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(), kCFNumberFormatterMultiplier, reinterpret_cast<CFTypeRef>(value));
}

/**
 @Status Interoperable
*/
- (NSNumber*)multiplier {
    return [(NSNumber*)CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterMultiplier) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setMaximumFractionDigits:(NSUInteger)value {
    _wasMaxFractionDigitsSet = YES;
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(),
                                 kCFNumberFormatterMaxFractionDigits,
                                 reinterpret_cast<CFTypeRef>([NSNumber numberWithUnsignedInteger:value]));
}

/**
 @Status Interoperable
*/
- (NSUInteger)maximumFractionDigits {
    return ((NSNumber*)(CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterMaxFractionDigits))).unsignedIntegerValue;
}

/**
 @Status Interoperable
*/
- (void)setPositivePrefix:(NSString*)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(), kCFNumberFormatterPositivePrefix, reinterpret_cast<CFTypeRef>(value));
}

/**
 @Status Interoperable
*/
- (NSString*)positivePrefix {
    return [(NSString*)CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterPositivePrefix) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setNegativePrefix:(NSString*)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(), kCFNumberFormatterNegativePrefix, reinterpret_cast<CFTypeRef>(value));
}

/**
 @Status Interoperable
*/
- (NSString*)negativePrefix {
    return [(NSString*)CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterNegativePrefix) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setPositiveSuffix:(NSString*)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(), kCFNumberFormatterPositiveSuffix, reinterpret_cast<CFTypeRef>(value));
}

/**
 @Status Interoperable
*/
- (NSString*)positiveSuffix {
    return [(NSString*)CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterPositiveSuffix) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setNegativeSuffix:(NSString*)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(), kCFNumberFormatterNegativeSuffix, reinterpret_cast<CFTypeRef>(value));
}

/**
 @Status Interoperable
*/
- (NSString*)negativeSuffix {
    return [(NSString*)CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterNegativeSuffix) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setPercentSymbol:(NSString*)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(), kCFNumberFormatterPercentSymbol, reinterpret_cast<CFTypeRef>(value));
}

/**
 @Status Interoperable
*/
- (NSString*)percentSymbol {
    return [(NSString*)CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterPercentSymbol) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setUsesGroupingSeparator:(BOOL)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(),
                                 kCFNumberFormatterUseGroupingSeparator,
                                 (value == YES) ? kCFBooleanTrue : kCFBooleanFalse);
}

/**
 @Status Interoperable
*/
- (BOOL)usesGroupingSeparator {
    return CFBooleanGetValue(
        static_cast<CFBooleanRef>(CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterUseGroupingSeparator)));
}

/**
 @Status Interoperable
*/
- (void)setGroupingSize:(NSUInteger)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(),
                                 kCFNumberFormatterGroupingSize,
                                 reinterpret_cast<CFTypeRef>([NSNumber numberWithUnsignedInteger:value]));
}

/**
 @Status Interoperable
*/
- (NSUInteger)groupingSize {
    return ((NSNumber*)(CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterGroupingSize))).unsignedIntegerValue;
}

/**
 @Status Interoperable
*/
- (void)setCurrencySymbol:(NSString*)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(), kCFNumberFormatterGroupingSize, reinterpret_cast<CFTypeRef>(value));
}

/**
 @Status Interoperable
*/
- (NSString*)currencySymbol {
    return [(NSString*)CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterCurrencySymbol) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setNilSymbol:(NSString*)symbol {
    @synchronized(self) {
        if (self.nilSymbol != symbol) {
            [self.nilSymbol autorelease];
            self.nilSymbol = [symbol copy];
        }
    }
}

/**
 @Status Interoperable
*/
- (NSString*)nilSymbol {
    @synchronized(self) {
        if (self.nilSymbol == nil) {
            return @"";
        }

        return self.nilSymbol;
    }
}

/**
 @Status Interoperable
*/
- (void)setMinimumIntegerDigits:(NSUInteger)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(),
                                 kCFNumberFormatterMinIntegerDigits,
                                 reinterpret_cast<CFTypeRef>([NSNumber numberWithUnsignedInteger:value]));
}

/**
 @Status Interoperable
*/
- (NSUInteger)minimumIntegerDigits {
    return ((NSNumber*)(CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterMinIntegerDigits))).unsignedIntegerValue;
}

/**
 @Status Interoperable
*/
- (void)setCurrencyDecimalSeparator:(NSString*)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(), kCFNumberFormatterCurrencyDecimalSeparator, reinterpret_cast<CFTypeRef>(value));
}

/**
 @Status Interoperable
*/
- (NSString*)currencyDecimalSeparator {
    return [(NSString*)CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterCurrencyDecimalSeparator) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setExponentSymbol:(NSString*)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(), kCFNumberFormatterExponentSymbol, reinterpret_cast<CFTypeRef>(value));
}

/**
 @Status Interoperable
*/
- (NSString*)exponentSymbol {
    return [(NSString*)CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterExponentSymbol) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setFormatWidth:(NSUInteger)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(),
                                 kCFNumberFormatterFormatWidth,
                                 reinterpret_cast<CFTypeRef>([NSNumber numberWithUnsignedInteger:value]));
}

/**
 @Status Interoperable
*/
- (NSUInteger)formatWidth {
    return ((NSNumber*)(CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterFormatWidth))).unsignedIntegerValue;
}

/**
 @Status Interoperable
*/
- (void)setInternationalCurrencySymbol:(NSString*)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(),
                                 kCFNumberFormatterInternationalCurrencySymbol,
                                 reinterpret_cast<CFTypeRef>(value));
}

/**
 @Status Interoperable
*/
- (NSString*)internationalCurrencySymbol {
    return [(NSString*)CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterInternationalCurrencySymbol) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setMinusSign:(NSString*)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(), kCFNumberFormatterMinusSign, reinterpret_cast<CFTypeRef>(value));
}

/**
 @Status Interoperable
*/
- (NSString*)minusSign {
    return [(NSString*)CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterMinusSign) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setPaddingCharacter:(NSString*)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(), kCFNumberFormatterPaddingCharacter, reinterpret_cast<CFTypeRef>(value));
}

/**
 @Status Interoperable
*/
- (NSString*)paddingCharacter {
    return [(NSString*)CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterPaddingCharacter) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setPerMillSymbol:(NSString*)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(), kCFNumberFormatterPerMillSymbol, reinterpret_cast<CFTypeRef>(value));
}

/**
 @Status Interoperable
*/
- (NSString*)perMillSymbol {
    return [(NSString*)CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterPerMillSymbol) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setPlusSign:(NSString*)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(), kCFNumberFormatterPlusSign, reinterpret_cast<CFTypeRef>(value));
}

/**
 @Status Interoperable
*/
- (NSString*)plusSign {
    return [(NSString*)CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterPlusSign) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setZeroSymbol:(NSString*)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(), kCFNumberFormatterZeroSymbol, reinterpret_cast<CFTypeRef>(value));
}

/**
 @Status Interoperable
*/
- (NSString*)zeroSymbol {
    return [(NSString*)CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterZeroSymbol) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setRoundingIncrement:(NSNumber*)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(), kCFNumberFormatterRoundingIncrement, reinterpret_cast<CFTypeRef>(value));
}

/**
 @Status Interoperable
*/
- (NSNumber*)roundingIncrement {
    return [(NSNumber*)CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterRoundingIncrement) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setMaximumIntegerDigits:(NSUInteger)value {
    _wasMaxIntegerDigitsSet = YES;
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(),
                                 kCFNumberFormatterMaxIntegerDigits,
                                 reinterpret_cast<CFTypeRef>([NSNumber numberWithUnsignedInteger:value]));
}

/**
 @Status Interoperable
*/
- (NSUInteger)maximumIntegerDigits {
    return ((NSNumber*)(CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterMaxIntegerDigits))).unsignedIntegerValue;
}

/**
 @Status Interoperable
*/
- (void)setMaximumSignificantDigits:(NSUInteger)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(),
                                 kCFNumberFormatterMaxSignificantDigits,
                                 reinterpret_cast<CFTypeRef>([NSNumber numberWithUnsignedInteger:value]));
}

/**
 @Status Interoperable
*/
- (NSUInteger)maximumSignificantDigits {
    return ((NSNumber*)(CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterMaxSignificantDigits)))
        .unsignedIntegerValue;
}

/**
 @Status Interoperable
*/
- (void)setMinimumFractionDigits:(NSUInteger)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(),
                                 kCFNumberFormatterMinFractionDigits,
                                 reinterpret_cast<CFTypeRef>([NSNumber numberWithUnsignedInteger:value]));
}

/**
 @Status Interoperable
*/
- (NSUInteger)minimumFractionDigits {
    return ((NSNumber*)(CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterMinFractionDigits))).unsignedIntegerValue;
}

/**
 @Status Interoperable
*/
- (void)setMinimumSignificantDigits:(NSUInteger)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(),
                                 kCFNumberFormatterMinSignificantDigits,
                                 reinterpret_cast<CFTypeRef>([NSNumber numberWithUnsignedInteger:value]));
}

/**
 @Status Interoperable
*/
- (NSUInteger)minimumSignificantDigits {
    return ((NSNumber*)(CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterMinSignificantDigits)))
        .unsignedIntegerValue;
}

/**
 @Status Interoperable
*/
- (void)setSecondaryGroupingSize:(NSUInteger)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(),
                                 kCFNumberFormatterSecondaryGroupingSize,
                                 reinterpret_cast<CFTypeRef>([NSNumber numberWithUnsignedInteger:value]));
}

/**
 @Status Interoperable
*/
- (NSUInteger)secondaryGroupingSize {
    return ((NSNumber*)(CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterSecondaryGroupingSize)))
        .unsignedIntegerValue;
}

/**
 @Status Interoperable
*/
- (void)setLenient:(BOOL)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(), kCFNumberFormatterIsLenient, value ? kCFBooleanTrue : kCFBooleanFalse);
}

/**
 @Status Interoperable
*/
- (BOOL)isLenient {
    return CFBooleanGetValue(
        static_cast<CFBooleanRef>(CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterIsLenient)));
}

/**
 @Status Interoperable
*/
- (void)setUsesSignificantDigits:(BOOL)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(),
                                 kCFNumberFormatterUseSignificantDigits,
                                 value ? kCFBooleanTrue : kCFBooleanFalse);
}

/**
 @Status Interoperable
*/
- (BOOL)usesSignificantDigits {
    return CFBooleanGetValue(
        static_cast<CFBooleanRef>(CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterUseSignificantDigits)));
}

/**
 @Status Interoperable
*/
- (void)setNumberStyle:(NSNumberFormatterStyle)value {
    woc::unique_cf<CFNumberFormatterRef> formatterCopy(
        CFNumberFormatterCreate(nullptr, static_cast<CFLocaleRef>([self locale]), (CFNumberFormatterStyle(value))));
    _copyPropertiesToFormatter(_cfNumberFormatter.get(), formatterCopy.get(), _wasMaxFractionDigitsSet, _wasMaxIntegerDigitsSet);
    _cfNumberFormatter.reset(formatterCopy.release());
}

/**
 @Status Interoperable
*/
- (NSNumberFormatterStyle)numberStyle {
    return (NSNumberFormatterStyle)(CFNumberFormatterGetStyle(_cfNumberFormatter.get()));
}

/**
 @Status Interoperable
*/
- (void)setRoundingMode:(NSNumberFormatterRoundingMode)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(),
                                 kCFNumberFormatterRoundingMode,
                                 reinterpret_cast<CFTypeRef>([NSNumber numberWithUnsignedInteger:value]));
}

/**
 @Status Interoperable
*/
- (NSNumberFormatterRoundingMode)roundingMode {
    return (NSNumberFormatterRoundingMode)(CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterRoundingMode));
}

/**
 @Status Interoperable
*/
- (void)setPaddingPosition:(NSNumberFormatterRoundingMode)value {
    CFNumberFormatterSetProperty(_cfNumberFormatter.get(),
                                 kCFNumberFormatterPaddingPosition,
                                 reinterpret_cast<CFTypeRef>([NSNumber numberWithUnsignedInteger:value]));
}

/**
 @Status Interoperable
*/
- (NSNumberFormatterPadPosition)paddingPosition {
    return (NSNumberFormatterPadPosition)(CFNumberFormatterCopyProperty(_cfNumberFormatter.get(), kCFNumberFormatterPaddingPosition));
}

static void _setCFInfinitySymbol(CFNumberFormatterRef formatter, NSString* value) {
    if (value != nil) {
        CFNumberFormatterSetProperty(formatter, kCFNumberFormatterInfinitySymbol, reinterpret_cast<CFTypeRef>(value));
    }
}

void _copyPropertiesToFormatter(CFNumberFormatterRef source,
                                CFNumberFormatterRef destination,
                                BOOL wasMaxFractionDigitsSet,
                                BOOL wasMaxIntegerDigitsSet) {
    static std::array<CFStringRef, 37> properties{ kCFNumberFormatterAlwaysShowDecimalSeparator,
                                                   kCFNumberFormatterCurrencyCode,
                                                   kCFNumberFormatterCurrencyDecimalSeparator,
                                                   kCFNumberFormatterCurrencyGroupingSeparator,
                                                   kCFNumberFormatterCurrencySymbol,
                                                   kCFNumberFormatterDecimalSeparator,
                                                   kCFNumberFormatterDefaultFormat,
                                                   kCFNumberFormatterExponentSymbol,
                                                   kCFNumberFormatterFormatWidth,
                                                   kCFNumberFormatterGroupingSeparator,
                                                   kCFNumberFormatterGroupingSize,
                                                   kCFNumberFormatterInfinitySymbol,
                                                   kCFNumberFormatterInternationalCurrencySymbol,
                                                   kCFNumberFormatterIsLenient,
                                                   kCFNumberFormatterMaxSignificantDigits,
                                                   kCFNumberFormatterMinFractionDigits,
                                                   kCFNumberFormatterMinIntegerDigits,
                                                   kCFNumberFormatterMinSignificantDigits,
                                                   kCFNumberFormatterMinusSign,
                                                   kCFNumberFormatterMultiplier,
                                                   kCFNumberFormatterNaNSymbol,
                                                   kCFNumberFormatterNegativePrefix,
                                                   kCFNumberFormatterNegativeSuffix,
                                                   kCFNumberFormatterPaddingCharacter,
                                                   kCFNumberFormatterPaddingPosition,
                                                   kCFNumberFormatterPerMillSymbol,
                                                   kCFNumberFormatterPercentSymbol,
                                                   kCFNumberFormatterPlusSign,
                                                   kCFNumberFormatterPositivePrefix,
                                                   kCFNumberFormatterPositiveSuffix,
                                                   kCFNumberFormatterRoundingIncrement,
                                                   kCFNumberFormatterRoundingMode,
                                                   kCFNumberFormatterSecondaryGroupingSize,
                                                   kCFNumberFormatterUseGroupingSeparator,
                                                   kCFNumberFormatterUseSignificantDigits,
                                                   kCFNumberFormatterZeroSymbol,
                                                   kCFNumberFormatterUsesCharacterDirectionKey };

    for (CFStringRef property : properties) {
        woc::unique_cf<CFTypeRef> value(CFNumberFormatterCopyProperty(source, property));
        if (value) {
            CFNumberFormatterSetProperty(destination, property, value.get());
        }
    }

    if (wasMaxFractionDigitsSet) {
        woc::unique_cf<CFTypeRef> value(CFNumberFormatterCopyProperty(source, kCFNumberFormatterMaxFractionDigits));
        if (value) {
            CFNumberFormatterSetProperty(destination, kCFNumberFormatterMaxFractionDigits, value.get());
        }
    }

    if (wasMaxIntegerDigitsSet) {
        woc::unique_cf<CFTypeRef> value(CFNumberFormatterCopyProperty(source, kCFNumberFormatterMaxIntegerDigits));
        if (value) {
            CFNumberFormatterSetProperty(destination, kCFNumberFormatterMaxIntegerDigits, value.get());
        }
    }
}

/**
 @Status Interoperable
*/
- (void)setLocale:(NSLocale*)value {
    woc::unique_cf<CFNumberFormatterRef> formatterCopy(
        CFNumberFormatterCreate(nullptr, static_cast<CFLocaleRef>(value), CFNumberFormatterGetStyle(_cfNumberFormatter.get())));
    _copyPropertiesToFormatter(_cfNumberFormatter.get(), formatterCopy.get(), _wasMaxFractionDigitsSet, _wasMaxIntegerDigitsSet);
    _cfNumberFormatter.reset(formatterCopy.release());
}

/**
 @Status Interoperable
*/
- (NSLocale*)locale {
    return static_cast<NSLocale*>(CFNumberFormatterGetLocale(_cfNumberFormatter.get()));
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
 @Status Interoperable
*/
- (NSNumber*)numberFromString:(NSString*)string {
    CFRange range = CFRangeMake(0, string.length);

    return [static_cast<NSNumber*>(
        CFNumberFormatterCreateNumberFromString(nullptr, _cfNumberFormatter.get(), static_cast<CFStringRef>(string), &range, 0))
        autorelease];
}

- (NSString*)stringFromNumber:(NSNumber*)number {
    if (number == nil) {
        return self.nilSymbol;
    }

    if (!_finite(number.floatValue)) {
        if (number.floatValue > 0) {
            _setCFInfinitySymbol(_cfNumberFormatter.get(), _positiveInfinitySymbol);
        } else {
            _setCFInfinitySymbol(_cfNumberFormatter.get(), _negativeInfinitySymbol);
        }
    }

    return [static_cast<NSString*>(
        CFNumberFormatterCreateStringWithNumber(nullptr, _cfNumberFormatter.get(), static_cast<CFNumberRef>(number))) autorelease];
}

/**
 @Status Interoperable
*/
+ (NSString*)localizedStringFromNumber:(NSNumber*)number numberStyle:(NSNumberFormatterStyle)style {
    NSNumberFormatter* formatter = [self new];
    [formatter setNumberStyle:style];

    NSString* ret = [formatter stringFromNumber:number];
    [formatter release];

    return ret;
}

/**
 @Status Caveat
 @Notes Unused.
*/
+ (void)setDefaultFormatterBehavior:(NSNumberFormatterBehavior)behavior {
    _defaultFormatterBehavior = behavior;
}

/**
 @Status Caveat
 @Notes generatesDecimalNumbers should generate an NSDecimalNumber.
*/
- (BOOL)getObjectValue:(id _Nullable*)anObject forString:(NSString*)aString range:(NSRange*)rangep error:(NSError* _Nullable*)error {
    if (anObject) {
        *anObject = [self numberFromString:[aString substringWithRange:*rangep]];
    } else {
        return NO;
    }

    return YES;
}

@end
