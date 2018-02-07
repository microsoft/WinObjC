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

// WindowsMediaCaptureFrames.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
#define OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsMediaCaptureDevicesCoreMediaPropertiesDevicesCorePlaybackProtection.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WMCFMediaFrameSourceGroup, WMCFMediaFrameSource, WMCFMediaFrameReader, WMCFMultiSourceMediaFrameReader, WMCFMediaFrameSourceInfo, WMCFMediaFrameSourceController, WMCFMediaFrameFormat, WMCFMediaFrameArrivedEventArgs, WMCFMediaFrameReference, WMCFMultiSourceMediaFrameArrivedEventArgs, WMCFMultiSourceMediaFrameReference, WMCFMediaFrameSourceGetPropertyResult, WMCFVideoMediaFrameFormat, WMCFDepthMediaFrameFormat, WMCFBufferMediaFrame, WMCFVideoMediaFrame, WMCFInfraredMediaFrame, WMCFDepthMediaFrame;
@protocol WMCFIMediaFrameSourceGroup, WMCFIMediaFrameSourceGroupStatics, WMCFIMediaFrameSourceInfo, WMCFIMediaFrameSource, WMCFIMediaFrameArrivedEventArgs, WMCFIMediaFrameReader, WMCFIMediaFrameReader2, WMCFIMultiSourceMediaFrameArrivedEventArgs, WMCFIMultiSourceMediaFrameReader, WMCFIMultiSourceMediaFrameReader2, WMCFIMediaFrameSourceController, WMCFIMediaFrameSourceController2, WMCFIMediaFrameSourceGetPropertyResult, WMCFIMediaFrameFormat, WMCFIVideoMediaFrameFormat, WMCFIMediaFrameReference, WMCFIMultiSourceMediaFrameReference, WMCFIBufferMediaFrame, WMCFIVideoMediaFrame, WMCFIInfraredMediaFrame, WMCFIDepthMediaFrame, WMCFIDepthMediaFrame2, WMCFIDepthMediaFrameFormat;

// Windows.Media.Capture.Frames.MediaFrameReaderStartStatus
enum _WMCFMediaFrameReaderStartStatus {
    WMCFMediaFrameReaderStartStatusSuccess = 0,
    WMCFMediaFrameReaderStartStatusUnknownFailure = 1,
    WMCFMediaFrameReaderStartStatusDeviceNotAvailable = 2,
    WMCFMediaFrameReaderStartStatusOutputFormatNotSupported = 3,
    WMCFMediaFrameReaderStartStatusExclusiveControlNotAvailable = 4,
};
typedef unsigned WMCFMediaFrameReaderStartStatus;

// Windows.Media.Capture.Frames.MediaFrameSourceSetPropertyStatus
enum _WMCFMediaFrameSourceSetPropertyStatus {
    WMCFMediaFrameSourceSetPropertyStatusSuccess = 0,
    WMCFMediaFrameSourceSetPropertyStatusUnknownFailure = 1,
    WMCFMediaFrameSourceSetPropertyStatusNotSupported = 2,
    WMCFMediaFrameSourceSetPropertyStatusInvalidValue = 3,
    WMCFMediaFrameSourceSetPropertyStatusDeviceNotAvailable = 4,
    WMCFMediaFrameSourceSetPropertyStatusNotInControl = 5,
};
typedef unsigned WMCFMediaFrameSourceSetPropertyStatus;

// Windows.Media.Capture.Frames.MediaFrameSourceGetPropertyStatus
enum _WMCFMediaFrameSourceGetPropertyStatus {
    WMCFMediaFrameSourceGetPropertyStatusSuccess = 0,
    WMCFMediaFrameSourceGetPropertyStatusUnknownFailure = 1,
    WMCFMediaFrameSourceGetPropertyStatusNotSupported = 2,
    WMCFMediaFrameSourceGetPropertyStatusDeviceNotAvailable = 3,
    WMCFMediaFrameSourceGetPropertyStatusMaxPropertyValueSizeTooSmall = 4,
    WMCFMediaFrameSourceGetPropertyStatusMaxPropertyValueSizeRequired = 5,
};
typedef unsigned WMCFMediaFrameSourceGetPropertyStatus;

// Windows.Media.Capture.Frames.MediaFrameSourceKind
enum _WMCFMediaFrameSourceKind {
    WMCFMediaFrameSourceKindCustom = 0,
    WMCFMediaFrameSourceKindColor = 1,
    WMCFMediaFrameSourceKindInfrared = 2,
    WMCFMediaFrameSourceKindDepth = 3,
};
typedef unsigned WMCFMediaFrameSourceKind;

