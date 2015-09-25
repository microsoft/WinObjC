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
#include "Foundation/NSNumber.h"
#include "Foundation/NSString.h"

#define CACHE_NSNUMBERS_BELOW 16
static id cachedNumbers[CACHE_NSNUMBERS_BELOW];

@implementation NSNumber : NSValue
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

+ (instancetype)numberWithChar:(char)num {
    return [[self alloc] initWithChar:num];
}

+ (instancetype)numberWithUnsignedChar:(unsigned char)num {
    return [[self alloc] initWithUnsignedChar:num];
}

+ (instancetype)numberWithInteger:(int)num {
    return [self numberWithInt:num];
}

+ (instancetype)numberWithUnsignedInt:(unsigned int)num {
    return [self numberWithInt:num];
}

+ (instancetype)numberWithUnsignedInteger:(NSUInteger)num {
    return [self numberWithInt:num];
}

+ (instancetype)numberWithInt:(int)num {
    if (num >= 0 && num < CACHE_NSNUMBERS_BELOW) {
        if (cachedNumbers[num] != nil) {
            return [cachedNumbers[num] retain];
        }
    }
    NSNumber* ret = [self alloc];
    ret = [[ret initWithInt:num] autorelease];

    if (num >= 0 && num < CACHE_NSNUMBERS_BELOW) {
        cachedNumbers[num] = [ret retain];
    }

    return ret;
}

+ (instancetype)numberWithShort:(short)num {
    NSNumber* ret = [self alloc];
    return [[ret initWithShort:num] autorelease];
}

+ (instancetype)numberWithUnsignedShort:(unsigned short)num {
    NSNumber* ret = [self alloc];
    return [[ret initWithUnsignedShort:num] autorelease];
}

+ (instancetype)numberWithLong:(long)num {
    NSNumber* ret = [self alloc];
    return [[ret initWithLong:num] autorelease];
}

+ (instancetype)numberWithUnsignedLong:(unsigned long)num {
    NSNumber* ret = [self alloc];
    return [[ret initWithUnsignedLong:num] autorelease];
}

+ (instancetype)zero {
    return [self numberWithInt:0];
}

+ (instancetype)one {
    return [self numberWithInt:0];
}

+ (instancetype)numberWithLongLong:(long long)num {
    NSNumber* ret = [self alloc];
    return [[ret initWithLongLong:num] autorelease];
}

+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)num {
    NSNumber* ret = [self alloc];
    return [[ret initWithUnsignedLongLong:num] autorelease];
}

+ (instancetype)numberWithBool:(BOOL)num {
    NSNumber* ret = [self alloc];
    return [[ret initWithBool:num] autorelease];
}

+ (instancetype)numberWithFloat:(float)num {
    NSNumber* ret = [self alloc];
    return [[ret initWithFloat:num] autorelease];
}

+ (instancetype)numberWithDouble:(double)num {
    NSNumber* ret = [self alloc];
    return [[ret initWithDouble:num] autorelease];
}

- (instancetype)initWithInt:(int)num {
    val.i = num;
    type = integerType;
    objCType = @encode(int);

    return self;
}

- (instancetype)initWithInteger:(NSInteger)num {
    val.i = num;
    type = integerType;
    objCType = @encode(NSInteger);

    return self;
}

- (instancetype)initWithShort:(short)num {
    val.i = num;
    type = integerType;
    objCType = @encode(short);

    return self;
}

- (instancetype)initWithUnsignedShort:(unsigned short)num {
    val.i = num;
    type = integerType;
    objCType = @encode(unsigned short);

    return self;
}

- (instancetype)initWithLong:(long)num {
    val.i = num;
    type = integerType;
    objCType = @encode(long);

    return self;
}

- (instancetype)initWithUnsignedLong:(unsigned long)num {
    val.i = num;
    type = integerType;
    objCType = @encode(unsigned long);

    return self;
}

- (instancetype)initWithUnsignedInt:(unsigned int)num {
    val.i = num;
    type = integerType;
    objCType = @encode(unsigned int);

    return self;
}

- (instancetype)initWithUnsignedInteger:(NSUInteger)num {
    val.i = num;
    type = integerType;
    objCType = @encode(NSUInteger);

    return self;
}

- (instancetype)initWithBool:(BOOL)num {
    val.i = num;
    type = integerType;
    isBool = true;
    objCType = @encode(char);

    return self;
}

- (instancetype)initWithChar:(char)num {
    val.i = num;
    type = integerType;
    objCType = @encode(char);

    return self;
}

- (instancetype)initWithUnsignedChar:(unsigned char)num {
    val.i = num;
    type = integerType;
    objCType = @encode(unsigned char);

    return self;
}

- (instancetype)initWithLongLong:(long long)num {
    val.i = num;
    type = int64Type;
    objCType = @encode(long long);

    return self;
}

- (instancetype)initWithUnsignedLongLong:(unsigned long long)num {
    val.i = num;
    type = int64Type;
    objCType = @encode(unsigned long long);

    return self;
}

- (instancetype)initWithFloat:(float)num {
    val.f = num;
    type = floatType;
    objCType = @encode(float);

    return self;
}

- (instancetype)initWithDouble:(double)num {
    val.f = num;
    type = doubleType;
    objCType = @encode(double);

    return self;
}

