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

#import <Foundation/NSCoder.h>

#import "NSRaise.h"
#import "Starboard.h"
#import "StubReturn.h"

@implementation NSCoder
- (NSBundle*)_bundle {
    return nil;
}

/**
@Status Interoperable
*/
- (BOOL)requiresSecureCoding {
    return NSInvalidAbstractInvocationReturn();
}

/**
@Status Interoperable
*/
- (NSSet*)allowedClasses {
    return NSInvalidAbstractInvocationReturn();
}

/**
@Status Interoperable
*/
- (unsigned)systemVersion {
    return NSInvalidAbstractInvocationReturn();
}

/**
@Status Interoperable
*/
- (void)setObjectZone:(NSZone*)zone {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (NSZone*)objectZone {
    return NSInvalidAbstractInvocationReturn();
}

/**
@Status Interoperable
*/
- (BOOL)allowsKeyedCoding {
    return NSInvalidAbstractInvocationReturn();
}

/**
@Status Interoperable
*/
- (void)encodeValueOfObjCType:(const char*)type at:(const void*)pointer {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (void)encodeDataObject:(NSData*)data {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (void)encodeObject:(id)object {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (void)encodePropertyList:(id)propertyList {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (void)encodeRootObject:(id)rootObject {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (void)encodeBycopyObject:(id)object {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (void)encodeByrefObject:(id)object {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (void)encodeConditionalObject:(id)object {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (void)encodeValuesOfObjCTypes:(const char*)types, ... {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (void)encodeArrayOfObjCType:(const char*)type count:(NSUInteger)count at:(const void*)pointer {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (void)encodeBytes:(const void*)ptr length:(NSUInteger)length {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (void)encodeBool:(BOOL)value forKey:(NSString*)key {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (void)encodeConditionalObject:(id)object forKey:(NSString*)key {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (void)encodeDouble:(double)value forKey:(NSString*)key {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (void)encodeFloat:(float)value forKey:(NSString*)key {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (void)encodeInt:(int)value forKey:(NSString*)key {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (void)encodeObject:(id)object forKey:(NSString*)key {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (void)encodeInt32:(int32_t)value forKey:(NSString*)key {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (void)encodeInt64:(int64_t)value forKey:(NSString*)key {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (void)encodeInteger:(NSInteger)value forKey:(NSString*)key {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (void)encodeBytes:(const uint8_t*)bytes length:(NSUInteger)length forKey:(NSString*)key {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (void)decodeValueOfObjCType:(const char*)type at:(void*)pointer {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (NSData*)decodeDataObject {
    return NSInvalidAbstractInvocationReturn();
}

/**
@Status Interoperable
*/
- (NSInteger)versionForClassName:(NSString*)className {
    return NSInvalidAbstractInvocationReturn();
}

/**
@Status Interoperable
*/
- (id)decodeObject {
    return NSInvalidAbstractInvocationReturn();
}

/**
@Status Interoperable
*/
- (id)decodePropertyList {
    return NSInvalidAbstractInvocationReturn();
}

/**
@Status Interoperable
*/
- (void)decodeValuesOfObjCTypes:(const char*)types, ... {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (void)decodeArrayOfObjCType:(const char*)type count:(NSUInteger)count at:(void*)pointer {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (void*)decodeBytesWithReturnedLength:(NSUInteger*)lengthp {
    return NSInvalidAbstractInvocationReturn();
}

/**
@Status Interoperable
*/
- (BOOL)containsValueForKey:(NSString*)key {
    return NSInvalidAbstractInvocationReturn();
}

/**
@Status Interoperable
*/
- (const uint8_t*)decodeBytesForKey:(NSString*)key returnedLength:(NSUInteger*)length {
    return NSInvalidAbstractInvocationReturn();
}

/**
@Status Interoperable
*/
- (BOOL)decodeBoolForKey:(NSString*)key {
    return NSInvalidAbstractInvocationReturn();
}

/**
@Status Interoperable
*/
- (double)decodeDoubleForKey:(NSString*)key {
    return NSInvalidAbstractInvocationReturn();
}

/**
@Status Interoperable
*/
- (float)decodeFloatForKey:(NSString*)key {
    return NSInvalidAbstractInvocationReturn();
}

/**
@Status Interoperable
*/
- (int)decodeIntForKey:(NSString*)key {
    return NSInvalidAbstractInvocationReturn();
}

/**
@Status Interoperable
*/
- (id)decodeObjectForKey:(NSString*)key {
    return NSInvalidAbstractInvocationReturn();
}

/**
@Status Interoperable
*/
- (id)decodeObjectOfClass:(Class)expectedClass forKey:(NSString*)key {
    return NSInvalidAbstractInvocationReturn();
}

/**
@Status Interoperable
*/
- (id)decodeObjectOfClasses:(NSSet*)expectedClasses forKey:(NSString*)key {
    return NSInvalidAbstractInvocationReturn();
}

/**
@Status Interoperable
*/
- (int32_t)decodeInt32ForKey:(NSString*)key {
    return NSInvalidAbstractInvocationReturn();
}

/**
@Status Interoperable
*/
- (int64_t)decodeInt64ForKey:(NSString*)key {
    return NSInvalidAbstractInvocationReturn();
}

/**
@Status Interoperable
*/
- (NSInteger)decodeIntegerForKey:(NSString*)key {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Stub
 @Notes
*/
- (id)decodePropertyListForKey:(NSString*)key {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
