/*
 * Copyright (c) 2011, The Iconfactory. All rights reserved.
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

#ifndef _UIAPPLICATION_H_
#define _UIAPPLICATION_H_

#import "UIResponder.h"
#import "UIDevice.h"
#import "UIApplicationDelegate.h"
#import <UIKit/UIAlert.h>
#import <StarboardExport.h>
#import <stdint.h>

UIKIT_EXPORT NSString *const UIApplicationStatusBarOrientationUserInfoKey;
UIKIT_EXPORT NSString *const UIApplicationStatusBarFrameUserInfoKey;

UIKIT_EXPORT NSString *UIApplicationDidChangeStatusBarFrameNotification;
UIKIT_EXPORT NSString *const UIApplicationWillChangeStatusBarOrientationNotification;
UIKIT_EXPORT NSString *const UIApplicationDidChangeStatusBarOrientationNotification;
UIKIT_EXPORT NSString *const UIApplicationWillEnterForegroundNotification;
UIKIT_EXPORT NSString *const UIApplicationWillTerminateNotification;
UIKIT_EXPORT NSString *const UIApplicationWillResignActiveNotification;
UIKIT_EXPORT NSString *const UIApplicationDidEnterBackgroundNotification;
UIKIT_EXPORT NSString *const UIApplicationDidBecomeActiveNotification;
UIKIT_EXPORT NSString *const UIApplicationDidFinishLaunchingNotification;
UIKIT_EXPORT NSString *const UIApplicationSignificantTimeChangeNotification;

UIKIT_EXPORT NSString *const UIApplicationLaunchOptionsURLKey;
UIKIT_EXPORT NSString *const UIApplicationLaunchOptionsSourceApplicationKey;
UIKIT_EXPORT NSString *const UIApplicationLaunchOptionsRemoteNotificationKey;
UIKIT_EXPORT NSString *const UIApplicationLaunchOptionsAnnotationKey;
UIKIT_EXPORT NSString *const UIApplicationLaunchOptionsLocalNotificationKey;
UIKIT_EXPORT NSString *const UIApplicationLaunchOptionsLocationKey;

UIKIT_EXPORT NSString *const UIApplicationDidReceiveMemoryWarningNotification;
UIKIT_EXPORT NSString *const UIApplicationWillChangeStatusBarFrameNotification;

UIKIT_EXPORT NSString *const UIApplicationWillChangeDisplayModeNofication;
UIKIT_EXPORT NSString *const UIApplicationDidChangeDisplayModeNofication;

UIKIT_EXPORT NSString *const UITrackingRunLoopMode;

//  UIApplicationMain is included in the static runtime component
SB_EXPORT int UIApplicationMain(int argc, char *argv[], NSString *pClassName, NSString *dClassName);

UIKIT_EXPORT int UIApplicationMainInit(int argc, char *argv[], NSString *pClassName, NSString *dClassName, int defaultOrientation);
UIKIT_EXPORT int UIApplicationMainLoop();

enum {
    UIStatusBarAnimationNone,
    UIStatusBarAnimationFade,
    UIStatusBarAnimationSlide,
};
typedef uint32_t UIStatusBarAnimation;

enum {
    UIUserInterfaceLayoutDirectionLeftToRight,
    UIUserInterfaceLayoutDirectionRightToLeft
};
typedef NSInteger UIUserInterfaceLayoutDirection;

enum {
    UIStatusBarStyleDefault,
    UIStatusBarStyleLightContent,
    UIStatusBarStyleBlackTranslucent,
    UIStatusBarStyleBlackOpaque
};
typedef uint32_t UIStatusBarStyle;

enum {
    UIInterfaceOrientationPortrait = UIDeviceOrientationPortrait,
    UIInterfaceOrientationPortraitUpsideDown = UIDeviceOrientationPortraitUpsideDown,
    UIInterfaceOrientationLandscapeLeft = UIDeviceOrientationLandscapeRight,
    UIInterfaceOrientationLandscapeRight = UIDeviceOrientationLandscapeLeft,

    UIInterfaceOrientationUnknown = UIDeviceOrientationUnknown,
};
typedef uint32_t UIInterfaceOrientation;

enum {
    UIInterfaceOrientationMaskPortrait = (1 << UIInterfaceOrientationPortrait),
    UIInterfaceOrientationMaskLandscapeLeft = (1 << UIInterfaceOrientationLandscapeLeft),
    UIInterfaceOrientationMaskLandscapeRight = (1 << UIInterfaceOrientationLandscapeRight),
    UIInterfaceOrientationMaskPortraitUpsideDown = (1 << UIInterfaceOrientationPortraitUpsideDown),
    UIInterfaceOrientationMaskLandscape = (UIInterfaceOrientationMaskLandscapeLeft | UIInterfaceOrientationMaskLandscapeRight),
    UIInterfaceOrientationMaskAll = (UIInterfaceOrientationMaskPortrait | UIInterfaceOrientationMaskLandscapeLeft | UIInterfaceOrientationMaskLandscapeRight | UIInterfaceOrientationMaskPortraitUpsideDown),
    UIInterfaceOrientationMaskAllButUpsideDown = (UIInterfaceOrientationMaskPortrait | UIInterfaceOrientationMaskLandscapeLeft | UIInterfaceOrientationMaskLandscapeRight),
};
typedef uint32_t UIInterfaceOrientationMask;

#define UIInterfaceOrientationIsPortrait(orientation) \
((orientation) == UIInterfaceOrientationPortrait || \
(orientation) == UIInterfaceOrientationPortraitUpsideDown)

#define UIInterfaceOrientationIsLandscape(orientation) \
((orientation) == UIInterfaceOrientationLandscapeLeft || \
(orientation) == UIInterfaceOrientationLandscapeRight)

#define UIDeviceOrientationIsValidInterfaceOrientation(orientation) \
((orientation) == UIDeviceOrientationPortrait || \
(orientation) == UIDeviceOrientationPortraitUpsideDown || \
(orientation) == UIDeviceOrientationLandscapeLeft || \
(orientation) == UIDeviceOrientationLandscapeRight)

// push is not gonna work in mac os, unless you are apple (facetime)
enum {
  UIRemoteNotificationTypeNone    = 0,
  UIRemoteNotificationTypeBadge   = 1 << 0,
  UIRemoteNotificationTypeSound   = 1 << 1,
  UIRemoteNotificationTypeAlert   = 1 << 2
};
typedef uint32_t UIRemoteNotificationType;

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
enum {
  UIApplicationStateActive,
  UIApplicationStateInactive,
  UIApplicationStateBackground
};
typedef uint32_t UIApplicationState;

typedef NSUInteger UIBackgroundTaskIdentifier;

UIKIT_EXPORT const UIBackgroundTaskIdentifier UIBackgroundTaskInvalid;
UIKIT_EXPORT const NSTimeInterval UIMinimumKeepAliveTimeout;

@class UIWindow, UIApplication, UILocalNotification;

UIKIT_EXPORT_CLASS
@interface UIApplication : UIResponder 

+ (UIApplication *)sharedApplication;

- (BOOL)sendAction:(SEL)action to:(id)target from:(id)sender forEvent:(UIEvent *)event;
- (void)sendEvent:(UIEvent *)event;

- (BOOL)openURL:(NSURL *)url;
- (BOOL)canOpenURL:(NSURL *)URL;

- (void)setStatusBarStyle:(UIStatusBarStyle)statusBarStyle animated:(BOOL)animated;  // no effect

- (void)beginIgnoringInteractionEvents;
- (void)endIgnoringInteractionEvents;
- (BOOL)isIgnoringInteractionEvents;

- (void)presentLocalNotificationNow:(UILocalNotification *)notification;
- (void)cancelLocalNotification:(UILocalNotification *)notification;
- (void)cancelAllLocalNotifications;
- (void)scheduleLocalNotification:(UILocalNotification *)notification;

- (UIBackgroundTaskIdentifier)beginBackgroundTaskWithExpirationHandler:(void(^)(void))handler;
- (void)endBackgroundTask:(UIBackgroundTaskIdentifier)identifier;

- (void)setStatusBarHidden:(BOOL)hidden withAnimation:(UIStatusBarAnimation)animation;

- (void)registerForRemoteNotificationTypes:(UIRemoteNotificationType)types;

- (UIRemoteNotificationType)enabledRemoteNotificationTypes;

- (void)beginReceivingRemoteControlEvents;

- (void)setStatusBarOrientation:(UIInterfaceOrientation)interfaceOrientation animated:(BOOL)animated;

// Internal

-(UIWindow*) _popupWindow;
// ---------

@property (nonatomic, readonly) UIWindow *keyWindow;
@property (nonatomic, readonly) NSArray *windows;
@property (nonatomic, getter=isStatusBarHidden) BOOL statusBarHidden;
@property (nonatomic, readonly) CGRect statusBarFrame;
@property (nonatomic, getter=isNetworkActivityIndicatorVisible) BOOL networkActivityIndicatorVisible;   // does nothing, always returns NO
@property (nonatomic) UIInterfaceOrientation statusBarOrientation;
@property (nonatomic, readonly) NSTimeInterval statusBarOrientationAnimationDuration;
@property (nonatomic, assign) id<UIApplicationDelegate> delegate;
@property (nonatomic, getter=isIdleTimerDisabled) BOOL idleTimerDisabled;   // has no actual affect
@property (nonatomic) BOOL applicationSupportsShakeToEdit;                  // no effect
@property (nonatomic) UIStatusBarStyle statusBarStyle;                      // always returns UIStatusBarStyleDefault
@property (nonatomic, readonly) UIApplicationState applicationState;        // see notes near UIApplicationState struct for details!
@property (nonatomic, readonly) NSTimeInterval backgroundTimeRemaining;     // always 0
@property (nonatomic) NSInteger applicationIconBadgeNumber;                 // no effect, but does set/get the number correctly
@property (nonatomic, copy) NSArray *scheduledLocalNotifications;           // no effect, returns nil
@property (nonatomic, readonly) UIUserInterfaceLayoutDirection userInterfaceLayoutDirection;

@end

@interface UIApplication(UIApplicationDeprecated)
- (void)setStatusBarHidden:(BOOL)hidden animated:(BOOL)animated __attribute__((deprecated)); // use -setStatusBarHidden:withAnimation:
@end

@interface UIApplication(UIApplicationStarboardAdditions)
+ (void) setStarboardInternalLoggingLevel: (int) level;
- (void) registerForRemoteNotificationTypes: (UIRemoteNotificationType) types withId: (NSString *) id;
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
    WOCDisplayPresetNative16x9Aspect
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
    WOCDeviceDesktop
};
typedef uint32_t WOCDeviceType;

@interface WOCDisplayMode : NSObject

@property (nonatomic) float magnification;
@property (nonatomic) float fixedWidth;
@property (nonatomic) float fixedHeight;
@property (nonatomic) double fixedAspectRatio;
@property (nonatomic) BOOL  autoMagnification;
@property (nonatomic) BOOL  sizeUIWindowToFit;
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

- (void)setDisplayPreset: (WOCDisplayPreset)mode;
- (void)updateDisplaySettings;
@end

@interface UIApplication(UIApplicationDisplayMode)
+ (WOCDisplayMode *)displayMode;
@end

// Implement this category attached to UIApplication to override startup defaults
@interface UIApplication(UIApplicationInitialStartupMode)
+ (void)setStartupDisplayMode: (WOCDisplayMode *)mode;
@end

#endif /* _UIAPPLICATION_H_ */
