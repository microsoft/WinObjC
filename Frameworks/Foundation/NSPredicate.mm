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

#import <Starboard.h>
#import <Foundation/NSPredicate.h>
#import <Foundation/Foundation.h>
#import <Foundation/NSComparisonPredicate.h>

#import "NSBooleanPredicate.h"
#import "ExpressionHelpers.h"
#import "rules.tab.h"

extern "C" NSPredicate* _parsePredicateFormatString(NSString* format, nextArgument nextArg);

@implementation NSPredicate {
    BOOL (^_evaluationBlock)(id evaluatedObject, NSDictionary* bindings);
}

/**
 @Status Interoperable
*/
+ (NSPredicate*)predicateWithFormat:(NSString*)format, ... {
    va_list args;
    va_start(args, format);
    NSPredicate* predicate = [self predicateWithFormat:format arguments:args];
    va_end(args);

    return predicate;
}

/**
 @Status Interoperable
*/
+ (NSPredicate*)predicateWithFormat:(NSString*)format argumentArray:(NSArray*)arguments {
    NSEnumerator* enumerator = [arguments objectEnumerator];

    return _parsePredicateFormatString(format, ^id(NSString* type) {
        return [enumerator nextObject];
    });
}

/**
 @Status Interoperable
*/
+ (NSPredicate*)predicateWithFormat:(NSString*)format arguments:(va_list)arguments {
    __block va_list args = arguments;
    return _parsePredicateFormatString(format, ^NSExpression*(NSString* type) {
        if ([type isEqualToString:@"@"]) {
            return [NSExpression expressionForConstantValue:va_arg(args, id)];
        }

        if ([type isEqualToString:@"K"]) {
            // the attribute name must be a string.
            id obj = va_arg(args, id);
            if (![obj isKindOfClass:[NSString class]]) {
                [NSException raise:NSInvalidArgumentException format:@"Key path must be a string."];
            }
            return [NSExpression expressionForKeyPath:obj];
        }

        if ([type isEqualToString:@"i"] || [type isEqualToString:@"d"]) {
            return [NSExpression expressionForConstantValue:[NSNumber numberWithInt:va_arg(args, int)]];
        }

        if ([type compare:@"f" options:NSCaseInsensitiveSearch] == NSOrderedSame) {
            return [NSExpression expressionForConstantValue:[NSNumber numberWithFloat:va_arg(args, double)]];
        }
        return va_arg(args, id);
    });
}

/**
 @Status Interoperable
*/
+ (NSPredicate*)predicateWithValue:(BOOL)value {
    return [[[NSBooleanPredicate alloc] initWithValue:value] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSPredicate*)predicateWithBlock:(BOOL (^)(id evaluatedObject, NSDictionary* bindings))block {
    return [[[NSPredicate alloc] _initWithBlock:block] autorelease];
}

- (instancetype)_initWithBlock:(BOOL (^)(id evaluatedObject, NSDictionary* bindings))block {
    if (self = [super init]) {
        _evaluationBlock = [block copy];
    }
    return self;
}

/**
 @Status Interoperable
*/
- (BOOL)evaluateWithObject:(id)object {
    return [self evaluateWithObject:object substitutionVariables:nil];
}

/**
 @Status Interoperable
*/
- (BOOL)evaluateWithObject:(id)object substitutionVariables:(NSDictionary*)variables {
    // Subclasses over write this, to implement their evaluation.
    if (_evaluationBlock) {
        return _evaluationBlock(object, variables);
    }
    return NO;
}

/**
 @Status Interoperable
*/
- (instancetype)predicateWithSubstitutionVariables:(NSDictionary*)variables {
    return [[self copy] autorelease];
}

/**
 @Status Stub
*/
- (void)allowEvaluation {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (id)copyWithZone:(NSZone*)zone {
    return [self retain];
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
- (instancetype)initWithCoder:(NSCoder*)decoder {
    if (self = [super init]) {
        _predicateFormat = [[decoder decodeObjectOfClass:[NSString class] forKey:@"predicateFormat"] retain];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    if (_evaluationBlock) {
        THROW_NS_HR_MSG(E_FAIL, "NSPredicate with a block cannot be encoded.");
    }
    if (_predicateFormat) {
        [encoder encodeObject:_predicateFormat forKey:@"predicateFormat"];
    }
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    [_predicateFormat release];
    [_evaluationBlock release];
    [super dealloc];
}

@end
