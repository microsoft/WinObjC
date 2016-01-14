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

#include "Starboard.h"
#include "Foundation/NSCoder.h"

static void _raiseInvalidAbstractException(SEL _cmd) {
  [NSException
       raise:NSDestinationInvalidException
      format:@"-[NSCoder %s]: invalid method invoked on abstract class.",
             sel_getName(_cmd)];
}

@implementation NSCoder
- (NSBundle*)_bundle {
  return nil;
}

/**
@Status Interoperable
*/
- (BOOL)requiresSecureCoding {
  _raiseInvalidAbstractException(_cmd);
  return NO;
}

/**
@Status Interoperable
*/
- (NSSet*)allowedClasses {
  _raiseInvalidAbstractException(_cmd);
  return nil;
}

/**
@Status Interoperable
*/
- (unsigned)systemVersion {
  _raiseInvalidAbstractException(_cmd);
  return 0;
}

/**
@Status Interoperable
*/
- (void)setObjectZone:(NSZone*)zone {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (NSZone*)objectZone {
  _raiseInvalidAbstractException(_cmd);
  return nil;
}

/**
@Status Interoperable
*/
- (BOOL)allowsKeyedCoding {
  _raiseInvalidAbstractException(_cmd);
  return NO;
}

/**
@Status Interoperable
*/
- (void)encodeValueOfObjCType:(const char*)type at:(const void*)pointer {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (void)encodeDataObject:(NSData*)data {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (void)encodeObject:(id)object {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (void)encodePropertyList:(id)propertyList {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (void)encodeRootObject:(id)rootObject {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (void)encodeBycopyObject:(id)object {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (void)encodeByrefObject:(id)object {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (void)encodeConditionalObject:(id)object {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (void)encodeValuesOfObjCTypes:(const char*)types, ... {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (void)encodeArrayOfObjCType:(const char*)type
                        count:(NSUInteger)count
                           at:(const void*)pointer {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (void)encodeBytes:(const void*)ptr length:(NSUInteger)length {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (void)encodePoint:(NSPoint)point {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (void)encodeSize:(NSSize)size {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (void)encodeRect:(NSRect)rect {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (void)encodePoint:(NSPoint)value forKey:(NSString*)key {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (void)encodeRect:(NSRect)value forKey:(NSString*)key {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (void)encodeSize:(NSSize)value forKey:(NSString*)key {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (void)encodeBool:(BOOL)value forKey:(NSString*)key {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (void)encodeConditionalObject:(id)object forKey:(NSString*)key {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (void)encodeDouble:(double)value forKey:(NSString*)key {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (void)encodeFloat:(float)value forKey:(NSString*)key {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (void)encodeInt:(int)value forKey:(NSString*)key {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (void)encodeObject:(id)object forKey:(NSString*)key {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (void)encodeInt32:(int32_t)value forKey:(NSString*)key {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (void)encodeInt64:(int64_t)value forKey:(NSString*)key {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (void)encodeInteger:(NSInteger)value forKey:(NSString*)key {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (void)encodeBytes:(const uint8_t*)bytes
             length:(NSUInteger)length
             forKey:(NSString*)key {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (void)decodeValueOfObjCType:(const char*)type at:(void*)pointer {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (NSData*)decodeDataObject {
  _raiseInvalidAbstractException(_cmd);
  return nil;
}

/**
@Status Interoperable
*/
- (NSInteger)versionForClassName:(NSString*)className {
  _raiseInvalidAbstractException(_cmd);
  return 0;
}

/**
@Status Interoperable
*/
- (id)decodeObject {
  _raiseInvalidAbstractException(_cmd);
  return nil;
}

/**
@Status Interoperable
*/
- (id)decodePropertyList {
  _raiseInvalidAbstractException(_cmd);
  return nil;
}

/**
@Status Interoperable
*/
- (void)decodeValuesOfObjCTypes:(const char*)types, ... {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (void)decodeArrayOfObjCType:(const char*)type
                        count:(NSUInteger)count
                           at:(void*)pointer {
  _raiseInvalidAbstractException(_cmd);
}

/**
@Status Interoperable
*/
- (void*)decodeBytesWithReturnedLength:(NSUInteger*)lengthp {
  _raiseInvalidAbstractException(_cmd);
  return nullptr;
}

/**
@Status Interoperable
*/
- (NSPoint)decodePoint {
  _raiseInvalidAbstractException(_cmd);
  return (NSPoint){0, 0};
}

/**
@Status Interoperable
*/
- (NSSize)decodeSize {
  _raiseInvalidAbstractException(_cmd);
  return (NSSize){0, 0};
}

/**
@Status Interoperable
*/
- (NSRect)decodeRect {
  _raiseInvalidAbstractException(_cmd);
  return (NSRect){0, 0, 0, 0};
}

/**
@Status Interoperable
*/
- (BOOL)containsValueForKey:(NSString*)key {
  _raiseInvalidAbstractException(_cmd);
  return NO;
}

/**
@Status Interoperable
*/
- (const uint8_t*)decodeBytesForKey:(NSString*)key
                      returnedLength:(NSUInteger*)length {
  _raiseInvalidAbstractException(_cmd);
  return nullptr;
}

/**
@Status Interoperable
*/
- (NSPoint)decodePointForKey:(NSString*)key {
  _raiseInvalidAbstractException(_cmd);
  return (NSPoint){0, 0};
}

/**
@Status Interoperable
*/
- (NSRect)decodeRectForKey:(NSString*)key {
  _raiseInvalidAbstractException(_cmd);
  return (NSRect){0, 0, 0, 0};
}

/**
@Status Interoperable
*/
- (NSSize)decodeSizeForKey:(NSString*)key {
  _raiseInvalidAbstractException(_cmd);
  return (NSSize){0, 0};
}

/**
@Status Interoperable
*/
- (BOOL)decodeBoolForKey:(NSString*)key {
  _raiseInvalidAbstractException(_cmd);
  return NO;
}

/**
@Status Interoperable
*/
- (double)decodeDoubleForKey:(NSString*)key {
  _raiseInvalidAbstractException(_cmd);
  return 0.0;
}

/**
@Status Interoperable
*/
- (float)decodeFloatForKey:(NSString*)key {
  _raiseInvalidAbstractException(_cmd);
  return 0.0f;
}

/**
@Status Interoperable
*/
- (int)decodeIntForKey:(NSString*)key {
  _raiseInvalidAbstractException(_cmd);
  return 0;
}

/**
@Status Interoperable
*/
- (id)decodeObjectForKey:(NSString*)key {
  _raiseInvalidAbstractException(_cmd);
  return nil;
}

/**
@Status Interoperable
*/
- (id)decodeObjectOfClass:(Class)expectedClass forKey:(NSString*)key {
  _raiseInvalidAbstractException(_cmd);
  return nil;
}

/**
@Status Interoperable
*/
- (id)decodeObjectOfClasses:(NSSet*)expectedClasses forKey:(NSString*)key {
  _raiseInvalidAbstractException(_cmd);
  return nil;
}

/**
@Status Interoperable
*/
- (int32_t)decodeInt32ForKey:(NSString*)key {
  _raiseInvalidAbstractException(_cmd);
  return 0;
}

/**
@Status Interoperable
*/
- (int64_t)decodeInt64ForKey:(NSString*)key {
  _raiseInvalidAbstractException(_cmd);
  return 0;
}

/**
@Status Interoperable
*/
- (NSInteger)decodeIntegerForKey:(NSString*)key {
  _raiseInvalidAbstractException(_cmd);
  return 0;
}

@end
