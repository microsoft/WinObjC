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

// WindowsMediaCapture.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
#define OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsMediaCaptureDevicesCoreMediaPropertiesDevicesCorePlaybackProtection.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WMCAppCapture, WMCCameraCaptureUIPhotoCaptureSettings, WMCCameraCaptureUIVideoCaptureSettings, WMCCameraCaptureUI, WMCMediaCaptureFailedEventArgs, WMCMediaCapture, WMCMediaCaptureVideoProfileMediaDescription, WMCMediaCaptureVideoProfile, WMCMediaCaptureInitializationSettings, WMCMediaCaptureSettings, WMCLowLagMediaRecording, WMCLowLagPhotoCapture, WMCLowLagPhotoSequenceCapture, WMCMediaCaptureFocusChangedEventArgs, WMCPhotoConfirmationCapturedEventArgs, WMCAdvancedPhotoCapture, WMCMediaCapturePauseResult, WMCMediaCaptureStopResult, WMCMediaCaptureDeviceExclusiveControlStatusChangedEventArgs, WMCCapturedPhoto, WMCAdvancedCapturedPhoto, WMCOptionalReferencePhotoCapturedEventArgs, WMCCapturedFrame, WMCPhotoCapturedEventArgs, WMCCapturedFrameControlValues, WMCVideoStreamConfiguration, WMCAppBroadcastGlobalSettings, WMCAppBroadcastProviderSettings, WMCAppBroadcastManager, WMCAppBroadcastBackgroundServiceSignInInfo, WMCAppBroadcastSignInStateChangedEventArgs, WMCAppBroadcastStreamReader, WMCAppBroadcastBackgroundServiceStreamInfo, WMCAppBroadcastStreamStateChangedEventArgs, WMCAppBroadcastBackgroundService, WMCAppBroadcastHeartbeatRequestedEventArgs, WMCAppBroadcastStreamAudioFrame, WMCAppBroadcastStreamVideoFrame, WMCAppBroadcastStreamVideoHeader, WMCAppBroadcastStreamAudioHeader, WMCAppBroadcastTriggerDetails, WMCAppBroadcastPlugInManager, WMCAppBroadcastPlugIn, WMCAppBroadcastPreview, WMCAppBroadcastState, WMCAppBroadcastViewerCountChangedEventArgs, WMCAppBroadcastMicrophoneCaptureStateChangedEventArgs, WMCAppBroadcastCameraCaptureStateChangedEventArgs, WMCAppBroadcastPlugInStateChangedEventArgs, WMCAppBroadcastPreviewStateChangedEventArgs, WMCAppBroadcastPreviewStreamReader, WMCAppBroadcastPreviewStreamVideoFrame, WMCAppBroadcastPreviewStreamVideoHeader, WMCAppBroadcastServices, WMCAppCaptureSettings, WMCAppCaptureAlternateShortcutKeys, WMCAppCaptureManager, WMCAppCaptureRecordOperation, WMCAppCaptureState, WMCAppCaptureMicrophoneCaptureStateChangedEventArgs, WMCAppCaptureRecordingStateChangedEventArgs, WMCAppCaptureDurationGeneratedEventArgs, WMCAppCaptureFileGeneratedEventArgs, WMCAppCaptureServices, WMCAppCaptureMetadataWriter, WMCCameraOptionsUI, WMCGameBarServicesManager, WMCGameBarServicesManagerGameBarServicesCreatedEventArgs, WMCGameBarServices, WMCGameBarServicesTargetInfo, WMCGameBarServicesCommandEventArgs;
@class WMCWhiteBalanceGain;
@protocol WMCIAppCapture, WMCIAppCaptureStatics, WMCIAppCaptureStatics2, WMCICameraCaptureUIPhotoCaptureSettings, WMCICameraCaptureUIVideoCaptureSettings, WMCICameraCaptureUI, WMCIMediaCaptureFailedEventArgs, WMCIMediaCaptureVideoProfileMediaDescription, WMCIMediaCaptureVideoProfile, WMCIMediaCaptureInitializationSettings, WMCIMediaCaptureInitializationSettings2, WMCIMediaCaptureInitializationSettings3, WMCIMediaCaptureInitializationSettings4, WMCIMediaCaptureInitializationSettings5, WMCIMediaCaptureInitializationSettings6, WMCIMediaCaptureStatics, WMCIMediaCapture, WMCIMediaCapture2, WMCIMediaCapture3, WMCIMediaCapture4, WMCIMediaCapture5, WMCIMediaCapture6, WMCILowLagPhotoCapture, WMCIAdvancedPhotoCapture, WMCIAdvancedCapturedPhoto, WMCIAdvancedCapturedPhoto2, WMCIOptionalReferencePhotoCapturedEventArgs, WMCILowLagMediaRecording, WMCILowLagMediaRecording2, WMCILowLagMediaRecording3, WMCIMediaCapturePauseResult, WMCIMediaCaptureStopResult, WMCILowLagPhotoSequenceCapture, WMCICapturedFrameControlValues, WMCICapturedFrameControlValues2, WMCIPhotoCapturedEventArgs, WMCICapturedPhoto, WMCICapturedFrame, WMCICapturedFrameWithSoftwareBitmap, WMCIMediaCaptureVideoPreview, WMCIMediaCaptureSettings, WMCIMediaCaptureSettings2, WMCIMediaCaptureFocusChangedEventArgs, WMCIPhotoConfirmationCapturedEventArgs, WMCIVideoStreamConfiguration, WMCIMediaCaptureDeviceExclusiveControlStatusChangedEventArgs, WMCIAppBroadcastManagerStatics, WMCIAppBroadcastGlobalSettings, WMCIAppBroadcastProviderSettings, WMCIAppBroadcastBackgroundServiceSignInInfo, WMCIAppBroadcastBackgroundServiceSignInInfo2, WMCIAppBroadcastBackgroundServiceStreamInfo, WMCIAppBroadcastBackgroundServiceStreamInfo2, WMCIAppBroadcastBackgroundService, WMCIAppBroadcastBackgroundService2, WMCIAppBroadcastSignInStateChangedEventArgs, WMCIAppBroadcastStreamStateChangedEventArgs, WMCIAppBroadcastHeartbeatRequestedEventArgs, WMCIAppBroadcastStreamReader, WMCIAppBroadcastStreamVideoFrame, WMCIAppBroadcastStreamAudioFrame, WMCIAppBroadcastStreamAudioHeader, WMCIAppBroadcastStreamVideoHeader, WMCIAppBroadcastTriggerDetails, WMCIAppBroadcastPlugInManagerStatics, WMCIAppBroadcastPlugInManager, WMCIAppBroadcastPlugIn, WMCIAppBroadcastServices, WMCIAppBroadcastState, WMCIAppBroadcastPreview, WMCIAppBroadcastPlugInStateChangedEventArgs, WMCIAppBroadcastPreviewStateChangedEventArgs, WMCIAppBroadcastPreviewStreamReader, WMCIAppBroadcastPreviewStreamVideoFrame, WMCIAppBroadcastPreviewStreamVideoHeader, WMCIAppBroadcastMicrophoneCaptureStateChangedEventArgs, WMCIAppBroadcastCameraCaptureStateChangedEventArgs, WMCIAppBroadcastViewerCountChangedEventArgs, WMCIAppCaptureManagerStatics, WMCIAppCaptureAlternateShortcutKeys, WMCIAppCaptureAlternateShortcutKeys2, WMCIAppCaptureAlternateShortcutKeys3, WMCIAppCaptureSettings, WMCIAppCaptureSettings2, WMCIAppCaptureSettings3, WMCIAppCaptureSettings4, WMCIAppCaptureSettings5, WMCIAppCaptureServices, WMCIAppCaptureState, WMCIAppCaptureMicrophoneCaptureStateChangedEventArgs, WMCIAppCaptureRecordOperation, WMCIAppCaptureRecordingStateChangedEventArgs, WMCIAppCaptureDurationGeneratedEventArgs, WMCIAppCaptureFileGeneratedEventArgs, WMCIAppCaptureMetadataWriter, WMCICameraOptionsUIStatics, WMCIGameBarServicesManagerStatics, WMCIGameBarServicesManager, WMCIGameBarServicesManagerGameBarServicesCreatedEventArgs, WMCIGameBarServices, WMCIGameBarServicesTargetInfo, WMCIGameBarServicesCommandEventArgs;

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

// Windows.Media.Capture.MediaCaptureThermalStatus
enum _WMCMediaCaptureThermalStatus {
    WMCMediaCaptureThermalStatusNormal = 0,
    WMCMediaCaptureThermalStatusOverheated = 1,
};
typedef unsigned WMCMediaCaptureThermalStatus;

// Windows.Media.Capture.MediaCaptureDeviceExclusiveControlStatus
enum _WMCMediaCaptureDeviceExclusiveControlStatus {
    WMCMediaCaptureDeviceExclusiveControlStatusExclusiveControlAvailable = 0,
    WMCMediaCaptureDeviceExclusiveControlStatusSharedReadOnlyAvailable = 1,
};
typedef unsigned WMCMediaCaptureDeviceExclusiveControlStatus;

// Windows.Media.Capture.KnownVideoProfile
enum _WMCKnownVideoProfile {
    WMCKnownVideoProfileVideoRecording = 0,
    WMCKnownVideoProfileHighQualityPhoto = 1,
    WMCKnownVideoProfileBalancedVideoAndPhoto = 2,
    WMCKnownVideoProfileVideoConferencing = 3,
    WMCKnownVideoProfilePhotoSequence = 4,
};
typedef unsigned WMCKnownVideoProfile;

// Windows.Media.Capture.MediaCaptureMemoryPreference
enum _WMCMediaCaptureMemoryPreference {
    WMCMediaCaptureMemoryPreferenceAuto = 0,
    WMCMediaCaptureMemoryPreferenceCpu = 1,
};
typedef unsigned WMCMediaCaptureMemoryPreference;

// Windows.Media.Capture.MediaCaptureSharingMode
enum _WMCMediaCaptureSharingMode {
    WMCMediaCaptureSharingModeExclusiveControl = 0,
    WMCMediaCaptureSharingModeSharedReadOnly = 1,
};
typedef unsigned WMCMediaCaptureSharingMode;

// Windows.Media.Capture.MediaStreamType
enum _WMCMediaStreamType {
    WMCMediaStreamTypeVideoPreview = 0,
    WMCMediaStreamTypeVideoRecord = 1,
    WMCMediaStreamTypeAudio = 2,
    WMCMediaStreamTypePhoto = 3,
};
typedef unsigned WMCMediaStreamType;

// Windows.Media.Capture.PowerlineFrequency
enum _WMCPowerlineFrequency {
    WMCPowerlineFrequencyDisabled = 0,
    WMCPowerlineFrequencyFiftyHertz = 1,
    WMCPowerlineFrequencySixtyHertz = 2,
    WMCPowerlineFrequencyAuto = 3,
};
typedef unsigned WMCPowerlineFrequency;

