// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Security::Credentials {

struct ICredentialFactory;
struct IKeyCredential;
struct IKeyCredentialAttestationResult;
struct IKeyCredentialManagerStatics;
struct IKeyCredentialOperationResult;
struct IKeyCredentialRetrievalResult;
struct IPasswordCredential;
struct IPasswordVault;
struct IWebAccount;
struct IWebAccount2;
struct IWebAccountFactory;
struct IWebAccountProvider;
struct IWebAccountProvider2;
struct IWebAccountProvider3;
struct IWebAccountProviderFactory;
struct KeyCredential;
struct KeyCredentialAttestationResult;
struct KeyCredentialOperationResult;
struct KeyCredentialRetrievalResult;
struct PasswordCredential;
struct PasswordCredentialPropertyStore;
struct PasswordVault;
struct WebAccount;
struct WebAccountProvider;

}

namespace Windows::Security::Credentials {

struct ICredentialFactory;
struct IKeyCredential;
struct IKeyCredentialAttestationResult;
struct IKeyCredentialManagerStatics;
struct IKeyCredentialOperationResult;
struct IKeyCredentialRetrievalResult;
struct IPasswordCredential;
struct IPasswordVault;
struct IWebAccount;
struct IWebAccount2;
struct IWebAccountFactory;
struct IWebAccountProvider;
struct IWebAccountProvider2;
struct IWebAccountProvider3;
struct IWebAccountProviderFactory;
struct KeyCredential;
struct KeyCredentialAttestationResult;
struct KeyCredentialManager;
struct KeyCredentialOperationResult;
struct KeyCredentialRetrievalResult;
struct PasswordCredential;
struct PasswordCredentialPropertyStore;
struct PasswordVault;
struct WebAccount;
struct WebAccountProvider;

}

namespace Windows::Security::Credentials {

template <typename T> struct impl_ICredentialFactory;
template <typename T> struct impl_IKeyCredential;
template <typename T> struct impl_IKeyCredentialAttestationResult;
template <typename T> struct impl_IKeyCredentialManagerStatics;
template <typename T> struct impl_IKeyCredentialOperationResult;
template <typename T> struct impl_IKeyCredentialRetrievalResult;
template <typename T> struct impl_IPasswordCredential;
template <typename T> struct impl_IPasswordVault;
template <typename T> struct impl_IWebAccount;
template <typename T> struct impl_IWebAccount2;
template <typename T> struct impl_IWebAccountFactory;
template <typename T> struct impl_IWebAccountProvider;
template <typename T> struct impl_IWebAccountProvider2;
template <typename T> struct impl_IWebAccountProvider3;
template <typename T> struct impl_IWebAccountProviderFactory;

}

namespace Windows::Security::Credentials {

enum class KeyCredentialAttestationStatus
{
    Success = 0,
    UnknownError = 1,
    NotSupported = 2,
    TemporaryFailure = 3,
};

enum class KeyCredentialCreationOption
{
    ReplaceExisting = 0,
    FailIfExists = 1,
};

enum class KeyCredentialStatus
{
    Success = 0,
    UnknownError = 1,
    NotFound = 2,
    UserCanceled = 3,
    UserPrefersPassword = 4,
    CredentialAlreadyExists = 5,
    SecurityDeviceLocked = 6,
};

enum class WebAccountPictureSize
{
    Size64x64 = 64,
    Size208x208 = 208,
    Size424x424 = 424,
    Size1080x1080 = 1080,
};

enum class WebAccountState
{
    None = 0,
    Connected = 1,
    Error = 2,
};

}

}
