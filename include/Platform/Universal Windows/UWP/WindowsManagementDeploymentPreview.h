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

// WindowsManagementDeploymentPreview.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSMANAGEMENTDEPLOYMENTPREVIEWEXPORT
#define OBJCUWPWINDOWSMANAGEMENTDEPLOYMENTPREVIEWEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsManagementDeploymentPreview.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WMDPInstalledClassicAppInfo, WMDPClassicAppManager;
@protocol WMDPIInstalledClassicAppInfo, WMDPIClassicAppManagerStatics;

#import <Foundation/Foundation.h>

// Windows.Management.Deployment.Preview.InstalledClassicAppInfo
#ifndef __WMDPInstalledClassicAppInfo_DEFINED__
#define __WMDPInstalledClassicAppInfo_DEFINED__

OBJCUWPWINDOWSMANAGEMENTDEPLOYMENTPREVIEWEXPORT
@interface WMDPInstalledClassicAppInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * displayName;
@property (readonly) NSString * displayVersion;
@end

#endif // __WMDPInstalledClassicAppInfo_DEFINED__

// Windows.Management.Deployment.Preview.ClassicAppManager
#ifndef __WMDPClassicAppManager_DEFINED__
#define __WMDPClassicAppManager_DEFINED__

OBJCUWPWINDOWSMANAGEMENTDEPLOYMENTPREVIEWEXPORT
@interface WMDPClassicAppManager : RTObject
+ (WMDPInstalledClassicAppInfo*)findInstalledApp:(NSString *)appUninstallKey;
@end

#endif // __WMDPClassicAppManager_DEFINED__

