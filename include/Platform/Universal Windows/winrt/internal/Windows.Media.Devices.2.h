// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.Devices.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_513ef3af_e784_5325_a91e_97c2b8111cf3
#define WINRT_GENERIC_513ef3af_e784_5325_a91e_97c2b8111cf3
template <> struct __declspec(uuid("513ef3af-e784-5325-a91e-97c2b8111cf3")) __declspec(novtable) IReference<uint32_t> : impl_IReference<uint32_t> {};
#endif

#ifndef WINRT_GENERIC_97d07327_2c78_57bc_98e6_a24cd024cf5b
#define WINRT_GENERIC_97d07327_2c78_57bc_98e6_a24cd024cf5b
template <> struct __declspec(uuid("97d07327-2c78-57bc-98e6-a24cd024cf5b")) __declspec(novtable) TypedEventHandler<Windows::Foundation::IInspectable, Windows::Media::Devices::DefaultAudioCaptureDeviceChangedEventArgs> : impl_TypedEventHandler<Windows::Foundation::IInspectable, Windows::Media::Devices::DefaultAudioCaptureDeviceChangedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_fd732aca_dafc_5b7d_bf72_b560b78d260c
#define WINRT_GENERIC_fd732aca_dafc_5b7d_bf72_b560b78d260c
template <> struct __declspec(uuid("fd732aca-dafc-5b7d-bf72-b560b78d260c")) __declspec(novtable) TypedEventHandler<Windows::Foundation::IInspectable, Windows::Media::Devices::DefaultAudioRenderDeviceChangedEventArgs> : impl_TypedEventHandler<Windows::Foundation::IInspectable, Windows::Media::Devices::DefaultAudioRenderDeviceChangedEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_9b915d69_e718_5b48_bb94_54bdf3737ea5
#define WINRT_GENERIC_9b915d69_e718_5b48_bb94_54bdf3737ea5
template <> struct __declspec(uuid("9b915d69-e718-5b48-bb94-54bdf3737ea5")) __declspec(novtable) IVectorView<winrt::Windows::Media::Devices::CaptureSceneMode> : impl_IVectorView<winrt::Windows::Media::Devices::CaptureSceneMode> {};
#endif

#ifndef WINRT_GENERIC_ef6c9fe3_06f9_5eff_98a8_917d9644c946
#define WINRT_GENERIC_ef6c9fe3_06f9_5eff_98a8_917d9644c946
template <> struct __declspec(uuid("ef6c9fe3-06f9-5eff-98a8-917d9644c946")) __declspec(novtable) IVectorView<winrt::Windows::Media::Devices::IsoSpeedPreset> : impl_IVectorView<winrt::Windows::Media::Devices::IsoSpeedPreset> {};
#endif

#ifndef WINRT_GENERIC_4d556155_d021_5a46_9a1c_f401d61b8529
#define WINRT_GENERIC_4d556155_d021_5a46_9a1c_f401d61b8529
template <> struct __declspec(uuid("4d556155-d021-5a46-9a1c-f401d61b8529")) __declspec(novtable) IVectorView<winrt::Windows::Media::Devices::ZoomTransitionMode> : impl_IVectorView<winrt::Windows::Media::Devices::ZoomTransitionMode> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_b0060b8a_1105_5ad4_963d_f6cf1905d349
#define WINRT_GENERIC_b0060b8a_1105_5ad4_963d_f6cf1905d349
template <> struct __declspec(uuid("b0060b8a-1105-5ad4-963d-f6cf1905d349")) __declspec(novtable) IReference<winrt::Windows::Media::Devices::ManualFocusDistance> : impl_IReference<winrt::Windows::Media::Devices::ManualFocusDistance> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_d8a495e3_d7d4_5e9f_a9c2_6b250655a2e0
#define WINRT_GENERIC_d8a495e3_d7d4_5e9f_a9c2_6b250655a2e0
template <> struct __declspec(uuid("d8a495e3-d7d4-5e9f-a9c2-6b250655a2e0")) __declspec(novtable) IVectorView<winrt::Windows::Media::Devices::FocusPreset> : impl_IVectorView<winrt::Windows::Media::Devices::FocusPreset> {};
#endif

