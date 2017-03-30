// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Management.Deployment.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Management::Deployment {

struct WINRT_EBO DeploymentResult :
    Windows::Management::Deployment::IDeploymentResult
{
    DeploymentResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PackageManager :
    Windows::Management::Deployment::IPackageManager,
    impl::require<PackageManager, Windows::Management::Deployment::IPackageManager2, Windows::Management::Deployment::IPackageManager3, Windows::Management::Deployment::IPackageManager4>
{
    PackageManager(std::nullptr_t) noexcept {}
    PackageManager();
    using impl_IPackageManager::AddPackageAsync;
    using impl_IPackageManager::RegisterPackageAsync;
    using impl_IPackageManager::RemovePackageAsync;
    using impl_IPackageManager::StagePackageAsync;
    using impl_IPackageManager2::RemovePackageAsync;
    using impl_IPackageManager2::StagePackageAsync;
    using impl_IPackageManager2::StageUserDataAsync;
    using impl_IPackageManager3::AddPackageAsync;
    using impl_IPackageManager3::RegisterPackageAsync;
    using impl_IPackageManager3::StagePackageAsync;
    using impl_IPackageManager3::StageUserDataAsync;
};

struct WINRT_EBO PackageUserInformation :
    Windows::Management::Deployment::IPackageUserInformation
{
    PackageUserInformation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PackageVolume :
    Windows::Management::Deployment::IPackageVolume,
    impl::require<PackageVolume, Windows::Management::Deployment::IPackageVolume2>
{
    PackageVolume(std::nullptr_t) noexcept {}
};

}

}
