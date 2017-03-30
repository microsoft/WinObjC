// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Security.Authentication.Identity.Provider.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Security::Authentication::Identity::Provider {

struct WINRT_EBO SecondaryAuthenticationFactorAuthentication :
    Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication
{
    SecondaryAuthenticationFactorAuthentication(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncAction ShowNotificationMessageAsync(hstring_view deviceName, Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationMessage message);
    static Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationResult> StartAuthenticationAsync(hstring_view deviceId, const Windows::Storage::Streams::IBuffer & serviceAuthenticationNonce);
    static event_token AuthenticationStageChanged(const Windows::Foundation::EventHandler<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs> & handler);
    using AuthenticationStageChanged_revoker = factory_event_revoker<ISecondaryAuthenticationFactorAuthenticationStatics>;
    static AuthenticationStageChanged_revoker AuthenticationStageChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs> & handler);
    static void AuthenticationStageChanged(event_token token);
    static Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageInfo> GetAuthenticationStageInfoAsync();
};

struct WINRT_EBO SecondaryAuthenticationFactorAuthenticationResult :
    Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationResult
{
    SecondaryAuthenticationFactorAuthenticationResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs :
    Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs
{
    SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SecondaryAuthenticationFactorAuthenticationStageInfo :
    Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageInfo
{
    SecondaryAuthenticationFactorAuthenticationStageInfo(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SecondaryAuthenticationFactorInfo :
    Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo
{
    SecondaryAuthenticationFactorInfo(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SecondaryAuthenticationFactorRegistration :
    Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistration
{
    SecondaryAuthenticationFactorRegistration(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationResult> RequestStartRegisteringDeviceAsync(hstring_view deviceId, Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDeviceCapabilities capabilities, hstring_view deviceFriendlyName, hstring_view deviceModelNumber, const Windows::Storage::Streams::IBuffer & deviceKey, const Windows::Storage::Streams::IBuffer & mutualAuthenticationKey);
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorInfo>> FindAllRegisteredDeviceInfoAsync(Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDeviceFindScope queryType);
    static Windows::Foundation::IAsyncAction UnregisterDeviceAsync(hstring_view deviceId);
    static Windows::Foundation::IAsyncAction UpdateDeviceConfigurationDataAsync(hstring_view deviceId, const Windows::Storage::Streams::IBuffer & deviceConfigurationData);
};

struct WINRT_EBO SecondaryAuthenticationFactorRegistrationResult :
    Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationResult
{
    SecondaryAuthenticationFactorRegistrationResult(std::nullptr_t) noexcept {}
};

}

}
