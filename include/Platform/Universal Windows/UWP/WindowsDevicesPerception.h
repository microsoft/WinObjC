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

// WindowsDevicesPerception.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WDPPerceptionColorFrameSourceWatcher, WDPPerceptionColorFrameSourceAddedEventArgs, WDPPerceptionColorFrameSourceRemovedEventArgs,
    WDPPerceptionDepthFrameSourceWatcher, WDPPerceptionDepthFrameSourceAddedEventArgs, WDPPerceptionDepthFrameSourceRemovedEventArgs,
    WDPPerceptionInfraredFrameSourceWatcher, WDPPerceptionInfraredFrameSourceAddedEventArgs,
    WDPPerceptionInfraredFrameSourceRemovedEventArgs, WDPPerceptionColorFrameSource, WDPPerceptionDepthFrameSource,
    WDPPerceptionInfraredFrameSource, WDPPerceptionControlSession, WDPPerceptionFrameSourcePropertyChangeResult,
    WDPPerceptionFrameSourcePropertiesChangedEventArgs, WDPPerceptionVideoProfile, WDPPerceptionDepthCorrelatedCameraIntrinsics,
    WDPPerceptionDepthCorrelatedCoordinateMapper, WDPPerceptionColorFrameReader, WDPPerceptionDepthFrameReader,
    WDPPerceptionInfraredFrameReader, WDPPerceptionColorFrameArrivedEventArgs, WDPPerceptionColorFrame,
    WDPPerceptionDepthFrameArrivedEventArgs, WDPPerceptionDepthFrame, WDPPerceptionInfraredFrameArrivedEventArgs,
    WDPPerceptionInfraredFrame, WDPKnownPerceptionFrameSourceProperties, WDPKnownPerceptionVideoFrameSourceProperties,
    WDPKnownPerceptionInfraredFrameSourceProperties, WDPKnownPerceptionDepthFrameSourceProperties,
    WDPKnownPerceptionColorFrameSourceProperties, WDPKnownPerceptionVideoProfileProperties, WDPKnownCameraIntrinsicsProperties;
@class RTArray_C_WFNVector3, RTArray_C_WFPoint;
@protocol WDPIPerceptionColorFrameSourceWatcher
, WDPIPerceptionDepthFrameSourceWatcher, WDPIPerceptionInfraredFrameSourceWatcher, WDPIPerceptionColorFrameSourceAddedEventArgs,
    WDPIPerceptionColorFrameSourceRemovedEventArgs, WDPIPerceptionDepthFrameSourceAddedEventArgs,
    WDPIPerceptionDepthFrameSourceRemovedEventArgs, WDPIPerceptionInfraredFrameSourceAddedEventArgs,
    WDPIPerceptionInfraredFrameSourceRemovedEventArgs, WDPIKnownPerceptionFrameSourcePropertiesStatics,
    WDPIKnownPerceptionVideoFrameSourcePropertiesStatics, WDPIKnownPerceptionInfraredFrameSourcePropertiesStatics,
    WDPIKnownPerceptionDepthFrameSourcePropertiesStatics, WDPIKnownPerceptionColorFrameSourcePropertiesStatics,
    WDPIKnownPerceptionVideoProfilePropertiesStatics, WDPIKnownCameraIntrinsicsPropertiesStatics,
    WDPIPerceptionFrameSourcePropertyChangeResult, WDPIPerceptionFrameSourcePropertiesChangedEventArgs,
    WDPIPerceptionInfraredFrameSourceStatics, WDPIPerceptionDepthFrameSourceStatics, WDPIPerceptionColorFrameSourceStatics,
    WDPIPerceptionColorFrameSource, WDPIPerceptionDepthFrameSource, WDPIPerceptionInfraredFrameSource, WDPIPerceptionVideoProfile,
    WDPIPerceptionColorFrameArrivedEventArgs, WDPIPerceptionDepthFrameArrivedEventArgs, WDPIPerceptionInfraredFrameArrivedEventArgs,
    WDPIPerceptionDepthCorrelatedCameraIntrinsics, WDPIPerceptionDepthCorrelatedCoordinateMapper, WDPIPerceptionControlSession,
    WDPIPerceptionColorFrameReader, WDPIPerceptionDepthFrameReader, WDPIPerceptionInfraredFrameReader, WDPIPerceptionColorFrame,
    WDPIPerceptionDepthFrame, WDPIPerceptionInfraredFrame;

// Windows.Devices.Perception.PerceptionFrameSourceAccessStatus
enum _WDPPerceptionFrameSourceAccessStatus {
    WDPPerceptionFrameSourceAccessStatusUnspecified = 0,
    WDPPerceptionFrameSourceAccessStatusAllowed = 1,
    WDPPerceptionFrameSourceAccessStatusDeniedByUser = 2,
    WDPPerceptionFrameSourceAccessStatusDeniedBySystem = 3,
};
typedef unsigned WDPPerceptionFrameSourceAccessStatus;

