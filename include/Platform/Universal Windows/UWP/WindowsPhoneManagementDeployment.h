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

// WindowsPhoneManagementDeployment.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSPHONEMANAGEMENTDEPLOYMENTEXPORT
#define OBJCUWPWINDOWSPHONEMANAGEMENTDEPLOYMENTEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsPhoneManagementDeployment.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WPMDEnterprise, WPMDEnterpriseEnrollmentResult, WPMDPackageInstallResult, WPMDInstallationManager, WPMDEnterpriseEnrollmentManager;
@protocol WPMDIEnterprise, WPMDIEnterpriseEnrollmentManager, WPMDIPackageInstallResult, WPMDIPackageInstallResult2, WPMDIEnterpriseEnrollmentResult, WPMDIInstallationManagerStatics, WPMDIInstallationManagerStatics2;

// Windows.Phone.Management.Deployment.EnterpriseStatus
enum _WPMDEnterpriseStatus {
    WPMDEnterpriseStatusEnrolled = 0,
    WPMDEnterpriseStatusDisabled = 1,
    WPMDEnterpriseStatusRevoked = 2,
    WPMDEnterpriseStatusExpired = 3,
};
typedef unsigned WPMDEnterpriseStatus;

// Windows.Phone.Management.Deployment.EnterpriseEnrollmentStatus
enum _WPMDEnterpriseEnrollmentStatus {
    WPMDEnterpriseEnrollmentStatusSuccess = 0,
    WPMDEnterpriseEnrollmentStatusCancelledByUser = 1,
    WPMDEnterpriseEnrollmentStatusUnknownFailure = 2,
};
typedef unsigned WPMDEnterpriseEnrollmentStatus;

#include "WindowsFoundation.h"
#include "WindowsManagementDeployment.h"
#include "WindowsApplicationModel.h"

#import <Foundation/Foundation.h>

// Windows.Phone.Management.Deployment.Enterprise
#ifndef __WPMDEnterprise_DEFINED__
#define __WPMDEnterprise_DEFINED__

OBJCUWPWINDOWSPHONEMANAGEMENTDEPLOYMENTEXPORT
@interface WPMDEnterprise : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFDateTime* enrollmentValidFrom;
@property (readonly) WFDateTime* enrollmentValidTo;
@property (readonly) WFGUID* id;
@property (readonly) NSString * name;
@property (readonly) WPMDEnterpriseStatus status;
@property (readonly) int workplaceId;
@end

#endif // __WPMDEnterprise_DEFINED__

// Windows.Phone.Management.Deployment.EnterpriseEnrollmentResult
#ifndef __WPMDEnterpriseEnrollmentResult_DEFINED__
#define __WPMDEnterpriseEnrollmentResult_DEFINED__

OBJCUWPWINDOWSPHONEMANAGEMENTDEPLOYMENTEXPORT
@interface WPMDEnterpriseEnrollmentResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WPMDEnterprise* enrolledEnterprise;
@property (readonly) WPMDEnterpriseEnrollmentStatus status;
@end

#endif // __WPMDEnterpriseEnrollmentResult_DEFINED__

// Windows.Phone.Management.Deployment.PackageInstallResult
#ifndef __WPMDPackageInstallResult_DEFINED__
#define __WPMDPackageInstallResult_DEFINED__

OBJCUWPWINDOWSPHONEMANAGEMENTDEPLOYMENTEXPORT
@interface WPMDPackageInstallResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMDPackageInstallState installState;
@property (readonly) NSString * productId;
@property (readonly) NSString * errorText;
@end

#endif // __WPMDPackageInstallResult_DEFINED__

// Windows.Phone.Management.Deployment.InstallationManager
#ifndef __WPMDInstallationManager_DEFINED__
#define __WPMDInstallationManager_DEFINED__

OBJCUWPWINDOWSPHONEMANAGEMENTDEPLOYMENTEXPORT
@interface WPMDInstallationManager : RTObject
+ (void)addPackageAsync:(NSString *)title sourceLocation:(WFUri*)sourceLocation success:(void (^)(WPMDPackageInstallResult*))success progress:(void (^)(unsigned int))progress failure:(void (^)(NSError*))failure;
+ (void)addPackagePreloadedAsync:(NSString *)title sourceLocation:(WFUri*)sourceLocation instanceId:(NSString *)instanceId offerId:(NSString *)offerId license:(WFUri*)license success:(void (^)(WPMDPackageInstallResult*))success progress:(void (^)(unsigned int))progress failure:(void (^)(NSError*))failure;
// Failed to generate member GetPendingPackageInstalls (Can't marshal Windows.Foundation.IAsyncOperationWithProgress`2<Windows.Phone.Management.Deployment.PackageInstallResult,UInt32>)
+ (id<NSFastEnumeration> /* WAPackage* */)findPackagesForCurrentPublisher;
+ (id<NSFastEnumeration> /* WAPackage* */)findPackages;
+ (void)removePackageAsync:(NSString *)packageFullName removalOptions:(WMDRemovalOptions)removalOptions success:(void (^)(WPMDPackageInstallResult*))success progress:(void (^)(unsigned int))progress failure:(void (^)(NSError*))failure;
+ (void)registerPackageAsync:(WFUri*)manifestUri dependencyPackageUris:(id<NSFastEnumeration> /* WFUri* */)dependencyPackageUris deploymentOptions:(WMDDeploymentOptions)deploymentOptions success:(void (^)(WPMDPackageInstallResult*))success progress:(void (^)(unsigned int))progress failure:(void (^)(NSError*))failure;
+ (id<NSFastEnumeration> /* WAPackage* */)findPackagesByNamePublisher:(NSString *)packageName packagePublisher:(NSString *)packagePublisher;
@end

#endif // __WPMDInstallationManager_DEFINED__

// Windows.Phone.Management.Deployment.EnterpriseEnrollmentManager
#ifndef __WPMDEnterpriseEnrollmentManager_DEFINED__
#define __WPMDEnterpriseEnrollmentManager_DEFINED__

OBJCUWPWINDOWSPHONEMANAGEMENTDEPLOYMENTEXPORT
@interface WPMDEnterpriseEnrollmentManager : RTObject
+ (RTObject<WFIAsyncAction>*)validateEnterprisesAsync;
+ (void)requestEnrollmentAsync:(NSString *)enrollmentToken success:(void (^)(WPMDEnterpriseEnrollmentResult*))success failure:(void (^)(NSError*))failure;
+ (void)requestUnenrollmentAsync:(WPMDEnterprise*)enterprise success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
+ (WPMDEnterprise*)currentEnterprise;
+ (NSArray* /* WPMDEnterprise* */)enrolledEnterprises;
@end

#endif // __WPMDEnterpriseEnrollmentManager_DEFINED__

