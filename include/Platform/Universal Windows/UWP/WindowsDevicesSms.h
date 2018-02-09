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

// WindowsDevicesSms.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSDEVICESSMSEXPORT
#define OBJCUWPWINDOWSDEVICESSMSEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsDevicesSms.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDSSmsBinaryMessage, WDSSmsTextMessage, WDSDeleteSmsMessageOperation, WDSDeleteSmsMessagesOperation, WDSGetSmsMessageOperation, WDSGetSmsMessagesOperation, WDSSmsDeviceMessageStore, WDSSendSmsMessageOperation, WDSSmsMessageReceivedEventArgs, WDSSmsDevice, WDSGetSmsDeviceOperation, WDSSmsReceivedEventDetails, WDSSmsTextMessage2, WDSSmsWapMessage, WDSSmsAppMessage, WDSSmsBroadcastMessage, WDSSmsVoicemailMessage, WDSSmsStatusMessage, WDSSmsSendMessageResult, WDSSmsDevice2, WDSSmsMessageReceivedTriggerDetails, WDSSmsFilterRule, WDSSmsFilterRules, WDSSmsMessageRegistration;
@class WDSSmsEncodedLength;
@protocol WDSISmsMessage, WDSISmsBinaryMessage, WDSISmsTextMessage, WDSISmsTextMessageStatics, WDSISmsDeviceMessageStore, WDSISmsMessageReceivedEventArgs, WDSISmsDeviceStatics, WDSISmsDeviceStatics2, WDSISmsDevice, WDSISmsReceivedEventDetails, WDSISmsReceivedEventDetails2, WDSISmsMessageBase, WDSISmsTextMessage2, WDSISmsWapMessage, WDSISmsAppMessage, WDSISmsBroadcastMessage, WDSISmsVoicemailMessage, WDSISmsStatusMessage, WDSISmsSendMessageResult, WDSISmsDevice2Statics, WDSISmsDevice2, WDSISmsMessageReceivedTriggerDetails, WDSISmsFilterRule, WDSISmsFilterRuleFactory, WDSISmsFilterRules, WDSISmsFilterRulesFactory, WDSISmsMessageRegistrationStatics, WDSISmsMessageRegistration;

// Windows.Devices.Sms.SmsMessageFilter
enum _WDSSmsMessageFilter {
    WDSSmsMessageFilterAll = 0,
    WDSSmsMessageFilterUnread = 1,
    WDSSmsMessageFilterRead = 2,
    WDSSmsMessageFilterSent = 3,
    WDSSmsMessageFilterDraft = 4,
};
typedef unsigned WDSSmsMessageFilter;

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

#include "WindowsStorageStreams.h"
#include "WindowsFoundation.h"
// Windows.Devices.Sms.SmsDeviceStatusChangedEventHandler
#ifndef __WDSSmsDeviceStatusChangedEventHandler__DEFINED
#define __WDSSmsDeviceStatusChangedEventHandler__DEFINED
typedef void(^WDSSmsDeviceStatusChangedEventHandler)(WDSSmsDevice* sender);
#endif // __WDSSmsDeviceStatusChangedEventHandler__DEFINED

// Windows.Devices.Sms.SmsMessageReceivedEventHandler
#ifndef __WDSSmsMessageReceivedEventHandler__DEFINED
#define __WDSSmsMessageReceivedEventHandler__DEFINED
typedef void(^WDSSmsMessageReceivedEventHandler)(WDSSmsDevice* sender, WDSSmsMessageReceivedEventArgs* e);
#endif // __WDSSmsMessageReceivedEventHandler__DEFINED

// Windows.Foundation.AsyncActionCompletedHandler
#ifndef __WFAsyncActionCompletedHandler__DEFINED
#define __WFAsyncActionCompletedHandler__DEFINED
typedef void(^WFAsyncActionCompletedHandler)(RTObject<WFIAsyncAction>* asyncInfo, WFAsyncStatus asyncStatus);
#endif // __WFAsyncActionCompletedHandler__DEFINED


#import <Foundation/Foundation.h>

// [struct] Windows.Devices.Sms.SmsEncodedLength
OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSSmsEncodedLength : NSObject
+ (instancetype)new;
@property unsigned int segmentCount;
@property unsigned int characterCountLastSegment;
@property unsigned int charactersPerSegment;
@property unsigned int byteCountLastSegment;
@property unsigned int bytesPerSegment;
@end