// Windows.Devices.Perception.PerceptionFrameSourcePropertyChangeStatus
enum _WDPPerceptionFrameSourcePropertyChangeStatus {
    WDPPerceptionFrameSourcePropertyChangeStatusUnknown = 0,
    WDPPerceptionFrameSourcePropertyChangeStatusAccepted = 1,
    WDPPerceptionFrameSourcePropertyChangeStatusLostControl = 2,
    WDPPerceptionFrameSourcePropertyChangeStatusPropertyNotSupported = 3,
    WDPPerceptionFrameSourcePropertyChangeStatusPropertyReadOnly = 4,
    WDPPerceptionFrameSourcePropertyChangeStatusValueOutOfRange = 5,
};
typedef unsigned WDPPerceptionFrameSourcePropertyChangeStatus;

#include "WindowsFoundationCollections.h"
#include "WindowsFoundation.h"
#include "WindowsMedia.h"
#include "WindowsMediaDevicesCore.h"
#include "WindowsDevicesEnumeration.h"
#include "WindowsFoundationNumerics.h"
#include "WindowsGraphicsImaging.h"

#import <Foundation/Foundation.h>

// Windows.Devices.Perception.PerceptionColorFrameSourceWatcher
#ifndef __WDPPerceptionColorFrameSourceWatcher_DEFINED__
#define __WDPPerceptionColorFrameSourceWatcher_DEFINED__

WINRT_EXPORT
@interface WDPPerceptionColorFrameSourceWatcher : RTObject
@property (readonly) WDEDeviceWatcherStatus status;
- (EventRegistrationToken)addEnumerationCompletedEvent:(void (^)(WDPPerceptionColorFrameSourceWatcher*, RTObject*))del;
- (void)removeEnumerationCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSourceAddedEvent:(void (^)(WDPPerceptionColorFrameSourceWatcher*,
                                                        WDPPerceptionColorFrameSourceAddedEventArgs*))del;
- (void)removeSourceAddedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSourceRemovedEvent:(void (^)(WDPPerceptionColorFrameSourceWatcher*,
                                                          WDPPerceptionColorFrameSourceRemovedEventArgs*))del;
- (void)removeSourceRemovedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStoppedEvent:(void (^)(WDPPerceptionColorFrameSourceWatcher*, RTObject*))del;
- (void)removeStoppedEvent:(EventRegistrationToken)tok;
- (void)start;
- (void)stop;
@end

#endif // __WDPPerceptionColorFrameSourceWatcher_DEFINED__

// Windows.Devices.Perception.PerceptionColorFrameSourceAddedEventArgs
#ifndef __WDPPerceptionColorFrameSourceAddedEventArgs_DEFINED__
#define __WDPPerceptionColorFrameSourceAddedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPPerceptionColorFrameSourceAddedEventArgs : RTObject
@property (readonly) WDPPerceptionColorFrameSource* frameSource;
@end

#endif // __WDPPerceptionColorFrameSourceAddedEventArgs_DEFINED__

// Windows.Devices.Perception.PerceptionColorFrameSourceRemovedEventArgs
#ifndef __WDPPerceptionColorFrameSourceRemovedEventArgs_DEFINED__
#define __WDPPerceptionColorFrameSourceRemovedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPPerceptionColorFrameSourceRemovedEventArgs : RTObject
@property (readonly) WDPPerceptionColorFrameSource* frameSource;
@end

#endif // __WDPPerceptionColorFrameSourceRemovedEventArgs_DEFINED__

// Windows.Devices.Perception.PerceptionDepthFrameSourceWatcher
#ifndef __WDPPerceptionDepthFrameSourceWatcher_DEFINED__
#define __WDPPerceptionDepthFrameSourceWatcher_DEFINED__

WINRT_EXPORT
@interface WDPPerceptionDepthFrameSourceWatcher : RTObject
@property (readonly) WDEDeviceWatcherStatus status;
- (EventRegistrationToken)addEnumerationCompletedEvent:(void (^)(WDPPerceptionDepthFrameSourceWatcher*, RTObject*))del;
- (void)removeEnumerationCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSourceAddedEvent:(void (^)(WDPPerceptionDepthFrameSourceWatcher*,
                                                        WDPPerceptionDepthFrameSourceAddedEventArgs*))del;
- (void)removeSourceAddedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSourceRemovedEvent:(void (^)(WDPPerceptionDepthFrameSourceWatcher*,
                                                          WDPPerceptionDepthFrameSourceRemovedEventArgs*))del;
- (void)removeSourceRemovedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStoppedEvent:(void (^)(WDPPerceptionDepthFrameSourceWatcher*, RTObject*))del;
- (void)removeStoppedEvent:(EventRegistrationToken)tok;
- (void)start;
- (void)stop;
@end

#endif // __WDPPerceptionDepthFrameSourceWatcher_DEFINED__

