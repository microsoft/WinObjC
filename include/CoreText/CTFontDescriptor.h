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

#include <stdint.h>

#import <CoreText/CoreTextExport.h>
#import <CoreFoundation/CFArray.h>
#import <CoreFoundation/CFDictionary.h>
#import <CoreFoundation/CFNumber.h>
#import <CoreFoundation/CFSet.h>
#import <CoreFoundation/CFString.h>
#import <CoreGraphics/CGBase.h>

typedef const struct __CTFontDescriptor* CTFontDescriptorRef;
typedef uint32_t CTFontOrientation;
typedef uint32_t CTFontFormat;
typedef uint32_t CTFontPriority;
typedef uint32_t CTFontSymbolicTraits;
typedef uint32_t CTFontStylisticClass;

enum { kCTFontDefaultOrientation = 0, kCTFontHorizontalOrientation = 1, kCTFontVerticalOrientation = 2 };
enum {
    kCTFontFormatUnrecognized = 0,
    kCTFontFormatOpenTypePostScript = 1,
    kCTFontFormatOpenTypeTrueType = 2,
    kCTFontFormatTrueType = 3,
    kCTFontFormatPostScript = 4,
    kCTFontFormatBitmap = 5
};
enum {
    kCTFontPrioritySystem = 10000,
    kCTFontPriorityNetwork = 20000,
    kCTFontPriorityComputer = 30000,
    kCTFontPriorityUser = 40000,
    kCTFontPriorityDynamic = 50000,
    kCTFontPriorityProcess = 60000
};
enum { kCTFontClassMaskShift = 28 };
enum {
    kCTFontItalicTrait = (1 << 0),
    kCTFontBoldTrait = (1 << 1),
    kCTFontExpandedTrait = (1 << 5),
    kCTFontCondensedTrait = (1 << 6),
    kCTFontMonoSpaceTrait = (1 << 10),
    kCTFontVerticalTrait = (1 << 11),
    kCTFontUIOptimizedTrait = (1 << 12),
    kCTFontClassMaskTrait = (15 << kCTFontClassMaskShift),

    kCTFontTraitItalic = kCTFontItalicTrait,
    kCTFontTraitBold = kCTFontBoldTrait,
    kCTFontTraitExpanded = kCTFontExpandedTrait,
    kCTFontTraitCondensed = kCTFontCondensedTrait,
    kCTFontTraitMonoSpace = kCTFontMonoSpaceTrait,
    kCTFontTraitVertical = kCTFontVerticalTrait,
    kCTFontTraitUIOptimized = kCTFontUIOptimizedTrait,
    kCTFontTraitClassMask = kCTFontClassMaskTrait,
};
enum {
    kCTFontUnknownClass = (0 << kCTFontClassMaskShift),
    kCTFontOldStyleSerifsClass = (1 << kCTFontClassMaskShift),
    kCTFontTransitionalSerifsClass = (2 << kCTFontClassMaskShift),
    kCTFontModernSerifsClass = (3 << kCTFontClassMaskShift),
    kCTFontClarendonSerifsClass = (4 << kCTFontClassMaskShift),
    kCTFontSlabSerifsClass = (5 << kCTFontClassMaskShift),
    kCTFontFreeformSerifsClass = (7 << kCTFontClassMaskShift),
    kCTFontSansSerifClass = (8 << kCTFontClassMaskShift),
    kCTFontOrnamentalsClass = (9 << kCTFontClassMaskShift),
    kCTFontScriptsClass = (10 << kCTFontClassMaskShift),
    kCTFontSymbolicClass = (12 << kCTFontClassMaskShift)
};