#ifndef WINRT_GENERIC_c877975c_f3c3_5b3d_93e4_5787be9b7f58
#define WINRT_GENERIC_c877975c_f3c3_5b3d_93e4_5787be9b7f58
template <> struct __declspec(uuid("c877975c-f3c3-5b3d-93e4-5787be9b7f58")) __declspec(novtable) IVectorView<winrt::Windows::Media::Devices::FocusMode> : impl_IVectorView<winrt::Windows::Media::Devices::FocusMode> {};
#endif

#ifndef WINRT_GENERIC_85f7663b_5467_5736_8d34_34395aa6d123
#define WINRT_GENERIC_85f7663b_5467_5736_8d34_34395aa6d123
template <> struct __declspec(uuid("85f7663b-5467-5736-8d34-34395aa6d123")) __declspec(novtable) IVectorView<winrt::Windows::Media::Devices::ManualFocusDistance> : impl_IVectorView<winrt::Windows::Media::Devices::ManualFocusDistance> {};
#endif

#ifndef WINRT_GENERIC_5df64825_c9e1_525f_9aeb_3c0f5f805f26
#define WINRT_GENERIC_5df64825_c9e1_525f_9aeb_3c0f5f805f26
template <> struct __declspec(uuid("5df64825-c9e1-525f-9aeb-3c0f5f805f26")) __declspec(novtable) IVectorView<winrt::Windows::Media::Devices::AutoFocusRange> : impl_IVectorView<winrt::Windows::Media::Devices::AutoFocusRange> {};
#endif

#ifndef WINRT_GENERIC_d73144c7_9d75_5dfb_8040_626202dcf454
#define WINRT_GENERIC_d73144c7_9d75_5dfb_8040_626202dcf454
template <> struct __declspec(uuid("d73144c7-9d75-5dfb-8040-626202dcf454")) __declspec(novtable) IIterable<Windows::Media::Devices::RegionOfInterest> : impl_IIterable<Windows::Media::Devices::RegionOfInterest> {};
#endif

#ifndef WINRT_GENERIC_ad0a4bbd_7630_53a4_aa9b_35a8c7d4958c
#define WINRT_GENERIC_ad0a4bbd_7630_53a4_aa9b_35a8c7d4958c
template <> struct __declspec(uuid("ad0a4bbd-7630-53a4-aa9b-35a8c7d4958c")) __declspec(novtable) IVectorView<winrt::Windows::Media::Devices::HdrVideoMode> : impl_IVectorView<winrt::Windows::Media::Devices::HdrVideoMode> {};
#endif

#ifndef WINRT_GENERIC_d05843b6_03c8_523e_b6fb_1fcb03218a54
#define WINRT_GENERIC_d05843b6_03c8_523e_b6fb_1fcb03218a54
template <> struct __declspec(uuid("d05843b6-03c8-523e-b6fb-1fcb03218a54")) __declspec(novtable) IVectorView<winrt::Windows::Media::Devices::AdvancedPhotoMode> : impl_IVectorView<winrt::Windows::Media::Devices::AdvancedPhotoMode> {};
#endif

#ifndef WINRT_GENERIC_8c2658d8_acaa_5a80_b259_1ba0697c6138
#define WINRT_GENERIC_8c2658d8_acaa_5a80_b259_1ba0697c6138
template <> struct __declspec(uuid("8c2658d8-acaa-5a80-b259-1ba0697c6138")) __declspec(novtable) IVectorView<winrt::Windows::Media::Devices::OpticalImageStabilizationMode> : impl_IVectorView<winrt::Windows::Media::Devices::OpticalImageStabilizationMode> {};
#endif

#ifndef WINRT_GENERIC_0f6c3b8b_5818_5cbf_bf26_6616bfc308c4
#define WINRT_GENERIC_0f6c3b8b_5818_5cbf_bf26_6616bfc308c4
template <> struct __declspec(uuid("0f6c3b8b-5818-5cbf-bf26-6616bfc308c4")) __declspec(novtable) IVectorView<Windows::Media::MediaProperties::IMediaEncodingProperties> : impl_IVectorView<Windows::Media::MediaProperties::IMediaEncodingProperties> {};
#endif