// Windows.Devices.Sms.SmsMessageReceivedEventHandler
#ifndef __WDSSmsMessageReceivedEventHandler__DEFINED
#define __WDSSmsMessageReceivedEventHandler__DEFINED
typedef void(^WDSSmsMessageReceivedEventHandler)(WDSSmsDevice* sender, WDSSmsMessageReceivedEventArgs* e);
#endif // __WDSSmsMessageReceivedEventHandler__DEFINED

// Windows.Devices.Sms.SmsDeviceStatusChangedEventHandler
#ifndef __WDSSmsDeviceStatusChangedEventHandler__DEFINED
#define __WDSSmsDeviceStatusChangedEventHandler__DEFINED
typedef void(^WDSSmsDeviceStatusChangedEventHandler)(WDSSmsDevice* sender);
#endif // __WDSSmsDeviceStatusChangedEventHandler__DEFINED

// Windows.Devices.Sms.ISmsMessage
#ifndef __WDSISmsMessage_DEFINED__
#define __WDSISmsMessage_DEFINED__

@protocol WDSISmsMessage
@property (readonly) unsigned int id;
@property (readonly) WDSSmsMessageClass messageClass;
@end

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSISmsMessage : RTObject <WDSISmsMessage>
@end

#endif // __WDSISmsMessage_DEFINED__

// Windows.Devices.Sms.ISmsBinaryMessage
#ifndef __WDSISmsBinaryMessage_DEFINED__
#define __WDSISmsBinaryMessage_DEFINED__

@protocol WDSISmsBinaryMessage <WDSISmsMessage>
@property WDSSmsDataFormat format;
- (NSArray* /* uint8_t */)getData;
- (void)setData:(NSArray* /* uint8_t */)value;
@end

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSISmsBinaryMessage : RTObject <WDSISmsBinaryMessage>
@end

#endif // __WDSISmsBinaryMessage_DEFINED__

// Windows.Devices.Sms.ISmsTextMessage
#ifndef __WDSISmsTextMessage_DEFINED__
#define __WDSISmsTextMessage_DEFINED__

@protocol WDSISmsTextMessage <WDSISmsMessage>
@property (retain) NSString * body;
@property WDSSmsEncoding encoding;
@property (retain) NSString * from;
@property (readonly) unsigned int partCount;
@property (readonly) unsigned int partNumber;
@property (readonly) unsigned int partReferenceId;
@property (readonly) WFDateTime* timestamp;
@property (retain) NSString * to;
- (NSArray* /* RTObject<WDSISmsBinaryMessage>* */)toBinaryMessages:(WDSSmsDataFormat)format;
@end

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSISmsTextMessage : RTObject <WDSISmsTextMessage>
@end

#endif // __WDSISmsTextMessage_DEFINED__

// Windows.Devices.Sms.ISmsDevice
#ifndef __WDSISmsDevice_DEFINED__
#define __WDSISmsDevice_DEFINED__

@protocol WDSISmsDevice
@property (readonly) NSString * accountPhoneNumber;
@property (readonly) WDSCellularClass cellularClass;
@property (readonly) WDSSmsDeviceStatus deviceStatus;
@property (readonly) WDSSmsDeviceMessageStore* messageStore;
- (EventRegistrationToken)addSmsDeviceStatusChangedEvent:(WDSSmsDeviceStatusChangedEventHandler)del;
- (void)removeSmsDeviceStatusChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSmsMessageReceivedEvent:(WDSSmsMessageReceivedEventHandler)del;
- (void)removeSmsMessageReceivedEvent:(EventRegistrationToken)tok;
- (WDSSendSmsMessageOperation*)sendMessageAsync:(RTObject<WDSISmsMessage>*)message;
- (WDSSmsEncodedLength*)calculateLength:(WDSSmsTextMessage*)message;
@end

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSISmsDevice : RTObject <WDSISmsDevice>
@end

#endif // __WDSISmsDevice_DEFINED__

// Windows.Devices.Sms.ISmsMessageBase
#ifndef __WDSISmsMessageBase_DEFINED__
#define __WDSISmsMessageBase_DEFINED__

@protocol WDSISmsMessageBase
@property (readonly) WDSCellularClass cellularClass;
@property (readonly) NSString * deviceId;
@property (readonly) WDSSmsMessageClass messageClass;
@property (readonly) WDSSmsMessageType messageType;
@property (readonly) NSString * simIccId;
@end

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSISmsMessageBase : RTObject <WDSISmsMessageBase>
@end

