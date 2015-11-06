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

// WindowsGlobalizationNumberFormatting.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WGNSignificantDigitsNumberRounder, WGNIncrementNumberRounder, WGNDecimalFormatter, WGNPercentFormatter, WGNPermilleFormatter,
    WGNCurrencyFormatter, WGNNumeralSystemTranslator;
@protocol WGNINumberRounder
, WGNISignificantDigitsNumberRounder, WGNIIncrementNumberRounder, WGNINumberFormatter, WGNINumberFormatter2, WGNINumberParser,
    WGNINumberFormatterOptions, WGNISignificantDigitsOption, WGNINumberRounderOption, WGNISignedZeroOption, WGNIDecimalFormatterFactory,
    WGNIPercentFormatterFactory, WGNIPermilleFormatterFactory, WGNICurrencyFormatterFactory, WGNICurrencyFormatter, WGNICurrencyFormatter2,
    WGNINumeralSystemTranslatorFactory, WGNINumeralSystemTranslator;

// Windows.Globalization.NumberFormatting.RoundingAlgorithm
enum _WGNRoundingAlgorithm {
    WGNRoundingAlgorithmNone = 0,
    WGNRoundingAlgorithmRoundDown = 1,
    WGNRoundingAlgorithmRoundUp = 2,
    WGNRoundingAlgorithmRoundTowardsZero = 3,
    WGNRoundingAlgorithmRoundAwayFromZero = 4,
    WGNRoundingAlgorithmRoundHalfDown = 5,
    WGNRoundingAlgorithmRoundHalfUp = 6,
    WGNRoundingAlgorithmRoundHalfTowardsZero = 7,
    WGNRoundingAlgorithmRoundHalfAwayFromZero = 8,
    WGNRoundingAlgorithmRoundHalfToEven = 9,
    WGNRoundingAlgorithmRoundHalfToOdd = 10,
};
typedef unsigned WGNRoundingAlgorithm;

// Windows.Globalization.NumberFormatting.CurrencyFormatterMode
enum _WGNCurrencyFormatterMode {
    WGNCurrencyFormatterModeUseSymbol = 0,
    WGNCurrencyFormatterModeUseCurrencyCode = 1,
};
typedef unsigned WGNCurrencyFormatterMode;

#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"

#import <Foundation/Foundation.h>

// Windows.Globalization.NumberFormatting.INumberRounder
#ifndef __WGNINumberRounder_DEFINED__
#define __WGNINumberRounder_DEFINED__

@protocol WGNINumberRounder
- (int)roundInt32:(int)value;
- (unsigned int)roundUInt32:(unsigned int)value;
- (int64_t)roundInt64:(int64_t)value;
- (uint64_t)roundUInt64:(uint64_t)value;
- (float)roundSingle:(float)value;
- (double)roundDouble:(double)value;
@end

#endif // __WGNINumberRounder_DEFINED__

// Windows.Globalization.NumberFormatting.INumberFormatter
#ifndef __WGNINumberFormatter_DEFINED__
#define __WGNINumberFormatter_DEFINED__

@protocol WGNINumberFormatter
- (NSString*)formatInt:(int64_t)value;
- (NSString*)formatUInt:(uint64_t)value;
- (NSString*)formatDouble:(double)value;
@end

#endif // __WGNINumberFormatter_DEFINED__

// Windows.Globalization.NumberFormatting.INumberFormatter2
#ifndef __WGNINumberFormatter2_DEFINED__
#define __WGNINumberFormatter2_DEFINED__

@protocol WGNINumberFormatter2
- (NSString*)formatInt:(int64_t)value;
- (NSString*)formatUInt:(uint64_t)value;
- (NSString*)formatDouble:(double)value;
@end

#endif // __WGNINumberFormatter2_DEFINED__

// Windows.Globalization.NumberFormatting.INumberParser
#ifndef __WGNINumberParser_DEFINED__
#define __WGNINumberParser_DEFINED__

@protocol WGNINumberParser
- (id)parseInt:(NSString*)text;
- (id)parseUInt:(NSString*)text;
- (id)parseDouble:(NSString*)text;
@end

#endif // __WGNINumberParser_DEFINED__

// Windows.Globalization.NumberFormatting.INumberFormatterOptions
#ifndef __WGNINumberFormatterOptions_DEFINED__
#define __WGNINumberFormatterOptions_DEFINED__

@protocol WGNINumberFormatterOptions
@property int fractionDigits;
@property (readonly) NSString* geographicRegion;
@property int integerDigits;
@property BOOL isDecimalPointAlwaysDisplayed;
@property BOOL isGrouped;
@property (readonly) NSArray* languages;
@property (copy) NSString* numeralSystem;
@property (readonly) NSString* resolvedGeographicRegion;
@property (readonly) NSString* resolvedLanguage;
@end

#endif // __WGNINumberFormatterOptions_DEFINED__

// Windows.Globalization.NumberFormatting.ISignificantDigitsOption
#ifndef __WGNISignificantDigitsOption_DEFINED__
#define __WGNISignificantDigitsOption_DEFINED__

