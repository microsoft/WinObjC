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

static const size_t c_cacheIntsBelow = 16;
static StrongId<NSNumber> s_cachedInts[c_cacheIntsBelow];

template <typename T>
static bool shouldStoreAsInt(T value) {
    // Small integers should be stored as ints so we can satisfy requests out of the cache
    return std::numeric_limits<T>::is_integer && (value >= 0) && (value < c_cacheIntsBelow);
}

// Union for the internal storage of NSNumber
union _NSNumberInternalValue {
    // BOOL, NSInteger, and NSUInteger are typedefs of other types below
    char charValue;
    double doubleValue;
    float floatValue;
    int intValue;
    long longValue;
    long long longLongValue;
    short shortValue;
    unsigned char unsignedCharValue;
    unsigned int unsignedIntValue;
    unsigned long unsignedLongValue;
    unsigned long long unsignedLongLongValue;
    unsigned short unsignedShortValue;

    // Default constructor for this union zeroes out the internal memory
    _NSNumberInternalValue() : unsignedLongLongValue() {
    }

    // Returns a pointer to the appropriate primitive unionValue in the union, based on the template type
    template <typename TNumberType>
    TNumberType* _getRawValuePointer();

    template <>
    char* _getRawValuePointer() {
        return &charValue;
    }

    template <>
    double* _getRawValuePointer() {
        return &doubleValue;
    }

    template <>
    float* _getRawValuePointer() {
        return &floatValue;
    }

    template <>
    int* _getRawValuePointer() {
        return &intValue;
    }

    template <>
    long* _getRawValuePointer() {
        return &longValue;
    }

    template <>
    long long* _getRawValuePointer() {
        return &longLongValue;
    }

    template <>
    short* _getRawValuePointer() {
        return &shortValue;
    }

    template <>
    unsigned char* _getRawValuePointer() {
        return &unsignedCharValue;
    }

    template <>
    unsigned int* _getRawValuePointer() {
        return &unsignedIntValue;
    }

    template <>
    unsigned long* _getRawValuePointer() {
        return &unsignedLongValue;
    }

    template <>
    unsigned long long* _getRawValuePointer() {
        return &unsignedLongLongValue;
    }

    template <>
    unsigned short* _getRawValuePointer() {
        return &unsignedShortValue;
    }

    // Getter and setter for the union
    template <typename TNumberType>
    TNumberType getRawValue() {
        return *_getRawValuePointer<TNumberType>();
    }

    template <typename TNumberType>
    void setRawValue(TNumberType num) {
        *_getRawValuePointer<TNumberType>() = num;
    }

    // Helper for returning a casted version of the raw value
    // The function name is meant to be read like: getRawValueAs<int>
    template <typename TNumberType>
    TNumberType getRawValueAs(const char* objCType) {
        switch (objCType[0]) {
            case 'c':
                return static_cast<TNumberType>(getRawValue<char>());
            case 'd':
                return static_cast<TNumberType>(getRawValue<double>());
            case 'f':
                return static_cast<TNumberType>(getRawValue<float>());
            case 'i':
                return static_cast<TNumberType>(getRawValue<int>());
            case 'l':
                return static_cast<TNumberType>(getRawValue<long>());
            case 'q':
                return static_cast<TNumberType>(getRawValue<long long>());
            case 's':
                return static_cast<TNumberType>(getRawValue<short>());
            case 'C':
                return static_cast<TNumberType>(getRawValue<unsigned char>());
            case 'I':
                return static_cast<TNumberType>(getRawValue<unsigned int>());
            case 'L':
                return static_cast<TNumberType>(getRawValue<unsigned long>());
            case 'Q':
                return static_cast<TNumberType>(getRawValue<unsigned long long>());
            case 'S':
                return static_cast<TNumberType>(getRawValue<unsigned short>());
            default:
                assert(0);
                return 0;
        }
    }
};

#pragma region NSNumber Initializer and Constructor Helpers

template <typename TNumberType>
static void _initWithRawValue(TNumberType rawValue, _NSNumberInternalValue& unionValue, const char** pObjCType) {
    unionValue.setRawValue(rawValue);
    *pObjCType = @encode(TNumberType);
}

#define INIT_WITH_NUM_AND_RETURN(num)             \
    if (self = [super init]) {                    \
        _initWithRawValue(num, _val, &_objCType); \
    }                                             \
    return self

