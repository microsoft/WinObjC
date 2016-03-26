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
#import <StubReturn.h>

const CFStringRef kCTFontURLAttribute = static_cast<CFStringRef>(@"kCTFontURLAttribute");
const CFStringRef kCTFontNameAttribute = static_cast<CFStringRef>(@"kCTFontNameAttribute");
const CFStringRef kCTFontDisplayNameAttribute = static_cast<CFStringRef>(@"kCTFontDisplayNameAttribute");
const CFStringRef kCTFontFamilyNameAttribute = static_cast<CFStringRef>(@"kCTFontFamilyNameAttribute");
const CFStringRef kCTFontStyleNameAttribute = static_cast<CFStringRef>(@"kCTFontStyleNameAttribute");
const CFStringRef kCTFontTraitsAttribute = static_cast<CFStringRef>(@"kCTFontTraitsAttribute");
const CFStringRef kCTFontVariationAttribute = static_cast<CFStringRef>(@"kCTFontVariationAttribute");
const CFStringRef kCTFontSizeAttribute = static_cast<CFStringRef>(@"kCTFontSizeAttribute");
const CFStringRef kCTFontMatrixAttribute = static_cast<CFStringRef>(@"kCTFontMatrixAttribute");
const CFStringRef kCTFontCascadeListAttribute = static_cast<CFStringRef>(@"kCTFontCascadeListAttribute");
const CFStringRef kCTFontCharacterSetAttribute = static_cast<CFStringRef>(@"kCTFontCharacterSetAttribute");
const CFStringRef kCTFontLanguagesAttribute = static_cast<CFStringRef>(@"kCTFontLanguagesAttribute");
const CFStringRef kCTFontBaselineAdjustAttribute = static_cast<CFStringRef>(@"kCTFontBaselineAdjustAttribute");
const CFStringRef kCTFontMacintoshEncodingsAttribute = static_cast<CFStringRef>(@"kCTFontMacintoshEncodingsAttribute");
const CFStringRef kCTFontFeaturesAttribute = static_cast<CFStringRef>(@"kCTFontFeaturesAttribute");
const CFStringRef kCTFontFeatureSettingsAttribute = static_cast<CFStringRef>(@"kCTFontFeatureSettingsAttribute");
const CFStringRef kCTFontFixedAdvanceAttribute = static_cast<CFStringRef>(@"kCTFontFixedAdvanceAttribute");
const CFStringRef kCTFontOrientationAttribute = static_cast<CFStringRef>(@"kCTFontOrientationAttribute");
const CFStringRef kCTFontFormatAttribute = static_cast<CFStringRef>(@"kCTFontFormatAttribute");
const CFStringRef kCTFontRegistrationScopeAttribute = static_cast<CFStringRef>(@"kCTFontRegistrationScopeAttribute");
const CFStringRef kCTFontPriorityAttribute = static_cast<CFStringRef>(@"kCTFontPriorityAttribute");
const CFStringRef kCTFontEnabledAttribute = static_cast<CFStringRef>(@"kCTFontEnabledAttribute");
const CFStringRef kCTFontSymbolicTrait = static_cast<CFStringRef>(@"kCTFontSymbolicTrait");
const CFStringRef kCTFontWeightTrait = static_cast<CFStringRef>(@"kCTFontWeightTrait");
const CFStringRef kCTFontWidthTrait = static_cast<CFStringRef>(@"kCTFontWidthTrait");
const CFStringRef kCTFontSlantTrait = static_cast<CFStringRef>(@"kCTFontSlantTrait");

/**
 @Status Stub
 @Notes
*/
CTFontDescriptorRef CTFontDescriptorCreateWithNameAndSize(CFStringRef name, CGFloat size) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
 @Notes
*/
CTFontDescriptorRef CTFontDescriptorCreateWithAttributes(CFDictionaryRef attributes) {
    return (CTFontDescriptorRef)[(__bridge NSDictionary*)attributes copy];
}

/**
 @Status Stub
 @Notes
*/
CTFontDescriptorRef CTFontDescriptorCreateCopyWithAttributes(CTFontDescriptorRef original, CFDictionaryRef attributes) {
    UNIMPLEMENTED();
    return StubReturn();
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
 @Status Stub
 @Notes
*/
CFDictionaryRef CTFontDescriptorCopyAttributes(CTFontDescriptorRef descriptor) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFTypeRef CTFontDescriptorCopyAttribute(CTFontDescriptorRef descriptor, CFStringRef attribute) {
    UNIMPLEMENTED();
    return StubReturn();
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
 @Status Stub
 @Notes
*/
CFTypeID CTFontDescriptorGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}
