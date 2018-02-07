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

// WindowsMediaDevicesCore.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
#define OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsMediaCaptureDevicesCoreMediaPropertiesDevicesCorePlaybackProtection.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WMDCVariablePhotoSequenceController, WMDCFrameExposureCapabilities, WMDCFrameExposureCompensationCapabilities, WMDCFrameIsoSpeedCapabilities, WMDCFrameFocusCapabilities, WMDCFrameFlashCapabilities, WMDCFrameControlCapabilities, WMDCFrameExposureControl, WMDCFrameExposureCompensationControl, WMDCFrameIsoSpeedControl, WMDCFrameFocusControl, WMDCFrameFlashControl, WMDCFrameController, WMDCCameraIntrinsics, WMDCDepthCorrelatedCoordinateMapper;
@protocol WMDCIFrameExposureCapabilities, WMDCIFrameExposureCompensationCapabilities, WMDCIFrameIsoSpeedCapabilities, WMDCIFrameFocusCapabilities, WMDCIFrameFlashCapabilities, WMDCIFrameControlCapabilities, WMDCIFrameControlCapabilities2, WMDCIFrameExposureControl, WMDCIFrameExposureCompensationControl, WMDCIFrameIsoSpeedControl, WMDCIFrameFocusControl, WMDCIFrameFlashControl, WMDCIFrameController, WMDCIFrameController2, WMDCIVariablePhotoSequenceController, WMDCICameraIntrinsicsFactory, WMDCICameraIntrinsics, WMDCICameraIntrinsics2, WMDCIDepthCorrelatedCoordinateMapper;

// Windows.Media.Devices.Core.FrameFlashMode
enum _WMDCFrameFlashMode {
    WMDCFrameFlashModeDisable = 0,
    WMDCFrameFlashModeEnable = 1,
    WMDCFrameFlashModeGlobal = 2,
};
typedef unsigned WMDCFrameFlashMode;

#include "WindowsFoundation.h"
#include "WindowsMediaMediaProperties.h"
#include "WindowsFoundationNumerics.h"
#include "WindowsPerceptionSpatial.h"

#import <Foundation/Foundation.h>

// Windows.Media.Devices.Core.VariablePhotoSequenceController
#ifndef __WMDCVariablePhotoSequenceController_DEFINED__
#define __WMDCVariablePhotoSequenceController_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMDCVariablePhotoSequenceController : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property float photosPerSecondLimit;
@property (readonly) NSMutableArray* /* WMDCFrameController* */ desiredFrameControllers;
@property (readonly) WMDCFrameControlCapabilities* frameCapabilities;
@property (readonly) float maxPhotosPerSecond;
@property (readonly) BOOL supported;
- (WMMMediaRatio*)getHighestConcurrentFrameRate:(RTObject<WMMIMediaEncodingProperties>*)captureProperties;
- (WMMMediaRatio*)getCurrentFrameRate;
@end

#endif // __WMDCVariablePhotoSequenceController_DEFINED__

// Windows.Media.Devices.Core.FrameExposureCapabilities
#ifndef __WMDCFrameExposureCapabilities_DEFINED__
#define __WMDCFrameExposureCapabilities_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMDCFrameExposureCapabilities : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFTimeSpan* max;
@property (readonly) WFTimeSpan* min;
@property (readonly) WFTimeSpan* step;
@property (readonly) BOOL supported;
@end

#endif // __WMDCFrameExposureCapabilities_DEFINED__

// Windows.Media.Devices.Core.FrameExposureCompensationCapabilities
#ifndef __WMDCFrameExposureCompensationCapabilities_DEFINED__
#define __WMDCFrameExposureCompensationCapabilities_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMDCFrameExposureCompensationCapabilities : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) float max;
@property (readonly) float min;
@property (readonly) float step;
@property (readonly) BOOL supported;
@end

#endif // __WMDCFrameExposureCompensationCapabilities_DEFINED__

// Windows.Media.Devices.Core.FrameIsoSpeedCapabilities
#ifndef __WMDCFrameIsoSpeedCapabilities_DEFINED__
#define __WMDCFrameIsoSpeedCapabilities_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMDCFrameIsoSpeedCapabilities : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int max;
@property (readonly) unsigned int min;
@property (readonly) unsigned int step;
@property (readonly) BOOL supported;
@end

#endif // __WMDCFrameIsoSpeedCapabilities_DEFINED__

// Windows.Media.Devices.Core.FrameFocusCapabilities
#ifndef __WMDCFrameFocusCapabilities_DEFINED__
#define __WMDCFrameFocusCapabilities_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMDCFrameFocusCapabilities : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int max;
@property (readonly) unsigned int min;
@property (readonly) unsigned int step;
@property (readonly) BOOL supported;
@end

#endif // __WMDCFrameFocusCapabilities_DEFINED__

// Windows.Media.Devices.Core.FrameFlashCapabilities
#ifndef __WMDCFrameFlashCapabilities_DEFINED__
#define __WMDCFrameFlashCapabilities_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMDCFrameFlashCapabilities : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL powerSupported;
@property (readonly) BOOL redEyeReductionSupported;
@property (readonly) BOOL supported;
@end

#endif // __WMDCFrameFlashCapabilities_DEFINED__

// Windows.Media.Devices.Core.FrameControlCapabilities
#ifndef __WMDCFrameControlCapabilities_DEFINED__
#define __WMDCFrameControlCapabilities_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMDCFrameControlCapabilities : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMDCFrameExposureCapabilities* exposure;
@property (readonly) WMDCFrameExposureCompensationCapabilities* exposureCompensation;
@property (readonly) WMDCFrameFocusCapabilities* focus;
@property (readonly) WMDCFrameIsoSpeedCapabilities* isoSpeed;
@property (readonly) BOOL photoConfirmationSupported;
@property (readonly) WMDCFrameFlashCapabilities* flash;
@end

