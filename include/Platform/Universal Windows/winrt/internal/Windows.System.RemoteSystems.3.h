// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.System.RemoteSystems.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::System::RemoteSystems {

struct WINRT_EBO RemoteSystem :
    Windows::System::RemoteSystems::IRemoteSystem
{
    RemoteSystem(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::System::RemoteSystems::RemoteSystem> FindByHostNameAsync(const Windows::Networking::HostName & hostName);
    static Windows::System::RemoteSystems::RemoteSystemWatcher CreateWatcher();
    static Windows::System::RemoteSystems::RemoteSystemWatcher CreateWatcher(iterable<Windows::System::RemoteSystems::IRemoteSystemFilter> filters);
    static Windows::Foundation::IAsyncOperation<winrt::Windows::System::RemoteSystems::RemoteSystemAccessStatus> RequestAccessAsync();
};

struct WINRT_EBO RemoteSystemAddedEventArgs :
    Windows::System::RemoteSystems::IRemoteSystemAddedEventArgs
{
    RemoteSystemAddedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RemoteSystemConnectionRequest :
    Windows::System::RemoteSystems::IRemoteSystemConnectionRequest
{
    RemoteSystemConnectionRequest(std::nullptr_t) noexcept {}
    RemoteSystemConnectionRequest(const Windows::System::RemoteSystems::RemoteSystem & remoteSystem);
};

struct WINRT_EBO RemoteSystemDiscoveryTypeFilter :
    Windows::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilter,
    impl::require<RemoteSystemDiscoveryTypeFilter, Windows::System::RemoteSystems::IRemoteSystemFilter>
{
    RemoteSystemDiscoveryTypeFilter(std::nullptr_t) noexcept {}
    RemoteSystemDiscoveryTypeFilter(Windows::System::RemoteSystems::RemoteSystemDiscoveryType discoveryType);
};

struct WINRT_EBO RemoteSystemKindFilter :
    Windows::System::RemoteSystems::IRemoteSystemKindFilter,
    impl::require<RemoteSystemKindFilter, Windows::System::RemoteSystems::IRemoteSystemFilter>
{
    RemoteSystemKindFilter(std::nullptr_t) noexcept {}
    RemoteSystemKindFilter(iterable<hstring> remoteSystemKinds);
};

struct RemoteSystemKinds
{
    RemoteSystemKinds() = delete;
    static hstring Phone();
    static hstring Hub();
    static hstring Holographic();
    static hstring Desktop();
    static hstring Xbox();
};

struct WINRT_EBO RemoteSystemRemovedEventArgs :
    Windows::System::RemoteSystems::IRemoteSystemRemovedEventArgs
{
    RemoteSystemRemovedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RemoteSystemStatusTypeFilter :
    Windows::System::RemoteSystems::IRemoteSystemStatusTypeFilter,
    impl::require<RemoteSystemStatusTypeFilter, Windows::System::RemoteSystems::IRemoteSystemFilter>
{
    RemoteSystemStatusTypeFilter(std::nullptr_t) noexcept {}
    RemoteSystemStatusTypeFilter(Windows::System::RemoteSystems::RemoteSystemStatusType remoteSystemStatusType);
};

struct WINRT_EBO RemoteSystemUpdatedEventArgs :
    Windows::System::RemoteSystems::IRemoteSystemUpdatedEventArgs
{
    RemoteSystemUpdatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RemoteSystemWatcher :
    Windows::System::RemoteSystems::IRemoteSystemWatcher
{
    RemoteSystemWatcher(std::nullptr_t) noexcept {}
};

}

}
