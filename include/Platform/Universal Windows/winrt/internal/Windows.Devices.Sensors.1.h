// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Devices.Sensors.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Graphics.Display.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Sensors {

struct __declspec(uuid("df184548-2711-4da7-8098-4b82205d3c7d")) __declspec(novtable) IAccelerometer : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetCurrentReading(Windows::Devices::Sensors::IAccelerometerReading ** value) = 0;
    virtual HRESULT __stdcall get_MinimumReportInterval(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_ReportInterval(uint32_t value) = 0;
    virtual HRESULT __stdcall get_ReportInterval(uint32_t * value) = 0;
    virtual HRESULT __stdcall add_ReadingChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Accelerometer, Windows::Devices::Sensors::AccelerometerReadingChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ReadingChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_Shaken(Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Accelerometer, Windows::Devices::Sensors::AccelerometerShakenEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Shaken(event_token token) = 0;
};

struct __declspec(uuid("e8f092ee-4964-401a-b602-220d7153c60a")) __declspec(novtable) IAccelerometer2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_ReadingTransform(winrt::Windows::Graphics::Display::DisplayOrientations value) = 0;
    virtual HRESULT __stdcall get_ReadingTransform(winrt::Windows::Graphics::Display::DisplayOrientations * value) = 0;
};

struct __declspec(uuid("87e0022a-ed80-49eb-bf8a-a4ea31e5cd84")) __declspec(novtable) IAccelerometer3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_ReportLatency(uint32_t value) = 0;
    virtual HRESULT __stdcall get_ReportLatency(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_MaxBatchSize(uint32_t * value) = 0;
};

struct __declspec(uuid("1d373c4f-42d3-45b2-8144-ab7fb665eb59")) __declspec(novtable) IAccelerometer4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ReadingType(winrt::Windows::Devices::Sensors::AccelerometerReadingType * type) = 0;
};

struct __declspec(uuid("7eac64a9-97d5-446d-ab5a-917df9b96a2c")) __declspec(novtable) IAccelerometerDeviceId : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
};

struct __declspec(uuid("b9fe7acb-d351-40af-8bb6-7aa9ae641fb7")) __declspec(novtable) IAccelerometerReading : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_AccelerationX(double * value) = 0;
    virtual HRESULT __stdcall get_AccelerationY(double * value) = 0;
    virtual HRESULT __stdcall get_AccelerationZ(double * value) = 0;
};

struct __declspec(uuid("0095c65b-b6ac-475a-9f44-8b32d35a3f25")) __declspec(novtable) IAccelerometerReadingChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Reading(Windows::Devices::Sensors::IAccelerometerReading ** value) = 0;
};

struct __declspec(uuid("95ff01d1-4a28-4f35-98e8-8178aae4084a")) __declspec(novtable) IAccelerometerShakenEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
};

struct __declspec(uuid("a5e28b74-5a87-4a2d-becc-0f906ea061dd")) __declspec(novtable) IAccelerometerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDefault(Windows::Devices::Sensors::IAccelerometer ** result) = 0;
};

struct __declspec(uuid("c4c4842f-d86b-4685-b2d7-3396f798d57b")) __declspec(novtable) IAccelerometerStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDefaultWithAccelerometerReadingType(winrt::Windows::Devices::Sensors::AccelerometerReadingType readingType, Windows::Devices::Sensors::IAccelerometer ** result) = 0;
};

struct __declspec(uuid("cd7a630c-fb5f-48eb-b09b-a2708d1c61ef")) __declspec(novtable) IActivitySensor : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetCurrentReadingAsync(Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::ActivitySensorReading> ** result) = 0;
    virtual HRESULT __stdcall get_SubscribedActivities(Windows::Foundation::Collections::IVector<winrt::Windows::Devices::Sensors::ActivityType> ** value) = 0;
    virtual HRESULT __stdcall get_PowerInMilliwatts(double * value) = 0;
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_SupportedActivities(Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::Sensors::ActivityType> ** value) = 0;
    virtual HRESULT __stdcall get_MinimumReportInterval(uint32_t * value) = 0;
    virtual HRESULT __stdcall add_ReadingChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::ActivitySensor, Windows::Devices::Sensors::ActivitySensorReadingChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ReadingChanged(event_token token) = 0;
};

struct __declspec(uuid("85125a96-1472-40a2-b2ae-e1ef29226c78")) __declspec(novtable) IActivitySensorReading : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_Activity(winrt::Windows::Devices::Sensors::ActivityType * value) = 0;
    virtual HRESULT __stdcall get_Confidence(winrt::Windows::Devices::Sensors::ActivitySensorReadingConfidence * value) = 0;
};

struct __declspec(uuid("4f3c2915-d93b-47bd-960a-f20fb2f322b9")) __declspec(novtable) IActivitySensorReadingChangeReport : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Reading(Windows::Devices::Sensors::IActivitySensorReading ** value) = 0;
};

struct __declspec(uuid("de386717-aeb6-4ec7-946a-d9cc19b951ec")) __declspec(novtable) IActivitySensorReadingChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Reading(Windows::Devices::Sensors::IActivitySensorReading ** value) = 0;
};

struct __declspec(uuid("a71e0e9d-ee8b-45d1-b25b-08cc0df92ab6")) __declspec(novtable) IActivitySensorStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDefaultAsync(Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::ActivitySensor> ** result) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelector(hstring * value) = 0;
    virtual HRESULT __stdcall abi_FromIdAsync(hstring deviceId, Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::ActivitySensor> ** result) = 0;
    virtual HRESULT __stdcall abi_GetSystemHistoryAsync(Windows::Foundation::DateTime fromTime, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::ActivitySensorReading>> ** result) = 0;
    virtual HRESULT __stdcall abi_GetSystemHistoryWithDurationAsync(Windows::Foundation::DateTime fromTime, Windows::Foundation::TimeSpan duration, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::ActivitySensorReading>> ** result) = 0;
};

struct __declspec(uuid("2c9e6612-b9ca-4677-b263-243297f79d3a")) __declspec(novtable) IActivitySensorTriggerDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ReadReports(Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::ActivitySensorReadingChangeReport> ** value) = 0;
};

struct __declspec(uuid("72f057fd-8f04-49f1-b4a7-f4e363b701a2")) __declspec(novtable) IAltimeter : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetCurrentReading(Windows::Devices::Sensors::IAltimeterReading ** value) = 0;
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_MinimumReportInterval(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_ReportInterval(uint32_t value) = 0;
    virtual HRESULT __stdcall get_ReportInterval(uint32_t * value) = 0;
    virtual HRESULT __stdcall add_ReadingChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Altimeter, Windows::Devices::Sensors::AltimeterReadingChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ReadingChanged(event_token token) = 0;
};

struct __declspec(uuid("fbe8ef73-7f5e-48c8-aa1a-f1f3befc1144")) __declspec(novtable) IAltimeterReading : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_AltitudeChangeInMeters(double * value) = 0;
};

struct __declspec(uuid("7069d077-446d-47f7-998c-ebc23b45e4a2")) __declspec(novtable) IAltimeterReadingChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Reading(Windows::Devices::Sensors::IAltimeterReading ** value) = 0;
};

struct __declspec(uuid("9eb4d7c3-e5ac-47ce-8eef-d3718168c01f")) __declspec(novtable) IAltimeterStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDefault(Windows::Devices::Sensors::IAltimeter ** result) = 0;
};

struct __declspec(uuid("934475a8-78bf-452f-b017-f0209ce6dab4")) __declspec(novtable) IBarometer : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetCurrentReading(Windows::Devices::Sensors::IBarometerReading ** value) = 0;
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_MinimumReportInterval(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_ReportInterval(uint32_t value) = 0;
    virtual HRESULT __stdcall get_ReportInterval(uint32_t * value) = 0;
    virtual HRESULT __stdcall add_ReadingChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Barometer, Windows::Devices::Sensors::BarometerReadingChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ReadingChanged(event_token token) = 0;
};

struct __declspec(uuid("f5b9d2e6-1df6-4a1a-a7ad-321d4f5db247")) __declspec(novtable) IBarometerReading : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_StationPressureInHectopascals(double * value) = 0;
};

struct __declspec(uuid("3d84945f-037b-404f-9bbb-6232d69543c3")) __declspec(novtable) IBarometerReadingChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Reading(Windows::Devices::Sensors::IBarometerReading ** value) = 0;
};

struct __declspec(uuid("286b270a-02e3-4f86-84fc-fdd892b5940f")) __declspec(novtable) IBarometerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDefault(Windows::Devices::Sensors::IBarometer ** result) = 0;
};

struct __declspec(uuid("292ffa94-1b45-403c-ba06-b106dba69a64")) __declspec(novtable) ICompass : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetCurrentReading(Windows::Devices::Sensors::ICompassReading ** value) = 0;
    virtual HRESULT __stdcall get_MinimumReportInterval(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_ReportInterval(uint32_t value) = 0;
    virtual HRESULT __stdcall get_ReportInterval(uint32_t * value) = 0;
    virtual HRESULT __stdcall add_ReadingChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Compass, Windows::Devices::Sensors::CompassReadingChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ReadingChanged(event_token token) = 0;
};

struct __declspec(uuid("36f26d09-c7d7-434f-b461-979ddfc2322f")) __declspec(novtable) ICompass2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_ReadingTransform(winrt::Windows::Graphics::Display::DisplayOrientations value) = 0;
    virtual HRESULT __stdcall get_ReadingTransform(winrt::Windows::Graphics::Display::DisplayOrientations * value) = 0;
};

struct __declspec(uuid("d181ca29-b085-4b1d-870a-4ff57ba74fd4")) __declspec(novtable) ICompassDeviceId : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
};

struct __declspec(uuid("82911128-513d-4dc9-b781-5eedfbf02d0c")) __declspec(novtable) ICompassReading : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_HeadingMagneticNorth(double * value) = 0;
    virtual HRESULT __stdcall get_HeadingTrueNorth(Windows::Foundation::IReference<double> ** value) = 0;
};

struct __declspec(uuid("8f1549b0-e8bc-4c7e-b009-4e41df137072")) __declspec(novtable) ICompassReadingChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Reading(Windows::Devices::Sensors::ICompassReading ** value) = 0;
};

struct __declspec(uuid("e761354e-8911-40f7-9e16-6ecc7daec5de")) __declspec(novtable) ICompassReadingHeadingAccuracy : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HeadingAccuracy(winrt::Windows::Devices::Sensors::MagnetometerAccuracy * value) = 0;
};

struct __declspec(uuid("9abc97df-56ec-4c25-b54d-40a68bb5b269")) __declspec(novtable) ICompassStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDefault(Windows::Devices::Sensors::ICompass ** result) = 0;
};

struct __declspec(uuid("fdb9a9c4-84b1-4ca2-9763-9b589506c70c")) __declspec(novtable) IGyrometer : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetCurrentReading(Windows::Devices::Sensors::IGyrometerReading ** value) = 0;
    virtual HRESULT __stdcall get_MinimumReportInterval(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_ReportInterval(uint32_t value) = 0;
    virtual HRESULT __stdcall get_ReportInterval(uint32_t * value) = 0;
    virtual HRESULT __stdcall add_ReadingChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Gyrometer, Windows::Devices::Sensors::GyrometerReadingChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ReadingChanged(event_token token) = 0;
};

