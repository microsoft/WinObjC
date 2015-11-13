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

// WindowsMediaDevicesCore.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WMDCCameraIntrinsics, WMDCVariablePhotoSequenceController, WMDCFrameExposureCapabilities, WMDCFrameExposureCompensationCapabilities,
    WMDCFrameIsoSpeedCapabilities, WMDCFrameFocusCapabilities, WMDCFrameFlashCapabilities, WMDCFrameControlCapabilities,
    WMDCFrameExposureControl, WMDCFrameExposureCompensationControl, WMDCFrameIsoSpeedControl, WMDCFrameFocusControl, WMDCFrameFlashControl,
    WMDCFrameController;
@class RTArray_C_WFNVector2, RTArray_C_WFPoint;
@protocol WMDCICameraIntrinsicsFactory
, WMDCICameraIntrinsics, WMDCIFrameExposureCapabilities, WMDCIFrameExposureCompensationCapabilities, WMDCIFrameIsoSpeedCapabilities,
    WMDCIFrameFocusCapabilities, WMDCIFrameFlashCapabilities, WMDCIFrameControlCapabilities, WMDCIFrameControlCapabilities2,
    WMDCIFrameExposureControl, WMDCIFrameExposureCompensationControl, WMDCIFrameIsoSpeedControl, WMDCIFrameFocusControl,
    WMDCIFrameFlashControl, WMDCIFrameController, WMDCIFrameController2, WMDCIVariablePhotoSequenceController;

// Windows.Media.Devices.Core.FrameFlashMode
enum _WMDCFrameFlashMode {
    WMDCFrameFlashModeDisable = 0,
    WMDCFrameFlashModeEnable = 1,
    WMDCFrameFlashModeGlobal = 2,
};
typedef unsigned WMDCFrameFlashMode;

#include "WindowsFoundationNumerics.h"
#include "WindowsFoundation.h"
#include "WindowsMediaMediaProperties.h"
#include "WindowsFoundationCollections.h"

#import <Foundation/Foundation.h>

// Windows.Media.Devices.Core.CameraIntrinsics
#ifndef __WMDCCameraIntrinsics_DEFINED__
#define __WMDCCameraIntrinsics_DEFINED__

WINRT_EXPORT
@interface WMDCCameraIntrinsics : RTObject
@property (readonly) WFNVector2* focalLength;
@property (readonly) unsigned int imageHeight;
@property (readonly) unsigned int imageWidth;
@property (readonly) WFNVector2* principalPoint;
@property (readonly) WFNVector3* radialDistortion;
@property (readonly) WFNVector2* tangentialDistortion;
- (WFPoint*)projectOntoFrame:(WFNVector3*)coordinate;
- (WFNVector2*)unprojectAtUnitDepth:(WFPoint*)pixelCoordinate;
- (void)projectManyOntoFrame:(id<NSFastEnumeration> /* WFNVector3* */)coordinates results:(RTArray_C_WFPoint*)results;
- (void)unprojectPixelsAtUnitDepth:(id<NSFastEnumeration> /* WFPoint* */)pixelCoordinates results:(RTArray_C_WFNVector2*)results;
@end

#endif // __WMDCCameraIntrinsics_DEFINED__

// Windows.Media.Devices.Core.VariablePhotoSequenceController
#ifndef __WMDCVariablePhotoSequenceController_DEFINED__
#define __WMDCVariablePhotoSequenceController_DEFINED__

WINRT_EXPORT
@interface WMDCVariablePhotoSequenceController : RTObject
@property float photosPerSecondLimit;
@property (readonly) NSMutableArray* desiredFrameControllers;
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

WINRT_EXPORT
@interface WMDCFrameExposureCapabilities : RTObject
@property (readonly) WFTimeSpan* max;
@property (readonly) WFTimeSpan* min;
@property (readonly) WFTimeSpan* step;
@property (readonly) BOOL supported;
@end

#endif // __WMDCFrameExposureCapabilities_DEFINED__

// Windows.Media.Devices.Core.FrameExposureCompensationCapabilities
#ifndef __WMDCFrameExposureCompensationCapabilities_DEFINED__
#define __WMDCFrameExposureCompensationCapabilities_DEFINED__

WINRT_EXPORT
@interface WMDCFrameExposureCompensationCapabilities : RTObject
@property (readonly) float max;
@property (readonly) float min;
@property (readonly) float step;
@property (readonly) BOOL supported;
@end

#endif // __WMDCFrameExposureCompensationCapabilities_DEFINED__

