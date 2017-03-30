// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Media.Capture.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.Collections.0.h"
#include "Windows.Graphics.Imaging.0.h"
#include "Windows.Media.0.h"
#include "Windows.Media.Capture.Frames.0.h"
#include "Windows.Media.Core.0.h"
#include "Windows.Media.Devices.0.h"
#include "Windows.Media.Effects.0.h"
#include "Windows.Media.MediaProperties.0.h"
#include "Windows.Storage.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.System.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Storage.1.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Media.Capture.Core.1.h"
#include "Windows.Media.1.h"
#include "Windows.Media.Capture.Frames.1.h"
#include "Windows.Media.Devices.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::Capture {

struct WhiteBalanceGain
{
    double R;
    double G;
    double B;
};

}

namespace Windows::Media::Capture {

using WhiteBalanceGain = ABI::Windows::Media::Capture::WhiteBalanceGain;

}

namespace ABI::Windows::Media::Capture {

struct __declspec(uuid("f072728b-b292-4491-9d41-99807a550bbf")) __declspec(novtable) IAdvancedCapturedPhoto : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Frame(Windows::Media::Capture::ICapturedFrame ** value) = 0;
    virtual HRESULT __stdcall get_Mode(winrt::Windows::Media::Devices::AdvancedPhotoMode * value) = 0;
    virtual HRESULT __stdcall get_Context(Windows::Foundation::IInspectable ** value) = 0;
};

struct __declspec(uuid("18cf6cd8-cffe-42d8-8104-017bb318f4a1")) __declspec(novtable) IAdvancedCapturedPhoto2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FrameBoundsRelativeToReferencePhoto(Windows::Foundation::IReference<Windows::Foundation::Rect> ** value) = 0;
};

struct __declspec(uuid("83ffaafa-6667-44dc-973c-a6bce596aa0f")) __declspec(novtable) IAdvancedPhotoCapture : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CaptureAsync(Windows::Foundation::IAsyncOperation<Windows::Media::Capture::AdvancedCapturedPhoto> ** operation) = 0;
    virtual HRESULT __stdcall abi_CaptureWithContextAsync(Windows::Foundation::IInspectable * context, Windows::Foundation::IAsyncOperation<Windows::Media::Capture::AdvancedCapturedPhoto> ** operation) = 0;
    virtual HRESULT __stdcall add_OptionalReferencePhotoCaptured(Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AdvancedPhotoCapture, Windows::Media::Capture::OptionalReferencePhotoCapturedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_OptionalReferencePhotoCaptured(event_token token) = 0;
    virtual HRESULT __stdcall add_AllPhotosCaptured(Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AdvancedPhotoCapture, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_AllPhotosCaptured(event_token token) = 0;
    virtual HRESULT __stdcall abi_FinishAsync(Windows::Foundation::IAsyncAction ** operation) = 0;
};

struct __declspec(uuid("9749d453-a29a-45ed-8f29-22d09942cff7")) __declspec(novtable) IAppCapture : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsCapturingAudio(bool * value) = 0;
    virtual HRESULT __stdcall get_IsCapturingVideo(bool * value) = 0;
    virtual HRESULT __stdcall add_CapturingChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AppCapture, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CapturingChanged(event_token token) = 0;
};

struct __declspec(uuid("19e8e0ef-236c-40f9-b38f-9b7dd65d1ccc")) __declspec(novtable) IAppCaptureAlternateShortcutKeys : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_ToggleGameBarKey(winrt::Windows::System::VirtualKey value) = 0;
    virtual HRESULT __stdcall get_ToggleGameBarKey(winrt::Windows::System::VirtualKey * value) = 0;
    virtual HRESULT __stdcall put_ToggleGameBarKeyModifiers(winrt::Windows::System::VirtualKeyModifiers value) = 0;
    virtual HRESULT __stdcall get_ToggleGameBarKeyModifiers(winrt::Windows::System::VirtualKeyModifiers * value) = 0;
    virtual HRESULT __stdcall put_SaveHistoricalVideoKey(winrt::Windows::System::VirtualKey value) = 0;
    virtual HRESULT __stdcall get_SaveHistoricalVideoKey(winrt::Windows::System::VirtualKey * value) = 0;
    virtual HRESULT __stdcall put_SaveHistoricalVideoKeyModifiers(winrt::Windows::System::VirtualKeyModifiers value) = 0;
    virtual HRESULT __stdcall get_SaveHistoricalVideoKeyModifiers(winrt::Windows::System::VirtualKeyModifiers * value) = 0;
    virtual HRESULT __stdcall put_ToggleRecordingKey(winrt::Windows::System::VirtualKey value) = 0;
    virtual HRESULT __stdcall get_ToggleRecordingKey(winrt::Windows::System::VirtualKey * value) = 0;
    virtual HRESULT __stdcall put_ToggleRecordingKeyModifiers(winrt::Windows::System::VirtualKeyModifiers value) = 0;
    virtual HRESULT __stdcall get_ToggleRecordingKeyModifiers(winrt::Windows::System::VirtualKeyModifiers * value) = 0;
    virtual HRESULT __stdcall put_TakeScreenshotKey(winrt::Windows::System::VirtualKey value) = 0;
    virtual HRESULT __stdcall get_TakeScreenshotKey(winrt::Windows::System::VirtualKey * value) = 0;
    virtual HRESULT __stdcall put_TakeScreenshotKeyModifiers(winrt::Windows::System::VirtualKeyModifiers value) = 0;
    virtual HRESULT __stdcall get_TakeScreenshotKeyModifiers(winrt::Windows::System::VirtualKeyModifiers * value) = 0;
    virtual HRESULT __stdcall put_ToggleRecordingIndicatorKey(winrt::Windows::System::VirtualKey value) = 0;
    virtual HRESULT __stdcall get_ToggleRecordingIndicatorKey(winrt::Windows::System::VirtualKey * value) = 0;
    virtual HRESULT __stdcall put_ToggleRecordingIndicatorKeyModifiers(winrt::Windows::System::VirtualKeyModifiers value) = 0;
    virtual HRESULT __stdcall get_ToggleRecordingIndicatorKeyModifiers(winrt::Windows::System::VirtualKeyModifiers * value) = 0;
};

struct __declspec(uuid("c3669090-dd17-47f0-95e5-ce42286cf338")) __declspec(novtable) IAppCaptureAlternateShortcutKeys2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_ToggleMicrophoneCaptureKey(winrt::Windows::System::VirtualKey value) = 0;
    virtual HRESULT __stdcall get_ToggleMicrophoneCaptureKey(winrt::Windows::System::VirtualKey * value) = 0;
    virtual HRESULT __stdcall put_ToggleMicrophoneCaptureKeyModifiers(winrt::Windows::System::VirtualKeyModifiers value) = 0;
    virtual HRESULT __stdcall get_ToggleMicrophoneCaptureKeyModifiers(winrt::Windows::System::VirtualKeyModifiers * value) = 0;
};

struct __declspec(uuid("7b81448c-418e-469c-a49a-45b597c826b6")) __declspec(novtable) IAppCaptureAlternateShortcutKeys3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_ToggleCameraCaptureKey(winrt::Windows::System::VirtualKey value) = 0;
    virtual HRESULT __stdcall get_ToggleCameraCaptureKey(winrt::Windows::System::VirtualKey * value) = 0;
    virtual HRESULT __stdcall put_ToggleCameraCaptureKeyModifiers(winrt::Windows::System::VirtualKeyModifiers value) = 0;
    virtual HRESULT __stdcall get_ToggleCameraCaptureKeyModifiers(winrt::Windows::System::VirtualKeyModifiers * value) = 0;
    virtual HRESULT __stdcall put_ToggleBroadcastKey(winrt::Windows::System::VirtualKey value) = 0;
    virtual HRESULT __stdcall get_ToggleBroadcastKey(winrt::Windows::System::VirtualKey * value) = 0;
    virtual HRESULT __stdcall put_ToggleBroadcastKeyModifiers(winrt::Windows::System::VirtualKeyModifiers value) = 0;
    virtual HRESULT __stdcall get_ToggleBroadcastKeyModifiers(winrt::Windows::System::VirtualKeyModifiers * value) = 0;
};

struct __declspec(uuid("7d9e3ea7-6282-4735-8d4e-aa45f90f6723")) __declspec(novtable) IAppCaptureManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetCurrentSettings(Windows::Media::Capture::IAppCaptureSettings ** value) = 0;
    virtual HRESULT __stdcall abi_ApplySettings(Windows::Media::Capture::IAppCaptureSettings * appCaptureSettings) = 0;
};

struct __declspec(uuid("14683a86-8807-48d3-883a-970ee4532a39")) __declspec(novtable) IAppCaptureSettings : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_AppCaptureDestinationFolder(Windows::Storage::IStorageFolder * value) = 0;
    virtual HRESULT __stdcall get_AppCaptureDestinationFolder(Windows::Storage::IStorageFolder ** value) = 0;
    virtual HRESULT __stdcall put_AudioEncodingBitrate(uint32_t value) = 0;
    virtual HRESULT __stdcall get_AudioEncodingBitrate(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_IsAudioCaptureEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsAudioCaptureEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_CustomVideoEncodingBitrate(uint32_t value) = 0;
    virtual HRESULT __stdcall get_CustomVideoEncodingBitrate(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_CustomVideoEncodingHeight(uint32_t value) = 0;
    virtual HRESULT __stdcall get_CustomVideoEncodingHeight(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_CustomVideoEncodingWidth(uint32_t value) = 0;
    virtual HRESULT __stdcall get_CustomVideoEncodingWidth(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_HistoricalBufferLength(uint32_t value) = 0;
    virtual HRESULT __stdcall get_HistoricalBufferLength(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_HistoricalBufferLengthUnit(winrt::Windows::Media::Capture::AppCaptureHistoricalBufferLengthUnit value) = 0;
    virtual HRESULT __stdcall get_HistoricalBufferLengthUnit(winrt::Windows::Media::Capture::AppCaptureHistoricalBufferLengthUnit * value) = 0;
    virtual HRESULT __stdcall put_IsHistoricalCaptureEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsHistoricalCaptureEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsHistoricalCaptureOnBatteryAllowed(bool value) = 0;
    virtual HRESULT __stdcall get_IsHistoricalCaptureOnBatteryAllowed(bool * value) = 0;
    virtual HRESULT __stdcall put_IsHistoricalCaptureOnWirelessDisplayAllowed(bool value) = 0;
    virtual HRESULT __stdcall get_IsHistoricalCaptureOnWirelessDisplayAllowed(bool * value) = 0;
    virtual HRESULT __stdcall put_MaximumRecordLength(Windows::Foundation::TimeSpan value) = 0;
    virtual HRESULT __stdcall get_MaximumRecordLength(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall put_ScreenshotDestinationFolder(Windows::Storage::IStorageFolder * value) = 0;
    virtual HRESULT __stdcall get_ScreenshotDestinationFolder(Windows::Storage::IStorageFolder ** value) = 0;
    virtual HRESULT __stdcall put_VideoEncodingBitrateMode(winrt::Windows::Media::Capture::AppCaptureVideoEncodingBitrateMode value) = 0;
    virtual HRESULT __stdcall get_VideoEncodingBitrateMode(winrt::Windows::Media::Capture::AppCaptureVideoEncodingBitrateMode * value) = 0;
    virtual HRESULT __stdcall put_VideoEncodingResolutionMode(winrt::Windows::Media::Capture::AppCaptureVideoEncodingResolutionMode value) = 0;
    virtual HRESULT __stdcall get_VideoEncodingResolutionMode(winrt::Windows::Media::Capture::AppCaptureVideoEncodingResolutionMode * value) = 0;
    virtual HRESULT __stdcall put_IsAppCaptureEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsAppCaptureEnabled(bool * value) = 0;
    virtual HRESULT __stdcall get_IsCpuConstrained(bool * value) = 0;
    virtual HRESULT __stdcall get_IsDisabledByPolicy(bool * value) = 0;
    virtual HRESULT __stdcall get_IsMemoryConstrained(bool * value) = 0;
    virtual HRESULT __stdcall get_HasHardwareEncoder(bool * value) = 0;
};

struct __declspec(uuid("fcb8cee7-e26b-476f-9b1a-ec342d2a8fde")) __declspec(novtable) IAppCaptureSettings2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsGpuConstrained(bool * value) = 0;
    virtual HRESULT __stdcall get_AlternateShortcutKeys(Windows::Media::Capture::IAppCaptureAlternateShortcutKeys ** value) = 0;
};

struct __declspec(uuid("a93502fe-88c2-42d6-aaaa-40feffd75aec")) __declspec(novtable) IAppCaptureSettings3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_IsMicrophoneCaptureEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsMicrophoneCaptureEnabled(bool * value) = 0;
};

struct __declspec(uuid("07c2774c-1a81-482f-a244-049d95f25b0b")) __declspec(novtable) IAppCaptureSettings4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_IsMicrophoneCaptureEnabledByDefault(bool value) = 0;
    virtual HRESULT __stdcall get_IsMicrophoneCaptureEnabledByDefault(bool * value) = 0;
    virtual HRESULT __stdcall put_SystemAudioGain(double value) = 0;
    virtual HRESULT __stdcall get_SystemAudioGain(double * value) = 0;
    virtual HRESULT __stdcall put_MicrophoneGain(double value) = 0;
    virtual HRESULT __stdcall get_MicrophoneGain(double * value) = 0;
    virtual HRESULT __stdcall put_VideoEncodingFrameRateMode(winrt::Windows::Media::Capture::AppCaptureVideoEncodingFrameRateMode value) = 0;
    virtual HRESULT __stdcall get_VideoEncodingFrameRateMode(winrt::Windows::Media::Capture::AppCaptureVideoEncodingFrameRateMode * value) = 0;
};

struct __declspec(uuid("f922dd6c-0a7e-4e74-8b20-9c1f902d08a1")) __declspec(novtable) IAppCaptureStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetForCurrentView(Windows::Media::Capture::IAppCapture ** value) = 0;
};

struct __declspec(uuid("48587540-6f93-4bb4-b8f3-e89e48948c91")) __declspec(novtable) ICameraCaptureUI : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PhotoSettings(Windows::Media::Capture::ICameraCaptureUIPhotoCaptureSettings ** value) = 0;
    virtual HRESULT __stdcall get_VideoSettings(Windows::Media::Capture::ICameraCaptureUIVideoCaptureSettings ** value) = 0;
    virtual HRESULT __stdcall abi_CaptureFileAsync(winrt::Windows::Media::Capture::CameraCaptureUIMode mode, Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> ** asyncInfo) = 0;
};

