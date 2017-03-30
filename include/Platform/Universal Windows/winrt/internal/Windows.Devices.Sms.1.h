// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Devices.Sms.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Sms {

struct SmsEncodedLength
{
    uint32_t SegmentCount;
    uint32_t CharacterCountLastSegment;
    uint32_t CharactersPerSegment;
    uint32_t ByteCountLastSegment;
    uint32_t BytesPerSegment;
};

}

namespace Windows::Devices::Sms {

using SmsEncodedLength = ABI::Windows::Devices::Sms::SmsEncodedLength;

}

namespace ABI::Windows::Devices::Sms {

struct __declspec(uuid("e8bb8494-d3a0-4a0a-86d7-291033a8cf54")) __declspec(novtable) ISmsAppMessage : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_To(hstring * value) = 0;
    virtual HRESULT __stdcall put_To(hstring value) = 0;
    virtual HRESULT __stdcall get_From(hstring * value) = 0;
    virtual HRESULT __stdcall get_Body(hstring * value) = 0;
    virtual HRESULT __stdcall put_Body(hstring value) = 0;
    virtual HRESULT __stdcall get_CallbackNumber(hstring * value) = 0;
    virtual HRESULT __stdcall put_CallbackNumber(hstring value) = 0;
    virtual HRESULT __stdcall get_IsDeliveryNotificationEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsDeliveryNotificationEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_RetryAttemptCount(int32_t * value) = 0;
    virtual HRESULT __stdcall put_RetryAttemptCount(int32_t value) = 0;
    virtual HRESULT __stdcall get_Encoding(winrt::Windows::Devices::Sms::SmsEncoding * value) = 0;
    virtual HRESULT __stdcall put_Encoding(winrt::Windows::Devices::Sms::SmsEncoding value) = 0;
    virtual HRESULT __stdcall get_PortNumber(int32_t * value) = 0;
    virtual HRESULT __stdcall put_PortNumber(int32_t value) = 0;
    virtual HRESULT __stdcall get_TeleserviceId(int32_t * value) = 0;
    virtual HRESULT __stdcall put_TeleserviceId(int32_t value) = 0;
    virtual HRESULT __stdcall get_ProtocolId(int32_t * value) = 0;
    virtual HRESULT __stdcall put_ProtocolId(int32_t value) = 0;
    virtual HRESULT __stdcall get_BinaryBody(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall put_BinaryBody(Windows::Storage::Streams::IBuffer * value) = 0;
};

struct __declspec(uuid("5bf4e813-3b53-4c6e-b61a-d86a63755650")) __declspec(novtable) ISmsBinaryMessage : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Format(winrt::Windows::Devices::Sms::SmsDataFormat * value) = 0;
    virtual HRESULT __stdcall put_Format(winrt::Windows::Devices::Sms::SmsDataFormat value) = 0;
    virtual HRESULT __stdcall abi_GetData(uint32_t * __valueSize, uint8_t ** value) = 0;
    virtual HRESULT __stdcall abi_SetData(uint32_t __valueSize, uint8_t * value) = 0;
};

struct __declspec(uuid("75aebbf1-e4b7-4874-a09c-2956e592f957")) __declspec(novtable) ISmsBroadcastMessage : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_To(hstring * value) = 0;
    virtual HRESULT __stdcall get_Body(hstring * value) = 0;
    virtual HRESULT __stdcall get_Channel(int32_t * value) = 0;
    virtual HRESULT __stdcall get_GeographicalScope(winrt::Windows::Devices::Sms::SmsGeographicalScope * value) = 0;
    virtual HRESULT __stdcall get_MessageCode(int32_t * value) = 0;
    virtual HRESULT __stdcall get_UpdateNumber(int32_t * value) = 0;
    virtual HRESULT __stdcall get_BroadcastType(winrt::Windows::Devices::Sms::SmsBroadcastType * value) = 0;
    virtual HRESULT __stdcall get_IsEmergencyAlert(bool * value) = 0;
    virtual HRESULT __stdcall get_IsUserPopupRequested(bool * value) = 0;
};

struct __declspec(uuid("091791ed-872b-4eec-9c72-ab11627b34ec")) __declspec(novtable) ISmsDevice : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SendMessageAsync(Windows::Devices::Sms::ISmsMessage * message, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_CalculateLength(Windows::Devices::Sms::ISmsTextMessage * message, Windows::Devices::Sms::SmsEncodedLength * encodedLength) = 0;
    virtual HRESULT __stdcall get_AccountPhoneNumber(hstring * value) = 0;
    virtual HRESULT __stdcall get_CellularClass(winrt::Windows::Devices::Sms::CellularClass * value) = 0;
    virtual HRESULT __stdcall get_MessageStore(Windows::Devices::Sms::ISmsDeviceMessageStore ** value) = 0;
    virtual HRESULT __stdcall get_DeviceStatus(winrt::Windows::Devices::Sms::SmsDeviceStatus * value) = 0;
    virtual HRESULT __stdcall add_SmsMessageReceived(Windows::Devices::Sms::SmsMessageReceivedEventHandler * eventHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_SmsMessageReceived(event_token eventCookie) = 0;
    virtual HRESULT __stdcall add_SmsDeviceStatusChanged(Windows::Devices::Sms::SmsDeviceStatusChangedEventHandler * eventHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_SmsDeviceStatusChanged(event_token eventCookie) = 0;
};

struct __declspec(uuid("bd8a5c13-e522-46cb-b8d5-9ead30fb6c47")) __declspec(novtable) ISmsDevice2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SmscAddress(hstring * value) = 0;
    virtual HRESULT __stdcall put_SmscAddress(hstring value) = 0;
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_ParentDeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_AccountPhoneNumber(hstring * value) = 0;
    virtual HRESULT __stdcall get_CellularClass(winrt::Windows::Devices::Sms::CellularClass * value) = 0;
    virtual HRESULT __stdcall get_DeviceStatus(winrt::Windows::Devices::Sms::SmsDeviceStatus * value) = 0;
    virtual HRESULT __stdcall abi_CalculateLength(Windows::Devices::Sms::ISmsMessageBase * message, Windows::Devices::Sms::SmsEncodedLength * value) = 0;
    virtual HRESULT __stdcall abi_SendMessageAndGetResultAsync(Windows::Devices::Sms::ISmsMessageBase * message, Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::SmsSendMessageResult> ** asyncInfo) = 0;
    virtual HRESULT __stdcall add_DeviceStatusChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Sms::SmsDevice2, Windows::Foundation::IInspectable> * eventHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_DeviceStatusChanged(event_token eventCookie) = 0;
};

struct __declspec(uuid("65c78325-1031-491e-8fb6-ef9991afe363")) __declspec(novtable) ISmsDevice2Statics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeviceSelector(hstring * value) = 0;
    virtual HRESULT __stdcall abi_FromId(hstring deviceId, Windows::Devices::Sms::ISmsDevice2 ** value) = 0;
    virtual HRESULT __stdcall abi_GetDefault(Windows::Devices::Sms::ISmsDevice2 ** value) = 0;
    virtual HRESULT __stdcall abi_FromParentId(hstring parentDeviceId, Windows::Devices::Sms::ISmsDevice2 ** value) = 0;
};

