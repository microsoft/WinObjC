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

#import <Foundation/NSDecimal.h>
#import <StubReturn.h>
#include <algorithm>

#define EXPONENT_MAX 127
#define EXPONENT_MIN -128

#define MANTISSA(decimal) decimal->_mantissa

#define LENGTH(decimal) decimal->_length

#define EXPONENT(decimal) decimal->_exponent

#define NEGATIVE_FLAG(decimal) decimal->_isNegative

#define SET_TO_ZERO(decimal) \
    LENGTH(decimal) = 0;     \
    EXPONENT(decimal) = 0;   \
    NEGATIVE_FLAG(decimal) = 0

#define IS_NEGATIVE(decimal) decimal->_isNegative

#define IS_POSITIVE(decimal) !IS_NEGATIVE(decimal)

#define IS_ZERO(decimal) (decimal->_length == 0) && IS_POSITIVE(decimal)

#define INVALIDATE_DECIMAL(decimal) decimal->_reserved = 1

#define VALIDATE_ARITHMETIC_INPUT(result, leftOperand, rightOperand)                \
    if (NSDecimalIsNotANumber(leftOperand) || NSDecimalIsNotANumber(leftOperand)) { \
        if (result) {                                                               \
            INVALIDATE_DECIMAL(result);                                             \
        }                                                                           \
        return NSCalculationNoError;                                                \
    }

#define CHECK_DIVIDE_BY0(decimal)                           \
    NSDecimal zero = { 0 };                                 \
    if (NSDecimalCompare(decimal, zero) == NSOrderedSame) { \
        return NSCalculationDivideByZero;                   \
    }

/**
 @Status Interoperable
*/
BOOL NSDecimalIsNotANumber(const NSDecimal* dcm) {
    THROW_NS_IF_FALSE(E_INVALIDARG, dcm != NULL);
    return (dcm->_reserved == 1);
}

/**
 @Status Stub
 @Notes
*/
NSString* NSDecimalString(const NSDecimal* dcm, id locale) {
    UNIMPLEMENTED();
    return StubReturn();
}

static NSCalculationError _addSameSign(NSDecimal* result, NSDecimal* x, NSDecimal* y) {
    // add starting at the end of the larger number.
    // Note: we will have different placements of digits, since the decimal would of been compacted.
    // We could ideally do a placement shifting to make the indexing much less complicated, but we would end up doing extra
    // mantissa normalization and then just end up recompacting it.
    NSDecimal* shortest;
    if (NSDecimalCompare(x, y) == NSOrderedDescending) {
        NSDecimalCopy(result, x);
        shortest = y;
    } else {
        NSDecimalCopy(result, y);
        shortest = x;
    }

    int carryOver = 0;
    int offset = (LENGTH(result) - LENGTH(shortest));
    for (int shortIndex = LENGTH(shortest) - 1; shortIndex >= 0; --shortIndex) {
        int temp = (MANTISSA(shortest)[shortIndex] + MANTISSA(result)[offset + shortIndex] + carryOver);
        MANTISSA(result)[offset + shortIndex] = temp % 10;
        carryOver = temp / 10;
    }

    if (!carryOver) {
        // we are done.
        return NSCalculationNoError;
    }

    // we have a carry over, start the propagation of the 1
    for (int index = offset - 1; index >= 0; --index) {
        if (MANTISSA(result)[index] != 9) {
            MANTISSA(result)[index] += 1;
            carryOver = 0;
            break;
        }

        MANTISSA(result)[index] = 0;
    }

    if (!carryOver) {
        // we are done.
        return NSCalculationNoError;
    }

    // If we still have a carry over, meaning we need to add one more place to the result and shift it.
    // We need to validate if we have enough space for the placement and shift.
    if (LENGTH(result) == NSDecimalMaxSize) {
        // we don't have any space left.
        INVALIDATE_DECIMAL(result);
        return NSCalculationLossOfPrecision;
    }

    // do the shiffting by one and append the carryover.
    memmove(&MANTISSA(result)[1], &MANTISSA(result)[0], sizeof(unsigned short) * LENGTH(result));
    MANTISSA(result)[0] = 1;

    return NSCalculationNoError;
}

