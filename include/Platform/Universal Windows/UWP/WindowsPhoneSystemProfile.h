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

// WindowsPhoneSystemProfile.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_PHONE_SYSTEM_PROFILE_EXPORT
#define OBJCUWP_WINDOWS_PHONE_SYSTEM_PROFILE_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_Phone_System_Profile.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WPSPRetailMode;
@protocol WPSPIRetailModeStatics;

#import <Foundation/Foundation.h>

// Windows.Phone.System.Profile.RetailMode
#ifndef __WPSPRetailMode_DEFINED__
#define __WPSPRetailMode_DEFINED__

OBJCUWP_WINDOWS_PHONE_SYSTEM_PROFILE_EXPORT
@interface WPSPRetailMode : RTObject
+ (BOOL)retailModeEnabled;
@end

#endif // __WPSPRetailMode_DEFINED__

