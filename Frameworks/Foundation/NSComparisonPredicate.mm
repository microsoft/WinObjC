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
#import <Foundation/NSComparisonPredicate.h>

@implementation NSComparisonPredicate

/**
 @Status Interoperable
*/
+ (NSComparisonPredicate*)predicateWithLeftExpression:(NSExpression*)lhs rightExpression:(NSExpression*)rhs customSelector:(SEL)selector {
    return [[[self alloc] initWithLeftExpression:lhs rightExpression:rhs customSelector:selector] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSComparisonPredicate*)predicateWithLeftExpression:(NSExpression*)lhs
                                      rightExpression:(NSExpression*)rhs
                                             modifier:(NSComparisonPredicateModifier)modifier
                                                 type:(NSPredicateOperatorType)type
                                              options:(NSComparisonPredicateOptions)options {
    return [[[self alloc] initWithLeftExpression:lhs rightExpression:rhs modifier:modifier type:type options:options] autorelease];
}

- (instancetype)_initWithLeftExpression:(NSExpression*)lhs rightExpression:(NSExpression*)rhs {
    if (self = [super init]) {
        _leftExpression = [lhs retain];
        _rightExpression = [rhs retain];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithLeftExpression:(NSExpression*)lhs
                       rightExpression:(NSExpression*)rhs
                              modifier:(NSComparisonPredicateModifier)modifier
                                  type:(NSPredicateOperatorType)type
                               options:(NSComparisonPredicateOptions)options {
    if (self = [self _initWithLeftExpression:lhs rightExpression:rhs]) {
        _predicateOperatorType = type;
        _comparisonPredicateModifier = modifier;
        _options = options;
    }

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithLeftExpression:(NSExpression*)lhs rightExpression:(NSExpression*)rhs customSelector:(SEL)selector {
    if (self = [self _initWithLeftExpression:lhs rightExpression:rhs]) {
        _predicateOperatorType = NSCustomSelectorPredicateOperatorType;
        _comparisonPredicateModifier = NSDirectPredicateModifier;
        _customSelector = selector;
    }

    return self;
}

- (BOOL)_checkCollectionsContainerForRightResult:(id)leftResult rightResult:(id)rightResult {
    // Only NSSets, NSArrays and NSDictionary
    if ([rightResult isKindOfClass:[NSArray class]] || [rightResult isKindOfClass:[NSSet class]]) {
        return [rightResult containsObject:leftResult];
    }

    if ([rightResult isKindOfClass:[NSDictionary class]]) {
        return [[rightResult allKeysForObject:leftResult] count] > 0;
    }

    return NO;
}

- (BOOL)_areResultsStrings:(id)leftResult rightResult:(id)rightResult {
    return ([leftResult isKindOfClass:[NSString class]] && [rightResult isKindOfClass:[NSString class]]);
}

- (NSStringCompareOptions)obtainStringCompareOptionsWithComparisonPredicateOptions:(NSComparisonPredicateOptions)options {
    switch (options) {
        case NSCaseInsensitivePredicateOption:
            return NSCaseInsensitiveSearch;
        case NSDiacriticInsensitivePredicateOption:
            return NSDiacriticInsensitiveSearch;
        // For the two below need to verify on reference platform.
        case NSNormalizedPredicateOption:
        case NSLocaleSensitivePredicateOption:
        default:
            break;
    }

    return NSCaseInsensitiveSearch;
}

- (BOOL)_InContainsPredicate:(id)leftResult rightResult:(id)rightResult {
    if (rightResult == nil) {
        return NO;
    }

    if ([self _checkCollectionsContainerForRightResult:leftResult rightResult:rightResult]) {
        return YES;
    }

    if ([self _areResultsStrings:leftResult rightResult:rightResult]) {
        // Ensure NSComparisonPredicateOptions options are met. _comparisonPredicateModifier
        NSComparisonPredicateOptions option = [self obtainStringCompareOptionsWithComparisonPredicateOptions:_comparisonPredicateModifier];
        return [rightResult rangeOfString:leftResult options:static_cast<NSStringCompareOptions>(option)].location != NSNotFound;
    }

    return NO;
}

- (BOOL)_betweenPredicate:(id)leftResult rightResult:(id)rightResult {
    // [lhs between rhs]
    if ((leftResult == nil) || (rightResult == nil) || (![rightResult isKindOfClass:[NSArray class]]) || ([rightResult count] != 2)) {
        return NO;
    }

    NSArray* limits = (NSArray*)rightResult;

    NSComparisonResult lowerResult = [leftResult compare:limits[0]];
    NSComparisonResult upperLimit = [leftResult compare:limits[1]];

    // rhs[0] <= lhs <= rhs[1]
    if (((lowerResult == NSOrderedDescending) || (lowerResult == NSOrderedSame)) &&
        ((upperLimit == NSOrderedAscending) || (upperLimit == NSOrderedSame))) {
        return YES;
    }

    return NO;
}

/**
 @Status Stub
*/
- (BOOL)_matchesLikePredicate:(id)leftResult rightResult:(id)rightResult {
    if (![self _areResultsStrings:leftResult rightResult:rightResult]) {
        return NO;
    }

    // TODO: Regex eval needs to be done. Like is a subset of Matches with simple regex.
    UNIMPLEMENTED();
    return NO;
}

- (BOOL)_directComparisonOfExpressionsWithObject:(id)leftResult rightResult:(id)rightResult {
    // TODO: need to check behaviour for if one of them is null or both of them are null.

    switch (_predicateOperatorType) {
        case NSLessThanPredicateOperatorType:
            return ([leftResult compare:rightResult] == NSOrderedAscending);

        case NSLessThanOrEqualToPredicateOperatorType: {
            NSComparisonResult result = [leftResult compare:rightResult];
            return ((result == NSOrderedAscending) || (result == NSOrderedSame));
        }

        case NSGreaterThanPredicateOperatorType:
            return ([leftResult compare:rightResult] == NSOrderedDescending);

        case NSGreaterThanOrEqualToPredicateOperatorType: {
            NSComparisonResult result = [leftResult compare:rightResult];
            return ((result == NSOrderedDescending) || (result == NSOrderedSame));
        }

        case NSEqualToPredicateOperatorType:
            return [leftResult isEqual:rightResult];

        case NSNotEqualToPredicateOperatorType:
            return ![leftResult isEqual:rightResult];

        case NSBeginsWithPredicateOperatorType: {
            NSStringCompareOptions compareOption =
                [self obtainStringCompareOptionsWithComparisonPredicateOptions:_comparisonPredicateModifier];
            return ([leftResult rangeOfString:rightResult options:static_cast<NSStringCompareOptions>(NSAnchoredSearch | compareOption)]
                        .location != NSNotFound);
        }
        case NSEndsWithPredicateOperatorType: {
            NSStringCompareOptions compareOption =
                [self obtainStringCompareOptionsWithComparisonPredicateOptions:_comparisonPredicateModifier];
            return ([leftResult rangeOfString:rightResult options:static_cast<NSStringCompareOptions>(NSBackwardsSearch | compareOption)]
                        .location != NSNotFound);
        }
        case NSInPredicateOperatorType:
            // check if right contains left
            return [self _InContainsPredicate:leftResult rightResult:rightResult];

        case NSContainsPredicateOperatorType:
            // Note here we do, if left contains right.
            return [self _InContainsPredicate:rightResult rightResult:leftResult];

        case NSCustomSelectorPredicateOperatorType: {
            // TODO: Need to verify edge cases etc.
            if ([leftResult respondsToSelector:_customSelector]) {
                return (BOOL)[leftResult performSelector:_customSelector withObject:rightResult];
            }
            [NSException raise:NSInvalidArgumentException format:@"Left expression does not respond to selector."];
        }
        case NSBetweenPredicateOperatorType:
            return [self _betweenPredicate:leftResult rightResult:rightResult];
        case NSMatchesPredicateOperatorType:
            return [self _matchesLikePredicate:leftResult rightResult:rightResult];
        case NSLikePredicateOperatorType:
            return [self _matchesLikePredicate:leftResult rightResult:rightResult];
        default:
            break;
    }

    return NO;
}

- (BOOL)_anyAllExpressionsWithObject:(id)leftResult rightResult:(id)rightResult object:(id)object context:(NSMutableDictionary*)context {
    // left is either a set or array.
    // TODO: Add support for NSOrderedSet when ready.

    if ((leftResult == nil) || (![leftResult isKindOfClass:[NSArray class]] && ![leftResult isKindOfClass:[NSSet class]])) {
        return NO;
    }

    NSArray* objects = [leftResult isKindOfClass:[NSSet class]] ? [leftResult allObjects] : leftResult;

    for (id obj in objects) {
        if ([obj isKindOfClass:[NSExpression class]]) {
            // Ensure we are down to a result id (Only one layer).
            obj = [obj expressionValueWithObject:object context:context];
        }

        BOOL result = [self _directComparisonOfExpressionsWithObject:obj rightResult:rightResult];

        if ((_comparisonPredicateModifier == NSAnyPredicateModifier) && (result)) {
            // If it's ANY and one of the results is a YES.
            return YES;
        }

        if ((_comparisonPredicateModifier == NSAllPredicateModifier) && (!result)) {
            // If it's ALL and one of the results is a NO.
            return NO;
        }
    }

    return YES;
}

/**
 @Status Caveat
 @Notes: The following are not supported as of now: NSMatchesPredicateOperatorType & NSLikePredicateOperatorType.
*/
- (BOOL)evaluateWithObject:(id)object {
    return [self evaluateWithObject:object substitutionVariables:nil];
}

/**
 @Status Caveat
 @Notes: The following are not supported as of now: NSMatchesPredicateOperatorType & NSLikePredicateOperatorType.
*/
- (BOOL)evaluateWithObject:(id)object substitutionVariables:(NSDictionary*)variables {
    NSMutableDictionary* vars = (NSMutableDictionary*)variables;

    id leftResult = [_leftExpression expressionValueWithObject:object context:vars];
    id rightResult = [_rightExpression expressionValueWithObject:object context:vars];

    switch (_comparisonPredicateModifier) {
        case NSDirectPredicateModifier:
            return [self _directComparisonOfExpressionsWithObject:leftResult rightResult:rightResult];
        case NSAllPredicateModifier:
        case NSAnyPredicateModifier:
            return [self _anyAllExpressionsWithObject:leftResult rightResult:rightResult object:object context:vars];
        default:
            break;
    }
    return NO;
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
    if (self = [super initWithCoder:decoder]) {
        _leftExpression = [[decoder decodeObjectOfClass:[NSExpression class] forKey:@"leftExpression"] retain];
        _rightExpression = [[decoder decodeObjectOfClass:[NSExpression class] forKey:@"rightExpression"] retain];
        _predicateOperatorType = (NSPredicateOperatorType)[decoder decodeInt64ForKey:@"predicateOperatorType"];
        _comparisonPredicateModifier = (NSComparisonPredicateModifier)[decoder decodeInt64ForKey:@"comparisonPredicateModifier"];
        _options = (NSComparisonPredicateOptions)[decoder decodeInt64ForKey:@"options"];

        NSString* selectorString = [decoder decodeObjectOfClass:[NSString class] forKey:@"customSelector"];
        if (selectorString) {
            _customSelector = NSSelectorFromString(selectorString);
        }
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    [super encodeWithCoder:encoder];
    [encoder encodeObject:_leftExpression forKey:@"leftExpression"];
    [encoder encodeObject:_rightExpression forKey:@"rightExpression"];
    [encoder encodeInt64:_predicateOperatorType forKey:@"predicateOperatorType"];
    [encoder encodeInt64:_comparisonPredicateModifier forKey:@"comparisonPredicateModifier"];
    [encoder encodeInt64:_options forKey:@"options"];

    if (_customSelector) {
        [encoder encodeObject:NSStringFromSelector(_customSelector) forKey:@"customSelector"];
    }
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    [_leftExpression release];
    [_rightExpression release];
    [super dealloc];
}

@end