static NSCalculationError _subtractValidRange(NSDecimal* result, NSDecimal* x, NSDecimal* y) {
    // Based on filtering in Subtract
    NSDecimalCopy(result, x);
    NSDecimal* shortest = y;

    int borrow = 0;
    int offset = (LENGTH(result) - LENGTH(shortest));

    for (int shortIndex = LENGTH(shortest) - 1; shortIndex >= 0; --shortIndex) {
        int temp = MANTISSA(result)[offset + shortIndex] - MANTISSA(shortest)[shortIndex] - borrow;
        // check for any borrow
        borrow = (temp < 0) ? 1 : 0;
        temp = (temp < 0) ? (temp + 10) : temp;
        MANTISSA(result)[offset + shortIndex] = temp;
    }

    if (!borrow) {
        return NSCalculationNoError;
    }

    for (int index = offset - 1; index >= 0; --index) {
        if (MANTISSA(result)[index] != 0) {
            MANTISSA(result)[index] -= 1;
            borrow = 0;
            break;
        }
        MANTISSA(result)[index] = 9;
    }

    if (borrow && ((offset - 1) < 0)) {
        [NSException raise:NSInternalInconsistencyException format:@"Invalid stage in decimal subtraction."];
    }

    return NSCalculationNoError;
}

/**
 @Status Interoperable
*/
NSCalculationError NSDecimalAdd(NSDecimal* result,
                                const NSDecimal* leftOperand,
                                const NSDecimal* rightOperand,
                                NSRoundingMode roundingMode) {
    THROW_NS_IF_FALSE(E_INVALIDARG, (leftOperand != NULL) || (rightOperand != NULL) || (result != NULL));
    VALIDATE_ARITHMETIC_INPUT(result, leftOperand, rightOperand);

    if (IS_ZERO(leftOperand)) {
        NSDecimalCopy(result, rightOperand);
        return NSCalculationNoError;
    }

    if (IS_ZERO(rightOperand)) {
        NSDecimalCopy(result, leftOperand);
        return NSCalculationNoError;
    }

    if (NEGATIVE_FLAG(leftOperand) != NEGATIVE_FLAG(rightOperand)) {
        // We have sign miss match.
        return (IS_NEGATIVE(rightOperand) ? NSDecimalSubtract(result, leftOperand, rightOperand, roundingMode) :
                                            NSDecimalSubtract(result, rightOperand, leftOperand, roundingMode));
    }

    NSDecimal left, right;

    // Copy over decimal for structural manipulation.
    NSDecimalCopy(&left, leftOperand);
    NSDecimalCopy(&right, rightOperand);

    // normalize both of them
    NSCalculationError error;
    if ((error = NSDecimalNormalize(&left, &right, roundingMode)) != NSCalculationNoError) {
        return error;
    }

    // They are both the same sign.
    if (IS_NEGATIVE(leftOperand) && IS_NEGATIVE(rightOperand)) {
        // Both of them are negative, make them positive
        NEGATIVE_FLAG((&left)) = 0;
        NEGATIVE_FLAG((&right)) = 0;
    }

    if ((error = _addSameSign(result, &left, &right)) != NSCalculationNoError) {
        return error;
    }

    if (IS_NEGATIVE(leftOperand) && IS_NEGATIVE(rightOperand)) {
        // set the negative flag back on.
        NEGATIVE_FLAG(result) = 1;
    }

    NSDecimalCompact(result);
    return NSCalculationNoError;
}

static NSCalculationError _evalSubtractSameNumbers(NSDecimal* result, NSDecimal* left, NSDecimal* right, NSComparisonResult comparison) {
    NSCalculationError error = NSCalculationNoError;
    switch (comparison) {
        case NSOrderedDescending:
            error = _subtractValidRange(result, left, right);
            break;
        case NSOrderedAscending:
            error = _subtractValidRange(result, right, left);
            NEGATIVE_FLAG(result) = 1;
            break;
        default:
            break;
    }

    return error;
}

