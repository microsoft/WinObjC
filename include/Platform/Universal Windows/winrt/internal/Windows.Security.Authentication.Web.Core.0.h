// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Security::Authentication::Web::Core {

struct IWebAccountEventArgs;
struct IWebAccountMonitor;
struct IWebAuthenticationCoreManagerStatics;
struct IWebAuthenticationCoreManagerStatics2;
struct IWebAuthenticationCoreManagerStatics3;
struct IWebProviderError;
struct IWebProviderErrorFactory;
struct IWebTokenRequest;
struct IWebTokenRequest2;
struct IWebTokenRequestFactory;
struct IWebTokenRequestResult;
struct IWebTokenResponse;
struct IWebTokenResponseFactory;
struct WebAccountEventArgs;
struct WebAccountMonitor;
struct WebProviderError;
struct WebTokenRequest;
struct WebTokenRequestResult;
struct WebTokenResponse;

}

namespace Windows::Security::Authentication::Web::Core {

struct IWebAccountEventArgs;
struct IWebAccountMonitor;
struct IWebAuthenticationCoreManagerStatics;
struct IWebAuthenticationCoreManagerStatics2;
struct IWebAuthenticationCoreManagerStatics3;
struct IWebProviderError;
struct IWebProviderErrorFactory;
struct IWebTokenRequest;
struct IWebTokenRequest2;
struct IWebTokenRequestFactory;
struct IWebTokenRequestResult;
struct IWebTokenResponse;
struct IWebTokenResponseFactory;
struct WebAccountEventArgs;
struct WebAccountMonitor;
struct WebAuthenticationCoreManager;
struct WebProviderError;
struct WebTokenRequest;
struct WebTokenRequestResult;
struct WebTokenResponse;

}

namespace Windows::Security::Authentication::Web::Core {

template <typename T> struct impl_IWebAccountEventArgs;
template <typename T> struct impl_IWebAccountMonitor;
template <typename T> struct impl_IWebAuthenticationCoreManagerStatics;
template <typename T> struct impl_IWebAuthenticationCoreManagerStatics2;
template <typename T> struct impl_IWebAuthenticationCoreManagerStatics3;
template <typename T> struct impl_IWebProviderError;
template <typename T> struct impl_IWebProviderErrorFactory;
template <typename T> struct impl_IWebTokenRequest;
template <typename T> struct impl_IWebTokenRequest2;
template <typename T> struct impl_IWebTokenRequestFactory;
template <typename T> struct impl_IWebTokenRequestResult;
template <typename T> struct impl_IWebTokenResponse;
template <typename T> struct impl_IWebTokenResponseFactory;

}

namespace Windows::Security::Authentication::Web::Core {

enum class WebTokenRequestPromptType
{
    Default = 0,
    ForceAuthentication = 1,
};

enum class WebTokenRequestStatus
{
    Success = 0,
    UserCancel = 1,
    AccountSwitch = 2,
    UserInteractionRequired = 3,
    AccountProviderNotAvailable = 4,
    ProviderError = 5,
};

}

}
