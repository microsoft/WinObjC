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

#import <CoreText/CTFont.h>
#import <CoreGraphics/CGFont.h>
#import <LoggingNative.h>
#import <Starboard.h>
#import <StubReturn.h>
#import <CoreFoundation/CFString.h>
#import <CFRuntime.h>
#import <CFBridgeUtilities.h>
#import <UIKit/UIFont.h>

#import <CoreText/CTFontDescriptor.h>
#include <COMIncludes.h>
#import <DWrite_3.h>
#import <wrl/client.h>
#include <COMIncludes_End.h>

#import "DWriteWrapper_CoreText.h"

#import <map>
#import <memory>
#import <vector>

static const wchar_t* g_logTag = L"CTFont";

const CFStringRef kCTFontCopyrightNameKey = CFSTR("CTFontCopyrightName");
const CFStringRef kCTFontFamilyNameKey = CFSTR("CTFontFamilyName");
const CFStringRef kCTFontSubFamilyNameKey = CFSTR("CTFontSubFamilyName");
const CFStringRef kCTFontStyleNameKey = CFSTR("CTFontStyleName");
const CFStringRef kCTFontUniqueNameKey = CFSTR("CTFontUniqueName");
const CFStringRef kCTFontFullNameKey = CFSTR("CTFontFullName");
const CFStringRef kCTFontVersionNameKey = CFSTR("CTFontVersionName");
const CFStringRef kCTFontPostScriptNameKey = CFSTR("CTFontPostScriptName");
const CFStringRef kCTFontTrademarkNameKey = CFSTR("CTFontTrademarkName");
const CFStringRef kCTFontManufacturerNameKey = CFSTR("CTFontManufacturerName");
const CFStringRef kCTFontDesignerNameKey = CFSTR("CTFontDesignerName");
const CFStringRef kCTFontDescriptionNameKey = CFSTR("CTFontDescriptionName");
const CFStringRef kCTFontVendorURLNameKey = CFSTR("CTFontVendorURLName");
const CFStringRef kCTFontDesignerURLNameKey = CFSTR("CTFontDesignerURLName");
const CFStringRef kCTFontLicenseNameKey = CFSTR("CTFontLicenseName");
const CFStringRef kCTFontLicenseURLNameKey = CFSTR("CTFontLicenseURLName");
const CFStringRef kCTFontSampleTextNameKey = CFSTR("CTFontSampleTextName");
const CFStringRef kCTFontPostScriptCIDNameKey = CFSTR("CTFontPostScriptCIDName");
const CFStringRef kCTFontVariationAxisIdentifierKey = CFSTR("CTFontVariationAxisIdentifier");
const CFStringRef kCTFontVariationAxisMinimumValueKey = CFSTR("CTFontVariationAxisMinimumValue");
const CFStringRef kCTFontVariationAxisMaximumValueKey = CFSTR("CTFontVariationAxisMaximumValue");
const CFStringRef kCTFontVariationAxisDefaultValueKey = CFSTR("CTFontVariationAxisDefaultValue");
const CFStringRef kCTFontVariationAxisNameKey = CFSTR("CTFontVariationAxisName");
const CFStringRef kCTFontFeatureTypeIdentifierKey = CFSTR("CTFontFeatureTypeIdentifier");
const CFStringRef kCTFontFeatureTypeNameKey = CFSTR("CTFontFeatureTypeName");
const CFStringRef kCTFontFeatureTypeExclusiveKey = CFSTR("CTFontFeatureTypeExclusive");
const CFStringRef kCTFontFeatureTypeSelectorsKey = CFSTR("CTFontFeatureTypeSelectors");
const CFStringRef kCTFontFeatureSelectorIdentifierKey = CFSTR("CTFontFeatureSelectorIdentifier");
const CFStringRef kCTFontFeatureSelectorNameKey = CFSTR("CTFontFeatureSelectorName");
const CFStringRef kCTFontFeatureSelectorDefaultKey = CFSTR("CTFontFeatureSelectorDefault");
const CFStringRef kCTFontFeatureSelectorSettingKey = CFSTR("CTFontFeatureSelectorSetting");

/**
 All these values are fixed number in IOS no matter on iphone* or ipad*.
 */
const CGFloat kCTFontLabelFontSize = 17.0f;
const CGFloat kCTFontButtonFontSize = 14.0f;
const CGFloat kCTFontSmallSystemFontSize = 12.0f;
const CGFloat kCTFontSystemFontSize = 14.0f;

