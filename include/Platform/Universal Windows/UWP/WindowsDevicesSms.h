//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

// WindowsDevicesSms.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WDSSmsTextMessage2, WDSSmsWapMessage, WDSSmsAppMessage, WDSSmsBroadcastMessage, WDSSmsVoicemailMessage, WDSSmsStatusMessage,
    WDSSmsSendMessageResult, WDSSmsDevice2, WDSSmsMessageReceivedTriggerDetails, WDSSmsFilterRule, WDSSmsFilterRules,
    WDSSmsMessageRegistration;
@class WDSSmsEncodedLength;
@protocol WDSISmsMessageBase
, WDSISmsTextMessage2, WDSISmsWapMessage, WDSISmsAppMessage, WDSISmsBroadcastMessage, WDSISmsVoicemailMessage, WDSISmsStatusMessage,
    WDSISmsSendMessageResult, WDSISmsDevice2Statics, WDSISmsDevice2, WDSISmsMessageReceivedTriggerDetails, WDSISmsFilterRule,
    WDSISmsFilterRuleFactory, WDSISmsFilterRules, WDSISmsFilterRulesFactory, WDSISmsMessageRegistrationStatics, WDSISmsMessageRegistration;

// Windows.Devices.Sms.SmsMessageClass
enum _WDSSmsMessageClass {
    WDSSmsMessageClassNone = 0,
    WDSSmsMessageClassClass0 = 1,
    WDSSmsMessageClassClass1 = 2,
    WDSSmsMessageClassClass2 = 3,
    WDSSmsMessageClassClass3 = 4,
};
typedef unsigned WDSSmsMessageClass;

// Windows.Devices.Sms.SmsMessageType
enum _WDSSmsMessageType {
    WDSSmsMessageTypeBinary = 0,
    WDSSmsMessageTypeText = 1,
    WDSSmsMessageTypeWap = 2,
    WDSSmsMessageTypeApp = 3,
    WDSSmsMessageTypeBroadcast = 4,
    WDSSmsMessageTypeVoicemail = 5,
    WDSSmsMessageTypeStatus = 6,
};
typedef unsigned WDSSmsMessageType;

// Windows.Devices.Sms.CellularClass
enum _WDSCellularClass {
    WDSCellularClassNone = 0,
    WDSCellularClassGsm = 1,
    WDSCellularClassCdma = 2,
};
typedef unsigned WDSCellularClass;

// Windows.Devices.Sms.SmsDataFormat
enum _WDSSmsDataFormat {
    WDSSmsDataFormatUnknown = 0,
    WDSSmsDataFormatCdmaSubmit = 1,
    WDSSmsDataFormatGsmSubmit = 2,
    WDSSmsDataFormatCdmaDeliver = 3,
    WDSSmsDataFormatGsmDeliver = 4,
};
typedef unsigned WDSSmsDataFormat;

// Windows.Devices.Sms.SmsEncoding
enum _WDSSmsEncoding {
    WDSSmsEncodingUnknown = 0,
    WDSSmsEncodingOptimal = 1,
    WDSSmsEncodingSevenBitAscii = 2,
    WDSSmsEncodingUnicode = 3,
    WDSSmsEncodingGsmSevenBit = 4,
    WDSSmsEncodingEightBit = 5,
    WDSSmsEncodingLatin = 6,
    WDSSmsEncodingKorean = 7,
    WDSSmsEncodingIA5 = 8,
    WDSSmsEncodingShiftJis = 9,
    WDSSmsEncodingLatinHebrew = 10,
};
typedef unsigned WDSSmsEncoding;

// Windows.Devices.Sms.SmsGeographicalScope
enum _WDSSmsGeographicalScope {
    WDSSmsGeographicalScopeNone = 0,
    WDSSmsGeographicalScopeCellWithImmediateDisplay = 1,
    WDSSmsGeographicalScopeLocationArea = 2,
    WDSSmsGeographicalScopePlmn = 3,
    WDSSmsGeographicalScopeCell = 4,
};
typedef unsigned WDSSmsGeographicalScope;

