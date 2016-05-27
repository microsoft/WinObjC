/*
 * Copyright (c) 2011, The Iconfactory. All rights reserved.
 * Copyright (c) 2016 Microsoft Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of The Iconfactory nor the names of its contributors may
 *    be used to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE ICONFACTORY BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#import <Foundation/Foundation.h>
#import <ApplicationServices/ApplicationServices.h>
#import <UIKit/UIKitExport.h>

typedef struct UIEdgeInsets {
    CGFloat top, left, bottom, right; // specify amount to inset (positive) for each of the edges. values can be negative to 'outset'
} UIEdgeInsets;

typedef struct UIOffset { CGFloat horizontal, vertical; } UIOffset;

// [todo] What is this? I can't find it in the docs
typedef struct UIFloatRange { CGFloat minimum, maximum; } UIFloatRange;

static inline UIEdgeInsets UIEdgeInsetsMake(CGFloat top, CGFloat left, CGFloat bottom, CGFloat right) {
    return (UIEdgeInsets){ top, left, bottom, right };
}

static inline CGRect UIEdgeInsetsInsetRect(CGRect rect, UIEdgeInsets insets) {
    rect.origin.x += insets.left;
    rect.origin.y += insets.top;
    rect.size.width -= (insets.left + insets.right);
    rect.size.height -= (insets.top + insets.bottom);
    return rect;
}

static inline BOOL UIEdgeInsetsEqualToEdgeInsets(UIEdgeInsets insets1, UIEdgeInsets insets2) {
    return CGRectEqualToRect(CGRectMake(insets1.left, insets1.top, insets1.right, insets1.bottom),
                             CGRectMake(insets2.left, insets2.top, insets2.right, insets2.bottom));
}

UIKIT_EXPORT const UIEdgeInsets UIEdgeInsetsZero;

static inline UIOffset UIOffsetMake(CGFloat horizontal, CGFloat vertical) {
    return (UIOffset){ horizontal, vertical };
}

static inline BOOL UIOffsetEqualToOffset(UIOffset offset1, UIOffset offset2) {
    return offset1.horizontal == offset2.horizontal && offset1.vertical == offset2.vertical;
}

UIKIT_EXPORT const UIOffset UIOffsetZero;

UIKIT_EXPORT NSString* NSStringFromCGPoint(CGPoint p);
UIKIT_EXPORT NSString* NSStringFromCGRect(CGRect r);
UIKIT_EXPORT NSString* NSStringFromCGSize(CGSize s);

UIKIT_EXPORT NSString* NSStringFromCGAffineTransform(CGAffineTransform transform);

UIKIT_EXPORT NSString* NSStringFromUIEdgeInsets(UIEdgeInsets insets);

UIKIT_EXPORT NSString* NSStringFromUIOffset(UIOffset offset);

UIKIT_EXPORT CGRect CGRectFromString(NSString* string);
UIKIT_EXPORT CGPoint CGPointFromString(NSString* string);
UIKIT_EXPORT CGSize CGSizeFromString(NSString* string);

@interface NSCoder (UIGeometryKeyedCoding)

- (void)encodeCGSize:(CGSize)size forKey:(NSString*)key;
- (void)encodeCGPoint:(CGPoint)point forKey:(NSString*)key;
- (void)encodeCGRect:(CGRect)rect forKey:(NSString*)key;
- (void)encodeCGVector:(CGVector)vector forKey:(NSString*)key;
- (void)encodeCGAffineTransform:(CGAffineTransform)transform forKey:(NSString*)key;
- (void)encodeUIEdgeInsets:(UIEdgeInsets)insets forKey:(NSString*)key;
- (void)encodeUIOffset:(UIOffset)offset forKey:(NSString*)key;
- (CGSize)decodeCGSizeForKey:(NSString*)key;
- (CGPoint)decodeCGPointForKey:(NSString*)key;
- (CGRect)decodeCGRectForKey:(NSString*)key;
- (CGVector)decodeCGVectorForKey:(NSString*)key;
- (CGAffineTransform)decodeCGAffineTransformForKey:(NSString*)key;
- (UIEdgeInsets)decodeUIEdgeInsetsForKey:(NSString*)key;
- (UIOffset)decodeUIOffsetForKey:(NSString*)key;

@end

typedef enum : NSUInteger {
    UIRectEdgeNone = 0,
    UIRectEdgeTop = 0x01,
    UIRectEdgeLeft = 0x02,
    UIRectEdgeBottom = 0x04,
    UIRectEdgeRight = 0x08,
    UIRectEdgeAll = UIRectEdgeTop | UIRectEdgeLeft | UIRectEdgeBottom | UIRectEdgeRight
} UIRectEdge;
