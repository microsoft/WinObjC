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

#import <StubReturn.h>
#include "Starboard.h"

#include "UIKit/UIPresentationController.h"

@implementation UIPresentationController

/**
 @Status Interoperable
*/
- (instancetype)initWithPresentedViewController:(UIViewController*)presentedViewController
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

/**
 @Status Stub
 @Notes
*/
- (void)viewWillTransitionToSize:(CGSize)size withTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)willTransitionToTraitCollection:(UITraitCollection*)newCollection withTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (CGSize)sizeForChildContentContainer:(id<UIContentContainer>)container withParentContainerSize:(CGSize)parentSize {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)preferredContentSizeDidChangeForChildContentContainer:(id<UIContentContainer>)container {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)systemLayoutFittingSizeDidChangeForChildContentContainer:(id<UIContentContainer>)container {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setNeedsFocusUpdate {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)updateFocusIfNeeded {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)shouldUpdateFocusInContext:(UIFocusUpdateContext*)context {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)didUpdateFocusInContext:(UIFocusUpdateContext*)context withAnimationCoordinator:(UIFocusAnimationCoordinator*)coordinator {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)traitCollectionDidChange:(UITraitCollection*)previousTraitCollection {
    UNIMPLEMENTED();
}

@end