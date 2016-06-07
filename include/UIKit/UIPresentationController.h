/*
 * Copyright (c) 2011, The Iconfactory. All rights reserved.
 * Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#pragma once

#import <Foundation/Foundation.h>
#import <UIKit/UIViewController.h>

@protocol UIAdaptivePresentationControllerDelegate;

UIKIT_EXPORT_CLASS
@interface UIPresentationController : NSObject <UIAppearanceContainer, UIContentContainer, UIFocusEnvironment, UITraitEnvironment>

- (instancetype)initWithPresentedViewController:(UIViewController*)presentedViewController
                       presentingViewController:(UIViewController*)presentingViewController;

- (UIView*)presentedView;
- (CGRect)frameOfPresentedViewInContainerView;

- (void)containerViewWillLayoutSubviews;
- (void)containerViewDidLayoutSubviews;
- (void)presentationTransitionWillBegin;
- (void)presentationTransitionDidEnd:(BOOL)completed;
- (void)dismissalTransitionWillBegin;
- (void)dismissalTransitionDidEnd:(BOOL)completed;

- (BOOL)shouldPresentInFullscreen;
- (BOOL)shouldRemovePresentersView;

@property (nonatomic, readonly, retain) UIViewController* presentingViewController;
@property (nonatomic, readonly, retain) UIViewController* presentedViewController;
@property (nonatomic, readonly, retain) UIView* containerView;
@property (nonatomic, readonly) UIModalPresentationStyle presentationStyle;

@property (nonatomic) CGSize preferredContentSize STUB_PROPERTY;
@property (nonatomic) UIView* preferredFocusedView STUB_PROPERTY; // TODO: property should be weak, needs ARC
@property (nonatomic, readonly) UITraitCollection* traitCollection STUB_PROPERTY;

@property (nonatomic) id<UIAdaptivePresentationControllerDelegate> delegate STUB_PROPERTY; // TODO: property should be weak, needs ARC

@end
