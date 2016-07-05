//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <Foundation/NSException.h>
#import <Foundation/NSString.h>
#import <CoreFoundation/CFString.h>
#import "ForFoundationOnly.h"

#include <COMIncludes.h>
#import <hstring.h>
#import <winstring.h>
#include <COMIncludes_end.h>

@interface _NSHSTRINGString : NSString {
    HSTRING _hs;
}
- (instancetype)initWithHSTRING:(HSTRING)hstring;
@end

@implementation NSString (WinObjCHSTRINGAdditions)
+ (instancetype)_stringWithHSTRING:(HSTRING)hstring {
    return [[[_NSHSTRINGString alloc] initWithHSTRING:hstring] autorelease];
}
@end

@implementation _NSHSTRINGString
- (Class)classForCoder {
    return [NSString class];
}

- (instancetype)initWithHSTRING:(HSTRING)hstring {
    if (self = [super init]) {
        WindowsDuplicateString(hstring, &_hs);
    }
    return self;
}

- (void)dealloc {
    WindowsDeleteString(_hs);
    [super dealloc];
}

- (NSUInteger)length {
    return WindowsGetStringLen(_hs);
}

- (NSUInteger)hash {
    uint32_t len = 0;
    const wchar_t* buf = WindowsGetStringRawBuffer(_hs, &len);
    return CFStringHashCharacters((const UniChar*)buf, len);
}

- (unichar)characterAtIndex:(NSUInteger)index {
    uint32_t len = 0;
    const wchar_t* buf = WindowsGetStringRawBuffer(_hs, &len);
    if (index >= len) {
        [NSException raise:NSRangeException
                    format:@"-[NSString characterAtIndex:]: Index %lu out of bounds; string length %lu", index, len];
    }
    return buf[index];
}

- (void)getCharacters:(unichar*)buffer range:(NSRange)range {
    uint32_t len = 0;
    const wchar_t* buf = WindowsGetStringRawBuffer(_hs, &len);
    if (range.length + range.location > len) {
        [NSException raise:NSRangeException
                    format:@"-[NSString getCharacters:range:]: Range {%lu, %lu} out of bounds; string length %lu",
                           range.length,
                           range.location,
                           len];
    }
    memcpy(buffer, buf + range.location, range.length * sizeof(wchar_t));
}

- (CFStringEncoding)_fastestEncodingInCFStringEncoding {
    // Since HSTRINGs are backed by wchar_t buffers, the fastest encoding for them is UTF16.
    return kCFStringEncodingUTF16LE;
}
@end

static __attribute__((constructor)) void _ForceTUInclusion() {
}
