// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel {

struct PackageVersion;

}

namespace Windows::ApplicationModel {

using PackageVersion = ABI::Windows::ApplicationModel::PackageVersion;

}

namespace ABI::Windows::ApplicationModel {

struct IAppDisplayInfo;
struct IAppInfo;
struct ICameraApplicationManagerStatics;
struct IDesignModeStatics;
struct IEnteredBackgroundEventArgs;
struct IFullTrustProcessLauncherStatics;
struct ILeavingBackgroundEventArgs;
struct IPackage;
struct IPackage2;
struct IPackage3;
struct IPackage4;
struct IPackageCatalog;
struct IPackageCatalogStatics;
struct IPackageId;
struct IPackageIdWithMetadata;
struct IPackageInstallingEventArgs;
struct IPackageStagingEventArgs;
struct IPackageStatics;
struct IPackageStatus;
struct IPackageStatusChangedEventArgs;
struct IPackageUninstallingEventArgs;
struct IPackageUpdatingEventArgs;
struct IPackageWithMetadata;
struct IStartupTask;
struct IStartupTaskStatics;
struct ISuspendingDeferral;
struct ISuspendingEventArgs;
struct ISuspendingOperation;
struct AppDisplayInfo;
struct AppInfo;
struct EnteredBackgroundEventArgs;
struct LeavingBackgroundEventArgs;
struct Package;
struct PackageCatalog;
struct PackageId;
struct PackageInstallingEventArgs;
struct PackageStagingEventArgs;
struct PackageStatus;
struct PackageStatusChangedEventArgs;
struct PackageUninstallingEventArgs;
struct PackageUpdatingEventArgs;
struct StartupTask;
struct SuspendingDeferral;
struct SuspendingEventArgs;
struct SuspendingOperation;

}

namespace Windows::ApplicationModel {

struct IAppDisplayInfo;
struct IAppInfo;
struct ICameraApplicationManagerStatics;
struct IDesignModeStatics;
struct IEnteredBackgroundEventArgs;
struct IFullTrustProcessLauncherStatics;
struct ILeavingBackgroundEventArgs;
struct IPackage;
struct IPackage2;
struct IPackage3;
struct IPackage4;
struct IPackageCatalog;
struct IPackageCatalogStatics;
struct IPackageId;
struct IPackageIdWithMetadata;
struct IPackageInstallingEventArgs;
struct IPackageStagingEventArgs;
struct IPackageStatics;
struct IPackageStatus;
struct IPackageStatusChangedEventArgs;
struct IPackageUninstallingEventArgs;
struct IPackageUpdatingEventArgs;
struct IPackageWithMetadata;
struct IStartupTask;
struct IStartupTaskStatics;
struct ISuspendingDeferral;
struct ISuspendingEventArgs;
struct ISuspendingOperation;
struct AppDisplayInfo;
struct AppInfo;
struct CameraApplicationManager;
struct DesignMode;
struct EnteredBackgroundEventArgs;
struct FullTrustProcessLauncher;
struct LeavingBackgroundEventArgs;
struct Package;
struct PackageCatalog;
struct PackageId;
struct PackageInstallingEventArgs;
struct PackageStagingEventArgs;
struct PackageStatus;
struct PackageStatusChangedEventArgs;
struct PackageUninstallingEventArgs;
struct PackageUpdatingEventArgs;
struct StartupTask;
struct SuspendingDeferral;
struct SuspendingEventArgs;
struct SuspendingOperation;

}

namespace Windows::ApplicationModel {

template <typename T> struct impl_IAppDisplayInfo;
template <typename T> struct impl_IAppInfo;
template <typename T> struct impl_ICameraApplicationManagerStatics;
template <typename T> struct impl_IDesignModeStatics;
template <typename T> struct impl_IEnteredBackgroundEventArgs;
template <typename T> struct impl_IFullTrustProcessLauncherStatics;
template <typename T> struct impl_ILeavingBackgroundEventArgs;
template <typename T> struct impl_IPackage;
template <typename T> struct impl_IPackage2;
template <typename T> struct impl_IPackage3;
template <typename T> struct impl_IPackage4;
template <typename T> struct impl_IPackageCatalog;
template <typename T> struct impl_IPackageCatalogStatics;
template <typename T> struct impl_IPackageId;
template <typename T> struct impl_IPackageIdWithMetadata;
template <typename T> struct impl_IPackageInstallingEventArgs;
template <typename T> struct impl_IPackageStagingEventArgs;
template <typename T> struct impl_IPackageStatics;
template <typename T> struct impl_IPackageStatus;
template <typename T> struct impl_IPackageStatusChangedEventArgs;
template <typename T> struct impl_IPackageUninstallingEventArgs;
template <typename T> struct impl_IPackageUpdatingEventArgs;
template <typename T> struct impl_IPackageWithMetadata;
template <typename T> struct impl_IStartupTask;
template <typename T> struct impl_IStartupTaskStatics;
template <typename T> struct impl_ISuspendingDeferral;
template <typename T> struct impl_ISuspendingEventArgs;
template <typename T> struct impl_ISuspendingOperation;

}

namespace Windows::ApplicationModel {

enum class PackageSignatureKind
{
    None = 0,
    Developer = 1,
    Enterprise = 2,
    Store = 3,
    System = 4,
};

enum class StartupTaskState
{
    Disabled = 0,
    DisabledByUser = 1,
    Enabled = 2,
};

}

}
