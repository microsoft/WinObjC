// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Perception.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_09335560_6c6b_5a26_9348_97b781132b20
#define WINRT_GENERIC_09335560_6c6b_5a26_9348_97b781132b20
template <> struct __declspec(uuid("09335560-6c6b-5a26-9348-97b781132b20")) __declspec(novtable) IKeyValuePair<hstring, Windows::Foundation::IInspectable> : impl_IKeyValuePair<hstring, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_bb78502a_f79d_54fa_92c9_90c5039fdf7e
#define WINRT_GENERIC_bb78502a_f79d_54fa_92c9_90c5039fdf7e
template <> struct __declspec(uuid("bb78502a-f79d-54fa-92c9-90c5039fdf7e")) __declspec(novtable) IMapView<hstring, Windows::Foundation::IInspectable> : impl_IMapView<hstring, Windows::Foundation::IInspectable> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_7202e817_22b8_5e7b_86b5_c4a90ccc23aa
#define WINRT_GENERIC_7202e817_22b8_5e7b_86b5_c4a90ccc23aa
template <> struct __declspec(uuid("7202e817-22b8-5e7b-86b5-c4a90ccc23aa")) __declspec(novtable) TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Devices::Perception::PerceptionColorFrameSourceAddedEventArgs> : impl_TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Devices::Perception::PerceptionColorFrameSourceAddedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_c7131ddd_ff22_5fb7_ada0_961e3b28917b
#define WINRT_GENERIC_c7131ddd_ff22_5fb7_ada0_961e3b28917b
template <> struct __declspec(uuid("c7131ddd-ff22-5fb7-ada0-961e3b28917b")) __declspec(novtable) TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Devices::Perception::PerceptionColorFrameSourceRemovedEventArgs> : impl_TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Devices::Perception::PerceptionColorFrameSourceRemovedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_b3f5bf64_7fc0_5d8c_978c_a38d5b18a51d
#define WINRT_GENERIC_b3f5bf64_7fc0_5d8c_978c_a38d5b18a51d
template <> struct __declspec(uuid("b3f5bf64-7fc0-5d8c-978c-a38d5b18a51d")) __declspec(novtable) TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_a3c1e25f_3574_5a27_a791_16e1bcc424f4
#define WINRT_GENERIC_a3c1e25f_3574_5a27_a791_16e1bcc424f4
template <> struct __declspec(uuid("a3c1e25f-3574-5a27-a791-16e1bcc424f4")) __declspec(novtable) TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Devices::Perception::PerceptionDepthFrameSourceAddedEventArgs> : impl_TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Devices::Perception::PerceptionDepthFrameSourceAddedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_5cf5faf7_0785_5589_a621_089d900412c8
#define WINRT_GENERIC_5cf5faf7_0785_5589_a621_089d900412c8
template <> struct __declspec(uuid("5cf5faf7-0785-5589-a621-089d900412c8")) __declspec(novtable) TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Devices::Perception::PerceptionDepthFrameSourceRemovedEventArgs> : impl_TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Devices::Perception::PerceptionDepthFrameSourceRemovedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_c5efa976_d948_50c7_8555_664190f9a968
#define WINRT_GENERIC_c5efa976_d948_50c7_8555_664190f9a968
template <> struct __declspec(uuid("c5efa976-d948-50c7-8555-664190f9a968")) __declspec(novtable) TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_a8180cd1_c25b_5c7f_94dd_198423bb56d5
#define WINRT_GENERIC_a8180cd1_c25b_5c7f_94dd_198423bb56d5
template <> struct __declspec(uuid("a8180cd1-c25b-5c7f-94dd-198423bb56d5")) __declspec(novtable) TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Devices::Perception::PerceptionInfraredFrameSourceAddedEventArgs> : impl_TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Devices::Perception::PerceptionInfraredFrameSourceAddedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_2ca3a9b7_3348_5953_8d0d_ef8d78640b23
#define WINRT_GENERIC_2ca3a9b7_3348_5953_8d0d_ef8d78640b23
template <> struct __declspec(uuid("2ca3a9b7-3348-5953-8d0d-ef8d78640b23")) __declspec(novtable) TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Devices::Perception::PerceptionInfraredFrameSourceRemovedEventArgs> : impl_TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Devices::Perception::PerceptionInfraredFrameSourceRemovedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_1555a628_3dff_5fd0_b10a_ca6adb2440c6
#define WINRT_GENERIC_1555a628_3dff_5fd0_b10a_ca6adb2440c6
template <> struct __declspec(uuid("1555a628-3dff-5fd0-b10a-ca6adb2440c6")) __declspec(novtable) TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Foundation::IInspectable> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_f272ae7a_c5c4_5712_8552_01deb8b70e07
#define WINRT_GENERIC_f272ae7a_c5c4_5712_8552_01deb8b70e07
template <> struct __declspec(uuid("f272ae7a-c5c4-5712-8552-01deb8b70e07")) __declspec(novtable) IVectorView<Windows::Devices::Perception::PerceptionInfraredFrameSource> : impl_IVectorView<Windows::Devices::Perception::PerceptionInfraredFrameSource> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_55122e42_cc65_5ccd_8f6c_84ced09db24e
#define WINRT_GENERIC_55122e42_cc65_5ccd_8f6c_84ced09db24e
template <> struct __declspec(uuid("55122e42-cc65-5ccd-8f6c-84ced09db24e")) __declspec(novtable) IAsyncOperation<Windows::Devices::Perception::PerceptionInfraredFrameSource> : impl_IAsyncOperation<Windows::Devices::Perception::PerceptionInfraredFrameSource> {};
#endif

