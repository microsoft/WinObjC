// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Graphics.Holographic.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_71d80b7c_1d27_5102_83d1_4f0efc7c9d6f
#define WINRT_GENERIC_71d80b7c_1d27_5102_83d1_4f0efc7c9d6f
template <> struct __declspec(uuid("71d80b7c-1d27-5102-83d1-4f0efc7c9d6f")) __declspec(novtable) TypedEventHandler<Windows::Graphics::Holographic::HolographicSpace, Windows::Graphics::Holographic::HolographicSpaceCameraAddedEventArgs> : impl_TypedEventHandler<Windows::Graphics::Holographic::HolographicSpace, Windows::Graphics::Holographic::HolographicSpaceCameraAddedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_db68cfc3_0874_502a_a3b9_2b1fe86c67be
#define WINRT_GENERIC_db68cfc3_0874_502a_a3b9_2b1fe86c67be
template <> struct __declspec(uuid("db68cfc3-0874-502a-a3b9-2b1fe86c67be")) __declspec(novtable) TypedEventHandler<Windows::Graphics::Holographic::HolographicSpace, Windows::Graphics::Holographic::HolographicSpaceCameraRemovedEventArgs> : impl_TypedEventHandler<Windows::Graphics::Holographic::HolographicSpace, Windows::Graphics::Holographic::HolographicSpaceCameraRemovedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_6e67ce78_cc67_52c0_b635_991db0bff5ca
#define WINRT_GENERIC_6e67ce78_cc67_52c0_b635_991db0bff5ca
template <> struct __declspec(uuid("6e67ce78-cc67-52c0-b635-991db0bff5ca")) __declspec(novtable) IReference<Windows::Graphics::Holographic::HolographicStereoTransform> : impl_IReference<Windows::Graphics::Holographic::HolographicStereoTransform> {};
#endif

#ifndef WINRT_GENERIC_f434face_0c36_5749_a8a0_0bb6ce78a614
#define WINRT_GENERIC_f434face_0c36_5749_a8a0_0bb6ce78a614
template <> struct __declspec(uuid("f434face-0c36-5749-a8a0-0bb6ce78a614")) __declspec(novtable) IReference<Windows::Perception::Spatial::SpatialBoundingFrustum> : impl_IReference<Windows::Perception::Spatial::SpatialBoundingFrustum> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_17c5dfb1_6e87_5a17_a791_ac07f8ee9292
#define WINRT_GENERIC_17c5dfb1_6e87_5a17_a791_ac07f8ee9292
template <> struct __declspec(uuid("17c5dfb1-6e87-5a17-a791-ac07f8ee9292")) __declspec(novtable) IVectorView<Windows::Graphics::Holographic::HolographicCameraPose> : impl_IVectorView<Windows::Graphics::Holographic::HolographicCameraPose> {};
#endif

#ifndef WINRT_GENERIC_01d6c0ae_ada5_50b0_8562_41fb1205bb4a
#define WINRT_GENERIC_01d6c0ae_ada5_50b0_8562_41fb1205bb4a
template <> struct __declspec(uuid("01d6c0ae-ada5-50b0-8562-41fb1205bb4a")) __declspec(novtable) IVectorView<Windows::Graphics::Holographic::HolographicCamera> : impl_IVectorView<Windows::Graphics::Holographic::HolographicCamera> {};
#endif

#ifndef WINRT_GENERIC_93e27fb4_332b_591e_ae6b_6192fa0a1009
#define WINRT_GENERIC_93e27fb4_332b_591e_ae6b_6192fa0a1009
template <> struct __declspec(uuid("93e27fb4-332b-591e-ae6b-6192fa0a1009")) __declspec(novtable) IIterator<Windows::Graphics::Holographic::HolographicCameraPose> : impl_IIterator<Windows::Graphics::Holographic::HolographicCameraPose> {};
#endif

#ifndef WINRT_GENERIC_92111aff_8dcc_538e_ae3d_31fd252a0ad5
#define WINRT_GENERIC_92111aff_8dcc_538e_ae3d_31fd252a0ad5
template <> struct __declspec(uuid("92111aff-8dcc-538e-ae3d-31fd252a0ad5")) __declspec(novtable) IIterable<Windows::Graphics::Holographic::HolographicCameraPose> : impl_IIterable<Windows::Graphics::Holographic::HolographicCameraPose> {};
#endif

#ifndef WINRT_GENERIC_6acc8576_2fea_561d_84dd_4a1ab05fc7ed
#define WINRT_GENERIC_6acc8576_2fea_561d_84dd_4a1ab05fc7ed
template <> struct __declspec(uuid("6acc8576-2fea-561d-84dd-4a1ab05fc7ed")) __declspec(novtable) IIterator<Windows::Graphics::Holographic::HolographicCamera> : impl_IIterator<Windows::Graphics::Holographic::HolographicCamera> {};
#endif

#ifndef WINRT_GENERIC_b2afd154_8db0_5bb2_ad7a_684afd479264
#define WINRT_GENERIC_b2afd154_8db0_5bb2_ad7a_684afd479264
template <> struct __declspec(uuid("b2afd154-8db0-5bb2-ad7a-684afd479264")) __declspec(novtable) IIterable<Windows::Graphics::Holographic::HolographicCamera> : impl_IIterable<Windows::Graphics::Holographic::HolographicCamera> {};
#endif


}

namespace Windows::Graphics::Holographic {

struct IHolographicCamera :
    Windows::Foundation::IInspectable,
    impl::consume<IHolographicCamera>
{
    IHolographicCamera(std::nullptr_t = nullptr) noexcept {}
};

struct IHolographicCameraPose :
    Windows::Foundation::IInspectable,
    impl::consume<IHolographicCameraPose>
{
    IHolographicCameraPose(std::nullptr_t = nullptr) noexcept {}
};

struct IHolographicCameraRenderingParameters :
    Windows::Foundation::IInspectable,
    impl::consume<IHolographicCameraRenderingParameters>
{
    IHolographicCameraRenderingParameters(std::nullptr_t = nullptr) noexcept {}
};

struct IHolographicFrame :
    Windows::Foundation::IInspectable,
    impl::consume<IHolographicFrame>
{
    IHolographicFrame(std::nullptr_t = nullptr) noexcept {}
};

struct IHolographicFramePrediction :
    Windows::Foundation::IInspectable,
    impl::consume<IHolographicFramePrediction>
{
    IHolographicFramePrediction(std::nullptr_t = nullptr) noexcept {}
};

struct IHolographicSpace :
    Windows::Foundation::IInspectable,
    impl::consume<IHolographicSpace>
{
    IHolographicSpace(std::nullptr_t = nullptr) noexcept {}
};

struct IHolographicSpaceCameraAddedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IHolographicSpaceCameraAddedEventArgs>
{
    IHolographicSpaceCameraAddedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IHolographicSpaceCameraRemovedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IHolographicSpaceCameraRemovedEventArgs>
{
    IHolographicSpaceCameraRemovedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IHolographicSpaceStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IHolographicSpaceStatics>
{
    IHolographicSpaceStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
