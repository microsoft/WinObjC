/* Copyright (c) 2008-2009 Christopher J. W. Lloyd

Permission is hereby granted,free of charge,to any person obtaining a copy of this software and associated documentation files (the
"Software"),to deal in the Software without restriction,including without limitation the rights to
use,copy,modify,merge,publish,distribute,sublicense,and/or sell copies of the Software,and to permit persons to whom the Software is
furnished to do so,subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS",WITHOUT WARRANTY OF ANY KIND,EXPRESS OR IMPLIED,INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY,FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM,DAMAGES OR OTHER LIABILITY,WHETHER IN AN ACTION OF CONTRACT,TORT OR OTHERWISE,ARISING FROM,OUT OF OR IN CONNECTION WITH THE SOFTWARE
OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

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

#ifndef _CFSTRING_H_
#define _CFSTRING_H_

#import <CoreFoundation/CFBase.h>
#import <CoreFoundation/CFArray.h>
#import <CoreFoundation/CFDictionary.h>
#import <CoreFoundation/CFLocale.h>
#import <CoreFoundation/CFData.h>
#import <CoreFoundation/CFCharacterSet.h>
#import <stdarg.h>
#import <stdint.h>

COREFOUNDATION_EXTERNC_BEGIN

ENABLE_IMPLICIT_BRIDGING

typedef CFOptionFlags CFStringCompareFlags;

typedef UInt32 CFStringEncoding;

#define kCFStringEncodingInvalidId (0xffffffffU)

enum {
    kCFCompareCaseInsensitive = (1 << 0),
    kCFCompareBackwards = (1 << 2),
    kCFCompareAnchored = (1 << 3),
    kCFCompareNonliteral = (1 << 4),
    kCFCompareLocalized = (1 << 5),
    kCFCompareNumerically = (1 << 6),
    kCFCompareDiacriticInsensitive = (1 << 7),
    kCFCompareWidthInsensitive = (1 << 8),
    kCFCompareForcedOrdering = (1 << 9),
};

typedef enum {
    kCFStringEncodingUTF8 = 0x08000100,
    kCFStringEncodingUTF16 = 0x00000100,
    kCFStringEncodingUTF16BE = 0x10000100,
    kCFStringEncodingUTF16LE = 0x14000100,
    kCFStringEncodingUTF32 = 0x0c000100,
    kCFStringEncodingUTF32BE = 0x18000100,
    kCFStringEncodingUTF32LE = 0x1c000100,
    kCFStringEncodingMacRoman = 0,
    kCFStringEncodingWindowsLatin1 = 0x0500,
    kCFStringEncodingISOLatin1 = 0x0201,
    kCFStringEncodingNextStepLatin = 0x0B01,
    kCFStringEncodingASCII = 0x0600,
    kCFStringEncodingUnicode = kCFStringEncodingUTF16,
    kCFStringEncodingNonLossyASCII = 0x0BFF,
} CFStringBuiltInEncodings;

typedef struct CFStringInlineBuffer { int nothing; } CFStringInlineBuffer;

typedef enum CFStringNormalizationForm {
    kCFStringNormalizationFormD = 0,
    kCFStringNormalizationFormKD = 1,
    kCFStringNormalizationFormC = 2,
    kCFStringNormalizationFormKC = 3
} CFStringNormalizationForm;

COREFOUNDATION_EXPORT const CFStringRef kCFStringTransformStripCombiningMarks;
COREFOUNDATION_EXPORT const CFStringRef kCFStringTransformToLatin;
COREFOUNDATION_EXPORT const CFStringRef kCFStringTransformFullwidthHalfwidth;
COREFOUNDATION_EXPORT const CFStringRef kCFStringTransformLatinKatakana;
COREFOUNDATION_EXPORT const CFStringRef kCFStringTransformLatinHiragana;
COREFOUNDATION_EXPORT const CFStringRef kCFStringTransformHiraganaKatakana;
COREFOUNDATION_EXPORT const CFStringRef kCFStringTransformMandarinLatin;
COREFOUNDATION_EXPORT const CFStringRef kCFStringTransformLatinHangul;
COREFOUNDATION_EXPORT const CFStringRef kCFStringTransformLatinArabic;
COREFOUNDATION_EXPORT const CFStringRef kCFStringTransformLatinHebrew;
COREFOUNDATION_EXPORT const CFStringRef kCFStringTransformLatinThai;
COREFOUNDATION_EXPORT const CFStringRef kCFStringTransformLatinCyrillic;
COREFOUNDATION_EXPORT const CFStringRef kCFStringTransformLatinGreek;
COREFOUNDATION_EXPORT const CFStringRef kCFStringTransformToXMLHex;
COREFOUNDATION_EXPORT const CFStringRef kCFStringTransformToUnicodeName;
COREFOUNDATION_EXPORT const CFStringRef kCFStringTransformStripDiacritics;

COREFOUNDATION_EXPORT CFTypeID CFStringGetTypeID(void);

COREFOUNDATION_EXPORT CFStringEncoding CFStringGetSystemEncoding(void);
COREFOUNDATION_EXPORT const CFStringEncoding* CFStringGetListOfAvailableEncodings(void);
COREFOUNDATION_EXPORT Boolean CFStringIsEncodingAvailable(CFStringEncoding encoding);
COREFOUNDATION_EXPORT CFStringRef CFStringGetNameOfEncoding(CFStringEncoding encoding);
COREFOUNDATION_EXPORT CFStringEncoding CFStringGetMostCompatibleMacStringEncoding(CFStringEncoding encoding);
COREFOUNDATION_EXPORT CFIndex CFStringGetMaximumSizeForEncoding(CFIndex length, CFStringEncoding encoding);

#ifdef __OBJC__
#define CFSTR(s) (CFStringRef)(@s)
#else
COREFOUNDATION_EXPORT CFStringRef CFStringMakeConstant(const char* cString);
#define CFSTR(s) CFStringMakeConstant(s)
#endif

COREFOUNDATION_EXPORT void CFStringAppendCharacters(CFMutableStringRef mutableString, const UniChar* chars, CFIndex numChars);

COREFOUNDATION_EXPORT CFStringRef CFStringCreateByCombiningStrings(CFAllocatorRef allocator, CFArrayRef array, CFStringRef separator);
COREFOUNDATION_EXPORT CFStringRef CFStringCreateCopy(CFAllocatorRef allocator, CFStringRef self);
COREFOUNDATION_EXPORT CFStringRef CFStringCreateMutableCopy(CFAllocatorRef allocator, CFIndex maxLength, CFStringRef self);
COREFOUNDATION_EXPORT CFStringRef CFStringCreateWithBytes(
    CFAllocatorRef allocator, const uint8_t* bytes, CFIndex length, CFStringEncoding encoding, Boolean isExternalRepresentation);
COREFOUNDATION_EXPORT CFStringRef CFStringCreateWithBytesNoCopy(CFAllocatorRef allocator,
                                                                const uint8_t* bytes,
                                                                CFIndex length,
                                                                CFStringEncoding encoding,
                                                                Boolean isExternalRepresentation,
                                                                CFAllocatorRef contentsDeallocator);
COREFOUNDATION_EXPORT CFStringRef CFStringCreateWithCharacters(CFAllocatorRef allocator, const UniChar* chars, CFIndex length);
COREFOUNDATION_EXPORT CFStringRef CFStringCreateWithCharactersNoCopy(CFAllocatorRef allocator,
                                                                     const UniChar* chars,
                                                                     CFIndex length,
                                                                     CFAllocatorRef contentsDeallocator);
COREFOUNDATION_EXPORT CFStringRef CFStringCreateWithCString(CFAllocatorRef allocator, const char* cString, CFStringEncoding encoding);
COREFOUNDATION_EXPORT CFStringRef CFStringCreateWithCStringNoCopy(CFAllocatorRef allocator,
                                                                  const char* cString,
                                                                  CFStringEncoding encoding,
                                                                  CFAllocatorRef contentsDeallocator);
COREFOUNDATION_EXPORT CFStringRef CFStringCreateWithFileSystemRepresentation(CFAllocatorRef allocator, const char* buffer);
COREFOUNDATION_EXPORT CFStringRef CFStringCreateWithFormat(CFAllocatorRef allocator,
                                                           CFDictionaryRef formatOptions,
                                                           CFStringRef format,
                                                           ...);
COREFOUNDATION_EXPORT CFStringRef CFStringCreateWithFormatAndArguments(CFAllocatorRef allocator,
                                                                       CFDictionaryRef formatOptions,
                                                                       CFStringRef format,
                                                                       va_list arguments);
COREFOUNDATION_EXPORT CFStringRef CFStringCreateFromExternalRepresentation(CFAllocatorRef allocator,
                                                                           CFDataRef data,
                                                                           CFStringEncoding encoding);

COREFOUNDATION_EXPORT CFStringRef CFStringCreateWithSubstring(CFAllocatorRef allocator, CFStringRef self, CFRange range);

COREFOUNDATION_EXPORT void CFShow(CFTypeRef self);
COREFOUNDATION_EXPORT void CFShowStr(CFStringRef self);

COREFOUNDATION_EXPORT CFComparisonResult CFStringCompare(CFStringRef self, CFStringRef other, CFOptionFlags options);
COREFOUNDATION_EXPORT CFComparisonResult CFStringCompareWithOptions(CFStringRef self,
                                                                    CFStringRef other,
                                                                    CFRange rangeToCompare,
                                                                    CFOptionFlags options);
COREFOUNDATION_EXPORT CFComparisonResult
CFStringCompareWithOptionsAndLocale(CFStringRef self, CFStringRef other, CFRange rangeToCompare, CFOptionFlags options, CFLocaleRef locale);

COREFOUNDATION_EXPORT CFStringRef CFStringConvertEncodingToIANACharSetName(CFStringEncoding encoding);
COREFOUNDATION_EXPORT UInt32 CFStringConvertEncodingToNSStringEncoding(CFStringEncoding encoding);
COREFOUNDATION_EXPORT UInt32 CFStringConvertEncodingToWindowsCodepage(CFStringEncoding encoding);

COREFOUNDATION_EXPORT CFStringEncoding CFStringConvertIANACharSetNameToEncoding(CFStringRef self);
COREFOUNDATION_EXPORT CFStringEncoding CFStringConvertNSStringEncodingToEncoding(UInt32 encoding);
COREFOUNDATION_EXPORT CFStringEncoding CFStringConvertWindowsCodepageToEncoding(UInt32 codepage);
COREFOUNDATION_EXPORT CFArrayRef CFStringCreateArrayBySeparatingStrings(CFAllocatorRef allocator,
                                                                        CFStringRef self,
                                                                        CFStringRef separatorString);
COREFOUNDATION_EXPORT CFArrayRef CFStringCreateArrayWithFindResults(
    CFAllocatorRef allocator, CFStringRef self, CFStringRef stringToFind, CFRange range, CFOptionFlags options);
COREFOUNDATION_EXPORT CFDataRef CFStringCreateExternalRepresentation(CFAllocatorRef allocator,
                                                                     CFStringRef self,
                                                                     CFStringEncoding encoding,
                                                                     uint8_t lossByte);
COREFOUNDATION_EXPORT void CFStringDelete(CFMutableStringRef theString, CFRange range);

COREFOUNDATION_EXPORT Boolean CFStringHasPrefix(CFStringRef self, CFStringRef prefix);
COREFOUNDATION_EXPORT Boolean CFStringHasSuffix(CFStringRef self, CFStringRef suffix);
COREFOUNDATION_EXPORT CFRange CFStringFind(CFStringRef self, CFStringRef stringToFind, CFOptionFlags options);
COREFOUNDATION_EXPORT Boolean
CFStringFindCharacterFromSet(CFStringRef self, CFCharacterSetRef set, CFRange range, CFOptionFlags options, CFRange* result);
COREFOUNDATION_EXPORT Boolean
CFStringFindWithOptions(CFStringRef self, CFStringRef stringToFind, CFRange range, CFOptionFlags options, CFRange* result);
COREFOUNDATION_EXPORT Boolean CFStringFindWithOptionsAndLocale(
    CFStringRef self, CFStringRef stringToFind, CFRange range, CFOptionFlags options, CFLocaleRef locale, CFRange* result);
COREFOUNDATION_EXPORT CFIndex CFStringGetBytes(CFStringRef self,
                                               CFRange range,
                                               CFStringEncoding encoding,
                                               uint8_t lossByte,
                                               Boolean isExternalRepresentation,
                                               uint8_t* bytes,
                                               CFIndex length,
                                               CFIndex* resultLength);

COREFOUNDATION_EXPORT CFIndex CFStringGetLength(CFStringRef self);
COREFOUNDATION_EXPORT UniChar CFStringGetCharacterAtIndex(CFStringRef self, CFIndex index);

COREFOUNDATION_EXPORT void CFStringGetCharacters(CFStringRef self, CFRange range, UniChar* buffer);
COREFOUNDATION_EXPORT const UniChar* CFStringGetCharactersPtr(CFStringRef self);

COREFOUNDATION_EXPORT Boolean CFStringGetCString(CFStringRef self, char* buffer, CFIndex bufferSize, CFStringEncoding encoding);
COREFOUNDATION_EXPORT const char* CFStringGetCStringPtr(CFStringRef self, CFStringEncoding encoding);

COREFOUNDATION_EXPORT void CFStringInitInlineBuffer(CFStringRef self, CFStringInlineBuffer* buffer, CFRange range);
COREFOUNDATION_EXPORT void CFStringInsert(CFMutableStringRef str, CFIndex idx, CFStringRef insertedStr);
COREFOUNDATION_EXPORT UniChar CFStringGetCharacterFromInlineBuffer(CFStringInlineBuffer* buffer, CFIndex index);

COREFOUNDATION_EXPORT SInt32 CFStringGetIntValue(CFStringRef self);
COREFOUNDATION_EXPORT double CFStringGetDoubleValue(CFStringRef self);
COREFOUNDATION_EXPORT CFStringEncoding CFStringGetFastestEncoding(CFStringRef self);
COREFOUNDATION_EXPORT CFStringEncoding CFStringGetSmallestEncoding(CFStringRef self);

COREFOUNDATION_EXPORT CFIndex CFStringGetMaximumSizeOfFileSystemRepresentation(CFStringRef self);
COREFOUNDATION_EXPORT Boolean CFStringGetFileSystemRepresentation(CFStringRef self, char* buffer, CFIndex bufferCapacity);

COREFOUNDATION_EXPORT void CFStringGetLineBounds(
    CFStringRef self, CFRange range, CFIndex* beginIndex, CFIndex* endIndex, CFIndex* contentsEndIndex);
COREFOUNDATION_EXPORT void CFStringGetParagraphBounds(
    CFStringRef self, CFRange range, CFIndex* beginIndex, CFIndex* endIndex, CFIndex* contentsEndIndex);
COREFOUNDATION_EXPORT CFRange CFStringGetRangeOfComposedCharactersAtIndex(CFStringRef self, CFIndex index);

COREFOUNDATION_EXPORT void CFStringTrimWhitespace(CFMutableStringRef theString);

COREFOUNDATION_EXPORT CFMutableStringRef CFStringCreateMutable(CFAllocatorRef alloc, CFIndex maxLength);
COREFOUNDATION_EXPORT void CFStringAppendFormat(CFMutableStringRef theString, CFDictionaryRef formatOptions, CFStringRef format, ...);
COREFOUNDATION_EXPORT void CFStringLowercase(CFMutableStringRef theString, CFLocaleRef locale);

COREFOUNDATION_EXPORT CFMutableStringRef CFStringCreateMutableWithExternalCharactersNoCopy(
    CFAllocatorRef alloc, UniChar* chars, CFIndex numChars, CFIndex capacity, CFAllocatorRef externalCharactersAllocator);
COREFOUNDATION_EXPORT void CFStringSetExternalCharactersNoCopy(CFMutableStringRef theString,
                                                               UniChar* chars,
                                                               CFIndex length,
                                                               CFIndex capacity);
COREFOUNDATION_EXPORT void CFStringAppend(CFMutableStringRef theString, CFStringRef appendedString);

COREFOUNDATION_EXPORT Boolean CFStringIsSurrogateHighCharacter(UniChar character);
COREFOUNDATION_EXPORT Boolean CFStringIsSurrogateLowCharacter(UniChar character);

COREFOUNDATION_EXPORT void CFStringNormalize(CFMutableStringRef theString, CFStringNormalizationForm theForm);

COREFOUNDATION_EXPORT void CFStringReplace(CFMutableStringRef theString, CFRange range, CFStringRef replacement);

COREFOUNDATION_EXPORT Boolean CFStringTransform(CFMutableStringRef string, CFRange* range, CFStringRef transform, Boolean reverse);

#ifdef CFSTR
#undef CFSTR
#endif
#define CFSTR(str) ((CFStringRef)__builtin___CFStringMakeConstantString("" str ""))

DISABLE_IMPLICIT_BRIDGING

COREFOUNDATION_EXTERNC_END

#endif /* _CFSTRING_H_ */