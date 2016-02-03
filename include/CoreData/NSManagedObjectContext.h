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
#import <Foundation/NSLock.h>

@class NSString;
@class NSArray;
@class NSFetchRequest;
@class NSError;
@class NSManagedObjectID;
@class NSSet;
@class NSManagedObject;
@class NSPersistentStore;
@class NSNotification;
@class NSUndoManager;
@class NSPersistentStoreCoordinator;
@class NSMutableDictionary;

typedef NS_ENUM(NSUInteger, NSManagedObjectContextConcurrencyType) {
    NSConfinementConcurrencyType = 0x00,
    NSPrivateQueueConcurrencyType = 0x01,
    NSMainQueueConcurrencyType = 0x02
};
COREDATA_EXPORT NSString* const NSInsertedObjectsKey;
COREDATA_EXPORT NSString* const NSUpdatedObjectsKey;
COREDATA_EXPORT NSString* const NSDeletedObjectsKey;
COREDATA_EXPORT NSString* const NSRefreshedObjectsKey;
COREDATA_EXPORT NSString* const NSInvalidatedObjectsKey;
COREDATA_EXPORT NSString* const NSInvalidatedAllObjectsKey;
COREDATA_EXPORT NSString* const NSManagedObjectContextObjectsDidChangeNotification;
COREDATA_EXPORT NSString* const NSManagedObjectContextDidSaveNotification;
COREDATA_EXPORT NSString* const NSManagedObjectContextWillSaveNotification;

COREDATA_EXPORT_CLASS
@interface NSManagedObjectContext : NSObject <NSCoding, NSLocking>
- (NSArray*)executeFetchRequest:(NSFetchRequest*)request error:(NSError* _Nullable*)error STUB_METHOD;
- (NSUInteger)countForFetchRequest:(NSFetchRequest*)request error:(NSError* _Nullable*)error STUB_METHOD;
- (NSManagedObject*)objectRegisteredForID:(NSManagedObjectID*)objectID STUB_METHOD;
- (NSManagedObject*)objectWithID:(NSManagedObjectID*)objectID STUB_METHOD;
- (NSManagedObject*)existingObjectWithID:(NSManagedObjectID*)objectID error:(NSError* _Nullable*)error STUB_METHOD;
@property (readonly, nonatomic, strong) NSSet* registeredObjects STUB_PROPERTY;
- (void)insertObject:(NSManagedObject*)object STUB_METHOD;
- (void)deleteObject:(NSManagedObject*)object STUB_METHOD;
- (void)assignObject:(id)object toPersistentStore:(NSPersistentStore*)store STUB_METHOD;
- (BOOL)obtainPermanentIDsForObjects:(NSArray*)objects error:(NSError* _Nullable*)error STUB_METHOD;
- (void)detectConflictsForObject:(NSManagedObject*)object STUB_METHOD;
- (void)refreshObject:(NSManagedObject*)object mergeChanges:(BOOL)flag STUB_METHOD;
- (void)processPendingChanges STUB_METHOD;
@property (readonly, nonatomic, strong) NSSet* insertedObjects STUB_PROPERTY;
@property (readonly, nonatomic, strong) NSSet* updatedObjects STUB_PROPERTY;
@property (readonly, nonatomic, strong) NSSet* deletedObjects STUB_PROPERTY;
- (instancetype)initWithConcurrencyType:(NSManagedObjectContextConcurrencyType)type STUB_METHOD;
@property (readonly) NSManagedObjectContextConcurrencyType concurrencyType STUB_PROPERTY;
- (void)mergeChangesFromContextDidSaveNotification:(NSNotification*)notification STUB_METHOD;
@property (nonatomic, strong) NSUndoManager* undoManager STUB_PROPERTY;
- (void)undo STUB_METHOD;
- (void)redo STUB_METHOD;
- (void)reset STUB_METHOD;
- (void)rollback STUB_METHOD;
- (BOOL)save:(NSError* _Nullable*)error STUB_METHOD;
@property (readonly, nonatomic) BOOL hasChanges STUB_PROPERTY;
@property (strong) NSPersistentStoreCoordinator* persistentStoreCoordinator STUB_PROPERTY;
@property (strong) NSManagedObjectContext* parentContext STUB_PROPERTY;
- (void)lock STUB_METHOD;
- (void)unlock STUB_METHOD;
- (BOOL)tryLock STUB_METHOD;
@property (nonatomic) BOOL propagatesDeletesAtEndOfEvent STUB_PROPERTY;
@property (nonatomic) BOOL retainsRegisteredObjects STUB_PROPERTY;
@property NSTimeInterval stalenessInterval STUB_PROPERTY;
@property (strong) id mergePolicy STUB_PROPERTY;
- (void)performBlock:(void (^)(void))block STUB_METHOD;
- (void)performBlockAndWait:(void (^)(void))block STUB_METHOD;
@property (readonly, nonatomic, strong) NSMutableDictionary* userInfo STUB_PROPERTY;
@end
