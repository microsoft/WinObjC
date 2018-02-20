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

// WindowsApplicationModelUserDataAccounts.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
#define OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsConsolidatedNamespace.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WAUUserDataAccount, WAUUserDataAccountStore, WAUUserDataAccountStoreChangedEventArgs, WAUUserDataAccountManagerForUser, WAUUserDataAccountManager;
@protocol WAUIUserDataAccount, WAUIUserDataAccount2, WAUIUserDataAccount3, WAUIUserDataAccount4, WAUIUserDataAccountStore, WAUIUserDataAccountStore2, WAUIUserDataAccountStore3, WAUIUserDataAccountManagerStatics, WAUIUserDataAccountManagerStatics2, WAUIUserDataAccountManagerForUser, WAUIUserDataAccountStoreChangedEventArgs;

// Windows.ApplicationModel.UserDataAccounts.UserDataAccountOtherAppReadAccess
enum _WAUUserDataAccountOtherAppReadAccess {
    WAUUserDataAccountOtherAppReadAccessSystemOnly = 0,
    WAUUserDataAccountOtherAppReadAccessFull = 1,
    WAUUserDataAccountOtherAppReadAccessNone = 2,
};
typedef unsigned WAUUserDataAccountOtherAppReadAccess;

// Windows.ApplicationModel.UserDataAccounts.UserDataAccountStoreAccessType
enum _WAUUserDataAccountStoreAccessType {
    WAUUserDataAccountStoreAccessTypeAllAccountsReadOnly = 0,
    WAUUserDataAccountStoreAccessTypeAppAccountsReadWrite = 1,
};
typedef unsigned WAUUserDataAccountStoreAccessType;

// Windows.ApplicationModel.UserDataAccounts.UserDataAccountContentKinds
enum _WAUUserDataAccountContentKinds {
    WAUUserDataAccountContentKindsEmail = 1,
    WAUUserDataAccountContentKindsContact = 2,
    WAUUserDataAccountContentKindsAppointment = 4,
};
typedef unsigned WAUUserDataAccountContentKinds;

#include "WindowsFoundationCollections.h"
#include "WindowsApplicationModelContacts.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundation.h"
#include "WindowsApplicationModelEmail.h"
#include "WindowsApplicationModelAppointments.h"
#include "WindowsApplicationModelUserDataTasks.h"
#include "WindowsSystem.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.UserDataAccounts.UserDataAccount
#ifndef __WAUUserDataAccount_DEFINED__
#define __WAUUserDataAccount_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAUUserDataAccount : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * userDisplayName;
@property WAUUserDataAccountOtherAppReadAccess otherAppReadAccess;
@property (retain) RTObject<WSSIRandomAccessStreamReference>* icon;
@property (readonly) NSString * deviceAccountTypeId;
@property (readonly) NSString * id;
@property (readonly) NSString * packageFamilyName;
@property BOOL isProtectedUnderLock;
@property (readonly) NSString * enterpriseId;
@property (retain) NSString * displayName;
@property (readonly) NSMutableArray* /* NSString * */ explictReadAccessPackageFamilyNames;
@property BOOL canShowCreateContactGroup;
@property (readonly) RTObject<WFCIPropertySet>* providerProperties;
- (RTObject<WFIAsyncAction>*)saveAsync;
- (RTObject<WFIAsyncAction>*)deleteAsync;
- (void)findAppointmentCalendarsAsyncWithSuccess:(void (^)(NSArray* /* WAAAppointmentCalendar* */))success failure:(void (^)(NSError*))failure;
- (void)findEmailMailboxesAsyncWithSuccess:(void (^)(NSArray* /* WAEEmailMailbox* */))success failure:(void (^)(NSError*))failure;
- (void)findContactListsAsyncWithSuccess:(void (^)(NSArray* /* WACContactList* */))success failure:(void (^)(NSError*))failure;
- (void)findContactAnnotationListsAsyncWithSuccess:(void (^)(NSArray* /* WACContactAnnotationList* */))success failure:(void (^)(NSError*))failure;
- (void)findUserDataTaskListsAsyncWithSuccess:(void (^)(NSArray* /* WAUUserDataTaskList* */))success failure:(void (^)(NSError*))failure;
- (void)findContactGroupsAsyncWithSuccess:(void (^)(NSArray* /* WACContactGroup* */))success failure:(void (^)(NSError*))failure;
- (void)tryShowCreateContactGroupAsyncWithSuccess:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
@end

