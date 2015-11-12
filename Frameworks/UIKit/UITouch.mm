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

#include "Starboard.h"

#include "UIKit/UITouch.h"
#include "UIKit/UIView.h"

@implementation UITouch : NSObject
+ (UITouch*)createWithPoint:(CGPoint)point tapCount:(int)tapCount {
    UITouch* newObj = [self new];
    UITouch* us = (UITouch*)newObj;
    us->touchX = point.x;
    us->touchY = point.y;
    us->previousTouchX = point.x;
    us->previousTouchY = point.y;
    us->timeStamp = 0.0f;
    us->tapCount = tapCount;

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
        // EbrDebugLog("Mapping %s (%f, %f -> %f, %f)\n", object_getClassName(viewAddr), touchX, touchY, ret->x,
        // ret->y);
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

/**
 @Status Interoperable
*/
- (NSUInteger)tapCount {
    return tapCount;
}

/**
 @Status Interoperable
*/
- (UITouchPhase)phase {
    return phase;
}

/**
 @Status Interoperable
*/
- (UIView*)view {
    return inView;
}

- (void)_redirectTouch:(UIView*)view {
    /*
    //  Remove the touch from the view
    UIView* curView = inView;

    [curView->priv->currentTouches removeObject:self];
    */

    [inView autorelease];
    inView = view;
    [inView retain];
}

- (void)_redirectPhase:(UITouchPhase)newPhase {
    phase = newPhase;
}

/**
 @Status Interoperable
*/
- (double)timestamp {
    assert(timeStamp != 0.0f);
    double ret = timeStamp;
    return ret;
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

- (id)copyWithZone:(NSZone*)zone {
    UITouch* ret = [[self class] allocWithZone:zone];

    ret->touchX = touchX;
    ret->touchY = touchY;
    ret->previousTouchX = previousTouchX;
    ret->previousTouchY = previousTouchY;
    ret->timeStamp = timeStamp;
    ret->inView = [inView retain];
    ret->tapCount = tapCount;
    ret->phase = phase;

    return ret;
}

- (void)dealloc {
    [inView autorelease];
    [super dealloc];
}

@end
