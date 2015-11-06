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

// WindowsStorageProvider.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WSPCachedFileUpdaterUI, WSPFileUpdateRequestedEventArgs, WSPFileUpdateRequest, WSPFileUpdateRequestDeferral, WSPCachedFileUpdater;
@protocol WSPICachedFileUpdaterUI
, WSPIFileUpdateRequestedEventArgs, WSPIFileUpdateRequest, WSPIFileUpdateRequestDeferral, WSPICachedFileUpdaterUI2, WSPIFileUpdateRequest2,
    WSPICachedFileUpdaterStatics;

// Windows.Storage.Provider.CachedFileTarget
enum _WSPCachedFileTarget {
    WSPCachedFileTargetLocal = 0,
    WSPCachedFileTargetRemote = 1,
};
typedef unsigned WSPCachedFileTarget;

// Windows.Storage.Provider.UIStatus
enum _WSPUIStatus {
    WSPUIStatusUnavailable = 0,
    WSPUIStatusHidden = 1,
    WSPUIStatusVisible = 2,
    WSPUIStatusComplete = 3,
};
typedef unsigned WSPUIStatus;

// Windows.Storage.Provider.FileUpdateStatus
enum _WSPFileUpdateStatus {
    WSPFileUpdateStatusIncomplete = 0,
    WSPFileUpdateStatusComplete = 1,
    WSPFileUpdateStatusUserInputNeeded = 2,
    WSPFileUpdateStatusCurrentlyUnavailable = 3,
    WSPFileUpdateStatusFailed = 4,
    WSPFileUpdateStatusCompleteAndRenamed = 5,
};
typedef unsigned WSPFileUpdateStatus;

// Windows.Storage.Provider.CachedFileOptions
enum _WSPCachedFileOptions {
    WSPCachedFileOptionsNone = 0,
    WSPCachedFileOptionsRequireUpdateOnAccess = 1,
    WSPCachedFileOptionsUseCachedFileWhenOffline = 2,
    WSPCachedFileOptionsDenyAccessWhenOffline = 4,
};
typedef unsigned WSPCachedFileOptions;

// Windows.Storage.Provider.ReadActivationMode
enum _WSPReadActivationMode {
    WSPReadActivationModeNotNeeded = 0,
    WSPReadActivationModeBeforeAccess = 1,
};
typedef unsigned WSPReadActivationMode;

// Windows.Storage.Provider.WriteActivationMode
enum _WSPWriteActivationMode {
    WSPWriteActivationModeReadOnly = 0,
    WSPWriteActivationModeNotNeeded = 1,
    WSPWriteActivationModeAfterWrite = 2,
};
typedef unsigned WSPWriteActivationMode;

#include "WindowsFoundation.h"
#include "WindowsStorage.h"

#import <Foundation/Foundation.h>

// Windows.Storage.Provider.CachedFileUpdaterUI
#ifndef __WSPCachedFileUpdaterUI_DEFINED__
#define __WSPCachedFileUpdaterUI_DEFINED__

WINRT_EXPORT
@interface WSPCachedFileUpdaterUI : RTObject
@property (copy) NSString* title;
@property (readonly) WSPUIStatus uIStatus;
@property (readonly) WSPCachedFileTarget updateTarget;
@property (readonly) WSPFileUpdateRequest* updateRequest;
- (EventRegistrationToken)addFileUpdateRequestedEvent:(void (^)(WSPCachedFileUpdaterUI*, WSPFileUpdateRequestedEventArgs*))del;
- (void)removeFileUpdateRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUIRequestedEvent:(void (^)(WSPCachedFileUpdaterUI*, RTObject*))del;
- (void)removeUIRequestedEvent:(EventRegistrationToken)tok;
- (WSPFileUpdateRequestDeferral*)getDeferral;
@end

#endif // __WSPCachedFileUpdaterUI_DEFINED__

// Windows.Storage.Provider.FileUpdateRequestedEventArgs
#ifndef __WSPFileUpdateRequestedEventArgs_DEFINED__
#define __WSPFileUpdateRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WSPFileUpdateRequestedEventArgs : RTObject
@property (readonly) WSPFileUpdateRequest* request;
@end

#endif // __WSPFileUpdateRequestedEventArgs_DEFINED__

// Windows.Storage.Provider.FileUpdateRequest
#ifndef __WSPFileUpdateRequest_DEFINED__
#define __WSPFileUpdateRequest_DEFINED__

WINRT_EXPORT
@interface WSPFileUpdateRequest : RTObject
@property WSPFileUpdateStatus status;
@property (readonly) NSString* contentId;
@property (readonly) WSStorageFile* file;
@property (copy) NSString* userInputNeededMessage;
- (WSPFileUpdateRequestDeferral*)getDeferral;
- (void)updateLocalFile:(RTObject<WSIStorageFile>*)value;
@end

#endif // __WSPFileUpdateRequest_DEFINED__

// Windows.Storage.Provider.FileUpdateRequestDeferral
#ifndef __WSPFileUpdateRequestDeferral_DEFINED__
#define __WSPFileUpdateRequestDeferral_DEFINED__

WINRT_EXPORT
@interface WSPFileUpdateRequestDeferral : RTObject
- (void)complete;
@end

#endif // __WSPFileUpdateRequestDeferral_DEFINED__

// Windows.Storage.Provider.CachedFileUpdater
#ifndef __WSPCachedFileUpdater_DEFINED__
#define __WSPCachedFileUpdater_DEFINED__

WINRT_EXPORT
@interface WSPCachedFileUpdater : RTObject
+ (void)setUpdateInformation:(RTObject<WSIStorageFile>*)file
                   contentId:(NSString*)contentId
                    readMode:(WSPReadActivationMode)readMode
                   writeMode:(WSPWriteActivationMode)writeMode
                     options:(WSPCachedFileOptions)options;
@end

#endif // __WSPCachedFileUpdater_DEFINED__
