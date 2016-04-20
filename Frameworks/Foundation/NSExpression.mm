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
#import <StubReturn.h>

#import "ExpressionHelpers.h"

@implementation NSExpression

/**
 @Status Interoperable
*/
- (instancetype)initWithExpressionType:(NSExpressionType)type {
    if (self = [super init]) {
        _expressionType = type;
    }
    return self;
}

/**
 @Status Interoperable
*/
+ (NSExpression*)expressionWithFormat:(NSString*)expressionFormat, ... {
    va_list args;
    va_start(args, expressionFormat);
    NSExpression* expression = [self expressionWithFormat:expressionFormat arguments:args];
    va_end(args);

    return expression;
}

/**
 @Status Interoperable
*/
+ (NSExpression*)expressionWithFormat:(NSString*)expressionFormat arguments:(va_list)argList {
    // Since NSPredicate parser uses NSExpression to build a NSComparisonPredicate,
    // we will just take the right side of the resulting NSComparisonPredicate
    NSPredicate* predicate = [NSPredicate predicateWithFormat:[NSString stringWithFormat:@"0 == %@", expressionFormat] arguments:argList];
    return [(NSComparisonPredicate*)predicate rightExpression];
}

/**
 @Status Interoperable
*/
+ (NSExpression*)expressionWithFormat:(NSString*)expressionFormat argumentArray:(NSArray*)arguments {
    // Since NSPredicate parser uses NSExpression to build a NSComparisonPredicate,
    // we will just take the right side of the resulting NSComparisonPredicate
    NSPredicate* predicate =
        [NSPredicate predicateWithFormat:[NSString stringWithFormat:@"0 == %@", expressionFormat] argumentArray:arguments];
    return [(NSComparisonPredicate*)predicate rightExpression];
}

/**
 @Status Interoperable
*/
+ (NSExpression*)expressionForKeyPath:(NSString*)keyPath {
    return [[[NSExpressionKeyPath alloc] initWithKeyPath:keyPath] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSExpression*)expressionForConstantValue:(id)obj {
    return [[[NSExpressionConstantValue alloc] initWithConstValue:obj] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSExpression*)expressionForEvaluatedObject {
    return [[[NSExpressionEvaluatedObject alloc] init] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSExpression*)expressionForVariable:(NSString*)string {
    return [[[NSExpressionVariable alloc] initWithVariableName:string] autorelease];
}

+ (NSExpression*)expressionForConstantValueTrue {
    return [NSExpression expressionForConstantValue:@YES];
}

+ (NSExpression*)expressionForConstantValueFalse {
    return [NSExpression expressionForConstantValue:@NO];
}

+ (NSExpression*)expressionforKeyValueAccess:(NSExpression*)rightExpression leftExpression:(NSExpression*)leftExpression {
    // must be in the form of SELF.x or a.b where both are KVC
    // if the left expression is SELF, then only right one matters for KVC
    if ([leftExpression isKindOfClass:[NSExpressionEvaluatedObject class]]) {
        if (![rightExpression isKindOfClass:[NSExpressionKeyPath class]]) {
            [NSException raise:NSGenericException
                        format:@"Not a valid expression for the following construct Expression.Expression, eg. self.foo"];
        }

        return rightExpression;
    }

    // Both expression should be KVC
    if (![rightExpression isKindOfClass:[NSExpressionKeyPath class]] || ![leftExpression isKindOfClass:[NSExpressionKeyPath class]]) {
        [NSException raise:NSGenericException
                    format:@"Not a valid expression for the following construct Expression.Expression, eg. bar.foo"];
    }

    return [self expressionForKeyPath:[NSString stringWithFormat:@"%@.%@", [leftExpression keyPath], [rightExpression keyPath]]];
}

- (NSExpression*)expressionWithSubstitutionVariables:(NSDictionary*)variables {
    // Sub classes should overwrite.
    return [[self copy] autorelease];
}

/**
 @Status Stub
*/
+ (NSExpression*)expressionForAnyKey {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
+ (NSExpression*)expressionForAggregate:(NSArray*)collection {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
+ (NSExpression*)expressionForUnionSet:(NSExpression*)left with:(NSExpression*)right {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
+ (NSExpression*)expressionForIntersectSet:(NSExpression*)left with:(NSExpression*)right {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
+ (NSExpression*)expressionForMinusSet:(NSExpression*)left with:(NSExpression*)right {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
+ (NSExpression*)expressionForSubquery:(NSExpression*)expression usingIteratorVariable:(NSString*)variable predicate:(id)predicate {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
+ (NSExpression*)expressionForBlock:(id (^)(id evaluatedObject, NSArray* expressions, NSMutableDictionary* context))block
                          arguments:(NSArray*)arguments {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Interoperable
*/
+ (NSExpression*)expressionForFunction:(NSString*)name arguments:(NSArray*)parameters {
    return [[[NSExpressionFunction alloc] initWithFunctionName:name arguments:parameters] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSExpression*)expressionForFunction:(NSExpression*)target selectorName:(NSString*)name arguments:(NSArray*)parameters {
    return [[[NSExpressionFunction alloc] initWithExpressionTarget:target selectorName:name arguments:parameters] autorelease];
}

/**
 @Status Interoperable
*/
- (id)expressionValueWithObject:(id)object context:(NSMutableDictionary*)context {
    // subclass will over write.
    return nil;
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
 @Status Caveat
 @Notes Only supported types are encoded by the derived classes.
*/
+ (BOOL)supportsSecureCoding {
    return YES;
}

/**
 @Status Caveat
 @Notes Only supported types are encoded by the derived classes.
*/
- (id)initWithCoder:(NSCoder*)decoder {
    _expressionType = (NSExpressionType)[decoder decodeInt64ForKey:@"expressionType"];

    return self;
}

/**
 @Status Caveat
 @Notes Only supported types are encoded by the derived classes.
*/
- (void)encodeWithCoder:(NSCoder*)coder {
    [coder encodeInt64:_expressionType forKey:@"expressionType"];
}

@end