struct __declspec(uuid("9889f253-f188-4427-8d54-ce0c2423c5c1")) __declspec(novtable) ISmsDeviceMessageStore : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_DeleteMessageAsync(uint32_t messageId, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_DeleteMessagesAsync(winrt::Windows::Devices::Sms::SmsMessageFilter messageFilter, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_GetMessageAsync(uint32_t messageId, Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::ISmsMessage> ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_GetMessagesAsync(winrt::Windows::Devices::Sms::SmsMessageFilter messageFilter, Windows::Foundation::IAsyncOperationWithProgress<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sms::ISmsMessage>, int32_t> ** asyncInfo) = 0;
    virtual HRESULT __stdcall get_MaxMessages(uint32_t * value) = 0;
};

struct __declspec(uuid("f88d07ea-d815-4dd1-a234-4520ce4604a4")) __declspec(novtable) ISmsDeviceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeviceSelector(hstring * phstrDeviceClassSelector) = 0;
    virtual HRESULT __stdcall abi_FromIdAsync(hstring deviceId, Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::SmsDevice> ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_GetDefaultAsync(Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::SmsDevice> ** asyncInfo) = 0;
};

struct __declspec(uuid("2ca11c87-0873-4caf-8a7d-bd471e8586d1")) __declspec(novtable) ISmsDeviceStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FromNetworkAccountIdAsync(hstring networkAccountId, Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::SmsDevice> ** asyncInfo) = 0;
};

struct __declspec(uuid("40e32fae-b049-4fbc-afe9-e2a610eff55c")) __declspec(novtable) ISmsFilterRule : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MessageType(winrt::Windows::Devices::Sms::SmsMessageType * value) = 0;
    virtual HRESULT __stdcall get_ImsiPrefixes(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_DeviceIds(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_SenderNumbers(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_TextMessagePrefixes(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_PortNumbers(Windows::Foundation::Collections::IVector<int32_t> ** value) = 0;
    virtual HRESULT __stdcall get_CellularClass(winrt::Windows::Devices::Sms::CellularClass * value) = 0;
    virtual HRESULT __stdcall put_CellularClass(winrt::Windows::Devices::Sms::CellularClass value) = 0;
    virtual HRESULT __stdcall get_ProtocolIds(Windows::Foundation::Collections::IVector<int32_t> ** value) = 0;
    virtual HRESULT __stdcall get_TeleserviceIds(Windows::Foundation::Collections::IVector<int32_t> ** value) = 0;
    virtual HRESULT __stdcall get_WapApplicationIds(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_WapContentTypes(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_BroadcastTypes(Windows::Foundation::Collections::IVector<winrt::Windows::Devices::Sms::SmsBroadcastType> ** value) = 0;
    virtual HRESULT __stdcall get_BroadcastChannels(Windows::Foundation::Collections::IVector<int32_t> ** value) = 0;
};

struct __declspec(uuid("00c36508-6296-4f29-9aad-8920ceba3ce8")) __declspec(novtable) ISmsFilterRuleFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateFilterRule(winrt::Windows::Devices::Sms::SmsMessageType messageType, Windows::Devices::Sms::ISmsFilterRule ** value) = 0;
};

struct __declspec(uuid("4e47eafb-79cd-4881-9894-55a4135b23fa")) __declspec(novtable) ISmsFilterRules : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ActionType(winrt::Windows::Devices::Sms::SmsFilterActionType * value) = 0;
    virtual HRESULT __stdcall get_Rules(Windows::Foundation::Collections::IVector<Windows::Devices::Sms::SmsFilterRule> ** value) = 0;
};

struct __declspec(uuid("a09924ed-6e2e-4530-9fde-465d02eed00e")) __declspec(novtable) ISmsFilterRulesFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateFilterRules(winrt::Windows::Devices::Sms::SmsFilterActionType actionType, Windows::Devices::Sms::ISmsFilterRules ** value) = 0;
};

struct __declspec(uuid("ed3c5e28-6984-4b07-811d-8d5906ed3cea")) __declspec(novtable) ISmsMessage : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_MessageClass(winrt::Windows::Devices::Sms::SmsMessageClass * value) = 0;
};

struct __declspec(uuid("2cf0fe30-fe50-4fc6-aa88-4ccfe27a29ea")) __declspec(novtable) ISmsMessageBase : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MessageType(winrt::Windows::Devices::Sms::SmsMessageType * value) = 0;
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_CellularClass(winrt::Windows::Devices::Sms::CellularClass * value) = 0;
    virtual HRESULT __stdcall get_MessageClass(winrt::Windows::Devices::Sms::SmsMessageClass * value) = 0;
    virtual HRESULT __stdcall get_SimIccId(hstring * value) = 0;
};

struct __declspec(uuid("08e80a98-b8e5-41c1-a3d8-d3abfae22675")) __declspec(novtable) ISmsMessageReceivedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TextMessage(Windows::Devices::Sms::ISmsTextMessage ** value) = 0;
    virtual HRESULT __stdcall get_BinaryMessage(Windows::Devices::Sms::ISmsBinaryMessage ** value) = 0;
};

struct __declspec(uuid("2bcfcbd4-2657-4128-ad5f-e3877132bdb1")) __declspec(novtable) ISmsMessageReceivedTriggerDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MessageType(winrt::Windows::Devices::Sms::SmsMessageType * value) = 0;
    virtual HRESULT __stdcall get_TextMessage(Windows::Devices::Sms::ISmsTextMessage2 ** value) = 0;
    virtual HRESULT __stdcall get_WapMessage(Windows::Devices::Sms::ISmsWapMessage ** value) = 0;
    virtual HRESULT __stdcall get_AppMessage(Windows::Devices::Sms::ISmsAppMessage ** value) = 0;
    virtual HRESULT __stdcall get_BroadcastMessage(Windows::Devices::Sms::ISmsBroadcastMessage ** value) = 0;
    virtual HRESULT __stdcall get_VoicemailMessage(Windows::Devices::Sms::ISmsVoicemailMessage ** value) = 0;
    virtual HRESULT __stdcall get_StatusMessage(Windows::Devices::Sms::ISmsStatusMessage ** value) = 0;
    virtual HRESULT __stdcall abi_Drop() = 0;
    virtual HRESULT __stdcall abi_Accept() = 0;
};

struct __declspec(uuid("1720503e-f34f-446b-83b3-0ff19923b409")) __declspec(novtable) ISmsMessageRegistration : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall abi_Unregister() = 0;
    virtual HRESULT __stdcall add_MessageReceived(Windows::Foundation::TypedEventHandler<Windows::Devices::Sms::SmsMessageRegistration, Windows::Devices::Sms::SmsMessageReceivedTriggerDetails> * eventHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_MessageReceived(event_token eventCookie) = 0;
};

