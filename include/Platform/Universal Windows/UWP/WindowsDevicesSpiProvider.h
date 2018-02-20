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

// WindowsDevicesSpiProvider.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSDEVICESSPIPROVIDEREXPORT
#define OBJCUWPWINDOWSDEVICESSPIPROVIDEREXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsDevicesSpiProvider.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDSPProviderSpiConnectionSettings;
@protocol WDSPIProviderSpiConnectionSettingsFactory, WDSPIProviderSpiConnectionSettings, WDSPISpiControllerProvider, WDSPISpiProvider, WDSPISpiDeviceProvider;

// Windows.Devices.Spi.Provider.ProviderSpiMode
enum _WDSPProviderSpiMode {
    WDSPProviderSpiModeMode0 = 0,
    WDSPProviderSpiModeMode1 = 1,
    WDSPProviderSpiModeMode2 = 2,
    WDSPProviderSpiModeMode3 = 3,
};
typedef unsigned WDSPProviderSpiMode;

// Windows.Devices.Spi.Provider.ProviderSpiSharingMode
enum _WDSPProviderSpiSharingMode {
    WDSPProviderSpiSharingModeExclusive = 0,
    WDSPProviderSpiSharingModeShared = 1,
};
typedef unsigned WDSPProviderSpiSharingMode;

#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Devices.Spi.Provider.ISpiControllerProvider
#ifndef __WDSPISpiControllerProvider_DEFINED__
#define __WDSPISpiControllerProvider_DEFINED__

@protocol WDSPISpiControllerProvider
- (RTObject<WDSPISpiDeviceProvider>*)getDeviceProvider:(WDSPProviderSpiConnectionSettings*)settings;
@end

OBJCUWPWINDOWSDEVICESSPIPROVIDEREXPORT
@interface WDSPISpiControllerProvider : RTObject <WDSPISpiControllerProvider>
@end

#endif // __WDSPISpiControllerProvider_DEFINED__

// Windows.Devices.Spi.Provider.ISpiProvider
#ifndef __WDSPISpiProvider_DEFINED__
#define __WDSPISpiProvider_DEFINED__

@protocol WDSPISpiProvider
- (void)getControllersAsyncWithSuccess:(void (^)(NSArray* /* RTObject<WDSPISpiControllerProvider>* */))success failure:(void (^)(NSError*))failure;
@end

OBJCUWPWINDOWSDEVICESSPIPROVIDEREXPORT
@interface WDSPISpiProvider : RTObject <WDSPISpiProvider>
@end

#endif // __WDSPISpiProvider_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSDEVICESSPIPROVIDEREXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.Devices.Spi.Provider.ISpiDeviceProvider
#ifndef __WDSPISpiDeviceProvider_DEFINED__
#define __WDSPISpiDeviceProvider_DEFINED__

@protocol WDSPISpiDeviceProvider <WFIClosable>
@property (readonly) WDSPProviderSpiConnectionSettings* connectionSettings;
@property (readonly) NSString * deviceId;
- (void)write:(NSArray* /* uint8_t */)buffer;
- (void)read:(NSArray* /* uint8_t */*)buffer;
- (void)transferSequential:(NSArray* /* uint8_t */)writeBuffer readBuffer:(NSArray* /* uint8_t */*)readBuffer;
- (void)transferFullDuplex:(NSArray* /* uint8_t */)writeBuffer readBuffer:(NSArray* /* uint8_t */*)readBuffer;
- (void)close;
@end

OBJCUWPWINDOWSDEVICESSPIPROVIDEREXPORT
@interface WDSPISpiDeviceProvider : RTObject <WDSPISpiDeviceProvider>
@end

#endif // __WDSPISpiDeviceProvider_DEFINED__

// Windows.Devices.Spi.Provider.ProviderSpiConnectionSettings
#ifndef __WDSPProviderSpiConnectionSettings_DEFINED__
#define __WDSPProviderSpiConnectionSettings_DEFINED__

OBJCUWPWINDOWSDEVICESSPIPROVIDEREXPORT
@interface WDSPProviderSpiConnectionSettings : RTObject
+ (WDSPProviderSpiConnectionSettings*)make:(int)chipSelectLine ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WDSPProviderSpiSharingMode sharingMode;
@property WDSPProviderSpiMode mode;
@property int dataBitLength;
@property int clockFrequency;
@property int chipSelectLine;
@end

#endif // __WDSPProviderSpiConnectionSettings_DEFINED__

