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
#import <UIKit/UIFontDescriptor.h>

#import <Foundation/NSNumber.h>

#import <NSRaise.h>
#import <BridgeHelpers.h>

#import "UICTFontDescriptor.h"

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

NSString* const UIFontDescriptorFamilyAttribute = static_cast<NSString*>(kCTFontFamilyNameAttribute);
NSString* const UIFontDescriptorNameAttribute = static_cast<NSString*>(kCTFontNameAttribute);
NSString* const UIFontDescriptorFaceAttribute = static_cast<NSString*>(kCTFontStyleNameAttribute);
NSString* const UIFontDescriptorSizeAttribute = static_cast<NSString*>(kCTFontSizeAttribute);
NSString* const UIFontDescriptorVisibleNameAttribute = static_cast<NSString*>(kCTFontDisplayNameAttribute);
NSString* const UIFontDescriptorMatrixAttribute = static_cast<NSString*>(kCTFontMatrixAttribute);
NSString* const UIFontDescriptorCharacterSetAttribute = static_cast<NSString*>(kCTFontCharacterSetAttribute);
NSString* const UIFontDescriptorCascadeListAttribute = static_cast<NSString*>(kCTFontCascadeListAttribute);
NSString* const UIFontDescriptorTraitsAttribute = static_cast<NSString*>(kCTFontTraitsAttribute);
NSString* const UIFontDescriptorFixedAdvanceAttribute = static_cast<NSString*>(kCTFontFixedAdvanceAttribute);
NSString* const UIFontDescriptorFeatureSettingsAttribute = static_cast<NSString*>(kCTFontFeatureSettingsAttribute);
NSString* const UIFontDescriptorTextStyleAttribute = @"NSCTFontUIUsageAttribute"; // This matches the reference platform

NSString* const UIFontSymbolicTrait = static_cast<NSString*>(kCTFontSymbolicTrait);
NSString* const UIFontWeightTrait = static_cast<NSString*>(kCTFontWeightTrait);
NSString* const UIFontWidthTrait = static_cast<NSString*>(kCTFontWidthTrait);
NSString* const UIFontSlantTrait = static_cast<NSString*>(kCTFontSlantTrait);

NSString* const UIFontFeatureTypeIdentifierKey = @"CTFeatureTypeIdentifier";
NSString* const UIFontFeatureSelectorIdentifierKey = @"CTFeatureSelectorIdentifier";

const CGFloat UIFontWeightUltraLight = kCTFontWeightUltraLight;
const CGFloat UIFontWeightThin = kCTFontWeightThin;
const CGFloat UIFontWeightLight = kCTFontWeightLight;
const CGFloat UIFontWeightRegular = kCTFontWeightRegular;
const CGFloat UIFontWeightMedium = kCTFontWeightMedium;
const CGFloat UIFontWeightSemibold = kCTFontWeightSemibold;
const CGFloat UIFontWeightBold = kCTFontWeightBold;
const CGFloat UIFontWeightHeavy = kCTFontWeightHeavy;
const CGFloat UIFontWeightBlack = kCTFontWeightBlack;

@implementation UIFontDescriptor

BASE_CLASS_REQUIRED_IMPLS(UIFontDescriptor, UIFontDescriptorPrototype, CTFontDescriptorGetTypeID);

/**
 @Status Caveat
 @Notes  Force to use default font name and size.
*/
+ (UIFontDescriptor*)preferredFontDescriptorWithTextStyle:(NSString*)style {
    return [UIFontDescriptor fontDescriptorWithName:nil size:0.0];
}

/**
 @Status Interoperable
*/
+ (UIFontDescriptor*)fontDescriptorWithFontAttributes:(NSDictionary*)attributes {
    return [[[self alloc] initWithFontAttributes:attributes] autorelease];
}

/**
 @Status Interoperable
*/
+ (UIFontDescriptor*)fontDescriptorWithName:(NSString*)fontName matrix:(CGAffineTransform)matrix {
    return [self fontDescriptorWithFontAttributes:@{
        UIFontDescriptorNameAttribute : fontName,
        UIFontDescriptorMatrixAttribute : [NSData dataWithBytes:reinterpret_cast<byte*>(&matrix) length:sizeof(CGAffineTransform)]
    }];
}

