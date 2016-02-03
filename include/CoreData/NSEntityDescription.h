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
@property (copy) NSString* name STUB_PROPERTY;
@property (readonly, assign) NSManagedObjectModel* managedObjectModel STUB_PROPERTY;
@property (copy) NSString* managedObjectClassName STUB_PROPERTY;
@property (copy) NSString* renamingIdentifier STUB_PROPERTY;
@property (getter=isAbstract) BOOL abstract STUB_PROPERTY;
@property (nonatomic, strong) NSDictionary* userInfo STUB_PROPERTY;
@property (readonly, copy) NSDictionary* subentitiesByName STUB_PROPERTY;
@property (strong) NSArray* subentities STUB_PROPERTY;
@property (readonly, assign) NSEntityDescription* superentity STUB_PROPERTY;
- (BOOL)isKindOfEntity:(NSEntityDescription*)entity STUB_METHOD;
@property (readonly, copy) NSDictionary* propertiesByName STUB_PROPERTY;
@property (strong) NSArray* properties STUB_PROPERTY;
@property (readonly, copy) NSDictionary* attributesByName STUB_PROPERTY;
@property (readonly, copy) NSDictionary* relationshipsByName STUB_PROPERTY;
- (NSArray*)relationshipsWithDestinationEntity:(NSEntityDescription*)entity STUB_METHOD;
+ (NSEntityDescription*)entityForName:(NSString*)entityName inManagedObjectContext:(NSManagedObjectContext*)context STUB_METHOD;
+ (NSManagedObject*)insertNewObjectForEntityForName:(NSString*)entityName
                             inManagedObjectContext:(NSManagedObjectContext*)context STUB_METHOD;
@property (readonly, copy) NSData* versionHash STUB_PROPERTY;
@property (copy) NSString* versionHashModifier STUB_PROPERTY;
- (id)copy STUB_METHOD;
@property (strong) NSArray* compoundIndexes STUB_PROPERTY;
@end