/**
 @Status Interoperable
*/
NSCalculationError NSDecimalSubtract(NSDecimal* result,
                                     const NSDecimal* leftOperand,
                                     const NSDecimal* rightOperand,
                                     NSRoundingMode roundingMode) {
    THROW_NS_IF_FALSE(E_INVALIDARG, (leftOperand != NULL) || (rightOperand != NULL) || (result != NULL));

    VALIDATE_ARITHMETIC_INPUT(result, leftOperand, rightOperand);

    if (IS_ZERO(leftOperand)) {
        NSDecimalCopy(result, rightOperand);
        return NSCalculationNoError;
    }

    if (IS_ZERO(rightOperand)) {
        NSDecimalCopy(result, leftOperand);
        // flip the sign
        NEGATIVE_FLAG(result) = !NEGATIVE_FLAG(result);
        return NSCalculationNoError;
    }

    NSDecimal left, right;

    // Copy over decimal for structural manipulation.
    NSDecimalCopy(&left, leftOperand);
    NSDecimalCopy(&right, rightOperand);
    NSCalculationError error;
    // Sign diff
    if (NEGATIVE_FLAG(leftOperand) != NEGATIVE_FLAG(rightOperand)) {
        // We can convert the subtraction into an addition.
        if (IS_NEGATIVE(rightOperand)) {
            NEGATIVE_FLAG((&right)) = 0;
            return NSDecimalAdd(result, leftOperand, &right, roundingMode);
        }

        NEGATIVE_FLAG((&left)) = 0;

        if ((error = NSDecimalAdd(result, &left, rightOperand, roundingMode)) != NSCalculationNoError) {
            return error;
        }
        // reset the negation flag.
        NEGATIVE_FLAG(result) = 1;
        return error;
    }

    if ((error = NSDecimalNormalize(&left, &right, roundingMode)) != NSCalculationNoError) {
        return error;
    }

    NSComparisonResult comparison = NSDecimalCompare(leftOperand, rightOperand);
    if (comparison == NSOrderedSame) {
        SET_TO_ZERO(result);
        return NSCalculationNoError;
    }

    if (IS_NEGATIVE(leftOperand) && IS_NEGATIVE(rightOperand)) {
        NEGATIVE_FLAG((&left)) = 0;
        NEGATIVE_FLAG((&right)) = 0;
        if ((error = _evalSubtractSameNumbers(result, &right, &left, comparison)) != NSCalculationNoError) {
            return error;
        }
    } else {
        if ((error = _evalSubtractSameNumbers(result, &left, &right, comparison)) != NSCalculationNoError) {
            return error;
        }
    }

    NSDecimalCompact(result);
    return NSCalculationNoError;
}

/**
 @Status Interoperable
*/
void NSDecimalCompact(NSDecimal* number) {
    if ((number == NULL) || NSDecimalIsNotANumber(number)) {
        return;
    }

    int indexer = 0;
    // remove all the leading and trailing 0s of the mantissa.
    while ((indexer < number->_length) && (MANTISSA(number)[indexer] == 0)) {
        indexer++;
    }

    // shift the mantissa by indexer
    if (indexer > 0) {
        memmove(&MANTISSA(number)[0], &MANTISSA(number)[indexer], sizeof(unsigned short) * (LENGTH(number) - indexer));
        LENGTH(number) -= indexer;
    }

    // remove trailing 0s
    indexer = LENGTH(number) - 1;
    while ((indexer >= 0) && (MANTISSA(number)[indexer] == 0) && (EXPONENT(number) < EXPONENT_MAX)) {
        LENGTH(number)--;
        EXPONENT(number)++;
        indexer--;
    }

    if (LENGTH(number) == 0) {
        SET_TO_ZERO(number);
    }
}

