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

#import <StubReturn.h>

NSString* const NSLinguisticTagSchemeTokenType = @"NSLinguisticTagSchemeTokenType";
NSString* const NSLinguisticTagSchemeLexicalClass = @"NSLinguisticTagSchemeLexicalClass";
NSString* const NSLinguisticTagSchemeNameType = @"NSLinguisticTagSchemeNameType";
NSString* const NSLinguisticTagSchemeNameTypeOrLexicalClass = @"NSLinguisticTagSchemeNameTypeOrLexicalClass";
NSString* const NSLinguisticTagSchemeLemma = @"NSLinguisticTagSchemeLemma";
NSString* const NSLinguisticTagSchemeLanguage = @"NSLinguisticTagSchemeLanguage";
NSString* const NSLinguisticTagSchemeScript = @"NSLinguisticTagSchemeScript";
NSString* const NSLinguisticTagWord = @"NSLinguisticTagWord";
NSString* const NSLinguisticTagPunctuation = @"NSLinguisticTagPunctuation";
NSString* const NSLinguisticTagWhitespace = @"NSLinguisticTagWhitespace";
NSString* const NSLinguisticTagOther = @"NSLinguisticTagOther";
NSString* const NSLinguisticTagNoun = @"NSLinguisticTagNoun";
NSString* const NSLinguisticTagVerb = @"NSLinguisticTagVerb";
NSString* const NSLinguisticTagAdjective = @"NSLinguisticTagAdjective";
NSString* const NSLinguisticTagAdverb = @"NSLinguisticTagAdverb";
NSString* const NSLinguisticTagPronoun = @"NSLinguisticTagPronoun";
NSString* const NSLinguisticTagDeterminer = @"NSLinguisticTagDeterminer";
NSString* const NSLinguisticTagParticle = @"NSLinguisticTagParticle";
NSString* const NSLinguisticTagPreposition = @"NSLinguisticTagPreposition";
NSString* const NSLinguisticTagNumber = @"NSLinguisticTagNumber";
NSString* const NSLinguisticTagConjunction = @"NSLinguisticTagConjunction";
NSString* const NSLinguisticTagInterjection = @"NSLinguisticTagInterjection";
NSString* const NSLinguisticTagClassifier = @"NSLinguisticTagClassifier";
NSString* const NSLinguisticTagIdiom = @"NSLinguisticTagIdiom";
NSString* const NSLinguisticTagOtherWord = @"NSLinguisticTagOtherWord";
NSString* const NSLinguisticTagSentenceTerminator = @"NSLinguisticTagSentenceTerminator";
NSString* const NSLinguisticTagOpenQuote = @"NSLinguisticTagOpenQuote";
NSString* const NSLinguisticTagCloseQuote = @"NSLinguisticTagCloseQuote";
NSString* const NSLinguisticTagOpenParenthesis = @"NSLinguisticTagOpenParenthesis";
NSString* const NSLinguisticTagCloseParenthesis = @"NSLinguisticTagCloseParenthesis";
NSString* const NSLinguisticTagWordJoiner = @"NSLinguisticTagWordJoiner";
NSString* const NSLinguisticTagDash = @"NSLinguisticTagDash";
NSString* const NSLinguisticTagOtherPunctuation = @"NSLinguisticTagOtherPunctuation";
NSString* const NSLinguisticTagParagraphBreak = @"NSLinguisticTagParagraphBreak";
NSString* const NSLinguisticTagOtherWhitespace = @"NSLinguisticTagOtherWhitespace";
NSString* const NSLinguisticTagPersonalName = @"NSLinguisticTagPersonalName";
NSString* const NSLinguisticTagPlaceName = @"NSLinguisticTagPlaceName";
NSString* const NSLinguisticTagOrganizationName = @"NSLinguisticTagOrganizationName";

@implementation NSLinguisticTagger
/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithTagSchemes:(NSArray*)tagSchemes options:(NSUInteger)opts {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSArray*)availableTagSchemesForLanguage:(NSString*)language {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)stringEditedInRange:(NSRange)newCharRange changeInLength:(NSInteger)delta {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setOrthography:(NSOrthography*)orthography range:(NSRange)charRange {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (NSOrthography*)orthographyAtIndex:(NSUInteger)charIndex effectiveRange:(NSRangePointer)effectiveRange {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)enumerateTagsInRange:(NSRange)range
                      scheme:(NSString*)tagScheme
                     options:(NSLinguisticTaggerOptions)opts
                  usingBlock:(void (^)(NSString*, NSRange, NSRange, BOOL*))block {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)possibleTagsAtIndex:(NSUInteger)charIndex
                         scheme:(NSString*)tagScheme
                     tokenRange:(NSRangePointer)tokenRange
                  sentenceRange:(NSRangePointer)sentenceRange
                         scores:(NSArray* _Nullable*)scores {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSString*)tagAtIndex:(NSUInteger)charIndex
                 scheme:(NSString*)tagScheme
             tokenRange:(NSRangePointer)tokenRange
          sentenceRange:(NSRangePointer)sentenceRange {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)tagsInRange:(NSRange)range
                 scheme:(NSString*)tagScheme
                options:(NSLinguisticTaggerOptions)opts
            tokenRanges:(NSArray* _Nullable*)tokenRanges {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSRange)sentenceRangeForRange:(NSRange)charRange {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