struct __declspec(uuid("b9f5be97-3472-46a8-8a9e-04ce42ccc97d")) __declspec(novtable) ICameraCaptureUIPhotoCaptureSettings : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Format(winrt::Windows::Media::Capture::CameraCaptureUIPhotoFormat * value) = 0;
    virtual HRESULT __stdcall put_Format(winrt::Windows::Media::Capture::CameraCaptureUIPhotoFormat value) = 0;
    virtual HRESULT __stdcall get_MaxResolution(winrt::Windows::Media::Capture::CameraCaptureUIMaxPhotoResolution * value) = 0;
    virtual HRESULT __stdcall put_MaxResolution(winrt::Windows::Media::Capture::CameraCaptureUIMaxPhotoResolution value) = 0;
    virtual HRESULT __stdcall get_CroppedSizeInPixels(Windows::Foundation::Size * value) = 0;
    virtual HRESULT __stdcall put_CroppedSizeInPixels(Windows::Foundation::Size value) = 0;
    virtual HRESULT __stdcall get_CroppedAspectRatio(Windows::Foundation::Size * value) = 0;
    virtual HRESULT __stdcall put_CroppedAspectRatio(Windows::Foundation::Size value) = 0;
    virtual HRESULT __stdcall get_AllowCropping(bool * value) = 0;
    virtual HRESULT __stdcall put_AllowCropping(bool value) = 0;
};

struct __declspec(uuid("64e92d1f-a28d-425a-b84f-e568335ff24e")) __declspec(novtable) ICameraCaptureUIVideoCaptureSettings : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Format(winrt::Windows::Media::Capture::CameraCaptureUIVideoFormat * value) = 0;
    virtual HRESULT __stdcall put_Format(winrt::Windows::Media::Capture::CameraCaptureUIVideoFormat value) = 0;
    virtual HRESULT __stdcall get_MaxResolution(winrt::Windows::Media::Capture::CameraCaptureUIMaxVideoResolution * value) = 0;
    virtual HRESULT __stdcall put_MaxResolution(winrt::Windows::Media::Capture::CameraCaptureUIMaxVideoResolution value) = 0;
    virtual HRESULT __stdcall get_MaxDurationInSeconds(float * value) = 0;
    virtual HRESULT __stdcall put_MaxDurationInSeconds(float value) = 0;
    virtual HRESULT __stdcall get_AllowTrimming(bool * value) = 0;
    virtual HRESULT __stdcall put_AllowTrimming(bool value) = 0;
};

struct __declspec(uuid("3b0d5e34-3906-4b7d-946c-7bde844499ae")) __declspec(novtable) ICameraOptionsUIStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Show(Windows::Media::Capture::IMediaCapture * mediaCapture) = 0;
};

struct __declspec(uuid("1dd2de1f-571b-44d8-8e80-a08a1578766e")) __declspec(novtable) ICapturedFrame : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Width(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Height(uint32_t * value) = 0;
};

struct __declspec(uuid("90c65b7f-4e0d-4ca4-882d-7a144fed0a90")) __declspec(novtable) ICapturedFrameControlValues : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Exposure(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> ** value) = 0;
    virtual HRESULT __stdcall get_ExposureCompensation(Windows::Foundation::IReference<float> ** value) = 0;
    virtual HRESULT __stdcall get_IsoSpeed(Windows::Foundation::IReference<uint32_t> ** value) = 0;
    virtual HRESULT __stdcall get_Focus(Windows::Foundation::IReference<uint32_t> ** value) = 0;
    virtual HRESULT __stdcall get_SceneMode(Windows::Foundation::IReference<winrt::Windows::Media::Devices::CaptureSceneMode> ** value) = 0;
    virtual HRESULT __stdcall get_Flashed(Windows::Foundation::IReference<bool> ** value) = 0;
    virtual HRESULT __stdcall get_FlashPowerPercent(Windows::Foundation::IReference<float> ** value) = 0;
    virtual HRESULT __stdcall get_WhiteBalance(Windows::Foundation::IReference<uint32_t> ** value) = 0;
    virtual HRESULT __stdcall get_ZoomFactor(Windows::Foundation::IReference<float> ** value) = 0;
};

struct __declspec(uuid("500b2b88-06d2-4aa7-a7db-d37af73321d8")) __declspec(novtable) ICapturedFrameControlValues2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FocusState(Windows::Foundation::IReference<winrt::Windows::Media::Devices::MediaCaptureFocusState> ** value) = 0;
    virtual HRESULT __stdcall get_IsoDigitalGain(Windows::Foundation::IReference<double> ** value) = 0;
    virtual HRESULT __stdcall get_IsoAnalogGain(Windows::Foundation::IReference<double> ** value) = 0;
    virtual HRESULT __stdcall get_SensorFrameRate(Windows::Media::MediaProperties::IMediaRatio ** value) = 0;
    virtual HRESULT __stdcall get_WhiteBalanceGain(Windows::Foundation::IReference<Windows::Media::Capture::WhiteBalanceGain> ** value) = 0;
};

struct __declspec(uuid("b58e8b6e-8503-49b5-9e86-897d26a3ff3d")) __declspec(novtable) ICapturedFrameWithSoftwareBitmap : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SoftwareBitmap(Windows::Graphics::Imaging::ISoftwareBitmap ** value) = 0;
};

struct __declspec(uuid("b0ce7e5a-cfcc-4d6c-8ad1-0869208aca16")) __declspec(novtable) ICapturedPhoto : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Frame(Windows::Media::Capture::ICapturedFrame ** value) = 0;
    virtual HRESULT __stdcall get_Thumbnail(Windows::Media::Capture::ICapturedFrame ** value) = 0;
};

struct __declspec(uuid("41c8baf7-ff3f-49f0-a477-f195e3ce5108")) __declspec(novtable) ILowLagMediaRecording : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_StartAsync(Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_StopAsync(Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_FinishAsync(Windows::Foundation::IAsyncAction ** operation) = 0;
};

struct __declspec(uuid("6369c758-5644-41e2-97af-8ef56a25e225")) __declspec(novtable) ILowLagMediaRecording2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_PauseAsync(winrt::Windows::Media::Devices::MediaCapturePauseBehavior behavior, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_ResumeAsync(Windows::Foundation::IAsyncAction ** operation) = 0;
};

struct __declspec(uuid("5c33ab12-48f7-47da-b41e-90880a5fe0ec")) __declspec(novtable) ILowLagMediaRecording3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_PauseWithResultAsync(winrt::Windows::Media::Devices::MediaCapturePauseBehavior behavior, Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCapturePauseResult> ** operation) = 0;
    virtual HRESULT __stdcall abi_StopWithResultAsync(Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCaptureStopResult> ** operation) = 0;
};

struct __declspec(uuid("a37251b7-6b44-473d-8f24-f703d6c0ec44")) __declspec(novtable) ILowLagPhotoCapture : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CaptureAsync(Windows::Foundation::IAsyncOperation<Windows::Media::Capture::CapturedPhoto> ** operation) = 0;
    virtual HRESULT __stdcall abi_FinishAsync(Windows::Foundation::IAsyncAction ** operation) = 0;
};

