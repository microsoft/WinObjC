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

#import "NSCFInputStream.h"
#import "BridgeHelpers.h"
#import <CoreFoundation/CFStream.h>
#import <CFFoundationInternal.h>

@interface NSCFInputStream : NSInputStream
@end

#pragma region NSInputStreamPrototype

@implementation NSInputStreamPrototype

PROTOTYPE_CLASS_REQUIRED_IMPLS(NSCFInputStream)

/**
 @Status Interoperable
*/
- (instancetype)initWithData:(NSData*)data {
    return reinterpret_cast<NSInputStreamPrototype*>(CFReadStreamCreateWithData(nullptr, static_cast<CFDataRef>(data)));
}

/**
 @Status Interoperable
 @Notes
*/
- (instancetype)initWithURL:(NSURL*)url {
    return reinterpret_cast<NSInputStreamPrototype*>(CFReadStreamCreateWithFile(nullptr, static_cast<CFURLRef>(url)));
}

@end

#pragma endregion

#pragma region NSCFInputStream
@implementation NSCFInputStream

BRIDGED_CLASS_REQUIRED_IMPLS(CFReadStreamRef, CFReadStreamGetTypeID, NSURL, NSCFInputStream)

/**
 @Status Interoperable
*/
- (NSStreamStatus)streamStatus {
    return CFReadStreamGetStatus(static_cast<CFReadStreamRef>(self));
}

/**
 @Status Interoperable
*/
- (void)close {
    CFReadStreamClose(static_cast<CFReadStreamRef>(self));
}

/**
 @Status Interoperable
*/
- (id)propertyForKey:(NSString*)key {
    return [static_cast<id>(CFReadStreamCopyProperty(static_cast<CFReadStreamRef>(self), static_cast<CFStringRef>(key))) autorelease];
}

/**
 @Status Interoperable
 @Notes
*/
- (BOOL)setProperty:(id)property forKey:(NSString*)key {
    return CFReadStreamSetProperty(static_cast<CFReadStreamRef>(self), static_cast<CFStringRef>(key), static_cast<CFTypeRef>(property));
}

/**
 @Status Interoperable
 @Notes
*/
- (void)open {
    CFReadStreamOpen(static_cast<CFReadStreamRef>(self));
}

/**
 @Status Interoperable
*/
- (NSInteger)read:(uint8_t*)buf maxLength:(NSUInteger)maxLength {
    return CFReadStreamRead(static_cast<CFReadStreamRef>(self), buf, maxLength);
}

/**
 @Status Interoperable
*/
- (BOOL)hasBytesAvailable {
    return CFReadStreamHasBytesAvailable(static_cast<CFReadStreamRef>(self));
}

/**
 @Status Interoperable
 @Notes
*/
- (BOOL)getBuffer:(uint8_t* _Nullable*)buffer length:(NSUInteger*)len {
    CFIndex length;
    const UInt8* result = CFReadStreamGetBuffer(static_cast<CFReadStreamRef>(self), 0, &length);
    if (result) {
        if (buffer) {
            *buffer = (uint8_t*)result;
        }

        if (len) {
            *len = length;
        }

        return YES;
    }

    return NO;
}

@end

#pragma endregion