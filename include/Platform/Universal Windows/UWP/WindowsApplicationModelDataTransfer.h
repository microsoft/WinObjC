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

// WindowsApplicationModelDataTransfer.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WADStandardDataFormats, WADDataPackagePropertySetView, WADDataPackagePropertySet, WADDataProviderDeferral, WADDataProviderRequest,
    WADOperationCompletedEventArgs, WADDataPackageView, WADDataPackage, WADHtmlFormatHelper, WADClipboard, WADDataRequestDeferral,
    WADDataRequest, WADDataRequestedEventArgs, WADTargetApplicationChosenEventArgs, WADDataTransferManager, WADSharedStorageAccessManager;
@protocol WADIStandardDataFormatsStatics
, WADIStandardDataFormatsStatics2, WADIDataPackagePropertySetView, WADIDataPackagePropertySetView2, WADIDataPackagePropertySetView3,
    WADIDataPackagePropertySet, WADIDataPackagePropertySet2, WADIDataPackagePropertySet3, WADIDataProviderDeferral, WADIDataProviderRequest,
    WADIOperationCompletedEventArgs, WADIDataPackageView, WADIDataPackageView2, WADIDataPackageView3, WADIDataPackage, WADIDataPackage2,
    WADIHtmlFormatHelperStatics, WADIClipboardStatics, WADIDataRequestDeferral, WADIDataRequest, WADIDataRequestedEventArgs,
    WADITargetApplicationChosenEventArgs, WADIDataTransferManager, WADIDataTransferManagerStatics, WADISharedStorageAccessManagerStatics;

// Windows.ApplicationModel.DataTransfer.DataPackageOperation
enum _WADDataPackageOperation {
    WADDataPackageOperationNone = 0,
    WADDataPackageOperationCopy = 1,
    WADDataPackageOperationMove = 2,
    WADDataPackageOperationLink = 4,
};
typedef unsigned WADDataPackageOperation;

#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"
#include "WindowsFoundation.h"
#include "WindowsUI.h"
#include "WindowsStorage.h"
#include "WindowsSecurityEnterpriseData.h"
// Windows.ApplicationModel.DataTransfer.DataProviderHandler
#ifndef __WADDataProviderHandler__DEFINED
#define __WADDataProviderHandler__DEFINED
typedef void (^WADDataProviderHandler)(WADDataProviderRequest* request);
#endif // __WADDataProviderHandler__DEFINED

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.DataTransfer.DataProviderHandler
#ifndef __WADDataProviderHandler__DEFINED
#define __WADDataProviderHandler__DEFINED
typedef void (^WADDataProviderHandler)(WADDataProviderRequest* request);
#endif // __WADDataProviderHandler__DEFINED

// Windows.ApplicationModel.DataTransfer.StandardDataFormats
#ifndef __WADStandardDataFormats_DEFINED__
#define __WADStandardDataFormats_DEFINED__

WINRT_EXPORT
@interface WADStandardDataFormats : RTObject
+ (NSString*)bitmap;
+ (NSString*)html;
+ (NSString*)rtf;
+ (NSString*)storageItems;
+ (NSString*)text;
+ (NSString*)uri;
+ (NSString*)applicationLink;
+ (NSString*)webLink;
@end

#endif // __WADStandardDataFormats_DEFINED__

// Windows.ApplicationModel.DataTransfer.DataPackagePropertySetView
#ifndef __WADDataPackagePropertySetView_DEFINED__
#define __WADDataPackagePropertySetView_DEFINED__

