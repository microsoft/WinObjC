// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.System.Profile.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_09335560_6c6b_5a26_9348_97b781132b20
#define WINRT_GENERIC_09335560_6c6b_5a26_9348_97b781132b20
template <> struct __declspec(uuid("09335560-6c6b-5a26-9348-97b781132b20")) __declspec(novtable) IKeyValuePair<hstring, Windows::Foundation::IInspectable> : impl_IKeyValuePair<hstring, Windows::Foundation::IInspectable> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_c50898f6_c536_5f47_8583_8b2c2438a13b
#define WINRT_GENERIC_c50898f6_c536_5f47_8583_8b2c2438a13b
template <> struct __declspec(uuid("c50898f6-c536-5f47-8583-8b2c2438a13b")) __declspec(novtable) EventHandler<Windows::Foundation::IInspectable> : impl_EventHandler<Windows::Foundation::IInspectable> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_bb78502a_f79d_54fa_92c9_90c5039fdf7e
#define WINRT_GENERIC_bb78502a_f79d_54fa_92c9_90c5039fdf7e
template <> struct __declspec(uuid("bb78502a-f79d-54fa-92c9-90c5039fdf7e")) __declspec(novtable) IMapView<hstring, Windows::Foundation::IInspectable> : impl_IMapView<hstring, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_fe2f3d47_5d47_5499_8374_430c7cda0204
#define WINRT_GENERIC_fe2f3d47_5d47_5499_8374_430c7cda0204
template <> struct __declspec(uuid("fe2f3d47-5d47-5499-8374-430c7cda0204")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> {};
#endif

#ifndef WINRT_GENERIC_5db5fa32_707c_5849_a06b_91c8eb9d10e8
#define WINRT_GENERIC_5db5fa32_707c_5849_a06b_91c8eb9d10e8
template <> struct __declspec(uuid("5db5fa32-707c-5849-a06b-91c8eb9d10e8")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> {};
#endif


}

namespace Windows::System::Profile {

struct IAnalyticsInfoStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IAnalyticsInfoStatics>
{
    IAnalyticsInfoStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IAnalyticsVersionInfo :
    Windows::Foundation::IInspectable,
    impl::consume<IAnalyticsVersionInfo>
{
    IAnalyticsVersionInfo(std::nullptr_t = nullptr) noexcept {}
};

struct IHardwareIdentificationStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IHardwareIdentificationStatics>
{
    IHardwareIdentificationStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IHardwareToken :
    Windows::Foundation::IInspectable,
    impl::consume<IHardwareToken>
{
    IHardwareToken(std::nullptr_t = nullptr) noexcept {}
};

struct IKnownRetailInfoPropertiesStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IKnownRetailInfoPropertiesStatics>
{
    IKnownRetailInfoPropertiesStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IPlatformDiagnosticsAndUsageDataSettingsStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IPlatformDiagnosticsAndUsageDataSettingsStatics>
{
    IPlatformDiagnosticsAndUsageDataSettingsStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IRetailInfoStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IRetailInfoStatics>
{
    IRetailInfoStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISharedModeSettingsStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISharedModeSettingsStatics>
{
    ISharedModeSettingsStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISystemIdentificationInfo :
    Windows::Foundation::IInspectable,
    impl::consume<ISystemIdentificationInfo>
{
    ISystemIdentificationInfo(std::nullptr_t = nullptr) noexcept {}
};

struct ISystemIdentificationStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISystemIdentificationStatics>
{
    ISystemIdentificationStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
