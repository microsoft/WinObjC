// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices {

struct ILowLevelDevicesAggregateProvider;
struct ILowLevelDevicesAggregateProviderFactory;
struct ILowLevelDevicesController;
struct ILowLevelDevicesControllerStatics;
struct LowLevelDevicesAggregateProvider;
struct LowLevelDevicesController;

}

namespace Windows::Devices {

struct ILowLevelDevicesAggregateProvider;
struct ILowLevelDevicesAggregateProviderFactory;
struct ILowLevelDevicesController;
struct ILowLevelDevicesControllerStatics;
struct LowLevelDevicesAggregateProvider;
struct LowLevelDevicesController;

}

namespace Windows::Devices {

template <typename T> struct impl_ILowLevelDevicesAggregateProvider;
template <typename T> struct impl_ILowLevelDevicesAggregateProviderFactory;
template <typename T> struct impl_ILowLevelDevicesController;
template <typename T> struct impl_ILowLevelDevicesControllerStatics;

}

}
