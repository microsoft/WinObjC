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

// WindowsNetworkingBackgroundTransfer.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WNBDownloadOperation, WNBUnconstrainedTransferRequestResult, WNBUploadOperation, WNBBackgroundTransferGroup,
    WNBBackgroundTransferContentPart, WNBResponseInformation, WNBBackgroundDownloader, WNBBackgroundUploader, WNBBackgroundTransferError,
    WNBContentPrefetcher;
@class WNBBackgroundDownloadProgress, WNBBackgroundUploadProgress;
@protocol WNBIBackgroundTransferBase
, WNBIUnconstrainedTransferRequestResult, WNBIBackgroundDownloaderUserConsent, WNBIBackgroundUploaderUserConsent, WNBIBackgroundDownloader,
    WNBIBackgroundDownloader2, WNBIBackgroundUploader, WNBIBackgroundUploader2, WNBIBackgroundTransferOperation,
    WNBIBackgroundTransferOperationPriority, WNBIDownloadOperation, WNBIDownloadOperation2, WNBIUploadOperation, WNBIUploadOperation2,
    WNBIBackgroundDownloaderStaticMethods, WNBIBackgroundDownloaderStaticMethods2, WNBIBackgroundUploaderStaticMethods,
    WNBIBackgroundUploaderStaticMethods2, WNBIResponseInformation, WNBIBackgroundTransferErrorStaticMethods,
    WNBIBackgroundTransferContentPart, WNBIBackgroundTransferContentPartFactory, WNBIBackgroundTransferGroup,
    WNBIBackgroundTransferGroupStatics, WNBIContentPrefetcherTime, WNBIContentPrefetcher;

// Windows.Networking.BackgroundTransfer.BackgroundTransferStatus
enum _WNBBackgroundTransferStatus {
    WNBBackgroundTransferStatusIdle = 0,
    WNBBackgroundTransferStatusRunning = 1,
    WNBBackgroundTransferStatusPausedByApplication = 2,
    WNBBackgroundTransferStatusPausedCostedNetwork = 3,
    WNBBackgroundTransferStatusPausedNoNetwork = 4,
    WNBBackgroundTransferStatusCompleted = 5,
    WNBBackgroundTransferStatusCanceled = 6,
    WNBBackgroundTransferStatusError = 7,
};
typedef unsigned WNBBackgroundTransferStatus;

// Windows.Networking.BackgroundTransfer.BackgroundTransferCostPolicy
enum _WNBBackgroundTransferCostPolicy {
    WNBBackgroundTransferCostPolicyDefault = 0,
    WNBBackgroundTransferCostPolicyUnrestrictedOnly = 1,
    WNBBackgroundTransferCostPolicyAlways = 2,
};
typedef unsigned WNBBackgroundTransferCostPolicy;

// Windows.Networking.BackgroundTransfer.BackgroundTransferPriority
enum _WNBBackgroundTransferPriority {
    WNBBackgroundTransferPriorityDefault = 0,
    WNBBackgroundTransferPriorityHigh = 1,
};
typedef unsigned WNBBackgroundTransferPriority;

// Windows.Networking.BackgroundTransfer.BackgroundTransferBehavior
enum _WNBBackgroundTransferBehavior {
    WNBBackgroundTransferBehaviorParallel = 0,
    WNBBackgroundTransferBehaviorSerialized = 1,
};
typedef unsigned WNBBackgroundTransferBehavior;

#include "WindowsWeb.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"
#include "WindowsSecurityCredentials.h"
#include "WindowsFoundation.h"
#include "WindowsStorage.h"
#include "WindowsUINotifications.h"

// [struct] Windows.Networking.BackgroundTransfer.BackgroundDownloadProgress
WINRT_EXPORT
@interface WNBBackgroundDownloadProgress : NSObject
+ (instancetype) new;
@property uint64_t bytesReceived;
@property uint64_t totalBytesToReceive;
@property WNBBackgroundTransferStatus status;
@property BOOL hasResponseChanged;
@property BOOL hasRestarted;
@end

