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

// WindowsMediaDevices.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WMDDefaultAudioCaptureDeviceChangedEventArgs, WMDDefaultAudioRenderDeviceChangedEventArgs, WMDMediaDevice, WMDAudioDeviceController,
    WMDVideoDeviceController, WMDSceneModeControl, WMDTorchControl, WMDFlashControl, WMDExposureCompensationControl, WMDIsoSpeedControl,
    WMDWhiteBalanceControl, WMDExposureControl, WMDZoomSettings, WMDZoomControl, WMDFocusSettings, WMDFocusControl, WMDRegionOfInterest,
    WMDRegionsOfInterestControl, WMDExposurePriorityVideoControl, WMDHdrVideoControl, WMDAdvancedPhotoCaptureSettings,
    WMDAdvancedPhotoControl, WMDOpticalImageStabilizationControl, WMDMediaDeviceControl, WMDLowLagPhotoSequenceControl,
    WMDLowLagPhotoControl, WMDPhotoConfirmationControl, WMDMediaDeviceControlCapabilities;
@protocol WMDIDefaultAudioDeviceChangedEventArgs
, WMDIMediaDeviceStatics, WMDISceneModeControl, WMDITorchControl, WMDIFlashControl, WMDIFlashControl2, WMDIExposureCompensationControl,
    WMDIIsoSpeedControl, WMDIIsoSpeedControl2, WMDIWhiteBalanceControl, WMDIExposureControl, WMDIZoomSettings, WMDIZoomControl,
    WMDIZoomControl2, WMDIFocusSettings, WMDIFocusControl, WMDIFocusControl2, WMDIRegionOfInterest, WMDIRegionOfInterest2,
    WMDIRegionsOfInterestControl, WMDIExposurePriorityVideoControl, WMDIHdrVideoControl, WMDIAdvancedPhotoCaptureSettings,
    WMDIAdvancedPhotoControl, WMDIOpticalImageStabilizationControl, WMDIMediaDeviceController, WMDIAudioDeviceController,
    WMDIVideoDeviceController, WMDIAdvancedVideoCaptureDeviceController2, WMDIAdvancedVideoCaptureDeviceController3,
    WMDIAdvancedVideoCaptureDeviceController4, WMDIMediaDeviceControl, WMDIMediaDeviceControlCapabilities,
    WMDIAdvancedVideoCaptureDeviceController, WMDILowLagPhotoSequenceControl, WMDILowLagPhotoControl, WMDIPhotoConfirmationControl;

// Windows.Media.Devices.AudioDeviceRole
enum _WMDAudioDeviceRole {
    WMDAudioDeviceRoleDefault = 0,
    WMDAudioDeviceRoleCommunications = 1,
};
typedef unsigned WMDAudioDeviceRole;

// Windows.Media.Devices.IsoSpeedPreset
enum _WMDIsoSpeedPreset {
    WMDIsoSpeedPresetAuto = 0,
    WMDIsoSpeedPresetIso50 = 1,
    WMDIsoSpeedPresetIso80 = 2,
    WMDIsoSpeedPresetIso100 = 3,
    WMDIsoSpeedPresetIso200 = 4,
    WMDIsoSpeedPresetIso400 = 5,
    WMDIsoSpeedPresetIso800 = 6,
    WMDIsoSpeedPresetIso1600 = 7,
    WMDIsoSpeedPresetIso3200 = 8,
    WMDIsoSpeedPresetIso6400 = 9,
    WMDIsoSpeedPresetIso12800 = 10,
    WMDIsoSpeedPresetIso25600 = 11,
};
typedef unsigned WMDIsoSpeedPreset;

// Windows.Media.Devices.CaptureSceneMode
enum _WMDCaptureSceneMode {
    WMDCaptureSceneModeAuto = 0,
    WMDCaptureSceneModeManual = 1,
    WMDCaptureSceneModeMacro = 2,
    WMDCaptureSceneModePortrait = 3,
    WMDCaptureSceneModeSport = 4,
    WMDCaptureSceneModeSnow = 5,
    WMDCaptureSceneModeNight = 6,
    WMDCaptureSceneModeBeach = 7,
    WMDCaptureSceneModeSunset = 8,
    WMDCaptureSceneModeCandlelight = 9,
    WMDCaptureSceneModeLandscape = 10,
    WMDCaptureSceneModeNightPortrait = 11,
    WMDCaptureSceneModeBacklit = 12,
};
typedef unsigned WMDCaptureSceneMode;

