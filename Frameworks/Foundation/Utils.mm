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

NSRange NSMakeRange(NSUInteger location, NSUInteger length) {
    NSRange ret = { location, length };
    return ret;
}

NSRange NSIntersectionRange(NSRange first, NSRange second) {
    NSUInteger min, loc, max1 = NSMaxRange(first), max2 = NSMaxRange(second);
    NSRange result;

    min = (max1 < max2) ? max1 : max2;
    loc = (first.location > second.location) ? first.location : second.location;

    if (min < loc)
        result.location = result.length = 0;
    else {
        result.location = loc;
        result.length = min - loc;
    }

    return result;
}

NSUInteger NSMaxRange(NSRange range) {
    return range.location + range.length;
}

NSRange NSUnionRange(NSRange range1, NSRange range2) {
    NSRange ret = { 0, 0 };
    assert(0);
    return ret;
}

BOOL NSEqualRanges(NSRange range1, NSRange range2) {
    return ((range1.location == range2.location) && (range1.length == range2.length));
}

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

Class NSClassFromString(NSString* name) {
    return objc_lookup_class((const char*)[name UTF8String]);
}

SEL NSSelectorFromString(NSString* str) {
    return sel_registerName([str UTF8String]);
}

NSString *NSStringFromClass(Class cls) {
    if (!cls)
        return nil;
    return [NSString stringWithUTF8String: object_getClassName(cls)];
}

unsigned int NSSwapHostIntToBig(unsigned int val) {
    return ((val & 0xFF) << 24) | ((val & 0xFF00) << 8) | ((val & 0xFF0000) >> 8) | (val >> 24);
}

NSString* NSStringFromSelector(SEL sel) {
    NSString* ret = [NSString stringWithCString:sel_getName(sel)];
    return ret;
}

NSString* temporaryDirectory = @"/tmp";

NSString* NSTemporaryDirectory(void) {
    return temporaryDirectory;
}

void NSSetTemporaryDirectory(NSString* path) {
    temporaryDirectory = [path retain];
}
