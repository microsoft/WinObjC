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

// WindowsMediaCasting.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WMCCastingSource, WMCCastingConnectionErrorOccurredEventArgs, WMCCastingDevice, WMCCastingConnection,
    WMCCastingDeviceSelectedEventArgs, WMCCastingDevicePickerFilter, WMCCastingDevicePicker;
@protocol WMCICastingSource
, WMCICastingConnectionErrorOccurredEventArgs, WMCICastingConnection, WMCICastingDevice, WMCICastingDeviceStatics,
    WMCICastingDeviceSelectedEventArgs, WMCICastingDevicePickerFilter, WMCICastingDevicePicker;

// Windows.Media.Casting.CastingPlaybackTypes
enum _WMCCastingPlaybackTypes {
    WMCCastingPlaybackTypesNone = 0,
    WMCCastingPlaybackTypesAudio = 1,
    WMCCastingPlaybackTypesVideo = 2,
    WMCCastingPlaybackTypesPicture = 4,
};
typedef unsigned WMCCastingPlaybackTypes;

// Windows.Media.Casting.CastingConnectionErrorStatus
enum _WMCCastingConnectionErrorStatus {
    WMCCastingConnectionErrorStatusSucceeded = 0,
    WMCCastingConnectionErrorStatusDeviceDidNotRespond = 1,
    WMCCastingConnectionErrorStatusDeviceError = 2,
    WMCCastingConnectionErrorStatusDeviceLocked = 3,
    WMCCastingConnectionErrorStatusProtectedPlaybackFailed = 4,
    WMCCastingConnectionErrorStatusInvalidCastingSource = 5,
    WMCCastingConnectionErrorStatusUnknown = 6,
};
typedef unsigned WMCCastingConnectionErrorStatus;

// Windows.Media.Casting.CastingConnectionState
enum _WMCCastingConnectionState {
    WMCCastingConnectionStateDisconnected = 0,
    WMCCastingConnectionStateConnected = 1,
    WMCCastingConnectionStateRendering = 2,
    WMCCastingConnectionStateDisconnecting = 3,
    WMCCastingConnectionStateConnecting = 4,
};
typedef unsigned WMCCastingConnectionState;

#include "WindowsUIPopups.h"
#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"
#include "WindowsStorageStreams.h"
#include "WindowsDevicesEnumeration.h"

#import <Foundation/Foundation.h>

// Windows.Media.Casting.CastingSource
#ifndef __WMCCastingSource_DEFINED__
#define __WMCCastingSource_DEFINED__

WINRT_EXPORT
@interface WMCCastingSource : RTObject
@property (copy) WFUri* preferredSourceUri;
@end

#endif // __WMCCastingSource_DEFINED__

// Windows.Media.Casting.CastingConnectionErrorOccurredEventArgs
#ifndef __WMCCastingConnectionErrorOccurredEventArgs_DEFINED__
#define __WMCCastingConnectionErrorOccurredEventArgs_DEFINED__

WINRT_EXPORT
@interface WMCCastingConnectionErrorOccurredEventArgs : RTObject
@property (readonly) WMCCastingConnectionErrorStatus errorStatus;
@property (readonly) NSString* message;
@end

#endif // __WMCCastingConnectionErrorOccurredEventArgs_DEFINED__

// Windows.Media.Casting.CastingDevice
#ifndef __WMCCastingDevice_DEFINED__
#define __WMCCastingDevice_DEFINED__

WINRT_EXPORT
@interface WMCCastingDevice : RTObject
+ (NSString*)getDeviceSelector:(WMCCastingPlaybackTypes)type;
+ (void)getDeviceSelectorFromCastingSourceAsync:(WMCCastingSource*)castingSource
                                        success:(void (^)(NSString*))success
                                        failure:(void (^)(NSError*))failure;
+ (void)fromIdAsync:(NSString*)value success:(void (^)(WMCCastingDevice*))success failure:(void (^)(NSError*))failure;
+ (void)deviceInfoSupportsCastingAsync:(WDEDeviceInformation*)device success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@property (readonly) NSString* friendlyName;
@property (readonly) RTObject<WSSIRandomAccessStreamWithContentType>* icon;
@property (readonly) NSString* id;
- (void)getSupportedCastingPlaybackTypesAsyncWithSuccess:(void (^)(WMCCastingPlaybackTypes))success failure:(void (^)(NSError*))failure;
- (WMCCastingConnection*)createCastingConnection;
@end

#endif // __WMCCastingDevice_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

// Windows.Media.Casting.CastingConnection
#ifndef __WMCCastingConnection_DEFINED__
#define __WMCCastingConnection_DEFINED__

WINRT_EXPORT
@interface WMCCastingConnection : RTObject <WFIClosable>
@property (copy) WMCCastingSource* source;
@property (readonly) WMCCastingDevice* device;
@property (readonly) WMCCastingConnectionState state;
- (EventRegistrationToken)addErrorOccurredEvent:(void (^)(WMCCastingConnection*, WMCCastingConnectionErrorOccurredEventArgs*))del;
- (void)removeErrorOccurredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStateChangedEvent:(void (^)(WMCCastingConnection*, RTObject*))del;
- (void)removeStateChangedEvent:(EventRegistrationToken)tok;
- (void)requestStartCastingAsync:(WMCCastingSource*)value
                         success:(void (^)(WMCCastingConnectionErrorStatus))success
                         failure:(void (^)(NSError*))failure;
- (void)disconnectAsyncWithSuccess:(void (^)(WMCCastingConnectionErrorStatus))success failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WMCCastingConnection_DEFINED__

// Windows.Media.Casting.CastingDeviceSelectedEventArgs
#ifndef __WMCCastingDeviceSelectedEventArgs_DEFINED__
#define __WMCCastingDeviceSelectedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMCCastingDeviceSelectedEventArgs : RTObject
@property (readonly) WMCCastingDevice* selectedCastingDevice;
@end

#endif // __WMCCastingDeviceSelectedEventArgs_DEFINED__

// Windows.Media.Casting.CastingDevicePickerFilter
#ifndef __WMCCastingDevicePickerFilter_DEFINED__
#define __WMCCastingDevicePickerFilter_DEFINED__

WINRT_EXPORT
@interface WMCCastingDevicePickerFilter : RTObject
@property BOOL supportsVideo;
@property BOOL supportsPictures;
@property BOOL supportsAudio;
@property (readonly) NSMutableArray* supportedCastingSources;
@end

#endif // __WMCCastingDevicePickerFilter_DEFINED__

// Windows.Media.Casting.CastingDevicePicker
#ifndef __WMCCastingDevicePicker_DEFINED__
#define __WMCCastingDevicePicker_DEFINED__

WINRT_EXPORT
@interface WMCCastingDevicePicker : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) WDEDevicePickerAppearance* appearance;
@property (readonly) WMCCastingDevicePickerFilter* filter;
- (EventRegistrationToken)addCastingDevicePickerDismissedEvent:(void (^)(WMCCastingDevicePicker*, RTObject*))del;
- (void)removeCastingDevicePickerDismissedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCastingDeviceSelectedEvent:(void (^)(WMCCastingDevicePicker*, WMCCastingDeviceSelectedEventArgs*))del;
- (void)removeCastingDeviceSelectedEvent:(EventRegistrationToken)tok;
- (void)show:(WFRect*)selection;
- (void)showWithPlacement:(WFRect*)selection preferredPlacement:(WUPPlacement)preferredPlacement;
- (void)hide;
@end

#endif // __WMCCastingDevicePicker_DEFINED__
