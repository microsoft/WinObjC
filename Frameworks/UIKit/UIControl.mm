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

#import <UIKit/UIControl.h>
#import <UIKit/UILabel.h>
#import <UIKit/UIRuntimeEventConnection.h>
#import <UIKit/UITouch.h>
#import <UIKit/UIView.h>

#import <Foundation/NSString.h>
#import <Foundation/NSMutableArray.h>
#import <Foundation/NSMutableSet.h>

#import "LoggingNative.h"
#import "StubReturn.h"
#import "UIControlInternal.h"

static const wchar_t* TAG = L"UIControl";

@implementation UIControl

- (void)_initUIControl {
    _registeredActions.attach([[NSMutableArray alloc] init]);
    _activeTouches.attach([[NSMutableArray alloc] init]);
    _contentVerticalAlignment = UIControlContentVerticalAlignmentTop;
    _contentHorizontalAlignment = UIControlContentHorizontalAlignmentLeft;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        [self _initUIControl];
    }

    return self;
}

/**
Microsoft Extension
*/
- (instancetype)initWithFrame:(CGRect)frame xamlElement:(RTObject*)xamlElement {
    if (self = [super initWithFrame:frame xamlElement:xamlElement]) {
        [self _initUIControl];
    }

    return self;
}

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    if (self = [super initWithCoder:coder]) {
        [self _initUIControl];

        BOOL selected = [coder decodeInt32ForKey:@"UISelected"];
        if (selected) {
            _curState |= UIControlStateSelected;
        }

        if ([coder containsValueForKey:@"UIContentHorizontalAlignment"]) {
            _contentHorizontalAlignment = [coder decodeInt32ForKey:@"UIContentHorizontalAlignment"];
        }
        if ([coder containsValueForKey:@"UIContentVerticalAlignment"]) {
            _contentVerticalAlignment = [coder decodeInt32ForKey:@"UIContentVerticalAlignment"];
        }
    }

    return self;
}

/**
 @Public No
*/
- (void)initAccessibility {
    [super initAccessibility];
    self.isAccessibilityElement = TRUE;
}

- (void)_addEventConnection:(UIRuntimeEventConnection*)connection {
    [_registeredActions addObject:connection];
}

/**
 @Status Interoperable
*/
- (void)sendAction:(SEL)sel to:(id)target forEvent:(UIEvent*)event {
    if (target == nil) {
        target = self;

        //  Cascade the action down the responder chain
        while (target != nil) {
            if ([target respondsToSelector:sel]) {
                break;
            }

            target = [target nextResponder];
        }
    }

    if (target != nil) {
        [target performSelector:sel withObject:self withObject:event];
    }
}

/**
 @Status Interoperable
*/
- (void)sendActionsForControlEvents:(UIControlEvents)mask {
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

            [self sendAction:sel to:curTarget forEvent:nil];
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
        const char* sel = sel_getName([obj sel]);

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
    // only update the value and then relayout if value actually changed
    if ((_curState & UIControlStateDisabled) != !enabled) {
        if (!enabled) {
            _curState |= UIControlStateDisabled;
        } else {
            _curState &= ~UIControlStateDisabled;
        }

        [self setNeedsDisplay];
        [self invalidateIntrinsicContentSize];
        [self setNeedsLayout];

        if (enabled) {
            self.accessibilityTraits &= ~UIAccessibilityTraitNotEnabled;
        } else {
            self.accessibilityTraits |= UIAccessibilityTraitNotEnabled;
        }
    }
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
    // only update the value and then relayout if value actually changed
    if ((_curState & UIControlStateSelected) != selected) {
        if (selected) {
            _curState |= UIControlStateSelected;
        } else {
            _curState &= ~UIControlStateSelected;
        }

        [self setNeedsDisplay];
        [self invalidateIntrinsicContentSize];
        [self setNeedsLayout];
    }
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
    // only update the value and then relayout if value actually changed
    if ((_curState & UIControlStateHighlighted) != highlighted) {
        if (highlighted) {
            _curState |= UIControlStateHighlighted;
        } else {
            _curState &= ~UIControlStateHighlighted;
        }

        [self setNeedsDisplay];
        [self invalidateIntrinsicContentSize];
        [self setNeedsLayout];
    }
}