#endif // __WDSISmsMessageBase_DEFINED__

// Windows.Devices.Sms.SmsBinaryMessage
#ifndef __WDSSmsBinaryMessage_DEFINED__
#define __WDSSmsBinaryMessage_DEFINED__

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSSmsBinaryMessage : RTObject <WDSISmsBinaryMessage, WDSISmsMessage>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WDSSmsDataFormat format;
@property (readonly) unsigned int id;
@property (readonly) WDSSmsMessageClass messageClass;
- (NSArray* /* uint8_t */)getData;
- (void)setData:(NSArray* /* uint8_t */)value;
@end

#endif // __WDSSmsBinaryMessage_DEFINED__

// Windows.Devices.Sms.SmsTextMessage
#ifndef __WDSSmsTextMessage_DEFINED__
#define __WDSSmsTextMessage_DEFINED__

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSSmsTextMessage : RTObject <WDSISmsTextMessage, WDSISmsMessage>
+ (WDSSmsTextMessage*)fromBinaryMessage:(WDSSmsBinaryMessage*)binaryMessage;
+ (WDSSmsTextMessage*)fromBinaryData:(WDSSmsDataFormat)format value:(NSArray* /* uint8_t */)value;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int id;
@property (readonly) WDSSmsMessageClass messageClass;
@property (retain) NSString * to;
@property (retain) NSString * from;
@property WDSSmsEncoding encoding;
@property (retain) NSString * body;
@property (readonly) unsigned int partCount;
@property (readonly) unsigned int partNumber;
@property (readonly) unsigned int partReferenceId;
@property (readonly) WFDateTime* timestamp;
- (NSArray* /* RTObject<WDSISmsBinaryMessage>* */)toBinaryMessages:(WDSSmsDataFormat)format;
@end

#endif // __WDSSmsTextMessage_DEFINED__

// Windows.Foundation.IAsyncInfo
#ifndef __WFIAsyncInfo_DEFINED__
#define __WFIAsyncInfo_DEFINED__

@protocol WFIAsyncInfo
@property (readonly) HRESULT errorCode;
@property (readonly) unsigned int id;
@property (readonly) WFAsyncStatus status;
- (void)cancel;
- (void)close;
@end

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WFIAsyncInfo : RTObject <WFIAsyncInfo>
@end

#endif // __WFIAsyncInfo_DEFINED__

// Windows.Foundation.IAsyncAction
#ifndef __WFIAsyncAction_DEFINED__
#define __WFIAsyncAction_DEFINED__

@protocol WFIAsyncAction <WFIAsyncInfo>
@property (copy) WFAsyncActionCompletedHandler completed;
- (void)getResults;
- (void)cancel;
- (void)close;
@end

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WFIAsyncAction : RTObject <WFIAsyncAction>
@end

#endif // __WFIAsyncAction_DEFINED__

// Windows.Devices.Sms.DeleteSmsMessageOperation
#ifndef __WDSDeleteSmsMessageOperation_DEFINED__
#define __WDSDeleteSmsMessageOperation_DEFINED__

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSDeleteSmsMessageOperation : RTObject <WFIAsyncAction, WFIAsyncInfo>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) HRESULT errorCode;
@property (readonly) unsigned int id;
@property (readonly) WFAsyncStatus status;
@property (copy) WFAsyncActionCompletedHandler completed;
- (void)getResults;
- (void)cancel;
- (void)close;
@end

#endif // __WDSDeleteSmsMessageOperation_DEFINED__

// Windows.Devices.Sms.DeleteSmsMessagesOperation
#ifndef __WDSDeleteSmsMessagesOperation_DEFINED__
#define __WDSDeleteSmsMessagesOperation_DEFINED__

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSDeleteSmsMessagesOperation : RTObject <WFIAsyncAction, WFIAsyncInfo>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) HRESULT errorCode;
@property (readonly) unsigned int id;
@property (readonly) WFAsyncStatus status;
@property (copy) WFAsyncActionCompletedHandler completed;
- (void)getResults;
- (void)cancel;
- (void)close;
@end

#endif // __WDSDeleteSmsMessagesOperation_DEFINED__