struct __declspec(uuid("63a05464-2898-4778-a03c-6f994907d63a")) __declspec(novtable) ISmsMessageRegistrationStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AllRegistrations(Windows::Foundation::Collections::IVectorView<Windows::Devices::Sms::SmsMessageRegistration> ** value) = 0;
    virtual HRESULT __stdcall abi_Register(hstring id, Windows::Devices::Sms::ISmsFilterRules * filterRules, Windows::Devices::Sms::ISmsMessageRegistration ** value) = 0;
};

struct __declspec(uuid("5bb50f15-e46d-4c82-847d-5a0304c1d53d")) __declspec(novtable) ISmsReceivedEventDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_MessageIndex(uint32_t * value) = 0;
};

struct __declspec(uuid("40e05c86-a7b4-4771-9ae7-0b5ffb12c03a")) __declspec(novtable) ISmsReceivedEventDetails2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MessageClass(winrt::Windows::Devices::Sms::SmsMessageClass * value) = 0;
    virtual HRESULT __stdcall get_BinaryMessage(Windows::Devices::Sms::ISmsBinaryMessage ** value) = 0;
};

struct __declspec(uuid("db139af2-78c9-4feb-9622-452328088d62")) __declspec(novtable) ISmsSendMessageResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsSuccessful(bool * value) = 0;
    virtual HRESULT __stdcall get_MessageReferenceNumbers(Windows::Foundation::Collections::IVectorView<int32_t> ** value) = 0;
    virtual HRESULT __stdcall get_CellularClass(winrt::Windows::Devices::Sms::CellularClass * value) = 0;
    virtual HRESULT __stdcall get_ModemErrorCode(winrt::Windows::Devices::Sms::SmsModemErrorCode * value) = 0;
    virtual HRESULT __stdcall get_IsErrorTransient(bool * value) = 0;
    virtual HRESULT __stdcall get_NetworkCauseCode(int32_t * value) = 0;
    virtual HRESULT __stdcall get_TransportFailureCause(int32_t * value) = 0;
};

struct __declspec(uuid("e6d28342-b70b-4677-9379-c9783fdff8f4")) __declspec(novtable) ISmsStatusMessage : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_To(hstring * value) = 0;
    virtual HRESULT __stdcall get_From(hstring * value) = 0;
    virtual HRESULT __stdcall get_Body(hstring * value) = 0;
    virtual HRESULT __stdcall get_Status(int32_t * value) = 0;
    virtual HRESULT __stdcall get_MessageReferenceNumber(int32_t * value) = 0;
    virtual HRESULT __stdcall get_ServiceCenterTimestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_DischargeTime(Windows::Foundation::DateTime * value) = 0;
};

struct __declspec(uuid("d61c904c-a495-487f-9a6f-971548c5bc9f")) __declspec(novtable) ISmsTextMessage : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_PartReferenceId(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_PartNumber(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_PartCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_To(hstring * value) = 0;
    virtual HRESULT __stdcall put_To(hstring value) = 0;
    virtual HRESULT __stdcall get_From(hstring * value) = 0;
    virtual HRESULT __stdcall put_From(hstring value) = 0;
    virtual HRESULT __stdcall get_Body(hstring * value) = 0;
    virtual HRESULT __stdcall put_Body(hstring value) = 0;
    virtual HRESULT __stdcall get_Encoding(winrt::Windows::Devices::Sms::SmsEncoding * value) = 0;
    virtual HRESULT __stdcall put_Encoding(winrt::Windows::Devices::Sms::SmsEncoding value) = 0;
    virtual HRESULT __stdcall abi_ToBinaryMessages(winrt::Windows::Devices::Sms::SmsDataFormat format, Windows::Foundation::Collections::IVectorView<Windows::Devices::Sms::ISmsBinaryMessage> ** messages) = 0;
};

struct __declspec(uuid("22a0d893-4555-4755-b5a1-e7fd84955f8d")) __declspec(novtable) ISmsTextMessage2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_To(hstring * value) = 0;
    virtual HRESULT __stdcall put_To(hstring value) = 0;
    virtual HRESULT __stdcall get_From(hstring * value) = 0;
    virtual HRESULT __stdcall get_Body(hstring * value) = 0;
    virtual HRESULT __stdcall put_Body(hstring value) = 0;
    virtual HRESULT __stdcall get_Encoding(winrt::Windows::Devices::Sms::SmsEncoding * value) = 0;
    virtual HRESULT __stdcall put_Encoding(winrt::Windows::Devices::Sms::SmsEncoding value) = 0;
    virtual HRESULT __stdcall get_CallbackNumber(hstring * value) = 0;
    virtual HRESULT __stdcall put_CallbackNumber(hstring value) = 0;
    virtual HRESULT __stdcall get_IsDeliveryNotificationEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsDeliveryNotificationEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_RetryAttemptCount(int32_t * value) = 0;
    virtual HRESULT __stdcall put_RetryAttemptCount(int32_t value) = 0;
    virtual HRESULT __stdcall get_TeleserviceId(int32_t * value) = 0;
    virtual HRESULT __stdcall get_ProtocolId(int32_t * value) = 0;
};

struct __declspec(uuid("7f68c5ed-3ccc-47a3-8c55-380d3b010892")) __declspec(novtable) ISmsTextMessageStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FromBinaryMessage(Windows::Devices::Sms::ISmsBinaryMessage * binaryMessage, Windows::Devices::Sms::ISmsTextMessage ** textMessage) = 0;
    virtual HRESULT __stdcall abi_FromBinaryData(winrt::Windows::Devices::Sms::SmsDataFormat format, uint32_t __valueSize, uint8_t * value, Windows::Devices::Sms::ISmsTextMessage ** textMessage) = 0;
};

struct __declspec(uuid("271aa0a6-95b1-44ff-bcb8-b8fdd7e08bc3")) __declspec(novtable) ISmsVoicemailMessage : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_To(hstring * value) = 0;
    virtual HRESULT __stdcall get_Body(hstring * value) = 0;
    virtual HRESULT __stdcall get_MessageCount(Windows::Foundation::IReference<int32_t> ** value) = 0;
};

struct __declspec(uuid("cd937743-7a55-4d3b-9021-f22e022d09c5")) __declspec(novtable) ISmsWapMessage : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_To(hstring * value) = 0;
    virtual HRESULT __stdcall get_From(hstring * value) = 0;
    virtual HRESULT __stdcall get_ApplicationId(hstring * value) = 0;
    virtual HRESULT __stdcall get_ContentType(hstring * value) = 0;
    virtual HRESULT __stdcall get_BinaryBody(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall get_Headers(Windows::Foundation::Collections::IMap<hstring, hstring> ** value) = 0;
};

