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

// WindowsMediaCapture.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WMCCameraCaptureUIPhotoCaptureSettings, WMCCameraCaptureUIVideoCaptureSettings, WMCCameraCaptureUI, WMCMediaCaptureFailedEventArgs,
    WMCMediaCapture, WMCMediaCaptureVideoProfileMediaDescription, WMCMediaCaptureVideoProfile, WMCMediaCaptureInitializationSettings,
    WMCMediaCaptureSettings, WMCLowLagMediaRecording, WMCLowLagPhotoCapture, WMCLowLagPhotoSequenceCapture,
    WMCMediaCaptureFocusChangedEventArgs, WMCPhotoConfirmationCapturedEventArgs, WMCAdvancedPhotoCapture, WMCCapturedPhoto,
    WMCAdvancedCapturedPhoto, WMCOptionalReferencePhotoCapturedEventArgs, WMCCapturedFrame, WMCPhotoCapturedEventArgs,
    WMCCapturedFrameControlValues, WMCVideoStreamConfiguration;
@class WMCWhiteBalanceGain;
@protocol WMCICameraCaptureUIPhotoCaptureSettings
, WMCICameraCaptureUIVideoCaptureSettings, WMCICameraCaptureUI, WMCIMediaCaptureFailedEventArgs,
    WMCIMediaCaptureVideoProfileMediaDescription, WMCIMediaCaptureVideoProfile, WMCIMediaCaptureInitializationSettings,
    WMCIMediaCaptureInitializationSettings2, WMCIMediaCaptureInitializationSettings3, WMCIMediaCaptureInitializationSettings4,
    WMCIMediaCaptureStatics, WMCIMediaCapture, WMCIMediaCapture2, WMCIMediaCapture3, WMCIMediaCapture4, WMCILowLagPhotoCapture,
    WMCIAdvancedPhotoCapture, WMCIAdvancedCapturedPhoto, WMCIOptionalReferencePhotoCapturedEventArgs, WMCILowLagMediaRecording,
    WMCILowLagMediaRecording2, WMCILowLagPhotoSequenceCapture, WMCICapturedFrameControlValues, WMCICapturedFrameControlValues2,
    WMCIPhotoCapturedEventArgs, WMCICapturedPhoto, WMCICapturedFrame, WMCICapturedFrameWithSoftwareBitmap, WMCIMediaCaptureVideoPreview,
    WMCIMediaCaptureSettings, WMCIMediaCaptureSettings2, WMCIMediaCaptureFocusChangedEventArgs, WMCIPhotoConfirmationCapturedEventArgs,
    WMCIVideoStreamConfiguration;

// Windows.Media.Capture.CameraCaptureUIMode
enum _WMCCameraCaptureUIMode {
    WMCCameraCaptureUIModePhotoOrVideo = 0,
    WMCCameraCaptureUIModePhoto = 1,
    WMCCameraCaptureUIModeVideo = 2,
};
typedef unsigned WMCCameraCaptureUIMode;

// Windows.Media.Capture.CameraCaptureUIPhotoFormat
enum _WMCCameraCaptureUIPhotoFormat {
    WMCCameraCaptureUIPhotoFormatJpeg = 0,
    WMCCameraCaptureUIPhotoFormatPng = 1,
    WMCCameraCaptureUIPhotoFormatJpegXR = 2,
};
typedef unsigned WMCCameraCaptureUIPhotoFormat;

// Windows.Media.Capture.CameraCaptureUIVideoFormat
enum _WMCCameraCaptureUIVideoFormat {
    WMCCameraCaptureUIVideoFormatMp4 = 0,
    WMCCameraCaptureUIVideoFormatWmv = 1,
};
typedef unsigned WMCCameraCaptureUIVideoFormat;

// Windows.Media.Capture.CameraCaptureUIMaxVideoResolution
enum _WMCCameraCaptureUIMaxVideoResolution {
    WMCCameraCaptureUIMaxVideoResolutionHighestAvailable = 0,
    WMCCameraCaptureUIMaxVideoResolutionLowDefinition = 1,
    WMCCameraCaptureUIMaxVideoResolutionStandardDefinition = 2,
    WMCCameraCaptureUIMaxVideoResolutionHighDefinition = 3,
};
typedef unsigned WMCCameraCaptureUIMaxVideoResolution;

// Windows.Media.Capture.CameraCaptureUIMaxPhotoResolution
enum _WMCCameraCaptureUIMaxPhotoResolution {
    WMCCameraCaptureUIMaxPhotoResolutionHighestAvailable = 0,
    WMCCameraCaptureUIMaxPhotoResolutionVerySmallQvga = 1,
    WMCCameraCaptureUIMaxPhotoResolutionSmallVga = 2,
    WMCCameraCaptureUIMaxPhotoResolutionMediumXga = 3,
    WMCCameraCaptureUIMaxPhotoResolutionLarge3M = 4,
    WMCCameraCaptureUIMaxPhotoResolutionVeryLarge5M = 5,
};
typedef unsigned WMCCameraCaptureUIMaxPhotoResolution;

