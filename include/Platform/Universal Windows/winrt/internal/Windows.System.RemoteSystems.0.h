// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::System::RemoteSystems {

struct IRemoteSystem;
struct IRemoteSystemAddedEventArgs;
struct IRemoteSystemConnectionRequest;
struct IRemoteSystemConnectionRequestFactory;
struct IRemoteSystemDiscoveryTypeFilter;
struct IRemoteSystemDiscoveryTypeFilterFactory;
struct IRemoteSystemFilter;
struct IRemoteSystemKindFilter;
struct IRemoteSystemKindFilterFactory;
struct IRemoteSystemKindStatics;
struct IRemoteSystemRemovedEventArgs;
struct IRemoteSystemStatics;
struct IRemoteSystemStatusTypeFilter;
struct IRemoteSystemStatusTypeFilterFactory;
struct IRemoteSystemUpdatedEventArgs;
struct IRemoteSystemWatcher;
struct RemoteSystem;
struct RemoteSystemAddedEventArgs;
struct RemoteSystemConnectionRequest;
struct RemoteSystemDiscoveryTypeFilter;
struct RemoteSystemKindFilter;
struct RemoteSystemRemovedEventArgs;
struct RemoteSystemStatusTypeFilter;
struct RemoteSystemUpdatedEventArgs;
struct RemoteSystemWatcher;

}

namespace Windows::System::RemoteSystems {

struct IRemoteSystem;
struct IRemoteSystemAddedEventArgs;
struct IRemoteSystemConnectionRequest;
struct IRemoteSystemConnectionRequestFactory;
struct IRemoteSystemDiscoveryTypeFilter;
struct IRemoteSystemDiscoveryTypeFilterFactory;
struct IRemoteSystemFilter;
struct IRemoteSystemKindFilter;
struct IRemoteSystemKindFilterFactory;
struct IRemoteSystemKindStatics;
struct IRemoteSystemRemovedEventArgs;
struct IRemoteSystemStatics;
struct IRemoteSystemStatusTypeFilter;
struct IRemoteSystemStatusTypeFilterFactory;
struct IRemoteSystemUpdatedEventArgs;
struct IRemoteSystemWatcher;
struct RemoteSystem;
struct RemoteSystemAddedEventArgs;
struct RemoteSystemConnectionRequest;
struct RemoteSystemDiscoveryTypeFilter;
struct RemoteSystemKindFilter;
struct RemoteSystemKinds;
struct RemoteSystemRemovedEventArgs;
struct RemoteSystemStatusTypeFilter;
struct RemoteSystemUpdatedEventArgs;
struct RemoteSystemWatcher;

}

namespace Windows::System::RemoteSystems {

template <typename T> struct impl_IRemoteSystem;
template <typename T> struct impl_IRemoteSystemAddedEventArgs;
template <typename T> struct impl_IRemoteSystemConnectionRequest;
template <typename T> struct impl_IRemoteSystemConnectionRequestFactory;
template <typename T> struct impl_IRemoteSystemDiscoveryTypeFilter;
template <typename T> struct impl_IRemoteSystemDiscoveryTypeFilterFactory;
template <typename T> struct impl_IRemoteSystemFilter;
template <typename T> struct impl_IRemoteSystemKindFilter;
template <typename T> struct impl_IRemoteSystemKindFilterFactory;
template <typename T> struct impl_IRemoteSystemKindStatics;
template <typename T> struct impl_IRemoteSystemRemovedEventArgs;
template <typename T> struct impl_IRemoteSystemStatics;
template <typename T> struct impl_IRemoteSystemStatusTypeFilter;
template <typename T> struct impl_IRemoteSystemStatusTypeFilterFactory;
template <typename T> struct impl_IRemoteSystemUpdatedEventArgs;
template <typename T> struct impl_IRemoteSystemWatcher;

}

namespace Windows::System::RemoteSystems {

enum class RemoteSystemAccessStatus
{
    Unspecified = 0,
    Allowed = 1,
    DeniedByUser = 2,
    DeniedBySystem = 3,
};

enum class RemoteSystemDiscoveryType
{
    Any = 0,
    Proximal = 1,
    Cloud = 2,
};

enum class RemoteSystemStatus
{
    Unavailable = 0,
    DiscoveringAvailability = 1,
    Available = 2,
    Unknown = 3,
};

enum class RemoteSystemStatusType
{
    Any = 0,
    Available = 1,
};

}

}
