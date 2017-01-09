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
#import "Starboard.h"
#import <Foundation/NSMutableDictionary.h>
#import <Foundation/NSValue.h>
#import <Foundation/NSString.h>
#import <math.h>
#import <UIKit/UIGestureRecognizer.h>
#import <UIKit/UIRuntimeEventConnection.h>
#import <UIKit/UIGestureRecognizerSubclass.h>

#import "UIGestureRecognizerInternal.h"
#include "LoggingNative.h"

static const wchar_t* TAG = L"UIGestureRecognizer";

extern NSMutableDictionary* g_curGesturesDict;

@implementation UIGestureRecognizer

static void commonInit(UIGestureRecognizer* self) {
    self->_disabled = NO;
    self->_cancelsTouchesInView = YES;
    self->_delaysTouchesBegan = NO;
    self->_delaysTouchesEnded = YES;
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    if (self = [super init]) {
        commonInit(self);
    }

    return self;
}

- (instancetype)initWithCoder:(NSCoder*)coder {
    if (self = [super init]) {
        commonInit(self);

        NSString* disabledKey = @"UIGestureRecognizer.disabled";
        NSString* cancelsTouchesInViewKey = @"UIGestureRecognizer.cancelsTouchesInView";
        NSString* delaysTouchesBeganKey = @"UIGestureRecognizer.delaysTouchesBegan";
        NSString* delaysTouchesEndedKey = @"UIGestureRecognizer.delaysTouchesEnded";

        if ([coder containsValueForKey:disabledKey]) {
            _disabled = [coder decodeBoolForKey:disabledKey];
        }

        if ([coder containsValueForKey:cancelsTouchesInViewKey]) {
            _cancelsTouchesInView = [coder decodeBoolForKey:cancelsTouchesInViewKey];
        }

        if ([coder containsValueForKey:delaysTouchesBeganKey]) {
            _delaysTouchesBegan = [coder decodeBoolForKey:delaysTouchesBeganKey];
        }

        if ([coder containsValueForKey:delaysTouchesEndedKey]) {
            _delaysTouchesEnded = [coder decodeBoolForKey:delaysTouchesEndedKey];
        }
    }

    return self;
}

- (void)encodeWithCoder:(NSCoder*)encoder {
    UNIMPLEMENTED();
}

