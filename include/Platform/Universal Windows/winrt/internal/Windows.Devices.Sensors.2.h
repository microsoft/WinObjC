// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Sensors.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.2.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_513ef3af_e784_5325_a91e_97c2b8111cf3
#define WINRT_GENERIC_513ef3af_e784_5325_a91e_97c2b8111cf3
template <> struct __declspec(uuid("513ef3af-e784-5325-a91e-97c2b8111cf3")) __declspec(novtable) IReference<uint32_t> : impl_IReference<uint32_t> {};
#endif

#ifndef WINRT_GENERIC_2f2d6c29_5473_5f3e_92e7_96572bb990e2
#define WINRT_GENERIC_2f2d6c29_5473_5f3e_92e7_96572bb990e2
template <> struct __declspec(uuid("2f2d6c29-5473-5f3e-92e7-96572bb990e2")) __declspec(novtable) IReference<double> : impl_IReference<double> {};
#endif

#ifndef WINRT_GENERIC_a5e83e40_b597_5b83_92f5_5bed3926ca80
#define WINRT_GENERIC_a5e83e40_b597_5b83_92f5_5bed3926ca80
template <> struct __declspec(uuid("a5e83e40-b597-5b83-92f5-5bed3926ca80")) __declspec(novtable) TypedEventHandler<Windows::Devices::Sensors::Accelerometer, Windows::Devices::Sensors::AccelerometerReadingChangedEventArgs> : impl_TypedEventHandler<Windows::Devices::Sensors::Accelerometer, Windows::Devices::Sensors::AccelerometerReadingChangedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_3e5d6eaf_f169_5d60_92b0_98cd6bd8f808
#define WINRT_GENERIC_3e5d6eaf_f169_5d60_92b0_98cd6bd8f808
template <> struct __declspec(uuid("3e5d6eaf-f169-5d60-92b0-98cd6bd8f808")) __declspec(novtable) TypedEventHandler<Windows::Devices::Sensors::Accelerometer, Windows::Devices::Sensors::AccelerometerShakenEventArgs> : impl_TypedEventHandler<Windows::Devices::Sensors::Accelerometer, Windows::Devices::Sensors::AccelerometerShakenEventArgs> {};
#endif

