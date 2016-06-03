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
#include "NSCFString.h"
#include <CoreFoundation/CFString.h>
#include "BridgeHelpers.h"
#include "ForFoundationOnly.h"

@implementation NSStringPrototype

PROTOTYPE_CLASS_REQUIRED_IMPLS

- (instancetype)init {
    return [self initWithCString:"" length:0];
}

- (instancetype)initWithCString:(const char*)cStr length:(NSUInteger)length {
    return reinterpret_cast<NSStringPrototype*>(static_cast<NSString*>(
        CFStringCreateWithCString(kCFAllocatorDefault,
                                  cStr,
                                  CFStringConvertNSStringEncodingToEncoding([[self class] defaultCStringEncoding]))));
}

- (instancetype)initWithUTF8String:(const char*)utf8str {
    return reinterpret_cast<NSStringPrototype*>(
        static_cast<NSString*>(CFStringCreateWithCString(kCFAllocatorDefault, utf8str, kCFStringEncodingUTF8)));
}

- (instancetype)initWithFormat:(id)formatStr arguments:(va_list)pReader {
    return reinterpret_cast<NSStringPrototype*>(static_cast<NSString*>(
        CFStringCreateWithFormatAndArguments(kCFAllocatorDefault, nullptr, static_cast<CFStringRef>(formatStr), pReader)));
}

- (instancetype)initWithBytes:(const void*)bytes length:(NSUInteger)length encoding:(NSStringEncoding)encoding {
    return reinterpret_cast<NSStringPrototype*>(static_cast<NSString*>(CFStringCreateWithBytes(
        kCFAllocatorDefault, (const UInt8*)bytes, length, CFStringConvertNSStringEncodingToEncoding(encoding), false)));
}

- (instancetype)initWithBytesNoCopy:(void*)bytes
                             length:(NSUInteger)length
                           encoding:(NSStringEncoding)encoding
                       freeWhenDone:(BOOL)freeWhenDone {
    return reinterpret_cast<NSStringPrototype*>(
        static_cast<NSString*>(CFStringCreateWithBytesNoCopy(kCFAllocatorDefault,
                                                             (const UInt8*)bytes,
                                                             length,
                                                             CFStringConvertNSStringEncodingToEncoding(encoding),
                                                             false,
                                                             (freeWhenDone) ? (nullptr) : (kCFAllocatorNull))));
}

- (instancetype)initWithCharacters:(const unichar*)bytes length:(NSUInteger)length {
    return reinterpret_cast<NSStringPrototype*>(static_cast<NSString*>(CFStringCreateWithCharacters(kCFAllocatorDefault, bytes, length)));
}

- (instancetype)initWithCharactersNoCopy:(unichar*)bytes length:(NSUInteger)length freeWhenDone:(BOOL)freeWhenDone {
    return reinterpret_cast<NSStringPrototype*>(static_cast<NSString*>(
        CFStringCreateWithCharactersNoCopy(kCFAllocatorDefault, bytes, length, (freeWhenDone) ? (nullptr) : (kCFAllocatorNull))));
}

- (instancetype)initWithCString:(const char*)bytes encoding:(NSStringEncoding)encoding {
    return reinterpret_cast<NSStringPrototype*>(
        static_cast<NSString*>(CFStringCreateWithCString(kCFAllocatorDefault, bytes, CFStringConvertNSStringEncodingToEncoding(encoding))));
}

- (instancetype)initWithString:(NSString*)otherStr {
    return reinterpret_cast<NSStringPrototype*>(static_cast<NSString*>(
        CFStringCreateWithSubstring(kCFAllocatorDefault, static_cast<CFStringRef>(otherStr), { 0, [otherStr length] })));
}

- (instancetype)initWithFormat:(NSString*)format locale:(id)locale arguments:(va_list)argList {
    CFStringRef str;

    if (locale == nil) {
        str = CFStringCreateWithFormatAndArguments(nullptr, nullptr, static_cast<CFStringRef>(format), argList);
    } else if ([locale isKindOfClass:[NSLocale class]] || [locale isKindOfClass:[NSDictionary class]]) {
        str = CFStringCreateWithFormatAndArguments(kCFAllocatorDefault,
                                                   static_cast<CFDictionaryRef>(locale),
                                                   static_cast<CFStringRef>(format),
                                                   argList);
    } else {
        [NSException raise:NSInvalidArgumentException format:@"Locale parameter must be a NSLocale or a NSDictionary."];
    }
    return reinterpret_cast<NSStringPrototype*>(static_cast<NSString*>(str));
}

- (instancetype)initWithCStringNoCopy:(char*)bytes length:(NSUInteger)length freeWhenDone:(BOOL)freeBuffer {
    return reinterpret_cast<NSStringPrototype*>(static_cast<NSString*>(CFStringCreateWithCStringNoCopy(
        kCFAllocatorDefault, bytes, CFStringGetSystemEncoding(), freeBuffer ? kCFAllocatorDefault : kCFAllocatorNull)));
}

@end
