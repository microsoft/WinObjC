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
#import <Foundation/NSMapTable.h>

@implementation NSMapTable
/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithKeyOptions:(NSPointerFunctionsOptions)keys
                      valueOptions:(NSPointerFunctionsOptions)values
                          capacity:(NSUInteger)capacity {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSMapTable*)mapTableWithKeyOptions:(NSPointerFunctionsOptions)keyOptions valueOptions:(NSPointerFunctionsOptions)valueOptions {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithKeyPointerFunctions:(NSPointerFunctions*)keyFunctions
                      valuePointerFunctions:(NSPointerFunctions*)valueFunctions
                                   capacity:(NSUInteger)initialCapacity {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSMapTable*)strongToStrongObjectsMapTable {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSMapTable*)weakToStrongObjectsMapTable {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSMapTable*)strongToWeakObjectsMapTable {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSMapTable*)weakToWeakObjectsMapTable {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (id)objectForKey:(id)aKey {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSEnumerator*)keyEnumerator {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSEnumerator*)objectEnumerator {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)setObject:(id)anObject forKey:(id)aKey {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeObjectForKey:(id)aKey {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeAllObjects {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (NSDictionary*)dictionaryRepresentation {
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
