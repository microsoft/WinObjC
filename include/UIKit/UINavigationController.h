/*
* Copyright (c) 2011, The Iconfactory. All rights reserved.
*
* Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#ifndef _UINAVIGATIONCONTROLLER_H_
#define _UINAVIGATIONCONTROLLER_H_

#import "UIViewController.h"

@class UINavigationBar, UIToolbar, UIViewController;

@protocol UINavigationControllerDelegate <NSObject>
@optional

/**
 @Status Interoperable
*/
- (void)navigationController:(UINavigationController*)navigationController
       didShowViewController:(UIViewController*)viewController
                    animated:(BOOL)animated;

/**
 @Status Interoperable
*/
- (void)navigationController:(UINavigationController*)navigationController
      willShowViewController:(UIViewController*)viewController
                    animated:(BOOL)animated;
@end

typedef enum {
    _UINavigationControllerVisibleControllerTransitionNone = 0,
    _UINavigationControllerVisibleControllerTransitionPushAnimated,
    _UINavigationControllerVisibleControllerTransitionPopAnimated
} _UINavigationControllerVisibleControllerTransition;

@interface UINavigationPane : UIView {
@public
    UIViewController* _parentController;
}
@end

UIKIT_EXPORT_CLASS
@interface UINavigationController : UIViewController

- (id)initWithRootViewController:(UIViewController*)rootViewController;

- (void)setViewControllers:(NSArray*)newViewControllers animated:(BOOL)animated;

- (void)pushViewController:(UIViewController*)viewController animated:(BOOL)animated;
- (UIViewController*)popViewControllerAnimated:(BOOL)animated;
- (NSArray*)popToViewController:(UIViewController*)viewController animated:(BOOL)animated;
- (NSArray*)popToRootViewControllerAnimated:(BOOL)animated;

- (void)setNavigationBarHidden:(BOOL)hidden animated:(BOOL)animated;
- (void)setToolbarHidden:(BOOL)hidden animated:(BOOL)animated; // toolbar support is not really implemented yet

- (void)setNavigationBarHidden:(BOOL)navigationBarHidden animated:(BOOL)animated; // doesn't animate yet

- (instancetype)initWithNavigationBarClass:(Class)navigationBarClass toolbarClass:(Class)toolbarClass;

@property (nonatomic, copy) NSArray* viewControllers;
@property (nonatomic, readonly, retain) UIViewController* visibleViewController;
@property (nonatomic, readonly) UINavigationBar* navigationBar;
@property (nonatomic, readonly) UIToolbar* toolbar; // toolbar support is not really implemented yet
@property (nonatomic, assign) id<UINavigationControllerDelegate> delegate;
@property (nonatomic, readonly, retain) UIViewController* topViewController;
@property (nonatomic, getter=isNavigationBarHidden) BOOL navigationBarHidden;
@property (nonatomic, getter=isToolbarHidden) BOOL toolbarHidden; // toolbar support is not really implemented yet
@property (nonatomic) BOOL hidesBarsOnSwipe;
@property (nonatomic, readonly) UIGestureRecognizer* interactivePopGestureRecognizer;

@property (nonatomic) BOOL hidesBarsOnTap;

@property (nonatomic, readonly) UIGestureRecognizer* barHideOnTapGestureRecognizer;
@property (nonatomic, readonly) UIGestureRecognizer* barHideOnSwipeGestureRecognizer;

@end

UIKIT_EXPORT const CGFloat UINavigationControllerHideShowBarDuration;

enum {
    UINavigationControllerOperationPush,
    UINavigationControllerOperationPop,
};

typedef NSUInteger UINavigationControllerOperation;

@protocol UIViewControllerTransitioningDelegate

@end

#endif /* _UINAVIGATIONCONTROLLER_H_ */