struct __declspec(uuid("7cc346bb-b9a9-4c91-8ffa-287e9c668669")) __declspec(novtable) ILowLagPhotoSequenceCapture : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_StartAsync(Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_StopAsync(Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_FinishAsync(Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall add_PhotoCaptured(Windows::Foundation::TypedEventHandler<Windows::Media::Capture::LowLagPhotoSequenceCapture, Windows::Media::Capture::PhotoCapturedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PhotoCaptured(event_token token) = 0;
};

struct __declspec(uuid("c61afbb4-fb10-4a34-ac18-ca80d9c8e7ee")) __declspec(novtable) IMediaCapture : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_InitializeAsync(Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_InitializeWithSettingsAsync(Windows::Media::Capture::IMediaCaptureInitializationSettings * mediaCaptureInitializationSettings, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_StartRecordToStorageFileAsync(Windows::Media::MediaProperties::IMediaEncodingProfile * encodingProfile, Windows::Storage::IStorageFile * file, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_StartRecordToStreamAsync(Windows::Media::MediaProperties::IMediaEncodingProfile * encodingProfile, Windows::Storage::Streams::IRandomAccessStream * stream, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_StartRecordToCustomSinkAsync(Windows::Media::MediaProperties::IMediaEncodingProfile * encodingProfile, Windows::Media::IMediaExtension * customMediaSink, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_StartRecordToCustomSinkIdAsync(Windows::Media::MediaProperties::IMediaEncodingProfile * encodingProfile, hstring customSinkActivationId, Windows::Foundation::Collections::IPropertySet * customSinkSettings, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_StopRecordAsync(Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_CapturePhotoToStorageFileAsync(Windows::Media::MediaProperties::IImageEncodingProperties * type, Windows::Storage::IStorageFile * file, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_CapturePhotoToStreamAsync(Windows::Media::MediaProperties::IImageEncodingProperties * type, Windows::Storage::Streams::IRandomAccessStream * stream, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_AddEffectAsync(winrt::Windows::Media::Capture::MediaStreamType mediaStreamType, hstring effectActivationID, Windows::Foundation::Collections::IPropertySet * effectSettings, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_ClearEffectsAsync(winrt::Windows::Media::Capture::MediaStreamType mediaStreamType, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_SetEncoderProperty(winrt::Windows::Media::Capture::MediaStreamType mediaStreamType, GUID propertyId, Windows::Foundation::IInspectable * propertyValue) = 0;
    virtual HRESULT __stdcall abi_GetEncoderProperty(winrt::Windows::Media::Capture::MediaStreamType mediaStreamType, GUID propertyId, Windows::Foundation::IInspectable ** propertyValue) = 0;
    virtual HRESULT __stdcall add_Failed(Windows::Media::Capture::MediaCaptureFailedEventHandler * errorEventHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_Failed(event_token eventCookie) = 0;
    virtual HRESULT __stdcall add_RecordLimitationExceeded(Windows::Media::Capture::RecordLimitationExceededEventHandler * recordLimitationExceededEventHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_RecordLimitationExceeded(event_token eventCookie) = 0;
    virtual HRESULT __stdcall get_MediaCaptureSettings(Windows::Media::Capture::IMediaCaptureSettings ** value) = 0;
    virtual HRESULT __stdcall get_AudioDeviceController(Windows::Media::Devices::IAudioDeviceController ** value) = 0;
    virtual HRESULT __stdcall get_VideoDeviceController(Windows::Media::Devices::IVideoDeviceController ** value) = 0;
    virtual HRESULT __stdcall abi_SetPreviewMirroring(bool value) = 0;
    virtual HRESULT __stdcall abi_GetPreviewMirroring(bool * value) = 0;
    virtual HRESULT __stdcall abi_SetPreviewRotation(winrt::Windows::Media::Capture::VideoRotation value) = 0;
    virtual HRESULT __stdcall abi_GetPreviewRotation(winrt::Windows::Media::Capture::VideoRotation * value) = 0;
    virtual HRESULT __stdcall abi_SetRecordRotation(winrt::Windows::Media::Capture::VideoRotation value) = 0;
    virtual HRESULT __stdcall abi_GetRecordRotation(winrt::Windows::Media::Capture::VideoRotation * value) = 0;
};

struct __declspec(uuid("9cc68260-7da1-4043-b652-21b8878daff9")) __declspec(novtable) IMediaCapture2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_PrepareLowLagRecordToStorageFileAsync(Windows::Media::MediaProperties::IMediaEncodingProfile * encodingProfile, Windows::Storage::IStorageFile * file, Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording> ** operation) = 0;
    virtual HRESULT __stdcall abi_PrepareLowLagRecordToStreamAsync(Windows::Media::MediaProperties::IMediaEncodingProfile * encodingProfile, Windows::Storage::Streams::IRandomAccessStream * stream, Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording> ** operation) = 0;
    virtual HRESULT __stdcall abi_PrepareLowLagRecordToCustomSinkAsync(Windows::Media::MediaProperties::IMediaEncodingProfile * encodingProfile, Windows::Media::IMediaExtension * customMediaSink, Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording> ** operation) = 0;
    virtual HRESULT __stdcall abi_PrepareLowLagRecordToCustomSinkIdAsync(Windows::Media::MediaProperties::IMediaEncodingProfile * encodingProfile, hstring customSinkActivationId, Windows::Foundation::Collections::IPropertySet * customSinkSettings, Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording> ** operation) = 0;
    virtual HRESULT __stdcall abi_PrepareLowLagPhotoCaptureAsync(Windows::Media::MediaProperties::IImageEncodingProperties * type, Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagPhotoCapture> ** operation) = 0;
    virtual HRESULT __stdcall abi_PrepareLowLagPhotoSequenceCaptureAsync(Windows::Media::MediaProperties::IImageEncodingProperties * type, Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagPhotoSequenceCapture> ** operation) = 0;
    virtual HRESULT __stdcall abi_SetEncodingPropertiesAsync(winrt::Windows::Media::Capture::MediaStreamType mediaStreamType, Windows::Media::MediaProperties::IMediaEncodingProperties * mediaEncodingProperties, Windows::Foundation::Collections::IMap<GUID, Windows::Foundation::IInspectable> * encoderProperties, Windows::Foundation::IAsyncAction ** operation) = 0;
};

struct __declspec(uuid("d4136f30-1564-466e-bc0a-af94e02ab016")) __declspec(novtable) IMediaCapture3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_PrepareVariablePhotoSequenceCaptureAsync(Windows::Media::MediaProperties::IImageEncodingProperties * type, Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Core::VariablePhotoSequenceCapture> ** operation) = 0;
    virtual HRESULT __stdcall add_FocusChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Media::Capture::MediaCaptureFocusChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_FocusChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_PhotoConfirmationCaptured(Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Media::Capture::PhotoConfirmationCapturedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PhotoConfirmationCaptured(event_token token) = 0;
};

struct __declspec(uuid("bacd6fd6-fb08-4947-aea2-ce14eff0ce13")) __declspec(novtable) IMediaCapture4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_AddAudioEffectAsync(Windows::Media::Effects::IAudioEffectDefinition * definition, Windows::Foundation::IAsyncOperation<Windows::Media::IMediaExtension> ** op) = 0;
    virtual HRESULT __stdcall abi_AddVideoEffectAsync(Windows::Media::Effects::IVideoEffectDefinition * definition, winrt::Windows::Media::Capture::MediaStreamType mediaStreamType, Windows::Foundation::IAsyncOperation<Windows::Media::IMediaExtension> ** op) = 0;
    virtual HRESULT __stdcall abi_PauseRecordAsync(winrt::Windows::Media::Devices::MediaCapturePauseBehavior behavior, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_ResumeRecordAsync(Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall add_CameraStreamStateChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CameraStreamStateChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_CameraStreamState(winrt::Windows::Media::Devices::CameraStreamState * streamState) = 0;
    virtual HRESULT __stdcall abi_GetPreviewFrameAsync(Windows::Foundation::IAsyncOperation<Windows::Media::VideoFrame> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetPreviewFrameCopyAsync(Windows::Media::IVideoFrame * destination, Windows::Foundation::IAsyncOperation<Windows::Media::VideoFrame> ** operation) = 0;
    virtual HRESULT __stdcall add_ThermalStatusChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ThermalStatusChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_ThermalStatus(winrt::Windows::Media::Capture::MediaCaptureThermalStatus * value) = 0;
    virtual HRESULT __stdcall abi_PrepareAdvancedPhotoCaptureAsync(Windows::Media::MediaProperties::IImageEncodingProperties * encodingProperties, Windows::Foundation::IAsyncOperation<Windows::Media::Capture::AdvancedPhotoCapture> ** operation) = 0;
};

struct __declspec(uuid("da787c22-3a9b-4720-a71e-97900a316e5a")) __declspec(novtable) IMediaCapture5 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RemoveEffectAsync(Windows::Media::IMediaExtension * effect, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_PauseRecordWithResultAsync(winrt::Windows::Media::Devices::MediaCapturePauseBehavior behavior, Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCapturePauseResult> ** operation) = 0;
    virtual HRESULT __stdcall abi_StopRecordWithResultAsync(Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCaptureStopResult> ** operation) = 0;
    virtual HRESULT __stdcall get_FrameSources(Windows::Foundation::Collections::IMapView<hstring, Windows::Media::Capture::Frames::MediaFrameSource> ** value) = 0;
    virtual HRESULT __stdcall abi_CreateFrameReaderAsync(Windows::Media::Capture::Frames::IMediaFrameSource * inputSource, Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameReader> ** value) = 0;
    virtual HRESULT __stdcall abi_CreateFrameReaderWithSubtypeAsync(Windows::Media::Capture::Frames::IMediaFrameSource * inputSource, hstring outputSubtype, Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameReader> ** value) = 0;
    virtual HRESULT __stdcall abi_CreateFrameReaderWithSubtypeAndSizeAsync(Windows::Media::Capture::Frames::IMediaFrameSource * inputSource, hstring outputSubtype, Windows::Graphics::Imaging::BitmapSize outputSize, Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameReader> ** value) = 0;
};

struct __declspec(uuid("80fde3f4-54c4-42c0-8d19-cea1a87ca18b")) __declspec(novtable) IMediaCaptureFailedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Message(hstring * value) = 0;
    virtual HRESULT __stdcall get_Code(uint32_t * value) = 0;
};

struct __declspec(uuid("81e1bc7f-2277-493e-abee-d3f44ff98c04")) __declspec(novtable) IMediaCaptureFocusChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FocusState(winrt::Windows::Media::Devices::MediaCaptureFocusState * value) = 0;
};

struct __declspec(uuid("9782ba70-ea65-4900-9356-8ca887726884")) __declspec(novtable) IMediaCaptureInitializationSettings : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_AudioDeviceId(hstring value) = 0;
    virtual HRESULT __stdcall get_AudioDeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall put_VideoDeviceId(hstring value) = 0;
    virtual HRESULT __stdcall get_VideoDeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall put_StreamingCaptureMode(winrt::Windows::Media::Capture::StreamingCaptureMode value) = 0;
    virtual HRESULT __stdcall get_StreamingCaptureMode(winrt::Windows::Media::Capture::StreamingCaptureMode * value) = 0;
    virtual HRESULT __stdcall put_PhotoCaptureSource(winrt::Windows::Media::Capture::PhotoCaptureSource value) = 0;
    virtual HRESULT __stdcall get_PhotoCaptureSource(winrt::Windows::Media::Capture::PhotoCaptureSource * value) = 0;
};

struct __declspec(uuid("404e0626-c9dc-43e9-aee4-e6bf1b57b44c")) __declspec(novtable) IMediaCaptureInitializationSettings2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_MediaCategory(winrt::Windows::Media::Capture::MediaCategory value) = 0;
    virtual HRESULT __stdcall get_MediaCategory(winrt::Windows::Media::Capture::MediaCategory * value) = 0;
    virtual HRESULT __stdcall put_AudioProcessing(winrt::Windows::Media::AudioProcessing value) = 0;
    virtual HRESULT __stdcall get_AudioProcessing(winrt::Windows::Media::AudioProcessing * value) = 0;
};

struct __declspec(uuid("4160519d-be48-4730-8104-0cf6e9e97948")) __declspec(novtable) IMediaCaptureInitializationSettings3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_AudioSource(Windows::Media::Core::IMediaSource * value) = 0;
    virtual HRESULT __stdcall get_AudioSource(Windows::Media::Core::IMediaSource ** value) = 0;
    virtual HRESULT __stdcall put_VideoSource(Windows::Media::Core::IMediaSource * value) = 0;
    virtual HRESULT __stdcall get_VideoSource(Windows::Media::Core::IMediaSource ** value) = 0;
};

struct __declspec(uuid("f502a537-4cb7-4d28-95ed-4f9f012e0518")) __declspec(novtable) IMediaCaptureInitializationSettings4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_VideoProfile(Windows::Media::Capture::IMediaCaptureVideoProfile ** value) = 0;
    virtual HRESULT __stdcall put_VideoProfile(Windows::Media::Capture::IMediaCaptureVideoProfile * value) = 0;
    virtual HRESULT __stdcall get_PreviewMediaDescription(Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription ** value) = 0;
    virtual HRESULT __stdcall put_PreviewMediaDescription(Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription * value) = 0;
    virtual HRESULT __stdcall get_RecordMediaDescription(Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription ** value) = 0;
    virtual HRESULT __stdcall put_RecordMediaDescription(Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription * value) = 0;
    virtual HRESULT __stdcall get_PhotoMediaDescription(Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription ** value) = 0;
    virtual HRESULT __stdcall put_PhotoMediaDescription(Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription * value) = 0;
};

struct __declspec(uuid("d5a2e3b8-2626-4e94-b7b3-5308a0f64b1a")) __declspec(novtable) IMediaCaptureInitializationSettings5 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SourceGroup(Windows::Media::Capture::Frames::IMediaFrameSourceGroup ** value) = 0;
    virtual HRESULT __stdcall put_SourceGroup(Windows::Media::Capture::Frames::IMediaFrameSourceGroup * value) = 0;
    virtual HRESULT __stdcall get_SharingMode(winrt::Windows::Media::Capture::MediaCaptureSharingMode * value) = 0;
    virtual HRESULT __stdcall put_SharingMode(winrt::Windows::Media::Capture::MediaCaptureSharingMode value) = 0;
    virtual HRESULT __stdcall get_MemoryPreference(winrt::Windows::Media::Capture::MediaCaptureMemoryPreference * value) = 0;
    virtual HRESULT __stdcall put_MemoryPreference(winrt::Windows::Media::Capture::MediaCaptureMemoryPreference value) = 0;
};

struct __declspec(uuid("aec47ca3-4477-4b04-a06f-2c1c5182fe9d")) __declspec(novtable) IMediaCapturePauseResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LastFrame(Windows::Media::IVideoFrame ** value) = 0;
    virtual HRESULT __stdcall get_RecordDuration(Windows::Foundation::TimeSpan * value) = 0;
};

struct __declspec(uuid("1d83aafe-6d45-4477-8dc4-ac5bc01c4091")) __declspec(novtable) IMediaCaptureSettings : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AudioDeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_VideoDeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_StreamingCaptureMode(winrt::Windows::Media::Capture::StreamingCaptureMode * value) = 0;
    virtual HRESULT __stdcall get_PhotoCaptureSource(winrt::Windows::Media::Capture::PhotoCaptureSource * value) = 0;
    virtual HRESULT __stdcall get_VideoDeviceCharacteristic(winrt::Windows::Media::Capture::VideoDeviceCharacteristic * value) = 0;
};

struct __declspec(uuid("6f9e7cfb-fa9f-4b13-9cbe-5ab94f1f3493")) __declspec(novtable) IMediaCaptureSettings2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ConcurrentRecordAndPhotoSupported(bool * value) = 0;
    virtual HRESULT __stdcall get_ConcurrentRecordAndPhotoSequenceSupported(bool * value) = 0;
    virtual HRESULT __stdcall get_CameraSoundRequiredForRegion(bool * value) = 0;
    virtual HRESULT __stdcall get_Horizontal35mmEquivalentFocalLength(Windows::Foundation::IReference<uint32_t> ** value) = 0;
    virtual HRESULT __stdcall get_PitchOffsetDegrees(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall get_Vertical35mmEquivalentFocalLength(Windows::Foundation::IReference<uint32_t> ** value) = 0;
    virtual HRESULT __stdcall get_MediaCategory(winrt::Windows::Media::Capture::MediaCategory * value) = 0;
    virtual HRESULT __stdcall get_AudioProcessing(winrt::Windows::Media::AudioProcessing * value) = 0;
};

struct __declspec(uuid("acef81ff-99ed-4645-965e-1925cfc63834")) __declspec(novtable) IMediaCaptureStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_IsVideoProfileSupported(hstring videoDeviceId, bool * value) = 0;
    virtual HRESULT __stdcall abi_FindAllVideoProfiles(hstring videoDeviceId, Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> ** value) = 0;
    virtual HRESULT __stdcall abi_FindConcurrentProfiles(hstring videoDeviceId, Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> ** value) = 0;
    virtual HRESULT __stdcall abi_FindKnownVideoProfiles(hstring videoDeviceId, winrt::Windows::Media::Capture::KnownVideoProfile name, Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> ** value) = 0;
};

struct __declspec(uuid("f9db6a2a-a092-4ad1-97d4-f201f9d082db")) __declspec(novtable) IMediaCaptureStopResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LastFrame(Windows::Media::IVideoFrame ** value) = 0;
    virtual HRESULT __stdcall get_RecordDuration(Windows::Foundation::TimeSpan * value) = 0;
};

struct __declspec(uuid("27727073-549e-447f-a20a-4f03c479d8c0")) __declspec(novtable) IMediaCaptureVideoPreview : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_StartPreviewAsync(Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_StartPreviewToCustomSinkAsync(Windows::Media::MediaProperties::IMediaEncodingProfile * encodingProfile, Windows::Media::IMediaExtension * customMediaSink, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_StartPreviewToCustomSinkIdAsync(Windows::Media::MediaProperties::IMediaEncodingProfile * encodingProfile, hstring customSinkActivationId, Windows::Foundation::Collections::IPropertySet * customSinkSettings, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_StopPreviewAsync(Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
};

struct __declspec(uuid("21a073bf-a3ee-4ecf-9ef6-50b0bc4e1305")) __declspec(novtable) IMediaCaptureVideoProfile : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_VideoDeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_SupportedPreviewMediaDescription(Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription> ** value) = 0;
    virtual HRESULT __stdcall get_SupportedRecordMediaDescription(Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription> ** value) = 0;
    virtual HRESULT __stdcall get_SupportedPhotoMediaDescription(Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription> ** value) = 0;
    virtual HRESULT __stdcall abi_GetConcurrency(Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> ** value) = 0;
};

struct __declspec(uuid("8012afef-b691-49ff-83f2-c1e76eaaea1b")) __declspec(novtable) IMediaCaptureVideoProfileMediaDescription : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Width(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Height(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_FrameRate(double * value) = 0;
    virtual HRESULT __stdcall get_IsVariablePhotoSequenceSupported(bool * value) = 0;
    virtual HRESULT __stdcall get_IsHdrVideoSupported(bool * value) = 0;
};

struct __declspec(uuid("470f88b3-1e6d-4051-9c8b-f1d85af047b7")) __declspec(novtable) IOptionalReferencePhotoCapturedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Frame(Windows::Media::Capture::ICapturedFrame ** value) = 0;
    virtual HRESULT __stdcall get_Context(Windows::Foundation::IInspectable ** value) = 0;
};

struct __declspec(uuid("373bfbc1-984e-4ff0-bf85-1c00aabc5a45")) __declspec(novtable) IPhotoCapturedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Frame(Windows::Media::Capture::ICapturedFrame ** value) = 0;
    virtual HRESULT __stdcall get_Thumbnail(Windows::Media::Capture::ICapturedFrame ** value) = 0;
    virtual HRESULT __stdcall get_CaptureTimeOffset(Windows::Foundation::TimeSpan * value) = 0;
};

struct __declspec(uuid("ab473672-c28a-4827-8f8d-3636d3beb51e")) __declspec(novtable) IPhotoConfirmationCapturedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Frame(Windows::Media::Capture::ICapturedFrame ** value) = 0;
    virtual HRESULT __stdcall get_CaptureTimeOffset(Windows::Foundation::TimeSpan * value) = 0;
};

struct __declspec(uuid("89179ef7-cd12-4e0e-a6d4-5b3de98b2e9b")) __declspec(novtable) IScreenCapture : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AudioSource(Windows::Media::Core::IMediaSource ** value) = 0;
    virtual HRESULT __stdcall get_VideoSource(Windows::Media::Core::IMediaSource ** value) = 0;
    virtual HRESULT __stdcall get_IsAudioSuspended(bool * value) = 0;
    virtual HRESULT __stdcall get_IsVideoSuspended(bool * value) = 0;
    virtual HRESULT __stdcall add_SourceSuspensionChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Capture::ScreenCapture, Windows::Media::Capture::SourceSuspensionChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SourceSuspensionChanged(event_token token) = 0;
};

struct __declspec(uuid("c898c3b0-c8a5-11e2-8b8b-0800200c9a66")) __declspec(novtable) IScreenCaptureStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetForCurrentView(Windows::Media::Capture::IScreenCapture ** value) = 0;
};

struct __declspec(uuid("2ece7b5e-d49b-4394-bc32-f97d6cedec1c")) __declspec(novtable) ISourceSuspensionChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsAudioSuspended(bool * value) = 0;
    virtual HRESULT __stdcall get_IsVideoSuspended(bool * value) = 0;
};

struct __declspec(uuid("d8770a6f-4390-4b5e-ad3e-0f8af0963490")) __declspec(novtable) IVideoStreamConfiguration : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_InputProperties(Windows::Media::MediaProperties::IVideoEncodingProperties ** value) = 0;
    virtual HRESULT __stdcall get_OutputProperties(Windows::Media::MediaProperties::IVideoEncodingProperties ** value) = 0;
};

struct __declspec(uuid("2014effb-5cd8-4f08-a314-0d360da59f14")) __declspec(novtable) MediaCaptureFailedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Media::Capture::IMediaCapture * sender, Windows::Media::Capture::IMediaCaptureFailedEventArgs * errorEventArgs) = 0;
};

