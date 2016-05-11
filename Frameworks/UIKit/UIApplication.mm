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
#import <StubReturn.h>

#include "Platform/EbrPlatform.h"

#include "CoreFoundation/CFArray.h"
#include "CoreGraphics/CGContext.h"

#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSMutableArray.h"
#include "Foundation/NSString.h"
#include "NSRunLoopSource.h"
#include "NSRunLoop+Internal.h"
#include "UIKit/UIView.h"
#include "UIKit/UIImage.h"
#include "UIKit/UIColor.h"
#include "UIViewInternal.h"
#include "UIApplicationInternal.h"
#include "UIKit/UIGestureRecognizerSubclass.h"
#include "UIGestureRecognizerInternal.h"
#include "UIWindowInternal.h"
#include "UILocalNotificationInternal.h"
#include "CALayerInternal.h"
#include "CATransactionInternal.h"
#include "UIResponderInternal.h"
#include "UITouchInternal.h"
#include "UIEventInternal.h"
#include "UWP/WindowsGraphicsDisplay.h"
#include "UWP/WindowsSystemDisplay.h"
#include "UrlLauncher.h"

#include "UIEmptyView.h"

#include "CACompositor.h"
#include "UIInterface.h"

#include "UWP/WindowsUICore.h"
#include "UWP/WindowsUINotifications.h"

#include "LoggingNative.h"
#include "UIApplicationMainInternal.h"
#import "StarboardXaml/UWPBackgroundTask.h"

static const wchar_t* TAG = L"UIApplication";

@interface UIKeyboardRotationView : UIView
@end

@implementation UIKeyboardRotationView
- (UIView*)hitTest:(CGPoint)point withEvent:(UIEvent*)event {
    UIView* ret = [super hitTest:point withEvent:event];

    if (ret == self) {
        return nil;
    }

    return ret;
}
@end

const NSTimeInterval UIMinimumKeepAliveTimeout = StubConstant();
const UIBackgroundTaskIdentifier UIBackgroundTaskInvalid = NSUIntegerMax;

NSString* const UIApplicationOpenSettingsURLString = @"UIApplicationOpenSettingsURLString";

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
NSString* const UIApplicationLaunchOptionsVoiceCommandKey = @"UIApplicationLaunchOptionsVoiceCommandKey";
NSString* const UIApplicationLaunchOptionsProtocolKey = @"UIApplicationLaunchOptionsProtocolKey";
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

NSString* const UIContentSizeCategoryNewValueKey = @"UIContentSizeCategoryNewValueKey";

NSString* const UIApplicationInvalidInterfaceOrientationException = @"UIApplicationInvalidInterfaceOrientationException";

NSString* const UIApplicationKeyboardExtensionPointIdentifier = @"UIApplicationKeyboardExtensionPointIdentifier";

NSString* const UIApplicationLaunchOptionsNewsstandDownloadsKey = @"UIApplicationLaunchOptionsNewsstandDownloadsKey";
NSString* const UIApplicationLaunchOptionsBluetoothCentralsKey = @"UIApplicationLaunchOptionsBluetoothCentralsKey";
NSString* const UIApplicationLaunchOptionsBluetoothPeripheralsKey = @"UIApplicationLaunchOptionsBluetoothPeripheralsKey";
NSString* const UIApplicationLaunchOptionsShortcutItemKey = @"UIApplicationLaunchOptionsShortcutItemKey";
NSString* const UIApplicationLaunchOptionsUserActivityDictionaryKey = @"UIApplicationLaunchOptionsUserActivityDictionaryKey";
NSString* const UIApplicationLaunchOptionsUserActivityTypeKey = @"UIApplicationLaunchOptionsUserActivityTypeKey";
NSString* const UIApplicationOpenURLOptionsSourceApplicationKey = @"UIApplicationOpenURLOptionsSourceApplicationKey";
NSString* const UIApplicationOpenURLOptionsAnnotationKey = @"UIApplicationOpenURLOptionsAnnotationKey";
NSString* const UIApplicationOpenURLOptionsOpenInPlaceKey = @"UIApplicationOpenURLOptionsOpenInPlaceKey";

