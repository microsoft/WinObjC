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

#include <StubReturn.h>
#include "Starboard.h"
#include "UIKit/UIFontDescriptor.h"

NSString* const UIFontTextStyleTitle1 = @"UICTFontTextStyleTitle1";
NSString* const UIFontTextStyleTitle2 = @"UICTFontTextStyleTitle2";
NSString* const UIFontTextStyleTitle3 = @"UICTFontTextStyleTitle3";
NSString* const UIFontTextStyleHeadline = @"UICTFontTextStyleHeadline";
NSString* const UIFontTextStyleSubheadline = @"UICTFontTextStyleSubheadline";
NSString* const UIFontTextStyleBody = @"UICTFontTextStyleBody";
NSString* const UIFontTextStyleFootnote = @"UICTFontTextStyleFootnote";
NSString* const UIFontTextStyleCaption1 = @"UICTFontTextStyleCaption1";
NSString* const UIFontTextStyleCaption2 = @"UICTFontTextStyleCaption2";
NSString* const UIFontTextStyleCallout = @"UICTFontTextStyleCallout";

NSString* const UIFontDescriptorFamilyAttribute = @"UIFontDescriptorFamilyAttribute";
NSString* const UIFontDescriptorTraitsAttribute = @"UIFontDescriptorTraitsAttribute";

NSString* const UIFontSymbolicTrait = @"UIFontSymbolicTrait";

NSString* const UIFontDescriptorNameAttribute = @"UIFontDescriptorNameAttribute";
NSString* const UIFontDescriptorFaceAttribute = @"UIFontDescriptorFaceAttribute";
NSString* const UIFontDescriptorSizeAttribute = @"UIFontDescriptorSizeAttribute";
NSString* const UIFontDescriptorVisibleNameAttribute = @"UIFontDescriptorVisibleNameAttribute";
NSString* const UIFontDescriptorMatrixAttribute = @"UIFontDescriptorMatrixAttribute";
NSString* const UIFontDescriptorCharacterSetAttribute = @"UIFontDescriptorCharacterSetAttribute";
NSString* const UIFontDescriptorCascadeListAttribute = @"UIFontDescriptorCascadeListAttribute";
NSString* const UIFontDescriptorFixedAdvanceAttribute = @"UIFontDescriptorFixedAdvanceAttribute";
NSString* const UIFontDescriptorFeatureSettingsAttribute = @"UIFontDescriptorFeatureSettingsAttribute";
NSString* const UIFontDescriptorTextStyleAttribute = @"UIFontDescriptorTextStyleAttribute";
NSString* const UIFontWeightTrait = @"UIFontWeightTrait";
NSString* const UIFontWidthTrait = @"UIFontWidthTrait";
NSString* const UIFontSlantTrait = @"UIFontSlantTrait";

NSString* const UIFontFeatureTypeIdentifierKey = @"UIFontFeatureTypeIdentifierKey";
NSString* const UIFontFeatureSelectorIdentifierKey = @"UIFontFeatureSelectorIdentifierKey";

NSString* const SystemFontName = @"SegoeUI";

/**@Status Stub */
const CGFloat UIFontWeightUltraLight = StubConstant();
/**@Status Stub */
const CGFloat UIFontWeightThin = StubConstant();
/**@Status Stub */
const CGFloat UIFontWeightLight = StubConstant();
/**@Status Stub */
const CGFloat UIFontWeightRegular = StubConstant();
/**@Status Stub */
const CGFloat UIFontWeightMedium = StubConstant();
/**@Status Stub */
const CGFloat UIFontWeightSemibold = StubConstant();
/**@Status Stub */
const CGFloat UIFontWeightBold = StubConstant();
/**@Status Stub */
const CGFloat UIFontWeightHeavy = StubConstant();
/**@Status Stub */
const CGFloat UIFontWeightBlack = StubConstant();

/**
 All these values are fixed number in IOS no matter on iphone* or ipad*.
 */
const float c_smallSystemFontSize = 12.0f;
const float c_systemFontSize = 14.0f;
const float c_labelFontSize = 17.0f;
const float c_buttonFontSize = 14.0f;

@implementation UIFontDescriptor {
@private
    idretaintype(NSString) _name;
    float _size;
    UIFontDescriptorSymbolicTraits _traits;
}

