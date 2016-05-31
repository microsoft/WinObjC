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

#import <CoreText/CoreTextExport.h>
#import <CoreText/CTFontDescriptor.h>

#import <CoreFoundation/CFArray.h>
#import <CoreFoundation/CFDictionary.h>
#import <CoreFoundation/CFString.h>

typedef const struct __CTFontCollection* CTFontCollectionRef;
typedef CFComparisonResult (*CTFontCollectionSortDescriptorsCallback)(CTFontDescriptorRef first, CTFontDescriptorRef second, void* refCon);
typedef struct __CTFontCollection* CTMutableFontCollectionRef;
typedef uint32_t CTFontCollectionCopyOptions;
enum { kCTFontCollectionCopyDefaultOptions = 0, kCTFontCollectionCopyUnique = (1L << 0), kCTFontCollectionCopyStandardSort = (1L << 1) };

CORETEXT_EXPORT const CFStringRef kCTFontCollectionRemoveDuplicatesOption;

CORETEXT_EXPORT CTFontCollectionRef CTFontCollectionCreateFromAvailableFonts(CFDictionaryRef options) STUB_METHOD;
CORETEXT_EXPORT CTFontCollectionRef CTFontCollectionCreateWithFontDescriptors(CFArrayRef queryDescriptors,
                                                                              CFDictionaryRef options) STUB_METHOD;
CORETEXT_EXPORT CTFontCollectionRef CTFontCollectionCreateCopyWithFontDescriptors(CTFontCollectionRef original,
                                                                                  CFArrayRef queryDescriptors,
                                                                                  CFDictionaryRef options) STUB_METHOD;
CORETEXT_EXPORT CFArrayRef CTFontCollectionCreateMatchingFontDescriptors(CTFontCollectionRef collection) STUB_METHOD;
CORETEXT_EXPORT CFArrayRef CTFontCollectionCreateMatchingFontDescriptorsSortedWithCallback(
    CTFontCollectionRef collection, CTFontCollectionSortDescriptorsCallback sortCallback, void* refCon) STUB_METHOD;
CORETEXT_EXPORT CFTypeID CTFontCollectionGetTypeID() STUB_METHOD;
