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

// WindowsManagementDeployment.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WMDDeploymentResult, WMDPackageUserInformation, WMDPackageManager;
@class WMDDeploymentProgress;
@protocol WMDIDeploymentResult
, WMDIPackageUserInformation, WMDIPackageManager, WMDIPackageManager2;

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
};
typedef unsigned WMDDeploymentOptions;

// Windows.Management.Deployment.RemovalOptions
enum _WMDRemovalOptions {
    WMDRemovalOptionsNone = 0,
    WMDRemovalOptionsPreserveApplicationData = 4096,
};
typedef unsigned WMDRemovalOptions;

// Windows.Management.Deployment.PackageTypes
enum _WMDPackageTypes {
    WMDPackageTypesNone = 0,
    WMDPackageTypesMain = 1,
    WMDPackageTypesFramework = 2,
    WMDPackageTypesResource = 4,
    WMDPackageTypesBundle = 8,
};
typedef unsigned WMDPackageTypes;

// Windows.Management.Deployment.PackageInstallState
enum _WMDPackageInstallState {
    WMDPackageInstallStateNotInstalled = 0,
    WMDPackageInstallStateStaged = 1,
    WMDPackageInstallStateInstalled = 2,
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

#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"
#include "WindowsApplicationModel.h"

// [struct] Windows.Management.Deployment.DeploymentProgress
WINRT_EXPORT
@interface WMDDeploymentProgress : NSObject
+ (instancetype) new;
@property WMDDeploymentProgressState state;
@property unsigned percentage;
@end

// Windows.Management.Deployment.DeploymentResult
#ifndef __WMDDeploymentResult_DEFINED__
#define __WMDDeploymentResult_DEFINED__

WINRT_EXPORT
@interface WMDDeploymentResult : RTObject
@property (readonly) WFGUID* activityId;
@property (readonly) NSString* errorText;
@property (readonly) HRESULT extendedErrorCode;
@end

#endif // __WMDDeploymentResult_DEFINED__

// Windows.Management.Deployment.PackageUserInformation
#ifndef __WMDPackageUserInformation_DEFINED__
#define __WMDPackageUserInformation_DEFINED__

WINRT_EXPORT
@interface WMDPackageUserInformation : RTObject
@property (readonly) WMDPackageInstallState installState;
@property (readonly) NSString* userSecurityId;
@end

#endif // __WMDPackageUserInformation_DEFINED__

// Windows.Management.Deployment.PackageManager
#ifndef __WMDPackageManager_DEFINED__
#define __WMDPackageManager_DEFINED__

WINRT_EXPORT
@interface WMDPackageManager : RTObject
+ (instancetype)create ACTIVATOR;
- (void)addPackageAsync:(WFUri*)packageUri
  dependencyPackageUris:(id<NSFastEnumeration> /*WFUri*/)dependencyPackageUris
      deploymentOptions:(WMDDeploymentOptions)deploymentOptions
                success:(void (^)(WMDDeploymentResult*))success
               progress:(void (^)(WMDDeploymentProgress*))progress
                failure:(void (^)(NSError*))failure;
- (void)updatePackageAsync:(WFUri*)packageUri
     dependencyPackageUris:(id<NSFastEnumeration> /*WFUri*/)dependencyPackageUris
         deploymentOptions:(WMDDeploymentOptions)deploymentOptions
                   success:(void (^)(WMDDeploymentResult*))success
                  progress:(void (^)(WMDDeploymentProgress*))progress
                   failure:(void (^)(NSError*))failure;
- (void)removePackageAsync:(NSString*)packageFullName
                   success:(void (^)(WMDDeploymentResult*))success
                  progress:(void (^)(WMDDeploymentProgress*))progress
                   failure:(void (^)(NSError*))failure;
- (void)stagePackageAsync:(WFUri*)packageUri
    dependencyPackageUris:(id<NSFastEnumeration> /*WFUri*/)dependencyPackageUris
                  success:(void (^)(WMDDeploymentResult*))success
                 progress:(void (^)(WMDDeploymentProgress*))progress
                  failure:(void (^)(NSError*))failure;
- (void)registerPackageAsync:(WFUri*)manifestUri
       dependencyPackageUris:(id<NSFastEnumeration> /*WFUri*/)dependencyPackageUris
           deploymentOptions:(WMDDeploymentOptions)deploymentOptions
                     success:(void (^)(WMDDeploymentResult*))success
                    progress:(void (^)(WMDDeploymentProgress*))progress
                     failure:(void (^)(NSError*))failure;
- (id<NSFastEnumeration> /*WAPackage*/)findPackages;
- (id<NSFastEnumeration> /*WAPackage*/)findPackagesByUserSecurityId:(NSString*)userSecurityId;
- (id<NSFastEnumeration> /*WAPackage*/)findPackagesByNamePublisher:(NSString*)packageName packagePublisher:(NSString*)packagePublisher;
- (id<NSFastEnumeration> /*WAPackage*/)findPackagesByUserSecurityIdNamePublisher:(NSString*)userSecurityId
                                                                     packageName:(NSString*)packageName
                                                                packagePublisher:(NSString*)packagePublisher;
- (id<NSFastEnumeration> /*WMDPackageUserInformation*/)findUsers:(NSString*)packageFullName;
- (void)setPackageState:(NSString*)packageFullName packageState:(WMDPackageState)packageState;
- (WAPackage*)findPackageByPackageFullName:(NSString*)packageFullName;
- (void)cleanupPackageForUserAsync:(NSString*)packageName
                    userSecurityId:(NSString*)userSecurityId
                           success:(void (^)(WMDDeploymentResult*))success
                          progress:(void (^)(WMDDeploymentProgress*))progress
                           failure:(void (^)(NSError*))failure;
- (id<NSFastEnumeration> /*WAPackage*/)findPackagesByPackageFamilyName:(NSString*)packageFamilyName;
- (id<NSFastEnumeration> /*WAPackage*/)findPackagesByUserSecurityIdPackageFamilyName:(NSString*)userSecurityId
                                                                   packageFamilyName:(NSString*)packageFamilyName;
- (WAPackage*)findPackageByUserSecurityIdPackageFullName:(NSString*)userSecurityId packageFullName:(NSString*)packageFullName;
- (void)removePackageWithOptionsAsync:(NSString*)packageFullName
                       removalOptions:(WMDRemovalOptions)removalOptions
                              success:(void (^)(WMDDeploymentResult*))success
                             progress:(void (^)(WMDDeploymentProgress*))progress
                              failure:(void (^)(NSError*))failure;
- (void)stagePackageWithOptionsAsync:(WFUri*)packageUri
               dependencyPackageUris:(id<NSFastEnumeration> /*WFUri*/)dependencyPackageUris
                   deploymentOptions:(WMDDeploymentOptions)deploymentOptions
                             success:(void (^)(WMDDeploymentResult*))success
                            progress:(void (^)(WMDDeploymentProgress*))progress
                             failure:(void (^)(NSError*))failure;
- (void)registerPackageByFullNameAsync:(NSString*)mainPackageFullName
            dependencyPackageFullNames:(id<NSFastEnumeration> /*String*/)dependencyPackageFullNames
                     deploymentOptions:(WMDDeploymentOptions)deploymentOptions
                               success:(void (^)(WMDDeploymentResult*))success
                              progress:(void (^)(WMDDeploymentProgress*))progress
                               failure:(void (^)(NSError*))failure;
- (id<NSFastEnumeration> /*WAPackage*/)findPackagesWithPackageTypes:(WMDPackageTypes)packageTypes;
- (id<NSFastEnumeration> /*WAPackage*/)findPackagesByUserSecurityIdWithPackageTypes:(NSString*)userSecurityId
                                                                       packageTypes:(WMDPackageTypes)packageTypes;
- (id<NSFastEnumeration> /*WAPackage*/)findPackagesByNamePublisherWithPackageTypes:(NSString*)packageName
                                                                  packagePublisher:(NSString*)packagePublisher
                                                                      packageTypes:(WMDPackageTypes)packageTypes;
- (id<NSFastEnumeration> /*WAPackage*/)findPackagesByUserSecurityIdNamePublisherWithPackageTypes:(NSString*)userSecurityId
                                                                                     packageName:(NSString*)packageName
                                                                                packagePublisher:(NSString*)packagePublisher
                                                                                    packageTypes:(WMDPackageTypes)packageTypes;
- (id<NSFastEnumeration> /*WAPackage*/)findPackagesByPackageFamilyNameWithPackageTypes:(NSString*)packageFamilyName
                                                                          packageTypes:(WMDPackageTypes)packageTypes;
- (id<NSFastEnumeration> /*WAPackage*/)findPackagesByUserSecurityIdPackageFamilyNameWithPackageTypes:(NSString*)userSecurityId
                                                                                   packageFamilyName:(NSString*)packageFamilyName
                                                                                        packageTypes:(WMDPackageTypes)packageTypes;
- (void)stageUserDataAsync:(NSString*)packageFullName
                   success:(void (^)(WMDDeploymentResult*))success
                  progress:(void (^)(WMDDeploymentProgress*))progress
                   failure:(void (^)(NSError*))failure;
@end

#endif // __WMDPackageManager_DEFINED__
