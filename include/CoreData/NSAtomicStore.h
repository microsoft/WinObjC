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
#import <CoreData/NSPersistentStore.h>

@class NSPersistentStoreCoordinator;
@class NSString;
@class NSURL;
@class NSDictionary;
@class NSError;
@class NSManagedObjectID;
@class NSEntityDescription;
@class NSSet;
@class NSAtomicStoreCacheNode;
@class NSManagedObject;

COREDATA_EXPORT_CLASS
@interface NSAtomicStore : NSPersistentStore
- (instancetype)initWithPersistentStoreCoordinator:(NSPersistentStoreCoordinator*)coordinator
                                 configurationName:(NSString*)configurationName
                                               URL:(NSURL*)url
                                           options:(NSDictionary*)options STUB_METHOD;
- (BOOL)load:(NSError* _Nullable*)error STUB_METHOD;
- (NSManagedObjectID*)objectIDForEntity:(NSEntityDescription*)entity referenceObject:(id)data STUB_METHOD;
- (void)addCacheNodes:(NSSet*)cacheNodes STUB_METHOD;
- (NSAtomicStoreCacheNode*)newCacheNodeForManagedObject:(NSManagedObject*)managedObject STUB_METHOD;
- (id)newReferenceObjectForManagedObject:(NSManagedObject*)managedObject STUB_METHOD;
- (void)updateCacheNode:(NSAtomicStoreCacheNode*)node fromManagedObject:(NSManagedObject*)managedObject STUB_METHOD;
- (void)willRemoveCacheNodes:(NSSet*)cacheNodes STUB_METHOD;
- (BOOL)save:(NSError* _Nullable*)error STUB_METHOD;
- (NSSet*)cacheNodes STUB_METHOD;
- (NSAtomicStoreCacheNode*)cacheNodeForObjectID:(NSManagedObjectID*)objectID STUB_METHOD;
- (id)referenceObjectForObjectID:(NSManagedObjectID*)objectID STUB_METHOD;
- (NSDictionary*)metadata STUB_METHOD;
- (void)setMetadata:(NSDictionary*)storeMetadata STUB_METHOD;
@end
