// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Enumeration::Pnp {

struct IPnpObject;
struct IPnpObjectStatics;
struct IPnpObjectUpdate;
struct IPnpObjectWatcher;
struct PnpObject;
struct PnpObjectCollection;
struct PnpObjectUpdate;
struct PnpObjectWatcher;

}

namespace Windows::Devices::Enumeration::Pnp {

struct IPnpObject;
struct IPnpObjectStatics;
struct IPnpObjectUpdate;
struct IPnpObjectWatcher;
struct PnpObject;
struct PnpObjectCollection;
struct PnpObjectUpdate;
struct PnpObjectWatcher;

}

namespace Windows::Devices::Enumeration::Pnp {

template <typename T> struct impl_IPnpObject;
template <typename T> struct impl_IPnpObjectStatics;
template <typename T> struct impl_IPnpObjectUpdate;
template <typename T> struct impl_IPnpObjectWatcher;

}

namespace Windows::Devices::Enumeration::Pnp {

enum class PnpObjectType
{
    Unknown = 0,
    DeviceInterface = 1,
    DeviceContainer = 2,
    Device = 3,
    DeviceInterfaceClass = 4,
    AssociationEndpoint = 5,
    AssociationEndpointContainer = 6,
    AssociationEndpointService = 7,
};

}

}