struct __declspec(uuid("3fae8f2e-4fe1-4ffd-aaba-e1f1337d4e53")) __declspec(novtable) RecordLimitationExceededEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Media::Capture::IMediaCapture * sender) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Media::Capture::AdvancedCapturedPhoto> { using default_interface = Windows::Media::Capture::IAdvancedCapturedPhoto; };
template <> struct traits<Windows::Media::Capture::AdvancedPhotoCapture> { using default_interface = Windows::Media::Capture::IAdvancedPhotoCapture; };
template <> struct traits<Windows::Media::Capture::AppCapture> { using default_interface = Windows::Media::Capture::IAppCapture; };
template <> struct traits<Windows::Media::Capture::AppCaptureAlternateShortcutKeys> { using default_interface = Windows::Media::Capture::IAppCaptureAlternateShortcutKeys; };
template <> struct traits<Windows::Media::Capture::AppCaptureSettings> { using default_interface = Windows::Media::Capture::IAppCaptureSettings; };
template <> struct traits<Windows::Media::Capture::CameraCaptureUI> { using default_interface = Windows::Media::Capture::ICameraCaptureUI; };
template <> struct traits<Windows::Media::Capture::CameraCaptureUIPhotoCaptureSettings> { using default_interface = Windows::Media::Capture::ICameraCaptureUIPhotoCaptureSettings; };
template <> struct traits<Windows::Media::Capture::CameraCaptureUIVideoCaptureSettings> { using default_interface = Windows::Media::Capture::ICameraCaptureUIVideoCaptureSettings; };
template <> struct traits<Windows::Media::Capture::CapturedFrame> { using default_interface = Windows::Media::Capture::ICapturedFrame; };
template <> struct traits<Windows::Media::Capture::CapturedFrameControlValues> { using default_interface = Windows::Media::Capture::ICapturedFrameControlValues; };
template <> struct traits<Windows::Media::Capture::CapturedPhoto> { using default_interface = Windows::Media::Capture::ICapturedPhoto; };
template <> struct traits<Windows::Media::Capture::LowLagMediaRecording> { using default_interface = Windows::Media::Capture::ILowLagMediaRecording; };
template <> struct traits<Windows::Media::Capture::LowLagPhotoCapture> { using default_interface = Windows::Media::Capture::ILowLagPhotoCapture; };
template <> struct traits<Windows::Media::Capture::LowLagPhotoSequenceCapture> { using default_interface = Windows::Media::Capture::ILowLagPhotoSequenceCapture; };
template <> struct traits<Windows::Media::Capture::MediaCapture> { using default_interface = Windows::Media::Capture::IMediaCapture; };
template <> struct traits<Windows::Media::Capture::MediaCaptureFailedEventArgs> { using default_interface = Windows::Media::Capture::IMediaCaptureFailedEventArgs; };
template <> struct traits<Windows::Media::Capture::MediaCaptureFocusChangedEventArgs> { using default_interface = Windows::Media::Capture::IMediaCaptureFocusChangedEventArgs; };
template <> struct traits<Windows::Media::Capture::MediaCaptureInitializationSettings> { using default_interface = Windows::Media::Capture::IMediaCaptureInitializationSettings; };
template <> struct traits<Windows::Media::Capture::MediaCapturePauseResult> { using default_interface = Windows::Media::Capture::IMediaCapturePauseResult; };
template <> struct traits<Windows::Media::Capture::MediaCaptureSettings> { using default_interface = Windows::Media::Capture::IMediaCaptureSettings; };
template <> struct traits<Windows::Media::Capture::MediaCaptureStopResult> { using default_interface = Windows::Media::Capture::IMediaCaptureStopResult; };
template <> struct traits<Windows::Media::Capture::MediaCaptureVideoProfile> { using default_interface = Windows::Media::Capture::IMediaCaptureVideoProfile; };
template <> struct traits<Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription> { using default_interface = Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription; };
template <> struct traits<Windows::Media::Capture::OptionalReferencePhotoCapturedEventArgs> { using default_interface = Windows::Media::Capture::IOptionalReferencePhotoCapturedEventArgs; };
template <> struct traits<Windows::Media::Capture::PhotoCapturedEventArgs> { using default_interface = Windows::Media::Capture::IPhotoCapturedEventArgs; };
template <> struct traits<Windows::Media::Capture::PhotoConfirmationCapturedEventArgs> { using default_interface = Windows::Media::Capture::IPhotoConfirmationCapturedEventArgs; };
template <> struct traits<Windows::Media::Capture::ScreenCapture> { using default_interface = Windows::Media::Capture::IScreenCapture; };
template <> struct traits<Windows::Media::Capture::SourceSuspensionChangedEventArgs> { using default_interface = Windows::Media::Capture::ISourceSuspensionChangedEventArgs; };
template <> struct traits<Windows::Media::Capture::VideoStreamConfiguration> { using default_interface = Windows::Media::Capture::IVideoStreamConfiguration; };

}