/**
 @Status Stub
*/
- (void)setAccessibilityLabel:(UILabel*)label {
    UNIMPLEMENTED();
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
    // TraceVerbose(TAG, L"%hs: addTaret(%hs, %hs) for 0x%08x", object_getClassName(self), target != nil ?
    // object_getClassName(target) : "(nil)", actionSel != NULL ? sel_getName(actionSel) : "(null)", events);

    if (actionSel == NULL) {
        TraceError(TAG, L"addTarget: *** ERROR *** actionSel = NULL");
        return;
    }

    [self removeTarget:target action:actionSel forControlEvents:events];
    StrongId<UIRuntimeEventConnection> newEvent;
    newEvent.attach([[UIRuntimeEventConnection alloc] initWithTarget:target selector:actionSel eventMask:events]);
    [_registeredActions addObject:newEvent];
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

/**
 @Status Interoperable
*/
- (void)touchesBegan:(NSSet*)touchSet withEvent:(UIEvent*)event {
    if (_curState & UIControlStateDisabled) {
        TraceVerbose(TAG, L"UIControl is disabled - ignoring touch");
        return;
    }

    // Multitouch isn't supported by default, that's handled through tracking.
    // The first touch is the one used for control events.
    if (!_controlEventTouch) {
        _controlEventTouch = [touchSet anyObject];
        _touchInside = TRUE;
        [self sendActionsForControlEvents:UIControlEventTouchDown];
    }

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

/**
 @Status Interoperable
*/
- (void)touchesMoved:(NSSet*)touchSet withEvent:(UIEvent*)event {
    if (_curState & UIControlStateDisabled) {
        TraceVerbose(TAG, L"UIControl is disabled - ignoring touch");
        return;
    }

    if ([touchSet containsObject:_controlEventTouch]) {
        CGPoint point = [_controlEventTouch locationInView:self];
        BOOL currentTouchInside = [self pointInside:point withEvent:event];

        if (currentTouchInside != _touchInside) {
            _touchInside = currentTouchInside;
            if (currentTouchInside) {
                [self sendActionsForControlEvents:UIControlEventTouchDragEnter];
            } else {
                [self sendActionsForControlEvents:UIControlEventTouchDragExit];
            }
        }

        // TODO: Investigate fat-fingers
        if (currentTouchInside) {
            [self sendActionsForControlEvents:UIControlEventTouchDragInside];
        } else {
            [self sendActionsForControlEvents:UIControlEventTouchDragOutside];
        }
    }

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

/**
 @Status Interoperable
*/
- (void)touchesEnded:(NSSet*)touchSet withEvent:(UIEvent*)event {
    _touchInside = FALSE;

    if (_curState & UIControlStateDisabled) {
        TraceVerbose(TAG, L"UIControl is disabled - ignoring touch");
        return;
    }

    if ([touchSet containsObject:_controlEventTouch]) {
        CGPoint point = [_controlEventTouch locationInView:self];
        BOOL currentTouchInside = [self pointInside:point withEvent:event];

        if (currentTouchInside) {
            [self sendActionsForControlEvents:UIControlEventTouchUpInside];
        } else {
            [self sendActionsForControlEvents:UIControlEventTouchUpOutside];
        }

        _controlEventTouch = nil;
    }

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

/**
 @Status Interoperable
*/
- (void)touchesCancelled:(NSSet*)touchSet withEvent:(UIEvent*)event {
    _touchInside = FALSE;

    if (_curState & UIControlStateDisabled) {
        TraceVerbose(TAG, L"UIControl is disabled - ignoring touch");
        return;
    }

    if ([touchSet containsObject:_controlEventTouch]) {
        [self sendActionsForControlEvents:UIControlEventTouchCancel];
        _controlEventTouch = nil;
    }
}

/**
 @Status Interoperable
*/
- (void)cancelTrackingWithEvent:(UIEvent*)event {
    TraceVerbose(TAG, L"cancelTrackingWithEvent not implemented");
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

/**
 @Status Interoperable
*/
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

/**
 @Status Stub
*/
- (UIControlEvents)allControlEvents {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)sendEvent:(id)event mask:(unsigned)mask {
    UNIMPLEMENTED();
}

@end
