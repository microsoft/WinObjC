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

#pragma once

#import <UIKit/UIKitExport.h>
#import <CoreGraphics/CGAffineTransform.h>
#import <UIKit/UIViewController.h>

@class NSString;
@class UIView;
@class UIViewController;

UIKIT_EXPORT NSString* const UITransitionContextFromViewControllerKey;
UIKIT_EXPORT NSString* const UITransitionContextToViewControllerKey;
UIKIT_EXPORT NSString* const UITransitionContextFromViewKey;
UIKIT_EXPORT NSString* const UITransitionContextToViewKey;

@protocol UIViewControllerContextTransitioning <NSObject>
- (UIView*)containerView;
- (UIViewController*)viewControllerForKey:(NSString*)key;
- (UIView*)viewForKey:(NSString*)key;
- (CGRect)initialFrameForViewController:(UIViewController*)vc;
- (CGRect)finalFrameForViewController:(UIViewController*)vc;
- (BOOL)isAnimated;
- (BOOL)isInteractive;
- (UIModalPresentationStyle)presentationStyle;
- (void)completeTransition:(BOOL)didComplete;
- (void)updateInteractiveTransition:(CGFloat)percentComplete;
- (void)finishInteractiveTransition;
- (void)cancelInteractiveTransition;
- (BOOL)transitionWasCancelled;
- (CGAffineTransform)targetTransform;
@end
