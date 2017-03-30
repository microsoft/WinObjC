// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.SmartCards.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
#define WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
template <> struct __declspec(uuid("cdb5efb3-5788-509d-9be1-71ccb8a3362a")) __declspec(novtable) IAsyncOperation<bool> : impl_IAsyncOperation<bool> {};
#endif

#ifndef WINRT_GENERIC_3e1fe603_f897_5263_b328_0806426b8a79
#define WINRT_GENERIC_3e1fe603_f897_5263_b328_0806426b8a79
template <> struct __declspec(uuid("3e1fe603-f897-5263-b328-0806426b8a79")) __declspec(novtable) IAsyncOperation<hstring> : impl_IAsyncOperation<hstring> {};
#endif

#ifndef WINRT_GENERIC_513ef3af_e784_5325_a91e_97c2b8111cf3
#define WINRT_GENERIC_513ef3af_e784_5325_a91e_97c2b8111cf3
template <> struct __declspec(uuid("513ef3af-e784-5325-a91e-97c2b8111cf3")) __declspec(novtable) IReference<uint32_t> : impl_IReference<uint32_t> {};
#endif

#ifndef WINRT_GENERIC_3bee8834_b9a7_5a80_a746_5ef097227878
#define WINRT_GENERIC_3bee8834_b9a7_5a80_a746_5ef097227878
template <> struct __declspec(uuid("3bee8834-b9a7-5a80-a746-5ef097227878")) __declspec(novtable) IAsyncOperation<Windows::Storage::Streams::IBuffer> : impl_IAsyncOperation<Windows::Storage::Streams::IBuffer> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_fd944562_11d6_5eab_bd72_701993b68fac
#define WINRT_GENERIC_fd944562_11d6_5eab_bd72_701993b68fac
template <> struct __declspec(uuid("fd944562-11d6-5eab-bd72-701993b68fac")) __declspec(novtable) IVectorView<Windows::Storage::Streams::IBuffer> : impl_IVectorView<Windows::Storage::Streams::IBuffer> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_036a830d_bbca_5cb9_977f_b29ea3042149
#define WINRT_GENERIC_036a830d_bbca_5cb9_977f_b29ea3042149
template <> struct __declspec(uuid("036a830d-bbca-5cb9-977f-b29ea3042149")) __declspec(novtable) IAsyncOperation<Windows::Devices::SmartCards::SmartCardReader> : impl_IAsyncOperation<Windows::Devices::SmartCards::SmartCardReader> {};
#endif

#ifndef WINRT_GENERIC_5ae402fa_1f22_5570_a0c8_b2320adedb81
#define WINRT_GENERIC_5ae402fa_1f22_5570_a0c8_b2320adedb81
template <> struct __declspec(uuid("5ae402fa-1f22-5570-a0c8-b2320adedb81")) __declspec(novtable) IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardReaderStatus> : impl_IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardReaderStatus> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_4bee6991_3508_5f03_a2f4_90a5ddb26bd8
#define WINRT_GENERIC_4bee6991_3508_5f03_a2f4_90a5ddb26bd8
template <> struct __declspec(uuid("4bee6991-3508-5f03-a2f4-90a5ddb26bd8")) __declspec(novtable) IVectorView<Windows::Devices::SmartCards::SmartCard> : impl_IVectorView<Windows::Devices::SmartCards::SmartCard> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_d36f2db9_5674_5f74_9f69_3cdc4559999f
#define WINRT_GENERIC_d36f2db9_5674_5f74_9f69_3cdc4559999f
template <> struct __declspec(uuid("d36f2db9-5674-5f74-9f69-3cdc4559999f")) __declspec(novtable) TypedEventHandler<Windows::Devices::SmartCards::SmartCardReader, Windows::Devices::SmartCards::CardAddedEventArgs> : impl_TypedEventHandler<Windows::Devices::SmartCards::SmartCardReader, Windows::Devices::SmartCards::CardAddedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_69da07c6_b266_5a1c_937c_d82b4a8232c6
#define WINRT_GENERIC_69da07c6_b266_5a1c_937c_d82b4a8232c6
template <> struct __declspec(uuid("69da07c6-b266-5a1c-937c-d82b4a8232c6")) __declspec(novtable) TypedEventHandler<Windows::Devices::SmartCards::SmartCardReader, Windows::Devices::SmartCards::CardRemovedEventArgs> : impl_TypedEventHandler<Windows::Devices::SmartCards::SmartCardReader, Windows::Devices::SmartCards::CardRemovedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_e2223376_8cf6_51bd_9907_1344aa665e5d
#define WINRT_GENERIC_e2223376_8cf6_51bd_9907_1344aa665e5d
template <> struct __declspec(uuid("e2223376-8cf6-51bd-9907-1344aa665e5d")) __declspec(novtable) IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardStatus> : impl_IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardStatus> {};
#endif