#ifndef WINRT_GENERIC_2c2f22a8_f383_5802_ba2c_0cbbcd989c9a
#define WINRT_GENERIC_2c2f22a8_f383_5802_ba2c_0cbbcd989c9a
template <> struct __declspec(uuid("2c2f22a8-f383-5802-ba2c-0cbbcd989c9a")) __declspec(novtable) IAsyncOperation<winrt::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus> : impl_IAsyncOperation<winrt::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_574d3642_9f78_5125_851f_8b67e0313e2f
#define WINRT_GENERIC_574d3642_9f78_5125_851f_8b67e0313e2f
template <> struct __declspec(uuid("574d3642-9f78-5125-851f-8b67e0313e2f")) __declspec(novtable) IVectorView<Windows::Devices::Perception::PerceptionDepthFrameSource> : impl_IVectorView<Windows::Devices::Perception::PerceptionDepthFrameSource> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_4382b038_d4b1_540b_859a_7016626bb99d
#define WINRT_GENERIC_4382b038_d4b1_540b_859a_7016626bb99d
template <> struct __declspec(uuid("4382b038-d4b1-540b-859a-7016626bb99d")) __declspec(novtable) IAsyncOperation<Windows::Devices::Perception::PerceptionDepthFrameSource> : impl_IAsyncOperation<Windows::Devices::Perception::PerceptionDepthFrameSource> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_cbf2f698_31a0_53c7_927b_8e1675f743bc
#define WINRT_GENERIC_cbf2f698_31a0_53c7_927b_8e1675f743bc
template <> struct __declspec(uuid("cbf2f698-31a0-53c7-927b-8e1675f743bc")) __declspec(novtable) IVectorView<Windows::Devices::Perception::PerceptionColorFrameSource> : impl_IVectorView<Windows::Devices::Perception::PerceptionColorFrameSource> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_9647fec8_2c56_5348_86c8_a9c3a97fb944
#define WINRT_GENERIC_9647fec8_2c56_5348_86c8_a9c3a97fb944
template <> struct __declspec(uuid("9647fec8-2c56-5348-86c8-a9c3a97fb944")) __declspec(novtable) IAsyncOperation<Windows::Devices::Perception::PerceptionColorFrameSource> : impl_IAsyncOperation<Windows::Devices::Perception::PerceptionColorFrameSource> {};
#endif

