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
@class WDSSmsBinaryMessage, WDSSmsTextMessage, WDSDeleteSmsMessageOperation, WDSDeleteSmsMessagesOperation, WDSGetSmsMessageOperation,
    WDSGetSmsMessagesOperation, WDSSmsDeviceMessageStore, WDSSendSmsMessageOperation, WDSSmsMessageReceivedEventArgs, WDSSmsDevice,
    WDSGetSmsDeviceOperation, WDSSmsReceivedEventDetails;
@class WDSSmsEncodedLength;
@protocol WDSISmsMessage
, WDSISmsBinaryMessage, WDSISmsTextMessage, WDSISmsTextMessageStatics, WDSISmsDeviceMessageStore, WDSISmsMessageReceivedEventArgs,
    WDSISmsDeviceStatics, WDSISmsDeviceStatics2, WDSISmsDevice, WDSISmsReceivedEventDetails, WDSISmsReceivedEventDetails2;

// Windows.Devices.Sms.SmsMessageClass
enum _WDSSmsMessageClass {
    WDSSmsMessageClassNone = 0,
    WDSSmsMessageClassClass0 = 1,
    WDSSmsMessageClassClass1 = 2,
    WDSSmsMessageClassClass2 = 3,
    WDSSmsMessageClassClass3 = 4,
};
typedef unsigned WDSSmsMessageClass;

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
};
typedef unsigned WDSSmsEncoding;

// Windows.Devices.Sms.SmsMessageFilter
enum _WDSSmsMessageFilter {
    WDSSmsMessageFilterAll = 0,
    WDSSmsMessageFilterUnread = 1,
    WDSSmsMessageFilterRead = 2,
    WDSSmsMessageFilterSent = 3,
    WDSSmsMessageFilterDraft = 4,
};
typedef unsigned WDSSmsMessageFilter;

// Windows.Devices.Sms.SmsMessageType
enum _WDSSmsMessageType {
    WDSSmsMessageTypeBinary = 0,
    WDSSmsMessageTypeText = 1,
};
typedef unsigned WDSSmsMessageType;

// Windows.Devices.Sms.CellularClass
enum _WDSCellularClass {
    WDSCellularClassNone = 0,
    WDSCellularClassGsm = 1,
    WDSCellularClassCdma = 2,
};
typedef unsigned WDSCellularClass;

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

#include "WindowsFoundationCollections.h"
#include "WindowsFoundation.h"
// Windows.Devices.Sms.SmsDeviceStatusChangedEventHandler
#ifndef __WDSSmsDeviceStatusChangedEventHandler__DEFINED
#define __WDSSmsDeviceStatusChangedEventHandler__DEFINED
typedef void (^WDSSmsDeviceStatusChangedEventHandler)(WDSSmsDevice* sender);
#endif // __WDSSmsDeviceStatusChangedEventHandler__DEFINED

// Windows.Devices.Sms.SmsMessageReceivedEventHandler
#ifndef __WDSSmsMessageReceivedEventHandler__DEFINED
#define __WDSSmsMessageReceivedEventHandler__DEFINED
typedef void (^WDSSmsMessageReceivedEventHandler)(WDSSmsDevice* sender, WDSSmsMessageReceivedEventArgs* e);
#endif // __WDSSmsMessageReceivedEventHandler__DEFINED

// Windows.Foundation.AsyncActionCompletedHandler
#ifndef __WFAsyncActionCompletedHandler__DEFINED
#define __WFAsyncActionCompletedHandler__DEFINED
typedef void (^WFAsyncActionCompletedHandler)(RTObject<WFIAsyncAction>* asyncInfo, WFAsyncStatus asyncStatus);
#endif // __WFAsyncActionCompletedHandler__DEFINED

#import <Foundation/Foundation.h>

// [struct] Windows.Devices.Sms.SmsEncodedLength
WINRT_EXPORT
@interface WDSSmsEncodedLength : NSObject
+ (instancetype) new;
@property unsigned segmentCount;
@property unsigned characterCountLastSegment;
@property unsigned charactersPerSegment;
@property unsigned byteCountLastSegment;
@property unsigned bytesPerSegment;
@end