// Windows.Devices.Perception.PerceptionDepthFrameSourceAddedEventArgs
#ifndef __WDPPerceptionDepthFrameSourceAddedEventArgs_DEFINED__
#define __WDPPerceptionDepthFrameSourceAddedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPPerceptionDepthFrameSourceAddedEventArgs : RTObject
@property (readonly) WDPPerceptionDepthFrameSource* frameSource;
@end

#endif // __WDPPerceptionDepthFrameSourceAddedEventArgs_DEFINED__

// Windows.Devices.Perception.PerceptionDepthFrameSourceRemovedEventArgs
#ifndef __WDPPerceptionDepthFrameSourceRemovedEventArgs_DEFINED__
#define __WDPPerceptionDepthFrameSourceRemovedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPPerceptionDepthFrameSourceRemovedEventArgs : RTObject
@property (readonly) WDPPerceptionDepthFrameSource* frameSource;
@end

#endif // __WDPPerceptionDepthFrameSourceRemovedEventArgs_DEFINED__

// Windows.Devices.Perception.PerceptionInfraredFrameSourceWatcher
#ifndef __WDPPerceptionInfraredFrameSourceWatcher_DEFINED__
#define __WDPPerceptionInfraredFrameSourceWatcher_DEFINED__

WINRT_EXPORT
@interface WDPPerceptionInfraredFrameSourceWatcher : RTObject
@property (readonly) WDEDeviceWatcherStatus status;
- (EventRegistrationToken)addEnumerationCompletedEvent:(void (^)(WDPPerceptionInfraredFrameSourceWatcher*, RTObject*))del;
- (void)removeEnumerationCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSourceAddedEvent:(void (^)(WDPPerceptionInfraredFrameSourceWatcher*,
                                                        WDPPerceptionInfraredFrameSourceAddedEventArgs*))del;
- (void)removeSourceAddedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSourceRemovedEvent:(void (^)(WDPPerceptionInfraredFrameSourceWatcher*,
                                                          WDPPerceptionInfraredFrameSourceRemovedEventArgs*))del;
- (void)removeSourceRemovedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStoppedEvent:(void (^)(WDPPerceptionInfraredFrameSourceWatcher*, RTObject*))del;
- (void)removeStoppedEvent:(EventRegistrationToken)tok;
- (void)start;
- (void)stop;
@end

#endif // __WDPPerceptionInfraredFrameSourceWatcher_DEFINED__

// Windows.Devices.Perception.PerceptionInfraredFrameSourceAddedEventArgs
#ifndef __WDPPerceptionInfraredFrameSourceAddedEventArgs_DEFINED__
#define __WDPPerceptionInfraredFrameSourceAddedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPPerceptionInfraredFrameSourceAddedEventArgs : RTObject
@property (readonly) WDPPerceptionInfraredFrameSource* frameSource;
@end

#endif // __WDPPerceptionInfraredFrameSourceAddedEventArgs_DEFINED__

// Windows.Devices.Perception.PerceptionInfraredFrameSourceRemovedEventArgs
#ifndef __WDPPerceptionInfraredFrameSourceRemovedEventArgs_DEFINED__
#define __WDPPerceptionInfraredFrameSourceRemovedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPPerceptionInfraredFrameSourceRemovedEventArgs : RTObject
@property (readonly) WDPPerceptionInfraredFrameSource* frameSource;
@end

#endif // __WDPPerceptionInfraredFrameSourceRemovedEventArgs_DEFINED__

// Windows.Devices.Perception.PerceptionColorFrameSource
#ifndef __WDPPerceptionColorFrameSource_DEFINED__
#define __WDPPerceptionColorFrameSource_DEFINED__

WINRT_EXPORT
@interface WDPPerceptionColorFrameSource : RTObject
+ (WDPPerceptionColorFrameSourceWatcher*)createWatcher;
+ (void)findAllAsyncWithSuccess:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
+ (void)fromIdAsync:(NSString*)id success:(void (^)(WDPPerceptionColorFrameSource*))success failure:(void (^)(NSError*))failure;
+ (void)requestAccessAsyncWithSuccess:(void (^)(WDPPerceptionFrameSourceAccessStatus))success failure:(void (^)(NSError*))failure;
@property (readonly) BOOL active;
@property (readonly) BOOL available;
@property (readonly) NSArray* availableVideoProfiles;
@property (readonly) WMDCCameraIntrinsics* cameraIntrinsics;
@property (readonly) NSString* deviceKind;
@property (readonly) NSString* displayName;
@property (readonly) NSString* id;
@property (readonly) BOOL isControlled;
@property (readonly) NSDictionary* properties;
@property (readonly) NSArray* supportedVideoProfiles;
@property (readonly) WDPPerceptionVideoProfile* videoProfile;
- (EventRegistrationToken)addActiveChangedEvent:(void (^)(WDPPerceptionColorFrameSource*, RTObject*))del;
- (void)removeActiveChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAvailableChangedEvent:(void (^)(WDPPerceptionColorFrameSource*, RTObject*))del;
- (void)removeAvailableChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCameraIntrinsicsChangedEvent:(void (^)(WDPPerceptionColorFrameSource*, RTObject*))del;
- (void)removeCameraIntrinsicsChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPropertiesChangedEvent:(void (^)(WDPPerceptionColorFrameSource*,
                                                              WDPPerceptionFrameSourcePropertiesChangedEventArgs*))del;
