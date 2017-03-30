// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.Store.LicenseManagement.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Store::LicenseManagement {

struct __declspec(uuid("b5ac3ae0-da47-4f20-9a23-09182c9476ff")) __declspec(novtable) ILicenseManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_AddLicenseAsync(Windows::Storage::Streams::IBuffer * license, Windows::Foundation::IAsyncAction ** action) = 0;
    virtual HRESULT __stdcall abi_GetSatisfactionInfosAsync(Windows::Foundation::Collections::IIterable<hstring> * contentIds, Windows::Foundation::Collections::IIterable<hstring> * keyIds, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionResult> ** operation) = 0;
};

struct __declspec(uuid("3ccbb08f-db31-48d5-8384-fa17c81474e2")) __declspec(novtable) ILicenseSatisfactionInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SatisfiedByDevice(bool * value) = 0;
    virtual HRESULT __stdcall get_SatisfiedByOpenLicense(bool * value) = 0;
    virtual HRESULT __stdcall get_SatisfiedByTrial(bool * value) = 0;
    virtual HRESULT __stdcall get_SatisfiedByPass(bool * value) = 0;
    virtual HRESULT __stdcall get_SatisfiedByInstallMedia(bool * value) = 0;
    virtual HRESULT __stdcall get_SatisfiedBySignedInUser(bool * value) = 0;
    virtual HRESULT __stdcall get_IsSatisfied(bool * value) = 0;
};

struct __declspec(uuid("3c674f73-3c87-4ee1-8201-f428359bd3af")) __declspec(novtable) ILicenseSatisfactionResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LicenseSatisfactionInfos(Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionInfo> ** value) = 0;
    virtual HRESULT __stdcall get_ExtendedError(HRESULT * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionInfo> { using default_interface = Windows::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo; };
template <> struct traits<Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionResult> { using default_interface = Windows::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionResult; };

}

namespace Windows::ApplicationModel::Store::LicenseManagement {

template <typename D>
struct WINRT_EBO impl_ILicenseManagerStatics
{
    Windows::Foundation::IAsyncAction AddLicenseAsync(const Windows::Storage::Streams::IBuffer & license) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionResult> GetSatisfactionInfosAsync(iterable<hstring> contentIds, iterable<hstring> keyIds) const;
};

template <typename D>
struct WINRT_EBO impl_ILicenseSatisfactionInfo
{
    bool SatisfiedByDevice() const;
    bool SatisfiedByOpenLicense() const;
    bool SatisfiedByTrial() const;
    bool SatisfiedByPass() const;
    bool SatisfiedByInstallMedia() const;
    bool SatisfiedBySignedInUser() const;
    bool IsSatisfied() const;
};

template <typename D>
struct WINRT_EBO impl_ILicenseSatisfactionResult
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionInfo> LicenseSatisfactionInfos() const;
    HRESULT ExtendedError() const;
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::Store::LicenseManagement::ILicenseManagerStatics>
{
    using abi = ABI::Windows::ApplicationModel::Store::LicenseManagement::ILicenseManagerStatics;
    template <typename D> using consume = Windows::ApplicationModel::Store::LicenseManagement::impl_ILicenseManagerStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo>
{
    using abi = ABI::Windows::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo;
    template <typename D> using consume = Windows::ApplicationModel::Store::LicenseManagement::impl_ILicenseSatisfactionInfo<D>;
};

template <> struct traits<Windows::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionResult>
{
    using abi = ABI::Windows::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionResult;
    template <typename D> using consume = Windows::ApplicationModel::Store::LicenseManagement::impl_ILicenseSatisfactionResult<D>;
};

template <> struct traits<Windows::ApplicationModel::Store::LicenseManagement::LicenseManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Store.LicenseManagement.LicenseManager"; }
};

template <> struct traits<Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionInfo>
{
    using abi = ABI::Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Store.LicenseManagement.LicenseSatisfactionInfo"; }
};

template <> struct traits<Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionResult>
{
    using abi = ABI::Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Store.LicenseManagement.LicenseSatisfactionResult"; }
};

}

}
