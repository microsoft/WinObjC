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
#import <Foundation/NSKeyValueObserving.h>

@class NSEntityDescription;
@class NSManagedObjectContext;
@class NSManagedObjectID;
@class NSString;
@class NSDictionary;
@class NSArray;
@class NSMutableSet;
@class NSError;
@class NSSet;

typedef NS_ENUM(NSUInteger, NSSnapshotEventType) {
    NSSnapshotEventUndoInsertion = 1 << 1,
    NSSnapshotEventUndoDeletion = 1 << 2,
    NSSnapshotEventUndoUpdate = 1 << 3,
    NSSnapshotEventRollback = 1 << 4,
    NSSnapshotEventRefresh = 1 << 5,
    NSSnapshotEventMergePolicy = 1 << 6
};

COREDATA_EXPORT_CLASS
@interface NSManagedObject : NSObject
- (NSManagedObject*)initWithEntity:(NSEntityDescription*)entity insertIntoManagedObjectContext:(NSManagedObjectContext*)context STUB_METHOD;
@property (readonly, nonatomic, strong) NSEntityDescription* entity STUB_PROPERTY;
@property (readonly, nonatomic, strong) NSManagedObjectID* objectID STUB_PROPERTY;
@property (readonly, assign, nonatomic) NSManagedObjectContext* managedObjectContext STUB_PROPERTY;
@property (readonly, nonatomic) BOOL hasChanges STUB_PROPERTY;
@property (readonly, getter=isInserted, nonatomic) BOOL inserted STUB_PROPERTY;
@property (readonly, getter=isUpdated, nonatomic) BOOL updated STUB_PROPERTY;
@property (readonly, getter=isDeleted, nonatomic) BOOL deleted STUB_PROPERTY;
@property (readonly, getter=isFault, nonatomic) BOOL fault STUB_PROPERTY;
@property (readonly, nonatomic) NSUInteger faultingState STUB_PROPERTY;
- (BOOL)hasFaultForRelationshipNamed:(NSString*)key STUB_METHOD;
+ (BOOL)contextShouldIgnoreUnmodeledPropertyChanges STUB_METHOD;
- (void)awakeFromFetch STUB_METHOD;
- (void)awakeFromInsert STUB_METHOD;
- (void)awakeFromSnapshotEvents:(NSSnapshotEventType)flags STUB_METHOD;
- (NSDictionary*)changedValues STUB_METHOD;
- (NSDictionary*)changedValuesForCurrentEvent STUB_METHOD;
- (NSDictionary*)committedValuesForKeys:(NSArray*)keys STUB_METHOD;
- (void)prepareForDeletion STUB_METHOD;
- (void)willSave STUB_METHOD;
- (void)didSave STUB_METHOD;
- (void)willTurnIntoFault STUB_METHOD;
- (void)didTurnIntoFault STUB_METHOD;
- (id)valueForKey:(NSString*)key STUB_METHOD;
- (void)setValue:(id)value forKey:(NSString*)key STUB_METHOD;
- (NSMutableSet*)mutableSetValueForKey:(NSString*)key STUB_METHOD;
- (id)primitiveValueForKey:(NSString*)key STUB_METHOD;
- (void)setPrimitiveValue:(id)value forKey:(NSString*)key STUB_METHOD;
- (BOOL)validateValue:(id _Nullable*)value forKey:(NSString*)key error:(NSError* _Nullable*)error STUB_METHOD;
- (BOOL)validateForDelete:(NSError* _Nullable*)error STUB_METHOD;
- (BOOL)validateForInsert:(NSError* _Nullable*)error STUB_METHOD;
- (BOOL)validateForUpdate:(NSError* _Nullable*)error STUB_METHOD;
+ (BOOL)automaticallyNotifiesObserversForKey:(NSString*)key STUB_METHOD;
- (void)didAccessValueForKey:(NSString*)key STUB_METHOD;
- (void)willAccessValueForKey:(NSString*)key STUB_METHOD;
- (void)didChangeValueForKey:(NSString*)key STUB_METHOD;
- (void)didChangeValueForKey:(NSString*)inKey
             withSetMutation:(NSKeyValueSetMutationKind)inMutationKind
                usingObjects:(NSSet*)inObjects STUB_METHOD;
- (void)willChangeValueForKey:(NSString*)key STUB_METHOD;
- (void)willChangeValueForKey:(NSString*)inKey
              withSetMutation:(NSKeyValueSetMutationKind)inMutationKind
                 usingObjects:(NSSet*)inObjects STUB_METHOD;
@end
