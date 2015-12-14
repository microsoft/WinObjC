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
NSString* NSHomeDirectory(void) {
    // We expect this call to only return a single directory
    return [NSSearchPathForDirectoriesInDomains(NSApplicationDirectory, 0, FALSE) lastObject];
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
