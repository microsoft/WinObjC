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

// WindowsManagementDeployment.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSMANAGEMENTDEPLOYMENTEXPORT
#define OBJCUWPWINDOWSMANAGEMENTDEPLOYMENTEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsManagementDeployment.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WMDDeploymentResult, WMDPackageUserInformation, WMDPackageVolume, WMDPackageManagerDebugSettings, WMDPackageManager;
@class WMDDeploymentProgress;
@protocol WMDIDeploymentResult, WMDIDeploymentResult2, WMDIPackageUserInformation, WMDIPackageManager, WMDIPackageManager2, WMDIPackageManager3, WMDIPackageManager4, WMDIPackageManager5, WMDIPackageManager6, WMDIPackageVolume, WMDIPackageVolume2, WMDIPackageManagerDebugSettings;

// Windows.Management.Deployment.DeploymentProgressState
enum _WMDDeploymentProgressState {
    WMDDeploymentProgressStateQueued = 0,
    WMDDeploymentProgressStateProcessing = 1,
};
typedef unsigned WMDDeploymentProgressState;

// Windows.Management.Deployment.DeploymentOptions
enum _WMDDeploymentOptions {
    WMDDeploymentOptionsNone = 0,
    WMDDeploymentOptionsForceApplicationShutdown = 1,
    WMDDeploymentOptionsDevelopmentMode = 2,
    WMDDeploymentOptionsInstallAllResources = 32,
    WMDDeploymentOptionsForceTargetApplicationShutdown = 64,
    WMDDeploymentOptionsRequiredContentGroupOnly = 256,
};
typedef unsigned WMDDeploymentOptions;

// Windows.Management.Deployment.RemovalOptions
enum _WMDRemovalOptions {
    WMDRemovalOptionsNone = 0,
    WMDRemovalOptionsPreserveApplicationData = 4096,
};
typedef unsigned WMDRemovalOptions;

// Windows.Management.Deployment.AddPackageByAppInstallerOptions
enum _WMDAddPackageByAppInstallerOptions {
    WMDAddPackageByAppInstallerOptionsNone = 0,
    WMDAddPackageByAppInstallerOptionsInstallAllResources = 32,
    WMDAddPackageByAppInstallerOptionsForceTargetAppShutdown = 64,
    WMDAddPackageByAppInstallerOptionsRequiredContentGroupOnly = 256,
};
typedef unsigned WMDAddPackageByAppInstallerOptions;

// Windows.Management.Deployment.PackageTypes
enum _WMDPackageTypes {
    WMDPackageTypesNone = 0,
    WMDPackageTypesMain = 1,
    WMDPackageTypesFramework = 2,
    WMDPackageTypesResource = 4,
    WMDPackageTypesBundle = 8,
    WMDPackageTypesXap = 16,
    WMDPackageTypesOptional = 32,
};
typedef unsigned WMDPackageTypes;

// Windows.Management.Deployment.PackageInstallState
enum _WMDPackageInstallState {
    WMDPackageInstallStateNotInstalled = 0,
    WMDPackageInstallStateStaged = 1,
    WMDPackageInstallStateInstalled = 2,
    WMDPackageInstallStatePaused = 6,
};
typedef unsigned WMDPackageInstallState;

// Windows.Management.Deployment.PackageState
enum _WMDPackageState {
    WMDPackageStateNormal = 0,
    WMDPackageStateLicenseInvalid = 1,
    WMDPackageStateModified = 2,
    WMDPackageStateTampered = 3,
};
typedef unsigned WMDPackageState;

// Windows.Management.Deployment.PackageStatus
enum _WMDPackageStatus {
    WMDPackageStatusOK = 0,
    WMDPackageStatusLicenseIssue = 1,
    WMDPackageStatusModified = 2,
    WMDPackageStatusTampered = 4,
    WMDPackageStatusDisabled = 8,
};
typedef unsigned WMDPackageStatus;

#include "WindowsFoundation.h"
#include "WindowsApplicationModel.h"

#import <Foundation/Foundation.h>