// Windows.Media.Capture.MediaCategory
enum _WMCMediaCategory {
    WMCMediaCategoryOther = 0,
    WMCMediaCategoryCommunications = 1,
    WMCMediaCategoryMedia = 2,
    WMCMediaCategoryGameChat = 3,
    WMCMediaCategorySpeech = 4,
};
typedef unsigned WMCMediaCategory;

// Windows.Media.Capture.MediaStreamType
enum _WMCMediaStreamType {
    WMCMediaStreamTypeVideoPreview = 0,
    WMCMediaStreamTypeVideoRecord = 1,
    WMCMediaStreamTypeAudio = 2,
    WMCMediaStreamTypePhoto = 3,
};
typedef unsigned WMCMediaStreamType;

// Windows.Media.Capture.StreamingCaptureMode
enum _WMCStreamingCaptureMode {
    WMCStreamingCaptureModeAudioAndVideo = 0,
    WMCStreamingCaptureModeAudio = 1,
    WMCStreamingCaptureModeVideo = 2,
};
typedef unsigned WMCStreamingCaptureMode;

// Windows.Media.Capture.VideoRotation
enum _WMCVideoRotation {
    WMCVideoRotationNone = 0,
    WMCVideoRotationClockwise90Degrees = 1,
    WMCVideoRotationClockwise180Degrees = 2,
    WMCVideoRotationClockwise270Degrees = 3,
};
typedef unsigned WMCVideoRotation;

// Windows.Media.Capture.PhotoCaptureSource
enum _WMCPhotoCaptureSource {
    WMCPhotoCaptureSourceAuto = 0,
    WMCPhotoCaptureSourceVideoPreview = 1,
    WMCPhotoCaptureSourcePhoto = 2,
};
typedef unsigned WMCPhotoCaptureSource;

// Windows.Media.Capture.VideoDeviceCharacteristic
enum _WMCVideoDeviceCharacteristic {
    WMCVideoDeviceCharacteristicAllStreamsIndependent = 0,
    WMCVideoDeviceCharacteristicPreviewRecordStreamsIdentical = 1,
    WMCVideoDeviceCharacteristicPreviewPhotoStreamsIdentical = 2,
    WMCVideoDeviceCharacteristicRecordPhotoStreamsIdentical = 3,
    WMCVideoDeviceCharacteristicAllStreamsIdentical = 4,
};
typedef unsigned WMCVideoDeviceCharacteristic;

// Windows.Media.Capture.PowerlineFrequency
enum _WMCPowerlineFrequency {
    WMCPowerlineFrequencyDisabled = 0,
    WMCPowerlineFrequencyFiftyHertz = 1,
    WMCPowerlineFrequencySixtyHertz = 2,
};
typedef unsigned WMCPowerlineFrequency;

// Windows.Media.Capture.MediaCaptureThermalStatus
enum _WMCMediaCaptureThermalStatus {
    WMCMediaCaptureThermalStatusNormal = 0,
    WMCMediaCaptureThermalStatusOverheated = 1,
};
typedef unsigned WMCMediaCaptureThermalStatus;

// Windows.Media.Capture.KnownVideoProfile
enum _WMCKnownVideoProfile {
    WMCKnownVideoProfileVideoRecording = 0,
    WMCKnownVideoProfileHighQualityPhoto = 1,
    WMCKnownVideoProfileBalancedVideoAndPhoto = 2,
    WMCKnownVideoProfileVideoConferencing = 3,
    WMCKnownVideoProfilePhotoSequence = 4,
};
typedef unsigned WMCKnownVideoProfile;

#include "WindowsMediaCaptureCore.h"
#include "WindowsFoundation.h"
#include "WindowsMediaDevices.h"
#include "WindowsMediaCore.h"
#include "WindowsStorage.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"
#include "WindowsMedia.h"
#include "WindowsMediaMediaProperties.h"
#include "WindowsMediaEffects.h"
#include "WindowsGraphicsImaging.h"
// Windows.Media.Capture.MediaCaptureFailedEventHandler
#ifndef __WMCMediaCaptureFailedEventHandler__DEFINED
#define __WMCMediaCaptureFailedEventHandler__DEFINED
typedef void (^WMCMediaCaptureFailedEventHandler)(WMCMediaCapture* sender, WMCMediaCaptureFailedEventArgs* errorEventArgs);
#endif // __WMCMediaCaptureFailedEventHandler__DEFINED

// Windows.Media.Capture.RecordLimitationExceededEventHandler
#ifndef __WMCRecordLimitationExceededEventHandler__DEFINED
#define __WMCRecordLimitationExceededEventHandler__DEFINED
typedef void (^WMCRecordLimitationExceededEventHandler)(WMCMediaCapture* sender);
#endif // __WMCRecordLimitationExceededEventHandler__DEFINED

