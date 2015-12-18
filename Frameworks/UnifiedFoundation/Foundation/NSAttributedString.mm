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
#import <CoreFoundation/CFAttributedString.h>

#import <algorithm>
#import "Starboard.h"

@implementation NSAttributedString

+ (instancetype)allocWithZone:(NSZone*)zone {
    if ((self == [NSAttributedString class]) || (self == [NSMutableAttributedString class])) {
        return (__bridge NSAttributedString*)_CFAttributedStringCreateEmpty();
    }

    return NSAllocateObject((Class)self, 0, zone);
}

/**
 @Status Interoperable
*/
- (instancetype)initWithString:(NSString*)string {
    [reinterpret_cast<NSMutableAttributedString*>(self) replaceCharactersInRange:NSMakeRange(0, 0) withString:string];
    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithAttributedString:(NSAttributedString*)string {
    [reinterpret_cast<NSMutableAttributedString*>(self) setAttributedString:string];
    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithString:(NSString*)string attributes:(NSDictionary*)attributes {
    [reinterpret_cast<NSMutableAttributedString*>(self) replaceCharactersInRange:NSMakeRange(0, 0) withString:string];
    [reinterpret_cast<NSMutableAttributedString*>(self) setAttributes:attributes range:NSMakeRange(0, [self length])];
    return self;
}

/**
 @Status Interoperable
 */
- (NSAttributedString*)attributedSubstringFromRange:(NSRange)range {
    NSAttributedString* ret =
        (__bridge NSAttributedString*)CFAttributedStringCreateWithSubstring(nullptr,
                                                                            reinterpret_cast<CFAttributedStringRef>(self),
                                                                            CFRangeMake(range.location, range.length));
    return [ret autorelease];
}

/**
 @Status Interoperable
*/
- (NSString*)string {
    return (__bridge NSString*)CFAttributedStringGetString(reinterpret_cast<CFAttributedStringRef>(self));
}

/**
 @Status Interoperable
*/
- (NSUInteger)length {
    return CFAttributedStringGetLength(reinterpret_cast<CFAttributedStringRef>(self));
}

/**
 @Status Interoperable
*/
- (NSDictionary*)attributesAtIndex:(NSUInteger)location effectiveRange:(NSRange*)range {
    CFRange outRange;
    NSDictionary* returnValue = (__bridge NSDictionary*)CFAttributedStringGetAttributes(reinterpret_cast<CFAttributedStringRef>(self),
                                                                                        location,
                                                                                        (range) ? &outRange : nullptr);
    if (range) {
        *range = NSMakeRange(outRange.location, outRange.length);
    }

    return returnValue;
}

/**
 @Status Interoperable
*/
- (NSDictionary*)attributesAtIndex:(NSUInteger)location longestEffectiveRange:(NSRange*)range inRange:(NSRange)inRange {
    CFRange outRange;
    NSDictionary* returnValue =
        (__bridge NSDictionary*)CFAttributedStringGetAttributesAndLongestEffectiveRange(reinterpret_cast<CFAttributedStringRef>(self),
                                                                                        location,
                                                                                        CFRangeMake(inRange.location, inRange.length),
                                                                                        (range) ? &outRange : nullptr);
    if (range) {
        *range = NSMakeRange(outRange.location, outRange.length);
    }

    return returnValue;
}

/**
 @Status Interoperable
*/
- (id)attribute:(NSString*)name atIndex:(NSUInteger)location effectiveRange:(NSRange*)range {
    CFRange outRange;

    id returnValue = (__bridge id)CFAttributedStringGetAttribute(reinterpret_cast<CFAttributedStringRef>(self),
                                                                 location,
                                                                 (__bridge CFStringRef)name,
                                                                 (range) ? &outRange : nullptr);
    if (range) {
        *range = NSMakeRange(outRange.location, outRange.length);
    }

    return returnValue;
}

/**
 @Status Interoperable
*/
- (id)attribute:(NSString*)name atIndex:(NSUInteger)location longestEffectiveRange:(NSRange*)range inRange:(NSRange)inRange {
    CFRange outRange;
    id returnValue = (__bridge id)CFAttributedStringGetAttributeAndLongestEffectiveRange(reinterpret_cast<CFAttributedStringRef>(self),
                                                                                         location,
                                                                                         (__bridge CFStringRef)name,
                                                                                         CFRangeMake(inRange.location, inRange.length),
                                                                                         (range) ? &outRange : nullptr);
    if (range) {
        *range = NSMakeRange(outRange.location, outRange.length);
    }

    return returnValue;
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

    NSUInteger enumerationBegin = std::max(0u, enumerationRange.location);
    NSUInteger enumerationEnd = std::min(enumerationRange.location + enumerationRange.length, [self length] - 1);

    if (reverse) {
        std::swap(enumerationBegin, enumerationEnd);

        // adjust for past-the-end
        enumerationBegin -= 1;
        enumerationEnd -= 1;
    }

    NSUInteger currentIndex = enumerationBegin;
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

        if (currentUnit && block) {
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
    return reinterpret_cast<id>(CFAttributedStringCreateCopy(nullptr, reinterpret_cast<CFAttributedStringRef>(self)));
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
