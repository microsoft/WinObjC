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

@implementation NSExpression

/**
 @Status Stub
*/
- (instancetype)initWithExpressionType:(NSExpressionType)type {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
+ (NSExpression*)expressionWithFormat:(NSString*)expressionFormat, ... {
    UNIMPLEMENTED();
    return nil;
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
 @Status Stub
*/
+ (NSExpression*)expressionForConstantValue:(id)obj {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
+ (NSExpression*)expressionForEvaluatedObject {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
+ (NSExpression*)expressionForKeyPath:(NSString*)keyPath {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
+ (NSExpression*)expressionForVariable:(NSString*)string {
    UNIMPLEMENTED();
    return nil;
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
 @Status Stub
*/
+ (NSExpression*)expressionForFunction:(NSString*)name arguments:(NSArray*)parameters {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
+ (NSExpression*)expressionForFunction:(NSExpression*)target selectorName:(NSString*)name arguments:(NSArray*)parameters {
    UNIMPLEMENTED();
    return nil;
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
 @Status Stub
 @Notes
*/
- (id)copyWithZone:(NSZone*)zone {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (BOOL)supportsSecureCoding {
    UNIMPLEMENTED();
    return StubReturn();
}

@end