WINRT_EXPORT
@interface WADDataPackagePropertySetView : RTObject
@property (readonly) WFUri* applicationListingUri;
@property (readonly) NSString* applicationName;
@property (readonly) NSString* description;
@property (readonly) NSArray* fileTypes;
@property (readonly) WSSRandomAccessStreamReference* thumbnail;
@property (readonly) NSString* title;
@property (readonly) WFUri* contentSourceApplicationLink;
@property (readonly) WFUri* contentSourceWebLink;
@property (readonly) WUColor* logoBackgroundColor;
@property (readonly) NSString* packageFamilyName;
@property (readonly) RTObject<WSSIRandomAccessStreamReference>* square30x30Logo;
@property (readonly) NSString* enterpriseId;
@property (readonly) unsigned int size;
- (id)objectForKey:(id)key;
- (NSArray*)allKeys;
- (NSArray*)allKeysForObject:(id)obj;
- (NSArray*)allValues;
- (id)keyEnumerator;
- (unsigned int)count;

@end

#endif // __WADDataPackagePropertySetView_DEFINED__

// Windows.ApplicationModel.DataTransfer.DataPackagePropertySet
#ifndef __WADDataPackagePropertySet_DEFINED__
#define __WADDataPackagePropertySet_DEFINED__

WINRT_EXPORT
@interface WADDataPackagePropertySet : RTObject
@property (copy) RTObject<WSSIRandomAccessStreamReference>* thumbnail;
@property (copy) NSString* title;
@property (copy) NSString* description;
@property (copy) NSString* applicationName;
@property (copy) WFUri* applicationListingUri;
@property (readonly) NSMutableArray* fileTypes;
@property (copy) RTObject<WSSIRandomAccessStreamReference>* square30x30Logo;
@property (copy) NSString* packageFamilyName;
@property (copy) WUColor* logoBackgroundColor;
@property (copy) WFUri* contentSourceWebLink;
@property (copy) WFUri* contentSourceApplicationLink;
@property (copy) NSString* enterpriseId;
@property (readonly) unsigned int size;
- (id)objectForKey:(id)key;
- (NSArray*)allKeys;
- (NSArray*)allKeysForObject:(id)obj;
- (NSArray*)allValues;
- (id)keyEnumerator;
- (unsigned int)count;

- (void)setObject:(id)obj forKey:(id)key;
- (void)setObject:(id)object forKeyedSubscript:(id)key;
- (void)removeObjectForKey:(id)key;
- (void)removeAllObjects;
- (void)removeObjectsForKeys:(NSArray*)keys;
- (void)addEntriesFromDictionary:(NSDictionary*)otherDict;
- (void)addEntriesFromDictionaryNoReplace:(NSDictionary*)otherDict;
- (void)setDictionary:(NSDictionary*)dict;
@end

#endif // __WADDataPackagePropertySet_DEFINED__

// Windows.ApplicationModel.DataTransfer.DataProviderDeferral
#ifndef __WADDataProviderDeferral_DEFINED__
#define __WADDataProviderDeferral_DEFINED__

WINRT_EXPORT
@interface WADDataProviderDeferral : RTObject
- (void)complete;
@end

#endif // __WADDataProviderDeferral_DEFINED__

// Windows.ApplicationModel.DataTransfer.DataProviderRequest
#ifndef __WADDataProviderRequest_DEFINED__
#define __WADDataProviderRequest_DEFINED__

WINRT_EXPORT
@interface WADDataProviderRequest : RTObject
@property (readonly) WFDateTime* deadline;
@property (readonly) NSString* formatId;
- (WADDataProviderDeferral*)getDeferral;
- (void)setData:(RTObject*)value;
@end

#endif // __WADDataProviderRequest_DEFINED__

// Windows.ApplicationModel.DataTransfer.OperationCompletedEventArgs
#ifndef __WADOperationCompletedEventArgs_DEFINED__
#define __WADOperationCompletedEventArgs_DEFINED__

WINRT_EXPORT
@interface WADOperationCompletedEventArgs : RTObject
@property (readonly) WADDataPackageOperation operation;
@end

#endif // __WADOperationCompletedEventArgs_DEFINED__

// Windows.ApplicationModel.DataTransfer.DataPackageView
#ifndef __WADDataPackageView_DEFINED__
#define __WADDataPackageView_DEFINED__

