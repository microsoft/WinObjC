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
#import "_UIGestureCoordinator.h"

#import <UIKit/UIGestureRecognizer.h>
#import <UIKit/UIView.h>
#import <UIKit/UITouch.h>
#import <UIKit/UIGestureRecognizerDelegate.h>
#import <UIKit/UIGestureRecognizerSubclass.h>

#import "UIViewInternal.h"
#import "UIGestureRecognizerInternal.h"
#import "_UIDirectManipulationRecognizer.h"

static const wchar_t* TAG = L"_UIGestureCoordinator";

static const bool DEBUG_ALL = false;
static const bool DEBUG_GESTURES = DEBUG_ALL || true;

static _UIGestureCoordinator* g_UIGestureCoordinator = nil;

@implementation _UIGestureCoordinator {
    // internal flag indicating all gestures has been
    // reset, so when processing new touch, we need
    // rebuild the gesture list
    BOOL _resetAllTrackingGestures;

    // regular gesture recognizer list
    // Prefer NSMutableSortedSet, but we don't support yet,
    // using NSMutableArray instead, same reason for _dManipRecognizers
    // when _resetAllTrackingGestures is set to YES, during touch processing
    // we will rebuild regular gesture list
    NSMutableArray* _regularRecognizers;

    // system DManip gesture recognizer list
    // when _resetAllTrackingGestures is set to YES, during touch processing
    // we will rebuild DManip gesture list
    NSMutableArray* _dManipRecognizers;

    // gesture list used for booking up gestures to be removed in one Touch
    // processing cycle. When processing a Touch event, some gestures can be
    // cancelled or be recognized, thsu become ended. These gestures will be
    // stored in this variable and then clean up. So when processing next touch
    // we don't have to enumerate through ended gesture, improve enumeration efficience
    NSMutableSet* _gesturesToRemove;

    // gesture list used for booking gestures in possible state.  when one candidate
    // gesture in _regularRecognizers becomes active we need enumerate this list to
    // make sure that if all gestures in this list can be fired concurrently, if not,
    // they will be transit to cancelled state and removed from this list.
    // it improves gesture processing efficiency
    NSMutableSet* _gesturesInPossibleState;
}

+ (instancetype)singleton {
    if (!g_UIGestureCoordinator) {
        g_UIGestureCoordinator = [_UIGestureCoordinator new];
    }

    return g_UIGestureCoordinator;
}

- (instancetype)init {
    if (self = [super init]) {
        _resetAllTrackingGestures = YES;
        _gesturesToRemove = [NSMutableSet new];
        _gesturesInPossibleState = [NSMutableSet new];
        _regularRecognizers = [NSMutableArray new];
        _dManipRecognizers = [NSMutableArray new];
    }

    return self;
}

// test override to provide custom gestures
- (void)buildTrackingGesturesListWith:(NSMutableArray*)regularRecognizers
                     PossibleGestures:(NSMutableSet*)gesturesInPossibleState
                        DManipGesture:(NSMutableArray*)dManipRecognizers {
    // by default do nothing
}

// build tracking gesture list given a view, if view is nil, it invokes buildTrackingGesturesListWith override to get
// custom build list of gesture for testing
- (void)_buildTrackingGesturesListForView:(UIView*)view {
    if (view == nil) {
        if (_resetAllTrackingGestures) {
            _resetAllTrackingGestures = FALSE;
            return [self buildTrackingGesturesListWith:_regularRecognizers
                                      PossibleGestures:_gesturesInPossibleState
                                         DManipGesture:_dManipRecognizers];
        }
    }

    // Otherwise, build up gesture tracking list based on view
    if (_resetAllTrackingGestures) {
        _resetAllTrackingGestures = FALSE;

        // Find gesture recognizers in the hierarchy, back-first
        UIView* curView = view;
        while (curView != nil) {
            // Adding enabled gestures on each view into cooresponding tracking gesture list
            for (UIGestureRecognizer* curgesture in curView->priv->gestures.get()) {
                if ([curgesture isEnabled]) {
                    // Separating gestures into regular (Non-DManip) and DManip Gesture
                    if (![curgesture isKindOfClass:[_UIDMPanGestureRecognizer class]]) {
                        [_regularRecognizers addObject:curgesture];
                    } else {
                        [_dManipRecognizers addObject:curgesture];
                    }

                    // if gesture is in possible state, Also add it to possible state list
                    if ([curgesture state] == UIGestureRecognizerStatePossible) {
                        [_gesturesInPossibleState addObject:curgesture];
                    }
                }
            }

            curView = curView->priv->superview;
        }
    }
}