// Windows.Media.Devices.MediaCaptureFocusState
enum _WMDMediaCaptureFocusState {
    WMDMediaCaptureFocusStateUninitialized = 0,
    WMDMediaCaptureFocusStateLost = 1,
    WMDMediaCaptureFocusStateSearching = 2,
    WMDMediaCaptureFocusStateFocused = 3,
    WMDMediaCaptureFocusStateFailed = 4,
};
typedef unsigned WMDMediaCaptureFocusState;

// Windows.Media.Devices.CameraStreamState
enum _WMDCameraStreamState {
    WMDCameraStreamStateNotStreaming = 0,
    WMDCameraStreamStateStreaming = 1,
    WMDCameraStreamStateBlockedForPrivacy = 2,
    WMDCameraStreamStateShutdown = 3,
};
typedef unsigned WMDCameraStreamState;

// Windows.Media.Devices.MediaCapturePauseBehavior
enum _WMDMediaCapturePauseBehavior {
    WMDMediaCapturePauseBehaviorRetainHardwareResources = 0,
    WMDMediaCapturePauseBehaviorReleaseHardwareResources = 1,
};
typedef unsigned WMDMediaCapturePauseBehavior;

// Windows.Media.Devices.AdvancedPhotoMode
enum _WMDAdvancedPhotoMode {
    WMDAdvancedPhotoModeAuto = 0,
    WMDAdvancedPhotoModeStandard = 1,
    WMDAdvancedPhotoModeHdr = 2,
};
typedef unsigned WMDAdvancedPhotoMode;

// Windows.Media.Devices.ColorTemperaturePreset
enum _WMDColorTemperaturePreset {
    WMDColorTemperaturePresetAuto = 0,
    WMDColorTemperaturePresetManual = 1,
    WMDColorTemperaturePresetCloudy = 2,
    WMDColorTemperaturePresetDaylight = 3,
    WMDColorTemperaturePresetFlash = 4,
    WMDColorTemperaturePresetFluorescent = 5,
    WMDColorTemperaturePresetTungsten = 6,
    WMDColorTemperaturePresetCandlelight = 7,
};
typedef unsigned WMDColorTemperaturePreset;

// Windows.Media.Devices.ZoomTransitionMode
enum _WMDZoomTransitionMode {
    WMDZoomTransitionModeAuto = 0,
    WMDZoomTransitionModeDirect = 1,
    WMDZoomTransitionModeSmooth = 2,
};
typedef unsigned WMDZoomTransitionMode;

// Windows.Media.Devices.FocusPreset
enum _WMDFocusPreset {
    WMDFocusPresetAuto = 0,
    WMDFocusPresetManual = 1,
    WMDFocusPresetAutoMacro = 2,
    WMDFocusPresetAutoNormal = 3,
    WMDFocusPresetAutoInfinity = 4,
    WMDFocusPresetAutoHyperfocal = 5,
};
typedef unsigned WMDFocusPreset;

// Windows.Media.Devices.FocusMode
enum _WMDFocusMode {
    WMDFocusModeAuto = 0,
    WMDFocusModeSingle = 1,
    WMDFocusModeContinuous = 2,
    WMDFocusModeManual = 3,
};
typedef unsigned WMDFocusMode;

// Windows.Media.Devices.ManualFocusDistance
enum _WMDManualFocusDistance {
    WMDManualFocusDistanceInfinity = 0,
    WMDManualFocusDistanceHyperfocal = 1,
    WMDManualFocusDistanceNearest = 2,
};
typedef unsigned WMDManualFocusDistance;

// Windows.Media.Devices.AutoFocusRange
enum _WMDAutoFocusRange {
    WMDAutoFocusRangeFullRange = 0,
    WMDAutoFocusRangeMacro = 1,
    WMDAutoFocusRangeNormal = 2,
};
typedef unsigned WMDAutoFocusRange;

