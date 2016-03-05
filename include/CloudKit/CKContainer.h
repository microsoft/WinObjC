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

#import <CloudKit/CloudKitExport.h>
#import <Foundation/NSObject.h>

@class NSError;
@class NSString;
@class CKDatabase;
@class CKOperation;
@class NSArray;
@class CKDiscoveredUserInfo;
@class CKRecordID;

typedef enum : NSInteger {
    CKApplicationPermissionStatusInitialState = 0,
    CKApplicationPermissionStatusCouldNotComplete = 1,
    CKApplicationPermissionStatusDenied = 2,
    CKApplicationPermissionStatusGranted = 3,
} CKApplicationPermissionStatus;

typedef void (^CKApplicationPermissionBlock)(CKApplicationPermissionStatus applicationPermissionStatus, NSError* error);

typedef enum : NSInteger {
    CKAccountStatusCouldNotDetermine = 0,
    CKAccountStatusAvailable = 1,
    CKAccountStatusRestricted = 2,
    CKAccountStatusNoAccount = 3,
} CKAccountStatus;

typedef enum : NSInteger {
    CKApplicationPermissionUserDiscoverability = 1 << 0,
} CKApplicationPermissions;

CLOUDKIT_EXPORT NSString* const CKOwnerDefaultName;
CLOUDKIT_EXPORT NSString* const CKAccountChangedNotification;

CLOUDKIT_EXPORT_CLASS
@interface CKContainer : NSObject
+ (CKContainer*)defaultContainer STUB_METHOD;
+ (CKContainer*)containerWithIdentifier:(NSString*)containerIdentifier STUB_METHOD;
@property (readonly, nonatomic) CKDatabase* privateCloudDatabase STUB_PROPERTY;
@property (readonly, nonatomic) CKDatabase* publicCloudDatabase STUB_PROPERTY;
@property (readonly, nonatomic) NSString* containerIdentifier STUB_PROPERTY;
- (void)accountStatusWithCompletionHandler:(void (^)(CKAccountStatus, NSError*))completionHandler STUB_METHOD;
- (void)requestApplicationPermission:(CKApplicationPermissions)applicationPermission
                   completionHandler:(CKApplicationPermissionBlock)completionHandler STUB_METHOD;
- (void)statusForApplicationPermission:(CKApplicationPermissions)applicationPermission
                     completionHandler:(CKApplicationPermissionBlock)completionHandler STUB_METHOD;
- (void)addOperation:(CKOperation*)operation STUB_METHOD;
- (void)discoverAllContactUserInfosWithCompletionHandler:(void (^)(NSArray*, NSError*))completionHandler STUB_METHOD;
- (void)discoverUserInfoWithEmailAddress:(NSString*)email
                       completionHandler:(void (^)(CKDiscoveredUserInfo*, NSError*))completionHandler STUB_METHOD;
- (void)discoverUserInfoWithUserRecordID:(CKRecordID*)userRecordID
                       completionHandler:(void (^)(CKDiscoveredUserInfo*, NSError*))completionHandler STUB_METHOD;
- (void)fetchUserRecordIDWithCompletionHandler:(void (^)(CKRecordID*, NSError*))completionHandler STUB_METHOD;
@end