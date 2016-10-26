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

#import <Starboard.h>
#import <math.h>

#import <Foundation/NSMutableDictionary.h>
#import <Foundation/NSMutableArray.h>
#import <Foundation/NSValue.h>
#import <Foundation/NSString.h>
#import <Foundation/NSTimer.h>
#import <UIKit/UITapGestureRecognizer.h>
#import <UIKit/UIGestureRecognizerSubclass.h>

#import "CACompositor.h"
#import "UIGestureRecognizerInternal.h"
#include "LoggingNative.h"

static const wchar_t* TAG = L"UITapGestureRecognizer";

static id _pendingTaps;
extern NSMutableDictionary* g_curGesturesDict;

#define TAP_SLACK_AREA \
    (((GetCACompositor()->screenWidth() / GetCACompositor()->deviceWidth()) * GetCACompositor()->screenXDpi()) / 3.0f) //  1/3 inch

@interface UITapRecognizer : NSObject {
@public
    DWORD _numberOfTapsRequired;
}
@end

@implementation UITapRecognizer

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    _numberOfTapsRequired = 1;
    if ([coder containsValueForKey:@"UITapRecognizer.numberOfTapsRequired"]) {
        _numberOfTapsRequired = [coder decodeIntForKey:@"UITapRecognizer.numberOfTapsRequired"];
    }
    return self;
}

@end

@implementation UITapGestureRecognizer {
    unsigned _numberOfTapsRequired;
    unsigned _numberOfTouchesRequired;
    unsigned _numTapsReceived;
    unsigned _maxTouches;
    double _tapTime;

    struct savedTouch _savedTouches[32];
    int _numSavedTouches;
    id _recognizeTimer;
    bool _wasRecognized;
    bool _wasReset;
    bool _delayRecognition;
}

static savedTouch* findTouch(UITapGestureRecognizer* self, id touch) {
    for (int i = 0; i < self->_numSavedTouches; i++) {
        if (self->_savedTouches[i]._touch == touch) {
            return &self->_savedTouches[i];
        }
    }

    return NULL;
}

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    [super initWithCoder:coder];
    _numberOfTouchesRequired = 1;
    _numberOfTapsRequired = 1;

    UITapRecognizer* imp = [coder decodeObjectForKey:@"UITapGestureRecognizer._imp"];
    if (imp != nil) {
        _numberOfTapsRequired = imp->_numberOfTapsRequired;
    }
    TraceVerbose(TAG, L"number of taps required - %d", _numberOfTapsRequired);
    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithTarget:(id)target action:(SEL)selector {
    [super initWithTarget:target action:selector];
    _numberOfTapsRequired = 1;
    _numberOfTouchesRequired = 1;
    return self;
}

/**
 @Status Interoperable
*/
- (void)setNumberOfTapsRequired:(unsigned)numberOfTaps {
    _numberOfTapsRequired = numberOfTaps;
}

/**
 @Status Interoperable
*/
- (unsigned)numberOfTapsRequired {
    return _numberOfTapsRequired;
}

/**
 @Status Interoperable
*/
- (void)setNumberOfTouchesRequired:(unsigned)numberOfTouches {
    _numberOfTouchesRequired = numberOfTouches;
}

static void resetSavedTouches(UITapGestureRecognizer* self) {
    for (int i = 0; i < self->_numSavedTouches; i++) {
        [self->_savedTouches[i]._touch release];
    }
    self->_numSavedTouches = 0;
}

/**
 @Status Interoperable
*/
- (void)reset {
    _numTapsReceived = 0;
    _state = UIGestureRecognizerStatePossible;
    _maxTouches = 0;
    _wasReset = true;
    _delayRecognition = false;

    if (_recognizeTimer == nil) {
        resetSavedTouches(self);
    }
    [super reset];
}

/**
 @Status Interoperable
*/
- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event {
    TraceVerbose(TAG, L"Touch Began");
    id curTouch = [touches anyObject];
    _tapTime = EbrGetMediaTime();

    if (_wasReset) {
        _wasReset = false;
        resetSavedTouches(self);
    }

    CGPoint curPos;
    curPos = [curTouch locationInView:nil];

    _savedTouches[_numSavedTouches]._touch = [curTouch retain];
    _savedTouches[_numSavedTouches]._savedPos = curPos;
    _numSavedTouches++;

    if ([[event allTouches] count] > _maxTouches) {
        _maxTouches = [[event allTouches] count];
    }

    TraceVerbose(TAG, L"Tap touch detected %x", curTouch);
    if (_numberOfTapsRequired == 1) {
        //  Delay the tap gesture recognition if there's more than one tap gesture recognizer
        bool shouldDelay = false;

        id curList = [g_curGesturesDict objectForKey:[UITapGestureRecognizer class]];
        for (id curGesture in curList) {
            // check if in current gesture list, any gesture required more than one tap
            // if so, we should delay firing current tap, to make sure multiple-tap get fired first.
            if ([curGesture numberOfTapsRequired] > 1) {
                shouldDelay = true;
            }
        }

        if (_recognizeTimer != nil) {
            [_recognizeTimer invalidate];
        }
        if (shouldDelay) {
            _recognizeTimer =
                [NSTimer scheduledTimerWithTimeInterval:0.35 target:self selector:@selector(_fireRecognized) userInfo:nil repeats:FALSE];
            if (_pendingTaps == nil) {
                _pendingTaps = [NSMutableArray new];
            }
            [_pendingTaps removeObject:self];
            [_pendingTaps addObject:self];
            _delayRecognition = true;
        }
    }
}

