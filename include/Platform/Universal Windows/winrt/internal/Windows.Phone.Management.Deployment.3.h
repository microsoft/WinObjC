// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Phone.Management.Deployment.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Phone::Management::Deployment {

struct WINRT_EBO Enterprise :
    Windows::Phone::Management::Deployment::IEnterprise
{
    Enterprise(std::nullptr_t) noexcept {}
};

struct EnterpriseEnrollmentManager
{
    EnterpriseEnrollmentManager() = delete;
    static Windows::Foundation::Collections::IVectorView<Windows::Phone::Management::Deployment::Enterprise> EnrolledEnterprises();
    static Windows::Phone::Management::Deployment::Enterprise CurrentEnterprise();
    static Windows::Foundation::IAsyncAction ValidateEnterprisesAsync();
    static Windows::Foundation::IAsyncOperation<Windows::Phone::Management::Deployment::EnterpriseEnrollmentResult> RequestEnrollmentAsync(hstring_view enrollmentToken);
    static Windows::Foundation::IAsyncOperation<bool> RequestUnenrollmentAsync(const Windows::Phone::Management::Deployment::Enterprise & enterprise);
};

struct WINRT_EBO EnterpriseEnrollmentResult :
    Windows::Phone::Management::Deployment::IEnterpriseEnrollmentResult
{
    EnterpriseEnrollmentResult(std::nullptr_t) noexcept {}
};

struct InstallationManager
{
    InstallationManager() = delete;
    static Windows::Foundation::IAsyncOperationWithProgress<Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t> AddPackageAsync(hstring_view title, const Windows::Foundation::Uri & sourceLocation);
    static Windows::Foundation::IAsyncOperationWithProgress<Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t> AddPackageAsync(hstring_view title, const Windows::Foundation::Uri & sourceLocation, hstring_view instanceId, hstring_view offerId, const Windows::Foundation::Uri & license);
    static Windows::Foundation::Collections::IIterable<Windows::Foundation::IAsyncOperationWithProgress<Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t>> GetPendingPackageInstalls();
    static Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> FindPackagesForCurrentPublisher();
    static Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> FindPackages();
    static Windows::Foundation::IAsyncOperationWithProgress<Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t> RemovePackageAsync(hstring_view packageFullName, Windows::Management::Deployment::RemovalOptions removalOptions);
    static Windows::Foundation::IAsyncOperationWithProgress<Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t> RegisterPackageAsync(const Windows::Foundation::Uri & manifestUri, iterable<Windows::Foundation::Uri> dependencyPackageUris, Windows::Management::Deployment::DeploymentOptions deploymentOptions);
    static Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> FindPackages(hstring_view packageName, hstring_view packagePublisher);
};

struct WINRT_EBO PackageInstallResult :
    Windows::Phone::Management::Deployment::IPackageInstallResult,
    impl::require<PackageInstallResult, Windows::Phone::Management::Deployment::IPackageInstallResult2>
{
    PackageInstallResult(std::nullptr_t) noexcept {}
};

}

}
