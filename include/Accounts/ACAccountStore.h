//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#pragma once

#import <Foundation/Foundation.h>
#import <Accounts/ACAccountExport.h>

ACCOUNTS_EXPORT NSString* const ACFacebookAppIdKey;
ACCOUNTS_EXPORT NSString* const ACFacebookPermissionsKey;
ACCOUNTS_EXPORT NSString* const ACFacebookAudienceKey;
ACCOUNTS_EXPORT NSString* const ACFacebookAudienceEveryone;
ACCOUNTS_EXPORT NSString* const ACFacebookAudienceFriends;
ACCOUNTS_EXPORT NSString* const ACFacebookAudienceOnlyMe;
ACCOUNTS_EXPORT NSString* const ACTencentWeiboAppIdKey;

ACCOUNTS_EXPORT NSString* const ACAccountStoreDidChangeNotification;

typedef NS_ENUM(NSUInteger, ACAccountCredentialRenewResult) {
    ACAccountCredentialRenewResultRenewed,
    ACAccountCredentialRenewResultRejected,
    ACAccountCredentialRenewResultFailed,
};

typedef void(^ACAccountStoreSaveCompletionHandler)(BOOL success, NSError* error);
typedef void(^ACAccountStoreRemoveCompletionHandler)(BOOL success, NSError* error);
typedef void(^ACAccountStoreRequestAccessCompletionHandler)(BOOL granted, NSError* error);
typedef void(^ACAccountStoreCredentialRenewalHandler)(ACAccountCredentialRenewResult renewResult, NSError* error);

@class ACAccount;
@class ACAccountType;

ACCOUNTS_EXPORT_CLASS
@interface ACAccountStore : NSObject
@property (readonly, weak, nonatomic) NSArray* accounts;

- (ACAccount*)accountWithIdentifier:(NSString*)identifier;
- (NSArray*)accountsWithAccountType:(ACAccountType*)accountType;
- (ACAccountType*)accountTypeWithAccountTypeIdentifier:(NSString*)typeIdentifier;
- (void)saveAccount:(ACAccount*)account withCompletionHandler:(ACAccountStoreSaveCompletionHandler)completionHandler;
- (void)requestAccessToAccountsWithType:(ACAccountType*)accountType
        options:(NSDictionary*)options
        completion:(ACAccountStoreRequestAccessCompletionHandler)completion;
- (void)renewCredentialsForAccount:(ACAccount*)account completion:(ACAccountStoreCredentialRenewalHandler)completionHandler;
- (void)removeAccount:(ACAccount*)account withCompletionHandler:(ACAccountStoreRemoveCompletionHandler)completionHandler;


@end