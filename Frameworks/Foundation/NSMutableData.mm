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

#import <Starboard.h>
#import <Foundation/NSMutableData.h>

#import "NSCFData.h"

#import <NSRaise.h>

@implementation NSMutableData

+ ALLOC_PROTOTYPE_SUBCLASS_WITH_ZONE(NSMutableData, NSMutableDataPrototype);

/**
 @Status Interoperable
*/
+ (instancetype)dataWithLength:(NSUInteger)length {
    return [[[self alloc] initWithLength:length] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)dataWithCapacity:(NSUInteger)capacity {
    return [[[self alloc] initWithCapacity:capacity] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithLength:(NSUInteger)length {
    if (self = [self init]) {
        [self setLength:length];
    }
    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCapacity:(NSUInteger)length {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (void)appendBytes:(const void*)bytes length:(NSUInteger)length {
    [self replaceBytesInRange:{ [self length], 0 } withBytes:bytes length:length];
}

/**
 @Status Interoperable
*/
- (void)appendData:(NSData*)data {
    [self appendBytes:[data bytes] length:[data length]];
}

/**
 @Status Interoperable
*/
- (void)setData:(NSData*)data {
    [self replaceBytesInRange:{ 0, [self length] } withBytes:[data bytes] length:[data length]];
}

/**
 @Status Interoperable
*/
- (void)setLength:(NSUInteger)length {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
- (void)increaseLengthBy:(NSUInteger)length {
    [self setLength:[self length] + length];
}

/**
 @Status Interoperable
*/
- (void)replaceBytesInRange:(NSRange)range withBytes:(const void*)bytes {
    [self replaceBytesInRange:range withBytes:bytes length:range.length];
}

/**
 @Status Interoperable
*/
- (void)resetBytesInRange:(NSRange)range {
    NSUInteger selfLength = [self length];

    if (range.location > selfLength) {
        [NSException raise:NSRangeException
                    format:@"location is out of bounds - range.location = %d, range.length = %d, Data length = %d",
                           range.location,
                           range.length,
                           selfLength];
    }

    if (range.location + range.length > selfLength) {
        [self increaseLengthBy:(range.location + range.length) - (selfLength)];
    }

    memset(reinterpret_cast<void*>(reinterpret_cast<char*>(self.mutableBytes) + range.location), 0, range.length);
}

/**
 @Status Interoperable
*/
- (void)replaceBytesInRange:(NSRange)range withBytes:(const void*)bytes length:(NSUInteger)length {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
- (void*)mutableBytes {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (id)copyWithZone:(NSZone*)zone {
    return [[NSMutableData alloc] initWithData:self];
}

@end
