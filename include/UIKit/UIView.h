/*
 * Copyright (c) 2011, The Iconfactory. All rights reserved.
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

 #ifndef _UIVIEW_H_
 #define _UIVIEW_H_

#import "UIResponder.h"
#import "UIGeometry.h"
#import "UIAppearance.h"
#import "NSLayoutConstraint.h"

enum {
    UIViewAutoresizingNone                 = 0,
    UIViewAutoresizingFlexibleLeftMargin   = 1 << 0,
    UIViewAutoresizingFlexibleWidth        = 1 << 1,
    UIViewAutoresizingFlexibleRightMargin  = 1 << 2,
    UIViewAutoresizingFlexibleTopMargin    = 1 << 3,
    UIViewAutoresizingFlexibleHeight       = 1 << 4,
    UIViewAutoresizingFlexibleBottomMargin = 1 << 5
};
typedef NSUInteger UIViewAutoresizing;

enum {
	UILayoutConstraintAxisHorizontal = 0,
	UILayoutConstraintAxisVertical = 1
};
typedef NSInteger UILayoutConstraintAxis;

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
    UIViewAnimationCurveEaseInOut,
    UIViewAnimationCurveEaseIn,
    UIViewAnimationCurveEaseOut,
    UIViewAnimationCurveLinear
} UIViewAnimationCurve;

typedef enum {
    UIViewAnimationTransitionNone,
    UIViewAnimationTransitionFlipFromLeft,
    UIViewAnimationTransitionFlipFromRight,
    UIViewAnimationTransitionCurlUp,
    UIViewAnimationTransitionCurlDown,
} UIViewAnimationTransition;

enum {
    UIViewAnimationOptionLayoutSubviews = 1 <<  0,
    UIViewAnimationOptionAllowUserInteraction = 1 <<  1,
    UIViewAnimationOptionBeginFromCurrentState = 1 <<  2,
    UIViewAnimationOptionRepeat = 1 <<  3,
    UIViewAnimationOptionAutoreverse = 1 <<  4,
    UIViewAnimationOptionOverrideInheritedDuration = 1 <<  5,
    UIViewAnimationOptionOverrideInheritedCurve = 1 <<  6,
    UIViewAnimationOptionAllowAnimatedContent = 1 <<  7,
    UIViewAnimationOptionShowHideTransitionViews = 1 <<  8, 
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
typedef NSUInteger UIViewAnimationOptions;

UIKIT_EXPORT const CGFloat UIViewNoIntrinsicMetric;

@class UIColor, CALayer, UIViewController, UIGestureRecognizer, NSLayoutConstraint, UIMotionEffect, WXFrameworkElement;

UIKIT_EXPORT_CLASS
@interface UIView : UIResponder<NSCoding, UIAppearance, UIAppearanceContainer>  {
@public
    id _backButtonDelegate;
    SEL _backButtonSelector;
    id _backButtonArg;
    BOOL _backButtonReturnsSuccess;
    int _backButtonPriority;    
}

+ (Class)layerClass;

- (id)initWithFrame:(CGRect)frame;
- (void)addSubview:(UIView *)subview;
- (void)insertSubview:(UIView *)subview atIndex:(NSInteger)index;
- (void)insertSubview:(UIView *)subview belowSubview:(UIView *)below;
- (void)insertSubview:(UIView *)subview aboveSubview:(UIView *)above;
- (void)removeFromSuperview;
- (void)bringSubviewToFront:(UIView *)subview;
- (void)sendSubviewToBack:(UIView *)subview;
- (CGRect)convertRect:(CGRect)toConvert fromView:(UIView *)fromView;
- (CGRect)convertRect:(CGRect)toConvert toView:(UIView *)toView;
- (CGPoint)convertPoint:(CGPoint)toConvert fromView:(UIView *)fromView;
- (CGPoint)convertPoint:(CGPoint)toConvert toView:(UIView *)toView;
- (void)setNeedsDisplay;
- (void)setNeedsDisplayInRect:(CGRect)invalidRect;
- (void)drawRect:(CGRect)rect;
- (void)sizeToFit;
- (CGSize)sizeThatFits:(CGSize)size;
- (void)setNeedsLayout;
- (void)layoutIfNeeded;
- (void)layoutSubviews;
- (BOOL)pointInside:(CGPoint)point withEvent:(UIEvent *)event;
- (UIView *)hitTest:(CGPoint)point withEvent:(UIEvent *)event;
- (UIView *)viewWithTag:(NSInteger)tag;
- (BOOL)isDescendantOfView:(UIView *)view;

- (void)addGestureRecognizer:(UIGestureRecognizer *)gestureRecognizer;      // not implemented
- (void)removeGestureRecognizer:(UIGestureRecognizer *)gestureRecognizer;   // not implemented

- (void)didAddSubview:(UIView *)subview;
- (void)didMoveToSuperview;
- (void)didMoveToWindow;
- (void)willMoveToSuperview:(UIView *)newSuperview;
- (void)willMoveToWindow:(UIWindow *)newWindow;
- (void)willRemoveSubview:(UIView *)subview;
- (void)exchangeSubviewAtIndex:(NSInteger)index1 withSubviewAtIndex:(NSInteger)index2;

- (BOOL)endEditing:(BOOL)force;

- (BOOL)translatesAutoresizingMaskIntoConstraints;
- (void)setTranslatesAutoresizingMaskIntoConstraints:(BOOL)flag;
- (UIView *)viewForBaselineLayout;

- (NSArray *)constraints;
- (void)updateConstraints;
- (void)updateConstraintsIfNeeded;
- (void)addConstraint:(NSLayoutConstraint *)constraint;
- (void)addConstraints:(NSArray *)constraints;
- (void)removeConstraint:(NSLayoutConstraint *)constraint;
- (void)removeConstraints:(NSArray *)constraints;
- (UILayoutPriority)contentCompressionResistancePriorityForAxis:(UILayoutConstraintAxis)axis;
- (void)setContentCompressionResistancePriority:(UILayoutPriority)priority forAxis:(UILayoutConstraintAxis)axis;
- (UILayoutPriority)contentHuggingPriorityForAxis:(UILayoutConstraintAxis)axis;
- (void)setContentHuggingPriority:(UILayoutPriority)priority forAxis:(UILayoutConstraintAxis)axis;
- (BOOL)needsUpdateConstraints;
- (void)setNeedsUpdateConstraints;

- (void)removeMotionEffect:(UIMotionEffect *)effect;
- (void)addMotionEffect:(UIMotionEffect *)effect;

- (CGSize)intrinsicContentSize;
- (void)invalidateIntrinsicContentSize;

+ (void)animateWithDuration:(NSTimeInterval)duration delay:(NSTimeInterval)delay usingSpringWithDamping:(CGFloat)dampingRatio initialSpringVelocity:(CGFloat)velocity options:(UIViewAnimationOptions)options animations:(void (^)(void))animations completion:(void (^)(BOOL finished))completion;
+ (void)animateWithDuration:(NSTimeInterval)duration delay:(NSTimeInterval)delay options:(UIViewAnimationOptions)options animations:(void (^)(void))animations completion:(void (^)(BOOL finished))completion;
+ (void)animateWithDuration:(NSTimeInterval)duration animations:(void (^)(void))animations completion:(void (^)(BOOL finished))completion;
+ (void)animateWithDuration:(NSTimeInterval)duration animations:(void (^)(void))animations;

// the block-based transition methods are not currently implemented
+ (void)transitionWithView:(UIView *)view duration:(NSTimeInterval)duration options:(UIViewAnimationOptions)options animations:(void (^)(void))animations completion:(void (^)(BOOL finished))completion;
+ (void)transitionFromView:(UIView *)fromView toView:(UIView *)toView duration:(NSTimeInterval)duration options:(UIViewAnimationOptions)options completion:(void (^)(BOOL finished))completion;

+ (void)beginAnimations:(NSString *)animationID context:(void *)context;
+ (void)commitAnimations;
+ (void)setAnimationBeginsFromCurrentState:(BOOL)beginFromCurrentState;
+ (void)setAnimationCurve:(UIViewAnimationCurve)curve;
+ (void)setAnimationDelay:(NSTimeInterval)delay;
+ (void)setAnimationDelegate:(id)delegate;
+ (void)setAnimationDidStopSelector:(SEL)selector;
+ (void)setAnimationDuration:(NSTimeInterval)duration;
+ (void)setAnimationRepeatAutoreverses:(BOOL)repeatAutoreverses;
+ (void)setAnimationRepeatCount:(float)repeatCount;
+ (void)setAnimationTransition:(UIViewAnimationTransition)transition forView:(UIView *)view cache:(BOOL)cache;
+ (void)setAnimationWillStartSelector:(SEL)selector;
+ (BOOL)areAnimationsEnabled;
+ (void)setAnimationsEnabled:(BOOL)enabled;

@property (nonatomic) CGRect frame;
@property (nonatomic) CGRect bounds;
@property (nonatomic) CGPoint center;
@property (nonatomic) CGAffineTransform transform;
@property (nonatomic, readonly) UIView *superview;
@property (nonatomic, readonly) UIWindow *window;
@property (nonatomic, readonly) NSArray *subviews;
@property (nonatomic) CGFloat alpha;
@property (nonatomic, getter=isOpaque) BOOL opaque;
@property (nonatomic) BOOL clearsContextBeforeDrawing;
@property (nonatomic, copy) UIColor *backgroundColor;
@property (nonatomic, readonly) CALayer *layer;
@property (nonatomic) BOOL clipsToBounds;
@property (nonatomic) BOOL autoresizesSubviews;
@property (nonatomic) UIViewAutoresizing autoresizingMask;
@property (nonatomic) CGRect contentStretch;
@property (nonatomic) NSInteger tag;
@property (nonatomic, getter=isHidden) BOOL hidden;
@property (nonatomic, getter=isUserInteractionEnabled) BOOL userInteractionEnabled;
@property (nonatomic) UIViewContentMode contentMode;
@property (nonatomic) CGFloat contentScaleFactor;
@property (nonatomic, getter=isMultipleTouchEnabled) BOOL multipleTouchEnabled; // state is maintained, but it has no effect
@property (nonatomic, getter=isExclusiveTouch) BOOL exclusiveTouch; // state is maintained, but it has no effect
@property (nonatomic,copy) NSArray *gestureRecognizers;
@property (nonatomic, retain) UIColor *tintColor;
@property (copy, nonatomic) NSArray *motionEffects;

-(void) setNativeElement:(WXFrameworkElement *) nativeElement;
@end

@interface UIView (StarboardActions)
-(void) setBackButtonDelegate: (id) delegate action: (SEL) action withParam: (id) param;
-(void) setBackButtonReturnsSuccess: (BOOL) returnsSuccess;
-(void) setBackButtonPriority: (int) priority;
@end

#endif /* _UIVIEW_H_ */
