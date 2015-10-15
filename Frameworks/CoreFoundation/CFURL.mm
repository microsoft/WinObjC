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

#import <CoreFoundation/CoreFoundation.h>
#include "Starboard.h"

static IWLazyClassLookup _LazyNSString("NSString");

// Won't work so great with continuations... FIXME sometime

static bool charInNSString(CFStringRef str, short ch) {
    unsigned length = [(NSString*)str length];
    if (length == 0) {
        return false;
    }

    const char* cstring = [(NSString*)str UTF8String];
    for (size_t i = 0; i < length; ++i) {
        if (cstring[i] == ch) {
            return true;
        }
    }
    return false;
}

CFStringRef CFURLCreateStringByAddingPercentEscapes(CFAllocatorRef allocator,
                                                    CFStringRef origString,
                                                    CFStringRef charactersToLeaveUnescaped,
                                                    CFStringRef legalURLCharactersToBeEscaped,
                                                    CFStringEncoding encoding) {
    const char* utf8String = [(NSString*)origString UTF8String];

    NSUInteger length = [(NSString *)origString lengthOfBytesUsingEncoding:encoding], resultLength = 0;
    char* result = (char*)EbrMalloc(length * 3 * 2 + 1);

    const char hex[] = "0123456789ABCDEF";
    const char legalURLCharacters[] = {
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmno"
        "pqrstuvwxyz0123456789-._~:/"
        "?#[]@!$&'()*+,;="
    };

    for (size_t i = 0; i < length; ++i) {
        char code = utf8String[i];

        bool legalCharacter = charInNSString(charactersToLeaveUnescaped, code);

        for (size_t n = 0; n < sizeof(legalURLCharacters) && !legalCharacter; ++n) {
            if (code == legalURLCharacters[n] && !charInNSString(legalURLCharactersToBeEscaped, code)) {
                legalCharacter = true;
            }
        }

        if (!legalCharacter) {
            result[resultLength++] = '%';
            result[resultLength++] = hex[(code >> 4) & 0xF];
            result[resultLength++] = hex[code & 0xF];
        } else {
            result[resultLength++] = code;
        }
    }

    NSString* ret;
    if (length == resultLength) {
        EbrFree(result);
        ret = [(NSString*)origString retain];
    } else {
        result[resultLength] = 0;

        NSString* ret = [[_LazyNSString alloc] initWithCString:result];
        EbrFree(result);
    }

    return (__bridge CFStringRef)ret;
}

CFStringRef CFURLCopyPathExtension(CFURLRef self) {
    return (CFStringRef)[[[(NSURL*)self path] pathExtension] retain];
}