// Windows.Devices.Sms.SmsMessageReceivedEventHandler
#ifndef __WDSSmsMessageReceivedEventHandler__DEFINED
#define __WDSSmsMessageReceivedEventHandler__DEFINED
typedef void (^WDSSmsMessageReceivedEventHandler)(WDSSmsDevice* sender, WDSSmsMessageReceivedEventArgs* e);
#endif // __WDSSmsMessageReceivedEventHandler__DEFINED

// Windows.Devices.Sms.SmsDeviceStatusChangedEventHandler
#ifndef __WDSSmsDeviceStatusChangedEventHandler__DEFINED
#define __WDSSmsDeviceStatusChangedEventHandler__DEFINED
typedef void (^WDSSmsDeviceStatusChangedEventHandler)(WDSSmsDevice* sender);
#endif // __WDSSmsDeviceStatusChangedEventHandler__DEFINED

// Windows.Devices.Sms.ISmsMessage
#ifndef __WDSISmsMessage_DEFINED__
#define __WDSISmsMessage_DEFINED__

@protocol WDSISmsMessage
@property (readonly) unsigned id;
@property (readonly) WDSSmsMessageClass messageClass;
@end

#endif // __WDSISmsMessage_DEFINED__

// Windows.Devices.Sms.ISmsBinaryMessage
#ifndef __WDSISmsBinaryMessage_DEFINED__
#define __WDSISmsBinaryMessage_DEFINED__

@protocol WDSISmsBinaryMessage <WDSISmsMessage>
@property WDSSmsDataFormat format;
- (id<NSFastEnumeration> /*UInt8*/)getData;
- (void)setData:(id<NSFastEnumeration> /*UInt8*/)value;
@end

#endif // __WDSISmsBinaryMessage_DEFINED__

// Windows.Devices.Sms.ISmsTextMessage
#ifndef __WDSISmsTextMessage_DEFINED__
#define __WDSISmsTextMessage_DEFINED__

@protocol WDSISmsTextMessage <WDSISmsMessage>
@property (copy) NSString* body;
@property WDSSmsEncoding encoding;
@property (copy) NSString* from;
@property (readonly) unsigned partCount;
@property (readonly) unsigned partNumber;
@property (readonly) unsigned partReferenceId;
@property (readonly) WFDateTime* timestamp;
@property (copy) NSString* to;
- (id<NSFastEnumeration> /*WDSISmsBinaryMessage*/)toBinaryMessages:(WDSSmsDataFormat)format;
@end

#endif // __WDSISmsTextMessage_DEFINED__

// Windows.Devices.Sms.ISmsDevice
#ifndef __WDSISmsDevice_DEFINED__
#define __WDSISmsDevice_DEFINED__

@protocol WDSISmsDevice
@property (readonly) NSString* accountPhoneNumber;
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

#endif // __WDSISmsDevice_DEFINED__

// Windows.Devices.Sms.SmsBinaryMessage
#ifndef __WDSSmsBinaryMessage_DEFINED__
#define __WDSSmsBinaryMessage_DEFINED__

WINRT_EXPORT
@interface WDSSmsBinaryMessage : RTObject <WDSISmsBinaryMessage, WDSISmsMessage>
+ (instancetype)create ACTIVATOR;
@property WDSSmsDataFormat format;
@property (readonly) unsigned id;
@property (readonly) WDSSmsMessageClass messageClass;
- (id<NSFastEnumeration> /*UInt8*/)getData;
- (void)setData:(id<NSFastEnumeration> /*UInt8*/)value;
@end

#endif // __WDSSmsBinaryMessage_DEFINED__

// Windows.Devices.Sms.SmsTextMessage
#ifndef __WDSSmsTextMessage_DEFINED__
#define __WDSSmsTextMessage_DEFINED__

WINRT_EXPORT
@interface WDSSmsTextMessage : RTObject <WDSISmsTextMessage, WDSISmsMessage>
+ (WDSSmsTextMessage*)fromBinaryMessage:(WDSSmsBinaryMessage*)binaryMessage;
+ (WDSSmsTextMessage*)fromBinaryData:(WDSSmsDataFormat)format value:(id<NSFastEnumeration> /*UInt8*/)value;
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* to;
@property (copy) NSString* from;
@property WDSSmsEncoding encoding;
@property (copy) NSString* body;
@property (readonly) unsigned partCount;
@property (readonly) unsigned partNumber;
@property (readonly) unsigned partReferenceId;
@property (readonly) WFDateTime* timestamp;
@property (readonly) unsigned id;
@property (readonly) WDSSmsMessageClass messageClass;
- (id<NSFastEnumeration> /*WDSISmsBinaryMessage*/)toBinaryMessages:(WDSSmsDataFormat)format;
@end

