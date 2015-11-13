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

// WindowsDataText.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WDTSemanticTextQuery, WDTUnicodeCharacters, WDTAlternateWordForm, WDTWordSegment, WDTWordsSegmenter, WDTSelectableWordSegment,
    WDTSelectableWordsSegmenter, WDTTextPredictionGenerator, WDTTextConversionGenerator, WDTTextReverseConversionGenerator;
@class WDTTextSegment;
@protocol WDTISemanticTextQueryFactory
, WDTISemanticTextQuery, WDTIUnicodeCharactersStatics, WDTIAlternateWordForm, WDTISelectableWordSegment, WDTIWordSegment,
    WDTIWordsSegmenter, WDTIWordsSegmenterFactory, WDTISelectableWordsSegmenter, WDTISelectableWordsSegmenterFactory,
    WDTITextPredictionGenerator, WDTITextPredictionGeneratorFactory, WDTITextConversionGenerator, WDTITextConversionGeneratorFactory,
    WDTITextReverseConversionGenerator, WDTITextReverseConversionGeneratorFactory;

// Windows.Data.Text.UnicodeGeneralCategory
enum _WDTUnicodeGeneralCategory {
    WDTUnicodeGeneralCategoryUppercaseLetter = 0,
    WDTUnicodeGeneralCategoryLowercaseLetter = 1,
    WDTUnicodeGeneralCategoryTitlecaseLetter = 2,
    WDTUnicodeGeneralCategoryModifierLetter = 3,
    WDTUnicodeGeneralCategoryOtherLetter = 4,
    WDTUnicodeGeneralCategoryNonspacingMark = 5,
    WDTUnicodeGeneralCategorySpacingCombiningMark = 6,
    WDTUnicodeGeneralCategoryEnclosingMark = 7,
    WDTUnicodeGeneralCategoryDecimalDigitNumber = 8,
    WDTUnicodeGeneralCategoryLetterNumber = 9,
    WDTUnicodeGeneralCategoryOtherNumber = 10,
    WDTUnicodeGeneralCategorySpaceSeparator = 11,
    WDTUnicodeGeneralCategoryLineSeparator = 12,
    WDTUnicodeGeneralCategoryParagraphSeparator = 13,
    WDTUnicodeGeneralCategoryControl = 14,
    WDTUnicodeGeneralCategoryFormat = 15,
    WDTUnicodeGeneralCategorySurrogate = 16,
    WDTUnicodeGeneralCategoryPrivateUse = 17,
    WDTUnicodeGeneralCategoryConnectorPunctuation = 18,
    WDTUnicodeGeneralCategoryDashPunctuation = 19,
    WDTUnicodeGeneralCategoryOpenPunctuation = 20,
    WDTUnicodeGeneralCategoryClosePunctuation = 21,
    WDTUnicodeGeneralCategoryInitialQuotePunctuation = 22,
    WDTUnicodeGeneralCategoryFinalQuotePunctuation = 23,
    WDTUnicodeGeneralCategoryOtherPunctuation = 24,
    WDTUnicodeGeneralCategoryMathSymbol = 25,
    WDTUnicodeGeneralCategoryCurrencySymbol = 26,
    WDTUnicodeGeneralCategoryModifierSymbol = 27,
    WDTUnicodeGeneralCategoryOtherSymbol = 28,
    WDTUnicodeGeneralCategoryNotAssigned = 29,
};
typedef unsigned WDTUnicodeGeneralCategory;

// Windows.Data.Text.UnicodeNumericType
enum _WDTUnicodeNumericType {
    WDTUnicodeNumericTypeNone = 0,
    WDTUnicodeNumericTypeDecimal = 1,
    WDTUnicodeNumericTypeDigit = 2,
    WDTUnicodeNumericTypeNumeric = 3,
};
typedef unsigned WDTUnicodeNumericType;

// Windows.Data.Text.AlternateNormalizationFormat
enum _WDTAlternateNormalizationFormat {
    WDTAlternateNormalizationFormatNotNormalized = 0,
    WDTAlternateNormalizationFormatNumber = 1,
    WDTAlternateNormalizationFormatCurrency = 3,
    WDTAlternateNormalizationFormatDate = 4,
    WDTAlternateNormalizationFormatTime = 5,
};
typedef unsigned WDTAlternateNormalizationFormat;

#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"
// Windows.Data.Text.SelectableWordSegmentsTokenizingHandler
#ifndef __WDTSelectableWordSegmentsTokenizingHandler__DEFINED
#define __WDTSelectableWordSegmentsTokenizingHandler__DEFINED
typedef void (^WDTSelectableWordSegmentsTokenizingHandler)(id<NSFastEnumeration> /* WDTSelectableWordSegment* */ precedingWords,
                                                           id<NSFastEnumeration> /* WDTSelectableWordSegment* */ words);
#endif // __WDTSelectableWordSegmentsTokenizingHandler__DEFINED

