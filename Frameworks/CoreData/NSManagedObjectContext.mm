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

#import <CoreData/NSManagedObjectContext.h>
#import <StubReturn.h>

NSString* const NSInsertedObjectsKey = @"NSInsertedObjectsKey";
NSString* const NSUpdatedObjectsKey = @"NSUpdatedObjectsKey";
NSString* const NSDeletedObjectsKey = @"NSDeletedObjectsKey";
NSString* const NSRefreshedObjectsKey = @"NSRefreshedObjectsKey";
NSString* const NSInvalidatedObjectsKey = @"NSInvalidatedObjectsKey";
NSString* const NSInvalidatedAllObjectsKey = @"NSInvalidatedAllObjectsKey";
NSString* const NSManagedObjectContextObjectsDidChangeNotification = @"NSManagedObjectContextObjectsDidChangeNotification";
NSString* const NSManagedObjectContextDidSaveNotification = @"NSManagedObjectContextDidSaveNotification";
NSString* const NSManagedObjectContextWillSaveNotification = @"NSManagedObjectContextWillSaveNotification";

@implementation NSManagedObjectContext
/**
@Status Stub
@Notes
*/
- (NSArray*)executeFetchRequest:(NSFetchRequest*)request error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (NSUInteger)countForFetchRequest:(NSFetchRequest*)request error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (NSManagedObject*)objectRegisteredForID:(NSManagedObjectID*)objectID {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (NSManagedObject*)objectWithID:(NSManagedObjectID*)objectID {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (NSManagedObject*)existingObjectWithID:(NSManagedObjectID*)objectID error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)insertObject:(NSManagedObject*)object {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)deleteObject:(NSManagedObject*)object {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)assignObject:(id)object toPersistentStore:(NSPersistentStore*)store {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (BOOL)obtainPermanentIDsForObjects:(NSArray*)objects error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)detectConflictsForObject:(NSManagedObject*)object {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)refreshObject:(NSManagedObject*)object mergeChanges:(BOOL)flag {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)processPendingChanges {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (instancetype)initWithConcurrencyType:(NSManagedObjectContextConcurrencyType)type {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)mergeChangesFromContextDidSaveNotification:(NSNotification*)notification {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)undo {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)redo {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)reset {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)rollback {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (BOOL)save:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)lock {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)unlock {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (BOOL)tryLock {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)performBlock:(void (^)(void))block {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)performBlockAndWait:(void (^)(void))block {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (instancetype)initWithCoder:(NSCoder*)decoder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    UNIMPLEMENTED();
}

@end