// Windows.Media.Capture.AppBroadcastCameraOverlayLocation
enum _WMCAppBroadcastCameraOverlayLocation {
    WMCAppBroadcastCameraOverlayLocationTopLeft = 0,
    WMCAppBroadcastCameraOverlayLocationTopCenter = 1,
    WMCAppBroadcastCameraOverlayLocationTopRight = 2,
    WMCAppBroadcastCameraOverlayLocationMiddleLeft = 3,
    WMCAppBroadcastCameraOverlayLocationMiddleCenter = 4,
    WMCAppBroadcastCameraOverlayLocationMiddleRight = 5,
    WMCAppBroadcastCameraOverlayLocationBottomLeft = 6,
    WMCAppBroadcastCameraOverlayLocationBottomCenter = 7,
    WMCAppBroadcastCameraOverlayLocationBottomRight = 8,
};
typedef unsigned WMCAppBroadcastCameraOverlayLocation;

// Windows.Media.Capture.AppBroadcastCameraOverlaySize
enum _WMCAppBroadcastCameraOverlaySize {
    WMCAppBroadcastCameraOverlaySizeSmall = 0,
    WMCAppBroadcastCameraOverlaySizeMedium = 1,
    WMCAppBroadcastCameraOverlaySizeLarge = 2,
};
typedef unsigned WMCAppBroadcastCameraOverlaySize;

// Windows.Media.Capture.AppBroadcastVideoEncodingBitrateMode
enum _WMCAppBroadcastVideoEncodingBitrateMode {
    WMCAppBroadcastVideoEncodingBitrateModeCustom = 0,
    WMCAppBroadcastVideoEncodingBitrateModeAuto = 1,
};
typedef unsigned WMCAppBroadcastVideoEncodingBitrateMode;

// Windows.Media.Capture.AppBroadcastVideoEncodingResolutionMode
enum _WMCAppBroadcastVideoEncodingResolutionMode {
    WMCAppBroadcastVideoEncodingResolutionModeCustom = 0,
    WMCAppBroadcastVideoEncodingResolutionModeAuto = 1,
};
typedef unsigned WMCAppBroadcastVideoEncodingResolutionMode;

// Windows.Media.Capture.AppBroadcastPlugInState
enum _WMCAppBroadcastPlugInState {
    WMCAppBroadcastPlugInStateUnknown = 0,
    WMCAppBroadcastPlugInStateInitialized = 1,
    WMCAppBroadcastPlugInStateMicrosoftSignInRequired = 2,
    WMCAppBroadcastPlugInStateOAuthSignInRequired = 3,
    WMCAppBroadcastPlugInStateProviderSignInRequired = 4,
    WMCAppBroadcastPlugInStateInBandwidthTest = 5,
    WMCAppBroadcastPlugInStateReadyToBroadcast = 6,
};
typedef unsigned WMCAppBroadcastPlugInState;

// Windows.Media.Capture.AppBroadcastStreamState
enum _WMCAppBroadcastStreamState {
    WMCAppBroadcastStreamStateInitializing = 0,
    WMCAppBroadcastStreamStateStreamReady = 1,
    WMCAppBroadcastStreamStateStarted = 2,
    WMCAppBroadcastStreamStatePaused = 3,
    WMCAppBroadcastStreamStateTerminated = 4,
};
typedef unsigned WMCAppBroadcastStreamState;

// Windows.Media.Capture.AppBroadcastSignInState
enum _WMCAppBroadcastSignInState {
    WMCAppBroadcastSignInStateNotSignedIn = 0,
    WMCAppBroadcastSignInStateMicrosoftSignInInProgress = 1,
    WMCAppBroadcastSignInStateMicrosoftSignInComplete = 2,
    WMCAppBroadcastSignInStateOAuthSignInInProgress = 3,
    WMCAppBroadcastSignInStateOAuthSignInComplete = 4,
};
typedef unsigned WMCAppBroadcastSignInState;

// Windows.Media.Capture.AppBroadcastTerminationReason
enum _WMCAppBroadcastTerminationReason {
    WMCAppBroadcastTerminationReasonNormalTermination = 0,
    WMCAppBroadcastTerminationReasonLostConnectionToService = 1,
    WMCAppBroadcastTerminationReasonNoNetworkConnectivity = 2,
    WMCAppBroadcastTerminationReasonServiceAbort = 3,
    WMCAppBroadcastTerminationReasonServiceError = 4,
    WMCAppBroadcastTerminationReasonServiceUnavailable = 5,
    WMCAppBroadcastTerminationReasonInternalError = 6,
    WMCAppBroadcastTerminationReasonUnsupportedFormat = 7,
    WMCAppBroadcastTerminationReasonBackgroundTaskTerminated = 8,
    WMCAppBroadcastTerminationReasonBackgroundTaskUnresponsive = 9,
};
typedef unsigned WMCAppBroadcastTerminationReason;

// Windows.Media.Capture.AppBroadcastSignInResult
enum _WMCAppBroadcastSignInResult {
    WMCAppBroadcastSignInResultSuccess = 0,
    WMCAppBroadcastSignInResultAuthenticationFailed = 1,
    WMCAppBroadcastSignInResultUnauthorized = 2,
    WMCAppBroadcastSignInResultServiceUnavailable = 3,
    WMCAppBroadcastSignInResultUnknown = 4,
};
typedef unsigned WMCAppBroadcastSignInResult;

// Windows.Media.Capture.ForegroundActivationArgument
enum _WMCForegroundActivationArgument {
    WMCForegroundActivationArgumentSignInRequired = 0,
    WMCForegroundActivationArgumentMoreSettings = 1,
};
typedef unsigned WMCForegroundActivationArgument;

// Windows.Media.Capture.AppBroadcastMicrophoneCaptureState
enum _WMCAppBroadcastMicrophoneCaptureState {
    WMCAppBroadcastMicrophoneCaptureStateStopped = 0,
    WMCAppBroadcastMicrophoneCaptureStateStarted = 1,
    WMCAppBroadcastMicrophoneCaptureStateFailed = 2,
};
typedef unsigned WMCAppBroadcastMicrophoneCaptureState;

// Windows.Media.Capture.AppBroadcastCameraCaptureState
enum _WMCAppBroadcastCameraCaptureState {
    WMCAppBroadcastCameraCaptureStateStopped = 0,
    WMCAppBroadcastCameraCaptureStateStarted = 1,
    WMCAppBroadcastCameraCaptureStateFailed = 2,
};
typedef unsigned WMCAppBroadcastCameraCaptureState;

// Windows.Media.Capture.AppBroadcastExitBroadcastModeReason
enum _WMCAppBroadcastExitBroadcastModeReason {
    WMCAppBroadcastExitBroadcastModeReasonNormalExit = 0,
    WMCAppBroadcastExitBroadcastModeReasonUserCanceled = 1,
    WMCAppBroadcastExitBroadcastModeReasonAuthorizationFail = 2,
    WMCAppBroadcastExitBroadcastModeReasonForegroundAppActivated = 3,
};
typedef unsigned WMCAppBroadcastExitBroadcastModeReason;

// Windows.Media.Capture.AppBroadcastPreviewState
enum _WMCAppBroadcastPreviewState {
    WMCAppBroadcastPreviewStateStarted = 0,
    WMCAppBroadcastPreviewStateStopped = 1,
    WMCAppBroadcastPreviewStateFailed = 2,
};
typedef unsigned WMCAppBroadcastPreviewState;

// Windows.Media.Capture.AppBroadcastCaptureTargetType
enum _WMCAppBroadcastCaptureTargetType {
    WMCAppBroadcastCaptureTargetTypeAppView = 0,
    WMCAppBroadcastCaptureTargetTypeEntireDisplay = 1,
};
typedef unsigned WMCAppBroadcastCaptureTargetType;

// Windows.Media.Capture.GameBarServicesDisplayMode
enum _WMCGameBarServicesDisplayMode {
    WMCGameBarServicesDisplayModeWindowed = 0,
    WMCGameBarServicesDisplayModeFullScreenExclusive = 1,
};
typedef unsigned WMCGameBarServicesDisplayMode;

// Windows.Media.Capture.AppCaptureVideoEncodingBitrateMode
enum _WMCAppCaptureVideoEncodingBitrateMode {
    WMCAppCaptureVideoEncodingBitrateModeCustom = 0,
    WMCAppCaptureVideoEncodingBitrateModeHigh = 1,
    WMCAppCaptureVideoEncodingBitrateModeStandard = 2,
};
typedef unsigned WMCAppCaptureVideoEncodingBitrateMode;

// Windows.Media.Capture.AppCaptureVideoEncodingResolutionMode
enum _WMCAppCaptureVideoEncodingResolutionMode {
    WMCAppCaptureVideoEncodingResolutionModeCustom = 0,
    WMCAppCaptureVideoEncodingResolutionModeHigh = 1,
    WMCAppCaptureVideoEncodingResolutionModeStandard = 2,
};
typedef unsigned WMCAppCaptureVideoEncodingResolutionMode;

// Windows.Media.Capture.AppCaptureVideoEncodingFrameRateMode
enum _WMCAppCaptureVideoEncodingFrameRateMode {
    WMCAppCaptureVideoEncodingFrameRateModeStandard = 0,
    WMCAppCaptureVideoEncodingFrameRateModeHigh = 1,
};
typedef unsigned WMCAppCaptureVideoEncodingFrameRateMode;

// Windows.Media.Capture.AppCaptureHistoricalBufferLengthUnit
enum _WMCAppCaptureHistoricalBufferLengthUnit {
    WMCAppCaptureHistoricalBufferLengthUnitMegabytes = 0,
    WMCAppCaptureHistoricalBufferLengthUnitSeconds = 1,
};
typedef unsigned WMCAppCaptureHistoricalBufferLengthUnit;

// Windows.Media.Capture.AppCaptureMicrophoneCaptureState
enum _WMCAppCaptureMicrophoneCaptureState {
    WMCAppCaptureMicrophoneCaptureStateStopped = 0,
    WMCAppCaptureMicrophoneCaptureStateStarted = 1,
    WMCAppCaptureMicrophoneCaptureStateFailed = 2,
};
typedef unsigned WMCAppCaptureMicrophoneCaptureState;

// Windows.Media.Capture.AppCaptureRecordingState
enum _WMCAppCaptureRecordingState {
    WMCAppCaptureRecordingStateInProgress = 0,
    WMCAppCaptureRecordingStateCompleted = 1,
    WMCAppCaptureRecordingStateFailed = 2,
};
typedef unsigned WMCAppCaptureRecordingState;

// Windows.Media.Capture.AppCaptureMetadataPriority
enum _WMCAppCaptureMetadataPriority {
    WMCAppCaptureMetadataPriorityInformational = 0,
    WMCAppCaptureMetadataPriorityImportant = 1,
};
typedef unsigned WMCAppCaptureMetadataPriority;

// Windows.Media.Capture.GameBarCommand
enum _WMCGameBarCommand {
    WMCGameBarCommandOpenGameBar = 0,
    WMCGameBarCommandRecordHistoricalBuffer = 1,
    WMCGameBarCommandToggleStartStopRecord = 2,
    WMCGameBarCommandStartRecord = 3,
    WMCGameBarCommandStopRecord = 4,
    WMCGameBarCommandTakeScreenshot = 5,
    WMCGameBarCommandStartBroadcast = 6,
    WMCGameBarCommandStopBroadcast = 7,
    WMCGameBarCommandPauseBroadcast = 8,
    WMCGameBarCommandResumeBroadcast = 9,
    WMCGameBarCommandToggleStartStopBroadcast = 10,
    WMCGameBarCommandToggleMicrophoneCapture = 11,
    WMCGameBarCommandToggleCameraCapture = 12,
    WMCGameBarCommandToggleRecordingIndicator = 13,
};
typedef unsigned WMCGameBarCommand;