// Windows.Media.Devices.RegionOfInterestType
enum _WMDRegionOfInterestType {
    WMDRegionOfInterestTypeUnknown = 0,
    WMDRegionOfInterestTypeFace = 1,
};
typedef unsigned WMDRegionOfInterestType;

// Windows.Media.Devices.HdrVideoMode
enum _WMDHdrVideoMode {
    WMDHdrVideoModeOff = 0,
    WMDHdrVideoModeOn = 1,
    WMDHdrVideoModeAuto = 2,
};
typedef unsigned WMDHdrVideoMode;

// Windows.Media.Devices.OpticalImageStabilizationMode
enum _WMDOpticalImageStabilizationMode {
    WMDOpticalImageStabilizationModeOff = 0,
    WMDOpticalImageStabilizationModeOn = 1,
    WMDOpticalImageStabilizationModeAuto = 2,
};
typedef unsigned WMDOpticalImageStabilizationMode;

// Windows.Media.Devices.CaptureUse
enum _WMDCaptureUse {
    WMDCaptureUseNone = 0,
    WMDCaptureUsePhoto = 1,
    WMDCaptureUseVideo = 2,
};
typedef unsigned WMDCaptureUse;

// Windows.Media.Devices.MediaCaptureOptimization
enum _WMDMediaCaptureOptimization {
    WMDMediaCaptureOptimizationDefault = 0,
    WMDMediaCaptureOptimizationQuality = 1,
    WMDMediaCaptureOptimizationLatency = 2,
    WMDMediaCaptureOptimizationPower = 3,
    WMDMediaCaptureOptimizationLatencyThenQuality = 4,
    WMDMediaCaptureOptimizationLatencyThenPower = 5,
    WMDMediaCaptureOptimizationPowerAndQuality = 6,
};
typedef unsigned WMDMediaCaptureOptimization;

#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"
#include "WindowsMediaCapture.h"
#include "WindowsMediaMediaProperties.h"
#include "WindowsMediaDevicesCore.h"

#import <Foundation/Foundation.h>

// Windows.Media.Devices.IDefaultAudioDeviceChangedEventArgs
#ifndef __WMDIDefaultAudioDeviceChangedEventArgs_DEFINED__
#define __WMDIDefaultAudioDeviceChangedEventArgs_DEFINED__

@protocol WMDIDefaultAudioDeviceChangedEventArgs
@property (readonly) NSString* id;
@property (readonly) WMDAudioDeviceRole role;
@end

#endif // __WMDIDefaultAudioDeviceChangedEventArgs_DEFINED__

// Windows.Media.Devices.IMediaDeviceController
#ifndef __WMDIMediaDeviceController_DEFINED__
#define __WMDIMediaDeviceController_DEFINED__

@protocol WMDIMediaDeviceController
- (NSArray*)getAvailableMediaStreamProperties:(WMCMediaStreamType)mediaStreamType;
- (RTObject<WMMIMediaEncodingProperties>*)getMediaStreamProperties:(WMCMediaStreamType)mediaStreamType;
- (RTObject<WFIAsyncAction>*)setMediaStreamPropertiesAsync:(WMCMediaStreamType)mediaStreamType
                                   mediaEncodingProperties:(RTObject<WMMIMediaEncodingProperties>*)mediaEncodingProperties;
@end

#endif // __WMDIMediaDeviceController_DEFINED__

// Windows.Media.Devices.DefaultAudioCaptureDeviceChangedEventArgs
#ifndef __WMDDefaultAudioCaptureDeviceChangedEventArgs_DEFINED__
#define __WMDDefaultAudioCaptureDeviceChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMDDefaultAudioCaptureDeviceChangedEventArgs : RTObject <WMDIDefaultAudioDeviceChangedEventArgs>
@property (readonly) NSString* id;
@property (readonly) WMDAudioDeviceRole role;
@end

#endif // __WMDDefaultAudioCaptureDeviceChangedEventArgs_DEFINED__

// Windows.Media.Devices.DefaultAudioRenderDeviceChangedEventArgs
#ifndef __WMDDefaultAudioRenderDeviceChangedEventArgs_DEFINED__
#define __WMDDefaultAudioRenderDeviceChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMDDefaultAudioRenderDeviceChangedEventArgs : RTObject <WMDIDefaultAudioDeviceChangedEventArgs>
@property (readonly) NSString* id;
@property (readonly) WMDAudioDeviceRole role;
@end

