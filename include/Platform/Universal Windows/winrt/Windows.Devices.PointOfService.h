// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Graphics.Imaging.3.h"
#include "internal/Windows.Devices.PointOfService.3.h"
#include "Windows.Devices.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::PointOfService::IBarcodeScanner> : produce_base<D, Windows::Devices::PointOfService::IBarcodeScanner>
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

    HRESULT __stdcall get_Capabilities(impl::abi_arg_out<Windows::Devices::PointOfService::IBarcodeScannerCapabilities> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Capabilities());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClaimScannerAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::ClaimedBarcodeScanner>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ClaimScannerAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CheckHealthAsync(Windows::Devices::PointOfService::UnifiedPosHealthCheckLevel level, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CheckHealthAsync(level));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSupportedSymbologiesAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<uint32_t>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetSupportedSymbologiesAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsSymbologySupportedAsync(uint32_t barcodeSymbology, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().IsSymbologySupportedAsync(barcodeSymbology));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RetrieveStatisticsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> statisticsCategories, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RetrieveStatisticsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&statisticsCategories)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSupportedProfiles(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetSupportedProfiles());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsProfileSupported(impl::abi_arg_in<hstring> profile, bool * isSupported) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *isSupported = detach_abi(this->shim().IsProfileSupported(*reinterpret_cast<const hstring *>(&profile)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_StatusUpdated(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::BarcodeScanner, Windows::Devices::PointOfService::BarcodeScannerStatusUpdatedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().StatusUpdated(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::BarcodeScanner, Windows::Devices::PointOfService::BarcodeScannerStatusUpdatedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_StatusUpdated(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StatusUpdated(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::PointOfService::IBarcodeScanner2> : produce_base<D, Windows::Devices::PointOfService::IBarcodeScanner2>
{
    HRESULT __stdcall get_VideoDeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoDeviceId());
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
struct produce<D, Windows::Devices::PointOfService::IBarcodeScannerCapabilities> : produce_base<D, Windows::Devices::PointOfService::IBarcodeScannerCapabilities>
{
    HRESULT __stdcall get_PowerReportingType(Windows::Devices::PointOfService::UnifiedPosPowerReportingType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PowerReportingType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsStatisticsReportingSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsStatisticsReportingSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsStatisticsUpdatingSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsStatisticsUpdatingSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsImagePreviewSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsImagePreviewSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::PointOfService::IBarcodeScannerCapabilities1> : produce_base<D, Windows::Devices::PointOfService::IBarcodeScannerCapabilities1>
{
    HRESULT __stdcall get_IsSoftwareTriggerSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsSoftwareTriggerSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::PointOfService::IBarcodeScannerDataReceivedEventArgs> : produce_base<D, Windows::Devices::PointOfService::IBarcodeScannerDataReceivedEventArgs>
{
    HRESULT __stdcall get_Report(impl::abi_arg_out<Windows::Devices::PointOfService::IBarcodeScannerReport> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Report());
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
struct produce<D, Windows::Devices::PointOfService::IBarcodeScannerErrorOccurredEventArgs> : produce_base<D, Windows::Devices::PointOfService::IBarcodeScannerErrorOccurredEventArgs>
{
    HRESULT __stdcall get_PartialInputData(impl::abi_arg_out<Windows::Devices::PointOfService::IBarcodeScannerReport> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PartialInputData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsRetriable(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsRetriable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ErrorData(impl::abi_arg_out<Windows::Devices::PointOfService::IUnifiedPosErrorData> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ErrorData());
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
struct produce<D, Windows::Devices::PointOfService::IBarcodeScannerImagePreviewReceivedEventArgs> : produce_base<D, Windows::Devices::PointOfService::IBarcodeScannerImagePreviewReceivedEventArgs>
{
    HRESULT __stdcall get_Preview(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamWithContentType> preview) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *preview = detach_abi(this->shim().Preview());
            return S_OK;
        }
        catch (...)
        {
            *preview = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::PointOfService::IBarcodeScannerReport> : produce_base<D, Windows::Devices::PointOfService::IBarcodeScannerReport>
{
    HRESULT __stdcall get_ScanDataType(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScanDataType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ScanData(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScanData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ScanDataLabel(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScanDataLabel());
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
struct produce<D, Windows::Devices::PointOfService::IBarcodeScannerStatics> : produce_base<D, Windows::Devices::PointOfService::IBarcodeScannerStatics>
{
    HRESULT __stdcall abi_GetDefaultAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::BarcodeScanner>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDefaultAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::BarcodeScanner>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FromIdAsync(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelector(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeviceSelector());
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
struct produce<D, Windows::Devices::PointOfService::IBarcodeScannerStatusUpdatedEventArgs> : produce_base<D, Windows::Devices::PointOfService::IBarcodeScannerStatusUpdatedEventArgs>
{
    HRESULT __stdcall get_Status(Windows::Devices::PointOfService::BarcodeScannerStatus * value) noexcept override
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

    HRESULT __stdcall get_ExtendedStatus(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::PointOfService::IBarcodeSymbologiesStatics> : produce_base<D, Windows::Devices::PointOfService::IBarcodeSymbologiesStatics>
{
    HRESULT __stdcall get_Unknown(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Unknown());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Ean8(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Ean8());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Ean8Add2(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Ean8Add2());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Ean8Add5(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Ean8Add5());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Eanv(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Eanv());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EanvAdd2(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EanvAdd2());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EanvAdd5(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EanvAdd5());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Ean13(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Ean13());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Ean13Add2(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Ean13Add2());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Ean13Add5(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Ean13Add5());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Isbn(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Isbn());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsbnAdd5(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsbnAdd5());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Ismn(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Ismn());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsmnAdd2(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsmnAdd2());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsmnAdd5(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsmnAdd5());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Issn(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Issn());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IssnAdd2(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IssnAdd2());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IssnAdd5(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IssnAdd5());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Ean99(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Ean99());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Ean99Add2(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Ean99Add2());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Ean99Add5(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Ean99Add5());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Upca(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Upca());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UpcaAdd2(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UpcaAdd2());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UpcaAdd5(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UpcaAdd5());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Upce(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Upce());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UpceAdd2(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UpceAdd2());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UpceAdd5(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UpceAdd5());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UpcCoupon(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UpcCoupon());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TfStd(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TfStd());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TfDis(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TfDis());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TfInt(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TfInt());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TfInd(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TfInd());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TfMat(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TfMat());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TfIata(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TfIata());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Gs1DatabarType1(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Gs1DatabarType1());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Gs1DatabarType2(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Gs1DatabarType2());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Gs1DatabarType3(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Gs1DatabarType3());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Code39(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Code39());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Code39Ex(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Code39Ex());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Trioptic39(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Trioptic39());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Code32(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Code32());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Pzn(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Pzn());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Code93(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Code93());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Code93Ex(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Code93Ex());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Code128(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Code128());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Gs1128(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Gs1128());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Gs1128Coupon(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Gs1128Coupon());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UccEan128(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UccEan128());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Sisac(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Sisac());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Isbt(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Isbt());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Codabar(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Codabar());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Code11(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Code11());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Msi(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Msi());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Plessey(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Plessey());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Telepen(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Telepen());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Code16k(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Code16k());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CodablockA(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CodablockA());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CodablockF(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CodablockF());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Codablock128(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Codablock128());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Code49(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Code49());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Aztec(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Aztec());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DataCode(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DataCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DataMatrix(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DataMatrix());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HanXin(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HanXin());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Maxicode(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Maxicode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MicroPdf417(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MicroPdf417());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MicroQr(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MicroQr());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Pdf417(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Pdf417());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Qr(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Qr());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MsTag(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MsTag());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Ccab(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Ccab());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Ccc(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Ccc());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Tlc39(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Tlc39());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AusPost(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AusPost());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanPost(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanPost());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ChinaPost(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChinaPost());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DutchKix(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DutchKix());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InfoMail(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InfoMail());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ItalianPost25(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ItalianPost25());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ItalianPost39(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ItalianPost39());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_JapanPost(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().JapanPost());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KoreanPost(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KoreanPost());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SwedenPost(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SwedenPost());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UkPost(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UkPost());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UsIntelligent(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UsIntelligent());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UsIntelligentPkg(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UsIntelligentPkg());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UsPlanet(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UsPlanet());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UsPostNet(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UsPostNet());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Us4StateFics(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Us4StateFics());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OcrA(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OcrA());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OcrB(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OcrB());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Micr(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Micr());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExtendedBase(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedBase());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetName(uint32_t scanDataType, impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetName(scanDataType));
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
struct produce<D, Windows::Devices::PointOfService::ICashDrawer> : produce_base<D, Windows::Devices::PointOfService::ICashDrawer>
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

    HRESULT __stdcall get_Capabilities(impl::abi_arg_out<Windows::Devices::PointOfService::ICashDrawerCapabilities> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Capabilities());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(impl::abi_arg_out<Windows::Devices::PointOfService::ICashDrawerStatus> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDrawerOpen(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDrawerOpen());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DrawerEventSource(impl::abi_arg_out<Windows::Devices::PointOfService::ICashDrawerEventSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DrawerEventSource());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClaimDrawerAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::ClaimedCashDrawer>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ClaimDrawerAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CheckHealthAsync(Windows::Devices::PointOfService::UnifiedPosHealthCheckLevel level, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CheckHealthAsync(level));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStatisticsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> statisticsCategories, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetStatisticsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&statisticsCategories)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_StatusUpdated(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::CashDrawer, Windows::Devices::PointOfService::CashDrawerStatusUpdatedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().StatusUpdated(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::CashDrawer, Windows::Devices::PointOfService::CashDrawerStatusUpdatedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_StatusUpdated(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StatusUpdated(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::PointOfService::ICashDrawerCapabilities> : produce_base<D, Windows::Devices::PointOfService::ICashDrawerCapabilities>
{
    HRESULT __stdcall get_PowerReportingType(Windows::Devices::PointOfService::UnifiedPosPowerReportingType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PowerReportingType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsStatisticsReportingSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsStatisticsReportingSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsStatisticsUpdatingSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsStatisticsUpdatingSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsStatusReportingSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsStatusReportingSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsStatusMultiDrawerDetectSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsStatusMultiDrawerDetectSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDrawerOpenSensorAvailable(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDrawerOpenSensorAvailable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::PointOfService::ICashDrawerCloseAlarm> : produce_base<D, Windows::Devices::PointOfService::ICashDrawerCloseAlarm>
{
    HRESULT __stdcall put_AlarmTimeout(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AlarmTimeout(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AlarmTimeout(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AlarmTimeout());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BeepFrequency(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BeepFrequency(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BeepFrequency(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BeepFrequency());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BeepDuration(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BeepDuration(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BeepDuration(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BeepDuration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BeepDelay(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BeepDelay(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BeepDelay(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BeepDelay());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_AlarmTimeoutExpired(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::CashDrawerCloseAlarm, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().AlarmTimeoutExpired(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::CashDrawerCloseAlarm, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AlarmTimeoutExpired(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AlarmTimeoutExpired(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().StartAsync());
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
struct produce<D, Windows::Devices::PointOfService::ICashDrawerEventSource> : produce_base<D, Windows::Devices::PointOfService::ICashDrawerEventSource>
{
    HRESULT __stdcall add_DrawerClosed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::CashDrawerEventSource, Windows::Devices::PointOfService::CashDrawerClosedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().DrawerClosed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::CashDrawerEventSource, Windows::Devices::PointOfService::CashDrawerClosedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DrawerClosed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DrawerClosed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DrawerOpened(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::CashDrawerEventSource, Windows::Devices::PointOfService::CashDrawerOpenedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().DrawerOpened(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::CashDrawerEventSource, Windows::Devices::PointOfService::CashDrawerOpenedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DrawerOpened(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DrawerOpened(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::PointOfService::ICashDrawerEventSourceEventArgs> : produce_base<D, Windows::Devices::PointOfService::ICashDrawerEventSourceEventArgs>
{
    HRESULT __stdcall get_CashDrawer(impl::abi_arg_out<Windows::Devices::PointOfService::ICashDrawer> drawer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *drawer = detach_abi(this->shim().CashDrawer());
            return S_OK;
        }
        catch (...)
        {
            *drawer = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::PointOfService::ICashDrawerStatics> : produce_base<D, Windows::Devices::PointOfService::ICashDrawerStatics>
{
    HRESULT __stdcall abi_GetDefaultAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::CashDrawer>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDefaultAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::CashDrawer>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FromIdAsync(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelector(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeviceSelector());
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
struct produce<D, Windows::Devices::PointOfService::ICashDrawerStatus> : produce_base<D, Windows::Devices::PointOfService::ICashDrawerStatus>
{
    HRESULT __stdcall get_StatusKind(Windows::Devices::PointOfService::CashDrawerStatusKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StatusKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExtendedStatus(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::PointOfService::ICashDrawerStatusUpdatedEventArgs> : produce_base<D, Windows::Devices::PointOfService::ICashDrawerStatusUpdatedEventArgs>
{
    HRESULT __stdcall get_Status(impl::abi_arg_out<Windows::Devices::PointOfService::ICashDrawerStatus> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
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
struct produce<D, Windows::Devices::PointOfService::IClaimedBarcodeScanner> : produce_base<D, Windows::Devices::PointOfService::IClaimedBarcodeScanner>
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

    HRESULT __stdcall put_IsDisabledOnDataReceived(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsDisabledOnDataReceived(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDisabledOnDataReceived(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDisabledOnDataReceived());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsDecodeDataEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsDecodeDataEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDecodeDataEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDecodeDataEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_EnableAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().EnableAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DisableAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().DisableAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RetainDevice() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RetainDevice();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetActiveSymbologiesAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<uint32_t>> symbologies, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SetActiveSymbologiesAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<uint32_t> *>(&symbologies)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ResetStatisticsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> statisticsCategories, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ResetStatisticsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&statisticsCategories)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateStatisticsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>>> statistics, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().UpdateStatisticsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>> *>(&statistics)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetActiveProfileAsync(impl::abi_arg_in<hstring> profile, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SetActiveProfileAsync(*reinterpret_cast<const hstring *>(&profile)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DataReceived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedBarcodeScanner, Windows::Devices::PointOfService::BarcodeScannerDataReceivedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().DataReceived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedBarcodeScanner, Windows::Devices::PointOfService::BarcodeScannerDataReceivedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DataReceived(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DataReceived(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_TriggerPressed(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Devices::PointOfService::ClaimedBarcodeScanner>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().TriggerPressed(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Devices::PointOfService::ClaimedBarcodeScanner> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_TriggerPressed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TriggerPressed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_TriggerReleased(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Devices::PointOfService::ClaimedBarcodeScanner>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().TriggerReleased(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Devices::PointOfService::ClaimedBarcodeScanner> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_TriggerReleased(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TriggerReleased(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ReleaseDeviceRequested(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Devices::PointOfService::ClaimedBarcodeScanner>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ReleaseDeviceRequested(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Devices::PointOfService::ClaimedBarcodeScanner> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ReleaseDeviceRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReleaseDeviceRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ImagePreviewReceived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedBarcodeScanner, Windows::Devices::PointOfService::BarcodeScannerImagePreviewReceivedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ImagePreviewReceived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedBarcodeScanner, Windows::Devices::PointOfService::BarcodeScannerImagePreviewReceivedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ImagePreviewReceived(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ImagePreviewReceived(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ErrorOccurred(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedBarcodeScanner, Windows::Devices::PointOfService::BarcodeScannerErrorOccurredEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ErrorOccurred(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedBarcodeScanner, Windows::Devices::PointOfService::BarcodeScannerErrorOccurredEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ErrorOccurred(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ErrorOccurred(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::PointOfService::IClaimedBarcodeScanner1> : produce_base<D, Windows::Devices::PointOfService::IClaimedBarcodeScanner1>
{
    HRESULT __stdcall abi_StartSoftwareTriggerAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().StartSoftwareTriggerAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopSoftwareTriggerAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().StopSoftwareTriggerAsync());
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
struct produce<D, Windows::Devices::PointOfService::IClaimedCashDrawer> : produce_base<D, Windows::Devices::PointOfService::IClaimedCashDrawer>
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

    HRESULT __stdcall get_IsDrawerOpen(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDrawerOpen());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CloseAlarm(impl::abi_arg_out<Windows::Devices::PointOfService::ICashDrawerCloseAlarm> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CloseAlarm());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OpenDrawerAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().OpenDrawerAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_EnableAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().EnableAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DisableAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().DisableAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RetainDeviceAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RetainDeviceAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ResetStatisticsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> statisticsCategories, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ResetStatisticsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&statisticsCategories)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateStatisticsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>>> statistics, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().UpdateStatisticsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>> *>(&statistics)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ReleaseDeviceRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedCashDrawer, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ReleaseDeviceRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedCashDrawer, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ReleaseDeviceRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReleaseDeviceRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::PointOfService::IClaimedJournalPrinter> : produce_base<D, Windows::Devices::PointOfService::IClaimedJournalPrinter>
{
    HRESULT __stdcall abi_CreateJob(impl::abi_arg_out<Windows::Devices::PointOfService::IPosPrinterJob> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateJob());
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
struct produce<D, Windows::Devices::PointOfService::IClaimedMagneticStripeReader> : produce_base<D, Windows::Devices::PointOfService::IClaimedMagneticStripeReader>
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

    HRESULT __stdcall put_IsDisabledOnDataReceived(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsDisabledOnDataReceived(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDisabledOnDataReceived(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDisabledOnDataReceived());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsDecodeDataEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsDecodeDataEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDecodeDataEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDecodeDataEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDeviceAuthenticated(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDeviceAuthenticated());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DataEncryptionAlgorithm(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DataEncryptionAlgorithm(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DataEncryptionAlgorithm(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DataEncryptionAlgorithm());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TracksToRead(Windows::Devices::PointOfService::MagneticStripeReaderTrackIds value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TracksToRead(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TracksToRead(Windows::Devices::PointOfService::MagneticStripeReaderTrackIds * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TracksToRead());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsTransmitSentinelsEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsTransmitSentinelsEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsTransmitSentinelsEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsTransmitSentinelsEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_EnableAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().EnableAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DisableAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().DisableAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RetainDevice() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RetainDevice();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetErrorReportingType(Windows::Devices::PointOfService::MagneticStripeReaderErrorReportingType value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetErrorReportingType(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RetrieveDeviceAuthenticationDataAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RetrieveDeviceAuthenticationDataAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AuthenticateDeviceAsync(uint32_t __responseTokenSize, impl::abi_arg_in<uint8_t> * responseToken, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().AuthenticateDeviceAsync(array_view<const uint8_t>(responseToken, responseToken + __responseTokenSize)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeAuthenticateDeviceAsync(uint32_t __responseTokenSize, impl::abi_arg_in<uint8_t> * responseToken, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().DeAuthenticateDeviceAsync(array_view<const uint8_t>(responseToken, responseToken + __responseTokenSize)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateKeyAsync(impl::abi_arg_in<hstring> key, impl::abi_arg_in<hstring> keyName, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().UpdateKeyAsync(*reinterpret_cast<const hstring *>(&key), *reinterpret_cast<const hstring *>(&keyName)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ResetStatisticsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> statisticsCategories, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ResetStatisticsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&statisticsCategories)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateStatisticsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>>> statistics, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().UpdateStatisticsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>> *>(&statistics)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_BankCardDataReceived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedMagneticStripeReader, Windows::Devices::PointOfService::MagneticStripeReaderBankCardDataReceivedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().BankCardDataReceived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedMagneticStripeReader, Windows::Devices::PointOfService::MagneticStripeReaderBankCardDataReceivedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_BankCardDataReceived(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BankCardDataReceived(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_AamvaCardDataReceived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedMagneticStripeReader, Windows::Devices::PointOfService::MagneticStripeReaderAamvaCardDataReceivedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().AamvaCardDataReceived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedMagneticStripeReader, Windows::Devices::PointOfService::MagneticStripeReaderAamvaCardDataReceivedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AamvaCardDataReceived(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AamvaCardDataReceived(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_VendorSpecificDataReceived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedMagneticStripeReader, Windows::Devices::PointOfService::MagneticStripeReaderVendorSpecificCardDataReceivedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().VendorSpecificDataReceived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedMagneticStripeReader, Windows::Devices::PointOfService::MagneticStripeReaderVendorSpecificCardDataReceivedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_VendorSpecificDataReceived(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VendorSpecificDataReceived(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ReleaseDeviceRequested(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Devices::PointOfService::ClaimedMagneticStripeReader>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ReleaseDeviceRequested(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Devices::PointOfService::ClaimedMagneticStripeReader> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ReleaseDeviceRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReleaseDeviceRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ErrorOccurred(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedMagneticStripeReader, Windows::Devices::PointOfService::MagneticStripeReaderErrorOccurredEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ErrorOccurred(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedMagneticStripeReader, Windows::Devices::PointOfService::MagneticStripeReaderErrorOccurredEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ErrorOccurred(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ErrorOccurred(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::PointOfService::IClaimedPosPrinter> : produce_base<D, Windows::Devices::PointOfService::IClaimedPosPrinter>
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

    HRESULT __stdcall put_CharacterSet(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CharacterSet(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CharacterSet(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CharacterSet());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsCoverOpen(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCoverOpen());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsCharacterSetMappingEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsCharacterSetMappingEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsCharacterSetMappingEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCharacterSetMappingEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MapMode(Windows::Devices::PointOfService::PosPrinterMapMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MapMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MapMode(Windows::Devices::PointOfService::PosPrinterMapMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MapMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Receipt(impl::abi_arg_out<Windows::Devices::PointOfService::IClaimedReceiptPrinter> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Receipt());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Slip(impl::abi_arg_out<Windows::Devices::PointOfService::IClaimedSlipPrinter> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Slip());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Journal(impl::abi_arg_out<Windows::Devices::PointOfService::IClaimedJournalPrinter> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Journal());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_EnableAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().EnableAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DisableAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().DisableAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RetainDeviceAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RetainDeviceAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ResetStatisticsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> statisticsCategories, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ResetStatisticsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&statisticsCategories)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateStatisticsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>>> statistics, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().UpdateStatisticsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>> *>(&statistics)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ReleaseDeviceRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedPosPrinter, Windows::Devices::PointOfService::PosPrinterReleaseDeviceRequestedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ReleaseDeviceRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedPosPrinter, Windows::Devices::PointOfService::PosPrinterReleaseDeviceRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ReleaseDeviceRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReleaseDeviceRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::PointOfService::IClaimedReceiptPrinter> : produce_base<D, Windows::Devices::PointOfService::IClaimedReceiptPrinter>
{
    HRESULT __stdcall get_SidewaysMaxLines(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SidewaysMaxLines());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SidewaysMaxChars(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SidewaysMaxChars());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LinesToPaperCut(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LinesToPaperCut());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PageSize(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PageSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PrintArea(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PrintArea());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateJob(impl::abi_arg_out<Windows::Devices::PointOfService::IReceiptPrintJob> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateJob());
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
struct produce<D, Windows::Devices::PointOfService::IClaimedSlipPrinter> : produce_base<D, Windows::Devices::PointOfService::IClaimedSlipPrinter>
{
    HRESULT __stdcall get_SidewaysMaxLines(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SidewaysMaxLines());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SidewaysMaxChars(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SidewaysMaxChars());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxLines(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxLines());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LinesNearEndToEnd(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LinesNearEndToEnd());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PrintSide(Windows::Devices::PointOfService::PosPrinterPrintSide * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PrintSide());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PageSize(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PageSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PrintArea(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PrintArea());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OpenJaws() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OpenJaws();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CloseJaws() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CloseJaws();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InsertSlipAsync(impl::abi_arg_in<Windows::Foundation::TimeSpan> timeout, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().InsertSlipAsync(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&timeout)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveSlipAsync(impl::abi_arg_in<Windows::Foundation::TimeSpan> timeout, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RemoveSlipAsync(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&timeout)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ChangePrintSide(Windows::Devices::PointOfService::PosPrinterPrintSide printSide) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ChangePrintSide(printSide);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateJob(impl::abi_arg_out<Windows::Devices::PointOfService::IReceiptOrSlipJob> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateJob());
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
struct produce<D, Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation> : produce_base<D, Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>
{
    HRESULT __stdcall put_CharactersPerLine(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CharactersPerLine(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CharactersPerLine(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CharactersPerLine());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LineHeight(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LineHeight(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LineHeight(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LineHeight());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LineSpacing(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LineSpacing(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LineSpacing(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LineSpacing());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LineWidth(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LineWidth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsLetterQuality(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsLetterQuality(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsLetterQuality(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsLetterQuality());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsPaperNearEnd(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsPaperNearEnd());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ColorCartridge(Windows::Devices::PointOfService::PosPrinterColorCartridge value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ColorCartridge(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ColorCartridge(Windows::Devices::PointOfService::PosPrinterColorCartridge * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ColorCartridge());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsCoverOpen(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCoverOpen());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsCartridgeRemoved(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCartridgeRemoved());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsCartridgeEmpty(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCartridgeEmpty());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsHeadCleaning(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsHeadCleaning());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsPaperEmpty(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsPaperEmpty());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsReadyToPrint(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsReadyToPrint());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ValidateData(impl::abi_arg_in<hstring> data, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ValidateData(*reinterpret_cast<const hstring *>(&data)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities> : produce_base<D, Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>
{
    HRESULT __stdcall get_IsPrinterPresent(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsPrinterPresent());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDualColorSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDualColorSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ColorCartridgeCapabilities(Windows::Devices::PointOfService::PosPrinterColorCapabilities * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ColorCartridgeCapabilities());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CartridgeSensors(Windows::Devices::PointOfService::PosPrinterCartridgeSensors * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CartridgeSensors());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsBoldSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsBoldSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsItalicSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsItalicSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsUnderlineSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsUnderlineSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDoubleHighPrintSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDoubleHighPrintSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDoubleWidePrintSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDoubleWidePrintSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDoubleHighDoubleWidePrintSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDoubleHighDoubleWidePrintSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsPaperEmptySensorSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsPaperEmptySensorSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsPaperNearEndSensorSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsPaperNearEndSensorSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedCharactersPerLine(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedCharactersPerLine());
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
struct produce<D, Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities> : produce_base<D, Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>
{
    HRESULT __stdcall get_IsBarcodeSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsBarcodeSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsBitmapSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsBitmapSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsLeft90RotationSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsLeft90RotationSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsRight90RotationSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsRight90RotationSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Is180RotationSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Is180RotationSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsPrintAreaSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsPrintAreaSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RuledLineCapabilities(Windows::Devices::PointOfService::PosPrinterRuledLineCapabilities * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RuledLineCapabilities());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedBarcodeRotations(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::PointOfService::PosPrinterRotation>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedBarcodeRotations());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedBitmapRotations(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::PointOfService::PosPrinterRotation>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedBitmapRotations());
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
struct produce<D, Windows::Devices::PointOfService::IJournalPrinterCapabilities> : produce_base<D, Windows::Devices::PointOfService::IJournalPrinterCapabilities>
{};

template <typename D>
struct produce<D, Windows::Devices::PointOfService::IMagneticStripeReader> : produce_base<D, Windows::Devices::PointOfService::IMagneticStripeReader>
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

    HRESULT __stdcall get_Capabilities(impl::abi_arg_out<Windows::Devices::PointOfService::IMagneticStripeReaderCapabilities> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Capabilities());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedCardTypes(uint32_t * __valueSize, impl::abi_arg_out<uint32_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            std::tie(*__valueSize, *value) = detach_abi(this->shim().SupportedCardTypes());
            return S_OK;
        }
        catch (...)
        {
            *__valueSize = 0;
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceAuthenticationProtocol(Windows::Devices::PointOfService::MagneticStripeReaderAuthenticationProtocol * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceAuthenticationProtocol());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CheckHealthAsync(Windows::Devices::PointOfService::UnifiedPosHealthCheckLevel level, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CheckHealthAsync(level));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClaimReaderAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::ClaimedMagneticStripeReader>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ClaimReaderAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RetrieveStatisticsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> statisticsCategories, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RetrieveStatisticsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&statisticsCategories)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetErrorReportingType(Windows::Devices::PointOfService::MagneticStripeReaderErrorReportingType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetErrorReportingType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_StatusUpdated(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::MagneticStripeReader, Windows::Devices::PointOfService::MagneticStripeReaderStatusUpdatedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().StatusUpdated(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::MagneticStripeReader, Windows::Devices::PointOfService::MagneticStripeReaderStatusUpdatedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_StatusUpdated(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StatusUpdated(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::PointOfService::IMagneticStripeReaderAamvaCardDataReceivedEventArgs> : produce_base<D, Windows::Devices::PointOfService::IMagneticStripeReaderAamvaCardDataReceivedEventArgs>
{
    HRESULT __stdcall get_Report(impl::abi_arg_out<Windows::Devices::PointOfService::IMagneticStripeReaderReport> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Report());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LicenseNumber(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LicenseNumber());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExpirationDate(impl::abi_arg_out<hstring> value) noexcept override
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

    HRESULT __stdcall get_Restrictions(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Restrictions());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Class(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Class());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Endorsements(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Endorsements());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BirthDate(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BirthDate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FirstName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FirstName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Surname(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Surname());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Suffix(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Suffix());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Gender(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Gender());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HairColor(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HairColor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EyeColor(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EyeColor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Height(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Height());
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

    HRESULT __stdcall get_Address(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Address());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_City(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().City());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_State(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().State());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PostalCode(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PostalCode());
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
struct produce<D, Windows::Devices::PointOfService::IMagneticStripeReaderBankCardDataReceivedEventArgs> : produce_base<D, Windows::Devices::PointOfService::IMagneticStripeReaderBankCardDataReceivedEventArgs>
{
    HRESULT __stdcall get_Report(impl::abi_arg_out<Windows::Devices::PointOfService::IMagneticStripeReaderReport> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Report());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AccountNumber(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AccountNumber());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExpirationDate(impl::abi_arg_out<hstring> value) noexcept override
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

    HRESULT __stdcall get_ServiceCode(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceCode());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall get_FirstName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FirstName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MiddleInitial(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MiddleInitial());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Surname(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Surname());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Suffix(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Suffix());
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
struct produce<D, Windows::Devices::PointOfService::IMagneticStripeReaderCapabilities> : produce_base<D, Windows::Devices::PointOfService::IMagneticStripeReaderCapabilities>
{
    HRESULT __stdcall get_CardAuthentication(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CardAuthentication());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedEncryptionAlgorithms(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedEncryptionAlgorithms());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AuthenticationLevel(Windows::Devices::PointOfService::MagneticStripeReaderAuthenticationLevel * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AuthenticationLevel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsIsoSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsIsoSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsJisOneSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsJisOneSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsJisTwoSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsJisTwoSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PowerReportingType(Windows::Devices::PointOfService::UnifiedPosPowerReportingType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PowerReportingType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsStatisticsReportingSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsStatisticsReportingSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsStatisticsUpdatingSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsStatisticsUpdatingSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsTrackDataMaskingSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsTrackDataMaskingSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsTransmitSentinelsSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsTransmitSentinelsSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::PointOfService::IMagneticStripeReaderCardTypesStatics> : produce_base<D, Windows::Devices::PointOfService::IMagneticStripeReaderCardTypesStatics>
{
    HRESULT __stdcall get_Unknown(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Unknown());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Bank(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Bank());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Aamva(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Aamva());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExtendedBase(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedBase());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::PointOfService::IMagneticStripeReaderEncryptionAlgorithmsStatics> : produce_base<D, Windows::Devices::PointOfService::IMagneticStripeReaderEncryptionAlgorithmsStatics>
{
    HRESULT __stdcall get_None(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().None());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TripleDesDukpt(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TripleDesDukpt());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExtendedBase(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedBase());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::PointOfService::IMagneticStripeReaderErrorOccurredEventArgs> : produce_base<D, Windows::Devices::PointOfService::IMagneticStripeReaderErrorOccurredEventArgs>
{
    HRESULT __stdcall get_Track1Status(Windows::Devices::PointOfService::MagneticStripeReaderTrackErrorType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Track1Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Track2Status(Windows::Devices::PointOfService::MagneticStripeReaderTrackErrorType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Track2Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Track3Status(Windows::Devices::PointOfService::MagneticStripeReaderTrackErrorType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Track3Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Track4Status(Windows::Devices::PointOfService::MagneticStripeReaderTrackErrorType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Track4Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ErrorData(impl::abi_arg_out<Windows::Devices::PointOfService::IUnifiedPosErrorData> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ErrorData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PartialInputData(impl::abi_arg_out<Windows::Devices::PointOfService::IMagneticStripeReaderReport> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PartialInputData());
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
struct produce<D, Windows::Devices::PointOfService::IMagneticStripeReaderReport> : produce_base<D, Windows::Devices::PointOfService::IMagneticStripeReaderReport>
{
    HRESULT __stdcall get_CardType(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CardType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Track1(impl::abi_arg_out<Windows::Devices::PointOfService::IMagneticStripeReaderTrackData> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Track1());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Track2(impl::abi_arg_out<Windows::Devices::PointOfService::IMagneticStripeReaderTrackData> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Track2());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Track3(impl::abi_arg_out<Windows::Devices::PointOfService::IMagneticStripeReaderTrackData> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Track3());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Track4(impl::abi_arg_out<Windows::Devices::PointOfService::IMagneticStripeReaderTrackData> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Track4());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, hstring>> value) noexcept override
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

    HRESULT __stdcall get_CardAuthenticationData(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CardAuthenticationData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CardAuthenticationDataLength(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CardAuthenticationDataLength());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AdditionalSecurityInformation(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AdditionalSecurityInformation());
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
struct produce<D, Windows::Devices::PointOfService::IMagneticStripeReaderStatics> : produce_base<D, Windows::Devices::PointOfService::IMagneticStripeReaderStatics>
{
    HRESULT __stdcall abi_GetDefaultAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::MagneticStripeReader>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDefaultAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::MagneticStripeReader>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FromIdAsync(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelector(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeviceSelector());
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
struct produce<D, Windows::Devices::PointOfService::IMagneticStripeReaderStatusUpdatedEventArgs> : produce_base<D, Windows::Devices::PointOfService::IMagneticStripeReaderStatusUpdatedEventArgs>
{
    HRESULT __stdcall get_Status(Windows::Devices::PointOfService::MagneticStripeReaderStatus * value) noexcept override
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

    HRESULT __stdcall get_ExtendedStatus(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::PointOfService::IMagneticStripeReaderTrackData> : produce_base<D, Windows::Devices::PointOfService::IMagneticStripeReaderTrackData>
{
    HRESULT __stdcall get_Data(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Data());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DiscretionaryData(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DiscretionaryData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EncryptedData(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EncryptedData());
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
struct produce<D, Windows::Devices::PointOfService::IMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs> : produce_base<D, Windows::Devices::PointOfService::IMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs>
{
    HRESULT __stdcall get_Report(impl::abi_arg_out<Windows::Devices::PointOfService::IMagneticStripeReaderReport> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Report());
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
struct produce<D, Windows::Devices::PointOfService::IPosPrinter> : produce_base<D, Windows::Devices::PointOfService::IPosPrinter>
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

    HRESULT __stdcall get_Capabilities(impl::abi_arg_out<Windows::Devices::PointOfService::IPosPrinterCapabilities> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Capabilities());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedCharacterSets(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedCharacterSets());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedTypeFaces(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedTypeFaces());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(impl::abi_arg_out<Windows::Devices::PointOfService::IPosPrinterStatus> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClaimPrinterAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::ClaimedPosPrinter>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ClaimPrinterAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CheckHealthAsync(Windows::Devices::PointOfService::UnifiedPosHealthCheckLevel level, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CheckHealthAsync(level));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStatisticsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> statisticsCategories, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetStatisticsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&statisticsCategories)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_StatusUpdated(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::PosPrinter, Windows::Devices::PointOfService::PosPrinterStatusUpdatedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().StatusUpdated(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::PosPrinter, Windows::Devices::PointOfService::PosPrinterStatusUpdatedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_StatusUpdated(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StatusUpdated(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::PointOfService::IPosPrinterCapabilities> : produce_base<D, Windows::Devices::PointOfService::IPosPrinterCapabilities>
{
    HRESULT __stdcall get_PowerReportingType(Windows::Devices::PointOfService::UnifiedPosPowerReportingType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PowerReportingType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsStatisticsReportingSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsStatisticsReportingSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsStatisticsUpdatingSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsStatisticsUpdatingSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DefaultCharacterSet(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DefaultCharacterSet());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HasCoverSensor(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasCoverSensor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanMapCharacterSet(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanMapCharacterSet());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsTransactionSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsTransactionSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Receipt(impl::abi_arg_out<Windows::Devices::PointOfService::IReceiptPrinterCapabilities> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Receipt());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Slip(impl::abi_arg_out<Windows::Devices::PointOfService::ISlipPrinterCapabilities> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Slip());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Journal(impl::abi_arg_out<Windows::Devices::PointOfService::IJournalPrinterCapabilities> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Journal());
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
struct produce<D, Windows::Devices::PointOfService::IPosPrinterCharacterSetIdsStatics> : produce_base<D, Windows::Devices::PointOfService::IPosPrinterCharacterSetIdsStatics>
{
    HRESULT __stdcall get_Utf16LE(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Utf16LE());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Ascii(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Ascii());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Ansi(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Ansi());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::PointOfService::IPosPrinterJob> : produce_base<D, Windows::Devices::PointOfService::IPosPrinterJob>
{
    HRESULT __stdcall abi_Print(impl::abi_arg_in<hstring> data) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Print(*reinterpret_cast<const hstring *>(&data));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PrintLine(impl::abi_arg_in<hstring> data) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PrintLine(*reinterpret_cast<const hstring *>(&data));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PrintNewline() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PrintLine();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ExecuteAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ExecuteAsync());
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
struct produce<D, Windows::Devices::PointOfService::IPosPrinterReleaseDeviceRequestedEventArgs> : produce_base<D, Windows::Devices::PointOfService::IPosPrinterReleaseDeviceRequestedEventArgs>
{};

template <typename D>
struct produce<D, Windows::Devices::PointOfService::IPosPrinterStatics> : produce_base<D, Windows::Devices::PointOfService::IPosPrinterStatics>
{
    HRESULT __stdcall abi_GetDefaultAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::PosPrinter>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDefaultAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::PosPrinter>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FromIdAsync(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelector(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeviceSelector());
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
struct produce<D, Windows::Devices::PointOfService::IPosPrinterStatus> : produce_base<D, Windows::Devices::PointOfService::IPosPrinterStatus>
{
    HRESULT __stdcall get_StatusKind(Windows::Devices::PointOfService::PosPrinterStatusKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StatusKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExtendedStatus(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::PointOfService::IPosPrinterStatusUpdatedEventArgs> : produce_base<D, Windows::Devices::PointOfService::IPosPrinterStatusUpdatedEventArgs>
{
    HRESULT __stdcall get_Status(impl::abi_arg_out<Windows::Devices::PointOfService::IPosPrinterStatus> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
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
struct produce<D, Windows::Devices::PointOfService::IReceiptOrSlipJob> : produce_base<D, Windows::Devices::PointOfService::IReceiptOrSlipJob>
{
    HRESULT __stdcall abi_SetBarcodeRotation(Windows::Devices::PointOfService::PosPrinterRotation value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetBarcodeRotation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPrintRotation(Windows::Devices::PointOfService::PosPrinterRotation value, bool includeBitmaps) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPrintRotation(value, includeBitmaps);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPrintArea(impl::abi_arg_in<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPrintArea(*reinterpret_cast<const Windows::Foundation::Rect *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetBitmap(uint32_t bitmapNumber, impl::abi_arg_in<Windows::Graphics::Imaging::IBitmapFrame> bitmap, Windows::Devices::PointOfService::PosPrinterAlignment alignment) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetBitmap(bitmapNumber, *reinterpret_cast<const Windows::Graphics::Imaging::BitmapFrame *>(&bitmap), alignment);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetBitmapCustomWidthStandardAlign(uint32_t bitmapNumber, impl::abi_arg_in<Windows::Graphics::Imaging::IBitmapFrame> bitmap, Windows::Devices::PointOfService::PosPrinterAlignment alignment, uint32_t width) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetBitmap(bitmapNumber, *reinterpret_cast<const Windows::Graphics::Imaging::BitmapFrame *>(&bitmap), alignment, width);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetCustomAlignedBitmap(uint32_t bitmapNumber, impl::abi_arg_in<Windows::Graphics::Imaging::IBitmapFrame> bitmap, uint32_t alignmentDistance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetCustomAlignedBitmap(bitmapNumber, *reinterpret_cast<const Windows::Graphics::Imaging::BitmapFrame *>(&bitmap), alignmentDistance);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetBitmapCustomWidthCustomAlign(uint32_t bitmapNumber, impl::abi_arg_in<Windows::Graphics::Imaging::IBitmapFrame> bitmap, uint32_t alignmentDistance, uint32_t width) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetCustomAlignedBitmap(bitmapNumber, *reinterpret_cast<const Windows::Graphics::Imaging::BitmapFrame *>(&bitmap), alignmentDistance, width);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PrintSavedBitmap(uint32_t bitmapNumber) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PrintSavedBitmap(bitmapNumber);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DrawRuledLine(impl::abi_arg_in<hstring> positionList, Windows::Devices::PointOfService::PosPrinterLineDirection lineDirection, uint32_t lineWidth, Windows::Devices::PointOfService::PosPrinterLineStyle lineStyle, uint32_t lineColor) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DrawRuledLine(*reinterpret_cast<const hstring *>(&positionList), lineDirection, lineWidth, lineStyle, lineColor);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PrintBarcode(impl::abi_arg_in<hstring> data, uint32_t symbology, uint32_t height, uint32_t width, Windows::Devices::PointOfService::PosPrinterBarcodeTextPosition textPosition, Windows::Devices::PointOfService::PosPrinterAlignment alignment) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PrintBarcode(*reinterpret_cast<const hstring *>(&data), symbology, height, width, textPosition, alignment);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PrintBarcodeCustomAlign(impl::abi_arg_in<hstring> data, uint32_t symbology, uint32_t height, uint32_t width, Windows::Devices::PointOfService::PosPrinterBarcodeTextPosition textPosition, uint32_t alignmentDistance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PrintBarcodeCustomAlign(*reinterpret_cast<const hstring *>(&data), symbology, height, width, textPosition, alignmentDistance);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PrintBitmap(impl::abi_arg_in<Windows::Graphics::Imaging::IBitmapFrame> bitmap, Windows::Devices::PointOfService::PosPrinterAlignment alignment) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PrintBitmap(*reinterpret_cast<const Windows::Graphics::Imaging::BitmapFrame *>(&bitmap), alignment);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PrintBitmapCustomWidthStandardAlign(impl::abi_arg_in<Windows::Graphics::Imaging::IBitmapFrame> bitmap, Windows::Devices::PointOfService::PosPrinterAlignment alignment, uint32_t width) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PrintBitmap(*reinterpret_cast<const Windows::Graphics::Imaging::BitmapFrame *>(&bitmap), alignment, width);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PrintCustomAlignedBitmap(impl::abi_arg_in<Windows::Graphics::Imaging::IBitmapFrame> bitmap, uint32_t alignmentDistance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PrintCustomAlignedBitmap(*reinterpret_cast<const Windows::Graphics::Imaging::BitmapFrame *>(&bitmap), alignmentDistance);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PrintBitmapCustomWidthCustomAlign(impl::abi_arg_in<Windows::Graphics::Imaging::IBitmapFrame> bitmap, uint32_t alignmentDistance, uint32_t width) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PrintCustomAlignedBitmap(*reinterpret_cast<const Windows::Graphics::Imaging::BitmapFrame *>(&bitmap), alignmentDistance, width);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::PointOfService::IReceiptPrintJob> : produce_base<D, Windows::Devices::PointOfService::IReceiptPrintJob>
{
    HRESULT __stdcall abi_MarkFeed(Windows::Devices::PointOfService::PosPrinterMarkFeedKind kind) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MarkFeed(kind);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CutPaper(double percentage) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CutPaper(percentage);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CutPaperDefault() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CutPaper();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::PointOfService::IReceiptPrinterCapabilities> : produce_base<D, Windows::Devices::PointOfService::IReceiptPrinterCapabilities>
{
    HRESULT __stdcall get_CanCutPaper(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanCutPaper());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsStampSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsStampSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MarkFeedCapabilities(Windows::Devices::PointOfService::PosPrinterMarkFeedCapabilities * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MarkFeedCapabilities());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::PointOfService::ISlipPrinterCapabilities> : produce_base<D, Windows::Devices::PointOfService::ISlipPrinterCapabilities>
{
    HRESULT __stdcall get_IsFullLengthSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsFullLengthSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsBothSidesPrintingSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsBothSidesPrintingSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::PointOfService::IUnifiedPosErrorData> : produce_base<D, Windows::Devices::PointOfService::IUnifiedPosErrorData>
{
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

    HRESULT __stdcall get_Severity(Windows::Devices::PointOfService::UnifiedPosErrorSeverity * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Severity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Reason(Windows::Devices::PointOfService::UnifiedPosErrorReason * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Reason());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExtendedReason(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedReason());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Devices::PointOfService {

template <typename D> hstring impl_IUnifiedPosErrorData<D>::Message() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUnifiedPosErrorData)->get_Message(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::PointOfService::UnifiedPosErrorSeverity impl_IUnifiedPosErrorData<D>::Severity() const
{
    Windows::Devices::PointOfService::UnifiedPosErrorSeverity value {};
    check_hresult(WINRT_SHIM(IUnifiedPosErrorData)->get_Severity(&value));
    return value;
}

template <typename D> Windows::Devices::PointOfService::UnifiedPosErrorReason impl_IUnifiedPosErrorData<D>::Reason() const
{
    Windows::Devices::PointOfService::UnifiedPosErrorReason value {};
    check_hresult(WINRT_SHIM(IUnifiedPosErrorData)->get_Reason(&value));
    return value;
}

template <typename D> uint32_t impl_IUnifiedPosErrorData<D>::ExtendedReason() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IUnifiedPosErrorData)->get_ExtendedReason(&value));
    return value;
}

template <typename D> Windows::Devices::PointOfService::BarcodeScannerStatus impl_IBarcodeScannerStatusUpdatedEventArgs<D>::Status() const
{
    Windows::Devices::PointOfService::BarcodeScannerStatus value {};
    check_hresult(WINRT_SHIM(IBarcodeScannerStatusUpdatedEventArgs)->get_Status(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeScannerStatusUpdatedEventArgs<D>::ExtendedStatus() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeScannerStatusUpdatedEventArgs)->get_ExtendedStatus(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Unknown() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Unknown(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Ean8() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Ean8(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Ean8Add2() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Ean8Add2(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Ean8Add5() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Ean8Add5(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Eanv() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Eanv(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::EanvAdd2() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_EanvAdd2(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::EanvAdd5() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_EanvAdd5(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Ean13() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Ean13(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Ean13Add2() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Ean13Add2(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Ean13Add5() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Ean13Add5(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Isbn() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Isbn(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::IsbnAdd5() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_IsbnAdd5(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Ismn() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Ismn(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::IsmnAdd2() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_IsmnAdd2(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::IsmnAdd5() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_IsmnAdd5(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Issn() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Issn(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::IssnAdd2() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_IssnAdd2(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::IssnAdd5() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_IssnAdd5(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Ean99() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Ean99(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Ean99Add2() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Ean99Add2(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Ean99Add5() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Ean99Add5(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Upca() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Upca(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::UpcaAdd2() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_UpcaAdd2(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::UpcaAdd5() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_UpcaAdd5(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Upce() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Upce(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::UpceAdd2() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_UpceAdd2(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::UpceAdd5() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_UpceAdd5(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::UpcCoupon() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_UpcCoupon(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::TfStd() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_TfStd(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::TfDis() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_TfDis(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::TfInt() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_TfInt(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::TfInd() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_TfInd(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::TfMat() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_TfMat(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::TfIata() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_TfIata(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Gs1DatabarType1() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Gs1DatabarType1(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Gs1DatabarType2() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Gs1DatabarType2(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Gs1DatabarType3() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Gs1DatabarType3(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Code39() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Code39(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Code39Ex() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Code39Ex(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Trioptic39() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Trioptic39(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Code32() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Code32(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Pzn() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Pzn(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Code93() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Code93(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Code93Ex() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Code93Ex(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Code128() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Code128(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Gs1128() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Gs1128(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Gs1128Coupon() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Gs1128Coupon(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::UccEan128() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_UccEan128(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Sisac() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Sisac(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Isbt() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Isbt(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Codabar() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Codabar(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Code11() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Code11(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Msi() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Msi(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Plessey() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Plessey(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Telepen() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Telepen(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Code16k() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Code16k(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::CodablockA() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_CodablockA(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::CodablockF() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_CodablockF(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Codablock128() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Codablock128(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Code49() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Code49(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Aztec() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Aztec(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::DataCode() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_DataCode(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::DataMatrix() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_DataMatrix(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::HanXin() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_HanXin(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Maxicode() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Maxicode(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::MicroPdf417() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_MicroPdf417(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::MicroQr() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_MicroQr(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Pdf417() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Pdf417(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Qr() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Qr(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::MsTag() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_MsTag(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Ccab() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Ccab(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Ccc() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Ccc(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Tlc39() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Tlc39(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::AusPost() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_AusPost(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::CanPost() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_CanPost(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::ChinaPost() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_ChinaPost(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::DutchKix() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_DutchKix(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::InfoMail() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_InfoMail(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::ItalianPost25() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_ItalianPost25(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::ItalianPost39() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_ItalianPost39(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::JapanPost() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_JapanPost(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::KoreanPost() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_KoreanPost(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::SwedenPost() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_SwedenPost(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::UkPost() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_UkPost(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::UsIntelligent() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_UsIntelligent(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::UsIntelligentPkg() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_UsIntelligentPkg(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::UsPlanet() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_UsPlanet(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::UsPostNet() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_UsPostNet(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Us4StateFics() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Us4StateFics(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::OcrA() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_OcrA(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::OcrB() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_OcrB(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::Micr() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_Micr(&value));
    return value;
}

template <typename D> uint32_t impl_IBarcodeSymbologiesStatics<D>::ExtendedBase() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->get_ExtendedBase(&value));
    return value;
}

template <typename D> hstring impl_IBarcodeSymbologiesStatics<D>::GetName(uint32_t scanDataType) const
{
    hstring value;
    check_hresult(WINRT_SHIM(IBarcodeSymbologiesStatics)->abi_GetName(scanDataType, put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::PointOfService::BarcodeScannerReport impl_IBarcodeScannerDataReceivedEventArgs<D>::Report() const
{
    Windows::Devices::PointOfService::BarcodeScannerReport value { nullptr };
    check_hresult(WINRT_SHIM(IBarcodeScannerDataReceivedEventArgs)->get_Report(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IBarcodeScannerReport<D>::ScanDataType() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBarcodeScannerReport)->get_ScanDataType(&value));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IBarcodeScannerReport<D>::ScanData() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IBarcodeScannerReport)->get_ScanData(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IBarcodeScannerReport<D>::ScanDataLabel() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IBarcodeScannerReport)->get_ScanDataLabel(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::PointOfService::BarcodeScannerReport impl_IBarcodeScannerErrorOccurredEventArgs<D>::PartialInputData() const
{
    Windows::Devices::PointOfService::BarcodeScannerReport value { nullptr };
    check_hresult(WINRT_SHIM(IBarcodeScannerErrorOccurredEventArgs)->get_PartialInputData(put_abi(value)));
    return value;
}

template <typename D> bool impl_IBarcodeScannerErrorOccurredEventArgs<D>::IsRetriable() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IBarcodeScannerErrorOccurredEventArgs)->get_IsRetriable(&value));
    return value;
}

template <typename D> Windows::Devices::PointOfService::UnifiedPosErrorData impl_IBarcodeScannerErrorOccurredEventArgs<D>::ErrorData() const
{
    Windows::Devices::PointOfService::UnifiedPosErrorData value { nullptr };
    check_hresult(WINRT_SHIM(IBarcodeScannerErrorOccurredEventArgs)->get_ErrorData(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamWithContentType impl_IBarcodeScannerImagePreviewReceivedEventArgs<D>::Preview() const
{
    Windows::Storage::Streams::IRandomAccessStreamWithContentType preview;
    check_hresult(WINRT_SHIM(IBarcodeScannerImagePreviewReceivedEventArgs)->get_Preview(put_abi(preview)));
    return preview;
}

template <typename D> Windows::Devices::PointOfService::UnifiedPosPowerReportingType impl_IBarcodeScannerCapabilities<D>::PowerReportingType() const
{
    Windows::Devices::PointOfService::UnifiedPosPowerReportingType value {};
    check_hresult(WINRT_SHIM(IBarcodeScannerCapabilities)->get_PowerReportingType(&value));
    return value;
}

template <typename D> bool impl_IBarcodeScannerCapabilities<D>::IsStatisticsReportingSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IBarcodeScannerCapabilities)->get_IsStatisticsReportingSupported(&value));
    return value;
}

template <typename D> bool impl_IBarcodeScannerCapabilities<D>::IsStatisticsUpdatingSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IBarcodeScannerCapabilities)->get_IsStatisticsUpdatingSupported(&value));
    return value;
}

template <typename D> bool impl_IBarcodeScannerCapabilities<D>::IsImagePreviewSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IBarcodeScannerCapabilities)->get_IsImagePreviewSupported(&value));
    return value;
}

template <typename D> bool impl_IBarcodeScannerCapabilities1<D>::IsSoftwareTriggerSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IBarcodeScannerCapabilities1)->get_IsSoftwareTriggerSupported(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::BarcodeScanner> impl_IBarcodeScannerStatics<D>::GetDefaultAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::BarcodeScanner> result;
    check_hresult(WINRT_SHIM(IBarcodeScannerStatics)->abi_GetDefaultAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::BarcodeScanner> impl_IBarcodeScannerStatics<D>::FromIdAsync(hstring_view deviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::BarcodeScanner> result;
    check_hresult(WINRT_SHIM(IBarcodeScannerStatics)->abi_FromIdAsync(get_abi(deviceId), put_abi(result)));
    return result;
}

template <typename D> hstring impl_IBarcodeScannerStatics<D>::GetDeviceSelector() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IBarcodeScannerStatics)->abi_GetDeviceSelector(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IBarcodeScanner<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IBarcodeScanner)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::PointOfService::BarcodeScannerCapabilities impl_IBarcodeScanner<D>::Capabilities() const
{
    Windows::Devices::PointOfService::BarcodeScannerCapabilities value { nullptr };
    check_hresult(WINRT_SHIM(IBarcodeScanner)->get_Capabilities(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::ClaimedBarcodeScanner> impl_IBarcodeScanner<D>::ClaimScannerAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::ClaimedBarcodeScanner> operation;
    check_hresult(WINRT_SHIM(IBarcodeScanner)->abi_ClaimScannerAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IBarcodeScanner<D>::CheckHealthAsync(Windows::Devices::PointOfService::UnifiedPosHealthCheckLevel level) const
{
    Windows::Foundation::IAsyncOperation<hstring> operation;
    check_hresult(WINRT_SHIM(IBarcodeScanner)->abi_CheckHealthAsync(level, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<uint32_t>> impl_IBarcodeScanner<D>::GetSupportedSymbologiesAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<uint32_t>> operation;
    check_hresult(WINRT_SHIM(IBarcodeScanner)->abi_GetSupportedSymbologiesAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IBarcodeScanner<D>::IsSymbologySupportedAsync(uint32_t barcodeSymbology) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IBarcodeScanner)->abi_IsSymbologySupportedAsync(barcodeSymbology, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> impl_IBarcodeScanner<D>::RetrieveStatisticsAsync(iterable<hstring> statisticsCategories) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> operation;
    check_hresult(WINRT_SHIM(IBarcodeScanner)->abi_RetrieveStatisticsAsync(get_abi(statisticsCategories), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IBarcodeScanner<D>::GetSupportedProfiles() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IBarcodeScanner)->abi_GetSupportedProfiles(put_abi(value)));
    return value;
}

template <typename D> bool impl_IBarcodeScanner<D>::IsProfileSupported(hstring_view profile) const
{
    bool isSupported {};
    check_hresult(WINRT_SHIM(IBarcodeScanner)->abi_IsProfileSupported(get_abi(profile), &isSupported));
    return isSupported;
}

template <typename D> event_token impl_IBarcodeScanner<D>::StatusUpdated(const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::BarcodeScanner, Windows::Devices::PointOfService::BarcodeScannerStatusUpdatedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IBarcodeScanner)->add_StatusUpdated(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IBarcodeScanner> impl_IBarcodeScanner<D>::StatusUpdated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::BarcodeScanner, Windows::Devices::PointOfService::BarcodeScannerStatusUpdatedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IBarcodeScanner>(this, &ABI::Windows::Devices::PointOfService::IBarcodeScanner::remove_StatusUpdated, StatusUpdated(handler));
}

template <typename D> void impl_IBarcodeScanner<D>::StatusUpdated(event_token token) const
{
    check_hresult(WINRT_SHIM(IBarcodeScanner)->remove_StatusUpdated(token));
}

template <typename D> hstring impl_IBarcodeScanner2<D>::VideoDeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IBarcodeScanner2)->get_VideoDeviceId(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IMagneticStripeReaderEncryptionAlgorithmsStatics<D>::None() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMagneticStripeReaderEncryptionAlgorithmsStatics)->get_None(&value));
    return value;
}

template <typename D> uint32_t impl_IMagneticStripeReaderEncryptionAlgorithmsStatics<D>::TripleDesDukpt() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMagneticStripeReaderEncryptionAlgorithmsStatics)->get_TripleDesDukpt(&value));
    return value;
}

template <typename D> uint32_t impl_IMagneticStripeReaderEncryptionAlgorithmsStatics<D>::ExtendedBase() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMagneticStripeReaderEncryptionAlgorithmsStatics)->get_ExtendedBase(&value));
    return value;
}

template <typename D> uint32_t impl_IMagneticStripeReaderCardTypesStatics<D>::Unknown() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMagneticStripeReaderCardTypesStatics)->get_Unknown(&value));
    return value;
}

template <typename D> uint32_t impl_IMagneticStripeReaderCardTypesStatics<D>::Bank() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMagneticStripeReaderCardTypesStatics)->get_Bank(&value));
    return value;
}

template <typename D> uint32_t impl_IMagneticStripeReaderCardTypesStatics<D>::Aamva() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMagneticStripeReaderCardTypesStatics)->get_Aamva(&value));
    return value;
}

template <typename D> uint32_t impl_IMagneticStripeReaderCardTypesStatics<D>::ExtendedBase() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMagneticStripeReaderCardTypesStatics)->get_ExtendedBase(&value));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IMagneticStripeReaderTrackData<D>::Data() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderTrackData)->get_Data(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IMagneticStripeReaderTrackData<D>::DiscretionaryData() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderTrackData)->get_DiscretionaryData(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IMagneticStripeReaderTrackData<D>::EncryptedData() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderTrackData)->get_EncryptedData(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IMagneticStripeReaderReport<D>::CardType() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMagneticStripeReaderReport)->get_CardType(&value));
    return value;
}

template <typename D> Windows::Devices::PointOfService::MagneticStripeReaderTrackData impl_IMagneticStripeReaderReport<D>::Track1() const
{
    Windows::Devices::PointOfService::MagneticStripeReaderTrackData value { nullptr };
    check_hresult(WINRT_SHIM(IMagneticStripeReaderReport)->get_Track1(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::PointOfService::MagneticStripeReaderTrackData impl_IMagneticStripeReaderReport<D>::Track2() const
{
    Windows::Devices::PointOfService::MagneticStripeReaderTrackData value { nullptr };
    check_hresult(WINRT_SHIM(IMagneticStripeReaderReport)->get_Track2(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::PointOfService::MagneticStripeReaderTrackData impl_IMagneticStripeReaderReport<D>::Track3() const
{
    Windows::Devices::PointOfService::MagneticStripeReaderTrackData value { nullptr };
    check_hresult(WINRT_SHIM(IMagneticStripeReaderReport)->get_Track3(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::PointOfService::MagneticStripeReaderTrackData impl_IMagneticStripeReaderReport<D>::Track4() const
{
    Windows::Devices::PointOfService::MagneticStripeReaderTrackData value { nullptr };
    check_hresult(WINRT_SHIM(IMagneticStripeReaderReport)->get_Track4(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, hstring> impl_IMagneticStripeReaderReport<D>::Properties() const
{
    Windows::Foundation::Collections::IMapView<hstring, hstring> value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderReport)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IMagneticStripeReaderReport<D>::CardAuthenticationData() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderReport)->get_CardAuthenticationData(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IMagneticStripeReaderReport<D>::CardAuthenticationDataLength() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMagneticStripeReaderReport)->get_CardAuthenticationDataLength(&value));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IMagneticStripeReaderReport<D>::AdditionalSecurityInformation() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderReport)->get_AdditionalSecurityInformation(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::PointOfService::MagneticStripeReaderReport impl_IMagneticStripeReaderBankCardDataReceivedEventArgs<D>::Report() const
{
    Windows::Devices::PointOfService::MagneticStripeReaderReport value { nullptr };
    check_hresult(WINRT_SHIM(IMagneticStripeReaderBankCardDataReceivedEventArgs)->get_Report(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMagneticStripeReaderBankCardDataReceivedEventArgs<D>::AccountNumber() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderBankCardDataReceivedEventArgs)->get_AccountNumber(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMagneticStripeReaderBankCardDataReceivedEventArgs<D>::ExpirationDate() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderBankCardDataReceivedEventArgs)->get_ExpirationDate(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMagneticStripeReaderBankCardDataReceivedEventArgs<D>::ServiceCode() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderBankCardDataReceivedEventArgs)->get_ServiceCode(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMagneticStripeReaderBankCardDataReceivedEventArgs<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderBankCardDataReceivedEventArgs)->get_Title(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMagneticStripeReaderBankCardDataReceivedEventArgs<D>::FirstName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderBankCardDataReceivedEventArgs)->get_FirstName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMagneticStripeReaderBankCardDataReceivedEventArgs<D>::MiddleInitial() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderBankCardDataReceivedEventArgs)->get_MiddleInitial(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMagneticStripeReaderBankCardDataReceivedEventArgs<D>::Surname() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderBankCardDataReceivedEventArgs)->get_Surname(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMagneticStripeReaderBankCardDataReceivedEventArgs<D>::Suffix() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderBankCardDataReceivedEventArgs)->get_Suffix(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::PointOfService::MagneticStripeReaderReport impl_IMagneticStripeReaderAamvaCardDataReceivedEventArgs<D>::Report() const
{
    Windows::Devices::PointOfService::MagneticStripeReaderReport value { nullptr };
    check_hresult(WINRT_SHIM(IMagneticStripeReaderAamvaCardDataReceivedEventArgs)->get_Report(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMagneticStripeReaderAamvaCardDataReceivedEventArgs<D>::LicenseNumber() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderAamvaCardDataReceivedEventArgs)->get_LicenseNumber(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMagneticStripeReaderAamvaCardDataReceivedEventArgs<D>::ExpirationDate() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderAamvaCardDataReceivedEventArgs)->get_ExpirationDate(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMagneticStripeReaderAamvaCardDataReceivedEventArgs<D>::Restrictions() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderAamvaCardDataReceivedEventArgs)->get_Restrictions(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMagneticStripeReaderAamvaCardDataReceivedEventArgs<D>::Class() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderAamvaCardDataReceivedEventArgs)->get_Class(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMagneticStripeReaderAamvaCardDataReceivedEventArgs<D>::Endorsements() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderAamvaCardDataReceivedEventArgs)->get_Endorsements(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMagneticStripeReaderAamvaCardDataReceivedEventArgs<D>::BirthDate() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderAamvaCardDataReceivedEventArgs)->get_BirthDate(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMagneticStripeReaderAamvaCardDataReceivedEventArgs<D>::FirstName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderAamvaCardDataReceivedEventArgs)->get_FirstName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMagneticStripeReaderAamvaCardDataReceivedEventArgs<D>::Surname() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderAamvaCardDataReceivedEventArgs)->get_Surname(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMagneticStripeReaderAamvaCardDataReceivedEventArgs<D>::Suffix() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderAamvaCardDataReceivedEventArgs)->get_Suffix(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMagneticStripeReaderAamvaCardDataReceivedEventArgs<D>::Gender() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderAamvaCardDataReceivedEventArgs)->get_Gender(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMagneticStripeReaderAamvaCardDataReceivedEventArgs<D>::HairColor() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderAamvaCardDataReceivedEventArgs)->get_HairColor(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMagneticStripeReaderAamvaCardDataReceivedEventArgs<D>::EyeColor() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderAamvaCardDataReceivedEventArgs)->get_EyeColor(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMagneticStripeReaderAamvaCardDataReceivedEventArgs<D>::Height() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderAamvaCardDataReceivedEventArgs)->get_Height(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMagneticStripeReaderAamvaCardDataReceivedEventArgs<D>::Weight() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderAamvaCardDataReceivedEventArgs)->get_Weight(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMagneticStripeReaderAamvaCardDataReceivedEventArgs<D>::Address() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderAamvaCardDataReceivedEventArgs)->get_Address(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMagneticStripeReaderAamvaCardDataReceivedEventArgs<D>::City() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderAamvaCardDataReceivedEventArgs)->get_City(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMagneticStripeReaderAamvaCardDataReceivedEventArgs<D>::State() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderAamvaCardDataReceivedEventArgs)->get_State(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMagneticStripeReaderAamvaCardDataReceivedEventArgs<D>::PostalCode() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderAamvaCardDataReceivedEventArgs)->get_PostalCode(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::PointOfService::MagneticStripeReaderReport impl_IMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs<D>::Report() const
{
    Windows::Devices::PointOfService::MagneticStripeReaderReport value { nullptr };
    check_hresult(WINRT_SHIM(IMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs)->get_Report(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::PointOfService::MagneticStripeReaderTrackErrorType impl_IMagneticStripeReaderErrorOccurredEventArgs<D>::Track1Status() const
{
    Windows::Devices::PointOfService::MagneticStripeReaderTrackErrorType value {};
    check_hresult(WINRT_SHIM(IMagneticStripeReaderErrorOccurredEventArgs)->get_Track1Status(&value));
    return value;
}

template <typename D> Windows::Devices::PointOfService::MagneticStripeReaderTrackErrorType impl_IMagneticStripeReaderErrorOccurredEventArgs<D>::Track2Status() const
{
    Windows::Devices::PointOfService::MagneticStripeReaderTrackErrorType value {};
    check_hresult(WINRT_SHIM(IMagneticStripeReaderErrorOccurredEventArgs)->get_Track2Status(&value));
    return value;
}

template <typename D> Windows::Devices::PointOfService::MagneticStripeReaderTrackErrorType impl_IMagneticStripeReaderErrorOccurredEventArgs<D>::Track3Status() const
{
    Windows::Devices::PointOfService::MagneticStripeReaderTrackErrorType value {};
    check_hresult(WINRT_SHIM(IMagneticStripeReaderErrorOccurredEventArgs)->get_Track3Status(&value));
    return value;
}

template <typename D> Windows::Devices::PointOfService::MagneticStripeReaderTrackErrorType impl_IMagneticStripeReaderErrorOccurredEventArgs<D>::Track4Status() const
{
    Windows::Devices::PointOfService::MagneticStripeReaderTrackErrorType value {};
    check_hresult(WINRT_SHIM(IMagneticStripeReaderErrorOccurredEventArgs)->get_Track4Status(&value));
    return value;
}

template <typename D> Windows::Devices::PointOfService::UnifiedPosErrorData impl_IMagneticStripeReaderErrorOccurredEventArgs<D>::ErrorData() const
{
    Windows::Devices::PointOfService::UnifiedPosErrorData value { nullptr };
    check_hresult(WINRT_SHIM(IMagneticStripeReaderErrorOccurredEventArgs)->get_ErrorData(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::PointOfService::MagneticStripeReaderReport impl_IMagneticStripeReaderErrorOccurredEventArgs<D>::PartialInputData() const
{
    Windows::Devices::PointOfService::MagneticStripeReaderReport value { nullptr };
    check_hresult(WINRT_SHIM(IMagneticStripeReaderErrorOccurredEventArgs)->get_PartialInputData(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::PointOfService::MagneticStripeReaderStatus impl_IMagneticStripeReaderStatusUpdatedEventArgs<D>::Status() const
{
    Windows::Devices::PointOfService::MagneticStripeReaderStatus value {};
    check_hresult(WINRT_SHIM(IMagneticStripeReaderStatusUpdatedEventArgs)->get_Status(&value));
    return value;
}

template <typename D> uint32_t impl_IMagneticStripeReaderStatusUpdatedEventArgs<D>::ExtendedStatus() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMagneticStripeReaderStatusUpdatedEventArgs)->get_ExtendedStatus(&value));
    return value;
}

template <typename D> hstring impl_IMagneticStripeReaderCapabilities<D>::CardAuthentication() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderCapabilities)->get_CardAuthentication(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IMagneticStripeReaderCapabilities<D>::SupportedEncryptionAlgorithms() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMagneticStripeReaderCapabilities)->get_SupportedEncryptionAlgorithms(&value));
    return value;
}

template <typename D> Windows::Devices::PointOfService::MagneticStripeReaderAuthenticationLevel impl_IMagneticStripeReaderCapabilities<D>::AuthenticationLevel() const
{
    Windows::Devices::PointOfService::MagneticStripeReaderAuthenticationLevel value {};
    check_hresult(WINRT_SHIM(IMagneticStripeReaderCapabilities)->get_AuthenticationLevel(&value));
    return value;
}

template <typename D> bool impl_IMagneticStripeReaderCapabilities<D>::IsIsoSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMagneticStripeReaderCapabilities)->get_IsIsoSupported(&value));
    return value;
}

template <typename D> bool impl_IMagneticStripeReaderCapabilities<D>::IsJisOneSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMagneticStripeReaderCapabilities)->get_IsJisOneSupported(&value));
    return value;
}

template <typename D> bool impl_IMagneticStripeReaderCapabilities<D>::IsJisTwoSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMagneticStripeReaderCapabilities)->get_IsJisTwoSupported(&value));
    return value;
}

template <typename D> Windows::Devices::PointOfService::UnifiedPosPowerReportingType impl_IMagneticStripeReaderCapabilities<D>::PowerReportingType() const
{
    Windows::Devices::PointOfService::UnifiedPosPowerReportingType value {};
    check_hresult(WINRT_SHIM(IMagneticStripeReaderCapabilities)->get_PowerReportingType(&value));
    return value;
}

template <typename D> bool impl_IMagneticStripeReaderCapabilities<D>::IsStatisticsReportingSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMagneticStripeReaderCapabilities)->get_IsStatisticsReportingSupported(&value));
    return value;
}

template <typename D> bool impl_IMagneticStripeReaderCapabilities<D>::IsStatisticsUpdatingSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMagneticStripeReaderCapabilities)->get_IsStatisticsUpdatingSupported(&value));
    return value;
}

template <typename D> bool impl_IMagneticStripeReaderCapabilities<D>::IsTrackDataMaskingSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMagneticStripeReaderCapabilities)->get_IsTrackDataMaskingSupported(&value));
    return value;
}

template <typename D> bool impl_IMagneticStripeReaderCapabilities<D>::IsTransmitSentinelsSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMagneticStripeReaderCapabilities)->get_IsTransmitSentinelsSupported(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::MagneticStripeReader> impl_IMagneticStripeReaderStatics<D>::GetDefaultAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::MagneticStripeReader> result;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderStatics)->abi_GetDefaultAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::MagneticStripeReader> impl_IMagneticStripeReaderStatics<D>::FromIdAsync(hstring_view deviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::MagneticStripeReader> result;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderStatics)->abi_FromIdAsync(get_abi(deviceId), put_abi(result)));
    return result;
}

template <typename D> hstring impl_IMagneticStripeReaderStatics<D>::GetDeviceSelector() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagneticStripeReaderStatics)->abi_GetDeviceSelector(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMagneticStripeReader<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMagneticStripeReader)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::PointOfService::MagneticStripeReaderCapabilities impl_IMagneticStripeReader<D>::Capabilities() const
{
    Windows::Devices::PointOfService::MagneticStripeReaderCapabilities value { nullptr };
    check_hresult(WINRT_SHIM(IMagneticStripeReader)->get_Capabilities(put_abi(value)));
    return value;
}

template <typename D> com_array<uint32_t> impl_IMagneticStripeReader<D>::SupportedCardTypes() const
{
    com_array<uint32_t> value {};
    check_hresult(WINRT_SHIM(IMagneticStripeReader)->get_SupportedCardTypes(impl::put_size_abi(value), put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::PointOfService::MagneticStripeReaderAuthenticationProtocol impl_IMagneticStripeReader<D>::DeviceAuthenticationProtocol() const
{
    Windows::Devices::PointOfService::MagneticStripeReaderAuthenticationProtocol value {};
    check_hresult(WINRT_SHIM(IMagneticStripeReader)->get_DeviceAuthenticationProtocol(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IMagneticStripeReader<D>::CheckHealthAsync(Windows::Devices::PointOfService::UnifiedPosHealthCheckLevel level) const
{
    Windows::Foundation::IAsyncOperation<hstring> operation;
    check_hresult(WINRT_SHIM(IMagneticStripeReader)->abi_CheckHealthAsync(level, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::ClaimedMagneticStripeReader> impl_IMagneticStripeReader<D>::ClaimReaderAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::ClaimedMagneticStripeReader> operation;
    check_hresult(WINRT_SHIM(IMagneticStripeReader)->abi_ClaimReaderAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> impl_IMagneticStripeReader<D>::RetrieveStatisticsAsync(iterable<hstring> statisticsCategories) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> operation;
    check_hresult(WINRT_SHIM(IMagneticStripeReader)->abi_RetrieveStatisticsAsync(get_abi(statisticsCategories), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Devices::PointOfService::MagneticStripeReaderErrorReportingType impl_IMagneticStripeReader<D>::GetErrorReportingType() const
{
    Windows::Devices::PointOfService::MagneticStripeReaderErrorReportingType value {};
    check_hresult(WINRT_SHIM(IMagneticStripeReader)->abi_GetErrorReportingType(&value));
    return value;
}

template <typename D> event_token impl_IMagneticStripeReader<D>::StatusUpdated(const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::MagneticStripeReader, Windows::Devices::PointOfService::MagneticStripeReaderStatusUpdatedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMagneticStripeReader)->add_StatusUpdated(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMagneticStripeReader> impl_IMagneticStripeReader<D>::StatusUpdated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::MagneticStripeReader, Windows::Devices::PointOfService::MagneticStripeReaderStatusUpdatedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMagneticStripeReader>(this, &ABI::Windows::Devices::PointOfService::IMagneticStripeReader::remove_StatusUpdated, StatusUpdated(handler));
}

template <typename D> void impl_IMagneticStripeReader<D>::StatusUpdated(event_token token) const
{
    check_hresult(WINRT_SHIM(IMagneticStripeReader)->remove_StatusUpdated(token));
}

template <typename D> uint32_t impl_IPosPrinterCharacterSetIdsStatics<D>::Utf16LE() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IPosPrinterCharacterSetIdsStatics)->get_Utf16LE(&value));
    return value;
}

template <typename D> uint32_t impl_IPosPrinterCharacterSetIdsStatics<D>::Ascii() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IPosPrinterCharacterSetIdsStatics)->get_Ascii(&value));
    return value;
}

template <typename D> uint32_t impl_IPosPrinterCharacterSetIdsStatics<D>::Ansi() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IPosPrinterCharacterSetIdsStatics)->get_Ansi(&value));
    return value;
}

template <typename D> bool impl_ICommonPosPrintStationCapabilities<D>::IsPrinterPresent() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommonPosPrintStationCapabilities)->get_IsPrinterPresent(&value));
    return value;
}

template <typename D> bool impl_ICommonPosPrintStationCapabilities<D>::IsDualColorSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommonPosPrintStationCapabilities)->get_IsDualColorSupported(&value));
    return value;
}

template <typename D> Windows::Devices::PointOfService::PosPrinterColorCapabilities impl_ICommonPosPrintStationCapabilities<D>::ColorCartridgeCapabilities() const
{
    Windows::Devices::PointOfService::PosPrinterColorCapabilities value {};
    check_hresult(WINRT_SHIM(ICommonPosPrintStationCapabilities)->get_ColorCartridgeCapabilities(&value));
    return value;
}

template <typename D> Windows::Devices::PointOfService::PosPrinterCartridgeSensors impl_ICommonPosPrintStationCapabilities<D>::CartridgeSensors() const
{
    Windows::Devices::PointOfService::PosPrinterCartridgeSensors value {};
    check_hresult(WINRT_SHIM(ICommonPosPrintStationCapabilities)->get_CartridgeSensors(&value));
    return value;
}

template <typename D> bool impl_ICommonPosPrintStationCapabilities<D>::IsBoldSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommonPosPrintStationCapabilities)->get_IsBoldSupported(&value));
    return value;
}

template <typename D> bool impl_ICommonPosPrintStationCapabilities<D>::IsItalicSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommonPosPrintStationCapabilities)->get_IsItalicSupported(&value));
    return value;
}

template <typename D> bool impl_ICommonPosPrintStationCapabilities<D>::IsUnderlineSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommonPosPrintStationCapabilities)->get_IsUnderlineSupported(&value));
    return value;
}

template <typename D> bool impl_ICommonPosPrintStationCapabilities<D>::IsDoubleHighPrintSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommonPosPrintStationCapabilities)->get_IsDoubleHighPrintSupported(&value));
    return value;
}

template <typename D> bool impl_ICommonPosPrintStationCapabilities<D>::IsDoubleWidePrintSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommonPosPrintStationCapabilities)->get_IsDoubleWidePrintSupported(&value));
    return value;
}

template <typename D> bool impl_ICommonPosPrintStationCapabilities<D>::IsDoubleHighDoubleWidePrintSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommonPosPrintStationCapabilities)->get_IsDoubleHighDoubleWidePrintSupported(&value));
    return value;
}

template <typename D> bool impl_ICommonPosPrintStationCapabilities<D>::IsPaperEmptySensorSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommonPosPrintStationCapabilities)->get_IsPaperEmptySensorSupported(&value));
    return value;
}

template <typename D> bool impl_ICommonPosPrintStationCapabilities<D>::IsPaperNearEndSensorSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommonPosPrintStationCapabilities)->get_IsPaperNearEndSensorSupported(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<uint32_t> impl_ICommonPosPrintStationCapabilities<D>::SupportedCharactersPerLine() const
{
    Windows::Foundation::Collections::IVectorView<uint32_t> value;
    check_hresult(WINRT_SHIM(ICommonPosPrintStationCapabilities)->get_SupportedCharactersPerLine(put_abi(value)));
    return value;
}

template <typename D> bool impl_ICommonReceiptSlipCapabilities<D>::IsBarcodeSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommonReceiptSlipCapabilities)->get_IsBarcodeSupported(&value));
    return value;
}

template <typename D> bool impl_ICommonReceiptSlipCapabilities<D>::IsBitmapSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommonReceiptSlipCapabilities)->get_IsBitmapSupported(&value));
    return value;
}

template <typename D> bool impl_ICommonReceiptSlipCapabilities<D>::IsLeft90RotationSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommonReceiptSlipCapabilities)->get_IsLeft90RotationSupported(&value));
    return value;
}

template <typename D> bool impl_ICommonReceiptSlipCapabilities<D>::IsRight90RotationSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommonReceiptSlipCapabilities)->get_IsRight90RotationSupported(&value));
    return value;
}

template <typename D> bool impl_ICommonReceiptSlipCapabilities<D>::Is180RotationSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommonReceiptSlipCapabilities)->get_Is180RotationSupported(&value));
    return value;
}

template <typename D> bool impl_ICommonReceiptSlipCapabilities<D>::IsPrintAreaSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommonReceiptSlipCapabilities)->get_IsPrintAreaSupported(&value));
    return value;
}

template <typename D> Windows::Devices::PointOfService::PosPrinterRuledLineCapabilities impl_ICommonReceiptSlipCapabilities<D>::RuledLineCapabilities() const
{
    Windows::Devices::PointOfService::PosPrinterRuledLineCapabilities value {};
    check_hresult(WINRT_SHIM(ICommonReceiptSlipCapabilities)->get_RuledLineCapabilities(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::PointOfService::PosPrinterRotation> impl_ICommonReceiptSlipCapabilities<D>::SupportedBarcodeRotations() const
{
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::PointOfService::PosPrinterRotation> value;
    check_hresult(WINRT_SHIM(ICommonReceiptSlipCapabilities)->get_SupportedBarcodeRotations(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::PointOfService::PosPrinterRotation> impl_ICommonReceiptSlipCapabilities<D>::SupportedBitmapRotations() const
{
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::PointOfService::PosPrinterRotation> value;
    check_hresult(WINRT_SHIM(ICommonReceiptSlipCapabilities)->get_SupportedBitmapRotations(put_abi(value)));
    return value;
}

template <typename D> bool impl_IReceiptPrinterCapabilities<D>::CanCutPaper() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IReceiptPrinterCapabilities)->get_CanCutPaper(&value));
    return value;
}

template <typename D> bool impl_IReceiptPrinterCapabilities<D>::IsStampSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IReceiptPrinterCapabilities)->get_IsStampSupported(&value));
    return value;
}

template <typename D> Windows::Devices::PointOfService::PosPrinterMarkFeedCapabilities impl_IReceiptPrinterCapabilities<D>::MarkFeedCapabilities() const
{
    Windows::Devices::PointOfService::PosPrinterMarkFeedCapabilities value {};
    check_hresult(WINRT_SHIM(IReceiptPrinterCapabilities)->get_MarkFeedCapabilities(&value));
    return value;
}

template <typename D> bool impl_ISlipPrinterCapabilities<D>::IsFullLengthSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISlipPrinterCapabilities)->get_IsFullLengthSupported(&value));
    return value;
}

template <typename D> bool impl_ISlipPrinterCapabilities<D>::IsBothSidesPrintingSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISlipPrinterCapabilities)->get_IsBothSidesPrintingSupported(&value));
    return value;
}

template <typename D> Windows::Devices::PointOfService::UnifiedPosPowerReportingType impl_IPosPrinterCapabilities<D>::PowerReportingType() const
{
    Windows::Devices::PointOfService::UnifiedPosPowerReportingType value {};
    check_hresult(WINRT_SHIM(IPosPrinterCapabilities)->get_PowerReportingType(&value));
    return value;
}

template <typename D> bool impl_IPosPrinterCapabilities<D>::IsStatisticsReportingSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPosPrinterCapabilities)->get_IsStatisticsReportingSupported(&value));
    return value;
}

template <typename D> bool impl_IPosPrinterCapabilities<D>::IsStatisticsUpdatingSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPosPrinterCapabilities)->get_IsStatisticsUpdatingSupported(&value));
    return value;
}

template <typename D> uint32_t impl_IPosPrinterCapabilities<D>::DefaultCharacterSet() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IPosPrinterCapabilities)->get_DefaultCharacterSet(&value));
    return value;
}

template <typename D> bool impl_IPosPrinterCapabilities<D>::HasCoverSensor() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPosPrinterCapabilities)->get_HasCoverSensor(&value));
    return value;
}

template <typename D> bool impl_IPosPrinterCapabilities<D>::CanMapCharacterSet() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPosPrinterCapabilities)->get_CanMapCharacterSet(&value));
    return value;
}

template <typename D> bool impl_IPosPrinterCapabilities<D>::IsTransactionSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPosPrinterCapabilities)->get_IsTransactionSupported(&value));
    return value;
}

template <typename D> Windows::Devices::PointOfService::ReceiptPrinterCapabilities impl_IPosPrinterCapabilities<D>::Receipt() const
{
    Windows::Devices::PointOfService::ReceiptPrinterCapabilities value { nullptr };
    check_hresult(WINRT_SHIM(IPosPrinterCapabilities)->get_Receipt(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::PointOfService::SlipPrinterCapabilities impl_IPosPrinterCapabilities<D>::Slip() const
{
    Windows::Devices::PointOfService::SlipPrinterCapabilities value { nullptr };
    check_hresult(WINRT_SHIM(IPosPrinterCapabilities)->get_Slip(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::PointOfService::JournalPrinterCapabilities impl_IPosPrinterCapabilities<D>::Journal() const
{
    Windows::Devices::PointOfService::JournalPrinterCapabilities value { nullptr };
    check_hresult(WINRT_SHIM(IPosPrinterCapabilities)->get_Journal(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::PointOfService::PosPrinterStatusKind impl_IPosPrinterStatus<D>::StatusKind() const
{
    Windows::Devices::PointOfService::PosPrinterStatusKind value {};
    check_hresult(WINRT_SHIM(IPosPrinterStatus)->get_StatusKind(&value));
    return value;
}

template <typename D> uint32_t impl_IPosPrinterStatus<D>::ExtendedStatus() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IPosPrinterStatus)->get_ExtendedStatus(&value));
    return value;
}

template <typename D> Windows::Devices::PointOfService::PosPrinterStatus impl_IPosPrinterStatusUpdatedEventArgs<D>::Status() const
{
    Windows::Devices::PointOfService::PosPrinterStatus value { nullptr };
    check_hresult(WINRT_SHIM(IPosPrinterStatusUpdatedEventArgs)->get_Status(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::PosPrinter> impl_IPosPrinterStatics<D>::GetDefaultAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::PosPrinter> result;
    check_hresult(WINRT_SHIM(IPosPrinterStatics)->abi_GetDefaultAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::PosPrinter> impl_IPosPrinterStatics<D>::FromIdAsync(hstring_view deviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::PosPrinter> result;
    check_hresult(WINRT_SHIM(IPosPrinterStatics)->abi_FromIdAsync(get_abi(deviceId), put_abi(result)));
    return result;
}

template <typename D> hstring impl_IPosPrinterStatics<D>::GetDeviceSelector() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPosPrinterStatics)->abi_GetDeviceSelector(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPosPrinter<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPosPrinter)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::PointOfService::PosPrinterCapabilities impl_IPosPrinter<D>::Capabilities() const
{
    Windows::Devices::PointOfService::PosPrinterCapabilities value { nullptr };
    check_hresult(WINRT_SHIM(IPosPrinter)->get_Capabilities(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<uint32_t> impl_IPosPrinter<D>::SupportedCharacterSets() const
{
    Windows::Foundation::Collections::IVectorView<uint32_t> value;
    check_hresult(WINRT_SHIM(IPosPrinter)->get_SupportedCharacterSets(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IPosPrinter<D>::SupportedTypeFaces() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IPosPrinter)->get_SupportedTypeFaces(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::PointOfService::PosPrinterStatus impl_IPosPrinter<D>::Status() const
{
    Windows::Devices::PointOfService::PosPrinterStatus value { nullptr };
    check_hresult(WINRT_SHIM(IPosPrinter)->get_Status(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::ClaimedPosPrinter> impl_IPosPrinter<D>::ClaimPrinterAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::ClaimedPosPrinter> operation;
    check_hresult(WINRT_SHIM(IPosPrinter)->abi_ClaimPrinterAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IPosPrinter<D>::CheckHealthAsync(Windows::Devices::PointOfService::UnifiedPosHealthCheckLevel level) const
{
    Windows::Foundation::IAsyncOperation<hstring> operation;
    check_hresult(WINRT_SHIM(IPosPrinter)->abi_CheckHealthAsync(level, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IPosPrinter<D>::GetStatisticsAsync(iterable<hstring> statisticsCategories) const
{
    Windows::Foundation::IAsyncOperation<hstring> operation;
    check_hresult(WINRT_SHIM(IPosPrinter)->abi_GetStatisticsAsync(get_abi(statisticsCategories), put_abi(operation)));
    return operation;
}

template <typename D> event_token impl_IPosPrinter<D>::StatusUpdated(const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::PosPrinter, Windows::Devices::PointOfService::PosPrinterStatusUpdatedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPosPrinter)->add_StatusUpdated(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPosPrinter> impl_IPosPrinter<D>::StatusUpdated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::PosPrinter, Windows::Devices::PointOfService::PosPrinterStatusUpdatedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPosPrinter>(this, &ABI::Windows::Devices::PointOfService::IPosPrinter::remove_StatusUpdated, StatusUpdated(handler));
}

template <typename D> void impl_IPosPrinter<D>::StatusUpdated(event_token token) const
{
    check_hresult(WINRT_SHIM(IPosPrinter)->remove_StatusUpdated(token));
}

template <typename D> void impl_IPosPrinterJob<D>::Print(hstring_view data) const
{
    check_hresult(WINRT_SHIM(IPosPrinterJob)->abi_Print(get_abi(data)));
}

template <typename D> void impl_IPosPrinterJob<D>::PrintLine(hstring_view data) const
{
    check_hresult(WINRT_SHIM(IPosPrinterJob)->abi_PrintLine(get_abi(data)));
}

template <typename D> void impl_IPosPrinterJob<D>::PrintLine() const
{
    check_hresult(WINRT_SHIM(IPosPrinterJob)->abi_PrintNewline());
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IPosPrinterJob<D>::ExecuteAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IPosPrinterJob)->abi_ExecuteAsync(put_abi(operation)));
    return operation;
}

template <typename D> void impl_IReceiptOrSlipJob<D>::SetBarcodeRotation(Windows::Devices::PointOfService::PosPrinterRotation value) const
{
    check_hresult(WINRT_SHIM(IReceiptOrSlipJob)->abi_SetBarcodeRotation(value));
}

template <typename D> void impl_IReceiptOrSlipJob<D>::SetPrintRotation(Windows::Devices::PointOfService::PosPrinterRotation value, bool includeBitmaps) const
{
    check_hresult(WINRT_SHIM(IReceiptOrSlipJob)->abi_SetPrintRotation(value, includeBitmaps));
}

template <typename D> void impl_IReceiptOrSlipJob<D>::SetPrintArea(const Windows::Foundation::Rect & value) const
{
    check_hresult(WINRT_SHIM(IReceiptOrSlipJob)->abi_SetPrintArea(get_abi(value)));
}

template <typename D> void impl_IReceiptOrSlipJob<D>::SetBitmap(uint32_t bitmapNumber, const Windows::Graphics::Imaging::BitmapFrame & bitmap, Windows::Devices::PointOfService::PosPrinterAlignment alignment) const
{
    check_hresult(WINRT_SHIM(IReceiptOrSlipJob)->abi_SetBitmap(bitmapNumber, get_abi(bitmap), alignment));
}

template <typename D> void impl_IReceiptOrSlipJob<D>::SetBitmap(uint32_t bitmapNumber, const Windows::Graphics::Imaging::BitmapFrame & bitmap, Windows::Devices::PointOfService::PosPrinterAlignment alignment, uint32_t width) const
{
    check_hresult(WINRT_SHIM(IReceiptOrSlipJob)->abi_SetBitmapCustomWidthStandardAlign(bitmapNumber, get_abi(bitmap), alignment, width));
}

template <typename D> void impl_IReceiptOrSlipJob<D>::SetCustomAlignedBitmap(uint32_t bitmapNumber, const Windows::Graphics::Imaging::BitmapFrame & bitmap, uint32_t alignmentDistance) const
{
    check_hresult(WINRT_SHIM(IReceiptOrSlipJob)->abi_SetCustomAlignedBitmap(bitmapNumber, get_abi(bitmap), alignmentDistance));
}

template <typename D> void impl_IReceiptOrSlipJob<D>::SetCustomAlignedBitmap(uint32_t bitmapNumber, const Windows::Graphics::Imaging::BitmapFrame & bitmap, uint32_t alignmentDistance, uint32_t width) const
{
    check_hresult(WINRT_SHIM(IReceiptOrSlipJob)->abi_SetBitmapCustomWidthCustomAlign(bitmapNumber, get_abi(bitmap), alignmentDistance, width));
}

template <typename D> void impl_IReceiptOrSlipJob<D>::PrintSavedBitmap(uint32_t bitmapNumber) const
{
    check_hresult(WINRT_SHIM(IReceiptOrSlipJob)->abi_PrintSavedBitmap(bitmapNumber));
}

template <typename D> void impl_IReceiptOrSlipJob<D>::DrawRuledLine(hstring_view positionList, Windows::Devices::PointOfService::PosPrinterLineDirection lineDirection, uint32_t lineWidth, Windows::Devices::PointOfService::PosPrinterLineStyle lineStyle, uint32_t lineColor) const
{
    check_hresult(WINRT_SHIM(IReceiptOrSlipJob)->abi_DrawRuledLine(get_abi(positionList), lineDirection, lineWidth, lineStyle, lineColor));
}

template <typename D> void impl_IReceiptOrSlipJob<D>::PrintBarcode(hstring_view data, uint32_t symbology, uint32_t height, uint32_t width, Windows::Devices::PointOfService::PosPrinterBarcodeTextPosition textPosition, Windows::Devices::PointOfService::PosPrinterAlignment alignment) const
{
    check_hresult(WINRT_SHIM(IReceiptOrSlipJob)->abi_PrintBarcode(get_abi(data), symbology, height, width, textPosition, alignment));
}

template <typename D> void impl_IReceiptOrSlipJob<D>::PrintBarcodeCustomAlign(hstring_view data, uint32_t symbology, uint32_t height, uint32_t width, Windows::Devices::PointOfService::PosPrinterBarcodeTextPosition textPosition, uint32_t alignmentDistance) const
{
    check_hresult(WINRT_SHIM(IReceiptOrSlipJob)->abi_PrintBarcodeCustomAlign(get_abi(data), symbology, height, width, textPosition, alignmentDistance));
}

template <typename D> void impl_IReceiptOrSlipJob<D>::PrintBitmap(const Windows::Graphics::Imaging::BitmapFrame & bitmap, Windows::Devices::PointOfService::PosPrinterAlignment alignment) const
{
    check_hresult(WINRT_SHIM(IReceiptOrSlipJob)->abi_PrintBitmap(get_abi(bitmap), alignment));
}

template <typename D> void impl_IReceiptOrSlipJob<D>::PrintBitmap(const Windows::Graphics::Imaging::BitmapFrame & bitmap, Windows::Devices::PointOfService::PosPrinterAlignment alignment, uint32_t width) const
{
    check_hresult(WINRT_SHIM(IReceiptOrSlipJob)->abi_PrintBitmapCustomWidthStandardAlign(get_abi(bitmap), alignment, width));
}

template <typename D> void impl_IReceiptOrSlipJob<D>::PrintCustomAlignedBitmap(const Windows::Graphics::Imaging::BitmapFrame & bitmap, uint32_t alignmentDistance) const
{
    check_hresult(WINRT_SHIM(IReceiptOrSlipJob)->abi_PrintCustomAlignedBitmap(get_abi(bitmap), alignmentDistance));
}

template <typename D> void impl_IReceiptOrSlipJob<D>::PrintCustomAlignedBitmap(const Windows::Graphics::Imaging::BitmapFrame & bitmap, uint32_t alignmentDistance, uint32_t width) const
{
    check_hresult(WINRT_SHIM(IReceiptOrSlipJob)->abi_PrintBitmapCustomWidthCustomAlign(get_abi(bitmap), alignmentDistance, width));
}

template <typename D> void impl_IReceiptPrintJob<D>::MarkFeed(Windows::Devices::PointOfService::PosPrinterMarkFeedKind kind) const
{
    check_hresult(WINRT_SHIM(IReceiptPrintJob)->abi_MarkFeed(kind));
}

template <typename D> void impl_IReceiptPrintJob<D>::CutPaper(double percentage) const
{
    check_hresult(WINRT_SHIM(IReceiptPrintJob)->abi_CutPaper(percentage));
}

template <typename D> void impl_IReceiptPrintJob<D>::CutPaper() const
{
    check_hresult(WINRT_SHIM(IReceiptPrintJob)->abi_CutPaperDefault());
}

template <typename D> void impl_ICommonClaimedPosPrinterStation<D>::CharactersPerLine(uint32_t value) const
{
    check_hresult(WINRT_SHIM(ICommonClaimedPosPrinterStation)->put_CharactersPerLine(value));
}

template <typename D> uint32_t impl_ICommonClaimedPosPrinterStation<D>::CharactersPerLine() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ICommonClaimedPosPrinterStation)->get_CharactersPerLine(&value));
    return value;
}

template <typename D> void impl_ICommonClaimedPosPrinterStation<D>::LineHeight(uint32_t value) const
{
    check_hresult(WINRT_SHIM(ICommonClaimedPosPrinterStation)->put_LineHeight(value));
}

template <typename D> uint32_t impl_ICommonClaimedPosPrinterStation<D>::LineHeight() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ICommonClaimedPosPrinterStation)->get_LineHeight(&value));
    return value;
}

template <typename D> void impl_ICommonClaimedPosPrinterStation<D>::LineSpacing(uint32_t value) const
{
    check_hresult(WINRT_SHIM(ICommonClaimedPosPrinterStation)->put_LineSpacing(value));
}

template <typename D> uint32_t impl_ICommonClaimedPosPrinterStation<D>::LineSpacing() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ICommonClaimedPosPrinterStation)->get_LineSpacing(&value));
    return value;
}

template <typename D> uint32_t impl_ICommonClaimedPosPrinterStation<D>::LineWidth() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ICommonClaimedPosPrinterStation)->get_LineWidth(&value));
    return value;
}

template <typename D> void impl_ICommonClaimedPosPrinterStation<D>::IsLetterQuality(bool value) const
{
    check_hresult(WINRT_SHIM(ICommonClaimedPosPrinterStation)->put_IsLetterQuality(value));
}

template <typename D> bool impl_ICommonClaimedPosPrinterStation<D>::IsLetterQuality() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommonClaimedPosPrinterStation)->get_IsLetterQuality(&value));
    return value;
}

template <typename D> bool impl_ICommonClaimedPosPrinterStation<D>::IsPaperNearEnd() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommonClaimedPosPrinterStation)->get_IsPaperNearEnd(&value));
    return value;
}

template <typename D> void impl_ICommonClaimedPosPrinterStation<D>::ColorCartridge(Windows::Devices::PointOfService::PosPrinterColorCartridge value) const
{
    check_hresult(WINRT_SHIM(ICommonClaimedPosPrinterStation)->put_ColorCartridge(value));
}

template <typename D> Windows::Devices::PointOfService::PosPrinterColorCartridge impl_ICommonClaimedPosPrinterStation<D>::ColorCartridge() const
{
    Windows::Devices::PointOfService::PosPrinterColorCartridge value {};
    check_hresult(WINRT_SHIM(ICommonClaimedPosPrinterStation)->get_ColorCartridge(&value));
    return value;
}

template <typename D> bool impl_ICommonClaimedPosPrinterStation<D>::IsCoverOpen() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommonClaimedPosPrinterStation)->get_IsCoverOpen(&value));
    return value;
}

template <typename D> bool impl_ICommonClaimedPosPrinterStation<D>::IsCartridgeRemoved() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommonClaimedPosPrinterStation)->get_IsCartridgeRemoved(&value));
    return value;
}

template <typename D> bool impl_ICommonClaimedPosPrinterStation<D>::IsCartridgeEmpty() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommonClaimedPosPrinterStation)->get_IsCartridgeEmpty(&value));
    return value;
}

template <typename D> bool impl_ICommonClaimedPosPrinterStation<D>::IsHeadCleaning() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommonClaimedPosPrinterStation)->get_IsHeadCleaning(&value));
    return value;
}

template <typename D> bool impl_ICommonClaimedPosPrinterStation<D>::IsPaperEmpty() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommonClaimedPosPrinterStation)->get_IsPaperEmpty(&value));
    return value;
}

template <typename D> bool impl_ICommonClaimedPosPrinterStation<D>::IsReadyToPrint() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICommonClaimedPosPrinterStation)->get_IsReadyToPrint(&value));
    return value;
}

template <typename D> bool impl_ICommonClaimedPosPrinterStation<D>::ValidateData(hstring_view data) const
{
    bool result {};
    check_hresult(WINRT_SHIM(ICommonClaimedPosPrinterStation)->abi_ValidateData(get_abi(data), &result));
    return result;
}

template <typename D> uint32_t impl_IClaimedReceiptPrinter<D>::SidewaysMaxLines() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IClaimedReceiptPrinter)->get_SidewaysMaxLines(&value));
    return value;
}

template <typename D> uint32_t impl_IClaimedReceiptPrinter<D>::SidewaysMaxChars() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IClaimedReceiptPrinter)->get_SidewaysMaxChars(&value));
    return value;
}

template <typename D> uint32_t impl_IClaimedReceiptPrinter<D>::LinesToPaperCut() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IClaimedReceiptPrinter)->get_LinesToPaperCut(&value));
    return value;
}

template <typename D> Windows::Foundation::Size impl_IClaimedReceiptPrinter<D>::PageSize() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(IClaimedReceiptPrinter)->get_PageSize(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Rect impl_IClaimedReceiptPrinter<D>::PrintArea() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(IClaimedReceiptPrinter)->get_PrintArea(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::PointOfService::ReceiptPrintJob impl_IClaimedReceiptPrinter<D>::CreateJob() const
{
    Windows::Devices::PointOfService::ReceiptPrintJob value { nullptr };
    check_hresult(WINRT_SHIM(IClaimedReceiptPrinter)->abi_CreateJob(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IClaimedSlipPrinter<D>::SidewaysMaxLines() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IClaimedSlipPrinter)->get_SidewaysMaxLines(&value));
    return value;
}

template <typename D> uint32_t impl_IClaimedSlipPrinter<D>::SidewaysMaxChars() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IClaimedSlipPrinter)->get_SidewaysMaxChars(&value));
    return value;
}

template <typename D> uint32_t impl_IClaimedSlipPrinter<D>::MaxLines() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IClaimedSlipPrinter)->get_MaxLines(&value));
    return value;
}

template <typename D> uint32_t impl_IClaimedSlipPrinter<D>::LinesNearEndToEnd() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IClaimedSlipPrinter)->get_LinesNearEndToEnd(&value));
    return value;
}

template <typename D> Windows::Devices::PointOfService::PosPrinterPrintSide impl_IClaimedSlipPrinter<D>::PrintSide() const
{
    Windows::Devices::PointOfService::PosPrinterPrintSide value {};
    check_hresult(WINRT_SHIM(IClaimedSlipPrinter)->get_PrintSide(&value));
    return value;
}

template <typename D> Windows::Foundation::Size impl_IClaimedSlipPrinter<D>::PageSize() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(IClaimedSlipPrinter)->get_PageSize(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Rect impl_IClaimedSlipPrinter<D>::PrintArea() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(IClaimedSlipPrinter)->get_PrintArea(put_abi(value)));
    return value;
}

template <typename D> void impl_IClaimedSlipPrinter<D>::OpenJaws() const
{
    check_hresult(WINRT_SHIM(IClaimedSlipPrinter)->abi_OpenJaws());
}

template <typename D> void impl_IClaimedSlipPrinter<D>::CloseJaws() const
{
    check_hresult(WINRT_SHIM(IClaimedSlipPrinter)->abi_CloseJaws());
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IClaimedSlipPrinter<D>::InsertSlipAsync(const Windows::Foundation::TimeSpan & timeout) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IClaimedSlipPrinter)->abi_InsertSlipAsync(get_abi(timeout), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IClaimedSlipPrinter<D>::RemoveSlipAsync(const Windows::Foundation::TimeSpan & timeout) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IClaimedSlipPrinter)->abi_RemoveSlipAsync(get_abi(timeout), put_abi(result)));
    return result;
}

template <typename D> void impl_IClaimedSlipPrinter<D>::ChangePrintSide(Windows::Devices::PointOfService::PosPrinterPrintSide printSide) const
{
    check_hresult(WINRT_SHIM(IClaimedSlipPrinter)->abi_ChangePrintSide(printSide));
}

template <typename D> Windows::Devices::PointOfService::SlipPrintJob impl_IClaimedSlipPrinter<D>::CreateJob() const
{
    Windows::Devices::PointOfService::SlipPrintJob value { nullptr };
    check_hresult(WINRT_SHIM(IClaimedSlipPrinter)->abi_CreateJob(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::PointOfService::JournalPrintJob impl_IClaimedJournalPrinter<D>::CreateJob() const
{
    Windows::Devices::PointOfService::JournalPrintJob value { nullptr };
    check_hresult(WINRT_SHIM(IClaimedJournalPrinter)->abi_CreateJob(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::PointOfService::CashDrawerStatus impl_ICashDrawerStatusUpdatedEventArgs<D>::Status() const
{
    Windows::Devices::PointOfService::CashDrawerStatus value { nullptr };
    check_hresult(WINRT_SHIM(ICashDrawerStatusUpdatedEventArgs)->get_Status(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::PointOfService::CashDrawerStatusKind impl_ICashDrawerStatus<D>::StatusKind() const
{
    Windows::Devices::PointOfService::CashDrawerStatusKind value {};
    check_hresult(WINRT_SHIM(ICashDrawerStatus)->get_StatusKind(&value));
    return value;
}

template <typename D> uint32_t impl_ICashDrawerStatus<D>::ExtendedStatus() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ICashDrawerStatus)->get_ExtendedStatus(&value));
    return value;
}

template <typename D> Windows::Devices::PointOfService::UnifiedPosPowerReportingType impl_ICashDrawerCapabilities<D>::PowerReportingType() const
{
    Windows::Devices::PointOfService::UnifiedPosPowerReportingType value {};
    check_hresult(WINRT_SHIM(ICashDrawerCapabilities)->get_PowerReportingType(&value));
    return value;
}

template <typename D> bool impl_ICashDrawerCapabilities<D>::IsStatisticsReportingSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICashDrawerCapabilities)->get_IsStatisticsReportingSupported(&value));
    return value;
}

template <typename D> bool impl_ICashDrawerCapabilities<D>::IsStatisticsUpdatingSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICashDrawerCapabilities)->get_IsStatisticsUpdatingSupported(&value));
    return value;
}

template <typename D> bool impl_ICashDrawerCapabilities<D>::IsStatusReportingSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICashDrawerCapabilities)->get_IsStatusReportingSupported(&value));
    return value;
}

template <typename D> bool impl_ICashDrawerCapabilities<D>::IsStatusMultiDrawerDetectSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICashDrawerCapabilities)->get_IsStatusMultiDrawerDetectSupported(&value));
    return value;
}

template <typename D> bool impl_ICashDrawerCapabilities<D>::IsDrawerOpenSensorAvailable() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICashDrawerCapabilities)->get_IsDrawerOpenSensorAvailable(&value));
    return value;
}

template <typename D> Windows::Devices::PointOfService::CashDrawer impl_ICashDrawerEventSourceEventArgs<D>::CashDrawer() const
{
    Windows::Devices::PointOfService::CashDrawer drawer { nullptr };
    check_hresult(WINRT_SHIM(ICashDrawerEventSourceEventArgs)->get_CashDrawer(put_abi(drawer)));
    return drawer;
}

template <typename D> event_token impl_ICashDrawerEventSource<D>::DrawerClosed(const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::CashDrawerEventSource, Windows::Devices::PointOfService::CashDrawerClosedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ICashDrawerEventSource)->add_DrawerClosed(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ICashDrawerEventSource> impl_ICashDrawerEventSource<D>::DrawerClosed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::CashDrawerEventSource, Windows::Devices::PointOfService::CashDrawerClosedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICashDrawerEventSource>(this, &ABI::Windows::Devices::PointOfService::ICashDrawerEventSource::remove_DrawerClosed, DrawerClosed(handler));
}

template <typename D> void impl_ICashDrawerEventSource<D>::DrawerClosed(event_token token) const
{
    check_hresult(WINRT_SHIM(ICashDrawerEventSource)->remove_DrawerClosed(token));
}

template <typename D> event_token impl_ICashDrawerEventSource<D>::DrawerOpened(const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::CashDrawerEventSource, Windows::Devices::PointOfService::CashDrawerOpenedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ICashDrawerEventSource)->add_DrawerOpened(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ICashDrawerEventSource> impl_ICashDrawerEventSource<D>::DrawerOpened(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::CashDrawerEventSource, Windows::Devices::PointOfService::CashDrawerOpenedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICashDrawerEventSource>(this, &ABI::Windows::Devices::PointOfService::ICashDrawerEventSource::remove_DrawerOpened, DrawerOpened(handler));
}

template <typename D> void impl_ICashDrawerEventSource<D>::DrawerOpened(event_token token) const
{
    check_hresult(WINRT_SHIM(ICashDrawerEventSource)->remove_DrawerOpened(token));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::CashDrawer> impl_ICashDrawerStatics<D>::GetDefaultAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::CashDrawer> result;
    check_hresult(WINRT_SHIM(ICashDrawerStatics)->abi_GetDefaultAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::CashDrawer> impl_ICashDrawerStatics<D>::FromIdAsync(hstring_view deviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::CashDrawer> result;
    check_hresult(WINRT_SHIM(ICashDrawerStatics)->abi_FromIdAsync(get_abi(deviceId), put_abi(result)));
    return result;
}

template <typename D> hstring impl_ICashDrawerStatics<D>::GetDeviceSelector() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICashDrawerStatics)->abi_GetDeviceSelector(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICashDrawer<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICashDrawer)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::PointOfService::CashDrawerCapabilities impl_ICashDrawer<D>::Capabilities() const
{
    Windows::Devices::PointOfService::CashDrawerCapabilities value { nullptr };
    check_hresult(WINRT_SHIM(ICashDrawer)->get_Capabilities(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::PointOfService::CashDrawerStatus impl_ICashDrawer<D>::Status() const
{
    Windows::Devices::PointOfService::CashDrawerStatus value { nullptr };
    check_hresult(WINRT_SHIM(ICashDrawer)->get_Status(put_abi(value)));
    return value;
}

template <typename D> bool impl_ICashDrawer<D>::IsDrawerOpen() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICashDrawer)->get_IsDrawerOpen(&value));
    return value;
}

template <typename D> Windows::Devices::PointOfService::CashDrawerEventSource impl_ICashDrawer<D>::DrawerEventSource() const
{
    Windows::Devices::PointOfService::CashDrawerEventSource value { nullptr };
    check_hresult(WINRT_SHIM(ICashDrawer)->get_DrawerEventSource(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::ClaimedCashDrawer> impl_ICashDrawer<D>::ClaimDrawerAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::ClaimedCashDrawer> operation;
    check_hresult(WINRT_SHIM(ICashDrawer)->abi_ClaimDrawerAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_ICashDrawer<D>::CheckHealthAsync(Windows::Devices::PointOfService::UnifiedPosHealthCheckLevel level) const
{
    Windows::Foundation::IAsyncOperation<hstring> operation;
    check_hresult(WINRT_SHIM(ICashDrawer)->abi_CheckHealthAsync(level, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_ICashDrawer<D>::GetStatisticsAsync(iterable<hstring> statisticsCategories) const
{
    Windows::Foundation::IAsyncOperation<hstring> operation;
    check_hresult(WINRT_SHIM(ICashDrawer)->abi_GetStatisticsAsync(get_abi(statisticsCategories), put_abi(operation)));
    return operation;
}

template <typename D> event_token impl_ICashDrawer<D>::StatusUpdated(const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::CashDrawer, Windows::Devices::PointOfService::CashDrawerStatusUpdatedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ICashDrawer)->add_StatusUpdated(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ICashDrawer> impl_ICashDrawer<D>::StatusUpdated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::CashDrawer, Windows::Devices::PointOfService::CashDrawerStatusUpdatedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICashDrawer>(this, &ABI::Windows::Devices::PointOfService::ICashDrawer::remove_StatusUpdated, StatusUpdated(handler));
}

template <typename D> void impl_ICashDrawer<D>::StatusUpdated(event_token token) const
{
    check_hresult(WINRT_SHIM(ICashDrawer)->remove_StatusUpdated(token));
}

template <typename D> void impl_ICashDrawerCloseAlarm<D>::AlarmTimeout(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(ICashDrawerCloseAlarm)->put_AlarmTimeout(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_ICashDrawerCloseAlarm<D>::AlarmTimeout() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(ICashDrawerCloseAlarm)->get_AlarmTimeout(put_abi(value)));
    return value;
}

template <typename D> void impl_ICashDrawerCloseAlarm<D>::BeepFrequency(uint32_t value) const
{
    check_hresult(WINRT_SHIM(ICashDrawerCloseAlarm)->put_BeepFrequency(value));
}

template <typename D> uint32_t impl_ICashDrawerCloseAlarm<D>::BeepFrequency() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ICashDrawerCloseAlarm)->get_BeepFrequency(&value));
    return value;
}

template <typename D> void impl_ICashDrawerCloseAlarm<D>::BeepDuration(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(ICashDrawerCloseAlarm)->put_BeepDuration(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_ICashDrawerCloseAlarm<D>::BeepDuration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(ICashDrawerCloseAlarm)->get_BeepDuration(put_abi(value)));
    return value;
}

template <typename D> void impl_ICashDrawerCloseAlarm<D>::BeepDelay(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(ICashDrawerCloseAlarm)->put_BeepDelay(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_ICashDrawerCloseAlarm<D>::BeepDelay() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(ICashDrawerCloseAlarm)->get_BeepDelay(put_abi(value)));
    return value;
}

template <typename D> event_token impl_ICashDrawerCloseAlarm<D>::AlarmTimeoutExpired(const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::CashDrawerCloseAlarm, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ICashDrawerCloseAlarm)->add_AlarmTimeoutExpired(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ICashDrawerCloseAlarm> impl_ICashDrawerCloseAlarm<D>::AlarmTimeoutExpired(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::CashDrawerCloseAlarm, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, ICashDrawerCloseAlarm>(this, &ABI::Windows::Devices::PointOfService::ICashDrawerCloseAlarm::remove_AlarmTimeoutExpired, AlarmTimeoutExpired(handler));
}

template <typename D> void impl_ICashDrawerCloseAlarm<D>::AlarmTimeoutExpired(event_token token) const
{
    check_hresult(WINRT_SHIM(ICashDrawerCloseAlarm)->remove_AlarmTimeoutExpired(token));
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ICashDrawerCloseAlarm<D>::StartAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(ICashDrawerCloseAlarm)->abi_StartAsync(put_abi(result)));
    return result;
}

template <typename D> hstring impl_IClaimedBarcodeScanner<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IClaimedBarcodeScanner)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> bool impl_IClaimedBarcodeScanner<D>::IsEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IClaimedBarcodeScanner)->get_IsEnabled(&value));
    return value;
}

template <typename D> void impl_IClaimedBarcodeScanner<D>::IsDisabledOnDataReceived(bool value) const
{
    check_hresult(WINRT_SHIM(IClaimedBarcodeScanner)->put_IsDisabledOnDataReceived(value));
}

template <typename D> bool impl_IClaimedBarcodeScanner<D>::IsDisabledOnDataReceived() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IClaimedBarcodeScanner)->get_IsDisabledOnDataReceived(&value));
    return value;
}

template <typename D> void impl_IClaimedBarcodeScanner<D>::IsDecodeDataEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IClaimedBarcodeScanner)->put_IsDecodeDataEnabled(value));
}

template <typename D> bool impl_IClaimedBarcodeScanner<D>::IsDecodeDataEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IClaimedBarcodeScanner)->get_IsDecodeDataEnabled(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IClaimedBarcodeScanner<D>::EnableAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IClaimedBarcodeScanner)->abi_EnableAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IClaimedBarcodeScanner<D>::DisableAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IClaimedBarcodeScanner)->abi_DisableAsync(put_abi(result)));
    return result;
}

template <typename D> void impl_IClaimedBarcodeScanner<D>::RetainDevice() const
{
    check_hresult(WINRT_SHIM(IClaimedBarcodeScanner)->abi_RetainDevice());
}

template <typename D> Windows::Foundation::IAsyncAction impl_IClaimedBarcodeScanner<D>::SetActiveSymbologiesAsync(iterable<uint32_t> symbologies) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IClaimedBarcodeScanner)->abi_SetActiveSymbologiesAsync(get_abi(symbologies), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IClaimedBarcodeScanner<D>::ResetStatisticsAsync(iterable<hstring> statisticsCategories) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IClaimedBarcodeScanner)->abi_ResetStatisticsAsync(get_abi(statisticsCategories), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IClaimedBarcodeScanner<D>::UpdateStatisticsAsync(iterable<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>> statistics) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IClaimedBarcodeScanner)->abi_UpdateStatisticsAsync(get_abi(statistics), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IClaimedBarcodeScanner<D>::SetActiveProfileAsync(hstring_view profile) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IClaimedBarcodeScanner)->abi_SetActiveProfileAsync(get_abi(profile), put_abi(result)));
    return result;
}

template <typename D> event_token impl_IClaimedBarcodeScanner<D>::DataReceived(const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedBarcodeScanner, Windows::Devices::PointOfService::BarcodeScannerDataReceivedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IClaimedBarcodeScanner)->add_DataReceived(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IClaimedBarcodeScanner> impl_IClaimedBarcodeScanner<D>::DataReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedBarcodeScanner, Windows::Devices::PointOfService::BarcodeScannerDataReceivedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IClaimedBarcodeScanner>(this, &ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner::remove_DataReceived, DataReceived(handler));
}

template <typename D> void impl_IClaimedBarcodeScanner<D>::DataReceived(event_token token) const
{
    check_hresult(WINRT_SHIM(IClaimedBarcodeScanner)->remove_DataReceived(token));
}

template <typename D> event_token impl_IClaimedBarcodeScanner<D>::TriggerPressed(const Windows::Foundation::EventHandler<Windows::Devices::PointOfService::ClaimedBarcodeScanner> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IClaimedBarcodeScanner)->add_TriggerPressed(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IClaimedBarcodeScanner> impl_IClaimedBarcodeScanner<D>::TriggerPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Devices::PointOfService::ClaimedBarcodeScanner> & handler) const
{
    return impl::make_event_revoker<D, IClaimedBarcodeScanner>(this, &ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner::remove_TriggerPressed, TriggerPressed(handler));
}

template <typename D> void impl_IClaimedBarcodeScanner<D>::TriggerPressed(event_token token) const
{
    check_hresult(WINRT_SHIM(IClaimedBarcodeScanner)->remove_TriggerPressed(token));
}

template <typename D> event_token impl_IClaimedBarcodeScanner<D>::TriggerReleased(const Windows::Foundation::EventHandler<Windows::Devices::PointOfService::ClaimedBarcodeScanner> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IClaimedBarcodeScanner)->add_TriggerReleased(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IClaimedBarcodeScanner> impl_IClaimedBarcodeScanner<D>::TriggerReleased(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Devices::PointOfService::ClaimedBarcodeScanner> & handler) const
{
    return impl::make_event_revoker<D, IClaimedBarcodeScanner>(this, &ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner::remove_TriggerReleased, TriggerReleased(handler));
}

template <typename D> void impl_IClaimedBarcodeScanner<D>::TriggerReleased(event_token token) const
{
    check_hresult(WINRT_SHIM(IClaimedBarcodeScanner)->remove_TriggerReleased(token));
}

template <typename D> event_token impl_IClaimedBarcodeScanner<D>::ReleaseDeviceRequested(const Windows::Foundation::EventHandler<Windows::Devices::PointOfService::ClaimedBarcodeScanner> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IClaimedBarcodeScanner)->add_ReleaseDeviceRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IClaimedBarcodeScanner> impl_IClaimedBarcodeScanner<D>::ReleaseDeviceRequested(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Devices::PointOfService::ClaimedBarcodeScanner> & handler) const
{
    return impl::make_event_revoker<D, IClaimedBarcodeScanner>(this, &ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner::remove_ReleaseDeviceRequested, ReleaseDeviceRequested(handler));
}

template <typename D> void impl_IClaimedBarcodeScanner<D>::ReleaseDeviceRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IClaimedBarcodeScanner)->remove_ReleaseDeviceRequested(token));
}

template <typename D> event_token impl_IClaimedBarcodeScanner<D>::ImagePreviewReceived(const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedBarcodeScanner, Windows::Devices::PointOfService::BarcodeScannerImagePreviewReceivedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IClaimedBarcodeScanner)->add_ImagePreviewReceived(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IClaimedBarcodeScanner> impl_IClaimedBarcodeScanner<D>::ImagePreviewReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedBarcodeScanner, Windows::Devices::PointOfService::BarcodeScannerImagePreviewReceivedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IClaimedBarcodeScanner>(this, &ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner::remove_ImagePreviewReceived, ImagePreviewReceived(handler));
}

template <typename D> void impl_IClaimedBarcodeScanner<D>::ImagePreviewReceived(event_token token) const
{
    check_hresult(WINRT_SHIM(IClaimedBarcodeScanner)->remove_ImagePreviewReceived(token));
}

template <typename D> event_token impl_IClaimedBarcodeScanner<D>::ErrorOccurred(const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedBarcodeScanner, Windows::Devices::PointOfService::BarcodeScannerErrorOccurredEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IClaimedBarcodeScanner)->add_ErrorOccurred(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IClaimedBarcodeScanner> impl_IClaimedBarcodeScanner<D>::ErrorOccurred(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedBarcodeScanner, Windows::Devices::PointOfService::BarcodeScannerErrorOccurredEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IClaimedBarcodeScanner>(this, &ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner::remove_ErrorOccurred, ErrorOccurred(handler));
}

template <typename D> void impl_IClaimedBarcodeScanner<D>::ErrorOccurred(event_token token) const
{
    check_hresult(WINRT_SHIM(IClaimedBarcodeScanner)->remove_ErrorOccurred(token));
}

template <typename D> Windows::Foundation::IAsyncAction impl_IClaimedBarcodeScanner1<D>::StartSoftwareTriggerAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IClaimedBarcodeScanner1)->abi_StartSoftwareTriggerAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IClaimedBarcodeScanner1<D>::StopSoftwareTriggerAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IClaimedBarcodeScanner1)->abi_StopSoftwareTriggerAsync(put_abi(result)));
    return result;
}

template <typename D> hstring impl_IClaimedMagneticStripeReader<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> bool impl_IClaimedMagneticStripeReader<D>::IsEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->get_IsEnabled(&value));
    return value;
}

template <typename D> void impl_IClaimedMagneticStripeReader<D>::IsDisabledOnDataReceived(bool value) const
{
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->put_IsDisabledOnDataReceived(value));
}

template <typename D> bool impl_IClaimedMagneticStripeReader<D>::IsDisabledOnDataReceived() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->get_IsDisabledOnDataReceived(&value));
    return value;
}

template <typename D> void impl_IClaimedMagneticStripeReader<D>::IsDecodeDataEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->put_IsDecodeDataEnabled(value));
}

template <typename D> bool impl_IClaimedMagneticStripeReader<D>::IsDecodeDataEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->get_IsDecodeDataEnabled(&value));
    return value;
}

template <typename D> bool impl_IClaimedMagneticStripeReader<D>::IsDeviceAuthenticated() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->get_IsDeviceAuthenticated(&value));
    return value;
}

template <typename D> void impl_IClaimedMagneticStripeReader<D>::DataEncryptionAlgorithm(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->put_DataEncryptionAlgorithm(value));
}

template <typename D> uint32_t impl_IClaimedMagneticStripeReader<D>::DataEncryptionAlgorithm() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->get_DataEncryptionAlgorithm(&value));
    return value;
}

template <typename D> void impl_IClaimedMagneticStripeReader<D>::TracksToRead(Windows::Devices::PointOfService::MagneticStripeReaderTrackIds value) const
{
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->put_TracksToRead(value));
}

template <typename D> Windows::Devices::PointOfService::MagneticStripeReaderTrackIds impl_IClaimedMagneticStripeReader<D>::TracksToRead() const
{
    Windows::Devices::PointOfService::MagneticStripeReaderTrackIds value {};
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->get_TracksToRead(&value));
    return value;
}

template <typename D> void impl_IClaimedMagneticStripeReader<D>::IsTransmitSentinelsEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->put_IsTransmitSentinelsEnabled(value));
}

template <typename D> bool impl_IClaimedMagneticStripeReader<D>::IsTransmitSentinelsEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->get_IsTransmitSentinelsEnabled(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IClaimedMagneticStripeReader<D>::EnableAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->abi_EnableAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IClaimedMagneticStripeReader<D>::DisableAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->abi_DisableAsync(put_abi(result)));
    return result;
}

template <typename D> void impl_IClaimedMagneticStripeReader<D>::RetainDevice() const
{
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->abi_RetainDevice());
}

template <typename D> void impl_IClaimedMagneticStripeReader<D>::SetErrorReportingType(Windows::Devices::PointOfService::MagneticStripeReaderErrorReportingType value) const
{
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->abi_SetErrorReportingType(value));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> impl_IClaimedMagneticStripeReader<D>::RetrieveDeviceAuthenticationDataAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> operation;
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->abi_RetrieveDeviceAuthenticationDataAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IClaimedMagneticStripeReader<D>::AuthenticateDeviceAsync(array_view<const uint8_t> responseToken) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->abi_AuthenticateDeviceAsync(responseToken.size(), get_abi(responseToken), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IClaimedMagneticStripeReader<D>::DeAuthenticateDeviceAsync(array_view<const uint8_t> responseToken) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->abi_DeAuthenticateDeviceAsync(responseToken.size(), get_abi(responseToken), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IClaimedMagneticStripeReader<D>::UpdateKeyAsync(hstring_view key, hstring_view keyName) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->abi_UpdateKeyAsync(get_abi(key), get_abi(keyName), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IClaimedMagneticStripeReader<D>::ResetStatisticsAsync(iterable<hstring> statisticsCategories) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->abi_ResetStatisticsAsync(get_abi(statisticsCategories), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IClaimedMagneticStripeReader<D>::UpdateStatisticsAsync(iterable<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>> statistics) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->abi_UpdateStatisticsAsync(get_abi(statistics), put_abi(result)));
    return result;
}

template <typename D> event_token impl_IClaimedMagneticStripeReader<D>::BankCardDataReceived(const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedMagneticStripeReader, Windows::Devices::PointOfService::MagneticStripeReaderBankCardDataReceivedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->add_BankCardDataReceived(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IClaimedMagneticStripeReader> impl_IClaimedMagneticStripeReader<D>::BankCardDataReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedMagneticStripeReader, Windows::Devices::PointOfService::MagneticStripeReaderBankCardDataReceivedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IClaimedMagneticStripeReader>(this, &ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader::remove_BankCardDataReceived, BankCardDataReceived(handler));
}

template <typename D> void impl_IClaimedMagneticStripeReader<D>::BankCardDataReceived(event_token token) const
{
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->remove_BankCardDataReceived(token));
}

template <typename D> event_token impl_IClaimedMagneticStripeReader<D>::AamvaCardDataReceived(const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedMagneticStripeReader, Windows::Devices::PointOfService::MagneticStripeReaderAamvaCardDataReceivedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->add_AamvaCardDataReceived(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IClaimedMagneticStripeReader> impl_IClaimedMagneticStripeReader<D>::AamvaCardDataReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedMagneticStripeReader, Windows::Devices::PointOfService::MagneticStripeReaderAamvaCardDataReceivedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IClaimedMagneticStripeReader>(this, &ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader::remove_AamvaCardDataReceived, AamvaCardDataReceived(handler));
}

template <typename D> void impl_IClaimedMagneticStripeReader<D>::AamvaCardDataReceived(event_token token) const
{
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->remove_AamvaCardDataReceived(token));
}

template <typename D> event_token impl_IClaimedMagneticStripeReader<D>::VendorSpecificDataReceived(const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedMagneticStripeReader, Windows::Devices::PointOfService::MagneticStripeReaderVendorSpecificCardDataReceivedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->add_VendorSpecificDataReceived(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IClaimedMagneticStripeReader> impl_IClaimedMagneticStripeReader<D>::VendorSpecificDataReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedMagneticStripeReader, Windows::Devices::PointOfService::MagneticStripeReaderVendorSpecificCardDataReceivedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IClaimedMagneticStripeReader>(this, &ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader::remove_VendorSpecificDataReceived, VendorSpecificDataReceived(handler));
}

template <typename D> void impl_IClaimedMagneticStripeReader<D>::VendorSpecificDataReceived(event_token token) const
{
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->remove_VendorSpecificDataReceived(token));
}

template <typename D> event_token impl_IClaimedMagneticStripeReader<D>::ReleaseDeviceRequested(const Windows::Foundation::EventHandler<Windows::Devices::PointOfService::ClaimedMagneticStripeReader> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->add_ReleaseDeviceRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IClaimedMagneticStripeReader> impl_IClaimedMagneticStripeReader<D>::ReleaseDeviceRequested(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Devices::PointOfService::ClaimedMagneticStripeReader> & handler) const
{
    return impl::make_event_revoker<D, IClaimedMagneticStripeReader>(this, &ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader::remove_ReleaseDeviceRequested, ReleaseDeviceRequested(handler));
}

template <typename D> void impl_IClaimedMagneticStripeReader<D>::ReleaseDeviceRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->remove_ReleaseDeviceRequested(token));
}

template <typename D> event_token impl_IClaimedMagneticStripeReader<D>::ErrorOccurred(const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedMagneticStripeReader, Windows::Devices::PointOfService::MagneticStripeReaderErrorOccurredEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->add_ErrorOccurred(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IClaimedMagneticStripeReader> impl_IClaimedMagneticStripeReader<D>::ErrorOccurred(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedMagneticStripeReader, Windows::Devices::PointOfService::MagneticStripeReaderErrorOccurredEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IClaimedMagneticStripeReader>(this, &ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader::remove_ErrorOccurred, ErrorOccurred(handler));
}

template <typename D> void impl_IClaimedMagneticStripeReader<D>::ErrorOccurred(event_token token) const
{
    check_hresult(WINRT_SHIM(IClaimedMagneticStripeReader)->remove_ErrorOccurred(token));
}

template <typename D> hstring impl_IClaimedPosPrinter<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IClaimedPosPrinter)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> bool impl_IClaimedPosPrinter<D>::IsEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IClaimedPosPrinter)->get_IsEnabled(&value));
    return value;
}

template <typename D> void impl_IClaimedPosPrinter<D>::CharacterSet(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IClaimedPosPrinter)->put_CharacterSet(value));
}

template <typename D> uint32_t impl_IClaimedPosPrinter<D>::CharacterSet() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IClaimedPosPrinter)->get_CharacterSet(&value));
    return value;
}

template <typename D> bool impl_IClaimedPosPrinter<D>::IsCoverOpen() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IClaimedPosPrinter)->get_IsCoverOpen(&value));
    return value;
}

template <typename D> void impl_IClaimedPosPrinter<D>::IsCharacterSetMappingEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IClaimedPosPrinter)->put_IsCharacterSetMappingEnabled(value));
}

template <typename D> bool impl_IClaimedPosPrinter<D>::IsCharacterSetMappingEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IClaimedPosPrinter)->get_IsCharacterSetMappingEnabled(&value));
    return value;
}

template <typename D> void impl_IClaimedPosPrinter<D>::MapMode(Windows::Devices::PointOfService::PosPrinterMapMode value) const
{
    check_hresult(WINRT_SHIM(IClaimedPosPrinter)->put_MapMode(value));
}

template <typename D> Windows::Devices::PointOfService::PosPrinterMapMode impl_IClaimedPosPrinter<D>::MapMode() const
{
    Windows::Devices::PointOfService::PosPrinterMapMode value {};
    check_hresult(WINRT_SHIM(IClaimedPosPrinter)->get_MapMode(&value));
    return value;
}

template <typename D> Windows::Devices::PointOfService::ClaimedReceiptPrinter impl_IClaimedPosPrinter<D>::Receipt() const
{
    Windows::Devices::PointOfService::ClaimedReceiptPrinter value { nullptr };
    check_hresult(WINRT_SHIM(IClaimedPosPrinter)->get_Receipt(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::PointOfService::ClaimedSlipPrinter impl_IClaimedPosPrinter<D>::Slip() const
{
    Windows::Devices::PointOfService::ClaimedSlipPrinter value { nullptr };
    check_hresult(WINRT_SHIM(IClaimedPosPrinter)->get_Slip(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::PointOfService::ClaimedJournalPrinter impl_IClaimedPosPrinter<D>::Journal() const
{
    Windows::Devices::PointOfService::ClaimedJournalPrinter value { nullptr };
    check_hresult(WINRT_SHIM(IClaimedPosPrinter)->get_Journal(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IClaimedPosPrinter<D>::EnableAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IClaimedPosPrinter)->abi_EnableAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IClaimedPosPrinter<D>::DisableAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IClaimedPosPrinter)->abi_DisableAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IClaimedPosPrinter<D>::RetainDeviceAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IClaimedPosPrinter)->abi_RetainDeviceAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IClaimedPosPrinter<D>::ResetStatisticsAsync(iterable<hstring> statisticsCategories) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IClaimedPosPrinter)->abi_ResetStatisticsAsync(get_abi(statisticsCategories), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IClaimedPosPrinter<D>::UpdateStatisticsAsync(iterable<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>> statistics) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IClaimedPosPrinter)->abi_UpdateStatisticsAsync(get_abi(statistics), put_abi(result)));
    return result;
}

template <typename D> event_token impl_IClaimedPosPrinter<D>::ReleaseDeviceRequested(const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedPosPrinter, Windows::Devices::PointOfService::PosPrinterReleaseDeviceRequestedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IClaimedPosPrinter)->add_ReleaseDeviceRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IClaimedPosPrinter> impl_IClaimedPosPrinter<D>::ReleaseDeviceRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedPosPrinter, Windows::Devices::PointOfService::PosPrinterReleaseDeviceRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IClaimedPosPrinter>(this, &ABI::Windows::Devices::PointOfService::IClaimedPosPrinter::remove_ReleaseDeviceRequested, ReleaseDeviceRequested(handler));
}

template <typename D> void impl_IClaimedPosPrinter<D>::ReleaseDeviceRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IClaimedPosPrinter)->remove_ReleaseDeviceRequested(token));
}

template <typename D> hstring impl_IClaimedCashDrawer<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IClaimedCashDrawer)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> bool impl_IClaimedCashDrawer<D>::IsEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IClaimedCashDrawer)->get_IsEnabled(&value));
    return value;
}

template <typename D> bool impl_IClaimedCashDrawer<D>::IsDrawerOpen() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IClaimedCashDrawer)->get_IsDrawerOpen(&value));
    return value;
}

template <typename D> Windows::Devices::PointOfService::CashDrawerCloseAlarm impl_IClaimedCashDrawer<D>::CloseAlarm() const
{
    Windows::Devices::PointOfService::CashDrawerCloseAlarm value { nullptr };
    check_hresult(WINRT_SHIM(IClaimedCashDrawer)->get_CloseAlarm(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IClaimedCashDrawer<D>::OpenDrawerAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IClaimedCashDrawer)->abi_OpenDrawerAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IClaimedCashDrawer<D>::EnableAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IClaimedCashDrawer)->abi_EnableAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IClaimedCashDrawer<D>::DisableAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IClaimedCashDrawer)->abi_DisableAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IClaimedCashDrawer<D>::RetainDeviceAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IClaimedCashDrawer)->abi_RetainDeviceAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IClaimedCashDrawer<D>::ResetStatisticsAsync(iterable<hstring> statisticsCategories) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IClaimedCashDrawer)->abi_ResetStatisticsAsync(get_abi(statisticsCategories), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IClaimedCashDrawer<D>::UpdateStatisticsAsync(iterable<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>> statistics) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IClaimedCashDrawer)->abi_UpdateStatisticsAsync(get_abi(statistics), put_abi(result)));
    return result;
}

template <typename D> event_token impl_IClaimedCashDrawer<D>::ReleaseDeviceRequested(const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedCashDrawer, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IClaimedCashDrawer)->add_ReleaseDeviceRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IClaimedCashDrawer> impl_IClaimedCashDrawer<D>::ReleaseDeviceRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::PointOfService::ClaimedCashDrawer, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IClaimedCashDrawer>(this, &ABI::Windows::Devices::PointOfService::IClaimedCashDrawer::remove_ReleaseDeviceRequested, ReleaseDeviceRequested(handler));
}

template <typename D> void impl_IClaimedCashDrawer<D>::ReleaseDeviceRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IClaimedCashDrawer)->remove_ReleaseDeviceRequested(token));
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::BarcodeScanner> BarcodeScanner::GetDefaultAsync()
{
    return get_activation_factory<BarcodeScanner, IBarcodeScannerStatics>().GetDefaultAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::BarcodeScanner> BarcodeScanner::FromIdAsync(hstring_view deviceId)
{
    return get_activation_factory<BarcodeScanner, IBarcodeScannerStatics>().FromIdAsync(deviceId);
}

inline hstring BarcodeScanner::GetDeviceSelector()
{
    return get_activation_factory<BarcodeScanner, IBarcodeScannerStatics>().GetDeviceSelector();
}

inline uint32_t BarcodeSymbologies::Unknown()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Unknown();
}

inline uint32_t BarcodeSymbologies::Ean8()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Ean8();
}

inline uint32_t BarcodeSymbologies::Ean8Add2()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Ean8Add2();
}

inline uint32_t BarcodeSymbologies::Ean8Add5()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Ean8Add5();
}

inline uint32_t BarcodeSymbologies::Eanv()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Eanv();
}

inline uint32_t BarcodeSymbologies::EanvAdd2()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().EanvAdd2();
}

inline uint32_t BarcodeSymbologies::EanvAdd5()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().EanvAdd5();
}

inline uint32_t BarcodeSymbologies::Ean13()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Ean13();
}

inline uint32_t BarcodeSymbologies::Ean13Add2()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Ean13Add2();
}

inline uint32_t BarcodeSymbologies::Ean13Add5()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Ean13Add5();
}

inline uint32_t BarcodeSymbologies::Isbn()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Isbn();
}

inline uint32_t BarcodeSymbologies::IsbnAdd5()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().IsbnAdd5();
}

inline uint32_t BarcodeSymbologies::Ismn()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Ismn();
}

inline uint32_t BarcodeSymbologies::IsmnAdd2()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().IsmnAdd2();
}

inline uint32_t BarcodeSymbologies::IsmnAdd5()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().IsmnAdd5();
}

inline uint32_t BarcodeSymbologies::Issn()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Issn();
}

inline uint32_t BarcodeSymbologies::IssnAdd2()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().IssnAdd2();
}

inline uint32_t BarcodeSymbologies::IssnAdd5()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().IssnAdd5();
}

inline uint32_t BarcodeSymbologies::Ean99()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Ean99();
}

inline uint32_t BarcodeSymbologies::Ean99Add2()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Ean99Add2();
}

inline uint32_t BarcodeSymbologies::Ean99Add5()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Ean99Add5();
}

inline uint32_t BarcodeSymbologies::Upca()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Upca();
}

inline uint32_t BarcodeSymbologies::UpcaAdd2()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().UpcaAdd2();
}

inline uint32_t BarcodeSymbologies::UpcaAdd5()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().UpcaAdd5();
}

inline uint32_t BarcodeSymbologies::Upce()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Upce();
}

inline uint32_t BarcodeSymbologies::UpceAdd2()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().UpceAdd2();
}

inline uint32_t BarcodeSymbologies::UpceAdd5()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().UpceAdd5();
}

inline uint32_t BarcodeSymbologies::UpcCoupon()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().UpcCoupon();
}

inline uint32_t BarcodeSymbologies::TfStd()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().TfStd();
}

inline uint32_t BarcodeSymbologies::TfDis()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().TfDis();
}

inline uint32_t BarcodeSymbologies::TfInt()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().TfInt();
}

inline uint32_t BarcodeSymbologies::TfInd()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().TfInd();
}

inline uint32_t BarcodeSymbologies::TfMat()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().TfMat();
}

inline uint32_t BarcodeSymbologies::TfIata()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().TfIata();
}

inline uint32_t BarcodeSymbologies::Gs1DatabarType1()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Gs1DatabarType1();
}

inline uint32_t BarcodeSymbologies::Gs1DatabarType2()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Gs1DatabarType2();
}

inline uint32_t BarcodeSymbologies::Gs1DatabarType3()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Gs1DatabarType3();
}

inline uint32_t BarcodeSymbologies::Code39()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Code39();
}

inline uint32_t BarcodeSymbologies::Code39Ex()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Code39Ex();
}

inline uint32_t BarcodeSymbologies::Trioptic39()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Trioptic39();
}

inline uint32_t BarcodeSymbologies::Code32()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Code32();
}

inline uint32_t BarcodeSymbologies::Pzn()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Pzn();
}

inline uint32_t BarcodeSymbologies::Code93()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Code93();
}

inline uint32_t BarcodeSymbologies::Code93Ex()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Code93Ex();
}

inline uint32_t BarcodeSymbologies::Code128()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Code128();
}

inline uint32_t BarcodeSymbologies::Gs1128()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Gs1128();
}

inline uint32_t BarcodeSymbologies::Gs1128Coupon()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Gs1128Coupon();
}

inline uint32_t BarcodeSymbologies::UccEan128()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().UccEan128();
}

inline uint32_t BarcodeSymbologies::Sisac()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Sisac();
}

inline uint32_t BarcodeSymbologies::Isbt()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Isbt();
}

inline uint32_t BarcodeSymbologies::Codabar()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Codabar();
}

inline uint32_t BarcodeSymbologies::Code11()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Code11();
}

inline uint32_t BarcodeSymbologies::Msi()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Msi();
}

inline uint32_t BarcodeSymbologies::Plessey()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Plessey();
}

inline uint32_t BarcodeSymbologies::Telepen()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Telepen();
}

inline uint32_t BarcodeSymbologies::Code16k()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Code16k();
}

inline uint32_t BarcodeSymbologies::CodablockA()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().CodablockA();
}

inline uint32_t BarcodeSymbologies::CodablockF()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().CodablockF();
}

inline uint32_t BarcodeSymbologies::Codablock128()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Codablock128();
}

inline uint32_t BarcodeSymbologies::Code49()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Code49();
}

inline uint32_t BarcodeSymbologies::Aztec()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Aztec();
}

inline uint32_t BarcodeSymbologies::DataCode()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().DataCode();
}

inline uint32_t BarcodeSymbologies::DataMatrix()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().DataMatrix();
}

inline uint32_t BarcodeSymbologies::HanXin()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().HanXin();
}

inline uint32_t BarcodeSymbologies::Maxicode()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Maxicode();
}

inline uint32_t BarcodeSymbologies::MicroPdf417()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().MicroPdf417();
}

inline uint32_t BarcodeSymbologies::MicroQr()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().MicroQr();
}

inline uint32_t BarcodeSymbologies::Pdf417()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Pdf417();
}

inline uint32_t BarcodeSymbologies::Qr()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Qr();
}

inline uint32_t BarcodeSymbologies::MsTag()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().MsTag();
}

inline uint32_t BarcodeSymbologies::Ccab()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Ccab();
}