namespace Windows::Media::Capture {

template <typename D>
struct WINRT_EBO impl_IAdvancedCapturedPhoto
{
    Windows::Media::Capture::CapturedFrame Frame() const;
    Windows::Media::Devices::AdvancedPhotoMode Mode() const;
    Windows::Foundation::IInspectable Context() const;
};

template <typename D>
struct WINRT_EBO impl_IAdvancedCapturedPhoto2
{
    Windows::Foundation::IReference<Windows::Foundation::Rect> FrameBoundsRelativeToReferencePhoto() const;
};

template <typename D>
struct WINRT_EBO impl_IAdvancedPhotoCapture
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::AdvancedCapturedPhoto> CaptureAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::AdvancedCapturedPhoto> CaptureAsync(const Windows::Foundation::IInspectable & context) const;
    event_token OptionalReferencePhotoCaptured(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AdvancedPhotoCapture, Windows::Media::Capture::OptionalReferencePhotoCapturedEventArgs> & handler) const;
    using OptionalReferencePhotoCaptured_revoker = event_revoker<IAdvancedPhotoCapture>;
    OptionalReferencePhotoCaptured_revoker OptionalReferencePhotoCaptured(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AdvancedPhotoCapture, Windows::Media::Capture::OptionalReferencePhotoCapturedEventArgs> & handler) const;
    void OptionalReferencePhotoCaptured(event_token token) const;
    event_token AllPhotosCaptured(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AdvancedPhotoCapture, Windows::Foundation::IInspectable> & handler) const;
    using AllPhotosCaptured_revoker = event_revoker<IAdvancedPhotoCapture>;
    AllPhotosCaptured_revoker AllPhotosCaptured(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AdvancedPhotoCapture, Windows::Foundation::IInspectable> & handler) const;
    void AllPhotosCaptured(event_token token) const;
    Windows::Foundation::IAsyncAction FinishAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IAppCapture
{
    bool IsCapturingAudio() const;
    bool IsCapturingVideo() const;
    event_token CapturingChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AppCapture, Windows::Foundation::IInspectable> & handler) const;
    using CapturingChanged_revoker = event_revoker<IAppCapture>;
    CapturingChanged_revoker CapturingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AppCapture, Windows::Foundation::IInspectable> & handler) const;
    void CapturingChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IAppCaptureAlternateShortcutKeys
{
    void ToggleGameBarKey(Windows::System::VirtualKey value) const;
    Windows::System::VirtualKey ToggleGameBarKey() const;
    void ToggleGameBarKeyModifiers(Windows::System::VirtualKeyModifiers value) const;
    Windows::System::VirtualKeyModifiers ToggleGameBarKeyModifiers() const;
    void SaveHistoricalVideoKey(Windows::System::VirtualKey value) const;
    Windows::System::VirtualKey SaveHistoricalVideoKey() const;
    void SaveHistoricalVideoKeyModifiers(Windows::System::VirtualKeyModifiers value) const;
    Windows::System::VirtualKeyModifiers SaveHistoricalVideoKeyModifiers() const;
    void ToggleRecordingKey(Windows::System::VirtualKey value) const;
    Windows::System::VirtualKey ToggleRecordingKey() const;
    void ToggleRecordingKeyModifiers(Windows::System::VirtualKeyModifiers value) const;
    Windows::System::VirtualKeyModifiers ToggleRecordingKeyModifiers() const;
    void TakeScreenshotKey(Windows::System::VirtualKey value) const;
    Windows::System::VirtualKey TakeScreenshotKey() const;
    void TakeScreenshotKeyModifiers(Windows::System::VirtualKeyModifiers value) const;
    Windows::System::VirtualKeyModifiers TakeScreenshotKeyModifiers() const;
    void ToggleRecordingIndicatorKey(Windows::System::VirtualKey value) const;
    Windows::System::VirtualKey ToggleRecordingIndicatorKey() const;
    void ToggleRecordingIndicatorKeyModifiers(Windows::System::VirtualKeyModifiers value) const;
    Windows::System::VirtualKeyModifiers ToggleRecordingIndicatorKeyModifiers() const;
};

template <typename D>
struct WINRT_EBO impl_IAppCaptureAlternateShortcutKeys2
{
    void ToggleMicrophoneCaptureKey(Windows::System::VirtualKey value) const;
    Windows::System::VirtualKey ToggleMicrophoneCaptureKey() const;
    void ToggleMicrophoneCaptureKeyModifiers(Windows::System::VirtualKeyModifiers value) const;
    Windows::System::VirtualKeyModifiers ToggleMicrophoneCaptureKeyModifiers() const;
};

template <typename D>
struct WINRT_EBO impl_IAppCaptureAlternateShortcutKeys3
{
    void ToggleCameraCaptureKey(Windows::System::VirtualKey value) const;
    Windows::System::VirtualKey ToggleCameraCaptureKey() const;
    void ToggleCameraCaptureKeyModifiers(Windows::System::VirtualKeyModifiers value) const;
    Windows::System::VirtualKeyModifiers ToggleCameraCaptureKeyModifiers() const;
    void ToggleBroadcastKey(Windows::System::VirtualKey value) const;
    Windows::System::VirtualKey ToggleBroadcastKey() const;
    void ToggleBroadcastKeyModifiers(Windows::System::VirtualKeyModifiers value) const;
    Windows::System::VirtualKeyModifiers ToggleBroadcastKeyModifiers() const;
};

template <typename D>
struct WINRT_EBO impl_IAppCaptureManagerStatics
{
    Windows::Media::Capture::AppCaptureSettings GetCurrentSettings() const;
    void ApplySettings(const Windows::Media::Capture::AppCaptureSettings & appCaptureSettings) const;
};

template <typename D>
struct WINRT_EBO impl_IAppCaptureSettings
{
    void AppCaptureDestinationFolder(const Windows::Storage::StorageFolder & value) const;
    Windows::Storage::StorageFolder AppCaptureDestinationFolder() const;
    void AudioEncodingBitrate(uint32_t value) const;
    uint32_t AudioEncodingBitrate() const;
    void IsAudioCaptureEnabled(bool value) const;
    bool IsAudioCaptureEnabled() const;
    void CustomVideoEncodingBitrate(uint32_t value) const;
    uint32_t CustomVideoEncodingBitrate() const;
    void CustomVideoEncodingHeight(uint32_t value) const;
    uint32_t CustomVideoEncodingHeight() const;
    void CustomVideoEncodingWidth(uint32_t value) const;
    uint32_t CustomVideoEncodingWidth() const;
    void HistoricalBufferLength(uint32_t value) const;
    uint32_t HistoricalBufferLength() const;
    void HistoricalBufferLengthUnit(Windows::Media::Capture::AppCaptureHistoricalBufferLengthUnit value) const;
    Windows::Media::Capture::AppCaptureHistoricalBufferLengthUnit HistoricalBufferLengthUnit() const;
    void IsHistoricalCaptureEnabled(bool value) const;
    bool IsHistoricalCaptureEnabled() const;
    void IsHistoricalCaptureOnBatteryAllowed(bool value) const;
    bool IsHistoricalCaptureOnBatteryAllowed() const;
    void IsHistoricalCaptureOnWirelessDisplayAllowed(bool value) const;
    bool IsHistoricalCaptureOnWirelessDisplayAllowed() const;
    void MaximumRecordLength(const Windows::Foundation::TimeSpan & value) const;
    Windows::Foundation::TimeSpan MaximumRecordLength() const;
    void ScreenshotDestinationFolder(const Windows::Storage::StorageFolder & value) const;
    Windows::Storage::StorageFolder ScreenshotDestinationFolder() const;
    void VideoEncodingBitrateMode(Windows::Media::Capture::AppCaptureVideoEncodingBitrateMode value) const;
    Windows::Media::Capture::AppCaptureVideoEncodingBitrateMode VideoEncodingBitrateMode() const;
    void VideoEncodingResolutionMode(Windows::Media::Capture::AppCaptureVideoEncodingResolutionMode value) const;
    Windows::Media::Capture::AppCaptureVideoEncodingResolutionMode VideoEncodingResolutionMode() const;
    void IsAppCaptureEnabled(bool value) const;
    bool IsAppCaptureEnabled() const;
    bool IsCpuConstrained() const;
    bool IsDisabledByPolicy() const;
    bool IsMemoryConstrained() const;
    bool HasHardwareEncoder() const;
};

template <typename D>
struct WINRT_EBO impl_IAppCaptureSettings2
{
    bool IsGpuConstrained() const;
    Windows::Media::Capture::AppCaptureAlternateShortcutKeys AlternateShortcutKeys() const;
};

template <typename D>
struct WINRT_EBO impl_IAppCaptureSettings3
{
    void IsMicrophoneCaptureEnabled(bool value) const;
    bool IsMicrophoneCaptureEnabled() const;
};

template <typename D>
struct WINRT_EBO impl_IAppCaptureSettings4
{
    void IsMicrophoneCaptureEnabledByDefault(bool value) const;
    bool IsMicrophoneCaptureEnabledByDefault() const;
    void SystemAudioGain(double value) const;
    double SystemAudioGain() const;
    void MicrophoneGain(double value) const;
    double MicrophoneGain() const;
    void VideoEncodingFrameRateMode(Windows::Media::Capture::AppCaptureVideoEncodingFrameRateMode value) const;
    Windows::Media::Capture::AppCaptureVideoEncodingFrameRateMode VideoEncodingFrameRateMode() const;
};

template <typename D>
struct WINRT_EBO impl_IAppCaptureStatics
{
    Windows::Media::Capture::AppCapture GetForCurrentView() const;
};

template <typename D>
struct WINRT_EBO impl_ICameraCaptureUI
{
    Windows::Media::Capture::CameraCaptureUIPhotoCaptureSettings PhotoSettings() const;
    Windows::Media::Capture::CameraCaptureUIVideoCaptureSettings VideoSettings() const;
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> CaptureFileAsync(Windows::Media::Capture::CameraCaptureUIMode mode) const;
};

