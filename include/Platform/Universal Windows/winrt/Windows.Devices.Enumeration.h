// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.UI.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.UI.Popups.3.h"
#include "internal/Windows.ApplicationModel.Background.3.h"
#include "internal/Windows.Devices.Enumeration.3.h"
#include "Windows.Devices.h"
#include "Windows.Foundation.h"
#include "Windows.Foundation.Collections.h"
#include "Windows.Storage.Streams.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDeviceAccessChangedEventArgs> : produce_base<D, Windows::Devices::Enumeration::IDeviceAccessChangedEventArgs>
{
    HRESULT __stdcall get_Status(Windows::Devices::Enumeration::DeviceAccessStatus * value) noexcept override
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
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDeviceAccessChangedEventArgs2> : produce_base<D, Windows::Devices::Enumeration::IDeviceAccessChangedEventArgs2>
{
    HRESULT __stdcall get_Id(impl::abi_arg_out<hstring> value) noexcept override
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
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDeviceAccessInformation> : produce_base<D, Windows::Devices::Enumeration::IDeviceAccessInformation>
{
    HRESULT __stdcall add_AccessChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceAccessInformation, Windows::Devices::Enumeration::DeviceAccessChangedEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().AccessChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceAccessInformation, Windows::Devices::Enumeration::DeviceAccessChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AccessChanged(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AccessChanged(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CurrentStatus(Windows::Devices::Enumeration::DeviceAccessStatus * status) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_abi(this->shim().CurrentStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDeviceAccessInformationStatics> : produce_base<D, Windows::Devices::Enumeration::IDeviceAccessInformationStatics>
{
    HRESULT __stdcall abi_CreateFromId(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Devices::Enumeration::IDeviceAccessInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateFromId(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromDeviceClassId(GUID deviceClassId, impl::abi_arg_out<Windows::Devices::Enumeration::IDeviceAccessInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateFromDeviceClassId(deviceClassId));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromDeviceClass(Windows::Devices::Enumeration::DeviceClass deviceClass, impl::abi_arg_out<Windows::Devices::Enumeration::IDeviceAccessInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateFromDeviceClass(deviceClass));
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
struct produce<D, Windows::Devices::Enumeration::IDeviceConnectionChangeTriggerDetails> : produce_base<D, Windows::Devices::Enumeration::IDeviceConnectionChangeTriggerDetails>
{
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
struct produce<D, Windows::Devices::Enumeration::IDeviceDisconnectButtonClickedEventArgs> : produce_base<D, Windows::Devices::Enumeration::IDeviceDisconnectButtonClickedEventArgs>
{
    HRESULT __stdcall get_Device(impl::abi_arg_out<Windows::Devices::Enumeration::IDeviceInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Device());
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
struct produce<D, Windows::Devices::Enumeration::IDeviceInformation> : produce_base<D, Windows::Devices::Enumeration::IDeviceInformation>
{
    HRESULT __stdcall get_Id(impl::abi_arg_out<hstring> value) noexcept override
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

    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall get_IsDefault(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDefault());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EnclosureLocation(impl::abi_arg_out<Windows::Devices::Enumeration::IEnclosureLocation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnclosureLocation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
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

    HRESULT __stdcall abi_Update(impl::abi_arg_in<Windows::Devices::Enumeration::IDeviceInformationUpdate> updateInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Update(*reinterpret_cast<const Windows::Devices::Enumeration::DeviceInformationUpdate *>(&updateInfo));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetThumbnailAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceThumbnail>> asyncOp) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_abi(this->shim().GetThumbnailAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncOp = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetGlyphThumbnailAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceThumbnail>> asyncOp) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_abi(this->shim().GetGlyphThumbnailAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncOp = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDeviceInformation2> : produce_base<D, Windows::Devices::Enumeration::IDeviceInformation2>
{
    HRESULT __stdcall get_Kind(Windows::Devices::Enumeration::DeviceInformationKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Pairing(impl::abi_arg_out<Windows::Devices::Enumeration::IDeviceInformationPairing> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Pairing());
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
struct produce<D, Windows::Devices::Enumeration::IDeviceInformationCustomPairing> : produce_base<D, Windows::Devices::Enumeration::IDeviceInformationCustomPairing>
{
    HRESULT __stdcall abi_PairAsync(Windows::Devices::Enumeration::DevicePairingKinds pairingKindsSupported, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().PairAsync(pairingKindsSupported));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PairWithProtectionLevelAsync(Windows::Devices::Enumeration::DevicePairingKinds pairingKindsSupported, Windows::Devices::Enumeration::DevicePairingProtectionLevel minProtectionLevel, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().PairAsync(pairingKindsSupported, minProtectionLevel));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PairWithProtectionLevelAndSettingsAsync(Windows::Devices::Enumeration::DevicePairingKinds pairingKindsSupported, Windows::Devices::Enumeration::DevicePairingProtectionLevel minProtectionLevel, impl::abi_arg_in<Windows::Devices::Enumeration::IDevicePairingSettings> devicePairingSettings, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().PairAsync(pairingKindsSupported, minProtectionLevel, *reinterpret_cast<const Windows::Devices::Enumeration::IDevicePairingSettings *>(&devicePairingSettings)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PairingRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceInformationCustomPairing, Windows::Devices::Enumeration::DevicePairingRequestedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PairingRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceInformationCustomPairing, Windows::Devices::Enumeration::DevicePairingRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PairingRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PairingRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDeviceInformationPairing> : produce_base<D, Windows::Devices::Enumeration::IDeviceInformationPairing>
{
    HRESULT __stdcall get_IsPaired(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsPaired());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanPair(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanPair());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PairAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().PairAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PairWithProtectionLevelAsync(Windows::Devices::Enumeration::DevicePairingProtectionLevel minProtectionLevel, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().PairAsync(minProtectionLevel));
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
struct produce<D, Windows::Devices::Enumeration::IDeviceInformationPairing2> : produce_base<D, Windows::Devices::Enumeration::IDeviceInformationPairing2>
{
    HRESULT __stdcall get_ProtectionLevel(Windows::Devices::Enumeration::DevicePairingProtectionLevel * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProtectionLevel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Custom(impl::abi_arg_out<Windows::Devices::Enumeration::IDeviceInformationCustomPairing> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Custom());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PairWithProtectionLevelAndSettingsAsync(Windows::Devices::Enumeration::DevicePairingProtectionLevel minProtectionLevel, impl::abi_arg_in<Windows::Devices::Enumeration::IDevicePairingSettings> devicePairingSettings, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().PairAsync(minProtectionLevel, *reinterpret_cast<const Windows::Devices::Enumeration::IDevicePairingSettings *>(&devicePairingSettings)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UnpairAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceUnpairingResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().UnpairAsync());
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
struct produce<D, Windows::Devices::Enumeration::IDeviceInformationPairingStatics> : produce_base<D, Windows::Devices::Enumeration::IDeviceInformationPairingStatics>
{
    HRESULT __stdcall abi_TryRegisterForAllInboundPairingRequests(Windows::Devices::Enumeration::DevicePairingKinds pairingKindsSupported, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryRegisterForAllInboundPairingRequests(pairingKindsSupported));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDeviceInformationStatics> : produce_base<D, Windows::Devices::Enumeration::IDeviceInformationStatics>
{
    HRESULT __stdcall abi_CreateFromIdAsync(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation>> asyncOp) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_abi(this->shim().CreateFromIdAsync(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *asyncOp = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromIdAsyncAdditionalProperties(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> additionalProperties, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation>> asyncOp) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_abi(this->shim().CreateFromIdAsync(*reinterpret_cast<const hstring *>(&deviceId), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&additionalProperties)));
            return S_OK;
        }
        catch (...)
        {
            *asyncOp = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection>> asyncOp) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_abi(this->shim().FindAllAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncOp = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllAsyncDeviceClass(Windows::Devices::Enumeration::DeviceClass deviceClass, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection>> asyncOp) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_abi(this->shim().FindAllAsync(deviceClass));
            return S_OK;
        }
        catch (...)
        {
            *asyncOp = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllAsyncAqsFilter(impl::abi_arg_in<hstring> aqsFilter, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection>> asyncOp) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_abi(this->shim().FindAllAsync(*reinterpret_cast<const hstring *>(&aqsFilter)));
            return S_OK;
        }
        catch (...)
        {
            *asyncOp = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllAsyncAqsFilterAndAdditionalProperties(impl::abi_arg_in<hstring> aqsFilter, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> additionalProperties, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection>> asyncOp) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_abi(this->shim().FindAllAsync(*reinterpret_cast<const hstring *>(&aqsFilter), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&additionalProperties)));
            return S_OK;
        }
        catch (...)
        {
            *asyncOp = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWatcher(impl::abi_arg_out<Windows::Devices::Enumeration::IDeviceWatcher> watcher) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *watcher = detach_abi(this->shim().CreateWatcher());
            return S_OK;
        }
        catch (...)
        {
            *watcher = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWatcherDeviceClass(Windows::Devices::Enumeration::DeviceClass deviceClass, impl::abi_arg_out<Windows::Devices::Enumeration::IDeviceWatcher> watcher) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *watcher = detach_abi(this->shim().CreateWatcher(deviceClass));
            return S_OK;
        }
        catch (...)
        {
            *watcher = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWatcherAqsFilter(impl::abi_arg_in<hstring> aqsFilter, impl::abi_arg_out<Windows::Devices::Enumeration::IDeviceWatcher> watcher) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *watcher = detach_abi(this->shim().CreateWatcher(*reinterpret_cast<const hstring *>(&aqsFilter)));
            return S_OK;
        }
        catch (...)
        {
            *watcher = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWatcherAqsFilterAndAdditionalProperties(impl::abi_arg_in<hstring> aqsFilter, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> additionalProperties, impl::abi_arg_out<Windows::Devices::Enumeration::IDeviceWatcher> watcher) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *watcher = detach_abi(this->shim().CreateWatcher(*reinterpret_cast<const hstring *>(&aqsFilter), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&additionalProperties)));
            return S_OK;
        }
        catch (...)
        {
            *watcher = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDeviceInformationStatics2> : produce_base<D, Windows::Devices::Enumeration::IDeviceInformationStatics2>
{
    HRESULT __stdcall abi_GetAqsFilterFromDeviceClass(Windows::Devices::Enumeration::DeviceClass deviceClass, impl::abi_arg_out<hstring> aqsFilter) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *aqsFilter = detach_abi(this->shim().GetAqsFilterFromDeviceClass(deviceClass));
            return S_OK;
        }
        catch (...)
        {
            *aqsFilter = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromIdAsyncWithKindAndAdditionalProperties(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> additionalProperties, Windows::Devices::Enumeration::DeviceInformationKind kind, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation>> asyncOp) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_abi(this->shim().CreateFromIdAsync(*reinterpret_cast<const hstring *>(&deviceId), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&additionalProperties), kind));
            return S_OK;
        }
        catch (...)
        {
            *asyncOp = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllAsyncWithKindAqsFilterAndAdditionalProperties(impl::abi_arg_in<hstring> aqsFilter, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> additionalProperties, Windows::Devices::Enumeration::DeviceInformationKind kind, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection>> asyncOp) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_abi(this->shim().FindAllAsync(*reinterpret_cast<const hstring *>(&aqsFilter), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&additionalProperties), kind));
            return S_OK;
        }
        catch (...)
        {
            *asyncOp = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWatcherWithKindAqsFilterAndAdditionalProperties(impl::abi_arg_in<hstring> aqsFilter, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> additionalProperties, Windows::Devices::Enumeration::DeviceInformationKind kind, impl::abi_arg_out<Windows::Devices::Enumeration::IDeviceWatcher> watcher) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *watcher = detach_abi(this->shim().CreateWatcher(*reinterpret_cast<const hstring *>(&aqsFilter), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&additionalProperties), kind));
            return S_OK;
        }
        catch (...)
        {
            *watcher = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDeviceInformationUpdate> : produce_base<D, Windows::Devices::Enumeration::IDeviceInformationUpdate>
{
    HRESULT __stdcall get_Id(impl::abi_arg_out<hstring> value) noexcept override
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
struct produce<D, Windows::Devices::Enumeration::IDeviceInformationUpdate2> : produce_base<D, Windows::Devices::Enumeration::IDeviceInformationUpdate2>
{
    HRESULT __stdcall get_Kind(Windows::Devices::Enumeration::DeviceInformationKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDevicePairingRequestedEventArgs> : produce_base<D, Windows::Devices::Enumeration::IDevicePairingRequestedEventArgs>
{
    HRESULT __stdcall get_DeviceInformation(impl::abi_arg_out<Windows::Devices::Enumeration::IDeviceInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceInformation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PairingKind(Windows::Devices::Enumeration::DevicePairingKinds * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PairingKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Pin(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Pin());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Accept() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Accept();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AcceptWithPin(impl::abi_arg_in<hstring> pin) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Accept(*reinterpret_cast<const hstring *>(&pin));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDeferral());
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
struct produce<D, Windows::Devices::Enumeration::IDevicePairingResult> : produce_base<D, Windows::Devices::Enumeration::IDevicePairingResult>
{
    HRESULT __stdcall get_Status(Windows::Devices::Enumeration::DevicePairingResultStatus * status) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProtectionLevelUsed(Windows::Devices::Enumeration::DevicePairingProtectionLevel * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProtectionLevelUsed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDevicePairingSettings> : produce_base<D, Windows::Devices::Enumeration::IDevicePairingSettings>
{};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDevicePicker> : produce_base<D, Windows::Devices::Enumeration::IDevicePicker>
{
    HRESULT __stdcall get_Filter(impl::abi_arg_out<Windows::Devices::Enumeration::IDevicePickerFilter> filter) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *filter = detach_abi(this->shim().Filter());
            return S_OK;
        }
        catch (...)
        {
            *filter = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Appearance(impl::abi_arg_out<Windows::Devices::Enumeration::IDevicePickerAppearance> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Appearance());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RequestedProperties(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestedProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DeviceSelected(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::Devices::Enumeration::DeviceSelectedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().DeviceSelected(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::Devices::Enumeration::DeviceSelectedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DeviceSelected(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DeviceSelected(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DisconnectButtonClicked(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::Devices::Enumeration::DeviceDisconnectButtonClickedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().DisconnectButtonClicked(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::Devices::Enumeration::DeviceDisconnectButtonClickedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DisconnectButtonClicked(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisconnectButtonClicked(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DevicePickerDismissed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().DevicePickerDismissed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DevicePickerDismissed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DevicePickerDismissed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Show(impl::abi_arg_in<Windows::Foundation::Rect> selection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Show(*reinterpret_cast<const Windows::Foundation::Rect *>(&selection));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowWithPlacement(impl::abi_arg_in<Windows::Foundation::Rect> selection, Windows::UI::Popups::Placement placement) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Show(*reinterpret_cast<const Windows::Foundation::Rect *>(&selection), placement);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PickSingleDeviceAsync(impl::abi_arg_in<Windows::Foundation::Rect> selection, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().PickSingleDeviceAsync(*reinterpret_cast<const Windows::Foundation::Rect *>(&selection)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PickSingleDeviceAsyncWithPlacement(impl::abi_arg_in<Windows::Foundation::Rect> selection, Windows::UI::Popups::Placement placement, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().PickSingleDeviceAsync(*reinterpret_cast<const Windows::Foundation::Rect *>(&selection), placement));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Hide() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Hide();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetDisplayStatus(impl::abi_arg_in<Windows::Devices::Enumeration::IDeviceInformation> device, impl::abi_arg_in<hstring> status, Windows::Devices::Enumeration::DevicePickerDisplayStatusOptions options) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetDisplayStatus(*reinterpret_cast<const Windows::Devices::Enumeration::DeviceInformation *>(&device), *reinterpret_cast<const hstring *>(&status), options);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDevicePickerAppearance> : produce_base<D, Windows::Devices::Enumeration::IDevicePickerAppearance>
{
    HRESULT __stdcall get_Title(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Title());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Title(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Title(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ForegroundColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ForegroundColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ForegroundColor(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ForegroundColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BackgroundColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BackgroundColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BackgroundColor(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BackgroundColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AccentColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AccentColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AccentColor(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AccentColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SelectedForegroundColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SelectedForegroundColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SelectedForegroundColor(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SelectedForegroundColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SelectedBackgroundColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SelectedBackgroundColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SelectedBackgroundColor(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SelectedBackgroundColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SelectedAccentColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SelectedAccentColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SelectedAccentColor(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SelectedAccentColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDevicePickerFilter> : produce_base<D, Windows::Devices::Enumeration::IDevicePickerFilter>
{
    HRESULT __stdcall get_SupportedDeviceClasses(impl::abi_arg_out<Windows::Foundation::Collections::IVector<winrt::Windows::Devices::Enumeration::DeviceClass>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedDeviceClasses());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedDeviceSelectors(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedDeviceSelectors());
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
struct produce<D, Windows::Devices::Enumeration::IDeviceSelectedEventArgs> : produce_base<D, Windows::Devices::Enumeration::IDeviceSelectedEventArgs>
{
    HRESULT __stdcall get_SelectedDevice(impl::abi_arg_out<Windows::Devices::Enumeration::IDeviceInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SelectedDevice());
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
struct produce<D, Windows::Devices::Enumeration::IDeviceUnpairingResult> : produce_base<D, Windows::Devices::Enumeration::IDeviceUnpairingResult>
{
    HRESULT __stdcall get_Status(Windows::Devices::Enumeration::DeviceUnpairingResultStatus * status) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDeviceWatcher> : produce_base<D, Windows::Devices::Enumeration::IDeviceWatcher>
{
    HRESULT __stdcall add_Added(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformation>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Added(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformation> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Added(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Added(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Updated(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformationUpdate>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Updated(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformationUpdate> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Updated(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Updated(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Removed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformationUpdate>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Removed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformationUpdate> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Removed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Removed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_EnumerationCompleted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().EnumerationCompleted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_EnumerationCompleted(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnumerationCompleted(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Stopped(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Stopped(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Stopped(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stopped(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::Devices::Enumeration::DeviceWatcherStatus * status) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Start() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Stop() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDeviceWatcher2> : produce_base<D, Windows::Devices::Enumeration::IDeviceWatcher2>
{
    HRESULT __stdcall abi_GetBackgroundTrigger(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<winrt::Windows::Devices::Enumeration::DeviceWatcherEventKind>> requestedEventKinds, impl::abi_arg_out<Windows::ApplicationModel::Background::IDeviceWatcherTrigger> trigger) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *trigger = detach_abi(this->shim().GetBackgroundTrigger(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<winrt::Windows::Devices::Enumeration::DeviceWatcherEventKind> *>(&requestedEventKinds)));
            return S_OK;
        }
        catch (...)
        {
            *trigger = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IDeviceWatcherEvent> : produce_base<D, Windows::Devices::Enumeration::IDeviceWatcherEvent>
{
    HRESULT __stdcall get_Kind(Windows::Devices::Enumeration::DeviceWatcherEventKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceInformation(impl::abi_arg_out<Windows::Devices::Enumeration::IDeviceInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceInformation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceInformationUpdate(impl::abi_arg_out<Windows::Devices::Enumeration::IDeviceInformationUpdate> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceInformationUpdate());
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
struct produce<D, Windows::Devices::Enumeration::IDeviceWatcherTriggerDetails> : produce_base<D, Windows::Devices::Enumeration::IDeviceWatcherTriggerDetails>
{
    HRESULT __stdcall get_DeviceWatcherEvents(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Enumeration::DeviceWatcherEvent>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceWatcherEvents());
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
struct produce<D, Windows::Devices::Enumeration::IEnclosureLocation> : produce_base<D, Windows::Devices::Enumeration::IEnclosureLocation>
{
    HRESULT __stdcall get_InDock(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InDock());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InLid(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InLid());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Panel(Windows::Devices::Enumeration::Panel * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Panel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::IEnclosureLocation2> : produce_base<D, Windows::Devices::Enumeration::IEnclosureLocation2>
{
    HRESULT __stdcall get_RotationAngleInDegreesClockwise(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RotationAngleInDegreesClockwise());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Devices::Enumeration {

template <typename D> hstring impl_IDeviceConnectionChangeTriggerDetails<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDeviceConnectionChangeTriggerDetails)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDevicePickerAppearance<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDevicePickerAppearance)->get_Title(put_abi(value)));
    return value;
}

template <typename D> void impl_IDevicePickerAppearance<D>::Title(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDevicePickerAppearance)->put_Title(get_abi(value)));
}

template <typename D> Windows::UI::Color impl_IDevicePickerAppearance<D>::ForegroundColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IDevicePickerAppearance)->get_ForegroundColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IDevicePickerAppearance<D>::ForegroundColor(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IDevicePickerAppearance)->put_ForegroundColor(get_abi(value)));
}

template <typename D> Windows::UI::Color impl_IDevicePickerAppearance<D>::BackgroundColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IDevicePickerAppearance)->get_BackgroundColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IDevicePickerAppearance<D>::BackgroundColor(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IDevicePickerAppearance)->put_BackgroundColor(get_abi(value)));
}

template <typename D> Windows::UI::Color impl_IDevicePickerAppearance<D>::AccentColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IDevicePickerAppearance)->get_AccentColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IDevicePickerAppearance<D>::AccentColor(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IDevicePickerAppearance)->put_AccentColor(get_abi(value)));
}

template <typename D> Windows::UI::Color impl_IDevicePickerAppearance<D>::SelectedForegroundColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IDevicePickerAppearance)->get_SelectedForegroundColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IDevicePickerAppearance<D>::SelectedForegroundColor(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IDevicePickerAppearance)->put_SelectedForegroundColor(get_abi(value)));
}

template <typename D> Windows::UI::Color impl_IDevicePickerAppearance<D>::SelectedBackgroundColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IDevicePickerAppearance)->get_SelectedBackgroundColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IDevicePickerAppearance<D>::SelectedBackgroundColor(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IDevicePickerAppearance)->put_SelectedBackgroundColor(get_abi(value)));
}

template <typename D> Windows::UI::Color impl_IDevicePickerAppearance<D>::SelectedAccentColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IDevicePickerAppearance)->get_SelectedAccentColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IDevicePickerAppearance<D>::SelectedAccentColor(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IDevicePickerAppearance)->put_SelectedAccentColor(get_abi(value)));
}

template <typename D> Windows::Devices::Enumeration::DeviceInformation impl_IDeviceSelectedEventArgs<D>::SelectedDevice() const
{
    Windows::Devices::Enumeration::DeviceInformation value { nullptr };
    check_hresult(WINRT_SHIM(IDeviceSelectedEventArgs)->get_SelectedDevice(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceInformation impl_IDeviceDisconnectButtonClickedEventArgs<D>::Device() const
{
    Windows::Devices::Enumeration::DeviceInformation value { nullptr };
    check_hresult(WINRT_SHIM(IDeviceDisconnectButtonClickedEventArgs)->get_Device(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<winrt::Windows::Devices::Enumeration::DeviceClass> impl_IDevicePickerFilter<D>::SupportedDeviceClasses() const
{
    Windows::Foundation::Collections::IVector<winrt::Windows::Devices::Enumeration::DeviceClass> value;
    check_hresult(WINRT_SHIM(IDevicePickerFilter)->get_SupportedDeviceClasses(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IDevicePickerFilter<D>::SupportedDeviceSelectors() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IDevicePickerFilter)->get_SupportedDeviceSelectors(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DevicePickerFilter impl_IDevicePicker<D>::Filter() const
{
    Windows::Devices::Enumeration::DevicePickerFilter filter { nullptr };
    check_hresult(WINRT_SHIM(IDevicePicker)->get_Filter(put_abi(filter)));
    return filter;
}

template <typename D> Windows::Devices::Enumeration::DevicePickerAppearance impl_IDevicePicker<D>::Appearance() const
{
    Windows::Devices::Enumeration::DevicePickerAppearance value { nullptr };
    check_hresult(WINRT_SHIM(IDevicePicker)->get_Appearance(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IDevicePicker<D>::RequestedProperties() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IDevicePicker)->get_RequestedProperties(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IDevicePicker<D>::DeviceSelected(const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::Devices::Enumeration::DeviceSelectedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IDevicePicker)->add_DeviceSelected(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IDevicePicker> impl_IDevicePicker<D>::DeviceSelected(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::Devices::Enumeration::DeviceSelectedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IDevicePicker>(this, &ABI::Windows::Devices::Enumeration::IDevicePicker::remove_DeviceSelected, DeviceSelected(handler));
}

template <typename D> void impl_IDevicePicker<D>::DeviceSelected(event_token token) const
{
    check_hresult(WINRT_SHIM(IDevicePicker)->remove_DeviceSelected(token));
}

template <typename D> event_token impl_IDevicePicker<D>::DisconnectButtonClicked(const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::Devices::Enumeration::DeviceDisconnectButtonClickedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IDevicePicker)->add_DisconnectButtonClicked(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IDevicePicker> impl_IDevicePicker<D>::DisconnectButtonClicked(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::Devices::Enumeration::DeviceDisconnectButtonClickedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IDevicePicker>(this, &ABI::Windows::Devices::Enumeration::IDevicePicker::remove_DisconnectButtonClicked, DisconnectButtonClicked(handler));
}

template <typename D> void impl_IDevicePicker<D>::DisconnectButtonClicked(event_token token) const
{
    check_hresult(WINRT_SHIM(IDevicePicker)->remove_DisconnectButtonClicked(token));
}

template <typename D> event_token impl_IDevicePicker<D>::DevicePickerDismissed(const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IDevicePicker)->add_DevicePickerDismissed(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IDevicePicker> impl_IDevicePicker<D>::DevicePickerDismissed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IDevicePicker>(this, &ABI::Windows::Devices::Enumeration::IDevicePicker::remove_DevicePickerDismissed, DevicePickerDismissed(handler));
}

template <typename D> void impl_IDevicePicker<D>::DevicePickerDismissed(event_token token) const
{
    check_hresult(WINRT_SHIM(IDevicePicker)->remove_DevicePickerDismissed(token));
}

template <typename D> void impl_IDevicePicker<D>::Show(const Windows::Foundation::Rect & selection) const
{
    check_hresult(WINRT_SHIM(IDevicePicker)->abi_Show(get_abi(selection)));
}

template <typename D> void impl_IDevicePicker<D>::Show(const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement placement) const
{
    check_hresult(WINRT_SHIM(IDevicePicker)->abi_ShowWithPlacement(get_abi(selection), placement));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation> impl_IDevicePicker<D>::PickSingleDeviceAsync(const Windows::Foundation::Rect & selection) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation> operation;
    check_hresult(WINRT_SHIM(IDevicePicker)->abi_PickSingleDeviceAsync(get_abi(selection), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation> impl_IDevicePicker<D>::PickSingleDeviceAsync(const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement placement) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation> operation;
    check_hresult(WINRT_SHIM(IDevicePicker)->abi_PickSingleDeviceAsyncWithPlacement(get_abi(selection), placement, put_abi(operation)));
    return operation;
}

template <typename D> void impl_IDevicePicker<D>::Hide() const
{
    check_hresult(WINRT_SHIM(IDevicePicker)->abi_Hide());
}

template <typename D> void impl_IDevicePicker<D>::SetDisplayStatus(const Windows::Devices::Enumeration::DeviceInformation & device, hstring_view status, Windows::Devices::Enumeration::DevicePickerDisplayStatusOptions options) const
{
    check_hresult(WINRT_SHIM(IDevicePicker)->abi_SetDisplayStatus(get_abi(device), get_abi(status), options));
}

template <typename D> bool impl_IEnclosureLocation<D>::InDock() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEnclosureLocation)->get_InDock(&value));
    return value;
}

template <typename D> bool impl_IEnclosureLocation<D>::InLid() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEnclosureLocation)->get_InLid(&value));
    return value;
}

template <typename D> Windows::Devices::Enumeration::Panel impl_IEnclosureLocation<D>::Panel() const
{
    Windows::Devices::Enumeration::Panel value {};
    check_hresult(WINRT_SHIM(IEnclosureLocation)->get_Panel(&value));
    return value;
}

template <typename D> uint32_t impl_IEnclosureLocation2<D>::RotationAngleInDegreesClockwise() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IEnclosureLocation2)->get_RotationAngleInDegreesClockwise(&value));
    return value;
}

template <typename D> hstring impl_IDeviceInformationUpdate<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDeviceInformationUpdate)->get_Id(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> impl_IDeviceInformationUpdate<D>::Properties() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> value;
    check_hresult(WINRT_SHIM(IDeviceInformationUpdate)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceInformationKind impl_IDeviceInformationUpdate2<D>::Kind() const
{
    Windows::Devices::Enumeration::DeviceInformationKind value {};
    check_hresult(WINRT_SHIM(IDeviceInformationUpdate2)->get_Kind(&value));
    return value;
}

template <typename D> event_token impl_IDeviceWatcher<D>::Added(const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformation> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IDeviceWatcher)->add_Added(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IDeviceWatcher> impl_IDeviceWatcher<D>::Added(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformation> & handler) const
{
    return impl::make_event_revoker<D, IDeviceWatcher>(this, &ABI::Windows::Devices::Enumeration::IDeviceWatcher::remove_Added, Added(handler));
}

template <typename D> void impl_IDeviceWatcher<D>::Added(event_token token) const
{
    check_hresult(WINRT_SHIM(IDeviceWatcher)->remove_Added(token));
}

template <typename D> event_token impl_IDeviceWatcher<D>::Updated(const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformationUpdate> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IDeviceWatcher)->add_Updated(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IDeviceWatcher> impl_IDeviceWatcher<D>::Updated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformationUpdate> & handler) const
{
    return impl::make_event_revoker<D, IDeviceWatcher>(this, &ABI::Windows::Devices::Enumeration::IDeviceWatcher::remove_Updated, Updated(handler));
}

template <typename D> void impl_IDeviceWatcher<D>::Updated(event_token token) const
{
    check_hresult(WINRT_SHIM(IDeviceWatcher)->remove_Updated(token));
}

template <typename D> event_token impl_IDeviceWatcher<D>::Removed(const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformationUpdate> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IDeviceWatcher)->add_Removed(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IDeviceWatcher> impl_IDeviceWatcher<D>::Removed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformationUpdate> & handler) const
{
    return impl::make_event_revoker<D, IDeviceWatcher>(this, &ABI::Windows::Devices::Enumeration::IDeviceWatcher::remove_Removed, Removed(handler));
}

template <typename D> void impl_IDeviceWatcher<D>::Removed(event_token token) const
{
    check_hresult(WINRT_SHIM(IDeviceWatcher)->remove_Removed(token));
}

template <typename D> event_token impl_IDeviceWatcher<D>::EnumerationCompleted(const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IDeviceWatcher)->add_EnumerationCompleted(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IDeviceWatcher> impl_IDeviceWatcher<D>::EnumerationCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IDeviceWatcher>(this, &ABI::Windows::Devices::Enumeration::IDeviceWatcher::remove_EnumerationCompleted, EnumerationCompleted(handler));
}

template <typename D> void impl_IDeviceWatcher<D>::EnumerationCompleted(event_token token) const
{
    check_hresult(WINRT_SHIM(IDeviceWatcher)->remove_EnumerationCompleted(token));
}

template <typename D> event_token impl_IDeviceWatcher<D>::Stopped(const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IDeviceWatcher)->add_Stopped(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IDeviceWatcher> impl_IDeviceWatcher<D>::Stopped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IDeviceWatcher>(this, &ABI::Windows::Devices::Enumeration::IDeviceWatcher::remove_Stopped, Stopped(handler));
}

template <typename D> void impl_IDeviceWatcher<D>::Stopped(event_token token) const
{
    check_hresult(WINRT_SHIM(IDeviceWatcher)->remove_Stopped(token));
}

template <typename D> Windows::Devices::Enumeration::DeviceWatcherStatus impl_IDeviceWatcher<D>::Status() const
{
    Windows::Devices::Enumeration::DeviceWatcherStatus status {};
    check_hresult(WINRT_SHIM(IDeviceWatcher)->get_Status(&status));
    return status;
}

template <typename D> void impl_IDeviceWatcher<D>::Start() const
{
    check_hresult(WINRT_SHIM(IDeviceWatcher)->abi_Start());
}

template <typename D> void impl_IDeviceWatcher<D>::Stop() const
{
    check_hresult(WINRT_SHIM(IDeviceWatcher)->abi_Stop());
}

template <typename D> Windows::ApplicationModel::Background::DeviceWatcherTrigger impl_IDeviceWatcher2<D>::GetBackgroundTrigger(iterable<winrt::Windows::Devices::Enumeration::DeviceWatcherEventKind> requestedEventKinds) const
{
    Windows::ApplicationModel::Background::DeviceWatcherTrigger trigger { nullptr };
    check_hresult(WINRT_SHIM(IDeviceWatcher2)->abi_GetBackgroundTrigger(get_abi(requestedEventKinds), put_abi(trigger)));
    return trigger;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation> impl_IDeviceInformationStatics<D>::CreateFromIdAsync(hstring_view deviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation> asyncOp;
    check_hresult(WINRT_SHIM(IDeviceInformationStatics)->abi_CreateFromIdAsync(get_abi(deviceId), put_abi(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation> impl_IDeviceInformationStatics<D>::CreateFromIdAsync(hstring_view deviceId, iterable<hstring> additionalProperties) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation> asyncOp;
    check_hresult(WINRT_SHIM(IDeviceInformationStatics)->abi_CreateFromIdAsyncAdditionalProperties(get_abi(deviceId), get_abi(additionalProperties), put_abi(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> impl_IDeviceInformationStatics<D>::FindAllAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> asyncOp;
    check_hresult(WINRT_SHIM(IDeviceInformationStatics)->abi_FindAllAsync(put_abi(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> impl_IDeviceInformationStatics<D>::FindAllAsync(Windows::Devices::Enumeration::DeviceClass deviceClass) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> asyncOp;
    check_hresult(WINRT_SHIM(IDeviceInformationStatics)->abi_FindAllAsyncDeviceClass(deviceClass, put_abi(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> impl_IDeviceInformationStatics<D>::FindAllAsync(hstring_view aqsFilter) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> asyncOp;
    check_hresult(WINRT_SHIM(IDeviceInformationStatics)->abi_FindAllAsyncAqsFilter(get_abi(aqsFilter), put_abi(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> impl_IDeviceInformationStatics<D>::FindAllAsync(hstring_view aqsFilter, iterable<hstring> additionalProperties) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> asyncOp;
    check_hresult(WINRT_SHIM(IDeviceInformationStatics)->abi_FindAllAsyncAqsFilterAndAdditionalProperties(get_abi(aqsFilter), get_abi(additionalProperties), put_abi(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Devices::Enumeration::DeviceWatcher impl_IDeviceInformationStatics<D>::CreateWatcher() const
{
    Windows::Devices::Enumeration::DeviceWatcher watcher { nullptr };
    check_hresult(WINRT_SHIM(IDeviceInformationStatics)->abi_CreateWatcher(put_abi(watcher)));
    return watcher;
}

template <typename D> Windows::Devices::Enumeration::DeviceWatcher impl_IDeviceInformationStatics<D>::CreateWatcher(Windows::Devices::Enumeration::DeviceClass deviceClass) const
{
    Windows::Devices::Enumeration::DeviceWatcher watcher { nullptr };
    check_hresult(WINRT_SHIM(IDeviceInformationStatics)->abi_CreateWatcherDeviceClass(deviceClass, put_abi(watcher)));
    return watcher;
}

template <typename D> Windows::Devices::Enumeration::DeviceWatcher impl_IDeviceInformationStatics<D>::CreateWatcher(hstring_view aqsFilter) const
{
    Windows::Devices::Enumeration::DeviceWatcher watcher { nullptr };
    check_hresult(WINRT_SHIM(IDeviceInformationStatics)->abi_CreateWatcherAqsFilter(get_abi(aqsFilter), put_abi(watcher)));
    return watcher;
}

template <typename D> Windows::Devices::Enumeration::DeviceWatcher impl_IDeviceInformationStatics<D>::CreateWatcher(hstring_view aqsFilter, iterable<hstring> additionalProperties) const
{
    Windows::Devices::Enumeration::DeviceWatcher watcher { nullptr };
    check_hresult(WINRT_SHIM(IDeviceInformationStatics)->abi_CreateWatcherAqsFilterAndAdditionalProperties(get_abi(aqsFilter), get_abi(additionalProperties), put_abi(watcher)));
    return watcher;
}

template <typename D> hstring impl_IDeviceInformationStatics2<D>::GetAqsFilterFromDeviceClass(Windows::Devices::Enumeration::DeviceClass deviceClass) const
{
    hstring aqsFilter;
    check_hresult(WINRT_SHIM(IDeviceInformationStatics2)->abi_GetAqsFilterFromDeviceClass(deviceClass, put_abi(aqsFilter)));
    return aqsFilter;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation> impl_IDeviceInformationStatics2<D>::CreateFromIdAsync(hstring_view deviceId, iterable<hstring> additionalProperties, Windows::Devices::Enumeration::DeviceInformationKind kind) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation> asyncOp;
    check_hresult(WINRT_SHIM(IDeviceInformationStatics2)->abi_CreateFromIdAsyncWithKindAndAdditionalProperties(get_abi(deviceId), get_abi(additionalProperties), kind, put_abi(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> impl_IDeviceInformationStatics2<D>::FindAllAsync(hstring_view aqsFilter, iterable<hstring> additionalProperties, Windows::Devices::Enumeration::DeviceInformationKind kind) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> asyncOp;
    check_hresult(WINRT_SHIM(IDeviceInformationStatics2)->abi_FindAllAsyncWithKindAqsFilterAndAdditionalProperties(get_abi(aqsFilter), get_abi(additionalProperties), kind, put_abi(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Devices::Enumeration::DeviceWatcher impl_IDeviceInformationStatics2<D>::CreateWatcher(hstring_view aqsFilter, iterable<hstring> additionalProperties, Windows::Devices::Enumeration::DeviceInformationKind kind) const
{
    Windows::Devices::Enumeration::DeviceWatcher watcher { nullptr };
    check_hresult(WINRT_SHIM(IDeviceInformationStatics2)->abi_CreateWatcherWithKindAqsFilterAndAdditionalProperties(get_abi(aqsFilter), get_abi(additionalProperties), kind, put_abi(watcher)));
    return watcher;
}

template <typename D> hstring impl_IDeviceInformation<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDeviceInformation)->get_Id(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDeviceInformation<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDeviceInformation)->get_Name(put_abi(value)));
    return value;
}

template <typename D> bool impl_IDeviceInformation<D>::IsEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDeviceInformation)->get_IsEnabled(&value));
    return value;
}

template <typename D> bool impl_IDeviceInformation<D>::IsDefault() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDeviceInformation)->get_IsDefault(&value));
    return value;
}

template <typename D> Windows::Devices::Enumeration::EnclosureLocation impl_IDeviceInformation<D>::EnclosureLocation() const
{
    Windows::Devices::Enumeration::EnclosureLocation value { nullptr };
    check_hresult(WINRT_SHIM(IDeviceInformation)->get_EnclosureLocation(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> impl_IDeviceInformation<D>::Properties() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> value;
    check_hresult(WINRT_SHIM(IDeviceInformation)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> void impl_IDeviceInformation<D>::Update(const Windows::Devices::Enumeration::DeviceInformationUpdate & updateInfo) const
{
    check_hresult(WINRT_SHIM(IDeviceInformation)->abi_Update(get_abi(updateInfo)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceThumbnail> impl_IDeviceInformation<D>::GetThumbnailAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceThumbnail> asyncOp;
    check_hresult(WINRT_SHIM(IDeviceInformation)->abi_GetThumbnailAsync(put_abi(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceThumbnail> impl_IDeviceInformation<D>::GetGlyphThumbnailAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceThumbnail> asyncOp;
    check_hresult(WINRT_SHIM(IDeviceInformation)->abi_GetGlyphThumbnailAsync(put_abi(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Devices::Enumeration::DevicePairingResultStatus impl_IDevicePairingResult<D>::Status() const
{
    Windows::Devices::Enumeration::DevicePairingResultStatus status {};
    check_hresult(WINRT_SHIM(IDevicePairingResult)->get_Status(&status));
    return status;
}

template <typename D> Windows::Devices::Enumeration::DevicePairingProtectionLevel impl_IDevicePairingResult<D>::ProtectionLevelUsed() const
{
    Windows::Devices::Enumeration::DevicePairingProtectionLevel value {};
    check_hresult(WINRT_SHIM(IDevicePairingResult)->get_ProtectionLevelUsed(&value));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceUnpairingResultStatus impl_IDeviceUnpairingResult<D>::Status() const
{
    Windows::Devices::Enumeration::DeviceUnpairingResultStatus status {};
    check_hresult(WINRT_SHIM(IDeviceUnpairingResult)->get_Status(&status));
    return status;
}

template <typename D> Windows::Devices::Enumeration::DeviceInformation impl_IDevicePairingRequestedEventArgs<D>::DeviceInformation() const
{
    Windows::Devices::Enumeration::DeviceInformation value { nullptr };
    check_hresult(WINRT_SHIM(IDevicePairingRequestedEventArgs)->get_DeviceInformation(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DevicePairingKinds impl_IDevicePairingRequestedEventArgs<D>::PairingKind() const
{
    Windows::Devices::Enumeration::DevicePairingKinds value {};
    check_hresult(WINRT_SHIM(IDevicePairingRequestedEventArgs)->get_PairingKind(&value));
    return value;
}

template <typename D> hstring impl_IDevicePairingRequestedEventArgs<D>::Pin() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDevicePairingRequestedEventArgs)->get_Pin(put_abi(value)));
    return value;
}

template <typename D> void impl_IDevicePairingRequestedEventArgs<D>::Accept() const
{
    check_hresult(WINRT_SHIM(IDevicePairingRequestedEventArgs)->abi_Accept());
}

template <typename D> void impl_IDevicePairingRequestedEventArgs<D>::Accept(hstring_view pin) const
{
    check_hresult(WINRT_SHIM(IDevicePairingRequestedEventArgs)->abi_AcceptWithPin(get_abi(pin)));
}

template <typename D> Windows::Foundation::Deferral impl_IDevicePairingRequestedEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral result { nullptr };
    check_hresult(WINRT_SHIM(IDevicePairingRequestedEventArgs)->abi_GetDeferral(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult> impl_IDeviceInformationCustomPairing<D>::PairAsync(Windows::Devices::Enumeration::DevicePairingKinds pairingKindsSupported) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult> result;
    check_hresult(WINRT_SHIM(IDeviceInformationCustomPairing)->abi_PairAsync(pairingKindsSupported, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult> impl_IDeviceInformationCustomPairing<D>::PairAsync(Windows::Devices::Enumeration::DevicePairingKinds pairingKindsSupported, Windows::Devices::Enumeration::DevicePairingProtectionLevel minProtectionLevel) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult> result;
    check_hresult(WINRT_SHIM(IDeviceInformationCustomPairing)->abi_PairWithProtectionLevelAsync(pairingKindsSupported, minProtectionLevel, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult> impl_IDeviceInformationCustomPairing<D>::PairAsync(Windows::Devices::Enumeration::DevicePairingKinds pairingKindsSupported, Windows::Devices::Enumeration::DevicePairingProtectionLevel minProtectionLevel, const Windows::Devices::Enumeration::IDevicePairingSettings & devicePairingSettings) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult> result;
    check_hresult(WINRT_SHIM(IDeviceInformationCustomPairing)->abi_PairWithProtectionLevelAndSettingsAsync(pairingKindsSupported, minProtectionLevel, get_abi(devicePairingSettings), put_abi(result)));
    return result;
}

template <typename D> event_token impl_IDeviceInformationCustomPairing<D>::PairingRequested(const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceInformationCustomPairing, Windows::Devices::Enumeration::DevicePairingRequestedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IDeviceInformationCustomPairing)->add_PairingRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IDeviceInformationCustomPairing> impl_IDeviceInformationCustomPairing<D>::PairingRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceInformationCustomPairing, Windows::Devices::Enumeration::DevicePairingRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IDeviceInformationCustomPairing>(this, &ABI::Windows::Devices::Enumeration::IDeviceInformationCustomPairing::remove_PairingRequested, PairingRequested(handler));
}

template <typename D> void impl_IDeviceInformationCustomPairing<D>::PairingRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IDeviceInformationCustomPairing)->remove_PairingRequested(token));
}

template <typename D> bool impl_IDeviceInformationPairing<D>::IsPaired() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDeviceInformationPairing)->get_IsPaired(&value));
    return value;
}

template <typename D> bool impl_IDeviceInformationPairing<D>::CanPair() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDeviceInformationPairing)->get_CanPair(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult> impl_IDeviceInformationPairing<D>::PairAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult> result;
    check_hresult(WINRT_SHIM(IDeviceInformationPairing)->abi_PairAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult> impl_IDeviceInformationPairing<D>::PairAsync(Windows::Devices::Enumeration::DevicePairingProtectionLevel minProtectionLevel) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult> result;
    check_hresult(WINRT_SHIM(IDeviceInformationPairing)->abi_PairWithProtectionLevelAsync(minProtectionLevel, put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::Enumeration::DevicePairingProtectionLevel impl_IDeviceInformationPairing2<D>::ProtectionLevel() const
{
    Windows::Devices::Enumeration::DevicePairingProtectionLevel value {};
    check_hresult(WINRT_SHIM(IDeviceInformationPairing2)->get_ProtectionLevel(&value));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceInformationCustomPairing impl_IDeviceInformationPairing2<D>::Custom() const
{
    Windows::Devices::Enumeration::DeviceInformationCustomPairing value { nullptr };
    check_hresult(WINRT_SHIM(IDeviceInformationPairing2)->get_Custom(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult> impl_IDeviceInformationPairing2<D>::PairAsync(Windows::Devices::Enumeration::DevicePairingProtectionLevel minProtectionLevel, const Windows::Devices::Enumeration::IDevicePairingSettings & devicePairingSettings) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult> result;
    check_hresult(WINRT_SHIM(IDeviceInformationPairing2)->abi_PairWithProtectionLevelAndSettingsAsync(minProtectionLevel, get_abi(devicePairingSettings), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceUnpairingResult> impl_IDeviceInformationPairing2<D>::UnpairAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceUnpairingResult> result;
    check_hresult(WINRT_SHIM(IDeviceInformationPairing2)->abi_UnpairAsync(put_abi(result)));
    return result;
}

template <typename D> bool impl_IDeviceInformationPairingStatics<D>::TryRegisterForAllInboundPairingRequests(Windows::Devices::Enumeration::DevicePairingKinds pairingKindsSupported) const
{
    bool result {};
    check_hresult(WINRT_SHIM(IDeviceInformationPairingStatics)->abi_TryRegisterForAllInboundPairingRequests(pairingKindsSupported, &result));
    return result;
}

template <typename D> Windows::Devices::Enumeration::DeviceInformationKind impl_IDeviceInformation2<D>::Kind() const
{
    Windows::Devices::Enumeration::DeviceInformationKind value {};
    check_hresult(WINRT_SHIM(IDeviceInformation2)->get_Kind(&value));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceInformationPairing impl_IDeviceInformation2<D>::Pairing() const
{
    Windows::Devices::Enumeration::DeviceInformationPairing value { nullptr };
    check_hresult(WINRT_SHIM(IDeviceInformation2)->get_Pairing(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceAccessStatus impl_IDeviceAccessChangedEventArgs<D>::Status() const
{
    Windows::Devices::Enumeration::DeviceAccessStatus value {};
    check_hresult(WINRT_SHIM(IDeviceAccessChangedEventArgs)->get_Status(&value));
    return value;
}

template <typename D> hstring impl_IDeviceAccessChangedEventArgs2<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDeviceAccessChangedEventArgs2)->get_Id(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IDeviceAccessInformation<D>::AccessChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceAccessInformation, Windows::Devices::Enumeration::DeviceAccessChangedEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IDeviceAccessInformation)->add_AccessChanged(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IDeviceAccessInformation> impl_IDeviceAccessInformation<D>::AccessChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceAccessInformation, Windows::Devices::Enumeration::DeviceAccessChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IDeviceAccessInformation>(this, &ABI::Windows::Devices::Enumeration::IDeviceAccessInformation::remove_AccessChanged, AccessChanged(handler));
}

template <typename D> void impl_IDeviceAccessInformation<D>::AccessChanged(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IDeviceAccessInformation)->remove_AccessChanged(cookie));
}

template <typename D> Windows::Devices::Enumeration::DeviceAccessStatus impl_IDeviceAccessInformation<D>::CurrentStatus() const
{
    Windows::Devices::Enumeration::DeviceAccessStatus status {};
    check_hresult(WINRT_SHIM(IDeviceAccessInformation)->get_CurrentStatus(&status));
    return status;
}

template <typename D> Windows::Devices::Enumeration::DeviceAccessInformation impl_IDeviceAccessInformationStatics<D>::CreateFromId(hstring_view deviceId) const
{
    Windows::Devices::Enumeration::DeviceAccessInformation value { nullptr };
    check_hresult(WINRT_SHIM(IDeviceAccessInformationStatics)->abi_CreateFromId(get_abi(deviceId), put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceAccessInformation impl_IDeviceAccessInformationStatics<D>::CreateFromDeviceClassId(GUID deviceClassId) const
{
    Windows::Devices::Enumeration::DeviceAccessInformation value { nullptr };
    check_hresult(WINRT_SHIM(IDeviceAccessInformationStatics)->abi_CreateFromDeviceClassId(deviceClassId, put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceAccessInformation impl_IDeviceAccessInformationStatics<D>::CreateFromDeviceClass(Windows::Devices::Enumeration::DeviceClass deviceClass) const
{
    Windows::Devices::Enumeration::DeviceAccessInformation value { nullptr };
    check_hresult(WINRT_SHIM(IDeviceAccessInformationStatics)->abi_CreateFromDeviceClass(deviceClass, put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceWatcherEventKind impl_IDeviceWatcherEvent<D>::Kind() const
{
    Windows::Devices::Enumeration::DeviceWatcherEventKind value {};
    check_hresult(WINRT_SHIM(IDeviceWatcherEvent)->get_Kind(&value));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceInformation impl_IDeviceWatcherEvent<D>::DeviceInformation() const
{
    Windows::Devices::Enumeration::DeviceInformation value { nullptr };
    check_hresult(WINRT_SHIM(IDeviceWatcherEvent)->get_DeviceInformation(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceInformationUpdate impl_IDeviceWatcherEvent<D>::DeviceInformationUpdate() const
{
    Windows::Devices::Enumeration::DeviceInformationUpdate value { nullptr };
    check_hresult(WINRT_SHIM(IDeviceWatcherEvent)->get_DeviceInformationUpdate(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Enumeration::DeviceWatcherEvent> impl_IDeviceWatcherTriggerDetails<D>::DeviceWatcherEvents() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Enumeration::DeviceWatcherEvent> value;
    check_hresult(WINRT_SHIM(IDeviceWatcherTriggerDetails)->get_DeviceWatcherEvents(put_abi(value)));
    return value;
}

inline Windows::Devices::Enumeration::DeviceAccessInformation DeviceAccessInformation::CreateFromId(hstring_view deviceId)
{
    return get_activation_factory<DeviceAccessInformation, IDeviceAccessInformationStatics>().CreateFromId(deviceId);
}

inline Windows::Devices::Enumeration::DeviceAccessInformation DeviceAccessInformation::CreateFromDeviceClassId(GUID deviceClassId)
{
    return get_activation_factory<DeviceAccessInformation, IDeviceAccessInformationStatics>().CreateFromDeviceClassId(deviceClassId);
}

inline Windows::Devices::Enumeration::DeviceAccessInformation DeviceAccessInformation::CreateFromDeviceClass(Windows::Devices::Enumeration::DeviceClass deviceClass)
{
    return get_activation_factory<DeviceAccessInformation, IDeviceAccessInformationStatics>().CreateFromDeviceClass(deviceClass);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation> DeviceInformation::CreateFromIdAsync(hstring_view deviceId)
{
    return get_activation_factory<DeviceInformation, IDeviceInformationStatics>().CreateFromIdAsync(deviceId);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation> DeviceInformation::CreateFromIdAsync(hstring_view deviceId, iterable<hstring> additionalProperties)
{
    return get_activation_factory<DeviceInformation, IDeviceInformationStatics>().CreateFromIdAsync(deviceId, additionalProperties);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> DeviceInformation::FindAllAsync()
{
    return get_activation_factory<DeviceInformation, IDeviceInformationStatics>().FindAllAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> DeviceInformation::FindAllAsync(Windows::Devices::Enumeration::DeviceClass deviceClass)
{
    return get_activation_factory<DeviceInformation, IDeviceInformationStatics>().FindAllAsync(deviceClass);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> DeviceInformation::FindAllAsync(hstring_view aqsFilter)
{
    return get_activation_factory<DeviceInformation, IDeviceInformationStatics>().FindAllAsync(aqsFilter);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> DeviceInformation::FindAllAsync(hstring_view aqsFilter, iterable<hstring> additionalProperties)
{
    return get_activation_factory<DeviceInformation, IDeviceInformationStatics>().FindAllAsync(aqsFilter, additionalProperties);
}

inline Windows::Devices::Enumeration::DeviceWatcher DeviceInformation::CreateWatcher()
{
    return get_activation_factory<DeviceInformation, IDeviceInformationStatics>().CreateWatcher();
}

inline Windows::Devices::Enumeration::DeviceWatcher DeviceInformation::CreateWatcher(Windows::Devices::Enumeration::DeviceClass deviceClass)
{
    return get_activation_factory<DeviceInformation, IDeviceInformationStatics>().CreateWatcher(deviceClass);
}

inline Windows::Devices::Enumeration::DeviceWatcher DeviceInformation::CreateWatcher(hstring_view aqsFilter)
{
    return get_activation_factory<DeviceInformation, IDeviceInformationStatics>().CreateWatcher(aqsFilter);
}

inline Windows::Devices::Enumeration::DeviceWatcher DeviceInformation::CreateWatcher(hstring_view aqsFilter, iterable<hstring> additionalProperties)
{
    return get_activation_factory<DeviceInformation, IDeviceInformationStatics>().CreateWatcher(aqsFilter, additionalProperties);
}

inline hstring DeviceInformation::GetAqsFilterFromDeviceClass(Windows::Devices::Enumeration::DeviceClass deviceClass)
{
    return get_activation_factory<DeviceInformation, IDeviceInformationStatics2>().GetAqsFilterFromDeviceClass(deviceClass);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation> DeviceInformation::CreateFromIdAsync(hstring_view deviceId, iterable<hstring> additionalProperties, Windows::Devices::Enumeration::DeviceInformationKind kind)
{
    return get_activation_factory<DeviceInformation, IDeviceInformationStatics2>().CreateFromIdAsync(deviceId, additionalProperties, kind);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> DeviceInformation::FindAllAsync(hstring_view aqsFilter, iterable<hstring> additionalProperties, Windows::Devices::Enumeration::DeviceInformationKind kind)
{
    return get_activation_factory<DeviceInformation, IDeviceInformationStatics2>().FindAllAsync(aqsFilter, additionalProperties, kind);
}

inline Windows::Devices::Enumeration::DeviceWatcher DeviceInformation::CreateWatcher(hstring_view aqsFilter, iterable<hstring> additionalProperties, Windows::Devices::Enumeration::DeviceInformationKind kind)
{
    return get_activation_factory<DeviceInformation, IDeviceInformationStatics2>().CreateWatcher(aqsFilter, additionalProperties, kind);
}

inline bool DeviceInformationPairing::TryRegisterForAllInboundPairingRequests(Windows::Devices::Enumeration::DevicePairingKinds pairingKindsSupported)
{
    return get_activation_factory<DeviceInformationPairing, IDeviceInformationPairingStatics>().TryRegisterForAllInboundPairingRequests(pairingKindsSupported);
}

inline DevicePicker::DevicePicker() :
    DevicePicker(activate_instance<DevicePicker>())
{}

}

}
#pragma warning(pop)
