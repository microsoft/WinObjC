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

// WindowsApplicationModelUserDataAccountsProvider.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
#define OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsConsolidatedNamespace.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WAUPUserDataAccountPartnerAccountInfo, WAUPUserDataAccountProviderAddAccountOperation, WAUPUserDataAccountProviderSettingsOperation, WAUPUserDataAccountProviderResolveErrorsOperation;
@protocol WAUPIUserDataAccountProviderOperation, WAUPIUserDataAccountProviderAddAccountOperation, WAUPIUserDataAccountPartnerAccountInfo, WAUPIUserDataAccountProviderSettingsOperation, WAUPIUserDataAccountProviderResolveErrorsOperation;

// Windows.ApplicationModel.UserDataAccounts.Provider.UserDataAccountProviderOperationKind
enum _WAUPUserDataAccountProviderOperationKind {
    WAUPUserDataAccountProviderOperationKindAddAccount = 0,
    WAUPUserDataAccountProviderOperationKindSettings = 1,
    WAUPUserDataAccountProviderOperationKindResolveErrors = 2,
};
typedef unsigned WAUPUserDataAccountProviderOperationKind;

// Windows.ApplicationModel.UserDataAccounts.Provider.UserDataAccountProviderPartnerAccountKind
enum _WAUPUserDataAccountProviderPartnerAccountKind {
    WAUPUserDataAccountProviderPartnerAccountKindExchange = 0,
    WAUPUserDataAccountProviderPartnerAccountKindPopOrImap = 1,
};
typedef unsigned WAUPUserDataAccountProviderPartnerAccountKind;

#include "WindowsApplicationModelUserDataAccounts.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.UserDataAccounts.Provider.IUserDataAccountProviderOperation
#ifndef __WAUPIUserDataAccountProviderOperation_DEFINED__
#define __WAUPIUserDataAccountProviderOperation_DEFINED__

@protocol WAUPIUserDataAccountProviderOperation
@property (readonly) WAUPUserDataAccountProviderOperationKind kind;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAUPIUserDataAccountProviderOperation : RTObject <WAUPIUserDataAccountProviderOperation>
@end

#endif // __WAUPIUserDataAccountProviderOperation_DEFINED__

// Windows.ApplicationModel.UserDataAccounts.Provider.UserDataAccountPartnerAccountInfo
#ifndef __WAUPUserDataAccountPartnerAccountInfo_DEFINED__
#define __WAUPUserDataAccountPartnerAccountInfo_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAUPUserDataAccountPartnerAccountInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAUPUserDataAccountProviderPartnerAccountKind accountKind;
@property (readonly) NSString * displayName;
@property (readonly) unsigned int priority;
@end

#endif // __WAUPUserDataAccountPartnerAccountInfo_DEFINED__

// Windows.ApplicationModel.UserDataAccounts.Provider.UserDataAccountProviderAddAccountOperation
#ifndef __WAUPUserDataAccountProviderAddAccountOperation_DEFINED__
#define __WAUPUserDataAccountProviderAddAccountOperation_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAUPUserDataAccountProviderAddAccountOperation : RTObject <WAUPIUserDataAccountProviderOperation>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAUUserDataAccountContentKinds contentKinds;
@property (readonly) NSArray* /* WAUPUserDataAccountPartnerAccountInfo* */ partnerAccountInfos;
@property (readonly) WAUPUserDataAccountProviderOperationKind kind;
- (void)reportCompleted:(NSString *)userDataAccountId;
@end

#endif // __WAUPUserDataAccountProviderAddAccountOperation_DEFINED__

// Windows.ApplicationModel.UserDataAccounts.Provider.UserDataAccountProviderSettingsOperation
#ifndef __WAUPUserDataAccountProviderSettingsOperation_DEFINED__
#define __WAUPUserDataAccountProviderSettingsOperation_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAUPUserDataAccountProviderSettingsOperation : RTObject <WAUPIUserDataAccountProviderOperation>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAUPUserDataAccountProviderOperationKind kind;
@property (readonly) NSString * userDataAccountId;
- (void)reportCompleted;
@end

#endif // __WAUPUserDataAccountProviderSettingsOperation_DEFINED__

// Windows.ApplicationModel.UserDataAccounts.Provider.UserDataAccountProviderResolveErrorsOperation
#ifndef __WAUPUserDataAccountProviderResolveErrorsOperation_DEFINED__
#define __WAUPUserDataAccountProviderResolveErrorsOperation_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAUPUserDataAccountProviderResolveErrorsOperation : RTObject <WAUPIUserDataAccountProviderOperation>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAUPUserDataAccountProviderOperationKind kind;
@property (readonly) NSString * userDataAccountId;
- (void)reportCompleted;
@end

#endif // __WAUPUserDataAccountProviderResolveErrorsOperation_DEFINED__

