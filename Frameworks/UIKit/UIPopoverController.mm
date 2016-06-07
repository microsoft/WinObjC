//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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
#import <StubReturn.h>
#import <UIKit/UIPopoverController.h>
#import <UIKit/UIPopoverControllerDelegate.h>
#import "UIPopoverControllerInternal.h"
#import "WYPopoverController.h"

@interface _WYPopoverDelegateInternal : NSObject <WYPopoverControllerDelegate>

@property (nonatomic, assign) UIPopoverController* controller;
@property (nonatomic, assign) id<UIPopoverControllerDelegate> delegate;

@end

@implementation _WYPopoverDelegateInternal

- (instancetype)initWithController:(UIPopoverController*)controller delegate:(id<UIPopoverControllerDelegate>)delegate {
    if (self = [super init]) {
        _controller = controller;
        _delegate = delegate;
    }
    return self;
}

- (BOOL)popoverControllerShouldDismissPopover:(WYPopoverController*)popoverController {
    if ([_delegate respondsToSelector:@selector(popoverControllerShouldDismissPopover:)]) {
        return [_delegate popoverControllerShouldDismissPopover:_controller];
    }
    return YES;
}

- (void)popoverControllerDidDismissPopover:(WYPopoverController*)popoverController {
    if ([_delegate respondsToSelector:@selector(popoverControllerDidDismissPopover:)]) {
        [_delegate popoverControllerDidDismissPopover:_controller];
    }
}

- (void)popoverController:(WYPopoverController*)popoverController willRepositionPopoverToRect:(inout CGRect*)rect inView:(inout UIView* _Nonnull*)view {
    if ([_delegate respondsToSelector:@selector(popoverController:willRepositionPopoverToRect:inView:)]) {
        [_delegate popoverController:_controller willRepositionPopoverToRect:rect inView:view];
    }
}

- (BOOL)popoverControllerShouldIgnoreKeyboardBounds:(WYPopoverController*)popoverController {
    return NO;
}

- (void)popoverController:(WYPopoverController*)popoverController willTranslatePopoverWithYOffset:(float*)value {
}

- (void)popoverControllerDidPresentPopover:(WYPopoverController*)popoverController {
    if (_controller->_presentCompletion) {
        _controller->_presentCompletion();
        [_controller->_presentCompletion release];
        _controller->_presentCompletion = nil;
    }
}

@end

@implementation UIPopoverController {
    StrongId<UIColor> _backgroundColor;
    StrongId<Class> _popoverBackgroundViewClass;
    StrongId<_WYPopoverDelegateInternal> _delegateInternal;
    WYPopoverController* _popoverControllerInternal;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithContentViewController:(UIViewController*)viewController {
    if (self = [super init]) {
        _popoverControllerInternal = [[WYPopoverController alloc] initWithContentViewController:viewController];
        _delegateInternal = [[_WYPopoverDelegateInternal alloc] initWithController:self delegate:nil];
        [_popoverControllerInternal setDelegate:_delegateInternal];
    }
    return self;
}

/**
 @Status Interoperable
*/
- (void)presentPopoverFromRect:(CGRect)rect
                        inView:(UIView*)view
      permittedArrowDirections:(UIPopoverArrowDirection)arrowDirections
                      animated:(BOOL)animated {

    [_popoverControllerInternal presentPopoverFromRect:rect
                                                inView:view
                              permittedArrowDirections:arrowDirections
                                              animated:animated];
}

/**
 @Status Interoperable
*/
- (void)presentPopoverFromBarButtonItem:(UIBarButtonItem*)item
               permittedArrowDirections:(UIPopoverArrowDirection)arrowDirections
                               animated:(BOOL)animated {

    [_popoverControllerInternal presentPopoverFromBarButtonItem:item
                                       permittedArrowDirections:arrowDirections
                                                       animated:animated];
}

/**
 @Status Interoperable
*/
- (void)dismissPopoverAnimated:(BOOL)animated {
    [_popoverControllerInternal dismissPopoverAnimated:animated];
}

- (void)_dismissPopoverAnimated:(BOOL)animated completion:(dispatch_block_t)completion {
    [_popoverControllerInternal dismissPopoverAnimated:animated completion:completion];
}

/**
 @Status Interoperable
*/
- (void)setDelegate:(id<UIPopoverControllerDelegate>)delegate {
    [_delegateInternal setDelegate:delegate];
}

/**
 @Status Interoperable
*/
- (id<UIPopoverControllerDelegate>)delegate {
    return [_delegateInternal delegate];
}

/**
 @Status Stub
*/
- (void)setContentViewController:(UIViewController*)viewController animated:(BOOL)animated {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setContentViewController:(UIViewController*)viewController {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (UIViewController*)contentViewController {
    return [_popoverControllerInternal contentViewController];
}

/**
 @Status Interoperable
*/
- (CGSize)popoverContentSize {
    return [_popoverControllerInternal popoverContentSize];
}

/**
 @Status Interoperable
*/
- (void)setPopoverContentSize:(CGSize)size {
    [_popoverControllerInternal setPopoverContentSize:size];
}

/**
 @Status Interoperable
*/
- (void)setPopoverContentSize:(CGSize)size animated:(BOOL)animated {
    [_popoverControllerInternal setPopoverContentSize:size];
}

/**
 @Status Interoperable
*/
- (BOOL)isPopoverVisible {
    return [_popoverControllerInternal isPopoverVisible];
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
    return [_popoverControllerInternal setPassthroughViews:passthroughViews];
}

/**
 @Status Stub
*/
- (UIPopoverArrowDirection)popoverArrowDirection {
    UNIMPLEMENTED();
    return UIPopoverArrowDirectionAny;
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
 @Status Stub
*/
- (Class)popoverBackgroundViewClass {
    UNIMPLEMENTED();
    return [_popoverBackgroundViewClass autorelease];
}

/**
 @Status Stub
*/
- (void)setPopoverBackgroundViewClass:(Class)popoverBackgroundViewClass {
    UNIMPLEMENTED();
    _popoverBackgroundViewClass = popoverBackgroundViewClass;
}

/**
 @Status Interoperable
*/
- (UIColor*)backgroundColor {
    return [_backgroundColor autorelease];
}

/**
 @Status Interoperable
*/
- (void)setBackgroundColor:(UIColor*)color {
    _backgroundColor.attach([color copy]);
    if (_backgroundColor) {
        [_popoverControllerInternal beginThemeUpdates];
        _popoverControllerInternal.theme.fillTopColor = _backgroundColor;
        _popoverControllerInternal.theme.fillBottomColor = _backgroundColor;
        _popoverControllerInternal.theme.outerStrokeColor = _backgroundColor;
        _popoverControllerInternal.theme.innerStrokeColor = _backgroundColor;
        [_popoverControllerInternal endThemeUpdates];
    }
}

- (void)dealloc {
    [_presentCompletion release];
    [_popoverControllerInternal release];
    [super dealloc];
}

@end
