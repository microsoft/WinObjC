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
#import <CoreData/NSPersistentStoreRequest.h>

@class NSString;
@class NSEntityDescription;
@class NSPredicate;
@class NSArray;

typedef NS_ENUM(NSUInteger, NSFetchRequestResultType) {
    NSManagedObjectResultType = 0x00,
    NSManagedObjectIDResultType = 0x01,
    NSDictionaryResultType = 0x02,
    NSCountResultType = 0x04
};

COREDATA_EXPORT_CLASS
@interface NSFetchRequest : NSPersistentStoreRequest <NSCoding, NSCopying>
+ (instancetype)fetchRequestWithEntityName:(NSString*)entityName STUB_METHOD;
- (instancetype)initWithEntityName:(NSString*)entityName STUB_METHOD;
@property (readonly, nonatomic, strong) NSString* entityName STUB_PROPERTY;
@property (nonatomic, strong) NSEntityDescription* entity STUB_PROPERTY;
@property (nonatomic) BOOL includesSubentities STUB_PROPERTY;
@property (nonatomic, strong) NSPredicate* predicate STUB_PROPERTY;
@property (nonatomic) NSUInteger fetchLimit STUB_PROPERTY;
@property (nonatomic) NSUInteger fetchOffset STUB_PROPERTY;
@property (nonatomic) NSUInteger fetchBatchSize STUB_PROPERTY;
@property (nonatomic, strong) NSArray* affectedStores STUB_PROPERTY;
@property (nonatomic, strong) NSArray* sortDescriptors STUB_PROPERTY;
@property (copy, nonatomic) NSArray* relationshipKeyPathsForPrefetching STUB_PROPERTY;
@property (nonatomic) NSFetchRequestResultType resultType STUB_PROPERTY;
@property (nonatomic) BOOL includesPendingChanges STUB_PROPERTY;
@property (copy, nonatomic) NSArray* propertiesToFetch STUB_PROPERTY;
@property (nonatomic) BOOL returnsDistinctResults STUB_PROPERTY;
@property (nonatomic) BOOL includesPropertyValues STUB_PROPERTY;
@property (nonatomic) BOOL shouldRefreshRefetchedObjects STUB_PROPERTY;
@property (nonatomic) BOOL returnsObjectsAsFaults STUB_PROPERTY;
@property (copy, nonatomic) NSArray* propertiesToGroupBy STUB_PROPERTY;
@property (nonatomic, strong) NSPredicate* havingPredicate STUB_PROPERTY;
@end
