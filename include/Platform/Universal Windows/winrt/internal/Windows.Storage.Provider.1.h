// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Storage.Provider.0.h"
#include "Windows.Storage.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Storage::Provider {

struct __declspec(uuid("9fc90920-7bcf-4888-a81e-102d7034d7ce")) __declspec(novtable) ICachedFileUpdaterStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SetUpdateInformation(Windows::Storage::IStorageFile * file, hstring contentId, winrt::Windows::Storage::Provider::ReadActivationMode readMode, winrt::Windows::Storage::Provider::WriteActivationMode writeMode, winrt::Windows::Storage::Provider::CachedFileOptions options) = 0;
};

struct __declspec(uuid("9e6f41e6-baf2-4a97-b600-9333f5df80fd")) __declspec(novtable) ICachedFileUpdaterUI : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Title(hstring * value) = 0;
    virtual HRESULT __stdcall put_Title(hstring value) = 0;
    virtual HRESULT __stdcall get_UpdateTarget(winrt::Windows::Storage::Provider::CachedFileTarget * value) = 0;
    virtual HRESULT __stdcall add_FileUpdateRequested(Windows::Foundation::TypedEventHandler<Windows::Storage::Provider::CachedFileUpdaterUI, Windows::Storage::Provider::FileUpdateRequestedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_FileUpdateRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_UIRequested(Windows::Foundation::TypedEventHandler<Windows::Storage::Provider::CachedFileUpdaterUI, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_UIRequested(event_token token) = 0;
    virtual HRESULT __stdcall get_UIStatus(winrt::Windows::Storage::Provider::UIStatus * value) = 0;
};

struct __declspec(uuid("8856a21c-8699-4340-9f49-f7cad7fe8991")) __declspec(novtable) ICachedFileUpdaterUI2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UpdateRequest(Windows::Storage::Provider::IFileUpdateRequest ** value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Storage::Provider::IFileUpdateRequestDeferral ** value) = 0;
};

struct __declspec(uuid("40c82536-c1fe-4d93-a792-1e736bc70837")) __declspec(novtable) IFileUpdateRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ContentId(hstring * value) = 0;
    virtual HRESULT __stdcall get_File(Windows::Storage::IStorageFile ** value) = 0;
    virtual HRESULT __stdcall get_Status(winrt::Windows::Storage::Provider::FileUpdateStatus * value) = 0;
    virtual HRESULT __stdcall put_Status(winrt::Windows::Storage::Provider::FileUpdateStatus value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Storage::Provider::IFileUpdateRequestDeferral ** value) = 0;
    virtual HRESULT __stdcall abi_UpdateLocalFile(Windows::Storage::IStorageFile * value) = 0;
};

struct __declspec(uuid("82484648-bdbe-447b-a2ee-7afe6a032a94")) __declspec(novtable) IFileUpdateRequest2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UserInputNeededMessage(hstring * value) = 0;
    virtual HRESULT __stdcall put_UserInputNeededMessage(hstring value) = 0;
};

struct __declspec(uuid("ffcedb2b-8ade-44a5-bb00-164c4e72f13a")) __declspec(novtable) IFileUpdateRequestDeferral : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Complete() = 0;
};

struct __declspec(uuid("7b0a9342-3905-438d-aaef-78ae265f8dd2")) __declspec(novtable) IFileUpdateRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::Storage::Provider::IFileUpdateRequest ** value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Storage::Provider::CachedFileUpdaterUI> { using default_interface = Windows::Storage::Provider::ICachedFileUpdaterUI; };
template <> struct traits<Windows::Storage::Provider::FileUpdateRequest> { using default_interface = Windows::Storage::Provider::IFileUpdateRequest; };
template <> struct traits<Windows::Storage::Provider::FileUpdateRequestDeferral> { using default_interface = Windows::Storage::Provider::IFileUpdateRequestDeferral; };
template <> struct traits<Windows::Storage::Provider::FileUpdateRequestedEventArgs> { using default_interface = Windows::Storage::Provider::IFileUpdateRequestedEventArgs; };

}

namespace Windows::Storage::Provider {

template <typename D>
struct WINRT_EBO impl_ICachedFileUpdaterStatics
{
    void SetUpdateInformation(const Windows::Storage::IStorageFile & file, hstring_view contentId, Windows::Storage::Provider::ReadActivationMode readMode, Windows::Storage::Provider::WriteActivationMode writeMode, Windows::Storage::Provider::CachedFileOptions options) const;
};

template <typename D>
struct WINRT_EBO impl_ICachedFileUpdaterUI
{
    hstring Title() const;
    void Title(hstring_view value) const;
    Windows::Storage::Provider::CachedFileTarget UpdateTarget() const;
    event_token FileUpdateRequested(const Windows::Foundation::TypedEventHandler<Windows::Storage::Provider::CachedFileUpdaterUI, Windows::Storage::Provider::FileUpdateRequestedEventArgs> & handler) const;
    using FileUpdateRequested_revoker = event_revoker<ICachedFileUpdaterUI>;
    FileUpdateRequested_revoker FileUpdateRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Storage::Provider::CachedFileUpdaterUI, Windows::Storage::Provider::FileUpdateRequestedEventArgs> & handler) const;
    void FileUpdateRequested(event_token token) const;
    event_token UIRequested(const Windows::Foundation::TypedEventHandler<Windows::Storage::Provider::CachedFileUpdaterUI, Windows::Foundation::IInspectable> & handler) const;
    using UIRequested_revoker = event_revoker<ICachedFileUpdaterUI>;
    UIRequested_revoker UIRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Storage::Provider::CachedFileUpdaterUI, Windows::Foundation::IInspectable> & handler) const;
    void UIRequested(event_token token) const;
    Windows::Storage::Provider::UIStatus UIStatus() const;
};

