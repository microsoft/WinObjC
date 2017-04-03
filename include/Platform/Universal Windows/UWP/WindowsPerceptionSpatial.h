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

// WindowsPerceptionSpatial.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSPERCEPTIONSPATIALEXPORT
#define OBJCUWPWINDOWSPERCEPTIONSPATIALEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsPerceptionSpatial.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WPSSpatialCoordinateSystem, WPSSpatialAnchor, WPSSpatialAnchorRawCoordinateSystemAdjustedEventArgs, WPSSpatialAnchorStore, WPSSpatialLocator, WPSSpatialLocatorPositionalTrackingDeactivatingEventArgs, WPSSpatialLocation, WPSSpatialLocatorAttachedFrameOfReference, WPSSpatialStationaryFrameOfReference, WPSSpatialAnchorManager, WPSSpatialAnchorTransferManager, WPSSpatialBoundingVolume;
@class WPSSpatialBoundingFrustum, WPSSpatialBoundingBox, WPSSpatialBoundingOrientedBox, WPSSpatialBoundingSphere;
@protocol WPSISpatialCoordinateSystem, WPSISpatialAnchorRawCoordinateSystemAdjustedEventArgs, WPSISpatialAnchor, WPSISpatialAnchor2, WPSISpatialAnchorStatics, WPSISpatialAnchorStore, WPSISpatialAnchorManagerStatics, WPSISpatialAnchorTransferManagerStatics, WPSISpatialLocatorPositionalTrackingDeactivatingEventArgs, WPSISpatialLocatorAttachedFrameOfReference, WPSISpatialStationaryFrameOfReference, WPSISpatialLocation, WPSISpatialLocator, WPSISpatialLocatorStatics, WPSISpatialBoundingVolume, WPSISpatialBoundingVolumeStatics;

// Windows.Perception.Spatial.SpatialPerceptionAccessStatus
enum _WPSSpatialPerceptionAccessStatus {
    WPSSpatialPerceptionAccessStatusUnspecified = 0,
    WPSSpatialPerceptionAccessStatusAllowed = 1,
    WPSSpatialPerceptionAccessStatusDeniedByUser = 2,
    WPSSpatialPerceptionAccessStatusDeniedBySystem = 3,
};
typedef unsigned WPSSpatialPerceptionAccessStatus;

// Windows.Perception.Spatial.SpatialLocatability
enum _WPSSpatialLocatability {
    WPSSpatialLocatabilityUnavailable = 0,
    WPSSpatialLocatabilityOrientationOnly = 1,
    WPSSpatialLocatabilityPositionalTrackingActivating = 2,
    WPSSpatialLocatabilityPositionalTrackingActive = 3,
    WPSSpatialLocatabilityPositionalTrackingInhibited = 4,
};
typedef unsigned WPSSpatialLocatability;

#include "WindowsPerception.h"
#include "WindowsFoundationNumerics.h"
#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"

#import <Foundation/Foundation.h>

// [struct] Windows.Perception.Spatial.SpatialBoundingFrustum
OBJCUWPWINDOWSPERCEPTIONSPATIALEXPORT
@interface WPSSpatialBoundingFrustum : NSObject
+ (instancetype)new;
@property (retain) WFNPlane* near;
@property (retain) WFNPlane* far;
@property (retain) WFNPlane* right;
@property (retain) WFNPlane* left;
@property (retain) WFNPlane* top;
@property (retain) WFNPlane* bottom;
@end

// [struct] Windows.Perception.Spatial.SpatialBoundingBox
OBJCUWPWINDOWSPERCEPTIONSPATIALEXPORT
@interface WPSSpatialBoundingBox : NSObject
+ (instancetype)new;
@property (retain) WFNVector3* center;
@property (retain) WFNVector3* extents;
@end

// [struct] Windows.Perception.Spatial.SpatialBoundingOrientedBox
OBJCUWPWINDOWSPERCEPTIONSPATIALEXPORT
@interface WPSSpatialBoundingOrientedBox : NSObject
+ (instancetype)new;
@property (retain) WFNVector3* center;
@property (retain) WFNVector3* extents;
@property (retain) WFNQuaternion* orientation;
@end

