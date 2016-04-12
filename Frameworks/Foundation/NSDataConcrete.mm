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
#include "CFHelpers.h"
#include "CFFoundationInternal.h"
#include "NSDataConcrete.h"
#include <CoreFoundation/CFData.h>

#pragma region Immutable Concrete Subclass
@implementation NSDataConcrete {
@private
    StrongId<NSCFData> _nscf;
}

- (instancetype)init {
    return [self initWithBytes:"" length:0];
}

- (instancetype)initWithBytesNoCopy:(void*)bytes length:(NSUInteger)length freeWhenDone:(BOOL)freeWhenDone {
    if (self = [super init]) {
        CFAllocatorRef deallocator = freeWhenDone ? kCFAllocatorDefault : kCFAllocatorNull;
        _nscf.attach(reinterpret_cast<NSCFData*>(
            static_cast<NSData*>((CFDataCreateWithBytesNoCopy(NULL, reinterpret_cast<const byte*>(bytes), length, deallocator)))));
    }
    return self;
}

- INNER_BRIDGE_CALL(_nscf, const void*, bytes);
- INNER_BRIDGE_CALL(_nscf, NSUInteger, length);

@end
#pragma endregion

#pragma region Mutable Concrete Subclass
@implementation NSMutableDataConcrete {
@private
    StrongId<NSCFData> _nscf;
}

- (instancetype)init {
    return [self initWithCapacity:0];
}

- (instancetype)initWithBytesNoCopy:(void*)bytes length:(NSUInteger)length freeWhenDone:(BOOL)freeWhenDone {
    if (self = [super init]) {
        // NSMutableData is documented to make a copy of the input data on the reference platform,
        // despite of the name of this initializer
        _nscf.attach(reinterpret_cast<NSCFData*>(static_cast<NSData*>((CFDataCreateMutable(NULL, 0)))));
        [_nscf appendBytes:bytes length:length];

        // NSMutableData is documented to free the bytes immediately, if specified, unlike the immutable version,
        // which frees when the object is dealloc'd
        if (freeWhenDone) {
            IwFree(bytes);
        }
    }
    return self;
}

- (instancetype)initWithCapacity:(NSUInteger)capacity {
    if (self = [super init]) {
        _nscf.attach(reinterpret_cast<NSCFData*>(static_cast<NSData*>((CFDataCreateMutable(NULL, capacity)))));
    }
    return self;
}

- INNER_BRIDGE_CALL(_nscf, const void*, bytes);
- INNER_BRIDGE_CALL(_nscf, void*, mutableBytes);
- INNER_BRIDGE_CALL(_nscf, NSUInteger, length);
- INNER_BRIDGE_CALL(_nscf, void, setLength:(NSUInteger)length);
- INNER_BRIDGE_CALL(_nscf, void,
                    replaceBytesInRange:(NSRange)range
                    withBytes:(const void*)replacementBytes
                    length:(NSUInteger)replacementLength);

@end
#pragma endregion

#pragma region NSCF Bridged Class
@implementation NSCFData

BRIDGED_CLASS_REQUIRED_IMPLS(CFDataRef, CFDataGetTypeID, NSData, NSCFData)

- (instancetype)initWithBytesNoCopy:(void*)bytes length:(NSUInteger)length freeWhenDone:(BOOL)freeWhenDone {
    FAIL_FAST();
    return nil;
}

- (instancetype)initWithCapacity:(NSUInteger)length {
    FAIL_FAST();
    return nil;
}

- (const void*)bytes {
    return CFDataGetBytePtr(static_cast<CFDataRef>(self));
}

- (void*)mutableBytes {
    return CFDataGetMutableBytePtr(static_cast<CFMutableDataRef>(self));
}

- (NSUInteger)length {
    return CFDataGetLength(static_cast<CFDataRef>(self));
}

- (void)setLength:(NSUInteger)length {
    CFDataSetLength(static_cast<CFMutableDataRef>(self), length);
}

- (void)replaceBytesInRange:(NSRange)range withBytes:(const void*)replacementBytes length:(NSUInteger)replacementLength {
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

@end
#pragma endregion