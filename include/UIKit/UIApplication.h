/*
* Copyright (c) 2011, The Iconfactory. All rights reserved.
* Copyright (c) 2016 Microsoft Corporation. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* 1. Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*
* 2. Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
*
* 3. Neither the name of The Iconfactory nor the names of its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE ICONFACTORY BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
* ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

#import <UIKit/UIResponder.h>
#import <UIKit/UIDevice.h>
#import <StarboardExport.h>
#import <stdint.h>

UIKIT_EXPORT NSString* const UIApplicationStatusBarOrientationUserInfoKey;
UIKIT_EXPORT NSString* const UIApplicationStatusBarFrameUserInfoKey;

UIKIT_EXPORT NSString* const UIApplicationDidChangeStatusBarFrameNotification;
UIKIT_EXPORT NSString* const UIApplicationWillChangeStatusBarOrientationNotification;
UIKIT_EXPORT NSString* const UIApplicationDidChangeStatusBarOrientationNotification;
UIKIT_EXPORT NSString* const UIApplicationWillEnterForegroundNotification;
UIKIT_EXPORT NSString* const UIApplicationWillTerminateNotification;
UIKIT_EXPORT NSString* const UIApplicationWillResignActiveNotification;
UIKIT_EXPORT NSString* const UIApplicationDidEnterBackgroundNotification;
UIKIT_EXPORT NSString* const UIApplicationDidBecomeActiveNotification;
UIKIT_EXPORT NSString* const UIApplicationDidFinishLaunchingNotification;
UIKIT_EXPORT NSString* const UIApplicationSignificantTimeChangeNotification;

UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsURLKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsSourceApplicationKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsRemoteNotificationKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsVoiceCommandKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsProtocolKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsAnnotationKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsLocalNotificationKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsLocationKey;

UIKIT_EXPORT NSString* const UIApplicationDidReceiveMemoryWarningNotification;
UIKIT_EXPORT NSString* const UIApplicationWillChangeStatusBarFrameNotification;

UIKIT_EXPORT NSString* const UIApplicationWillChangeDisplayModeNofication;
UIKIT_EXPORT NSString* const UIApplicationDidChangeDisplayModeNofication;

UIKIT_EXPORT NSString* const UITrackingRunLoopMode;

UIKIT_EXPORT NSString* const UIContentSizeCategoryAccessibilityExtraExtraExtraLarge;
UIKIT_EXPORT NSString* const UIContentSizeCategoryAccessibilityExtraExtraLarge;
UIKIT_EXPORT NSString* const UIContentSizeCategoryExtraExtraLarge;
UIKIT_EXPORT NSString* const UIContentSizeCategoryExtraExtraExtraLarge;
UIKIT_EXPORT NSString* const UIContentSizeCategoryAccessibilityExtraLarge;
UIKIT_EXPORT NSString* const UIContentSizeCategoryExtraLarge;
UIKIT_EXPORT NSString* const UIContentSizeCategoryAccessibilityLarge;
UIKIT_EXPORT NSString* const UIContentSizeCategoryLarge;
UIKIT_EXPORT NSString* const UIContentSizeCategoryAccessibilityMedium;
UIKIT_EXPORT NSString* const UIContentSizeCategoryMedium;
UIKIT_EXPORT NSString* const UIContentSizeCategorySmall;
UIKIT_EXPORT NSString* const UIContentSizeCategoryExtraSmall;

UIKIT_EXPORT const NSTimeInterval UIApplicationBackgroundFetchIntervalMinimum;
UIKIT_EXPORT const NSTimeInterval UIApplicationBackgroundFetchIntervalNever;

UIKIT_EXPORT NSString* const UIApplicationInvalidInterfaceOrientationException;
UIKIT_EXPORT NSString* const UIApplicationKeyboardExtensionPointIdentifier;
UIKIT_EXPORT NSString* const UIApplicationOpenSettingsURLString;
UIKIT_EXPORT NSString* const UIApplicationKeyboardExtensionPointIdentifier;
UIKIT_EXPORT NSString* const UIContentSizeCategoryNewValueKey;

UIKIT_EXPORT NSString* const UIApplicationBackgroundRefreshStatusDidChangeNotification;
UIKIT_EXPORT NSString* const UIApplicationProtectedDataDidBecomeAvailable;
UIKIT_EXPORT NSString* const UIApplicationProtectedDataWillBecomeUnavailable;
UIKIT_EXPORT NSString* const UIApplicationUserDidTakeScreenshotNotification;
UIKIT_EXPORT NSString* const UIContentSizeCategoryDidChangeNotification;

typedef NSUInteger UIBackgroundTaskIdentifier;
UIKIT_EXPORT const UIBackgroundTaskIdentifier UIBackgroundTaskInvalid;

// We may want to revisit these eventually:
#define UIInterfaceOrientationIsPortrait(orientation) \
    ((orientation) == UIInterfaceOrientationPortrait || (orientation) == UIInterfaceOrientationPortraitUpsideDown)

#define UIInterfaceOrientationIsLandscape(orientation) \
    ((orientation) == UIInterfaceOrientationLandscapeLeft || (orientation) == UIInterfaceOrientationLandscapeRight)

#define UIDeviceOrientationIsValidInterfaceOrientation(orientation)                                            \
    ((orientation) == UIDeviceOrientationPortrait || (orientation) == UIDeviceOrientationPortraitUpsideDown || \
     (orientation) == UIDeviceOrientationLandscapeLeft || (orientation) == UIDeviceOrientationLandscapeRight)

#define UIDeviceOrientationIsPortrait(orientation) \
    ((orientation) == UIDeviceOrientationPortrait || (orientation) == UIDeviceOrientationPortraitUpsideDown)

#define UIDeviceOrientationIsLandscape(orientation) \
    ((orientation) == UIDeviceOrientationLandscapeLeft || (orientation) == UIDeviceOrientationLandscapeRight)

typedef NSUInteger UIBackgroundTaskIdentifier;
typedef enum : NSUInteger {
    UIRemoteNotificationTypeNone = 0,
    UIRemoteNotificationTypeBadge = 1 << 0,
    UIRemoteNotificationTypeSound = 1 << 1,
    UIRemoteNotificationTypeAlert = 1 << 2,
    UIRemoteNotificationTypeNewsstandContentAvailability = 1 << 3,
} UIRemoteNotificationType;

typedef enum : NSInteger {
    UIStatusBarStyleDefault,
    UIStatusBarStyleLightContent,
    UIStatusBarStyleBlackTranslucent,
    UIStatusBarStyleBlackOpaque,
} UIStatusBarStyle;

typedef enum : NSInteger {
    UIStatusBarAnimationNone,
    UIStatusBarAnimationFade,
    UIStatusBarAnimationSlide,
} UIStatusBarAnimation;

// whenever the NSApplication is no longer "active" from OSX's point of view, your UIApplication instance
// will switch to UIApplicationStateInactive. This happens when the app is no longer in the foreground, for instance.
// chameleon will also switch to the inactive state when the screen is put to sleep due to power saving mode.
// when the screen wakes up or the app is brought to the foreground, it is switched back to UIApplicationStateActive.
//
// UIApplicationStateBackground is now supported and your app will transition to this state in two possible ways.
// one is when the AppKitIntegration method -terminateApplicationBeforeDate: is called. that method is intended to be
// used when your NSApplicationDelegate is being asked to terminate. the application is also switched to
// UIApplicationStateBackground when the machine is put to sleep. when the machine is reawakened, it will transition
// back to UIApplicationStateInactive (as per the UIKit docs). The OS tends to reactive the app in the usual way if
// it happened to be the foreground app when the machine was put to sleep, so it should ultimately work out as expected.
//
// any registered background tasks are allowed to complete whenever the app switches into UIApplicationStateBackground
// mode, so that means that when -terminateApplicationBeforeDate: is called directly, we will wait on background tasks
// and also show an alert to the user letting them know what's happening. it also means we attempt to delay machine
// sleep whenever sleep is initiated for as long as we can until any pending background tasks are completed. (there is no
// alert in that case) this should allow your app time to do any of the usual things like sync with network services or
// save state. just as on iOS, there's no guarentee you'll have time to complete you background task and there's no
// guarentee that your expiration handler will even be called. additionally, the reliability of your network is certainly
// going to be suspect when entering sleep as well. so be aware - but basically these same constraints exist on iOS so
// in many respects it shouldn't affect your code much or at all.
typedef enum : NSInteger {
    UIApplicationStateActive,
    UIApplicationStateInactive,
    UIApplicationStateBackground,
} UIApplicationState;

typedef enum : NSUInteger {
    UIBackgroundFetchResultNewData,
    UIBackgroundFetchResultNoData,
    UIBackgroundFetchResultFailed,
} UIBackgroundFetchResult;

typedef enum : NSUInteger {
    UIBackgroundRefreshStatusRestricted,
    UIBackgroundRefreshStatusDenied,
    UIBackgroundRefreshStatusAvailable,
} UIBackgroundRefreshStatus;

enum {
    UIInterfaceOrientationUnknown = UIDeviceOrientationUnknown,
    UIInterfaceOrientationPortrait = UIDeviceOrientationPortrait,
    UIInterfaceOrientationPortraitUpsideDown = UIDeviceOrientationPortraitUpsideDown,
    UIInterfaceOrientationLandscapeLeft = UIDeviceOrientationLandscapeRight,
    UIInterfaceOrientationLandscapeRight = UIDeviceOrientationLandscapeLeft,
};
typedef NSUInteger UIInterfaceOrientation;

typedef enum : NSUInteger {
    UIInterfaceOrientationMaskPortrait = (1 << UIInterfaceOrientationPortrait),
    UIInterfaceOrientationMaskLandscapeLeft = (1 << UIInterfaceOrientationLandscapeLeft),
    UIInterfaceOrientationMaskLandscapeRight = (1 << UIInterfaceOrientationLandscapeRight),
    UIInterfaceOrientationMaskPortraitUpsideDown = (1 << UIInterfaceOrientationPortraitUpsideDown),
    UIInterfaceOrientationMaskLandscape = (UIInterfaceOrientationMaskLandscapeLeft | UIInterfaceOrientationMaskLandscapeRight),
    UIInterfaceOrientationMaskAll = (UIInterfaceOrientationMaskPortrait | UIInterfaceOrientationMaskLandscapeLeft |
                                     UIInterfaceOrientationMaskLandscapeRight | UIInterfaceOrientationMaskPortraitUpsideDown),
    UIInterfaceOrientationMaskAllButUpsideDown =
        (UIInterfaceOrientationMaskPortrait | UIInterfaceOrientationMaskLandscapeLeft | UIInterfaceOrientationMaskLandscapeRight),
} UIInterfaceOrientationMask;

typedef enum : NSInteger {
    UIUserInterfaceLayoutDirectionLeftToRight,
    UIUserInterfaceLayoutDirectionRightToLeft,
} UIUserInterfaceLayoutDirection;

UIKIT_EXPORT int UIApplicationMain(int argc, char* argv[], NSString* pClassName, NSString* dClassName);
UIKIT_EXPORT void UIApplicationInitialize(const wchar_t* principalClass, const wchar_t* delegateClass);
UIKIT_EXPORT const UIBackgroundTaskIdentifier UIBackgroundTaskInvalid;
UIKIT_EXPORT const NSTimeInterval UIMinimumKeepAliveTimeout;

@class UIWindow, UIApplication, UILocalNotification, UIUserNotificationSettings, UIImage;
@protocol UIApplicationDelegate
, UIStateRestoring;

UIKIT_EXPORT_CLASS
@interface UIApplication : UIResponder

+ (UIApplication*)sharedApplication;
+ (void)registerObjectForStateRestoration:(id<UIStateRestoring>)object restorationIdentifier:(NSString*)restorationIdentifier STUB_METHOD;
- (BOOL)canOpenURL:(NSURL*)URL;
- (BOOL)isIgnoringInteractionEvents;
- (BOOL)isRegisteredForRemoteNotifications;
- (BOOL)openURL:(NSURL*)url;
- (BOOL)sendAction:(SEL)action to:(id)target from:(id)sender forEvent:(UIEvent*)event;
- (BOOL)setKeepAliveTimeout:(NSTimeInterval)timeout handler:(void (^)(void))keepAliveHandler STUB_METHOD;
- (UIBackgroundTaskIdentifier)beginBackgroundTaskWithExpirationHandler:(void (^)(void))handler;
- (UIBackgroundTaskIdentifier)beginBackgroundTaskWithName:(NSString*)taskName expirationHandler:(void (^)(void))handler STUB_METHOD;
- (UIInterfaceOrientationMask)supportedInterfaceOrientationsForWindow:(UIWindow*)window STUB_METHOD;
- (UIRemoteNotificationType)enabledRemoteNotificationTypes;
- (UIUserNotificationSettings*)currentUserNotificationSettings STUB_METHOD;
- (void)beginIgnoringInteractionEvents;
- (void)beginReceivingRemoteControlEvents;
- (void)cancelAllLocalNotifications;
- (void)cancelLocalNotification:(UILocalNotification*)notification;
- (void)clearKeepAliveTimeout STUB_METHOD;
- (void)completeStateRestoration STUB_METHOD;
- (void)endBackgroundTask:(UIBackgroundTaskIdentifier)identifier;
- (void)endIgnoringInteractionEvents;
- (void)endReceivingRemoteControlEvents STUB_METHOD;
- (void)extendStateRestoration STUB_METHOD;
- (void)ignoreSnapshotOnNextApplicationLaunch STUB_METHOD;
- (void)presentLocalNotificationNow:(UILocalNotification*)notification;
- (void)registerForRemoteNotificationTypes:(UIRemoteNotificationType)types;
- (void)registerForRemoteNotifications;
- (void)registerUserNotificationSettings:(UIUserNotificationSettings*)notificationSettings;
- (void)scheduleLocalNotification:(UILocalNotification*)notification;
- (void)sendEvent:(UIEvent*)event STUB_METHOD;
- (void)setMinimumBackgroundFetchInterval:(NSTimeInterval)minimumBackgroundFetchInterval STUB_METHOD;
- (void)setNewsstandIconImage:(UIImage*)image STUB_METHOD;
- (void)setStatusBarHidden:(BOOL)hidden animated:(BOOL)animated;
- (void)setStatusBarHidden:(BOOL)hidden withAnimation:(UIStatusBarAnimation)animation;
- (void)setStatusBarOrientation:(UIInterfaceOrientation)interfaceOrientation animated:(BOOL)animated;
- (void)setStatusBarStyle:(UIStatusBarStyle)statusBarStyle animated:(BOOL)animated STUB_METHOD;
- (void)unregisterForRemoteNotifications STUB_METHOD;
@property (copy, nonatomic) NSArray* scheduledLocalNotifications STUB_PROPERTY;
@property (copy, nonatomic) NSArray* shortcutItems STUB_PROPERTY;
@property (getter=isIdleTimerDisabled, nonatomic) BOOL idleTimerDisabled;
@property (getter=isNetworkActivityIndicatorVisible, nonatomic) BOOL networkActivityIndicatorVisible STUB_PROPERTY;
@property (getter=isProximitySensingEnabled, nonatomic) BOOL proximitySensingEnabled STUB_PROPERTY;
@property (nonatomic) BOOL applicationSupportsShakeToEdit STUB_PROPERTY;
@property (nonatomic) NSInteger applicationIconBadgeNumber;
@property (nonatomic) UIInterfaceOrientation statusBarOrientation;
@property (nonatomic, assign) id<UIApplicationDelegate> delegate;
@property (nonatomic, copy) NSString* preferredContentSizeCategory;
@property (nonatomic, getter=isStatusBarHidden) BOOL statusBarHidden;
@property (nonatomic, readonly) CGRect statusBarFrame;
@property (nonatomic, readonly) NSArray* windows;
@property (nonatomic, readonly) NSTimeInterval statusBarOrientationAnimationDuration;
@property (nonatomic, readonly) UIApplicationState applicationState; // see notes near UIApplicationState struct for details!
@property (nonatomic, readonly) UIUserInterfaceLayoutDirection userInterfaceLayoutDirection;
@property (nonatomic, readonly) UIWindow* keyWindow;
@property (readonly, getter=isProtectedDataAvailable, nonatomic) BOOL protectedDataAvailable STUB_PROPERTY;
@property (readonly, nonatomic) NSTimeInterval backgroundTimeRemaining STUB_PROPERTY;
@property (readonly, nonatomic) UIBackgroundRefreshStatus backgroundRefreshStatus STUB_PROPERTY;
@property (readonly, nonatomic) UIStatusBarStyle statusBarStyle STUB_PROPERTY;

@end

@interface UIApplication (UIApplicationDeprecated)
- (void)setStatusBarHidden:(BOOL)hidden animated:(BOOL)animated __attribute__((deprecated)); // use -setStatusBarHidden:withAnimation:
@end

@interface UIApplication (UIApplicationStarboardAdditions)
- (void)registerForRemoteNotificationTypes:(UIRemoteNotificationType)types withId:(NSString*)id;
@end

enum {
    WOCDisplayPresetPhone320x480,
    WOCDisplayPresetPhone320x568,
    WOCDisplayPresetTablet768x1024,
    WOCDisplayPresetNative,
    WOCDisplayPresetNative2x,
    WOCDisplayPresetNative320Fixed,
    WOCDisplayPresetNative768Fixed,
    WOCDisplayPresetNative4x3Aspect,
    WOCDisplayPresetNative16x9Aspect,
};
typedef uint32_t WOCDisplayPreset;

enum {
    WOCOperationModePhone,
    WOCOperationModeTablet,
};
typedef uint32_t WOCOperationMode;

enum {
    WOCDevicePhone,
    WOCDeviceTablet,
    WOCDeviceDesktop,
};
typedef uint32_t WOCDeviceType;

/**
 @Public No
*/
@interface WOCDisplayMode : NSObject