CORETEXT_EXPORT const CFStringRef kCTFontURLAttribute;
CORETEXT_EXPORT const CFStringRef kCTFontNameAttribute;
CORETEXT_EXPORT const CFStringRef kCTFontDisplayNameAttribute;
CORETEXT_EXPORT const CFStringRef kCTFontFamilyNameAttribute;
CORETEXT_EXPORT const CFStringRef kCTFontStyleNameAttribute;
CORETEXT_EXPORT const CFStringRef kCTFontTraitsAttribute;
CORETEXT_EXPORT const CFStringRef kCTFontVariationAttribute;
CORETEXT_EXPORT const CFStringRef kCTFontSizeAttribute;
CORETEXT_EXPORT const CFStringRef kCTFontMatrixAttribute;
CORETEXT_EXPORT const CFStringRef kCTFontCascadeListAttribute;
CORETEXT_EXPORT const CFStringRef kCTFontCharacterSetAttribute;
CORETEXT_EXPORT const CFStringRef kCTFontLanguagesAttribute;
CORETEXT_EXPORT const CFStringRef kCTFontBaselineAdjustAttribute;
CORETEXT_EXPORT const CFStringRef kCTFontMacintoshEncodingsAttribute;
CORETEXT_EXPORT const CFStringRef kCTFontFeaturesAttribute;
CORETEXT_EXPORT const CFStringRef kCTFontFeatureSettingsAttribute;
CORETEXT_EXPORT const CFStringRef kCTFontFixedAdvanceAttribute;
CORETEXT_EXPORT const CFStringRef kCTFontOrientationAttribute;
CORETEXT_EXPORT const CFStringRef kCTFontFormatAttribute;
CORETEXT_EXPORT const CFStringRef kCTFontRegistrationScopeAttribute;
CORETEXT_EXPORT const CFStringRef kCTFontPriorityAttribute;
CORETEXT_EXPORT const CFStringRef kCTFontEnabledAttribute;
CORETEXT_EXPORT const CFStringRef kCTFontSymbolicTrait;
CORETEXT_EXPORT const CFStringRef kCTFontWeightTrait;
CORETEXT_EXPORT const CFStringRef kCTFontWidthTrait;
CORETEXT_EXPORT const CFStringRef kCTFontSlantTrait;

CORETEXT_EXPORT CTFontDescriptorRef CTFontDescriptorCreateWithNameAndSize(CFStringRef name, CGFloat size) STUB_METHOD;
CORETEXT_EXPORT CTFontDescriptorRef CTFontDescriptorCreateWithAttributes(CFDictionaryRef attributes);
CORETEXT_EXPORT CTFontDescriptorRef CTFontDescriptorCreateCopyWithAttributes(CTFontDescriptorRef original,
                                                                             CFDictionaryRef attributes) STUB_METHOD;
CORETEXT_EXPORT CTFontDescriptorRef CTFontDescriptorCreateCopyWithVariation(CTFontDescriptorRef original,
                                                                            CFNumberRef variationIdentifier,
                                                                            CGFloat variationValue) STUB_METHOD;
CORETEXT_EXPORT CTFontDescriptorRef CTFontDescriptorCreateCopyWithFeature(CTFontDescriptorRef original,
                                                                          CFNumberRef featureTypeIdentifier,
                                                                          CFNumberRef featureSelectorIdentifier) STUB_METHOD;
CORETEXT_EXPORT CFArrayRef CTFontDescriptorCreateMatchingFontDescriptors(CTFontDescriptorRef descriptor,
                                                                         CFSetRef mandatoryAttributes) STUB_METHOD;
CORETEXT_EXPORT CTFontDescriptorRef CTFontDescriptorCreateMatchingFontDescriptor(CTFontDescriptorRef descriptor,
                                                                                 CFSetRef mandatoryAttributes) STUB_METHOD;
CORETEXT_EXPORT CFDictionaryRef CTFontDescriptorCopyAttributes(CTFontDescriptorRef descriptor) STUB_METHOD;
CORETEXT_EXPORT CFTypeRef CTFontDescriptorCopyAttribute(CTFontDescriptorRef descriptor, CFStringRef attribute) STUB_METHOD;
CORETEXT_EXPORT CFTypeRef CTFontDescriptorCopyLocalizedAttribute(CTFontDescriptorRef descriptor,
                                                                 CFStringRef attribute,
                                                                 CFStringRef _Nullable* language) STUB_METHOD;
CORETEXT_EXPORT CFTypeID CTFontDescriptorGetTypeID() STUB_METHOD;
