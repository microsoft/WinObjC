// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.Calls.Provider.0.h"
#include "Windows.Storage.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Calls::Provider {

struct __declspec(uuid("20613479-0ef9-4454-871c-afb66a14b6a5")) __declspec(novtable) IPhoneCallOrigin : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Category(hstring * value) = 0;
    virtual HRESULT __stdcall put_Category(hstring value) = 0;
    virtual HRESULT __stdcall get_CategoryDescription(hstring * value) = 0;
    virtual HRESULT __stdcall put_CategoryDescription(hstring value) = 0;
    virtual HRESULT __stdcall get_Location(hstring * value) = 0;
    virtual HRESULT __stdcall put_Location(hstring value) = 0;
};

struct __declspec(uuid("04c7e980-9ac2-4768-b536-b68da4957d02")) __declspec(novtable) IPhoneCallOrigin2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall put_DisplayName(hstring value) = 0;
};

struct __declspec(uuid("49330fb4-d1a7-43a2-aeee-c07b6dbaf068")) __declspec(novtable) IPhoneCallOrigin3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DisplayPicture(Windows::Storage::IStorageFile ** value) = 0;
    virtual HRESULT __stdcall put_DisplayPicture(Windows::Storage::IStorageFile * value) = 0;
};

struct __declspec(uuid("ccfc5a0a-9af7-6149-39d0-e076fcce1395")) __declspec(novtable) IPhoneCallOriginManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsCurrentAppActiveCallOriginApp(bool * value) = 0;
    virtual HRESULT __stdcall abi_ShowPhoneCallOriginSettingsUI() = 0;
    virtual HRESULT __stdcall abi_SetCallOrigin(GUID requestId, Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin * callOrigin) = 0;
};

struct __declspec(uuid("8bf3ee3f-40f4-4380-8c7c-aea2c9b8dd7a")) __declspec(novtable) IPhoneCallOriginManagerStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RequestSetAsActiveCallOriginAppAsync(Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::Calls::Provider::PhoneCallOrigin> { using default_interface = Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin; };

}

namespace Windows::ApplicationModel::Calls::Provider {

template <typename D>
struct WINRT_EBO impl_IPhoneCallOrigin
{
    hstring Category() const;
    void Category(hstring_view value) const;
    hstring CategoryDescription() const;
    void CategoryDescription(hstring_view value) const;
    hstring Location() const;
    void Location(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneCallOrigin2
{
    hstring DisplayName() const;
    void DisplayName(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneCallOrigin3
{
    Windows::Storage::StorageFile DisplayPicture() const;
    void DisplayPicture(const Windows::Storage::StorageFile & value) const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneCallOriginManagerStatics
{
    bool IsCurrentAppActiveCallOriginApp() const;
    void ShowPhoneCallOriginSettingsUI() const;
    void SetCallOrigin(GUID requestId, const Windows::ApplicationModel::Calls::Provider::PhoneCallOrigin & callOrigin) const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneCallOriginManagerStatics2
{
    Windows::Foundation::IAsyncOperation<bool> RequestSetAsActiveCallOriginAppAsync() const;
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin>
{
    using abi = ABI::Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin;
    template <typename D> using consume = Windows::ApplicationModel::Calls::Provider::impl_IPhoneCallOrigin<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin2>
{
    using abi = ABI::Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin2;
    template <typename D> using consume = Windows::ApplicationModel::Calls::Provider::impl_IPhoneCallOrigin2<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin3>
{
    using abi = ABI::Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin3;
    template <typename D> using consume = Windows::ApplicationModel::Calls::Provider::impl_IPhoneCallOrigin3<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics>
{
    using abi = ABI::Windows::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics;
    template <typename D> using consume = Windows::ApplicationModel::Calls::Provider::impl_IPhoneCallOriginManagerStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics2>
{
    using abi = ABI::Windows::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics2;
    template <typename D> using consume = Windows::ApplicationModel::Calls::Provider::impl_IPhoneCallOriginManagerStatics2<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::Provider::PhoneCallOrigin>
{
    using abi = ABI::Windows::ApplicationModel::Calls::Provider::PhoneCallOrigin;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.Provider.PhoneCallOrigin"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::Provider::PhoneCallOriginManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.Provider.PhoneCallOriginManager"; }
};

}

}
