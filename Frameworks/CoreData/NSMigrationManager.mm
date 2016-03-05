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
#import <CoreData/NSMigrationManager.h>

@implementation NSMigrationManager
/**
@Status Stub
@Notes
*/
- (instancetype)initWithSourceModel:(NSManagedObjectModel*)sourceModel destinationModel:(NSManagedObjectModel*)destinationModel {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)migrateStoreFromURL:(NSURL*)sourceURL
                       type:(NSString*)sStoreType
                    options:(NSDictionary*)sOptions
           withMappingModel:(NSMappingModel*)mappings
           toDestinationURL:(NSURL*)dURL
            destinationType:(NSString*)dStoreType
         destinationOptions:(NSDictionary*)dOptions
                      error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)reset {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)cancelMigrationWithError:(NSError*)error {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)associateSourceInstance:(NSManagedObject*)sourceInstance
        withDestinationInstance:(NSManagedObject*)destinationInstance
               forEntityMapping:(NSEntityMapping*)entityMapping {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (NSArray*)destinationInstancesForEntityMappingNamed:(NSString*)mappingName sourceInstances:(NSArray*)sourceInstances {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (NSArray*)sourceInstancesForEntityMappingNamed:(NSString*)mappingName destinationInstances:(NSArray*)destinationInstances {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (NSEntityDescription*)sourceEntityForEntityMapping:(NSEntityMapping*)mEntity {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (NSEntityDescription*)destinationEntityForEntityMapping:(NSEntityMapping*)mEntity {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