template <typename D>
struct WINRT_EBO impl_ICachedFileUpdaterUI2
{
    Windows::Storage::Provider::FileUpdateRequest UpdateRequest() const;
    Windows::Storage::Provider::FileUpdateRequestDeferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IFileUpdateRequest
{
    hstring ContentId() const;
    Windows::Storage::StorageFile File() const;
    Windows::Storage::Provider::FileUpdateStatus Status() const;
    void Status(Windows::Storage::Provider::FileUpdateStatus value) const;
    Windows::Storage::Provider::FileUpdateRequestDeferral GetDeferral() const;
    void UpdateLocalFile(const Windows::Storage::IStorageFile & value) const;
};

template <typename D>
struct WINRT_EBO impl_IFileUpdateRequest2
{
    hstring UserInputNeededMessage() const;
    void UserInputNeededMessage(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IFileUpdateRequestDeferral
{
    void Complete() const;
};

template <typename D>
struct WINRT_EBO impl_IFileUpdateRequestedEventArgs
{
    Windows::Storage::Provider::FileUpdateRequest Request() const;
};

}

namespace impl {

template <> struct traits<Windows::Storage::Provider::ICachedFileUpdaterStatics>
{
    using abi = ABI::Windows::Storage::Provider::ICachedFileUpdaterStatics;
    template <typename D> using consume = Windows::Storage::Provider::impl_ICachedFileUpdaterStatics<D>;
};

template <> struct traits<Windows::Storage::Provider::ICachedFileUpdaterUI>
{
    using abi = ABI::Windows::Storage::Provider::ICachedFileUpdaterUI;
    template <typename D> using consume = Windows::Storage::Provider::impl_ICachedFileUpdaterUI<D>;
};

template <> struct traits<Windows::Storage::Provider::ICachedFileUpdaterUI2>
{
    using abi = ABI::Windows::Storage::Provider::ICachedFileUpdaterUI2;
    template <typename D> using consume = Windows::Storage::Provider::impl_ICachedFileUpdaterUI2<D>;
};

template <> struct traits<Windows::Storage::Provider::IFileUpdateRequest>
{
    using abi = ABI::Windows::Storage::Provider::IFileUpdateRequest;
    template <typename D> using consume = Windows::Storage::Provider::impl_IFileUpdateRequest<D>;
};

template <> struct traits<Windows::Storage::Provider::IFileUpdateRequest2>
{
    using abi = ABI::Windows::Storage::Provider::IFileUpdateRequest2;
    template <typename D> using consume = Windows::Storage::Provider::impl_IFileUpdateRequest2<D>;
};

template <> struct traits<Windows::Storage::Provider::IFileUpdateRequestDeferral>
{
    using abi = ABI::Windows::Storage::Provider::IFileUpdateRequestDeferral;
    template <typename D> using consume = Windows::Storage::Provider::impl_IFileUpdateRequestDeferral<D>;
};

template <> struct traits<Windows::Storage::Provider::IFileUpdateRequestedEventArgs>
{
    using abi = ABI::Windows::Storage::Provider::IFileUpdateRequestedEventArgs;
    template <typename D> using consume = Windows::Storage::Provider::impl_IFileUpdateRequestedEventArgs<D>;
};

template <> struct traits<Windows::Storage::Provider::CachedFileUpdater>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Storage.Provider.CachedFileUpdater"; }
};

template <> struct traits<Windows::Storage::Provider::CachedFileUpdaterUI>
{
    using abi = ABI::Windows::Storage::Provider::CachedFileUpdaterUI;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Storage.Provider.CachedFileUpdaterUI"; }
};

template <> struct traits<Windows::Storage::Provider::FileUpdateRequest>
{
    using abi = ABI::Windows::Storage::Provider::FileUpdateRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Storage.Provider.FileUpdateRequest"; }
};

template <> struct traits<Windows::Storage::Provider::FileUpdateRequestDeferral>
{
    using abi = ABI::Windows::Storage::Provider::FileUpdateRequestDeferral;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Storage.Provider.FileUpdateRequestDeferral"; }
};

template <> struct traits<Windows::Storage::Provider::FileUpdateRequestedEventArgs>
{
    using abi = ABI::Windows::Storage::Provider::FileUpdateRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Storage.Provider.FileUpdateRequestedEventArgs"; }
};

}

}
