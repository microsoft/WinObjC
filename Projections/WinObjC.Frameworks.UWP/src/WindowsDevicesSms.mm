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

// WindowsDevicesSms.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Sms.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesSms.h"
#include "WindowsDevicesSms_priv.h"

@implementation WDSISmsMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sms::ISmsMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)id {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDSSmsMessageClass)messageClass {
    ABI::Windows::Devices::Sms::SmsMessageClass unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageClass(&unmarshalledReturn));
    return (WDSSmsMessageClass)unmarshalledReturn;
}

@end

@implementation WDSISmsBinaryMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sms::ISmsBinaryMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSSmsDataFormat)format {
    ABI::Windows::Devices::Sms::SmsDataFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsBinaryMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Format(&unmarshalledReturn));
    return (WDSSmsDataFormat)unmarshalledReturn;
}

- (void)setFormat:(WDSSmsDataFormat)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsBinaryMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_Format((ABI::Windows::Devices::Sms::SmsDataFormat)value));
}

- (NSArray* /* uint8_t */)getData {
    uint8_t* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsBinaryMessage>(self);
    THROW_NS_IF_FAILED(_comInst->GetData(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_UInt8_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (void)setData:(NSArray* /* uint8_t */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    uint8_t* __value_Array = NULL;
    if (!ConvertToCArray<uint8_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsBinaryMessage>(self);
    THROW_NS_IF_FAILED(_comInst->SetData(__value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (unsigned int)id {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDSSmsMessageClass)messageClass {
    ABI::Windows::Devices::Sms::SmsMessageClass unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageClass(&unmarshalledReturn));
    return (WDSSmsMessageClass)unmarshalledReturn;
}

@end

@implementation WDSISmsTextMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sms::ISmsTextMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (unsigned int)partReferenceId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_PartReferenceId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)partNumber {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_PartNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)partCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_PartCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)to {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_To(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTo:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_To(nsStrToHstr(value).Get()));
}

- (NSString*)from {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_From(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setFrom:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_From(nsStrToHstr(value).Get()));
}

- (NSString*)body {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Body(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setBody:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_Body(nsStrToHstr(value).Get()));
}

- (WDSSmsEncoding)encoding {
    ABI::Windows::Devices::Sms::SmsEncoding unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Encoding(&unmarshalledReturn));
    return (WDSSmsEncoding)unmarshalledReturn;
}

- (void)setEncoding:(WDSSmsEncoding)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_Encoding((ABI::Windows::Devices::Sms::SmsEncoding)value));
}

- (NSArray* /* RTObject<WDSISmsBinaryMessage>* */)toBinaryMessages:(WDSSmsDataFormat)format {
    ComPtr<IVectorView<ABI::Windows::Devices::Sms::ISmsBinaryMessage*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage>(self);
    THROW_NS_IF_FAILED(_comInst->ToBinaryMessages((ABI::Windows::Devices::Sms::SmsDataFormat)format, unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_RTObject_WDSISmsBinaryMessage_create(unmarshalledReturn.Get());
}

- (unsigned int)id {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDSSmsMessageClass)messageClass {
    ABI::Windows::Devices::Sms::SmsMessageClass unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageClass(&unmarshalledReturn));
    return (WDSSmsMessageClass)unmarshalledReturn;
}

@end

@implementation WDSISmsDevice

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sms::ISmsDevice> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSSendSmsMessageOperation*)sendMessageAsync:(RTObject<WDSISmsMessage>*)message {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice>(self);
    THROW_NS_IF_FAILED(_comInst->SendMessageAsync(_getRtInterface<ABI::Windows::Devices::Sms::ISmsMessage>(message).Get(),
                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSendSmsMessageOperation>(unmarshalledReturn.Get());
}

- (WDSSmsEncodedLength*)calculateLength:(WDSSmsTextMessage*)message {
    ABI::Windows::Devices::Sms::SmsEncodedLength unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice>(self);
    THROW_NS_IF_FAILED(
        _comInst->CalculateLength(_getRtInterface<ABI::Windows::Devices::Sms::ISmsTextMessage>(message).Get(), &unmarshalledReturn));
    return WDSSmsEncodedLength_create(unmarshalledReturn);
}

- (NSString*)accountPhoneNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccountPhoneNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDSCellularClass)cellularClass {
    ABI::Windows::Devices::Sms::CellularClass unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_CellularClass(&unmarshalledReturn));
    return (WDSCellularClass)unmarshalledReturn;
}

- (WDSSmsDeviceMessageStore*)messageStore {
    ComPtr<ABI::Windows::Devices::Sms::ISmsDeviceMessageStore> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageStore(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSmsDeviceMessageStore>(unmarshalledReturn.Get());
}

- (WDSSmsDeviceStatus)deviceStatus {
    ABI::Windows::Devices::Sms::SmsDeviceStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceStatus(&unmarshalledReturn));
    return (WDSSmsDeviceStatus)unmarshalledReturn;
}

- (EventRegistrationToken)addSmsMessageReceivedEvent:(WDSSmsMessageReceivedEventHandler)eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_SmsMessageReceived(Make<WDSSmsMessageReceivedEventHandler_shim>(eventHandler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSmsMessageReceivedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SmsMessageReceived(eventCookie));
}

- (EventRegistrationToken)addSmsDeviceStatusChangedEvent:(WDSSmsDeviceStatusChangedEventHandler)eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_SmsDeviceStatusChanged(Make<WDSSmsDeviceStatusChangedEventHandler_shim>(eventHandler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSmsDeviceStatusChangedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SmsDeviceStatusChanged(eventCookie));
}

@end

@implementation WDSISmsMessageBase

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sms::ISmsMessageBase> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSSmsMessageType)messageType {
    ABI::Windows::Devices::Sms::SmsMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageType(&unmarshalledReturn));
    return (WDSSmsMessageType)unmarshalledReturn;
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDSCellularClass)cellularClass {
    ABI::Windows::Devices::Sms::CellularClass unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_CellularClass(&unmarshalledReturn));
    return (WDSCellularClass)unmarshalledReturn;
}

- (WDSSmsMessageClass)messageClass {
    ABI::Windows::Devices::Sms::SmsMessageClass unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageClass(&unmarshalledReturn));
    return (WDSSmsMessageClass)unmarshalledReturn;
}

