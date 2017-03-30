// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Storage.FileProperties.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.Storage.Streams.1.h"
#include "Windows.Storage.Streams.2.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_1b0d3570_0877_5ec2_8a2c_3b9539506aca
#define WINRT_GENERIC_1b0d3570_0877_5ec2_8a2c_3b9539506aca
template <> struct __declspec(uuid("1b0d3570-0877-5ec2-8a2c-3b9539506aca")) __declspec(novtable) IMap<hstring, Windows::Foundation::IInspectable> : impl_IMap<hstring, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_09335560_6c6b_5a26_9348_97b781132b20
#define WINRT_GENERIC_09335560_6c6b_5a26_9348_97b781132b20
template <> struct __declspec(uuid("09335560-6c6b-5a26-9348-97b781132b20")) __declspec(novtable) IKeyValuePair<hstring, Windows::Foundation::IInspectable> : impl_IKeyValuePair<hstring, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_98b9acc1_4b56_532e_ac73_03d5291cca90
#define WINRT_GENERIC_98b9acc1_4b56_532e_ac73_03d5291cca90
template <> struct __declspec(uuid("98b9acc1-4b56-532e-ac73-03d5291cca90")) __declspec(novtable) IVector<hstring> : impl_IVector<hstring> {};
#endif

#ifndef WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
#define WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
template <> struct __declspec(uuid("2f13c006-a03a-5f69-b090-75a43e33423e")) __declspec(novtable) IVectorView<hstring> : impl_IVectorView<hstring> {};
#endif

#ifndef WINRT_GENERIC_bb78502a_f79d_54fa_92c9_90c5039fdf7e
#define WINRT_GENERIC_bb78502a_f79d_54fa_92c9_90c5039fdf7e
template <> struct __declspec(uuid("bb78502a-f79d-54fa-92c9-90c5039fdf7e")) __declspec(novtable) IMapView<hstring, Windows::Foundation::IInspectable> : impl_IMapView<hstring, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
#define WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
template <> struct __declspec(uuid("e2fcc7c1-3bfc-5a0b-b2b0-72e769d1cb7e")) __declspec(novtable) IIterable<hstring> : impl_IIterable<hstring> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_2f2d6c29_5473_5f3e_92e7_96572bb990e2
#define WINRT_GENERIC_2f2d6c29_5473_5f3e_92e7_96572bb990e2
template <> struct __declspec(uuid("2f2d6c29-5473-5f3e-92e7-96572bb990e2")) __declspec(novtable) IReference<double> : impl_IReference<double> {};
#endif

#ifndef WINRT_GENERIC_3723e070_c2ae_538f_846e_0f9d280310c0
#define WINRT_GENERIC_3723e070_c2ae_538f_846e_0f9d280310c0
template <> struct __declspec(uuid("3723e070-c2ae-538f-846e-0f9d280310c0")) __declspec(novtable) IAsyncOperation<Windows::Devices::Geolocation::Geopoint> : impl_IAsyncOperation<Windows::Devices::Geolocation::Geopoint> {};
#endif

#ifndef WINRT_GENERIC_0d023b76_20a7_56f3_84ab_ce31e6544b71
#define WINRT_GENERIC_0d023b76_20a7_56f3_84ab_ce31e6544b71
template <> struct __declspec(uuid("0d023b76-20a7-56f3-84ab-ce31e6544b71")) __declspec(novtable) IAsyncOperation<Windows::Storage::FileProperties::MusicProperties> : impl_IAsyncOperation<Windows::Storage::FileProperties::MusicProperties> {};
#endif

#ifndef WINRT_GENERIC_447d4590_d3f9_58bf_ac58_6f9a50839efe
#define WINRT_GENERIC_447d4590_d3f9_58bf_ac58_6f9a50839efe
template <> struct __declspec(uuid("447d4590-d3f9-58bf-ac58-6f9a50839efe")) __declspec(novtable) IAsyncOperation<Windows::Storage::FileProperties::VideoProperties> : impl_IAsyncOperation<Windows::Storage::FileProperties::VideoProperties> {};
#endif

#ifndef WINRT_GENERIC_fcd07511_e7f8_5bda_8c04_795a639dae8f
#define WINRT_GENERIC_fcd07511_e7f8_5bda_8c04_795a639dae8f
template <> struct __declspec(uuid("fcd07511-e7f8-5bda-8c04-795a639dae8f")) __declspec(novtable) IAsyncOperation<Windows::Storage::FileProperties::ImageProperties> : impl_IAsyncOperation<Windows::Storage::FileProperties::ImageProperties> {};
#endif

