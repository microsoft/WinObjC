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

const CFStringRef kCTFontURLAttribute = static_cast<CFStringRef>(@"NSFontURLAttribute");
const CFStringRef kCTFontNameAttribute = static_cast<CFStringRef>(@"NSFontNameAttribute");
const CFStringRef kCTFontDisplayNameAttribute = static_cast<CFStringRef>(@"NSFontVisibleNameAttribute");
const CFStringRef kCTFontFamilyNameAttribute = static_cast<CFStringRef>(@"NSFontFamilyAttribute");
const CFStringRef kCTFontStyleNameAttribute = static_cast<CFStringRef>(@"NSFontFaceAttribute");
const CFStringRef kCTFontTraitsAttribute = static_cast<CFStringRef>(@"NSFontTraitsAttribute");
const CFStringRef kCTFontVariationAttribute = static_cast<CFStringRef>(@"NSFontVariationAttribute");
const CFStringRef kCTFontSizeAttribute = static_cast<CFStringRef>(@"NSFontSizeAttribute");
const CFStringRef kCTFontMatrixAttribute = static_cast<CFStringRef>(@"NSFontMatrixAttribute");
const CFStringRef kCTFontCascadeListAttribute = static_cast<CFStringRef>(@"NSFontCascadeListAttribute");
const CFStringRef kCTFontCharacterSetAttribute = static_cast<CFStringRef>(@"NSFontCharacterSetAttribute");
const CFStringRef kCTFontLanguagesAttribute = static_cast<CFStringRef>(@"NSFontLanguagesAttribute");
const CFStringRef kCTFontBaselineAdjustAttribute = static_cast<CFStringRef>(@"NSFontBaselineAdjustAttribute");
const CFStringRef kCTFontMacintoshEncodingsAttribute = static_cast<CFStringRef>(@"NSFontMacintoshEncodingsAttribute");
const CFStringRef kCTFontFeaturesAttribute = static_cast<CFStringRef>(@"NSFontFeaturesAttribute");
const CFStringRef kCTFontFeatureSettingsAttribute = static_cast<CFStringRef>(@"NSFontFeatureSettingsAttribute");
const CFStringRef kCTFontFixedAdvanceAttribute = static_cast<CFStringRef>(@"NSFontFixedAdvanceAttribute");
const CFStringRef kCTFontOrientationAttribute = static_cast<CFStringRef>(@"NSFontOrientationAttribute");
const CFStringRef kCTFontFormatAttribute = static_cast<CFStringRef>(@"NSFontFormatAttribute");
const CFStringRef kCTFontRegistrationScopeAttribute = static_cast<CFStringRef>(@"NSFontRegistrationScopeAttribute");
const CFStringRef kCTFontPriorityAttribute = static_cast<CFStringRef>(@"NSFontPriorityAttribute");
const CFStringRef kCTFontEnabledAttribute = static_cast<CFStringRef>(@"NSFontEnabledAttribute");

const CFStringRef kCTFontSymbolicTrait = static_cast<CFStringRef>(@"NSCTFontSymbolicTrait");
const CFStringRef kCTFontWeightTrait = static_cast<CFStringRef>(@"NSCTFontWeightTrait");
const CFStringRef kCTFontWidthTrait = static_cast<CFStringRef>(@"NSCTFontWidthTrait");
const CFStringRef kCTFontSlantTrait = static_cast<CFStringRef>(@"NSCTFontSlantTrait");

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
    __CFGenericValidateType(descriptor, CTFontDescriptorGetTypeID());
    return CFDictionaryCreateCopy(CFGetAllocator(descriptor->_dictionary), descriptor->_dictionary);
}

/**
 @Status Interoperable
 @Notes
*/
CFTypeRef CTFontDescriptorCopyAttribute(CTFontDescriptorRef descriptor, CFStringRef attribute) {
    CF_OBJC_FUNCDISPATCHV(CTFontDescriptorGetTypeID(), CFTypeRef, (UIFontDescriptor*)descriptor, objectForKey
                          : static_cast<NSString*>(attribute));
    __CFGenericValidateType(descriptor, CTFontDescriptorGetTypeID());

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