#ifndef WINRT_GENERIC_6f3b411f_d147_59f1_bbe4_7bec396c7b6e
#define WINRT_GENERIC_6f3b411f_d147_59f1_bbe4_7bec396c7b6e
template <> struct __declspec(uuid("6f3b411f-d147-59f1-bbe4-7bec396c7b6e")) __declspec(novtable) TypedEventHandler<Windows::Devices::Sensors::Inclinometer, Windows::Devices::Sensors::InclinometerReadingChangedEventArgs> : impl_TypedEventHandler<Windows::Devices::Sensors::Inclinometer, Windows::Devices::Sensors::InclinometerReadingChangedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_15171524_5786_59a5_af5b_a01245726c44
#define WINRT_GENERIC_15171524_5786_59a5_af5b_a01245726c44
template <> struct __declspec(uuid("15171524-5786-59a5-af5b-a01245726c44")) __declspec(novtable) TypedEventHandler<Windows::Devices::Sensors::Gyrometer, Windows::Devices::Sensors::GyrometerReadingChangedEventArgs> : impl_TypedEventHandler<Windows::Devices::Sensors::Gyrometer, Windows::Devices::Sensors::GyrometerReadingChangedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_e787d73d_a121_5ae6_b497_ab934837e57f
#define WINRT_GENERIC_e787d73d_a121_5ae6_b497_ab934837e57f
template <> struct __declspec(uuid("e787d73d-a121-5ae6-b497-ab934837e57f")) __declspec(novtable) TypedEventHandler<Windows::Devices::Sensors::Compass, Windows::Devices::Sensors::CompassReadingChangedEventArgs> : impl_TypedEventHandler<Windows::Devices::Sensors::Compass, Windows::Devices::Sensors::CompassReadingChangedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_1ecf183a_9f0a_5f73_9225_5a33eab5594f
#define WINRT_GENERIC_1ecf183a_9f0a_5f73_9225_5a33eab5594f
template <> struct __declspec(uuid("1ecf183a-9f0a-5f73-9225-5a33eab5594f")) __declspec(novtable) TypedEventHandler<Windows::Devices::Sensors::LightSensor, Windows::Devices::Sensors::LightSensorReadingChangedEventArgs> : impl_TypedEventHandler<Windows::Devices::Sensors::LightSensor, Windows::Devices::Sensors::LightSensorReadingChangedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_91ae0c43_e1f7_577d_a161_8aaf275eb927
#define WINRT_GENERIC_91ae0c43_e1f7_577d_a161_8aaf275eb927
template <> struct __declspec(uuid("91ae0c43-e1f7-577d-a161-8aaf275eb927")) __declspec(novtable) TypedEventHandler<Windows::Devices::Sensors::OrientationSensor, Windows::Devices::Sensors::OrientationSensorReadingChangedEventArgs> : impl_TypedEventHandler<Windows::Devices::Sensors::OrientationSensor, Windows::Devices::Sensors::OrientationSensorReadingChangedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_92437fa7_ea7b_5fc5_8ecf_1b911bea2bfc
#define WINRT_GENERIC_92437fa7_ea7b_5fc5_8ecf_1b911bea2bfc
template <> struct __declspec(uuid("92437fa7-ea7b-5fc5-8ecf-1b911bea2bfc")) __declspec(novtable) TypedEventHandler<Windows::Devices::Sensors::SimpleOrientationSensor, Windows::Devices::Sensors::SimpleOrientationSensorOrientationChangedEventArgs> : impl_TypedEventHandler<Windows::Devices::Sensors::SimpleOrientationSensor, Windows::Devices::Sensors::SimpleOrientationSensorOrientationChangedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_f9a0da76_c4fd_50ab_98b6_bfd26d6d3d82
#define WINRT_GENERIC_f9a0da76_c4fd_50ab_98b6_bfd26d6d3d82
template <> struct __declspec(uuid("f9a0da76-c4fd-50ab-98b6-bfd26d6d3d82")) __declspec(novtable) TypedEventHandler<Windows::Devices::Sensors::Magnetometer, Windows::Devices::Sensors::MagnetometerReadingChangedEventArgs> : impl_TypedEventHandler<Windows::Devices::Sensors::Magnetometer, Windows::Devices::Sensors::MagnetometerReadingChangedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_c33003ae_e7ae_572b_8d55_7db197356c30
#define WINRT_GENERIC_c33003ae_e7ae_572b_8d55_7db197356c30
template <> struct __declspec(uuid("c33003ae-e7ae-572b-8d55-7db197356c30")) __declspec(novtable) IAsyncOperation<Windows::Devices::Sensors::ActivitySensor> : impl_IAsyncOperation<Windows::Devices::Sensors::ActivitySensor> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_726234a9_7137_55c4_a444_352dcdc30d77
#define WINRT_GENERIC_726234a9_7137_55c4_a444_352dcdc30d77
template <> struct __declspec(uuid("726234a9-7137-55c4-a444-352dcdc30d77")) __declspec(novtable) IVectorView<Windows::Devices::Sensors::ActivitySensorReading> : impl_IVectorView<Windows::Devices::Sensors::ActivitySensorReading> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_79a87969_327f_5b7a_a0d3_73eab16de21c
#define WINRT_GENERIC_79a87969_327f_5b7a_a0d3_73eab16de21c
template <> struct __declspec(uuid("79a87969-327f-5b7a-a0d3-73eab16de21c")) __declspec(novtable) IAsyncOperation<Windows::Devices::Sensors::ActivitySensorReading> : impl_IAsyncOperation<Windows::Devices::Sensors::ActivitySensorReading> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_e3e660d6_d041_5ecd_b18b_fa254e4a860f
#define WINRT_GENERIC_e3e660d6_d041_5ecd_b18b_fa254e4a860f
template <> struct __declspec(uuid("e3e660d6-d041-5ecd-b18b-fa254e4a860f")) __declspec(novtable) IVector<winrt::Windows::Devices::Sensors::ActivityType> : impl_IVector<winrt::Windows::Devices::Sensors::ActivityType> {};
#endif