// main entrance to send touch to gesture pipleline for processing
- (bool)processGesturesForTouch:(UITouch*)touch event:(UIEvent*)event touchEventName:(SEL)eventName {
    if (DEBUG_GESTURES) {
        TraceVerbose(TAG, L"processGesturesForTouch.");
    }

    [self _buildTrackingGesturesListForView:touch.view];

    // Send touch to regualr gesture for state transiton
    BOOL dManipGesturesCancelled = NO;
    for (UIGestureRecognizer* curgesture in _regularRecognizers) {
        if ([curgesture state] != UIGestureRecognizerStateCancelled) {
            if (DEBUG_GESTURES) {
                TraceVerbose(TAG, L"Checking gesture %hs.", object_getClassName(curgesture));
            }

            id delegate = [curgesture delegate];
            BOOL send = TRUE;
            if (touch.phase == UITouchPhaseBegan && [delegate respondsToSelector:@selector(gestureRecognizer:shouldReceiveTouch:)]) {
                send = [delegate gestureRecognizer:curgesture shouldReceiveTouch:touch];
            }

            if (send) {
                [curgesture performSelector:eventName withObject:[NSMutableSet setWithObject:touch] withObject:event];
                // Verify if gesture state change to Began or recognized after transition, which means a gesture just become active
                if ((curgesture.state == UIGestureRecognizerStateBegan) || (curgesture.state == UIGestureRecognizerStateRecognized)) {
                    // Remove any gesture in possible state which can not fire concurrently with newly active gesture
                    [self _removeGesturesByActiveGesture:curgesture];

                    if (!dManipGesturesCancelled) {
                        // Cancel all DimanipGesture as well if have not done so
                        [self _cancelAllDManipGestures];
                        dManipGesturesCancelled = YES;
                    }

                    if (DEBUG_GESTURES) {
                        TraceVerbose(TAG,
                                     L"gesture %hs is in state %d, cancel DManipGesture.",
                                     object_getClassName(curgesture),
                                     curgesture.state);
                    }
                }
            }
        }
    }

    if (!dManipGesturesCancelled) {
        // if DimanipGesture has not been cancelled, send touch to it for state transition
        for (_UIDMPanGestureRecognizer* dManipGesture in _dManipRecognizers) {
            if ([dManipGesture state] != UIGestureRecognizerStateCancelled) {
                id delegate = [dManipGesture delegate];

                BOOL send = TRUE;
                if (touch.phase == UITouchPhaseBegan && [delegate respondsToSelector:@selector(gestureRecognizer:shouldReceiveTouch:)]) {
                    send = [delegate gestureRecognizer:dManipGesture shouldReceiveTouch:touch];
                }

                if (send) {
                    [dManipGesture performSelector:eventName withObject:[NSMutableSet setWithObject:touch] withObject:event];
                    if (DEBUG_GESTURES) {
                        TraceVerbose(TAG,
                                     L"Send Touch with phase=%d to DManip gesture %hs.",
                                     touch.phase,
                                     object_getClassName(dManipGesture));
                    }
                }
            }
        }
    }

    BOOL shouldCancelTouches = NO;
    BOOL recognized = NO;

    // Fire regular gestures first
    for (UIGestureRecognizer* curGesture in _regularRecognizers) {
        id curgestureClass = [curGesture class];
        if (![curGesture isKindOfClass:[_UIDMPanGestureRecognizer class]]) {
            BOOL recognized = [curgestureClass _fireGesture:curGesture];
            if (recognized && DEBUG_GESTURES) {
                TraceVerbose(TAG, L"Gesture (%hs) handled.", object_getClassName(curgestureClass));
            }

            if ([curGesture isKindOfClass:[UIPanGestureRecognizer class]]) {
                // TODO: moved from UIPanGestureRecognizer, it is unclear why this special treatment is required earlier
                // or should not this be the common treatment for all gestures?
                shouldCancelTouches |= curGesture.cancelsTouchesInView;
            } else {
                shouldCancelTouches |= recognized;
            }
        }
    }

    // Gesture has not been recognized, fire Dimanip Gestures.
    if (!recognized) {
        for (UIGestureRecognizer* curGesture in _dManipRecognizers) {
            id curgestureClass = [curGesture class];
            if ([curGesture isKindOfClass:[_UIDMPanGestureRecognizer class]]) {
                BOOL recognized = [curgestureClass _fireGesture:curGesture];
                if (recognized && DEBUG_GESTURES) {
                    TraceVerbose(TAG, L"Gesture (%hs) handled.", object_getClassName(curgestureClass));
                }

                shouldCancelTouches |= recognized;
            }
        }
    }

    //  Removed/reset failed/done/cancelled gestures, including gestures and dManipGestures
    [self _resetAndClearGestureInEndingStateFrom:_dManipRecognizers];
    [self _resetAndClearGestureInEndingStateFrom:_regularRecognizers];

    return shouldCancelTouches;
}