struct __declspec(uuid("63df2443-8ce8-41c3-ac44-8698810b557f")) __declspec(novtable) IGyrometer2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_ReadingTransform(winrt::Windows::Graphics::Display::DisplayOrientations value) = 0;
    virtual HRESULT __stdcall get_ReadingTransform(winrt::Windows::Graphics::Display::DisplayOrientations * value) = 0;
};

struct __declspec(uuid("1ee5e978-89a2-4275-9e95-7126f4708760")) __declspec(novtable) IGyrometerDeviceId : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
};

struct __declspec(uuid("b3d6de5c-1ee4-456f-9de7-e2493b5c8e03")) __declspec(novtable) IGyrometerReading : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_AngularVelocityX(double * value) = 0;
    virtual HRESULT __stdcall get_AngularVelocityY(double * value) = 0;
    virtual HRESULT __stdcall get_AngularVelocityZ(double * value) = 0;
};

struct __declspec(uuid("0fdf1895-6f9e-42ce-8d58-388c0ab8356d")) __declspec(novtable) IGyrometerReadingChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Reading(Windows::Devices::Sensors::IGyrometerReading ** value) = 0;
};

struct __declspec(uuid("83b6e7c9-e49d-4b39-86e6-cd554be4c5c1")) __declspec(novtable) IGyrometerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDefault(Windows::Devices::Sensors::IGyrometer ** result) = 0;
};

struct __declspec(uuid("2648ca6f-2286-406f-9161-f0c4bd806ebf")) __declspec(novtable) IInclinometer : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetCurrentReading(Windows::Devices::Sensors::IInclinometerReading ** value) = 0;
    virtual HRESULT __stdcall get_MinimumReportInterval(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_ReportInterval(uint32_t value) = 0;
    virtual HRESULT __stdcall get_ReportInterval(uint32_t * value) = 0;
    virtual HRESULT __stdcall add_ReadingChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Inclinometer, Windows::Devices::Sensors::InclinometerReadingChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ReadingChanged(event_token token) = 0;
};

struct __declspec(uuid("029f3393-28b2-45f8-bb16-61e86a7fae6e")) __declspec(novtable) IInclinometer2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_ReadingTransform(winrt::Windows::Graphics::Display::DisplayOrientations value) = 0;
    virtual HRESULT __stdcall get_ReadingTransform(winrt::Windows::Graphics::Display::DisplayOrientations * value) = 0;
    virtual HRESULT __stdcall get_ReadingType(winrt::Windows::Devices::Sensors::SensorReadingType * type) = 0;
};

struct __declspec(uuid("01e91982-41ff-4406-ae83-62210ff16fe3")) __declspec(novtable) IInclinometerDeviceId : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
};

struct __declspec(uuid("9f44f055-b6f6-497f-b127-1a775e501458")) __declspec(novtable) IInclinometerReading : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_PitchDegrees(float * value) = 0;
    virtual HRESULT __stdcall get_RollDegrees(float * value) = 0;
    virtual HRESULT __stdcall get_YawDegrees(float * value) = 0;
};

struct __declspec(uuid("4ae91dc1-e7eb-4938-8511-ae0d6b440438")) __declspec(novtable) IInclinometerReadingChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Reading(Windows::Devices::Sensors::IInclinometerReading ** value) = 0;
};

struct __declspec(uuid("b453e880-1fe3-4986-a257-e6ece2723949")) __declspec(novtable) IInclinometerReadingYawAccuracy : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_YawAccuracy(winrt::Windows::Devices::Sensors::MagnetometerAccuracy * value) = 0;
};

struct __declspec(uuid("f22ec551-9c30-453a-8b49-3c3eeb33cb61")) __declspec(novtable) IInclinometerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDefault(Windows::Devices::Sensors::IInclinometer ** result) = 0;
};

struct __declspec(uuid("043f9775-6a1e-499c-86e0-638c1a864b00")) __declspec(novtable) IInclinometerStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDefaultForRelativeReadings(Windows::Devices::Sensors::IInclinometer ** result) = 0;
};

struct __declspec(uuid("bd9a4280-b91a-4829-9392-abc0b6bdf2b4")) __declspec(novtable) IInclinometerStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDefaultWithSensorReadingType(winrt::Windows::Devices::Sensors::SensorReadingType sensorReadingtype, Windows::Devices::Sensors::IInclinometer ** result) = 0;
};

struct __declspec(uuid("f84c0718-0c54-47ae-922e-789f57fb03a0")) __declspec(novtable) ILightSensor : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetCurrentReading(Windows::Devices::Sensors::ILightSensorReading ** value) = 0;
    virtual HRESULT __stdcall get_MinimumReportInterval(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_ReportInterval(uint32_t value) = 0;
    virtual HRESULT __stdcall get_ReportInterval(uint32_t * value) = 0;
    virtual HRESULT __stdcall add_ReadingChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::LightSensor, Windows::Devices::Sensors::LightSensorReadingChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ReadingChanged(event_token token) = 0;
};

struct __declspec(uuid("7fee49f8-0afb-4f51-87f0-6c26375ce94f")) __declspec(novtable) ILightSensorDeviceId : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
};

struct __declspec(uuid("ffdf6300-227c-4d2b-b302-fc0142485c68")) __declspec(novtable) ILightSensorReading : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_IlluminanceInLux(float * value) = 0;
};

struct __declspec(uuid("a3a2f4cf-258b-420c-b8ab-8edd601ecf50")) __declspec(novtable) ILightSensorReadingChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Reading(Windows::Devices::Sensors::ILightSensorReading ** value) = 0;
};

struct __declspec(uuid("45db8c84-c3a8-471e-9a53-6457fad87c0e")) __declspec(novtable) ILightSensorStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDefault(Windows::Devices::Sensors::ILightSensor ** result) = 0;
};

struct __declspec(uuid("484f626e-d3c9-4111-b3f6-2cf1faa418d5")) __declspec(novtable) IMagnetometer : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetCurrentReading(Windows::Devices::Sensors::IMagnetometerReading ** value) = 0;
    virtual HRESULT __stdcall get_MinimumReportInterval(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_ReportInterval(uint32_t value) = 0;
    virtual HRESULT __stdcall get_ReportInterval(uint32_t * value) = 0;
    virtual HRESULT __stdcall add_ReadingChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Magnetometer, Windows::Devices::Sensors::MagnetometerReadingChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ReadingChanged(event_token token) = 0;
};

struct __declspec(uuid("b4656c85-26f6-444b-a9e2-a23f966cd368")) __declspec(novtable) IMagnetometer2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_ReadingTransform(winrt::Windows::Graphics::Display::DisplayOrientations value) = 0;
    virtual HRESULT __stdcall get_ReadingTransform(winrt::Windows::Graphics::Display::DisplayOrientations * value) = 0;
};

struct __declspec(uuid("58b498c2-7e4b-404c-9fc5-5de8b40ebae3")) __declspec(novtable) IMagnetometerDeviceId : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
};

struct __declspec(uuid("0c2cc40d-ebfd-4e5c-bb11-afc29b3cae61")) __declspec(novtable) IMagnetometerReading : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_MagneticFieldX(float * value) = 0;
    virtual HRESULT __stdcall get_MagneticFieldY(float * value) = 0;
    virtual HRESULT __stdcall get_MagneticFieldZ(float * value) = 0;
    virtual HRESULT __stdcall get_DirectionalAccuracy(winrt::Windows::Devices::Sensors::MagnetometerAccuracy * value) = 0;
};

struct __declspec(uuid("17eae872-2eb9-4ee7-8ad0-3127537d949b")) __declspec(novtable) IMagnetometerReadingChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Reading(Windows::Devices::Sensors::IMagnetometerReading ** value) = 0;
};

struct __declspec(uuid("853c64cc-0698-4dda-a6df-9cb9cc4ab40a")) __declspec(novtable) IMagnetometerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDefault(Windows::Devices::Sensors::IMagnetometer ** result) = 0;
};

struct __declspec(uuid("5e354635-cf6b-4c63-abd8-10252b0bf6ec")) __declspec(novtable) IOrientationSensor : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetCurrentReading(Windows::Devices::Sensors::IOrientationSensorReading ** value) = 0;
    virtual HRESULT __stdcall get_MinimumReportInterval(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_ReportInterval(uint32_t value) = 0;
    virtual HRESULT __stdcall get_ReportInterval(uint32_t * value) = 0;
    virtual HRESULT __stdcall add_ReadingChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::OrientationSensor, Windows::Devices::Sensors::OrientationSensorReadingChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ReadingChanged(event_token token) = 0;
};

struct __declspec(uuid("0d924cf9-2f1f-49c9-8042-4a1813d67760")) __declspec(novtable) IOrientationSensor2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_ReadingTransform(winrt::Windows::Graphics::Display::DisplayOrientations value) = 0;
    virtual HRESULT __stdcall get_ReadingTransform(winrt::Windows::Graphics::Display::DisplayOrientations * value) = 0;
    virtual HRESULT __stdcall get_ReadingType(winrt::Windows::Devices::Sensors::SensorReadingType * type) = 0;
};

struct __declspec(uuid("5a69b648-4c29-49ec-b28f-ea1d117b66f0")) __declspec(novtable) IOrientationSensorDeviceId : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
};

struct __declspec(uuid("4756c993-6595-4897-bcc6-d537ee757564")) __declspec(novtable) IOrientationSensorReading : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_RotationMatrix(Windows::Devices::Sensors::ISensorRotationMatrix ** value) = 0;
    virtual HRESULT __stdcall get_Quaternion(Windows::Devices::Sensors::ISensorQuaternion ** value) = 0;
};

struct __declspec(uuid("012c1186-c3ba-46bc-ae65-7a98996cbfb8")) __declspec(novtable) IOrientationSensorReadingChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Reading(Windows::Devices::Sensors::IOrientationSensorReading ** value) = 0;
};

struct __declspec(uuid("d1ac9824-3f5a-49a2-bc7b-1180bc38cd2b")) __declspec(novtable) IOrientationSensorReadingYawAccuracy : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_YawAccuracy(winrt::Windows::Devices::Sensors::MagnetometerAccuracy * value) = 0;
};

struct __declspec(uuid("10ef8712-fb4c-428a-898b-2765e409e669")) __declspec(novtable) IOrientationSensorStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDefault(Windows::Devices::Sensors::IOrientationSensor ** result) = 0;
};

struct __declspec(uuid("59da0d0b-d40a-4c71-9276-8a272a0a6619")) __declspec(novtable) IOrientationSensorStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDefaultForRelativeReadings(Windows::Devices::Sensors::IOrientationSensor ** result) = 0;
};

struct __declspec(uuid("d82ce920-2777-40ff-9f59-d654b085f12f")) __declspec(novtable) IOrientationSensorStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDefaultWithSensorReadingType(winrt::Windows::Devices::Sensors::SensorReadingType sensorReadingtype, Windows::Devices::Sensors::IOrientationSensor ** result) = 0;
    virtual HRESULT __stdcall abi_GetDefaultWithSensorReadingTypeAndSensorOptimizationGoal(winrt::Windows::Devices::Sensors::SensorReadingType sensorReadingType, winrt::Windows::Devices::Sensors::SensorOptimizationGoal optimizationGoal, Windows::Devices::Sensors::IOrientationSensor ** result) = 0;
};