#endif // __WDSSmsTextMessage_DEFINED__

// Windows.Foundation.IAsyncInfo
#ifndef __WFIAsyncInfo_DEFINED__
#define __WFIAsyncInfo_DEFINED__

@protocol WFIAsyncInfo
@property (readonly) HRESULT errorCode;
@property (readonly) unsigned id;
@property (readonly) WFAsyncStatus status;
- (void)cancel;
- (void)close;
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

#endif // __WFIAsyncAction_DEFINED__

// Windows.Devices.Sms.DeleteSmsMessageOperation
#ifndef __WDSDeleteSmsMessageOperation_DEFINED__
#define __WDSDeleteSmsMessageOperation_DEFINED__

WINRT_EXPORT
@interface WDSDeleteSmsMessageOperation : RTObject <WFIAsyncAction, WFIAsyncInfo>
@property (copy) WFAsyncActionCompletedHandler completed;
@property (readonly) HRESULT errorCode;
@property (readonly) unsigned id;
@property (readonly) WFAsyncStatus status;
- (void)getResults;
- (void)cancel;
- (void)close;
@end

#endif // __WDSDeleteSmsMessageOperation_DEFINED__

// Windows.Devices.Sms.DeleteSmsMessagesOperation
#ifndef __WDSDeleteSmsMessagesOperation_DEFINED__
#define __WDSDeleteSmsMessagesOperation_DEFINED__

WINRT_EXPORT
@interface WDSDeleteSmsMessagesOperation : RTObject <WFIAsyncAction, WFIAsyncInfo>
@property (copy) WFAsyncActionCompletedHandler completed;
@property (readonly) HRESULT errorCode;
@property (readonly) unsigned id;
@property (readonly) WFAsyncStatus status;
- (void)getResults;
- (void)cancel;
- (void)close;
@end

#endif // __WDSDeleteSmsMessagesOperation_DEFINED__

// Windows.Devices.Sms.GetSmsMessageOperation
#ifndef __WDSGetSmsMessageOperation_DEFINED__
#define __WDSGetSmsMessageOperation_DEFINED__

WINRT_EXPORT
@interface WDSGetSmsMessageOperation : RTObject <WFIAsyncInfo>
// Failed to generate property Completed (Can't marshal
// Windows.Foundation.AsyncOperationCompletedHandler`1<Windows.Devices.Sms.ISmsMessage>)
@property (readonly) HRESULT errorCode;
@property (readonly) unsigned id;
@property (readonly) WFAsyncStatus status;
// Could not find base class Windows.Foundation.IAsyncOperation`1<Windows.Devices.Sms.ISmsMessage> type information
- (void)cancel;
- (void)close;
@end

#endif // __WDSGetSmsMessageOperation_DEFINED__

// Windows.Devices.Sms.GetSmsMessagesOperation
#ifndef __WDSGetSmsMessagesOperation_DEFINED__
#define __WDSGetSmsMessagesOperation_DEFINED__

WINRT_EXPORT
@interface WDSGetSmsMessagesOperation : RTObject <WFIAsyncInfo>
// Failed to generate property Progress (Can't marshal
// Windows.Foundation.AsyncOperationProgressHandler`2<Windows.Foundation.Collections.IVectorView`1<Windows.Devices.Sms.ISmsMessage>,Int32>)
// Failed to generate property Completed (Can't marshal
// Windows.Foundation.AsyncOperationWithProgressCompletedHandler`2<Windows.Foundation.Collections.IVectorView`1<Windows.Devices.Sms.ISmsMessage>,Int32>)
@property (readonly) HRESULT errorCode;
@property (readonly) unsigned id;
@property (readonly) WFAsyncStatus status;
// Could not find base class
// Windows.Foundation.IAsyncOperationWithProgress`2<Windows.Foundation.Collections.IVectorView`1<Windows.Devices.Sms.ISmsMessage>,Int32>
// type information
- (void)cancel;
- (void)close;
@end

