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

// WindowsGamingXboxLiveStorage.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSGAMINGXBOXLIVESTORAGEEXPORT
#define OBJCUWPWINDOWSGAMINGXBOXLIVESTORAGEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsGamingXboxLiveStorage.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WGXSGameSaveContainer, WGXSGameSaveOperationResult, WGXSGameSaveContainerInfoQuery, WGXSGameSaveProviderGetResult, WGXSGameSaveProvider, WGXSGameSaveBlobGetResult, WGXSGameSaveBlobInfoQuery, WGXSGameSaveContainerInfo, WGXSGameSaveBlobInfo, WGXSGameSaveContainerInfoGetResult, WGXSGameSaveBlobInfoGetResult;
@protocol WGXSIGameSaveProvider, WGXSIGameSaveProviderStatics, WGXSIGameSaveProviderGetResult, WGXSIGameSaveContainer, WGXSIGameSaveBlobGetResult, WGXSIGameSaveContainerInfo, WGXSIGameSaveBlobInfo, WGXSIGameSaveContainerInfoQuery, WGXSIGameSaveContainerInfoGetResult, WGXSIGameSaveBlobInfoQuery, WGXSIGameSaveBlobInfoGetResult, WGXSIGameSaveOperationResult;

// Windows.Gaming.XboxLive.Storage.GameSaveErrorStatus
enum _WGXSGameSaveErrorStatus {
    WGXSGameSaveErrorStatusOk = 0,
    WGXSGameSaveErrorStatusAbort = -2147467260,
    WGXSGameSaveErrorStatusInvalidContainerName = -2138898431,
    WGXSGameSaveErrorStatusNoAccess = -2138898430,
    WGXSGameSaveErrorStatusOutOfLocalStorage = -2138898429,
    WGXSGameSaveErrorStatusUserCanceled = -2138898428,
    WGXSGameSaveErrorStatusUpdateTooBig = -2138898427,
    WGXSGameSaveErrorStatusQuotaExceeded = -2138898426,
    WGXSGameSaveErrorStatusProvidedBufferTooSmall = -2138898425,
    WGXSGameSaveErrorStatusBlobNotFound = -2138898424,
    WGXSGameSaveErrorStatusNoXboxLiveInfo = -2138898423,
    WGXSGameSaveErrorStatusContainerNotInSync = -2138898422,
    WGXSGameSaveErrorStatusContainerSyncFailed = -2138898421,
    WGXSGameSaveErrorStatusUserHasNoXboxLiveInfo = -2138898420,
    WGXSGameSaveErrorStatusObjectExpired = -2138898419,
};
typedef unsigned WGXSGameSaveErrorStatus;

#include "WindowsSystem.h"
#include "WindowsFoundationCollections.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Gaming.XboxLive.Storage.GameSaveContainer
#ifndef __WGXSGameSaveContainer_DEFINED__
#define __WGXSGameSaveContainer_DEFINED__

OBJCUWPWINDOWSGAMINGXBOXLIVESTORAGEEXPORT
@interface WGXSGameSaveContainer : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * name;
@property (readonly) WGXSGameSaveProvider* provider;
- (void)submitUpdatesAsync:(NSDictionary* /* NSString *, RTObject<WSSIBuffer>* */)blobsToWrite blobsToDelete:(id<NSFastEnumeration> /* NSString * */)blobsToDelete displayName:(NSString *)displayName success:(void (^)(WGXSGameSaveOperationResult*))success failure:(void (^)(NSError*))failure;
- (void)readAsync:(NSDictionary* /* NSString *, RTObject<WSSIBuffer>* */)blobsToRead success:(void (^)(WGXSGameSaveOperationResult*))success failure:(void (^)(NSError*))failure;
- (void)getAsync:(id<NSFastEnumeration> /* NSString * */)blobsToRead success:(void (^)(WGXSGameSaveBlobGetResult*))success failure:(void (^)(NSError*))failure;
- (void)submitPropertySetUpdatesAsync:(RTObject<WFCIPropertySet>*)blobsToWrite blobsToDelete:(id<NSFastEnumeration> /* NSString * */)blobsToDelete displayName:(NSString *)displayName success:(void (^)(WGXSGameSaveOperationResult*))success failure:(void (^)(NSError*))failure;
- (WGXSGameSaveBlobInfoQuery*)createBlobInfoQuery:(NSString *)blobNamePrefix;
@end

