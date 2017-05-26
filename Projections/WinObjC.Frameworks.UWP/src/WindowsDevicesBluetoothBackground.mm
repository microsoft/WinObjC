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

// WindowsDevicesBluetoothBackground.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Bluetooth.Background.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesBluetoothBackground.h"
#include "WindowsDevicesBluetoothBackground_priv.h"

@implementation WDBBRfcommInboundConnectionInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::Background::IRfcommInboundConnectionInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WSSIBuffer>*)sdpRecord {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Background::IRfcommInboundConnectionInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_SdpRecord(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)setSdpRecord:(RTObject<WSSIBuffer>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Background::IRfcommInboundConnectionInformation>(self);
    THROW_NS_IF_FAILED(_comInst->put_SdpRecord(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(value).Get()));
}

- (WDBRRfcommServiceId*)localServiceId {
    ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Background::IRfcommInboundConnectionInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalServiceId(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBRRfcommServiceId>(unmarshalledReturn.Get());
}

- (void)setLocalServiceId:(WDBRRfcommServiceId*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Background::IRfcommInboundConnectionInformation>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_LocalServiceId(_getRtInterface<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId>(value).Get()));
}

- (WDBBluetoothServiceCapabilities)serviceCapabilities {
    ABI::Windows::Devices::Bluetooth::BluetoothServiceCapabilities unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Background::IRfcommInboundConnectionInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceCapabilities(&unmarshalledReturn));
    return (WDBBluetoothServiceCapabilities)unmarshalledReturn;
}

- (void)setServiceCapabilities:(WDBBluetoothServiceCapabilities)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Background::IRfcommInboundConnectionInformation>(self);
    THROW_NS_IF_FAILED(_comInst->put_ServiceCapabilities((ABI::Windows::Devices::Bluetooth::BluetoothServiceCapabilities)value));
}

@end

@implementation WDBBRfcommOutboundConnectionInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::Background::IRfcommOutboundConnectionInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDBRRfcommServiceId*)remoteServiceId {
    ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Background::IRfcommOutboundConnectionInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteServiceId(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBRRfcommServiceId>(unmarshalledReturn.Get());
}

- (void)setRemoteServiceId:(WDBRRfcommServiceId*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Background::IRfcommOutboundConnectionInformation>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_RemoteServiceId(_getRtInterface<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId>(value).Get()));
}

@end

@implementation WDBBRfcommConnectionTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::Background::IRfcommConnectionTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNSStreamSocket*)socket {
    ComPtr<ABI::Windows::Networking::Sockets::IStreamSocket> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Background::IRfcommConnectionTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Socket(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNSStreamSocket>(unmarshalledReturn.Get());
}

- (BOOL)incoming {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Background::IRfcommConnectionTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Incoming(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDBBluetoothDevice*)remoteDevice {
    ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothDevice> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Background::IRfcommConnectionTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteDevice(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBBluetoothDevice>(unmarshalledReturn.Get());
}

@end

@implementation WDBBGattCharacteristicNotificationTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::Background::IGattCharacteristicNotificationTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDBGGattCharacteristic*)characteristic {
    ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Background::IGattCharacteristicNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Characteristic(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBGGattCharacteristic>(unmarshalledReturn.Get());
}

- (RTObject<WSSIBuffer>*)value {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Background::IGattCharacteristicNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

@end

@implementation WDBBBluetoothLEAdvertisementWatcherTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::Background::IBluetoothLEAdvertisementWatcherTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDBBluetoothError)error {
    ABI::Windows::Devices::Bluetooth::BluetoothError unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Background::IBluetoothLEAdvertisementWatcherTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Error(&unmarshalledReturn));
    return (WDBBluetoothError)unmarshalledReturn;
}

- (NSArray* /* WDBABluetoothLEAdvertisementReceivedEventArgs* */)advertisements {
    ComPtr<IVectorView<ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Background::IBluetoothLEAdvertisementWatcherTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Advertisements(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDBABluetoothLEAdvertisementReceivedEventArgs_create(unmarshalledReturn.Get());
}

- (WDBBluetoothSignalStrengthFilter*)signalStrengthFilter {
    ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Bluetooth::Background::IBluetoothLEAdvertisementWatcherTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_SignalStrengthFilter(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBBluetoothSignalStrengthFilter>(unmarshalledReturn.Get());
}

@end

@implementation WDBBBluetoothLEAdvertisementPublisherTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Bluetooth::Background::IBluetoothLEAdvertisementPublisherTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDBABluetoothLEAdvertisementPublisherStatus)status {
    ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatus unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Devices::Bluetooth::Background::IBluetoothLEAdvertisementPublisherTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WDBABluetoothLEAdvertisementPublisherStatus)unmarshalledReturn;
}

- (WDBBluetoothError)error {
    ABI::Windows::Devices::Bluetooth::BluetoothError unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Devices::Bluetooth::Background::IBluetoothLEAdvertisementPublisherTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Error(&unmarshalledReturn));
    return (WDBBluetoothError)unmarshalledReturn;
}

@end

id RTProxiedNSArray_WDBABluetoothLEAdvertisementReceivedEventArgs_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<
        ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs*>,
                        RTArrayObj<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementReceivedEventArgs*,
                                   IVectorView<ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs*>,
                                   WDBABluetoothLEAdvertisementReceivedEventArgs,
                                   ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs*,
                                   dummyObjCCreator,
                                   dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