// Below values match the reference platform UIKit values
const CGFloat kCTFontWeightUltraLight = -0.80f;
const CGFloat kCTFontWeightThin = -0.60f;
const CGFloat kCTFontWeightLight = -0.40f;
const CGFloat kCTFontWeightRegular = 0.00f;
const CGFloat kCTFontWeightMedium = 0.23f;
const CGFloat kCTFontWeightSemibold = 0.30f;
const CGFloat kCTFontWeightBold = 0.40f;
const CGFloat kCTFontWeightHeavy = 0.56f;
const CGFloat kCTFontWeightBlack = 0.62f;

const CFStringRef kCTFontDefaultFontName = CFSTR("Arial");
const CFStringRef kCTFontDefaultBoldFontName = CFSTR("Arial Bold");
const CFStringRef kCTFontDefaultItalicFontName = CFSTR("Arial Italic");
const CFStringRef kCTFontDefaultMonospacedFontName = CFSTR("Courier New");

using namespace Microsoft::WRL;

struct __CTFont {
    CFRuntimeBase _base;
    ComPtr<IDWriteFontFace> _dwriteFontFace;
    CGFloat _pointSize; // This is also stored in _descriptor as a CFNumber, but as an optimization, keep it here also as an ordinary float

    CTFontDescriptorRef _descriptor;

    struct DWRITE_FONT_METRICS _metrics;
    bool _cachedMetrics; // Set to true when _metrics is init'd
};

static Boolean __CTFontEqual(CFTypeRef cf1, CFTypeRef cf2) {
    struct __CTFont* font1 = (struct __CTFont*)cf1;
    struct __CTFont* font2 = (struct __CTFont*)cf2;

    return (font1->_pointSize == font2->_pointSize) &&
           (CFEqual(CFAutorelease(CTFontCopyPostScriptName(font1)), CFAutorelease(CTFontCopyPostScriptName(font2)))) &&
           (CFEqual(font1->_descriptor, font2->_descriptor));
}

static CFHashCode __CTFontHash(CFTypeRef cf) {
    CTFontRef font = (CTFontRef)cf;
    return CFHash(CFAutorelease(CTFontCopyFullName(font))) * CTFontGetSize(font) * CFHash(font->_descriptor);
}

static CFStringRef __CTFontCopyDescription(CFTypeRef cf) {
    CTFontRef font = (CTFontRef)cf;
    return CFStringCreateWithFormat(kCFAllocatorSystemDefault,
                                    NULL,
                                    CFSTR("<CTFont %p>{font-name: %@; font-family: %@; font-size: %.2f}"),
                                    cf,
                                    CFAutorelease(CTFontCopyDisplayName(font)),
                                    CFAutorelease(CTFontCopyFamilyName(font)),
                                    CTFontGetSize(font));
}

static void __CTFontInit(CFTypeRef cf) {
    CTFontRef font = (CTFontRef)cf;
    // ComPtr needs to be manually new'd, to avoid calling Create functions to an incomplete out-pointer
    struct __CTFont* mutableFont = const_cast<struct __CTFont*>(font);
    new (std::addressof(mutableFont->_dwriteFontFace)) ComPtr<IDWriteFontFace>();
}

static void __CTFontDeallocate(CFTypeRef cf) {
    CTFontRef font = (CTFontRef)cf;
    CFRelease(font->_descriptor);
    // ComPtr needs to be manually destructed, since CFTypes do a memset(0) on dealloc
    font->_dwriteFontFace.~ComPtr();
}

static const CFRuntimeClass __CTFontClass = { 0,
                                              "CTFont",
                                              __CTFontInit, // init
                                              NULL, // copy
                                              __CTFontDeallocate, // deallocate
                                              __CTFontEqual,
                                              __CTFontHash,
                                              NULL, //
                                              __CTFontCopyDescription };

// Private convenience helper for creating a CFDataRef from a CGAffineTransform
CFDataRef __CFDataCreateWithCGAffineTransform(CGAffineTransform matrix) {
    return CFDataCreate(kCFAllocatorDefault, reinterpret_cast<byte*>(&matrix), sizeof(CGAffineTransform));
}

// Private convenience helper for getting the CGAffineTransform value out of a CFDataRef
CGAffineTransform __CGAffineTransformGetFromCFData(CFDataRef data) {
    CGAffineTransform ret;
    CFDataGetBytes(data, CFRangeMake(0, sizeof(CGAffineTransform)), reinterpret_cast<byte*>(&ret));
    return ret;
}

