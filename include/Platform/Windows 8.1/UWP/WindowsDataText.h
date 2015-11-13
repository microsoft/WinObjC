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
    WDTSelectableWordsSegmenter;
@class WDTTextSegment;
@protocol WDTISemanticTextQueryFactory
, WDTISemanticTextQuery, WDTIUnicodeCharactersStatics, WDTIAlternateWordForm, WDTISelectableWordSegment, WDTIWordSegment,
    WDTIWordsSegmenter, WDTIWordsSegmenterFactory, WDTISelectableWordsSegmenter, WDTISelectableWordsSegmenterFactory;

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

#include "WindowsFoundationCollections.h"
// Windows.Data.Text.SelectableWordSegmentsTokenizingHandler
#ifndef __WDTSelectableWordSegmentsTokenizingHandler__DEFINED
#define __WDTSelectableWordSegmentsTokenizingHandler__DEFINED
typedef void (^WDTSelectableWordSegmentsTokenizingHandler)(id<NSFastEnumeration> /*WDTSelectableWordSegment*/ precedingWords,
                                                           id<NSFastEnumeration> /*WDTSelectableWordSegment*/ words);
#endif // __WDTSelectableWordSegmentsTokenizingHandler__DEFINED

// Windows.Data.Text.WordSegmentsTokenizingHandler
#ifndef __WDTWordSegmentsTokenizingHandler__DEFINED
#define __WDTWordSegmentsTokenizingHandler__DEFINED
typedef void (^WDTWordSegmentsTokenizingHandler)(id<NSFastEnumeration> /*WDTWordSegment*/ precedingWords,
                                                 id<NSFastEnumeration> /*WDTWordSegment*/ words);
#endif // __WDTWordSegmentsTokenizingHandler__DEFINED

#import <Foundation/Foundation.h>

// [struct] Windows.Data.Text.TextSegment
WINRT_EXPORT
@interface WDTTextSegment : NSObject
+ (instancetype) new;
@property unsigned startPosition;
@property unsigned length;
@end

// Windows.Data.Text.WordSegmentsTokenizingHandler
#ifndef __WDTWordSegmentsTokenizingHandler__DEFINED
#define __WDTWordSegmentsTokenizingHandler__DEFINED
typedef void (^WDTWordSegmentsTokenizingHandler)(id<NSFastEnumeration> /*WDTWordSegment*/ precedingWords,
                                                 id<NSFastEnumeration> /*WDTWordSegment*/ words);
#endif // __WDTWordSegmentsTokenizingHandler__DEFINED

// Windows.Data.Text.SelectableWordSegmentsTokenizingHandler
#ifndef __WDTSelectableWordSegmentsTokenizingHandler__DEFINED
#define __WDTSelectableWordSegmentsTokenizingHandler__DEFINED
typedef void (^WDTSelectableWordSegmentsTokenizingHandler)(id<NSFastEnumeration> /*WDTSelectableWordSegment*/ precedingWords,
                                                           id<NSFastEnumeration> /*WDTSelectableWordSegment*/ words);
#endif // __WDTSelectableWordSegmentsTokenizingHandler__DEFINED

// Windows.Data.Text.SemanticTextQuery
#ifndef __WDTSemanticTextQuery_DEFINED__
#define __WDTSemanticTextQuery_DEFINED__

WINRT_EXPORT
@interface WDTSemanticTextQuery : RTObject
+ (WDTSemanticTextQuery*)create:(NSString*)aqsFilter ACTIVATOR;
+ (WDTSemanticTextQuery*)createWithLanguage:(NSString*)aqsFilter filterLanguage:(NSString*)filterLanguage ACTIVATOR;
- (id<NSFastEnumeration> /*WDTTextSegment*/)find:(NSString*)content;
- (id<NSFastEnumeration> /*WDTTextSegment*/)findInProperty:(NSString*)propertyContent propertyName:(NSString*)propertyName;
@end

#endif // __WDTSemanticTextQuery_DEFINED__

// Windows.Data.Text.UnicodeCharacters
#ifndef __WDTUnicodeCharacters_DEFINED__
#define __WDTUnicodeCharacters_DEFINED__

WINRT_EXPORT
@interface WDTUnicodeCharacters : RTObject
+ (unsigned)getCodepointFromSurrogatePair:(unsigned)highSurrogate lowSurrogate:(unsigned)lowSurrogate;
+ (void)getSurrogatePairFromCodepoint:(unsigned)codepoint highSurrogate:(WCHAR*)highSurrogate lowSurrogate:(WCHAR*)lowSurrogate;
+ (BOOL)isHighSurrogate:(unsigned)codepoint;
+ (BOOL)isLowSurrogate:(unsigned)codepoint;
+ (BOOL)isSupplementary:(unsigned)codepoint;
+ (BOOL)isNoncharacter:(unsigned)codepoint;
+ (BOOL)isWhitespace:(unsigned)codepoint;
+ (BOOL)isAlphabetic:(unsigned)codepoint;
+ (BOOL)isCased:(unsigned)codepoint;
+ (BOOL)isUppercase:(unsigned)codepoint;
+ (BOOL)isLowercase:(unsigned)codepoint;
+ (BOOL)isIdStart:(unsigned)codepoint;
+ (BOOL)isIdContinue:(unsigned)codepoint;
+ (BOOL)isGraphemeBase:(unsigned)codepoint;
+ (BOOL)isGraphemeExtend:(unsigned)codepoint;
+ (WDTUnicodeNumericType)getNumericType:(unsigned)codepoint;
+ (WDTUnicodeGeneralCategory)getGeneralCategory:(unsigned)codepoint;
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
@property (readonly) id<NSFastEnumeration> /*WDTAlternateWordForm*/ alternateForms;
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
- (WDTWordSegment*)getTokenAt:(NSString*)text startIndex:(unsigned)startIndex;
- (id<NSFastEnumeration> /*WDTWordSegment*/)getTokens:(NSString*)text;
- (void)tokenize:(NSString*)text startIndex:(unsigned)startIndex handler:(WDTWordSegmentsTokenizingHandler)handler;
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
- (WDTSelectableWordSegment*)getTokenAt:(NSString*)text startIndex:(unsigned)startIndex;
- (id<NSFastEnumeration> /*WDTSelectableWordSegment*/)getTokens:(NSString*)text;
- (void)tokenize:(NSString*)text startIndex:(unsigned)startIndex handler:(WDTSelectableWordSegmentsTokenizingHandler)handler;
@end

#endif // __WDTSelectableWordsSegmenter_DEFINED__
