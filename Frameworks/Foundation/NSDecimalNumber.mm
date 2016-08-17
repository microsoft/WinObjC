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

typedef NS_ENUM(NSInteger, _DecimalOperand) { _Addition, _Subtract, _Multiply, _Divide };

static NSDecimalNumber* _zero;
static NSDecimalNumber* _one;
static NSDecimalNumber* _notANumber;
static NSDecimalNumber* _maxNumber;
static NSDecimalNumber* _minNumber;

@implementation NSDecimalNumber {
    NSDecimal* _decimal;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    delete _decimal;
    [super dealloc];
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
        _one = [[NSDecimalNumber alloc] initWithMantissa:1 exponent:0 isNegative:NO];
    });
    return _one;
}

/**
 @Status Interoperable
*/
+ (NSDecimalNumber*)zero {
    static dispatch_once_t __zeroOnce;
    dispatch_once(&__zeroOnce, ^{
        _zero = [[NSDecimalNumber alloc] initWithMantissa:0 exponent:0 isNegative:NO];
    });
    return _zero;
}

/**
 @Status Interoperable
*/
+ (NSDecimalNumber*)notANumber {
    static dispatch_once_t __notANumberOnce;
    dispatch_once(&__notANumberOnce, ^{
        NSDecimal decimal = { 0 };
        decimal._reserved = 1;
        _notANumber = [[NSDecimalNumber alloc] initWithDecimal:decimal];
    });
    return _notANumber;
}

/**
 @Status Interoperable
*/
+ (NSDecimalNumber*)maximumDecimalNumber {
    static dispatch_once_t __maxNumberOnce;
    dispatch_once(&__maxNumberOnce, ^{
        _maxNumber = [[NSDecimalNumber alloc] initWithMantissa:std::numeric_limits<unsigned long long>::max() exponent:127 isNegative:NO];
    });
    return _maxNumber;
}

