//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#import <CoreData/NSPersistentStore.h>

@class NSMutableSet, NSSet, NSAtomicStoreCacheNode, NSManagedObjectID, NSManagedObject, NSEntityDescription, NSMutableDictionary,
    NSDictionary;

@interface NSAtomicStore : NSPersistentStore {
    NSDictionary* _metadata;
    NSMutableSet* _cacheNodes;
    NSMutableDictionary* _objectIDToCacheNode;
    NSMutableDictionary* _objectIDTable;
}

- initWithPersistentStoreCoordinator:(NSPersistentStoreCoordinator*)coordinator
                   configurationName:(NSString*)configurationName
                                 URL:(NSURL*)url
                             options:(NSDictionary*)options;

- (NSSet*)cacheNodes;

- (NSDictionary*)metadata;
- (void)setMetadata:(NSDictionary*)value;

- (void)addCacheNodes:(NSSet*)value;

- (NSAtomicStoreCacheNode*)cacheNodeForObjectID:(NSManagedObjectID*)objectID;
- (NSAtomicStoreCacheNode*)newCacheNodeForManagedObject:(NSManagedObject*)managedObject;

- newReferenceObjectForManagedObject:(NSManagedObject*)managedObject;

- (NSManagedObjectID*)objectIDForEntity:(NSEntityDescription*)entity referenceObject:data;

- referenceObjectForObjectID:(NSManagedObjectID*)objectID;

- (void)updateCacheNode:(NSAtomicStoreCacheNode*)node fromManagedObject:(NSManagedObject*)managedObject;

- (void)willRemoveCacheNodes:(NSSet*)cacheNodes;

- (BOOL)load:(NSError**)error;
- (BOOL)save:(NSError**)error;

@end
