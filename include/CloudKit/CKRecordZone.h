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

typedef enum CKRecordZoneCapabilities : NSUInteger {
    CKRecordZoneCapabilityFetchChanges = 1 << 0,
    CKRecordZoneCapabilityAtomic = 1 << 1,
} CKRecordZoneCapabilities;

CLOUDKIT_EXPORT NSString* const CKRecordZoneDefaultName;

CLOUDKIT_EXPORT_CLASS
@interface CKRecordZone : NSObject <NSCopying, NSSecureCoding>
+ (CKRecordZone*)defaultRecordZone STUB_METHOD;
- (instancetype)initWithZoneName:(NSString*)zoneName STUB_METHOD;
- (instancetype)initWithZoneID:(CKRecordZoneID*)zoneID STUB_METHOD;
@property (readonly, nonatomic, strong) CKRecordZoneID* zoneID STUB_PROPERTY;
@property (readonly, assign, nonatomic) CKRecordZoneCapabilities capabilities STUB_PROPERTY;
@end