#ifndef WINRT_GENERIC_6184fc80_b752_5ce8_a136_f57174bb9309
#define WINRT_GENERIC_6184fc80_b752_5ce8_a136_f57174bb9309
template <> struct __declspec(uuid("6184fc80-b752-5ce8-a136-f57174bb9309")) __declspec(novtable) IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> : impl_IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> {};
#endif

#ifndef WINRT_GENERIC_6607bc41_294b_5975_9c3f_4b49836d0916
#define WINRT_GENERIC_6607bc41_294b_5975_9c3f_4b49836d0916
template <> struct __declspec(uuid("6607bc41-294b-5975-9c3f-4b49836d0916")) __declspec(novtable) IAsyncOperation<GUID> : impl_IAsyncOperation<GUID> {};
#endif

#ifndef WINRT_GENERIC_1c650663_3f68_599b_b9d4_c350f13ee4e4
#define WINRT_GENERIC_1c650663_3f68_599b_b9d4_c350f13ee4e4
template <> struct __declspec(uuid("1c650663-3f68-599b-b9d4-c350f13ee4e4")) __declspec(novtable) IAsyncOperation<Windows::Devices::SmartCards::SmartCardChallengeContext> : impl_IAsyncOperation<Windows::Devices::SmartCards::SmartCardChallengeContext> {};
#endif

#ifndef WINRT_GENERIC_779bbc5b_a75c_5988_978f_34dbc629d576
#define WINRT_GENERIC_779bbc5b_a75c_5988_978f_34dbc629d576
template <> struct __declspec(uuid("779bbc5b-a75c-5988-978f-34dbc629d576")) __declspec(novtable) IAsyncOperation<Windows::Devices::SmartCards::SmartCardConnection> : impl_IAsyncOperation<Windows::Devices::SmartCards::SmartCardConnection> {};
#endif

#ifndef WINRT_GENERIC_1dd898f0_c825_5bf3_9564_4708932f955f
#define WINRT_GENERIC_1dd898f0_c825_5bf3_9564_4708932f955f
template <> struct __declspec(uuid("1dd898f0-c825-5bf3-9564-4708932f955f")) __declspec(novtable) IAsyncOperation<Windows::Devices::SmartCards::SmartCardEmulator> : impl_IAsyncOperation<Windows::Devices::SmartCards::SmartCardEmulator> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_b24324ba_192b_568b_81cf_9ac383406ed9
#define WINRT_GENERIC_b24324ba_192b_568b_81cf_9ac383406ed9
template <> struct __declspec(uuid("b24324ba-192b-568b-81cf-9ac383406ed9")) __declspec(novtable) IVectorView<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration> : impl_IVectorView<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_d8030032_5f3c_50e8_91b8_691c454609e8
#define WINRT_GENERIC_d8030032_5f3c_50e8_91b8_691c454609e8
template <> struct __declspec(uuid("d8030032-5f3c-50e8-91b8-691c454609e8")) __declspec(novtable) IAsyncOperation<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration> : impl_IAsyncOperation<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration> {};
#endif