struct __declspec(uuid("9a1e013d-3d98-45f8-8920-8e4ecaca5f97")) __declspec(novtable) IPedometer : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_PowerInMilliwatts(double * value) = 0;
    virtual HRESULT __stdcall get_MinimumReportInterval(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_ReportInterval(uint32_t value) = 0;
    virtual HRESULT __stdcall get_ReportInterval(uint32_t * value) = 0;
    virtual HRESULT __stdcall add_ReadingChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Pedometer, Windows::Devices::Sensors::PedometerReadingChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ReadingChanged(event_token token) = 0;
};

struct __declspec(uuid("e5a406df-2b81-4add-b2ff-77ab6c98ba19")) __declspec(novtable) IPedometer2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetCurrentReadings(Windows::Foundation::Collections::IMapView<winrt::Windows::Devices::Sensors::PedometerStepKind, Windows::Devices::Sensors::PedometerReading> ** value) = 0;
};

struct __declspec(uuid("cbad8f50-7a54-466b-9010-77a162fca5d7")) __declspec(novtable) IPedometerDataThresholdFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Devices::Sensors::IPedometer * sensor, int32_t stepGoal, Windows::Devices::Sensors::ISensorDataThreshold ** threshold) = 0;
};

struct __declspec(uuid("2245dcf4-a8e1-432f-896a-be0dd9b02d24")) __declspec(novtable) IPedometerReading : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_StepKind(winrt::Windows::Devices::Sensors::PedometerStepKind * value) = 0;
    virtual HRESULT __stdcall get_CumulativeSteps(int32_t * value) = 0;
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_CumulativeStepsDuration(Windows::Foundation::TimeSpan * value) = 0;
};

struct __declspec(uuid("f855e47e-abbc-4456-86a8-25cf2b333742")) __declspec(novtable) IPedometerReadingChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Reading(Windows::Devices::Sensors::IPedometerReading ** value) = 0;
};

struct __declspec(uuid("82980a2f-4083-4dfb-b411-938ea0f4b946")) __declspec(novtable) IPedometerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FromIdAsync(hstring deviceId, Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::Pedometer> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetDefaultAsync(Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::Pedometer> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelector(hstring * result) = 0;
    virtual HRESULT __stdcall abi_GetSystemHistoryAsync(Windows::Foundation::DateTime fromTime, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::PedometerReading>> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetSystemHistoryWithDurationAsync(Windows::Foundation::DateTime fromTime, Windows::Foundation::TimeSpan duration, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::PedometerReading>> ** operation) = 0;
};

struct __declspec(uuid("79f5c6bb-ce0e-4133-b47e-8627ea72f677")) __declspec(novtable) IPedometerStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetReadingsFromTriggerDetails(Windows::Devices::Sensors::ISensorDataThresholdTriggerDetails * triggerDetails, Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::PedometerReading> ** result) = 0;
};

struct __declspec(uuid("54c076b8-ecfb-4944-b928-74fc504d47ee")) __declspec(novtable) IProximitySensor : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_MaxDistanceInMillimeters(Windows::Foundation::IReference<uint32_t> ** value) = 0;
    virtual HRESULT __stdcall get_MinDistanceInMillimeters(Windows::Foundation::IReference<uint32_t> ** value) = 0;
    virtual HRESULT __stdcall abi_GetCurrentReading(Windows::Devices::Sensors::IProximitySensorReading ** value) = 0;
    virtual HRESULT __stdcall add_ReadingChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::ProximitySensor, Windows::Devices::Sensors::ProximitySensorReadingChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ReadingChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_CreateDisplayOnOffController(Windows::Foundation::IClosable ** controller) = 0;
};

struct __declspec(uuid("905ac121-6d27-4ad3-9db5-6467f2a5ad9d")) __declspec(novtable) IProximitySensorDataThresholdFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Devices::Sensors::IProximitySensor * sensor, Windows::Devices::Sensors::ISensorDataThreshold ** threshold) = 0;
};

struct __declspec(uuid("71228d59-132d-4d5f-8ff9-2f0db8751ced")) __declspec(novtable) IProximitySensorReading : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_IsDetected(bool * value) = 0;
    virtual HRESULT __stdcall get_DistanceInMillimeters(Windows::Foundation::IReference<uint32_t> ** value) = 0;
};

struct __declspec(uuid("cfc2f366-c3e8-40fd-8cc3-67e289004938")) __declspec(novtable) IProximitySensorReadingChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Reading(Windows::Devices::Sensors::IProximitySensorReading ** value) = 0;
};

struct __declspec(uuid("29186649-6269-4e57-a5ad-82be80813392")) __declspec(novtable) IProximitySensorStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeviceSelector(hstring * value) = 0;
    virtual HRESULT __stdcall abi_FromId(hstring sensorId, Windows::Devices::Sensors::IProximitySensor ** result) = 0;
};

struct __declspec(uuid("cbf473ae-e9ca-422f-ad67-4c3d25df350c")) __declspec(novtable) IProximitySensorStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetReadingsFromTriggerDetails(Windows::Devices::Sensors::ISensorDataThresholdTriggerDetails * triggerDetails, Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::ProximitySensorReading> ** result) = 0;
};

struct __declspec(uuid("54daec61-fe4b-4e07-b260-3a4cdfbe396e")) __declspec(novtable) ISensorDataThreshold : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("9106f1b7-e88d-48b1-bc90-619c7b349391")) __declspec(novtable) ISensorDataThresholdTriggerDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_SensorType(winrt::Windows::Devices::Sensors::SensorType * value) = 0;
};

struct __declspec(uuid("c9c5c827-c71c-46e7-9da3-36a193b232bc")) __declspec(novtable) ISensorQuaternion : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_W(float * value) = 0;
    virtual HRESULT __stdcall get_X(float * value) = 0;
    virtual HRESULT __stdcall get_Y(float * value) = 0;
    virtual HRESULT __stdcall get_Z(float * value) = 0;
};

struct __declspec(uuid("0a3d5a67-22f4-4392-9538-65d0bd064aa6")) __declspec(novtable) ISensorRotationMatrix : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_M11(float * value) = 0;
    virtual HRESULT __stdcall get_M12(float * value) = 0;
    virtual HRESULT __stdcall get_M13(float * value) = 0;
    virtual HRESULT __stdcall get_M21(float * value) = 0;
    virtual HRESULT __stdcall get_M22(float * value) = 0;
    virtual HRESULT __stdcall get_M23(float * value) = 0;
    virtual HRESULT __stdcall get_M31(float * value) = 0;
    virtual HRESULT __stdcall get_M32(float * value) = 0;
    virtual HRESULT __stdcall get_M33(float * value) = 0;
};

struct __declspec(uuid("5ff53856-214a-4dee-a3f9-616f1ab06ffd")) __declspec(novtable) ISimpleOrientationSensor : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetCurrentOrientation(winrt::Windows::Devices::Sensors::SimpleOrientation * value) = 0;
    virtual HRESULT __stdcall add_OrientationChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::SimpleOrientationSensor, Windows::Devices::Sensors::SimpleOrientationSensorOrientationChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_OrientationChanged(event_token token) = 0;
};

struct __declspec(uuid("a277a798-8870-453e-8bd6-b8f5d8d7941b")) __declspec(novtable) ISimpleOrientationSensor2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_ReadingTransform(winrt::Windows::Graphics::Display::DisplayOrientations value) = 0;
    virtual HRESULT __stdcall get_ReadingTransform(winrt::Windows::Graphics::Display::DisplayOrientations * value) = 0;
};

struct __declspec(uuid("fbc00acb-3b76-41f6-8091-30efe646d3cf")) __declspec(novtable) ISimpleOrientationSensorDeviceId : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
};

struct __declspec(uuid("bcd5c660-23d4-4b4c-a22e-ba81ade0c601")) __declspec(novtable) ISimpleOrientationSensorOrientationChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_Orientation(winrt::Windows::Devices::Sensors::SimpleOrientation * value) = 0;
};

