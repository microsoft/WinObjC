//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import <UIKit/UIKitExport.h>
#import <Foundation/NSObject.h>
#import <CoreGraphics/CGBase.h>

@class NSArray;
@class NSDictionary;

typedef NSInteger NSLayoutRelation;
typedef enum : NSInteger {
    NSLayoutAttributeLeft = 1,
    NSLayoutAttributeRight,
    NSLayoutAttributeTop,
    NSLayoutAttributeBottom,
    NSLayoutAttributeLeading,
    NSLayoutAttributeTrailing,
    NSLayoutAttributeWidth,
    NSLayoutAttributeHeight,
    NSLayoutAttributeCenterX,
    NSLayoutAttributeCenterY,
    NSLayoutAttributeBaseline,
    NSLayoutAttributeLastBaseline = NSLayoutAttributeBaseline,
    NSLayoutAttributeFirstBaseline,
    NSLayoutAttributeLeftMargin,
    NSLayoutAttributeRightMargin,
    NSLayoutAttributeTopMargin,
    NSLayoutAttributeBottomMargin,
    NSLayoutAttributeLeadingMargin,
    NSLayoutAttributeTrailingMargin,
    NSLayoutAttributeCenterXWithinMargins,
    NSLayoutAttributeCenterYWithinMargins,
    NSLayoutAttributeNotAnAttribute = 0
} NSLayoutAttribute;

typedef NSUInteger NSLayoutFormatOptions;
typedef float UILayoutPriority;

enum {
    NSLayoutRelationLessThanOrEqual = -1,
    NSLayoutRelationEqual = 0,
    NSLayoutRelationGreaterThanOrEqual = 1,
};

enum {
    UILayoutPriorityRequired = 1000,
    UILayoutPriorityDefaultHigh = 750,
    UILayoutPriorityDefaultLow = 250,
    UILayoutPriorityFittingSizeLevel = 50,
};

enum {
    /* choose only one of these */
    NSLayoutFormatAlignAllLeft = NSLayoutAttributeLeft,
    NSLayoutFormatAlignAllRight = NSLayoutAttributeRight,
    NSLayoutFormatAlignAllTop = NSLayoutAttributeTop,
    NSLayoutFormatAlignAllBottom = NSLayoutAttributeBottom,
    NSLayoutFormatAlignAllLeading = NSLayoutAttributeLeading,
    NSLayoutFormatAlignAllTrailing = NSLayoutAttributeTrailing,
    NSLayoutFormatAlignAllCenterX = NSLayoutAttributeCenterX,
    NSLayoutFormatAlignAllCenterY = NSLayoutAttributeCenterY,
    NSLayoutFormatAlignAllBaseline = NSLayoutAttributeBaseline,
    NSLayoutFormatAlignmentMask = 0xFF,
    /* choose only one of these three */
    NSLayoutFormatDirectionLeadingToTrailing = 0 << 8, // default
    NSLayoutFormatDirectionLeftToRight = 1 << 8,
    NSLayoutFormatDirectionRightToLeft = 2 << 8,
    NSLayoutFormatDirectionMask = 0x3 << 8,
};

UIKIT_EXPORT_CLASS
@interface NSLayoutConstraint : NSObject <NSCoding>

@property (readonly, assign) id firstItem;
@property (readonly, assign) id secondItem;
@property (readonly) NSLayoutAttribute firstAttribute;
@property (readonly) NSLayoutAttribute secondAttribute;
@property (readonly) CGFloat multiplier;
@property (readonly) NSLayoutRelation relation;
@property UILayoutPriority priority;
@property CGFloat constant;

+ (NSArray*)constraintsWithVisualFormat:(NSString*)format
                                options:(NSLayoutFormatOptions)opts
                                metrics:(NSDictionary*)metrics
                                  views:(NSDictionary*)views;
+ (instancetype)constraintWithItem:(id)view1
                         attribute:(NSLayoutAttribute)attr1
                         relatedBy:(NSLayoutRelation)relation
                            toItem:(id)view2
                         attribute:(NSLayoutAttribute)attr2
                        multiplier:(CGFloat)multiplier
                          constant:(CGFloat)c;

@property (getter=isActive) BOOL active;

+ (void)activateConstraints:(NSArray*)constraints;
+ (void)deactivateConstraints:(NSArray*)constraints;

@property (copy) NSString* identifier;
@property BOOL shouldBeArchived STUB_PROPERTY;

@end
