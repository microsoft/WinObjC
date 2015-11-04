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

#include "UIKit/UIEvent.h"
#include "Foundation/NSMutableSet.h"

@implementation UIEvent {
    idretaintype(NSSet) touches;
    idretaintype(UITouch) touchEvent;
    double _timestamp;
}
+ (UIEvent*)createWithTouches:(NSSet*)touchUISet touchEvent:(UIEvent*)touch {
    UIEvent* us = (UIEvent*)[self new];
    us->touches = touchUISet;
    us->touchEvent = touch;

    return us;
}

/**
 @Status Stub
*/
- (NSSet*)touchesForWindow:(UIWindow*)window {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
- (NSSet*)touchesForGestureRecognizer:(UIGestureRecognizer*)gesture {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Interoperable
*/
- (NSSet*)allTouches {
    return touches;
}

- (UITouch*)_touchEvent {
    return touchEvent;
}

/**
 @Status Interoperable
*/
- (NSSet*)touchesForView:(UIView*)view {
    NSEnumerator* curEnum = [touches objectEnumerator];
    NSMutableSet* ret = [NSMutableSet set];

    UITouch* curTouch;
    while ((curTouch = [curEnum nextObject]) != nil) {
        if ([curTouch view] == view) {
            [ret addObject:curTouch];
        }
    }

    if ([ret count] > 0) {
        return ret;
    } else {
        return nil;
    }
}

- (void)setTimestamp:(double)time {
    _timestamp = time;
}

/**
 @Status Interoperable
*/
- (UIEventType)type {
    return UIEventTypeTouches;
}

- (void)dealloc {
    touches = nil;
    touchEvent = nil;
    [super dealloc];
}

/**
 @Status Interoperable
*/
- (double)timestamp {
    return _timestamp;
}

@end
