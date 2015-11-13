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
@class WMDDialRequestedEventArgs, WMDRedialRequestedEventArgs, WMDKeypadPressedEventArgs, WMDCallControl,
    WMDDefaultAudioCaptureDeviceChangedEventArgs, WMDDefaultAudioRenderDeviceChangedEventArgs, WMDMediaDevice, WMDAudioDeviceController,
    WMDVideoDeviceController, WMDSceneModeControl, WMDTorchControl, WMDFlashControl, WMDExposureCompensationControl, WMDIsoSpeedControl,
    WMDWhiteBalanceControl, WMDExposureControl, WMDFocusControl, WMDRegionOfInterest, WMDRegionsOfInterestControl, WMDMediaDeviceControl,
    WMDLowLagPhotoSequenceControl, WMDLowLagPhotoControl, WMDMediaDeviceControlCapabilities;
@protocol WMDIDialRequestedEventArgs
, WMDIRedialRequestedEventArgs, WMDIKeypadPressedEventArgs, WMDICallControl, WMDICallControlStatics, WMDIDefaultAudioDeviceChangedEventArgs,
    WMDIMediaDeviceStatics, WMDISceneModeControl, WMDITorchControl, WMDIFlashControl, WMDIExposureCompensationControl, WMDIIsoSpeedControl,
    WMDIWhiteBalanceControl, WMDIExposureControl, WMDIFocusControl, WMDIRegionOfInterest, WMDIRegionsOfInterestControl,
    WMDIMediaDeviceController, WMDIAudioDeviceController, WMDIVideoDeviceController, WMDIAdvancedVideoCaptureDeviceController2,
    WMDIMediaDeviceControl, WMDIMediaDeviceControlCapabilities, WMDIAdvancedVideoCaptureDeviceController, WMDILowLagPhotoSequenceControl,
    WMDILowLagPhotoControl;

// Windows.Media.Devices.TelephonyKey
enum _WMDTelephonyKey {
    WMDTelephonyKeyD0 = 0,
    WMDTelephonyKeyD1 = 1,
    WMDTelephonyKeyD2 = 2,
    WMDTelephonyKeyD3 = 3,
    WMDTelephonyKeyD4 = 4,
    WMDTelephonyKeyD5 = 5,
    WMDTelephonyKeyD6 = 6,
    WMDTelephonyKeyD7 = 7,
    WMDTelephonyKeyD8 = 8,
    WMDTelephonyKeyD9 = 9,
    WMDTelephonyKeyStar = 10,
    WMDTelephonyKeyPound = 11,
    WMDTelephonyKeyA = 12,
    WMDTelephonyKeyB = 13,
    WMDTelephonyKeyC = 14,
    WMDTelephonyKeyD = 15,
};
typedef unsigned WMDTelephonyKey;

// Windows.Media.Devices.AudioDeviceRole
enum _WMDAudioDeviceRole {
    WMDAudioDeviceRoleDefault = 0,
    WMDAudioDeviceRoleCommunications = 1,
};
typedef unsigned WMDAudioDeviceRole;

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

// Windows.Media.Devices.CaptureUse
enum _WMDCaptureUse {
    WMDCaptureUseNone = 0,
    WMDCaptureUsePhoto = 1,
    WMDCaptureUseVideo = 2,
};
typedef unsigned WMDCaptureUse;

#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"
#include "WindowsMediaCapture.h"
#include "WindowsMediaMediaProperties.h"
// Windows.Media.Devices.CallControlEventHandler
#ifndef __WMDCallControlEventHandler__DEFINED
#define __WMDCallControlEventHandler__DEFINED
typedef void (^WMDCallControlEventHandler)(WMDCallControl* sender);
#endif // __WMDCallControlEventHandler__DEFINED

// Windows.Media.Devices.DialRequestedEventHandler
#ifndef __WMDDialRequestedEventHandler__DEFINED
#define __WMDDialRequestedEventHandler__DEFINED
typedef void (^WMDDialRequestedEventHandler)(WMDCallControl* sender, WMDDialRequestedEventArgs* e);
#endif // __WMDDialRequestedEventHandler__DEFINED

// Windows.Media.Devices.KeypadPressedEventHandler
#ifndef __WMDKeypadPressedEventHandler__DEFINED
#define __WMDKeypadPressedEventHandler__DEFINED
typedef void (^WMDKeypadPressedEventHandler)(WMDCallControl* sender, WMDKeypadPressedEventArgs* e);
#endif // __WMDKeypadPressedEventHandler__DEFINED

// Windows.Media.Devices.RedialRequestedEventHandler
#ifndef __WMDRedialRequestedEventHandler__DEFINED
#define __WMDRedialRequestedEventHandler__DEFINED
typedef void (^WMDRedialRequestedEventHandler)(WMDCallControl* sender, WMDRedialRequestedEventArgs* e);
#endif // __WMDRedialRequestedEventHandler__DEFINED

#import <Foundation/Foundation.h>

