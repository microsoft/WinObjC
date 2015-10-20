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

#include <math.h>
#include "UIKit/UIKit.h"

#include "UIGestureRecognizerInternal.h"

@implementation UIPinchGestureRecognizer {
    struct TrackingTouch {
        id touch;
        CGPoint _firstTouchPos, _lastTouchPos, _prevTouchPos;
        double _lastTouchTime, _prevTouchTime, _firstTouchTime;
    };

    TrackingTouch _touches[2];
    int _numTouches;
    id _touchedView;
    float _startScale, _curScale;
    bool _startedPinch;
}

static TrackingTouch* findTouch(UIPinchGestureRecognizer* self, UITouch* touch) {
    for (int i = 0; i < self->_numTouches; i++) {
        if (self->_touches[i].touch == touch) {
            return &self->_touches[i];
        }
    }

    return NULL;
}

static void deleteTouch(UIPinchGestureRecognizer* self, UITouch* touch) {
    for (int i = 0; i < self->_numTouches; i++) {
        if (self->_touches[i].touch == touch) {
            memmove(&self->_touches[i], &self->_touches[i + 1], (1 - i) * sizeof(TrackingTouch));
            self->_numTouches--;
            return;
        }
    }
}

- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event {
    UITouch* touch = [touches anyObject];

    if (_numTouches < 2) {
        _touches[_numTouches]._firstTouchPos = [touch locationInView:nil];
        _touches[_numTouches]._firstTouchTime = _touches[_numTouches]._prevTouchTime = _touches[_numTouches]._lastTouchTime =
            [touch timestamp];
        _touches[_numTouches]._lastTouchPos = _touches[_numTouches]._firstTouchPos;
        _touches[_numTouches].touch = touch;
        _numTouches++;
    }
}

- (void)touchesEnded:(NSSet*)touches withEvent:(UIEvent*)event {
    UITouch* touch = [touches anyObject];

    deleteTouch(self, touch);
    if (_numTouches == 0) {
        switch (_state) {
            case UIGestureRecognizerStateBegan:
            case UIGestureRecognizerStateChanged:
                _state = UIGestureRecognizerStateEnded;
                _startedPinch = false;
                break;

            case UIGestureRecognizerStatePossible:
                if (_startedPinch) {
                    _state = UIGestureRecognizerStateEnded;
                } else {
                    _state = UIGestureRecognizerStateFailed;
                }
                _startedPinch = false;
                break;

            default:
                break;
        }
    } else if (_numTouches == 1) {
        _state = UIGestureRecognizerStatePossible;
    }
}

- (void)touchesMoved:(NSSet*)touches withEvent:(UIEvent*)event {
    UITouch* touch = [touches anyObject];

    TrackingTouch* trackedTouch = findTouch(self, touch);
    if (trackedTouch != NULL) {
        CGPoint pos;
        pos = [touch locationInView:nil];

        _touchedView = [touch view];

        trackedTouch->_prevTouchPos = trackedTouch->_lastTouchPos;
        trackedTouch->_prevTouchTime = trackedTouch->_lastTouchTime;
        trackedTouch->_lastTouchPos = pos;
        trackedTouch->_lastTouchTime = [touch timestamp];

        if (_numTouches == 2) {
            float curDist = _touches[0]._lastTouchPos.dist(_touches[1]._lastTouchPos);
            float firstDist = _touches[0]._firstTouchPos.dist(_touches[1]._firstTouchPos);

            switch (_state) {
                case UIGestureRecognizerStatePossible:
                    if (curDist != firstDist) {
                        BOOL start = TRUE;

                        if ([_delegate respondsToSelector:@selector(gestureRecognizerShouldBegin:)]) {
                            start = [_delegate gestureRecognizerShouldBegin:self];
                        }

                        if (start) {
                            _curScale = _startScale;
                            _state = UIGestureRecognizerStateBegan;
                        } else {
                            _state = UIGestureRecognizerStateFailed;
                        }
                    }
                    break;

                case UIGestureRecognizerStateBegan:
                    _curScale = _startScale * curDist / firstDist;
                    _state = UIGestureRecognizerStateChanged;
                    _startedPinch = true;
                    break;

                case UIGestureRecognizerStateChanged:
                    _curScale = _startScale * curDist / firstDist;
                    break;

                default:
                    break;
            }
        } else {
            //  Keep track of the first touch location
            trackedTouch->_firstTouchTime = trackedTouch->_lastTouchTime;
            trackedTouch->_firstTouchPos = trackedTouch->_lastTouchPos;
        }
    }
}

- (void)setScale:(float)scale {
    _curScale = scale;
    _startScale = scale;
    _touches[0]._firstTouchPos = _touches[0]._lastTouchPos;
    _touches[1]._firstTouchPos = _touches[1]._lastTouchPos;
}

- (float)startScale {
    return _startScale;
}

- (float)scale {
    return _curScale;
}

- (UIView*)_touchedView {
    return _touchedView;
}

- (CGPoint)locationInView:(UIView*)viewAddr {
    CGPoint pos1, pos2;

    pos1 = [[viewAddr window] convertPoint:_touches[0]._lastTouchPos fromView:nil toView:viewAddr];
    pos2 = [[viewAddr window] convertPoint:_touches[1]._lastTouchPos fromView:nil toView:viewAddr];

    CGPoint ret;
    ret = (pos1 + pos2) / 2.0f;

    return ret;
}

- (instancetype)initWithTarget:(id)target action:(SEL)selector {
    [super initWithTarget:target action:selector];

    _curScale = 1.0f;
    _startScale = 1.0f;
    _startedPinch = false;

    return self;
}

- (instancetype)init {
    [super init];

    _curScale = 1.0f;
    _startScale = 1.0f;
    _startedPinch = false;

    return self;
}

- (NSUInteger)numberOfTouches {
    return 2;
}
@end
