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

// WindowsApplicationModelCalls.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WACPhoneCallHistoryEntryAddress, WACPhoneCallHistoryEntry, WACPhoneCallHistoryEntryReader, WACPhoneCallHistoryEntryQueryOptions,
    WACPhoneCallHistoryStore, WACPhoneCallHistoryManager;
@protocol WACIPhoneCallHistoryEntry
, WACIPhoneCallHistoryEntryAddress, WACIPhoneCallHistoryEntryAddressFactory, WACIPhoneCallHistoryEntryQueryOptions,
    WACIPhoneCallHistoryEntryReader, WACIPhoneCallHistoryStore, WACIPhoneCallHistoryManagerStatics;

// Windows.ApplicationModel.Calls.PhoneCallHistoryEntryOtherAppReadAccess
enum _WACPhoneCallHistoryEntryOtherAppReadAccess {
    WACPhoneCallHistoryEntryOtherAppReadAccessFull = 0,
    WACPhoneCallHistoryEntryOtherAppReadAccessSystemOnly = 1,
};
typedef unsigned WACPhoneCallHistoryEntryOtherAppReadAccess;

// Windows.ApplicationModel.Calls.PhoneCallHistoryEntryMedia
enum _WACPhoneCallHistoryEntryMedia {
    WACPhoneCallHistoryEntryMediaAudio = 0,
    WACPhoneCallHistoryEntryMediaVideo = 1,
};
typedef unsigned WACPhoneCallHistoryEntryMedia;

// Windows.ApplicationModel.Calls.PhoneCallHistoryEntryRawAddressKind
enum _WACPhoneCallHistoryEntryRawAddressKind {
    WACPhoneCallHistoryEntryRawAddressKindPhoneNumber = 0,
    WACPhoneCallHistoryEntryRawAddressKindCustom = 1,
};
typedef unsigned WACPhoneCallHistoryEntryRawAddressKind;

// Windows.ApplicationModel.Calls.PhoneCallHistoryEntryQueryDesiredMedia
enum _WACPhoneCallHistoryEntryQueryDesiredMedia {
    WACPhoneCallHistoryEntryQueryDesiredMediaNone = 0,
    WACPhoneCallHistoryEntryQueryDesiredMediaAudio = 1,
    WACPhoneCallHistoryEntryQueryDesiredMediaVideo = 2,
    WACPhoneCallHistoryEntryQueryDesiredMediaAll = -1,
};
typedef unsigned WACPhoneCallHistoryEntryQueryDesiredMedia;

// Windows.ApplicationModel.Calls.PhoneCallHistoryStoreAccessType
enum _WACPhoneCallHistoryStoreAccessType {
    WACPhoneCallHistoryStoreAccessTypeAppEntriesReadWrite = 0,
    WACPhoneCallHistoryStoreAccessTypeAllEntriesLimitedReadWrite = 1,
    WACPhoneCallHistoryStoreAccessTypeAllEntriesReadWrite = 2,
};
typedef unsigned WACPhoneCallHistoryStoreAccessType;

// Windows.ApplicationModel.Calls.PhoneCallHistorySourceIdKind
enum _WACPhoneCallHistorySourceIdKind {
    WACPhoneCallHistorySourceIdKindCellularPhoneLineId = 0,
    WACPhoneCallHistorySourceIdKindPackageFamilyName = 1,
};
typedef unsigned WACPhoneCallHistorySourceIdKind;

#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Calls.PhoneCallHistoryEntryAddress
#ifndef __WACPhoneCallHistoryEntryAddress_DEFINED__
#define __WACPhoneCallHistoryEntryAddress_DEFINED__

WINRT_EXPORT
@interface WACPhoneCallHistoryEntryAddress : RTObject
+ (WACPhoneCallHistoryEntryAddress*)create:(NSString*)rawAddress
                            rawAddressKind:(WACPhoneCallHistoryEntryRawAddressKind)rawAddressKind ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property WACPhoneCallHistoryEntryRawAddressKind rawAddressKind;
@property (copy) NSString* rawAddress;
@property (copy) NSString* displayName;
@property (copy) NSString* contactId;
@end

#endif // __WACPhoneCallHistoryEntryAddress_DEFINED__

// Windows.ApplicationModel.Calls.PhoneCallHistoryEntry
#ifndef __WACPhoneCallHistoryEntry_DEFINED__
#define __WACPhoneCallHistoryEntry_DEFINED__

