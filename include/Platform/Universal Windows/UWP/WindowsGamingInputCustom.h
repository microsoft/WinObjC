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

// WindowsGamingInputCustom.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSGAMINGINPUTCUSTOMEXPORT
#define OBJCUWPWINDOWSGAMINGINPUTCUSTOMEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsGamingInputCustom.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WGICGipFirmwareUpdateResult, WGICGipGameControllerProvider, WGICHidGameControllerProvider, WGICXusbGameControllerProvider, WGICGameControllerFactoryManager;
@class WGICGameControllerVersionInfo, WGICGipFirmwareUpdateProgress;
@protocol WGICIGameControllerInputSink, WGICIGipGameControllerInputSink, WGICIHidGameControllerInputSink, WGICIXusbGameControllerInputSink, WGICIGipFirmwareUpdateResult, WGICIGameControllerProvider, WGICIGipGameControllerProvider, WGICIHidGameControllerProvider, WGICIXusbGameControllerProvider, WGICICustomGameControllerFactory, WGICIGameControllerFactoryManagerStatics, WGICIGameControllerFactoryManagerStatics2;

// Windows.Gaming.Input.Custom.GipFirmwareUpdateStatus
enum _WGICGipFirmwareUpdateStatus {
    WGICGipFirmwareUpdateStatusCompleted = 0,
    WGICGipFirmwareUpdateStatusUpToDate = 1,
    WGICGipFirmwareUpdateStatusFailed = 2,
};
typedef unsigned WGICGipFirmwareUpdateStatus;

// Windows.Gaming.Input.Custom.GipMessageClass
enum _WGICGipMessageClass {
    WGICGipMessageClassCommand = 0,
    WGICGipMessageClassLowLatency = 1,
    WGICGipMessageClassStandardLatency = 2,
};
typedef unsigned WGICGipMessageClass;

// Windows.Gaming.Input.Custom.XusbDeviceType
enum _WGICXusbDeviceType {
    WGICXusbDeviceTypeUnknown = 0,
    WGICXusbDeviceTypeGamepad = 1,
};
typedef unsigned WGICXusbDeviceType;

// Windows.Gaming.Input.Custom.XusbDeviceSubtype
enum _WGICXusbDeviceSubtype {
    WGICXusbDeviceSubtypeUnknown = 0,
    WGICXusbDeviceSubtypeGamepad = 1,
    WGICXusbDeviceSubtypeArcadePad = 2,
    WGICXusbDeviceSubtypeArcadeStick = 3,
    WGICXusbDeviceSubtypeFlightStick = 4,
    WGICXusbDeviceSubtypeWheel = 5,
    WGICXusbDeviceSubtypeGuitar = 6,
    WGICXusbDeviceSubtypeGuitarAlternate = 7,
    WGICXusbDeviceSubtypeGuitarBass = 8,
    WGICXusbDeviceSubtypeDrumKit = 9,
    WGICXusbDeviceSubtypeDancePad = 10,
};
typedef unsigned WGICXusbDeviceSubtype;

#include "WindowsStorageStreams.h"
#include "WindowsGamingInput.h"

#import <Foundation/Foundation.h>

// [struct] Windows.Gaming.Input.Custom.GameControllerVersionInfo
OBJCUWPWINDOWSGAMINGINPUTCUSTOMEXPORT
@interface WGICGameControllerVersionInfo : NSObject
+ (instancetype)new;
@property unsigned short major;
@property unsigned short minor;
@property unsigned short build;
@property unsigned short revision;
@end

// [struct] Windows.Gaming.Input.Custom.GipFirmwareUpdateProgress
OBJCUWPWINDOWSGAMINGINPUTCUSTOMEXPORT
@interface WGICGipFirmwareUpdateProgress : NSObject
+ (instancetype)new;
@property double percentCompleted;
@property unsigned int currentComponentId;
@end

// Windows.Gaming.Input.Custom.IGameControllerInputSink
#ifndef __WGICIGameControllerInputSink_DEFINED__
#define __WGICIGameControllerInputSink_DEFINED__

@protocol WGICIGameControllerInputSink
- (void)onInputResumed:(uint64_t)timestamp;
- (void)onInputSuspended:(uint64_t)timestamp;
@end

OBJCUWPWINDOWSGAMINGINPUTCUSTOMEXPORT
@interface WGICIGameControllerInputSink : RTObject <WGICIGameControllerInputSink>
@end

#endif // __WGICIGameControllerInputSink_DEFINED__

// Windows.Gaming.Input.Custom.IGipGameControllerInputSink
#ifndef __WGICIGipGameControllerInputSink_DEFINED__
#define __WGICIGipGameControllerInputSink_DEFINED__

@protocol WGICIGipGameControllerInputSink <WGICIGameControllerInputSink>
- (void)onKeyReceived:(uint64_t)timestamp keyCode:(uint8_t)keyCode isPressed:(BOOL)isPressed;
- (void)onMessageReceived:(uint64_t)timestamp messageClass:(WGICGipMessageClass)messageClass messageId:(uint8_t)messageId sequenceId:(uint8_t)sequenceId messageBuffer:(NSArray* /* uint8_t */)messageBuffer;
- (void)onInputResumed:(uint64_t)timestamp;
- (void)onInputSuspended:(uint64_t)timestamp;
@end

