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

#include "Starboard.h"
#include "Foundation/NSRange.h"

/**
@Status Interoperable
*/
NSUInteger NSMaxRange(NSRange range) {
    return range.location + range.length;
}

/**
@Status Interoperable
*/
BOOL NSEqualRanges(NSRange range1, NSRange range2) {
    return ((range1.location == range2.location) && (range1.length == range2.length));
}

/**
@Status Interoperable
*/
static BOOL NSLocationInRange(NSUInteger idx, NSRange r) {
    return (idx >= r.location && idx < r.location + r.length);
}

/**
 @Status Interoperable
*/
NSString* NSStringFromRange(NSRange range) {
    return [NSString stringWithFormat:@"{%lu, %lu}", (unsigned long)range.location, (unsigned long)range.length];
}

/**
 @Status Interoperable
*/
NSRange NSRangeFromString(NSString* s) {
    static NSCharacterSet* trimChars = [NSCharacterSet characterSetWithCharactersInString:@"{}- "];

    // Valid string begins with '{' and ends with '}'
    if ([s characterAtIndex:0] == '{' && [s characterAtIndex:([s length] - 1)] == '}') {
        NSArray* components = [s componentsSeparatedByString:@","];

        // The two components are position and length - any other number of components is invalid.
        if ([components count] != 2) {
            return NSMakeRange(0, 0);
        }

        unsigned long long position;
        NSScanner* scanner = [NSScanner scannerWithString:[components[0] stringByTrimmingCharactersInSet:trimChars]];
        if (![scanner scanUnsignedLongLong:&position]) {
            return NSMakeRange(0, 0);
        }

        unsigned long long length;
        scanner = [NSScanner scannerWithString:[components[1] stringByTrimmingCharactersInSet:trimChars]];
        if (![scanner scanUnsignedLongLong:&length]) {
            return NSMakeRange(0, 0);
        }

        return NSMakeRange(position, length);
    }

    return NSMakeRange(0, 0);
}

/**
@Status Interoperable
*/
NSRange NSIntersectionRange(NSRange first, NSRange second) {
    NSUInteger min, loc, max1 = NSMaxRange(first), max2 = NSMaxRange(second);
    NSRange result;

    min = (max1 < max2) ? max1 : max2;
    loc = (first.location > second.location) ? first.location : second.location;

    if (min < loc) {
        result.location = result.length = 0;
    } else {
        result.location = loc;
        result.length = min - loc;
    }

    return result;
}

/**
@Status Interoperable
*/
NSRange NSUnionRange(NSRange range1, NSRange range2) {
    NSRange result;
    result.location = MIN(range1.location, range2.location);
    NSUInteger maximum = MAX(NSMaxRange(range1), NSMaxRange(range2));
    result.length = maximum - result.location;

    return result;
}