// Windows.Media.Capture.Frames.MultiSourceMediaFrameReaderStartStatus
enum _WMCFMultiSourceMediaFrameReaderStartStatus {
    WMCFMultiSourceMediaFrameReaderStartStatusSuccess = 0,
    WMCFMultiSourceMediaFrameReaderStartStatusNotSupported = 1,
    WMCFMultiSourceMediaFrameReaderStartStatusInsufficientResources = 2,
    WMCFMultiSourceMediaFrameReaderStartStatusDeviceNotAvailable = 3,
    WMCFMultiSourceMediaFrameReaderStartStatusUnknownFailure = 4,
};
typedef unsigned WMCFMultiSourceMediaFrameReaderStartStatus;

// Windows.Media.Capture.Frames.MediaFrameReaderAcquisitionMode
enum _WMCFMediaFrameReaderAcquisitionMode {
    WMCFMediaFrameReaderAcquisitionModeRealtime = 0,
    WMCFMediaFrameReaderAcquisitionModeBuffered = 1,
};
typedef unsigned WMCFMediaFrameReaderAcquisitionMode;

#include "WindowsMediaCapture.h"
#include "WindowsMediaDevicesCore.h"
#include "WindowsDevicesEnumeration.h"
#include "WindowsMediaDevices.h"
#include "WindowsPerceptionSpatial.h"
#include "WindowsFoundation.h"
#include "WindowsMediaMediaProperties.h"
#include "WindowsStorageStreams.h"
#include "WindowsGraphicsImaging.h"
#include "WindowsGraphicsDirectXDirect3D11.h"
#include "WindowsMedia.h"

#import <Foundation/Foundation.h>

// Windows.Media.Capture.Frames.MediaFrameSourceGroup
#ifndef __WMCFMediaFrameSourceGroup_DEFINED__
#define __WMCFMediaFrameSourceGroup_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCFMediaFrameSourceGroup : RTObject
+ (void)findAllAsyncWithSuccess:(void (^)(NSArray* /* WMCFMediaFrameSourceGroup* */))success failure:(void (^)(NSError*))failure;
+ (void)fromIdAsync:(NSString *)id success:(void (^)(WMCFMediaFrameSourceGroup*))success failure:(void (^)(NSError*))failure;
+ (NSString *)getDeviceSelector;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * displayName;
@property (readonly) NSString * id;
@property (readonly) NSArray* /* WMCFMediaFrameSourceInfo* */ sourceInfos;
@end

#endif // __WMCFMediaFrameSourceGroup_DEFINED__

// Windows.Media.Capture.Frames.MediaFrameSource
#ifndef __WMCFMediaFrameSource_DEFINED__
#define __WMCFMediaFrameSource_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCFMediaFrameSource : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMCFMediaFrameSourceController* controller;
@property (readonly) WMCFMediaFrameFormat* currentFormat;
@property (readonly) WMCFMediaFrameSourceInfo* info;
@property (readonly) NSArray* /* WMCFMediaFrameFormat* */ supportedFormats;
- (EventRegistrationToken)addFormatChangedEvent:(void(^)(WMCFMediaFrameSource*, RTObject*))del;
- (void)removeFormatChangedEvent:(EventRegistrationToken)tok;
- (RTObject<WFIAsyncAction>*)setFormatAsync:(WMCFMediaFrameFormat*)format;
- (WMDCCameraIntrinsics*)tryGetCameraIntrinsics:(WMCFMediaFrameFormat*)format;
@end

#endif // __WMCFMediaFrameSource_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.Media.Capture.Frames.MediaFrameReader
#ifndef __WMCFMediaFrameReader_DEFINED__
#define __WMCFMediaFrameReader_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCFMediaFrameReader : RTObject <WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WMCFMediaFrameReaderAcquisitionMode acquisitionMode;
- (EventRegistrationToken)addFrameArrivedEvent:(void(^)(WMCFMediaFrameReader*, WMCFMediaFrameArrivedEventArgs*))del;
- (void)removeFrameArrivedEvent:(EventRegistrationToken)tok;
- (WMCFMediaFrameReference*)tryAcquireLatestFrame;
- (void)startAsyncWithSuccess:(void (^)(WMCFMediaFrameReaderStartStatus))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)stopAsync;
- (void)close;
@end

#endif // __WMCFMediaFrameReader_DEFINED__

