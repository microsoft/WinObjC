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

#import "Starboard.h"
#import <Foundation/NSMutableData.h>

@implementation NSMutableData
void setCapacity(NSMutableData* self, unsigned length, bool exact = false) {
    if (exact) {
        self->_capacity = length;

        if (self->_freeWhenDone == FALSE) {
            uint8_t* newBytes = (uint8_t*)malloc(self->_capacity);

            if (self->_length > 0) {
                memcpy(newBytes, self->_bytes, self->_length);
            }

            self->_bytes = newBytes;
        } else {
            self->_bytes = (uint8_t*)realloc(self->_bytes, self->_capacity);
        }

        self->_freeWhenDone = TRUE;
    } else {
        if (length > self->_capacity) {
            if (self->_capacity < 16) {
                self->_capacity = 16;
            }
            while (self->_capacity < length) {
                self->_capacity *= 2;
            }

            assert(self->_capacity >= length);
            if (self->_freeWhenDone == FALSE) {
                uint8_t* newBytes = (uint8_t*)malloc(self->_capacity);

                if (self->_length > 0) {
                    memcpy(newBytes, self->_bytes, self->_length);
                }

                self->_bytes = newBytes;
            } else {
                self->_bytes = (uint8_t*)realloc(self->_bytes, self->_capacity);
            }

            self->_freeWhenDone = TRUE;
        }
    }
}

+ (instancetype)data {
    return [[[self alloc] initWithLength:0] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)dataWithLength:(unsigned)length {
    return [[[self alloc] initWithLength:length] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)dataWithCapacity:(unsigned)capacity {
    return [[[self alloc] initWithCapacity:capacity] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithLength:(unsigned)length {
    setCapacity(self, length, true);
    memset(_bytes, 0, length);
    _length = length;

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCapacity:(unsigned)length {
    _length = 0;

    return self;
}

/**
 @Status Interoperable
*/
- (void)appendBytes:(const void*)bytes length:(NSUInteger)length {
    setCapacity(self, _length + length);
    memcpy(&_bytes[_length], bytes, length);
    _length += length;
}

/**
 @Status Interoperable
*/
- (void)appendData:(NSData*)data {
    char* bytes = (char*)[data bytes];
    unsigned length = [data length];

    setCapacity(self, _length + length);
    memcpy(&_bytes[_length], bytes, length);
    _length += length;
}

/**
 @Status Interoperable
*/
- (void)setData:(NSData*)data {
    char* bytes = (char*)[data bytes];
    unsigned length = [data length];

    setCapacity(self, length, true);
    memcpy(_bytes, bytes, length);
    _length = length;
}

/**
 @Status Interoperable
*/
- (void)setLength:(unsigned)length {
    unsigned setPos = _length;
    unsigned increasedSize = 0;

    if (length > _length) {
        increasedSize = length - _length;
    }

    setCapacity(self, length, true);
    _length = length;

    if (increasedSize > 0) {
        memset(&_bytes[setPos], 0, increasedSize);
    }
}

/**
 @Status Interoperable
*/
- (void)increaseLengthBy:(unsigned)length {
    unsigned setPos = _length;
    unsigned increasedSize = length;

    setCapacity(self, _length + length, false);
    _length += length;

    memset(&_bytes[setPos], 0, increasedSize);
}

/**
 @Status Interoperable
*/
- (void)replaceBytesInRange:(NSRange)range withBytes:(const void*)bytes {
    if (range.location > _length) {
        [NSException
             raise:NSRangeException
            format:@"location is out of bounds - range.location = %d, range.length = %d, Data length = %d", range.location, range.length, _length];
    }

    if (range.location + range.length > _length) {
        [self increaseLengthBy:(range.location + range.length) - (_length)];
    }

    assert(range.location + range.length <= _length);
    memcpy(&_bytes[range.location], bytes, range.length);
}

/**
 @Status Interoperable
*/
- (void)resetBytesInRange:(NSRange)range {

    if (range.location > _length) {
        [NSException
             raise:NSRangeException
            format:@"location is out of bounds - range.location = %d, range.length = %d, Data length = %d", range.location, range.length, _length];
    }

    if (range.location + range.length > _length) {
        [self increaseLengthBy:(range.location + range.length) - (_length)];
    }

    memset(&_bytes[range.location], 0, range.length);
}

/**
 @Status Interoperable
*/
- (void)replaceBytesInRange:(NSRange)range withBytes:(const void*)bytes length:(unsigned)length {
    // location starts beyond current length, throws
    if (range.location > _length) {
        [NSException
             raise:NSRangeException
            format:@"location is out of bounds - range.location = %d, range.length = %d, Data length = %d", range.location, range.length, _length];
    }

    // calcuate tailLength - e.g., for "1234567890", if replacement happens with the range of "234" with "xxxx", final result is "1xxxx567890"
    // we need shift 567890 to the right - 567890 is the tail, its length - taillength is 6 
    // if, however, we replace range "890" or the tail with anything, there is no need to shift the tail because tail is replaced
    unsigned tailLength = 0;
    if (range.location + range.length < _length) {
        tailLength = _length - (range.location + range.length);
    }

    // calcuate and set newLength/capacity after replace
    unsigned newLength = range.location + length + tailLength;
    setCapacity(self, newLength, true);
    _length = newLength;

    // shift tail to the new location if necessary, notice use memmove in case memory overlap
    if (tailLength > 0) {
        memmove(&_bytes[newLength - tailLength], &_bytes[range.location + range.length], tailLength);
    }

    // do replacement when necessary
    if (length > 0) {
        memcpy(&_bytes[range.location], bytes, length);
    }
}

/**
 @Status Interoperable
*/
- (void*)mutableBytes {
    return (void*)_bytes;
}

- (id)copyWithZone:(NSZone*)zone {
    return [[NSMutableData alloc] initWithData:self];
}

@end
