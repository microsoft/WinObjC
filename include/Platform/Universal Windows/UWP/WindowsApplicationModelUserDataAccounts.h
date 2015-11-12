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

// WindowsApplicationModelUserDataAccounts.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WAUUserDataAccount, WAUUserDataAccountStore, WAUUserDataAccountManager;
@protocol WAUIUserDataAccount
, WAUIUserDataAccountStore, WAUIUserDataAccountManagerStatics;

// Windows.ApplicationModel.UserDataAccounts.UserDataAccountOtherAppReadAccess
enum _WAUUserDataAccountOtherAppReadAccess {
    WAUUserDataAccountOtherAppReadAccessSystemOnly = 0,
    WAUUserDataAccountOtherAppReadAccessFull = 1,
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

#include "WindowsApplicationModelContacts.h"
#include "WindowsFoundationCollections.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundation.h"
#include "WindowsApplicationModelEmail.h"
#include "WindowsApplicationModelAppointments.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.UserDataAccounts.UserDataAccount
#ifndef __WAUUserDataAccount_DEFINED__
#define __WAUUserDataAccount_DEFINED__

WINRT_EXPORT
@interface WAUUserDataAccount : RTObject
@property (copy) NSString* userDisplayName;
@property WAUUserDataAccountOtherAppReadAccess otherAppReadAccess;
@property (readonly) NSString* deviceAccountTypeId;
@property (readonly) RTObject<WSSIRandomAccessStreamReference>* icon;
@property (readonly) NSString* id;
@property (readonly) NSString* packageFamilyName;
- (RTObject<WFIAsyncAction>*)saveAsync;
- (RTObject<WFIAsyncAction>*)deleteAsync;
- (void)findAppointmentCalendarsAsyncWithSuccess:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
- (void)findEmailMailboxesAsyncWithSuccess:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
- (void)findContactListsAsyncWithSuccess:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
- (void)findContactAnnotationListsAsyncWithSuccess:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WAUUserDataAccount_DEFINED__

// Windows.ApplicationModel.UserDataAccounts.UserDataAccountStore
#ifndef __WAUUserDataAccountStore_DEFINED__
#define __WAUUserDataAccountStore_DEFINED__

WINRT_EXPORT
@interface WAUUserDataAccountStore : RTObject
- (void)findAccountsAsyncWithSuccess:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
- (void)getAccountAsync:(NSString*)id success:(void (^)(WAUUserDataAccount*))success failure:(void (^)(NSError*))failure;
- (void)createAccountAsync:(NSString*)userDisplayName success:(void (^)(WAUUserDataAccount*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WAUUserDataAccountStore_DEFINED__

// Windows.ApplicationModel.UserDataAccounts.UserDataAccountManager
#ifndef __WAUUserDataAccountManager_DEFINED__
#define __WAUUserDataAccountManager_DEFINED__

WINRT_EXPORT
@interface WAUUserDataAccountManager : RTObject
+ (void)requestStoreAsync:(WAUUserDataAccountStoreAccessType)storeAccessType
                  success:(void (^)(WAUUserDataAccountStore*))success
                  failure:(void (^)(NSError*))failure;
+ (void)showAddAccountAsync:(WAUUserDataAccountContentKinds)contentKinds
                    success:(void (^)(NSString*))success
                    failure:(void (^)(NSError*))failure;
+ (RTObject<WFIAsyncAction>*)showAccountSettingsAsync:(NSString*)id;
+ (RTObject<WFIAsyncAction>*)showAccountErrorResolverAsync:(NSString*)id;
@end

#endif // __WAUUserDataAccountManager_DEFINED__
