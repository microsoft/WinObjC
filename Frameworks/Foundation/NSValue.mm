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

#import <Foundation/NSValue.h>
#import <NSRaise.h>
#import <Starboard.h>
#import <StubReturn.h>
#import <objc/encoding.h>

static unsigned hashBytes(void* bytes, size_t len) {
    unsigned ret = 0;
    char* cur = (char*)bytes;

    while (len--) {
        ret = (ret << 8) | (ret >> 24);
        ret ^= *cur;
        cur++;
    }

    return ret;
}

@interface _NSValueConcrete : NSValue
@end

@implementation _NSValueConcrete {
    woc::unique_iw<const char> _objCType;
    size_t _size;
    std::unique_ptr<unsigned char[]> _value;
}

- (NSValue*)init {
    [self release];
    return nil;
}

- (NSValue*)_initWithBytes:(const void*)ptr size:(size_t)sz objCType:(const char*)ocType {
    self = [super init];
    if (self) {
        _objCType.reset(IwStrDup(ocType));

        _size = sz;
        _value = std::make_unique<unsigned char[]>(_size);
        memcpy(_value.get(), ptr, _size);
    }
    return self;
}

- (NSValue*)initWithBytes:(const void*)value objCType:(const char*)valueOCType {
    return [self _initWithBytes:value size:objc_sizeof_type(valueOCType) objCType:valueOCType];
}

- (void)getValue:(void*)dest {
    memcpy(dest, _value.get(), _size);
}

- (const char*)objCType {
    return _objCType.get();
}

// Overridden to reduce copies
- (BOOL)isEqualToValue:(_NSValueConcrete*)other {
    if (![other isKindOfClass:[_NSValueConcrete class]]) {
        return [super isEqualToValue:other];
    }
    
    return (_size == other->_size &&
            0 == strcmp(_objCType.get(), other->_objCType.get()) &&
            0 == memcmp(_value.get(), other->_value.get(), _size));
}

// Overridden to reduce copies
- (NSObject*)copyWithZone:(NSZone*)zone {
    return [[NSValue allocWithZone:zone] initWithBytes:_value.get() objCType:_objCType.get()];
}

// Overridden to reduce copies
- (void)encodeWithCoder:(NSKeyedArchiver*)coder {
    [coder encodeObject:[NSString stringWithUTF8String:_objCType.get()] forKey:@"NSV.objCType"];
    [coder encodeBytes:static_cast<unsigned char*>(_value.get()) length:_size forKey:@"NSV.data"];
}

// Overridden to reduce copies
- (unsigned)hash {
    return hashBytes(_value.get(), _size);
}

- (NSString*)description {
    return [NSString stringWithFormat:@"<%u bytes of %s at %p>", _size, _objCType.get(), _value.get()];
}

- (Class)classForCoder {
    return [NSValue class];
}


@end

@implementation NSValue : NSObject

+ (NSObject*)allocWithZone : (NSZone*)zone {
    if (self == [NSValue class]) {
        return [_NSValueConcrete allocWithZone:zone];
    }

    return [super allocWithZone:zone];
}

/**
 @Status Interoperable
*/
- (NSValue*)initWithBytes:(const void*)value objCType:(const char*)valueOCType {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (const char*)objCType {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (void)getValue:(void*)dest {
    NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
+ (NSValue*)valueWithBytes:(const void*)value objCType:(const char*)valueOCType {
    return [[[self alloc] initWithBytes:value objCType:valueOCType] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSValue*)value:(const void*)value withObjCType:(const char*)objCType {
    return [self valueWithBytes:value objCType:objCType];
}

/**
 @Status Interoperable
*/
+ (NSValue*)valueWithRange:(NSRange)value {
    return [[[self alloc] initWithBytes:(void*)&value objCType:@encode(NSRange)] autorelease];
}

/**
 @Status Interoperable
*/
- (NSRange)rangeValue {
    NSRange val;
    [self getValue:&val];
    return val;
}

/**
 @Status Interoperable
*/
+ (NSValue*)valueWithPointer:(const void*)pointer {
    return [[[self alloc] initWithBytes:&pointer objCType:@encode(void*)] autorelease];
}

/**
 @Status Interoperable
*/
- (void*)pointerValue {
    void* val;
    [self getValue:&val];
    return val;
}

/**
 @Status Interoperable
*/
+ (NSValue*)valueWithNonretainedObject:(id)obj {
    return [[[self alloc] initWithBytes:&obj objCType:@encode(id)] autorelease];
}

/**
 @Status Interoperable
*/
- (id)nonretainedObjectValue {
    id val;
    [self getValue:&val];
    return val;
}

/**
 @Status Interoperable
*/
- (BOOL)isEqual:(id)other {
    if (![other isKindOfClass:[NSValue class]]) {
        return NO;
    }

    return [self isEqualToValue:other];
}

/**
 @Status Interoperable
*/
- (BOOL)isEqualToValue:(NSValue*)other {
    if (![other isKindOfClass:[NSValue class]]) {
        return NO;
    }
    
    int size = objc_sizeof_type([self objCType]);
    int otherSize = objc_sizeof_type([other objCType]);
    
    std::unique_ptr<char[]> selfValue = std::make_unique<char[]>(size);
    std::unique_ptr<char[]> otherValue = std::make_unique<char[]>(otherSize);

    [self getValue:selfValue.get()];
    [other getValue:otherValue.get()];

    return (size == otherSize &&
            0 == strcmp([self objCType], [other objCType]) &&
            0 == memcmp(selfValue.get(), otherValue.get(), size));
}

/**
 @Status Interoperable
*/
- (unsigned)hash {
    int size = objc_sizeof_type([self objCType]);
    std::unique_ptr<char[]> selfValue = std::make_unique<char[]>(size);
    [self getValue:selfValue.get()];
    return hashBytes(selfValue.get(), size);
}

/**
 @Status Interoperable
*/
- (NSObject*)copyWithZone:(NSZone*)zone {
    int size = objc_sizeof_type([self objCType]);
    std::unique_ptr<char[]> selfValue = std::make_unique<char[]>(size);
    [self getValue:selfValue.get()];
    return [[NSValue allocWithZone:zone] initWithBytes:selfValue.get() objCType:[self objCType]];
}

/**
 @Status Interoperable
*/
+ (BOOL)supportsSecureCoding {
    return YES;
}

/**
 @Status Interoperable
*/
- (NSValue*)initWithCoder:(NSKeyedUnarchiver*)coder {
    unsigned size;
    void* data = (void*)[coder decodeBytesForKey:@"NSV.data" returnedLength:&size];
    assert(size != 0 && data != NULL);

    const char* objCType = [[coder decodeObjectForKey:@"NSV.objCType"] UTF8String];

    return [self initWithBytes:data objCType:objCType];
}

/**
 @Status Interoperable
*/
- (void)encodeWithCoder:(NSKeyedArchiver*)coder {
    [coder encodeObject:[NSString stringWithUTF8String:[self objCType]] forKey:@"NSV.objCType"];
    int size = objc_sizeof_type([self objCType]);
    std::unique_ptr<unsigned char[]> selfValue = std::make_unique<unsigned char[]>(size);
    [self getValue:selfValue.get()];
    [coder encodeBytes:static_cast<const unsigned char*>(selfValue.get()) length:size forKey:@"NSV.data"];
}

@end