// Windows.Devices.Sms.SmsBroadcastType
enum _WDSSmsBroadcastType {
    WDSSmsBroadcastTypeOther = 0,
    WDSSmsBroadcastTypeCmasPresidential = 1,
    WDSSmsBroadcastTypeCmasExtreme = 2,
    WDSSmsBroadcastTypeCmasSevere = 3,
    WDSSmsBroadcastTypeCmasAmber = 4,
    WDSSmsBroadcastTypeCmasTest = 5,
    WDSSmsBroadcastTypeEUAlert1 = 6,
    WDSSmsBroadcastTypeEUAlert2 = 7,
    WDSSmsBroadcastTypeEUAlert3 = 8,
    WDSSmsBroadcastTypeEUAlertAmber = 9,
    WDSSmsBroadcastTypeEUAlertInfo = 10,
    WDSSmsBroadcastTypeEtwsEarthquake = 11,
    WDSSmsBroadcastTypeEtwsTsunami = 12,
    WDSSmsBroadcastTypeEtwsTsunamiAndEarthquake = 13,
    WDSSmsBroadcastTypeLatAlertLocal = 14,
};
typedef unsigned WDSSmsBroadcastType;

// Windows.Devices.Sms.SmsDeviceStatus
enum _WDSSmsDeviceStatus {
    WDSSmsDeviceStatusOff = 0,
    WDSSmsDeviceStatusReady = 1,
    WDSSmsDeviceStatusSimNotInserted = 2,
    WDSSmsDeviceStatusBadSim = 3,
    WDSSmsDeviceStatusDeviceFailure = 4,
    WDSSmsDeviceStatusSubscriptionNotActivated = 5,
    WDSSmsDeviceStatusDeviceLocked = 6,
    WDSSmsDeviceStatusDeviceBlocked = 7,
};
typedef unsigned WDSSmsDeviceStatus;

// Windows.Devices.Sms.SmsModemErrorCode
enum _WDSSmsModemErrorCode {
    WDSSmsModemErrorCodeOther = 0,
    WDSSmsModemErrorCodeMessagingNetworkError = 1,
    WDSSmsModemErrorCodeSmsOperationNotSupportedByDevice = 2,
    WDSSmsModemErrorCodeSmsServiceNotSupportedByNetwork = 3,
    WDSSmsModemErrorCodeDeviceFailure = 4,
    WDSSmsModemErrorCodeMessageNotEncodedProperly = 5,
    WDSSmsModemErrorCodeMessageTooLarge = 6,
    WDSSmsModemErrorCodeDeviceNotReady = 7,
    WDSSmsModemErrorCodeNetworkNotReady = 8,
    WDSSmsModemErrorCodeInvalidSmscAddress = 9,
    WDSSmsModemErrorCodeNetworkFailure = 10,
    WDSSmsModemErrorCodeFixedDialingNumberRestricted = 11,
};
typedef unsigned WDSSmsModemErrorCode;

// Windows.Devices.Sms.SmsFilterActionType
enum _WDSSmsFilterActionType {
    WDSSmsFilterActionTypeAcceptImmediately = 0,
    WDSSmsFilterActionTypeDrop = 1,
    WDSSmsFilterActionTypePeek = 2,
    WDSSmsFilterActionTypeAccept = 3,
};
typedef unsigned WDSSmsFilterActionType;

#include "WindowsFoundationCollections.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// [struct] Windows.Devices.Sms.SmsEncodedLength
WINRT_EXPORT
@interface WDSSmsEncodedLength : NSObject
+ (instancetype) new;
@property unsigned int segmentCount;
@property unsigned int characterCountLastSegment;
@property unsigned int charactersPerSegment;
@property unsigned int byteCountLastSegment;
@property unsigned int bytesPerSegment;
@end

// Windows.Devices.Sms.ISmsMessageBase
#ifndef __WDSISmsMessageBase_DEFINED__
#define __WDSISmsMessageBase_DEFINED__

