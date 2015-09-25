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
#include "Foundation/NSMutableData.h"

@implementation NSMutableData : NSData
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
            if (self->_capacity < 16)
                self->_capacity = 16;
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

+ (instancetype)dataWithLength:(unsigned)length {
    return [[[self alloc] initWithLength:length] autorelease];
}

+ (instancetype)dataWithCapacity:(unsigned)capacity {
    return [[[self alloc] initWithCapacity:capacity] autorelease];
}

- (instancetype)initWithLength:(unsigned)length {
    setCapacity(self, length, true);
    memset(_bytes, 0, length);
    _length = length;

    return self;
}

- (instancetype)initWithCapacity:(unsigned)length {
    _length = 0;

    return self;
}

- (void)appendBytes:(const char*)bytes length:(unsigned)length {
    setCapacity(self, _length + length);
    memcpy(&_bytes[_length], bytes, length);
    _length += length;
}

- (void)appendData:(NSData*)data {
    char* bytes = (char*)[data bytes];
    unsigned length = [data length];

    setCapacity(self, _length + length);
    memcpy(&_bytes[_length], bytes, length);
    _length += length;
}

- (void)setData:(NSData*)data {
    char* bytes = (char*)[data bytes];
    unsigned length = [data length];

    setCapacity(self, length, true);
    memcpy(_bytes, bytes, length);
    _length = length;
}

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

- (void)increaseLengthBy:(unsigned)length {
    unsigned setPos = _length;
    unsigned increasedSize = length;

    setCapacity(self, _length + length, false);
    _length += length;

    memset(&_bytes[setPos], 0, increasedSize);
}

- (void)replaceBytesInRange:(NSRange)range withBytes:(void*)bytes {
    if (range.location + range.length > _length) {
        [self increaseLengthBy:(range.location + range.length) - (_length)];
    }

    assert(range.location + range.length <= _length);
    memcpy(&_bytes[range.location], bytes, range.length);
}

- (void)replaceBytesInRange:(NSRange)aRange withBytes:(void*)bytes length:(unsigned)length {
    if (aRange.location == 0 && aRange.length == _length && length == 0) {
        [self setLength:0];
        return;
    }
    assert(!"replaceBytesInRangeLength not implemented!");
}

- (uint8_t*)mutableBytes {
    return _bytes;
}

- (id)copyWithZone:(id)zone {
    return [[NSMutableData alloc] initWithData:self];
}

@end