- (void)_addEventConnection:(UIRuntimeEventConnection*)connection {
    id dest = [connection obj];
    SEL destSel = (SEL)[connection sel];
    [self addTarget:dest action:destSel];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithTarget:(id)target action:(SEL)selector {
    [self addTarget:target action:selector];
    return self;
}

/**
 @Status Interoperable
*/
- (void)setDelegate:(id<UIGestureRecognizerDelegate>)delegate {
    _delegate = delegate;
}

/**
 @Status Interoperable
*/
- (id<UIGestureRecognizerDelegate>)delegate {
    return _delegate;
}

- (void)_setView:(UIView*)view {
    _view = view;
}

/**
 @Status Interoperable
*/
- (UIView*)view {
    return _view;
}

/**
 @Status Interoperable
*/
- (void)setEnabled:(BOOL)enabled {
    _disabled = !enabled;
}

/**
 @Status Interoperable
*/
- (BOOL)isEnabled {
    return !_disabled;
}

/**
 @Status Stub
*/
- (void)setCancelsTouchesInView:(BOOL)cancels {
    UNIMPLEMENTED();

    _cancelsTouchesInView = cancels;
}

/**
 @Status Stub
*/
- (void)setDelaysTouchesBegan:(BOOL)delays {
    UNIMPLEMENTED();

    _delaysTouchesBegan = delays;
}

/**
 @Status Stub
*/
- (void)setDelaysTouchesEnded:(BOOL)delays {
    UNIMPLEMENTED();

    _delaysTouchesEnded = delays;
}

/**
 @Status Interoperable
*/
- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event {
}

/**
 @Status Interoperable
*/
- (void)touchesMoved:(NSSet*)touches withEvent:(UIEvent*)event {
}

/**
 @Status Interoperable
*/
- (void)touchesEnded:(NSSet*)touches withEvent:(UIEvent*)event {
}

/**
 @Status Interoperable
*/
- (void)touchesCancelled:(NSSet*)touches withEvent:(UIEvent*)event {
}

/**
 @Status Interoperable
*/
- (UIGestureRecognizerState)state {
    return _state;
}

- (void)setState:(UIGestureRecognizerState)state {
    _state = state;
}

- (void)_fire {
    for (int i = 0; i < _numTargets; i++) {
        id target = _targets[i]._target;
        SEL sel = _targets[i]._selector;

        [target performSelector:sel withObject:self];
    }
}

/**
 @Status Interoperable
*/
- (void)addTarget:(id)target action:(SEL)action {
    _targets[_numTargets]._target = target;
    _targets[_numTargets]._selector = action;
    _numTargets++;
}

/**
 @Status Interoperable
*/
- (void)reset {
    _state = UIGestureRecognizerStatePossible;
}

/**
 @Status Stub
*/
- (void)requireGestureRecognizerToFail:(UIGestureRecognizer*)gesture {
    UNIMPLEMENTED();
}

+ (BOOL)_fireGestures:(id)gestures shouldCancelTouches:(BOOL&)shouldCancelTouches {
    bool didRecognize = false;

    for (UIGestureRecognizer* curgesture in gestures) {
        UIGestureRecognizerState state = (UIGestureRecognizerState)[curgesture state];

        if (state == UIGestureRecognizerStateRecognized || state == UIGestureRecognizerStateBegan ||
            state == UIGestureRecognizerStateChanged || state == UIGestureRecognizerStateEnded) {
            [curgesture _fire];
            shouldCancelTouches |= curgesture.cancelsTouchesInView;
            didRecognize = true;
        }
    }

    return didRecognize;
}

- (void)cancel {
    if (_state == UIGestureRecognizerStateBegan || _state == UIGestureRecognizerStateChanged) {
        _state = UIGestureRecognizerStateCancelled;
        [self _fire];
    } else {
        _state = UIGestureRecognizerStateCancelled;
    }
}

- (void)_cancelIfActive {
    id curList = [g_curGesturesDict objectForKey:[self class]];
    if ([curList containsObject:self]) {
        [self cancel];
    }
}

+ (void)_cancelActiveExcept:(UIGestureRecognizer*)gesture {
    id curList = [g_curGesturesDict objectForKey:self];
    for (UIGestureRecognizer* curGesture in curList) {
        if (curGesture != gesture) {
            TraceVerbose(TAG, L"Cancelling %hs", object_getClassName(curGesture));
            [curGesture cancel];
        }
    }
}

+ (void)_failActiveExcept:(UIGestureRecognizer*)gesture {
    NSArray* curList = [g_curGesturesDict objectForKey:self];
    for (UIGestureRecognizer* curGesture in curList) {
        if (curGesture != gesture) {
            UIGestureRecognizer* gesture = curGesture;

            if (gesture->_state != UIGestureRecognizerStatePossible) {
                gesture->_state = UIGestureRecognizerStateFailed;
            }
        }
    }
}

/**
 @Status Stub
*/
- (CGPoint)locationInView:(UIView*)view {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (CGPoint)locationOfTouch:(NSUInteger)touchIndex inView:(UIView*)view {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (NSUInteger)numberOfTouches {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (BOOL)canBePreventedByGestureRecognizer:(UIGestureRecognizer*)preventingGestureRecognizer {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (BOOL)canPreventGestureRecognizer:(UIGestureRecognizer*)preventedGestureRecognizer {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (BOOL)shouldBeRequiredToFailByGestureRecognizer:(UIGestureRecognizer*)otherGestureRecognizer {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (BOOL)shouldRequireFailureOfGestureRecognizer:(UIGestureRecognizer*)otherGestureRecognizer {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)ignorePress:(UIPress*)button forEvent:(UIPressesEvent*)event {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)ignoreTouch:(UITouch*)touch forEvent:(UIEvent*)event {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)pressesBegan:(NSSet*)presses withEvent:(UIPressesEvent*)event {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)pressesCancelled:(NSSet*)presses withEvent:(UIPressesEvent*)event {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)pressesChanged:(NSSet*)presses withEvent:(UIPressesEvent*)event {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)pressesEnded:(NSSet*)presses withEvent:(UIPressesEvent*)event {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)removeTarget:(id)target action:(SEL)action {
    UNIMPLEMENTED();
}

@end
