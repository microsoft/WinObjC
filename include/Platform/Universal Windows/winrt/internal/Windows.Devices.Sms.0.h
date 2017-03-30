// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Sms {

struct SmsEncodedLength;

}

namespace Windows::Devices::Sms {

using SmsEncodedLength = ABI::Windows::Devices::Sms::SmsEncodedLength;

}

namespace ABI::Windows::Devices::Sms {

struct ISmsAppMessage;
struct ISmsBinaryMessage;
struct ISmsBroadcastMessage;
struct ISmsDevice;
struct ISmsDevice2;
struct ISmsDevice2Statics;
struct ISmsDeviceMessageStore;
struct ISmsDeviceStatics;
struct ISmsDeviceStatics2;
struct ISmsFilterRule;
struct ISmsFilterRuleFactory;
struct ISmsFilterRules;
struct ISmsFilterRulesFactory;
struct ISmsMessage;
struct ISmsMessageBase;
struct ISmsMessageReceivedEventArgs;
struct ISmsMessageReceivedTriggerDetails;
struct ISmsMessageRegistration;
struct ISmsMessageRegistrationStatics;
struct ISmsReceivedEventDetails;
struct ISmsReceivedEventDetails2;
struct ISmsSendMessageResult;
struct ISmsStatusMessage;
struct ISmsTextMessage;
struct ISmsTextMessage2;
struct ISmsTextMessageStatics;
struct ISmsVoicemailMessage;
struct ISmsWapMessage;
struct SmsDeviceStatusChangedEventHandler;
struct SmsMessageReceivedEventHandler;
struct DeleteSmsMessageOperation;
struct DeleteSmsMessagesOperation;
struct GetSmsDeviceOperation;
struct GetSmsMessageOperation;
struct GetSmsMessagesOperation;
struct SendSmsMessageOperation;
struct SmsAppMessage;
struct SmsBinaryMessage;
struct SmsBroadcastMessage;
struct SmsDevice;
struct SmsDevice2;
struct SmsDeviceMessageStore;
struct SmsFilterRule;
struct SmsFilterRules;
struct SmsMessageReceivedEventArgs;
struct SmsMessageReceivedTriggerDetails;
struct SmsMessageRegistration;
struct SmsReceivedEventDetails;
struct SmsSendMessageResult;
struct SmsStatusMessage;
struct SmsTextMessage;
struct SmsTextMessage2;
struct SmsVoicemailMessage;
struct SmsWapMessage;

}

namespace Windows::Devices::Sms {

struct SmsDeviceStatusChangedEventHandler;
struct SmsMessageReceivedEventHandler;
struct ISmsAppMessage;
struct ISmsBinaryMessage;
struct ISmsBroadcastMessage;
struct ISmsDevice;
struct ISmsDevice2;
struct ISmsDevice2Statics;
struct ISmsDeviceMessageStore;
struct ISmsDeviceStatics;
struct ISmsDeviceStatics2;
struct ISmsFilterRule;
struct ISmsFilterRuleFactory;
struct ISmsFilterRules;
struct ISmsFilterRulesFactory;
struct ISmsMessage;
struct ISmsMessageBase;
struct ISmsMessageReceivedEventArgs;
struct ISmsMessageReceivedTriggerDetails;
struct ISmsMessageRegistration;
struct ISmsMessageRegistrationStatics;
struct ISmsReceivedEventDetails;
struct ISmsReceivedEventDetails2;
struct ISmsSendMessageResult;
struct ISmsStatusMessage;
struct ISmsTextMessage;
struct ISmsTextMessage2;
struct ISmsTextMessageStatics;
struct ISmsVoicemailMessage;
struct ISmsWapMessage;
struct DeleteSmsMessageOperation;
struct DeleteSmsMessagesOperation;
struct GetSmsDeviceOperation;
struct GetSmsMessageOperation;
struct GetSmsMessagesOperation;
struct SendSmsMessageOperation;
struct SmsAppMessage;
struct SmsBinaryMessage;
struct SmsBroadcastMessage;
struct SmsDevice;
struct SmsDevice2;
struct SmsDeviceMessageStore;
struct SmsFilterRule;
struct SmsFilterRules;
struct SmsMessageReceivedEventArgs;
struct SmsMessageReceivedTriggerDetails;
struct SmsMessageRegistration;
struct SmsReceivedEventDetails;
struct SmsSendMessageResult;
struct SmsStatusMessage;
struct SmsTextMessage;
struct SmsTextMessage2;
struct SmsVoicemailMessage;
struct SmsWapMessage;

}