#endif // __WMDDefaultAudioRenderDeviceChangedEventArgs_DEFINED__

// Windows.Media.Devices.MediaDevice
#ifndef __WMDMediaDevice_DEFINED__
#define __WMDMediaDevice_DEFINED__

WINRT_EXPORT
@interface WMDMediaDevice : RTObject
+ (NSString*)getAudioCaptureSelector;
+ (NSString*)getAudioRenderSelector;
+ (NSString*)getVideoCaptureSelector;
+ (NSString*)getDefaultAudioCaptureId:(WMDAudioDeviceRole)role;
+ (NSString*)getDefaultAudioRenderId:(WMDAudioDeviceRole)role;
+ (EventRegistrationToken)addDefaultAudioCaptureDeviceChangedEvent:(void (^)(RTObject*, WMDDefaultAudioCaptureDeviceChangedEventArgs*))del;
+ (void)removeDefaultAudioCaptureDeviceChangedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addDefaultAudioRenderDeviceChangedEvent:(void (^)(RTObject*, WMDDefaultAudioRenderDeviceChangedEventArgs*))del;
+ (void)removeDefaultAudioRenderDeviceChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WMDMediaDevice_DEFINED__

// Windows.Media.Devices.AudioDeviceController
#ifndef __WMDAudioDeviceController_DEFINED__
#define __WMDAudioDeviceController_DEFINED__

WINRT_EXPORT
@interface WMDAudioDeviceController : RTObject <WMDIMediaDeviceController>
@property float volumePercent;
@property BOOL muted;
- (NSArray*)getAvailableMediaStreamProperties:(WMCMediaStreamType)mediaStreamType;
- (RTObject<WMMIMediaEncodingProperties>*)getMediaStreamProperties:(WMCMediaStreamType)mediaStreamType;
- (RTObject<WFIAsyncAction>*)setMediaStreamPropertiesAsync:(WMCMediaStreamType)mediaStreamType
                                   mediaEncodingProperties:(RTObject<WMMIMediaEncodingProperties>*)mediaEncodingProperties;
@end

#endif // __WMDAudioDeviceController_DEFINED__

// Windows.Media.Devices.VideoDeviceController
#ifndef __WMDVideoDeviceController_DEFINED__
#define __WMDVideoDeviceController_DEFINED__

WINRT_EXPORT
@interface WMDVideoDeviceController : RTObject <WMDIMediaDeviceController>
@property WMDCaptureUse primaryUse;
@property (readonly) WMDIsoSpeedControl* isoSpeedControl;
@property (readonly) WMDFlashControl* flashControl;
@property (readonly) WMDFocusControl* focusControl;
@property (readonly) WMDWhiteBalanceControl* whiteBalanceControl;
@property (readonly) WMDTorchControl* torchControl;
@property (readonly) WMDSceneModeControl* sceneModeControl;
@property (readonly) WMDRegionsOfInterestControl* regionsOfInterestControl;
@property (readonly) WMDLowLagPhotoSequenceControl* lowLagPhotoSequence;
@property (readonly) WMDLowLagPhotoControl* lowLagPhoto;
@property (readonly) WMDExposureCompensationControl* exposureCompensationControl;
@property (readonly) WMDExposureControl* exposureControl;
@property (readonly) WMDZoomControl* zoomControl;
@property (readonly) WMDCVariablePhotoSequenceController* variablePhotoSequenceController;
@property (readonly) WMDPhotoConfirmationControl* photoConfirmationControl;
@property WMDMediaCaptureOptimization desiredOptimization;
@property (readonly) WMDHdrVideoControl* hdrVideoControl;
@property (readonly) WMDAdvancedPhotoControl* advancedPhotoControl;
@property (readonly) WMDExposurePriorityVideoControl* exposurePriorityVideoControl;
@property (readonly) WMDOpticalImageStabilizationControl* opticalImageStabilizationControl;
@property (readonly) WMDMediaDeviceControl* pan;
@property (readonly) WMDMediaDeviceControl* hue;
@property (readonly) WMDMediaDeviceControl* focus;
@property (readonly) WMDMediaDeviceControl* contrast;
@property (readonly) WMDMediaDeviceControl* brightness;
@property (readonly) WMDMediaDeviceControl* backlightCompensation;
@property (readonly) WMDMediaDeviceControl* zoom;
@property (readonly) WMDMediaDeviceControl* whiteBalance;
@property (readonly) WMDMediaDeviceControl* exposure;
@property (readonly) WMDMediaDeviceControl* tilt;
@property (readonly) WMDMediaDeviceControl* roll;
- (BOOL)trySetPowerlineFrequency:(WMCPowerlineFrequency)value;
- (BOOL)tryGetPowerlineFrequency:(WMCPowerlineFrequency*)value;
- (NSArray*)getAvailableMediaStreamProperties:(WMCMediaStreamType)mediaStreamType;
- (RTObject<WMMIMediaEncodingProperties>*)getMediaStreamProperties:(WMCMediaStreamType)mediaStreamType;
- (RTObject<WFIAsyncAction>*)setMediaStreamPropertiesAsync:(WMCMediaStreamType)mediaStreamType
                                   mediaEncodingProperties:(RTObject<WMMIMediaEncodingProperties>*)mediaEncodingProperties;