#endif // __WGXSGameSaveContainer_DEFINED__

// Windows.Gaming.XboxLive.Storage.GameSaveOperationResult
#ifndef __WGXSGameSaveOperationResult_DEFINED__
#define __WGXSGameSaveOperationResult_DEFINED__

OBJCUWPWINDOWSGAMINGXBOXLIVESTORAGEEXPORT
@interface WGXSGameSaveOperationResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGXSGameSaveErrorStatus status;
@end

#endif // __WGXSGameSaveOperationResult_DEFINED__

// Windows.Gaming.XboxLive.Storage.GameSaveContainerInfoQuery
#ifndef __WGXSGameSaveContainerInfoQuery_DEFINED__
#define __WGXSGameSaveContainerInfoQuery_DEFINED__

OBJCUWPWINDOWSGAMINGXBOXLIVESTORAGEEXPORT
@interface WGXSGameSaveContainerInfoQuery : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)getContainerInfoAsyncWithSuccess:(void (^)(WGXSGameSaveContainerInfoGetResult*))success failure:(void (^)(NSError*))failure;
- (void)getContainerInfoWithIndexAndMaxAsync:(unsigned int)startIndex maxNumberOfItems:(unsigned int)maxNumberOfItems success:(void (^)(WGXSGameSaveContainerInfoGetResult*))success failure:(void (^)(NSError*))failure;
- (void)getItemCountAsyncWithSuccess:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure;
@end

#endif // __WGXSGameSaveContainerInfoQuery_DEFINED__

// Windows.Gaming.XboxLive.Storage.GameSaveProviderGetResult
#ifndef __WGXSGameSaveProviderGetResult_DEFINED__
#define __WGXSGameSaveProviderGetResult_DEFINED__

OBJCUWPWINDOWSGAMINGXBOXLIVESTORAGEEXPORT
@interface WGXSGameSaveProviderGetResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGXSGameSaveErrorStatus status;
@property (readonly) WGXSGameSaveProvider* value;
@end

#endif // __WGXSGameSaveProviderGetResult_DEFINED__

// Windows.Gaming.XboxLive.Storage.GameSaveProvider
#ifndef __WGXSGameSaveProvider_DEFINED__
#define __WGXSGameSaveProvider_DEFINED__