struct __declspec(uuid("72ed066f-70aa-40c6-9b1b-3433f7459b4e")) __declspec(novtable) ISimpleOrientationSensorStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDefault(Windows::Devices::Sensors::ISimpleOrientationSensor ** result) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::Sensors::Accelerometer> { using default_interface = Windows::Devices::Sensors::IAccelerometer; };
template <> struct traits<Windows::Devices::Sensors::AccelerometerReading> { using default_interface = Windows::Devices::Sensors::IAccelerometerReading; };
template <> struct traits<Windows::Devices::Sensors::AccelerometerReadingChangedEventArgs> { using default_interface = Windows::Devices::Sensors::IAccelerometerReadingChangedEventArgs; };
template <> struct traits<Windows::Devices::Sensors::AccelerometerShakenEventArgs> { using default_interface = Windows::Devices::Sensors::IAccelerometerShakenEventArgs; };
template <> struct traits<Windows::Devices::Sensors::ActivitySensor> { using default_interface = Windows::Devices::Sensors::IActivitySensor; };
template <> struct traits<Windows::Devices::Sensors::ActivitySensorReading> { using default_interface = Windows::Devices::Sensors::IActivitySensorReading; };
template <> struct traits<Windows::Devices::Sensors::ActivitySensorReadingChangeReport> { using default_interface = Windows::Devices::Sensors::IActivitySensorReadingChangeReport; };
template <> struct traits<Windows::Devices::Sensors::ActivitySensorReadingChangedEventArgs> { using default_interface = Windows::Devices::Sensors::IActivitySensorReadingChangedEventArgs; };
template <> struct traits<Windows::Devices::Sensors::ActivitySensorTriggerDetails> { using default_interface = Windows::Devices::Sensors::IActivitySensorTriggerDetails; };
template <> struct traits<Windows::Devices::Sensors::Altimeter> { using default_interface = Windows::Devices::Sensors::IAltimeter; };
template <> struct traits<Windows::Devices::Sensors::AltimeterReading> { using default_interface = Windows::Devices::Sensors::IAltimeterReading; };
template <> struct traits<Windows::Devices::Sensors::AltimeterReadingChangedEventArgs> { using default_interface = Windows::Devices::Sensors::IAltimeterReadingChangedEventArgs; };
template <> struct traits<Windows::Devices::Sensors::Barometer> { using default_interface = Windows::Devices::Sensors::IBarometer; };
template <> struct traits<Windows::Devices::Sensors::BarometerReading> { using default_interface = Windows::Devices::Sensors::IBarometerReading; };
template <> struct traits<Windows::Devices::Sensors::BarometerReadingChangedEventArgs> { using default_interface = Windows::Devices::Sensors::IBarometerReadingChangedEventArgs; };
template <> struct traits<Windows::Devices::Sensors::Compass> { using default_interface = Windows::Devices::Sensors::ICompass; };
template <> struct traits<Windows::Devices::Sensors::CompassReading> { using default_interface = Windows::Devices::Sensors::ICompassReading; };
template <> struct traits<Windows::Devices::Sensors::CompassReadingChangedEventArgs> { using default_interface = Windows::Devices::Sensors::ICompassReadingChangedEventArgs; };
template <> struct traits<Windows::Devices::Sensors::Gyrometer> { using default_interface = Windows::Devices::Sensors::IGyrometer; };
template <> struct traits<Windows::Devices::Sensors::GyrometerReading> { using default_interface = Windows::Devices::Sensors::IGyrometerReading; };
template <> struct traits<Windows::Devices::Sensors::GyrometerReadingChangedEventArgs> { using default_interface = Windows::Devices::Sensors::IGyrometerReadingChangedEventArgs; };
template <> struct traits<Windows::Devices::Sensors::Inclinometer> { using default_interface = Windows::Devices::Sensors::IInclinometer; };
template <> struct traits<Windows::Devices::Sensors::InclinometerReading> { using default_interface = Windows::Devices::Sensors::IInclinometerReading; };
template <> struct traits<Windows::Devices::Sensors::InclinometerReadingChangedEventArgs> { using default_interface = Windows::Devices::Sensors::IInclinometerReadingChangedEventArgs; };
template <> struct traits<Windows::Devices::Sensors::LightSensor> { using default_interface = Windows::Devices::Sensors::ILightSensor; };
template <> struct traits<Windows::Devices::Sensors::LightSensorReading> { using default_interface = Windows::Devices::Sensors::ILightSensorReading; };
template <> struct traits<Windows::Devices::Sensors::LightSensorReadingChangedEventArgs> { using default_interface = Windows::Devices::Sensors::ILightSensorReadingChangedEventArgs; };
template <> struct traits<Windows::Devices::Sensors::Magnetometer> { using default_interface = Windows::Devices::Sensors::IMagnetometer; };
template <> struct traits<Windows::Devices::Sensors::MagnetometerReading> { using default_interface = Windows::Devices::Sensors::IMagnetometerReading; };
template <> struct traits<Windows::Devices::Sensors::MagnetometerReadingChangedEventArgs> { using default_interface = Windows::Devices::Sensors::IMagnetometerReadingChangedEventArgs; };
template <> struct traits<Windows::Devices::Sensors::OrientationSensor> { using default_interface = Windows::Devices::Sensors::IOrientationSensor; };
template <> struct traits<Windows::Devices::Sensors::OrientationSensorReading> { using default_interface = Windows::Devices::Sensors::IOrientationSensorReading; };
template <> struct traits<Windows::Devices::Sensors::OrientationSensorReadingChangedEventArgs> { using default_interface = Windows::Devices::Sensors::IOrientationSensorReadingChangedEventArgs; };
template <> struct traits<Windows::Devices::Sensors::Pedometer> { using default_interface = Windows::Devices::Sensors::IPedometer; };
template <> struct traits<Windows::Devices::Sensors::PedometerDataThreshold> { using default_interface = Windows::Devices::Sensors::ISensorDataThreshold; };
template <> struct traits<Windows::Devices::Sensors::PedometerReading> { using default_interface = Windows::Devices::Sensors::IPedometerReading; };
template <> struct traits<Windows::Devices::Sensors::PedometerReadingChangedEventArgs> { using default_interface = Windows::Devices::Sensors::IPedometerReadingChangedEventArgs; };
template <> struct traits<Windows::Devices::Sensors::ProximitySensor> { using default_interface = Windows::Devices::Sensors::IProximitySensor; };
template <> struct traits<Windows::Devices::Sensors::ProximitySensorDataThreshold> { using default_interface = Windows::Devices::Sensors::ISensorDataThreshold; };
template <> struct traits<Windows::Devices::Sensors::ProximitySensorDisplayOnOffController> { using default_interface = Windows::Foundation::IClosable; };
template <> struct traits<Windows::Devices::Sensors::ProximitySensorReading> { using default_interface = Windows::Devices::Sensors::IProximitySensorReading; };
template <> struct traits<Windows::Devices::Sensors::ProximitySensorReadingChangedEventArgs> { using default_interface = Windows::Devices::Sensors::IProximitySensorReadingChangedEventArgs; };
template <> struct traits<Windows::Devices::Sensors::SensorDataThresholdTriggerDetails> { using default_interface = Windows::Devices::Sensors::ISensorDataThresholdTriggerDetails; };
template <> struct traits<Windows::Devices::Sensors::SensorQuaternion> { using default_interface = Windows::Devices::Sensors::ISensorQuaternion; };
template <> struct traits<Windows::Devices::Sensors::SensorRotationMatrix> { using default_interface = Windows::Devices::Sensors::ISensorRotationMatrix; };
template <> struct traits<Windows::Devices::Sensors::SimpleOrientationSensor> { using default_interface = Windows::Devices::Sensors::ISimpleOrientationSensor; };
template <> struct traits<Windows::Devices::Sensors::SimpleOrientationSensorOrientationChangedEventArgs> { using default_interface = Windows::Devices::Sensors::ISimpleOrientationSensorOrientationChangedEventArgs; };

}

namespace Windows::Devices::Sensors {

template <typename D>
struct WINRT_EBO impl_IAccelerometer
{
    Windows::Devices::Sensors::AccelerometerReading GetCurrentReading() const;
    uint32_t MinimumReportInterval() const;
    void ReportInterval(uint32_t value) const;
    uint32_t ReportInterval() const;
    event_token ReadingChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Accelerometer, Windows::Devices::Sensors::AccelerometerReadingChangedEventArgs> & handler) const;
    using ReadingChanged_revoker = event_revoker<IAccelerometer>;
    ReadingChanged_revoker ReadingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Accelerometer, Windows::Devices::Sensors::AccelerometerReadingChangedEventArgs> & handler) const;
    void ReadingChanged(event_token token) const;
    event_token Shaken(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Accelerometer, Windows::Devices::Sensors::AccelerometerShakenEventArgs> & handler) const;
    using Shaken_revoker = event_revoker<IAccelerometer>;
    Shaken_revoker Shaken(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Accelerometer, Windows::Devices::Sensors::AccelerometerShakenEventArgs> & handler) const;
    void Shaken(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IAccelerometer2
{
    void ReadingTransform(Windows::Graphics::Display::DisplayOrientations value) const;
    Windows::Graphics::Display::DisplayOrientations ReadingTransform() const;
};

template <typename D>
struct WINRT_EBO impl_IAccelerometer3
{
    void ReportLatency(uint32_t value) const;
    uint32_t ReportLatency() const;
    uint32_t MaxBatchSize() const;
};

template <typename D>
struct WINRT_EBO impl_IAccelerometer4
{
    Windows::Devices::Sensors::AccelerometerReadingType ReadingType() const;
};

template <typename D>
struct WINRT_EBO impl_IAccelerometerDeviceId
{
    hstring DeviceId() const;
};

template <typename D>
struct WINRT_EBO impl_IAccelerometerReading
{
    Windows::Foundation::DateTime Timestamp() const;
    double AccelerationX() const;
    double AccelerationY() const;
    double AccelerationZ() const;
};

template <typename D>
struct WINRT_EBO impl_IAccelerometerReadingChangedEventArgs
{
    Windows::Devices::Sensors::AccelerometerReading Reading() const;
};

template <typename D>
struct WINRT_EBO impl_IAccelerometerShakenEventArgs
{
    Windows::Foundation::DateTime Timestamp() const;
};

template <typename D>
struct WINRT_EBO impl_IAccelerometerStatics
{
    Windows::Devices::Sensors::Accelerometer GetDefault() const;
};

template <typename D>
struct WINRT_EBO impl_IAccelerometerStatics2
{
    Windows::Devices::Sensors::Accelerometer GetDefault(Windows::Devices::Sensors::AccelerometerReadingType readingType) const;
};

template <typename D>
struct WINRT_EBO impl_IActivitySensor
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::ActivitySensorReading> GetCurrentReadingAsync() const;
    Windows::Foundation::Collections::IVector<winrt::Windows::Devices::Sensors::ActivityType> SubscribedActivities() const;
    double PowerInMilliwatts() const;
    hstring DeviceId() const;
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::Sensors::ActivityType> SupportedActivities() const;
    uint32_t MinimumReportInterval() const;
    event_token ReadingChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::ActivitySensor, Windows::Devices::Sensors::ActivitySensorReadingChangedEventArgs> & handler) const;
    using ReadingChanged_revoker = event_revoker<IActivitySensor>;
    ReadingChanged_revoker ReadingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::ActivitySensor, Windows::Devices::Sensors::ActivitySensorReadingChangedEventArgs> & handler) const;
    void ReadingChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IActivitySensorReading
{
    Windows::Foundation::DateTime Timestamp() const;
    Windows::Devices::Sensors::ActivityType Activity() const;
    Windows::Devices::Sensors::ActivitySensorReadingConfidence Confidence() const;
};

template <typename D>
struct WINRT_EBO impl_IActivitySensorReadingChangeReport
{
    Windows::Devices::Sensors::ActivitySensorReading Reading() const;
};

template <typename D>
struct WINRT_EBO impl_IActivitySensorReadingChangedEventArgs
{
    Windows::Devices::Sensors::ActivitySensorReading Reading() const;
};

template <typename D>
struct WINRT_EBO impl_IActivitySensorStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::ActivitySensor> GetDefaultAsync() const;
    hstring GetDeviceSelector() const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::ActivitySensor> FromIdAsync(hstring_view deviceId) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::ActivitySensorReading>> GetSystemHistoryAsync(const Windows::Foundation::DateTime & fromTime) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::ActivitySensorReading>> GetSystemHistoryAsync(const Windows::Foundation::DateTime & fromTime, const Windows::Foundation::TimeSpan & duration) const;
};

template <typename D>
struct WINRT_EBO impl_IActivitySensorTriggerDetails
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::ActivitySensorReadingChangeReport> ReadReports() const;
};

template <typename D>
struct WINRT_EBO impl_IAltimeter
{
    Windows::Devices::Sensors::AltimeterReading GetCurrentReading() const;
    hstring DeviceId() const;
    uint32_t MinimumReportInterval() const;
    void ReportInterval(uint32_t value) const;
    uint32_t ReportInterval() const;
    event_token ReadingChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Altimeter, Windows::Devices::Sensors::AltimeterReadingChangedEventArgs> & handler) const;
    using ReadingChanged_revoker = event_revoker<IAltimeter>;
    ReadingChanged_revoker ReadingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Altimeter, Windows::Devices::Sensors::AltimeterReadingChangedEventArgs> & handler) const;
    void ReadingChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IAltimeterReading
{
    Windows::Foundation::DateTime Timestamp() const;
    double AltitudeChangeInMeters() const;
};

template <typename D>
struct WINRT_EBO impl_IAltimeterReadingChangedEventArgs
{
    Windows::Devices::Sensors::AltimeterReading Reading() const;
};

template <typename D>
struct WINRT_EBO impl_IAltimeterStatics
{
    Windows::Devices::Sensors::Altimeter GetDefault() const;
};

template <typename D>
struct WINRT_EBO impl_IBarometer
{
    Windows::Devices::Sensors::BarometerReading GetCurrentReading() const;
    hstring DeviceId() const;
    uint32_t MinimumReportInterval() const;
    void ReportInterval(uint32_t value) const;
    uint32_t ReportInterval() const;
    event_token ReadingChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Barometer, Windows::Devices::Sensors::BarometerReadingChangedEventArgs> & handler) const;
    using ReadingChanged_revoker = event_revoker<IBarometer>;
    ReadingChanged_revoker ReadingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Barometer, Windows::Devices::Sensors::BarometerReadingChangedEventArgs> & handler) const;
    void ReadingChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IBarometerReading
{
    Windows::Foundation::DateTime Timestamp() const;
    double StationPressureInHectopascals() const;
};

template <typename D>
struct WINRT_EBO impl_IBarometerReadingChangedEventArgs
{
    Windows::Devices::Sensors::BarometerReading Reading() const;
};

template <typename D>
struct WINRT_EBO impl_IBarometerStatics
{
    Windows::Devices::Sensors::Barometer GetDefault() const;
};

