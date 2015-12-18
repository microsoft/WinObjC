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
#import <Foundation/Foundation.h>

/**
 @Status Interoperable
*/
void CFStringAppendCharacters(CFMutableStringRef str, const UniChar* append, CFIndex length) {
    [(NSMutableString*)str __appendCharacters:append length:length];
}

/**
 @Status Interoperable
*/
void CFStringAppend(CFMutableStringRef str, CFStringRef append) {
    [(NSMutableString*)str appendString:(NSString*)append];
}

/**
 @Status Interoperable
*/
void CFStringReplace(CFMutableStringRef str, CFRange range, CFStringRef replacement) {
    [(NSMutableString*)str replaceCharactersInRange:{ range.location, range.length } withString:(NSString*)replacement];
}

/**
 @Status Caveat
 @Notes Limited encodings supported
*/
CFStringRef CFStringConvertEncodingToIANACharSetName(CFStringEncoding encoding) {
    switch (encoding) {
        case kCFStringEncodingASCII:
            return (CFStringRef) @"ANSI_X3.4-1968";

        default:
            assert(0);
            break;
    }

    return 0;
}

/**
 @Status Caveat
 @Notes Limited encodings supported
*/
CFStringEncoding CFStringConvertNSStringEncodingToEncoding(UInt32 encoding) {
    switch (encoding) {
        case NSASCIIStringEncoding:
        case NSUTF8StringEncoding:
        case NSWindowsCP1252StringEncoding:
        case NSISOLatin1StringEncoding:
            return kCFStringEncodingASCII;

        case NSUTF16LittleEndianStringEncoding:
            return kCFStringEncodingUTF16LE;

        default:
            assert(0);
            break;
    }

    return 0;
}

/**
 @Status Interoperable
 @Notes Limited encodings supported
*/
const char* CFStringGetCStringPtr(CFStringRef self, CFStringEncoding encoding) {
    assert(encoding == 0x600 || encoding == 0);
    return [(NSString*)self UTF8String];
}

/**
 @Status Interoperable
*/
CFComparisonResult CFStringCompare(CFStringRef self, CFStringRef other, CFOptionFlags options) {
    return (CFComparisonResult)[(NSString*)self compare:(NSString*)other options:options];
}

/**
 @Status Interoperable
*/
CFIndex CFStringGetLength(CFStringRef self) {
    return [(NSString*)self length];
}

/**
 @Status Stub
*/
CFStringEncoding CFStringGetFastestEncoding(CFStringRef self) {
    UNIMPLEMENTED();
    return 0;
}
