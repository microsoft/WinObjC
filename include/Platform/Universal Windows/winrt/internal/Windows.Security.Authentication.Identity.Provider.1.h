// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Security.Authentication.Identity.Provider.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Security::Authentication::Identity::Provider {

struct __declspec(uuid("020a16e5-6a25-40a3-8c00-50a023f619d1")) __declspec(novtable) ISecondaryAuthenticationFactorAuthentication : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ServiceAuthenticationHmac(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall get_SessionNonce(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall get_DeviceNonce(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall get_DeviceConfigurationData(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall abi_FinishAuthenticationAsync(Windows::Storage::Streams::IBuffer * deviceHmac, Windows::Storage::Streams::IBuffer * sessionHmac, Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorFinishAuthenticationStatus> ** result) = 0;
    virtual HRESULT __stdcall abi_AbortAuthenticationAsync(hstring errorLogMessage, Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("9cbb5987-ef6d-4bc2-bf49-4617515a0f9a")) __declspec(novtable) ISecondaryAuthenticationFactorAuthenticationResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(winrt::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStatus * value) = 0;
    virtual HRESULT __stdcall get_Authentication(Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication ** value) = 0;
};

struct __declspec(uuid("d4a5ee56-7291-4073-bc1f-ccb8f5afdf96")) __declspec(novtable) ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_StageInfo(Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageInfo ** value) = 0;
};

struct __declspec(uuid("56fec28b-e8aa-4c0f-8e4c-a559e73add88")) __declspec(novtable) ISecondaryAuthenticationFactorAuthenticationStageInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Stage(winrt::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStage * value) = 0;
    virtual HRESULT __stdcall get_Scenario(winrt::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationScenario * value) = 0;
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
};

struct __declspec(uuid("3f582656-28f8-4e0f-ae8c-5898b9ae2469")) __declspec(novtable) ISecondaryAuthenticationFactorAuthenticationStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ShowNotificationMessageAsync(hstring deviceName, winrt::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationMessage message, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_StartAuthenticationAsync(hstring deviceId, Windows::Storage::Streams::IBuffer * serviceAuthenticationNonce, Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationResult> ** operation) = 0;
    virtual HRESULT __stdcall add_AuthenticationStageChanged(Windows::Foundation::EventHandler<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_AuthenticationStageChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_GetAuthenticationStageInfoAsync(Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageInfo> ** result) = 0;
};

struct __declspec(uuid("1e2ba861-8533-4fce-839b-ecb72410ac14")) __declspec(novtable) ISecondaryAuthenticationFactorInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * deviceId) = 0;
    virtual HRESULT __stdcall get_DeviceFriendlyName(hstring * value) = 0;
    virtual HRESULT __stdcall get_DeviceModelNumber(hstring * value) = 0;
    virtual HRESULT __stdcall get_DeviceConfigurationData(Windows::Storage::Streams::IBuffer ** value) = 0;
};

struct __declspec(uuid("9f4cbbb4-8cba-48b0-840d-dbb22a54c678")) __declspec(novtable) ISecondaryAuthenticationFactorRegistration : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FinishRegisteringDeviceAsync(Windows::Storage::Streams::IBuffer * deviceConfigurationData, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_AbortRegisteringDeviceAsync(hstring errorLogMessage, Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("a4fe35f0-ade3-4981-af6b-ec195921682a")) __declspec(novtable) ISecondaryAuthenticationFactorRegistrationResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(winrt::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationStatus * value) = 0;
    virtual HRESULT __stdcall get_Registration(Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistration ** value) = 0;
};

