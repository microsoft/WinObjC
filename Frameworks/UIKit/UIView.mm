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
#import "UIAnimationNotification.h"
#import "QuartzCore/CABasicAnimation.h"
#import "QuartzCore/CALayer.h"
#import "UIAppearanceSetter.h"
#import "UIViewInternal.h"
#import "UIWindowInternal.h"
#import "UIViewControllerInternal.h"
#import "UIGestureRecognizerInternal.h"
#import "CALayerInternal.h"
#import "CAAnimationInternal.h"
#import <AutoLayout.h>
#import <NSLayoutConstraint+AutoLayout.h>
#import <UIView+AutoLayout.h>
#import "NSLayoutAnchorInternal.h"
#import "CACompositor.h"
#import <Windows.h>
#import <LoggingNative.h>
#import <NSLogging.h>
#import <objc/blocks_runtime.h>
#import "UWP/WindowsUIXamlControls.h"
#import "UIEventInternal.h"
#import "UITouchInternal.h"

#import <math.h>
#import <string>

@class UIAppearanceSetter;

static const wchar_t* TAG = L"UIView";
static const bool DEBUG_ALL = false;
static const bool DEBUG_TOUCHES_VERBOSE = DEBUG_ALL || false;
static const bool DEBUG_TOUCHES = DEBUG_TOUCHES_VERBOSE || false;
static const bool DEBUG_TOUCHES_LIGHT = DEBUG_TOUCHES || true;
static const bool DEBUG_HIT_TESTING = DEBUG_ALL || false;
static const bool DEBUG_HIT_TESTING_LIGHT = DEBUG_HIT_TESTING || true;
static const bool DEBUG_GESTURES = DEBUG_ALL || false;
static const bool DEBUG_LAYOUT = DEBUG_ALL || false;

const CGFloat UIViewNoIntrinsicMetric = -1.0f;

/** @Status Stub */
const CGSize UILayoutFittingCompressedSize = StubConstant();
/** @Status Stub */
const CGSize UILayoutFittingExpandedSize = StubConstant();

BOOL g_alwaysSendViewEvents = TRUE;
int g_animationsDisabled = 0, g_nestedAnimationsDisabled = 0;
BOOL g_presentingAnimated = FALSE;

typedef void (^animationBlockFunc)(void);
typedef void (^completionBlockFunc)(BOOL);
#define CALLBLOCK(b) b()
#define CALLCOMPLETIONBLOCK(b, finished) b(finished)
#define COPYBLOCK(b) Block_copy(b)

typedef struct {
    int _numAnimations;
    double _animationDuration;
    double _animationDelay;
    id _animationDelegate;
    idretaint<CAMediaTimingFunction> _animationCurve;
    id _animationID;
    void* _context;
    SEL _animationWillStartSelector;
    SEL _animationDidStopSelector;
    BOOL _autoReverses;
    BOOL _beginsFromCurrentState;
    float _repeatCount;
    UIAnimationNotification* _animationNotifier;
    completionBlockFunc _completionBlock;
} AnimationProperties;

static AnimationProperties _animationProperties[32];
static int stackLevel = 0;

int viewCount = 0;

@implementation UIView {
    idretaintype(CALayer) layer;
    bool _deallocating;
}

@synthesize preferredFocusedView;
@synthesize traitCollection;
@synthesize collisionBoundsType;
@synthesize collisionBoundingPath;

- (UIViewPrivateState*)_privateState {
    return priv;
}

// TODO: GitHub issue 508 and 509
// We need a type-safe way to do this with projections.  This is copied verbatim from the projections
// code and works perfectly for this limited usage, but we don't do any type validation below.
inline id _createRtProxy(Class cls, IInspectable* iface) {
    // Oddly, WinRT can hand us back NULL objects from successful function calls. Plumb these through as nil.
    if (!iface) {
        return nil;
    }

    RTObject* ret = [NSAllocateObject(cls, 0, 0) init];
    [ret setComObj:iface];
    return [ret autorelease];
}

///////////////////////////////////////////////////////////////////////////////////////////
// TODO: This block of code will likely change when we incorporate WinRT GestureRecognizers
NSMutableDictionary* g_curGesturesDict;
id g_currentlyTrackingGesturesList;
BOOL g_resetAllTrackingGestures = TRUE;
- (bool)_processGesturesForTouch:(UITouch*)touch event:(UIEvent*)event touchEventName:(SEL)eventName {
    UIView* view = touch.view;
    if (view == nil) {
        return false;
    }

    if (!g_currentlyTrackingGesturesList) {
        g_currentlyTrackingGesturesList = [NSMutableArray new];
    }

    bool handled = false;

    UIView* views[128];
    int viewDepth = 0;
    if (g_resetAllTrackingGestures) {
        g_resetAllTrackingGestures = FALSE;
        //  Find gesture recognizers in the heirarchy, back-first
        UIView* curView = view;

        while (curView != nil) {
            assert(viewDepth < 128);
            views[viewDepth++] = curView;
            curView = curView->priv->superview;
        }

        for (int i = viewDepth - 1; i >= 0; i--) {
            curView = views[i];

            for (UIGestureRecognizer* curgesture in curView->priv->gestures) {
                if ([curgesture isEnabled]) {
                    [g_currentlyTrackingGesturesList addObject:curgesture];
                }
            }
        }
    }

    viewDepth = 0;

    g_curGesturesDict = [NSMutableDictionary new];

    UIGestureRecognizer* recognizers[128];

    for (UIGestureRecognizer* curgesture in g_currentlyTrackingGesturesList) {
        recognizers[viewDepth++] = curgesture;

        id gestureClass = [curgesture class];
        NSMutableArray* arr = [g_curGesturesDict objectForKey:gestureClass];
        if (arr == nil) {
            arr = [NSMutableArray new];
            [g_curGesturesDict setObject:arr forKey:gestureClass];
            [arr release];
        }
        [arr addObject:curgesture];
    }

    for (int i = 0; i < viewDepth; i++) {
        UIGestureRecognizer* curgesture = recognizers[i];

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
            }
        }
    }

    // gesture priority list
    const static id s_gesturesPriority[] = {[UIPinchGestureRecognizer class],
                                            [UISwipeGestureRecognizer class],
                                            [UIPanGestureRecognizer class],
                                            [UILongPressGestureRecognizer class],
                                            [UITapGestureRecognizer class] };

    const static int s_numGestureTypes = sizeof(s_gesturesPriority) / sizeof(s_gesturesPriority[0]);

    //  Process all gestures
    for (int i = 0; i < s_numGestureTypes; i++) {
        id curgestureClass = s_gesturesPriority[i];
        id gestures = [g_curGesturesDict objectForKey:curgestureClass];
        if ([curgestureClass _fireGestures:gestures]) {
            handled = true;
            if (handled && DEBUG_GESTURES) {
                TraceVerbose(TAG, L"Gesture (%hs) handled.", object_getClassName(curgestureClass));
            }
        }
    }

    //  Removed/reset failed/done gestures
    for (int i = 0; i < viewDepth; i++) {
        UIGestureRecognizer* curgesture = recognizers[i];
        UIGestureRecognizerState state = (UIGestureRecognizerState)[curgesture state];

        if (state == UIGestureRecognizerStateRecognized || state == UIGestureRecognizerStateEnded ||
            state == UIGestureRecognizerStateFailed || state == UIGestureRecognizerStateCancelled) {
            [curgesture reset];

            if (DEBUG_GESTURES) {
                TraceVerbose(TAG, L"Removing gesture %hs %x state=%d.", object_getClassName(curgesture), curgesture, state);
            }

            [g_currentlyTrackingGesturesList removeObject:curgesture];
            id gesturesArr = [g_curGesturesDict objectForKey:[curgesture class]];
            [gesturesArr removeObject:curgesture];
        }
    }

    [g_curGesturesDict release];
    g_curGesturesDict = nil;

    return handled;
}
// TODO: This block of code will likely change when we incorporate WinRT GestureRecognizers
///////////////////////////////////////////////////////////////////////////////////////////

// Struct which binds a static UITouch instance to a XAML pointer id.
// TouchPoints are created on-demand (in touchPointFromPointerId below),
// and they are bound to a single XAML pointer id for the remainder of the app lifetime.
struct TouchPoint {
    static const int s_invalidPointerId = -1;
    int pointerId = s_invalidPointerId;
    bool isPressed = false;
    StrongId<UITouch> touch;
};

// The collection of static touchpoints we'll use for the duration of this app.
TouchPoint s_touchPoints[10] = {};

// Returns a static TouchPoint instance for the given pointerId.  Creates one if it doesn't already exist.
static TouchPoint& _touchPointFromPointerId(int pointerId) {
    // Look for an existing entry for this pointer id
    for (auto& touchPoint : s_touchPoints) {
        if (touchPoint.pointerId == pointerId) {
            return touchPoint;
        }
    }

    // No existing entry found, so reserve one
    for (auto& touchPoint : s_touchPoints) {
        if (touchPoint.pointerId == TouchPoint::s_invalidPointerId) {
            touchPoint.pointerId = pointerId;

            // Allocate a UITouch instance for this entry if necessary
            if (!touchPoint.touch) {
                touchPoint.touch.attach([UITouch _createWithPoint:CGPointMake(0, 0)]);
            }

            return touchPoint;
        }
    }

    // Out of touch points!
    FAIL_FAST();
}

// Reset the given touch point, making it available for reuse on further touch events
static void _resetTouchPoint(TouchPoint& touchPoint) {
    if (DEBUG_TOUCHES_VERBOSE) {
        TraceVerbose(TAG, L"Resetting touch point: %d.", touchPoint.pointerId);
    }
    touchPoint.touch->_view = nil;
    touchPoint.pointerId = TouchPoint::s_invalidPointerId;
}

static std::string _printViewHeirarchy(UIView* leafView) {
    std::string logString;
    char buffer[1024];
    for (UIView* current = leafView; current != nil; current = current->priv->superview) {
        int charactersWritten = sprintf_s(&buffer[0],
                                          ARRAYSIZE(buffer) - 1, // Leave room for our null terminator
                                          "%hs(0x%08x, _isHitTestable=%hs, XAML_HitTestable=%hs)<-",
                                          object_getClassName(current),
                                          current,
                                          [current _isHitTestable] ? "true" : "false",
                                          [current->priv->_xamlInputElement isHitTestVisible] ? "true" : "false");
        buffer[charactersWritten] = '\0';
        logString += buffer;
    }

    return logString;
}

- (UIView*)_doHitTest:(UITouch*)touch allTouches:(NSMutableSet<UITouch*>*)allTouches {
    if (!DEBUG_HIT_TESTING_LIGHT && !UIApplication.displayMode.useLegacyHitTesting) {
        // Don't do any unneeded work
        return self;
    }

    // Create a temp event solely for hit-testing purposes
    UIEvent* hitTestEvent = [[UIEvent _createWithTouches:allTouches forNewTouch:touch] autorelease];

    // Perform a hit test starting at the owning window
    UIWindow* rootWindow = [self _getWindowInternal];
    CGPoint point = { touch->_touchX, touch->_touchY };
    point = [rootWindow convertPoint:point fromView:rootWindow toView:rootWindow];
    UIView* hitTestResult = [rootWindow hitTest:point withEvent:hitTestEvent];

    if (hitTestResult && (hitTestResult != self)) {
        if (DEBUG_HIT_TESTING_LIGHT) {
            std::string selfTree = _printViewHeirarchy(self);
            std::string hitTestTree = _printViewHeirarchy(hitTestResult);
            TraceWarning(TAG,
                         L"XAML's chosen hit test view: \r\n\t %hs \r\n ...does not match the legacy hit test results: \r\n\t %hs.",
                         selfTree.c_str(),
                         hitTestTree.c_str());
        }

        // Note: This functionality will be deprecated in future releases
        if (UIApplication.displayMode.useLegacyHitTesting) {
            TraceWarning(TAG,
                         L"Returning legacy hit test view %hs(0x%08x) because UIApplication.displayMode.useLegacyHitTesting is enabled.",
                         object_getClassName(hitTestResult),
                         hitTestResult);
            return hitTestResult;
        }
    }

    // By default, use 'self' even if the hit test didn't match up
    return self;
}

