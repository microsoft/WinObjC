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

@class NSURL;
@class NSArray;
@class NSDictionary;
@class NSString;
@class NSFetchRequest;
@class NSSet;

COREDATA_EXPORT_CLASS
@interface NSManagedObjectModel : NSObject <NSCoding, NSCopying, NSFastEnumeration>
- (instancetype)initWithContentsOfURL:(NSURL*)url;
+ (NSManagedObjectModel*)mergedModelFromBundles:(NSArray*)bundles STUB_METHOD;
+ (NSManagedObjectModel*)mergedModelFromBundles:(NSArray*)bundles forStoreMetadata:(NSDictionary*)metadata STUB_METHOD;
+ (NSManagedObjectModel*)modelByMergingModels:(NSArray*)models STUB_METHOD;
+ (NSManagedObjectModel*)modelByMergingModels:(NSArray*)models forStoreMetadata:(NSDictionary*)metadata STUB_METHOD;
@property (strong) NSArray* entities;
@property (readonly, copy) NSDictionary* entitiesByName;
@property (readonly, strong) NSArray* configurations STUB_PROPERTY;
- (NSArray*)entitiesForConfiguration:(NSString*)configuration STUB_METHOD;
- (void)setEntities:(NSArray*)entities forConfiguration:(NSString*)configuration;
@property (readonly, copy) NSDictionary* fetchRequestTemplatesByName STUB_PROPERTY;
- (NSFetchRequest*)fetchRequestTemplateForName:(NSString*)name STUB_METHOD;
- (NSFetchRequest*)fetchRequestFromTemplateWithName:(NSString*)name substitutionVariables:(NSDictionary*)variables STUB_METHOD;
- (void)setFetchRequestTemplate:(NSFetchRequest*)fetchRequest forName:(NSString*)name STUB_METHOD;
@property (strong) NSDictionary* localizationDictionary STUB_PROPERTY;
- (BOOL)isConfiguration:(NSString*)configuration compatibleWithStoreMetadata:(NSDictionary*)metadata STUB_METHOD;
@property (readonly, copy) NSDictionary* entityVersionHashesByName STUB_PROPERTY;
@property (copy) NSSet* versionIdentifiers STUB_PROPERTY;
@end