// Windows.Media.Capture.Frames.MultiSourceMediaFrameReader
#ifndef __WMCFMultiSourceMediaFrameReader_DEFINED__
#define __WMCFMultiSourceMediaFrameReader_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCFMultiSourceMediaFrameReader : RTObject <WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WMCFMediaFrameReaderAcquisitionMode acquisitionMode;
- (EventRegistrationToken)addFrameArrivedEvent:(void(^)(WMCFMultiSourceMediaFrameReader*, WMCFMultiSourceMediaFrameArrivedEventArgs*))del;
- (void)removeFrameArrivedEvent:(EventRegistrationToken)tok;
- (WMCFMultiSourceMediaFrameReference*)tryAcquireLatestFrame;
- (void)startAsyncWithSuccess:(void (^)(WMCFMultiSourceMediaFrameReaderStartStatus))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)stopAsync;
- (void)close;
@end

#endif // __WMCFMultiSourceMediaFrameReader_DEFINED__

// Windows.Media.Capture.Frames.MediaFrameSourceInfo
#ifndef __WMCFMediaFrameSourceInfo_DEFINED__
#define __WMCFMediaFrameSourceInfo_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCFMediaFrameSourceInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WPSSpatialCoordinateSystem* coordinateSystem;
@property (readonly) WDEDeviceInformation* deviceInformation;
@property (readonly) NSString * id;
@property (readonly) WMCMediaStreamType mediaStreamType;
@property (readonly) NSDictionary* /* WFGUID*, RTObject* */ properties;
@property (readonly) WMCFMediaFrameSourceGroup* sourceGroup;
@property (readonly) WMCFMediaFrameSourceKind sourceKind;
@end

#endif // __WMCFMediaFrameSourceInfo_DEFINED__

// Windows.Media.Capture.Frames.MediaFrameSourceController
#ifndef __WMCFMediaFrameSourceController_DEFINED__
#define __WMCFMediaFrameSourceController_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCFMediaFrameSourceController : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMDVideoDeviceController* videoDeviceController;
- (void)getPropertyAsync:(NSString *)propertyId success:(void (^)(WMCFMediaFrameSourceGetPropertyResult*))success failure:(void (^)(NSError*))failure;
- (void)setPropertyAsync:(NSString *)propertyId propertyValue:(RTObject*)propertyValue success:(void (^)(WMCFMediaFrameSourceSetPropertyStatus))success failure:(void (^)(NSError*))failure;
- (void)getPropertyByExtendedIdAsync:(NSArray* /* uint8_t */)extendedPropertyId maxPropertyValueSize:(id /* unsigned int */)maxPropertyValueSize success:(void (^)(WMCFMediaFrameSourceGetPropertyResult*))success failure:(void (^)(NSError*))failure;
- (void)setPropertyByExtendedIdAsync:(NSArray* /* uint8_t */)extendedPropertyId propertyValue:(NSArray* /* uint8_t */)propertyValue success:(void (^)(WMCFMediaFrameSourceSetPropertyStatus))success failure:(void (^)(NSError*))failure;
@end

#endif // __WMCFMediaFrameSourceController_DEFINED__

// Windows.Media.Capture.Frames.MediaFrameFormat
#ifndef __WMCFMediaFrameFormat_DEFINED__
#define __WMCFMediaFrameFormat_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCFMediaFrameFormat : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMMMediaRatio* frameRate;
@property (readonly) NSString * majorType;
@property (readonly) NSDictionary* /* WFGUID*, RTObject* */ properties;
@property (readonly) NSString * subtype;
@property (readonly) WMCFVideoMediaFrameFormat* videoFormat;
@end

#endif // __WMCFMediaFrameFormat_DEFINED__

// Windows.Media.Capture.Frames.MediaFrameArrivedEventArgs
#ifndef __WMCFMediaFrameArrivedEventArgs_DEFINED__
#define __WMCFMediaFrameArrivedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCFMediaFrameArrivedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WMCFMediaFrameArrivedEventArgs_DEFINED__

// Windows.Media.Capture.Frames.MediaFrameReference
#ifndef __WMCFMediaFrameReference_DEFINED__
#define __WMCFMediaFrameReference_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCFMediaFrameReference : RTObject <WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMCFBufferMediaFrame* bufferMediaFrame;
@property (readonly) WPSSpatialCoordinateSystem* coordinateSystem;
@property (readonly) WFTimeSpan* duration;
@property (readonly) WMCFMediaFrameFormat* format;
@property (readonly) NSDictionary* /* WFGUID*, RTObject* */ properties;
@property (readonly) WMCFMediaFrameSourceKind sourceKind;
@property (readonly) id /* WFTimeSpan* */ systemRelativeTime;
@property (readonly) WMCFVideoMediaFrame* videoMediaFrame;
- (void)close;
@end

#endif // __WMCFMediaFrameReference_DEFINED__

// Windows.Media.Capture.Frames.MultiSourceMediaFrameArrivedEventArgs
#ifndef __WMCFMultiSourceMediaFrameArrivedEventArgs_DEFINED__
#define __WMCFMultiSourceMediaFrameArrivedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCFMultiSourceMediaFrameArrivedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WMCFMultiSourceMediaFrameArrivedEventArgs_DEFINED__