#import <Foundation/Foundation.h>

// [struct] Windows.Media.Capture.WhiteBalanceGain
WINRT_EXPORT
@interface WMCWhiteBalanceGain : NSObject
+ (instancetype) new;
@property double r;
@property double g;
@property double b;
@end

// Windows.Media.Capture.MediaCaptureFailedEventHandler
#ifndef __WMCMediaCaptureFailedEventHandler__DEFINED
#define __WMCMediaCaptureFailedEventHandler__DEFINED
typedef void (^WMCMediaCaptureFailedEventHandler)(WMCMediaCapture* sender, WMCMediaCaptureFailedEventArgs* errorEventArgs);
#endif // __WMCMediaCaptureFailedEventHandler__DEFINED

// Windows.Media.Capture.RecordLimitationExceededEventHandler
#ifndef __WMCRecordLimitationExceededEventHandler__DEFINED
#define __WMCRecordLimitationExceededEventHandler__DEFINED
typedef void (^WMCRecordLimitationExceededEventHandler)(WMCMediaCapture* sender);
#endif // __WMCRecordLimitationExceededEventHandler__DEFINED

// Windows.Media.Capture.CameraCaptureUIPhotoCaptureSettings
#ifndef __WMCCameraCaptureUIPhotoCaptureSettings_DEFINED__
#define __WMCCameraCaptureUIPhotoCaptureSettings_DEFINED__

WINRT_EXPORT
@interface WMCCameraCaptureUIPhotoCaptureSettings : RTObject
@property WMCCameraCaptureUIMaxPhotoResolution maxResolution;
@property WMCCameraCaptureUIPhotoFormat format;
@property (copy) WFSize* croppedSizeInPixels;
@property (copy) WFSize* croppedAspectRatio;
@property BOOL allowCropping;
@end

#endif // __WMCCameraCaptureUIPhotoCaptureSettings_DEFINED__

// Windows.Media.Capture.CameraCaptureUIVideoCaptureSettings
#ifndef __WMCCameraCaptureUIVideoCaptureSettings_DEFINED__
#define __WMCCameraCaptureUIVideoCaptureSettings_DEFINED__

WINRT_EXPORT
@interface WMCCameraCaptureUIVideoCaptureSettings : RTObject
@property WMCCameraCaptureUIMaxVideoResolution maxResolution;
@property float maxDurationInSeconds;
@property WMCCameraCaptureUIVideoFormat format;
@property BOOL allowTrimming;
@end

#endif // __WMCCameraCaptureUIVideoCaptureSettings_DEFINED__

// Windows.Media.Capture.CameraCaptureUI
#ifndef __WMCCameraCaptureUI_DEFINED__
#define __WMCCameraCaptureUI_DEFINED__

WINRT_EXPORT
@interface WMCCameraCaptureUI : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) WMCCameraCaptureUIPhotoCaptureSettings* photoSettings;
@property (readonly) WMCCameraCaptureUIVideoCaptureSettings* videoSettings;
- (void)captureFileAsync:(WMCCameraCaptureUIMode)mode success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WMCCameraCaptureUI_DEFINED__

// Windows.Media.Capture.MediaCaptureFailedEventArgs
#ifndef __WMCMediaCaptureFailedEventArgs_DEFINED__
#define __WMCMediaCaptureFailedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMCMediaCaptureFailedEventArgs : RTObject
@property (readonly) unsigned int code;
@property (readonly) NSString* message;
@end

#endif // __WMCMediaCaptureFailedEventArgs_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

// Windows.Media.Capture.MediaCapture
#ifndef __WMCMediaCapture_DEFINED__
#define __WMCMediaCapture_DEFINED__