// [struct] Windows.Management.Deployment.DeploymentProgress
OBJCUWPWINDOWSMANAGEMENTDEPLOYMENTEXPORT
@interface WMDDeploymentProgress : NSObject
+ (instancetype)new;
@property WMDDeploymentProgressState state;
@property unsigned int percentage;
@end

// Windows.Management.Deployment.DeploymentResult
#ifndef __WMDDeploymentResult_DEFINED__
#define __WMDDeploymentResult_DEFINED__

OBJCUWPWINDOWSMANAGEMENTDEPLOYMENTEXPORT
@interface WMDDeploymentResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFGUID* activityId;
@property (readonly) NSString * errorText;
@property (readonly) HRESULT extendedErrorCode;
@property (readonly) BOOL isRegistered;
@end

#endif // __WMDDeploymentResult_DEFINED__

// Windows.Management.Deployment.PackageUserInformation
#ifndef __WMDPackageUserInformation_DEFINED__
#define __WMDPackageUserInformation_DEFINED__

OBJCUWPWINDOWSMANAGEMENTDEPLOYMENTEXPORT
@interface WMDPackageUserInformation : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMDPackageInstallState installState;
@property (readonly) NSString * userSecurityId;
@end

#endif // __WMDPackageUserInformation_DEFINED__

// Windows.Management.Deployment.PackageVolume
#ifndef __WMDPackageVolume_DEFINED__
#define __WMDPackageVolume_DEFINED__

OBJCUWPWINDOWSMANAGEMENTDEPLOYMENTEXPORT
@interface WMDPackageVolume : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isOffline;
@property (readonly) BOOL isSystemVolume;
@property (readonly) NSString * mountPoint;
@property (readonly) NSString * name;
@property (readonly) NSString * packageStorePath;
@property (readonly) BOOL supportsHardLinks;
@property (readonly) BOOL isAppxInstallSupported;
@property (readonly) BOOL isFullTrustPackageSupported;
- (NSMutableArray* /* WAPackage* */)findPackages;
- (NSMutableArray* /* WAPackage* */)findPackagesByNamePublisher:(NSString *)packageName packagePublisher:(NSString *)packagePublisher;
- (NSMutableArray* /* WAPackage* */)findPackagesByPackageFamilyName:(NSString *)packageFamilyName;
- (NSMutableArray* /* WAPackage* */)findPackagesWithPackageTypes:(WMDPackageTypes)packageTypes;
- (NSMutableArray* /* WAPackage* */)findPackagesByNamePublisherWithPackagesTypes:(WMDPackageTypes)packageTypes packageName:(NSString *)packageName packagePublisher:(NSString *)packagePublisher;
- (NSMutableArray* /* WAPackage* */)findPackagesByPackageFamilyNameWithPackageTypes:(WMDPackageTypes)packageTypes packageFamilyName:(NSString *)packageFamilyName;
- (NSMutableArray* /* WAPackage* */)findPackageByPackageFullName:(NSString *)packageFullName;
- (NSMutableArray* /* WAPackage* */)findPackagesByUserSecurityId:(NSString *)userSecurityId;
- (NSMutableArray* /* WAPackage* */)findPackagesByUserSecurityIdNamePublisher:(NSString *)userSecurityId packageName:(NSString *)packageName packagePublisher:(NSString *)packagePublisher;
- (NSMutableArray* /* WAPackage* */)findPackagesByUserSecurityIdPackageFamilyName:(NSString *)userSecurityId packageFamilyName:(NSString *)packageFamilyName;
- (NSMutableArray* /* WAPackage* */)findPackagesByUserSecurityIdWithPackageTypes:(NSString *)userSecurityId packageTypes:(WMDPackageTypes)packageTypes;
- (NSMutableArray* /* WAPackage* */)findPackagesByUserSecurityIdNamePublisherWithPackageTypes:(NSString *)userSecurityId packageTypes:(WMDPackageTypes)packageTypes packageName:(NSString *)packageName packagePublisher:(NSString *)packagePublisher;
- (NSMutableArray* /* WAPackage* */)findPackagesByUserSecurityIdPackageFamilyNameWithPackagesTypes:(NSString *)userSecurityId packageTypes:(WMDPackageTypes)packageTypes packageFamilyName:(NSString *)packageFamilyName;
- (NSMutableArray* /* WAPackage* */)findPackageByUserSecurityIdPackageFullName:(NSString *)userSecurityId packageFullName:(NSString *)packageFullName;
- (void)getAvailableSpaceAsyncWithSuccess:(void (^)(uint64_t))success failure:(void (^)(NSError*))failure;
@end

