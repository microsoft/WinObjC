// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Phone.PersonalInformation.Provisioning.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Phone.PersonalInformation.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Phone::PersonalInformation::Provisioning {

struct __declspec(uuid("c0d79a21-01af-4fd3-98cd-b3d656de15f4")) __declspec(novtable) IContactPartnerProvisioningManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_AssociateNetworkAccountAsync(Windows::Phone::PersonalInformation::IContactStore * store, hstring networkName, hstring networkAccountId, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_ImportVcardToSystemAsync(Windows::Storage::Streams::IInputStream * stream, Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("c26155f7-55ed-475d-9334-c5d484c30f1a")) __declspec(novtable) IContactPartnerProvisioningManagerStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_AssociateSocialNetworkAccountAsync(Windows::Phone::PersonalInformation::IContactStore * store, hstring networkName, hstring networkAccountId, Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("8a1b0850-73c5-457c-bc59-ed7d615c05a4")) __declspec(novtable) IMessagePartnerProvisioningManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ImportSmsToSystemAsync(bool incoming, bool read, hstring body, hstring sender, Windows::Foundation::Collections::IVectorView<hstring> * recipients, Windows::Foundation::DateTime deliveryTime, Windows::Foundation::IAsyncAction ** action) = 0;
    virtual HRESULT __stdcall abi_ImportMmsToSystemAsync(bool incoming, bool read, hstring subject, hstring sender, Windows::Foundation::Collections::IVectorView<hstring> * recipients, Windows::Foundation::DateTime deliveryTime, Windows::Foundation::Collections::IVectorView<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> * attachments, Windows::Foundation::IAsyncAction ** action) = 0;
};

}

namespace ABI {


}

namespace Windows::Phone::PersonalInformation::Provisioning {

template <typename D>
struct WINRT_EBO impl_IContactPartnerProvisioningManagerStatics
{
    Windows::Foundation::IAsyncAction AssociateNetworkAccountAsync(const Windows::Phone::PersonalInformation::ContactStore & store, hstring_view networkName, hstring_view networkAccountId) const;
    Windows::Foundation::IAsyncAction ImportVcardToSystemAsync(const Windows::Storage::Streams::IInputStream & stream) const;
};

template <typename D>
struct WINRT_EBO impl_IContactPartnerProvisioningManagerStatics2
{
    Windows::Foundation::IAsyncAction AssociateSocialNetworkAccountAsync(const Windows::Phone::PersonalInformation::ContactStore & store, hstring_view networkName, hstring_view networkAccountId) const;
};

template <typename D>
struct WINRT_EBO impl_IMessagePartnerProvisioningManagerStatics
{
    Windows::Foundation::IAsyncAction ImportSmsToSystemAsync(bool incoming, bool read, hstring_view body, hstring_view sender, vector_view<hstring> recipients, const Windows::Foundation::DateTime & deliveryTime) const;
    Windows::Foundation::IAsyncAction ImportMmsToSystemAsync(bool incoming, bool read, hstring_view subject, hstring_view sender, vector_view<hstring> recipients, const Windows::Foundation::DateTime & deliveryTime, vector_view<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> attachments) const;
};

}

namespace impl {

template <> struct traits<Windows::Phone::PersonalInformation::Provisioning::IContactPartnerProvisioningManagerStatics>
{
    using abi = ABI::Windows::Phone::PersonalInformation::Provisioning::IContactPartnerProvisioningManagerStatics;
    template <typename D> using consume = Windows::Phone::PersonalInformation::Provisioning::impl_IContactPartnerProvisioningManagerStatics<D>;
};

template <> struct traits<Windows::Phone::PersonalInformation::Provisioning::IContactPartnerProvisioningManagerStatics2>
{
    using abi = ABI::Windows::Phone::PersonalInformation::Provisioning::IContactPartnerProvisioningManagerStatics2;
    template <typename D> using consume = Windows::Phone::PersonalInformation::Provisioning::impl_IContactPartnerProvisioningManagerStatics2<D>;
};

template <> struct traits<Windows::Phone::PersonalInformation::Provisioning::IMessagePartnerProvisioningManagerStatics>
{
    using abi = ABI::Windows::Phone::PersonalInformation::Provisioning::IMessagePartnerProvisioningManagerStatics;
    template <typename D> using consume = Windows::Phone::PersonalInformation::Provisioning::impl_IMessagePartnerProvisioningManagerStatics<D>;
};

template <> struct traits<Windows::Phone::PersonalInformation::Provisioning::ContactPartnerProvisioningManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Phone.PersonalInformation.Provisioning.ContactPartnerProvisioningManager"; }
};

template <> struct traits<Windows::Phone::PersonalInformation::Provisioning::MessagePartnerProvisioningManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Phone.PersonalInformation.Provisioning.MessagePartnerProvisioningManager"; }
};

}

}
