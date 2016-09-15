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

struct __CTFontDescriptor {
    CFRuntimeBase _base;
    CFDictionaryRef _dictionary;
};

static Boolean __CTFontDescriptorEqual(CFTypeRef cf1, CFTypeRef cf2) {
    struct __CTFontDescriptor* desc1 = (struct __CTFontDescriptor*)cf1;
    struct __CTFontDescriptor* desc2 = (struct __CTFontDescriptor*)cf2;
    return CFEqual(desc1->_dictionary, desc2->_dictionary);
}

static CFHashCode __CTFontDescriptorHash(CFTypeRef cf) {
    CTFontDescriptorRef desc = (CTFontDescriptorRef)cf;
    return CFHash(desc->_dictionary);
}

static CFStringRef __CTFontDescriptorCopyDescription(CFTypeRef cf) {
    CTFontDescriptorRef desc = (CTFontDescriptorRef)cf;
    return CFStringCreateWithFormat(kCFAllocatorSystemDefault, NULL, CFSTR("<CTFontDescriptor %p> = %@"), cf, desc->_dictionary);
}

static void __CTFontDescriptorDeallocate(CFTypeRef cf) {
    CTFontDescriptorRef desc = (CTFontDescriptorRef)cf;
    // _dictionary needs to be released, since CFTypes do a memset(0) on dealloc
    CFRelease(desc->_dictionary);
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

/**
 @Status Interoperable
 @Notes
*/
CTFontDescriptorRef CTFontDescriptorCreateWithNameAndSize(CFStringRef name, CGFloat size) {
    CFStringRef keys[] = { kCTFontNameAttribute, kCTFontSizeAttribute };
    CFTypeRef values[] = { name, CFAutorelease(CFNumberCreate(kCFAllocatorDefault, kCFNumberCGFloatType, &size)) };
    CFDictionaryRef attributes = CFDictionaryCreate(kCFAllocatorDefault,
                                                    reinterpret_cast<const void**>(keys),
                                                    reinterpret_cast<const void**>(values),
                                                    2, // number of key-value pairs
                                                    &kCFTypeDictionaryKeyCallBacks,
                                                    &kCFTypeDictionaryValueCallBacks);
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

    mutableRet->_dictionary = CFDictionaryCreateCopy(kCFAllocatorDefault, attributes);
    return ret;
}

/**
 @Status Interoperable
 @Notes
*/
CTFontDescriptorRef CTFontDescriptorCreateCopyWithAttributes(CTFontDescriptorRef original, CFDictionaryRef attributes) {
    // New attributes override old ones
    CFMutableDictionaryRef newAttributes = CFDictionaryCreateMutableCopy(kCFAllocatorDefault, 0, original->_dictionary);
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
    CF_OBJC_FUNCDISPATCHV(CTFontDescriptorGetTypeID(), CFDictionaryRef, (UIFontDescriptor*)descriptor, fontAttributes);
    return CFDictionaryCreateCopy(CFGetAllocator(descriptor->_dictionary), descriptor->_dictionary);
}

/**
 @Status Interoperable
 @Notes
*/
CFTypeRef CTFontDescriptorCopyAttribute(CTFontDescriptorRef descriptor, CFStringRef attribute) {
    CF_OBJC_FUNCDISPATCHV(CTFontDescriptorGetTypeID(), CFTypeRef, (UIFontDescriptor*)descriptor, objectForKey
                          : static_cast<NSString*>(attribute));

    // Use CFRetain instead of a true copy here
    //  - A generic 'CFCopy' is not available, as not all types are copyable
    //  - This behavior matches that of the reference platform - if a mutable attribute is snuck in, its changes are reflected
    return CFRetain(CFDictionaryGetValue(descriptor->_dictionary, attribute));
}

/**
 @Status Stub
 @Notes
*/
CFTypeRef CTFontDescriptorCopyLocalizedAttribute(CTFontDescriptorRef descriptor, CFStringRef attribute, CFStringRef _Nullable* language) {
    UNIMPLEMENTED();
    return StubReturn();
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