#endif // __WMDPackageVolume_DEFINED__

// Windows.Management.Deployment.PackageManagerDebugSettings
#ifndef __WMDPackageManagerDebugSettings_DEFINED__
#define __WMDPackageManagerDebugSettings_DEFINED__

OBJCUWPWINDOWSMANAGEMENTDEPLOYMENTEXPORT
@interface WMDPackageManagerDebugSettings : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (RTObject<WFIAsyncAction>*)setContentGroupStateAsync:(WAPackage*)package contentGroupName:(NSString *)contentGroupName state:(WAPackageContentGroupState)state;
- (RTObject<WFIAsyncAction>*)setContentGroupStateWithPercentageAsync:(WAPackage*)package contentGroupName:(NSString *)contentGroupName state:(WAPackageContentGroupState)state completionPercentage:(double)completionPercentage;
@end

#endif // __WMDPackageManagerDebugSettings_DEFINED__

// Windows.Management.Deployment.PackageManager
#ifndef __WMDPackageManager_DEFINED__
#define __WMDPackageManager_DEFINED__

OBJCUWPWINDOWSMANAGEMENTDEPLOYMENTEXPORT
@interface WMDPackageManager : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMDPackageManagerDebugSettings* debugSettings;
- (void)addPackageAsync:(WFUri*)packageUri dependencyPackageUris:(id<NSFastEnumeration> /* WFUri* */)dependencyPackageUris deploymentOptions:(WMDDeploymentOptions)deploymentOptions success:(void (^)(WMDDeploymentResult*))success progress:(void (^)(WMDDeploymentProgress*))progress failure:(void (^)(NSError*))failure;
- (void)updatePackageAsync:(WFUri*)packageUri dependencyPackageUris:(id<NSFastEnumeration> /* WFUri* */)dependencyPackageUris deploymentOptions:(WMDDeploymentOptions)deploymentOptions success:(void (^)(WMDDeploymentResult*))success progress:(void (^)(WMDDeploymentProgress*))progress failure:(void (^)(NSError*))failure;
- (void)removePackageAsync:(NSString *)packageFullName success:(void (^)(WMDDeploymentResult*))success progress:(void (^)(WMDDeploymentProgress*))progress failure:(void (^)(NSError*))failure;
- (void)stagePackageAsync:(WFUri*)packageUri dependencyPackageUris:(id<NSFastEnumeration> /* WFUri* */)dependencyPackageUris success:(void (^)(WMDDeploymentResult*))success progress:(void (^)(WMDDeploymentProgress*))progress failure:(void (^)(NSError*))failure;
- (void)registerPackageAsync:(WFUri*)manifestUri dependencyPackageUris:(id<NSFastEnumeration> /* WFUri* */)dependencyPackageUris deploymentOptions:(WMDDeploymentOptions)deploymentOptions success:(void (^)(WMDDeploymentResult*))success progress:(void (^)(WMDDeploymentProgress*))progress failure:(void (^)(NSError*))failure;
- (id<NSFastEnumeration> /* WAPackage* */)findPackages;
- (id<NSFastEnumeration> /* WAPackage* */)findPackagesByUserSecurityId:(NSString *)userSecurityId;
- (id<NSFastEnumeration> /* WAPackage* */)findPackagesByNamePublisher:(NSString *)packageName packagePublisher:(NSString *)packagePublisher;
- (id<NSFastEnumeration> /* WAPackage* */)findPackagesByUserSecurityIdNamePublisher:(NSString *)userSecurityId packageName:(NSString *)packageName packagePublisher:(NSString *)packagePublisher;
- (id<NSFastEnumeration> /* WMDPackageUserInformation* */)findUsers:(NSString *)packageFullName;
- (void)setPackageState:(NSString *)packageFullName packageState:(WMDPackageState)packageState;
- (WAPackage*)findPackageByPackageFullName:(NSString *)packageFullName;
- (void)cleanupPackageForUserAsync:(NSString *)packageName userSecurityId:(NSString *)userSecurityId success:(void (^)(WMDDeploymentResult*))success progress:(void (^)(WMDDeploymentProgress*))progress failure:(void (^)(NSError*))failure;
- (id<NSFastEnumeration> /* WAPackage* */)findPackagesByPackageFamilyName:(NSString *)packageFamilyName;
- (id<NSFastEnumeration> /* WAPackage* */)findPackagesByUserSecurityIdPackageFamilyName:(NSString *)userSecurityId packageFamilyName:(NSString *)packageFamilyName;
- (WAPackage*)findPackageByUserSecurityIdPackageFullName:(NSString *)userSecurityId packageFullName:(NSString *)packageFullName;
- (void)removePackageWithOptionsAsync:(NSString *)packageFullName removalOptions:(WMDRemovalOptions)removalOptions success:(void (^)(WMDDeploymentResult*))success progress:(void (^)(WMDDeploymentProgress*))progress failure:(void (^)(NSError*))failure;
- (void)stagePackageWithOptionsAsync:(WFUri*)packageUri dependencyPackageUris:(id<NSFastEnumeration> /* WFUri* */)dependencyPackageUris deploymentOptions:(WMDDeploymentOptions)deploymentOptions success:(void (^)(WMDDeploymentResult*))success progress:(void (^)(WMDDeploymentProgress*))progress failure:(void (^)(NSError*))failure;
- (void)registerPackageByFullNameAsync:(NSString *)mainPackageFullName dependencyPackageFullNames:(id<NSFastEnumeration> /* NSString * */)dependencyPackageFullNames deploymentOptions:(WMDDeploymentOptions)deploymentOptions success:(void (^)(WMDDeploymentResult*))success progress:(void (^)(WMDDeploymentProgress*))progress failure:(void (^)(NSError*))failure;
- (id<NSFastEnumeration> /* WAPackage* */)findPackagesWithPackageTypes:(WMDPackageTypes)packageTypes;
- (id<NSFastEnumeration> /* WAPackage* */)findPackagesByUserSecurityIdWithPackageTypes:(NSString *)userSecurityId packageTypes:(WMDPackageTypes)packageTypes;
- (id<NSFastEnumeration> /* WAPackage* */)findPackagesByNamePublisherWithPackageTypes:(NSString *)packageName packagePublisher:(NSString *)packagePublisher packageTypes:(WMDPackageTypes)packageTypes;
- (id<NSFastEnumeration> /* WAPackage* */)findPackagesByUserSecurityIdNamePublisherWithPackageTypes:(NSString *)userSecurityId packageName:(NSString *)packageName packagePublisher:(NSString *)packagePublisher packageTypes:(WMDPackageTypes)packageTypes;
- (id<NSFastEnumeration> /* WAPackage* */)findPackagesByPackageFamilyNameWithPackageTypes:(NSString *)packageFamilyName packageTypes:(WMDPackageTypes)packageTypes;
- (id<NSFastEnumeration> /* WAPackage* */)findPackagesByUserSecurityIdPackageFamilyNameWithPackageTypes:(NSString *)userSecurityId packageFamilyName:(NSString *)packageFamilyName packageTypes:(WMDPackageTypes)packageTypes;
- (void)stageUserDataAsync:(NSString *)packageFullName success:(void (^)(WMDDeploymentResult*))success progress:(void (^)(WMDDeploymentProgress*))progress failure:(void (^)(NSError*))failure;
- (void)addPackageVolumeAsync:(NSString *)packageStorePath success:(void (^)(WMDPackageVolume*))success failure:(void (^)(NSError*))failure;
- (void)addPackageToVolumeAsync:(WFUri*)packageUri dependencyPackageUris:(id<NSFastEnumeration> /* WFUri* */)dependencyPackageUris deploymentOptions:(WMDDeploymentOptions)deploymentOptions targetVolume:(WMDPackageVolume*)targetVolume success:(void (^)(WMDDeploymentResult*))success progress:(void (^)(WMDDeploymentProgress*))progress failure:(void (^)(NSError*))failure;
- (void)clearPackageStatus:(NSString *)packageFullName status:(WMDPackageStatus)status;
- (void)registerPackageWithAppDataVolumeAsync:(WFUri*)manifestUri dependencyPackageUris:(id<NSFastEnumeration> /* WFUri* */)dependencyPackageUris deploymentOptions:(WMDDeploymentOptions)deploymentOptions appDataVolume:(WMDPackageVolume*)appDataVolume success:(void (^)(WMDDeploymentResult*))success progress:(void (^)(WMDDeploymentProgress*))progress failure:(void (^)(NSError*))failure;
- (WMDPackageVolume*)findPackageVolumeByName:(NSString *)volumeName;
- (id<NSFastEnumeration> /* WMDPackageVolume* */)findPackageVolumes;
- (WMDPackageVolume*)getDefaultPackageVolume;
- (void)movePackageToVolumeAsync:(NSString *)packageFullName deploymentOptions:(WMDDeploymentOptions)deploymentOptions targetVolume:(WMDPackageVolume*)targetVolume success:(void (^)(WMDDeploymentResult*))success progress:(void (^)(WMDDeploymentProgress*))progress failure:(void (^)(NSError*))failure;
- (void)removePackageVolumeAsync:(WMDPackageVolume*)volume success:(void (^)(WMDDeploymentResult*))success progress:(void (^)(WMDDeploymentProgress*))progress failure:(void (^)(NSError*))failure;
- (void)setDefaultPackageVolume:(WMDPackageVolume*)volume;
- (void)setPackageStatus:(NSString *)packageFullName status:(WMDPackageStatus)status;
- (void)setPackageVolumeOfflineAsync:(WMDPackageVolume*)packageVolume success:(void (^)(WMDDeploymentResult*))success progress:(void (^)(WMDDeploymentProgress*))progress failure:(void (^)(NSError*))failure;
- (void)setPackageVolumeOnlineAsync:(WMDPackageVolume*)packageVolume success:(void (^)(WMDDeploymentResult*))success progress:(void (^)(WMDDeploymentProgress*))progress failure:(void (^)(NSError*))failure;
- (void)stagePackageToVolumeAsync:(WFUri*)packageUri dependencyPackageUris:(id<NSFastEnumeration> /* WFUri* */)dependencyPackageUris deploymentOptions:(WMDDeploymentOptions)deploymentOptions targetVolume:(WMDPackageVolume*)targetVolume success:(void (^)(WMDDeploymentResult*))success progress:(void (^)(WMDDeploymentProgress*))progress failure:(void (^)(NSError*))failure;
- (void)stageUserDataWithOptionsAsync:(NSString *)packageFullName deploymentOptions:(WMDDeploymentOptions)deploymentOptions success:(void (^)(WMDDeploymentResult*))success progress:(void (^)(WMDDeploymentProgress*))progress failure:(void (^)(NSError*))failure;
- (void)getPackageVolumesAsyncWithSuccess:(void (^)(NSArray* /* WMDPackageVolume* */))success failure:(void (^)(NSError*))failure;
- (void)addPackageToVolumeAndOptionalPackagesAsync:(WFUri*)packageUri dependencyPackageUris:(id<NSFastEnumeration> /* WFUri* */)dependencyPackageUris deploymentOptions:(WMDDeploymentOptions)deploymentOptions targetVolume:(WMDPackageVolume*)targetVolume optionalPackageFamilyNames:(id<NSFastEnumeration> /* NSString * */)optionalPackageFamilyNames externalPackageUris:(id<NSFastEnumeration> /* WFUri* */)externalPackageUris success:(void (^)(WMDDeploymentResult*))success progress:(void (^)(WMDDeploymentProgress*))progress failure:(void (^)(NSError*))failure;
- (void)stagePackageToVolumeAndOptionalPackagesAsync:(WFUri*)packageUri dependencyPackageUris:(id<NSFastEnumeration> /* WFUri* */)dependencyPackageUris deploymentOptions:(WMDDeploymentOptions)deploymentOptions targetVolume:(WMDPackageVolume*)targetVolume optionalPackageFamilyNames:(id<NSFastEnumeration> /* NSString * */)optionalPackageFamilyNames externalPackageUris:(id<NSFastEnumeration> /* WFUri* */)externalPackageUris success:(void (^)(WMDDeploymentResult*))success progress:(void (^)(WMDDeploymentProgress*))progress failure:(void (^)(NSError*))failure;
- (void)registerPackageByFamilyNameAndOptionalPackagesAsync:(NSString *)mainPackageFamilyName dependencyPackageFamilyNames:(id<NSFastEnumeration> /* NSString * */)dependencyPackageFamilyNames deploymentOptions:(WMDDeploymentOptions)deploymentOptions appDataVolume:(WMDPackageVolume*)appDataVolume optionalPackageFamilyNames:(id<NSFastEnumeration> /* NSString * */)optionalPackageFamilyNames success:(void (^)(WMDDeploymentResult*))success progress:(void (^)(WMDDeploymentProgress*))progress failure:(void (^)(NSError*))failure;
- (void)provisionPackageForAllUsersAsync:(NSString *)packageFamilyName success:(void (^)(WMDDeploymentResult*))success progress:(void (^)(WMDDeploymentProgress*))progress failure:(void (^)(NSError*))failure;
- (void)addPackageByAppInstallerFileAsync:(WFUri*)appInstallerFileUri options:(WMDAddPackageByAppInstallerOptions)options targetVolume:(WMDPackageVolume*)targetVolume success:(void (^)(WMDDeploymentResult*))success progress:(void (^)(WMDDeploymentProgress*))progress failure:(void (^)(NSError*))failure;
- (void)requestAddPackageByAppInstallerFileAsync:(WFUri*)appInstallerFileUri options:(WMDAddPackageByAppInstallerOptions)options targetVolume:(WMDPackageVolume*)targetVolume success:(void (^)(WMDDeploymentResult*))success progress:(void (^)(WMDDeploymentProgress*))progress failure:(void (^)(NSError*))failure;
- (void)addPackageToVolumeAndRelatedSetAsync:(WFUri*)packageUri dependencyPackageUris:(id<NSFastEnumeration> /* WFUri* */)dependencyPackageUris options:(WMDDeploymentOptions)options targetVolume:(WMDPackageVolume*)targetVolume optionalPackageFamilyNames:(id<NSFastEnumeration> /* NSString * */)optionalPackageFamilyNames packageUrisToInstall:(id<NSFastEnumeration> /* WFUri* */)packageUrisToInstall relatedPackageUris:(id<NSFastEnumeration> /* WFUri* */)relatedPackageUris success:(void (^)(WMDDeploymentResult*))success progress:(void (^)(WMDDeploymentProgress*))progress failure:(void (^)(NSError*))failure;
- (void)stagePackageToVolumeAndRelatedSetAsync:(WFUri*)packageUri dependencyPackageUris:(id<NSFastEnumeration> /* WFUri* */)dependencyPackageUris options:(WMDDeploymentOptions)options targetVolume:(WMDPackageVolume*)targetVolume optionalPackageFamilyNames:(id<NSFastEnumeration> /* NSString * */)optionalPackageFamilyNames packageUrisToInstall:(id<NSFastEnumeration> /* WFUri* */)packageUrisToInstall relatedPackageUris:(id<NSFastEnumeration> /* WFUri* */)relatedPackageUris success:(void (^)(WMDDeploymentResult*))success progress:(void (^)(WMDDeploymentProgress*))progress failure:(void (^)(NSError*))failure;
- (void)requestAddPackageAsync:(WFUri*)packageUri dependencyPackageUris:(id<NSFastEnumeration> /* WFUri* */)dependencyPackageUris deploymentOptions:(WMDDeploymentOptions)deploymentOptions targetVolume:(WMDPackageVolume*)targetVolume optionalPackageFamilyNames:(id<NSFastEnumeration> /* NSString * */)optionalPackageFamilyNames relatedPackageUris:(id<NSFastEnumeration> /* WFUri* */)relatedPackageUris success:(void (^)(WMDDeploymentResult*))success progress:(void (^)(WMDDeploymentProgress*))progress failure:(void (^)(NSError*))failure;
@end

#endif // __WMDPackageManager_DEFINED__

