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
#import <CoreData/NSManagedObjectModel.h>

@implementation NSManagedObjectModel
/**
@Status Stub
@Notes
*/
- (instancetype)initWithContentsOfURL:(NSURL*)url {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (NSManagedObjectModel*)mergedModelFromBundles:(NSArray*)bundles {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (NSManagedObjectModel*)mergedModelFromBundles:(NSArray*)bundles forStoreMetadata:(NSDictionary*)metadata {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (NSManagedObjectModel*)modelByMergingModels:(NSArray*)models {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (NSManagedObjectModel*)modelByMergingModels:(NSArray*)models forStoreMetadata:(NSDictionary*)metadata {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (NSArray*)entitiesForConfiguration:(NSString*)configuration {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)setEntities:(NSArray*)entities forConfiguration:(NSString*)configuration {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (NSFetchRequest*)fetchRequestTemplateForName:(NSString*)name {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (NSFetchRequest*)fetchRequestFromTemplateWithName:(NSString*)name substitutionVariables:(NSDictionary*)variables {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)setFetchRequestTemplate:(NSFetchRequest*)fetchRequest forName:(NSString*)name {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (BOOL)isConfiguration:(NSString*)configuration compatibleWithStoreMetadata:(NSDictionary*)metadata {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (instancetype)initWithCoder:(NSCoder*)decoder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (id)copyWithZone:(NSZone*)zone {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id _Nonnull[])stackbuf count:(NSUInteger)len {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