- (UITouchPhase)_processPointerEvent:(WUXIPointerRoutedEventArgs*)pointerEventArgs forTouchPhase:(UITouchPhase)touchPhase {
    // The collection of active touches reused for the duration of this app
    static StrongId<NSMutableSet<UITouch*>> s_allTouches = [NSMutableSet<UITouch*> set];

    // The touch event we'll reuse for the duration of this app
    static StrongId<UIEvent> s_touchEvent = [[UIEvent alloc] init];

    // Grab our owning window so we can translate the touch point to its coordinate space.
    UIWindow* owningWindow = [self _getWindowInternal];

    // Sometimes we're seeing touches for Views that don't have a parent; we should probably track this down at some point,
    // as these Views should probably be temporarily hit-test disabled during the transition.
    // At least log for now in case we see any strange behavior that results from this.
    if (!owningWindow) {
        TraceVerbose(TAG,
                     L"Touched view %hs(0x%08x) for phase %d doesn't have a parent window with which to translate the touch point "
                     L"coordinates; falling back to XAML's root coordinate space.",
                     object_getClassName(self),
                     self,
                     touchPhase);
    }

    // Get the point value in this view's parent UIWindow's coordinates
    WUIPointerPoint* pointerPoint = [pointerEventArgs getCurrentPoint:(owningWindow ? owningWindow->priv->_xamlInputElement : nil)];

    // Locate the static TouchPoint object for this pointerId
    TouchPoint& touchPoint = _touchPointFromPointerId([pointerPoint pointerId]);

    // Ignore move events if the pointer isn't pressed
    if ((touchPhase != UITouchPhaseBegan) && !touchPoint.isPressed) {
        if (DEBUG_TOUCHES_VERBOSE) {
            TraceVerbose(TAG, L"Touch point not pressed; ignoring touch event for phase:%d.", touchPhase);
        }

        // Reset the touch point since we don't need it
        _resetTouchPoint(touchPoint);
        return UITouchPhaseCancelled;
    }

    // Update the touch info for this pointer event
    [touchPoint.touch _updateWithPoint:pointerPoint forPhase:touchPhase];

    // Preprocess pointer event
    SEL touchEventName;
    switch (touchPhase) {
        case UITouchPhaseBegan:
            // Toggle the touchPoint's pressed state
            touchPoint.isPressed = true;

            // Add this touch to the set of all current touches in the app
            [s_allTouches addObject:touchPoint.touch];

            // Assign the correct selector
            touchEventName = @selector(touchesBegan:withEvent:);
            break;

        case UITouchPhaseMoved:
            // Assign the correct selector
            touchEventName = @selector(touchesMoved:withEvent:);
            break;

        case UITouchPhaseEnded:
            // Assign the correct selector
            touchEventName = @selector(touchesEnded:withEvent:);
            touchPoint.isPressed = false;
            break;

        case UITouchPhaseCancelled:
            // Assign the correct selector
            touchEventName = @selector(touchesCancelled:withEvent:);
            touchPoint.isPressed = false;
            break;

        default:
            FAIL_FAST();
    }

    // Keep the static touch event up to date
    [s_touchEvent _updateWithTouches:s_allTouches touchEvent:touchPoint.touch];

    // Set the touch's view
    if (DEBUG_HIT_TESTING_LIGHT) {
        TraceVerbose(TAG, L"Hit testing view %hs(0x%08x) for touchPhase %d.", object_getClassName(self), self, touchPhase);
    }
    touchPoint.touch->_view = [self _doHitTest:touchPoint.touch allTouches:s_allTouches];

    // Run through GestureRecognizers
    bool touchCanceled =
        [touchPoint.touch->_view _processGesturesForTouch:touchPoint.touch event:s_touchEvent touchEventName:touchEventName];

    // The gesture was recognized, so cancel any current touches on the view (including this touch)
    if (touchCanceled) {
        touchPoint.touch->_phase = UITouchPhaseCancelled;
        touchEventName = @selector(touchesCancelled:withEvent:);
    }

    if (touchPhase != UITouchPhaseBegan && ![touchPoint.touch->_view->priv->currentTouches containsObject:touchPoint.touch]) {
        // Ignore if the pointer isn't captured
        if (DEBUG_TOUCHES_LIGHT) {
            TraceVerbose(TAG,
                         L"View %hs(0x%08x) not aware of touch, ignoring touch for touchPhase %d.",
                         object_getClassName(touchPoint.touch->_view),
                         static_cast<UIView*>(touchPoint.touch->_view),
                         touchPhase);
        }
    } else if (touchPhase == UITouchPhaseBegan && !touchPoint.touch->_view->priv->multipleTouchEnabled &&
               ([touchPoint.touch->_view->priv->currentTouches count] > 0)) {
        // Ignore if we already have a touch for this view and !multipleTouchEnabled
        if (DEBUG_TOUCHES_LIGHT) {
            TraceVerbose(TAG,
                         L"View %hs(0x%08x) already has a touch, ignoring this subsequent touch due to !multipleTouchEnabled.",
                         object_getClassName(touchPoint.touch->_view),
                         static_cast<UIView*>(touchPoint.touch->_view));
        }
    } else {
        // Prepare to send the event to the target view
        NSMutableSet* touchesForEvent;
        switch (touchPoint.touch->_phase) {
            case UITouchPhaseBegan:
                // Track the touch in this view
                [touchPoint.touch->_view->priv->currentTouches addObject:touchPoint.touch];

                if (DEBUG_TOUCHES_LIGHT) {
                    TraceVerbose(TAG,
                                 L"Firing UITouchPhaseBegan to %hs(0x%08x).",
                                 object_getClassName(touchPoint.touch->_view),
                                 static_cast<UIView*>(touchPoint.touch->_view));
                }

                // Use this sole touch for the event we send to the view
                // TODO: This is how it worked before; is that the expected behavior?
                touchesForEvent = [NSMutableSet setWithObject:touchPoint.touch];
                break;

            case UITouchPhaseMoved:
                if (DEBUG_TOUCHES_LIGHT) {
                    TraceVerbose(TAG,
                                 L"Firing UITouchPhaseMoved to %hs(0x%08x).",
                                 object_getClassName(touchPoint.touch->_view),
                                 static_cast<UIView*>(touchPoint.touch->_view));
                }

                // Use *all* of the view's current touches for the event we send to to it
                // TODO: This is how it worked before; is that the expected behavior?
                touchesForEvent = [NSMutableSet setWithArray:touchPoint.touch->_view->priv->currentTouches];
                break;

            case UITouchPhaseEnded:
            case UITouchPhaseCancelled:
                if (DEBUG_TOUCHES_LIGHT) {
                    TraceVerbose(TAG,
                                 L"Firing %hs to %hs(0x%08x).",
                                 (touchPoint.touch->_phase == UITouchPhaseEnded) ? "UITouchPhaseEnded" : "UITouchPhaseCancelled",
                                 object_getClassName(touchPoint.touch->_view),
                                 static_cast<UIView*>(touchPoint.touch->_view));
                }

                // Remove the touch point from the view
                [touchPoint.touch->_view->priv->currentTouches removeObject:touchPoint.touch];

                // Use this sole touch for the event we send to the view
                // TODO: This is how it worked before; is that the expected behavior?
                touchesForEvent = [NSMutableSet setWithObject:touchPoint.touch];
                break;

            default:
                break;
        }

        // Send the appropriate event to the hit test view
        [touchPoint.touch->_view performSelector:touchEventName withObject:touchesForEvent withObject:s_touchEvent];
    }

    // Final cleanup based on the actual pointer event (not the coerced event after running through gestures)
    switch (touchPhase) {
        case UITouchPhaseEnded:
        case UITouchPhaseCancelled:
            if (DEBUG_TOUCHES) {
                TraceVerbose(TAG, L"Final cleanup for touch point %d, due to touch phase %d.", touchPoint.pointerId, touchPhase);
            }

            // Clean up s_allTouches as this is no longer a valid touch point
            [s_allTouches removeObject:touchPoint.touch];

            // Reset the touch point since we're no longer tracking it
            _resetTouchPoint(touchPoint);

            /////////////////////////////////////////////////////////////////////////////
            // TODO: This block will be removed once we move to WinRT gesture recognizers
            //  If all fingers come off the screen, reset all gestures
            g_resetAllTrackingGestures = TRUE;
            for (auto& touchPoint : s_touchPoints) {
                if (touchPoint.touch && touchPoint.touch->_view) {
                    g_resetAllTrackingGestures = FALSE;
                }
            }

            if (g_resetAllTrackingGestures) {
                for (UIGestureRecognizer* curgesture in g_currentlyTrackingGesturesList) {
                    [curgesture reset];
                }

                [g_currentlyTrackingGesturesList removeAllObjects];
            }
            // TODO: This block will be removed once we move to WinRT gesture recognizers
            /////////////////////////////////////////////////////////////////////////////

            break;

        default:
            break;
    }

    // Clear out the stored _pointerPoint on the touch for this event since we shouldn't hold onto them
    touchPoint.touch->_pointerPoint = nil;

    // Return the coerced UITouchPhase to the caller
    return touchPoint.touch->_phase;
}

// Calculate whether or not this view should be hit testable
- (BOOL)_isHitTestable {
    if (!priv->userInteractionEnabled) {
        if (DEBUG_HIT_TESTING) {
            TraceVerbose(TAG,
                         L"_isHitTestable returning NO for %hs(0x%08x) because !priv->userInteractionEnabled.",
                         object_getClassName(self),
                         self);
        }
        return NO;
    }

    if ([self isHidden]) {
        if (DEBUG_HIT_TESTING) {
            TraceVerbose(TAG, L"_isHitTestable returning NO for %hs(0x%08x) because [self isHidden].", object_getClassName(self), self);
        }
        return NO;
    }

    if ([self alpha] <= 0.01f) {
        if (DEBUG_HIT_TESTING) {
            TraceVerbose(TAG,
                         L"_isHitTestable returning NO for %hs(0x%08x) because [self alpha] <= 0.01f.",
                         object_getClassName(self),
                         self);
        }
        return NO;
    }

    return YES;
}

// Update hit test state on our backing XAML element
- (void)_updateHitTestability {
    // Should we currently be hit testable?
    BOOL isHitTestable = [self _isHitTestable];

    if (DEBUG_HIT_TESTING) {
        if ([self->priv->_xamlInputElement isHitTestVisible] != isHitTestable) {
            TraceVerbose(TAG,
                         L"Changing the XAML element for %hs(0x%08x) to hit-testable=%hs.",
                         object_getClassName(self),
                         self,
                         isHitTestable ? "true" : "false");
        } else {
            TraceVerbose(TAG,
                         L"The XAML element for %hs(0x%08x) is already set to hit-testable=%hs.",
                         object_getClassName(self),
                         self,
                         isHitTestable ? "true" : "false");
        }
    }

    // Update our _xamlInputElement as needed
    [self->priv->_xamlInputElement setIsHitTestVisible:isHitTestable];
}

- (void)_initPriv {
    if (self->priv) {
        return;
    }

    viewCount++;

    // Create the private backing object
    self->priv = new UIViewPrivateState(self);

    // Configure autolayout
    static bool isAutoLayoutInitialized = InitializeAutoLayout();
    [self autoLayoutAlloc];

    // Create and initialize our backing presentation layer
    self->layer.attach([[[self class] layerClass] new]);
    [self->layer setDelegate:self];

    // Grab the layer's backing XAML node
    Microsoft::WRL::ComPtr<IInspectable> inspectableNode(GetCACompositor()->GetXamlLayoutElement([self->layer _presentationNode]));
    self->priv->_xamlInputElement = _createRtProxy([WXFrameworkElement class], inspectableNode.Get());

    // Set the XAML element's name so it's easily found in the VS live tree viewer
    [self->priv->_xamlInputElement setName:[NSString stringWithUTF8String:object_getClassName(self)]];

    // Subscribe to the XAML node's input events
    __block UIView* weakSelf = self;
    self->priv->_pointerPressedEventRegistration =
        [self->priv->_xamlInputElement addPointerPressedEvent:^(RTObject* sender, WUXIPointerRoutedEventArgs* e) {
            // Capture the pointer within this xaml element
            [weakSelf->priv->_xamlInputElement capturePointer:e.pointer];

            // Set the event to handled, then process it as a UITouch
            e.handled = YES;
            [weakSelf _processPointerEvent:e forTouchPhase:UITouchPhaseBegan];
        }];

    self->priv->_pointerMovedEventRegistration =
        [self->priv->_xamlInputElement addPointerMovedEvent:^(RTObject* sender, WUXIPointerRoutedEventArgs* e) {
            // Set the event to handled, then process it as a UITouch
            e.handled = YES;
            [weakSelf _processPointerEvent:e forTouchPhase:UITouchPhaseMoved];
        }];

    self->priv->_pointerReleasedEventRegistration =
        [self->priv->_xamlInputElement addPointerReleasedEvent:^(RTObject* sender, WUXIPointerRoutedEventArgs* e) {
            // Set the event to handled, then process it as a UITouch
            e.handled = YES;
            [weakSelf _processPointerEvent:e forTouchPhase:UITouchPhaseEnded];
        }];

    self->priv->_pointerCanceledEventRegistration =
        [self->priv->_xamlInputElement addPointerCanceledEvent:^(RTObject* sender, WUXIPointerRoutedEventArgs* e) {
            // Set the event to handled, then process it as a UITouch
            e.handled = YES;
            // Uncommon event; we'll use the same handling as pointer capture lost (below)
            [weakSelf _processPointerEvent:e forTouchPhase:UITouchPhaseCancelled];
        }];

    self->priv->_pointerCaptureLostEventRegistration =
        [self->priv->_xamlInputElement addPointerCaptureLostEvent:^(RTObject* sender, WUXIPointerRoutedEventArgs* e) {
            // Set the event to handled, then process it as a UITouch
            e.handled = YES;
            // Treat capture lost just like a pointer canceled (which is actually quite uncommon)
            [weakSelf _processPointerEvent:e forTouchPhase:UITouchPhaseCancelled];
        }];
}

/**
 @Public No
*/
- (void)initAccessibility {
    self.isAccessibilityElement = FALSE;
    self.accessibilityTraits = UIAccessibilityTraitNone;
    [self updateAccessibility];
}

/**
 @Public No
*/
- (void)updateAccessibility {
    IWUpdateAccessibility(self.layer, self);
}

/**
 @Status Interoperable
*/
+ (instancetype)allocWithZone:(NSZone*)zone {
    UIView* ret = [super allocWithZone:zone];

    // Run on the main thread because the underlying XAML objects can only be
    // called from the UI thread
    RunSynchronouslyOnMainThread(^{
        [ret _initPriv];
    });

    return ret;
}

