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

// WindowsManagementCore.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSMANAGEMENTCOREEXPORT
#define OBJCUWPWINDOWSMANAGEMENTCOREEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsManagementCore.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WMCApplicationDataManager;
@protocol WMCIApplicationDataManagerStatics, WMCIApplicationDataManager;

#include "WindowsStorage.h"

#import <Foundation/Foundation.h>

// Windows.Management.Core.ApplicationDataManager
#ifndef __WMCApplicationDataManager_DEFINED__
#define __WMCApplicationDataManager_DEFINED__

OBJCUWPWINDOWSMANAGEMENTCOREEXPORT
@interface WMCApplicationDataManager : RTObject
+ (WSApplicationData*)createForPackageFamily:(NSString *)packageFamilyName;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WMCApplicationDataManager_DEFINED__