@protocol WDSISmsMessageBase
@property (readonly) WDSCellularClass cellularClass;
@property (readonly) NSString* deviceId;
@property (readonly) WDSSmsMessageClass messageClass;
@property (readonly) WDSSmsMessageType messageType;
@property (readonly) NSString* simIccId;
@end

#endif // __WDSISmsMessageBase_DEFINED__

// Windows.Devices.Sms.SmsTextMessage2
#ifndef __WDSSmsTextMessage2_DEFINED__
#define __WDSSmsTextMessage2_DEFINED__

WINRT_EXPORT
@interface WDSSmsTextMessage2 : RTObject <WDSISmsMessageBase>
+ (instancetype)create ACTIVATOR;
@property (readonly) WDSSmsMessageType messageType;
@property (readonly) NSString* deviceId;
@property (readonly) WDSCellularClass cellularClass;
@property (readonly) WDSSmsMessageClass messageClass;
@property (readonly) NSString* simIccId;
@property int retryAttemptCount;
@property (copy) NSString* to;
@property BOOL isDeliveryNotificationEnabled;
@property WDSSmsEncoding encoding;
@property (copy) NSString* callbackNumber;
@property (copy) NSString* body;
@property (readonly) int protocolId;
@property (readonly) NSString* from;
@property (readonly) WFDateTime* timestamp;
@property (readonly) int teleserviceId;
@end

#endif // __WDSSmsTextMessage2_DEFINED__

// Windows.Devices.Sms.SmsWapMessage
#ifndef __WDSSmsWapMessage_DEFINED__
#define __WDSSmsWapMessage_DEFINED__

WINRT_EXPORT
@interface WDSSmsWapMessage : RTObject <WDSISmsMessageBase>
@property (readonly) WDSCellularClass cellularClass;
@property (readonly) NSString* deviceId;
@property (readonly) WDSSmsMessageClass messageClass;
@property (readonly) WDSSmsMessageType messageType;
@property (readonly) NSString* simIccId;
@property (readonly) WFDateTime* timestamp;
@property (readonly) NSString* applicationId;
@property (readonly) RTObject<WSSIBuffer>* binaryBody;
@property (readonly) NSString* contentType;
@property (readonly) NSString* from;
@property (readonly) NSMutableDictionary* headers;
@property (readonly) NSString* to;
@end

#endif // __WDSSmsWapMessage_DEFINED__

// Windows.Devices.Sms.SmsAppMessage
#ifndef __WDSSmsAppMessage_DEFINED__
#define __WDSSmsAppMessage_DEFINED__

WINRT_EXPORT
@interface WDSSmsAppMessage : RTObject <WDSISmsMessageBase>
+ (instancetype)create ACTIVATOR;
@property int protocolId;
@property int portNumber;
@property BOOL isDeliveryNotificationEnabled;
@property int retryAttemptCount;
@property WDSSmsEncoding encoding;
@property (copy) NSString* callbackNumber;
@property (copy) NSString* body;
@property (copy) RTObject<WSSIBuffer>* binaryBody;
@property (copy) NSString* to;
@property int teleserviceId;
@property (readonly) NSString* from;
@property (readonly) WFDateTime* timestamp;
@property (readonly) WDSCellularClass cellularClass;
@property (readonly) NSString* deviceId;
@property (readonly) WDSSmsMessageClass messageClass;
@property (readonly) WDSSmsMessageType messageType;
@property (readonly) NSString* simIccId;
@end

#endif // __WDSSmsAppMessage_DEFINED__

// Windows.Devices.Sms.SmsBroadcastMessage
#ifndef __WDSSmsBroadcastMessage_DEFINED__
#define __WDSSmsBroadcastMessage_DEFINED__