/**
 @Status Interoperable
*/
+ (UIFontDescriptor*)fontDescriptorWithName:(NSString*)fontName size:(CGFloat)size {
    UIFontDescriptor* fontDescriptor = [[UIFontDescriptor alloc] init];
    fontDescriptor->_name = [UIFontDescriptor _getFallBackFontName:fontName];
    fontDescriptor->_size = [UIFontDescriptor _getFallBackFontSize:size];
    return [fontDescriptor autorelease];
}

+ (UIFontDescriptor*)fontDescriptorWithDescriptor:(UIFontDescriptor*)descriptor size:(CGFloat)size {
    UIFontDescriptor* fontDescriptor = [[UIFontDescriptor alloc] init];
    fontDescriptor->_name = descriptor->_name;
    fontDescriptor->_size = [UIFontDescriptor _getFallBackFontSize:size];
    fontDescriptor->_traits = descriptor->_traits;
    return [fontDescriptor autorelease];
}

/**
 @Status Caveat
  @Notes         Force to use default font name and size.
*/
+ (UIFontDescriptor*)preferredFontDescriptorWithTextStyle:(NSString*)style {
    return [UIFontDescriptor fontDescriptorWithName:nil size:0.0];
}

/**
 This is a temp solution, we need to implement the fall back logic in 1512.
 Here just to check nil, and return default system font as fall back.
 */
+ (NSString*)_getFallBackFontName:(NSString*)fontName {
    NSString* ret = [NSString alloc];
    if (fontName == nil || fontName.length == 0) {
        ret = [ret initWithString:SystemFontName];
    } else {
        ret = [ret initWithString:fontName];
    }
    return [ret autorelease];
}

+ (float)_getFallBackFontSize:(float)size {
    if (size <= 0) {
        return c_systemFontSize;
    } else {
        return size;
    }
}

+ (float)_getSystemSmallFontSize {
    return c_smallSystemFontSize;
}

+ (float)_getSystemFontSize {
    return c_systemFontSize;
}

+ (float)_getLabelFontSize {
    return c_labelFontSize;
}

+ (float)_getButtonFontSize {
    return c_buttonFontSize;
}

/**
 @Status Interoperable
*/
- (UIFontDescriptor*)fontDescriptorWithSymbolicTraits:(UIFontDescriptorSymbolicTraits)symbolicTraits {
    UIFontDescriptor* result = [UIFontDescriptor fontDescriptorWithDescriptor:self size:self->_size];
    result->_traits = symbolicTraits;
    return result;
}

/**
 @Status Stub
*/
- (instancetype)initWithFontAttributes:(NSDictionary*)attributes {
    UNIMPLEMENTED();
    return nil;
}

- (NSString*)_getFontName {
    return self->_name;
}

/**
 @Status Interoperable
*/
- (UIFontDescriptorSymbolicTraits)symbolicTraits {
    return self->_traits;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    _name = nil;
    [super dealloc];
}

/**
 @Status Stub
*/
+ (UIFontDescriptor*)fontDescriptorWithFontAttributes:(NSDictionary*)attributes {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
+ (UIFontDescriptor*)fontDescriptorWithName:(NSString*)fontName matrix:(CGAffineTransform)matrix {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (UIFontDescriptor*)fontDescriptorByAddingAttributes:(NSDictionary*)attributes {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (UIFontDescriptor*)fontDescriptorWithFace:(NSString*)newFace {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (UIFontDescriptor*)fontDescriptorWithFamily:(NSString*)newFamily {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (UIFontDescriptor*)fontDescriptorWithMatrix:(CGAffineTransform)matrix {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (UIFontDescriptor*)fontDescriptorWithSize:(CGFloat)newPointSize {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (NSArray*)matchingFontDescriptorsWithMandatoryKeys:(NSSet*)mandatoryKeys {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (NSDictionary*)fontAttributes {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (id)objectForKey:(NSString*)anAttribute {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (instancetype)copyWithZone:(NSZone*)zone {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
  @Status Interoperable
*/
- (CGFloat)pointSize {
    return self->_size;
}

/**
 @Status Stub
*/
- (instancetype)initWithCoder:(NSCoder*)decoder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
+ (BOOL)supportsSecureCoding {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