static UIView* initInternal(UIView* self, CGRect pos) {
    if (DEBUG_LAYOUT) {
        TraceVerbose(TAG, L"[%f,%f] @ %fx%f", (float)pos.origin.x, (float)pos.origin.y, (float)pos.size.width, (float)pos.size.height);
    }

    // Run on the main thread because the underlying XAML objects can only be
    // called from the UI thread
    RunSynchronouslyOnMainThread(^{
        [self _initPriv];
        [self setOpaque:TRUE];
        [self setFrame:pos];
        [self setNeedsDisplay];
        [self initAccessibility];
    });

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFrame:(CGRect)pos {
    return initInternal(self, pos);
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    CGRect pos;

    pos.origin.x = 0;
    pos.origin.y = 0;
    pos.size.width = 0;
    pos.size.height = 0;

    return [self initWithFrame:pos];
}

#define PAUSE_ANIMATIONS() g_nestedAnimationsDisabled++;
#define CONTINUE_ANIMATIONS()           \
    g_nestedAnimationsDisabled--;       \
    if (g_nestedAnimationsDisabled < 0) \
        g_nestedAnimationsDisabled = 0;

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    CGRect bounds;

    id boundsObj = [coder decodeObjectForKey:@"UIBounds"];
    if (boundsObj != nil) {
        if ([boundsObj isKindOfClass:[NSString class]]) {
            bounds = CGRectFromString(boundsObj);
        } else {
            memcpy(&bounds, reinterpret_cast<const char*>([boundsObj bytes]) + 1, sizeof(CGRect));
        }
    } else {
        bounds.origin.x = 0;
        bounds.origin.y = 0;
        bounds.size.width = 0;
        bounds.size.height = 0;
    }

    CGPoint center;

    id centerObj = [coder decodeObjectForKey:@"UICenter"];
    if (centerObj) {
        if ([centerObj isKindOfClass:[NSString class]]) {
            center = CGPointFromString(centerObj);
        } else {
            memcpy(&center, reinterpret_cast<const char*>([centerObj bytes]) + 1, sizeof(CGPoint));
        }
    } else {
        center.x = 0;
        center.y = 0;
    }

    PAUSE_ANIMATIONS();
    [self setBounds:bounds];
    [self setCenter:center];
    [self setNeedsDisplay];
    if ([coder containsValueForKey:@"UIAlpha"]) {
        float val = [coder decodeFloatForKey:@"UIAlpha"];
        [self setAlpha:val];
    }
    if ([coder containsValueForKey:@"UIContentStretch"]) {
        CGRect rect;

        id obj = [coder decodeObjectForKey:@"UIContentStretch"];
        if ([obj isKindOfClass:[NSString class]]) {
            rect = CGRectFromString(obj);
        } else {
            memcpy(&rect, (char*)[obj bytes] + 1, sizeof(CGRect));
        }

        [self setContentStretch:rect];
    }

    CONTINUE_ANIMATIONS();

    if ([coder decodeInt32ForKey:@"UIUserInteractionDisabled"]) {
        [self setUserInteractionEnabled:NO];
    }

    self.contentMode = (UIViewContentMode)[coder decodeInt32ForKey:@"UIContentMode"];

    id uiDelegate = [coder decodeObjectForKey:@"UIDelegate"];
    if (uiDelegate != nil) {
        if ([self respondsToSelector:@selector(setDelegate:)]) {
            [self performSelector:@selector(setDelegate:) withObject:uiDelegate];
        } else {
            TraceWarning(TAG, L"UIDelegate decoded but %hs(0x%08x) doesn't support setDelegate!", object_getClassName(self), self);
        }
    }

    NSArray* subviewsObj = [coder decodeObjectForKey:@"UISubviews"];
    if (subviewsObj != nil) {
        int count = [subviewsObj count];

        for (int i = 0; i < count; i++) {
            UIView* subView = [subviewsObj objectAtIndex:i];
            [self addSubview:subView];
        }
    }

    if ([coder containsValueForKey:@"UIViewDoesNotTranslateAutoresizingMaskIntoConstraints"]) {
        priv->translatesAutoresizingMaskIntoConstraints =
            ![coder decodeInt32ForKey:@"UIViewDoesNotTranslateAutoresizingMaskIntoConstraints"];
    }

    if ([coder containsValueForKey:@"UIViewContentCompressionResistancePriority"]) {
        id sizeObj = [coder decodeObjectForKey:@"UIViewContentCompressionResistancePriority"];
        if ([sizeObj isKindOfClass:[NSString class]]) {
            const char* stretchStr = [sizeObj UTF8String];
            sscanf_s(stretchStr,
                     "{%f, %f}",
                     &priv->_contentCompressionResistancePriority.width,
                     &priv->_contentCompressionResistancePriority.height);
        } else {
            CGSize* size = (CGSize*)[sizeObj bytes];
            memcpy(&priv->_contentCompressionResistancePriority, size, sizeof(CGRect));
        }
    }

    if ([coder containsValueForKey:@"UIViewContentHuggingPriority"]) {
        id sizeObj = [coder decodeObjectForKey:@"UIViewContentHuggingPriority"];
        if ([sizeObj isKindOfClass:[NSString class]]) {
            const char* stretchStr = [(NSString*)sizeObj UTF8String];
            sscanf_s(stretchStr, "{%f, %f}", &priv->_contentHuggingPriority.width, &priv->_contentHuggingPriority.height);
        } else {
            CGSize* size = (CGSize*)[sizeObj bytes];
            memcpy(&priv->_contentHuggingPriority, size, sizeof(CGRect));
        }
    }

    if ([coder containsValueForKey:@"UIViewAutolayoutConstraints"]) {
        NSArray* constraints = [coder decodeObjectForKey:@"UIViewAutolayoutConstraints"];
        NSArray* removeConstraints = [coder decodeObjectForKey:@"_UILayoutGuideConstraintsToRemove"];
        int count = [constraints count];
        for (int i = 0; i < count; i++) {
            NSLayoutConstraint* constraint = [constraints objectAtIndex:i];
            if ([constraint isKindOfClass:[NSLayoutConstraint class]]) {
                bool remove = false;
                for (int i = 0; i < [removeConstraints count]; i++) {
                    NSLayoutConstraint* wayward = [removeConstraints objectAtIndex:i];
                    if (wayward == constraint) {
                        NSTraceVerbose(TAG, @"Removing constraint (%@)", [wayward description]);
                        [wayward _printConstraint];
                        remove = true;
                        break;
                    }
                }

                if (![priv->constraints containsObject:constraint] && !remove) {
                    [priv->constraints addObject:constraint];
                    [constraint autoLayoutConstraintAddedToView:self];
                }
            } else {
                NSTraceVerbose(TAG, @"Skipping unsupported constraint type: %@", [constraint description]);
            }
        }
    }

    [NSLayoutConstraint _printConstraints:self.constraints];

    [self setHidden:[coder decodeInt32ForKey:@"UIHidden"]];

    priv->autoresizesSubviews = [coder decodeInt32ForKey:@"UIAutoresizeSubviews"];
    priv->autoresizingMask = (UIViewAutoresizing)[coder decodeInt32ForKey:@"UIAutoresizingMask"];
    priv->tag = [coder decodeInt32ForKey:@"UITag"];
    priv->multipleTouchEnabled = [coder decodeInt32ForKey:@"UIMultipleTouchEnabled"];

    [self setOpaque:[coder decodeInt32ForKey:@"UIOpaque"]];
    [self setClipsToBounds:[coder decodeInt32ForKey:@"UIClipsToBounds"]];

    UIColor* backgroundColor = [coder decodeObjectForKey:@"UIBackgroundColor"];
    if (backgroundColor != nil) {
        self.backgroundColor = backgroundColor;
    }

    NSArray* gestures = [coder decodeObjectForKey:@"gestureRecognizers"];
    if (gestures != nil) {
        TraceVerbose(TAG, L"UIView initWithCoder adding gesture recognizers");
        [self setGestureRecognizers:gestures];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)encodeWithCoder:(NSCoder*)coder {
    TraceWarning(TAG, L"Unsupported attempt to encode a UIView");
}

/**
 @Status Interoperable
*/
- (BOOL)gestureRecognizerShouldBegin:(UIGestureRecognizer*)gestureRecognizer {
    return YES;
}

/**
 @Status Interoperable
*/
- (NSArray*)layoutGuides {
    return [[priv->_layoutGuides copy] autorelease];
}

/**
 @Status Interoperable
*/
- (void)addLayoutGuide:(UILayoutGuide*)layoutGuide {
    if (layoutGuide == nil) {
        @throw [NSException exceptionWithName:NSInvalidArgumentException reason:@"Cannot add nil UILayoutGuide!" userInfo:nil];
    }
    if (layoutGuide.owningView != self) {
        [layoutGuide.owningView removeLayoutGuide:layoutGuide];
        [priv->_layoutGuides addObject:layoutGuide];
        layoutGuide.owningView = self;
    }
}

/**
 @Status Interoperable
*/
- (void)removeLayoutGuide:(UILayoutGuide*)layoutGuide {
    if (layoutGuide == nil) {
        @throw [NSException exceptionWithName:NSInvalidArgumentException reason:@"Cannot remove nil UILayoutGuide!" userInfo:nil];
    }
    if (![priv->_layoutGuides containsObject:layoutGuide]) {
        @throw [NSException exceptionWithName:NSInvalidArgumentException reason:@"Cannot remove nil UILayoutGuide!" userInfo:nil];
    }
    layoutGuide.owningView = nil;
    [priv->_layoutGuides removeObject:layoutGuide];
}

/**
 @Status Interoperable
*/
- (CGRect)bounds {
    return [layer bounds];
}

/**
 @Status Interoperable
*/
- (CGPoint)center {
    return [layer position];
}

/**
 @Status Interoperable
*/
- (CGAffineTransform)transform {
    return [layer affineTransform];
}

/**
 @Status Interoperable
*/
- (CGRect)frame {
    return CGRectStandardize([layer frame]);
}

/**
 @Status Interoperable
*/
- (void)setCenter:(CGPoint)center {
    [layer setPosition:center];
}

/**
 @Status Interoperable
*/
- (void)layoutSublayersOfLayer:(CALayer*)forLayer {
    if (forLayer == layer) {
        UIViewController* controller = [UIViewController controllerForView:self];
        if (controller != nil) {
            [controller viewWillLayoutSubviews];
        }

        [self updateConstraintsIfNeeded];
        [self autoLayoutUpdateConstraints];
        [self layoutSubviews];
        [self __didLayout];

        if (controller != nil) {
            [controller viewDidLayoutSubviews];
        }
    }
}

/**
 @Status Caveat
 @Notes Questionable impl re: AutoLayout.
*/
- (void)layoutSubviews {
    if (priv->autoresizesSubviews) {
        [self autoLayoutLayoutSubviews];
    }
}

/**
 @Status Interoperable
*/
- (void)layoutIfNeeded {
    [layer layoutIfNeeded];
}

- (void)__didLayout {
}

/**
 @Status Interoperable
*/
- (void)setNeedsLayout {
    [layer setNeedsLayout];
}

- (void)_setShouldLayout {
    [layer _setShouldLayout];
}

/**
 @Status Interoperable
*/
- (CGRect)origin {
    CGRect curFrame;

    curFrame = [layer frame];

    return curFrame;
}

static void doResize(unsigned mask, float& pos, float& size, float parentSize, float delta) {
    switch (mask) {
        case 0:
            break;

        case UIViewAutoresizingFlexibleLeftMargin:
            pos += delta;
            break;

        case UIViewAutoresizingFlexibleWidth:
            size += delta;
            break;

        case (UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleWidth): {
            float totalSize = 0.0f;
            float newSize;

            totalSize += pos;
            totalSize += size;
            newSize = totalSize + delta;

            if (totalSize == 0.0f) {
                pos += size;
            } else {
                float newPos = pos * newSize / totalSize;
                size = ((pos + size) * newSize / totalSize) - newPos;
                pos = newPos;
            }
        } break;

        case UIViewAutoresizingFlexibleRightMargin:
            break;

        case (UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleRightMargin): {
            float totalSize = 0.0f;
            float newSize;

            totalSize += pos;
            totalSize += parentSize - (pos + size);
            newSize = totalSize + delta;

            if (totalSize == 0.0f) {
                pos = newSize / 2.0f;
            } else {
                pos = pos * newSize / totalSize;
            }
            break;
        }

        case (UIViewAutoresizingFlexibleRightMargin | UIViewAutoresizingFlexibleWidth): {
            float totalSize = 0.0f;
            float lastSize = parentSize - (pos + size);
            float newSize;

            totalSize += size;
            totalSize += lastSize;
            newSize = totalSize + delta;

            if (lastSize <= 0.0f || size == 0.0f) {
                size = parentSize + delta - pos;
            } else {
                float newPos = pos * newSize / totalSize;
                size = ((pos + size) * newSize / totalSize) - newPos;
            }
        } break;

        case (UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleRightMargin | UIViewAutoresizingFlexibleWidth): {
            float totalSize = 0.0f;
            float lastSize = parentSize - (pos + size);
            float newSize;

            totalSize += pos;
            totalSize += size;
            totalSize += lastSize;
            newSize = totalSize + delta;

            if (totalSize == 0.0f) {
                pos = (parentSize + delta) / 3.0f;
                size = (parentSize + delta) / 3.0f;
            } else {
                float newPos = pos * newSize / totalSize;
                size = ((pos + size) * newSize / totalSize) - newPos;
                pos = newPos;
            }
        } break;

        default:
            assert(0);
            break;
    }
}

static void adjustSubviews(UIView* self, CGSize parentSize, CGSize delta) {
    if (!self->priv)
        return;

    if (self->priv->autoresizesSubviews) {
        //  Go through each subview and resize it
        LLTREE_FOREACH(curSubview, self->priv) {
            UIView* subview = curSubview->self;

            UIViewAutoresizing mask = subview->priv->autoresizingMask;

            if (mask == UIViewAutoresizingNone || !subview->priv->translatesAutoresizingMaskIntoConstraints) {
                continue;
            }

            CGRect curFrame, origFrame;
            curFrame = [subview frame];
            origFrame = curFrame;

            curFrame.origin.x += subview->priv->_resizeRoundingError.origin.x;
            curFrame.origin.y += subview->priv->_resizeRoundingError.origin.y;
            curFrame.size.width += subview->priv->_resizeRoundingError.size.width;
            curFrame.size.height += subview->priv->_resizeRoundingError.size.height;

            doResize(mask & 7, curFrame.origin.x, curFrame.size.width, parentSize.width, delta.width);
            doResize((mask >> 3) & 7, curFrame.origin.y, curFrame.size.height, parentSize.height, delta.height);

            if (curFrame.size.width < 0.0f)
                curFrame.size.width = 0.0f;
            if (curFrame.size.height < 0.0f)
                curFrame.size.height = 0.0f;

            CGRect beforeRound = curFrame;
            curFrame.origin.x = floorf(curFrame.origin.x);
            curFrame.origin.y = floorf(curFrame.origin.y);
            curFrame.size.width = floorf(curFrame.size.width);
            curFrame.size.height = floorf(curFrame.size.height);

            if (memcmp(&curFrame, &origFrame, sizeof(CGRect)) != 0) {
                subview->priv->_resizeRoundingError.origin.x = beforeRound.origin.x - curFrame.origin.x;
                subview->priv->_resizeRoundingError.origin.y = beforeRound.origin.y - curFrame.origin.y;
                subview->priv->_resizeRoundingError.size.width = beforeRound.size.width - curFrame.size.width;
                subview->priv->_resizeRoundingError.size.height = beforeRound.size.height - curFrame.size.height;

                if (DEBUG_LAYOUT) {
                    TraceVerbose(TAG,
                                 L"Resizing %hs(0x%08x) (%f, %f, %f, %f) -> (%f, %f, %f, %f)",
                                 object_getClassName(subview),
                                 subview,
                                 origFrame.origin.x,
                                 origFrame.origin.y,
                                 origFrame.size.width,
                                 origFrame.size.height,
                                 curFrame.origin.x,
                                 curFrame.origin.y,
                                 curFrame.size.width,
                                 curFrame.size.height);
                }
                [subview setFrame:curFrame];
            } else {
                subview->priv->_resizeRoundingError.origin.x = beforeRound.origin.x - origFrame.origin.x;
                subview->priv->_resizeRoundingError.origin.y = beforeRound.origin.y - origFrame.origin.y;
                subview->priv->_resizeRoundingError.size.width = beforeRound.size.width - origFrame.size.width;
                subview->priv->_resizeRoundingError.size.height = beforeRound.size.height - origFrame.size.height;
            }
        }
    }

    return;
}

static float doRound(float f) {
    return (float)(floor((f * 2) + 0.5) / 2.0f);
}

/**
 @Status Interoperable
*/
- (void)setFrame:(CGRect)frame {
    if (memcmp(&frame, &CGRectNull, sizeof(CGRect)) == 0) {
        TraceWarning(TAG, L"setFrame: CGRectNull!");
        return;
    }

    // Keep our hit test state up to date
    [self _updateHitTestability];

    //  Get our existing frame
    CGRect curFrame;
    curFrame = [self frame];

    if (memcmp(&frame, &curFrame, sizeof(CGRect)) == 0) {
        return;
    }

    frame.origin.x = doRound(frame.origin.x);
    frame.origin.y = doRound(frame.origin.y);
    frame.size.width = doRound(frame.size.width);
    frame.size.height = doRound(frame.size.height);

    if (DEBUG_LAYOUT) {
        TraceVerbose(TAG,
                     L"SetFrame %hs(0x%08x): %f, %f, %f, %f",
                     object_getClassName(self),
                     self,
                     frame.origin.x,
                     frame.origin.y,
                     frame.size.width,
                     frame.size.height);
    }

    CGRect startFrame = frame;

    if (frame.origin.x == doRound(curFrame.origin.x) && frame.origin.y == doRound(curFrame.origin.y) &&
        frame.size.width == doRound(curFrame.size.width) && frame.size.height == doRound(curFrame.size.height)) {
        return;
    }

    //  Get transformed bounding box
    CGAffineTransform curTransform, translate, invTranslate;
    curTransform = [layer affineTransform];

    CGPoint anchorPoint;
    CGPoint position;

    anchorPoint = [layer anchorPoint];

    position.x = frame.origin.x + frame.size.width * anchorPoint.x;
    position.y = frame.origin.y + frame.size.height * anchorPoint.y;

    //  Get transformed bounding box
    translate = CGAffineTransformMakeTranslation(-position.x, -position.y);
    translate = CGAffineTransformConcat(translate, curTransform);
    invTranslate = CGAffineTransformMakeTranslation(position.x, position.y);
    translate = CGAffineTransformConcat(translate, invTranslate);

    translate = CGAffineTransformInvert(translate);
    frame = CGRectApplyAffineTransform(frame, translate);

    CGSize outSize;
    outSize.width = frame.size.width;
    outSize.height = frame.size.height;

    position.x = frame.origin.x + frame.size.width * anchorPoint.x;
    position.y = frame.origin.y + frame.size.height * anchorPoint.y;

    CGRect curBounds;
    curBounds = [layer bounds];

    CGSize delta;
    delta.width = outSize.width - curBounds.size.width;
    delta.height = outSize.height - curBounds.size.height;
    if (delta.width != 0.0f || delta.height != 0.0f) {
        adjustSubviews(self, curBounds.size, delta);
    }

    [layer setPosition:position];

    curBounds.size = outSize;

    [layer setBounds:curBounds];

    // Baseline UIViews don't share a superview with the view it's constraining.
    // They must also be a direct relationship to its superview.
    for (UIView* child in [self subviews]) {
        [child autoLayoutUpdateConstraints];
    }

    [self autoLayoutUpdateConstraints];

    self.accessibilityFrame = self.frame;
}

/**
 @Status Interoperable
*/
- (void)setBounds:(CGRect)bounds {
    //  Get our existing bounds
    CGRect curBounds;
    curBounds = [self bounds];

    if (DEBUG_LAYOUT) {
        TraceVerbose(TAG,
                     L"Resizing %hs(0x%08x) (%f, %f, %f, %f)",
                     object_getClassName(self),
                     self,
                     curBounds.origin.x,
                     curBounds.origin.y,
                     curBounds.size.width,
                     curBounds.size.height);
    }

    CGSize delta;
    delta.width = bounds.size.width - curBounds.size.width;
    delta.height = bounds.size.height - curBounds.size.height;
    if (delta.width != 0.0f || delta.height != 0.0f) {
        adjustSubviews(self, curBounds.size, delta);
    }

    [layer setBounds:bounds];
}

/**
 @Status Interoperable
*/
- (void)setOrigin:(CGPoint)origin {
    CGRect curFrame;

    curFrame = [layer frame];
    curFrame.origin = origin;

    [layer setFrame:curFrame];
}

- (void)_setBoundsOrigin:(CGPoint)origin {
    [layer setOrigin:origin];
}

/**
 @Status Interoperable
*/
- (NSArray*)subviews {
    return priv->subnodesArray();
}

- (void)_notifyWillMoveToWindow:(UIWindow*)window superview:(UIView*)superview {
    UIViewController* controller = [UIViewController controllerForView:self];

    if (controller != nil && window != nil) {
        UIViewController* rootController = [[[[UIApplication sharedApplication] windows] objectAtIndex:0] rootViewController];
        if (rootController == nil) {
            [[[[UIApplication sharedApplication] windows] objectAtIndex:0] _setRootViewController:controller];
            rootController = controller;
        }

        UIViewController* parentController = [UIViewController controllerForView:superview];
        if (rootController == controller || g_alwaysSendViewEvents)
            [controller _notifyViewWillAppear:g_presentingAnimated]; /*** should we do this? ****/
    }
    if (controller != nil && window == nil) {
        UIViewController* rootController = [[[[UIApplication sharedApplication] windows] objectAtIndex:0] rootViewController];
        UIViewController* parentController = [UIViewController controllerForView:superview];
        if (rootController == controller || g_alwaysSendViewEvents)
            [controller _notifyViewWillDisappear:g_presentingAnimated]; /*** should we do this? ****/
    }

    if (window == nil) {
        for (UIGestureRecognizer* curgesture in priv->gestures) {
            if ([curgesture respondsToSelector:@selector(_cancelIfActive)]) {
                [curgesture _cancelIfActive];
            }
        }
    }

    [self willMoveToWindow:window];

    LLTREE_FOREACH(curView, priv) {
        [curView->self _notifyWillMoveToWindow:window superview:superview];
    }
}

/**
 @Status Interoperable
*/
- (void)willMoveToSuperview:(UIView*)view {
}

- (void)_notifyDidMoveToWindow:(UIWindow*)window superview:(UIView*)superview {
    LLTREE_FOREACH(curView, priv) {
        [curView->self _notifyDidMoveToWindow:window superview:superview];
    }

    UIViewController* controller = [UIViewController controllerForView:self];

    if (controller != nil && window != nil) {
        UIViewController* rootController = [[[[UIApplication sharedApplication] windows] objectAtIndex:0] rootViewController];
        UIViewController* parentController = [UIViewController controllerForView:superview];
        if (rootController == controller || [controller parentViewController] != nil ||
            [controller isKindOfClass:[UINavigationController class]] || [parentController isKindOfClass:[UINavigationController class]] ||
            g_alwaysSendViewEvents) {
            if (stackLevel == 0) {
                [controller _notifyViewWillAppear:FALSE];
                [controller _notifyViewDidAppear:FALSE];
            }
        }
    }
    if (controller != nil && window == nil) {
        UIViewController* rootController = [[[[UIApplication sharedApplication] windows] objectAtIndex:0] rootViewController];
        if (rootController == controller) {
            [[[[UIApplication sharedApplication] windows] objectAtIndex:0] _setRootViewController:nil];
        }

        UIViewController* parentController = [UIViewController controllerForView:superview];
        if (rootController == controller || [controller parentViewController] != nil ||
            [controller isKindOfClass:[UINavigationController class]] || [parentController isKindOfClass:[UINavigationController class]] ||
            g_alwaysSendViewEvents)
            [controller _notifyViewDidDisappear:FALSE];
    }

    if (window == nil) {
        /* Optimization: release contents when not part of the view heirarchy */
        [layer _releaseContents:FALSE];
    }
    [self didMoveToWindow];
}

/**
 @Status Interoperable
*/
- (void)removeFromSuperview {
    if (priv->_isChangingParent) {
        assert(0);
    }
    if (priv->superview != nil) {
        [self retain];
        priv->_isChangingParent = true;

        UIWindow* curWindow = [self _getWindowInternal];
        UIView* curSuperview = priv->superview;

        //  Notify our superview that we will be removed
        if ([priv->superview respondsToSelector:@selector(willRemoveSubview:)]) {
            [priv->superview willRemoveSubview:self];
        }
        if ([self respondsToSelector:@selector(willMoveToSuperview:)]) {
            [self willMoveToSuperview:nil];
        }
        if (curWindow != nil) {
            [self _notifyWillMoveToWindow:nil superview:curSuperview];
        }

        UIView* superview = priv->superview;
        UIView* pSuper = curSuperview;
        if (superview != curSuperview) {
            TraceWarning(TAG, L"Warning: superview changed!");
        }

        pSuper->priv->removeChild(priv);
        priv->superview = nil;
        [layer removeFromSuperlayer];

        priv->_isChangingParent = false;
        [self didMoveToSuperview];

        if (curWindow != nil) {
            [self _notifyDidMoveToWindow:nil superview:curSuperview];
        }

        [self release];
        [self autorelease];
    }
}

- (void)_removeFromSuperviewNoNotify {
    if (priv->superview != nil) {
        [self retain];

        UIWindow* curWindow = [self _getWindowInternal];
        UIView* curSuperview = priv->superview;

        UIView* superview = priv->superview;
        UIView* pSuper = superview;

        pSuper->priv->removeChild(priv);
        priv->superview = nil;
        [self release];
        [layer removeFromSuperlayer];

        [self autorelease];
    }
}

/**
 @Status Interoperable
*/
- (void)addSubview:(UIView*)subview {
    if (subview == nil) {
        TraceWarning(TAG, L"subview = nil!");
        return;
    }
    if (subview == self) {
        TraceWarning(TAG, L"subview = self?!");
        return;
    }
    if (((UIView*)subview)->priv->_isChangingParent) {
        assert(0);
    }

    if (DEBUG_LAYOUT) {
        TraceVerbose(TAG,
                     L"Adding subview %hs(0x%08x) to %hs(0x%08x)",
                     object_getClassName(subview),
                     subview,
                     object_getClassName(self),
                     self);
    }

    UIWindow* subviewWindow = [subview _getWindowInternal];
    UIWindow* curWindow = [self _getWindowInternal];

    if ([subview superview] != self) {
        //  Notify the subview it's about to be moved
        if (subviewWindow != curWindow) {
            [subview _notifyWillMoveToWindow:curWindow superview:self];
        }
        if ([subview respondsToSelector:@selector(willMoveToSuperview:)]) {
            [subview willMoveToSuperview:self];
        }

        //  Remove the view from its superview
        [subview _removeFromSuperviewNoNotify];

        //  Add it to our views
        priv->addChildAfter(subview, nil);
        [subview retain];
        ((UIView*)subview)->priv->superview = self;

        //  Add its layer to our layers
        CALayer* subviewLayer = [subview layer];
        [layer addSublayer:subviewLayer];

        //  Notify the subview it's about to be moved
        if (subviewWindow != curWindow) {
            [subview _notifyDidMoveToWindow:curWindow superview:self];
        }
        [subview didMoveToSuperview];
        [UIAppearanceSetter _applyAppearance:subview];

        //  Notify our view it was added
        if ([self respondsToSelector:@selector(didAddSubview:)]) {
            [self didAddSubview:subview];
        }

        [self setNeedsUpdateConstraints];

        [subview setNeedsDisplay];
    } else {
        //  Just bring it to the front
        [self bringSubviewToFront:subview];
    }
}

/**
 @Status Interoperable
*/
- (void)insertSubview:(UIView*)subview atIndex:(int)index {
    UIWindow* subviewWindow = [subview _getWindowInternal];
    UIWindow* curWindow = [self _getWindowInternal];

    [subview retain];

    //  Notify the subview it's about to be moved
    if ([subview respondsToSelector:@selector(willMoveToSuperview:)]) {
        [subview willMoveToSuperview:self];
    }
    if (subviewWindow != curWindow) {
        [subview _notifyWillMoveToWindow:curWindow superview:self];
    }

    //  Remove the view from its superview
    [subview _removeFromSuperviewNoNotify];

    //  Add it to our views
    if (priv->childCount < index) {
        index = priv->childCount;
        TraceWarning(TAG, L"Warning: Tried to insert subview at bad index");
    }
    priv->insertChildAtIndex(subview, index);
    [subview retain];
    ((UIView*)subview)->priv->superview = self;

    //  Add its layer to our layers
    CALayer* subviewLayer = [subview layer];
    [layer insertSublayer:subviewLayer atIndex:index];

    //  Notify the subview it's about to be moved
    [subview didMoveToSuperview];
    [UIAppearanceSetter _applyAppearance:subview];

    if (subviewWindow != curWindow) {
        [subview _notifyDidMoveToWindow:curWindow superview:self];
    }

    //  Notify our view it was added
    if ([self respondsToSelector:@selector(didAddSubview:)]) {
        [self didAddSubview:subview];
    }

    [subview setNeedsDisplay];
    [subview release];
}

/**
 @Status Interoperable
*/
- (void)insertSubview:(UIView*)subview belowSubview:(UIView*)belowSubview {
    if (subview == nil) {
        TraceWarning(TAG, L"Subview = nil!");
        return;
    }

    if (belowSubview == nil) {
        TraceWarning(TAG, L"belowSubview = nil!");
        return;
    }

    UIWindow* subviewWindow = [subview _getWindowInternal];
    UIWindow* curWindow = [self _getWindowInternal];

    [subview retain];

    //  Notify the subview it's about to be moved
    if ([subview respondsToSelector:@selector(willMoveToSuperview:)]) {
        [subview willMoveToSuperview:self];
    }
    if (subviewWindow != curWindow) {
        [subview _notifyWillMoveToWindow:curWindow superview:self];
    }

    //  Remove the view from its superview
    [subview _removeFromSuperviewNoNotify];

    int index;

    if (priv->containsChild(belowSubview)) {
        index = priv->indexOfChild(belowSubview);
    } else {
        // If the below subview doesn't exist, default is to put it on top.
        // This includes if the subview is the same as belowSubview and was removed.
        index = priv->childCount;
    }

    //  Add it to our views
    priv->insertChildAtIndex(subview, index);
    [subview retain];
    ((UIView*)subview)->priv->superview = self;

    //  Add its layet to our layers
    CALayer* subviewLayer = [subview layer];
    [layer insertSublayer:subviewLayer atIndex:index];

    //  Notify the subview it's about to be moved
    [subview didMoveToSuperview];
    [UIAppearanceSetter _applyAppearance:subview];

    if (subviewWindow != curWindow) {
        [subview _notifyDidMoveToWindow:curWindow superview:self];
    }

    //  Notify our view it was added
    if ([self respondsToSelector:@selector(didAddSubview:)]) {
        [self didAddSubview:subview];
    }

    [subview setNeedsDisplay];
    [subview release];
}

/**
 @Status Interoperable
*/
- (void)exchangeSubviewAtIndex:(int)index1 withSubviewAtIndex:(int)index2 {
    UIView* view1 = nil;
    UIView* view2 = nil;

    if (index1 >= 0 && index1 < priv->childCount) {
        view1 = priv->childAtIndex(index1)->self;
    }
    if (index2 >= 0 && index2 < priv->childCount) {
        view2 = priv->childAtIndex(index2)->self;
    }
    if (view1 == nil || view2 == nil) {
        TraceWarning(TAG,
                     L"Cannot exchange subviews %d and %d count=%d on view %hs (view1=%hs view2=%hs)",
                     index1,
                     index2,
                     priv->childCount,
                     object_getClassName(self),
                     view1 ? object_getClassName(view1) : "nil",
                     view2 ? object_getClassName(view2) : "nil");
        return;
    }

    assert(view1 != nil && view2 != nil);
    priv->exchangeChild(view1, view2);

    CALayer* layer1 = [view1 layer];
    CALayer* layer2 = [view2 layer];

    [layer exchangeSublayer:layer1 withLayer:layer2];
}

/**
 @Status Interoperable
*/
- (void)insertSubview:(UIView*)subview aboveSubview:(UIView*)aboveSubview {
    if (subview == nil) {
        TraceWarning(TAG, L"insertSubview: subview = nil!");
        return;
    }

    if (aboveSubview == nil) {
        TraceWarning(TAG, L"aboveSubview = nil!");
        return;
    }

    UIWindow* subviewWindow = [subview _getWindowInternal];
    UIWindow* curWindow = [self _getWindowInternal];

    [subview retain];

    //  Notify the subview it's about to be moved
    if ([subview respondsToSelector:@selector(willMoveToSuperview:)]) {
        [subview willMoveToSuperview:self];
    }
    if (subviewWindow != curWindow) {
        [subview _notifyWillMoveToWindow:curWindow superview:self];
    }

    //  Remove the view from its superview
    [subview _removeFromSuperviewNoNotify];

    int index;

    if (priv->containsChild(aboveSubview)) {
        // Put on top.
        index = priv->indexOfChild(aboveSubview) + 1;
    } else {
        // If the below subview doesn't exist, default is to put it on top.
        // This includes if the subview is the same as belowSubview and was removed.
        index = priv->childCount;
    }

    //  Add it to our views
    priv->insertChildAtIndex(subview, index);
    [subview retain];
    ((UIView*)subview)->priv->superview = self;

    //  Add its layet to our layers
    CALayer* subviewLayer = [subview layer];
    [layer insertSublayer:subviewLayer atIndex:index];

    //  Notify the subview it's about to be moved
    [subview didMoveToSuperview];
    [UIAppearanceSetter _applyAppearance:subview];

    if (subviewWindow != curWindow) {
        [subview _notifyDidMoveToWindow:curWindow superview:self];
    }

    //  Notify our view it was added
    if ([self respondsToSelector:@selector(didAddSubview:)]) {
        [self didAddSubview:subview];
    }

    [subview setNeedsDisplay];
    [subview release];
}

/**
 @Status Interoperable
*/
- (void)bringSubviewToFront:(UIView*)subview {
    if (!priv->containsChild(subview))
        return;

    priv->removeChild(subview);
    priv->addChildAfter(subview, nil);

    [layer bringSublayerToFront:[subview layer]];
}

/**
 @Status Interoperable
*/
- (void)sendSubviewToBack:(UIView*)subview {
    if (!priv->containsChild(subview))
        return;

    priv->removeChild(subview);
    priv->addChildBefore(subview, nil);

    [layer sendSublayerToBack:[subview layer]];
}

- (void)setContentView:(UIView*)view {
    [self addSubview:view];
}

/**
 @Status Interoperable
*/
- (void)setContentScaleFactor:(float)factor {
    [layer setContentsScale:factor];
}

/**
 @Status Interoperable
*/
- (float)contentScaleFactor {
    return [layer contentsScale];
}

/**
 @Status Stub
*/
- (void)orderFront:(UIView*)view {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)makeKey:(UIView*)view {
    TraceWarning(TAG, L"UIVIew::makeKey");
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (void)setHidden:(BOOL)hide {
    // Update internal layer state
    [layer setHidden:hide];

    if (DEBUG_HIT_TESTING) {
        TraceVerbose(TAG, L"Setting %hs(0x%08x) to hidden=%hs.", object_getClassName(self), self, hide ? "true" : "false");
    }

    // Keep our hit test state up to date
    [self _updateHitTestability];
}

/**
 @Status Interoperable
*/
- (BOOL)isHidden {
    return [layer isHidden];
}

/**
 @Status Interoperable
*/
- (UIView*)superview {
    return priv->superview;
}

/**
 @Status Interoperable
*/
- (BOOL)pointInside:(CGPoint)point withEvent:(UIEvent*)event {
    //  CGPoint is in our coordinate system
    CGRect bounds = [layer bounds];
    return CGRectContainsPoint(bounds, point);
}

/**
 @Status Interoperable
*/
- (UIView*)hitTest:(CGPoint)point withEvent:(UIEvent*)event {
    UIWindow* window = [self _getWindowInternal];

    if ([self isHidden]) {
        if (DEBUG_HIT_TESTING) {
            TraceVerbose(TAG, L"hitTest ignoring hidden view %hs(0x%08x)", object_getClassName(self), self);
        }
        return nil;
    }

    if (![self isUserInteractionEnabled]) {
        if (DEBUG_HIT_TESTING) {
            TraceVerbose(TAG, L"hitTest ignoring disabled view %hs(0x%08x)", object_getClassName(self), self);
        }
        return nil;
    }

    if ([self alpha] <= 0.01f) {
        if (DEBUG_HIT_TESTING) {
            TraceVerbose(TAG, L"hitTest ignoring alpha view %hs(0x%08x)", object_getClassName(self), self);
        }
        return nil;
    }

    if (![self pointInside:point withEvent:event]) {
        if (DEBUG_HIT_TESTING) {
            TraceVerbose(TAG, L"hitTest rejected; outside of view %hs(0x%08x)", object_getClassName(self), self);
        }
        return nil;
    }

    if (DEBUG_HIT_TESTING) {
        TraceVerbose(TAG, L"HitTest inside %hs(0x%08x)", object_getClassName(self), self);
    }

    //  Go through subviews backwards until we find the furthest descendant
    int subviewCount = 0;
    UIView** subviewsCopy = (UIView**)alloca(sizeof(UIView*) * priv->childCount);
    LLTREE_FOREACH(curSubview, priv) {
        subviewsCopy[subviewCount++] = curSubview->self;
    }

    int i;
    for (i = subviewCount - 1; i >= 0; i--) {
        UIView* view = subviewsCopy[i];

        if ([view isHidden]) {
            if (DEBUG_HIT_TESTING) {
                TraceVerbose(TAG, L"hitTest skipping hidden subview %hs(0x%08x)", object_getClassName(view), view);
            }
            continue;
        }

        if (![view isUserInteractionEnabled]) {
            if (DEBUG_HIT_TESTING) {
                TraceVerbose(TAG, L"hitTest skipping disabled subview %hs(0x%08x)", object_getClassName(view), view);
            }
            continue;
        }

        if ([view alpha] <= 0.01f) {
            if (DEBUG_HIT_TESTING) {
                TraceVerbose(TAG, L"hitTest skipping alpha subview %hs(0x%08x)", object_getClassName(view), view);
            }
            continue;
        }

        CGPoint newPoint = [window convertPoint:point fromView:self toView:view];
        if ([view pointInside:newPoint withEvent:event]) {
            if (DEBUG_HIT_TESTING) {
                TraceVerbose(TAG, L"Point (%f, %f) was inside %hs(0x%08x).", newPoint.x, newPoint.y, object_getClassName(view), view);
            }

            // The point was inside, so hit test this view
            UIView* ret = [view hitTest:newPoint withEvent:event];
            if (ret != nil) {
                if (DEBUG_HIT_TESTING_LIGHT) {
                    TraceVerbose(TAG,
                                 L"Found the hit test view %hs(0x%08x) within view: %hs(0x%08x).",
                                 object_getClassName(ret),
                                 ret,
                                 object_getClassName(view),
                                 view);
                }
                return ret;
            }
        } else if (DEBUG_HIT_TESTING) {
            TraceVerbose(TAG, L"Point (%f, %f) was NOT inside %hs(0x%08x).", newPoint.x, newPoint.y, object_getClassName(view), view);
        }
    }

    return self;
}

/**
 @Status Interoperable
*/
- (CGRect)convertRect:(CGRect)pos toView:(UIView*)toView {
    CGRect ret;

    UIWindow* ourWindow = [self _getWindowInternal];

    if (ourWindow == nil) {
        ret.origin.x = pos.origin.x;
        ret.origin.y = pos.origin.y;
        ret.size = pos.size;
        return ret;
    }

    if (toView == nil)
        toView = ourWindow;

    CGPoint pt1 = pos.origin;
    CGPoint pt2;

    pt2 = pos.origin;
    pt2.x += pos.size.width;
    pt2.y += pos.size.height;

    pt1 = [ourWindow convertPoint:pt1 fromView:self toView:toView];
    pt2 = [ourWindow convertPoint:pt2 fromView:self toView:toView];

    ret.origin.x = pt1.x < pt2.x ? pt1.x : pt2.x;
    ret.origin.y = pt1.y < pt2.y ? pt1.y : pt2.y;
    ret.size.width = fabsf(pt1.x - pt2.x);
    ret.size.height = fabsf(pt1.y - pt2.y);

    return ret;
}

/**
 @Status Interoperable
*/
- (CGRect)convertRect:(CGRect)pos fromView:(UIView*)fromView {
    CGRect ret;

    UIWindow* ourWindow = [self _getWindowInternal];

    if (ourWindow == nil) {
        ret.origin.x = pos.origin.x;
        ret.origin.y = pos.origin.y;
        ret.size = pos.size;
        return ret;
    }

    if (fromView == nil)
        fromView = ourWindow;

    CGPoint pt1 = pos.origin;
    CGPoint pt2;

    pt2 = pos.origin;
    pt2.x += pos.size.width;
    pt2.y += pos.size.height;

    pt1 = [ourWindow convertPoint:pt1 fromView:fromView toView:self];
    pt2 = [ourWindow convertPoint:pt2 fromView:fromView toView:self];

    ret.origin.x = pt1.x < pt2.x ? pt1.x : pt2.x;
    ret.origin.y = pt1.y < pt2.y ? pt1.y : pt2.y;
    ret.size.width = fabsf(pt1.x - pt2.x);
    ret.size.height = fabsf(pt1.y - pt2.y);

    return ret;
}

/**
 @Status Interoperable
*/
- (CGPoint)convertPoint:(CGPoint)pos toView:(UIView*)toView {
    CGPoint ret;

    UIWindow* ourWindow = [self _getWindowInternal];
    if (ourWindow == nil) {
        return pos;
    }

    if (toView == nil)
        toView = ourWindow;

    ret = [ourWindow convertPoint:pos fromView:self toView:toView];

    return ret;
}

/**
 @Status Interoperable
*/
- (CGPoint)convertPoint:(CGPoint)pos fromView:(UIView*)fromView {
    CGPoint ret;

    UIWindow* ourWindow = [self _getWindowInternal];
    if (ourWindow == nil) {
        return pos;
    }

    if (fromView == nil)
        fromView = ourWindow;

    ret = [ourWindow convertPoint:pos fromView:fromView toView:self];

    return ret;
}

/**
 @Status Interoperable
*/
- (void)drawLayer:(CALayer*)layer inContext:(CGContextRef)context {
    UIGraphicsPushContext(context);

    CGRect bounds;
    bounds = CGContextGetClipBoundingBox(context);
    [self drawRect:bounds];

    UIGraphicsPopContext();
}

/**
 @Status Interoperable
*/
- (CALayer*)layer {
    return layer;
}

/**
 @Status Interoperable
*/
- (void)setNeedsDisplay {
    [layer setNeedsDisplay];
}

/**
 @Status Caveat
 @Notes Same impl as setNeedsDisplay. With our compositor this might not even have meaning.
*/
- (void)setNeedsDisplayInRect:(CGRect)rc {
    [layer setNeedsDisplay];
}

/**
 @Status Interoperable
*/
- (UIWindow*)window {
    return [self _getWindowInternal];
}

- (UIWindow*)_getWindowInternal {
    if (!priv) {
        TraceWarning(TAG, L"priv = NULL!");
        return nil;
    }

    if (!priv->superview) {
        return nil;
    }

    return [priv->superview _getWindowInternal];
}

/**
 @Status Interoperable
*/
- (void)setMultipleTouchEnabled:(BOOL)enabled {
    if (!priv) {
        TraceWarning(TAG, L"Priv is null, should alloc priv in alloc");
        return;
    }

    priv->multipleTouchEnabled = enabled;
}

/**
 @Status Interoperable
*/
+ (Class)layerClass {
    return [CALayer class];
}

/**
 @Status Interoperable
*/
- (void)setAlpha:(float)alpha {
    // Update our layer state
    [layer setOpacity:alpha];

    if (DEBUG_HIT_TESTING) {
        TraceVerbose(TAG, L"Setting %hs(0x%08x) to alpha=%f.", object_getClassName(self), self, alpha);
    }

    // Keep our hit test state up to date
    [self _updateHitTestability];
}

/**
 @Status Interoperable
*/
- (float)alpha {
    return [layer opacity];
}

/**
 @Status Interoperable
*/
- (void)setTransform:(CGAffineTransform)transform {
    [layer setAffineTransform:transform];
}

/**
 @Status Stub
*/
- (void)setRotationBy:(float)degrees {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setClearsContextBeforeDrawing:(BOOL)clear {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (void)setBackgroundColor:(UIColor*)color {
    priv->backgroundColor = color;
    [layer setBackgroundColor:[color CGColor]];
}

/**
 @Status Interoperable
*/
- (UIColor*)backgroundColor {
    return priv->backgroundColor;
}

/**
 @Status Interoperable
*/
- (void)setUserInteractionEnabled:(BOOL)enabled {
    // Toggle internal state
    priv->userInteractionEnabled = enabled;

    if (DEBUG_HIT_TESTING) {
        TraceVerbose(TAG,
                     L"Setting %hs(0x%08x) to userInteractionEnabled=%hs.",
                     object_getClassName(self),
                     self,
                     enabled ? "true" : "false");
    }

    // Keep our hit test state up to date
    [self _updateHitTestability];
}

/**
 @Status Interoperable
*/
- (void)setTag:(int)newTag {
    priv->tag = newTag;
}

/**
 @Status Interoperable
*/
- (int)tag {
    return priv->tag;
}

/**
 @Status Interoperable
*/
- (BOOL)isUserInteractionEnabled {
    return priv->userInteractionEnabled;
}

/**
 @Status Interoperable
*/
- (BOOL)isMultipleTouchEnabled {
    return priv->multipleTouchEnabled;
}

/**
 @Status Interoperable
*/
- (UIViewContentMode)contentMode {
    return priv->contentMode;
}

/**
 @Status Interoperable
*/
- (void)setContentMode:(UIViewContentMode)mode {
    priv->contentMode = mode;

    //  Top/bottom switched due to geometric origin of CALayer

    switch (mode) {
        case UIViewContentModeScaleToFill:
            [layer setContentsGravity:kCAGravityResize];
            break;

        case UIViewContentModeCenter:
            [layer setContentsGravity:kCAGravityCenter];
            break;

        case UIViewContentModeTop:
            [layer setContentsGravity:kCAGravityBottom];
            break;

        case UIViewContentModeScaleAspectFit:
            [layer setContentsGravity:kCAGravityResizeAspect];
            break;

        case UIViewContentModeTopLeft:
            [layer setContentsGravity:kCAGravityBottomLeft];
            break;

        case UIViewContentModeTopRight:
            [layer setContentsGravity:kCAGravityBottomRight];
            break;

        case UIViewContentModeBottomLeft:
            [layer setContentsGravity:kCAGravityTopLeft];
            break;

        case UIViewContentModeLeft:
            [layer setContentsGravity:kCAGravityLeft];
            break;

        case UIViewContentModeScaleAspectFill:
            [layer setContentsGravity:kCAGravityResizeAspectFill];
            break;

        case UIViewContentModeBottom:
            [layer setContentsGravity:kCAGravityTop];
            break;

        case UIViewContentModeBottomRight:
            [layer setContentsGravity:kCAGravityTopRight];
            break;

        case UIViewContentModeRight:
            [layer setContentsGravity:kCAGravityRight];
            break;

        case UIViewContentModeRedraw:
            [layer setNeedsDisplayOnBoundsChange:TRUE];
            break;

        default:
            assert(0);
    }
}

/**
 @Status Interoperable
*/
- (void)setContentStretch:(CGRect)stretch {
    [layer setContentsCenter:stretch];
}

/**
 @Status Interoperable
*/
- (void)setOpaque:(BOOL)opaque {
    [layer setOpaque:opaque];
}

/**
 @Status Interoperable
*/
- (BOOL)isOpaque {
    return [layer isOpaque];
}

/**
 @Status Interoperable
*/
- (void)setAutoresizingMask:(UIViewAutoresizing)mask {
    if (mask != priv->autoresizingMask) {
        if (mask >= (UIViewAutoresizingFlexibleBottomMargin << 1)) {
            @throw [NSException exceptionWithName:NSInvalidArgumentException reason:@"Argument 'mask' out of range!" userInfo:nil];
        }
        priv->autoresizingMask = mask;
        [self setNeedsUpdateConstraints];
    }
}

/**
 @Status Interoperable
*/
- (UIViewAutoresizing)autoresizingMask {
    return priv->autoresizingMask;
}

/**
 @Status Interoperable
*/
- (void)setAutoresizesSubviews:(BOOL)autoresize {
    if (autoresize != priv->autoresizesSubviews) {
        priv->autoresizesSubviews = autoresize;
        [self setNeedsUpdateConstraints];
    }
}

/**
 @Status Interoperable
*/
- (BOOL)translatesAutoresizingMaskIntoConstraints {
    return self->priv->translatesAutoresizingMaskIntoConstraints;
}

/**
 @Status Interoperable
*/
- (void)setTranslatesAutoresizingMaskIntoConstraints:(BOOL)translate {
    if (translate != self->priv->translatesAutoresizingMaskIntoConstraints) {
        self->priv->translatesAutoresizingMaskIntoConstraints = translate;
        [self setNeedsUpdateConstraints];
    }
}

/**
 @Status Interoperable
*/
- (NSArray*)constraints {
    return priv->constraints;
}

/**
 @Status Interoperable
*/
- (void)addConstraint:(NSLayoutConstraint*)constraint {
    UIView* firstItemOwner = [constraint.firstItem isKindOfClass:[UIView class]] ? [(UIView*)constraint.firstItem superview] :
                                                                                   [(UILayoutGuide*)constraint.firstItem owningView];
    UIView* secondItemOwner = [constraint.secondItem isKindOfClass:[UIView class]] ? [(UIView*)constraint.secondItem superview] :
                                                                                     [(UILayoutGuide*)constraint.secondItem owningView];

    // Constraints can only be added if they are self or a child of this view.
    if (((constraint.firstItem != self) && (firstItemOwner != self)) ||
        (constraint.secondItem && ((constraint.secondItem != self) && (secondItemOwner != self)))) {
        TraceWarning(TAG,
                     L"Only constraints with relations to this view and its children may be added. "
                     "This error may occur if your view hierarchy has not yet been initialized.");
        return;
    }

    if ([priv->constraints containsObject:constraint]) {
        return;
    }

    [priv->constraints addObject:constraint];

    [constraint _setView:self];
    [constraint autoLayoutConstraintAddedToView:self];

    // This might not be entirely correct, but one of the items might be using autosizing masks, so we have to poke at them.
    if ([constraint.firstItem respondsToSelector:@selector(setNeedsUpdateConstraints)]) {
        [constraint.firstItem setNeedsUpdateConstraints];
    }
    if ([constraint.secondItem respondsToSelector:@selector(setNeedsUpdateConstraints)]) {
        [constraint.secondItem setNeedsUpdateConstraints];
    }
    // setNeedsUpdateConstraints also sets needsLayout, but we migth be constraining between UILayoutGuides.
    [self setNeedsLayout];
}

/**
 @Status Interoperable
*/
- (void)removeConstraint:(NSLayoutConstraint*)constraint {
    [[constraint retain] autorelease];

    [constraint _setView:nil];

    [priv->constraints removeObject:constraint];

    [constraint autoLayoutConstraintRemovedFromView];

    if ([constraint.firstItem respondsToSelector:@selector(setNeedsUpdateConstraints)]) {
        [constraint.firstItem setNeedsUpdateConstraints];
    }
    if ([constraint.firstItem respondsToSelector:@selector(setNeedsUpdateConstraints)]) {
        [constraint.secondItem setNeedsUpdateConstraints];
    }
}

/**
 @Status Interoperable
*/
- (void)addConstraints:(NSArray*)constraints {
    for (int i = 0; i < [constraints count]; i++) {
        [self addConstraint:(NSLayoutConstraint*)[constraints objectAtIndex:i]];
    }
}

/**
 @Status Interoperable
*/
- (void)removeConstraints:(NSArray*)constraints {
    for (int i = 0; i < [constraints count]; i++) {
        [self removeConstraint:(NSLayoutConstraint*)[constraints objectAtIndex:i]];
    }
}

- (void)_applyConstraints {
    [self updateConstraints];

    for (UIView* child in [self subviews]) {
        [child _applyConstraints];
    }
}

/**
 @Status Interoperable
 @Notes May need some validation.
*/
- (void)updateConstraints {
    priv->_constraintsNeedUpdate = NO;

    [self autoLayoutUpdateConstraints];
}

/**
 @Status Interoperable
*/
- (void)updateConstraintsIfNeeded {
    if (self.needsUpdateConstraints) {
        UIViewController* controller = [UIViewController controllerForView:self];
        if (controller != nil) {
            [controller updateViewConstraints];
        } else {
            [self updateConstraints];
        }
    }
}

/**
 @Status Interoperable
*/
- (BOOL)needsUpdateConstraints {
    return priv->_constraintsNeedUpdate;
}

/**
 @Status Interoperable
*/
- (void)setNeedsUpdateConstraints {
    priv->_constraintsNeedUpdate = YES;
    [self setNeedsLayout];
}

/**
 @Status Stub
*/
- (void)removeMotionEffect:(UIMotionEffect*)effect {
    UNIMPLEMENTED();
    TraceWarning(TAG, L"Unsupported use of motion effects in removeMotionEffect:");
}

/**
 @Status Stub
*/
- (void)addMotionEffect:(UIMotionEffect*)effect {
    UNIMPLEMENTED();
    TraceWarning(TAG, L"Unsupported use of motion effects in addMotionEffect:");
}

/**
 @Status Interoperable
*/
- (UILayoutPriority)contentCompressionResistancePriorityForAxis:(UILayoutConstraintAxis)axis {
    switch (axis) {
        case UILayoutConstraintAxisHorizontal:
            return priv->_contentHuggingPriority.width;
            break;
        case UILayoutConstraintAxisVertical:
            return priv->_contentHuggingPriority.height;
            break;
        default:
            TraceWarning(TAG, L"Content compression resistance for unknown axis.");
            return 0.0f;
    }
}

/**
 @Status Interoperable
*/
- (void)setContentCompressionResistancePriority:(UILayoutPriority)priority forAxis:(UILayoutConstraintAxis)axis {
    switch (axis) {
        case UILayoutConstraintAxisHorizontal:
            priv->_contentCompressionResistancePriority.width = priority;
            break;
        case UILayoutConstraintAxisVertical:
            priv->_contentCompressionResistancePriority.height = priority;
            break;
        default:
            TraceWarning(TAG, L"Content compression resistance set on unknown axis.");
            return;
    }
    [self setNeedsUpdateConstraints];
}

/**
 @Status Interoperable
*/
- (UILayoutPriority)contentHuggingPriorityForAxis:(UILayoutConstraintAxis)axis {
    switch (axis) {
        case UILayoutConstraintAxisHorizontal:
            return priv->_contentHuggingPriority.width;
            break;
        case UILayoutConstraintAxisVertical:
            return priv->_contentHuggingPriority.height;
            break;
        default:
            TraceWarning(TAG, L"Content hugging for unknown axis.");
            return 0.0f;
    }
}

/**
 @Status Interoperable
*/
- (void)setContentHuggingPriority:(UILayoutPriority)priority forAxis:(UILayoutConstraintAxis)axis {
    switch (axis) {
        case UILayoutConstraintAxisHorizontal:
            priv->_contentHuggingPriority.width = priority;
            break;
        case UILayoutConstraintAxisVertical:
            priv->_contentHuggingPriority.height = priority;
            break;
        default:
            TraceWarning(TAG, L"Content hugging set on unknown axis.");
            return;
    }
    [self setNeedsUpdateConstraints];
}

/**
 @Status Interoperable
*/
- (UIView*)viewWithTag:(int)tag {
    if (priv->tag == tag) {
        return self;
    }

    LLTREE_FOREACH(curView, priv) {
        id ret = [curView->self viewWithTag:tag];
        if (ret != nil) {
            return ret;
        }
    }

    return nil;
}

/**
 @Status Interoperable
*/
- (UIResponder*)nextResponder {
    UIViewController* controller = [UIViewController controllerForView:self];

    if (controller) {
        return controller;
    }

    return priv->superview;
}

/**
 @Status Interoperable
*/
- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event {
    if (DEBUG_TOUCHES_LIGHT) {
        TraceVerbose(TAG, L"touchesBegan: %hs(0x%08x)", object_getClassName(self), self);
    }

    UIResponder* nextResponder = [self nextResponder];
    if (nextResponder != nil) {
        [nextResponder touchesBegan:touches withEvent:event];
    }
}

/**
 @Status Interoperable
*/
- (void)touchesMoved:(NSSet*)touches withEvent:(UIEvent*)event {
    if (DEBUG_TOUCHES_LIGHT) {
        TraceVerbose(TAG, L"touchesMoved: %hs(0x%08x)", object_getClassName(self), self);
    }

    UIResponder* nextResponder = [self nextResponder];
    if (nextResponder != nil) {
        [nextResponder touchesMoved:touches withEvent:event];
    }
}

/**
 @Status Interoperable
*/
- (void)touchesEnded:(NSSet*)touches withEvent:(UIEvent*)event {
    if (DEBUG_TOUCHES_LIGHT) {
        TraceVerbose(TAG, L"touchesEnded: %hs(0x%08x)", object_getClassName(self), self);
    }

    UIResponder* nextResponder = [self nextResponder];
    if (nextResponder != nil) {
        [nextResponder touchesEnded:touches withEvent:event];
    }
}

/**
 @Status Interoperable
*/
- (void)touchesCancelled:(NSSet*)touches withEvent:(UIEvent*)event {
    if (DEBUG_TOUCHES_LIGHT) {
        TraceVerbose(TAG, L"touchesCancelled: %hs(0x%08x)", object_getClassName(self), self);
    }

    UIResponder* nextResponder = [self nextResponder];
    if (nextResponder != nil) {
        [nextResponder touchesCancelled:touches withEvent:event];
    }
}

/**
 @Status Interoperable
*/
- (void)setClipsToBounds:(BOOL)clip {
    [layer setMasksToBounds:clip];
}

/**
 @Status Interoperable
*/
- (BOOL)clipsToBounds {
    return [layer masksToBounds];
}

/**
 @Status Stub
*/
- (void)setExclusiveTouch:(BOOL)isExclusive {
    UNIMPLEMENTED();
    TraceWarning(TAG, L"setExclusiveTouch not supported.");
}

/**
 @Status Interoperable
*/
- (id<CAAction>)actionForLayer:(CALayer*)actionLayer forKey:(NSString*)key {
    if (stackLevel > 0 && g_animationsDisabled == 0 && g_nestedAnimationsDisabled == 0) {
        if ([key isEqualToString:@"opacity"] || [key isEqualToString:@"position"] || [key isEqualToString:@"bounds"] ||
            [key isEqualToString:@"bounds.origin"] || [key isEqualToString:@"bounds.size"] || [key isEqualToString:@"transform"]) {
            CABasicAnimation* ret = [CABasicAnimation animationWithKeyPath:key];

            if (_animationProperties[stackLevel]._beginsFromCurrentState && ![key isEqualToString:@"opacity"]) {
                [ret setFromValue:[actionLayer presentationValueForKey:key]];
            } else {
                [ret setFromValue:[actionLayer valueForKey:key]];
            }

            if (_animationProperties[stackLevel]._animationCurve != nil) {
                [ret setTimingFunction:_animationProperties[stackLevel]._animationCurve];
            }
            [ret setDuration:_animationProperties[stackLevel]._animationDuration];
            [ret setAutoreverses:_animationProperties[stackLevel]._autoReverses];
            [ret setRepeatCount:_animationProperties[stackLevel]._repeatCount];
            [ret setBeginTime:_animationProperties[stackLevel]._animationDelay + CACurrentMediaTime()];
            [ret setDelegate:_animationProperties[stackLevel]._animationNotifier];
            _animationProperties[stackLevel]._numAnimations++;

            return ret;
        }
    }

    return (id<CAAction>)[NSNull null];
}

/**
 @Status Interoperable
*/
+ (void)performWithoutAnimation:(void (^)(void))actionsWithoutAnimation {
    BOOL areAnimationsEnabled = [self areAnimationsEnabled];
    [self setAnimationsEnabled:NO];
    CALLBLOCK(actionsWithoutAnimation);
    [self setAnimationsEnabled:areAnimationsEnabled];
}

/**
 @Status Interoperable
*/
+ (void)animateWithDuration:(double)duration animations:(animationBlockFunc)animationBlock {
    [self beginAnimations:nil context:0];
    [self setAnimationDuration:duration];
    [self setAnimationCurve:UIViewAnimationCurveEaseInOut];
    CALLBLOCK(animationBlock);

    [self commitAnimations];
}

/**
 @Status Interoperable
*/
+ (void)transitionFromView:(UIView*)fromView
                    toView:(UIView*)toView
                  duration:(double)duration
                   options:(uint32_t)options
                completion:(completionBlockFunc)completion {
    [self beginAnimations:nil context:0];
    _animationProperties[stackLevel]._completionBlock = COPYBLOCK(completion);
    [self setAnimationDuration:duration];
    [self setAnimationCurve:UIViewAnimationCurveEaseInOut];
    [self setAnimationTransition:UIViewAnimationTransitionFlipFromLeft forView:toView cache:FALSE];

    id superview = [fromView superview];
    [fromView removeFromSuperview];
    [superview addSubview:toView];
    [self commitAnimations];
}

/**
 @Status Interoperable
*/
+ (void)transitionWithView:(id)view
                  duration:(double)duration
                   options:(unsigned)options
                animations:(animationBlockFunc)animationBlock
                completion:(completionBlockFunc)completion {
    [self beginAnimations:nil context:0];
    _animationProperties[stackLevel]._completionBlock = COPYBLOCK(completion);
    [self setAnimationDuration:duration];
    [self setAnimationCurve:UIViewAnimationCurveEaseInOut];
    [self setAnimationTransition:UIViewAnimationTransitionFlipFromLeft forView:view cache:FALSE];
    CALLBLOCK(animationBlock);

    [self commitAnimations];
}

/**
 @Status Interoperable
*/
+ (void)animateWithDuration:(double)duration animations:(animationBlockFunc)animationBlock completion:(completionBlockFunc)completion {
    TraceWarning(TAG, L"animationWithDurationCompletion not fully supported.");
    [self beginAnimations:nil context:0];
    _animationProperties[stackLevel]._completionBlock = COPYBLOCK(completion);
    [self setAnimationDuration:duration];
    [self setAnimationCurve:UIViewAnimationCurveEaseInOut];
    CALLBLOCK(animationBlock);
    [self commitAnimations];
    // EbrCall(E2H(completion)[3], "dd", completion, TRUE);
}

/**
 @Status Interoperable
*/
+ (void)animateWithDuration:(double)duration
                      delay:(double)delay
                    options:(unsigned)options
                 animations:(animationBlockFunc)animationBlock
                 completion:(completionBlockFunc)completion {
    [self beginAnimations:nil context:0];
    _animationProperties[stackLevel]._completionBlock = COPYBLOCK(completion);
    [self setAnimationDuration:duration];
    [self setAnimationDelay:delay];
    [self setAnimationCurve:UIViewAnimationCurveEaseInOut];

    if (options & UIViewAnimationOptionBeginFromCurrentState) {
        [self setAnimationBeginsFromCurrentState:TRUE];
    }
    if (options & UIViewAnimationOptionAutoreverse) {
        [self setAnimationRepeatAutoreverses:TRUE];
    }
    if (options & UIViewAnimationOptionCurveLinear) {
        [self setAnimationCurve:UIViewAnimationCurveLinear];
    }

    CALLBLOCK(animationBlock);
    [self commitAnimations];
    // EbrCall(E2H(completion)[3], "dd", completion, TRUE);
}

/**
 @Status Stub
*/
+ (void)animateWithDuration:(NSTimeInterval)duration
                      delay:(NSTimeInterval)delay
     usingSpringWithDamping:(CGFloat)dampingRatio
      initialSpringVelocity:(CGFloat)velocity
                    options:(UIViewAnimationOptions)options
                 animations:(void (^)(void))animations
                 completion:(void (^)(BOOL finished))completion {
    UNIMPLEMENTED();
    completion(YES);
}

/**
 @Status Caveat
 @Notes UIViewKeyframeAnimationOptions are ignored that do not map to UIViewAnimationOptions.
*/
+ (void)animateKeyframesWithDuration:(NSTimeInterval)duration
                               delay:(NSTimeInterval)delay
                             options:(UIViewKeyframeAnimationOptions)options
                          animations:(void (^)(void))animations
                          completion:(void (^)(BOOL finished))completion {
    TraceWarning(TAG,
                 L"animateKeyframesWithDuration:(NSTimeInterval)duration options:(UIViewKeyframeAnimationOptions)options"
                 "animations:(void (^)(void))animations completion:(void (^)(BOOL finished))completion not fully supported.");
    // remove all unsupported options.
    UIViewAnimationOptions uiViewAnimationOptions = (UIViewAnimationOptions)(0x23F & options);

    [self animateWithDuration:duration delay:(double)delay options:uiViewAnimationOptions animations:animations completion:completion];
}

/**
 @Status Interoperable
*/
+ (void)addKeyframeWithRelativeStartTime:(double)frameStartTime
                        relativeDuration:(double)frameDuration
                              animations:(void (^)(void))animations {
    [self beginAnimations:nil context:0];
    [self setAnimationDelay:frameStartTime];
    [self setAnimationDuration:frameDuration];

    CALLBLOCK(animations);
}

/**
 @Status Interoperable
*/
+ (void)beginAnimations:(id)animationID context:(void*)context {
    stackLevel++;
    assert(stackLevel < 32);

    _animationProperties[stackLevel]._numAnimations = 0;
    _animationProperties[stackLevel]._animationDuration = 0.2f;
    _animationProperties[stackLevel]._animationDelay = 0.0f;
    _animationProperties[stackLevel]._animationID = animationID;
    _animationProperties[stackLevel]._context = context;
    _animationProperties[stackLevel]._repeatCount = 0.0f;
    _animationProperties[stackLevel]._autoReverses = FALSE;
    _animationProperties[stackLevel]._beginsFromCurrentState = FALSE;
    _animationProperties[stackLevel]._animationCurve = [CAMediaTimingFunction functionWithName:@"kCAMediaTimingFunctionEaseInEaseOut"];
    _animationProperties[stackLevel]._animationWillStartSelector = NULL;
    _animationProperties[stackLevel]._animationDidStopSelector = NULL;
    _animationProperties[stackLevel]._animationDelegate = nil;
    _animationProperties[stackLevel]._animationNotifier = [UIAnimationNotification alloc];
    [_animationProperties[stackLevel]._animationNotifier autorelease];
    _animationProperties[stackLevel]._completionBlock = nil;
}

/**
 @Status Interoperable
*/
+ (void)setAnimationCurve:(UIViewAnimationCurve)curve {
    switch (curve) {
        case UIViewAnimationCurveEaseInOut:
            _animationProperties[stackLevel]._animationCurve =
                [CAMediaTimingFunction functionWithName:@"kCAMediaTimingFunctionEaseInEaseOut"];
            break;

        case UIViewAnimationCurveEaseIn:
            _animationProperties[stackLevel]._animationCurve = [CAMediaTimingFunction functionWithName:@"kCAMediaTimingFunctionEaseIn"];
            break;

        case UIViewAnimationCurveEaseOut:
            _animationProperties[stackLevel]._animationCurve = [CAMediaTimingFunction functionWithName:@"kCAMediaTimingFunctionEaseOut"];
            break;

        case UIViewAnimationCurveLinear:
            _animationProperties[stackLevel]._animationCurve = [CAMediaTimingFunction functionWithName:@"kCAMediaTimingFunctionLinear"];
            break;

        default:
            assert(0);
            break;
    }
}

/**
 @Status Interoperable
*/
+ (void)setAnimationRepeatAutoreverses:(BOOL)autoReverses {
    _animationProperties[stackLevel]._autoReverses = autoReverses;
}

/**
 @Status Interoperable
*/
+ (void)setAnimationRepeatCount:(float)count {
    _animationProperties[stackLevel]._repeatCount = count;
}

/**
 @Status Interoperable
*/
+ (void)setAnimationDuration:(double)duration {
    _animationProperties[stackLevel]._animationDuration = duration;
}

+ (double)_getAnimationDuration {
    if (stackLevel > 0) {
        return _animationProperties[stackLevel]._animationDuration;
    } else {
        return 0.0;
    }
}

/**
 @Status Interoperable
*/
+ (void)setAnimationDelay:(double)delay {
    _animationProperties[stackLevel]._animationDelay = delay;
}

/**
 @Status Interoperable
*/
+ (void)setAnimationDelegate:(id)delegate {
    _animationProperties[stackLevel]._animationDelegate = delegate;
}

/**
 @Status Interoperable
*/
+ (void)setAnimationsEnabled:(BOOL)enable {
    g_animationsDisabled = !enable;
}

+ (void)_setNestedAnimationsEnabled:(BOOL)enable {
    if (enable) {
        CONTINUE_ANIMATIONS();
    } else {
        PAUSE_ANIMATIONS();
    }
}

/**
 @Status Interoperable
*/
+ (BOOL)animationsEnabled {
    return (g_animationsDisabled == 0) && (g_nestedAnimationsDisabled == 0);
}

/**
 @Status Interoperable
*/
+ (BOOL)areAnimationsEnabled {
    return [self animationsEnabled];
}

/**
 @Status Interoperable
*/
+ (void)setAnimationTransition:(UIViewAnimationTransition)transition forView:(UIView*)view cache:(BOOL)cache {
    if (stackLevel > 0 && transition != UIViewAnimationTransitionNone) {
        _animationProperties[stackLevel]._numAnimations++;
        CATransition* ret = [CATransition animation];
        [ret setDuration:_animationProperties[stackLevel]._animationDuration];
        [ret setAutoreverses:_animationProperties[stackLevel]._autoReverses];
        [ret setRepeatCount:_animationProperties[stackLevel]._repeatCount];
        [ret setDelay:_animationProperties[stackLevel]._animationDelay];
        [ret setDelegate:_animationProperties[stackLevel]._animationNotifier];

        switch (transition) {
            case UIViewAnimationTransitionFlipFromLeft:
                [ret setType:@"kCATransitionFlip"];
                [ret setSubtype:@"kCATransitionFromLeft"];
                break;

            case UIViewAnimationTransitionFlipFromRight:
                [ret setType:@"kCATransitionFlip"];
                [ret setSubtype:@"kCATransitionFromRight"];
                break;

            default:
                [ret setType:@"kCATransitionPush"];
                [ret setSubtype:@"kCATransitionFromLeft"];
                break;
        }

        [[view layer] addAnimation:ret forKey:@"transition"];
    }
}

+ (void)_setPageTransitionForView:(UIView*)view fromLeft:(BOOL)fromLeft {
    if (stackLevel > 0) {
        _animationProperties[stackLevel]._numAnimations++;
        CATransition* ret = [CATransition animation];
        [ret setDuration:_animationProperties[stackLevel]._animationDuration];
        [ret setAutoreverses:_animationProperties[stackLevel]._autoReverses];
        [ret setRepeatCount:_animationProperties[stackLevel]._repeatCount];
        [ret setDelay:_animationProperties[stackLevel]._animationDelay];
        [ret setDelegate:_animationProperties[stackLevel]._animationNotifier];
        [ret setType:@"kCATransitionPush"];

        [ret setSubtype:fromLeft ? @"kCATransitionFromLeft" : @"kCATransitionFromRight"];
        [[view layer] addAnimation:ret forKey:@"transition"];
    }
}

/**
 @Status Interoperable
*/
+ (void)setAnimationBeginsFromCurrentState:(BOOL)curState {
    _animationProperties[stackLevel]._beginsFromCurrentState = curState;
}

/**
 @Status Interoperable
*/
+ (void)setAnimationDidStopSelector:(SEL)selector {
    _animationProperties[stackLevel]._animationDidStopSelector = selector;
}

/**
 @Status Interoperable
*/
+ (void)setAnimationWillStartSelector:(SEL)selector {
    _animationProperties[stackLevel]._animationWillStartSelector = selector;
}

/**
 @Status Interoperable
*/
+ (void)commitAnimations {
    if (stackLevel <= 0) {
        TraceWarning(TAG, L"UIView: No animations stacked!");
        return;
    }

    if (_animationProperties[stackLevel]._numAnimations > 0) {
        _animationProperties[stackLevel]._animationNotifier->_numAnimations = _animationProperties[stackLevel]._numAnimations;
        _animationProperties[stackLevel]._animationNotifier->_numStarted = 0;
        _animationProperties[stackLevel]._animationNotifier->_numStopped = 0;
        _animationProperties[stackLevel]._animationNotifier->_animationDidStopSelector =
            _animationProperties[stackLevel]._animationDidStopSelector;
        _animationProperties[stackLevel]._animationNotifier->_animationWillStartSelector =
            _animationProperties[stackLevel]._animationWillStartSelector;
        _animationProperties[stackLevel]._animationNotifier->_animDelegate = [_animationProperties[stackLevel]._animationDelegate retain];
        _animationProperties[stackLevel]._animationNotifier->_context = _animationProperties[stackLevel]._context;
        _animationProperties[stackLevel]._animationNotifier->_animName = [_animationProperties[stackLevel]._animationID copy];
        _animationProperties[stackLevel]._animationNotifier->_completionBlock = _animationProperties[stackLevel]._completionBlock;
    } else {
        sendDidStop(_animationProperties[stackLevel]._animationDelegate,
                    _animationProperties[stackLevel]._animationDidStopSelector,
                    _animationProperties[stackLevel]._animationID,
                    TRUE,
                    _animationProperties[stackLevel]._context);
        if (_animationProperties[stackLevel]._completionBlock) {
            // TraceWarning(TAG,L"Calling completion block %x", E2H(_animationProperties[stackLevel]._completionBlock)[3]);
            CALLCOMPLETIONBLOCK(_animationProperties[stackLevel]._completionBlock, TRUE);
            [_animationProperties[stackLevel]._completionBlock release];
        }
    }

    stackLevel--;
}

/**
 @Status Interoperable
*/
- (void)willMoveToWindow:(UIWindow*)window {
}

/**
 @Status Interoperable
*/
- (void)willRemoveSubview:(UIView*)subview {
}

/**
 @Status Interoperable
*/
- (BOOL)isDescendantOfView:(UIView*)view {
    id curView = self;
    while (curView != nil) {
        if (curView == view) {
            return TRUE;
        }
        curView = [curView superview];
    }
    return FALSE;
}

/**
 @Status Interoperable
*/
- (void)awakeFromNib {
}

/**
 @Status Interoperable
*/
- (void)didMoveToWindow {
    [super didMoveToWindow];
}

/**
 @Status Interoperable
*/
- (void)didMoveToSuperview {
}

/**
 @Status Interoperable
*/
- (void)didAddSubview:(UIView*)subview {
}

/**
 @Status Interoperable
*/
- (CGSize)sizeThatFits:(CGSize)curSize {
    CGRect curBounds;
    curBounds = [self bounds];
    return curBounds.size;
}

/**
 @Status Interoperable
*/
- (void)sizeToFit {
    CGRect curSize;

    //  Get current size
    curSize = [self frame];

    //  Get preferred size
    curSize.size = [self sizeThatFits:curSize.size];
    [self setFrame:curSize];
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    // Run on the main thread because the underlying XAML objects can only be
    // called from the UI thread
    RunSynchronouslyOnMainThread(^{
        [self _dealloc];
    });
}

- (void)_dealloc {
    if (_deallocating) {
        return;
    }

    _deallocating = true;
    viewCount--;
    TraceInfo(TAG, L"%d: dealloc %hs %x", viewCount, object_getClassName(self), self);

    // Unsubscribe from pointer events
    [self->priv->_xamlInputElement removePointerPressedEvent:self->priv->_pointerPressedEventRegistration];
    [self->priv->_xamlInputElement removePointerMovedEvent:self->priv->_pointerMovedEventRegistration];
    [self->priv->_xamlInputElement removePointerReleasedEvent:self->priv->_pointerReleasedEventRegistration];
    [self->priv->_xamlInputElement removePointerCanceledEvent:self->priv->_pointerCanceledEventRegistration];
    [self->priv->_xamlInputElement removePointerCaptureLostEvent:self->priv->_pointerCaptureLostEventRegistration];

    [self removeFromSuperview];
    priv->backgroundColor = nil;
    priv->constraints = nil;
    int subviewCount = 0;
    id* subviewsCopy = (id*)alloca(sizeof(id) * priv->childCount);
    LLTREE_FOREACH(curView, priv) {
        subviewsCopy[subviewCount] = curView->self;
        [subviewsCopy[subviewCount] retain];
        subviewCount++;
    }

    for (int i = 0; i < subviewCount; i++) {
        [subviewsCopy[i] removeFromSuperview];
        [subviewsCopy[i] release];
    }

    for (UIGestureRecognizer* curgesture in priv->gestures) {
        if ([curgesture respondsToSelector:@selector(_setView:)]) {
            [curgesture _setView:nil];
        }
    }
    [priv->gestures release];
    [priv->currentTouches release];
    layer = nil;

    [self autoLayoutDealloc];

    delete priv;

    [super dealloc];
}

/**
 @Status Interoperable
*/
- (BOOL)endEditing:(BOOL)force {
    for (UIView* child in [self subviews]) {
        if ([child isKindOfClass:[UITextField class]]) {
            if ([child isFirstResponder]) {
                [child resignFirstResponder];
                return TRUE;
            }
        } else {
            if ([child endEditing:force]) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

/**
 @Status Interoperable
*/
- (void)drawRect:(CGRect)pos {
}

/**
 @Status Interoperable
*/
- (void)addGestureRecognizer:(UIGestureRecognizer*)gesture {
    [priv->gestures addObject:gesture];
    [gesture.view removeGestureRecognizer:gesture];
    [gesture _setView:self];
}

/**
 @Status Interoperable
*/
- (void)removeGestureRecognizer:(UIGestureRecognizer*)gesture {
    [priv->gestures removeObject:gesture];
    [gesture _setView:nil];
}

/**
 @Status Interoperable
*/
- (void)setGestureRecognizers:(NSArray*)gestures {
    for (UIGestureRecognizer* curgesture in priv->gestures) {
        if ([curgesture isKindOfClass:[UIGestureRecognizer class]]) {
            [curgesture _setView:nil];
        }
    }

    for (UIGestureRecognizer* curgesture in gestures) {
        if ([curgesture isKindOfClass:[UIGestureRecognizer class]]) {
            [curgesture.view removeGestureRecognizer:curgesture];
        }
    }

    gestures = [gestures copy];
    [priv->gestures release];
    priv->gestures = gestures;

    for (UIGestureRecognizer* curgesture in priv->gestures) {
        if ([curgesture isKindOfClass:[UIGestureRecognizer class]]) {
            [curgesture _setView:self];
        } else {
            TraceWarning(TAG, L"UIView: object %hs is not a gesture!", object_getClassName(curgesture));
        }
    }
}

/**
 @Status Interoperable
*/
- (NSArray*)gestureRecognizers {
    return priv->gestures;
}

/**
 @Status Stub
*/
+ (instancetype)appearance {
    UNIMPLEMENTED_WITH_MSG("Unimplemented method %hs on UIView called", __func__);
    return StubReturn();
}

/**
 @Status Stub
*/
+ (instancetype)appearanceWhenContainedIn:(Class<UIAppearanceContainer>)containedClass, ... {
    UNIMPLEMENTED_WITH_MSG("Unimplemented method %hs on UIView called", __func__);
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (void)setBackButtonDelegate:(id)delegate action:(SEL)action withParam:(id)param {
    _backButtonDelegate = delegate;
    _backButtonSelector = action;
    _backButtonArg = param;
}

/**
 @Status Interoperable
*/
- (void)setBackButtonReturnsSuccess:(BOOL)returnsSuccess {
    _backButtonReturnsSuccess = returnsSuccess;
}

/**
 @Status Interoperable
*/
- (void)setBackButtonPriority:(int)priority {
    _backButtonPriority = priority;
}

/**
 @Public No
*/
- (void)setEnabled:(BOOL)enabled {
    [self setUserInteractionEnabled:enabled];
}

/**
 @Public No
*/
- (BOOL)_isEnabled {
    return [self isUserInteractionEnabled];
}

- (void)__setContentsImage:(id)image {
    UIImageSetLayerContents([self layer], image);
}

/**
 @Status Interoperable
*/
- (UIView*)viewForBaselineLayout {
    return self;
}

/**
 @Status Interoperable
*/
- (void)invalidateIntrinsicContentSize {
    [self autoLayoutInvalidateContentSize];
}

/**
 @Status Interoperable
*/
- (CGSize)intrinsicContentSize {
    CGSize ret;
    ret.width = UIViewNoIntrinsicMetric;
    ret.height = UIViewNoIntrinsicMetric;
    return ret;
}

/**
 @Status Caveat
 @Notes afterUpdates is ignored.
*/
- (UIView*)resizableSnapshotViewFromRect:(CGRect)rect afterScreenUpdates:(BOOL)afterUpdates withCapInsets:(UIEdgeInsets)capInsets {
    // TODO Support afterUpdates.
    UIGraphicsBeginImageContextWithOptions(rect.size, NO, 0.0);
    CGContextRef cgcontext = UIGraphicsGetCurrentContext();
    CGContextSaveGState(cgcontext);
    CGContextTranslateCTM(cgcontext, -rect.origin.x, -rect.origin.y);

    [self.layer renderInContext:UIGraphicsGetCurrentContext()];
    UIImage* screenshot = [UIGraphicsGetImageFromCurrentImageContext() resizableImageWithCapInsets:capInsets];
    CGContextRestoreGState(UIGraphicsGetCurrentContext());
    UIGraphicsEndImageContext();

    UIImageView* viewScreenShot = [[UIImageView alloc] initWithImage:screenshot];

    [viewScreenShot setFrame:rect];
    return [viewScreenShot autorelease];
}

/**
 @Status Caveat
 @Notes afterUpdates is ignored.
*/
- (UIView*)snapshotViewAfterScreenUpdates:(BOOL)afterUpdates {
    // TODO Support afterUpdates.
    UIGraphicsBeginImageContextWithOptions(self.frame.size, NO, 0.0);
    [self.layer renderInContext:UIGraphicsGetCurrentContext()];
    UIImage* screenshot = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();

    UIImageView* viewScreenShot = [[UIImageView alloc] initWithImage:screenshot];

    return [viewScreenShot autorelease];
}

/**
 @Status Interoperable
*/
- (void)setNativeElement:(WXFrameworkElement*)nativeElement {
    [self layer].contentsElement = nativeElement;
}

/**
 @Status Interoperable
*/
- (NSLayoutDimension*)heightAnchor {
    if (priv->_heightAnchor == nil) {
        priv->_heightAnchor = [NSLayoutAnchor _anchorWithAttribute:NSLayoutAttributeHeight owner:self];
    }
    return priv->_heightAnchor;
}

/**
 @Status Interoperable
*/
- (NSLayoutDimension*)widthAnchor {
    if (priv->_widthAnchor == nil) {
        priv->_widthAnchor = [NSLayoutAnchor _anchorWithAttribute:NSLayoutAttributeWidth owner:self];
    }
    return priv->_widthAnchor;
}

/**
 @Status Interoperable
*/
- (NSLayoutXAxisAnchor*)centerXAnchor {
    if (priv->_centerXAnchor == nil) {
        priv->_centerXAnchor = [NSLayoutAnchor _anchorWithAttribute:NSLayoutAttributeCenterX owner:self];
    }
    return priv->_centerXAnchor;
}

/**
 @Status Interoperable
*/
- (NSLayoutXAxisAnchor*)leadingAnchor {
    if (priv->_leadingAnchor == nil) {
        priv->_leadingAnchor = [NSLayoutAnchor _anchorWithAttribute:NSLayoutAttributeLeading owner:self];
    }
    return priv->_leadingAnchor;
}

/**
 @Status Interoperable
*/
- (NSLayoutXAxisAnchor*)leftAnchor {
    if (priv->_leftAnchor == nil) {
        priv->_leftAnchor = [NSLayoutAnchor _anchorWithAttribute:NSLayoutAttributeLeft owner:self];
    }
    return priv->_leftAnchor;
}

/**
 @Status Interoperable
*/
- (NSLayoutXAxisAnchor*)rightAnchor {
    if (priv->_rightAnchor == nil) {
        priv->_rightAnchor = [NSLayoutAnchor _anchorWithAttribute:NSLayoutAttributeRight owner:self];
    }
    return priv->_rightAnchor;
}

/**
 @Status Interoperable
*/
- (NSLayoutXAxisAnchor*)trailingAnchor {
    if (priv->_trailingAnchor == nil) {
        priv->_trailingAnchor = [NSLayoutAnchor _anchorWithAttribute:NSLayoutAttributeTrailing owner:self];
    }
    return priv->_trailingAnchor;
}

/**
 @Status Interoperable
*/
- (NSLayoutYAxisAnchor*)bottomAnchor {
    if (priv->_bottomAnchor == nil) {
        priv->_bottomAnchor = [NSLayoutAnchor _anchorWithAttribute:NSLayoutAttributeBottom owner:self];
    }
    return priv->_bottomAnchor;
}

/**
 @Status Interoperable
*/
- (NSLayoutYAxisAnchor*)centerYAnchor {
    if (priv->_centerYAnchor == nil) {
        priv->_centerYAnchor = [NSLayoutAnchor _anchorWithAttribute:NSLayoutAttributeCenterY owner:self];
    }
    return priv->_centerYAnchor;
}

/**
 @Status Interoperable
*/
- (NSLayoutYAxisAnchor*)firstBaselineAnchor {
    if (priv->_firstBaselineAnchor == nil) {
        priv->_firstBaselineAnchor = [NSLayoutAnchor _anchorWithAttribute:NSLayoutAttributeFirstBaseline owner:self];
    }
    return priv->_firstBaselineAnchor;
}

/**
 @Status Interoperable
*/
- (NSLayoutYAxisAnchor*)lastBaselineAnchor {
    if (priv->_lastBaselineAnchor == nil) {
        priv->_lastBaselineAnchor = [NSLayoutAnchor _anchorWithAttribute:NSLayoutAttributeLastBaseline owner:self];
    }
    return priv->_lastBaselineAnchor;
}

/**
 @Status Interoperable
*/
- (NSLayoutYAxisAnchor*)topAnchor {
    if (priv->_topAnchor == nil) {
        priv->_topAnchor = [NSLayoutAnchor _anchorWithAttribute:NSLayoutAttributeTop owner:self];
    }
    return priv->_topAnchor;
}

/**
 @Status Stub
*/
- (BOOL)canBecomeFocused {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (BOOL)hasAmbiguousLayout {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (CGRect)alignmentRectForFrame:(CGRect)frame {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (CGRect)frameForAlignmentRect:(CGRect)alignmentRect {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (CGSize)systemLayoutSizeFittingSize:(CGSize)targetSize {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (CGSize)systemLayoutSizeFittingSize:(CGSize)targetSize
        withHorizontalFittingPriority:(UILayoutPriority)horizontalFittingPriority
              verticalFittingPriority:(UILayoutPriority)verticalFittingPriority {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (NSArray*)constraintsAffectingLayoutForAxis:(UILayoutConstraintAxis)axis {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (UIEdgeInsets)alignmentRectInsets {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (UIViewPrintFormatter*)viewPrintFormatter {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (BOOL)drawViewHierarchyInRect:(CGRect)rect afterScreenUpdates:(BOOL)afterUpdates {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)decodeRestorableStateWithCoder:(NSCoder*)coder {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)drawRect:(CGRect)area forViewPrintFormatter:(UIViewPrintFormatter*)formatter {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)encodeRestorableStateWithCoder:(NSCoder*)coder {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)exerciseAmbiguityInLayout {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)layoutMarginsDidChange {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)tintColorDidChange {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
+ (BOOL)requiresConstraintBasedLayout {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
+ (NSTimeInterval)inheritedAnimationDuration {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
+ (UIUserInterfaceLayoutDirection)userInterfaceLayoutDirectionForSemanticContentAttribute:(UISemanticContentAttribute)attribute {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
+ (void)performSystemAnimation:(UISystemAnimation)animation
                       onViews:(NSArray*)views
                       options:(UIViewAnimationOptions)options
                    animations:(void (^)(void))parallelAnimations
                    completion:(void (^)(BOOL))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
+ (void)setAnimationStartDate:(NSDate*)startTime {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (CGPoint)convertPoint:(CGPoint)point toCoordinateSpace:(id<UICoordinateSpace>)coordinateSpace {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (CGPoint)convertPoint:(CGPoint)point fromCoordinateSpace:(id<UICoordinateSpace>)coordinateSpace {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (CGRect)convertRect:(CGRect)rect toCoordinateSpace:(id<UICoordinateSpace>)coordinateSpace {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (CGRect)convertRect:(CGRect)rect fromCoordinateSpace:(id<UICoordinateSpace>)coordinateSpace {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)setNeedsFocusUpdate {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)updateFocusIfNeeded {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (BOOL)shouldUpdateFocusInContext:(UIFocusUpdateContext*)context {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)didUpdateFocusInContext:(UIFocusUpdateContext*)context withAnimationCoordinator:(UIFocusAnimationCoordinator*)coordinator {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)traitCollectionDidChange:(UITraitCollection*)previousTraitCollection {
    UNIMPLEMENTED();
}

@end
