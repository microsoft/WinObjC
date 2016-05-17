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
#import "BridgeHelpers.h"
#import "CFHelpers.h"
#import "CFFoundationInternal.h"
#import "NSCFNumber.h"
#import "NSNumberInternal.h"
#import <CoreFoundation/CFNumber.h>

// Matches private struct in CFNumber
typedef struct {
    int64_t high;
    uint64_t low;
} CFSInt128Struct;

// Matches private CFNumberType value in CFNumber
enum { kCFNumberSInt128Type = 17 };

@implementation NSNumberPrototype

PROTOTYPE_CLASS_REQUIRED_IMPLS

// Helper macro for NSNumberPrototype initializers (signed)
// Var args are the signature of the initializer
#define NS_NUMBER_INIT_IMPL(cfNumberType, ...)                                                                                        \
    (instancetype) __VA_ARGS__ num {                                                                                                  \
        return reinterpret_cast<NSNumberPrototype*>(static_cast<NSNumber*>(CFNumberCreate(kCFAllocatorDefault, cfNumberType, &num))); \
    }

- NS_NUMBER_INIT_IMPL(kCFNumberCharType, initWithChar:(char));
- NS_NUMBER_INIT_IMPL(kCFNumberDoubleType, initWithDouble:(double));
- NS_NUMBER_INIT_IMPL(kCFNumberFloatType, initWithFloat:(float));
- NS_NUMBER_INIT_IMPL(kCFNumberIntType, initWithInt:(int));
- NS_NUMBER_INIT_IMPL(kCFNumberNSIntegerType, initWithInteger:(NSInteger));
- NS_NUMBER_INIT_IMPL(kCFNumberLongType, initWithLong:(long));
- NS_NUMBER_INIT_IMPL(kCFNumberLongLongType, initWithLongLong:(long long));
- NS_NUMBER_INIT_IMPL(kCFNumberShortType, initWithShort:(short));

// Helper macro for NSNumberPrototype initializers (unsigned)
// Var args are the signature of the initializer
// Unsigned requires an extra step of init, as CFNumber does not actually support unsigned types,
// instead storing in a signed value of twice the size
// Get around this by casting to an intermediate value
#define NS_NUMBER_INIT_UNSIGNED_IMPL(cfNumberType, intermediateType, ...)                           \
    (instancetype) __VA_ARGS__ num {                                                                \
        intermediateType castedNum = static_cast<intermediateType>(num);                            \
        return reinterpret_cast<NSNumberPrototype*>(                                                \
            static_cast<NSNumber*>(CFNumberCreate(kCFAllocatorDefault, cfNumberType, &castedNum))); \
    }

- NS_NUMBER_INIT_UNSIGNED_IMPL(kCFNumberSInt16Type, int16_t, initWithUnsignedChar:(unsigned char));
- NS_NUMBER_INIT_UNSIGNED_IMPL(kCFNumberSInt64Type, int64_t, initWithUnsignedInt:(unsigned int));
- NS_NUMBER_INIT_UNSIGNED_IMPL(kCFNumberSInt64Type, int64_t, initWithUnsignedInteger:(NSUInteger));
- NS_NUMBER_INIT_UNSIGNED_IMPL(kCFNumberSInt64Type, int64_t, initWithUnsignedLong:(unsigned long));
- NS_NUMBER_INIT_UNSIGNED_IMPL(kCFNumberSInt32Type, int32_t, initWithUnsignedShort:(unsigned short));

// Unsigned long long requires unique handling due to its 128-bit struct
- (instancetype)initWithUnsignedLongLong:(unsigned long long)num {
    CFSInt128Struct castedNum{};
    castedNum.low = num;
    return reinterpret_cast<NSNumberPrototype*>(
        static_cast<NSNumber*>(CFNumberCreate(kCFAllocatorDefault, static_cast<CFNumberType>(kCFNumberSInt128Type), &castedNum)));
}

// For bool, return the extant constants
- (instancetype)initWithBool:(BOOL)value {
    return reinterpret_cast<NSNumberPrototype*>(static_cast<NSNumber*>(value ? kCFBooleanTrue : kCFBooleanFalse));
}

@end