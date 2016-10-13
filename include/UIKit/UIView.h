/*
* Copyright (c) 2011, The Iconfactory. All rights reserved.
*
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

#import <UIKit/UIResponder.h>
#import <UIKit/UIGeometry.h>
#import <UIKit/UIAppearance.h>
#import <UIKit/UIAppearanceContainer.h>
#import <UIKit/NSLayoutConstraint.h>
#import <UIKit/UIAccessibility.h>
#import <UIKit/UICoordinateSpace.h>
#import <UIKit/UIDynamicItem.h>
#import <UIKit/UIFocusEnvironment.h>
#import <UIKit/UITraitEnvironment.h>
#import <UIKit/UIApplication.h>

typedef enum {
    UIViewAnimationCurveEaseInOut,
    UIViewAnimationCurveEaseIn,
    UIViewAnimationCurveEaseOut,
    UIViewAnimationCurveLinear,
} UIViewAnimationCurve;

typedef enum {
    UIViewContentModeScaleToFill,
    UIViewContentModeScaleAspectFit,
    UIViewContentModeScaleAspectFill,
    UIViewContentModeRedraw,
    UIViewContentModeCenter,
    UIViewContentModeTop,
    UIViewContentModeBottom,
    UIViewContentModeLeft,
    UIViewContentModeRight,
    UIViewContentModeTopLeft,
    UIViewContentModeTopRight,
    UIViewContentModeBottomLeft,
    UIViewContentModeBottomRight,
} UIViewContentMode;

typedef enum {
    UIViewTintAdjustmentModeAutomatic,
    UIViewTintAdjustmentModeNormal,
    UIViewTintAdjustmentModeDimmed,
} UIViewTintAdjustmentMode;

typedef enum {
    UISystemAnimationDelete,
} UISystemAnimation;

typedef enum {
    UIViewAnimationTransitionNone,
    UIViewAnimationTransitionFlipFromLeft,
    UIViewAnimationTransitionFlipFromRight,
    UIViewAnimationTransitionCurlUp,
    UIViewAnimationTransitionCurlDown,
} UIViewAnimationTransition;

typedef NS_OPTIONS(NSUInteger, UIViewAnimationOptions) {
    UIViewAnimationOptionLayoutSubviews = 1 << 0,
    UIViewAnimationOptionAllowUserInteraction = 1 << 1,
    UIViewAnimationOptionBeginFromCurrentState = 1 << 2,
    UIViewAnimationOptionRepeat = 1 << 3,
    UIViewAnimationOptionAutoreverse = 1 << 4,
    UIViewAnimationOptionOverrideInheritedDuration = 1 << 5,
    UIViewAnimationOptionOverrideInheritedCurve = 1 << 6,
    UIViewAnimationOptionAllowAnimatedContent = 1 << 7,
    UIViewAnimationOptionShowHideTransitionViews = 1 << 8,
    UIViewAnimationOptionOverrideInheritedOptions = 1 << 9,
    UIViewAnimationOptionCurveEaseInOut = 0 << 16,
    UIViewAnimationOptionCurveEaseIn = 1 << 16,
    UIViewAnimationOptionCurveEaseOut = 2 << 16,
    UIViewAnimationOptionCurveLinear = 3 << 16,
    UIViewAnimationOptionTransitionNone = 0 << 20,
    UIViewAnimationOptionTransitionFlipFromLeft = 1 << 20,
    UIViewAnimationOptionTransitionFlipFromRight = 2 << 20,
    UIViewAnimationOptionTransitionCurlUp = 3 << 20,
    UIViewAnimationOptionTransitionCurlDown = 4 << 20,
    UIViewAnimationOptionTransitionCrossDissolve = 5 << 20,
    UIViewAnimationOptionTransitionFlipFromTop = 6 << 20,
    UIViewAnimationOptionTransitionFlipFromBottom = 7 << 20,
};

typedef enum {
    UIViewKeyframeAnimationOptionLayoutSubviews = UIViewAnimationOptionLayoutSubviews,
    UIViewKeyframeAnimationOptionAllowUserInteraction = UIViewAnimationOptionAllowUserInteraction,
    UIViewKeyframeAnimationOptionBeginFromCurrentState = UIViewAnimationOptionBeginFromCurrentState,
    UIViewKeyframeAnimationOptionRepeat = UIViewAnimationOptionRepeat,
    UIViewKeyframeAnimationOptionAutoreverse = UIViewAnimationOptionAutoreverse,
    UIViewKeyframeAnimationOptionOverrideInheritedDuration = UIViewAnimationOptionOverrideInheritedDuration,
    UIViewKeyframeAnimationOptionOverrideInheritedOptions = UIViewAnimationOptionOverrideInheritedOptions,
    UIViewKeyframeAnimationOptionCalculationModeLinear = 0 << 9,
    UIViewKeyframeAnimationOptionCalculationModeDiscrete = 1 << 9,
    UIViewKeyframeAnimationOptionCalculationModePaced = 2 << 9,
    UIViewKeyframeAnimationOptionCalculationModeCubic = 3 << 9,
    UIViewKeyframeAnimationOptionCalculationModeCubicPaced = 4 << 9,
} UIViewKeyframeAnimationOptions;

typedef enum : NSInteger {
    UISemanticContentAttributeUnspecified = 0,
    UISemanticContentAttributePlayback,
    UISemanticContentAttributeSpatial,
    UISemanticContentAttributeForceLeftToRight,
    UISemanticContentAttributeForceRightToLeft,
} UISemanticContentAttribute;

typedef NSUInteger UIViewAutoresizing;
enum {
    UIViewAutoresizingNone = 0,
    UIViewAutoresizingFlexibleLeftMargin = 1 << 0,
    UIViewAutoresizingFlexibleWidth = 1 << 1,
    UIViewAutoresizingFlexibleRightMargin = 1 << 2,
    UIViewAutoresizingFlexibleTopMargin = 1 << 3,
    UIViewAutoresizingFlexibleHeight = 1 << 4,
    UIViewAutoresizingFlexibleBottomMargin = 1 << 5,
};

typedef NSInteger UILayoutConstraintAxis;
enum {
    UILayoutConstraintAxisHorizontal = 0,
    UILayoutConstraintAxisVertical = 1,
};

UIKIT_EXPORT const CGSize UILayoutFittingCompressedSize;
UIKIT_EXPORT const CGSize UILayoutFittingExpandedSize;
UIKIT_EXPORT const CGFloat UIViewNoIntrinsicMetric;

@class UIColor, CALayer, NSArray, UIWindow, NSLayoutYAxisAnchor, NSLayoutXAxisAnchor, NSLayoutDimension, UILayoutGuide,
    UIViewPrintFormatter, UIGestureRecognizer, NSString, NSDate, UIMotionEffect, NSCoder, UIEvent;

UIKIT_EXPORT_CLASS
@interface UIView : UIResponder <UIAccessibility,
                                 NSCoding,
                                 NSObject,
                                 UIAppearance,
                                 UIAppearanceContainer,
                                 UICoordinateSpace,
                                 UIDynamicItem,
                                 UIFocusEnvironment,
                                 UITraitEnvironment> {
@public
    id _backButtonDelegate;
    SEL _backButtonSelector;
    id _backButtonArg;
    BOOL _backButtonReturnsSuccess;
    int _backButtonPriority;
}

+ (BOOL)areAnimationsEnabled;
+ (BOOL)requiresConstraintBasedLayout STUB_METHOD;
+ (Class)layerClass;

+ (NSTimeInterval)inheritedAnimationDuration STUB_METHOD;
+ (UIUserInterfaceLayoutDirection)userInterfaceLayoutDirectionForSemanticContentAttribute:(UISemanticContentAttribute)attribute STUB_METHOD;
+ (void)addKeyframeWithRelativeStartTime:(double)frameStartTime
                        relativeDuration:(double)frameDuration
                              animations:(void (^)(void))animations;
+ (void)animateKeyframesWithDuration:(NSTimeInterval)duration
                               delay:(NSTimeInterval)delay
                             options:(UIViewKeyframeAnimationOptions)options
                          animations:(void (^)(void))animations
                          completion:(void (^)(BOOL))completion;
+ (void)animateWithDuration:(NSTimeInterval)duration animations:(void (^)(void))animations completion:(void (^)(BOOL finished))completion;
+ (void)animateWithDuration:(NSTimeInterval)duration animations:(void (^)(void))animations;
+ (void)animateWithDuration:(NSTimeInterval)duration
                      delay:(NSTimeInterval)delay
                    options:(UIViewAnimationOptions)options
                 animations:(void (^)(void))animations
                 completion:(void (^)(BOOL finished))completion;
+ (void)animateWithDuration:(NSTimeInterval)duration
                      delay:(NSTimeInterval)delay
     usingSpringWithDamping:(CGFloat)dampingRatio
      initialSpringVelocity:(CGFloat)velocity
                    options:(UIViewAnimationOptions)options
                 animations:(void (^)(void))animations
                 completion:(void (^)(BOOL finished))completion;
+ (void)beginAnimations:(NSString*)animationID context:(void*)context;
+ (void)commitAnimations;
+ (void)performSystemAnimation:(UISystemAnimation)animation
                       onViews:(NSArray*)views
                       options:(UIViewAnimationOptions)options
                    animations:(void (^)(void))parallelAnimations
                    completion:(void (^)(BOOL))completion STUB_METHOD;
+ (void)performWithoutAnimation:(void (^)(void))actionsWithoutAnimation;
+ (void)setAnimationBeginsFromCurrentState:(BOOL)beginFromCurrentState;
+ (void)setAnimationCurve:(UIViewAnimationCurve)curve;
+ (void)setAnimationDelay:(NSTimeInterval)delay;
+ (void)setAnimationDelegate:(id)delegate;
+ (void)setAnimationDidStopSelector:(SEL)selector;
+ (void)setAnimationDuration:(NSTimeInterval)duration;
+ (void)setAnimationRepeatAutoreverses:(BOOL)repeatAutoreverses;
+ (void)setAnimationRepeatCount:(float)repeatCount;
+ (void)setAnimationStartDate:(NSDate*)startTime STUB_METHOD;
+ (void)setAnimationTransition:(UIViewAnimationTransition)transition forView:(UIView*)view cache:(BOOL)cache;
+ (void)setAnimationWillStartSelector:(SEL)selector;
+ (void)setAnimationsEnabled:(BOOL)enabled;
+ (void)transitionFromView:(UIView*)fromView
                    toView:(UIView*)toView
                  duration:(NSTimeInterval)duration
                   options:(UIViewAnimationOptions)options
                completion:(void (^)(BOOL finished))completion;
+ (void)transitionWithView:(UIView*)view
                  duration:(NSTimeInterval)duration
                   options:(UIViewAnimationOptions)options
                animations:(void (^)(void))animations
                completion:(void (^)(BOOL finished))completion;
- (BOOL)canBecomeFocused STUB_METHOD;
- (BOOL)drawViewHierarchyInRect:(CGRect)rect afterScreenUpdates:(BOOL)afterUpdates STUB_METHOD;
- (BOOL)endEditing:(BOOL)force;
- (BOOL)gestureRecognizerShouldBegin:(UIGestureRecognizer*)gestureRecognizer;
- (BOOL)hasAmbiguousLayout STUB_METHOD;
- (BOOL)isDescendantOfView:(UIView*)view;
- (BOOL)needsUpdateConstraints;
- (BOOL)pointInside:(CGPoint)point withEvent:(UIEvent*)event;
- (CGPoint)convertPoint:(CGPoint)toConvert fromView:(UIView*)fromView;
- (CGPoint)convertPoint:(CGPoint)toConvert toView:(UIView*)toView;
- (CGRect)alignmentRectForFrame:(CGRect)frame STUB_METHOD;
- (CGRect)convertRect:(CGRect)toConvert fromView:(UIView*)fromView;
- (CGRect)convertRect:(CGRect)toConvert toView:(UIView*)toView;
- (CGRect)frameForAlignmentRect:(CGRect)alignmentRect STUB_METHOD;
- (CGSize)intrinsicContentSize;
- (CGSize)sizeThatFits:(CGSize)size;
- (CGSize)systemLayoutSizeFittingSize:(CGSize)targetSize STUB_METHOD;
- (CGSize)systemLayoutSizeFittingSize:(CGSize)targetSize
        withHorizontalFittingPriority:(UILayoutPriority)horizontalFittingPriority
              verticalFittingPriority:(UILayoutPriority)verticalFittingPriority STUB_METHOD;
- (NSArray*)constraintsAffectingLayoutForAxis:(UILayoutConstraintAxis)axis STUB_METHOD;
- (UIEdgeInsets)alignmentRectInsets STUB_METHOD;
- (UILayoutPriority)contentCompressionResistancePriorityForAxis:(UILayoutConstraintAxis)axis;
- (UILayoutPriority)contentHuggingPriorityForAxis:(UILayoutConstraintAxis)axis;
- (UIView*)hitTest:(CGPoint)point withEvent:(UIEvent*)event;
- (UIView*)resizableSnapshotViewFromRect:(CGRect)rect afterScreenUpdates:(BOOL)afterUpdates withCapInsets:(UIEdgeInsets)capInsets;
- (UIView*)snapshotViewAfterScreenUpdates:(BOOL)afterUpdates;
- (UIView*)viewForBaselineLayout;
- (UIView*)viewWithTag:(NSInteger)tag;
- (UIViewPrintFormatter*)viewPrintFormatter STUB_METHOD;
- (instancetype)initWithFrame:(CGRect)aRect;
- (void)addConstraint:(NSLayoutConstraint*)constraint;
- (void)addConstraints:(NSArray*)constraints;
- (void)addGestureRecognizer:(UIGestureRecognizer*)gestureRecognizer;
- (void)addLayoutGuide:(UILayoutGuide*)layoutGuide;
- (void)addMotionEffect:(UIMotionEffect*)effect STUB_METHOD;
- (void)addSubview:(UIView*)subview;
- (void)bringSubviewToFront:(UIView*)subview;
- (void)decodeRestorableStateWithCoder:(NSCoder*)coder STUB_METHOD;
- (void)didAddSubview:(UIView*)subview;
- (void)didMoveToSuperview;
- (void)didMoveToWindow;
- (void)drawRect:(CGRect)area forViewPrintFormatter:(UIViewPrintFormatter*)formatter STUB_METHOD;
- (void)drawRect:(CGRect)rect;
- (void)encodeRestorableStateWithCoder:(NSCoder*)coder STUB_METHOD;
- (void)exchangeSubviewAtIndex:(NSInteger)index1 withSubviewAtIndex:(NSInteger)index2;
- (void)exerciseAmbiguityInLayout STUB_METHOD;
- (void)insertSubview:(UIView*)subview aboveSubview:(UIView*)above;
- (void)insertSubview:(UIView*)subview atIndex:(NSInteger)index;
- (void)insertSubview:(UIView*)subview belowSubview:(UIView*)below;
- (void)invalidateIntrinsicContentSize;
- (void)layoutIfNeeded;
- (void)layoutMarginsDidChange STUB_METHOD;
- (void)layoutSubviews;
- (void)removeConstraint:(NSLayoutConstraint*)constraint;
- (void)removeConstraints:(NSArray*)constraints;
- (void)removeFromSuperview;
- (void)removeGestureRecognizer:(UIGestureRecognizer*)gestureRecognizer;
- (void)removeLayoutGuide:(UILayoutGuide*)layoutGuide;
- (void)removeMotionEffect:(UIMotionEffect*)effect STUB_METHOD;
- (void)sendSubviewToBack:(UIView*)subview;
- (void)setContentCompressionResistancePriority:(UILayoutPriority)priority forAxis:(UILayoutConstraintAxis)axis;
- (void)setContentHuggingPriority:(UILayoutPriority)priority forAxis:(UILayoutConstraintAxis)axis;
- (void)setNeedsDisplay;
- (void)setNeedsDisplayInRect:(CGRect)invalidRect;
- (void)setNeedsLayout;
- (void)setNeedsUpdateConstraints;
- (void)sizeToFit;
- (void)tintColorDidChange STUB_METHOD;
- (void)updateConstraints;
- (void)updateConstraintsIfNeeded;
- (void)willMoveToSuperview:(UIView*)newSuperview;
- (void)willMoveToWindow:(UIWindow*)newWindow;
- (void)willRemoveSubview:(UIView*)subview;

// the block-based transition methods are not currently implemented
@property (copy, nonatomic) NSArray* motionEffects;
@property (copy, nonatomic) NSString* restorationIdentifier STUB_PROPERTY;
@property (nonatomic) BOOL autoresizesSubviews;
@property (nonatomic) BOOL clearsContextBeforeDrawing STUB_PROPERTY;
@property (nonatomic) BOOL clipsToBounds;
@property (nonatomic) BOOL preservesSuperviewLayoutMargins STUB_PROPERTY;
@property (nonatomic) BOOL translatesAutoresizingMaskIntoConstraints;
@property (nonatomic) CGAffineTransform transform;
@property (nonatomic) CGFloat alpha;
@property (nonatomic) CGFloat contentScaleFactor;
@property (nonatomic) CGPoint center;
@property (nonatomic) CGRect bounds;
@property (nonatomic) CGRect contentStretch;
@property (nonatomic) CGRect frame;
@property (nonatomic) NSInteger tag;
@property (nonatomic) UIEdgeInsets layoutMargins STUB_PROPERTY;
@property (nonatomic) UISemanticContentAttribute semanticContentAttribute STUB_PROPERTY;
@property (nonatomic) UIViewAutoresizing autoresizingMask;
@property (nonatomic) UIViewContentMode contentMode;
@property (nonatomic) UIViewTintAdjustmentMode tintAdjustmentMode STUB_PROPERTY;
@property (nonatomic, copy) NSArray* gestureRecognizers;
@property (nonatomic, copy) UIColor* backgroundColor;
@property (nonatomic, getter=isExclusiveTouch) BOOL exclusiveTouch STUB_PROPERTY;
@property (nonatomic, getter=isHidden) BOOL hidden;
@property (nonatomic, getter=isMultipleTouchEnabled) BOOL multipleTouchEnabled;
@property (nonatomic, getter=isOpaque) BOOL opaque;
@property (nonatomic, getter=isUserInteractionEnabled) BOOL userInteractionEnabled;
@property (nonatomic, readonly) CALayer* layer;
@property (nonatomic, readonly) NSArray* subviews;
@property (nonatomic, readonly) UIView* superview;
@property (nonatomic, readonly) UIWindow* window;
@property (nonatomic, retain) UIColor* tintColor;
@property (nonatomic, strong) UIView* maskView STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSArray* layoutGuides STUB_PROPERTY;
@property (readonly, getter=isFocused, nonatomic) BOOL focused STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* constraints;
@property (readonly, nonatomic, strong) UILayoutGuide* readableContentGuide STUB_PROPERTY;
@property (readonly, strong) NSLayoutDimension* heightAnchor;
@property (readonly, strong) NSLayoutDimension* widthAnchor;
@property (readonly, strong) NSLayoutXAxisAnchor* centerXAnchor;
@property (readonly, strong) NSLayoutXAxisAnchor* leadingAnchor;
@property (readonly, strong) NSLayoutXAxisAnchor* leftAnchor;
@property (readonly, strong) NSLayoutXAxisAnchor* rightAnchor;
@property (readonly, strong) NSLayoutXAxisAnchor* trailingAnchor;
@property (readonly, strong) NSLayoutYAxisAnchor* bottomAnchor;
@property (readonly, strong) NSLayoutYAxisAnchor* centerYAnchor;
@property (readonly, strong) NSLayoutYAxisAnchor* firstBaselineAnchor;
@property (readonly, strong) NSLayoutYAxisAnchor* lastBaselineAnchor;
@property (readonly, strong) NSLayoutYAxisAnchor* topAnchor;
@property (readonly, strong) UILayoutGuide* layoutMarginsGuide STUB_PROPERTY;
@property (readonly, strong) UIView* viewForFirstBaselineLayout STUB_PROPERTY;
@property (readonly, strong) UIView* viewForLastBaselineLayout STUB_PROPERTY;

// UIAccessibility properties.
@property BOOL isAccessibilityElement;
@property (copy) NSString* accessibilityLabel;
@property (copy) NSString* accessibilityHint;
@property (copy) NSString* accessibilityValue;
@property UIAccessibilityTraits accessibilityTraits;
@property UIAccessibilityNavigationStyle accessibilityNavigationStyle;
@property (nonatomic) CGRect accessibilityFrame;
@property (copy) UIBezierPath* accessibilityPath;
@property CGPoint accessibilityActivationPoint;
@property (retain) NSString* accessibilityLanguage;
@property BOOL accessibilityElementsHidden;
@property BOOL shouldGroupAccessibilityChildren;
@property BOOL accessibilityViewIsModal;
@property (copy) NSString* accessibilityIdentifier;
@end

// WinObjC Xaml Extensions
@class WXFrameworkElement;
@interface UIView (UIKitXamlExtensions)
@property (nonatomic, retain) WXFrameworkElement* xamlElement;
@end

@interface UIView (StarboardActions)
- (void)setBackButtonDelegate:(id)delegate action:(SEL)action withParam:(id)param;
- (void)setBackButtonReturnsSuccess:(BOOL)returnsSuccess;
- (void)setBackButtonPriority:(int)priority;
@end
