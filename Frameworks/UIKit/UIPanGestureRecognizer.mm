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

#import "Starboard.h"

#import <UIKit/UIGestureRecognizerSubclass.h>
#import <UIKit/UIPanGestureRecognizer.h>
#import <UIKit/UITouch.h>
#import <UIKit/UIWindow.h>

#import <Foundation/NSMutableDictionary.h>
#import <Foundation/NSValue.h>
#import <Foundation/NSString.h>

#import "UIGestureRecognizerInternal.h"
#import "LoggingNative.h"
#import "UIScrollViewInternal.h"
#import "UITouchInternal.h"
#import "UIPanGestureRecognizerInternal.h"
#import "UIWindowInternal.h"

#import <vector>

static const wchar_t* TAG = L"UIPanGestureRecognizer";

#define VELOCITY_THRESHOLD 50.0f

@implementation UIPanGestureRecognizer {
    CGPoint _translation;
    CGPoint _velocity;
    NSTimeInterval _lastMovementTime;

    struct Private* _priv;

    UIView* _touchedView;

    // Configurable properties of the gesture:
    float _dragSlack;
    double _disableVelocity;

    bool _didFireEnded;
    bool _lockVertical, _lockHorizontal;
}

static void commonInit(UIPanGestureRecognizer* self) {
    self->_dragSlack = 5.0f;
    self->_minimumNumberOfTouches = 1;
    self->_maximumNumberOfTouches = NSUIntegerMax;
    self->_priv = new Private;
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
 @Status Caveat
 @Notes May not be fully implemented
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    if (self = [super initWithCoder:coder]) {
        commonInit(self);

        NSString* minimumNumberOfTouchesKey = @"UIPanGestureRecognizer.minimumNumberOfTouches";
        NSString* maximumNumberOfTouchesKey = @"UIPanGestureRecognizer.maximumNumberOfTouches";

        if ([coder containsValueForKey:minimumNumberOfTouchesKey]) {
            _minimumNumberOfTouches = [coder decodeIntForKey:minimumNumberOfTouchesKey];
        }

        if ([coder containsValueForKey:maximumNumberOfTouchesKey]) {
            _maximumNumberOfTouches = [coder decodeIntForKey:maximumNumberOfTouchesKey];
        }
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    delete _priv;
    [super dealloc];
}

/**
 @Status Interoperable
*/
- (void)setMinimumNumberOfTouches:(NSUInteger)numberOfTouches {
    _minimumNumberOfTouches = numberOfTouches;
}

/**
 @Status Interoperable
*/
- (void)setMaximumNumberOfTouches:(NSUInteger)numberOfTouches {
    _maximumNumberOfTouches = numberOfTouches;
}

static void numTouchesChanged(UIPanGestureRecognizer* o) {
    // End or fail the gesture if we have too many touches to make a match:
    if (o->_priv->touches.size() > o->_maximumNumberOfTouches || o->_priv->touches.size() < o->_minimumNumberOfTouches) {
        switch (o->_state) {
            case UIGestureRecognizerStateBegan:
            case UIGestureRecognizerStateChanged:
                o->_state = UIGestureRecognizerStateEnded;
                break;

            case UIGestureRecognizerStatePossible:
                if (o->_priv->touches.size() == 0) {
                    o->_state = UIGestureRecognizerStateFailed;
                } else {
                    // If we have non-zero fingers down, we may still be able to match - we don't want to remove
                    // ourselves from the list of possible gestures.
                }
                break;
            default:
                UNIMPLEMENTED_WITH_MSG("Unsupported gesture recoginizer state (%d)", o->_state);
                break;
        }
    }
}

static CGPoint getAverageVelocity(double disableVelocity, const std::vector<TouchInfo>& touches) {
    if (EbrGetMediaTime() < disableVelocity) {
        CGPoint ret = { 0, 0 };
        return ret;
    }

    float dirX = 0.0f, dirY = 0.0f;
    CGPoint ret = { 0, 0 };
    float numAverages = 0.0f;
    for (size_t i = 0; i < touches.size(); i++) {
        CGPoint touchVelocity = CGPointMake(touches[i].touch->_velocityX, touches[i].touch->_velocityY);
        ret.x += touchVelocity.x;
        ret.y += touchVelocity.y;
        numAverages += 1.0f;

        //  Make sure all fingers are moving in the same general direction
        float touchDirX = 0.0f, touchDirY = 0.0f;
        if (touchVelocity.x > 0.0f) {
            touchDirX = 1.0f;
        } else if (touchVelocity.x < 0.0f) {
            touchDirX = -1.0f;
        }
        if (touchVelocity.x > 0.0f) {
            touchDirY = 1.0f;
        } else if (touchVelocity.x < 0.0f) {
            touchDirY = -1.0f;
        }
        if (dirX == 0.0f)
            dirX = touchDirX;
        if (dirY == 0.0f)
            dirY = touchDirY;

        if ((dirX != 0.0f && dirX != touchDirX) || (dirY != 0.0f && dirY != touchDirY)) {
            ret.x = 0.0f;
            ret.y = 0.0f;
            return ret;
        }
    }

    if (numAverages > 0.0f) {
        ret.x /= numAverages;
        ret.y /= numAverages;
    }

    return ret;
}

static TouchInfo* findTouch(UITouch* touch, std::vector<TouchInfo>& touches) {
    for (size_t i = 0; i < touches.size(); i++) {
        if (touches[i].touch == touch)
            return &touches[i];
    }

    return NULL;
}

static void deleteTouch(UITouch* touch, std::vector<TouchInfo>& touches) {
    for (size_t i = 0; i < touches.size(); i++) {
        if (touches[i].touch == touch) {
            touches.erase(touches.begin() + i);
            return;
        }
    }
    assert(!"Trying to remove unmatched touch!");
}

/**
 @Status Interoperable
*/
- (NSUInteger)numberOfTouches {
    return _priv->touches.size();
}

/**
 @Status Interoperable
*/
- (CGPoint)locationOfTouch:(NSUInteger)index inView:(UIView*)viewAddr {
    CGPoint ret;
    ret = [_priv->touches[index].touch locationInView:viewAddr];

    return ret;
}

/**
 @Status Interoperable
*/
- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event {
    if (_priv->touches.size() == 0) {
        _priv->currentTranslation.x = 0.f;
        _priv->currentTranslation.y = 0.f;
    }

    // Add each of the new presses to our list of tracked ones:
    for (UITouch* touch in touches) {
        assert([touch phase] == UITouchPhaseBegan);

        TouchInfo curTouch;
        curTouch.touch = touch;
        curTouch.startTime = [touch timestamp];

        CGPoint pos;
        pos = [touch locationInView:nil];

        curTouch.startPos = curTouch.lastPos = pos;
        _touchedView = [touch view];
        _priv->touches.push_back(curTouch);
    }

    _priv->lastCenter = lastMidpoint(_priv->touches);
    _priv->currentVelocity = getAverageVelocity(_disableVelocity, _priv->touches);

    if (_state == UIGestureRecognizerStatePossible && _priv->touches.size() >= _minimumNumberOfTouches &&
        _priv->touches.size() <= _maximumNumberOfTouches) {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-method-access"
        // TODO: File bug
        if ([_delegate respondsToSelector:@selector(_gestureRecognizerTouchesReached:)]) {
            [_delegate _gestureRecognizerTouchesReached:self];
        }
    }
#pragma clang diagnostic pop

    numTouchesChanged(self);
}

static CGPoint lastMidpoint(const std::vector<TouchInfo>& touches) {
    CGPoint lastMidpoint = { 0, 0 };
    for (size_t i = 0; i < touches.size(); ++i) {
        lastMidpoint += touches[i].lastPos;
    }
    lastMidpoint /= float(touches.size());
    return lastMidpoint;
}

/**
 @Status Interoperable
*/
- (void)touchesMoved:(NSSet*)touches withEvent:(UIEvent*)event {
    CGPoint prevPos = lastMidpoint(_priv->touches);

    for (UITouch* touch in touches) {
        assert([touch phase] == UITouchPhaseMoved);
        TouchInfo* info = findTouch(touch, _priv->touches);

        if (!info) {
            FAIL_FAST();
        }

        info->lastPos = [touch locationInView:nil];
    }

    _priv->lastCenter = lastMidpoint(_priv->touches);
    CGPoint delta = _priv->lastCenter - prevPos;
    _priv->currentTranslation += delta;

    _priv->currentVelocity = getAverageVelocity(_disableVelocity, _priv->touches);

    if (_state == UIGestureRecognizerStatePossible && _priv->touches.size() >= _minimumNumberOfTouches &&
        _priv->touches.size() <= _maximumNumberOfTouches) {
        if (_priv->currentTranslation.lenGe(_dragSlack)) {
            BOOL start = TRUE;

            if ([_delegate respondsToSelector:@selector(gestureRecognizerShouldBegin:)]) {
                start = [_delegate gestureRecognizerShouldBegin:self];
            }

            if (start) {
                _state = UIGestureRecognizerStateBegan;
                TraceVerbose(TAG, L"Pan gesture recognized");
            } else {
                _state = UIGestureRecognizerStateFailed;
            }
        }
    } else if (_state == UIGestureRecognizerStateBegan) {
        _state = UIGestureRecognizerStateChanged;
    }
}

/**
 @Status Interoperable
*/
- (void)touchesEnded:(NSSet*)touches withEvent:(UIEvent*)event {
    // account for the timestamp and any final movement on the finger up event:
    for (UITouch* touch in touches) {
        assert([touch phase] == UITouchPhaseEnded);
        TouchInfo* info = findTouch(touch, _priv->touches);

        if (!info) {
            FAIL_FAST();
        }

        info->lastPos = [touch locationInView:nil];
    }

    _priv->currentVelocity = getAverageVelocity(_disableVelocity, _priv->touches);
    CGPoint currentMidpoint = lastMidpoint(_priv->touches);

    // remove this point:
    CGPoint prevMidpoint = lastMidpoint(_priv->touches);
    for (UITouch* touch in touches) {
        TouchInfo* info = findTouch(touch, _priv->touches);

        if (!info) {
            continue;
        }
        deleteTouch(touch, _priv->touches);
    }

    _priv->lastCenter = lastMidpoint(_priv->touches);

    numTouchesChanged(self);

    //  After each finger comes up, disable velocity calculations for 250ms
    _disableVelocity = EbrGetMediaTime() + 0.25;
}

static CGPoint pointToView(const CGPoint& pt, UIView* viewAddr) {
    CGPoint newPt;
    newPt = [[viewAddr window] _convertPoint:pt fromView:nil toView:viewAddr];
    return newPt;
}

static CGPoint pointFromView(const CGPoint& pt, UIView* viewAddr) {
    CGPoint newPt;
    newPt = [[viewAddr window] _convertPoint:pt fromView:viewAddr toView:nil];
    return newPt;
}

/**
 @Status Interoperable
*/
- (CGPoint)translationInView:(UIView*)viewAddr {
    const CGPoint origin = { 0, 0 };

    CGPoint ret;
    ret = pointToView(_priv->currentTranslation, viewAddr) - pointToView(origin, viewAddr);

    if (_lockVertical) {
        ret.x = 0;
    }

    if (_lockHorizontal) {
        ret.y = 0;
    }

    return ret;
}

/**
 @Status Interoperable
*/
- (void)setTranslation:(CGPoint)translation inView:(id)viewAddr {
    const CGPoint origin = { 0, 0 };

    CGPoint pos = pointFromView(translation, viewAddr) - pointFromView(origin, viewAddr);
    _priv->currentTranslation = pos;
}

- (UIView*)_touchedView {
    return _touchedView;
}

- (void)_setDragSlack:(float)slack {
    _dragSlack = slack;
}

- (float)_getDragSlack {
    return _dragSlack;
}

/**
 @Status Interoperable
*/
- (CGPoint)locationInView:(id)viewAddr {
    CGPoint ret;
    ret = [[viewAddr window] _convertPoint:_priv->lastCenter fromView:nil toView:viewAddr];
    return ret;
}

/**
 @Status Interoperable
*/
- (CGPoint)velocityInView:(UIView*)viewAddr {
    CGPoint ret;

    if (_priv->currentVelocity.len() < VELOCITY_THRESHOLD) {
        ret.x = 0.0f;
        ret.y = 0.0f;
        return ret;
    }

    CGPoint zero = { 0, 0 };
    CGPoint dx = pointToView(_priv->currentVelocity, viewAddr) - pointToView(zero, viewAddr);
    ret = dx;

    if (_lockVertical) {
        ret.x = 0;
    }

    if (_lockHorizontal) {
        ret.y = 0;
    }

    return ret;
}

/**
 @Status Interoperable
*/
- (void)reset {
    _priv->touches.clear();
    _priv->currentTranslation.x = 0.f;
    _priv->currentTranslation.y = 0.f;
    _didFireEnded = false;
    _lockVertical = false;
    _lockHorizontal = false;

    [super reset];
}

- (const std::vector<TouchInfo>&)_getTouches {
    return self->_priv->touches;
}

@end