#ifndef WINRT_GENERIC_aafa6d7a_2f7f_5dd7_aa0a_265731a2b3b3
#define WINRT_GENERIC_aafa6d7a_2f7f_5dd7_aa0a_265731a2b3b3
template <> struct __declspec(uuid("aafa6d7a-2f7f-5dd7-aa0a-265731a2b3b3")) __declspec(novtable) IIterator<winrt::Windows::Media::Devices::CaptureSceneMode> : impl_IIterator<winrt::Windows::Media::Devices::CaptureSceneMode> {};
#endif

#ifndef WINRT_GENERIC_16d26b98_2cbc_52f0_ab64_1723714418e9
#define WINRT_GENERIC_16d26b98_2cbc_52f0_ab64_1723714418e9
template <> struct __declspec(uuid("16d26b98-2cbc-52f0-ab64-1723714418e9")) __declspec(novtable) IIterable<winrt::Windows::Media::Devices::CaptureSceneMode> : impl_IIterable<winrt::Windows::Media::Devices::CaptureSceneMode> {};
#endif

#ifndef WINRT_GENERIC_1b33af76_980b_5348_916a_793f61b555a0
#define WINRT_GENERIC_1b33af76_980b_5348_916a_793f61b555a0
template <> struct __declspec(uuid("1b33af76-980b-5348-916a-793f61b555a0")) __declspec(novtable) IIterator<winrt::Windows::Media::Devices::IsoSpeedPreset> : impl_IIterator<winrt::Windows::Media::Devices::IsoSpeedPreset> {};
#endif

#ifndef WINRT_GENERIC_94839abe_9712_545a_a94d_a567a3e8dfb7
#define WINRT_GENERIC_94839abe_9712_545a_a94d_a567a3e8dfb7
template <> struct __declspec(uuid("94839abe-9712-545a-a94d-a567a3e8dfb7")) __declspec(novtable) IIterable<winrt::Windows::Media::Devices::IsoSpeedPreset> : impl_IIterable<winrt::Windows::Media::Devices::IsoSpeedPreset> {};
#endif

#ifndef WINRT_GENERIC_80eb468a_fdc4_5c89_99b8_8d476264e211
#define WINRT_GENERIC_80eb468a_fdc4_5c89_99b8_8d476264e211
template <> struct __declspec(uuid("80eb468a-fdc4-5c89-99b8-8d476264e211")) __declspec(novtable) IIterator<winrt::Windows::Media::Devices::ZoomTransitionMode> : impl_IIterator<winrt::Windows::Media::Devices::ZoomTransitionMode> {};
#endif

#ifndef WINRT_GENERIC_db656915_8fac_5fb2_98e0_0e97421656c5
#define WINRT_GENERIC_db656915_8fac_5fb2_98e0_0e97421656c5
template <> struct __declspec(uuid("db656915-8fac-5fb2-98e0-0e97421656c5")) __declspec(novtable) IIterable<winrt::Windows::Media::Devices::ZoomTransitionMode> : impl_IIterable<winrt::Windows::Media::Devices::ZoomTransitionMode> {};
#endif

#ifndef WINRT_GENERIC_d3ebc8e9_f0c5_51c0_bb86_bdea0a6946fb
#define WINRT_GENERIC_d3ebc8e9_f0c5_51c0_bb86_bdea0a6946fb
template <> struct __declspec(uuid("d3ebc8e9-f0c5-51c0-bb86-bdea0a6946fb")) __declspec(novtable) IIterator<winrt::Windows::Media::Devices::FocusPreset> : impl_IIterator<winrt::Windows::Media::Devices::FocusPreset> {};
#endif

#ifndef WINRT_GENERIC_26ba711b_3a32_5216_bc34_61ecafbebdc1
#define WINRT_GENERIC_26ba711b_3a32_5216_bc34_61ecafbebdc1
template <> struct __declspec(uuid("26ba711b-3a32-5216-bc34-61ecafbebdc1")) __declspec(novtable) IIterable<winrt::Windows::Media::Devices::FocusPreset> : impl_IIterable<winrt::Windows::Media::Devices::FocusPreset> {};
#endif

#ifndef WINRT_GENERIC_f9a43cd4_b300_541f_af79_3de3400e16af
#define WINRT_GENERIC_f9a43cd4_b300_541f_af79_3de3400e16af
template <> struct __declspec(uuid("f9a43cd4-b300-541f-af79-3de3400e16af")) __declspec(novtable) IIterator<winrt::Windows::Media::Devices::FocusMode> : impl_IIterator<winrt::Windows::Media::Devices::FocusMode> {};
#endif