#ifndef WINRT_GENERIC_146f9403_42f4_59a2_a85a_8294af3e3e78
#define WINRT_GENERIC_146f9403_42f4_59a2_a85a_8294af3e3e78
template <> struct __declspec(uuid("146f9403-42f4-59a2-a85a-8294af3e3e78")) __declspec(novtable) TypedEventHandler<Windows::Devices::SmartCards::SmartCardEmulator, Windows::Devices::SmartCards::SmartCardEmulatorApduReceivedEventArgs> : impl_TypedEventHandler<Windows::Devices::SmartCards::SmartCardEmulator, Windows::Devices::SmartCards::SmartCardEmulatorApduReceivedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_cb9840cb_cc46_5c37_ab00_dd23d77b263b
#define WINRT_GENERIC_cb9840cb_cc46_5c37_ab00_dd23d77b263b
template <> struct __declspec(uuid("cb9840cb-cc46-5c37-ab00-dd23d77b263b")) __declspec(novtable) TypedEventHandler<Windows::Devices::SmartCards::SmartCardEmulator, Windows::Devices::SmartCards::SmartCardEmulatorConnectionDeactivatedEventArgs> : impl_TypedEventHandler<Windows::Devices::SmartCards::SmartCardEmulator, Windows::Devices::SmartCards::SmartCardEmulatorConnectionDeactivatedEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_308fe894_cc06_5007_bc85_cbe94ac1a70c
#define WINRT_GENERIC_308fe894_cc06_5007_bc85_cbe94ac1a70c
template <> struct __declspec(uuid("308fe894-cc06-5007-bc85-cbe94ac1a70c")) __declspec(novtable) IVector<Windows::Storage::Streams::IBuffer> : impl_IVector<Windows::Storage::Streams::IBuffer> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_b8f15d35_2f3d_53aa_b5c6_faca4c7ff16e
#define WINRT_GENERIC_b8f15d35_2f3d_53aa_b5c6_faca4c7ff16e
template <> struct __declspec(uuid("b8f15d35-2f3d-53aa-b5c6-faca4c7ff16e")) __declspec(novtable) IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardActivationPolicyChangeResult> : impl_IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardActivationPolicyChangeResult> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_db52d376_027e_5270_a457_fb8b4ae8958c
#define WINRT_GENERIC_db52d376_027e_5270_a457_fb8b4ae8958c
template <> struct __declspec(uuid("db52d376-027e-5270-a457-fb8b4ae8958c")) __declspec(novtable) IIterable<Windows::Devices::SmartCards::SmartCardAutomaticResponseApdu> : impl_IIterable<Windows::Devices::SmartCards::SmartCardAutomaticResponseApdu> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_f5b0e1b0_57a7_5ab3_aeaa_d6b635257866
#define WINRT_GENERIC_f5b0e1b0_57a7_5ab3_aeaa_d6b635257866
template <> struct __declspec(uuid("f5b0e1b0-57a7-5ab3-aeaa-d6b635257866")) __declspec(novtable) IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> : impl_IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_234ab631_ed5f_51bc_8a8a_d5f3495f32de
#define WINRT_GENERIC_234ab631_ed5f_51bc_8a8a_d5f3495f32de
template <> struct __declspec(uuid("234ab631-ed5f-51bc-8a8a-d5f3495f32de")) __declspec(novtable) IIterable<Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep> : impl_IIterable<Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_5dfde47d_9770_5f44_a983_f2fee430768e
#define WINRT_GENERIC_5dfde47d_9770_5f44_a983_f2fee430768e
template <> struct __declspec(uuid("5dfde47d-9770-5f44-a983-f2fee430768e")) __declspec(novtable) IAsyncOperation<Windows::Devices::SmartCards::SmartCardCryptogramGenerator> : impl_IAsyncOperation<Windows::Devices::SmartCards::SmartCardCryptogramGenerator> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_394bc0cc_c621_5ba3_b4f0_712fcf591392
#define WINRT_GENERIC_394bc0cc_c621_5ba3_b4f0_712fcf591392
template <> struct __declspec(uuid("394bc0cc-c621-5ba3-b4f0-712fcf591392")) __declspec(novtable) IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialType> : impl_IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialType> {};
#endif

#ifndef WINRT_GENERIC_a9df831c_c22b_5d30_a86c_5a31fe192433
#define WINRT_GENERIC_a9df831c_c22b_5d30_a86c_5a31fe192433
template <> struct __declspec(uuid("a9df831c-c22b-5d30-a86c-5a31fe192433")) __declspec(novtable) IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramAlgorithm> : impl_IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramAlgorithm> {};
#endif

#ifndef WINRT_GENERIC_b7cce3f2_9889_586c_beb1_68feddb7cb15
#define WINRT_GENERIC_b7cce3f2_9889_586c_beb1_68feddb7cb15
template <> struct __declspec(uuid("b7cce3f2-9889-586c-beb1-68feddb7cb15")) __declspec(novtable) IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageFormat> : impl_IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageFormat> {};
#endif

#ifndef WINRT_GENERIC_3a4176a2_d221_5a9f_a4c2_a5b8736da2d8
#define WINRT_GENERIC_3a4176a2_d221_5a9f_a4c2_a5b8736da2d8
template <> struct __declspec(uuid("3a4176a2-d221-5a9f-a4c2-a5b8736da2d8")) __declspec(novtable) IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageConfirmationResponseFormat> : impl_IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageConfirmationResponseFormat> {};
#endif

#ifndef WINRT_GENERIC_9c0dfca0_4b62_56a8_8af3_8376898a15bc
#define WINRT_GENERIC_9c0dfca0_4b62_56a8_8af3_8376898a15bc
template <> struct __declspec(uuid("9c0dfca0-4b62-56a8-8af3-8376898a15bc")) __declspec(novtable) IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities> : impl_IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_2187f5a4_691c_50e1_bf4f_ddedc3e684b8
#define WINRT_GENERIC_2187f5a4_691c_50e1_bf4f_ddedc3e684b8
template <> struct __declspec(uuid("2187f5a4-691c-50e1-bf4f-ddedc3e684b8")) __declspec(novtable) IAsyncOperation<Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyInfo> : impl_IAsyncOperation<Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyInfo> {};
#endif

