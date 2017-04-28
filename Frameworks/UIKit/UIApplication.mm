//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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
#import "AssertARCEnabled.h"

#include "Platform/EbrPlatform.h"

#import <UIKit/NSValue+UIKitAdditions.h>
#import <UIKit/UIColor.h>
#import <UIKit/UIAlertView.h>
#import <UIKit/UIApplication.h>
#import <UIKit/UIApplicationDelegate.h>
#import <UIKit/UIImage.h>
#import <UIKit/UIImageView.h>
#import <UIKit/UITextInputTraits.h>
#import <UIKit/UIView.h>
#import <UIKit/UIViewController.h>
#import <UIKit/UIWindow.h>

#include <CoreFoundation/CFArray.h>

#include <CoreGraphics/CGContext.h>

#include <Foundation/NSMutableDictionary.h>
#include <Foundation/NSMutableArray.h>
#include <Foundation/NSString.h>

#include <QuartzCore/CALayer.h>
#include <QuartzCore/CATransaction.h>

#include "NSRunLoopSource.h"
#include "NSRunLoop+Internal.h"

#include "UIViewInternal.h"
#include "UIApplicationInternal.h"
#include "UIKit/UIGestureRecognizerSubclass.h"
#include "UIGestureRecognizerInternal.h"
#include "UIWindowInternal.h"
#include "CALayerInternal.h"
#include "CATransactionInternal.h"
#include "UIResponderInternal.h"
#include "UITouchInternal.h"
#include "UIEventInternal.h"
#include "UrlLauncher.h"
#include "StringHelpers.h"
#import <string>

#include "UIInterface.h"

#include "COMIncludes.h"
#import <winrt/Windows.System.Display.h>
#import <winrt/Windows.Graphics.Display.h>
#import <winrt/Windows.Data.Xml.Dom.h>
#import <winrt/Windows.UI.Notifications.h>
#import <winrt/Windows.UI.Core.h>
#include "COMIncludes_End.h"

#include "LoggingNative.h"
#include "UIApplicationMainInternal.h"
#import "StarboardXaml/DisplayProperties.h"
#import "StarboardXaml/UWPBackgroundTask.h"

using winrt::Windows::System::Display::DisplayRequest;
using winrt::Windows::Graphics::Display::DisplayInformation;

using namespace winrt::Windows::Data::Xml::Dom;
using namespace winrt::Windows::UI::Notifications;
using namespace winrt::Windows::UI::Core;
namespace WF = winrt::Windows::Foundation;

static const wchar_t* TAG = L"UIApplication";

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
NSString* const UIApplicationLaunchOptionsToastActionKey = @"UIApplicationLaunchOptionsToastActionKey";
NSString* const UIApplicationLaunchOptionsVoiceCommandKey = @"UIApplicationLaunchOptionsVoiceCommandKey";
NSString* const UIApplicationLaunchOptionsFileKey = @"UIApplicationLaunchOptionsFileKey";
NSString* const UIApplicationLaunchOptionsProtocolKey = @"UIApplicationLaunchOptionsProtocolKey";
NSString* const UIApplicationLaunchOptionsLocationKey = @"UIApplicationLaunchOptionsLocationKey";

NSString* const UIApplicationLaunchOptionsToastActionArgumentKey = @"UIApplicationLaunchOptionsToastActionArgumentKey";
NSString* const UIApplicationLaunchOptionsToastActionUserInputKey = @"UIApplicationLaunchOptionsToastActionUserInputKey";

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

extern UIWindow* _curKeyWindow;
NSArray<UIWindow*>* g_windows;

// TODO: #2443 Remove _popupWindow (and all references to it) when we move UIAlertView over to Xaml
UIWindow* g_popupWindow;

UIApplication* sharedApplication;

BOOL refreshPending = FALSE;
NSRunLoopSource* shutdownEvent;

unsigned ignoringInteractionEvents = 0;
EbrEvent g_shutdownEvent;
extern id _curFirstResponder;

UIApplicationState _applicationState = UIApplicationStateInactive;

// Used to query for Url scheme handlers or launch an app with a Url
UrlLauncher* _launcher;

