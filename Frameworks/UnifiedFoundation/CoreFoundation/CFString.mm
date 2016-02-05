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
#import <Foundation/Foundation.h>
#import "NSMutableString+Internal.h"
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
            UNIMPLEMENTED_WITH_MSG("%x is not a supported encoding, defaulting to ANSI_X3.4-1968", encoding);
            return (CFStringRef) @"ANSI_X3.4-1968";
    }
}

/**
 @Status Caveat
 @Notes Limited encodings supported
*/
UInt32 CFStringConvertEncodingToNSStringEncoding(CFStringEncoding encoding) {
    // IMPORTANT: Make sure this matches with the converse function CFStringConvertNSStringEncodingToEncoding below
    switch (encoding) {
        case kCFStringEncodingASCII:
            return NSASCIIStringEncoding;

        case kCFStringEncodingUTF8:
            return NSUTF8StringEncoding;

        case kCFStringEncodingUnicode:
            return NSUnicodeStringEncoding;

        case kCFStringEncodingUTF16LE:
            return NSUTF16LittleEndianStringEncoding;

        default:
            UNIMPLEMENTED_WITH_MSG("%x is not a supported encoding, defaulting to NSUnicodeStringEncoding", encoding);
            return NSUnicodeStringEncoding;
    }
}

/**
 @Status Caveat
 @Notes Limited encodings supported
*/
CFStringEncoding CFStringConvertNSStringEncodingToEncoding(UInt32 encoding) {
    // IMPORTANT: Make sure this matches with the converse function CFStringConvertEncodingToNSStringEncoding above
    switch (encoding) {
        case NSASCIIStringEncoding:
        case NSWindowsCP1252StringEncoding:
        case NSISOLatin1StringEncoding:
            return kCFStringEncodingASCII;

        case NSUTF8StringEncoding:
            return kCFStringEncodingUTF8;

        case NSUnicodeStringEncoding: // Also NSUTF16StringEncoding = NSUnicodeStringEncoding
            return kCFStringEncodingUnicode;

        case static_cast<UInt32>(NSUTF16LittleEndianStringEncoding):
            return kCFStringEncodingUTF16LE;

        default:
            UNIMPLEMENTED_WITH_MSG("%x is not a supported encoding, defaulting to kCFStringEncodingUnicode", encoding);
            return kCFStringEncodingUnicode;
    }
}

/**
 @Status Stub
*/
CFStringEncoding CFStringConvertIANACharSetNameToEncoding(CFStringRef self) {
    UNIMPLEMENTED();
    return kCFStringEncodingUnicode;
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
    return (CFComparisonResult)[(NSString*)self compare:(NSString*)other options:static_cast<NSStringCompareOptions>(options)];
}

/**
 @Status Interoperable
*/
CFIndex CFStringGetLength(CFStringRef self) {
    return [(NSString*)self length];
}

/**
 @Status Interoperable
*/
CFStringEncoding CFStringGetFastestEncoding(CFStringRef self) {
    return CFStringConvertNSStringEncodingToEncoding([(NSString*)self fastestEncoding]);
}

/**
 @Status Stub
*/
Boolean CFStringTransform(CFMutableStringRef string, CFRange* range, CFStringRef transform, Boolean reverse) {
    UNIMPLEMENTED();
    return false;
}