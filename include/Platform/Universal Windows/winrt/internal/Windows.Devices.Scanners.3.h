// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Scanners.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::Scanners {

struct WINRT_EBO ImageScanner :
    Windows::Devices::Scanners::IImageScanner
{
    ImageScanner(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Devices::Scanners::ImageScanner> FromIdAsync(hstring_view deviceId);
    static hstring GetDeviceSelector();
};

struct WINRT_EBO ImageScannerAutoConfiguration :
    Windows::Devices::Scanners::IImageScannerFormatConfiguration
{
    ImageScannerAutoConfiguration(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ImageScannerFeederConfiguration :
    Windows::Devices::Scanners::IImageScannerFormatConfiguration,
    impl::require<ImageScannerFeederConfiguration, Windows::Devices::Scanners::IImageScannerSourceConfiguration, Windows::Devices::Scanners::IImageScannerFeederConfiguration>
{
    ImageScannerFeederConfiguration(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ImageScannerFlatbedConfiguration :
    Windows::Devices::Scanners::IImageScannerFormatConfiguration,
    impl::require<ImageScannerFlatbedConfiguration, Windows::Devices::Scanners::IImageScannerSourceConfiguration>
{
    ImageScannerFlatbedConfiguration(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ImageScannerPreviewResult :
    Windows::Devices::Scanners::IImageScannerPreviewResult
{
    ImageScannerPreviewResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ImageScannerScanResult :
    Windows::Devices::Scanners::IImageScannerScanResult
{
    ImageScannerScanResult(std::nullptr_t) noexcept {}
};

}

}
