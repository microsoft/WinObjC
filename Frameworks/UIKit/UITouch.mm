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
#import "UIKit/UITouch.h"
#import "UIKit/UIView.h"
#import "UIViewInternal.h"
#import "CACompositor.h"
#import "UITouchInternal.h"
#import "UWP/WindowsUIInput.h"
#import "RingBuffer.h"

static const wchar_t* TAG = L"UITouch";
static const bool INPUT_TRACING_ENABLED = false;

#define TAP_SLACK_AREA \
    (((GetCACompositor()->screenWidth() / GetCACompositor()->deviceWidth()) * GetCACompositor()->screenXDpi()) / 3.0f) //  1/3 inch

static const float c_tapTimeout = 0.300; // seconds
static const float c_microsecondsToSeconds = 1000000.0;

static float _touchDistance(float x1, float y1, float x2, float y2) {
    return sqrtf(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
}

static int _calculateTapCount(UITouch* touch, CGPoint newTouchPoint, UITouchPhase newTouchPhase, NSTimeInterval newTimestamp) {
    if (newTouchPhase == UITouchPhaseBegan) {
        if (_touchDistance(newTouchPoint.x, newTouchPoint.y, touch->_touchX, touch->_touchY) < TAP_SLACK_AREA &&
            ((newTimestamp / c_microsecondsToSeconds) - touch->_timestamp) <= c_tapTimeout) {
            // We haven't moved much, so increment the tap count
            return touch.tapCount + 1;
        } else {
            // New single tap
            return 1;
        }
    }

    // Any other UITouchPhase shouldn't update the tap count
    return touch.tapCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// TODO: This manual velocity tracking shouldn't be necessary once we move to WinRT Pan gesture recognition.
// Records touch data for velocity calculations
struct TouchRecord {
    TouchRecord() {
    }
    TouchRecord(const CGPoint& pos, double timestamp) : pos(pos), timestamp(timestamp) {
    }

    CGPoint pos = { 0, 0 };
    double timestamp = 0.0;
};

@interface UITouch () {
@public
    RingBuffer<TouchRecord, 50> _touchHistory;
}
@end

// Calculates touch velocity
static CGPoint calculateTouchVelocity(RingBuffer<TouchRecord, 50>& touchHistory) {
    const float time = 0.1f;
    double endTime = touchHistory.fromEnd(0).timestamp;
    CGPoint curPos = touchHistory.fromEnd(0).pos;
    double curTime = endTime;
    bool gotRecord = false; //  Get at least one record
    CGPoint ret = { 0, 0 };
    float numRet = 0.0f;

    bool distanceSatisfied = false;

    size_t i = 1;
    for (; i < touchHistory.size(); ++i) {
        double timestamp = touchHistory.fromEnd(i).timestamp;
        CGPoint pos = touchHistory.fromEnd(i).pos;
        if ((endTime - timestamp > time) && gotRecord) {
            break;
        }

        if (timestamp != curTime) {
            if (curPos.x != pos.x && curPos.y != pos.y) {
                //  Average the speed and direction in
                CGPoint dir;
                dir.x = (float)((curPos.x - pos.x) / (curTime - timestamp));
                dir.y = (float)((curPos.y - pos.y) / (curTime - timestamp));
                numRet += 1.0f;
                ret.x += dir.x;
                ret.y += dir.y;

                gotRecord = true;

                //  Make sure that at least one of the touches satisfies a minimum distance threshold
                if ((curPos - pos).lenGe(.5f)) {
                    distanceSatisfied = true;
                }
            }
        }
    }

    if (numRet > 0.0f) {
        ret.x /= numRet;
        ret.y /= numRet;
    }

    if (!distanceSatisfied) {
        ret.x = 0.0f;
        ret.y = 0.0f;
    }

    return ret;
}

// Initialize velocity tracking for this touch point
static void trackTouchVelocity(RingBuffer<TouchRecord, 50>& touchHistory, CGPoint position, double timestamp) {
    touchHistory.reset();
    touchHistory.add(TouchRecord(position, timestamp));
}

// Update velocity tracking for this touch point
static void recordTouchVelocity(RingBuffer<TouchRecord, 50>& touchHistory, CGPoint position, double timestamp) {
    touchHistory.add(TouchRecord(position, timestamp));
}
// TODO: This manual velocity tracking shouldn't be necessary once we move to WinRT Pan gesture recognition.
////////////////////////////////////////////////////////////////////////////////////////////////////////////

@implementation UITouch

@synthesize timestamp = _timestamp;
@synthesize tapCount = _tapCount;
@synthesize phase = _phase;

+ (UITouch*)_createWithPoint:(CGPoint)point {
    UITouch* newObj = [self new];
    UITouch* us = (UITouch*)newObj;
    us->_touchX = point.x;
    us->_touchY = point.y;
    us->_previousTouchX = point.x;
    us->_previousTouchY = point.y;
    us->_velocityX = 0.0f;
    us->_velocityY = 0.0f;
    us->_timestamp = 0.0f;
    us->_tapCount = 0;
    us->_phase = UITouchPhaseCancelled;

    return newObj;
}

- (void)_updateWithPoint:(WUIPointerPoint*)pointerPoint
         routedEventArgs:(WUXIPointerRoutedEventArgs*)routedEventArgs
                forPhase:(UITouchPhase)touchPhase {
    _routedEventArgs = routedEventArgs;

    // Grab the postion of the event
    WFPoint* position = [pointerPoint position];
    CGPoint point = CGPointMake(position.x, position.y);

    // First update the tapcount
    _tapCount = _calculateTapCount(self, point, touchPhase, pointerPoint.timestamp);

    if (touchPhase == UITouchPhaseBegan && INPUT_TRACING_ENABLED) {
        TraceVerbose(TAG, L"Tap count: %d.", _tapCount);
    }

    // Update all other fields
    _previousTouchX = _touchX;
    _previousTouchY = _touchY;
    _touchX = point.x;
    _touchY = point.y;
    _phase = touchPhase;
    _timestamp = (pointerPoint.timestamp / c_microsecondsToSeconds);
    _pointerPoint = pointerPoint;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // TODO: This manual velocity tracking shouldn't be necessary once we move to WinRT Pan gesture recognition.
    if (touchPhase == UITouchPhaseBegan) {
        trackTouchVelocity(_touchHistory, point, _timestamp);
        _velocityX = 0.0;
        _velocityY = 0.0;
    } else {
        recordTouchVelocity(_touchHistory, point, _timestamp);
        CGPoint velocity = calculateTouchVelocity(_touchHistory);
        _velocityX = velocity.x;
        _velocityY = velocity.y;

        if (INPUT_TRACING_ENABLED) {
            TraceVerbose(TAG, L"Velocity: x=%f, y=%f.", _velocityX, _velocityY);
        }
    }
    // TODO: This manual velocity tracking shouldn't be necessary once we move to WinRT Pan gesture recognition.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/**
 @Status Interoperable
*/
- (CGPoint)locationInView:(UIView*)viewAddr {
    CGPoint ret;
    CGPoint location;

    location.x = _touchX;
    location.y = _touchY;

    if (viewAddr != 0) {
        id window = [((UIView*)(viewAddr))_getWindowInternal];

        if (window != nil) {
            ret = [window convertPoint:location fromView:window toView:viewAddr];
        } else {
            CGRect rect = { 0 };
            rect = [viewAddr frame];

            ret.x = _touchX - rect.origin.x;
            ret.y = _touchY - rect.origin.y;
        }
    } else {
        ret.x = _touchX;
        ret.y = _touchY;
    }

    return ret;
}

/**
 @Status Interoperable
*/
- (CGPoint)previousLocationInView:(UIView*)viewAddr {
    CGPoint ret;
    CGPoint location;

    location.x = _previousTouchX;
    location.y = _previousTouchY;

    UIWindow* window = [viewAddr window];
    if (window != nil) {
        ret = [window convertPoint:location fromView:window toView:viewAddr];
    } else {
        CGRect rect = { 0 };
        rect = [viewAddr frame];
        ret.x = location.x - rect.origin.x;
        ret.y = location.y - rect.origin.y;
    }

    return ret;
}

- (instancetype)copyWithZone:(NSZone*)zone {
    UITouch* ret = [[self class] allocWithZone:zone];

    ret->_timestamp = self.timestamp;
    ret->_view = self.view;
    ret->_tapCount = self.tapCount;
    ret->_phase = self.phase;
    ret->_velocityX = _velocityX;
    ret->_velocityY = _velocityY;
    ret->_touchX = _touchX;
    ret->_touchY = _touchY;
    ret->_previousTouchX = _previousTouchX;
    ret->_previousTouchY = _previousTouchY;

    return ret;
}

/**
 @Status Stub
*/
- (void)dealloc {
    [super dealloc];
}

/**
 @Status Stub
*/
- (CGFloat)azimuthAngleInView:(UIView*)view {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (CGPoint)locationInNode:(SKNode*)node {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (CGPoint)preciseLocationInView:(UIView*)view {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (CGPoint)precisePreviousLocationInView:(UIView*)view {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (CGPoint)previousLocationInNode:(SKNode*)node {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (CGVector)azimuthUnitVectorInView:(UIView*)view {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (UIView*)view {
    return _view;
}

@end
