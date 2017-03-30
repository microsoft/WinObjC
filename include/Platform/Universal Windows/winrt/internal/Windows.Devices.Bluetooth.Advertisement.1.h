// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Devices.Bluetooth.Advertisement.0.h"
#include "Windows.Devices.Bluetooth.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Bluetooth::Advertisement {

struct __declspec(uuid("066fb2b7-33d1-4e7d-8367-cf81d0f79653")) __declspec(novtable) IBluetoothLEAdvertisement : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Flags(Windows::Foundation::IReference<winrt::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFlags> ** value) = 0;
    virtual HRESULT __stdcall put_Flags(Windows::Foundation::IReference<winrt::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFlags> * value) = 0;
    virtual HRESULT __stdcall get_LocalName(hstring * value) = 0;
    virtual HRESULT __stdcall put_LocalName(hstring value) = 0;
    virtual HRESULT __stdcall get_ServiceUuids(Windows::Foundation::Collections::IVector<GUID> ** value) = 0;
    virtual HRESULT __stdcall get_ManufacturerData(Windows::Foundation::Collections::IVector<Windows::Devices::Bluetooth::Advertisement::BluetoothLEManufacturerData> ** value) = 0;
    virtual HRESULT __stdcall get_DataSections(Windows::Foundation::Collections::IVector<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataSection> ** value) = 0;
    virtual HRESULT __stdcall abi_GetManufacturerDataByCompanyId(uint16_t companyId, Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::Advertisement::BluetoothLEManufacturerData> ** dataList) = 0;
    virtual HRESULT __stdcall abi_GetSectionsByType(uint8_t type, Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataSection> ** sectionList) = 0;
};

struct __declspec(uuid("fbfad7f2-b9c5-4a08-bc51-502f8ef68a79")) __declspec(novtable) IBluetoothLEAdvertisementBytePattern : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DataType(uint8_t * value) = 0;
    virtual HRESULT __stdcall put_DataType(uint8_t value) = 0;
    virtual HRESULT __stdcall get_Offset(int16_t * value) = 0;
    virtual HRESULT __stdcall put_Offset(int16_t value) = 0;
    virtual HRESULT __stdcall get_Data(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall put_Data(Windows::Storage::Streams::IBuffer * value) = 0;
};

struct __declspec(uuid("c2e24d73-fd5c-4ec3-be2a-9ca6fa11b7bd")) __declspec(novtable) IBluetoothLEAdvertisementBytePatternFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(uint8_t dataType, int16_t offset, Windows::Storage::Streams::IBuffer * data, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePattern ** value) = 0;
};

struct __declspec(uuid("d7213314-3a43-40f9-b6f0-92bfefc34ae3")) __declspec(novtable) IBluetoothLEAdvertisementDataSection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DataType(uint8_t * value) = 0;
    virtual HRESULT __stdcall put_DataType(uint8_t value) = 0;
    virtual HRESULT __stdcall get_Data(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall put_Data(Windows::Storage::Streams::IBuffer * value) = 0;
};

struct __declspec(uuid("e7a40942-a845-4045-bf7e-3e9971db8a6b")) __declspec(novtable) IBluetoothLEAdvertisementDataSectionFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(uint8_t dataType, Windows::Storage::Streams::IBuffer * data, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSection ** value) = 0;
};