#ifndef WINRT_GENERIC_561bc21f_4ae2_580a_a216_0ad48f373a4c
#define WINRT_GENERIC_561bc21f_4ae2_580a_a216_0ad48f373a4c
template <> struct __declspec(uuid("561bc21f-4ae2-580a-a216-0ad48f373a4c")) __declspec(novtable) IIterable<winrt::Windows::Media::Devices::FocusMode> : impl_IIterable<winrt::Windows::Media::Devices::FocusMode> {};
#endif

#ifndef WINRT_GENERIC_b02944e1_f649_511e_80dd_2e2b20379deb
#define WINRT_GENERIC_b02944e1_f649_511e_80dd_2e2b20379deb
template <> struct __declspec(uuid("b02944e1-f649-511e-80dd-2e2b20379deb")) __declspec(novtable) IIterator<winrt::Windows::Media::Devices::ManualFocusDistance> : impl_IIterator<winrt::Windows::Media::Devices::ManualFocusDistance> {};
#endif

#ifndef WINRT_GENERIC_cf8cbeb1_2a4c_522d_962f_84c31a598d68
#define WINRT_GENERIC_cf8cbeb1_2a4c_522d_962f_84c31a598d68
template <> struct __declspec(uuid("cf8cbeb1-2a4c-522d-962f-84c31a598d68")) __declspec(novtable) IIterable<winrt::Windows::Media::Devices::ManualFocusDistance> : impl_IIterable<winrt::Windows::Media::Devices::ManualFocusDistance> {};
#endif

#ifndef WINRT_GENERIC_07489ac5_3c71_59c6_b7dc_7f21341c2f71
#define WINRT_GENERIC_07489ac5_3c71_59c6_b7dc_7f21341c2f71
template <> struct __declspec(uuid("07489ac5-3c71-59c6-b7dc-7f21341c2f71")) __declspec(novtable) IIterator<winrt::Windows::Media::Devices::AutoFocusRange> : impl_IIterator<winrt::Windows::Media::Devices::AutoFocusRange> {};
#endif

#ifndef WINRT_GENERIC_751664c6_f8d6_50a3_ab80_137c6d908c55
#define WINRT_GENERIC_751664c6_f8d6_50a3_ab80_137c6d908c55
template <> struct __declspec(uuid("751664c6-f8d6-50a3-ab80-137c6d908c55")) __declspec(novtable) IIterable<winrt::Windows::Media::Devices::AutoFocusRange> : impl_IIterable<winrt::Windows::Media::Devices::AutoFocusRange> {};
#endif

#ifndef WINRT_GENERIC_8eb80e4e_9691_594f_8b3d_f52ecc0f7837
#define WINRT_GENERIC_8eb80e4e_9691_594f_8b3d_f52ecc0f7837
template <> struct __declspec(uuid("8eb80e4e-9691-594f-8b3d-f52ecc0f7837")) __declspec(novtable) IIterator<Windows::Media::Devices::RegionOfInterest> : impl_IIterator<Windows::Media::Devices::RegionOfInterest> {};
#endif

#ifndef WINRT_GENERIC_3db61d13_0f30_5d2d_99cb_30c7b9009878
#define WINRT_GENERIC_3db61d13_0f30_5d2d_99cb_30c7b9009878
template <> struct __declspec(uuid("3db61d13-0f30-5d2d-99cb-30c7b9009878")) __declspec(novtable) IIterator<winrt::Windows::Media::Devices::HdrVideoMode> : impl_IIterator<winrt::Windows::Media::Devices::HdrVideoMode> {};
#endif

#ifndef WINRT_GENERIC_1d9679a7_2d06_5294_ac67_f9cd3561dcb8
#define WINRT_GENERIC_1d9679a7_2d06_5294_ac67_f9cd3561dcb8
template <> struct __declspec(uuid("1d9679a7-2d06-5294-ac67-f9cd3561dcb8")) __declspec(novtable) IIterable<winrt::Windows::Media::Devices::HdrVideoMode> : impl_IIterable<winrt::Windows::Media::Devices::HdrVideoMode> {};
#endif

