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

@class ACAccountType;
@class ACAccountCredential;

ACCOUNTS_EXPORT NSString* const ACErrorDomain;

typedef NS_ENUM(NSUInteger, ACErrorCode) {
    ACErrorUnknown = 1,
    ACErrorAccountMissingRequiredProperty,
    ACErrorAccountAuthenticationFailed,
    ACErrorAccountTypeInvalid,
    ACErrorAccountAlreadyExists,
    ACErrorAccountNotFound,
    ACErrorPermissionDenied,
    ACErrorAccessInfoInvalid,
    ACErrorClientPermissionDenied,
    ACErrorAccessDeniedByProtectionPolicy,
    ACErrorCredentialNotFound,
    ACErrorFetchCredentialFailed,
    ACErrorStoreCredentialFailed,
    ACErrorRemoveCredentialFailed,
    ACErrorUpdatingNonexistentAccount,
    ACErrorInvalidClientBundleID,
};

ACCOUNTS_EXPORT_CLASS
@interface ACAccount : NSObject

@property (copy, nonatomic) NSString* accountDescription STUB_PROPERTY;
@property (strong, nonatomic) ACAccountType* accountType STUB_PROPERTY;
@property (strong, nonatomic) ACAccountCredential* credential STUB_PROPERTY;
@property (readonly, weak, nonatomic) NSString* identifier STUB_PROPERTY;
@property (copy, nonatomic) NSString* username STUB_PROPERTY;
@property (copy, nonatomic) NSString* userFullName STUB_PROPERTY;

- (instancetype)initWithAccountType:(ACAccountType*)type STUB_METHOD;
@end