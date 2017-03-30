// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Media.Devices.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Media.Capture.0.h"
#include "Windows.Media.Devices.Core.0.h"
#include "Windows.Media.MediaProperties.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Media.MediaProperties.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::Devices {

struct __declspec(uuid("596f759f-50df-4454-bc63-4d3d01b61958")) __declspec(novtable) CallControlEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Media::Devices::ICallControl * sender) = 0;
};

struct __declspec(uuid("5abbffdb-c21f-4bc4-891b-257e28c1b1a4")) __declspec(novtable) DialRequestedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Media::Devices::ICallControl * sender, Windows::Media::Devices::IDialRequestedEventArgs * e) = 0;
};

struct __declspec(uuid("08f3863a-0018-445b-93d2-646d1c5ed05c")) __declspec(novtable) IAdvancedPhotoCaptureSettings : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Mode(winrt::Windows::Media::Devices::AdvancedPhotoMode * value) = 0;
    virtual HRESULT __stdcall put_Mode(winrt::Windows::Media::Devices::AdvancedPhotoMode value) = 0;
};

struct __declspec(uuid("c5b15486-9001-4682-9309-68eae0080eec")) __declspec(novtable) IAdvancedPhotoControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Supported(bool * value) = 0;
    virtual HRESULT __stdcall get_SupportedModes(Windows::Foundation::Collections::IVectorView<winrt::Windows::Media::Devices::AdvancedPhotoMode> ** value) = 0;
    virtual HRESULT __stdcall get_Mode(winrt::Windows::Media::Devices::AdvancedPhotoMode * value) = 0;
    virtual HRESULT __stdcall abi_Configure(Windows::Media::Devices::IAdvancedPhotoCaptureSettings * settings) = 0;
};

struct __declspec(uuid("de6ff4d3-2b96-4583-80ab-b5b01dc6a8d7")) __declspec(novtable) IAdvancedVideoCaptureDeviceController : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SetDeviceProperty(hstring propertyId, Windows::Foundation::IInspectable * propertyValue) = 0;
    virtual HRESULT __stdcall abi_GetDeviceProperty(hstring propertyId, Windows::Foundation::IInspectable ** propertyValue) = 0;
};

struct __declspec(uuid("8bb94f8f-f11a-43db-b402-11930b80ae56")) __declspec(novtable) IAdvancedVideoCaptureDeviceController2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LowLagPhotoSequence(Windows::Media::Devices::ILowLagPhotoSequenceControl ** value) = 0;
    virtual HRESULT __stdcall get_LowLagPhoto(Windows::Media::Devices::ILowLagPhotoControl ** value) = 0;
    virtual HRESULT __stdcall get_SceneModeControl(Windows::Media::Devices::ISceneModeControl ** value) = 0;
    virtual HRESULT __stdcall get_TorchControl(Windows::Media::Devices::ITorchControl ** value) = 0;
    virtual HRESULT __stdcall get_FlashControl(Windows::Media::Devices::IFlashControl ** value) = 0;
    virtual HRESULT __stdcall get_WhiteBalanceControl(Windows::Media::Devices::IWhiteBalanceControl ** value) = 0;
    virtual HRESULT __stdcall get_ExposureControl(Windows::Media::Devices::IExposureControl ** value) = 0;
    virtual HRESULT __stdcall get_FocusControl(Windows::Media::Devices::IFocusControl ** value) = 0;
    virtual HRESULT __stdcall get_ExposureCompensationControl(Windows::Media::Devices::IExposureCompensationControl ** value) = 0;
    virtual HRESULT __stdcall get_IsoSpeedControl(Windows::Media::Devices::IIsoSpeedControl ** value) = 0;
    virtual HRESULT __stdcall get_RegionsOfInterestControl(Windows::Media::Devices::IRegionsOfInterestControl ** value) = 0;
    virtual HRESULT __stdcall get_PrimaryUse(winrt::Windows::Media::Devices::CaptureUse * value) = 0;
    virtual HRESULT __stdcall put_PrimaryUse(winrt::Windows::Media::Devices::CaptureUse value) = 0;
};

struct __declspec(uuid("a98b8f34-ee0d-470c-b9f0-4229c4bbd089")) __declspec(novtable) IAdvancedVideoCaptureDeviceController3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_VariablePhotoSequenceController(Windows::Media::Devices::Core::IVariablePhotoSequenceController ** value) = 0;
    virtual HRESULT __stdcall get_PhotoConfirmationControl(Windows::Media::Devices::IPhotoConfirmationControl ** value) = 0;
    virtual HRESULT __stdcall get_ZoomControl(Windows::Media::Devices::IZoomControl ** value) = 0;
};

struct __declspec(uuid("ea9fbfaf-d371-41c3-9a17-824a87ebdfd2")) __declspec(novtable) IAdvancedVideoCaptureDeviceController4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ExposurePriorityVideoControl(Windows::Media::Devices::IExposurePriorityVideoControl ** value) = 0;
    virtual HRESULT __stdcall get_DesiredOptimization(winrt::Windows::Media::Devices::MediaCaptureOptimization * value) = 0;
    virtual HRESULT __stdcall put_DesiredOptimization(winrt::Windows::Media::Devices::MediaCaptureOptimization value) = 0;
    virtual HRESULT __stdcall get_HdrVideoControl(Windows::Media::Devices::IHdrVideoControl ** value) = 0;
    virtual HRESULT __stdcall get_OpticalImageStabilizationControl(Windows::Media::Devices::IOpticalImageStabilizationControl ** value) = 0;
    virtual HRESULT __stdcall get_AdvancedPhotoControl(Windows::Media::Devices::IAdvancedPhotoControl ** value) = 0;
};

struct __declspec(uuid("edd4a388-79c7-4f7c-90e8-ef934b21580a")) __declspec(novtable) IAudioDeviceController : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_Muted(bool value) = 0;
    virtual HRESULT __stdcall get_Muted(bool * value) = 0;
    virtual HRESULT __stdcall put_VolumePercent(float value) = 0;
    virtual HRESULT __stdcall get_VolumePercent(float * value) = 0;
};