// Private convenience helper for getting a mutable dictionary of a font's attributes to work with
CFMutableDictionaryRef __CTFontCopyAutoreleasedMutableAttributes(CTFontRef font) {
    CFDictionaryRef originalAttributes = CTFontDescriptorCopyAttributes(font->_descriptor);
    CFAutorelease(originalAttributes);

    CFMutableDictionaryRef ret = CFDictionaryCreateMutableCopy(kCFAllocatorDefault, 0, originalAttributes);
    CFAutorelease(ret);
    return ret;
}

// Private convenience helper for creating a CTFont with an attributes dictionary
CTFontRef __CTFontCreateWithAttributes(CFDictionaryRef attributes, CGFloat size, const CGAffineTransform* matrix) {
    CTFontDescriptorRef descriptor = CTFontDescriptorCreateWithAttributes(attributes);
    CFAutorelease(descriptor);
    return CTFontCreateWithFontDescriptor(descriptor, size, matrix);
}

// Private convenience helper for creating a CTFontDescriptor from a DWriteFontFace
CTFontDescriptorRef __CTFontDescriptorCreateWithDWriteFontFace(CGFloat size,
                                                               const CGAffineTransform* matrix,
                                                               Microsoft::WRL::ComPtr<IDWriteFontFace> fontFace) {
    CFStringRef name = _DWriteFontCopyName(fontFace, kCTFontFullNameKey);
    CFAutorelease(name);
    if (matrix) {
        CFStringRef keys[] = { kCTFontNameAttribute, kCTFontSizeAttribute, kCTFontMatrixAttribute };
        CFTypeRef values[] = { name,
                               CFAutorelease(CFNumberCreate(kCFAllocatorDefault, kCFNumberCGFloatType, &size)),
                               CFAutorelease(__CFDataCreateWithCGAffineTransform(*matrix)) };
        CFDictionaryRef attributes = CFDictionaryCreate(kCFAllocatorDefault,
                                                        reinterpret_cast<const void**>(keys),
                                                        reinterpret_cast<const void**>(values),
                                                        3, // number of key-value pairs
                                                        &kCFTypeDictionaryKeyCallBacks,
                                                        &kCFTypeDictionaryValueCallBacks);

        CFAutorelease(attributes);
        return CTFontDescriptorCreateWithAttributes(attributes);
    } else {
        return CTFontDescriptorCreateWithNameAndSize(name, size);
    }
}

/**
 @Status Caveat
 @Notes matrix parameter stored but not used
*/
CTFontRef CTFontCreateWithName(CFStringRef name, CGFloat size, const CGAffineTransform* matrix) {
    return CTFontCreateWithNameAndOptions(name, size, matrix, kCTFontOptionsDefault);
}

/**
 @Status Caveat
 @Notes matrix parameter stored but not used, options parameter not supported
*/
CTFontRef CTFontCreateWithNameAndOptions(CFStringRef name, CGFloat size, const CGAffineTransform* matrix, CTFontOptions options) {
    size_t memSize = sizeof(struct __CTFont) - sizeof(CFRuntimeBase);
    CTFontRef ret = static_cast<CTFontRef>(_CFRuntimeCreateInstance(kCFAllocatorDefault, CTFontGetTypeID(), memSize, NULL));
    struct __CTFont* mutableRet = const_cast<struct __CTFont*>(ret);

    if (FAILED(_DWriteCreateFontFaceWithName(name, &mutableRet->_dwriteFontFace))) {
        TraceError(g_logTag, L"Failed to create font.");
        CFRelease(ret);
        return nullptr;
    }

    mutableRet->_pointSize = size > 0 ? size : kCTFontSystemFontSize;
    mutableRet->_descriptor = __CTFontDescriptorCreateWithDWriteFontFace(mutableRet->_pointSize, matrix, mutableRet->_dwriteFontFace);

    return ret;
}

/**
 @Status Caveat
 @Notes matrix parameter stored but not used
*/
CTFontRef CTFontCreateWithFontDescriptor(CTFontDescriptorRef descriptor, CGFloat size, const CGAffineTransform* matrix) {
    return CTFontCreateWithFontDescriptorAndOptions(descriptor, size, matrix, kCTFontOptionsDefault);
}

