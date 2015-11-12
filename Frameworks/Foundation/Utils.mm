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

#include "Foundation/Foundation.h"
#include "Foundation/NSArray.h"
#include "Foundation/NSPathUtilities.h"

/**
 @Status Interoperable
*/
NSRange NSMakeRange(NSUInteger location, NSUInteger length) {
    NSRange ret = { location, length };
    return ret;
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
NSUInteger NSMaxRange(NSRange range) {
    return range.location + range.length;
}

/**
 @Status Interoperable
*/
NSRange NSUnionRange(NSRange range1, NSRange range2) {
    NSRange ret = { 0, 0 };
    assert(0);
    return ret;
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
NSArray* NSSearchPathForDirectoriesInDomains(NSSearchPathDirectory dir, NSSearchPathDomainMask mask, BOOL tilde) {
    switch (dir) {
        case NSDocumentDirectory:
            return [NSArray arrayWithObject:@"/Documents/"];

        case NSApplicationDirectory:
            return [NSArray arrayWithObject:@"./"];

        case NSLibraryDirectory:
            return [NSArray arrayWithObject:@"/Library/"];

        case NSCachesDirectory:
            return [NSArray arrayWithObject:@"/Cache/"];

        case NSApplicationSupportDirectory:
            return [NSArray arrayWithObject:@"/AppSupport/"];

        case NSAllApplicationsDirectory:
            return [NSArray arrayWithObject:@"/"];

        default:
            assert(0);
            break;
    }

    return 0;
}

/**
 @Status Interoperable
*/
Class NSClassFromString(NSString* name) {
    return objc_lookup_class((const char*)[name UTF8String]);
}

/**
 @Status Interoperable
*/
SEL NSSelectorFromString(NSString* str) {
    return sel_registerName([str UTF8String]);
}

/**
 @Status Interoperable
*/
NSString* NSStringFromClass(Class cls) {
    if (!cls) {
        return nil;
    }
    return [NSString stringWithUTF8String:object_getClassName(cls)];
}

/**
 @Status Interoperable
*/
unsigned int NSSwapHostIntToBig(unsigned int val) {
    return ((val & 0xFF) << 24) | ((val & 0xFF00) << 8) | ((val & 0xFF0000) >> 8) | (val >> 24);
}

/**
 @Status Interoperable
*/
NSString* NSStringFromSelector(SEL sel) {
    NSString* ret = [NSString stringWithCString:sel_getName(sel)];
    return ret;
}

NSString* temporaryDirectory = @"/tmp";

/**
 @Status Interoperable
*/
NSString* NSTemporaryDirectory(void) {
    return temporaryDirectory;
}

/**
 @Status Interoperable
*/
void NSSetTemporaryDirectory(NSString* path) {
    temporaryDirectory = [path retain];
}
