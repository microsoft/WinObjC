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

@class NSManagedObjectModel;
@class NSURL;
@class NSString;
@class NSDictionary;
@class NSMappingModel;
@class NSError;
@class NSEntityMapping;
@class NSManagedObject;
@class NSArray;
@class NSEntityDescription;
@class NSManagedObjectContext;

COREDATA_EXPORT_CLASS
@interface NSMigrationManager : NSObject
- (instancetype)initWithSourceModel:(NSManagedObjectModel*)sourceModel destinationModel:(NSManagedObjectModel*)destinationModel STUB_METHOD;
- (BOOL)migrateStoreFromURL:(NSURL*)sourceURL
                       type:(NSString*)sStoreType
                    options:(NSDictionary*)sOptions
           withMappingModel:(NSMappingModel*)mappings
           toDestinationURL:(NSURL*)dURL
            destinationType:(NSString*)dStoreType
         destinationOptions:(NSDictionary*)dOptions
                      error:(NSError* _Nullable*)error STUB_METHOD;
- (void)reset STUB_METHOD;
- (void)cancelMigrationWithError:(NSError*)error STUB_METHOD;
@property (readonly) float migrationProgress STUB_PROPERTY;
@property (readonly, strong) NSEntityMapping* currentEntityMapping STUB_PROPERTY;
- (void)associateSourceInstance:(NSManagedObject*)sourceInstance
        withDestinationInstance:(NSManagedObject*)destinationInstance
               forEntityMapping:(NSEntityMapping*)entityMapping STUB_METHOD;
- (NSArray*)destinationInstancesForEntityMappingNamed:(NSString*)mappingName sourceInstances:(NSArray*)sourceInstances STUB_METHOD;
- (NSArray*)sourceInstancesForEntityMappingNamed:(NSString*)mappingName destinationInstances:(NSArray*)destinationInstances STUB_METHOD;
@property (readonly, strong) NSMappingModel* mappingModel STUB_PROPERTY;
@property (readonly, strong) NSManagedObjectModel* sourceModel STUB_PROPERTY;
@property (readonly, strong) NSManagedObjectModel* destinationModel STUB_PROPERTY;
- (NSEntityDescription*)sourceEntityForEntityMapping:(NSEntityMapping*)mEntity STUB_METHOD;
- (NSEntityDescription*)destinationEntityForEntityMapping:(NSEntityMapping*)mEntity STUB_METHOD;
@property (readonly, strong) NSManagedObjectContext* sourceContext STUB_PROPERTY;
@property (readonly, strong) NSManagedObjectContext* destinationContext STUB_PROPERTY;
@property (nonatomic, strong) NSDictionary* userInfo STUB_PROPERTY;
@property BOOL usesStoreSpecificMigrationManager STUB_PROPERTY;
@end