struct __declspec(uuid("1adf0f65-e3b7-4155-997f-b756ef65beba")) __declspec(novtable) ISecondaryAuthenticationFactorRegistrationStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RequestStartRegisteringDeviceAsync(hstring deviceId, winrt::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDeviceCapabilities capabilities, hstring deviceFriendlyName, hstring deviceModelNumber, Windows::Storage::Streams::IBuffer * deviceKey, Windows::Storage::Streams::IBuffer * mutualAuthenticationKey, Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationResult> ** operation) = 0;
    virtual HRESULT __stdcall abi_FindAllRegisteredDeviceInfoAsync(winrt::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDeviceFindScope queryType, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorInfo>> ** deviceInfoList) = 0;
    virtual HRESULT __stdcall abi_UnregisterDeviceAsync(hstring deviceId, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_UpdateDeviceConfigurationDataAsync(hstring deviceId, Windows::Storage::Streams::IBuffer * deviceConfigurationData, Windows::Foundation::IAsyncAction ** result) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthentication> { using default_interface = Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication; };
template <> struct traits<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationResult> { using default_interface = Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationResult; };
template <> struct traits<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs> { using default_interface = Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs; };
template <> struct traits<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageInfo> { using default_interface = Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageInfo; };
template <> struct traits<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorInfo> { using default_interface = Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo; };
template <> struct traits<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistration> { using default_interface = Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistration; };
template <> struct traits<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationResult> { using default_interface = Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationResult; };

}

namespace Windows::Security::Authentication::Identity::Provider {

template <typename D>
struct WINRT_EBO impl_ISecondaryAuthenticationFactorAuthentication
{
    Windows::Storage::Streams::IBuffer ServiceAuthenticationHmac() const;
    Windows::Storage::Streams::IBuffer SessionNonce() const;
    Windows::Storage::Streams::IBuffer DeviceNonce() const;
    Windows::Storage::Streams::IBuffer DeviceConfigurationData() const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorFinishAuthenticationStatus> FinishAuthenticationAsync(const Windows::Storage::Streams::IBuffer & deviceHmac, const Windows::Storage::Streams::IBuffer & sessionHmac) const;
    Windows::Foundation::IAsyncAction AbortAuthenticationAsync(hstring_view errorLogMessage) const;
};

template <typename D>
struct WINRT_EBO impl_ISecondaryAuthenticationFactorAuthenticationResult
{
    Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStatus Status() const;
    Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthentication Authentication() const;
};

template <typename D>
struct WINRT_EBO impl_ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs
{
    Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageInfo StageInfo() const;
};

template <typename D>
struct WINRT_EBO impl_ISecondaryAuthenticationFactorAuthenticationStageInfo
{
    Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStage Stage() const;
    Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationScenario Scenario() const;
    hstring DeviceId() const;
};

template <typename D>
struct WINRT_EBO impl_ISecondaryAuthenticationFactorAuthenticationStatics
{
    Windows::Foundation::IAsyncAction ShowNotificationMessageAsync(hstring_view deviceName, Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationMessage message) const;
    Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationResult> StartAuthenticationAsync(hstring_view deviceId, const Windows::Storage::Streams::IBuffer & serviceAuthenticationNonce) const;
    event_token AuthenticationStageChanged(const Windows::Foundation::EventHandler<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs> & handler) const;
    using AuthenticationStageChanged_revoker = event_revoker<ISecondaryAuthenticationFactorAuthenticationStatics>;
    AuthenticationStageChanged_revoker AuthenticationStageChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs> & handler) const;
    void AuthenticationStageChanged(event_token token) const;
    Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageInfo> GetAuthenticationStageInfoAsync() const;
};

template <typename D>
struct WINRT_EBO impl_ISecondaryAuthenticationFactorInfo
{
    hstring DeviceId() const;
    hstring DeviceFriendlyName() const;
    hstring DeviceModelNumber() const;
    Windows::Storage::Streams::IBuffer DeviceConfigurationData() const;
};

template <typename D>
struct WINRT_EBO impl_ISecondaryAuthenticationFactorRegistration
{
    Windows::Foundation::IAsyncAction FinishRegisteringDeviceAsync(const Windows::Storage::Streams::IBuffer & deviceConfigurationData) const;
    Windows::Foundation::IAsyncAction AbortRegisteringDeviceAsync(hstring_view errorLogMessage) const;
};

