// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Graphics.Printing.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Devices.Scanners.3.h"
#include "Windows.Devices.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Scanners::IImageScanner> : produce_base<D, Windows::Devices::Scanners::IImageScanner>
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

    HRESULT __stdcall get_DefaultScanSource(Windows::Devices::Scanners::ImageScannerScanSource * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DefaultScanSource());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsScanSourceSupported(Windows::Devices::Scanners::ImageScannerScanSource value, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsScanSourceSupported(value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FlatbedConfiguration(impl::abi_arg_out<Windows::Devices::Scanners::IImageScannerFormatConfiguration> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FlatbedConfiguration());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FeederConfiguration(impl::abi_arg_out<Windows::Devices::Scanners::IImageScannerFormatConfiguration> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FeederConfiguration());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AutoConfiguration(impl::abi_arg_out<Windows::Devices::Scanners::IImageScannerFormatConfiguration> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AutoConfiguration());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsPreviewSupported(Windows::Devices::Scanners::ImageScannerScanSource scanSource, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsPreviewSupported(scanSource));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ScanPreviewToStreamAsync(Windows::Devices::Scanners::ImageScannerScanSource scanSource, impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> targetStream, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Scanners::ImageScannerPreviewResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ScanPreviewToStreamAsync(scanSource, *reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&targetStream)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ScanFilesToFolderAsync(Windows::Devices::Scanners::ImageScannerScanSource scanSource, impl::abi_arg_in<Windows::Storage::IStorageFolder> storageFolder, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Devices::Scanners::ImageScannerScanResult, uint32_t>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ScanFilesToFolderAsync(scanSource, *reinterpret_cast<const Windows::Storage::StorageFolder *>(&storageFolder)));
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
struct produce<D, Windows::Devices::Scanners::IImageScannerFeederConfiguration> : produce_base<D, Windows::Devices::Scanners::IImageScannerFeederConfiguration>
{
    HRESULT __stdcall get_CanAutoDetectPageSize(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanAutoDetectPageSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AutoDetectPageSize(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AutoDetectPageSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AutoDetectPageSize(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutoDetectPageSize(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PageSize(Windows::Graphics::Printing::PrintMediaSize * value) noexcept override
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

    HRESULT __stdcall put_PageSize(Windows::Graphics::Printing::PrintMediaSize value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PageSize(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PageOrientation(Windows::Graphics::Printing::PrintOrientation * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PageOrientation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PageOrientation(Windows::Graphics::Printing::PrintOrientation value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PageOrientation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PageSizeDimensions(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PageSizeDimensions());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsPageSizeSupported(Windows::Graphics::Printing::PrintMediaSize pageSize, Windows::Graphics::Printing::PrintOrientation pageOrientation, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsPageSizeSupported(pageSize, pageOrientation));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxNumberOfPages(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxNumberOfPages());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxNumberOfPages(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxNumberOfPages(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanScanDuplex(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanScanDuplex());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Duplex(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Duplex());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Duplex(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Duplex(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanScanAhead(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanScanAhead());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ScanAhead(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScanAhead());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ScanAhead(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ScanAhead(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Scanners::IImageScannerFormatConfiguration> : produce_base<D, Windows::Devices::Scanners::IImageScannerFormatConfiguration>
{
    HRESULT __stdcall get_DefaultFormat(Windows::Devices::Scanners::ImageScannerFormat * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DefaultFormat());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Format(Windows::Devices::Scanners::ImageScannerFormat * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Format());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Format(Windows::Devices::Scanners::ImageScannerFormat value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Format(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsFormatSupported(Windows::Devices::Scanners::ImageScannerFormat value, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsFormatSupported(value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Scanners::IImageScannerPreviewResult> : produce_base<D, Windows::Devices::Scanners::IImageScannerPreviewResult>
{
    HRESULT __stdcall get_Succeeded(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Succeeded());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Format(Windows::Devices::Scanners::ImageScannerFormat * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Format());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Scanners::IImageScannerScanResult> : produce_base<D, Windows::Devices::Scanners::IImageScannerScanResult>
{
    HRESULT __stdcall get_ScannedFiles(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScannedFiles());
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
struct produce<D, Windows::Devices::Scanners::IImageScannerSourceConfiguration> : produce_base<D, Windows::Devices::Scanners::IImageScannerSourceConfiguration>
{
    HRESULT __stdcall get_MinScanArea(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinScanArea());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxScanArea(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxScanArea());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SelectedScanRegion(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SelectedScanRegion());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SelectedScanRegion(impl::abi_arg_in<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SelectedScanRegion(*reinterpret_cast<const Windows::Foundation::Rect *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AutoCroppingMode(Windows::Devices::Scanners::ImageScannerAutoCroppingMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AutoCroppingMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AutoCroppingMode(Windows::Devices::Scanners::ImageScannerAutoCroppingMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutoCroppingMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsAutoCroppingModeSupported(Windows::Devices::Scanners::ImageScannerAutoCroppingMode value, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsAutoCroppingModeSupported(value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinResolution(impl::abi_arg_out<Windows::Devices::Scanners::ImageScannerResolution> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinResolution());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxResolution(impl::abi_arg_out<Windows::Devices::Scanners::ImageScannerResolution> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxResolution());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OpticalResolution(impl::abi_arg_out<Windows::Devices::Scanners::ImageScannerResolution> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OpticalResolution());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DesiredResolution(impl::abi_arg_out<Windows::Devices::Scanners::ImageScannerResolution> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DesiredResolution());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DesiredResolution(impl::abi_arg_in<Windows::Devices::Scanners::ImageScannerResolution> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredResolution(*reinterpret_cast<const Windows::Devices::Scanners::ImageScannerResolution *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ActualResolution(impl::abi_arg_out<Windows::Devices::Scanners::ImageScannerResolution> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ActualResolution());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DefaultColorMode(Windows::Devices::Scanners::ImageScannerColorMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DefaultColorMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ColorMode(Windows::Devices::Scanners::ImageScannerColorMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ColorMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ColorMode(Windows::Devices::Scanners::ImageScannerColorMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ColorMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsColorModeSupported(Windows::Devices::Scanners::ImageScannerColorMode value, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsColorModeSupported(value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinBrightness(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinBrightness());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxBrightness(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxBrightness());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BrightnessStep(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BrightnessStep());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DefaultBrightness(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DefaultBrightness());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Brightness(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Brightness());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Brightness(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Brightness(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinContrast(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinContrast());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxContrast(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxContrast());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContrastStep(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContrastStep());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DefaultContrast(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DefaultContrast());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Contrast(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Contrast());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Contrast(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Contrast(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Scanners::IImageScannerStatics> : produce_base<D, Windows::Devices::Scanners::IImageScannerStatics>
{
    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Scanners::ImageScanner>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().FromIdAsync(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelector(impl::abi_arg_out<hstring> selector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *selector = detach_abi(this->shim().GetDeviceSelector());
            return S_OK;
        }
        catch (...)
        {
            *selector = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Devices::Scanners {

template <typename D> Windows::Devices::Scanners::ImageScannerFormat impl_IImageScannerFormatConfiguration<D>::DefaultFormat() const
{
    Windows::Devices::Scanners::ImageScannerFormat value {};
    check_hresult(WINRT_SHIM(IImageScannerFormatConfiguration)->get_DefaultFormat(&value));
    return value;
}

template <typename D> Windows::Devices::Scanners::ImageScannerFormat impl_IImageScannerFormatConfiguration<D>::Format() const
{
    Windows::Devices::Scanners::ImageScannerFormat value {};
    check_hresult(WINRT_SHIM(IImageScannerFormatConfiguration)->get_Format(&value));
    return value;
}

template <typename D> void impl_IImageScannerFormatConfiguration<D>::Format(Windows::Devices::Scanners::ImageScannerFormat value) const
{
    check_hresult(WINRT_SHIM(IImageScannerFormatConfiguration)->put_Format(value));
}

template <typename D> bool impl_IImageScannerFormatConfiguration<D>::IsFormatSupported(Windows::Devices::Scanners::ImageScannerFormat value) const
{
    bool result {};
    check_hresult(WINRT_SHIM(IImageScannerFormatConfiguration)->abi_IsFormatSupported(value, &result));
    return result;
}

template <typename D> Windows::Foundation::Size impl_IImageScannerSourceConfiguration<D>::MinScanArea() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(IImageScannerSourceConfiguration)->get_MinScanArea(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Size impl_IImageScannerSourceConfiguration<D>::MaxScanArea() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(IImageScannerSourceConfiguration)->get_MaxScanArea(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Rect impl_IImageScannerSourceConfiguration<D>::SelectedScanRegion() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(IImageScannerSourceConfiguration)->get_SelectedScanRegion(put_abi(value)));
    return value;
}

template <typename D> void impl_IImageScannerSourceConfiguration<D>::SelectedScanRegion(const Windows::Foundation::Rect & value) const
{
    check_hresult(WINRT_SHIM(IImageScannerSourceConfiguration)->put_SelectedScanRegion(get_abi(value)));
}

template <typename D> Windows::Devices::Scanners::ImageScannerAutoCroppingMode impl_IImageScannerSourceConfiguration<D>::AutoCroppingMode() const
{
    Windows::Devices::Scanners::ImageScannerAutoCroppingMode value {};
    check_hresult(WINRT_SHIM(IImageScannerSourceConfiguration)->get_AutoCroppingMode(&value));
    return value;
}

template <typename D> void impl_IImageScannerSourceConfiguration<D>::AutoCroppingMode(Windows::Devices::Scanners::ImageScannerAutoCroppingMode value) const
{
    check_hresult(WINRT_SHIM(IImageScannerSourceConfiguration)->put_AutoCroppingMode(value));
}

template <typename D> bool impl_IImageScannerSourceConfiguration<D>::IsAutoCroppingModeSupported(Windows::Devices::Scanners::ImageScannerAutoCroppingMode value) const
{
    bool result {};
    check_hresult(WINRT_SHIM(IImageScannerSourceConfiguration)->abi_IsAutoCroppingModeSupported(value, &result));
    return result;
}

template <typename D> Windows::Devices::Scanners::ImageScannerResolution impl_IImageScannerSourceConfiguration<D>::MinResolution() const
{
    Windows::Devices::Scanners::ImageScannerResolution value {};
    check_hresult(WINRT_SHIM(IImageScannerSourceConfiguration)->get_MinResolution(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Scanners::ImageScannerResolution impl_IImageScannerSourceConfiguration<D>::MaxResolution() const
{
    Windows::Devices::Scanners::ImageScannerResolution value {};
    check_hresult(WINRT_SHIM(IImageScannerSourceConfiguration)->get_MaxResolution(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Scanners::ImageScannerResolution impl_IImageScannerSourceConfiguration<D>::OpticalResolution() const
{
    Windows::Devices::Scanners::ImageScannerResolution value {};
    check_hresult(WINRT_SHIM(IImageScannerSourceConfiguration)->get_OpticalResolution(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Scanners::ImageScannerResolution impl_IImageScannerSourceConfiguration<D>::DesiredResolution() const
{
    Windows::Devices::Scanners::ImageScannerResolution value {};
    check_hresult(WINRT_SHIM(IImageScannerSourceConfiguration)->get_DesiredResolution(put_abi(value)));
    return value;
}

template <typename D> void impl_IImageScannerSourceConfiguration<D>::DesiredResolution(const Windows::Devices::Scanners::ImageScannerResolution & value) const
{
    check_hresult(WINRT_SHIM(IImageScannerSourceConfiguration)->put_DesiredResolution(get_abi(value)));
}

template <typename D> Windows::Devices::Scanners::ImageScannerResolution impl_IImageScannerSourceConfiguration<D>::ActualResolution() const
{
    Windows::Devices::Scanners::ImageScannerResolution value {};
    check_hresult(WINRT_SHIM(IImageScannerSourceConfiguration)->get_ActualResolution(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Scanners::ImageScannerColorMode impl_IImageScannerSourceConfiguration<D>::DefaultColorMode() const
{
    Windows::Devices::Scanners::ImageScannerColorMode value {};
    check_hresult(WINRT_SHIM(IImageScannerSourceConfiguration)->get_DefaultColorMode(&value));
    return value;
}

template <typename D> Windows::Devices::Scanners::ImageScannerColorMode impl_IImageScannerSourceConfiguration<D>::ColorMode() const
{
    Windows::Devices::Scanners::ImageScannerColorMode value {};
    check_hresult(WINRT_SHIM(IImageScannerSourceConfiguration)->get_ColorMode(&value));
    return value;
}

template <typename D> void impl_IImageScannerSourceConfiguration<D>::ColorMode(Windows::Devices::Scanners::ImageScannerColorMode value) const
{
    check_hresult(WINRT_SHIM(IImageScannerSourceConfiguration)->put_ColorMode(value));
}

template <typename D> bool impl_IImageScannerSourceConfiguration<D>::IsColorModeSupported(Windows::Devices::Scanners::ImageScannerColorMode value) const
{
    bool result {};
    check_hresult(WINRT_SHIM(IImageScannerSourceConfiguration)->abi_IsColorModeSupported(value, &result));
    return result;
}

template <typename D> int32_t impl_IImageScannerSourceConfiguration<D>::MinBrightness() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IImageScannerSourceConfiguration)->get_MinBrightness(&value));
    return value;
}

template <typename D> int32_t impl_IImageScannerSourceConfiguration<D>::MaxBrightness() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IImageScannerSourceConfiguration)->get_MaxBrightness(&value));
    return value;
}

template <typename D> uint32_t impl_IImageScannerSourceConfiguration<D>::BrightnessStep() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IImageScannerSourceConfiguration)->get_BrightnessStep(&value));
    return value;
}

template <typename D> int32_t impl_IImageScannerSourceConfiguration<D>::DefaultBrightness() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IImageScannerSourceConfiguration)->get_DefaultBrightness(&value));
    return value;
}

template <typename D> int32_t impl_IImageScannerSourceConfiguration<D>::Brightness() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IImageScannerSourceConfiguration)->get_Brightness(&value));
    return value;
}

template <typename D> void impl_IImageScannerSourceConfiguration<D>::Brightness(int32_t value) const
{
    check_hresult(WINRT_SHIM(IImageScannerSourceConfiguration)->put_Brightness(value));
}

template <typename D> int32_t impl_IImageScannerSourceConfiguration<D>::MinContrast() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IImageScannerSourceConfiguration)->get_MinContrast(&value));
    return value;
}

template <typename D> int32_t impl_IImageScannerSourceConfiguration<D>::MaxContrast() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IImageScannerSourceConfiguration)->get_MaxContrast(&value));
    return value;
}

template <typename D> uint32_t impl_IImageScannerSourceConfiguration<D>::ContrastStep() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IImageScannerSourceConfiguration)->get_ContrastStep(&value));
    return value;
}

template <typename D> int32_t impl_IImageScannerSourceConfiguration<D>::DefaultContrast() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IImageScannerSourceConfiguration)->get_DefaultContrast(&value));
    return value;
}

template <typename D> int32_t impl_IImageScannerSourceConfiguration<D>::Contrast() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IImageScannerSourceConfiguration)->get_Contrast(&value));
    return value;
}

template <typename D> void impl_IImageScannerSourceConfiguration<D>::Contrast(int32_t value) const
{
    check_hresult(WINRT_SHIM(IImageScannerSourceConfiguration)->put_Contrast(value));
}

template <typename D> bool impl_IImageScannerFeederConfiguration<D>::CanAutoDetectPageSize() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IImageScannerFeederConfiguration)->get_CanAutoDetectPageSize(&value));
    return value;
}

template <typename D> bool impl_IImageScannerFeederConfiguration<D>::AutoDetectPageSize() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IImageScannerFeederConfiguration)->get_AutoDetectPageSize(&value));
    return value;
}

template <typename D> void impl_IImageScannerFeederConfiguration<D>::AutoDetectPageSize(bool value) const
{
    check_hresult(WINRT_SHIM(IImageScannerFeederConfiguration)->put_AutoDetectPageSize(value));
}

template <typename D> Windows::Graphics::Printing::PrintMediaSize impl_IImageScannerFeederConfiguration<D>::PageSize() const
{
    Windows::Graphics::Printing::PrintMediaSize value {};
    check_hresult(WINRT_SHIM(IImageScannerFeederConfiguration)->get_PageSize(&value));
    return value;
}

template <typename D> void impl_IImageScannerFeederConfiguration<D>::PageSize(Windows::Graphics::Printing::PrintMediaSize value) const
{
    check_hresult(WINRT_SHIM(IImageScannerFeederConfiguration)->put_PageSize(value));
}

template <typename D> Windows::Graphics::Printing::PrintOrientation impl_IImageScannerFeederConfiguration<D>::PageOrientation() const
{
    Windows::Graphics::Printing::PrintOrientation value {};
    check_hresult(WINRT_SHIM(IImageScannerFeederConfiguration)->get_PageOrientation(&value));
    return value;
}

template <typename D> void impl_IImageScannerFeederConfiguration<D>::PageOrientation(Windows::Graphics::Printing::PrintOrientation value) const
{
    check_hresult(WINRT_SHIM(IImageScannerFeederConfiguration)->put_PageOrientation(value));
}

template <typename D> Windows::Foundation::Size impl_IImageScannerFeederConfiguration<D>::PageSizeDimensions() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(IImageScannerFeederConfiguration)->get_PageSizeDimensions(put_abi(value)));
    return value;
}

template <typename D> bool impl_IImageScannerFeederConfiguration<D>::IsPageSizeSupported(Windows::Graphics::Printing::PrintMediaSize pageSize, Windows::Graphics::Printing::PrintOrientation pageOrientation) const
{
    bool result {};
    check_hresult(WINRT_SHIM(IImageScannerFeederConfiguration)->abi_IsPageSizeSupported(pageSize, pageOrientation, &result));
    return result;
}

template <typename D> uint32_t impl_IImageScannerFeederConfiguration<D>::MaxNumberOfPages() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IImageScannerFeederConfiguration)->get_MaxNumberOfPages(&value));
    return value;
}

template <typename D> void impl_IImageScannerFeederConfiguration<D>::MaxNumberOfPages(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IImageScannerFeederConfiguration)->put_MaxNumberOfPages(value));
}

template <typename D> bool impl_IImageScannerFeederConfiguration<D>::CanScanDuplex() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IImageScannerFeederConfiguration)->get_CanScanDuplex(&value));
    return value;
}

template <typename D> bool impl_IImageScannerFeederConfiguration<D>::Duplex() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IImageScannerFeederConfiguration)->get_Duplex(&value));
    return value;
}

template <typename D> void impl_IImageScannerFeederConfiguration<D>::Duplex(bool value) const
{
    check_hresult(WINRT_SHIM(IImageScannerFeederConfiguration)->put_Duplex(value));
}

template <typename D> bool impl_IImageScannerFeederConfiguration<D>::CanScanAhead() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IImageScannerFeederConfiguration)->get_CanScanAhead(&value));
    return value;
}

template <typename D> bool impl_IImageScannerFeederConfiguration<D>::ScanAhead() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IImageScannerFeederConfiguration)->get_ScanAhead(&value));
    return value;
}

template <typename D> void impl_IImageScannerFeederConfiguration<D>::ScanAhead(bool value) const
{
    check_hresult(WINRT_SHIM(IImageScannerFeederConfiguration)->put_ScanAhead(value));
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile> impl_IImageScannerScanResult<D>::ScannedFiles() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile> value;
    check_hresult(WINRT_SHIM(IImageScannerScanResult)->get_ScannedFiles(put_abi(value)));
    return value;
}

template <typename D> bool impl_IImageScannerPreviewResult<D>::Succeeded() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IImageScannerPreviewResult)->get_Succeeded(&value));
    return value;
}

template <typename D> Windows::Devices::Scanners::ImageScannerFormat impl_IImageScannerPreviewResult<D>::Format() const
{
    Windows::Devices::Scanners::ImageScannerFormat value {};
    check_hresult(WINRT_SHIM(IImageScannerPreviewResult)->get_Format(&value));
    return value;
}

template <typename D> hstring impl_IImageScanner<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IImageScanner)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Scanners::ImageScannerScanSource impl_IImageScanner<D>::DefaultScanSource() const
{
    Windows::Devices::Scanners::ImageScannerScanSource value {};
    check_hresult(WINRT_SHIM(IImageScanner)->get_DefaultScanSource(&value));
    return value;
}

