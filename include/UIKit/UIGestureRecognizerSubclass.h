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
#pragma once

// NOTE: Concrete subclass of UIGestureRecognizer must import this file. It should either overwrite
// or call its parent method for the methods defined in this file. The Gesture client however, should
// never call these methods directly. This is protocol stated in reference doc

#import <Foundation/NSSet.h>
#import <UIKit/UIGestureRecognizer.h>

@interface UIGestureRecognizer ()

// state is defined in UIGestureRecognizer.h as readonly for gesture client
// it is re-defined here as readwrite so that UIGestureRecognizer subclass
// can reset the state
@property (nonatomic, readwrite) UIGestureRecognizerState state;

- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event;
- (void)touchesMoved:(NSSet*)touches withEvent:(UIEvent*)event;
- (void)touchesEnded:(NSSet*)touches withEvent:(UIEvent*)event;
- (void)touchesCancelled:(NSSet*)touches withEvent:(UIEvent*)event;
- (void)reset;
- (void)ignoreTouch:(UITouch*)touch forEvent:(UIEvent*)event; // don't override
- (BOOL)canBePreventedByGestureRecognizer:(UIGestureRecognizer*)preventingGestureRecognizer;
- (BOOL)canPreventGestureRecognizer:(UIGestureRecognizer*)preventedGestureRecognizer;
- (BOOL)shouldRequireFailureOfGestureRecognizer:(UIGestureRecognizer*)otherGestureRecognizer;
- (BOOL)shouldBeRequiredToFailByGestureRecognizer:(UIGestureRecognizer*)otherGestureRecognizer;
- (void)ignorePress:(UIPress*)button forEvent:(UIPressesEvent*)event;
- (void)pressesBegan:(NSSet*)presses withEvent:(UIPressesEvent*)event;
- (void)pressesChanged:(NSSet*)presses withEvent:(UIPressesEvent*)event;
- (void)pressesEnded:(NSSet*)presses withEvent:(UIPressesEvent*)event;
- (void)pressesCancelled:(NSSet*)presses withEvent:(UIPressesEvent*)event;

@end
