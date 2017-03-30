// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Enumeration.Pnp.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::Enumeration::Pnp {

struct WINRT_EBO PnpObject :
    Windows::Devices::Enumeration::Pnp::IPnpObject
{
    PnpObject(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::Pnp::PnpObject> CreateFromIdAsync(Windows::Devices::Enumeration::Pnp::PnpObjectType type, hstring_view id, iterable<hstring> requestedProperties);
    static Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::Pnp::PnpObjectCollection> FindAllAsync(Windows::Devices::Enumeration::Pnp::PnpObjectType type, iterable<hstring> requestedProperties);
    static Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::Pnp::PnpObjectCollection> FindAllAsync(Windows::Devices::Enumeration::Pnp::PnpObjectType type, iterable<hstring> requestedProperties, hstring_view aqsFilter);
    static Windows::Devices::Enumeration::Pnp::PnpObjectWatcher CreateWatcher(Windows::Devices::Enumeration::Pnp::PnpObjectType type, iterable<hstring> requestedProperties);
    static Windows::Devices::Enumeration::Pnp::PnpObjectWatcher CreateWatcher(Windows::Devices::Enumeration::Pnp::PnpObjectType type, iterable<hstring> requestedProperties, hstring_view aqsFilter);
};

struct WINRT_EBO PnpObjectCollection :
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Enumeration::Pnp::PnpObject>
{
    PnpObjectCollection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PnpObjectUpdate :
    Windows::Devices::Enumeration::Pnp::IPnpObjectUpdate
{
    PnpObjectUpdate(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PnpObjectWatcher :
    Windows::Devices::Enumeration::Pnp::IPnpObjectWatcher
{
    PnpObjectWatcher(std::nullptr_t) noexcept {}
};

}

}
