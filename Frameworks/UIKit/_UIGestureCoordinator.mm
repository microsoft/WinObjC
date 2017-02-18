//******************************************************************************
//
// Copyright (c) Microsoft Corporation. All rights reserved.
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
#import <UIKit/UIGestureRecognizerSubclass.h>

#import "UIViewInternal.h"
#import "UIGestureRecognizerInternal.h"
#import "_UIDirectManipulationRecognizer.h"

static const wchar_t* TAG = L"_UIGestureCoordinator";

static const bool DEBUG_ALL = false;
static const bool DEBUG_GESTURES = DEBUG_ALL || false;

static _UIGestureCoordinator* g_UIGestureCoordinator = nil;

@implementation _UIGestureCoordinator {
    // internal flag indicating all gestures has been reset or not, so when processing a touch, we need
    // rebuild tracking gesture list if this flag is YES. otherwise, don't re-build the tracking gestures
    BOOL _resetAllTrackingGestures;

    // gesture recognizer tracking list. Prefer NSMutableSortedSet, but we don't support yet.
    // using NSMutableArray instead, same reason for _dManipRecognizers
    // it gets rebuild when processing a touch if _resetAllTrackingGestures
    NSMutableArray* _gestureTrackingList;

    // system DManip gesture recognizer list
    // when _resetAllTrackingGestures is set to YES, during touch processing
    // we will rebuild DManip gesture list. This is for fast cancellation
    // purpose when necessary. Improve enumeration efficiency.
    NSMutableArray* _dManipRecognizers;

    // gesture list used for book keeping gestures to be removed in one Touch
    // processing cycle. When processing a Touch event, some gestures can be
    // cancelled or be recognized (ended), thus become ended. These gestures will be
    // stored in this variable and then cleaned up. So when processing next touch
    // we don't have to enumerate through these ended gestures, improve enumeration efficiency
    NSMutableSet* _gesturesToRemove;

    // gesture list used for book keeping gestures in UIGestureRecognizerStatePossible.
    // when one candidate gesture in _gestureTrackingList becomes active we need enumerate
    // this list to make sure that if all gestures in this list can be fired concurrently,
    // if not, they will be transit to cancelled state and removed from this list.
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
        _gestureTrackingList = [NSMutableArray new];
        _dManipRecognizers = [NSMutableArray new];
    }

    return self;
}

// build tracking gesture list given a view, if view is nil, it invokes buildTrackingGesturesListWith override to get
// custom build list of gesture for testing
- (void)_buildTrackingGesturesListForView:(UIView*)view {
    // Find gesture recognizers in the hierarchy, back-first
    UIView* curView = view;
    while (curView != nil) {
        // Adding enabled gestures on each view into cooresponding tracking gesture list
        for (UIGestureRecognizer* curGesture in curView->priv->gestures.get()) {
            if ([curGesture isEnabled]) {
                if (DEBUG_GESTURES) {
                    TraceVerbose(TAG, L"Adding gesture in %hs into gesture list.", object_getClassName(curGesture));
                }

                [_gestureTrackingList addObject:curGesture];

                // if it is DManipGesture, also add it into own book keeping container
                // for fast cancellation purpose
                if ([curGesture isKindOfClass:[_UIDMPanGestureRecognizer class]]) {
                    if (DEBUG_GESTURES) {
                        TraceVerbose(TAG,
                                     L"Found a %hs gesture, adding it into dmanip gesture list as well.",
                                     object_getClassName(curGesture));
                    }
                    [_dManipRecognizers addObject:curGesture];
                }

                // if gesture is in possible state, Also add it to possible state list
                if ([curGesture state] == UIGestureRecognizerStatePossible) {
                    if (DEBUG_GESTURES) {
                        TraceVerbose(TAG,
                                     L"%hs gesture is in possible state, adding it possible state list as well.",
                                     object_getClassName(curGesture));
                    }
                    [_gesturesInPossibleState addObject:curGesture];
                }
            }
        }

        curView = curView->priv->superview;
    }
}

