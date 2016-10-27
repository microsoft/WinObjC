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
#import <StubReturn.h>
#import <math.h>

#import <UIKit/UISwipeGestureRecognizer.h>
#import <UIKit/UIGestureRecognizerSubclass.h>

#import "UIGestureRecognizerInternal.h"

@implementation UISwipeGestureRecognizer {
@public
    UISwipeGestureRecognizerDirection _direction;
    NSUInteger _numberOfTouchesRequired;

    CGPoint _startPos;
    double _startTime;
}

static void commonInit(UISwipeGestureRecognizer* self) {
    self->_direction = UISwipeGestureRecognizerDirectionRight;
    self->_numberOfTouchesRequired = 1;
}

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    if (self = [super initWithCoder:coder]) {
        commonInit(self);

        NSString* directionKey = @"UISwipeGestureRecognizer.direction";
        NSString* numberOfTouchesRequiredKey = @"UISwipeGestureRecognizer.numberOfTouchesRequired";

        if ([coder containsValueForKey:directionKey]) {
            _direction = (UISwipeGestureRecognizerDirection)[coder decodeIntForKey:directionKey];
        }

        if ([coder containsValueForKey:numberOfTouchesRequiredKey]) {
            _numberOfTouchesRequired = [coder decodeIntForKey:numberOfTouchesRequiredKey];
        }
    }

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithTarget:(id)target action:(SEL)selector {
    if (self = [super initWithTarget:target action:selector]) {
        commonInit(self);
    }

    return self;
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

/**
 @Status Stub
*/
- (void)setNumberOfTouchesRequired:(NSUInteger)numberOfTouches {
    UNIMPLEMENTED();
    _numberOfTouchesRequired = numberOfTouches;
}

/**
 @Status Stub
*/
- (NSUInteger)numberOfTouchesRequired {
    UNIMPLEMENTED();
    return _numberOfTouchesRequired;
}

/**
 @Status Interoperable
*/
- (void)setDirection:(UISwipeGestureRecognizerDirection)direction {
    _direction = direction;
}

/**
 @Status Interoperable
*/
- (UISwipeGestureRecognizerDirection)direction {
    return _direction;
}

/**
 @Status Interoperable
*/
- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event {
    if ([touches count] != 1) {
        _state = UIGestureRecognizerStateFailed;
        return;
    }
    UITouch* touch = [touches anyObject];
    _startPos = [touch locationInView:[self view]];
    _startTime = [touch timestamp];
}

/**
 @Status Interoperable
*/
- (void)touchesMoved:(NSSet*)touches withEvent:(UIEvent*)event {
    if ([touches count] != 1) {
        _state = UIGestureRecognizerStateFailed;
        return;
    }
    UITouch* touch = [touches anyObject];
    CGPoint curPos;
    curPos = [touch locationInView:[self view]];

    CGPoint normVec = (curPos - _startPos).normalized();
    float angle = atan2(normVec.y, normVec.x) * 180.0 / M_PI;

    while (angle < 0)
        angle += 360.0f;

    // TODO: Make this good
    if ((curPos - _startPos).lenGe(10) && [touch timestamp] - _startTime < 0.1) {
        if (((angle > 340.0f || angle < 20.0f) && _direction == UISwipeGestureRecognizerDirectionRight) ||
            ((angle > 160.0f && angle < 200.0f) && _direction == UISwipeGestureRecognizerDirectionLeft) ||
            ((angle > 70.0f && angle < 110.0f) && _direction == UISwipeGestureRecognizerDirectionDown) ||
            ((angle > 250.0f && angle <= 290.0f) && _direction == UISwipeGestureRecognizerDirectionUp)) {
            _state = UIGestureRecognizerStateRecognized;
        } else {
            _state = UIGestureRecognizerStateFailed;
        }
    }
}

/**
 @Status Interoperable
*/
- (void)touchesEnded:(NSSet*)touches withEvent:(UIEvent*)event {
    _startPos = { 0, 0 };
}

/**
 @Status Interoperable
*/
- (void)touchesCancelled:(NSSet*)touches withEvent:(UIEvent*)event {
    _startPos = { 0, 0 };
}

/**
 @Status Interoperable
*/
- (CGPoint)locationInView:(UIView*)view {
    return [[self view] convertPoint:_startPos toView:view];
}
@end
