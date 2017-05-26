//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

// WindowsDevicesBluetoothAdvertisement.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Bluetooth.Advertisement.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesBluetoothAdvertisement.h"
#include "WindowsDevicesBluetoothAdvertisement_priv.h"

@implementation WDBABluetoothLEManufacturerData

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerData> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerDataFactory>
WDBAIBluetoothLEManufacturerDataFactory_inst() {
    ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerDataFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEManufacturerData").Get(), &inst));
    return inst;
}

+ (WDBABluetoothLEManufacturerData*)make:(unsigned short)companyId data:(RTObject<WSSIBuffer>*)data {
    ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerData> unmarshalledReturn;
    auto _comInst = WDBAIBluetoothLEManufacturerDataFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(companyId,
                                        _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(data).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDBABluetoothLEManufacturerData>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEManufacturerData").Get(), &out));
    return [_createRtProxy<WDBABluetoothLEManufacturerData>(out.Get()) retain];
}

- (unsigned short)companyId {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerData>(self);
    THROW_NS_IF_FAILED(_comInst->get_CompanyId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setCompanyId:(unsigned short)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerData>(self);
    THROW_NS_IF_FAILED(_comInst->put_CompanyId(value));
}

- (RTObject<WSSIBuffer>*)data {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerData>(self);
    THROW_NS_IF_FAILED(_comInst->get_Data(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)setData:(RTObject<WSSIBuffer>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerData>(self);
    THROW_NS_IF_FAILED(_comInst->put_Data(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(value).Get()));
}

@end

@implementation WDBABluetoothLEAdvertisementDataSection

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementDataSection").Get(), &out));
    return [_createRtProxy<WDBABluetoothLEAdvertisementDataSection>(out.Get()) retain];
}

static ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSectionFactory>
WDBAIBluetoothLEAdvertisementDataSectionFactory_inst() {
    ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSectionFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementDataSection").Get(), &inst));
    return inst;
}

+ (WDBABluetoothLEAdvertisementDataSection*)make:(uint8_t)dataType data:(RTObject<WSSIBuffer>*)data {
    ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSection> unmarshalledReturn;
    auto _comInst = WDBAIBluetoothLEAdvertisementDataSectionFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(dataType,
                                        _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(data).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDBABluetoothLEAdvertisementDataSection>(unmarshalledReturn.Get()) retain];
}

- (uint8_t)dataType {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSection>(self);
    THROW_NS_IF_FAILED(_comInst->get_DataType(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDataType:(uint8_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSection>(self);
    THROW_NS_IF_FAILED(_comInst->put_DataType(value));
}

- (RTObject<WSSIBuffer>*)data {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Data(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)setData:(RTObject<WSSIBuffer>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSection>(self);
    THROW_NS_IF_FAILED(_comInst->put_Data(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(value).Get()));
}

@end

@implementation WDBABluetoothLEAdvertisement

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisement").Get(), &out));
    return [_createRtProxy<WDBABluetoothLEAdvertisement>(out.Get()) retain];
}

- (id /* WDBABluetoothLEAdvertisementFlags */)flags {
    ComPtr<IReference<ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFlags>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Flags(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WDBABluetoothLEAdvertisementFlags,
                            ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFlags>::convert(unmarshalledReturn
                                                                                                                         .Get());
}

- (void)setFlags:(id /* WDBABluetoothLEAdvertisementFlags */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_Flags(BuildNullable<ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFlags>(value)));
}

- (NSString*)localName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLocalName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement>(self);
    THROW_NS_IF_FAILED(_comInst->put_LocalName(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* WFGUID* */)serviceUuids {
    ComPtr<IVector<GUID>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceUuids(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WFGUID_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WDBABluetoothLEManufacturerData* */)manufacturerData {
    ComPtr<IVector<ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEManufacturerData*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement>(self);
    THROW_NS_IF_FAILED(_comInst->get_ManufacturerData(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WDBABluetoothLEManufacturerData_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WDBABluetoothLEAdvertisementDataSection* */)dataSections {
    ComPtr<IVector<ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataSection*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement>(self);
    THROW_NS_IF_FAILED(_comInst->get_DataSections(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WDBABluetoothLEAdvertisementDataSection_create(unmarshalledReturn.Get());
}

- (NSArray* /* WDBABluetoothLEManufacturerData* */)getManufacturerDataByCompanyId:(unsigned short)companyId {
    ComPtr<IVectorView<ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEManufacturerData*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement>(self);
    THROW_NS_IF_FAILED(_comInst->GetManufacturerDataByCompanyId(companyId, unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDBABluetoothLEManufacturerData_create(unmarshalledReturn.Get());
}

- (NSArray* /* WDBABluetoothLEAdvertisementDataSection* */)getSectionsByType:(uint8_t)type {
    ComPtr<IVectorView<ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataSection*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement>(self);
    THROW_NS_IF_FAILED(_comInst->GetSectionsByType(type, unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDBABluetoothLEAdvertisementDataSection_create(unmarshalledReturn.Get());
}

@end

@implementation WDBABluetoothLEAdvertisementBytePattern

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePattern> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePatternFactory>
WDBAIBluetoothLEAdvertisementBytePatternFactory_inst() {
    ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePatternFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementBytePattern").Get(), &inst));
    return inst;
}

+ (WDBABluetoothLEAdvertisementBytePattern*)make:(uint8_t)dataType offset:(int16_t)offset data:(RTObject<WSSIBuffer>*)data {
    ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePattern> unmarshalledReturn;
    auto _comInst = WDBAIBluetoothLEAdvertisementBytePatternFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(dataType,
                                        offset,
                                        _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(data).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDBABluetoothLEAdvertisementBytePattern>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementBytePattern").Get(), &out));
    return [_createRtProxy<WDBABluetoothLEAdvertisementBytePattern>(out.Get()) retain];
}

- (uint8_t)dataType {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePattern>(self);
    THROW_NS_IF_FAILED(_comInst->get_DataType(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDataType:(uint8_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePattern>(self);
    THROW_NS_IF_FAILED(_comInst->put_DataType(value));
}

- (int16_t)offset {
    int16_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePattern>(self);
    THROW_NS_IF_FAILED(_comInst->get_Offset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOffset:(int16_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePattern>(self);
    THROW_NS_IF_FAILED(_comInst->put_Offset(value));
}

- (RTObject<WSSIBuffer>*)data {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePattern>(self);
    THROW_NS_IF_FAILED(_comInst->get_Data(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)setData:(RTObject<WSSIBuffer>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePattern>(self);
    THROW_NS_IF_FAILED(_comInst->put_Data(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(value).Get()));
}

@end

@implementation WDBABluetoothLEAdvertisementFilter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementFilter").Get(), &out));
    return [_createRtProxy<WDBABluetoothLEAdvertisementFilter>(out.Get()) retain];
}

- (WDBABluetoothLEAdvertisement*)advertisement {
    ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_Advertisement(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBABluetoothLEAdvertisement>(unmarshalledReturn.Get());
}

- (void)setAdvertisement:(WDBABluetoothLEAdvertisement*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter>(self);
    THROW_NS_IF_FAILED(_comInst->put_Advertisement(
        _getRtInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement>(value).Get()));
}

- (NSMutableArray* /* WDBABluetoothLEAdvertisementBytePattern* */)bytePatterns {
    ComPtr<IVector<ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementBytePattern*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_BytePatterns(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WDBABluetoothLEAdvertisementBytePattern_create(unmarshalledReturn.Get());
}

@end

@implementation WDBABluetoothLEAdvertisementWatcherStoppedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcherStoppedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDBBluetoothError)error {
    ABI::Windows::Devices::Bluetooth::BluetoothError unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcherStoppedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Error(&unmarshalledReturn));
    return (WDBBluetoothError)unmarshalledReturn;
}

@end

@implementation WDBABluetoothLEAdvertisementWatcher

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementWatcher").Get(), &out));
    return [_createRtProxy<WDBABluetoothLEAdvertisementWatcher>(out.Get()) retain];
}

static ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcherFactory>
WDBAIBluetoothLEAdvertisementWatcherFactory_inst() {
    ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcherFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementWatcher").Get(), &inst));
    return inst;
}

+ (WDBABluetoothLEAdvertisementWatcher*)make:(WDBABluetoothLEAdvertisementFilter*)advertisementFilter {
    ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher> unmarshalledReturn;
    auto _comInst = WDBAIBluetoothLEAdvertisementWatcherFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(
        _getRtInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter>(advertisementFilter).Get(),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDBABluetoothLEAdvertisementWatcher>(unmarshalledReturn.Get()) retain];
}

- (WFTimeSpan*)minSamplingInterval {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinSamplingInterval(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFTimeSpan*)maxSamplingInterval {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxSamplingInterval(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFTimeSpan*)minOutOfRangeTimeout {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinOutOfRangeTimeout(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFTimeSpan*)maxOutOfRangeTimeout {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxOutOfRangeTimeout(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WDBABluetoothLEAdvertisementWatcherStatus)status {
    ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcherStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WDBABluetoothLEAdvertisementWatcherStatus)unmarshalledReturn;
}

- (WDBABluetoothLEScanningMode)scanningMode {
    ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEScanningMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScanningMode(&unmarshalledReturn));
    return (WDBABluetoothLEScanningMode)unmarshalledReturn;
}

- (void)setScanningMode:(WDBABluetoothLEScanningMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->put_ScanningMode((ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEScanningMode)value));
}

- (WDBBluetoothSignalStrengthFilter*)signalStrengthFilter {
    ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->get_SignalStrengthFilter(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBBluetoothSignalStrengthFilter>(unmarshalledReturn.Get());
}

- (void)setSignalStrengthFilter:(WDBBluetoothSignalStrengthFilter*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_SignalStrengthFilter(_getRtInterface<ABI::Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter>(value).Get()));
}

- (WDBABluetoothLEAdvertisementFilter*)advertisementFilter {
    ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->get_AdvertisementFilter(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBABluetoothLEAdvertisementFilter>(unmarshalledReturn.Get());
}

- (void)setAdvertisementFilter:(WDBABluetoothLEAdvertisementFilter*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->put_AdvertisementFilter(
        _getRtInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter>(value).Get()));
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

- (EventRegistrationToken)addReceivedEvent:(void (^)(WDBABluetoothLEAdvertisementWatcher*,
                                                     WDBABluetoothLEAdvertisementReceivedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_Received(
        Make<
            ITypedEventHandler_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementWatcher_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementReceivedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeReceivedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Received(token));
}

- (EventRegistrationToken)addStoppedEvent:(void (^)(WDBABluetoothLEAdvertisementWatcher*,
                                                    WDBABluetoothLEAdvertisementWatcherStoppedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_Stopped(
        Make<
            ITypedEventHandler_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementWatcher_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementWatcherStoppedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStoppedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Stopped(token));
}

@end

@implementation WDBABluetoothLEAdvertisementReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int16_t)rawSignalStrengthInDBm {
    int16_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawSignalStrengthInDBm(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)bluetoothAddress {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_BluetoothAddress(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDBABluetoothLEAdvertisementType)advertisementType {
    ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_AdvertisementType(&unmarshalledReturn));
    return (WDBABluetoothLEAdvertisementType)unmarshalledReturn;
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WDBABluetoothLEAdvertisement*)advertisement {
    ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Advertisement(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBABluetoothLEAdvertisement>(unmarshalledReturn.Get());
}

@end

@implementation WDBABluetoothLEAdvertisementDataTypes

ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataTypesStatics>
WDBAIBluetoothLEAdvertisementDataTypesStatics_inst() {
    ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataTypesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementDataTypes").Get(), &inst));
    return inst;
}

+ (uint8_t)flags {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBAIBluetoothLEAdvertisementDataTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Flags(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)incompleteService16BitUuids {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBAIBluetoothLEAdvertisementDataTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IncompleteService16BitUuids(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)completeService16BitUuids {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBAIBluetoothLEAdvertisementDataTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CompleteService16BitUuids(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)incompleteService32BitUuids {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBAIBluetoothLEAdvertisementDataTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IncompleteService32BitUuids(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)completeService32BitUuids {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBAIBluetoothLEAdvertisementDataTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CompleteService32BitUuids(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)incompleteService128BitUuids {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBAIBluetoothLEAdvertisementDataTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IncompleteService128BitUuids(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)completeService128BitUuids {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBAIBluetoothLEAdvertisementDataTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CompleteService128BitUuids(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)shortenedLocalName {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBAIBluetoothLEAdvertisementDataTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ShortenedLocalName(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)completeLocalName {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBAIBluetoothLEAdvertisementDataTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CompleteLocalName(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)txPowerLevel {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBAIBluetoothLEAdvertisementDataTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TxPowerLevel(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)slaveConnectionIntervalRange {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBAIBluetoothLEAdvertisementDataTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SlaveConnectionIntervalRange(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)serviceSolicitation16BitUuids {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBAIBluetoothLEAdvertisementDataTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ServiceSolicitation16BitUuids(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)serviceSolicitation32BitUuids {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBAIBluetoothLEAdvertisementDataTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ServiceSolicitation32BitUuids(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)serviceSolicitation128BitUuids {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBAIBluetoothLEAdvertisementDataTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ServiceSolicitation128BitUuids(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)serviceData16BitUuids {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBAIBluetoothLEAdvertisementDataTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ServiceData16BitUuids(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)serviceData32BitUuids {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBAIBluetoothLEAdvertisementDataTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ServiceData32BitUuids(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)serviceData128BitUuids {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBAIBluetoothLEAdvertisementDataTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ServiceData128BitUuids(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)publicTargetAddress {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBAIBluetoothLEAdvertisementDataTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PublicTargetAddress(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)randomTargetAddress {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBAIBluetoothLEAdvertisementDataTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RandomTargetAddress(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)appearance {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBAIBluetoothLEAdvertisementDataTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Appearance(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)advertisingInterval {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBAIBluetoothLEAdvertisementDataTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AdvertisingInterval(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint8_t)manufacturerSpecificData {
    uint8_t unmarshalledReturn;
    auto _comInst = WDBAIBluetoothLEAdvertisementDataTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ManufacturerSpecificData(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDBABluetoothLEAdvertisementPublisherStatusChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherStatusChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDBABluetoothLEAdvertisementPublisherStatus)status {
    ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatus unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherStatusChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WDBABluetoothLEAdvertisementPublisherStatus)unmarshalledReturn;
}

- (WDBBluetoothError)error {
    ABI::Windows::Devices::Bluetooth::BluetoothError unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherStatusChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Error(&unmarshalledReturn));
    return (WDBBluetoothError)unmarshalledReturn;
}

@end

@implementation WDBABluetoothLEAdvertisementPublisher

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherFactory>
WDBAIBluetoothLEAdvertisementPublisherFactory_inst() {
    ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementPublisher").Get(), &inst));
    return inst;
}

+ (WDBABluetoothLEAdvertisementPublisher*)make:(WDBABluetoothLEAdvertisement*)advertisement {
    ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher> unmarshalledReturn;
    auto _comInst = WDBAIBluetoothLEAdvertisementPublisherFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create(_getRtInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement>(advertisement).Get(),
                         unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDBABluetoothLEAdvertisementPublisher>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementPublisher").Get(), &out));
    return [_createRtProxy<WDBABluetoothLEAdvertisementPublisher>(out.Get()) retain];
}

- (WDBABluetoothLEAdvertisementPublisherStatus)status {
    ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WDBABluetoothLEAdvertisementPublisherStatus)unmarshalledReturn;
}

- (WDBABluetoothLEAdvertisement*)advertisement {
    ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher>(self);
    THROW_NS_IF_FAILED(_comInst->get_Advertisement(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBABluetoothLEAdvertisement>(unmarshalledReturn.Get());
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

- (EventRegistrationToken)addStatusChangedEvent:(void (^)(WDBABluetoothLEAdvertisementPublisher*,
                                                          WDBABluetoothLEAdvertisementPublisherStatusChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher>(self);
    THROW_NS_IF_FAILED(_comInst->add_StatusChanged(
        Make<
            ITypedEventHandler_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementPublisher_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementPublisherStatusChangedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStatusChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_StatusChanged(token));
}

@end

id RTProxiedNSArray_WDBABluetoothLEAdvertisementDataSection_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<
        ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataSection*>,
                        RTArrayObj<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSection*,
                                   IVectorView<ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataSection*>,
                                   WDBABluetoothLEAdvertisementDataSection,
                                   ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataSection*,
                                   dummyObjCCreator,
                                   dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDBABluetoothLEManufacturerData_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<
        ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEManufacturerData*>,
                        RTArrayObj<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerData*,
                                   IVectorView<ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEManufacturerData*>,
                                   WDBABluetoothLEManufacturerData,
                                   ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEManufacturerData*,
                                   dummyObjCCreator,
                                   dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WDBABluetoothLEAdvertisementBytePattern_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<MutableArrayAdapterObj<
        IVector<ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementBytePattern*>,
        RTMutableArrayObj<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePattern*,
                          IVector<ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementBytePattern*>,
                          WDBABluetoothLEAdvertisementBytePattern,
                          ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementBytePattern*,
                          dummyObjCCreator,
                          dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WDBABluetoothLEAdvertisementDataSection_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<MutableArrayAdapterObj<
        IVector<ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataSection*>,
        RTMutableArrayObj<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSection*,
                          IVector<ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataSection*>,
                          WDBABluetoothLEAdvertisementDataSection,
                          ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementDataSection*,
                          dummyObjCCreator,
                          dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WDBABluetoothLEManufacturerData_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEManufacturerData*>,
                               RTMutableArrayObj<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerData*,
                                                 IVector<ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEManufacturerData*>,
                                                 WDBABluetoothLEManufacturerData,
                                                 ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEManufacturerData*,
                                                 dummyObjCCreator,
                                                 dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WFGUID_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<GUID>, RTMutableArrayObj<GUID, IVector<GUID>, WFGUID, GUID, dummyObjCCreator, dummyWRLCreator>>>(
        val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
