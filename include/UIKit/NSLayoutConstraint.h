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

#ifndef _NSLAYOUTCONSTRAINT_H_
#define _NSLAYOUTCONSTRAINT_H_

#import "UIKitExport.h"
#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>

#define NSDictionaryOfVariableBindings(...) _NSDictionaryOfVariableBindings(@"" # __VA_ARGS__, __VA_ARGS__, nil)
SB_EXPORT NSDictionary* _NSDictionaryOfVariableBindings(NSString *keysString, ...);

enum {
    UILayoutPriorityRequired = 1000,
    UILayoutPriorityDefaultHigh = 750,
    UILayoutPriorityDefaultLow = 250,
    UILayoutPriorityFittingSizeLevel = 50,
};
typedef float UILayoutPriority;

enum {
    NSLayoutPriorityRequired = 1000,
    NSLayoutPriorityDefaultHigh = 750,
    NSLayoutPriorityDragThatCanResizeWindow = 510,
    NSLayoutPriorityWindowSizeStayPut = 500,
    NSLayoutPriorityDragThatCannotResizeWindow = 490,
    NSLayoutPriorityDefaultLow = 250,
    NSLayoutPriorityFittingSizeCompression = 50,
};
typedef float NSLayoutPriority;

typedef enum {
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

typedef enum {
	NSLayoutConstraintOrientationHorizontal = 0,
	NSLayoutConstraintOrientationVertical = 1
} NSLayoutConstraintOrientation;


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
typedef uint32_t NSLayoutFormatOptions;

typedef enum {
    NSLayoutRelationLessThanOrEqual = -1,
    NSLayoutRelationEqual = 0,
    NSLayoutRelationGreaterThanOrEqual = 1,
} NSLayoutRelation;

@class NSDictionary, NSArray;

UIKIT_EXPORT_CLASS
@interface NSLayoutConstraint : NSObject<NSCoding> 

@property (readonly, assign) id firstItem;
@property (readonly, assign) id secondItem;
@property (readonly) NSLayoutAttribute firstAttribute;
@property (readonly) NSLayoutAttribute secondAttribute;
@property (readonly) CGFloat multiplier;
@property (readonly) NSLayoutRelation relation;
@property NSLayoutPriority priority;
@property CGFloat constant;

+ (NSArray *)constraintsWithVisualFormat:(NSString *)format options:(NSLayoutFormatOptions)opts metrics:(NSDictionary *)metrics views:(NSDictionary *)views;
+ (instancetype)constraintWithItem:(id)view1 attribute:(NSLayoutAttribute)attr1 relatedBy:(NSLayoutRelation)relation toItem:(id)view2 attribute:(NSLayoutAttribute)attr2 multiplier:(CGFloat)multiplier constant:(CGFloat)c;

@end

#endif /* _NSLAYOUTCONSTRAINT_H_ */
