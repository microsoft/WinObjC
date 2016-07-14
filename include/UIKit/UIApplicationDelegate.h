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

#import <UIKit/UIKitExport.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIApplication.h>
/* TODO 7328699::
 * Projection headers cannot currenly be included in modules, so we must forward declare classes for now
 * App developers should import the following files to use methods requiring projected classes
 * #import <UWP/WindowsFoundation.h>
 * #import <UWP/WindowsMediaSpeechRecognition.h>
*/

@class NSString, UIApplication, NSDictionary, NSCoder, UIViewController, NSArray, UIUserNotificationSettings, UILocalNotification, NSData,
    NSError, NSUserActivity, UIApplicationShortcutItem, NSURL, UIWindow, WFCValueSet, WMSSpeechRecognitionResult, WFUri;

UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsURLKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsSourceApplicationKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsRemoteNotificationKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsLocalNotificationKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsToastActionKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsVoiceCommandKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsProtocolKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsAnnotationKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsLocationKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsNewsstandDownloadsKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsBluetoothCentralsKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsBluetoothPeripheralsKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsShortcutItemKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsUserActivityDictionaryKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsUserActivityTypeKey;
UIKIT_EXPORT NSString* const UIApplicationOpenURLOptionsSourceApplicationKey;
UIKIT_EXPORT NSString* const UIApplicationOpenURLOptionsAnnotationKey;
UIKIT_EXPORT NSString* const UIApplicationOpenURLOptionsOpenInPlaceKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsToastActionArgumentKey;
UIKIT_EXPORT NSString* const UIApplicationLaunchOptionsToastActionUserInputKey;

@protocol UIApplicationDelegate <NSObject>
@optional

/**
 @Status Interoperable
*/
- (BOOL)application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions;

/**
 @Status Interoperable
*/
- (void)applicationDidFinishLaunching:(UIApplication*)application;

/**
 @Status Interoperable
*/
- (void)applicationDidBecomeActive:(UIApplication*)application;

/**
 @Status Interoperable
*/
- (void)applicationWillResignActive:(UIApplication*)application;

- (BOOL)application:(UIApplication*)application willFinishLaunchingWithOptions:(NSDictionary*)launchOptions;
- (BOOL)application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions;
- (void)applicationDidFinishLaunching:(UIApplication*)application;
- (void)applicationDidBecomeActive:(UIApplication*)application;
- (void)applicationWillResignActive:(UIApplication*)application;
- (void)applicationDidEnterBackground:(UIApplication*)application;
- (void)applicationWillEnterForeground:(UIApplication*)application;
- (void)applicationWillTerminate:(UIApplication*)application;
- (void)applicationProtectedDataWillBecomeUnavailable:(UIApplication*)application;
- (void)applicationProtectedDataDidBecomeAvailable:(UIApplication*)application;
- (void)applicationDidReceiveMemoryWarning:(UIApplication*)application;
- (void)applicationSignificantTimeChange:(UIApplication*)application;
- (BOOL)application:(UIApplication*)application shouldSaveApplicationState:(NSCoder*)coder;
- (BOOL)application:(UIApplication*)application shouldRestoreApplicationState:(NSCoder*)coder;
- (UIViewController*)application:(UIApplication*)application
    viewControllerWithRestorationIdentifierPath:(NSArray*)identifierComponents
                                          coder:(NSCoder*)coder;
- (void)application:(UIApplication*)application willEncodeRestorableStateWithCoder:(NSCoder*)coder;
- (void)application:(UIApplication*)application didDecodeRestorableStateWithCoder:(NSCoder*)coder;
- (void)application:(UIApplication*)application
    performFetchWithCompletionHandler:(void (^)(UIBackgroundFetchResult result))completionHandler;
- (void)application:(UIApplication*)application
    handleEventsForBackgroundURLSession:(NSString*)identifier
                      completionHandler:(void (^)(void))completionHandler;
