// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Store::Preview {

struct IStoreConfigurationStatics;
struct IStoreConfigurationStatics2;
struct IStoreConfigurationStatics3;
struct IStoreHardwareManufacturerInfo;
struct IStorePreview;
struct IStorePreviewProductInfo;
struct IStorePreviewPurchaseResults;
struct IStorePreviewSkuInfo;
struct StoreHardwareManufacturerInfo;
struct StorePreviewProductInfo;
struct StorePreviewPurchaseResults;
struct StorePreviewSkuInfo;

}

namespace Windows::ApplicationModel::Store::Preview {

struct IStoreConfigurationStatics;
struct IStoreConfigurationStatics2;
struct IStoreConfigurationStatics3;
struct IStoreHardwareManufacturerInfo;
struct IStorePreview;
struct IStorePreviewProductInfo;
struct IStorePreviewPurchaseResults;
struct IStorePreviewSkuInfo;
struct StoreConfiguration;
struct StoreHardwareManufacturerInfo;
struct StorePreview;
struct StorePreviewProductInfo;
struct StorePreviewPurchaseResults;
struct StorePreviewSkuInfo;

}

namespace Windows::ApplicationModel::Store::Preview {

template <typename T> struct impl_IStoreConfigurationStatics;
template <typename T> struct impl_IStoreConfigurationStatics2;
template <typename T> struct impl_IStoreConfigurationStatics3;
template <typename T> struct impl_IStoreHardwareManufacturerInfo;
template <typename T> struct impl_IStorePreview;
template <typename T> struct impl_IStorePreviewProductInfo;
template <typename T> struct impl_IStorePreviewPurchaseResults;
template <typename T> struct impl_IStorePreviewSkuInfo;

}

namespace Windows::ApplicationModel::Store::Preview {

enum class StoreLogOptions : unsigned
{
    None = 0x0,
    TryElevate = 0x1,
};

DEFINE_ENUM_FLAG_OPERATORS(StoreLogOptions)

enum class StorePreviewProductPurchaseStatus
{
    Succeeded = 0,
    AlreadyPurchased = 1,
    NotFulfilled = 2,
    NotPurchased = 3,
};

enum class StoreSystemFeature
{
    ArchitectureX86 = 0,
    ArchitectureX64 = 1,
    ArchitectureArm = 2,
    DirectX9 = 3,
    DirectX10 = 4,
    DirectX11 = 5,
    D3D12HardwareFL11 = 6,
    D3D12HardwareFL12 = 7,
    Memory300MB = 8,
    Memory750MB = 9,
    Memory1GB = 10,
    Memory2GB = 11,
    CameraFront = 12,
    CameraRear = 13,
    Gyroscope = 14,
    Hover = 15,
    Magnetometer = 16,
    Nfc = 17,
    Resolution720P = 18,
    ResolutionWvga = 19,
    ResolutionWvgaOr720P = 20,
    ResolutionWxga = 21,
    ResolutionWvgaOrWxga = 22,
    ResolutionWxgaOr720P = 23,
    Memory4GB = 24,
    Memory6GB = 25,
    Memory8GB = 26,
    Memory12GB = 27,
    Memory16GB = 28,
    Memory20GB = 29,
    VideoMemory2GB = 30,
    VideoMemory4GB = 31,
    VideoMemory6GB = 32,
    VideoMemory1GB = 33,
};

}

}
