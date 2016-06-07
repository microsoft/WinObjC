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

#include "Starboard.h"

#import <UIKit/UIPopoverPresentationController.h>
#import <UIKit/UIPopoverPresentationControllerDelegate.h>
#import <UIKit/UIPopoverControllerDelegate.h>
#import <UIKit/UIPopoverController.h>
#import "UIPopoverPresentationControllerInternal.h"
#import "UIPopoverControllerInternal.h"

@interface _UIPopoverControllerDelegateInternal : NSObject <UIPopoverControllerDelegate>

@property (nonatomic, assign) UIPopoverPresentationController* controller;
@property (nonatomic, assign) id<UIPopoverPresentationControllerDelegate> delegate;

@end

@implementation _UIPopoverControllerDelegateInternal

- (instancetype)initWithController:(UIPopoverPresentationController*)controller delegate:(id<UIPopoverPresentationControllerDelegate>)delegate {
    if (self = [super init]) {
        _controller = controller;
        _delegate = delegate;
    }
    return self;
}

- (void)popoverController:(UIPopoverController*)popoverController
    willRepositionPopoverToRect:(inout CGRect*)rect
                         inView:(inout UIView* _Nonnull*)view {
    if ([_delegate respondsToSelector:@selector(popoverPresentationController:willRepositionPopoverToRect:inView:)]) {
        [_delegate popoverPresentationController:_controller willRepositionPopoverToRect:rect inView:view];
    }
}

- (BOOL)popoverControllerShouldDismissPopover:(UIPopoverController*)popoverController {
    BOOL shouldDismiss = YES;

    if ([_delegate respondsToSelector:@selector(popoverPresentationControllerShouldDismissPopover:)]) {
        shouldDismiss = [_delegate popoverPresentationControllerShouldDismissPopover:_controller];
    }

    if (shouldDismiss) {
        if (_controller->_willDismissCompletion) {
            _controller->_willDismissCompletion();
            [_controller->_willDismissCompletion release];
            _controller->_willDismissCompletion = nil;
        }
    }

    return shouldDismiss;
}

- (void)popoverControllerDidDismissPopover:(UIPopoverController*)popoverController {
    if ([_delegate respondsToSelector:@selector(popoverPresentationControllerDidDismissPopover:)]) {
        [_delegate popoverPresentationControllerDidDismissPopover:_controller];
    }
}

@end

