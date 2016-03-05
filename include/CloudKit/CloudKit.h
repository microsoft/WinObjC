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

#import <StubIncludes.h>
#import <CloudKit/CKAsset.h>
#import <CloudKit/CKContainer.h>
#import <CloudKit/CKDatabase.h>
#import <CloudKit/CKDatabaseOperation.h>
#import <CloudKit/CKDiscoverAllContactsOperation.h>
#import <CloudKit/CKDiscoveredUserInfo.h>
#import <CloudKit/CKDiscoverUserInfosOperation.h>
#import <CloudKit/CKFetchNotificationChangesOperation.h>
#import <CloudKit/CKFetchRecordChangesOperation.h>
#import <CloudKit/CKFetchRecordsOperation.h>
#import <CloudKit/CKFetchRecordZonesOperation.h>
#import <CloudKit/CKFetchSubscriptionsOperation.h>
#import <CloudKit/CKLocationSortDescriptor.h>
#import <CloudKit/CKMarkNotificationsReadOperation.h>
#import <CloudKit/CKModifyBadgeOperation.h>
#import <CloudKit/CKModifyRecordsOperation.h>
#import <CloudKit/CKModifyRecordZonesOperation.h>
#import <CloudKit/CKModifySubscriptionsOperation.h>
#import <CloudKit/CKNotification.h>
#import <CloudKit/CKNotificationID.h>
#import <CloudKit/CKNotificationInfo.h>
#import <CloudKit/CKOperation.h>
#import <CloudKit/CKQuery.h>
#import <CloudKit/CKQueryCursor.h>
#import <CloudKit/CKQueryNotification.h>
#import <CloudKit/CKQueryOperation.h>
#import <CloudKit/CKRecord.h>
#import <CloudKit/CKRecordID.h>
#import <CloudKit/CKRecordValue.h>
#import <CloudKit/CKRecordZone.h>
#import <CloudKit/CKRecordZoneID.h>
#import <CloudKit/CKRecordZoneNotification.h>
#import <CloudKit/CKReference.h>
#import <CloudKit/CKServerChangeToken.h>
#import <CloudKit/CKSubscription.h>
#import <CloudKit/CloudKitExport.h>
#import <CloudKit/CloudKitFrameworkConstants.h>