WINRT_EXPORT
@interface WMCMediaCapture : RTObject <WFIClosable>
+ (BOOL)isVideoProfileSupported:(NSString*)videoDeviceId;
+ (NSArray*)findAllVideoProfiles:(NSString*)videoDeviceId;
+ (NSArray*)findConcurrentProfiles:(NSString*)videoDeviceId;
+ (NSArray*)findKnownVideoProfiles:(NSString*)videoDeviceId name:(WMCKnownVideoProfile)name;
+ (instancetype)create ACTIVATOR;
@property (readonly) WMDAudioDeviceController* audioDeviceController;
@property (readonly) WMCMediaCaptureSettings* mediaCaptureSettings;
@property (readonly) WMDVideoDeviceController* videoDeviceController;
@property (readonly) WMDCameraStreamState cameraStreamState;
@property (readonly) WMCMediaCaptureThermalStatus thermalStatus;
- (EventRegistrationToken)addFailedEvent:(WMCMediaCaptureFailedEventHandler)del;
- (void)removeFailedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRecordLimitationExceededEvent:(WMCRecordLimitationExceededEventHandler)del;
- (void)removeRecordLimitationExceededEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addFocusChangedEvent:(void (^)(WMCMediaCapture*, WMCMediaCaptureFocusChangedEventArgs*))del;
- (void)removeFocusChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPhotoConfirmationCapturedEvent:(void (^)(WMCMediaCapture*, WMCPhotoConfirmationCapturedEventArgs*))del;
- (void)removePhotoConfirmationCapturedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCameraStreamStateChangedEvent:(void (^)(WMCMediaCapture*, RTObject*))del;
- (void)removeCameraStreamStateChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addThermalStatusChangedEvent:(void (^)(WMCMediaCapture*, RTObject*))del;
- (void)removeThermalStatusChangedEvent:(EventRegistrationToken)tok;
- (RTObject<WFIAsyncAction>*)initializeAsync;
- (RTObject<WFIAsyncAction>*)initializeWithSettingsAsync:(WMCMediaCaptureInitializationSettings*)mediaCaptureInitializationSettings;
- (RTObject<WFIAsyncAction>*)startRecordToStorageFileAsync:(WMMMediaEncodingProfile*)encodingProfile file:(RTObject<WSIStorageFile>*)file;
- (RTObject<WFIAsyncAction>*)startRecordToStreamAsync:(WMMMediaEncodingProfile*)encodingProfile
                                               stream:(RTObject<WSSIRandomAccessStream>*)stream;
- (RTObject<WFIAsyncAction>*)startRecordToCustomSinkAsync:(WMMMediaEncodingProfile*)encodingProfile
                                          customMediaSink:(RTObject<WMIMediaExtension>*)customMediaSink;
- (RTObject<WFIAsyncAction>*)startRecordToCustomSinkIdAsync:(WMMMediaEncodingProfile*)encodingProfile
                                     customSinkActivationId:(NSString*)customSinkActivationId
                                         customSinkSettings:(RTObject<WFCIPropertySet>*)customSinkSettings;
- (RTObject<WFIAsyncAction>*)stopRecordAsync;
- (RTObject<WFIAsyncAction>*)capturePhotoToStorageFileAsync:(WMMImageEncodingProperties*)type file:(RTObject<WSIStorageFile>*)file;
- (RTObject<WFIAsyncAction>*)capturePhotoToStreamAsync:(WMMImageEncodingProperties*)type stream:(RTObject<WSSIRandomAccessStream>*)stream;
- (RTObject<WFIAsyncAction>*)addEffectAsync:(WMCMediaStreamType)mediaStreamType
                         effectActivationID:(NSString*)effectActivationID
                             effectSettings:(RTObject<WFCIPropertySet>*)effectSettings;
- (RTObject<WFIAsyncAction>*)clearEffectsAsync:(WMCMediaStreamType)mediaStreamType;
- (void)setEncoderProperty:(WMCMediaStreamType)mediaStreamType propertyId:(WFGUID*)propertyId propertyValue:(RTObject*)propertyValue;
- (RTObject*)getEncoderProperty:(WMCMediaStreamType)mediaStreamType propertyId:(WFGUID*)propertyId;
- (void)setPreviewMirroring:(BOOL)value;
- (BOOL)getPreviewMirroring;
- (void)setPreviewRotation:(WMCVideoRotation)value;
- (WMCVideoRotation)getPreviewRotation;
- (void)setRecordRotation:(WMCVideoRotation)value;
- (WMCVideoRotation)getRecordRotation;
- (RTObject<WFIAsyncAction>*)startPreviewAsync;
- (RTObject<WFIAsyncAction>*)startPreviewToCustomSinkAsync:(WMMMediaEncodingProfile*)encodingProfile
                                           customMediaSink:(RTObject<WMIMediaExtension>*)customMediaSink;
- (RTObject<WFIAsyncAction>*)startPreviewToCustomSinkIdAsync:(WMMMediaEncodingProfile*)encodingProfile
                                      customSinkActivationId:(NSString*)customSinkActivationId
                                          customSinkSettings:(RTObject<WFCIPropertySet>*)customSinkSettings;
- (RTObject<WFIAsyncAction>*)stopPreviewAsync;
- (void)prepareLowLagRecordToStorageFileAsync:(WMMMediaEncodingProfile*)encodingProfile
                                         file:(RTObject<WSIStorageFile>*)file
                                      success:(void (^)(WMCLowLagMediaRecording*))success
                                      failure:(void (^)(NSError*))failure;
- (void)prepareLowLagRecordToStreamAsync:(WMMMediaEncodingProfile*)encodingProfile
                                  stream:(RTObject<WSSIRandomAccessStream>*)stream
                                 success:(void (^)(WMCLowLagMediaRecording*))success
                                 failure:(void (^)(NSError*))failure;