struct __declspec(uuid("982b1162-3dd7-4618-af89-0c272d5d06d8")) __declspec(novtable) SmsDeviceStatusChangedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Devices::Sms::ISmsDevice * sender) = 0;
};

struct __declspec(uuid("0b7ad409-ec2d-47ce-a253-732beeebcacd")) __declspec(novtable) SmsMessageReceivedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Devices::Sms::ISmsDevice * sender, Windows::Devices::Sms::ISmsMessageReceivedEventArgs * e) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::Sms::DeleteSmsMessageOperation> { using default_interface = Windows::Foundation::IAsyncAction; };
template <> struct traits<Windows::Devices::Sms::DeleteSmsMessagesOperation> { using default_interface = Windows::Foundation::IAsyncAction; };
template <> struct traits<Windows::Devices::Sms::GetSmsDeviceOperation> { using default_interface = Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::SmsDevice>; };
template <> struct traits<Windows::Devices::Sms::GetSmsMessageOperation> { using default_interface = Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::ISmsMessage>; };
template <> struct traits<Windows::Devices::Sms::GetSmsMessagesOperation> { using default_interface = Windows::Foundation::IAsyncOperationWithProgress<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sms::ISmsMessage>, int32_t>; };
template <> struct traits<Windows::Devices::Sms::SendSmsMessageOperation> { using default_interface = Windows::Foundation::IAsyncAction; };
template <> struct traits<Windows::Devices::Sms::SmsAppMessage> { using default_interface = Windows::Devices::Sms::ISmsAppMessage; };
template <> struct traits<Windows::Devices::Sms::SmsBinaryMessage> { using default_interface = Windows::Devices::Sms::ISmsBinaryMessage; };
template <> struct traits<Windows::Devices::Sms::SmsBroadcastMessage> { using default_interface = Windows::Devices::Sms::ISmsBroadcastMessage; };
template <> struct traits<Windows::Devices::Sms::SmsDevice> { using default_interface = Windows::Devices::Sms::ISmsDevice; };
template <> struct traits<Windows::Devices::Sms::SmsDevice2> { using default_interface = Windows::Devices::Sms::ISmsDevice2; };
template <> struct traits<Windows::Devices::Sms::SmsDeviceMessageStore> { using default_interface = Windows::Devices::Sms::ISmsDeviceMessageStore; };
template <> struct traits<Windows::Devices::Sms::SmsFilterRule> { using default_interface = Windows::Devices::Sms::ISmsFilterRule; };
template <> struct traits<Windows::Devices::Sms::SmsFilterRules> { using default_interface = Windows::Devices::Sms::ISmsFilterRules; };
template <> struct traits<Windows::Devices::Sms::SmsMessageReceivedEventArgs> { using default_interface = Windows::Devices::Sms::ISmsMessageReceivedEventArgs; };
template <> struct traits<Windows::Devices::Sms::SmsMessageReceivedTriggerDetails> { using default_interface = Windows::Devices::Sms::ISmsMessageReceivedTriggerDetails; };
template <> struct traits<Windows::Devices::Sms::SmsMessageRegistration> { using default_interface = Windows::Devices::Sms::ISmsMessageRegistration; };
template <> struct traits<Windows::Devices::Sms::SmsReceivedEventDetails> { using default_interface = Windows::Devices::Sms::ISmsReceivedEventDetails; };
template <> struct traits<Windows::Devices::Sms::SmsSendMessageResult> { using default_interface = Windows::Devices::Sms::ISmsSendMessageResult; };
template <> struct traits<Windows::Devices::Sms::SmsStatusMessage> { using default_interface = Windows::Devices::Sms::ISmsStatusMessage; };
template <> struct traits<Windows::Devices::Sms::SmsTextMessage> { using default_interface = Windows::Devices::Sms::ISmsTextMessage; };
template <> struct traits<Windows::Devices::Sms::SmsTextMessage2> { using default_interface = Windows::Devices::Sms::ISmsTextMessage2; };
template <> struct traits<Windows::Devices::Sms::SmsVoicemailMessage> { using default_interface = Windows::Devices::Sms::ISmsVoicemailMessage; };
template <> struct traits<Windows::Devices::Sms::SmsWapMessage> { using default_interface = Windows::Devices::Sms::ISmsWapMessage; };

}