/**
 @Status Interoperable
*/
+ (NSDecimalNumber*)minimumDecimalNumber {
    static dispatch_once_t __minNumberOnce;
    dispatch_once(&__minNumberOnce, ^{
        _minNumber = [[NSDecimalNumber alloc] initWithMantissa:std::numeric_limits<unsigned long long>::min() exponent:127 isNegative:YES];
    });
    return _minNumber;
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
- (instancetype)initWithDecimal:(NSDecimal)decimal {
    if (self = [super init]) {
        _decimal = new NSDecimal{ 0 };
        NSDecimal* foo = new NSDecimal{ 0 };
        if (_decimal == NULL) {
            [self release];
            return nil;
        }
        NSDecimalCopy(_decimal, &decimal);
        NSDecimalCompact(_decimal);
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

    std::vector<unsigned short> digits;
    // We need to set the mantissa
    while (mantissa > 0) {
        digits.push_back(mantissa % 10);
        mantissa = mantissa / 10;
    }

    // re-order
    std::reverse(digits.begin(), digits.end());

    decimal._length = digits.size();
    if (decimal._length != 0) {
        memcpy(decimal._mantissa, &digits[0], decimal._length * sizeof(unsigned short));
    }
    return [self initWithDecimal:decimal];
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
    NSDecimalCopy(&decimal, _decimal);
    return decimal;
}

/**
 @Status Interoperable
*/
- (BOOL)isEqual:(NSObject*)objAddr {
    if ([objAddr isKindOfClass:[NSDecimalNumber class]]) {
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

- (NSDecimalNumber*)_decimalOperation:(_DecimalOperand)operand
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
        case _Subtract:
            error = NSDecimalSubtract(&result, &a, &b, [behavior roundingMode]);
            break;
        case _Multiply:
            error = NSDecimalMultiply(&result, &a, &b, [behavior roundingMode]);
            break;
        case _Divide:
            error = NSDecimalDivide(&result, &a, &b, [behavior roundingMode]);
            break;
        default:
            return nil;
    }

    if (error != NSCalculationNoError) {
        return [behavior exceptionDuringOperation:_cmd error:error leftOperand:self rightOperand:decimalNumber];
    }

    NSDecimalRound(&result, &result, [behavior scale], [behavior roundingMode]);
    return [NSDecimalNumber decimalNumberWithDecimal:result];
}

/**
 @Status Interoperable
*/
- (NSDecimalNumber*)decimalNumberByAdding:(NSDecimalNumber*)decimalNumber withBehavior:(id<NSDecimalNumberBehaviors>)behavior {
    return [self _decimalOperation:_Addition decimalNumber:decimalNumber withBehavior:behavior];
}

/**
 @Status Interoperable
*/
- (NSDecimalNumber*)decimalNumberByAdding:(NSDecimalNumber*)decimalNumber {
    return [self decimalNumberByAdding:decimalNumber withBehavior:[NSDecimalNumber defaultBehavior]];
}

/**
 @Status Interoperable
*/
- (NSDecimalNumber*)decimalNumberBySubtracting:(NSDecimalNumber*)decimalNumber withBehavior:(id<NSDecimalNumberBehaviors>)behavior {
    return [self _decimalOperation:_Subtract decimalNumber:decimalNumber withBehavior:behavior];
}

/**
 @Status Interoperable
*/
- (NSDecimalNumber*)decimalNumberBySubtracting:(NSDecimalNumber*)decimalNumber {
    return [self decimalNumberBySubtracting:decimalNumber withBehavior:[NSDecimalNumber defaultBehavior]];
}

/**
 @Status Interoperable
*/
- (NSDecimalNumber*)decimalNumberByMultiplyingBy:(NSDecimalNumber*)decimalNumber withBehavior:(id<NSDecimalNumberBehaviors>)behavior {
    return [self _decimalOperation:_Multiply decimalNumber:decimalNumber withBehavior:behavior];
}

/**
 @Status Interoperable
*/
- (NSDecimalNumber*)decimalNumberByMultiplyingBy:(NSDecimalNumber*)decimalNumber {
    return [self decimalNumberByMultiplyingBy:decimalNumber withBehavior:[NSDecimalNumber defaultBehavior]];
}

/**
 @Status Interoperable
*/
- (NSDecimalNumber*)decimalNumberByDividingBy:(NSDecimalNumber*)decimalNumber withBehavior:(id<NSDecimalNumberBehaviors>)behavior {
    return [self _decimalOperation:_Divide decimalNumber:decimalNumber withBehavior:behavior];
}

/**
 @Status Interoperable
*/
- (NSDecimalNumber*)decimalNumberByDividingBy:(NSDecimalNumber*)decimalNumber {
    return [self decimalNumberByDividingBy:decimalNumber withBehavior:[NSDecimalNumber defaultBehavior]];
}

/**
 @Status Interoperable
*/
- (NSDecimalNumber*)decimalNumberByRaisingToPower:(NSUInteger)power withBehavior:(id<NSDecimalNumberBehaviors>)behavior {
    NSDecimal result;
    NSCalculationError error = NSCalculationNoError;
    NSDecimal dValue = [self decimalValue];
    error = NSDecimalPower(&result, &dValue, power, [behavior roundingMode]);

    if (error != NSCalculationNoError) {
        return [behavior exceptionDuringOperation:_cmd error:error leftOperand:self rightOperand:nil];
    }

    return [NSDecimalNumber decimalNumberWithDecimal:result];
}

/**
 @Status Interoperable
*/
- (NSDecimalNumber*)decimalNumberByRaisingToPower:(NSUInteger)power {
    return [self decimalNumberByRaisingToPower:power withBehavior:[NSDecimalNumber defaultBehavior]];
}

/**
 @Status Interoperable
*/
- (NSDecimalNumber*)decimalNumberByMultiplyingByPowerOf10:(short)power withBehavior:(id<NSDecimalNumberBehaviors>)behavior {
    NSDecimal result;
    NSCalculationError error = NSCalculationNoError;
    NSDecimal dValue = [self decimalValue];
    error = NSDecimalMultiplyByPowerOf10(&result, &dValue, power, [behavior roundingMode]);

    if (error != NSCalculationNoError) {
        return [behavior exceptionDuringOperation:_cmd error:error leftOperand:self rightOperand:nil];
    }

    return [NSDecimalNumber decimalNumberWithDecimal:result];
}

/**
 @Status Interoperable
*/
- (NSDecimalNumber*)decimalNumberByMultiplyingByPowerOf10:(short)power {
    return [self decimalNumberByMultiplyingByPowerOf10:power withBehavior:[NSDecimalNumber defaultBehavior]];
}

/**
 @Status Interoperable
*/
- (NSDecimalNumber*)decimalNumberByRoundingAccordingToBehavior:(id<NSDecimalNumberBehaviors>)behavior {
    NSDecimal result;
    NSDecimal dValue = [self decimalValue];
    NSDecimalRound(&result, &dValue, [behavior scale], [behavior roundingMode]);
    return [NSDecimalNumber decimalNumberWithDecimal:result];
}

/**
 @Status Interoperable
*/
- (double)doubleValue {
    double result = 0.0;

    if (NSDecimalIsNotANumber(_decimal)) {
        return NAN;
    }

    for (int index = 0; index < _decimal->_length; ++index) {
        result = result * 10;
        result += _decimal->_mantissa[index];
    }

    if (_decimal->_exponent >= 0) {
        for (int i = 0; i < _decimal->_exponent; i++) {
            result *= 10.0;
        }
    } else {
        for (int i = _decimal->_exponent; i < 0; ++i) {
            result /= 10.0;
        }
    }

    return _decimal->_isNegative ? -result : result;
}

/**
 @Status Interoperable
*/
- (BOOL)boolValue {
    return [self doubleValue] != 0.0;
}

/**
 @Status Interoperable
*/
- (char)charValue {
    return static_cast<char>([self doubleValue]);
}

/**
 @Status Interoperable
*/
- (float)floatValue {
    return static_cast<float>([self doubleValue]);
}

/**
 @Status Interoperable
*/
- (int)intValue {
    return static_cast<int>([self doubleValue]);
}

/**
 @Status Interoperable
*/
- (long)longValue {
    return static_cast<long>([self doubleValue]);
}

/**
 @Status Interoperable
*/
- (long long)longLongValue {
    return static_cast<long long>([self doubleValue]);
}

/**
 @Status Interoperable
*/
- (short)shortValue {
    return static_cast<short>([self doubleValue]);
}

/**
 @Status Interoperable
*/
- (unsigned char)unsignedCharValue {
    return static_cast<unsigned char>([self doubleValue]);
}

/**
 @Status Interoperable
*/
- (unsigned int)unsignedIntValue {
    return static_cast<unsigned int>([self doubleValue]);
}

/**
 @Status Interoperable
*/
- (NSUInteger)unsignedIntegerValue {
    return static_cast<NSUInteger>([self doubleValue]);
}

/**
 @Status Interoperable
*/
- (NSInteger)integerValue {
    return static_cast<NSInteger>([self doubleValue]);
}

/**
 @Status Interoperable
*/
- (unsigned long)unsignedLongValue {
    return static_cast<unsigned long>([self doubleValue]);
}

/**
 @Status Interoperable
*/
- (unsigned long long)unsignedLongLongValue {
    return static_cast<unsigned long long>([self doubleValue]);
}

/**
 @Status Interoperable
*/
- (unsigned short)unsignedShortValue {
    return static_cast<unsigned short>([self doubleValue]);
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

/**
 @Status Interoperable
*/
- (instancetype)initWithBool:(BOOL)num {
    return [self initWithMantissa:(num ? 1 : 0) exponent:0 isNegative:NO];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithChar:(char)num {
    return [self initWithMantissa:((num < 0) ? -num : num) exponent:0 isNegative:((num < 0) ? YES : NO)];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithDouble:(double)num {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithFloat:(float)num {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (instancetype)initWithInt:(int)num {
    return [self initWithMantissa:((num < 0) ? -num : num) exponent:0 isNegative:((num < 0) ? YES : NO)];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithInteger:(NSInteger)num {
    return [self initWithMantissa:((num < 0) ? -num : num) exponent:0 isNegative:((num < 0) ? YES : NO)];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithLong:(long)num {
    return [self initWithMantissa:((num < 0) ? -num : num) exponent:0 isNegative:((num < 0) ? YES : NO)];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithLongLong:(long long)num {
    return [self initWithMantissa:((num < 0) ? -num : num) exponent:0 isNegative:((num < 0) ? YES : NO)];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithShort:(short)num {
    return [self initWithMantissa:((num < 0) ? -num : num) exponent:0 isNegative:((num < 0) ? YES : NO)];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithUnsignedChar:(unsigned char)num {
    return [self initWithMantissa:num exponent:0 isNegative:NO];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithUnsignedInt:(unsigned int)num {
    return [self initWithMantissa:num exponent:0 isNegative:NO];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithUnsignedInteger:(NSUInteger)num {
    return [self initWithMantissa:num exponent:0 isNegative:NO];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithUnsignedLong:(unsigned long)num {
    return [self initWithMantissa:num exponent:0 isNegative:NO];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithUnsignedLongLong:(unsigned long long)num {
    return [self initWithMantissa:num exponent:0 isNegative:NO];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithUnsignedShort:(unsigned short)num {
    return [self initWithMantissa:num exponent:0 isNegative:NO];
}

@end
