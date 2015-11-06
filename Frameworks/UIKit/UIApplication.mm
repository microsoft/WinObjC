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
@interface UIKeyboardRotationView : UIView {
}
@end
@class _UISettings;

#include "Platform/EbrPlatform.h"
#include "EbrRemoteNotifications.h"

#include "CoreFoundation/CFArray.h"
#include "CoreGraphics/CGContext.h"

#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSMutableArray.h"
#include "Foundation/NSString.h"
#include "NSRunLoopSource.h"
#include "UIKit/UIView.h"
#include "UIKit/UIImage.h"
#include "UIKit/UIColor.h"
#include "UIViewInternal.h"
#include "UIApplicationInternal.h"
typedef wchar_t WCHAR;
#include "UWP/WindowsGraphicsDisplay.h"

#include "UIEmptyController.h"

#include "CACompositor.h"
#include "UIInterface.h"

#include "RingBuffer.h"
#include <math.h>


NSString* const UIApplicationStatusBarOrientationUserInfoKey = @"";
NSString* const UIApplicationStatusBarFrameUserInfoKey = @"UIApplicationStatusBarFrameUserInfoKey";

NSString* const UIApplicationDidChangeStatusBarFrameNotification = @"UIApplicationDidChangeStatusBarFrameNotification";
NSString* const UIApplicationWillChangeStatusBarOrientationNotification = @"UIApplicationWillChangeStatusBarOrientationNotification";
NSString* const UIApplicationDidChangeStatusBarOrientationNotification = @"UIApplicationDidChangeStatusBarOrientationNotification";
NSString* const UIApplicationWillEnterForegroundNotification = @"UIApplicationWillEnterForegroundNotification";
NSString* const UIApplicationWillTerminateNotification = @"UIApplicationWillTerminateNotification";
NSString* const UIApplicationWillResignActiveNotification = @"UIApplicationWillResignActiveNotification";
NSString* const UIApplicationDidEnterBackgroundNotification = @"UIApplicationDidEnterBackgroundNotification";
NSString* const UIApplicationDidBecomeActiveNotification = @"UIApplicationDidBecomeActiveNotification";
NSString* const UIApplicationDidFinishLaunchingNotification = @"UIApplicationDidFinishLaunchingNotification";
NSString* const UIApplicationSignificantTimeChangeNotification = @"UIApplicationSignificantTimeChangeNotification";

NSString* const UIApplicationLaunchOptionsURLKey = @"UIApplicationLaunchOptionsURLKey";
NSString* const UIApplicationLaunchOptionsSourceApplicationKey = @"UIApplicationLaunchOptionsSourceApplicationKey";
NSString* const UIApplicationLaunchOptionsRemoteNotificationKey = @"UIApplicationLaunchOptionsRemoteNotificationKey";
NSString* const UIApplicationLaunchOptionsAnnotationKey = @"UIApplicationLaunchOptionsAnnotationKey";
NSString* const UIApplicationLaunchOptionsLocalNotificationKey = @"UIApplicationLaunchOptionsLocalNotificationKey";
NSString* const UIApplicationLaunchOptionsLocationKey = @"UIApplicationLaunchOptionsLocationKey";

NSString* const UIApplicationDidReceiveMemoryWarningNotification = @"UIApplicationDidReceiveMemoryWarningNotification";
NSString* const UIApplicationWillChangeStatusBarFrameNotification = @"UIApplicationWillChangeStatusBarFrameNotification";

NSString* const UIApplicationWillChangeDisplayModeNofication = @"UIApplicationWillChangeDisplayModeNofication";
NSString* const UIApplicationDidChangeDisplayModeNofication = @"UIApplicationDidChangeDisplayModeNofication";

NSString* const UITrackingRunLoopMode = @"UITrackingRunLoopMode";

NSString* const UIContentSizeCategoryAccessibilityExtraExtraExtraLarge = @"UIContentSizeCategoryAccessibilityExtraExtraExtraLarge";
NSString* const UIContentSizeCategoryAccessibilityExtraExtraLarge = @"UIContentSizeCategoryAccessibilityExtraExtraLarge";
NSString* const UIContentSizeCategoryExtraExtraLarge = @"UIContentSizeCategoryExtraExtraLarge";
NSString* const UIContentSizeCategoryExtraExtraExtraLarge = @"UIContentSizeCategoryExtraExtraExtraLarge";
NSString* const UIContentSizeCategoryAccessibilityExtraLarge = @"UIContentSizeCategoryAccessibilityExtraLarge";
NSString* const UIContentSizeCategoryExtraLarge = @"UIContentSizeCategoryExtraLarge";
NSString* const UIContentSizeCategoryAccessibilityLarge = @"UIContentSizeCategoryAccessibilityLarge";
NSString* const UIContentSizeCategoryLarge = @"UIContentSizeCategoryLarge";
NSString* const UIContentSizeCategoryAccessibilityMedium = @"UIContentSizeCategoryAccessibilityMedium";
NSString* const UIContentSizeCategoryMedium = @"UIContentSizeCategoryMedium";
NSString* const UIContentSizeCategorySmall = @"UIContentSizeCategorySmall";
NSString* const UIContentSizeCategoryExtraSmall = @"UIContentSizeCategoryExtraSmall";

float windowInsetLeft, windowInsetRight, windowInsetTop, windowInsetBottom;
float statusBarHeight = 20.0f;
static UIInterfaceOrientation _curOrientation = UIInterfaceOrientationPortrait;
static UIInterfaceOrientation _internalOrientation = UIInterfaceOrientationPortrait;
extern int requestDeviceOrientation;
extern UIWindow* _curKeyWindow;

NSArray* windows;
UIWindow* popupWindow;
UIApplication* sharedApplication;
extern bool g_bDidChangeView;
int showKeyboard, forceHideKeyboard;
static int curKeyboardType, showKeyboardType;
bool keyboardVisible;
CGRect keyboardRect;
UIView* _blankView;
static bool blankViewUp = false;
static float curBlankViewHeight = 0.0f;
static bool doEvaluateKeyboard = false;

#ifdef _DEBUG
bool g_logErrors = true;
#else
bool g_logErrors = true;
#endif

// Right now it's expected that the user sets this when they want otherwise:
float keyboardBaseHeight = 200, keyboardPhysicalHeight = 0;

static UIEdgeInsets _statusBarInsets;

id currentlyTrackingGesturesList;
BOOL resetAllTrackingGestures = TRUE;

BOOL refreshPending = FALSE;
id newMouseEvent, shutdownEvent;
id statusBar, statusBarRotationLayer, popupRotationLayer;
BOOL statusBarHidden = FALSE;
unsigned ignoringInteractionEvents = 0;
BOOL idleDisabled = FALSE;
extern BOOL _doShutdown;
EbrEvent g_NewMouseEvent, g_shutdownEvent;
extern id _curFirstResponder;

extern pthread_t renderTid;
extern pthread_mutex_t g_ChangeOrientationLock;
extern pthread_cond_t g_ChangeOrientationCond;

UIApplicationState _applicationState;
extern EbrEvent _applicationStateChanged;
bool _drawingAllowed = true;

NSMutableDictionary* curGesturesDict;

typedef struct {
    float x, y;
    double timeStamp;
    int count;
} TouchRecord;

static TouchRecord touchRecords[32];
static int touchRecordHead = 0, touchRecordTail = 0;

