// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.Protection.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Media::Protection {

template <typename H> struct impl_ComponentLoadFailedEventHandler : implements<impl_ComponentLoadFailedEventHandler<H>, abi<ComponentLoadFailedEventHandler>>, H
{
    impl_ComponentLoadFailedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Media::Protection::IMediaProtectionManager> sender, impl::abi_arg_in<Windows::Media::Protection::IComponentLoadFailedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Media::Protection::MediaProtectionManager *>(&sender), *reinterpret_cast<const Windows::Media::Protection::ComponentLoadFailedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_RebootNeededEventHandler : implements<impl_RebootNeededEventHandler<H>, abi<RebootNeededEventHandler>>, H
{
    impl_RebootNeededEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Media::Protection::IMediaProtectionManager> sender) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Media::Protection::MediaProtectionManager *>(&sender));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_ServiceRequestedEventHandler : implements<impl_ServiceRequestedEventHandler<H>, abi<ServiceRequestedEventHandler>>, H
{
    impl_ServiceRequestedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Media::Protection::IMediaProtectionManager> sender, impl::abi_arg_in<Windows::Media::Protection::IServiceRequestedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Media::Protection::MediaProtectionManager *>(&sender), *reinterpret_cast<const Windows::Media::Protection::ServiceRequestedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Media::Protection {

struct WINRT_EBO ComponentLoadFailedEventArgs :
    Windows::Media::Protection::IComponentLoadFailedEventArgs
{
    ComponentLoadFailedEventArgs(std::nullptr_t) noexcept {}
};

struct ComponentRenewal
{
    ComponentRenewal() = delete;
    static Windows::Foundation::IAsyncOperationWithProgress<winrt::Windows::Media::Protection::RenewalStatus, uint32_t> RenewSystemComponentsAsync(const Windows::Media::Protection::RevocationAndRenewalInformation & information);
};

struct WINRT_EBO HdcpSession :
    Windows::Media::Protection::IHdcpSession
{
    HdcpSession(std::nullptr_t) noexcept {}
    HdcpSession();
};

struct WINRT_EBO MediaProtectionManager :
    Windows::Media::Protection::IMediaProtectionManager
{
    MediaProtectionManager(std::nullptr_t) noexcept {}
    MediaProtectionManager();
};

struct WINRT_EBO MediaProtectionPMPServer :
    Windows::Media::Protection::IMediaProtectionPMPServer
{
    MediaProtectionPMPServer(std::nullptr_t) noexcept {}
    MediaProtectionPMPServer(const Windows::Foundation::Collections::IPropertySet & pProperties);
};

struct WINRT_EBO MediaProtectionServiceCompletion :
    Windows::Media::Protection::IMediaProtectionServiceCompletion
{
    MediaProtectionServiceCompletion(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ProtectionCapabilities :
    Windows::Media::Protection::IProtectionCapabilities
{
    ProtectionCapabilities(std::nullptr_t) noexcept {}
    ProtectionCapabilities();
};

struct WINRT_EBO RevocationAndRenewalInformation :
    Windows::Media::Protection::IRevocationAndRenewalInformation
{
    RevocationAndRenewalInformation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RevocationAndRenewalItem :
    Windows::Media::Protection::IRevocationAndRenewalItem
{
    RevocationAndRenewalItem(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ServiceRequestedEventArgs :
    Windows::Media::Protection::IServiceRequestedEventArgs,
    impl::require<ServiceRequestedEventArgs, Windows::Media::Protection::IServiceRequestedEventArgs2>
{
    ServiceRequestedEventArgs(std::nullptr_t) noexcept {}
};

}

}
