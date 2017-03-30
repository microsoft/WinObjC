// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Perception.Provider.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::Perception::Provider {

template <typename H> struct impl_PerceptionStartFaceAuthenticationHandler : implements<impl_PerceptionStartFaceAuthenticationHandler<H>, abi<PerceptionStartFaceAuthenticationHandler>>, H
{
    impl_PerceptionStartFaceAuthenticationHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroup> sender, bool * result) noexcept override
    {
        try
        {
            *result = detach_abi((*this)(*reinterpret_cast<const Windows::Devices::Perception::Provider::PerceptionFaceAuthenticationGroup *>(&sender)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_PerceptionStopFaceAuthenticationHandler : implements<impl_PerceptionStopFaceAuthenticationHandler<H>, abi<PerceptionStopFaceAuthenticationHandler>>, H
{
    impl_PerceptionStopFaceAuthenticationHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroup> sender) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Devices::Perception::Provider::PerceptionFaceAuthenticationGroup *>(&sender));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Devices::Perception::Provider {

struct KnownPerceptionFrameKind
{
    KnownPerceptionFrameKind() = delete;
    static hstring Color();
    static hstring Depth();
    static hstring Infrared();
};

struct WINRT_EBO PerceptionControlGroup :
    Windows::Devices::Perception::Provider::IPerceptionControlGroup
{
    PerceptionControlGroup(std::nullptr_t) noexcept {}
    PerceptionControlGroup(iterable<hstring> ids);
};

struct WINRT_EBO PerceptionCorrelation :
    Windows::Devices::Perception::Provider::IPerceptionCorrelation
{
    PerceptionCorrelation(std::nullptr_t) noexcept {}
    PerceptionCorrelation(hstring_view targetId, const Windows::Foundation::Numerics::float3 & position, const Windows::Foundation::Numerics::quaternion & orientation);
};

struct WINRT_EBO PerceptionCorrelationGroup :
    Windows::Devices::Perception::Provider::IPerceptionCorrelationGroup
{
    PerceptionCorrelationGroup(std::nullptr_t) noexcept {}
    PerceptionCorrelationGroup(iterable<Windows::Devices::Perception::Provider::PerceptionCorrelation> relativeLocations);
};

struct WINRT_EBO PerceptionFaceAuthenticationGroup :
    Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroup
{
    PerceptionFaceAuthenticationGroup(std::nullptr_t) noexcept {}
    PerceptionFaceAuthenticationGroup(iterable<hstring> ids, const Windows::Devices::Perception::Provider::PerceptionStartFaceAuthenticationHandler & startHandler, const Windows::Devices::Perception::Provider::PerceptionStopFaceAuthenticationHandler & stopHandler);
};

struct WINRT_EBO PerceptionFrame :
    Windows::Devices::Perception::Provider::IPerceptionFrame
{
    PerceptionFrame(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PerceptionFrameProviderInfo :
    Windows::Devices::Perception::Provider::IPerceptionFrameProviderInfo
{
    PerceptionFrameProviderInfo(std::nullptr_t) noexcept {}
    PerceptionFrameProviderInfo();
};

struct PerceptionFrameProviderManagerService
{
    PerceptionFrameProviderManagerService() = delete;
    static void RegisterFrameProviderInfo(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionFrameProviderInfo & frameProviderInfo);
    static void UnregisterFrameProviderInfo(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionFrameProviderInfo & frameProviderInfo);
    static void RegisterFaceAuthenticationGroup(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionFaceAuthenticationGroup & faceAuthenticationGroup);
    static void UnregisterFaceAuthenticationGroup(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionFaceAuthenticationGroup & faceAuthenticationGroup);
    static void RegisterControlGroup(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionControlGroup & controlGroup);
    static void UnregisterControlGroup(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionControlGroup & controlGroup);
    static void RegisterCorrelationGroup(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionCorrelationGroup & correlationGroup);
    static void UnregisterCorrelationGroup(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionCorrelationGroup & correlationGroup);
    static void UpdateAvailabilityForProvider(const Windows::Devices::Perception::Provider::IPerceptionFrameProvider & provider, bool available);
    static void PublishFrameForProvider(const Windows::Devices::Perception::Provider::IPerceptionFrameProvider & provider, const Windows::Devices::Perception::Provider::PerceptionFrame & frame);
};

struct WINRT_EBO PerceptionPropertyChangeRequest :
    Windows::Devices::Perception::Provider::IPerceptionPropertyChangeRequest
{
    PerceptionPropertyChangeRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PerceptionVideoFrameAllocator :
    Windows::Devices::Perception::Provider::IPerceptionVideoFrameAllocator
{
    PerceptionVideoFrameAllocator(std::nullptr_t) noexcept {}
    PerceptionVideoFrameAllocator(uint32_t maxOutstandingFrameCountForWrite, Windows::Graphics::Imaging::BitmapPixelFormat format, const Windows::Foundation::Size & resolution, Windows::Graphics::Imaging::BitmapAlphaMode alpha);
};

}

}
