//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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
#pragma once

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>

#import <Foundation/NSFormatter.h>

@class NSString;
@class NSNumber;
@class NSLocale;
@class NSDictionary;

#import <CoreFoundation/CFNumberFormatter.h>
#import <Foundation/NSError.h>
typedef NSUInteger NSNumberFormatterStyle;
typedef NSUInteger NSNumberFormatterBehavior;
typedef NSUInteger NSNumberFormatterPadPosition;
typedef NSUInteger NSNumberFormatterRoundingMode;
enum {
    NSNumberFormatterNoStyle = kCFNumberFormatterNoStyle,
    NSNumberFormatterDecimalStyle = kCFNumberFormatterDecimalStyle,
    NSNumberFormatterCurrencyStyle = kCFNumberFormatterCurrencyStyle,
    NSNumberFormatterPercentStyle = kCFNumberFormatterPercentStyle,
    NSNumberFormatterScientificStyle = kCFNumberFormatterScientificStyle,
    NSNumberFormatterSpellOutStyle = kCFNumberFormatterSpellOutStyle,
    NSNumberFormatterOrdinalStyle = kCFNumberFormatterOrdinalStyle,
    NSNumberFormatterCurrencyISOCodeStyle = kCFNumberFormatterCurrencyISOCodeStyle,
    NSNumberFormatterCurrencyPluralStyle = kCFNumberFormatterCurrencyPluralStyle,
    NSNumberFormatterCurrencyAccountingStyle = kCFNumberFormatterCurrencyAccountingStyle
};

enum {
    NSNumberFormatterBehaviorDefault = 0,
    NSNumberFormatterBehavior10_0 = 1000,
    NSNumberFormatterBehavior10_4 = 1040,
};

enum {
    NSNumberFormatterPadBeforePrefix = kCFNumberFormatterPadBeforePrefix,
    NSNumberFormatterPadAfterPrefix = kCFNumberFormatterPadAfterPrefix,
    NSNumberFormatterPadBeforeSuffix = kCFNumberFormatterPadBeforeSuffix,
    NSNumberFormatterPadAfterSuffix = kCFNumberFormatterPadAfterSuffix
};

enum {
    NSNumberFormatterRoundCeiling = kCFNumberFormatterRoundCeiling,
    NSNumberFormatterRoundFloor = kCFNumberFormatterRoundFloor,
    NSNumberFormatterRoundDown = kCFNumberFormatterRoundDown,
    NSNumberFormatterRoundUp = kCFNumberFormatterRoundUp,
    NSNumberFormatterRoundHalfEven = kCFNumberFormatterRoundHalfEven,
    NSNumberFormatterRoundHalfDown = kCFNumberFormatterRoundHalfDown,
    NSNumberFormatterRoundHalfUp = kCFNumberFormatterRoundHalfUp
};

FOUNDATION_EXPORT_CLASS
@interface NSNumberFormatter : NSFormatter <NSCoding, NSCopying>

/**
@Status Caveat
@Notes NSNumberFormatterBehavior10_0 likely crashes.
*/
@property NSNumberFormatterBehavior formatterBehavior;
@property NSNumberFormatterStyle numberStyle;
@property BOOL generatesDecimalNumbers;

@property (copy) NSLocale* locale;
@property (copy) NSNumber* roundingIncrement;
@property NSNumberFormatterRoundingMode roundingMode;
@property NSFormattingContext formattingContext;
@property NSUInteger formatWidth;
@property (copy) NSString* negativeFormat;
@property (copy) NSString* positiveFormat;
@property (copy) NSNumber* multiplier;
@property (copy) NSString* percentSymbol;
@property (copy) NSString* perMillSymbol;
@property (copy) NSString* minusSign;
@property (copy) NSString* plusSign;
@property (copy) NSString* exponentSymbol;
@property (copy) NSString* zeroSymbol;
@property (copy) NSString* nilSymbol;
@property (copy) NSString* notANumberSymbol;
@property (copy) NSString* negativeInfinitySymbol;
@property (copy) NSString* positiveInfinitySymbol;
@property (copy) NSString* currencySymbol;
@property (copy) NSString* currencyCode;
@property (copy) NSString* internationalCurrencySymbol;
@property (copy) NSString* currencyGroupingSeparator;
@property (copy) NSString* positivePrefix;
@property (copy) NSString* positiveSuffix;
@property (copy) NSString* negativePrefix;
@property (copy) NSString* negativeSuffix;
@property (copy) NSDictionary* textAttributesForNegativeValues;
@property (copy) NSDictionary* textAttributesForPositiveValues;
@property (copy) NSDictionary* textAttributesForZero;
@property (copy) NSDictionary* textAttributesForNil;
@property (copy) NSDictionary* textAttributesForNotANumber;
@property (copy) NSDictionary* textAttributesForPositiveInfinity;
@property (copy) NSDictionary* textAttributesForNegativeInfinity;
@property (copy) NSString* groupingSeparator;
@property BOOL usesGroupingSeparator;
@property (copy) NSString* decimalSeparator;
@property BOOL alwaysShowsDecimalSeparator;
@property (copy) NSString* currencyDecimalSeparator;
@property NSUInteger groupingSize;
@property NSUInteger secondaryGroupingSize;
@property (copy) NSString* paddingCharacter;
@property NSNumberFormatterPadPosition paddingPosition;
@property BOOL allowsFloats;
@property (copy) NSNumber* minimum;
@property (copy) NSNumber* maximum;
@property NSUInteger minimumIntegerDigits;
@property NSUInteger minimumFractionDigits;
@property NSUInteger maximumIntegerDigits;
@property NSUInteger maximumFractionDigits;
@property BOOL usesSignificantDigits;
@property NSUInteger minimumSignificantDigits;
@property NSUInteger maximumSignificantDigits;
@property (getter=isLenient) BOOL lenient;
@property (getter=isPartialStringValidationEnabled) BOOL partialStringValidationEnabled;

+ (void)setDefaultFormatterBehavior:(NSNumberFormatterBehavior)behavior;
+ (NSNumberFormatterBehavior)defaultFormatterBehavior;
+ (NSString*)localizedStringFromNumber:(NSNumber*)num numberStyle:(NSNumberFormatterStyle)localizationStyle;
- (BOOL)getObjectValue:(id _Nullable*)anObject forString:(NSString*)aString range:(NSRange*)rangep error:(NSError* _Nullable*)error;
- (NSNumber*)numberFromString:(NSString*)string;
- (NSString*)stringFromNumber:(NSNumber*)number;

@end
