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

#import <ErrorHandling.h>
#import <StubReturn.h>

#import <CoreData/CoreData.h>
#import <Foundation/Foundation.h>

#import <CoreData/NSManagedObjectModel-XMLParsing.h>

@interface NSManagedObjectModel () {
    StrongId<NSMutableArray> _unresolvedEntities;
}
@property (atomic, copy) NSDictionary<NSString*, NSEntityDescription*>* entitiesByName;
@end

@implementation NSManagedObjectModel
/**
 @Status Caveat
 @Notes Parses all relationships, entities, attributes and ignopres configurations and fetch requests.
*/
- (id)initWithContentsOfURL:(NSURL*)url {
    [self release];
    if (!url) {
        return nil;
    }

    return [_NSManagedObjectModelFromXMLDataAtURL(url) retain];
}

- (instancetype)_initWithXMLElementName:(NSString*)entityName attributes:(NSDictionary<NSString*, NSString*>*)attributes {
    if (self = [super init]) {
        _unresolvedEntities.attach([NSMutableArray new]);
    }
    return self;
}

- (void)dealloc {
    [_entities release];
    [_configurations release];
    [_localizationDictionary release];
    [_versionIdentifiers release];

    // derived properties
    [_entitiesByName release];
    [_fetchRequestTemplatesByName release];
    [_entityVersionHashesByName release];

    [super dealloc];
}

- (bool)_insertChildElement:(id<_NSCDXMLCoding>)childElement {
    if ([childElement isKindOfClass:[NSEntityDescription class]]) {
        [_unresolvedEntities addObject:childElement];
        return YES;
    }
    return NO;
}

/**
 @Status Caveat
 @Notes Does not support configurations.
*/
- (void)setEntities:(NSArray*)entities forConfiguration:(NSString*)configuration {
    @synchronized(self) {
        if (entities == _entities) {
            return;
        }
        [_entities autorelease];
        _entities = [entities copy];

        NSMutableDictionary<NSString*, NSEntityDescription*>* entitiesByName = [NSMutableDictionary dictionary];

        // Pass 1: add all named entities.
        for (NSEntityDescription* entity in _entities) {
            [entity setManagedObjectModel:self];
            [entitiesByName setObject:entity forKey:entity.name];
        }
        self.entitiesByName = entitiesByName;
    }
}

- (void)_awakeFromXML {
    [self setEntities:_unresolvedEntities forConfiguration:nil];
    for (NSEntityDescription* entity in (id)_unresolvedEntities) {
        [entity _awakeFromXML];
    }

    for (NSEntityDescription* entity in (id)_unresolvedEntities) {
        // This has to happen in a second pass, since inverse relationships can only be established
        // after every entity is registered on the context, and every entity's relationships have
        // otherwise been created.
        [entity _resolveRelationships];
    }
    _unresolvedEntities = nil;
}

/**
 @Status Interoperable
*/
- (NSString*)description {
    return [NSString stringWithFormat:@"<%@ %p: %@>", object_getClass(self), self, _entitiesByName];
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