static float touchDist(float x1, float y1, float x2, float y2) {
    return sqrtf(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
}

#define TAP_SLACK_AREA \
    (((GetCACompositor()->screenWidth() / GetCACompositor()->deviceWidth()) * GetCACompositor()->screenXDpi()) / 3.0f) //  1/3 inch

static void RecordTouch(float x, float y, double timeStamp) {
    //  Skip over old touches
    while (timeStamp - touchRecords[touchRecordHead].timeStamp > 0.300 && touchRecordHead != touchRecordTail) {
        touchRecordHead = (touchRecordHead + 1) % 32;
    }

    int curPos = touchRecordHead;

    while (curPos != touchRecordTail) {
        if (timeStamp - touchRecords[curPos].timeStamp <= 0.300 &&
            touchDist(x, y, touchRecords[curPos].x, touchRecords[curPos].y) < TAP_SLACK_AREA) {
            //  Update the record
            touchRecords[curPos].count++;
            touchRecords[curPos].timeStamp = timeStamp;
            return;
        }
        curPos = (curPos + 1) % 32;
    }

    touchRecords[touchRecordTail].x = x;
    touchRecords[touchRecordTail].y = y;
    touchRecords[touchRecordTail].timeStamp = timeStamp;
    touchRecords[touchRecordTail].count = 1;

    touchRecordTail = (touchRecordTail + 1) % 32;
}

static int GetTouchCount(float x, float y, double timeStamp) {
    int curPos = touchRecordHead;

    while (curPos != touchRecordTail) {
        if (timeStamp - touchRecords[curPos].timeStamp <= 0.300 &&
            touchDist(x, y, touchRecords[curPos].x, touchRecords[curPos].y) < TAP_SLACK_AREA) {
            //  Update the record
            return touchRecords[curPos].count;
        }
        curPos = (curPos + 1) % 32;
    }

    return 0;
}

extern int glDrawContext;

int GetMouseEvents(EbrInputEvent* pDest, int max);

static UIView *_curKeyboardAccessory, *_curKeyboardInputView;

static idretaintype(NSMutableArray) _curNotifications;

@implementation UIApplication {
    id _delegate;
    NSUInteger _statusBarStyle;
}
+ (instancetype)alloc {
    if (sharedApplication != nil) {
        return sharedApplication;
    }

#ifdef SUPPORT_REMOTE_NOTIFICATIONS
    EbrInitRemoteNotifications();
#endif

    sharedApplication = [super alloc];

    newMouseEvent = [NSRunLoopSource new];
    [newMouseEvent setSourceDelegate:sharedApplication selector:@selector(newMouseEvent)];
    [newMouseEvent setPriority:100];
    g_NewMouseEvent = (EbrEvent)[newMouseEvent eventHandle];

    shutdownEvent = [NSRunLoopSource new];
    [shutdownEvent setSourceDelegate:[UIApplication class] selector:@selector(_shutdownEvent)];
    g_shutdownEvent = (EbrEvent)[shutdownEvent eventHandle];

    [[NSRunLoop mainRunLoop] addInputSource:newMouseEvent forMode:@"kCFRunLoopDefaultMode"];
    [[NSRunLoop mainRunLoop] addInputSource:shutdownEvent forMode:@"kCFRunLoopDefaultMode"];
    [[NSRunLoop mainRunLoop] addObserver:sharedApplication forMode:@"kCFRunLoopDefaultMode"];
    currentlyTrackingGesturesList = [NSMutableArray new];

    return sharedApplication;
}

- (void)_destroy {
    [popupWindow _destroy];
    popupWindow = nil;
    sharedApplication = nil;

    [[NSRunLoop mainRunLoop] removeInputSource:newMouseEvent forMode:@"kCFRunLoopDefaultMode"];
    [[NSRunLoop mainRunLoop] removeObserver:sharedApplication forMode:@"kCFRunLoopDefaultMode"];
}

- (void)notify:(unsigned)activity {
    if ([NSThread currentThread] != [NSThread mainThread]) {
        return;
    }
    if (_applicationState == UIApplicationStateBackground) {
        return;
    }

    if (activity & kCFRunLoopBeforeTimers) {
        //  Always evaluate keyboard if it's diplayed - properties can change
        if (doEvaluateKeyboard || blankViewUp) {
            doEvaluateKeyboard = false;
            evaluateKeyboard(self);
        }
        if (refreshPending) {
            refreshPending = FALSE;

            if (curKeyboardType != showKeyboardType) {
                curKeyboardType = showKeyboardType;
                EbrSetKeyboardType(curKeyboardType);
            }
            if (forceHideKeyboard == 0 && showKeyboard > 0 && keyboardVisible == false) {
                keyboardVisible = true;
                EbrPlatformShowKeyboard();
            } else if ((forceHideKeyboard > 0 || showKeyboard == 0) && keyboardVisible == true) {
                keyboardVisible = false;
                EbrPlatformHideKeyboard();
            }

            if ([windows count] > 0) {
                int windowCount = [windows count];

                for (int i = 0; i < windowCount; i++) {
                    id window = [windows objectAtIndex:i];
                    id windowLayer = [window layer];
                    [windowLayer validateDisplayHierarchy];
                }

                [CATransaction _commitRootQueue];
                GetCACompositor()->ProcessTransactions();
            }
        }
    }
}

+ (void)viewChanged {
    if (!refreshPending) {
        id mainRunLoop = [NSRunLoop mainRunLoop];
        id currentRunLoop = [NSRunLoop currentRunLoop];
        if (mainRunLoop != currentRunLoop) {
            EbrDebugLog("**** Error - UI updated on non-UI thread ******\n");
            // return;
        }

        refreshPending = TRUE;

        [[NSRunLoop mainRunLoop] _wakeUp];
    }
}

+ (void)viewTreeChanged {
    if (!refreshPending) {
        refreshPending = TRUE;
        [[NSRunLoop mainRunLoop] _wakeUp];
    }
}

static id findTopActionButtons(NSArray* arr, NSArray* windows, UIView* root) {
    id subviews = [root subviews];
    int count = [subviews count];

    for (int i = count - 1; i >= 0; i--) {
        UIView* curView = [subviews objectAtIndex:i];
        findTopActionButtons(arr, windows, curView);
        if ([curView isHidden]) {
            continue;
        }

        if (curView->_backButtonDelegate != nil) {
            CGRect bounds;
            bounds = [curView bounds];

            CGPoint middle;
            int windowCount = [windows count];

            for (int j = windowCount - 1; j >= 0; j--) {
                id curWindow = [windows objectAtIndex:j];

                middle.x = bounds.origin.x + bounds.size.width / 2.0f;
                middle.y = bounds.origin.y + bounds.size.height / 2.0f;
                middle = [curView convertPoint:middle toView:nil];
                middle = [curWindow convertPoint:middle fromView:nil toView:curWindow];

                id pointView = [curWindow hitTest:middle withEvent:nil];

                if (pointView == curView || [pointView isDescendantOfView:curView]) {
                    [arr addObject:curView];
                    break;
                } else if (pointView != nil && pointView != curWindow) {
                    break;
                }
            }
        }
    }

    return nil;
}

static int __EbrSortViewPriorities(id val1, id val2, void* context) {
    UIView* view1 = val1;
    UIView* view2 = val2;

    if (view1->_backButtonPriority > view2->_backButtonPriority) {
        return -1;
    } else if (view1->_backButtonPriority < view2->_backButtonPriority) {
        return 1;
    } else {
        return 0;
    }
}

+ (void)_doBackAction {
    if (ignoringInteractionEvents) {
        return;
    }

    NSArray* windows = [[self sharedApplication] windows];
    int count = [windows count];

    bool wasHandled = false;

    id allActionButtons = [NSMutableArray new];

    for (int i = count - 1; i >= 0 && !wasHandled; i--) {
        id window = [windows objectAtIndex:i];

        findTopActionButtons(allActionButtons, windows, window);
    }
    [allActionButtons sortUsingFunction:__EbrSortViewPriorities context:0];

    for (UIView* curView in allActionButtons) {
        NSInvocation* inv =
            [NSInvocation invocationWithMethodSignature:[[curView->_backButtonDelegate class]
                                                            instanceMethodSignatureForSelector:curView->_backButtonSelector]];
        inv.selector = curView->_backButtonSelector;
        inv.target = curView->_backButtonDelegate;

        [inv invoke];
        BOOL buttonHandled = FALSE;
        [inv getReturnValue:&buttonHandled];

        if (buttonHandled || !curView->_backButtonReturnsSuccess) {
            wasHandled = true;
            break;
        }
    }

    [allActionButtons release];

    if (!wasHandled) {
        // Not handled by any of the windows, try sending a message about it:
        id appDelegate = [[self sharedApplication] delegate];
        if ([appDelegate respondsToSelector:@selector(applicationBackButtonPressed:)]) {
            [appDelegate applicationBackButtonPressed:nil];
        }
    }
}

+ (void)_launchedWithURL:(NSURL*)url {
    UIApplication* shared = [self sharedApplication];
    id delegate = [shared delegate];
    EbrDebugLog("Launchedwithurl: %x\n", url);
    char* pURL = (char*)[[url absoluteString] UTF8String];

    if ([delegate respondsToSelector:@selector(application:handleOpenURL:)]) {
        [delegate application:shared handleOpenURL:url];
    } else if ([delegate respondsToSelector:@selector(application:openURL:sourceApplication:annotation:)]) {
        [delegate application:shared openURL:url sourceApplication:nil annotation:nil];
    }
}

/**
 @Status Interoperable
*/
+ (UIApplication*)sharedApplication {
    return sharedApplication;
}

/**
 @Status Stub
*/
- (void)scheduleLocalNotification:(UILocalNotification*)n {
    UNIMPLEMENTED();
    [n _setReceiver:self];
    int idx = [_curNotifications indexOfObject:n];
    if (idx == NSNotFound) {
        [_curNotifications addObject:n];
    }
}

- (void)_receiveAlarm:(id)localNotification {
    int idx = [_curNotifications indexOfObject:localNotification];
    if (idx == NSNotFound) {
        return; // probably deleted.
    }

    UIAlertView* alert = [[UIAlertView alloc] initWithTitle:@"Alert"
                                                    message:[localNotification alertBody]
                                                   delegate:nil
                                          cancelButtonTitle:[localNotification alertAction]
                                          otherButtonTitles:nil];

    [alert show];
    [alert release];

    [_curNotifications removeObjectAtIndex:(unsigned long)idx];
    [localNotification release];
}

/**
 @Status Stub
*/
- (void)setStatusBarStyle:(unsigned)style animated:(BOOL)animated {
    UNIMPLEMENTED();
    _statusBarStyle = style;
}

/**
 @Status Stub
*/
- (unsigned)statusBarStyle {
    UNIMPLEMENTED();
    return _statusBarStyle;
}

/**
 @Status Interoperable
*/
- (void)setStatusBarHidden:(BOOL)hide {
    [self setStatusBarHidden:hide animated:0];
}

/**
 @Status Caveat
 @Notes animation parameter not supported
*/
- (void)setStatusBarHidden:(BOOL)hide withAnimation:(UIStatusBarAnimation)anim {
    [self setStatusBarHidden:hide animated:anim];
}

- (void)setProximitySensingEnabled:(BOOL)enabled {
}

/**
 @Status Interoperable
*/
- (void)setStatusBarOrientation:(UIInterfaceOrientation)orientation {
    [self setStatusBarOrientation:orientation animated:FALSE];
}

/**
 @Status Stub
*/
- (UIUserInterfaceLayoutDirection)userInterfaceLayoutDirection {
    UNIMPLEMENTED();
    return UIUserInterfaceLayoutDirectionLeftToRight;
}

/**
 @Status Interoperable
*/
- (void)setStatusBarOrientation:(UIInterfaceOrientation)orientation animated:(BOOL)animated {
    CGRect rect, appFrame;

    appFrame.origin.x = 0;
    appFrame.origin.y = 0;
    appFrame.size.width = GetCACompositor()->screenWidth();
    appFrame.size.height = GetCACompositor()->screenHeight();

    _curOrientation = orientation;
    CGAffineTransform trans;

    int changeHostOrientation = 0;

    switch (_curOrientation) {
        case UIInterfaceOrientationLandscapeRight:
            rect.origin.x = appFrame.origin.y;
            rect.origin.y = appFrame.origin.x;
            rect.size.width = appFrame.size.height;
            rect.size.height = appFrame.size.width;

            [statusBarRotationLayer
                setCenter:CGPointMake(appFrame.origin.x + appFrame.size.width / 2.0f, appFrame.origin.y + appFrame.size.height / 2.0f)];
            [popupRotationLayer
                setCenter:CGPointMake(appFrame.origin.x + appFrame.size.width / 2.0f, appFrame.origin.y + appFrame.size.height / 2.0f)];
            rect.origin.x = 0.0f;
            rect.origin.y = 0.0f;
            [statusBarRotationLayer setBounds:rect];
            [popupRotationLayer setBounds:rect];

            trans = CGAffineTransformMakeRotation(kPi / 2);
            [statusBarRotationLayer setTransform:trans];
            [popupRotationLayer setTransform:trans];

            _statusBarInsets.left = statusBarHeight;
            _statusBarInsets.right = 0.0f;
            _statusBarInsets.top = 0.0f;
            _statusBarInsets.bottom = 0.0f;

            changeHostOrientation = 3;
            break;

        case UIInterfaceOrientationPortrait:
            rect.origin.x = appFrame.origin.x;
            rect.origin.y = appFrame.origin.y;
            rect.size.width = appFrame.size.width;
            rect.size.height = appFrame.size.height;

            [statusBarRotationLayer
                setCenter:CGPointMake(appFrame.origin.x + appFrame.size.width / 2.0f, appFrame.origin.y + appFrame.size.height / 2.0f)];
            [popupRotationLayer
                setCenter:CGPointMake(appFrame.origin.x + appFrame.size.width / 2.0f, appFrame.origin.y + appFrame.size.height / 2.0f)];
            rect.origin.x = 0.0f;
            rect.origin.y = 0.0f;
            [statusBarRotationLayer setBounds:rect];
            [popupRotationLayer setBounds:rect];

            trans = CGAffineTransformMakeTranslation(0.0f, 0.0f);
            [statusBarRotationLayer setTransform:trans];
            [popupRotationLayer setTransform:trans];

            _statusBarInsets.left = 0.0f;
            _statusBarInsets.right = 0.0f;
            _statusBarInsets.top = statusBarHeight;
            _statusBarInsets.bottom = 0.0f;
            changeHostOrientation = 0;
            break;

        case UIInterfaceOrientationLandscapeLeft:
            rect.origin.x = appFrame.origin.y;
            rect.origin.y = appFrame.origin.x;
            rect.size.width = appFrame.size.height;
            rect.size.height = appFrame.size.width;

            [statusBarRotationLayer
                setCenter:CGPointMake(appFrame.origin.x + appFrame.size.width / 2.0f, appFrame.origin.y + appFrame.size.height / 2.0f)];
            [popupRotationLayer
                setCenter:CGPointMake(appFrame.origin.x + appFrame.size.width / 2.0f, appFrame.origin.y + appFrame.size.height / 2.0f)];
            rect.origin.x = 0.0f;
            rect.origin.y = 0.0f;
            [statusBarRotationLayer setBounds:rect];
            [popupRotationLayer setBounds:rect];

            trans = CGAffineTransformMakeRotation(270.0f / 180.0f * kPi);
            [statusBarRotationLayer setTransform:trans];
            [popupRotationLayer setTransform:trans];

            _statusBarInsets.left = statusBarHeight;
            _statusBarInsets.right = 0.0f;
            _statusBarInsets.top = 0.0f;
            _statusBarInsets.bottom = 0.0f;
            changeHostOrientation = 1;
            break;

        case UIInterfaceOrientationPortraitUpsideDown:
            rect.origin.x = appFrame.origin.x;
            rect.origin.y = appFrame.origin.y;
            rect.size.width = appFrame.size.width;
            rect.size.height = appFrame.size.height;

            [statusBarRotationLayer
                setCenter:CGPointMake(appFrame.origin.x + appFrame.size.width / 2.0f, appFrame.origin.y + appFrame.size.height / 2.0f)];
            [popupRotationLayer
                setCenter:CGPointMake(appFrame.origin.x + appFrame.size.width / 2.0f, appFrame.origin.y + appFrame.size.height / 2.0f)];
            rect.origin.x = 0.0f;
            rect.origin.y = 0.0f;
            [statusBarRotationLayer setBounds:rect];
            [popupRotationLayer setBounds:rect];

            trans = CGAffineTransformMakeRotation(kPi);
            [statusBarRotationLayer setTransform:trans];
            [popupRotationLayer setTransform:trans];

            _statusBarInsets.left = 0.0f;
            _statusBarInsets.right = 0.0f;
            _statusBarInsets.top = 0.0f;
            _statusBarInsets.bottom = statusBarHeight;
            changeHostOrientation = 2;
            break;

        default:
            EbrDebugLog("Unknown orientation %d\n", _curOrientation);
            assert(0);
            break;
    }

#if defined(ANDROID) || defined(QNX)
    pthread_mutex_lock(&g_ChangeOrientationLock);
    requestDeviceOrientation = changeHostOrientation;
    pthread_cond_wait(&g_ChangeOrientationCond, &g_ChangeOrientationLock);
    if (!statusBarHidden) {
#ifdef NO_STATUSBAR
        windowInsetLeft = _statusBarInsets.left;
        windowInsetRight = _statusBarInsets.right;
        windowInsetTop = _statusBarInsets.top;
        windowInsetBottom = _statusBarInsets.bottom;
        g_bDidChangeView = true;
#endif
    }

#ifdef RUN_NATIVE_RESOLUTION
    //  Resize base windows to screen size
    id windows = [self windows];
    int count = [windows count];

    CGRect frame;
    frame.origin.x = 0;
    frame.origin.y = 0;
    frame.size.width = GetCACompositor()->screenWidth();
    frame.size.height = GetCACompositor()->screenHeight();

    CGPoint center;
    center.x = frame.origin.x + frame.size.width / 2.0f;
    center.y = frame.origin.y + frame.size.height / 2.0f;

    int i;
    for (i = 0; i < count; i++) {
        id window = [windows objectAtIndex:i];
        id windowLayer = [window layer];

        [windowLayer setBounds:frame];
        [windowLayer setPosition:center];
    }
#endif
    pthread_mutex_unlock(&g_ChangeOrientationLock);
#endif
}

- (void)_setInternalOrientation:(UIInterfaceOrientation)orientation {
    _internalOrientation = orientation;
}

/**
 @Status Interoperable
*/
- (UIInterfaceOrientation)statusBarOrientation {
    return _curOrientation;
}

- (UIInterfaceOrientation)_internalOrientation {
    return _internalOrientation;
}

- (void)setStatusBarMode:(unsigned)mode
             orientation:(UIInterfaceOrientation)orientation
                duration:(unsigned)duration
                 fenceID:(unsigned)fenceID {
}

- (void)setStatusBarMode:(unsigned)mode duration:(unsigned)duration {
}

/**
 @Status Interoperable
*/
- (void)setDelegate:(id)delegateAddr {
    _delegate = delegateAddr;
}

/**
 @Status Interoperable
*/
- (id)delegate {
    return _delegate;
}

/**
 @Status Stub
*/
- (void)setIdleTimerDisabled:(BOOL)disable {
    UNIMPLEMENTED();
    idleDisabled = disable;
}

/**
 @Status Stub
*/
- (BOOL)isIdleTimerDisabled {
    UNIMPLEMENTED();
    return idleDisabled;
}

/**
 @Status Interoperable
*/
- (void)setStatusBarHidden:(BOOL)hidden animated:(BOOL)animated {
    if (statusBarHidden != hidden) {
        statusBarHidden = hidden;
        [statusBar setHidden:hidden];
#ifdef NO_STATUSBAR
        if (!statusBarHidden) {
            windowInsetLeft = _statusBarInsets.left;
            windowInsetRight = _statusBarInsets.right;
            windowInsetTop = _statusBarInsets.top;
            windowInsetBottom = _statusBarInsets.bottom;
            g_bDidChangeView = true;
        } else {
            windowInsetLeft = 0;
            windowInsetRight = 0;
            windowInsetTop = 0;
            windowInsetBottom = 0;
            g_bDidChangeView = true;
        }
#endif

        /*
        int windowCount = [windows count];

        for ( int i = 0; i < windowCount; i ++ ) {
        id curWindow = [windows objectAtIndex:i];
        id controller = [curWindow rootViewController];

        if ( controller != nil ) {
        [controller _resizeForStatusBar:hidden];
        }
        }
        */
    }
}

/**
 @Status Stub
*/
- (void)setApplicationIconBadgeNumber:(int)num {
    UNIMPLEMENTED();
    EbrSetApplicationBadgeNumber(num);
}

static void printViews(id curView, int level) {
    char szOut[2048];
    strcpy(szOut, "");

    for (int i = 0; i < level * 2; i++) {
        sprintf(&szOut[strlen(szOut)], " ");
    }
    sprintf(&szOut[strlen(szOut)], "%s @ 0x%08x ", object_getClassName(curView), (unsigned int)curView);

    if ([curView isHidden] || [curView alpha] <= 0.01f) {
        sprintf(&szOut[strlen(szOut)], " (hidden) ");
    }
    if (![curView isUserInteractionEnabled]) {
        sprintf(&szOut[strlen(szOut)], " (interaction disabled) ");
    }
    if ([curView isOpaque]) {
        sprintf(&szOut[strlen(szOut)], " (opaque) ");
    }
    if ([curView respondsToSelector:@selector(text)]) {
        id text = [curView text];
        sprintf(&szOut[strlen(szOut)], " (text=\"%s\") ", [text UTF8String]);
    }

    CGRect rect;
    rect = [curView frame];
    id fmt = [NSString stringWithFormat:@"{%f, %f}{%f, %f}\n", rect.origin.x, rect.origin.y, rect.size.width, rect.size.height];
    // sprintf(&szOut[strlen(szOut)], "{%f, %f}{%f, %f}\n", rect.origin.x, rect.origin.y, rect.size.width,
    // rect.size.height);
    EbrDebugLog("%s%s", szOut, [fmt UTF8String]);

    for (unsigned i = 0; i < [[curView subviews] count]; i++) {
        printViews([[curView subviews] objectAtIndex:i], level + 1);
    }
}

+ (void)_shutdownEvent {
    _doShutdown = TRUE;
    [[NSRunLoop mainRunLoop] _stop];
}

- (void)newMouseEvent {
    EbrInputEvent localEvents[256];
    int numEvents = GetMouseEvents(localEvents, 256);

    for (int curEvent = 0; curEvent < numEvents; curEvent++) {
        EbrInputEvent* evt = &localEvents[curEvent];

        if (evt->mouseEvent == keyPressed) {
            if (evt->type == 27) {
                [UIApplication _doBackAction];
                return;
            }
            [UIResponder keyPressed:evt->type];
            return;
        }

        /*
        int count = [windows count];
        for ( int i = 0; i < count; i ++ ) {
        id curWindow = [windows objectAtIndex:i];
        printViews(curWindow, 1);
        }
        */

        static UITouch* touches[10];
        static NSMutableSet* allTouches;
        UITouch* newTouchEvent;

        int finger = evt->fingerCount;

        if (allTouches == nil) {
            allTouches = [[NSMutableSet set] retain];
        }

        switch (evt->mouseEvent) {
            case mouseDown: {
#ifndef WIN32
                assert(touches[finger] == nil);
#endif

                RecordTouch(evt->x, evt->y, evt->touchTime);
                int tapCount = GetTouchCount(evt->x, evt->y, evt->touchTime);
                touches[finger] = [[UITouch createWithPoint:CGPointMake(evt->x, evt->y) tapCount:tapCount] autorelease];
                [allTouches addObject:touches[finger]];
                newTouchEvent = touches[finger];

                UIEvent* touchTestEvent = [[UIEvent createWithTouches:allTouches touchEvent:newTouchEvent] autorelease];

                //  Figure out which view it's in
                id mouseView = nil;
                int count = [windows count];

                for (int i = count - 1; i >= 0; i--) {
                    id curWindow = [windows objectAtIndex:i];

                    CGPoint pos;

                    pos.x = evt->x;
                    pos.y = evt->y;

                    pos = [curWindow convertPoint:pos fromView:nil toView:curWindow];

                    mouseView = [curWindow hitTest:pos withEvent:touchTestEvent];
                    if (mouseView != nil && mouseView != curWindow) {
                        break;
                    }
                }

                if (mouseView != nil) {
                    EbrDebugLog("%s touched\n", object_getClassName(mouseView));
                }
                touches[finger]->inView = mouseView;
                [touches[finger]->inView retain];

                touches[finger]->phase = UITouchPhaseBegan;
                touches[finger]->timeStamp = evt->touchTime;
                touches[finger]->velocityX = evt->velocityX;
                touches[finger]->velocityY = evt->velocityY;
                touches[finger]->previousTouchX = touches[finger]->touchX;
                touches[finger]->previousTouchY = touches[finger]->touchY;
                touches[finger]->touchX = evt->x;
                touches[finger]->touchY = evt->y;
            } break;

            case mouseMove:
                assert(touches[finger] != nil);
                if (touches[finger] == nil) {
                    continue;
                }

                newTouchEvent = touches[finger];
                touches[finger]->phase = UITouchPhaseMoved;
                touches[finger]->timeStamp = evt->touchTime;
                touches[finger]->velocityX = evt->velocityX;
                touches[finger]->velocityY = evt->velocityY;
                touches[finger]->previousTouchX = touches[finger]->touchX;
                touches[finger]->previousTouchY = touches[finger]->touchY;
                touches[finger]->touchX = evt->x;
                touches[finger]->touchY = evt->y;
                break;

            case mouseUp: {
                // This code may be helpful for debugging gestures again later:
                /*
                static int count = 0;
                if ( count < 3 )
                ++count;
                else
                continue;
                */

                if (touches[finger] == nil) {
                    continue;
                }

                assert(touches[finger] != nil);
                newTouchEvent = touches[finger];
                touches[finger]->phase = UITouchPhaseEnded;
                touches[finger]->timeStamp = evt->touchTime;
                touches[finger]->velocityX = evt->velocityX;
                touches[finger]->velocityY = evt->velocityY;
                touches[finger]->previousTouchX = touches[finger]->touchX;
                touches[finger]->previousTouchY = touches[finger]->touchY;
                touches[finger]->touchX = evt->x;
                touches[finger]->touchY = evt->y;
                break;
            }

            default:
                assert(0);
                break;
        }

        UIEvent* touchEvent = [[UIEvent createWithTouches:allTouches touchEvent:newTouchEvent] autorelease];
        [touchEvent setTimestamp:evt->touchTime];

        //  Send off the UIEvent
        [self sendEvent:touchEvent];

        switch (evt->mouseEvent) {
            case mouseUp:
                [allTouches removeObject:touches[finger]];
                touches[finger] = nil;

                //  If all fingers come off the screen, reset all gestures
                resetAllTrackingGestures = TRUE;

                for (int i = 0; i < 10; i++) {
                    if (touches[i] != nil) {
                        resetAllTrackingGestures = FALSE;
                    }
                }

                if (resetAllTrackingGestures) {
                    for (UIGestureRecognizer* curgesture in currentlyTrackingGesturesList) {
                        [curgesture reset];
                    }

                    [currentlyTrackingGesturesList removeAllObjects];
                }
                break;
        }
    }
}

/**
 @Status Interoperable
*/
- (void)sendEvent:(UIEvent*)event {
    UITouch* touch = [event _touchEvent];
    SEL eventName;

    switch (touch->phase) {
        case UITouchPhaseBegan:
            eventName = @selector(touchesBegan:withEvent:);
            break;

        case UITouchPhaseMoved:
            eventName = @selector(touchesMoved:withEvent:);
            break;

        case UITouchPhaseEnded:
            eventName = @selector(touchesEnded:withEvent:);
            break;

        case UITouchPhaseCancelled:
            eventName = @selector(touchesCancelled:withEvent:);
            break;

        default:
            assert(0);
            break;
    }

    UIView* view = touch->inView;
    if (view == nil) {
        return;
    }
    bool process = true;

    UIView* views[128];
    int viewDepth = 0;
    if (resetAllTrackingGestures) {
        resetAllTrackingGestures = FALSE;
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
                    [currentlyTrackingGesturesList addObject:curgesture];
                }
            }
        }
    }

    viewDepth = 0;

    curGesturesDict = [NSMutableDictionary new];

    UIGestureRecognizer* recognizers[128];

    for (UIGestureRecognizer* curgesture in currentlyTrackingGesturesList) {
        recognizers[viewDepth++] = curgesture;

        id gestureClass = [curgesture class];
        NSMutableArray* arr = [curGesturesDict objectForKey:gestureClass];
        if (arr == nil) {
            arr = [NSMutableArray new];
            [curGesturesDict setObject:arr forKey:gestureClass];
            [arr release];
        }
        [arr addObject:curgesture];
    }

    for (int i = 0; i < viewDepth; i++) {
        UIGestureRecognizer* curgesture = recognizers[i];

        if ([curgesture state] != UIGestureRecognizerStateCancelled) {
            // EbrDebugLog("Checking gesture %s\n", object_getClassName(curgesture));
            id delegate = [curgesture delegate];
            BOOL send = TRUE;
            if (touch->phase == UITouchPhaseBegan && [delegate respondsToSelector:@selector(gestureRecognizer:shouldReceiveTouch:)]) {
                send = [delegate gestureRecognizer:curgesture shouldReceiveTouch:touch];
            }

            if (send) {
                [curgesture performSelector:eventName withObject:[NSMutableSet setWithObject:touch] withObject:event];
            }
        }
    }

    //  Process all gestures
    id gesturesPriority[] = {[UIPinchGestureRecognizer class],
                             [UISwipeGestureRecognizer class],
                             [UIPanGestureRecognizer class],
                             [UITapGestureRecognizer class] };
    int numGestureTypes = 4;

    for (int i = 0; i < numGestureTypes; i++) {
        id curgestureClass = gesturesPriority[i];
        id gestures = [curGesturesDict objectForKey:curgestureClass];
        if ([curgestureClass _fireGestures:gestures]) {
            process = false;
        }
    }

    //  Removed/reset failed/done gestures
    for (int i = 0; i < viewDepth; i++) {
        UIGestureRecognizer* curgesture = recognizers[i];
        UIGestureRecognizerState state = (UIGestureRecognizerState)[curgesture state];

        if (state == UIGestureRecognizerStateRecognized || state == UIGestureRecognizerStateEnded ||
            state == UIGestureRecognizerStateFailed || state == UIGestureRecognizerStateCancelled) {
            [curgesture reset];
            EbrDebugLog("Removing gesture %s %x state=%d\n", object_getClassName(curgesture), curgesture, state);
            [currentlyTrackingGesturesList removeObject:curgesture];
            id gesturesArr = [curGesturesDict objectForKey:[curgesture class]];
            [gesturesArr removeObject:curgesture];
        }
    }

    [curGesturesDict release];
    curGesturesDict = nil;

    if (process == false) {
        touch->phase = UITouchPhaseCancelled;
        eventName = @selector(touchesCancelled:withEvent:);
    }

    if (touch->phase != UITouchPhaseBegan && ![view->priv->currentTouches containsObject:touch]) {
        // EbrDebugLog("View not aware of touch, ignoring\n");
        return;
    }

    if (touch->phase == UITouchPhaseBegan && ignoringInteractionEvents > 0) {
        EbrDebugLog("Global interaction disabled, ignoring\n");
        return;
    }

    if (touch->phase == UITouchPhaseBegan && !view->priv->multipleTouchEnabled) {
        if ([view->priv->currentTouches count] > 0) {
            EbrDebugLog("View already has a touch, ignoring\n");
            return;
        }
    }

    NSMutableSet* touches;
    if (touch->phase == UITouchPhaseBegan) {
        [view->priv->currentTouches addObject:touch];
        touches = [NSMutableSet setWithObject:touch];
    } else if (touch->phase == UITouchPhaseEnded || touch->phase == UITouchPhaseCancelled) {
        touches = [NSMutableSet setWithObject:touch];
        [view->priv->currentTouches removeObject:touch];
    } else {
        touches = [NSMutableSet setWithArray:view->priv->currentTouches];
    }

    [view performSelector:eventName withObject:touches withObject:event];
}

