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
#import <Foundation/NSCompoundPredicate.h>

@implementation NSCompoundPredicate

/**
 @Status Interoperable
*/
- (instancetype)initWithType:(NSCompoundPredicateType)type subpredicates:(NSArray*)subpredicates {
    if (self = [super init]) {
        _compoundPredicateType = type;
        _subpredicates = [subpredicates copy];
    }

    return self;
}

/**
 @Status Interoperable
*/
+ (NSCompoundPredicate*)notPredicateWithSubpredicate:(NSPredicate*)predicate {
    return [[[[self class] alloc] initWithType:NSNotPredicateType subpredicates:[NSArray arrayWithObject:predicate]] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSCompoundPredicate*)andPredicateWithSubpredicates:(NSArray*)subpredicates {
    return [[[[self class] alloc] initWithType:NSAndPredicateType subpredicates:subpredicates] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSCompoundPredicate*)orPredicateWithSubpredicates:(NSArray*)subpredicates {
    return [[[[self class] alloc] initWithType:NSOrPredicateType subpredicates:subpredicates] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)predicateWithSubstitutionVariables:(NSDictionary*)variables {
    NSMutableArray* predicateWithSub = [NSMutableArray arrayWithCapacity:[_subpredicates count]];

    for (NSPredicate* predicate : _subpredicates) {
        id result = [predicate predicateWithSubstitutionVariables:variables];
        [predicateWithSub addObject:result];
    }

    return [[[[self class] alloc] initWithType:_compoundPredicateType subpredicates:predicateWithSub] autorelease];
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
- (instancetype)initWithCoder:(NSCoder*)decoder {
    if (self = [super initWithCoder:decoder]) {
        _subpredicates = [[decoder decodeObjectOfClass:[NSArray class] forKey:@"subpredicates"] retain];
        _compoundPredicateType = (NSCompoundPredicateType)[decoder decodeInt64ForKey:@"compoundPredicateType"];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    [super encodeWithCoder:encoder];
    [encoder encodeObject:_subpredicates forKey:@"subpredicates"];
    [encoder encodeInt64:_compoundPredicateType forKey:@"compoundPredicateType"];
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
    if ((_compoundPredicateType == NSAndPredicateType) && ([_subpredicates count] == 0)) {
        return YES;
    }

    BOOL result = NO;
    for (id predicate in _subpredicates) {
        result = [predicate evaluateWithObject:object substitutionVariables:variables];
        switch (_compoundPredicateType) {
            case NSNotPredicateType:
                return !result;

            case NSAndPredicateType:
                // short-circuit.
                if (!result) {
                    return NO;
                }
                break;

            case NSOrPredicateType:
                // short-circuit.
                if (result) {
                    return YES;
                }
                break;
        }
    }

    return result;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    [_subpredicates release];
    [super dealloc];
}

@end