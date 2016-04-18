//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#import "Starboard.h"
#import "StubReturn.h"
#import "UIKit/UIManagedDocument.h"

@implementation UIManagedDocument

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithFileURL:(NSURL*)url {
    UNIMPLEMENTED();
    return StubReturn();
}

/*
 @Status Stub
 @Notes
*/
+ (NSManagedObjectModel*)modelByMergingModels:(NSArray*)models {
    UNIMPLEMENTED();
    return StubReturn();
}

/*
 @Status Stub
 @Notes
*/
+ (NSManagedObjectModel*)mergedModelFromBundles:(NSArray*)bundles {
    UNIMPLEMENTED();
    return StubReturn();
}

/*
 @Status Stub
 @Notes
*/
- (instancetype)initWithContentsOfURL:(NSURL*)url {
    UNIMPLEMENTED();
    return StubReturn();
}

/*
 @Status Stub
 @Notes
*/
- (NSArray*)entities {
    UNIMPLEMENTED();
    return StubReturn();
}

/*
 @Status Stub
 @Notes
*/
- (NSDictionary*)entitiesByName {
    UNIMPLEMENTED();
    return StubReturn();
}

/*
 @Status Stub
 @Notes
*/
- (NSDictionary*)localizationDictionary {
    UNIMPLEMENTED();
    return StubReturn();
}

/*
 @Status Stub
 @Notes
*/
- (void)setEntities:(NSArray*)entities {
    UNIMPLEMENTED();
}

/*
 @Status Stub
 @Notes
*/
- (void)setLocalizationDictionary:(NSDictionary*)dictionary {
    UNIMPLEMENTED();
}

/*
 @Status Stub
 @Notes
*/
- (NSArray*)configurations {
    UNIMPLEMENTED();
    return StubReturn();
}

/*
 @Status Stub
 @Notes
*/
- (NSArray*)entitiesForConfiguration:(NSString*)configuration {
    UNIMPLEMENTED();
    return StubReturn();
}

/*
 @Status Stub
 @Notes
*/
- (void)setEntities:(NSArray*)entities forConfiguration:(NSString*)configuration {
    UNIMPLEMENTED();
}

/*
 @Status Stub
 @Notes
*/
- (NSFetchRequest*)fetchRequestTemplateForName:(NSString*)name {
    UNIMPLEMENTED();
    return StubReturn();
}

/*
 @Status Stub
 @Notes
*/
- (NSFetchRequest*)fetchRequestFromTemplateWithName:(NSString*)name substitutionVariables:(NSDictionary*)variables {
    UNIMPLEMENTED();
    return StubReturn();
}

/*
 @Status Stub
 @Notes
*/
- (void)setFetchRequestTemplate:(NSFetchRequest*)fetchRequest forName:(NSString*)name {
    UNIMPLEMENTED();
}

/*
 @Status Stub
 @Notes
*/
- (BOOL)isConfiguration:(NSString*)configuration compatibleWithStoreMetadata:(NSDictionary*)metadata {
    UNIMPLEMENTED();
    return StubReturn();
}
@end