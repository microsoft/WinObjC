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

// WindowsStoragePickersProvider.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WSPPFileRemovedEventArgs, WSPPFileOpenPickerUI, WSPPPickerClosingEventArgs, WSPPPickerClosingOperation, WSPPPickerClosingDeferral,
    WSPPFileSavePickerUI, WSPPTargetFileRequestedEventArgs, WSPPTargetFileRequest, WSPPTargetFileRequestDeferral;
@protocol WSPPIFileRemovedEventArgs
, WSPPIFileOpenPickerUI, WSPPIPickerClosingEventArgs, WSPPIPickerClosingOperation, WSPPIPickerClosingDeferral, WSPPIFileSavePickerUI,
    WSPPITargetFileRequestedEventArgs, WSPPITargetFileRequest, WSPPITargetFileRequestDeferral;

// Windows.Storage.Pickers.Provider.AddFileResult
enum _WSPPAddFileResult {
    WSPPAddFileResultAdded = 0,
    WSPPAddFileResultAlreadyAdded = 1,
    WSPPAddFileResultNotAllowed = 2,
    WSPPAddFileResultUnavailable = 3,
};
typedef unsigned WSPPAddFileResult;

// Windows.Storage.Pickers.Provider.FileSelectionMode
enum _WSPPFileSelectionMode {
    WSPPFileSelectionModeSingle = 0,
    WSPPFileSelectionModeMultiple = 1,
};
typedef unsigned WSPPFileSelectionMode;

// Windows.Storage.Pickers.Provider.SetFileNameResult
enum _WSPPSetFileNameResult {
    WSPPSetFileNameResultSucceeded = 0,
    WSPPSetFileNameResultNotAllowed = 1,
    WSPPSetFileNameResultUnavailable = 2,
};
typedef unsigned WSPPSetFileNameResult;

#include "WindowsStorage.h"
#include "WindowsFoundationCollections.h"
#include "WindowsFoundation.h"

// Windows.Storage.Pickers.Provider.FileRemovedEventArgs
#ifndef __WSPPFileRemovedEventArgs_DEFINED__
#define __WSPPFileRemovedEventArgs_DEFINED__

WINRT_EXPORT
@interface WSPPFileRemovedEventArgs : RTObject
@property (readonly) NSString* id;
@end

#endif // __WSPPFileRemovedEventArgs_DEFINED__

// Windows.Storage.Pickers.Provider.FileOpenPickerUI
#ifndef __WSPPFileOpenPickerUI_DEFINED__
#define __WSPPFileOpenPickerUI_DEFINED__

WINRT_EXPORT
@interface WSPPFileOpenPickerUI : RTObject
@property (copy) NSString* title;
@property (readonly) id<NSFastEnumeration> /*String*/ allowedFileTypes;
@property (readonly) WSPPFileSelectionMode selectionMode;
@property (readonly) NSString* settingsIdentifier;
- (EventRegistrationToken)addClosingEvent:(void (^)(WSPPFileOpenPickerUI*, WSPPPickerClosingEventArgs*))del;
- (void)removeClosingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addFileRemovedEvent:(void (^)(WSPPFileOpenPickerUI*, WSPPFileRemovedEventArgs*))del;
- (void)removeFileRemovedEvent:(EventRegistrationToken)tok;
- (WSPPAddFileResult)addFile:(NSString*)id file:(RTObject<WSIStorageFile>*)file;
- (void)removeFile:(NSString*)id;
- (BOOL)containsFile:(NSString*)id;
- (BOOL)canAddFile:(RTObject<WSIStorageFile>*)file;
@end

#endif // __WSPPFileOpenPickerUI_DEFINED__

// Windows.Storage.Pickers.Provider.PickerClosingEventArgs
#ifndef __WSPPPickerClosingEventArgs_DEFINED__
#define __WSPPPickerClosingEventArgs_DEFINED__

WINRT_EXPORT
@interface WSPPPickerClosingEventArgs : RTObject
@property (readonly) WSPPPickerClosingOperation* closingOperation;
@property (readonly) BOOL isCanceled;
@end

#endif // __WSPPPickerClosingEventArgs_DEFINED__

// Windows.Storage.Pickers.Provider.PickerClosingOperation
#ifndef __WSPPPickerClosingOperation_DEFINED__
#define __WSPPPickerClosingOperation_DEFINED__

WINRT_EXPORT
@interface WSPPPickerClosingOperation : RTObject
@property (readonly) WFDateTime* deadline;
- (WSPPPickerClosingDeferral*)getDeferral;
@end

#endif // __WSPPPickerClosingOperation_DEFINED__

// Windows.Storage.Pickers.Provider.PickerClosingDeferral
#ifndef __WSPPPickerClosingDeferral_DEFINED__
#define __WSPPPickerClosingDeferral_DEFINED__

WINRT_EXPORT
@interface WSPPPickerClosingDeferral : RTObject
- (void)complete;
@end

#endif // __WSPPPickerClosingDeferral_DEFINED__

// Windows.Storage.Pickers.Provider.FileSavePickerUI
#ifndef __WSPPFileSavePickerUI_DEFINED__
#define __WSPPFileSavePickerUI_DEFINED__

WINRT_EXPORT
@interface WSPPFileSavePickerUI : RTObject
@property (copy) NSString* title;
@property (readonly) id<NSFastEnumeration> /*String*/ allowedFileTypes;
@property (readonly) NSString* fileName;
@property (readonly) NSString* settingsIdentifier;
- (EventRegistrationToken)addFileNameChangedEvent:(void (^)(WSPPFileSavePickerUI*, RTObject*))del;
- (void)removeFileNameChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTargetFileRequestedEvent:(void (^)(WSPPFileSavePickerUI*, WSPPTargetFileRequestedEventArgs*))del;
- (void)removeTargetFileRequestedEvent:(EventRegistrationToken)tok;
- (WSPPSetFileNameResult)trySetFileName:(NSString*)value;
@end

#endif // __WSPPFileSavePickerUI_DEFINED__

// Windows.Storage.Pickers.Provider.TargetFileRequestedEventArgs
#ifndef __WSPPTargetFileRequestedEventArgs_DEFINED__
#define __WSPPTargetFileRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WSPPTargetFileRequestedEventArgs : RTObject
@property (readonly) WSPPTargetFileRequest* request;
@end

#endif // __WSPPTargetFileRequestedEventArgs_DEFINED__

// Windows.Storage.Pickers.Provider.TargetFileRequest
#ifndef __WSPPTargetFileRequest_DEFINED__
#define __WSPPTargetFileRequest_DEFINED__

WINRT_EXPORT
@interface WSPPTargetFileRequest : RTObject
@property (copy) RTObject<WSIStorageFile>* targetFile;
- (WSPPTargetFileRequestDeferral*)getDeferral;
@end

#endif // __WSPPTargetFileRequest_DEFINED__

// Windows.Storage.Pickers.Provider.TargetFileRequestDeferral
#ifndef __WSPPTargetFileRequestDeferral_DEFINED__
#define __WSPPTargetFileRequestDeferral_DEFINED__

WINRT_EXPORT
@interface WSPPTargetFileRequestDeferral : RTObject
- (void)complete;
@end

#endif // __WSPPTargetFileRequestDeferral_DEFINED__
