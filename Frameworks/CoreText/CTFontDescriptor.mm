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

#import <CoreText/CTFontDescriptor.h>

#import <CFBridgeUtilities.h>
#import <CFRuntime.h>
#import <Starboard.h>
#import <StubReturn.h>

#import "DWriteWrapper_CoreText.h"

#include <COMIncludes.h>
#import <DWrite_3.h>
#import <wrl/client.h>
#include <COMIncludes_End.h>

const CFStringRef kCTFontURLAttribute = CFSTR("NSFontURLAttribute");
const CFStringRef kCTFontNameAttribute = CFSTR("NSFontNameAttribute");
const CFStringRef kCTFontDisplayNameAttribute = CFSTR("NSFontVisibleNameAttribute");
const CFStringRef kCTFontFamilyNameAttribute = CFSTR("NSFontFamilyAttribute");
const CFStringRef kCTFontStyleNameAttribute = CFSTR("NSFontFaceAttribute");
const CFStringRef kCTFontTraitsAttribute = CFSTR("NSFontTraitsAttribute");
const CFStringRef kCTFontVariationAttribute = CFSTR("NSFontVariationAttribute");
const CFStringRef kCTFontSizeAttribute = CFSTR("NSFontSizeAttribute");
const CFStringRef kCTFontMatrixAttribute = CFSTR("NSFontMatrixAttribute");
const CFStringRef kCTFontCascadeListAttribute = CFSTR("NSFontCascadeListAttribute");
const CFStringRef kCTFontCharacterSetAttribute = CFSTR("NSFontCharacterSetAttribute");
const CFStringRef kCTFontLanguagesAttribute = CFSTR("NSFontLanguagesAttribute");
const CFStringRef kCTFontBaselineAdjustAttribute = CFSTR("NSFontBaselineAdjustAttribute");
const CFStringRef kCTFontMacintoshEncodingsAttribute = CFSTR("NSFontMacintoshEncodingsAttribute");
const CFStringRef kCTFontFeaturesAttribute = CFSTR("NSFontFeaturesAttribute");
const CFStringRef kCTFontFeatureSettingsAttribute = CFSTR("NSFontFeatureSettingsAttribute");
const CFStringRef kCTFontFixedAdvanceAttribute = CFSTR("NSFontFixedAdvanceAttribute");
const CFStringRef kCTFontOrientationAttribute = CFSTR("NSFontOrientationAttribute");
const CFStringRef kCTFontFormatAttribute = CFSTR("NSFontFormatAttribute");
const CFStringRef kCTFontRegistrationScopeAttribute = CFSTR("NSFontRegistrationScopeAttribute");
const CFStringRef kCTFontPriorityAttribute = CFSTR("NSFontPriorityAttribute");
const CFStringRef kCTFontEnabledAttribute = CFSTR("NSFontEnabledAttribute");

const CFStringRef kCTFontSymbolicTrait = CFSTR("NSCTFontSymbolicTrait");
const CFStringRef kCTFontWeightTrait = CFSTR("NSCTFontWeightTrait");
const CFStringRef kCTFontWidthTrait = CFSTR("NSCTFontWidthTrait");
const CFStringRef kCTFontSlantTrait = CFSTR("NSCTFontSlantTrait");

using namespace Microsoft::WRL;

struct __CTFontDescriptor {
    CFRuntimeBase _base;

    // Mutable dictionary here is an optimization that allows avoiding extra mutable->immutable copy during certain constructors
    CFMutableDictionaryRef _attributes;
};

static Boolean __CTFontDescriptorEqual(CFTypeRef cf1, CFTypeRef cf2) {
    struct __CTFontDescriptor* desc1 = (struct __CTFontDescriptor*)cf1;
    struct __CTFontDescriptor* desc2 = (struct __CTFontDescriptor*)cf2;
    return CFEqual(desc1->_attributes, desc2->_attributes);
}

static CFHashCode __CTFontDescriptorHash(CFTypeRef cf) {
    CTFontDescriptorRef desc = (CTFontDescriptorRef)cf;
    return CFHash(desc->_attributes);
}