@implementation UIPopoverPresentationController {
    StrongId<UIPopoverController> _popoverControllerInternal;
    StrongId<_UIPopoverControllerDelegateInternal> _delegateInternal;
    StrongId<Class> _popoverBackgroundViewClass;
    StrongId<UIBarButtonItem*> _barButtonItem;
    StrongId<UIView*> _sourceView;
    CGRect _sourceRect;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithPresentedViewController:(UIViewController*)presentedViewController
             presentingViewController:(UIViewController*)presentingViewController {
    self = [super initWithPresentedViewController:presentedViewController presentingViewController:presentingViewController];
    if (self) {
        _permittedArrowDirections = UIPopoverArrowDirectionAny;
        _popoverControllerInternal = [[UIPopoverController alloc] initWithContentViewController:presentedViewController];
        _delegateInternal = [[_UIPopoverControllerDelegateInternal alloc] initWithController:self delegate:nil];
        [_popoverControllerInternal setDelegate:_delegateInternal];
    }
    return self;
}

- (void)_prepareForPresentation {
    if ([[_delegateInternal delegate] respondsToSelector:@selector(prepareForPopoverPresentation:)]) {
        [[_delegateInternal delegate] prepareForPopoverPresentation:self];
    }
}

- (void)_presentAnimated:(BOOL)animated completion:(dispatch_block_t)presentCompletion {
    [_popoverControllerInternal->_presentCompletion release];
    _popoverControllerInternal->_presentCompletion = [presentCompletion copy];

    if (_barButtonItem) {
        [_popoverControllerInternal presentPopoverFromBarButtonItem:_barButtonItem
                                           permittedArrowDirections:_permittedArrowDirections
                                                           animated:animated];
    } else {
        [_popoverControllerInternal presentPopoverFromRect:_sourceRect
                                                    inView:_sourceView
                                  permittedArrowDirections:_permittedArrowDirections
                                                  animated:animated];
    }
}

- (void)_dismissAnimated:(BOOL)animated completion:(dispatch_block_t)dismissCompletion {
    [_popoverControllerInternal _dismissPopoverAnimated:animated completion:dismissCompletion];
}

/**
 @Status Stub
*/
- (UIView*)presentedView {
    return [super presentedView];
}

/**
 @Status Stub
*/
- (CGRect)frameOfPresentedViewInContainerView {
    return [super frameOfPresentedViewInContainerView];
}

/**
 @Status Stub
*/
- (BOOL)shouldPresentInFullscreen {
    return [super shouldPresentInFullscreen];
}

/**
 @Status Stub
*/
- (BOOL)shouldRemovePresentersView {
    return [super shouldRemovePresentersView];
}

/**
 @Status Stub
*/
- (void)containerViewWillLayoutSubviews {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)containerViewDidLayoutSubviews {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)presentationTransitionWillBegin {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)presentationTransitionDidEnd:(BOOL)completed {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)dismissalTransitionWillBegin {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)dismissalTransitionDidEnd:(BOOL)completed {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (void)setSourceView:(UIView*)sourceView {
    _sourceView = sourceView;
}

/**
 @Status Interoperable
*/
- (UIView*)sourceView {
    return _sourceView;
}

/**
 @Status Interoperable
*/
- (void)setSourceRect:(CGRect)sourceRect {
    _sourceRect = sourceRect;
}

/**
 @Status Interoperable
*/
- (CGRect)sourceRect {
    return _sourceRect;
}

/**
 @Status Interoperable
*/
- (void)setBarButtonItem:(UIBarButtonItem*)barButtonItem {
    _barButtonItem = barButtonItem;
}

/**
 @Status Interoperable
*/
- (UIBarButtonItem*)barButtonItem {
    return _barButtonItem;
}

/**
 @Status Interoperable
*/
- (void)setPopoverLayoutMargins:(UIEdgeInsets)popoverLayoutMargins {
    [_popoverControllerInternal setPopoverLayoutMargins:popoverLayoutMargins];
}

/**
 @Status Interoperable
*/
- (UIEdgeInsets)popoverLayoutMargins {
    return [_popoverControllerInternal popoverLayoutMargins];
}

/**
 @Status Interoperable
*/
- (void)setDelegate:(id<UIPopoverPresentationControllerDelegate>)delegate {
    [_delegateInternal setDelegate:delegate];
}

/**
 @Status Interoperable
*/
- (id<UIPopoverPresentationControllerDelegate>)delegate {
    return [_delegateInternal delegate];
}

/**
 @Status Interoperable
*/
- (NSArray*)passthroughViews {
    return [_popoverControllerInternal passthroughViews];
}

/**
 @Status Interoperable
*/
- (void)setPassthroughViews:(NSArray*)passthroughViews {
    [_popoverControllerInternal setPassthroughViews:passthroughViews];
}

/**
 @Status Interoperable
*/
- (UIPopoverArrowDirection)popoverArrowDirection {
    return (UIPopoverArrowDirection)[_popoverControllerInternal popoverArrowDirection];
}

/**
 @Status Interoperable
*/
- (UIColor*)backgroundColor {
    return [_popoverControllerInternal backgroundColor];
}

/**
 @Status Interoperable
*/
- (void)setBackgroundColor:(UIColor*)backgroundColor {
    [_popoverControllerInternal setBackgroundColor:backgroundColor];
}

/**
 @Status Stub
*/
- (Class)popoverBackgroundViewClass {
    UNIMPLEMENTED();
    return _popoverBackgroundViewClass;
}

/**
 @Status Stub
*/
- (void)setPopoverBackgroundViewClass:(Class)popoverBackgroundViewClass {
    UNIMPLEMENTED();
    _popoverBackgroundViewClass = popoverBackgroundViewClass;
}

- (void)dealloc {
    [_willDismissCompletion release];
    [super dealloc];
}

@end
