// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.Devices.Core.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_513ef3af_e784_5325_a91e_97c2b8111cf3
#define WINRT_GENERIC_513ef3af_e784_5325_a91e_97c2b8111cf3
template <> struct __declspec(uuid("513ef3af-e784-5325-a91e-97c2b8111cf3")) __declspec(novtable) IReference<uint32_t> : impl_IReference<uint32_t> {};
#endif

#ifndef WINRT_GENERIC_604d0c4c_91de_5c2a_935f_362f13eaf800
#define WINRT_GENERIC_604d0c4c_91de_5c2a_935f_362f13eaf800
template <> struct __declspec(uuid("604d0c4c-91de-5c2a-935f-362f13eaf800")) __declspec(novtable) IReference<Windows::Foundation::TimeSpan> : impl_IReference<Windows::Foundation::TimeSpan> {};
#endif

#ifndef WINRT_GENERIC_3c00fd60_2950_5939_a21a_2d12c5a01b8a
#define WINRT_GENERIC_3c00fd60_2950_5939_a21a_2d12c5a01b8a
template <> struct __declspec(uuid("3c00fd60-2950-5939-a21a-2d12c5a01b8a")) __declspec(novtable) IReference<bool> : impl_IReference<bool> {};
#endif

#ifndef WINRT_GENERIC_719cc2ba_3e76_5def_9f1a_38d85a145ea8
#define WINRT_GENERIC_719cc2ba_3e76_5def_9f1a_38d85a145ea8
template <> struct __declspec(uuid("719cc2ba-3e76-5def-9f1a-38d85a145ea8")) __declspec(novtable) IReference<float> : impl_IReference<float> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_1c8f8276_b89a_5093_a1ed_af49dfb72a89
#define WINRT_GENERIC_1c8f8276_b89a_5093_a1ed_af49dfb72a89
template <> struct __declspec(uuid("1c8f8276-b89a-5093-a1ed-af49dfb72a89")) __declspec(novtable) IVector<Windows::Media::Devices::Core::FrameController> : impl_IVector<Windows::Media::Devices::Core::FrameController> {};
#endif

#ifndef WINRT_GENERIC_fcd6a2a3_b6ff_5572_912b_99ebaf95165d
#define WINRT_GENERIC_fcd6a2a3_b6ff_5572_912b_99ebaf95165d
template <> struct __declspec(uuid("fcd6a2a3-b6ff-5572-912b-99ebaf95165d")) __declspec(novtable) IVectorView<Windows::Media::Devices::Core::FrameController> : impl_IVectorView<Windows::Media::Devices::Core::FrameController> {};
#endif

#ifndef WINRT_GENERIC_1440dc88_63ff_5a01_bb93_390c76742488
#define WINRT_GENERIC_1440dc88_63ff_5a01_bb93_390c76742488
template <> struct __declspec(uuid("1440dc88-63ff-5a01-bb93-390c76742488")) __declspec(novtable) IIterator<Windows::Media::Devices::Core::FrameController> : impl_IIterator<Windows::Media::Devices::Core::FrameController> {};
#endif

#ifndef WINRT_GENERIC_bd8eeadc_2dd9_5ad8_ac5d_f3b13b94b9c2
#define WINRT_GENERIC_bd8eeadc_2dd9_5ad8_ac5d_f3b13b94b9c2
template <> struct __declspec(uuid("bd8eeadc-2dd9-5ad8-ac5d-f3b13b94b9c2")) __declspec(novtable) IIterable<Windows::Media::Devices::Core::FrameController> : impl_IIterable<Windows::Media::Devices::Core::FrameController> {};
#endif


}