- (BOOL)isEqual:(NSObject*)objAddr {
    return [self compare:objAddr] == 0;
}

- (BOOL)isEqualToNumber:(NSNumber*)objAddr {
    return [self compare:objAddr] == 0;
}

- (int)compare:(NSNumber*)objAddr {
    if (objAddr == self)
        return 0;
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

- (id)copyWithZone:(NSZone*)zone {
    return [self retain];
}

- (int)intValue {
    if (type == integerType || type == int64Type) {
        return (signed int)val.i;
    } else {
        return (signed int)val.f;
    }
}

- (NSUInteger)unsignedIntValue {
    if (type == integerType || type == int64Type) {
        return (NSUInteger)val.i;
    } else {
        return (NSUInteger)val.f;
    }
}

- (short)shortValue {
    return [self intValue] & 0xFFFF;
}

- (BOOL)boolValue {
    return [self intValue];
}

- (char)charValue {
    return (char)[self intValue];
}

- (unsigned char)unsignedCharValue {
    return (unsigned char)[self intValue];
}

- (unsigned short)unsignedShortValue {
    return (unsigned short)[self intValue];
}

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

- (long)longValue {
    if (type == integerType || type == int64Type) {
        return (long)val.i;
    } else {
        return (long)val.f;
    }
}

- (unsigned long)unsignedLongValue {
    if (type == integerType || type == int64Type) {
        return (unsigned long)val.i;
    } else {
        return (unsigned long)val.f;
    }
}

- (unsigned long long)unsignedLongLongValue {
    if (type == integerType || type == int64Type) {
        return (unsigned long long)val.i;
    } else {
        return (unsigned long long)val.f;
    }
}

- (long long)longLongValue {
    if (type == integerType || type == int64Type) {
        return (signed __int64)val.i;
    } else {
        return (signed __int64)val.f;
    }
}

- (void)_copyInt64Value:(void*)dest {
    unsigned __int64 ret = [self unsignedLongLongValue];
    memcpy(dest, &ret, 8);
}

- (BOOL)_isBool {
    return isBool;
}

- (NSDecimal)decimalValue {
    NSDecimal ret = {[self doubleValue] };
    return ret;
}

- (double)doubleValue {
    if (type == integerType || type == int64Type) {
        return (double)val.i;
    } else {
        return (double)val.f;
    }
}

- (NSString*)stringValue {
    NSString* ret;

    switch (objCType[0]) {
        case 'i':
        case 'l':
            ret = [NSString stringWithFormat:@"%d", (int)val.i];
            break;

        case 'I':
        case 'L':
            ret = [NSString stringWithFormat:@"%u", (unsigned int)val.i];
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
        case 'C':
            ret = [NSString stringWithFormat:@"%i", val.i];
            break;

        default:
            assert(0);
            break;
    }

    return ret;
}

- (const char*)objCType {
    return objCType;
}

- (id)classForArchiver {
    return [NSNumber class];
}

- (NSString*)description {
    return [self stringValue];
}

- (NSString*)descriptionWithLocale:(NSLocale*)locale {
    return [self description];
}

- (unsigned)hash {
    return [self intValue];
}

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

        default:
            assert(0);
            break;
    }
}

- (NSUInteger)unsignedIntegerValue {
    return [self intValue];
}

- (int)integerValue {
    return [self intValue];
}

@end

DWORD NSDecimalCompare(NSDecimal* num1, NSDecimal* num2) {
    if (num1->val < num2->val) {
        return -1;
    } else if (num1->val > num2->val) {
        return 1;
    } else {
        return 0;
    }
}

DWORD NSDecimalAdd(NSDecimal* result, NSDecimal* left, NSDecimal* right, DWORD rounding) {
    result->val = left->val + right->val;
    return 0;
}

DWORD NSDecimalSubtract(NSDecimal* result, NSDecimal* left, NSDecimal* right, DWORD rounding) {
    result->val = left->val - right->val;
    return 0;
}

DWORD NSDecimalDivide(NSDecimal* result, NSDecimal* left, NSDecimal* right, DWORD rounding) {
    result->val = left->val / right->val;
    return 0;
}

DWORD NSDecimalMultiply(NSDecimal* result, NSDecimal* left, NSDecimal* right, DWORD rounding) {
    result->val = left->val * right->val;
    return 0;
}

DWORD NSDecimalIsNotANumber(NSDecimal* num) {
    if (num->val != num->val)
        return TRUE;
    return FALSE;
}

DWORD NSDecimalRound(NSDecimal* result, NSDecimal* num, int scale, DWORD rounding) {
    result->val = num->val;
    return 0;
}

NSString* NSDecimalString(NSDecimal* num, id locale) {
    char szVal[128];
    sprintf(szVal, "%f", num->val);
    return [NSString stringWithCString:szVal];
}

@interface NSCFBoolean : NSNumber {
@public
}
@end

@implementation NSCFBoolean : NSNumber
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-missing-super-calls"
- (void)dealloc {
}
#pragma clang diagnostic pop

- (instancetype)retain {
    return self;
}

- (oneway void)release {
}

+ (void)load {
    object_setClass(((NSCFBoolean*)kCFBooleanTrue), self);
    object_setClass(((NSCFBoolean*)kCFBooleanFalse), self);
}
@end