inline uint32_t BarcodeSymbologies::Ccc()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Ccc();
}

inline uint32_t BarcodeSymbologies::Tlc39()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Tlc39();
}

inline uint32_t BarcodeSymbologies::AusPost()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().AusPost();
}

inline uint32_t BarcodeSymbologies::CanPost()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().CanPost();
}

inline uint32_t BarcodeSymbologies::ChinaPost()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().ChinaPost();
}

inline uint32_t BarcodeSymbologies::DutchKix()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().DutchKix();
}

inline uint32_t BarcodeSymbologies::InfoMail()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().InfoMail();
}

inline uint32_t BarcodeSymbologies::ItalianPost25()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().ItalianPost25();
}

inline uint32_t BarcodeSymbologies::ItalianPost39()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().ItalianPost39();
}

inline uint32_t BarcodeSymbologies::JapanPost()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().JapanPost();
}

inline uint32_t BarcodeSymbologies::KoreanPost()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().KoreanPost();
}

inline uint32_t BarcodeSymbologies::SwedenPost()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().SwedenPost();
}

inline uint32_t BarcodeSymbologies::UkPost()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().UkPost();
}

inline uint32_t BarcodeSymbologies::UsIntelligent()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().UsIntelligent();
}

inline uint32_t BarcodeSymbologies::UsIntelligentPkg()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().UsIntelligentPkg();
}