// Windows.Media.Capture.GameBarCommandOrigin
enum _WMCGameBarCommandOrigin {
    WMCGameBarCommandOriginShortcutKey = 0,
    WMCGameBarCommandOriginCortana = 1,
    WMCGameBarCommandOriginAppCommand = 2,
};
typedef unsigned WMCGameBarCommandOrigin;

// Windows.Media.Capture.GameBarTargetCapturePolicy
enum _WMCGameBarTargetCapturePolicy {
    WMCGameBarTargetCapturePolicyEnabledBySystem = 0,
    WMCGameBarTargetCapturePolicyEnabledByUser = 1,
    WMCGameBarTargetCapturePolicyNotEnabled = 2,
    WMCGameBarTargetCapturePolicyProhibitedBySystem = 3,
    WMCGameBarTargetCapturePolicyProhibitedByPublisher = 4,
};
typedef unsigned WMCGameBarTargetCapturePolicy;

#include "WindowsMediaCaptureFrames.h"
#include "WindowsMediaCaptureCore.h"
#include "WindowsFoundation.h"
#include "WindowsMediaCore.h"
#include "WindowsStorage.h"
#include "WindowsMedia.h"
#include "WindowsMediaMediaProperties.h"
#include "WindowsFoundationCollections.h"
#include "WindowsStorageStreams.h"
#include "WindowsMediaDevices.h"
#include "WindowsMediaEffects.h"
#include "WindowsGraphicsImaging.h"
#include "WindowsSecurityAuthenticationWeb.h"
#include "WindowsSystem.h"
// Windows.Media.Capture.MediaCaptureFailedEventHandler
#ifndef __WMCMediaCaptureFailedEventHandler__DEFINED
#define __WMCMediaCaptureFailedEventHandler__DEFINED
typedef void(^WMCMediaCaptureFailedEventHandler)(WMCMediaCapture* sender, WMCMediaCaptureFailedEventArgs* errorEventArgs);
#endif // __WMCMediaCaptureFailedEventHandler__DEFINED

// Windows.Media.Capture.RecordLimitationExceededEventHandler
#ifndef __WMCRecordLimitationExceededEventHandler__DEFINED
#define __WMCRecordLimitationExceededEventHandler__DEFINED
typedef void(^WMCRecordLimitationExceededEventHandler)(WMCMediaCapture* sender);
#endif // __WMCRecordLimitationExceededEventHandler__DEFINED


#import <Foundation/Foundation.h>

// [struct] Windows.Media.Capture.WhiteBalanceGain
OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCWhiteBalanceGain : NSObject
+ (instancetype)new;
@property double r;
@property double g;
@property double b;
@end

// Windows.Media.Capture.MediaCaptureFailedEventHandler
#ifndef __WMCMediaCaptureFailedEventHandler__DEFINED
#define __WMCMediaCaptureFailedEventHandler__DEFINED
typedef void(^WMCMediaCaptureFailedEventHandler)(WMCMediaCapture* sender, WMCMediaCaptureFailedEventArgs* errorEventArgs);
#endif // __WMCMediaCaptureFailedEventHandler__DEFINED

// Windows.Media.Capture.RecordLimitationExceededEventHandler
#ifndef __WMCRecordLimitationExceededEventHandler__DEFINED
#define __WMCRecordLimitationExceededEventHandler__DEFINED
typedef void(^WMCRecordLimitationExceededEventHandler)(WMCMediaCapture* sender);
#endif // __WMCRecordLimitationExceededEventHandler__DEFINED

// Windows.Media.Capture.AppCapture
#ifndef __WMCAppCapture_DEFINED__
#define __WMCAppCapture_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppCapture : RTObject
+ (WMCAppCapture*)getForCurrentView;
+ (RTObject<WFIAsyncAction>*)setAllowedAsync:(BOOL)allowed;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isCapturingAudio;
@property (readonly) BOOL isCapturingVideo;
- (EventRegistrationToken)addCapturingChangedEvent:(void(^)(WMCAppCapture*, RTObject*))del;
- (void)removeCapturingChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WMCAppCapture_DEFINED__

// Windows.Media.Capture.CameraCaptureUIPhotoCaptureSettings
#ifndef __WMCCameraCaptureUIPhotoCaptureSettings_DEFINED__
#define __WMCCameraCaptureUIPhotoCaptureSettings_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCCameraCaptureUIPhotoCaptureSettings : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WMCCameraCaptureUIMaxPhotoResolution maxResolution;
@property WMCCameraCaptureUIPhotoFormat format;
@property (retain) WFSize* croppedSizeInPixels;
@property (retain) WFSize* croppedAspectRatio;
@property BOOL allowCropping;
@end

#endif // __WMCCameraCaptureUIPhotoCaptureSettings_DEFINED__

// Windows.Media.Capture.CameraCaptureUIVideoCaptureSettings
#ifndef __WMCCameraCaptureUIVideoCaptureSettings_DEFINED__
#define __WMCCameraCaptureUIVideoCaptureSettings_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCCameraCaptureUIVideoCaptureSettings : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WMCCameraCaptureUIMaxVideoResolution maxResolution;
@property float maxDurationInSeconds;
@property WMCCameraCaptureUIVideoFormat format;
@property BOOL allowTrimming;
@end

#endif // __WMCCameraCaptureUIVideoCaptureSettings_DEFINED__

// Windows.Media.Capture.CameraCaptureUI
#ifndef __WMCCameraCaptureUI_DEFINED__
#define __WMCCameraCaptureUI_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCCameraCaptureUI : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMCCameraCaptureUIPhotoCaptureSettings* photoSettings;
@property (readonly) WMCCameraCaptureUIVideoCaptureSettings* videoSettings;
- (void)captureFileAsync:(WMCCameraCaptureUIMode)mode success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WMCCameraCaptureUI_DEFINED__

// Windows.Media.Capture.MediaCaptureFailedEventArgs
#ifndef __WMCMediaCaptureFailedEventArgs_DEFINED__
#define __WMCMediaCaptureFailedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaCaptureFailedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int code;
@property (readonly) NSString * message;
@end

#endif // __WMCMediaCaptureFailedEventArgs_DEFINED__

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