- (void)removePropertiesChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVideoProfileChangedEvent:(void (^)(WDPPerceptionColorFrameSource*, RTObject*))del;
- (void)removeVideoProfileChangedEvent:(EventRegistrationToken)tok;
- (WDPPerceptionControlSession*)acquireControlSession;
- (BOOL)canControlIndependentlyFrom:(NSString*)targetId;
- (BOOL)isCorrelatedWith:(NSString*)targetId;
- (BOOL)tryGetTransformTo:(NSString*)targetId result:(WFNMatrix4x4**)result;
- (void)tryGetDepthCorrelatedCameraIntrinsicsAsync:(WDPPerceptionDepthFrameSource*)correlatedDepthFrameSource
                                           success:(void (^)(WDPPerceptionDepthCorrelatedCameraIntrinsics*))success
                                           failure:(void (^)(NSError*))failure;
- (void)tryGetDepthCorrelatedCoordinateMapperAsync:(NSString*)targetSourceId
                        correlatedDepthFrameSource:(WDPPerceptionDepthFrameSource*)correlatedDepthFrameSource
                                           success:(void (^)(WDPPerceptionDepthCorrelatedCoordinateMapper*))success
                                           failure:(void (^)(NSError*))failure;
- (void)trySetVideoProfileAsync:(WDPPerceptionControlSession*)controlSession
                        profile:(WDPPerceptionVideoProfile*)profile
                        success:(void (^)(WDPPerceptionFrameSourcePropertyChangeResult*))success
                        failure:(void (^)(NSError*))failure;
- (WDPPerceptionColorFrameReader*)openReader;
@end

#endif // __WDPPerceptionColorFrameSource_DEFINED__

// Windows.Devices.Perception.PerceptionDepthFrameSource
#ifndef __WDPPerceptionDepthFrameSource_DEFINED__
#define __WDPPerceptionDepthFrameSource_DEFINED__

WINRT_EXPORT
@interface WDPPerceptionDepthFrameSource : RTObject
+ (WDPPerceptionDepthFrameSourceWatcher*)createWatcher;
+ (void)findAllAsyncWithSuccess:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
+ (void)fromIdAsync:(NSString*)id success:(void (^)(WDPPerceptionDepthFrameSource*))success failure:(void (^)(NSError*))failure;
+ (void)requestAccessAsyncWithSuccess:(void (^)(WDPPerceptionFrameSourceAccessStatus))success failure:(void (^)(NSError*))failure;
@property (readonly) BOOL active;
@property (readonly) BOOL available;
@property (readonly) NSArray* availableVideoProfiles;
@property (readonly) WMDCCameraIntrinsics* cameraIntrinsics;
@property (readonly) NSString* deviceKind;
@property (readonly) NSString* displayName;
@property (readonly) NSString* id;
@property (readonly) BOOL isControlled;
@property (readonly) NSDictionary* properties;
@property (readonly) NSArray* supportedVideoProfiles;
@property (readonly) WDPPerceptionVideoProfile* videoProfile;
- (EventRegistrationToken)addActiveChangedEvent:(void (^)(WDPPerceptionDepthFrameSource*, RTObject*))del;
- (void)removeActiveChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAvailableChangedEvent:(void (^)(WDPPerceptionDepthFrameSource*, RTObject*))del;
- (void)removeAvailableChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCameraIntrinsicsChangedEvent:(void (^)(WDPPerceptionDepthFrameSource*, RTObject*))del;
- (void)removeCameraIntrinsicsChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPropertiesChangedEvent:(void (^)(WDPPerceptionDepthFrameSource*,
                                                              WDPPerceptionFrameSourcePropertiesChangedEventArgs*))del;
- (void)removePropertiesChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVideoProfileChangedEvent:(void (^)(WDPPerceptionDepthFrameSource*, RTObject*))del;
- (void)removeVideoProfileChangedEvent:(EventRegistrationToken)tok;
- (WDPPerceptionControlSession*)acquireControlSession;
- (BOOL)canControlIndependentlyFrom:(NSString*)targetId;
- (BOOL)isCorrelatedWith:(NSString*)targetId;
- (BOOL)tryGetTransformTo:(NSString*)targetId result:(WFNMatrix4x4**)result;
- (void)tryGetDepthCorrelatedCameraIntrinsicsAsync:(WDPPerceptionDepthFrameSource*)target
                                           success:(void (^)(WDPPerceptionDepthCorrelatedCameraIntrinsics*))success
                                           failure:(void (^)(NSError*))failure;
