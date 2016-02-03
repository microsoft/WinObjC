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

@class NSArray;
@class NSData;
@class CKRecord;
@class NSError;

typedef enum : NSInteger {
    CKRecordSaveIfServerRecordUnchanged = 0,
    CKRecordSaveChangedKeys = 1,
    CKRecordSaveAllKeys = 2,
} CKRecordSavePolicy;

CLOUDKIT_EXPORT_CLASS
@interface CKModifyRecordsOperation : CKDatabaseOperation
- (instancetype)initWithRecordsToSave:(NSArray*)records recordIDsToDelete:(NSArray*)recordIDs STUB_METHOD;
@property (copy, nonatomic) NSArray* recordsToSave STUB_PROPERTY;
@property (copy, nonatomic) NSArray* recordIDsToDelete STUB_PROPERTY;
@property (assign, nonatomic) CKRecordSavePolicy savePolicy STUB_PROPERTY;
@property (copy, nonatomic) NSData* clientChangeTokenData STUB_PROPERTY;
@property (assign, nonatomic) BOOL atomic STUB_PROPERTY;
@property (copy, nonatomic, nonnull) void (^perRecordProgressBlock)(CKRecord*, double) STUB_PROPERTY;
@property (copy, nonatomic, nullable) void (^perRecordCompletionBlock)(CKRecord*, NSError*) STUB_PROPERTY;
@property (copy, nonatomic, nullable) void (^modifyRecordsCompletionBlock)(NSArray*, NSArray*, NSError*) STUB_PROPERTY;
@end