template <typename D>
struct WINRT_EBO impl_ICompass
{
    Windows::Devices::Sensors::CompassReading GetCurrentReading() const;
    uint32_t MinimumReportInterval() const;
    void ReportInterval(uint32_t value) const;
    uint32_t ReportInterval() const;
    event_token ReadingChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Compass, Windows::Devices::Sensors::CompassReadingChangedEventArgs> & handler) const;
    using ReadingChanged_revoker = event_revoker<ICompass>;
    ReadingChanged_revoker ReadingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Compass, Windows::Devices::Sensors::CompassReadingChangedEventArgs> & handler) const;
    void ReadingChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_ICompass2
{
    void ReadingTransform(Windows::Graphics::Display::DisplayOrientations value) const;
    Windows::Graphics::Display::DisplayOrientations ReadingTransform() const;
};

template <typename D>
struct WINRT_EBO impl_ICompassDeviceId
{
    hstring DeviceId() const;
};

template <typename D>
struct WINRT_EBO impl_ICompassReading
{
    Windows::Foundation::DateTime Timestamp() const;
    double HeadingMagneticNorth() const;
    Windows::Foundation::IReference<double> HeadingTrueNorth() const;
};

template <typename D>
struct WINRT_EBO impl_ICompassReadingChangedEventArgs
{
    Windows::Devices::Sensors::CompassReading Reading() const;
};

template <typename D>
struct WINRT_EBO impl_ICompassReadingHeadingAccuracy
{
    Windows::Devices::Sensors::MagnetometerAccuracy HeadingAccuracy() const;
};

template <typename D>
struct WINRT_EBO impl_ICompassStatics
{
    Windows::Devices::Sensors::Compass GetDefault() const;
};

template <typename D>
struct WINRT_EBO impl_IGyrometer
{
    Windows::Devices::Sensors::GyrometerReading GetCurrentReading() const;
    uint32_t MinimumReportInterval() const;
    void ReportInterval(uint32_t value) const;
    uint32_t ReportInterval() const;
    event_token ReadingChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Gyrometer, Windows::Devices::Sensors::GyrometerReadingChangedEventArgs> & handler) const;
    using ReadingChanged_revoker = event_revoker<IGyrometer>;
    ReadingChanged_revoker ReadingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Gyrometer, Windows::Devices::Sensors::GyrometerReadingChangedEventArgs> & handler) const;
    void ReadingChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IGyrometer2
{
    void ReadingTransform(Windows::Graphics::Display::DisplayOrientations value) const;
    Windows::Graphics::Display::DisplayOrientations ReadingTransform() const;
};

template <typename D>
struct WINRT_EBO impl_IGyrometerDeviceId
{
    hstring DeviceId() const;
};

template <typename D>
struct WINRT_EBO impl_IGyrometerReading
{
    Windows::Foundation::DateTime Timestamp() const;
    double AngularVelocityX() const;
    double AngularVelocityY() const;
    double AngularVelocityZ() const;
};

template <typename D>
struct WINRT_EBO impl_IGyrometerReadingChangedEventArgs
{
    Windows::Devices::Sensors::GyrometerReading Reading() const;
};

template <typename D>
struct WINRT_EBO impl_IGyrometerStatics
{
    Windows::Devices::Sensors::Gyrometer GetDefault() const;
};

template <typename D>
struct WINRT_EBO impl_IInclinometer
{
    Windows::Devices::Sensors::InclinometerReading GetCurrentReading() const;
    uint32_t MinimumReportInterval() const;
    void ReportInterval(uint32_t value) const;
    uint32_t ReportInterval() const;
    event_token ReadingChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Inclinometer, Windows::Devices::Sensors::InclinometerReadingChangedEventArgs> & handler) const;
    using ReadingChanged_revoker = event_revoker<IInclinometer>;
    ReadingChanged_revoker ReadingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Inclinometer, Windows::Devices::Sensors::InclinometerReadingChangedEventArgs> & handler) const;
    void ReadingChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IInclinometer2
{
    void ReadingTransform(Windows::Graphics::Display::DisplayOrientations value) const;
    Windows::Graphics::Display::DisplayOrientations ReadingTransform() const;
    Windows::Devices::Sensors::SensorReadingType ReadingType() const;
};

template <typename D>
struct WINRT_EBO impl_IInclinometerDeviceId
{
    hstring DeviceId() const;
};

template <typename D>
struct WINRT_EBO impl_IInclinometerReading
{
    Windows::Foundation::DateTime Timestamp() const;
    float PitchDegrees() const;
    float RollDegrees() const;
    float YawDegrees() const;
};

template <typename D>
struct WINRT_EBO impl_IInclinometerReadingChangedEventArgs
{
    Windows::Devices::Sensors::InclinometerReading Reading() const;
};

template <typename D>
struct WINRT_EBO impl_IInclinometerReadingYawAccuracy
{
    Windows::Devices::Sensors::MagnetometerAccuracy YawAccuracy() const;
};

template <typename D>
struct WINRT_EBO impl_IInclinometerStatics
{
    Windows::Devices::Sensors::Inclinometer GetDefault() const;
};

template <typename D>
struct WINRT_EBO impl_IInclinometerStatics2
{
    Windows::Devices::Sensors::Inclinometer GetDefaultForRelativeReadings() const;
};

template <typename D>
struct WINRT_EBO impl_IInclinometerStatics3
{
    Windows::Devices::Sensors::Inclinometer GetDefault(Windows::Devices::Sensors::SensorReadingType sensorReadingtype) const;
};

template <typename D>
struct WINRT_EBO impl_ILightSensor
{
    Windows::Devices::Sensors::LightSensorReading GetCurrentReading() const;
    uint32_t MinimumReportInterval() const;
    void ReportInterval(uint32_t value) const;
    uint32_t ReportInterval() const;
    event_token ReadingChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::LightSensor, Windows::Devices::Sensors::LightSensorReadingChangedEventArgs> & handler) const;
    using ReadingChanged_revoker = event_revoker<ILightSensor>;
    ReadingChanged_revoker ReadingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::LightSensor, Windows::Devices::Sensors::LightSensorReadingChangedEventArgs> & handler) const;
    void ReadingChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_ILightSensorDeviceId
{
    hstring DeviceId() const;
};

template <typename D>
struct WINRT_EBO impl_ILightSensorReading
{
    Windows::Foundation::DateTime Timestamp() const;
    float IlluminanceInLux() const;
};

template <typename D>
struct WINRT_EBO impl_ILightSensorReadingChangedEventArgs
{
    Windows::Devices::Sensors::LightSensorReading Reading() const;
};

template <typename D>
struct WINRT_EBO impl_ILightSensorStatics
{
    Windows::Devices::Sensors::LightSensor GetDefault() const;
};

template <typename D>
struct WINRT_EBO impl_IMagnetometer
{
    Windows::Devices::Sensors::MagnetometerReading GetCurrentReading() const;
    uint32_t MinimumReportInterval() const;
    void ReportInterval(uint32_t value) const;
    uint32_t ReportInterval() const;
    event_token ReadingChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Magnetometer, Windows::Devices::Sensors::MagnetometerReadingChangedEventArgs> & handler) const;
    using ReadingChanged_revoker = event_revoker<IMagnetometer>;
    ReadingChanged_revoker ReadingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Magnetometer, Windows::Devices::Sensors::MagnetometerReadingChangedEventArgs> & handler) const;
    void ReadingChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IMagnetometer2
{
    void ReadingTransform(Windows::Graphics::Display::DisplayOrientations value) const;
    Windows::Graphics::Display::DisplayOrientations ReadingTransform() const;
};

template <typename D>
struct WINRT_EBO impl_IMagnetometerDeviceId
{
    hstring DeviceId() const;
};

template <typename D>
struct WINRT_EBO impl_IMagnetometerReading
{
    Windows::Foundation::DateTime Timestamp() const;
    float MagneticFieldX() const;
    float MagneticFieldY() const;
    float MagneticFieldZ() const;
    Windows::Devices::Sensors::MagnetometerAccuracy DirectionalAccuracy() const;
};

template <typename D>
struct WINRT_EBO impl_IMagnetometerReadingChangedEventArgs
{
    Windows::Devices::Sensors::MagnetometerReading Reading() const;
};

template <typename D>
struct WINRT_EBO impl_IMagnetometerStatics
{
    Windows::Devices::Sensors::Magnetometer GetDefault() const;
};

template <typename D>
struct WINRT_EBO impl_IOrientationSensor
{
    Windows::Devices::Sensors::OrientationSensorReading GetCurrentReading() const;
    uint32_t MinimumReportInterval() const;
    void ReportInterval(uint32_t value) const;
    uint32_t ReportInterval() const;
    event_token ReadingChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::OrientationSensor, Windows::Devices::Sensors::OrientationSensorReadingChangedEventArgs> & handler) const;
    using ReadingChanged_revoker = event_revoker<IOrientationSensor>;
    ReadingChanged_revoker ReadingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::OrientationSensor, Windows::Devices::Sensors::OrientationSensorReadingChangedEventArgs> & handler) const;
    void ReadingChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IOrientationSensor2
{
    void ReadingTransform(Windows::Graphics::Display::DisplayOrientations value) const;
    Windows::Graphics::Display::DisplayOrientations ReadingTransform() const;
    Windows::Devices::Sensors::SensorReadingType ReadingType() const;
};

template <typename D>
struct WINRT_EBO impl_IOrientationSensorDeviceId
{
    hstring DeviceId() const;
};

template <typename D>
struct WINRT_EBO impl_IOrientationSensorReading
{
    Windows::Foundation::DateTime Timestamp() const;
    Windows::Devices::Sensors::SensorRotationMatrix RotationMatrix() const;
    Windows::Devices::Sensors::SensorQuaternion Quaternion() const;
};

template <typename D>
struct WINRT_EBO impl_IOrientationSensorReadingChangedEventArgs
{
    Windows::Devices::Sensors::OrientationSensorReading Reading() const;
};

template <typename D>
struct WINRT_EBO impl_IOrientationSensorReadingYawAccuracy
{
    Windows::Devices::Sensors::MagnetometerAccuracy YawAccuracy() const;
};

template <typename D>
struct WINRT_EBO impl_IOrientationSensorStatics
{
    Windows::Devices::Sensors::OrientationSensor GetDefault() const;
};

template <typename D>
struct WINRT_EBO impl_IOrientationSensorStatics2
{
    Windows::Devices::Sensors::OrientationSensor GetDefaultForRelativeReadings() const;
};

template <typename D>
struct WINRT_EBO impl_IOrientationSensorStatics3
{
    Windows::Devices::Sensors::OrientationSensor GetDefault(Windows::Devices::Sensors::SensorReadingType sensorReadingtype) const;
    Windows::Devices::Sensors::OrientationSensor GetDefault(Windows::Devices::Sensors::SensorReadingType sensorReadingType, Windows::Devices::Sensors::SensorOptimizationGoal optimizationGoal) const;
};

template <typename D>
struct WINRT_EBO impl_IPedometer
{
    hstring DeviceId() const;
    double PowerInMilliwatts() const;
    uint32_t MinimumReportInterval() const;
    void ReportInterval(uint32_t value) const;
    uint32_t ReportInterval() const;
    event_token ReadingChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Pedometer, Windows::Devices::Sensors::PedometerReadingChangedEventArgs> & handler) const;
    using ReadingChanged_revoker = event_revoker<IPedometer>;
    ReadingChanged_revoker ReadingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::Pedometer, Windows::Devices::Sensors::PedometerReadingChangedEventArgs> & handler) const;
    void ReadingChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IPedometer2
{
    Windows::Foundation::Collections::IMapView<winrt::Windows::Devices::Sensors::PedometerStepKind, Windows::Devices::Sensors::PedometerReading> GetCurrentReadings() const;
};

