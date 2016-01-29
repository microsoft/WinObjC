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
@class NSDictionary;
@class NSManagedObjectModel;
@class NSURL;
@class NSError;
@class NSPersistentStore;
@class NSArray;
@class NSPersistentStoreRequest;
@class NSManagedObjectContext;
@class NSManagedObjectID;

typedef NS_ENUM(NSUInteger, NSPersistentStoreUbiquitousTransitionType) {
    NSPersistentStoreUbiquitousTransitionTypeAccountAdded,
    NSPersistentStoreUbiquitousTransitionTypeAccountRemoved,
    NSPersistentStoreUbiquitousTransitionTypeContentRemoved,
    NSPersistentStoreUbiquitousTransitionTypeInitialImportCompleted
};

COREDATA_EXPORT NSString* const NSSQLiteStoreType;
COREDATA_EXPORT NSString* const NSBinaryStoreType;
COREDATA_EXPORT NSString* const NSInMemoryStoreType;
COREDATA_EXPORT NSString* const NSStoreTypeKey;
COREDATA_EXPORT NSString* const NSStoreUUIDKey;
COREDATA_EXPORT NSString* const NSAddedPersistentStoresKey;
COREDATA_EXPORT NSString* const NSRemovedPersistentStoresKey;
COREDATA_EXPORT NSString* const NSUUIDChangedPersistentStoresKey;
COREDATA_EXPORT NSString* const NSPersistentStoreUbiquitousTransitionTypeKey;
COREDATA_EXPORT NSString* const NSReadOnlyPersistentStoreOption;
COREDATA_EXPORT NSString* const NSPersistentStoreTimeoutOption;
COREDATA_EXPORT NSString* const NSSQLitePragmasOption;
COREDATA_EXPORT NSString* const NSSQLiteAnalyzeOption;
COREDATA_EXPORT NSString* const NSSQLiteManualVacuumOption;
COREDATA_EXPORT NSString* const NSPersistentStoreFileProtectionKey;
COREDATA_EXPORT NSString* const NSPersistentStoreUbiquitousContentNameKey;
COREDATA_EXPORT NSString* const NSPersistentStoreUbiquitousContentURLKey;
COREDATA_EXPORT NSString* const NSPersistentStoreUbiquitousPeerTokenOption;
COREDATA_EXPORT NSString* const NSPersistentStoreRemoveUbiquitousMetadataOption;
COREDATA_EXPORT NSString* const NSPersistentStoreUbiquitousContainerIdentifierKey;
COREDATA_EXPORT NSString* const NSPersistentStoreRebuildFromUbiquitousContentOption;
COREDATA_EXPORT NSString* const NSIgnorePersistentStoreVersioningOption;
COREDATA_EXPORT NSString* const NSMigratePersistentStoresAutomaticallyOption;
COREDATA_EXPORT NSString* const NSInferMappingModelAutomaticallyOption;
COREDATA_EXPORT NSString* const NSStoreModelVersionHashesKey;
COREDATA_EXPORT NSString* const NSStoreModelVersionIdentifiersKey;
COREDATA_EXPORT NSString* const NSPersistentStoreOSCompatibility;
COREDATA_EXPORT NSString* const NSPersistentStoreCoordinatorStoresDidChangeNotification;
COREDATA_EXPORT NSString* const NSPersistentStoreCoordinatorStoresWillChangeNotification;
COREDATA_EXPORT NSString* const NSPersistentStoreCoordinatorWillRemoveStoreNotification;
COREDATA_EXPORT NSString* const NSPersistentStoreDidImportUbiquitousContentChangesNotification;

COREDATA_EXPORT_CLASS
@interface NSPersistentStoreCoordinator : NSObject <NSLocking>
+ (NSDictionary*)registeredStoreTypes STUB_METHOD;
+ (void)registerStoreClass:(Class)storeClass forStoreType:(NSString*)storeType STUB_METHOD;
- (instancetype)initWithManagedObjectModel:(NSManagedObjectModel*)model STUB_METHOD;
@property (readonly, strong) NSManagedObjectModel* managedObjectModel STUB_PROPERTY;
- (NSPersistentStore*)addPersistentStoreWithType:(NSString*)storeType
                                   configuration:(NSString*)configuration
                                             URL:(NSURL*)storeURL
                                         options:(NSDictionary*)options
                                           error:(NSError* _Nullable*)error STUB_METHOD;
- (BOOL)setURL:(NSURL*)url forPersistentStore:(NSPersistentStore*)store STUB_METHOD;
- (BOOL)removePersistentStore:(NSPersistentStore*)store error:(NSError* _Nullable*)error STUB_METHOD;
- (NSPersistentStore*)migratePersistentStore:(NSPersistentStore*)store
                                       toURL:(NSURL*)URL
                                     options:(NSDictionary*)options
                                    withType:(NSString*)storeType
                                       error:(NSError* _Nullable*)error STUB_METHOD;
@property (readonly, strong) NSArray* persistentStores STUB_PROPERTY;
- (NSPersistentStore*)persistentStoreForURL:(NSURL*)URL STUB_METHOD;
- (NSURL*)URLForPersistentStore:(NSPersistentStore*)store STUB_METHOD;
+ (BOOL)removeUbiquitousContentAndPersistentStoreAtURL:(NSURL*)storeURL
                                               options:(NSDictionary*)options
                                                 error:(NSError* _Nullable*)error STUB_METHOD;
- (id)executeRequest:(NSPersistentStoreRequest*)request
         withContext:(NSManagedObjectContext*)context
               error:(NSError* _Nullable*)error STUB_METHOD;
- (void)lock STUB_METHOD;
- (BOOL)tryLock STUB_METHOD;
- (void)unlock STUB_METHOD;
- (NSDictionary*)metadataForPersistentStore:(NSPersistentStore*)store STUB_METHOD;
- (void)setMetadata:(NSDictionary*)metadata forPersistentStore:(NSPersistentStore*)store STUB_METHOD;
+ (BOOL)setMetadata:(NSDictionary*)metadata
    forPersistentStoreOfType:(NSString*)storeType
                         URL:(NSURL*)url
                       error:(NSError* _Nullable*)error STUB_METHOD;
+ (NSDictionary*)metadataForPersistentStoreOfType:(NSString*)storeType URL:(NSURL*)url error:(NSError* _Nullable*)error STUB_METHOD;
- (NSManagedObjectID*)managedObjectIDForURIRepresentation:(NSURL*)URL STUB_METHOD;
@end
