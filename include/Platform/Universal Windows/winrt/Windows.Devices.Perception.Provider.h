// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Graphics.Imaging.3.h"
#include "internal/Windows.Devices.Perception.3.h"
#include "internal/Windows.Media.3.h"
#include "internal/Windows.Devices.Perception.Provider.3.h"
#include "Windows.Devices.Perception.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::Perception::Provider {

template <typename L> PerceptionStartFaceAuthenticationHandler::PerceptionStartFaceAuthenticationHandler(L lambda) :
    PerceptionStartFaceAuthenticationHandler(impl::make_delegate<impl_PerceptionStartFaceAuthenticationHandler<L>, PerceptionStartFaceAuthenticationHandler>(std::forward<L>(lambda)))
{}

template <typename F> PerceptionStartFaceAuthenticationHandler::PerceptionStartFaceAuthenticationHandler(F * function) :
    PerceptionStartFaceAuthenticationHandler([=](auto && ... args) { return function(args ...); })
{}

template <typename O, typename M> PerceptionStartFaceAuthenticationHandler::PerceptionStartFaceAuthenticationHandler(O * object, M method) :
    PerceptionStartFaceAuthenticationHandler([=](auto && ... args) { return ((*object).*(method))(args ...); })
{}

inline bool PerceptionStartFaceAuthenticationHandler::operator()(const Windows::Devices::Perception::Provider::PerceptionFaceAuthenticationGroup & sender) const
{
    bool result {};
    check_hresult((*(abi<PerceptionStartFaceAuthenticationHandler> **)this)->abi_Invoke(get_abi(sender), &result));
    return result;
}

template <typename L> PerceptionStopFaceAuthenticationHandler::PerceptionStopFaceAuthenticationHandler(L lambda) :
    PerceptionStopFaceAuthenticationHandler(impl::make_delegate<impl_PerceptionStopFaceAuthenticationHandler<L>, PerceptionStopFaceAuthenticationHandler>(std::forward<L>(lambda)))
{}

