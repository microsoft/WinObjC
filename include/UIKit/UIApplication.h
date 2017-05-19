/*
* Copyright (c) 2011, The Iconfactory. All rights reserved.
* Copyright (c) Microsoft Corporation. All rights reserved.
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

#import <UIKit/UIDevice.h>
#import <UIKit/UIResponder.h>
#import <StarboardExport.h>
#import <CoreGraphics/CGBase.h>
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
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsToastActionKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsVoiceCommandKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsProtocolKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsFileKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsAnnotationKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsLocalNotificationKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsLocationKey;

UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsToastActionArgumentKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsToastActionUserInputKey;

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
+ (void)registerObjectForStateRestoration:(id<UIStateRestoring>)object
                    restorationIdentifier:(NSString*)restorationIdentifier NOTINPLAN_METHOD;
- (BOOL)canOpenURL:(NSURL*)URL;
- (BOOL)isIgnoringInteractionEvents;
- (BOOL)isRegisteredForRemoteNotifications NOTINPLAN_METHOD;
- (BOOL)openURL:(NSURL*)url;
- (BOOL)sendAction:(SEL)action to:(id)target from:(id)sender forEvent:(UIEvent*)event;
- (BOOL)setKeepAliveTimeout:(NSTimeInterval)timeout handler:(void (^)(void))keepAliveHandler NOTINPLAN_METHOD;
- (UIBackgroundTaskIdentifier)beginBackgroundTaskWithExpirationHandler:(void (^)(void))handler;
- (UIBackgroundTaskIdentifier)beginBackgroundTaskWithName:(NSString*)taskName expirationHandler:(void (^)(void))handler STUB_METHOD;
- (UIInterfaceOrientationMask)supportedInterfaceOrientationsForWindow:(UIWindow*)window NOTINPLAN_METHOD;
- (UIRemoteNotificationType)enabledRemoteNotificationTypes NOTINPLAN_METHOD;
- (UIUserNotificationSettings*)currentUserNotificationSettings STUB_METHOD;
- (void)beginIgnoringInteractionEvents;
- (void)beginReceivingRemoteControlEvents NOTINPLAN_METHOD;
- (void)cancelAllLocalNotifications NOTINPLAN_METHOD;
- (void)cancelLocalNotification:(UILocalNotification*)notification NOTINPLAN_METHOD;
- (void)clearKeepAliveTimeout NOTINPLAN_METHOD;
- (void)completeStateRestoration NOTINPLAN_METHOD;
- (void)endBackgroundTask:(UIBackgroundTaskIdentifier)identifier;
- (void)endIgnoringInteractionEvents;
- (void)endReceivingRemoteControlEvents NOTINPLAN_METHOD;
- (void)extendStateRestoration NOTINPLAN_METHOD;
- (void)ignoreSnapshotOnNextApplicationLaunch NOTINPLAN_METHOD;
- (void)presentLocalNotificationNow:(UILocalNotification*)notification NOTINPLAN_METHOD;
- (void)registerForRemoteNotificationTypes:(UIRemoteNotificationType)types NOTINPLAN_METHOD;
- (void)registerForRemoteNotifications NOTINPLAN_METHOD;
- (void)registerUserNotificationSettings:(UIUserNotificationSettings*)notificationSettings NOTINPLAN_METHOD;
- (void)scheduleLocalNotification:(UILocalNotification*)notification NOTINPLAN_METHOD;
- (void)sendEvent:(UIEvent*)event NOTINPLAN_METHOD;
- (void)setMinimumBackgroundFetchInterval:(NSTimeInterval)minimumBackgroundFetchInterval NOTINPLAN_METHOD;
- (void)setNewsstandIconImage:(UIImage*)image NOTINPLAN_METHOD;
- (void)setStatusBarHidden:(BOOL)hidden animated:(BOOL)animated NOTINPLAN_METHOD;
- (void)setStatusBarHidden:(BOOL)hidden withAnimation:(UIStatusBarAnimation)animation NOTINPLAN_METHOD;
- (void)setStatusBarOrientation:(UIInterfaceOrientation)interfaceOrientation animated:(BOOL)animated NOTINPLAN_METHOD;
- (void)setStatusBarStyle:(UIStatusBarStyle)statusBarStyle animated:(BOOL)animated NOTINPLAN_METHOD;
- (void)unregisterForRemoteNotifications NOTINPLAN_METHOD;
@property (copy, nonatomic) NSArray* scheduledLocalNotifications NOTINPLAN_PROPERTY;
@property (copy, nonatomic) NSArray* shortcutItems NOTINPLAN_PROPERTY;
@property (getter=isIdleTimerDisabled, nonatomic) BOOL idleTimerDisabled;
@property (getter=isNetworkActivityIndicatorVisible, nonatomic) BOOL networkActivityIndicatorVisible NOTINPLAN_PROPERTY;
@property (getter=isProximitySensingEnabled, nonatomic) BOOL proximitySensingEnabled NOTINPLAN_PROPERTY;
@property (nonatomic) BOOL applicationSupportsShakeToEdit NOTINPLAN_PROPERTY;
@property (nonatomic) NSInteger applicationIconBadgeNumber;
@property (nonatomic) UIInterfaceOrientation statusBarOrientation NOTINPLAN_PROPERTY;
@property (nonatomic, assign) id<UIApplicationDelegate> delegate;
@property (nonatomic, copy) NSString* preferredContentSizeCategory NOTINPLAN_PROPERTY;
@property (nonatomic, getter=isStatusBarHidden) BOOL statusBarHidden NOTINPLAN_PROPERTY;
@property (nonatomic, readonly) CGRect statusBarFrame NOTINPLAN_PROPERTY;
@property (nonatomic, readonly) NSArray<UIWindow*>* windows;
@property (nonatomic, readonly) NSTimeInterval statusBarOrientationAnimationDuration NOTINPLAN_PROPERTY;
@property (nonatomic, readonly) UIApplicationState applicationState;
@property (nonatomic, readonly) UIUserInterfaceLayoutDirection userInterfaceLayoutDirection NOTINPLAN_PROPERTY;
@property (nonatomic, readonly) UIWindow* keyWindow;
@property (readonly, getter=isProtectedDataAvailable, nonatomic) BOOL protectedDataAvailable STUB_PROPERTY;
@property (readonly, nonatomic) NSTimeInterval backgroundTimeRemaining STUB_PROPERTY;
@property (readonly, nonatomic) UIBackgroundRefreshStatus backgroundRefreshStatus STUB_PROPERTY;
@property (readonly, nonatomic) UIStatusBarStyle statusBarStyle STUB_PROPERTY;

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

// Note: Will be deprecated in future releases
@property (nonatomic) BOOL useLegacyBatchedCATransactions;
@end

@interface UIApplication (UIApplicationDisplayMode)
+ (WOCDisplayMode*)displayMode;
@end

// Implement this category attached to UIApplication to override startup defaults
@interface UIApplication (UIApplicationInitialStartupMode)
+ (void)setStartupDisplayMode:(WOCDisplayMode*)mode;
@end

// Necessary to prevent crash in apps that neglect to pull in the delegate header.
// Tracked as #1647.
#import <UIKit/UIApplicationDelegate.h>