template <typename D>
struct WINRT_EBO impl_IPedometerDataThresholdFactory
{
    Windows::Devices::Sensors::PedometerDataThreshold Create(const Windows::Devices::Sensors::Pedometer & sensor, int32_t stepGoal) const;
};

template <typename D>
struct WINRT_EBO impl_IPedometerReading
{
    Windows::Devices::Sensors::PedometerStepKind StepKind() const;
    int32_t CumulativeSteps() const;
    Windows::Foundation::DateTime Timestamp() const;
    Windows::Foundation::TimeSpan CumulativeStepsDuration() const;
};

template <typename D>
struct WINRT_EBO impl_IPedometerReadingChangedEventArgs
{
    Windows::Devices::Sensors::PedometerReading Reading() const;
};

template <typename D>
struct WINRT_EBO impl_IPedometerStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::Pedometer> FromIdAsync(hstring_view deviceId) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Sensors::Pedometer> GetDefaultAsync() const;
    hstring GetDeviceSelector() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::PedometerReading>> GetSystemHistoryAsync(const Windows::Foundation::DateTime & fromTime) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::PedometerReading>> GetSystemHistoryAsync(const Windows::Foundation::DateTime & fromTime, const Windows::Foundation::TimeSpan & duration) const;
};

template <typename D>
struct WINRT_EBO impl_IPedometerStatics2
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::PedometerReading> GetReadingsFromTriggerDetails(const Windows::Devices::Sensors::SensorDataThresholdTriggerDetails & triggerDetails) const;
};

template <typename D>
struct WINRT_EBO impl_IProximitySensor
{
    hstring DeviceId() const;
    Windows::Foundation::IReference<uint32_t> MaxDistanceInMillimeters() const;
    Windows::Foundation::IReference<uint32_t> MinDistanceInMillimeters() const;
    Windows::Devices::Sensors::ProximitySensorReading GetCurrentReading() const;
    event_token ReadingChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::ProximitySensor, Windows::Devices::Sensors::ProximitySensorReadingChangedEventArgs> & handler) const;
    using ReadingChanged_revoker = event_revoker<IProximitySensor>;
    ReadingChanged_revoker ReadingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::ProximitySensor, Windows::Devices::Sensors::ProximitySensorReadingChangedEventArgs> & handler) const;
    void ReadingChanged(event_token token) const;
    Windows::Devices::Sensors::ProximitySensorDisplayOnOffController CreateDisplayOnOffController() const;
};

template <typename D>
struct WINRT_EBO impl_IProximitySensorDataThresholdFactory
{
    Windows::Devices::Sensors::ProximitySensorDataThreshold Create(const Windows::Devices::Sensors::ProximitySensor & sensor) const;
};

template <typename D>
struct WINRT_EBO impl_IProximitySensorReading
{
    Windows::Foundation::DateTime Timestamp() const;
    bool IsDetected() const;
    Windows::Foundation::IReference<uint32_t> DistanceInMillimeters() const;
};

template <typename D>
struct WINRT_EBO impl_IProximitySensorReadingChangedEventArgs
{
    Windows::Devices::Sensors::ProximitySensorReading Reading() const;
};

template <typename D>
struct WINRT_EBO impl_IProximitySensorStatics
{
    hstring GetDeviceSelector() const;
    Windows::Devices::Sensors::ProximitySensor FromId(hstring_view sensorId) const;
};

template <typename D>
struct WINRT_EBO impl_IProximitySensorStatics2
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Sensors::ProximitySensorReading> GetReadingsFromTriggerDetails(const Windows::Devices::Sensors::SensorDataThresholdTriggerDetails & triggerDetails) const;
};

template <typename D>
struct WINRT_EBO impl_ISensorDataThreshold
{
};

template <typename D>
struct WINRT_EBO impl_ISensorDataThresholdTriggerDetails
{
    hstring DeviceId() const;
    Windows::Devices::Sensors::SensorType SensorType() const;
};

template <typename D>
struct WINRT_EBO impl_ISensorQuaternion
{
    float W() const;
    float X() const;
    float Y() const;
    float Z() const;
};

template <typename D>
struct WINRT_EBO impl_ISensorRotationMatrix
{
    float M11() const;
    float M12() const;
    float M13() const;
    float M21() const;
    float M22() const;
    float M23() const;
    float M31() const;
    float M32() const;
    float M33() const;
};

template <typename D>
struct WINRT_EBO impl_ISimpleOrientationSensor
{
    Windows::Devices::Sensors::SimpleOrientation GetCurrentOrientation() const;
    event_token OrientationChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::SimpleOrientationSensor, Windows::Devices::Sensors::SimpleOrientationSensorOrientationChangedEventArgs> & handler) const;
    using OrientationChanged_revoker = event_revoker<ISimpleOrientationSensor>;
    OrientationChanged_revoker OrientationChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sensors::SimpleOrientationSensor, Windows::Devices::Sensors::SimpleOrientationSensorOrientationChangedEventArgs> & handler) const;
    void OrientationChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_ISimpleOrientationSensor2
{
    void ReadingTransform(Windows::Graphics::Display::DisplayOrientations value) const;
    Windows::Graphics::Display::DisplayOrientations ReadingTransform() const;
};

template <typename D>
struct WINRT_EBO impl_ISimpleOrientationSensorDeviceId
{
    hstring DeviceId() const;
};

template <typename D>
struct WINRT_EBO impl_ISimpleOrientationSensorOrientationChangedEventArgs
{
    Windows::Foundation::DateTime Timestamp() const;
    Windows::Devices::Sensors::SimpleOrientation Orientation() const;
};

template <typename D>
struct WINRT_EBO impl_ISimpleOrientationSensorStatics
{
    Windows::Devices::Sensors::SimpleOrientationSensor GetDefault() const;
};

}

