// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Scanners.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_80646519_5e2a_595d_a8cd_2a24b4067f1b
#define WINRT_GENERIC_80646519_5e2a_595d_a8cd_2a24b4067f1b
template <> struct __declspec(uuid("80646519-5e2a-595d-a8cd-2a24b4067f1b")) __declspec(novtable) IVectorView<Windows::Storage::StorageFile> : impl_IVectorView<Windows::Storage::StorageFile> {};
#endif

#ifndef WINRT_GENERIC_9ac00304_83ea_5688_87b6_ae38aab65d0b
#define WINRT_GENERIC_9ac00304_83ea_5688_87b6_ae38aab65d0b
template <> struct __declspec(uuid("9ac00304-83ea-5688-87b6-ae38aab65d0b")) __declspec(novtable) IIterable<Windows::Storage::StorageFile> : impl_IIterable<Windows::Storage::StorageFile> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_2f74576f_0498_5348_bc3b_a70d1a771718
#define WINRT_GENERIC_2f74576f_0498_5348_bc3b_a70d1a771718
template <> struct __declspec(uuid("2f74576f-0498-5348-bc3b-a70d1a771718")) __declspec(novtable) IAsyncOperation<Windows::Devices::Scanners::ImageScannerPreviewResult> : impl_IAsyncOperation<Windows::Devices::Scanners::ImageScannerPreviewResult> {};
#endif

#ifndef WINRT_GENERIC_6e6e228a_f618_5d33_8523_02d16672665b
#define WINRT_GENERIC_6e6e228a_f618_5d33_8523_02d16672665b
template <> struct __declspec(uuid("6e6e228a-f618-5d33-8523-02d16672665b")) __declspec(novtable) IAsyncOperationWithProgress<Windows::Devices::Scanners::ImageScannerScanResult, uint32_t> : impl_IAsyncOperationWithProgress<Windows::Devices::Scanners::ImageScannerScanResult, uint32_t> {};
#endif

#ifndef WINRT_GENERIC_75d78736_6c52_551e_ab5f_50674f323431
#define WINRT_GENERIC_75d78736_6c52_551e_ab5f_50674f323431
template <> struct __declspec(uuid("75d78736-6c52-551e-ab5f-50674f323431")) __declspec(novtable) IAsyncOperation<Windows::Devices::Scanners::ImageScanner> : impl_IAsyncOperation<Windows::Devices::Scanners::ImageScanner> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_43e29f53_0298_55aa_a6c8_4edd323d9598
#define WINRT_GENERIC_43e29f53_0298_55aa_a6c8_4edd323d9598
template <> struct __declspec(uuid("43e29f53-0298-55aa-a6c8-4edd323d9598")) __declspec(novtable) IIterator<Windows::Storage::StorageFile> : impl_IIterator<Windows::Storage::StorageFile> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_c054a410_ac3c_5353_b1ee_e85e78faf3f1
#define WINRT_GENERIC_c054a410_ac3c_5353_b1ee_e85e78faf3f1
template <> struct __declspec(uuid("c054a410-ac3c-5353-b1ee-e85e78faf3f1")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Scanners::ImageScannerPreviewResult> : impl_AsyncOperationCompletedHandler<Windows::Devices::Scanners::ImageScannerPreviewResult> {};
#endif

#ifndef WINRT_GENERIC_d1662baa_4f20_5d18_97f1_a01a6d0dd980
#define WINRT_GENERIC_d1662baa_4f20_5d18_97f1_a01a6d0dd980
template <> struct __declspec(uuid("d1662baa-4f20-5d18-97f1-a01a6d0dd980")) __declspec(novtable) AsyncOperationProgressHandler<Windows::Devices::Scanners::ImageScannerScanResult, uint32_t> : impl_AsyncOperationProgressHandler<Windows::Devices::Scanners::ImageScannerScanResult, uint32_t> {};
#endif

#ifndef WINRT_GENERIC_bd8bdbd8_459a_52dc_b101_75b398a61aef
#define WINRT_GENERIC_bd8bdbd8_459a_52dc_b101_75b398a61aef
template <> struct __declspec(uuid("bd8bdbd8-459a-52dc-b101-75b398a61aef")) __declspec(novtable) AsyncOperationWithProgressCompletedHandler<Windows::Devices::Scanners::ImageScannerScanResult, uint32_t> : impl_AsyncOperationWithProgressCompletedHandler<Windows::Devices::Scanners::ImageScannerScanResult, uint32_t> {};
#endif

#ifndef WINRT_GENERIC_b35ad6b4_0da0_5241_87ff_eef3a1883243
#define WINRT_GENERIC_b35ad6b4_0da0_5241_87ff_eef3a1883243
template <> struct __declspec(uuid("b35ad6b4-0da0-5241-87ff-eef3a1883243")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Scanners::ImageScanner> : impl_AsyncOperationCompletedHandler<Windows::Devices::Scanners::ImageScanner> {};
#endif


}

namespace Windows::Devices::Scanners {

struct IImageScanner :
    Windows::Foundation::IInspectable,
    impl::consume<IImageScanner>
{
    IImageScanner(std::nullptr_t = nullptr) noexcept {}
};

struct IImageScannerFeederConfiguration :
    Windows::Foundation::IInspectable,
    impl::consume<IImageScannerFeederConfiguration>,
    impl::require<IImageScannerFeederConfiguration, Windows::Devices::Scanners::IImageScannerFormatConfiguration, Windows::Devices::Scanners::IImageScannerSourceConfiguration>
{
    IImageScannerFeederConfiguration(std::nullptr_t = nullptr) noexcept {}
};

struct IImageScannerFormatConfiguration :
    Windows::Foundation::IInspectable,
    impl::consume<IImageScannerFormatConfiguration>
{
    IImageScannerFormatConfiguration(std::nullptr_t = nullptr) noexcept {}
};

struct IImageScannerPreviewResult :
    Windows::Foundation::IInspectable,
    impl::consume<IImageScannerPreviewResult>
{
    IImageScannerPreviewResult(std::nullptr_t = nullptr) noexcept {}
};

struct IImageScannerScanResult :
    Windows::Foundation::IInspectable,
    impl::consume<IImageScannerScanResult>
{
    IImageScannerScanResult(std::nullptr_t = nullptr) noexcept {}
};

struct IImageScannerSourceConfiguration :
    Windows::Foundation::IInspectable,
    impl::consume<IImageScannerSourceConfiguration>,
    impl::require<IImageScannerSourceConfiguration, Windows::Devices::Scanners::IImageScannerFormatConfiguration>
{
    IImageScannerSourceConfiguration(std::nullptr_t = nullptr) noexcept {}
};

struct IImageScannerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IImageScannerStatics>
{
    IImageScannerStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
