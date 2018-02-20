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

// WindowsGamingInputPreview.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSGAMINGINPUTPREVIEWEXPORT
#define OBJCUWPWINDOWSGAMINGINPUTPREVIEWEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsGamingInputPreview.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WGIPGameControllerProviderInfo;
@protocol WGIPIGameControllerProviderInfoStatics;

#include "WindowsGamingInputCustom.h"

#import <Foundation/Foundation.h>

// Windows.Gaming.Input.Preview.GameControllerProviderInfo
#ifndef __WGIPGameControllerProviderInfo_DEFINED__
#define __WGIPGameControllerProviderInfo_DEFINED__

OBJCUWPWINDOWSGAMINGINPUTPREVIEWEXPORT
@interface WGIPGameControllerProviderInfo : RTObject
+ (NSString *)getParentProviderId:(RTObject<WGICIGameControllerProvider>*)provider;
+ (NSString *)getProviderId:(RTObject<WGICIGameControllerProvider>*)provider;
@end

#endif // __WGIPGameControllerProviderInfo_DEFINED__

