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

#import <Foundation/NSAttributedString.h>
#import <Foundation/NSMutableAttributedString.h>
#import <CoreFoundation/CFAttributedString.h>
#import "NSRaise.h"
#import "NSCFAttributedString.h"
#import "BridgeHelpers.h"

#import <algorithm>

@implementation NSAttributedString

+ ALLOC_PROTOTYPE_SUBCLASS_WITH_ZONE(NSAttributedString, NSAttributedStringPrototype);

/**
 @Status Interoperable
*/
- (NSString*)string {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (id)attribute:(NSString*)name atIndex:(NSUInteger)location effectiveRange:(NSRange*)range {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSDictionary*)attributesAtIndex:(NSUInteger)location effectiveRange:(NSRange*)range {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (instancetype)initWithString:(NSString*)string {
    return [self initWithString:string attributes:[[NSDictionary new] autorelease]];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithAttributedString:(NSAttributedString*)string {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (instancetype)initWithString:(NSString*)string attributes:(NSDictionary*)attributes {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
 */
- (NSAttributedString*)attributedSubstringFromRange:(NSRange)range {
    NSMutableAttributedString* ret = [[NSMutableAttributedString alloc] initWithAttributedString:self];

    // delete section before the range
    [ret deleteCharactersInRange:NSMakeRange(0, range.location)];

    // delete section after the range
    // if done first, the range would be {range.location + range.length, [ret length] - (range.location + range.length)}
    // since the first delete reduces length by range.location, subtract range.location from both sides
    [ret deleteCharactersInRange:NSMakeRange(range.length, [ret length] - range.length)];

    return ret;
}

/**
 @Status Interoperable
*/
- (NSUInteger)length {
    return [[self string] length];
}

/**
 @Status Interoperable
*/
- (NSDictionary*)attributesAtIndex:(NSUInteger)location longestEffectiveRange:(NSRange*)range inRange:(NSRange)inRange {
    NSDictionary* ret = [self attributesAtIndex:location effectiveRange:range];
    if (range) {
        *range = NSIntersectionRange(*range, inRange);
    }
    return ret;
}

/**
 @Status Interoperable
*/
- (id)attribute:(NSString*)name atIndex:(NSUInteger)location longestEffectiveRange:(NSRange*)range inRange:(NSRange)inRange {
    id ret = [self attribute:name atIndex:location effectiveRange:range];
    if (range) {
        *range = NSIntersectionRange(*range, inRange);
    }
    return ret;
}

/**
 @Status Interoperable
 */
- (BOOL)isEqualToAttributedString:(NSAttributedString*)otherString {
    if (![[self string] isEqual:[otherString string]]) {
        // Compare string content
        return NO;

    } else {
        // Compare attributes
        NSRange selfRange;
        NSRange otherRange;
        NSUInteger index = 0;
        NSUInteger length = [self length];

        while (index < length) {
            NSDictionary* selfAttributes = [self attributesAtIndex:index effectiveRange:&selfRange];
            NSDictionary* otherAttributes = [otherString attributesAtIndex:index effectiveRange:&otherRange];

            if (!(NSEqualRanges(selfRange, otherRange) && [selfAttributes isEqual:otherAttributes])) {
                return NO;
            }

            index += selfRange.length;
        }
    }
    return YES;
}

// Traits struct for generically calling either [self attribute:] or [self attributesAtIndex:]
template <typename TEnumerationUnit>
struct EnumerationTraits;

template <>
struct EnumerationTraits<id> {
    static id getUnitWithLongestEffectiveRange(
        NSAttributedString* self, NSString* attrName, NSUInteger location, NSRange* range, NSRange inRange) {
        return [self attribute:attrName atIndex:location longestEffectiveRange:range inRange:inRange];
    }

    static id getUnitWithoutLongestEffectiveRange(NSAttributedString* self, NSString* attrName, NSUInteger location, NSRange* range) {
        return [self attribute:attrName atIndex:location effectiveRange:range];
    }

    static BOOL valid(id self) {
        return (self != nil);
    }
};

template <>
struct EnumerationTraits<NSDictionary*> {
    static NSDictionary* getUnitWithLongestEffectiveRange(
        NSAttributedString* self, NSString* attrName, NSUInteger location, NSRange* range, NSRange inRange) {
        return [self attributesAtIndex:location longestEffectiveRange:range inRange:inRange];
    }

    static NSDictionary* getUnitWithoutLongestEffectiveRange(NSAttributedString* self,
                                                             NSString* attrName,
                                                             NSUInteger location,
                                                             NSRange* range) {
        return [self attributesAtIndex:location effectiveRange:range];
    }

    static BOOL valid(NSDictionary* self) {
        return (self) && ([self count] > 0);
    }
};

// Internal helper for code reuse between enumerateAttribute: and enumerateAttributesInRange:
template <typename TEnumerationUnit>
static void _enumerateInRange(NSAttributedString* self,
                              NSString* attrName,
                              NSRange enumerationRange,
                              NSAttributedStringEnumerationOptions opts,
                              void (^block)(TEnumerationUnit, NSRange, BOOL*)) {
    bool reverse = opts & NSAttributedStringEnumerationReverse;
    bool longestEffectiveRangeNotRequired = opts & NSAttributedStringEnumerationLongestEffectiveRangeNotRequired;

    NSUInteger currentIndex =
        reverse ? std::min(enumerationRange.location + enumerationRange.length, [self length]) - 1 : enumerationRange.location;

    NSUInteger prevLength = [self length];
    NSUInteger lengthDiff = 0;
    NSRange currentRange;
    TEnumerationUnit currentUnit;
    BOOL stop = NO;

    while (NSLocationInRange(currentIndex, enumerationRange)) {
        lengthDiff = 0;

        if (longestEffectiveRangeNotRequired) {
            currentUnit =
                EnumerationTraits<TEnumerationUnit>::getUnitWithoutLongestEffectiveRange(self, attrName, currentIndex, &currentRange);
        } else {
            currentUnit = EnumerationTraits<TEnumerationUnit>::getUnitWithLongestEffectiveRange(self,
                                                                                                attrName,
                                                                                                currentIndex,
                                                                                                &currentRange,
                                                                                                enumerationRange);
        }

        if (EnumerationTraits<TEnumerationUnit>::valid(currentUnit) && block) {
            block(currentUnit, currentRange, &stop);

            // handle length changes by block
            NSUInteger currentLength = [self length];
            if (prevLength != currentLength) {
                lengthDiff = currentLength - prevLength;
                prevLength = currentLength;
            }

            if (stop) {
                break;
            }
        }

        if (reverse) {
            currentIndex -= currentRange.length;
            enumerationRange.length += lengthDiff;
        } else {
            currentIndex += (currentRange.length + lengthDiff);
            enumerationRange.length += lengthDiff;
        }

        if (currentRange.length == 0) {
            break;
        }
    }
}

/**
 @Status Interoperable
 */
- (void)enumerateAttribute:(NSString*)attrName
                   inRange:(NSRange)enumerationRange
                   options:(NSAttributedStringEnumerationOptions)opts
                usingBlock:(void (^)(id value, NSRange range, BOOL* stop))block {
    _enumerateInRange(self, attrName, enumerationRange, opts, block);
}

/**
 @Status Interoperable
 */
- (void)enumerateAttributesInRange:(NSRange)enumerationRange
                           options:(NSAttributedStringEnumerationOptions)opts
                        usingBlock:(void (^)(NSDictionary* attrs, NSRange range, BOOL* stop))block {
    _enumerateInRange(self, nil, enumerationRange, opts, block);
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
- (id)mutableCopyWithZone:(NSZone*)zone {
    NSMutableAttributedString* ret =
        [self isKindOfClass:[NSMutableAttributedString class]] ? [[self class] new] : [NSMutableAttributedString new];
    [ret appendAttributedString:self];
    return ret;
}

/**
 @Status Stub
 */
- (instancetype)initWithCoder:(NSCoder*)decoder {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
 */
- (void)encodeWithCoder:(NSCoder*)encoder {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 */
+ (BOOL)supportsSecureCoding {
    UNIMPLEMENTED();
    return NO;
}

@end
