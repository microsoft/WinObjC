//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import <CoreText/CoreTextExport.h>
#import <CoreText/CTLine.h>

#import <CoreFoundation/CFAttributedString.h>
#import <CoreFoundation/CFDictionary.h>
#import <CoreFoundation/CFString.h>

typedef const struct __CTTypesetter* CTTypesetterRef;

CORETEXT_EXPORT const CFStringRef kCTTypesetterOptionDisableBidiProcessing;
CORETEXT_EXPORT const CFStringRef kCTTypesetterOptionForcedEmbeddingLevel;

CORETEXT_EXPORT CTTypesetterRef CTTypesetterCreateWithAttributedString(CFAttributedStringRef string);
CORETEXT_EXPORT CTTypesetterRef CTTypesetterCreateWithAttributedStringAndOptions(CFAttributedStringRef string,
                                                                                 CFDictionaryRef options) STUB_METHOD;
CORETEXT_EXPORT CTLineRef CTTypesetterCreateLine(CTTypesetterRef typesetter, CFRange stringRange);
CORETEXT_EXPORT CTLineRef CTTypesetterCreateLineWithOffset(CTTypesetterRef typesetter, CFRange stringRange, double offset);
CORETEXT_EXPORT CFIndex CTTypesetterSuggestLineBreak(CTTypesetterRef typesetter, CFIndex startIndex, double width);
CORETEXT_EXPORT CFIndex CTTypesetterSuggestLineBreakWithOffset(CTTypesetterRef typesetter, CFIndex startIndex, double width, double offset);
CORETEXT_EXPORT CFIndex CTTypesetterSuggestClusterBreak(CTTypesetterRef typesetter, CFIndex startIndex, double width) STUB_METHOD;
CORETEXT_EXPORT CFIndex CTTypesetterSuggestClusterBreakWithOffset(CTTypesetterRef typesetter,
                                                                  CFIndex startIndex,
                                                                  double width,
                                                                  double offset) STUB_METHOD;
CORETEXT_EXPORT CFTypeID CTTypesetterGetTypeID() STUB_METHOD;