- (void)tryGetDepthCorrelatedCoordinateMapperAsync:(NSString*)targetId
                         depthFrameSourceToMapWith:(WDPPerceptionDepthFrameSource*)depthFrameSourceToMapWith
                                           success:(void (^)(WDPPerceptionDepthCorrelatedCoordinateMapper*))success
                                           failure:(void (^)(NSError*))failure;
- (void)trySetVideoProfileAsync:(WDPPerceptionControlSession*)controlSession
                        profile:(WDPPerceptionVideoProfile*)profile
                        success:(void (^)(WDPPerceptionFrameSourcePropertyChangeResult*))success
                        failure:(void (^)(NSError*))failure;
- (WDPPerceptionDepthFrameReader*)openReader;
@end

#endif // __WDPPerceptionDepthFrameSource_DEFINED__

// Windows.Devices.Perception.PerceptionInfraredFrameSource
#ifndef __WDPPerceptionInfraredFrameSource_DEFINED__
#define __WDPPerceptionInfraredFrameSource_DEFINED__

WINRT_EXPORT
@interface WDPPerceptionInfraredFrameSource : RTObject
+ (WDPPerceptionInfraredFrameSourceWatcher*)createWatcher;
+ (void)findAllAsyncWithSuccess:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
+ (void)fromIdAsync:(NSString*)id success:(void (^)(WDPPerceptionInfraredFrameSource*))success failure:(void (^)(NSError*))failure;
+ (void)requestAccessAsyncWithSuccess:(void (^)(WDPPerceptionFrameSourceAccessStatus))success failure:(void (^)(NSError*))failure;
@property (readonly) BOOL active;
@property (readonly) BOOL available;
@property (readonly) NSArray* availableVideoProfiles;
@property (readonly) WMDCCameraIntrinsics* cameraIntrinsics;
@property (readonly) NSString* deviceKind;
@property (readonly) NSString* displayName;
@property (readonly) NSString* id;
@property (readonly) BOOL isControlled;
@property (readonly) NSDictionary* properties;
@property (readonly) NSArray* supportedVideoProfiles;
@property (readonly) WDPPerceptionVideoProfile* videoProfile;
- (EventRegistrationToken)addActiveChangedEvent:(void (^)(WDPPerceptionInfraredFrameSource*, RTObject*))del;
- (void)removeActiveChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAvailableChangedEvent:(void (^)(WDPPerceptionInfraredFrameSource*, RTObject*))del;
- (void)removeAvailableChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCameraIntrinsicsChangedEvent:(void (^)(WDPPerceptionInfraredFrameSource*, RTObject*))del;
- (void)removeCameraIntrinsicsChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPropertiesChangedEvent:(void (^)(WDPPerceptionInfraredFrameSource*,
                                                              WDPPerceptionFrameSourcePropertiesChangedEventArgs*))del;
- (void)removePropertiesChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVideoProfileChangedEvent:(void (^)(WDPPerceptionInfraredFrameSource*, RTObject*))del;
- (void)removeVideoProfileChangedEvent:(EventRegistrationToken)tok;
- (WDPPerceptionControlSession*)acquireControlSession;
- (BOOL)canControlIndependentlyFrom:(NSString*)targetId;
- (BOOL)isCorrelatedWith:(NSString*)targetId;
- (BOOL)tryGetTransformTo:(NSString*)targetId result:(WFNMatrix4x4**)result;
- (void)tryGetDepthCorrelatedCameraIntrinsicsAsync:(WDPPerceptionDepthFrameSource*)target
                                           success:(void (^)(WDPPerceptionDepthCorrelatedCameraIntrinsics*))success
                                           failure:(void (^)(NSError*))failure;
- (void)tryGetDepthCorrelatedCoordinateMapperAsync:(NSString*)targetId
                         depthFrameSourceToMapWith:(WDPPerceptionDepthFrameSource*)depthFrameSourceToMapWith
                                           success:(void (^)(WDPPerceptionDepthCorrelatedCoordinateMapper*))success
                                           failure:(void (^)(NSError*))failure;
- (void)trySetVideoProfileAsync:(WDPPerceptionControlSession*)controlSession
                        profile:(WDPPerceptionVideoProfile*)profile
                        success:(void (^)(WDPPerceptionFrameSourcePropertyChangeResult*))success
                        failure:(void (^)(NSError*))failure;
- (WDPPerceptionInfraredFrameReader*)openReader;
@end

#endif // __WDPPerceptionInfraredFrameSource_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

// Windows.Devices.Perception.PerceptionControlSession
#ifndef __WDPPerceptionControlSession_DEFINED__
#define __WDPPerceptionControlSession_DEFINED__

WINRT_EXPORT
@interface WDPPerceptionControlSession : RTObject <WFIClosable>
- (EventRegistrationToken)addControlLostEvent:(void (^)(WDPPerceptionControlSession*, RTObject*))del;
- (void)removeControlLostEvent:(EventRegistrationToken)tok;
- (void)trySetPropertyAsync:(NSString*)name
                      value:(RTObject*)value
                    success:(void (^)(WDPPerceptionFrameSourcePropertyChangeResult*))success
                    failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WDPPerceptionControlSession_DEFINED__

