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

// WindowsDevicesAdcProvider.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_DEVICES_ADC_PROVIDER_EXPORT
#define OBJCUWP_WINDOWS_DEVICES_ADC_PROVIDER_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_Devices_Adc_Provider.lib")
#endif
#endif
#include <UWP/interopBase.h>

@protocol WDAPIAdcControllerProvider, WDAPIAdcProvider;

// Windows.Devices.Adc.Provider.ProviderAdcChannelMode
enum _WDAPProviderAdcChannelMode {
    WDAPProviderAdcChannelModeSingleEnded = 0,
    WDAPProviderAdcChannelModeDifferential = 1,
};
typedef unsigned WDAPProviderAdcChannelMode;

#import <Foundation/Foundation.h>

// Windows.Devices.Adc.Provider.IAdcControllerProvider
#ifndef __WDAPIAdcControllerProvider_DEFINED__
#define __WDAPIAdcControllerProvider_DEFINED__

@protocol WDAPIAdcControllerProvider
@property (readonly) int channelCount;
@property WDAPProviderAdcChannelMode channelMode;
@property (readonly) int maxValue;
@property (readonly) int minValue;
@property (readonly) int resolutionInBits;
- (BOOL)isChannelModeSupported:(WDAPProviderAdcChannelMode)channelMode;
- (void)acquireChannel:(int)channel;
- (void)releaseChannel:(int)channel;
- (int)readValue:(int)channelNumber;
@end

OBJCUWP_WINDOWS_DEVICES_ADC_PROVIDER_EXPORT
@interface WDAPIAdcControllerProvider : RTObject <WDAPIAdcControllerProvider>
@end

#endif // __WDAPIAdcControllerProvider_DEFINED__

// Windows.Devices.Adc.Provider.IAdcProvider
#ifndef __WDAPIAdcProvider_DEFINED__
#define __WDAPIAdcProvider_DEFINED__

@protocol WDAPIAdcProvider
- (NSArray* /* RTObject<WDAPIAdcControllerProvider>* */)getControllers;
@end

OBJCUWP_WINDOWS_DEVICES_ADC_PROVIDER_EXPORT
@interface WDAPIAdcProvider : RTObject <WDAPIAdcProvider>
@end

#endif // __WDAPIAdcProvider_DEFINED__