template <typename F> PerceptionStopFaceAuthenticationHandler::PerceptionStopFaceAuthenticationHandler(F * function) :
    PerceptionStopFaceAuthenticationHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> PerceptionStopFaceAuthenticationHandler::PerceptionStopFaceAuthenticationHandler(O * object, M method) :
    PerceptionStopFaceAuthenticationHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void PerceptionStopFaceAuthenticationHandler::operator()(const Windows::Devices::Perception::Provider::PerceptionFaceAuthenticationGroup & sender) const
{
    check_hresult((*(abi<PerceptionStopFaceAuthenticationHandler> **)this)->abi_Invoke(get_abi(sender)));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Perception::Provider::IKnownPerceptionFrameKindStatics> : produce_base<D, Windows::Devices::Perception::Provider::IKnownPerceptionFrameKindStatics>
{
    HRESULT __stdcall get_Color(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Color());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Depth(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Depth());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Infrared(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Infrared());
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
struct produce<D, Windows::Devices::Perception::Provider::IPerceptionControlGroup> : produce_base<D, Windows::Devices::Perception::Provider::IPerceptionControlGroup>
{
    HRESULT __stdcall get_FrameProviderIds(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrameProviderIds());
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
struct produce<D, Windows::Devices::Perception::Provider::IPerceptionControlGroupFactory> : produce_base<D, Windows::Devices::Perception::Provider::IPerceptionControlGroupFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> ids, impl::abi_arg_out<Windows::Devices::Perception::Provider::IPerceptionControlGroup> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&ids)));
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
struct produce<D, Windows::Devices::Perception::Provider::IPerceptionCorrelation> : produce_base<D, Windows::Devices::Perception::Provider::IPerceptionCorrelation>
{
    HRESULT __stdcall get_TargetId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall get_Orientation(impl::abi_arg_out<Windows::Foundation::Numerics::quaternion> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Orientation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Perception::Provider::IPerceptionCorrelationFactory> : produce_base<D, Windows::Devices::Perception::Provider::IPerceptionCorrelationFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> targetId, impl::abi_arg_in<Windows::Foundation::Numerics::float3> position, impl::abi_arg_in<Windows::Foundation::Numerics::quaternion> orientation, impl::abi_arg_out<Windows::Devices::Perception::Provider::IPerceptionCorrelation> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&targetId), *reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&position), *reinterpret_cast<const Windows::Foundation::Numerics::quaternion *>(&orientation)));
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
struct produce<D, Windows::Devices::Perception::Provider::IPerceptionCorrelationGroup> : produce_base<D, Windows::Devices::Perception::Provider::IPerceptionCorrelationGroup>
{
    HRESULT __stdcall get_RelativeLocations(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::Provider::PerceptionCorrelation>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RelativeLocations());
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
struct produce<D, Windows::Devices::Perception::Provider::IPerceptionCorrelationGroupFactory> : produce_base<D, Windows::Devices::Perception::Provider::IPerceptionCorrelationGroupFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Devices::Perception::Provider::PerceptionCorrelation>> relativeLocations, impl::abi_arg_out<Windows::Devices::Perception::Provider::IPerceptionCorrelationGroup> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Devices::Perception::Provider::PerceptionCorrelation> *>(&relativeLocations)));
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
struct produce<D, Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroup> : produce_base<D, Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroup>
{
    HRESULT __stdcall get_FrameProviderIds(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrameProviderIds());
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
struct produce<D, Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroupFactory> : produce_base<D, Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroupFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> ids, impl::abi_arg_in<Windows::Devices::Perception::Provider::PerceptionStartFaceAuthenticationHandler> startHandler, impl::abi_arg_in<Windows::Devices::Perception::Provider::PerceptionStopFaceAuthenticationHandler> stopHandler, impl::abi_arg_out<Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroup> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&ids), *reinterpret_cast<const Windows::Devices::Perception::Provider::PerceptionStartFaceAuthenticationHandler *>(&startHandler), *reinterpret_cast<const Windows::Devices::Perception::Provider::PerceptionStopFaceAuthenticationHandler *>(&stopHandler)));
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
struct produce<D, Windows::Devices::Perception::Provider::IPerceptionFrame> : produce_base<D, Windows::Devices::Perception::Provider::IPerceptionFrame>
{
    HRESULT __stdcall get_RelativeTime(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RelativeTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RelativeTime(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RelativeTime(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Foundation::Collections::IPropertySet> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Properties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FrameData(impl::abi_arg_out<Windows::Foundation::IMemoryBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrameData());
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
struct produce<D, Windows::Devices::Perception::Provider::IPerceptionFrameProvider> : produce_base<D, Windows::Devices::Perception::Provider::IPerceptionFrameProvider>
{
    HRESULT __stdcall get_FrameProviderInfo(impl::abi_arg_out<Windows::Devices::Perception::Provider::IPerceptionFrameProviderInfo> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FrameProviderInfo());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Available(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Available());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Foundation::Collections::IPropertySet> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Properties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Start() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Stop() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetProperty(impl::abi_arg_in<Windows::Devices::Perception::Provider::IPerceptionPropertyChangeRequest> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetProperty(*reinterpret_cast<const Windows::Devices::Perception::Provider::PerceptionPropertyChangeRequest *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Perception::Provider::IPerceptionFrameProviderInfo> : produce_base<D, Windows::Devices::Perception::Provider::IPerceptionFrameProviderInfo>
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

    HRESULT __stdcall put_Id(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Id(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall get_DeviceKind(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceKind());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DeviceKind(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DeviceKind(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FrameKind(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrameKind());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FrameKind(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FrameKind(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Hidden(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Hidden());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Hidden(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Hidden(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager> : produce_base<D, Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager>
{
    HRESULT __stdcall abi_GetFrameProvider(impl::abi_arg_in<Windows::Devices::Perception::Provider::IPerceptionFrameProviderInfo> frameProviderInfo, impl::abi_arg_out<Windows::Devices::Perception::Provider::IPerceptionFrameProvider> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetFrameProvider(*reinterpret_cast<const Windows::Devices::Perception::Provider::PerceptionFrameProviderInfo *>(&frameProviderInfo)));
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
struct produce<D, Windows::Devices::Perception::Provider::IPerceptionFrameProviderManagerServiceStatics> : produce_base<D, Windows::Devices::Perception::Provider::IPerceptionFrameProviderManagerServiceStatics>
{
    HRESULT __stdcall abi_RegisterFrameProviderInfo(impl::abi_arg_in<Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager> manager, impl::abi_arg_in<Windows::Devices::Perception::Provider::IPerceptionFrameProviderInfo> frameProviderInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RegisterFrameProviderInfo(*reinterpret_cast<const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager *>(&manager), *reinterpret_cast<const Windows::Devices::Perception::Provider::PerceptionFrameProviderInfo *>(&frameProviderInfo));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UnregisterFrameProviderInfo(impl::abi_arg_in<Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager> manager, impl::abi_arg_in<Windows::Devices::Perception::Provider::IPerceptionFrameProviderInfo> frameProviderInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UnregisterFrameProviderInfo(*reinterpret_cast<const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager *>(&manager), *reinterpret_cast<const Windows::Devices::Perception::Provider::PerceptionFrameProviderInfo *>(&frameProviderInfo));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RegisterFaceAuthenticationGroup(impl::abi_arg_in<Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager> manager, impl::abi_arg_in<Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroup> faceAuthenticationGroup) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RegisterFaceAuthenticationGroup(*reinterpret_cast<const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager *>(&manager), *reinterpret_cast<const Windows::Devices::Perception::Provider::PerceptionFaceAuthenticationGroup *>(&faceAuthenticationGroup));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UnregisterFaceAuthenticationGroup(impl::abi_arg_in<Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager> manager, impl::abi_arg_in<Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroup> faceAuthenticationGroup) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UnregisterFaceAuthenticationGroup(*reinterpret_cast<const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager *>(&manager), *reinterpret_cast<const Windows::Devices::Perception::Provider::PerceptionFaceAuthenticationGroup *>(&faceAuthenticationGroup));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RegisterControlGroup(impl::abi_arg_in<Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager> manager, impl::abi_arg_in<Windows::Devices::Perception::Provider::IPerceptionControlGroup> controlGroup) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RegisterControlGroup(*reinterpret_cast<const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager *>(&manager), *reinterpret_cast<const Windows::Devices::Perception::Provider::PerceptionControlGroup *>(&controlGroup));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UnregisterControlGroup(impl::abi_arg_in<Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager> manager, impl::abi_arg_in<Windows::Devices::Perception::Provider::IPerceptionControlGroup> controlGroup) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UnregisterControlGroup(*reinterpret_cast<const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager *>(&manager), *reinterpret_cast<const Windows::Devices::Perception::Provider::PerceptionControlGroup *>(&controlGroup));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RegisterCorrelationGroup(impl::abi_arg_in<Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager> manager, impl::abi_arg_in<Windows::Devices::Perception::Provider::IPerceptionCorrelationGroup> correlationGroup) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RegisterCorrelationGroup(*reinterpret_cast<const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager *>(&manager), *reinterpret_cast<const Windows::Devices::Perception::Provider::PerceptionCorrelationGroup *>(&correlationGroup));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UnregisterCorrelationGroup(impl::abi_arg_in<Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager> manager, impl::abi_arg_in<Windows::Devices::Perception::Provider::IPerceptionCorrelationGroup> correlationGroup) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UnregisterCorrelationGroup(*reinterpret_cast<const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager *>(&manager), *reinterpret_cast<const Windows::Devices::Perception::Provider::PerceptionCorrelationGroup *>(&correlationGroup));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateAvailabilityForProvider(impl::abi_arg_in<Windows::Devices::Perception::Provider::IPerceptionFrameProvider> provider, bool available) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UpdateAvailabilityForProvider(*reinterpret_cast<const Windows::Devices::Perception::Provider::IPerceptionFrameProvider *>(&provider), available);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PublishFrameForProvider(impl::abi_arg_in<Windows::Devices::Perception::Provider::IPerceptionFrameProvider> provider, impl::abi_arg_in<Windows::Devices::Perception::Provider::IPerceptionFrame> frame) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PublishFrameForProvider(*reinterpret_cast<const Windows::Devices::Perception::Provider::IPerceptionFrameProvider *>(&provider), *reinterpret_cast<const Windows::Devices::Perception::Provider::PerceptionFrame *>(&frame));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Perception::Provider::IPerceptionPropertyChangeRequest> : produce_base<D, Windows::Devices::Perception::Provider::IPerceptionPropertyChangeRequest>
{
    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Value(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Value());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Status(Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeStatus value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Status(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDeferral());
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
struct produce<D, Windows::Devices::Perception::Provider::IPerceptionVideoFrameAllocator> : produce_base<D, Windows::Devices::Perception::Provider::IPerceptionVideoFrameAllocator>
{
    HRESULT __stdcall abi_AllocateFrame(impl::abi_arg_out<Windows::Devices::Perception::Provider::IPerceptionFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllocateFrame());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CopyFromVideoFrame(impl::abi_arg_in<Windows::Media::IVideoFrame> frame, impl::abi_arg_out<Windows::Devices::Perception::Provider::IPerceptionFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CopyFromVideoFrame(*reinterpret_cast<const Windows::Media::VideoFrame *>(&frame)));
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
struct produce<D, Windows::Devices::Perception::Provider::IPerceptionVideoFrameAllocatorFactory> : produce_base<D, Windows::Devices::Perception::Provider::IPerceptionVideoFrameAllocatorFactory>
{
    HRESULT __stdcall abi_Create(uint32_t maxOutstandingFrameCountForWrite, Windows::Graphics::Imaging::BitmapPixelFormat format, impl::abi_arg_in<Windows::Foundation::Size> resolution, Windows::Graphics::Imaging::BitmapAlphaMode alpha, impl::abi_arg_out<Windows::Devices::Perception::Provider::IPerceptionVideoFrameAllocator> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(maxOutstandingFrameCountForWrite, format, *reinterpret_cast<const Windows::Foundation::Size *>(&resolution), alpha));
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

namespace Windows::Devices::Perception::Provider {

template <typename D> hstring impl_IKnownPerceptionFrameKindStatics<D>::Color() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionFrameKindStatics)->get_Color(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionFrameKindStatics<D>::Depth() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionFrameKindStatics)->get_Depth(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionFrameKindStatics<D>::Infrared() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionFrameKindStatics)->get_Infrared(put_abi(value)));
    return value;
}

template <typename D> void impl_IPerceptionFrameProviderManagerServiceStatics<D>::RegisterFrameProviderInfo(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionFrameProviderInfo & frameProviderInfo) const
{
    check_hresult(WINRT_SHIM(IPerceptionFrameProviderManagerServiceStatics)->abi_RegisterFrameProviderInfo(get_abi(manager), get_abi(frameProviderInfo)));
}

template <typename D> void impl_IPerceptionFrameProviderManagerServiceStatics<D>::UnregisterFrameProviderInfo(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionFrameProviderInfo & frameProviderInfo) const
{
    check_hresult(WINRT_SHIM(IPerceptionFrameProviderManagerServiceStatics)->abi_UnregisterFrameProviderInfo(get_abi(manager), get_abi(frameProviderInfo)));
}

template <typename D> void impl_IPerceptionFrameProviderManagerServiceStatics<D>::RegisterFaceAuthenticationGroup(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionFaceAuthenticationGroup & faceAuthenticationGroup) const
{
    check_hresult(WINRT_SHIM(IPerceptionFrameProviderManagerServiceStatics)->abi_RegisterFaceAuthenticationGroup(get_abi(manager), get_abi(faceAuthenticationGroup)));
}

template <typename D> void impl_IPerceptionFrameProviderManagerServiceStatics<D>::UnregisterFaceAuthenticationGroup(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionFaceAuthenticationGroup & faceAuthenticationGroup) const
{
    check_hresult(WINRT_SHIM(IPerceptionFrameProviderManagerServiceStatics)->abi_UnregisterFaceAuthenticationGroup(get_abi(manager), get_abi(faceAuthenticationGroup)));
}

template <typename D> void impl_IPerceptionFrameProviderManagerServiceStatics<D>::RegisterControlGroup(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionControlGroup & controlGroup) const
{
    check_hresult(WINRT_SHIM(IPerceptionFrameProviderManagerServiceStatics)->abi_RegisterControlGroup(get_abi(manager), get_abi(controlGroup)));
}

template <typename D> void impl_IPerceptionFrameProviderManagerServiceStatics<D>::UnregisterControlGroup(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionControlGroup & controlGroup) const
{
    check_hresult(WINRT_SHIM(IPerceptionFrameProviderManagerServiceStatics)->abi_UnregisterControlGroup(get_abi(manager), get_abi(controlGroup)));
}

template <typename D> void impl_IPerceptionFrameProviderManagerServiceStatics<D>::RegisterCorrelationGroup(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionCorrelationGroup & correlationGroup) const
{
    check_hresult(WINRT_SHIM(IPerceptionFrameProviderManagerServiceStatics)->abi_RegisterCorrelationGroup(get_abi(manager), get_abi(correlationGroup)));
}

template <typename D> void impl_IPerceptionFrameProviderManagerServiceStatics<D>::UnregisterCorrelationGroup(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionCorrelationGroup & correlationGroup) const
{
    check_hresult(WINRT_SHIM(IPerceptionFrameProviderManagerServiceStatics)->abi_UnregisterCorrelationGroup(get_abi(manager), get_abi(correlationGroup)));
}

template <typename D> void impl_IPerceptionFrameProviderManagerServiceStatics<D>::UpdateAvailabilityForProvider(const Windows::Devices::Perception::Provider::IPerceptionFrameProvider & provider, bool available) const
{
    check_hresult(WINRT_SHIM(IPerceptionFrameProviderManagerServiceStatics)->abi_UpdateAvailabilityForProvider(get_abi(provider), available));
}

template <typename D> void impl_IPerceptionFrameProviderManagerServiceStatics<D>::PublishFrameForProvider(const Windows::Devices::Perception::Provider::IPerceptionFrameProvider & provider, const Windows::Devices::Perception::Provider::PerceptionFrame & frame) const
{
    check_hresult(WINRT_SHIM(IPerceptionFrameProviderManagerServiceStatics)->abi_PublishFrameForProvider(get_abi(provider), get_abi(frame)));
}

template <typename D> hstring impl_IPerceptionFrameProviderInfo<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPerceptionFrameProviderInfo)->get_Id(put_abi(value)));
    return value;
}

template <typename D> void impl_IPerceptionFrameProviderInfo<D>::Id(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPerceptionFrameProviderInfo)->put_Id(get_abi(value)));
}

template <typename D> hstring impl_IPerceptionFrameProviderInfo<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPerceptionFrameProviderInfo)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> void impl_IPerceptionFrameProviderInfo<D>::DisplayName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPerceptionFrameProviderInfo)->put_DisplayName(get_abi(value)));
}

template <typename D> hstring impl_IPerceptionFrameProviderInfo<D>::DeviceKind() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPerceptionFrameProviderInfo)->get_DeviceKind(put_abi(value)));
    return value;
}

template <typename D> void impl_IPerceptionFrameProviderInfo<D>::DeviceKind(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPerceptionFrameProviderInfo)->put_DeviceKind(get_abi(value)));
}

template <typename D> hstring impl_IPerceptionFrameProviderInfo<D>::FrameKind() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPerceptionFrameProviderInfo)->get_FrameKind(put_abi(value)));
    return value;
}

template <typename D> void impl_IPerceptionFrameProviderInfo<D>::FrameKind(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPerceptionFrameProviderInfo)->put_FrameKind(get_abi(value)));
}

template <typename D> bool impl_IPerceptionFrameProviderInfo<D>::Hidden() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPerceptionFrameProviderInfo)->get_Hidden(&value));
    return value;
}

