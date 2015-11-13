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

// WindowsDevicesPortable.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WDPStorageDevice, WDPServiceDevice;
@protocol WDPIStorageDeviceStatics
, WDPIServiceDeviceStatics;

// Windows.Devices.Portable.ServiceDeviceType
enum _WDPServiceDeviceType {
    WDPServiceDeviceTypeCalendarService = 0,
    WDPServiceDeviceTypeContactsService = 1,
    WDPServiceDeviceTypeDeviceStatusService = 2,
    WDPServiceDeviceTypeNotesService = 3,
    WDPServiceDeviceTypeRingtonesService = 4,
    WDPServiceDeviceTypeSmsService = 5,
    WDPServiceDeviceTypeTasksService = 6,
};
typedef unsigned WDPServiceDeviceType;

#include "WindowsStorage.h"

// Windows.Devices.Portable.StorageDevice
#ifndef __WDPStorageDevice_DEFINED__
#define __WDPStorageDevice_DEFINED__

WINRT_EXPORT
@interface WDPStorageDevice : RTObject
+ (WSStorageFolder*)fromId:(NSString*)deviceId;
+ (NSString*)getDeviceSelector;
@end

#endif // __WDPStorageDevice_DEFINED__

// Windows.Devices.Portable.ServiceDevice
#ifndef __WDPServiceDevice_DEFINED__
#define __WDPServiceDevice_DEFINED__

WINRT_EXPORT
@interface WDPServiceDevice : RTObject
+ (NSString*)getDeviceSelector:(WDPServiceDeviceType)serviceType;
+ (NSString*)getDeviceSelectorFromServiceId:(WFGUID*)serviceId;
@end

#endif // __WDPServiceDevice_DEFINED__
