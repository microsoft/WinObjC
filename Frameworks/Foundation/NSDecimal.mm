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
#import <Foundation/NSDecimal.h>
#import <algorithm>

#define IS_NEGATIVE(decimal) (decimal)->_isNegative

#define IS_POSITIVE(decimal) !IS_NEGATIVE(decimal)

#define IS_ZERO(decimal) (((decimal)->_length == 0) && IS_POSITIVE(decimal))

// clang-format off
#define INVALIDATE_DECIMAL(decimal) \
decimal->_length = 0;               \
decimal->_isNegative = YES;

#define SET_TO_ZERO(decimal) \
decimal->_length = 0;        \
decimal->_isNegative = NO;   \
NSDecimalCompact(decimal);
// clang-format on

#define VALIDATE_ARITHMETIC_INPUT(result, leftOperand, rightOperand)                 \
    if (NSDecimalIsNotANumber(leftOperand) || NSDecimalIsNotANumber(rightOperand)) { \
        INVALIDATE_DECIMAL(result);                                                  \
        return NSCalculationOverflow;                                                \
    }

// Internal struct to manipulate the NSDecimal struct
// this takes care of carry over/remainder
typedef struct {
    NSDecimal decimal;
    // Pointer to the mantissa being manipulated
    unsigned short* _mantissa;
    unsigned short _remainder;
    // length of the array being pointed by _mantissa
    unsigned int _extendedLen;
} NSDecimalInternal;

// Internal helper methods. All of these methods assume the NSDecimal/NSDecimalInternal is
// normalized via NSDecimalNormalize (the exponents of the both decimals will be the same)
static void _InternalDecimalCopy(NSDecimal* destination, NSDecimalInternal* source);
static NSComparisonResult _compareMantissa(NSDecimal* left, NSDecimal* right);

static NSCalculationError _handleDifferenceOfSignAddition(NSDecimal* result,
                                                          NSDecimal* left,
                                                          NSDecimal* right,
                                                          NSRoundingMode roundingMode);

static NSCalculationError _subtraction(NSDecimal* result, const NSDecimal* left, const NSDecimal* right);
static NSCalculationError _mantissaAddition(NSDecimalInternal* result, NSDecimalInternal* augend, unsigned short addend);
static NSCalculationError _mantissaMultiplication(NSDecimalInternal* result, NSDecimalInternal* multiplicand, unsigned short multiplier);
static unsigned int _obtainLength(unsigned short* mantissa, int length);
static NSCalculationError _mantissaDivision(NSDecimalInternal* result, NSDecimalInternal* dividend, unsigned short divisor);
static NSCalculationError _compactMantissa(NSDecimalInternal* iDecimal, NSRoundingMode roundingMode);

/**
 @Status Interoperable
*/
void NSDecimalCopy(NSDecimal* destination, const NSDecimal* source) {
    if (!source || !destination) {
        return;
    }

    destination->_isNegative = source->_isNegative;
    destination->_exponent = source->_exponent;
    destination->_length = source->_length;
    destination->_isCompact = source->_isCompact;
    destination->_reserved = source->_reserved;
    memcpy(&destination->_mantissa, &source->_mantissa, NSDecimalMaxSize * sizeof(unsigned short));
}

/**
 @Status Interoperable
*/
BOOL NSDecimalIsNotANumber(const NSDecimal* dcm) {
    THROW_NS_IF_FALSE(E_INVALIDARG, dcm != NULL);
    return !dcm->_length && IS_NEGATIVE(dcm);
}

