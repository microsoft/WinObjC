// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.System.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.System.Profile.3.h"
#include "Windows.System.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::System::Profile::IAnalyticsInfoStatics> : produce_base<D, Windows::System::Profile::IAnalyticsInfoStatics>
{
    HRESULT __stdcall get_VersionInfo(impl::abi_arg_out<Windows::System::Profile::IAnalyticsVersionInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VersionInfo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceForm(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceForm());
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
struct produce<D, Windows::System::Profile::IAnalyticsVersionInfo> : produce_base<D, Windows::System::Profile::IAnalyticsVersionInfo>
{
    HRESULT __stdcall get_DeviceFamily(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceFamily());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceFamilyVersion(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceFamilyVersion());
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
struct produce<D, Windows::System::Profile::IHardwareIdentificationStatics> : produce_base<D, Windows::System::Profile::IHardwareIdentificationStatics>
{
    HRESULT __stdcall abi_GetPackageSpecificToken(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> nonce, impl::abi_arg_out<Windows::System::Profile::IHardwareToken> packageSpecificHardwareToken) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageSpecificHardwareToken = detach_abi(this->shim().GetPackageSpecificToken(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&nonce)));
            return S_OK;
        }
        catch (...)
        {
            *packageSpecificHardwareToken = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::Profile::IHardwareToken> : produce_base<D, Windows::System::Profile::IHardwareToken>
{
    HRESULT __stdcall get_Id(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Signature(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Signature());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Certificate(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Certificate());
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
struct produce<D, Windows::System::Profile::IKnownRetailInfoPropertiesStatics> : produce_base<D, Windows::System::Profile::IKnownRetailInfoPropertiesStatics>
{
    HRESULT __stdcall get_RetailAccessCode(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RetailAccessCode());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ManufacturerName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ManufacturerName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ModelName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ModelName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayModelName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayModelName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Price(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Price());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsFeatured(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsFeatured());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FormFactor(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FormFactor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ScreenSize(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScreenSize());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Weight(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Weight());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayDescription(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayDescription());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BatteryLifeDescription(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BatteryLifeDescription());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProcessorDescription(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProcessorDescription());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Memory(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Memory());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StorageDescription(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StorageDescription());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GraphicsDescription(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GraphicsDescription());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FrontCameraDescription(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrontCameraDescription());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RearCameraDescription(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RearCameraDescription());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HasNfc(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasNfc());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HasSdSlot(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasSdSlot());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HasOpticalDrive(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasOpticalDrive());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsOfficeInstalled(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsOfficeInstalled());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WindowsEdition(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WindowsEdition());
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
struct produce<D, Windows::System::Profile::IPlatformDiagnosticsAndUsageDataSettingsStatics> : produce_base<D, Windows::System::Profile::IPlatformDiagnosticsAndUsageDataSettingsStatics>
{
    HRESULT __stdcall get_CollectionLevel(Windows::System::Profile::PlatformDataCollectionLevel * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CollectionLevel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CollectionLevelChanged(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().CollectionLevelChanged(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CollectionLevelChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CollectionLevelChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CanCollectDiagnostics(Windows::System::Profile::PlatformDataCollectionLevel level, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CanCollectDiagnostics(level));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::Profile::IRetailInfoStatics> : produce_base<D, Windows::System::Profile::IRetailInfoStatics>
{
    HRESULT __stdcall get_IsDemoModeEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDemoModeEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Properties());
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
struct produce<D, Windows::System::Profile::ISharedModeSettingsStatics> : produce_base<D, Windows::System::Profile::ISharedModeSettingsStatics>
{
    HRESULT __stdcall get_IsEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::Profile::ISystemIdentificationInfo> : produce_base<D, Windows::System::Profile::ISystemIdentificationInfo>
{
    HRESULT __stdcall get_Id(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Source(Windows::System::Profile::SystemIdentificationSource * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Source());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::Profile::ISystemIdentificationStatics> : produce_base<D, Windows::System::Profile::ISystemIdentificationStatics>
{
    HRESULT __stdcall abi_GetSystemIdForPublisher(impl::abi_arg_out<Windows::System::Profile::ISystemIdentificationInfo> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetSystemIdForPublisher());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSystemIdForUser(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_out<Windows::System::Profile::ISystemIdentificationInfo> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetSystemIdForUser(*reinterpret_cast<const Windows::System::User *>(&user)));
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

namespace Windows::System::Profile {

template <typename D> Windows::System::Profile::AnalyticsVersionInfo impl_IAnalyticsInfoStatics<D>::VersionInfo() const
{
    Windows::System::Profile::AnalyticsVersionInfo value { nullptr };
    check_hresult(WINRT_SHIM(IAnalyticsInfoStatics)->get_VersionInfo(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAnalyticsInfoStatics<D>::DeviceForm() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAnalyticsInfoStatics)->get_DeviceForm(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAnalyticsVersionInfo<D>::DeviceFamily() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAnalyticsVersionInfo)->get_DeviceFamily(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAnalyticsVersionInfo<D>::DeviceFamilyVersion() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAnalyticsVersionInfo)->get_DeviceFamilyVersion(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ISystemIdentificationInfo<D>::Id() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(ISystemIdentificationInfo)->get_Id(put_abi(value)));
    return value;
}

template <typename D> Windows::System::Profile::SystemIdentificationSource impl_ISystemIdentificationInfo<D>::Source() const
{
    Windows::System::Profile::SystemIdentificationSource value {};
    check_hresult(WINRT_SHIM(ISystemIdentificationInfo)->get_Source(&value));
    return value;
}

template <typename D> Windows::System::Profile::SystemIdentificationInfo impl_ISystemIdentificationStatics<D>::GetSystemIdForPublisher() const
{
    Windows::System::Profile::SystemIdentificationInfo result { nullptr };
    check_hresult(WINRT_SHIM(ISystemIdentificationStatics)->abi_GetSystemIdForPublisher(put_abi(result)));
    return result;
}

template <typename D> Windows::System::Profile::SystemIdentificationInfo impl_ISystemIdentificationStatics<D>::GetSystemIdForUser(const Windows::System::User & user) const
{
    Windows::System::Profile::SystemIdentificationInfo result { nullptr };
    check_hresult(WINRT_SHIM(ISystemIdentificationStatics)->abi_GetSystemIdForUser(get_abi(user), put_abi(result)));
    return result;
}

template <typename D> Windows::System::Profile::PlatformDataCollectionLevel impl_IPlatformDiagnosticsAndUsageDataSettingsStatics<D>::CollectionLevel() const
{
    Windows::System::Profile::PlatformDataCollectionLevel value {};
    check_hresult(WINRT_SHIM(IPlatformDiagnosticsAndUsageDataSettingsStatics)->get_CollectionLevel(&value));
    return value;
}

template <typename D> event_token impl_IPlatformDiagnosticsAndUsageDataSettingsStatics<D>::CollectionLevelChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPlatformDiagnosticsAndUsageDataSettingsStatics)->add_CollectionLevelChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPlatformDiagnosticsAndUsageDataSettingsStatics> impl_IPlatformDiagnosticsAndUsageDataSettingsStatics<D>::CollectionLevelChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPlatformDiagnosticsAndUsageDataSettingsStatics>(this, &ABI::Windows::System::Profile::IPlatformDiagnosticsAndUsageDataSettingsStatics::remove_CollectionLevelChanged, CollectionLevelChanged(handler));
}

template <typename D> void impl_IPlatformDiagnosticsAndUsageDataSettingsStatics<D>::CollectionLevelChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IPlatformDiagnosticsAndUsageDataSettingsStatics)->remove_CollectionLevelChanged(token));
}

template <typename D> bool impl_IPlatformDiagnosticsAndUsageDataSettingsStatics<D>::CanCollectDiagnostics(Windows::System::Profile::PlatformDataCollectionLevel level) const
{
    bool result {};
    check_hresult(WINRT_SHIM(IPlatformDiagnosticsAndUsageDataSettingsStatics)->abi_CanCollectDiagnostics(level, &result));
    return result;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IHardwareToken<D>::Id() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IHardwareToken)->get_Id(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IHardwareToken<D>::Signature() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IHardwareToken)->get_Signature(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IHardwareToken<D>::Certificate() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IHardwareToken)->get_Certificate(put_abi(value)));
    return value;
}

template <typename D> Windows::System::Profile::HardwareToken impl_IHardwareIdentificationStatics<D>::GetPackageSpecificToken(const Windows::Storage::Streams::IBuffer & nonce) const
{
    Windows::System::Profile::HardwareToken packageSpecificHardwareToken { nullptr };
    check_hresult(WINRT_SHIM(IHardwareIdentificationStatics)->abi_GetPackageSpecificToken(get_abi(nonce), put_abi(packageSpecificHardwareToken)));
    return packageSpecificHardwareToken;
}

template <typename D> bool impl_ISharedModeSettingsStatics<D>::IsEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISharedModeSettingsStatics)->get_IsEnabled(&value));
    return value;
}

template <typename D> bool impl_IRetailInfoStatics<D>::IsDemoModeEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IRetailInfoStatics)->get_IsDemoModeEnabled(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> impl_IRetailInfoStatics<D>::Properties() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> value;
    check_hresult(WINRT_SHIM(IRetailInfoStatics)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownRetailInfoPropertiesStatics<D>::RetailAccessCode() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownRetailInfoPropertiesStatics)->get_RetailAccessCode(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownRetailInfoPropertiesStatics<D>::ManufacturerName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownRetailInfoPropertiesStatics)->get_ManufacturerName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownRetailInfoPropertiesStatics<D>::ModelName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownRetailInfoPropertiesStatics)->get_ModelName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownRetailInfoPropertiesStatics<D>::DisplayModelName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownRetailInfoPropertiesStatics)->get_DisplayModelName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownRetailInfoPropertiesStatics<D>::Price() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownRetailInfoPropertiesStatics)->get_Price(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownRetailInfoPropertiesStatics<D>::IsFeatured() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownRetailInfoPropertiesStatics)->get_IsFeatured(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownRetailInfoPropertiesStatics<D>::FormFactor() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownRetailInfoPropertiesStatics)->get_FormFactor(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownRetailInfoPropertiesStatics<D>::ScreenSize() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownRetailInfoPropertiesStatics)->get_ScreenSize(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownRetailInfoPropertiesStatics<D>::Weight() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownRetailInfoPropertiesStatics)->get_Weight(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownRetailInfoPropertiesStatics<D>::DisplayDescription() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownRetailInfoPropertiesStatics)->get_DisplayDescription(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownRetailInfoPropertiesStatics<D>::BatteryLifeDescription() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownRetailInfoPropertiesStatics)->get_BatteryLifeDescription(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownRetailInfoPropertiesStatics<D>::ProcessorDescription() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownRetailInfoPropertiesStatics)->get_ProcessorDescription(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownRetailInfoPropertiesStatics<D>::Memory() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownRetailInfoPropertiesStatics)->get_Memory(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownRetailInfoPropertiesStatics<D>::StorageDescription() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownRetailInfoPropertiesStatics)->get_StorageDescription(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownRetailInfoPropertiesStatics<D>::GraphicsDescription() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownRetailInfoPropertiesStatics)->get_GraphicsDescription(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownRetailInfoPropertiesStatics<D>::FrontCameraDescription() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownRetailInfoPropertiesStatics)->get_FrontCameraDescription(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownRetailInfoPropertiesStatics<D>::RearCameraDescription() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownRetailInfoPropertiesStatics)->get_RearCameraDescription(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownRetailInfoPropertiesStatics<D>::HasNfc() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownRetailInfoPropertiesStatics)->get_HasNfc(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownRetailInfoPropertiesStatics<D>::HasSdSlot() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownRetailInfoPropertiesStatics)->get_HasSdSlot(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownRetailInfoPropertiesStatics<D>::HasOpticalDrive() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownRetailInfoPropertiesStatics)->get_HasOpticalDrive(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownRetailInfoPropertiesStatics<D>::IsOfficeInstalled() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownRetailInfoPropertiesStatics)->get_IsOfficeInstalled(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownRetailInfoPropertiesStatics<D>::WindowsEdition() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownRetailInfoPropertiesStatics)->get_WindowsEdition(put_abi(value)));
    return value;
}

inline Windows::System::Profile::AnalyticsVersionInfo AnalyticsInfo::VersionInfo()
{
    return get_activation_factory<AnalyticsInfo, IAnalyticsInfoStatics>().VersionInfo();
}

inline hstring AnalyticsInfo::DeviceForm()
{
    return get_activation_factory<AnalyticsInfo, IAnalyticsInfoStatics>().DeviceForm();
}

inline Windows::System::Profile::HardwareToken HardwareIdentification::GetPackageSpecificToken(const Windows::Storage::Streams::IBuffer & nonce)
{
    return get_activation_factory<HardwareIdentification, IHardwareIdentificationStatics>().GetPackageSpecificToken(nonce);
}

inline hstring KnownRetailInfoProperties::RetailAccessCode()
{
    return get_activation_factory<KnownRetailInfoProperties, IKnownRetailInfoPropertiesStatics>().RetailAccessCode();
}

inline hstring KnownRetailInfoProperties::ManufacturerName()
{
    return get_activation_factory<KnownRetailInfoProperties, IKnownRetailInfoPropertiesStatics>().ManufacturerName();
}

inline hstring KnownRetailInfoProperties::ModelName()
{
    return get_activation_factory<KnownRetailInfoProperties, IKnownRetailInfoPropertiesStatics>().ModelName();
}

inline hstring KnownRetailInfoProperties::DisplayModelName()
{
    return get_activation_factory<KnownRetailInfoProperties, IKnownRetailInfoPropertiesStatics>().DisplayModelName();
}

inline hstring KnownRetailInfoProperties::Price()
{
    return get_activation_factory<KnownRetailInfoProperties, IKnownRetailInfoPropertiesStatics>().Price();
}

inline hstring KnownRetailInfoProperties::IsFeatured()
{
    return get_activation_factory<KnownRetailInfoProperties, IKnownRetailInfoPropertiesStatics>().IsFeatured();
}

inline hstring KnownRetailInfoProperties::FormFactor()
{
    return get_activation_factory<KnownRetailInfoProperties, IKnownRetailInfoPropertiesStatics>().FormFactor();
}

inline hstring KnownRetailInfoProperties::ScreenSize()
{
    return get_activation_factory<KnownRetailInfoProperties, IKnownRetailInfoPropertiesStatics>().ScreenSize();
}

inline hstring KnownRetailInfoProperties::Weight()
{
    return get_activation_factory<KnownRetailInfoProperties, IKnownRetailInfoPropertiesStatics>().Weight();
}

inline hstring KnownRetailInfoProperties::DisplayDescription()
{
    return get_activation_factory<KnownRetailInfoProperties, IKnownRetailInfoPropertiesStatics>().DisplayDescription();
}

inline hstring KnownRetailInfoProperties::BatteryLifeDescription()
{
    return get_activation_factory<KnownRetailInfoProperties, IKnownRetailInfoPropertiesStatics>().BatteryLifeDescription();
}

inline hstring KnownRetailInfoProperties::ProcessorDescription()
{
    return get_activation_factory<KnownRetailInfoProperties, IKnownRetailInfoPropertiesStatics>().ProcessorDescription();
}

inline hstring KnownRetailInfoProperties::Memory()
{
    return get_activation_factory<KnownRetailInfoProperties, IKnownRetailInfoPropertiesStatics>().Memory();
}

inline hstring KnownRetailInfoProperties::StorageDescription()
{
    return get_activation_factory<KnownRetailInfoProperties, IKnownRetailInfoPropertiesStatics>().StorageDescription();
}

inline hstring KnownRetailInfoProperties::GraphicsDescription()
{
    return get_activation_factory<KnownRetailInfoProperties, IKnownRetailInfoPropertiesStatics>().GraphicsDescription();
}

inline hstring KnownRetailInfoProperties::FrontCameraDescription()
{
    return get_activation_factory<KnownRetailInfoProperties, IKnownRetailInfoPropertiesStatics>().FrontCameraDescription();
}

inline hstring KnownRetailInfoProperties::RearCameraDescription()
{
    return get_activation_factory<KnownRetailInfoProperties, IKnownRetailInfoPropertiesStatics>().RearCameraDescription();
}

inline hstring KnownRetailInfoProperties::HasNfc()
{
    return get_activation_factory<KnownRetailInfoProperties, IKnownRetailInfoPropertiesStatics>().HasNfc();
}

inline hstring KnownRetailInfoProperties::HasSdSlot()
{
    return get_activation_factory<KnownRetailInfoProperties, IKnownRetailInfoPropertiesStatics>().HasSdSlot();
}

inline hstring KnownRetailInfoProperties::HasOpticalDrive()
{
    return get_activation_factory<KnownRetailInfoProperties, IKnownRetailInfoPropertiesStatics>().HasOpticalDrive();
}

inline hstring KnownRetailInfoProperties::IsOfficeInstalled()
{
    return get_activation_factory<KnownRetailInfoProperties, IKnownRetailInfoPropertiesStatics>().IsOfficeInstalled();
}

inline hstring KnownRetailInfoProperties::WindowsEdition()
{
    return get_activation_factory<KnownRetailInfoProperties, IKnownRetailInfoPropertiesStatics>().WindowsEdition();
}

inline Windows::System::Profile::PlatformDataCollectionLevel PlatformDiagnosticsAndUsageDataSettings::CollectionLevel()
{
    return get_activation_factory<PlatformDiagnosticsAndUsageDataSettings, IPlatformDiagnosticsAndUsageDataSettingsStatics>().CollectionLevel();
}

inline event_token PlatformDiagnosticsAndUsageDataSettings::CollectionLevelChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    return get_activation_factory<PlatformDiagnosticsAndUsageDataSettings, IPlatformDiagnosticsAndUsageDataSettingsStatics>().CollectionLevelChanged(handler);
}

inline factory_event_revoker<IPlatformDiagnosticsAndUsageDataSettingsStatics> PlatformDiagnosticsAndUsageDataSettings::CollectionLevelChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    auto factory = get_activation_factory<PlatformDiagnosticsAndUsageDataSettings, IPlatformDiagnosticsAndUsageDataSettingsStatics>();
    return { factory, &ABI::Windows::System::Profile::IPlatformDiagnosticsAndUsageDataSettingsStatics::remove_CollectionLevelChanged, factory.CollectionLevelChanged(handler) };
}

