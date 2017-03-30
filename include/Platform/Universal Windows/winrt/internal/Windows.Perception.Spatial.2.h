// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Perception.Spatial.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
#define WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
template <> struct __declspec(uuid("cdb5efb3-5788-509d-9be1-71ccb8a3362a")) __declspec(novtable) IAsyncOperation<bool> : impl_IAsyncOperation<bool> {};
#endif

#ifndef WINRT_GENERIC_2f2d6c29_5473_5f3e_92e7_96572bb990e2
#define WINRT_GENERIC_2f2d6c29_5473_5f3e_92e7_96572bb990e2
template <> struct __declspec(uuid("2f2d6c29-5473-5f3e-92e7-96572bb990e2")) __declspec(novtable) IReference<double> : impl_IReference<double> {};
#endif

#ifndef WINRT_GENERIC_dacbffdc_68ef_5fd0_b657_782d0ac9807e
#define WINRT_GENERIC_dacbffdc_68ef_5fd0_b657_782d0ac9807e
template <> struct __declspec(uuid("dacbffdc-68ef-5fd0-b657-782d0ac9807e")) __declspec(novtable) IReference<Windows::Foundation::Numerics::float4x4> : impl_IReference<Windows::Foundation::Numerics::float4x4> {};
#endif

#ifndef WINRT_GENERIC_fa43f9e4_3558_59c8_9a77_6e8b765adcc8
#define WINRT_GENERIC_fa43f9e4_3558_59c8_9a77_6e8b765adcc8
template <> struct __declspec(uuid("fa43f9e4-3558-59c8-9a77-6e8b765adcc8")) __declspec(novtable) TypedEventHandler<Windows::Perception::Spatial::SpatialAnchor, Windows::Perception::Spatial::SpatialAnchorRawCoordinateSystemAdjustedEventArgs> : impl_TypedEventHandler<Windows::Perception::Spatial::SpatialAnchor, Windows::Perception::Spatial::SpatialAnchorRawCoordinateSystemAdjustedEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_2d344564_21b1_5470_b013_488cdde45c48
#define WINRT_GENERIC_2d344564_21b1_5470_b013_488cdde45c48
template <> struct __declspec(uuid("2d344564-21b1-5470-b013-488cdde45c48")) __declspec(novtable) IMapView<hstring, Windows::Perception::Spatial::SpatialAnchor> : impl_IMapView<hstring, Windows::Perception::Spatial::SpatialAnchor> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_1cd05e51_1457_5023_8f5d_fe5e5a953423
#define WINRT_GENERIC_1cd05e51_1457_5023_8f5d_fe5e5a953423
template <> struct __declspec(uuid("1cd05e51-1457-5023-8f5d-fe5e5a953423")) __declspec(novtable) IAsyncOperation<Windows::Perception::Spatial::SpatialAnchorStore> : impl_IAsyncOperation<Windows::Perception::Spatial::SpatialAnchorStore> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_627298e7_068d_53f6_9154_d7d8d8091463
#define WINRT_GENERIC_627298e7_068d_53f6_9154_d7d8d8091463
template <> struct __declspec(uuid("627298e7-068d-53f6-9154-d7d8d8091463")) __declspec(novtable) IKeyValuePair<hstring, Windows::Perception::Spatial::SpatialAnchor> : impl_IKeyValuePair<hstring, Windows::Perception::Spatial::SpatialAnchor> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_b425d126_1069_563f_a863_44a30a8f071d
#define WINRT_GENERIC_b425d126_1069_563f_a863_44a30a8f071d
template <> struct __declspec(uuid("b425d126-1069-563f-a863-44a30a8f071d")) __declspec(novtable) IAsyncOperation<winrt::Windows::Perception::Spatial::SpatialPerceptionAccessStatus> : impl_IAsyncOperation<winrt::Windows::Perception::Spatial::SpatialPerceptionAccessStatus> {};
#endif

#ifndef WINRT_GENERIC_dbb08ab5_6b40_55fb_83d3_50d5373a3b20
#define WINRT_GENERIC_dbb08ab5_6b40_55fb_83d3_50d5373a3b20
template <> struct __declspec(uuid("dbb08ab5-6b40-55fb-83d3-50d5373a3b20")) __declspec(novtable) TypedEventHandler<Windows::Perception::Spatial::SpatialLocator, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Perception::Spatial::SpatialLocator, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_34bf236c_e5d6_501f_8693_bc1d8d431d7e
#define WINRT_GENERIC_34bf236c_e5d6_501f_8693_bc1d8d431d7e
template <> struct __declspec(uuid("34bf236c-e5d6-501f-8693-bc1d8d431d7e")) __declspec(novtable) TypedEventHandler<Windows::Perception::Spatial::SpatialLocator, Windows::Perception::Spatial::SpatialLocatorPositionalTrackingDeactivatingEventArgs> : impl_TypedEventHandler<Windows::Perception::Spatial::SpatialLocator, Windows::Perception::Spatial::SpatialLocatorPositionalTrackingDeactivatingEventArgs> {};
#endif

#ifndef WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
#define WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
template <> struct __declspec(uuid("c1d3d1a2-ae17-5a5f-b5a2-bdcc8844889a")) __declspec(novtable) AsyncOperationCompletedHandler<bool> : impl_AsyncOperationCompletedHandler<bool> {};
#endif