- (void)prepareLowLagRecordToCustomSinkAsync:(WMMMediaEncodingProfile*)encodingProfile
                             customMediaSink:(RTObject<WMIMediaExtension>*)customMediaSink
                                     success:(void (^)(WMCLowLagMediaRecording*))success
                                     failure:(void (^)(NSError*))failure;
- (void)prepareLowLagRecordToCustomSinkIdAsync:(WMMMediaEncodingProfile*)encodingProfile
                        customSinkActivationId:(NSString*)customSinkActivationId
                            customSinkSettings:(RTObject<WFCIPropertySet>*)customSinkSettings
                                       success:(void (^)(WMCLowLagMediaRecording*))success
                                       failure:(void (^)(NSError*))failure;
- (void)prepareLowLagPhotoCaptureAsync:(WMMImageEncodingProperties*)type
                               success:(void (^)(WMCLowLagPhotoCapture*))success
                               failure:(void (^)(NSError*))failure;
- (void)prepareLowLagPhotoSequenceCaptureAsync:(WMMImageEncodingProperties*)type
                                       success:(void (^)(WMCLowLagPhotoSequenceCapture*))success
                                       failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)setEncodingPropertiesAsync:(WMCMediaStreamType)mediaStreamType
                                mediaEncodingProperties:(RTObject<WMMIMediaEncodingProperties>*)mediaEncodingProperties
                                      encoderProperties:(WMMMediaPropertySet*)encoderProperties;
- (void)close;
- (void)prepareVariablePhotoSequenceCaptureAsync:(WMMImageEncodingProperties*)type
                                         success:(void (^)(WMCCVariablePhotoSequenceCapture*))success
                                         failure:(void (^)(NSError*))failure;
- (void)addAudioEffectAsync:(RTObject<WMEIAudioEffectDefinition>*)definition
                    success:(void (^)(RTObject<WMIMediaExtension>*))success
                    failure:(void (^)(NSError*))failure;
- (void)addVideoEffectAsync:(RTObject<WMEIVideoEffectDefinition>*)definition
            mediaStreamType:(WMCMediaStreamType)mediaStreamType
                    success:(void (^)(RTObject<WMIMediaExtension>*))success
                    failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)pauseRecordAsync:(WMDMediaCapturePauseBehavior)behavior;
- (RTObject<WFIAsyncAction>*)resumeRecordAsync;
- (void)getPreviewFrameAsyncWithSuccess:(void (^)(WMVideoFrame*))success failure:(void (^)(NSError*))failure;
- (void)getPreviewFrameCopyAsync:(WMVideoFrame*)destination success:(void (^)(WMVideoFrame*))success failure:(void (^)(NSError*))failure;
- (void)prepareAdvancedPhotoCaptureAsync:(WMMImageEncodingProperties*)encodingProperties
                                 success:(void (^)(WMCAdvancedPhotoCapture*))success
                                 failure:(void (^)(NSError*))failure;
@end

#endif // __WMCMediaCapture_DEFINED__

// Windows.Media.Capture.MediaCaptureVideoProfileMediaDescription
#ifndef __WMCMediaCaptureVideoProfileMediaDescription_DEFINED__
#define __WMCMediaCaptureVideoProfileMediaDescription_DEFINED__

WINRT_EXPORT
@interface WMCMediaCaptureVideoProfileMediaDescription : RTObject
@property (readonly) double frameRate;
@property (readonly) unsigned int height;
@property (readonly) BOOL isHdrVideoSupported;
@property (readonly) BOOL isVariablePhotoSequenceSupported;
@property (readonly) unsigned int width;
@end

#endif // __WMCMediaCaptureVideoProfileMediaDescription_DEFINED__

// Windows.Media.Capture.MediaCaptureVideoProfile
#ifndef __WMCMediaCaptureVideoProfile_DEFINED__
#define __WMCMediaCaptureVideoProfile_DEFINED__

WINRT_EXPORT
@interface WMCMediaCaptureVideoProfile : RTObject
@property (readonly) NSString* id;
@property (readonly) NSArray* supportedPhotoMediaDescription;
@property (readonly) NSArray* supportedPreviewMediaDescription;
@property (readonly) NSArray* supportedRecordMediaDescription;
@property (readonly) NSString* videoDeviceId;
- (NSArray*)getConcurrency;
@end

#endif // __WMCMediaCaptureVideoProfile_DEFINED__

// Windows.Media.Capture.MediaCaptureInitializationSettings
#ifndef __WMCMediaCaptureInitializationSettings_DEFINED__
#define __WMCMediaCaptureInitializationSettings_DEFINED__

