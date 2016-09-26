//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import <Starboard.h>
#import <StubReturn.h>
#import <Foundation/Foundation.h>
#import <Foundation/NSDecimal.h>
#import <Foundation/NSDecimalNumberHandler.h>
#import <vector>
#import <algorithm>
#import <limits>

NSString* const NSDecimalNumberExactnessException = @"NSDecimalNumberExactnessException";
NSString* const NSDecimalNumberOverflowException = @"NSDecimalNumberOverflowException";
NSString* const NSDecimalNumberUnderflowException = @"NSDecimalNumberUnderflowException";
NSString* const NSDecimalNumberDivideByZeroException = @"NSDecimalNumberDivideByZeroException";

typedef NS_ENUM(NSInteger, _DecimalOperations) { _Addition, _Subtraction, _Multiplication, _Division };
const int _MAX_EXP = 127;

static NSDecimalNumber* s_zero;
static NSDecimalNumber* s_one;
static NSDecimalNumber* s_notANumber;
static NSDecimalNumber* s_maxNumber;
static NSDecimalNumber* s_minNumber;

@implementation NSDecimalNumber {
    NSDecimal _decimal;
}

/**
 @Status Stub
 @Notes
*/
+ (NSDecimalNumber*)decimalNumberWithString:(NSString*)str {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (const char*)objCType {
    return "d";
}

/**
 @Status Interoperable
*/
+ (id<NSDecimalNumberBehaviors>)defaultBehavior {
    return [NSDecimalNumberHandler defaultDecimalNumberHandler];
}

/**
 @Status Interoperable
*/
+ (NSDecimalNumber*)one {
    static dispatch_once_t __oneOnce;
    dispatch_once(&__oneOnce, ^{
        s_one = [[NSDecimalNumber alloc] initWithMantissa:1 exponent:0 isNegative:NO];
    });
    return s_one;
}

/**
 @Status Interoperable
*/
+ (NSDecimalNumber*)zero {
    static dispatch_once_t __zeroOnce;
    dispatch_once(&__zeroOnce, ^{
        s_zero = [[NSDecimalNumber alloc] initWithMantissa:0 exponent:0 isNegative:NO];
    });
    return s_zero;
}

/**
 @Status Interoperable
*/
+ (NSDecimalNumber*)notANumber {
    static dispatch_once_t __notANumberOnce;
    dispatch_once(&__notANumberOnce, ^{
        s_notANumber = [[NSDecimalNumber alloc] initWithMantissa:0 exponent:0 isNegative:YES];
    });
    return s_notANumber;
}

/**
 @Status Interoperable
*/
+ (NSDecimalNumber*)maximumDecimalNumber {
    static dispatch_once_t __maxNumberOnce;
    dispatch_once(&__maxNumberOnce, ^{
        s_maxNumber =
            [[NSDecimalNumber alloc] initWithMantissa:std::numeric_limits<unsigned long long>::max() exponent:_MAX_EXP isNegative:NO];
    });
    return s_maxNumber;
}

/**
 @Status Interoperable
*/
+ (NSDecimalNumber*)minimumDecimalNumber {
    static dispatch_once_t __minNumberOnce;
    dispatch_once(&__minNumberOnce, ^{
        s_minNumber =
            [[NSDecimalNumber alloc] initWithMantissa:std::numeric_limits<unsigned long long>::max() exponent:_MAX_EXP isNegative:YES];
    });
    return s_minNumber;
}

/**
 @Status Interoperable
*/
+ (NSDecimalNumber*)decimalNumberWithDecimal:(NSDecimal)decimal {
    return [[[NSDecimalNumber alloc] initWithDecimal:decimal] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSDecimalNumber*)decimalNumberWithMantissa:(unsigned long long)mantissa exponent:(short)exponent isNegative:(BOOL)isNegative {
    return [[[NSDecimalNumber alloc] initWithMantissa:mantissa exponent:exponent isNegative:isNegative] autorelease];
}

/**
 @Status Stub
 @Notes
*/
+ (NSDecimalNumber*)decimalNumberWithString:(NSString*)numericString locale:(id)locale {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (NSNumber*)initWithBool:(BOOL)value {
    return [self initWithLongLong:static_cast<long long>(value)];
}

/**
 @Status Interoperable
*/
- (NSNumber*)initWithChar:(char)value {
    return [self initWithLongLong:static_cast<long long>(value)];
}

/**
 @Status Interoperable
*/
- (NSNumber*)initWithDouble:(double)value {
    int exp = 0;
    double res = value;
    if (res < 0) {
        res *= -1;
    }

    if (res == DBL_MIN) {
        return [self initWithMantissa:0 exponent:0 isNegative:0];
    }

    if (res > 1.8e146) {
        return [self initWithMantissa:ULLONG_MAX exponent:0x7f isNegative:(value < 0)];
    }
    // Attempt best for smaller numbers (this is being compacted via NSDecimalCompact in initWithMantissa)
    while ((res != 0) && (res < static_cast<double>(ULLONG_MAX))) {
        res *= 10;
        exp--;
    }

    while (res > static_cast<double>(ULLONG_MAX)) {
        res /= 10.0;
        exp++;
    }

    return [self initWithMantissa:static_cast<unsigned long long>(res) exponent:exp isNegative:(value < 0.0)];
}

/**
 @Status Interoperable
*/
- (NSNumber*)initWithFloat:(float)value {
    return [self initWithDouble:static_cast<double>(value)];
}

/**
 @Status Interoperable
*/
- (NSNumber*)initWithInt:(int)value {
    return [self initWithLongLong:static_cast<long long>(value)];
}

/**
 @Status Interoperable
*/
- (NSNumber*)initWithInteger:(NSInteger)value {
    return [self initWithLongLong:static_cast<long long>(value)];
}

/**
 @Status Interoperable
*/
- (NSNumber*)initWithLong:(long)value {
    return [self initWithLongLong:static_cast<long long>(value)];
}

/**
 @Status Interoperable
*/
- (NSNumber*)initWithShort:(short)value {
    return [self initWithLongLong:static_cast<long long>(value)];
}

/**
 @Status Interoperable
*/
- (NSNumber*)initWithUnsignedChar:(unsigned char)value {
    return [self initWithUnsignedLongLong:static_cast<unsigned long long>(value)];
}

/**
 @Status Interoperable
*/
- (NSNumber*)initWithUnsignedInt:(unsigned int)value {
    return [self initWithUnsignedLongLong:static_cast<unsigned long long>(value)];
}

/**
 @Status Interoperable
*/
- (NSNumber*)initWithUnsignedInteger:(NSUInteger)value {
    return [self initWithUnsignedLongLong:static_cast<unsigned long long>(value)];
}

/**
 @Status Interoperable
*/
- (NSNumber*)initWithUnsignedLong:(unsigned long)value {
    return [self initWithUnsignedLongLong:static_cast<unsigned long long>(value)];
}

/**
 @Status Interoperable
*/
- (NSNumber*)initWithUnsignedShort:(unsigned short)value {
    return [self initWithUnsignedLongLong:static_cast<unsigned long long>(value)];
}

/**
 @Status Interoperable
*/
- (NSNumber*)initWithUnsignedLongLong:(unsigned long long)value {
    return [self initWithMantissa:value exponent:0 isNegative:NO];
}

/**
 @Status Interoperable
*/
- (NSNumber*)initWithLongLong:(long long)value {
    long long val = value;
    if (val < 0) {
        val *= -1;
    }
    return [self initWithMantissa:val exponent:0 isNegative:(value < 0)];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithDecimal:(NSDecimal)decimal {
    if (self = [super init]) {
        _decimal = { 0 };
        NSDecimalCopy(&_decimal, &decimal);
        NSDecimalCompact(&_decimal);
    }

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithMantissa:(unsigned long long)mantissa exponent:(short)exponent isNegative:(BOOL)flag {
    NSDecimal decimal = { 0 };
    decimal._exponent = exponent;
    decimal._isNegative = flag;

    // copy over the 8 byte value.
    memcpy(&(decimal._mantissa), &mantissa, sizeof(unsigned long long));

    for (int index = NSDecimalMaxSize - 1; index >= 0; --index) {
        if (decimal._mantissa[index] != 0) {
            decimal._length = index + 1;
            break;
        }
    }

    return [self initWithDecimal:decimal];
}

/**
 @Status Interoperable
*/
- (BOOL)isEqual:(NSObject*)objAddr {
    if ([objAddr isKindOfClass:[NSNumber class]]) {
        return [self isEqualToNumber:static_cast<NSDecimalNumber*>(objAddr)];
    }
    return NO;
}

/**
 @Status Interoperable
*/
- (BOOL)isEqualToNumber:(NSNumber*)objAddr {
    return [self compare:objAddr] == NSOrderedSame;
}

/**
 @Status Interoperable
*/
- (NSComparisonResult)compare:(NSNumber*)decimalNumber {
    NSDecimal a = [self decimalValue];
    NSDecimal b = [decimalNumber decimalValue];
    return NSDecimalCompare(&a, &b);
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithString:(NSString*)numericString {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithString:(NSString*)numericString locale:(id)locale {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (NSDecimal)decimalValue {
    // Read-Only
    NSDecimal decimal = { 0 };
    NSDecimalCopy(&decimal, &_decimal);
    return decimal;
}

- (NSDecimalNumber*)_decimalOperation:(_DecimalOperations)operand
                        decimalNumber:(NSDecimalNumber*)decimalNumber
                         withBehavior:(id<NSDecimalNumberBehaviors>)behavior {
    RETURN_NULL_IF(!decimalNumber);

    NSDecimal a = [self decimalValue];
    NSDecimal b = [decimalNumber decimalValue];

    NSDecimal result;
    NSCalculationError error = NSCalculationNoError;

    switch (operand) {
        case _Addition:
            error = NSDecimalAdd(&result, &a, &b, [behavior roundingMode]);
            break;
        case _Subtraction:
            error = NSDecimalSubtract(&result, &a, &b, [behavior roundingMode]);
            break;
        // case _Multiplication:
        //    error = NSDecimalMultiply(&result, &a, &b, [behavior roundingMode]);
        //   break;
        //  case _Division:
        //  error = NSDecimalDivide(&result, &a, &b, [behavior roundingMode]);
        // break;
        default:
            return nil;
    }

    if (error != NSCalculationNoError) {
        return [behavior exceptionDuringOperation:_cmd error:error leftOperand:self rightOperand:decimalNumber];
    }

    // TODO: Implement NSDecimalRound
    // NSDecimalRound(&result, &result, [behavior scale], [behavior roundingMode]);
    return [NSDecimalNumber decimalNumberWithDecimal:result];
}

/**
 @Status Caveat
 @Notes NSDecimalNumberBehaviors roundingMode is not supported.
*/
- (NSDecimalNumber*)decimalNumberByAdding:(NSDecimalNumber*)decimalNumber withBehavior:(id<NSDecimalNumberBehaviors>)behavior {
    return [self _decimalOperation:_Addition decimalNumber:decimalNumber withBehavior:behavior];
}

/**
 @Status Caveat
 @Notes NSDecimalNumberBehaviors roundingMode is not supported.
*/
- (NSDecimalNumber*)decimalNumberByAdding:(NSDecimalNumber*)decimalNumber {
    return [self decimalNumberByAdding:decimalNumber withBehavior:[NSDecimalNumber defaultBehavior]];
}

/**
 @Status Caveat
 @Notes NSDecimalNumberBehaviors roundingMode is not supported.
*/
- (NSDecimalNumber*)decimalNumberBySubtracting:(NSDecimalNumber*)decimalNumber withBehavior:(id<NSDecimalNumberBehaviors>)behavior {
    return [self _decimalOperation:_Subtraction decimalNumber:decimalNumber withBehavior:behavior];
}

/**
 @Status Caveat
 @Notes NSDecimalNumberBehaviors roundingMode is not supported.
*/
- (NSDecimalNumber*)decimalNumberBySubtracting:(NSDecimalNumber*)decimalNumber {
    return [self decimalNumberBySubtracting:decimalNumber withBehavior:[NSDecimalNumber defaultBehavior]];
}

/**
 @Status Stub
 @Notes
*/
- (NSDecimalNumber*)decimalNumberByMultiplyingBy:(NSDecimalNumber*)decimalNumber {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSDecimalNumber*)decimalNumberByDividingBy:(NSDecimalNumber*)decimalNumber {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSDecimalNumber*)decimalNumberByRaisingToPower:(NSUInteger)power {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSDecimalNumber*)decimalNumberByMultiplyingByPowerOf10:(short)power {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSDecimalNumber*)decimalNumberByMultiplyingBy:(NSDecimalNumber*)decimalNumber withBehavior:(id<NSDecimalNumberBehaviors>)behavior {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSDecimalNumber*)decimalNumberByDividingBy:(NSDecimalNumber*)decimalNumber withBehavior:(id<NSDecimalNumberBehaviors>)behavior {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSDecimalNumber*)decimalNumberByRaisingToPower:(NSUInteger)power withBehavior:(id<NSDecimalNumberBehaviors>)behavior {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSDecimalNumber*)decimalNumberByMultiplyingByPowerOf10:(short)power withBehavior:(id<NSDecimalNumberBehaviors>)behavior {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSDecimalNumber*)decimalNumberByRoundingAccordingToBehavior:(id<NSDecimalNumberBehaviors>)behavior {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSString*)descriptionWithLocale:(id)locale {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (void)setDefaultBehavior:(id<NSDecimalNumberBehaviors>)behavior {
    UNIMPLEMENTED();
}

@end
