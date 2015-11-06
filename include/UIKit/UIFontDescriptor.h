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

#ifndef _UIFONTDESCRIPTOR_H_
#define _UIFONTDESCRIPTOR_H_

#import "UIKitExport.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIFontDescriptor.h>

enum {
    UIFontTextStyleBody,
};

extern NSString* UIFontSymbolicTrait;
extern NSString* UIFontDescriptorTraitsAttribute;
extern NSString* UIFontDescriptorFamilyAttribute;

typedef enum : uint32_t {
    /* Typeface info (lower 16 bits of UIFontDescriptorSymbolicTraits ) */
    UIFontDescriptorTraitItalic = 1u << 0,
    UIFontDescriptorTraitBold = 1u << 1,
    UIFontDescriptorTraitExpanded = 1u << 5,
    UIFontDescriptorTraitCondensed = 1u << 6,
    UIFontDescriptorTraitMonoSpace = 1u << 10,
    UIFontDescriptorTraitVertical = 1u << 11,
    UIFontDescriptorTraitUIOptimized = 1u << 12,
    UIFontDescriptorTraitTightLeading = 1u << 15,
    UIFontDescriptorTraitLooseLeading = 1u << 16,

    /* Font appearance info (upper 16 bits of UIFontDescriptorSymbolicTraits */
    UIFontDescriptorClassMask = 0xF0000000,

    UIFontDescriptorClassUnknown = 0u << 28,
    UIFontDescriptorClassOldStyleSerifs = 1u << 28,
    UIFontDescriptorClassTransitionalSerifs = 2u << 28,
    UIFontDescriptorClassModernSerifs = 3u << 28,
    UIFontDescriptorClassClarendonSerifs = 4u << 28,
    UIFontDescriptorClassSlabSerifs = 5u << 28,
    UIFontDescriptorClassFreeformSerifs = 7u << 28,
    UIFontDescriptorClassSansSerif = 8u << 28,
    UIFontDescriptorClassOrnamentals = 9u << 28,
    UIFontDescriptorClassScripts = 10u << 28,
    UIFontDescriptorClassSymbolic = 12u << 28
} UIFontDescriptorSymbolicTraits;

typedef NSUInteger UIFontTextStyle;

UIKIT_EXPORT_CLASS 
@interface UIFontDescriptor : NSObject + (UIFontDescriptor*)preferredFontDescriptorWithTextStyle : (NSUInteger)stytle;
+ (UIFontDescriptor*)fontDescriptorWithName:(NSString*)name size:(CGFloat)size;
+ (UIFontDescriptor*)fontDescriptorWithDescriptor:(UIFontDescriptor*)descriptor size:(CGFloat)size;

- (instancetype)initWithFontAttributes:(NSDictionary*)attributes;

@property (nonatomic) UIFontDescriptorSymbolicTraits symbolicTraits;

@end

#endif // _UIFONTDESCRIPTOR_H_