@property (nonatomic) float magnification;
@property (nonatomic) float fixedWidth;
@property (nonatomic) float fixedHeight;
@property (nonatomic) double fixedAspectRatio;
@property (nonatomic) BOOL autoMagnification;
@property (nonatomic) BOOL sizeUIWindowToFit;
@property (nonatomic) BOOL useHostScaleFactor;
@property (nonatomic) BOOL clampScaleToClosestExpected;
@property (nonatomic) WOCOperationMode operationMode;
@property (nonatomic) UIInterfaceOrientation presentationTransform;

@property (nonatomic, readonly) CGSize currentSize;
@property (nonatomic, readonly) float currentMagnification;

@property (nonatomic, readonly) CGSize hostWindowSize;
@property (nonatomic, readonly) CGSize hostScreenSizePixels;
@property (nonatomic, readonly) float hostScreenScale;

@property (nonatomic, readonly) CGSize hostScreenSizePoints;
@property (nonatomic, readonly) CGSize hostScreenSizeInches;
@property (nonatomic, readonly) float hostScreenDiagonalInches;

@property (nonatomic, readonly) WOCDeviceType hostDeviceType;

- (void)setDisplayPreset:(WOCDisplayPreset)mode;
- (void)updateDisplaySettings;

// Note: Will be deprecated in future releases
@property (nonatomic) BOOL useLegacyHitTesting;
@end

@interface UIApplication (UIApplicationDisplayMode)
+ (WOCDisplayMode*)displayMode;
@end

// Implement this category attached to UIApplication to override startup defaults
@interface UIApplication (UIApplicationInitialStartupMode)
+ (void)setStartupDisplayMode:(WOCDisplayMode*)mode;
@end