// Windows.Devices.Perception.PerceptionFrameSourcePropertyChangeResult
#ifndef __WDPPerceptionFrameSourcePropertyChangeResult_DEFINED__
#define __WDPPerceptionFrameSourcePropertyChangeResult_DEFINED__

WINRT_EXPORT
@interface WDPPerceptionFrameSourcePropertyChangeResult : RTObject
@property (readonly) RTObject* newValue;
@property (readonly) WDPPerceptionFrameSourcePropertyChangeStatus status;
@end

#endif // __WDPPerceptionFrameSourcePropertyChangeResult_DEFINED__

// Windows.Devices.Perception.PerceptionFrameSourcePropertiesChangedEventArgs
#ifndef __WDPPerceptionFrameSourcePropertiesChangedEventArgs_DEFINED__
#define __WDPPerceptionFrameSourcePropertiesChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPPerceptionFrameSourcePropertiesChangedEventArgs : RTObject
@property (readonly) WFCCollectionChange collectionChange;
@property (readonly) NSString* key;
@end

#endif // __WDPPerceptionFrameSourcePropertiesChangedEventArgs_DEFINED__

// Windows.Devices.Perception.PerceptionVideoProfile
#ifndef __WDPPerceptionVideoProfile_DEFINED__
#define __WDPPerceptionVideoProfile_DEFINED__

WINRT_EXPORT
@interface WDPPerceptionVideoProfile : RTObject
@property (readonly) WGIBitmapAlphaMode bitmapAlphaMode;
@property (readonly) WGIBitmapPixelFormat bitmapPixelFormat;
@property (readonly) WFTimeSpan* frameDuration;
@property (readonly) int height;
@property (readonly) int width;
- (BOOL)isEqual:(WDPPerceptionVideoProfile*)other;
@end

#endif // __WDPPerceptionVideoProfile_DEFINED__

// Windows.Devices.Perception.PerceptionDepthCorrelatedCameraIntrinsics
#ifndef __WDPPerceptionDepthCorrelatedCameraIntrinsics_DEFINED__
#define __WDPPerceptionDepthCorrelatedCameraIntrinsics_DEFINED__

WINRT_EXPORT
@interface WDPPerceptionDepthCorrelatedCameraIntrinsics : RTObject
- (WFNVector3*)unprojectPixelAtCorrelatedDepth:(WFPoint*)pixelCoordinate depthFrame:(WDPPerceptionDepthFrame*)depthFrame;
- (void)unprojectPixelsAtCorrelatedDepth:(id<NSFastEnumeration> /* WFPoint* */)sourceCoordinates
                              depthFrame:(WDPPerceptionDepthFrame*)depthFrame
                                 results:(RTArray_C_WFNVector3*)results;
- (RTObject<WFIAsyncAction>*)unprojectRegionPixelsAtCorrelatedDepthAsync:(WFRect*)region
                                                              depthFrame:(WDPPerceptionDepthFrame*)depthFrame
                                                                 results:(RTArray_C_WFNVector3*)results;
- (RTObject<WFIAsyncAction>*)unprojectAllPixelsAtCorrelatedDepthAsync:(WDPPerceptionDepthFrame*)depthFrame
                                                              results:(RTArray_C_WFNVector3*)results;
@end

#endif // __WDPPerceptionDepthCorrelatedCameraIntrinsics_DEFINED__

// Windows.Devices.Perception.PerceptionDepthCorrelatedCoordinateMapper
#ifndef __WDPPerceptionDepthCorrelatedCoordinateMapper_DEFINED__
#define __WDPPerceptionDepthCorrelatedCoordinateMapper_DEFINED__

WINRT_EXPORT
@interface WDPPerceptionDepthCorrelatedCoordinateMapper : RTObject
- (WFPoint*)mapPixelToTarget:(WFPoint*)sourcePixelCoordinate depthFrame:(WDPPerceptionDepthFrame*)depthFrame;
- (void)mapPixelsToTarget:(id<NSFastEnumeration> /* WFPoint* */)sourceCoordinates
               depthFrame:(WDPPerceptionDepthFrame*)depthFrame
                  results:(RTArray_C_WFPoint*)results;
- (RTObject<WFIAsyncAction>*)mapRegionOfPixelsToTargetAsync:(WFRect*)region
                                                 depthFrame:(WDPPerceptionDepthFrame*)depthFrame
                                          targetCoordinates:(RTArray_C_WFPoint*)targetCoordinates;
- (RTObject<WFIAsyncAction>*)mapAllPixelsToTargetAsync:(WDPPerceptionDepthFrame*)depthFrame
                                     targetCoordinates:(RTArray_C_WFPoint*)targetCoordinates;
@end

#endif // __WDPPerceptionDepthCorrelatedCoordinateMapper_DEFINED__

