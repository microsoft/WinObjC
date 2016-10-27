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

// WindowsSecurityExchangeActiveSyncProvisioning.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_SECURITY_EXCHANGEACTIVESYNCPROVISIONING_EXPORT
#define OBJCUWP_WINDOWS_SECURITY_EXCHANGEACTIVESYNCPROVISIONING_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_Security_ExchangeActiveSyncProvisioning.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSEEasClientDeviceInformation;
@protocol WSEIEasClientDeviceInformation
, WSEIEasClientDeviceInformation2;

#import <Foundation/Foundation.h>

// Windows.Security.ExchangeActiveSyncProvisioning.EasClientDeviceInformation
#ifndef __WSEEasClientDeviceInformation_DEFINED__
#define __WSEEasClientDeviceInformation_DEFINED__

OBJCUWP_WINDOWS_SECURITY_EXCHANGEACTIVESYNCPROVISIONING_EXPORT
@interface WSEEasClientDeviceInformation : RTObject
+ (instancetype)make ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) NSString* friendlyName;
@property (readonly) WFGUID* id;
@property (readonly) NSString* operatingSystem;
@property (readonly) NSString* systemManufacturer;
@property (readonly) NSString* systemProductName;
@property (readonly) NSString* systemSku;
@property (readonly) NSString* systemFirmwareVersion;
@property (readonly) NSString* systemHardwareVersion;
@end

#endif // __WSEEasClientDeviceInformation_DEFINED__
