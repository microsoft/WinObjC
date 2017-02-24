// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.ApplicationModel.Contacts.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.ApplicationModel.Contacts.Provider.3.h"
#include "Windows.ApplicationModel.Contacts.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::Provider::IContactPickerUI> : produce_base<D, Windows::ApplicationModel::Contacts::Provider::IContactPickerUI>
{
    HRESULT __stdcall abi_AddContact(impl::abi_arg_in<hstring> id, impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContact> contact, Windows::ApplicationModel::Contacts::Provider::AddContactResult * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().AddContact(*reinterpret_cast<const hstring *>(&id), *reinterpret_cast<const Windows::ApplicationModel::Contacts::Contact *>(&contact)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveContact(impl::abi_arg_in<hstring> id) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveContact(*reinterpret_cast<const hstring *>(&id));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ContainsContact(impl::abi_arg_in<hstring> id, bool * isContained) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *isContained = detach_abi(this->shim().ContainsContact(*reinterpret_cast<const hstring *>(&id)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DesiredFields(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DesiredFields());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SelectionMode(Windows::ApplicationModel::Contacts::ContactSelectionMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SelectionMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ContactRemoved(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::Provider::ContactPickerUI, Windows::ApplicationModel::Contacts::Provider::ContactRemovedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ContactRemoved(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::Provider::ContactPickerUI, Windows::ApplicationModel::Contacts::Provider::ContactRemovedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ContactRemoved(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContactRemoved(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::Provider::IContactPickerUI2> : produce_base<D, Windows::ApplicationModel::Contacts::Provider::IContactPickerUI2>
{
    HRESULT __stdcall abi_AddContact(impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContact> contact, Windows::ApplicationModel::Contacts::Provider::AddContactResult * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().AddContact(*reinterpret_cast<const Windows::ApplicationModel::Contacts::Contact *>(&contact)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DesiredFieldsWithContactFieldType(impl::abi_arg_out<Windows::Foundation::Collections::IVector<winrt::Windows::ApplicationModel::Contacts::ContactFieldType>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DesiredFieldsWithContactFieldType());
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
struct produce<D, Windows::ApplicationModel::Contacts::Provider::IContactRemovedEventArgs> : produce_base<D, Windows::ApplicationModel::Contacts::Provider::IContactRemovedEventArgs>
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
};

}

namespace Windows::ApplicationModel::Contacts::Provider {

template <typename D> hstring impl_IContactRemovedEventArgs<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactRemovedEventArgs)->get_Id(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Contacts::Provider::AddContactResult impl_IContactPickerUI<D>::AddContact(hstring_view id, const Windows::ApplicationModel::Contacts::Contact & contact) const
{
    Windows::ApplicationModel::Contacts::Provider::AddContactResult result {};
    check_hresult(WINRT_SHIM(IContactPickerUI)->abi_AddContact(get_abi(id), get_abi(contact), &result));
    return result;
}

template <typename D> void impl_IContactPickerUI<D>::RemoveContact(hstring_view id) const
{
    check_hresult(WINRT_SHIM(IContactPickerUI)->abi_RemoveContact(get_abi(id)));
}

template <typename D> bool impl_IContactPickerUI<D>::ContainsContact(hstring_view id) const
{
    bool isContained {};
    check_hresult(WINRT_SHIM(IContactPickerUI)->abi_ContainsContact(get_abi(id), &isContained));
    return isContained;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IContactPickerUI<D>::DesiredFields() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IContactPickerUI)->get_DesiredFields(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactSelectionMode impl_IContactPickerUI<D>::SelectionMode() const
{
    Windows::ApplicationModel::Contacts::ContactSelectionMode value {};
    check_hresult(WINRT_SHIM(IContactPickerUI)->get_SelectionMode(&value));
    return value;
}

template <typename D> event_token impl_IContactPickerUI<D>::ContactRemoved(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::Provider::ContactPickerUI, Windows::ApplicationModel::Contacts::Provider::ContactRemovedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IContactPickerUI)->add_ContactRemoved(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IContactPickerUI> impl_IContactPickerUI<D>::ContactRemoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::Provider::ContactPickerUI, Windows::ApplicationModel::Contacts::Provider::ContactRemovedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IContactPickerUI>(this, &ABI::Windows::ApplicationModel::Contacts::Provider::IContactPickerUI::remove_ContactRemoved, ContactRemoved(handler));
}

template <typename D> void impl_IContactPickerUI<D>::ContactRemoved(event_token token) const
{
    check_hresult(WINRT_SHIM(IContactPickerUI)->remove_ContactRemoved(token));
}

template <typename D> Windows::ApplicationModel::Contacts::Provider::AddContactResult impl_IContactPickerUI2<D>::AddContact(const Windows::ApplicationModel::Contacts::Contact & contact) const
{
    Windows::ApplicationModel::Contacts::Provider::AddContactResult result {};
    check_hresult(WINRT_SHIM(IContactPickerUI2)->abi_AddContact(get_abi(contact), &result));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVector<winrt::Windows::ApplicationModel::Contacts::ContactFieldType> impl_IContactPickerUI2<D>::DesiredFieldsWithContactFieldType() const
{
    Windows::Foundation::Collections::IVector<winrt::Windows::ApplicationModel::Contacts::ContactFieldType> value;
    check_hresult(WINRT_SHIM(IContactPickerUI2)->get_DesiredFieldsWithContactFieldType(put_abi(value)));
    return value;
}

}

}
#pragma warning(pop)
