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

@implementation NSMutableStringPrototype

PROTOTYPE_CLASS_REQUIRED_IMPLS(NSObject)

- (instancetype)init {
    return [self initWithCapacity:0];
}

- (instancetype)initWithCString:(const char*)cStr length:(NSUInteger)length {
    CFMutableStringRef mutableRef = CFStringCreateMutable(kCFAllocatorDefault, 0);
    CFStringAppendCString(mutableRef, cStr, CFStringConvertNSStringEncodingToEncoding([[self class] defaultCStringEncoding]));
    return reinterpret_cast<NSMutableStringPrototype*>(static_cast<NSMutableString*>(mutableRef));
}

- (instancetype)initWithUTF8String:(const char*)utf8str {
    CFMutableStringRef mutableRef = CFStringCreateMutable(kCFAllocatorDefault, 0);
    CFStringAppendCString(mutableRef, utf8str, kCFStringEncodingUTF8);
    return reinterpret_cast<NSMutableStringPrototype*>(static_cast<NSMutableString*>(mutableRef));
}

- (instancetype)initWithFormat:(id)formatStr arguments:(va_list)pReader {
    CFMutableStringRef mutableRef = CFStringCreateMutable(kCFAllocatorDefault, 0);
    _CFStringAppendFormatAndArgumentsAux(mutableRef, &_NSCFStringCopyDescription, nullptr, static_cast<CFStringRef>(formatStr), pReader);
    return reinterpret_cast<NSMutableStringPrototype*>(static_cast<NSMutableString*>(mutableRef));
}

- (instancetype)initWithBytes:(const void*)bytes length:(NSUInteger)length encoding:(NSStringEncoding)encoding {
    CFMutableStringRef mutableRef = CFStringCreateMutable(kCFAllocatorDefault, 0);

    // This really isn't the most efficient. Unfortunately though, there is no exposed CF append bytes method.
    CFStringAppend(mutableRef,
                   CFStringCreateWithBytesNoCopy(
                       nullptr, (const UInt8*)bytes, length, CFStringConvertNSStringEncodingToEncoding(encoding), false, kCFAllocatorNull));
    return reinterpret_cast<NSMutableStringPrototype*>(static_cast<NSMutableString*>(mutableRef));
}

- (instancetype)initWithBytesNoCopy:(void*)bytes
                             length:(NSUInteger)length
                           encoding:(NSStringEncoding)encoding
                       freeWhenDone:(BOOL)freeWhenDone {
    if (self = [super init]) {
        self = [self initWithBytes:bytes length:length encoding:encoding];

        // Don't take the "NoCopy" hint because a *mutable* string cannot use the provided buffer and reasonably expect
        // to be able to append etc without also taking an external allocator for resizing. Do free the buffer now if they
        // said freeWhenDone since it is "done" at this point. NOTE: this *must* have been allocated with same heap as IwMalloc's.
        if (freeWhenDone && bytes) {
            IwFree(bytes);
        }
    }
    return self;
}

- (instancetype)initWithCharacters:(const unichar*)bytes length:(NSUInteger)length {
    CFMutableStringRef mutableRef = CFStringCreateMutable(kCFAllocatorDefault, 0);
    CFStringAppendCharacters(mutableRef, bytes, length);
    return reinterpret_cast<NSMutableStringPrototype*>(static_cast<NSMutableString*>(mutableRef));
}

- (instancetype)initWithCharactersNoCopy:(unichar*)bytes length:(NSUInteger)length freeWhenDone:(BOOL)freeWhenDone {
    if (self = [super init]) {
        self = [self initWithCharacters:bytes length:length];

        // Don't take the "NoCopy" hint because a *mutable* string cannot use the provided buffer and reasonably expect
        // to be able to append etc without also taking an external allocator for resizing. Do free the buffer now if they
        // said freeWhenDone since it is "done" at this point. NOTE: this *must* have been allocated with same heap as IwMalloc's.
        if (freeWhenDone && bytes) {
            IwFree(bytes);
        }
    }
    return self;
}

- (instancetype)initWithCString:(const char*)bytes encoding:(NSStringEncoding)encoding {
    CFMutableStringRef mutableRef = CFStringCreateMutable(kCFAllocatorDefault, 0);
    CFStringAppendCString(mutableRef, bytes, CFStringConvertNSStringEncodingToEncoding(encoding));
    return reinterpret_cast<NSMutableStringPrototype*>(static_cast<NSMutableString*>(mutableRef));
}

- (instancetype)initWithCapacity:(NSUInteger)capacity {
    return reinterpret_cast<NSMutableStringPrototype*>(static_cast<NSMutableString*>(CFStringCreateMutable(kCFAllocatorDefault, capacity)));
}

- (instancetype)initWithString:(NSString*)otherStr {
    CFMutableStringRef mutableRef = CFStringCreateMutable(kCFAllocatorDefault, 0);
    CFStringAppend(mutableRef, static_cast<CFStringRef>(otherStr));
    return reinterpret_cast<NSMutableStringPrototype*>(static_cast<NSMutableString*>(mutableRef));
}

@end
