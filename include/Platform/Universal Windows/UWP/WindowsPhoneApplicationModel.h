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

// WindowsPhoneApplicationModel.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_PHONE_APPLICATIONMODEL_EXPORT
#define OBJCUWP_WINDOWS_PHONE_APPLICATIONMODEL_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_Phone_ApplicationModel.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WPAApplicationProfile;
@protocol WPAIApplicationProfileStatics;

// Windows.Phone.ApplicationModel.ApplicationProfileModes
enum _WPAApplicationProfileModes {
    WPAApplicationProfileModesDefault = 0,
    WPAApplicationProfileModesAlternate = 1,
};
typedef unsigned WPAApplicationProfileModes;

#import <Foundation/Foundation.h>

// Windows.Phone.ApplicationModel.ApplicationProfile
#ifndef __WPAApplicationProfile_DEFINED__
#define __WPAApplicationProfile_DEFINED__

OBJCUWP_WINDOWS_PHONE_APPLICATIONMODEL_EXPORT
@interface WPAApplicationProfile : RTObject
+ (WPAApplicationProfileModes)modes;
@end

#endif // __WPAApplicationProfile_DEFINED__