- (void)setDeviceProperty:(NSString*)propertyId propertyValue:(RTObject*)propertyValue;
- (RTObject*)getDeviceProperty:(NSString*)propertyId;
@end

#endif // __WMDVideoDeviceController_DEFINED__

// Windows.Media.Devices.SceneModeControl
#ifndef __WMDSceneModeControl_DEFINED__
#define __WMDSceneModeControl_DEFINED__

WINRT_EXPORT
@interface WMDSceneModeControl : RTObject
@property (readonly) NSArray* supportedModes;
@property (readonly) WMDCaptureSceneMode value;
- (RTObject<WFIAsyncAction>*)setValueAsync:(WMDCaptureSceneMode)sceneMode;
@end

#endif // __WMDSceneModeControl_DEFINED__

// Windows.Media.Devices.TorchControl
#ifndef __WMDTorchControl_DEFINED__
#define __WMDTorchControl_DEFINED__

WINRT_EXPORT
@interface WMDTorchControl : RTObject
@property float powerPercent;
@property BOOL enabled;
@property (readonly) BOOL powerSupported;
@property (readonly) BOOL supported;
@end

#endif // __WMDTorchControl_DEFINED__

// Windows.Media.Devices.FlashControl
#ifndef __WMDFlashControl_DEFINED__
#define __WMDFlashControl_DEFINED__

WINRT_EXPORT
@interface WMDFlashControl : RTObject
@property BOOL redEyeReduction;
@property float powerPercent;
@property BOOL enabled;
@property BOOL Auto;
@property (readonly) BOOL powerSupported;
@property (readonly) BOOL redEyeReductionSupported;
@property (readonly) BOOL supported;
@property BOOL assistantLightEnabled;
@property (readonly) BOOL assistantLightSupported;
@end

#endif // __WMDFlashControl_DEFINED__

// Windows.Media.Devices.ExposureCompensationControl
#ifndef __WMDExposureCompensationControl_DEFINED__
#define __WMDExposureCompensationControl_DEFINED__

WINRT_EXPORT
@interface WMDExposureCompensationControl : RTObject
@property (readonly) float max;
@property (readonly) float min;
@property (readonly) float step;
@property (readonly) BOOL supported;
@property (readonly) float value;
- (RTObject<WFIAsyncAction>*)setValueAsync:(float)value;
@end

#endif // __WMDExposureCompensationControl_DEFINED__

// Windows.Media.Devices.IsoSpeedControl
#ifndef __WMDIsoSpeedControl_DEFINED__
#define __WMDIsoSpeedControl_DEFINED__

WINRT_EXPORT
@interface WMDIsoSpeedControl : RTObject
@property (readonly) WMDIsoSpeedPreset preset;
@property (readonly) BOOL supported;
@property (readonly) NSArray* supportedPresets;
@property (readonly) BOOL Auto;
@property (readonly) unsigned int max;
@property (readonly) unsigned int min;
@property (readonly) unsigned int step;
@property (readonly) unsigned int value;
- (RTObject<WFIAsyncAction>*)setPresetAsync:(WMDIsoSpeedPreset)preset;
- (RTObject<WFIAsyncAction>*)setValueAsync:(unsigned int)isoSpeed;
- (RTObject<WFIAsyncAction>*)setAutoAsync;
@end

