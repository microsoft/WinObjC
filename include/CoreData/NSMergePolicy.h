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

#import <CoreData/CoreDataExport.h>
#import <Foundation/NSObject.h>

@class NSArray;
@class NSError;

typedef NS_ENUM(NSUInteger, NSMergePolicyType) {
    NSErrorMergePolicyType = 0x00,
    NSMergeByPropertyStoreTrumpMergePolicyType = 0x01,
    NSMergeByPropertyObjectTrumpMergePolicyType = 0x02,
    NSOverwriteMergePolicyType = 0x03,
    NSRollbackMergePolicyType = 0x04
};

COREDATA_EXPORT const id NSErrorMergePolicy;
COREDATA_EXPORT const id NSMergeByPropertyStoreTrumpMergePolicy;
COREDATA_EXPORT const id NSMergeByPropertyObjectTrumpMergePolicy;
COREDATA_EXPORT const id NSOverwriteMergePolicy;
COREDATA_EXPORT const id NSRollbackMergePolicy;

COREDATA_EXPORT_CLASS
@interface NSMergePolicy : NSObject
- (id)initWithMergeType:(NSMergePolicyType)ty STUB_METHOD;
- (BOOL)resolveConflicts:(NSArray*)list error:(NSError* _Nullable*)error STUB_METHOD;
@property (readonly) NSMergePolicyType mergeType STUB_PROPERTY;
@end
