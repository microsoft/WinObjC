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
#import <CloudKit/CKDatabaseOperation.h>

@class CKRecordZoneID;
@class CKServerChangeToken;
@class NSArray;
@class CKRecord;
@class CKRecordID;
@class NSData;
@class NSError;

CLOUDKIT_EXPORT_CLASS
@interface CKFetchRecordChangesOperation : CKDatabaseOperation
- (instancetype)initWithRecordZoneID:(CKRecordZoneID*)recordZoneID
           previousServerChangeToken:(CKServerChangeToken*)previousServerChangeToken STUB_METHOD;
@property (copy, nonatomic) CKRecordZoneID* recordZoneID STUB_PROPERTY;
@property (copy, nonatomic) CKServerChangeToken* previousServerChangeToken STUB_PROPERTY;
@property (copy, nonatomic) NSArray* desiredKeys STUB_PROPERTY;
@property (assign, nonatomic) NSUInteger resultsLimit STUB_PROPERTY;
@property (copy, nonatomic, nonnull) void (^recordChangedBlock)(CKRecord*) STUB_PROPERTY;
@property (copy, nonatomic, nonnull) void (^recordWithIDWasDeletedBlock)(CKRecordID*) STUB_PROPERTY;
@property (copy, nonatomic, nullable) void (^fetchRecordChangesCompletionBlock)(CKServerChangeToken*, NSData*, NSError*) STUB_PROPERTY;
@property (readonly, nonatomic) BOOL moreComing STUB_PROPERTY;
@end