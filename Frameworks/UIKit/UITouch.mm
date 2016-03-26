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

@implementation UITouch

@synthesize timestamp = _timestamp;
@synthesize tapCount = _tapCount;
@synthesize view = _view;
@synthesize phase = _phase;

+ (UITouch*)createWithPoint:(CGPoint)point tapCount:(int)tapCount {
    UITouch* newObj = [self new];
    UITouch* us = (UITouch*)newObj;
    us->touchX = point.x;
    us->touchY = point.y;
    us->previousTouchX = point.x;
    us->previousTouchY = point.y;
    us->_timestamp = 0.0f;
    us->_tapCount = tapCount;

    return newObj;
}

/**
 @Status Interoperable
*/
- (CGPoint)locationInView:(UIView*)viewAddr {
    CGPoint ret;
    CGPoint location;

    location.x = touchX;
    location.y = touchY;

    if (viewAddr != 0) {
        id window = [((UIView*)(viewAddr))_getWindowInternal];

        if (window != nil) {
            ret = [window convertPoint:location fromView:window toView:viewAddr];
        } else {
            CGRect rect = { 0 };

            rect = [viewAddr frame];

            ret.x = touchX - rect.origin.x;
            ret.y = touchY - rect.origin.y;
        }
    } else {
        ret.x = touchX;
        ret.y = touchY;
    }

    return ret;
}

/**
 @Status Interoperable
*/
- (CGPoint)previousLocationInView:(UIView*)viewAddr {
    CGPoint ret;
    CGPoint location;

    location.x = previousTouchX;
    location.y = previousTouchY;

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

- (void)_redirectTouch:(UIView*)view {
    /*
    //  Remove the touch from the view
    UIView* curView = inView;

    [curView->priv->currentTouches removeObject:self];
    */

    [_view autorelease];
    _view = view;
    [_view retain];
}

- (void)_redirectPhase:(UITouchPhase)newPhase {
    _phase = newPhase;
}

/**
 @Status Interoperable
*/
- (CGPoint)velocity {
    CGPoint ret;
    ret.x = velocityX;
    ret.y = velocityY;
    return ret;
}

- (instancetype)copyWithZone:(NSZone*)zone {
    UITouch* ret = [[self class] allocWithZone:zone];

    _timestamp = self.timestamp;
    _view = [self.view retain];
    _tapCount = self.tapCount;
    _phase = self.phase;

    ret->touchX = touchX;
    ret->touchY = touchY;
    ret->previousTouchX = previousTouchX;
    ret->previousTouchY = previousTouchY;

    return ret;
}

/**
 @Status Stub
*/
- (void)dealloc {
    [_view autorelease];
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

@end