/**
 @Status Caveat
 @Notes matrix parameter stored but not used, options parameter not supported
*/
CTFontRef CTFontCreateWithFontDescriptorAndOptions(CTFontDescriptorRef descriptor,
                                                   CGFloat size,
                                                   const CGAffineTransform* matrix,
                                                   CTFontOptions options) {
    size_t memSize = sizeof(struct __CTFont) - sizeof(CFRuntimeBase);
    CTFontRef ret = static_cast<CTFontRef>(_CFRuntimeCreateInstance(kCFAllocatorDefault, CTFontGetTypeID(), memSize, NULL));
    struct __CTFont* mutableRet = const_cast<struct __CTFont*>(ret);

    if (FAILED(_DWriteCreateFontFaceWithFontDescriptor(descriptor, &mutableRet->_dwriteFontFace))) {
        TraceError(g_logTag, L"Failed to create font.");
        CFRelease(ret);
        return nullptr;
    }

    mutableRet->_pointSize = size > 0 ? size : kCTFontSystemFontSize;
    mutableRet->_descriptor = __CTFontDescriptorCreateWithDWriteFontFace(mutableRet->_pointSize, matrix, mutableRet->_dwriteFontFace);

    return ret;
}

/**
 @Status Stub
 @Notes
*/
CTFontRef CTFontCreateUIFontForLanguage(CTFontUIFontType uiType, CGFloat size, CFStringRef language) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
 @Notes matrix parameter stored but not used
*/
CTFontRef CTFontCreateCopyWithAttributes(CTFontRef font, CGFloat size, const CGAffineTransform* matrix, CTFontDescriptorRef attributes) {
    if (!font) {
        return nullptr;
    }

    CFDictionaryRef originalAttributes = CTFontDescriptorCopyAttributes(font->_descriptor);
    CFAutorelease(originalAttributes);

    CFMutableDictionaryRef attributesToUse = CFDictionaryCreateMutableCopy(kCFAllocatorDefault, 0, originalAttributes);
    CFAutorelease(attributesToUse);

    // Copy new attributes from attributes to attributesToUse
    CFDictionaryApplyFunction(originalAttributes,
                              [](const void* key, const void* value, void* context) {
                                  CFDictionarySetValue(reinterpret_cast<CFMutableDictionaryRef>(context), key, value);
                              },
                              attributesToUse);

    // If both font name and family name are present, allow more variation in the final font by relying on just the family name
    if (CFDictionaryContainsKey(attributesToUse, kCTFontNameAttribute) &&
        CFDictionaryContainsKey(attributesToUse, kCTFontFamilyNameAttribute)) {
        CFDictionaryRemoveValue(attributesToUse, kCTFontNameAttribute);
    }

    return __CTFontCreateWithAttributes(attributesToUse, size, matrix);
}

/**
 @Status Caveat
 @Notes matrix parameter stored but not used, only limited bits (italic, bold, expanded, condensed) supported in symTraitMask
*/
CTFontRef CTFontCreateCopyWithSymbolicTraits(
    CTFontRef font, CGFloat size, const CGAffineTransform* matrix, CTFontSymbolicTraits symTraitValue, CTFontSymbolicTraits symTraitMask) {
    CFMutableDictionaryRef attributesToUse = __CTFontCopyAutoreleasedMutableAttributes(font);

    // Allow more variation in the final font by relying on just the family name
    if (CFDictionaryContainsKey(attributesToUse, kCTFontNameAttribute)) {
        CFDictionaryRemoveValue(attributesToUse, kCTFontNameAttribute);
    }

    CFDictionarySetValue(attributesToUse, kCTFontFamilyNameAttribute, CFAutorelease(CTFontCopyFamilyName(font)));

    // Reference platform is more nuanced in how it uses the bit mask/bit value
    // ie: consider the first bit (italic)
    // mask = false, value = any: iOS doesn't care, will match a font regardless of slant
    // mask = true, value = false: iOS will try to match a font that matches the default value (not slanted)
    // mask = true, value = true: iOS will try to find an oblique/italic font
    // DWrite lacks this level of nuance, requiring at least a default value
    // As such, just take the bitwise & of the mask and value here
    // Traits are stored in a separate dictionary
    CFTypeRef traitKeys[] = { kCTFontSymbolicTrait };
    CFTypeRef traitValues[] = { CFAutorelease(_CFNumberCreateFromSymbolicTraits(symTraitValue & symTraitMask)) };
    CFDictionaryRef traits = CFDictionaryCreate(kCFAllocatorDefault,
                                                reinterpret_cast<const void**>(traitKeys),
                                                reinterpret_cast<const void**>(traitValues),
                                                1, // number of key-value pairs
                                                &kCFTypeDictionaryKeyCallBacks,
                                                &kCFTypeDictionaryValueCallBacks);
    CFDictionarySetValue(attributesToUse, kCTFontTraitsAttribute, CFAutorelease(traits));

    return __CTFontCreateWithAttributes(attributesToUse, size, matrix);
}

