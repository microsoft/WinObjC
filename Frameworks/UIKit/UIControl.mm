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
#include "UIKit/UIView.h"
#include "UIKit/UIControl.h"
#include "UIKit/UIRuntimeEventConnection.h"
#include "Foundation/NSString.h"
#include "Foundation/NSMutableArray.h"
#include "Foundation/NSMutableSet.h"

@implementation UIControl : UIView
- (instancetype)initWithFrame:(CGRect)pos {
    _registeredActions = [NSMutableArray new];
    _activeTouches = [NSMutableArray new];
    _contentVerticalAlignment = UIControlContentVerticalAlignmentTop;
    _contentHorizontalAlignment = UIControlContentHorizontalAlignmentLeft;

    [super initWithFrame:pos];

    return self;
}

- (id)initWithCoder:(NSCoder*)coder {
    _registeredActions = [[NSMutableArray alloc] init];
    _activeTouches = [NSMutableArray new];

    BOOL selected = [coder decodeInt32ForKey:@"UISelected"];
    if (selected) {
        _curState |= UIControlStateSelected;
    }

    _contentVerticalAlignment = UIControlContentVerticalAlignmentTop;
    _contentHorizontalAlignment = UIControlContentHorizontalAlignmentLeft;

    if ([coder containsValueForKey:@"UIContentHorizontalAlignment"]) {
        _contentHorizontalAlignment = [coder decodeInt32ForKey:@"UIContentHorizontalAlignment"];
    }
    if ([coder containsValueForKey:@"UIContentVerticalAlignment"]) {
        _contentVerticalAlignment = [coder decodeInt32ForKey:@"UIContentVerticalAlignment"];
    }

    [super initWithCoder:coder];

    return self;
}

- (void)addEventConnection:(UIRuntimeEventConnection*)connection {
    [_registeredActions addObject:connection];
}

/**
 @Status Interoperable
*/
- (void)sendEvent:(id)event mask:(unsigned)mask {
    unsigned count = [_registeredActions count];

    for (unsigned i = 0; i < count; i++) {
        UIRuntimeEventConnection* obj = [_registeredActions objectAtIndex:i];

        if (![obj isValid]) {
            [_registeredActions removeObjectAtIndex:i];
            i--;
            count--;
            continue;
        }

        unsigned objMask = [obj mask];
        id target = [obj obj];
        SEL sel = (SEL)[obj sel];

        if ((objMask & mask) != 0) {
            id curTarget = target;
            if (curTarget == nil) {
                curTarget = self;

                while (curTarget != nil) {
                    if ([curTarget respondsToSelector:sel]) {
                        break;
                    }
                    curTarget = [curTarget nextResponder];
                }
            }

            [curTarget performSelector:sel withObject:self withObject:event];
        }
    }
}

/**
 @Status Interoperable
*/
- (NSArray*)actionsForTarget:(id)targetObj forControlEvent:(UIControlEvents)controlEvent {
    unsigned count = [_registeredActions count];
    NSMutableArray* ret = [NSMutableArray array];

    for (unsigned i = 0; i < count; i++) {
        UIRuntimeEventConnection* obj = [_registeredActions objectAtIndex:i];

        if (![obj isValid]) {
            [_registeredActions removeObjectAtIndex:i];
            i--;
            count--;
            continue;
        }

        unsigned objMask = [obj mask];
        id target = [obj obj];
        char* sel = (char*)[obj sel];

        if ((objMask & controlEvent) != 0 && target == targetObj) {
            [ret addObject:[NSString stringWithCString:sel]];
        }
    }

    if ([ret count] > 0) {
        return ret;
    } else {
        return nil;
    }
}

/**
 @Status Interoperable
*/
- (NSSet*)allTargets {
    unsigned count = [_registeredActions count];
    id ret = [NSMutableSet set];

    for (unsigned i = 0; i < count; i++) {
        id obj = [_registeredActions objectAtIndex:i];

        if (![obj isValid]) {
            [_registeredActions removeObjectAtIndex:i];
            i--;
            count--;
            continue;
        }

        id target = [obj obj];
        [ret addObject:target];
    }

    return ret;
}