/**
 @Status Interoperable
*/
NSComparisonResult NSDecimalCompare(const NSDecimal* leftOperand, const NSDecimal* rightOperand) {
    if (leftOperand == rightOperand) {
        return NSOrderedSame;
    }

    THROW_NS_IF_FALSE(E_INVALIDARG, (leftOperand != NULL) || (rightOperand != NULL));

    if (NEGATIVE_FLAG(leftOperand) != NEGATIVE_FLAG(rightOperand)) {
        // miss match in sign.
        return IS_NEGATIVE(rightOperand) ? NSOrderedDescending : NSOrderedAscending;
    }

    int leftValue = EXPONENT(leftOperand) + LENGTH(leftOperand);
    int rightValue = EXPONENT(rightOperand) + LENGTH(rightOperand);
    if (leftValue > rightValue) {
        return IS_NEGATIVE(rightOperand) ? NSOrderedAscending : NSOrderedDescending;
    }
    if (leftValue < rightValue) {
        return IS_NEGATIVE(rightOperand) ? NSOrderedDescending : NSOrderedAscending;
    }

    // same length
    int index = std::min(LENGTH(leftOperand), LENGTH(rightOperand)) - 1;
    while (index >= 0) {
        if (MANTISSA(leftOperand)[index] < MANTISSA(rightOperand)[index]) {
            return (IS_NEGATIVE(rightOperand)) ? NSOrderedDescending : NSOrderedAscending;
        }

        if (MANTISSA(leftOperand)[index] > MANTISSA(rightOperand)[index]) {
            return IS_NEGATIVE(rightOperand) ? NSOrderedAscending : NSOrderedDescending;
        }
        index--;
    }

    if (LENGTH(rightOperand) > LENGTH(leftOperand)) {
        return IS_NEGATIVE(rightOperand) ? NSOrderedDescending : NSOrderedAscending;
    }
    if (LENGTH(rightOperand) < LENGTH(leftOperand)) {
        return IS_NEGATIVE(rightOperand) ? NSOrderedAscending : NSOrderedDescending;
    }

    return NSOrderedSame;
}

