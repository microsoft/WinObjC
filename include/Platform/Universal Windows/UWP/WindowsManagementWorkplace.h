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

// WindowsManagementWorkplace.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSMANAGEMENTWORKPLACEEXPORT
#define OBJCUWPWINDOWSMANAGEMENTWORKPLACEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsManagementWorkplace.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WMWMdmPolicy, WMWWorkplaceSettings;
@protocol WMWIMdmAllowPolicyStatics, WMWIMdmPolicyStatics2, WMWIWorkplaceSettingsStatics;

// Windows.Management.Workplace.MessagingSyncPolicy
enum _WMWMessagingSyncPolicy {
    WMWMessagingSyncPolicyDisallowed = 0,
    WMWMessagingSyncPolicyAllowed = 1,
    WMWMessagingSyncPolicyRequired = 2,
};
typedef unsigned WMWMessagingSyncPolicy;

#import <Foundation/Foundation.h>

// Windows.Management.Workplace.MdmPolicy
#ifndef __WMWMdmPolicy_DEFINED__
#define __WMWMdmPolicy_DEFINED__

OBJCUWPWINDOWSMANAGEMENTWORKPLACEEXPORT
@interface WMWMdmPolicy : RTObject
+ (WMWMessagingSyncPolicy)getMessagingSyncPolicy;
+ (BOOL)isBrowserAllowed;
+ (BOOL)isCameraAllowed;
+ (BOOL)isMicrosoftAccountAllowed;
+ (BOOL)isStoreAllowed;
@end

#endif // __WMWMdmPolicy_DEFINED__

// Windows.Management.Workplace.WorkplaceSettings
#ifndef __WMWWorkplaceSettings_DEFINED__
#define __WMWWorkplaceSettings_DEFINED__

OBJCUWPWINDOWSMANAGEMENTWORKPLACEEXPORT
@interface WMWWorkplaceSettings : RTObject
+ (BOOL)isMicrosoftAccountOptional;
@end

#endif // __WMWWorkplaceSettings_DEFINED__

