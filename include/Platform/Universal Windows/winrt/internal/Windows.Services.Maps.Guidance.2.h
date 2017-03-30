// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Services.Maps.Guidance.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
#define WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
template <> struct __declspec(uuid("2f13c006-a03a-5f69-b090-75a43e33423e")) __declspec(novtable) IVectorView<hstring> : impl_IVectorView<hstring> {};
#endif

#ifndef WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
#define WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
template <> struct __declspec(uuid("e2fcc7c1-3bfc-5a0b-b2b0-72e769d1cb7e")) __declspec(novtable) IIterable<hstring> : impl_IIterable<hstring> {};
#endif

#ifndef WINRT_GENERIC_81493670_e515_5c62_b34c_6e3d996cad31
#define WINRT_GENERIC_81493670_e515_5c62_b34c_6e3d996cad31
template <> struct __declspec(uuid("81493670-e515-5c62-b34c-6e3d996cad31")) __declspec(novtable) IVectorView<Windows::Services::Maps::Guidance::GuidanceLaneInfo> : impl_IVectorView<Windows::Services::Maps::Guidance::GuidanceLaneInfo> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_82b3f7df_bf13_5445_aadc_ec61b50fbb46
#define WINRT_GENERIC_82b3f7df_bf13_5445_aadc_ec61b50fbb46
template <> struct __declspec(uuid("82b3f7df-bf13-5445-aadc-ec61b50fbb46")) __declspec(novtable) TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Services::Maps::Guidance::GuidanceUpdatedEventArgs> : impl_TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Services::Maps::Guidance::GuidanceUpdatedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_3f496c35_3dca_5e91_8730_6ef77e9d70bd
#define WINRT_GENERIC_3f496c35_3dca_5e91_8730_6ef77e9d70bd
template <> struct __declspec(uuid("3f496c35-3dca-5e91-8730-6ef77e9d70bd")) __declspec(novtable) TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_61b92b1b_f22f_581b_bfa0_4868c314c63a
#define WINRT_GENERIC_61b92b1b_f22f_581b_bfa0_4868c314c63a
template <> struct __declspec(uuid("61b92b1b-f22f-581b-bfa0-4868c314c63a")) __declspec(novtable) TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Services::Maps::Guidance::GuidanceReroutedEventArgs> : impl_TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Services::Maps::Guidance::GuidanceReroutedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_743db36f_e9aa_557a_9fd7_304c9b0499df
#define WINRT_GENERIC_743db36f_e9aa_557a_9fd7_304c9b0499df
template <> struct __declspec(uuid("743db36f-e9aa-557a-9fd7-304c9b0499df")) __declspec(novtable) TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Services::Maps::Guidance::GuidanceAudioNotificationRequestedEventArgs> : impl_TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Services::Maps::Guidance::GuidanceAudioNotificationRequestedEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_875644d8_57a4_59d6_9d2c_5d450d39d2f6
#define WINRT_GENERIC_875644d8_57a4_59d6_9d2c_5d450d39d2f6
template <> struct __declspec(uuid("875644d8-57a4-59d6-9d2c-5d450d39d2f6")) __declspec(novtable) IVectorView<Windows::Services::Maps::Guidance::GuidanceManeuver> : impl_IVectorView<Windows::Services::Maps::Guidance::GuidanceManeuver> {};
#endif

#ifndef WINRT_GENERIC_f04c7cc2_4d54_5244_beb2_8f4f05c184e6
#define WINRT_GENERIC_f04c7cc2_4d54_5244_beb2_8f4f05c184e6
template <> struct __declspec(uuid("f04c7cc2-4d54-5244-beb2-8f4f05c184e6")) __declspec(novtable) IVectorView<Windows::Services::Maps::Guidance::GuidanceRoadSegment> : impl_IVectorView<Windows::Services::Maps::Guidance::GuidanceRoadSegment> {};
#endif

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif

#ifndef WINRT_GENERIC_4d4ce4d8_7ce0_5168_ab29_6bcf7f198a58
#define WINRT_GENERIC_4d4ce4d8_7ce0_5168_ab29_6bcf7f198a58
template <> struct __declspec(uuid("4d4ce4d8-7ce0-5168-ab29-6bcf7f198a58")) __declspec(novtable) IIterator<Windows::Services::Maps::Guidance::GuidanceLaneInfo> : impl_IIterator<Windows::Services::Maps::Guidance::GuidanceLaneInfo> {};
#endif

#ifndef WINRT_GENERIC_45960d72_1bf6_5a1d_a17f_e83f56f1ab57
#define WINRT_GENERIC_45960d72_1bf6_5a1d_a17f_e83f56f1ab57
template <> struct __declspec(uuid("45960d72-1bf6-5a1d-a17f-e83f56f1ab57")) __declspec(novtable) IIterable<Windows::Services::Maps::Guidance::GuidanceLaneInfo> : impl_IIterable<Windows::Services::Maps::Guidance::GuidanceLaneInfo> {};
#endif