template <typename D> void impl_IPerceptionFrameProviderInfo<D>::Hidden(bool value) const
{
    check_hresult(WINRT_SHIM(IPerceptionFrameProviderInfo)->put_Hidden(value));
}

template <typename D> Windows::Devices::Perception::Provider::PerceptionControlGroup impl_IPerceptionControlGroupFactory<D>::Create(iterable<hstring> ids) const
{
    Windows::Devices::Perception::Provider::PerceptionControlGroup result { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionControlGroupFactory)->abi_Create(get_abi(ids), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IPerceptionControlGroup<D>::FrameProviderIds() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IPerceptionControlGroup)->get_FrameProviderIds(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Perception::Provider::PerceptionFaceAuthenticationGroup impl_IPerceptionFaceAuthenticationGroupFactory<D>::Create(iterable<hstring> ids, const Windows::Devices::Perception::Provider::PerceptionStartFaceAuthenticationHandler & startHandler, const Windows::Devices::Perception::Provider::PerceptionStopFaceAuthenticationHandler & stopHandler) const
{
    Windows::Devices::Perception::Provider::PerceptionFaceAuthenticationGroup result { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionFaceAuthenticationGroupFactory)->abi_Create(get_abi(ids), get_abi(startHandler), get_abi(stopHandler), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IPerceptionFaceAuthenticationGroup<D>::FrameProviderIds() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IPerceptionFaceAuthenticationGroup)->get_FrameProviderIds(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Perception::Provider::PerceptionCorrelation impl_IPerceptionCorrelationFactory<D>::Create(hstring_view targetId, const Windows::Foundation::Numerics::float3 & position, const Windows::Foundation::Numerics::quaternion & orientation) const
{
    Windows::Devices::Perception::Provider::PerceptionCorrelation result { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionCorrelationFactory)->abi_Create(get_abi(targetId), get_abi(position), get_abi(orientation), put_abi(result)));
    return result;
}

template <typename D> hstring impl_IPerceptionCorrelation<D>::TargetId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPerceptionCorrelation)->get_TargetId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Numerics::float3 impl_IPerceptionCorrelation<D>::Position() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(IPerceptionCorrelation)->get_Position(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Numerics::quaternion impl_IPerceptionCorrelation<D>::Orientation() const
{
    Windows::Foundation::Numerics::quaternion value {};
    check_hresult(WINRT_SHIM(IPerceptionCorrelation)->get_Orientation(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Perception::Provider::PerceptionCorrelationGroup impl_IPerceptionCorrelationGroupFactory<D>::Create(iterable<Windows::Devices::Perception::Provider::PerceptionCorrelation> relativeLocations) const
{
    Windows::Devices::Perception::Provider::PerceptionCorrelationGroup result { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionCorrelationGroupFactory)->abi_Create(get_abi(relativeLocations), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::Provider::PerceptionCorrelation> impl_IPerceptionCorrelationGroup<D>::RelativeLocations() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::Provider::PerceptionCorrelation> value;
    check_hresult(WINRT_SHIM(IPerceptionCorrelationGroup)->get_RelativeLocations(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IPerceptionFrame<D>::RelativeTime() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IPerceptionFrame)->get_RelativeTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IPerceptionFrame<D>::RelativeTime(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IPerceptionFrame)->put_RelativeTime(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::ValueSet impl_IPerceptionFrame<D>::Properties() const
{
    Windows::Foundation::Collections::ValueSet value { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionFrame)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IMemoryBuffer impl_IPerceptionFrame<D>::FrameData() const
{
    Windows::Foundation::IMemoryBuffer value;
    check_hresult(WINRT_SHIM(IPerceptionFrame)->get_FrameData(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Perception::Provider::PerceptionVideoFrameAllocator impl_IPerceptionVideoFrameAllocatorFactory<D>::Create(uint32_t maxOutstandingFrameCountForWrite, Windows::Graphics::Imaging::BitmapPixelFormat format, const Windows::Foundation::Size & resolution, Windows::Graphics::Imaging::BitmapAlphaMode alpha) const
{
    Windows::Devices::Perception::Provider::PerceptionVideoFrameAllocator result { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionVideoFrameAllocatorFactory)->abi_Create(maxOutstandingFrameCountForWrite, format, get_abi(resolution), alpha, put_abi(result)));
    return result;
}

template <typename D> hstring impl_IPerceptionPropertyChangeRequest<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPerceptionPropertyChangeRequest)->get_Name(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_IPerceptionPropertyChangeRequest<D>::Value() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IPerceptionPropertyChangeRequest)->get_Value(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeStatus impl_IPerceptionPropertyChangeRequest<D>::Status() const
{
    Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeStatus value {};
    check_hresult(WINRT_SHIM(IPerceptionPropertyChangeRequest)->get_Status(&value));
    return value;
}

template <typename D> void impl_IPerceptionPropertyChangeRequest<D>::Status(Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeStatus value) const
{
    check_hresult(WINRT_SHIM(IPerceptionPropertyChangeRequest)->put_Status(value));
}

template <typename D> Windows::Foundation::Deferral impl_IPerceptionPropertyChangeRequest<D>::GetDeferral() const
{
    Windows::Foundation::Deferral result { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionPropertyChangeRequest)->abi_GetDeferral(put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::Perception::Provider::IPerceptionFrameProvider impl_IPerceptionFrameProviderManager<D>::GetFrameProvider(const Windows::Devices::Perception::Provider::PerceptionFrameProviderInfo & frameProviderInfo) const
{
    Windows::Devices::Perception::Provider::IPerceptionFrameProvider result;
    check_hresult(WINRT_SHIM(IPerceptionFrameProviderManager)->abi_GetFrameProvider(get_abi(frameProviderInfo), put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::Perception::Provider::PerceptionFrameProviderInfo impl_IPerceptionFrameProvider<D>::FrameProviderInfo() const
{
    Windows::Devices::Perception::Provider::PerceptionFrameProviderInfo result { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionFrameProvider)->get_FrameProviderInfo(put_abi(result)));
    return result;
}

template <typename D> bool impl_IPerceptionFrameProvider<D>::Available() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPerceptionFrameProvider)->get_Available(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IPropertySet impl_IPerceptionFrameProvider<D>::Properties() const
{
    Windows::Foundation::Collections::IPropertySet value;
    check_hresult(WINRT_SHIM(IPerceptionFrameProvider)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> void impl_IPerceptionFrameProvider<D>::Start() const
{
    check_hresult(WINRT_SHIM(IPerceptionFrameProvider)->abi_Start());
}

template <typename D> void impl_IPerceptionFrameProvider<D>::Stop() const
{
    check_hresult(WINRT_SHIM(IPerceptionFrameProvider)->abi_Stop());
}

template <typename D> void impl_IPerceptionFrameProvider<D>::SetProperty(const Windows::Devices::Perception::Provider::PerceptionPropertyChangeRequest & value) const
{
    check_hresult(WINRT_SHIM(IPerceptionFrameProvider)->abi_SetProperty(get_abi(value)));
}

template <typename D> Windows::Devices::Perception::Provider::PerceptionFrame impl_IPerceptionVideoFrameAllocator<D>::AllocateFrame() const
{
    Windows::Devices::Perception::Provider::PerceptionFrame value { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionVideoFrameAllocator)->abi_AllocateFrame(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Perception::Provider::PerceptionFrame impl_IPerceptionVideoFrameAllocator<D>::CopyFromVideoFrame(const Windows::Media::VideoFrame & frame) const
{
    Windows::Devices::Perception::Provider::PerceptionFrame value { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionVideoFrameAllocator)->abi_CopyFromVideoFrame(get_abi(frame), put_abi(value)));
    return value;
}

inline hstring KnownPerceptionFrameKind::Color()
{
    return get_activation_factory<KnownPerceptionFrameKind, IKnownPerceptionFrameKindStatics>().Color();
}

inline hstring KnownPerceptionFrameKind::Depth()
{
    return get_activation_factory<KnownPerceptionFrameKind, IKnownPerceptionFrameKindStatics>().Depth();
}

inline hstring KnownPerceptionFrameKind::Infrared()
{
    return get_activation_factory<KnownPerceptionFrameKind, IKnownPerceptionFrameKindStatics>().Infrared();
}

inline PerceptionControlGroup::PerceptionControlGroup(iterable<hstring> ids) :
    PerceptionControlGroup(get_activation_factory<PerceptionControlGroup, IPerceptionControlGroupFactory>().Create(ids))
{}

inline PerceptionCorrelation::PerceptionCorrelation(hstring_view targetId, const Windows::Foundation::Numerics::float3 & position, const Windows::Foundation::Numerics::quaternion & orientation) :
    PerceptionCorrelation(get_activation_factory<PerceptionCorrelation, IPerceptionCorrelationFactory>().Create(targetId, position, orientation))
{}

inline PerceptionCorrelationGroup::PerceptionCorrelationGroup(iterable<Windows::Devices::Perception::Provider::PerceptionCorrelation> relativeLocations) :
    PerceptionCorrelationGroup(get_activation_factory<PerceptionCorrelationGroup, IPerceptionCorrelationGroupFactory>().Create(relativeLocations))
{}

inline PerceptionFaceAuthenticationGroup::PerceptionFaceAuthenticationGroup(iterable<hstring> ids, const Windows::Devices::Perception::Provider::PerceptionStartFaceAuthenticationHandler & startHandler, const Windows::Devices::Perception::Provider::PerceptionStopFaceAuthenticationHandler & stopHandler) :
    PerceptionFaceAuthenticationGroup(get_activation_factory<PerceptionFaceAuthenticationGroup, IPerceptionFaceAuthenticationGroupFactory>().Create(ids, startHandler, stopHandler))
{}

inline PerceptionFrameProviderInfo::PerceptionFrameProviderInfo() :
    PerceptionFrameProviderInfo(activate_instance<PerceptionFrameProviderInfo>())
{}

inline void PerceptionFrameProviderManagerService::RegisterFrameProviderInfo(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionFrameProviderInfo & frameProviderInfo)
{
    get_activation_factory<PerceptionFrameProviderManagerService, IPerceptionFrameProviderManagerServiceStatics>().RegisterFrameProviderInfo(manager, frameProviderInfo);
}

inline void PerceptionFrameProviderManagerService::UnregisterFrameProviderInfo(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionFrameProviderInfo & frameProviderInfo)
{
    get_activation_factory<PerceptionFrameProviderManagerService, IPerceptionFrameProviderManagerServiceStatics>().UnregisterFrameProviderInfo(manager, frameProviderInfo);
}

inline void PerceptionFrameProviderManagerService::RegisterFaceAuthenticationGroup(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionFaceAuthenticationGroup & faceAuthenticationGroup)
{
    get_activation_factory<PerceptionFrameProviderManagerService, IPerceptionFrameProviderManagerServiceStatics>().RegisterFaceAuthenticationGroup(manager, faceAuthenticationGroup);
}

inline void PerceptionFrameProviderManagerService::UnregisterFaceAuthenticationGroup(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionFaceAuthenticationGroup & faceAuthenticationGroup)
{
    get_activation_factory<PerceptionFrameProviderManagerService, IPerceptionFrameProviderManagerServiceStatics>().UnregisterFaceAuthenticationGroup(manager, faceAuthenticationGroup);
}

inline void PerceptionFrameProviderManagerService::RegisterControlGroup(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionControlGroup & controlGroup)
{
    get_activation_factory<PerceptionFrameProviderManagerService, IPerceptionFrameProviderManagerServiceStatics>().RegisterControlGroup(manager, controlGroup);
}

inline void PerceptionFrameProviderManagerService::UnregisterControlGroup(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionControlGroup & controlGroup)
{
    get_activation_factory<PerceptionFrameProviderManagerService, IPerceptionFrameProviderManagerServiceStatics>().UnregisterControlGroup(manager, controlGroup);
}

inline void PerceptionFrameProviderManagerService::RegisterCorrelationGroup(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionCorrelationGroup & correlationGroup)
{
    get_activation_factory<PerceptionFrameProviderManagerService, IPerceptionFrameProviderManagerServiceStatics>().RegisterCorrelationGroup(manager, correlationGroup);
}

inline void PerceptionFrameProviderManagerService::UnregisterCorrelationGroup(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionCorrelationGroup & correlationGroup)
{
    get_activation_factory<PerceptionFrameProviderManagerService, IPerceptionFrameProviderManagerServiceStatics>().UnregisterCorrelationGroup(manager, correlationGroup);
}

inline void PerceptionFrameProviderManagerService::UpdateAvailabilityForProvider(const Windows::Devices::Perception::Provider::IPerceptionFrameProvider & provider, bool available)
{
    get_activation_factory<PerceptionFrameProviderManagerService, IPerceptionFrameProviderManagerServiceStatics>().UpdateAvailabilityForProvider(provider, available);
}

inline void PerceptionFrameProviderManagerService::PublishFrameForProvider(const Windows::Devices::Perception::Provider::IPerceptionFrameProvider & provider, const Windows::Devices::Perception::Provider::PerceptionFrame & frame)
{
    get_activation_factory<PerceptionFrameProviderManagerService, IPerceptionFrameProviderManagerServiceStatics>().PublishFrameForProvider(provider, frame);
}

inline PerceptionVideoFrameAllocator::PerceptionVideoFrameAllocator(uint32_t maxOutstandingFrameCountForWrite, Windows::Graphics::Imaging::BitmapPixelFormat format, const Windows::Foundation::Size & resolution, Windows::Graphics::Imaging::BitmapAlphaMode alpha) :
    PerceptionVideoFrameAllocator(get_activation_factory<PerceptionVideoFrameAllocator, IPerceptionVideoFrameAllocatorFactory>().Create(maxOutstandingFrameCountForWrite, format, resolution, alpha))
{}

}

}
#pragma warning(pop)