namespace Windows::Devices::Sms {

template <typename T> struct impl_ISmsAppMessage;
template <typename T> struct impl_ISmsBinaryMessage;
template <typename T> struct impl_ISmsBroadcastMessage;
template <typename T> struct impl_ISmsDevice;
template <typename T> struct impl_ISmsDevice2;
template <typename T> struct impl_ISmsDevice2Statics;
template <typename T> struct impl_ISmsDeviceMessageStore;
template <typename T> struct impl_ISmsDeviceStatics;
template <typename T> struct impl_ISmsDeviceStatics2;
template <typename T> struct impl_ISmsFilterRule;
template <typename T> struct impl_ISmsFilterRuleFactory;
template <typename T> struct impl_ISmsFilterRules;
template <typename T> struct impl_ISmsFilterRulesFactory;
template <typename T> struct impl_ISmsMessage;
template <typename T> struct impl_ISmsMessageBase;
template <typename T> struct impl_ISmsMessageReceivedEventArgs;
template <typename T> struct impl_ISmsMessageReceivedTriggerDetails;
template <typename T> struct impl_ISmsMessageRegistration;
template <typename T> struct impl_ISmsMessageRegistrationStatics;
template <typename T> struct impl_ISmsReceivedEventDetails;
template <typename T> struct impl_ISmsReceivedEventDetails2;
template <typename T> struct impl_ISmsSendMessageResult;
template <typename T> struct impl_ISmsStatusMessage;
template <typename T> struct impl_ISmsTextMessage;
template <typename T> struct impl_ISmsTextMessage2;
template <typename T> struct impl_ISmsTextMessageStatics;
template <typename T> struct impl_ISmsVoicemailMessage;
template <typename T> struct impl_ISmsWapMessage;
template <typename T> struct impl_SmsDeviceStatusChangedEventHandler;
template <typename T> struct impl_SmsMessageReceivedEventHandler;

}

namespace Windows::Devices::Sms {

enum class CellularClass
{
    None = 0,
    Gsm = 1,
    Cdma = 2,
};

enum class SmsBroadcastType
{
    Other = 0,
    CmasPresidential = 1,
    CmasExtreme = 2,
    CmasSevere = 3,
    CmasAmber = 4,
    CmasTest = 5,
    EUAlert1 = 6,
    EUAlert2 = 7,
    EUAlert3 = 8,
    EUAlertAmber = 9,
    EUAlertInfo = 10,
    EtwsEarthquake = 11,
    EtwsTsunami = 12,
    EtwsTsunamiAndEarthquake = 13,
    LatAlertLocal = 14,
};

enum class SmsDataFormat
{
    Unknown = 0,
    CdmaSubmit = 1,
    GsmSubmit = 2,
    CdmaDeliver = 3,
    GsmDeliver = 4,
};

enum class SmsDeviceStatus
{
    Off = 0,
    Ready = 1,
    SimNotInserted = 2,
    BadSim = 3,
    DeviceFailure = 4,
    SubscriptionNotActivated = 5,
    DeviceLocked = 6,
    DeviceBlocked = 7,
};

enum class SmsEncoding
{
    Unknown = 0,
    Optimal = 1,
    SevenBitAscii = 2,
    Unicode = 3,
    GsmSevenBit = 4,
    EightBit = 5,
    Latin = 6,
    Korean = 7,
    IA5 = 8,
    ShiftJis = 9,
    LatinHebrew = 10,
};

enum class SmsFilterActionType
{
    AcceptImmediately = 0,
    Drop = 1,
    Peek = 2,
    Accept = 3,
};

enum class SmsGeographicalScope
{
    None = 0,
    CellWithImmediateDisplay = 1,
    LocationArea = 2,
    Plmn = 3,
    Cell = 4,
};

enum class SmsMessageClass
{
    None = 0,
    Class0 = 1,
    Class1 = 2,
    Class2 = 3,
    Class3 = 4,
};

enum class [[deprecated("SmsMessageFilter may be altered or unavailable for releases after Windows 10.")]] SmsMessageFilter
{
    All = 0,
    Unread = 1,
    Read = 2,
    Sent = 3,
    Draft = 4,
};

enum class SmsMessageType
{
    Binary = 0,
    Text = 1,
    Wap = 2,
    App = 3,
    Broadcast = 4,
    Voicemail = 5,
    Status = 6,
};

enum class SmsModemErrorCode
{
    Other = 0,
    MessagingNetworkError = 1,
    SmsOperationNotSupportedByDevice = 2,
    SmsServiceNotSupportedByNetwork = 3,
    DeviceFailure = 4,
    MessageNotEncodedProperly = 5,
    MessageTooLarge = 6,
    DeviceNotReady = 7,
    NetworkNotReady = 8,
    InvalidSmscAddress = 9,
    NetworkFailure = 10,
    FixedDialingNumberRestricted = 11,
};

}

}