namespace Windows::Devices::Sms {

template <typename D>
struct WINRT_EBO impl_ISmsAppMessage
{
    Windows::Foundation::DateTime Timestamp() const;
    hstring To() const;
    void To(hstring_view value) const;
    hstring From() const;
    hstring Body() const;
    void Body(hstring_view value) const;
    hstring CallbackNumber() const;
    void CallbackNumber(hstring_view value) const;
    bool IsDeliveryNotificationEnabled() const;
    void IsDeliveryNotificationEnabled(bool value) const;
    int32_t RetryAttemptCount() const;
    void RetryAttemptCount(int32_t value) const;
    Windows::Devices::Sms::SmsEncoding Encoding() const;
    void Encoding(Windows::Devices::Sms::SmsEncoding value) const;
    int32_t PortNumber() const;
    void PortNumber(int32_t value) const;
    int32_t TeleserviceId() const;
    void TeleserviceId(int32_t value) const;
    int32_t ProtocolId() const;
    void ProtocolId(int32_t value) const;
    Windows::Storage::Streams::IBuffer BinaryBody() const;
    void BinaryBody(const Windows::Storage::Streams::IBuffer & value) const;
};

template <typename D>
struct WINRT_EBO impl_ISmsBinaryMessage
{
    [[deprecated("SmsBinaryMessage may be altered or unavailable for releases after Windows 10. Instead, use SmsAppMessage.")]] Windows::Devices::Sms::SmsDataFormat Format() const;
    [[deprecated("SmsBinaryMessage may be altered or unavailable for releases after Windows 10. Instead, use SmsAppMessage.")]] void Format(Windows::Devices::Sms::SmsDataFormat value) const;
    [[deprecated("SmsBinaryMessage may be altered or unavailable for releases after Windows 10. Instead, use SmsAppMessage.")]] com_array<uint8_t> GetData() const;
    [[deprecated("SmsBinaryMessage may be altered or unavailable for releases after Windows 10. Instead, use SmsAppMessage.")]] void SetData(array_view<const uint8_t> value) const;
};

template <typename D>
struct WINRT_EBO impl_ISmsBroadcastMessage
{
    Windows::Foundation::DateTime Timestamp() const;
    hstring To() const;
    hstring Body() const;
    int32_t Channel() const;
    Windows::Devices::Sms::SmsGeographicalScope GeographicalScope() const;
    int32_t MessageCode() const;
    int32_t UpdateNumber() const;
    Windows::Devices::Sms::SmsBroadcastType BroadcastType() const;
    bool IsEmergencyAlert() const;
    bool IsUserPopupRequested() const;
};

template <typename D>
struct WINRT_EBO impl_ISmsDevice
{
    [[deprecated("SmsDevice may be altered or unavailable for releases after Windows 10. Instead, use SmsDevice2.")]] Windows::Devices::Sms::SendSmsMessageOperation SendMessageAsync(const Windows::Devices::Sms::ISmsMessage & message) const;
    [[deprecated("SmsDevice may be altered or unavailable for releases after Windows 10. Instead, use SmsDevice2.")]] Windows::Devices::Sms::SmsEncodedLength CalculateLength(const Windows::Devices::Sms::SmsTextMessage & message) const;
    [[deprecated("SmsDevice may be altered or unavailable for releases after Windows 10. Instead, use SmsDevice2.")]] hstring AccountPhoneNumber() const;
    [[deprecated("SmsDevice may be altered or unavailable for releases after Windows 10. Instead, use SmsDevice2.")]] Windows::Devices::Sms::CellularClass CellularClass() const;
    [[deprecated("SmsDevice may be altered or unavailable for releases after Windows 10. Instead, use SmsDevice2.")]] Windows::Devices::Sms::SmsDeviceMessageStore MessageStore() const;
    [[deprecated("SmsDevice may be altered or unavailable for releases after Windows 10. Instead, use SmsDevice2.")]] Windows::Devices::Sms::SmsDeviceStatus DeviceStatus() const;
    [[deprecated("SmsDevice may be altered or unavailable for releases after Windows 10. Instead, use SmsDevice2.")]] event_token SmsMessageReceived(const Windows::Devices::Sms::SmsMessageReceivedEventHandler & eventHandler) const;
    using SmsMessageReceived_revoker = event_revoker<ISmsDevice>;
    [[deprecated("SmsDevice may be altered or unavailable for releases after Windows 10. Instead, use SmsDevice2.")]] SmsMessageReceived_revoker SmsMessageReceived(auto_revoke_t, const Windows::Devices::Sms::SmsMessageReceivedEventHandler & eventHandler) const;
    [[deprecated("SmsDevice may be altered or unavailable for releases after Windows 10. Instead, use SmsDevice2.")]] void SmsMessageReceived(event_token eventCookie) const;
    [[deprecated("SmsDevice may be altered or unavailable for releases after Windows 10. Instead, use SmsDevice2.")]] event_token SmsDeviceStatusChanged(const Windows::Devices::Sms::SmsDeviceStatusChangedEventHandler & eventHandler) const;
    using SmsDeviceStatusChanged_revoker = event_revoker<ISmsDevice>;
    [[deprecated("SmsDevice may be altered or unavailable for releases after Windows 10. Instead, use SmsDevice2.")]] SmsDeviceStatusChanged_revoker SmsDeviceStatusChanged(auto_revoke_t, const Windows::Devices::Sms::SmsDeviceStatusChangedEventHandler & eventHandler) const;
    [[deprecated("SmsDevice may be altered or unavailable for releases after Windows 10. Instead, use SmsDevice2.")]] void SmsDeviceStatusChanged(event_token eventCookie) const;
};

template <typename D>
struct WINRT_EBO impl_ISmsDevice2
{
    hstring SmscAddress() const;
    void SmscAddress(hstring_view value) const;
    hstring DeviceId() const;
    hstring ParentDeviceId() const;
    hstring AccountPhoneNumber() const;
    Windows::Devices::Sms::CellularClass CellularClass() const;
    Windows::Devices::Sms::SmsDeviceStatus DeviceStatus() const;
    Windows::Devices::Sms::SmsEncodedLength CalculateLength(const Windows::Devices::Sms::ISmsMessageBase & message) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::SmsSendMessageResult> SendMessageAndGetResultAsync(const Windows::Devices::Sms::ISmsMessageBase & message) const;
    event_token DeviceStatusChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sms::SmsDevice2, Windows::Foundation::IInspectable> & eventHandler) const;
    using DeviceStatusChanged_revoker = event_revoker<ISmsDevice2>;
    DeviceStatusChanged_revoker DeviceStatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sms::SmsDevice2, Windows::Foundation::IInspectable> & eventHandler) const;
    void DeviceStatusChanged(event_token eventCookie) const;
};

template <typename D>
struct WINRT_EBO impl_ISmsDevice2Statics
{
    hstring GetDeviceSelector() const;
    Windows::Devices::Sms::SmsDevice2 FromId(hstring_view deviceId) const;
    Windows::Devices::Sms::SmsDevice2 GetDefault() const;
    Windows::Devices::Sms::SmsDevice2 FromParentId(hstring_view parentDeviceId) const;
};

template <typename D>
struct WINRT_EBO impl_ISmsDeviceMessageStore
{
    [[deprecated("SmsDeviceMessageStore may be altered or unavailable for releases after Windows 10.")]] Windows::Foundation::IAsyncAction DeleteMessageAsync(uint32_t messageId) const;
    [[deprecated("SmsDeviceMessageStore may be altered or unavailable for releases after Windows 10.")]] Windows::Foundation::IAsyncAction DeleteMessagesAsync(Windows::Devices::Sms::SmsMessageFilter messageFilter) const;
    [[deprecated("SmsDeviceMessageStore may be altered or unavailable for releases after Windows 10.")]] Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::ISmsMessage> GetMessageAsync(uint32_t messageId) const;
    [[deprecated("SmsDeviceMessageStore may be altered or unavailable for releases after Windows 10.")]] Windows::Foundation::IAsyncOperationWithProgress<Windows::Foundation::Collections::IVectorView<Windows::Devices::Sms::ISmsMessage>, int32_t> GetMessagesAsync(Windows::Devices::Sms::SmsMessageFilter messageFilter) const;
    [[deprecated("SmsDeviceMessageStore may be altered or unavailable for releases after Windows 10.")]] uint32_t MaxMessages() const;
};

template <typename D>
struct WINRT_EBO impl_ISmsDeviceStatics
{
    [[deprecated("ISmsDeviceStatics may be altered or unavailable for releases after Windows 10.")]] hstring GetDeviceSelector() const;
    [[deprecated("ISmsDeviceStatics may be altered or unavailable for releases after Windows 10.")]] Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::SmsDevice> FromIdAsync(hstring_view deviceId) const;
    [[deprecated("ISmsDeviceStatics may be altered or unavailable for releases after Windows 10.")]] Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::SmsDevice> GetDefaultAsync() const;
};

template <typename D>
struct WINRT_EBO impl_ISmsDeviceStatics2
{
    [[deprecated("ISmsDeviceStatics2 may be altered or unavailable for releases after Windows 10.")]] Windows::Foundation::IAsyncOperation<Windows::Devices::Sms::SmsDevice> FromNetworkAccountIdAsync(hstring_view networkAccountId) const;
};