/**
 @Status Stub
*/
- (BOOL)openURL:(NSURL*)url {
    UNIMPLEMENTED();
    NSString* scheme = [url scheme];
    if ([scheme isEqualToString:@"fbauth"]) {
        return FALSE;
    }
    if ([scheme isEqualToString:@"http"] || [scheme isEqualToString:@"https"] || [scheme isEqualToString:@"mailto"]) {
        EbrOpenURL((char*)[[url absoluteString] UTF8String]);
        return TRUE;
    } else {
        id delegate = [self delegate];

        if ([delegate respondsToSelector:@selector(application:handleOpenURL:)]) {
            EbrDebugLog("Sending URL %x to %x\n", url, delegate);
            return [delegate application:self handleOpenURL:url];
        }
    }

    return FALSE;
}

/**
 @Status Stub
*/
- (BOOL)canOpenURL:(NSURL*)url {
    UNIMPLEMENTED();
    EbrDebugLog("UIApplication: Can open URL %s?\n", [[url absoluteString] UTF8String]);
    NSString* scheme = [url scheme];
    if ([scheme isEqualToString:@"http"] || [scheme isEqualToString:@"https"]) {
        return TRUE;
    }

    return FALSE;
}

/**
 @Status Stub
*/
- (void)setNetworkActivityIndicatorVisible:(BOOL)visible {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setApplicationSupportsShakeToEdit:(BOOL)supports {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)registerForRemoteNotificationTypes:(unsigned)types {
    UNIMPLEMENTED();
    [self registerForRemoteNotificationTypes:types withId:@"309806373466"];
}

/**
 @Status Stub
*/
- (void)registerForRemoteNotificationTypes:(unsigned)types withId:(id)identifier {
    UNIMPLEMENTED();
#ifdef SUPPORT_REMOTE_NOTIFICATIONS
    EbrRegisterForRemoteNotifications(identifier);
#endif
}

/**
 @Status Interoperable
*/
- (BOOL)sendAction:(SEL)action to:(id)target from:(id)sender forEvent:(UIEvent*)forEvent {
    UIResponder* curTarget = target;

    if (curTarget == nil) {
        curTarget = _curFirstResponder;
    }

    while (curTarget != nil) {
        if ([curTarget respondsToSelector:action]) {
            _m(curTarget, action, sender, forEvent);
            return TRUE;
        }
        curTarget = [curTarget nextResponder];
    }

    return FALSE;
}

- (void)setSceneViewController:(UIViewController*)controller {
    static bool set = false;

    if (!set) {
        set = true;
        [self performSelector:@selector(_showScene:) withObject:controller afterDelay:0.0];
    }
}

/**
 @Status Stub
*/
- (UIBackgroundTaskIdentifier)beginBackgroundTaskWithExpirationHandler:(void (^)())handler {
    UNIMPLEMENTED();
    EbrDebugLog("beginBackgroundTaskWithExpirationHandler not supported\n");
    return 0;
}

/**
 @Status Stub
*/
- (double)backgroundTimeRemaining {
    UNIMPLEMENTED();
    return 60.0 * 5;
}

/**
 @Status Stub
*/
- (void)endBackgroundTask:(UIBackgroundTaskIdentifier)handler {
    UNIMPLEMENTED();
    EbrDebugLog("endBackgroundTask not supported\n");
}

- (void)_showScene:(UIViewController*)controller {
    //[[self _popupWindow] setRootViewController:controller];
}

/**
 @Status Interoperable
*/
- (NSArray*)windows {
    return windows;
}

/**
 @Status Interoperable
*/
- (UIWindow*)keyWindow {
    return _curKeyWindow;
}

- (instancetype)init {
    windows = (id)CFArrayCreateMutable(NULL, 32, NULL);

    if (statusBar == nil) {
        CGRect frame;
        frame.origin.x = 0.0f;
        frame.origin.y = 0.0f;
        frame.size.width = GetCACompositor()->screenWidth();
        frame.size.height = statusBarHeight;
        statusBar = [[UIImageView alloc] initWithFrame:frame];
        [statusBar setImage:[UIImage imageNamed:@"/img/StatusBar.png"]];
        [statusBar setAutoresizingMask:UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleBottomMargin];

        frame.size.height = GetCACompositor()->screenHeight();
        statusBarRotationLayer = [[UIView alloc] initWithFrame:frame];
        [statusBarRotationLayer addSubview:statusBar];
        popupRotationLayer = [[UIKeyboardRotationView alloc] initWithFrame:frame];

#ifdef NO_STATUSBAR
        windowInsetLeft = 0.0f;
        windowInsetRight = 0.0f;
        windowInsetTop = statusBarHeight;
        windowInsetBottom = 0.0f;
        g_bDidChangeView = true;
#endif

        CALayer* layer = [statusBarRotationLayer layer];
        [layer validateDisplayHierarchy];
        GetCACompositor()->setNodeTopMost((DisplayNode*)[layer _presentationNode], true);
        [CATransaction _addSublayerToTop:layer];
        GetCACompositor()->setNodeTopMost((DisplayNode*)[[popupRotationLayer layer] _presentationNode], true);
        GetCACompositor()->setNodeTopMost((DisplayNode*)[[statusBarRotationLayer layer] _presentationNode], true);
    }

    _curNotifications = [NSMutableArray new];

    return self;
}

- (UIView*)_statusBarInternal {
    return statusBar;
}

/**
 @Status Interoperable
*/
- (BOOL)isStatusBarHidden {
    return statusBarHidden;
}

/**
 @Status Interoperable
*/
- (void)beginIgnoringInteractionEvents {
    ignoringInteractionEvents++;
}

/**
 @Status Stub
*/
- (void)beginReceivingRemoteControlEvents {
    UNIMPLEMENTED();
}

- (void)endReceivingRemoteControlEvents {
}

/**
 @Status Interoperable
*/
- (void)endIgnoringInteractionEvents {
    if (ignoringInteractionEvents > 0) {
        ignoringInteractionEvents--;
    }
}

/**
 @Status Interoperable
*/
- (BOOL)isIgnoringInteractionEvents {
    return ignoringInteractionEvents > 0;
}

/**
 @Status Stub
*/
- (double)statusBarOrientationAnimationDuration {
    UNIMPLEMENTED();
    return 0.4;
}

/**
 @Status Interoperable
*/
- (CGRect)statusBarFrame {
    CGRect ret;

    memset(&ret, 0, sizeof(CGRect));

    switch (_curOrientation) {
        case UIInterfaceOrientationLandscapeRight:
            ret.origin.x = GetCACompositor()->screenWidth() - statusBarHeight;
            ret.origin.y = 0.0f;
            ret.size.width = statusBarHeight;
            ret.size.height = GetCACompositor()->screenHeight();
            break;

        case UIInterfaceOrientationPortrait:
            ret.origin.x = 0.0f;
            ret.origin.y = 0.0f;
            ret.size.width = GetCACompositor()->screenWidth();
            ret.size.height = statusBarHeight;
            break;

        case UIInterfaceOrientationLandscapeLeft:
            ret.origin.x = 0.0f;
            ret.origin.y = 0.0f;
            ret.size.width = statusBarHeight;
            ret.size.height = GetCACompositor()->screenHeight();
            break;

        case UIInterfaceOrientationPortraitUpsideDown:
            ret.origin.x = 0.0f;
            ret.origin.y = GetCACompositor()->screenHeight() - statusBarHeight;
            ret.size.width = GetCACompositor()->screenWidth();
            ret.size.height = statusBarHeight;
            break;
    }

    return ret;
}

- (UIWindow*)_popupWindow {
    static BOOL building = false;
    if (popupWindow == nil && building == FALSE) {
        building = TRUE;

        CGRect popupRect;

        popupRect.origin.x = 0;
        popupRect.origin.y = 0;
        popupRect.size.width = GetCACompositor()->screenWidth();
        popupRect.size.height = GetCACompositor()->screenHeight();

        popupWindow = [[UIWindow alloc] initWithContentRect:popupRect];
        [popupWindow setWindowLevel:100000.0f];
        [popupWindow addSubview:popupRotationLayer];
        building = false;
    }

    return popupWindow;
}

- (UIView*)_popupLayer {
    return popupRotationLayer;
}

/**
 @Status Stub
*/
- (int)applicationIconBadgeNumber {
    UNIMPLEMENTED();
    return 0;
}

/**
 @Status Stub
*/
- (NSArray*)scheduledLocalNotifications {
    UNIMPLEMENTED();
    return _curNotifications;
}

/**
 @Status Stub
*/
- (unsigned)enabledRemoteNotificationTypes {
    UNIMPLEMENTED();
    return 0;
}

/**
 @Status Stub
*/
- (void)cancelAllLocalNotifications {
    UNIMPLEMENTED();
    int count = [_curNotifications count];
    while (count > 0) {
        id object = [_curNotifications objectAtIndex:count - 1];
        [object _cancelAlarm];
        [_curNotifications removeLastObject];
        --count;
    }
}

/**
 @Status Stub
*/
- (void)cancelLocalNotification:(UILocalNotification*)notification {
    UNIMPLEMENTED();
    [notification _cancelAlarm];
    int idx = [_curNotifications indexOfObject:notification];
    if (idx != NSNotFound) {
        [_curNotifications removeObjectAtIndex:idx];
    }
}

/**
 @Status Stub
*/
- (void)presentLocalNotificationNow:(UILocalNotification*)notification {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (UIApplicationState)applicationState {
    return _applicationState;
}

static void WarnViewControllers(UIView* subview) {
    id controller = [UIViewController controllerForView:subview];
    if ([controller respondsToSelector:@selector(didReceiveMemoryWarning)]) {
        [controller didReceiveMemoryWarning];
    }

    NSArray* subviews = [subview subviews];
    for (UIView* curSubview in subviews) {
        WarnViewControllers(curSubview);
    }
}

- (void)_sendToBackground {
    id delegate = [self delegate];

    //  For devices with <= 512mb of memory, send a memory warning
    //  so that the app will release as much memory as possible
    uint64_t totalMemory = [UIDevice _deviceTotalMemory];
    if (totalMemory <= 512 * 1024 * 1024) {
        if ([delegate respondsToSelector:@selector(applicationDidReceiveMemoryWarning:)]) {
            [delegate applicationDidReceiveMemoryWarning:self];
        }
        if ([windows count] > 0) {
            int windowCount = [windows count];

            for (int i = 0; i < windowCount; i++) {
                id window = [windows objectAtIndex:i];
                WarnViewControllers(window);
            }
        }
    }

    if ([delegate respondsToSelector:@selector(applicationWillResignActive:)]) {
        [delegate applicationWillResignActive:self];
    }
    [[NSNotificationCenter defaultCenter] postNotificationName:@"UIApplicationWillResignActiveNotification" object:self];
    EbrPauseSound();

    if ([windows count] > 0) {
        int windowCount = [windows count];

        for (int i = 0; i < windowCount; i++) {
            id window = [windows objectAtIndex:i];
            id windowLayer = [window layer];
            [windowLayer discardDisplayHierarchy];
        }

        GetCACompositor()->ProcessTransactions();
    }
    _applicationState = UIApplicationStateBackground;
    _drawingAllowed = false;
    if ([delegate respondsToSelector:@selector(applicationDidEnterBackground:)]) {
        [delegate applicationDidEnterBackground:self];
    }
    [[NSNotificationCenter defaultCenter] postNotificationName:@"UIApplicationDidEnterBackgroundNotification" object:self];
    EbrEventSignal(_applicationStateChanged);
}

- (void)_bringToForeground:(NSURL*)url {
    EbrResumeSound();
    id delegate = [self delegate];
    if ([delegate respondsToSelector:@selector(applicationWillEnterForeground:)]) {
        [delegate applicationWillEnterForeground:self];
    }
    [[NSNotificationCenter defaultCenter] postNotificationName:@"UIApplicationWillEnterForegroundNotification" object:self];

    _applicationState = UIApplicationStateActive;
    EbrDebugLog("Bringing to foreground with: %x\n", url);
    if (url != nil) {
        [UIApplication _launchedWithURL:url];
    }

    if ([delegate respondsToSelector:@selector(applicationDidBecomeActive:)]) {
        [delegate applicationDidBecomeActive:self];
    }
    [[NSNotificationCenter defaultCenter] postNotificationName:@"UIApplicationDidBecomeActiveNotification" object:self];
}

static void layoutBlankView(UIView* inputView, UIView* accessoryView, float totalHeight) {
    if (totalHeight > 0) {
        CGRect statusRect;
        statusRect = [popupRotationLayer bounds];

        CGRect accessorySize = { 0 };
        if (_curKeyboardAccessory != accessoryView) {
            [_curKeyboardAccessory removeFromSuperview];
            _curKeyboardAccessory = accessoryView;
            if (_curKeyboardAccessory != nil) {
                [_blankView addSubview:_curKeyboardAccessory];
            }
        }

        if (_curKeyboardAccessory != nil) {
            accessorySize = [_curKeyboardAccessory bounds];
            accessorySize.origin.x = 0;
            accessorySize.origin.y = 0;
            accessorySize.size.width = statusRect.size.width;
            [_curKeyboardAccessory setFrame:accessorySize];
        }

        if (_curKeyboardInputView != inputView) {
            [_curKeyboardInputView removeFromSuperview];
            _curKeyboardInputView = inputView;
            if (_curKeyboardInputView != nil) {
                [_blankView addSubview:_curKeyboardInputView];
            }
        }

        if (_curKeyboardInputView != nil) {
            CGRect keyboardRect = { 0, accessorySize.size.height, statusRect.size.width, totalHeight - accessorySize.size.height };
            [_curKeyboardInputView setFrame:keyboardRect];
        }
    } else {
        [_curKeyboardAccessory removeFromSuperview];
        _curKeyboardAccessory = nil;
        [_curKeyboardInputView removeFromSuperview];
        _curKeyboardInputView = nil;
    }
}

//  Brings up the blank keyboard view to the specified height
//  and fires off any events associated with it - including
//  keyboard hide events
static void animateKeyboardResize(id self, float newHeight, bool forceKeyboardAppearance) {
    CGRect statusRect;
    statusRect = [popupRotationLayer bounds];

    CGRect startRect, endRect;

    if (newHeight > 0) {
        if (!blankViewUp) {
            //  Blank view is not onscreen
            startRect.origin.x = 0.0f;
            startRect.origin.y = statusRect.size.height;
            startRect.size.width = statusRect.size.width;
            startRect.size.height = newHeight;

            endRect.origin.x = 0.0f;
            endRect.origin.y = statusRect.size.height - newHeight;
            endRect.size.width = statusRect.size.width;
            endRect.size.height = newHeight;
        } else {
            //  Blank view is already on screen but is being resized
            startRect.origin.x = 0.0f;
            startRect.origin.y = statusRect.size.height - curBlankViewHeight;
            startRect.size.width = statusRect.size.width;
            startRect.size.height = curBlankViewHeight;

            endRect.origin.x = 0.0f;
            endRect.origin.y = statusRect.size.height - newHeight;
            endRect.size.width = statusRect.size.width;
            endRect.size.height = newHeight;
        }
    } else {
        //  Keyboard is being hidden
        if (!blankViewUp) {
            //  Blank view is not onscreen
            return;
        } else {
            //  Blank view is on screen
            startRect.origin.x = 0.0f;
            startRect.origin.y = statusRect.size.height - curBlankViewHeight;
            startRect.size.width = statusRect.size.width;
            startRect.size.height = curBlankViewHeight;

            endRect.origin.x = 0.0f;
            endRect.origin.y = statusRect.size.height;
            endRect.size.width = statusRect.size.width;
            endRect.size.height = curBlankViewHeight;
        }
    }

    CGRect mappedStart, mappedEnd;
    mappedStart = [[self _popupWindow] convertRect:startRect fromView:popupRotationLayer];
    mappedEnd = [[self _popupWindow] convertRect:endRect fromView:popupRotationLayer];

    [_blankView setFrame:startRect];
    [popupRotationLayer addSubview:_blankView];

    [UIView beginAnimations:@"ResizeAnimation" context:nil];

    if (newHeight <= 0) {
        //  Keyboard is being hidden
        [UIView setAnimationDelegate:self];
        [UIView setAnimationDidStopSelector:@selector(_keyboardDismissed)];
    }
    [_blankView setFrame:endRect];
    [UIView commitAnimations];

    [popupWindow bringSubviewToFront:popupRotationLayer];

    CGRect keyboardBounds;
    keyboardBounds.origin.x = 0.0f;
    keyboardBounds.origin.y = 0.0f;
    keyboardBounds.size = endRect.size;

    CGPoint centerBegin, centerEnd;

    centerBegin.x = mappedStart.origin.x + mappedStart.size.width / 2.0f;
    centerBegin.y = mappedStart.origin.y + mappedStart.size.height / 2.0f;

    centerEnd.x = mappedEnd.origin.x + mappedEnd.size.width / 2.0f;
    centerEnd.y = mappedEnd.origin.y + mappedEnd.size.height / 2.0f;

    // Fire the notification:
    id keys[7] =
    { @"UIKeyboardFrameEndUserInfoKey",
      @"UIKeyboardFrameBeginUserInfoKey",
      @"UIKeyboardAnimationDurationUserInfoKey",
      @"UIKeyboardAnimationCurveUserInfoKey",
      @"UIKeyboardBoundsUserInfoKey",
      @"UIKeyboardCenterBeginUserInfoKey",
      @"UIKeyboardCenterEndUserInfoKey",
    };
    id values[7] = {
        [NSValue valueWithCGRect:mappedEnd],  [NSValue valueWithCGRect:mappedStart],    [NSNumber numberWithDouble:0.25],
        [NSNumber numberWithInt:0],           [NSValue valueWithCGRect:keyboardBounds], [NSValue valueWithCGPoint:centerBegin],
        [NSValue valueWithCGPoint:centerEnd],
    };

    id dict = [NSDictionary dictionaryWithObjects:values forKeys:keys count:7];

    static float oldHeight = 0;

    if (newHeight > 0) {
        if (!blankViewUp || forceKeyboardAppearance) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"UIKeyboardWillShowNotification" object:nil userInfo:dict];
            [[NSNotificationCenter defaultCenter] postNotificationName:@"UIKeyboardDidShowNotification" object:nil userInfo:dict];
        }
        if (!blankViewUp) {
            EbrOnShowKeyboardInternal();
        } else {
            if (oldHeight != newHeight) {
                [[NSNotificationCenter defaultCenter] postNotificationName:@"UIKeyboardWillChangeFrameNotification"
                                                                    object:nil
                                                                  userInfo:dict];
                [[NSNotificationCenter defaultCenter] postNotificationName:@"UIKeyboardDidChangeFrameNotification"
                                                                    object:nil
                                                                  userInfo:dict];
            }
        }
    } else {
        //  Keyboard is being hidden
        [[NSNotificationCenter defaultCenter] postNotificationName:@"UIKeyboardWillHideNotification" object:nil userInfo:dict];
        [[NSNotificationCenter defaultCenter] postNotificationName:@"UIKeyboardDidHideNotification" object:nil userInfo:dict];
        EbrOnHideKeyboardInternal();
    }
    oldHeight = newHeight;

    if (newHeight > 0) {
        blankViewUp = true;
    } else {
        blankViewUp = false;
    }
    curBlankViewHeight = newHeight;
}