- (NSString*)simIccId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_SimIccId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDSSmsBinaryMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sms::ISmsBinaryMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Devices.Sms.SmsBinaryMessage").Get(), &out));
    return [_createRtProxy<WDSSmsBinaryMessage>(out.Get()) retain];
}

- (WDSSmsDataFormat)format {
    ABI::Windows::Devices::Sms::SmsDataFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsBinaryMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Format(&unmarshalledReturn));
    return (WDSSmsDataFormat)unmarshalledReturn;
}

- (void)setFormat:(WDSSmsDataFormat)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsBinaryMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_Format((ABI::Windows::Devices::Sms::SmsDataFormat)value));
}

- (NSArray* /* uint8_t */)getData {
    uint8_t* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsBinaryMessage>(self);
    THROW_NS_IF_FAILED(_comInst->GetData(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_UInt8_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (void)setData:(NSArray* /* uint8_t */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    uint8_t* __value_Array = NULL;
    if (!ConvertToCArray<uint8_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsBinaryMessage>(self);
    THROW_NS_IF_FAILED(_comInst->SetData(__value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (unsigned int)id {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDSSmsMessageClass)messageClass {
    ABI::Windows::Devices::Sms::SmsMessageClass unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageClass(&unmarshalledReturn));
    return (WDSSmsMessageClass)unmarshalledReturn;
}

@end

@implementation WDSSmsTextMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sms::ISmsTextMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Devices.Sms.SmsTextMessage").Get(), &out));
    return [_createRtProxy<WDSSmsTextMessage>(out.Get()) retain];
}

ComPtr<ABI::Windows::Devices::Sms::ISmsTextMessageStatics> WDSISmsTextMessageStatics_inst() {
    ComPtr<ABI::Windows::Devices::Sms::ISmsTextMessageStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Sms.SmsTextMessage").Get(), &inst));
    return inst;
}

+ (WDSSmsTextMessage*)fromBinaryMessage:(WDSSmsBinaryMessage*)binaryMessage {
    ComPtr<ABI::Windows::Devices::Sms::ISmsTextMessage> unmarshalledReturn;
    auto _comInst = WDSISmsTextMessageStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromBinaryMessage(_getRtInterface<ABI::Windows::Devices::Sms::ISmsBinaryMessage>(binaryMessage).Get(),
                                                   unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSmsTextMessage>(unmarshalledReturn.Get());
}

+ (WDSSmsTextMessage*)fromBinaryData:(WDSSmsDataFormat)format value:(NSArray* /* uint8_t */)value {
    ComPtr<ABI::Windows::Devices::Sms::ISmsTextMessage> unmarshalledReturn;
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    uint8_t* __value_Array = NULL;
    if (!ConvertToCArray<uint8_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = WDSISmsTextMessageStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromBinaryData((ABI::Windows::Devices::Sms::SmsDataFormat)format,
                                                __value_ArrayLen,
                                                __value_Array,
                                                unmarshalledReturn.GetAddressOf()));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
    return _createRtProxy<WDSSmsTextMessage>(unmarshalledReturn.Get());
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (unsigned int)partReferenceId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_PartReferenceId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)partNumber {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_PartNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)partCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_PartCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)to {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_To(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTo:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_To(nsStrToHstr(value).Get()));
}

- (NSString*)from {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_From(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setFrom:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_From(nsStrToHstr(value).Get()));
}

- (NSString*)body {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Body(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setBody:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_Body(nsStrToHstr(value).Get()));
}

- (WDSSmsEncoding)encoding {
    ABI::Windows::Devices::Sms::SmsEncoding unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Encoding(&unmarshalledReturn));
    return (WDSSmsEncoding)unmarshalledReturn;
}

- (void)setEncoding:(WDSSmsEncoding)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_Encoding((ABI::Windows::Devices::Sms::SmsEncoding)value));
}

- (NSArray* /* RTObject<WDSISmsBinaryMessage>* */)toBinaryMessages:(WDSSmsDataFormat)format {
    ComPtr<IVectorView<ABI::Windows::Devices::Sms::ISmsBinaryMessage*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage>(self);
    THROW_NS_IF_FAILED(_comInst->ToBinaryMessages((ABI::Windows::Devices::Sms::SmsDataFormat)format, unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_RTObject_WDSISmsBinaryMessage_create(unmarshalledReturn.Get());
}

- (unsigned int)id {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDSSmsMessageClass)messageClass {
    ABI::Windows::Devices::Sms::SmsMessageClass unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageClass(&unmarshalledReturn));
    return (WDSSmsMessageClass)unmarshalledReturn;
}

@end

@implementation WDSDeleteSmsMessageOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setCompleted:(WFAsyncActionCompletedHandler)handler {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncAction>(self);
    THROW_NS_IF_FAILED(_comInst->put_Completed(Make<WFAsyncActionCompletedHandler_shim>(handler).Get()));
}

- (WFAsyncActionCompletedHandler)completed {
    ComPtr<ABI::Windows::Foundation::IAsyncActionCompletedHandler> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncAction>(self);
    THROW_NS_IF_FAILED(_comInst->get_Completed(unmarshalledReturn.GetAddressOf()));
    return nil;
}

- (void)getResults {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncAction>(self);
    THROW_NS_IF_FAILED(_comInst->GetResults());
}

- (unsigned int)id {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFAsyncStatus)status {
    AsyncStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (unsigned)unmarshalledReturn;
}

- (HRESULT)errorCode {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorCode(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

- (void)cancel {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->Cancel());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDSDeleteSmsMessagesOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setCompleted:(WFAsyncActionCompletedHandler)handler {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncAction>(self);
    THROW_NS_IF_FAILED(_comInst->put_Completed(Make<WFAsyncActionCompletedHandler_shim>(handler).Get()));
}

- (WFAsyncActionCompletedHandler)completed {
    ComPtr<ABI::Windows::Foundation::IAsyncActionCompletedHandler> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncAction>(self);
    THROW_NS_IF_FAILED(_comInst->get_Completed(unmarshalledReturn.GetAddressOf()));
    return nil;
}

- (void)getResults {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncAction>(self);
    THROW_NS_IF_FAILED(_comInst->GetResults());
}

- (unsigned int)id {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFAsyncStatus)status {
    AsyncStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (unsigned)unmarshalledReturn;
}

- (HRESULT)errorCode {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorCode(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

- (void)cancel {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->Cancel());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDSGetSmsMessageOperation

// Failed to get type for default interface: Can't marshal Windows.Foundation.IAsyncOperation`1<Windows.Devices.Sms.ISmsMessage>
// Could not find base class Windows.Foundation.IAsyncOperation`1<Windows.Devices.Sms.ISmsMessage> type information
- (unsigned int)id {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFAsyncStatus)status {
    AsyncStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (unsigned)unmarshalledReturn;
}

- (HRESULT)errorCode {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorCode(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

- (void)cancel {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->Cancel());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDSGetSmsMessagesOperation

// Failed to get type for default interface: Can't marshal
// Windows.Foundation.IAsyncOperationWithProgress`2<Windows.Foundation.Collections.IVectorView`1<Windows.Devices.Sms.ISmsMessage>,Int32>
// Could not find base class
// Windows.Foundation.IAsyncOperationWithProgress`2<Windows.Foundation.Collections.IVectorView`1<Windows.Devices.Sms.ISmsMessage>,Int32>
// type information
- (unsigned int)id {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFAsyncStatus)status {
    AsyncStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (unsigned)unmarshalledReturn;
}

- (HRESULT)errorCode {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorCode(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

- (void)cancel {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->Cancel());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDSSmsDeviceMessageStore

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sms::ISmsDeviceMessageStore> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WFIAsyncAction>*)deleteMessageAsync:(unsigned int)messageId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDeviceMessageStore>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteMessageAsync(messageId, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)deleteMessagesAsync:(WDSSmsMessageFilter)messageFilter {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDeviceMessageStore>(self);
    THROW_NS_IF_FAILED(
        _comInst->DeleteMessagesAsync((ABI::Windows::Devices::Sms::SmsMessageFilter)messageFilter, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)getMessageAsync:(unsigned int)messageId success:(void (^)(RTObject<WDSISmsMessage>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Sms::ISmsMessage*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDeviceMessageStore>(self);
    THROW_NS_IF_FAILED(_comInst->GetMessageAsync(messageId, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Sms::ISmsMessage*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Sms::ISmsMessage*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Sms::ISmsMessage> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDSISmsMessage>(result.Get()));
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

- (void)getMessagesAsync:(WDSSmsMessageFilter)messageFilter
                 success:(void (^)(NSArray* /* RTObject<WDSISmsMessage>* */))success
                progress:(void (^)(int))progress
                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<IVectorView<ABI::Windows::Devices::Sms::ISmsMessage*>*, int>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDeviceMessageStore>(self);
    THROW_NS_IF_FAILED(_comInst->GetMessagesAsync((ABI::Windows::Devices::Sms::SmsMessageFilter)messageFilter, &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<IVectorView<ABI::Windows::Devices::Sms::ISmsMessage*>*, int>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<IVectorView<ABI::Windows::Devices::Sms::ISmsMessage*>*, int>* op,
            int status) {
            @autoreleasepool {
                progressRc(status);
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<IVectorView<ABI::Windows::Devices::Sms::ISmsMessage*>*,
                                                                              int>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<IVectorView<ABI::Windows::Devices::Sms::ISmsMessage*>*, int>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Devices::Sms::ISmsMessage*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_RTObject_WDSISmsMessage_create(result.Get()));
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

- (unsigned int)maxMessages {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDeviceMessageStore>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxMessages(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDSSendSmsMessageOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setCompleted:(WFAsyncActionCompletedHandler)handler {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncAction>(self);
    THROW_NS_IF_FAILED(_comInst->put_Completed(Make<WFAsyncActionCompletedHandler_shim>(handler).Get()));
}

- (WFAsyncActionCompletedHandler)completed {
    ComPtr<ABI::Windows::Foundation::IAsyncActionCompletedHandler> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncAction>(self);
    THROW_NS_IF_FAILED(_comInst->get_Completed(unmarshalledReturn.GetAddressOf()));
    return nil;
}

- (void)getResults {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncAction>(self);
    THROW_NS_IF_FAILED(_comInst->GetResults());
}

- (unsigned int)id {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFAsyncStatus)status {
    AsyncStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (unsigned)unmarshalledReturn;
}

- (HRESULT)errorCode {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorCode(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

- (void)cancel {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->Cancel());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDSSmsMessageReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sms::ISmsMessageReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSSmsTextMessage*)textMessage {
    ComPtr<ABI::Windows::Devices::Sms::ISmsTextMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_TextMessage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSmsTextMessage>(unmarshalledReturn.Get());
}

- (WDSSmsBinaryMessage*)binaryMessage {
    ComPtr<ABI::Windows::Devices::Sms::ISmsBinaryMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_BinaryMessage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSmsBinaryMessage>(unmarshalledReturn.Get());
}

@end

@implementation WDSSmsDevice

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sms::ISmsDevice> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Sms::ISmsDeviceStatics2> WDSISmsDeviceStatics2_inst() {
    ComPtr<ABI::Windows::Devices::Sms::ISmsDeviceStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Sms.SmsDevice").Get(), &inst));
    return inst;
}

+ (void)fromNetworkAccountIdAsync:(NSString*)networkAccountId success:(void (^)(WDSSmsDevice*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Sms::SmsDevice*>> unmarshalledReturn;
    auto _comInst = WDSISmsDeviceStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->FromNetworkAccountIdAsync(nsStrToHstr(networkAccountId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Sms::SmsDevice*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Sms::SmsDevice*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Sms::ISmsDevice> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDSSmsDevice>(result.Get()));
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

ComPtr<ABI::Windows::Devices::Sms::ISmsDeviceStatics> WDSISmsDeviceStatics_inst() {
    ComPtr<ABI::Windows::Devices::Sms::ISmsDeviceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Sms.SmsDevice").Get(), &inst));
    return inst;
}

+ (NSString*)getDeviceSelector {
    HSTRING unmarshalledReturn;
    auto _comInst = WDSISmsDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDSSmsDevice*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Sms::SmsDevice*>> unmarshalledReturn;
    auto _comInst = WDSISmsDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(deviceId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Sms::SmsDevice*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Sms::SmsDevice*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Sms::ISmsDevice> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDSSmsDevice>(result.Get()));
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

+ (void)getDefaultAsyncWithSuccess:(void (^)(WDSSmsDevice*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Sms::SmsDevice*>> unmarshalledReturn;
    auto _comInst = WDSISmsDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefaultAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Sms::SmsDevice*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Sms::SmsDevice*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Sms::ISmsDevice> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDSSmsDevice>(result.Get()));
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

- (WDSSendSmsMessageOperation*)sendMessageAsync:(RTObject<WDSISmsMessage>*)message {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice>(self);
    THROW_NS_IF_FAILED(_comInst->SendMessageAsync(_getRtInterface<ABI::Windows::Devices::Sms::ISmsMessage>(message).Get(),
                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSendSmsMessageOperation>(unmarshalledReturn.Get());
}

- (WDSSmsEncodedLength*)calculateLength:(WDSSmsTextMessage*)message {
    ABI::Windows::Devices::Sms::SmsEncodedLength unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice>(self);
    THROW_NS_IF_FAILED(
        _comInst->CalculateLength(_getRtInterface<ABI::Windows::Devices::Sms::ISmsTextMessage>(message).Get(), &unmarshalledReturn));
    return WDSSmsEncodedLength_create(unmarshalledReturn);
}

- (NSString*)accountPhoneNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccountPhoneNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDSCellularClass)cellularClass {
    ABI::Windows::Devices::Sms::CellularClass unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_CellularClass(&unmarshalledReturn));
    return (WDSCellularClass)unmarshalledReturn;
}

- (WDSSmsDeviceMessageStore*)messageStore {
    ComPtr<ABI::Windows::Devices::Sms::ISmsDeviceMessageStore> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageStore(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSmsDeviceMessageStore>(unmarshalledReturn.Get());
}

- (WDSSmsDeviceStatus)deviceStatus {
    ABI::Windows::Devices::Sms::SmsDeviceStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceStatus(&unmarshalledReturn));
    return (WDSSmsDeviceStatus)unmarshalledReturn;
}

- (EventRegistrationToken)addSmsMessageReceivedEvent:(WDSSmsMessageReceivedEventHandler)eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_SmsMessageReceived(Make<WDSSmsMessageReceivedEventHandler_shim>(eventHandler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSmsMessageReceivedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SmsMessageReceived(eventCookie));
}

- (EventRegistrationToken)addSmsDeviceStatusChangedEvent:(WDSSmsDeviceStatusChangedEventHandler)eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_SmsDeviceStatusChanged(Make<WDSSmsDeviceStatusChangedEventHandler_shim>(eventHandler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSmsDeviceStatusChangedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SmsDeviceStatusChanged(eventCookie));
}

@end

@implementation WDSGetSmsDeviceOperation

// Failed to get type for default interface: Can't marshal Windows.Foundation.IAsyncOperation`1<Windows.Devices.Sms.SmsDevice>
// Could not find base class Windows.Foundation.IAsyncOperation`1<Windows.Devices.Sms.SmsDevice> type information
- (unsigned int)id {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFAsyncStatus)status {
    AsyncStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (unsigned)unmarshalledReturn;
}

- (HRESULT)errorCode {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorCode(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

- (void)cancel {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->Cancel());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDSSmsReceivedEventDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sms::ISmsReceivedEventDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsReceivedEventDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (unsigned int)messageIndex {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsReceivedEventDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageIndex(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDSSmsMessageClass)messageClass {
    ABI::Windows::Devices::Sms::SmsMessageClass unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsReceivedEventDetails2>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageClass(&unmarshalledReturn));
    return (WDSSmsMessageClass)unmarshalledReturn;
}

- (WDSSmsBinaryMessage*)binaryMessage {
    ComPtr<ABI::Windows::Devices::Sms::ISmsBinaryMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsReceivedEventDetails2>(self);
    THROW_NS_IF_FAILED(_comInst->get_BinaryMessage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSmsBinaryMessage>(unmarshalledReturn.Get());
}

@end

@implementation WDSSmsTextMessage2

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sms::ISmsTextMessage2> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Devices.Sms.SmsTextMessage2").Get(), &out));
    return [_createRtProxy<WDSSmsTextMessage2>(out.Get()) retain];
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (NSString*)to {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_To(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTo:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_To(nsStrToHstr(value).Get()));
}

- (NSString*)from {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_From(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)body {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Body(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setBody:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Body(nsStrToHstr(value).Get()));
}

- (WDSSmsEncoding)encoding {
    ABI::Windows::Devices::Sms::SmsEncoding unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Encoding(&unmarshalledReturn));
    return (WDSSmsEncoding)unmarshalledReturn;
}

- (void)setEncoding:(WDSSmsEncoding)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Encoding((ABI::Windows::Devices::Sms::SmsEncoding)value));
}

- (NSString*)callbackNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CallbackNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCallbackNumber:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_CallbackNumber(nsStrToHstr(value).Get()));
}

- (BOOL)isDeliveryNotificationEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDeliveryNotificationEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsDeliveryNotificationEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsDeliveryNotificationEnabled((boolean)value));
}

- (int)retryAttemptCount {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_RetryAttemptCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRetryAttemptCount:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->put_RetryAttemptCount(value));
}

- (int)teleserviceId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_TeleserviceId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)protocolId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsTextMessage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProtocolId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDSSmsMessageType)messageType {
    ABI::Windows::Devices::Sms::SmsMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageType(&unmarshalledReturn));
    return (WDSSmsMessageType)unmarshalledReturn;
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDSCellularClass)cellularClass {
    ABI::Windows::Devices::Sms::CellularClass unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_CellularClass(&unmarshalledReturn));
    return (WDSCellularClass)unmarshalledReturn;
}

- (WDSSmsMessageClass)messageClass {
    ABI::Windows::Devices::Sms::SmsMessageClass unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageClass(&unmarshalledReturn));
    return (WDSSmsMessageClass)unmarshalledReturn;
}

- (NSString*)simIccId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_SimIccId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDSSmsWapMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sms::ISmsWapMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsWapMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (NSString*)to {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsWapMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_To(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)from {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsWapMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_From(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)applicationId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsWapMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_ApplicationId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)contentType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsWapMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WSSIBuffer>*)binaryBody {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsWapMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_BinaryBody(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (NSMutableDictionary* /* NSString *, NSString * */)headers {
    ComPtr<IMap<HSTRING, HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsWapMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Headers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_NSString_NSString_create(unmarshalledReturn.Get());
}

- (WDSSmsMessageType)messageType {
    ABI::Windows::Devices::Sms::SmsMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageType(&unmarshalledReturn));
    return (WDSSmsMessageType)unmarshalledReturn;
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDSCellularClass)cellularClass {
    ABI::Windows::Devices::Sms::CellularClass unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_CellularClass(&unmarshalledReturn));
    return (WDSCellularClass)unmarshalledReturn;
}

- (WDSSmsMessageClass)messageClass {
    ABI::Windows::Devices::Sms::SmsMessageClass unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageClass(&unmarshalledReturn));
    return (WDSSmsMessageClass)unmarshalledReturn;
}

- (NSString*)simIccId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_SimIccId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDSSmsAppMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sms::ISmsAppMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Devices.Sms.SmsAppMessage").Get(), &out));
    return [_createRtProxy<WDSSmsAppMessage>(out.Get()) retain];
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsAppMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (NSString*)to {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsAppMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_To(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTo:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsAppMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_To(nsStrToHstr(value).Get()));
}

- (NSString*)from {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsAppMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_From(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)body {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsAppMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Body(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setBody:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsAppMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_Body(nsStrToHstr(value).Get()));
}

- (NSString*)callbackNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsAppMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_CallbackNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCallbackNumber:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsAppMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_CallbackNumber(nsStrToHstr(value).Get()));
}

- (BOOL)isDeliveryNotificationEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsAppMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDeliveryNotificationEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsDeliveryNotificationEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsAppMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsDeliveryNotificationEnabled((boolean)value));
}

- (int)retryAttemptCount {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsAppMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_RetryAttemptCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRetryAttemptCount:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsAppMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_RetryAttemptCount(value));
}

- (WDSSmsEncoding)encoding {
    ABI::Windows::Devices::Sms::SmsEncoding unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsAppMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Encoding(&unmarshalledReturn));
    return (WDSSmsEncoding)unmarshalledReturn;
}

- (void)setEncoding:(WDSSmsEncoding)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsAppMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_Encoding((ABI::Windows::Devices::Sms::SmsEncoding)value));
}

- (int)portNumber {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsAppMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_PortNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setPortNumber:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsAppMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_PortNumber(value));
}

- (int)teleserviceId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsAppMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_TeleserviceId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setTeleserviceId:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsAppMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_TeleserviceId(value));
}

- (int)protocolId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsAppMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProtocolId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setProtocolId:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsAppMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_ProtocolId(value));
}

- (RTObject<WSSIBuffer>*)binaryBody {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsAppMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_BinaryBody(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)setBinaryBody:(RTObject<WSSIBuffer>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsAppMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_BinaryBody(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(value).Get()));
}

- (WDSSmsMessageType)messageType {
    ABI::Windows::Devices::Sms::SmsMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageType(&unmarshalledReturn));
    return (WDSSmsMessageType)unmarshalledReturn;
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDSCellularClass)cellularClass {
    ABI::Windows::Devices::Sms::CellularClass unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_CellularClass(&unmarshalledReturn));
    return (WDSCellularClass)unmarshalledReturn;
}

- (WDSSmsMessageClass)messageClass {
    ABI::Windows::Devices::Sms::SmsMessageClass unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageClass(&unmarshalledReturn));
    return (WDSSmsMessageClass)unmarshalledReturn;
}

