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
#import <Foundation/NSEnumerator.h>

@class NSManagedObject;
@class NSString;
@class NSManagedObjectModel;
@class NSDictionary;
@class NSArray;
@class NSManagedObjectContext;
@class NSData;

COREDATA_EXPORT_CLASS
@interface NSEntityDescription : NSObject <NSCoding, NSCopying, NSFastEnumeration>
+ (NSEntityDescription*)entityForName:(NSString*)entityName inManagedObjectContext:(NSManagedObjectContext*)context STUB_METHOD;
+ (NSManagedObject*)insertNewObjectForEntityForName:(NSString*)entityName
                             inManagedObjectContext:(NSManagedObjectContext*)context STUB_METHOD;

@property (copy) NSString* name;
@property (readonly, assign) NSManagedObjectModel* managedObjectModel;
@property (copy) NSString* managedObjectClassName;
@property (copy) NSString* renamingIdentifier;
@property (getter=isAbstract) BOOL abstract;
@property (nonatomic, strong) NSDictionary* userInfo;

@property (strong) NSArray* subentities;
@property (readonly, copy) NSDictionary* subentitiesByName;
@property (readonly, assign) NSEntityDescription* superentity;
- (BOOL)isKindOfEntity:(NSEntityDescription*)entity STUB_METHOD;

@property (strong) NSArray* properties;
@property (readonly, copy) NSDictionary* propertiesByName;
@property (readonly, copy) NSDictionary* attributesByName;
@property (readonly, copy) NSDictionary* relationshipsByName;
- (NSArray*)relationshipsWithDestinationEntity:(NSEntityDescription*)entity STUB_METHOD;

@property (strong) NSArray* compoundIndexes;

@property (readonly, copy) NSData* versionHash STUB_PROPERTY;
@property (copy) NSString* versionHashModifier;
- (id)copy STUB_METHOD;
@end
