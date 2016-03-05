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

#import <StubReturn.h>
#import <CoreData/NSPersistentStoreCoordinator.h>

NSString* const NSSQLiteStoreType = @"NSSQLiteStoreType";
NSString* const NSBinaryStoreType = @"NSBinaryStoreType";
NSString* const NSInMemoryStoreType = @"NSInMemoryStoreType";
NSString* const NSStoreTypeKey = @"NSStoreTypeKey";
NSString* const NSStoreUUIDKey = @"NSStoreUUIDKey";
NSString* const NSAddedPersistentStoresKey = @"NSAddedPersistentStoresKey";
NSString* const NSRemovedPersistentStoresKey = @"NSRemovedPersistentStoresKey";
NSString* const NSUUIDChangedPersistentStoresKey = @"NSUUIDChangedPersistentStoresKey";
NSString* const NSPersistentStoreUbiquitousTransitionTypeKey = @"NSPersistentStoreUbiquitousTransitionTypeKey";
NSString* const NSReadOnlyPersistentStoreOption = @"NSReadOnlyPersistentStoreOption";
NSString* const NSPersistentStoreTimeoutOption = @"NSPersistentStoreTimeoutOption";
NSString* const NSSQLitePragmasOption = @"NSSQLitePragmasOption";
NSString* const NSSQLiteAnalyzeOption = @"NSSQLiteAnalyzeOption";
NSString* const NSSQLiteManualVacuumOption = @"NSSQLiteManualVacuumOption";
NSString* const NSPersistentStoreFileProtectionKey = @"NSPersistentStoreFileProtectionKey";
NSString* const NSPersistentStoreUbiquitousContentNameKey = @"NSPersistentStoreUbiquitousContentNameKey";
NSString* const NSPersistentStoreUbiquitousContentURLKey = @"NSPersistentStoreUbiquitousContentURLKey";
NSString* const NSPersistentStoreUbiquitousPeerTokenOption = @"NSPersistentStoreUbiquitousPeerTokenOption";
NSString* const NSPersistentStoreRemoveUbiquitousMetadataOption = @"NSPersistentStoreRemoveUbiquitousMetadataOption";
NSString* const NSPersistentStoreUbiquitousContainerIdentifierKey = @"NSPersistentStoreUbiquitousContainerIdentifierKey";
NSString* const NSPersistentStoreRebuildFromUbiquitousContentOption = @"NSPersistentStoreRebuildFromUbiquitousContentOption";
NSString* const NSIgnorePersistentStoreVersioningOption = @"NSIgnorePersistentStoreVersioningOption";
NSString* const NSMigratePersistentStoresAutomaticallyOption = @"NSMigratePersistentStoresAutomaticallyOption";
NSString* const NSInferMappingModelAutomaticallyOption = @"NSInferMappingModelAutomaticallyOption";
NSString* const NSStoreModelVersionHashesKey = @"NSStoreModelVersionHashesKey";
NSString* const NSStoreModelVersionIdentifiersKey = @"NSStoreModelVersionIdentifiersKey";
NSString* const NSPersistentStoreOSCompatibility = @"NSPersistentStoreOSCompatibility";
NSString* const NSPersistentStoreCoordinatorStoresDidChangeNotification = @"NSPersistentStoreCoordinatorStoresDidChangeNotification";
NSString* const NSPersistentStoreCoordinatorStoresWillChangeNotification = @"NSPersistentStoreCoordinatorStoresWillChangeNotification";
NSString* const NSPersistentStoreCoordinatorWillRemoveStoreNotification = @"NSPersistentStoreCoordinatorWillRemoveStoreNotification";
NSString* const NSPersistentStoreDidImportUbiquitousContentChangesNotification =
    @"NSPersistentStoreDidImportUbiquitousContentChangesNotification";

@implementation NSPersistentStoreCoordinator
/**
@Status Stub
@Notes
*/
+ (NSDictionary*)registeredStoreTypes {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (void)registerStoreClass:(Class)storeClass forStoreType:(NSString*)storeType {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (instancetype)initWithManagedObjectModel:(NSManagedObjectModel*)model {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (NSPersistentStore*)addPersistentStoreWithType:(NSString*)storeType
                                   configuration:(NSString*)configuration
                                             URL:(NSURL*)storeURL
                                         options:(NSDictionary*)options
                                           error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)setURL:(NSURL*)url forPersistentStore:(NSPersistentStore*)store {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)removePersistentStore:(NSPersistentStore*)store error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (NSPersistentStore*)migratePersistentStore:(NSPersistentStore*)store
                                       toURL:(NSURL*)URL
                                     options:(NSDictionary*)options
                                    withType:(NSString*)storeType
                                       error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (NSPersistentStore*)persistentStoreForURL:(NSURL*)URL {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (NSURL*)URLForPersistentStore:(NSPersistentStore*)store {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (BOOL)removeUbiquitousContentAndPersistentStoreAtURL:(NSURL*)storeURL options:(NSDictionary*)options error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (id)executeRequest:(NSPersistentStoreRequest*)request withContext:(NSManagedObjectContext*)context error:(NSError* _Nullable*)error {
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
- (BOOL)tryLock {
    UNIMPLEMENTED();
    return StubReturn();
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
- (NSDictionary*)metadataForPersistentStore:(NSPersistentStore*)store {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)setMetadata:(NSDictionary*)metadata forPersistentStore:(NSPersistentStore*)store {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
+ (BOOL)setMetadata:(NSDictionary*)metadata forPersistentStoreOfType:(NSString*)storeType URL:(NSURL*)url error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (NSDictionary*)metadataForPersistentStoreOfType:(NSString*)storeType URL:(NSURL*)url error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (NSManagedObjectID*)managedObjectIDForURIRepresentation:(NSURL*)URL {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
