// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.System.RemoteSystems.0.h"
#include "Windows.Networking.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::System::RemoteSystems {

struct __declspec(uuid("ed5838cd-1e10-4a8c-b4a6-4e5fd6f97721")) __declspec(novtable) IRemoteSystem : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_Kind(hstring * value) = 0;
    virtual HRESULT __stdcall get_Status(winrt::Windows::System::RemoteSystems::RemoteSystemStatus * value) = 0;
    virtual HRESULT __stdcall get_IsAvailableByProximity(bool * value) = 0;
};

struct __declspec(uuid("8f39560f-e534-4697-8836-7abea151516e")) __declspec(novtable) IRemoteSystemAddedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RemoteSystem(Windows::System::RemoteSystems::IRemoteSystem ** value) = 0;
};

struct __declspec(uuid("84ed4104-8d5e-4d72-8238-7621576c7a67")) __declspec(novtable) IRemoteSystemConnectionRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RemoteSystem(Windows::System::RemoteSystems::IRemoteSystem ** value) = 0;
};

struct __declspec(uuid("aa0a0a20-baeb-4575-b530-810bb9786334")) __declspec(novtable) IRemoteSystemConnectionRequestFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::System::RemoteSystems::IRemoteSystem * remoteSystem, Windows::System::RemoteSystems::IRemoteSystemConnectionRequest ** result) = 0;
};

struct __declspec(uuid("42d9041f-ee5a-43da-ac6a-6fee25460741")) __declspec(novtable) IRemoteSystemDiscoveryTypeFilter : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RemoteSystemDiscoveryType(winrt::Windows::System::RemoteSystems::RemoteSystemDiscoveryType * value) = 0;
};

struct __declspec(uuid("9f9eb993-c260-4161-92f2-9c021f23fe5d")) __declspec(novtable) IRemoteSystemDiscoveryTypeFilterFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(winrt::Windows::System::RemoteSystems::RemoteSystemDiscoveryType discoveryType, Windows::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilter ** result) = 0;
};

struct __declspec(uuid("4a3ba9e4-99eb-45eb-ba16-0367728ff374")) __declspec(novtable) IRemoteSystemFilter : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("38e1c9ec-22c3-4ef6-901a-bbb1c7aad4ed")) __declspec(novtable) IRemoteSystemKindFilter : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RemoteSystemKinds(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
};

struct __declspec(uuid("a1fb18ee-99ea-40bc-9a39-c670aa804a28")) __declspec(novtable) IRemoteSystemKindFilterFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Foundation::Collections::IIterable<hstring> * remoteSystemKinds, Windows::System::RemoteSystems::IRemoteSystemKindFilter ** result) = 0;
};

struct __declspec(uuid("f6317633-ab14-41d0-9553-796aadb882db")) __declspec(novtable) IRemoteSystemKindStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Phone(hstring * value) = 0;
    virtual HRESULT __stdcall get_Hub(hstring * value) = 0;
    virtual HRESULT __stdcall get_Holographic(hstring * value) = 0;
    virtual HRESULT __stdcall get_Desktop(hstring * value) = 0;
    virtual HRESULT __stdcall get_Xbox(hstring * value) = 0;
};

struct __declspec(uuid("8b3d16bb-7306-49ea-b7df-67d5714cb013")) __declspec(novtable) IRemoteSystemRemovedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RemoteSystemId(hstring * value) = 0;
};

struct __declspec(uuid("a485b392-ff2b-4b47-be62-743f2f140f30")) __declspec(novtable) IRemoteSystemStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FindByHostNameAsync(Windows::Networking::IHostName * hostName, Windows::Foundation::IAsyncOperation<Windows::System::RemoteSystems::RemoteSystem> ** operation) = 0;
    virtual HRESULT __stdcall abi_CreateWatcher(Windows::System::RemoteSystems::IRemoteSystemWatcher ** result) = 0;
    virtual HRESULT __stdcall abi_CreateWatcherWithFilters(Windows::Foundation::Collections::IIterable<Windows::System::RemoteSystems::IRemoteSystemFilter> * filters, Windows::System::RemoteSystems::IRemoteSystemWatcher ** result) = 0;
    virtual HRESULT __stdcall abi_RequestAccessAsync(Windows::Foundation::IAsyncOperation<winrt::Windows::System::RemoteSystems::RemoteSystemAccessStatus> ** operation) = 0;
};