/**
 @Status Interoperable
*/
- (void)setEnabled:(BOOL)enabled {
    if (!enabled) {
        _curState |= UIControlStateDisabled;
    } else {
        _curState &= ~UIControlStateDisabled;
    }

    [self setNeedsDisplay];
    [self setNeedsLayout];
}

/**
 @Status Interoperable
*/
- (BOOL)isEnabled {
    return !(_curState & UIControlStateDisabled);
}

/**
 @Status Interoperable
*/
- (BOOL)isSelected {
    return _curState & UIControlStateSelected;
}

/**
 @Status Interoperable
*/
- (BOOL)isHighlighted {
    return _curState & UIControlStateHighlighted;
}

/**
 @Status Interoperable
*/
- (BOOL)isTouchInside {
    return _touchInside;
}

/**
 @Status Interoperable
*/
- (void)setSelected:(BOOL)selected {
    if (selected) {
        _curState |= UIControlStateSelected;
    } else {
        _curState &= ~UIControlStateSelected;
    }

    [self setNeedsDisplay];
    [self setNeedsLayout];
}

/**
 @Status Interoperable
*/
- (UIControlState)state {
    return _curState;
}

/**
 @Status Interoperable
*/
- (void)setHighlighted:(BOOL)highlighted {
    if (highlighted) {
        _curState |= UIControlStateHighlighted;
    } else {
        _curState &= ~UIControlStateHighlighted;
    }

    [self setNeedsDisplay];
    [self setNeedsLayout];
}

- (void)setAccessibilityLabel:(UILabel*)label {
}

/**
 @Status Interoperable
*/
- (void)setContentVerticalAlignment:(UIControlContentVerticalAlignment)alignment {
    _contentVerticalAlignment = alignment;
}

/**
 @Status Interoperable
*/
- (UIControlContentVerticalAlignment)contentVerticalAlignment {
    return _contentVerticalAlignment;
}

/**
 @Status Interoperable
*/
- (void)setContentHorizontalAlignment:(UIControlContentHorizontalAlignment)alignment {
    _contentHorizontalAlignment = alignment;
}

/**
 @Status Interoperable
*/
- (UIControlContentHorizontalAlignment)contentHorizontalAlignment {
    return _contentHorizontalAlignment;
}

/**
 @Status Interoperable
*/
- (void)addTarget:(id)target action:(SEL)actionSel forControlEvents:(UIControlEvents)events {
    // EbrDebugLog("%s: addTaret(%s, %s) for 0x%08x\n", object_getClassName(self), target != nil ?
    // object_getClassName(target) : "(nil)", actionSel != NULL ? sel_getName(actionSel) : "(null)", events);

    if (actionSel == NULL) {
        EbrDebugLog("addTarget: *** ERROR *** actionSel = NULL\n");
        return;
    }

    [self removeTarget:target action:actionSel forControlEvents:events];
    UIRuntimeEventConnection* newEvent = [[UIRuntimeEventConnection alloc] initWithTarget:target selector:actionSel eventMask:events];
    [_registeredActions addObject:newEvent];
    [newEvent release];
}

/**
 @Status Interoperable
*/
- (void)removeTarget:(id)target action:(SEL)actionSel forControlEvents:(UIControlEvents)events {
    //  Go through all targets
    unsigned count = [_registeredActions count];

    for (unsigned i = 0; i < count; i++) {
        UIRuntimeEventConnection* curEvent = [_registeredActions objectAtIndex:i];
        if (target == nil) {
            SEL eventSel = (SEL)[curEvent sel];
            unsigned mask = [curEvent mask];

            if ((actionSel == NULL || actionSel == eventSel) && (mask & events) != 0) {
                [curEvent invalidate];
            }
        } else {
            SEL eventSel = (SEL)[curEvent sel];

            if (target == [curEvent obj] && (actionSel == NULL || actionSel == eventSel)) {
                [curEvent invalidate];
            }
        }
    }
}