// given an activeGesture, enumerate possible gesture list
// cancel gesture that can not concurrently fire and remove it from the intenral possible state gesture list
// NOTE: it is possible that the cancelled gesture is still in regular gesture list with the state to be cancelled
// But since we are in the middle of enumerating regular gesture list, remove it is from the list is actually
// less efficient than just check if it is in cancelled state, so we don't remove it here. it will be removed
// at end of processingGesture
- (void)_removeGesturesByActiveGesture:(UIGestureRecognizer*)activeGesture {
    BOOL activeResponds =
        [activeGesture.delegate respondsToSelector:@selector(gestureRecognizer:shouldRecognizeSimultaneouslyWithGestureRecognizer:)];

    [_gesturesInPossibleState removeObject:activeGesture];
    for (UIGestureRecognizer* possibleGesture in _gesturesInPossibleState) {
        // Based on reference platform: test if active gesture can prevent other gesture, if so, further check if the other gesture
        // can be prevented by active gesture if both result are YES, we need consult the delegates for both gesture.
        // if both delegates saying NO for concurrent firing the other gesture will be prevented from firing by active gesture.
        // NOTE: if delegate is not found, referece platform treat it as if the delegate exists and return NO
        if ([activeGesture canPreventGestureRecognizer:possibleGesture] &&
            [possibleGesture canBePreventedByGestureRecognizer:activeGesture]) {
            BOOL possibleResponds = [possibleGesture.delegate
                respondsToSelector:@selector(gestureRecognizer:shouldRecognizeSimultaneouslyWithGestureRecognizer:)];
            if ((!possibleResponds ||
                 ![possibleGesture.delegate gestureRecognizer:possibleGesture
                     shouldRecognizeSimultaneouslyWithGestureRecognizer:activeGesture]) &&
                (!activeResponds ||
                 ![activeGesture.delegate gestureRecognizer:activeGesture
                     shouldRecognizeSimultaneouslyWithGestureRecognizer:possibleGesture])) {
                [_gesturesToRemove addObject:possibleGesture];
                if (DEBUG_GESTURES) {
                    TraceVerbose(TAG,
                                 L"Prepare to remove gesture %hs state=%d, current active gesture %hs state=%d",
                                 object_getClassName(possibleGesture),
                                 possibleGesture.state,
                                 object_getClassName(activeGesture),
                                 activeGesture.state);
                }
            }
        }
    }

    // Remove those gesture that can not fire concurrently with current active Gestures
    for (UIGestureRecognizer* gestureToRemove in _gesturesToRemove) {
        if (DEBUG_GESTURES) {
            TraceVerbose(TAG,
                         L"Removing gesture %hs %x state=%d, reset its state",
                         object_getClassName(gestureToRemove),
                         gestureToRemove,
                         gestureToRemove.state);
        }

        // transite the gesture from possible to cancel state
        [gestureToRemove _cancel];

        // remove this cancelled gesture from both state list
        [_gesturesInPossibleState removeObject:gestureToRemove];
    }

    // Clean up gestureToRemove list, preparing for reuse next time
    [_gesturesToRemove removeAllObjects];
}

- (void)_cancelAllDManipGestures {
    // Scanning DManip Gestures, if one regular gesture is already ongoing, cancel all DManip Gestures
    // otherwise, send Touch to DManip gestures for state transition
    for (_UIDMPanGestureRecognizer* dManipGesture in _dManipRecognizers) {
        [dManipGesture _cancel];
        [_gesturesToRemove addObject:dManipGesture];
        if (DEBUG_GESTURES) {
            TraceVerbose(TAG, L"Cancelled DManip gesture %hs .", object_getClassName(dManipGesture));
        }
    }

    for (UIGestureRecognizer* gestureToRemove in _gesturesToRemove) {
        [_dManipRecognizers removeObject:gestureToRemove];
    }

    [_gesturesToRemove removeAllObjects];
}

