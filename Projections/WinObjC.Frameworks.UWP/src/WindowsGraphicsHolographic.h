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

// WindowsGraphicsHolographic.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSGRAPHICSHOLOGRAPHICEXPORT
#define OBJCUWPWINDOWSGRAPHICSHOLOGRAPHICEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsGraphicsHolographic.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WGHHolographicCamera, WGHHolographicSpace, WGHHolographicSpaceCameraAddedEventArgs, WGHHolographicSpaceCameraRemovedEventArgs,
    WGHHolographicFrame, WGHHolographicCameraPose, WGHHolographicCameraRenderingParameters, WGHHolographicFramePrediction;
@class WGHHolographicStereoTransform, WGHHolographicAdapterId;
@protocol WGHIHolographicCamera
, WGHIHolographicSpaceCameraAddedEventArgs, WGHIHolographicSpaceCameraRemovedEventArgs, WGHIHolographicSpace, WGHIHolographicSpaceStatics,
    WGHIHolographicCameraPose, WGHIHolographicFramePrediction, WGHIHolographicCameraRenderingParameters, WGHIHolographicFrame;

// Windows.Graphics.Holographic.HolographicFramePresentResult
enum _WGHHolographicFramePresentResult {
    WGHHolographicFramePresentResultSuccess = 0,
    WGHHolographicFramePresentResultDeviceRemoved = 1,
};
typedef unsigned WGHHolographicFramePresentResult;

// Windows.Graphics.Holographic.HolographicFramePresentWaitBehavior
enum _WGHHolographicFramePresentWaitBehavior {
    WGHHolographicFramePresentWaitBehaviorWaitForFrameToFinish = 0,
    WGHHolographicFramePresentWaitBehaviorDoNotWaitForFrameToFinish = 1,
};
typedef unsigned WGHHolographicFramePresentWaitBehavior;

#include "WindowsPerceptionSpatial.h"
#include "WindowsUICore.h"
#include "WindowsFoundation.h"
#include "WindowsGraphicsDirectXDirect3D11.h"
#include "WindowsFoundationNumerics.h"
#include "WindowsPerception.h"

#import <Foundation/Foundation.h>

// [struct] Windows.Graphics.Holographic.HolographicStereoTransform
OBJCUWPWINDOWSGRAPHICSHOLOGRAPHICEXPORT
@interface WGHHolographicStereoTransform : NSObject
+ (instancetype) new;
@property (retain) WFNMatrix4x4* left;
@property (retain) WFNMatrix4x4* right;
@end

// [struct] Windows.Graphics.Holographic.HolographicAdapterId
OBJCUWPWINDOWSGRAPHICSHOLOGRAPHICEXPORT
@interface WGHHolographicAdapterId : NSObject
+ (instancetype) new;
@property unsigned int lowPart;
@property int highPart;
@end

// Windows.Graphics.Holographic.HolographicCamera
#ifndef __WGHHolographicCamera_DEFINED__
#define __WGHHolographicCamera_DEFINED__

OBJCUWPWINDOWSGRAPHICSHOLOGRAPHICEXPORT
@interface WGHHolographicCamera : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property double viewportScaleFactor;
@property (readonly) unsigned int id;
@property (readonly) BOOL isStereo;
@property (readonly) WFSize* renderTargetSize;
- (void)setNearPlaneDistance:(double)value;
- (void)setFarPlaneDistance:(double)value;
@end

#endif // __WGHHolographicCamera_DEFINED__

// Windows.Graphics.Holographic.HolographicSpace
#ifndef __WGHHolographicSpace_DEFINED__
#define __WGHHolographicSpace_DEFINED__

OBJCUWPWINDOWSGRAPHICSHOLOGRAPHICEXPORT
@interface WGHHolographicSpace : RTObject
+ (WGHHolographicSpace*)createForCoreWindow:(WUCCoreWindow*)window;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WGHHolographicAdapterId* primaryAdapterId;
- (EventRegistrationToken)addCameraAddedEvent:(void (^)(WGHHolographicSpace*, WGHHolographicSpaceCameraAddedEventArgs*))del;
- (void)removeCameraAddedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCameraRemovedEvent:(void (^)(WGHHolographicSpace*, WGHHolographicSpaceCameraRemovedEventArgs*))del;
- (void)removeCameraRemovedEvent:(EventRegistrationToken)tok;
- (void)setDirect3D11Device:(RTObject<WGDDIDirect3DDevice>*)value;
- (WGHHolographicFrame*)createNextFrame;
@end

#endif // __WGHHolographicSpace_DEFINED__

// Windows.Graphics.Holographic.HolographicSpaceCameraAddedEventArgs
#ifndef __WGHHolographicSpaceCameraAddedEventArgs_DEFINED__
#define __WGHHolographicSpaceCameraAddedEventArgs_DEFINED__