template <typename D>
struct WINRT_EBO impl_ICameraCaptureUIPhotoCaptureSettings
{
    Windows::Media::Capture::CameraCaptureUIPhotoFormat Format() const;
    void Format(Windows::Media::Capture::CameraCaptureUIPhotoFormat value) const;
    Windows::Media::Capture::CameraCaptureUIMaxPhotoResolution MaxResolution() const;
    void MaxResolution(Windows::Media::Capture::CameraCaptureUIMaxPhotoResolution value) const;
    Windows::Foundation::Size CroppedSizeInPixels() const;
    void CroppedSizeInPixels(const Windows::Foundation::Size & value) const;
    Windows::Foundation::Size CroppedAspectRatio() const;
    void CroppedAspectRatio(const Windows::Foundation::Size & value) const;
    bool AllowCropping() const;
    void AllowCropping(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_ICameraCaptureUIVideoCaptureSettings
{
    Windows::Media::Capture::CameraCaptureUIVideoFormat Format() const;
    void Format(Windows::Media::Capture::CameraCaptureUIVideoFormat value) const;
    Windows::Media::Capture::CameraCaptureUIMaxVideoResolution MaxResolution() const;
    void MaxResolution(Windows::Media::Capture::CameraCaptureUIMaxVideoResolution value) const;
    float MaxDurationInSeconds() const;
    void MaxDurationInSeconds(float value) const;
    bool AllowTrimming() const;
    void AllowTrimming(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_ICameraOptionsUIStatics
{
    void Show(const Windows::Media::Capture::MediaCapture & mediaCapture) const;
};

template <typename D>
struct WINRT_EBO impl_ICapturedFrame
{
    uint32_t Width() const;
    uint32_t Height() const;
};

template <typename D>
struct WINRT_EBO impl_ICapturedFrameControlValues
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> Exposure() const;
    Windows::Foundation::IReference<float> ExposureCompensation() const;
    Windows::Foundation::IReference<uint32_t> IsoSpeed() const;
    Windows::Foundation::IReference<uint32_t> Focus() const;
    Windows::Foundation::IReference<winrt::Windows::Media::Devices::CaptureSceneMode> SceneMode() const;
    Windows::Foundation::IReference<bool> Flashed() const;
    Windows::Foundation::IReference<float> FlashPowerPercent() const;
    Windows::Foundation::IReference<uint32_t> WhiteBalance() const;
    Windows::Foundation::IReference<float> ZoomFactor() const;
};

template <typename D>
struct WINRT_EBO impl_ICapturedFrameControlValues2
{
    Windows::Foundation::IReference<winrt::Windows::Media::Devices::MediaCaptureFocusState> FocusState() const;
    Windows::Foundation::IReference<double> IsoDigitalGain() const;
    Windows::Foundation::IReference<double> IsoAnalogGain() const;
    Windows::Media::MediaProperties::MediaRatio SensorFrameRate() const;
    Windows::Foundation::IReference<Windows::Media::Capture::WhiteBalanceGain> WhiteBalanceGain() const;
};

template <typename D>
struct WINRT_EBO impl_ICapturedFrameWithSoftwareBitmap
{
    Windows::Graphics::Imaging::SoftwareBitmap SoftwareBitmap() const;
};

template <typename D>
struct WINRT_EBO impl_ICapturedPhoto
{
    Windows::Media::Capture::CapturedFrame Frame() const;
    Windows::Media::Capture::CapturedFrame Thumbnail() const;
};

template <typename D>
struct WINRT_EBO impl_ILowLagMediaRecording
{
    Windows::Foundation::IAsyncAction StartAsync() const;
    Windows::Foundation::IAsyncAction StopAsync() const;
    Windows::Foundation::IAsyncAction FinishAsync() const;
};

template <typename D>
struct WINRT_EBO impl_ILowLagMediaRecording2
{
    Windows::Foundation::IAsyncAction PauseAsync(Windows::Media::Devices::MediaCapturePauseBehavior behavior) const;
    Windows::Foundation::IAsyncAction ResumeAsync() const;
};

template <typename D>
struct WINRT_EBO impl_ILowLagMediaRecording3
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCapturePauseResult> PauseWithResultAsync(Windows::Media::Devices::MediaCapturePauseBehavior behavior) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCaptureStopResult> StopWithResultAsync() const;
};

template <typename D>
struct WINRT_EBO impl_ILowLagPhotoCapture
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::CapturedPhoto> CaptureAsync() const;
    Windows::Foundation::IAsyncAction FinishAsync() const;
};

template <typename D>
struct WINRT_EBO impl_ILowLagPhotoSequenceCapture
{
    Windows::Foundation::IAsyncAction StartAsync() const;
    Windows::Foundation::IAsyncAction StopAsync() const;
    Windows::Foundation::IAsyncAction FinishAsync() const;
    event_token PhotoCaptured(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::LowLagPhotoSequenceCapture, Windows::Media::Capture::PhotoCapturedEventArgs> & handler) const;
    using PhotoCaptured_revoker = event_revoker<ILowLagPhotoSequenceCapture>;
    PhotoCaptured_revoker PhotoCaptured(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::LowLagPhotoSequenceCapture, Windows::Media::Capture::PhotoCapturedEventArgs> & handler) const;
    void PhotoCaptured(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaCapture
{
    Windows::Foundation::IAsyncAction InitializeAsync() const;
    Windows::Foundation::IAsyncAction InitializeAsync(const Windows::Media::Capture::MediaCaptureInitializationSettings & mediaCaptureInitializationSettings) const;
    Windows::Foundation::IAsyncAction StartRecordToStorageFileAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, const Windows::Storage::IStorageFile & file) const;
    Windows::Foundation::IAsyncAction StartRecordToStreamAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, const Windows::Storage::Streams::IRandomAccessStream & stream) const;
    Windows::Foundation::IAsyncAction StartRecordToCustomSinkAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, const Windows::Media::IMediaExtension & customMediaSink) const;
    Windows::Foundation::IAsyncAction StartRecordToCustomSinkAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, hstring_view customSinkActivationId, const Windows::Foundation::Collections::IPropertySet & customSinkSettings) const;
    Windows::Foundation::IAsyncAction StopRecordAsync() const;
    Windows::Foundation::IAsyncAction CapturePhotoToStorageFileAsync(const Windows::Media::MediaProperties::ImageEncodingProperties & type, const Windows::Storage::IStorageFile & file) const;
    Windows::Foundation::IAsyncAction CapturePhotoToStreamAsync(const Windows::Media::MediaProperties::ImageEncodingProperties & type, const Windows::Storage::Streams::IRandomAccessStream & stream) const;
    [[deprecated("AddEffectAsync might not be available in future versions of Windows. Starting with Windows Threshold, use AddAudioEffectAsync and AddVideoEffectAsync instead")]] Windows::Foundation::IAsyncAction AddEffectAsync(Windows::Media::Capture::MediaStreamType mediaStreamType, hstring_view effectActivationID, const Windows::Foundation::Collections::IPropertySet & effectSettings) const;
    Windows::Foundation::IAsyncAction ClearEffectsAsync(Windows::Media::Capture::MediaStreamType mediaStreamType) const;
    void SetEncoderProperty(Windows::Media::Capture::MediaStreamType mediaStreamType, GUID propertyId, const Windows::Foundation::IInspectable & propertyValue) const;
    Windows::Foundation::IInspectable GetEncoderProperty(Windows::Media::Capture::MediaStreamType mediaStreamType, GUID propertyId) const;
    event_token Failed(const Windows::Media::Capture::MediaCaptureFailedEventHandler & errorEventHandler) const;
    using Failed_revoker = event_revoker<IMediaCapture>;
    Failed_revoker Failed(auto_revoke_t, const Windows::Media::Capture::MediaCaptureFailedEventHandler & errorEventHandler) const;
    void Failed(event_token eventCookie) const;
    event_token RecordLimitationExceeded(const Windows::Media::Capture::RecordLimitationExceededEventHandler & recordLimitationExceededEventHandler) const;
    using RecordLimitationExceeded_revoker = event_revoker<IMediaCapture>;
    RecordLimitationExceeded_revoker RecordLimitationExceeded(auto_revoke_t, const Windows::Media::Capture::RecordLimitationExceededEventHandler & recordLimitationExceededEventHandler) const;
    void RecordLimitationExceeded(event_token eventCookie) const;
    Windows::Media::Capture::MediaCaptureSettings MediaCaptureSettings() const;
    Windows::Media::Devices::AudioDeviceController AudioDeviceController() const;
    Windows::Media::Devices::VideoDeviceController VideoDeviceController() const;
    void SetPreviewMirroring(bool value) const;
    bool GetPreviewMirroring() const;
    void SetPreviewRotation(Windows::Media::Capture::VideoRotation value) const;
    Windows::Media::Capture::VideoRotation GetPreviewRotation() const;
    void SetRecordRotation(Windows::Media::Capture::VideoRotation value) const;
    Windows::Media::Capture::VideoRotation GetRecordRotation() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaCapture2
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording> PrepareLowLagRecordToStorageFileAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, const Windows::Storage::IStorageFile & file) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording> PrepareLowLagRecordToStreamAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, const Windows::Storage::Streams::IRandomAccessStream & stream) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording> PrepareLowLagRecordToCustomSinkAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, const Windows::Media::IMediaExtension & customMediaSink) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording> PrepareLowLagRecordToCustomSinkAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, hstring_view customSinkActivationId, const Windows::Foundation::Collections::IPropertySet & customSinkSettings) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagPhotoCapture> PrepareLowLagPhotoCaptureAsync(const Windows::Media::MediaProperties::ImageEncodingProperties & type) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagPhotoSequenceCapture> PrepareLowLagPhotoSequenceCaptureAsync(const Windows::Media::MediaProperties::ImageEncodingProperties & type) const;
    Windows::Foundation::IAsyncAction SetEncodingPropertiesAsync(Windows::Media::Capture::MediaStreamType mediaStreamType, const Windows::Media::MediaProperties::IMediaEncodingProperties & mediaEncodingProperties, const Windows::Media::MediaProperties::MediaPropertySet & encoderProperties) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaCapture3
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Core::VariablePhotoSequenceCapture> PrepareVariablePhotoSequenceCaptureAsync(const Windows::Media::MediaProperties::ImageEncodingProperties & type) const;
    event_token FocusChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Media::Capture::MediaCaptureFocusChangedEventArgs> & handler) const;
    using FocusChanged_revoker = event_revoker<IMediaCapture3>;
    FocusChanged_revoker FocusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Media::Capture::MediaCaptureFocusChangedEventArgs> & handler) const;
    void FocusChanged(event_token token) const;
    event_token PhotoConfirmationCaptured(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Media::Capture::PhotoConfirmationCapturedEventArgs> & handler) const;
    using PhotoConfirmationCaptured_revoker = event_revoker<IMediaCapture3>;
    PhotoConfirmationCaptured_revoker PhotoConfirmationCaptured(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Media::Capture::PhotoConfirmationCapturedEventArgs> & handler) const;
    void PhotoConfirmationCaptured(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaCapture4
{
    Windows::Foundation::IAsyncOperation<Windows::Media::IMediaExtension> AddAudioEffectAsync(const Windows::Media::Effects::IAudioEffectDefinition & definition) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::IMediaExtension> AddVideoEffectAsync(const Windows::Media::Effects::IVideoEffectDefinition & definition, Windows::Media::Capture::MediaStreamType mediaStreamType) const;
    Windows::Foundation::IAsyncAction PauseRecordAsync(Windows::Media::Devices::MediaCapturePauseBehavior behavior) const;
    Windows::Foundation::IAsyncAction ResumeRecordAsync() const;
    event_token CameraStreamStateChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Foundation::IInspectable> & handler) const;
    using CameraStreamStateChanged_revoker = event_revoker<IMediaCapture4>;
    CameraStreamStateChanged_revoker CameraStreamStateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Foundation::IInspectable> & handler) const;
    void CameraStreamStateChanged(event_token token) const;
    Windows::Media::Devices::CameraStreamState CameraStreamState() const;
    Windows::Foundation::IAsyncOperation<Windows::Media::VideoFrame> GetPreviewFrameAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Media::VideoFrame> GetPreviewFrameAsync(const Windows::Media::VideoFrame & destination) const;
    event_token ThermalStatusChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Foundation::IInspectable> & handler) const;
    using ThermalStatusChanged_revoker = event_revoker<IMediaCapture4>;
    ThermalStatusChanged_revoker ThermalStatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Foundation::IInspectable> & handler) const;
    void ThermalStatusChanged(event_token token) const;
    Windows::Media::Capture::MediaCaptureThermalStatus ThermalStatus() const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::AdvancedPhotoCapture> PrepareAdvancedPhotoCaptureAsync(const Windows::Media::MediaProperties::ImageEncodingProperties & encodingProperties) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaCapture5
{
    Windows::Foundation::IAsyncAction RemoveEffectAsync(const Windows::Media::IMediaExtension & effect) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCapturePauseResult> PauseRecordWithResultAsync(Windows::Media::Devices::MediaCapturePauseBehavior behavior) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCaptureStopResult> StopRecordWithResultAsync() const;
    Windows::Foundation::Collections::IMapView<hstring, Windows::Media::Capture::Frames::MediaFrameSource> FrameSources() const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameReader> CreateFrameReaderAsync(const Windows::Media::Capture::Frames::MediaFrameSource & inputSource) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameReader> CreateFrameReaderAsync(const Windows::Media::Capture::Frames::MediaFrameSource & inputSource, hstring_view outputSubtype) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameReader> CreateFrameReaderAsync(const Windows::Media::Capture::Frames::MediaFrameSource & inputSource, hstring_view outputSubtype, const Windows::Graphics::Imaging::BitmapSize & outputSize) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaCaptureFailedEventArgs
{
    hstring Message() const;
    uint32_t Code() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaCaptureFocusChangedEventArgs
{
    Windows::Media::Devices::MediaCaptureFocusState FocusState() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaCaptureInitializationSettings
{
    void AudioDeviceId(hstring_view value) const;
    hstring AudioDeviceId() const;
    void VideoDeviceId(hstring_view value) const;
    hstring VideoDeviceId() const;
    void StreamingCaptureMode(Windows::Media::Capture::StreamingCaptureMode value) const;
    Windows::Media::Capture::StreamingCaptureMode StreamingCaptureMode() const;
    void PhotoCaptureSource(Windows::Media::Capture::PhotoCaptureSource value) const;
    Windows::Media::Capture::PhotoCaptureSource PhotoCaptureSource() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaCaptureInitializationSettings2
{
    void MediaCategory(Windows::Media::Capture::MediaCategory value) const;
    Windows::Media::Capture::MediaCategory MediaCategory() const;
    void AudioProcessing(Windows::Media::AudioProcessing value) const;
    Windows::Media::AudioProcessing AudioProcessing() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaCaptureInitializationSettings3
{
    void AudioSource(const Windows::Media::Core::IMediaSource & value) const;
    Windows::Media::Core::IMediaSource AudioSource() const;
    void VideoSource(const Windows::Media::Core::IMediaSource & value) const;
    Windows::Media::Core::IMediaSource VideoSource() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaCaptureInitializationSettings4
{
    Windows::Media::Capture::MediaCaptureVideoProfile VideoProfile() const;
    void VideoProfile(const Windows::Media::Capture::MediaCaptureVideoProfile & value) const;
    Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription PreviewMediaDescription() const;
    void PreviewMediaDescription(const Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription & value) const;
    Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription RecordMediaDescription() const;
    void RecordMediaDescription(const Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription & value) const;
    Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription PhotoMediaDescription() const;
    void PhotoMediaDescription(const Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription & value) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaCaptureInitializationSettings5
{
    Windows::Media::Capture::Frames::MediaFrameSourceGroup SourceGroup() const;
    void SourceGroup(const Windows::Media::Capture::Frames::MediaFrameSourceGroup & value) const;
    Windows::Media::Capture::MediaCaptureSharingMode SharingMode() const;
    void SharingMode(Windows::Media::Capture::MediaCaptureSharingMode value) const;
    Windows::Media::Capture::MediaCaptureMemoryPreference MemoryPreference() const;
    void MemoryPreference(Windows::Media::Capture::MediaCaptureMemoryPreference value) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaCapturePauseResult
{
    Windows::Media::VideoFrame LastFrame() const;
    Windows::Foundation::TimeSpan RecordDuration() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaCaptureSettings
{
    hstring AudioDeviceId() const;
    hstring VideoDeviceId() const;
    Windows::Media::Capture::StreamingCaptureMode StreamingCaptureMode() const;
    Windows::Media::Capture::PhotoCaptureSource PhotoCaptureSource() const;
    Windows::Media::Capture::VideoDeviceCharacteristic VideoDeviceCharacteristic() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaCaptureSettings2
{
    bool ConcurrentRecordAndPhotoSupported() const;
    bool ConcurrentRecordAndPhotoSequenceSupported() const;
    bool CameraSoundRequiredForRegion() const;
    Windows::Foundation::IReference<uint32_t> Horizontal35mmEquivalentFocalLength() const;
    Windows::Foundation::IReference<int32_t> PitchOffsetDegrees() const;
    Windows::Foundation::IReference<uint32_t> Vertical35mmEquivalentFocalLength() const;
    Windows::Media::Capture::MediaCategory MediaCategory() const;
    Windows::Media::AudioProcessing AudioProcessing() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaCaptureStatics
{
    bool IsVideoProfileSupported(hstring_view videoDeviceId) const;
    Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> FindAllVideoProfiles(hstring_view videoDeviceId) const;
    Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> FindConcurrentProfiles(hstring_view videoDeviceId) const;
    Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> FindKnownVideoProfiles(hstring_view videoDeviceId, Windows::Media::Capture::KnownVideoProfile name) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaCaptureStopResult
{
    Windows::Media::VideoFrame LastFrame() const;
    Windows::Foundation::TimeSpan RecordDuration() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaCaptureVideoPreview
{
    Windows::Foundation::IAsyncAction StartPreviewAsync() const;
    Windows::Foundation::IAsyncAction StartPreviewToCustomSinkAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, const Windows::Media::IMediaExtension & customMediaSink) const;
    Windows::Foundation::IAsyncAction StartPreviewToCustomSinkAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, hstring_view customSinkActivationId, const Windows::Foundation::Collections::IPropertySet & customSinkSettings) const;
    Windows::Foundation::IAsyncAction StopPreviewAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaCaptureVideoProfile
{
    hstring Id() const;
    hstring VideoDeviceId() const;
    Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription> SupportedPreviewMediaDescription() const;
    Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription> SupportedRecordMediaDescription() const;
    Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription> SupportedPhotoMediaDescription() const;
    Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> GetConcurrency() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaCaptureVideoProfileMediaDescription
{
    uint32_t Width() const;
    uint32_t Height() const;
    double FrameRate() const;
    bool IsVariablePhotoSequenceSupported() const;
    bool IsHdrVideoSupported() const;
};

template <typename D>
struct WINRT_EBO impl_IOptionalReferencePhotoCapturedEventArgs
{
    Windows::Media::Capture::CapturedFrame Frame() const;
    Windows::Foundation::IInspectable Context() const;
};

template <typename D>
struct WINRT_EBO impl_IPhotoCapturedEventArgs
{
    Windows::Media::Capture::CapturedFrame Frame() const;
    Windows::Media::Capture::CapturedFrame Thumbnail() const;
    Windows::Foundation::TimeSpan CaptureTimeOffset() const;
};

template <typename D>
struct WINRT_EBO impl_IPhotoConfirmationCapturedEventArgs
{
    Windows::Media::Capture::CapturedFrame Frame() const;
    Windows::Foundation::TimeSpan CaptureTimeOffset() const;
};

template <typename D>
struct WINRT_EBO impl_IScreenCapture
{
    Windows::Media::Core::IMediaSource AudioSource() const;
    Windows::Media::Core::IMediaSource VideoSource() const;
    bool IsAudioSuspended() const;
    bool IsVideoSuspended() const;
    event_token SourceSuspensionChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::ScreenCapture, Windows::Media::Capture::SourceSuspensionChangedEventArgs> & handler) const;
    using SourceSuspensionChanged_revoker = event_revoker<IScreenCapture>;
    SourceSuspensionChanged_revoker SourceSuspensionChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::ScreenCapture, Windows::Media::Capture::SourceSuspensionChangedEventArgs> & handler) const;
    void SourceSuspensionChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IScreenCaptureStatics
{
    Windows::Media::Capture::ScreenCapture GetForCurrentView() const;
};

template <typename D>
struct WINRT_EBO impl_ISourceSuspensionChangedEventArgs
{
    bool IsAudioSuspended() const;
    bool IsVideoSuspended() const;
};

template <typename D>
struct WINRT_EBO impl_IVideoStreamConfiguration
{
    Windows::Media::MediaProperties::VideoEncodingProperties InputProperties() const;
    Windows::Media::MediaProperties::VideoEncodingProperties OutputProperties() const;
};

}

namespace impl {

template <> struct traits<Windows::Media::Capture::IAdvancedCapturedPhoto>
{
    using abi = ABI::Windows::Media::Capture::IAdvancedCapturedPhoto;
    template <typename D> using consume = Windows::Media::Capture::impl_IAdvancedCapturedPhoto<D>;
};

template <> struct traits<Windows::Media::Capture::IAdvancedCapturedPhoto2>
{
    using abi = ABI::Windows::Media::Capture::IAdvancedCapturedPhoto2;
    template <typename D> using consume = Windows::Media::Capture::impl_IAdvancedCapturedPhoto2<D>;
};

template <> struct traits<Windows::Media::Capture::IAdvancedPhotoCapture>
{
    using abi = ABI::Windows::Media::Capture::IAdvancedPhotoCapture;
    template <typename D> using consume = Windows::Media::Capture::impl_IAdvancedPhotoCapture<D>;
};

template <> struct traits<Windows::Media::Capture::IAppCapture>
{
    using abi = ABI::Windows::Media::Capture::IAppCapture;
    template <typename D> using consume = Windows::Media::Capture::impl_IAppCapture<D>;
};

template <> struct traits<Windows::Media::Capture::IAppCaptureAlternateShortcutKeys>
{
    using abi = ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys;
    template <typename D> using consume = Windows::Media::Capture::impl_IAppCaptureAlternateShortcutKeys<D>;
};

template <> struct traits<Windows::Media::Capture::IAppCaptureAlternateShortcutKeys2>
{
    using abi = ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys2;
    template <typename D> using consume = Windows::Media::Capture::impl_IAppCaptureAlternateShortcutKeys2<D>;
};

template <> struct traits<Windows::Media::Capture::IAppCaptureAlternateShortcutKeys3>
{
    using abi = ABI::Windows::Media::Capture::IAppCaptureAlternateShortcutKeys3;
    template <typename D> using consume = Windows::Media::Capture::impl_IAppCaptureAlternateShortcutKeys3<D>;
};

template <> struct traits<Windows::Media::Capture::IAppCaptureManagerStatics>
{
    using abi = ABI::Windows::Media::Capture::IAppCaptureManagerStatics;
    template <typename D> using consume = Windows::Media::Capture::impl_IAppCaptureManagerStatics<D>;
};

template <> struct traits<Windows::Media::Capture::IAppCaptureSettings>
{
    using abi = ABI::Windows::Media::Capture::IAppCaptureSettings;
    template <typename D> using consume = Windows::Media::Capture::impl_IAppCaptureSettings<D>;
};

template <> struct traits<Windows::Media::Capture::IAppCaptureSettings2>
{
    using abi = ABI::Windows::Media::Capture::IAppCaptureSettings2;
    template <typename D> using consume = Windows::Media::Capture::impl_IAppCaptureSettings2<D>;
};

template <> struct traits<Windows::Media::Capture::IAppCaptureSettings3>
{
    using abi = ABI::Windows::Media::Capture::IAppCaptureSettings3;
    template <typename D> using consume = Windows::Media::Capture::impl_IAppCaptureSettings3<D>;
};

template <> struct traits<Windows::Media::Capture::IAppCaptureSettings4>
{
    using abi = ABI::Windows::Media::Capture::IAppCaptureSettings4;
    template <typename D> using consume = Windows::Media::Capture::impl_IAppCaptureSettings4<D>;
};

template <> struct traits<Windows::Media::Capture::IAppCaptureStatics>
{
    using abi = ABI::Windows::Media::Capture::IAppCaptureStatics;
    template <typename D> using consume = Windows::Media::Capture::impl_IAppCaptureStatics<D>;
};

template <> struct traits<Windows::Media::Capture::ICameraCaptureUI>
{
    using abi = ABI::Windows::Media::Capture::ICameraCaptureUI;
    template <typename D> using consume = Windows::Media::Capture::impl_ICameraCaptureUI<D>;
};

template <> struct traits<Windows::Media::Capture::ICameraCaptureUIPhotoCaptureSettings>
{
    using abi = ABI::Windows::Media::Capture::ICameraCaptureUIPhotoCaptureSettings;
    template <typename D> using consume = Windows::Media::Capture::impl_ICameraCaptureUIPhotoCaptureSettings<D>;
};

template <> struct traits<Windows::Media::Capture::ICameraCaptureUIVideoCaptureSettings>
{
    using abi = ABI::Windows::Media::Capture::ICameraCaptureUIVideoCaptureSettings;
    template <typename D> using consume = Windows::Media::Capture::impl_ICameraCaptureUIVideoCaptureSettings<D>;
};

template <> struct traits<Windows::Media::Capture::ICameraOptionsUIStatics>
{
    using abi = ABI::Windows::Media::Capture::ICameraOptionsUIStatics;
    template <typename D> using consume = Windows::Media::Capture::impl_ICameraOptionsUIStatics<D>;
};

template <> struct traits<Windows::Media::Capture::ICapturedFrame>
{
    using abi = ABI::Windows::Media::Capture::ICapturedFrame;
    template <typename D> using consume = Windows::Media::Capture::impl_ICapturedFrame<D>;
};

template <> struct traits<Windows::Media::Capture::ICapturedFrameControlValues>
{
    using abi = ABI::Windows::Media::Capture::ICapturedFrameControlValues;
    template <typename D> using consume = Windows::Media::Capture::impl_ICapturedFrameControlValues<D>;
};

template <> struct traits<Windows::Media::Capture::ICapturedFrameControlValues2>
{
    using abi = ABI::Windows::Media::Capture::ICapturedFrameControlValues2;
    template <typename D> using consume = Windows::Media::Capture::impl_ICapturedFrameControlValues2<D>;
};

template <> struct traits<Windows::Media::Capture::ICapturedFrameWithSoftwareBitmap>
{
    using abi = ABI::Windows::Media::Capture::ICapturedFrameWithSoftwareBitmap;
    template <typename D> using consume = Windows::Media::Capture::impl_ICapturedFrameWithSoftwareBitmap<D>;
};

template <> struct traits<Windows::Media::Capture::ICapturedPhoto>
{
    using abi = ABI::Windows::Media::Capture::ICapturedPhoto;
    template <typename D> using consume = Windows::Media::Capture::impl_ICapturedPhoto<D>;
};

template <> struct traits<Windows::Media::Capture::ILowLagMediaRecording>
{
    using abi = ABI::Windows::Media::Capture::ILowLagMediaRecording;
    template <typename D> using consume = Windows::Media::Capture::impl_ILowLagMediaRecording<D>;
};

template <> struct traits<Windows::Media::Capture::ILowLagMediaRecording2>
{
    using abi = ABI::Windows::Media::Capture::ILowLagMediaRecording2;
    template <typename D> using consume = Windows::Media::Capture::impl_ILowLagMediaRecording2<D>;
};

template <> struct traits<Windows::Media::Capture::ILowLagMediaRecording3>
{
    using abi = ABI::Windows::Media::Capture::ILowLagMediaRecording3;
    template <typename D> using consume = Windows::Media::Capture::impl_ILowLagMediaRecording3<D>;
};

template <> struct traits<Windows::Media::Capture::ILowLagPhotoCapture>
{
    using abi = ABI::Windows::Media::Capture::ILowLagPhotoCapture;
    template <typename D> using consume = Windows::Media::Capture::impl_ILowLagPhotoCapture<D>;
};

template <> struct traits<Windows::Media::Capture::ILowLagPhotoSequenceCapture>
{
    using abi = ABI::Windows::Media::Capture::ILowLagPhotoSequenceCapture;
    template <typename D> using consume = Windows::Media::Capture::impl_ILowLagPhotoSequenceCapture<D>;
};

template <> struct traits<Windows::Media::Capture::IMediaCapture>
{
    using abi = ABI::Windows::Media::Capture::IMediaCapture;
    template <typename D> using consume = Windows::Media::Capture::impl_IMediaCapture<D>;
};

template <> struct traits<Windows::Media::Capture::IMediaCapture2>
{
    using abi = ABI::Windows::Media::Capture::IMediaCapture2;
    template <typename D> using consume = Windows::Media::Capture::impl_IMediaCapture2<D>;
};

template <> struct traits<Windows::Media::Capture::IMediaCapture3>
{
    using abi = ABI::Windows::Media::Capture::IMediaCapture3;
    template <typename D> using consume = Windows::Media::Capture::impl_IMediaCapture3<D>;
};

template <> struct traits<Windows::Media::Capture::IMediaCapture4>
{
    using abi = ABI::Windows::Media::Capture::IMediaCapture4;
    template <typename D> using consume = Windows::Media::Capture::impl_IMediaCapture4<D>;
};

template <> struct traits<Windows::Media::Capture::IMediaCapture5>
{
    using abi = ABI::Windows::Media::Capture::IMediaCapture5;
    template <typename D> using consume = Windows::Media::Capture::impl_IMediaCapture5<D>;
};

template <> struct traits<Windows::Media::Capture::IMediaCaptureFailedEventArgs>
{
    using abi = ABI::Windows::Media::Capture::IMediaCaptureFailedEventArgs;
    template <typename D> using consume = Windows::Media::Capture::impl_IMediaCaptureFailedEventArgs<D>;
};

template <> struct traits<Windows::Media::Capture::IMediaCaptureFocusChangedEventArgs>
{
    using abi = ABI::Windows::Media::Capture::IMediaCaptureFocusChangedEventArgs;
    template <typename D> using consume = Windows::Media::Capture::impl_IMediaCaptureFocusChangedEventArgs<D>;
};

template <> struct traits<Windows::Media::Capture::IMediaCaptureInitializationSettings>
{
    using abi = ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings;
    template <typename D> using consume = Windows::Media::Capture::impl_IMediaCaptureInitializationSettings<D>;
};

template <> struct traits<Windows::Media::Capture::IMediaCaptureInitializationSettings2>
{
    using abi = ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings2;
    template <typename D> using consume = Windows::Media::Capture::impl_IMediaCaptureInitializationSettings2<D>;
};

template <> struct traits<Windows::Media::Capture::IMediaCaptureInitializationSettings3>
{
    using abi = ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings3;
    template <typename D> using consume = Windows::Media::Capture::impl_IMediaCaptureInitializationSettings3<D>;
};

template <> struct traits<Windows::Media::Capture::IMediaCaptureInitializationSettings4>
{
    using abi = ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings4;
    template <typename D> using consume = Windows::Media::Capture::impl_IMediaCaptureInitializationSettings4<D>;
};

template <> struct traits<Windows::Media::Capture::IMediaCaptureInitializationSettings5>
{
    using abi = ABI::Windows::Media::Capture::IMediaCaptureInitializationSettings5;
    template <typename D> using consume = Windows::Media::Capture::impl_IMediaCaptureInitializationSettings5<D>;
};

template <> struct traits<Windows::Media::Capture::IMediaCapturePauseResult>
{
    using abi = ABI::Windows::Media::Capture::IMediaCapturePauseResult;
    template <typename D> using consume = Windows::Media::Capture::impl_IMediaCapturePauseResult<D>;
};

template <> struct traits<Windows::Media::Capture::IMediaCaptureSettings>
{
    using abi = ABI::Windows::Media::Capture::IMediaCaptureSettings;
    template <typename D> using consume = Windows::Media::Capture::impl_IMediaCaptureSettings<D>;
};

template <> struct traits<Windows::Media::Capture::IMediaCaptureSettings2>
{
    using abi = ABI::Windows::Media::Capture::IMediaCaptureSettings2;
    template <typename D> using consume = Windows::Media::Capture::impl_IMediaCaptureSettings2<D>;
};

template <> struct traits<Windows::Media::Capture::IMediaCaptureStatics>
{
    using abi = ABI::Windows::Media::Capture::IMediaCaptureStatics;
    template <typename D> using consume = Windows::Media::Capture::impl_IMediaCaptureStatics<D>;
};

template <> struct traits<Windows::Media::Capture::IMediaCaptureStopResult>
{
    using abi = ABI::Windows::Media::Capture::IMediaCaptureStopResult;
    template <typename D> using consume = Windows::Media::Capture::impl_IMediaCaptureStopResult<D>;
};

template <> struct traits<Windows::Media::Capture::IMediaCaptureVideoPreview>
{
    using abi = ABI::Windows::Media::Capture::IMediaCaptureVideoPreview;
    template <typename D> using consume = Windows::Media::Capture::impl_IMediaCaptureVideoPreview<D>;
};

template <> struct traits<Windows::Media::Capture::IMediaCaptureVideoProfile>
{
    using abi = ABI::Windows::Media::Capture::IMediaCaptureVideoProfile;
    template <typename D> using consume = Windows::Media::Capture::impl_IMediaCaptureVideoProfile<D>;
};

template <> struct traits<Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription>
{
    using abi = ABI::Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription;
    template <typename D> using consume = Windows::Media::Capture::impl_IMediaCaptureVideoProfileMediaDescription<D>;
};

template <> struct traits<Windows::Media::Capture::IOptionalReferencePhotoCapturedEventArgs>
{
    using abi = ABI::Windows::Media::Capture::IOptionalReferencePhotoCapturedEventArgs;
    template <typename D> using consume = Windows::Media::Capture::impl_IOptionalReferencePhotoCapturedEventArgs<D>;
};

template <> struct traits<Windows::Media::Capture::IPhotoCapturedEventArgs>
{
    using abi = ABI::Windows::Media::Capture::IPhotoCapturedEventArgs;
    template <typename D> using consume = Windows::Media::Capture::impl_IPhotoCapturedEventArgs<D>;
};

template <> struct traits<Windows::Media::Capture::IPhotoConfirmationCapturedEventArgs>
{
    using abi = ABI::Windows::Media::Capture::IPhotoConfirmationCapturedEventArgs;
    template <typename D> using consume = Windows::Media::Capture::impl_IPhotoConfirmationCapturedEventArgs<D>;
};

template <> struct traits<Windows::Media::Capture::IScreenCapture>
{
    using abi = ABI::Windows::Media::Capture::IScreenCapture;
    template <typename D> using consume = Windows::Media::Capture::impl_IScreenCapture<D>;
};

template <> struct traits<Windows::Media::Capture::IScreenCaptureStatics>
{
    using abi = ABI::Windows::Media::Capture::IScreenCaptureStatics;
    template <typename D> using consume = Windows::Media::Capture::impl_IScreenCaptureStatics<D>;
};

template <> struct traits<Windows::Media::Capture::ISourceSuspensionChangedEventArgs>
{
    using abi = ABI::Windows::Media::Capture::ISourceSuspensionChangedEventArgs;
    template <typename D> using consume = Windows::Media::Capture::impl_ISourceSuspensionChangedEventArgs<D>;
};

template <> struct traits<Windows::Media::Capture::IVideoStreamConfiguration>
{
    using abi = ABI::Windows::Media::Capture::IVideoStreamConfiguration;
    template <typename D> using consume = Windows::Media::Capture::impl_IVideoStreamConfiguration<D>;
};

template <> struct traits<Windows::Media::Capture::MediaCaptureFailedEventHandler>
{
    using abi = ABI::Windows::Media::Capture::MediaCaptureFailedEventHandler;
};

template <> struct traits<Windows::Media::Capture::RecordLimitationExceededEventHandler>
{
    using abi = ABI::Windows::Media::Capture::RecordLimitationExceededEventHandler;
};

template <> struct traits<Windows::Media::Capture::AdvancedCapturedPhoto>
{
    using abi = ABI::Windows::Media::Capture::AdvancedCapturedPhoto;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.AdvancedCapturedPhoto"; }
};

template <> struct traits<Windows::Media::Capture::AdvancedPhotoCapture>
{
    using abi = ABI::Windows::Media::Capture::AdvancedPhotoCapture;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.AdvancedPhotoCapture"; }
};

template <> struct traits<Windows::Media::Capture::AppCapture>
{
    using abi = ABI::Windows::Media::Capture::AppCapture;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.AppCapture"; }
};

template <> struct traits<Windows::Media::Capture::AppCaptureAlternateShortcutKeys>
{
    using abi = ABI::Windows::Media::Capture::AppCaptureAlternateShortcutKeys;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.AppCaptureAlternateShortcutKeys"; }
};

template <> struct traits<Windows::Media::Capture::AppCaptureManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.AppCaptureManager"; }
};

template <> struct traits<Windows::Media::Capture::AppCaptureSettings>
{
    using abi = ABI::Windows::Media::Capture::AppCaptureSettings;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.AppCaptureSettings"; }
};

template <> struct traits<Windows::Media::Capture::CameraCaptureUI>
{
    using abi = ABI::Windows::Media::Capture::CameraCaptureUI;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.CameraCaptureUI"; }
};

template <> struct traits<Windows::Media::Capture::CameraCaptureUIPhotoCaptureSettings>
{
    using abi = ABI::Windows::Media::Capture::CameraCaptureUIPhotoCaptureSettings;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.CameraCaptureUIPhotoCaptureSettings"; }
};

template <> struct traits<Windows::Media::Capture::CameraCaptureUIVideoCaptureSettings>
{
    using abi = ABI::Windows::Media::Capture::CameraCaptureUIVideoCaptureSettings;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.CameraCaptureUIVideoCaptureSettings"; }
};

template <> struct traits<Windows::Media::Capture::CameraOptionsUI>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.CameraOptionsUI"; }
};

template <> struct traits<Windows::Media::Capture::CapturedFrame>
{
    using abi = ABI::Windows::Media::Capture::CapturedFrame;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.CapturedFrame"; }
};

template <> struct traits<Windows::Media::Capture::CapturedFrameControlValues>
{
    using abi = ABI::Windows::Media::Capture::CapturedFrameControlValues;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.CapturedFrameControlValues"; }
};

template <> struct traits<Windows::Media::Capture::CapturedPhoto>
{
    using abi = ABI::Windows::Media::Capture::CapturedPhoto;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.CapturedPhoto"; }
};

template <> struct traits<Windows::Media::Capture::LowLagMediaRecording>
{
    using abi = ABI::Windows::Media::Capture::LowLagMediaRecording;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.LowLagMediaRecording"; }
};

template <> struct traits<Windows::Media::Capture::LowLagPhotoCapture>
{
    using abi = ABI::Windows::Media::Capture::LowLagPhotoCapture;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.LowLagPhotoCapture"; }
};

template <> struct traits<Windows::Media::Capture::LowLagPhotoSequenceCapture>
{
    using abi = ABI::Windows::Media::Capture::LowLagPhotoSequenceCapture;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.LowLagPhotoSequenceCapture"; }
};

template <> struct traits<Windows::Media::Capture::MediaCapture>
{
    using abi = ABI::Windows::Media::Capture::MediaCapture;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.MediaCapture"; }
};

template <> struct traits<Windows::Media::Capture::MediaCaptureFailedEventArgs>
{
    using abi = ABI::Windows::Media::Capture::MediaCaptureFailedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.MediaCaptureFailedEventArgs"; }
};

template <> struct traits<Windows::Media::Capture::MediaCaptureFocusChangedEventArgs>
{
    using abi = ABI::Windows::Media::Capture::MediaCaptureFocusChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.MediaCaptureFocusChangedEventArgs"; }
};

template <> struct traits<Windows::Media::Capture::MediaCaptureInitializationSettings>
{
    using abi = ABI::Windows::Media::Capture::MediaCaptureInitializationSettings;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.MediaCaptureInitializationSettings"; }
};

template <> struct traits<Windows::Media::Capture::MediaCapturePauseResult>
{
    using abi = ABI::Windows::Media::Capture::MediaCapturePauseResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.MediaCapturePauseResult"; }
};

template <> struct traits<Windows::Media::Capture::MediaCaptureSettings>
{
    using abi = ABI::Windows::Media::Capture::MediaCaptureSettings;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.MediaCaptureSettings"; }
};

template <> struct traits<Windows::Media::Capture::MediaCaptureStopResult>
{
    using abi = ABI::Windows::Media::Capture::MediaCaptureStopResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.MediaCaptureStopResult"; }
};

template <> struct traits<Windows::Media::Capture::MediaCaptureVideoProfile>
{
    using abi = ABI::Windows::Media::Capture::MediaCaptureVideoProfile;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.MediaCaptureVideoProfile"; }
};

template <> struct traits<Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription>
{
    using abi = ABI::Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.MediaCaptureVideoProfileMediaDescription"; }
};

template <> struct traits<Windows::Media::Capture::OptionalReferencePhotoCapturedEventArgs>
{
    using abi = ABI::Windows::Media::Capture::OptionalReferencePhotoCapturedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.OptionalReferencePhotoCapturedEventArgs"; }
};

template <> struct traits<Windows::Media::Capture::PhotoCapturedEventArgs>
{
    using abi = ABI::Windows::Media::Capture::PhotoCapturedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.PhotoCapturedEventArgs"; }
};

template <> struct traits<Windows::Media::Capture::PhotoConfirmationCapturedEventArgs>
{
    using abi = ABI::Windows::Media::Capture::PhotoConfirmationCapturedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.PhotoConfirmationCapturedEventArgs"; }
};

template <> struct traits<Windows::Media::Capture::ScreenCapture>
{
    using abi = ABI::Windows::Media::Capture::ScreenCapture;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.ScreenCapture"; }
};

template <> struct traits<Windows::Media::Capture::SourceSuspensionChangedEventArgs>
{
    using abi = ABI::Windows::Media::Capture::SourceSuspensionChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.SourceSuspensionChangedEventArgs"; }
};

template <> struct traits<Windows::Media::Capture::VideoStreamConfiguration>
{
    using abi = ABI::Windows::Media::Capture::VideoStreamConfiguration;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.VideoStreamConfiguration"; }
};

}

}
