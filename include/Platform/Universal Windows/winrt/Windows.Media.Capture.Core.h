// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Media.Capture.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Media.Capture.Core.3.h"
#include "Windows.Media.Capture.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Media::Capture::Core::IVariablePhotoCapturedEventArgs> : produce_base<D, Windows::Media::Capture::Core::IVariablePhotoCapturedEventArgs>
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

    HRESULT __stdcall get_UsedFrameControllerIndex(impl::abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UsedFrameControllerIndex());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CapturedFrameControlValues(impl::abi_arg_out<Windows::Media::Capture::ICapturedFrameControlValues> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CapturedFrameControlValues());
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
struct produce<D, Windows::Media::Capture::Core::IVariablePhotoSequenceCapture> : produce_base<D, Windows::Media::Capture::Core::IVariablePhotoSequenceCapture>
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

    HRESULT __stdcall add_PhotoCaptured(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Capture::Core::VariablePhotoSequenceCapture, Windows::Media::Capture::Core::VariablePhotoCapturedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PhotoCaptured(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::Core::VariablePhotoSequenceCapture, Windows::Media::Capture::Core::VariablePhotoCapturedEventArgs> *>(&handler)));
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

    HRESULT __stdcall add_Stopped(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Capture::Core::VariablePhotoSequenceCapture, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Stopped(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::Core::VariablePhotoSequenceCapture, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Stopped(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stopped(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::Core::IVariablePhotoSequenceCapture2> : produce_base<D, Windows::Media::Capture::Core::IVariablePhotoSequenceCapture2>
{
    HRESULT __stdcall abi_UpdateSettingsAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().UpdateSettingsAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Media::Capture::Core {

template <typename D> Windows::Media::Capture::CapturedFrame impl_IVariablePhotoCapturedEventArgs<D>::Frame() const
{
    Windows::Media::Capture::CapturedFrame value { nullptr };
    check_hresult(WINRT_SHIM(IVariablePhotoCapturedEventArgs)->get_Frame(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IVariablePhotoCapturedEventArgs<D>::CaptureTimeOffset() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IVariablePhotoCapturedEventArgs)->get_CaptureTimeOffset(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_IVariablePhotoCapturedEventArgs<D>::UsedFrameControllerIndex() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(WINRT_SHIM(IVariablePhotoCapturedEventArgs)->get_UsedFrameControllerIndex(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::CapturedFrameControlValues impl_IVariablePhotoCapturedEventArgs<D>::CapturedFrameControlValues() const
{
    Windows::Media::Capture::CapturedFrameControlValues value { nullptr };
    check_hresult(WINRT_SHIM(IVariablePhotoCapturedEventArgs)->get_CapturedFrameControlValues(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IVariablePhotoSequenceCapture<D>::StartAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IVariablePhotoSequenceCapture)->abi_StartAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IVariablePhotoSequenceCapture<D>::StopAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IVariablePhotoSequenceCapture)->abi_StopAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IVariablePhotoSequenceCapture<D>::FinishAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IVariablePhotoSequenceCapture)->abi_FinishAsync(put_abi(operation)));
    return operation;
}

template <typename D> event_token impl_IVariablePhotoSequenceCapture<D>::PhotoCaptured(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::Core::VariablePhotoSequenceCapture, Windows::Media::Capture::Core::VariablePhotoCapturedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IVariablePhotoSequenceCapture)->add_PhotoCaptured(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IVariablePhotoSequenceCapture> impl_IVariablePhotoSequenceCapture<D>::PhotoCaptured(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::Core::VariablePhotoSequenceCapture, Windows::Media::Capture::Core::VariablePhotoCapturedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IVariablePhotoSequenceCapture>(this, &ABI::Windows::Media::Capture::Core::IVariablePhotoSequenceCapture::remove_PhotoCaptured, PhotoCaptured(handler));
}

template <typename D> void impl_IVariablePhotoSequenceCapture<D>::PhotoCaptured(event_token token) const
{
    check_hresult(WINRT_SHIM(IVariablePhotoSequenceCapture)->remove_PhotoCaptured(token));
}

template <typename D> event_token impl_IVariablePhotoSequenceCapture<D>::Stopped(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::Core::VariablePhotoSequenceCapture, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IVariablePhotoSequenceCapture)->add_Stopped(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IVariablePhotoSequenceCapture> impl_IVariablePhotoSequenceCapture<D>::Stopped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::Core::VariablePhotoSequenceCapture, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IVariablePhotoSequenceCapture>(this, &ABI::Windows::Media::Capture::Core::IVariablePhotoSequenceCapture::remove_Stopped, Stopped(handler));
}

template <typename D> void impl_IVariablePhotoSequenceCapture<D>::Stopped(event_token token) const
{
    check_hresult(WINRT_SHIM(IVariablePhotoSequenceCapture)->remove_Stopped(token));
}

template <typename D> Windows::Foundation::IAsyncAction impl_IVariablePhotoSequenceCapture2<D>::UpdateSettingsAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IVariablePhotoSequenceCapture2)->abi_UpdateSettingsAsync(put_abi(operation)));
    return operation;
}

}

}
#pragma warning(pop)