@protocol WGNISignificantDigitsOption
@property int significantDigits;
@end

#endif // __WGNISignificantDigitsOption_DEFINED__

// Windows.Globalization.NumberFormatting.INumberRounderOption
#ifndef __WGNINumberRounderOption_DEFINED__
#define __WGNINumberRounderOption_DEFINED__

@protocol WGNINumberRounderOption
@property (copy) RTObject<WGNINumberRounder>* numberRounder;
@end

#endif // __WGNINumberRounderOption_DEFINED__

// Windows.Globalization.NumberFormatting.ISignedZeroOption
#ifndef __WGNISignedZeroOption_DEFINED__
#define __WGNISignedZeroOption_DEFINED__

@protocol WGNISignedZeroOption
@property BOOL isZeroSigned;
@end

#endif // __WGNISignedZeroOption_DEFINED__

// Windows.Globalization.NumberFormatting.SignificantDigitsNumberRounder
#ifndef __WGNSignificantDigitsNumberRounder_DEFINED__
#define __WGNSignificantDigitsNumberRounder_DEFINED__

WINRT_EXPORT
@interface WGNSignificantDigitsNumberRounder : RTObject <WGNINumberRounder>
+ (instancetype)create ACTIVATOR;
@property unsigned int significantDigits;
@property WGNRoundingAlgorithm roundingAlgorithm;
- (int)roundInt32:(int)value;
- (unsigned int)roundUInt32:(unsigned int)value;
- (int64_t)roundInt64:(int64_t)value;
- (uint64_t)roundUInt64:(uint64_t)value;
- (float)roundSingle:(float)value;
- (double)roundDouble:(double)value;
@end

#endif // __WGNSignificantDigitsNumberRounder_DEFINED__

// Windows.Globalization.NumberFormatting.IncrementNumberRounder
#ifndef __WGNIncrementNumberRounder_DEFINED__
#define __WGNIncrementNumberRounder_DEFINED__

WINRT_EXPORT
@interface WGNIncrementNumberRounder : RTObject <WGNINumberRounder>
+ (instancetype)create ACTIVATOR;
@property WGNRoundingAlgorithm roundingAlgorithm;
@property double increment;
- (int)roundInt32:(int)value;
- (unsigned int)roundUInt32:(unsigned int)value;
- (int64_t)roundInt64:(int64_t)value;
- (uint64_t)roundUInt64:(uint64_t)value;
- (float)roundSingle:(float)value;
- (double)roundDouble:(double)value;
@end

#endif // __WGNIncrementNumberRounder_DEFINED__

// Windows.Globalization.NumberFormatting.DecimalFormatter
#ifndef __WGNDecimalFormatter_DEFINED__
#define __WGNDecimalFormatter_DEFINED__

WINRT_EXPORT
@interface WGNDecimalFormatter : RTObject <WGNINumberFormatterOptions,
                                           WGNINumberFormatter,
                                           WGNINumberFormatter2,
                                           WGNINumberParser,
                                           WGNISignificantDigitsOption,
                                           WGNINumberRounderOption,
                                           WGNISignedZeroOption>
+ (instancetype)create ACTIVATOR;
+ (WGNDecimalFormatter*)createDecimalFormatter:(id<NSFastEnumeration> /* NSString * */)languages
                              geographicRegion:(NSString*)geographicRegion ACTIVATOR;
@property BOOL isDecimalPointAlwaysDisplayed;
@property int integerDigits;
@property BOOL isGrouped;
@property int fractionDigits;
@property (copy) NSString* numeralSystem;
@property (readonly) NSString* geographicRegion;
@property (readonly) NSArray* languages;
@property (readonly) NSString* resolvedGeographicRegion;
@property (readonly) NSString* resolvedLanguage;
@property (copy) RTObject<WGNINumberRounder>* numberRounder;
@property BOOL isZeroSigned;
@property int significantDigits;
- (NSString*)formatInt:(int64_t)value;
- (NSString*)formatUInt:(uint64_t)value;
- (NSString*)formatDouble:(double)value;
- (id)parseInt:(NSString*)text;
- (id)parseUInt:(NSString*)text;
- (id)parseDouble:(NSString*)text;
@end

#endif // __WGNDecimalFormatter_DEFINED__

// Windows.Globalization.NumberFormatting.PercentFormatter
#ifndef __WGNPercentFormatter_DEFINED__
#define __WGNPercentFormatter_DEFINED__

WINRT_EXPORT
@interface WGNPercentFormatter : RTObject <WGNINumberFormatterOptions,
                                           WGNINumberFormatter,
                                           WGNINumberFormatter2,
                                           WGNINumberParser,
                                           WGNISignificantDigitsOption,
                                           WGNINumberRounderOption,
                                           WGNISignedZeroOption>
+ (instancetype)create ACTIVATOR;
+ (WGNPercentFormatter*)createPercentFormatter:(id<NSFastEnumeration> /* NSString * */)languages
                              geographicRegion:(NSString*)geographicRegion ACTIVATOR;
