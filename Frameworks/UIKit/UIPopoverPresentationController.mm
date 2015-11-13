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

#include "UIKit/UIPopoverPresentationController.h"

@implementation UIPopoverPresentationController

/**
 @Status Stub
*/
- (id)initWithPresentedViewController:(UIViewController*)presentedViewController
             presentingViewController:(UIViewController*)presentingViewController {
    return [super initWithPresentedViewController:presentedViewController presentingViewController:presentingViewController];
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

@end
