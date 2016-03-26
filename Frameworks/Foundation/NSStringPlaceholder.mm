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
#include "StubReturn.h"
#include "CFHelpers.h"
#include "CFFoundationInternal.h"
#include "NSStringPlaceholder.h"
#include <CoreFoundation/CFString.h>
#include "BridgeHelpers.h"
#include "ForFoundationOnly.h"

@implementation NSStringPlaceholder

- (instancetype)init {
    return [self initWithCString:"" length:0];
}

- (instancetype)initWithCString:(const char*)cStr length:(NSUInteger)length {
    return reinterpret_cast<NSStringPlaceholder*>(static_cast<NSString*>(
        CFStringCreateWithCString(NULL, cStr, CFStringConvertNSStringEncodingToEncoding([[self class] defaultCStringEncoding]))));
}

- (instancetype)initWithUTF8String:(const char*)utf8str {
    return reinterpret_cast<NSStringPlaceholder*>(static_cast<NSString*>(CFStringCreateWithCString(NULL, utf8str, kCFStringEncodingUTF8)));
}

- (instancetype)initWithFormat:(id)formatStr arguments:(va_list)pReader {
    return reinterpret_cast<NSStringPlaceholder*>(
        static_cast<NSString*>(CFStringCreateWithFormatAndArguments(nullptr, nullptr, static_cast<CFStringRef>(formatStr), pReader)));
}

- (instancetype)initWithBytes:(const void*)bytes length:(NSUInteger)length encoding:(NSStringEncoding)encoding {
    return reinterpret_cast<NSStringPlaceholder*>(static_cast<NSString*>(
        CFStringCreateWithBytes(nullptr, (const UInt8*)bytes, length, CFStringConvertNSStringEncodingToEncoding(encoding), false)));
}

- (instancetype)initWithBytesNoCopy:(void*)bytes
                             length:(NSUInteger)length
                           encoding:(NSStringEncoding)encoding
                       freeWhenDone:(BOOL)freeWhenDone {
    return reinterpret_cast<NSStringPlaceholder*>(
        static_cast<NSString*>(CFStringCreateWithBytesNoCopy(nullptr,
                                                             (const UInt8*)bytes,
                                                             length,
                                                             CFStringConvertNSStringEncodingToEncoding(encoding),
                                                             false,
                                                             (freeWhenDone) ? (nullptr) : (kCFAllocatorNull))));
}

- (instancetype)initWithCharacters:(const unichar*)bytes length:(NSUInteger)length {
    return reinterpret_cast<NSStringPlaceholder*>(static_cast<NSString*>(CFStringCreateWithCharacters(nullptr, bytes, length)));
}

- (instancetype)initWithCharactersNoCopy:(unichar*)bytes length:(NSUInteger)length freeWhenDone:(BOOL)freeWhenDone {
    return reinterpret_cast<NSStringPlaceholder*>(static_cast<NSString*>(
        CFStringCreateWithCharactersNoCopy(nullptr, bytes, length, (freeWhenDone) ? (nullptr) : (kCFAllocatorNull))));
}

- (instancetype)initWithCString:(const char*)bytes encoding:(NSStringEncoding)encoding {
    return reinterpret_cast<NSStringPlaceholder*>(
        static_cast<NSString*>(CFStringCreateWithCString(NULL, bytes, CFStringConvertNSStringEncodingToEncoding(encoding))));
}

- (instancetype)initWithString:(NSString*)otherStr {
    return reinterpret_cast<NSStringPlaceholder*>(
        static_cast<NSString*>(CFStringCreateWithSubstring(NULL, static_cast<CFStringRef>(otherStr), { 0, [otherStr length] })));
}

@end