namespace Windows::Media::Devices::Core {

struct ICameraIntrinsics :
    Windows::Foundation::IInspectable,
    impl::consume<ICameraIntrinsics>
{
    ICameraIntrinsics(std::nullptr_t = nullptr) noexcept {}
};

struct ICameraIntrinsics2 :
    Windows::Foundation::IInspectable,
    impl::consume<ICameraIntrinsics2>
{
    ICameraIntrinsics2(std::nullptr_t = nullptr) noexcept {}
};

struct ICameraIntrinsicsFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ICameraIntrinsicsFactory>
{
    ICameraIntrinsicsFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IDepthCorrelatedCoordinateMapper :
    Windows::Foundation::IInspectable,
    impl::consume<IDepthCorrelatedCoordinateMapper>,
    impl::require<IDepthCorrelatedCoordinateMapper, Windows::Foundation::IClosable>
{
    IDepthCorrelatedCoordinateMapper(std::nullptr_t = nullptr) noexcept {}
};

struct IFrameControlCapabilities :
    Windows::Foundation::IInspectable,
    impl::consume<IFrameControlCapabilities>
{
    IFrameControlCapabilities(std::nullptr_t = nullptr) noexcept {}
};

struct IFrameControlCapabilities2 :
    Windows::Foundation::IInspectable,
    impl::consume<IFrameControlCapabilities2>
{
    IFrameControlCapabilities2(std::nullptr_t = nullptr) noexcept {}
};

struct IFrameController :
    Windows::Foundation::IInspectable,
    impl::consume<IFrameController>
{
    IFrameController(std::nullptr_t = nullptr) noexcept {}
};

struct IFrameController2 :
    Windows::Foundation::IInspectable,
    impl::consume<IFrameController2>
{
    IFrameController2(std::nullptr_t = nullptr) noexcept {}
};

struct IFrameExposureCapabilities :
    Windows::Foundation::IInspectable,
    impl::consume<IFrameExposureCapabilities>
{
    IFrameExposureCapabilities(std::nullptr_t = nullptr) noexcept {}
};

struct IFrameExposureCompensationCapabilities :
    Windows::Foundation::IInspectable,
    impl::consume<IFrameExposureCompensationCapabilities>
{
    IFrameExposureCompensationCapabilities(std::nullptr_t = nullptr) noexcept {}
};

struct IFrameExposureCompensationControl :
    Windows::Foundation::IInspectable,
    impl::consume<IFrameExposureCompensationControl>
{
    IFrameExposureCompensationControl(std::nullptr_t = nullptr) noexcept {}
};

struct IFrameExposureControl :
    Windows::Foundation::IInspectable,
    impl::consume<IFrameExposureControl>
{
    IFrameExposureControl(std::nullptr_t = nullptr) noexcept {}
};

struct IFrameFlashCapabilities :
    Windows::Foundation::IInspectable,
    impl::consume<IFrameFlashCapabilities>
{
    IFrameFlashCapabilities(std::nullptr_t = nullptr) noexcept {}
};

struct IFrameFlashControl :
    Windows::Foundation::IInspectable,
    impl::consume<IFrameFlashControl>
{
    IFrameFlashControl(std::nullptr_t = nullptr) noexcept {}
};

struct IFrameFocusCapabilities :
    Windows::Foundation::IInspectable,
    impl::consume<IFrameFocusCapabilities>
{
    IFrameFocusCapabilities(std::nullptr_t = nullptr) noexcept {}
};

struct IFrameFocusControl :
    Windows::Foundation::IInspectable,
    impl::consume<IFrameFocusControl>
{
    IFrameFocusControl(std::nullptr_t = nullptr) noexcept {}
};

struct IFrameIsoSpeedCapabilities :
    Windows::Foundation::IInspectable,
    impl::consume<IFrameIsoSpeedCapabilities>
{
    IFrameIsoSpeedCapabilities(std::nullptr_t = nullptr) noexcept {}
};

struct IFrameIsoSpeedControl :
    Windows::Foundation::IInspectable,
    impl::consume<IFrameIsoSpeedControl>
{
    IFrameIsoSpeedControl(std::nullptr_t = nullptr) noexcept {}
};

struct IVariablePhotoSequenceController :
    Windows::Foundation::IInspectable,
    impl::consume<IVariablePhotoSequenceController>
{
    IVariablePhotoSequenceController(std::nullptr_t = nullptr) noexcept {}
};

}

}
