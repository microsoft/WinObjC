// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Media.3.h"
#include "internal/Windows.Media.Core.3.h"
#include "internal/Windows.Media.Capture.Frames.3.h"
#include "internal/Windows.Media.MediaProperties.3.h"
#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Media.Devices.3.h"
#include "internal/Windows.Media.Effects.3.h"
#include "internal/Windows.Graphics.Imaging.3.h"
#include "internal/Windows.System.3.h"
#include "internal/Windows.Media.Capture.3.h"
#include "Windows.Media.h"
#include "Windows.Foundation.h"
#include "Windows.Storage.Streams.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Media::Capture {

template <typename L> MediaCaptureFailedEventHandler::MediaCaptureFailedEventHandler(L lambda) :
    MediaCaptureFailedEventHandler(impl::make_delegate<impl_MediaCaptureFailedEventHandler<L>, MediaCaptureFailedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> MediaCaptureFailedEventHandler::MediaCaptureFailedEventHandler(F * function) :
    MediaCaptureFailedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> MediaCaptureFailedEventHandler::MediaCaptureFailedEventHandler(O * object, M method) :
    MediaCaptureFailedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void MediaCaptureFailedEventHandler::operator()(const Windows::Media::Capture::MediaCapture & sender, const Windows::Media::Capture::MediaCaptureFailedEventArgs & errorEventArgs) const
{
    check_hresult((*(abi<MediaCaptureFailedEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(errorEventArgs)));
}

template <typename L> RecordLimitationExceededEventHandler::RecordLimitationExceededEventHandler(L lambda) :
    RecordLimitationExceededEventHandler(impl::make_delegate<impl_RecordLimitationExceededEventHandler<L>, RecordLimitationExceededEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> RecordLimitationExceededEventHandler::RecordLimitationExceededEventHandler(F * function) :
    RecordLimitationExceededEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> RecordLimitationExceededEventHandler::RecordLimitationExceededEventHandler(O * object, M method) :
    RecordLimitationExceededEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void RecordLimitationExceededEventHandler::operator()(const Windows::Media::Capture::MediaCapture & sender) const
{
    check_hresult((*(abi<RecordLimitationExceededEventHandler> **)this)->abi_Invoke(get_abi(sender)));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::Media::Capture::IAdvancedCapturedPhoto> : produce_base<D, Windows::Media::Capture::IAdvancedCapturedPhoto>
{
    HRESULT __stdcall get_Frame(impl::abi_arg_out<Windows::Media::Capture::ICapturedFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Frame());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Mode(Windows::Media::Devices::AdvancedPhotoMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Mode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Context(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Context());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IAdvancedCapturedPhoto2> : produce_base<D, Windows::Media::Capture::IAdvancedCapturedPhoto2>
{
    HRESULT __stdcall get_FrameBoundsRelativeToReferencePhoto(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::Rect>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrameBoundsRelativeToReferencePhoto());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IAdvancedPhotoCapture> : produce_base<D, Windows::Media::Capture::IAdvancedPhotoCapture>
{
    HRESULT __stdcall abi_CaptureAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::AdvancedCapturedPhoto>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CaptureAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CaptureWithContextAsync(impl::abi_arg_in<Windows::Foundation::IInspectable> context, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::AdvancedCapturedPhoto>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CaptureAsync(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&context)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_OptionalReferencePhotoCaptured(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AdvancedPhotoCapture, Windows::Media::Capture::OptionalReferencePhotoCapturedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().OptionalReferencePhotoCaptured(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AdvancedPhotoCapture, Windows::Media::Capture::OptionalReferencePhotoCapturedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_OptionalReferencePhotoCaptured(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OptionalReferencePhotoCaptured(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_AllPhotosCaptured(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AdvancedPhotoCapture, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().AllPhotosCaptured(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AdvancedPhotoCapture, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AllPhotosCaptured(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllPhotosCaptured(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FinishAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FinishAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IAppCapture> : produce_base<D, Windows::Media::Capture::IAppCapture>
{
    HRESULT __stdcall get_IsCapturingAudio(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCapturingAudio());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsCapturingVideo(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCapturingVideo());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CapturingChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AppCapture, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().CapturingChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AppCapture, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CapturingChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CapturingChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IAppCaptureAlternateShortcutKeys> : produce_base<D, Windows::Media::Capture::IAppCaptureAlternateShortcutKeys>
{
    HRESULT __stdcall put_ToggleGameBarKey(Windows::System::VirtualKey value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ToggleGameBarKey(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ToggleGameBarKey(Windows::System::VirtualKey * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ToggleGameBarKey());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ToggleGameBarKeyModifiers(Windows::System::VirtualKeyModifiers value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ToggleGameBarKeyModifiers(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ToggleGameBarKeyModifiers(Windows::System::VirtualKeyModifiers * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ToggleGameBarKeyModifiers());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SaveHistoricalVideoKey(Windows::System::VirtualKey value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SaveHistoricalVideoKey(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SaveHistoricalVideoKey(Windows::System::VirtualKey * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SaveHistoricalVideoKey());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SaveHistoricalVideoKeyModifiers(Windows::System::VirtualKeyModifiers value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SaveHistoricalVideoKeyModifiers(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SaveHistoricalVideoKeyModifiers(Windows::System::VirtualKeyModifiers * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SaveHistoricalVideoKeyModifiers());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ToggleRecordingKey(Windows::System::VirtualKey value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ToggleRecordingKey(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ToggleRecordingKey(Windows::System::VirtualKey * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ToggleRecordingKey());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ToggleRecordingKeyModifiers(Windows::System::VirtualKeyModifiers value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ToggleRecordingKeyModifiers(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ToggleRecordingKeyModifiers(Windows::System::VirtualKeyModifiers * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ToggleRecordingKeyModifiers());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TakeScreenshotKey(Windows::System::VirtualKey value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TakeScreenshotKey(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TakeScreenshotKey(Windows::System::VirtualKey * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TakeScreenshotKey());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TakeScreenshotKeyModifiers(Windows::System::VirtualKeyModifiers value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TakeScreenshotKeyModifiers(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TakeScreenshotKeyModifiers(Windows::System::VirtualKeyModifiers * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TakeScreenshotKeyModifiers());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ToggleRecordingIndicatorKey(Windows::System::VirtualKey value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ToggleRecordingIndicatorKey(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ToggleRecordingIndicatorKey(Windows::System::VirtualKey * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ToggleRecordingIndicatorKey());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ToggleRecordingIndicatorKeyModifiers(Windows::System::VirtualKeyModifiers value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ToggleRecordingIndicatorKeyModifiers(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ToggleRecordingIndicatorKeyModifiers(Windows::System::VirtualKeyModifiers * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ToggleRecordingIndicatorKeyModifiers());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IAppCaptureAlternateShortcutKeys2> : produce_base<D, Windows::Media::Capture::IAppCaptureAlternateShortcutKeys2>
{
    HRESULT __stdcall put_ToggleMicrophoneCaptureKey(Windows::System::VirtualKey value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ToggleMicrophoneCaptureKey(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ToggleMicrophoneCaptureKey(Windows::System::VirtualKey * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ToggleMicrophoneCaptureKey());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ToggleMicrophoneCaptureKeyModifiers(Windows::System::VirtualKeyModifiers value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ToggleMicrophoneCaptureKeyModifiers(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ToggleMicrophoneCaptureKeyModifiers(Windows::System::VirtualKeyModifiers * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ToggleMicrophoneCaptureKeyModifiers());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IAppCaptureAlternateShortcutKeys3> : produce_base<D, Windows::Media::Capture::IAppCaptureAlternateShortcutKeys3>
{
    HRESULT __stdcall put_ToggleCameraCaptureKey(Windows::System::VirtualKey value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ToggleCameraCaptureKey(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ToggleCameraCaptureKey(Windows::System::VirtualKey * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ToggleCameraCaptureKey());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ToggleCameraCaptureKeyModifiers(Windows::System::VirtualKeyModifiers value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ToggleCameraCaptureKeyModifiers(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ToggleCameraCaptureKeyModifiers(Windows::System::VirtualKeyModifiers * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ToggleCameraCaptureKeyModifiers());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ToggleBroadcastKey(Windows::System::VirtualKey value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ToggleBroadcastKey(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ToggleBroadcastKey(Windows::System::VirtualKey * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ToggleBroadcastKey());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ToggleBroadcastKeyModifiers(Windows::System::VirtualKeyModifiers value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ToggleBroadcastKeyModifiers(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ToggleBroadcastKeyModifiers(Windows::System::VirtualKeyModifiers * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ToggleBroadcastKeyModifiers());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IAppCaptureManagerStatics> : produce_base<D, Windows::Media::Capture::IAppCaptureManagerStatics>
{
    HRESULT __stdcall abi_GetCurrentSettings(impl::abi_arg_out<Windows::Media::Capture::IAppCaptureSettings> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetCurrentSettings());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ApplySettings(impl::abi_arg_in<Windows::Media::Capture::IAppCaptureSettings> appCaptureSettings) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ApplySettings(*reinterpret_cast<const Windows::Media::Capture::AppCaptureSettings *>(&appCaptureSettings));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IAppCaptureSettings> : produce_base<D, Windows::Media::Capture::IAppCaptureSettings>
{
    HRESULT __stdcall put_AppCaptureDestinationFolder(impl::abi_arg_in<Windows::Storage::IStorageFolder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppCaptureDestinationFolder(*reinterpret_cast<const Windows::Storage::StorageFolder *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AppCaptureDestinationFolder(impl::abi_arg_out<Windows::Storage::IStorageFolder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppCaptureDestinationFolder());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AudioEncodingBitrate(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioEncodingBitrate(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AudioEncodingBitrate(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AudioEncodingBitrate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsAudioCaptureEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsAudioCaptureEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsAudioCaptureEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsAudioCaptureEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CustomVideoEncodingBitrate(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CustomVideoEncodingBitrate(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CustomVideoEncodingBitrate(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CustomVideoEncodingBitrate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CustomVideoEncodingHeight(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CustomVideoEncodingHeight(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CustomVideoEncodingHeight(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CustomVideoEncodingHeight());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CustomVideoEncodingWidth(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CustomVideoEncodingWidth(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CustomVideoEncodingWidth(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CustomVideoEncodingWidth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_HistoricalBufferLength(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HistoricalBufferLength(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HistoricalBufferLength(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HistoricalBufferLength());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_HistoricalBufferLengthUnit(Windows::Media::Capture::AppCaptureHistoricalBufferLengthUnit value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HistoricalBufferLengthUnit(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HistoricalBufferLengthUnit(Windows::Media::Capture::AppCaptureHistoricalBufferLengthUnit * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HistoricalBufferLengthUnit());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsHistoricalCaptureEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsHistoricalCaptureEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsHistoricalCaptureEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsHistoricalCaptureEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsHistoricalCaptureOnBatteryAllowed(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsHistoricalCaptureOnBatteryAllowed(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsHistoricalCaptureOnBatteryAllowed(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsHistoricalCaptureOnBatteryAllowed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsHistoricalCaptureOnWirelessDisplayAllowed(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsHistoricalCaptureOnWirelessDisplayAllowed(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsHistoricalCaptureOnWirelessDisplayAllowed(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsHistoricalCaptureOnWirelessDisplayAllowed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaximumRecordLength(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaximumRecordLength(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaximumRecordLength(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaximumRecordLength());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ScreenshotDestinationFolder(impl::abi_arg_in<Windows::Storage::IStorageFolder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ScreenshotDestinationFolder(*reinterpret_cast<const Windows::Storage::StorageFolder *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ScreenshotDestinationFolder(impl::abi_arg_out<Windows::Storage::IStorageFolder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScreenshotDestinationFolder());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_VideoEncodingBitrateMode(Windows::Media::Capture::AppCaptureVideoEncodingBitrateMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VideoEncodingBitrateMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoEncodingBitrateMode(Windows::Media::Capture::AppCaptureVideoEncodingBitrateMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoEncodingBitrateMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_VideoEncodingResolutionMode(Windows::Media::Capture::AppCaptureVideoEncodingResolutionMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VideoEncodingResolutionMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoEncodingResolutionMode(Windows::Media::Capture::AppCaptureVideoEncodingResolutionMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoEncodingResolutionMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsAppCaptureEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsAppCaptureEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsAppCaptureEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsAppCaptureEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsCpuConstrained(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCpuConstrained());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDisabledByPolicy(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDisabledByPolicy());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsMemoryConstrained(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsMemoryConstrained());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HasHardwareEncoder(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasHardwareEncoder());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IAppCaptureSettings2> : produce_base<D, Windows::Media::Capture::IAppCaptureSettings2>
{
    HRESULT __stdcall get_IsGpuConstrained(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsGpuConstrained());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AlternateShortcutKeys(impl::abi_arg_out<Windows::Media::Capture::IAppCaptureAlternateShortcutKeys> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AlternateShortcutKeys());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IAppCaptureSettings3> : produce_base<D, Windows::Media::Capture::IAppCaptureSettings3>
{
    HRESULT __stdcall put_IsMicrophoneCaptureEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsMicrophoneCaptureEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsMicrophoneCaptureEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsMicrophoneCaptureEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IAppCaptureSettings4> : produce_base<D, Windows::Media::Capture::IAppCaptureSettings4>
{
    HRESULT __stdcall put_IsMicrophoneCaptureEnabledByDefault(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsMicrophoneCaptureEnabledByDefault(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsMicrophoneCaptureEnabledByDefault(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsMicrophoneCaptureEnabledByDefault());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SystemAudioGain(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SystemAudioGain(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SystemAudioGain(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SystemAudioGain());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MicrophoneGain(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MicrophoneGain(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MicrophoneGain(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MicrophoneGain());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_VideoEncodingFrameRateMode(Windows::Media::Capture::AppCaptureVideoEncodingFrameRateMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VideoEncodingFrameRateMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoEncodingFrameRateMode(Windows::Media::Capture::AppCaptureVideoEncodingFrameRateMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoEncodingFrameRateMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IAppCaptureStatics> : produce_base<D, Windows::Media::Capture::IAppCaptureStatics>
{
    HRESULT __stdcall abi_GetForCurrentView(impl::abi_arg_out<Windows::Media::Capture::IAppCapture> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetForCurrentView());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::ICameraCaptureUI> : produce_base<D, Windows::Media::Capture::ICameraCaptureUI>
{
    HRESULT __stdcall get_PhotoSettings(impl::abi_arg_out<Windows::Media::Capture::ICameraCaptureUIPhotoCaptureSettings> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PhotoSettings());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoSettings(impl::abi_arg_out<Windows::Media::Capture::ICameraCaptureUIVideoCaptureSettings> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoSettings());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CaptureFileAsync(Windows::Media::Capture::CameraCaptureUIMode mode, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().CaptureFileAsync(mode));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::ICameraCaptureUIPhotoCaptureSettings> : produce_base<D, Windows::Media::Capture::ICameraCaptureUIPhotoCaptureSettings>
{
    HRESULT __stdcall get_Format(Windows::Media::Capture::CameraCaptureUIPhotoFormat * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Format());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Format(Windows::Media::Capture::CameraCaptureUIPhotoFormat value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Format(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxResolution(Windows::Media::Capture::CameraCaptureUIMaxPhotoResolution * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxResolution());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxResolution(Windows::Media::Capture::CameraCaptureUIMaxPhotoResolution value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxResolution(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CroppedSizeInPixels(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CroppedSizeInPixels());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CroppedSizeInPixels(impl::abi_arg_in<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CroppedSizeInPixels(*reinterpret_cast<const Windows::Foundation::Size *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CroppedAspectRatio(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CroppedAspectRatio());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CroppedAspectRatio(impl::abi_arg_in<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CroppedAspectRatio(*reinterpret_cast<const Windows::Foundation::Size *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AllowCropping(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowCropping());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AllowCropping(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowCropping(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::ICameraCaptureUIVideoCaptureSettings> : produce_base<D, Windows::Media::Capture::ICameraCaptureUIVideoCaptureSettings>
{
    HRESULT __stdcall get_Format(Windows::Media::Capture::CameraCaptureUIVideoFormat * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Format());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Format(Windows::Media::Capture::CameraCaptureUIVideoFormat value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Format(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxResolution(Windows::Media::Capture::CameraCaptureUIMaxVideoResolution * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxResolution());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxResolution(Windows::Media::Capture::CameraCaptureUIMaxVideoResolution value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxResolution(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxDurationInSeconds(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxDurationInSeconds());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxDurationInSeconds(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxDurationInSeconds(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AllowTrimming(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowTrimming());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AllowTrimming(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowTrimming(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::ICameraOptionsUIStatics> : produce_base<D, Windows::Media::Capture::ICameraOptionsUIStatics>
{
    HRESULT __stdcall abi_Show(impl::abi_arg_in<Windows::Media::Capture::IMediaCapture> mediaCapture) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Show(*reinterpret_cast<const Windows::Media::Capture::MediaCapture *>(&mediaCapture));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::ICapturedFrame> : produce_base<D, Windows::Media::Capture::ICapturedFrame>
{
    HRESULT __stdcall get_Width(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Width());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Height(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Height());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::ICapturedFrameControlValues> : produce_base<D, Windows::Media::Capture::ICapturedFrameControlValues>
{
    HRESULT __stdcall get_Exposure(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Exposure());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExposureCompensation(impl::abi_arg_out<Windows::Foundation::IReference<float>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExposureCompensation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsoSpeed(impl::abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsoSpeed());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Focus(impl::abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Focus());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SceneMode(impl::abi_arg_out<Windows::Foundation::IReference<winrt::Windows::Media::Devices::CaptureSceneMode>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SceneMode());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Flashed(impl::abi_arg_out<Windows::Foundation::IReference<bool>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Flashed());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FlashPowerPercent(impl::abi_arg_out<Windows::Foundation::IReference<float>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FlashPowerPercent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WhiteBalance(impl::abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WhiteBalance());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZoomFactor(impl::abi_arg_out<Windows::Foundation::IReference<float>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ZoomFactor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::ICapturedFrameControlValues2> : produce_base<D, Windows::Media::Capture::ICapturedFrameControlValues2>
{
    HRESULT __stdcall get_FocusState(impl::abi_arg_out<Windows::Foundation::IReference<winrt::Windows::Media::Devices::MediaCaptureFocusState>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FocusState());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsoDigitalGain(impl::abi_arg_out<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsoDigitalGain());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsoAnalogGain(impl::abi_arg_out<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsoAnalogGain());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SensorFrameRate(impl::abi_arg_out<Windows::Media::MediaProperties::IMediaRatio> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SensorFrameRate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WhiteBalanceGain(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Media::Capture::WhiteBalanceGain>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WhiteBalanceGain());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::ICapturedFrameWithSoftwareBitmap> : produce_base<D, Windows::Media::Capture::ICapturedFrameWithSoftwareBitmap>
{
    HRESULT __stdcall get_SoftwareBitmap(impl::abi_arg_out<Windows::Graphics::Imaging::ISoftwareBitmap> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SoftwareBitmap());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::ICapturedPhoto> : produce_base<D, Windows::Media::Capture::ICapturedPhoto>
{
    HRESULT __stdcall get_Frame(impl::abi_arg_out<Windows::Media::Capture::ICapturedFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Frame());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Thumbnail(impl::abi_arg_out<Windows::Media::Capture::ICapturedFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Thumbnail());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::ILowLagMediaRecording> : produce_base<D, Windows::Media::Capture::ILowLagMediaRecording>
{
    HRESULT __stdcall abi_StartAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().StartAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().StopAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FinishAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FinishAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::ILowLagMediaRecording2> : produce_base<D, Windows::Media::Capture::ILowLagMediaRecording2>
{
    HRESULT __stdcall abi_PauseAsync(Windows::Media::Devices::MediaCapturePauseBehavior behavior, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().PauseAsync(behavior));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ResumeAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ResumeAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::ILowLagMediaRecording3> : produce_base<D, Windows::Media::Capture::ILowLagMediaRecording3>
{
    HRESULT __stdcall abi_PauseWithResultAsync(Windows::Media::Devices::MediaCapturePauseBehavior behavior, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCapturePauseResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().PauseWithResultAsync(behavior));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopWithResultAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCaptureStopResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().StopWithResultAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::ILowLagPhotoCapture> : produce_base<D, Windows::Media::Capture::ILowLagPhotoCapture>
{
    HRESULT __stdcall abi_CaptureAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::CapturedPhoto>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CaptureAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FinishAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FinishAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::ILowLagPhotoSequenceCapture> : produce_base<D, Windows::Media::Capture::ILowLagPhotoSequenceCapture>
{
    HRESULT __stdcall abi_StartAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().StartAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().StopAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FinishAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FinishAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PhotoCaptured(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Capture::LowLagPhotoSequenceCapture, Windows::Media::Capture::PhotoCapturedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PhotoCaptured(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::LowLagPhotoSequenceCapture, Windows::Media::Capture::PhotoCapturedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PhotoCaptured(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PhotoCaptured(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCapture> : produce_base<D, Windows::Media::Capture::IMediaCapture>
{
    HRESULT __stdcall abi_InitializeAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().InitializeAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InitializeWithSettingsAsync(impl::abi_arg_in<Windows::Media::Capture::IMediaCaptureInitializationSettings> mediaCaptureInitializationSettings, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().InitializeAsync(*reinterpret_cast<const Windows::Media::Capture::MediaCaptureInitializationSettings *>(&mediaCaptureInitializationSettings)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartRecordToStorageFileAsync(impl::abi_arg_in<Windows::Media::MediaProperties::IMediaEncodingProfile> encodingProfile, impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().StartRecordToStorageFileAsync(*reinterpret_cast<const Windows::Media::MediaProperties::MediaEncodingProfile *>(&encodingProfile), *reinterpret_cast<const Windows::Storage::IStorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartRecordToStreamAsync(impl::abi_arg_in<Windows::Media::MediaProperties::IMediaEncodingProfile> encodingProfile, impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> stream, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().StartRecordToStreamAsync(*reinterpret_cast<const Windows::Media::MediaProperties::MediaEncodingProfile *>(&encodingProfile), *reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&stream)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartRecordToCustomSinkAsync(impl::abi_arg_in<Windows::Media::MediaProperties::IMediaEncodingProfile> encodingProfile, impl::abi_arg_in<Windows::Media::IMediaExtension> customMediaSink, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().StartRecordToCustomSinkAsync(*reinterpret_cast<const Windows::Media::MediaProperties::MediaEncodingProfile *>(&encodingProfile), *reinterpret_cast<const Windows::Media::IMediaExtension *>(&customMediaSink)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartRecordToCustomSinkIdAsync(impl::abi_arg_in<Windows::Media::MediaProperties::IMediaEncodingProfile> encodingProfile, impl::abi_arg_in<hstring> customSinkActivationId, impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> customSinkSettings, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().StartRecordToCustomSinkAsync(*reinterpret_cast<const Windows::Media::MediaProperties::MediaEncodingProfile *>(&encodingProfile), *reinterpret_cast<const hstring *>(&customSinkActivationId), *reinterpret_cast<const Windows::Foundation::Collections::IPropertySet *>(&customSinkSettings)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopRecordAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().StopRecordAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CapturePhotoToStorageFileAsync(impl::abi_arg_in<Windows::Media::MediaProperties::IImageEncodingProperties> type, impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().CapturePhotoToStorageFileAsync(*reinterpret_cast<const Windows::Media::MediaProperties::ImageEncodingProperties *>(&type), *reinterpret_cast<const Windows::Storage::IStorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CapturePhotoToStreamAsync(impl::abi_arg_in<Windows::Media::MediaProperties::IImageEncodingProperties> type, impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> stream, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().CapturePhotoToStreamAsync(*reinterpret_cast<const Windows::Media::MediaProperties::ImageEncodingProperties *>(&type), *reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&stream)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddEffectAsync(Windows::Media::Capture::MediaStreamType mediaStreamType, impl::abi_arg_in<hstring> effectActivationID, impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> effectSettings, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().AddEffectAsync(mediaStreamType, *reinterpret_cast<const hstring *>(&effectActivationID), *reinterpret_cast<const Windows::Foundation::Collections::IPropertySet *>(&effectSettings)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClearEffectsAsync(Windows::Media::Capture::MediaStreamType mediaStreamType, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().ClearEffectsAsync(mediaStreamType));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetEncoderProperty(Windows::Media::Capture::MediaStreamType mediaStreamType, GUID propertyId, impl::abi_arg_in<Windows::Foundation::IInspectable> propertyValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetEncoderProperty(mediaStreamType, propertyId, *reinterpret_cast<const Windows::Foundation::IInspectable *>(&propertyValue));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetEncoderProperty(Windows::Media::Capture::MediaStreamType mediaStreamType, GUID propertyId, impl::abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_abi(this->shim().GetEncoderProperty(mediaStreamType, propertyId));
            return S_OK;
        }
        catch (...)
        {
            *propertyValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Failed(impl::abi_arg_in<Windows::Media::Capture::MediaCaptureFailedEventHandler> errorEventHandler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().Failed(*reinterpret_cast<const Windows::Media::Capture::MediaCaptureFailedEventHandler *>(&errorEventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Failed(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Failed(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_RecordLimitationExceeded(impl::abi_arg_in<Windows::Media::Capture::RecordLimitationExceededEventHandler> recordLimitationExceededEventHandler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().RecordLimitationExceeded(*reinterpret_cast<const Windows::Media::Capture::RecordLimitationExceededEventHandler *>(&recordLimitationExceededEventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_RecordLimitationExceeded(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RecordLimitationExceeded(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MediaCaptureSettings(impl::abi_arg_out<Windows::Media::Capture::IMediaCaptureSettings> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MediaCaptureSettings());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AudioDeviceController(impl::abi_arg_out<Windows::Media::Devices::IAudioDeviceController> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AudioDeviceController());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoDeviceController(impl::abi_arg_out<Windows::Media::Devices::IVideoDeviceController> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoDeviceController());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPreviewMirroring(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPreviewMirroring(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPreviewMirroring(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetPreviewMirroring());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPreviewRotation(Windows::Media::Capture::VideoRotation value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPreviewRotation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPreviewRotation(Windows::Media::Capture::VideoRotation * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetPreviewRotation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetRecordRotation(Windows::Media::Capture::VideoRotation value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetRecordRotation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetRecordRotation(Windows::Media::Capture::VideoRotation * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetRecordRotation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCapture2> : produce_base<D, Windows::Media::Capture::IMediaCapture2>
{
    HRESULT __stdcall abi_PrepareLowLagRecordToStorageFileAsync(impl::abi_arg_in<Windows::Media::MediaProperties::IMediaEncodingProfile> encodingProfile, impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().PrepareLowLagRecordToStorageFileAsync(*reinterpret_cast<const Windows::Media::MediaProperties::MediaEncodingProfile *>(&encodingProfile), *reinterpret_cast<const Windows::Storage::IStorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PrepareLowLagRecordToStreamAsync(impl::abi_arg_in<Windows::Media::MediaProperties::IMediaEncodingProfile> encodingProfile, impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> stream, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().PrepareLowLagRecordToStreamAsync(*reinterpret_cast<const Windows::Media::MediaProperties::MediaEncodingProfile *>(&encodingProfile), *reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&stream)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PrepareLowLagRecordToCustomSinkAsync(impl::abi_arg_in<Windows::Media::MediaProperties::IMediaEncodingProfile> encodingProfile, impl::abi_arg_in<Windows::Media::IMediaExtension> customMediaSink, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().PrepareLowLagRecordToCustomSinkAsync(*reinterpret_cast<const Windows::Media::MediaProperties::MediaEncodingProfile *>(&encodingProfile), *reinterpret_cast<const Windows::Media::IMediaExtension *>(&customMediaSink)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PrepareLowLagRecordToCustomSinkIdAsync(impl::abi_arg_in<Windows::Media::MediaProperties::IMediaEncodingProfile> encodingProfile, impl::abi_arg_in<hstring> customSinkActivationId, impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> customSinkSettings, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().PrepareLowLagRecordToCustomSinkAsync(*reinterpret_cast<const Windows::Media::MediaProperties::MediaEncodingProfile *>(&encodingProfile), *reinterpret_cast<const hstring *>(&customSinkActivationId), *reinterpret_cast<const Windows::Foundation::Collections::IPropertySet *>(&customSinkSettings)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PrepareLowLagPhotoCaptureAsync(impl::abi_arg_in<Windows::Media::MediaProperties::IImageEncodingProperties> type, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagPhotoCapture>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().PrepareLowLagPhotoCaptureAsync(*reinterpret_cast<const Windows::Media::MediaProperties::ImageEncodingProperties *>(&type)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PrepareLowLagPhotoSequenceCaptureAsync(impl::abi_arg_in<Windows::Media::MediaProperties::IImageEncodingProperties> type, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagPhotoSequenceCapture>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().PrepareLowLagPhotoSequenceCaptureAsync(*reinterpret_cast<const Windows::Media::MediaProperties::ImageEncodingProperties *>(&type)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetEncodingPropertiesAsync(Windows::Media::Capture::MediaStreamType mediaStreamType, impl::abi_arg_in<Windows::Media::MediaProperties::IMediaEncodingProperties> mediaEncodingProperties, impl::abi_arg_in<Windows::Foundation::Collections::IMap<GUID, Windows::Foundation::IInspectable>> encoderProperties, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SetEncodingPropertiesAsync(mediaStreamType, *reinterpret_cast<const Windows::Media::MediaProperties::IMediaEncodingProperties *>(&mediaEncodingProperties), *reinterpret_cast<const Windows::Media::MediaProperties::MediaPropertySet *>(&encoderProperties)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCapture3> : produce_base<D, Windows::Media::Capture::IMediaCapture3>
{
    HRESULT __stdcall abi_PrepareVariablePhotoSequenceCaptureAsync(impl::abi_arg_in<Windows::Media::MediaProperties::IImageEncodingProperties> type, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Core::VariablePhotoSequenceCapture>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().PrepareVariablePhotoSequenceCaptureAsync(*reinterpret_cast<const Windows::Media::MediaProperties::ImageEncodingProperties *>(&type)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_FocusChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Media::Capture::MediaCaptureFocusChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().FocusChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Media::Capture::MediaCaptureFocusChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_FocusChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FocusChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PhotoConfirmationCaptured(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Media::Capture::PhotoConfirmationCapturedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PhotoConfirmationCaptured(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Media::Capture::PhotoConfirmationCapturedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PhotoConfirmationCaptured(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PhotoConfirmationCaptured(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCapture4> : produce_base<D, Windows::Media::Capture::IMediaCapture4>
{
    HRESULT __stdcall abi_AddAudioEffectAsync(impl::abi_arg_in<Windows::Media::Effects::IAudioEffectDefinition> definition, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::IMediaExtension>> op) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *op = detach_abi(this->shim().AddAudioEffectAsync(*reinterpret_cast<const Windows::Media::Effects::IAudioEffectDefinition *>(&definition)));
            return S_OK;
        }
        catch (...)
        {
            *op = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddVideoEffectAsync(impl::abi_arg_in<Windows::Media::Effects::IVideoEffectDefinition> definition, Windows::Media::Capture::MediaStreamType mediaStreamType, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::IMediaExtension>> op) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *op = detach_abi(this->shim().AddVideoEffectAsync(*reinterpret_cast<const Windows::Media::Effects::IVideoEffectDefinition *>(&definition), mediaStreamType));
            return S_OK;
        }
        catch (...)
        {
            *op = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PauseRecordAsync(Windows::Media::Devices::MediaCapturePauseBehavior behavior, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().PauseRecordAsync(behavior));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ResumeRecordAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().ResumeRecordAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CameraStreamStateChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().CameraStreamStateChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CameraStreamStateChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CameraStreamStateChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CameraStreamState(Windows::Media::Devices::CameraStreamState * streamState) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *streamState = detach_abi(this->shim().CameraStreamState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPreviewFrameAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::VideoFrame>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetPreviewFrameAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPreviewFrameCopyAsync(impl::abi_arg_in<Windows::Media::IVideoFrame> destination, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::VideoFrame>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetPreviewFrameAsync(*reinterpret_cast<const Windows::Media::VideoFrame *>(&destination)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ThermalStatusChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ThermalStatusChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ThermalStatusChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ThermalStatusChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ThermalStatus(Windows::Media::Capture::MediaCaptureThermalStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ThermalStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PrepareAdvancedPhotoCaptureAsync(impl::abi_arg_in<Windows::Media::MediaProperties::IImageEncodingProperties> encodingProperties, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::AdvancedPhotoCapture>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().PrepareAdvancedPhotoCaptureAsync(*reinterpret_cast<const Windows::Media::MediaProperties::ImageEncodingProperties *>(&encodingProperties)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCapture5> : produce_base<D, Windows::Media::Capture::IMediaCapture5>
{
    HRESULT __stdcall abi_RemoveEffectAsync(impl::abi_arg_in<Windows::Media::IMediaExtension> effect, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().RemoveEffectAsync(*reinterpret_cast<const Windows::Media::IMediaExtension *>(&effect)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PauseRecordWithResultAsync(Windows::Media::Devices::MediaCapturePauseBehavior behavior, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCapturePauseResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().PauseRecordWithResultAsync(behavior));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopRecordWithResultAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCaptureStopResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().StopRecordWithResultAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FrameSources(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::Media::Capture::Frames::MediaFrameSource>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrameSources());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFrameReaderAsync(impl::abi_arg_in<Windows::Media::Capture::Frames::IMediaFrameSource> inputSource, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameReader>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateFrameReaderAsync(*reinterpret_cast<const Windows::Media::Capture::Frames::MediaFrameSource *>(&inputSource)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFrameReaderWithSubtypeAsync(impl::abi_arg_in<Windows::Media::Capture::Frames::IMediaFrameSource> inputSource, impl::abi_arg_in<hstring> outputSubtype, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameReader>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateFrameReaderAsync(*reinterpret_cast<const Windows::Media::Capture::Frames::MediaFrameSource *>(&inputSource), *reinterpret_cast<const hstring *>(&outputSubtype)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFrameReaderWithSubtypeAndSizeAsync(impl::abi_arg_in<Windows::Media::Capture::Frames::IMediaFrameSource> inputSource, impl::abi_arg_in<hstring> outputSubtype, impl::abi_arg_in<Windows::Graphics::Imaging::BitmapSize> outputSize, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameReader>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateFrameReaderAsync(*reinterpret_cast<const Windows::Media::Capture::Frames::MediaFrameSource *>(&inputSource), *reinterpret_cast<const hstring *>(&outputSubtype), *reinterpret_cast<const Windows::Graphics::Imaging::BitmapSize *>(&outputSize)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCaptureFailedEventArgs> : produce_base<D, Windows::Media::Capture::IMediaCaptureFailedEventArgs>
{
    HRESULT __stdcall get_Message(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Message());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Code(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Code());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCaptureFocusChangedEventArgs> : produce_base<D, Windows::Media::Capture::IMediaCaptureFocusChangedEventArgs>
{
    HRESULT __stdcall get_FocusState(Windows::Media::Devices::MediaCaptureFocusState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FocusState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCaptureInitializationSettings> : produce_base<D, Windows::Media::Capture::IMediaCaptureInitializationSettings>
{
    HRESULT __stdcall put_AudioDeviceId(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioDeviceId(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AudioDeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AudioDeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_VideoDeviceId(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VideoDeviceId(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoDeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoDeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StreamingCaptureMode(Windows::Media::Capture::StreamingCaptureMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StreamingCaptureMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StreamingCaptureMode(Windows::Media::Capture::StreamingCaptureMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StreamingCaptureMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PhotoCaptureSource(Windows::Media::Capture::PhotoCaptureSource value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PhotoCaptureSource(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PhotoCaptureSource(Windows::Media::Capture::PhotoCaptureSource * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PhotoCaptureSource());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCaptureInitializationSettings2> : produce_base<D, Windows::Media::Capture::IMediaCaptureInitializationSettings2>
{
    HRESULT __stdcall put_MediaCategory(Windows::Media::Capture::MediaCategory value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MediaCategory(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MediaCategory(Windows::Media::Capture::MediaCategory * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MediaCategory());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AudioProcessing(Windows::Media::AudioProcessing value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioProcessing(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AudioProcessing(Windows::Media::AudioProcessing * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AudioProcessing());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCaptureInitializationSettings3> : produce_base<D, Windows::Media::Capture::IMediaCaptureInitializationSettings3>
{
    HRESULT __stdcall put_AudioSource(impl::abi_arg_in<Windows::Media::Core::IMediaSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioSource(*reinterpret_cast<const Windows::Media::Core::IMediaSource *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AudioSource(impl::abi_arg_out<Windows::Media::Core::IMediaSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AudioSource());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_VideoSource(impl::abi_arg_in<Windows::Media::Core::IMediaSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VideoSource(*reinterpret_cast<const Windows::Media::Core::IMediaSource *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoSource(impl::abi_arg_out<Windows::Media::Core::IMediaSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoSource());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCaptureInitializationSettings4> : produce_base<D, Windows::Media::Capture::IMediaCaptureInitializationSettings4>
{
    HRESULT __stdcall get_VideoProfile(impl::abi_arg_out<Windows::Media::Capture::IMediaCaptureVideoProfile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoProfile());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_VideoProfile(impl::abi_arg_in<Windows::Media::Capture::IMediaCaptureVideoProfile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VideoProfile(*reinterpret_cast<const Windows::Media::Capture::MediaCaptureVideoProfile *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PreviewMediaDescription(impl::abi_arg_out<Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PreviewMediaDescription());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PreviewMediaDescription(impl::abi_arg_in<Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PreviewMediaDescription(*reinterpret_cast<const Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RecordMediaDescription(impl::abi_arg_out<Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RecordMediaDescription());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RecordMediaDescription(impl::abi_arg_in<Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RecordMediaDescription(*reinterpret_cast<const Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PhotoMediaDescription(impl::abi_arg_out<Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PhotoMediaDescription());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PhotoMediaDescription(impl::abi_arg_in<Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PhotoMediaDescription(*reinterpret_cast<const Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCaptureInitializationSettings5> : produce_base<D, Windows::Media::Capture::IMediaCaptureInitializationSettings5>
{
    HRESULT __stdcall get_SourceGroup(impl::abi_arg_out<Windows::Media::Capture::Frames::IMediaFrameSourceGroup> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceGroup());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SourceGroup(impl::abi_arg_in<Windows::Media::Capture::Frames::IMediaFrameSourceGroup> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceGroup(*reinterpret_cast<const Windows::Media::Capture::Frames::MediaFrameSourceGroup *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SharingMode(Windows::Media::Capture::MediaCaptureSharingMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SharingMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SharingMode(Windows::Media::Capture::MediaCaptureSharingMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SharingMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MemoryPreference(Windows::Media::Capture::MediaCaptureMemoryPreference * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MemoryPreference());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MemoryPreference(Windows::Media::Capture::MediaCaptureMemoryPreference value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MemoryPreference(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCapturePauseResult> : produce_base<D, Windows::Media::Capture::IMediaCapturePauseResult>
{
    HRESULT __stdcall get_LastFrame(impl::abi_arg_out<Windows::Media::IVideoFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastFrame());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RecordDuration(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RecordDuration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCaptureSettings> : produce_base<D, Windows::Media::Capture::IMediaCaptureSettings>
{
    HRESULT __stdcall get_AudioDeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AudioDeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoDeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoDeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StreamingCaptureMode(Windows::Media::Capture::StreamingCaptureMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StreamingCaptureMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PhotoCaptureSource(Windows::Media::Capture::PhotoCaptureSource * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PhotoCaptureSource());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoDeviceCharacteristic(Windows::Media::Capture::VideoDeviceCharacteristic * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoDeviceCharacteristic());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCaptureSettings2> : produce_base<D, Windows::Media::Capture::IMediaCaptureSettings2>
{
    HRESULT __stdcall get_ConcurrentRecordAndPhotoSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ConcurrentRecordAndPhotoSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ConcurrentRecordAndPhotoSequenceSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ConcurrentRecordAndPhotoSequenceSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CameraSoundRequiredForRegion(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CameraSoundRequiredForRegion());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Horizontal35mmEquivalentFocalLength(impl::abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Horizontal35mmEquivalentFocalLength());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PitchOffsetDegrees(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PitchOffsetDegrees());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Vertical35mmEquivalentFocalLength(impl::abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Vertical35mmEquivalentFocalLength());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MediaCategory(Windows::Media::Capture::MediaCategory * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MediaCategory());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AudioProcessing(Windows::Media::AudioProcessing * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AudioProcessing());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCaptureStatics> : produce_base<D, Windows::Media::Capture::IMediaCaptureStatics>
{
    HRESULT __stdcall abi_IsVideoProfileSupported(impl::abi_arg_in<hstring> videoDeviceId, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsVideoProfileSupported(*reinterpret_cast<const hstring *>(&videoDeviceId)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllVideoProfiles(impl::abi_arg_in<hstring> videoDeviceId, impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FindAllVideoProfiles(*reinterpret_cast<const hstring *>(&videoDeviceId)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindConcurrentProfiles(impl::abi_arg_in<hstring> videoDeviceId, impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FindConcurrentProfiles(*reinterpret_cast<const hstring *>(&videoDeviceId)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindKnownVideoProfiles(impl::abi_arg_in<hstring> videoDeviceId, Windows::Media::Capture::KnownVideoProfile name, impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FindKnownVideoProfiles(*reinterpret_cast<const hstring *>(&videoDeviceId), name));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCaptureStopResult> : produce_base<D, Windows::Media::Capture::IMediaCaptureStopResult>
{
    HRESULT __stdcall get_LastFrame(impl::abi_arg_out<Windows::Media::IVideoFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastFrame());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RecordDuration(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RecordDuration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCaptureVideoPreview> : produce_base<D, Windows::Media::Capture::IMediaCaptureVideoPreview>
{
    HRESULT __stdcall abi_StartPreviewAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().StartPreviewAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartPreviewToCustomSinkAsync(impl::abi_arg_in<Windows::Media::MediaProperties::IMediaEncodingProfile> encodingProfile, impl::abi_arg_in<Windows::Media::IMediaExtension> customMediaSink, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().StartPreviewToCustomSinkAsync(*reinterpret_cast<const Windows::Media::MediaProperties::MediaEncodingProfile *>(&encodingProfile), *reinterpret_cast<const Windows::Media::IMediaExtension *>(&customMediaSink)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartPreviewToCustomSinkIdAsync(impl::abi_arg_in<Windows::Media::MediaProperties::IMediaEncodingProfile> encodingProfile, impl::abi_arg_in<hstring> customSinkActivationId, impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> customSinkSettings, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().StartPreviewToCustomSinkAsync(*reinterpret_cast<const Windows::Media::MediaProperties::MediaEncodingProfile *>(&encodingProfile), *reinterpret_cast<const hstring *>(&customSinkActivationId), *reinterpret_cast<const Windows::Foundation::Collections::IPropertySet *>(&customSinkSettings)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopPreviewAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().StopPreviewAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCaptureVideoProfile> : produce_base<D, Windows::Media::Capture::IMediaCaptureVideoProfile>
{
    HRESULT __stdcall get_Id(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoDeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoDeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedPreviewMediaDescription(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedPreviewMediaDescription());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedRecordMediaDescription(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedRecordMediaDescription());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedPhotoMediaDescription(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedPhotoMediaDescription());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetConcurrency(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetConcurrency());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription> : produce_base<D, Windows::Media::Capture::IMediaCaptureVideoProfileMediaDescription>
{
    HRESULT __stdcall get_Width(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Width());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Height(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Height());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FrameRate(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrameRate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsVariablePhotoSequenceSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsVariablePhotoSequenceSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsHdrVideoSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsHdrVideoSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IOptionalReferencePhotoCapturedEventArgs> : produce_base<D, Windows::Media::Capture::IOptionalReferencePhotoCapturedEventArgs>
{
    HRESULT __stdcall get_Frame(impl::abi_arg_out<Windows::Media::Capture::ICapturedFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Frame());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Context(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Context());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IPhotoCapturedEventArgs> : produce_base<D, Windows::Media::Capture::IPhotoCapturedEventArgs>
{
    HRESULT __stdcall get_Frame(impl::abi_arg_out<Windows::Media::Capture::ICapturedFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Frame());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Thumbnail(impl::abi_arg_out<Windows::Media::Capture::ICapturedFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Thumbnail());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CaptureTimeOffset(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CaptureTimeOffset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IPhotoConfirmationCapturedEventArgs> : produce_base<D, Windows::Media::Capture::IPhotoConfirmationCapturedEventArgs>
{
    HRESULT __stdcall get_Frame(impl::abi_arg_out<Windows::Media::Capture::ICapturedFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Frame());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CaptureTimeOffset(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CaptureTimeOffset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IScreenCapture> : produce_base<D, Windows::Media::Capture::IScreenCapture>
{
    HRESULT __stdcall get_AudioSource(impl::abi_arg_out<Windows::Media::Core::IMediaSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AudioSource());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoSource(impl::abi_arg_out<Windows::Media::Core::IMediaSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoSource());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsAudioSuspended(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsAudioSuspended());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsVideoSuspended(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsVideoSuspended());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SourceSuspensionChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Capture::ScreenCapture, Windows::Media::Capture::SourceSuspensionChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SourceSuspensionChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::ScreenCapture, Windows::Media::Capture::SourceSuspensionChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SourceSuspensionChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceSuspensionChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IScreenCaptureStatics> : produce_base<D, Windows::Media::Capture::IScreenCaptureStatics>
{
    HRESULT __stdcall abi_GetForCurrentView(impl::abi_arg_out<Windows::Media::Capture::IScreenCapture> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetForCurrentView());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::ISourceSuspensionChangedEventArgs> : produce_base<D, Windows::Media::Capture::ISourceSuspensionChangedEventArgs>
{
    HRESULT __stdcall get_IsAudioSuspended(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsAudioSuspended());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsVideoSuspended(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsVideoSuspended());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::IVideoStreamConfiguration> : produce_base<D, Windows::Media::Capture::IVideoStreamConfiguration>
{
    HRESULT __stdcall get_InputProperties(impl::abi_arg_out<Windows::Media::MediaProperties::IVideoEncodingProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InputProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OutputProperties(impl::abi_arg_out<Windows::Media::MediaProperties::IVideoEncodingProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OutputProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Media::Capture {

template <typename D> bool impl_IAppCapture<D>::IsCapturingAudio() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppCapture)->get_IsCapturingAudio(&value));
    return value;
}

template <typename D> bool impl_IAppCapture<D>::IsCapturingVideo() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppCapture)->get_IsCapturingVideo(&value));
    return value;
}

template <typename D> event_token impl_IAppCapture<D>::CapturingChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AppCapture, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IAppCapture)->add_CapturingChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IAppCapture> impl_IAppCapture<D>::CapturingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AppCapture, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IAppCapture>(this, &ABI::Windows::Media::Capture::IAppCapture::remove_CapturingChanged, CapturingChanged(handler));
}

template <typename D> void impl_IAppCapture<D>::CapturingChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IAppCapture)->remove_CapturingChanged(token));
}

template <typename D> Windows::Media::Capture::AppCapture impl_IAppCaptureStatics<D>::GetForCurrentView() const
{
    Windows::Media::Capture::AppCapture value { nullptr };
    check_hresult(WINRT_SHIM(IAppCaptureStatics)->abi_GetForCurrentView(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::CameraCaptureUIPhotoFormat impl_ICameraCaptureUIPhotoCaptureSettings<D>::Format() const
{
    Windows::Media::Capture::CameraCaptureUIPhotoFormat value {};
    check_hresult(WINRT_SHIM(ICameraCaptureUIPhotoCaptureSettings)->get_Format(&value));
    return value;
}

template <typename D> void impl_ICameraCaptureUIPhotoCaptureSettings<D>::Format(Windows::Media::Capture::CameraCaptureUIPhotoFormat value) const
{
    check_hresult(WINRT_SHIM(ICameraCaptureUIPhotoCaptureSettings)->put_Format(value));
}

template <typename D> Windows::Media::Capture::CameraCaptureUIMaxPhotoResolution impl_ICameraCaptureUIPhotoCaptureSettings<D>::MaxResolution() const
{
    Windows::Media::Capture::CameraCaptureUIMaxPhotoResolution value {};
    check_hresult(WINRT_SHIM(ICameraCaptureUIPhotoCaptureSettings)->get_MaxResolution(&value));
    return value;
}

template <typename D> void impl_ICameraCaptureUIPhotoCaptureSettings<D>::MaxResolution(Windows::Media::Capture::CameraCaptureUIMaxPhotoResolution value) const
{
    check_hresult(WINRT_SHIM(ICameraCaptureUIPhotoCaptureSettings)->put_MaxResolution(value));
}

template <typename D> Windows::Foundation::Size impl_ICameraCaptureUIPhotoCaptureSettings<D>::CroppedSizeInPixels() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(ICameraCaptureUIPhotoCaptureSettings)->get_CroppedSizeInPixels(put_abi(value)));
    return value;
}

template <typename D> void impl_ICameraCaptureUIPhotoCaptureSettings<D>::CroppedSizeInPixels(const Windows::Foundation::Size & value) const
{
    check_hresult(WINRT_SHIM(ICameraCaptureUIPhotoCaptureSettings)->put_CroppedSizeInPixels(get_abi(value)));
}

template <typename D> Windows::Foundation::Size impl_ICameraCaptureUIPhotoCaptureSettings<D>::CroppedAspectRatio() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(ICameraCaptureUIPhotoCaptureSettings)->get_CroppedAspectRatio(put_abi(value)));
    return value;
}

template <typename D> void impl_ICameraCaptureUIPhotoCaptureSettings<D>::CroppedAspectRatio(const Windows::Foundation::Size & value) const
{
    check_hresult(WINRT_SHIM(ICameraCaptureUIPhotoCaptureSettings)->put_CroppedAspectRatio(get_abi(value)));
}

template <typename D> bool impl_ICameraCaptureUIPhotoCaptureSettings<D>::AllowCropping() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICameraCaptureUIPhotoCaptureSettings)->get_AllowCropping(&value));
    return value;
}

template <typename D> void impl_ICameraCaptureUIPhotoCaptureSettings<D>::AllowCropping(bool value) const
{
    check_hresult(WINRT_SHIM(ICameraCaptureUIPhotoCaptureSettings)->put_AllowCropping(value));
}

template <typename D> Windows::Media::Capture::CameraCaptureUIVideoFormat impl_ICameraCaptureUIVideoCaptureSettings<D>::Format() const
{
    Windows::Media::Capture::CameraCaptureUIVideoFormat value {};
    check_hresult(WINRT_SHIM(ICameraCaptureUIVideoCaptureSettings)->get_Format(&value));
    return value;
}

template <typename D> void impl_ICameraCaptureUIVideoCaptureSettings<D>::Format(Windows::Media::Capture::CameraCaptureUIVideoFormat value) const
{
    check_hresult(WINRT_SHIM(ICameraCaptureUIVideoCaptureSettings)->put_Format(value));
}

template <typename D> Windows::Media::Capture::CameraCaptureUIMaxVideoResolution impl_ICameraCaptureUIVideoCaptureSettings<D>::MaxResolution() const
{
    Windows::Media::Capture::CameraCaptureUIMaxVideoResolution value {};
    check_hresult(WINRT_SHIM(ICameraCaptureUIVideoCaptureSettings)->get_MaxResolution(&value));
    return value;
}

template <typename D> void impl_ICameraCaptureUIVideoCaptureSettings<D>::MaxResolution(Windows::Media::Capture::CameraCaptureUIMaxVideoResolution value) const
{
    check_hresult(WINRT_SHIM(ICameraCaptureUIVideoCaptureSettings)->put_MaxResolution(value));
}

template <typename D> float impl_ICameraCaptureUIVideoCaptureSettings<D>::MaxDurationInSeconds() const
{
    float value {};
    check_hresult(WINRT_SHIM(ICameraCaptureUIVideoCaptureSettings)->get_MaxDurationInSeconds(&value));
    return value;
}

template <typename D> void impl_ICameraCaptureUIVideoCaptureSettings<D>::MaxDurationInSeconds(float value) const
{
    check_hresult(WINRT_SHIM(ICameraCaptureUIVideoCaptureSettings)->put_MaxDurationInSeconds(value));
}

template <typename D> bool impl_ICameraCaptureUIVideoCaptureSettings<D>::AllowTrimming() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICameraCaptureUIVideoCaptureSettings)->get_AllowTrimming(&value));
    return value;
}

template <typename D> void impl_ICameraCaptureUIVideoCaptureSettings<D>::AllowTrimming(bool value) const
{
    check_hresult(WINRT_SHIM(ICameraCaptureUIVideoCaptureSettings)->put_AllowTrimming(value));
}

template <typename D> Windows::Media::Capture::CameraCaptureUIPhotoCaptureSettings impl_ICameraCaptureUI<D>::PhotoSettings() const
{
    Windows::Media::Capture::CameraCaptureUIPhotoCaptureSettings value { nullptr };
    check_hresult(WINRT_SHIM(ICameraCaptureUI)->get_PhotoSettings(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::CameraCaptureUIVideoCaptureSettings impl_ICameraCaptureUI<D>::VideoSettings() const
{
    Windows::Media::Capture::CameraCaptureUIVideoCaptureSettings value { nullptr };
    check_hresult(WINRT_SHIM(ICameraCaptureUI)->get_VideoSettings(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_ICameraCaptureUI<D>::CaptureFileAsync(Windows::Media::Capture::CameraCaptureUIMode mode) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> asyncInfo;
    check_hresult(WINRT_SHIM(ICameraCaptureUI)->abi_CaptureFileAsync(mode, put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> hstring impl_IMediaCaptureFailedEventArgs<D>::Message() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMediaCaptureFailedEventArgs)->get_Message(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IMediaCaptureFailedEventArgs<D>::Code() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMediaCaptureFailedEventArgs)->get_Code(&value));
    return value;
}

template <typename D> uint32_t impl_IMediaCaptureVideoProfileMediaDescription<D>::Width() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMediaCaptureVideoProfileMediaDescription)->get_Width(&value));
    return value;
}

template <typename D> uint32_t impl_IMediaCaptureVideoProfileMediaDescription<D>::Height() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMediaCaptureVideoProfileMediaDescription)->get_Height(&value));
    return value;
}

template <typename D> double impl_IMediaCaptureVideoProfileMediaDescription<D>::FrameRate() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMediaCaptureVideoProfileMediaDescription)->get_FrameRate(&value));
    return value;
}

template <typename D> bool impl_IMediaCaptureVideoProfileMediaDescription<D>::IsVariablePhotoSequenceSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaCaptureVideoProfileMediaDescription)->get_IsVariablePhotoSequenceSupported(&value));
    return value;
}

template <typename D> bool impl_IMediaCaptureVideoProfileMediaDescription<D>::IsHdrVideoSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaCaptureVideoProfileMediaDescription)->get_IsHdrVideoSupported(&value));
    return value;
}

template <typename D> hstring impl_IMediaCaptureVideoProfile<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMediaCaptureVideoProfile)->get_Id(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMediaCaptureVideoProfile<D>::VideoDeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMediaCaptureVideoProfile)->get_VideoDeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription> impl_IMediaCaptureVideoProfile<D>::SupportedPreviewMediaDescription() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription> value;
    check_hresult(WINRT_SHIM(IMediaCaptureVideoProfile)->get_SupportedPreviewMediaDescription(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription> impl_IMediaCaptureVideoProfile<D>::SupportedRecordMediaDescription() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription> value;
    check_hresult(WINRT_SHIM(IMediaCaptureVideoProfile)->get_SupportedRecordMediaDescription(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription> impl_IMediaCaptureVideoProfile<D>::SupportedPhotoMediaDescription() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription> value;
    check_hresult(WINRT_SHIM(IMediaCaptureVideoProfile)->get_SupportedPhotoMediaDescription(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> impl_IMediaCaptureVideoProfile<D>::GetConcurrency() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> value;
    check_hresult(WINRT_SHIM(IMediaCaptureVideoProfile)->abi_GetConcurrency(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings<D>::AudioDeviceId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings)->put_AudioDeviceId(get_abi(value)));
}

template <typename D> hstring impl_IMediaCaptureInitializationSettings<D>::AudioDeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings)->get_AudioDeviceId(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings<D>::VideoDeviceId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings)->put_VideoDeviceId(get_abi(value)));
}

template <typename D> hstring impl_IMediaCaptureInitializationSettings<D>::VideoDeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings)->get_VideoDeviceId(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings<D>::StreamingCaptureMode(Windows::Media::Capture::StreamingCaptureMode value) const
{
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings)->put_StreamingCaptureMode(value));
}

template <typename D> Windows::Media::Capture::StreamingCaptureMode impl_IMediaCaptureInitializationSettings<D>::StreamingCaptureMode() const
{
    Windows::Media::Capture::StreamingCaptureMode value {};
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings)->get_StreamingCaptureMode(&value));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings<D>::PhotoCaptureSource(Windows::Media::Capture::PhotoCaptureSource value) const
{
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings)->put_PhotoCaptureSource(value));
}

template <typename D> Windows::Media::Capture::PhotoCaptureSource impl_IMediaCaptureInitializationSettings<D>::PhotoCaptureSource() const
{
    Windows::Media::Capture::PhotoCaptureSource value {};
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings)->get_PhotoCaptureSource(&value));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings2<D>::MediaCategory(Windows::Media::Capture::MediaCategory value) const
{
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings2)->put_MediaCategory(value));
}

template <typename D> Windows::Media::Capture::MediaCategory impl_IMediaCaptureInitializationSettings2<D>::MediaCategory() const
{
    Windows::Media::Capture::MediaCategory value {};
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings2)->get_MediaCategory(&value));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings2<D>::AudioProcessing(Windows::Media::AudioProcessing value) const
{
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings2)->put_AudioProcessing(value));
}

template <typename D> Windows::Media::AudioProcessing impl_IMediaCaptureInitializationSettings2<D>::AudioProcessing() const
{
    Windows::Media::AudioProcessing value {};
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings2)->get_AudioProcessing(&value));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings3<D>::AudioSource(const Windows::Media::Core::IMediaSource & value) const
{
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings3)->put_AudioSource(get_abi(value)));
}

template <typename D> Windows::Media::Core::IMediaSource impl_IMediaCaptureInitializationSettings3<D>::AudioSource() const
{
    Windows::Media::Core::IMediaSource value;
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings3)->get_AudioSource(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings3<D>::VideoSource(const Windows::Media::Core::IMediaSource & value) const
{
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings3)->put_VideoSource(get_abi(value)));
}

template <typename D> Windows::Media::Core::IMediaSource impl_IMediaCaptureInitializationSettings3<D>::VideoSource() const
{
    Windows::Media::Core::IMediaSource value;
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings3)->get_VideoSource(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::MediaCaptureVideoProfile impl_IMediaCaptureInitializationSettings4<D>::VideoProfile() const
{
    Windows::Media::Capture::MediaCaptureVideoProfile value { nullptr };
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings4)->get_VideoProfile(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings4<D>::VideoProfile(const Windows::Media::Capture::MediaCaptureVideoProfile & value) const
{
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings4)->put_VideoProfile(get_abi(value)));
}

template <typename D> Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription impl_IMediaCaptureInitializationSettings4<D>::PreviewMediaDescription() const
{
    Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription value { nullptr };
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings4)->get_PreviewMediaDescription(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings4<D>::PreviewMediaDescription(const Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription & value) const
{
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings4)->put_PreviewMediaDescription(get_abi(value)));
}

template <typename D> Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription impl_IMediaCaptureInitializationSettings4<D>::RecordMediaDescription() const
{
    Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription value { nullptr };
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings4)->get_RecordMediaDescription(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings4<D>::RecordMediaDescription(const Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription & value) const
{
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings4)->put_RecordMediaDescription(get_abi(value)));
}

template <typename D> Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription impl_IMediaCaptureInitializationSettings4<D>::PhotoMediaDescription() const
{
    Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription value { nullptr };
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings4)->get_PhotoMediaDescription(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings4<D>::PhotoMediaDescription(const Windows::Media::Capture::MediaCaptureVideoProfileMediaDescription & value) const
{
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings4)->put_PhotoMediaDescription(get_abi(value)));
}

template <typename D> Windows::Media::Capture::Frames::MediaFrameSourceGroup impl_IMediaCaptureInitializationSettings5<D>::SourceGroup() const
{
    Windows::Media::Capture::Frames::MediaFrameSourceGroup value { nullptr };
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings5)->get_SourceGroup(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings5<D>::SourceGroup(const Windows::Media::Capture::Frames::MediaFrameSourceGroup & value) const
{
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings5)->put_SourceGroup(get_abi(value)));
}

template <typename D> Windows::Media::Capture::MediaCaptureSharingMode impl_IMediaCaptureInitializationSettings5<D>::SharingMode() const
{
    Windows::Media::Capture::MediaCaptureSharingMode value {};
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings5)->get_SharingMode(&value));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings5<D>::SharingMode(Windows::Media::Capture::MediaCaptureSharingMode value) const
{
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings5)->put_SharingMode(value));
}

template <typename D> Windows::Media::Capture::MediaCaptureMemoryPreference impl_IMediaCaptureInitializationSettings5<D>::MemoryPreference() const
{
    Windows::Media::Capture::MediaCaptureMemoryPreference value {};
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings5)->get_MemoryPreference(&value));
    return value;
}

template <typename D> void impl_IMediaCaptureInitializationSettings5<D>::MemoryPreference(Windows::Media::Capture::MediaCaptureMemoryPreference value) const
{
    check_hresult(WINRT_SHIM(IMediaCaptureInitializationSettings5)->put_MemoryPreference(value));
}

template <typename D> bool impl_IMediaCaptureStatics<D>::IsVideoProfileSupported(hstring_view videoDeviceId) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaCaptureStatics)->abi_IsVideoProfileSupported(get_abi(videoDeviceId), &value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> impl_IMediaCaptureStatics<D>::FindAllVideoProfiles(hstring_view videoDeviceId) const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> value;
    check_hresult(WINRT_SHIM(IMediaCaptureStatics)->abi_FindAllVideoProfiles(get_abi(videoDeviceId), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> impl_IMediaCaptureStatics<D>::FindConcurrentProfiles(hstring_view videoDeviceId) const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> value;
    check_hresult(WINRT_SHIM(IMediaCaptureStatics)->abi_FindConcurrentProfiles(get_abi(videoDeviceId), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> impl_IMediaCaptureStatics<D>::FindKnownVideoProfiles(hstring_view videoDeviceId, Windows::Media::Capture::KnownVideoProfile name) const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> value;
    check_hresult(WINRT_SHIM(IMediaCaptureStatics)->abi_FindKnownVideoProfiles(get_abi(videoDeviceId), name, put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture<D>::InitializeAsync() const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IMediaCapture)->abi_InitializeAsync(put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture<D>::InitializeAsync(const Windows::Media::Capture::MediaCaptureInitializationSettings & mediaCaptureInitializationSettings) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IMediaCapture)->abi_InitializeWithSettingsAsync(get_abi(mediaCaptureInitializationSettings), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture<D>::StartRecordToStorageFileAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, const Windows::Storage::IStorageFile & file) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IMediaCapture)->abi_StartRecordToStorageFileAsync(get_abi(encodingProfile), get_abi(file), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture<D>::StartRecordToStreamAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, const Windows::Storage::Streams::IRandomAccessStream & stream) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IMediaCapture)->abi_StartRecordToStreamAsync(get_abi(encodingProfile), get_abi(stream), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture<D>::StartRecordToCustomSinkAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, const Windows::Media::IMediaExtension & customMediaSink) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IMediaCapture)->abi_StartRecordToCustomSinkAsync(get_abi(encodingProfile), get_abi(customMediaSink), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture<D>::StartRecordToCustomSinkAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, hstring_view customSinkActivationId, const Windows::Foundation::Collections::IPropertySet & customSinkSettings) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IMediaCapture)->abi_StartRecordToCustomSinkIdAsync(get_abi(encodingProfile), get_abi(customSinkActivationId), get_abi(customSinkSettings), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture<D>::StopRecordAsync() const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IMediaCapture)->abi_StopRecordAsync(put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture<D>::CapturePhotoToStorageFileAsync(const Windows::Media::MediaProperties::ImageEncodingProperties & type, const Windows::Storage::IStorageFile & file) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IMediaCapture)->abi_CapturePhotoToStorageFileAsync(get_abi(type), get_abi(file), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture<D>::CapturePhotoToStreamAsync(const Windows::Media::MediaProperties::ImageEncodingProperties & type, const Windows::Storage::Streams::IRandomAccessStream & stream) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IMediaCapture)->abi_CapturePhotoToStreamAsync(get_abi(type), get_abi(stream), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture<D>::AddEffectAsync(Windows::Media::Capture::MediaStreamType mediaStreamType, hstring_view effectActivationID, const Windows::Foundation::Collections::IPropertySet & effectSettings) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IMediaCapture)->abi_AddEffectAsync(mediaStreamType, get_abi(effectActivationID), get_abi(effectSettings), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture<D>::ClearEffectsAsync(Windows::Media::Capture::MediaStreamType mediaStreamType) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IMediaCapture)->abi_ClearEffectsAsync(mediaStreamType, put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> void impl_IMediaCapture<D>::SetEncoderProperty(Windows::Media::Capture::MediaStreamType mediaStreamType, GUID propertyId, const Windows::Foundation::IInspectable & propertyValue) const
{
    check_hresult(WINRT_SHIM(IMediaCapture)->abi_SetEncoderProperty(mediaStreamType, propertyId, get_abi(propertyValue)));
}

template <typename D> Windows::Foundation::IInspectable impl_IMediaCapture<D>::GetEncoderProperty(Windows::Media::Capture::MediaStreamType mediaStreamType, GUID propertyId) const
{
    Windows::Foundation::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IMediaCapture)->abi_GetEncoderProperty(mediaStreamType, propertyId, put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> event_token impl_IMediaCapture<D>::Failed(const Windows::Media::Capture::MediaCaptureFailedEventHandler & errorEventHandler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(IMediaCapture)->add_Failed(get_abi(errorEventHandler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IMediaCapture> impl_IMediaCapture<D>::Failed(auto_revoke_t, const Windows::Media::Capture::MediaCaptureFailedEventHandler & errorEventHandler) const
{
    return impl::make_event_revoker<D, IMediaCapture>(this, &ABI::Windows::Media::Capture::IMediaCapture::remove_Failed, Failed(errorEventHandler));
}

template <typename D> void impl_IMediaCapture<D>::Failed(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(IMediaCapture)->remove_Failed(eventCookie));
}

template <typename D> event_token impl_IMediaCapture<D>::RecordLimitationExceeded(const Windows::Media::Capture::RecordLimitationExceededEventHandler & recordLimitationExceededEventHandler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(IMediaCapture)->add_RecordLimitationExceeded(get_abi(recordLimitationExceededEventHandler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IMediaCapture> impl_IMediaCapture<D>::RecordLimitationExceeded(auto_revoke_t, const Windows::Media::Capture::RecordLimitationExceededEventHandler & recordLimitationExceededEventHandler) const
{
    return impl::make_event_revoker<D, IMediaCapture>(this, &ABI::Windows::Media::Capture::IMediaCapture::remove_RecordLimitationExceeded, RecordLimitationExceeded(recordLimitationExceededEventHandler));
}

template <typename D> void impl_IMediaCapture<D>::RecordLimitationExceeded(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(IMediaCapture)->remove_RecordLimitationExceeded(eventCookie));
}

template <typename D> Windows::Media::Capture::MediaCaptureSettings impl_IMediaCapture<D>::MediaCaptureSettings() const
{
    Windows::Media::Capture::MediaCaptureSettings value { nullptr };
    check_hresult(WINRT_SHIM(IMediaCapture)->get_MediaCaptureSettings(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Devices::AudioDeviceController impl_IMediaCapture<D>::AudioDeviceController() const
{
    Windows::Media::Devices::AudioDeviceController value { nullptr };
    check_hresult(WINRT_SHIM(IMediaCapture)->get_AudioDeviceController(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Devices::VideoDeviceController impl_IMediaCapture<D>::VideoDeviceController() const
{
    Windows::Media::Devices::VideoDeviceController value { nullptr };
    check_hresult(WINRT_SHIM(IMediaCapture)->get_VideoDeviceController(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaCapture<D>::SetPreviewMirroring(bool value) const
{
    check_hresult(WINRT_SHIM(IMediaCapture)->abi_SetPreviewMirroring(value));
}

template <typename D> bool impl_IMediaCapture<D>::GetPreviewMirroring() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaCapture)->abi_GetPreviewMirroring(&value));
    return value;
}

template <typename D> void impl_IMediaCapture<D>::SetPreviewRotation(Windows::Media::Capture::VideoRotation value) const
{
    check_hresult(WINRT_SHIM(IMediaCapture)->abi_SetPreviewRotation(value));
}

template <typename D> Windows::Media::Capture::VideoRotation impl_IMediaCapture<D>::GetPreviewRotation() const
{
    Windows::Media::Capture::VideoRotation value {};
    check_hresult(WINRT_SHIM(IMediaCapture)->abi_GetPreviewRotation(&value));
    return value;
}

template <typename D> void impl_IMediaCapture<D>::SetRecordRotation(Windows::Media::Capture::VideoRotation value) const
{
    check_hresult(WINRT_SHIM(IMediaCapture)->abi_SetRecordRotation(value));
}

template <typename D> Windows::Media::Capture::VideoRotation impl_IMediaCapture<D>::GetRecordRotation() const
{
    Windows::Media::Capture::VideoRotation value {};
    check_hresult(WINRT_SHIM(IMediaCapture)->abi_GetRecordRotation(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording> impl_IMediaCapture2<D>::PrepareLowLagRecordToStorageFileAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, const Windows::Storage::IStorageFile & file) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording> operation;
    check_hresult(WINRT_SHIM(IMediaCapture2)->abi_PrepareLowLagRecordToStorageFileAsync(get_abi(encodingProfile), get_abi(file), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording> impl_IMediaCapture2<D>::PrepareLowLagRecordToStreamAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, const Windows::Storage::Streams::IRandomAccessStream & stream) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording> operation;
    check_hresult(WINRT_SHIM(IMediaCapture2)->abi_PrepareLowLagRecordToStreamAsync(get_abi(encodingProfile), get_abi(stream), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording> impl_IMediaCapture2<D>::PrepareLowLagRecordToCustomSinkAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, const Windows::Media::IMediaExtension & customMediaSink) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording> operation;
    check_hresult(WINRT_SHIM(IMediaCapture2)->abi_PrepareLowLagRecordToCustomSinkAsync(get_abi(encodingProfile), get_abi(customMediaSink), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording> impl_IMediaCapture2<D>::PrepareLowLagRecordToCustomSinkAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, hstring_view customSinkActivationId, const Windows::Foundation::Collections::IPropertySet & customSinkSettings) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagMediaRecording> operation;
    check_hresult(WINRT_SHIM(IMediaCapture2)->abi_PrepareLowLagRecordToCustomSinkIdAsync(get_abi(encodingProfile), get_abi(customSinkActivationId), get_abi(customSinkSettings), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagPhotoCapture> impl_IMediaCapture2<D>::PrepareLowLagPhotoCaptureAsync(const Windows::Media::MediaProperties::ImageEncodingProperties & type) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagPhotoCapture> operation;
    check_hresult(WINRT_SHIM(IMediaCapture2)->abi_PrepareLowLagPhotoCaptureAsync(get_abi(type), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagPhotoSequenceCapture> impl_IMediaCapture2<D>::PrepareLowLagPhotoSequenceCaptureAsync(const Windows::Media::MediaProperties::ImageEncodingProperties & type) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::LowLagPhotoSequenceCapture> operation;
    check_hresult(WINRT_SHIM(IMediaCapture2)->abi_PrepareLowLagPhotoSequenceCaptureAsync(get_abi(type), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture2<D>::SetEncodingPropertiesAsync(Windows::Media::Capture::MediaStreamType mediaStreamType, const Windows::Media::MediaProperties::IMediaEncodingProperties & mediaEncodingProperties, const Windows::Media::MediaProperties::MediaPropertySet & encoderProperties) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IMediaCapture2)->abi_SetEncodingPropertiesAsync(mediaStreamType, get_abi(mediaEncodingProperties), get_abi(encoderProperties), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Core::VariablePhotoSequenceCapture> impl_IMediaCapture3<D>::PrepareVariablePhotoSequenceCaptureAsync(const Windows::Media::MediaProperties::ImageEncodingProperties & type) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Core::VariablePhotoSequenceCapture> operation;
    check_hresult(WINRT_SHIM(IMediaCapture3)->abi_PrepareVariablePhotoSequenceCaptureAsync(get_abi(type), put_abi(operation)));
    return operation;
}

template <typename D> event_token impl_IMediaCapture3<D>::FocusChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Media::Capture::MediaCaptureFocusChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaCapture3)->add_FocusChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaCapture3> impl_IMediaCapture3<D>::FocusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Media::Capture::MediaCaptureFocusChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaCapture3>(this, &ABI::Windows::Media::Capture::IMediaCapture3::remove_FocusChanged, FocusChanged(handler));
}

template <typename D> void impl_IMediaCapture3<D>::FocusChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaCapture3)->remove_FocusChanged(token));
}

template <typename D> event_token impl_IMediaCapture3<D>::PhotoConfirmationCaptured(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Media::Capture::PhotoConfirmationCapturedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaCapture3)->add_PhotoConfirmationCaptured(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaCapture3> impl_IMediaCapture3<D>::PhotoConfirmationCaptured(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Media::Capture::PhotoConfirmationCapturedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaCapture3>(this, &ABI::Windows::Media::Capture::IMediaCapture3::remove_PhotoConfirmationCaptured, PhotoConfirmationCaptured(handler));
}

template <typename D> void impl_IMediaCapture3<D>::PhotoConfirmationCaptured(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaCapture3)->remove_PhotoConfirmationCaptured(token));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::IMediaExtension> impl_IMediaCapture4<D>::AddAudioEffectAsync(const Windows::Media::Effects::IAudioEffectDefinition & definition) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::IMediaExtension> op;
    check_hresult(WINRT_SHIM(IMediaCapture4)->abi_AddAudioEffectAsync(get_abi(definition), put_abi(op)));
    return op;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::IMediaExtension> impl_IMediaCapture4<D>::AddVideoEffectAsync(const Windows::Media::Effects::IVideoEffectDefinition & definition, Windows::Media::Capture::MediaStreamType mediaStreamType) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::IMediaExtension> op;
    check_hresult(WINRT_SHIM(IMediaCapture4)->abi_AddVideoEffectAsync(get_abi(definition), mediaStreamType, put_abi(op)));
    return op;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture4<D>::PauseRecordAsync(Windows::Media::Devices::MediaCapturePauseBehavior behavior) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IMediaCapture4)->abi_PauseRecordAsync(behavior, put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture4<D>::ResumeRecordAsync() const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IMediaCapture4)->abi_ResumeRecordAsync(put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> event_token impl_IMediaCapture4<D>::CameraStreamStateChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaCapture4)->add_CameraStreamStateChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaCapture4> impl_IMediaCapture4<D>::CameraStreamStateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMediaCapture4>(this, &ABI::Windows::Media::Capture::IMediaCapture4::remove_CameraStreamStateChanged, CameraStreamStateChanged(handler));
}

template <typename D> void impl_IMediaCapture4<D>::CameraStreamStateChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaCapture4)->remove_CameraStreamStateChanged(token));
}

template <typename D> Windows::Media::Devices::CameraStreamState impl_IMediaCapture4<D>::CameraStreamState() const
{
    Windows::Media::Devices::CameraStreamState streamState {};
    check_hresult(WINRT_SHIM(IMediaCapture4)->get_CameraStreamState(&streamState));
    return streamState;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::VideoFrame> impl_IMediaCapture4<D>::GetPreviewFrameAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::VideoFrame> operation;
    check_hresult(WINRT_SHIM(IMediaCapture4)->abi_GetPreviewFrameAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::VideoFrame> impl_IMediaCapture4<D>::GetPreviewFrameAsync(const Windows::Media::VideoFrame & destination) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::VideoFrame> operation;
    check_hresult(WINRT_SHIM(IMediaCapture4)->abi_GetPreviewFrameCopyAsync(get_abi(destination), put_abi(operation)));
    return operation;
}

template <typename D> event_token impl_IMediaCapture4<D>::ThermalStatusChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaCapture4)->add_ThermalStatusChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaCapture4> impl_IMediaCapture4<D>::ThermalStatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::MediaCapture, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMediaCapture4>(this, &ABI::Windows::Media::Capture::IMediaCapture4::remove_ThermalStatusChanged, ThermalStatusChanged(handler));
}

template <typename D> void impl_IMediaCapture4<D>::ThermalStatusChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaCapture4)->remove_ThermalStatusChanged(token));
}

template <typename D> Windows::Media::Capture::MediaCaptureThermalStatus impl_IMediaCapture4<D>::ThermalStatus() const
{
    Windows::Media::Capture::MediaCaptureThermalStatus value {};
    check_hresult(WINRT_SHIM(IMediaCapture4)->get_ThermalStatus(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::AdvancedPhotoCapture> impl_IMediaCapture4<D>::PrepareAdvancedPhotoCaptureAsync(const Windows::Media::MediaProperties::ImageEncodingProperties & encodingProperties) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::AdvancedPhotoCapture> operation;
    check_hresult(WINRT_SHIM(IMediaCapture4)->abi_PrepareAdvancedPhotoCaptureAsync(get_abi(encodingProperties), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCapture5<D>::RemoveEffectAsync(const Windows::Media::IMediaExtension & effect) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IMediaCapture5)->abi_RemoveEffectAsync(get_abi(effect), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCapturePauseResult> impl_IMediaCapture5<D>::PauseRecordWithResultAsync(Windows::Media::Devices::MediaCapturePauseBehavior behavior) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCapturePauseResult> operation;
    check_hresult(WINRT_SHIM(IMediaCapture5)->abi_PauseRecordWithResultAsync(behavior, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCaptureStopResult> impl_IMediaCapture5<D>::StopRecordWithResultAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCaptureStopResult> operation;
    check_hresult(WINRT_SHIM(IMediaCapture5)->abi_StopRecordWithResultAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Media::Capture::Frames::MediaFrameSource> impl_IMediaCapture5<D>::FrameSources() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Media::Capture::Frames::MediaFrameSource> value;
    check_hresult(WINRT_SHIM(IMediaCapture5)->get_FrameSources(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameReader> impl_IMediaCapture5<D>::CreateFrameReaderAsync(const Windows::Media::Capture::Frames::MediaFrameSource & inputSource) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameReader> value;
    check_hresult(WINRT_SHIM(IMediaCapture5)->abi_CreateFrameReaderAsync(get_abi(inputSource), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameReader> impl_IMediaCapture5<D>::CreateFrameReaderAsync(const Windows::Media::Capture::Frames::MediaFrameSource & inputSource, hstring_view outputSubtype) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameReader> value;
    check_hresult(WINRT_SHIM(IMediaCapture5)->abi_CreateFrameReaderWithSubtypeAsync(get_abi(inputSource), get_abi(outputSubtype), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameReader> impl_IMediaCapture5<D>::CreateFrameReaderAsync(const Windows::Media::Capture::Frames::MediaFrameSource & inputSource, hstring_view outputSubtype, const Windows::Graphics::Imaging::BitmapSize & outputSize) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameReader> value;
    check_hresult(WINRT_SHIM(IMediaCapture5)->abi_CreateFrameReaderWithSubtypeAndSizeAsync(get_abi(inputSource), get_abi(outputSubtype), get_abi(outputSize), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::CapturedPhoto> impl_ILowLagPhotoCapture<D>::CaptureAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::CapturedPhoto> operation;
    check_hresult(WINRT_SHIM(ILowLagPhotoCapture)->abi_CaptureAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ILowLagPhotoCapture<D>::FinishAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(ILowLagPhotoCapture)->abi_FinishAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::AdvancedCapturedPhoto> impl_IAdvancedPhotoCapture<D>::CaptureAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::AdvancedCapturedPhoto> operation;
    check_hresult(WINRT_SHIM(IAdvancedPhotoCapture)->abi_CaptureAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::AdvancedCapturedPhoto> impl_IAdvancedPhotoCapture<D>::CaptureAsync(const Windows::Foundation::IInspectable & context) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::AdvancedCapturedPhoto> operation;
    check_hresult(WINRT_SHIM(IAdvancedPhotoCapture)->abi_CaptureWithContextAsync(get_abi(context), put_abi(operation)));
    return operation;
}

template <typename D> event_token impl_IAdvancedPhotoCapture<D>::OptionalReferencePhotoCaptured(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AdvancedPhotoCapture, Windows::Media::Capture::OptionalReferencePhotoCapturedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IAdvancedPhotoCapture)->add_OptionalReferencePhotoCaptured(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IAdvancedPhotoCapture> impl_IAdvancedPhotoCapture<D>::OptionalReferencePhotoCaptured(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AdvancedPhotoCapture, Windows::Media::Capture::OptionalReferencePhotoCapturedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IAdvancedPhotoCapture>(this, &ABI::Windows::Media::Capture::IAdvancedPhotoCapture::remove_OptionalReferencePhotoCaptured, OptionalReferencePhotoCaptured(handler));
}

template <typename D> void impl_IAdvancedPhotoCapture<D>::OptionalReferencePhotoCaptured(event_token token) const
{
    check_hresult(WINRT_SHIM(IAdvancedPhotoCapture)->remove_OptionalReferencePhotoCaptured(token));
}

template <typename D> event_token impl_IAdvancedPhotoCapture<D>::AllPhotosCaptured(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AdvancedPhotoCapture, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IAdvancedPhotoCapture)->add_AllPhotosCaptured(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IAdvancedPhotoCapture> impl_IAdvancedPhotoCapture<D>::AllPhotosCaptured(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::AdvancedPhotoCapture, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IAdvancedPhotoCapture>(this, &ABI::Windows::Media::Capture::IAdvancedPhotoCapture::remove_AllPhotosCaptured, AllPhotosCaptured(handler));
}

template <typename D> void impl_IAdvancedPhotoCapture<D>::AllPhotosCaptured(event_token token) const
{
    check_hresult(WINRT_SHIM(IAdvancedPhotoCapture)->remove_AllPhotosCaptured(token));
}

template <typename D> Windows::Foundation::IAsyncAction impl_IAdvancedPhotoCapture<D>::FinishAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IAdvancedPhotoCapture)->abi_FinishAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Media::Capture::CapturedFrame impl_IAdvancedCapturedPhoto<D>::Frame() const
{
    Windows::Media::Capture::CapturedFrame value { nullptr };
    check_hresult(WINRT_SHIM(IAdvancedCapturedPhoto)->get_Frame(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Devices::AdvancedPhotoMode impl_IAdvancedCapturedPhoto<D>::Mode() const
{
    Windows::Media::Devices::AdvancedPhotoMode value {};
    check_hresult(WINRT_SHIM(IAdvancedCapturedPhoto)->get_Mode(&value));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_IAdvancedCapturedPhoto<D>::Context() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IAdvancedCapturedPhoto)->get_Context(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::Rect> impl_IAdvancedCapturedPhoto2<D>::FrameBoundsRelativeToReferencePhoto() const
{
    Windows::Foundation::IReference<Windows::Foundation::Rect> value;
    check_hresult(WINRT_SHIM(IAdvancedCapturedPhoto2)->get_FrameBoundsRelativeToReferencePhoto(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::CapturedFrame impl_IOptionalReferencePhotoCapturedEventArgs<D>::Frame() const
{
    Windows::Media::Capture::CapturedFrame value { nullptr };
    check_hresult(WINRT_SHIM(IOptionalReferencePhotoCapturedEventArgs)->get_Frame(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_IOptionalReferencePhotoCapturedEventArgs<D>::Context() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IOptionalReferencePhotoCapturedEventArgs)->get_Context(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ILowLagMediaRecording<D>::StartAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(ILowLagMediaRecording)->abi_StartAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ILowLagMediaRecording<D>::StopAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(ILowLagMediaRecording)->abi_StopAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ILowLagMediaRecording<D>::FinishAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(ILowLagMediaRecording)->abi_FinishAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ILowLagMediaRecording2<D>::PauseAsync(Windows::Media::Devices::MediaCapturePauseBehavior behavior) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(ILowLagMediaRecording2)->abi_PauseAsync(behavior, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ILowLagMediaRecording2<D>::ResumeAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(ILowLagMediaRecording2)->abi_ResumeAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCapturePauseResult> impl_ILowLagMediaRecording3<D>::PauseWithResultAsync(Windows::Media::Devices::MediaCapturePauseBehavior behavior) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCapturePauseResult> operation;
    check_hresult(WINRT_SHIM(ILowLagMediaRecording3)->abi_PauseWithResultAsync(behavior, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCaptureStopResult> impl_ILowLagMediaRecording3<D>::StopWithResultAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::MediaCaptureStopResult> operation;
    check_hresult(WINRT_SHIM(ILowLagMediaRecording3)->abi_StopWithResultAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Media::VideoFrame impl_IMediaCapturePauseResult<D>::LastFrame() const
{
    Windows::Media::VideoFrame value { nullptr };
    check_hresult(WINRT_SHIM(IMediaCapturePauseResult)->get_LastFrame(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaCapturePauseResult<D>::RecordDuration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaCapturePauseResult)->get_RecordDuration(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::VideoFrame impl_IMediaCaptureStopResult<D>::LastFrame() const
{
    Windows::Media::VideoFrame value { nullptr };
    check_hresult(WINRT_SHIM(IMediaCaptureStopResult)->get_LastFrame(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaCaptureStopResult<D>::RecordDuration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaCaptureStopResult)->get_RecordDuration(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ILowLagPhotoSequenceCapture<D>::StartAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(ILowLagPhotoSequenceCapture)->abi_StartAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ILowLagPhotoSequenceCapture<D>::StopAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(ILowLagPhotoSequenceCapture)->abi_StopAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ILowLagPhotoSequenceCapture<D>::FinishAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(ILowLagPhotoSequenceCapture)->abi_FinishAsync(put_abi(operation)));
    return operation;
}

template <typename D> event_token impl_ILowLagPhotoSequenceCapture<D>::PhotoCaptured(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::LowLagPhotoSequenceCapture, Windows::Media::Capture::PhotoCapturedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ILowLagPhotoSequenceCapture)->add_PhotoCaptured(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ILowLagPhotoSequenceCapture> impl_ILowLagPhotoSequenceCapture<D>::PhotoCaptured(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::LowLagPhotoSequenceCapture, Windows::Media::Capture::PhotoCapturedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ILowLagPhotoSequenceCapture>(this, &ABI::Windows::Media::Capture::ILowLagPhotoSequenceCapture::remove_PhotoCaptured, PhotoCaptured(handler));
}

template <typename D> void impl_ILowLagPhotoSequenceCapture<D>::PhotoCaptured(event_token token) const
{
    check_hresult(WINRT_SHIM(ILowLagPhotoSequenceCapture)->remove_PhotoCaptured(token));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_ICapturedFrameControlValues<D>::Exposure() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(WINRT_SHIM(ICapturedFrameControlValues)->get_Exposure(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<float> impl_ICapturedFrameControlValues<D>::ExposureCompensation() const
{
    Windows::Foundation::IReference<float> value;
    check_hresult(WINRT_SHIM(ICapturedFrameControlValues)->get_ExposureCompensation(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_ICapturedFrameControlValues<D>::IsoSpeed() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(WINRT_SHIM(ICapturedFrameControlValues)->get_IsoSpeed(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_ICapturedFrameControlValues<D>::Focus() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(WINRT_SHIM(ICapturedFrameControlValues)->get_Focus(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<winrt::Windows::Media::Devices::CaptureSceneMode> impl_ICapturedFrameControlValues<D>::SceneMode() const
{
    Windows::Foundation::IReference<winrt::Windows::Media::Devices::CaptureSceneMode> value;
    check_hresult(WINRT_SHIM(ICapturedFrameControlValues)->get_SceneMode(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<bool> impl_ICapturedFrameControlValues<D>::Flashed() const
{
    Windows::Foundation::IReference<bool> value;
    check_hresult(WINRT_SHIM(ICapturedFrameControlValues)->get_Flashed(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<float> impl_ICapturedFrameControlValues<D>::FlashPowerPercent() const
{
    Windows::Foundation::IReference<float> value;
    check_hresult(WINRT_SHIM(ICapturedFrameControlValues)->get_FlashPowerPercent(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_ICapturedFrameControlValues<D>::WhiteBalance() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(WINRT_SHIM(ICapturedFrameControlValues)->get_WhiteBalance(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<float> impl_ICapturedFrameControlValues<D>::ZoomFactor() const
{
    Windows::Foundation::IReference<float> value;
    check_hresult(WINRT_SHIM(ICapturedFrameControlValues)->get_ZoomFactor(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<winrt::Windows::Media::Devices::MediaCaptureFocusState> impl_ICapturedFrameControlValues2<D>::FocusState() const
{
    Windows::Foundation::IReference<winrt::Windows::Media::Devices::MediaCaptureFocusState> value;
    check_hresult(WINRT_SHIM(ICapturedFrameControlValues2)->get_FocusState(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<double> impl_ICapturedFrameControlValues2<D>::IsoDigitalGain() const
{
    Windows::Foundation::IReference<double> value;
    check_hresult(WINRT_SHIM(ICapturedFrameControlValues2)->get_IsoDigitalGain(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<double> impl_ICapturedFrameControlValues2<D>::IsoAnalogGain() const
{
    Windows::Foundation::IReference<double> value;
    check_hresult(WINRT_SHIM(ICapturedFrameControlValues2)->get_IsoAnalogGain(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::MediaProperties::MediaRatio impl_ICapturedFrameControlValues2<D>::SensorFrameRate() const
{
    Windows::Media::MediaProperties::MediaRatio value { nullptr };
    check_hresult(WINRT_SHIM(ICapturedFrameControlValues2)->get_SensorFrameRate(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Media::Capture::WhiteBalanceGain> impl_ICapturedFrameControlValues2<D>::WhiteBalanceGain() const
{
    Windows::Foundation::IReference<Windows::Media::Capture::WhiteBalanceGain> value;
    check_hresult(WINRT_SHIM(ICapturedFrameControlValues2)->get_WhiteBalanceGain(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::CapturedFrame impl_IPhotoCapturedEventArgs<D>::Frame() const
{
    Windows::Media::Capture::CapturedFrame value { nullptr };
    check_hresult(WINRT_SHIM(IPhotoCapturedEventArgs)->get_Frame(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::CapturedFrame impl_IPhotoCapturedEventArgs<D>::Thumbnail() const
{
    Windows::Media::Capture::CapturedFrame value { nullptr };
    check_hresult(WINRT_SHIM(IPhotoCapturedEventArgs)->get_Thumbnail(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IPhotoCapturedEventArgs<D>::CaptureTimeOffset() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IPhotoCapturedEventArgs)->get_CaptureTimeOffset(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::CapturedFrame impl_ICapturedPhoto<D>::Frame() const
{
    Windows::Media::Capture::CapturedFrame value { nullptr };
    check_hresult(WINRT_SHIM(ICapturedPhoto)->get_Frame(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::CapturedFrame impl_ICapturedPhoto<D>::Thumbnail() const
{
    Windows::Media::Capture::CapturedFrame value { nullptr };
    check_hresult(WINRT_SHIM(ICapturedPhoto)->get_Thumbnail(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_ICapturedFrame<D>::Width() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ICapturedFrame)->get_Width(&value));
    return value;
}

template <typename D> uint32_t impl_ICapturedFrame<D>::Height() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ICapturedFrame)->get_Height(&value));
    return value;
}

template <typename D> Windows::Graphics::Imaging::SoftwareBitmap impl_ICapturedFrameWithSoftwareBitmap<D>::SoftwareBitmap() const
{
    Windows::Graphics::Imaging::SoftwareBitmap value { nullptr };
    check_hresult(WINRT_SHIM(ICapturedFrameWithSoftwareBitmap)->get_SoftwareBitmap(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCaptureVideoPreview<D>::StartPreviewAsync() const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IMediaCaptureVideoPreview)->abi_StartPreviewAsync(put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCaptureVideoPreview<D>::StartPreviewToCustomSinkAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, const Windows::Media::IMediaExtension & customMediaSink) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IMediaCaptureVideoPreview)->abi_StartPreviewToCustomSinkAsync(get_abi(encodingProfile), get_abi(customMediaSink), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCaptureVideoPreview<D>::StartPreviewToCustomSinkAsync(const Windows::Media::MediaProperties::MediaEncodingProfile & encodingProfile, hstring_view customSinkActivationId, const Windows::Foundation::Collections::IPropertySet & customSinkSettings) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IMediaCaptureVideoPreview)->abi_StartPreviewToCustomSinkIdAsync(get_abi(encodingProfile), get_abi(customSinkActivationId), get_abi(customSinkSettings), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaCaptureVideoPreview<D>::StopPreviewAsync() const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IMediaCaptureVideoPreview)->abi_StopPreviewAsync(put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> hstring impl_IMediaCaptureSettings<D>::AudioDeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMediaCaptureSettings)->get_AudioDeviceId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMediaCaptureSettings<D>::VideoDeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMediaCaptureSettings)->get_VideoDeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::StreamingCaptureMode impl_IMediaCaptureSettings<D>::StreamingCaptureMode() const
{
    Windows::Media::Capture::StreamingCaptureMode value {};
    check_hresult(WINRT_SHIM(IMediaCaptureSettings)->get_StreamingCaptureMode(&value));
    return value;
}

template <typename D> Windows::Media::Capture::PhotoCaptureSource impl_IMediaCaptureSettings<D>::PhotoCaptureSource() const
{
    Windows::Media::Capture::PhotoCaptureSource value {};
    check_hresult(WINRT_SHIM(IMediaCaptureSettings)->get_PhotoCaptureSource(&value));
    return value;
}

template <typename D> Windows::Media::Capture::VideoDeviceCharacteristic impl_IMediaCaptureSettings<D>::VideoDeviceCharacteristic() const
{
    Windows::Media::Capture::VideoDeviceCharacteristic value {};
    check_hresult(WINRT_SHIM(IMediaCaptureSettings)->get_VideoDeviceCharacteristic(&value));
    return value;
}

template <typename D> bool impl_IMediaCaptureSettings2<D>::ConcurrentRecordAndPhotoSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaCaptureSettings2)->get_ConcurrentRecordAndPhotoSupported(&value));
    return value;
}

template <typename D> bool impl_IMediaCaptureSettings2<D>::ConcurrentRecordAndPhotoSequenceSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaCaptureSettings2)->get_ConcurrentRecordAndPhotoSequenceSupported(&value));
    return value;
}

template <typename D> bool impl_IMediaCaptureSettings2<D>::CameraSoundRequiredForRegion() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaCaptureSettings2)->get_CameraSoundRequiredForRegion(&value));
    return value;
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_IMediaCaptureSettings2<D>::Horizontal35mmEquivalentFocalLength() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(WINRT_SHIM(IMediaCaptureSettings2)->get_Horizontal35mmEquivalentFocalLength(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IMediaCaptureSettings2<D>::PitchOffsetDegrees() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IMediaCaptureSettings2)->get_PitchOffsetDegrees(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_IMediaCaptureSettings2<D>::Vertical35mmEquivalentFocalLength() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(WINRT_SHIM(IMediaCaptureSettings2)->get_Vertical35mmEquivalentFocalLength(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::MediaCategory impl_IMediaCaptureSettings2<D>::MediaCategory() const
{
    Windows::Media::Capture::MediaCategory value {};
    check_hresult(WINRT_SHIM(IMediaCaptureSettings2)->get_MediaCategory(&value));
    return value;
}

template <typename D> Windows::Media::AudioProcessing impl_IMediaCaptureSettings2<D>::AudioProcessing() const
{
    Windows::Media::AudioProcessing value {};
    check_hresult(WINRT_SHIM(IMediaCaptureSettings2)->get_AudioProcessing(&value));
    return value;
}

template <typename D> Windows::Media::Devices::MediaCaptureFocusState impl_IMediaCaptureFocusChangedEventArgs<D>::FocusState() const
{
    Windows::Media::Devices::MediaCaptureFocusState value {};
    check_hresult(WINRT_SHIM(IMediaCaptureFocusChangedEventArgs)->get_FocusState(&value));
    return value;
}

template <typename D> Windows::Media::Capture::CapturedFrame impl_IPhotoConfirmationCapturedEventArgs<D>::Frame() const
{
    Windows::Media::Capture::CapturedFrame value { nullptr };
    check_hresult(WINRT_SHIM(IPhotoConfirmationCapturedEventArgs)->get_Frame(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IPhotoConfirmationCapturedEventArgs<D>::CaptureTimeOffset() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IPhotoConfirmationCapturedEventArgs)->get_CaptureTimeOffset(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::MediaProperties::VideoEncodingProperties impl_IVideoStreamConfiguration<D>::InputProperties() const
{
    Windows::Media::MediaProperties::VideoEncodingProperties value { nullptr };
    check_hresult(WINRT_SHIM(IVideoStreamConfiguration)->get_InputProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::MediaProperties::VideoEncodingProperties impl_IVideoStreamConfiguration<D>::OutputProperties() const
{
    Windows::Media::MediaProperties::VideoEncodingProperties value { nullptr };
    check_hresult(WINRT_SHIM(IVideoStreamConfiguration)->get_OutputProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::AppCaptureSettings impl_IAppCaptureManagerStatics<D>::GetCurrentSettings() const
{
    Windows::Media::Capture::AppCaptureSettings value { nullptr };
    check_hresult(WINRT_SHIM(IAppCaptureManagerStatics)->abi_GetCurrentSettings(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppCaptureManagerStatics<D>::ApplySettings(const Windows::Media::Capture::AppCaptureSettings & appCaptureSettings) const
{
    check_hresult(WINRT_SHIM(IAppCaptureManagerStatics)->abi_ApplySettings(get_abi(appCaptureSettings)));
}

template <typename D> void impl_IAppCaptureAlternateShortcutKeys<D>::ToggleGameBarKey(Windows::System::VirtualKey value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys)->put_ToggleGameBarKey(value));
}

template <typename D> Windows::System::VirtualKey impl_IAppCaptureAlternateShortcutKeys<D>::ToggleGameBarKey() const
{
    Windows::System::VirtualKey value {};
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys)->get_ToggleGameBarKey(&value));
    return value;
}

template <typename D> void impl_IAppCaptureAlternateShortcutKeys<D>::ToggleGameBarKeyModifiers(Windows::System::VirtualKeyModifiers value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys)->put_ToggleGameBarKeyModifiers(value));
}

template <typename D> Windows::System::VirtualKeyModifiers impl_IAppCaptureAlternateShortcutKeys<D>::ToggleGameBarKeyModifiers() const
{
    Windows::System::VirtualKeyModifiers value {};
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys)->get_ToggleGameBarKeyModifiers(&value));
    return value;
}

template <typename D> void impl_IAppCaptureAlternateShortcutKeys<D>::SaveHistoricalVideoKey(Windows::System::VirtualKey value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys)->put_SaveHistoricalVideoKey(value));
}

template <typename D> Windows::System::VirtualKey impl_IAppCaptureAlternateShortcutKeys<D>::SaveHistoricalVideoKey() const
{
    Windows::System::VirtualKey value {};
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys)->get_SaveHistoricalVideoKey(&value));
    return value;
}

template <typename D> void impl_IAppCaptureAlternateShortcutKeys<D>::SaveHistoricalVideoKeyModifiers(Windows::System::VirtualKeyModifiers value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys)->put_SaveHistoricalVideoKeyModifiers(value));
}

template <typename D> Windows::System::VirtualKeyModifiers impl_IAppCaptureAlternateShortcutKeys<D>::SaveHistoricalVideoKeyModifiers() const
{
    Windows::System::VirtualKeyModifiers value {};
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys)->get_SaveHistoricalVideoKeyModifiers(&value));
    return value;
}

template <typename D> void impl_IAppCaptureAlternateShortcutKeys<D>::ToggleRecordingKey(Windows::System::VirtualKey value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys)->put_ToggleRecordingKey(value));
}

template <typename D> Windows::System::VirtualKey impl_IAppCaptureAlternateShortcutKeys<D>::ToggleRecordingKey() const
{
    Windows::System::VirtualKey value {};
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys)->get_ToggleRecordingKey(&value));
    return value;
}

template <typename D> void impl_IAppCaptureAlternateShortcutKeys<D>::ToggleRecordingKeyModifiers(Windows::System::VirtualKeyModifiers value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys)->put_ToggleRecordingKeyModifiers(value));
}

template <typename D> Windows::System::VirtualKeyModifiers impl_IAppCaptureAlternateShortcutKeys<D>::ToggleRecordingKeyModifiers() const
{
    Windows::System::VirtualKeyModifiers value {};
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys)->get_ToggleRecordingKeyModifiers(&value));
    return value;
}

template <typename D> void impl_IAppCaptureAlternateShortcutKeys<D>::TakeScreenshotKey(Windows::System::VirtualKey value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys)->put_TakeScreenshotKey(value));
}

template <typename D> Windows::System::VirtualKey impl_IAppCaptureAlternateShortcutKeys<D>::TakeScreenshotKey() const
{
    Windows::System::VirtualKey value {};
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys)->get_TakeScreenshotKey(&value));
    return value;
}

template <typename D> void impl_IAppCaptureAlternateShortcutKeys<D>::TakeScreenshotKeyModifiers(Windows::System::VirtualKeyModifiers value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys)->put_TakeScreenshotKeyModifiers(value));
}

template <typename D> Windows::System::VirtualKeyModifiers impl_IAppCaptureAlternateShortcutKeys<D>::TakeScreenshotKeyModifiers() const
{
    Windows::System::VirtualKeyModifiers value {};
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys)->get_TakeScreenshotKeyModifiers(&value));
    return value;
}

template <typename D> void impl_IAppCaptureAlternateShortcutKeys<D>::ToggleRecordingIndicatorKey(Windows::System::VirtualKey value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys)->put_ToggleRecordingIndicatorKey(value));
}

template <typename D> Windows::System::VirtualKey impl_IAppCaptureAlternateShortcutKeys<D>::ToggleRecordingIndicatorKey() const
{
    Windows::System::VirtualKey value {};
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys)->get_ToggleRecordingIndicatorKey(&value));
    return value;
}

template <typename D> void impl_IAppCaptureAlternateShortcutKeys<D>::ToggleRecordingIndicatorKeyModifiers(Windows::System::VirtualKeyModifiers value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys)->put_ToggleRecordingIndicatorKeyModifiers(value));
}

template <typename D> Windows::System::VirtualKeyModifiers impl_IAppCaptureAlternateShortcutKeys<D>::ToggleRecordingIndicatorKeyModifiers() const
{
    Windows::System::VirtualKeyModifiers value {};
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys)->get_ToggleRecordingIndicatorKeyModifiers(&value));
    return value;
}

template <typename D> void impl_IAppCaptureAlternateShortcutKeys2<D>::ToggleMicrophoneCaptureKey(Windows::System::VirtualKey value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys2)->put_ToggleMicrophoneCaptureKey(value));
}

template <typename D> Windows::System::VirtualKey impl_IAppCaptureAlternateShortcutKeys2<D>::ToggleMicrophoneCaptureKey() const
{
    Windows::System::VirtualKey value {};
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys2)->get_ToggleMicrophoneCaptureKey(&value));
    return value;
}

template <typename D> void impl_IAppCaptureAlternateShortcutKeys2<D>::ToggleMicrophoneCaptureKeyModifiers(Windows::System::VirtualKeyModifiers value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys2)->put_ToggleMicrophoneCaptureKeyModifiers(value));
}

template <typename D> Windows::System::VirtualKeyModifiers impl_IAppCaptureAlternateShortcutKeys2<D>::ToggleMicrophoneCaptureKeyModifiers() const
{
    Windows::System::VirtualKeyModifiers value {};
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys2)->get_ToggleMicrophoneCaptureKeyModifiers(&value));
    return value;
}

template <typename D> void impl_IAppCaptureAlternateShortcutKeys3<D>::ToggleCameraCaptureKey(Windows::System::VirtualKey value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys3)->put_ToggleCameraCaptureKey(value));
}

template <typename D> Windows::System::VirtualKey impl_IAppCaptureAlternateShortcutKeys3<D>::ToggleCameraCaptureKey() const
{
    Windows::System::VirtualKey value {};
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys3)->get_ToggleCameraCaptureKey(&value));
    return value;
}

template <typename D> void impl_IAppCaptureAlternateShortcutKeys3<D>::ToggleCameraCaptureKeyModifiers(Windows::System::VirtualKeyModifiers value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys3)->put_ToggleCameraCaptureKeyModifiers(value));
}

template <typename D> Windows::System::VirtualKeyModifiers impl_IAppCaptureAlternateShortcutKeys3<D>::ToggleCameraCaptureKeyModifiers() const
{
    Windows::System::VirtualKeyModifiers value {};
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys3)->get_ToggleCameraCaptureKeyModifiers(&value));
    return value;
}

template <typename D> void impl_IAppCaptureAlternateShortcutKeys3<D>::ToggleBroadcastKey(Windows::System::VirtualKey value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys3)->put_ToggleBroadcastKey(value));
}

template <typename D> Windows::System::VirtualKey impl_IAppCaptureAlternateShortcutKeys3<D>::ToggleBroadcastKey() const
{
    Windows::System::VirtualKey value {};
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys3)->get_ToggleBroadcastKey(&value));
    return value;
}

template <typename D> void impl_IAppCaptureAlternateShortcutKeys3<D>::ToggleBroadcastKeyModifiers(Windows::System::VirtualKeyModifiers value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys3)->put_ToggleBroadcastKeyModifiers(value));
}

template <typename D> Windows::System::VirtualKeyModifiers impl_IAppCaptureAlternateShortcutKeys3<D>::ToggleBroadcastKeyModifiers() const
{
    Windows::System::VirtualKeyModifiers value {};
    check_hresult(WINRT_SHIM(IAppCaptureAlternateShortcutKeys3)->get_ToggleBroadcastKeyModifiers(&value));
    return value;
}

template <typename D> void impl_IAppCaptureSettings<D>::AppCaptureDestinationFolder(const Windows::Storage::StorageFolder & value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->put_AppCaptureDestinationFolder(get_abi(value)));
}

template <typename D> Windows::Storage::StorageFolder impl_IAppCaptureSettings<D>::AppCaptureDestinationFolder() const
{
    Windows::Storage::StorageFolder value { nullptr };
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->get_AppCaptureDestinationFolder(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppCaptureSettings<D>::AudioEncodingBitrate(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->put_AudioEncodingBitrate(value));
}

template <typename D> uint32_t impl_IAppCaptureSettings<D>::AudioEncodingBitrate() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->get_AudioEncodingBitrate(&value));
    return value;
}

template <typename D> void impl_IAppCaptureSettings<D>::IsAudioCaptureEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->put_IsAudioCaptureEnabled(value));
}

template <typename D> bool impl_IAppCaptureSettings<D>::IsAudioCaptureEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->get_IsAudioCaptureEnabled(&value));
    return value;
}

template <typename D> void impl_IAppCaptureSettings<D>::CustomVideoEncodingBitrate(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->put_CustomVideoEncodingBitrate(value));
}

template <typename D> uint32_t impl_IAppCaptureSettings<D>::CustomVideoEncodingBitrate() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->get_CustomVideoEncodingBitrate(&value));
    return value;
}

template <typename D> void impl_IAppCaptureSettings<D>::CustomVideoEncodingHeight(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->put_CustomVideoEncodingHeight(value));
}

template <typename D> uint32_t impl_IAppCaptureSettings<D>::CustomVideoEncodingHeight() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->get_CustomVideoEncodingHeight(&value));
    return value;
}

template <typename D> void impl_IAppCaptureSettings<D>::CustomVideoEncodingWidth(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->put_CustomVideoEncodingWidth(value));
}

template <typename D> uint32_t impl_IAppCaptureSettings<D>::CustomVideoEncodingWidth() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->get_CustomVideoEncodingWidth(&value));
    return value;
}

template <typename D> void impl_IAppCaptureSettings<D>::HistoricalBufferLength(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->put_HistoricalBufferLength(value));
}

template <typename D> uint32_t impl_IAppCaptureSettings<D>::HistoricalBufferLength() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->get_HistoricalBufferLength(&value));
    return value;
}

template <typename D> void impl_IAppCaptureSettings<D>::HistoricalBufferLengthUnit(Windows::Media::Capture::AppCaptureHistoricalBufferLengthUnit value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->put_HistoricalBufferLengthUnit(value));
}

template <typename D> Windows::Media::Capture::AppCaptureHistoricalBufferLengthUnit impl_IAppCaptureSettings<D>::HistoricalBufferLengthUnit() const
{
    Windows::Media::Capture::AppCaptureHistoricalBufferLengthUnit value {};
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->get_HistoricalBufferLengthUnit(&value));
    return value;
}

template <typename D> void impl_IAppCaptureSettings<D>::IsHistoricalCaptureEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->put_IsHistoricalCaptureEnabled(value));
}

template <typename D> bool impl_IAppCaptureSettings<D>::IsHistoricalCaptureEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->get_IsHistoricalCaptureEnabled(&value));
    return value;
}

template <typename D> void impl_IAppCaptureSettings<D>::IsHistoricalCaptureOnBatteryAllowed(bool value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->put_IsHistoricalCaptureOnBatteryAllowed(value));
}

template <typename D> bool impl_IAppCaptureSettings<D>::IsHistoricalCaptureOnBatteryAllowed() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->get_IsHistoricalCaptureOnBatteryAllowed(&value));
    return value;
}

template <typename D> void impl_IAppCaptureSettings<D>::IsHistoricalCaptureOnWirelessDisplayAllowed(bool value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->put_IsHistoricalCaptureOnWirelessDisplayAllowed(value));
}

template <typename D> bool impl_IAppCaptureSettings<D>::IsHistoricalCaptureOnWirelessDisplayAllowed() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->get_IsHistoricalCaptureOnWirelessDisplayAllowed(&value));
    return value;
}

template <typename D> void impl_IAppCaptureSettings<D>::MaximumRecordLength(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->put_MaximumRecordLength(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_IAppCaptureSettings<D>::MaximumRecordLength() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->get_MaximumRecordLength(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppCaptureSettings<D>::ScreenshotDestinationFolder(const Windows::Storage::StorageFolder & value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->put_ScreenshotDestinationFolder(get_abi(value)));
}

template <typename D> Windows::Storage::StorageFolder impl_IAppCaptureSettings<D>::ScreenshotDestinationFolder() const
{
    Windows::Storage::StorageFolder value { nullptr };
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->get_ScreenshotDestinationFolder(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppCaptureSettings<D>::VideoEncodingBitrateMode(Windows::Media::Capture::AppCaptureVideoEncodingBitrateMode value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->put_VideoEncodingBitrateMode(value));
}

template <typename D> Windows::Media::Capture::AppCaptureVideoEncodingBitrateMode impl_IAppCaptureSettings<D>::VideoEncodingBitrateMode() const
{
    Windows::Media::Capture::AppCaptureVideoEncodingBitrateMode value {};
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->get_VideoEncodingBitrateMode(&value));
    return value;
}

template <typename D> void impl_IAppCaptureSettings<D>::VideoEncodingResolutionMode(Windows::Media::Capture::AppCaptureVideoEncodingResolutionMode value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->put_VideoEncodingResolutionMode(value));
}

template <typename D> Windows::Media::Capture::AppCaptureVideoEncodingResolutionMode impl_IAppCaptureSettings<D>::VideoEncodingResolutionMode() const
{
    Windows::Media::Capture::AppCaptureVideoEncodingResolutionMode value {};
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->get_VideoEncodingResolutionMode(&value));
    return value;
}

template <typename D> void impl_IAppCaptureSettings<D>::IsAppCaptureEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->put_IsAppCaptureEnabled(value));
}

template <typename D> bool impl_IAppCaptureSettings<D>::IsAppCaptureEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->get_IsAppCaptureEnabled(&value));
    return value;
}

template <typename D> bool impl_IAppCaptureSettings<D>::IsCpuConstrained() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->get_IsCpuConstrained(&value));
    return value;
}

template <typename D> bool impl_IAppCaptureSettings<D>::IsDisabledByPolicy() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->get_IsDisabledByPolicy(&value));
    return value;
}

template <typename D> bool impl_IAppCaptureSettings<D>::IsMemoryConstrained() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->get_IsMemoryConstrained(&value));
    return value;
}

template <typename D> bool impl_IAppCaptureSettings<D>::HasHardwareEncoder() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppCaptureSettings)->get_HasHardwareEncoder(&value));
    return value;
}

template <typename D> bool impl_IAppCaptureSettings2<D>::IsGpuConstrained() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppCaptureSettings2)->get_IsGpuConstrained(&value));
    return value;
}

template <typename D> Windows::Media::Capture::AppCaptureAlternateShortcutKeys impl_IAppCaptureSettings2<D>::AlternateShortcutKeys() const
{
    Windows::Media::Capture::AppCaptureAlternateShortcutKeys value { nullptr };
    check_hresult(WINRT_SHIM(IAppCaptureSettings2)->get_AlternateShortcutKeys(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppCaptureSettings3<D>::IsMicrophoneCaptureEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureSettings3)->put_IsMicrophoneCaptureEnabled(value));
}

template <typename D> bool impl_IAppCaptureSettings3<D>::IsMicrophoneCaptureEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppCaptureSettings3)->get_IsMicrophoneCaptureEnabled(&value));
    return value;
}

template <typename D> void impl_IAppCaptureSettings4<D>::IsMicrophoneCaptureEnabledByDefault(bool value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureSettings4)->put_IsMicrophoneCaptureEnabledByDefault(value));
}

template <typename D> bool impl_IAppCaptureSettings4<D>::IsMicrophoneCaptureEnabledByDefault() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppCaptureSettings4)->get_IsMicrophoneCaptureEnabledByDefault(&value));
    return value;
}

template <typename D> void impl_IAppCaptureSettings4<D>::SystemAudioGain(double value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureSettings4)->put_SystemAudioGain(value));
}

template <typename D> double impl_IAppCaptureSettings4<D>::SystemAudioGain() const
{
    double value {};
    check_hresult(WINRT_SHIM(IAppCaptureSettings4)->get_SystemAudioGain(&value));
    return value;
}

template <typename D> void impl_IAppCaptureSettings4<D>::MicrophoneGain(double value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureSettings4)->put_MicrophoneGain(value));
}

template <typename D> double impl_IAppCaptureSettings4<D>::MicrophoneGain() const
{
    double value {};
    check_hresult(WINRT_SHIM(IAppCaptureSettings4)->get_MicrophoneGain(&value));
    return value;
}

template <typename D> void impl_IAppCaptureSettings4<D>::VideoEncodingFrameRateMode(Windows::Media::Capture::AppCaptureVideoEncodingFrameRateMode value) const
{
    check_hresult(WINRT_SHIM(IAppCaptureSettings4)->put_VideoEncodingFrameRateMode(value));
}

template <typename D> Windows::Media::Capture::AppCaptureVideoEncodingFrameRateMode impl_IAppCaptureSettings4<D>::VideoEncodingFrameRateMode() const
{
    Windows::Media::Capture::AppCaptureVideoEncodingFrameRateMode value {};
    check_hresult(WINRT_SHIM(IAppCaptureSettings4)->get_VideoEncodingFrameRateMode(&value));
    return value;
}

template <typename D> void impl_ICameraOptionsUIStatics<D>::Show(const Windows::Media::Capture::MediaCapture & mediaCapture) const
{
    check_hresult(WINRT_SHIM(ICameraOptionsUIStatics)->abi_Show(get_abi(mediaCapture)));
}

template <typename D> bool impl_ISourceSuspensionChangedEventArgs<D>::IsAudioSuspended() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISourceSuspensionChangedEventArgs)->get_IsAudioSuspended(&value));
    return value;
}

template <typename D> bool impl_ISourceSuspensionChangedEventArgs<D>::IsVideoSuspended() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISourceSuspensionChangedEventArgs)->get_IsVideoSuspended(&value));
    return value;
}

template <typename D> Windows::Media::Core::IMediaSource impl_IScreenCapture<D>::AudioSource() const
{
    Windows::Media::Core::IMediaSource value;
    check_hresult(WINRT_SHIM(IScreenCapture)->get_AudioSource(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Core::IMediaSource impl_IScreenCapture<D>::VideoSource() const
{
    Windows::Media::Core::IMediaSource value;
    check_hresult(WINRT_SHIM(IScreenCapture)->get_VideoSource(put_abi(value)));
    return value;
}

template <typename D> bool impl_IScreenCapture<D>::IsAudioSuspended() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IScreenCapture)->get_IsAudioSuspended(&value));
    return value;
}

template <typename D> bool impl_IScreenCapture<D>::IsVideoSuspended() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IScreenCapture)->get_IsVideoSuspended(&value));
    return value;
}

template <typename D> event_token impl_IScreenCapture<D>::SourceSuspensionChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::ScreenCapture, Windows::Media::Capture::SourceSuspensionChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IScreenCapture)->add_SourceSuspensionChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IScreenCapture> impl_IScreenCapture<D>::SourceSuspensionChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::ScreenCapture, Windows::Media::Capture::SourceSuspensionChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IScreenCapture>(this, &ABI::Windows::Media::Capture::IScreenCapture::remove_SourceSuspensionChanged, SourceSuspensionChanged(handler));
}

template <typename D> void impl_IScreenCapture<D>::SourceSuspensionChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IScreenCapture)->remove_SourceSuspensionChanged(token));
}

template <typename D> Windows::Media::Capture::ScreenCapture impl_IScreenCaptureStatics<D>::GetForCurrentView() const
{
    Windows::Media::Capture::ScreenCapture value { nullptr };
    check_hresult(WINRT_SHIM(IScreenCaptureStatics)->abi_GetForCurrentView(put_abi(value)));
    return value;
}

inline Windows::Media::Capture::AppCapture AppCapture::GetForCurrentView()
{
    return get_activation_factory<AppCapture, IAppCaptureStatics>().GetForCurrentView();
}

inline Windows::Media::Capture::AppCaptureSettings AppCaptureManager::GetCurrentSettings()
{
    return get_activation_factory<AppCaptureManager, IAppCaptureManagerStatics>().GetCurrentSettings();
}

inline void AppCaptureManager::ApplySettings(const Windows::Media::Capture::AppCaptureSettings & appCaptureSettings)
{
    get_activation_factory<AppCaptureManager, IAppCaptureManagerStatics>().ApplySettings(appCaptureSettings);
}

inline CameraCaptureUI::CameraCaptureUI() :
    CameraCaptureUI(activate_instance<CameraCaptureUI>())
{}

inline void CameraOptionsUI::Show(const Windows::Media::Capture::MediaCapture & mediaCapture)
{
    get_activation_factory<CameraOptionsUI, ICameraOptionsUIStatics>().Show(mediaCapture);
}

inline MediaCapture::MediaCapture() :
    MediaCapture(activate_instance<MediaCapture>())
{}

inline bool MediaCapture::IsVideoProfileSupported(hstring_view videoDeviceId)
{
    return get_activation_factory<MediaCapture, IMediaCaptureStatics>().IsVideoProfileSupported(videoDeviceId);
}

inline Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> MediaCapture::FindAllVideoProfiles(hstring_view videoDeviceId)
{
    return get_activation_factory<MediaCapture, IMediaCaptureStatics>().FindAllVideoProfiles(videoDeviceId);
}

inline Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> MediaCapture::FindConcurrentProfiles(hstring_view videoDeviceId)
{
    return get_activation_factory<MediaCapture, IMediaCaptureStatics>().FindConcurrentProfiles(videoDeviceId);
}

inline Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::MediaCaptureVideoProfile> MediaCapture::FindKnownVideoProfiles(hstring_view videoDeviceId, Windows::Media::Capture::KnownVideoProfile name)
{
    return get_activation_factory<MediaCapture, IMediaCaptureStatics>().FindKnownVideoProfiles(videoDeviceId, name);
}

inline MediaCaptureInitializationSettings::MediaCaptureInitializationSettings() :
    MediaCaptureInitializationSettings(activate_instance<MediaCaptureInitializationSettings>())
{}

inline Windows::Media::Capture::ScreenCapture ScreenCapture::GetForCurrentView()
{
    return get_activation_factory<ScreenCapture, IScreenCaptureStatics>().GetForCurrentView();
}

}

}
#pragma warning(pop)