/**
 @Status Interoperable
*/
NSComparisonResult NSDecimalCompare(const NSDecimal* leftOperand, const NSDecimal* rightOperand) {
    if (leftOperand == rightOperand) {
        return NSOrderedSame;
    }

    THROW_NS_IF_FALSE(E_INVALIDARG, (leftOperand != NULL) && (rightOperand != NULL));

    // not a number
    if (NSDecimalIsNotANumber(leftOperand)) {
        if (NSDecimalIsNotANumber(rightOperand)) {
            return NSOrderedSame;
        }
        return NSOrderedAscending;
    } else if (NSDecimalIsNotANumber(rightOperand)) {
        return NSOrderedDescending;
    }

    NSDecimal left, right;
    NSDecimalCopy(&left, leftOperand);
    NSDecimalCopy(&right, rightOperand);
    NSDecimalNormalize(&left, &right, NSRoundPlain);

    if (!left._isNegative && right._isNegative) {
        return NSOrderedDescending;
    }

    if (left._isNegative && !right._isNegative) {
        return NSOrderedAscending;
    }

    // same signs
    NSComparisonResult result = _compareMantissa(&left, &right);

    if ((result != NSOrderedSame) && (left._isNegative)) {
        result *= -1;
    }

    return result;
}

/**
 @Status Caveat
 @Notes roundingMode is not supported.
*/
NSCalculationError NSDecimalNormalize(NSDecimal* number1, NSDecimal* number2, NSRoundingMode roundingMode) {
    THROW_NS_IF_FALSE(E_INVALIDARG,
                      (number1 != NULL) && (number2 != NULL) && !NSDecimalIsNotANumber(number1) && !NSDecimalIsNotANumber(number2));

    if (number1->_exponent == number2->_exponent) {
        return NSCalculationNoError;
    }

    NSDecimal* decimalToNormalize;
    NSDecimal* refDecimal;

    if (number1->_exponent > number2->_exponent) {
        decimalToNormalize = number1;
        refDecimal = number2;
    } else {
        decimalToNormalize = number2;
        refDecimal = number1;
    }

    int exponent = decimalToNormalize->_exponent - refDecimal->_exponent;

    NSDecimalInternal internalResult = {};

    NSDecimalCopy(&internalResult.decimal, decimalToNormalize);
    internalResult._mantissa = internalResult.decimal._mantissa;
    internalResult._remainder = 0;
    internalResult._extendedLen = NSDecimalMaxSize;

    NSCalculationError error = NSCalculationNoError;
    // TODO: this can be better done, by creating a mantissa out of the 10^exp and doing mantissa by mantissa multiplication.
    // This should be changed when NSDecimalMultiplication is implemented.
    while (exponent > 0) {
        error = _mantissaMultiplication(&internalResult, &internalResult, 10);
        if (error != NSCalculationNoError) {
            return error;
        }
        exponent--;
    }

    internalResult.decimal._exponent = refDecimal->_exponent;
    _InternalDecimalCopy(decimalToNormalize, &internalResult);
    return NSCalculationNoError;
}

/**
 @Status Interoperable
*/
void NSDecimalCompact(NSDecimal* number) {
    if ((number == NULL) || NSDecimalIsNotANumber(number) || IS_ZERO(number)) {
        return;
    }

    // Not checking the isCompact field, since it could of been falsely set.
    // We try out best to compact it.

    int exponent = number->_exponent;
    NSDecimalInternal internalResult = {};

    // reduce by 10 as much as we can
    NSDecimalCopy(&internalResult.decimal, number);
    internalResult._mantissa = internalResult.decimal._mantissa;
    internalResult._remainder = 0;
    internalResult._extendedLen = NSDecimalMaxSize;

    do {
        _mantissaDivision(&internalResult, &internalResult, 10);
        exponent++;
    } while (!internalResult._remainder);

    // put back the leftover remainder.
    _mantissaMultiplication(&internalResult, &internalResult, 10);
    exponent--;
    _mantissaAddition(&internalResult, &internalResult, internalResult._remainder);

    while (exponent > NSDecimalMaxExponent) {
        // refit
        _mantissaMultiplication(&internalResult, &internalResult, 10);
        exponent--;
    }

    // update the exp
    internalResult.decimal._exponent = exponent;
    _InternalDecimalCopy(number, &internalResult);
    number->_isCompact = 1;
}

