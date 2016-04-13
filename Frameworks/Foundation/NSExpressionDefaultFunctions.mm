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

@implementation NSExpressionDefaultFunctions

// Future Support-TODO: Add functions for support, stddev, add, sub, etc.

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