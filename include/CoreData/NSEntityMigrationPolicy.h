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

@class NSString;
@class NSEntityMapping;
@class NSMigrationManager;
@class NSError;
@class NSManagedObject;

COREDATA_EXPORT NSString* const NSMigrationManagerKey;
COREDATA_EXPORT NSString* const NSMigrationSourceObjectKey;
COREDATA_EXPORT NSString* const NSMigrationDestinationObjectKey;
COREDATA_EXPORT NSString* const NSMigrationEntityMappingKey;
COREDATA_EXPORT NSString* const NSMigrationPropertyMappingKey;
COREDATA_EXPORT NSString* const NSMigrationEntityPolicyKey;

COREDATA_EXPORT_CLASS
@interface NSEntityMigrationPolicy : NSObject
- (BOOL)beginEntityMapping:(NSEntityMapping*)mapping manager:(NSMigrationManager*)manager error:(NSError* _Nullable*)error STUB_METHOD;
- (BOOL)createDestinationInstancesForSourceInstance:(NSManagedObject*)sInstance
                                      entityMapping:(NSEntityMapping*)mapping
                                            manager:(NSMigrationManager*)manager
                                              error:(NSError* _Nullable*)error STUB_METHOD;
- (BOOL)endInstanceCreationForEntityMapping:(NSEntityMapping*)mapping
                                    manager:(NSMigrationManager*)manager
                                      error:(NSError* _Nullable*)error STUB_METHOD;
- (BOOL)createRelationshipsForDestinationInstance:(NSManagedObject*)dInstance
                                    entityMapping:(NSEntityMapping*)mapping
                                          manager:(NSMigrationManager*)manager
                                            error:(NSError* _Nullable*)error STUB_METHOD;
- (BOOL)endRelationshipCreationForEntityMapping:(NSEntityMapping*)mapping
                                        manager:(NSMigrationManager*)manager
                                          error:(NSError* _Nullable*)error STUB_METHOD;
- (BOOL)performCustomValidationForEntityMapping:(NSEntityMapping*)mapping
                                        manager:(NSMigrationManager*)manager
                                          error:(NSError* _Nullable*)error STUB_METHOD;
- (BOOL)endEntityMapping:(NSEntityMapping*)mapping manager:(NSMigrationManager*)manager error:(NSError* _Nullable*)error STUB_METHOD;
@end