struct __declspec(uuid("0c39514e-cbb6-4777-8534-2e0c521affa2")) __declspec(novtable) IRemoteSystemStatusTypeFilter : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RemoteSystemStatusType(winrt::Windows::System::RemoteSystems::RemoteSystemStatusType * value) = 0;
};

struct __declspec(uuid("33cf78fa-d724-4125-ac7a-8d281e44c949")) __declspec(novtable) IRemoteSystemStatusTypeFilterFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(winrt::Windows::System::RemoteSystems::RemoteSystemStatusType remoteSystemStatusType, Windows::System::RemoteSystems::IRemoteSystemStatusTypeFilter ** result) = 0;
};

struct __declspec(uuid("7502ff0e-dbcb-4155-b4ca-b30a04f27627")) __declspec(novtable) IRemoteSystemUpdatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RemoteSystem(Windows::System::RemoteSystems::IRemoteSystem ** value) = 0;
};

struct __declspec(uuid("5d600c7e-2c07-48c5-889c-455d2b099771")) __declspec(novtable) IRemoteSystemWatcher : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Start() = 0;
    virtual HRESULT __stdcall abi_Stop() = 0;
    virtual HRESULT __stdcall add_RemoteSystemAdded(Windows::Foundation::TypedEventHandler<Windows::System::RemoteSystems::RemoteSystemWatcher, Windows::System::RemoteSystems::RemoteSystemAddedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_RemoteSystemAdded(event_token token) = 0;
    virtual HRESULT __stdcall add_RemoteSystemUpdated(Windows::Foundation::TypedEventHandler<Windows::System::RemoteSystems::RemoteSystemWatcher, Windows::System::RemoteSystems::RemoteSystemUpdatedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_RemoteSystemUpdated(event_token token) = 0;
    virtual HRESULT __stdcall add_RemoteSystemRemoved(Windows::Foundation::TypedEventHandler<Windows::System::RemoteSystems::RemoteSystemWatcher, Windows::System::RemoteSystems::RemoteSystemRemovedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_RemoteSystemRemoved(event_token token) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::System::RemoteSystems::RemoteSystem> { using default_interface = Windows::System::RemoteSystems::IRemoteSystem; };
template <> struct traits<Windows::System::RemoteSystems::RemoteSystemAddedEventArgs> { using default_interface = Windows::System::RemoteSystems::IRemoteSystemAddedEventArgs; };
template <> struct traits<Windows::System::RemoteSystems::RemoteSystemConnectionRequest> { using default_interface = Windows::System::RemoteSystems::IRemoteSystemConnectionRequest; };
template <> struct traits<Windows::System::RemoteSystems::RemoteSystemDiscoveryTypeFilter> { using default_interface = Windows::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilter; };
template <> struct traits<Windows::System::RemoteSystems::RemoteSystemKindFilter> { using default_interface = Windows::System::RemoteSystems::IRemoteSystemKindFilter; };
template <> struct traits<Windows::System::RemoteSystems::RemoteSystemRemovedEventArgs> { using default_interface = Windows::System::RemoteSystems::IRemoteSystemRemovedEventArgs; };
template <> struct traits<Windows::System::RemoteSystems::RemoteSystemStatusTypeFilter> { using default_interface = Windows::System::RemoteSystems::IRemoteSystemStatusTypeFilter; };
template <> struct traits<Windows::System::RemoteSystems::RemoteSystemUpdatedEventArgs> { using default_interface = Windows::System::RemoteSystems::IRemoteSystemUpdatedEventArgs; };
template <> struct traits<Windows::System::RemoteSystems::RemoteSystemWatcher> { using default_interface = Windows::System::RemoteSystems::IRemoteSystemWatcher; };

}

namespace Windows::System::RemoteSystems {

template <typename D>
struct WINRT_EBO impl_IRemoteSystem
{
    hstring DisplayName() const;
    hstring Id() const;
    hstring Kind() const;
    Windows::System::RemoteSystems::RemoteSystemStatus Status() const;
    bool IsAvailableByProximity() const;
};

template <typename D>
struct WINRT_EBO impl_IRemoteSystemAddedEventArgs
{
    Windows::System::RemoteSystems::RemoteSystem RemoteSystem() const;
};

template <typename D>
struct WINRT_EBO impl_IRemoteSystemConnectionRequest
{
    Windows::System::RemoteSystems::RemoteSystem RemoteSystem() const;
};

template <typename D>
struct WINRT_EBO impl_IRemoteSystemConnectionRequestFactory
{
    Windows::System::RemoteSystems::RemoteSystemConnectionRequest Create(const Windows::System::RemoteSystems::RemoteSystem & remoteSystem) const;
};

template <typename D>
struct WINRT_EBO impl_IRemoteSystemDiscoveryTypeFilter
{
    Windows::System::RemoteSystems::RemoteSystemDiscoveryType RemoteSystemDiscoveryType() const;
};

template <typename D>
struct WINRT_EBO impl_IRemoteSystemDiscoveryTypeFilterFactory
{
    Windows::System::RemoteSystems::RemoteSystemDiscoveryTypeFilter Create(Windows::System::RemoteSystems::RemoteSystemDiscoveryType discoveryType) const;
};

template <typename D>
struct WINRT_EBO impl_IRemoteSystemFilter
{
};

template <typename D>
struct WINRT_EBO impl_IRemoteSystemKindFilter
{
    Windows::Foundation::Collections::IVectorView<hstring> RemoteSystemKinds() const;
};

template <typename D>
struct WINRT_EBO impl_IRemoteSystemKindFilterFactory
{
    Windows::System::RemoteSystems::RemoteSystemKindFilter Create(iterable<hstring> remoteSystemKinds) const;
};

template <typename D>
struct WINRT_EBO impl_IRemoteSystemKindStatics
{
    hstring Phone() const;
    hstring Hub() const;
    hstring Holographic() const;
    hstring Desktop() const;
    hstring Xbox() const;
};

template <typename D>
struct WINRT_EBO impl_IRemoteSystemRemovedEventArgs
{
    hstring RemoteSystemId() const;
};

template <typename D>
struct WINRT_EBO impl_IRemoteSystemStatics
{
    Windows::Foundation::IAsyncOperation<Windows::System::RemoteSystems::RemoteSystem> FindByHostNameAsync(const Windows::Networking::HostName & hostName) const;
    Windows::System::RemoteSystems::RemoteSystemWatcher CreateWatcher() const;
    Windows::System::RemoteSystems::RemoteSystemWatcher CreateWatcher(iterable<Windows::System::RemoteSystems::IRemoteSystemFilter> filters) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::System::RemoteSystems::RemoteSystemAccessStatus> RequestAccessAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IRemoteSystemStatusTypeFilter
{
    Windows::System::RemoteSystems::RemoteSystemStatusType RemoteSystemStatusType() const;
};

template <typename D>
struct WINRT_EBO impl_IRemoteSystemStatusTypeFilterFactory
{
    Windows::System::RemoteSystems::RemoteSystemStatusTypeFilter Create(Windows::System::RemoteSystems::RemoteSystemStatusType remoteSystemStatusType) const;
};

template <typename D>
struct WINRT_EBO impl_IRemoteSystemUpdatedEventArgs
{
    Windows::System::RemoteSystems::RemoteSystem RemoteSystem() const;
};

template <typename D>
struct WINRT_EBO impl_IRemoteSystemWatcher
{
    void Start() const;
    void Stop() const;
    event_token RemoteSystemAdded(const Windows::Foundation::TypedEventHandler<Windows::System::RemoteSystems::RemoteSystemWatcher, Windows::System::RemoteSystems::RemoteSystemAddedEventArgs> & handler) const;
    using RemoteSystemAdded_revoker = event_revoker<IRemoteSystemWatcher>;
    RemoteSystemAdded_revoker RemoteSystemAdded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::System::RemoteSystems::RemoteSystemWatcher, Windows::System::RemoteSystems::RemoteSystemAddedEventArgs> & handler) const;
    void RemoteSystemAdded(event_token token) const;
    event_token RemoteSystemUpdated(const Windows::Foundation::TypedEventHandler<Windows::System::RemoteSystems::RemoteSystemWatcher, Windows::System::RemoteSystems::RemoteSystemUpdatedEventArgs> & handler) const;
    using RemoteSystemUpdated_revoker = event_revoker<IRemoteSystemWatcher>;
    RemoteSystemUpdated_revoker RemoteSystemUpdated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::System::RemoteSystems::RemoteSystemWatcher, Windows::System::RemoteSystems::RemoteSystemUpdatedEventArgs> & handler) const;
    void RemoteSystemUpdated(event_token token) const;
    event_token RemoteSystemRemoved(const Windows::Foundation::TypedEventHandler<Windows::System::RemoteSystems::RemoteSystemWatcher, Windows::System::RemoteSystems::RemoteSystemRemovedEventArgs> & handler) const;
    using RemoteSystemRemoved_revoker = event_revoker<IRemoteSystemWatcher>;
    RemoteSystemRemoved_revoker RemoteSystemRemoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::System::RemoteSystems::RemoteSystemWatcher, Windows::System::RemoteSystems::RemoteSystemRemovedEventArgs> & handler) const;
    void RemoteSystemRemoved(event_token token) const;
};

}

