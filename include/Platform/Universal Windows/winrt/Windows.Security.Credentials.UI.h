// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Security.Credentials.UI.3.h"
#include "Windows.Security.Credentials.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Security::Credentials::UI::ICredentialPickerOptions> : produce_base<D, Windows::Security::Credentials::UI::ICredentialPickerOptions>
{
    HRESULT __stdcall put_Caption(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Caption(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Caption(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Caption());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Message(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Message(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Message(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Message());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ErrorCode(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ErrorCode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ErrorCode(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ErrorCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TargetName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TargetName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AuthenticationProtocol(Windows::Security::Credentials::UI::AuthenticationProtocol value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AuthenticationProtocol(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AuthenticationProtocol(Windows::Security::Credentials::UI::AuthenticationProtocol * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AuthenticationProtocol());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CustomAuthenticationProtocol(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CustomAuthenticationProtocol(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CustomAuthenticationProtocol(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CustomAuthenticationProtocol());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PreviousCredential(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PreviousCredential(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PreviousCredential(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PreviousCredential());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AlwaysDisplayDialog(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AlwaysDisplayDialog(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AlwaysDisplayDialog(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AlwaysDisplayDialog());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CallerSavesCredential(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CallerSavesCredential(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CallerSavesCredential(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CallerSavesCredential());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CredentialSaveOption(Windows::Security::Credentials::UI::CredentialSaveOption value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CredentialSaveOption(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CredentialSaveOption(Windows::Security::Credentials::UI::CredentialSaveOption * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CredentialSaveOption());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Credentials::UI::ICredentialPickerResults> : produce_base<D, Windows::Security::Credentials::UI::ICredentialPickerResults>
{
    HRESULT __stdcall get_ErrorCode(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ErrorCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CredentialSaveOption(Windows::Security::Credentials::UI::CredentialSaveOption * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CredentialSaveOption());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CredentialSaved(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CredentialSaved());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Credential(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Credential());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CredentialDomainName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CredentialDomainName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CredentialUserName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CredentialUserName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CredentialPassword(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CredentialPassword());
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
struct produce<D, Windows::Security::Credentials::UI::ICredentialPickerStatics> : produce_base<D, Windows::Security::Credentials::UI::ICredentialPickerStatics>
{
    HRESULT __stdcall abi_PickWithOptionsAsync(impl::abi_arg_in<Windows::Security::Credentials::UI::ICredentialPickerOptions> options, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::UI::CredentialPickerResults>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().PickAsync(*reinterpret_cast<const Windows::Security::Credentials::UI::CredentialPickerOptions *>(&options)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PickWithMessageAsync(impl::abi_arg_in<hstring> targetName, impl::abi_arg_in<hstring> message, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::UI::CredentialPickerResults>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().PickAsync(*reinterpret_cast<const hstring *>(&targetName), *reinterpret_cast<const hstring *>(&message)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PickWithCaptionAsync(impl::abi_arg_in<hstring> targetName, impl::abi_arg_in<hstring> message, impl::abi_arg_in<hstring> caption, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::UI::CredentialPickerResults>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().PickAsync(*reinterpret_cast<const hstring *>(&targetName), *reinterpret_cast<const hstring *>(&message), *reinterpret_cast<const hstring *>(&caption)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Credentials::UI::IUserConsentVerifierStatics> : produce_base<D, Windows::Security::Credentials::UI::IUserConsentVerifierStatics>
{
    HRESULT __stdcall abi_CheckAvailabilityAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Credentials::UI::UserConsentVerifierAvailability>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CheckAvailabilityAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestVerificationAsync(impl::abi_arg_in<hstring> message, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Credentials::UI::UserConsentVerificationResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestVerificationAsync(*reinterpret_cast<const hstring *>(&message)));
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

namespace Windows::Security::Credentials::UI {

template <typename D> void impl_ICredentialPickerOptions<D>::Caption(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICredentialPickerOptions)->put_Caption(get_abi(value)));
}

template <typename D> hstring impl_ICredentialPickerOptions<D>::Caption() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICredentialPickerOptions)->get_Caption(put_abi(value)));
    return value;
}

template <typename D> void impl_ICredentialPickerOptions<D>::Message(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICredentialPickerOptions)->put_Message(get_abi(value)));
}

template <typename D> hstring impl_ICredentialPickerOptions<D>::Message() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICredentialPickerOptions)->get_Message(put_abi(value)));
    return value;
}

template <typename D> void impl_ICredentialPickerOptions<D>::ErrorCode(uint32_t value) const
{
    check_hresult(WINRT_SHIM(ICredentialPickerOptions)->put_ErrorCode(value));
}

template <typename D> uint32_t impl_ICredentialPickerOptions<D>::ErrorCode() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ICredentialPickerOptions)->get_ErrorCode(&value));
    return value;
}

template <typename D> void impl_ICredentialPickerOptions<D>::TargetName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICredentialPickerOptions)->put_TargetName(get_abi(value)));
}

template <typename D> hstring impl_ICredentialPickerOptions<D>::TargetName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICredentialPickerOptions)->get_TargetName(put_abi(value)));
    return value;
}

template <typename D> void impl_ICredentialPickerOptions<D>::AuthenticationProtocol(Windows::Security::Credentials::UI::AuthenticationProtocol value) const
{
    check_hresult(WINRT_SHIM(ICredentialPickerOptions)->put_AuthenticationProtocol(value));
}

template <typename D> Windows::Security::Credentials::UI::AuthenticationProtocol impl_ICredentialPickerOptions<D>::AuthenticationProtocol() const
{
    Windows::Security::Credentials::UI::AuthenticationProtocol value {};
    check_hresult(WINRT_SHIM(ICredentialPickerOptions)->get_AuthenticationProtocol(&value));
    return value;
}

template <typename D> void impl_ICredentialPickerOptions<D>::CustomAuthenticationProtocol(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICredentialPickerOptions)->put_CustomAuthenticationProtocol(get_abi(value)));
}

template <typename D> hstring impl_ICredentialPickerOptions<D>::CustomAuthenticationProtocol() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICredentialPickerOptions)->get_CustomAuthenticationProtocol(put_abi(value)));
    return value;
}

template <typename D> void impl_ICredentialPickerOptions<D>::PreviousCredential(const Windows::Storage::Streams::IBuffer & value) const
{
    check_hresult(WINRT_SHIM(ICredentialPickerOptions)->put_PreviousCredential(get_abi(value)));
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ICredentialPickerOptions<D>::PreviousCredential() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(ICredentialPickerOptions)->get_PreviousCredential(put_abi(value)));
    return value;
}

template <typename D> void impl_ICredentialPickerOptions<D>::AlwaysDisplayDialog(bool value) const
{
    check_hresult(WINRT_SHIM(ICredentialPickerOptions)->put_AlwaysDisplayDialog(value));
}

template <typename D> bool impl_ICredentialPickerOptions<D>::AlwaysDisplayDialog() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICredentialPickerOptions)->get_AlwaysDisplayDialog(&value));
    return value;
}

template <typename D> void impl_ICredentialPickerOptions<D>::CallerSavesCredential(bool value) const
{
    check_hresult(WINRT_SHIM(ICredentialPickerOptions)->put_CallerSavesCredential(value));
}

template <typename D> bool impl_ICredentialPickerOptions<D>::CallerSavesCredential() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICredentialPickerOptions)->get_CallerSavesCredential(&value));
    return value;
}