namespace impl {

template <> struct traits<Windows::Devices::Sensors::IAccelerometer>
{
    using abi = ABI::Windows::Devices::Sensors::IAccelerometer;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IAccelerometer<D>;
};

template <> struct traits<Windows::Devices::Sensors::IAccelerometer2>
{
    using abi = ABI::Windows::Devices::Sensors::IAccelerometer2;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IAccelerometer2<D>;
};

template <> struct traits<Windows::Devices::Sensors::IAccelerometer3>
{
    using abi = ABI::Windows::Devices::Sensors::IAccelerometer3;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IAccelerometer3<D>;
};

template <> struct traits<Windows::Devices::Sensors::IAccelerometer4>
{
    using abi = ABI::Windows::Devices::Sensors::IAccelerometer4;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IAccelerometer4<D>;
};

template <> struct traits<Windows::Devices::Sensors::IAccelerometerDeviceId>
{
    using abi = ABI::Windows::Devices::Sensors::IAccelerometerDeviceId;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IAccelerometerDeviceId<D>;
};

template <> struct traits<Windows::Devices::Sensors::IAccelerometerReading>
{
    using abi = ABI::Windows::Devices::Sensors::IAccelerometerReading;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IAccelerometerReading<D>;
};

template <> struct traits<Windows::Devices::Sensors::IAccelerometerReadingChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Sensors::IAccelerometerReadingChangedEventArgs;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IAccelerometerReadingChangedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Sensors::IAccelerometerShakenEventArgs>
{
    using abi = ABI::Windows::Devices::Sensors::IAccelerometerShakenEventArgs;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IAccelerometerShakenEventArgs<D>;
};

template <> struct traits<Windows::Devices::Sensors::IAccelerometerStatics>
{
    using abi = ABI::Windows::Devices::Sensors::IAccelerometerStatics;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IAccelerometerStatics<D>;
};

template <> struct traits<Windows::Devices::Sensors::IAccelerometerStatics2>
{
    using abi = ABI::Windows::Devices::Sensors::IAccelerometerStatics2;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IAccelerometerStatics2<D>;
};

template <> struct traits<Windows::Devices::Sensors::IActivitySensor>
{
    using abi = ABI::Windows::Devices::Sensors::IActivitySensor;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IActivitySensor<D>;
};

template <> struct traits<Windows::Devices::Sensors::IActivitySensorReading>
{
    using abi = ABI::Windows::Devices::Sensors::IActivitySensorReading;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IActivitySensorReading<D>;
};

template <> struct traits<Windows::Devices::Sensors::IActivitySensorReadingChangeReport>
{
    using abi = ABI::Windows::Devices::Sensors::IActivitySensorReadingChangeReport;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IActivitySensorReadingChangeReport<D>;
};

template <> struct traits<Windows::Devices::Sensors::IActivitySensorReadingChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Sensors::IActivitySensorReadingChangedEventArgs;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IActivitySensorReadingChangedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Sensors::IActivitySensorStatics>
{
    using abi = ABI::Windows::Devices::Sensors::IActivitySensorStatics;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IActivitySensorStatics<D>;
};

template <> struct traits<Windows::Devices::Sensors::IActivitySensorTriggerDetails>
{
    using abi = ABI::Windows::Devices::Sensors::IActivitySensorTriggerDetails;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IActivitySensorTriggerDetails<D>;
};

template <> struct traits<Windows::Devices::Sensors::IAltimeter>
{
    using abi = ABI::Windows::Devices::Sensors::IAltimeter;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IAltimeter<D>;
};

template <> struct traits<Windows::Devices::Sensors::IAltimeterReading>
{
    using abi = ABI::Windows::Devices::Sensors::IAltimeterReading;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IAltimeterReading<D>;
};

template <> struct traits<Windows::Devices::Sensors::IAltimeterReadingChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Sensors::IAltimeterReadingChangedEventArgs;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IAltimeterReadingChangedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Sensors::IAltimeterStatics>
{
    using abi = ABI::Windows::Devices::Sensors::IAltimeterStatics;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IAltimeterStatics<D>;
};

template <> struct traits<Windows::Devices::Sensors::IBarometer>
{
    using abi = ABI::Windows::Devices::Sensors::IBarometer;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IBarometer<D>;
};

template <> struct traits<Windows::Devices::Sensors::IBarometerReading>
{
    using abi = ABI::Windows::Devices::Sensors::IBarometerReading;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IBarometerReading<D>;
};

template <> struct traits<Windows::Devices::Sensors::IBarometerReadingChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Sensors::IBarometerReadingChangedEventArgs;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IBarometerReadingChangedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Sensors::IBarometerStatics>
{
    using abi = ABI::Windows::Devices::Sensors::IBarometerStatics;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IBarometerStatics<D>;
};

template <> struct traits<Windows::Devices::Sensors::ICompass>
{
    using abi = ABI::Windows::Devices::Sensors::ICompass;
    template <typename D> using consume = Windows::Devices::Sensors::impl_ICompass<D>;
};

template <> struct traits<Windows::Devices::Sensors::ICompass2>
{
    using abi = ABI::Windows::Devices::Sensors::ICompass2;
    template <typename D> using consume = Windows::Devices::Sensors::impl_ICompass2<D>;
};

template <> struct traits<Windows::Devices::Sensors::ICompassDeviceId>
{
    using abi = ABI::Windows::Devices::Sensors::ICompassDeviceId;
    template <typename D> using consume = Windows::Devices::Sensors::impl_ICompassDeviceId<D>;
};

template <> struct traits<Windows::Devices::Sensors::ICompassReading>
{
    using abi = ABI::Windows::Devices::Sensors::ICompassReading;
    template <typename D> using consume = Windows::Devices::Sensors::impl_ICompassReading<D>;
};

template <> struct traits<Windows::Devices::Sensors::ICompassReadingChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Sensors::ICompassReadingChangedEventArgs;
    template <typename D> using consume = Windows::Devices::Sensors::impl_ICompassReadingChangedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Sensors::ICompassReadingHeadingAccuracy>
{
    using abi = ABI::Windows::Devices::Sensors::ICompassReadingHeadingAccuracy;
    template <typename D> using consume = Windows::Devices::Sensors::impl_ICompassReadingHeadingAccuracy<D>;
};

template <> struct traits<Windows::Devices::Sensors::ICompassStatics>
{
    using abi = ABI::Windows::Devices::Sensors::ICompassStatics;
    template <typename D> using consume = Windows::Devices::Sensors::impl_ICompassStatics<D>;
};

template <> struct traits<Windows::Devices::Sensors::IGyrometer>
{
    using abi = ABI::Windows::Devices::Sensors::IGyrometer;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IGyrometer<D>;
};

template <> struct traits<Windows::Devices::Sensors::IGyrometer2>
{
    using abi = ABI::Windows::Devices::Sensors::IGyrometer2;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IGyrometer2<D>;
};

template <> struct traits<Windows::Devices::Sensors::IGyrometerDeviceId>
{
    using abi = ABI::Windows::Devices::Sensors::IGyrometerDeviceId;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IGyrometerDeviceId<D>;
};

template <> struct traits<Windows::Devices::Sensors::IGyrometerReading>
{
    using abi = ABI::Windows::Devices::Sensors::IGyrometerReading;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IGyrometerReading<D>;
};

template <> struct traits<Windows::Devices::Sensors::IGyrometerReadingChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Sensors::IGyrometerReadingChangedEventArgs;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IGyrometerReadingChangedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Sensors::IGyrometerStatics>
{
    using abi = ABI::Windows::Devices::Sensors::IGyrometerStatics;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IGyrometerStatics<D>;
};

template <> struct traits<Windows::Devices::Sensors::IInclinometer>
{
    using abi = ABI::Windows::Devices::Sensors::IInclinometer;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IInclinometer<D>;
};

template <> struct traits<Windows::Devices::Sensors::IInclinometer2>
{
    using abi = ABI::Windows::Devices::Sensors::IInclinometer2;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IInclinometer2<D>;
};

template <> struct traits<Windows::Devices::Sensors::IInclinometerDeviceId>
{
    using abi = ABI::Windows::Devices::Sensors::IInclinometerDeviceId;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IInclinometerDeviceId<D>;
};

template <> struct traits<Windows::Devices::Sensors::IInclinometerReading>
{
    using abi = ABI::Windows::Devices::Sensors::IInclinometerReading;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IInclinometerReading<D>;
};

template <> struct traits<Windows::Devices::Sensors::IInclinometerReadingChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Sensors::IInclinometerReadingChangedEventArgs;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IInclinometerReadingChangedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Sensors::IInclinometerReadingYawAccuracy>
{
    using abi = ABI::Windows::Devices::Sensors::IInclinometerReadingYawAccuracy;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IInclinometerReadingYawAccuracy<D>;
};

template <> struct traits<Windows::Devices::Sensors::IInclinometerStatics>
{
    using abi = ABI::Windows::Devices::Sensors::IInclinometerStatics;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IInclinometerStatics<D>;
};

template <> struct traits<Windows::Devices::Sensors::IInclinometerStatics2>
{
    using abi = ABI::Windows::Devices::Sensors::IInclinometerStatics2;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IInclinometerStatics2<D>;
};

template <> struct traits<Windows::Devices::Sensors::IInclinometerStatics3>
{
    using abi = ABI::Windows::Devices::Sensors::IInclinometerStatics3;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IInclinometerStatics3<D>;
};

template <> struct traits<Windows::Devices::Sensors::ILightSensor>
{
    using abi = ABI::Windows::Devices::Sensors::ILightSensor;
    template <typename D> using consume = Windows::Devices::Sensors::impl_ILightSensor<D>;
};

template <> struct traits<Windows::Devices::Sensors::ILightSensorDeviceId>
{
    using abi = ABI::Windows::Devices::Sensors::ILightSensorDeviceId;
    template <typename D> using consume = Windows::Devices::Sensors::impl_ILightSensorDeviceId<D>;
};

template <> struct traits<Windows::Devices::Sensors::ILightSensorReading>
{
    using abi = ABI::Windows::Devices::Sensors::ILightSensorReading;
    template <typename D> using consume = Windows::Devices::Sensors::impl_ILightSensorReading<D>;
};

template <> struct traits<Windows::Devices::Sensors::ILightSensorReadingChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Sensors::ILightSensorReadingChangedEventArgs;
    template <typename D> using consume = Windows::Devices::Sensors::impl_ILightSensorReadingChangedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Sensors::ILightSensorStatics>
{
    using abi = ABI::Windows::Devices::Sensors::ILightSensorStatics;
    template <typename D> using consume = Windows::Devices::Sensors::impl_ILightSensorStatics<D>;
};

template <> struct traits<Windows::Devices::Sensors::IMagnetometer>
{
    using abi = ABI::Windows::Devices::Sensors::IMagnetometer;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IMagnetometer<D>;
};

template <> struct traits<Windows::Devices::Sensors::IMagnetometer2>
{
    using abi = ABI::Windows::Devices::Sensors::IMagnetometer2;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IMagnetometer2<D>;
};

template <> struct traits<Windows::Devices::Sensors::IMagnetometerDeviceId>
{
    using abi = ABI::Windows::Devices::Sensors::IMagnetometerDeviceId;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IMagnetometerDeviceId<D>;
};

template <> struct traits<Windows::Devices::Sensors::IMagnetometerReading>
{
    using abi = ABI::Windows::Devices::Sensors::IMagnetometerReading;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IMagnetometerReading<D>;
};

template <> struct traits<Windows::Devices::Sensors::IMagnetometerReadingChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Sensors::IMagnetometerReadingChangedEventArgs;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IMagnetometerReadingChangedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Sensors::IMagnetometerStatics>
{
    using abi = ABI::Windows::Devices::Sensors::IMagnetometerStatics;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IMagnetometerStatics<D>;
};

template <> struct traits<Windows::Devices::Sensors::IOrientationSensor>
{
    using abi = ABI::Windows::Devices::Sensors::IOrientationSensor;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IOrientationSensor<D>;
};

template <> struct traits<Windows::Devices::Sensors::IOrientationSensor2>
{
    using abi = ABI::Windows::Devices::Sensors::IOrientationSensor2;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IOrientationSensor2<D>;
};

template <> struct traits<Windows::Devices::Sensors::IOrientationSensorDeviceId>
{
    using abi = ABI::Windows::Devices::Sensors::IOrientationSensorDeviceId;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IOrientationSensorDeviceId<D>;
};

template <> struct traits<Windows::Devices::Sensors::IOrientationSensorReading>
{
    using abi = ABI::Windows::Devices::Sensors::IOrientationSensorReading;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IOrientationSensorReading<D>;
};

template <> struct traits<Windows::Devices::Sensors::IOrientationSensorReadingChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Sensors::IOrientationSensorReadingChangedEventArgs;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IOrientationSensorReadingChangedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Sensors::IOrientationSensorReadingYawAccuracy>
{
    using abi = ABI::Windows::Devices::Sensors::IOrientationSensorReadingYawAccuracy;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IOrientationSensorReadingYawAccuracy<D>;
};

template <> struct traits<Windows::Devices::Sensors::IOrientationSensorStatics>
{
    using abi = ABI::Windows::Devices::Sensors::IOrientationSensorStatics;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IOrientationSensorStatics<D>;
};

template <> struct traits<Windows::Devices::Sensors::IOrientationSensorStatics2>
{
    using abi = ABI::Windows::Devices::Sensors::IOrientationSensorStatics2;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IOrientationSensorStatics2<D>;
};

template <> struct traits<Windows::Devices::Sensors::IOrientationSensorStatics3>
{
    using abi = ABI::Windows::Devices::Sensors::IOrientationSensorStatics3;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IOrientationSensorStatics3<D>;
};

template <> struct traits<Windows::Devices::Sensors::IPedometer>
{
    using abi = ABI::Windows::Devices::Sensors::IPedometer;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IPedometer<D>;
};

template <> struct traits<Windows::Devices::Sensors::IPedometer2>
{
    using abi = ABI::Windows::Devices::Sensors::IPedometer2;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IPedometer2<D>;
};

template <> struct traits<Windows::Devices::Sensors::IPedometerDataThresholdFactory>
{
    using abi = ABI::Windows::Devices::Sensors::IPedometerDataThresholdFactory;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IPedometerDataThresholdFactory<D>;
};

template <> struct traits<Windows::Devices::Sensors::IPedometerReading>
{
    using abi = ABI::Windows::Devices::Sensors::IPedometerReading;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IPedometerReading<D>;
};

template <> struct traits<Windows::Devices::Sensors::IPedometerReadingChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Sensors::IPedometerReadingChangedEventArgs;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IPedometerReadingChangedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Sensors::IPedometerStatics>
{
    using abi = ABI::Windows::Devices::Sensors::IPedometerStatics;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IPedometerStatics<D>;
};

template <> struct traits<Windows::Devices::Sensors::IPedometerStatics2>
{
    using abi = ABI::Windows::Devices::Sensors::IPedometerStatics2;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IPedometerStatics2<D>;
};

template <> struct traits<Windows::Devices::Sensors::IProximitySensor>
{
    using abi = ABI::Windows::Devices::Sensors::IProximitySensor;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IProximitySensor<D>;
};

template <> struct traits<Windows::Devices::Sensors::IProximitySensorDataThresholdFactory>
{
    using abi = ABI::Windows::Devices::Sensors::IProximitySensorDataThresholdFactory;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IProximitySensorDataThresholdFactory<D>;
};

template <> struct traits<Windows::Devices::Sensors::IProximitySensorReading>
{
    using abi = ABI::Windows::Devices::Sensors::IProximitySensorReading;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IProximitySensorReading<D>;
};

template <> struct traits<Windows::Devices::Sensors::IProximitySensorReadingChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Sensors::IProximitySensorReadingChangedEventArgs;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IProximitySensorReadingChangedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Sensors::IProximitySensorStatics>
{
    using abi = ABI::Windows::Devices::Sensors::IProximitySensorStatics;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IProximitySensorStatics<D>;
};

template <> struct traits<Windows::Devices::Sensors::IProximitySensorStatics2>
{
    using abi = ABI::Windows::Devices::Sensors::IProximitySensorStatics2;
    template <typename D> using consume = Windows::Devices::Sensors::impl_IProximitySensorStatics2<D>;
};

template <> struct traits<Windows::Devices::Sensors::ISensorDataThreshold>
{
    using abi = ABI::Windows::Devices::Sensors::ISensorDataThreshold;
    template <typename D> using consume = Windows::Devices::Sensors::impl_ISensorDataThreshold<D>;
};

template <> struct traits<Windows::Devices::Sensors::ISensorDataThresholdTriggerDetails>
{
    using abi = ABI::Windows::Devices::Sensors::ISensorDataThresholdTriggerDetails;
    template <typename D> using consume = Windows::Devices::Sensors::impl_ISensorDataThresholdTriggerDetails<D>;
};

template <> struct traits<Windows::Devices::Sensors::ISensorQuaternion>
{
    using abi = ABI::Windows::Devices::Sensors::ISensorQuaternion;
    template <typename D> using consume = Windows::Devices::Sensors::impl_ISensorQuaternion<D>;
};

template <> struct traits<Windows::Devices::Sensors::ISensorRotationMatrix>
{
    using abi = ABI::Windows::Devices::Sensors::ISensorRotationMatrix;
    template <typename D> using consume = Windows::Devices::Sensors::impl_ISensorRotationMatrix<D>;
};

template <> struct traits<Windows::Devices::Sensors::ISimpleOrientationSensor>
{
    using abi = ABI::Windows::Devices::Sensors::ISimpleOrientationSensor;
    template <typename D> using consume = Windows::Devices::Sensors::impl_ISimpleOrientationSensor<D>;
};

template <> struct traits<Windows::Devices::Sensors::ISimpleOrientationSensor2>
{
    using abi = ABI::Windows::Devices::Sensors::ISimpleOrientationSensor2;
    template <typename D> using consume = Windows::Devices::Sensors::impl_ISimpleOrientationSensor2<D>;
};

template <> struct traits<Windows::Devices::Sensors::ISimpleOrientationSensorDeviceId>
{
    using abi = ABI::Windows::Devices::Sensors::ISimpleOrientationSensorDeviceId;
    template <typename D> using consume = Windows::Devices::Sensors::impl_ISimpleOrientationSensorDeviceId<D>;
};

template <> struct traits<Windows::Devices::Sensors::ISimpleOrientationSensorOrientationChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Sensors::ISimpleOrientationSensorOrientationChangedEventArgs;
    template <typename D> using consume = Windows::Devices::Sensors::impl_ISimpleOrientationSensorOrientationChangedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Sensors::ISimpleOrientationSensorStatics>
{
    using abi = ABI::Windows::Devices::Sensors::ISimpleOrientationSensorStatics;
    template <typename D> using consume = Windows::Devices::Sensors::impl_ISimpleOrientationSensorStatics<D>;
};

template <> struct traits<Windows::Devices::Sensors::Accelerometer>
{
    using abi = ABI::Windows::Devices::Sensors::Accelerometer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.Accelerometer"; }
};

template <> struct traits<Windows::Devices::Sensors::AccelerometerReading>
{
    using abi = ABI::Windows::Devices::Sensors::AccelerometerReading;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.AccelerometerReading"; }
};

template <> struct traits<Windows::Devices::Sensors::AccelerometerReadingChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Sensors::AccelerometerReadingChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.AccelerometerReadingChangedEventArgs"; }
};

