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
#import "StubReturn.h"
#include <Foundation/Foundation.h>

NSString* const NSDecimalNumberExactnessException = @"NSDecimalNumberExactnessException";
NSString* const NSDecimalNumberOverflowException = @"NSDecimalNumberOverflowException";
NSString* const NSDecimalNumberUnderflowException = @"NSDecimalNumberUnderflowException";
NSString* const NSDecimalNumberDivideByZeroException = @"NSDecimalNumberDivideByZeroException";

/**
 @Status Stub
 @Notes
*/
NSCalculationError NSDecimalAdd(NSDecimal* result,
                                const NSDecimal* leftOperand,
                                const NSDecimal* rightOperand,
                                NSRoundingMode roundingMode) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void NSDecimalCompact(NSDecimal* number) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
NSComparisonResult NSDecimalCompare(const NSDecimal* leftOperand, const NSDecimal* rightOperand) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void NSDecimalCopy(NSDecimal* destination, const NSDecimal* source) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
NSCalculationError NSDecimalDivide(NSDecimal* result,
                                   const NSDecimal* leftOperand,
                                   const NSDecimal* rightOperand,
                                   NSRoundingMode roundingMode) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
BOOL NSDecimalIsNotANumber(const NSDecimal* dcm) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
NSCalculationError NSDecimalMultiply(NSDecimal* result,
                                     const NSDecimal* leftOperand,
                                     const NSDecimal* rightOperand,
                                     NSRoundingMode roundingMode) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
NSCalculationError NSDecimalMultiplyByPowerOf10(NSDecimal* result, const NSDecimal* number, short power, NSRoundingMode roundingMode) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
NSCalculationError NSDecimalNormalize(NSDecimal* number1, NSDecimal* number2, NSRoundingMode roundingMode) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
NSCalculationError NSDecimalPower(NSDecimal* result, const NSDecimal* number, NSUInteger power, NSRoundingMode roundingMode) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void NSDecimalRound(NSDecimal* result, const NSDecimal* number, NSInteger scale, NSRoundingMode roundingMode) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
NSString* NSDecimalString(const NSDecimal* dcm, id locale) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
NSCalculationError NSDecimalSubtract(NSDecimal* result,
                                     const NSDecimal* leftOperand,
                                     const NSDecimal* rightOperand,
                                     NSRoundingMode roundingMode) {
    UNIMPLEMENTED();
    return StubReturn();
}

@implementation NSDecimalNumber

/**
 @Status Caveat
 @Notes does not support locale using ',', does not support exponents
*/
+ (NSDecimalNumber*)decimalNumberWithString:(NSString*)str {
    const char* pStr = [str UTF8String];
    if (strstr(pStr, ".") != NULL) {
        double fVal = strtod(pStr, NULL);
        return [[self alloc] initWithDouble:fVal];
    } else {
        int64_t val = _strtoi64(pStr, NULL, 10);
        return [[self alloc] initWithLongLong:val];
    }
}

/**
 @Status Interoperable
*/
- (const char*)objCType {
    return "d";
}

/**
 @Status Stub
 @Notes
*/
+ (NSDecimalNumber*)decimalNumberWithDecimal:(NSDecimal)decimal {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSDecimalNumber*)decimalNumberWithMantissa:(unsigned long long)mantissa exponent:(short)exponent isNegative:(BOOL)isNegative {
    UNIMPLEMENTED();
    return StubReturn();
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
 @Status Stub
 @Notes
*/
+ (NSDecimalNumber*)one {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSDecimalNumber*)zero {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSDecimalNumber*)notANumber {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithDecimal:(NSDecimal)decimal {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithMantissa:(unsigned long long)mantissa exponent:(short)exponent isNegative:(BOOL)flag {
    UNIMPLEMENTED();
    return StubReturn();
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
 @Status Stub
 @Notes
*/
- (NSDecimalNumber*)decimalNumberByAdding:(NSDecimalNumber*)decimalNumber {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSDecimalNumber*)decimalNumberBySubtracting:(NSDecimalNumber*)decimalNumber {
    UNIMPLEMENTED();
    return StubReturn();
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
- (NSDecimalNumber*)decimalNumberByAdding:(NSDecimalNumber*)decimalNumber withBehavior:(id<NSDecimalNumberBehaviors>)behavior {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSDecimalNumber*)decimalNumberBySubtracting:(NSDecimalNumber*)decimalNumber withBehavior:(id<NSDecimalNumberBehaviors>)behavior {
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
+ (id<NSDecimalNumberBehaviors>)defaultBehavior {
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
 @Status Stub
 @Notes
*/
- (NSComparisonResult)compare:(NSNumber*)decimalNumber {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSDecimalNumber*)maximumDecimalNumber {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSDecimalNumber*)minimumDecimalNumber {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