// Windows.Media.Devices.CallControlEventHandler
#ifndef __WMDCallControlEventHandler__DEFINED
#define __WMDCallControlEventHandler__DEFINED
typedef void (^WMDCallControlEventHandler)(WMDCallControl* sender);
#endif // __WMDCallControlEventHandler__DEFINED

// Windows.Media.Devices.DialRequestedEventHandler
#ifndef __WMDDialRequestedEventHandler__DEFINED
#define __WMDDialRequestedEventHandler__DEFINED
typedef void (^WMDDialRequestedEventHandler)(WMDCallControl* sender, WMDDialRequestedEventArgs* e);
#endif // __WMDDialRequestedEventHandler__DEFINED

// Windows.Media.Devices.RedialRequestedEventHandler
#ifndef __WMDRedialRequestedEventHandler__DEFINED
#define __WMDRedialRequestedEventHandler__DEFINED
typedef void (^WMDRedialRequestedEventHandler)(WMDCallControl* sender, WMDRedialRequestedEventArgs* e);
#endif // __WMDRedialRequestedEventHandler__DEFINED

// Windows.Media.Devices.KeypadPressedEventHandler
#ifndef __WMDKeypadPressedEventHandler__DEFINED
#define __WMDKeypadPressedEventHandler__DEFINED
typedef void (^WMDKeypadPressedEventHandler)(WMDCallControl* sender, WMDKeypadPressedEventArgs* e);
#endif // __WMDKeypadPressedEventHandler__DEFINED

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
- (id<NSFastEnumeration> /*WMMIMediaEncodingProperties*/)getAvailableMediaStreamProperties:(WMCMediaStreamType)mediaStreamType;
- (RTObject<WMMIMediaEncodingProperties>*)getMediaStreamProperties:(WMCMediaStreamType)mediaStreamType;
- (RTObject<WFIAsyncAction>*)setMediaStreamPropertiesAsync:(WMCMediaStreamType)mediaStreamType
                                   mediaEncodingProperties:(RTObject<WMMIMediaEncodingProperties>*)mediaEncodingProperties;
@end

#endif // __WMDIMediaDeviceController_DEFINED__

// Windows.Media.Devices.DialRequestedEventArgs
#ifndef __WMDDialRequestedEventArgs_DEFINED__
#define __WMDDialRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMDDialRequestedEventArgs : RTObject
@property (readonly) RTObject* contact;
- (void)handled;
@end

#endif // __WMDDialRequestedEventArgs_DEFINED__

// Windows.Media.Devices.RedialRequestedEventArgs
#ifndef __WMDRedialRequestedEventArgs_DEFINED__
#define __WMDRedialRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMDRedialRequestedEventArgs : RTObject
- (void)handled;
@end

#endif // __WMDRedialRequestedEventArgs_DEFINED__

// Windows.Media.Devices.KeypadPressedEventArgs
#ifndef __WMDKeypadPressedEventArgs_DEFINED__
#define __WMDKeypadPressedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMDKeypadPressedEventArgs : RTObject
@property (readonly) WMDTelephonyKey telephonyKey;
@end

#endif // __WMDKeypadPressedEventArgs_DEFINED__

// Windows.Media.Devices.CallControl
#ifndef __WMDCallControl_DEFINED__
#define __WMDCallControl_DEFINED__

WINRT_EXPORT
@interface WMDCallControl : RTObject
+ (WMDCallControl*)getDefault;
+ (WMDCallControl*)fromId:(NSString*)deviceId;
@property (readonly) BOOL hasRinger;
- (EventRegistrationToken)addAnswerRequestedEvent:(WMDCallControlEventHandler)del;
- (void)removeAnswerRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAudioTransferRequestedEvent:(WMDCallControlEventHandler)del;
- (void)removeAudioTransferRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDialRequestedEvent:(WMDDialRequestedEventHandler)del;
- (void)removeDialRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addHangUpRequestedEvent:(WMDCallControlEventHandler)del;
- (void)removeHangUpRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addKeypadPressedEvent:(WMDKeypadPressedEventHandler)del;
- (void)removeKeypadPressedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRedialRequestedEvent:(WMDRedialRequestedEventHandler)del;
- (void)removeRedialRequestedEvent:(EventRegistrationToken)tok;
- (uint64_t)indicateNewIncomingCall:(BOOL)enableRinger callerId:(NSString*)callerId;
- (uint64_t)indicateNewOutgoingCall;
- (void)indicateActiveCall:(uint64_t)callToken;
- (void)endCall:(uint64_t)callToken;
@end