template <typename D>
struct WINRT_EBO impl_ISecondaryAuthenticationFactorRegistrationResult
{
    Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationStatus Status() const;
    Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistration Registration() const;
};

template <typename D>
struct WINRT_EBO impl_ISecondaryAuthenticationFactorRegistrationStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationResult> RequestStartRegisteringDeviceAsync(hstring_view deviceId, Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDeviceCapabilities capabilities, hstring_view deviceFriendlyName, hstring_view deviceModelNumber, const Windows::Storage::Streams::IBuffer & deviceKey, const Windows::Storage::Streams::IBuffer & mutualAuthenticationKey) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorInfo>> FindAllRegisteredDeviceInfoAsync(Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDeviceFindScope queryType) const;
    Windows::Foundation::IAsyncAction UnregisterDeviceAsync(hstring_view deviceId) const;
    Windows::Foundation::IAsyncAction UpdateDeviceConfigurationDataAsync(hstring_view deviceId, const Windows::Storage::Streams::IBuffer & deviceConfigurationData) const;
};

}

namespace impl {

template <> struct traits<Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication>
{
    using abi = ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication;
    template <typename D> using consume = Windows::Security::Authentication::Identity::Provider::impl_ISecondaryAuthenticationFactorAuthentication<D>;
};

template <> struct traits<Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationResult>
{
    using abi = ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationResult;
    template <typename D> using consume = Windows::Security::Authentication::Identity::Provider::impl_ISecondaryAuthenticationFactorAuthenticationResult<D>;
};

template <> struct traits<Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs>
{
    using abi = ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs;
    template <typename D> using consume = Windows::Security::Authentication::Identity::Provider::impl_ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs<D>;
};

template <> struct traits<Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageInfo>
{
    using abi = ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageInfo;
    template <typename D> using consume = Windows::Security::Authentication::Identity::Provider::impl_ISecondaryAuthenticationFactorAuthenticationStageInfo<D>;
};

template <> struct traits<Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStatics>
{
    using abi = ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStatics;
    template <typename D> using consume = Windows::Security::Authentication::Identity::Provider::impl_ISecondaryAuthenticationFactorAuthenticationStatics<D>;
};

template <> struct traits<Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo>
{
    using abi = ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo;
    template <typename D> using consume = Windows::Security::Authentication::Identity::Provider::impl_ISecondaryAuthenticationFactorInfo<D>;
};

template <> struct traits<Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistration>
{
    using abi = ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistration;
    template <typename D> using consume = Windows::Security::Authentication::Identity::Provider::impl_ISecondaryAuthenticationFactorRegistration<D>;
};

template <> struct traits<Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationResult>
{
    using abi = ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationResult;
    template <typename D> using consume = Windows::Security::Authentication::Identity::Provider::impl_ISecondaryAuthenticationFactorRegistrationResult<D>;
};

template <> struct traits<Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationStatics>
{
    using abi = ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationStatics;
    template <typename D> using consume = Windows::Security::Authentication::Identity::Provider::impl_ISecondaryAuthenticationFactorRegistrationStatics<D>;
};

template <> struct traits<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthentication>
{
    using abi = ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthentication;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorAuthentication"; }
};

template <> struct traits<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationResult>
{
    using abi = ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorAuthenticationResult"; }
};

template <> struct traits<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs>
{
    using abi = ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs"; }
};

template <> struct traits<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageInfo>
{
    using abi = ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorAuthenticationStageInfo"; }
};

template <> struct traits<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorInfo>
{
    using abi = ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorInfo"; }
};

template <> struct traits<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistration>
{
    using abi = ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistration;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorRegistration"; }
};

template <> struct traits<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationResult>
{
    using abi = ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorRegistrationResult"; }
};

}

}
