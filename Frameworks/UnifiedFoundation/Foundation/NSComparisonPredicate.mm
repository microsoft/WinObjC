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
        _customSelector = selector;
    }

    return self;
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
 @Status Stub
*/
- (BOOL)evaluateWithObject:(id)object {
    UNIMPLEMENTED();
    return [self evaluateWithObject:object substitutionVariables:nil];
}

/**
 @Status Stub
*/
- (BOOL)evaluateWithObject:(id)object substitutionVariables:(NSDictionary*)variables {
    UNIMPLEMENTED();
    return NO;
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