static DisplayRequest _screenActive(nullptr);
BOOL idleDisabled = FALSE;

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

    // TODO: #2442 This will be revisited when we sort out our WinRT navigation integration model
    // Subscribe to back button events
    // Note: This method may be called from UnitTests, so make sure we don't fall over if we're not running from within a UWP.
    if (CoreWindow::GetForCurrentThread()) {
        SystemNavigationManager::GetForCurrentView().BackRequested(objcwinrt::callback([] (const WF::IInspectable& sender, const BackRequestedEventArgs& e) {
            e.Handled([UIApplication _doBackAction]);
        }));
    }

    return sharedApplication;
}

- (void)_destroy {
    g_popupWindow = nil;
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
        if (refreshPending) {
            refreshPending = FALSE;

            for (UIWindow* window in g_windows) {
                [[window layer] _displayChanged];
            }
        }
    }
}

+ (void)_viewTreeChanged {
    if (!refreshPending) {
        refreshPending = TRUE;
        [[NSRunLoop mainRunLoop] _wakeUp];
    }
}

static id findTopActionButtons(NSMutableArray* arr, NSArray* windows, UIView* root) {
    NSArray* subviews = [root subviews];
    int count = [subviews count];

    for (int i = count - 1; i >= 0; i--) {
        UIView* curView = [subviews objectAtIndex:i];
        findTopActionButtons(arr, windows, curView);

        if (![curView isHidden] && (curView->_backButtonDelegate != nil)) {
           [arr addObject:curView];
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

    NSMutableArray* allActionButtons = [NSMutableArray new];
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
 @Status NotInPlan
*/
- (void)scheduleLocalNotification:(UILocalNotification*)n {
    UNIMPLEMENTED();
}

/**
 @Status NotInPlan
 @Notes UWP status bar can be directly accessed via WinRT APIs, and will eventually be supported via UIViewController APIs.
*/
- (void)setStatusBarHidden:(BOOL)hide {
    UNIMPLEMENTED_WITH_MSG("UWP status bar can be directly accessed via WinRT APIs, and will eventually be supported via UIViewController APIs.");
}

/**
 @Status NotInPlan
 @Notes UWP status bar can be directly accessed via WinRT APIs, and will eventually be supported via UIViewController APIs.
*/
- (BOOL)isStatusBarHidden {
    UNIMPLEMENTED_WITH_MSG("UWP status bar can be directly accessed via WinRT APIs, and will eventually be supported via UIViewController APIs.");
    return StubReturn();
}

/**
 @Status NotInPlan
 @Notes UWP status bar can be directly accessed via WinRT APIs, and will eventually be supported via UIViewController APIs.
*/
- (CGRect)statusBarFrame {
    UNIMPLEMENTED_WITH_MSG("UWP status bar can be directly accessed via WinRT APIs, and will eventually be supported via UIViewController APIs.");
    return StubReturn();
}


/**
 @Status NotInPlan
 @Notes UWP status bar can be directly accessed via WinRT APIs, and will eventually be supported via UIViewController APIs.
*/
- (void)setStatusBarHidden:(BOOL)hidden animated:(BOOL)animated {
    UNIMPLEMENTED_WITH_MSG("UWP status bar can be directly accessed via WinRT APIs, and will eventually be supported via UIViewController APIs.");
}

/**
 @Status NotInPlan
 @Notes UWP status bar can be directly accessed via WinRT APIs, and will eventually be supported via UIViewController APIs.
*/
- (void)setStatusBarHidden:(BOOL)hide withAnimation:(UIStatusBarAnimation)anim {
    UNIMPLEMENTED_WITH_MSG("UWP status bar can be directly accessed via WinRT APIs, and will eventually be supported via UIViewController APIs.");
}

/**
 @Status NotInPlan
 @Notes UWP status bar can be directly accessed via WinRT APIs, and will eventually be supported via UIViewController APIs.
*/
- (void)setStatusBarOrientation:(UIInterfaceOrientation)orientation {
    UNIMPLEMENTED_WITH_MSG("UWP status bar can be directly accessed via WinRT APIs, and will eventually be supported via UIViewController APIs.");
}

/**
 @Status NotInPlan
 @Notes UWP status bar can be directly accessed via WinRT APIs, and will eventually be supported via UIViewController APIs.
*/
- (void)setStatusBarOrientation:(UIInterfaceOrientation)orientation animated:(BOOL)animated {
    UNIMPLEMENTED_WITH_MSG("UWP status bar can be directly accessed via WinRT APIs, and will eventually be supported via UIViewController APIs.");
}

/**
 @Status NotInPlan
*/
- (UIUserInterfaceLayoutDirection)userInterfaceLayoutDirection {
    UNIMPLEMENTED();
    return UIUserInterfaceLayoutDirectionLeftToRight;
}

/**
 @Status NotInPlan
 @Notes UWP status bar can be directly accessed via WinRT APIs, and will eventually be supported via UIViewController APIs.
*/
- (UIInterfaceOrientation)statusBarOrientation {
    UNIMPLEMENTED_WITH_MSG("UWP status bar can be directly accessed via WinRT APIs, and will eventually be supported via UIViewController APIs.");
    return StubReturn();
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
 @Status NotInPlan
*/
- (NSArray*)scheduledLocalNotifications {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status NotInPlan
*/
- (void)setScheduledLocalNotifications:(NSArray*)notifications {
    UNIMPLEMENTED();
}


/**
 @Status NotInPlan
*/
- (NSArray*)shortcutItems {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status NotInPlan
*/
- (void)setShortcutItems:(NSArray*)items {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (void)setIdleTimerDisabled:(BOOL)disable {
    idleDisabled = disable;
    // New DisplayRequest is required to guarantee the screenActive request is honored.
    if (disable) {
        _screenActive = DisplayRequest();
        _screenActive.RequestActive();
    } else if (_screenActive) {
        _screenActive.RequestRelease();
    }
}

/**
 @Status Interoperable
*/
- (BOOL)isIdleTimerDisabled {
    return idleDisabled;
}

/**
 @Status NotInPlan
*/
- (void)setNetworkActivityIndicatorVisible:(BOOL)visible {
    UNIMPLEMENTED();
}

/**
 @Status NotInPlan
*/
- (BOOL)isNetworkActivityIndicatorVisible {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status NotInPlan
*/
-(void)setProximitySensingEnabled:(BOOL)enabled {
    UNIMPLEMENTED();
}

/**
 @Status NotInPlan
*/
-(BOOL)isProximitySensingEnabled {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status NotInPlan
*/
- (void)setApplicationSupportsShakeToEdit:(BOOL)supports {
    UNIMPLEMENTED();
}

/**
 @Status NotInPlan
*/
- (BOOL)applicationSupportsShakeToEdit {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status NotInPlan
*/
- (void)setPreferredContentSizeCategory:(NSString*)category {
    UNIMPLEMENTED();
}

/**
 @Status NotInPlan
*/
- (NSString*)preferredContentSizeCategory {
    UNIMPLEMENTED();
    return StubReturn();
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

    XmlDocument doc = BadgeUpdateManager::GetTemplateContent(BadgeTemplateType::BadgeNumber);
    XmlNodeList badges = doc.GetElementsByTagName(L"badge");

    if (badges.Length() == 0) {
        return;
    }

    IXmlNode badgeObject = badges.GetAt(0);

    if (!badgeObject) {
        return;
    }

    XmlElement badgeElement = badgeObject.as<XmlElement>();
    badgeElement.SetAttribute(L"value", std::to_wstring(num));

    BadgeNotification notification(doc);
    BadgeUpdater updater = BadgeUpdateManager::CreateBadgeUpdaterForApplication();

    updater.Update(notification);
}

+ (void)_shutdownEvent {
    [[NSRunLoop mainRunLoop] _stop];
    [[NSRunLoop mainRunLoop] _shutdown];
    _UIApplicationShutdown();
}

/**
 @Status NotInPlan
 @Notes Application-level events are not delivered in this manner on Windows.
*/
- (void)sendEvent:(UIEvent*)event {
    UNIMPLEMENTED_WITH_MSG("Application-level events are not delivered in this manner on Windows.");
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
 @Status NotInPlan
*/
- (void)registerForRemoteNotificationTypes:(UIRemoteNotificationType)types {
    UNIMPLEMENTED();
}

/**
 @Status NotInPlan
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
            // Perhaps we should make this ARC-compliant, and return the result of the action.
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Warc-performSelector-leaks"
            // We found a target; invoke the selector.
            [curTarget performSelector:action withObject:sender withObject:forEvent];
            return TRUE;
#pragma clang diagnostic pop
        }
        curTarget = [curTarget nextResponder];
    }

    return FALSE;
}

// NOTE: This method is here merely due to the fact that Xib2Nib writes it to the Nib file.
// If this method is removed, we crash when instantiating storyboards.
// TODO: #2523 Validate Xib2Nib's "sceneViewController" outlet connection on UIApplication.
- (void)setSceneViewController:(UIViewController*)controller {
    UNIMPLEMENTED();
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

/**
 @Status Interoperable
*/
- (NSArray<UIWindow*>*)windows {
    return g_windows;
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
    g_windows = [[NSMutableArray alloc] init];

    // Use default system launcher
    _launcher = [[UrlLauncher alloc] initWithLauncher:Nil];

    return self;
}

// Allow us to init parts of UIApplication for unit tests, without the need for an actual UI
- (instancetype)_initForTestingWithLauncher:(Class)launcher {
    _launcher = [[UrlLauncher alloc] initWithLauncher:launcher];
    return self;
}

/**
 @Status Interoperable
*/
- (void)beginIgnoringInteractionEvents {
    ignoringInteractionEvents++;

    // Disable input for this Window
    if (ignoringInteractionEvents == 1) {
        CoreWindow::GetForCurrentThread().IsInputEnabled(false);
    }
}

/**
 @Status NotInPlan
*/
- (void)beginReceivingRemoteControlEvents {
    UNIMPLEMENTED();
}

/**
 @Status NotInPlan
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
        CoreWindow::GetForCurrentThread().IsInputEnabled(true);
    }
}

/**
 @Status Interoperable
*/
- (BOOL)isIgnoringInteractionEvents {
    return ignoringInteractionEvents > 0;
}

/**
 @Status NotInPlan
 @Notes UWP status bar can be directly accessed via WinRT APIs, and will eventually be supported via UIViewController APIs.
*/
- (double)statusBarOrientationAnimationDuration {
    UNIMPLEMENTED_WITH_MSG("UWP status bar can be directly accessed via WinRT APIs, and will eventually be supported via UIViewController APIs.");
    return StubReturn();
}

// TODO: #2443 Remove _popupWindow (and all references to it) when we move UIAlertView over to Xaml
- (UIWindow*)_popupWindow {
    if (!g_popupWindow) {
        CGRect popupRect;
        popupRect.origin.x = 0;
        popupRect.origin.y = 0;
        popupRect.size.width = DisplayProperties::ScreenWidth();
        popupRect.size.height = DisplayProperties::ScreenHeight();

        // Allocate a top-level, yet hidden UIWindow for displaying our popups
        g_popupWindow = [[UIWindow alloc] initWithFrame:popupRect];
        [g_popupWindow setWindowLevel:100000.0f];
    }

    return g_popupWindow;
}

/**
 @Status Interoperable
*/
- (int)applicationIconBadgeNumber {
    return _applicationIconBadgeNumber;
}

/**
 @Status NotInPlan
 This will return UIRemoteNotificationTypeNone until we interop with our Notification system.
*/
- (UIRemoteNotificationType)enabledRemoteNotificationTypes {
    return UIRemoteNotificationTypeNone;
}

/**
 @Status NotInPlan
*/
- (void)cancelAllLocalNotifications {
    UNIMPLEMENTED();
}

/**
 @Status NotInPlan
*/
- (void)cancelLocalNotification:(UILocalNotification*)notification {
    UNIMPLEMENTED();
}

/**
 @Status NotInPlan
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

        // Wake/unblock the main run loop so it starts processing messages again.
        [[NSRunLoop mainRunLoop] _wakeUp];

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

- (void)_sendToastActionReceivedEvent:(NSDictionary*)toastAction {
    if ([self.delegate respondsToSelector:@selector(application:didReceiveToastAction:)]) {
        [self.delegate application:sharedApplication didReceiveToastAction:toastAction];
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
}

- (void)_sendVoiceCommandReceivedEvent:(WMSSpeechRecognitionResult*)result {
    if ([self.delegate respondsToSelector:@selector(application:didReceiveVoiceCommand:)]) {
        [self.delegate application:sharedApplication didReceiveVoiceCommand:result];
    }
}

- (void)_sendFileReceivedEvent:(WAAFileActivatedEventArgs*)result {
    if ([self.delegate respondsToSelector:@selector(application:didReceiveFile:)]) {
        [self.delegate application:sharedApplication didReceiveFile:result];
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

    for (UIWindow* window in g_windows) {
        _sendMemoryWarningToViewControllers(window);
    }
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
 @Status NotInPlan
*/
- (BOOL)isRegisteredForRemoteNotifications {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status NotInPlan
*/
- (void)registerForRemoteNotifications {
    UNIMPLEMENTED();
}

/**
 @Status NotInPlan
*/
- (BOOL)setKeepAliveTimeout:(NSTimeInterval)timeout handler:(void (^)(void))keepAliveHandler {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status NotInPlan
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
 @Status NotInPlan
*/
- (void)clearKeepAliveTimeout {
    UNIMPLEMENTED();
}

/**
 @Status NotInPlan
*/
- (void)completeStateRestoration {
    UNIMPLEMENTED();
}

/**
 @Status NotInPlan
*/
- (void)extendStateRestoration {
    UNIMPLEMENTED();
}

/**
 @Status NotInPlan
*/
- (void)ignoreSnapshotOnNextApplicationLaunch {
    UNIMPLEMENTED();
}

/**
 @Status NotInPlan
*/
- (void)setMinimumBackgroundFetchInterval:(NSTimeInterval)minimumBackgroundFetchInterval {
    UNIMPLEMENTED();
}

/**
 @Status NotInPlan
*/
- (void)setNewsstandIconImage:(UIImage*)image {
    UNIMPLEMENTED();
}

/**
 @Status NotInPlan
 @Notes UWP status bar can be directly accessed via WinRT APIs, and will eventually be supported via UIViewController APIs.
*/
- (void)setStatusBarStyle:(UIStatusBarStyle)statusBarStyle animated:(BOOL)animated {
    UNIMPLEMENTED_WITH_MSG("UWP status bar can be directly accessed via WinRT APIs, and will eventually be supported via UIViewController APIs.");
}

/**
 @Status NotInPlan
*/
- (void)unregisterForRemoteNotifications {
    UNIMPLEMENTED();
}

/**
 @Status NotInPlan
*/
+ (void)registerObjectForStateRestoration:(id<UIStateRestoring>)object restorationIdentifier:(NSString*)restorationIdentifier {
    UNIMPLEMENTED();
}

@end

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
    DisplayProperties::ScreenRotation newRotation = DisplayProperties::ScreenRotationNone;

    switch (_presentationTransform) {
        case UIInterfaceOrientationPortraitUpsideDown:
            newRotation = DisplayProperties::ScreenRotation180;
            break;

        case UIInterfaceOrientationLandscapeLeft:
            newRotation = DisplayProperties::ScreenRotation90CounterClockwise;
            break;

        case UIInterfaceOrientationLandscapeRight:
            newRotation = DisplayProperties::ScreenRotation90Clockwise;
            break;
    }

    DisplayProperties::SetTablet(_operationMode == WOCOperationModeTablet);
    DisplayProperties::SetScreenSize(newWidth, newHeight, newMagnification, newRotation);
    DisplayProperties::SetDeviceSize(newWidth, newHeight);

    //  Adjust size of all UIWindows
    CGRect curBounds;
    curBounds.origin.x = 0.0f;
    curBounds.origin.y = 0.0f;
    curBounds.size.width = newWidth;
    curBounds.size.height = newHeight;
    bool isFrameSet = false;
    for (UIWindow* current in g_windows) {
        if (current.sizeUIWindowToFit) {
            [current setFrame:curBounds];
            isFrameSet = true;
        }
    }

    if (isFrameSet) {
        [UIApplication _viewTreeChanged];
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
        _hostScale = ((float)DisplayInformation::GetForCurrentView().ResolutionScale()) / 100.0f;
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
        float dpi = DisplayInformation::GetForCurrentView().LogicalDpi();

        _hostScreenDpi.width = dpi;
        _hostScreenDpi.height = dpi;
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