WINRT_EXPORT
@interface WADDataPackageView : RTObject
@property (readonly) NSArray* availableFormats;
@property (readonly) WADDataPackagePropertySetView* properties;
@property (readonly) WADDataPackageOperation requestedOperation;
- (void)reportOperationCompleted:(WADDataPackageOperation)value;
- (BOOL)contains:(NSString*)formatId;
- (void)getDataAsync:(NSString*)formatId success:(void (^)(RTObject*))success failure:(void (^)(NSError*))failure;
- (void)getTextAsyncWithSuccess:(void (^)(NSString*))success failure:(void (^)(NSError*))failure;
- (void)getCustomTextAsync:(NSString*)formatId success:(void (^)(NSString*))success failure:(void (^)(NSError*))failure;
- (void)getUriAsyncWithSuccess:(void (^)(WFUri*))success failure:(void (^)(NSError*))failure;
- (void)getHtmlFormatAsyncWithSuccess:(void (^)(NSString*))success failure:(void (^)(NSError*))failure;
- (void)getResourceMapAsyncWithSuccess:(void (^)(NSDictionary*))success failure:(void (^)(NSError*))failure;
- (void)getRtfAsyncWithSuccess:(void (^)(NSString*))success failure:(void (^)(NSError*))failure;
- (void)getBitmapAsyncWithSuccess:(void (^)(WSSRandomAccessStreamReference*))success failure:(void (^)(NSError*))failure;
- (void)getStorageItemsAsyncWithSuccess:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
- (void)getApplicationLinkAsyncWithSuccess:(void (^)(WFUri*))success failure:(void (^)(NSError*))failure;
- (void)getWebLinkAsyncWithSuccess:(void (^)(WFUri*))success failure:(void (^)(NSError*))failure;
- (void)requestAccessAsyncWithSuccess:(void (^)(WSEProtectionPolicyEvaluationResult))success failure:(void (^)(NSError*))failure;
- (void)requestAccessWithEnterpriseIdAsync:(NSString*)enterpriseId
                                   success:(void (^)(WSEProtectionPolicyEvaluationResult))success
                                   failure:(void (^)(NSError*))failure;
- (WSEProtectionPolicyEvaluationResult)unlockAndAssumeEnterpriseIdentity;
@end

#endif // __WADDataPackageView_DEFINED__

// Windows.ApplicationModel.DataTransfer.DataPackage
#ifndef __WADDataPackage_DEFINED__
#define __WADDataPackage_DEFINED__

WINRT_EXPORT
@interface WADDataPackage : RTObject
+ (instancetype)create ACTIVATOR;
@property WADDataPackageOperation requestedOperation;
@property (readonly) WADDataPackagePropertySet* properties;
@property (readonly) NSMutableDictionary* resourceMap;
- (EventRegistrationToken)addDestroyedEvent:(void (^)(WADDataPackage*, RTObject*))del;
- (void)removeDestroyedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOperationCompletedEvent:(void (^)(WADDataPackage*, WADOperationCompletedEventArgs*))del;
- (void)removeOperationCompletedEvent:(EventRegistrationToken)tok;
- (WADDataPackageView*)getView;
- (void)setData:(NSString*)formatId value:(RTObject*)value;
- (void)setDataProvider:(NSString*)formatId delayRenderer:(WADDataProviderHandler)delayRenderer;
- (void)setText:(NSString*)value;
- (void)setUri:(WFUri*)value;
- (void)setHtmlFormat:(NSString*)value;
- (void)setRtf:(NSString*)value;
- (void)setBitmap:(WSSRandomAccessStreamReference*)value;
- (void)setStorageItemsReadOnly:(id<NSFastEnumeration> /* RTObject<WSIStorageItem>* */)value;
- (void)setStorageItems:(id<NSFastEnumeration> /* RTObject<WSIStorageItem>* */)value readOnly:(BOOL)readOnly;
- (void)setApplicationLink:(WFUri*)value;
- (void)setWebLink:(WFUri*)value;
@end

#endif // __WADDataPackage_DEFINED__

