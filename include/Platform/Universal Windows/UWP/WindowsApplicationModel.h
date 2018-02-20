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

// WindowsApplicationModel.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
#define OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsConsolidatedNamespace.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WAFullTrustProcessLauncher, WAStartupTask, WAAppDisplayInfo, WAAppInfo, WAPackageStatus, WAPackageId, WAPackage, WAPackageContentGroup, WAPackageStagingEventArgs, WAPackageInstallingEventArgs, WAPackageUpdatingEventArgs, WAPackageUninstallingEventArgs, WAPackageStatusChangedEventArgs, WAPackageContentGroupStagingEventArgs, WAPackageCatalog, WAPackageCatalogAddOptionalPackageResult, WAPackageCatalogRemoveOptionalPackagesResult, WADesignMode, WASuspendingEventArgs, WALeavingBackgroundEventArgs, WAEnteredBackgroundEventArgs, WASuspendingDeferral, WASuspendingOperation;
@class WAPackageVersion;
@protocol WAIFullTrustProcessLauncherStatics, WAIStartupTask, WAIStartupTaskStatics, WAIAppDisplayInfo, WAIAppInfo, WAIPackageIdWithMetadata, WAIPackageWithMetadata, WAIPackageStatus, WAIPackageStatus2, WAIPackageId, WAIPackage, WAIPackage2, WAIPackage3, WAIPackage4, WAIPackage5, WAIPackageStatics, WAIPackageStagingEventArgs, WAIPackageInstallingEventArgs, WAIPackageUpdatingEventArgs, WAIPackageUninstallingEventArgs, WAIPackageStatusChangedEventArgs, WAIPackageContentGroupStagingEventArgs, WAIPackageCatalog, WAIPackageCatalogAddOptionalPackageResult, WAIPackageCatalog2, WAIPackageCatalogRemoveOptionalPackagesResult, WAIPackageCatalog3, WAIPackageCatalogStatics, WAIPackageContentGroup, WAIPackageContentGroupStatics, WAIDesignModeStatics, WAIDesignModeStatics2, WAISuspendingDeferral, WAISuspendingOperation, WAISuspendingEventArgs, WAILeavingBackgroundEventArgs, WAIEnteredBackgroundEventArgs;

// Windows.ApplicationModel.StartupTaskState
enum _WAStartupTaskState {
    WAStartupTaskStateDisabled = 0,
    WAStartupTaskStateDisabledByUser = 1,
    WAStartupTaskStateEnabled = 2,
    WAStartupTaskStateDisabledByPolicy = 3,
};
typedef unsigned WAStartupTaskState;

// Windows.ApplicationModel.PackageSignatureKind
enum _WAPackageSignatureKind {
    WAPackageSignatureKindNone = 0,
    WAPackageSignatureKindDeveloper = 1,
    WAPackageSignatureKindEnterprise = 2,
    WAPackageSignatureKindStore = 3,
    WAPackageSignatureKindSystem = 4,
};
typedef unsigned WAPackageSignatureKind;

// Windows.ApplicationModel.PackageContentGroupState
enum _WAPackageContentGroupState {
    WAPackageContentGroupStateNotStaged = 0,
    WAPackageContentGroupStateQueued = 1,
    WAPackageContentGroupStateStaging = 2,
    WAPackageContentGroupStateStaged = 3,
};
typedef unsigned WAPackageContentGroupState;

#include "WindowsSystem.h"
#include "WindowsFoundation.h"
#include "WindowsApplicationModelCore.h"
#include "WindowsStorageStreams.h"
#include "WindowsStorage.h"

#import <Foundation/Foundation.h>

// [struct] Windows.ApplicationModel.PackageVersion
OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAPackageVersion : NSObject
+ (instancetype)new;
@property unsigned short major;
@property unsigned short minor;
@property unsigned short build;
@property unsigned short revision;
@end

// Windows.ApplicationModel.ISuspendingDeferral
#ifndef __WAISuspendingDeferral_DEFINED__
#define __WAISuspendingDeferral_DEFINED__