/**
 @Status Caveat
 @Notes roundingMode is not supported.
*/
NSCalculationError NSDecimalAdd(NSDecimal* result,
                                const NSDecimal* leftOperand,
                                const NSDecimal* rightOperand,
                                NSRoundingMode roundingMode) {
    THROW_NS_IF_FALSE(E_INVALIDARG, (leftOperand != NULL) && (rightOperand != NULL) && (result != NULL));
    VALIDATE_ARITHMETIC_INPUT(result, leftOperand, rightOperand);

    if (IS_ZERO(leftOperand)) {
        NSDecimalCopy(result, rightOperand);
        return NSCalculationNoError;
    }

    if (IS_ZERO(rightOperand)) {
        NSDecimalCopy(result, leftOperand);
        return NSCalculationNoError;
    }

    NSDecimal left, right;

    // Copy over decimal for structural manipulation.
    NSDecimalCopy(&left, leftOperand);
    NSDecimalCopy(&right, rightOperand);

    // normalize both of them
    NSCalculationError error = NSDecimalNormalize(&left, &right, roundingMode);
    if (error != NSCalculationNoError) {
        return error;
    }

    // If they are both the same sign, then we can directly add the mantissa
    if (IS_NEGATIVE(leftOperand) == IS_NEGATIVE(rightOperand)) {
        // set the signs
        NSDecimal* shortest;
        NSDecimal* longest;
        unsigned int shortLen;
        unsigned int longestLen;
        if (rightOperand->_length < leftOperand->_length) {
            shortLen = rightOperand->_length;
            shortest = &right;
            longestLen = leftOperand->_length;
            longest = &left;
            NSDecimalCopy(result, &left);

        } else {
            shortLen = leftOperand->_length;
            shortest = &left;
            longestLen = rightOperand->_length;
            longest = &right;
            NSDecimalCopy(result, &right);
        }

        unsigned short finalResult[NSDecimalMaxSize + 1] = {};
        unsigned int res = 0;

        // Since the decimals are normalized, add the mantissa's and account for overflow.
        for (int index = 0; index < shortLen; ++index) {
            res += shortest->_mantissa[index] + longest->_mantissa[index];
            finalResult[index] = res;
            res = res >> 0x10;
        }

        // take care of the rest
        for (int index = shortLen; index < longestLen; ++index) {
            res += longest->_mantissa[index];
            finalResult[index] = res;
            res = res >> 0x10;
        }

        if (res != 0) {
            if (longestLen >= NSDecimalMaxSize + 1) {
                INVALIDATE_DECIMAL(result);
                return NSCalculationOverflow;
            }
            finalResult[longestLen] = res;
            result->_length = longestLen + 1;
        }

        // We need to fit
        NSDecimalInternal internalResult = {};
        NSDecimalCopy(&internalResult.decimal, result);
        internalResult._mantissa = finalResult;
        internalResult._remainder = 0;
        internalResult._extendedLen = NSDecimalMaxSize + 1;

        NSCalculationError error = _compactMantissa(&internalResult, roundingMode);
        if (error != NSCalculationNoError) {
            INVALIDATE_DECIMAL(result);
            return error;
        }

        // set the result back
        _InternalDecimalCopy(result, &internalResult);
        NSDecimalCompact(result);
        return NSCalculationNoError;
    }

    return _handleDifferenceOfSignAddition(result, &left, &right, roundingMode);
}

