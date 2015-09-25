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

#include "UIKit/UIKit.h"
#include <math.h>

#include "UIGestureRecognizerInternal.h"

@implementation UISwipeGestureRecognizer {
@public
    UISwipeGestureRecognizerDirection _direction;
    NSUInteger _numberOfTouchesRequired;

    CGPoint _startPos;
    double _startTime;
}

- (instancetype)initWithCoder:(NSCoder*)coder {
    [super initWithCoder:coder];
    if ([coder containsValueForKey:@"UISwipeGestureRecognizer.direction"]) {
        _direction = (UISwipeGestureRecognizerDirection)[coder decodeIntForKey:@"UISwipeGestureRecognizer.direction"];
    } else {
        // Use this as a default:
        _direction = UISwipeGestureRecognizerDirectionRight;
    }
    _numberOfTouchesRequired = 1;

    return self;
}

- (instancetype)initWithTarget:(id)target action:(SEL)selector {
    [super initWithTarget:target action:selector];

    // Use this as a default:
    _direction = UISwipeGestureRecognizerDirectionRight;
    _numberOfTouchesRequired = 1;
    return self;
}

- (instancetype)init {
    [super init];

    _direction = UISwipeGestureRecognizerDirectionRight;
    _numberOfTouchesRequired = 1;

    return self;
}

- (void)setNumberOfTouchesRequired:(NSUInteger)numberOfTouches {
    _numberOfTouchesRequired = numberOfTouches;
}

- (NSUInteger)numberOfTouchesRequired {
    return _numberOfTouchesRequired;
}

- (void)setDirection:(UISwipeGestureRecognizerDirection)direction {
    _direction = direction;
}

- (UISwipeGestureRecognizerDirection)direction {
    return _direction;
}

- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event {
    if ([touches count] != 1) {
        _state = UIGestureRecognizerStateFailed;
        return;
    }
    UITouch* touch = [touches anyObject];
    _startPos = [touch locationInView:[self view]];
    _startTime = [touch timestamp];
}

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

- (void)touchesEnded:(NSSet*)touches withEvent:(UIEvent*)event {
}

- (CGPoint)locationInView:(UIView*)viewAddr {
    return CGPointMake(0, 0);
}
@end