// Windows.Data.Text.WordSegmentsTokenizingHandler
#ifndef __WDTWordSegmentsTokenizingHandler__DEFINED
#define __WDTWordSegmentsTokenizingHandler__DEFINED
typedef void (^WDTWordSegmentsTokenizingHandler)(id<NSFastEnumeration> /* WDTWordSegment* */ precedingWords,
                                                 id<NSFastEnumeration> /* WDTWordSegment* */ words);
#endif // __WDTWordSegmentsTokenizingHandler__DEFINED

#import <Foundation/Foundation.h>

// [struct] Windows.Data.Text.TextSegment
WINRT_EXPORT
@interface WDTTextSegment : NSObject
+ (instancetype) new;
@property unsigned int startPosition;
@property unsigned int length;
@end

// Windows.Data.Text.WordSegmentsTokenizingHandler
#ifndef __WDTWordSegmentsTokenizingHandler__DEFINED
#define __WDTWordSegmentsTokenizingHandler__DEFINED
typedef void (^WDTWordSegmentsTokenizingHandler)(id<NSFastEnumeration> /* WDTWordSegment* */ precedingWords,
                                                 id<NSFastEnumeration> /* WDTWordSegment* */ words);
#endif // __WDTWordSegmentsTokenizingHandler__DEFINED

// Windows.Data.Text.SelectableWordSegmentsTokenizingHandler
#ifndef __WDTSelectableWordSegmentsTokenizingHandler__DEFINED
#define __WDTSelectableWordSegmentsTokenizingHandler__DEFINED
typedef void (^WDTSelectableWordSegmentsTokenizingHandler)(id<NSFastEnumeration> /* WDTSelectableWordSegment* */ precedingWords,
                                                           id<NSFastEnumeration> /* WDTSelectableWordSegment* */ words);
#endif // __WDTSelectableWordSegmentsTokenizingHandler__DEFINED

// Windows.Data.Text.SemanticTextQuery
#ifndef __WDTSemanticTextQuery_DEFINED__
#define __WDTSemanticTextQuery_DEFINED__

WINRT_EXPORT
@interface WDTSemanticTextQuery : RTObject
+ (WDTSemanticTextQuery*)create:(NSString*)aqsFilter ACTIVATOR;
+ (WDTSemanticTextQuery*)createWithLanguage:(NSString*)aqsFilter filterLanguage:(NSString*)filterLanguage ACTIVATOR;
- (NSArray*)find:(NSString*)content;
- (NSArray*)findInProperty:(NSString*)propertyContent propertyName:(NSString*)propertyName;
@end

#endif // __WDTSemanticTextQuery_DEFINED__

// Windows.Data.Text.UnicodeCharacters
#ifndef __WDTUnicodeCharacters_DEFINED__
#define __WDTUnicodeCharacters_DEFINED__

WINRT_EXPORT
@interface WDTUnicodeCharacters : RTObject
+ (unsigned int)getCodepointFromSurrogatePair:(unsigned int)highSurrogate lowSurrogate:(unsigned int)lowSurrogate;
+ (void)getSurrogatePairFromCodepoint:(unsigned int)codepoint highSurrogate:(WCHAR*)highSurrogate lowSurrogate:(WCHAR*)lowSurrogate;
+ (BOOL)isHighSurrogate:(unsigned int)codepoint;
+ (BOOL)isLowSurrogate:(unsigned int)codepoint;
+ (BOOL)isSupplementary:(unsigned int)codepoint;
+ (BOOL)isNoncharacter:(unsigned int)codepoint;
+ (BOOL)isWhitespace:(unsigned int)codepoint;
+ (BOOL)isAlphabetic:(unsigned int)codepoint;
+ (BOOL)isCased:(unsigned int)codepoint;
+ (BOOL)isUppercase:(unsigned int)codepoint;
+ (BOOL)isLowercase:(unsigned int)codepoint;
+ (BOOL)isIdStart:(unsigned int)codepoint;
+ (BOOL)isIdContinue:(unsigned int)codepoint;
+ (BOOL)isGraphemeBase:(unsigned int)codepoint;
+ (BOOL)isGraphemeExtend:(unsigned int)codepoint;
+ (WDTUnicodeNumericType)getNumericType:(unsigned int)codepoint;
+ (WDTUnicodeGeneralCategory)getGeneralCategory:(unsigned int)codepoint;
@end

#endif // __WDTUnicodeCharacters_DEFINED__

// Windows.Data.Text.AlternateWordForm
#ifndef __WDTAlternateWordForm_DEFINED__
#define __WDTAlternateWordForm_DEFINED__

WINRT_EXPORT
@interface WDTAlternateWordForm : RTObject
@property (readonly) NSString* alternateText;
@property (readonly) WDTAlternateNormalizationFormat normalizationFormat;
@property (readonly) WDTTextSegment* sourceTextSegment;
@end