// The textfield the keyboard is for has changed state and we need to figure out what to do:
- (id)_keyboardChanged {
    doEvaluateKeyboard = true;
    [[NSRunLoop mainRunLoop] _wakeUp];
    return self;
}

// The textfield the keyboard is for has changed state and we need to figure out what to do:
- (id)_evaluateKeyboard {
    evaluateKeyboard(self);
    return self;
}

static void evaluateKeyboard(id self) {
    [self _popupWindow];

    if (_blankView == nil) {
        CGRect frame = { 0 };
        _blankView = [[UIEmptyController alloc] initWithFrame:frame];
        [_blankView setBackgroundColor:[UIColor blackColor]];
        [_blankView setAutoresizesSubviews:FALSE];
    }

    // Figure out what's going on with our first responder:
    id keyboardAccessory = nil, inputView = nil;
    id curResponder = _curFirstResponder;
    showKeyboardType = 0;

    while (curResponder != nil) {
        if ([curResponder respondsToSelector:@selector(keyboardType)]) {
            showKeyboardType = [curResponder keyboardType];
        }

        //  Special case: keyboard accessory is first responder
        if (curResponder == _curKeyboardAccessory) {
            keyboardAccessory = curResponder;
            break;
        }

        inputView = [curResponder inputView];
        keyboardAccessory = [curResponder inputAccessoryView];
        if (inputView != nil || keyboardAccessory != nil) {
            break;
        }

        curResponder = [curResponder nextResponder];
    }

    float totalBlankViewHeight = 0.0f;

    if (inputView) {
        //  We have an overridden keyboard view - force the
        //  physical keyboard to be hidden
        forceHideKeyboard = 1;
        keyboardBaseHeight = 200;

        if ([inputView autoresizingMask] & UIViewAutoresizingFlexibleHeight) {
            totalBlankViewHeight += keyboardBaseHeight;
        } else {
            CGRect bounds;
            bounds = [inputView bounds];
            keyboardBaseHeight = bounds.size.height;
            totalBlankViewHeight += keyboardBaseHeight;
        }
    } else {
        //  The physical keyboard might be displayed
        forceHideKeyboard = 0;
        if (showKeyboard > 0) {
            totalBlankViewHeight += keyboardPhysicalHeight;
        }

        if (showKeyboard > 0 && keyboardVisible == false) {
            //  We don't want to display the keyboard accessory if
            //  the hardware keyboard hasn't actually popped up
            //  yet - we want both the accessory and the physical
            //  keyboard to be shown at once, so lets return, allow
            //  the keyboard to come up, which will call us again
            //  with the actual height of the keyboard
            return;
        }
    }

    CGRect accessorySize;
    if (keyboardAccessory != nil) {
        if (totalBlankViewHeight > 0) {
            accessorySize = [keyboardAccessory bounds];
            totalBlankViewHeight += accessorySize.size.height;
        }
    }

    //  Special case: send
    static id lastAccessory = nil;

    animateKeyboardResize(self, totalBlankViewHeight, lastAccessory != keyboardAccessory);
    lastAccessory = keyboardAccessory;
    layoutBlankView(inputView, keyboardAccessory, totalBlankViewHeight);
}