template <typename D>
struct WINRT_EBO impl_ISmsFilterRule
{
    Windows::Devices::Sms::SmsMessageType MessageType() const;
    Windows::Foundation::Collections::IVector<hstring> ImsiPrefixes() const;
    Windows::Foundation::Collections::IVector<hstring> DeviceIds() const;
    Windows::Foundation::Collections::IVector<hstring> SenderNumbers() const;
    Windows::Foundation::Collections::IVector<hstring> TextMessagePrefixes() const;
    Windows::Foundation::Collections::IVector<int32_t> PortNumbers() const;
    Windows::Devices::Sms::CellularClass CellularClass() const;
    void CellularClass(Windows::Devices::Sms::CellularClass value) const;
    Windows::Foundation::Collections::IVector<int32_t> ProtocolIds() const;
    Windows::Foundation::Collections::IVector<int32_t> TeleserviceIds() const;
    Windows::Foundation::Collections::IVector<hstring> WapApplicationIds() const;
    Windows::Foundation::Collections::IVector<hstring> WapContentTypes() const;
    Windows::Foundation::Collections::IVector<winrt::Windows::Devices::Sms::SmsBroadcastType> BroadcastTypes() const;
    Windows::Foundation::Collections::IVector<int32_t> BroadcastChannels() const;
};

template <typename D>
struct WINRT_EBO impl_ISmsFilterRuleFactory
{
    Windows::Devices::Sms::SmsFilterRule CreateFilterRule(Windows::Devices::Sms::SmsMessageType messageType) const;
};

template <typename D>
struct WINRT_EBO impl_ISmsFilterRules
{
    Windows::Devices::Sms::SmsFilterActionType ActionType() const;
    Windows::Foundation::Collections::IVector<Windows::Devices::Sms::SmsFilterRule> Rules() const;
};

template <typename D>
struct WINRT_EBO impl_ISmsFilterRulesFactory
{
    Windows::Devices::Sms::SmsFilterRules CreateFilterRules(Windows::Devices::Sms::SmsFilterActionType actionType) const;
};

template <typename D>
struct WINRT_EBO impl_ISmsMessage
{
    uint32_t Id() const;
    Windows::Devices::Sms::SmsMessageClass MessageClass() const;
};

template <typename D>
struct WINRT_EBO impl_ISmsMessageBase
{
    Windows::Devices::Sms::SmsMessageType MessageType() const;
    hstring DeviceId() const;
    Windows::Devices::Sms::CellularClass CellularClass() const;
    Windows::Devices::Sms::SmsMessageClass MessageClass() const;
    hstring SimIccId() const;
};

template <typename D>
struct WINRT_EBO impl_ISmsMessageReceivedEventArgs
{
    [[deprecated("SmsMessageReceivedEventArgs may be altered or unavailable for releases after Windows 10.")]] Windows::Devices::Sms::SmsTextMessage TextMessage() const;
    [[deprecated("SmsMessageReceivedEventArgs may be altered or unavailable for releases after Windows 10.")]] Windows::Devices::Sms::SmsBinaryMessage BinaryMessage() const;
};

template <typename D>
struct WINRT_EBO impl_ISmsMessageReceivedTriggerDetails
{
    Windows::Devices::Sms::SmsMessageType MessageType() const;
    Windows::Devices::Sms::SmsTextMessage2 TextMessage() const;
    Windows::Devices::Sms::SmsWapMessage WapMessage() const;
    Windows::Devices::Sms::SmsAppMessage AppMessage() const;
    Windows::Devices::Sms::SmsBroadcastMessage BroadcastMessage() const;
    Windows::Devices::Sms::SmsVoicemailMessage VoicemailMessage() const;
    Windows::Devices::Sms::SmsStatusMessage StatusMessage() const;
    void Drop() const;
    void Accept() const;
};

template <typename D>
struct WINRT_EBO impl_ISmsMessageRegistration
{
    hstring Id() const;
    void Unregister() const;
    event_token MessageReceived(const Windows::Foundation::TypedEventHandler<Windows::Devices::Sms::SmsMessageRegistration, Windows::Devices::Sms::SmsMessageReceivedTriggerDetails> & eventHandler) const;
    using MessageReceived_revoker = event_revoker<ISmsMessageRegistration>;
    MessageReceived_revoker MessageReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Sms::SmsMessageRegistration, Windows::Devices::Sms::SmsMessageReceivedTriggerDetails> & eventHandler) const;
    void MessageReceived(event_token eventCookie) const;
};

template <typename D>
struct WINRT_EBO impl_ISmsMessageRegistrationStatics
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Sms::SmsMessageRegistration> AllRegistrations() const;
    Windows::Devices::Sms::SmsMessageRegistration Register(hstring_view id, const Windows::Devices::Sms::SmsFilterRules & filterRules) const;
};

template <typename D>
struct WINRT_EBO impl_ISmsReceivedEventDetails
{
    [[deprecated("SmsReceivedEventDetails may be altered or unavailable for releases after Windows 10. Instead, use SmsMessageReceivedTriggerDetails.")]] hstring DeviceId() const;
    [[deprecated("SmsReceivedEventDetails may be altered or unavailable for releases after Windows 10. Instead, use SmsMessageReceivedTriggerDetails.")]] uint32_t MessageIndex() const;
};

template <typename D>
struct WINRT_EBO impl_ISmsReceivedEventDetails2
{
    [[deprecated("SmsReceivedEventDetails may be altered or unavailable for releases after Windows 10. Instead, use SmsMessageReceivedTriggerDetails.")]] Windows::Devices::Sms::SmsMessageClass MessageClass() const;
    [[deprecated("SmsReceivedEventDetails may be altered or unavailable for releases after Windows 10. Instead, use SmsMessageReceivedTriggerDetails.")]] Windows::Devices::Sms::SmsBinaryMessage BinaryMessage() const;
};

template <typename D>
struct WINRT_EBO impl_ISmsSendMessageResult
{
    bool IsSuccessful() const;
    Windows::Foundation::Collections::IVectorView<int32_t> MessageReferenceNumbers() const;
    Windows::Devices::Sms::CellularClass CellularClass() const;
    Windows::Devices::Sms::SmsModemErrorCode ModemErrorCode() const;
    bool IsErrorTransient() const;
    int32_t NetworkCauseCode() const;
    int32_t TransportFailureCause() const;
};

template <typename D>
struct WINRT_EBO impl_ISmsStatusMessage
{
    hstring To() const;
    hstring From() const;
    hstring Body() const;
    int32_t Status() const;
    int32_t MessageReferenceNumber() const;
    Windows::Foundation::DateTime ServiceCenterTimestamp() const;
    Windows::Foundation::DateTime DischargeTime() const;
};