// Windows.Devices.Perception.PerceptionColorFrameReader
#ifndef __WDPPerceptionColorFrameReader_DEFINED__
#define __WDPPerceptionColorFrameReader_DEFINED__

WINRT_EXPORT
@interface WDPPerceptionColorFrameReader : RTObject <WFIClosable>
@property BOOL isPaused;
@property (readonly) WDPPerceptionColorFrameSource* source;
- (EventRegistrationToken)addFrameArrivedEvent:(void (^)(WDPPerceptionColorFrameReader*, WDPPerceptionColorFrameArrivedEventArgs*))del;
- (void)removeFrameArrivedEvent:(EventRegistrationToken)tok;
- (WDPPerceptionColorFrame*)tryReadLatestFrame;
- (void)close;
@end

#endif // __WDPPerceptionColorFrameReader_DEFINED__

// Windows.Devices.Perception.PerceptionDepthFrameReader
#ifndef __WDPPerceptionDepthFrameReader_DEFINED__
#define __WDPPerceptionDepthFrameReader_DEFINED__

WINRT_EXPORT
@interface WDPPerceptionDepthFrameReader : RTObject <WFIClosable>
@property BOOL isPaused;
@property (readonly) WDPPerceptionDepthFrameSource* source;
- (EventRegistrationToken)addFrameArrivedEvent:(void (^)(WDPPerceptionDepthFrameReader*, WDPPerceptionDepthFrameArrivedEventArgs*))del;
- (void)removeFrameArrivedEvent:(EventRegistrationToken)tok;
- (WDPPerceptionDepthFrame*)tryReadLatestFrame;
- (void)close;
@end

#endif // __WDPPerceptionDepthFrameReader_DEFINED__

// Windows.Devices.Perception.PerceptionInfraredFrameReader
#ifndef __WDPPerceptionInfraredFrameReader_DEFINED__
#define __WDPPerceptionInfraredFrameReader_DEFINED__

WINRT_EXPORT
@interface WDPPerceptionInfraredFrameReader : RTObject <WFIClosable>
@property BOOL isPaused;
@property (readonly) WDPPerceptionInfraredFrameSource* source;
- (EventRegistrationToken)addFrameArrivedEvent:(void (^)(WDPPerceptionInfraredFrameReader*,
                                                         WDPPerceptionInfraredFrameArrivedEventArgs*))del;
- (void)removeFrameArrivedEvent:(EventRegistrationToken)tok;
- (WDPPerceptionInfraredFrame*)tryReadLatestFrame;
- (void)close;
@end

#endif // __WDPPerceptionInfraredFrameReader_DEFINED__

// Windows.Devices.Perception.PerceptionColorFrameArrivedEventArgs
#ifndef __WDPPerceptionColorFrameArrivedEventArgs_DEFINED__
#define __WDPPerceptionColorFrameArrivedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPPerceptionColorFrameArrivedEventArgs : RTObject
@property (readonly) WFTimeSpan* relativeTime;
- (WDPPerceptionColorFrame*)tryOpenFrame;
@end

#endif // __WDPPerceptionColorFrameArrivedEventArgs_DEFINED__

// Windows.Devices.Perception.PerceptionColorFrame
#ifndef __WDPPerceptionColorFrame_DEFINED__
#define __WDPPerceptionColorFrame_DEFINED__

WINRT_EXPORT
@interface WDPPerceptionColorFrame : RTObject <WFIClosable>
@property (readonly) WMVideoFrame* videoFrame;
- (void)close;
@end

#endif // __WDPPerceptionColorFrame_DEFINED__

// Windows.Devices.Perception.PerceptionDepthFrameArrivedEventArgs
#ifndef __WDPPerceptionDepthFrameArrivedEventArgs_DEFINED__
#define __WDPPerceptionDepthFrameArrivedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPPerceptionDepthFrameArrivedEventArgs : RTObject
@property (readonly) WFTimeSpan* relativeTime;
- (WDPPerceptionDepthFrame*)tryOpenFrame;
@end

#endif // __WDPPerceptionDepthFrameArrivedEventArgs_DEFINED__

// Windows.Devices.Perception.PerceptionDepthFrame
#ifndef __WDPPerceptionDepthFrame_DEFINED__
#define __WDPPerceptionDepthFrame_DEFINED__

WINRT_EXPORT
@interface WDPPerceptionDepthFrame : RTObject <WFIClosable>
@property (readonly) WMVideoFrame* videoFrame;
- (void)close;
@end

#endif // __WDPPerceptionDepthFrame_DEFINED__

// Windows.Devices.Perception.PerceptionInfraredFrameArrivedEventArgs
#ifndef __WDPPerceptionInfraredFrameArrivedEventArgs_DEFINED__
#define __WDPPerceptionInfraredFrameArrivedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPPerceptionInfraredFrameArrivedEventArgs : RTObject
@property (readonly) WFTimeSpan* relativeTime;
- (WDPPerceptionInfraredFrame*)tryOpenFrame;
@end

#endif // __WDPPerceptionInfraredFrameArrivedEventArgs_DEFINED__

