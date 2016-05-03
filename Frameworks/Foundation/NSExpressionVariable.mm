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
#import <Foundation/NSDictionary.h>
#import <Foundation/NSExpression.h>
#import <Foundation/NSMutableDictionary.h>
#import "NSExpressionVariable.h"

@implementation NSExpressionVariable

/**
 @Status Interoperable
*/
- (id)initWithVariableName:(NSString*)name {
    if (self = [super initWithExpressionType:NSVariableExpressionType]) {
        _name = [name copy];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (id)initWithVariableName:(NSString*)name expression:(NSExpression*)value {
    if (self = [self initWithVariableName:name]) {
        _value = [value copy];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (id)expressionValueWithObject:(id)object context:(NSMutableDictionary*)context {
    id result = [context objectForKey:_name];

    // ensure basic non-expression type is returned.
    if ([result isKindOfClass:[NSExpression class]]) {
        return [result expressionValueWithObject:object context:context];
    }

    return result;
}

- (NSExpression*)expressionWithSubstitutionVariables:(NSDictionary*)variables {
    return [NSExpression expressionForConstantValue:[variables objectForKey:_name]];
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
    [encoder encodeObject:_name forKey:@"name"];
    [encoder encodeObject:_value forKey:@"value"];
    [super encodeWithCoder:encoder];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCoder:(NSCoder*)decoder {
    if (self = [super initWithCoder:decoder]) {
        _name = [[decoder decodeObjectOfClass:[NSString class] forKey:@"name"] retain];
        _value = [[decoder decodeObjectOfClass:[NSExpression class] forKey:@"value"] retain];
    }
    return self;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    [_name release];
    [_value release];
    [super dealloc];
}
@end