// Windows.Media.Capture.MediaCapture
#ifndef __WMCMediaCapture_DEFINED__
#define __WMCMediaCapture_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaCapture : RTObject <WFIClosable>
+ (BOOL)isVideoProfileSupported:(NSString *)videoDeviceId;
+ (NSArray* /* WMCMediaCaptureVideoProfile* */)findAllVideoProfiles:(NSString *)videoDeviceId;
+ (NSArray* /* WMCMediaCaptureVideoProfile* */)findConcurrentProfiles:(NSString *)videoDeviceId;
+ (NSArray* /* WMCMediaCaptureVideoProfile* */)findKnownVideoProfiles:(NSString *)videoDeviceId name:(WMCKnownVideoProfile)name;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMDAudioDeviceController* audioDeviceController;
@property (readonly) WMCMediaCaptureSettings* mediaCaptureSettings;
@property (readonly) WMDVideoDeviceController* videoDeviceController;
@property (readonly) WMDCameraStreamState cameraStreamState;
@property (readonly) WMCMediaCaptureThermalStatus thermalStatus;
@property (readonly) NSDictionary* /* NSString *, WMCFMediaFrameSource* */ frameSources;
- (EventRegistrationToken)addFailedEvent:(WMCMediaCaptureFailedEventHandler)del;
- (void)removeFailedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRecordLimitationExceededEvent:(WMCRecordLimitationExceededEventHandler)del;
- (void)removeRecordLimitationExceededEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addFocusChangedEvent:(void(^)(WMCMediaCapture*, WMCMediaCaptureFocusChangedEventArgs*))del;
- (void)removeFocusChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPhotoConfirmationCapturedEvent:(void(^)(WMCMediaCapture*, WMCPhotoConfirmationCapturedEventArgs*))del;
- (void)removePhotoConfirmationCapturedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCameraStreamStateChangedEvent:(void(^)(WMCMediaCapture*, RTObject*))del;
- (void)removeCameraStreamStateChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addThermalStatusChangedEvent:(void(^)(WMCMediaCapture*, RTObject*))del;
- (void)removeThermalStatusChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCaptureDeviceExclusiveControlStatusChangedEvent:(void(^)(WMCMediaCapture*, WMCMediaCaptureDeviceExclusiveControlStatusChangedEventArgs*))del;
- (void)removeCaptureDeviceExclusiveControlStatusChangedEvent:(EventRegistrationToken)tok;
- (RTObject<WFIAsyncAction>*)initializeAsync;
- (RTObject<WFIAsyncAction>*)initializeWithSettingsAsync:(WMCMediaCaptureInitializationSettings*)mediaCaptureInitializationSettings;
- (RTObject<WFIAsyncAction>*)startRecordToStorageFileAsync:(WMMMediaEncodingProfile*)encodingProfile file:(RTObject<WSIStorageFile>*)file;
- (RTObject<WFIAsyncAction>*)startRecordToStreamAsync:(WMMMediaEncodingProfile*)encodingProfile stream:(RTObject<WSSIRandomAccessStream>*)stream;
- (RTObject<WFIAsyncAction>*)startRecordToCustomSinkAsync:(WMMMediaEncodingProfile*)encodingProfile customMediaSink:(RTObject<WMIMediaExtension>*)customMediaSink;
- (RTObject<WFIAsyncAction>*)startRecordToCustomSinkIdAsync:(WMMMediaEncodingProfile*)encodingProfile customSinkActivationId:(NSString *)customSinkActivationId customSinkSettings:(RTObject<WFCIPropertySet>*)customSinkSettings;
- (RTObject<WFIAsyncAction>*)stopRecordAsync;
- (RTObject<WFIAsyncAction>*)capturePhotoToStorageFileAsync:(WMMImageEncodingProperties*)type file:(RTObject<WSIStorageFile>*)file;
- (RTObject<WFIAsyncAction>*)capturePhotoToStreamAsync:(WMMImageEncodingProperties*)type stream:(RTObject<WSSIRandomAccessStream>*)stream;
- (RTObject<WFIAsyncAction>*)addEffectAsync:(WMCMediaStreamType)mediaStreamType effectActivationID:(NSString *)effectActivationID effectSettings:(RTObject<WFCIPropertySet>*)effectSettings;
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
- (RTObject<WFIAsyncAction>*)startPreviewToCustomSinkAsync:(WMMMediaEncodingProfile*)encodingProfile customMediaSink:(RTObject<WMIMediaExtension>*)customMediaSink;
- (RTObject<WFIAsyncAction>*)startPreviewToCustomSinkIdAsync:(WMMMediaEncodingProfile*)encodingProfile customSinkActivationId:(NSString *)customSinkActivationId customSinkSettings:(RTObject<WFCIPropertySet>*)customSinkSettings;
- (RTObject<WFIAsyncAction>*)stopPreviewAsync;
- (void)prepareLowLagRecordToStorageFileAsync:(WMMMediaEncodingProfile*)encodingProfile file:(RTObject<WSIStorageFile>*)file success:(void (^)(WMCLowLagMediaRecording*))success failure:(void (^)(NSError*))failure;
- (void)prepareLowLagRecordToStreamAsync:(WMMMediaEncodingProfile*)encodingProfile stream:(RTObject<WSSIRandomAccessStream>*)stream success:(void (^)(WMCLowLagMediaRecording*))success failure:(void (^)(NSError*))failure;
- (void)prepareLowLagRecordToCustomSinkAsync:(WMMMediaEncodingProfile*)encodingProfile customMediaSink:(RTObject<WMIMediaExtension>*)customMediaSink success:(void (^)(WMCLowLagMediaRecording*))success failure:(void (^)(NSError*))failure;
- (void)prepareLowLagRecordToCustomSinkIdAsync:(WMMMediaEncodingProfile*)encodingProfile customSinkActivationId:(NSString *)customSinkActivationId customSinkSettings:(RTObject<WFCIPropertySet>*)customSinkSettings success:(void (^)(WMCLowLagMediaRecording*))success failure:(void (^)(NSError*))failure;
- (void)prepareLowLagPhotoCaptureAsync:(WMMImageEncodingProperties*)type success:(void (^)(WMCLowLagPhotoCapture*))success failure:(void (^)(NSError*))failure;
- (void)prepareLowLagPhotoSequenceCaptureAsync:(WMMImageEncodingProperties*)type success:(void (^)(WMCLowLagPhotoSequenceCapture*))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)setEncodingPropertiesAsync:(WMCMediaStreamType)mediaStreamType mediaEncodingProperties:(RTObject<WMMIMediaEncodingProperties>*)mediaEncodingProperties encoderProperties:(WMMMediaPropertySet*)encoderProperties;
- (void)close;
- (void)prepareVariablePhotoSequenceCaptureAsync:(WMMImageEncodingProperties*)type success:(void (^)(WMCCVariablePhotoSequenceCapture*))success failure:(void (^)(NSError*))failure;
- (void)addAudioEffectAsync:(RTObject<WMEIAudioEffectDefinition>*)definition success:(void (^)(RTObject<WMIMediaExtension>*))success failure:(void (^)(NSError*))failure;
- (void)addVideoEffectAsync:(RTObject<WMEIVideoEffectDefinition>*)definition mediaStreamType:(WMCMediaStreamType)mediaStreamType success:(void (^)(RTObject<WMIMediaExtension>*))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)pauseRecordAsync:(WMDMediaCapturePauseBehavior)behavior;
- (RTObject<WFIAsyncAction>*)resumeRecordAsync;
- (void)getPreviewFrameAsyncWithSuccess:(void (^)(WMVideoFrame*))success failure:(void (^)(NSError*))failure;
- (void)getPreviewFrameCopyAsync:(WMVideoFrame*)destination success:(void (^)(WMVideoFrame*))success failure:(void (^)(NSError*))failure;
- (void)prepareAdvancedPhotoCaptureAsync:(WMMImageEncodingProperties*)encodingProperties success:(void (^)(WMCAdvancedPhotoCapture*))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)removeEffectAsync:(RTObject<WMIMediaExtension>*)effect;
- (void)pauseRecordWithResultAsync:(WMDMediaCapturePauseBehavior)behavior success:(void (^)(WMCMediaCapturePauseResult*))success failure:(void (^)(NSError*))failure;
- (void)stopRecordWithResultAsyncWithSuccess:(void (^)(WMCMediaCaptureStopResult*))success failure:(void (^)(NSError*))failure;
- (void)createFrameReaderAsync:(WMCFMediaFrameSource*)inputSource success:(void (^)(WMCFMediaFrameReader*))success failure:(void (^)(NSError*))failure;
- (void)createFrameReaderWithSubtypeAsync:(WMCFMediaFrameSource*)inputSource outputSubtype:(NSString *)outputSubtype success:(void (^)(WMCFMediaFrameReader*))success failure:(void (^)(NSError*))failure;
- (void)createFrameReaderWithSubtypeAndSizeAsync:(WMCFMediaFrameSource*)inputSource outputSubtype:(NSString *)outputSubtype outputSize:(WGIBitmapSize*)outputSize success:(void (^)(WMCFMediaFrameReader*))success failure:(void (^)(NSError*))failure;
- (void)createMultiSourceFrameReaderAsync:(id<NSFastEnumeration> /* WMCFMediaFrameSource* */)inputSources success:(void (^)(WMCFMultiSourceMediaFrameReader*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WMCMediaCapture_DEFINED__

// Windows.Media.Capture.MediaCaptureVideoProfileMediaDescription
#ifndef __WMCMediaCaptureVideoProfileMediaDescription_DEFINED__
#define __WMCMediaCaptureVideoProfileMediaDescription_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaCaptureVideoProfileMediaDescription : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
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

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaCaptureVideoProfile : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * id;
@property (readonly) NSArray* /* WMCMediaCaptureVideoProfileMediaDescription* */ supportedPhotoMediaDescription;
@property (readonly) NSArray* /* WMCMediaCaptureVideoProfileMediaDescription* */ supportedPreviewMediaDescription;
@property (readonly) NSArray* /* WMCMediaCaptureVideoProfileMediaDescription* */ supportedRecordMediaDescription;
@property (readonly) NSString * videoDeviceId;
- (NSArray* /* WMCMediaCaptureVideoProfile* */)getConcurrency;
@end

#endif // __WMCMediaCaptureVideoProfile_DEFINED__

// Windows.Media.Capture.MediaCaptureInitializationSettings
#ifndef __WMCMediaCaptureInitializationSettings_DEFINED__
#define __WMCMediaCaptureInitializationSettings_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaCaptureInitializationSettings : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * videoDeviceId;
@property (retain) NSString * audioDeviceId;
@property WMCPhotoCaptureSource photoCaptureSource;
@property WMCStreamingCaptureMode streamingCaptureMode;
@property WMCMediaCategory mediaCategory;
@property WMAudioProcessing audioProcessing;
@property (retain) RTObject<WMCIMediaSource>* videoSource;
@property (retain) RTObject<WMCIMediaSource>* audioSource;
@property (retain) WMCMediaCaptureVideoProfileMediaDescription* recordMediaDescription;
@property (retain) WMCMediaCaptureVideoProfile* videoProfile;
@property (retain) WMCMediaCaptureVideoProfileMediaDescription* photoMediaDescription;
@property (retain) WMCMediaCaptureVideoProfileMediaDescription* previewMediaDescription;
@property (retain) WMCFMediaFrameSourceGroup* sourceGroup;
@property WMCMediaCaptureSharingMode sharingMode;
@property WMCMediaCaptureMemoryPreference memoryPreference;
@property BOOL alwaysPlaySystemShutterSound;
@end

#endif // __WMCMediaCaptureInitializationSettings_DEFINED__

// Windows.Media.Capture.MediaCaptureSettings
#ifndef __WMCMediaCaptureSettings_DEFINED__
#define __WMCMediaCaptureSettings_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaCaptureSettings : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * audioDeviceId;
@property (readonly) WMCPhotoCaptureSource photoCaptureSource;
@property (readonly) WMCStreamingCaptureMode streamingCaptureMode;
@property (readonly) WMCVideoDeviceCharacteristic videoDeviceCharacteristic;
@property (readonly) NSString * videoDeviceId;
@property (readonly) WMAudioProcessing audioProcessing;
@property (readonly) BOOL cameraSoundRequiredForRegion;
@property (readonly) BOOL concurrentRecordAndPhotoSequenceSupported;
@property (readonly) BOOL concurrentRecordAndPhotoSupported;
@property (readonly) id /* unsigned int */ horizontal35mmEquivalentFocalLength;
@property (readonly) WMCMediaCategory mediaCategory;
@property (readonly) id /* int */ pitchOffsetDegrees;
@property (readonly) id /* unsigned int */ vertical35mmEquivalentFocalLength;
@end

#endif // __WMCMediaCaptureSettings_DEFINED__

// Windows.Media.Capture.LowLagMediaRecording
#ifndef __WMCLowLagMediaRecording_DEFINED__
#define __WMCLowLagMediaRecording_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCLowLagMediaRecording : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (RTObject<WFIAsyncAction>*)startAsync;
- (RTObject<WFIAsyncAction>*)stopAsync;
- (RTObject<WFIAsyncAction>*)finishAsync;
- (RTObject<WFIAsyncAction>*)pauseAsync:(WMDMediaCapturePauseBehavior)behavior;
- (RTObject<WFIAsyncAction>*)resumeAsync;
- (void)pauseWithResultAsync:(WMDMediaCapturePauseBehavior)behavior success:(void (^)(WMCMediaCapturePauseResult*))success failure:(void (^)(NSError*))failure;
- (void)stopWithResultAsyncWithSuccess:(void (^)(WMCMediaCaptureStopResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WMCLowLagMediaRecording_DEFINED__

// Windows.Media.Capture.LowLagPhotoCapture
#ifndef __WMCLowLagPhotoCapture_DEFINED__
#define __WMCLowLagPhotoCapture_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCLowLagPhotoCapture : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)captureAsyncWithSuccess:(void (^)(WMCCapturedPhoto*))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)finishAsync;
@end

#endif // __WMCLowLagPhotoCapture_DEFINED__

// Windows.Media.Capture.LowLagPhotoSequenceCapture
#ifndef __WMCLowLagPhotoSequenceCapture_DEFINED__
#define __WMCLowLagPhotoSequenceCapture_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCLowLagPhotoSequenceCapture : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addPhotoCapturedEvent:(void(^)(WMCLowLagPhotoSequenceCapture*, WMCPhotoCapturedEventArgs*))del;
- (void)removePhotoCapturedEvent:(EventRegistrationToken)tok;
- (RTObject<WFIAsyncAction>*)startAsync;
- (RTObject<WFIAsyncAction>*)stopAsync;
- (RTObject<WFIAsyncAction>*)finishAsync;
@end

#endif // __WMCLowLagPhotoSequenceCapture_DEFINED__

// Windows.Media.Capture.MediaCaptureFocusChangedEventArgs
#ifndef __WMCMediaCaptureFocusChangedEventArgs_DEFINED__
#define __WMCMediaCaptureFocusChangedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaCaptureFocusChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMDMediaCaptureFocusState focusState;
@end

#endif // __WMCMediaCaptureFocusChangedEventArgs_DEFINED__

// Windows.Media.Capture.PhotoConfirmationCapturedEventArgs
#ifndef __WMCPhotoConfirmationCapturedEventArgs_DEFINED__
#define __WMCPhotoConfirmationCapturedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCPhotoConfirmationCapturedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFTimeSpan* captureTimeOffset;
@property (readonly) WMCCapturedFrame* frame;
@end

#endif // __WMCPhotoConfirmationCapturedEventArgs_DEFINED__

// Windows.Media.Capture.AdvancedPhotoCapture
#ifndef __WMCAdvancedPhotoCapture_DEFINED__
#define __WMCAdvancedPhotoCapture_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAdvancedPhotoCapture : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addAllPhotosCapturedEvent:(void(^)(WMCAdvancedPhotoCapture*, RTObject*))del;
- (void)removeAllPhotosCapturedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOptionalReferencePhotoCapturedEvent:(void(^)(WMCAdvancedPhotoCapture*, WMCOptionalReferencePhotoCapturedEventArgs*))del;
- (void)removeOptionalReferencePhotoCapturedEvent:(EventRegistrationToken)tok;
- (void)captureAsyncWithSuccess:(void (^)(WMCAdvancedCapturedPhoto*))success failure:(void (^)(NSError*))failure;
- (void)captureWithContextAsync:(RTObject*)context success:(void (^)(WMCAdvancedCapturedPhoto*))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)finishAsync;
@end

#endif // __WMCAdvancedPhotoCapture_DEFINED__

// Windows.Media.Capture.MediaCapturePauseResult
#ifndef __WMCMediaCapturePauseResult_DEFINED__
#define __WMCMediaCapturePauseResult_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaCapturePauseResult : RTObject <WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMVideoFrame* lastFrame;
@property (readonly) WFTimeSpan* recordDuration;
- (void)close;
@end

#endif // __WMCMediaCapturePauseResult_DEFINED__

// Windows.Media.Capture.MediaCaptureStopResult
#ifndef __WMCMediaCaptureStopResult_DEFINED__
#define __WMCMediaCaptureStopResult_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaCaptureStopResult : RTObject <WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMVideoFrame* lastFrame;
@property (readonly) WFTimeSpan* recordDuration;
- (void)close;
@end

#endif // __WMCMediaCaptureStopResult_DEFINED__

// Windows.Media.Capture.MediaCaptureDeviceExclusiveControlStatusChangedEventArgs
#ifndef __WMCMediaCaptureDeviceExclusiveControlStatusChangedEventArgs_DEFINED__
#define __WMCMediaCaptureDeviceExclusiveControlStatusChangedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaCaptureDeviceExclusiveControlStatusChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * deviceId;
@property (readonly) WMCMediaCaptureDeviceExclusiveControlStatus status;
@end

#endif // __WMCMediaCaptureDeviceExclusiveControlStatusChangedEventArgs_DEFINED__

// Windows.Media.Capture.CapturedPhoto
#ifndef __WMCCapturedPhoto_DEFINED__
#define __WMCCapturedPhoto_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCCapturedPhoto : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMCCapturedFrame* frame;
@property (readonly) WMCCapturedFrame* thumbnail;
@end

#endif // __WMCCapturedPhoto_DEFINED__

// Windows.Media.Capture.AdvancedCapturedPhoto
#ifndef __WMCAdvancedCapturedPhoto_DEFINED__
#define __WMCAdvancedCapturedPhoto_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAdvancedCapturedPhoto : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject* context;
@property (readonly) WMCCapturedFrame* frame;
@property (readonly) WMDAdvancedPhotoMode mode;
@property (readonly) id /* WFRect* */ frameBoundsRelativeToReferencePhoto;
@end

#endif // __WMCAdvancedCapturedPhoto_DEFINED__

// Windows.Media.Capture.OptionalReferencePhotoCapturedEventArgs
#ifndef __WMCOptionalReferencePhotoCapturedEventArgs_DEFINED__
#define __WMCOptionalReferencePhotoCapturedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCOptionalReferencePhotoCapturedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject* context;
@property (readonly) WMCCapturedFrame* frame;
@end

#endif // __WMCOptionalReferencePhotoCapturedEventArgs_DEFINED__

// Windows.Storage.Streams.IInputStream
#ifndef __WSSIInputStream_DEFINED__
#define __WSSIInputStream_DEFINED__

@protocol WSSIInputStream <WFIClosable>
- (void)readAsync:(RTObject<WSSIBuffer>*)buffer count:(unsigned int)count options:(WSSInputStreamOptions)options success:(void (^)(RTObject<WSSIBuffer>*))success progress:(void (^)(unsigned int))progress failure:(void (^)(NSError*))failure;
- (void)close;
@end

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WSSIInputStream : RTObject <WSSIInputStream>
@end

#endif // __WSSIInputStream_DEFINED__

// Windows.Storage.Streams.IOutputStream
#ifndef __WSSIOutputStream_DEFINED__
#define __WSSIOutputStream_DEFINED__

@protocol WSSIOutputStream <WFIClosable>
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer success:(void (^)(unsigned int))success progress:(void (^)(unsigned int))progress failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)close;
@end

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WSSIOutputStream : RTObject <WSSIOutputStream>
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
- (void)readAsync:(RTObject<WSSIBuffer>*)buffer count:(unsigned int)count options:(WSSInputStreamOptions)options success:(void (^)(RTObject<WSSIBuffer>*))success progress:(void (^)(unsigned int))progress failure:(void (^)(NSError*))failure;
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer success:(void (^)(unsigned int))success progress:(void (^)(unsigned int))progress failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WSSIRandomAccessStream : RTObject <WSSIRandomAccessStream>
@end

#endif // __WSSIRandomAccessStream_DEFINED__

// Windows.Storage.Streams.IContentTypeProvider
#ifndef __WSSIContentTypeProvider_DEFINED__
#define __WSSIContentTypeProvider_DEFINED__

@protocol WSSIContentTypeProvider
@property (readonly) NSString * contentType;
@end

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WSSIContentTypeProvider : RTObject <WSSIContentTypeProvider>
@end

#endif // __WSSIContentTypeProvider_DEFINED__

// Windows.Storage.Streams.IRandomAccessStreamWithContentType
#ifndef __WSSIRandomAccessStreamWithContentType_DEFINED__
#define __WSSIRandomAccessStreamWithContentType_DEFINED__

@protocol WSSIRandomAccessStreamWithContentType <WSSIRandomAccessStream, WFIClosable, WSSIInputStream, WSSIOutputStream, WSSIContentTypeProvider>
- (RTObject<WSSIInputStream>*)getInputStreamAt:(uint64_t)position;
- (RTObject<WSSIOutputStream>*)getOutputStreamAt:(uint64_t)position;
- (void)seek:(uint64_t)position;
- (RTObject<WSSIRandomAccessStream>*)cloneStream;
- (void)close;
- (void)readAsync:(RTObject<WSSIBuffer>*)buffer count:(unsigned int)count options:(WSSInputStreamOptions)options success:(void (^)(RTObject<WSSIBuffer>*))success progress:(void (^)(unsigned int))progress failure:(void (^)(NSError*))failure;
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer success:(void (^)(unsigned int))success progress:(void (^)(unsigned int))progress failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WSSIRandomAccessStreamWithContentType : RTObject <WSSIRandomAccessStreamWithContentType>
@end

#endif // __WSSIRandomAccessStreamWithContentType_DEFINED__

// Windows.Media.Capture.CapturedFrame
#ifndef __WMCCapturedFrame_DEFINED__
#define __WMCCapturedFrame_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCCapturedFrame : RTObject <WSSIRandomAccessStreamWithContentType, WSSIContentTypeProvider, WSSIRandomAccessStream, WSSIOutputStream, WFIClosable, WSSIInputStream>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int height;
@property (readonly) unsigned int width;
@property (readonly) WGISoftwareBitmap* softwareBitmap;
@property (readonly) NSString * contentType;
@property uint64_t size;
@property (readonly) BOOL canRead;
@property (readonly) BOOL canWrite;
@property (readonly) uint64_t position;
- (RTObject<WSSIInputStream>*)getInputStreamAt:(uint64_t)position;
- (RTObject<WSSIOutputStream>*)getOutputStreamAt:(uint64_t)position;
- (void)seek:(uint64_t)position;
- (RTObject<WSSIRandomAccessStream>*)cloneStream;
- (void)close;
- (void)readAsync:(RTObject<WSSIBuffer>*)buffer count:(unsigned int)count options:(WSSInputStreamOptions)options success:(void (^)(RTObject<WSSIBuffer>*))success progress:(void (^)(unsigned int))progress failure:(void (^)(NSError*))failure;
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer success:(void (^)(unsigned int))success progress:(void (^)(unsigned int))progress failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WMCCapturedFrame_DEFINED__

// Windows.Media.Capture.PhotoCapturedEventArgs
#ifndef __WMCPhotoCapturedEventArgs_DEFINED__
#define __WMCPhotoCapturedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCPhotoCapturedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFTimeSpan* captureTimeOffset;
@property (readonly) WMCCapturedFrame* frame;
@property (readonly) WMCCapturedFrame* thumbnail;
@end

#endif // __WMCPhotoCapturedEventArgs_DEFINED__

// Windows.Media.Capture.CapturedFrameControlValues
#ifndef __WMCCapturedFrameControlValues_DEFINED__
#define __WMCCapturedFrameControlValues_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCCapturedFrameControlValues : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) id /* WFTimeSpan* */ exposure;
@property (readonly) id /* float */ exposureCompensation;
@property (readonly) id /* float */ flashPowerPercent;
@property (readonly) id /* BOOL */ flashed;
@property (readonly) id /* unsigned int */ focus;
@property (readonly) id /* unsigned int */ isoSpeed;
@property (readonly) id /* WMDCaptureSceneMode */ sceneMode;
@property (readonly) id /* unsigned int */ whiteBalance;
@property (readonly) id /* float */ zoomFactor;
@property (readonly) id /* WMDMediaCaptureFocusState */ focusState;
@property (readonly) id /* double */ isoAnalogGain;
@property (readonly) id /* double */ isoDigitalGain;
@property (readonly) WMMMediaRatio* sensorFrameRate;
@property (readonly) id /* WMCWhiteBalanceGain* */ whiteBalanceGain;
@end

#endif // __WMCCapturedFrameControlValues_DEFINED__

// Windows.Media.Capture.VideoStreamConfiguration
#ifndef __WMCVideoStreamConfiguration_DEFINED__
#define __WMCVideoStreamConfiguration_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCVideoStreamConfiguration : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMMVideoEncodingProperties* inputProperties;
@property (readonly) WMMVideoEncodingProperties* outputProperties;
@end

#endif // __WMCVideoStreamConfiguration_DEFINED__

// Windows.Media.Capture.AppBroadcastGlobalSettings
#ifndef __WMCAppBroadcastGlobalSettings_DEFINED__
#define __WMCAppBroadcastGlobalSettings_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppBroadcastGlobalSettings : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double systemAudioGain;
@property (retain) NSString * selectedCameraId;
@property double microphoneGain;
@property BOOL isMicrophoneCaptureEnabledByDefault;
@property BOOL isEchoCancellationEnabled;
@property BOOL isCursorImageCaptureEnabled;
@property BOOL isCameraCaptureEnabledByDefault;
@property BOOL isAudioCaptureEnabled;
@property WMCAppBroadcastCameraOverlaySize cameraOverlaySize;
@property WMCAppBroadcastCameraOverlayLocation cameraOverlayLocation;
@property (readonly) BOOL hasHardwareEncoder;
@property (readonly) BOOL isBroadcastEnabled;
@property (readonly) BOOL isDisabledByPolicy;
@property (readonly) BOOL isGpuConstrained;
@end

#endif // __WMCAppBroadcastGlobalSettings_DEFINED__

// Windows.Media.Capture.AppBroadcastProviderSettings
#ifndef __WMCAppBroadcastProviderSettings_DEFINED__
#define __WMCAppBroadcastProviderSettings_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppBroadcastProviderSettings : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WMCAppBroadcastVideoEncodingResolutionMode videoEncodingResolutionMode;
@property WMCAppBroadcastVideoEncodingBitrateMode videoEncodingBitrateMode;
@property (retain) NSString * defaultBroadcastTitle;
@property unsigned int customVideoEncodingWidth;
@property unsigned int customVideoEncodingHeight;
@property unsigned int customVideoEncodingBitrate;
@property unsigned int audioEncodingBitrate;
@end

#endif // __WMCAppBroadcastProviderSettings_DEFINED__

// Windows.Media.Capture.AppBroadcastManager
#ifndef __WMCAppBroadcastManager_DEFINED__
#define __WMCAppBroadcastManager_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppBroadcastManager : RTObject
+ (WMCAppBroadcastGlobalSettings*)getGlobalSettings;
+ (void)applyGlobalSettings:(WMCAppBroadcastGlobalSettings*)value;
+ (WMCAppBroadcastProviderSettings*)getProviderSettings;
+ (void)applyProviderSettings:(WMCAppBroadcastProviderSettings*)value;
@end

#endif // __WMCAppBroadcastManager_DEFINED__

// Windows.Media.Capture.AppBroadcastBackgroundServiceSignInInfo
#ifndef __WMCAppBroadcastBackgroundServiceSignInInfo_DEFINED__
#define __WMCAppBroadcastBackgroundServiceSignInInfo_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppBroadcastBackgroundServiceSignInInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * userName;
@property (retain) WFUri* oAuthRequestUri;
@property (retain) WFUri* oAuthCallbackUri;
@property (readonly) WSAWWebAuthenticationResult* authenticationResult;
@property (readonly) WMCAppBroadcastSignInState signInState;
- (EventRegistrationToken)addSignInStateChangedEvent:(void(^)(WMCAppBroadcastBackgroundServiceSignInInfo*, WMCAppBroadcastSignInStateChangedEventArgs*))del;
- (void)removeSignInStateChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUserNameChangedEvent:(void(^)(WMCAppBroadcastBackgroundServiceSignInInfo*, RTObject*))del;
- (void)removeUserNameChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WMCAppBroadcastBackgroundServiceSignInInfo_DEFINED__

// Windows.Media.Capture.AppBroadcastSignInStateChangedEventArgs
#ifndef __WMCAppBroadcastSignInStateChangedEventArgs_DEFINED__
#define __WMCAppBroadcastSignInStateChangedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppBroadcastSignInStateChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMCAppBroadcastSignInResult result;
@property (readonly) WMCAppBroadcastSignInState signInState;
@end

#endif // __WMCAppBroadcastSignInStateChangedEventArgs_DEFINED__

// Windows.Media.Capture.AppBroadcastStreamReader
#ifndef __WMCAppBroadcastStreamReader_DEFINED__
#define __WMCAppBroadcastStreamReader_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppBroadcastStreamReader : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject<WSSIBuffer>* audioAacSequence;
@property (readonly) unsigned int audioBitrate;
@property (readonly) unsigned int audioChannels;
@property (readonly) unsigned int audioSampleRate;
@property (readonly) unsigned int videoBitrate;
@property (readonly) unsigned int videoHeight;
@property (readonly) unsigned int videoWidth;
- (EventRegistrationToken)addAudioFrameArrivedEvent:(void(^)(WMCAppBroadcastStreamReader*, RTObject*))del;
- (void)removeAudioFrameArrivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVideoFrameArrivedEvent:(void(^)(WMCAppBroadcastStreamReader*, RTObject*))del;
- (void)removeVideoFrameArrivedEvent:(EventRegistrationToken)tok;
- (WMCAppBroadcastStreamAudioFrame*)tryGetNextAudioFrame;
- (WMCAppBroadcastStreamVideoFrame*)tryGetNextVideoFrame;
@end

#endif // __WMCAppBroadcastStreamReader_DEFINED__

// Windows.Media.Capture.AppBroadcastBackgroundServiceStreamInfo
#ifndef __WMCAppBroadcastBackgroundServiceStreamInfo_DEFINED__
#define __WMCAppBroadcastBackgroundServiceStreamInfo_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppBroadcastBackgroundServiceStreamInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property uint64_t desiredVideoEncodingBitrate;
@property uint64_t bandwidthTestBitrate;
@property (retain) NSString * audioCodec;
@property (readonly) WMCAppBroadcastStreamReader* broadcastStreamReader;
@property (readonly) WMCAppBroadcastStreamState streamState;
- (EventRegistrationToken)addStreamStateChangedEvent:(void(^)(WMCAppBroadcastBackgroundServiceStreamInfo*, WMCAppBroadcastStreamStateChangedEventArgs*))del;
- (void)removeStreamStateChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVideoEncodingBitrateChangedEvent:(void(^)(WMCAppBroadcastBackgroundServiceStreamInfo*, RTObject*))del;
- (void)removeVideoEncodingBitrateChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVideoEncodingResolutionChangedEvent:(void(^)(WMCAppBroadcastBackgroundServiceStreamInfo*, RTObject*))del;
- (void)removeVideoEncodingResolutionChangedEvent:(EventRegistrationToken)tok;
- (void)reportProblemWithStream;
@end

#endif // __WMCAppBroadcastBackgroundServiceStreamInfo_DEFINED__

// Windows.Media.Capture.AppBroadcastStreamStateChangedEventArgs
#ifndef __WMCAppBroadcastStreamStateChangedEventArgs_DEFINED__
#define __WMCAppBroadcastStreamStateChangedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppBroadcastStreamStateChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMCAppBroadcastStreamState streamState;
@end

#endif // __WMCAppBroadcastStreamStateChangedEventArgs_DEFINED__

// Windows.Media.Capture.AppBroadcastBackgroundService
#ifndef __WMCAppBroadcastBackgroundService_DEFINED__
#define __WMCAppBroadcastBackgroundService_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppBroadcastBackgroundService : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property unsigned int viewerCount;
@property (retain) WMCAppBroadcastBackgroundServiceStreamInfo* streamInfo;
@property (retain) WMCAppBroadcastBackgroundServiceSignInInfo* signInInfo;
@property WMCAppBroadcastPlugInState plugInState;
@property (retain) NSString * broadcastTitle;
@property (readonly) NSString * appId;
@property (readonly) NSString * titleId;
@property (retain) NSString * broadcastLanguage;
@property (retain) NSString * broadcastChannel;
- (EventRegistrationToken)addHeartbeatRequestedEvent:(void(^)(WMCAppBroadcastBackgroundService*, WMCAppBroadcastHeartbeatRequestedEventArgs*))del;
- (void)removeHeartbeatRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addBroadcastChannelChangedEvent:(void(^)(WMCAppBroadcastBackgroundService*, RTObject*))del;
- (void)removeBroadcastChannelChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addBroadcastLanguageChangedEvent:(void(^)(WMCAppBroadcastBackgroundService*, RTObject*))del;
- (void)removeBroadcastLanguageChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addBroadcastTitleChangedEvent:(void(^)(WMCAppBroadcastBackgroundService*, RTObject*))del;
- (void)removeBroadcastTitleChangedEvent:(EventRegistrationToken)tok;
- (void)terminateBroadcast:(WMCAppBroadcastTerminationReason)reason providerSpecificReason:(unsigned int)providerSpecificReason;
@end

#endif // __WMCAppBroadcastBackgroundService_DEFINED__

// Windows.Media.Capture.AppBroadcastHeartbeatRequestedEventArgs
#ifndef __WMCAppBroadcastHeartbeatRequestedEventArgs_DEFINED__
#define __WMCAppBroadcastHeartbeatRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppBroadcastHeartbeatRequestedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@end

#endif // __WMCAppBroadcastHeartbeatRequestedEventArgs_DEFINED__

// Windows.Media.Capture.AppBroadcastStreamAudioFrame
#ifndef __WMCAppBroadcastStreamAudioFrame_DEFINED__
#define __WMCAppBroadcastStreamAudioFrame_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppBroadcastStreamAudioFrame : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject<WSSIBuffer>* audioBuffer;
@property (readonly) WMCAppBroadcastStreamAudioHeader* audioHeader;
@end

#endif // __WMCAppBroadcastStreamAudioFrame_DEFINED__

// Windows.Media.Capture.AppBroadcastStreamVideoFrame
#ifndef __WMCAppBroadcastStreamVideoFrame_DEFINED__
#define __WMCAppBroadcastStreamVideoFrame_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppBroadcastStreamVideoFrame : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject<WSSIBuffer>* videoBuffer;
@property (readonly) WMCAppBroadcastStreamVideoHeader* videoHeader;
@end

#endif // __WMCAppBroadcastStreamVideoFrame_DEFINED__

// Windows.Media.Capture.AppBroadcastStreamVideoHeader
#ifndef __WMCAppBroadcastStreamVideoHeader_DEFINED__
#define __WMCAppBroadcastStreamVideoHeader_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppBroadcastStreamVideoHeader : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFDateTime* absoluteTimestamp;
@property (readonly) WFTimeSpan* duration;
@property (readonly) uint64_t frameId;
@property (readonly) BOOL hasDiscontinuity;
@property (readonly) BOOL isKeyFrame;
@property (readonly) WFTimeSpan* relativeTimestamp;
@end

#endif // __WMCAppBroadcastStreamVideoHeader_DEFINED__

// Windows.Media.Capture.AppBroadcastStreamAudioHeader
#ifndef __WMCAppBroadcastStreamAudioHeader_DEFINED__
#define __WMCAppBroadcastStreamAudioHeader_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppBroadcastStreamAudioHeader : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFDateTime* absoluteTimestamp;
@property (readonly) WFTimeSpan* duration;
@property (readonly) uint64_t frameId;
@property (readonly) BOOL hasDiscontinuity;
@property (readonly) WFTimeSpan* relativeTimestamp;
@end

#endif // __WMCAppBroadcastStreamAudioHeader_DEFINED__

// Windows.Media.Capture.AppBroadcastTriggerDetails
#ifndef __WMCAppBroadcastTriggerDetails_DEFINED__
#define __WMCAppBroadcastTriggerDetails_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppBroadcastTriggerDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMCAppBroadcastBackgroundService* backgroundService;
@end

#endif // __WMCAppBroadcastTriggerDetails_DEFINED__

// Windows.Media.Capture.AppBroadcastPlugInManager
#ifndef __WMCAppBroadcastPlugInManager_DEFINED__
#define __WMCAppBroadcastPlugInManager_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppBroadcastPlugInManager : RTObject
+ (WMCAppBroadcastPlugInManager*)getDefault;
+ (WMCAppBroadcastPlugInManager*)getForUser:(WSUser*)user;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WMCAppBroadcastPlugIn* defaultPlugIn;
@property (readonly) BOOL isBroadcastProviderAvailable;
@property (readonly) NSArray* /* WMCAppBroadcastPlugIn* */ plugInList;
@end

#endif // __WMCAppBroadcastPlugInManager_DEFINED__

// Windows.Media.Capture.AppBroadcastPlugIn
#ifndef __WMCAppBroadcastPlugIn_DEFINED__
#define __WMCAppBroadcastPlugIn_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppBroadcastPlugIn : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * appId;
@property (readonly) NSString * displayName;
@property (readonly) RTObject<WSSIRandomAccessStreamReference>* logo;
@property (readonly) WMCAppBroadcastProviderSettings* providerSettings;
@end

#endif // __WMCAppBroadcastPlugIn_DEFINED__

// Windows.Media.Capture.AppBroadcastPreview
#ifndef __WMCAppBroadcastPreview_DEFINED__
#define __WMCAppBroadcastPreview_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppBroadcastPreview : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) id /* unsigned int */ errorCode;
@property (readonly) WMCAppBroadcastPreviewState previewState;
@property (readonly) WMCAppBroadcastPreviewStreamReader* previewStreamReader;
- (EventRegistrationToken)addPreviewStateChangedEvent:(void(^)(WMCAppBroadcastPreview*, WMCAppBroadcastPreviewStateChangedEventArgs*))del;
- (void)removePreviewStateChangedEvent:(EventRegistrationToken)tok;
- (void)stopPreview;
@end

#endif // __WMCAppBroadcastPreview_DEFINED__

// Windows.Media.Capture.AppBroadcastState
#ifndef __WMCAppBroadcastState_DEFINED__
#define __WMCAppBroadcastState_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppBroadcastState : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WMCAppBroadcastSignInState signInState;
@property BOOL shouldCaptureMicrophone;
@property BOOL shouldCaptureCamera;
@property (retain) WSAWWebAuthenticationResult* authenticationResult;
@property (readonly) BOOL isCaptureTargetRunning;
@property (readonly) unsigned int microphoneCaptureError;
@property (readonly) WMCAppBroadcastMicrophoneCaptureState microphoneCaptureState;
@property (readonly) WFUri* oAuthCallbackUri;
@property (readonly) WFUri* oAuthRequestUri;
@property (readonly) WMCAppBroadcastPlugInState plugInState;
@property (readonly) unsigned int cameraCaptureError;
@property (readonly) WMCAppBroadcastCameraCaptureState cameraCaptureState;
@property (readonly) WFSize* encodedVideoSize;
@property (readonly) WMCAppBroadcastStreamState streamState;
@property (readonly) WMCAppBroadcastTerminationReason terminationReason;
@property (readonly) unsigned int terminationReasonPlugInSpecific;
@property (readonly) unsigned int viewerCount;
- (EventRegistrationToken)addCameraCaptureStateChangedEvent:(void(^)(WMCAppBroadcastState*, WMCAppBroadcastCameraCaptureStateChangedEventArgs*))del;
- (void)removeCameraCaptureStateChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCaptureTargetClosedEvent:(void(^)(WMCAppBroadcastState*, RTObject*))del;
- (void)removeCaptureTargetClosedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMicrophoneCaptureStateChangedEvent:(void(^)(WMCAppBroadcastState*, WMCAppBroadcastMicrophoneCaptureStateChangedEventArgs*))del;
- (void)removeMicrophoneCaptureStateChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPlugInStateChangedEvent:(void(^)(WMCAppBroadcastState*, WMCAppBroadcastPlugInStateChangedEventArgs*))del;
- (void)removePlugInStateChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStreamStateChangedEvent:(void(^)(WMCAppBroadcastState*, WMCAppBroadcastStreamStateChangedEventArgs*))del;
- (void)removeStreamStateChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addViewerCountChangedEvent:(void(^)(WMCAppBroadcastState*, WMCAppBroadcastViewerCountChangedEventArgs*))del;
- (void)removeViewerCountChangedEvent:(EventRegistrationToken)tok;
- (void)restartMicrophoneCapture;
- (void)restartCameraCapture;
@end

#endif // __WMCAppBroadcastState_DEFINED__

// Windows.Media.Capture.AppBroadcastViewerCountChangedEventArgs
#ifndef __WMCAppBroadcastViewerCountChangedEventArgs_DEFINED__
#define __WMCAppBroadcastViewerCountChangedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppBroadcastViewerCountChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int viewerCount;
@end

#endif // __WMCAppBroadcastViewerCountChangedEventArgs_DEFINED__

// Windows.Media.Capture.AppBroadcastMicrophoneCaptureStateChangedEventArgs
#ifndef __WMCAppBroadcastMicrophoneCaptureStateChangedEventArgs_DEFINED__
#define __WMCAppBroadcastMicrophoneCaptureStateChangedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppBroadcastMicrophoneCaptureStateChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int errorCode;
@property (readonly) WMCAppBroadcastMicrophoneCaptureState state;
@end

#endif // __WMCAppBroadcastMicrophoneCaptureStateChangedEventArgs_DEFINED__

// Windows.Media.Capture.AppBroadcastCameraCaptureStateChangedEventArgs
#ifndef __WMCAppBroadcastCameraCaptureStateChangedEventArgs_DEFINED__
#define __WMCAppBroadcastCameraCaptureStateChangedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppBroadcastCameraCaptureStateChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int errorCode;
@property (readonly) WMCAppBroadcastCameraCaptureState state;
@end

#endif // __WMCAppBroadcastCameraCaptureStateChangedEventArgs_DEFINED__

// Windows.Media.Capture.AppBroadcastPlugInStateChangedEventArgs
#ifndef __WMCAppBroadcastPlugInStateChangedEventArgs_DEFINED__
#define __WMCAppBroadcastPlugInStateChangedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppBroadcastPlugInStateChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMCAppBroadcastPlugInState plugInState;
@end

#endif // __WMCAppBroadcastPlugInStateChangedEventArgs_DEFINED__

// Windows.Media.Capture.AppBroadcastPreviewStateChangedEventArgs
#ifndef __WMCAppBroadcastPreviewStateChangedEventArgs_DEFINED__
#define __WMCAppBroadcastPreviewStateChangedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppBroadcastPreviewStateChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int errorCode;
@property (readonly) WMCAppBroadcastPreviewState previewState;
@end

#endif // __WMCAppBroadcastPreviewStateChangedEventArgs_DEFINED__

// Windows.Media.Capture.AppBroadcastPreviewStreamReader
#ifndef __WMCAppBroadcastPreviewStreamReader_DEFINED__
#define __WMCAppBroadcastPreviewStreamReader_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppBroadcastPreviewStreamReader : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGIBitmapAlphaMode videoBitmapAlphaMode;
@property (readonly) WGIBitmapPixelFormat videoBitmapPixelFormat;
@property (readonly) unsigned int videoHeight;
@property (readonly) unsigned int videoStride;
@property (readonly) unsigned int videoWidth;
- (EventRegistrationToken)addVideoFrameArrivedEvent:(void(^)(WMCAppBroadcastPreviewStreamReader*, RTObject*))del;
- (void)removeVideoFrameArrivedEvent:(EventRegistrationToken)tok;
- (WMCAppBroadcastPreviewStreamVideoFrame*)tryGetNextVideoFrame;
@end

#endif // __WMCAppBroadcastPreviewStreamReader_DEFINED__

// Windows.Media.Capture.AppBroadcastPreviewStreamVideoFrame
#ifndef __WMCAppBroadcastPreviewStreamVideoFrame_DEFINED__
#define __WMCAppBroadcastPreviewStreamVideoFrame_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppBroadcastPreviewStreamVideoFrame : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject<WSSIBuffer>* videoBuffer;
@property (readonly) WMCAppBroadcastPreviewStreamVideoHeader* videoHeader;
@end

#endif // __WMCAppBroadcastPreviewStreamVideoFrame_DEFINED__

// Windows.Media.Capture.AppBroadcastPreviewStreamVideoHeader
#ifndef __WMCAppBroadcastPreviewStreamVideoHeader_DEFINED__
#define __WMCAppBroadcastPreviewStreamVideoHeader_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppBroadcastPreviewStreamVideoHeader : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFDateTime* absoluteTimestamp;
@property (readonly) WFTimeSpan* duration;
@property (readonly) uint64_t frameId;
@property (readonly) WFTimeSpan* relativeTimestamp;
@end

#endif // __WMCAppBroadcastPreviewStreamVideoHeader_DEFINED__

// Windows.Media.Capture.AppBroadcastServices
#ifndef __WMCAppBroadcastServices_DEFINED__
#define __WMCAppBroadcastServices_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppBroadcastServices : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WMCAppBroadcastCaptureTargetType captureTargetType;
@property (retain) NSString * broadcastTitle;
@property (retain) NSString * broadcastLanguage;
@property (readonly) BOOL canCapture;
@property (readonly) WMCAppBroadcastState* state;
@property (readonly) NSString * userName;
- (void)enterBroadcastModeAsync:(WMCAppBroadcastPlugIn*)plugIn success:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure;
- (void)exitBroadcastMode:(WMCAppBroadcastExitBroadcastModeReason)reason;
- (void)startBroadcast;
- (void)pauseBroadcast;
- (void)resumeBroadcast;
- (WMCAppBroadcastPreview*)startPreview:(WFSize*)desiredSize;
@end

#endif // __WMCAppBroadcastServices_DEFINED__

// Windows.Media.Capture.AppCaptureSettings
#ifndef __WMCAppCaptureSettings_DEFINED__
#define __WMCAppCaptureSettings_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppCaptureSettings : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isHistoricalCaptureOnWirelessDisplayAllowed;
@property WMCAppCaptureVideoEncodingBitrateMode videoEncodingBitrateMode;
@property BOOL isHistoricalCaptureOnBatteryAllowed;
@property BOOL isAudioCaptureEnabled;
@property BOOL isAppCaptureEnabled;
@property (retain) WSStorageFolder* appCaptureDestinationFolder;
@property unsigned int historicalBufferLength;
@property BOOL isHistoricalCaptureEnabled;
@property unsigned int customVideoEncodingWidth;
@property unsigned int customVideoEncodingHeight;
@property unsigned int customVideoEncodingBitrate;
@property unsigned int audioEncodingBitrate;
@property WMCAppCaptureHistoricalBufferLengthUnit historicalBufferLengthUnit;
@property WMCAppCaptureVideoEncodingResolutionMode videoEncodingResolutionMode;
@property (retain) WSStorageFolder* screenshotDestinationFolder;
@property (retain) WFTimeSpan* maximumRecordLength;
@property (readonly) BOOL hasHardwareEncoder;
@property (readonly) BOOL isCpuConstrained;
@property (readonly) BOOL isMemoryConstrained;
@property (readonly) BOOL isDisabledByPolicy;
@property (readonly) WMCAppCaptureAlternateShortcutKeys* alternateShortcutKeys;
@property (readonly) BOOL isGpuConstrained;
@property BOOL isMicrophoneCaptureEnabled;
@property WMCAppCaptureVideoEncodingFrameRateMode videoEncodingFrameRateMode;
@property double systemAudioGain;
@property double microphoneGain;
@property BOOL isMicrophoneCaptureEnabledByDefault;
@property BOOL isEchoCancellationEnabled;
@property BOOL isCursorImageCaptureEnabled;
@end

#endif // __WMCAppCaptureSettings_DEFINED__

// Windows.Media.Capture.AppCaptureAlternateShortcutKeys
#ifndef __WMCAppCaptureAlternateShortcutKeys_DEFINED__
#define __WMCAppCaptureAlternateShortcutKeys_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppCaptureAlternateShortcutKeys : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WSVirtualKeyModifiers toggleRecordingKeyModifiers;
@property WSVirtualKey toggleRecordingKey;
@property WSVirtualKeyModifiers toggleRecordingIndicatorKeyModifiers;
@property WSVirtualKey toggleRecordingIndicatorKey;
@property WSVirtualKeyModifiers toggleGameBarKeyModifiers;
@property WSVirtualKey toggleGameBarKey;
@property WSVirtualKeyModifiers takeScreenshotKeyModifiers;
@property WSVirtualKey takeScreenshotKey;
@property WSVirtualKeyModifiers saveHistoricalVideoKeyModifiers;
@property WSVirtualKey saveHistoricalVideoKey;
@property WSVirtualKeyModifiers toggleMicrophoneCaptureKeyModifiers;
@property WSVirtualKey toggleMicrophoneCaptureKey;
@property WSVirtualKeyModifiers toggleCameraCaptureKeyModifiers;
@property WSVirtualKey toggleCameraCaptureKey;
@property WSVirtualKeyModifiers toggleBroadcastKeyModifiers;
@property WSVirtualKey toggleBroadcastKey;
@end

#endif // __WMCAppCaptureAlternateShortcutKeys_DEFINED__

// Windows.Media.Capture.AppCaptureManager
#ifndef __WMCAppCaptureManager_DEFINED__
#define __WMCAppCaptureManager_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppCaptureManager : RTObject
+ (WMCAppCaptureSettings*)getCurrentSettings;
+ (void)applySettings:(WMCAppCaptureSettings*)appCaptureSettings;
@end

#endif // __WMCAppCaptureManager_DEFINED__

// Windows.Media.Capture.AppCaptureRecordOperation
#ifndef __WMCAppCaptureRecordOperation_DEFINED__
#define __WMCAppCaptureRecordOperation_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppCaptureRecordOperation : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) id /* WFTimeSpan* */ duration;
@property (readonly) id /* unsigned int */ errorCode;
@property (readonly) WSStorageFile* file;
@property (readonly) id /* BOOL */ isFileTruncated;
@property (readonly) WMCAppCaptureRecordingState state;
- (EventRegistrationToken)addDurationGeneratedEvent:(void(^)(WMCAppCaptureRecordOperation*, WMCAppCaptureDurationGeneratedEventArgs*))del;
- (void)removeDurationGeneratedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addFileGeneratedEvent:(void(^)(WMCAppCaptureRecordOperation*, WMCAppCaptureFileGeneratedEventArgs*))del;
- (void)removeFileGeneratedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStateChangedEvent:(void(^)(WMCAppCaptureRecordOperation*, WMCAppCaptureRecordingStateChangedEventArgs*))del;
- (void)removeStateChangedEvent:(EventRegistrationToken)tok;
- (void)stopRecording;
@end

#endif // __WMCAppCaptureRecordOperation_DEFINED__

// Windows.Media.Capture.AppCaptureState
#ifndef __WMCAppCaptureState_DEFINED__
#define __WMCAppCaptureState_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppCaptureState : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL shouldCaptureMicrophone;
@property (readonly) BOOL isHistoricalCaptureEnabled;
@property (readonly) BOOL isTargetRunning;
@property (readonly) unsigned int microphoneCaptureError;
@property (readonly) WMCAppCaptureMicrophoneCaptureState microphoneCaptureState;
- (EventRegistrationToken)addCaptureTargetClosedEvent:(void(^)(WMCAppCaptureState*, RTObject*))del;
- (void)removeCaptureTargetClosedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMicrophoneCaptureStateChangedEvent:(void(^)(WMCAppCaptureState*, WMCAppCaptureMicrophoneCaptureStateChangedEventArgs*))del;
- (void)removeMicrophoneCaptureStateChangedEvent:(EventRegistrationToken)tok;
- (void)restartMicrophoneCapture;
@end

#endif // __WMCAppCaptureState_DEFINED__

// Windows.Media.Capture.AppCaptureMicrophoneCaptureStateChangedEventArgs
#ifndef __WMCAppCaptureMicrophoneCaptureStateChangedEventArgs_DEFINED__
#define __WMCAppCaptureMicrophoneCaptureStateChangedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppCaptureMicrophoneCaptureStateChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int errorCode;
@property (readonly) WMCAppCaptureMicrophoneCaptureState state;
@end

#endif // __WMCAppCaptureMicrophoneCaptureStateChangedEventArgs_DEFINED__

// Windows.Media.Capture.AppCaptureRecordingStateChangedEventArgs
#ifndef __WMCAppCaptureRecordingStateChangedEventArgs_DEFINED__
#define __WMCAppCaptureRecordingStateChangedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppCaptureRecordingStateChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int errorCode;
@property (readonly) WMCAppCaptureRecordingState state;
@end

#endif // __WMCAppCaptureRecordingStateChangedEventArgs_DEFINED__

// Windows.Media.Capture.AppCaptureDurationGeneratedEventArgs
#ifndef __WMCAppCaptureDurationGeneratedEventArgs_DEFINED__
#define __WMCAppCaptureDurationGeneratedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppCaptureDurationGeneratedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFTimeSpan* duration;
@end

#endif // __WMCAppCaptureDurationGeneratedEventArgs_DEFINED__

// Windows.Media.Capture.AppCaptureFileGeneratedEventArgs
#ifndef __WMCAppCaptureFileGeneratedEventArgs_DEFINED__
#define __WMCAppCaptureFileGeneratedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppCaptureFileGeneratedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSStorageFile* file;
@end

#endif // __WMCAppCaptureFileGeneratedEventArgs_DEFINED__

// Windows.Media.Capture.AppCaptureServices
#ifndef __WMCAppCaptureServices_DEFINED__
#define __WMCAppCaptureServices_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppCaptureServices : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL canCapture;
@property (readonly) WMCAppCaptureState* state;
- (WMCAppCaptureRecordOperation*)record;
- (WMCAppCaptureRecordOperation*)recordTimeSpan:(WFDateTime*)startTime duration:(WFTimeSpan*)duration;
@end

#endif // __WMCAppCaptureServices_DEFINED__

// Windows.Media.Capture.AppCaptureMetadataWriter
#ifndef __WMCAppCaptureMetadataWriter_DEFINED__
#define __WMCAppCaptureMetadataWriter_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAppCaptureMetadataWriter : RTObject <WFIClosable>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) uint64_t remainingStorageBytesAvailable;
- (EventRegistrationToken)addMetadataPurgedEvent:(void(^)(WMCAppCaptureMetadataWriter*, RTObject*))del;
- (void)removeMetadataPurgedEvent:(EventRegistrationToken)tok;
- (void)addStringEvent:(NSString *)name value:(NSString *)value priority:(WMCAppCaptureMetadataPriority)priority;
- (void)addInt32Event:(NSString *)name value:(int)value priority:(WMCAppCaptureMetadataPriority)priority;
- (void)addDoubleEvent:(NSString *)name value:(double)value priority:(WMCAppCaptureMetadataPriority)priority;
- (void)startStringState:(NSString *)name value:(NSString *)value priority:(WMCAppCaptureMetadataPriority)priority;
- (void)startInt32State:(NSString *)name value:(int)value priority:(WMCAppCaptureMetadataPriority)priority;
- (void)startDoubleState:(NSString *)name value:(double)value priority:(WMCAppCaptureMetadataPriority)priority;
- (void)stopState:(NSString *)name;
- (void)stopAllStates;
- (void)close;
@end

#endif // __WMCAppCaptureMetadataWriter_DEFINED__

// Windows.Media.Capture.CameraOptionsUI
#ifndef __WMCCameraOptionsUI_DEFINED__
#define __WMCCameraOptionsUI_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCCameraOptionsUI : RTObject
+ (void)show:(WMCMediaCapture*)mediaCapture;
@end

#endif // __WMCCameraOptionsUI_DEFINED__

// Windows.Media.Capture.GameBarServicesManager
#ifndef __WMCGameBarServicesManager_DEFINED__
#define __WMCGameBarServicesManager_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCGameBarServicesManager : RTObject
+ (WMCGameBarServicesManager*)getDefault;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addGameBarServicesCreatedEvent:(void(^)(WMCGameBarServicesManager*, WMCGameBarServicesManagerGameBarServicesCreatedEventArgs*))del;
- (void)removeGameBarServicesCreatedEvent:(EventRegistrationToken)tok;
@end

#endif // __WMCGameBarServicesManager_DEFINED__

// Windows.Media.Capture.GameBarServicesManagerGameBarServicesCreatedEventArgs
#ifndef __WMCGameBarServicesManagerGameBarServicesCreatedEventArgs_DEFINED__
#define __WMCGameBarServicesManagerGameBarServicesCreatedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCGameBarServicesManagerGameBarServicesCreatedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMCGameBarServices* gameBarServices;
@end

#endif // __WMCGameBarServicesManagerGameBarServicesCreatedEventArgs_DEFINED__

// Windows.Media.Capture.GameBarServices
#ifndef __WMCGameBarServices_DEFINED__
#define __WMCGameBarServices_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCGameBarServices : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMCAppBroadcastServices* appBroadcastServices;
@property (readonly) WMCAppCaptureServices* appCaptureServices;
@property (readonly) NSString * sessionId;
@property (readonly) WMCGameBarTargetCapturePolicy targetCapturePolicy;
@property (readonly) WMCGameBarServicesTargetInfo* targetInfo;
- (EventRegistrationToken)addCommandReceivedEvent:(void(^)(WMCGameBarServices*, WMCGameBarServicesCommandEventArgs*))del;
- (void)removeCommandReceivedEvent:(EventRegistrationToken)tok;
- (void)enableCapture;
- (void)disableCapture;
@end

#endif // __WMCGameBarServices_DEFINED__

// Windows.Media.Capture.GameBarServicesTargetInfo
#ifndef __WMCGameBarServicesTargetInfo_DEFINED__
#define __WMCGameBarServicesTargetInfo_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCGameBarServicesTargetInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * appId;
@property (readonly) WMCGameBarServicesDisplayMode displayMode;
@property (readonly) NSString * displayName;
@property (readonly) NSString * titleId;
@end

#endif // __WMCGameBarServicesTargetInfo_DEFINED__

// Windows.Media.Capture.GameBarServicesCommandEventArgs
#ifndef __WMCGameBarServicesCommandEventArgs_DEFINED__
#define __WMCGameBarServicesCommandEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCGameBarServicesCommandEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMCGameBarCommand command;
@property (readonly) WMCGameBarCommandOrigin origin;
@end

#endif // __WMCGameBarServicesCommandEventArgs_DEFINED__