// [struct] Windows.Perception.Spatial.SpatialBoundingSphere
OBJCUWPWINDOWSPERCEPTIONSPATIALEXPORT
@interface WPSSpatialBoundingSphere : NSObject
+ (instancetype)new;
@property (retain) WFNVector3* center;
@property float radius;
@end

// Windows.Perception.Spatial.SpatialCoordinateSystem
#ifndef __WPSSpatialCoordinateSystem_DEFINED__
#define __WPSSpatialCoordinateSystem_DEFINED__

OBJCUWPWINDOWSPERCEPTIONSPATIALEXPORT
@interface WPSSpatialCoordinateSystem : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (id /* WFNMatrix4x4* */)tryGetTransformTo:(WPSSpatialCoordinateSystem*)target;
@end

#endif // __WPSSpatialCoordinateSystem_DEFINED__

// Windows.Perception.Spatial.SpatialAnchor
#ifndef __WPSSpatialAnchor_DEFINED__
#define __WPSSpatialAnchor_DEFINED__

OBJCUWPWINDOWSPERCEPTIONSPATIALEXPORT
@interface WPSSpatialAnchor : RTObject
+ (WPSSpatialAnchor*)tryCreateRelativeTo:(WPSSpatialCoordinateSystem*)coordinateSystem;
+ (WPSSpatialAnchor*)tryCreateWithPositionRelativeTo:(WPSSpatialCoordinateSystem*)coordinateSystem position:(WFNVector3*)position;
+ (WPSSpatialAnchor*)tryCreateWithPositionAndOrientationRelativeTo:(WPSSpatialCoordinateSystem*)coordinateSystem position:(WFNVector3*)position orientation:(WFNQuaternion*)orientation;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WPSSpatialCoordinateSystem* coordinateSystem;
@property (readonly) WPSSpatialCoordinateSystem* rawCoordinateSystem;
@property (readonly) BOOL removedByUser;
- (EventRegistrationToken)addRawCoordinateSystemAdjustedEvent:(void(^)(WPSSpatialAnchor*, WPSSpatialAnchorRawCoordinateSystemAdjustedEventArgs*))del;
- (void)removeRawCoordinateSystemAdjustedEvent:(EventRegistrationToken)tok;
@end

#endif // __WPSSpatialAnchor_DEFINED__

// Windows.Perception.Spatial.SpatialAnchorRawCoordinateSystemAdjustedEventArgs
#ifndef __WPSSpatialAnchorRawCoordinateSystemAdjustedEventArgs_DEFINED__
#define __WPSSpatialAnchorRawCoordinateSystemAdjustedEventArgs_DEFINED__

OBJCUWPWINDOWSPERCEPTIONSPATIALEXPORT
@interface WPSSpatialAnchorRawCoordinateSystemAdjustedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFNMatrix4x4* oldRawCoordinateSystemToNewRawCoordinateSystemTransform;
@end

#endif // __WPSSpatialAnchorRawCoordinateSystemAdjustedEventArgs_DEFINED__

// Windows.Perception.Spatial.SpatialAnchorStore
#ifndef __WPSSpatialAnchorStore_DEFINED__
#define __WPSSpatialAnchorStore_DEFINED__

OBJCUWPWINDOWSPERCEPTIONSPATIALEXPORT
@interface WPSSpatialAnchorStore : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (NSDictionary* /* NSString *, WPSSpatialAnchor* */)getAllSavedAnchors;
- (BOOL)trySave:(NSString *)id anchor:(WPSSpatialAnchor*)anchor;
- (void)remove:(NSString *)id;
- (void)clear;
@end

#endif // __WPSSpatialAnchorStore_DEFINED__

// Windows.Perception.Spatial.SpatialLocator
#ifndef __WPSSpatialLocator_DEFINED__
#define __WPSSpatialLocator_DEFINED__

