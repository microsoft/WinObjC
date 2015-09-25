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

#import <Foundation/Foundation.h>

void CFStringAppendCharacters(CFMutableStringRef str, const UniChar* append, CFIndex length) {
    [(NSMutableString*)str __appendCharacters:append length:length];
}

void CFStringAppend(CFMutableStringRef str, CFStringRef append) {
    [(NSMutableString*)str appendString:(NSString*)append];
}

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

const char* CFStringGetCStringPtr(CFStringRef self, CFStringEncoding encoding) {
    assert(encoding == 0x600 || encoding == 0);
    return [(NSString*)self UTF8String];
}

CFComparisonResult CFStringCompare(CFStringRef self, CFStringRef other, CFOptionFlags options) {
    return (CFComparisonResult)[(NSString*)self compare:(NSString*)other options:options];
}

CFIndex CFStringGetLength(CFStringRef self) {
    return [(NSString*)self length];
}