WINRT_EXPORT
@interface WMCMediaCaptureInitializationSettings : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* videoDeviceId;
@property WMCStreamingCaptureMode streamingCaptureMode;
@property WMCPhotoCaptureSource photoCaptureSource;
@property (copy) NSString* audioDeviceId;
@property WMCMediaCategory mediaCategory;
@property WMAudioProcessing audioProcessing;
@property (copy) RTObject<WMCIMediaSource>* audioSource;
@property (copy) RTObject<WMCIMediaSource>* videoSource;
@property (copy) WMCMediaCaptureVideoProfile* videoProfile;
@property (copy) WMCMediaCaptureVideoProfileMediaDescription* recordMediaDescription;
@property (copy) WMCMediaCaptureVideoProfileMediaDescription* previewMediaDescription;
@property (copy) WMCMediaCaptureVideoProfileMediaDescription* photoMediaDescription;
@end

#endif // __WMCMediaCaptureInitializationSettings_DEFINED__

// Windows.Media.Capture.MediaCaptureSettings
#ifndef __WMCMediaCaptureSettings_DEFINED__
#define __WMCMediaCaptureSettings_DEFINED__

WINRT_EXPORT
@interface WMCMediaCaptureSettings : RTObject
@property (readonly) NSString* audioDeviceId;
@property (readonly) WMCPhotoCaptureSource photoCaptureSource;
@property (readonly) WMCStreamingCaptureMode streamingCaptureMode;
@property (readonly) WMCVideoDeviceCharacteristic videoDeviceCharacteristic;
@property (readonly) NSString* videoDeviceId;
@property (readonly) WMAudioProcessing audioProcessing;
@property (readonly) BOOL cameraSoundRequiredForRegion;
@property (readonly) BOOL concurrentRecordAndPhotoSequenceSupported;
@property (readonly) BOOL concurrentRecordAndPhotoSupported;
@property (readonly) id horizontal35mmEquivalentFocalLength;
@property (readonly) WMCMediaCategory mediaCategory;
@property (readonly) id pitchOffsetDegrees;
@property (readonly) id vertical35mmEquivalentFocalLength;
@end

#endif // __WMCMediaCaptureSettings_DEFINED__

// Windows.Media.Capture.LowLagMediaRecording
#ifndef __WMCLowLagMediaRecording_DEFINED__
#define __WMCLowLagMediaRecording_DEFINED__

WINRT_EXPORT
@interface WMCLowLagMediaRecording : RTObject
- (RTObject<WFIAsyncAction>*)startAsync;
- (RTObject<WFIAsyncAction>*)stopAsync;
- (RTObject<WFIAsyncAction>*)finishAsync;
- (RTObject<WFIAsyncAction>*)pauseAsync:(WMDMediaCapturePauseBehavior)behavior;
- (RTObject<WFIAsyncAction>*)resumeAsync;
@end

#endif // __WMCLowLagMediaRecording_DEFINED__

// Windows.Media.Capture.LowLagPhotoCapture
#ifndef __WMCLowLagPhotoCapture_DEFINED__
#define __WMCLowLagPhotoCapture_DEFINED__

WINRT_EXPORT
@interface WMCLowLagPhotoCapture : RTObject
- (void)captureAsyncWithSuccess:(void (^)(WMCCapturedPhoto*))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)finishAsync;
@end

#endif // __WMCLowLagPhotoCapture_DEFINED__

// Windows.Media.Capture.LowLagPhotoSequenceCapture
#ifndef __WMCLowLagPhotoSequenceCapture_DEFINED__
#define __WMCLowLagPhotoSequenceCapture_DEFINED__

WINRT_EXPORT
@interface WMCLowLagPhotoSequenceCapture : RTObject
- (EventRegistrationToken)addPhotoCapturedEvent:(void (^)(WMCLowLagPhotoSequenceCapture*, WMCPhotoCapturedEventArgs*))del;
- (void)removePhotoCapturedEvent:(EventRegistrationToken)tok;
- (RTObject<WFIAsyncAction>*)startAsync;
- (RTObject<WFIAsyncAction>*)stopAsync;
- (RTObject<WFIAsyncAction>*)finishAsync;
@end

#endif // __WMCLowLagPhotoSequenceCapture_DEFINED__

// Windows.Media.Capture.MediaCaptureFocusChangedEventArgs
#ifndef __WMCMediaCaptureFocusChangedEventArgs_DEFINED__
#define __WMCMediaCaptureFocusChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMCMediaCaptureFocusChangedEventArgs : RTObject
@property (readonly) WMDMediaCaptureFocusState focusState;
@end

#endif // __WMCMediaCaptureFocusChangedEventArgs_DEFINED__

// Windows.Media.Capture.PhotoConfirmationCapturedEventArgs
#ifndef __WMCPhotoConfirmationCapturedEventArgs_DEFINED__
#define __WMCPhotoConfirmationCapturedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMCPhotoConfirmationCapturedEventArgs : RTObject
@property (readonly) WFTimeSpan* captureTimeOffset;
@property (readonly) WMCCapturedFrame* frame;
@end

#endif // __WMCPhotoConfirmationCapturedEventArgs_DEFINED__

