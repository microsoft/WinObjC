//******************************************************************************
//
//  Copyright (c) 2007 Christopher J. W. Lloyd
//  Copyright (c) Microsoft. All rights reserved.
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
#pragma once

#include <limits.h>
#import <Foundation/NSObjCRuntime.h>

typedef NS_ENUM(NSUInteger, NSRoundingMode) { NSRoundPlain, NSRoundDown, NSRoundUp, NSRoundBankers };

typedef NS_ENUM(NSUInteger, NSCalculationError) {
    NSCalculationNoError = 0,
    NSCalculationLossOfPrecision,
    NSCalculationUnderflow,
    NSCalculationOverflow,
    NSCalculationDivideByZero
};

#define NSDecimalMaxSize (8)
#define NSDecimalMaxExponent 127
#define NSDecimalNoScale SHRT_MAX

typedef struct NSDecimal {
    signed int _exponent : 8;
    // indicates the length occupied by the value in the mantissa array
    unsigned int _length : 4;
    unsigned int _isNegative : 1;
    unsigned int _isCompact : 1;
    // Not being used
    unsigned int _reserved : 18;
    unsigned short _mantissa[NSDecimalMaxSize];
} NSDecimal;

FOUNDATION_EXPORT void NSDecimalCopy(NSDecimal* destination, const NSDecimal* source);

FOUNDATION_EXPORT BOOL NSDecimalIsNotANumber(const NSDecimal* dcm);

FOUNDATION_EXPORT NSString* NSDecimalString(const NSDecimal* dcm, id locale) STUB_METHOD;

FOUNDATION_EXPORT NSComparisonResult NSDecimalCompare(const NSDecimal* leftOperand, const NSDecimal* rightOperand);

FOUNDATION_EXPORT void NSDecimalRound(NSDecimal* result, const NSDecimal* number, NSInteger scale, NSRoundingMode roundingMode) STUB_METHOD;

FOUNDATION_EXPORT NSCalculationError NSDecimalNormalize(NSDecimal* number1, NSDecimal* number2, NSRoundingMode roundingMode);

FOUNDATION_EXPORT void NSDecimalCompact(NSDecimal* number);

FOUNDATION_EXPORT NSCalculationError NSDecimalAdd(NSDecimal* result,
                                                  const NSDecimal* leftOperand,
                                                  const NSDecimal* rightOperand,
                                                  NSRoundingMode roundingMode);

FOUNDATION_EXPORT NSCalculationError NSDecimalSubtract(NSDecimal* result,
                                                       const NSDecimal* leftOperand,
                                                       const NSDecimal* rightOperand,
                                                       NSRoundingMode roundingMode);

FOUNDATION_EXPORT NSCalculationError NSDecimalMultiply(NSDecimal* result,
                                                       const NSDecimal* leftOperand,
                                                       const NSDecimal* rightOperand,
                                                       NSRoundingMode roundingMode) STUB_METHOD;

FOUNDATION_EXPORT NSCalculationError NSDecimalDivide(NSDecimal* result,
                                                     const NSDecimal* leftOperand,
                                                     const NSDecimal* rightOperand,
                                                     NSRoundingMode roundingMode) STUB_METHOD;

FOUNDATION_EXPORT NSCalculationError NSDecimalMultiplyByPowerOf10(NSDecimal* result,
                                                                  const NSDecimal* number,
                                                                  short power,
                                                                  NSRoundingMode roundingMode) STUB_METHOD;

FOUNDATION_EXPORT NSCalculationError NSDecimalPower(NSDecimal* result,
                                                    const NSDecimal* number,
                                                    NSUInteger power,
                                                    NSRoundingMode roundingMode) STUB_METHOD;