OBJCUWPWINDOWSGAMINGINPUTCUSTOMEXPORT
@interface WGICIGipGameControllerInputSink : RTObject <WGICIGipGameControllerInputSink>
@end

#endif // __WGICIGipGameControllerInputSink_DEFINED__

// Windows.Gaming.Input.Custom.IHidGameControllerInputSink
#ifndef __WGICIHidGameControllerInputSink_DEFINED__
#define __WGICIHidGameControllerInputSink_DEFINED__

@protocol WGICIHidGameControllerInputSink <WGICIGameControllerInputSink>
- (void)onInputReportReceived:(uint64_t)timestamp reportId:(uint8_t)reportId reportBuffer:(NSArray* /* uint8_t */)reportBuffer;
- (void)onInputResumed:(uint64_t)timestamp;
- (void)onInputSuspended:(uint64_t)timestamp;
@end

OBJCUWPWINDOWSGAMINGINPUTCUSTOMEXPORT
@interface WGICIHidGameControllerInputSink : RTObject <WGICIHidGameControllerInputSink>
@end

#endif // __WGICIHidGameControllerInputSink_DEFINED__

// Windows.Gaming.Input.Custom.IXusbGameControllerInputSink
#ifndef __WGICIXusbGameControllerInputSink_DEFINED__
#define __WGICIXusbGameControllerInputSink_DEFINED__

@protocol WGICIXusbGameControllerInputSink <WGICIGameControllerInputSink>
- (void)onInputReceived:(uint64_t)timestamp reportId:(uint8_t)reportId inputBuffer:(NSArray* /* uint8_t */)inputBuffer;
- (void)onInputResumed:(uint64_t)timestamp;
- (void)onInputSuspended:(uint64_t)timestamp;
@end

OBJCUWPWINDOWSGAMINGINPUTCUSTOMEXPORT
@interface WGICIXusbGameControllerInputSink : RTObject <WGICIXusbGameControllerInputSink>
@end

#endif // __WGICIXusbGameControllerInputSink_DEFINED__

// Windows.Gaming.Input.Custom.IGameControllerProvider
#ifndef __WGICIGameControllerProvider_DEFINED__
#define __WGICIGameControllerProvider_DEFINED__

@protocol WGICIGameControllerProvider
@property (readonly) WGICGameControllerVersionInfo* firmwareVersionInfo;
@property (readonly) unsigned short hardwareProductId;
@property (readonly) unsigned short hardwareVendorId;
@property (readonly) WGICGameControllerVersionInfo* hardwareVersionInfo;
@property (readonly) BOOL isConnected;
@end

OBJCUWPWINDOWSGAMINGINPUTCUSTOMEXPORT
@interface WGICIGameControllerProvider : RTObject <WGICIGameControllerProvider>
@end

#endif // __WGICIGameControllerProvider_DEFINED__

// Windows.Gaming.Input.Custom.ICustomGameControllerFactory
#ifndef __WGICICustomGameControllerFactory_DEFINED__
#define __WGICICustomGameControllerFactory_DEFINED__

@protocol WGICICustomGameControllerFactory
- (RTObject*)createGameController:(RTObject<WGICIGameControllerProvider>*)provider;
- (void)onGameControllerAdded:(RTObject<WGIIGameController>*)value;
- (void)onGameControllerRemoved:(RTObject<WGIIGameController>*)value;
@end

OBJCUWPWINDOWSGAMINGINPUTCUSTOMEXPORT
@interface WGICICustomGameControllerFactory : RTObject <WGICICustomGameControllerFactory>
@end

#endif // __WGICICustomGameControllerFactory_DEFINED__

// Windows.Gaming.Input.Custom.GipFirmwareUpdateResult
#ifndef __WGICGipFirmwareUpdateResult_DEFINED__
#define __WGICGipFirmwareUpdateResult_DEFINED__

OBJCUWPWINDOWSGAMINGINPUTCUSTOMEXPORT
@interface WGICGipFirmwareUpdateResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int extendedErrorCode;
@property (readonly) unsigned int finalComponentId;
@property (readonly) WGICGipFirmwareUpdateStatus status;
@end

#endif // __WGICGipFirmwareUpdateResult_DEFINED__

// Windows.Gaming.Input.Custom.GipGameControllerProvider
#ifndef __WGICGipGameControllerProvider_DEFINED__
#define __WGICGipGameControllerProvider_DEFINED__

