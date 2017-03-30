// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Scanners {

struct ImageScannerResolution;

}

namespace Windows::Devices::Scanners {

using ImageScannerResolution = ABI::Windows::Devices::Scanners::ImageScannerResolution;

}

namespace ABI::Windows::Devices::Scanners {

struct IImageScanner;
struct IImageScannerFeederConfiguration;
struct IImageScannerFormatConfiguration;
struct IImageScannerPreviewResult;
struct IImageScannerScanResult;
struct IImageScannerSourceConfiguration;
struct IImageScannerStatics;
struct ImageScanner;
struct ImageScannerAutoConfiguration;
struct ImageScannerFeederConfiguration;
struct ImageScannerFlatbedConfiguration;
struct ImageScannerPreviewResult;
struct ImageScannerScanResult;

}

namespace Windows::Devices::Scanners {

struct IImageScanner;
struct IImageScannerFeederConfiguration;
struct IImageScannerFormatConfiguration;
struct IImageScannerPreviewResult;
struct IImageScannerScanResult;
struct IImageScannerSourceConfiguration;
struct IImageScannerStatics;
struct ImageScanner;
struct ImageScannerAutoConfiguration;
struct ImageScannerFeederConfiguration;
struct ImageScannerFlatbedConfiguration;
struct ImageScannerPreviewResult;
struct ImageScannerScanResult;

}

namespace Windows::Devices::Scanners {

template <typename T> struct impl_IImageScanner;
template <typename T> struct impl_IImageScannerFeederConfiguration;
template <typename T> struct impl_IImageScannerFormatConfiguration;
template <typename T> struct impl_IImageScannerPreviewResult;
template <typename T> struct impl_IImageScannerScanResult;
template <typename T> struct impl_IImageScannerSourceConfiguration;
template <typename T> struct impl_IImageScannerStatics;

}

namespace Windows::Devices::Scanners {

enum class ImageScannerAutoCroppingMode
{
    Disabled = 0,
    SingleRegion = 1,
    MultipleRegion = 2,
};

enum class ImageScannerColorMode
{
    Color = 0,
    Grayscale = 1,
    Monochrome = 2,
    AutoColor = 3,
};

enum class ImageScannerFormat
{
    Jpeg = 0,
    Png = 1,
    DeviceIndependentBitmap = 2,
    Tiff = 3,
    Xps = 4,
    OpenXps = 5,
    Pdf = 6,
};

enum class ImageScannerScanSource
{
    Default = 0,
    Flatbed = 1,
    Feeder = 2,
    AutoConfigured = 3,
};

}

}
