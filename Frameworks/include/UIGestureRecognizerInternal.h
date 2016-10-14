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

// Pan gestures stack, and the rules for whether they consume the gesture are based on its content extents.
// At the end of its content, a UIScrollView will "stick" to its extents, and won't unstick until the pan returns to where it was initially
// stuck. Pan gestures are sent multiple times to the same UIScrollViews, in this order:
// _UIPanGestureStageImmediate:
//		Gives all "unstuck" UIScrollViews the chance to immediately consume a portion of the pan delta.
// _UIPanGestureStageDeferred:
//		All "stuck" UIScrollViews are given another chance to consume and transition to an unstuck state.
// _UIPanGestureStageRemainder:
//		Whatever unconsumed delta may be used for over-drag (dragging past content extents)
typedef NS_ENUM(NSUInteger, _UIPanGestureStage) {
    _UIPanGestureStageImmediate,
    _UIPanGestureStageDeferred,
    _UIPanGestureStageRemainder,
};

#define _UIPanGestureStageNumStages 3

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

    struct {
        unsigned shouldBegin : 1;
        unsigned shouldReceiveTouch : 1;
        unsigned shouldRecognizeSimultaneouslyWithGestureRecognizer : 1;
    } _delegateHas;
}

+ (void)_cancelActiveExcept:(UIGestureRecognizer*)gesture;
- (void)_setView:(UIView*)view;
- (void)_cancelIfActive;
- (void)_fire;
+ (BOOL)_fireGestures:(id)gestures shouldCancelTouches:(BOOL&)shouldCancelTouches;
+ (void)_failActiveExcept:(UIGestureRecognizer*)gesture;
- (void)_addEventConnection:(UIRuntimeEventConnection*)connection;
@end

@class UIView;
@interface UIPanGestureRecognizer ()
- (UIView*)_touchedView;
- (void)_setDragSlack:(float)slack;
- (void)_lockDirection:(int)dir;
- (_UIPanGestureStage)_stage;
@end