@protocol WAISuspendingDeferral
- (void)complete;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAISuspendingDeferral : RTObject <WAISuspendingDeferral>
@end

#endif // __WAISuspendingDeferral_DEFINED__

// Windows.ApplicationModel.ISuspendingOperation
#ifndef __WAISuspendingOperation_DEFINED__
#define __WAISuspendingOperation_DEFINED__

@protocol WAISuspendingOperation
@property (readonly) WFDateTime* deadline;
- (WASuspendingDeferral*)getDeferral;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAISuspendingOperation : RTObject <WAISuspendingOperation>
@end

#endif // __WAISuspendingOperation_DEFINED__

// Windows.ApplicationModel.ISuspendingEventArgs
#ifndef __WAISuspendingEventArgs_DEFINED__
#define __WAISuspendingEventArgs_DEFINED__

@protocol WAISuspendingEventArgs
@property (readonly) WASuspendingOperation* suspendingOperation;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAISuspendingEventArgs : RTObject <WAISuspendingEventArgs>
@end

#endif // __WAISuspendingEventArgs_DEFINED__

// Windows.ApplicationModel.ILeavingBackgroundEventArgs
#ifndef __WAILeavingBackgroundEventArgs_DEFINED__
#define __WAILeavingBackgroundEventArgs_DEFINED__

@protocol WAILeavingBackgroundEventArgs
- (WFDeferral*)getDeferral;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAILeavingBackgroundEventArgs : RTObject <WAILeavingBackgroundEventArgs>
@end

#endif // __WAILeavingBackgroundEventArgs_DEFINED__

// Windows.ApplicationModel.IEnteredBackgroundEventArgs
#ifndef __WAIEnteredBackgroundEventArgs_DEFINED__
#define __WAIEnteredBackgroundEventArgs_DEFINED__

@protocol WAIEnteredBackgroundEventArgs
- (WFDeferral*)getDeferral;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAIEnteredBackgroundEventArgs : RTObject <WAIEnteredBackgroundEventArgs>
@end

#endif // __WAIEnteredBackgroundEventArgs_DEFINED__

// Windows.ApplicationModel.FullTrustProcessLauncher
#ifndef __WAFullTrustProcessLauncher_DEFINED__
#define __WAFullTrustProcessLauncher_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAFullTrustProcessLauncher : RTObject
+ (RTObject<WFIAsyncAction>*)launchFullTrustProcessForCurrentAppAsync;
+ (RTObject<WFIAsyncAction>*)launchFullTrustProcessForCurrentAppWithParametersAsync:(NSString *)parameterGroupId;
+ (RTObject<WFIAsyncAction>*)launchFullTrustProcessForAppAsync:(NSString *)fullTrustPackageRelativeAppId;
+ (RTObject<WFIAsyncAction>*)launchFullTrustProcessForAppWithParametersAsync:(NSString *)fullTrustPackageRelativeAppId parameterGroupId:(NSString *)parameterGroupId;
@end

#endif // __WAFullTrustProcessLauncher_DEFINED__