// Windows.Devices.Sms.GetSmsMessageOperation
#ifndef __WDSGetSmsMessageOperation_DEFINED__
#define __WDSGetSmsMessageOperation_DEFINED__

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSGetSmsMessageOperation : RTObject <WFIAsyncInfo>
 // Failed to get type for default interface: Can't marshal Windows.Foundation.IAsyncOperation`1<Windows.Devices.Sms.ISmsMessage>
@property (readonly) HRESULT errorCode;
@property (readonly) unsigned int id;
@property (readonly) WFAsyncStatus status;
// Failed to generate property Completed (Can't marshal Windows.Foundation.AsyncOperationCompletedHandler`1<Windows.Devices.Sms.ISmsMessage>)
// Could not find base class Windows.Foundation.IAsyncOperation`1<Windows.Devices.Sms.ISmsMessage> type information
- (void)cancel;
- (void)close;
@end

#endif // __WDSGetSmsMessageOperation_DEFINED__

// Windows.Devices.Sms.GetSmsMessagesOperation
#ifndef __WDSGetSmsMessagesOperation_DEFINED__
#define __WDSGetSmsMessagesOperation_DEFINED__

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSGetSmsMessagesOperation : RTObject <WFIAsyncInfo>
 // Failed to get type for default interface: Can't marshal Windows.Foundation.IAsyncOperationWithProgress`2<Windows.Foundation.Collections.IVectorView`1<Windows.Devices.Sms.ISmsMessage>,Int32>
@property (readonly) HRESULT errorCode;
@property (readonly) unsigned int id;
@property (readonly) WFAsyncStatus status;
// Failed to generate property Progress (Can't marshal Windows.Foundation.AsyncOperationProgressHandler`2<Windows.Foundation.Collections.IVectorView`1<Windows.Devices.Sms.ISmsMessage>,Int32>)
// Failed to generate property Completed (Can't marshal Windows.Foundation.AsyncOperationWithProgressCompletedHandler`2<Windows.Foundation.Collections.IVectorView`1<Windows.Devices.Sms.ISmsMessage>,Int32>)
// Could not find base class Windows.Foundation.IAsyncOperationWithProgress`2<Windows.Foundation.Collections.IVectorView`1<Windows.Devices.Sms.ISmsMessage>,Int32> type information
- (void)cancel;
- (void)close;
@end

#endif // __WDSGetSmsMessagesOperation_DEFINED__

// Windows.Devices.Sms.SmsDeviceMessageStore
#ifndef __WDSSmsDeviceMessageStore_DEFINED__
#define __WDSSmsDeviceMessageStore_DEFINED__

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSSmsDeviceMessageStore : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int maxMessages;
- (RTObject<WFIAsyncAction>*)deleteMessageAsync:(unsigned int)messageId;
- (RTObject<WFIAsyncAction>*)deleteMessagesAsync:(WDSSmsMessageFilter)messageFilter;
- (void)getMessageAsync:(unsigned int)messageId success:(void (^)(RTObject<WDSISmsMessage>*))success failure:(void (^)(NSError*))failure;
- (void)getMessagesAsync:(WDSSmsMessageFilter)messageFilter success:(void (^)(NSArray* /* RTObject<WDSISmsMessage>* */))success progress:(void (^)(int))progress failure:(void (^)(NSError*))failure;
@end

#endif // __WDSSmsDeviceMessageStore_DEFINED__

// Windows.Devices.Sms.SendSmsMessageOperation
#ifndef __WDSSendSmsMessageOperation_DEFINED__
#define __WDSSendSmsMessageOperation_DEFINED__

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSSendSmsMessageOperation : RTObject <WFIAsyncAction, WFIAsyncInfo>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) HRESULT errorCode;
@property (readonly) unsigned int id;
@property (readonly) WFAsyncStatus status;
@property (copy) WFAsyncActionCompletedHandler completed;
- (void)getResults;
- (void)cancel;
- (void)close;
@end

#endif // __WDSSendSmsMessageOperation_DEFINED__

// Windows.Devices.Sms.SmsMessageReceivedEventArgs
#ifndef __WDSSmsMessageReceivedEventArgs_DEFINED__
#define __WDSSmsMessageReceivedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSSmsMessageReceivedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDSSmsBinaryMessage* binaryMessage;
@property (readonly) WDSSmsTextMessage* textMessage;
@end

#endif // __WDSSmsMessageReceivedEventArgs_DEFINED__