OBJCUWPWINDOWSGRAPHICSHOLOGRAPHICEXPORT
@interface WGHHolographicSpaceCameraAddedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WGHHolographicCamera* camera;
- (WFDeferral*)getDeferral;
@end

#endif // __WGHHolographicSpaceCameraAddedEventArgs_DEFINED__

// Windows.Graphics.Holographic.HolographicSpaceCameraRemovedEventArgs
#ifndef __WGHHolographicSpaceCameraRemovedEventArgs_DEFINED__
#define __WGHHolographicSpaceCameraRemovedEventArgs_DEFINED__

OBJCUWPWINDOWSGRAPHICSHOLOGRAPHICEXPORT
@interface WGHHolographicSpaceCameraRemovedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WGHHolographicCamera* camera;
@end

#endif // __WGHHolographicSpaceCameraRemovedEventArgs_DEFINED__

// Windows.Graphics.Holographic.HolographicFrame
#ifndef __WGHHolographicFrame_DEFINED__
#define __WGHHolographicFrame_DEFINED__

OBJCUWPWINDOWSGRAPHICSHOLOGRAPHICEXPORT
@interface WGHHolographicFrame : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WGHHolographicCamera* */ addedCameras;
@property (readonly) WGHHolographicFramePrediction* currentPrediction;
@property (readonly) WFTimeSpan* duration;
@property (readonly) NSArray* /* WGHHolographicCamera* */ removedCameras;
- (WGHHolographicCameraRenderingParameters*)getRenderingParameters:(WGHHolographicCameraPose*)cameraPose;
- (void)updateCurrentPrediction;
- (WGHHolographicFramePresentResult)presentUsingCurrentPrediction;
- (WGHHolographicFramePresentResult)presentUsingCurrentPredictionWithBehavior:(WGHHolographicFramePresentWaitBehavior)waitBehavior;
- (void)waitForFrameToFinish;
@end

#endif // __WGHHolographicFrame_DEFINED__

// Windows.Graphics.Holographic.HolographicCameraPose
#ifndef __WGHHolographicCameraPose_DEFINED__
#define __WGHHolographicCameraPose_DEFINED__

OBJCUWPWINDOWSGRAPHICSHOLOGRAPHICEXPORT
@interface WGHHolographicCameraPose : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) double farPlaneDistance;
@property (readonly) WGHHolographicCamera* holographicCamera;
@property (readonly) double nearPlaneDistance;
@property (readonly) WGHHolographicStereoTransform* projectionTransform;
@property (readonly) WFRect* viewport;
- (id /* WGHHolographicStereoTransform* */)tryGetViewTransform:(WPSSpatialCoordinateSystem*)coordinateSystem;
- (id /* WPSSpatialBoundingFrustum* */)tryGetCullingFrustum:(WPSSpatialCoordinateSystem*)coordinateSystem;
- (id /* WPSSpatialBoundingFrustum* */)tryGetVisibleFrustum:(WPSSpatialCoordinateSystem*)coordinateSystem;
@end

#endif // __WGHHolographicCameraPose_DEFINED__

// Windows.Graphics.Holographic.HolographicCameraRenderingParameters
#ifndef __WGHHolographicCameraRenderingParameters_DEFINED__
#define __WGHHolographicCameraRenderingParameters_DEFINED__

OBJCUWPWINDOWSGRAPHICSHOLOGRAPHICEXPORT
@interface WGHHolographicCameraRenderingParameters : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) RTObject<WGDDIDirect3DSurface>* direct3D11BackBuffer;
@property (readonly) RTObject<WGDDIDirect3DDevice>* direct3D11Device;
- (void)setFocusPoint:(WPSSpatialCoordinateSystem*)coordinateSystem position:(WFNVector3*)position;
- (void)setFocusPointWithNormal:(WPSSpatialCoordinateSystem*)coordinateSystem position:(WFNVector3*)position normal:(WFNVector3*)normal;
- (void)setFocusPointWithNormalLinearVelocity:(WPSSpatialCoordinateSystem*)coordinateSystem
                                     position:(WFNVector3*)position
                                       normal:(WFNVector3*)normal
                               linearVelocity:(WFNVector3*)linearVelocity;
@end

#endif // __WGHHolographicCameraRenderingParameters_DEFINED__

// Windows.Graphics.Holographic.HolographicFramePrediction
#ifndef __WGHHolographicFramePrediction_DEFINED__
#define __WGHHolographicFramePrediction_DEFINED__

OBJCUWPWINDOWSGRAPHICSHOLOGRAPHICEXPORT
@interface WGHHolographicFramePrediction : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WGHHolographicCameraPose* */ cameraPoses;
@property (readonly) WPPerceptionTimestamp* timestamp;
@end

#endif // __WGHHolographicFramePrediction_DEFINED__