template <typename D> void impl_ICredentialPickerOptions<D>::CredentialSaveOption(Windows::Security::Credentials::UI::CredentialSaveOption value) const
{
    check_hresult(WINRT_SHIM(ICredentialPickerOptions)->put_CredentialSaveOption(value));
}

template <typename D> Windows::Security::Credentials::UI::CredentialSaveOption impl_ICredentialPickerOptions<D>::CredentialSaveOption() const
{
    Windows::Security::Credentials::UI::CredentialSaveOption value {};
    check_hresult(WINRT_SHIM(ICredentialPickerOptions)->get_CredentialSaveOption(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::UI::CredentialPickerResults> impl_ICredentialPickerStatics<D>::PickAsync(const Windows::Security::Credentials::UI::CredentialPickerOptions & options) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::UI::CredentialPickerResults> operation;
    check_hresult(WINRT_SHIM(ICredentialPickerStatics)->abi_PickWithOptionsAsync(get_abi(options), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::UI::CredentialPickerResults> impl_ICredentialPickerStatics<D>::PickAsync(hstring_view targetName, hstring_view message) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::UI::CredentialPickerResults> operation;
    check_hresult(WINRT_SHIM(ICredentialPickerStatics)->abi_PickWithMessageAsync(get_abi(targetName), get_abi(message), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::UI::CredentialPickerResults> impl_ICredentialPickerStatics<D>::PickAsync(hstring_view targetName, hstring_view message, hstring_view caption) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::UI::CredentialPickerResults> operation;
    check_hresult(WINRT_SHIM(ICredentialPickerStatics)->abi_PickWithCaptionAsync(get_abi(targetName), get_abi(message), get_abi(caption), put_abi(operation)));
    return operation;
}

template <typename D> uint32_t impl_ICredentialPickerResults<D>::ErrorCode() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ICredentialPickerResults)->get_ErrorCode(&value));
    return value;
}

template <typename D> Windows::Security::Credentials::UI::CredentialSaveOption impl_ICredentialPickerResults<D>::CredentialSaveOption() const
{
    Windows::Security::Credentials::UI::CredentialSaveOption value {};
    check_hresult(WINRT_SHIM(ICredentialPickerResults)->get_CredentialSaveOption(&value));
    return value;
}

template <typename D> bool impl_ICredentialPickerResults<D>::CredentialSaved() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICredentialPickerResults)->get_CredentialSaved(&value));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ICredentialPickerResults<D>::Credential() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(ICredentialPickerResults)->get_Credential(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICredentialPickerResults<D>::CredentialDomainName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICredentialPickerResults)->get_CredentialDomainName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICredentialPickerResults<D>::CredentialUserName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICredentialPickerResults)->get_CredentialUserName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICredentialPickerResults<D>::CredentialPassword() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICredentialPickerResults)->get_CredentialPassword(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Credentials::UI::UserConsentVerifierAvailability> impl_IUserConsentVerifierStatics<D>::CheckAvailabilityAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Credentials::UI::UserConsentVerifierAvailability> result;
    check_hresult(WINRT_SHIM(IUserConsentVerifierStatics)->abi_CheckAvailabilityAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Credentials::UI::UserConsentVerificationResult> impl_IUserConsentVerifierStatics<D>::RequestVerificationAsync(hstring_view message) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Credentials::UI::UserConsentVerificationResult> result;
    check_hresult(WINRT_SHIM(IUserConsentVerifierStatics)->abi_RequestVerificationAsync(get_abi(message), put_abi(result)));
    return result;
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::UI::CredentialPickerResults> CredentialPicker::PickAsync(const Windows::Security::Credentials::UI::CredentialPickerOptions & options)
{
    return get_activation_factory<CredentialPicker, ICredentialPickerStatics>().PickAsync(options);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::UI::CredentialPickerResults> CredentialPicker::PickAsync(hstring_view targetName, hstring_view message)
{
    return get_activation_factory<CredentialPicker, ICredentialPickerStatics>().PickAsync(targetName, message);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::UI::CredentialPickerResults> CredentialPicker::PickAsync(hstring_view targetName, hstring_view message, hstring_view caption)
{
    return get_activation_factory<CredentialPicker, ICredentialPickerStatics>().PickAsync(targetName, message, caption);
}

inline CredentialPickerOptions::CredentialPickerOptions() :
    CredentialPickerOptions(activate_instance<CredentialPickerOptions>())
{}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Credentials::UI::UserConsentVerifierAvailability> UserConsentVerifier::CheckAvailabilityAsync()
{
    return get_activation_factory<UserConsentVerifier, IUserConsentVerifierStatics>().CheckAvailabilityAsync();
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Credentials::UI::UserConsentVerificationResult> UserConsentVerifier::RequestVerificationAsync(hstring_view message)
{
    return get_activation_factory<UserConsentVerifier, IUserConsentVerifierStatics>().RequestVerificationAsync(message);
}

}

}
#pragma warning(pop)
