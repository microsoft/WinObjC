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

@class NSString;
@class NSPredicate;
@class CKRecordZoneID;
@class CKNotificationInfo;

typedef enum : NSInteger {
    CKSubscriptionTypeQuery = 1,
    CKSubscriptionTypeRecordZone = 2,
} CKSubscriptionType;

typedef enum : NSUInteger {
    CKSubscriptionOptionsFiresOnRecordCreation = 1 << 0,
    CKSubscriptionOptionsFiresOnRecordUpdate = 1 << 1,
    CKSubscriptionOptionsFiresOnRecordDeletion = 1 << 2,
    CKSubscriptionOptionsFiresOnce = 1 << 3,
} CKSubscriptionOptions;

CLOUDKIT_EXPORT_CLASS
@interface CKSubscription : NSObject <NSCopying, NSSecureCoding>
- (instancetype)initWithRecordType:(NSString*)recordType
                         predicate:(NSPredicate*)predicate
                           options:(CKSubscriptionOptions)subscriptionOptions STUB_METHOD;
- (instancetype)initWithRecordType:(NSString*)recordType
                         predicate:(NSPredicate*)predicate
                    subscriptionID:(NSString*)subscriptionID
                           options:(CKSubscriptionOptions)subscriptionOptions STUB_METHOD;
- (instancetype)initWithZoneID:(CKRecordZoneID*)zoneID options:(CKSubscriptionOptions)subscriptionOptions STUB_METHOD;
- (instancetype)initWithZoneID:(CKRecordZoneID*)zoneID
                subscriptionID:(NSString*)subscriptionID
                       options:(CKSubscriptionOptions)subscriptionOptions STUB_METHOD;
@property (copy, nonatomic) CKRecordZoneID* zoneID STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* recordType STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSPredicate* predicate STUB_PROPERTY;
@property (copy, nonatomic) CKNotificationInfo* notificationInfo STUB_PROPERTY;
@property (readonly, assign, nonatomic) CKSubscriptionType subscriptionType STUB_PROPERTY;
@property (readonly, assign, nonatomic) CKSubscriptionOptions subscriptionOptions STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* subscriptionID STUB_PROPERTY;
@end