#ifndef WINRT_GENERIC_6f2eea36_de40_55b4_90c3_255673f71b2e
#define WINRT_GENERIC_6f2eea36_de40_55b4_90c3_255673f71b2e
template <> struct __declspec(uuid("6f2eea36-de40-55b4-90c3-255673f71b2e")) __declspec(novtable) IAsyncOperation<Windows::Devices::SmartCards::SmartCardCryptogramMaterialPossessionProof> : impl_IAsyncOperation<Windows::Devices::SmartCards::SmartCardCryptogramMaterialPossessionProof> {};
#endif

#ifndef WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
#define WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
template <> struct __declspec(uuid("c1d3d1a2-ae17-5a5f-b5a2-bdcc8844889a")) __declspec(novtable) AsyncOperationCompletedHandler<bool> : impl_AsyncOperationCompletedHandler<bool> {};
#endif

#ifndef WINRT_GENERIC_b79a741f_7fb5_50ae_9e99_911201ec3d41
#define WINRT_GENERIC_b79a741f_7fb5_50ae_9e99_911201ec3d41
template <> struct __declspec(uuid("b79a741f-7fb5-50ae-9e99-911201ec3d41")) __declspec(novtable) AsyncOperationCompletedHandler<hstring> : impl_AsyncOperationCompletedHandler<hstring> {};
#endif