template <> struct traits<Windows::Devices::Sensors::AccelerometerShakenEventArgs>
{
    using abi = ABI::Windows::Devices::Sensors::AccelerometerShakenEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.AccelerometerShakenEventArgs"; }
};

template <> struct traits<Windows::Devices::Sensors::ActivitySensor>
{
    using abi = ABI::Windows::Devices::Sensors::ActivitySensor;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.ActivitySensor"; }
};

template <> struct traits<Windows::Devices::Sensors::ActivitySensorReading>
{
    using abi = ABI::Windows::Devices::Sensors::ActivitySensorReading;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.ActivitySensorReading"; }
};

template <> struct traits<Windows::Devices::Sensors::ActivitySensorReadingChangeReport>
{
    using abi = ABI::Windows::Devices::Sensors::ActivitySensorReadingChangeReport;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.ActivitySensorReadingChangeReport"; }
};

template <> struct traits<Windows::Devices::Sensors::ActivitySensorReadingChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Sensors::ActivitySensorReadingChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.ActivitySensorReadingChangedEventArgs"; }
};

template <> struct traits<Windows::Devices::Sensors::ActivitySensorTriggerDetails>
{
    using abi = ABI::Windows::Devices::Sensors::ActivitySensorTriggerDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.ActivitySensorTriggerDetails"; }
};

template <> struct traits<Windows::Devices::Sensors::Altimeter>
{
    using abi = ABI::Windows::Devices::Sensors::Altimeter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.Altimeter"; }
};

template <> struct traits<Windows::Devices::Sensors::AltimeterReading>
{
    using abi = ABI::Windows::Devices::Sensors::AltimeterReading;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.AltimeterReading"; }
};

template <> struct traits<Windows::Devices::Sensors::AltimeterReadingChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Sensors::AltimeterReadingChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.AltimeterReadingChangedEventArgs"; }
};

template <> struct traits<Windows::Devices::Sensors::Barometer>
{
    using abi = ABI::Windows::Devices::Sensors::Barometer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.Barometer"; }
};

template <> struct traits<Windows::Devices::Sensors::BarometerReading>
{
    using abi = ABI::Windows::Devices::Sensors::BarometerReading;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.BarometerReading"; }
};

template <> struct traits<Windows::Devices::Sensors::BarometerReadingChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Sensors::BarometerReadingChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.BarometerReadingChangedEventArgs"; }
};

template <> struct traits<Windows::Devices::Sensors::Compass>
{
    using abi = ABI::Windows::Devices::Sensors::Compass;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.Compass"; }
};

template <> struct traits<Windows::Devices::Sensors::CompassReading>
{
    using abi = ABI::Windows::Devices::Sensors::CompassReading;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.CompassReading"; }
};

template <> struct traits<Windows::Devices::Sensors::CompassReadingChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Sensors::CompassReadingChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.CompassReadingChangedEventArgs"; }
};

template <> struct traits<Windows::Devices::Sensors::Gyrometer>
{
    using abi = ABI::Windows::Devices::Sensors::Gyrometer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.Gyrometer"; }
};

template <> struct traits<Windows::Devices::Sensors::GyrometerReading>
{
    using abi = ABI::Windows::Devices::Sensors::GyrometerReading;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.GyrometerReading"; }
};

template <> struct traits<Windows::Devices::Sensors::GyrometerReadingChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Sensors::GyrometerReadingChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.GyrometerReadingChangedEventArgs"; }
};

template <> struct traits<Windows::Devices::Sensors::Inclinometer>
{
    using abi = ABI::Windows::Devices::Sensors::Inclinometer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.Inclinometer"; }
};

template <> struct traits<Windows::Devices::Sensors::InclinometerReading>
{
    using abi = ABI::Windows::Devices::Sensors::InclinometerReading;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.InclinometerReading"; }
};

template <> struct traits<Windows::Devices::Sensors::InclinometerReadingChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Sensors::InclinometerReadingChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.InclinometerReadingChangedEventArgs"; }
};

template <> struct traits<Windows::Devices::Sensors::LightSensor>
{
    using abi = ABI::Windows::Devices::Sensors::LightSensor;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.LightSensor"; }
};

template <> struct traits<Windows::Devices::Sensors::LightSensorReading>
{
    using abi = ABI::Windows::Devices::Sensors::LightSensorReading;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.LightSensorReading"; }
};

template <> struct traits<Windows::Devices::Sensors::LightSensorReadingChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Sensors::LightSensorReadingChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.LightSensorReadingChangedEventArgs"; }
};

template <> struct traits<Windows::Devices::Sensors::Magnetometer>
{
    using abi = ABI::Windows::Devices::Sensors::Magnetometer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.Magnetometer"; }
};

template <> struct traits<Windows::Devices::Sensors::MagnetometerReading>
{
    using abi = ABI::Windows::Devices::Sensors::MagnetometerReading;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.MagnetometerReading"; }
};

template <> struct traits<Windows::Devices::Sensors::MagnetometerReadingChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Sensors::MagnetometerReadingChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.MagnetometerReadingChangedEventArgs"; }
};

template <> struct traits<Windows::Devices::Sensors::OrientationSensor>
{
    using abi = ABI::Windows::Devices::Sensors::OrientationSensor;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.OrientationSensor"; }
};

template <> struct traits<Windows::Devices::Sensors::OrientationSensorReading>
{
    using abi = ABI::Windows::Devices::Sensors::OrientationSensorReading;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.OrientationSensorReading"; }
};

template <> struct traits<Windows::Devices::Sensors::OrientationSensorReadingChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Sensors::OrientationSensorReadingChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.OrientationSensorReadingChangedEventArgs"; }
};

template <> struct traits<Windows::Devices::Sensors::Pedometer>
{
    using abi = ABI::Windows::Devices::Sensors::Pedometer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.Pedometer"; }
};

template <> struct traits<Windows::Devices::Sensors::PedometerDataThreshold>
{
    using abi = ABI::Windows::Devices::Sensors::PedometerDataThreshold;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.PedometerDataThreshold"; }
};

template <> struct traits<Windows::Devices::Sensors::PedometerReading>
{
    using abi = ABI::Windows::Devices::Sensors::PedometerReading;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.PedometerReading"; }
};

template <> struct traits<Windows::Devices::Sensors::PedometerReadingChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Sensors::PedometerReadingChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.PedometerReadingChangedEventArgs"; }
};

template <> struct traits<Windows::Devices::Sensors::ProximitySensor>
{
    using abi = ABI::Windows::Devices::Sensors::ProximitySensor;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.ProximitySensor"; }
};

template <> struct traits<Windows::Devices::Sensors::ProximitySensorDataThreshold>
{
    using abi = ABI::Windows::Devices::Sensors::ProximitySensorDataThreshold;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.ProximitySensorDataThreshold"; }
};

template <> struct traits<Windows::Devices::Sensors::ProximitySensorDisplayOnOffController>
{
    using abi = ABI::Windows::Devices::Sensors::ProximitySensorDisplayOnOffController;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.ProximitySensorDisplayOnOffController"; }
};

template <> struct traits<Windows::Devices::Sensors::ProximitySensorReading>
{
    using abi = ABI::Windows::Devices::Sensors::ProximitySensorReading;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.ProximitySensorReading"; }
};

template <> struct traits<Windows::Devices::Sensors::ProximitySensorReadingChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Sensors::ProximitySensorReadingChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.ProximitySensorReadingChangedEventArgs"; }
};

template <> struct traits<Windows::Devices::Sensors::SensorDataThresholdTriggerDetails>
{
    using abi = ABI::Windows::Devices::Sensors::SensorDataThresholdTriggerDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.SensorDataThresholdTriggerDetails"; }
};

template <> struct traits<Windows::Devices::Sensors::SensorQuaternion>
{
    using abi = ABI::Windows::Devices::Sensors::SensorQuaternion;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.SensorQuaternion"; }
};

template <> struct traits<Windows::Devices::Sensors::SensorRotationMatrix>
{
    using abi = ABI::Windows::Devices::Sensors::SensorRotationMatrix;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.SensorRotationMatrix"; }
};

template <> struct traits<Windows::Devices::Sensors::SimpleOrientationSensor>
{
    using abi = ABI::Windows::Devices::Sensors::SimpleOrientationSensor;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.SimpleOrientationSensor"; }
};

template <> struct traits<Windows::Devices::Sensors::SimpleOrientationSensorOrientationChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Sensors::SimpleOrientationSensorOrientationChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sensors.SimpleOrientationSensorOrientationChangedEventArgs"; }
};

}

}
