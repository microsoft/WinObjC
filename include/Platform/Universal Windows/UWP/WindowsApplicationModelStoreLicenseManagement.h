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

// WindowsApplicationModelStoreLicenseManagement.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSAPPLICATIONMODELSTORELICENSEMANAGEMENTEXPORT
#define OBJCUWPWINDOWSAPPLICATIONMODELSTORELICENSEMANAGEMENTEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsApplicationModelStoreLicenseManagement.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WASLLicenseSatisfactionInfo, WASLLicenseSatisfactionResult, WASLLicenseManager;
@protocol WASLILicenseSatisfactionResult, WASLILicenseSatisfactionInfo, WASLILicenseManagerStatics, WASLILicenseManagerStatics2;

// Windows.ApplicationModel.Store.LicenseManagement.LicenseRefreshOption
enum _WASLLicenseRefreshOption {
    WASLLicenseRefreshOptionRunningLicenses = 0,
    WASLLicenseRefreshOptionAllLicenses = 1,
};
typedef unsigned WASLLicenseRefreshOption;

#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Store.LicenseManagement.LicenseSatisfactionInfo
#ifndef __WASLLicenseSatisfactionInfo_DEFINED__
#define __WASLLicenseSatisfactionInfo_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSTORELICENSEMANAGEMENTEXPORT
@interface WASLLicenseSatisfactionInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isSatisfied;
@property (readonly) BOOL satisfiedByDevice;
@property (readonly) BOOL satisfiedByInstallMedia;
@property (readonly) BOOL satisfiedByOpenLicense;
@property (readonly) BOOL satisfiedByPass;
@property (readonly) BOOL satisfiedBySignedInUser;
@property (readonly) BOOL satisfiedByTrial;
@end

#endif // __WASLLicenseSatisfactionInfo_DEFINED__

// Windows.ApplicationModel.Store.LicenseManagement.LicenseSatisfactionResult
#ifndef __WASLLicenseSatisfactionResult_DEFINED__
#define __WASLLicenseSatisfactionResult_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSTORELICENSEMANAGEMENTEXPORT
@interface WASLLicenseSatisfactionResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) HRESULT extendedError;
@property (readonly) NSDictionary* /* NSString *, WASLLicenseSatisfactionInfo* */ licenseSatisfactionInfos;
@end

#endif // __WASLLicenseSatisfactionResult_DEFINED__

// Windows.ApplicationModel.Store.LicenseManagement.LicenseManager
#ifndef __WASLLicenseManager_DEFINED__
#define __WASLLicenseManager_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSTORELICENSEMANAGEMENTEXPORT
@interface WASLLicenseManager : RTObject
+ (RTObject<WFIAsyncAction>*)refreshLicensesAsync:(WASLLicenseRefreshOption)refreshOption;
+ (RTObject<WFIAsyncAction>*)addLicenseAsync:(RTObject<WSSIBuffer>*)license;
+ (void)getSatisfactionInfosAsync:(id<NSFastEnumeration> /* NSString * */)contentIds keyIds:(id<NSFastEnumeration> /* NSString * */)keyIds success:(void (^)(WASLLicenseSatisfactionResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WASLLicenseManager_DEFINED__

