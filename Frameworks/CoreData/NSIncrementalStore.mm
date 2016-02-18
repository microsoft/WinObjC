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
#import <CoreData/NSIncrementalStore.h>

@implementation NSIncrementalStore
/**
@Status Stub
@Notes
*/
- (BOOL)loadMetadata:(NSError* _Nullable*)error {
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
- (NSIncrementalStoreNode*)newValuesForObjectWithID:(NSManagedObjectID*)objectID
                                        withContext:(NSManagedObjectContext*)context
                                              error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (id)newValueForRelationship:(NSRelationshipDescription*)relationship
              forObjectWithID:(NSManagedObjectID*)objectID
                  withContext:(NSManagedObjectContext*)context
                        error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (NSArray*)obtainPermanentIDsForObjects:(NSArray*)array error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (id)identifierForNewStoreAtURL:(NSURL*)storeURL {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)managedObjectContextDidRegisterObjectsWithIDs:(NSArray*)objectIDs {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)managedObjectContextDidUnregisterObjectsWithIDs:(NSArray*)objectIDs {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (NSManagedObjectID*)newObjectIDForEntity:(NSEntityDescription*)entity referenceObject:(id)data {
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

@end
