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
#import <Foundation/NSRange.h>

@class NSString;
@class NSArray;
@class NSOrthography;

typedef NSUInteger NSLinguisticTaggerOptions;
enum {
    NSLinguisticTaggerOmitWords = 1 << 0,
    NSLinguisticTaggerOmitPunctuation = 1 << 1,
    NSLinguisticTaggerOmitWhitespace = 1 << 2,
    NSLinguisticTaggerOmitOther = 1 << 3,
    NSLinguisticTaggerJoinNames = 1 << 4
};

FOUNDATION_EXPORT NSString* const NSLinguisticTagSchemeTokenType;
FOUNDATION_EXPORT NSString* const NSLinguisticTagSchemeLexicalClass;
FOUNDATION_EXPORT NSString* const NSLinguisticTagSchemeNameType;
FOUNDATION_EXPORT NSString* const NSLinguisticTagSchemeNameTypeOrLexicalClass;
FOUNDATION_EXPORT NSString* const NSLinguisticTagSchemeLemma;
FOUNDATION_EXPORT NSString* const NSLinguisticTagSchemeLanguage;
FOUNDATION_EXPORT NSString* const NSLinguisticTagSchemeScript;
FOUNDATION_EXPORT NSString* const NSLinguisticTagWord;
FOUNDATION_EXPORT NSString* const NSLinguisticTagPunctuation;
FOUNDATION_EXPORT NSString* const NSLinguisticTagWhitespace;
FOUNDATION_EXPORT NSString* const NSLinguisticTagOther;
FOUNDATION_EXPORT NSString* const NSLinguisticTagNoun;
FOUNDATION_EXPORT NSString* const NSLinguisticTagVerb;
FOUNDATION_EXPORT NSString* const NSLinguisticTagAdjective;
FOUNDATION_EXPORT NSString* const NSLinguisticTagAdverb;
FOUNDATION_EXPORT NSString* const NSLinguisticTagPronoun;
FOUNDATION_EXPORT NSString* const NSLinguisticTagDeterminer;
FOUNDATION_EXPORT NSString* const NSLinguisticTagParticle;
FOUNDATION_EXPORT NSString* const NSLinguisticTagPreposition;
FOUNDATION_EXPORT NSString* const NSLinguisticTagNumber;
FOUNDATION_EXPORT NSString* const NSLinguisticTagConjunction;
FOUNDATION_EXPORT NSString* const NSLinguisticTagInterjection;
FOUNDATION_EXPORT NSString* const NSLinguisticTagClassifier;
FOUNDATION_EXPORT NSString* const NSLinguisticTagIdiom;
FOUNDATION_EXPORT NSString* const NSLinguisticTagOtherWord;
FOUNDATION_EXPORT NSString* const NSLinguisticTagSentenceTerminator;
FOUNDATION_EXPORT NSString* const NSLinguisticTagOpenQuote;
FOUNDATION_EXPORT NSString* const NSLinguisticTagCloseQuote;
FOUNDATION_EXPORT NSString* const NSLinguisticTagOpenParenthesis;
FOUNDATION_EXPORT NSString* const NSLinguisticTagCloseParenthesis;
FOUNDATION_EXPORT NSString* const NSLinguisticTagWordJoiner;
FOUNDATION_EXPORT NSString* const NSLinguisticTagDash;
FOUNDATION_EXPORT NSString* const NSLinguisticTagOtherPunctuation;
FOUNDATION_EXPORT NSString* const NSLinguisticTagParagraphBreak;
FOUNDATION_EXPORT NSString* const NSLinguisticTagOtherWhitespace;
FOUNDATION_EXPORT NSString* const NSLinguisticTagPersonalName;
FOUNDATION_EXPORT NSString* const NSLinguisticTagPlaceName;
FOUNDATION_EXPORT NSString* const NSLinguisticTagOrganizationName;

FOUNDATION_EXPORT_CLASS
@interface NSLinguisticTagger : NSObject
- (instancetype)initWithTagSchemes:(NSArray*)tagSchemes options:(NSUInteger)opts STUB_METHOD;
@property (readonly, copy) NSArray* tagSchemes STUB_PROPERTY;
+ (NSArray*)availableTagSchemesForLanguage:(NSString*)language STUB_METHOD;
@property (retain) NSString* string STUB_PROPERTY;
- (void)stringEditedInRange:(NSRange)newCharRange changeInLength:(NSInteger)delta STUB_METHOD;
- (void)setOrthography:(NSOrthography*)orthography range:(NSRange)charRange STUB_METHOD;
- (NSOrthography*)orthographyAtIndex:(NSUInteger)charIndex effectiveRange:(NSRangePointer)effectiveRange STUB_METHOD;
- (void)enumerateTagsInRange:(NSRange)range
                      scheme:(NSString*)tagScheme
                     options:(NSLinguisticTaggerOptions)opts
                  usingBlock:(void (^)(NSString*, NSRange, NSRange, BOOL*))block STUB_METHOD;
- (NSArray*)possibleTagsAtIndex:(NSUInteger)charIndex
                         scheme:(NSString*)tagScheme
                     tokenRange:(NSRangePointer)tokenRange
                  sentenceRange:(NSRangePointer)sentenceRange
                         scores:(NSArray* _Nullable*)scores STUB_METHOD;
- (NSString*)tagAtIndex:(NSUInteger)charIndex
                 scheme:(NSString*)tagScheme
             tokenRange:(NSRangePointer)tokenRange
          sentenceRange:(NSRangePointer)sentenceRange STUB_METHOD;
- (NSArray*)tagsInRange:(NSRange)range
                 scheme:(NSString*)tagScheme
                options:(NSLinguisticTaggerOptions)opts
            tokenRanges:(NSArray* _Nullable*)tokenRanges STUB_METHOD;
- (NSRange)sentenceRangeForRange:(NSRange)charRange STUB_METHOD;
@end
