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

#import "Accounts/Accounts.h"
#include "Starboard.h"
#import "AssertARCEnabled.h"

NSString* const ACFacebookAppIdKey = @"ACFacebookAppIdKey";
NSString* const ACFacebookPermissionsKey = @"ACFacebookPermissionsKey";
NSString* const ACFacebookAudienceKey = @"ACFacebookAudienceKey";
NSString* const ACFacebookAudienceEveryone = @"everyone";
NSString* const ACFacebookAudienceFriends = @"friends";
NSString* const ACFacebookAudienceOnlyMe = @"me";
NSString* const ACTencentWeiboAppIdKey = @"ACTencentWeiboAppIdKey";

NSString* const ACAccountStoreDidChangeNotification = @"ACAccountStoreDidChangeNotification";

@implementation ACAccountStore

/**
 @Status Stub
*/
- (ACAccount*)accountWithIdentifier:(NSString*)identifier {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
- (NSArray*)accountsWithAccountType:(ACAccountType*)accountType {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
- (ACAccountType*)accountTypeWithAccountTypeIdentifier:(NSString*)typeIdentifier {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
- (void)saveAccount:(ACAccount*)account withCompletionHandler:(ACAccountStoreSaveCompletionHandler)completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)requestAccessToAccountsWithType:(ACAccountType*)accountType
        options:(NSDictionary*)options
        completion:(ACAccountStoreRequestAccessCompletionHandler)completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)renewCredentialsForAccount:(ACAccount*)account completion:(ACAccountStoreCredentialRenewalHandler)completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)removeAccount:(ACAccount*)account withCompletionHandler:(ACAccountStoreRemoveCompletionHandler)completionHandler {
    UNIMPLEMENTED();
}

@end