OBJCUWPWINDOWSPERCEPTIONSPATIALEXPORT
@interface WPSSpatialLocator : RTObject
+ (WPSSpatialLocator*)getDefault;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WPSSpatialLocatability locatability;
- (EventRegistrationToken)addLocatabilityChangedEvent:(void(^)(WPSSpatialLocator*, RTObject*))del;
- (void)removeLocatabilityChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPositionalTrackingDeactivatingEvent:(void(^)(WPSSpatialLocator*, WPSSpatialLocatorPositionalTrackingDeactivatingEventArgs*))del;
- (void)removePositionalTrackingDeactivatingEvent:(EventRegistrationToken)tok;
- (WPSSpatialLocation*)tryLocateAtTimestamp:(WPPerceptionTimestamp*)timestamp coordinateSystem:(WPSSpatialCoordinateSystem*)coordinateSystem;
- (WPSSpatialLocatorAttachedFrameOfReference*)createAttachedFrameOfReferenceAtCurrentHeading;
- (WPSSpatialLocatorAttachedFrameOfReference*)createAttachedFrameOfReferenceAtCurrentHeadingWithPosition:(WFNVector3*)relativePosition;
- (WPSSpatialLocatorAttachedFrameOfReference*)createAttachedFrameOfReferenceAtCurrentHeadingWithPositionAndOrientation:(WFNVector3*)relativePosition relativeOrientation:(WFNQuaternion*)relativeOrientation;
- (WPSSpatialLocatorAttachedFrameOfReference*)createAttachedFrameOfReferenceAtCurrentHeadingWithPositionAndOrientationAndRelativeHeading:(WFNVector3*)relativePosition relativeOrientation:(WFNQuaternion*)relativeOrientation relativeHeadingInRadians:(double)relativeHeadingInRadians;
- (WPSSpatialStationaryFrameOfReference*)createStationaryFrameOfReferenceAtCurrentLocation;
- (WPSSpatialStationaryFrameOfReference*)createStationaryFrameOfReferenceAtCurrentLocationWithPosition:(WFNVector3*)relativePosition;
- (WPSSpatialStationaryFrameOfReference*)createStationaryFrameOfReferenceAtCurrentLocationWithPositionAndOrientation:(WFNVector3*)relativePosition relativeOrientation:(WFNQuaternion*)relativeOrientation;
- (WPSSpatialStationaryFrameOfReference*)createStationaryFrameOfReferenceAtCurrentLocationWithPositionAndOrientationAndRelativeHeading:(WFNVector3*)relativePosition relativeOrientation:(WFNQuaternion*)relativeOrientation relativeHeadingInRadians:(double)relativeHeadingInRadians;
@end

#endif // __WPSSpatialLocator_DEFINED__

// Windows.Perception.Spatial.SpatialLocatorPositionalTrackingDeactivatingEventArgs
#ifndef __WPSSpatialLocatorPositionalTrackingDeactivatingEventArgs_DEFINED__
#define __WPSSpatialLocatorPositionalTrackingDeactivatingEventArgs_DEFINED__

OBJCUWPWINDOWSPERCEPTIONSPATIALEXPORT
@interface WPSSpatialLocatorPositionalTrackingDeactivatingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL canceled;
@end

#endif // __WPSSpatialLocatorPositionalTrackingDeactivatingEventArgs_DEFINED__

// Windows.Perception.Spatial.SpatialLocation
#ifndef __WPSSpatialLocation_DEFINED__
#define __WPSSpatialLocation_DEFINED__

OBJCUWPWINDOWSPERCEPTIONSPATIALEXPORT
@interface WPSSpatialLocation : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFNQuaternion* absoluteAngularAcceleration;
@property (readonly) WFNQuaternion* absoluteAngularVelocity;
@property (readonly) WFNVector3* absoluteLinearAcceleration;
@property (readonly) WFNVector3* absoluteLinearVelocity;
@property (readonly) WFNQuaternion* orientation;
@property (readonly) WFNVector3* position;
@end

#endif // __WPSSpatialLocation_DEFINED__

