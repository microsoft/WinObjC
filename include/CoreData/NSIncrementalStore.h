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

@class NSError;
@class NSPersistentStoreRequest;
@class NSManagedObjectContext;
@class NSIncrementalStoreNode;
@class NSManagedObjectID;
@class NSRelationshipDescription;
@class NSArray;
@class NSURL;
@class NSEntityDescription;

COREDATA_EXPORT_CLASS
@interface NSIncrementalStore : NSPersistentStore
- (BOOL)loadMetadata:(NSError* _Nullable*)error STUB_METHOD;
- (id)executeRequest:(NSPersistentStoreRequest*)request
         withContext:(NSManagedObjectContext*)context
               error:(NSError* _Nullable*)error STUB_METHOD;
- (NSIncrementalStoreNode*)newValuesForObjectWithID:(NSManagedObjectID*)objectID
                                        withContext:(NSManagedObjectContext*)context
                                              error:(NSError* _Nullable*)error STUB_METHOD;
- (id)newValueForRelationship:(NSRelationshipDescription*)relationship
              forObjectWithID:(NSManagedObjectID*)objectID
                  withContext:(NSManagedObjectContext*)context
                        error:(NSError* _Nullable*)error STUB_METHOD;
- (NSArray*)obtainPermanentIDsForObjects:(NSArray*)array error:(NSError* _Nullable*)error STUB_METHOD;
+ (id)identifierForNewStoreAtURL:(NSURL*)storeURL STUB_METHOD;
- (void)managedObjectContextDidRegisterObjectsWithIDs:(NSArray*)objectIDs STUB_METHOD;
- (void)managedObjectContextDidUnregisterObjectsWithIDs:(NSArray*)objectIDs STUB_METHOD;
- (NSManagedObjectID*)newObjectIDForEntity:(NSEntityDescription*)entity referenceObject:(id)data STUB_METHOD;
- (id)referenceObjectForObjectID:(NSManagedObjectID*)objectID STUB_METHOD;
@end
