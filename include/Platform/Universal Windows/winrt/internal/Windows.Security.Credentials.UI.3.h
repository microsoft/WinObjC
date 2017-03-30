// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Security.Credentials.UI.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Security::Credentials::UI {

struct CredentialPicker
{
    CredentialPicker() = delete;
    static Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::UI::CredentialPickerResults> PickAsync(const Windows::Security::Credentials::UI::CredentialPickerOptions & options);
    static Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::UI::CredentialPickerResults> PickAsync(hstring_view targetName, hstring_view message);
    static Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::UI::CredentialPickerResults> PickAsync(hstring_view targetName, hstring_view message, hstring_view caption);
};

struct WINRT_EBO CredentialPickerOptions :
    Windows::Security::Credentials::UI::ICredentialPickerOptions
{
    CredentialPickerOptions(std::nullptr_t) noexcept {}
    CredentialPickerOptions();
};

struct WINRT_EBO CredentialPickerResults :
    Windows::Security::Credentials::UI::ICredentialPickerResults
{
    CredentialPickerResults(std::nullptr_t) noexcept {}
};

struct UserConsentVerifier
{
    UserConsentVerifier() = delete;
    static Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Credentials::UI::UserConsentVerifierAvailability> CheckAvailabilityAsync();
    static Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Credentials::UI::UserConsentVerificationResult> RequestVerificationAsync(hstring_view message);
};

}

}
