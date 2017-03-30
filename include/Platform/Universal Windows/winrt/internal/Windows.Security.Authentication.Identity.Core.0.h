// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Security::Authentication::Identity::Core {

struct IMicrosoftAccountMultiFactorAuthenticationManager;
struct IMicrosoftAccountMultiFactorAuthenticatorStatics;
struct IMicrosoftAccountMultiFactorGetSessionsResult;
struct IMicrosoftAccountMultiFactorOneTimeCodedInfo;
struct IMicrosoftAccountMultiFactorSessionInfo;
struct IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo;
struct MicrosoftAccountMultiFactorAuthenticationManager;
struct MicrosoftAccountMultiFactorGetSessionsResult;
struct MicrosoftAccountMultiFactorOneTimeCodedInfo;
struct MicrosoftAccountMultiFactorSessionInfo;
struct MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo;

}

namespace Windows::Security::Authentication::Identity::Core {

struct IMicrosoftAccountMultiFactorAuthenticationManager;
struct IMicrosoftAccountMultiFactorAuthenticatorStatics;
struct IMicrosoftAccountMultiFactorGetSessionsResult;
struct IMicrosoftAccountMultiFactorOneTimeCodedInfo;
struct IMicrosoftAccountMultiFactorSessionInfo;
struct IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo;
struct MicrosoftAccountMultiFactorAuthenticationManager;
struct MicrosoftAccountMultiFactorGetSessionsResult;
struct MicrosoftAccountMultiFactorOneTimeCodedInfo;
struct MicrosoftAccountMultiFactorSessionInfo;
struct MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo;

}

namespace Windows::Security::Authentication::Identity::Core {

template <typename T> struct impl_IMicrosoftAccountMultiFactorAuthenticationManager;
template <typename T> struct impl_IMicrosoftAccountMultiFactorAuthenticatorStatics;
template <typename T> struct impl_IMicrosoftAccountMultiFactorGetSessionsResult;
template <typename T> struct impl_IMicrosoftAccountMultiFactorOneTimeCodedInfo;
template <typename T> struct impl_IMicrosoftAccountMultiFactorSessionInfo;
template <typename T> struct impl_IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo;

}

namespace Windows::Security::Authentication::Identity::Core {

enum class MicrosoftAccountMultiFactorAuthenticationType
{
    User = 0,
    Device = 1,
};

enum class MicrosoftAccountMultiFactorServiceResponse
{
    Success = 0,
    Error = 1,
    NoNetworkConnection = 2,
    ServiceUnavailable = 3,
    TotpSetupDenied = 4,
    NgcNotSetup = 5,
    SessionAlreadyDenied = 6,
    SessionAlreadyApproved = 7,
    SessionExpired = 8,
    NgcNonceExpired = 9,
    InvalidSessionId = 10,
    InvalidSessionType = 11,
    InvalidOperation = 12,
    InvalidStateTransition = 13,
    DeviceNotFound = 14,
    FlowDisabled = 15,
    SessionNotApproved = 16,
    OperationCanceledByUser = 17,
    NgcDisabledByServer = 18,
    NgcKeyNotFoundOnServer = 19,
    UIRequired = 20,
    DeviceIdChanged = 21,
};

enum class MicrosoftAccountMultiFactorSessionApprovalStatus
{
    Pending = 0,
    Approved = 1,
    Denied = 2,
};

enum class MicrosoftAccountMultiFactorSessionAuthenticationStatus
{
    Authenticated = 0,
    Unauthenticated = 1,
};

}

}