#ifndef WINRT_GENERIC_023444d9_7b47_5497_9569_4399faf96717
#define WINRT_GENERIC_023444d9_7b47_5497_9569_4399faf96717
template <> struct __declspec(uuid("023444d9-7b47-5497-9569-4399faf96717")) __declspec(novtable) TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_b2c3a488_7ed9_5110_804a_9792ef7f26be
#define WINRT_GENERIC_b2c3a488_7ed9_5110_804a_9792ef7f26be
template <> struct __declspec(uuid("b2c3a488-7ed9-5110-804a-9792ef7f26be")) __declspec(novtable) TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> : impl_TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_8dcb30e8_4ec1_51b7_9997_10f325f03d47
#define WINRT_GENERIC_8dcb30e8_4ec1_51b7_9997_10f325f03d47
template <> struct __declspec(uuid("8dcb30e8-4ec1-51b7-9997-10f325f03d47")) __declspec(novtable) IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> : impl_IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_702b0f49_a742_5c3a_abd6_77f9999b8a09
#define WINRT_GENERIC_702b0f49_a742_5c3a_abd6_77f9999b8a09
template <> struct __declspec(uuid("702b0f49-a742-5c3a-abd6-77f9999b8a09")) __declspec(novtable) IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics> : impl_IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics> {};
#endif

#ifndef WINRT_GENERIC_f04b9d99_c0d5_5b48_9ae5_9802093cb45e
#define WINRT_GENERIC_f04b9d99_c0d5_5b48_9ae5_9802093cb45e
template <> struct __declspec(uuid("f04b9d99-c0d5-5b48-9ae5-9802093cb45e")) __declspec(novtable) IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper> : impl_IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper> {};
#endif

#ifndef WINRT_GENERIC_4a7bcb69_2b09_55d1_af68_b5aa5c2c6471
#define WINRT_GENERIC_4a7bcb69_2b09_55d1_af68_b5aa5c2c6471
template <> struct __declspec(uuid("4a7bcb69-2b09-55d1-af68-b5aa5c2c6471")) __declspec(novtable) IAsyncOperation<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult> : impl_IAsyncOperation<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult> {};
#endif

#ifndef WINRT_GENERIC_135ba76a_ab44_5f69_b208_e732cce9403b
#define WINRT_GENERIC_135ba76a_ab44_5f69_b208_e732cce9403b
template <> struct __declspec(uuid("135ba76a-ab44-5f69-b208-e732cce9403b")) __declspec(novtable) TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_188fdef2_d829_548b_a89d_38a34c5cb641
#define WINRT_GENERIC_188fdef2_d829_548b_a89d_38a34c5cb641
template <> struct __declspec(uuid("188fdef2-d829-548b-a89d-38a34c5cb641")) __declspec(novtable) TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> : impl_TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_31edabbd_d123_5e88_89d8_c80ee8f0f2ca
#define WINRT_GENERIC_31edabbd_d123_5e88_89d8_c80ee8f0f2ca
template <> struct __declspec(uuid("31edabbd-d123-5e88-89d8-c80ee8f0f2ca")) __declspec(novtable) TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_b6c1b828_a157_54ed_9c18_6919b9f91be9
#define WINRT_GENERIC_b6c1b828_a157_54ed_9c18_6919b9f91be9
template <> struct __declspec(uuid("b6c1b828-a157-54ed-9c18-6919b9f91be9")) __declspec(novtable) TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> : impl_TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_abc21152_2495_5e8c_aed3_7dc55309ac08
#define WINRT_GENERIC_abc21152_2495_5e8c_aed3_7dc55309ac08
template <> struct __declspec(uuid("abc21152-2495-5e8c-aed3-7dc55309ac08")) __declspec(novtable) TypedEventHandler<Windows::Devices::Perception::PerceptionControlSession, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Devices::Perception::PerceptionControlSession, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_a4a50ea5_778d_5056_a1cf_546a1be2c010
#define WINRT_GENERIC_a4a50ea5_778d_5056_a1cf_546a1be2c010
template <> struct __declspec(uuid("a4a50ea5-778d-5056-a1cf-546a1be2c010")) __declspec(novtable) TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameReader, Windows::Devices::Perception::PerceptionColorFrameArrivedEventArgs> : impl_TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameReader, Windows::Devices::Perception::PerceptionColorFrameArrivedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_4d529b7e_eea0_511b_8285_47e8c85d0295
#define WINRT_GENERIC_4d529b7e_eea0_511b_8285_47e8c85d0295
template <> struct __declspec(uuid("4d529b7e-eea0-511b-8285-47e8c85d0295")) __declspec(novtable) TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameReader, Windows::Devices::Perception::PerceptionDepthFrameArrivedEventArgs> : impl_TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameReader, Windows::Devices::Perception::PerceptionDepthFrameArrivedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_687fef67_8871_56fe_8e7e_1d2929cc6f42
#define WINRT_GENERIC_687fef67_8871_56fe_8e7e_1d2929cc6f42
template <> struct __declspec(uuid("687fef67-8871-56fe-8e7e-1d2929cc6f42")) __declspec(novtable) TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameReader, Windows::Devices::Perception::PerceptionInfraredFrameArrivedEventArgs> : impl_TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameReader, Windows::Devices::Perception::PerceptionInfraredFrameArrivedEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_b22b294f_a4d2_5726_a7fc_5e331432d9b4
#define WINRT_GENERIC_b22b294f_a4d2_5726_a7fc_5e331432d9b4
template <> struct __declspec(uuid("b22b294f-a4d2-5726-a7fc-5e331432d9b4")) __declspec(novtable) IIterator<Windows::Devices::Perception::PerceptionInfraredFrameSource> : impl_IIterator<Windows::Devices::Perception::PerceptionInfraredFrameSource> {};
#endif