#endif // __WMDIsoSpeedControl_DEFINED__

// Windows.Media.Devices.WhiteBalanceControl
#ifndef __WMDWhiteBalanceControl_DEFINED__
#define __WMDWhiteBalanceControl_DEFINED__

WINRT_EXPORT
@interface WMDWhiteBalanceControl : RTObject
@property (readonly) unsigned int max;
@property (readonly) unsigned int min;
@property (readonly) WMDColorTemperaturePreset preset;
@property (readonly) unsigned int step;
@property (readonly) BOOL supported;
@property (readonly) unsigned int value;
- (RTObject<WFIAsyncAction>*)setPresetAsync:(WMDColorTemperaturePreset)preset;
- (RTObject<WFIAsyncAction>*)setValueAsync:(unsigned int)temperature;
@end

#endif // __WMDWhiteBalanceControl_DEFINED__

// Windows.Media.Devices.ExposureControl
#ifndef __WMDExposureControl_DEFINED__
#define __WMDExposureControl_DEFINED__

WINRT_EXPORT
@interface WMDExposureControl : RTObject
@property (readonly) BOOL Auto;
@property (readonly) WFTimeSpan* max;
@property (readonly) WFTimeSpan* min;
@property (readonly) WFTimeSpan* step;
@property (readonly) BOOL supported;
@property (readonly) WFTimeSpan* value;
- (RTObject<WFIAsyncAction>*)setAutoAsync:(BOOL)value;
- (RTObject<WFIAsyncAction>*)setValueAsync:(WFTimeSpan*)shutterDuration;
@end

#endif // __WMDExposureControl_DEFINED__

// Windows.Media.Devices.ZoomSettings
#ifndef __WMDZoomSettings_DEFINED__
#define __WMDZoomSettings_DEFINED__

WINRT_EXPORT
@interface WMDZoomSettings : RTObject
+ (instancetype)create ACTIVATOR;
@property float value;
@property WMDZoomTransitionMode mode;
@end

#endif // __WMDZoomSettings_DEFINED__

// Windows.Media.Devices.ZoomControl
#ifndef __WMDZoomControl_DEFINED__
#define __WMDZoomControl_DEFINED__

WINRT_EXPORT
@interface WMDZoomControl : RTObject
@property float value;
@property (readonly) float max;
@property (readonly) float min;
@property (readonly) float step;
@property (readonly) BOOL supported;
@property (readonly) WMDZoomTransitionMode mode;
@property (readonly) NSArray* supportedModes;
- (void)configure:(WMDZoomSettings*)settings;
@end

#endif // __WMDZoomControl_DEFINED__

// Windows.Media.Devices.FocusSettings
#ifndef __WMDFocusSettings_DEFINED__
#define __WMDFocusSettings_DEFINED__

WINRT_EXPORT
@interface WMDFocusSettings : RTObject
+ (instancetype)create ACTIVATOR;
@property BOOL waitForFocus;
@property (copy) id value;
@property WMDFocusMode mode;
@property (copy) id distance;
@property BOOL disableDriverFallback;
@property WMDAutoFocusRange autoFocusRange;
@end

#endif // __WMDFocusSettings_DEFINED__

// Windows.Media.Devices.FocusControl
#ifndef __WMDFocusControl_DEFINED__
#define __WMDFocusControl_DEFINED__