// Windows.Media.Capture.Frames.MultiSourceMediaFrameReference
#ifndef __WMCFMultiSourceMediaFrameReference_DEFINED__
#define __WMCFMultiSourceMediaFrameReference_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCFMultiSourceMediaFrameReference : RTObject <WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WMCFMediaFrameReference*)tryGetFrameReferenceBySourceId:(NSString *)sourceId;
- (void)close;
@end

#endif // __WMCFMultiSourceMediaFrameReference_DEFINED__

// Windows.Media.Capture.Frames.MediaFrameSourceGetPropertyResult
#ifndef __WMCFMediaFrameSourceGetPropertyResult_DEFINED__
#define __WMCFMediaFrameSourceGetPropertyResult_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCFMediaFrameSourceGetPropertyResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMCFMediaFrameSourceGetPropertyStatus status;
@property (readonly) RTObject* value;
@end

#endif // __WMCFMediaFrameSourceGetPropertyResult_DEFINED__

// Windows.Media.Capture.Frames.VideoMediaFrameFormat
#ifndef __WMCFVideoMediaFrameFormat_DEFINED__
#define __WMCFVideoMediaFrameFormat_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCFVideoMediaFrameFormat : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMCFDepthMediaFrameFormat* depthFormat;
@property (readonly) unsigned int height;
@property (readonly) WMCFMediaFrameFormat* mediaFrameFormat;
@property (readonly) unsigned int width;
@end

#endif // __WMCFVideoMediaFrameFormat_DEFINED__

// Windows.Media.Capture.Frames.DepthMediaFrameFormat
#ifndef __WMCFDepthMediaFrameFormat_DEFINED__
#define __WMCFDepthMediaFrameFormat_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCFDepthMediaFrameFormat : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) double depthScaleInMeters;
@property (readonly) WMCFVideoMediaFrameFormat* videoFormat;
@end

#endif // __WMCFDepthMediaFrameFormat_DEFINED__

// Windows.Media.Capture.Frames.BufferMediaFrame
#ifndef __WMCFBufferMediaFrame_DEFINED__
#define __WMCFBufferMediaFrame_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCFBufferMediaFrame : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject<WSSIBuffer>* buffer;
@property (readonly) WMCFMediaFrameReference* frameReference;
@end

#endif // __WMCFBufferMediaFrame_DEFINED__

// Windows.Media.Capture.Frames.VideoMediaFrame
#ifndef __WMCFVideoMediaFrame_DEFINED__
#define __WMCFVideoMediaFrame_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCFVideoMediaFrame : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMDCCameraIntrinsics* cameraIntrinsics;
@property (readonly) WMCFDepthMediaFrame* depthMediaFrame;
@property (readonly) RTObject<WGDDIDirect3DSurface>* direct3DSurface;
@property (readonly) WMCFMediaFrameReference* frameReference;
@property (readonly) WMCFInfraredMediaFrame* infraredMediaFrame;
@property (readonly) WGISoftwareBitmap* softwareBitmap;
@property (readonly) WMCFVideoMediaFrameFormat* videoFormat;
- (WMVideoFrame*)getVideoFrame;
@end

#endif // __WMCFVideoMediaFrame_DEFINED__

// Windows.Media.Capture.Frames.InfraredMediaFrame
#ifndef __WMCFInfraredMediaFrame_DEFINED__
#define __WMCFInfraredMediaFrame_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCFInfraredMediaFrame : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMCFMediaFrameReference* frameReference;
@property (readonly) BOOL isIlluminated;
@property (readonly) WMCFVideoMediaFrame* videoMediaFrame;
@end

#endif // __WMCFInfraredMediaFrame_DEFINED__

// Windows.Media.Capture.Frames.DepthMediaFrame
#ifndef __WMCFDepthMediaFrame_DEFINED__
#define __WMCFDepthMediaFrame_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCFDepthMediaFrame : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMCFDepthMediaFrameFormat* depthFormat;
@property (readonly) WMCFMediaFrameReference* frameReference;
@property (readonly) WMCFVideoMediaFrame* videoMediaFrame;
@property (readonly) unsigned int maxReliableDepth;
@property (readonly) unsigned int minReliableDepth;
- (WMDCDepthCorrelatedCoordinateMapper*)tryCreateCoordinateMapper:(WMDCCameraIntrinsics*)cameraIntrinsics coordinateSystem:(WPSSpatialCoordinateSystem*)coordinateSystem;
@end

#endif // __WMCFDepthMediaFrame_DEFINED__

