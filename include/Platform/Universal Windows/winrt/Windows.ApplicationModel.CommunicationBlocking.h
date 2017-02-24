// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.ApplicationModel.CommunicationBlocking.3.h"
#include "Windows.ApplicationModel.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAccessManagerStatics> : produce_base<D, Windows::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAccessManagerStatics>
{
    HRESULT __stdcall get_IsBlockingActive(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsBlockingActive());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsBlockedNumberAsync(impl::abi_arg_in<hstring> number, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsBlockedNumberAsync(*reinterpret_cast<const hstring *>(&number)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowBlockNumbersUI(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> phoneNumbers, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ShowBlockNumbersUI(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&phoneNumbers)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowUnblockNumbersUI(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> phoneNumbers, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ShowUnblockNumbersUI(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&phoneNumbers)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowBlockedCallsUI() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowBlockedCallsUI();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowBlockedMessagesUI() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowBlockedMessagesUI();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics> : produce_base<D, Windows::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics>
{
    HRESULT __stdcall get_IsCurrentAppActiveBlockingApp(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCurrentAppActiveBlockingApp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowCommunicationBlockingSettingsUI() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowCommunicationBlockingSettingsUI();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics2> : produce_base<D, Windows::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics2>
{
    HRESULT __stdcall abi_RequestSetAsActiveBlockingAppAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestSetAsActiveBlockingAppAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::CommunicationBlocking {

template <typename D> bool impl_ICommunicationBlockingAppManagerStatics<D>::IsCurrentAppActiveBlockingApp() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommunicationBlockingAppManagerStatics)->get_IsCurrentAppActiveBlockingApp(&value));
    return value;
}

template <typename D> void impl_ICommunicationBlockingAppManagerStatics<D>::ShowCommunicationBlockingSettingsUI() const
{
    check_hresult(WINRT_SHIM(ICommunicationBlockingAppManagerStatics)->abi_ShowCommunicationBlockingSettingsUI());
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ICommunicationBlockingAppManagerStatics2<D>::RequestSetAsActiveBlockingAppAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(ICommunicationBlockingAppManagerStatics2)->abi_RequestSetAsActiveBlockingAppAsync(put_abi(result)));
    return result;
}

template <typename D> bool impl_ICommunicationBlockingAccessManagerStatics<D>::IsBlockingActive() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommunicationBlockingAccessManagerStatics)->get_IsBlockingActive(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ICommunicationBlockingAccessManagerStatics<D>::IsBlockedNumberAsync(hstring_view number) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(ICommunicationBlockingAccessManagerStatics)->abi_IsBlockedNumberAsync(get_abi(number), put_abi(result)));
    return result;
}

template <typename D> bool impl_ICommunicationBlockingAccessManagerStatics<D>::ShowBlockNumbersUI(iterable<hstring> phoneNumbers) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommunicationBlockingAccessManagerStatics)->abi_ShowBlockNumbersUI(get_abi(phoneNumbers), &value));
    return value;
}

template <typename D> bool impl_ICommunicationBlockingAccessManagerStatics<D>::ShowUnblockNumbersUI(iterable<hstring> phoneNumbers) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommunicationBlockingAccessManagerStatics)->abi_ShowUnblockNumbersUI(get_abi(phoneNumbers), &value));
    return value;
}

template <typename D> void impl_ICommunicationBlockingAccessManagerStatics<D>::ShowBlockedCallsUI() const
{
    check_hresult(WINRT_SHIM(ICommunicationBlockingAccessManagerStatics)->abi_ShowBlockedCallsUI());
}

template <typename D> void impl_ICommunicationBlockingAccessManagerStatics<D>::ShowBlockedMessagesUI() const
{
    check_hresult(WINRT_SHIM(ICommunicationBlockingAccessManagerStatics)->abi_ShowBlockedMessagesUI());
}

inline bool CommunicationBlockingAccessManager::IsBlockingActive()
{
    return get_activation_factory<CommunicationBlockingAccessManager, ICommunicationBlockingAccessManagerStatics>().IsBlockingActive();
}

inline Windows::Foundation::IAsyncOperation<bool> CommunicationBlockingAccessManager::IsBlockedNumberAsync(hstring_view number)
{
    return get_activation_factory<CommunicationBlockingAccessManager, ICommunicationBlockingAccessManagerStatics>().IsBlockedNumberAsync(number);
}

inline bool CommunicationBlockingAccessManager::ShowBlockNumbersUI(iterable<hstring> phoneNumbers)
{
    return get_activation_factory<CommunicationBlockingAccessManager, ICommunicationBlockingAccessManagerStatics>().ShowBlockNumbersUI(phoneNumbers);
}

inline bool CommunicationBlockingAccessManager::ShowUnblockNumbersUI(iterable<hstring> phoneNumbers)
{
    return get_activation_factory<CommunicationBlockingAccessManager, ICommunicationBlockingAccessManagerStatics>().ShowUnblockNumbersUI(phoneNumbers);
}

inline void CommunicationBlockingAccessManager::ShowBlockedCallsUI()
{
    get_activation_factory<CommunicationBlockingAccessManager, ICommunicationBlockingAccessManagerStatics>().ShowBlockedCallsUI();
}

inline void CommunicationBlockingAccessManager::ShowBlockedMessagesUI()
{
    get_activation_factory<CommunicationBlockingAccessManager, ICommunicationBlockingAccessManagerStatics>().ShowBlockedMessagesUI();
}

inline bool CommunicationBlockingAppManager::IsCurrentAppActiveBlockingApp()
{
    return get_activation_factory<CommunicationBlockingAppManager, ICommunicationBlockingAppManagerStatics>().IsCurrentAppActiveBlockingApp();
}

inline void CommunicationBlockingAppManager::ShowCommunicationBlockingSettingsUI()
{
    get_activation_factory<CommunicationBlockingAppManager, ICommunicationBlockingAppManagerStatics>().ShowCommunicationBlockingSettingsUI();
}

inline Windows::Foundation::IAsyncOperation<bool> CommunicationBlockingAppManager::RequestSetAsActiveBlockingAppAsync()
{
    return get_activation_factory<CommunicationBlockingAppManager, ICommunicationBlockingAppManagerStatics2>().RequestSetAsActiveBlockingAppAsync();
}

}

}
#pragma warning(pop)