// [struct] Windows.Networking.BackgroundTransfer.BackgroundUploadProgress
WINRT_EXPORT
@interface WNBBackgroundUploadProgress : NSObject
+ (instancetype) new;
@property uint64_t bytesReceived;
@property uint64_t bytesSent;
@property uint64_t totalBytesToReceive;
@property uint64_t totalBytesToSend;
@property WNBBackgroundTransferStatus status;
@property BOOL hasResponseChanged;
@property BOOL hasRestarted;
@end

// Windows.Networking.BackgroundTransfer.IBackgroundTransferBase
#ifndef __WNBIBackgroundTransferBase_DEFINED__
#define __WNBIBackgroundTransferBase_DEFINED__

@protocol WNBIBackgroundTransferBase
@property WNBBackgroundTransferCostPolicy costPolicy;
@property (copy) NSString* group;
@property (copy) NSString* method;
@property (copy) WSCPasswordCredential* proxyCredential;
@property (copy) WSCPasswordCredential* serverCredential;
- (void)setRequestHeader:(NSString*)headerName headerValue:(NSString*)headerValue;
@end

#endif // __WNBIBackgroundTransferBase_DEFINED__

// Windows.Networking.BackgroundTransfer.IBackgroundTransferOperation
#ifndef __WNBIBackgroundTransferOperation_DEFINED__
#define __WNBIBackgroundTransferOperation_DEFINED__

@protocol WNBIBackgroundTransferOperation
@property WNBBackgroundTransferCostPolicy costPolicy;
@property (readonly) NSString* group;
@property (readonly) WFGUID* guid;
@property (readonly) NSString* method;
@property (readonly) WFUri* requestedUri;
- (RTObject<WSSIInputStream>*)getResultStreamAt:(uint64_t)position;
- (WNBResponseInformation*)getResponseInformation;
@end

#endif // __WNBIBackgroundTransferOperation_DEFINED__

// Windows.Networking.BackgroundTransfer.IBackgroundTransferOperationPriority
#ifndef __WNBIBackgroundTransferOperationPriority_DEFINED__
#define __WNBIBackgroundTransferOperationPriority_DEFINED__

@protocol WNBIBackgroundTransferOperationPriority
@property WNBBackgroundTransferPriority priority;
@end

#endif // __WNBIBackgroundTransferOperationPriority_DEFINED__

// Windows.Networking.BackgroundTransfer.IBackgroundTransferContentPartFactory
#ifndef __WNBIBackgroundTransferContentPartFactory_DEFINED__
#define __WNBIBackgroundTransferContentPartFactory_DEFINED__

@protocol WNBIBackgroundTransferContentPartFactory
- (WNBBackgroundTransferContentPart*)createWithName:(NSString*)name;
- (WNBBackgroundTransferContentPart*)createWithNameAndFileName:(NSString*)name fileName:(NSString*)fileName;
@end

#endif // __WNBIBackgroundTransferContentPartFactory_DEFINED__

// Windows.Networking.BackgroundTransfer.DownloadOperation
#ifndef __WNBDownloadOperation_DEFINED__
#define __WNBDownloadOperation_DEFINED__

WINRT_EXPORT
@interface WNBDownloadOperation : RTObject <WNBIBackgroundTransferOperation, WNBIBackgroundTransferOperationPriority>
@property (readonly) WNBBackgroundDownloadProgress* progress;
@property (readonly) RTObject<WSIStorageFile>* resultFile;
@property WNBBackgroundTransferPriority priority;
@property WNBBackgroundTransferCostPolicy costPolicy;
@property (readonly) NSString* group;
@property (readonly) WFGUID* guid;
@property (readonly) NSString* method;
@property (readonly) WFUri* requestedUri;
@property (readonly) WNBBackgroundTransferGroup* transferGroup;
- (void)startAsyncWithSuccess:(void (^)(WNBDownloadOperation*))success
                     progress:(void (^)(WNBDownloadOperation*))progress
                      failure:(void (^)(NSError*))failure;
