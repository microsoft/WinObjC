// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Devices.HumanInterfaceDevice.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::HumanInterfaceDevice {

struct __declspec(uuid("524df48a-3695-408c-bba2-e2eb5abfbc20")) __declspec(novtable) IHidBooleanControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_UsagePage(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_UsageId(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_IsActive(bool * value) = 0;
    virtual HRESULT __stdcall put_IsActive(bool value) = 0;
    virtual HRESULT __stdcall get_ControlDescription(Windows::Devices::HumanInterfaceDevice::IHidBooleanControlDescription ** value) = 0;
};

struct __declspec(uuid("6196e543-29d8-4a2a-8683-849e207bbe31")) __declspec(novtable) IHidBooleanControlDescription : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_ReportId(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_ReportType(winrt::Windows::Devices::HumanInterfaceDevice::HidReportType * value) = 0;
    virtual HRESULT __stdcall get_UsagePage(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_UsageId(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_ParentCollections(Windows::Foundation::Collections::IVectorView<Windows::Devices::HumanInterfaceDevice::HidCollection> ** value) = 0;
};

struct __declspec(uuid("c8eed2ea-8a77-4c36-aa00-5ff0449d3e73")) __declspec(novtable) IHidBooleanControlDescription2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsAbsolute(bool * value) = 0;
};

struct __declspec(uuid("7189f5a3-32f1-46e3-befd-44d2663b7e6a")) __declspec(novtable) IHidCollection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Type(winrt::Windows::Devices::HumanInterfaceDevice::HidCollectionType * value) = 0;
    virtual HRESULT __stdcall get_UsagePage(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_UsageId(uint32_t * value) = 0;
};

struct __declspec(uuid("5f8a14e7-2200-432e-95da-d09b87d574a8")) __declspec(novtable) IHidDevice : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_VendorId(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_ProductId(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_Version(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_UsagePage(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_UsageId(uint16_t * value) = 0;
    virtual HRESULT __stdcall abi_GetInputReportAsync(Windows::Foundation::IAsyncOperation<Windows::Devices::HumanInterfaceDevice::HidInputReport> ** value) = 0;
    virtual HRESULT __stdcall abi_GetInputReportByIdAsync(uint16_t reportId, Windows::Foundation::IAsyncOperation<Windows::Devices::HumanInterfaceDevice::HidInputReport> ** value) = 0;
    virtual HRESULT __stdcall abi_GetFeatureReportAsync(Windows::Foundation::IAsyncOperation<Windows::Devices::HumanInterfaceDevice::HidFeatureReport> ** value) = 0;
    virtual HRESULT __stdcall abi_GetFeatureReportByIdAsync(uint16_t reportId, Windows::Foundation::IAsyncOperation<Windows::Devices::HumanInterfaceDevice::HidFeatureReport> ** value) = 0;
    virtual HRESULT __stdcall abi_CreateOutputReport(Windows::Devices::HumanInterfaceDevice::IHidOutputReport ** outputReport) = 0;
    virtual HRESULT __stdcall abi_CreateOutputReportById(uint16_t reportId, Windows::Devices::HumanInterfaceDevice::IHidOutputReport ** outputReport) = 0;
    virtual HRESULT __stdcall abi_CreateFeatureReport(Windows::Devices::HumanInterfaceDevice::IHidFeatureReport ** featureReport) = 0;
    virtual HRESULT __stdcall abi_CreateFeatureReportById(uint16_t reportId, Windows::Devices::HumanInterfaceDevice::IHidFeatureReport ** featureReport) = 0;
    virtual HRESULT __stdcall abi_SendOutputReportAsync(Windows::Devices::HumanInterfaceDevice::IHidOutputReport * outputReport, Windows::Foundation::IAsyncOperation<uint32_t> ** operation) = 0;
    virtual HRESULT __stdcall abi_SendFeatureReportAsync(Windows::Devices::HumanInterfaceDevice::IHidFeatureReport * featureReport, Windows::Foundation::IAsyncOperation<uint32_t> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetBooleanControlDescriptions(winrt::Windows::Devices::HumanInterfaceDevice::HidReportType reportType, uint16_t usagePage, uint16_t usageId, Windows::Foundation::Collections::IVectorView<Windows::Devices::HumanInterfaceDevice::HidBooleanControlDescription> ** value) = 0;
    virtual HRESULT __stdcall abi_GetNumericControlDescriptions(winrt::Windows::Devices::HumanInterfaceDevice::HidReportType reportType, uint16_t usagePage, uint16_t usageId, Windows::Foundation::Collections::IVectorView<Windows::Devices::HumanInterfaceDevice::HidNumericControlDescription> ** value) = 0;
    virtual HRESULT __stdcall add_InputReportReceived(Windows::Foundation::TypedEventHandler<Windows::Devices::HumanInterfaceDevice::HidDevice, Windows::Devices::HumanInterfaceDevice::HidInputReportReceivedEventArgs> * reportHandler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_InputReportReceived(event_token token) = 0;
};

struct __declspec(uuid("9e5981e4-9856-418c-9f73-77de0cd85754")) __declspec(novtable) IHidDeviceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeviceSelector(uint16_t usagePage, uint16_t usageId, hstring * selector) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelectorVidPid(uint16_t usagePage, uint16_t usageId, uint16_t vendorId, uint16_t productId, hstring * selector) = 0;
    virtual HRESULT __stdcall abi_FromIdAsync(hstring deviceId, winrt::Windows::Storage::FileAccessMode accessMode, Windows::Foundation::IAsyncOperation<Windows::Devices::HumanInterfaceDevice::HidDevice> ** hidDevice) = 0;
};

struct __declspec(uuid("841d9b79-5ae5-46e3-82ef-1fec5c8942f4")) __declspec(novtable) IHidFeatureReport : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_Data(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall put_Data(Windows::Storage::Streams::IBuffer * value) = 0;
    virtual HRESULT __stdcall abi_GetBooleanControl(uint16_t usagePage, uint16_t usageId, Windows::Devices::HumanInterfaceDevice::IHidBooleanControl ** value) = 0;
    virtual HRESULT __stdcall abi_GetBooleanControlByDescription(Windows::Devices::HumanInterfaceDevice::IHidBooleanControlDescription * controlDescription, Windows::Devices::HumanInterfaceDevice::IHidBooleanControl ** value) = 0;
    virtual HRESULT __stdcall abi_GetNumericControl(uint16_t usagePage, uint16_t usageId, Windows::Devices::HumanInterfaceDevice::IHidNumericControl ** value) = 0;
    virtual HRESULT __stdcall abi_GetNumericControlByDescription(Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription * controlDescription, Windows::Devices::HumanInterfaceDevice::IHidNumericControl ** value) = 0;
};

struct __declspec(uuid("c35d0e50-f7e7-4e8d-b23e-cabbe56b90e9")) __declspec(novtable) IHidInputReport : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_Data(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall get_ActivatedBooleanControls(Windows::Foundation::Collections::IVectorView<Windows::Devices::HumanInterfaceDevice::HidBooleanControl> ** value) = 0;
    virtual HRESULT __stdcall get_TransitionedBooleanControls(Windows::Foundation::Collections::IVectorView<Windows::Devices::HumanInterfaceDevice::HidBooleanControl> ** value) = 0;
    virtual HRESULT __stdcall abi_GetBooleanControl(uint16_t usagePage, uint16_t usageId, Windows::Devices::HumanInterfaceDevice::IHidBooleanControl ** value) = 0;
    virtual HRESULT __stdcall abi_GetBooleanControlByDescription(Windows::Devices::HumanInterfaceDevice::IHidBooleanControlDescription * controlDescription, Windows::Devices::HumanInterfaceDevice::IHidBooleanControl ** value) = 0;
    virtual HRESULT __stdcall abi_GetNumericControl(uint16_t usagePage, uint16_t usageId, Windows::Devices::HumanInterfaceDevice::IHidNumericControl ** value) = 0;
    virtual HRESULT __stdcall abi_GetNumericControlByDescription(Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription * controlDescription, Windows::Devices::HumanInterfaceDevice::IHidNumericControl ** value) = 0;
};

struct __declspec(uuid("7059c5cb-59b2-4dc2-985c-0adc6136fa2d")) __declspec(novtable) IHidInputReportReceivedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Report(Windows::Devices::HumanInterfaceDevice::IHidInputReport ** value) = 0;
};

struct __declspec(uuid("e38a12a5-35a7-4b75-89c8-fb1f28b10823")) __declspec(novtable) IHidNumericControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_IsGrouped(bool * value) = 0;
    virtual HRESULT __stdcall get_UsagePage(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_UsageId(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_Value(int64_t * value) = 0;
    virtual HRESULT __stdcall put_Value(int64_t value) = 0;
    virtual HRESULT __stdcall get_ScaledValue(int64_t * value) = 0;
    virtual HRESULT __stdcall put_ScaledValue(int64_t value) = 0;
    virtual HRESULT __stdcall get_ControlDescription(Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription ** value) = 0;
};

struct __declspec(uuid("638d5e86-1d97-4c75-927f-5ff58ba05e32")) __declspec(novtable) IHidNumericControlDescription : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_ReportId(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_ReportType(winrt::Windows::Devices::HumanInterfaceDevice::HidReportType * value) = 0;
    virtual HRESULT __stdcall get_ReportSize(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_ReportCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_UsagePage(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_UsageId(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_LogicalMinimum(int32_t * value) = 0;
    virtual HRESULT __stdcall get_LogicalMaximum(int32_t * value) = 0;
    virtual HRESULT __stdcall get_PhysicalMinimum(int32_t * value) = 0;
    virtual HRESULT __stdcall get_PhysicalMaximum(int32_t * value) = 0;
    virtual HRESULT __stdcall get_UnitExponent(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Unit(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_IsAbsolute(bool * value) = 0;
    virtual HRESULT __stdcall get_HasNull(bool * value) = 0;
    virtual HRESULT __stdcall get_ParentCollections(Windows::Foundation::Collections::IVectorView<Windows::Devices::HumanInterfaceDevice::HidCollection> ** value) = 0;
};

struct __declspec(uuid("62cb2544-c896-4463-93c1-df9db053c450")) __declspec(novtable) IHidOutputReport : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_Data(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall put_Data(Windows::Storage::Streams::IBuffer * value) = 0;
    virtual HRESULT __stdcall abi_GetBooleanControl(uint16_t usagePage, uint16_t usageId, Windows::Devices::HumanInterfaceDevice::IHidBooleanControl ** value) = 0;
    virtual HRESULT __stdcall abi_GetBooleanControlByDescription(Windows::Devices::HumanInterfaceDevice::IHidBooleanControlDescription * controlDescription, Windows::Devices::HumanInterfaceDevice::IHidBooleanControl ** value) = 0;
    virtual HRESULT __stdcall abi_GetNumericControl(uint16_t usagePage, uint16_t usageId, Windows::Devices::HumanInterfaceDevice::IHidNumericControl ** value) = 0;
    virtual HRESULT __stdcall abi_GetNumericControlByDescription(Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription * controlDescription, Windows::Devices::HumanInterfaceDevice::IHidNumericControl ** value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::HumanInterfaceDevice::HidBooleanControl> { using default_interface = Windows::Devices::HumanInterfaceDevice::IHidBooleanControl; };
template <> struct traits<Windows::Devices::HumanInterfaceDevice::HidBooleanControlDescription> { using default_interface = Windows::Devices::HumanInterfaceDevice::IHidBooleanControlDescription; };
template <> struct traits<Windows::Devices::HumanInterfaceDevice::HidCollection> { using default_interface = Windows::Devices::HumanInterfaceDevice::IHidCollection; };
template <> struct traits<Windows::Devices::HumanInterfaceDevice::HidDevice> { using default_interface = Windows::Devices::HumanInterfaceDevice::IHidDevice; };
template <> struct traits<Windows::Devices::HumanInterfaceDevice::HidFeatureReport> { using default_interface = Windows::Devices::HumanInterfaceDevice::IHidFeatureReport; };
template <> struct traits<Windows::Devices::HumanInterfaceDevice::HidInputReport> { using default_interface = Windows::Devices::HumanInterfaceDevice::IHidInputReport; };
template <> struct traits<Windows::Devices::HumanInterfaceDevice::HidInputReportReceivedEventArgs> { using default_interface = Windows::Devices::HumanInterfaceDevice::IHidInputReportReceivedEventArgs; };
template <> struct traits<Windows::Devices::HumanInterfaceDevice::HidNumericControl> { using default_interface = Windows::Devices::HumanInterfaceDevice::IHidNumericControl; };
template <> struct traits<Windows::Devices::HumanInterfaceDevice::HidNumericControlDescription> { using default_interface = Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription; };
template <> struct traits<Windows::Devices::HumanInterfaceDevice::HidOutputReport> { using default_interface = Windows::Devices::HumanInterfaceDevice::IHidOutputReport; };

}

namespace Windows::Devices::HumanInterfaceDevice {

template <typename D>
struct WINRT_EBO impl_IHidBooleanControl
{
    uint32_t Id() const;
    uint16_t UsagePage() const;
    uint16_t UsageId() const;
    bool IsActive() const;
    void IsActive(bool value) const;
    Windows::Devices::HumanInterfaceDevice::HidBooleanControlDescription ControlDescription() const;
};

template <typename D>
struct WINRT_EBO impl_IHidBooleanControlDescription
{
    uint32_t Id() const;
    uint16_t ReportId() const;
    Windows::Devices::HumanInterfaceDevice::HidReportType ReportType() const;
    uint16_t UsagePage() const;
    uint16_t UsageId() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::HumanInterfaceDevice::HidCollection> ParentCollections() const;
};

template <typename D>
struct WINRT_EBO impl_IHidBooleanControlDescription2
{
    bool IsAbsolute() const;
};

template <typename D>
struct WINRT_EBO impl_IHidCollection
{
    uint32_t Id() const;
    Windows::Devices::HumanInterfaceDevice::HidCollectionType Type() const;
    uint32_t UsagePage() const;
    uint32_t UsageId() const;
};

template <typename D>
struct WINRT_EBO impl_IHidDevice
{
    uint16_t VendorId() const;
    uint16_t ProductId() const;
    uint16_t Version() const;
    uint16_t UsagePage() const;
    uint16_t UsageId() const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::HumanInterfaceDevice::HidInputReport> GetInputReportAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::HumanInterfaceDevice::HidInputReport> GetInputReportAsync(uint16_t reportId) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::HumanInterfaceDevice::HidFeatureReport> GetFeatureReportAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::HumanInterfaceDevice::HidFeatureReport> GetFeatureReportAsync(uint16_t reportId) const;
    Windows::Devices::HumanInterfaceDevice::HidOutputReport CreateOutputReport() const;
    Windows::Devices::HumanInterfaceDevice::HidOutputReport CreateOutputReport(uint16_t reportId) const;
    Windows::Devices::HumanInterfaceDevice::HidFeatureReport CreateFeatureReport() const;
    Windows::Devices::HumanInterfaceDevice::HidFeatureReport CreateFeatureReport(uint16_t reportId) const;
    Windows::Foundation::IAsyncOperation<uint32_t> SendOutputReportAsync(const Windows::Devices::HumanInterfaceDevice::HidOutputReport & outputReport) const;
    Windows::Foundation::IAsyncOperation<uint32_t> SendFeatureReportAsync(const Windows::Devices::HumanInterfaceDevice::HidFeatureReport & featureReport) const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::HumanInterfaceDevice::HidBooleanControlDescription> GetBooleanControlDescriptions(Windows::Devices::HumanInterfaceDevice::HidReportType reportType, uint16_t usagePage, uint16_t usageId) const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::HumanInterfaceDevice::HidNumericControlDescription> GetNumericControlDescriptions(Windows::Devices::HumanInterfaceDevice::HidReportType reportType, uint16_t usagePage, uint16_t usageId) const;
    event_token InputReportReceived(const Windows::Foundation::TypedEventHandler<Windows::Devices::HumanInterfaceDevice::HidDevice, Windows::Devices::HumanInterfaceDevice::HidInputReportReceivedEventArgs> & reportHandler) const;
    using InputReportReceived_revoker = event_revoker<IHidDevice>;
    InputReportReceived_revoker InputReportReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::HumanInterfaceDevice::HidDevice, Windows::Devices::HumanInterfaceDevice::HidInputReportReceivedEventArgs> & reportHandler) const;
    void InputReportReceived(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IHidDeviceStatics
{
    hstring GetDeviceSelector(uint16_t usagePage, uint16_t usageId) const;
    hstring GetDeviceSelector(uint16_t usagePage, uint16_t usageId, uint16_t vendorId, uint16_t productId) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::HumanInterfaceDevice::HidDevice> FromIdAsync(hstring_view deviceId, Windows::Storage::FileAccessMode accessMode) const;
};

template <typename D>
struct WINRT_EBO impl_IHidFeatureReport
{
    uint16_t Id() const;
    Windows::Storage::Streams::IBuffer Data() const;
    void Data(const Windows::Storage::Streams::IBuffer & value) const;
    Windows::Devices::HumanInterfaceDevice::HidBooleanControl GetBooleanControl(uint16_t usagePage, uint16_t usageId) const;
    Windows::Devices::HumanInterfaceDevice::HidBooleanControl GetBooleanControlByDescription(const Windows::Devices::HumanInterfaceDevice::HidBooleanControlDescription & controlDescription) const;
    Windows::Devices::HumanInterfaceDevice::HidNumericControl GetNumericControl(uint16_t usagePage, uint16_t usageId) const;
    Windows::Devices::HumanInterfaceDevice::HidNumericControl GetNumericControlByDescription(const Windows::Devices::HumanInterfaceDevice::HidNumericControlDescription & controlDescription) const;
};

template <typename D>
struct WINRT_EBO impl_IHidInputReport
{
    uint16_t Id() const;
    Windows::Storage::Streams::IBuffer Data() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::HumanInterfaceDevice::HidBooleanControl> ActivatedBooleanControls() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::HumanInterfaceDevice::HidBooleanControl> TransitionedBooleanControls() const;
    Windows::Devices::HumanInterfaceDevice::HidBooleanControl GetBooleanControl(uint16_t usagePage, uint16_t usageId) const;
    Windows::Devices::HumanInterfaceDevice::HidBooleanControl GetBooleanControlByDescription(const Windows::Devices::HumanInterfaceDevice::HidBooleanControlDescription & controlDescription) const;
    Windows::Devices::HumanInterfaceDevice::HidNumericControl GetNumericControl(uint16_t usagePage, uint16_t usageId) const;
    Windows::Devices::HumanInterfaceDevice::HidNumericControl GetNumericControlByDescription(const Windows::Devices::HumanInterfaceDevice::HidNumericControlDescription & controlDescription) const;
};

template <typename D>
struct WINRT_EBO impl_IHidInputReportReceivedEventArgs
{
    Windows::Devices::HumanInterfaceDevice::HidInputReport Report() const;
};

template <typename D>
struct WINRT_EBO impl_IHidNumericControl
{
    uint32_t Id() const;
    bool IsGrouped() const;
    uint16_t UsagePage() const;
    uint16_t UsageId() const;
    int64_t Value() const;
    void Value(int64_t value) const;
    int64_t ScaledValue() const;
    void ScaledValue(int64_t value) const;
    Windows::Devices::HumanInterfaceDevice::HidNumericControlDescription ControlDescription() const;
};

template <typename D>
struct WINRT_EBO impl_IHidNumericControlDescription
{
    uint32_t Id() const;
    uint16_t ReportId() const;
    Windows::Devices::HumanInterfaceDevice::HidReportType ReportType() const;
    uint32_t ReportSize() const;
    uint32_t ReportCount() const;
    uint16_t UsagePage() const;
    uint16_t UsageId() const;
    int32_t LogicalMinimum() const;
    int32_t LogicalMaximum() const;
    int32_t PhysicalMinimum() const;
    int32_t PhysicalMaximum() const;
    uint32_t UnitExponent() const;
    uint32_t Unit() const;
    bool IsAbsolute() const;
    bool HasNull() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::HumanInterfaceDevice::HidCollection> ParentCollections() const;
};

template <typename D>
struct WINRT_EBO impl_IHidOutputReport
{
    uint16_t Id() const;
    Windows::Storage::Streams::IBuffer Data() const;
    void Data(const Windows::Storage::Streams::IBuffer & value) const;
    Windows::Devices::HumanInterfaceDevice::HidBooleanControl GetBooleanControl(uint16_t usagePage, uint16_t usageId) const;
    Windows::Devices::HumanInterfaceDevice::HidBooleanControl GetBooleanControlByDescription(const Windows::Devices::HumanInterfaceDevice::HidBooleanControlDescription & controlDescription) const;
    Windows::Devices::HumanInterfaceDevice::HidNumericControl GetNumericControl(uint16_t usagePage, uint16_t usageId) const;
    Windows::Devices::HumanInterfaceDevice::HidNumericControl GetNumericControlByDescription(const Windows::Devices::HumanInterfaceDevice::HidNumericControlDescription & controlDescription) const;
};

}

namespace impl {

template <> struct traits<Windows::Devices::HumanInterfaceDevice::IHidBooleanControl>
{
    using abi = ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControl;
    template <typename D> using consume = Windows::Devices::HumanInterfaceDevice::impl_IHidBooleanControl<D>;
};

template <> struct traits<Windows::Devices::HumanInterfaceDevice::IHidBooleanControlDescription>
{
    using abi = ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControlDescription;
    template <typename D> using consume = Windows::Devices::HumanInterfaceDevice::impl_IHidBooleanControlDescription<D>;
};

template <> struct traits<Windows::Devices::HumanInterfaceDevice::IHidBooleanControlDescription2>
{
    using abi = ABI::Windows::Devices::HumanInterfaceDevice::IHidBooleanControlDescription2;
    template <typename D> using consume = Windows::Devices::HumanInterfaceDevice::impl_IHidBooleanControlDescription2<D>;
};

template <> struct traits<Windows::Devices::HumanInterfaceDevice::IHidCollection>
{
    using abi = ABI::Windows::Devices::HumanInterfaceDevice::IHidCollection;
    template <typename D> using consume = Windows::Devices::HumanInterfaceDevice::impl_IHidCollection<D>;
};

template <> struct traits<Windows::Devices::HumanInterfaceDevice::IHidDevice>
{
    using abi = ABI::Windows::Devices::HumanInterfaceDevice::IHidDevice;
    template <typename D> using consume = Windows::Devices::HumanInterfaceDevice::impl_IHidDevice<D>;
};

template <> struct traits<Windows::Devices::HumanInterfaceDevice::IHidDeviceStatics>
{
    using abi = ABI::Windows::Devices::HumanInterfaceDevice::IHidDeviceStatics;
    template <typename D> using consume = Windows::Devices::HumanInterfaceDevice::impl_IHidDeviceStatics<D>;
};

template <> struct traits<Windows::Devices::HumanInterfaceDevice::IHidFeatureReport>
{
    using abi = ABI::Windows::Devices::HumanInterfaceDevice::IHidFeatureReport;
    template <typename D> using consume = Windows::Devices::HumanInterfaceDevice::impl_IHidFeatureReport<D>;
};

template <> struct traits<Windows::Devices::HumanInterfaceDevice::IHidInputReport>
{
    using abi = ABI::Windows::Devices::HumanInterfaceDevice::IHidInputReport;
    template <typename D> using consume = Windows::Devices::HumanInterfaceDevice::impl_IHidInputReport<D>;
};

template <> struct traits<Windows::Devices::HumanInterfaceDevice::IHidInputReportReceivedEventArgs>
{
    using abi = ABI::Windows::Devices::HumanInterfaceDevice::IHidInputReportReceivedEventArgs;
    template <typename D> using consume = Windows::Devices::HumanInterfaceDevice::impl_IHidInputReportReceivedEventArgs<D>;
};

template <> struct traits<Windows::Devices::HumanInterfaceDevice::IHidNumericControl>
{
    using abi = ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControl;
    template <typename D> using consume = Windows::Devices::HumanInterfaceDevice::impl_IHidNumericControl<D>;
};

template <> struct traits<Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription>
{
    using abi = ABI::Windows::Devices::HumanInterfaceDevice::IHidNumericControlDescription;
    template <typename D> using consume = Windows::Devices::HumanInterfaceDevice::impl_IHidNumericControlDescription<D>;
};

template <> struct traits<Windows::Devices::HumanInterfaceDevice::IHidOutputReport>
{
    using abi = ABI::Windows::Devices::HumanInterfaceDevice::IHidOutputReport;
    template <typename D> using consume = Windows::Devices::HumanInterfaceDevice::impl_IHidOutputReport<D>;
};

template <> struct traits<Windows::Devices::HumanInterfaceDevice::HidBooleanControl>
{
    using abi = ABI::Windows::Devices::HumanInterfaceDevice::HidBooleanControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.HumanInterfaceDevice.HidBooleanControl"; }
};

template <> struct traits<Windows::Devices::HumanInterfaceDevice::HidBooleanControlDescription>
{
    using abi = ABI::Windows::Devices::HumanInterfaceDevice::HidBooleanControlDescription;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.HumanInterfaceDevice.HidBooleanControlDescription"; }
};

template <> struct traits<Windows::Devices::HumanInterfaceDevice::HidCollection>
{
    using abi = ABI::Windows::Devices::HumanInterfaceDevice::HidCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.HumanInterfaceDevice.HidCollection"; }
};

template <> struct traits<Windows::Devices::HumanInterfaceDevice::HidDevice>
{
    using abi = ABI::Windows::Devices::HumanInterfaceDevice::HidDevice;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.HumanInterfaceDevice.HidDevice"; }
};

template <> struct traits<Windows::Devices::HumanInterfaceDevice::HidFeatureReport>
{
    using abi = ABI::Windows::Devices::HumanInterfaceDevice::HidFeatureReport;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.HumanInterfaceDevice.HidFeatureReport"; }
};

template <> struct traits<Windows::Devices::HumanInterfaceDevice::HidInputReport>
{
    using abi = ABI::Windows::Devices::HumanInterfaceDevice::HidInputReport;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.HumanInterfaceDevice.HidInputReport"; }
};

template <> struct traits<Windows::Devices::HumanInterfaceDevice::HidInputReportReceivedEventArgs>
{
    using abi = ABI::Windows::Devices::HumanInterfaceDevice::HidInputReportReceivedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.HumanInterfaceDevice.HidInputReportReceivedEventArgs"; }
};

template <> struct traits<Windows::Devices::HumanInterfaceDevice::HidNumericControl>
{
    using abi = ABI::Windows::Devices::HumanInterfaceDevice::HidNumericControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.HumanInterfaceDevice.HidNumericControl"; }
};

template <> struct traits<Windows::Devices::HumanInterfaceDevice::HidNumericControlDescription>
{
    using abi = ABI::Windows::Devices::HumanInterfaceDevice::HidNumericControlDescription;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.HumanInterfaceDevice.HidNumericControlDescription"; }
};

template <> struct traits<Windows::Devices::HumanInterfaceDevice::HidOutputReport>
{
    using abi = ABI::Windows::Devices::HumanInterfaceDevice::HidOutputReport;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.HumanInterfaceDevice.HidOutputReport"; }
};

}

}