#endif // __WDSGetSmsMessagesOperation_DEFINED__

// Windows.Devices.Sms.SmsDeviceMessageStore
#ifndef __WDSSmsDeviceMessageStore_DEFINED__
#define __WDSSmsDeviceMessageStore_DEFINED__

WINRT_EXPORT
@interface WDSSmsDeviceMessageStore : RTObject
@property (readonly) unsigned maxMessages;
- (RTObject<WFIAsyncAction>*)deleteMessageAsync:(unsigned)messageId;
- (RTObject<WFIAsyncAction>*)deleteMessagesAsync:(WDSSmsMessageFilter)messageFilter;
- (void)getMessageAsync:(unsigned)messageId success:(void (^)(RTObject<WDSISmsMessage>*))success failure:(void (^)(NSError*))failure;
- (void)getMessagesAsync:(WDSSmsMessageFilter)messageFilter
                 success:(void (^)(id<NSFastEnumeration> /*WDSISmsMessage*/))success
                progress:(void (^)(int))progress
                 failure:(void (^)(NSError*))failure;
@end

#endif // __WDSSmsDeviceMessageStore_DEFINED__

// Windows.Devices.Sms.SendSmsMessageOperation
#ifndef __WDSSendSmsMessageOperation_DEFINED__
#define __WDSSendSmsMessageOperation_DEFINED__

WINRT_EXPORT
@interface WDSSendSmsMessageOperation : RTObject <WFIAsyncAction, WFIAsyncInfo>
@property (copy) WFAsyncActionCompletedHandler completed;
@property (readonly) HRESULT errorCode;
@property (readonly) unsigned id;
@property (readonly) WFAsyncStatus status;
- (void)getResults;
- (void)cancel;
- (void)close;
@end

#endif // __WDSSendSmsMessageOperation_DEFINED__

// Windows.Devices.Sms.SmsMessageReceivedEventArgs
#ifndef __WDSSmsMessageReceivedEventArgs_DEFINED__
#define __WDSSmsMessageReceivedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDSSmsMessageReceivedEventArgs : RTObject
@property (readonly) WDSSmsBinaryMessage* binaryMessage;
@property (readonly) WDSSmsTextMessage* textMessage;
@end

#endif // __WDSSmsMessageReceivedEventArgs_DEFINED__

// Windows.Devices.Sms.SmsDevice
#ifndef __WDSSmsDevice_DEFINED__
#define __WDSSmsDevice_DEFINED__

WINRT_EXPORT
@interface WDSSmsDevice : RTObject <WDSISmsDevice>
+ (void)fromNetworkAccountIdAsync:(NSString*)networkAccountId success:(void (^)(WDSSmsDevice*))success failure:(void (^)(NSError*))failure;
+ (NSString*)getDeviceSelector;
+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDSSmsDevice*))success failure:(void (^)(NSError*))failure;
+ (void)getDefaultAsyncWithSuccess:(void (^)(WDSSmsDevice*))success failure:(void (^)(NSError*))failure;
@property (readonly) NSString* accountPhoneNumber;
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

WINRT_EXPORT
@interface WDSGetSmsDeviceOperation : RTObject <WFIAsyncInfo>
// Failed to generate property Completed (Can't marshal Windows.Foundation.AsyncOperationCompletedHandler`1<Windows.Devices.Sms.SmsDevice>)
@property (readonly) HRESULT errorCode;
@property (readonly) unsigned id;
@property (readonly) WFAsyncStatus status;
// Could not find base class Windows.Foundation.IAsyncOperation`1<Windows.Devices.Sms.SmsDevice> type information
- (void)cancel;
- (void)close;
@end

#endif // __WDSGetSmsDeviceOperation_DEFINED__

// Windows.Devices.Sms.SmsReceivedEventDetails
#ifndef __WDSSmsReceivedEventDetails_DEFINED__
#define __WDSSmsReceivedEventDetails_DEFINED__

WINRT_EXPORT
@interface WDSSmsReceivedEventDetails : RTObject
@property (readonly) NSString* deviceId;
@property (readonly) unsigned messageIndex;
@property (readonly) WDSSmsBinaryMessage* binaryMessage;
@property (readonly) WDSSmsMessageClass messageClass;
@end

#endif // __WDSSmsReceivedEventDetails_DEFINED__