static CFStringRef __CTFontDescriptorCopyDescription(CFTypeRef cf) {
    CTFontDescriptorRef desc = (CTFontDescriptorRef)cf;
    return CFStringCreateWithFormat(kCFAllocatorSystemDefault, NULL, CFSTR("<CTFontDescriptor %p> = %@"), cf, desc->_attributes);
}

static void __CTFontDescriptorDeallocate(CFTypeRef cf) {
    CTFontDescriptorRef desc = (CTFontDescriptorRef)cf;
    // _attributes needs to be released, since CFTypes do a memset(0) on dealloc
    CFRelease(desc->_attributes);
}

static CFTypeID __kCTFontDescriptorTypeID = _kCFRuntimeNotATypeID;

static const CFRuntimeClass __CTFontDescriptorClass = { 0,
                                                        "CTFontDescriptor",
                                                        NULL, // init
                                                        NULL, // copy
                                                        __CTFontDescriptorDeallocate, // deallocate
                                                        __CTFontDescriptorEqual,
                                                        __CTFontDescriptorHash,
                                                        NULL, //
                                                        __CTFontDescriptorCopyDescription };

CFDictionaryRef __CreateAttributesDictFromNameAndSize(CFStringRef name, CGFloat size) {
    CFStringRef keys[] = { kCTFontNameAttribute, kCTFontSizeAttribute };
    CFTypeRef values[] = { name, CFAutorelease(CFNumberCreate(kCFAllocatorDefault, kCFNumberCGFloatType, &size)) };
    return CFDictionaryCreate(kCFAllocatorDefault,
                              reinterpret_cast<const void**>(keys),
                              reinterpret_cast<const void**>(values),
                              2, // number of key-value pairs
                              &kCFTypeDictionaryKeyCallBacks,
                              &kCFTypeDictionaryValueCallBacks);
}

/**
 @Status Interoperable
 @Notes
*/
CTFontDescriptorRef CTFontDescriptorCreateWithNameAndSize(CFStringRef name, CGFloat size) {
    CFDictionaryRef attributes = __CreateAttributesDictFromNameAndSize(name, size);
    CFAutorelease(attributes);
    return CTFontDescriptorCreateWithAttributes(attributes);
}

/**
 @Status Interoperable
 @Notes
*/
CTFontDescriptorRef CTFontDescriptorCreateWithAttributes(CFDictionaryRef attributes) {
    size_t memSize = sizeof(struct __CTFontDescriptor) - sizeof(CFRuntimeBase);
    CTFontDescriptorRef ret =
        static_cast<CTFontDescriptorRef>(_CFRuntimeCreateInstance(kCFAllocatorDefault, CTFontDescriptorGetTypeID(), memSize, NULL));
    struct __CTFontDescriptor* mutableRet = const_cast<struct __CTFontDescriptor*>(ret);

    mutableRet->_attributes = CFDictionaryCreateMutableCopy(kCFAllocatorDefault, 0, attributes);

    return ret;
}

/**
 @Status Interoperable
 @Notes
*/
CTFontDescriptorRef CTFontDescriptorCreateCopyWithAttributes(CTFontDescriptorRef original, CFDictionaryRef attributes) {
    if (!original) {
        return nullptr;
    }

    // New attributes override old ones
    CFMutableDictionaryRef newAttributes = CFDictionaryCreateMutableCopy(kCFAllocatorDefault, 0, original->_attributes);
    CFAutorelease(newAttributes);

    CFDictionaryApplyFunction(attributes,
                              [](const void* key, const void* value, void* context) {
                                  CFDictionarySetValue(reinterpret_cast<CFMutableDictionaryRef>(context), key, value);
                              },
                              newAttributes);

    return CTFontDescriptorCreateWithAttributes(newAttributes);
}