struct __declspec(uuid("a520d0d6-ae8d-45db-8011-ca49d3b3e578")) __declspec(novtable) ICallControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_IndicateNewIncomingCall(bool enableRinger, hstring callerId, uint64_t * callToken) = 0;
    virtual HRESULT __stdcall abi_IndicateNewOutgoingCall(uint64_t * callToken) = 0;
    virtual HRESULT __stdcall abi_IndicateActiveCall(uint64_t callToken) = 0;
    virtual HRESULT __stdcall abi_EndCall(uint64_t callToken) = 0;
    virtual HRESULT __stdcall get_HasRinger(bool * value) = 0;
    virtual HRESULT __stdcall add_AnswerRequested(Windows::Media::Devices::CallControlEventHandler * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_AnswerRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_HangUpRequested(Windows::Media::Devices::CallControlEventHandler * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_HangUpRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_DialRequested(Windows::Media::Devices::DialRequestedEventHandler * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DialRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_RedialRequested(Windows::Media::Devices::RedialRequestedEventHandler * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_RedialRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_KeypadPressed(Windows::Media::Devices::KeypadPressedEventHandler * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_KeypadPressed(event_token token) = 0;
    virtual HRESULT __stdcall add_AudioTransferRequested(Windows::Media::Devices::CallControlEventHandler * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_AudioTransferRequested(event_token token) = 0;
};

struct __declspec(uuid("03945ad5-85ab-40e1-af19-56c94303b019")) __declspec(novtable) ICallControlStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDefault(Windows::Media::Devices::ICallControl ** callControl) = 0;
    virtual HRESULT __stdcall abi_FromId(hstring deviceId, Windows::Media::Devices::ICallControl ** callControl) = 0;
};

struct __declspec(uuid("110f882f-1c05-4657-a18e-47c9b69f07ab")) __declspec(novtable) IDefaultAudioDeviceChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_Role(winrt::Windows::Media::Devices::AudioDeviceRole * value) = 0;
};

struct __declspec(uuid("037b929e-953c-4286-8866-4f0f376c855a")) __declspec(novtable) IDialRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Handled() = 0;
    virtual HRESULT __stdcall get_Contact(Windows::Foundation::IInspectable ** value) = 0;
};

struct __declspec(uuid("81c8e834-dcec-4011-a610-1f3847e64aca")) __declspec(novtable) IExposureCompensationControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Supported(bool * value) = 0;
    virtual HRESULT __stdcall get_Min(float * value) = 0;
    virtual HRESULT __stdcall get_Max(float * value) = 0;
    virtual HRESULT __stdcall get_Step(float * value) = 0;
    virtual HRESULT __stdcall get_Value(float * value) = 0;
    virtual HRESULT __stdcall abi_SetValueAsync(float value, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
};

struct __declspec(uuid("09e8cbe2-ad96-4f28-a0e0-96ed7e1b5fd2")) __declspec(novtable) IExposureControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Supported(bool * value) = 0;
    virtual HRESULT __stdcall get_Auto(bool * value) = 0;
    virtual HRESULT __stdcall abi_SetAutoAsync(bool value, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall get_Min(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_Max(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_Step(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_Value(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall abi_SetValueAsync(Windows::Foundation::TimeSpan shutterDuration, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
};

struct __declspec(uuid("2cb240a3-5168-4271-9ea5-47621a98a352")) __declspec(novtable) IExposurePriorityVideoControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Supported(bool * value) = 0;
    virtual HRESULT __stdcall get_Enabled(bool * value) = 0;
    virtual HRESULT __stdcall put_Enabled(bool value) = 0;
};

struct __declspec(uuid("def41dbe-7d68-45e3-8c0f-be7bb32837d0")) __declspec(novtable) IFlashControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Supported(bool * value) = 0;
    virtual HRESULT __stdcall get_PowerSupported(bool * value) = 0;
    virtual HRESULT __stdcall get_RedEyeReductionSupported(bool * value) = 0;
    virtual HRESULT __stdcall get_Enabled(bool * value) = 0;
    virtual HRESULT __stdcall put_Enabled(bool value) = 0;
    virtual HRESULT __stdcall get_Auto(bool * value) = 0;
    virtual HRESULT __stdcall put_Auto(bool value) = 0;
    virtual HRESULT __stdcall get_RedEyeReduction(bool * value) = 0;
    virtual HRESULT __stdcall put_RedEyeReduction(bool value) = 0;
    virtual HRESULT __stdcall get_PowerPercent(float * value) = 0;
    virtual HRESULT __stdcall put_PowerPercent(float value) = 0;
};

struct __declspec(uuid("7d29cc9e-75e1-4af7-bd7d-4e38e1c06cd6")) __declspec(novtable) IFlashControl2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AssistantLightSupported(bool * value) = 0;
    virtual HRESULT __stdcall get_AssistantLightEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_AssistantLightEnabled(bool value) = 0;
};

struct __declspec(uuid("c0d889f6-5228-4453-b153-85606592b238")) __declspec(novtable) IFocusControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Supported(bool * value) = 0;
    virtual HRESULT __stdcall get_SupportedPresets(Windows::Foundation::Collections::IVectorView<winrt::Windows::Media::Devices::FocusPreset> ** value) = 0;
    virtual HRESULT __stdcall get_Preset(winrt::Windows::Media::Devices::FocusPreset * value) = 0;
    virtual HRESULT __stdcall abi_SetPresetAsync(winrt::Windows::Media::Devices::FocusPreset preset, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_SetPresetWithCompletionOptionAsync(winrt::Windows::Media::Devices::FocusPreset preset, bool completeBeforeFocus, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall get_Min(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Max(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Step(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Value(uint32_t * value) = 0;
    virtual HRESULT __stdcall abi_SetValueAsync(uint32_t focus, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_FocusAsync(Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
};

struct __declspec(uuid("3f7cff48-c534-4e9e-94c3-52ef2afd5d07")) __declspec(novtable) IFocusControl2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FocusChangedSupported(bool * value) = 0;
    virtual HRESULT __stdcall get_WaitForFocusSupported(bool * value) = 0;
    virtual HRESULT __stdcall get_SupportedFocusModes(Windows::Foundation::Collections::IVectorView<winrt::Windows::Media::Devices::FocusMode> ** value) = 0;
    virtual HRESULT __stdcall get_SupportedFocusDistances(Windows::Foundation::Collections::IVectorView<winrt::Windows::Media::Devices::ManualFocusDistance> ** value) = 0;
    virtual HRESULT __stdcall get_SupportedFocusRanges(Windows::Foundation::Collections::IVectorView<winrt::Windows::Media::Devices::AutoFocusRange> ** value) = 0;
    virtual HRESULT __stdcall get_Mode(winrt::Windows::Media::Devices::FocusMode * value) = 0;
    virtual HRESULT __stdcall get_FocusState(winrt::Windows::Media::Devices::MediaCaptureFocusState * value) = 0;
    virtual HRESULT __stdcall abi_UnlockAsync(Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_LockAsync(Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_Configure(Windows::Media::Devices::IFocusSettings * settings) = 0;
};

struct __declspec(uuid("79958f6b-3263-4275-85d6-aeae891c96ee")) __declspec(novtable) IFocusSettings : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Mode(winrt::Windows::Media::Devices::FocusMode * value) = 0;
    virtual HRESULT __stdcall put_Mode(winrt::Windows::Media::Devices::FocusMode value) = 0;
    virtual HRESULT __stdcall get_AutoFocusRange(winrt::Windows::Media::Devices::AutoFocusRange * value) = 0;
    virtual HRESULT __stdcall put_AutoFocusRange(winrt::Windows::Media::Devices::AutoFocusRange value) = 0;
    virtual HRESULT __stdcall get_Value(Windows::Foundation::IReference<uint32_t> ** value) = 0;
    virtual HRESULT __stdcall put_Value(Windows::Foundation::IReference<uint32_t> * value) = 0;
    virtual HRESULT __stdcall get_Distance(Windows::Foundation::IReference<winrt::Windows::Media::Devices::ManualFocusDistance> ** value) = 0;
    virtual HRESULT __stdcall put_Distance(Windows::Foundation::IReference<winrt::Windows::Media::Devices::ManualFocusDistance> * value) = 0;
    virtual HRESULT __stdcall get_WaitForFocus(bool * value) = 0;
    virtual HRESULT __stdcall put_WaitForFocus(bool value) = 0;
    virtual HRESULT __stdcall get_DisableDriverFallback(bool * value) = 0;
    virtual HRESULT __stdcall put_DisableDriverFallback(bool value) = 0;
};

struct __declspec(uuid("55d8e2d0-30c0-43bf-9b9a-9799d70ced94")) __declspec(novtable) IHdrVideoControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Supported(bool * value) = 0;
    virtual HRESULT __stdcall get_SupportedModes(Windows::Foundation::Collections::IVectorView<winrt::Windows::Media::Devices::HdrVideoMode> ** value) = 0;
    virtual HRESULT __stdcall get_Mode(winrt::Windows::Media::Devices::HdrVideoMode * value) = 0;
    virtual HRESULT __stdcall put_Mode(winrt::Windows::Media::Devices::HdrVideoMode value) = 0;
};

struct __declspec(uuid("27b6c322-25ad-4f1b-aaab-524ab376ca33")) __declspec(novtable) IIsoSpeedControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Supported(bool * value) = 0;
    virtual HRESULT __stdcall get_SupportedPresets(Windows::Foundation::Collections::IVectorView<winrt::Windows::Media::Devices::IsoSpeedPreset> ** value) = 0;
    virtual HRESULT __stdcall get_Preset(winrt::Windows::Media::Devices::IsoSpeedPreset * value) = 0;
    virtual HRESULT __stdcall abi_SetPresetAsync(winrt::Windows::Media::Devices::IsoSpeedPreset preset, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
};

struct __declspec(uuid("6f1578f2-6d77-4f8a-8c2f-6130b6395053")) __declspec(novtable) IIsoSpeedControl2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Min(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Max(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Step(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Value(uint32_t * value) = 0;
    virtual HRESULT __stdcall abi_SetValueAsync(uint32_t isoSpeed, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall get_Auto(bool * value) = 0;
    virtual HRESULT __stdcall abi_SetAutoAsync(Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
};

struct __declspec(uuid("d3a43900-b4fa-49cd-9442-89af6568f601")) __declspec(novtable) IKeypadPressedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TelephonyKey(winrt::Windows::Media::Devices::TelephonyKey * telephonyKey) = 0;
};

struct __declspec(uuid("6d5c4dd0-fadf-415d-aee6-3baa529300c9")) __declspec(novtable) ILowLagPhotoControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetHighestConcurrentFrameRate(Windows::Media::MediaProperties::IMediaEncodingProperties * captureProperties, Windows::Media::MediaProperties::IMediaRatio ** value) = 0;
    virtual HRESULT __stdcall abi_GetCurrentFrameRate(Windows::Media::MediaProperties::IMediaRatio ** value) = 0;
    virtual HRESULT __stdcall get_ThumbnailEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_ThumbnailEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_ThumbnailFormat(winrt::Windows::Media::MediaProperties::MediaThumbnailFormat * value) = 0;
    virtual HRESULT __stdcall put_ThumbnailFormat(winrt::Windows::Media::MediaProperties::MediaThumbnailFormat value) = 0;
    virtual HRESULT __stdcall get_DesiredThumbnailSize(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_DesiredThumbnailSize(uint32_t value) = 0;
    virtual HRESULT __stdcall get_HardwareAcceleratedThumbnailSupported(uint32_t * value) = 0;
};

struct __declspec(uuid("3dcf909d-6d16-409c-bafe-b9a594c6fde6")) __declspec(novtable) ILowLagPhotoSequenceControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Supported(bool * value) = 0;
    virtual HRESULT __stdcall get_MaxPastPhotos(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_MaxPhotosPerSecond(float * value) = 0;
    virtual HRESULT __stdcall get_PastPhotoLimit(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_PastPhotoLimit(uint32_t value) = 0;
    virtual HRESULT __stdcall get_PhotosPerSecondLimit(float * value) = 0;
    virtual HRESULT __stdcall put_PhotosPerSecondLimit(float value) = 0;
    virtual HRESULT __stdcall abi_GetHighestConcurrentFrameRate(Windows::Media::MediaProperties::IMediaEncodingProperties * captureProperties, Windows::Media::MediaProperties::IMediaRatio ** value) = 0;
    virtual HRESULT __stdcall abi_GetCurrentFrameRate(Windows::Media::MediaProperties::IMediaRatio ** value) = 0;
    virtual HRESULT __stdcall get_ThumbnailEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_ThumbnailEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_ThumbnailFormat(winrt::Windows::Media::MediaProperties::MediaThumbnailFormat * value) = 0;
    virtual HRESULT __stdcall put_ThumbnailFormat(winrt::Windows::Media::MediaProperties::MediaThumbnailFormat value) = 0;
    virtual HRESULT __stdcall get_DesiredThumbnailSize(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_DesiredThumbnailSize(uint32_t value) = 0;
    virtual HRESULT __stdcall get_HardwareAcceleratedThumbnailSupported(uint32_t * value) = 0;
};

struct __declspec(uuid("efa8dfa9-6f75-4863-ba0b-583f3036b4de")) __declspec(novtable) IMediaDeviceControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Capabilities(Windows::Media::Devices::IMediaDeviceControlCapabilities ** value) = 0;
    virtual HRESULT __stdcall abi_TryGetValue(double * value, bool * succeeded) = 0;
    virtual HRESULT __stdcall abi_TrySetValue(double value, bool * succeeded) = 0;
    virtual HRESULT __stdcall abi_TryGetAuto(bool * value, bool * succeeded) = 0;
    virtual HRESULT __stdcall abi_TrySetAuto(bool value, bool * succeeded) = 0;
};

struct __declspec(uuid("23005816-eb85-43e2-b92b-8240d5ee70ec")) __declspec(novtable) IMediaDeviceControlCapabilities : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Supported(bool * value) = 0;
    virtual HRESULT __stdcall get_Min(double * value) = 0;
    virtual HRESULT __stdcall get_Max(double * value) = 0;
    virtual HRESULT __stdcall get_Step(double * value) = 0;
    virtual HRESULT __stdcall get_Default(double * value) = 0;
    virtual HRESULT __stdcall get_AutoModeSupported(bool * value) = 0;
};

struct __declspec(uuid("f6f8f5ce-209a-48fb-86fc-d44578f317e6")) __declspec(novtable) IMediaDeviceController : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetAvailableMediaStreamProperties(winrt::Windows::Media::Capture::MediaStreamType mediaStreamType, Windows::Foundation::Collections::IVectorView<Windows::Media::MediaProperties::IMediaEncodingProperties> ** value) = 0;
    virtual HRESULT __stdcall abi_GetMediaStreamProperties(winrt::Windows::Media::Capture::MediaStreamType mediaStreamType, Windows::Media::MediaProperties::IMediaEncodingProperties ** value) = 0;
    virtual HRESULT __stdcall abi_SetMediaStreamPropertiesAsync(winrt::Windows::Media::Capture::MediaStreamType mediaStreamType, Windows::Media::MediaProperties::IMediaEncodingProperties * mediaEncodingProperties, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
};

struct __declspec(uuid("aa2d9a40-909f-4bba-bf8b-0c0d296f14f0")) __declspec(novtable) IMediaDeviceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetAudioCaptureSelector(hstring * selector) = 0;
    virtual HRESULT __stdcall abi_GetAudioRenderSelector(hstring * selector) = 0;
    virtual HRESULT __stdcall abi_GetVideoCaptureSelector(hstring * selector) = 0;
    virtual HRESULT __stdcall abi_GetDefaultAudioCaptureId(winrt::Windows::Media::Devices::AudioDeviceRole role, hstring * deviceId) = 0;
    virtual HRESULT __stdcall abi_GetDefaultAudioRenderId(winrt::Windows::Media::Devices::AudioDeviceRole role, hstring * deviceId) = 0;
    virtual HRESULT __stdcall add_DefaultAudioCaptureDeviceChanged(Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Media::Devices::DefaultAudioCaptureDeviceChangedEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_DefaultAudioCaptureDeviceChanged(event_token cookie) = 0;
    virtual HRESULT __stdcall add_DefaultAudioRenderDeviceChanged(Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Media::Devices::DefaultAudioRenderDeviceChangedEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_DefaultAudioRenderDeviceChanged(event_token cookie) = 0;
};

struct __declspec(uuid("bfad9c1d-00bc-423b-8eb2-a0178ca94247")) __declspec(novtable) IOpticalImageStabilizationControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Supported(bool * value) = 0;
    virtual HRESULT __stdcall get_SupportedModes(Windows::Foundation::Collections::IVectorView<winrt::Windows::Media::Devices::OpticalImageStabilizationMode> ** value) = 0;
    virtual HRESULT __stdcall get_Mode(winrt::Windows::Media::Devices::OpticalImageStabilizationMode * value) = 0;
    virtual HRESULT __stdcall put_Mode(winrt::Windows::Media::Devices::OpticalImageStabilizationMode value) = 0;
};

struct __declspec(uuid("c8f3f363-ff5e-4582-a9a8-0550f85a4a76")) __declspec(novtable) IPhotoConfirmationControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Supported(bool * pbSupported) = 0;
    virtual HRESULT __stdcall get_Enabled(bool * value) = 0;
    virtual HRESULT __stdcall put_Enabled(bool value) = 0;
    virtual HRESULT __stdcall get_PixelFormat(winrt::Windows::Media::MediaProperties::MediaPixelFormat * format) = 0;
    virtual HRESULT __stdcall put_PixelFormat(winrt::Windows::Media::MediaProperties::MediaPixelFormat format) = 0;
};

struct __declspec(uuid("7eb55209-76ab-4c31-b40e-4b58379d580c")) __declspec(novtable) IRedialRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Handled() = 0;
};

struct __declspec(uuid("e5ecc834-ce66-4e05-a78f-cf391a5ec2d1")) __declspec(novtable) IRegionOfInterest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AutoFocusEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_AutoFocusEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_AutoWhiteBalanceEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_AutoWhiteBalanceEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_AutoExposureEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_AutoExposureEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_Bounds(Windows::Foundation::Rect * value) = 0;
    virtual HRESULT __stdcall put_Bounds(Windows::Foundation::Rect value) = 0;
};

struct __declspec(uuid("19fe2a91-73aa-4d51-8a9d-56ccf7db7f54")) __declspec(novtable) IRegionOfInterest2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Type(winrt::Windows::Media::Devices::RegionOfInterestType * value) = 0;
    virtual HRESULT __stdcall put_Type(winrt::Windows::Media::Devices::RegionOfInterestType value) = 0;
    virtual HRESULT __stdcall get_BoundsNormalized(bool * value) = 0;
    virtual HRESULT __stdcall put_BoundsNormalized(bool value) = 0;
    virtual HRESULT __stdcall get_Weight(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_Weight(uint32_t value) = 0;
};

struct __declspec(uuid("c323f527-ab0b-4558-8b5b-df5693db0378")) __declspec(novtable) IRegionsOfInterestControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MaxRegions(uint32_t * value) = 0;
    virtual HRESULT __stdcall abi_SetRegionsAsync(Windows::Foundation::Collections::IIterable<Windows::Media::Devices::RegionOfInterest> * regions, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_SetRegionsWithLockAsync(Windows::Foundation::Collections::IIterable<Windows::Media::Devices::RegionOfInterest> * regions, bool lockValues, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_ClearRegionsAsync(Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall get_AutoFocusSupported(bool * value) = 0;
    virtual HRESULT __stdcall get_AutoWhiteBalanceSupported(bool * value) = 0;
    virtual HRESULT __stdcall get_AutoExposureSupported(bool * value) = 0;
};

struct __declspec(uuid("d48e5af7-8d59-4854-8c62-12c70ba89b7c")) __declspec(novtable) ISceneModeControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SupportedModes(Windows::Foundation::Collections::IVectorView<winrt::Windows::Media::Devices::CaptureSceneMode> ** value) = 0;
    virtual HRESULT __stdcall get_Value(winrt::Windows::Media::Devices::CaptureSceneMode * value) = 0;
    virtual HRESULT __stdcall abi_SetValueAsync(winrt::Windows::Media::Devices::CaptureSceneMode sceneMode, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
};

struct __declspec(uuid("a6053665-8250-416c-919a-724296afa306")) __declspec(novtable) ITorchControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Supported(bool * value) = 0;
    virtual HRESULT __stdcall get_PowerSupported(bool * value) = 0;
    virtual HRESULT __stdcall get_Enabled(bool * value) = 0;
    virtual HRESULT __stdcall put_Enabled(bool value) = 0;
    virtual HRESULT __stdcall get_PowerPercent(float * value) = 0;
    virtual HRESULT __stdcall put_PowerPercent(float value) = 0;
};

struct __declspec(uuid("99555575-2e2e-40b8-b6c7-f82d10013210")) __declspec(novtable) IVideoDeviceController : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Brightness(Windows::Media::Devices::IMediaDeviceControl ** value) = 0;
    virtual HRESULT __stdcall get_Contrast(Windows::Media::Devices::IMediaDeviceControl ** value) = 0;
    virtual HRESULT __stdcall get_Hue(Windows::Media::Devices::IMediaDeviceControl ** value) = 0;
    virtual HRESULT __stdcall get_WhiteBalance(Windows::Media::Devices::IMediaDeviceControl ** value) = 0;
    virtual HRESULT __stdcall get_BacklightCompensation(Windows::Media::Devices::IMediaDeviceControl ** value) = 0;
    virtual HRESULT __stdcall get_Pan(Windows::Media::Devices::IMediaDeviceControl ** value) = 0;
    virtual HRESULT __stdcall get_Tilt(Windows::Media::Devices::IMediaDeviceControl ** value) = 0;
    virtual HRESULT __stdcall get_Zoom(Windows::Media::Devices::IMediaDeviceControl ** value) = 0;
    virtual HRESULT __stdcall get_Roll(Windows::Media::Devices::IMediaDeviceControl ** value) = 0;
    virtual HRESULT __stdcall get_Exposure(Windows::Media::Devices::IMediaDeviceControl ** value) = 0;
    virtual HRESULT __stdcall get_Focus(Windows::Media::Devices::IMediaDeviceControl ** value) = 0;
    virtual HRESULT __stdcall abi_TrySetPowerlineFrequency(winrt::Windows::Media::Capture::PowerlineFrequency value, bool * succeeded) = 0;
    virtual HRESULT __stdcall abi_TryGetPowerlineFrequency(winrt::Windows::Media::Capture::PowerlineFrequency * value, bool * succeeded) = 0;
};

struct __declspec(uuid("781f047e-7162-49c8-a8f9-9481c565363e")) __declspec(novtable) IWhiteBalanceControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Supported(bool * value) = 0;
    virtual HRESULT __stdcall get_Preset(winrt::Windows::Media::Devices::ColorTemperaturePreset * value) = 0;
    virtual HRESULT __stdcall abi_SetPresetAsync(winrt::Windows::Media::Devices::ColorTemperaturePreset preset, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall get_Min(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Max(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Step(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Value(uint32_t * value) = 0;
    virtual HRESULT __stdcall abi_SetValueAsync(uint32_t temperature, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
};

struct __declspec(uuid("3a1e0b12-32da-4c17-bfd7-8d0c73c8f5a5")) __declspec(novtable) IZoomControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Supported(bool * value) = 0;
    virtual HRESULT __stdcall get_Min(float * value) = 0;
    virtual HRESULT __stdcall get_Max(float * value) = 0;
    virtual HRESULT __stdcall get_Step(float * value) = 0;
    virtual HRESULT __stdcall get_Value(float * value) = 0;
    virtual HRESULT __stdcall put_Value(float value) = 0;
};

struct __declspec(uuid("69843db0-2e99-4641-8529-184f319d1671")) __declspec(novtable) IZoomControl2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SupportedModes(Windows::Foundation::Collections::IVectorView<winrt::Windows::Media::Devices::ZoomTransitionMode> ** value) = 0;
    virtual HRESULT __stdcall get_Mode(winrt::Windows::Media::Devices::ZoomTransitionMode * value) = 0;
    virtual HRESULT __stdcall abi_Configure(Windows::Media::Devices::IZoomSettings * settings) = 0;
};

struct __declspec(uuid("6ad66b24-14b4-4bfd-b18f-88fe24463b52")) __declspec(novtable) IZoomSettings : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Mode(winrt::Windows::Media::Devices::ZoomTransitionMode * value) = 0;
    virtual HRESULT __stdcall put_Mode(winrt::Windows::Media::Devices::ZoomTransitionMode value) = 0;
    virtual HRESULT __stdcall get_Value(float * value) = 0;
    virtual HRESULT __stdcall put_Value(float value) = 0;
};

struct __declspec(uuid("e637a454-c527-422c-8926-c9af83b559a0")) __declspec(novtable) KeypadPressedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Media::Devices::ICallControl * sender, Windows::Media::Devices::IKeypadPressedEventArgs * e) = 0;
};

struct __declspec(uuid("baf257d1-4ebd-4b84-9f47-6ec43d75d8b1")) __declspec(novtable) RedialRequestedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Media::Devices::ICallControl * sender, Windows::Media::Devices::IRedialRequestedEventArgs * e) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Media::Devices::AdvancedPhotoCaptureSettings> { using default_interface = Windows::Media::Devices::IAdvancedPhotoCaptureSettings; };
template <> struct traits<Windows::Media::Devices::AdvancedPhotoControl> { using default_interface = Windows::Media::Devices::IAdvancedPhotoControl; };
template <> struct traits<Windows::Media::Devices::AudioDeviceController> { using default_interface = Windows::Media::Devices::IAudioDeviceController; };
template <> struct traits<Windows::Media::Devices::CallControl> { using default_interface = Windows::Media::Devices::ICallControl; };
template <> struct traits<Windows::Media::Devices::DefaultAudioCaptureDeviceChangedEventArgs> { using default_interface = Windows::Media::Devices::IDefaultAudioDeviceChangedEventArgs; };
template <> struct traits<Windows::Media::Devices::DefaultAudioRenderDeviceChangedEventArgs> { using default_interface = Windows::Media::Devices::IDefaultAudioDeviceChangedEventArgs; };
template <> struct traits<Windows::Media::Devices::DialRequestedEventArgs> { using default_interface = Windows::Media::Devices::IDialRequestedEventArgs; };
template <> struct traits<Windows::Media::Devices::ExposureCompensationControl> { using default_interface = Windows::Media::Devices::IExposureCompensationControl; };
template <> struct traits<Windows::Media::Devices::ExposureControl> { using default_interface = Windows::Media::Devices::IExposureControl; };
template <> struct traits<Windows::Media::Devices::ExposurePriorityVideoControl> { using default_interface = Windows::Media::Devices::IExposurePriorityVideoControl; };
template <> struct traits<Windows::Media::Devices::FlashControl> { using default_interface = Windows::Media::Devices::IFlashControl; };
template <> struct traits<Windows::Media::Devices::FocusControl> { using default_interface = Windows::Media::Devices::IFocusControl; };
template <> struct traits<Windows::Media::Devices::FocusSettings> { using default_interface = Windows::Media::Devices::IFocusSettings; };
template <> struct traits<Windows::Media::Devices::HdrVideoControl> { using default_interface = Windows::Media::Devices::IHdrVideoControl; };
template <> struct traits<Windows::Media::Devices::IsoSpeedControl> { using default_interface = Windows::Media::Devices::IIsoSpeedControl; };
template <> struct traits<Windows::Media::Devices::KeypadPressedEventArgs> { using default_interface = Windows::Media::Devices::IKeypadPressedEventArgs; };
template <> struct traits<Windows::Media::Devices::LowLagPhotoControl> { using default_interface = Windows::Media::Devices::ILowLagPhotoControl; };
template <> struct traits<Windows::Media::Devices::LowLagPhotoSequenceControl> { using default_interface = Windows::Media::Devices::ILowLagPhotoSequenceControl; };
template <> struct traits<Windows::Media::Devices::MediaDeviceControl> { using default_interface = Windows::Media::Devices::IMediaDeviceControl; };
template <> struct traits<Windows::Media::Devices::MediaDeviceControlCapabilities> { using default_interface = Windows::Media::Devices::IMediaDeviceControlCapabilities; };
template <> struct traits<Windows::Media::Devices::OpticalImageStabilizationControl> { using default_interface = Windows::Media::Devices::IOpticalImageStabilizationControl; };
template <> struct traits<Windows::Media::Devices::PhotoConfirmationControl> { using default_interface = Windows::Media::Devices::IPhotoConfirmationControl; };
template <> struct traits<Windows::Media::Devices::RedialRequestedEventArgs> { using default_interface = Windows::Media::Devices::IRedialRequestedEventArgs; };
template <> struct traits<Windows::Media::Devices::RegionOfInterest> { using default_interface = Windows::Media::Devices::IRegionOfInterest; };
template <> struct traits<Windows::Media::Devices::RegionsOfInterestControl> { using default_interface = Windows::Media::Devices::IRegionsOfInterestControl; };
template <> struct traits<Windows::Media::Devices::SceneModeControl> { using default_interface = Windows::Media::Devices::ISceneModeControl; };
template <> struct traits<Windows::Media::Devices::TorchControl> { using default_interface = Windows::Media::Devices::ITorchControl; };
template <> struct traits<Windows::Media::Devices::VideoDeviceController> { using default_interface = Windows::Media::Devices::IVideoDeviceController; };
template <> struct traits<Windows::Media::Devices::WhiteBalanceControl> { using default_interface = Windows::Media::Devices::IWhiteBalanceControl; };
template <> struct traits<Windows::Media::Devices::ZoomControl> { using default_interface = Windows::Media::Devices::IZoomControl; };
template <> struct traits<Windows::Media::Devices::ZoomSettings> { using default_interface = Windows::Media::Devices::IZoomSettings; };

}

namespace Windows::Media::Devices {

template <typename D>
struct WINRT_EBO impl_IAdvancedPhotoCaptureSettings
{
    Windows::Media::Devices::AdvancedPhotoMode Mode() const;
    void Mode(Windows::Media::Devices::AdvancedPhotoMode value) const;
};

template <typename D>
struct WINRT_EBO impl_IAdvancedPhotoControl
{
    bool Supported() const;
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Media::Devices::AdvancedPhotoMode> SupportedModes() const;
    Windows::Media::Devices::AdvancedPhotoMode Mode() const;
    void Configure(const Windows::Media::Devices::AdvancedPhotoCaptureSettings & settings) const;
};

template <typename D>
struct WINRT_EBO impl_IAdvancedVideoCaptureDeviceController
{
    void SetDeviceProperty(hstring_view propertyId, const Windows::Foundation::IInspectable & propertyValue) const;
    Windows::Foundation::IInspectable GetDeviceProperty(hstring_view propertyId) const;
};

template <typename D>
struct WINRT_EBO impl_IAdvancedVideoCaptureDeviceController2
{
    Windows::Media::Devices::LowLagPhotoSequenceControl LowLagPhotoSequence() const;
    Windows::Media::Devices::LowLagPhotoControl LowLagPhoto() const;
    Windows::Media::Devices::SceneModeControl SceneModeControl() const;
    Windows::Media::Devices::TorchControl TorchControl() const;
    Windows::Media::Devices::FlashControl FlashControl() const;
    Windows::Media::Devices::WhiteBalanceControl WhiteBalanceControl() const;
    Windows::Media::Devices::ExposureControl ExposureControl() const;
    Windows::Media::Devices::FocusControl FocusControl() const;
    Windows::Media::Devices::ExposureCompensationControl ExposureCompensationControl() const;
    Windows::Media::Devices::IsoSpeedControl IsoSpeedControl() const;
    Windows::Media::Devices::RegionsOfInterestControl RegionsOfInterestControl() const;
    Windows::Media::Devices::CaptureUse PrimaryUse() const;
    void PrimaryUse(Windows::Media::Devices::CaptureUse value) const;
};

template <typename D>
struct WINRT_EBO impl_IAdvancedVideoCaptureDeviceController3
{
    Windows::Media::Devices::Core::VariablePhotoSequenceController VariablePhotoSequenceController() const;
    Windows::Media::Devices::PhotoConfirmationControl PhotoConfirmationControl() const;
    Windows::Media::Devices::ZoomControl ZoomControl() const;
};

template <typename D>
struct WINRT_EBO impl_IAdvancedVideoCaptureDeviceController4
{
    Windows::Media::Devices::ExposurePriorityVideoControl ExposurePriorityVideoControl() const;
    Windows::Media::Devices::MediaCaptureOptimization DesiredOptimization() const;
    void DesiredOptimization(Windows::Media::Devices::MediaCaptureOptimization value) const;
    Windows::Media::Devices::HdrVideoControl HdrVideoControl() const;
    Windows::Media::Devices::OpticalImageStabilizationControl OpticalImageStabilizationControl() const;
    Windows::Media::Devices::AdvancedPhotoControl AdvancedPhotoControl() const;
};

template <typename D>
struct WINRT_EBO impl_IAudioDeviceController
{
    void Muted(bool value) const;
    bool Muted() const;
    void VolumePercent(float value) const;
    float VolumePercent() const;
};

template <typename D>
struct WINRT_EBO impl_ICallControl
{
    uint64_t IndicateNewIncomingCall(bool enableRinger, hstring_view callerId) const;
    uint64_t IndicateNewOutgoingCall() const;
    void IndicateActiveCall(uint64_t callToken) const;
    void EndCall(uint64_t callToken) const;
    bool HasRinger() const;
    event_token AnswerRequested(const Windows::Media::Devices::CallControlEventHandler & handler) const;
    using AnswerRequested_revoker = event_revoker<ICallControl>;
    AnswerRequested_revoker AnswerRequested(auto_revoke_t, const Windows::Media::Devices::CallControlEventHandler & handler) const;
    void AnswerRequested(event_token token) const;
    event_token HangUpRequested(const Windows::Media::Devices::CallControlEventHandler & handler) const;
    using HangUpRequested_revoker = event_revoker<ICallControl>;
    HangUpRequested_revoker HangUpRequested(auto_revoke_t, const Windows::Media::Devices::CallControlEventHandler & handler) const;
    void HangUpRequested(event_token token) const;
    event_token DialRequested(const Windows::Media::Devices::DialRequestedEventHandler & handler) const;
    using DialRequested_revoker = event_revoker<ICallControl>;
    DialRequested_revoker DialRequested(auto_revoke_t, const Windows::Media::Devices::DialRequestedEventHandler & handler) const;
    void DialRequested(event_token token) const;
    event_token RedialRequested(const Windows::Media::Devices::RedialRequestedEventHandler & handler) const;
    using RedialRequested_revoker = event_revoker<ICallControl>;
    RedialRequested_revoker RedialRequested(auto_revoke_t, const Windows::Media::Devices::RedialRequestedEventHandler & handler) const;
    void RedialRequested(event_token token) const;
    event_token KeypadPressed(const Windows::Media::Devices::KeypadPressedEventHandler & handler) const;
    using KeypadPressed_revoker = event_revoker<ICallControl>;
    KeypadPressed_revoker KeypadPressed(auto_revoke_t, const Windows::Media::Devices::KeypadPressedEventHandler & handler) const;
    void KeypadPressed(event_token token) const;
    event_token AudioTransferRequested(const Windows::Media::Devices::CallControlEventHandler & handler) const;
    using AudioTransferRequested_revoker = event_revoker<ICallControl>;
    AudioTransferRequested_revoker AudioTransferRequested(auto_revoke_t, const Windows::Media::Devices::CallControlEventHandler & handler) const;
    void AudioTransferRequested(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_ICallControlStatics
{
    Windows::Media::Devices::CallControl GetDefault() const;
    Windows::Media::Devices::CallControl FromId(hstring_view deviceId) const;
};

template <typename D>
struct WINRT_EBO impl_IDefaultAudioDeviceChangedEventArgs
{
    hstring Id() const;
    Windows::Media::Devices::AudioDeviceRole Role() const;
};

template <typename D>
struct WINRT_EBO impl_IDialRequestedEventArgs
{
    void Handled() const;
    Windows::Foundation::IInspectable Contact() const;
};

template <typename D>
struct WINRT_EBO impl_IExposureCompensationControl
{
    bool Supported() const;
    float Min() const;
    float Max() const;
    float Step() const;
    float Value() const;
    Windows::Foundation::IAsyncAction SetValueAsync(float value) const;
};

template <typename D>
struct WINRT_EBO impl_IExposureControl
{
    bool Supported() const;
    bool Auto() const;
    Windows::Foundation::IAsyncAction SetAutoAsync(bool value) const;
    Windows::Foundation::TimeSpan Min() const;
    Windows::Foundation::TimeSpan Max() const;
    Windows::Foundation::TimeSpan Step() const;
    Windows::Foundation::TimeSpan Value() const;
    Windows::Foundation::IAsyncAction SetValueAsync(const Windows::Foundation::TimeSpan & shutterDuration) const;
};

template <typename D>
struct WINRT_EBO impl_IExposurePriorityVideoControl
{
    bool Supported() const;
    bool Enabled() const;
    void Enabled(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IFlashControl
{
    bool Supported() const;
    bool PowerSupported() const;
    bool RedEyeReductionSupported() const;
    bool Enabled() const;
    void Enabled(bool value) const;
    bool Auto() const;
    void Auto(bool value) const;
    bool RedEyeReduction() const;
    void RedEyeReduction(bool value) const;
    float PowerPercent() const;
    void PowerPercent(float value) const;
};

template <typename D>
struct WINRT_EBO impl_IFlashControl2
{
    bool AssistantLightSupported() const;
    bool AssistantLightEnabled() const;
    void AssistantLightEnabled(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IFocusControl
{
    bool Supported() const;
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Media::Devices::FocusPreset> SupportedPresets() const;
    Windows::Media::Devices::FocusPreset Preset() const;
    Windows::Foundation::IAsyncAction SetPresetAsync(Windows::Media::Devices::FocusPreset preset) const;
    Windows::Foundation::IAsyncAction SetPresetAsync(Windows::Media::Devices::FocusPreset preset, bool completeBeforeFocus) const;
    uint32_t Min() const;
    uint32_t Max() const;
    uint32_t Step() const;
    uint32_t Value() const;
    Windows::Foundation::IAsyncAction SetValueAsync(uint32_t focus) const;
    Windows::Foundation::IAsyncAction FocusAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IFocusControl2
{
    bool FocusChangedSupported() const;
    bool WaitForFocusSupported() const;
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Media::Devices::FocusMode> SupportedFocusModes() const;
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Media::Devices::ManualFocusDistance> SupportedFocusDistances() const;
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Media::Devices::AutoFocusRange> SupportedFocusRanges() const;
    Windows::Media::Devices::FocusMode Mode() const;
    Windows::Media::Devices::MediaCaptureFocusState FocusState() const;
    Windows::Foundation::IAsyncAction UnlockAsync() const;
    Windows::Foundation::IAsyncAction LockAsync() const;
    void Configure(const Windows::Media::Devices::FocusSettings & settings) const;
};

template <typename D>
struct WINRT_EBO impl_IFocusSettings
{
    Windows::Media::Devices::FocusMode Mode() const;
    void Mode(Windows::Media::Devices::FocusMode value) const;
    Windows::Media::Devices::AutoFocusRange AutoFocusRange() const;
    void AutoFocusRange(Windows::Media::Devices::AutoFocusRange value) const;
    Windows::Foundation::IReference<uint32_t> Value() const;
    void Value(const optional<uint32_t> & value) const;
    Windows::Foundation::IReference<winrt::Windows::Media::Devices::ManualFocusDistance> Distance() const;
    void Distance(const optional<winrt::Windows::Media::Devices::ManualFocusDistance> & value) const;
    bool WaitForFocus() const;
    void WaitForFocus(bool value) const;
    bool DisableDriverFallback() const;
    void DisableDriverFallback(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IHdrVideoControl
{
    bool Supported() const;
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Media::Devices::HdrVideoMode> SupportedModes() const;
    Windows::Media::Devices::HdrVideoMode Mode() const;
    void Mode(Windows::Media::Devices::HdrVideoMode value) const;
};

template <typename D>
struct WINRT_EBO impl_IIsoSpeedControl
{
    bool Supported() const;
    [[deprecated("SupportedPresets may not be available in future versions of Windows Phone. Starting with Windows Phone 8.1, use SetAutoAsync, Auto, SetValueAsync, and Value instead")]] Windows::Foundation::Collections::IVectorView<winrt::Windows::Media::Devices::IsoSpeedPreset> SupportedPresets() const;
    [[deprecated("Preset may not be available in future versions of Windows Phone. Starting with Windows Phone 8.1, use SetAutoAsync, Auto, SetValueAsync, and Value instead")]] Windows::Media::Devices::IsoSpeedPreset Preset() const;
    [[deprecated("SetPresetAsync may not be available in future versions of Windows Phone. Starting with Windows Phone 8.1, use SetAutoAsync, Auto, SetValueAsync, and Value instead")]] Windows::Foundation::IAsyncAction SetPresetAsync(Windows::Media::Devices::IsoSpeedPreset preset) const;
};

template <typename D>
struct WINRT_EBO impl_IIsoSpeedControl2
{
    uint32_t Min() const;
    uint32_t Max() const;
    uint32_t Step() const;
    uint32_t Value() const;
    Windows::Foundation::IAsyncAction SetValueAsync(uint32_t isoSpeed) const;
    bool Auto() const;
    Windows::Foundation::IAsyncAction SetAutoAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IKeypadPressedEventArgs
{
    Windows::Media::Devices::TelephonyKey TelephonyKey() const;
};

template <typename D>
struct WINRT_EBO impl_ILowLagPhotoControl
{
    Windows::Media::MediaProperties::MediaRatio GetHighestConcurrentFrameRate(const Windows::Media::MediaProperties::IMediaEncodingProperties & captureProperties) const;
    Windows::Media::MediaProperties::MediaRatio GetCurrentFrameRate() const;
    bool ThumbnailEnabled() const;
    void ThumbnailEnabled(bool value) const;
    Windows::Media::MediaProperties::MediaThumbnailFormat ThumbnailFormat() const;
    void ThumbnailFormat(Windows::Media::MediaProperties::MediaThumbnailFormat value) const;
    uint32_t DesiredThumbnailSize() const;
    void DesiredThumbnailSize(uint32_t value) const;
    uint32_t HardwareAcceleratedThumbnailSupported() const;
};

template <typename D>
struct WINRT_EBO impl_ILowLagPhotoSequenceControl
{
    bool Supported() const;
    uint32_t MaxPastPhotos() const;
    float MaxPhotosPerSecond() const;
    uint32_t PastPhotoLimit() const;
    void PastPhotoLimit(uint32_t value) const;
    float PhotosPerSecondLimit() const;
    void PhotosPerSecondLimit(float value) const;
    Windows::Media::MediaProperties::MediaRatio GetHighestConcurrentFrameRate(const Windows::Media::MediaProperties::IMediaEncodingProperties & captureProperties) const;
    Windows::Media::MediaProperties::MediaRatio GetCurrentFrameRate() const;
    bool ThumbnailEnabled() const;
    void ThumbnailEnabled(bool value) const;
    Windows::Media::MediaProperties::MediaThumbnailFormat ThumbnailFormat() const;
    void ThumbnailFormat(Windows::Media::MediaProperties::MediaThumbnailFormat value) const;
    uint32_t DesiredThumbnailSize() const;
    void DesiredThumbnailSize(uint32_t value) const;
    uint32_t HardwareAcceleratedThumbnailSupported() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaDeviceControl
{
    Windows::Media::Devices::MediaDeviceControlCapabilities Capabilities() const;
    bool TryGetValue(double & value) const;
    bool TrySetValue(double value) const;
    bool TryGetAuto(bool & value) const;
    bool TrySetAuto(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaDeviceControlCapabilities
{
    bool Supported() const;
    double Min() const;
    double Max() const;
    double Step() const;
    double Default() const;
    bool AutoModeSupported() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaDeviceController
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::MediaProperties::IMediaEncodingProperties> GetAvailableMediaStreamProperties(Windows::Media::Capture::MediaStreamType mediaStreamType) const;
    Windows::Media::MediaProperties::IMediaEncodingProperties GetMediaStreamProperties(Windows::Media::Capture::MediaStreamType mediaStreamType) const;
    Windows::Foundation::IAsyncAction SetMediaStreamPropertiesAsync(Windows::Media::Capture::MediaStreamType mediaStreamType, const Windows::Media::MediaProperties::IMediaEncodingProperties & mediaEncodingProperties) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaDeviceStatics
{
    hstring GetAudioCaptureSelector() const;
    hstring GetAudioRenderSelector() const;
    hstring GetVideoCaptureSelector() const;
    hstring GetDefaultAudioCaptureId(Windows::Media::Devices::AudioDeviceRole role) const;
    hstring GetDefaultAudioRenderId(Windows::Media::Devices::AudioDeviceRole role) const;
    event_token DefaultAudioCaptureDeviceChanged(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Media::Devices::DefaultAudioCaptureDeviceChangedEventArgs> & handler) const;
    using DefaultAudioCaptureDeviceChanged_revoker = event_revoker<IMediaDeviceStatics>;
    DefaultAudioCaptureDeviceChanged_revoker DefaultAudioCaptureDeviceChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Media::Devices::DefaultAudioCaptureDeviceChangedEventArgs> & handler) const;
    void DefaultAudioCaptureDeviceChanged(event_token cookie) const;
    event_token DefaultAudioRenderDeviceChanged(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Media::Devices::DefaultAudioRenderDeviceChangedEventArgs> & handler) const;
    using DefaultAudioRenderDeviceChanged_revoker = event_revoker<IMediaDeviceStatics>;
    DefaultAudioRenderDeviceChanged_revoker DefaultAudioRenderDeviceChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Media::Devices::DefaultAudioRenderDeviceChangedEventArgs> & handler) const;
    void DefaultAudioRenderDeviceChanged(event_token cookie) const;
};

template <typename D>
struct WINRT_EBO impl_IOpticalImageStabilizationControl
{
    bool Supported() const;
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Media::Devices::OpticalImageStabilizationMode> SupportedModes() const;
    Windows::Media::Devices::OpticalImageStabilizationMode Mode() const;
    void Mode(Windows::Media::Devices::OpticalImageStabilizationMode value) const;
};

template <typename D>
struct WINRT_EBO impl_IPhotoConfirmationControl
{
    bool Supported() const;
    bool Enabled() const;
    void Enabled(bool value) const;
    Windows::Media::MediaProperties::MediaPixelFormat PixelFormat() const;
    void PixelFormat(Windows::Media::MediaProperties::MediaPixelFormat format) const;
};

template <typename D>
struct WINRT_EBO impl_IRedialRequestedEventArgs
{
    void Handled() const;
};

template <typename D>
struct WINRT_EBO impl_IRegionOfInterest
{
    bool AutoFocusEnabled() const;
    void AutoFocusEnabled(bool value) const;
    bool AutoWhiteBalanceEnabled() const;
    void AutoWhiteBalanceEnabled(bool value) const;
    bool AutoExposureEnabled() const;
    void AutoExposureEnabled(bool value) const;
    Windows::Foundation::Rect Bounds() const;
    void Bounds(const Windows::Foundation::Rect & value) const;
};

template <typename D>
struct WINRT_EBO impl_IRegionOfInterest2
{
    Windows::Media::Devices::RegionOfInterestType Type() const;
    void Type(Windows::Media::Devices::RegionOfInterestType value) const;
    bool BoundsNormalized() const;
    void BoundsNormalized(bool value) const;
    uint32_t Weight() const;
    void Weight(uint32_t value) const;
};

template <typename D>
struct WINRT_EBO impl_IRegionsOfInterestControl
{
    uint32_t MaxRegions() const;
    Windows::Foundation::IAsyncAction SetRegionsAsync(iterable<Windows::Media::Devices::RegionOfInterest> regions) const;
    Windows::Foundation::IAsyncAction SetRegionsAsync(iterable<Windows::Media::Devices::RegionOfInterest> regions, bool lockValues) const;
    Windows::Foundation::IAsyncAction ClearRegionsAsync() const;
    bool AutoFocusSupported() const;
    bool AutoWhiteBalanceSupported() const;
    bool AutoExposureSupported() const;
};

template <typename D>
struct WINRT_EBO impl_ISceneModeControl
{
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Media::Devices::CaptureSceneMode> SupportedModes() const;
    Windows::Media::Devices::CaptureSceneMode Value() const;
    Windows::Foundation::IAsyncAction SetValueAsync(Windows::Media::Devices::CaptureSceneMode sceneMode) const;
};

template <typename D>
struct WINRT_EBO impl_ITorchControl
{
    bool Supported() const;
    bool PowerSupported() const;
    bool Enabled() const;
    void Enabled(bool value) const;
    float PowerPercent() const;
    void PowerPercent(float value) const;
};

template <typename D>
struct WINRT_EBO impl_IVideoDeviceController
{
    Windows::Media::Devices::MediaDeviceControl Brightness() const;
    Windows::Media::Devices::MediaDeviceControl Contrast() const;
    Windows::Media::Devices::MediaDeviceControl Hue() const;
    Windows::Media::Devices::MediaDeviceControl WhiteBalance() const;
    Windows::Media::Devices::MediaDeviceControl BacklightCompensation() const;
    Windows::Media::Devices::MediaDeviceControl Pan() const;
    Windows::Media::Devices::MediaDeviceControl Tilt() const;
    Windows::Media::Devices::MediaDeviceControl Zoom() const;
    Windows::Media::Devices::MediaDeviceControl Roll() const;
    Windows::Media::Devices::MediaDeviceControl Exposure() const;
    Windows::Media::Devices::MediaDeviceControl Focus() const;
    bool TrySetPowerlineFrequency(Windows::Media::Capture::PowerlineFrequency value) const;
    bool TryGetPowerlineFrequency(Windows::Media::Capture::PowerlineFrequency & value) const;
};

template <typename D>
struct WINRT_EBO impl_IWhiteBalanceControl
{
    bool Supported() const;
    Windows::Media::Devices::ColorTemperaturePreset Preset() const;
    Windows::Foundation::IAsyncAction SetPresetAsync(Windows::Media::Devices::ColorTemperaturePreset preset) const;
    uint32_t Min() const;
    uint32_t Max() const;
    uint32_t Step() const;
    uint32_t Value() const;
    Windows::Foundation::IAsyncAction SetValueAsync(uint32_t temperature) const;
};

template <typename D>
struct WINRT_EBO impl_IZoomControl
{
    bool Supported() const;
    float Min() const;
    float Max() const;
    float Step() const;
    float Value() const;
    void Value(float value) const;
};

template <typename D>
struct WINRT_EBO impl_IZoomControl2
{
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Media::Devices::ZoomTransitionMode> SupportedModes() const;
    Windows::Media::Devices::ZoomTransitionMode Mode() const;
    void Configure(const Windows::Media::Devices::ZoomSettings & settings) const;
};

template <typename D>
struct WINRT_EBO impl_IZoomSettings
{
    Windows::Media::Devices::ZoomTransitionMode Mode() const;
    void Mode(Windows::Media::Devices::ZoomTransitionMode value) const;
    float Value() const;
    void Value(float value) const;
};

}

namespace impl {

template <> struct traits<Windows::Media::Devices::CallControlEventHandler>
{
    using abi = ABI::Windows::Media::Devices::CallControlEventHandler;
};

template <> struct traits<Windows::Media::Devices::DialRequestedEventHandler>
{
    using abi = ABI::Windows::Media::Devices::DialRequestedEventHandler;
};

template <> struct traits<Windows::Media::Devices::IAdvancedPhotoCaptureSettings>
{
    using abi = ABI::Windows::Media::Devices::IAdvancedPhotoCaptureSettings;
    template <typename D> using consume = Windows::Media::Devices::impl_IAdvancedPhotoCaptureSettings<D>;
};

template <> struct traits<Windows::Media::Devices::IAdvancedPhotoControl>
{
    using abi = ABI::Windows::Media::Devices::IAdvancedPhotoControl;
    template <typename D> using consume = Windows::Media::Devices::impl_IAdvancedPhotoControl<D>;
};

template <> struct traits<Windows::Media::Devices::IAdvancedVideoCaptureDeviceController>
{
    using abi = ABI::Windows::Media::Devices::IAdvancedVideoCaptureDeviceController;
    template <typename D> using consume = Windows::Media::Devices::impl_IAdvancedVideoCaptureDeviceController<D>;
};

template <> struct traits<Windows::Media::Devices::IAdvancedVideoCaptureDeviceController2>
{
    using abi = ABI::Windows::Media::Devices::IAdvancedVideoCaptureDeviceController2;
    template <typename D> using consume = Windows::Media::Devices::impl_IAdvancedVideoCaptureDeviceController2<D>;
};

template <> struct traits<Windows::Media::Devices::IAdvancedVideoCaptureDeviceController3>
{
    using abi = ABI::Windows::Media::Devices::IAdvancedVideoCaptureDeviceController3;
    template <typename D> using consume = Windows::Media::Devices::impl_IAdvancedVideoCaptureDeviceController3<D>;
};

template <> struct traits<Windows::Media::Devices::IAdvancedVideoCaptureDeviceController4>
{
    using abi = ABI::Windows::Media::Devices::IAdvancedVideoCaptureDeviceController4;
    template <typename D> using consume = Windows::Media::Devices::impl_IAdvancedVideoCaptureDeviceController4<D>;
};

template <> struct traits<Windows::Media::Devices::IAudioDeviceController>
{
    using abi = ABI::Windows::Media::Devices::IAudioDeviceController;
    template <typename D> using consume = Windows::Media::Devices::impl_IAudioDeviceController<D>;
};

template <> struct traits<Windows::Media::Devices::ICallControl>
{
    using abi = ABI::Windows::Media::Devices::ICallControl;
    template <typename D> using consume = Windows::Media::Devices::impl_ICallControl<D>;
};

template <> struct traits<Windows::Media::Devices::ICallControlStatics>
{
    using abi = ABI::Windows::Media::Devices::ICallControlStatics;
    template <typename D> using consume = Windows::Media::Devices::impl_ICallControlStatics<D>;
};

template <> struct traits<Windows::Media::Devices::IDefaultAudioDeviceChangedEventArgs>
{
    using abi = ABI::Windows::Media::Devices::IDefaultAudioDeviceChangedEventArgs;
    template <typename D> using consume = Windows::Media::Devices::impl_IDefaultAudioDeviceChangedEventArgs<D>;
};

template <> struct traits<Windows::Media::Devices::IDialRequestedEventArgs>
{
    using abi = ABI::Windows::Media::Devices::IDialRequestedEventArgs;
    template <typename D> using consume = Windows::Media::Devices::impl_IDialRequestedEventArgs<D>;
};

template <> struct traits<Windows::Media::Devices::IExposureCompensationControl>
{
    using abi = ABI::Windows::Media::Devices::IExposureCompensationControl;
    template <typename D> using consume = Windows::Media::Devices::impl_IExposureCompensationControl<D>;
};

template <> struct traits<Windows::Media::Devices::IExposureControl>
{
    using abi = ABI::Windows::Media::Devices::IExposureControl;
    template <typename D> using consume = Windows::Media::Devices::impl_IExposureControl<D>;
};

template <> struct traits<Windows::Media::Devices::IExposurePriorityVideoControl>
{
    using abi = ABI::Windows::Media::Devices::IExposurePriorityVideoControl;
    template <typename D> using consume = Windows::Media::Devices::impl_IExposurePriorityVideoControl<D>;
};

template <> struct traits<Windows::Media::Devices::IFlashControl>
{
    using abi = ABI::Windows::Media::Devices::IFlashControl;
    template <typename D> using consume = Windows::Media::Devices::impl_IFlashControl<D>;
};

template <> struct traits<Windows::Media::Devices::IFlashControl2>
{
    using abi = ABI::Windows::Media::Devices::IFlashControl2;
    template <typename D> using consume = Windows::Media::Devices::impl_IFlashControl2<D>;
};

template <> struct traits<Windows::Media::Devices::IFocusControl>
{
    using abi = ABI::Windows::Media::Devices::IFocusControl;
    template <typename D> using consume = Windows::Media::Devices::impl_IFocusControl<D>;
};

template <> struct traits<Windows::Media::Devices::IFocusControl2>
{
    using abi = ABI::Windows::Media::Devices::IFocusControl2;
    template <typename D> using consume = Windows::Media::Devices::impl_IFocusControl2<D>;
};

template <> struct traits<Windows::Media::Devices::IFocusSettings>
{
    using abi = ABI::Windows::Media::Devices::IFocusSettings;
    template <typename D> using consume = Windows::Media::Devices::impl_IFocusSettings<D>;
};

template <> struct traits<Windows::Media::Devices::IHdrVideoControl>
{
    using abi = ABI::Windows::Media::Devices::IHdrVideoControl;
    template <typename D> using consume = Windows::Media::Devices::impl_IHdrVideoControl<D>;
};

template <> struct traits<Windows::Media::Devices::IIsoSpeedControl>
{
    using abi = ABI::Windows::Media::Devices::IIsoSpeedControl;
    template <typename D> using consume = Windows::Media::Devices::impl_IIsoSpeedControl<D>;
};

template <> struct traits<Windows::Media::Devices::IIsoSpeedControl2>
{
    using abi = ABI::Windows::Media::Devices::IIsoSpeedControl2;
    template <typename D> using consume = Windows::Media::Devices::impl_IIsoSpeedControl2<D>;
};

template <> struct traits<Windows::Media::Devices::IKeypadPressedEventArgs>
{
    using abi = ABI::Windows::Media::Devices::IKeypadPressedEventArgs;
    template <typename D> using consume = Windows::Media::Devices::impl_IKeypadPressedEventArgs<D>;
};

template <> struct traits<Windows::Media::Devices::ILowLagPhotoControl>
{
    using abi = ABI::Windows::Media::Devices::ILowLagPhotoControl;
    template <typename D> using consume = Windows::Media::Devices::impl_ILowLagPhotoControl<D>;
};

template <> struct traits<Windows::Media::Devices::ILowLagPhotoSequenceControl>
{
    using abi = ABI::Windows::Media::Devices::ILowLagPhotoSequenceControl;
    template <typename D> using consume = Windows::Media::Devices::impl_ILowLagPhotoSequenceControl<D>;
};

template <> struct traits<Windows::Media::Devices::IMediaDeviceControl>
{
    using abi = ABI::Windows::Media::Devices::IMediaDeviceControl;
    template <typename D> using consume = Windows::Media::Devices::impl_IMediaDeviceControl<D>;
};

template <> struct traits<Windows::Media::Devices::IMediaDeviceControlCapabilities>
{
    using abi = ABI::Windows::Media::Devices::IMediaDeviceControlCapabilities;
    template <typename D> using consume = Windows::Media::Devices::impl_IMediaDeviceControlCapabilities<D>;
};

template <> struct traits<Windows::Media::Devices::IMediaDeviceController>
{
    using abi = ABI::Windows::Media::Devices::IMediaDeviceController;
    template <typename D> using consume = Windows::Media::Devices::impl_IMediaDeviceController<D>;
};

template <> struct traits<Windows::Media::Devices::IMediaDeviceStatics>
{
    using abi = ABI::Windows::Media::Devices::IMediaDeviceStatics;
    template <typename D> using consume = Windows::Media::Devices::impl_IMediaDeviceStatics<D>;
};

template <> struct traits<Windows::Media::Devices::IOpticalImageStabilizationControl>
{
    using abi = ABI::Windows::Media::Devices::IOpticalImageStabilizationControl;
    template <typename D> using consume = Windows::Media::Devices::impl_IOpticalImageStabilizationControl<D>;
};

template <> struct traits<Windows::Media::Devices::IPhotoConfirmationControl>
{
    using abi = ABI::Windows::Media::Devices::IPhotoConfirmationControl;
    template <typename D> using consume = Windows::Media::Devices::impl_IPhotoConfirmationControl<D>;
};

template <> struct traits<Windows::Media::Devices::IRedialRequestedEventArgs>
{
    using abi = ABI::Windows::Media::Devices::IRedialRequestedEventArgs;
    template <typename D> using consume = Windows::Media::Devices::impl_IRedialRequestedEventArgs<D>;
};

template <> struct traits<Windows::Media::Devices::IRegionOfInterest>
{
    using abi = ABI::Windows::Media::Devices::IRegionOfInterest;
    template <typename D> using consume = Windows::Media::Devices::impl_IRegionOfInterest<D>;
};

template <> struct traits<Windows::Media::Devices::IRegionOfInterest2>
{
    using abi = ABI::Windows::Media::Devices::IRegionOfInterest2;
    template <typename D> using consume = Windows::Media::Devices::impl_IRegionOfInterest2<D>;
};

template <> struct traits<Windows::Media::Devices::IRegionsOfInterestControl>
{
    using abi = ABI::Windows::Media::Devices::IRegionsOfInterestControl;
    template <typename D> using consume = Windows::Media::Devices::impl_IRegionsOfInterestControl<D>;
};

template <> struct traits<Windows::Media::Devices::ISceneModeControl>
{
    using abi = ABI::Windows::Media::Devices::ISceneModeControl;
    template <typename D> using consume = Windows::Media::Devices::impl_ISceneModeControl<D>;
};

template <> struct traits<Windows::Media::Devices::ITorchControl>
{
    using abi = ABI::Windows::Media::Devices::ITorchControl;
    template <typename D> using consume = Windows::Media::Devices::impl_ITorchControl<D>;
};

template <> struct traits<Windows::Media::Devices::IVideoDeviceController>
{
    using abi = ABI::Windows::Media::Devices::IVideoDeviceController;
    template <typename D> using consume = Windows::Media::Devices::impl_IVideoDeviceController<D>;
};

template <> struct traits<Windows::Media::Devices::IWhiteBalanceControl>
{
    using abi = ABI::Windows::Media::Devices::IWhiteBalanceControl;
    template <typename D> using consume = Windows::Media::Devices::impl_IWhiteBalanceControl<D>;
};

template <> struct traits<Windows::Media::Devices::IZoomControl>
{
    using abi = ABI::Windows::Media::Devices::IZoomControl;
    template <typename D> using consume = Windows::Media::Devices::impl_IZoomControl<D>;
};

template <> struct traits<Windows::Media::Devices::IZoomControl2>
{
    using abi = ABI::Windows::Media::Devices::IZoomControl2;
    template <typename D> using consume = Windows::Media::Devices::impl_IZoomControl2<D>;
};

template <> struct traits<Windows::Media::Devices::IZoomSettings>
{
    using abi = ABI::Windows::Media::Devices::IZoomSettings;
    template <typename D> using consume = Windows::Media::Devices::impl_IZoomSettings<D>;
};

template <> struct traits<Windows::Media::Devices::KeypadPressedEventHandler>
{
    using abi = ABI::Windows::Media::Devices::KeypadPressedEventHandler;
};

template <> struct traits<Windows::Media::Devices::RedialRequestedEventHandler>
{
    using abi = ABI::Windows::Media::Devices::RedialRequestedEventHandler;
};

template <> struct traits<Windows::Media::Devices::AdvancedPhotoCaptureSettings>
{
    using abi = ABI::Windows::Media::Devices::AdvancedPhotoCaptureSettings;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.AdvancedPhotoCaptureSettings"; }
};

template <> struct traits<Windows::Media::Devices::AdvancedPhotoControl>
{
    using abi = ABI::Windows::Media::Devices::AdvancedPhotoControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.AdvancedPhotoControl"; }
};

template <> struct traits<Windows::Media::Devices::AudioDeviceController>
{
    using abi = ABI::Windows::Media::Devices::AudioDeviceController;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.AudioDeviceController"; }
};

template <> struct traits<Windows::Media::Devices::CallControl>
{
    using abi = ABI::Windows::Media::Devices::CallControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.CallControl"; }
};

template <> struct traits<Windows::Media::Devices::DefaultAudioCaptureDeviceChangedEventArgs>
{
    using abi = ABI::Windows::Media::Devices::DefaultAudioCaptureDeviceChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.DefaultAudioCaptureDeviceChangedEventArgs"; }
};

template <> struct traits<Windows::Media::Devices::DefaultAudioRenderDeviceChangedEventArgs>
{
    using abi = ABI::Windows::Media::Devices::DefaultAudioRenderDeviceChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.DefaultAudioRenderDeviceChangedEventArgs"; }
};

template <> struct traits<Windows::Media::Devices::DialRequestedEventArgs>
{
    using abi = ABI::Windows::Media::Devices::DialRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.DialRequestedEventArgs"; }
};

template <> struct traits<Windows::Media::Devices::ExposureCompensationControl>
{
    using abi = ABI::Windows::Media::Devices::ExposureCompensationControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.ExposureCompensationControl"; }
};

template <> struct traits<Windows::Media::Devices::ExposureControl>
{
    using abi = ABI::Windows::Media::Devices::ExposureControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.ExposureControl"; }
};

template <> struct traits<Windows::Media::Devices::ExposurePriorityVideoControl>
{
    using abi = ABI::Windows::Media::Devices::ExposurePriorityVideoControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.ExposurePriorityVideoControl"; }
};

template <> struct traits<Windows::Media::Devices::FlashControl>
{
    using abi = ABI::Windows::Media::Devices::FlashControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.FlashControl"; }
};

template <> struct traits<Windows::Media::Devices::FocusControl>
{
    using abi = ABI::Windows::Media::Devices::FocusControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.FocusControl"; }
};

template <> struct traits<Windows::Media::Devices::FocusSettings>
{
    using abi = ABI::Windows::Media::Devices::FocusSettings;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.FocusSettings"; }
};

template <> struct traits<Windows::Media::Devices::HdrVideoControl>
{
    using abi = ABI::Windows::Media::Devices::HdrVideoControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.HdrVideoControl"; }
};

template <> struct traits<Windows::Media::Devices::IsoSpeedControl>
{
    using abi = ABI::Windows::Media::Devices::IsoSpeedControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.IsoSpeedControl"; }
};

template <> struct traits<Windows::Media::Devices::KeypadPressedEventArgs>
{
    using abi = ABI::Windows::Media::Devices::KeypadPressedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.KeypadPressedEventArgs"; }
};

template <> struct traits<Windows::Media::Devices::LowLagPhotoControl>
{
    using abi = ABI::Windows::Media::Devices::LowLagPhotoControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.LowLagPhotoControl"; }
};

template <> struct traits<Windows::Media::Devices::LowLagPhotoSequenceControl>
{
    using abi = ABI::Windows::Media::Devices::LowLagPhotoSequenceControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.LowLagPhotoSequenceControl"; }
};

template <> struct traits<Windows::Media::Devices::MediaDevice>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.MediaDevice"; }
};

template <> struct traits<Windows::Media::Devices::MediaDeviceControl>
{
    using abi = ABI::Windows::Media::Devices::MediaDeviceControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.MediaDeviceControl"; }
};

template <> struct traits<Windows::Media::Devices::MediaDeviceControlCapabilities>
{
    using abi = ABI::Windows::Media::Devices::MediaDeviceControlCapabilities;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.MediaDeviceControlCapabilities"; }
};

template <> struct traits<Windows::Media::Devices::OpticalImageStabilizationControl>
{
    using abi = ABI::Windows::Media::Devices::OpticalImageStabilizationControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.OpticalImageStabilizationControl"; }
};

template <> struct traits<Windows::Media::Devices::PhotoConfirmationControl>
{
    using abi = ABI::Windows::Media::Devices::PhotoConfirmationControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.PhotoConfirmationControl"; }
};

template <> struct traits<Windows::Media::Devices::RedialRequestedEventArgs>
{
    using abi = ABI::Windows::Media::Devices::RedialRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.RedialRequestedEventArgs"; }
};

template <> struct traits<Windows::Media::Devices::RegionOfInterest>
{
    using abi = ABI::Windows::Media::Devices::RegionOfInterest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.RegionOfInterest"; }
};

template <> struct traits<Windows::Media::Devices::RegionsOfInterestControl>
{
    using abi = ABI::Windows::Media::Devices::RegionsOfInterestControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.RegionsOfInterestControl"; }
};

template <> struct traits<Windows::Media::Devices::SceneModeControl>
{
    using abi = ABI::Windows::Media::Devices::SceneModeControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.SceneModeControl"; }
};

template <> struct traits<Windows::Media::Devices::TorchControl>
{
    using abi = ABI::Windows::Media::Devices::TorchControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.TorchControl"; }
};

template <> struct traits<Windows::Media::Devices::VideoDeviceController>
{
    using abi = ABI::Windows::Media::Devices::VideoDeviceController;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.VideoDeviceController"; }
};

template <> struct traits<Windows::Media::Devices::WhiteBalanceControl>
{
    using abi = ABI::Windows::Media::Devices::WhiteBalanceControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.WhiteBalanceControl"; }
};

template <> struct traits<Windows::Media::Devices::ZoomControl>
{
    using abi = ABI::Windows::Media::Devices::ZoomControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.ZoomControl"; }
};

template <> struct traits<Windows::Media::Devices::ZoomSettings>
{
    using abi = ABI::Windows::Media::Devices::ZoomSettings;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.ZoomSettings"; }
};

}

}
