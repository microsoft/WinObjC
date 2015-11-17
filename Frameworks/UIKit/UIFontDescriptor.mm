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

NSString* const SystemFontName = @"SegoeUI";

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
  @Status        Interoperable
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
    fontDescriptor->_size = size;
    fontDescriptor->_traits = descriptor->_traits;
    return [fontDescriptor autorelease];
}

/**
  @Status        Caveat
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
    // We need to set the maximun of size, since xaml will crash if it is too big.
    float const maxSize = 100;
    if (size <= 0 || size > maxSize) {
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
  @Status        Interoperable
*/
- (UIFontDescriptor*)fontDescriptorWithSymbolicTraits:(UIFontDescriptorSymbolicTraits)symbolicTraits {
    UIFontDescriptor* result = [UIFontDescriptor fontDescriptorWithDescriptor:self size:self->_size];
    result->_traits = symbolicTraits;
    return result;
}

/**
  @Status        Stub
*/
- (instancetype)initWithFontAttributes:(NSDictionary*)attributes {
    // Just to unblock the build.
}

- (NSString*)_getFontName {
    return self->_name;
}

/**
  @Status        Interoperable
*/
- (UIFontDescriptorSymbolicTraits)symbolicTraits {
    return self->_traits;
}

- (void)dealloc {
    _name = nil;
    [super dealloc];
}

@end