#endif // __WMDCFrameControlCapabilities_DEFINED__

// Windows.Media.Devices.Core.FrameExposureControl
#ifndef __WMDCFrameExposureControl_DEFINED__
#define __WMDCFrameExposureControl_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMDCFrameExposureControl : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) id /* WFTimeSpan* */ value;
@property BOOL Auto;
@end

#endif // __WMDCFrameExposureControl_DEFINED__

// Windows.Media.Devices.Core.FrameExposureCompensationControl
#ifndef __WMDCFrameExposureCompensationControl_DEFINED__
#define __WMDCFrameExposureCompensationControl_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMDCFrameExposureCompensationControl : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) id /* float */ value;
@end

#endif // __WMDCFrameExposureCompensationControl_DEFINED__

// Windows.Media.Devices.Core.FrameIsoSpeedControl
#ifndef __WMDCFrameIsoSpeedControl_DEFINED__
#define __WMDCFrameIsoSpeedControl_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMDCFrameIsoSpeedControl : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) id /* unsigned int */ value;
@property BOOL Auto;
@end

#endif // __WMDCFrameIsoSpeedControl_DEFINED__

// Windows.Media.Devices.Core.FrameFocusControl
#ifndef __WMDCFrameFocusControl_DEFINED__
#define __WMDCFrameFocusControl_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMDCFrameFocusControl : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) id /* unsigned int */ value;
@end

#endif // __WMDCFrameFocusControl_DEFINED__

// Windows.Media.Devices.Core.FrameFlashControl
#ifndef __WMDCFrameFlashControl_DEFINED__
#define __WMDCFrameFlashControl_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMDCFrameFlashControl : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL redEyeReduction;
@property float powerPercent;
@property WMDCFrameFlashMode mode;
@property BOOL Auto;
@end

#endif // __WMDCFrameFlashControl_DEFINED__

// Windows.Media.Devices.Core.FrameController
#ifndef __WMDCFrameController_DEFINED__
#define __WMDCFrameController_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMDCFrameController : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) id /* BOOL */ photoConfirmationEnabled;
@property (readonly) WMDCFrameExposureCompensationControl* exposureCompensationControl;
@property (readonly) WMDCFrameExposureControl* exposureControl;
@property (readonly) WMDCFrameFocusControl* focusControl;
@property (readonly) WMDCFrameIsoSpeedControl* isoSpeedControl;
@property (readonly) WMDCFrameFlashControl* flashControl;
@end

#endif // __WMDCFrameController_DEFINED__

// Windows.Media.Devices.Core.CameraIntrinsics
#ifndef __WMDCCameraIntrinsics_DEFINED__
#define __WMDCCameraIntrinsics_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMDCCameraIntrinsics : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFNVector2* focalLength;
@property (readonly) unsigned int imageHeight;
@property (readonly) unsigned int imageWidth;
@property (readonly) WFNVector2* principalPoint;
@property (readonly) WFNVector3* radialDistortion;
@property (readonly) WFNVector2* tangentialDistortion;
@property (readonly) WFNMatrix4x4* undistortedProjectionTransform;
- (WFPoint*)projectOntoFrame:(WFNVector3*)coordinate;
- (WFNVector2*)unprojectAtUnitDepth:(WFPoint*)pixelCoordinate;
- (void)projectManyOntoFrame:(NSArray* /* WFNVector3* */)coordinates results:(NSArray* /* WFPoint* */*)results;
- (void)unprojectPixelsAtUnitDepth:(NSArray* /* WFPoint* */)pixelCoordinates results:(NSArray* /* WFNVector2* */*)results;
- (WFPoint*)distortPoint:(WFPoint*)input;
- (void)distortPoints:(NSArray* /* WFPoint* */)inputs results:(NSArray* /* WFPoint* */*)results;
- (WFPoint*)undistortPoint:(WFPoint*)input;
- (void)undistortPoints:(NSArray* /* WFPoint* */)inputs results:(NSArray* /* WFPoint* */*)results;
@end

#endif // __WMDCCameraIntrinsics_DEFINED__

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

// Windows.Media.Devices.Core.DepthCorrelatedCoordinateMapper
#ifndef __WMDCDepthCorrelatedCoordinateMapper_DEFINED__
#define __WMDCDepthCorrelatedCoordinateMapper_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMDCDepthCorrelatedCoordinateMapper : RTObject <WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WFNVector3*)unprojectPoint:(WFPoint*)sourcePoint targetCoordinateSystem:(WPSSpatialCoordinateSystem*)targetCoordinateSystem;
- (void)unprojectPoints:(NSArray* /* WFPoint* */)sourcePoints targetCoordinateSystem:(WPSSpatialCoordinateSystem*)targetCoordinateSystem results:(NSArray* /* WFNVector3* */*)results;
- (WFPoint*)mapPoint:(WFPoint*)sourcePoint targetCoordinateSystem:(WPSSpatialCoordinateSystem*)targetCoordinateSystem targetCameraIntrinsics:(WMDCCameraIntrinsics*)targetCameraIntrinsics;
- (void)mapPoints:(NSArray* /* WFPoint* */)sourcePoints targetCoordinateSystem:(WPSSpatialCoordinateSystem*)targetCoordinateSystem targetCameraIntrinsics:(WMDCCameraIntrinsics*)targetCameraIntrinsics results:(NSArray* /* WFPoint* */*)results;
- (void)close;
@end

#endif // __WMDCDepthCorrelatedCoordinateMapper_DEFINED__