/**
 @Status Caveat
 @Notes roundingMode is not supported.
*/
NSCalculationError NSDecimalSubtract(NSDecimal* result,
                                     const NSDecimal* leftOperand,
                                     const NSDecimal* rightOperand,
                                     NSRoundingMode roundingMode) {
    THROW_NS_IF_FALSE(E_INVALIDARG, (leftOperand != NULL) && (rightOperand != NULL) && (result != NULL));
    VALIDATE_ARITHMETIC_INPUT(result, leftOperand, rightOperand);
    // Convert the subtraction into an addition.
    // L - R -> L + (-R)
    // flip the sign, if and only if it's non zero and a valid number
    NSDecimal right;
    NSDecimalCopy(&right, rightOperand);
    right._isNegative = (IS_ZERO(&right) || NSDecimalIsNotANumber(&right)) ? right._isNegative : !right._isNegative;

    return NSDecimalAdd(result, leftOperand, &right, roundingMode);
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
NSString* NSDecimalString(const NSDecimal* dcm, id locale) STUB_METHOD {
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

static void _InternalDecimalCopy(NSDecimal* destination, NSDecimalInternal* source) {
    if (!source || !destination) {
        return;
    }

    NSDecimalCopy(destination, &(source->decimal));
    memcpy(destination->_mantissa, source->_mantissa, NSDecimalMaxSize * sizeof(unsigned short));
}

static NSComparisonResult _compareMantissa(NSDecimal* left, NSDecimal* right) {
    // Note: All inputs have been normalized via NSDecimalNormalize
    if (left->_length > right->_length) {
        return NSOrderedDescending;
    }

    if (left->_length < right->_length) {
        return NSOrderedAscending;
    }

    // same length
    for (int index = right->_length - 1; index >= 0; index--) {
        if (right->_mantissa[index] > left->_mantissa[index]) {
            return NSOrderedAscending;
        }

        if (right->_mantissa[index] < left->_mantissa[index]) {
            return NSOrderedDescending;
        }
    }

    return NSOrderedSame;
}

static NSCalculationError _handleDifferenceOfSignAddition(NSDecimal* result,
                                                          NSDecimal* left,
                                                          NSDecimal* right,
                                                          NSRoundingMode roundingMode) {
    // Note: All inputs have been normalized via NSDecimalNormalize
    // Since these are normalized and to account for unsigned subtraction we have to do mantissa based comparison.

    NSComparisonResult res = _compareMantissa(left, right);

    if (res == NSOrderedSame) {
        SET_TO_ZERO(result);
        return NSCalculationNoError;
    }

    NSDecimal* greater = left;
    NSDecimal* lesser = right;

    if (res == NSOrderedAscending) {
        std::swap(greater, lesser);
    }

    NSCalculationError error = _subtraction(result, greater, lesser);
    if (error != NSCalculationNoError) {
        INVALIDATE_DECIMAL(result);
        return error;
    }
    result->_isNegative = greater->_isNegative;
    result->_exponent = greater->_exponent;

    NSDecimalCompact(result);
    return NSCalculationNoError;
}

static NSCalculationError _subtraction(NSDecimal* result, const NSDecimal* left, const NSDecimal* right) {
    // Note: All inputs have been normalized via NSDecimalNormalize
    unsigned int commonLength = std::min(left->_length, right->_length);

    unsigned int overflow = 1;

    // Since the decimal is normalized, we just subtract the mantissas
    // subtract the numbers in the length
    for (int index = 0; index < commonLength; index++) {
        overflow += USHRT_MAX + ((left->_mantissa)[index] - (right->_mantissa)[index]);
        (result->_mantissa)[index] = overflow;
        overflow = overflow >> 0x10;
    }

    unsigned int length = right->_length;

    // handle the rest of the length.
    if (right->_length < left->_length) {
        while (length < left->_length && overflow == 0) {
            overflow = USHRT_MAX + (left->_mantissa)[length];
            (result->_mantissa)[length] = overflow;
            overflow = overflow >> 0x10;
            length++;
        }

        memmove((result->_mantissa) + length, left->_mantissa + length, (left->_length - length) * sizeof(unsigned short));
        length = (length < left->_length) ? left->_length : length;
    }

    result->_length = length;

    return NSCalculationNoError;
}

static NSCalculationError _mantissaAddition(NSDecimalInternal* result, NSDecimalInternal* augend, unsigned short addend) {
    // Note: All inputs have been normalized via NSDecimalNormalize
    // Add the addend to the mantissa
    for (int index = 0; index < augend->decimal._length; ++index) {
        unsigned int res = static_cast<unsigned int>((augend->_mantissa)[index]) + static_cast<unsigned int>(addend);
        (result->_mantissa)[index] = res;
        addend = res >> 0x10;
    }

    if (addend != 0) {
        if (result->_extendedLen == augend->decimal._length) {
            // overflow
            return NSCalculationOverflow;
        }

        // set the carryover
        (result->_mantissa)[augend->decimal._length] = addend;
        result->decimal._length++;
    }

    return NSCalculationNoError;
}

static NSCalculationError _mantissaMultiplication(NSDecimalInternal* result, NSDecimalInternal* multiplicand, unsigned short multiplier) {
    // Note: All inputs have been normalized via NSDecimalNormalize
    // This will be used for by hand style multiplication
    if (multiplier == 0 || multiplicand->decimal._length == 0) {
        result->decimal._length = 0;
        result->decimal._exponent = 0;
        return NSCalculationNoError;
    }

    unsigned int carryOver = 0;

    // multiply the mantissa by the multiplier and propagate the carry over.
    for (int index = 0; index < multiplicand->decimal._length; ++index) {
        unsigned int res =
            carryOver + (static_cast<unsigned int>(multiplier) * static_cast<unsigned int>((multiplicand->_mantissa)[index]));
        (result->_mantissa)[index] = res;
        carryOver = res >> 0x10;
    }

    // we have the carry over
    if (carryOver != 0) {
        if (result->_extendedLen == multiplicand->decimal._length) {
            // overflow
            return NSCalculationOverflow;
        }

        // set the overflow
        (result->_mantissa)[multiplicand->decimal._length] = carryOver;
        result->decimal._length++;
    }

    return NSCalculationNoError;
}

static unsigned int _obtainLength(unsigned short* mantissa, int length) {
    for (int i = length - 1; i >= 0; --i) {
        if (mantissa[i] != 0) {
            return i + 1;
        }
    }

    return 1;
}

static NSCalculationError _mantissaDivision(NSDecimalInternal* result, NSDecimalInternal* dividend, unsigned short divisor) {
    // Note: All inputs have been normalized via NSDecimalNormalize
    if (!divisor) {
        INVALIDATE_DECIMAL((&result->decimal));
        return NSCalculationDivideByZero;
    }

    // Divide the mantissa by the divisor
    for (int index = dividend->decimal._length - 1; index >= 0; --index) {
        unsigned int res = static_cast<unsigned int>((dividend->_mantissa)[index]) | (result->_remainder << 0x10);
        result->_remainder = res % divisor;
        (result->_mantissa)[index] = res / divisor;
    }

    result->decimal._length = _obtainLength(result->_mantissa, dividend->decimal._length);

    return NSCalculationNoError;
}

static NSCalculationError _compactMantissa(NSDecimalInternal* iDecimal, NSRoundingMode roundingMode) {
    // Attempt to fit a mantissa of size greater than NSDecimalMaxSize into the mantissa of size NSDecimalMaxSize
    // Note: All inputs have been normalized via NSDecimalNormalize

    int exponent = 0;

    NSDecimalInternal result;
    // divide by 10 until we can compact it.
    while (iDecimal->decimal._length > NSDecimalMaxSize) {
        exponent++;
        NSCalculationError error = _mantissaDivision(iDecimal, iDecimal, 10);
        if (error != NSCalculationNoError) {
            return error;
        }
    }

    // update the exp
    result.decimal._exponent += exponent;

    // TODO: Add Support for rounding
    if (result._remainder != 0) {
    }

    return NSCalculationNoError;
}