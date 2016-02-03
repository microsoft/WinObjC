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
#pragma once

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>

@class NSString;
@class NSArray;
@class NSMutableDictionary;
@class NSPredicate;

typedef NSUInteger NSExpressionType;
enum {
    NSConstantValueExpressionType = 0,
    NSEvaluatedObjectExpressionType,
    NSVariableExpressionType,
    NSKeyPathExpressionType,
    NSFunctionExpressionType,
    NSUnionSetExpressionType,
    NSIntersectSetExpressionType,
    NSMinusSetExpressionType,
    NSSubqueryExpressionType = 13,
    NSAggregateExpressionType = 14,
    NSAnyKeyExpressionType = 15,
    NSBlockExpressionType = 19
};

FOUNDATION_EXPORT_CLASS
@interface NSExpression : NSObject <NSCopying, NSSecureCoding>
- (instancetype)initWithExpressionType:(NSExpressionType)type;
+ (NSExpression*)expressionWithFormat:(NSString*)expressionFormat, ...;
+ (NSExpression*)expressionWithFormat:(NSString*)expressionFormat argumentArray:(NSArray*)arguments;
+ (NSExpression*)expressionWithFormat:(NSString*)expressionFormat arguments:(va_list)argList;
+ (NSExpression*)expressionForConstantValue:(id)obj;
+ (NSExpression*)expressionForEvaluatedObject;
+ (NSExpression*)expressionForKeyPath:(NSString*)keyPath;
+ (NSExpression*)expressionForVariable:(NSString*)string;
+ (NSExpression*)expressionForAnyKey;
+ (NSExpression*)expressionForAggregate:(NSArray*)collection;
+ (NSExpression*)expressionForUnionSet:(NSExpression*)left with:(NSExpression*)right;
+ (NSExpression*)expressionForIntersectSet:(NSExpression*)left with:(NSExpression*)right;
+ (NSExpression*)expressionForMinusSet:(NSExpression*)left with:(NSExpression*)right;
+ (NSExpression*)expressionForSubquery:(NSExpression*)expression usingIteratorVariable:(NSString*)variable predicate:(id)predicate;
+ (NSExpression*)expressionForBlock:(id _Nonnull (^)(id, NSArray*, NSMutableDictionary*))block arguments:(NSArray*)arguments;
+ (NSExpression*)expressionForFunction:(NSString*)name arguments:(NSArray*)parameters;
+ (NSExpression*)expressionForFunction:(NSExpression*)target selectorName:(NSString*)name arguments:(NSArray*)parameters;
@property (readonly, copy) NSArray* arguments;
@property (readonly, retain) id collection;
@property (readonly, retain) id constantValue;
@property (readonly) NSExpressionType expressionType;
@property (readonly, copy) NSString* function;
@property (readonly, copy) NSString* keyPath;
@property (readonly, copy) NSExpression* operand;
@property (readonly, copy) NSPredicate* predicate;
@property (readonly, copy) NSExpression* leftExpression;
@property (readonly, copy) NSExpression* rightExpression;
@property (readonly, copy) NSString* variable;
- (id)expressionValueWithObject:(id)object context:(NSMutableDictionary*)context;
- (void)allowEvaluation;
@property (readonly, copy, nonnull) id (^expressionBlock)(id, NSArray*, NSMutableDictionary*);
@end
