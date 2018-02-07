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

// WindowsMediaAppRecording.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSMEDIAAPPRECORDINGEXPORT
#define OBJCUWPWINDOWSMEDIAAPPRECORDINGEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsMediaAppRecording.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WMAAppRecordingStatus, WMAAppRecordingResult, WMAAppRecordingSaveScreenshotResult, WMAAppRecordingManager, WMAAppRecordingStatusDetails, WMAAppRecordingSavedScreenshotInfo;
@protocol WMAIAppRecordingManager, WMAIAppRecordingManagerStatics, WMAIAppRecordingStatus, WMAIAppRecordingStatusDetails, WMAIAppRecordingResult, WMAIAppRecordingSaveScreenshotResult, WMAIAppRecordingSavedScreenshotInfo;

// Windows.Media.AppRecording.AppRecordingSaveScreenshotOption
enum _WMAAppRecordingSaveScreenshotOption {
    WMAAppRecordingSaveScreenshotOptionNone = 0,
    WMAAppRecordingSaveScreenshotOptionHdrContentVisible = 1,
};
typedef unsigned WMAAppRecordingSaveScreenshotOption;

#include "WindowsStorage.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Media.AppRecording.AppRecordingStatus
#ifndef __WMAAppRecordingStatus_DEFINED__
#define __WMAAppRecordingStatus_DEFINED__

OBJCUWPWINDOWSMEDIAAPPRECORDINGEXPORT
@interface WMAAppRecordingStatus : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL canRecord;
@property (readonly) BOOL canRecordTimeSpan;
@property (readonly) WMAAppRecordingStatusDetails* details;
@property (readonly) WFTimeSpan* historicalBufferDuration;
@end

#endif // __WMAAppRecordingStatus_DEFINED__

// Windows.Media.AppRecording.AppRecordingResult
#ifndef __WMAAppRecordingResult_DEFINED__
#define __WMAAppRecordingResult_DEFINED__

OBJCUWPWINDOWSMEDIAAPPRECORDINGEXPORT
@interface WMAAppRecordingResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFTimeSpan* duration;
@property (readonly) HRESULT extendedError;
@property (readonly) BOOL isFileTruncated;
@property (readonly) BOOL succeeded;
@end

#endif // __WMAAppRecordingResult_DEFINED__

// Windows.Media.AppRecording.AppRecordingSaveScreenshotResult
#ifndef __WMAAppRecordingSaveScreenshotResult_DEFINED__
#define __WMAAppRecordingSaveScreenshotResult_DEFINED__

OBJCUWPWINDOWSMEDIAAPPRECORDINGEXPORT
@interface WMAAppRecordingSaveScreenshotResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) HRESULT extendedError;
@property (readonly) NSArray* /* WMAAppRecordingSavedScreenshotInfo* */ savedScreenshotInfos;
@property (readonly) BOOL succeeded;
@end

#endif // __WMAAppRecordingSaveScreenshotResult_DEFINED__

// Windows.Media.AppRecording.AppRecordingManager
#ifndef __WMAAppRecordingManager_DEFINED__
#define __WMAAppRecordingManager_DEFINED__

OBJCUWPWINDOWSMEDIAAPPRECORDINGEXPORT
@interface WMAAppRecordingManager : RTObject
+ (WMAAppRecordingManager*)getDefault;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* NSString * */ supportedScreenshotMediaEncodingSubtypes;
- (WMAAppRecordingStatus*)getStatus;
- (void)startRecordingToFileAsync:(WSStorageFile*)file success:(void (^)(WMAAppRecordingResult*))success failure:(void (^)(NSError*))failure;
- (void)recordTimeSpanToFileAsync:(WFDateTime*)startTime duration:(WFTimeSpan*)duration file:(WSStorageFile*)file success:(void (^)(WMAAppRecordingResult*))success failure:(void (^)(NSError*))failure;
- (void)saveScreenshotToFilesAsync:(WSStorageFolder*)folder filenamePrefix:(NSString *)filenamePrefix option:(WMAAppRecordingSaveScreenshotOption)option requestedFormats:(id<NSFastEnumeration> /* NSString * */)requestedFormats success:(void (^)(WMAAppRecordingSaveScreenshotResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WMAAppRecordingManager_DEFINED__

// Windows.Media.AppRecording.AppRecordingStatusDetails
#ifndef __WMAAppRecordingStatusDetails_DEFINED__
#define __WMAAppRecordingStatusDetails_DEFINED__

OBJCUWPWINDOWSMEDIAAPPRECORDINGEXPORT
@interface WMAAppRecordingStatusDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isAnyAppBroadcasting;
@property (readonly) BOOL isAppInactive;
@property (readonly) BOOL isBlockedForApp;
@property (readonly) BOOL isCaptureResourceUnavailable;
@property (readonly) BOOL isDisabledBySystem;
@property (readonly) BOOL isDisabledByUser;
@property (readonly) BOOL isGameStreamInProgress;
@property (readonly) BOOL isGpuConstrained;
@property (readonly) BOOL isTimeSpanRecordingDisabled;
@end

#endif // __WMAAppRecordingStatusDetails_DEFINED__

// Windows.Media.AppRecording.AppRecordingSavedScreenshotInfo
#ifndef __WMAAppRecordingSavedScreenshotInfo_DEFINED__
#define __WMAAppRecordingSavedScreenshotInfo_DEFINED__

OBJCUWPWINDOWSMEDIAAPPRECORDINGEXPORT
@interface WMAAppRecordingSavedScreenshotInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSStorageFile* file;
@property (readonly) NSString * mediaEncodingSubtype;
@end

#endif // __WMAAppRecordingSavedScreenshotInfo_DEFINED__