- (NSString*)simIccId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_SimIccId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDSSmsBroadcastMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sms::ISmsBroadcastMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsBroadcastMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (NSString*)to {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsBroadcastMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_To(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)body {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsBroadcastMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Body(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int)channel {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsBroadcastMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Channel(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDSSmsGeographicalScope)geographicalScope {
    ABI::Windows::Devices::Sms::SmsGeographicalScope unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsBroadcastMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_GeographicalScope(&unmarshalledReturn));
    return (WDSSmsGeographicalScope)unmarshalledReturn;
}

- (int)messageCode {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsBroadcastMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageCode(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)updateNumber {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsBroadcastMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_UpdateNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDSSmsBroadcastType)broadcastType {
    ABI::Windows::Devices::Sms::SmsBroadcastType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsBroadcastMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_BroadcastType(&unmarshalledReturn));
    return (WDSSmsBroadcastType)unmarshalledReturn;
}

- (BOOL)isEmergencyAlert {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsBroadcastMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsEmergencyAlert(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isUserPopupRequested {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsBroadcastMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsUserPopupRequested(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDSSmsMessageType)messageType {
    ABI::Windows::Devices::Sms::SmsMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageType(&unmarshalledReturn));
    return (WDSSmsMessageType)unmarshalledReturn;
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDSCellularClass)cellularClass {
    ABI::Windows::Devices::Sms::CellularClass unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_CellularClass(&unmarshalledReturn));
    return (WDSCellularClass)unmarshalledReturn;
}

- (WDSSmsMessageClass)messageClass {
    ABI::Windows::Devices::Sms::SmsMessageClass unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageClass(&unmarshalledReturn));
    return (WDSSmsMessageClass)unmarshalledReturn;
}

- (NSString*)simIccId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_SimIccId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDSSmsVoicemailMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sms::ISmsVoicemailMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsVoicemailMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (NSString*)to {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsVoicemailMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_To(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)body {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsVoicemailMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Body(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (id /* int */)messageCount {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsVoicemailMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageCount(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (WDSSmsMessageType)messageType {
    ABI::Windows::Devices::Sms::SmsMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageType(&unmarshalledReturn));
    return (WDSSmsMessageType)unmarshalledReturn;
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDSCellularClass)cellularClass {
    ABI::Windows::Devices::Sms::CellularClass unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_CellularClass(&unmarshalledReturn));
    return (WDSCellularClass)unmarshalledReturn;
}

- (WDSSmsMessageClass)messageClass {
    ABI::Windows::Devices::Sms::SmsMessageClass unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageClass(&unmarshalledReturn));
    return (WDSSmsMessageClass)unmarshalledReturn;
}

- (NSString*)simIccId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_SimIccId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDSSmsStatusMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sms::ISmsStatusMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)to {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsStatusMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_To(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)from {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsStatusMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_From(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)body {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsStatusMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Body(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int)status {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsStatusMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)messageReferenceNumber {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsStatusMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageReferenceNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFDateTime*)serviceCenterTimestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsStatusMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceCenterTimestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFDateTime*)dischargeTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsStatusMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_DischargeTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WDSSmsMessageType)messageType {
    ABI::Windows::Devices::Sms::SmsMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageType(&unmarshalledReturn));
    return (WDSSmsMessageType)unmarshalledReturn;
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDSCellularClass)cellularClass {
    ABI::Windows::Devices::Sms::CellularClass unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_CellularClass(&unmarshalledReturn));
    return (WDSCellularClass)unmarshalledReturn;
}

- (WDSSmsMessageClass)messageClass {
    ABI::Windows::Devices::Sms::SmsMessageClass unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageClass(&unmarshalledReturn));
    return (WDSSmsMessageClass)unmarshalledReturn;
}

- (NSString*)simIccId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_SimIccId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDSSmsSendMessageResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sms::ISmsSendMessageResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isSuccessful {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsSendMessageResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSuccessful(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* int */)messageReferenceNumbers {
    ComPtr<IVectorView<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsSendMessageResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageReferenceNumbers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_Int32_create(unmarshalledReturn.Get());
}

- (WDSCellularClass)cellularClass {
    ABI::Windows::Devices::Sms::CellularClass unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsSendMessageResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_CellularClass(&unmarshalledReturn));
    return (WDSCellularClass)unmarshalledReturn;
}

- (WDSSmsModemErrorCode)modemErrorCode {
    ABI::Windows::Devices::Sms::SmsModemErrorCode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsSendMessageResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ModemErrorCode(&unmarshalledReturn));
    return (WDSSmsModemErrorCode)unmarshalledReturn;
}

