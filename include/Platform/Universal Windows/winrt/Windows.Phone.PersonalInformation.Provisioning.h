// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Phone.PersonalInformation.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Phone.PersonalInformation.Provisioning.3.h"
#include "Windows.Phone.PersonalInformation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Phone::PersonalInformation::Provisioning::IContactPartnerProvisioningManagerStatics> : produce_base<D, Windows::Phone::PersonalInformation::Provisioning::IContactPartnerProvisioningManagerStatics>
{
    HRESULT __stdcall abi_AssociateNetworkAccountAsync(impl::abi_arg_in<Windows::Phone::PersonalInformation::IContactStore> store, impl::abi_arg_in<hstring> networkName, impl::abi_arg_in<hstring> networkAccountId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().AssociateNetworkAccountAsync(*reinterpret_cast<const Windows::Phone::PersonalInformation::ContactStore *>(&store), *reinterpret_cast<const hstring *>(&networkName), *reinterpret_cast<const hstring *>(&networkAccountId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ImportVcardToSystemAsync(impl::abi_arg_in<Windows::Storage::Streams::IInputStream> stream, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ImportVcardToSystemAsync(*reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&stream)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Phone::PersonalInformation::Provisioning::IContactPartnerProvisioningManagerStatics2> : produce_base<D, Windows::Phone::PersonalInformation::Provisioning::IContactPartnerProvisioningManagerStatics2>
{
    HRESULT __stdcall abi_AssociateSocialNetworkAccountAsync(impl::abi_arg_in<Windows::Phone::PersonalInformation::IContactStore> store, impl::abi_arg_in<hstring> networkName, impl::abi_arg_in<hstring> networkAccountId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().AssociateSocialNetworkAccountAsync(*reinterpret_cast<const Windows::Phone::PersonalInformation::ContactStore *>(&store), *reinterpret_cast<const hstring *>(&networkName), *reinterpret_cast<const hstring *>(&networkAccountId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Phone::PersonalInformation::Provisioning::IMessagePartnerProvisioningManagerStatics> : produce_base<D, Windows::Phone::PersonalInformation::Provisioning::IMessagePartnerProvisioningManagerStatics>
{
    HRESULT __stdcall abi_ImportSmsToSystemAsync(bool incoming, bool read, impl::abi_arg_in<hstring> body, impl::abi_arg_in<hstring> sender, impl::abi_arg_in<Windows::Foundation::Collections::IVectorView<hstring>> recipients, impl::abi_arg_in<Windows::Foundation::DateTime> deliveryTime, impl::abi_arg_out<Windows::Foundation::IAsyncAction> action) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *action = detach_abi(this->shim().ImportSmsToSystemAsync(incoming, read, *reinterpret_cast<const hstring *>(&body), *reinterpret_cast<const hstring *>(&sender), *reinterpret_cast<const Windows::Foundation::Collections::IVectorView<hstring> *>(&recipients), *reinterpret_cast<const Windows::Foundation::DateTime *>(&deliveryTime)));
            return S_OK;
        }
        catch (...)
        {
            *action = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ImportMmsToSystemAsync(bool incoming, bool read, impl::abi_arg_in<hstring> subject, impl::abi_arg_in<hstring> sender, impl::abi_arg_in<Windows::Foundation::Collections::IVectorView<hstring>> recipients, impl::abi_arg_in<Windows::Foundation::DateTime> deliveryTime, impl::abi_arg_in<Windows::Foundation::Collections::IVectorView<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>>> attachments, impl::abi_arg_out<Windows::Foundation::IAsyncAction> action) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *action = detach_abi(this->shim().ImportMmsToSystemAsync(incoming, read, *reinterpret_cast<const hstring *>(&subject), *reinterpret_cast<const hstring *>(&sender), *reinterpret_cast<const Windows::Foundation::Collections::IVectorView<hstring> *>(&recipients), *reinterpret_cast<const Windows::Foundation::DateTime *>(&deliveryTime), *reinterpret_cast<const Windows::Foundation::Collections::IVectorView<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> *>(&attachments)));
            return S_OK;
        }
        catch (...)
        {
            *action = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Phone::PersonalInformation::Provisioning {

template <typename D> Windows::Foundation::IAsyncAction impl_IContactPartnerProvisioningManagerStatics<D>::AssociateNetworkAccountAsync(const Windows::Phone::PersonalInformation::ContactStore & store, hstring_view networkName, hstring_view networkAccountId) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IContactPartnerProvisioningManagerStatics)->abi_AssociateNetworkAccountAsync(get_abi(store), get_abi(networkName), get_abi(networkAccountId), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IContactPartnerProvisioningManagerStatics<D>::ImportVcardToSystemAsync(const Windows::Storage::Streams::IInputStream & stream) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IContactPartnerProvisioningManagerStatics)->abi_ImportVcardToSystemAsync(get_abi(stream), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IContactPartnerProvisioningManagerStatics2<D>::AssociateSocialNetworkAccountAsync(const Windows::Phone::PersonalInformation::ContactStore & store, hstring_view networkName, hstring_view networkAccountId) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IContactPartnerProvisioningManagerStatics2)->abi_AssociateSocialNetworkAccountAsync(get_abi(store), get_abi(networkName), get_abi(networkAccountId), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMessagePartnerProvisioningManagerStatics<D>::ImportSmsToSystemAsync(bool incoming, bool read, hstring_view body, hstring_view sender, vector_view<hstring> recipients, const Windows::Foundation::DateTime & deliveryTime) const
{
    Windows::Foundation::IAsyncAction action;
    check_hresult(WINRT_SHIM(IMessagePartnerProvisioningManagerStatics)->abi_ImportSmsToSystemAsync(incoming, read, get_abi(body), get_abi(sender), get_abi(recipients), get_abi(deliveryTime), put_abi(action)));
    return action;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMessagePartnerProvisioningManagerStatics<D>::ImportMmsToSystemAsync(bool incoming, bool read, hstring_view subject, hstring_view sender, vector_view<hstring> recipients, const Windows::Foundation::DateTime & deliveryTime, vector_view<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> attachments) const
{
    Windows::Foundation::IAsyncAction action;
    check_hresult(WINRT_SHIM(IMessagePartnerProvisioningManagerStatics)->abi_ImportMmsToSystemAsync(incoming, read, get_abi(subject), get_abi(sender), get_abi(recipients), get_abi(deliveryTime), get_abi(attachments), put_abi(action)));
    return action;
}

inline Windows::Foundation::IAsyncAction ContactPartnerProvisioningManager::AssociateNetworkAccountAsync(const Windows::Phone::PersonalInformation::ContactStore & store, hstring_view networkName, hstring_view networkAccountId)
{
    return get_activation_factory<ContactPartnerProvisioningManager, IContactPartnerProvisioningManagerStatics>().AssociateNetworkAccountAsync(store, networkName, networkAccountId);
}

inline Windows::Foundation::IAsyncAction ContactPartnerProvisioningManager::ImportVcardToSystemAsync(const Windows::Storage::Streams::IInputStream & stream)
{
    return get_activation_factory<ContactPartnerProvisioningManager, IContactPartnerProvisioningManagerStatics>().ImportVcardToSystemAsync(stream);
}

inline Windows::Foundation::IAsyncAction ContactPartnerProvisioningManager::AssociateSocialNetworkAccountAsync(const Windows::Phone::PersonalInformation::ContactStore & store, hstring_view networkName, hstring_view networkAccountId)
{
    return get_activation_factory<ContactPartnerProvisioningManager, IContactPartnerProvisioningManagerStatics2>().AssociateSocialNetworkAccountAsync(store, networkName, networkAccountId);
}

inline Windows::Foundation::IAsyncAction MessagePartnerProvisioningManager::ImportSmsToSystemAsync(bool incoming, bool read, hstring_view body, hstring_view sender, vector_view<hstring> recipients, const Windows::Foundation::DateTime & deliveryTime)
{
    return get_activation_factory<MessagePartnerProvisioningManager, IMessagePartnerProvisioningManagerStatics>().ImportSmsToSystemAsync(incoming, read, body, sender, recipients, deliveryTime);
}

inline Windows::Foundation::IAsyncAction MessagePartnerProvisioningManager::ImportMmsToSystemAsync(bool incoming, bool read, hstring_view subject, hstring_view sender, vector_view<hstring> recipients, const Windows::Foundation::DateTime & deliveryTime, vector_view<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> attachments)
{
    return get_activation_factory<MessagePartnerProvisioningManager, IMessagePartnerProvisioningManagerStatics>().ImportMmsToSystemAsync(incoming, read, subject, sender, recipients, deliveryTime, attachments);
}

}

}
#pragma warning(pop)