- (void)_keyboardDismissed {
    [_blankView removeFromSuperview];
}

- (void)_newEditText:(NSString*)text {
    int len = [text length];
    WORD* chars = (WORD*)EbrCalloc(2, len);
    [text getCharacters:chars range:NSMakeRange(0, len)];

    for (int i = 0; i < len; i++) {
        [UIResponder keyPressed:chars[i]];
    }
    EbrFree(chars);
}

- (void)_editTextDelete:(NSNumber*)numBefore {
    [UIResponder _deleteRange:numBefore];
}

- (void)_didRegisterForRemoteNotification:(NSData*)tokenData {
#ifndef SUPPORT_REMOTE_NOTIFICATIONS
    return;
#endif
    NSString* str = [[NSString alloc] initWithData:tokenData encoding:NSUTF8StringEncoding];
    EbrDebugLog("Received token: %s\n", [str UTF8String]);

    if ([_delegate respondsToSelector:@selector(application:didRegisterForRemoteNotificationsWithDeviceToken:)]) {
        [_delegate application:self didRegisterForRemoteNotificationsWithDeviceToken:tokenData];
    }

    /*
    id errStr = [NSString stringWithFormat:@"Registered - token = \"%@\"", str];
    id alertView = [[UIAlertView alloc] initWithTitle:@"GCM Registration Succeeded" message:errStr delegate:nil
    defaultButton:@"Ok" cancelButton:nil otherButtons:nil];
    [alertView show];
    [alertView release];
    [str release];
    */
}