// Windows.Devices.Sms.SmsDevice
#ifndef __WDSSmsDevice_DEFINED__
#define __WDSSmsDevice_DEFINED__

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSSmsDevice : RTObject <WDSISmsDevice>
+ (void)fromNetworkAccountIdAsync:(NSString *)networkAccountId success:(void (^)(WDSSmsDevice*))success failure:(void (^)(NSError*))failure;
+ (NSString *)getDeviceSelector;
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDSSmsDevice*))success failure:(void (^)(NSError*))failure;
+ (void)getDefaultAsyncWithSuccess:(void (^)(WDSSmsDevice*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * accountPhoneNumber;
@property (readonly) WDSCellularClass cellularClass;
@property (readonly) WDSSmsDeviceStatus deviceStatus;
@property (readonly) WDSSmsDeviceMessageStore* messageStore;
- (EventRegistrationToken)addSmsDeviceStatusChangedEvent:(WDSSmsDeviceStatusChangedEventHandler)del;
- (void)removeSmsDeviceStatusChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSmsMessageReceivedEvent:(WDSSmsMessageReceivedEventHandler)del;
- (void)removeSmsMessageReceivedEvent:(EventRegistrationToken)tok;
- (WDSSendSmsMessageOperation*)sendMessageAsync:(RTObject<WDSISmsMessage>*)message;
- (WDSSmsEncodedLength*)calculateLength:(WDSSmsTextMessage*)message;
@end

#endif // __WDSSmsDevice_DEFINED__

// Windows.Devices.Sms.GetSmsDeviceOperation
#ifndef __WDSGetSmsDeviceOperation_DEFINED__
#define __WDSGetSmsDeviceOperation_DEFINED__

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSGetSmsDeviceOperation : RTObject <WFIAsyncInfo>
 // Failed to get type for default interface: Can't marshal Windows.Foundation.IAsyncOperation`1<Windows.Devices.Sms.SmsDevice>
@property (readonly) HRESULT errorCode;
@property (readonly) unsigned int id;
@property (readonly) WFAsyncStatus status;
// Failed to generate property Completed (Can't marshal Windows.Foundation.AsyncOperationCompletedHandler`1<Windows.Devices.Sms.SmsDevice>)
// Could not find base class Windows.Foundation.IAsyncOperation`1<Windows.Devices.Sms.SmsDevice> type information
- (void)cancel;
- (void)close;
@end

#endif // __WDSGetSmsDeviceOperation_DEFINED__

// Windows.Devices.Sms.SmsReceivedEventDetails
#ifndef __WDSSmsReceivedEventDetails_DEFINED__
#define __WDSSmsReceivedEventDetails_DEFINED__

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSSmsReceivedEventDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * deviceId;
@property (readonly) unsigned int messageIndex;
@property (readonly) WDSSmsBinaryMessage* binaryMessage;
@property (readonly) WDSSmsMessageClass messageClass;
@end

#endif // __WDSSmsReceivedEventDetails_DEFINED__

// Windows.Devices.Sms.SmsTextMessage2
#ifndef __WDSSmsTextMessage2_DEFINED__
#define __WDSSmsTextMessage2_DEFINED__

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSSmsTextMessage2 : RTObject <WDSISmsMessageBase>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDSSmsMessageType messageType;
@property (readonly) NSString * deviceId;
@property (readonly) WDSCellularClass cellularClass;
@property (readonly) WDSSmsMessageClass messageClass;
@property (readonly) NSString * simIccId;
@property int retryAttemptCount;
@property (retain) NSString * to;
@property BOOL isDeliveryNotificationEnabled;
@property WDSSmsEncoding encoding;
@property (retain) NSString * callbackNumber;
@property (retain) NSString * body;
@property (readonly) int protocolId;
@property (readonly) NSString * from;
@property (readonly) WFDateTime* timestamp;
@property (readonly) int teleserviceId;
@end

#endif // __WDSSmsTextMessage2_DEFINED__

// Windows.Devices.Sms.SmsWapMessage
#ifndef __WDSSmsWapMessage_DEFINED__
#define __WDSSmsWapMessage_DEFINED__

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSSmsWapMessage : RTObject <WDSISmsMessageBase>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDSCellularClass cellularClass;
@property (readonly) NSString * deviceId;
@property (readonly) WDSSmsMessageClass messageClass;
@property (readonly) WDSSmsMessageType messageType;
@property (readonly) NSString * simIccId;
@property (readonly) WFDateTime* timestamp;
@property (readonly) NSString * applicationId;
@property (readonly) RTObject<WSSIBuffer>* binaryBody;
@property (readonly) NSString * contentType;
@property (readonly) NSString * from;
@property (readonly) NSMutableDictionary* /* NSString *, NSString * */ headers;
@property (readonly) NSString * to;
@end

#endif // __WDSSmsWapMessage_DEFINED__

// Windows.Devices.Sms.SmsAppMessage
#ifndef __WDSSmsAppMessage_DEFINED__
#define __WDSSmsAppMessage_DEFINED__

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSSmsAppMessage : RTObject <WDSISmsMessageBase>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property int protocolId;
@property int portNumber;
@property BOOL isDeliveryNotificationEnabled;
@property int retryAttemptCount;
@property WDSSmsEncoding encoding;
@property (retain) NSString * body;
@property (retain) NSString * callbackNumber;
@property (retain) RTObject<WSSIBuffer>* binaryBody;
@property (retain) NSString * to;
@property int teleserviceId;
@property (readonly) NSString * from;
@property (readonly) WFDateTime* timestamp;
@property (readonly) WDSCellularClass cellularClass;
@property (readonly) NSString * deviceId;
@property (readonly) WDSSmsMessageClass messageClass;
@property (readonly) WDSSmsMessageType messageType;
@property (readonly) NSString * simIccId;
@end

#endif // __WDSSmsAppMessage_DEFINED__

// Windows.Devices.Sms.SmsBroadcastMessage
#ifndef __WDSSmsBroadcastMessage_DEFINED__
#define __WDSSmsBroadcastMessage_DEFINED__

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSSmsBroadcastMessage : RTObject <WDSISmsMessageBase>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * body;
@property (readonly) WDSSmsBroadcastType broadcastType;
@property (readonly) int channel;
@property (readonly) WDSSmsGeographicalScope geographicalScope;
@property (readonly) BOOL isEmergencyAlert;
@property (readonly) BOOL isUserPopupRequested;
@property (readonly) int messageCode;
@property (readonly) WFDateTime* timestamp;
@property (readonly) NSString * to;
@property (readonly) int updateNumber;
@property (readonly) WDSCellularClass cellularClass;
@property (readonly) NSString * deviceId;
@property (readonly) WDSSmsMessageClass messageClass;
@property (readonly) WDSSmsMessageType messageType;
@property (readonly) NSString * simIccId;
@end

#endif // __WDSSmsBroadcastMessage_DEFINED__

// Windows.Devices.Sms.SmsVoicemailMessage
#ifndef __WDSSmsVoicemailMessage_DEFINED__
#define __WDSSmsVoicemailMessage_DEFINED__

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSSmsVoicemailMessage : RTObject <WDSISmsMessageBase>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDSCellularClass cellularClass;
@property (readonly) NSString * deviceId;
@property (readonly) WDSSmsMessageClass messageClass;
@property (readonly) WDSSmsMessageType messageType;
@property (readonly) NSString * simIccId;
@property (readonly) NSString * body;
@property (readonly) id /* int */ messageCount;
@property (readonly) WFDateTime* timestamp;
@property (readonly) NSString * to;
@end

#endif // __WDSSmsVoicemailMessage_DEFINED__

// Windows.Devices.Sms.SmsStatusMessage
#ifndef __WDSSmsStatusMessage_DEFINED__
#define __WDSSmsStatusMessage_DEFINED__

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSSmsStatusMessage : RTObject <WDSISmsMessageBase>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDSCellularClass cellularClass;
@property (readonly) NSString * deviceId;
@property (readonly) WDSSmsMessageClass messageClass;
@property (readonly) WDSSmsMessageType messageType;
@property (readonly) NSString * simIccId;
@property (readonly) int status;
@property (readonly) NSString * body;
@property (readonly) WFDateTime* dischargeTime;
@property (readonly) NSString * from;
@property (readonly) int messageReferenceNumber;
@property (readonly) WFDateTime* serviceCenterTimestamp;
@property (readonly) NSString * to;
@end

#endif // __WDSSmsStatusMessage_DEFINED__

// Windows.Devices.Sms.SmsSendMessageResult
#ifndef __WDSSmsSendMessageResult_DEFINED__
#define __WDSSmsSendMessageResult_DEFINED__

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSSmsSendMessageResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDSCellularClass cellularClass;
@property (readonly) BOOL isErrorTransient;
@property (readonly) BOOL isSuccessful;
@property (readonly) NSArray* /* int */ messageReferenceNumbers;
@property (readonly) WDSSmsModemErrorCode modemErrorCode;
@property (readonly) int networkCauseCode;
@property (readonly) int transportFailureCause;
@end

#endif // __WDSSmsSendMessageResult_DEFINED__

// Windows.Devices.Sms.SmsDevice2
#ifndef __WDSSmsDevice2_DEFINED__
#define __WDSSmsDevice2_DEFINED__

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSSmsDevice2 : RTObject
+ (NSString *)getDeviceSelector;
+ (WDSSmsDevice2*)fromId:(NSString *)deviceId;
+ (WDSSmsDevice2*)getDefault;
+ (WDSSmsDevice2*)fromParentId:(NSString *)parentDeviceId;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * smscAddress;
@property (readonly) NSString * accountPhoneNumber;
@property (readonly) WDSCellularClass cellularClass;
@property (readonly) NSString * deviceId;
@property (readonly) WDSSmsDeviceStatus deviceStatus;
@property (readonly) NSString * parentDeviceId;
- (EventRegistrationToken)addDeviceStatusChangedEvent:(void(^)(WDSSmsDevice2*, RTObject*))del;
- (void)removeDeviceStatusChangedEvent:(EventRegistrationToken)tok;
- (WDSSmsEncodedLength*)calculateLength:(RTObject<WDSISmsMessageBase>*)message;
- (void)sendMessageAndGetResultAsync:(RTObject<WDSISmsMessageBase>*)message success:(void (^)(WDSSmsSendMessageResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDSSmsDevice2_DEFINED__

// Windows.Devices.Sms.SmsMessageReceivedTriggerDetails
#ifndef __WDSSmsMessageReceivedTriggerDetails_DEFINED__
#define __WDSSmsMessageReceivedTriggerDetails_DEFINED__

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSSmsMessageReceivedTriggerDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
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

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSSmsFilterRule : RTObject
+ (WDSSmsFilterRule*)makeFilterRule:(WDSSmsMessageType)messageType ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WDSCellularClass cellularClass;
@property (readonly) NSMutableArray* /* int */ broadcastChannels;
@property (readonly) NSMutableArray* /* WDSSmsBroadcastType */ broadcastTypes;
@property (readonly) NSMutableArray* /* NSString * */ deviceIds;
@property (readonly) NSMutableArray* /* NSString * */ imsiPrefixes;
@property (readonly) WDSSmsMessageType messageType;
@property (readonly) NSMutableArray* /* int */ portNumbers;
@property (readonly) NSMutableArray* /* int */ protocolIds;
@property (readonly) NSMutableArray* /* NSString * */ senderNumbers;
@property (readonly) NSMutableArray* /* int */ teleserviceIds;
@property (readonly) NSMutableArray* /* NSString * */ textMessagePrefixes;
@property (readonly) NSMutableArray* /* NSString * */ wapApplicationIds;
@property (readonly) NSMutableArray* /* NSString * */ wapContentTypes;
@end

#endif // __WDSSmsFilterRule_DEFINED__

// Windows.Devices.Sms.SmsFilterRules
#ifndef __WDSSmsFilterRules_DEFINED__
#define __WDSSmsFilterRules_DEFINED__

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSSmsFilterRules : RTObject
+ (WDSSmsFilterRules*)makeFilterRules:(WDSSmsFilterActionType)actionType ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDSSmsFilterActionType actionType;
@property (readonly) NSMutableArray* /* WDSSmsFilterRule* */ rules;
@end

#endif // __WDSSmsFilterRules_DEFINED__

// Windows.Devices.Sms.SmsMessageRegistration
#ifndef __WDSSmsMessageRegistration_DEFINED__
#define __WDSSmsMessageRegistration_DEFINED__

OBJCUWPWINDOWSDEVICESSMSEXPORT
@interface WDSSmsMessageRegistration : RTObject
+ (WDSSmsMessageRegistration*)Register:(NSString *)id filterRules:(WDSSmsFilterRules*)filterRules;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * id;
+ (NSArray* /* WDSSmsMessageRegistration* */)allRegistrations;
- (EventRegistrationToken)addMessageReceivedEvent:(void(^)(WDSSmsMessageRegistration*, WDSSmsMessageReceivedTriggerDetails*))del;
- (void)removeMessageReceivedEvent:(EventRegistrationToken)tok;
- (void)unregister;
@end

#endif // __WDSSmsMessageRegistration_DEFINED__

