//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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
 @Status Stub
 @Notes
*/
- (instancetype)initWithCoder:(NSCoder*)decoder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    UNIMPLEMENTED();
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
 @Status Stub
 @Notes
*/
- (NSDecimalNumber*)exceptionDuringOperation:(SEL)method
                                       error:(NSCalculationError)error
                                 leftOperand:(NSDecimalNumber*)leftOperand
                                rightOperand:(NSDecimalNumber*)rightOperand {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