#ifndef WINRT_GENERIC_74a37092_2641_5c3d_b3cb_689dc8aba22e
#define WINRT_GENERIC_74a37092_2641_5c3d_b3cb_689dc8aba22e
template <> struct __declspec(uuid("74a37092-2641-5c3d-b3cb-689dc8aba22e")) __declspec(novtable) IIterator<Windows::Services::Maps::Guidance::GuidanceManeuver> : impl_IIterator<Windows::Services::Maps::Guidance::GuidanceManeuver> {};
#endif

#ifndef WINRT_GENERIC_b5780d67_8a8b_558f_a4b6_c4531ef32ec8
#define WINRT_GENERIC_b5780d67_8a8b_558f_a4b6_c4531ef32ec8
template <> struct __declspec(uuid("b5780d67-8a8b-558f-a4b6-c4531ef32ec8")) __declspec(novtable) IIterable<Windows::Services::Maps::Guidance::GuidanceManeuver> : impl_IIterable<Windows::Services::Maps::Guidance::GuidanceManeuver> {};
#endif

#ifndef WINRT_GENERIC_148cb8ff_3ab9_53ab_8824_256a62047b43
#define WINRT_GENERIC_148cb8ff_3ab9_53ab_8824_256a62047b43
template <> struct __declspec(uuid("148cb8ff-3ab9-53ab-8824-256a62047b43")) __declspec(novtable) IIterator<Windows::Services::Maps::Guidance::GuidanceRoadSegment> : impl_IIterator<Windows::Services::Maps::Guidance::GuidanceRoadSegment> {};
#endif

#ifndef WINRT_GENERIC_f7c614c4_0fca_5eda_804c_85c829956334
#define WINRT_GENERIC_f7c614c4_0fca_5eda_804c_85c829956334
template <> struct __declspec(uuid("f7c614c4-0fca-5eda-804c-85c829956334")) __declspec(novtable) IIterable<Windows::Services::Maps::Guidance::GuidanceRoadSegment> : impl_IIterable<Windows::Services::Maps::Guidance::GuidanceRoadSegment> {};
#endif


}

namespace Windows::Services::Maps::Guidance {

struct IGuidanceAudioNotificationRequestedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IGuidanceAudioNotificationRequestedEventArgs>
{
    IGuidanceAudioNotificationRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IGuidanceLaneInfo :
    Windows::Foundation::IInspectable,
    impl::consume<IGuidanceLaneInfo>
{
    IGuidanceLaneInfo(std::nullptr_t = nullptr) noexcept {}
};

struct IGuidanceManeuver :
    Windows::Foundation::IInspectable,
    impl::consume<IGuidanceManeuver>
{
    IGuidanceManeuver(std::nullptr_t = nullptr) noexcept {}
};

struct IGuidanceMapMatchedCoordinate :
    Windows::Foundation::IInspectable,
    impl::consume<IGuidanceMapMatchedCoordinate>
{
    IGuidanceMapMatchedCoordinate(std::nullptr_t = nullptr) noexcept {}
};

struct IGuidanceNavigator :
    Windows::Foundation::IInspectable,
    impl::consume<IGuidanceNavigator>
{
    IGuidanceNavigator(std::nullptr_t = nullptr) noexcept {}
};

struct IGuidanceNavigator2 :
    Windows::Foundation::IInspectable,
    impl::consume<IGuidanceNavigator2>
{
    IGuidanceNavigator2(std::nullptr_t = nullptr) noexcept {}
};

struct IGuidanceNavigatorStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IGuidanceNavigatorStatics>
{
    IGuidanceNavigatorStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IGuidanceNavigatorStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IGuidanceNavigatorStatics2>
{
    IGuidanceNavigatorStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IGuidanceReroutedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IGuidanceReroutedEventArgs>
{
    IGuidanceReroutedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IGuidanceRoadSegment :
    Windows::Foundation::IInspectable,
    impl::consume<IGuidanceRoadSegment>
{
    IGuidanceRoadSegment(std::nullptr_t = nullptr) noexcept {}
};

struct IGuidanceRoadSignpost :
    Windows::Foundation::IInspectable,
    impl::consume<IGuidanceRoadSignpost>
{
    IGuidanceRoadSignpost(std::nullptr_t = nullptr) noexcept {}
};

struct IGuidanceRoute :
    Windows::Foundation::IInspectable,
    impl::consume<IGuidanceRoute>
{
    IGuidanceRoute(std::nullptr_t = nullptr) noexcept {}
};

struct IGuidanceRouteStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IGuidanceRouteStatics>
{
    IGuidanceRouteStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IGuidanceTelemetryCollector :
    Windows::Foundation::IInspectable,
    impl::consume<IGuidanceTelemetryCollector>
{
    IGuidanceTelemetryCollector(std::nullptr_t = nullptr) noexcept {}
};

struct IGuidanceTelemetryCollectorStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IGuidanceTelemetryCollectorStatics>
{
    IGuidanceTelemetryCollectorStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IGuidanceUpdatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IGuidanceUpdatedEventArgs>
{
    IGuidanceUpdatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

}

}