template <typename D>
struct WINRT_EBO impl_ISmsTextMessage
{
    [[deprecated("SmsTextMessage may be altered or unavailable for releases after Windows 10. Instead, use SmsTextMessage2.")]] Windows::Foundation::DateTime Timestamp() const;
    [[deprecated("SmsTextMessage may be altered or unavailable for releases after Windows 10. Instead, use SmsTextMessage2.")]] uint32_t PartReferenceId() const;
    [[deprecated("SmsTextMessage may be altered or unavailable for releases after Windows 10. Instead, use SmsTextMessage2.")]] uint32_t PartNumber() const;
    [[deprecated("SmsTextMessage may be altered or unavailable for releases after Windows 10. Instead, use SmsTextMessage2.")]] uint32_t PartCount() const;
    [[deprecated("SmsTextMessage may be altered or unavailable for releases after Windows 10. Instead, use SmsTextMessage2.")]] hstring To() const;
    [[deprecated("SmsTextMessage may be altered or unavailable for releases after Windows 10. Instead, use SmsTextMessage2.")]] void To(hstring_view value) const;
    [[deprecated("SmsTextMessage may be altered or unavailable for releases after Windows 10. Instead, use SmsTextMessage2.")]] hstring From() const;
    [[deprecated("SmsTextMessage may be altered or unavailable for releases after Windows 10. Instead, use SmsTextMessage2.")]] void From(hstring_view value) const;
    [[deprecated("SmsTextMessage may be altered or unavailable for releases after Windows 10. Instead, use SmsTextMessage2.")]] hstring Body() const;
    [[deprecated("SmsTextMessage may be altered or unavailable for releases after Windows 10. Instead, use SmsTextMessage2.")]] void Body(hstring_view value) const;
    [[deprecated("SmsTextMessage may be altered or unavailable for releases after Windows 10. Instead, use SmsTextMessage2.")]] Windows::Devices::Sms::SmsEncoding Encoding() const;
    [[deprecated("SmsTextMessage may be altered or unavailable for releases after Windows 10. Instead, use SmsTextMessage2.")]] void Encoding(Windows::Devices::Sms::SmsEncoding value) const;
    [[deprecated("SmsTextMessage may be altered or unavailable for releases after Windows 10. Instead, use SmsTextMessage2.")]] Windows::Foundation::Collections::IVectorView<Windows::Devices::Sms::ISmsBinaryMessage> ToBinaryMessages(Windows::Devices::Sms::SmsDataFormat format) const;
};

template <typename D>
struct WINRT_EBO impl_ISmsTextMessage2
{
    Windows::Foundation::DateTime Timestamp() const;
    hstring To() const;
    void To(hstring_view value) const;
    hstring From() const;
    hstring Body() const;
    void Body(hstring_view value) const;
    Windows::Devices::Sms::SmsEncoding Encoding() const;
    void Encoding(Windows::Devices::Sms::SmsEncoding value) const;
    hstring CallbackNumber() const;
    void CallbackNumber(hstring_view value) const;
    bool IsDeliveryNotificationEnabled() const;
    void IsDeliveryNotificationEnabled(bool value) const;
    int32_t RetryAttemptCount() const;
    void RetryAttemptCount(int32_t value) const;
    int32_t TeleserviceId() const;
    int32_t ProtocolId() const;
};

template <typename D>
struct WINRT_EBO impl_ISmsTextMessageStatics
{
    [[deprecated("ISmsTextMessageStatics may be altered or unavailable for releases after Windows 10.")]] Windows::Devices::Sms::SmsTextMessage FromBinaryMessage(const Windows::Devices::Sms::SmsBinaryMessage & binaryMessage) const;
    [[deprecated("ISmsTextMessageStatics may be altered or unavailable for releases after Windows 10.")]] Windows::Devices::Sms::SmsTextMessage FromBinaryData(Windows::Devices::Sms::SmsDataFormat format, array_view<const uint8_t> value) const;
};

template <typename D>
struct WINRT_EBO impl_ISmsVoicemailMessage
{
    Windows::Foundation::DateTime Timestamp() const;
    hstring To() const;
    hstring Body() const;
    Windows::Foundation::IReference<int32_t> MessageCount() const;
};

template <typename D>
struct WINRT_EBO impl_ISmsWapMessage
{
    Windows::Foundation::DateTime Timestamp() const;
    hstring To() const;
    hstring From() const;
    hstring ApplicationId() const;
    hstring ContentType() const;
    Windows::Storage::Streams::IBuffer BinaryBody() const;
    Windows::Foundation::Collections::IMap<hstring, hstring> Headers() const;
};

}

