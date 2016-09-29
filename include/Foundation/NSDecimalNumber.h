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
#pragma once

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>

#import <Foundation/NSNumber.h>
#import <Foundation/NSDecimal.h>

@class NSString;
@protocol NSDecimalNumberBehaviors;

FOUNDATION_EXPORT NSString* const NSDecimalNumberExactnessException;
FOUNDATION_EXPORT NSString* const NSDecimalNumberOverflowException;
FOUNDATION_EXPORT NSString* const NSDecimalNumberUnderflowException;
FOUNDATION_EXPORT NSString* const NSDecimalNumberDivideByZeroException;

FOUNDATION_EXPORT_CLASS
@interface NSDecimalNumber : NSNumber <NSCopying, NSSecureCoding>

+ (NSDecimalNumber*)one;
+ (NSDecimalNumber*)zero;
+ (NSDecimalNumber*)notANumber;
- (instancetype)initWithDecimal:(NSDecimal)decimal;
- (instancetype)initWithMantissa:(unsigned long long)mantissa exponent:(short)exponent isNegative:(BOOL)flag;

+ (NSDecimalNumber*)decimalNumberWithDecimal:(NSDecimal)decimal;
+ (NSDecimalNumber*)decimalNumberWithMantissa:(unsigned long long)mantissa exponent:(short)exponent isNegative:(BOOL)isNegative;
+ (NSDecimalNumber*)decimalNumberWithString:(NSString*)numericString STUB_METHOD;
+ (NSDecimalNumber*)decimalNumberWithString:(NSString*)numericString locale:(id)locale STUB_METHOD;

- (instancetype)initWithString:(NSString*)numericString STUB_METHOD;
- (instancetype)initWithString:(NSString*)numericString locale:(id)locale STUB_METHOD;

- (NSDecimalNumber*)decimalNumberByAdding:(NSDecimalNumber*)decimalNumber;
- (NSDecimalNumber*)decimalNumberBySubtracting:(NSDecimalNumber*)decimalNumber;
- (NSDecimalNumber*)decimalNumberByMultiplyingBy:(NSDecimalNumber*)decimalNumber STUB_METHOD;
- (NSDecimalNumber*)decimalNumberByDividingBy:(NSDecimalNumber*)decimalNumber STUB_METHOD;
- (NSDecimalNumber*)decimalNumberByRaisingToPower:(NSUInteger)power STUB_METHOD;
- (NSDecimalNumber*)decimalNumberByMultiplyingByPowerOf10:(short)power STUB_METHOD;
- (NSDecimalNumber*)decimalNumberByAdding:(NSDecimalNumber*)decimalNumber withBehavior:(id<NSDecimalNumberBehaviors>)behavior;
- (NSDecimalNumber*)decimalNumberBySubtracting:(NSDecimalNumber*)decimalNumber withBehavior:(id<NSDecimalNumberBehaviors>)behavior;
- (NSDecimalNumber*)decimalNumberByMultiplyingBy:(NSDecimalNumber*)decimalNumber
                                    withBehavior:(id<NSDecimalNumberBehaviors>)behavior STUB_METHOD;
- (NSDecimalNumber*)decimalNumberByDividingBy:(NSDecimalNumber*)decimalNumber
                                 withBehavior:(id<NSDecimalNumberBehaviors>)behavior STUB_METHOD;
- (NSDecimalNumber*)decimalNumberByRaisingToPower:(NSUInteger)power withBehavior:(id<NSDecimalNumberBehaviors>)behavior STUB_METHOD;
- (NSDecimalNumber*)decimalNumberByMultiplyingByPowerOf10:(short)power withBehavior:(id<NSDecimalNumberBehaviors>)behavior STUB_METHOD;
- (NSDecimalNumber*)decimalNumberByRoundingAccordingToBehavior:(id<NSDecimalNumberBehaviors>)behavior STUB_METHOD;
- (NSString*)descriptionWithLocale:(id)locale STUB_METHOD;
+ (void)setDefaultBehavior:(id<NSDecimalNumberBehaviors>)behavior STUB_METHOD;
- (NSComparisonResult)compare:(NSNumber*)decimalNumber;
+ (NSDecimalNumber*)maximumDecimalNumber;
+ (NSDecimalNumber*)minimumDecimalNumber;

@property (readonly) const char* objCType;
@property (readonly) NSDecimal decimalValue;
+ (id<NSDecimalNumberBehaviors>)defaultBehavior;
@end