// Windows.ApplicationModel.StartupTask
#ifndef __WAStartupTask_DEFINED__
#define __WAStartupTask_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAStartupTask : RTObject
+ (void)getForCurrentPackageAsyncWithSuccess:(void (^)(NSArray* /* WAStartupTask* */))success failure:(void (^)(NSError*))failure;
+ (void)getAsync:(NSString *)taskId success:(void (^)(WAStartupTask*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAStartupTaskState state;
@property (readonly) NSString * taskId;
- (void)requestEnableAsyncWithSuccess:(void (^)(WAStartupTaskState))success failure:(void (^)(NSError*))failure;
- (void)disable;
@end

#endif // __WAStartupTask_DEFINED__

// Windows.ApplicationModel.AppDisplayInfo
#ifndef __WAAppDisplayInfo_DEFINED__
#define __WAAppDisplayInfo_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAppDisplayInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * Description;
@property (readonly) NSString * displayName;
- (WSSRandomAccessStreamReference*)getLogo:(WFSize*)size;
@end

#endif // __WAAppDisplayInfo_DEFINED__

// Windows.ApplicationModel.AppInfo
#ifndef __WAAppInfo_DEFINED__
#define __WAAppInfo_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAAppInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * appUserModelId;
@property (readonly) WAAppDisplayInfo* displayInfo;
@property (readonly) NSString * id;
@property (readonly) NSString * packageFamilyName;
@end

#endif // __WAAppInfo_DEFINED__

// Windows.ApplicationModel.PackageStatus
#ifndef __WAPackageStatus_DEFINED__
#define __WAPackageStatus_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAPackageStatus : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL dataOffline;
@property (readonly) BOOL dependencyIssue;
@property (readonly) BOOL deploymentInProgress;
@property (readonly) BOOL disabled;
@property (readonly) BOOL licenseIssue;
@property (readonly) BOOL modified;
@property (readonly) BOOL needsRemediation;
@property (readonly) BOOL notAvailable;
@property (readonly) BOOL packageOffline;
@property (readonly) BOOL servicing;
@property (readonly) BOOL tampered;
@property (readonly) BOOL isPartiallyStaged;
- (BOOL)verifyIsOK;
@end

#endif // __WAPackageStatus_DEFINED__

// Windows.ApplicationModel.PackageId
#ifndef __WAPackageId_DEFINED__
#define __WAPackageId_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAPackageId : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSProcessorArchitecture architecture;
@property (readonly) NSString * familyName;
@property (readonly) NSString * fullName;
@property (readonly) NSString * name;
@property (readonly) NSString * publisher;
@property (readonly) NSString * publisherId;
@property (readonly) NSString * resourceId;
@property (readonly) WAPackageVersion* Version;
@property (readonly) NSString * author;
@property (readonly) NSString * productId;
@end

#endif // __WAPackageId_DEFINED__

// Windows.ApplicationModel.Package
#ifndef __WAPackage_DEFINED__
#define __WAPackage_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAPackage : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WAPackage* */ dependencies;
@property (readonly) WAPackageId* id;
@property (readonly) WSStorageFolder* installedLocation;
@property (readonly) BOOL isFramework;
@property (readonly) NSString * Description;
@property (readonly) NSString * displayName;
@property (readonly) BOOL isBundle;
@property (readonly) BOOL isDevelopmentMode;
@property (readonly) BOOL isResourcePackage;
@property (readonly) WFUri* logo;
@property (readonly) NSString * publisherDisplayName;
@property (readonly) WFDateTime* installedDate;
@property (readonly) WAPackageStatus* status;
@property (readonly) BOOL isOptional;
@property (readonly) WAPackageSignatureKind signatureKind;
@property (readonly) WFDateTime* installDate;
+ (WAPackage*)current;
- (void)getAppListEntriesAsyncWithSuccess:(void (^)(NSArray* /* WACAppListEntry* */))success failure:(void (^)(NSError*))failure;
- (NSString *)getThumbnailToken;
- (void)launch:(NSString *)parameters;
- (void)verifyContentIntegrityAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)getContentGroupsAsyncWithSuccess:(void (^)(NSMutableArray* /* WAPackageContentGroup* */))success failure:(void (^)(NSError*))failure;
- (void)getContentGroupAsync:(NSString *)name success:(void (^)(WAPackageContentGroup*))success failure:(void (^)(NSError*))failure;
- (void)stageContentGroupsAsync:(id<NSFastEnumeration> /* NSString * */)names success:(void (^)(NSMutableArray* /* WAPackageContentGroup* */))success failure:(void (^)(NSError*))failure;
- (void)stageContentGroupsWithPriorityAsync:(id<NSFastEnumeration> /* NSString * */)names moveToHeadOfQueue:(BOOL)moveToHeadOfQueue success:(void (^)(NSMutableArray* /* WAPackageContentGroup* */))success failure:(void (^)(NSError*))failure;
- (void)setInUseAsync:(BOOL)inUse success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WAPackage_DEFINED__

// Windows.ApplicationModel.PackageContentGroup
#ifndef __WAPackageContentGroup_DEFINED__
#define __WAPackageContentGroup_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAPackageContentGroup : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isRequired;
@property (readonly) NSString * name;
@property (readonly) WAPackage* package;
@property (readonly) WAPackageContentGroupState state;
+ (NSString *)requiredGroupName;
@end

#endif // __WAPackageContentGroup_DEFINED__

// Windows.ApplicationModel.PackageStagingEventArgs
#ifndef __WAPackageStagingEventArgs_DEFINED__
#define __WAPackageStagingEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAPackageStagingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFGUID* activityId;
@property (readonly) HRESULT errorCode;
@property (readonly) BOOL isComplete;
@property (readonly) WAPackage* package;
@property (readonly) double progress;
@end

#endif // __WAPackageStagingEventArgs_DEFINED__

// Windows.ApplicationModel.PackageInstallingEventArgs
#ifndef __WAPackageInstallingEventArgs_DEFINED__
#define __WAPackageInstallingEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAPackageInstallingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFGUID* activityId;
@property (readonly) HRESULT errorCode;
@property (readonly) BOOL isComplete;
@property (readonly) WAPackage* package;
@property (readonly) double progress;
@end

#endif // __WAPackageInstallingEventArgs_DEFINED__

// Windows.ApplicationModel.PackageUpdatingEventArgs
#ifndef __WAPackageUpdatingEventArgs_DEFINED__
#define __WAPackageUpdatingEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAPackageUpdatingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFGUID* activityId;
@property (readonly) HRESULT errorCode;
@property (readonly) BOOL isComplete;
@property (readonly) double progress;
@property (readonly) WAPackage* sourcePackage;
@property (readonly) WAPackage* targetPackage;
@end

#endif // __WAPackageUpdatingEventArgs_DEFINED__

// Windows.ApplicationModel.PackageUninstallingEventArgs
#ifndef __WAPackageUninstallingEventArgs_DEFINED__
#define __WAPackageUninstallingEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAPackageUninstallingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFGUID* activityId;
@property (readonly) HRESULT errorCode;
@property (readonly) BOOL isComplete;
@property (readonly) WAPackage* package;
@property (readonly) double progress;
@end

#endif // __WAPackageUninstallingEventArgs_DEFINED__

// Windows.ApplicationModel.PackageStatusChangedEventArgs
#ifndef __WAPackageStatusChangedEventArgs_DEFINED__
#define __WAPackageStatusChangedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAPackageStatusChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAPackage* package;
@end

#endif // __WAPackageStatusChangedEventArgs_DEFINED__

// Windows.ApplicationModel.PackageContentGroupStagingEventArgs
#ifndef __WAPackageContentGroupStagingEventArgs_DEFINED__
#define __WAPackageContentGroupStagingEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAPackageContentGroupStagingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFGUID* activityId;
@property (readonly) NSString * contentGroupName;
@property (readonly) HRESULT errorCode;
@property (readonly) BOOL isComplete;
@property (readonly) BOOL isContentGroupRequired;
@property (readonly) WAPackage* package;
@property (readonly) double progress;
@end

#endif // __WAPackageContentGroupStagingEventArgs_DEFINED__

// Windows.ApplicationModel.PackageCatalog
#ifndef __WAPackageCatalog_DEFINED__
#define __WAPackageCatalog_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAPackageCatalog : RTObject
+ (WAPackageCatalog*)openForCurrentPackage;
+ (WAPackageCatalog*)openForCurrentUser;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addPackageInstallingEvent:(void(^)(WAPackageCatalog*, WAPackageInstallingEventArgs*))del;
- (void)removePackageInstallingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPackageStagingEvent:(void(^)(WAPackageCatalog*, WAPackageStagingEventArgs*))del;
- (void)removePackageStagingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPackageStatusChangedEvent:(void(^)(WAPackageCatalog*, WAPackageStatusChangedEventArgs*))del;
- (void)removePackageStatusChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPackageUninstallingEvent:(void(^)(WAPackageCatalog*, WAPackageUninstallingEventArgs*))del;
- (void)removePackageUninstallingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPackageUpdatingEvent:(void(^)(WAPackageCatalog*, WAPackageUpdatingEventArgs*))del;
- (void)removePackageUpdatingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPackageContentGroupStagingEvent:(void(^)(WAPackageCatalog*, WAPackageContentGroupStagingEventArgs*))del;
- (void)removePackageContentGroupStagingEvent:(EventRegistrationToken)tok;
- (void)addOptionalPackageAsync:(NSString *)optionalPackageFamilyName success:(void (^)(WAPackageCatalogAddOptionalPackageResult*))success failure:(void (^)(NSError*))failure;
- (void)removeOptionalPackagesAsync:(id<NSFastEnumeration> /* NSString * */)optionalPackageFamilyNames success:(void (^)(WAPackageCatalogRemoveOptionalPackagesResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WAPackageCatalog_DEFINED__

// Windows.ApplicationModel.PackageCatalogAddOptionalPackageResult
#ifndef __WAPackageCatalogAddOptionalPackageResult_DEFINED__
#define __WAPackageCatalogAddOptionalPackageResult_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAPackageCatalogAddOptionalPackageResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) HRESULT extendedError;
@property (readonly) WAPackage* package;
@end

#endif // __WAPackageCatalogAddOptionalPackageResult_DEFINED__

// Windows.ApplicationModel.PackageCatalogRemoveOptionalPackagesResult
#ifndef __WAPackageCatalogRemoveOptionalPackagesResult_DEFINED__
#define __WAPackageCatalogRemoveOptionalPackagesResult_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAPackageCatalogRemoveOptionalPackagesResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) HRESULT extendedError;
@property (readonly) NSArray* /* WAPackage* */ packagesRemoved;
@end

#endif // __WAPackageCatalogRemoveOptionalPackagesResult_DEFINED__

// Windows.ApplicationModel.DesignMode
#ifndef __WADesignMode_DEFINED__
#define __WADesignMode_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WADesignMode : RTObject
+ (BOOL)designModeEnabled;
+ (BOOL)designMode2Enabled;
@end

#endif // __WADesignMode_DEFINED__

// Windows.ApplicationModel.SuspendingEventArgs
#ifndef __WASuspendingEventArgs_DEFINED__
#define __WASuspendingEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WASuspendingEventArgs : RTObject <WAISuspendingEventArgs>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WASuspendingOperation* suspendingOperation;
@end

#endif // __WASuspendingEventArgs_DEFINED__

// Windows.ApplicationModel.LeavingBackgroundEventArgs
#ifndef __WALeavingBackgroundEventArgs_DEFINED__
#define __WALeavingBackgroundEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WALeavingBackgroundEventArgs : RTObject <WAILeavingBackgroundEventArgs>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WFDeferral*)getDeferral;
@end

#endif // __WALeavingBackgroundEventArgs_DEFINED__

// Windows.ApplicationModel.EnteredBackgroundEventArgs
#ifndef __WAEnteredBackgroundEventArgs_DEFINED__
#define __WAEnteredBackgroundEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEnteredBackgroundEventArgs : RTObject <WAIEnteredBackgroundEventArgs>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WFDeferral*)getDeferral;
@end

#endif // __WAEnteredBackgroundEventArgs_DEFINED__

// Windows.ApplicationModel.SuspendingDeferral
#ifndef __WASuspendingDeferral_DEFINED__
#define __WASuspendingDeferral_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WASuspendingDeferral : RTObject <WAISuspendingDeferral>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)complete;
@end

#endif // __WASuspendingDeferral_DEFINED__

// Windows.ApplicationModel.SuspendingOperation
#ifndef __WASuspendingOperation_DEFINED__
#define __WASuspendingOperation_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WASuspendingOperation : RTObject <WAISuspendingOperation>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFDateTime* deadline;
- (WASuspendingDeferral*)getDeferral;
@end

#endif // __WASuspendingOperation_DEFINED__