// Windows.Devices.Perception.PerceptionInfraredFrame
#ifndef __WDPPerceptionInfraredFrame_DEFINED__
#define __WDPPerceptionInfraredFrame_DEFINED__

WINRT_EXPORT
@interface WDPPerceptionInfraredFrame : RTObject <WFIClosable>
@property (readonly) WMVideoFrame* videoFrame;
- (void)close;
@end

#endif // __WDPPerceptionInfraredFrame_DEFINED__

// Windows.Devices.Perception.KnownPerceptionFrameSourceProperties
#ifndef __WDPKnownPerceptionFrameSourceProperties_DEFINED__
#define __WDPKnownPerceptionFrameSourceProperties_DEFINED__

WINRT_EXPORT
@interface WDPKnownPerceptionFrameSourceProperties : RTObject
+ (NSString*)deviceModelVersion;
+ (NSString*)enclosureLocation;
+ (NSString*)frameKind;
+ (NSString*)id;
+ (NSString*)physicalDeviceIds;
@end

#endif // __WDPKnownPerceptionFrameSourceProperties_DEFINED__

// Windows.Devices.Perception.KnownPerceptionVideoFrameSourceProperties
#ifndef __WDPKnownPerceptionVideoFrameSourceProperties_DEFINED__
#define __WDPKnownPerceptionVideoFrameSourceProperties_DEFINED__

WINRT_EXPORT
@interface WDPKnownPerceptionVideoFrameSourceProperties : RTObject
+ (NSString*)availableVideoProfiles;
+ (NSString*)cameraIntrinsics;
+ (NSString*)isMirrored;
+ (NSString*)supportedVideoProfiles;
+ (NSString*)videoProfile;
@end

#endif // __WDPKnownPerceptionVideoFrameSourceProperties_DEFINED__

// Windows.Devices.Perception.KnownPerceptionInfraredFrameSourceProperties
#ifndef __WDPKnownPerceptionInfraredFrameSourceProperties_DEFINED__
#define __WDPKnownPerceptionInfraredFrameSourceProperties_DEFINED__

WINRT_EXPORT
@interface WDPKnownPerceptionInfraredFrameSourceProperties : RTObject
+ (NSString*)activeIlluminationEnabled;
+ (NSString*)ambientSubtractionEnabled;
+ (NSString*)autoExposureEnabled;
+ (NSString*)exposure;
+ (NSString*)exposureCompensation;
+ (NSString*)interleavedIlluminationEnabled;
+ (NSString*)structureLightPatternEnabled;
@end

#endif // __WDPKnownPerceptionInfraredFrameSourceProperties_DEFINED__

// Windows.Devices.Perception.KnownPerceptionDepthFrameSourceProperties
#ifndef __WDPKnownPerceptionDepthFrameSourceProperties_DEFINED__
#define __WDPKnownPerceptionDepthFrameSourceProperties_DEFINED__

WINRT_EXPORT
@interface WDPKnownPerceptionDepthFrameSourceProperties : RTObject
+ (NSString*)maxDepth;
+ (NSString*)minDepth;
@end

#endif // __WDPKnownPerceptionDepthFrameSourceProperties_DEFINED__

// Windows.Devices.Perception.KnownPerceptionColorFrameSourceProperties
#ifndef __WDPKnownPerceptionColorFrameSourceProperties_DEFINED__
#define __WDPKnownPerceptionColorFrameSourceProperties_DEFINED__

WINRT_EXPORT
@interface WDPKnownPerceptionColorFrameSourceProperties : RTObject
+ (NSString*)autoExposureEnabled;
+ (NSString*)exposure;
+ (NSString*)exposureCompensation;
@end

#endif // __WDPKnownPerceptionColorFrameSourceProperties_DEFINED__

// Windows.Devices.Perception.KnownPerceptionVideoProfileProperties
#ifndef __WDPKnownPerceptionVideoProfileProperties_DEFINED__
#define __WDPKnownPerceptionVideoProfileProperties_DEFINED__

WINRT_EXPORT
@interface WDPKnownPerceptionVideoProfileProperties : RTObject
+ (NSString*)bitmapAlphaMode;
+ (NSString*)bitmapPixelFormat;
+ (NSString*)frameDuration;
+ (NSString*)height;
+ (NSString*)width;
@end

#endif // __WDPKnownPerceptionVideoProfileProperties_DEFINED__

// Windows.Devices.Perception.KnownCameraIntrinsicsProperties
#ifndef __WDPKnownCameraIntrinsicsProperties_DEFINED__
#define __WDPKnownCameraIntrinsicsProperties_DEFINED__

WINRT_EXPORT
@interface WDPKnownCameraIntrinsicsProperties : RTObject
+ (NSString*)focalLength;
+ (NSString*)principalPoint;
+ (NSString*)radialDistortion;
+ (NSString*)tangentialDistortion;
@end

#endif // __WDPKnownCameraIntrinsicsProperties_DEFINED__
