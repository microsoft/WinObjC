// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel {

struct WINRT_EBO AppDisplayInfo :
    Windows::ApplicationModel::IAppDisplayInfo
{
    AppDisplayInfo(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AppInfo :
    Windows::ApplicationModel::IAppInfo
{
    AppInfo(std::nullptr_t) noexcept {}
};

struct CameraApplicationManager
{
    CameraApplicationManager() = delete;
    static void ShowInstalledApplicationsUI();
};

struct DesignMode
{
    DesignMode() = delete;
    static bool DesignModeEnabled();
};

struct WINRT_EBO EnteredBackgroundEventArgs :
    Windows::ApplicationModel::IEnteredBackgroundEventArgs
{
    EnteredBackgroundEventArgs(std::nullptr_t) noexcept {}
};

struct FullTrustProcessLauncher
{
    FullTrustProcessLauncher() = delete;
    static Windows::Foundation::IAsyncAction LaunchFullTrustProcessForCurrentAppAsync();
    static Windows::Foundation::IAsyncAction LaunchFullTrustProcessForCurrentAppAsync(hstring_view parameterGroupId);
    static Windows::Foundation::IAsyncAction LaunchFullTrustProcessForAppAsync(hstring_view fullTrustPackageRelativeAppId);
    static Windows::Foundation::IAsyncAction LaunchFullTrustProcessForAppAsync(hstring_view fullTrustPackageRelativeAppId, hstring_view parameterGroupId);
};

struct WINRT_EBO LeavingBackgroundEventArgs :
    Windows::ApplicationModel::ILeavingBackgroundEventArgs
{
    LeavingBackgroundEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Package :
    Windows::ApplicationModel::IPackage,
    impl::require<Package, Windows::ApplicationModel::IPackageWithMetadata, Windows::ApplicationModel::IPackage2, Windows::ApplicationModel::IPackage3, Windows::ApplicationModel::IPackage4>
{
    Package(std::nullptr_t) noexcept {}
    static Windows::ApplicationModel::Package Current();
};

struct WINRT_EBO PackageCatalog :
    Windows::ApplicationModel::IPackageCatalog
{
    PackageCatalog(std::nullptr_t) noexcept {}
    static Windows::ApplicationModel::PackageCatalog OpenForCurrentPackage();
    static Windows::ApplicationModel::PackageCatalog OpenForCurrentUser();
};

struct WINRT_EBO PackageId :
    Windows::ApplicationModel::IPackageId,
    impl::require<PackageId, Windows::ApplicationModel::IPackageIdWithMetadata>
{
    PackageId(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PackageInstallingEventArgs :
    Windows::ApplicationModel::IPackageInstallingEventArgs
{
    PackageInstallingEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PackageStagingEventArgs :
    Windows::ApplicationModel::IPackageStagingEventArgs
{
    PackageStagingEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PackageStatus :
    Windows::ApplicationModel::IPackageStatus
{
    PackageStatus(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PackageStatusChangedEventArgs :
    Windows::ApplicationModel::IPackageStatusChangedEventArgs
{
    PackageStatusChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PackageUninstallingEventArgs :
    Windows::ApplicationModel::IPackageUninstallingEventArgs
{
    PackageUninstallingEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PackageUpdatingEventArgs :
    Windows::ApplicationModel::IPackageUpdatingEventArgs
{
    PackageUpdatingEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO StartupTask :
    Windows::ApplicationModel::IStartupTask
{
    StartupTask(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::StartupTask>> GetForCurrentPackageAsync();
    static Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::StartupTask> GetAsync(hstring_view taskId);
};

struct WINRT_EBO SuspendingDeferral :
    Windows::ApplicationModel::ISuspendingDeferral
{
    SuspendingDeferral(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SuspendingEventArgs :
    Windows::ApplicationModel::ISuspendingEventArgs
{
    SuspendingEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SuspendingOperation :
    Windows::ApplicationModel::ISuspendingOperation
{
    SuspendingOperation(std::nullptr_t) noexcept {}
};

}

}