NSString* const UIApplicationBackgroundRefreshStatusDidChangeNotification = @"UIApplicationBackgroundRefreshStatusDidChangeNotification";
NSString* const UIApplicationProtectedDataDidBecomeAvailable = @"UIApplicationProtectedDataDidBecomeAvailable";
NSString* const UIApplicationProtectedDataWillBecomeUnavailable = @"UIApplicationProtectedDataWillBecomeUnavailable";
NSString* const UIApplicationUserDidTakeScreenshotNotification = @"UIApplicationUserDidTakeScreenshotNotification";
NSString* const UIContentSizeCategoryDidChangeNotification = @"UIContentSizeCategoryDidChangeNotification";

const NSTimeInterval UIApplicationBackgroundFetchIntervalMinimum = StubConstant();
const NSTimeInterval UIApplicationBackgroundFetchIntervalNever = StubConstant();

float statusBarHeight = 20.0f;
static UIInterfaceOrientation _curOrientation = UIInterfaceOrientationPortrait;
static UIInterfaceOrientation _internalOrientation = UIInterfaceOrientationPortrait;
extern int requestDeviceOrientation;
extern UIWindow* _curKeyWindow;

NSArray* windows;
UIWindow* popupWindow;
UIApplication* sharedApplication;
int showKeyboard, forceHideKeyboard;
static int curKeyboardType, showKeyboardType;
bool keyboardVisible;
CGRect keyboardRect;
UIView* _blankView;
static bool blankViewUp = false;
static float curBlankViewHeight = 0.0f;
static bool doEvaluateKeyboard = false;

// Right now it's expected that the user sets this when they want otherwise:
float keyboardBaseHeight = 200, keyboardPhysicalHeight = 0;

static UIEdgeInsets _statusBarInsets;

BOOL refreshPending = FALSE;
NSRunLoopSource* shutdownEvent;
UIImageView* statusBar;
UIView* statusBarRotationLayer;
UIView* popupRotationLayer;
BOOL statusBarHidden = FALSE;
unsigned ignoringInteractionEvents = 0;
BOOL idleDisabled = FALSE;
extern BOOL _doShutdown;
EbrEvent g_shutdownEvent;
extern id _curFirstResponder;

UIApplicationState _applicationState = UIApplicationStateInactive;

// Used to query for Url scheme handlers or launch an app with a Url
UrlLauncher* _launcher;

static UIView *_curKeyboardAccessory, *_curKeyboardInputView;

static idretaintype(NSMutableArray) _curNotifications;

static idretaintype(WSDDisplayRequest) _screenActive;

@implementation UIApplication {
    id _delegate;
}

@synthesize applicationIconBadgeNumber = _applicationIconBadgeNumber;

/**
 @Status Interoperable
*/
+ (instancetype)alloc {
    if (sharedApplication != nil) {
        return sharedApplication;
    }

    sharedApplication = [super alloc];

    shutdownEvent = [NSRunLoopSource new];
    [shutdownEvent setSourceDelegate:[UIApplication class] selector:@selector(_shutdownEvent)];
    g_shutdownEvent = (EbrEvent)[shutdownEvent eventHandle];

    [[NSRunLoop mainRunLoop] _addInputSource:shutdownEvent forMode:@"kCFRunLoopDefaultMode"];
    [[NSRunLoop mainRunLoop] _addObserver:sharedApplication forMode:@"kCFRunLoopDefaultMode"];

    // TODO: This will be revisited when we sort out our WinRT navigation integration model
    // Subscribe to back button events
    // Note: This method may be called from UnitTests, so make sure we don't fall over if we're not running from within a UWP.
    if ([WUCCoreWindow getForCurrentThread]) {
        [[WUCSystemNavigationManager getForCurrentView] addBackRequestedEvent:^(RTObject* sender, WUCBackRequestedEventArgs* e) {
            e.handled = [UIApplication _doBackAction];
        }];
    }

    return sharedApplication;
}