#ifndef WINRT_GENERIC_fc7a0488_2803_505c_9e62_9200afe416c6
#define WINRT_GENERIC_fc7a0488_2803_505c_9e62_9200afe416c6
template <> struct __declspec(uuid("fc7a0488-2803-505c-9e62-9200afe416c6")) __declspec(novtable) IVectorView<winrt::Windows::Devices::Sensors::ActivityType> : impl_IVectorView<winrt::Windows::Devices::Sensors::ActivityType> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_a5b72e01_546c_5fbb_b847_49200aaaaac5
#define WINRT_GENERIC_a5b72e01_546c_5fbb_b847_49200aaaaac5
template <> struct __declspec(uuid("a5b72e01-546c-5fbb-b847-49200aaaaac5")) __declspec(novtable) TypedEventHandler<Windows::Devices::Sensors::ActivitySensor, Windows::Devices::Sensors::ActivitySensorReadingChangedEventArgs> : impl_TypedEventHandler<Windows::Devices::Sensors::ActivitySensor, Windows::Devices::Sensors::ActivitySensorReadingChangedEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_10e48a80_dd6a_5704_8f3d_3d46111f391e
#define WINRT_GENERIC_10e48a80_dd6a_5704_8f3d_3d46111f391e
template <> struct __declspec(uuid("10e48a80-dd6a-5704-8f3d-3d46111f391e")) __declspec(novtable) IVectorView<Windows::Devices::Sensors::ActivitySensorReadingChangeReport> : impl_IVectorView<Windows::Devices::Sensors::ActivitySensorReadingChangeReport> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_e4caf459_d101_5ca5_a4ea_deb0917ae27e
#define WINRT_GENERIC_e4caf459_d101_5ca5_a4ea_deb0917ae27e
template <> struct __declspec(uuid("e4caf459-d101-5ca5-a4ea-deb0917ae27e")) __declspec(novtable) TypedEventHandler<Windows::Devices::Sensors::Barometer, Windows::Devices::Sensors::BarometerReadingChangedEventArgs> : impl_TypedEventHandler<Windows::Devices::Sensors::Barometer, Windows::Devices::Sensors::BarometerReadingChangedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_9414388f_1b3e_55f5_819b_ab3833646055
#define WINRT_GENERIC_9414388f_1b3e_55f5_819b_ab3833646055
template <> struct __declspec(uuid("9414388f-1b3e-55f5-819b-ab3833646055")) __declspec(novtable) IAsyncOperation<Windows::Devices::Sensors::Pedometer> : impl_IAsyncOperation<Windows::Devices::Sensors::Pedometer> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_52076f5c_7838_54d9_9517_5511eb627952
#define WINRT_GENERIC_52076f5c_7838_54d9_9517_5511eb627952
template <> struct __declspec(uuid("52076f5c-7838-54d9-9517-5511eb627952")) __declspec(novtable) IVectorView<Windows::Devices::Sensors::PedometerReading> : impl_IVectorView<Windows::Devices::Sensors::PedometerReading> {};
#endif