- (void)application:(UIApplication*)application didRegisterUserNotificationSettings:(UIUserNotificationSettings*)notificationSettings;
- (void)application:(UIApplication*)application didReceiveLocalNotification:(UILocalNotification*)notification;
- (void)application:(UIApplication*)application
    handleActionWithIdentifier:(NSString*)identifier
          forLocalNotification:(UILocalNotification*)notification
             completionHandler:(void (^)(void))completionHandler;
- (void)application:(UIApplication*)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData*)deviceToken;
- (void)application:(UIApplication*)application didFailToRegisterForRemoteNotificationsWithError:(NSError*)error;
- (void)application:(UIApplication*)application
    didReceiveRemoteNotification:(NSDictionary*)userInfo
          fetchCompletionHandler:(void (^)(UIBackgroundFetchResult result))handler;
- (void)application:(UIApplication*)application
    handleActionWithIdentifier:(NSString*)identifier
         forRemoteNotification:(NSDictionary*)userInfo
             completionHandler:(void (^)(void))completionHandler;
- (void)application:(UIApplication*)application didReceiveRemoteNotification:(NSDictionary*)userInfo;
- (void)application:(UIApplication*)application didReceiveToastAction:(NSDictionary*)action;
- (void)application:(UIApplication*)application didReceiveVoiceCommand:(WMSSpeechRecognitionResult*)result;
- (void)application:(UIApplication*)application didReceiveProtocol:(WFUri*)uri;
- (void)application:(UIApplication*)application
    handleActionWithIdentifier:(NSString*)identifier
          forLocalNotification:(UILocalNotification*)notification
              withResponseInfo:(NSDictionary*)responseInfo
             completionHandler:(void (^)(void))completionHandler;
- (void)application:(UIApplication*)application
    handleActionWithIdentifier:(NSString*)identifier
         forRemoteNotification:(NSDictionary*)userInfo
              withResponseInfo:(NSDictionary*)responseInfo
             completionHandler:(void (^)(void))completionHandler;
- (BOOL)application:(UIApplication*)application willContinueUserActivityWithType:(NSString*)userActivityType;
- (BOOL)application:(UIApplication*)application
    continueUserActivity:(NSUserActivity*)userActivity
      restorationHandler:(void (^)(NSArray* restorableObjects))restorationHandler;
- (void)application:(UIApplication*)application didUpdateUserActivity:(NSUserActivity*)userActivity;
- (void)application:(UIApplication*)application didFailToContinueUserActivityWithType:(NSString*)userActivityType error:(NSError*)error;
- (void)application:(UIApplication*)application
    performActionForShortcutItem:(UIApplicationShortcutItem*)shortcutItem
               completionHandler:(void (^)(BOOL succeeded))completionHandler;
- (void)application:(UIApplication*)application
    handleWatchKitExtensionRequest:(NSDictionary*)userInfo
                             reply:(void (^)(NSDictionary* replyInfo))reply;
- (void)applicationShouldRequestHealthAuthorization:(UIApplication*)application;
- (BOOL)application:(UIApplication*)app openURL:(NSURL*)url options:(NSDictionary*)options;
- (BOOL)application:(UIApplication*)application shouldAllowExtensionPointIdentifier:(NSString*)extensionPointIdentifier;
- (UIInterfaceOrientationMask)application:(UIApplication*)application supportedInterfaceOrientationsForWindow:(UIWindow*)window;
- (void)application:(UIApplication*)application
    willChangeStatusBarOrientation:(UIInterfaceOrientation)newStatusBarOrientation
                          duration:(NSTimeInterval)duration;
- (void)application:(UIApplication*)application didChangeStatusBarOrientation:(UIInterfaceOrientation)oldStatusBarOrientation;
- (void)application:(UIApplication*)application willChangeStatusBarFrame:(CGRect)newStatusBarFrame;
- (void)application:(UIApplication*)application didChangeStatusBarFrame:(CGRect)oldStatusBarFrame;
- (BOOL)application:(UIApplication*)application handleOpenURL:(NSURL*)url;
- (BOOL)application:(UIApplication*)application
            openURL:(NSURL*)url
  sourceApplication:(NSString*)sourceApplication
         annotation:(id)annotation;

@property (nonatomic, strong) UIWindow* window;

@end