- (void)attachAsyncWithSuccess:(void (^)(WNBDownloadOperation*))success
                      progress:(void (^)(WNBDownloadOperation*))progress
                       failure:(void (^)(NSError*))failure;
- (void)pause;
- (void)resume;
- (RTObject<WSSIInputStream>*)getResultStreamAt:(uint64_t)position;
- (WNBResponseInformation*)getResponseInformation;
@end

#endif // __WNBDownloadOperation_DEFINED__

// Windows.Networking.BackgroundTransfer.UnconstrainedTransferRequestResult
#ifndef __WNBUnconstrainedTransferRequestResult_DEFINED__
#define __WNBUnconstrainedTransferRequestResult_DEFINED__

WINRT_EXPORT
@interface WNBUnconstrainedTransferRequestResult : RTObject
@property (readonly) BOOL isUnconstrained;
@end

#endif // __WNBUnconstrainedTransferRequestResult_DEFINED__

// Windows.Networking.BackgroundTransfer.UploadOperation
#ifndef __WNBUploadOperation_DEFINED__
#define __WNBUploadOperation_DEFINED__

WINRT_EXPORT
@interface WNBUploadOperation : RTObject <WNBIBackgroundTransferOperation, WNBIBackgroundTransferOperationPriority>
@property (readonly) WNBBackgroundUploadProgress* progress;
@property (readonly) RTObject<WSIStorageFile>* sourceFile;
@property WNBBackgroundTransferCostPolicy costPolicy;
@property (readonly) NSString* group;
@property (readonly) WFGUID* guid;
@property (readonly) NSString* method;
@property (readonly) WFUri* requestedUri;
@property WNBBackgroundTransferPriority priority;
@property (readonly) WNBBackgroundTransferGroup* transferGroup;
- (void)startAsyncWithSuccess:(void (^)(WNBUploadOperation*))success
                     progress:(void (^)(WNBUploadOperation*))progress
                      failure:(void (^)(NSError*))failure;
- (void)attachAsyncWithSuccess:(void (^)(WNBUploadOperation*))success
                      progress:(void (^)(WNBUploadOperation*))progress
                       failure:(void (^)(NSError*))failure;
- (RTObject<WSSIInputStream>*)getResultStreamAt:(uint64_t)position;
- (WNBResponseInformation*)getResponseInformation;
@end

#endif // __WNBUploadOperation_DEFINED__

// Windows.Networking.BackgroundTransfer.BackgroundTransferGroup
#ifndef __WNBBackgroundTransferGroup_DEFINED__
#define __WNBBackgroundTransferGroup_DEFINED__

WINRT_EXPORT
@interface WNBBackgroundTransferGroup : RTObject
+ (WNBBackgroundTransferGroup*)createGroup:(NSString*)name;
@property WNBBackgroundTransferBehavior transferBehavior;
@property (readonly) NSString* name;
@end

#endif // __WNBBackgroundTransferGroup_DEFINED__

// Windows.Networking.BackgroundTransfer.BackgroundTransferContentPart
#ifndef __WNBBackgroundTransferContentPart_DEFINED__
#define __WNBBackgroundTransferContentPart_DEFINED__

WINRT_EXPORT
@interface WNBBackgroundTransferContentPart : RTObject
+ (WNBBackgroundTransferContentPart*)createWithName:(NSString*)name ACTIVATOR;
+ (WNBBackgroundTransferContentPart*)createWithNameAndFileName:(NSString*)name fileName:(NSString*)fileName ACTIVATOR;
+ (instancetype)create ACTIVATOR;
- (void)setHeader:(NSString*)headerName headerValue:(NSString*)headerValue;
- (void)setText:(NSString*)value;
- (void)setFile:(RTObject<WSIStorageFile>*)value;
@end