/**
 @Status Stub
 @Notes
*/
CTFontDescriptorRef CTFontDescriptorCreateCopyWithVariation(CTFontDescriptorRef original,
                                                            CFNumberRef variationIdentifier,
                                                            CGFloat variationValue) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CTFontDescriptorRef CTFontDescriptorCreateCopyWithFeature(CTFontDescriptorRef original,
                                                          CFNumberRef featureTypeIdentifier,
                                                          CFNumberRef featureSelectorIdentifier) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFArrayRef CTFontDescriptorCreateMatchingFontDescriptors(CTFontDescriptorRef descriptor, CFSetRef mandatoryAttributes) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CTFontDescriptorRef CTFontDescriptorCreateMatchingFontDescriptor(CTFontDescriptorRef descriptor, CFSetRef mandatoryAttributes) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
 @Notes
*/
CFDictionaryRef CTFontDescriptorCopyAttributes(CTFontDescriptorRef descriptor) {
    if (!descriptor) {
        return nullptr;
    }
    CF_OBJC_FUNCDISPATCHV(CTFontDescriptorGetTypeID(), CFDictionaryRef, (UIFontDescriptor*)descriptor, fontAttributes);
    return CFDictionaryCreateCopy(CFGetAllocator(descriptor->_attributes), descriptor->_attributes);
}

/**
 @Status Interoperable
 @Notes
*/
CFTypeRef CTFontDescriptorCopyAttribute(CTFontDescriptorRef descriptor, CFStringRef attribute) {
    if (!descriptor) {
        return nullptr;
    }

    CF_OBJC_FUNCDISPATCHV(CTFontDescriptorGetTypeID(), CFTypeRef, (UIFontDescriptor*)descriptor, objectForKey
                          : static_cast<NSString*>(attribute));

    // kCTFontTraitsAttribute is a special case
    if (CFEqual(attribute, kCTFontTraitsAttribute)) {
        CFTypeRef traits = CFDictionaryGetValue(descriptor->_attributes, kCTFontTraitsAttribute);
        if (traits) {
            return CFDictionaryCreateCopy(kCFAllocatorDefault, static_cast<CFDictionaryRef>(traits));
        } else {
            // If traits are unspecified, query DWrite for some font traits.

            // Rely on font name, or family name if font name is not specified
            CFStringRef name = static_cast<CFStringRef>(CFDictionaryGetValue(descriptor->_attributes, kCTFontNameAttribute));
            if (!name) {
                name = static_cast<CFStringRef>(CFDictionaryGetValue(descriptor->_attributes, kCTFontFamilyNameAttribute));
            }

            if (name) {
                ComPtr<IDWriteFontFace> fontFace;
                if (!FAILED(_DWriteCreateFontFaceWithName(name, &fontFace))) {
                    // Return this +1, since this function is CopyAttribute
                    // Do not cache this value (reference platform doesn't, messes up certain convenience constructors in CTFont)
                    return _DWriteFontCreateTraitsDict(fontFace);
                }
            }
            // Nothing that can be done here if neither name is specified, just return null
            return nullptr;
        }
    }

    // General case
    // Use CFRetain instead of a true copy here
    //  - A generic 'CFCopy' is not available, as not all types are copyable
    //  - This behavior matches that of the reference platform - if a mutable attribute is snuck in, its changes are reflected
    return CFRetain(CFDictionaryGetValue(descriptor->_attributes, attribute));
}

/**
 @Status Caveat
 @Notes  Currently ignores language
*/
CFTypeRef CTFontDescriptorCopyLocalizedAttribute(CTFontDescriptorRef descriptor, CFStringRef attribute, CFStringRef _Nullable* language) {
    return CTFontDescriptorCopyAttribute(descriptor, attribute);
}

/**
 @Status Interoperable
 @Notes
*/
CFTypeID CTFontDescriptorGetTypeID() {
    static dispatch_once_t initOnce = 0;
    dispatch_once(&initOnce,
                  ^{
                      __kCTFontDescriptorTypeID = _CFRuntimeRegisterClass(&__CTFontDescriptorClass);
                  });
    return __kCTFontDescriptorTypeID;
}
