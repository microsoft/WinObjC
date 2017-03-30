// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Security::ExchangeActiveSyncProvisioning {

struct IEasClientDeviceInformation;
struct IEasClientDeviceInformation2;
struct IEasClientSecurityPolicy;
struct IEasComplianceResults;
struct IEasComplianceResults2;
struct EasClientDeviceInformation;
struct EasClientSecurityPolicy;
struct EasComplianceResults;

}

namespace Windows::Security::ExchangeActiveSyncProvisioning {

struct IEasClientDeviceInformation;
struct IEasClientDeviceInformation2;
struct IEasClientSecurityPolicy;
struct IEasComplianceResults;
struct IEasComplianceResults2;
struct EasClientDeviceInformation;
struct EasClientSecurityPolicy;
struct EasComplianceResults;

}

namespace Windows::Security::ExchangeActiveSyncProvisioning {

template <typename T> struct impl_IEasClientDeviceInformation;
template <typename T> struct impl_IEasClientDeviceInformation2;
template <typename T> struct impl_IEasClientSecurityPolicy;
template <typename T> struct impl_IEasComplianceResults;
template <typename T> struct impl_IEasComplianceResults2;

}

namespace Windows::Security::ExchangeActiveSyncProvisioning {

enum class EasDisallowConvenienceLogonResult
{
    NotEvaluated = 0,
    Compliant = 1,
    CanBeCompliant = 2,
    RequestedPolicyIsStricter = 3,
};

enum class EasEncryptionProviderType
{
    NotEvaluated = 0,
    WindowsEncryption = 1,
    OtherEncryption = 2,
};

enum class EasMaxInactivityTimeLockResult
{
    NotEvaluated = 0,
    Compliant = 1,
    CanBeCompliant = 2,
    RequestedPolicyIsStricter = 3,
    InvalidParameter = 4,
};

enum class EasMaxPasswordFailedAttemptsResult
{
    NotEvaluated = 0,
    Compliant = 1,
    CanBeCompliant = 2,
    RequestedPolicyIsStricter = 3,
    InvalidParameter = 4,
};

enum class EasMinPasswordComplexCharactersResult
{
    NotEvaluated = 0,
    Compliant = 1,
    CanBeCompliant = 2,
    RequestedPolicyIsStricter = 3,
    RequestedPolicyNotEnforceable = 4,
    InvalidParameter = 5,
    CurrentUserHasBlankPassword = 6,
    AdminsHaveBlankPassword = 7,
    UserCannotChangePassword = 8,
    AdminsCannotChangePassword = 9,
    LocalControlledUsersCannotChangePassword = 10,
    ConnectedAdminsProviderPolicyIsWeak = 11,
    ConnectedUserProviderPolicyIsWeak = 12,
    ChangeConnectedAdminsPassword = 13,
    ChangeConnectedUserPassword = 14,
};

enum class EasMinPasswordLengthResult
{
    NotEvaluated = 0,
    Compliant = 1,
    CanBeCompliant = 2,
    RequestedPolicyIsStricter = 3,
    RequestedPolicyNotEnforceable = 4,
    InvalidParameter = 5,
    CurrentUserHasBlankPassword = 6,
    AdminsHaveBlankPassword = 7,
    UserCannotChangePassword = 8,
    AdminsCannotChangePassword = 9,
    LocalControlledUsersCannotChangePassword = 10,
    ConnectedAdminsProviderPolicyIsWeak = 11,
    ConnectedUserProviderPolicyIsWeak = 12,
    ChangeConnectedAdminsPassword = 13,
    ChangeConnectedUserPassword = 14,
};

enum class EasPasswordExpirationResult
{
    NotEvaluated = 0,
    Compliant = 1,
    CanBeCompliant = 2,
    RequestedPolicyIsStricter = 3,
    RequestedExpirationIncompatible = 4,
    InvalidParameter = 5,
    UserCannotChangePassword = 6,
    AdminsCannotChangePassword = 7,
    LocalControlledUsersCannotChangePassword = 8,
};

enum class EasPasswordHistoryResult
{
    NotEvaluated = 0,
    Compliant = 1,
    CanBeCompliant = 2,
    RequestedPolicyIsStricter = 3,
    InvalidParameter = 4,
};

enum class EasRequireEncryptionResult
{
    NotEvaluated = 0,
    Compliant = 1,
    CanBeCompliant = 2,
    NotProvisionedOnAllVolumes = 3,
    DeFixedDataNotSupported [[deprecated("DeFixedDataNotSupported may be altered or unavailable for releases after Windows 8.1. Instead, use FixedDataNotSupported.")]] = 4,
    FixedDataNotSupported = 4,
    DeHardwareNotCompliant [[deprecated("DeHardwareNotCompliant may be altered or unavailable for releases after Windows 8.1. Instead, use HardwareNotCompliant.")]] = 5,
    HardwareNotCompliant = 5,
    DeWinReNotConfigured [[deprecated("DeWinReNotConfigured may be altered or unavailable for releases after Windows 8.1. Instead, use LockNotConfigured.")]] = 6,
    LockNotConfigured = 6,
    DeProtectionSuspended [[deprecated("DeProtectionSuspended may be altered or unavailable for releases after Windows 8.1. Instead, use ProtectionSuspended.")]] = 7,
    ProtectionSuspended = 7,
    DeOsVolumeNotProtected [[deprecated("DeOsVolumeNotProtected may be altered or unavailable for releases after Windows 8.1. Instead, use OsVolumeNotProtected.")]] = 8,
    OsVolumeNotProtected = 8,
    DeProtectionNotYetEnabled [[deprecated("DeProtectionNotYetEnabled may be altered or unavailable for releases after Windows 8.1. Instead, use ProtectionNotYetEnabled.")]] = 9,
    ProtectionNotYetEnabled = 9,
    NoFeatureLicense = 10,
    OsNotProtected = 11,
    UnexpectedFailure = 12,
};

}

}
