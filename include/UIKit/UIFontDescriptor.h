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

#pragma once

#import "UIKitExport.h"
#import <Foundation/Foundation.h>
#import <CoreGraphics/CGAffineTransform.h>
#import <UIKit/UIFontDescriptor.h>

@class NSString;
@class NSDictionary;
@class NSArray;
@class NSSet;

typedef NSUInteger UIFontDescriptorClass;
enum {
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
    UIFontDescriptorClassSymbolic = 12u << 28,
};

typedef NSUInteger UIFontDescriptorSymbolicTraits;

UIKIT_EXPORT NSString* const UIFontTextStyleTitle1;
UIKIT_EXPORT NSString* const UIFontTextStyleTitle2;
UIKIT_EXPORT NSString* const UIFontTextStyleTitle3;
UIKIT_EXPORT NSString* const UIFontTextStyleHeadline;
UIKIT_EXPORT NSString* const UIFontTextStyleSubheadline;
UIKIT_EXPORT NSString* const UIFontTextStyleBody;
UIKIT_EXPORT NSString* const UIFontTextStyleFootnote;
UIKIT_EXPORT NSString* const UIFontTextStyleCaption1;
UIKIT_EXPORT NSString* const UIFontTextStyleCaption2;
UIKIT_EXPORT NSString* const UIFontTextStyleCallout;
UIKIT_EXPORT NSString* const UIFontDescriptorFamilyAttribute;
UIKIT_EXPORT NSString* const UIFontDescriptorNameAttribute;
UIKIT_EXPORT NSString* const UIFontDescriptorFaceAttribute;
UIKIT_EXPORT NSString* const UIFontDescriptorSizeAttribute;
UIKIT_EXPORT NSString* const UIFontDescriptorVisibleNameAttribute;
UIKIT_EXPORT NSString* const UIFontDescriptorMatrixAttribute;
UIKIT_EXPORT NSString* const UIFontDescriptorCharacterSetAttribute;
UIKIT_EXPORT NSString* const UIFontDescriptorCascadeListAttribute;
UIKIT_EXPORT NSString* const UIFontDescriptorTraitsAttribute;
UIKIT_EXPORT NSString* const UIFontDescriptorFixedAdvanceAttribute;
UIKIT_EXPORT NSString* const UIFontDescriptorFeatureSettingsAttribute;
UIKIT_EXPORT NSString* const UIFontDescriptorTextStyleAttribute;
UIKIT_EXPORT NSString* const UIFontSymbolicTrait;
UIKIT_EXPORT NSString* const UIFontWeightTrait;
UIKIT_EXPORT NSString* const UIFontWidthTrait;
UIKIT_EXPORT NSString* const UIFontSlantTrait;
UIKIT_EXPORT const CGFloat UIFontWeightUltraLight;
UIKIT_EXPORT const CGFloat UIFontWeightThin;
UIKIT_EXPORT const CGFloat UIFontWeightLight;
UIKIT_EXPORT const CGFloat UIFontWeightRegular;
UIKIT_EXPORT const CGFloat UIFontWeightMedium;
UIKIT_EXPORT const CGFloat UIFontWeightSemibold;
UIKIT_EXPORT const CGFloat UIFontWeightBold;
UIKIT_EXPORT const CGFloat UIFontWeightHeavy;
UIKIT_EXPORT const CGFloat UIFontWeightBlack;
UIKIT_EXPORT NSString* const UIFontFeatureTypeIdentifierKey;
UIKIT_EXPORT NSString* const UIFontFeatureSelectorIdentifierKey;

UIKIT_EXPORT_CLASS
@interface UIFontDescriptor : NSObject <NSCopying, NSObject, NSSecureCoding>
+ (UIFontDescriptor*)preferredFontDescriptorWithTextStyle:(NSString*)style;
+ (UIFontDescriptor*)fontDescriptorWithFontAttributes:(NSDictionary*)attributes;
+ (UIFontDescriptor*)fontDescriptorWithName:(NSString*)fontName matrix:(CGAffineTransform)matrix;
+ (UIFontDescriptor*)fontDescriptorWithName:(NSString*)fontName size:(CGFloat)size;
- (UIFontDescriptor*)fontDescriptorByAddingAttributes:(NSDictionary*)attributes;
- (UIFontDescriptor*)fontDescriptorWithFace:(NSString*)newFace;
- (UIFontDescriptor*)fontDescriptorWithFamily:(NSString*)newFamily;
- (UIFontDescriptor*)fontDescriptorWithMatrix:(CGAffineTransform)matrix;
- (UIFontDescriptor*)fontDescriptorWithSize:(CGFloat)newPointSize;
- (UIFontDescriptor*)fontDescriptorWithSymbolicTraits:(UIFontDescriptorSymbolicTraits)symbolicTraits STUB_METHOD;
- (instancetype)initWithFontAttributes:(NSDictionary*)attributes;
- (NSArray*)matchingFontDescriptorsWithMandatoryKeys:(NSSet*)mandatoryKeys STUB_METHOD;
- (NSDictionary<NSString*, id>*)fontAttributes;
@property (readonly, nonatomic) CGAffineTransform matrix;
- (id)objectForKey:(NSString*)anAttribute;
@property (readonly, nonatomic) CGFloat pointSize;
@property (readonly, nonatomic) NSString* postscriptName STUB_PROPERTY;
@property (readonly, nonatomic) UIFontDescriptorSymbolicTraits symbolicTraits;
@end
