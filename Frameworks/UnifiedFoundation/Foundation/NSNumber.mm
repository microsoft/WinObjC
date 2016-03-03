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

#include <limits>
#import "Starboard.h"
#import "Foundation/NSNumber.h"
#import "Foundation/NSString.h"

static const size_t c_cacheNSNumbersBelow = 16;
static StrongId<NSNumber> s_cachedNumbers[c_cacheNSNumbersBelow];

template <typename T>
static bool shouldStoreAsInt(T value) {
    // Small integers should be stored as ints so we can satisfy requests out of the cache
    return std::numeric_limits<T>::is_integer && (value >= 0) && (value < c_cacheNSNumbersBelow);
}

@implementation NSNumber

/**
 @Status Interoperable
*/
+ (void)initialize {
    if (self == [NSNumber class]) {
        for (size_t i = 0; i < c_cacheNSNumbersBelow; i++) {
            s_cachedNumbers[i].attach([[NSNumber alloc] initWithInt:i]);
        }
    }
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    if ([coder containsValueForKey:@"NS.intval"]) {
        val.i = (int)[coder decodeIntForKey:@"NS.intval"];
        type = integerType;
        objCType = @encode(int);
    } else {
        assert(0);
    }

    return self;
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithChar:(char)num {
    if (shouldStoreAsInt(num)) {
        return [self numberWithInt:num];
    }

    return [[self alloc] initWithChar:num];
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithUnsignedChar:(unsigned char)num {
    if (shouldStoreAsInt(num)) {
        return [self numberWithInt:num];
    }

    return [[self alloc] initWithUnsignedChar:num];
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithInteger:(int)num {
    return [self numberWithInt:num];
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithUnsignedInt:(unsigned int)num {
    return [self numberWithInt:num];
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithUnsignedInteger:(NSUInteger)num {
    return [self numberWithInt:num];
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithInt:(int)num {
    if (num >= 0 && num < c_cacheNSNumbersBelow) {
        return s_cachedNumbers[num];
    } else {
        return [[[self alloc] initWithInt:num] autorelease];
    }
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithShort:(short)num {
    if (shouldStoreAsInt(num)) {
        return [self numberWithInt:num];
    }

    NSNumber* ret = [self alloc];
    return [[ret initWithShort:num] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithUnsignedShort:(unsigned short)num {
    if (shouldStoreAsInt(num)) {
        return [self numberWithInt:num];
    }

    NSNumber* ret = [self alloc];
    return [[ret initWithUnsignedShort:num] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithLong:(long)num {
    if (shouldStoreAsInt(num)) {
        return [self numberWithInt:num];
    }

    NSNumber* ret = [self alloc];
    return [[ret initWithLong:num] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithUnsignedLong:(unsigned long)num {
    if (shouldStoreAsInt(num)) {
        return [self numberWithInt:num];
    }

    NSNumber* ret = [self alloc];
    return [[ret initWithUnsignedLong:num] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)zero {
    return [self numberWithInt:0];
}

/**
 @Status Interoperable
*/
+ (instancetype)one {
    return [self numberWithInt:1];
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithLongLong:(long long)num {
    if (shouldStoreAsInt(num)) {
        return [self numberWithInt:num];
    }

    NSNumber* ret = [self alloc];
    return [[ret initWithLongLong:num] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)num {
    if (shouldStoreAsInt(num)) {
        return [self numberWithInt:num];
    }

    NSNumber* ret = [self alloc];
    return [[ret initWithUnsignedLongLong:num] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithBool:(BOOL)num {
    NSNumber* ret = [self alloc];
    return [[ret initWithBool:num] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithFloat:(float)num {
    NSNumber* ret = [self alloc];
    return [[ret initWithFloat:num] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithDouble:(double)num {
    NSNumber* ret = [self alloc];
    return [[ret initWithDouble:num] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithInt:(int)num {
    val.i = num;
    type = integerType;
    objCType = @encode(int);

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithInteger:(NSInteger)num {
    val.i = num;
    type = integerType;
    objCType = @encode(NSInteger);

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithShort:(short)num {
    val.i = num;
    type = integerType;
    objCType = @encode(short);

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithUnsignedShort:(unsigned short)num {
    val.i = num;
    type = integerType;
    objCType = @encode(unsigned short);

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithLong:(long)num {
    val.i = num;
    type = integerType;
    objCType = @encode(long);

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithUnsignedLong:(unsigned long)num {
    val.i = num;
    type = integerType;
    objCType = @encode(unsigned long);

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithUnsignedInt:(unsigned int)num {
    val.i = num;
    type = integerType;
    objCType = @encode(unsigned int);

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithUnsignedInteger:(NSUInteger)num {
    val.i = num;
    type = integerType;
    objCType = @encode(NSUInteger);

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithBool:(BOOL)num {
    val.i = num;
    type = integerType;
    isBool = true;
    objCType = @encode(char);

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithChar:(char)num {
    val.i = num;
    type = integerType;
    objCType = @encode(char);

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithUnsignedChar:(unsigned char)num {
    val.i = num;
    type = integerType;
    objCType = @encode(unsigned char);

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithLongLong:(long long)num {
    val.i = num;
    type = int64Type;
    objCType = @encode(long long);

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithUnsignedLongLong:(unsigned long long)num {
    val.i = num;
    type = int64Type;
    objCType = @encode(unsigned long long);

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFloat:(float)num {
    val.f = num;
    type = floatType;
    objCType = @encode(float);

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithDouble:(double)num {
    val.f = num;
    type = doubleType;
    objCType = @encode(double);

    return self;
}

/**
 @Status Interoperable
*/
- (BOOL)isEqual:(NSObject*)objAddr {
    return [self compare:objAddr] == 0;
}

/**
 @Status Interoperable
*/
- (BOOL)isEqualToNumber:(NSNumber*)objAddr {
    return [self compare:objAddr] == 0;
}

/**
 @Status Interoperable
*/
- (int)compare:(NSNumber*)objAddr {
    if (objAddr == self) {
        return 0;
    }
    if (objAddr != nil && [objAddr isKindOfClass:[NSNumber class]]) {
        if (type == objAddr->type) {
            if (val.i < objAddr->val.i) {
                return -1;
            } else if (val.i > objAddr->val.i) {
                return 1;
            } else {
                return 0;
            }
        } else {
            if ([self doubleValue] < [objAddr doubleValue]) {
                return -1;
            } else if ([self doubleValue] > [objAddr doubleValue]) {
                return 1;
            } else {
                return 0;
            }
        }
    }

    return -1;
}

/**
 @Status Interoperable
*/
- (id)copyWithZone:(NSZone*)zone {
    return [self retain];
}

/**
 @Status Interoperable
*/
- (int)intValue {
    if (type == integerType || type == int64Type) {
        return (signed int)val.i;
    } else {
        return (signed int)val.f;
    }
}

/**
 @Status Interoperable
*/
- (NSUInteger)unsignedIntValue {
    if (type == integerType || type == int64Type) {
        return (NSUInteger)val.i;
    } else {
        return (NSUInteger)val.f;
    }
}

/**
 @Status Interoperable
*/
- (short)shortValue {
    return [self intValue] & 0xFFFF;
}

/**
 @Status Interoperable
*/
- (BOOL)boolValue {
    return [self intValue];
}

/**
 @Status Interoperable
*/
- (char)charValue {
    return (char)[self intValue];
}

/**
 @Status Interoperable
*/
- (unsigned char)unsignedCharValue {
    return (unsigned char)[self intValue];
}

/**
 @Status Interoperable
*/
- (unsigned short)unsignedShortValue {
    return (unsigned short)[self intValue];
}

/**
 @Status Interoperable
*/
- (float)floatValue {
    if (type == integerType || type == int64Type) {
        switch (*objCType) {
            case 'i':
            case 'l':
            case 'q':
            case 'c':
                return (float)((int64_t)val.i);
        }

        return (float)val.i;
    } else {
        return (float)val.f;
    }
}

/**
 @Status Interoperable
*/
- (long)longValue {
    if (type == integerType || type == int64Type) {
        return (long)val.i;
    } else {
        return (long)val.f;
    }
}

/**
 @Status Interoperable
*/
- (unsigned long)unsignedLongValue {
    if (type == integerType || type == int64Type) {
        return (unsigned long)val.i;
    } else {
        return (unsigned long)val.f;
    }
}

/**
 @Status Interoperable
*/
- (unsigned long long)unsignedLongLongValue {
    if (type == integerType || type == int64Type) {
        return (unsigned long long)val.i;
    } else {
        return (unsigned long long)val.f;
    }
}

/**
 @Status Interoperable
*/
- (long long)longLongValue {
    if (type == integerType || type == int64Type) {
        return (signed __int64)val.i;
    } else {
        return (signed __int64)val.f;
    }
}

- (BOOL)_isBool {
    return isBool;
}

/**
 @Status Interoperable
*/
- (NSDecimal)decimalValue {
    NSDecimal ret = {[self doubleValue] };
    return ret;
}

/**
 @Status Interoperable
*/
- (double)doubleValue {
    if (type == integerType || type == int64Type) {
        return (double)val.i;
    } else {
        return (double)val.f;
    }
}

/**
 @Status Interoperable
*/
- (NSString*)stringValue {
    NSString* ret;

    switch (objCType[0]) {
        case 'i':
        case 'l':
            ret = [NSString stringWithFormat:@"%d", static_cast<int>(val.i)];
            break;

        case 'I':
        case 'L':
            ret = [NSString stringWithFormat:@"%u", static_cast<unsigned int>(val.i)];
            break;

        case 'q':
            ret = [NSString stringWithFormat:@"%lld", val.i];
            break;

        case 'Q':
            ret = [NSString stringWithFormat:@"%llu", val.i];
            break;

        case 'f':
        case 'd':
            ret = [NSString stringWithFormat:@"%f", val.f];
            break;

        case 'c':
            // TODO: 6546983 ideally using "%hhd", so we can get rid of (short) cast
            // but it was not supported, so we cast the value to char and then short
            // and then format the value using short
            ret = [NSString stringWithFormat:@"%hd", static_cast<short>(static_cast<char>(val.i))];
            break;

        case 'C':
            // TODO: 6546983 ideally using "%hhu", so we can get rid of (unsigned short) cast
            // but it was not supported, so we cast the value to char and then usinged short
            // and then format the value using unsigned short
            ret = [NSString stringWithFormat:@"%hu", static_cast<unsigned short>(static_cast<char>(val.i))];
            break;

        case 's':
            ret = [NSString stringWithFormat:@"%hd", static_cast<short>(val.i)];
            break;

        case 'S':
            ret = [NSString stringWithFormat:@"%hu", static_cast<unsigned short>(val.i)];
            break;

        default:
            assert(0);
            break;
    }

    return ret;
}

/**
 @Status Interoperable
*/
- (const char*)objCType {
    return objCType;
}

/**
 @Status Interoperable
*/
- (Class)classForCoder {
    return [NSNumber class];
}

/**
 @Status Interoperable
*/
- (NSString*)description {
    return [self stringValue];
}

/**
 @Status Caveat
 @Notes Doesn't take NSLocale into account.
*/
- (NSString*)descriptionWithLocale:(NSLocale*)locale {
    return [self description];
}

/**
 @Status Interoperable
*/
- (unsigned)hash {
    return [self intValue];
}

/**
 @Status Interoperable
*/
- (void)getValue:(void*)dest {
    switch (objCType[0]) {
        case 'i':
        case 'l':
        case 'I':
            *((int*)dest) = (int)val.i;
            break;

        case 'q':
        case 'Q':
            *((__int64*)dest) = val.i;
            break;

        case 'f':
            *((float*)dest) = (float)val.f;
            break;

        case 'd':
            *((double*)dest) = val.f;
            break;

        case 'c':
            *((char*)dest) = (char)val.i;
            break;
        case 's':
        case 'S':
            *((short*)dest) = (short)val.i;
            break;
        default:
            assert(0);
            break;
    }
}

/**
 @Status Interoperable
*/
- (NSUInteger)unsignedIntegerValue {
    return [self intValue];
}

/**
 @Status Interoperable
*/
- (int)integerValue {
    return [self intValue];
}

@end

/**
 @Status Stub
*/
DWORD NSDecimalCompare(NSDecimal* num1, NSDecimal* num2) {
    UNIMPLEMENTED();
    if (num1->val < num2->val) {
        return -1;
    } else if (num1->val > num2->val) {
        return 1;
    } else {
        return 0;
    }
}

/**
 @Status Stub
*/
DWORD NSDecimalAdd(NSDecimal* result, NSDecimal* left, NSDecimal* right, DWORD rounding) {
    UNIMPLEMENTED();
    result->val = left->val + right->val;
    return 0;
}

/**
 @Status Stub
*/
DWORD NSDecimalSubtract(NSDecimal* result, NSDecimal* left, NSDecimal* right, DWORD rounding) {
    UNIMPLEMENTED();
    result->val = left->val - right->val;
    return 0;
}

/**
 @Status Stub
*/
DWORD NSDecimalDivide(NSDecimal* result, NSDecimal* left, NSDecimal* right, DWORD rounding) {
    UNIMPLEMENTED();
    result->val = left->val / right->val;
    return 0;
}

/**
 @Status Stub
*/
DWORD NSDecimalMultiply(NSDecimal* result, NSDecimal* left, NSDecimal* right, DWORD rounding) {
    UNIMPLEMENTED();
    result->val = left->val * right->val;
    return 0;
}

/**
 @Status Stub
*/
DWORD NSDecimalIsNotANumber(NSDecimal* num) {
    UNIMPLEMENTED();
    if (num->val != num->val) {
        return TRUE;
    }
    return FALSE;
}

/**
 @Status Stub
*/
DWORD NSDecimalRound(NSDecimal* result, NSDecimal* num, int scale, DWORD rounding) {
    UNIMPLEMENTED();
    result->val = num->val;
    return 0;
}

/**
 @Status Stub
*/
NSString* NSDecimalString(NSDecimal* num, id locale) {
    UNIMPLEMENTED();
    char szVal[128];
    sprintf_s(szVal, sizeof(szVal), "%f", num->val);
    return [NSString stringWithCString:szVal];
}

@interface NSCFBoolean : NSNumber {
@public
}
@end

@implementation NSCFBoolean
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-missing-super-calls"
/**
 @Status Interoperable
*/
- (void)dealloc {
}
#pragma clang diagnostic pop

/**
 @Status Interoperable
*/
- (instancetype)retain {
    return self;
}

/**
 @Status Interoperable
*/
- (oneway void)release {
}

/**
 @Status Interoperable
*/
+ (void)load {
    object_setClass(((NSCFBoolean*)kCFBooleanTrue), self);
    object_setClass(((NSCFBoolean*)kCFBooleanFalse), self);
}
@end
