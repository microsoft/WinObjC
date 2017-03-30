// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Media.Capture.Core.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Media.Capture.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::Capture::Core {

struct __declspec(uuid("d1eb4c5c-1b53-4e4a-8b5c-db7887ac949b")) __declspec(novtable) IVariablePhotoCapturedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Frame(Windows::Media::Capture::ICapturedFrame ** value) = 0;
    virtual HRESULT __stdcall get_CaptureTimeOffset(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_UsedFrameControllerIndex(Windows::Foundation::IReference<uint32_t> ** value) = 0;
    virtual HRESULT __stdcall get_CapturedFrameControlValues(Windows::Media::Capture::ICapturedFrameControlValues ** value) = 0;
};

struct __declspec(uuid("d0112d1d-031e-4041-a6d6-bd742476a8ee")) __declspec(novtable) IVariablePhotoSequenceCapture : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_StartAsync(Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_StopAsync(Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_FinishAsync(Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall add_PhotoCaptured(Windows::Foundation::TypedEventHandler<Windows::Media::Capture::Core::VariablePhotoSequenceCapture, Windows::Media::Capture::Core::VariablePhotoCapturedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PhotoCaptured(event_token token) = 0;
    virtual HRESULT __stdcall add_Stopped(Windows::Foundation::TypedEventHandler<Windows::Media::Capture::Core::VariablePhotoSequenceCapture, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Stopped(event_token token) = 0;
};

struct __declspec(uuid("fe2c62bc-50b0-43e3-917c-e3b92798942f")) __declspec(novtable) IVariablePhotoSequenceCapture2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_UpdateSettingsAsync(Windows::Foundation::IAsyncAction ** operation) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Media::Capture::Core::VariablePhotoCapturedEventArgs> { using default_interface = Windows::Media::Capture::Core::IVariablePhotoCapturedEventArgs; };
template <> struct traits<Windows::Media::Capture::Core::VariablePhotoSequenceCapture> { using default_interface = Windows::Media::Capture::Core::IVariablePhotoSequenceCapture; };

}

namespace Windows::Media::Capture::Core {

template <typename D>
struct WINRT_EBO impl_IVariablePhotoCapturedEventArgs
{
    Windows::Media::Capture::CapturedFrame Frame() const;
    Windows::Foundation::TimeSpan CaptureTimeOffset() const;
    Windows::Foundation::IReference<uint32_t> UsedFrameControllerIndex() const;
    Windows::Media::Capture::CapturedFrameControlValues CapturedFrameControlValues() const;
};

template <typename D>
struct WINRT_EBO impl_IVariablePhotoSequenceCapture
{
    Windows::Foundation::IAsyncAction StartAsync() const;
    Windows::Foundation::IAsyncAction StopAsync() const;
    Windows::Foundation::IAsyncAction FinishAsync() const;
    event_token PhotoCaptured(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::Core::VariablePhotoSequenceCapture, Windows::Media::Capture::Core::VariablePhotoCapturedEventArgs> & handler) const;
    using PhotoCaptured_revoker = event_revoker<IVariablePhotoSequenceCapture>;
    PhotoCaptured_revoker PhotoCaptured(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::Core::VariablePhotoSequenceCapture, Windows::Media::Capture::Core::VariablePhotoCapturedEventArgs> & handler) const;
    void PhotoCaptured(event_token token) const;
    event_token Stopped(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::Core::VariablePhotoSequenceCapture, Windows::Foundation::IInspectable> & handler) const;
    using Stopped_revoker = event_revoker<IVariablePhotoSequenceCapture>;
    Stopped_revoker Stopped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::Core::VariablePhotoSequenceCapture, Windows::Foundation::IInspectable> & handler) const;
    void Stopped(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IVariablePhotoSequenceCapture2
{
    Windows::Foundation::IAsyncAction UpdateSettingsAsync() const;
};

}

namespace impl {

template <> struct traits<Windows::Media::Capture::Core::IVariablePhotoCapturedEventArgs>
{
    using abi = ABI::Windows::Media::Capture::Core::IVariablePhotoCapturedEventArgs;
    template <typename D> using consume = Windows::Media::Capture::Core::impl_IVariablePhotoCapturedEventArgs<D>;
};

template <> struct traits<Windows::Media::Capture::Core::IVariablePhotoSequenceCapture>
{
    using abi = ABI::Windows::Media::Capture::Core::IVariablePhotoSequenceCapture;
    template <typename D> using consume = Windows::Media::Capture::Core::impl_IVariablePhotoSequenceCapture<D>;
};

template <> struct traits<Windows::Media::Capture::Core::IVariablePhotoSequenceCapture2>
{
    using abi = ABI::Windows::Media::Capture::Core::IVariablePhotoSequenceCapture2;
    template <typename D> using consume = Windows::Media::Capture::Core::impl_IVariablePhotoSequenceCapture2<D>;
};

template <> struct traits<Windows::Media::Capture::Core::VariablePhotoCapturedEventArgs>
{
    using abi = ABI::Windows::Media::Capture::Core::VariablePhotoCapturedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.Core.VariablePhotoCapturedEventArgs"; }
};

template <> struct traits<Windows::Media::Capture::Core::VariablePhotoSequenceCapture>
{
    using abi = ABI::Windows::Media::Capture::Core::VariablePhotoSequenceCapture;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.Core.VariablePhotoSequenceCapture"; }
};

}

}
