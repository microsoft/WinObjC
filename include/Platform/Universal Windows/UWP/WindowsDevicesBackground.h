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

// WindowsDevicesBackground.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_DEVICES_BACKGROUND_EXPORT
#define OBJCUWP_WINDOWS_DEVICES_BACKGROUND_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_Devices_Background.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDBDeviceUseDetails, WDBDeviceServicingDetails;
@protocol WDBIDeviceUseDetails
, WDBIDeviceServicingDetails;

#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Devices.Background.DeviceUseDetails
#ifndef __WDBDeviceUseDetails_DEFINED__
#define __WDBDeviceUseDetails_DEFINED__

OBJCUWP_WINDOWS_DEVICES_BACKGROUND_EXPORT
@interface WDBDeviceUseDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) NSString* arguments;
@property (readonly) NSString* deviceId;
@end

#endif // __WDBDeviceUseDetails_DEFINED__

// Windows.Devices.Background.DeviceServicingDetails
#ifndef __WDBDeviceServicingDetails_DEFINED__
#define __WDBDeviceServicingDetails_DEFINED__

OBJCUWP_WINDOWS_DEVICES_BACKGROUND_EXPORT
@interface WDBDeviceServicingDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) NSString* arguments;
@property (readonly) NSString* deviceId;
@property (readonly) WFTimeSpan* expectedDuration;
@end

#endif // __WDBDeviceServicingDetails_DEFINED__
