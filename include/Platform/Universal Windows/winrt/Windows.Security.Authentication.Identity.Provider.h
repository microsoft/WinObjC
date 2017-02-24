// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Security.Authentication.Identity.Provider.3.h"
#include "Windows.Security.Authentication.Identity.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication> : produce_base<D, Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication>
{
    HRESULT __stdcall get_ServiceAuthenticationHmac(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceAuthenticationHmac());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SessionNonce(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SessionNonce());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceNonce(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceNonce());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceConfigurationData(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceConfigurationData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FinishAuthenticationAsync(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> deviceHmac, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> sessionHmac, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorFinishAuthenticationStatus>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FinishAuthenticationAsync(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&deviceHmac), *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&sessionHmac)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AbortAuthenticationAsync(impl::abi_arg_in<hstring> errorLogMessage, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().AbortAuthenticationAsync(*reinterpret_cast<const hstring *>(&errorLogMessage)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationResult> : produce_base<D, Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationResult>
{
    HRESULT __stdcall get_Status(Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Authentication(impl::abi_arg_out<Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Authentication());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs> : produce_base<D, Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs>
{
    HRESULT __stdcall get_StageInfo(impl::abi_arg_out<Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StageInfo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageInfo> : produce_base<D, Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageInfo>
{
    HRESULT __stdcall get_Stage(Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStage * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Stage());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Scenario(Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationScenario * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Scenario());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStatics> : produce_base<D, Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStatics>
{
    HRESULT __stdcall abi_ShowNotificationMessageAsync(impl::abi_arg_in<hstring> deviceName, Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationMessage message, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ShowNotificationMessageAsync(*reinterpret_cast<const hstring *>(&deviceName), message));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartAuthenticationAsync(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> serviceAuthenticationNonce, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().StartAuthenticationAsync(*reinterpret_cast<const hstring *>(&deviceId), *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&serviceAuthenticationNonce)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_AuthenticationStageChanged(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().AuthenticationStageChanged(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AuthenticationStageChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AuthenticationStageChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAuthenticationStageInfoAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageInfo>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetAuthenticationStageInfoAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo> : produce_base<D, Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo>
{
    HRESULT __stdcall get_DeviceId(impl::abi_arg_out<hstring> deviceId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deviceId = detach_abi(this->shim().DeviceId());
            return S_OK;
        }
        catch (...)
        {
            *deviceId = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceFriendlyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceFriendlyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceModelNumber(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceModelNumber());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceConfigurationData(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceConfigurationData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistration> : produce_base<D, Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistration>
{
    HRESULT __stdcall abi_FinishRegisteringDeviceAsync(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> deviceConfigurationData, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FinishRegisteringDeviceAsync(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&deviceConfigurationData)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AbortRegisteringDeviceAsync(impl::abi_arg_in<hstring> errorLogMessage, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().AbortRegisteringDeviceAsync(*reinterpret_cast<const hstring *>(&errorLogMessage)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationResult> : produce_base<D, Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationResult>
{
    HRESULT __stdcall get_Status(Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Registration(impl::abi_arg_out<Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistration> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Registration());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationStatics> : produce_base<D, Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationStatics>
{
    HRESULT __stdcall abi_RequestStartRegisteringDeviceAsync(impl::abi_arg_in<hstring> deviceId, Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDeviceCapabilities capabilities, impl::abi_arg_in<hstring> deviceFriendlyName, impl::abi_arg_in<hstring> deviceModelNumber, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> deviceKey, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> mutualAuthenticationKey, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestStartRegisteringDeviceAsync(*reinterpret_cast<const hstring *>(&deviceId), capabilities, *reinterpret_cast<const hstring *>(&deviceFriendlyName), *reinterpret_cast<const hstring *>(&deviceModelNumber), *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&deviceKey), *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&mutualAuthenticationKey)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllRegisteredDeviceInfoAsync(Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDeviceFindScope queryType, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorInfo>>> deviceInfoList) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deviceInfoList = detach_abi(this->shim().FindAllRegisteredDeviceInfoAsync(queryType));
            return S_OK;
        }
        catch (...)
        {
            *deviceInfoList = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UnregisterDeviceAsync(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().UnregisterDeviceAsync(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateDeviceConfigurationDataAsync(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> deviceConfigurationData, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().UpdateDeviceConfigurationDataAsync(*reinterpret_cast<const hstring *>(&deviceId), *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&deviceConfigurationData)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Security::Authentication::Identity::Provider {

template <typename D> Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationStatus impl_ISecondaryAuthenticationFactorRegistrationResult<D>::Status() const
{
    Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationStatus value {};
    check_hresult(WINRT_SHIM(ISecondaryAuthenticationFactorRegistrationResult)->get_Status(&value));
    return value;
}

template <typename D> Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistration impl_ISecondaryAuthenticationFactorRegistrationResult<D>::Registration() const
{
    Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistration value { nullptr };
    check_hresult(WINRT_SHIM(ISecondaryAuthenticationFactorRegistrationResult)->get_Registration(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStatus impl_ISecondaryAuthenticationFactorAuthenticationResult<D>::Status() const
{
    Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStatus value {};
    check_hresult(WINRT_SHIM(ISecondaryAuthenticationFactorAuthenticationResult)->get_Status(&value));
    return value;
}

template <typename D> Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthentication impl_ISecondaryAuthenticationFactorAuthenticationResult<D>::Authentication() const
{
    Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthentication value { nullptr };
    check_hresult(WINRT_SHIM(ISecondaryAuthenticationFactorAuthenticationResult)->get_Authentication(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationResult> impl_ISecondaryAuthenticationFactorRegistrationStatics<D>::RequestStartRegisteringDeviceAsync(hstring_view deviceId, Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDeviceCapabilities capabilities, hstring_view deviceFriendlyName, hstring_view deviceModelNumber, const Windows::Storage::Streams::IBuffer & deviceKey, const Windows::Storage::Streams::IBuffer & mutualAuthenticationKey) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationResult> operation;
    check_hresult(WINRT_SHIM(ISecondaryAuthenticationFactorRegistrationStatics)->abi_RequestStartRegisteringDeviceAsync(get_abi(deviceId), capabilities, get_abi(deviceFriendlyName), get_abi(deviceModelNumber), get_abi(deviceKey), get_abi(mutualAuthenticationKey), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorInfo>> impl_ISecondaryAuthenticationFactorRegistrationStatics<D>::FindAllRegisteredDeviceInfoAsync(Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDeviceFindScope queryType) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorInfo>> deviceInfoList;
    check_hresult(WINRT_SHIM(ISecondaryAuthenticationFactorRegistrationStatics)->abi_FindAllRegisteredDeviceInfoAsync(queryType, put_abi(deviceInfoList)));
    return deviceInfoList;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISecondaryAuthenticationFactorRegistrationStatics<D>::UnregisterDeviceAsync(hstring_view deviceId) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(ISecondaryAuthenticationFactorRegistrationStatics)->abi_UnregisterDeviceAsync(get_abi(deviceId), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISecondaryAuthenticationFactorRegistrationStatics<D>::UpdateDeviceConfigurationDataAsync(hstring_view deviceId, const Windows::Storage::Streams::IBuffer & deviceConfigurationData) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(ISecondaryAuthenticationFactorRegistrationStatics)->abi_UpdateDeviceConfigurationDataAsync(get_abi(deviceId), get_abi(deviceConfigurationData), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISecondaryAuthenticationFactorRegistration<D>::FinishRegisteringDeviceAsync(const Windows::Storage::Streams::IBuffer & deviceConfigurationData) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(ISecondaryAuthenticationFactorRegistration)->abi_FinishRegisteringDeviceAsync(get_abi(deviceConfigurationData), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISecondaryAuthenticationFactorRegistration<D>::AbortRegisteringDeviceAsync(hstring_view errorLogMessage) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(ISecondaryAuthenticationFactorRegistration)->abi_AbortRegisteringDeviceAsync(get_abi(errorLogMessage), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISecondaryAuthenticationFactorAuthenticationStatics<D>::ShowNotificationMessageAsync(hstring_view deviceName, Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationMessage message) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(ISecondaryAuthenticationFactorAuthenticationStatics)->abi_ShowNotificationMessageAsync(get_abi(deviceName), message, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationResult> impl_ISecondaryAuthenticationFactorAuthenticationStatics<D>::StartAuthenticationAsync(hstring_view deviceId, const Windows::Storage::Streams::IBuffer & serviceAuthenticationNonce) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationResult> operation;
    check_hresult(WINRT_SHIM(ISecondaryAuthenticationFactorAuthenticationStatics)->abi_StartAuthenticationAsync(get_abi(deviceId), get_abi(serviceAuthenticationNonce), put_abi(operation)));
    return operation;
}

template <typename D> event_token impl_ISecondaryAuthenticationFactorAuthenticationStatics<D>::AuthenticationStageChanged(const Windows::Foundation::EventHandler<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ISecondaryAuthenticationFactorAuthenticationStatics)->add_AuthenticationStageChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ISecondaryAuthenticationFactorAuthenticationStatics> impl_ISecondaryAuthenticationFactorAuthenticationStatics<D>::AuthenticationStageChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ISecondaryAuthenticationFactorAuthenticationStatics>(this, &ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStatics::remove_AuthenticationStageChanged, AuthenticationStageChanged(handler));
}

template <typename D> void impl_ISecondaryAuthenticationFactorAuthenticationStatics<D>::AuthenticationStageChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(ISecondaryAuthenticationFactorAuthenticationStatics)->remove_AuthenticationStageChanged(token));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageInfo> impl_ISecondaryAuthenticationFactorAuthenticationStatics<D>::GetAuthenticationStageInfoAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageInfo> result;
    check_hresult(WINRT_SHIM(ISecondaryAuthenticationFactorAuthenticationStatics)->abi_GetAuthenticationStageInfoAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ISecondaryAuthenticationFactorAuthentication<D>::ServiceAuthenticationHmac() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(ISecondaryAuthenticationFactorAuthentication)->get_ServiceAuthenticationHmac(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ISecondaryAuthenticationFactorAuthentication<D>::SessionNonce() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(ISecondaryAuthenticationFactorAuthentication)->get_SessionNonce(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ISecondaryAuthenticationFactorAuthentication<D>::DeviceNonce() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(ISecondaryAuthenticationFactorAuthentication)->get_DeviceNonce(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ISecondaryAuthenticationFactorAuthentication<D>::DeviceConfigurationData() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(ISecondaryAuthenticationFactorAuthentication)->get_DeviceConfigurationData(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorFinishAuthenticationStatus> impl_ISecondaryAuthenticationFactorAuthentication<D>::FinishAuthenticationAsync(const Windows::Storage::Streams::IBuffer & deviceHmac, const Windows::Storage::Streams::IBuffer & sessionHmac) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorFinishAuthenticationStatus> result;
    check_hresult(WINRT_SHIM(ISecondaryAuthenticationFactorAuthentication)->abi_FinishAuthenticationAsync(get_abi(deviceHmac), get_abi(sessionHmac), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISecondaryAuthenticationFactorAuthentication<D>::AbortAuthenticationAsync(hstring_view errorLogMessage) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(ISecondaryAuthenticationFactorAuthentication)->abi_AbortAuthenticationAsync(get_abi(errorLogMessage), put_abi(result)));
    return result;
}

template <typename D> hstring impl_ISecondaryAuthenticationFactorInfo<D>::DeviceId() const
{
    hstring deviceId;
    check_hresult(WINRT_SHIM(ISecondaryAuthenticationFactorInfo)->get_DeviceId(put_abi(deviceId)));
    return deviceId;
}

template <typename D> hstring impl_ISecondaryAuthenticationFactorInfo<D>::DeviceFriendlyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISecondaryAuthenticationFactorInfo)->get_DeviceFriendlyName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISecondaryAuthenticationFactorInfo<D>::DeviceModelNumber() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISecondaryAuthenticationFactorInfo)->get_DeviceModelNumber(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ISecondaryAuthenticationFactorInfo<D>::DeviceConfigurationData() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(ISecondaryAuthenticationFactorInfo)->get_DeviceConfigurationData(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStage impl_ISecondaryAuthenticationFactorAuthenticationStageInfo<D>::Stage() const
{
    Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStage value {};
    check_hresult(WINRT_SHIM(ISecondaryAuthenticationFactorAuthenticationStageInfo)->get_Stage(&value));
    return value;
}

template <typename D> Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationScenario impl_ISecondaryAuthenticationFactorAuthenticationStageInfo<D>::Scenario() const
{
    Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationScenario value {};
    check_hresult(WINRT_SHIM(ISecondaryAuthenticationFactorAuthenticationStageInfo)->get_Scenario(&value));
    return value;
}

template <typename D> hstring impl_ISecondaryAuthenticationFactorAuthenticationStageInfo<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISecondaryAuthenticationFactorAuthenticationStageInfo)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageInfo impl_ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs<D>::StageInfo() const
{
    Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageInfo value { nullptr };
    check_hresult(WINRT_SHIM(ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs)->get_StageInfo(put_abi(value)));
    return value;
}

inline Windows::Foundation::IAsyncAction SecondaryAuthenticationFactorAuthentication::ShowNotificationMessageAsync(hstring_view deviceName, Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationMessage message)
{
    return get_activation_factory<SecondaryAuthenticationFactorAuthentication, ISecondaryAuthenticationFactorAuthenticationStatics>().ShowNotificationMessageAsync(deviceName, message);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationResult> SecondaryAuthenticationFactorAuthentication::StartAuthenticationAsync(hstring_view deviceId, const Windows::Storage::Streams::IBuffer & serviceAuthenticationNonce)
{
    return get_activation_factory<SecondaryAuthenticationFactorAuthentication, ISecondaryAuthenticationFactorAuthenticationStatics>().StartAuthenticationAsync(deviceId, serviceAuthenticationNonce);
}

inline event_token SecondaryAuthenticationFactorAuthentication::AuthenticationStageChanged(const Windows::Foundation::EventHandler<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs> & handler)
{
    return get_activation_factory<SecondaryAuthenticationFactorAuthentication, ISecondaryAuthenticationFactorAuthenticationStatics>().AuthenticationStageChanged(handler);
}

inline factory_event_revoker<ISecondaryAuthenticationFactorAuthenticationStatics> SecondaryAuthenticationFactorAuthentication::AuthenticationStageChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs> & handler)
{
    auto factory = get_activation_factory<SecondaryAuthenticationFactorAuthentication, ISecondaryAuthenticationFactorAuthenticationStatics>();
    return { factory, &ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStatics::remove_AuthenticationStageChanged, factory.AuthenticationStageChanged(handler) };
}

inline void SecondaryAuthenticationFactorAuthentication::AuthenticationStageChanged(event_token token)
{
    get_activation_factory<SecondaryAuthenticationFactorAuthentication, ISecondaryAuthenticationFactorAuthenticationStatics>().AuthenticationStageChanged(token);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageInfo> SecondaryAuthenticationFactorAuthentication::GetAuthenticationStageInfoAsync()
{
    return get_activation_factory<SecondaryAuthenticationFactorAuthentication, ISecondaryAuthenticationFactorAuthenticationStatics>().GetAuthenticationStageInfoAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationResult> SecondaryAuthenticationFactorRegistration::RequestStartRegisteringDeviceAsync(hstring_view deviceId, Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDeviceCapabilities capabilities, hstring_view deviceFriendlyName, hstring_view deviceModelNumber, const Windows::Storage::Streams::IBuffer & deviceKey, const Windows::Storage::Streams::IBuffer & mutualAuthenticationKey)
{
    return get_activation_factory<SecondaryAuthenticationFactorRegistration, ISecondaryAuthenticationFactorRegistrationStatics>().RequestStartRegisteringDeviceAsync(deviceId, capabilities, deviceFriendlyName, deviceModelNumber, deviceKey, mutualAuthenticationKey);
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorInfo>> SecondaryAuthenticationFactorRegistration::FindAllRegisteredDeviceInfoAsync(Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDeviceFindScope queryType)
{
    return get_activation_factory<SecondaryAuthenticationFactorRegistration, ISecondaryAuthenticationFactorRegistrationStatics>().FindAllRegisteredDeviceInfoAsync(queryType);
}

inline Windows::Foundation::IAsyncAction SecondaryAuthenticationFactorRegistration::UnregisterDeviceAsync(hstring_view deviceId)
{
    return get_activation_factory<SecondaryAuthenticationFactorRegistration, ISecondaryAuthenticationFactorRegistrationStatics>().UnregisterDeviceAsync(deviceId);
}

inline Windows::Foundation::IAsyncAction SecondaryAuthenticationFactorRegistration::UpdateDeviceConfigurationDataAsync(hstring_view deviceId, const Windows::Storage::Streams::IBuffer & deviceConfigurationData)
{
    return get_activation_factory<SecondaryAuthenticationFactorRegistration, ISecondaryAuthenticationFactorRegistrationStatics>().UpdateDeviceConfigurationDataAsync(deviceId, deviceConfigurationData);
}

}

}
#pragma warning(pop)
