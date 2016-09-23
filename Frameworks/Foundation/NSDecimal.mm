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

#define IS_NEGATIVE(decimal) (decimal)->_isNegative

#define IS_POSITIVE(decimal) !IS_NEGATIVE(decimal)

#define IS_ZERO(decimal) (((decimal)->_length == 0) && IS_POSITIVE(decimal))

#define INVALIDATE_DECIMAL(decimal) \
    \
decimal->_length = 0;               \
    \
decimal->_isNegative = YES;

#define SET_TO_ZERO(decimal) \
    \
decimal->_length = 0;        \
    \
decimal->_isNegative = NO;   \
    \
NSDecimalCompact(decimal);

#define VALIDATE_ARITHMETIC_INPUT(result, leftOperand, rightOperand)                 \
    if (NSDecimalIsNotANumber(leftOperand) || NSDecimalIsNotANumber(rightOperand)) { \
        INVALIDATE_DECIMAL(result);                                                  \
        return NSCalculationOverflow;                                                \
    }

#define REMINDER(decimal) (decimal->_reminder)

typedef struct {
    NSDecimal decimal;
    unsigned short* _mantissa;
    unsigned short _reminder;
    // only used for cases where we have carryover
    unsigned int _extendedLen;
} NSDecimalInternal;

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

void _InternalDecimalCopy(NSDecimal* destination, NSDecimalInternal* source) {
    if (!source || !destination) {
        return;
    }
    NSDecimalCopy(destination, &(source->decimal));
    memcpy(destination->_mantissa, source->_mantissa, NSDecimalMaxSize * sizeof(unsigned short));
}

NSCalculationError _subtraction(NSDecimal* result, const NSDecimal* left, const NSDecimal* right) {
    unsigned int commonLength = (left->_length < right->_length) ? left->_length : right->_length;

    unsigned int overflow = 1;

    for (int index = 0; index < commonLength; index++) {
        overflow += USHRT_MAX + ((left->_mantissa)[index] - (right->_mantissa)[index]);
        (result->_mantissa)[index] = overflow;
        overflow = overflow >> 16;
    }

    unsigned int length = right->_length;

    if (right->_length < left->_length) {
        while (length < left->_length && overflow == 0) {
            overflow = USHRT_MAX + (left->_mantissa)[length];
            (result->_mantissa)[length] = overflow;
            overflow = overflow >> 16;
            length++;
        }

        memmove((result->_mantissa) + length, left->_mantissa + length, (left->_length - length) * sizeof(unsigned short));
        length = (length < left->_length) ? left->_length : length;
    }

    result->_length = length;

    return NSCalculationNoError;
}

