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

#import <objc/runtime.h>
#import <UIKit/UIGestureRecognizer.h>
#import <UIKit/UIPanGestureRecognizer.h>

typedef struct {
    __unsafe_unretained id _target;
    SEL _selector;
} GestureTarget;

@class UIRuntimeEventConnection;

@interface UIGestureRecognizer () <NSCoding> {
@protected
    __unsafe_unretained id _delegate;
    BOOL _delaysTouchesBegan;
    BOOL _delaysTouchesEnded;
    BOOL _cancelsTouchesInView;
    BOOL _disabled;
    UIGestureRecognizerState _state;
    UIView* _view;
    NSMutableArray* _registeredActions;
    NSMutableArray* _trackingTouches;

    GestureTarget _targets[32];
    int _numTargets;
}

- (void)_setView:(UIView*)view;
- (void)_fire;
+ (BOOL)_fireGesture:(UIGestureRecognizer*)gesture;
- (void)_addEventConnection:(UIRuntimeEventConnection*)connection;
- (void)_cancel;
@end