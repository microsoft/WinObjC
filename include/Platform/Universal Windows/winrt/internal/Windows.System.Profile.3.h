// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.System.Profile.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::System::Profile {

struct AnalyticsInfo
{
    AnalyticsInfo() = delete;
    static Windows::System::Profile::AnalyticsVersionInfo VersionInfo();
    static hstring DeviceForm();
};

struct WINRT_EBO AnalyticsVersionInfo :
    Windows::System::Profile::IAnalyticsVersionInfo
{
    AnalyticsVersionInfo(std::nullptr_t) noexcept {}
};

struct HardwareIdentification
{
    HardwareIdentification() = delete;
    static Windows::System::Profile::HardwareToken GetPackageSpecificToken(const Windows::Storage::Streams::IBuffer & nonce);
};

struct WINRT_EBO HardwareToken :
    Windows::System::Profile::IHardwareToken
{
    HardwareToken(std::nullptr_t) noexcept {}
};

struct KnownRetailInfoProperties
{
    KnownRetailInfoProperties() = delete;
    static hstring RetailAccessCode();
    static hstring ManufacturerName();
    static hstring ModelName();
    static hstring DisplayModelName();
    static hstring Price();
    static hstring IsFeatured();
    static hstring FormFactor();
    static hstring ScreenSize();
    static hstring Weight();
    static hstring DisplayDescription();
    static hstring BatteryLifeDescription();
    static hstring ProcessorDescription();
    static hstring Memory();
    static hstring StorageDescription();
    static hstring GraphicsDescription();
    static hstring FrontCameraDescription();
    static hstring RearCameraDescription();
    static hstring HasNfc();
    static hstring HasSdSlot();
    static hstring HasOpticalDrive();
    static hstring IsOfficeInstalled();
    static hstring WindowsEdition();
};

struct PlatformDiagnosticsAndUsageDataSettings
{
    PlatformDiagnosticsAndUsageDataSettings() = delete;
    static Windows::System::Profile::PlatformDataCollectionLevel CollectionLevel();
    static event_token CollectionLevelChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using CollectionLevelChanged_revoker = factory_event_revoker<IPlatformDiagnosticsAndUsageDataSettingsStatics>;
    static CollectionLevelChanged_revoker CollectionLevelChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    static void CollectionLevelChanged(event_token token);
    static bool CanCollectDiagnostics(Windows::System::Profile::PlatformDataCollectionLevel level);
};

struct RetailInfo
{
    RetailInfo() = delete;
    static bool IsDemoModeEnabled();
    static Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> Properties();
};

struct SharedModeSettings
{
    SharedModeSettings() = delete;
    static bool IsEnabled();
};

struct SystemIdentification
{
    SystemIdentification() = delete;
    static Windows::System::Profile::SystemIdentificationInfo GetSystemIdForPublisher();
    static Windows::System::Profile::SystemIdentificationInfo GetSystemIdForUser(const Windows::System::User & user);
};

struct WINRT_EBO SystemIdentificationInfo :
    Windows::System::Profile::ISystemIdentificationInfo
{
    SystemIdentificationInfo(std::nullptr_t) noexcept {}
};

}

}