@property BOOL isDecimalPointAlwaysDisplayed;
@property int integerDigits;
@property BOOL isGrouped;
@property int fractionDigits;
@property (copy) NSString* numeralSystem;
@property (readonly) NSString* geographicRegion;
@property (readonly) NSArray* languages;
@property (readonly) NSString* resolvedGeographicRegion;
@property (readonly) NSString* resolvedLanguage;
@property (copy) RTObject<WGNINumberRounder>* numberRounder;
@property BOOL isZeroSigned;
@property int significantDigits;
- (NSString*)formatInt:(int64_t)value;
- (NSString*)formatUInt:(uint64_t)value;
- (NSString*)formatDouble:(double)value;
- (id)parseInt:(NSString*)text;
- (id)parseUInt:(NSString*)text;
- (id)parseDouble:(NSString*)text;
@end

#endif // __WGNPercentFormatter_DEFINED__

// Windows.Globalization.NumberFormatting.PermilleFormatter
#ifndef __WGNPermilleFormatter_DEFINED__
#define __WGNPermilleFormatter_DEFINED__

WINRT_EXPORT
@interface WGNPermilleFormatter : RTObject <WGNINumberFormatterOptions,
                                            WGNINumberFormatter,
                                            WGNINumberFormatter2,
                                            WGNINumberParser,
                                            WGNISignificantDigitsOption,
                                            WGNINumberRounderOption,
                                            WGNISignedZeroOption>
+ (WGNPermilleFormatter*)createPermilleFormatter:(id<NSFastEnumeration> /* NSString * */)languages
                                geographicRegion:(NSString*)geographicRegion ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property BOOL isDecimalPointAlwaysDisplayed;
@property int integerDigits;
@property BOOL isGrouped;
@property int fractionDigits;
@property (copy) NSString* numeralSystem;
@property (readonly) NSString* geographicRegion;
@property (readonly) NSArray* languages;
@property (readonly) NSString* resolvedGeographicRegion;
@property (readonly) NSString* resolvedLanguage;
@property (copy) RTObject<WGNINumberRounder>* numberRounder;
@property BOOL isZeroSigned;
@property int significantDigits;
- (NSString*)formatInt:(int64_t)value;
- (NSString*)formatUInt:(uint64_t)value;
- (NSString*)formatDouble:(double)value;
- (id)parseInt:(NSString*)text;
- (id)parseUInt:(NSString*)text;
- (id)parseDouble:(NSString*)text;
@end

#endif // __WGNPermilleFormatter_DEFINED__

// Windows.Globalization.NumberFormatting.CurrencyFormatter
#ifndef __WGNCurrencyFormatter_DEFINED__
#define __WGNCurrencyFormatter_DEFINED__

WINRT_EXPORT
@interface WGNCurrencyFormatter : RTObject <WGNINumberParser,
                                            WGNINumberFormatter2,
                                            WGNINumberFormatter,
                                            WGNINumberFormatterOptions,
                                            WGNISignificantDigitsOption,
                                            WGNINumberRounderOption,
                                            WGNISignedZeroOption>
+ (WGNCurrencyFormatter*)createCurrencyFormatterCode:(NSString*)currencyCode ACTIVATOR;
+ (WGNCurrencyFormatter*)createCurrencyFormatterCodeContext:(NSString*)currencyCode
                                                  languages:(id<NSFastEnumeration> /* NSString * */)languages
                                           geographicRegion:(NSString*)geographicRegion ACTIVATOR;
@property (copy) NSString* currency;
@property WGNCurrencyFormatterMode mode;
@property BOOL isGrouped;
@property BOOL isDecimalPointAlwaysDisplayed;
@property int integerDigits;
@property int fractionDigits;
@property (copy) NSString* numeralSystem;
@property (readonly) NSString* geographicRegion;
@property (readonly) NSString* resolvedGeographicRegion;
@property (readonly) NSString* resolvedLanguage;
@property (readonly) NSArray* languages;
@property (copy) RTObject<WGNINumberRounder>* numberRounder;
@property BOOL isZeroSigned;
@property int significantDigits;
- (NSString*)formatInt:(int64_t)value;
- (NSString*)formatUInt:(uint64_t)value;
- (NSString*)formatDouble:(double)value;
- (id)parseInt:(NSString*)text;
- (id)parseUInt:(NSString*)text;
- (id)parseDouble:(NSString*)text;
- (void)applyRoundingForCurrency:(WGNRoundingAlgorithm)roundingAlgorithm;
@end

#endif // __WGNCurrencyFormatter_DEFINED__

// Windows.Globalization.NumberFormatting.NumeralSystemTranslator
#ifndef __WGNNumeralSystemTranslator_DEFINED__
#define __WGNNumeralSystemTranslator_DEFINED__

WINRT_EXPORT
@interface WGNNumeralSystemTranslator : RTObject
+ (WGNNumeralSystemTranslator*)create:(id<NSFastEnumeration> /* NSString * */)languages ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* numeralSystem;
@property (readonly) NSArray* languages;
@property (readonly) NSString* resolvedLanguage;
- (NSString*)translateNumerals:(NSString*)value;
@end

#endif // __WGNNumeralSystemTranslator_DEFINED__
