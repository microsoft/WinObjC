// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Media.Playback.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Media.Protection.3.h"
#include "Windows.Media.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Media::Protection {

template <typename L> ComponentLoadFailedEventHandler::ComponentLoadFailedEventHandler(L lambda) :
    ComponentLoadFailedEventHandler(impl::make_delegate<impl_ComponentLoadFailedEventHandler<L>, ComponentLoadFailedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> ComponentLoadFailedEventHandler::ComponentLoadFailedEventHandler(F * function) :
    ComponentLoadFailedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> ComponentLoadFailedEventHandler::ComponentLoadFailedEventHandler(O * object, M method) :
    ComponentLoadFailedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void ComponentLoadFailedEventHandler::operator()(const Windows::Media::Protection::MediaProtectionManager & sender, const Windows::Media::Protection::ComponentLoadFailedEventArgs & e) const
{
    check_hresult((*(abi<ComponentLoadFailedEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> RebootNeededEventHandler::RebootNeededEventHandler(L lambda) :
    RebootNeededEventHandler(impl::make_delegate<impl_RebootNeededEventHandler<L>, RebootNeededEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> RebootNeededEventHandler::RebootNeededEventHandler(F * function) :
    RebootNeededEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> RebootNeededEventHandler::RebootNeededEventHandler(O * object, M method) :
    RebootNeededEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void RebootNeededEventHandler::operator()(const Windows::Media::Protection::MediaProtectionManager & sender) const
{
    check_hresult((*(abi<RebootNeededEventHandler> **)this)->abi_Invoke(get_abi(sender)));
}

template <typename L> ServiceRequestedEventHandler::ServiceRequestedEventHandler(L lambda) :
    ServiceRequestedEventHandler(impl::make_delegate<impl_ServiceRequestedEventHandler<L>, ServiceRequestedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> ServiceRequestedEventHandler::ServiceRequestedEventHandler(F * function) :
    ServiceRequestedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> ServiceRequestedEventHandler::ServiceRequestedEventHandler(O * object, M method) :
    ServiceRequestedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void ServiceRequestedEventHandler::operator()(const Windows::Media::Protection::MediaProtectionManager & sender, const Windows::Media::Protection::ServiceRequestedEventArgs & e) const
{
    check_hresult((*(abi<ServiceRequestedEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::Media::Protection::IComponentLoadFailedEventArgs> : produce_base<D, Windows::Media::Protection::IComponentLoadFailedEventArgs>
{
    HRESULT __stdcall get_Information(impl::abi_arg_out<Windows::Media::Protection::IRevocationAndRenewalInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Information());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Completion(impl::abi_arg_out<Windows::Media::Protection::IMediaProtectionServiceCompletion> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Completion());
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
struct produce<D, Windows::Media::Protection::IComponentRenewalStatics> : produce_base<D, Windows::Media::Protection::IComponentRenewalStatics>
{
    HRESULT __stdcall abi_RenewSystemComponentsAsync(impl::abi_arg_in<Windows::Media::Protection::IRevocationAndRenewalInformation> information, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<winrt::Windows::Media::Protection::RenewalStatus, uint32_t>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RenewSystemComponentsAsync(*reinterpret_cast<const Windows::Media::Protection::RevocationAndRenewalInformation *>(&information)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Protection::IHdcpSession> : produce_base<D, Windows::Media::Protection::IHdcpSession>
{
    HRESULT __stdcall abi_IsEffectiveProtectionAtLeast(Windows::Media::Protection::HdcpProtection protection, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsEffectiveProtectionAtLeast(protection));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetEffectiveProtection(impl::abi_arg_out<Windows::Foundation::IReference<winrt::Windows::Media::Protection::HdcpProtection>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetEffectiveProtection());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetDesiredMinProtectionAsync(Windows::Media::Protection::HdcpProtection protection, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Media::Protection::HdcpSetProtectionResult>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SetDesiredMinProtectionAsync(protection));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ProtectionChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Protection::HdcpSession, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ProtectionChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Protection::HdcpSession, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ProtectionChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProtectionChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Protection::IMediaProtectionManager> : produce_base<D, Windows::Media::Protection::IMediaProtectionManager>
{
    HRESULT __stdcall add_ServiceRequested(impl::abi_arg_in<Windows::Media::Protection::ServiceRequestedEventHandler> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().ServiceRequested(*reinterpret_cast<const Windows::Media::Protection::ServiceRequestedEventHandler *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ServiceRequested(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ServiceRequested(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_RebootNeeded(impl::abi_arg_in<Windows::Media::Protection::RebootNeededEventHandler> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().RebootNeeded(*reinterpret_cast<const Windows::Media::Protection::RebootNeededEventHandler *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_RebootNeeded(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RebootNeeded(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ComponentLoadFailed(impl::abi_arg_in<Windows::Media::Protection::ComponentLoadFailedEventHandler> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().ComponentLoadFailed(*reinterpret_cast<const Windows::Media::Protection::ComponentLoadFailedEventHandler *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ComponentLoadFailed(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ComponentLoadFailed(cookie);
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
};

template <typename D>
struct produce<D, Windows::Media::Protection::IMediaProtectionPMPServer> : produce_base<D, Windows::Media::Protection::IMediaProtectionPMPServer>
{
    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Foundation::Collections::IPropertySet> ppProperties) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *ppProperties = detach_abi(this->shim().Properties());
            return S_OK;
        }
        catch (...)
        {
            *ppProperties = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Protection::IMediaProtectionPMPServerFactory> : produce_base<D, Windows::Media::Protection::IMediaProtectionPMPServerFactory>
{
    HRESULT __stdcall abi_CreatePMPServer(impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> pProperties, impl::abi_arg_out<Windows::Media::Protection::IMediaProtectionPMPServer> ppObject) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *ppObject = detach_abi(this->shim().CreatePMPServer(*reinterpret_cast<const Windows::Foundation::Collections::IPropertySet *>(&pProperties)));
            return S_OK;
        }
        catch (...)
        {
            *ppObject = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Protection::IMediaProtectionServiceCompletion> : produce_base<D, Windows::Media::Protection::IMediaProtectionServiceCompletion>
{
    HRESULT __stdcall abi_Complete(bool success) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete(success);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Protection::IMediaProtectionServiceRequest> : produce_base<D, Windows::Media::Protection::IMediaProtectionServiceRequest>
{
    HRESULT __stdcall get_ProtectionSystem(GUID * system) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *system = detach_abi(this->shim().ProtectionSystem());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Type(GUID * type) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *type = detach_abi(this->shim().Type());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Protection::IProtectionCapabilities> : produce_base<D, Windows::Media::Protection::IProtectionCapabilities>
{
    HRESULT __stdcall abi_IsTypeSupported(impl::abi_arg_in<hstring> type, impl::abi_arg_in<hstring> keySystem, Windows::Media::Protection::ProtectionCapabilityResult * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsTypeSupported(*reinterpret_cast<const hstring *>(&type), *reinterpret_cast<const hstring *>(&keySystem)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Protection::IRevocationAndRenewalInformation> : produce_base<D, Windows::Media::Protection::IRevocationAndRenewalInformation>
{
    HRESULT __stdcall get_Items(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Media::Protection::RevocationAndRenewalItem>> items) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *items = detach_abi(this->shim().Items());
            return S_OK;
        }
        catch (...)
        {
            *items = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Protection::IRevocationAndRenewalItem> : produce_base<D, Windows::Media::Protection::IRevocationAndRenewalItem>
{
    HRESULT __stdcall get_Reasons(Windows::Media::Protection::RevocationAndRenewalReasons * reasons) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *reasons = detach_abi(this->shim().Reasons());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HeaderHash(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HeaderHash());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PublicKeyHash(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PublicKeyHash());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> name) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *name = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *name = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RenewalId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RenewalId());
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
struct produce<D, Windows::Media::Protection::IServiceRequestedEventArgs> : produce_base<D, Windows::Media::Protection::IServiceRequestedEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::Media::Protection::IMediaProtectionServiceRequest> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Request());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Completion(impl::abi_arg_out<Windows::Media::Protection::IMediaProtectionServiceCompletion> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Completion());
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
struct produce<D, Windows::Media::Protection::IServiceRequestedEventArgs2> : produce_base<D, Windows::Media::Protection::IServiceRequestedEventArgs2>
{
    HRESULT __stdcall get_MediaPlaybackItem(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackItem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MediaPlaybackItem());
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

namespace Windows::Media::Protection {

template <typename D> event_token impl_IMediaProtectionManager<D>::ServiceRequested(const Windows::Media::Protection::ServiceRequestedEventHandler & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IMediaProtectionManager)->add_ServiceRequested(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IMediaProtectionManager> impl_IMediaProtectionManager<D>::ServiceRequested(auto_revoke_t, const Windows::Media::Protection::ServiceRequestedEventHandler & handler) const
{
    return impl::make_event_revoker<D, IMediaProtectionManager>(this, &ABI::Windows::Media::Protection::IMediaProtectionManager::remove_ServiceRequested, ServiceRequested(handler));
}

template <typename D> void impl_IMediaProtectionManager<D>::ServiceRequested(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IMediaProtectionManager)->remove_ServiceRequested(cookie));
}

template <typename D> event_token impl_IMediaProtectionManager<D>::RebootNeeded(const Windows::Media::Protection::RebootNeededEventHandler & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IMediaProtectionManager)->add_RebootNeeded(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IMediaProtectionManager> impl_IMediaProtectionManager<D>::RebootNeeded(auto_revoke_t, const Windows::Media::Protection::RebootNeededEventHandler & handler) const
{
    return impl::make_event_revoker<D, IMediaProtectionManager>(this, &ABI::Windows::Media::Protection::IMediaProtectionManager::remove_RebootNeeded, RebootNeeded(handler));
}

template <typename D> void impl_IMediaProtectionManager<D>::RebootNeeded(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IMediaProtectionManager)->remove_RebootNeeded(cookie));
}

template <typename D> event_token impl_IMediaProtectionManager<D>::ComponentLoadFailed(const Windows::Media::Protection::ComponentLoadFailedEventHandler & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IMediaProtectionManager)->add_ComponentLoadFailed(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IMediaProtectionManager> impl_IMediaProtectionManager<D>::ComponentLoadFailed(auto_revoke_t, const Windows::Media::Protection::ComponentLoadFailedEventHandler & handler) const
{
    return impl::make_event_revoker<D, IMediaProtectionManager>(this, &ABI::Windows::Media::Protection::IMediaProtectionManager::remove_ComponentLoadFailed, ComponentLoadFailed(handler));
}

template <typename D> void impl_IMediaProtectionManager<D>::ComponentLoadFailed(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IMediaProtectionManager)->remove_ComponentLoadFailed(cookie));
}

template <typename D> Windows::Foundation::Collections::IPropertySet impl_IMediaProtectionManager<D>::Properties() const
{
    Windows::Foundation::Collections::IPropertySet value;
    check_hresult(WINRT_SHIM(IMediaProtectionManager)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaProtectionServiceCompletion<D>::Complete(bool success) const
{
    check_hresult(WINRT_SHIM(IMediaProtectionServiceCompletion)->abi_Complete(success));
}

template <typename D> Windows::Media::Protection::IMediaProtectionServiceRequest impl_IServiceRequestedEventArgs<D>::Request() const
{
    Windows::Media::Protection::IMediaProtectionServiceRequest value;
    check_hresult(WINRT_SHIM(IServiceRequestedEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Protection::MediaProtectionServiceCompletion impl_IServiceRequestedEventArgs<D>::Completion() const
{
    Windows::Media::Protection::MediaProtectionServiceCompletion value { nullptr };
    check_hresult(WINRT_SHIM(IServiceRequestedEventArgs)->get_Completion(put_abi(value)));
    return value;
}

template <typename D> GUID impl_IMediaProtectionServiceRequest<D>::ProtectionSystem() const
{
    GUID system {};
    check_hresult(WINRT_SHIM(IMediaProtectionServiceRequest)->get_ProtectionSystem(&system));
    return system;
}

template <typename D> GUID impl_IMediaProtectionServiceRequest<D>::Type() const
{
    GUID type {};
    check_hresult(WINRT_SHIM(IMediaProtectionServiceRequest)->get_Type(&type));
    return type;
}

template <typename D> Windows::Media::Playback::MediaPlaybackItem impl_IServiceRequestedEventArgs2<D>::MediaPlaybackItem() const
{
    Windows::Media::Playback::MediaPlaybackItem value { nullptr };
    check_hresult(WINRT_SHIM(IServiceRequestedEventArgs2)->get_MediaPlaybackItem(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Protection::RevocationAndRenewalInformation impl_IComponentLoadFailedEventArgs<D>::Information() const
{
    Windows::Media::Protection::RevocationAndRenewalInformation value { nullptr };
    check_hresult(WINRT_SHIM(IComponentLoadFailedEventArgs)->get_Information(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Protection::MediaProtectionServiceCompletion impl_IComponentLoadFailedEventArgs<D>::Completion() const
{
    Windows::Media::Protection::MediaProtectionServiceCompletion value { nullptr };
    check_hresult(WINRT_SHIM(IComponentLoadFailedEventArgs)->get_Completion(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Media::Protection::RevocationAndRenewalItem> impl_IRevocationAndRenewalInformation<D>::Items() const
{
    Windows::Foundation::Collections::IVector<Windows::Media::Protection::RevocationAndRenewalItem> items;
    check_hresult(WINRT_SHIM(IRevocationAndRenewalInformation)->get_Items(put_abi(items)));
    return items;
}

template <typename D> Windows::Media::Protection::RevocationAndRenewalReasons impl_IRevocationAndRenewalItem<D>::Reasons() const
{
    Windows::Media::Protection::RevocationAndRenewalReasons reasons {};
    check_hresult(WINRT_SHIM(IRevocationAndRenewalItem)->get_Reasons(&reasons));
    return reasons;
}

template <typename D> hstring impl_IRevocationAndRenewalItem<D>::HeaderHash() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IRevocationAndRenewalItem)->get_HeaderHash(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IRevocationAndRenewalItem<D>::PublicKeyHash() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IRevocationAndRenewalItem)->get_PublicKeyHash(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IRevocationAndRenewalItem<D>::Name() const
{
    hstring name;
    check_hresult(WINRT_SHIM(IRevocationAndRenewalItem)->get_Name(put_abi(name)));
    return name;
}

template <typename D> hstring impl_IRevocationAndRenewalItem<D>::RenewalId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IRevocationAndRenewalItem)->get_RenewalId(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Protection::MediaProtectionPMPServer impl_IMediaProtectionPMPServerFactory<D>::CreatePMPServer(const Windows::Foundation::Collections::IPropertySet & pProperties) const
{
    Windows::Media::Protection::MediaProtectionPMPServer ppObject { nullptr };
    check_hresult(WINRT_SHIM(IMediaProtectionPMPServerFactory)->abi_CreatePMPServer(get_abi(pProperties), put_abi(ppObject)));
    return ppObject;
}

template <typename D> Windows::Foundation::Collections::IPropertySet impl_IMediaProtectionPMPServer<D>::Properties() const
{
    Windows::Foundation::Collections::IPropertySet ppProperties;
    check_hresult(WINRT_SHIM(IMediaProtectionPMPServer)->get_Properties(put_abi(ppProperties)));
    return ppProperties;
}

template <typename D> Windows::Media::Protection::ProtectionCapabilityResult impl_IProtectionCapabilities<D>::IsTypeSupported(hstring_view type, hstring_view keySystem) const
{
    Windows::Media::Protection::ProtectionCapabilityResult value {};
    check_hresult(WINRT_SHIM(IProtectionCapabilities)->abi_IsTypeSupported(get_abi(type), get_abi(keySystem), &value));
    return value;
}

template <typename D> bool impl_IHdcpSession<D>::IsEffectiveProtectionAtLeast(Windows::Media::Protection::HdcpProtection protection) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IHdcpSession)->abi_IsEffectiveProtectionAtLeast(protection, &value));
    return value;
}

template <typename D> Windows::Foundation::IReference<winrt::Windows::Media::Protection::HdcpProtection> impl_IHdcpSession<D>::GetEffectiveProtection() const
{
    Windows::Foundation::IReference<winrt::Windows::Media::Protection::HdcpProtection> value;
    check_hresult(WINRT_SHIM(IHdcpSession)->abi_GetEffectiveProtection(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Media::Protection::HdcpSetProtectionResult> impl_IHdcpSession<D>::SetDesiredMinProtectionAsync(Windows::Media::Protection::HdcpProtection protection) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Media::Protection::HdcpSetProtectionResult> value;
    check_hresult(WINRT_SHIM(IHdcpSession)->abi_SetDesiredMinProtectionAsync(protection, put_abi(value)));
    return value;
}

template <typename D> event_token impl_IHdcpSession<D>::ProtectionChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Protection::HdcpSession, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IHdcpSession)->add_ProtectionChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IHdcpSession> impl_IHdcpSession<D>::ProtectionChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Protection::HdcpSession, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IHdcpSession>(this, &ABI::Windows::Media::Protection::IHdcpSession::remove_ProtectionChanged, ProtectionChanged(handler));
}

template <typename D> void impl_IHdcpSession<D>::ProtectionChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IHdcpSession)->remove_ProtectionChanged(token));
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<winrt::Windows::Media::Protection::RenewalStatus, uint32_t> impl_IComponentRenewalStatics<D>::RenewSystemComponentsAsync(const Windows::Media::Protection::RevocationAndRenewalInformation & information) const
{
    Windows::Foundation::IAsyncOperationWithProgress<winrt::Windows::Media::Protection::RenewalStatus, uint32_t> operation;
    check_hresult(WINRT_SHIM(IComponentRenewalStatics)->abi_RenewSystemComponentsAsync(get_abi(information), put_abi(operation)));
    return operation;
}

inline Windows::Foundation::IAsyncOperationWithProgress<winrt::Windows::Media::Protection::RenewalStatus, uint32_t> ComponentRenewal::RenewSystemComponentsAsync(const Windows::Media::Protection::RevocationAndRenewalInformation & information)
{
    return get_activation_factory<ComponentRenewal, IComponentRenewalStatics>().RenewSystemComponentsAsync(information);
}

inline HdcpSession::HdcpSession() :
    HdcpSession(activate_instance<HdcpSession>())
{}

inline MediaProtectionManager::MediaProtectionManager() :
    MediaProtectionManager(activate_instance<MediaProtectionManager>())
{}

inline MediaProtectionPMPServer::MediaProtectionPMPServer(const Windows::Foundation::Collections::IPropertySet & pProperties) :
    MediaProtectionPMPServer(get_activation_factory<MediaProtectionPMPServer, IMediaProtectionPMPServerFactory>().CreatePMPServer(pProperties))
{}

inline ProtectionCapabilities::ProtectionCapabilities() :
    ProtectionCapabilities(activate_instance<ProtectionCapabilities>())
{}

}

}
#pragma warning(pop)