#ifndef WINRT_GENERIC_51c3d2fd_b8a1_5620_b746_7ee6d533aca3
#define WINRT_GENERIC_51c3d2fd_b8a1_5620_b746_7ee6d533aca3
template <> struct __declspec(uuid("51c3d2fd-b8a1-5620-b746-7ee6d533aca3")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Storage::Streams::IBuffer> : impl_AsyncOperationCompletedHandler<Windows::Storage::Streams::IBuffer> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_afee38e0_f882_5f10_9655_1fc98cc8cce5
#define WINRT_GENERIC_afee38e0_f882_5f10_9655_1fc98cc8cce5
template <> struct __declspec(uuid("afee38e0-f882-5f10-9655-1fc98cc8cce5")) __declspec(novtable) IIterator<Windows::Storage::Streams::IBuffer> : impl_IIterator<Windows::Storage::Streams::IBuffer> {};
#endif

#ifndef WINRT_GENERIC_902972bf_a984_5443_b1c5_2f04a99e1fca
#define WINRT_GENERIC_902972bf_a984_5443_b1c5_2f04a99e1fca
template <> struct __declspec(uuid("902972bf-a984-5443-b1c5-2f04a99e1fca")) __declspec(novtable) IIterable<Windows::Storage::Streams::IBuffer> : impl_IIterable<Windows::Storage::Streams::IBuffer> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_20d3244d_375a_5f7d_8944_164fdfed4239
#define WINRT_GENERIC_20d3244d_375a_5f7d_8944_164fdfed4239
template <> struct __declspec(uuid("20d3244d-375a-5f7d-8944-164fdfed4239")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::SmartCards::SmartCardReader> : impl_AsyncOperationCompletedHandler<Windows::Devices::SmartCards::SmartCardReader> {};
#endif

#ifndef WINRT_GENERIC_3d7e6ea9_e739_555c_9c02_07396c5321f5
#define WINRT_GENERIC_3d7e6ea9_e739_555c_9c02_07396c5321f5
template <> struct __declspec(uuid("3d7e6ea9-e739-555c-9c02-07396c5321f5")) __declspec(novtable) AsyncOperationCompletedHandler<winrt::Windows::Devices::SmartCards::SmartCardReaderStatus> : impl_AsyncOperationCompletedHandler<winrt::Windows::Devices::SmartCards::SmartCardReaderStatus> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_86b29903_916e_5817_bc96_df324475e31a
#define WINRT_GENERIC_86b29903_916e_5817_bc96_df324475e31a
template <> struct __declspec(uuid("86b29903-916e-5817-bc96-df324475e31a")) __declspec(novtable) IIterator<Windows::Devices::SmartCards::SmartCard> : impl_IIterator<Windows::Devices::SmartCards::SmartCard> {};
#endif

#ifndef WINRT_GENERIC_a32c5202_d113_535f_880e_50f3e5121ef8
#define WINRT_GENERIC_a32c5202_d113_535f_880e_50f3e5121ef8
template <> struct __declspec(uuid("a32c5202-d113-535f-880e-50f3e5121ef8")) __declspec(novtable) IIterable<Windows::Devices::SmartCards::SmartCard> : impl_IIterable<Windows::Devices::SmartCards::SmartCard> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_bdaf4a41_3b4a_56b0_aeec_fee71cc7f328
#define WINRT_GENERIC_bdaf4a41_3b4a_56b0_aeec_fee71cc7f328
template <> struct __declspec(uuid("bdaf4a41-3b4a-56b0-aeec-fee71cc7f328")) __declspec(novtable) AsyncOperationCompletedHandler<winrt::Windows::Devices::SmartCards::SmartCardStatus> : impl_AsyncOperationCompletedHandler<winrt::Windows::Devices::SmartCards::SmartCardStatus> {};
#endif

#ifndef WINRT_GENERIC_7a2e58dc_22ee_5cb8_83cc_a7a61b9dcd2c
#define WINRT_GENERIC_7a2e58dc_22ee_5cb8_83cc_a7a61b9dcd2c
template <> struct __declspec(uuid("7a2e58dc-22ee-5cb8-83cc-a7a61b9dcd2c")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::SmartCards::SmartCardProvisioning> : impl_AsyncOperationCompletedHandler<Windows::Devices::SmartCards::SmartCardProvisioning> {};
#endif

#ifndef WINRT_GENERIC_5233899b_ba7e_504f_bb83_ceebac62decf
#define WINRT_GENERIC_5233899b_ba7e_504f_bb83_ceebac62decf
template <> struct __declspec(uuid("5233899b-ba7e-504f-bb83-ceebac62decf")) __declspec(novtable) AsyncOperationCompletedHandler<GUID> : impl_AsyncOperationCompletedHandler<GUID> {};
#endif

#ifndef WINRT_GENERIC_96b172f6_dedb_5f3e_af90_7b0f10219352
#define WINRT_GENERIC_96b172f6_dedb_5f3e_af90_7b0f10219352
template <> struct __declspec(uuid("96b172f6-dedb-5f3e-af90-7b0f10219352")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::SmartCards::SmartCardChallengeContext> : impl_AsyncOperationCompletedHandler<Windows::Devices::SmartCards::SmartCardChallengeContext> {};
#endif

#ifndef WINRT_GENERIC_c71f00e6_af26_5e5c_913d_0efeb7d08ef7
#define WINRT_GENERIC_c71f00e6_af26_5e5c_913d_0efeb7d08ef7
template <> struct __declspec(uuid("c71f00e6-af26-5e5c-913d-0efeb7d08ef7")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::SmartCards::SmartCardConnection> : impl_AsyncOperationCompletedHandler<Windows::Devices::SmartCards::SmartCardConnection> {};
#endif

#ifndef WINRT_GENERIC_4982e406_052c_5782_a57d_54f9f44f8412
#define WINRT_GENERIC_4982e406_052c_5782_a57d_54f9f44f8412
template <> struct __declspec(uuid("4982e406-052c-5782-a57d-54f9f44f8412")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::SmartCards::SmartCardEmulator> : impl_AsyncOperationCompletedHandler<Windows::Devices::SmartCards::SmartCardEmulator> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_d3777a61_2106_505f_bcfa_b3cc8e1412e1
#define WINRT_GENERIC_d3777a61_2106_505f_bcfa_b3cc8e1412e1
template <> struct __declspec(uuid("d3777a61-2106-505f-bcfa-b3cc8e1412e1")) __declspec(novtable) IIterator<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration> : impl_IIterator<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration> {};
#endif

#ifndef WINRT_GENERIC_4d153aad_915c_59c9_98b9_a97bf3a570ad
#define WINRT_GENERIC_4d153aad_915c_59c9_98b9_a97bf3a570ad
template <> struct __declspec(uuid("4d153aad-915c-59c9-98b9-a97bf3a570ad")) __declspec(novtable) IIterable<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration> : impl_IIterable<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_371045fb_4994_5413_89be_ba4e97ad82a0
#define WINRT_GENERIC_371045fb_4994_5413_89be_ba4e97ad82a0
template <> struct __declspec(uuid("371045fb-4994-5413-89be-ba4e97ad82a0")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration> : impl_AsyncOperationCompletedHandler<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration> {};
#endif

#ifndef WINRT_GENERIC_9528f94b_047b_5e2a_8fc0_7017f5daddff
#define WINRT_GENERIC_9528f94b_047b_5e2a_8fc0_7017f5daddff
template <> struct __declspec(uuid("9528f94b-047b-5e2a-8fc0-7017f5daddff")) __declspec(novtable) AsyncOperationCompletedHandler<winrt::Windows::Devices::SmartCards::SmartCardActivationPolicyChangeResult> : impl_AsyncOperationCompletedHandler<winrt::Windows::Devices::SmartCards::SmartCardActivationPolicyChangeResult> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_78eb5c52_9dd2_5e35_a868_f64919eba6b6
#define WINRT_GENERIC_78eb5c52_9dd2_5e35_a868_f64919eba6b6
template <> struct __declspec(uuid("78eb5c52-9dd2-5e35-a868-f64919eba6b6")) __declspec(novtable) IIterator<Windows::Devices::SmartCards::SmartCardAutomaticResponseApdu> : impl_IIterator<Windows::Devices::SmartCards::SmartCardAutomaticResponseApdu> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_c6c447c7_a60d_500a_9bfe_59f25c33e979
#define WINRT_GENERIC_c6c447c7_a60d_500a_9bfe_59f25c33e979
template <> struct __declspec(uuid("c6c447c7-a60d-500a-9bfe-59f25c33e979")) __declspec(novtable) AsyncOperationCompletedHandler<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> : impl_AsyncOperationCompletedHandler<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_81a62a70_8acd_598c_8d0a_a27d23e6cb1e
#define WINRT_GENERIC_81a62a70_8acd_598c_8d0a_a27d23e6cb1e
template <> struct __declspec(uuid("81a62a70-8acd-598c-8d0a-a27d23e6cb1e")) __declspec(novtable) IIterator<Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep> : impl_IIterator<Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_25cc9462_46a1_50a6_ad14_9a9718372005
#define WINRT_GENERIC_25cc9462_46a1_50a6_ad14_9a9718372005
template <> struct __declspec(uuid("25cc9462-46a1-50a6-ad14-9a9718372005")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::SmartCards::SmartCardCryptogramGenerator> : impl_AsyncOperationCompletedHandler<Windows::Devices::SmartCards::SmartCardCryptogramGenerator> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_97e1414d_439a_5dc2_81fc_d988e32c8dab
#define WINRT_GENERIC_97e1414d_439a_5dc2_81fc_d988e32c8dab
template <> struct __declspec(uuid("97e1414d-439a-5dc2-81fc-d988e32c8dab")) __declspec(novtable) IIterator<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialType> : impl_IIterator<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialType> {};
#endif

#ifndef WINRT_GENERIC_2d379f84_389c_5809_a2c6_919b47caab88
#define WINRT_GENERIC_2d379f84_389c_5809_a2c6_919b47caab88
template <> struct __declspec(uuid("2d379f84-389c-5809-a2c6-919b47caab88")) __declspec(novtable) IIterable<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialType> : impl_IIterable<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialType> {};
#endif

#ifndef WINRT_GENERIC_4f1e0492_dab2_53c3_b5fb_c4b4373b1ec2
#define WINRT_GENERIC_4f1e0492_dab2_53c3_b5fb_c4b4373b1ec2
template <> struct __declspec(uuid("4f1e0492-dab2-53c3-b5fb-c4b4373b1ec2")) __declspec(novtable) IIterator<winrt::Windows::Devices::SmartCards::SmartCardCryptogramAlgorithm> : impl_IIterator<winrt::Windows::Devices::SmartCards::SmartCardCryptogramAlgorithm> {};
#endif

#ifndef WINRT_GENERIC_8e0de0e9_0742_559e_9b1b_460268622c1f
#define WINRT_GENERIC_8e0de0e9_0742_559e_9b1b_460268622c1f
template <> struct __declspec(uuid("8e0de0e9-0742-559e-9b1b-460268622c1f")) __declspec(novtable) IIterable<winrt::Windows::Devices::SmartCards::SmartCardCryptogramAlgorithm> : impl_IIterable<winrt::Windows::Devices::SmartCards::SmartCardCryptogramAlgorithm> {};
#endif

#ifndef WINRT_GENERIC_7bf75a02_ee7e_513a_80f8_f7d8f004c907
#define WINRT_GENERIC_7bf75a02_ee7e_513a_80f8_f7d8f004c907
template <> struct __declspec(uuid("7bf75a02-ee7e-513a-80f8-f7d8f004c907")) __declspec(novtable) IIterator<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageFormat> : impl_IIterator<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageFormat> {};
#endif

#ifndef WINRT_GENERIC_3e241acc_1745_57ce_9368_21ba2130c3c1
#define WINRT_GENERIC_3e241acc_1745_57ce_9368_21ba2130c3c1
template <> struct __declspec(uuid("3e241acc-1745-57ce-9368-21ba2130c3c1")) __declspec(novtable) IIterable<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageFormat> : impl_IIterable<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageFormat> {};
#endif

#ifndef WINRT_GENERIC_9d1091ae_be37_5be7_8edf_60c5164880b6
#define WINRT_GENERIC_9d1091ae_be37_5be7_8edf_60c5164880b6
template <> struct __declspec(uuid("9d1091ae-be37-5be7-8edf-60c5164880b6")) __declspec(novtable) IIterator<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageConfirmationResponseFormat> : impl_IIterator<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageConfirmationResponseFormat> {};
#endif

#ifndef WINRT_GENERIC_c40c4451_4ebb_5635_9c7d_33c8c5d37a09
#define WINRT_GENERIC_c40c4451_4ebb_5635_9c7d_33c8c5d37a09
template <> struct __declspec(uuid("c40c4451-4ebb-5635-9c7d-33c8c5d37a09")) __declspec(novtable) IIterable<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageConfirmationResponseFormat> : impl_IIterable<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageConfirmationResponseFormat> {};
#endif

#ifndef WINRT_GENERIC_c858d7a0_c54e_513c_a097_a42fd3d569af
#define WINRT_GENERIC_c858d7a0_c54e_513c_a097_a42fd3d569af
template <> struct __declspec(uuid("c858d7a0-c54e-513c-a097-a42fd3d569af")) __declspec(novtable) IIterator<winrt::Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities> : impl_IIterator<winrt::Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities> {};
#endif

#ifndef WINRT_GENERIC_983619f1_45b9_5557_9800_eaa2bca6da57
#define WINRT_GENERIC_983619f1_45b9_5557_9800_eaa2bca6da57
template <> struct __declspec(uuid("983619f1-45b9-5557-9800-eaa2bca6da57")) __declspec(novtable) IIterable<winrt::Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities> : impl_IIterable<winrt::Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_3f34e667_0a36_5414_88ab_6371d1b3b07e
#define WINRT_GENERIC_3f34e667_0a36_5414_88ab_6371d1b3b07e
template <> struct __declspec(uuid("3f34e667-0a36-5414-88ab-6371d1b3b07e")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyInfo> : impl_AsyncOperationCompletedHandler<Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyInfo> {};
#endif

#ifndef WINRT_GENERIC_caf2474e_8810_5b17_95d6_81758ae51985
#define WINRT_GENERIC_caf2474e_8810_5b17_95d6_81758ae51985
template <> struct __declspec(uuid("caf2474e-8810-5b17-95d6-81758ae51985")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::SmartCards::SmartCardCryptogramMaterialPossessionProof> : impl_AsyncOperationCompletedHandler<Windows::Devices::SmartCards::SmartCardCryptogramMaterialPossessionProof> {};
#endif

#ifndef WINRT_GENERIC_3b2691b2_fc5e_59ff_8c6f_e6dd29a967fc
#define WINRT_GENERIC_3b2691b2_fc5e_59ff_8c6f_e6dd29a967fc
template <> struct __declspec(uuid("3b2691b2-fc5e-59ff-8c6f-e6dd29a967fc")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::SmartCards::SmartCard>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::SmartCards::SmartCard>> {};
#endif

#ifndef WINRT_GENERIC_045e34b9_f153_5920_99de_ed912ea38b1a
#define WINRT_GENERIC_045e34b9_f153_5920_99de_ed912ea38b1a
template <> struct __declspec(uuid("045e34b9-f153-5920-99de-ed912ea38b1a")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration>> {};
#endif

#ifndef WINRT_GENERIC_bfea3fad_411e_5721_88f5_92c9b9fbbe14
#define WINRT_GENERIC_bfea3fad_411e_5721_88f5_92c9b9fbbe14
template <> struct __declspec(uuid("bfea3fad-411e-5721-88f5-92c9b9fbbe14")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Devices::SmartCards::SmartCard>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Devices::SmartCards::SmartCard>> {};
#endif

#ifndef WINRT_GENERIC_dddeb324_2853_5e3c_a4d9_1ca8c577c02e
#define WINRT_GENERIC_dddeb324_2853_5e3c_a4d9_1ca8c577c02e
template <> struct __declspec(uuid("dddeb324-2853-5e3c-a4d9-1ca8c577c02e")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration>> {};
#endif


}

namespace Windows::Devices::SmartCards {

struct SmartCardPinResetHandler : Windows::Foundation::IUnknown
{
    SmartCardPinResetHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> SmartCardPinResetHandler(L lambda);
    template <typename F> SmartCardPinResetHandler (F * function);
    template <typename O, typename M> SmartCardPinResetHandler(O * object, M method);
    void operator()(const Windows::Devices::SmartCards::SmartCardProvisioning & sender, const Windows::Devices::SmartCards::SmartCardPinResetRequest & request) const;
};

struct ICardAddedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ICardAddedEventArgs>
{
    ICardAddedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ICardRemovedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ICardRemovedEventArgs>
{
    ICardRemovedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCard :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCard>
{
    ISmartCard(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardAppletIdGroup :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardAppletIdGroup>
{
    ISmartCardAppletIdGroup(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardAppletIdGroupFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardAppletIdGroupFactory>
{
    ISmartCardAppletIdGroupFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardAppletIdGroupRegistration :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardAppletIdGroupRegistration>
{
    ISmartCardAppletIdGroupRegistration(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardAppletIdGroupStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardAppletIdGroupStatics>
{
    ISmartCardAppletIdGroupStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardAutomaticResponseApdu :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardAutomaticResponseApdu>
{
    ISmartCardAutomaticResponseApdu(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardAutomaticResponseApdu2 :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardAutomaticResponseApdu2>
{
    ISmartCardAutomaticResponseApdu2(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardAutomaticResponseApdu3 :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardAutomaticResponseApdu3>
{
    ISmartCardAutomaticResponseApdu3(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardAutomaticResponseApduFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardAutomaticResponseApduFactory>
{
    ISmartCardAutomaticResponseApduFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardChallengeContext :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardChallengeContext>,
    impl::require<ISmartCardChallengeContext, Windows::Foundation::IClosable>
{
    ISmartCardChallengeContext(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardConnect :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardConnect>
{
    ISmartCardConnect(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardConnection :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardConnection>,
    impl::require<ISmartCardConnection, Windows::Foundation::IClosable>
{
    ISmartCardConnection(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardCryptogramGenerator :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardCryptogramGenerator>
{
    ISmartCardCryptogramGenerator(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardCryptogramGeneratorStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardCryptogramGeneratorStatics>
{
    ISmartCardCryptogramGeneratorStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardCryptogramMaterialPossessionProof :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardCryptogramMaterialPossessionProof>
{
    ISmartCardCryptogramMaterialPossessionProof(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardCryptogramPlacementStep :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardCryptogramPlacementStep>
{
    ISmartCardCryptogramPlacementStep(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardCryptogramStorageKeyInfo :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardCryptogramStorageKeyInfo>
{
    ISmartCardCryptogramStorageKeyInfo(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardCryptogramStorageKeyInfo2 :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardCryptogramStorageKeyInfo2>
{
    ISmartCardCryptogramStorageKeyInfo2(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardEmulator :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardEmulator>
{
    ISmartCardEmulator(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardEmulator2 :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardEmulator2>
{
    ISmartCardEmulator2(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardEmulatorApduReceivedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardEmulatorApduReceivedEventArgs>
{
    ISmartCardEmulatorApduReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardEmulatorApduReceivedEventArgs2 :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardEmulatorApduReceivedEventArgs2>
{
    ISmartCardEmulatorApduReceivedEventArgs2(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardEmulatorApduReceivedEventArgsWithCryptograms :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardEmulatorApduReceivedEventArgsWithCryptograms>
{
    ISmartCardEmulatorApduReceivedEventArgsWithCryptograms(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardEmulatorConnectionDeactivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardEmulatorConnectionDeactivatedEventArgs>
{
    ISmartCardEmulatorConnectionDeactivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardEmulatorConnectionProperties :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardEmulatorConnectionProperties>
{
    ISmartCardEmulatorConnectionProperties(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardEmulatorStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardEmulatorStatics>
{
    ISmartCardEmulatorStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardEmulatorStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardEmulatorStatics2>
{
    ISmartCardEmulatorStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardPinPolicy :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardPinPolicy>
{
    ISmartCardPinPolicy(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardPinResetDeferral :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardPinResetDeferral>
{
    ISmartCardPinResetDeferral(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardPinResetRequest :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardPinResetRequest>
{
    ISmartCardPinResetRequest(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardProvisioning :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardProvisioning>
{
    ISmartCardProvisioning(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardProvisioning2 :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardProvisioning2>
{
    ISmartCardProvisioning2(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardProvisioningStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardProvisioningStatics>
{
    ISmartCardProvisioningStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardProvisioningStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardProvisioningStatics2>
{
    ISmartCardProvisioningStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardReader :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardReader>
{
    ISmartCardReader(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardReaderStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardReaderStatics>
{
    ISmartCardReaderStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardTriggerDetails :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardTriggerDetails>
{
    ISmartCardTriggerDetails(std::nullptr_t = nullptr) noexcept {}
};

struct ISmartCardTriggerDetails2 :
    Windows::Foundation::IInspectable,
    impl::consume<ISmartCardTriggerDetails2>
{
    ISmartCardTriggerDetails2(std::nullptr_t = nullptr) noexcept {}
};

}

}
