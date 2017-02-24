// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.ApplicationModel.Calls.Provider.3.h"
#include "Windows.ApplicationModel.Calls.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin> : produce_base<D, Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin>
{
    HRESULT __stdcall get_Category(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Category());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Category(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Category(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CategoryDescription(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CategoryDescription());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CategoryDescription(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CategoryDescription(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Location(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Location());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Location(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Location(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin2> : produce_base<D, Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin2>
{
    HRESULT __stdcall get_DisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DisplayName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin3> : produce_base<D, Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin3>
{
    HRESULT __stdcall get_DisplayPicture(impl::abi_arg_out<Windows::Storage::IStorageFile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayPicture());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DisplayPicture(impl::abi_arg_in<Windows::Storage::IStorageFile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayPicture(*reinterpret_cast<const Windows::Storage::StorageFile *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics> : produce_base<D, Windows::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics>
{
    HRESULT __stdcall get_IsCurrentAppActiveCallOriginApp(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCurrentAppActiveCallOriginApp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowPhoneCallOriginSettingsUI() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowPhoneCallOriginSettingsUI();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetCallOrigin(GUID requestId, impl::abi_arg_in<Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin> callOrigin) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetCallOrigin(requestId, *reinterpret_cast<const Windows::ApplicationModel::Calls::Provider::PhoneCallOrigin *>(&callOrigin));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics2> : produce_base<D, Windows::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics2>
{
    HRESULT __stdcall abi_RequestSetAsActiveCallOriginAppAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestSetAsActiveCallOriginAppAsync());
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

namespace Windows::ApplicationModel::Calls::Provider {

template <typename D> hstring impl_IPhoneCallOrigin<D>::Category() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPhoneCallOrigin)->get_Category(put_abi(value)));
    return value;
}

template <typename D> void impl_IPhoneCallOrigin<D>::Category(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallOrigin)->put_Category(get_abi(value)));
}

template <typename D> hstring impl_IPhoneCallOrigin<D>::CategoryDescription() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPhoneCallOrigin)->get_CategoryDescription(put_abi(value)));
    return value;
}

template <typename D> void impl_IPhoneCallOrigin<D>::CategoryDescription(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallOrigin)->put_CategoryDescription(get_abi(value)));
}

template <typename D> hstring impl_IPhoneCallOrigin<D>::Location() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPhoneCallOrigin)->get_Location(put_abi(value)));
    return value;
}

template <typename D> void impl_IPhoneCallOrigin<D>::Location(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallOrigin)->put_Location(get_abi(value)));
}

template <typename D> hstring impl_IPhoneCallOrigin2<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPhoneCallOrigin2)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> void impl_IPhoneCallOrigin2<D>::DisplayName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallOrigin2)->put_DisplayName(get_abi(value)));
}

template <typename D> Windows::Storage::StorageFile impl_IPhoneCallOrigin3<D>::DisplayPicture() const
{
    Windows::Storage::StorageFile value { nullptr };
    check_hresult(WINRT_SHIM(IPhoneCallOrigin3)->get_DisplayPicture(put_abi(value)));
    return value;
}

template <typename D> void impl_IPhoneCallOrigin3<D>::DisplayPicture(const Windows::Storage::StorageFile & value) const
{
    check_hresult(WINRT_SHIM(IPhoneCallOrigin3)->put_DisplayPicture(get_abi(value)));
}

template <typename D> bool impl_IPhoneCallOriginManagerStatics<D>::IsCurrentAppActiveCallOriginApp() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPhoneCallOriginManagerStatics)->get_IsCurrentAppActiveCallOriginApp(&value));
    return value;
}

template <typename D> void impl_IPhoneCallOriginManagerStatics<D>::ShowPhoneCallOriginSettingsUI() const
{
    check_hresult(WINRT_SHIM(IPhoneCallOriginManagerStatics)->abi_ShowPhoneCallOriginSettingsUI());
}

template <typename D> void impl_IPhoneCallOriginManagerStatics<D>::SetCallOrigin(GUID requestId, const Windows::ApplicationModel::Calls::Provider::PhoneCallOrigin & callOrigin) const
{
    check_hresult(WINRT_SHIM(IPhoneCallOriginManagerStatics)->abi_SetCallOrigin(requestId, get_abi(callOrigin)));
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IPhoneCallOriginManagerStatics2<D>::RequestSetAsActiveCallOriginAppAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IPhoneCallOriginManagerStatics2)->abi_RequestSetAsActiveCallOriginAppAsync(put_abi(result)));
    return result;
}

inline PhoneCallOrigin::PhoneCallOrigin() :
    PhoneCallOrigin(activate_instance<PhoneCallOrigin>())
{}

inline bool PhoneCallOriginManager::IsCurrentAppActiveCallOriginApp()
{
    return get_activation_factory<PhoneCallOriginManager, IPhoneCallOriginManagerStatics>().IsCurrentAppActiveCallOriginApp();
}

inline void PhoneCallOriginManager::ShowPhoneCallOriginSettingsUI()
{
    get_activation_factory<PhoneCallOriginManager, IPhoneCallOriginManagerStatics>().ShowPhoneCallOriginSettingsUI();
}

inline void PhoneCallOriginManager::SetCallOrigin(GUID requestId, const Windows::ApplicationModel::Calls::Provider::PhoneCallOrigin & callOrigin)
{
    get_activation_factory<PhoneCallOriginManager, IPhoneCallOriginManagerStatics>().SetCallOrigin(requestId, callOrigin);
}

inline Windows::Foundation::IAsyncOperation<bool> PhoneCallOriginManager::RequestSetAsActiveCallOriginAppAsync()
{
    return get_activation_factory<PhoneCallOriginManager, IPhoneCallOriginManagerStatics2>().RequestSetAsActiveCallOriginAppAsync();
}

}

}
#pragma warning(pop)