/**
 @Status Caveat
 @Notes matrix parameter stored but not used
*/
CTFontRef CTFontCreateCopyWithFamily(CTFontRef font, CGFloat size, const CGAffineTransform* matrix, CFStringRef family) {
    if (!font) {
        return nullptr;
    }

    CFMutableDictionaryRef attributesToUse = __CTFontCopyAutoreleasedMutableAttributes(font);

    // Make sure attributes have the correct traits
    CFDictionarySetValue(attributesToUse, kCTFontTraitsAttribute, CFAutorelease(_DWriteFontCreateTraitsDict(font->_dwriteFontFace)));

    // Erase any existing font name
    if (CFDictionaryContainsKey(attributesToUse, kCTFontNameAttribute)) {
        CFDictionaryRemoveValue(attributesToUse, kCTFontNameAttribute);
    }

    // Set family name
    CFDictionarySetValue(attributesToUse, kCTFontFamilyNameAttribute, family);

    return __CTFontCreateWithAttributes(attributesToUse, size, matrix);
}

/**
 @Status Stub
 @Notes
*/
CTFontRef CTFontCreateForString(CTFontRef currentFont, CFStringRef string, CFRange range) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
 @Notes
*/
CTFontDescriptorRef CTFontCopyFontDescriptor(CTFontRef font) {
    CF_OBJC_FUNCDISPATCHV(CTFontGetTypeID(), CTFontDescriptorRef, (UIFont*)font, fontDescriptor);
    return CTFontDescriptorCreateWithNameAndSize(static_cast<CFStringRef>(CFAutorelease(CTFontCopyFullName(font))), CTFontGetSize(font));
}

/**
 @Status Interoperable
 @Notes
*/
CFTypeRef CTFontCopyAttribute(CTFontRef font, CFStringRef attribute) {
    if (!font) {
        return nullptr;
    }
    return CTFontDescriptorCopyAttribute(font->_descriptor, attribute);
}

/**
 @Status Interoperable
*/
CGFloat CTFontGetSize(CTFontRef font) {
    CF_OBJC_FUNCDISPATCHV(CTFontGetTypeID(), CGFloat, (UIFont*)font, pointSize);

    if (!font) {
        return 0;
    }
    return font->_pointSize;
}

/**
 @Status Interoperable
 @Notes
*/
CGAffineTransform CTFontGetMatrix(CTFontRef font) {
    CFDataRef data = static_cast<CFDataRef>(CFAutorelease(CTFontCopyAttribute(font, kCTFontMatrixAttribute)));
    if (data) {
        return __CGAffineTransformGetFromCFData(data);
    } else {
        // Identity matrix seems like a decent default return
        return CGAffineTransformIdentity;
    }
}

/**
 @Status Interoperable
 @Notes
*/
CTFontSymbolicTraits CTFontGetSymbolicTraits(CTFontRef font) {
    CFDictionaryRef traits = CTFontCopyTraits(font);

    if (traits) {
        const void* num = CFDictionaryGetValue(traits, kCTFontSymbolicTrait);
        CFRelease(traits);

        if (num) {
            return _CTFontSymbolicTraitsFromCFNumber(static_cast<CFNumberRef>(num));
        }
    }

    return 0;
}

/**
 @Status Interoperable
 @Notes
*/
CFDictionaryRef CTFontCopyTraits(CTFontRef font) {
    if (!font) {
        return nullptr;
    }
    return static_cast<CFDictionaryRef>(CTFontDescriptorCopyAttribute(font->_descriptor, kCTFontTraitsAttribute));
}

/**
 @Status Interoperable
*/
CFStringRef CTFontCopyPostScriptName(CTFontRef font) {
    return CTFontCopyName(font, kCTFontPostScriptNameKey);
}

/**
 @Status Interoperable
*/
CFStringRef CTFontCopyFamilyName(CTFontRef font) {
    CF_OBJC_FUNCDISPATCHV(CTFontGetTypeID(), CFStringRef, (UIFont*)font, familyName);
    return CTFontCopyName(font, kCTFontFamilyNameKey);
}

/**
 @Status Interoperable
*/
CFStringRef CTFontCopyFullName(CTFontRef font) {
    CF_OBJC_FUNCDISPATCHV(CTFontGetTypeID(), CFStringRef, (UIFont*)font, fontName);
    return CTFontCopyName(font, kCTFontFullNameKey);
}