/**
 @Status Interoperable
*/
+ (UIFontDescriptor*)fontDescriptorWithName:(NSString*)fontName size:(CGFloat)size {
    return [self fontDescriptorWithFontAttributes:@{
        UIFontDescriptorNameAttribute : fontName,
        UIFontDescriptorSizeAttribute : [NSNumber numberWithFloat:size]
    }];
}

/**
 @Status Interoperable
*/
- (UIFontDescriptor*)fontDescriptorByAddingAttributes:(NSDictionary*)attributes {
    NSMutableDictionary* newAttributes = [[[self fontAttributes] mutableCopy] autorelease];
    [newAttributes addEntriesFromDictionary:attributes];
    return [UIFontDescriptor fontDescriptorWithFontAttributes:newAttributes];
}

/**
 @Status Interoperable
*/
- (UIFontDescriptor*)fontDescriptorWithFace:(NSString*)newFace {
    return [self fontDescriptorByAddingAttributes:@{ UIFontDescriptorFaceAttribute : newFace }];
}

/**
 @Status Interoperable
*/
- (UIFontDescriptor*)fontDescriptorWithFamily:(NSString*)newFamily {
    NSMutableDictionary* newAttributes = [[[self fontAttributes] mutableCopy] autorelease];

    [newAttributes removeObjectForKey:UIFontDescriptorNameAttribute];
    [newAttributes setObject:newFamily forKey:UIFontDescriptorFamilyAttribute];

    return [UIFontDescriptor fontDescriptorWithFontAttributes:newAttributes];
}

/**
 @Status Interoperable
*/
- (UIFontDescriptor*)fontDescriptorWithMatrix:(CGAffineTransform)matrix {
    return [self fontDescriptorByAddingAttributes:@{
        UIFontDescriptorMatrixAttribute : [NSData dataWithBytes:reinterpret_cast<byte*>(&matrix) length:sizeof(CGAffineTransform)]
    }];
}

/**
 @Status Interoperable
*/
- (UIFontDescriptor*)fontDescriptorWithSize:(CGFloat)newPointSize {
    return [self fontDescriptorByAddingAttributes:@{ UIFontDescriptorSizeAttribute : [NSNumber numberWithFloat:newPointSize] }];
}

/**
 @Status Stub
*/
- (UIFontDescriptor*)fontDescriptorWithSymbolicTraits:(UIFontDescriptorSymbolicTraits)symbolicTraits {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFontAttributes:(NSDictionary*)attributes {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Stub
*/
- (NSArray*)matchingFontDescriptorsWithMandatoryKeys:(NSSet*)mandatoryKeys {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (NSDictionary<NSString*, id>*)fontAttributes {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (CGAffineTransform)matrix {
    NSData* data = [self objectForKey:UIFontDescriptorMatrixAttribute];
    if (data) {
        CGAffineTransform ret;
        [data getBytes:reinterpret_cast<byte*>(&ret) length:sizeof(CGAffineTransform)];
        return ret;
    } else {
        // Identity matrix seems like a decent default return
        return CGAffineTransformIdentity;
    }
}

/**
 @Status Interoperable
*/
- (id)objectForKey:(NSString*)anAttribute {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (CGFloat)pointSize {
    NSObject* pointSize = [self objectForKey:UIFontDescriptorSizeAttribute];
    return [pointSize isKindOfClass:[NSNumber class]] ? static_cast<NSNumber*>(pointSize).floatValue : 0.0;
}

/**
 @Status Interoperable
*/
- (UIFontDescriptorSymbolicTraits)symbolicTraits {
    NSDictionary* traits = [self objectForKey:UIFontDescriptorTraitsAttribute];
    if (traits) {
        NSNumber* symbolicTraits = [traits objectForKey:UIFontSymbolicTrait];

        if (symbolicTraits) {
            return [symbolicTraits unsignedIntValue];
        }
    }
    return 0;
}

/**
 @Status Stub
*/
- (instancetype)copyWithZone:(NSZone*)zone {
    UNIMPLEMENTED();
    return StubReturn();
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