inline void PlatformDiagnosticsAndUsageDataSettings::CollectionLevelChanged(event_token token)
{
    get_activation_factory<PlatformDiagnosticsAndUsageDataSettings, IPlatformDiagnosticsAndUsageDataSettingsStatics>().CollectionLevelChanged(token);
}

inline bool PlatformDiagnosticsAndUsageDataSettings::CanCollectDiagnostics(Windows::System::Profile::PlatformDataCollectionLevel level)
{
    return get_activation_factory<PlatformDiagnosticsAndUsageDataSettings, IPlatformDiagnosticsAndUsageDataSettingsStatics>().CanCollectDiagnostics(level);
}

inline bool RetailInfo::IsDemoModeEnabled()
{
    return get_activation_factory<RetailInfo, IRetailInfoStatics>().IsDemoModeEnabled();
}

inline Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> RetailInfo::Properties()
{
    return get_activation_factory<RetailInfo, IRetailInfoStatics>().Properties();
}

inline bool SharedModeSettings::IsEnabled()
{
    return get_activation_factory<SharedModeSettings, ISharedModeSettingsStatics>().IsEnabled();
}

inline Windows::System::Profile::SystemIdentificationInfo SystemIdentification::GetSystemIdForPublisher()
{
    return get_activation_factory<SystemIdentification, ISystemIdentificationStatics>().GetSystemIdForPublisher();
}

inline Windows::System::Profile::SystemIdentificationInfo SystemIdentification::GetSystemIdForUser(const Windows::System::User & user)
{
    return get_activation_factory<SystemIdentification, ISystemIdentificationStatics>().GetSystemIdForUser(user);
}

}

}
#pragma warning(pop)
