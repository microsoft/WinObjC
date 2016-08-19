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

#import <Foundation/NSPredicate.h>
#import <Foundation/NSExpression.h>

typedef NSUInteger NSComparisonPredicateModifier;
typedef NSUInteger NSComparisonPredicateOptions;
typedef NSUInteger NSPredicateOperatorType;
enum {
    NSDirectPredicateModifier = 0,
    NSAllPredicateModifier,
    NSAnyPredicateModifier,
};

enum {
    NSCaseInsensitivePredicateOption = 0x01,
    NSDiacriticInsensitivePredicateOption = 0x02,
    NSNormalizedPredicateOption = 0x04,
    NSLocaleSensitivePredicateOption = 0x08
};

enum {
    NSLessThanPredicateOperatorType = 0,
    NSLessThanOrEqualToPredicateOperatorType,
    NSGreaterThanPredicateOperatorType,
    NSGreaterThanOrEqualToPredicateOperatorType,
    NSEqualToPredicateOperatorType,
    NSNotEqualToPredicateOperatorType,
    NSMatchesPredicateOperatorType,
    NSLikePredicateOperatorType,
    NSBeginsWithPredicateOperatorType,
    NSEndsWithPredicateOperatorType,
    NSInPredicateOperatorType,
    NSCustomSelectorPredicateOperatorType,
    NSContainsPredicateOperatorType,
    NSBetweenPredicateOperatorType
};

FOUNDATION_EXPORT_CLASS
@interface NSComparisonPredicate : NSPredicate <NSCopying, NSSecureCoding>
+ (NSComparisonPredicate*)predicateWithLeftExpression:(NSExpression*)lhs rightExpression:(NSExpression*)rhs customSelector:(SEL)selector;
+ (NSComparisonPredicate*)predicateWithLeftExpression:(NSExpression*)lhs
                                      rightExpression:(NSExpression*)rhs
                                             modifier:(NSComparisonPredicateModifier)modifier
                                                 type:(NSPredicateOperatorType)type
                                              options:(NSComparisonPredicateOptions)options;
- (instancetype)initWithLeftExpression:(NSExpression*)lhs rightExpression:(NSExpression*)rhs customSelector:(SEL)selector;
- (instancetype)initWithLeftExpression:(NSExpression*)lhs
                       rightExpression:(NSExpression*)rhs
                              modifier:(NSComparisonPredicateModifier)modifier
                                  type:(NSPredicateOperatorType)type
                               options:(NSComparisonPredicateOptions)options;
@property (readonly) NSComparisonPredicateModifier comparisonPredicateModifier;
@property (readonly) SEL customSelector;
@property (readonly, retain) NSExpression* rightExpression;
@property (readonly, retain) NSExpression* leftExpression;
@property (readonly) NSComparisonPredicateOptions options;
@property (readonly) NSPredicateOperatorType predicateOperatorType;
@end
