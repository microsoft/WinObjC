/* Copyright(c)2008 Dan Knapp

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files(the
"Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the
following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifndef _NSMANAGEDOBJECTCONTEXT_H_
#define _NSMANAGEDOBJECTCONTEXT_H_

#import <Foundation/NSObject.h>
#import <Foundation/NSString.h>
#import <Foundation/NSDate.h>
#import <Foundation/NSLock.h>
#import <StarboardExport.h>

enum {
    NSConfinementConcurrencyType = 0,
    NSPrivateQueueConcurrencyType = 1,
    NSMainQueueConcurrencyType = 2,
};
typedef uint32_t NSManagedObjectContextConcurrencyType;

@class NSSet, NSMutableSet, NSNotification, NSUndoManager, NSMapTable;
@class NSManagedObject, NSManagedObjectID, NSFetchRequest, NSPersistentStore, NSPersistentStoreCoordinator;

FOUNDATION_EXPORT NSString* const NSManagedObjectContextWillSaveNotification;
FOUNDATION_EXPORT NSString* const NSManagedObjectContextDidSaveNotification;
FOUNDATION_EXPORT NSString* const NSManagedObjectContextObjectsDidChangeNotification;

FOUNDATION_EXPORT NSString* const NSInsertedObjectsKey;
FOUNDATION_EXPORT NSString* const NSUpdatedObjectsKey;
FOUNDATION_EXPORT NSString* const NSDeletedObjectsKey;
FOUNDATION_EXPORT NSString* const NSRefreshedObjectsKey;
FOUNDATION_EXPORT NSString* const NSInvalidatedObjectsKey;
FOUNDATION_EXPORT NSString* const NSInvalidatedAllObjectsKey;

SB_EXPORT id NSErrorMergePolicy;
SB_EXPORT id NSOverwriteMergePolicy;
SB_EXPORT id NSRollbackMergePolicy;
SB_EXPORT id NSMergeByPropertyStoreTrumpMergePolicy;
SB_EXPORT id NSMergeByPropertyObjectTrumpMergePolicy;

FOUNDATION_EXPORT_CLASS
@interface NSManagedObjectContext : NSObject <NSLocking>

- (NSPersistentStoreCoordinator*)persistentStoreCoordinator;
- (NSUndoManager*)undoManager;
- (BOOL)retainsRegisteredObjects;
- (BOOL)propagatesDeletesAtEndOfEvent;
- (NSTimeInterval)stalenessInterval;
- (id)mergePolicy;

- (void)setPersistentStoreCoordinator:(NSPersistentStoreCoordinator*)value;
- (void)setUndoManager:(NSUndoManager*)value;
- (void)setRetainsRegisteredObjects:(BOOL)value;
- (void)setPropagatesDeletesAtEndOfEvent:(BOOL)value;
- (void)setStalenessInterval:(NSTimeInterval)value;
- (void)setMergePolicy:(id)value;

- (NSSet*)registeredObjects;
- (NSSet*)insertedObjects;
- (NSSet*)updatedObjects;
- (NSSet*)deletedObjects;

- (BOOL)hasChanges;

- (void)lock;
- (void)unlock;
- (BOOL)tryLock;

- (void)undo;
- (void)redo;
- (void)reset;
- (void)rollback;

- (NSManagedObject*)objectRegisteredForID:(NSManagedObjectID*)objectID;

- (NSManagedObject*)objectWithID:(NSManagedObjectID*)objectID;

- (NSArray*)executeFetchRequest:(NSFetchRequest*)request error:(NSError**)error;
- (NSUInteger)countForFetchRequest:(NSFetchRequest*)request error:(NSError**)error;

- (void)insertObject:(NSManagedObject*)object;
- (void)deleteObject:(NSManagedObject*)object;

- (void)assignObject:object toPersistentStore:(NSPersistentStore*)store;

- (void)detectConflictsForObject:(NSManagedObject*)object;

- (void)refreshObject:(NSManagedObject*)object mergeChanges:(BOOL)flag;

- (void)processPendingChanges;

- (BOOL)obtainPermanentIDsForObjects:(NSArray*)objects error:(NSError**)error;
- (BOOL)save:(NSError**)error;
- (void)mergeChangesFromContextDidSaveNotification:(NSNotification*)notification;

- (BOOL)commitEditing;
- (void)commitEditingWithDelegate:(id)delegate didCommitSelector:(SEL)didCommitSelector contextInfo:(void*)contextInfo;
- (void)discardEditing;
- (void)objectDidBeginEditing:(id)editor;
- (void)objectDidEndEditing:(id)editor;

- (void)performBlock:(void (^)())block;
- (void)performBlockAndWait:(void (^)())block;

- (NSManagedObject*)existingObjectWithID:(NSManagedObjectID*)objectID error:(NSError**)error;

- (NSManagedObjectContext*)parentContext;
- (void)setParentContext:(NSManagedObjectContext*)parent;

- (NSManagedObjectContextConcurrencyType)concurrencyType;
- (id)initWithConcurrencyType:(NSManagedObjectContextConcurrencyType)ct;

@end

#endif /* _NSMANAGEDOBJECTCONTEXT_H_ */