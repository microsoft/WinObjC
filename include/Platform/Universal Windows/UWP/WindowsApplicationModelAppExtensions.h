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

// WindowsApplicationModelAppExtensions.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSAPPLICATIONMODELAPPEXTENSIONSEXPORT
#define OBJCUWPWINDOWSAPPLICATIONMODELAPPEXTENSIONSEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsApplicationModelAppExtensions.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WAAAppExtensionCatalog, WAAAppExtension, WAAAppExtensionPackageInstalledEventArgs, WAAAppExtensionPackageUpdatingEventArgs, WAAAppExtensionPackageUpdatedEventArgs, WAAAppExtensionPackageUninstallingEventArgs, WAAAppExtensionPackageStatusChangedEventArgs;
@protocol WAAIAppExtensionCatalogStatics, WAAIAppExtensionCatalog, WAAIAppExtension, WAAIAppExtensionPackageInstalledEventArgs, WAAIAppExtensionPackageUpdatingEventArgs, WAAIAppExtensionPackageUpdatedEventArgs, WAAIAppExtensionPackageUninstallingEventArgs, WAAIAppExtensionPackageStatusChangedEventArgs;

#include "WindowsFoundationCollections.h"
#include "WindowsFoundation.h"
#include "WindowsApplicationModel.h"
#include "WindowsStorage.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.AppExtensions.AppExtensionCatalog
#ifndef __WAAAppExtensionCatalog_DEFINED__
#define __WAAAppExtensionCatalog_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELAPPEXTENSIONSEXPORT
@interface WAAAppExtensionCatalog : RTObject
+ (WAAAppExtensionCatalog*)open:(NSString *)appExtensionName;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addPackageInstalledEvent:(void(^)(WAAAppExtensionCatalog*, WAAAppExtensionPackageInstalledEventArgs*))del;
- (void)removePackageInstalledEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPackageStatusChangedEvent:(void(^)(WAAAppExtensionCatalog*, WAAAppExtensionPackageStatusChangedEventArgs*))del;
- (void)removePackageStatusChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPackageUninstallingEvent:(void(^)(WAAAppExtensionCatalog*, WAAAppExtensionPackageUninstallingEventArgs*))del;
- (void)removePackageUninstallingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPackageUpdatedEvent:(void(^)(WAAAppExtensionCatalog*, WAAAppExtensionPackageUpdatedEventArgs*))del;
- (void)removePackageUpdatedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPackageUpdatingEvent:(void(^)(WAAAppExtensionCatalog*, WAAAppExtensionPackageUpdatingEventArgs*))del;
- (void)removePackageUpdatingEvent:(EventRegistrationToken)tok;
- (void)findAllAsyncWithSuccess:(void (^)(NSArray* /* WAAAppExtension* */))success failure:(void (^)(NSError*))failure;
- (void)requestRemovePackageAsync:(NSString *)packageFullName success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WAAAppExtensionCatalog_DEFINED__

// Windows.ApplicationModel.AppExtensions.AppExtension
#ifndef __WAAAppExtension_DEFINED__
#define __WAAAppExtension_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELAPPEXTENSIONSEXPORT
@interface WAAAppExtension : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAppInfo* appInfo;
@property (readonly) NSString * Description;
@property (readonly) NSString * displayName;
@property (readonly) NSString * id;
@property (readonly) WAPackage* package;
- (void)getExtensionPropertiesAsyncWithSuccess:(void (^)(RTObject<WFCIPropertySet>*))success failure:(void (^)(NSError*))failure;
- (void)getPublicFolderAsyncWithSuccess:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WAAAppExtension_DEFINED__

// Windows.ApplicationModel.AppExtensions.AppExtensionPackageInstalledEventArgs
#ifndef __WAAAppExtensionPackageInstalledEventArgs_DEFINED__
#define __WAAAppExtensionPackageInstalledEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELAPPEXTENSIONSEXPORT
@interface WAAAppExtensionPackageInstalledEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * appExtensionName;
@property (readonly) NSArray* /* WAAAppExtension* */ extensions;
@property (readonly) WAPackage* package;
@end

#endif // __WAAAppExtensionPackageInstalledEventArgs_DEFINED__

// Windows.ApplicationModel.AppExtensions.AppExtensionPackageUpdatingEventArgs
#ifndef __WAAAppExtensionPackageUpdatingEventArgs_DEFINED__
#define __WAAAppExtensionPackageUpdatingEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELAPPEXTENSIONSEXPORT
@interface WAAAppExtensionPackageUpdatingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * appExtensionName;
@property (readonly) WAPackage* package;
@end

#endif // __WAAAppExtensionPackageUpdatingEventArgs_DEFINED__

// Windows.ApplicationModel.AppExtensions.AppExtensionPackageUpdatedEventArgs
#ifndef __WAAAppExtensionPackageUpdatedEventArgs_DEFINED__
#define __WAAAppExtensionPackageUpdatedEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELAPPEXTENSIONSEXPORT
@interface WAAAppExtensionPackageUpdatedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * appExtensionName;
@property (readonly) NSArray* /* WAAAppExtension* */ extensions;
@property (readonly) WAPackage* package;
@end

#endif // __WAAAppExtensionPackageUpdatedEventArgs_DEFINED__

// Windows.ApplicationModel.AppExtensions.AppExtensionPackageUninstallingEventArgs
#ifndef __WAAAppExtensionPackageUninstallingEventArgs_DEFINED__
#define __WAAAppExtensionPackageUninstallingEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELAPPEXTENSIONSEXPORT
@interface WAAAppExtensionPackageUninstallingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * appExtensionName;
@property (readonly) WAPackage* package;
@end

#endif // __WAAAppExtensionPackageUninstallingEventArgs_DEFINED__

// Windows.ApplicationModel.AppExtensions.AppExtensionPackageStatusChangedEventArgs
#ifndef __WAAAppExtensionPackageStatusChangedEventArgs_DEFINED__
#define __WAAAppExtensionPackageStatusChangedEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELAPPEXTENSIONSEXPORT
@interface WAAAppExtensionPackageStatusChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * appExtensionName;
@property (readonly) WAPackage* package;
@end

#endif // __WAAAppExtensionPackageStatusChangedEventArgs_DEFINED__