NSCalculationError _mantissaAddition(NSDecimalInternal* result, NSDecimalInternal* augend, unsigned short addend) {
    for (int index = 0; index < augend->decimal._length; ++index) {
        unsigned int res = static_cast<unsigned int>((augend->_mantissa)[index]) + static_cast<unsigned int>(addend);
        (result->_mantissa)[index] = res;
        addend = res >> 16;
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

NSCalculationError _mantissaMultiplication(NSDecimalInternal* result, NSDecimalInternal* multiplicand, unsigned short multiplier) {
    // This will be used for by hand style multiplication
    if (multiplier == 0 || multiplicand->decimal._length == 0) {
        result->decimal._length = 0;
        result->decimal._exponent = 0;
        return NSCalculationNoError;
    }

    unsigned int carryOver = 0;

    for (int index = 0; index < multiplicand->decimal._length; ++index) {
        unsigned int res =
            (static_cast<unsigned int>(multiplier) * static_cast<unsigned int>((multiplicand->_mantissa)[index])) + carryOver;
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

unsigned int _obtainLength(unsigned short* mantissa, int length) {
    unsigned int result = 0;
    for (int i = length - 1; i >= 0; --i) {
        result = i + 1;
        if (mantissa[i] != 0) {
            break;
        }
    }

    return result;
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

NSCalculationError _mantissaDivision(NSDecimalInternal* result, NSDecimalInternal* dividend, unsigned short divisor) {
    if (!divisor) {
        INVALIDATE_DECIMAL(result);
        return NSCalculationDivideByZero;
    }

    for (int index = dividend->decimal._length - 1; index >= 0; --index) {
        unsigned int res = static_cast<unsigned int>((dividend->_mantissa)[index]) | (result->_reminder << 16);
        result->_reminder = res % divisor;
        (result->_mantissa)[index] = res / divisor;
    }

    result->decimal._length = _obtainLength(result->_mantissa, dividend->decimal._length);

    return NSCalculationNoError;
}

NSCalculationError compactMantissa(NSDecimalInternal* iDecimal, NSRoundingMode roundingMode) {
    // divide by 10 until we can compact it.
    int exponent = 0;

    NSDecimalInternal result;
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
    if (result._reminder != 0) {
    }

    return NSCalculationNoError;
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
 @Status Interoperable
*/
NSComparisonResult NSDecimalCompare(const NSDecimal* leftOperand, const NSDecimal* rightOperand) {
    if (leftOperand == rightOperand) {
        return NSOrderedSame;
    }

    THROW_NS_IF_FALSE(E_INVALIDARG, (leftOperand != NULL) && (rightOperand != NULL));

    NSDecimal left, right;
    NSDecimalCopy(&left, leftOperand);
    NSDecimalCopy(&right, rightOperand);
    NSDecimalNormalize(&left, &right, 0);

    if (!left._isNegative && right._isNegative) {
        return NSOrderedDescending;
    }

    if (left._isNegative && !right._isNegative) {
        return NSOrderedAscending;
    }

    // same signs
    if (left._length < right._length) {
        return right._isNegative ? NSOrderedDescending : NSOrderedAscending;
    }

    if (left._length > right._length) {
        return right._isNegative ? NSOrderedAscending : NSOrderedDescending;
    }

    // all same
    int index = right._length - 1;
    while (index >= 0) {
        if (left._mantissa[index] < right._mantissa[index]) {
            return right._isNegative ? NSOrderedDescending : NSOrderedAscending;
        }

        if (left._mantissa[index] > right._mantissa[index]) {
            return right._isNegative ? NSOrderedAscending : NSOrderedDescending;
        }
        index--;
    }

    return NSOrderedSame;
}

/**
 @Status Interoperable
*/
NSCalculationError NSDecimalNormalize(NSDecimal* number1, NSDecimal* number2, NSRoundingMode roundingMode) {
    THROW_NS_IF_FALSE(E_INVALIDARG,
                      (number1 == NULL) && (number2 == NULL) && NSDecimalIsNotANumber(number1) && NSDecimalIsNotANumber(number2));

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

    NSDecimalInternal internalResult = { 0 };

    NSDecimalCopy(&internalResult.decimal, decimalToNormalize);
    internalResult._mantissa = internalResult.decimal._mantissa;
    internalResult._reminder = 0;
    internalResult._extendedLen = NSDecimalMaxSize;

    NSCalculationError error = NSCalculationNoError;
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

    int exponent = number->_exponent;
    NSDecimalInternal internalResult = { 0 };

    // reduce by 10 as much as we can
    NSDecimalCopy(&internalResult.decimal, number);
    internalResult._mantissa = internalResult.decimal._mantissa;
    internalResult._reminder = 0;
    internalResult._extendedLen = number->_length;

    do {
        _mantissaDivision(&internalResult, &internalResult, 10);
        exponent++;
    } while (!internalResult._reminder);

    // put back the leftover reminder.
    _mantissaMultiplication(&internalResult, &internalResult, 10);
    exponent--;
    _mantissaAddition(&internalResult, &internalResult, internalResult._reminder);

    while (exponent > 127) {
        // refit
        _mantissaMultiplication(&internalResult, &internalResult, 10);
        exponent--;
    }

    // update the exp
    internalResult.decimal._exponent = exponent;
    _InternalDecimalCopy(number, &internalResult);
    number->_isCompact = 1;
}

NSComparisonResult _compareMantissa(NSDecimal* left, NSDecimal* right) {
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

NSCalculationError _handleDifferenceOfSignAddition(NSDecimal* result, NSDecimal* left, NSDecimal* right, NSRoundingMode roundingMode) {
    // Since these are normalized and to account for unsigned subtraction we have to do mantissa based comparison.

    NSComparisonResult res = _compareMantissa(left, right);

    if (res == NSOrderedSame) {
        SET_TO_ZERO(result);
        return NSCalculationNoError;
    }

    if (res == NSOrderedAscending) {
        // R > L
        NSCalculationError error = _subtraction(result, right, left);
        if (error != NSCalculationNoError) {
            INVALIDATE_DECIMAL(result);
            return error;
        }
        result->_isNegative = right->_isNegative;
        result->_exponent = right->_exponent;
    } else {
        NSCalculationError error = _subtraction(result, left, right);
        if (error != NSCalculationNoError) {
            INVALIDATE_DECIMAL(result);
            return error;
        }
        result->_isNegative = left->_isNegative;
        result->_exponent = left->_exponent;
    }

    NSDecimalCompact(result);
    return NSCalculationNoError;
}

/**
 @Status Interoperable
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
    if ((IS_NEGATIVE(leftOperand) && IS_NEGATIVE(rightOperand)) || (IS_POSITIVE(leftOperand) && IS_POSITIVE(rightOperand))) {
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

        unsigned short finalResult[NSDecimalMaxSize + 1] = { 0 };
        unsigned int res = 0;

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
        NSDecimalInternal internalResult = { 0 };
        NSDecimalCopy(&internalResult.decimal, result);
        internalResult._mantissa = finalResult;
        internalResult._reminder = 0;
        internalResult._extendedLen = NSDecimalMaxSize + 1;

        NSCalculationError error = compactMantissa(&internalResult, roundingMode);
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
 @Status Interoperable
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