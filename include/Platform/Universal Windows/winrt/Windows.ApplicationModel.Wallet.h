// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.UI.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Devices.Geolocation.3.h"
#include "internal/Windows.ApplicationModel.Wallet.3.h"
#include "Windows.ApplicationModel.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::Wallet::IWalletBarcode> : produce_base<D, Windows::ApplicationModel::Wallet::IWalletBarcode>
{
    HRESULT __stdcall get_Symbology(Windows::ApplicationModel::Wallet::WalletBarcodeSymbology * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Symbology());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Value(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Value());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetImageAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamReference>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetImageAsync());
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
struct produce<D, Windows::ApplicationModel::Wallet::IWalletBarcodeFactory> : produce_base<D, Windows::ApplicationModel::Wallet::IWalletBarcodeFactory>
{
    HRESULT __stdcall abi_CreateWalletBarcode(Windows::ApplicationModel::Wallet::WalletBarcodeSymbology symbology, impl::abi_arg_in<hstring> value, impl::abi_arg_out<Windows::ApplicationModel::Wallet::IWalletBarcode> barcode) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *barcode = detach_abi(this->shim().CreateWalletBarcode(symbology, *reinterpret_cast<const hstring *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            *barcode = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateCustomWalletBarcode(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> streamToBarcodeImage, impl::abi_arg_out<Windows::ApplicationModel::Wallet::IWalletBarcode> barcode) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *barcode = detach_abi(this->shim().CreateCustomWalletBarcode(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&streamToBarcodeImage)));
            return S_OK;
        }
        catch (...)
        {
            *barcode = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Wallet::IWalletItem> : produce_base<D, Windows::ApplicationModel::Wallet::IWalletItem>
{
    HRESULT __stdcall get_DisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DisplayName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall get_IsAcknowledged(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsAcknowledged());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsAcknowledged(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsAcknowledged(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IssuerDisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IssuerDisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IssuerDisplayName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IssuerDisplayName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastUpdated(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastUpdated());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LastUpdated(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LastUpdated(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Kind(Windows::ApplicationModel::Wallet::WalletItemKind * value) noexcept override
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

    HRESULT __stdcall get_Barcode(impl::abi_arg_out<Windows::ApplicationModel::Wallet::IWalletBarcode> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Barcode());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Barcode(impl::abi_arg_in<Windows::ApplicationModel::Wallet::IWalletBarcode> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Barcode(*reinterpret_cast<const Windows::ApplicationModel::Wallet::WalletBarcode *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExpirationDate(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExpirationDate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ExpirationDate(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExpirationDate(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Logo159x159(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Logo159x159());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Logo159x159(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Logo159x159(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Logo336x336(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Logo336x336());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Logo336x336(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Logo336x336(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Logo99x99(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Logo99x99());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Logo99x99(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Logo99x99(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayMessage(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DisplayMessage(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayMessage(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDisplayMessageLaunchable(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDisplayMessageLaunchable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsDisplayMessageLaunchable(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsDisplayMessageLaunchable(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LogoText(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LogoText());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LogoText(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LogoText(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HeaderColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HeaderColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_HeaderColor(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HeaderColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BodyColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BodyColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BodyColor(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BodyColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HeaderFontColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HeaderFontColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_HeaderFontColor(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HeaderFontColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BodyFontColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BodyFontColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BodyFontColor(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BodyFontColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HeaderBackgroundImage(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HeaderBackgroundImage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_HeaderBackgroundImage(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HeaderBackgroundImage(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BodyBackgroundImage(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BodyBackgroundImage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BodyBackgroundImage(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BodyBackgroundImage(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LogoImage(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LogoImage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LogoImage(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LogoImage(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PromotionalImage(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PromotionalImage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PromotionalImage(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PromotionalImage(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RelevantDate(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RelevantDate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RelevantDate(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RelevantDate(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RelevantDateDisplayMessage(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RelevantDateDisplayMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RelevantDateDisplayMessage(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RelevantDateDisplayMessage(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransactionHistory(impl::abi_arg_out<Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletTransaction>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransactionHistory());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RelevantLocations(impl::abi_arg_out<Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletRelevantLocation>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RelevantLocations());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsMoreTransactionHistoryLaunchable(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsMoreTransactionHistoryLaunchable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsMoreTransactionHistoryLaunchable(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsMoreTransactionHistoryLaunchable(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayProperties(impl::abi_arg_out<Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletItemCustomProperty>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Verbs(impl::abi_arg_out<Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletVerb>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Verbs());
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
struct produce<D, Windows::ApplicationModel::Wallet::IWalletItemCustomProperty> : produce_base<D, Windows::ApplicationModel::Wallet::IWalletItemCustomProperty>
{
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

    HRESULT __stdcall put_Name(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Name(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Value(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Value());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Value(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Value(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AutoDetectLinks(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AutoDetectLinks());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AutoDetectLinks(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutoDetectLinks(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DetailViewPosition(Windows::ApplicationModel::Wallet::WalletDetailViewPosition * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DetailViewPosition());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DetailViewPosition(Windows::ApplicationModel::Wallet::WalletDetailViewPosition value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DetailViewPosition(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SummaryViewPosition(Windows::ApplicationModel::Wallet::WalletSummaryViewPosition * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SummaryViewPosition());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SummaryViewPosition(Windows::ApplicationModel::Wallet::WalletSummaryViewPosition value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SummaryViewPosition(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Wallet::IWalletItemCustomPropertyFactory> : produce_base<D, Windows::ApplicationModel::Wallet::IWalletItemCustomPropertyFactory>
{
    HRESULT __stdcall abi_CreateWalletItemCustomProperty(impl::abi_arg_in<hstring> name, impl::abi_arg_in<hstring> value, impl::abi_arg_out<Windows::ApplicationModel::Wallet::IWalletItemCustomProperty> walletItemCustomProperty) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *walletItemCustomProperty = detach_abi(this->shim().CreateWalletItemCustomProperty(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const hstring *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            *walletItemCustomProperty = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Wallet::IWalletItemFactory> : produce_base<D, Windows::ApplicationModel::Wallet::IWalletItemFactory>
{
    HRESULT __stdcall abi_CreateWalletItem(Windows::ApplicationModel::Wallet::WalletItemKind kind, impl::abi_arg_in<hstring> displayName, impl::abi_arg_out<Windows::ApplicationModel::Wallet::IWalletItem> walletItem) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *walletItem = detach_abi(this->shim().CreateWalletItem(kind, *reinterpret_cast<const hstring *>(&displayName)));
            return S_OK;
        }
        catch (...)
        {
            *walletItem = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Wallet::IWalletItemStore> : produce_base<D, Windows::ApplicationModel::Wallet::IWalletItemStore>
{
    HRESULT __stdcall abi_AddAsync(impl::abi_arg_in<hstring> id, impl::abi_arg_in<Windows::ApplicationModel::Wallet::IWalletItem> item, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().AddAsync(*reinterpret_cast<const hstring *>(&id), *reinterpret_cast<const Windows::ApplicationModel::Wallet::WalletItem *>(&item)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClearAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ClearAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetWalletItemAsync(impl::abi_arg_in<hstring> id, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItem>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetWalletItemAsync(*reinterpret_cast<const hstring *>(&id)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetItemsAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Wallet::WalletItem>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetItemsAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetItemsWithKindAsync(Windows::ApplicationModel::Wallet::WalletItemKind kind, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Wallet::WalletItem>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetItemsAsync(kind));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ImportItemAsync(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> stream, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItem>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ImportItemAsync(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&stream)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteAsync(impl::abi_arg_in<hstring> id, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().DeleteAsync(*reinterpret_cast<const hstring *>(&id)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ShowAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowItemAsync(impl::abi_arg_in<hstring> id, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ShowAsync(*reinterpret_cast<const hstring *>(&id)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateAsync(impl::abi_arg_in<Windows::ApplicationModel::Wallet::IWalletItem> item, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().UpdateAsync(*reinterpret_cast<const Windows::ApplicationModel::Wallet::WalletItem *>(&item)));
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
struct produce<D, Windows::ApplicationModel::Wallet::IWalletItemStore2> : produce_base<D, Windows::ApplicationModel::Wallet::IWalletItemStore2>
{
    HRESULT __stdcall add_ItemsChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Wallet::WalletItemStore, Windows::Foundation::IInspectable>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().ItemsChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Wallet::WalletItemStore, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ItemsChanged(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ItemsChanged(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Wallet::IWalletManagerStatics> : produce_base<D, Windows::ApplicationModel::Wallet::IWalletManagerStatics>
{
    HRESULT __stdcall abi_RequestStoreAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItemStore>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestStoreAsync());
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
struct produce<D, Windows::ApplicationModel::Wallet::IWalletRelevantLocation> : produce_base<D, Windows::ApplicationModel::Wallet::IWalletRelevantLocation>
{
    HRESULT __stdcall get_Position(impl::abi_arg_out<Windows::Devices::Geolocation::BasicGeoposition> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Position());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Position(impl::abi_arg_in<Windows::Devices::Geolocation::BasicGeoposition> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Position(*reinterpret_cast<const Windows::Devices::Geolocation::BasicGeoposition *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayMessage(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DisplayMessage(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayMessage(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Wallet::IWalletTransaction> : produce_base<D, Windows::ApplicationModel::Wallet::IWalletTransaction>
{
    HRESULT __stdcall get_Description(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Description());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Description(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayAmount(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayAmount());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DisplayAmount(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayAmount(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IgnoreTimeOfDay(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IgnoreTimeOfDay());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IgnoreTimeOfDay(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IgnoreTimeOfDay(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayLocation(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayLocation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DisplayLocation(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayLocation(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransactionDate(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransactionDate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TransactionDate(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransactionDate(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsLaunchable(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsLaunchable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsLaunchable(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsLaunchable(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Wallet::IWalletVerb> : produce_base<D, Windows::ApplicationModel::Wallet::IWalletVerb>
{
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

    HRESULT __stdcall put_Name(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Name(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Wallet::IWalletVerbFactory> : produce_base<D, Windows::ApplicationModel::Wallet::IWalletVerbFactory>
{
    HRESULT __stdcall abi_CreateWalletVerb(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::ApplicationModel::Wallet::IWalletVerb> WalletVerb) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *WalletVerb = detach_abi(this->shim().CreateWalletVerb(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *WalletVerb = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::Wallet {

template <typename D> Windows::ApplicationModel::Wallet::WalletBarcodeSymbology impl_IWalletBarcode<D>::Symbology() const
{
    Windows::ApplicationModel::Wallet::WalletBarcodeSymbology value {};
    check_hresult(WINRT_SHIM(IWalletBarcode)->get_Symbology(&value));
    return value;
}

template <typename D> hstring impl_IWalletBarcode<D>::Value() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWalletBarcode)->get_Value(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamReference> impl_IWalletBarcode<D>::GetImageAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamReference> operation;
    check_hresult(WINRT_SHIM(IWalletBarcode)->abi_GetImageAsync(put_abi(operation)));
    return operation;
}

template <typename D> hstring impl_IWalletItemCustomProperty<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWalletItemCustomProperty)->get_Name(put_abi(value)));
    return value;
}

template <typename D> void impl_IWalletItemCustomProperty<D>::Name(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IWalletItemCustomProperty)->put_Name(get_abi(value)));
}

template <typename D> hstring impl_IWalletItemCustomProperty<D>::Value() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWalletItemCustomProperty)->get_Value(put_abi(value)));
    return value;
}

template <typename D> void impl_IWalletItemCustomProperty<D>::Value(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IWalletItemCustomProperty)->put_Value(get_abi(value)));
}

template <typename D> bool impl_IWalletItemCustomProperty<D>::AutoDetectLinks() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IWalletItemCustomProperty)->get_AutoDetectLinks(&value));
    return value;
}

template <typename D> void impl_IWalletItemCustomProperty<D>::AutoDetectLinks(bool value) const
{
    check_hresult(WINRT_SHIM(IWalletItemCustomProperty)->put_AutoDetectLinks(value));
}

template <typename D> Windows::ApplicationModel::Wallet::WalletDetailViewPosition impl_IWalletItemCustomProperty<D>::DetailViewPosition() const
{
    Windows::ApplicationModel::Wallet::WalletDetailViewPosition value {};
    check_hresult(WINRT_SHIM(IWalletItemCustomProperty)->get_DetailViewPosition(&value));
    return value;
}

template <typename D> void impl_IWalletItemCustomProperty<D>::DetailViewPosition(Windows::ApplicationModel::Wallet::WalletDetailViewPosition value) const
{
    check_hresult(WINRT_SHIM(IWalletItemCustomProperty)->put_DetailViewPosition(value));
}

template <typename D> Windows::ApplicationModel::Wallet::WalletSummaryViewPosition impl_IWalletItemCustomProperty<D>::SummaryViewPosition() const
{
    Windows::ApplicationModel::Wallet::WalletSummaryViewPosition value {};
    check_hresult(WINRT_SHIM(IWalletItemCustomProperty)->get_SummaryViewPosition(&value));
    return value;
}

template <typename D> void impl_IWalletItemCustomProperty<D>::SummaryViewPosition(Windows::ApplicationModel::Wallet::WalletSummaryViewPosition value) const
{
    check_hresult(WINRT_SHIM(IWalletItemCustomProperty)->put_SummaryViewPosition(value));
}

template <typename D> hstring impl_IWalletVerb<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWalletVerb)->get_Name(put_abi(value)));
    return value;
}

template <typename D> void impl_IWalletVerb<D>::Name(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IWalletVerb)->put_Name(get_abi(value)));
}

template <typename D> hstring impl_IWalletItem<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWalletItem)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::DisplayName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IWalletItem)->put_DisplayName(get_abi(value)));
}

template <typename D> hstring impl_IWalletItem<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWalletItem)->get_Id(put_abi(value)));
    return value;
}

template <typename D> bool impl_IWalletItem<D>::IsAcknowledged() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IWalletItem)->get_IsAcknowledged(&value));
    return value;
}

template <typename D> void impl_IWalletItem<D>::IsAcknowledged(bool value) const
{
    check_hresult(WINRT_SHIM(IWalletItem)->put_IsAcknowledged(value));
}

template <typename D> hstring impl_IWalletItem<D>::IssuerDisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWalletItem)->get_IssuerDisplayName(put_abi(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::IssuerDisplayName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IWalletItem)->put_IssuerDisplayName(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IWalletItem<D>::LastUpdated() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IWalletItem)->get_LastUpdated(put_abi(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::LastUpdated(const optional<Windows::Foundation::DateTime> & value) const
{
    check_hresult(WINRT_SHIM(IWalletItem)->put_LastUpdated(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Wallet::WalletItemKind impl_IWalletItem<D>::Kind() const
{
    Windows::ApplicationModel::Wallet::WalletItemKind value {};
    check_hresult(WINRT_SHIM(IWalletItem)->get_Kind(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Wallet::WalletBarcode impl_IWalletItem<D>::Barcode() const
{
    Windows::ApplicationModel::Wallet::WalletBarcode value { nullptr };
    check_hresult(WINRT_SHIM(IWalletItem)->get_Barcode(put_abi(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::Barcode(const Windows::ApplicationModel::Wallet::WalletBarcode & value) const
{
    check_hresult(WINRT_SHIM(IWalletItem)->put_Barcode(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IWalletItem<D>::ExpirationDate() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IWalletItem)->get_ExpirationDate(put_abi(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::ExpirationDate(const optional<Windows::Foundation::DateTime> & value) const
{
    check_hresult(WINRT_SHIM(IWalletItem)->put_ExpirationDate(get_abi(value)));
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IWalletItem<D>::Logo159x159() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(WINRT_SHIM(IWalletItem)->get_Logo159x159(put_abi(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::Logo159x159(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const
{
    check_hresult(WINRT_SHIM(IWalletItem)->put_Logo159x159(get_abi(value)));
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IWalletItem<D>::Logo336x336() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(WINRT_SHIM(IWalletItem)->get_Logo336x336(put_abi(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::Logo336x336(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const
{
    check_hresult(WINRT_SHIM(IWalletItem)->put_Logo336x336(get_abi(value)));
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IWalletItem<D>::Logo99x99() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(WINRT_SHIM(IWalletItem)->get_Logo99x99(put_abi(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::Logo99x99(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const
{
    check_hresult(WINRT_SHIM(IWalletItem)->put_Logo99x99(get_abi(value)));
}

template <typename D> hstring impl_IWalletItem<D>::DisplayMessage() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWalletItem)->get_DisplayMessage(put_abi(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::DisplayMessage(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IWalletItem)->put_DisplayMessage(get_abi(value)));
}

template <typename D> bool impl_IWalletItem<D>::IsDisplayMessageLaunchable() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IWalletItem)->get_IsDisplayMessageLaunchable(&value));
    return value;
}

template <typename D> void impl_IWalletItem<D>::IsDisplayMessageLaunchable(bool value) const
{
    check_hresult(WINRT_SHIM(IWalletItem)->put_IsDisplayMessageLaunchable(value));
}

template <typename D> hstring impl_IWalletItem<D>::LogoText() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWalletItem)->get_LogoText(put_abi(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::LogoText(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IWalletItem)->put_LogoText(get_abi(value)));
}

template <typename D> Windows::UI::Color impl_IWalletItem<D>::HeaderColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IWalletItem)->get_HeaderColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::HeaderColor(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IWalletItem)->put_HeaderColor(get_abi(value)));
}

template <typename D> Windows::UI::Color impl_IWalletItem<D>::BodyColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IWalletItem)->get_BodyColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::BodyColor(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IWalletItem)->put_BodyColor(get_abi(value)));
}

template <typename D> Windows::UI::Color impl_IWalletItem<D>::HeaderFontColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IWalletItem)->get_HeaderFontColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::HeaderFontColor(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IWalletItem)->put_HeaderFontColor(get_abi(value)));
}

template <typename D> Windows::UI::Color impl_IWalletItem<D>::BodyFontColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IWalletItem)->get_BodyFontColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::BodyFontColor(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IWalletItem)->put_BodyFontColor(get_abi(value)));
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IWalletItem<D>::HeaderBackgroundImage() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(WINRT_SHIM(IWalletItem)->get_HeaderBackgroundImage(put_abi(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::HeaderBackgroundImage(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const
{
    check_hresult(WINRT_SHIM(IWalletItem)->put_HeaderBackgroundImage(get_abi(value)));
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IWalletItem<D>::BodyBackgroundImage() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(WINRT_SHIM(IWalletItem)->get_BodyBackgroundImage(put_abi(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::BodyBackgroundImage(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const
{
    check_hresult(WINRT_SHIM(IWalletItem)->put_BodyBackgroundImage(get_abi(value)));
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IWalletItem<D>::LogoImage() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(WINRT_SHIM(IWalletItem)->get_LogoImage(put_abi(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::LogoImage(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const
{
    check_hresult(WINRT_SHIM(IWalletItem)->put_LogoImage(get_abi(value)));
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IWalletItem<D>::PromotionalImage() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(WINRT_SHIM(IWalletItem)->get_PromotionalImage(put_abi(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::PromotionalImage(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const
{
    check_hresult(WINRT_SHIM(IWalletItem)->put_PromotionalImage(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IWalletItem<D>::RelevantDate() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IWalletItem)->get_RelevantDate(put_abi(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::RelevantDate(const optional<Windows::Foundation::DateTime> & value) const
{
    check_hresult(WINRT_SHIM(IWalletItem)->put_RelevantDate(get_abi(value)));
}

template <typename D> hstring impl_IWalletItem<D>::RelevantDateDisplayMessage() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWalletItem)->get_RelevantDateDisplayMessage(put_abi(value)));
    return value;
}

template <typename D> void impl_IWalletItem<D>::RelevantDateDisplayMessage(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IWalletItem)->put_RelevantDateDisplayMessage(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletTransaction> impl_IWalletItem<D>::TransactionHistory() const
{
    Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletTransaction> value;
    check_hresult(WINRT_SHIM(IWalletItem)->get_TransactionHistory(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletRelevantLocation> impl_IWalletItem<D>::RelevantLocations() const
{
    Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletRelevantLocation> value;
    check_hresult(WINRT_SHIM(IWalletItem)->get_RelevantLocations(put_abi(value)));
    return value;
}

template <typename D> bool impl_IWalletItem<D>::IsMoreTransactionHistoryLaunchable() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IWalletItem)->get_IsMoreTransactionHistoryLaunchable(&value));
    return value;
}

template <typename D> void impl_IWalletItem<D>::IsMoreTransactionHistoryLaunchable(bool value) const
{
    check_hresult(WINRT_SHIM(IWalletItem)->put_IsMoreTransactionHistoryLaunchable(value));
}

template <typename D> Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletItemCustomProperty> impl_IWalletItem<D>::DisplayProperties() const
{
    Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletItemCustomProperty> value;
    check_hresult(WINRT_SHIM(IWalletItem)->get_DisplayProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletVerb> impl_IWalletItem<D>::Verbs() const
{
    Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletVerb> value;
    check_hresult(WINRT_SHIM(IWalletItem)->get_Verbs(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IWalletTransaction<D>::Description() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWalletTransaction)->get_Description(put_abi(value)));
    return value;
}

template <typename D> void impl_IWalletTransaction<D>::Description(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IWalletTransaction)->put_Description(get_abi(value)));
}

template <typename D> hstring impl_IWalletTransaction<D>::DisplayAmount() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWalletTransaction)->get_DisplayAmount(put_abi(value)));
    return value;
}

template <typename D> void impl_IWalletTransaction<D>::DisplayAmount(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IWalletTransaction)->put_DisplayAmount(get_abi(value)));
}

template <typename D> bool impl_IWalletTransaction<D>::IgnoreTimeOfDay() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IWalletTransaction)->get_IgnoreTimeOfDay(&value));
    return value;
}

template <typename D> void impl_IWalletTransaction<D>::IgnoreTimeOfDay(bool value) const
{
    check_hresult(WINRT_SHIM(IWalletTransaction)->put_IgnoreTimeOfDay(value));
}

template <typename D> hstring impl_IWalletTransaction<D>::DisplayLocation() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWalletTransaction)->get_DisplayLocation(put_abi(value)));
    return value;
}

template <typename D> void impl_IWalletTransaction<D>::DisplayLocation(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IWalletTransaction)->put_DisplayLocation(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IWalletTransaction<D>::TransactionDate() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IWalletTransaction)->get_TransactionDate(put_abi(value)));
    return value;
}

template <typename D> void impl_IWalletTransaction<D>::TransactionDate(const optional<Windows::Foundation::DateTime> & value) const
{
    check_hresult(WINRT_SHIM(IWalletTransaction)->put_TransactionDate(get_abi(value)));
}

template <typename D> bool impl_IWalletTransaction<D>::IsLaunchable() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IWalletTransaction)->get_IsLaunchable(&value));
    return value;
}

template <typename D> void impl_IWalletTransaction<D>::IsLaunchable(bool value) const
{
    check_hresult(WINRT_SHIM(IWalletTransaction)->put_IsLaunchable(value));
}

template <typename D> Windows::Devices::Geolocation::BasicGeoposition impl_IWalletRelevantLocation<D>::Position() const
{
    Windows::Devices::Geolocation::BasicGeoposition value {};
    check_hresult(WINRT_SHIM(IWalletRelevantLocation)->get_Position(put_abi(value)));
    return value;
}

template <typename D> void impl_IWalletRelevantLocation<D>::Position(const Windows::Devices::Geolocation::BasicGeoposition & value) const
{
    check_hresult(WINRT_SHIM(IWalletRelevantLocation)->put_Position(get_abi(value)));
}

template <typename D> hstring impl_IWalletRelevantLocation<D>::DisplayMessage() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWalletRelevantLocation)->get_DisplayMessage(put_abi(value)));
    return value;
}

template <typename D> void impl_IWalletRelevantLocation<D>::DisplayMessage(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IWalletRelevantLocation)->put_DisplayMessage(get_abi(value)));
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWalletItemStore<D>::AddAsync(hstring_view id, const Windows::ApplicationModel::Wallet::WalletItem & item) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IWalletItemStore)->abi_AddAsync(get_abi(id), get_abi(item), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWalletItemStore<D>::ClearAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IWalletItemStore)->abi_ClearAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItem> impl_IWalletItemStore<D>::GetWalletItemAsync(hstring_view id) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItem> operation;
    check_hresult(WINRT_SHIM(IWalletItemStore)->abi_GetWalletItemAsync(get_abi(id), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Wallet::WalletItem>> impl_IWalletItemStore<D>::GetItemsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Wallet::WalletItem>> operation;
    check_hresult(WINRT_SHIM(IWalletItemStore)->abi_GetItemsAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Wallet::WalletItem>> impl_IWalletItemStore<D>::GetItemsAsync(Windows::ApplicationModel::Wallet::WalletItemKind kind) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Wallet::WalletItem>> operation;
    check_hresult(WINRT_SHIM(IWalletItemStore)->abi_GetItemsWithKindAsync(kind, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItem> impl_IWalletItemStore<D>::ImportItemAsync(const Windows::Storage::Streams::IRandomAccessStreamReference & stream) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItem> operation;
    check_hresult(WINRT_SHIM(IWalletItemStore)->abi_ImportItemAsync(get_abi(stream), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWalletItemStore<D>::DeleteAsync(hstring_view id) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IWalletItemStore)->abi_DeleteAsync(get_abi(id), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWalletItemStore<D>::ShowAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IWalletItemStore)->abi_ShowAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWalletItemStore<D>::ShowAsync(hstring_view id) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IWalletItemStore)->abi_ShowItemAsync(get_abi(id), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWalletItemStore<D>::UpdateAsync(const Windows::ApplicationModel::Wallet::WalletItem & item) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IWalletItemStore)->abi_UpdateAsync(get_abi(item), put_abi(operation)));
    return operation;
}

template <typename D> event_token impl_IWalletItemStore2<D>::ItemsChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Wallet::WalletItemStore, Windows::Foundation::IInspectable> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IWalletItemStore2)->add_ItemsChanged(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IWalletItemStore2> impl_IWalletItemStore2<D>::ItemsChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Wallet::WalletItemStore, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IWalletItemStore2>(this, &ABI::Windows::ApplicationModel::Wallet::IWalletItemStore2::remove_ItemsChanged, ItemsChanged(handler));
}

template <typename D> void impl_IWalletItemStore2<D>::ItemsChanged(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IWalletItemStore2)->remove_ItemsChanged(cookie));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItemStore> impl_IWalletManagerStatics<D>::RequestStoreAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItemStore> operation;
    check_hresult(WINRT_SHIM(IWalletManagerStatics)->abi_RequestStoreAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::ApplicationModel::Wallet::WalletItemCustomProperty impl_IWalletItemCustomPropertyFactory<D>::CreateWalletItemCustomProperty(hstring_view name, hstring_view value) const
{
    Windows::ApplicationModel::Wallet::WalletItemCustomProperty walletItemCustomProperty { nullptr };
    check_hresult(WINRT_SHIM(IWalletItemCustomPropertyFactory)->abi_CreateWalletItemCustomProperty(get_abi(name), get_abi(value), put_abi(walletItemCustomProperty)));
    return walletItemCustomProperty;
}

template <typename D> Windows::ApplicationModel::Wallet::WalletVerb impl_IWalletVerbFactory<D>::CreateWalletVerb(hstring_view name) const
{
    Windows::ApplicationModel::Wallet::WalletVerb WalletVerb { nullptr };
    check_hresult(WINRT_SHIM(IWalletVerbFactory)->abi_CreateWalletVerb(get_abi(name), put_abi(WalletVerb)));
    return WalletVerb;
}

template <typename D> Windows::ApplicationModel::Wallet::WalletItem impl_IWalletItemFactory<D>::CreateWalletItem(Windows::ApplicationModel::Wallet::WalletItemKind kind, hstring_view displayName) const
{
    Windows::ApplicationModel::Wallet::WalletItem walletItem { nullptr };
    check_hresult(WINRT_SHIM(IWalletItemFactory)->abi_CreateWalletItem(kind, get_abi(displayName), put_abi(walletItem)));
    return walletItem;
}

template <typename D> Windows::ApplicationModel::Wallet::WalletBarcode impl_IWalletBarcodeFactory<D>::CreateWalletBarcode(Windows::ApplicationModel::Wallet::WalletBarcodeSymbology symbology, hstring_view value) const
{
    Windows::ApplicationModel::Wallet::WalletBarcode barcode { nullptr };
    check_hresult(WINRT_SHIM(IWalletBarcodeFactory)->abi_CreateWalletBarcode(symbology, get_abi(value), put_abi(barcode)));
    return barcode;
}

template <typename D> Windows::ApplicationModel::Wallet::WalletBarcode impl_IWalletBarcodeFactory<D>::CreateCustomWalletBarcode(const Windows::Storage::Streams::IRandomAccessStreamReference & streamToBarcodeImage) const
{
    Windows::ApplicationModel::Wallet::WalletBarcode barcode { nullptr };
    check_hresult(WINRT_SHIM(IWalletBarcodeFactory)->abi_CreateCustomWalletBarcode(get_abi(streamToBarcodeImage), put_abi(barcode)));
    return barcode;
}

inline WalletBarcode::WalletBarcode(Windows::ApplicationModel::Wallet::WalletBarcodeSymbology symbology, hstring_view value) :
    WalletBarcode(get_activation_factory<WalletBarcode, IWalletBarcodeFactory>().CreateWalletBarcode(symbology, value))
{}

inline WalletBarcode::WalletBarcode(const Windows::Storage::Streams::IRandomAccessStreamReference & streamToBarcodeImage) :
    WalletBarcode(get_activation_factory<WalletBarcode, IWalletBarcodeFactory>().CreateCustomWalletBarcode(streamToBarcodeImage))
{}

inline WalletItem::WalletItem(Windows::ApplicationModel::Wallet::WalletItemKind kind, hstring_view displayName) :
    WalletItem(get_activation_factory<WalletItem, IWalletItemFactory>().CreateWalletItem(kind, displayName))
{}

inline WalletItemCustomProperty::WalletItemCustomProperty(hstring_view name, hstring_view value) :
    WalletItemCustomProperty(get_activation_factory<WalletItemCustomProperty, IWalletItemCustomPropertyFactory>().CreateWalletItemCustomProperty(name, value))
{}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItemStore> WalletManager::RequestStoreAsync()
{
    return get_activation_factory<WalletManager, IWalletManagerStatics>().RequestStoreAsync();
}

inline WalletRelevantLocation::WalletRelevantLocation() :
    WalletRelevantLocation(activate_instance<WalletRelevantLocation>())
{}

inline WalletTransaction::WalletTransaction() :
    WalletTransaction(activate_instance<WalletTransaction>())
{}

inline WalletVerb::WalletVerb(hstring_view name) :
    WalletVerb(get_activation_factory<WalletVerb, IWalletVerbFactory>().CreateWalletVerb(name))
{}

}

}
#pragma warning(pop)
