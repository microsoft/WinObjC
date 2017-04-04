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

// WindowsEmbeddedDeviceLockdown.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSEMBEDDEDDEVICELOCKDOWNEXPORT
#define OBJCUWPWINDOWSEMBEDDEDDEVICELOCKDOWNEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsEmbeddedDeviceLockdown.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WEDDeviceLockdownProfileInformation, WEDDeviceLockdownProfile;
@protocol WEDIDeviceLockdownProfileInformation, WEDIDeviceLockdownProfileStatics;

#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Embedded.DeviceLockdown.DeviceLockdownProfileInformation
#ifndef __WEDDeviceLockdownProfileInformation_DEFINED__
#define __WEDDeviceLockdownProfileInformation_DEFINED__

OBJCUWPWINDOWSEMBEDDEDDEVICELOCKDOWNEXPORT
@interface WEDDeviceLockdownProfileInformation : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * name;
@end

#endif // __WEDDeviceLockdownProfileInformation_DEFINED__

// Windows.Embedded.DeviceLockdown.DeviceLockdownProfile
#ifndef __WEDDeviceLockdownProfile_DEFINED__
#define __WEDDeviceLockdownProfile_DEFINED__

OBJCUWPWINDOWSEMBEDDEDDEVICELOCKDOWNEXPORT
@interface WEDDeviceLockdownProfile : RTObject
+ (NSArray* /* WFGUID* */)getSupportedLockdownProfiles;
+ (WFGUID*)getCurrentLockdownProfile;
+ (RTObject<WFIAsyncAction>*)applyLockdownProfileAsync:(WFGUID*)profileID;
+ (WEDDeviceLockdownProfileInformation*)getLockdownProfileInformation:(WFGUID*)profileID;
@end

#endif // __WEDDeviceLockdownProfile_DEFINED__