// Windows.Media.Capture.AdvancedPhotoCapture
#ifndef __WMCAdvancedPhotoCapture_DEFINED__
#define __WMCAdvancedPhotoCapture_DEFINED__

WINRT_EXPORT
@interface WMCAdvancedPhotoCapture : RTObject
- (EventRegistrationToken)addAllPhotosCapturedEvent:(void (^)(WMCAdvancedPhotoCapture*, RTObject*))del;
- (void)removeAllPhotosCapturedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOptionalReferencePhotoCapturedEvent:(void (^)(WMCAdvancedPhotoCapture*,
                                                                           WMCOptionalReferencePhotoCapturedEventArgs*))del;
- (void)removeOptionalReferencePhotoCapturedEvent:(EventRegistrationToken)tok;
- (void)captureAsyncWithSuccess:(void (^)(WMCAdvancedCapturedPhoto*))success failure:(void (^)(NSError*))failure;
- (void)captureWithContextAsync:(RTObject*)context success:(void (^)(WMCAdvancedCapturedPhoto*))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)finishAsync;
@end

#endif // __WMCAdvancedPhotoCapture_DEFINED__

// Windows.Media.Capture.CapturedPhoto
#ifndef __WMCCapturedPhoto_DEFINED__
#define __WMCCapturedPhoto_DEFINED__

WINRT_EXPORT
@interface WMCCapturedPhoto : RTObject
@property (readonly) WMCCapturedFrame* frame;
@property (readonly) WMCCapturedFrame* thumbnail;
@end

#endif // __WMCCapturedPhoto_DEFINED__

// Windows.Media.Capture.AdvancedCapturedPhoto
#ifndef __WMCAdvancedCapturedPhoto_DEFINED__
#define __WMCAdvancedCapturedPhoto_DEFINED__

WINRT_EXPORT
@interface WMCAdvancedCapturedPhoto : RTObject
@property (readonly) RTObject* context;
@property (readonly) WMCCapturedFrame* frame;
@property (readonly) WMDAdvancedPhotoMode mode;
@end

#endif // __WMCAdvancedCapturedPhoto_DEFINED__

// Windows.Media.Capture.OptionalReferencePhotoCapturedEventArgs
#ifndef __WMCOptionalReferencePhotoCapturedEventArgs_DEFINED__
#define __WMCOptionalReferencePhotoCapturedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMCOptionalReferencePhotoCapturedEventArgs : RTObject
@property (readonly) RTObject* context;
@property (readonly) WMCCapturedFrame* frame;
@end

#endif // __WMCOptionalReferencePhotoCapturedEventArgs_DEFINED__

// Windows.Storage.Streams.IInputStream
#ifndef __WSSIInputStream_DEFINED__
#define __WSSIInputStream_DEFINED__

@protocol WSSIInputStream <WFIClosable>
- (void)readAsync:(RTObject<WSSIBuffer>*)buffer
            count:(unsigned int)count
          options:(WSSInputStreamOptions)options
          success:(void (^)(RTObject<WSSIBuffer>*))success
         progress:(void (^)(unsigned int))progress
          failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WSSIInputStream_DEFINED__

// Windows.Storage.Streams.IOutputStream
#ifndef __WSSIOutputStream_DEFINED__
#define __WSSIOutputStream_DEFINED__

@protocol WSSIOutputStream <WFIClosable>
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer
           success:(void (^)(unsigned int))success
          progress:(void (^)(unsigned int))progress
           failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WSSIOutputStream_DEFINED__

// Windows.Storage.Streams.IRandomAccessStream
#ifndef __WSSIRandomAccessStream_DEFINED__
#define __WSSIRandomAccessStream_DEFINED__

@protocol WSSIRandomAccessStream <WFIClosable, WSSIInputStream, WSSIOutputStream>
@property (readonly) BOOL canRead;
@property (readonly) BOOL canWrite;
@property (readonly) uint64_t position;
@property uint64_t size;
- (RTObject<WSSIInputStream>*)getInputStreamAt:(uint64_t)position;
- (RTObject<WSSIOutputStream>*)getOutputStreamAt:(uint64_t)position;
- (void)seek:(uint64_t)position;
- (RTObject<WSSIRandomAccessStream>*)cloneStream;
- (void)close;
- (void)readAsync:(RTObject<WSSIBuffer>*)buffer
            count:(unsigned int)count
          options:(WSSInputStreamOptions)options
          success:(void (^)(RTObject<WSSIBuffer>*))success
         progress:(void (^)(unsigned int))progress
          failure:(void (^)(NSError*))failure;
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer
           success:(void (^)(unsigned int))success
          progress:(void (^)(unsigned int))progress
           failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSSIRandomAccessStream_DEFINED__

// Windows.Storage.Streams.IContentTypeProvider
#ifndef __WSSIContentTypeProvider_DEFINED__
#define __WSSIContentTypeProvider_DEFINED__

