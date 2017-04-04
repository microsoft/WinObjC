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

#ifndef OBJCUWPWINDOWSPHONEAPPLICATIONMODELEXPORT
#define OBJCUWPWINDOWSPHONEAPPLICATIONMODELEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsPhoneApplicationModel.lib")
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

OBJCUWPWINDOWSPHONEAPPLICATIONMODELEXPORT
@interface WPAApplicationProfile : RTObject
+ (WPAApplicationProfileModes)modes;
@end

#endif // __WPAApplicationProfile_DEFINED__

