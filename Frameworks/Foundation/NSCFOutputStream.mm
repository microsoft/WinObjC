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

#import "NSCFOutputStream.h"
#import "BridgeHelpers.h"
#import <CoreFoundation/CFStream.h>
#import <CFFoundationInternal.h>

@interface NSCFOutputStream : NSOutputStream
@end

#pragma region NSOutputStreamPrototype

@implementation NSOutputStreamPrototype

PROTOTYPE_CLASS_REQUIRED_IMPLS(NSCFOutputStream)

/**
 @Status Interoperable
*/
- (instancetype)initToMemory {
    return reinterpret_cast<NSOutputStreamPrototype*>(CFWriteStreamCreateWithAllocatedBuffers(nullptr, nullptr));
}

/**
 @Status Interoperable
*/
- (instancetype)initToBuffer:(uint8_t*)buffer capacity:(NSUInteger)capacity {
    return reinterpret_cast<NSOutputStreamPrototype*>(CFWriteStreamCreateWithBuffer(nullptr, buffer, capacity));
}

/**
 @Status Interoperable
*/
- (instancetype)initWithURL:(NSURL*)url append:(BOOL)shouldAppend {
    CFWriteStreamRef outputStream = CFWriteStreamCreateWithFile(nullptr, static_cast<CFURLRef>(url));

    if (shouldAppend) {
        CFWriteStreamSetProperty(outputStream, kCFStreamPropertyAppendToFile, kCFBooleanTrue);
    }

    return reinterpret_cast<NSOutputStreamPrototype*>(outputStream);
}

@end

#pragma endregion

#pragma region NSCFOutputStream
@implementation NSCFOutputStream

BRIDGED_CLASS_REQUIRED_IMPLS(CFWriteStreamRef, CFWriteStreamGetTypeID, NSURL, NSCFOutputStream)

/**
 @Status Interoperable
*/
- (NSStreamStatus)streamStatus {
    return CFWriteStreamGetStatus(static_cast<CFWriteStreamRef>(self));
}

/**
 @Status Interoperable
*/
- (void)close {
    CFWriteStreamClose(static_cast<CFWriteStreamRef>(self));
}

/**
 @Status Interoperable
*/
- (id)propertyForKey:(NSString*)key {
    return [static_cast<id>(CFWriteStreamCopyProperty(static_cast<CFWriteStreamRef>(self), static_cast<CFStringRef>(key))) autorelease];
}

/**
 @Status Interoperable
 @Notes
*/
- (BOOL)setProperty:(id)property forKey:(NSString*)key {
    return CFWriteStreamSetProperty(static_cast<CFWriteStreamRef>(self), static_cast<CFStringRef>(key), static_cast<CFTypeRef>(property));
}

/**
 @Status Interoperable
 @Notes
*/
- (void)open {
    CFWriteStreamOpen(static_cast<CFWriteStreamRef>(self));
}

/**
 @Status Interoperable
*/
- (NSInteger)write:(const uint8_t*)buf maxLength:(NSUInteger)maxLength {
    return CFWriteStreamWrite(static_cast<CFWriteStreamRef>(self), buf, maxLength);
}

/**
 @Status Interoperable
*/
- (BOOL)hasSpaceAvailable {
    return CFWriteStreamCanAcceptBytes(static_cast<CFWriteStreamRef>(self));
}

@end

#pragma endregion