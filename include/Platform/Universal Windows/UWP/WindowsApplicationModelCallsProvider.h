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

// WindowsApplicationModelCallsProvider.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_APPLICATIONMODEL_CALLS_PROVIDER_EXPORT
#define OBJCUWP_WINDOWS_APPLICATIONMODEL_CALLS_PROVIDER_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_ApplicationModel_Calls_Provider.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WACPPhoneCallOrigin, WACPPhoneCallOriginManager;
@protocol WACPIPhoneCallOrigin, WACPIPhoneCallOrigin2, WACPIPhoneCallOrigin3, WACPIPhoneCallOriginManagerStatics, WACPIPhoneCallOriginManagerStatics2;

#include "WindowsStorage.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Calls.Provider.PhoneCallOrigin
#ifndef __WACPPhoneCallOrigin_DEFINED__
#define __WACPPhoneCallOrigin_DEFINED__

OBJCUWP_WINDOWS_APPLICATIONMODEL_CALLS_PROVIDER_EXPORT
@interface WACPPhoneCallOrigin : RTObject
+ (instancetype)make ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (retain) NSString * location;
@property (retain) NSString * categoryDescription;
@property (retain) NSString * category;
@property (retain) NSString * displayName;
@property (retain) WSStorageFile* displayPicture;
@end

#endif // __WACPPhoneCallOrigin_DEFINED__

// Windows.ApplicationModel.Calls.Provider.PhoneCallOriginManager
#ifndef __WACPPhoneCallOriginManager_DEFINED__
#define __WACPPhoneCallOriginManager_DEFINED__

OBJCUWP_WINDOWS_APPLICATIONMODEL_CALLS_PROVIDER_EXPORT
@interface WACPPhoneCallOriginManager : RTObject
+ (void)showPhoneCallOriginSettingsUI;
+ (void)setCallOrigin:(WFGUID*)requestId callOrigin:(WACPPhoneCallOrigin*)callOrigin;
+ (void)requestSetAsActiveCallOriginAppAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
+ (void)showPhoneCallOriginSettingsUI;
+ (void)setCallOrigin:(WFGUID*)requestId callOrigin:(WACPPhoneCallOrigin*)callOrigin;
+ (BOOL)isCurrentAppActiveCallOriginApp;
@end

#endif // __WACPPhoneCallOriginManager_DEFINED__