OBJCUWPWINDOWSGAMINGINPUTCUSTOMEXPORT
@interface WGICGipGameControllerProvider : RTObject <WGICIGameControllerProvider>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGICGameControllerVersionInfo* firmwareVersionInfo;
@property (readonly) unsigned short hardwareProductId;
@property (readonly) unsigned short hardwareVendorId;
@property (readonly) WGICGameControllerVersionInfo* hardwareVersionInfo;
@property (readonly) BOOL isConnected;
- (void)sendMessage:(WGICGipMessageClass)messageClass messageId:(uint8_t)messageId messageBuffer:(NSArray* /* uint8_t */)messageBuffer;
- (void)sendReceiveMessage:(WGICGipMessageClass)messageClass messageId:(uint8_t)messageId requestMessageBuffer:(NSArray* /* uint8_t */)requestMessageBuffer responseMessageBuffer:(NSArray* /* uint8_t */*)responseMessageBuffer;
- (void)updateFirmwareAsync:(RTObject<WSSIInputStream>*)firmwareImage success:(void (^)(WGICGipFirmwareUpdateResult*))success progress:(void (^)(WGICGipFirmwareUpdateProgress*))progress failure:(void (^)(NSError*))failure;
@end

#endif // __WGICGipGameControllerProvider_DEFINED__

// Windows.Gaming.Input.Custom.HidGameControllerProvider
#ifndef __WGICHidGameControllerProvider_DEFINED__
#define __WGICHidGameControllerProvider_DEFINED__

OBJCUWPWINDOWSGAMINGINPUTCUSTOMEXPORT
@interface WGICHidGameControllerProvider : RTObject <WGICIGameControllerProvider>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGICGameControllerVersionInfo* firmwareVersionInfo;
@property (readonly) unsigned short hardwareProductId;
@property (readonly) unsigned short hardwareVendorId;
@property (readonly) WGICGameControllerVersionInfo* hardwareVersionInfo;
@property (readonly) BOOL isConnected;
@property (readonly) unsigned short usageId;
@property (readonly) unsigned short usagePage;
- (void)getFeatureReport:(uint8_t)reportId reportBuffer:(NSArray* /* uint8_t */*)reportBuffer;
- (void)sendFeatureReport:(uint8_t)reportId reportBuffer:(NSArray* /* uint8_t */)reportBuffer;
- (void)sendOutputReport:(uint8_t)reportId reportBuffer:(NSArray* /* uint8_t */)reportBuffer;
@end

#endif // __WGICHidGameControllerProvider_DEFINED__

// Windows.Gaming.Input.Custom.XusbGameControllerProvider
#ifndef __WGICXusbGameControllerProvider_DEFINED__
#define __WGICXusbGameControllerProvider_DEFINED__

OBJCUWPWINDOWSGAMINGINPUTCUSTOMEXPORT
@interface WGICXusbGameControllerProvider : RTObject <WGICIGameControllerProvider>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGICGameControllerVersionInfo* firmwareVersionInfo;
@property (readonly) unsigned short hardwareProductId;
@property (readonly) unsigned short hardwareVendorId;
@property (readonly) WGICGameControllerVersionInfo* hardwareVersionInfo;
@property (readonly) BOOL isConnected;
- (void)setVibration:(double)lowFrequencyMotorSpeed highFrequencyMotorSpeed:(double)highFrequencyMotorSpeed;
@end

#endif // __WGICXusbGameControllerProvider_DEFINED__

// Windows.Gaming.Input.Custom.GameControllerFactoryManager
#ifndef __WGICGameControllerFactoryManager_DEFINED__
#define __WGICGameControllerFactoryManager_DEFINED__

OBJCUWPWINDOWSGAMINGINPUTCUSTOMEXPORT
@interface WGICGameControllerFactoryManager : RTObject
+ (void)registerCustomFactoryForGipInterface:(RTObject<WGICICustomGameControllerFactory>*)factory interfaceId:(WFGUID*)interfaceId;
+ (void)registerCustomFactoryForHardwareId:(RTObject<WGICICustomGameControllerFactory>*)factory hardwareVendorId:(unsigned short)hardwareVendorId hardwareProductId:(unsigned short)hardwareProductId;
+ (void)registerCustomFactoryForXusbType:(RTObject<WGICICustomGameControllerFactory>*)factory xusbType:(WGICXusbDeviceType)xusbType xusbSubtype:(WGICXusbDeviceSubtype)xusbSubtype;
+ (RTObject<WGIIGameController>*)tryGetFactoryControllerFromGameController:(RTObject<WGICICustomGameControllerFactory>*)factory gameController:(RTObject<WGIIGameController>*)gameController;
+ (void)registerCustomFactoryForGipInterface:(RTObject<WGICICustomGameControllerFactory>*)factory interfaceId:(WFGUID*)interfaceId;
+ (void)registerCustomFactoryForHardwareId:(RTObject<WGICICustomGameControllerFactory>*)factory hardwareVendorId:(unsigned short)hardwareVendorId hardwareProductId:(unsigned short)hardwareProductId;
+ (void)registerCustomFactoryForXusbType:(RTObject<WGICICustomGameControllerFactory>*)factory xusbType:(WGICXusbDeviceType)xusbType xusbSubtype:(WGICXusbDeviceSubtype)xusbSubtype;
@end

#endif // __WGICGameControllerFactoryManager_DEFINED__