namespace impl {

template <> struct traits<Windows::Devices::Sms::ISmsAppMessage>
{
    using abi = ABI::Windows::Devices::Sms::ISmsAppMessage;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsAppMessage<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsBinaryMessage>
{
    using abi = ABI::Windows::Devices::Sms::ISmsBinaryMessage;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsBinaryMessage<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsBroadcastMessage>
{
    using abi = ABI::Windows::Devices::Sms::ISmsBroadcastMessage;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsBroadcastMessage<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsDevice>
{
    using abi = ABI::Windows::Devices::Sms::ISmsDevice;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsDevice<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsDevice2>
{
    using abi = ABI::Windows::Devices::Sms::ISmsDevice2;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsDevice2<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsDevice2Statics>
{
    using abi = ABI::Windows::Devices::Sms::ISmsDevice2Statics;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsDevice2Statics<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsDeviceMessageStore>
{
    using abi = ABI::Windows::Devices::Sms::ISmsDeviceMessageStore;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsDeviceMessageStore<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsDeviceStatics>
{
    using abi = ABI::Windows::Devices::Sms::ISmsDeviceStatics;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsDeviceStatics<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsDeviceStatics2>
{
    using abi = ABI::Windows::Devices::Sms::ISmsDeviceStatics2;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsDeviceStatics2<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsFilterRule>
{
    using abi = ABI::Windows::Devices::Sms::ISmsFilterRule;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsFilterRule<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsFilterRuleFactory>
{
    using abi = ABI::Windows::Devices::Sms::ISmsFilterRuleFactory;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsFilterRuleFactory<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsFilterRules>
{
    using abi = ABI::Windows::Devices::Sms::ISmsFilterRules;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsFilterRules<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsFilterRulesFactory>
{
    using abi = ABI::Windows::Devices::Sms::ISmsFilterRulesFactory;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsFilterRulesFactory<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsMessage>
{
    using abi = ABI::Windows::Devices::Sms::ISmsMessage;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsMessage<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsMessageBase>
{
    using abi = ABI::Windows::Devices::Sms::ISmsMessageBase;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsMessageBase<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsMessageReceivedEventArgs>
{
    using abi = ABI::Windows::Devices::Sms::ISmsMessageReceivedEventArgs;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsMessageReceivedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsMessageReceivedTriggerDetails>
{
    using abi = ABI::Windows::Devices::Sms::ISmsMessageReceivedTriggerDetails;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsMessageReceivedTriggerDetails<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsMessageRegistration>
{
    using abi = ABI::Windows::Devices::Sms::ISmsMessageRegistration;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsMessageRegistration<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsMessageRegistrationStatics>
{
    using abi = ABI::Windows::Devices::Sms::ISmsMessageRegistrationStatics;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsMessageRegistrationStatics<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsReceivedEventDetails>
{
    using abi = ABI::Windows::Devices::Sms::ISmsReceivedEventDetails;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsReceivedEventDetails<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsReceivedEventDetails2>
{
    using abi = ABI::Windows::Devices::Sms::ISmsReceivedEventDetails2;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsReceivedEventDetails2<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsSendMessageResult>
{
    using abi = ABI::Windows::Devices::Sms::ISmsSendMessageResult;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsSendMessageResult<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsStatusMessage>
{
    using abi = ABI::Windows::Devices::Sms::ISmsStatusMessage;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsStatusMessage<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsTextMessage>
{
    using abi = ABI::Windows::Devices::Sms::ISmsTextMessage;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsTextMessage<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsTextMessage2>
{
    using abi = ABI::Windows::Devices::Sms::ISmsTextMessage2;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsTextMessage2<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsTextMessageStatics>
{
    using abi = ABI::Windows::Devices::Sms::ISmsTextMessageStatics;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsTextMessageStatics<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsVoicemailMessage>
{
    using abi = ABI::Windows::Devices::Sms::ISmsVoicemailMessage;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsVoicemailMessage<D>;
};

template <> struct traits<Windows::Devices::Sms::ISmsWapMessage>
{
    using abi = ABI::Windows::Devices::Sms::ISmsWapMessage;
    template <typename D> using consume = Windows::Devices::Sms::impl_ISmsWapMessage<D>;
};

template <> struct traits<Windows::Devices::Sms::SmsDeviceStatusChangedEventHandler>
{
    using abi = ABI::Windows::Devices::Sms::SmsDeviceStatusChangedEventHandler;
};

template <> struct traits<Windows::Devices::Sms::SmsMessageReceivedEventHandler>
{
    using abi = ABI::Windows::Devices::Sms::SmsMessageReceivedEventHandler;
};

template <> struct traits<Windows::Devices::Sms::DeleteSmsMessageOperation>
{
    using abi = ABI::Windows::Devices::Sms::DeleteSmsMessageOperation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.DeleteSmsMessageOperation"; }
};

template <> struct traits<Windows::Devices::Sms::DeleteSmsMessagesOperation>
{
    using abi = ABI::Windows::Devices::Sms::DeleteSmsMessagesOperation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.DeleteSmsMessagesOperation"; }
};

template <> struct traits<Windows::Devices::Sms::GetSmsDeviceOperation>
{
    using abi = ABI::Windows::Devices::Sms::GetSmsDeviceOperation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.GetSmsDeviceOperation"; }
};

template <> struct traits<Windows::Devices::Sms::GetSmsMessageOperation>
{
    using abi = ABI::Windows::Devices::Sms::GetSmsMessageOperation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.GetSmsMessageOperation"; }
};

template <> struct traits<Windows::Devices::Sms::GetSmsMessagesOperation>
{
    using abi = ABI::Windows::Devices::Sms::GetSmsMessagesOperation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.GetSmsMessagesOperation"; }
};

template <> struct traits<Windows::Devices::Sms::SendSmsMessageOperation>
{
    using abi = ABI::Windows::Devices::Sms::SendSmsMessageOperation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SendSmsMessageOperation"; }
};

template <> struct traits<Windows::Devices::Sms::SmsAppMessage>
{
    using abi = ABI::Windows::Devices::Sms::SmsAppMessage;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsAppMessage"; }
};

template <> struct traits<Windows::Devices::Sms::SmsBinaryMessage>
{
    using abi = ABI::Windows::Devices::Sms::SmsBinaryMessage;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsBinaryMessage"; }
};

template <> struct traits<Windows::Devices::Sms::SmsBroadcastMessage>
{
    using abi = ABI::Windows::Devices::Sms::SmsBroadcastMessage;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsBroadcastMessage"; }
};

template <> struct traits<Windows::Devices::Sms::SmsDevice>
{
    using abi = ABI::Windows::Devices::Sms::SmsDevice;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsDevice"; }
};

template <> struct traits<Windows::Devices::Sms::SmsDevice2>
{
    using abi = ABI::Windows::Devices::Sms::SmsDevice2;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsDevice2"; }
};

template <> struct traits<Windows::Devices::Sms::SmsDeviceMessageStore>
{
    using abi = ABI::Windows::Devices::Sms::SmsDeviceMessageStore;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsDeviceMessageStore"; }
};

template <> struct traits<Windows::Devices::Sms::SmsFilterRule>
{
    using abi = ABI::Windows::Devices::Sms::SmsFilterRule;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsFilterRule"; }
};

template <> struct traits<Windows::Devices::Sms::SmsFilterRules>
{
    using abi = ABI::Windows::Devices::Sms::SmsFilterRules;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsFilterRules"; }
};

template <> struct traits<Windows::Devices::Sms::SmsMessageReceivedEventArgs>
{
    using abi = ABI::Windows::Devices::Sms::SmsMessageReceivedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsMessageReceivedEventArgs"; }
};

template <> struct traits<Windows::Devices::Sms::SmsMessageReceivedTriggerDetails>
{
    using abi = ABI::Windows::Devices::Sms::SmsMessageReceivedTriggerDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsMessageReceivedTriggerDetails"; }
};

template <> struct traits<Windows::Devices::Sms::SmsMessageRegistration>
{
    using abi = ABI::Windows::Devices::Sms::SmsMessageRegistration;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsMessageRegistration"; }
};

template <> struct traits<Windows::Devices::Sms::SmsReceivedEventDetails>
{
    using abi = ABI::Windows::Devices::Sms::SmsReceivedEventDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsReceivedEventDetails"; }
};

template <> struct traits<Windows::Devices::Sms::SmsSendMessageResult>
{
    using abi = ABI::Windows::Devices::Sms::SmsSendMessageResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsSendMessageResult"; }
};

template <> struct traits<Windows::Devices::Sms::SmsStatusMessage>
{
    using abi = ABI::Windows::Devices::Sms::SmsStatusMessage;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsStatusMessage"; }
};

template <> struct traits<Windows::Devices::Sms::SmsTextMessage>
{
    using abi = ABI::Windows::Devices::Sms::SmsTextMessage;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsTextMessage"; }
};

template <> struct traits<Windows::Devices::Sms::SmsTextMessage2>
{
    using abi = ABI::Windows::Devices::Sms::SmsTextMessage2;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsTextMessage2"; }
};

template <> struct traits<Windows::Devices::Sms::SmsVoicemailMessage>
{
    using abi = ABI::Windows::Devices::Sms::SmsVoicemailMessage;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsVoicemailMessage"; }
};

template <> struct traits<Windows::Devices::Sms::SmsWapMessage>
{
    using abi = ABI::Windows::Devices::Sms::SmsWapMessage;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Sms.SmsWapMessage"; }
};

}

}
