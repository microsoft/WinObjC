// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.Devices.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Media::Devices {

template <typename H> struct impl_CallControlEventHandler : implements<impl_CallControlEventHandler<H>, abi<CallControlEventHandler>>, H
{
    impl_CallControlEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Media::Devices::ICallControl> sender) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Media::Devices::CallControl *>(&sender));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_DialRequestedEventHandler : implements<impl_DialRequestedEventHandler<H>, abi<DialRequestedEventHandler>>, H
{
    impl_DialRequestedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Media::Devices::ICallControl> sender, impl::abi_arg_in<Windows::Media::Devices::IDialRequestedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Media::Devices::CallControl *>(&sender), *reinterpret_cast<const Windows::Media::Devices::DialRequestedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_KeypadPressedEventHandler : implements<impl_KeypadPressedEventHandler<H>, abi<KeypadPressedEventHandler>>, H
{
    impl_KeypadPressedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Media::Devices::ICallControl> sender, impl::abi_arg_in<Windows::Media::Devices::IKeypadPressedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Media::Devices::CallControl *>(&sender), *reinterpret_cast<const Windows::Media::Devices::KeypadPressedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_RedialRequestedEventHandler : implements<impl_RedialRequestedEventHandler<H>, abi<RedialRequestedEventHandler>>, H
{
    impl_RedialRequestedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Media::Devices::ICallControl> sender, impl::abi_arg_in<Windows::Media::Devices::IRedialRequestedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Media::Devices::CallControl *>(&sender), *reinterpret_cast<const Windows::Media::Devices::RedialRequestedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Media::Devices {

struct WINRT_EBO AdvancedPhotoCaptureSettings :
    Windows::Media::Devices::IAdvancedPhotoCaptureSettings
{
    AdvancedPhotoCaptureSettings(std::nullptr_t) noexcept {}
    AdvancedPhotoCaptureSettings();
};

struct WINRT_EBO AdvancedPhotoControl :
    Windows::Media::Devices::IAdvancedPhotoControl
{
    AdvancedPhotoControl(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AudioDeviceController :
    Windows::Media::Devices::IAudioDeviceController
{
    AudioDeviceController(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CallControl :
    Windows::Media::Devices::ICallControl
{
    CallControl(std::nullptr_t) noexcept {}
    static Windows::Media::Devices::CallControl GetDefault();
    static Windows::Media::Devices::CallControl FromId(hstring_view deviceId);
};

struct WINRT_EBO DefaultAudioCaptureDeviceChangedEventArgs :
    Windows::Media::Devices::IDefaultAudioDeviceChangedEventArgs
{
    DefaultAudioCaptureDeviceChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DefaultAudioRenderDeviceChangedEventArgs :
    Windows::Media::Devices::IDefaultAudioDeviceChangedEventArgs
{
    DefaultAudioRenderDeviceChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DialRequestedEventArgs :
    Windows::Media::Devices::IDialRequestedEventArgs
{
    DialRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ExposureCompensationControl :
    Windows::Media::Devices::IExposureCompensationControl
{
    ExposureCompensationControl(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ExposureControl :
    Windows::Media::Devices::IExposureControl
{
    ExposureControl(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ExposurePriorityVideoControl :
    Windows::Media::Devices::IExposurePriorityVideoControl
{
    ExposurePriorityVideoControl(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FlashControl :
    Windows::Media::Devices::IFlashControl,
    impl::require<FlashControl, Windows::Media::Devices::IFlashControl2>
{
    FlashControl(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FocusControl :
    Windows::Media::Devices::IFocusControl,
    impl::require<FocusControl, Windows::Media::Devices::IFocusControl2>
{
    FocusControl(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FocusSettings :
    Windows::Media::Devices::IFocusSettings
{
    FocusSettings(std::nullptr_t) noexcept {}
    FocusSettings();
};

struct WINRT_EBO HdrVideoControl :
    Windows::Media::Devices::IHdrVideoControl
{
    HdrVideoControl(std::nullptr_t) noexcept {}
};

struct WINRT_EBO IsoSpeedControl :
    Windows::Media::Devices::IIsoSpeedControl,
    impl::require<IsoSpeedControl, Windows::Media::Devices::IIsoSpeedControl2>
{
    IsoSpeedControl(std::nullptr_t) noexcept {}
};

struct WINRT_EBO KeypadPressedEventArgs :
    Windows::Media::Devices::IKeypadPressedEventArgs
{
    KeypadPressedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO LowLagPhotoControl :
    Windows::Media::Devices::ILowLagPhotoControl
{
    LowLagPhotoControl(std::nullptr_t) noexcept {}
};

struct WINRT_EBO LowLagPhotoSequenceControl :
    Windows::Media::Devices::ILowLagPhotoSequenceControl
{
    LowLagPhotoSequenceControl(std::nullptr_t) noexcept {}
};

struct MediaDevice
{
    MediaDevice() = delete;
    static hstring GetAudioCaptureSelector();
    static hstring GetAudioRenderSelector();
    static hstring GetVideoCaptureSelector();
    static hstring GetDefaultAudioCaptureId(Windows::Media::Devices::AudioDeviceRole role);
    static hstring GetDefaultAudioRenderId(Windows::Media::Devices::AudioDeviceRole role);
    static event_token DefaultAudioCaptureDeviceChanged(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Media::Devices::DefaultAudioCaptureDeviceChangedEventArgs> & handler);
    using DefaultAudioCaptureDeviceChanged_revoker = factory_event_revoker<IMediaDeviceStatics>;
    static DefaultAudioCaptureDeviceChanged_revoker DefaultAudioCaptureDeviceChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Media::Devices::DefaultAudioCaptureDeviceChangedEventArgs> & handler);
    static void DefaultAudioCaptureDeviceChanged(event_token cookie);
    static event_token DefaultAudioRenderDeviceChanged(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Media::Devices::DefaultAudioRenderDeviceChangedEventArgs> & handler);
    using DefaultAudioRenderDeviceChanged_revoker = factory_event_revoker<IMediaDeviceStatics>;
    static DefaultAudioRenderDeviceChanged_revoker DefaultAudioRenderDeviceChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Media::Devices::DefaultAudioRenderDeviceChangedEventArgs> & handler);
    static void DefaultAudioRenderDeviceChanged(event_token cookie);
};

struct WINRT_EBO MediaDeviceControl :
    Windows::Media::Devices::IMediaDeviceControl
{
    MediaDeviceControl(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaDeviceControlCapabilities :
    Windows::Media::Devices::IMediaDeviceControlCapabilities
{
    MediaDeviceControlCapabilities(std::nullptr_t) noexcept {}
};

struct WINRT_EBO OpticalImageStabilizationControl :
    Windows::Media::Devices::IOpticalImageStabilizationControl
{
    OpticalImageStabilizationControl(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PhotoConfirmationControl :
    Windows::Media::Devices::IPhotoConfirmationControl
{
    PhotoConfirmationControl(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RedialRequestedEventArgs :
    Windows::Media::Devices::IRedialRequestedEventArgs
{
    RedialRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RegionOfInterest :
    Windows::Media::Devices::IRegionOfInterest,
    impl::require<RegionOfInterest, Windows::Media::Devices::IRegionOfInterest2>
{
    RegionOfInterest(std::nullptr_t) noexcept {}
    RegionOfInterest();
};

struct WINRT_EBO RegionsOfInterestControl :
    Windows::Media::Devices::IRegionsOfInterestControl
{
    RegionsOfInterestControl(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SceneModeControl :
    Windows::Media::Devices::ISceneModeControl
{
    SceneModeControl(std::nullptr_t) noexcept {}
};

struct WINRT_EBO TorchControl :
    Windows::Media::Devices::ITorchControl
{
    TorchControl(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VideoDeviceController :
    Windows::Media::Devices::IVideoDeviceController,
    impl::require<VideoDeviceController, Windows::Media::Devices::IAdvancedVideoCaptureDeviceController2, Windows::Media::Devices::IAdvancedVideoCaptureDeviceController3, Windows::Media::Devices::IAdvancedVideoCaptureDeviceController4, Windows::Media::Devices::IAdvancedVideoCaptureDeviceController>
{
    VideoDeviceController(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WhiteBalanceControl :
    Windows::Media::Devices::IWhiteBalanceControl
{
    WhiteBalanceControl(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ZoomControl :
    Windows::Media::Devices::IZoomControl,
    impl::require<ZoomControl, Windows::Media::Devices::IZoomControl2>
{
    ZoomControl(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ZoomSettings :
    Windows::Media::Devices::IZoomSettings
{
    ZoomSettings(std::nullptr_t) noexcept {}
    ZoomSettings();
};

}

}
