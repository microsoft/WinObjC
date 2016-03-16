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
#import <CloudKit/CKDatabase.h>
#import "AssertARCEnabled.h"

@implementation CKDatabase
/**
 @Status Stub
 @Notes
*/
- (void)performQuery:(CKQuery*)query
        inZoneWithID:(CKRecordZoneID*)zoneID
   completionHandler:(void (^)(NSArray*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)addOperation:(CKDatabaseOperation*)operation {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)fetchRecordWithID:(CKRecordID*)recordID completionHandler:(void (^)(CKRecord*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)saveRecord:(CKRecord*)record completionHandler:(void (^)(CKRecord*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)deleteRecordWithID:(CKRecordID*)recordID completionHandler:(void (^)(CKRecordID*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)fetchAllRecordZonesWithCompletionHandler:(void (^)(NSArray*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)fetchRecordZoneWithID:(CKRecordZoneID*)zoneID completionHandler:(void (^)(CKRecordZone*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)saveRecordZone:(CKRecordZone*)zone completionHandler:(void (^)(CKRecordZone*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)deleteRecordZoneWithID:(CKRecordZoneID*)zoneID completionHandler:(void (^)(CKRecordZoneID*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)fetchAllSubscriptionsWithCompletionHandler:(void (^)(NSArray*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)fetchSubscriptionWithID:(NSString*)subscriptionID completionHandler:(void (^)(CKSubscription*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)saveSubscription:(CKSubscription*)subscription completionHandler:(void (^)(CKSubscription*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)deleteSubscriptionWithID:(NSString*)subscriptionID completionHandler:(void (^)(NSString*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

@end
