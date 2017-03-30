// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Phone::Management::Deployment {

struct IEnterprise;
struct IEnterpriseEnrollmentManager;
struct IEnterpriseEnrollmentResult;
struct IInstallationManagerStatics;
struct IInstallationManagerStatics2;
struct IPackageInstallResult;
struct IPackageInstallResult2;
struct Enterprise;
struct EnterpriseEnrollmentResult;
struct PackageInstallResult;

}

namespace Windows::Phone::Management::Deployment {

struct IEnterprise;
struct IEnterpriseEnrollmentManager;
struct IEnterpriseEnrollmentResult;
struct IInstallationManagerStatics;
struct IInstallationManagerStatics2;
struct IPackageInstallResult;
struct IPackageInstallResult2;
struct Enterprise;
struct EnterpriseEnrollmentManager;
struct EnterpriseEnrollmentResult;
struct InstallationManager;
struct PackageInstallResult;

}

namespace Windows::Phone::Management::Deployment {

template <typename T> struct impl_IEnterprise;
template <typename T> struct impl_IEnterpriseEnrollmentManager;
template <typename T> struct impl_IEnterpriseEnrollmentResult;
template <typename T> struct impl_IInstallationManagerStatics;
template <typename T> struct impl_IInstallationManagerStatics2;
template <typename T> struct impl_IPackageInstallResult;
template <typename T> struct impl_IPackageInstallResult2;

}

namespace Windows::Phone::Management::Deployment {

enum class EnterpriseEnrollmentStatus
{
    Success = 0,
    CancelledByUser = 1,
    UnknownFailure = 2,
};

enum class EnterpriseStatus
{
    Enrolled = 0,
    Disabled = 1,
    Revoked = 2,
    Expired = 3,
};

}

}