WINRT_EXPORT
@interface WDSSmsBroadcastMessage : RTObject <WDSISmsMessageBase>
@property (readonly) NSString* body;
@property (readonly) WDSSmsBroadcastType broadcastType;
@property (readonly) int channel;
@property (readonly) WDSSmsGeographicalScope geographicalScope;
@property (readonly) BOOL isEmergencyAlert;
@property (readonly) BOOL isUserPopupRequested;
@property (readonly) int messageCode;
@property (readonly) WFDateTime* timestamp;
@property (readonly) NSString* to;
@property (readonly) int updateNumber;
@property (readonly) WDSCellularClass cellularClass;
@property (readonly) NSString* deviceId;
@property (readonly) WDSSmsMessageClass messageClass;
@property (readonly) WDSSmsMessageType messageType;
@property (readonly) NSString* simIccId;
@end

#endif // __WDSSmsBroadcastMessage_DEFINED__

// Windows.Devices.Sms.SmsVoicemailMessage
#ifndef __WDSSmsVoicemailMessage_DEFINED__
#define __WDSSmsVoicemailMessage_DEFINED__

WINRT_EXPORT
@interface WDSSmsVoicemailMessage : RTObject <WDSISmsMessageBase>
@property (readonly) WDSCellularClass cellularClass;
@property (readonly) NSString* deviceId;
@property (readonly) WDSSmsMessageClass messageClass;
@property (readonly) WDSSmsMessageType messageType;
@property (readonly) NSString* simIccId;
@property (readonly) NSString* body;
@property (readonly) id messageCount;
@property (readonly) WFDateTime* timestamp;
@property (readonly) NSString* to;
@end

#endif // __WDSSmsVoicemailMessage_DEFINED__

// Windows.Devices.Sms.SmsStatusMessage
#ifndef __WDSSmsStatusMessage_DEFINED__
#define __WDSSmsStatusMessage_DEFINED__

WINRT_EXPORT
@interface WDSSmsStatusMessage : RTObject <WDSISmsMessageBase>
@property (readonly) WDSCellularClass cellularClass;
@property (readonly) NSString* deviceId;
@property (readonly) WDSSmsMessageClass messageClass;
@property (readonly) WDSSmsMessageType messageType;
@property (readonly) NSString* simIccId;
@property (readonly) int status;
@property (readonly) NSString* body;
@property (readonly) WFDateTime* dischargeTime;
@property (readonly) NSString* from;
@property (readonly) int messageReferenceNumber;
@property (readonly) WFDateTime* serviceCenterTimestamp;
@property (readonly) NSString* to;
@end

#endif // __WDSSmsStatusMessage_DEFINED__

// Windows.Devices.Sms.SmsSendMessageResult
#ifndef __WDSSmsSendMessageResult_DEFINED__
#define __WDSSmsSendMessageResult_DEFINED__

WINRT_EXPORT
@interface WDSSmsSendMessageResult : RTObject
@property (readonly) WDSCellularClass cellularClass;
@property (readonly) BOOL isErrorTransient;
@property (readonly) BOOL isSuccessful;
@property (readonly) NSArray* messageReferenceNumbers;
@property (readonly) WDSSmsModemErrorCode modemErrorCode;
@property (readonly) int networkCauseCode;
@property (readonly) int transportFailureCause;
@end

#endif // __WDSSmsSendMessageResult_DEFINED__

// Windows.Devices.Sms.SmsDevice2
#ifndef __WDSSmsDevice2_DEFINED__
#define __WDSSmsDevice2_DEFINED__

WINRT_EXPORT
@interface WDSSmsDevice2 : RTObject
+ (NSString*)getDeviceSelector;
+ (WDSSmsDevice2*)fromId:(NSString*)deviceId;
+ (WDSSmsDevice2*)getDefault;
+ (WDSSmsDevice2*)fromParentId:(NSString*)parentDeviceId;
@property (copy) NSString* smscAddress;
@property (readonly) NSString* accountPhoneNumber;
@property (readonly) WDSCellularClass cellularClass;
@property (readonly) NSString* deviceId;
@property (readonly) WDSSmsDeviceStatus deviceStatus;
@property (readonly) NSString* parentDeviceId;
- (EventRegistrationToken)addDeviceStatusChangedEvent:(void (^)(WDSSmsDevice2*, RTObject*))del;
- (void)removeDeviceStatusChangedEvent:(EventRegistrationToken)tok;
- (WDSSmsEncodedLength*)calculateLength:(RTObject<WDSISmsMessageBase>*)message;
- (void)sendMessageAndGetResultAsync:(RTObject<WDSISmsMessageBase>*)message
                             success:(void (^)(WDSSmsSendMessageResult*))success
                             failure:(void (^)(NSError*))failure;
