// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Management.Workplace.3.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Management::Workplace::IMdmAllowPolicyStatics> : produce_base<D, Windows::Management::Workplace::IMdmAllowPolicyStatics>
{
    HRESULT __stdcall abi_IsBrowserAllowed(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsBrowserAllowed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsCameraAllowed(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCameraAllowed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsMicrosoftAccountAllowed(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsMicrosoftAccountAllowed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsStoreAllowed(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsStoreAllowed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Management::Workplace::IMdmPolicyStatics2> : produce_base<D, Windows::Management::Workplace::IMdmPolicyStatics2>
{
    HRESULT __stdcall abi_GetMessagingSyncPolicy(Windows::Management::Workplace::MessagingSyncPolicy * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetMessagingSyncPolicy());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Management::Workplace::IWorkplaceSettingsStatics> : produce_base<D, Windows::Management::Workplace::IWorkplaceSettingsStatics>
{
    HRESULT __stdcall get_IsMicrosoftAccountOptional(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsMicrosoftAccountOptional());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Management::Workplace {

template <typename D> bool impl_IMdmAllowPolicyStatics<D>::IsBrowserAllowed() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMdmAllowPolicyStatics)->abi_IsBrowserAllowed(&value));
    return value;
}

template <typename D> bool impl_IMdmAllowPolicyStatics<D>::IsCameraAllowed() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMdmAllowPolicyStatics)->abi_IsCameraAllowed(&value));
    return value;
}

template <typename D> bool impl_IMdmAllowPolicyStatics<D>::IsMicrosoftAccountAllowed() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMdmAllowPolicyStatics)->abi_IsMicrosoftAccountAllowed(&value));
    return value;
}

template <typename D> bool impl_IMdmAllowPolicyStatics<D>::IsStoreAllowed() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMdmAllowPolicyStatics)->abi_IsStoreAllowed(&value));
    return value;
}

template <typename D> Windows::Management::Workplace::MessagingSyncPolicy impl_IMdmPolicyStatics2<D>::GetMessagingSyncPolicy() const
{
    Windows::Management::Workplace::MessagingSyncPolicy value {};
    check_hresult(WINRT_SHIM(IMdmPolicyStatics2)->abi_GetMessagingSyncPolicy(&value));
    return value;
}

template <typename D> bool impl_IWorkplaceSettingsStatics<D>::IsMicrosoftAccountOptional() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IWorkplaceSettingsStatics)->get_IsMicrosoftAccountOptional(&value));
    return value;
}

inline bool MdmPolicy::IsBrowserAllowed()
{
    return get_activation_factory<MdmPolicy, IMdmAllowPolicyStatics>().IsBrowserAllowed();
}

inline bool MdmPolicy::IsCameraAllowed()
{
    return get_activation_factory<MdmPolicy, IMdmAllowPolicyStatics>().IsCameraAllowed();
}

inline bool MdmPolicy::IsMicrosoftAccountAllowed()
{
    return get_activation_factory<MdmPolicy, IMdmAllowPolicyStatics>().IsMicrosoftAccountAllowed();
}

inline bool MdmPolicy::IsStoreAllowed()
{
    return get_activation_factory<MdmPolicy, IMdmAllowPolicyStatics>().IsStoreAllowed();
}

inline Windows::Management::Workplace::MessagingSyncPolicy MdmPolicy::GetMessagingSyncPolicy()
{
    return get_activation_factory<MdmPolicy, IMdmPolicyStatics2>().GetMessagingSyncPolicy();
}

inline bool WorkplaceSettings::IsMicrosoftAccountOptional()
{
    return get_activation_factory<WorkplaceSettings, IWorkplaceSettingsStatics>().IsMicrosoftAccountOptional();
}

}

}
#pragma warning(pop)
