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

// WindowsManagementDeploymentPreview.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_MANAGEMENT_DEPLOYMENT_PREVIEW_EXPORT
#define OBJCUWP_WINDOWS_MANAGEMENT_DEPLOYMENT_PREVIEW_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_Management_Deployment_Preview.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WMDPInstalledClassicAppInfo, WMDPClassicAppManager;
@protocol WMDPIInstalledClassicAppInfo, WMDPIClassicAppManagerStatics;

#import <Foundation/Foundation.h>

// Windows.Management.Deployment.Preview.InstalledClassicAppInfo
#ifndef __WMDPInstalledClassicAppInfo_DEFINED__
#define __WMDPInstalledClassicAppInfo_DEFINED__

OBJCUWP_WINDOWS_MANAGEMENT_DEPLOYMENT_PREVIEW_EXPORT
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

OBJCUWP_WINDOWS_MANAGEMENT_DEPLOYMENT_PREVIEW_EXPORT
@interface WMDPClassicAppManager : RTObject
+ (WMDPInstalledClassicAppInfo*)findInstalledApp:(NSString *)appUninstallKey;
@end

#endif // __WMDPClassicAppManager_DEFINED__