#ifndef WINRT_GENERIC_e6d0bc9d_e1cb_5ed0_8ede_7d037bcc2e07
#define WINRT_GENERIC_e6d0bc9d_e1cb_5ed0_8ede_7d037bcc2e07
template <> struct __declspec(uuid("e6d0bc9d-e1cb-5ed0-8ede-7d037bcc2e07")) __declspec(novtable) IIterator<winrt::Windows::Media::Devices::AdvancedPhotoMode> : impl_IIterator<winrt::Windows::Media::Devices::AdvancedPhotoMode> {};
#endif

#ifndef WINRT_GENERIC_7d090784_70a9_570c_be82_0d0890318975
#define WINRT_GENERIC_7d090784_70a9_570c_be82_0d0890318975
template <> struct __declspec(uuid("7d090784-70a9-570c-be82-0d0890318975")) __declspec(novtable) IIterable<winrt::Windows::Media::Devices::AdvancedPhotoMode> : impl_IIterable<winrt::Windows::Media::Devices::AdvancedPhotoMode> {};
#endif

#ifndef WINRT_GENERIC_4a165d46_cf19_5a03_bb54_63fc2b4ed39b
#define WINRT_GENERIC_4a165d46_cf19_5a03_bb54_63fc2b4ed39b
template <> struct __declspec(uuid("4a165d46-cf19-5a03-bb54-63fc2b4ed39b")) __declspec(novtable) IIterator<winrt::Windows::Media::Devices::OpticalImageStabilizationMode> : impl_IIterator<winrt::Windows::Media::Devices::OpticalImageStabilizationMode> {};
#endif

#ifndef WINRT_GENERIC_323d7734_94c2_544d_a560_56560fe68819
#define WINRT_GENERIC_323d7734_94c2_544d_a560_56560fe68819
template <> struct __declspec(uuid("323d7734-94c2-544d-a560-56560fe68819")) __declspec(novtable) IIterable<winrt::Windows::Media::Devices::OpticalImageStabilizationMode> : impl_IIterable<winrt::Windows::Media::Devices::OpticalImageStabilizationMode> {};
#endif

#ifndef WINRT_GENERIC_7c094aec_c8f3_5f49_99c7_b66d8414200e
#define WINRT_GENERIC_7c094aec_c8f3_5f49_99c7_b66d8414200e
template <> struct __declspec(uuid("7c094aec-c8f3-5f49-99c7-b66d8414200e")) __declspec(novtable) IIterator<Windows::Media::MediaProperties::IMediaEncodingProperties> : impl_IIterator<Windows::Media::MediaProperties::IMediaEncodingProperties> {};
#endif

#ifndef WINRT_GENERIC_d7fc75d5_3492_5bbb_9b34_dac3e24e79d0
#define WINRT_GENERIC_d7fc75d5_3492_5bbb_9b34_dac3e24e79d0
template <> struct __declspec(uuid("d7fc75d5-3492-5bbb-9b34-dac3e24e79d0")) __declspec(novtable) IIterable<Windows::Media::MediaProperties::IMediaEncodingProperties> : impl_IIterable<Windows::Media::MediaProperties::IMediaEncodingProperties> {};
#endif


}