@protocol WSSIContentTypeProvider
@property (readonly) NSString* contentType;
@end

#endif // __WSSIContentTypeProvider_DEFINED__

// Windows.Storage.Streams.IRandomAccessStreamWithContentType
#ifndef __WSSIRandomAccessStreamWithContentType_DEFINED__
#define __WSSIRandomAccessStreamWithContentType_DEFINED__

@protocol
    WSSIRandomAccessStreamWithContentType <WSSIRandomAccessStream, WFIClosable, WSSIInputStream, WSSIOutputStream, WSSIContentTypeProvider>
- (RTObject<WSSIInputStream>*)getInputStreamAt:(uint64_t)position;
- (RTObject<WSSIOutputStream>*)getOutputStreamAt:(uint64_t)position;
- (void)seek:(uint64_t)position;
- (RTObject<WSSIRandomAccessStream>*)cloneStream;
- (void)close;
- (void)readAsync:(RTObject<WSSIBuffer>*)buffer
            count:(unsigned int)count
          options:(WSSInputStreamOptions)options
          success:(void (^)(RTObject<WSSIBuffer>*))success
         progress:(void (^)(unsigned int))progress
          failure:(void (^)(NSError*))failure;
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer
           success:(void (^)(unsigned int))success
          progress:(void (^)(unsigned int))progress
           failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSSIRandomAccessStreamWithContentType_DEFINED__

// Windows.Media.Capture.CapturedFrame
#ifndef __WMCCapturedFrame_DEFINED__
#define __WMCCapturedFrame_DEFINED__

WINRT_EXPORT
@interface WMCCapturedFrame : RTObject <WSSIRandomAccessStreamWithContentType,
                                        WSSIContentTypeProvider,
                                        WSSIRandomAccessStream,
                                        WSSIOutputStream,
                                        WFIClosable,
                                        WSSIInputStream>
@property (readonly) unsigned int height;
@property (readonly) unsigned int width;
@property (readonly) WGISoftwareBitmap* softwareBitmap;
@property (readonly) NSString* contentType;
@property uint64_t size;
@property (readonly) BOOL canRead;
@property (readonly) BOOL canWrite;
@property (readonly) uint64_t position;
- (RTObject<WSSIInputStream>*)getInputStreamAt:(uint64_t)position;
- (RTObject<WSSIOutputStream>*)getOutputStreamAt:(uint64_t)position;
- (void)seek:(uint64_t)position;
- (RTObject<WSSIRandomAccessStream>*)cloneStream;
- (void)close;
- (void)readAsync:(RTObject<WSSIBuffer>*)buffer
            count:(unsigned int)count
          options:(WSSInputStreamOptions)options
          success:(void (^)(RTObject<WSSIBuffer>*))success
         progress:(void (^)(unsigned int))progress
          failure:(void (^)(NSError*))failure;
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer
           success:(void (^)(unsigned int))success
          progress:(void (^)(unsigned int))progress
           failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WMCCapturedFrame_DEFINED__

// Windows.Media.Capture.PhotoCapturedEventArgs
#ifndef __WMCPhotoCapturedEventArgs_DEFINED__
#define __WMCPhotoCapturedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMCPhotoCapturedEventArgs : RTObject
@property (readonly) WFTimeSpan* captureTimeOffset;
@property (readonly) WMCCapturedFrame* frame;
@property (readonly) WMCCapturedFrame* thumbnail;
@end

#endif // __WMCPhotoCapturedEventArgs_DEFINED__

// Windows.Media.Capture.CapturedFrameControlValues
#ifndef __WMCCapturedFrameControlValues_DEFINED__
#define __WMCCapturedFrameControlValues_DEFINED__

WINRT_EXPORT
@interface WMCCapturedFrameControlValues : RTObject
@property (readonly) id exposure;
@property (readonly) id exposureCompensation;
@property (readonly) id flashPowerPercent;
@property (readonly) id flashed;
@property (readonly) id focus;
@property (readonly) id isoSpeed;
@property (readonly) id sceneMode;
@property (readonly) id whiteBalance;
@property (readonly) id zoomFactor;
@property (readonly) id focusState;
@property (readonly) id isoAnalogGain;
@property (readonly) id isoDigitalGain;
@property (readonly) WMMMediaRatio* sensorFrameRate;
@property (readonly) id whiteBalanceGain;
@end

#endif // __WMCCapturedFrameControlValues_DEFINED__

// Windows.Media.Capture.VideoStreamConfiguration
#ifndef __WMCVideoStreamConfiguration_DEFINED__
#define __WMCVideoStreamConfiguration_DEFINED__

WINRT_EXPORT
@interface WMCVideoStreamConfiguration : RTObject
@property (readonly) WMMVideoEncodingProperties* inputProperties;
@property (readonly) WMMVideoEncodingProperties* outputProperties;
@end

#endif // __WMCVideoStreamConfiguration_DEFINED__