- (void)touchesBegan:(NSSet*)touchSet withEvent:(UIEvent*)event {
    if (_curState & UIControlStateDisabled) {
        EbrDebugLog("UIControl is disabled - ignoring touch\n");
        return;
    }

    _touchInside = TRUE;
    [self sendEvent:event mask:UIControlEventTouchDown];

    if ([self respondsToSelector:@selector(beginTrackingWithTouch:withEvent:)]) {
        NSEnumerator* objEnum = [touchSet objectEnumerator];
        UITouch* curTouch;

        while ((curTouch = [objEnum nextObject]) != nil) {
            if (![_activeTouches containsObject:curTouch]) {
                BOOL track = [self beginTrackingWithTouch:curTouch withEvent:event];
                if (track) {
                    [_activeTouches addObject:curTouch];
                }
            }
        }
    }
}

- (void)touchesMoved:(NSSet*)touchSet withEvent:(UIEvent*)event {
    if (_curState & UIControlStateDisabled) {
        EbrDebugLog("UIControl is disabled - ignoring touch\n");
        return;
    }

    [self sendEvent:event mask:UIControlEventTouchDragInside];

    if ([self respondsToSelector:@selector(continueTrackingWithTouch:withEvent:)]) {
        NSEnumerator* objEnum = [touchSet objectEnumerator];
        UITouch* curTouch;

        while ((curTouch = [objEnum nextObject]) != nil) {
            if ([_activeTouches containsObject:curTouch]) {
                BOOL track = [self continueTrackingWithTouch:curTouch withEvent:event];
                if (!track) {
                    [_activeTouches removeObject:curTouch];
                    if ([self respondsToSelector:@selector(endTrackingWithTouch:withEvent:)]) {
                        [self endTrackingWithTouch:curTouch withEvent:event];
                    }
                }
            }
        }
    }
}

- (void)touchesEnded:(NSSet*)touchSet withEvent:(UIEvent*)event {
    _touchInside = FALSE;

    if (_curState & UIControlStateDisabled) {
        EbrDebugLog("UIControl is disabled - ignoring touch\n");
        return;
    }

    [self sendEvent:event mask:UIControlEventTouchUpInside];

    NSEnumerator* objEnum = [touchSet objectEnumerator];
    UITouch* curTouch;

    while ((curTouch = [objEnum nextObject]) != nil) {
        if ([_activeTouches containsObject:curTouch]) {
            [_activeTouches removeObject:curTouch];
            if ([self respondsToSelector:@selector(endTrackingWithTouch:withEvent:)]) {
                [self endTrackingWithTouch:curTouch withEvent:event];
            }
        }
    }
}

- (void)touchesCancelled:(NSSet*)touchSet withEvent:(UIEvent*)event {
    _touchInside = FALSE;

    if (_curState & UIControlStateDisabled) {
        EbrDebugLog("UIControl is disabled - ignoring touch\n");
        return;
    }

    [self sendEvent:event mask:UIControlEventTouchCancel];
}

/**
 @Status Interoperable
*/
- (void)cancelTrackingWithEvent:(UIEvent*)event {
    EbrDebugLog("cancelTrackingWithEvent not implemented\n");
}

/**
 @Status Interoperable
*/
- (BOOL)isTracking {
    return [_activeTouches count] > 0;
}

/**
 @Status Interoperable
*/
- (void)sendActionsForControlEvents:(UIControlEvents)eventMask {
    [self sendEvent:self mask:eventMask];
}

/**
 @Status Interoperable
*/
- (BOOL)beginTrackingWithTouch:(NSSet*)touchSet withEvent:(UIEvent*)event {
    return TRUE;
}

/**
 @Status Interoperable
*/
- (BOOL)continueTrackingWithTouch:(NSSet*)touchSet withEvent:(UIEvent*)event {
    return TRUE;
}

/**
 @Status Interoperable
*/
- (void)endTrackingWithTouch:(NSSet*)touchSet withEvent:(UIEvent*)event {
}

- (void)sendControlEventsOnBack:(UIControlEvents)events {
    if (events == 0) {
        [self setBackButtonDelegate:nil action:NULL withParam:0];
    } else {
        _sendControlEventsOnBack = events;
        [self setBackButtonDelegate:self action:@selector(_backPressed) withParam:0];
    }
}

- (void)_backPressed {
    [self sendActionsForControlEvents:_sendControlEventsOnBack];
}

- (void)dealloc {
    [_registeredActions release];
    [_activeTouches release];

    [super dealloc];
}

@end