// main entrance to send touch to gesture pipleline for processing
- (bool)processGesturesForTouch:(UITouch*)touch event:(UIEvent*)event touchEventName:(SEL)eventName {
    if (DEBUG_GESTURES) {
        TraceVerbose(TAG, L"processGesturesForTouch for touchphase = %d.", touch.phase);
    }

    if (_resetAllTrackingGestures) {
        _resetAllTrackingGestures = NO;
        [self _buildTrackingGesturesListForView:touch.view];
    }

    // Send touch to gestures for state transiton
    BOOL dManipGesturesCancelled = NO;
    for (UIGestureRecognizer* curGesture in _gestureTrackingList) {
        if ([curGesture state] != UIGestureRecognizerStateCancelled) {
            if (DEBUG_GESTURES) {
                TraceVerbose(TAG, L"Checking gesture %hs for touchphase =%d.", object_getClassName(curGesture), touch.phase);
            }

            id delegate = [curGesture delegate];
            BOOL send = YES;
            if (touch.phase == UITouchPhaseBegan && [delegate respondsToSelector:@selector(gestureRecognizer:shouldReceiveTouch:)]) {
                send = [delegate gestureRecognizer:curGesture shouldReceiveTouch:touch];
            }

            if (send) {
                [curGesture performSelector:eventName withObject:[NSMutableSet setWithObject:touch] withObject:event];
                // Verify if gesture state change to Began or recognized after transition, which means a gesture just become active
                if ((curGesture.state == UIGestureRecognizerStateBegan) || (curGesture.state == UIGestureRecognizerStateRecognized)) {
                    // Remove any gesture in possible state which can not fire concurrently with newly active gesture
                    [self _removeGesturesPreventedByActiveGesture:curGesture];

                    // Cancel all DManipGesture if current active gesture is not DManip gesture and we have not cancel them yet
                    if (![curGesture isKindOfClass:[_UIDMPanGestureRecognizer class]] && !dManipGesturesCancelled) {
                        if (DEBUG_GESTURES) {
                            TraceVerbose(TAG,
                                         L"gesture %hs is in state %d, cancel DManipGesture.",
                                         object_getClassName(curGesture),
                                         curGesture.state);
                        }

                        [self _cancelAllDManipGestures];
                        dManipGesturesCancelled = YES;
                    }
                }
            }
        }
    }

    BOOL shouldCancelTouches = NO;
    BOOL recognized = NO;

    // Fire gesture
    for (UIGestureRecognizer* curGesture in _gestureTrackingList) {
        id curGestureClass = [curGesture class];
        BOOL recognized = [curGestureClass _fireGesture:curGesture];
        if (recognized && DEBUG_GESTURES) {
            TraceVerbose(TAG, L"Gesture (%hs) handled.", object_getClassName(curGestureClass));
        }

        if ([curGesture isKindOfClass:[UIPanGestureRecognizer class]]) {
            // TODO: moved from UIPanGestureRecognizer, it is unclear why this special treatment is required earlier
            // or should not this be the common treatment for all gestures?
            shouldCancelTouches |= curGesture.cancelsTouchesInView;
        } else {
            shouldCancelTouches |= recognized;
        }
    }

    //  Removed/reset failed/done/cancelled gestures, including gestures and dManipGestures
    [self _resetAndClearGestureInEndingStateFrom:_gestureTrackingList];

    return shouldCancelTouches;
}

// given an activeGesture, enumerate possible gesture list
// cancel gesture that can not concurrently fire and remove it from the possible state gesture list
// NOTE: it is possible that the cancelled gesture is still in tracking gesture list with the state to be cancelled
// But since we are in the middle of enumerating gesture tracking list, remove it is from the list is actually
// less efficient than just check if it is in cancelled state, so we don't remove it here. it will be removed
// at end of processingGesture
//
// Based on reference platform: test if active gesture can prevent other gesture, if so, further check if the other gesture
// can be prevented by active gesture if both result are YES, we need consult the delegates for both gesture.
// if both delegates saying NO for concurrent firing the other gesture will be prevented from firing by active gesture.
// NOTE: if delegate is not found, reference platform treat it as if the delegate exists and return NO
// it can be break down into the following decision table: x stands for YES OR NO, or "does not matter".
//
// ----------------------------------------------------------------------------------------------------------------------_-----
// | ActiveGesture  | PossibleGesture  | Delegate for  |   Delegate for   | ActiveDelegate | Possible Delegate| Final Result  |
// | CanPrevent     | CanBePrevented   | ActiveGesture | PossibleGesture  | allow recognize| allow recognize  | To Prevent    |
// | PossibleGesture| By ActiveGesture |    Exists     |     Exists       | simultaneously |   simultaneously |PossibleGesture|
// | returns        | returns          |               |                  |                |                  |   Gesture     |
// ----------------------------------------------------------------------------------------------------------------------------
// |      NO       |       NO          |       X       |           X       |        X      |         X        |  NOT Prevent  |
// |      NO       |       YES         |       X       |           X       |        X      |         X        |  NOT Prevent  |
// |      YES      |       NO          |       X       |           X       |        X      |         X        |  NOT Prevent  |
// |      YES      |       YES         |       NO      |           NO      |        X      |         X        |  Prevent      |
// |      YES      |       YES         |       NO      |           YES     |        X      |         YES      |  NOT Prevent  |
// |      YES      |       YES         |       NO      |           YES     |        X      |         NO       |  Prevent      |
// |      YES      |       YES         |       YES     |           NO      |        YES    |         X        |  NOT Prevent  |
// |      YES      |       YES         |       YES     |           NO      |        NO     |         X        |  Prevent      |
// |      YES      |       YES         |       YES     |           YES     |        NO     |         NO       |  Prevent      |
// |      YES      |       YES         |       YES     |           YES     |        YES    |         NO       |  Not Prevent  |
// |      YES      |       YES         |       YES     |           YES     |        NO     |         YES      |  Not Prevent  |
// |      YES      |       YES         |       YES     |           YES     |        YES    |         YES      |  Not Prevent  |
// ---------------------------------------------------------------------------------------------------------------------------