#endif // __WNBBackgroundTransferContentPart_DEFINED__

// Windows.Networking.BackgroundTransfer.ResponseInformation
#ifndef __WNBResponseInformation_DEFINED__
#define __WNBResponseInformation_DEFINED__

WINRT_EXPORT
@interface WNBResponseInformation : RTObject
@property (readonly) WFUri* actualUri;
@property (readonly) NSDictionary* /*String, String*/ headers;
@property (readonly) BOOL isResumable;
@property (readonly) unsigned statusCode;
@end

#endif // __WNBResponseInformation_DEFINED__

// Windows.Networking.BackgroundTransfer.BackgroundDownloader
#ifndef __WNBBackgroundDownloader_DEFINED__
#define __WNBBackgroundDownloader_DEFINED__

WINRT_EXPORT
@interface WNBBackgroundDownloader : RTObject <WNBIBackgroundTransferBase>
+ (void)getCurrentDownloadsForTransferGroupAsync:(WNBBackgroundTransferGroup*)group
                                         success:(void (^)(id<NSFastEnumeration> /*WNBDownloadOperation*/))success
                                         failure:(void (^)(NSError*))failure;
+ (void)requestUnconstrainedDownloadsAsync:(id<NSFastEnumeration> /*WNBDownloadOperation*/)operations
                                   success:(void (^)(WNBUnconstrainedTransferRequestResult*))success
                                   failure:(void (^)(NSError*))failure;
+ (void)getCurrentDownloadsAsyncWithSuccess:(void (^)(id<NSFastEnumeration> /*WNBDownloadOperation*/))success
                                    failure:(void (^)(NSError*))failure;
+ (void)getCurrentDownloadsForGroupAsync:(NSString*)group
                                 success:(void (^)(id<NSFastEnumeration> /*WNBDownloadOperation*/))success
                                 failure:(void (^)(NSError*))failure;
+ (instancetype)create ACTIVATOR;
@property (copy) WSCPasswordCredential* serverCredential;
@property (copy) WSCPasswordCredential* proxyCredential;
@property (copy) NSString* method;
@property (copy) NSString* group;
@property WNBBackgroundTransferCostPolicy costPolicy;
@property (copy) WNBBackgroundTransferGroup* transferGroup;
@property (copy) WUNToastNotification* successToastNotification;
@property (copy) WUNTileNotification* successTileNotification;
@property (copy) WUNToastNotification* failureToastNotification;
@property (copy) WUNTileNotification* failureTileNotification;
- (WNBDownloadOperation*)createDownload:(WFUri*)uri resultFile:(RTObject<WSIStorageFile>*)resultFile;
- (WNBDownloadOperation*)createDownloadFromFile:(WFUri*)uri
                                     resultFile:(RTObject<WSIStorageFile>*)resultFile
                                requestBodyFile:(RTObject<WSIStorageFile>*)requestBodyFile;
- (void)createDownloadAsync:(WFUri*)uri
                 resultFile:(RTObject<WSIStorageFile>*)resultFile
          requestBodyStream:(RTObject<WSSIInputStream>*)requestBodyStream
                    success:(void (^)(WNBDownloadOperation*))success
                    failure:(void (^)(NSError*))failure;
- (void)setRequestHeader:(NSString*)headerName headerValue:(NSString*)headerValue;
@end

#endif // __WNBBackgroundDownloader_DEFINED__

// Windows.Networking.BackgroundTransfer.BackgroundUploader
#ifndef __WNBBackgroundUploader_DEFINED__
#define __WNBBackgroundUploader_DEFINED__

WINRT_EXPORT
@interface WNBBackgroundUploader : RTObject <WNBIBackgroundTransferBase>
+ (void)getCurrentUploadsForTransferGroupAsync:(WNBBackgroundTransferGroup*)group
                                       success:(void (^)(id<NSFastEnumeration> /*WNBUploadOperation*/))success
                                       failure:(void (^)(NSError*))failure;