#endif // __WAUUserDataAccount_DEFINED__

// Windows.ApplicationModel.UserDataAccounts.UserDataAccountStore
#ifndef __WAUUserDataAccountStore_DEFINED__
#define __WAUUserDataAccountStore_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAUUserDataAccountStore : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addStoreChangedEvent:(void(^)(WAUUserDataAccountStore*, WAUUserDataAccountStoreChangedEventArgs*))del;
- (void)removeStoreChangedEvent:(EventRegistrationToken)tok;
- (void)findAccountsAsyncWithSuccess:(void (^)(NSArray* /* WAUUserDataAccount* */))success failure:(void (^)(NSError*))failure;
- (void)getAccountAsync:(NSString *)id success:(void (^)(WAUUserDataAccount*))success failure:(void (^)(NSError*))failure;
- (void)createAccountAsync:(NSString *)userDisplayName success:(void (^)(WAUUserDataAccount*))success failure:(void (^)(NSError*))failure;
- (void)createAccountWithPackageRelativeAppIdAsync:(NSString *)userDisplayName packageRelativeAppId:(NSString *)packageRelativeAppId success:(void (^)(WAUUserDataAccount*))success failure:(void (^)(NSError*))failure;
- (void)createAccountWithPackageRelativeAppIdAndEnterpriseIdAsync:(NSString *)userDisplayName packageRelativeAppId:(NSString *)packageRelativeAppId enterpriseId:(NSString *)enterpriseId success:(void (^)(WAUUserDataAccount*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WAUUserDataAccountStore_DEFINED__

// Windows.ApplicationModel.UserDataAccounts.UserDataAccountStoreChangedEventArgs
#ifndef __WAUUserDataAccountStoreChangedEventArgs_DEFINED__
#define __WAUUserDataAccountStoreChangedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAUUserDataAccountStoreChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WFDeferral*)getDeferral;
@end

#endif // __WAUUserDataAccountStoreChangedEventArgs_DEFINED__

// Windows.ApplicationModel.UserDataAccounts.UserDataAccountManagerForUser
#ifndef __WAUUserDataAccountManagerForUser_DEFINED__
#define __WAUUserDataAccountManagerForUser_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAUUserDataAccountManagerForUser : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSUser* user;
- (void)requestStoreAsync:(WAUUserDataAccountStoreAccessType)storeAccessType success:(void (^)(WAUUserDataAccountStore*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WAUUserDataAccountManagerForUser_DEFINED__

// Windows.ApplicationModel.UserDataAccounts.UserDataAccountManager
#ifndef __WAUUserDataAccountManager_DEFINED__
#define __WAUUserDataAccountManager_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAUUserDataAccountManager : RTObject
+ (void)requestStoreAsync:(WAUUserDataAccountStoreAccessType)storeAccessType success:(void (^)(WAUUserDataAccountStore*))success failure:(void (^)(NSError*))failure;
+ (void)showAddAccountAsync:(WAUUserDataAccountContentKinds)contentKinds success:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
+ (RTObject<WFIAsyncAction>*)showAccountSettingsAsync:(NSString *)id;
+ (RTObject<WFIAsyncAction>*)showAccountErrorResolverAsync:(NSString *)id;
+ (WAUUserDataAccountManagerForUser*)getForUser:(WSUser*)user;
@end

#endif // __WAUUserDataAccountManager_DEFINED__

