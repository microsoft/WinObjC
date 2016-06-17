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

#ifndef _CFSTRINGTOKENIZER_H_
#define _CFSTRINGTOKENIZER_H_

#import <CoreFoundation/CFBase.h>
#import <CoreFoundation/CFLocale.h>

CF_EXTERN_C_BEGIN

typedef struct CFStringTokenizer* CFStringTokenizerRef;

typedef CFOptionFlags CFStringTokenizerTokenType;

/**
@Status Interoperable
*/
CF_EXPORT CFTypeID CFStringTokenizerGetTypeID(void);

/**
@Status Stub
@Notes
*/
CF_EXPORT CFOptionFlags CFStringTokenizerGetSupportedOptionsForLanguage(CFStringRef language);

/**
@Status Caveat
@Notes Supports the following CFOptionFlags: kCFStringTokenizerUnitSentence,
kCFStringTokenizerUnitWordBoundary,kCFStringTokenizerUnitLineBreak
*/
CF_EXPORT CFStringTokenizerRef
CFStringTokenizerCreate(CFAllocatorRef allocator, CFStringRef string, CFRange range, CFOptionFlags options, CFLocaleRef locale);

/**
@Status Caveat
@Notes Only supports kCFStringTokenizerTokenNormal.
*/
CF_EXPORT CFStringTokenizerTokenType CFStringTokenizerAdvanceToNextToken(CFStringTokenizerRef self);

/**
@Status Stub
@Notes
*/
CF_EXPORT CFStringRef CFStringTokenizerCopyBestStringLanguage(CFStringRef string, CFRange range);

/**
@Status Stub
@Notes
*/
CF_EXPORT CFTypeRef CFStringTokenizerCopyCurrentTokenAttribute(CFStringTokenizerRef self, CFOptionFlags attribute);

/**
@Status Stub
@Notes
*/
CF_EXPORT CFIndex CFStringTokenizerGetCurrentSubTokens(CFStringTokenizerRef self,
                                                       CFRange* ranges,
                                                       CFIndex maxRangeLength,
                                                       CFMutableArrayRef subTokens);
/**
@Status Interoperable
*/
CF_EXPORT CFRange CFStringTokenizerGetCurrentTokenRange(CFStringTokenizerRef self);

/**
@Status Caveat
@Notes Only supports kCFStringTokenizerTokenNormal.
*/
CF_EXPORT CFStringTokenizerTokenType CFStringTokenizerGoToTokenAtIndex(CFStringTokenizerRef self, CFIndex index);

/**
@Status Interoperable
*/
CF_EXPORT void CFStringTokenizerSetString(CFStringTokenizerRef self, CFStringRef string, CFRange range);

enum {
    kCFStringTokenizerUnitWord = 0,
    kCFStringTokenizerUnitSentence = 1,
    kCFStringTokenizerUnitParagraph = 2,
    kCFStringTokenizerUnitLineBreak = 3,
    kCFStringTokenizerUnitWordBoundary = 4,
    kCFStringTokenizerAttributeLatinTranscription = 1L << 16,
    kCFStringTokenizerAttributeLanguage = 1L << 17
};

enum {
    kCFStringTokenizerTokenNone = 0,
    kCFStringTokenizerTokenNormal = 1,
    kCFStringTokenizerTokenHasSubTokensMask = 1L << 1,
    kCFStringTokenizerTokenHasDerivedSubTokensMask = 1L << 2,
    kCFStringTokenizerTokenHasHasNumbersMask = 1L << 3,
    kCFStringTokenizerTokenHasNonLettersMask = 1L << 4,
    kCFStringTokenizerTokenIsCJWordMask = 1L << 5
};

CF_EXTERN_C_END

#endif /* _CFSTRINGTOKENIZER_H_ */