// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Perception.3.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Perception::IPerceptionTimestamp> : produce_base<D, Windows::Perception::IPerceptionTimestamp>
{
    HRESULT __stdcall get_TargetTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PredictionAmount(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PredictionAmount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Perception::IPerceptionTimestampHelperStatics> : produce_base<D, Windows::Perception::IPerceptionTimestampHelperStatics>
{
    HRESULT __stdcall abi_FromHistoricalTargetTime(impl::abi_arg_in<Windows::Foundation::DateTime> targetTime, impl::abi_arg_out<Windows::Perception::IPerceptionTimestamp> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromHistoricalTargetTime(*reinterpret_cast<const Windows::Foundation::DateTime *>(&targetTime)));
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

namespace Windows::Perception {

template <typename D> Windows::Foundation::DateTime impl_IPerceptionTimestamp<D>::TargetTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IPerceptionTimestamp)->get_TargetTime(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IPerceptionTimestamp<D>::PredictionAmount() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IPerceptionTimestamp)->get_PredictionAmount(put_abi(value)));
    return value;
}

template <typename D> Windows::Perception::PerceptionTimestamp impl_IPerceptionTimestampHelperStatics<D>::FromHistoricalTargetTime(const Windows::Foundation::DateTime & targetTime) const
{
    Windows::Perception::PerceptionTimestamp value { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionTimestampHelperStatics)->abi_FromHistoricalTargetTime(get_abi(targetTime), put_abi(value)));
    return value;
}

inline Windows::Perception::PerceptionTimestamp PerceptionTimestampHelper::FromHistoricalTargetTime(const Windows::Foundation::DateTime & targetTime)
{
    return get_activation_factory<PerceptionTimestampHelper, IPerceptionTimestampHelperStatics>().FromHistoricalTargetTime(targetTime);
}

}

}
#pragma warning(pop)
