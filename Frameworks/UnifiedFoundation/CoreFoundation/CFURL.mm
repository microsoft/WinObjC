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

#import "CoreFoundation/CoreFoundation.h"
#import "Starboard.h"
#import <algorithm>
#import <memory>

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

/**
 @Status Interoperable
*/
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

        NSString* ret = [[NSString alloc] initWithCString:result];
        EbrFree(result);
    }

    return (__bridge CFStringRef)ret;
}

/**
 @Status Interoperable
*/
CFStringRef CFURLCopyPathExtension(CFURLRef self) {
    return (CFStringRef)[[[(NSURL*)self path] pathExtension] retain];
}

/**
 @Status Interoperable
*/
CFStringRef CFURLCreateStringByReplacingPercentEscapes(CFAllocatorRef allocator, CFStringRef string, CFStringRef charactersToLeaveEscaped) {
    return CFURLCreateStringByReplacingPercentEscapesUsingEncoding(allocator, string, charactersToLeaveEscaped, kCFStringEncodingUTF8);
}

/**
 @Status Caveat
 @Notes Only UTF-8 is supported
*/
CFStringRef CFURLCreateStringByReplacingPercentEscapesUsingEncoding(CFAllocatorRef allocator,
                                                                    CFStringRef string,
                                                                    CFStringRef charactersToLeaveEscaped,
                                                                    CFStringEncoding encoding) {
    if (encoding != kCFStringEncodingUTF8) {
        UNIMPLEMENTED_WITH_MSG("Only UTF-8 is supported.");
        return nullptr;
    }

    NSUInteger length = [(NSString*)string length];
    NSUInteger resultLength = 0;

    const unichar* buffer = [(NSString*)string rawCharacters];
    std::unique_ptr<unichar[]> result(new unichar[length * 2]);
    unichar firstCharacter = 0;
    unichar firstNibble = 0;

    enum {
        STATE_NORMAL,
        STATE_PERCENT,
        STATE_HEX1,
    } state = STATE_NORMAL;

    // Unescape the charactersToLeaveEscaped
    // This can only recurse a maximum of once, since nullptr is passed for characters to leave escaped
    NSString* escapedStringToIgnore =
        charactersToLeaveEscaped ?
            (NSString*)CFURLCreateStringByReplacingPercentEscapes(nullptr, (CFStringRef)charactersToLeaveEscaped, nullptr) :
            nil;
    // Will be nil if escapedStringToIgnore is nil
    const unichar* escapedCharsToIgnore = [escapedStringToIgnore rawCharacters];
    const unichar* escapedCharsToIgnoreEnd = escapedCharsToIgnore ? escapedCharsToIgnore + [escapedStringToIgnore length] : nullptr;

    for (NSUInteger i = 0; i < length; i++) {
        unichar check = buffer[i];

        switch (state) {
            case STATE_NORMAL:
                if (check == '%')
                    state = STATE_PERCENT;
                else
                    result[resultLength++] = check;
                break;

            case STATE_PERCENT:
                state = STATE_HEX1;
                if (check >= '0' && check <= '9') {
                    firstCharacter = check;
                    firstNibble = (firstCharacter - '0');
                } else if (check >= 'a' && check <= 'f') {
                    firstCharacter = check;
                    firstNibble = (firstCharacter - 'a') + 10;
                } else if (check >= 'A' && check <= 'F') {
                    firstCharacter = check;
                    firstNibble = (firstCharacter - 'A') + 10;
                } else {
                    result[resultLength++] = '%';
                    result[resultLength++] = check;
                    state = STATE_NORMAL;
                }
                break;

            case STATE_HEX1:
                // Cache the result to first check if the unencoding needs to occur
                unichar resultChar;
                bool resultCharInitialized;

                if (check >= '0' && check <= '9') {
                    resultChar = firstNibble * 16 + check - '0';
                    resultCharInitialized = true;

                } else if (check >= 'a' && check <= 'f') {
                    resultChar = firstNibble * 16 + (check - 'a') + 10;
                    resultCharInitialized = true;

                } else if (check >= 'A' && check <= 'F') {
                    resultChar = firstNibble * 16 + (check - 'A') + 10;
                    resultCharInitialized = true;
                }

                // If resultCharInitialized
                //      If no escapedCharsToIgnore OR
                //      If escapedCharsToIgnore AND resultChar not in escapedCharsToIgnore
                if (resultCharInitialized &&
                    (!escapedCharsToIgnore ||
                     std::find(escapedCharsToIgnore, escapedCharsToIgnoreEnd, resultChar) == escapedCharsToIgnoreEnd)) {
                    result[resultLength++] = resultChar;
                } else {
                    result[resultLength++] = '%';
                    result[resultLength++] = firstCharacter;
                    result[resultLength++] = check;
                }
                state = STATE_NORMAL;
                break;
        }
    }

    if (resultLength == length) {
        return string;
    }

    NSString* ret = [NSString stringWithCharacters:result.get() length:resultLength];

    return (CFStringRef)ret;
}

/**
 @Status Stub
*/
CFStringRef CFURLCopyPath(CFURLRef self) {
    UNIMPLEMENTED();
    return nullptr;
}
