// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Perception.People.3.h"
#include "Windows.Perception.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Perception::People::IHeadPose> : produce_base<D, Windows::Perception::People::IHeadPose>
{
    HRESULT __stdcall get_Position(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Position());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ForwardDirection(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ForwardDirection());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UpDirection(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UpDirection());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Perception::People {

template <typename D> Windows::Foundation::Numerics::float3 impl_IHeadPose<D>::Position() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(IHeadPose)->get_Position(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Numerics::float3 impl_IHeadPose<D>::ForwardDirection() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(IHeadPose)->get_ForwardDirection(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Numerics::float3 impl_IHeadPose<D>::UpDirection() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(IHeadPose)->get_UpDirection(put_abi(value)));
    return value;
}

}

}
#pragma warning(pop)