// Windows.ApplicationModel.DataTransfer.HtmlFormatHelper
#ifndef __WADHtmlFormatHelper_DEFINED__
#define __WADHtmlFormatHelper_DEFINED__

WINRT_EXPORT
@interface WADHtmlFormatHelper : RTObject
+ (NSString*)getStaticFragment:(NSString*)htmlFormat;
+ (NSString*)createHtmlFormat:(NSString*)htmlFragment;
@end

#endif // __WADHtmlFormatHelper_DEFINED__

// Windows.ApplicationModel.DataTransfer.Clipboard
#ifndef __WADClipboard_DEFINED__
#define __WADClipboard_DEFINED__

WINRT_EXPORT
@interface WADClipboard : RTObject
+ (WADDataPackageView*)getContent;
+ (void)setContent:(WADDataPackage*)content;
+ (void)flush;
+ (void)clear;
+ (EventRegistrationToken)addContentChangedEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removeContentChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WADClipboard_DEFINED__

// Windows.ApplicationModel.DataTransfer.DataRequestDeferral
#ifndef __WADDataRequestDeferral_DEFINED__
#define __WADDataRequestDeferral_DEFINED__

WINRT_EXPORT
@interface WADDataRequestDeferral : RTObject
- (void)complete;
@end

#endif // __WADDataRequestDeferral_DEFINED__

// Windows.ApplicationModel.DataTransfer.DataRequest
#ifndef __WADDataRequest_DEFINED__
#define __WADDataRequest_DEFINED__

WINRT_EXPORT
@interface WADDataRequest : RTObject
@property (copy) WADDataPackage* data;
@property (readonly) WFDateTime* deadline;
- (void)failWithDisplayText:(NSString*)value;
- (WADDataRequestDeferral*)getDeferral;
@end

#endif // __WADDataRequest_DEFINED__

// Windows.ApplicationModel.DataTransfer.DataRequestedEventArgs
#ifndef __WADDataRequestedEventArgs_DEFINED__
#define __WADDataRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WADDataRequestedEventArgs : RTObject
@property (readonly) WADDataRequest* request;
@end

#endif // __WADDataRequestedEventArgs_DEFINED__

// Windows.ApplicationModel.DataTransfer.TargetApplicationChosenEventArgs
#ifndef __WADTargetApplicationChosenEventArgs_DEFINED__
#define __WADTargetApplicationChosenEventArgs_DEFINED__

WINRT_EXPORT
@interface WADTargetApplicationChosenEventArgs : RTObject
@property (readonly) NSString* applicationName;
@end

#endif // __WADTargetApplicationChosenEventArgs_DEFINED__

// Windows.ApplicationModel.DataTransfer.DataTransferManager
#ifndef __WADDataTransferManager_DEFINED__
#define __WADDataTransferManager_DEFINED__

WINRT_EXPORT
@interface WADDataTransferManager : RTObject
+ (void)showShareUI;
+ (WADDataTransferManager*)getForCurrentView;
- (EventRegistrationToken)addDataRequestedEvent:(void (^)(WADDataTransferManager*, WADDataRequestedEventArgs*))del;
- (void)removeDataRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTargetApplicationChosenEvent:(void (^)(WADDataTransferManager*, WADTargetApplicationChosenEventArgs*))del;
- (void)removeTargetApplicationChosenEvent:(EventRegistrationToken)tok;
@end

#endif // __WADDataTransferManager_DEFINED__

// Windows.ApplicationModel.DataTransfer.SharedStorageAccessManager
#ifndef __WADSharedStorageAccessManager_DEFINED__
#define __WADSharedStorageAccessManager_DEFINED__

WINRT_EXPORT
@interface WADSharedStorageAccessManager : RTObject
+ (NSString*)addFile:(RTObject<WSIStorageFile>*)file;
+ (void)redeemTokenForFileAsync:(NSString*)token success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
+ (void)removeFile:(NSString*)token;
@end

#endif // __WADSharedStorageAccessManager_DEFINED__