- (void)_resetAndClearGestureInEndingStateFrom:(NSMutableArray*)gestures {
    for (UIGestureRecognizer* curGesture in gestures) {
        UIGestureRecognizerState state = [curGesture state];
        if (state == UIGestureRecognizerStateRecognized || state == UIGestureRecognizerStateEnded ||
            state == UIGestureRecognizerStateFailed || state == UIGestureRecognizerStateCancelled) {
            [_gesturesToRemove addObject:curGesture];
        }
    }

    for (UIGestureRecognizer* gestureToRemove in _gesturesToRemove) {
        if (DEBUG_GESTURES) {
            TraceVerbose(TAG,
                         L"Removing gesture %hs %x state=%d.",
                         object_getClassName(gestureToRemove),
                         gestureToRemove,
                         gestureToRemove.state);
        }
        [gestureToRemove reset];
        [gestures removeObject:gestureToRemove];
    }

    [_gesturesToRemove removeAllObjects];
}

// reset all gestures in all container to possible state and remove them from their container
// this is called by UIView when all finger are lifted (all touch ended or cancelled)
// thus all gestures are reset
- (void)resetTrackingGestureList {
    if (DEBUG_GESTURES) {
        TraceVerbose(TAG, L"resetTrackingGestureList");
    }

    _resetAllTrackingGestures = TRUE;

    [self _resetGetures:_regularRecognizers];
    [self _resetGetures:_dManipRecognizers];
    [_gesturesInPossibleState removeAllObjects];
}

// reset gestures in an container (transit to possible state), remove them from the container
- (void)_resetGetures:(NSMutableArray*)gestures {
    for (UIGestureRecognizer* curgesture in gestures) {
        if (DEBUG_GESTURES) {
            TraceVerbose(TAG, L"reset Gesture %hs", object_getClassName(curgesture));
        }
        [curgesture reset];
    }
    [gestures removeAllObjects];
}

// cancelTrackedGesture: if a given gesture is currently on file (tracked)
// remove it from its container.  Otherwise, no-op.
- (void)cancelTrackedGesture:(UIGestureRecognizer*)curgesture {
    NSUInteger i = NSNotFound;
    if ([curgesture isKindOfClass:[_UIDMPanGestureRecognizer class]]) {
        i = [_dManipRecognizers indexOfObject:curgesture];
        if (i != NSNotFound) {
            [_dManipRecognizers removeObjectAtIndex:i];
            [curgesture _cancel];
        }
    } else {
        i = [_regularRecognizers indexOfObject:curgesture];
        if (i != NSNotFound) {
            [_regularRecognizers removeObjectAtIndex:i];
            [curgesture _cancel];
        }

        if ([_gesturesInPossibleState containsObject:curgesture]) {
            [_gesturesInPossibleState removeObject:curgesture];
            [curgesture _cancel];
        }
    }
}

- (void)dealloc {
    [_gesturesToRemove release];
    [_dManipRecognizers release];
    [_regularRecognizers release];
    [_gesturesInPossibleState release];
    [super dealloc];
}

// check if any TapGesture required more than one tap
- (BOOL)containsTapGestureRequiredMultipleTap {
    for (UIGestureRecognizer* curGesture in _regularRecognizers) {
        if ([curGesture isKindOfClass:[UITapGestureRecognizer class]] && [(UITapGestureRecognizer*)curGesture numberOfTapsRequired] > 1) {
            return YES;
        }
    }

    return NO;
}

- (unsigned)maxNubmerOfTapsRequiredInAllTapGestures {
    unsigned maxNumberOfTapsRequired = 0;
    for (id curGesture in _regularRecognizers) {
        if ([curGesture isKindOfClass:[UITapGestureRecognizer class]] &&
            [(UITapGestureRecognizer*)curGesture numberOfTapsRequired] > maxNumberOfTapsRequired) {
            maxNumberOfTapsRequired = [curGesture numberOfTapsRequired];
        }
    }

    return maxNumberOfTapsRequired;
}

- (void)failOtherTapGesturesExcept:(UITapGestureRecognizer*)tapGesture {
    for (UIGestureRecognizer* curGesture in _regularRecognizers) {
        if (curGesture != tapGesture && [curGesture isKindOfClass:[UITapGestureRecognizer class]]) {
            if (curGesture.state != UIGestureRecognizerStatePossible) {
                curGesture.state = UIGestureRecognizerStateFailed;
            }
        }
    }
}

- (NSArray*)getRegularGestureRecognizers {
    return _regularRecognizers;
}

- (NSSet*)getGestureRecognizerInPossibleState {
    return _gesturesInPossibleState;
}

- (NSArray*)getDmanipGestureRecognizer {
    return _dManipRecognizers;
}

@end
