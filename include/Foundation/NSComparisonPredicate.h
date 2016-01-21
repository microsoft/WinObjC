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

#ifndef _NSCOMPARISONPREDICATE_H_
#define _NSCOMPARISONPREDICATE_H_

#import <Foundation/NSPredicate.h>

@class NSExpression;

typedef NS_ENUM(NSInteger, NSPredicateOperatorType) {
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

typedef NS_ENUM(NSInteger, NSComparisonPredicateOptions) {
    NSCaseInsensitivePredicateOption = 0x01,
    NSDiacriticInsensitivePredicateOption = 0x02,
    NSNormalizedPredicateOption = 0x04,
    NSLocaleSensitivePredicateOption = 0x08
};

typedef NS_ENUM(NSInteger, NSComparisonPredicateModifier) {
    NSDirectPredicateModifier = 0,
    NSAllPredicateModifier,
    NSAnyPredicateModifier,
};

FOUNDATION_EXPORT_CLASS
@interface NSComparisonPredicate : NSPredicate <NSSecureCoding, NSCopying>

+ (NSComparisonPredicate*)predicateWithLeftExpression:(NSExpression*)lhs rightExpression:(NSExpression*)rhs customSelector:(SEL)selector;

+ (NSComparisonPredicate*)predicateWithLeftExpression:(NSExpression*)lhs
                                      rightExpression:(NSExpression*)rhs
                                             modifier:(NSComparisonPredicateModifier)modifier
                                                 type:(NSPredicateOperatorType)type
                                              options:(NSComparisonPredicateOptions)options;

- (instancetype)initWithLeftExpression:(NSExpression*)lhs
                       rightExpression:(NSExpression*)rhs
                              modifier:(NSComparisonPredicateModifier)modifier
                                  type:(NSPredicateOperatorType)type
                               options:(NSComparisonPredicateOptions)options;

- (instancetype)initWithLeftExpression:(NSExpression*)lhs rightExpression:(NSExpression*)rhs customSelector:(SEL)selector;

@property (readonly, retain) NSExpression* leftExpression;
@property (readonly, retain) NSExpression* rightExpression;
@property (readonly) NSPredicateOperatorType predicateOperatorType;
@property (readonly) NSComparisonPredicateModifier comparisonPredicateModifier;
@property (readonly) NSComparisonPredicateOptions options;
@property (readonly) SEL customSelector;

@end

#endif /* _NSCOMPARISONPREDICATE_H_ */