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
#import "StubReturn.h"
#import <Foundation/NSExpression.h>
#import "ExpressionHelpers.h"

@implementation NSExpression

/**
 @Status Stub
*/
- (instancetype)initWithExpressionType:(NSExpressionType)type {
    if (self = [super init]) {
        _expressionType = type;
    }
    return self;
}

/**
 @Status Stub
*/
+ (NSExpression*)expressionWithFormat:(NSString*)expressionFormat, ... {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Interoperable
*/
+ (NSExpression*)expressionForKeyPath:(NSString*)keyPath {
    return [[[NSExpressionKeyPath alloc] initWithKeyPath:keyPath] autorelease];
}

/**
 @Status Stub
*/
+ (NSExpression*)expressionWithFormat:(NSString*)expressionFormat argumentArray:(NSArray*)arguments {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
+ (NSExpression*)expressionWithFormat:(NSString*)expressionFormat arguments:(va_list)argList {
    UNIMPLEMENTED();
    return nil;
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
 @Status Stub
*/
- (id)expressionValueWithObject:(id)object context:(NSMutableDictionary*)context {
    UNIMPLEMENTED();
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
 @Status Cavet
 @Notes
*/
+ (BOOL)supportsSecureCoding {
    return YES;
}

/**
 @Status Cavet
 @Notes Only supported types are encoded by the derived classes.
*/
- (id)initWithCoder:(NSCoder*)decoder {
    if (self = [super initWithCoder:decoder]) {
        _expressionType = (NSExpressionType)[decoder decodeInt64ForKey:@"expressionType"];
    }

    return self;
}

/**
 @Status Cavet
 @Notes Only supported types are encoded by the derived classes.
*/
- (void)encodeWithCoder:(NSCoder*)coder {
    [coder encodeInt64:_expressionType forKey:@"expressionType"];
}

@end