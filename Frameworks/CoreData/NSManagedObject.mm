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
#import <CoreData/NSManagedObject.h>

@implementation NSManagedObject
/**
@Status Stub
@Notes
*/
- (NSManagedObject*)initWithEntity:(NSEntityDescription*)entity insertIntoManagedObjectContext:(NSManagedObjectContext*)context {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)hasFaultForRelationshipNamed:(NSString*)key {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (BOOL)contextShouldIgnoreUnmodeledPropertyChanges {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)awakeFromFetch {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)awakeFromInsert {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)awakeFromSnapshotEvents:(NSSnapshotEventType)flags {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (NSDictionary*)changedValues {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (NSDictionary*)changedValuesForCurrentEvent {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (NSDictionary*)committedValuesForKeys:(NSArray*)keys {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)prepareForDeletion {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)willSave {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)didSave {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)willTurnIntoFault {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)didTurnIntoFault {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (id)valueForKey:(NSString*)key {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)setValue:(id)value forKey:(NSString*)key {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (NSMutableSet*)mutableSetValueForKey:(NSString*)key {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (id)primitiveValueForKey:(NSString*)key {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)setPrimitiveValue:(id)value forKey:(NSString*)key {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (BOOL)validateValue:(id _Nullable*)value forKey:(NSString*)key error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)validateForDelete:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)validateForInsert:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)validateForUpdate:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (BOOL)automaticallyNotifiesObserversForKey:(NSString*)key {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)didAccessValueForKey:(NSString*)key {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)willAccessValueForKey:(NSString*)key {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)didChangeValueForKey:(NSString*)key {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)didChangeValueForKey:(NSString*)inKey withSetMutation:(NSKeyValueSetMutationKind)inMutationKind usingObjects:(NSSet*)inObjects {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)willChangeValueForKey:(NSString*)key {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)willChangeValueForKey:(NSString*)inKey withSetMutation:(NSKeyValueSetMutationKind)inMutationKind usingObjects:(NSSet*)inObjects {
    UNIMPLEMENTED();
}

@end
