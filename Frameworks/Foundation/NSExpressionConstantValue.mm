//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#import <Foundation/NSCoder.h>
#import <Foundation/NSException.h>
#import <Foundation/NSString.h>
#import "NSExpressionConstantValue.h"

@implementation NSExpressionConstantValue

/**
 @Status Interoperable
*/
- (id)initWithConstValue:(id)value {
    if (self = [super initWithExpressionType:NSConstantValueExpressionType]) {
        _value = [value copy];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (id)expressionValueWithObject:(id)object context:(NSMutableDictionary*)context {
    return _value;
}

- (NSExpression*) expressionWithSubstitutionVariables:(NSDictionary*)variables {
    return [[self copy] autorelease];
}

/**
 @Status Interoperable
*/
+ (BOOL)supportsSecureCoding {
    return YES;
}

/**
 @Status Interoperable
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    [encoder encodeObject:_value forKey:@"value"];
    [super encodeWithCoder:encoder];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCoder:(NSCoder*)decoder {
    if (self = [super initWithCoder:decoder]) {
        _value = [[decoder decodeObjectOfClass:[NSObject class] forKey:@"value"] retain];
    }
    return self;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    [_value release];
    [super dealloc];
}
@end