- (void)_removeGesturesPreventedByActiveGesture:(UIGestureRecognizer*)activeGesture {
    BOOL activeResponds =
        [activeGesture.delegate respondsToSelector:@selector(gestureRecognizer:shouldRecognizeSimultaneouslyWithGestureRecognizer:)];
    [_gesturesInPossibleState removeObject:activeGesture];
    for (UIGestureRecognizer* possibleGesture in _gesturesInPossibleState) {
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
                         L"Cancel gesture that has been prevented %hs %x state=%d",
                         object_getClassName(gestureToRemove),
                         gestureToRemove,
                         gestureToRemove.state);
        }

        // transite the gesture from possible to cancel state
        [gestureToRemove _cancel];

        // remove this cancelled gesture from both state list
        [_gesturesInPossibleState removeObject:gestureToRemove];
    }

    [_gesturesToRemove removeAllObjects];
}

- (void)_cancelAllDManipGestures {
    for (_UIDMPanGestureRecognizer* dManipGesture in _dManipRecognizers) {
        if (DEBUG_GESTURES) {
            TraceVerbose(TAG, L"Cancelled DManip gesture %hs .", object_getClassName(dManipGesture));
        }

        [dManipGesture _cancel];
        [_gesturesToRemove addObject:dManipGesture];
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
                         L"Reset gesture %hs %x state=%d and remove it from tracking gesture list",
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

    _resetAllTrackingGestures = YES;

    [self _resetGetures:_gestureTrackingList];

    // clean up all booking conainer
    [_gesturesToRemove removeAllObjects];
    [_dManipRecognizers removeAllObjects];
    [_gesturesInPossibleState removeAllObjects];
}

// reset gestures in an container (transit to possible state), remove them from the container
- (void)_resetGetures:(NSMutableArray*)gestures {
    for (UIGestureRecognizer* curGesture in gestures) {
        if (DEBUG_GESTURES) {
            TraceVerbose(TAG, L"reset Gesture %hs", object_getClassName(curGesture));
        }
        [curGesture reset];
    }
    [gestures removeAllObjects];
}

// cancelTrackedGesture: if a given gesture is currently on file (tracked)
// remove it from its container.  Otherwise, no-op.
- (void)cancelTrackedGesture:(UIGestureRecognizer*)curGesture {
    NSUInteger i = NSNotFound;
    i = [_gestureTrackingList indexOfObject:curGesture];
    if (i != NSNotFound) {
        [_gestureTrackingList removeObjectAtIndex:i];
        [curGesture _cancel];
    }
}

- (void)dealloc {
    [_gesturesToRemove release];
    [_dManipRecognizers release];
    [_gestureTrackingList release];
    [_gesturesInPossibleState release];
    [super dealloc];
}

// check if any TapGesture required more than one tap
- (BOOL)containsTapGestureRequiredMultipleTap {
    for (UIGestureRecognizer* curGesture in _gestureTrackingList) {
        if ([curGesture isKindOfClass:[UITapGestureRecognizer class]] && [(UITapGestureRecognizer*)curGesture numberOfTapsRequired] > 1) {
            return YES;
        }
    }

    return NO;
}

- (unsigned)maxNubmerOfTapsRequiredInAllTapGestures {
    unsigned maxNumberOfTapsRequired = 0;
    for (id curGesture in _gestureTrackingList) {
        if ([curGesture isKindOfClass:[UITapGestureRecognizer class]] &&
            [(UITapGestureRecognizer*)curGesture numberOfTapsRequired] > maxNumberOfTapsRequired) {
            maxNumberOfTapsRequired = [curGesture numberOfTapsRequired];
        }
    }

    return maxNumberOfTapsRequired;
}

- (void)failOtherTapGesturesExcept:(UITapGestureRecognizer*)tapGesture {
    for (UIGestureRecognizer* curGesture in _gestureTrackingList) {
        if (curGesture != tapGesture && [curGesture isKindOfClass:[UITapGestureRecognizer class]]) {
            if (curGesture.state != UIGestureRecognizerStatePossible) {
                curGesture.state = UIGestureRecognizerStateFailed;
            }
        }
    }
}

- (NSArray*)getRegularGestureRecognizers {
    return _gestureTrackingList;
}

- (NSSet*)getGestureRecognizerInPossibleState {
    return _gesturesInPossibleState;
}

- (NSArray*)getDmanipGestureRecognizer {
    return _dManipRecognizers;
}

@end