@end

#endif // __WDSSmsDevice2_DEFINED__

// Windows.Devices.Sms.SmsMessageReceivedTriggerDetails
#ifndef __WDSSmsMessageReceivedTriggerDetails_DEFINED__
#define __WDSSmsMessageReceivedTriggerDetails_DEFINED__

WINRT_EXPORT
@interface WDSSmsMessageReceivedTriggerDetails : RTObject
@property (readonly) WDSSmsAppMessage* appMessage;
@property (readonly) WDSSmsBroadcastMessage* broadcastMessage;
@property (readonly) WDSSmsMessageType messageType;
@property (readonly) WDSSmsStatusMessage* statusMessage;
@property (readonly) WDSSmsTextMessage2* textMessage;
@property (readonly) WDSSmsVoicemailMessage* voicemailMessage;
@property (readonly) WDSSmsWapMessage* wapMessage;
- (void)drop;
- (void)accept;
@end

#endif // __WDSSmsMessageReceivedTriggerDetails_DEFINED__

// Windows.Devices.Sms.SmsFilterRule
#ifndef __WDSSmsFilterRule_DEFINED__
#define __WDSSmsFilterRule_DEFINED__

WINRT_EXPORT
@interface WDSSmsFilterRule : RTObject
+ (WDSSmsFilterRule*)createFilterRule:(WDSSmsMessageType)messageType ACTIVATOR;
@property WDSCellularClass cellularClass;
@property (readonly) NSMutableArray* broadcastChannels;
@property (readonly) NSMutableArray* broadcastTypes;
@property (readonly) NSMutableArray* deviceIds;
@property (readonly) NSMutableArray* imsiPrefixes;
@property (readonly) WDSSmsMessageType messageType;
@property (readonly) NSMutableArray* portNumbers;
@property (readonly) NSMutableArray* protocolIds;
@property (readonly) NSMutableArray* senderNumbers;
@property (readonly) NSMutableArray* teleserviceIds;
@property (readonly) NSMutableArray* textMessagePrefixes;
@property (readonly) NSMutableArray* wapApplicationIds;
@property (readonly) NSMutableArray* wapContentTypes;
@end

#endif // __WDSSmsFilterRule_DEFINED__

// Windows.Devices.Sms.SmsFilterRules
#ifndef __WDSSmsFilterRules_DEFINED__
#define __WDSSmsFilterRules_DEFINED__

WINRT_EXPORT
@interface WDSSmsFilterRules : RTObject
+ (WDSSmsFilterRules*)createFilterRules:(WDSSmsFilterActionType)actionType ACTIVATOR;
@property (readonly) WDSSmsFilterActionType actionType;
@property (readonly) NSMutableArray* rules;
@end

#endif // __WDSSmsFilterRules_DEFINED__

// Windows.Devices.Sms.SmsMessageRegistration
#ifndef __WDSSmsMessageRegistration_DEFINED__
#define __WDSSmsMessageRegistration_DEFINED__

WINRT_EXPORT
@interface WDSSmsMessageRegistration : RTObject
+ (WDSSmsMessageRegistration*)Register:(NSString*)id filterRules:(WDSSmsFilterRules*)filterRules;
@property (readonly) NSString* id;
+ (NSArray*)allRegistrations;
- (EventRegistrationToken)addMessageReceivedEvent:(void (^)(WDSSmsMessageRegistration*, WDSSmsMessageReceivedTriggerDetails*))del;
- (void)removeMessageReceivedEvent:(EventRegistrationToken)tok;
- (void)unregister;
@end

#endif // __WDSSmsMessageRegistration_DEFINED__
