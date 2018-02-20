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

// WindowsServicesMapsOfflineMaps.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSSERVICESMAPSOFFLINEMAPSEXPORT
#define OBJCUWPWINDOWSSERVICESMAPSOFFLINEMAPSEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsServicesMapsOfflineMaps.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSMOOfflineMapPackage, WSMOOfflineMapPackageStartDownloadResult, WSMOOfflineMapPackageQueryResult;
@protocol WSMOIOfflineMapPackageQueryResult, WSMOIOfflineMapPackageStartDownloadResult, WSMOIOfflineMapPackage, WSMOIOfflineMapPackageStatics;

// Windows.Services.Maps.OfflineMaps.OfflineMapPackageQueryStatus
enum _WSMOOfflineMapPackageQueryStatus {
    WSMOOfflineMapPackageQueryStatusSuccess = 0,
    WSMOOfflineMapPackageQueryStatusUnknownError = 1,
    WSMOOfflineMapPackageQueryStatusInvalidCredentials = 2,
    WSMOOfflineMapPackageQueryStatusNetworkFailure = 3,
};
typedef unsigned WSMOOfflineMapPackageQueryStatus;

// Windows.Services.Maps.OfflineMaps.OfflineMapPackageStatus
enum _WSMOOfflineMapPackageStatus {
    WSMOOfflineMapPackageStatusNotDownloaded = 0,
    WSMOOfflineMapPackageStatusDownloading = 1,
    WSMOOfflineMapPackageStatusDownloaded = 2,
    WSMOOfflineMapPackageStatusDeleting = 3,
};
typedef unsigned WSMOOfflineMapPackageStatus;

// Windows.Services.Maps.OfflineMaps.OfflineMapPackageStartDownloadStatus
enum _WSMOOfflineMapPackageStartDownloadStatus {
    WSMOOfflineMapPackageStartDownloadStatusSuccess = 0,
    WSMOOfflineMapPackageStartDownloadStatusUnknownError = 1,
    WSMOOfflineMapPackageStartDownloadStatusInvalidCredentials = 2,
    WSMOOfflineMapPackageStartDownloadStatusDeniedWithoutCapability = 3,
};
typedef unsigned WSMOOfflineMapPackageStartDownloadStatus;

#include "WindowsFoundation.h"
#include "WindowsDevicesGeolocation.h"

#import <Foundation/Foundation.h>

// Windows.Services.Maps.OfflineMaps.OfflineMapPackage
#ifndef __WSMOOfflineMapPackage_DEFINED__
#define __WSMOOfflineMapPackage_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSOFFLINEMAPSEXPORT
@interface WSMOOfflineMapPackage : RTObject
+ (void)findPackagesAsync:(WDGGeopoint*)queryPoint success:(void (^)(WSMOOfflineMapPackageQueryResult*))success failure:(void (^)(NSError*))failure;
+ (void)findPackagesInBoundingBoxAsync:(WDGGeoboundingBox*)queryBoundingBox success:(void (^)(WSMOOfflineMapPackageQueryResult*))success failure:(void (^)(NSError*))failure;
+ (void)findPackagesInGeocircleAsync:(WDGGeocircle*)queryCircle success:(void (^)(WSMOOfflineMapPackageQueryResult*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * displayName;
@property (readonly) NSString * enclosingRegionName;
@property (readonly) uint64_t estimatedSizeInBytes;
@property (readonly) WSMOOfflineMapPackageStatus status;
- (EventRegistrationToken)addStatusChangedEvent:(void(^)(WSMOOfflineMapPackage*, RTObject*))del;
- (void)removeStatusChangedEvent:(EventRegistrationToken)tok;
- (void)requestStartDownloadAsyncWithSuccess:(void (^)(WSMOOfflineMapPackageStartDownloadResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSMOOfflineMapPackage_DEFINED__

// Windows.Services.Maps.OfflineMaps.OfflineMapPackageStartDownloadResult
#ifndef __WSMOOfflineMapPackageStartDownloadResult_DEFINED__
#define __WSMOOfflineMapPackageStartDownloadResult_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSOFFLINEMAPSEXPORT
@interface WSMOOfflineMapPackageStartDownloadResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSMOOfflineMapPackageStartDownloadStatus status;
@end

#endif // __WSMOOfflineMapPackageStartDownloadResult_DEFINED__

// Windows.Services.Maps.OfflineMaps.OfflineMapPackageQueryResult
#ifndef __WSMOOfflineMapPackageQueryResult_DEFINED__
#define __WSMOOfflineMapPackageQueryResult_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSOFFLINEMAPSEXPORT
@interface WSMOOfflineMapPackageQueryResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WSMOOfflineMapPackage* */ packages;
@property (readonly) WSMOOfflineMapPackageQueryStatus status;
@end

#endif // __WSMOOfflineMapPackageQueryResult_DEFINED__

