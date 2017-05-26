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

// WindowsDevicesSerialCommunication.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.SerialCommunication.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesSerialCommunication.h"
#include "WindowsDevicesSerialCommunication_priv.h"

@implementation WDSSerialDevice

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::SerialCommunication::ISerialDevice> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::SerialCommunication::ISerialDeviceStatics> WDSISerialDeviceStatics_inst() {
    ComPtr<ABI::Windows::Devices::SerialCommunication::ISerialDeviceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.SerialCommunication.SerialDevice").Get(),
                                                       &inst));
    return inst;
}

+ (NSString*)getDeviceSelector {
    HSTRING unmarshalledReturn;
    auto _comInst = WDSISerialDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)getDeviceSelectorFromPortName:(NSString*)portName {
    HSTRING unmarshalledReturn;
    auto _comInst = WDSISerialDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelectorFromPortName(nsStrToHstr(portName).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)getDeviceSelectorFromUsbVidPid:(unsigned short)vendorId productId:(unsigned short)productId {
    HSTRING unmarshalledReturn;
    auto _comInst = WDSISerialDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelectorFromUsbVidPid(vendorId, productId, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDSSerialDevice*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SerialCommunication::SerialDevice*>> unmarshalledReturn;
    auto _comInst = WDSISerialDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(deviceId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::SerialCommunication::SerialDevice*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SerialCommunication::SerialDevice*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::SerialCommunication::ISerialDevice> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDSSerialDevice>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (unsigned int)baudRate {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_BaudRate(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setBaudRate:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->put_BaudRate(value));
}

- (BOOL)breakSignalState {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_BreakSignalState(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setBreakSignalState:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->put_BreakSignalState((boolean)value));
}

- (unsigned int)bytesReceived {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_BytesReceived(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)carrierDetectState {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_CarrierDetectState(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)clearToSendState {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClearToSendState(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (unsigned short)dataBits {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_DataBits(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDataBits:(unsigned short)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->put_DataBits(value));
}

- (BOOL)dataSetReadyState {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_DataSetReadyState(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDSSerialHandshake)handshake {
    ABI::Windows::Devices::SerialCommunication::SerialHandshake unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handshake(&unmarshalledReturn));
    return (WDSSerialHandshake)unmarshalledReturn;
}

- (void)setHandshake:(WDSSerialHandshake)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handshake((ABI::Windows::Devices::SerialCommunication::SerialHandshake)value));
}

- (BOOL)isDataTerminalReadyEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDataTerminalReadyEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsDataTerminalReadyEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsDataTerminalReadyEnabled((boolean)value));
}

- (BOOL)isRequestToSendEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsRequestToSendEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsRequestToSendEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsRequestToSendEnabled((boolean)value));
}

- (WDSSerialParity)parity {
    ABI::Windows::Devices::SerialCommunication::SerialParity unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_Parity(&unmarshalledReturn));
    return (WDSSerialParity)unmarshalledReturn;
}

- (void)setParity:(WDSSerialParity)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->put_Parity((ABI::Windows::Devices::SerialCommunication::SerialParity)value));
}

- (NSString*)portName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_PortName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFTimeSpan*)readTimeout {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReadTimeout(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setReadTimeout:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReadTimeout(*[value internalStruct]));
}

- (WDSSerialStopBitCount)stopBits {
    ABI::Windows::Devices::SerialCommunication::SerialStopBitCount unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_StopBits(&unmarshalledReturn));
    return (WDSSerialStopBitCount)unmarshalledReturn;
}

- (void)setStopBits:(WDSSerialStopBitCount)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->put_StopBits((ABI::Windows::Devices::SerialCommunication::SerialStopBitCount)value));
}

- (unsigned short)usbVendorId {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_UsbVendorId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned short)usbProductId {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_UsbProductId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFTimeSpan*)writeTimeout {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_WriteTimeout(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setWriteTimeout:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->put_WriteTimeout(*[value internalStruct]));
}

- (RTObject<WSSIInputStream>*)inputStream {
    ComPtr<ABI::Windows::Storage::Streams::IInputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_InputStream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIInputStream>(unmarshalledReturn.Get());
}

- (RTObject<WSSIOutputStream>*)outputStream {
    ComPtr<ABI::Windows::Storage::Streams::IOutputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutputStream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIOutputStream>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addErrorReceivedEvent:(void (^)(WDSSerialDevice*, WDSErrorReceivedEventArgs*))reportHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->add_ErrorReceived(
        Make<
            ITypedEventHandler_Windows_Devices_SerialCommunication_SerialDevice_Windows_Devices_SerialCommunication_ErrorReceivedEventArgs>(
            reportHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeErrorReceivedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ErrorReceived(token));
}

- (EventRegistrationToken)addPinChangedEvent:(void (^)(WDSSerialDevice*, WDSPinChangedEventArgs*))reportHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->add_PinChanged(
        Make<ITypedEventHandler_Windows_Devices_SerialCommunication_SerialDevice_Windows_Devices_SerialCommunication_PinChangedEventArgs>(
            reportHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePinChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::ISerialDevice>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PinChanged(token));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDSErrorReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::SerialCommunication::IErrorReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSSerialError)error {
    ABI::Windows::Devices::SerialCommunication::SerialError unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::IErrorReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Error(&unmarshalledReturn));
    return (WDSSerialError)unmarshalledReturn;
}

@end

@implementation WDSPinChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::SerialCommunication::IPinChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSSerialPinChange)pinChange {
    ABI::Windows::Devices::SerialCommunication::SerialPinChange unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SerialCommunication::IPinChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PinChange(&unmarshalledReturn));
    return (WDSSerialPinChange)unmarshalledReturn;
}

@end
