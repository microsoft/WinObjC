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
#import <CoreData/NSAtomicStore.h>

@implementation NSAtomicStore
/**
@Status Stub
@Notes
*/
- (instancetype)initWithPersistentStoreCoordinator:(NSPersistentStoreCoordinator*)coordinator
                                 configurationName:(NSString*)configurationName
                                               URL:(NSURL*)url
                                           options:(NSDictionary*)options {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)load:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (NSManagedObjectID*)objectIDForEntity:(NSEntityDescription*)entity referenceObject:(id)data {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)addCacheNodes:(NSSet*)cacheNodes {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (NSAtomicStoreCacheNode*)newCacheNodeForManagedObject:(NSManagedObject*)managedObject {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (id)newReferenceObjectForManagedObject:(NSManagedObject*)managedObject {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)updateCacheNode:(NSAtomicStoreCacheNode*)node fromManagedObject:(NSManagedObject*)managedObject {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)willRemoveCacheNodes:(NSSet*)cacheNodes {
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
- (NSSet*)cacheNodes {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (NSAtomicStoreCacheNode*)cacheNodeForObjectID:(NSManagedObjectID*)objectID {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (id)referenceObjectForObjectID:(NSManagedObjectID*)objectID {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (NSDictionary*)metadata {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)setMetadata:(NSDictionary*)storeMetadata {
    UNIMPLEMENTED();
}

@end