inline uint32_t BarcodeSymbologies::UsPlanet()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().UsPlanet();
}

inline uint32_t BarcodeSymbologies::UsPostNet()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().UsPostNet();
}

inline uint32_t BarcodeSymbologies::Us4StateFics()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Us4StateFics();
}

inline uint32_t BarcodeSymbologies::OcrA()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().OcrA();
}

inline uint32_t BarcodeSymbologies::OcrB()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().OcrB();
}

inline uint32_t BarcodeSymbologies::Micr()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().Micr();
}

inline uint32_t BarcodeSymbologies::ExtendedBase()
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().ExtendedBase();
}

inline hstring BarcodeSymbologies::GetName(uint32_t scanDataType)
{
    return get_activation_factory<BarcodeSymbologies, IBarcodeSymbologiesStatics>().GetName(scanDataType);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::CashDrawer> CashDrawer::GetDefaultAsync()
{
    return get_activation_factory<CashDrawer, ICashDrawerStatics>().GetDefaultAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::CashDrawer> CashDrawer::FromIdAsync(hstring_view deviceId)
{
    return get_activation_factory<CashDrawer, ICashDrawerStatics>().FromIdAsync(deviceId);
}

inline hstring CashDrawer::GetDeviceSelector()
{
    return get_activation_factory<CashDrawer, ICashDrawerStatics>().GetDeviceSelector();
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::MagneticStripeReader> MagneticStripeReader::GetDefaultAsync()
{
    return get_activation_factory<MagneticStripeReader, IMagneticStripeReaderStatics>().GetDefaultAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::MagneticStripeReader> MagneticStripeReader::FromIdAsync(hstring_view deviceId)
{
    return get_activation_factory<MagneticStripeReader, IMagneticStripeReaderStatics>().FromIdAsync(deviceId);
}

inline hstring MagneticStripeReader::GetDeviceSelector()
{
    return get_activation_factory<MagneticStripeReader, IMagneticStripeReaderStatics>().GetDeviceSelector();
}

inline uint32_t MagneticStripeReaderCardTypes::Unknown()
{
    return get_activation_factory<MagneticStripeReaderCardTypes, IMagneticStripeReaderCardTypesStatics>().Unknown();
}

inline uint32_t MagneticStripeReaderCardTypes::Bank()
{
    return get_activation_factory<MagneticStripeReaderCardTypes, IMagneticStripeReaderCardTypesStatics>().Bank();
}

inline uint32_t MagneticStripeReaderCardTypes::Aamva()
{
    return get_activation_factory<MagneticStripeReaderCardTypes, IMagneticStripeReaderCardTypesStatics>().Aamva();
}

inline uint32_t MagneticStripeReaderCardTypes::ExtendedBase()
{
    return get_activation_factory<MagneticStripeReaderCardTypes, IMagneticStripeReaderCardTypesStatics>().ExtendedBase();
}

inline uint32_t MagneticStripeReaderEncryptionAlgorithms::None()
{
    return get_activation_factory<MagneticStripeReaderEncryptionAlgorithms, IMagneticStripeReaderEncryptionAlgorithmsStatics>().None();
}

inline uint32_t MagneticStripeReaderEncryptionAlgorithms::TripleDesDukpt()
{
    return get_activation_factory<MagneticStripeReaderEncryptionAlgorithms, IMagneticStripeReaderEncryptionAlgorithmsStatics>().TripleDesDukpt();
}

inline uint32_t MagneticStripeReaderEncryptionAlgorithms::ExtendedBase()
{
    return get_activation_factory<MagneticStripeReaderEncryptionAlgorithms, IMagneticStripeReaderEncryptionAlgorithmsStatics>().ExtendedBase();
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::PosPrinter> PosPrinter::GetDefaultAsync()
{
    return get_activation_factory<PosPrinter, IPosPrinterStatics>().GetDefaultAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::PosPrinter> PosPrinter::FromIdAsync(hstring_view deviceId)
{
    return get_activation_factory<PosPrinter, IPosPrinterStatics>().FromIdAsync(deviceId);
}

inline hstring PosPrinter::GetDeviceSelector()
{
    return get_activation_factory<PosPrinter, IPosPrinterStatics>().GetDeviceSelector();
}

inline uint32_t PosPrinterCharacterSetIds::Utf16LE()
{
    return get_activation_factory<PosPrinterCharacterSetIds, IPosPrinterCharacterSetIdsStatics>().Utf16LE();
}

inline uint32_t PosPrinterCharacterSetIds::Ascii()
{
    return get_activation_factory<PosPrinterCharacterSetIds, IPosPrinterCharacterSetIdsStatics>().Ascii();
}

inline uint32_t PosPrinterCharacterSetIds::Ansi()
{
    return get_activation_factory<PosPrinterCharacterSetIds, IPosPrinterCharacterSetIdsStatics>().Ansi();
}

}

}
#pragma warning(pop)