- (void)_didFailRegisterForRemoteNotification:(id)error {
#ifndef SUPPORT_REMOTE_NOTIFICATIONS
    return;
#endif
    /*
    id errStr = [NSString stringWithFormat:@"Error - %@", error];
    id alertView = [[UIAlertView alloc] initWithTitle:@"GCM Registration Failed" message:errStr delegate:nil
    defaultButton:@"Ok" cancelButton:nil otherButtons:nil];
    [alertView show];
    [alertView release];
    */
}

- (void)_didReceiveRemoteNotification:(NSData*)data {
#ifndef SUPPORT_REMOTE_NOTIFICATIONS
    return;
#endif

    /*
    id str = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
    id errStr = [NSString stringWithFormat:@"Data = \"%@\"", str];
    id alertView = [[UIAlertView alloc] initWithTitle:@"GCM Message Received" message:errStr delegate:nil
    defaultButton:@"Ok" cancelButton:nil otherButtons:nil];
    [alertView show];
    [alertView release];
    [str release];
    */

    id obj = [NSJSONSerialization JSONObjectWithData:data options:0 error:NULL];

    EbrDebugLog("Type is: %s\n", object_getClassName(obj));
    EbrDebugLog("Received notification: %s\n", [[obj description] UTF8String]);

    if ([_delegate respondsToSelector:@selector(application:didReceiveRemoteNotification:)]) {
        [_delegate application:self didReceiveRemoteNotification:obj];
    }
}

