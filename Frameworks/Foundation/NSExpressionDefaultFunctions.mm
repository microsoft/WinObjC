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

#import "NSExpressionDefaultFunctions.h"
#import <Foundation/NSArray.h>
#import <Foundation/NSException.h>

@implementation NSExpressionDefaultFunctions

// Future Support-VSO 7120732: Add functions for support, stddev etc.

// VSO 7120710: Switch to NSDecimalNumber when it's ready, it will do most of the work for us.

/**
 @Status Interoperable
*/
- (NSNumber*)sum:(NSArray*)values {
    double result = 0;

    for (id num in values) {
        result += [(NSNumber*)num doubleValue];
    }

    return [NSNumber numberWithDouble:result];
}

/**
 @Status Interoperable
*/
- (NSNumber*)plus:(NSNumber*)first second:(NSNumber*)second {
    return [NSNumber numberWithDouble:([first doubleValue] + [second doubleValue])];
}

/**
 @Status Interoperable
*/
- (NSNumber*)minus:(NSNumber*)first second:(NSNumber*)second {
    return [NSNumber numberWithDouble:([first doubleValue] - [second doubleValue])];
}

/**
 @Status Interoperable
*/
- (NSNumber*)multiply:(NSNumber*)first second:(NSNumber*)second {
    return [NSNumber numberWithDouble:([first doubleValue] * [second doubleValue])];
}

/**
 @Status Interoperable
*/
- (NSNumber*)divideBy:(NSNumber*)first second:(NSNumber*)second {
    return [NSNumber numberWithDouble:([first doubleValue] / [second doubleValue])];
}

/**
 @Status Interoperable
*/
- (NSNumber*)exp:(NSNumber*)base to:(NSNumber*)power {
    return [NSNumber numberWithDouble:(pow([base doubleValue], [power doubleValue]))];
}

- (id)copyWithZone:(NSZone*)zone {
    return [self retain];
}

/**
 @Status Interoperable
*/
- (NSDate*)now {
    return [NSDate date];
}

@end