// Windows.Perception.Spatial.SpatialLocatorAttachedFrameOfReference
#ifndef __WPSSpatialLocatorAttachedFrameOfReference_DEFINED__
#define __WPSSpatialLocatorAttachedFrameOfReference_DEFINED__

OBJCUWPWINDOWSPERCEPTIONSPATIALEXPORT
@interface WPSSpatialLocatorAttachedFrameOfReference : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFNVector3* relativePosition;
@property (retain) WFNQuaternion* relativeOrientation;
- (void)adjustHeading:(double)headingOffsetInRadians;
- (WPSSpatialCoordinateSystem*)getStationaryCoordinateSystemAtTimestamp:(WPPerceptionTimestamp*)timestamp;
- (id /* double */)tryGetRelativeHeadingAtTimestamp:(WPPerceptionTimestamp*)timestamp;
@end

#endif // __WPSSpatialLocatorAttachedFrameOfReference_DEFINED__

// Windows.Perception.Spatial.SpatialStationaryFrameOfReference
#ifndef __WPSSpatialStationaryFrameOfReference_DEFINED__
#define __WPSSpatialStationaryFrameOfReference_DEFINED__

OBJCUWPWINDOWSPERCEPTIONSPATIALEXPORT
@interface WPSSpatialStationaryFrameOfReference : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WPSSpatialCoordinateSystem* coordinateSystem;
@end

#endif // __WPSSpatialStationaryFrameOfReference_DEFINED__

// Windows.Perception.Spatial.SpatialAnchorManager
#ifndef __WPSSpatialAnchorManager_DEFINED__
#define __WPSSpatialAnchorManager_DEFINED__

OBJCUWPWINDOWSPERCEPTIONSPATIALEXPORT
@interface WPSSpatialAnchorManager : RTObject
+ (void)requestStoreAsyncWithSuccess:(void (^)(WPSSpatialAnchorStore*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WPSSpatialAnchorManager_DEFINED__

// Windows.Perception.Spatial.SpatialAnchorTransferManager
#ifndef __WPSSpatialAnchorTransferManager_DEFINED__
#define __WPSSpatialAnchorTransferManager_DEFINED__

OBJCUWPWINDOWSPERCEPTIONSPATIALEXPORT
@interface WPSSpatialAnchorTransferManager : RTObject
+ (void)tryImportAnchorsAsync:(RTObject<WSSIInputStream>*)stream success:(void (^)(NSDictionary* /* NSString *, WPSSpatialAnchor* */))success failure:(void (^)(NSError*))failure;
+ (void)tryExportAnchorsAsync:(id<NSFastEnumeration> /* RTKeyValuePair* < NSString *, WPSSpatialAnchor* > */)anchors stream:(RTObject<WSSIOutputStream>*)stream success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
+ (void)requestAccessAsyncWithSuccess:(void (^)(WPSSpatialPerceptionAccessStatus))success failure:(void (^)(NSError*))failure;
@end

#endif // __WPSSpatialAnchorTransferManager_DEFINED__

// Windows.Perception.Spatial.SpatialBoundingVolume
#ifndef __WPSSpatialBoundingVolume_DEFINED__
#define __WPSSpatialBoundingVolume_DEFINED__

OBJCUWPWINDOWSPERCEPTIONSPATIALEXPORT
@interface WPSSpatialBoundingVolume : RTObject
+ (WPSSpatialBoundingVolume*)fromBox:(WPSSpatialCoordinateSystem*)coordinateSystem box:(WPSSpatialBoundingBox*)box;
+ (WPSSpatialBoundingVolume*)fromOrientedBox:(WPSSpatialCoordinateSystem*)coordinateSystem box:(WPSSpatialBoundingOrientedBox*)box;
+ (WPSSpatialBoundingVolume*)fromSphere:(WPSSpatialCoordinateSystem*)coordinateSystem sphere:(WPSSpatialBoundingSphere*)sphere;
+ (WPSSpatialBoundingVolume*)fromFrustum:(WPSSpatialCoordinateSystem*)coordinateSystem frustum:(WPSSpatialBoundingFrustum*)frustum;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WPSSpatialBoundingVolume_DEFINED__

