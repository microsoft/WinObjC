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

#import <CGDataProviderInternal.h>

#import <CoreGraphics/DWriteWrapper.h>
#import <CoreText/CTFont.h>

#import <NSRaise.h>
#import <BridgeHelpers.h>

#import <Foundation/NSString.h>
#import <Foundation/NSData.h>
#import <Foundation/NSArray.h>

#import "LoggingNative.h"
#import "UICTFont.h"
#import "UIFontInternal.h"
#import <CoreTextInternal.h>

#include <COMIncludes.h>
#import <DWrite.h>
#import <wrl/client.h>
#include <COMIncludes_End.h>

using namespace Microsoft::WRL;

@implementation UIFont

BASE_CLASS_REQUIRED_IMPLS(UIFont, UIFontPrototype, CTFontGetTypeID);

/**
 @Status Interoperable
*/
+ (NSArray<NSString*>*)familyNames {
    return [static_cast<NSArray<NSString*>*>(_DWriteCopyFontFamilyNames()) autorelease];
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
 @Status Interoperable
 @Tags          Font
 @Public        Yes
*/
+ (UIFont*)fontWithDescriptor:(UIFontDescriptor*)descriptor size:(CGFloat)fontSize {
    return [UICTFont fontWithDescriptor:descriptor size:fontSize];
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
    static id dFont = [[self systemFontOfSize:[self systemFontSize]] retain];
    return dFont;
}

+ (UIFont*)buttonFont {
    static id dFont = [[self systemFontOfSize:[self buttonFontSize]] retain];
    return dFont;
}

/**
 @Status Interoperable
*/
+ (UIFont*)systemFontOfSize:(CGFloat)size {
    return [self fontWithName:(__bridge NSString*)kCTFontDefaultFontName size:size];
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
    return [self fontWithName:(__bridge NSString*)kCTFontDefaultBoldFontName size:size];
}

/**
 @Status Interoperable
*/
+ (UIFont*)italicSystemFontOfSize:(CGFloat)size {
    return [self fontWithName:(__bridge NSString*)kCTFontDefaultItalicFontName size:size];
}

/**
 @Status Stub
*/
+ (UIFont*)monospacedDigitSystemFontOfSize:(CGFloat)size weight:(CGFloat)weight {
    return [self fontWithName:(__bridge NSString*)kCTFontDefaultMonospacedFontName size:size];
}

/**
 @Status Interoperable
*/
+ (NSArray<NSString*>*)fontNamesForFamilyName:(NSString*)familyName {
    return [static_cast<NSArray<NSString*>*>(_DWriteCopyFontNamesForFamilyName((__bridge CFStringRef)familyName)) autorelease];
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
 @Status Interoperable
*/
- (CGFloat)leading {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
 @Tags          Font
 @Public        Yes
*/
- (UIFontDescriptor*)fontDescriptor {
    return NSInvalidAbstractInvocationReturn();
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

// WinObjC-only extension for compatibility issues between DWrite and Xaml
// Returns the family name of the font Xaml can use
- (NSString*)_compatibleFamilyName {
    return static_cast<NSString*>(_DWriteGetFamilyNameForFontName(static_cast<CFStringRef>([self fontName])));
}

// WinObjC-only extension for compatibility issues between DWrite and Xaml
// Returns the weight of the font Xaml can use
- (DWRITE_FONT_WEIGHT)_fontWeight {
    return _CTFontGetDWriteWeight(static_cast<CTFontRef>(self));
}

// WinObjC-only extension for compatibility issues between DWrite and Xaml
// Returns the stretch of the font Xaml can use
- (DWRITE_FONT_STRETCH)_fontStretch {
    return _CTFontGetDWriteStretch(static_cast<CTFontRef>(self));
}

// WinObjC-only extension for compatibility issues between DWrite and Xaml
// Returns the style of the font Xaml can use
- (DWRITE_FONT_STYLE)_fontStyle {
    return _CTFontGetDWriteStyle(static_cast<CTFontRef>(self));
}

@end