+ (void)requestUnconstrainedUploadsAsync:(id<NSFastEnumeration> /*WNBUploadOperation*/)operations
                                 success:(void (^)(WNBUnconstrainedTransferRequestResult*))success
                                 failure:(void (^)(NSError*))failure;
+ (void)getCurrentUploadsAsyncWithSuccess:(void (^)(id<NSFastEnumeration> /*WNBUploadOperation*/))success
                                  failure:(void (^)(NSError*))failure;
+ (void)getCurrentUploadsForGroupAsync:(NSString*)group
                               success:(void (^)(id<NSFastEnumeration> /*WNBUploadOperation*/))success
                               failure:(void (^)(NSError*))failure;
+ (instancetype)create ACTIVATOR;
@property (copy) WNBBackgroundTransferGroup* transferGroup;
@property (copy) WUNToastNotification* successToastNotification;
@property (copy) WUNTileNotification* successTileNotification;
@property (copy) WUNToastNotification* failureToastNotification;
@property (copy) WUNTileNotification* failureTileNotification;
@property (copy) WSCPasswordCredential* serverCredential;
@property (copy) WSCPasswordCredential* proxyCredential;
@property (copy) NSString* method;
@property (copy) NSString* group;
@property WNBBackgroundTransferCostPolicy costPolicy;
- (WNBUploadOperation*)createUpload:(WFUri*)uri sourceFile:(RTObject<WSIStorageFile>*)sourceFile;
- (void)createUploadFromStreamAsync:(WFUri*)uri
                       sourceStream:(RTObject<WSSIInputStream>*)sourceStream
                            success:(void (^)(WNBUploadOperation*))success
                            failure:(void (^)(NSError*))failure;
- (void)createUploadWithFormDataAndAutoBoundaryAsync:(WFUri*)uri
                                               parts:(id<NSFastEnumeration> /*WNBBackgroundTransferContentPart*/)parts
                                             success:(void (^)(WNBUploadOperation*))success
                                             failure:(void (^)(NSError*))failure;
- (void)createUploadWithSubTypeAsync:(WFUri*)uri
                               parts:(id<NSFastEnumeration> /*WNBBackgroundTransferContentPart*/)parts
                             subType:(NSString*)subType
                             success:(void (^)(WNBUploadOperation*))success
                             failure:(void (^)(NSError*))failure;
- (void)createUploadWithSubTypeAndBoundaryAsync:(WFUri*)uri
                                          parts:(id<NSFastEnumeration> /*WNBBackgroundTransferContentPart*/)parts
                                        subType:(NSString*)subType
                                       boundary:(NSString*)boundary
                                        success:(void (^)(WNBUploadOperation*))success
                                        failure:(void (^)(NSError*))failure;
- (void)setRequestHeader:(NSString*)headerName headerValue:(NSString*)headerValue;
@end

#endif // __WNBBackgroundUploader_DEFINED__

// Windows.Networking.BackgroundTransfer.BackgroundTransferError
#ifndef __WNBBackgroundTransferError_DEFINED__
#define __WNBBackgroundTransferError_DEFINED__

WINRT_EXPORT
@interface WNBBackgroundTransferError : RTObject
+ (WWWebErrorStatus)getStatus:(int)hresult;
@end

#endif // __WNBBackgroundTransferError_DEFINED__

// Windows.Networking.BackgroundTransfer.ContentPrefetcher
#ifndef __WNBContentPrefetcher_DEFINED__
#define __WNBContentPrefetcher_DEFINED__

WINRT_EXPORT
@interface WNBContentPrefetcher : RTObject
+ (WFDateTime*)lastSuccessfulPrefetchTime;
+ (WFUri*)indirectContentUri;
+ (void)setIndirectContentUri:(WFUri*)value;
+ (id<NSFastEnumeration> /*WFUri*/)contentUris;
@end

#endif // __WNBContentPrefetcher_DEFINED__