+ (void)setStarboardInternalLoggingLevel:(int)level {
    if (level > 0) {
        g_logErrors = true;
    } else {
        g_logErrors = false;
    }
}

- (void)__showOptions {
    [_UISettings showSettings];
}

/**
 @Status Caveat
 @Notes WinObjC extension
*/
+ (WOCDisplayMode*)displayMode {
    static WOCDisplayMode* ret = nil;
    if (ret == nil) {
        ret = [WOCDisplayMode new];
    }

    return ret;
}
@end

struct Record {
    Record() {
    }
    Record(const CGPoint& pos, double timestamp) : pos(pos), timestamp(timestamp) {
    }

    CGPoint pos;
    double timestamp;
};

static RingBuffer<Record, 50> _touchHistory[10];

static CGPoint findLastSpeed(int finger, float time) {
    double endTime = _touchHistory[finger].fromEnd(0).timestamp;
    CGPoint curPos = _touchHistory[finger].fromEnd(0).pos;
    double curTime = endTime;
    bool gotRecord = false; //  Get at least one record
    CGPoint ret = { 0, 0 };
    float numRet = 0.0f;

    bool distanceSatisfied = false;

    size_t i = 1;
    for (; i < _touchHistory[finger].size(); ++i) {
        double timestamp = _touchHistory[finger].fromEnd(i).timestamp;
        CGPoint pos = _touchHistory[finger].fromEnd(i).pos;
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
                if ((curPos - pos).lenGe(5.0f)) {
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

#define MAX_MOUSE_EVENTS 1024
static EbrInputEvent g_MouseEventsQueue[MAX_MOUSE_EVENTS];
static int g_MouseEventsHead = 0, g_MouseEventsTail = 0;

EbrLock g_MouseCrit = EBRLOCK_INITIALIZE;
extern EbrEvent g_NewMouseEvent;

void AddMouseEvent(EbrInputEvent* pEvt) {
    EbrLockEnter(g_MouseCrit);

    bool add = true;
    CGPoint pos = CGPoint::point(pEvt->x, pEvt->y);

    switch (pEvt->mouseEvent) {
        case mouseDown: {
            pEvt->velocityX = 0.0f;
            pEvt->velocityY = 0.0f;
            _touchHistory[pEvt->fingerCount].reset();
            _touchHistory[pEvt->fingerCount].add(Record(pos, pEvt->touchTime));
        } break;

        case mouseMove: {
            _touchHistory[pEvt->fingerCount].add(Record(pos, pEvt->touchTime));
            CGPoint velocity = findLastSpeed(pEvt->fingerCount, 0.1f);
            pEvt->velocityX = velocity.x;
            pEvt->velocityY = velocity.y;
        } break;

        case mouseUp: {
            _touchHistory[pEvt->fingerCount].add(Record(pos, pEvt->touchTime));
            CGPoint velocity = findLastSpeed(pEvt->fingerCount, 0.1f);
            pEvt->velocityX = velocity.x;
            pEvt->velocityY = velocity.y;
        } break;
    }

    if (add) {
        memcpy(&g_MouseEventsQueue[g_MouseEventsHead], pEvt, sizeof(EbrInputEvent));
        g_MouseEventsHead = (g_MouseEventsHead + 1) % (MAX_MOUSE_EVENTS);
        if (g_MouseEventsHead == g_MouseEventsTail) {
            assert(0); //  Queue overflow
        }
    }

    EbrLockLeave(g_MouseCrit);
    EbrEventSignal(g_NewMouseEvent);
}

int GetMouseEvents(EbrInputEvent* pDest, int max) {
    int ret = 0;
    EbrInputEvent* fingerMoves[10] = { 0 };

    EbrLockEnter(g_MouseCrit);

    while (max--) {
        if (g_MouseEventsTail != g_MouseEventsHead) {
            EbrInputEvent curEvent;

            memcpy(&curEvent, &g_MouseEventsQueue[g_MouseEventsTail], sizeof(EbrInputEvent));
            if (curEvent.mouseEvent == mouseMove) {
                int finger = curEvent.fingerCount;
                if (fingerMoves[finger] == NULL) {
                    memcpy(pDest, &g_MouseEventsQueue[g_MouseEventsTail], sizeof(EbrInputEvent));
                    fingerMoves[finger] = pDest;
                    pDest++;
                    ret++;
                } else {
                    memcpy(fingerMoves[finger], &g_MouseEventsQueue[g_MouseEventsTail], sizeof(EbrInputEvent));
                }
            } else {
                memcpy(pDest, &g_MouseEventsQueue[g_MouseEventsTail], sizeof(EbrInputEvent));
                pDest++;
                ret++;
            }
            g_MouseEventsTail = (g_MouseEventsTail + 1) % (MAX_MOUSE_EVENTS);
        } else {
            break;
        }
    }

    EbrLockLeave(g_MouseCrit);

    return ret;
}

void AddMouseEvent(EbrInputEvent* pEvt);

void UIQueueKeyInput(int key) {
    EbrInputEvent localEvt;
    EbrInputEvent* evt = &localEvt;

    memset(evt, 0, sizeof(EbrInputEvent));

    evt->mouseEvent = keyPressed;
    evt->type = key;

    AddMouseEvent(evt);
}

double microStartEpoch;
int64_t microEpoch;

#define EVENT_DOWN 0x64
#define EVENT_MOVE 0x65
#define EVENT_UP 0x66

#define MAXPOINTS 10
static int idLookup[MAXPOINTS] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };

int GetContactIndex(int dwID) {
    for (int i = 0; i < MAXPOINTS; i++) {
        if (idLookup[i] == dwID) {
            return i;
        }
    }

    return -1;
}

int AddContactIndex(int dwID) {
    for (int i = 0; i < MAXPOINTS; i++) {
        if (idLookup[i] == -1) {
            idLookup[i] = dwID;
            return i;
        }
    }

    printf("Out of contact points!\n");

    return -1;
}

void UIQueueTouchInput(
    float x, float y, int fingerID, int eventType, float surfaceWidth, float surfaceHeight, int64_t eventTime, bool bLandscape) {
    int touchID = 0;

    if (eventType == EVENT_DOWN) {
        touchID = AddContactIndex(fingerID);
    } else {
        touchID = GetContactIndex(fingerID);
    }
    if (touchID == -1) {
        return;
    }

    EbrInputEvent evt;

    float viewWidth = bLandscape ? GetCACompositor()->screenHeight() : GetCACompositor()->screenWidth();
    float viewHeight = bLandscape ? GetCACompositor()->screenWidth() : GetCACompositor()->screenHeight();

    float aspectX = (float)surfaceWidth / (float)(viewWidth - (windowInsetLeft + windowInsetRight));
    float aspectY = (float)surfaceHeight / (float)(viewHeight - (windowInsetTop + windowInsetBottom));

    float aspect = aspectX < aspectY ? aspectX : aspectY;

    float outWidth = (viewWidth - (windowInsetLeft + windowInsetRight)) * aspect;
    float outHeight = (viewHeight - (windowInsetTop + windowInsetBottom)) * aspect;

    float leftX = ((float)surfaceWidth - outWidth) / 2.0f;
    float topY = ((float)surfaceHeight - outHeight) / 2.0f;

    x -= leftX;
    y -= topY;

    if (bLandscape) {
        float tmp = x;
        x = outHeight - y;
        y = tmp;
        x = x * GetCACompositor()->screenWidth() / outHeight;
        y = y * GetCACompositor()->screenHeight() / outWidth;
    } else {
        x = x * GetCACompositor()->screenWidth() / outWidth;
        y = y * GetCACompositor()->screenHeight() / outHeight;
    }

    if (x < 0.0f) {
        x = 0.0f;
    }
    if (x > GetCACompositor()->screenWidth()) {
        x = GetCACompositor()->screenWidth();
    }
    if (y < 0.0f) {
        y = 0.0f;
    }
    if (y > GetCACompositor()->screenHeight()) {
        y = GetCACompositor()->screenHeight();
    }

    evt.x = x;
    evt.y = y;
    evt.numPoints = 1;

    evt.fingerCount = touchID;
    evt.touchTime = (eventTime / 1000000000.0);

    switch (eventType) {
        case EVENT_DOWN:
            evt.mouseEvent = mouseDown;
            AddMouseEvent(&evt);
            break;

        case EVENT_UP:
            idLookup[touchID] = -1;
            evt.mouseEvent = mouseUp;
            AddMouseEvent(&evt);
            break;

        case EVENT_MOVE:
            evt.mouseEvent = mouseMove;
            AddMouseEvent(&evt);
            break;
    }
}

void UIRequestTransactionProcessing() {
    [UIApplication viewChanged];
}

void UIShutdown() {
    [UIApplication _shutdownEvent];
    [[NSRunLoop mainRunLoop] _wakeUp];
}

@implementation WOCDisplayMode {
    float _magnification;
    float _fixedWidth, _fixedHeight;
    double _fixedAspectRatio;
    BOOL _autoMagnification;
    BOOL _sizeUIWindowToFit;
    WOCOperationMode _operationMode;
    CGSize _windowSize;
    CGSize _hostScreenSize;
    float _hostScale;
    CGSize _hostScreenDpi;
    UIInterfaceOrientation _presentationTransform;
}
@synthesize magnification = _magnification;
@synthesize fixedWidth = _fixedWidth;
@synthesize fixedHeight = _fixedHeight;
@synthesize fixedAspectRatio = _fixedAspectRatio;
@synthesize autoMagnification = _autoMagnification;
@synthesize sizeUIWindowToFit = _sizeUIWindowToFit;
@synthesize operationMode = _operationMode;
@synthesize presentationTransform = _presentationTransform;

- (instancetype)init {
    _fixedWidth = 320.0f;
    _fixedHeight = 480.0f;
    _fixedAspectRatio = 0.0f;
    _magnification = 1.0f;
    _autoMagnification = TRUE;
    _sizeUIWindowToFit = TRUE;
    _operationMode = WOCOperationModePhone;
    _presentationTransform = UIInterfaceOrientationPortrait;
    return self;
}

- (void)_setWindowSize:(CGSize)size {
    _windowSize = size;
}

/**
 @Status Interoperable
*/
- (CGSize)currentSize {
    return CGSizeMake([self currentWidth], [self currentHeight]);
}

- (CGSize)_currentOrientationWindowSize {
    switch (_presentationTransform) {
        case UIInterfaceOrientationLandscapeLeft:
        case UIInterfaceOrientationLandscapeRight:
            return CGSizeMake(_windowSize.height, _windowSize.width);

        default:
            return CGSizeMake(_windowSize.width, _windowSize.height);
    }
}

- (float)currentWidth {
    if (_fixedAspectRatio > 0.0f) {
        float totalWidth = self._currentOrientationWindowSize.width / _magnification;
        float totalHeight = self._currentOrientationWindowSize.height / _magnification;

        float newWidth = totalWidth;
        float newHeight = totalWidth / _fixedAspectRatio;
        if (newHeight > totalHeight) {
            newWidth = totalHeight * _fixedAspectRatio;
            newHeight = totalHeight;
        }

        return round(newWidth);
    }

    if (_fixedWidth > 0) {
        return _fixedWidth;
    } else {
        if (_fixedHeight > 0 && _autoMagnification) {
            return round(self._currentOrientationWindowSize.width * _fixedHeight / self._currentOrientationWindowSize.height);
        } else {
            return round(self._currentOrientationWindowSize.width / _magnification);
        }
    }
}

- (float)currentHeight {
    if (_fixedAspectRatio > 0.0f) {
        float totalWidth = self._currentOrientationWindowSize.width / _magnification;
        float totalHeight = self._currentOrientationWindowSize.height / _magnification;

        float newWidth = totalWidth;
        float newHeight = totalWidth / _fixedAspectRatio;
        if (newHeight > totalHeight) {
            newWidth = totalHeight * _fixedAspectRatio;
            newHeight = totalHeight;
        }

        return round(newHeight);
    }

    if (_fixedHeight > 0) {
        return _fixedHeight;
    } else {
        if (_fixedWidth > 0 && _autoMagnification) {
            return round(self._currentOrientationWindowSize.height * _fixedWidth / self._currentOrientationWindowSize.width);
        } else {
            return round(self._currentOrientationWindowSize.height / _magnification);
        }
    }
}

/**
 @Status Interoperable
*/
- (float)currentMagnification {
    if (_autoMagnification) {
        //  Calculate magnification as a function of the screen width/height and aspect-fit it
        float width = [self currentWidth];
        float height = [self currentHeight];
        float aspectX = self._currentOrientationWindowSize.width / width;
        float aspectY = self._currentOrientationWindowSize.height / height;
        return aspectX > aspectY ? aspectY : aspectX;
    } else {
        //  Simply magnify the window as specified
        return _magnification;
    }
}

/**
 @Status Interoperable
*/
- (void)updateDisplaySettings {
    [self _updateDisplaySettings];
}

- (void)_updateDisplaySettings {
    [[NSNotificationCenter defaultCenter] postNotificationName:UIApplicationWillChangeDisplayModeNofication object:self];

    float newWidth = [self currentWidth];
    float newHeight = [self currentHeight];
    float newMagnification = [self currentMagnification];
    float newRotation = CACompositorRotationNone;

    switch (_presentationTransform) {
        case UIInterfaceOrientationPortraitUpsideDown:
            newRotation = CACompositorRotation180;
            break;

        case UIInterfaceOrientationLandscapeLeft:
            newRotation = CACompositorRotation90CounterClockwise;
            break;

        case UIInterfaceOrientationLandscapeRight:
            newRotation = CACompositorRotation90Clockwise;
            break;
    }

    GetCACompositor()->setScreenSize(newWidth, newHeight, newMagnification, newRotation);
    GetCACompositor()->setDeviceSize(newWidth, newHeight);

    //  Adjust size of all UIWindows
    if (_sizeUIWindowToFit) {
        CGRect curBounds;
        curBounds.origin.x = 0.0f;
        curBounds.origin.y = 0.0f;
        curBounds.size.width = newWidth;
        curBounds.size.height = newHeight;

        for (UIWindow* current in windows) {
            [current setFrame:curBounds];
        }

        [popupRotationLayer setFrame:curBounds];
        [UIApplication viewTreeChanged];
    }

    [[NSNotificationCenter defaultCenter] postNotificationName:UIApplicationDidChangeDisplayModeNofication object:self];
}

/**
 @Status Interoperable
*/
- (CGSize)hostWindowSize {
    return _windowSize;
}

- (CGSize)hostWindowSizePixels {
    return CGSizeMake(self._currentOrientationWindowSize.width * self.hostScreenScale,
                      self._currentOrientationWindowSize.height * self.hostScreenScale);
}

/**
 @Status Interoperable
*/
- (float)hostScreenScale {
    if (_hostScale == 0.0f) {
        _hostScale = ((float)[[WGDDisplayInformation getForCurrentView] resolutionScale]) / 100.0f;
    }
    return _hostScale;
}

/**
 @Status Interoperable
*/
- (CGSize)hostScreenSizePixels {
    CGSize screenSize = [self hostScreenSizePoints];
    return CGSizeMake(screenSize.width * self.hostScreenScale, screenSize.height * self.hostScreenScale);
}

/**
 @Status Interoperable
*/
- (CGSize)hostScreenSizePoints {
    if (_hostScreenSize.width == 0 || _hostScreenSize.height == 0) {
        _hostScreenSize = self._currentOrientationWindowSize;
    }

    return CGSizeMake(_hostScreenSize.width, _hostScreenSize.height);
}

/**
 @Status Interoperable
*/
- (CGSize)hostScreenSizeInches {
    CGSize sizePixels = self.hostScreenSizePixels;

    if (_hostScreenDpi.width == 0 || _hostScreenDpi.height == 0) {
        float dpiX = [WGDDisplayInformation getForCurrentView].logicalDpi;
        float dpiY = [WGDDisplayInformation getForCurrentView].logicalDpi;

        _hostScreenDpi.width = dpiX;
        _hostScreenDpi.height = dpiY;
    }
    return CGSizeMake(sizePixels.width / _hostScreenDpi.width, sizePixels.height / _hostScreenDpi.height);
}

/**
 @Status Interoperable
*/
- (float)hostScreenDiagonalInches {
    CGSize sizeInches = self.hostScreenSizeInches;
    return sqrt(sizeInches.width * sizeInches.width + sizeInches.height * sizeInches.height);
}

/**
 @Status Interoperable
*/
- (void)setDisplayPreset:(WOCDisplayPreset)mode {
    switch (mode) {
        case WOCDisplayPresetPhone320x480:
            self.fixedWidth = 320.0f;
            self.fixedHeight = 480.0f;
            self.fixedAspectRatio = 0.0f;
            self.magnification = 1.0f;
            break;

        case WOCDisplayPresetPhone320x568:
            self.fixedWidth = 320.0f;
            self.fixedHeight = 568.0f;
            self.fixedAspectRatio = 0.0f;
            self.magnification = 1.0f;
            break;

        case WOCDisplayPresetTablet768x1024:
            self.fixedWidth = 768.0f;
            self.fixedHeight = 1024.0f;
            self.fixedAspectRatio = 0.0f;
            self.magnification = 1.0f;
            break;

        case WOCDisplayPresetNative:
            self.fixedWidth = 0.0f;
            self.fixedHeight = 0.0f;
            self.fixedAspectRatio = 0.0f;
            self.magnification = 1.0f;
            break;

        case WOCDisplayPresetNative2x:
            self.fixedWidth = 0.0f;
            self.fixedHeight = 0.0f;
            self.fixedAspectRatio = 0.0f;
            self.magnification = 2.0f;
            break;

        case WOCDisplayPresetNative320Fixed:
            self.fixedWidth = 320.0f;
            self.fixedHeight = 0.0f;
            self.fixedAspectRatio = 0.0f;
            self.magnification = 1.0f;
            break;

        case WOCDisplayPresetNative768Fixed:
            self.fixedWidth = 768.0f;
            self.fixedHeight = 0.0f;
            self.fixedAspectRatio = 0.0f;
            self.magnification = 1.0f;
            break;

        case WOCDisplayPresetNative4x3Aspect:
            self.fixedWidth = 0.0f;
            self.fixedHeight = 0.0f;
            self.fixedAspectRatio = 4.0 / 3.0;
            self.magnification = 1.0f;
            break;

        case WOCDisplayPresetNative16x9Aspect:
            self.fixedWidth = 0.0f;
            self.fixedHeight = 0.0f;
            self.fixedAspectRatio = 16.0 / 9.0;
            self.magnification = 1.0f;
            break;
    }
}
@end