#endif // __WDTAlternateWordForm_DEFINED__

// Windows.Data.Text.WordSegment
#ifndef __WDTWordSegment_DEFINED__
#define __WDTWordSegment_DEFINED__

WINRT_EXPORT
@interface WDTWordSegment : RTObject
@property (readonly) NSArray* alternateForms;
@property (readonly) WDTTextSegment* sourceTextSegment;
@property (readonly) NSString* text;
@end

#endif // __WDTWordSegment_DEFINED__

// Windows.Data.Text.WordsSegmenter
#ifndef __WDTWordsSegmenter_DEFINED__
#define __WDTWordsSegmenter_DEFINED__

WINRT_EXPORT
@interface WDTWordsSegmenter : RTObject
+ (WDTWordsSegmenter*)createWithLanguage:(NSString*)language ACTIVATOR;
@property (readonly) NSString* resolvedLanguage;
- (WDTWordSegment*)getTokenAt:(NSString*)text startIndex:(unsigned int)startIndex;
- (NSArray*)getTokens:(NSString*)text;
- (void)tokenize:(NSString*)text startIndex:(unsigned int)startIndex handler:(WDTWordSegmentsTokenizingHandler)handler;
@end

#endif // __WDTWordsSegmenter_DEFINED__

// Windows.Data.Text.SelectableWordSegment
#ifndef __WDTSelectableWordSegment_DEFINED__
#define __WDTSelectableWordSegment_DEFINED__

WINRT_EXPORT
@interface WDTSelectableWordSegment : RTObject
@property (readonly) WDTTextSegment* sourceTextSegment;
@property (readonly) NSString* text;
@end

#endif // __WDTSelectableWordSegment_DEFINED__

// Windows.Data.Text.SelectableWordsSegmenter
#ifndef __WDTSelectableWordsSegmenter_DEFINED__
#define __WDTSelectableWordsSegmenter_DEFINED__

WINRT_EXPORT
@interface WDTSelectableWordsSegmenter : RTObject
+ (WDTSelectableWordsSegmenter*)createWithLanguage:(NSString*)language ACTIVATOR;
@property (readonly) NSString* resolvedLanguage;
- (WDTSelectableWordSegment*)getTokenAt:(NSString*)text startIndex:(unsigned int)startIndex;
- (NSArray*)getTokens:(NSString*)text;
- (void)tokenize:(NSString*)text startIndex:(unsigned int)startIndex handler:(WDTSelectableWordSegmentsTokenizingHandler)handler;
@end

#endif // __WDTSelectableWordsSegmenter_DEFINED__

// Windows.Data.Text.TextPredictionGenerator
#ifndef __WDTTextPredictionGenerator_DEFINED__
#define __WDTTextPredictionGenerator_DEFINED__

WINRT_EXPORT
@interface WDTTextPredictionGenerator : RTObject
+ (WDTTextPredictionGenerator*)create:(NSString*)languageTag ACTIVATOR;
@property (readonly) BOOL languageAvailableButNotInstalled;
@property (readonly) NSString* resolvedLanguage;
- (void)getCandidatesAsync:(NSString*)input success:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
- (void)getCandidatesWithMaxCountAsync:(NSString*)input
                         maxCandidates:(unsigned int)maxCandidates
                               success:(void (^)(NSArray*))success
                               failure:(void (^)(NSError*))failure;
@end

#endif // __WDTTextPredictionGenerator_DEFINED__

// Windows.Data.Text.TextConversionGenerator
#ifndef __WDTTextConversionGenerator_DEFINED__
#define __WDTTextConversionGenerator_DEFINED__

WINRT_EXPORT
@interface WDTTextConversionGenerator : RTObject
+ (WDTTextConversionGenerator*)create:(NSString*)languageTag ACTIVATOR;
@property (readonly) BOOL languageAvailableButNotInstalled;
@property (readonly) NSString* resolvedLanguage;
- (void)getCandidatesAsync:(NSString*)input success:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
- (void)getCandidatesWithMaxCountAsync:(NSString*)input
                         maxCandidates:(unsigned int)maxCandidates
                               success:(void (^)(NSArray*))success
                               failure:(void (^)(NSError*))failure;
@end

#endif // __WDTTextConversionGenerator_DEFINED__

// Windows.Data.Text.TextReverseConversionGenerator
#ifndef __WDTTextReverseConversionGenerator_DEFINED__
#define __WDTTextReverseConversionGenerator_DEFINED__

WINRT_EXPORT
@interface WDTTextReverseConversionGenerator : RTObject
+ (WDTTextReverseConversionGenerator*)create:(NSString*)languageTag ACTIVATOR;
@property (readonly) BOOL languageAvailableButNotInstalled;
@property (readonly) NSString* resolvedLanguage;
- (void)convertBackAsync:(NSString*)input success:(void (^)(NSString*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDTTextReverseConversionGenerator_DEFINED__
