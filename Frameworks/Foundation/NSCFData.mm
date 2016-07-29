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

#include "Starboard.h"
#include "CFHelpers.h"
#include "CFFoundationInternal.h"
#include "NSCFData.h"
#include <CoreFoundation/CFData.h>
#include "BridgeHelpers.h"

@interface NSCFData : NSMutableData
@end

#pragma region NSDataPrototype
@implementation NSDataPrototype

PROTOTYPE_CLASS_REQUIRED_IMPLS(NSCFData)

- (_Nullable instancetype)init {
    return [self initWithBytes:"" length:0];
}

- (_Nullable instancetype)initWithBytesNoCopy:(void*)bytes length:(NSUInteger)length freeWhenDone:(BOOL)freeWhenDone {
    CFAllocatorRef deallocator = freeWhenDone ? kCFAllocatorDefault : kCFAllocatorNull;
    return reinterpret_cast<NSDataPrototype*>(static_cast<NSData*>(
        (CFDataCreateWithBytesNoCopy(kCFAllocatorDefault, reinterpret_cast<const byte*>(bytes), length, deallocator))));
}

@end
#pragma endregion

#pragma region NSMutableDataPrototype
@implementation NSMutableDataPrototype

PROTOTYPE_CLASS_REQUIRED_IMPLS(NSCFData)

- (_Nullable instancetype)init {
    return [self initWithCapacity:0];
}

- (_Nullable instancetype)initWithBytesNoCopy:(void*)bytes length:(NSUInteger)length freeWhenDone:(BOOL)freeWhenDone {
    // NSMutableData is documented to make a copy of the input data on the reference platform,
    // despite of the name of this initializer
    NSMutableData* data = static_cast<NSMutableData*>(CFDataCreateMutable(kCFAllocatorDefault, 0));
    [data appendBytes:bytes length:length];

    // NSMutableData is documented to free the bytes immediately, if specified, unlike the immutable version,
    // which frees when the object is dealloc'd
    if (freeWhenDone) {
        IwFree(bytes);
    }

    return reinterpret_cast<NSMutableDataPrototype*>(data);
}

- (_Nullable instancetype)initWithCapacity:(NSUInteger)capacity {
    return reinterpret_cast<NSMutableDataPrototype*>(CFDataCreateMutable(kCFAllocatorDefault, 0));
}

@end
#pragma endregion

#pragma region NSCF Bridged Class
@implementation NSCFData

BRIDGED_CLASS_REQUIRED_IMPLS(CFDataRef, CFDataGetTypeID, NSData, NSCFData)

- (const void*)bytes {
    return CFDataGetBytePtr(static_cast<CFDataRef>(self));
}

- (void*)mutableBytes {
    BRIDGED_THROW_IF_IMMUTABLE(_CFDataIsMutable, CFDataRef);
    return CFDataGetMutableBytePtr(static_cast<CFMutableDataRef>(self));
}

- (NSUInteger)length {
    return CFDataGetLength(static_cast<CFDataRef>(self));
}

- (void)setLength:(NSUInteger)length {
    BRIDGED_THROW_IF_IMMUTABLE(_CFDataIsMutable, CFDataRef);
    CFDataSetLength(static_cast<CFMutableDataRef>(self), length);
}

- (void)replaceBytesInRange:(NSRange)range withBytes:(const void*)replacementBytes length:(NSUInteger)replacementLength {
    BRIDGED_THROW_IF_IMMUTABLE(_CFDataIsMutable, CFDataRef);
    if (range.location + range.length > [self length]) {
        [NSException raise:NSRangeException
                    format:@"range is out of bounds - range.location = %d, range.length = %d, Data length = %d",
                           range.location,
                           range.length,
                           [self length]];
    } else {
        CFDataReplaceBytes(static_cast<CFMutableDataRef>(self),
                           { range.location, range.length },
                           reinterpret_cast<const byte*>(replacementBytes),
                           replacementLength);
    }
}

- (NSObject*)copyWithZone:(NSZone*)zone {
    if (_CFDataIsMutable(static_cast<CFDataRef>(self)) || !_CFDataOwnsBuffer(static_cast<CFDataRef>(self))) {
        return reinterpret_cast<NSCFData*>(static_cast<NSData*>(CFDataCreateCopy(nullptr, static_cast<CFDataRef>(self))));
    }

    return [self retain];
}

- (NSObject*)mutableCopyWithZone:(NSZone*)zone {
    return reinterpret_cast<NSCFData*>(
        static_cast<NSMutableData*>(CFDataCreateMutableCopy(nullptr, 0, static_cast<CFMutableDataRef>(self))));
}

@end
#pragma endregion