template <typename D> bool impl_IImageScanner<D>::IsScanSourceSupported(Windows::Devices::Scanners::ImageScannerScanSource value) const
{
    bool result {};
    check_hresult(WINRT_SHIM(IImageScanner)->abi_IsScanSourceSupported(value, &result));
    return result;
}

template <typename D> Windows::Devices::Scanners::ImageScannerFlatbedConfiguration impl_IImageScanner<D>::FlatbedConfiguration() const
{
    Windows::Devices::Scanners::ImageScannerFlatbedConfiguration value { nullptr };
    check_hresult(WINRT_SHIM(IImageScanner)->get_FlatbedConfiguration(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Scanners::ImageScannerFeederConfiguration impl_IImageScanner<D>::FeederConfiguration() const
{
    Windows::Devices::Scanners::ImageScannerFeederConfiguration value { nullptr };
    check_hresult(WINRT_SHIM(IImageScanner)->get_FeederConfiguration(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Scanners::ImageScannerAutoConfiguration impl_IImageScanner<D>::AutoConfiguration() const
{
    Windows::Devices::Scanners::ImageScannerAutoConfiguration value { nullptr };
    check_hresult(WINRT_SHIM(IImageScanner)->get_AutoConfiguration(put_abi(value)));
    return value;
}

template <typename D> bool impl_IImageScanner<D>::IsPreviewSupported(Windows::Devices::Scanners::ImageScannerScanSource scanSource) const
{
    bool result {};
    check_hresult(WINRT_SHIM(IImageScanner)->abi_IsPreviewSupported(scanSource, &result));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Scanners::ImageScannerPreviewResult> impl_IImageScanner<D>::ScanPreviewToStreamAsync(Windows::Devices::Scanners::ImageScannerScanSource scanSource, const Windows::Storage::Streams::IRandomAccessStream & targetStream) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Scanners::ImageScannerPreviewResult> operation;
    check_hresult(WINRT_SHIM(IImageScanner)->abi_ScanPreviewToStreamAsync(scanSource, get_abi(targetStream), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Devices::Scanners::ImageScannerScanResult, uint32_t> impl_IImageScanner<D>::ScanFilesToFolderAsync(Windows::Devices::Scanners::ImageScannerScanSource scanSource, const Windows::Storage::StorageFolder & storageFolder) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Devices::Scanners::ImageScannerScanResult, uint32_t> operation;
    check_hresult(WINRT_SHIM(IImageScanner)->abi_ScanFilesToFolderAsync(scanSource, get_abi(storageFolder), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Scanners::ImageScanner> impl_IImageScannerStatics<D>::FromIdAsync(hstring_view deviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Scanners::ImageScanner> asyncInfo;
    check_hresult(WINRT_SHIM(IImageScannerStatics)->abi_FromIdAsync(get_abi(deviceId), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> hstring impl_IImageScannerStatics<D>::GetDeviceSelector() const
{
    hstring selector;
    check_hresult(WINRT_SHIM(IImageScannerStatics)->abi_GetDeviceSelector(put_abi(selector)));
    return selector;
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Scanners::ImageScanner> ImageScanner::FromIdAsync(hstring_view deviceId)
{
    return get_activation_factory<ImageScanner, IImageScannerStatics>().FromIdAsync(deviceId);
}

inline hstring ImageScanner::GetDeviceSelector()
{
    return get_activation_factory<ImageScanner, IImageScannerStatics>().GetDeviceSelector();
}

}

}
#pragma warning(pop)