namespace Windows::Media::Devices {

struct CallControlEventHandler : Windows::Foundation::IUnknown
{
    CallControlEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> CallControlEventHandler(L lambda);
    template <typename F> CallControlEventHandler (F * function);
    template <typename O, typename M> CallControlEventHandler(O * object, M method);
    void operator()(const Windows::Media::Devices::CallControl & sender) const;
};

struct DialRequestedEventHandler : Windows::Foundation::IUnknown
{
    DialRequestedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> DialRequestedEventHandler(L lambda);
    template <typename F> DialRequestedEventHandler (F * function);
    template <typename O, typename M> DialRequestedEventHandler(O * object, M method);
    void operator()(const Windows::Media::Devices::CallControl & sender, const Windows::Media::Devices::DialRequestedEventArgs & e) const;
};

struct KeypadPressedEventHandler : Windows::Foundation::IUnknown
{
    KeypadPressedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> KeypadPressedEventHandler(L lambda);
    template <typename F> KeypadPressedEventHandler (F * function);
    template <typename O, typename M> KeypadPressedEventHandler(O * object, M method);
    void operator()(const Windows::Media::Devices::CallControl & sender, const Windows::Media::Devices::KeypadPressedEventArgs & e) const;
};

struct RedialRequestedEventHandler : Windows::Foundation::IUnknown
{
    RedialRequestedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> RedialRequestedEventHandler(L lambda);
    template <typename F> RedialRequestedEventHandler (F * function);
    template <typename O, typename M> RedialRequestedEventHandler(O * object, M method);
    void operator()(const Windows::Media::Devices::CallControl & sender, const Windows::Media::Devices::RedialRequestedEventArgs & e) const;
};

struct IAdvancedPhotoCaptureSettings :
    Windows::Foundation::IInspectable,
    impl::consume<IAdvancedPhotoCaptureSettings>
{
    IAdvancedPhotoCaptureSettings(std::nullptr_t = nullptr) noexcept {}
};

struct IAdvancedPhotoControl :
    Windows::Foundation::IInspectable,
    impl::consume<IAdvancedPhotoControl>
{
    IAdvancedPhotoControl(std::nullptr_t = nullptr) noexcept {}
};

struct IAdvancedVideoCaptureDeviceController :
    Windows::Foundation::IInspectable,
    impl::consume<IAdvancedVideoCaptureDeviceController>
{
    IAdvancedVideoCaptureDeviceController(std::nullptr_t = nullptr) noexcept {}
};

struct IAdvancedVideoCaptureDeviceController2 :
    Windows::Foundation::IInspectable,
    impl::consume<IAdvancedVideoCaptureDeviceController2>
{
    IAdvancedVideoCaptureDeviceController2(std::nullptr_t = nullptr) noexcept {}
};

struct IAdvancedVideoCaptureDeviceController3 :
    Windows::Foundation::IInspectable,
    impl::consume<IAdvancedVideoCaptureDeviceController3>
{
    IAdvancedVideoCaptureDeviceController3(std::nullptr_t = nullptr) noexcept {}
};

struct IAdvancedVideoCaptureDeviceController4 :
    Windows::Foundation::IInspectable,
    impl::consume<IAdvancedVideoCaptureDeviceController4>
{
    IAdvancedVideoCaptureDeviceController4(std::nullptr_t = nullptr) noexcept {}
};

struct IAudioDeviceController :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioDeviceController>,
    impl::require<IAudioDeviceController, Windows::Media::Devices::IMediaDeviceController>
{
    IAudioDeviceController(std::nullptr_t = nullptr) noexcept {}
};

struct ICallControl :
    Windows::Foundation::IInspectable,
    impl::consume<ICallControl>
{
    ICallControl(std::nullptr_t = nullptr) noexcept {}
};

struct ICallControlStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ICallControlStatics>
{
    ICallControlStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IDefaultAudioDeviceChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IDefaultAudioDeviceChangedEventArgs>
{
    IDefaultAudioDeviceChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IDialRequestedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IDialRequestedEventArgs>
{
    IDialRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IExposureCompensationControl :
    Windows::Foundation::IInspectable,
    impl::consume<IExposureCompensationControl>
{
    IExposureCompensationControl(std::nullptr_t = nullptr) noexcept {}
};

struct IExposureControl :
    Windows::Foundation::IInspectable,
    impl::consume<IExposureControl>
{
    IExposureControl(std::nullptr_t = nullptr) noexcept {}
};

struct IExposurePriorityVideoControl :
    Windows::Foundation::IInspectable,
    impl::consume<IExposurePriorityVideoControl>
{
    IExposurePriorityVideoControl(std::nullptr_t = nullptr) noexcept {}
};

struct IFlashControl :
    Windows::Foundation::IInspectable,
    impl::consume<IFlashControl>
{
    IFlashControl(std::nullptr_t = nullptr) noexcept {}
};

struct IFlashControl2 :
    Windows::Foundation::IInspectable,
    impl::consume<IFlashControl2>
{
    IFlashControl2(std::nullptr_t = nullptr) noexcept {}
};

struct IFocusControl :
    Windows::Foundation::IInspectable,
    impl::consume<IFocusControl>
{
    IFocusControl(std::nullptr_t = nullptr) noexcept {}
};

struct IFocusControl2 :
    Windows::Foundation::IInspectable,
    impl::consume<IFocusControl2>
{
    IFocusControl2(std::nullptr_t = nullptr) noexcept {}
};

struct IFocusSettings :
    Windows::Foundation::IInspectable,
    impl::consume<IFocusSettings>
{
    IFocusSettings(std::nullptr_t = nullptr) noexcept {}
};

struct IHdrVideoControl :
    Windows::Foundation::IInspectable,
    impl::consume<IHdrVideoControl>
{
    IHdrVideoControl(std::nullptr_t = nullptr) noexcept {}
};

struct IIsoSpeedControl :
    Windows::Foundation::IInspectable,
    impl::consume<IIsoSpeedControl>
{
    IIsoSpeedControl(std::nullptr_t = nullptr) noexcept {}
};

struct IIsoSpeedControl2 :
    Windows::Foundation::IInspectable,
    impl::consume<IIsoSpeedControl2>
{
    IIsoSpeedControl2(std::nullptr_t = nullptr) noexcept {}
};

struct IKeypadPressedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IKeypadPressedEventArgs>
{
    IKeypadPressedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ILowLagPhotoControl :
    Windows::Foundation::IInspectable,
    impl::consume<ILowLagPhotoControl>
{
    ILowLagPhotoControl(std::nullptr_t = nullptr) noexcept {}
};

struct ILowLagPhotoSequenceControl :
    Windows::Foundation::IInspectable,
    impl::consume<ILowLagPhotoSequenceControl>
{
    ILowLagPhotoSequenceControl(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaDeviceControl :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaDeviceControl>
{
    IMediaDeviceControl(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaDeviceControlCapabilities :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaDeviceControlCapabilities>
{
    IMediaDeviceControlCapabilities(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaDeviceController :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaDeviceController>
{
    IMediaDeviceController(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaDeviceStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaDeviceStatics>
{
    IMediaDeviceStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IOpticalImageStabilizationControl :
    Windows::Foundation::IInspectable,
    impl::consume<IOpticalImageStabilizationControl>
{
    IOpticalImageStabilizationControl(std::nullptr_t = nullptr) noexcept {}
};

struct IPhotoConfirmationControl :
    Windows::Foundation::IInspectable,
    impl::consume<IPhotoConfirmationControl>
{
    IPhotoConfirmationControl(std::nullptr_t = nullptr) noexcept {}
};

struct IRedialRequestedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IRedialRequestedEventArgs>
{
    IRedialRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IRegionOfInterest :
    Windows::Foundation::IInspectable,
    impl::consume<IRegionOfInterest>
{
    IRegionOfInterest(std::nullptr_t = nullptr) noexcept {}
};

struct IRegionOfInterest2 :
    Windows::Foundation::IInspectable,
    impl::consume<IRegionOfInterest2>
{
    IRegionOfInterest2(std::nullptr_t = nullptr) noexcept {}
};

struct IRegionsOfInterestControl :
    Windows::Foundation::IInspectable,
    impl::consume<IRegionsOfInterestControl>
{
    IRegionsOfInterestControl(std::nullptr_t = nullptr) noexcept {}
};

struct ISceneModeControl :
    Windows::Foundation::IInspectable,
    impl::consume<ISceneModeControl>
{
    ISceneModeControl(std::nullptr_t = nullptr) noexcept {}
};

struct ITorchControl :
    Windows::Foundation::IInspectable,
    impl::consume<ITorchControl>
{
    ITorchControl(std::nullptr_t = nullptr) noexcept {}
};

struct IVideoDeviceController :
    Windows::Foundation::IInspectable,
    impl::consume<IVideoDeviceController>,
    impl::require<IVideoDeviceController, Windows::Media::Devices::IMediaDeviceController>
{
    IVideoDeviceController(std::nullptr_t = nullptr) noexcept {}
};

struct IWhiteBalanceControl :
    Windows::Foundation::IInspectable,
    impl::consume<IWhiteBalanceControl>
{
    IWhiteBalanceControl(std::nullptr_t = nullptr) noexcept {}
};

struct IZoomControl :
    Windows::Foundation::IInspectable,
    impl::consume<IZoomControl>
{
    IZoomControl(std::nullptr_t = nullptr) noexcept {}
};

struct IZoomControl2 :
    Windows::Foundation::IInspectable,
    impl::consume<IZoomControl2>
{
    IZoomControl2(std::nullptr_t = nullptr) noexcept {}
};

struct IZoomSettings :
    Windows::Foundation::IInspectable,
    impl::consume<IZoomSettings>
{
    IZoomSettings(std::nullptr_t = nullptr) noexcept {}
};

}

}
