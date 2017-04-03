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
#import <Starboard/SmartTypes.h>
#import <UIKit/NSLayoutAnchor.h>
#import <UIKit/NSLayoutXAxisAnchor.h>
#import <UIKit/NSLayoutYAxisAnchor.h>
#import <UIKit/NSLayoutDimension.h>
#import <UIKit/NSStringDrawingContext.h>
#import <UIKit/UILayoutSupport.h>
#import <UIKit/UITouch.h>
#import <UIKit/UIView.h>
#import "UWP/InteropBase.h"
#import "UWP/WindowsUIXamlControls.h"

#include "COMIncludes.h"
#import <winrt/Windows.Foundation.h>
#import <winrt/Windows.UI.Xaml.h>
#import <winrt/Windows.UI.Xaml.Input.h>
#include "COMIncludes_End.h"

@class UIWindow;

// Round subpixel values to be able to perform per-pixel UI placement/calculations
inline float doPixelRound(float f) {
    return (float)(floorf((f * 2) + 0.5) / 2.0f);
}

// Round subpixel values to be able to perform per-pixel UI placement/calculations
inline CGSize doPixelRound(CGSize size) {
    size.width = doPixelRound(size.width);
    size.height = doPixelRound(size.height);
    return size;
}

// Round subpixel values to be able to perform per-pixel UI placement/calculations
inline CGRect doPixelRound(CGRect frame) {
    frame.origin.x = doPixelRound(frame.origin.x);
    frame.origin.y = doPixelRound(frame.origin.y);
    frame.size.width = doPixelRound(frame.size.width);
    frame.size.height = doPixelRound(frame.size.height);
    return frame;
}

class UIViewPrivateState : public LLTreeNode<UIViewPrivateState, UIView> {
public:
    id superview; //  id
    StrongId<UIColor> backgroundColor;
    id curTouch, curTouchEvent, curTouchSet;
    uint32_t tag;
    BOOL userInteractionEnabled;
    BOOL multipleTouchEnabled;
    UIViewContentMode contentMode;
    StrongId<NSMutableArray> currentTouches;
    StrongId<NSMutableArray> gestures;
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

    winrt::event_token _pointerPressedEventRegistration = { };
    winrt::event_token _pointerMovedEventRegistration = { };
    winrt::event_token _pointerReleasedEventRegistration = { };
    winrt::event_token _pointerCanceledEventRegistration = { };
    winrt::event_token _pointerCaptureLostEventRegistration = { };

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
        constraints = [NSMutableArray new];
        translatesAutoresizingMaskIntoConstraints = YES;
        _isChangingParent = false;
        _constraintsNeedUpdate = false;
        _contentHuggingPriority.height = 250.0f;
        _contentHuggingPriority.width = 250.0f;
        _contentCompressionResistancePriority.height = 750.0f;
        _contentCompressionResistancePriority.width = 750.0f;
        _layoutGuides = [NSMutableArray new];

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

- (UITouchPhase)_processPointerEvent:(const winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs&)pointerEventArgs forTouchPhase:(UITouchPhase)touchPhase;

+ (void)_setPageTransitionForView:(UIView*)view fromLeft:(BOOL)fromLeft;
- (void)_applyConstraints;
- (void)_setShouldLayout;
+ (void)_setNestedAnimationsEnabled:(BOOL)enable;
- (void)__setContentsImage:(id)image;
- (UIWindow*)_getWindowInternal;
- (BOOL)_isEnabled;
- (winrt::Windows::UI::Xaml::FrameworkElement)_winrtXamlElement;
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

inline void RunSynchronouslyOnMainThread(void (^block)()) {
    if ([NSThread isMainThread]) {
        block();
    } else {
        dispatch_sync(dispatch_get_main_queue(), block);
    }
}