namespace impl {

template <> struct traits<Windows::System::RemoteSystems::IRemoteSystem>
{
    using abi = ABI::Windows::System::RemoteSystems::IRemoteSystem;
    template <typename D> using consume = Windows::System::RemoteSystems::impl_IRemoteSystem<D>;
};

template <> struct traits<Windows::System::RemoteSystems::IRemoteSystemAddedEventArgs>
{
    using abi = ABI::Windows::System::RemoteSystems::IRemoteSystemAddedEventArgs;
    template <typename D> using consume = Windows::System::RemoteSystems::impl_IRemoteSystemAddedEventArgs<D>;
};

template <> struct traits<Windows::System::RemoteSystems::IRemoteSystemConnectionRequest>
{
    using abi = ABI::Windows::System::RemoteSystems::IRemoteSystemConnectionRequest;
    template <typename D> using consume = Windows::System::RemoteSystems::impl_IRemoteSystemConnectionRequest<D>;
};

template <> struct traits<Windows::System::RemoteSystems::IRemoteSystemConnectionRequestFactory>
{
    using abi = ABI::Windows::System::RemoteSystems::IRemoteSystemConnectionRequestFactory;
    template <typename D> using consume = Windows::System::RemoteSystems::impl_IRemoteSystemConnectionRequestFactory<D>;
};

template <> struct traits<Windows::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilter>
{
    using abi = ABI::Windows::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilter;
    template <typename D> using consume = Windows::System::RemoteSystems::impl_IRemoteSystemDiscoveryTypeFilter<D>;
};

template <> struct traits<Windows::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilterFactory>
{
    using abi = ABI::Windows::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilterFactory;
    template <typename D> using consume = Windows::System::RemoteSystems::impl_IRemoteSystemDiscoveryTypeFilterFactory<D>;
};

template <> struct traits<Windows::System::RemoteSystems::IRemoteSystemFilter>
{
    using abi = ABI::Windows::System::RemoteSystems::IRemoteSystemFilter;
    template <typename D> using consume = Windows::System::RemoteSystems::impl_IRemoteSystemFilter<D>;
};

template <> struct traits<Windows::System::RemoteSystems::IRemoteSystemKindFilter>
{
    using abi = ABI::Windows::System::RemoteSystems::IRemoteSystemKindFilter;
    template <typename D> using consume = Windows::System::RemoteSystems::impl_IRemoteSystemKindFilter<D>;
};

template <> struct traits<Windows::System::RemoteSystems::IRemoteSystemKindFilterFactory>
{
    using abi = ABI::Windows::System::RemoteSystems::IRemoteSystemKindFilterFactory;
    template <typename D> using consume = Windows::System::RemoteSystems::impl_IRemoteSystemKindFilterFactory<D>;
};

template <> struct traits<Windows::System::RemoteSystems::IRemoteSystemKindStatics>
{
    using abi = ABI::Windows::System::RemoteSystems::IRemoteSystemKindStatics;
    template <typename D> using consume = Windows::System::RemoteSystems::impl_IRemoteSystemKindStatics<D>;
};

template <> struct traits<Windows::System::RemoteSystems::IRemoteSystemRemovedEventArgs>
{
    using abi = ABI::Windows::System::RemoteSystems::IRemoteSystemRemovedEventArgs;
    template <typename D> using consume = Windows::System::RemoteSystems::impl_IRemoteSystemRemovedEventArgs<D>;
};

template <> struct traits<Windows::System::RemoteSystems::IRemoteSystemStatics>
{
    using abi = ABI::Windows::System::RemoteSystems::IRemoteSystemStatics;
    template <typename D> using consume = Windows::System::RemoteSystems::impl_IRemoteSystemStatics<D>;
};

template <> struct traits<Windows::System::RemoteSystems::IRemoteSystemStatusTypeFilter>
{
    using abi = ABI::Windows::System::RemoteSystems::IRemoteSystemStatusTypeFilter;
    template <typename D> using consume = Windows::System::RemoteSystems::impl_IRemoteSystemStatusTypeFilter<D>;
};

template <> struct traits<Windows::System::RemoteSystems::IRemoteSystemStatusTypeFilterFactory>
{
    using abi = ABI::Windows::System::RemoteSystems::IRemoteSystemStatusTypeFilterFactory;
    template <typename D> using consume = Windows::System::RemoteSystems::impl_IRemoteSystemStatusTypeFilterFactory<D>;
};

template <> struct traits<Windows::System::RemoteSystems::IRemoteSystemUpdatedEventArgs>
{
    using abi = ABI::Windows::System::RemoteSystems::IRemoteSystemUpdatedEventArgs;
    template <typename D> using consume = Windows::System::RemoteSystems::impl_IRemoteSystemUpdatedEventArgs<D>;
};

template <> struct traits<Windows::System::RemoteSystems::IRemoteSystemWatcher>
{
    using abi = ABI::Windows::System::RemoteSystems::IRemoteSystemWatcher;
    template <typename D> using consume = Windows::System::RemoteSystems::impl_IRemoteSystemWatcher<D>;
};

template <> struct traits<Windows::System::RemoteSystems::RemoteSystem>
{
    using abi = ABI::Windows::System::RemoteSystems::RemoteSystem;
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.RemoteSystems.RemoteSystem"; }
};

template <> struct traits<Windows::System::RemoteSystems::RemoteSystemAddedEventArgs>
{
    using abi = ABI::Windows::System::RemoteSystems::RemoteSystemAddedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.RemoteSystems.RemoteSystemAddedEventArgs"; }
};

template <> struct traits<Windows::System::RemoteSystems::RemoteSystemConnectionRequest>
{
    using abi = ABI::Windows::System::RemoteSystems::RemoteSystemConnectionRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.RemoteSystems.RemoteSystemConnectionRequest"; }
};

template <> struct traits<Windows::System::RemoteSystems::RemoteSystemDiscoveryTypeFilter>
{
    using abi = ABI::Windows::System::RemoteSystems::RemoteSystemDiscoveryTypeFilter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.RemoteSystems.RemoteSystemDiscoveryTypeFilter"; }
};

template <> struct traits<Windows::System::RemoteSystems::RemoteSystemKindFilter>
{
    using abi = ABI::Windows::System::RemoteSystems::RemoteSystemKindFilter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.RemoteSystems.RemoteSystemKindFilter"; }
};

template <> struct traits<Windows::System::RemoteSystems::RemoteSystemKinds>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.RemoteSystems.RemoteSystemKinds"; }
};

template <> struct traits<Windows::System::RemoteSystems::RemoteSystemRemovedEventArgs>
{
    using abi = ABI::Windows::System::RemoteSystems::RemoteSystemRemovedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.RemoteSystems.RemoteSystemRemovedEventArgs"; }
};

template <> struct traits<Windows::System::RemoteSystems::RemoteSystemStatusTypeFilter>
{
    using abi = ABI::Windows::System::RemoteSystems::RemoteSystemStatusTypeFilter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.RemoteSystems.RemoteSystemStatusTypeFilter"; }
};

template <> struct traits<Windows::System::RemoteSystems::RemoteSystemUpdatedEventArgs>
{
    using abi = ABI::Windows::System::RemoteSystems::RemoteSystemUpdatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.RemoteSystems.RemoteSystemUpdatedEventArgs"; }
};

template <> struct traits<Windows::System::RemoteSystems::RemoteSystemWatcher>
{
    using abi = ABI::Windows::System::RemoteSystems::RemoteSystemWatcher;
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.RemoteSystems.RemoteSystemWatcher"; }
};

}

}