#define RETURN_CACHED_IF_CACHED(num)                       \
    if (shouldStoreAsInt(num)) {                           \
        return [self numberWithInt:static_cast<int>(num)]; \
    }

#pragma endregion

@implementation NSNumber {
@private
    _NSNumberInternalValue _val;
    const char* _objCType;
    BOOL _isBool;
}

/**
 @Status Interoperable
*/
+ (void)initialize {
    if (self == [NSNumber class]) {
        for (size_t i = 0; i < c_cacheIntsBelow; i++) {
            s_cachedInts[i].attach([[NSNumber alloc] initWithInt:i]);
        }
    }
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    if ([coder containsValueForKey:@"NS.intval"]) {
        _val.intValue = (int)[coder decodeIntForKey:@"NS.intval"];
        _objCType = @encode(int);
    } else {
        FAIL_FAST_HR_MSG(E_UNEXPECTED, "NSNumber initWithCoder with non-integer unsupported");
    }

    return self;
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithBool:(BOOL)num {
    return [[[self alloc] initWithBool:num] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithChar:(char)num {
    RETURN_CACHED_IF_CACHED(num);
    return [[[self alloc] initWithChar:num] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithDouble:(double)num {
    RETURN_CACHED_IF_CACHED(num);
    return [[[self alloc] initWithDouble:num] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithFloat:(float)num {
    RETURN_CACHED_IF_CACHED(num);
    return [[[self alloc] initWithFloat:num] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithInt:(int)num {
    if (num >= 0 && num < c_cacheIntsBelow) {
        return s_cachedInts[num];
    }
    return [[[self alloc] initWithInt:num] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithInteger:(NSInteger)num {
    RETURN_CACHED_IF_CACHED(num);
    return [[[self alloc] initWithInteger:num] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithLong:(long)num {
    RETURN_CACHED_IF_CACHED(num);
    return [[[self alloc] initWithLong:num] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithLongLong:(long long)num {
    RETURN_CACHED_IF_CACHED(num);
    return [[[self alloc] initWithLongLong:num] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithShort:(short)num {
    RETURN_CACHED_IF_CACHED(num);
    return [[[self alloc] initWithShort:num] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithUnsignedChar:(unsigned char)num {
    RETURN_CACHED_IF_CACHED(num);
    return [[[self alloc] initWithUnsignedChar:num] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithUnsignedInt:(unsigned int)num {
    RETURN_CACHED_IF_CACHED(num);
    return [[[self alloc] initWithUnsignedInt:num] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithUnsignedInteger:(NSUInteger)num {
    RETURN_CACHED_IF_CACHED(num);
    return [[[self alloc] initWithUnsignedInteger:num] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithUnsignedLong:(unsigned long)num {
    RETURN_CACHED_IF_CACHED(num);
    return [[[self alloc] initWithUnsignedLong:num] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)num {
    RETURN_CACHED_IF_CACHED(num);
    return [[[self alloc] initWithUnsignedLongLong:num] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)numberWithUnsignedShort:(unsigned short)num {
    RETURN_CACHED_IF_CACHED(num);
    return [[[self alloc] initWithUnsignedShort:num] autorelease];
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
- (instancetype)initWithBool:(BOOL)num {
    _initWithRawValue(num, _val, &_objCType);
    _isBool = YES;
    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithChar:(char)num {
    INIT_WITH_NUM_AND_RETURN(num);
}

/**
 @Status Interoperable
*/
- (instancetype)initWithDouble:(double)num {
    INIT_WITH_NUM_AND_RETURN(num);
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFloat:(float)num {
    INIT_WITH_NUM_AND_RETURN(num);
}

/**
 @Status Interoperable
*/
- (instancetype)initWithInt:(int)num {
    INIT_WITH_NUM_AND_RETURN(num);
}

/**
 @Status Interoperable
*/
- (instancetype)initWithInteger:(NSInteger)num {
    INIT_WITH_NUM_AND_RETURN(num);
}

/**
 @Status Interoperable
*/
- (instancetype)initWithLong:(long)num {
    INIT_WITH_NUM_AND_RETURN(num);
}

/**
 @Status Interoperable
*/
- (instancetype)initWithLongLong:(long long)num {
    INIT_WITH_NUM_AND_RETURN(num);
}

/**
 @Status Interoperable
*/
- (instancetype)initWithShort:(short)num {
    INIT_WITH_NUM_AND_RETURN(num);
}

/**
 @Status Interoperable
*/
- (instancetype)initWithUnsignedChar:(unsigned char)num {
    INIT_WITH_NUM_AND_RETURN(num);
}

/**
 @Status Interoperable
*/
- (instancetype)initWithUnsignedInt:(unsigned int)num {
    INIT_WITH_NUM_AND_RETURN(num);
}

/**
 @Status Interoperable
*/
- (instancetype)initWithUnsignedInteger:(NSUInteger)num {
    INIT_WITH_NUM_AND_RETURN(num);
}

/**
 @Status Interoperable
*/
- (instancetype)initWithUnsignedLong:(unsigned long)num {
    INIT_WITH_NUM_AND_RETURN(num);
}

/**
 @Status Interoperable
*/
- (instancetype)initWithUnsignedLongLong:(unsigned long long)num {
    INIT_WITH_NUM_AND_RETURN(num);
}

/**
 @Status Interoperable
*/
- (instancetype)initWithUnsignedShort:(unsigned short)num {
    INIT_WITH_NUM_AND_RETURN(num);
}

/**
 @Status Interoperable
*/
- (BOOL)isEqual:(NSObject*)objAddr {
    if ([objAddr isKindOfClass:[NSNumber class]]) {
        return [self isEqualToNumber:(NSNumber*)objAddr];
    }
    return NO;
}

/**
 @Status Interoperable
*/
- (BOOL)isEqualToNumber:(NSNumber*)objAddr {
    return [self compare:objAddr] == 0;
}

#pragma region NSNumber compare Helpers
- (BOOL)_isUnsigned {
    return isupper(_objCType[0]);
}

- (BOOL)_isFloatingPoint {
    char objCTypeLowered = tolower(_objCType[0]);
    return (objCTypeLowered == 'f') || (objCTypeLowered == 'd');
}

template <typename TNumberType>
static int _NSNumberCompare(TNumberType selfValue, TNumberType otherValue) {
    if (selfValue > otherValue) {
        return 1;
    } else if (selfValue < otherValue) {
        return -1;
    } else {
        return 0;
    }
}

static int _NSNumberCompareUnsignedSigned(unsigned long long unsignedValue, long long signedValue) {
    if (unsignedValue > LLONG_MAX) {
        return 1;
    } else {
        return _NSNumberCompare(static_cast<long long>(unsignedValue), signedValue);
    }
}
#pragma endregion

/**
 @Status Interoperable
*/
- (int)compare:(NSNumber*)other {
    if (other == self) {
        return 0;
    }

    if ([self _isFloatingPoint] || [other _isFloatingPoint]) {
        return _NSNumberCompare([self doubleValue], [other doubleValue]);

    } else {
        BOOL selfUnsigned = [self _isUnsigned];
        BOOL otherUnsigned = [other _isUnsigned];

        if (selfUnsigned && otherUnsigned) {
            return _NSNumberCompare([self unsignedLongLongValue], [other unsignedLongLongValue]);
        } else if (!selfUnsigned && !otherUnsigned) {
            return _NSNumberCompare([self longLongValue], [other longLongValue]);
        } else if (selfUnsigned && !otherUnsigned) {
            return _NSNumberCompareUnsignedSigned([self unsignedLongLongValue], [other longLongValue]);
        } else {
            return -_NSNumberCompareUnsignedSigned([other unsignedLongLongValue], [self longLongValue]);
        }
    }
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
- (BOOL)boolValue {
    return _val.getRawValueAs<BOOL>(_objCType);
}

/**
 @Status Interoperable
*/
- (char)charValue {
    return _val.getRawValueAs<char>(_objCType);
}

/**
 @Status Interoperable
*/
- (double)doubleValue {
    return _val.getRawValueAs<double>(_objCType);
}

/**
 @Status Interoperable
*/
- (float)floatValue {
    return _val.getRawValueAs<float>(_objCType);
}

/**
 @Status Interoperable
*/
- (int)intValue {
    return _val.getRawValueAs<int>(_objCType);
}

/**
 @Status Interoperable
*/
- (NSInteger)integerValue {
    return _val.getRawValueAs<NSInteger>(_objCType);
}

/**
 @Status Interoperable
*/
- (long)longValue {
    return _val.getRawValueAs<long>(_objCType);
}

/**
 @Status Interoperable
*/
- (long long)longLongValue {
    return _val.getRawValueAs<long long>(_objCType);
}

/**
 @Status Interoperable
*/
- (short)shortValue {
    return _val.getRawValueAs<short>(_objCType);
}

/**
 @Status Interoperable
*/
- (unsigned char)unsignedCharValue {
    return _val.getRawValueAs<unsigned char>(_objCType);
}

/**
 @Status Interoperable
*/
- (unsigned int)unsignedIntValue {
    return _val.getRawValueAs<unsigned int>(_objCType);
}

/**
 @Status Interoperable
*/
- (NSUInteger)unsignedIntegerValue {
    return _val.getRawValueAs<NSUInteger>(_objCType);
}

/**
 @Status Interoperable
*/
- (unsigned long)unsignedLongValue {
    return _val.getRawValueAs<unsigned long>(_objCType);
}

/**
 @Status Interoperable
*/
- (unsigned long long)unsignedLongLongValue {
    return _val.getRawValueAs<unsigned long long>(_objCType);
}

/**
 @Status Interoperable
*/
- (unsigned short)unsignedShortValue {
    return _val.getRawValueAs<unsigned short>(_objCType);
}

// Used for CFType
- (BOOL)_isBool {
    return _isBool;
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
- (NSString*)stringValue {
    switch (_objCType[0]) {
        case 'c':
            // TODO: 6546983 ideally using "%hhd", so we can get rid of (short) cast
            // but it was not supported, so we cast the value to char and then short
            // and then format the value using short
            return [NSString stringWithFormat:@"%hd", static_cast<short>(_val.getRawValue<char>())];
        case 'd':
            return [NSString stringWithFormat:@"%0.16g", _val.getRawValue<double>()];
        case 'f':
            return [NSString stringWithFormat:@"%0.7g", _val.getRawValue<float>()];
        case 'i':
            return [NSString stringWithFormat:@"%d", _val.getRawValue<int>()];
        case 'l':
            return [NSString stringWithFormat:@"%ld", _val.getRawValue<long>()];
        case 'q':
            return [NSString stringWithFormat:@"%lld", _val.getRawValue<long long>()];
        case 's':
            return [NSString stringWithFormat:@"%hd", _val.getRawValue<short>()];
        case 'C':
            // TODO: 6546983 ideally using "%hhu", so we can get rid of (unsigned short) cast
            // but it was not supported, so we cast the value to char and then usinged short
            // and then format the value using unsigned short
            return [NSString stringWithFormat:@"%hu", static_cast<short>(_val.getRawValue<unsigned char>())];
        case 'I':
            return [NSString stringWithFormat:@"%u", _val.getRawValue<unsigned int>()];
        case 'L':
            return [NSString stringWithFormat:@"%lu", _val.getRawValue<unsigned long>()];
        case 'Q':
            return [NSString stringWithFormat:@"%llu", _val.getRawValue<unsigned long long>()];
        case 'S':
            return [NSString stringWithFormat:@"%hu", _val.getRawValue<unsigned short>()];
        default:
            assert(0);
            return nil;
    }
}

/**
 @Status Interoperable
*/
- (const char*)objCType {
    return _objCType;
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
- (NSUInteger)hash {
    return [self unsignedIntegerValue];
}

/**
 @Status Interoperable
*/
- (void)getValue:(void*)dest {
    switch (_objCType[0]) {
        case 'c':
            *(char*)dest = _val.getRawValue<char>();
            break;
        case 'd':
            *(double*)dest = _val.getRawValue<double>();
            break;
        case 'f':
            *(float*)dest = _val.getRawValue<float>();
            break;
        case 'i':
            *(int*)dest = _val.getRawValue<int>();
            break;
        case 'l':
            *(long*)dest = _val.getRawValue<long>();
            break;
        case 'q':
            *(long long*)dest = _val.getRawValue<long long>();
            break;
        case 's':
            *(short*)dest = _val.getRawValue<short>();
            break;
        case 'C':
            *(unsigned char*)dest = _val.getRawValue<unsigned char>();
            break;
        case 'I':
            *(unsigned int*)dest = _val.getRawValue<unsigned int>();
            break;
        case 'L':
            *(unsigned long*)dest = _val.getRawValue<unsigned long>();
            break;
        case 'Q':
            *(unsigned long long*)dest = _val.getRawValue<unsigned long long>();
            break;
        case 'S':
            *(unsigned short*)dest = _val.getRawValue<unsigned short>();
            break;
        default:
            assert(0);
            break;
    }
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
