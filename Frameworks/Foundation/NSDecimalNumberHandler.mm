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

#import <StubReturn.h>
#import <Foundation/NSDecimalNumberHandler.h>
#import <Foundation/NSDecimalNumber.h>
#import <Foundation/NSNumber.h>

@implementation NSDecimalNumberHandler {
    NSRoundingMode _roundingMode;
    short _scale;
    BOOL _raiseOnExactness;
    BOOL _raiseOnOverflow;
    BOOL _raiseOnUnderflow;
    BOOL _raiseOnDivideByZero;
}

/**
 @Status Interoperable
*/
+ (NSDecimalNumberHandler*)defaultDecimalNumberHandler {
    static NSDecimalNumberHandler* defaultHandler = [[NSDecimalNumberHandler alloc] initWithRoundingMode:NSRoundPlain
                                                                                                   scale:NSDecimalNoScale
                                                                                        raiseOnExactness:NO
                                                                                         raiseOnOverflow:YES
                                                                                        raiseOnUnderflow:YES
                                                                                     raiseOnDivideByZero:YES];
    return defaultHandler;
}

/**
 @Status Interoperable
*/
+ (instancetype)decimalNumberHandlerWithRoundingMode:(NSRoundingMode)roundingMode
                                               scale:(short)scale
                                    raiseOnExactness:(BOOL)raiseOnExactness
                                     raiseOnOverflow:(BOOL)raiseOnOverflow
                                    raiseOnUnderflow:(BOOL)raiseOnUnderflow
                                 raiseOnDivideByZero:(BOOL)raiseOnDivideByZero {
    return [[[NSDecimalNumberHandler alloc] initWithRoundingMode:roundingMode
                                                           scale:scale
                                                raiseOnExactness:raiseOnExactness
                                                 raiseOnOverflow:raiseOnOverflow
                                                raiseOnUnderflow:raiseOnUnderflow
                                             raiseOnDivideByZero:raiseOnDivideByZero] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithRoundingMode:(NSRoundingMode)roundingMode
                               scale:(short)scale
                    raiseOnExactness:(BOOL)raiseOnExactness
                     raiseOnOverflow:(BOOL)raiseOnOverflow
                    raiseOnUnderflow:(BOOL)raiseOnUnderflow
                 raiseOnDivideByZero:(BOOL)raiseOnDivideByZero {
    if (self = [super init]) {
        _roundingMode = roundingMode;
        _scale = scale;
        _raiseOnExactness = raiseOnExactness;
        _raiseOnOverflow = raiseOnOverflow;
        _raiseOnUnderflow = raiseOnUnderflow;
        _raiseOnDivideByZero = raiseOnDivideByZero;
    }

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCoder:(NSCoder*)decoder {
    if (self == [self init]) {
        _roundingMode = static_cast<NSRoundingMode>([decoder decodeInt64ForKey:@"NS.roundingMode"]);
        _scale = [[decoder decodeObjectOfClass:[NSNumber class] forKey:@"NS.scale"] shortValue];
        _raiseOnExactness = [decoder decodeBoolForKey:@"NS.raiseOnExactness"];
        _raiseOnOverflow = [decoder decodeBoolForKey:@"NS.raiseOnOverflow"];
        _raiseOnUnderflow = [decoder decodeBoolForKey:@"NS.raiseOnUnderflow"];
        _raiseOnDivideByZero = [decoder decodeBoolForKey:@"NS.raiseOnDivideByZero"];
    }
    return self;
}

/**
 @Status Interoperable
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    [encoder encodeInt64:_roundingMode forKey:@"NS.roundingMode"];
    [encoder encodeObject:[NSNumber numberWithShort:_scale] forKey:@"NS.scale"];
    [encoder encodeBool:_raiseOnExactness forKey:@"NS.raiseOnExactness"];
    [encoder encodeBool:_raiseOnOverflow forKey:@"NS.raiseOnOverflow"];
    [encoder encodeBool:_raiseOnUnderflow forKey:@"NS.raiseOnUnderflow"];
    [encoder encodeBool:_raiseOnDivideByZero forKey:@"NS.raiseOnDivideByZero"];
}

/**
 @Status Interoperable
*/
- (NSRoundingMode)roundingMode {
    return _roundingMode;
}

/**
 @Status Interoperable
*/
- (short)scale {
    return _scale;
}

/**
 @Status Interoperable
*/
- (NSDecimalNumber*)exceptionDuringOperation:(SEL)method
                                       error:(NSCalculationError)error
                                 leftOperand:(NSDecimalNumber*)leftOperand
                                rightOperand:(NSDecimalNumber*)rightOperand {
    switch (error) {
        case NSCalculationUnderflow:
            if (_raiseOnUnderflow) {
                [NSException raise:NSDecimalNumberUnderflowException format:@"NSDecimalNumber underflow"];
            }
            return [NSDecimalNumber notANumber];
        case NSCalculationOverflow:
            if (_raiseOnOverflow) {
                [NSException raise:NSDecimalNumberOverflowException format:@"NSDecimalNumber overflow"];
            }
            return [NSDecimalNumber notANumber];

        case NSCalculationLossOfPrecision:
            if (_raiseOnExactness) {
                [NSException raise:NSDecimalNumberExactnessException format:@"NSDecimalNumber exactness exception"];
            }
            return nil;
        case NSCalculationDivideByZero:
            if (_raiseOnDivideByZero) {
                [NSException raise:NSDecimalNumberDivideByZeroException format:@"Attempt to divide by 0"];
            }
            return [NSDecimalNumber notANumber];
    }

    return nil;
}

@end