WINRT_EXPORT
@interface WMDFocusControl : RTObject
@property (readonly) unsigned int max;
@property (readonly) unsigned int min;
@property (readonly) WMDFocusPreset preset;
@property (readonly) unsigned int step;
@property (readonly) BOOL supported;
@property (readonly) NSArray* supportedPresets;
@property (readonly) unsigned int value;
@property (readonly) BOOL focusChangedSupported;
@property (readonly) WMDMediaCaptureFocusState focusState;
@property (readonly) WMDFocusMode mode;
@property (readonly) NSArray* supportedFocusDistances;
@property (readonly) NSArray* supportedFocusModes;
@property (readonly) NSArray* supportedFocusRanges;
@property (readonly) BOOL waitForFocusSupported;
- (RTObject<WFIAsyncAction>*)setPresetAsync:(WMDFocusPreset)preset;
- (RTObject<WFIAsyncAction>*)setPresetWithCompletionOptionAsync:(WMDFocusPreset)preset completeBeforeFocus:(BOOL)completeBeforeFocus;
- (RTObject<WFIAsyncAction>*)setValueAsync:(unsigned int)focus;
- (RTObject<WFIAsyncAction>*)focusAsync;
- (RTObject<WFIAsyncAction>*)unlockAsync;
- (RTObject<WFIAsyncAction>*)lockAsync;
- (void)configure:(WMDFocusSettings*)settings;
@end

#endif // __WMDFocusControl_DEFINED__

// Windows.Media.Devices.RegionOfInterest
#ifndef __WMDRegionOfInterest_DEFINED__
#define __WMDRegionOfInterest_DEFINED__

WINRT_EXPORT
@interface WMDRegionOfInterest : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) WFRect* bounds;
@property BOOL autoWhiteBalanceEnabled;
@property BOOL autoFocusEnabled;
@property BOOL autoExposureEnabled;
@property unsigned int weight;
@property WMDRegionOfInterestType type;
@property BOOL boundsNormalized;
@end

#endif // __WMDRegionOfInterest_DEFINED__

// Windows.Media.Devices.RegionsOfInterestControl
#ifndef __WMDRegionsOfInterestControl_DEFINED__
#define __WMDRegionsOfInterestControl_DEFINED__

WINRT_EXPORT
@interface WMDRegionsOfInterestControl : RTObject
@property (readonly) BOOL autoExposureSupported;
@property (readonly) BOOL autoFocusSupported;
@property (readonly) BOOL autoWhiteBalanceSupported;
@property (readonly) unsigned int maxRegions;
- (RTObject<WFIAsyncAction>*)setRegionsAsync:(id<NSFastEnumeration> /* WMDRegionOfInterest* */)regions;
- (RTObject<WFIAsyncAction>*)setRegionsWithLockAsync:(id<NSFastEnumeration> /* WMDRegionOfInterest* */)regions lockValues:(BOOL)lockValues;
- (RTObject<WFIAsyncAction>*)clearRegionsAsync;
@end

#endif // __WMDRegionsOfInterestControl_DEFINED__

// Windows.Media.Devices.ExposurePriorityVideoControl
#ifndef __WMDExposurePriorityVideoControl_DEFINED__
#define __WMDExposurePriorityVideoControl_DEFINED__

WINRT_EXPORT
@interface WMDExposurePriorityVideoControl : RTObject
@property BOOL enabled;
@property (readonly) BOOL supported;
@end

#endif // __WMDExposurePriorityVideoControl_DEFINED__

// Windows.Media.Devices.HdrVideoControl
#ifndef __WMDHdrVideoControl_DEFINED__
#define __WMDHdrVideoControl_DEFINED__

WINRT_EXPORT
@interface WMDHdrVideoControl : RTObject
@property WMDHdrVideoMode mode;
@property (readonly) BOOL supported;
@property (readonly) NSArray* supportedModes;
@end

#endif // __WMDHdrVideoControl_DEFINED__

// Windows.Media.Devices.AdvancedPhotoCaptureSettings
#ifndef __WMDAdvancedPhotoCaptureSettings_DEFINED__
#define __WMDAdvancedPhotoCaptureSettings_DEFINED__

WINRT_EXPORT
@interface WMDAdvancedPhotoCaptureSettings : RTObject
+ (instancetype)create ACTIVATOR;
@property WMDAdvancedPhotoMode mode;
@end

#endif // __WMDAdvancedPhotoCaptureSettings_DEFINED__

// Windows.Media.Devices.AdvancedPhotoControl
#ifndef __WMDAdvancedPhotoControl_DEFINED__
#define __WMDAdvancedPhotoControl_DEFINED__

WINRT_EXPORT
@interface WMDAdvancedPhotoControl : RTObject
@property (readonly) WMDAdvancedPhotoMode mode;
@property (readonly) BOOL supported;
@property (readonly) NSArray* supportedModes;
- (void)configure:(WMDAdvancedPhotoCaptureSettings*)settings;
@end