/**
 @Status Interoperable
*/
void NSDecimalCopy(NSDecimal* destination, const NSDecimal* source) {
    if (!source || !destination) {
        return;
    }

    NEGATIVE_FLAG(destination) = NEGATIVE_FLAG(source);
    EXPONENT(destination) = EXPONENT(source);
    LENGTH(destination) = LENGTH(source);
    destination->_isCompact = source->_isCompact;
    destination->_reserved = source->_reserved;
    memcpy(&MANTISSA(destination), &MANTISSA(source), NSDecimalMaxSize * sizeof(unsigned short));
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
NSCalculationError NSDecimalMultiply(NSDecimal* result,
                                     const NSDecimal* leftOperand,
                                     const NSDecimal* rightOperand,
                                     NSRoundingMode roundingMode) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
NSCalculationError NSDecimalMultiplyByPowerOf10(NSDecimal* result, const NSDecimal* number, short power, NSRoundingMode roundingMode) {
    THROW_NS_IF_FALSE(E_INVALIDARG, (result != NULL) || (number != NULL));

    NSDecimalCopy(result, number);
    int exponent;
    if ((exponent = EXPONENT(result) + power) > EXPONENT_MAX) {
        INVALIDATE_DECIMAL(result);
        return NSCalculationOverflow;
    }

    if (exponent < EXPONENT_MIN) {
        INVALIDATE_DECIMAL(result);
        return NSCalculationUnderflow;
    }

    EXPONENT(result) = exponent;
    return NSCalculationNoError;
}

/**
 @Status Interoperable
*/
NSCalculationError NSDecimalNormalize(NSDecimal* number1, NSDecimal* number2, NSRoundingMode roundingMode) {
    THROW_NS_IF_FALSE(E_INVALIDARG, (number1 != NULL) || (number2 != NULL));

    if (NSDecimalIsNotANumber(number1) || NSDecimalIsNotANumber(number2)) {
        return NSCalculationNoError;
    }

    if (EXPONENT(number1) == EXPONENT(number2)) {
        return NSCalculationNoError;
    }

    // Pick out the larger decimal.
    NSDecimal* decimalToNormalize;
    NSDecimal* refDecimal;
    if (EXPONENT(number1) > EXPONENT(number2)) {
        decimalToNormalize = number1;
        refDecimal = number2;
    } else {
        decimalToNormalize = number2;
        refDecimal = number1;
    }

    // Since we want to keep it whole numbers as per mantissa, we'll normalize the larger of the two
    int expDiff = EXPONENT(decimalToNormalize) - EXPONENT(refDecimal);
    for (int index = 0; index < expDiff; index++) {
        MANTISSA(decimalToNormalize)[LENGTH(decimalToNormalize) + index] = 0;
    }

    // update the length and the exponent
    EXPONENT(decimalToNormalize) -= expDiff;
    LENGTH(decimalToNormalize) += expDiff;
    return NSCalculationNoError;
}

/**
 @Status Stub
 @Notes
*/
NSCalculationError NSDecimalPower(NSDecimal* result, const NSDecimal* number, NSUInteger power, NSRoundingMode roundingMode) {
    UNIMPLEMENTED();
    return StubReturn();
}

static void _roundUp(NSDecimal* decimal) {
    for (int index = LENGTH(decimal) - 1; index >= 0; index--) {
        // If it's 9, we set it to 0 and cause a propagation
        if (MANTISSA(decimal)[index] != 9) {
            MANTISSA(decimal)[index] += 1;
            break;
        }
        MANTISSA(decimal)[index] = 0;
    }
}

/**
 @Status Interoperable
*/
void NSDecimalRound(NSDecimal* result, const NSDecimal* number, NSInteger scale, NSRoundingMode roundingMode) {
    THROW_NS_IF_FALSE(E_INVALIDARG, (result != NULL) || (number != NULL));

    if (NSDecimalIsNotANumber(number)) {
        return;
    }
    if (scale == NSDecimalNoScale || (LENGTH(number) == 0)) {
        NSDecimalCopy(result, number);
        return;
    }

    int adjustedLengthOfMantissa = EXPONENT(number) + LENGTH(number) + scale;
    if (adjustedLengthOfMantissa <= 0) {
        // We pretty much rounded it off fully.
        NSDecimalCopy(result, number);
        SET_TO_ZERO(result);
        return;
    }

    int adjustedExponent = (LENGTH(number) + EXPONENT(number)) - adjustedLengthOfMantissa;

    // Copy over the structure and update the entries.
    NSDecimalCopy(result, number);
    EXPONENT(result) = adjustedExponent;
    LENGTH(result) = adjustedLengthOfMantissa;

    // Do the proper roundings.
    switch (roundingMode) {
        case NSRoundPlain:
            // Round to the closest possible return value;
            // when caught halfway between two positive numbers (higher or equal to 5), round up;
            // when caught between two negative numbers, round down.
            if (MANTISSA(result)[adjustedLengthOfMantissa] >= 5) {
                // This handles both cases: round up for positive and round down for negative.
                _roundUp(result);
            }
            break;

        case NSRoundUp:
            // If the digit at (adjustedLengthOfMantissa -1) less than 9, we just increment the value, if it's 9, then we set it to 0,
            // and propagate the change throughout the array.
            // Note: that round up the cutoff digit if the decimal is non negative.
            if (IS_POSITIVE(result)) {
                _roundUp(result);
            }
            break;

        case NSRoundDown:
            // Same case as round up if it's a negative number, if not leave as is with the adjusted exponent.
            if (IS_NEGATIVE(result) && (scale != EXPONENT(result))) {
                _roundUp(result);
            }
            break;

        case NSRoundBankers: {
            // Round to the closest possible return value;
            // when halfway between two possibilities, return the possibility whose last digit is even.
            unsigned short value = MANTISSA(result)[adjustedLengthOfMantissa];

            bool roundup = (value == 5) && (adjustedLengthOfMantissa != 0) && ((MANTISSA(result)[adjustedLengthOfMantissa - 1] % 2) != 0);

            if (value > 5 || roundup) {
                _roundUp(result);
            }
            break;
        }

        default:
            break;
    }

    NSDecimalCompact(result);
}
