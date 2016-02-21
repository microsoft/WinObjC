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

#import <StubReturn.h>
#import <vector>
#import <Starboard.h>

#import <Foundation/NSTimer.h>
#import <UIKit/UILongPressGestureRecognizer.h>
#import <UIKit/UIGestureRecognizerSubclass.h>

#import "UIGestureRecognizerInternal.h"

// used to track a single touch and its startPosition
typedef struct {
    UITouch* touch;
    CGPoint startPosition;
} TrackedTouch;


@implementation UILongPressGestureRecognizer {
    // tracking a list of tracked touch
    std::vector<TrackedTouch> _trackedTouches;

    // timer to fire when minimumPressDuration is reached
    idretaintype(NSTimer) _recognizeTimer;
}

@synthesize minimumPressDuration;
@synthesize allowableMovement;
@synthesize numberOfTapsRequired;
@synthesize numberOfTouchesRequired;

/**
 @Status Interoperable
*/
- (instancetype)initWithTarget:(id)target action:(SEL)selector {
    if (self = [super initWithTarget:target action:selector]) {
        [self _commonInit];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    if (self = [super init]) {
        [self _commonInit];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (id)initWithCoder:(NSCoder*)coder {
    if (self = [super initWithCoder:coder]) {
        [self _commonInit];

        NSString* minimumPressDuration = @"UILongPressGestureRecognizer.minimumPressDuration";
        NSString* allowableMovement = @"UILongPressGestureRecognizer.allowableMovement";
        NSString* numberOfTapsRequired = @"UILongPressGestureRecognizer.numberOfTapsRequired";
        NSString* numberOfTouchesRequired = @"UILongPressGestureRecognizer.numberOfTouchesRequired";

        if ([coder containsValueForKey:minimumPressDuration]) {
            self->minimumPressDuration = [coder decodeIntForKey:minimumPressDuration];
        }

        if ([coder containsValueForKey:allowableMovement]) {
            self->allowableMovement = [coder decodeIntForKey:allowableMovement];
        }

        if ([coder containsValueForKey:numberOfTapsRequired]) {
            self->numberOfTapsRequired = [coder decodeIntForKey:numberOfTapsRequired];
        }

        if ([coder containsValueForKey:numberOfTouchesRequired]) {
            self->numberOfTouchesRequired = [coder decodeIntForKey:numberOfTouchesRequired];
        }
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    if (_recognizeTimer != nil) {
        [_recognizeTimer invalidate];
    }
    [super dealloc];
}

/**
 @Status Interoperable
*/
- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event {
    EbrDebugLog("UILongPressGestureRecognizer:touchesBegan. begining state = %d\n", self.state);

    // Add each of the new presses to our list of tracked ones:
    for (UITouch* touch in touches) {
        FAIL_FAST_HR_IF(E_UNEXPECTED, [touch phase] != UITouchPhaseBegan);
        TrackedTouch curTouch;
        curTouch.touch = touch;
        curTouch.startPosition = [touch locationInView:nil];
        _trackedTouches.push_back(curTouch);
    }

    // when tracked touches met the minimum required, fire the timer
    if (_trackedTouches.size() >= numberOfTouchesRequired && _recognizeTimer == nil) {
        EbrDebugLog("UILongPressGestureRecognizer:touchesBegan starting recognizer timer.\n");
        _recognizeTimer = [NSTimer scheduledTimerWithTimeInterval:minimumPressDuration
                                                           target:self
                                                         selector:@selector(_recognizeTimerFired)
                                                         userInfo:nil
                                                          repeats:FALSE];
    }

    EbrDebugLog("UILongPressGestureRecognizer:touchesBegan. ending state = %d\n", self.state);
}

static TrackedTouch* findTouch(UITouch* touch, std::vector<TrackedTouch>& touches) {
    for (size_t i = 0; i < touches.size(); i++) {
        if (touches[i].touch == touch)
            return &touches[i];
    }

    return NULL;
}

/**
 @Status Interoperable
*/
- (void)touchesMoved:(NSSet*)touches withEvent:(UIEvent*)event {
    EbrDebugLog("UILongPressGestureRecognizer:touchesMoved. begining state = %d\n", self.state);

    // for each of the touch, caculate the distance
    for (UITouch* touch in touches) {
        FAIL_FAST_HR_IF(E_UNEXPECTED, [touch phase] != UITouchPhaseMoved);
        TrackedTouch* originalTouch = findTouch(touch, _trackedTouches);
        if (originalTouch == nil) {
            continue;
        }

        CGPoint currentPosition = [touch locationInView:nil];
        CGPoint originalPostion = originalTouch->startPosition;

        if (sqrt(pow(currentPosition.x - originalPostion.x, 2) + pow(currentPosition.y - originalPostion.y, 2)) > allowableMovement) {
            // distance moved more than allowed for one touch, transit the state to corresponding state and invaldiate timer
            // if a gesture has already been UIGestureRecognizerStateBegan or UIGestureRecognizerStateChanged state
            // The gesture should transit to ended state .
            // if a gesture is in possible state, has not began yet, it will transit to failed state directly
            EbrDebugLog("UILongPressGestureRecognizer:touchesMoved distance beyond allowable distance\n");

            if (self.state == UIGestureRecognizerStateBegan || self.state == UIGestureRecognizerStateChanged) {
                self.state = UIGestureRecognizerStateEnded;
            } else if (self.state == UIGestureRecognizerStatePossible) {
                self.state = UIGestureRecognizerStateFailed;
            }

            // in any case, invalidate the timer if necessary
            if (_recognizeTimer != nil) {
                [_recognizeTimer invalidate];
            }
            break;
        }
    }

    if ((self.state != UIGestureRecognizerStateEnded) && (self.state != UIGestureRecognizerStateFailed)) {
        // after distance calculation, if gesture didn't fail, transit state to change state if it is already Began state
        if (self.state == UIGestureRecognizerStateBegan) {
            self.state = UIGestureRecognizerStateChanged;
        } else {
            // otherwise, the gesture should must be in possible state or changed state and should continue to be so
            FAIL_FAST_HR_IF(E_UNEXPECTED, self.state != UIGestureRecognizerStatePossible && self.state != UIGestureRecognizerStateChanged);
        }
    }

    EbrDebugLog("UILongPressGestureRecognizer:touchesMoved. ending state = %d\n", self.state);
}

/**
 @Status Interoperable
*/
- (void)touchesEnded:(NSSet*)touches withEvent:(UIEvent*)event {
    EbrDebugLog("UILongPressGestureRecognizer:touchesEnded. begining state = %d\n", self.state);

    for (UITouch* touch in touches) {
        TrackedTouch* originalTouch = findTouch(touch, _trackedTouches);
        if (originalTouch == nil) {
            continue;
        }

        // otherwise, we found a tracked finger is lifted, end the gesture
        if (self.state == UIGestureRecognizerStateBegan || self.state == UIGestureRecognizerStateChanged) {
            self.state = UIGestureRecognizerStateEnded;
        } else if (self.state == UIGestureRecognizerStatePossible || self.state == UIGestureRecognizerStateChanged) {
            self.state = UIGestureRecognizerStateFailed;
        }
    }

    EbrDebugLog("UILongPressGestureRecognizer:touchesEnded. ending state = %d\n", self.state);
}

/**
 @Status Interoperable
*/
- (void)reset {
    EbrDebugLog("UILongPressGestureRecognizer:reset. begining state = %d\n", self.state);

    _trackedTouches.clear();

    if (_recognizeTimer != nil) {
        EbrDebugLog("UILongPressGestureRecognizer:reset invalidate timer.\n");
        [_recognizeTimer invalidate];
        _recognizeTimer = nil;
    }

    [super reset];

    EbrDebugLog("UILongPressGestureRecognizer:reset. ending state = %d\n", self.state);
}

/**
 @Status Interoperable
*/
- (void)touchesCancelled:(NSSet*)touches withEvent:(UIEvent*)event {
    EbrDebugLog("[UILongPressGestureRecognizer:touchesCancelled.\n");
    self.state = UIGestureRecognizerStateCancelled;
    [self reset];
}

- (void)_commonInit {
    self->minimumPressDuration = 0.5f;
    self->numberOfTapsRequired = 0;
    self->numberOfTouchesRequired = 1;
    self->allowableMovement = 10;
}

- (void)_recognizeTimerFired {
    EbrDebugLog("UILongPressGestureRecognizer:_recognizeTimerFired, current state %d.\n", self.state);
    // when timer fires, current staste must be possible, transit the state to Began state
    FAIL_FAST_HR_IF(E_UNEXPECTED, self.state != UIGestureRecognizerStatePossible);
    self.state = UIGestureRecognizerStateBegan;
    [self _fire];
}

@end
