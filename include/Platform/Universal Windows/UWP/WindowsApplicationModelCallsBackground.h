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

// WindowsApplicationModelCallsBackground.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_APPLICATIONMODEL_CALLS_BACKGROUND_EXPORT
#define OBJCUWP_WINDOWS_APPLICATIONMODEL_CALLS_BACKGROUND_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_ApplicationModel_Calls_Background.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WACBPhoneCallBlockedTriggerDetails, WACBPhoneCallOriginDataRequestTriggerDetails, WACBPhoneNewVoicemailMessageTriggerDetails, WACBPhoneLineChangedTriggerDetails;
@protocol WACBIPhoneCallBlockedTriggerDetails, WACBIPhoneCallOriginDataRequestTriggerDetails, WACBIPhoneNewVoicemailMessageTriggerDetails, WACBIPhoneLineChangedTriggerDetails;

// Windows.ApplicationModel.Calls.Background.PhoneCallBlockedReason
enum _WACBPhoneCallBlockedReason {
    WACBPhoneCallBlockedReasonInCallBlockingList = 0,
    WACBPhoneCallBlockedReasonPrivateNumber = 1,
    WACBPhoneCallBlockedReasonUnknownNumber = 2,
};
typedef unsigned WACBPhoneCallBlockedReason;

// Windows.ApplicationModel.Calls.Background.PhoneTriggerType
enum _WACBPhoneTriggerType {
    WACBPhoneTriggerTypeNewVoicemailMessage = 0,
    WACBPhoneTriggerTypeCallHistoryChanged = 1,
    WACBPhoneTriggerTypeLineChanged = 2,
    WACBPhoneTriggerTypeAirplaneModeDisabledForEmergencyCall = 3,
    WACBPhoneTriggerTypeCallOriginDataRequest = 4,
    WACBPhoneTriggerTypeCallBlocked = 5,
};
typedef unsigned WACBPhoneTriggerType;

// Windows.ApplicationModel.Calls.Background.PhoneLineChangeKind
enum _WACBPhoneLineChangeKind {
    WACBPhoneLineChangeKindAdded = 0,
    WACBPhoneLineChangeKindRemoved = 1,
    WACBPhoneLineChangeKindPropertiesChanged = 2,
};
typedef unsigned WACBPhoneLineChangeKind;

// Windows.ApplicationModel.Calls.Background.PhoneLineProperties
enum _WACBPhoneLineProperties {
    WACBPhoneLinePropertiesNone = 0,
    WACBPhoneLinePropertiesBrandingOptions = 1,
    WACBPhoneLinePropertiesCanDial = 2,
    WACBPhoneLinePropertiesCellularDetails = 4,
    WACBPhoneLinePropertiesDisplayColor = 8,
    WACBPhoneLinePropertiesDisplayName = 16,
    WACBPhoneLinePropertiesNetworkName = 32,
    WACBPhoneLinePropertiesNetworkState = 64,
    WACBPhoneLinePropertiesTransport = 128,
    WACBPhoneLinePropertiesVoicemail = 256,
};
typedef unsigned WACBPhoneLineProperties;

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Calls.Background.PhoneCallBlockedTriggerDetails
#ifndef __WACBPhoneCallBlockedTriggerDetails_DEFINED__
#define __WACBPhoneCallBlockedTriggerDetails_DEFINED__

OBJCUWP_WINDOWS_APPLICATIONMODEL_CALLS_BACKGROUND_EXPORT
@interface WACBPhoneCallBlockedTriggerDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WACBPhoneCallBlockedReason callBlockedReason;
@property (readonly) WFGUID* lineId;
@property (readonly) NSString * phoneNumber;
@end

#endif // __WACBPhoneCallBlockedTriggerDetails_DEFINED__

// Windows.ApplicationModel.Calls.Background.PhoneCallOriginDataRequestTriggerDetails
#ifndef __WACBPhoneCallOriginDataRequestTriggerDetails_DEFINED__
#define __WACBPhoneCallOriginDataRequestTriggerDetails_DEFINED__

OBJCUWP_WINDOWS_APPLICATIONMODEL_CALLS_BACKGROUND_EXPORT
@interface WACBPhoneCallOriginDataRequestTriggerDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) NSString * phoneNumber;
@property (readonly) WFGUID* requestId;
@end

#endif // __WACBPhoneCallOriginDataRequestTriggerDetails_DEFINED__

// Windows.ApplicationModel.Calls.Background.PhoneNewVoicemailMessageTriggerDetails
#ifndef __WACBPhoneNewVoicemailMessageTriggerDetails_DEFINED__
#define __WACBPhoneNewVoicemailMessageTriggerDetails_DEFINED__

OBJCUWP_WINDOWS_APPLICATIONMODEL_CALLS_BACKGROUND_EXPORT
@interface WACBPhoneNewVoicemailMessageTriggerDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WFGUID* lineId;
@property (readonly) NSString * operatorMessage;
@property (readonly) int voicemailCount;
@end

#endif // __WACBPhoneNewVoicemailMessageTriggerDetails_DEFINED__

// Windows.ApplicationModel.Calls.Background.PhoneLineChangedTriggerDetails
#ifndef __WACBPhoneLineChangedTriggerDetails_DEFINED__
#define __WACBPhoneLineChangedTriggerDetails_DEFINED__

OBJCUWP_WINDOWS_APPLICATIONMODEL_CALLS_BACKGROUND_EXPORT
@interface WACBPhoneLineChangedTriggerDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WACBPhoneLineChangeKind changeType;
@property (readonly) WFGUID* lineId;
- (BOOL)hasLinePropertyChanged:(WACBPhoneLineProperties)lineProperty;
@end

#endif // __WACBPhoneLineChangedTriggerDetails_DEFINED__