- (BOOL)isErrorTransient {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsSendMessageResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsErrorTransient(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (int)networkCauseCode {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsSendMessageResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkCauseCode(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)transportFailureCause {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsSendMessageResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransportFailureCause(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDSSmsDevice2

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sms::ISmsDevice2> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Sms::ISmsDevice2Statics> WDSISmsDevice2Statics_inst() {
    ComPtr<ABI::Windows::Devices::Sms::ISmsDevice2Statics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Sms.SmsDevice2").Get(), &inst));
    return inst;
}

+ (NSString*)getDeviceSelector {
    HSTRING unmarshalledReturn;
    auto _comInst = WDSISmsDevice2Statics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (WDSSmsDevice2*)fromId:(NSString*)deviceId {
    ComPtr<ABI::Windows::Devices::Sms::ISmsDevice2> unmarshalledReturn;
    auto _comInst = WDSISmsDevice2Statics_inst();
    THROW_NS_IF_FAILED(_comInst->FromId(nsStrToHstr(deviceId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSmsDevice2>(unmarshalledReturn.Get());
}

+ (WDSSmsDevice2*)getDefault {
    ComPtr<ABI::Windows::Devices::Sms::ISmsDevice2> unmarshalledReturn;
    auto _comInst = WDSISmsDevice2Statics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSmsDevice2>(unmarshalledReturn.Get());
}

+ (WDSSmsDevice2*)fromParentId:(NSString*)parentDeviceId {
    ComPtr<ABI::Windows::Devices::Sms::ISmsDevice2> unmarshalledReturn;
    auto _comInst = WDSISmsDevice2Statics_inst();
    THROW_NS_IF_FAILED(_comInst->FromParentId(nsStrToHstr(parentDeviceId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSmsDevice2>(unmarshalledReturn.Get());
}

- (NSString*)smscAddress {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SmscAddress(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSmscAddress:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice2>(self);
    THROW_NS_IF_FAILED(_comInst->put_SmscAddress(nsStrToHstr(value).Get()));
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice2>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)parentDeviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ParentDeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)accountPhoneNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccountPhoneNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDSCellularClass)cellularClass {
    ABI::Windows::Devices::Sms::CellularClass unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CellularClass(&unmarshalledReturn));
    return (WDSCellularClass)unmarshalledReturn;
}

- (WDSSmsDeviceStatus)deviceStatus {
    ABI::Windows::Devices::Sms::SmsDeviceStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice2>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceStatus(&unmarshalledReturn));
    return (WDSSmsDeviceStatus)unmarshalledReturn;
}

- (WDSSmsEncodedLength*)calculateLength:(RTObject<WDSISmsMessageBase>*)message {
    ABI::Windows::Devices::Sms::SmsEncodedLength unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice2>(self);
    THROW_NS_IF_FAILED(
        _comInst->CalculateLength(_getRtInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(message).Get(), &unmarshalledReturn));
    return WDSSmsEncodedLength_create(unmarshalledReturn);
}

- (void)sendMessageAndGetResultAsync:(RTObject<WDSISmsMessageBase>*)message
                             success:(void (^)(WDSSmsSendMessageResult*))success
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Sms::SmsSendMessageResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice2>(self);
    THROW_NS_IF_FAILED(_comInst->SendMessageAndGetResultAsync(_getRtInterface<ABI::Windows::Devices::Sms::ISmsMessageBase>(message).Get(),
                                                              &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Sms::SmsSendMessageResult*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Sms::SmsSendMessageResult*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Sms::ISmsSendMessageResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDSSmsSendMessageResult>(result.Get()));
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

- (EventRegistrationToken)addDeviceStatusChangedEvent:(void (^)(WDSSmsDevice2*, RTObject*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice2>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_DeviceStatusChanged(Make<ITypedEventHandler_Windows_Devices_Sms_SmsDevice2_System_Object>(eventHandler).Get(),
                                          &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDeviceStatusChangedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsDevice2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DeviceStatusChanged(eventCookie));
}

@end

@implementation WDSSmsMessageReceivedTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sms::ISmsMessageReceivedTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSSmsMessageType)messageType {
    ABI::Windows::Devices::Sms::SmsMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageReceivedTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageType(&unmarshalledReturn));
    return (WDSSmsMessageType)unmarshalledReturn;
}

- (WDSSmsTextMessage2*)textMessage {
    ComPtr<ABI::Windows::Devices::Sms::ISmsTextMessage2> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageReceivedTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_TextMessage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSmsTextMessage2>(unmarshalledReturn.Get());
}

- (WDSSmsWapMessage*)wapMessage {
    ComPtr<ABI::Windows::Devices::Sms::ISmsWapMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageReceivedTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_WapMessage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSmsWapMessage>(unmarshalledReturn.Get());
}

- (WDSSmsAppMessage*)appMessage {
    ComPtr<ABI::Windows::Devices::Sms::ISmsAppMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageReceivedTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppMessage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSmsAppMessage>(unmarshalledReturn.Get());
}

- (WDSSmsBroadcastMessage*)broadcastMessage {
    ComPtr<ABI::Windows::Devices::Sms::ISmsBroadcastMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageReceivedTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_BroadcastMessage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSmsBroadcastMessage>(unmarshalledReturn.Get());
}

- (WDSSmsVoicemailMessage*)voicemailMessage {
    ComPtr<ABI::Windows::Devices::Sms::ISmsVoicemailMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageReceivedTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_VoicemailMessage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSmsVoicemailMessage>(unmarshalledReturn.Get());
}

- (WDSSmsStatusMessage*)statusMessage {
    ComPtr<ABI::Windows::Devices::Sms::ISmsStatusMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageReceivedTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_StatusMessage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSmsStatusMessage>(unmarshalledReturn.Get());
}

- (void)drop {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageReceivedTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->Drop());
}

- (void)accept {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageReceivedTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->Accept());
}

@end

@implementation WDSSmsFilterRule

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sms::ISmsFilterRule> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Sms::ISmsFilterRuleFactory> WDSISmsFilterRuleFactory_inst() {
    ComPtr<ABI::Windows::Devices::Sms::ISmsFilterRuleFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Sms.SmsFilterRule").Get(), &inst));
    return inst;
}

+ (WDSSmsFilterRule*)makeFilterRule:(WDSSmsMessageType)messageType {
    ComPtr<ABI::Windows::Devices::Sms::ISmsFilterRule> unmarshalledReturn;
    auto _comInst = WDSISmsFilterRuleFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateFilterRule((ABI::Windows::Devices::Sms::SmsMessageType)messageType, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDSSmsFilterRule>(unmarshalledReturn.Get()) retain];
}

- (WDSSmsMessageType)messageType {
    ABI::Windows::Devices::Sms::SmsMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsFilterRule>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageType(&unmarshalledReturn));
    return (WDSSmsMessageType)unmarshalledReturn;
}

- (NSMutableArray* /* NSString * */)imsiPrefixes {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsFilterRule>(self);
    THROW_NS_IF_FAILED(_comInst->get_ImsiPrefixes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* NSString * */)deviceIds {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsFilterRule>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceIds(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* NSString * */)senderNumbers {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsFilterRule>(self);
    THROW_NS_IF_FAILED(_comInst->get_SenderNumbers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* NSString * */)textMessagePrefixes {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsFilterRule>(self);
    THROW_NS_IF_FAILED(_comInst->get_TextMessagePrefixes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* int */)portNumbers {
    ComPtr<IVector<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsFilterRule>(self);
    THROW_NS_IF_FAILED(_comInst->get_PortNumbers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_Int32_create(unmarshalledReturn.Get());
}

- (WDSCellularClass)cellularClass {
    ABI::Windows::Devices::Sms::CellularClass unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsFilterRule>(self);
    THROW_NS_IF_FAILED(_comInst->get_CellularClass(&unmarshalledReturn));
    return (WDSCellularClass)unmarshalledReturn;
}

- (void)setCellularClass:(WDSCellularClass)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsFilterRule>(self);
    THROW_NS_IF_FAILED(_comInst->put_CellularClass((ABI::Windows::Devices::Sms::CellularClass)value));
}

- (NSMutableArray* /* int */)protocolIds {
    ComPtr<IVector<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsFilterRule>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProtocolIds(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_Int32_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* int */)teleserviceIds {
    ComPtr<IVector<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsFilterRule>(self);
    THROW_NS_IF_FAILED(_comInst->get_TeleserviceIds(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_Int32_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* NSString * */)wapApplicationIds {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsFilterRule>(self);
    THROW_NS_IF_FAILED(_comInst->get_WapApplicationIds(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* NSString * */)wapContentTypes {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsFilterRule>(self);
    THROW_NS_IF_FAILED(_comInst->get_WapContentTypes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WDSSmsBroadcastType */)broadcastTypes {
    ComPtr<IVector<ABI::Windows::Devices::Sms::SmsBroadcastType>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsFilterRule>(self);
    THROW_NS_IF_FAILED(_comInst->get_BroadcastTypes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WDSSmsBroadcastType_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* int */)broadcastChannels {
    ComPtr<IVector<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsFilterRule>(self);
    THROW_NS_IF_FAILED(_comInst->get_BroadcastChannels(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_Int32_create(unmarshalledReturn.Get());
}

@end

@implementation WDSSmsFilterRules

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sms::ISmsFilterRules> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Sms::ISmsFilterRulesFactory> WDSISmsFilterRulesFactory_inst() {
    ComPtr<ABI::Windows::Devices::Sms::ISmsFilterRulesFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Sms.SmsFilterRules").Get(), &inst));
    return inst;
}

+ (WDSSmsFilterRules*)makeFilterRules:(WDSSmsFilterActionType)actionType {
    ComPtr<ABI::Windows::Devices::Sms::ISmsFilterRules> unmarshalledReturn;
    auto _comInst = WDSISmsFilterRulesFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateFilterRules((ABI::Windows::Devices::Sms::SmsFilterActionType)actionType, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDSSmsFilterRules>(unmarshalledReturn.Get()) retain];
}

- (WDSSmsFilterActionType)actionType {
    ABI::Windows::Devices::Sms::SmsFilterActionType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsFilterRules>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActionType(&unmarshalledReturn));
    return (WDSSmsFilterActionType)unmarshalledReturn;
}

- (NSMutableArray* /* WDSSmsFilterRule* */)rules {
    ComPtr<IVector<ABI::Windows::Devices::Sms::SmsFilterRule*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsFilterRules>(self);
    THROW_NS_IF_FAILED(_comInst->get_Rules(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WDSSmsFilterRule_create(unmarshalledReturn.Get());
}

@end

@implementation WDSSmsMessageRegistration

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sms::ISmsMessageRegistration> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Sms::ISmsMessageRegistrationStatics> WDSISmsMessageRegistrationStatics_inst() {
    ComPtr<ABI::Windows::Devices::Sms::ISmsMessageRegistrationStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Sms.SmsMessageRegistration").Get(), &inst));
    return inst;
}

+ (NSArray* /* WDSSmsMessageRegistration* */)allRegistrations {
    ComPtr<IVectorView<ABI::Windows::Devices::Sms::SmsMessageRegistration*>> unmarshalledReturn;
    auto _comInst = WDSISmsMessageRegistrationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AllRegistrations(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDSSmsMessageRegistration_create(unmarshalledReturn.Get());
}

+ (WDSSmsMessageRegistration*)Register:(NSString*)id filterRules:(WDSSmsFilterRules*)filterRules {
    ComPtr<ABI::Windows::Devices::Sms::ISmsMessageRegistration> unmarshalledReturn;
    auto _comInst = WDSISmsMessageRegistrationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Register(nsStrToHstr(id).Get(),
                                          _getRtInterface<ABI::Windows::Devices::Sms::ISmsFilterRules>(filterRules).Get(),
                                          unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSmsMessageRegistration>(unmarshalledReturn.Get());
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)unregister {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->Unregister());
}

- (EventRegistrationToken)addMessageReceivedEvent:(void (^)(WDSSmsMessageRegistration*, WDSSmsMessageReceivedTriggerDetails*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->add_MessageReceived(
        Make<ITypedEventHandler_Windows_Devices_Sms_SmsMessageRegistration_Windows_Devices_Sms_SmsMessageReceivedTriggerDetails>(
            eventHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeMessageReceivedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sms::ISmsMessageRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->remove_MessageReceived(eventCookie));
}

@end

@implementation WDSSmsEncodedLength {
    ABI::Windows::Devices::Sms::SmsEncodedLength structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Devices::Sms::SmsEncodedLength)s {
    WDSSmsEncodedLength* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Devices::Sms::SmsEncodedLength*)internalStruct {
    return &structVal;
}
- (unsigned int)segmentCount {
    return structVal.SegmentCount;
}
- (void)setSegmentCount:(unsigned int)val {
    structVal.SegmentCount = val;
}
- (unsigned int)characterCountLastSegment {
    return structVal.CharacterCountLastSegment;
}
- (void)setCharacterCountLastSegment:(unsigned int)val {
    structVal.CharacterCountLastSegment = val;
}
- (unsigned int)charactersPerSegment {
    return structVal.CharactersPerSegment;
}
- (void)setCharactersPerSegment:(unsigned int)val {
    structVal.CharactersPerSegment = val;
}
- (unsigned int)byteCountLastSegment {
    return structVal.ByteCountLastSegment;
}
- (void)setByteCountLastSegment:(unsigned int)val {
    structVal.ByteCountLastSegment = val;
}
- (unsigned int)bytesPerSegment {
    return structVal.BytesPerSegment;
}
- (void)setBytesPerSegment:(unsigned int)val {
    structVal.BytesPerSegment = val;
}
@end
id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<uint8_t, RTCArrayObj<uint8_t, uint8_t, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_Int32_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<int>, RTArrayObj<int, IVectorView<int>, int, int, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_RTObject_WDSISmsBinaryMessage_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Sms::ISmsBinaryMessage*>,
                                         RTArrayObj<ABI::Windows::Devices::Sms::ISmsBinaryMessage*,
                                                    IVectorView<ABI::Windows::Devices::Sms::ISmsBinaryMessage*>,
                                                    RTObject<WDSISmsBinaryMessage>,
                                                    ABI::Windows::Devices::Sms::ISmsBinaryMessage*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_RTObject_WDSISmsMessage_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Sms::ISmsMessage*>,
                                         RTArrayObj<ABI::Windows::Devices::Sms::ISmsMessage*,
                                                    IVectorView<ABI::Windows::Devices::Sms::ISmsMessage*>,
                                                    RTObject<WDSISmsMessage>,
                                                    ABI::Windows::Devices::Sms::ISmsMessage*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDSSmsMessageRegistration_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Sms::SmsMessageRegistration*>,
                                         RTArrayObj<ABI::Windows::Devices::Sms::ISmsMessageRegistration*,
                                                    IVectorView<ABI::Windows::Devices::Sms::SmsMessageRegistration*>,
                                                    WDSSmsMessageRegistration,
                                                    ABI::Windows::Devices::Sms::SmsMessageRegistration*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_Int32_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<int>, RTMutableArrayObj<int, IVector<int>, int, int, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_NSString_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<HSTRING>,
                               RTMutableArrayObj<HSTRING, IVector<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WDSSmsBroadcastType_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Devices::Sms::SmsBroadcastType>,
                                                RTMutableArrayObj<ABI::Windows::Devices::Sms::SmsBroadcastType,
                                                                  IVector<ABI::Windows::Devices::Sms::SmsBroadcastType>,
                                                                  WDSSmsBroadcastType,
                                                                  ABI::Windows::Devices::Sms::SmsBroadcastType,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WDSSmsFilterRule_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Devices::Sms::SmsFilterRule*>,
                                                RTMutableArrayObj<ABI::Windows::Devices::Sms::ISmsFilterRule*,
                                                                  IVector<ABI::Windows::Devices::Sms::SmsFilterRule*>,
                                                                  WDSSmsFilterRule,
                                                                  ABI::Windows::Devices::Sms::SmsFilterRule*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableDictionary_NSString_NSString_create(IInspectable* val) {
    std::unique_ptr<MutableDictionaryAdapter> adapter = std::make_unique<
        MutableDictionaryAdapterObj<IMap<HSTRING, HSTRING>,
                                    DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, HSTRING>>,
                                    RTMapObj<HSTRING,
                                             HSTRING,
                                             HSTRING,
                                             HSTRING,
                                             NSString,
                                             NSString,
                                             IMap<HSTRING, HSTRING>,
                                             dummyObjCCreator,
                                             dummyObjCCreator,
                                             dummyWRLCreator,
                                             dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}
