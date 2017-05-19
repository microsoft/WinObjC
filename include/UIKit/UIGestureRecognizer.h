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

#import <UIKit/UIKitExport.h>
#import <Foundation/Foundation.h>
#import <CoreGraphics/CGBase.h>

typedef enum {
    UIGestureRecognizerStatePossible,
    UIGestureRecognizerStateBegan,
    UIGestureRecognizerStateChanged,
    UIGestureRecognizerStateEnded,
    UIGestureRecognizerStateCancelled,
    UIGestureRecognizerStateFailed,
    UIGestureRecognizerStateRecognized = UIGestureRecognizerStateEnded,
} UIGestureRecognizerState;

@class UIView, UIGestureRecognizer, UITouch, UIEvent, UIPress, UIPressesEvent;
@protocol UIGestureRecognizerDelegate;

UIKIT_EXPORT_CLASS
@interface UIGestureRecognizer : NSObject

// Initializing a Gesture Recognizer
- (instancetype)initWithTarget:(id)target action:(SEL)action;

// Getting the Touches and Location of a Gesture
- (CGPoint)locationInView:(UIView*)view STUB_METHOD;
- (CGPoint)locationOfTouch:(NSUInteger)touchIndex inView:(UIView*)view STUB_METHOD;
- (NSUInteger)numberOfTouches STUB_METHOD;

// Adding and Removing Targets and Actions
- (void)addTarget:(id)target action:(SEL)action;
- (void)removeTarget:(id)target action:(SEL)action STUB_METHOD;

// Specifying Dependencies Between Gesture Recognizers
- (void)requireGestureRecognizerToFail:(UIGestureRecognizer*)otherGestureRecognizer;

// Canceling and Delaying Touches
@property (nonatomic) BOOL cancelsTouchesInView;
@property (nonatomic) BOOL delaysTouchesBegan;
@property (nonatomic) BOOL delaysTouchesEnded;

// Setting and Getting the Delegate
@property (nonatomic, weak) id<UIGestureRecognizerDelegate> delegate;

// Getting the Recognizer’s State and View
@property (nonatomic, getter=isEnabled) BOOL enabled;
@property (nonatomic, readonly) UIGestureRecognizerState state;
@property (nonatomic, readonly) UIView* view;

// Recognizing Different Gestures
@property (copy, nonatomic) NSArray* allowedPressTypes STUB_PROPERTY;
@property (copy, nonatomic) NSArray* allowedTouchTypes STUB_PROPERTY;

@end

@protocol UIGestureRecognizerDelegate <NSObject>
@optional
- (BOOL)gestureRecognizerShouldBegin:(UIGestureRecognizer*)gestureRecognizer;
- (BOOL)gestureRecognizer:(UIGestureRecognizer*)gestureRecognizer shouldReceiveTouch:(UITouch*)touch;
- (BOOL)gestureRecognizer:(UIGestureRecognizer*)gestureRecognizer
    shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer*)otherGestureRecognizer;
- (BOOL)gestureRecognizer:(UIGestureRecognizer*)gestureRecognizer
    shouldRequireFailureOfGestureRecognizer:(UIGestureRecognizer*)otherGestureRecognizer;
- (BOOL)gestureRecognizer:(UIGestureRecognizer*)gestureRecognizer
    shouldBeRequiredToFailByGestureRecognizer:(UIGestureRecognizer*)otherGestureRecognizer;
@end
