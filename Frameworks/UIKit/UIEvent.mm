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
#include "Starboard.h"

#include "UIKit/UIEvent.h"

@implementation UIEvent {
    StrongId<NSMutableSet<UITouch*>> touches;
    StrongId<UITouch> touchEvent;
    double _timestamp;
}

/**
 @Public No
 Note: Only used for legacy hit-testing purposes.  Should remove at some point.
*/
+ (UIEvent*)_createWithTouches:(NSSet*)allTouches forNewTouch:(UITouch*)newTouch {
    UIEvent* us = (UIEvent*)[self new];
    us->touches = allTouches;
    us->touchEvent = newTouch;

    return us;
}

/**
 @Public No
*/
- (void)_updateWithTouches:(NSMutableSet<UITouch*>*)allTouches touchEvent:(UITouch*)newTouch {
    self->touches = allTouches;
    self->touchEvent = newTouch;
    self->_timestamp = newTouch.timestamp;
}

/**
 @Status Stub
*/
- (NSSet<UITouch*>*)touchesForWindow:(UIWindow*)window {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
- (NSSet<UITouch*>*)touchesForGestureRecognizer:(UIGestureRecognizer*)gesture {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Interoperable
*/
- (NSSet<UITouch*>*)allTouches {
    return touches;
}

- (UITouch*)_touchEvent {
    return touchEvent;
}

/**
 @Status Interoperable
*/
- (NSSet<UITouch*>*)touchesForView:(UIView*)view {
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

/**
 @Status Caveat
 @Notes Only supports/returns UIEventTypeTouches.
*/
- (UIEventType)type {
    return UIEventTypeTouches;
}

/**
 @Status Caveat
 @Notes Only supports/returns UIEventSubtypeNone.
*/
- (UIEventSubtype)subtype {
    return UIEventSubtypeNone;
}

/**
 @Status Interoperable
*/
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