#ifndef WINRT_GENERIC_6c86e97c_5699_5700_8d35_d350ad3e4df2
#define WINRT_GENERIC_6c86e97c_5699_5700_8d35_d350ad3e4df2
template <> struct __declspec(uuid("6c86e97c-5699-5700-8d35-d350ad3e4df2")) __declspec(novtable) IAsyncOperation<Windows::Storage::FileProperties::DocumentProperties> : impl_IAsyncOperation<Windows::Storage::FileProperties::DocumentProperties> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_4b5f2f60_19b1_5566_9df6_92a42235cbf9
#define WINRT_GENERIC_4b5f2f60_19b1_5566_9df6_92a42235cbf9
template <> struct __declspec(uuid("4b5f2f60-19b1-5566-9df6-92a42235cbf9")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Geolocation::Geopoint> : impl_AsyncOperationCompletedHandler<Windows::Devices::Geolocation::Geopoint> {};
#endif

#ifndef WINRT_GENERIC_d84e1312_d661_5b7f_9566_7421bdedc1ea
#define WINRT_GENERIC_d84e1312_d661_5b7f_9566_7421bdedc1ea
template <> struct __declspec(uuid("d84e1312-d661-5b7f-9566-7421bdedc1ea")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Storage::FileProperties::MusicProperties> : impl_AsyncOperationCompletedHandler<Windows::Storage::FileProperties::MusicProperties> {};
#endif

#ifndef WINRT_GENERIC_43401d34_61ab_5cf2_921f_55b616631d1d
#define WINRT_GENERIC_43401d34_61ab_5cf2_921f_55b616631d1d
template <> struct __declspec(uuid("43401d34-61ab-5cf2-921f-55b616631d1d")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Storage::FileProperties::VideoProperties> : impl_AsyncOperationCompletedHandler<Windows::Storage::FileProperties::VideoProperties> {};
#endif

#ifndef WINRT_GENERIC_c63729bc_e4c3_564c_b137_2cb4f5966a83
#define WINRT_GENERIC_c63729bc_e4c3_564c_b137_2cb4f5966a83
template <> struct __declspec(uuid("c63729bc-e4c3-564c-b137-2cb4f5966a83")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Storage::FileProperties::ImageProperties> : impl_AsyncOperationCompletedHandler<Windows::Storage::FileProperties::ImageProperties> {};
#endif

#ifndef WINRT_GENERIC_4452ed4c_642b_501b_9617_7d68b4ac3c66
#define WINRT_GENERIC_4452ed4c_642b_501b_9617_7d68b4ac3c66
template <> struct __declspec(uuid("4452ed4c-642b-501b-9617-7d68b4ac3c66")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Storage::FileProperties::DocumentProperties> : impl_AsyncOperationCompletedHandler<Windows::Storage::FileProperties::DocumentProperties> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_fe2f3d47_5d47_5499_8374_430c7cda0204
#define WINRT_GENERIC_fe2f3d47_5d47_5499_8374_430c7cda0204
template <> struct __declspec(uuid("fe2f3d47-5d47-5499-8374-430c7cda0204")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_127e39c7_07c1_58e5_b48e_3a4729839fec
#define WINRT_GENERIC_127e39c7_07c1_58e5_b48e_3a4729839fec
template <> struct __declspec(uuid("127e39c7-07c1-58e5-b48e-3a4729839fec")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>> : impl_IAsyncOperation<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_5db5fa32_707c_5849_a06b_91c8eb9d10e8
#define WINRT_GENERIC_5db5fa32_707c_5849_a06b_91c8eb9d10e8
template <> struct __declspec(uuid("5db5fa32-707c-5849-a06b-91c8eb9d10e8")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_7344f356_8399_5756_a2f8_abd50c4146ff
#define WINRT_GENERIC_7344f356_8399_5756_a2f8_abd50c4146ff
template <> struct __declspec(uuid("7344f356-8399-5756-a2f8-abd50c4146ff")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>> {};
#endif


}

namespace Windows::Storage::FileProperties {

struct IBasicProperties :
    Windows::Foundation::IInspectable,
    impl::consume<IBasicProperties>
{
    IBasicProperties(std::nullptr_t = nullptr) noexcept {}
};

struct IDocumentProperties :
    Windows::Foundation::IInspectable,
    impl::consume<IDocumentProperties>,
    impl::require<IDocumentProperties, Windows::Storage::FileProperties::IStorageItemExtraProperties>
{
    IDocumentProperties(std::nullptr_t = nullptr) noexcept {}
};

struct IGeotagHelperStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IGeotagHelperStatics>
{
    IGeotagHelperStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IImageProperties :
    Windows::Foundation::IInspectable,
    impl::consume<IImageProperties>,
    impl::require<IImageProperties, Windows::Storage::FileProperties::IStorageItemExtraProperties>
{
    IImageProperties(std::nullptr_t = nullptr) noexcept {}
};

struct IMusicProperties :
    Windows::Foundation::IInspectable,
    impl::consume<IMusicProperties>,
    impl::require<IMusicProperties, Windows::Storage::FileProperties::IStorageItemExtraProperties>
{
    IMusicProperties(std::nullptr_t = nullptr) noexcept {}
};

struct IStorageItemContentProperties :
    Windows::Foundation::IInspectable,
    impl::consume<IStorageItemContentProperties>,
    impl::require<IStorageItemContentProperties, Windows::Storage::FileProperties::IStorageItemExtraProperties>
{
    IStorageItemContentProperties(std::nullptr_t = nullptr) noexcept {}
};

struct IStorageItemExtraProperties :
    Windows::Foundation::IInspectable,
    impl::consume<IStorageItemExtraProperties>
{
    IStorageItemExtraProperties(std::nullptr_t = nullptr) noexcept {}
};

struct IThumbnailProperties :
    Windows::Foundation::IInspectable,
    impl::consume<IThumbnailProperties>
{
    IThumbnailProperties(std::nullptr_t = nullptr) noexcept {}
};

struct IVideoProperties :
    Windows::Foundation::IInspectable,
    impl::consume<IVideoProperties>,
    impl::require<IVideoProperties, Windows::Storage::FileProperties::IStorageItemExtraProperties>
{
    IVideoProperties(std::nullptr_t = nullptr) noexcept {}
};

}

}