/**
 @Status Interoperable
*/
CFStringRef CTFontCopyDisplayName(CTFontRef font) {
    // This should work okay as a display name
    return CTFontCopyName(font, kCTFontFullNameKey);
}

/**
 @Status Interoperable
*/
CFStringRef CTFontCopyName(CTFontRef font, CFStringRef nameKey) {
    if (!font) {
        return nullptr;
    }
    return _DWriteFontCopyName(font->_dwriteFontFace, nameKey);
}

/**
 @Status Stub
 @Notes
*/
CFStringRef CTFontCopyLocalizedName(CTFontRef font, CFStringRef nameKey, CFStringRef _Nullable* actualLanguage) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFCharacterSetRef CTFontCopyCharacterSet(CTFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFStringEncoding CTFontGetStringEncoding(CTFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFArrayRef CTFontCopySupportedLanguages(CTFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

// Private helper for getting a DWRITE_FONT_METRICS struct, to avoid code duplication
static struct DWRITE_FONT_METRICS __CTFontGetDWriteMetrics(CTFontRef font) {
    if (!font->_cachedMetrics) {
        font->_dwriteFontFace->GetMetrics(&const_cast<struct __CTFont*>(font)->_metrics);
    }
    return font->_metrics;
}

// Private helper for converting a DWRITE_FONT_METRIC unit to a CTFont API unit
// DWRITE_FONT_METRICS measures its metrics in 'design units'
// CTFont APIs generally return in terms of point size
static CGFloat __CTFontScaleMetric(CTFontRef font, CGFloat metric) {
    return metric * font->_pointSize / CTFontGetUnitsPerEm(font);
}

// Private helper for converting a whole CGRect rather than a single metric
static CGRect __CTFontScaleRect(CTFontRef font, CGRect& rect) {
    rect.origin.x = __CTFontScaleMetric(font, rect.origin.x);
    rect.origin.y = __CTFontScaleMetric(font, rect.origin.y);
    rect.size.width = __CTFontScaleMetric(font, rect.size.width);
    rect.size.height = __CTFontScaleMetric(font, rect.size.height);
    return rect;
}

/**
 @Status Interoperable
 @Notes
*/
CGFloat CTFontGetAscent(CTFontRef font) {
    if (!font) {
        return 0;
    }
    CF_OBJC_FUNCDISPATCHV(CTFontGetTypeID(), CGFloat, (UIFont*)font, ascender);
    return __CTFontScaleMetric(font, __CTFontGetDWriteMetrics(font).ascent);
}

/**
 @Status Interoperable
 @Notes
*/
CGFloat CTFontGetDescent(CTFontRef font) {
    if (!font) {
        return 0;
    }
    CF_OBJC_FUNCDISPATCHV(CTFontGetTypeID(), CGFloat, (UIFont*)font, descender);
    // DWRITE_FONT_METRICS keeps an unsigned value for descent, but CTFontGetDescent is expected to return a negative value
    return -__CTFontScaleMetric(font, __CTFontGetDWriteMetrics(font).descent);
}

/**
 @Status Interoperable
 @Notes
*/
CGFloat CTFontGetLeading(CTFontRef font) {
    if (!font) {
        return 0;
    }
    return __CTFontScaleMetric(font, __CTFontGetDWriteMetrics(font).lineGap);
}

/**
 @Status Interoperable
 @Notes
*/
unsigned int CTFontGetUnitsPerEm(CTFontRef font) {
    if (!font) {
        return 0;
    }
    return __CTFontGetDWriteMetrics(font).designUnitsPerEm;
}

/**
 @Status Interoperable
 @Notes
*/
CFIndex CTFontGetGlyphCount(CTFontRef font) {
    if (!font) {
        return 0;
    }
    return font->_dwriteFontFace->GetGlyphCount();
}

/**
 @Status Interoperable
 @Notes
*/
CGRect CTFontGetBoundingBox(CTFontRef font) {
    if (!font) {
        return { { 0, 0 }, { 0, 0 } };
    }

    CGRect ret = _DWriteFontGetBoundingBox(font->_dwriteFontFace);

    // Scale the bounding box
    return __CTFontScaleRect(font, ret);
}

/**
 @Status Interoperable
 @Notes
*/
CGFloat CTFontGetUnderlinePosition(CTFontRef font) {
    if (!font) {
        return 0;
    }
    return __CTFontScaleMetric(font, __CTFontGetDWriteMetrics(font).underlinePosition);
}

/**
 @Status Interoperable
 @Notes
*/
CGFloat CTFontGetUnderlineThickness(CTFontRef font) {
    if (!font) {
        return 0;
    }
    return __CTFontScaleMetric(font, __CTFontGetDWriteMetrics(font).underlineThickness);
}

/**
 @Status Interoperable
 @Notes
*/
CGFloat CTFontGetSlantAngle(CTFontRef font) {
    if (!font) {
        return 0;
    }
    return _DWriteFontGetSlantDegrees(font->_dwriteFontFace);
}

/**
 @Status Interoperable
 @Notes
*/
CGFloat CTFontGetCapHeight(CTFontRef font) {
    if (!font) {
        return 0;
    }
    CF_OBJC_FUNCDISPATCHV(CTFontGetTypeID(), CGFloat, (UIFont*)font, capHeight);
    return __CTFontScaleMetric(font, __CTFontGetDWriteMetrics(font).capHeight);
}

/**
 @Status Interoperable
 @Notes
*/
CGFloat CTFontGetXHeight(CTFontRef font) {
    if (!font) {
        return 0;
    }
    CF_OBJC_FUNCDISPATCHV(CTFontGetTypeID(), CGFloat, (UIFont*)font, xHeight);
    return __CTFontScaleMetric(font, __CTFontGetDWriteMetrics(font).xHeight);
}

/**
 @Status Stub
 @Notes
*/
CGPathRef CTFontCreatePathForGlyph(CTFontRef font, CGGlyph glyph, const CGAffineTransform* matrix) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGGlyph CTFontGetGlyphWithName(CTFontRef font, CFStringRef glyphName) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
 @Notes  kCTFontVerticalOrientation is unsupported, returns the same as default and horizontal orientations
*/
CGRect CTFontGetBoundingRectsForGlyphs(
    CTFontRef font, CTFontOrientation orientation, const CGGlyph glyphs[], CGRect* boundingRects, CFIndex count) {
    if (!glyphs || count <= 0) {
        TraceError(g_logTag, L"No glyphs were specified");
        return CGRectNull;
    }

    if (boundingRects) {
        if (FAILED(_DWriteFontGetBoundingBoxesForGlyphs(
                font->_dwriteFontFace, glyphs, boundingRects, count, (orientation == kCTFontVerticalOrientation)))) {
            TraceError(g_logTag, L"Unable to get glyph bounding boxes");
            return CGRectNull;
        }

        CGRect ret = { { std::numeric_limits<CGFloat>::max(), std::numeric_limits<CGFloat>::max() },
                       { std::numeric_limits<CGFloat>::lowest(), std::numeric_limits<CGFloat>::lowest() } };

        for (size_t i = 0; i < count; ++i) {
            // DWrite uses design units, where as CTFont uses point size
            // Scale all the boundingRects
            boundingRects[i] = __CTFontScaleRect(font, boundingRects[i]);

            // Find the overall bounding rect
            // This can probably be made more efficient by putting all of each attribute in an array and sorting it,
            // but that seems like overkill for now
            ret.origin.x = std::min(ret.origin.x, boundingRects[i].origin.x);
            ret.origin.y = std::min(ret.origin.y, boundingRects[i].origin.y);
            ret.size.width = std::max(ret.size.width, boundingRects[i].size.width);
            ret.size.height = std::max(ret.size.height, boundingRects[i].size.height);
        }

        return ret;

    } else {
        // Caller doesn't care about boundingRects, but still needs to calculate the overall rect
        // Call the boundingRects code path above with a temporary buffer
        std::vector<CGRect> rects = std::vector<CGRect>(count);
        return CTFontGetBoundingRectsForGlyphs(font, orientation, glyphs, rects.data(), count);
    }
}

/**
 @Status Caveat
 @Notes  kCTFontVerticalOrientation returns an imprecise, equal advance for each glyph
*/
double CTFontGetAdvancesForGlyphs(CTFontRef font, CTFontOrientation orientation, const CGGlyph glyphs[], CGSize* advances, CFIndex count) {
    if (!font) {
        return 0;
    }
    ComPtr<IDWriteFontFace1> fontFace1;
    font->_dwriteFontFace.As(&fontFace1);

    // DWrite uses design units, where as CTFont uses CGSize (struct of two floats)
    // Use an intermediatary buffer to call into DWrite
    int32_t designUnitGlyphAdvances[count];

    if (FAILED(fontFace1->GetDesignGlyphAdvances(count, glyphs, designUnitGlyphAdvances, (orientation == kCTFontVerticalOrientation)))) {
        TraceError(g_logTag, L"Unable to get glyph advances");
    }

    CGFloat ret = 0.0f;

    for (size_t i = 0; i < count; i++) {
        CGSize advance = { __CTFontScaleMetric(font, designUnitGlyphAdvances[i]), 0 };
        advances[i] = advance;

        // Return value is the sum of all the advances
        ret += advance.width;
    }

    return ret;
}

/**
 @Status Stub
 @Notes
*/
void CTFontGetVerticalTranslationsForGlyphs(CTFontRef font, const CGGlyph glyphs[], CGSize translations[], CFIndex count) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
CFArrayRef CTFontCopyVariationAxes(CTFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFDictionaryRef CTFontCopyVariation(CTFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFArrayRef CTFontCopyFeatures(CTFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFArrayRef CTFontCopyFeatureSettings(CTFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
 @Notes
*/
bool CTFontGetGlyphsForCharacters(CTFontRef fontRef, const UniChar characters[], CGGlyph glyphs[], CFIndex count) {
    if (!fontRef || !characters || !glyphs || count <= 0) {
        return false;
    }

    struct __CTFont* font = const_cast<struct __CTFont*>(fontRef);
    std::vector<uint32_t> chars(characters, characters + count);
    return SUCCEEDED(font->_dwriteFontFace->GetGlyphIndices(chars.data(), count, glyphs));
}

/**
 @Status Stub
 @Notes
*/
void CTFontDrawGlyphs(CTFontRef font, const CGGlyph glyphs[], const CGPoint positions[], size_t count, CGContextRef context) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
CFIndex CTFontGetLigatureCaretPositions(CTFontRef font, CGGlyph glyph, CGFloat* positions, CFIndex maxPositions) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
 @Notes Attributes parameter is not supported
*/
CGFontRef CTFontCopyGraphicsFont(CTFontRef font, CTFontDescriptorRef _Nullable* attributes) {
    return (CGFontRef)[static_cast<UIFont*>(font) retain];
}

/**
 @Status Caveat
 @Notes transform and attributes parameters not supported
*/
CTFontRef CTFontCreateWithGraphicsFont(CGFontRef cgFont, CGFloat size, const CGAffineTransform* xform, CTFontDescriptorRef attributes) {
    if (size == 0.0f) {
        size = 12.0f;
    }

    id ret = [[(UIFont*)cgFont fontWithSize:size] retain];
    return (CTFontRef)ret;
}
/**
 @Status Stub
 @Notes
*/
CFArrayRef CTFontCopyAvailableTables(CTFontRef font, CTFontTableOptions options) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
 @Notes options is not supported, and is deprecated anyway
*/
CFDataRef CTFontCopyTable(CTFontRef font, CTFontTableTag table, CTFontTableOptions options) {
    return _DWriteFontCopyTable(font->_dwriteFontFace, table);
}

/**
 @Status Interoperable
 @Notes
*/
CFTypeID CTFontGetTypeID() {
    static CFTypeID __kCTFontTypeID = _CFRuntimeRegisterClass(&__CTFontClass);
    return __kCTFontTypeID;
}

// Private function for getting font weight for XAML
DWRITE_FONT_WEIGHT _CTFontGetDWriteWeight(CTFontRef font) {
    ComPtr<IDWriteFontFace3> fontFace3;
    if (font && SUCCEEDED(font->_dwriteFontFace.As(&fontFace3))) {
        return fontFace3->GetWeight();
    }
    return DWRITE_FONT_WEIGHT_NORMAL;
}

// Private function for getting font stretch for XAML
DWRITE_FONT_STRETCH _CTFontGetDWriteStretch(CTFontRef font) {
    ComPtr<IDWriteFontFace3> fontFace3;
    if (font && SUCCEEDED(font->_dwriteFontFace.As(&fontFace3))) {
        return fontFace3->GetStretch();
    }
    return DWRITE_FONT_STRETCH_NORMAL;
}

// Private function for getting font style for XAML
DWRITE_FONT_STYLE _CTFontGetDWriteStyle(CTFontRef font) {
    ComPtr<IDWriteFontFace3> fontFace3;
    if (font && SUCCEEDED(font->_dwriteFontFace.As(&fontFace3))) {
        return fontFace3->GetStyle();
    }
    return DWRITE_FONT_STYLE_NORMAL;
}