#ifndef WINRT_GENERIC_9309d0db_338d_5adf_8b3e_509bfdfccef3
#define WINRT_GENERIC_9309d0db_338d_5adf_8b3e_509bfdfccef3
template <> struct __declspec(uuid("9309d0db-338d-5adf-8b3e-509bfdfccef3")) __declspec(novtable) IIterable<Windows::Devices::Perception::PerceptionInfraredFrameSource> : impl_IIterable<Windows::Devices::Perception::PerceptionInfraredFrameSource> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_a8d4cd8e_b210_54f7_ae2b_7770e19b3e36
#define WINRT_GENERIC_a8d4cd8e_b210_54f7_ae2b_7770e19b3e36
template <> struct __declspec(uuid("a8d4cd8e-b210-54f7-ae2b-7770e19b3e36")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource> : impl_AsyncOperationCompletedHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource> {};
#endif

#ifndef WINRT_GENERIC_62744ea4_3447_5722_ab5e_02567b4fceeb
#define WINRT_GENERIC_62744ea4_3447_5722_ab5e_02567b4fceeb
template <> struct __declspec(uuid("62744ea4-3447-5722-ab5e-02567b4fceeb")) __declspec(novtable) AsyncOperationCompletedHandler<winrt::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus> : impl_AsyncOperationCompletedHandler<winrt::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_20cff8c2_7844_54e5_ae4f_57e7768f9b69
#define WINRT_GENERIC_20cff8c2_7844_54e5_ae4f_57e7768f9b69
template <> struct __declspec(uuid("20cff8c2-7844-54e5-ae4f-57e7768f9b69")) __declspec(novtable) IIterator<Windows::Devices::Perception::PerceptionDepthFrameSource> : impl_IIterator<Windows::Devices::Perception::PerceptionDepthFrameSource> {};
#endif

#ifndef WINRT_GENERIC_8a07e1e8_5a02_585b_a26e_ad79beaa94cf
#define WINRT_GENERIC_8a07e1e8_5a02_585b_a26e_ad79beaa94cf
template <> struct __declspec(uuid("8a07e1e8-5a02-585b-a26e-ad79beaa94cf")) __declspec(novtable) IIterable<Windows::Devices::Perception::PerceptionDepthFrameSource> : impl_IIterable<Windows::Devices::Perception::PerceptionDepthFrameSource> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_b48cb886_3476_58d9_b76d_fda6b3e81f54
#define WINRT_GENERIC_b48cb886_3476_58d9_b76d_fda6b3e81f54
template <> struct __declspec(uuid("b48cb886-3476-58d9-b76d-fda6b3e81f54")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Perception::PerceptionDepthFrameSource> : impl_AsyncOperationCompletedHandler<Windows::Devices::Perception::PerceptionDepthFrameSource> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_24089f00_ba6d_50d4_ac46_f288755e4181
#define WINRT_GENERIC_24089f00_ba6d_50d4_ac46_f288755e4181
template <> struct __declspec(uuid("24089f00-ba6d-50d4-ac46-f288755e4181")) __declspec(novtable) IIterator<Windows::Devices::Perception::PerceptionColorFrameSource> : impl_IIterator<Windows::Devices::Perception::PerceptionColorFrameSource> {};
#endif

#ifndef WINRT_GENERIC_db18069e_7b5a_54c3_a627_d56f9517fdf5
#define WINRT_GENERIC_db18069e_7b5a_54c3_a627_d56f9517fdf5
template <> struct __declspec(uuid("db18069e-7b5a-54c3-a627-d56f9517fdf5")) __declspec(novtable) IIterable<Windows::Devices::Perception::PerceptionColorFrameSource> : impl_IIterable<Windows::Devices::Perception::PerceptionColorFrameSource> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_3b56acc2_e275_54fb_be08_9fdc8f1a1e10
#define WINRT_GENERIC_3b56acc2_e275_54fb_be08_9fdc8f1a1e10
template <> struct __declspec(uuid("3b56acc2-e275-54fb-be08-9fdc8f1a1e10")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Perception::PerceptionColorFrameSource> : impl_AsyncOperationCompletedHandler<Windows::Devices::Perception::PerceptionColorFrameSource> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_38ce8062_7079_5d7b_841f_9aa4580fd5f1
#define WINRT_GENERIC_38ce8062_7079_5d7b_841f_9aa4580fd5f1
template <> struct __declspec(uuid("38ce8062-7079-5d7b-841f-9aa4580fd5f1")) __declspec(novtable) IIterator<Windows::Devices::Perception::PerceptionVideoProfile> : impl_IIterator<Windows::Devices::Perception::PerceptionVideoProfile> {};
#endif

#ifndef WINRT_GENERIC_f6aea351_eb9b_564d_b10a_06673094acc8
#define WINRT_GENERIC_f6aea351_eb9b_564d_b10a_06673094acc8
template <> struct __declspec(uuid("f6aea351-eb9b-564d-b10a-06673094acc8")) __declspec(novtable) IIterable<Windows::Devices::Perception::PerceptionVideoProfile> : impl_IIterable<Windows::Devices::Perception::PerceptionVideoProfile> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_f396602a_3d8d_5fd5_99e3_1d3630be5938
#define WINRT_GENERIC_f396602a_3d8d_5fd5_99e3_1d3630be5938
template <> struct __declspec(uuid("f396602a-3d8d-5fd5-99e3-1d3630be5938")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics> : impl_AsyncOperationCompletedHandler<Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics> {};
#endif

#ifndef WINRT_GENERIC_48deeda0_684d_51e6_b07c_d234d1006bfc
#define WINRT_GENERIC_48deeda0_684d_51e6_b07c_d234d1006bfc
template <> struct __declspec(uuid("48deeda0-684d-51e6-b07c-d234d1006bfc")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper> : impl_AsyncOperationCompletedHandler<Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper> {};
#endif

#ifndef WINRT_GENERIC_3a06099c_dba6_58a5_8464_e2326896841a
#define WINRT_GENERIC_3a06099c_dba6_58a5_8464_e2326896841a
template <> struct __declspec(uuid("3a06099c-dba6-58a5-8464-e2326896841a")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult> : impl_AsyncOperationCompletedHandler<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_fe2f3d47_5d47_5499_8374_430c7cda0204
#define WINRT_GENERIC_fe2f3d47_5d47_5499_8374_430c7cda0204
template <> struct __declspec(uuid("fe2f3d47-5d47-5499-8374-430c7cda0204")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_b11eecaa_6f8c_5040_8d46_c3204c562582
#define WINRT_GENERIC_b11eecaa_6f8c_5040_8d46_c3204c562582
template <> struct __declspec(uuid("b11eecaa-6f8c-5040-8d46-c3204c562582")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionInfraredFrameSource>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionInfraredFrameSource>> {};
#endif

#ifndef WINRT_GENERIC_e20a534d_d406_5964_8465_e6dc75c5821d
#define WINRT_GENERIC_e20a534d_d406_5964_8465_e6dc75c5821d
template <> struct __declspec(uuid("e20a534d-d406-5964-8465-e6dc75c5821d")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionDepthFrameSource>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionDepthFrameSource>> {};
#endif

#ifndef WINRT_GENERIC_33845b5f_d59e_5271_bb68_f74e9d6a538d
#define WINRT_GENERIC_33845b5f_d59e_5271_bb68_f74e9d6a538d
template <> struct __declspec(uuid("33845b5f-d59e-5271-bb68-f74e9d6a538d")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionColorFrameSource>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionColorFrameSource>> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_5db5fa32_707c_5849_a06b_91c8eb9d10e8
#define WINRT_GENERIC_5db5fa32_707c_5849_a06b_91c8eb9d10e8
template <> struct __declspec(uuid("5db5fa32-707c-5849-a06b-91c8eb9d10e8")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_3aac58a8_4454_57e5_a90b_2449c5b7dfe8
#define WINRT_GENERIC_3aac58a8_4454_57e5_a90b_2449c5b7dfe8
template <> struct __declspec(uuid("3aac58a8-4454-57e5-a90b-2449c5b7dfe8")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionInfraredFrameSource>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionInfraredFrameSource>> {};
#endif

#ifndef WINRT_GENERIC_c06e62a4_965b_5a29_9732_8ac8669b585e
#define WINRT_GENERIC_c06e62a4_965b_5a29_9732_8ac8669b585e
template <> struct __declspec(uuid("c06e62a4-965b-5a29-9732-8ac8669b585e")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionDepthFrameSource>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionDepthFrameSource>> {};
#endif

#ifndef WINRT_GENERIC_0a36a7af_da9e_553f_8dc5_e89d705bb40b
#define WINRT_GENERIC_0a36a7af_da9e_553f_8dc5_e89d705bb40b
template <> struct __declspec(uuid("0a36a7af-da9e-553f-8dc5-e89d705bb40b")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionColorFrameSource>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionColorFrameSource>> {};
#endif


}

namespace Windows::Devices::Perception {

struct IKnownCameraIntrinsicsPropertiesStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IKnownCameraIntrinsicsPropertiesStatics>
{
    IKnownCameraIntrinsicsPropertiesStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IKnownPerceptionColorFrameSourcePropertiesStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IKnownPerceptionColorFrameSourcePropertiesStatics>
{
    IKnownPerceptionColorFrameSourcePropertiesStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IKnownPerceptionDepthFrameSourcePropertiesStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IKnownPerceptionDepthFrameSourcePropertiesStatics>
{
    IKnownPerceptionDepthFrameSourcePropertiesStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IKnownPerceptionFrameSourcePropertiesStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IKnownPerceptionFrameSourcePropertiesStatics>
{
    IKnownPerceptionFrameSourcePropertiesStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IKnownPerceptionFrameSourcePropertiesStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IKnownPerceptionFrameSourcePropertiesStatics2>
{
    IKnownPerceptionFrameSourcePropertiesStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IKnownPerceptionInfraredFrameSourcePropertiesStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IKnownPerceptionInfraredFrameSourcePropertiesStatics>
{
    IKnownPerceptionInfraredFrameSourcePropertiesStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IKnownPerceptionVideoFrameSourcePropertiesStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IKnownPerceptionVideoFrameSourcePropertiesStatics>
{
    IKnownPerceptionVideoFrameSourcePropertiesStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IKnownPerceptionVideoProfilePropertiesStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IKnownPerceptionVideoProfilePropertiesStatics>
{
    IKnownPerceptionVideoProfilePropertiesStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionColorFrame :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionColorFrame>,
    impl::require<IPerceptionColorFrame, Windows::Foundation::IClosable>
{
    IPerceptionColorFrame(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionColorFrameArrivedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionColorFrameArrivedEventArgs>
{
    IPerceptionColorFrameArrivedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionColorFrameReader :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionColorFrameReader>,
    impl::require<IPerceptionColorFrameReader, Windows::Foundation::IClosable>
{
    IPerceptionColorFrameReader(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionColorFrameSource :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionColorFrameSource>
{
    IPerceptionColorFrameSource(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionColorFrameSource2 :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionColorFrameSource2>
{
    IPerceptionColorFrameSource2(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionColorFrameSourceAddedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionColorFrameSourceAddedEventArgs>
{
    IPerceptionColorFrameSourceAddedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionColorFrameSourceRemovedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionColorFrameSourceRemovedEventArgs>
{
    IPerceptionColorFrameSourceRemovedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionColorFrameSourceStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionColorFrameSourceStatics>
{
    IPerceptionColorFrameSourceStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionColorFrameSourceWatcher :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionColorFrameSourceWatcher>
{
    IPerceptionColorFrameSourceWatcher(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionControlSession :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionControlSession>,
    impl::require<IPerceptionControlSession, Windows::Foundation::IClosable>
{
    IPerceptionControlSession(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionDepthCorrelatedCameraIntrinsics :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionDepthCorrelatedCameraIntrinsics>
{
    IPerceptionDepthCorrelatedCameraIntrinsics(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionDepthCorrelatedCoordinateMapper :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionDepthCorrelatedCoordinateMapper>
{
    IPerceptionDepthCorrelatedCoordinateMapper(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionDepthFrame :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionDepthFrame>,
    impl::require<IPerceptionDepthFrame, Windows::Foundation::IClosable>
{
    IPerceptionDepthFrame(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionDepthFrameArrivedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionDepthFrameArrivedEventArgs>
{
    IPerceptionDepthFrameArrivedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionDepthFrameReader :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionDepthFrameReader>,
    impl::require<IPerceptionDepthFrameReader, Windows::Foundation::IClosable>
{
    IPerceptionDepthFrameReader(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionDepthFrameSource :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionDepthFrameSource>
{
    IPerceptionDepthFrameSource(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionDepthFrameSource2 :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionDepthFrameSource2>
{
    IPerceptionDepthFrameSource2(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionDepthFrameSourceAddedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionDepthFrameSourceAddedEventArgs>
{
    IPerceptionDepthFrameSourceAddedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionDepthFrameSourceRemovedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionDepthFrameSourceRemovedEventArgs>
{
    IPerceptionDepthFrameSourceRemovedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionDepthFrameSourceStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionDepthFrameSourceStatics>
{
    IPerceptionDepthFrameSourceStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionDepthFrameSourceWatcher :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionDepthFrameSourceWatcher>
{
    IPerceptionDepthFrameSourceWatcher(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionFrameSourcePropertiesChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionFrameSourcePropertiesChangedEventArgs>
{
    IPerceptionFrameSourcePropertiesChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionFrameSourcePropertyChangeResult :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionFrameSourcePropertyChangeResult>
{
    IPerceptionFrameSourcePropertyChangeResult(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionInfraredFrame :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionInfraredFrame>,
    impl::require<IPerceptionInfraredFrame, Windows::Foundation::IClosable>
{
    IPerceptionInfraredFrame(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionInfraredFrameArrivedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionInfraredFrameArrivedEventArgs>
{
    IPerceptionInfraredFrameArrivedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionInfraredFrameReader :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionInfraredFrameReader>,
    impl::require<IPerceptionInfraredFrameReader, Windows::Foundation::IClosable>
{
    IPerceptionInfraredFrameReader(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionInfraredFrameSource :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionInfraredFrameSource>
{
    IPerceptionInfraredFrameSource(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionInfraredFrameSource2 :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionInfraredFrameSource2>
{
    IPerceptionInfraredFrameSource2(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionInfraredFrameSourceAddedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionInfraredFrameSourceAddedEventArgs>
{
    IPerceptionInfraredFrameSourceAddedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionInfraredFrameSourceRemovedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionInfraredFrameSourceRemovedEventArgs>
{
    IPerceptionInfraredFrameSourceRemovedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionInfraredFrameSourceStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionInfraredFrameSourceStatics>
{
    IPerceptionInfraredFrameSourceStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionInfraredFrameSourceWatcher :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionInfraredFrameSourceWatcher>
{
    IPerceptionInfraredFrameSourceWatcher(std::nullptr_t = nullptr) noexcept {}
};

struct IPerceptionVideoProfile :
    Windows::Foundation::IInspectable,
    impl::consume<IPerceptionVideoProfile>
{
    IPerceptionVideoProfile(std::nullptr_t = nullptr) noexcept {}
};

}

}
