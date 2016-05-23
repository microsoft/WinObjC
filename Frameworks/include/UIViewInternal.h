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

#import "LinkedList.h"

@class UIWindow;
@class WXFrameworkElement;

class UIViewPrivateState : public LLTreeNode<UIViewPrivateState, UIView> {
public:
    id superview; //  id
    StrongId<UIColor> backgroundColor;
    id curTouch, curTouchEvent, curTouchSet;
    uint32_t tag;
    BOOL userInteractionEnabled;
    BOOL multipleTouchEnabled;
    UIViewContentMode contentMode;
    id currentTouches;
    id gestures;
    StrongId<NSMutableArray> constraints;
    bool _isChangingParent;
    bool _constraintsNeedUpdate;

    StrongId<NSMutableArray> _layoutGuides;
    StrongId<NSLayoutDimension> _heightAnchor;
    StrongId<NSLayoutDimension> _widthAnchor;
    StrongId<NSLayoutXAxisAnchor> _centerXAnchor;
    StrongId<NSLayoutXAxisAnchor> _leadingAnchor;
    StrongId<NSLayoutXAxisAnchor> _leftAnchor;
    StrongId<NSLayoutXAxisAnchor> _rightAnchor;
    StrongId<NSLayoutXAxisAnchor> _trailingAnchor;
    StrongId<NSLayoutYAxisAnchor> _bottomAnchor;
    StrongId<NSLayoutYAxisAnchor> _centerYAnchor;
    StrongId<NSLayoutYAxisAnchor> _firstBaselineAnchor;
    StrongId<NSLayoutYAxisAnchor> _lastBaselineAnchor;
    StrongId<NSLayoutYAxisAnchor> _topAnchor;

    UIViewAutoresizing autoresizingMask;
    CGSize _contentHuggingPriority;
    CGSize _contentCompressionResistancePriority;
    BOOL autoresizesSubviews;
    BOOL translatesAutoresizingMaskIntoConstraints;
    CGRect _resizeRoundingError;

    StrongId<WXFrameworkElement> _xamlInputElement; // The XAML element receiving touch input for this view

    UIViewPrivateState(UIView* owner) {
        setSelf(owner);
        superview = nil;
        backgroundColor = nil;
        curTouch = nil;
        curTouchEvent = nil;
        curTouchSet = nil;
        tag = 0;
        userInteractionEnabled = YES;
        multipleTouchEnabled = NO;
        contentMode = UIViewContentModeScaleToFill;
        currentTouches = [[NSMutableArray alloc] initWithCapacity:16];
        gestures = [NSMutableArray new];
        constraints.attach([NSMutableArray new]);
        translatesAutoresizingMaskIntoConstraints = YES;
        _isChangingParent = false;
        _constraintsNeedUpdate = false;
        _contentHuggingPriority.height = 250.0f;
        _contentHuggingPriority.width = 250.0f;
        _contentCompressionResistancePriority.height = 750.0f;
        _contentCompressionResistancePriority.width = 750.0f;
        _layoutGuides.attach([NSMutableArray new]);

        memset(&_resizeRoundingError, 0, sizeof(_resizeRoundingError));

        autoresizesSubviews = YES;
        autoresizingMask = UIViewAutoresizingNone;
    }
};

// This is a bit of a hack (since didMoveToWindow should only be in UIView-derived classes)
// but we use this to resign firstResponder-ship so carets stop blinking when moving between windows.
@interface UIResponder ()
- (void)didMoveToWindow;
@end

@interface UIView () {
@public
    UIViewPrivateState* priv;
}
- (void)_initPriv;
+ (void)_setPageTransitionForView:(UIView*)view fromLeft:(BOOL)fromLeft;
- (UIViewPrivateState*)_privateState;

- (void)_applyConstraints;
- (void)_setShouldLayout;
+ (void)_setNestedAnimationsEnabled:(BOOL)enable;
- (void)_setBoundsOrigin:(CGPoint)origin;
- (void)__setContentsImage:(id)image;
- (UIWindow*)_getWindowInternal;
- (BOOL)_isEnabled;
@end

@interface NSLayoutConstraint () 
- (void)_setView:(UIView*)view;
- (void)_printConstraint;
+ (void)_printConstraints:(NSArray*)constraints;
@end

@interface _UILayoutGuide : UIView <UILayoutSupport>
@end

@interface NSStringDrawingContext ()
- (void)_setInternalTotalBounds:(CGRect)rect;
@end
