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

@class CKQuery;
@class CKRecordZoneID;
@class NSArray;
@class NSError;
@class CKDatabaseOperation;
@class CKRecordID;
@class CKRecord;
@class CKRecordZone;
@class NSString;
@class CKSubscription;

CLOUDKIT_EXPORT_CLASS
@interface CKDatabase : NSObject
- (void)performQuery:(CKQuery*)query
        inZoneWithID:(CKRecordZoneID*)zoneID
   completionHandler:(void (^)(NSArray*, NSError*))completionHandler STUB_METHOD;
- (void)addOperation:(CKDatabaseOperation*)operation STUB_METHOD;
- (void)fetchRecordWithID:(CKRecordID*)recordID completionHandler:(void (^)(CKRecord*, NSError*))completionHandler STUB_METHOD;
- (void)saveRecord:(CKRecord*)record completionHandler:(void (^)(CKRecord*, NSError*))completionHandler STUB_METHOD;
- (void)deleteRecordWithID:(CKRecordID*)recordID completionHandler:(void (^)(CKRecordID*, NSError*))completionHandler STUB_METHOD;
- (void)fetchAllRecordZonesWithCompletionHandler:(void (^)(NSArray*, NSError*))completionHandler STUB_METHOD;
- (void)fetchRecordZoneWithID:(CKRecordZoneID*)zoneID completionHandler:(void (^)(CKRecordZone*, NSError*))completionHandler STUB_METHOD;
- (void)saveRecordZone:(CKRecordZone*)zone completionHandler:(void (^)(CKRecordZone*, NSError*))completionHandler STUB_METHOD;
- (void)deleteRecordZoneWithID:(CKRecordZoneID*)zoneID completionHandler:(void (^)(CKRecordZoneID*, NSError*))completionHandler STUB_METHOD;
- (void)fetchAllSubscriptionsWithCompletionHandler:(void (^)(NSArray*, NSError*))completionHandler STUB_METHOD;
- (void)fetchSubscriptionWithID:(NSString*)subscriptionID
              completionHandler:(void (^)(CKSubscription*, NSError*))completionHandler STUB_METHOD;
- (void)saveSubscription:(CKSubscription*)subscription completionHandler:(void (^)(CKSubscription*, NSError*))completionHandler STUB_METHOD;
- (void)deleteSubscriptionWithID:(NSString*)subscriptionID completionHandler:(void (^)(NSString*, NSError*))completionHandler STUB_METHOD;
@end