struct __declspec(uuid("3bb6472f-0606-434b-a76e-74159f0684d3")) __declspec(novtable) IBluetoothLEAdvertisementDataTypesStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Flags(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_IncompleteService16BitUuids(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_CompleteService16BitUuids(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_IncompleteService32BitUuids(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_CompleteService32BitUuids(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_IncompleteService128BitUuids(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_CompleteService128BitUuids(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_ShortenedLocalName(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_CompleteLocalName(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_TxPowerLevel(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_SlaveConnectionIntervalRange(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_ServiceSolicitation16BitUuids(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_ServiceSolicitation32BitUuids(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_ServiceSolicitation128BitUuids(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_ServiceData16BitUuids(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_ServiceData32BitUuids(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_ServiceData128BitUuids(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_PublicTargetAddress(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_RandomTargetAddress(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_Appearance(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_AdvertisingInterval(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_ManufacturerSpecificData(uint8_t * value) = 0;
};

struct __declspec(uuid("131eb0d3-d04e-47b1-837e-49405bf6f80f")) __declspec(novtable) IBluetoothLEAdvertisementFilter : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Advertisement(Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement ** value) = 0;
    virtual HRESULT __stdcall put_Advertisement(Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement * value) = 0;
    virtual HRESULT __stdcall get_BytePatterns(Windows::Foundation::Collections::IVector<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementBytePattern> ** value) = 0;
};

struct __declspec(uuid("cde820f9-d9fa-43d6-a264-ddd8b7da8b78")) __declspec(novtable) IBluetoothLEAdvertisementPublisher : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(winrt::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatus * value) = 0;
    virtual HRESULT __stdcall get_Advertisement(Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement ** value) = 0;
    virtual HRESULT __stdcall abi_Start() = 0;
    virtual HRESULT __stdcall abi_Stop() = 0;
    virtual HRESULT __stdcall add_StatusChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisher, Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatusChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_StatusChanged(event_token token) = 0;
};

struct __declspec(uuid("5c5f065e-b863-4981-a1af-1c544d8b0c0d")) __declspec(novtable) IBluetoothLEAdvertisementPublisherFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement * advertisement, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher ** value) = 0;
};

struct __declspec(uuid("09c2bd9f-2dff-4b23-86ee-0d14fb94aeae")) __declspec(novtable) IBluetoothLEAdvertisementPublisherStatusChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(winrt::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatus * value) = 0;
    virtual HRESULT __stdcall get_Error(winrt::Windows::Devices::Bluetooth::BluetoothError * value) = 0;
};

struct __declspec(uuid("27987ddf-e596-41be-8d43-9e6731d4a913")) __declspec(novtable) IBluetoothLEAdvertisementReceivedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RawSignalStrengthInDBm(int16_t * value) = 0;
    virtual HRESULT __stdcall get_BluetoothAddress(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_AdvertisementType(winrt::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementType * value) = 0;
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_Advertisement(Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement ** value) = 0;
};

struct __declspec(uuid("a6ac336f-f3d3-4297-8d6c-c81ea6623f40")) __declspec(novtable) IBluetoothLEAdvertisementWatcher : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MinSamplingInterval(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_MaxSamplingInterval(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_MinOutOfRangeTimeout(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_MaxOutOfRangeTimeout(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_Status(winrt::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcherStatus * value) = 0;
    virtual HRESULT __stdcall get_ScanningMode(winrt::Windows::Devices::Bluetooth::Advertisement::BluetoothLEScanningMode * value) = 0;
    virtual HRESULT __stdcall put_ScanningMode(winrt::Windows::Devices::Bluetooth::Advertisement::BluetoothLEScanningMode value) = 0;
    virtual HRESULT __stdcall get_SignalStrengthFilter(Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter ** value) = 0;
    virtual HRESULT __stdcall put_SignalStrengthFilter(Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter * value) = 0;
    virtual HRESULT __stdcall get_AdvertisementFilter(Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter ** value) = 0;
    virtual HRESULT __stdcall put_AdvertisementFilter(Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter * value) = 0;
    virtual HRESULT __stdcall abi_Start() = 0;
    virtual HRESULT __stdcall abi_Stop() = 0;
    virtual HRESULT __stdcall add_Received(Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher, Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Received(event_token token) = 0;
    virtual HRESULT __stdcall add_Stopped(Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher, Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcherStoppedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Stopped(event_token token) = 0;
};

struct __declspec(uuid("9aaf2d56-39ac-453e-b32a-85c657e017f1")) __declspec(novtable) IBluetoothLEAdvertisementWatcherFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter * advertisementFilter, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher ** value) = 0;
};

struct __declspec(uuid("dd40f84d-e7b9-43e3-9c04-0685d085fd8c")) __declspec(novtable) IBluetoothLEAdvertisementWatcherStoppedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Error(winrt::Windows::Devices::Bluetooth::BluetoothError * value) = 0;
};

struct __declspec(uuid("912dba18-6963-4533-b061-4694dafb34e5")) __declspec(novtable) IBluetoothLEManufacturerData : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CompanyId(uint16_t * value) = 0;
    virtual HRESULT __stdcall put_CompanyId(uint16_t value) = 0;
    virtual HRESULT __stdcall get_Data(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall put_Data(Windows::Storage::Streams::IBuffer * value) = 0;
};

struct __declspec(uuid("c09b39f8-319a-441e-8de5-66a81e877a6c")) __declspec(novtable) IBluetoothLEManufacturerDataFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(uint16_t companyId, Windows::Storage::Streams::IBuffer * data, Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerData ** value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement> { using default_interface = Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement; };
template <> struct traits<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementBytePattern> { using default_interface = Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePattern; };
template <> struct traits<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataSection> { using default_interface = Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSection; };
template <> struct traits<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter> { using default_interface = Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter; };
template <> struct traits<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisher> { using default_interface = Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher; };
template <> struct traits<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatusChangedEventArgs> { using default_interface = Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherStatusChangedEventArgs; };
template <> struct traits<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs> { using default_interface = Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementReceivedEventArgs; };
template <> struct traits<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher> { using default_interface = Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher; };
template <> struct traits<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcherStoppedEventArgs> { using default_interface = Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcherStoppedEventArgs; };
template <> struct traits<Windows::Devices::Bluetooth::Advertisement::BluetoothLEManufacturerData> { using default_interface = Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerData; };

}

namespace Windows::Devices::Bluetooth::Advertisement {

template <typename D>
struct WINRT_EBO impl_IBluetoothLEAdvertisement
{
    Windows::Foundation::IReference<winrt::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFlags> Flags() const;
    void Flags(const optional<winrt::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFlags> & value) const;
    hstring LocalName() const;
    void LocalName(hstring_view value) const;
    Windows::Foundation::Collections::IVector<GUID> ServiceUuids() const;
    Windows::Foundation::Collections::IVector<Windows::Devices::Bluetooth::Advertisement::BluetoothLEManufacturerData> ManufacturerData() const;
    Windows::Foundation::Collections::IVector<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataSection> DataSections() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::Advertisement::BluetoothLEManufacturerData> GetManufacturerDataByCompanyId(uint16_t companyId) const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataSection> GetSectionsByType(uint8_t type) const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothLEAdvertisementBytePattern
{
    uint8_t DataType() const;
    void DataType(uint8_t value) const;
    int16_t Offset() const;
    void Offset(int16_t value) const;
    Windows::Storage::Streams::IBuffer Data() const;
    void Data(const Windows::Storage::Streams::IBuffer & value) const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothLEAdvertisementBytePatternFactory
{
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementBytePattern Create(uint8_t dataType, int16_t offset, const Windows::Storage::Streams::IBuffer & data) const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothLEAdvertisementDataSection
{
    uint8_t DataType() const;
    void DataType(uint8_t value) const;
    Windows::Storage::Streams::IBuffer Data() const;
    void Data(const Windows::Storage::Streams::IBuffer & value) const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothLEAdvertisementDataSectionFactory
{
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataSection Create(uint8_t dataType, const Windows::Storage::Streams::IBuffer & data) const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothLEAdvertisementDataTypesStatics
{
    uint8_t Flags() const;
    uint8_t IncompleteService16BitUuids() const;
    uint8_t CompleteService16BitUuids() const;
    uint8_t IncompleteService32BitUuids() const;
    uint8_t CompleteService32BitUuids() const;
    uint8_t IncompleteService128BitUuids() const;
    uint8_t CompleteService128BitUuids() const;
    uint8_t ShortenedLocalName() const;
    uint8_t CompleteLocalName() const;
    uint8_t TxPowerLevel() const;
    uint8_t SlaveConnectionIntervalRange() const;
    uint8_t ServiceSolicitation16BitUuids() const;
    uint8_t ServiceSolicitation32BitUuids() const;
    uint8_t ServiceSolicitation128BitUuids() const;
    uint8_t ServiceData16BitUuids() const;
    uint8_t ServiceData32BitUuids() const;
    uint8_t ServiceData128BitUuids() const;
    uint8_t PublicTargetAddress() const;
    uint8_t RandomTargetAddress() const;
    uint8_t Appearance() const;
    uint8_t AdvertisingInterval() const;
    uint8_t ManufacturerSpecificData() const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothLEAdvertisementFilter
{
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement Advertisement() const;
    void Advertisement(const Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement & value) const;
    Windows::Foundation::Collections::IVector<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementBytePattern> BytePatterns() const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothLEAdvertisementPublisher
{
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatus Status() const;
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement Advertisement() const;
    void Start() const;
    void Stop() const;
    event_token StatusChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisher, Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatusChangedEventArgs> & handler) const;
    using StatusChanged_revoker = event_revoker<IBluetoothLEAdvertisementPublisher>;
    StatusChanged_revoker StatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisher, Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatusChangedEventArgs> & handler) const;
    void StatusChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothLEAdvertisementPublisherFactory
{
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisher Create(const Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement & advertisement) const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothLEAdvertisementPublisherStatusChangedEventArgs
{
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatus Status() const;
    Windows::Devices::Bluetooth::BluetoothError Error() const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothLEAdvertisementReceivedEventArgs
{
    int16_t RawSignalStrengthInDBm() const;
    uint64_t BluetoothAddress() const;
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementType AdvertisementType() const;
    Windows::Foundation::DateTime Timestamp() const;
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement Advertisement() const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothLEAdvertisementWatcher
{
    Windows::Foundation::TimeSpan MinSamplingInterval() const;
    Windows::Foundation::TimeSpan MaxSamplingInterval() const;
    Windows::Foundation::TimeSpan MinOutOfRangeTimeout() const;
    Windows::Foundation::TimeSpan MaxOutOfRangeTimeout() const;
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcherStatus Status() const;
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEScanningMode ScanningMode() const;
    void ScanningMode(Windows::Devices::Bluetooth::Advertisement::BluetoothLEScanningMode value) const;
    Windows::Devices::Bluetooth::BluetoothSignalStrengthFilter SignalStrengthFilter() const;
    void SignalStrengthFilter(const Windows::Devices::Bluetooth::BluetoothSignalStrengthFilter & value) const;
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter AdvertisementFilter() const;
    void AdvertisementFilter(const Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter & value) const;
    void Start() const;
    void Stop() const;
    event_token Received(const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher, Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs> & handler) const;
    using Received_revoker = event_revoker<IBluetoothLEAdvertisementWatcher>;
    Received_revoker Received(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher, Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs> & handler) const;
    void Received(event_token token) const;
    event_token Stopped(const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher, Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcherStoppedEventArgs> & handler) const;
    using Stopped_revoker = event_revoker<IBluetoothLEAdvertisementWatcher>;
    Stopped_revoker Stopped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher, Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcherStoppedEventArgs> & handler) const;
    void Stopped(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothLEAdvertisementWatcherFactory
{
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher Create(const Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter & advertisementFilter) const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothLEAdvertisementWatcherStoppedEventArgs
{
    Windows::Devices::Bluetooth::BluetoothError Error() const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothLEManufacturerData
{
    uint16_t CompanyId() const;
    void CompanyId(uint16_t value) const;
    Windows::Storage::Streams::IBuffer Data() const;
    void Data(const Windows::Storage::Streams::IBuffer & value) const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothLEManufacturerDataFactory
{
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEManufacturerData Create(uint16_t companyId, const Windows::Storage::Streams::IBuffer & data) const;
};

}

namespace impl {

template <> struct traits<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement>
{
    using abi = ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement;
    template <typename D> using consume = Windows::Devices::Bluetooth::Advertisement::impl_IBluetoothLEAdvertisement<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePattern>
{
    using abi = ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePattern;
    template <typename D> using consume = Windows::Devices::Bluetooth::Advertisement::impl_IBluetoothLEAdvertisementBytePattern<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePatternFactory>
{
    using abi = ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePatternFactory;
    template <typename D> using consume = Windows::Devices::Bluetooth::Advertisement::impl_IBluetoothLEAdvertisementBytePatternFactory<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSection>
{
    using abi = ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSection;
    template <typename D> using consume = Windows::Devices::Bluetooth::Advertisement::impl_IBluetoothLEAdvertisementDataSection<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSectionFactory>
{
    using abi = ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSectionFactory;
    template <typename D> using consume = Windows::Devices::Bluetooth::Advertisement::impl_IBluetoothLEAdvertisementDataSectionFactory<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataTypesStatics>
{
    using abi = ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataTypesStatics;
    template <typename D> using consume = Windows::Devices::Bluetooth::Advertisement::impl_IBluetoothLEAdvertisementDataTypesStatics<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter>
{
    using abi = ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter;
    template <typename D> using consume = Windows::Devices::Bluetooth::Advertisement::impl_IBluetoothLEAdvertisementFilter<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher>
{
    using abi = ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher;
    template <typename D> using consume = Windows::Devices::Bluetooth::Advertisement::impl_IBluetoothLEAdvertisementPublisher<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherFactory>
{
    using abi = ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherFactory;
    template <typename D> using consume = Windows::Devices::Bluetooth::Advertisement::impl_IBluetoothLEAdvertisementPublisherFactory<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherStatusChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherStatusChangedEventArgs;
    template <typename D> using consume = Windows::Devices::Bluetooth::Advertisement::impl_IBluetoothLEAdvertisementPublisherStatusChangedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementReceivedEventArgs>
{
    using abi = ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementReceivedEventArgs;
    template <typename D> using consume = Windows::Devices::Bluetooth::Advertisement::impl_IBluetoothLEAdvertisementReceivedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher>
{
    using abi = ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher;
    template <typename D> using consume = Windows::Devices::Bluetooth::Advertisement::impl_IBluetoothLEAdvertisementWatcher<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcherFactory>
{
    using abi = ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcherFactory;
    template <typename D> using consume = Windows::Devices::Bluetooth::Advertisement::impl_IBluetoothLEAdvertisementWatcherFactory<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcherStoppedEventArgs>
{
    using abi = ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcherStoppedEventArgs;
    template <typename D> using consume = Windows::Devices::Bluetooth::Advertisement::impl_IBluetoothLEAdvertisementWatcherStoppedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerData>
{
    using abi = ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerData;
    template <typename D> using consume = Windows::Devices::Bluetooth::Advertisement::impl_IBluetoothLEManufacturerData<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerDataFactory>
{
    using abi = ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerDataFactory;
    template <typename D> using consume = Windows::Devices::Bluetooth::Advertisement::impl_IBluetoothLEManufacturerDataFactory<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement>
{
    using abi = ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisement"; }
};

template <> struct traits<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementBytePattern>
{
    using abi = ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementBytePattern;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementBytePattern"; }
};

template <> struct traits<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataSection>
{
    using abi = ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataSection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementDataSection"; }
};

template <> struct traits<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataTypes>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementDataTypes"; }
};

template <> struct traits<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter>
{
    using abi = ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementFilter"; }
};

template <> struct traits<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisher>
{
    using abi = ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisher;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementPublisher"; }
};

template <> struct traits<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatusChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatusChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementPublisherStatusChangedEventArgs"; }
};

template <> struct traits<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs>
{
    using abi = ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementReceivedEventArgs"; }
};

template <> struct traits<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher>
{
    using abi = ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementWatcher"; }
};

template <> struct traits<Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcherStoppedEventArgs>
{
    using abi = ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcherStoppedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementWatcherStoppedEventArgs"; }
};

template <> struct traits<Windows::Devices::Bluetooth::Advertisement::BluetoothLEManufacturerData>
{
    using abi = ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEManufacturerData;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEManufacturerData"; }
};

}

}