#endif // __WMDAdvancedPhotoControl_DEFINED__

// Windows.Media.Devices.OpticalImageStabilizationControl
#ifndef __WMDOpticalImageStabilizationControl_DEFINED__
#define __WMDOpticalImageStabilizationControl_DEFINED__

WINRT_EXPORT
@interface WMDOpticalImageStabilizationControl : RTObject
@property WMDOpticalImageStabilizationMode mode;
@property (readonly) BOOL supported;
@property (readonly) NSArray* supportedModes;
@end

#endif // __WMDOpticalImageStabilizationControl_DEFINED__

// Windows.Media.Devices.MediaDeviceControl
#ifndef __WMDMediaDeviceControl_DEFINED__
#define __WMDMediaDeviceControl_DEFINED__

WINRT_EXPORT
@interface WMDMediaDeviceControl : RTObject
@property (readonly) WMDMediaDeviceControlCapabilities* capabilities;
- (BOOL)tryGetValue:(double*)value;
- (BOOL)trySetValue:(double)value;
- (BOOL)tryGetAuto:(BOOL*)value;
- (BOOL)trySetAuto:(BOOL)value;
@end

#endif // __WMDMediaDeviceControl_DEFINED__

// Windows.Media.Devices.LowLagPhotoSequenceControl
#ifndef __WMDLowLagPhotoSequenceControl_DEFINED__
#define __WMDLowLagPhotoSequenceControl_DEFINED__

WINRT_EXPORT
@interface WMDLowLagPhotoSequenceControl : RTObject
@property WMMMediaThumbnailFormat thumbnailFormat;
@property BOOL thumbnailEnabled;
@property float photosPerSecondLimit;
@property unsigned int pastPhotoLimit;
@property unsigned int desiredThumbnailSize;
@property (readonly) unsigned int hardwareAcceleratedThumbnailSupported;
@property (readonly) unsigned int maxPastPhotos;
@property (readonly) float maxPhotosPerSecond;
@property (readonly) BOOL supported;
- (WMMMediaRatio*)getHighestConcurrentFrameRate:(RTObject<WMMIMediaEncodingProperties>*)captureProperties;
- (WMMMediaRatio*)getCurrentFrameRate;
@end

#endif // __WMDLowLagPhotoSequenceControl_DEFINED__

// Windows.Media.Devices.LowLagPhotoControl
#ifndef __WMDLowLagPhotoControl_DEFINED__
#define __WMDLowLagPhotoControl_DEFINED__

WINRT_EXPORT
@interface WMDLowLagPhotoControl : RTObject
@property WMMMediaThumbnailFormat thumbnailFormat;
@property BOOL thumbnailEnabled;
@property unsigned int desiredThumbnailSize;
@property (readonly) unsigned int hardwareAcceleratedThumbnailSupported;
- (WMMMediaRatio*)getHighestConcurrentFrameRate:(RTObject<WMMIMediaEncodingProperties>*)captureProperties;
- (WMMMediaRatio*)getCurrentFrameRate;
@end

#endif // __WMDLowLagPhotoControl_DEFINED__

// Windows.Media.Devices.PhotoConfirmationControl
#ifndef __WMDPhotoConfirmationControl_DEFINED__
#define __WMDPhotoConfirmationControl_DEFINED__

WINRT_EXPORT
@interface WMDPhotoConfirmationControl : RTObject
@property WMMMediaPixelFormat pixelFormat;
@property BOOL enabled;
@property (readonly) BOOL supported;
@end

#endif // __WMDPhotoConfirmationControl_DEFINED__

// Windows.Media.Devices.MediaDeviceControlCapabilities
#ifndef __WMDMediaDeviceControlCapabilities_DEFINED__
#define __WMDMediaDeviceControlCapabilities_DEFINED__

WINRT_EXPORT
@interface WMDMediaDeviceControlCapabilities : RTObject
@property (readonly) BOOL autoModeSupported;
@property (readonly) double Default;
@property (readonly) double max;
@property (readonly) double min;
@property (readonly) double step;
@property (readonly) BOOL supported;
@end

#endif // __WMDMediaDeviceControlCapabilities_DEFINED__
