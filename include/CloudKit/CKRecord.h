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
@class CKRecordZoneID;
@class CKRecordID;
@protocol CKRecordValue;
@class NSArray;
@class NSDate;
@class NSCoder;

CLOUDKIT_EXPORT NSString* const CKRecordTypeUserRecord;

CLOUDKIT_EXPORT_CLASS
@interface CKRecord : NSObject <NSCopying, NSSecureCoding>
- (instancetype)initWithRecordType:(NSString*)recordType STUB_METHOD;
- (instancetype)initWithRecordType:(NSString*)recordType zoneID:(CKRecordZoneID*)zoneID STUB_METHOD;
- (instancetype)initWithRecordType:(NSString*)recordType recordID:(CKRecordID*)recordID STUB_METHOD;
- (id<CKRecordValue>)objectForKey:(NSString*)key STUB_METHOD;
- (void)setObject:(id<CKRecordValue>)obj forKey:(NSString*)key STUB_METHOD;
- (id<CKRecordValue>)objectForKeyedSubscript:(NSString*)key STUB_METHOD;
- (void)setObject:(id<CKRecordValue>)obj forKeyedSubscript:(NSString*)key STUB_METHOD;
- (NSArray*)allKeys STUB_METHOD;
- (NSArray*)changedKeys STUB_METHOD;
@property (readonly, copy, nonatomic) CKRecordID* recordID STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* recordType STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSDate* creationDate STUB_PROPERTY;
@property (readonly, copy, nonatomic) CKRecordID* creatorUserRecordID STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSDate* modificationDate STUB_PROPERTY;
@property (readonly, copy, nonatomic) CKRecordID* lastModifiedUserRecordID STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* recordChangeTag STUB_PROPERTY;
- (NSArray*)allTokens STUB_METHOD;
- (void)encodeSystemFieldsWithCoder:(NSCoder*)coder STUB_METHOD;
@end