WINRT_EXPORT
@interface WACPhoneCallHistoryEntry : RTObject
+ (instancetype)create ACTIVATOR;
@property WACPhoneCallHistoryEntryMedia media;
@property BOOL isMissed;
@property BOOL isIncoming;
@property BOOL isCallerIdBlocked;
@property BOOL isSeen;
@property (copy) id duration;
@property BOOL isEmergency;
@property BOOL isSuppressed;
@property (copy) WFDateTime* startTime;
@property WACPhoneCallHistorySourceIdKind sourceIdKind;
@property (copy) WACPhoneCallHistoryEntryAddress* address;
@property (copy) NSString* sourceId;
@property (copy) NSString* remoteId;
@property WACPhoneCallHistoryEntryOtherAppReadAccess otherAppReadAccess;
@property BOOL isRinging;
@property BOOL isVoicemail;
@property (readonly) NSString* id;
@property (readonly) NSString* sourceDisplayName;
@end

#endif // __WACPhoneCallHistoryEntry_DEFINED__

// Windows.ApplicationModel.Calls.PhoneCallHistoryEntryReader
#ifndef __WACPhoneCallHistoryEntryReader_DEFINED__
#define __WACPhoneCallHistoryEntryReader_DEFINED__

WINRT_EXPORT
@interface WACPhoneCallHistoryEntryReader : RTObject
- (void)readBatchAsyncWithSuccess:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WACPhoneCallHistoryEntryReader_DEFINED__

// Windows.ApplicationModel.Calls.PhoneCallHistoryEntryQueryOptions
#ifndef __WACPhoneCallHistoryEntryQueryOptions_DEFINED__
#define __WACPhoneCallHistoryEntryQueryOptions_DEFINED__

WINRT_EXPORT
@interface WACPhoneCallHistoryEntryQueryOptions : RTObject
+ (instancetype)create ACTIVATOR;
@property WACPhoneCallHistoryEntryQueryDesiredMedia desiredMedia;
@property (readonly) NSMutableArray* sourceIds;
@end

#endif // __WACPhoneCallHistoryEntryQueryOptions_DEFINED__

// Windows.ApplicationModel.Calls.PhoneCallHistoryStore
#ifndef __WACPhoneCallHistoryStore_DEFINED__
#define __WACPhoneCallHistoryStore_DEFINED__

WINRT_EXPORT
@interface WACPhoneCallHistoryStore : RTObject
- (void)getEntryAsync:(NSString*)callHistoryEntryId
              success:(void (^)(WACPhoneCallHistoryEntry*))success
              failure:(void (^)(NSError*))failure;
- (WACPhoneCallHistoryEntryReader*)getEntryReader;
- (WACPhoneCallHistoryEntryReader*)getEntryReaderWithOptions:(WACPhoneCallHistoryEntryQueryOptions*)queryOptions;
- (RTObject<WFIAsyncAction>*)saveEntryAsync:(WACPhoneCallHistoryEntry*)callHistoryEntry;
- (RTObject<WFIAsyncAction>*)deleteEntryAsync:(WACPhoneCallHistoryEntry*)callHistoryEntry;
- (RTObject<WFIAsyncAction>*)deleteEntriesAsync:(id<NSFastEnumeration> /* WACPhoneCallHistoryEntry* */)callHistoryEntries;
- (RTObject<WFIAsyncAction>*)markEntryAsSeenAsync:(WACPhoneCallHistoryEntry*)callHistoryEntry;
- (RTObject<WFIAsyncAction>*)markEntriesAsSeenAsync:(id<NSFastEnumeration> /* WACPhoneCallHistoryEntry* */)callHistoryEntries;
- (void)getUnseenCountAsyncWithSuccess:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)markAllAsSeenAsync;
- (void)getSourcesUnseenCountAsync:(id<NSFastEnumeration> /* NSString * */)sourceIds
                           success:(void (^)(unsigned int))success
                           failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)markSourcesAsSeenAsync:(id<NSFastEnumeration> /* NSString * */)sourceIds;
@end

#endif // __WACPhoneCallHistoryStore_DEFINED__

// Windows.ApplicationModel.Calls.PhoneCallHistoryManager
#ifndef __WACPhoneCallHistoryManager_DEFINED__
#define __WACPhoneCallHistoryManager_DEFINED__

WINRT_EXPORT
@interface WACPhoneCallHistoryManager : RTObject
+ (void)requestStoreAsync:(WACPhoneCallHistoryStoreAccessType)accessType
                  success:(void (^)(WACPhoneCallHistoryStore*))success
                  failure:(void (^)(NSError*))failure;
@end

#endif // __WACPhoneCallHistoryManager_DEFINED__
