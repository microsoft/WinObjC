// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Store::Preview::InstallControl {

struct IAppInstallItem;
struct IAppInstallItem2;
struct IAppInstallManager;
struct IAppInstallManager2;
struct IAppInstallManager3;
struct IAppInstallManagerItemEventArgs;
struct IAppInstallStatus;
struct IAppInstallStatus2;
struct AppInstallItem;
struct AppInstallManager;
struct AppInstallManagerItemEventArgs;
struct AppInstallStatus;

}

namespace Windows::ApplicationModel::Store::Preview::InstallControl {

struct IAppInstallItem;
struct IAppInstallItem2;
struct IAppInstallManager;
struct IAppInstallManager2;
struct IAppInstallManager3;
struct IAppInstallManagerItemEventArgs;
struct IAppInstallStatus;
struct IAppInstallStatus2;
struct AppInstallItem;
struct AppInstallManager;
struct AppInstallManagerItemEventArgs;
struct AppInstallStatus;

}

namespace Windows::ApplicationModel::Store::Preview::InstallControl {

template <typename T> struct impl_IAppInstallItem;
template <typename T> struct impl_IAppInstallItem2;
template <typename T> struct impl_IAppInstallManager;
template <typename T> struct impl_IAppInstallManager2;
template <typename T> struct impl_IAppInstallManager3;
template <typename T> struct impl_IAppInstallManagerItemEventArgs;
template <typename T> struct impl_IAppInstallStatus;
template <typename T> struct impl_IAppInstallStatus2;

}

namespace Windows::ApplicationModel::Store::Preview::InstallControl {

enum class AppInstallState
{
    Pending = 0,
    Starting = 1,
    AcquiringLicense = 2,
    Downloading = 3,
    RestoringData = 4,
    Installing = 5,
    Completed = 6,
    Canceled = 7,
    Paused = 8,
    Error = 9,
    PausedLowBattery = 10,
    PausedWiFiRecommended = 11,
    PausedWiFiRequired = 12,
    ReadyToDownload = 13,
};

enum class AppInstallType
{
    Install = 0,
    Update = 1,
    Repair = 2,
};

enum class AutoUpdateSetting
{
    Disabled = 0,
    Enabled = 1,
    DisabledByPolicy = 2,
    EnabledByPolicy = 3,
};

}

}
