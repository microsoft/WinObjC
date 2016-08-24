/* Copyright (c) 2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the
following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifndef _NSDECIMAL_H_
#define _NSDECIMAL_H_

#include <limits.h>
#import <Foundation/NSObjCRuntime.h>

#define NSDecimalMaxSize (8)
#define NSDecimalNoScale SHRT_MAX

enum { NSRoundPlain, NSRoundDown, NSRoundUp, NSRoundBankers };

typedef uint32_t NSRoundingMode;

enum { NSCalculationNoError = 0, NSCalculationLossOfPrecision, NSCalculationUnderflow, NSCalculationOverflow, NSCalculationDivideByZero };

typedef uint32_t NSCalculationError;

typedef struct NSDecimal {
    union {
        signed int _exponent : 8;
        unsigned int _length : 4;
        unsigned int _isNegative : 1;
        unsigned int _isCompact : 1;
        unsigned int _reserved : 18;
        unsigned short _mantissa[NSDecimalMaxSize];
    };

    double val;
} NSDecimal;

FOUNDATION_EXPORT BOOL NSDecimalIsNotANumber(const NSDecimal* dcm) STUB_METHOD;

FOUNDATION_EXPORT NSString* NSDecimalString(const NSDecimal* dcm, id locale) STUB_METHOD;

FOUNDATION_EXPORT NSComparisonResult NSDecimalCompare(const NSDecimal* leftOperand, const NSDecimal* rightOperand);

FOUNDATION_EXPORT NSCalculationError NSDecimalAdd(NSDecimal* result,
                                                  const NSDecimal* leftOperand,
                                                  const NSDecimal* rightOperand,
                                                  NSRoundingMode roundingMode) STUB_METHOD;

FOUNDATION_EXPORT NSCalculationError NSDecimalSubtract(NSDecimal* result,
                                                       const NSDecimal* leftOperand,
                                                       const NSDecimal* rightOperand,
                                                       NSRoundingMode roundingMode) STUB_METHOD;

FOUNDATION_EXPORT NSCalculationError NSDecimalMultiply(NSDecimal* result,
                                                       const NSDecimal* leftOperand,
                                                       const NSDecimal* rightOperand,
                                                       NSRoundingMode roundingMode) STUB_METHOD;

FOUNDATION_EXPORT NSCalculationError NSDecimalDivide(NSDecimal* result,
                                                     const NSDecimal* leftOperand,
                                                     const NSDecimal* rightOperand,
                                                     NSRoundingMode roundingMode) STUB_METHOD;

FOUNDATION_EXPORT void NSDecimalRound(NSDecimal* result, const NSDecimal* number, NSInteger scale, NSRoundingMode roundingMode) STUB_METHOD;

#endif /* _NSDECIMAL_H_ */