- (void)_destroy {
    [popupWindow _destroy];
    popupWindow = nil;
    sharedApplication = nil;

    [[NSRunLoop mainRunLoop] _removeObserver:sharedApplication forMode:@"kCFRunLoopDefaultMode"];
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
            }
            if (forceHideKeyboard == 0 && showKeyboard > 0 && keyboardVisible == false) {
                keyboardVisible = true;
            } else if ((forceHideKeyboard > 0 || showKeyboard == 0) && keyboardVisible == true) {
                keyboardVisible = false;
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
            TraceError(TAG, L"**** Error - UI updated on non-UI thread ******");
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

static id findTopActionButtons(NSMutableArray* arr, NSArray* windows, UIView* root) {
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

+ (BOOL)_doBackAction {
    TraceVerbose(TAG, L"Handling back button press.");

    if (ignoringInteractionEvents) {
        return false;
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
            [appDelegate performSelector:@selector(applicationBackButtonPressed:) withObject:nil];
        }
    }

    return wasHandled;
}

+ (void)_launchedWithURL:(NSURL*)url {
    UIApplication* shared = [self sharedApplication];
    id delegate = [shared delegate];
    TraceVerbose(TAG, L"Launchedwithurl: %x", url);
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
            TraceVerbose(TAG, L"Unknown orientation %d", _curOrientation);
            assert(0);
            break;
    }
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
 @Status Interoperable
*/
- (void)setIdleTimerDisabled:(BOOL)disable {
    idleDisabled = disable;
    // New WSDDisplayRequest are required to gurantee the screenActive request is honored.
    if (disable) {
        _screenActive = [WSDDisplayRequest make];
        [_screenActive requestActive];
    } else if (_screenActive != nil) {
        [_screenActive requestRelease];
    }
}

/**
 @Status Interoperable
*/
- (BOOL)isIdleTimerDisabled {
    return idleDisabled;
}

/**
 @Status Interoperable
*/
- (void)setStatusBarHidden:(BOOL)hidden animated:(BOOL)animated {
    if (statusBarHidden != hidden) {
        statusBarHidden = hidden;
        [statusBar setHidden:hidden];
    }
}

/**
 @Status Interoperable
*/
- (void)setApplicationIconBadgeNumber:(int)num {
    if (num > 0) {
        _applicationIconBadgeNumber = num;
    } else {
        // 0 or negative input.
        _applicationIconBadgeNumber = 0;
    }

    WDXDXmlDocument* doc = [WUNBadgeUpdateManager getTemplateContent:WUNBadgeTemplateTypeBadgeNumber];
    WDXDXmlNodeList* badges = [doc getElementsByTagName:@"badge"];

    if ([badges count] == 0) {
        return;
    }

    id badgeObject = [badges objectAtIndex:0];

    if (badgeObject == nil) {
        return;
    }

    WDXDXmlElement* badgeElement = rt_dynamic_cast<WDXDXmlElement>(badgeObject);
    [badgeElement setAttribute:@"value" attributeValue:[NSString stringWithFormat:@"%i", num]];

    WUNBadgeNotification* notification = [WUNBadgeNotification makeBadgeNotification:doc];
    WUNBadgeUpdater* updater = [WUNBadgeUpdateManager createBadgeUpdaterForApplication];

    [updater update:notification];
}

static void printViews(id curView, int level) {
    char szOut[2048];
    strcpy_s(szOut, sizeof(szOut), "");

    for (int i = 0; i < level * 2; i++) {
        sprintf_s(&szOut[strlen(szOut)], sizeof(szOut) - strlen(szOut), " ");
    }
    sprintf_s(&szOut[strlen(szOut)], sizeof(szOut) - strlen(szOut), "%s @ 0x%08x ", object_getClassName(curView), (unsigned int)curView);

    if ([curView isHidden] || [curView alpha] <= 0.01f) {
        sprintf_s(&szOut[strlen(szOut)], sizeof(szOut) - strlen(szOut), " (hidden) ");
    }
    if (![curView isUserInteractionEnabled]) {
        sprintf_s(&szOut[strlen(szOut)], sizeof(szOut) - strlen(szOut), " (interaction disabled) ");
    }
    if ([curView isOpaque]) {
        sprintf_s(&szOut[strlen(szOut)], sizeof(szOut) - strlen(szOut), " (opaque) ");
    }
    if ([curView respondsToSelector:@selector(text)]) {
        id text = [curView text];
        sprintf_s(&szOut[strlen(szOut)], sizeof(szOut) - strlen(szOut), " (text=\"%s\") ", [text UTF8String]);
    }

    CGRect rect;
    rect = [curView frame];
    id fmt = [NSString stringWithFormat:@"{%f, %f}{%f, %f}\n", rect.origin.x, rect.origin.y, rect.size.width, rect.size.height];

    /*
    sprintf_s(&szOut[szOutLength],
              sizeof(szOut) - strlen(szOut),
              "{%f, %f}{%f, %f}\n",
              rect.origin.x,
              rect.origin.y,
              rect.size.width,
              rect.size.height);
    */

    TraceVerbose(TAG, L"%hs%hs", szOut, [fmt UTF8String]);

    for (unsigned i = 0; i < [[curView subviews] count]; i++) {
        printViews([[curView subviews] objectAtIndex:i], level + 1);
    }
}

+ (void)_shutdownEvent {
    _doShutdown = TRUE;
    [[NSRunLoop mainRunLoop] _stop];
    [[NSRunLoop mainRunLoop] _shutdown];
    _UIApplicationShutdown();
}

/**
 @Status Stub
*/
- (void)sendEvent:(UIEvent*)event {
    UNIMPLEMENTED();
}

/**
 @Status Caveat
 @Notes This method only returns the status for if the URL can be opened and not the actual open URL call status.
*/
- (BOOL)openURL:(NSURL*)url {
    return [_launcher _openURLAsync:url];
}

/**
 @Status Interoperable
*/
- (BOOL)canOpenURL:(NSURL*)url {
    return [_launcher _canOpenURL:url];
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
- (void)registerForRemoteNotificationTypes:(UIRemoteNotificationType)types {
    UNIMPLEMENTED();
    [self registerForRemoteNotificationTypes:types withId:@"309806373466"];
}

/**
 @Status Stub
*/
- (void)registerForRemoteNotificationTypes:(UIRemoteNotificationType)types withId:(id)identifier {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)registerUserNotificationSettings:(UIUserNotificationSettings*)notificationSettings {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (BOOL)sendAction:(SEL)action to:(id)target from:(id)sender forEvent:(UIEvent*)forEvent {
    // If sending to nil, use the current first responder
    UIResponder* curTarget = target;
    if (curTarget == nil) {
        curTarget = _curFirstResponder;
    }

    // Walk the target's responder chain looking for a responder for this action
    while (curTarget != nil) {
        if ([curTarget respondsToSelector:action]) {
            // We found a target; invoke the selector.
            [curTarget performSelector:action withObject:sender withObject:forEvent];
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
#ifdef ENABLE_BACKGROUND_TASK
    return [[UWPBackgroundTask sharedInstance] requestBackgroundTask:handler];
#else
    UNIMPLEMENTED();
    TraceVerbose(TAG, L"beginBackgroundTaskWithExpirationHandler not supported");
    return 0;
#endif
}

/**
 @Status Stub
*/
- (UIBackgroundTaskIdentifier)beginBackgroundTaskWithName:(NSString*)taskName expirationHandler:(void (^)(void))handler {
#ifdef ENABLE_BACKGROUND_TASK
    // taskName argument is not used here as UWPBackgroundTask has its own in-built mechanism to to keep track of tasks.
    return [[UWPBackgroundTask sharedInstance] requestBackgroundTask:handler];
#else
    UNIMPLEMENTED();
    return StubReturn();
#endif
}

/**
 @Status Stub
*/
- (double)backgroundTimeRemaining {
#ifdef ENABLE_BACKGROUND_TASK
    return [[UWPBackgroundTask sharedInstance] timeRemaining];
#else
    UNIMPLEMENTED();
    return 60.0 * 5;
#endif
}

/**
 @Status Stub
*/
- (void)endBackgroundTask:(UIBackgroundTaskIdentifier)taskIdentifier {
#ifdef ENABLE_BACKGROUND_TASK
    [[UWPBackgroundTask sharedInstance] unregisterBackgroundTask:taskIdentifier];
#else
    UNIMPLEMENTED();
    TraceVerbose(TAG, L"endBackgroundTask not supported");
#endif
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

/**
 @Status Interoperable
*/
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

        CALayer* layer = [statusBarRotationLayer layer];
        [layer validateDisplayHierarchy];
        GetCACompositor()->setNodeTopMost((DisplayNode*)[layer _presentationNode], true);
        [CATransaction _addSublayerToTop:layer];
        GetCACompositor()->setNodeTopMost((DisplayNode*)[[popupRotationLayer layer] _presentationNode], true);
        GetCACompositor()->setNodeTopMost((DisplayNode*)[[statusBarRotationLayer layer] _presentationNode], true);
    }

    _curNotifications = [NSMutableArray new];
    _launcher = [[UrlLauncher alloc] initWithLauncher:[WSLauncher class]];

    return self;
}

// Allow us to init parts of UIApplication for unit tests, without the need for an actual UI
- (instancetype)_initForTestingWithLauncher:(Class)launcher {
    _launcher = [[UrlLauncher alloc] initWithLauncher:launcher];
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

    // Disable input for this Window
    if (ignoringInteractionEvents == 1) {
        [WUCCoreWindow getForCurrentThread].isInputEnabled = NO;
    }
}

/**
 @Status Stub
*/
- (void)beginReceivingRemoteControlEvents {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)endReceivingRemoteControlEvents {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (void)endIgnoringInteractionEvents {
    if (ignoringInteractionEvents > 0) {
        ignoringInteractionEvents--;
    }

    if (ignoringInteractionEvents == 0) {
        // Re-enable input for this Window
        [WUCCoreWindow getForCurrentThread].isInputEnabled = YES;
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

/**
 @Status Interoperable
*/
- (UIWindow*)_popupWindow {
    static BOOL building = false;
    if (popupWindow == nil && building == FALSE) {
        building = TRUE;

        CGRect popupRect;

        popupRect.origin.x = 0;
        popupRect.origin.y = 0;
        popupRect.size.width = GetCACompositor()->screenWidth();
        popupRect.size.height = GetCACompositor()->screenHeight();

        popupWindow = [[UIWindow alloc] _initWithContentRect:popupRect];
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
 @Status Interoperable
*/
- (int)applicationIconBadgeNumber {
    return _applicationIconBadgeNumber;
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
 This will return UIRemoteNotificationTypeNone until we interop with our Notification system.
*/
- (UIRemoteNotificationType)enabledRemoteNotificationTypes {
    return UIRemoteNotificationTypeNone;
}

/**
 @Status Stub
*/
- (void)cancelAllLocalNotifications {
    UNIMPLEMENTED();
    int count = [_curNotifications count];
    while (count > 0) {
        UILocalNotification* object = [_curNotifications objectAtIndex:count - 1];
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

static void _sendMemoryWarningToViewControllers(UIView* subview) {
    id controller = [UIViewController controllerForView:subview];
    if ([controller respondsToSelector:@selector(didReceiveMemoryWarning)]) {
        [controller didReceiveMemoryWarning];
    }

    NSArray* subviews = [subview subviews];
    for (UIView* curSubview in subviews) {
        _sendMemoryWarningToViewControllers(curSubview);
    }
}

- (void)_sendActiveStatus:(BOOL)isActive {
    if (isActive) {
        [self _sendEnteringForegroundEvents];

        if ([self.delegate respondsToSelector:@selector(applicationDidBecomeActive:)]) {
            [self.delegate applicationDidBecomeActive:self];
        }
        [[NSNotificationCenter defaultCenter] postNotificationName:@"UIApplicationDidBecomeActiveNotification" object:self];
    } else {
        if ([self.delegate respondsToSelector:@selector(applicationWillResignActive:)]) {
            [self.delegate applicationWillResignActive:self];
        }
        [[NSNotificationCenter defaultCenter] postNotificationName:@"UIApplicationWillResignActiveNotification" object:self];

        [self _sendEnteringBackgroundEvents];
    }
}

- (void)_sendEnteringBackgroundEvents {
#ifdef ENABLE_BACKGROUND_TASK
    [[UWPBackgroundTask sharedInstance] isEnteringBackground];
#endif

    if ([self.delegate respondsToSelector:@selector(applicationDidEnterBackground:)]) {
        [self.delegate applicationDidEnterBackground:self];
    }
    [[NSNotificationCenter defaultCenter] postNotificationName:@"UIApplicationDidEnterBackgroundNotification" object:self];

    _applicationState = UIApplicationStateBackground;
}

- (void)_sendEnteringForegroundEvents {
#ifdef ENABLE_BACKGROUND_TASK
    [[UWPBackgroundTask sharedInstance] isEnteringForeground];
#endif

    if (_applicationState == UIApplicationStateBackground) {
        // Note: *applicationWillEnterForeground* events should only be sent when the app is coming to Foreground from Background.
        if ([self.delegate respondsToSelector:@selector(applicationWillEnterForeground:)]) {
            [self.delegate applicationWillEnterForeground:self];
        }
        [[NSNotificationCenter defaultCenter] postNotificationName:@"UIApplicationWillEnterForegroundNotification" object:self];
    }

    _applicationState = UIApplicationStateActive;
}

- (void)_launchToForeground:(NSURL*)url {
    [self _sendEnteringForegroundEvents];

    TraceVerbose(TAG, L"Launching to foreground with: %@", url);
    if (url != nil) {
        [UIApplication _launchedWithURL:url];
    }
}

- (void)_sendNotificationReceivedEvent:(NSString*)notificationData {
    NSMutableDictionary* data = [NSMutableDictionary dictionary];
    [data setValue:notificationData forKey:UIApplicationLaunchOptionsRemoteNotificationKey];

    // As there is now way to distinguish remote notification from local, calling both delegates here for now.
    if ([self.delegate respondsToSelector:@selector(application:didReceiveRemoteNotification:fetchCompletionHandler:)]) {
#ifdef ENABLE_BACKGROUND_TASK
        // Hold a ApplicationTrigger deferral to prevent the application from suspending until the completion handler is
        // called.
        NSUInteger taskIdentifier = [[UWPBackgroundTask sharedInstance] requestBackgroundTask:nil];
#endif
        [self.delegate application:self
            didReceiveRemoteNotification:data
                  fetchCompletionHandler:^(UIBackgroundFetchResult result) {
                      TraceVerbose(TAG, L"didReceiveRemoteNotification fetchCompletionHandler called with result %d", result);
#ifdef ENABLE_BACKGROUND_TASK
                      [[UWPBackgroundTask sharedInstance] unregisterBackgroundTask:taskIdentifier];
#endif
                  }];
    } else if ([self.delegate respondsToSelector:@selector(application:didReceiveRemoteNotification:)]) {
        [self.delegate application:self didReceiveRemoteNotification:data];
    }

    // TODO::
    // todo-nithishm-05262016 - Implement UILocalNotification and call LocalNotification delegate here.
}

- (void)_sendVoiceCommandReceivedEvent:(WMSSpeechRecognitionResult*)voiceCommandResult {
    if ([self.delegate respondsToSelector:@selector(application:didReceiveVoiceCommand:)]) {
        [self.delegate application:sharedApplication didReceiveVoiceCommand:voiceCommandResult];
    }
}

- (void)_sendProtocolReceivedEvent:(WFUri*)protocolUri source:(NSString*)source {
    id delegate = self.delegate;

    if ([delegate respondsToSelector:@selector(application:didReceiveProtocol:)]) {
        [delegate application:sharedApplication didReceiveProtocol:protocolUri];
    }

    if ([delegate respondsToSelector:@selector(application:openURL:sourceApplication:annotation:)]) {
        NSURL* url = [NSURL URLWithString:protocolUri.absoluteUri];

        [delegate application:sharedApplication openURL:url sourceApplication:source annotation:nil];
    }
}

- (void)_sendHighMemoryWarning {
    if ([self.delegate respondsToSelector:@selector(applicationDidReceiveMemoryWarning:)]) {
        [self.delegate applicationDidReceiveMemoryWarning:self];
    }
    [[NSNotificationCenter defaultCenter] postNotificationName:@"UIApplicationDidReceiveMemoryWarningNotification" object:self];

    int windowCount = [windows count];
    for (int i = 0; i < windowCount; i++) {
        UIView* window = [windows objectAtIndex:i];
        _sendMemoryWarningToViewControllers(window);
    }
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
        _blankView = [[UIEmptyView alloc] initWithFrame:frame];
        [_blankView setBackgroundColor:[UIColor blackColor]];
        [_blankView setAutoresizesSubviews:FALSE];
    }

    // Figure out what's going on with our first responder:
    UIView* keyboardAccessory = nil;
    UIView* inputView = nil;
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
    WORD* chars = (WORD*)IwCalloc(2, len);
    [text getCharacters:chars range:NSMakeRange(0, len)];

    for (int i = 0; i < len; i++) {
        [UIResponder _keyPressed:chars[i]];
    }
    IwFree(chars);
}

- (void)_editTextDelete:(NSNumber*)numBefore {
    [UIResponder _deleteRange:numBefore];
}

- (void)_didRegisterForRemoteNotification:(NSData*)tokenData {
#ifndef SUPPORT_REMOTE_NOTIFICATIONS
    return;
#endif
    NSString* str = [[NSString alloc] initWithData:tokenData encoding:NSUTF8StringEncoding];
    TraceVerbose(TAG, L"Received token: %hs", [str UTF8String]);

    if ([self.delegate respondsToSelector:@selector(application:didRegisterForRemoteNotificationsWithDeviceToken:)]) {
        [self.delegate application:self didRegisterForRemoteNotificationsWithDeviceToken:tokenData];
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

    NSDictionary* obj = [NSJSONSerialization JSONObjectWithData:data options:0 error:NULL];

    TraceVerbose(TAG, L"Type is: %hs", object_getClassName(obj));
    TraceVerbose(TAG, L"Received notification: %hs", [[obj description] UTF8String]);

    if ([self.delegate respondsToSelector:@selector(application:didReceiveRemoteNotification:)]) {
        [self.delegate application:self didReceiveRemoteNotification:obj];
    }
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

/**
 @Status Stub
*/
- (BOOL)isRegisteredForRemoteNotifications {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)registerForRemoteNotifications {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (BOOL)setKeepAliveTimeout:(NSTimeInterval)timeout handler:(void (^)(void))keepAliveHandler {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (UIInterfaceOrientationMask)supportedInterfaceOrientationsForWindow:(UIWindow*)window {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (UIUserNotificationSettings*)currentUserNotificationSettings {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)clearKeepAliveTimeout {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)completeStateRestoration {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)extendStateRestoration {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)ignoreSnapshotOnNextApplicationLaunch {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setMinimumBackgroundFetchInterval:(NSTimeInterval)minimumBackgroundFetchInterval {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setNewsstandIconImage:(UIImage*)image {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setStatusBarStyle:(UIStatusBarStyle)statusBarStyle animated:(BOOL)animated {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)unregisterForRemoteNotifications {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
+ (void)registerObjectForStateRestoration:(id<UIStateRestoring>)object restorationIdentifier:(NSString*)restorationIdentifier {
    UNIMPLEMENTED();
}

@end

void UIRequestTransactionProcessing() {
    [UIApplication viewChanged];
}

void UIShutdown() {
    [UIApplication _shutdownEvent];
    [[NSRunLoop mainRunLoop] _wakeUp];
}

/**
 @Public No
*/
@implementation WOCDisplayMode {
    float _magnification;
    float _fixedWidth, _fixedHeight;
    double _fixedAspectRatio;
    BOOL _autoMagnification;
    BOOL _sizeUIWindowToFit;
    BOOL _useHostScaleFactor;
    BOOL _clampScaleToClosestExpected;
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
@synthesize useHostScaleFactor = _useHostScaleFactor;
@synthesize clampScaleToClosestExpected = _clampScaleToClosestExpected;

- (instancetype)init {
    _fixedWidth = 320.0f;
    _fixedHeight = 480.0f;
    _fixedAspectRatio = 0.0f;
    _magnification = 1.0f;
    _autoMagnification = TRUE;
    _sizeUIWindowToFit = TRUE;
    _useHostScaleFactor = TRUE;
    _clampScaleToClosestExpected = TRUE;
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

    GetCACompositor()->setTablet(_operationMode == WOCOperationModeTablet);
    GetCACompositor()->setScreenSize(newWidth, newHeight, newMagnification, newRotation);
    GetCACompositor()->setDeviceSize(newWidth, newHeight);

    //  Adjust size of all UIWindows
    CGRect curBounds;
    curBounds.origin.x = 0.0f;
    curBounds.origin.y = 0.0f;
    curBounds.size.width = newWidth;
    curBounds.size.height = newHeight;
    bool isFrameSet = false;
    for (UIWindow* current in windows) {
        if (current.sizeUIWindowToFit) {
            [current setFrame:curBounds];
            isFrameSet = true;
        }
    }

    if (_sizeUIWindowToFit) {
        [popupRotationLayer setFrame:curBounds];
        isFrameSet = true;
    }

    if (isFrameSet) {
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
