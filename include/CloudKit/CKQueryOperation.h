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

@class CKQuery;
@class CKQueryCursor;
@class CKRecordZoneID;
@class NSArray;
@class CKRecord;
@class NSError;

CLOUDKIT_EXPORT const NSUInteger CKQueryOperationMaximumResults;

CLOUDKIT_EXPORT_CLASS
@interface CKQueryOperation : CKDatabaseOperation
- (instancetype)initWithQuery:(CKQuery*)query STUB_METHOD;
- (instancetype)initWithCursor:(CKQueryCursor*)cursor STUB_METHOD;
@property (copy, nonatomic) CKQuery* query STUB_PROPERTY;
@property (copy, nonatomic) CKQueryCursor* cursor STUB_PROPERTY;
@property (copy, nonatomic) CKRecordZoneID* zoneID STUB_PROPERTY;
@property (assign, nonatomic) NSUInteger resultsLimit STUB_PROPERTY;
@property (copy, nonatomic) NSArray* desiredKeys STUB_PROPERTY;
@property (copy, nonatomic, nonnull) void (^recordFetchedBlock)(CKRecord*) STUB_PROPERTY;
@property (copy, nonatomic, nullable) void (^queryCompletionBlock)(CKQueryCursor*, NSError*) STUB_PROPERTY;
@end