#ifndef WINRT_GENERIC_64f0c54c_4865_56bd_ac98_64a98451e362
#define WINRT_GENERIC_64f0c54c_4865_56bd_ac98_64a98451e362
template <> struct __declspec(uuid("64f0c54c-4865-56bd-ac98-64a98451e362")) __declspec(novtable) IMapView<winrt::Windows::Devices::Sensors::PedometerStepKind, Windows::Devices::Sensors::PedometerReading> : impl_IMapView<winrt::Windows::Devices::Sensors::PedometerStepKind, Windows::Devices::Sensors::PedometerReading> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_dcd47693_aad5_5b3c_9c8d_140b8bc2122b
#define WINRT_GENERIC_dcd47693_aad5_5b3c_9c8d_140b8bc2122b
template <> struct __declspec(uuid("dcd47693-aad5-5b3c-9c8d-140b8bc2122b")) __declspec(novtable) TypedEventHandler<Windows::Devices::Sensors::Pedometer, Windows::Devices::Sensors::PedometerReadingChangedEventArgs> : impl_TypedEventHandler<Windows::Devices::Sensors::Pedometer, Windows::Devices::Sensors::PedometerReadingChangedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_9f7e222b_892a_5e68_b08a_10384b5f92b9
#define WINRT_GENERIC_9f7e222b_892a_5e68_b08a_10384b5f92b9
template <> struct __declspec(uuid("9f7e222b-892a-5e68-b08a-10384b5f92b9")) __declspec(novtable) TypedEventHandler<Windows::Devices::Sensors::ProximitySensor, Windows::Devices::Sensors::ProximitySensorReadingChangedEventArgs> : impl_TypedEventHandler<Windows::Devices::Sensors::ProximitySensor, Windows::Devices::Sensors::ProximitySensorReadingChangedEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_7a09d76c_8ced_5e30_b7fe_1ff74d4d9814
#define WINRT_GENERIC_7a09d76c_8ced_5e30_b7fe_1ff74d4d9814
template <> struct __declspec(uuid("7a09d76c-8ced-5e30-b7fe-1ff74d4d9814")) __declspec(novtable) IVectorView<Windows::Devices::Sensors::ProximitySensorReading> : impl_IVectorView<Windows::Devices::Sensors::ProximitySensorReading> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_d775d699_9d74_5473_9c1b_d51a89db6642
#define WINRT_GENERIC_d775d699_9d74_5473_9c1b_d51a89db6642
template <> struct __declspec(uuid("d775d699-9d74-5473-9c1b-d51a89db6642")) __declspec(novtable) TypedEventHandler<Windows::Devices::Sensors::Altimeter, Windows::Devices::Sensors::AltimeterReadingChangedEventArgs> : impl_TypedEventHandler<Windows::Devices::Sensors::Altimeter, Windows::Devices::Sensors::AltimeterReadingChangedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_fb0594f4_93d9_5c2f_b8eb_90f1e9258fdc
#define WINRT_GENERIC_fb0594f4_93d9_5c2f_b8eb_90f1e9258fdc
template <> struct __declspec(uuid("fb0594f4-93d9-5c2f-b8eb-90f1e9258fdc")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Sensors::ActivitySensor> : impl_AsyncOperationCompletedHandler<Windows::Devices::Sensors::ActivitySensor> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_d2dab535_0c94_547e_afe3_5527bcbeb9cc
#define WINRT_GENERIC_d2dab535_0c94_547e_afe3_5527bcbeb9cc
template <> struct __declspec(uuid("d2dab535-0c94-547e-afe3-5527bcbeb9cc")) __declspec(novtable) IIterator<Windows::Devices::Sensors::ActivitySensorReading> : impl_IIterator<Windows::Devices::Sensors::ActivitySensorReading> {};
#endif

#ifndef WINRT_GENERIC_9a34ce03_8c6d_5994_907f_d5c2d19148cb
#define WINRT_GENERIC_9a34ce03_8c6d_5994_907f_d5c2d19148cb
template <> struct __declspec(uuid("9a34ce03-8c6d-5994-907f-d5c2d19148cb")) __declspec(novtable) IIterable<Windows::Devices::Sensors::ActivitySensorReading> : impl_IIterable<Windows::Devices::Sensors::ActivitySensorReading> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_adc48d5d_b343_5a58_8454_6e2bc2e0475c
#define WINRT_GENERIC_adc48d5d_b343_5a58_8454_6e2bc2e0475c
template <> struct __declspec(uuid("adc48d5d-b343-5a58-8454-6e2bc2e0475c")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Sensors::ActivitySensorReading> : impl_AsyncOperationCompletedHandler<Windows::Devices::Sensors::ActivitySensorReading> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_40524281_a7c6_50b1_b6f5_0baa95d902c2
#define WINRT_GENERIC_40524281_a7c6_50b1_b6f5_0baa95d902c2
template <> struct __declspec(uuid("40524281-a7c6-50b1-b6f5-0baa95d902c2")) __declspec(novtable) IIterator<winrt::Windows::Devices::Sensors::ActivityType> : impl_IIterator<winrt::Windows::Devices::Sensors::ActivityType> {};
#endif

#ifndef WINRT_GENERIC_2a04cdfa_5dfd_5178_8731_ade998e4a7f6
#define WINRT_GENERIC_2a04cdfa_5dfd_5178_8731_ade998e4a7f6
template <> struct __declspec(uuid("2a04cdfa-5dfd-5178-8731-ade998e4a7f6")) __declspec(novtable) IIterable<winrt::Windows::Devices::Sensors::ActivityType> : impl_IIterable<winrt::Windows::Devices::Sensors::ActivityType> {};
#endif

#ifndef WINRT_GENERIC_9c07034e_8333_59d5_8d60_0e3f0438ac12
#define WINRT_GENERIC_9c07034e_8333_59d5_8d60_0e3f0438ac12
template <> struct __declspec(uuid("9c07034e-8333-59d5-8d60-0e3f0438ac12")) __declspec(novtable) IIterator<Windows::Devices::Sensors::ActivitySensorReadingChangeReport> : impl_IIterator<Windows::Devices::Sensors::ActivitySensorReadingChangeReport> {};
#endif

#ifndef WINRT_GENERIC_551a4962_9e96_5e6b_8b8a_65ee3d0046f3
#define WINRT_GENERIC_551a4962_9e96_5e6b_8b8a_65ee3d0046f3
template <> struct __declspec(uuid("551a4962-9e96-5e6b-8b8a-65ee3d0046f3")) __declspec(novtable) IIterable<Windows::Devices::Sensors::ActivitySensorReadingChangeReport> : impl_IIterable<Windows::Devices::Sensors::ActivitySensorReadingChangeReport> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_a62dbe4e_51de_5a13_ba21_e76df3bc1396
#define WINRT_GENERIC_a62dbe4e_51de_5a13_ba21_e76df3bc1396
template <> struct __declspec(uuid("a62dbe4e-51de-5a13-ba21-e76df3bc1396")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Sensors::Pedometer> : impl_AsyncOperationCompletedHandler<Windows::Devices::Sensors::Pedometer> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_0ac70ed3_8553_5ef3_92f8_438609623087
#define WINRT_GENERIC_0ac70ed3_8553_5ef3_92f8_438609623087
template <> struct __declspec(uuid("0ac70ed3-8553-5ef3-92f8-438609623087")) __declspec(novtable) IIterator<Windows::Devices::Sensors::PedometerReading> : impl_IIterator<Windows::Devices::Sensors::PedometerReading> {};
#endif

#ifndef WINRT_GENERIC_bbb61a5c_98c3_5718_88fe_5392a7451e2d
#define WINRT_GENERIC_bbb61a5c_98c3_5718_88fe_5392a7451e2d
template <> struct __declspec(uuid("bbb61a5c-98c3-5718-88fe-5392a7451e2d")) __declspec(novtable) IIterable<Windows::Devices::Sensors::PedometerReading> : impl_IIterable<Windows::Devices::Sensors::PedometerReading> {};
#endif

#ifndef WINRT_GENERIC_b270d3b8_3dd2_599f_a671_2de5035503da
#define WINRT_GENERIC_b270d3b8_3dd2_599f_a671_2de5035503da
template <> struct __declspec(uuid("b270d3b8-3dd2-599f-a671-2de5035503da")) __declspec(novtable) IKeyValuePair<winrt::Windows::Devices::Sensors::PedometerStepKind, Windows::Devices::Sensors::PedometerReading> : impl_IKeyValuePair<winrt::Windows::Devices::Sensors::PedometerStepKind, Windows::Devices::Sensors::PedometerReading> {};
#endif

#ifndef WINRT_GENERIC_1d4f08df_7f49_573b_936a_6d4d4e610930
#define WINRT_GENERIC_1d4f08df_7f49_573b_936a_6d4d4e610930
template <> struct __declspec(uuid("1d4f08df-7f49-573b-936a-6d4d4e610930")) __declspec(novtable) IIterator<Windows::Devices::Sensors::ProximitySensorReading> : impl_IIterator<Windows::Devices::Sensors::ProximitySensorReading> {};
#endif

#ifndef WINRT_GENERIC_301ebccf_11ab_5e90_98ee_bd99c0e3bb76
#define WINRT_GENERIC_301ebccf_11ab_5e90_98ee_bd99c0e3bb76
template <> struct __declspec(uuid("301ebccf-11ab-5e90-98ee-bd99c0e3bb76")) __declspec(novtable) IIterable<Windows::Devices::Sensors::ProximitySensorReading> : impl_IIterable<Windows::Devices::Sensors::ProximitySensorReading> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_cd781b82_7900_51a3_80ce_903e2e0a4f0e
#define WINRT_GENERIC_cd781b82_7900_51a3_80ce_903e2e0a4f0e
template <> struct __declspec(uuid("cd781b82-7900-51a3-80ce-903e2e0a4f0e")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::ActivitySensorReading>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::ActivitySensorReading>> {};
#endif

#ifndef WINRT_GENERIC_2aeac503_a3a8_57b3_a8a9_e16b0cd4c0a4
#define WINRT_GENERIC_2aeac503_a3a8_57b3_a8a9_e16b0cd4c0a4
template <> struct __declspec(uuid("2aeac503-a3a8-57b3-a8a9-e16b0cd4c0a4")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::PedometerReading>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::PedometerReading>> {};
#endif

#ifndef WINRT_GENERIC_179fb953_2d58_5991_8f5b_ac64219a1101
#define WINRT_GENERIC_179fb953_2d58_5991_8f5b_ac64219a1101
template <> struct __declspec(uuid("179fb953-2d58-5991-8f5b-ac64219a1101")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::ActivitySensorReading>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::ActivitySensorReading>> {};
#endif

#ifndef WINRT_GENERIC_5bbff840_59f2_5108_9205_a0bbf8f9ba68
#define WINRT_GENERIC_5bbff840_59f2_5108_9205_a0bbf8f9ba68
template <> struct __declspec(uuid("5bbff840-59f2-5108-9205-a0bbf8f9ba68")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::PedometerReading>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::PedometerReading>> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_3e88fe66_d4a7_5658_b5cf_1a39e1fc4165
#define WINRT_GENERIC_3e88fe66_d4a7_5658_b5cf_1a39e1fc4165
template <> struct __declspec(uuid("3e88fe66-d4a7-5658-b5cf-1a39e1fc4165")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<winrt::Windows::Devices::Sensors::PedometerStepKind, Windows::Devices::Sensors::PedometerReading>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<winrt::Windows::Devices::Sensors::PedometerStepKind, Windows::Devices::Sensors::PedometerReading>> {};
#endif

#ifndef WINRT_GENERIC_098f29cb_bc91_5639_a541_d5a4811ec35b
#define WINRT_GENERIC_098f29cb_bc91_5639_a541_d5a4811ec35b
template <> struct __declspec(uuid("098f29cb-bc91-5639-a541-d5a4811ec35b")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<winrt::Windows::Devices::Sensors::PedometerStepKind, Windows::Devices::Sensors::PedometerReading>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<winrt::Windows::Devices::Sensors::PedometerStepKind, Windows::Devices::Sensors::PedometerReading>> {};
#endif


}

namespace Windows::Devices::Sensors {

struct IAccelerometer :
    Windows::Foundation::IInspectable,
    impl::consume<IAccelerometer>
{
    IAccelerometer(std::nullptr_t = nullptr) noexcept {}
};

struct IAccelerometer2 :
    Windows::Foundation::IInspectable,
    impl::consume<IAccelerometer2>
{
    IAccelerometer2(std::nullptr_t = nullptr) noexcept {}
};

struct IAccelerometer3 :
    Windows::Foundation::IInspectable,
    impl::consume<IAccelerometer3>
{
    IAccelerometer3(std::nullptr_t = nullptr) noexcept {}
};

struct IAccelerometer4 :
    Windows::Foundation::IInspectable,
    impl::consume<IAccelerometer4>
{
    IAccelerometer4(std::nullptr_t = nullptr) noexcept {}
};

struct IAccelerometerDeviceId :
    Windows::Foundation::IInspectable,
    impl::consume<IAccelerometerDeviceId>
{
    IAccelerometerDeviceId(std::nullptr_t = nullptr) noexcept {}
};

struct IAccelerometerReading :
    Windows::Foundation::IInspectable,
    impl::consume<IAccelerometerReading>
{
    IAccelerometerReading(std::nullptr_t = nullptr) noexcept {}
};

struct IAccelerometerReadingChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IAccelerometerReadingChangedEventArgs>
{
    IAccelerometerReadingChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IAccelerometerShakenEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IAccelerometerShakenEventArgs>
{
    IAccelerometerShakenEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IAccelerometerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IAccelerometerStatics>
{
    IAccelerometerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IAccelerometerStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IAccelerometerStatics2>
{
    IAccelerometerStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IActivitySensor :
    Windows::Foundation::IInspectable,
    impl::consume<IActivitySensor>
{
    IActivitySensor(std::nullptr_t = nullptr) noexcept {}
};

struct IActivitySensorReading :
    Windows::Foundation::IInspectable,
    impl::consume<IActivitySensorReading>
{
    IActivitySensorReading(std::nullptr_t = nullptr) noexcept {}
};

struct IActivitySensorReadingChangeReport :
    Windows::Foundation::IInspectable,
    impl::consume<IActivitySensorReadingChangeReport>
{
    IActivitySensorReadingChangeReport(std::nullptr_t = nullptr) noexcept {}
};

struct IActivitySensorReadingChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IActivitySensorReadingChangedEventArgs>
{
    IActivitySensorReadingChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IActivitySensorStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IActivitySensorStatics>
{
    IActivitySensorStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IActivitySensorTriggerDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IActivitySensorTriggerDetails>
{
    IActivitySensorTriggerDetails(std::nullptr_t = nullptr) noexcept {}
};

struct IAltimeter :
    Windows::Foundation::IInspectable,
    impl::consume<IAltimeter>
{
    IAltimeter(std::nullptr_t = nullptr) noexcept {}
};

struct IAltimeterReading :
    Windows::Foundation::IInspectable,
    impl::consume<IAltimeterReading>
{
    IAltimeterReading(std::nullptr_t = nullptr) noexcept {}
};

struct IAltimeterReadingChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IAltimeterReadingChangedEventArgs>
{
    IAltimeterReadingChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IAltimeterStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IAltimeterStatics>
{
    IAltimeterStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IBarometer :
    Windows::Foundation::IInspectable,
    impl::consume<IBarometer>
{
    IBarometer(std::nullptr_t = nullptr) noexcept {}
};

struct IBarometerReading :
    Windows::Foundation::IInspectable,
    impl::consume<IBarometerReading>
{
    IBarometerReading(std::nullptr_t = nullptr) noexcept {}
};

struct IBarometerReadingChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IBarometerReadingChangedEventArgs>
{
    IBarometerReadingChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IBarometerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IBarometerStatics>
{
    IBarometerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ICompass :
    Windows::Foundation::IInspectable,
    impl::consume<ICompass>
{
    ICompass(std::nullptr_t = nullptr) noexcept {}
};

struct ICompass2 :
    Windows::Foundation::IInspectable,
    impl::consume<ICompass2>
{
    ICompass2(std::nullptr_t = nullptr) noexcept {}
};

struct ICompassDeviceId :
    Windows::Foundation::IInspectable,
    impl::consume<ICompassDeviceId>
{
    ICompassDeviceId(std::nullptr_t = nullptr) noexcept {}
};

struct ICompassReading :
    Windows::Foundation::IInspectable,
    impl::consume<ICompassReading>
{
    ICompassReading(std::nullptr_t = nullptr) noexcept {}
};

struct ICompassReadingChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ICompassReadingChangedEventArgs>
{
    ICompassReadingChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ICompassReadingHeadingAccuracy :
    Windows::Foundation::IInspectable,
    impl::consume<ICompassReadingHeadingAccuracy>
{
    ICompassReadingHeadingAccuracy(std::nullptr_t = nullptr) noexcept {}
};

struct ICompassStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ICompassStatics>
{
    ICompassStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IGyrometer :
    Windows::Foundation::IInspectable,
    impl::consume<IGyrometer>
{
    IGyrometer(std::nullptr_t = nullptr) noexcept {}
};

struct IGyrometer2 :
    Windows::Foundation::IInspectable,
    impl::consume<IGyrometer2>
{
    IGyrometer2(std::nullptr_t = nullptr) noexcept {}
};

struct IGyrometerDeviceId :
    Windows::Foundation::IInspectable,
    impl::consume<IGyrometerDeviceId>
{
    IGyrometerDeviceId(std::nullptr_t = nullptr) noexcept {}
};

struct IGyrometerReading :
    Windows::Foundation::IInspectable,
    impl::consume<IGyrometerReading>
{
    IGyrometerReading(std::nullptr_t = nullptr) noexcept {}
};

struct IGyrometerReadingChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IGyrometerReadingChangedEventArgs>
{
    IGyrometerReadingChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IGyrometerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IGyrometerStatics>
{
    IGyrometerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IInclinometer :
    Windows::Foundation::IInspectable,
    impl::consume<IInclinometer>
{
    IInclinometer(std::nullptr_t = nullptr) noexcept {}
};

struct IInclinometer2 :
    Windows::Foundation::IInspectable,
    impl::consume<IInclinometer2>
{
    IInclinometer2(std::nullptr_t = nullptr) noexcept {}
};

struct IInclinometerDeviceId :
    Windows::Foundation::IInspectable,
    impl::consume<IInclinometerDeviceId>
{
    IInclinometerDeviceId(std::nullptr_t = nullptr) noexcept {}
};

struct IInclinometerReading :
    Windows::Foundation::IInspectable,
    impl::consume<IInclinometerReading>
{
    IInclinometerReading(std::nullptr_t = nullptr) noexcept {}
};

struct IInclinometerReadingChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IInclinometerReadingChangedEventArgs>
{
    IInclinometerReadingChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IInclinometerReadingYawAccuracy :
    Windows::Foundation::IInspectable,
    impl::consume<IInclinometerReadingYawAccuracy>
{
    IInclinometerReadingYawAccuracy(std::nullptr_t = nullptr) noexcept {}
};

struct IInclinometerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IInclinometerStatics>
{
    IInclinometerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IInclinometerStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IInclinometerStatics2>
{
    IInclinometerStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IInclinometerStatics3 :
    Windows::Foundation::IInspectable,
    impl::consume<IInclinometerStatics3>
{
    IInclinometerStatics3(std::nullptr_t = nullptr) noexcept {}
};

struct ILightSensor :
    Windows::Foundation::IInspectable,
    impl::consume<ILightSensor>
{
    ILightSensor(std::nullptr_t = nullptr) noexcept {}
};

struct ILightSensorDeviceId :
    Windows::Foundation::IInspectable,
    impl::consume<ILightSensorDeviceId>
{
    ILightSensorDeviceId(std::nullptr_t = nullptr) noexcept {}
};

struct ILightSensorReading :
    Windows::Foundation::IInspectable,
    impl::consume<ILightSensorReading>
{
    ILightSensorReading(std::nullptr_t = nullptr) noexcept {}
};

struct ILightSensorReadingChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ILightSensorReadingChangedEventArgs>
{
    ILightSensorReadingChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ILightSensorStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ILightSensorStatics>
{
    ILightSensorStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IMagnetometer :
    Windows::Foundation::IInspectable,
    impl::consume<IMagnetometer>
{
    IMagnetometer(std::nullptr_t = nullptr) noexcept {}
};

struct IMagnetometer2 :
    Windows::Foundation::IInspectable,
    impl::consume<IMagnetometer2>
{
    IMagnetometer2(std::nullptr_t = nullptr) noexcept {}
};

struct IMagnetometerDeviceId :
    Windows::Foundation::IInspectable,
    impl::consume<IMagnetometerDeviceId>
{
    IMagnetometerDeviceId(std::nullptr_t = nullptr) noexcept {}
};

struct IMagnetometerReading :
    Windows::Foundation::IInspectable,
    impl::consume<IMagnetometerReading>
{
    IMagnetometerReading(std::nullptr_t = nullptr) noexcept {}
};

struct IMagnetometerReadingChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IMagnetometerReadingChangedEventArgs>
{
    IMagnetometerReadingChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IMagnetometerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IMagnetometerStatics>
{
    IMagnetometerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IOrientationSensor :
    Windows::Foundation::IInspectable,
    impl::consume<IOrientationSensor>
{
    IOrientationSensor(std::nullptr_t = nullptr) noexcept {}
};

struct IOrientationSensor2 :
    Windows::Foundation::IInspectable,
    impl::consume<IOrientationSensor2>
{
    IOrientationSensor2(std::nullptr_t = nullptr) noexcept {}
};

struct IOrientationSensorDeviceId :
    Windows::Foundation::IInspectable,
    impl::consume<IOrientationSensorDeviceId>
{
    IOrientationSensorDeviceId(std::nullptr_t = nullptr) noexcept {}
};

struct IOrientationSensorReading :
    Windows::Foundation::IInspectable,
    impl::consume<IOrientationSensorReading>
{
    IOrientationSensorReading(std::nullptr_t = nullptr) noexcept {}
};

struct IOrientationSensorReadingChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IOrientationSensorReadingChangedEventArgs>
{
    IOrientationSensorReadingChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IOrientationSensorReadingYawAccuracy :
    Windows::Foundation::IInspectable,
    impl::consume<IOrientationSensorReadingYawAccuracy>
{
    IOrientationSensorReadingYawAccuracy(std::nullptr_t = nullptr) noexcept {}
};

struct IOrientationSensorStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IOrientationSensorStatics>
{
    IOrientationSensorStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IOrientationSensorStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IOrientationSensorStatics2>
{
    IOrientationSensorStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IOrientationSensorStatics3 :
    Windows::Foundation::IInspectable,
    impl::consume<IOrientationSensorStatics3>
{
    IOrientationSensorStatics3(std::nullptr_t = nullptr) noexcept {}
};

struct IPedometer :
    Windows::Foundation::IInspectable,
    impl::consume<IPedometer>
{
    IPedometer(std::nullptr_t = nullptr) noexcept {}
};

struct IPedometer2 :
    Windows::Foundation::IInspectable,
    impl::consume<IPedometer2>
{
    IPedometer2(std::nullptr_t = nullptr) noexcept {}
};

struct IPedometerDataThresholdFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IPedometerDataThresholdFactory>
{
    IPedometerDataThresholdFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IPedometerReading :
    Windows::Foundation::IInspectable,
    impl::consume<IPedometerReading>
{
    IPedometerReading(std::nullptr_t = nullptr) noexcept {}
};

struct IPedometerReadingChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPedometerReadingChangedEventArgs>
{
    IPedometerReadingChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPedometerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IPedometerStatics>
{
    IPedometerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IPedometerStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IPedometerStatics2>
{
    IPedometerStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IProximitySensor :
    Windows::Foundation::IInspectable,
    impl::consume<IProximitySensor>
{
    IProximitySensor(std::nullptr_t = nullptr) noexcept {}
};

struct IProximitySensorDataThresholdFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IProximitySensorDataThresholdFactory>
{
    IProximitySensorDataThresholdFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IProximitySensorReading :
    Windows::Foundation::IInspectable,
    impl::consume<IProximitySensorReading>
{
    IProximitySensorReading(std::nullptr_t = nullptr) noexcept {}
};

struct IProximitySensorReadingChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IProximitySensorReadingChangedEventArgs>
{
    IProximitySensorReadingChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IProximitySensorStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IProximitySensorStatics>
{
    IProximitySensorStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IProximitySensorStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IProximitySensorStatics2>
{
    IProximitySensorStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct ISensorDataThreshold :
    Windows::Foundation::IInspectable,
    impl::consume<ISensorDataThreshold>
{
    ISensorDataThreshold(std::nullptr_t = nullptr) noexcept {}
};

struct ISensorDataThresholdTriggerDetails :
    Windows::Foundation::IInspectable,
    impl::consume<ISensorDataThresholdTriggerDetails>
{
    ISensorDataThresholdTriggerDetails(std::nullptr_t = nullptr) noexcept {}
};

struct ISensorQuaternion :
    Windows::Foundation::IInspectable,
    impl::consume<ISensorQuaternion>
{
    ISensorQuaternion(std::nullptr_t = nullptr) noexcept {}
};

struct ISensorRotationMatrix :
    Windows::Foundation::IInspectable,
    impl::consume<ISensorRotationMatrix>
{
    ISensorRotationMatrix(std::nullptr_t = nullptr) noexcept {}
};

struct ISimpleOrientationSensor :
    Windows::Foundation::IInspectable,
    impl::consume<ISimpleOrientationSensor>
{
    ISimpleOrientationSensor(std::nullptr_t = nullptr) noexcept {}
};

struct ISimpleOrientationSensor2 :
    Windows::Foundation::IInspectable,
    impl::consume<ISimpleOrientationSensor2>
{
    ISimpleOrientationSensor2(std::nullptr_t = nullptr) noexcept {}
};

struct ISimpleOrientationSensorDeviceId :
    Windows::Foundation::IInspectable,
    impl::consume<ISimpleOrientationSensorDeviceId>
{
    ISimpleOrientationSensorDeviceId(std::nullptr_t = nullptr) noexcept {}
};

struct ISimpleOrientationSensorOrientationChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ISimpleOrientationSensorOrientationChangedEventArgs>
{
    ISimpleOrientationSensorOrientationChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ISimpleOrientationSensorStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISimpleOrientationSensorStatics>
{
    ISimpleOrientationSensorStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
