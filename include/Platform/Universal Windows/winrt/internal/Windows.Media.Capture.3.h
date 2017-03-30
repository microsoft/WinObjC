// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.Capture.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Media::Capture {

template <typename H> struct impl_MediaCaptureFailedEventHandler : implements<impl_MediaCaptureFailedEventHandler<H>, abi<MediaCaptureFailedEventHandler>>, H
{
    impl_MediaCaptureFailedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Media::Capture::IMediaCapture> sender, impl::abi_arg_in<Windows::Media::Capture::IMediaCaptureFailedEventArgs> errorEventArgs) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Media::Capture::MediaCapture *>(&sender), *reinterpret_cast<const Windows::Media::Capture::MediaCaptureFailedEventArgs *>(&errorEventArgs));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_RecordLimitationExceededEventHandler : implements<impl_RecordLimitationExceededEventHandler<H>, abi<RecordLimitationExceededEventHandler>>, H
{
    impl_RecordLimitationExceededEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Media::Capture::IMediaCapture> sender) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Media::Capture::MediaCapture *>(&sender));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Media::Capture {

struct WINRT_EBO AdvancedCapturedPhoto :
    Windows::Media::Capture::IAdvancedCapturedPhoto,
    impl::require<AdvancedCapturedPhoto, Windows::Media::Capture::IAdvancedCapturedPhoto2>
{
    AdvancedCapturedPhoto(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AdvancedPhotoCapture :
    Windows::Media::Capture::IAdvancedPhotoCapture
{
    AdvancedPhotoCapture(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AppCapture :
    Windows::Media::Capture::IAppCapture
{
    AppCapture(std::nullptr_t) noexcept {}
    static Windows::Media::Capture::AppCapture GetForCurrentView();
};

struct WINRT_EBO AppCaptureAlternateShortcutKeys :
    Windows::Media::Capture::IAppCaptureAlternateShortcutKeys,
    impl::require<AppCaptureAlternateShortcutKeys, Windows::Media::Capture::IAppCaptureAlternateShortcutKeys2, Windows::Media::Capture::IAppCaptureAlternateShortcutKeys3>
{
    AppCaptureAlternateShortcutKeys(std::nullptr_t) noexcept {}
};

struct AppCaptureManager
{
    AppCaptureManager() = delete;
    static Windows::Media::Capture::AppCaptureSettings GetCurrentSettings();
    static void ApplySettings(const Windows::Media::Capture::AppCaptureSettings & appCaptureSettings);
};

struct WINRT_EBO AppCaptureSettings :
    Windows::Media::Capture::IAppCaptureSettings,
    impl::require<AppCaptureSettings, Windows::Media::Capture::IAppCaptureSettings2, Windows::Media::Capture::IAppCaptureSettings3, Windows::Media::Capture::IAppCaptureSettings4>
{
    AppCaptureSettings(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CameraCaptureUI :
    Windows::Media::Capture::ICameraCaptureUI
{
    CameraCaptureUI(std::nullptr_t) noexcept {}
    CameraCaptureUI();
};

struct WINRT_EBO CameraCaptureUIPhotoCaptureSettings :
    Windows::Media::Capture::ICameraCaptureUIPhotoCaptureSettings
{
    CameraCaptureUIPhotoCaptureSettings(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CameraCaptureUIVideoCaptureSettings :
    Windows::Media::Capture::ICameraCaptureUIVideoCaptureSettings
{
    CameraCaptureUIVideoCaptureSettings(std::nullptr_t) noexcept {}
};

struct CameraOptionsUI
{
    CameraOptionsUI() = delete;
    static void Show(const Windows::Media::Capture::MediaCapture & mediaCapture);
};

struct WINRT_EBO CapturedFrame :
    Windows::Media::Capture::ICapturedFrame,
    impl::require<CapturedFrame, Windows::Media::Capture::ICapturedFrameWithSoftwareBitmap>
{
    CapturedFrame(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CapturedFrameControlValues :
    Windows::Media::Capture::ICapturedFrameControlValues,
    impl::require<CapturedFrameControlValues, Windows::Media::Capture::ICapturedFrameControlValues2>
{
    CapturedFrameControlValues(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CapturedPhoto :
    Windows::Media::Capture::ICapturedPhoto
{
    CapturedPhoto(std::nullptr_t) noexcept {}
};

struct WINRT_EBO LowLagMediaRecording :
    Windows::Media::Capture::ILowLagMediaRecording,
    impl::require<LowLagMediaRecording, Windows::Media::Capture::ILowLagMediaRecording2, Windows::Media::Capture::ILowLagMediaRecording3>
{
    LowLagMediaRecording(std::nullptr_t) noexcept {}
};

struct WINRT_EBO LowLagPhotoCapture :
    Windows::Media::Capture::ILowLagPhotoCapture
{
    LowLagPhotoCapture(std::nullptr_t) noexcept {}
};

struct WINRT_EBO LowLagPhotoSequenceCapture :
    Windows::Media::Capture::ILowLagPhotoSequenceCapture
{
    LowLagPhotoSequenceCapture(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaCapture :
    Windows::Media::Capture::IMediaCapture,
    impl::require<MediaCapture, Windows::Foundation::IClosable, Windows::Media::Capture::IMediaCapture2, Windows::Media::Capture::IMediaCapture3, Windows::Media::Capture::IMediaCapture4, Windows::Media::Capture::IMediaCapture5, Windows::Media::Capture::IMediaCaptureVideoPreview>
{
    MediaCapture(std::nullptr_t) noexcept {}
    MediaCapture();
    static bool IsVideoProfileSupported(hstring_view videoDeviceId);
    static Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> FindAllVideoProfiles(hstring_view videoDeviceId);
    static Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> FindConcurrentProfiles(hstring_view videoDeviceId);
    static Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> FindKnownVideoProfiles(hstring_view videoDeviceId, Windows::Media::Capture::KnownVideoProfile name);
};

struct WINRT_EBO MediaCaptureFailedEventArgs :
    Windows::Media::Capture::IMediaCaptureFailedEventArgs
{
    MediaCaptureFailedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaCaptureFocusChangedEventArgs :
    Windows::Media::Capture::IMediaCaptureFocusChangedEventArgs
{
    MediaCaptureFocusChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaCaptureInitializationSettings :
    Windows::Media::Capture::IMediaCaptureInitializationSettings,
    impl::require<MediaCaptureInitializationSettings, Windows::Media::Capture::IMediaCaptureInitializationSettings2, Windows::Media::Capture::IMediaCaptureInitializationSettings3, Windows::Media::Capture::IMediaCaptureInitializationSettings4, Windows::Media::Capture::IMediaCaptureInitializationSettings5>
{
    MediaCaptureInitializationSettings(std::nullptr_t) noexcept {}
    MediaCaptureInitializationSettings();
};

struct WINRT_EBO MediaCapturePauseResult :
    Windows::Media::Capture::IMediaCapturePauseResult,
    impl::require<MediaCapturePauseResult, Windows::Foundation::IClosable>
{
    MediaCapturePauseResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaCaptureSettings :
    Windows::Media::Capture::IMediaCaptureSettings,
    impl::require<MediaCaptureSettings, Windows::Media::Capture::IMediaCaptureSettings2>
{
    MediaCaptureSettings(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaCaptureStopResult :
    Windows::Media::Capture::IMediaCaptureStopResult,
    impl::require<MediaCaptureStopResult, Windows::Foundation::IClosable>
{
    MediaCaptureStopResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaCaptureVideoProfile :
    Windows::Media::Capture::IMediaCaptureVideoProfile
{
    MediaCaptureVideoProfile(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaCaptureVideoProfileMediaDescription :
    Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription
{
    MediaCaptureVideoProfileMediaDescription(std::nullptr_t) noexcept {}
};

struct WINRT_EBO OptionalReferencePhotoCapturedEventArgs :
    Windows::Media::Capture::IOptionalReferencePhotoCapturedEventArgs
{
    OptionalReferencePhotoCapturedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PhotoCapturedEventArgs :
    Windows::Media::Capture::IPhotoCapturedEventArgs
{
    PhotoCapturedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PhotoConfirmationCapturedEventArgs :
    Windows::Media::Capture::IPhotoConfirmationCapturedEventArgs
{
    PhotoConfirmationCapturedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ScreenCapture :
    Windows::Media::Capture::IScreenCapture
{
    ScreenCapture(std::nullptr_t) noexcept {}
    static Windows::Media::Capture::ScreenCapture GetForCurrentView();
};

struct WINRT_EBO SourceSuspensionChangedEventArgs :
    Windows::Media::Capture::ISourceSuspensionChangedEventArgs
{
    SourceSuspensionChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VideoStreamConfiguration :
    Windows::Media::Capture::IVideoStreamConfiguration
{
    VideoStreamConfiguration(std::nullptr_t) noexcept {}
};

}

}
