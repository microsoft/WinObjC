// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Management::Deployment {

struct DeploymentProgress;

}

namespace Windows::Management::Deployment {

using DeploymentProgress = ABI::Windows::Management::Deployment::DeploymentProgress;

}

namespace ABI::Windows::Management::Deployment {

struct IDeploymentResult;
struct IPackageManager;
struct IPackageManager2;
struct IPackageManager3;
struct IPackageManager4;
struct IPackageUserInformation;
struct IPackageVolume;
struct IPackageVolume2;
struct DeploymentResult;
struct PackageManager;
struct PackageUserInformation;
struct PackageVolume;

}

namespace Windows::Management::Deployment {

struct IDeploymentResult;
struct IPackageManager;
struct IPackageManager2;
struct IPackageManager3;
struct IPackageManager4;
struct IPackageUserInformation;
struct IPackageVolume;
struct IPackageVolume2;
struct DeploymentResult;
struct PackageManager;
struct PackageUserInformation;
struct PackageVolume;

}

namespace Windows::Management::Deployment {

template <typename T> struct impl_IDeploymentResult;
template <typename T> struct impl_IPackageManager;
template <typename T> struct impl_IPackageManager2;
template <typename T> struct impl_IPackageManager3;
template <typename T> struct impl_IPackageManager4;
template <typename T> struct impl_IPackageUserInformation;
template <typename T> struct impl_IPackageVolume;
template <typename T> struct impl_IPackageVolume2;

}

namespace Windows::Management::Deployment {

enum class DeploymentOptions : unsigned
{
    None = 0x0,
    ForceApplicationShutdown = 0x1,
    DevelopmentMode = 0x2,
    InstallAllResources = 0x20,
    ForceTargetApplicationShutdown = 0x40,
};

DEFINE_ENUM_FLAG_OPERATORS(DeploymentOptions)

enum class DeploymentProgressState
{
    Queued = 0,
    Processing = 1,
};

enum class PackageInstallState
{
    NotInstalled = 0,
    Staged = 1,
    Installed = 2,
    Paused = 6,
};

enum class PackageState
{
    Normal = 0,
    LicenseInvalid = 1,
    Modified = 2,
    Tampered = 3,
};

enum class PackageStatus : unsigned
{
    OK = 0x0,
    LicenseIssue = 0x1,
    Modified = 0x2,
    Tampered = 0x4,
    Disabled = 0x8,
};

DEFINE_ENUM_FLAG_OPERATORS(PackageStatus)

enum class PackageTypes : unsigned
{
    None = 0x0,
    Main = 0x1,
    Framework = 0x2,
    Resource = 0x4,
    Bundle = 0x8,
    Xap = 0x10,
    Optional = 0x20,
};

DEFINE_ENUM_FLAG_OPERATORS(PackageTypes)

enum class RemovalOptions : unsigned
{
    None = 0x0,
    PreserveApplicationData = 0x1000,
};

DEFINE_ENUM_FLAG_OPERATORS(RemovalOptions)

}

}
