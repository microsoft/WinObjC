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

#include "UIKit/UIPresentationController.h"

@implementation UIPresentationController

/**
 @Status Interoperable
*/
- (id)initWithPresentedViewController:(UIViewController*)presentedViewController
             presentingViewController:(UIViewController*)presentingViewController {
    _presentingViewController = presentingViewController;
    _presentedViewController = presentedViewController;
    _presentationStyle = _presentedViewController.modalPresentationStyle;
    _containerView = _presentingViewController.view;

    return self;
}

/**
 @Status Interoperable
*/
- (UIView*)presentedView {
    return self.presentedViewController.view;
}

/**
 @Status Interoperable
*/
- (CGRect)frameOfPresentedViewInContainerView {
    return _containerView.frame;
}

/**
 @Status Interoperable
*/
- (BOOL)shouldPresentInFullscreen {
    return YES;
}

/**
 @Status Interoperable
*/
- (BOOL)shouldRemovePresentersView {
    return NO;
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

@end