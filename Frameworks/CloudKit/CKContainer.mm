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

#import <StubReturn.h>
#import <CloudKit/CKContainer.h>
#import "AssertARCEnabled.h"

NSString* const CKOwnerDefaultName = @"CKOwnerDefaultName";
NSString* const CKAccountChangedNotification = @"CKAccountChangedNotification";

@implementation CKContainer
/**
 @Status Stub
 @Notes
*/
+ (CKContainer*)defaultContainer {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (CKContainer*)containerWithIdentifier:(NSString*)containerIdentifier {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)accountStatusWithCompletionHandler:(void (^)(CKAccountStatus, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)requestApplicationPermission:(CKApplicationPermissions)applicationPermission
                   completionHandler:(CKApplicationPermissionBlock)completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)statusForApplicationPermission:(CKApplicationPermissions)applicationPermission
                     completionHandler:(CKApplicationPermissionBlock)completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)addOperation:(CKOperation*)operation {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)discoverAllContactUserInfosWithCompletionHandler:(void (^)(NSArray*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)discoverUserInfoWithEmailAddress:(NSString*)email completionHandler:(void (^)(CKDiscoveredUserInfo*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)discoverUserInfoWithUserRecordID:(CKRecordID*)userRecordID
                       completionHandler:(void (^)(CKDiscoveredUserInfo*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)fetchUserRecordIDWithCompletionHandler:(void (^)(CKRecordID*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

@end