#ifndef WINRT_GENERIC_84c21a3a_037a_503f_8006_ab577b7f6f66
#define WINRT_GENERIC_84c21a3a_037a_503f_8006_ab577b7f6f66
template <> struct __declspec(uuid("84c21a3a-037a-503f-8006-ab577b7f6f66")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Perception::Spatial::SpatialAnchorStore> : impl_AsyncOperationCompletedHandler<Windows::Perception::Spatial::SpatialAnchorStore> {};
#endif

#ifndef WINRT_GENERIC_6ced54c8_7689_525a_80e1_956a9d85cd83
#define WINRT_GENERIC_6ced54c8_7689_525a_80e1_956a9d85cd83
template <> struct __declspec(uuid("6ced54c8-7689-525a-80e1-956a9d85cd83")) __declspec(novtable) AsyncOperationCompletedHandler<winrt::Windows::Perception::Spatial::SpatialPerceptionAccessStatus> : impl_AsyncOperationCompletedHandler<winrt::Windows::Perception::Spatial::SpatialPerceptionAccessStatus> {};
#endif

#ifndef WINRT_GENERIC_bbe07728_da33_52c5_aae0_a5e74cdf0471
#define WINRT_GENERIC_bbe07728_da33_52c5_aae0_a5e74cdf0471
template <> struct __declspec(uuid("bbe07728-da33-52c5-aae0-a5e74cdf0471")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IMapView<hstring, Windows::Perception::Spatial::SpatialAnchor>> : impl_IAsyncOperation<Windows::Foundation::Collections::IMapView<hstring, Windows::Perception::Spatial::SpatialAnchor>> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_55f0fa8a_afd4_5541_a1c3_36f12147d606
#define WINRT_GENERIC_55f0fa8a_afd4_5541_a1c3_36f12147d606
template <> struct __declspec(uuid("55f0fa8a-afd4-5541-a1c3-36f12147d606")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Perception::Spatial::SpatialAnchor>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Perception::Spatial::SpatialAnchor>> {};
#endif

#ifndef WINRT_GENERIC_67a5f318_0232_5900_ac7e_5c647d731cbc
#define WINRT_GENERIC_67a5f318_0232_5900_ac7e_5c647d731cbc
template <> struct __declspec(uuid("67a5f318-0232-5900-ac7e-5c647d731cbc")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Perception::Spatial::SpatialAnchor>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Perception::Spatial::SpatialAnchor>> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_3a950aa3_9c65_586e_af75_1acf07190e90
#define WINRT_GENERIC_3a950aa3_9c65_586e_af75_1acf07190e90
template <> struct __declspec(uuid("3a950aa3-9c65-586e-af75-1acf07190e90")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IMapView<hstring, Windows::Perception::Spatial::SpatialAnchor>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IMapView<hstring, Windows::Perception::Spatial::SpatialAnchor>> {};
#endif


}

namespace Windows::Perception::Spatial {

struct ISpatialAnchor :
    Windows::Foundation::IInspectable,
    impl::consume<ISpatialAnchor>
{
    ISpatialAnchor(std::nullptr_t = nullptr) noexcept {}
};

struct ISpatialAnchor2 :
    Windows::Foundation::IInspectable,
    impl::consume<ISpatialAnchor2>
{
    ISpatialAnchor2(std::nullptr_t = nullptr) noexcept {}
};

struct ISpatialAnchorManagerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISpatialAnchorManagerStatics>
{
    ISpatialAnchorManagerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISpatialAnchorRawCoordinateSystemAdjustedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ISpatialAnchorRawCoordinateSystemAdjustedEventArgs>
{
    ISpatialAnchorRawCoordinateSystemAdjustedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ISpatialAnchorStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISpatialAnchorStatics>
{
    ISpatialAnchorStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISpatialAnchorStore :
    Windows::Foundation::IInspectable,
    impl::consume<ISpatialAnchorStore>
{
    ISpatialAnchorStore(std::nullptr_t = nullptr) noexcept {}
};

struct ISpatialAnchorTransferManagerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISpatialAnchorTransferManagerStatics>
{
    ISpatialAnchorTransferManagerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISpatialBoundingVolume :
    Windows::Foundation::IInspectable,
    impl::consume<ISpatialBoundingVolume>
{
    ISpatialBoundingVolume(std::nullptr_t = nullptr) noexcept {}
};

struct ISpatialBoundingVolumeStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISpatialBoundingVolumeStatics>
{
    ISpatialBoundingVolumeStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISpatialCoordinateSystem :
    Windows::Foundation::IInspectable,
    impl::consume<ISpatialCoordinateSystem>
{
    ISpatialCoordinateSystem(std::nullptr_t = nullptr) noexcept {}
};

struct ISpatialLocation :
    Windows::Foundation::IInspectable,
    impl::consume<ISpatialLocation>
{
    ISpatialLocation(std::nullptr_t = nullptr) noexcept {}
};

struct ISpatialLocator :
    Windows::Foundation::IInspectable,
    impl::consume<ISpatialLocator>
{
    ISpatialLocator(std::nullptr_t = nullptr) noexcept {}
};

struct ISpatialLocatorAttachedFrameOfReference :
    Windows::Foundation::IInspectable,
    impl::consume<ISpatialLocatorAttachedFrameOfReference>
{
    ISpatialLocatorAttachedFrameOfReference(std::nullptr_t = nullptr) noexcept {}
};

struct ISpatialLocatorPositionalTrackingDeactivatingEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ISpatialLocatorPositionalTrackingDeactivatingEventArgs>
{
    ISpatialLocatorPositionalTrackingDeactivatingEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ISpatialLocatorStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISpatialLocatorStatics>
{
    ISpatialLocatorStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISpatialStationaryFrameOfReference :
    Windows::Foundation::IInspectable,
    impl::consume<ISpatialStationaryFrameOfReference>
{
    ISpatialStationaryFrameOfReference(std::nullptr_t = nullptr) noexcept {}
};

}

}