OBJCUWPWINDOWSGAMINGXBOXLIVESTORAGEEXPORT
@interface WGXSGameSaveProvider : RTObject
+ (void)getForUserAsync:(WSUser*)user serviceConfigId:(NSString *)serviceConfigId success:(void (^)(WGXSGameSaveProviderGetResult*))success failure:(void (^)(NSError*))failure;
+ (void)getSyncOnDemandForUserAsync:(WSUser*)user serviceConfigId:(NSString *)serviceConfigId success:(void (^)(WGXSGameSaveProviderGetResult*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* NSString * */ containersChangedSinceLastSync;
@property (readonly) WSUser* user;
- (WGXSGameSaveContainer*)createContainer:(NSString *)name;
- (void)deleteContainerAsync:(NSString *)name success:(void (^)(WGXSGameSaveOperationResult*))success failure:(void (^)(NSError*))failure;
- (WGXSGameSaveContainerInfoQuery*)createContainerInfoQuery;
- (WGXSGameSaveContainerInfoQuery*)createContainerInfoQueryWithName:(NSString *)containerNamePrefix;
- (void)getRemainingBytesInQuotaAsyncWithSuccess:(void (^)(int64_t))success failure:(void (^)(NSError*))failure;
@end

#endif // __WGXSGameSaveProvider_DEFINED__

// Windows.Gaming.XboxLive.Storage.GameSaveBlobGetResult
#ifndef __WGXSGameSaveBlobGetResult_DEFINED__
#define __WGXSGameSaveBlobGetResult_DEFINED__

OBJCUWPWINDOWSGAMINGXBOXLIVESTORAGEEXPORT
@interface WGXSGameSaveBlobGetResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGXSGameSaveErrorStatus status;
@property (readonly) NSDictionary* /* NSString *, RTObject<WSSIBuffer>* */ value;
@end

#endif // __WGXSGameSaveBlobGetResult_DEFINED__

// Windows.Gaming.XboxLive.Storage.GameSaveBlobInfoQuery
#ifndef __WGXSGameSaveBlobInfoQuery_DEFINED__
#define __WGXSGameSaveBlobInfoQuery_DEFINED__

OBJCUWPWINDOWSGAMINGXBOXLIVESTORAGEEXPORT
@interface WGXSGameSaveBlobInfoQuery : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)getBlobInfoAsyncWithSuccess:(void (^)(WGXSGameSaveBlobInfoGetResult*))success failure:(void (^)(NSError*))failure;
- (void)getBlobInfoWithIndexAndMaxAsync:(unsigned int)startIndex maxNumberOfItems:(unsigned int)maxNumberOfItems success:(void (^)(WGXSGameSaveBlobInfoGetResult*))success failure:(void (^)(NSError*))failure;
- (void)getItemCountAsyncWithSuccess:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure;
@end

#endif // __WGXSGameSaveBlobInfoQuery_DEFINED__

// Windows.Gaming.XboxLive.Storage.GameSaveContainerInfo
#ifndef __WGXSGameSaveContainerInfo_DEFINED__
#define __WGXSGameSaveContainerInfo_DEFINED__

OBJCUWPWINDOWSGAMINGXBOXLIVESTORAGEEXPORT
@interface WGXSGameSaveContainerInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * displayName;
@property (readonly) WFDateTime* lastModifiedTime;
@property (readonly) NSString * name;
@property (readonly) BOOL needsSync;
@property (readonly) uint64_t totalSize;
@end

#endif // __WGXSGameSaveContainerInfo_DEFINED__

// Windows.Gaming.XboxLive.Storage.GameSaveBlobInfo
#ifndef __WGXSGameSaveBlobInfo_DEFINED__
#define __WGXSGameSaveBlobInfo_DEFINED__

OBJCUWPWINDOWSGAMINGXBOXLIVESTORAGEEXPORT
@interface WGXSGameSaveBlobInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * name;
@property (readonly) unsigned int size;
@end

#endif // __WGXSGameSaveBlobInfo_DEFINED__

// Windows.Gaming.XboxLive.Storage.GameSaveContainerInfoGetResult
#ifndef __WGXSGameSaveContainerInfoGetResult_DEFINED__
#define __WGXSGameSaveContainerInfoGetResult_DEFINED__

OBJCUWPWINDOWSGAMINGXBOXLIVESTORAGEEXPORT
@interface WGXSGameSaveContainerInfoGetResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGXSGameSaveErrorStatus status;
@property (readonly) NSArray* /* WGXSGameSaveContainerInfo* */ value;
@end

#endif // __WGXSGameSaveContainerInfoGetResult_DEFINED__

// Windows.Gaming.XboxLive.Storage.GameSaveBlobInfoGetResult
#ifndef __WGXSGameSaveBlobInfoGetResult_DEFINED__
#define __WGXSGameSaveBlobInfoGetResult_DEFINED__

OBJCUWPWINDOWSGAMINGXBOXLIVESTORAGEEXPORT
@interface WGXSGameSaveBlobInfoGetResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGXSGameSaveErrorStatus status;
@property (readonly) NSArray* /* WGXSGameSaveBlobInfo* */ value;
@end

#endif // __WGXSGameSaveBlobInfoGetResult_DEFINED__

