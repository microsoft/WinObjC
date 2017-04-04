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

#ifndef OBJCUWPWINDOWSAPPLICATIONMODELCALLSPROVIDEREXPORT
#define OBJCUWPWINDOWSAPPLICATIONMODELCALLSPROVIDEREXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsApplicationModelCallsProvider.lib")
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

OBJCUWPWINDOWSAPPLICATIONMODELCALLSPROVIDEREXPORT
@interface WACPPhoneCallOrigin : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
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

OBJCUWPWINDOWSAPPLICATIONMODELCALLSPROVIDEREXPORT
@interface WACPPhoneCallOriginManager : RTObject
+ (void)showPhoneCallOriginSettingsUI;
+ (void)setCallOrigin:(WFGUID*)requestId callOrigin:(WACPPhoneCallOrigin*)callOrigin;
+ (void)requestSetAsActiveCallOriginAppAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
+ (void)showPhoneCallOriginSettingsUI;
+ (void)setCallOrigin:(WFGUID*)requestId callOrigin:(WACPPhoneCallOrigin*)callOrigin;
+ (BOOL)isCurrentAppActiveCallOriginApp;
@end

#endif // __WACPPhoneCallOriginManager_DEFINED__