/**
 @Status Interoperable
*/
- (void)touchesMoved:(NSSet*)touches withEvent:(UIEvent*)event {
    TraceVerbose(TAG, L"Touch Moved");
    id curTouch = [touches anyObject];
    CGPoint curPos;
    curPos = [curTouch locationInView:nil];

    savedTouch* save = findTouch(self, curTouch);
    if (save != NULL) {
        CGPoint startPos = save->_savedPos;

        if (startPos.distGr(curPos, 10.0f)) {
            TraceVerbose(TAG, L"touch moved too far");
            _state = UIGestureRecognizerStateFailed;
            [_pendingTaps removeObject:self];
            [_recognizeTimer invalidate];
            _recognizeTimer = nil;
            _wasRecognized = false;
        }
    } else {
        TraceVerbose(TAG, L"touch %x not found - count=%d", curTouch, _numSavedTouches);
    }
}

/**
 @Status Interoperable
*/
- (void)touchesEnded:(NSSet*)touches withEvent:(UIEvent*)event {
    TraceVerbose(TAG, L"Touch Ended");
    id curTouch = [touches anyObject];
    CGPoint curPos;
    curPos = [curTouch locationInView:nil];
    savedTouch* save = findTouch(self, curTouch);
    if (save != NULL) {
        CGPoint startPos = save->_savedPos;

        if (startPos.distGr(curPos, TAP_SLACK_AREA)) {
            TraceVerbose(TAG, L"touch moved too far on end");
            _state = UIGestureRecognizerStateFailed;
        }
    } else {
        TraceVerbose(TAG, L"touch not found");
    }

    id allTouches = [event allTouches];

    // We may have to revisit this logic, since the UITouch tap count should drive it.
    if (_maxTouches > _numberOfTouchesRequired || EbrGetMediaTime() - _tapTime > 0.75f) {
        TraceVerbose(TAG, L"too many touches, numberOfTouchesRequired=%d, _maxTouches=%d", _numberOfTouchesRequired, _maxTouches);
        _state = UIGestureRecognizerStateFailed;
    } else if (_maxTouches == _numberOfTouchesRequired) {
        bool success = true;

        // get max numberofTapsRequired in current Tap gesture list.
        unsigned maxNumberOfTapsRequired = 0;
        for (id curGesture in [g_curGesturesDict objectForKey:[UITapGestureRecognizer class]]) {
            if ([curGesture numberOfTapsRequired] > maxNumberOfTapsRequired) {
                maxNumberOfTapsRequired = [curGesture numberOfTapsRequired];
            }
        }

        for (id curTouch in allTouches) {
            unsigned tapCount = [curTouch tapCount];
            if ((maxNumberOfTapsRequired > _numberOfTapsRequired) && (tapCount > _numberOfTapsRequired)) {
                TraceVerbose(TAG, L"too many taps, tapCount=%d, numberOfTapsRequired=%d", tapCount, _numberOfTapsRequired);
                _state = UIGestureRecognizerStateFailed;
                success = false;
            } else if (tapCount < _numberOfTapsRequired) {
                success = false;
            }
        }

        if (success) {
            if (_delayRecognition) {
                _wasRecognized = true;
            } else {
                _state = UIGestureRecognizerStateRecognized;
                [[self class] _failActiveExcept:self];
                TraceVerbose(TAG, L"recognized.");
            }
        } else {
            [_pendingTaps removeObject:self];
            [_recognizeTimer invalidate];
            _recognizeTimer = nil;
            _wasRecognized = false;
        }
    }
}

- (id)_fireRecognized {
    if (_wasRecognized) {
        UITapGestureRecognizer* fireGesture = nil;
        for (id curObj in _pendingTaps) {
            UITapGestureRecognizer* _cur = curObj;
            if (_cur->_wasRecognized) {
                fireGesture = curObj;
            }
            _cur->_wasRecognized = false;
        }
        [_pendingTaps removeObject:self];
        if (fireGesture == nil) {
            fireGesture = self;
        }
        fireGesture->_state = UIGestureRecognizerStateRecognized;
        [fireGesture _fire];
    } else {
        [_pendingTaps removeObject:self];
    }
    [_recognizeTimer invalidate];
    _recognizeTimer = nil;

    //  Set to cancelled so that it will be removed from the potential gesture list
    [self reset];
    return self;
}

/**
 @Status Interoperable
*/
- (unsigned)numberOfTouches {
    return _numSavedTouches;
}

/**
 @Status Interoperable
*/
- (CGPoint)locationInView:(id)viewAddr {
    if (_numSavedTouches > 0) {
        id touch = _savedTouches[0]._touch;
        return [touch locationInView:viewAddr];
    }

    CGPoint ret = { 0, 0 };
    return ret;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    for (int i = 0; i < _numSavedTouches; i++) {
        [_savedTouches[i]._touch release];
    }
    [_pendingTaps removeObject:self];
    [_recognizeTimer invalidate];
    _recognizeTimer = nil;

    [super dealloc];
}

@end