#endif // __WMDCallControl_DEFINED__

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
- (id<NSFastEnumeration> /*WMMIMediaEncodingProperties*/)getAvailableMediaStreamProperties:(WMCMediaStreamType)mediaStreamType;
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
@property (readonly) WMDWhiteBalanceControl* whiteBalanceControl;
@property (readonly) WMDExposureCompensationControl* exposureCompensationControl;
@property (readonly) WMDExposureControl* exposureControl;
@property (readonly) WMDFlashControl* flashControl;
@property (readonly) WMDFocusControl* focusControl;
@property (readonly) WMDIsoSpeedControl* isoSpeedControl;
@property (readonly) WMDLowLagPhotoControl* lowLagPhoto;
@property (readonly) WMDLowLagPhotoSequenceControl* lowLagPhotoSequence;
@property (readonly) WMDRegionsOfInterestControl* regionsOfInterestControl;
@property (readonly) WMDSceneModeControl* sceneModeControl;
@property (readonly) WMDTorchControl* torchControl;
@property (readonly) WMDMediaDeviceControl* pan;
@property (readonly) WMDMediaDeviceControl* roll;
@property (readonly) WMDMediaDeviceControl* whiteBalance;
@property (readonly) WMDMediaDeviceControl* zoom;
@property (readonly) WMDMediaDeviceControl* backlightCompensation;
@property (readonly) WMDMediaDeviceControl* brightness;
@property (readonly) WMDMediaDeviceControl* contrast;
@property (readonly) WMDMediaDeviceControl* exposure;
@property (readonly) WMDMediaDeviceControl* focus;
@property (readonly) WMDMediaDeviceControl* hue;
@property (readonly) WMDMediaDeviceControl* tilt;
- (BOOL)trySetPowerlineFrequency:(WMCPowerlineFrequency)value;
- (BOOL)tryGetPowerlineFrequency:(WMCPowerlineFrequency*)value;
- (id<NSFastEnumeration> /*WMMIMediaEncodingProperties*/)getAvailableMediaStreamProperties:(WMCMediaStreamType)mediaStreamType;
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
@property (readonly) id<NSFastEnumeration> /*WMDCaptureSceneMode*/ supportedModes;
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
@property (readonly) id<NSFastEnumeration> /*WMDIsoSpeedPreset*/ supportedPresets;
- (RTObject<WFIAsyncAction>*)setPresetAsync:(WMDIsoSpeedPreset)preset;
@end

#endif // __WMDIsoSpeedControl_DEFINED__

// Windows.Media.Devices.WhiteBalanceControl
#ifndef __WMDWhiteBalanceControl_DEFINED__
#define __WMDWhiteBalanceControl_DEFINED__

WINRT_EXPORT
@interface WMDWhiteBalanceControl : RTObject
@property (readonly) unsigned max;
@property (readonly) unsigned min;
@property (readonly) WMDColorTemperaturePreset preset;
@property (readonly) unsigned step;
@property (readonly) BOOL supported;
@property (readonly) unsigned value;
- (RTObject<WFIAsyncAction>*)setPresetAsync:(WMDColorTemperaturePreset)preset;
- (RTObject<WFIAsyncAction>*)setValueAsync:(unsigned)temperature;
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

// Windows.Media.Devices.FocusControl
#ifndef __WMDFocusControl_DEFINED__
#define __WMDFocusControl_DEFINED__

WINRT_EXPORT
@interface WMDFocusControl : RTObject
@property (readonly) unsigned max;
@property (readonly) unsigned min;
@property (readonly) WMDFocusPreset preset;
@property (readonly) unsigned step;
@property (readonly) BOOL supported;
@property (readonly) id<NSFastEnumeration> /*WMDFocusPreset*/ supportedPresets;
@property (readonly) unsigned value;
- (RTObject<WFIAsyncAction>*)setPresetAsync:(WMDFocusPreset)preset;
- (RTObject<WFIAsyncAction>*)setPresetWithCompletionOptionAsync:(WMDFocusPreset)preset completeBeforeFocus:(BOOL)completeBeforeFocus;
- (RTObject<WFIAsyncAction>*)setValueAsync:(unsigned)focus;
- (RTObject<WFIAsyncAction>*)focusAsync;
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
@property (readonly) unsigned maxRegions;
- (RTObject<WFIAsyncAction>*)setRegionsAsync:(id<NSFastEnumeration> /*WMDRegionOfInterest*/)regions;
- (RTObject<WFIAsyncAction>*)setRegionsWithLockAsync:(id<NSFastEnumeration> /*WMDRegionOfInterest*/)regions lockValues:(BOOL)lockValues;
- (RTObject<WFIAsyncAction>*)clearRegionsAsync;
@end

#endif // __WMDRegionsOfInterestControl_DEFINED__

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
@property unsigned pastPhotoLimit;
@property unsigned desiredThumbnailSize;
@property (readonly) unsigned hardwareAcceleratedThumbnailSupported;
@property (readonly) unsigned maxPastPhotos;
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
@property unsigned desiredThumbnailSize;
@property (readonly) unsigned hardwareAcceleratedThumbnailSupported;
- (WMMMediaRatio*)getHighestConcurrentFrameRate:(RTObject<WMMIMediaEncodingProperties>*)captureProperties;
- (WMMMediaRatio*)getCurrentFrameRate;
@end

#endif // __WMDLowLagPhotoControl_DEFINED__

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
