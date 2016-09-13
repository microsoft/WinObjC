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

#import <StubReturn.h>
#import <Starboard.h>
#import <UIKit/UIFont.h>
#import <UIKit/UIFontDescriptor.h>

#import <CGFontInternal.h>
#import <CGDataProviderInternal.h>

#import <CoreText/CTFont.h>
#import <CoreText/DWriteWrapper.h>

#import <NSRaise.h>
#import <BridgeHelpers.h>

#import <Foundation/NSString.h>
#import <Foundation/NSData.h>
#import <Foundation/NSArray.h>

#import "LoggingNative.h"
#import "UICTFont.h"
#import "UIFontInternal.h"
#import "UIFontDescriptorInternal.h"

#include <COMIncludes.h>
#import <DWrite.h>
#import <wrl/client.h>
#include <COMIncludes_End.h>

using namespace Microsoft::WRL;

NSString* const c_defaultFontName = @"Arial";

@implementation UIFont

BASE_CLASS_REQUIRED_IMPLS(UIFont, UICTFont, CTFontGetTypeID);

/**
 @Status Interoperable
*/
+ (NSArray<NSString*>*)familyNames {
    return static_cast<NSArray<NSString*>*>(_DWriteGetFontFamilyNames());
}

/**
 @Status Stub
*/
+ (UIFont*)preferredFontForTextStyle:(NSString*)style {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
+ (UIFont*)fontWithData:(NSData*)data {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
+ (UIFont*)fontWithName:(NSString*)name size:(CGFloat)size {
    return [UICTFont fontWithName:name size:size];
}

/**
 @Status Caveat
 @Notes  Currently only takes the name, and possibly size, from the font descriptor
 @Tags          Font
 @Public        Yes
*/
+ (UIFont*)fontWithDescriptor:(UIFontDescriptor*)descriptor size:(CGFloat)fontSize {
    // TODO: Needs to more deeply read the font descriptor - this is probably fine as a placeholder
    // Needs to probably also not rely on a private function
    if (fontSize <= 0) {
        fontSize = descriptor.pointSize;
    }

    UIFont* font = [UIFont fontWithName:[descriptor _getFontName] size:fontSize];
    return font;
}

+ (UIFont*)messageFont {
    static id mFont = [[self systemFontOfSize:15.0f] retain];
    return mFont;
}

+ (UIFont*)titleFont {
    static id tFont = [[self systemFontOfSize:20.0f] retain];
    return tFont;
}

+ (UIFont*)defaultFont {
    static id dFont = [[self systemFontOfSize:10.0f] retain];
    return dFont;
}

+ (UIFont*)buttonFont {
    static id dFont = [[self systemFontOfSize:17.0f] retain];
    return dFont;
}

/**
 @Status Interoperable
*/
+ (UIFont*)systemFontOfSize:(CGFloat)size {
    // TODO 5785385: Using clumsy fontWithDescriptor to initialize here, so that _descriptor is initialized
    // Clean this up a bit once fontDescriptor gets better support
    UIFont* ret = [self fontWithDescriptor:[UIFontDescriptor fontDescriptorWithName:c_defaultFontName size:size] size:size];

    return ret;
}

/**
 @Status Stub
*/
+ (UIFont*)systemFontOfSize:(CGFloat)size weight:(CGFloat)weight {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
+ (UIFont*)boldSystemFontOfSize:(CGFloat)size {
    // TODO 5785385: Using clumsy fontWithDescriptor to initialize here, so that _descriptor is initialized
    // Clean this up a bit once fontDescriptor gets better support
    UIFontDescriptor* fontDes =
        [[UIFontDescriptor fontDescriptorWithName:@"Arial Bold" size:size] fontDescriptorWithSymbolicTraits:UIFontDescriptorTraitBold];
    UIFont* ret = [self fontWithDescriptor:fontDes size:size];

    return ret;
}

/**
 @Status Interoperable
*/
+ (UIFont*)italicSystemFontOfSize:(CGFloat)size {
    // TODO 5785385: Using clumsy fontWithDescriptor to initialize here, so that _descriptor is initialized
    // Clean this up a bit once fontDescriptor gets better support
    UIFontDescriptor* fontDes =
        [[UIFontDescriptor fontDescriptorWithName:@"Arial Oblique" size:size] fontDescriptorWithSymbolicTraits:UIFontDescriptorTraitItalic];
    UIFont* ret = [self fontWithDescriptor:fontDes size:size];

    return ret;
}

/**
 @Status Stub
*/
+ (UIFont*)monospacedDigitSystemFontOfSize:(CGFloat)size weight:(CGFloat)weight {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
+ (NSArray<NSString*>*)fontNamesForFamilyName:(NSString*)familyName {
    return static_cast<NSArray<NSString*>*>(_DWriteGetFontNamesForFamilyName((__bridge CFStringRef)familyName));
}

/**
 @Status Interoperable
*/
- (UIFont*)fontWithSize:(CGFloat)size {
    return [UIFont fontWithName:[self fontName] size:size];
}

/**
 @Status Interoperable
*/
- (NSString*)fontName {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSString*)familyName {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (CGFloat)descender {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (CGFloat)ascender {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (CGFloat)lineHeight {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (CGFloat)capHeight {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (CGFloat)xHeight {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (CGFloat)pointSize {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Stub
*/
- (CGFloat)leading {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
 @Tags          Font
 @Public        Yes
*/
- (UIFontDescriptor*)fontDescriptor {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
 @Tags          Font
 @Public        Yes
*/
+ (CGFloat)smallSystemFontSize {
    return kCTFontSmallSystemFontSize;
}

/**
 @Status Interoperable
 @Tags          Font
 @Public        Yes
*/
+ (CGFloat)systemFontSize {
    return kCTFontSystemFontSize;
}

/**
 @Status Interoperable
 @Tags          Font
 @Public        Yes
*/
+ (CGFloat)labelFontSize {
    return kCTFontLabelFontSize;
}

/**
 @Status Interoperable
 @Tags          Font
 @Public        Yes
*/
+ (CGFloat)buttonFontSize {
    return kCTFontButtonFontSize;
}

- (NSUInteger)hash {
    UNIMPLEMENTED();
    return StubReturn();
}

- (BOOL)isEqual:(UIFont*)other {
    if (![other isKindOfClass:[UIFont class]]) {
        return NO;
    }
    if (self.pointSize != other.pointSize) {
        return NO;
    }
    if (![self.fontName isEqual:other.fontName]) {
        return NO;
    }

    return YES;
}

/**
@Status Interoperable
*/
- (instancetype)copyWithZone:(NSZone*)zone {
    return [self retain];
}

- (void)_setName:(NSString*)name {
    UNIMPLEMENTED();
}

- (uint32_t)_fontHandle {
    UNIMPLEMENTED();
    return StubReturn();
}

- (uint32_t)_sizingFontHandle {
    UNIMPLEMENTED();
    return StubReturn();
}

// Internal methods

// Private message sent from CTFontManager for the implementation of CTFontManagerRegisterGraphicsFont
- (bool)_CTFontManagerRegisterGraphicsFont:(CGFontRef)font withError:(CFErrorRef*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

// Internal methods
// Private message sent from CTFontManager for the implementation of CTFontManagerRegisterFontsForURL in CTFontManager
+ (bool)_CTFontManagerRegisterFontsForURL:(CFURLRef)fontURL withScope:(CTFontManagerScope)scope withError:(CFErrorRef*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
