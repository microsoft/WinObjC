// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Security::Authentication::Web {

struct IWebAuthenticationBrokerStatics;
struct IWebAuthenticationBrokerStatics2;
struct IWebAuthenticationResult;
struct WebAuthenticationResult;

}

namespace Windows::Security::Authentication::Web {

struct IWebAuthenticationBrokerStatics;
struct IWebAuthenticationBrokerStatics2;
struct IWebAuthenticationResult;
struct WebAuthenticationBroker;
struct WebAuthenticationResult;

}

namespace Windows::Security::Authentication::Web {

template <typename T> struct impl_IWebAuthenticationBrokerStatics;
template <typename T> struct impl_IWebAuthenticationBrokerStatics2;
template <typename T> struct impl_IWebAuthenticationResult;

}

namespace Windows::Security::Authentication::Web {

enum class TokenBindingKeyType
{
    Rsa2048 = 0,
    EcdsaP256 = 1,
    AnyExisting = 2,
};

enum class WebAuthenticationOptions : unsigned
{
    None = 0x0,
    SilentMode = 0x1,
    UseTitle = 0x2,
    UseHttpPost = 0x4,
    UseCorporateNetwork = 0x8,
};

DEFINE_ENUM_FLAG_OPERATORS(WebAuthenticationOptions)

enum class WebAuthenticationStatus
{
    Success = 0,
    UserCancel = 1,
    ErrorHttp = 2,
};

}

}
