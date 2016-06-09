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

#import <UIKit/UIView.h>
#import <UIKit/UICoordinateSpace.h>
#import <UIKit/UIDynamicItem.h>
#import <UIKit/UIFocusEnvironment.h>
#import <UIKit/UITraitEnvironment.h>

typedef CGFloat UIWindowLevel;
UIKIT_EXPORT const UIWindowLevel UIWindowLevelNormal;
UIKIT_EXPORT const UIWindowLevel UIWindowLevelStatusBar;
UIKIT_EXPORT const UIWindowLevel UIWindowLevelAlert;

UIKIT_EXPORT NSString* const UIWindowDidBecomeVisibleNotification;
UIKIT_EXPORT NSString* const UIWindowDidBecomeHiddenNotification;
UIKIT_EXPORT NSString* const UIWindowDidBecomeKeyNotification;
UIKIT_EXPORT NSString* const UIWindowDidResignKeyNotification;

UIKIT_EXPORT NSString* const UIKeyboardWillShowNotification;
UIKIT_EXPORT NSString* const UIKeyboardDidShowNotification;
UIKIT_EXPORT NSString* const UIKeyboardWillHideNotification;
UIKIT_EXPORT NSString* const UIKeyboardDidHideNotification;

UIKIT_EXPORT NSString* const UIKeyboardFrameBeginUserInfoKey;
UIKIT_EXPORT NSString* const UIKeyboardFrameEndUserInfoKey;
UIKIT_EXPORT NSString* const UIKeyboardAnimationDurationUserInfoKey;
UIKIT_EXPORT NSString* const UIKeyboardAnimationCurveUserInfoKey;

UIKIT_EXPORT NSString* const UIKeyboardWillChangeFrameNotification;
UIKIT_EXPORT NSString* const UIKeyboardDidChangeFrameNotification;

// deprecated
UIKIT_EXPORT NSString* const UIKeyboardCenterBeginUserInfoKey;
UIKIT_EXPORT NSString* const UIKeyboardCenterEndUserInfoKey;
UIKIT_EXPORT NSString* const UIKeyboardBoundsUserInfoKey;
UIKIT_EXPORT NSString* const UIKeyboardIsLocalUserInfoKey;

@class UIScreen, UIViewController;

UIKIT_EXPORT_CLASS
@interface UIWindow : UIView <NSCoding,
                              NSObject,
                              UIAppearance,
                              UIAppearanceContainer,
                              UICoordinateSpace,
                              UIDynamicItem,
                              UIFocusEnvironment,
                              UITraitEnvironment>

- (CGPoint)convertPoint:(CGPoint)toConvert toWindow:(UIWindow*)toWindow STUB_METHOD;
- (CGPoint)convertPoint:(CGPoint)toConvert fromWindow:(UIWindow*)fromWindow STUB_METHOD;
- (CGRect)convertRect:(CGRect)toConvert fromWindow:(UIWindow*)fromWindow;
- (CGRect)convertRect:(CGRect)toConvert toWindow:(UIWindow*)toWindow STUB_METHOD;
- (CGRect)convertRect:(CGRect)toConvert fromView:(UIView*)fromView toView:(UIView*)toView STUB_METHOD;
- (CGPoint)convertPoint:(CGPoint)toConvert fromView:(UIView*)fromView toView:(UIView*)toView;
- (CGPoint)convertPoint:(CGPoint)toConvert fromLayer:(CALayer*)fromView toLayer:(CALayer*)toView STUB_METHOD;

- (void)makeKeyWindow;
- (void)makeKeyAndVisible;
- (void)resignKeyWindow;
- (void)becomeKeyWindow;
- (void)sendEvent:(UIEvent*)event;

@property (nonatomic, readonly, getter=isKeyWindow) BOOL keyWindow;
@property (nonatomic, retain) UIScreen* screen STUB_PROPERTY;
@property (nonatomic, assign) UIWindowLevel windowLevel;
@property (nonatomic, retain) UIViewController* rootViewController;
@property (nonatomic) BOOL sizeUIWindowToFit;

@end