// Windows.Media.Devices.Core.FrameIsoSpeedCapabilities
#ifndef __WMDCFrameIsoSpeedCapabilities_DEFINED__
#define __WMDCFrameIsoSpeedCapabilities_DEFINED__

WINRT_EXPORT
@interface WMDCFrameIsoSpeedCapabilities : RTObject
@property (readonly) unsigned int max;
@property (readonly) unsigned int min;
@property (readonly) unsigned int step;
@property (readonly) BOOL supported;
@end

#endif // __WMDCFrameIsoSpeedCapabilities_DEFINED__

// Windows.Media.Devices.Core.FrameFocusCapabilities
#ifndef __WMDCFrameFocusCapabilities_DEFINED__
#define __WMDCFrameFocusCapabilities_DEFINED__

WINRT_EXPORT
@interface WMDCFrameFocusCapabilities : RTObject
@property (readonly) unsigned int max;
@property (readonly) unsigned int min;
@property (readonly) unsigned int step;
@property (readonly) BOOL supported;
@end

#endif // __WMDCFrameFocusCapabilities_DEFINED__

// Windows.Media.Devices.Core.FrameFlashCapabilities
#ifndef __WMDCFrameFlashCapabilities_DEFINED__
#define __WMDCFrameFlashCapabilities_DEFINED__

WINRT_EXPORT
@interface WMDCFrameFlashCapabilities : RTObject
@property (readonly) BOOL powerSupported;
@property (readonly) BOOL redEyeReductionSupported;
@property (readonly) BOOL supported;
@end

#endif // __WMDCFrameFlashCapabilities_DEFINED__

// Windows.Media.Devices.Core.FrameControlCapabilities
#ifndef __WMDCFrameControlCapabilities_DEFINED__
#define __WMDCFrameControlCapabilities_DEFINED__

WINRT_EXPORT
@interface WMDCFrameControlCapabilities : RTObject
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

WINRT_EXPORT
@interface WMDCFrameExposureControl : RTObject
@property (copy) id value;
@property BOOL Auto;
@end

#endif // __WMDCFrameExposureControl_DEFINED__

// Windows.Media.Devices.Core.FrameExposureCompensationControl
#ifndef __WMDCFrameExposureCompensationControl_DEFINED__
#define __WMDCFrameExposureCompensationControl_DEFINED__

WINRT_EXPORT
@interface WMDCFrameExposureCompensationControl : RTObject
@property (copy) id value;
@end

#endif // __WMDCFrameExposureCompensationControl_DEFINED__

// Windows.Media.Devices.Core.FrameIsoSpeedControl
#ifndef __WMDCFrameIsoSpeedControl_DEFINED__
#define __WMDCFrameIsoSpeedControl_DEFINED__

WINRT_EXPORT
@interface WMDCFrameIsoSpeedControl : RTObject
@property (copy) id value;
@property BOOL Auto;
@end

#endif // __WMDCFrameIsoSpeedControl_DEFINED__

// Windows.Media.Devices.Core.FrameFocusControl
#ifndef __WMDCFrameFocusControl_DEFINED__
#define __WMDCFrameFocusControl_DEFINED__

WINRT_EXPORT
@interface WMDCFrameFocusControl : RTObject
@property (copy) id value;
@end

#endif // __WMDCFrameFocusControl_DEFINED__

// Windows.Media.Devices.Core.FrameFlashControl
#ifndef __WMDCFrameFlashControl_DEFINED__
#define __WMDCFrameFlashControl_DEFINED__

WINRT_EXPORT
@interface WMDCFrameFlashControl : RTObject
@property BOOL redEyeReduction;
@property float powerPercent;
@property WMDCFrameFlashMode mode;
@property BOOL Auto;
@end

#endif // __WMDCFrameFlashControl_DEFINED__

// Windows.Media.Devices.Core.FrameController
#ifndef __WMDCFrameController_DEFINED__
#define __WMDCFrameController_DEFINED__

WINRT_EXPORT
@interface WMDCFrameController : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) id photoConfirmationEnabled;
@property (readonly) WMDCFrameExposureCompensationControl* exposureCompensationControl;
@property (readonly) WMDCFrameExposureControl* exposureControl;
@property (readonly) WMDCFrameFocusControl* focusControl;
@property (readonly) WMDCFrameIsoSpeedControl* isoSpeedControl;
@property (readonly) WMDCFrameFlashControl* flashControl;
@end

#endif // __WMDCFrameController_DEFINED__
