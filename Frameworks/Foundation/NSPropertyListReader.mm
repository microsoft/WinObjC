/* Copyright (c) 2007 Michael Ash
Copyright (c) 2007 Jens Ayton (uid decoding)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "Starboard.h"
#include "NSPropertyListReader.h"

#include "Foundation/NSNumber.h"
#include "Foundation/NSNull.h"
#include "Foundation/NSData.h"
#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSMutableArray.h"

void NSPropertyListReaderA::_readHeader() {
    uint64_t trailerStart = (uint64_t)([_data length] - TRAILER_SIZE);

    _trailerOffsetIntSize = (uint8_t)_readIntOfSize(sizeof(_trailerOffsetIntSize), &trailerStart);
    _trailerOffsetRefSize = (uint8_t)_readIntOfSize(sizeof(_trailerOffsetRefSize), &trailerStart);
    _trailerNumObjects = _readIntOfSize(sizeof(_trailerNumObjects), &trailerStart);
    _trailerTopObject = _readIntOfSize(sizeof(_trailerTopObject), &trailerStart);
    _trailerOffsetTableOffset = _readIntOfSize(sizeof(_trailerOffsetTableOffset), &trailerStart);
}

uint64_t NSPropertyListReaderA::_readIntOfSize(size_t size, uint64_t* offsetPtr) {
    uint64_t ret = 0;
    const uint8_t* ptr = (const uint8_t*)(_dataBytes + *offsetPtr);
    size_t i;
    for (i = 0; i < size; i++) {
        ret <<= 8;
        ret |= *ptr;
        ptr++;
    }

    *offsetPtr += size;

    return ret;
}

NSDictionary* NSPropertyListReaderA::ExtractUID(const uint8_t* ptr, unsigned length, uint64_t offset) {
    /*        UIDs are used by Cocoa's key-value coder.
    When writing other plist formats, they are expanded to dictionaries of
    the form <dict><key>CF$UID</key><integer>value</integer></dict>, so we
    do the same here on reading. This results in plists identical to what
    running plutil -convert xml1 gives us. However, this is not the same
    result as [Core]Foundation's plist parser, which extracts them as un-
    introspectable CF objects. In fact, it even seems to convert the CF$UID
    dictionaries from XML plists on the fly.
    */

    uint64_t value;

    if (!ReadSelfSizedInt(ptr, length, offset, &value, NULL)) {
        return 0;
    }

    NSNumber* num = [[NSNumber alloc] initWithLongLong:value];
    NSDictionary* ret = [[NSDictionary alloc] initWithObject:num forKey:@"CF$UID"];
    [num release];

    return ret;
}

double NSPropertyListReaderA::_readFloatOfSize(size_t size, uint64_t* offsetPtr) {
    uint64_t val = _readIntOfSize(size, offsetPtr);

    if (size == 4) {
        uint32_t val32 = (uint32_t)val;
        return *(float*)&val32;
    }
    if (size == 8) {
        return *(double*)&val;
    }

    assert(0);
    return 0.0;
}

int NSPropertyListReaderA::readLongLength(uint64_t* offset) {
    const uint8_t* ptr = (const uint8_t*)_dataBytes;
    uint8_t marker = ptr[*offset];

    (*offset)++;

    uint8_t topNibble = marker >> 4;
    uint8_t botNibble = marker & 0x0F;

    if (topNibble == 0x1)
        return (int)_readIntOfSize(1 << botNibble, offset);
    if (topNibble == 0x2) {
        size_t size = 1 << botNibble;
        uint64_t val = _readIntOfSize(size, offset);

        if (size == 4) {
            return (int)*((float*)&val);
        }
        if (size == 8) {
            return (int)*((double*)&val);
        }
        return 0;
    }

    assert(0);
    return 0;
}

id NSPropertyListReaderA::_readObjectAtOffset(uint64_t* offset) {
    const uint8_t* ptr = (const uint8_t*)_dataBytes;
    uint8_t marker = ptr[*offset];

    (*offset)++;

    if (marker == 0x00)
        return [NSNull new];

    if (marker == 0x08)
        return (id)kCFBooleanFalse;
    if (marker == 0x09)
        return (id)kCFBooleanTrue;

    uint8_t topNibble = marker >> 4;
    uint8_t botNibble = marker & 0x0F;

    if (topNibble == 0x1)
        return [[NSNumber alloc] initWithLongLong:(_readIntOfSize(1 << botNibble, offset))];
    if (topNibble == 0x2) {
        size_t size = 1 << botNibble;
        uint64_t val = _readIntOfSize(size, offset);

        if (size == 4) {
            uint32_t val32 = (uint32_t)val;
            return [[NSNumber alloc] initWithFloat:*(float*)&val32];
        }
        if (size == 8) {
            return [[NSNumber alloc] initWithDouble:*(double*)&val];
        }
        return [[NSNumber alloc] initWithDouble:0.0];
    }
    if (topNibble == 0x3)
        return [[NSDate alloc] initWithTimeIntervalSinceReferenceDate:_readFloatOfSize(8, offset)];

    if (topNibble == 0x4 || topNibble == 0x5 || topNibble == 0x6 || topNibble == 0x8 || topNibble == 0xA ||
        topNibble == 0xD) {
        size_t length = 0;
        if (botNibble != 0xF)
            length = botNibble;
        else {
            length = readLongLength(offset);
        }

        if (topNibble == 0x4)
            return [[NSData alloc] initWithBytes:_dataBytes + *offset length:length];
        if (topNibble == 0x5)
            return [[NSString alloc] initWithBytes:_dataBytes + *offset length:length encoding:NSASCIIStringEncoding];
        if (topNibble == 0x6) {
            return [[NSString alloc] initWithBytes:_dataBytes + *offset
                                            length:(length * 2)
                                          encoding:NSUTF16BigEndianStringEncoding];
        }
        if (topNibble == 0x8)
            return ExtractUID(_dataBytes, _length, (*offset) - 1);

        if (topNibble == 0xA) {
            NSArray* result;
            id* objs = (id*)EbrMalloc(length * sizeof(id));
            uint64_t i;
            for (i = 0; i < length; i++)
                objs[i] = _readInlineObjectAtOffset(offset);

            if ((_flags & kCFPropertyListMutableContainers) || (_flags & kCFPropertyListMutableContainersAndLeaves)) {
                result = [[NSMutableArray alloc] initWithObjectsTakeOwnership:objs count:length];
            } else {
                result = [[NSArray alloc] initWithObjectsTakeOwnership:objs count:length];
            }

            EbrFree(objs);
            return result;
        }

        if (topNibble == 0xD) {
            id result;
            id* keys = (id*)EbrMalloc(length * sizeof(id));
            id* objs = (id*)EbrMalloc(length * sizeof(id));
            uint64_t i;
            for (i = 0; i < length; i++)
                keys[i] = _readInlineObjectAtOffset(offset);
            for (i = 0; i < length; i++)
                objs[i] = _readInlineObjectAtOffset(offset);

            if ((_flags & kCFPropertyListMutableContainers) || (_flags & kCFPropertyListMutableContainersAndLeaves)) {
                result = [[NSMutableDictionary alloc] initWithObjectsTakeOwnership:objs forKeys:keys count:length];
            } else {
                result = [[NSDictionary alloc] initWithObjectsTakeOwnership:objs forKeys:keys count:length];
            }

            EbrFree(keys);
            EbrFree(objs);
            return result;
        }
    }

    assert(0);
    return 0;
}

id NSPropertyListReaderA::_readInlineObjectAtOffset(uint64_t* offset) {
    // first read the offset table index out of the file
    uint64_t objOffset = _readIntOfSize(_trailerOffsetRefSize, offset);

    // then transform the index into an offset in the file which points to
    // that offset table entry
    objOffset = _trailerOffsetTableOffset + objOffset * _trailerOffsetIntSize;

    // lastly read the offset stored at that entry
    objOffset = _readIntOfSize(_trailerOffsetIntSize, &objOffset);

    // and read the object stored there
    return _readObjectAtOffset(&objOffset);
}

id NSPropertyListReaderA::read() {
    id result = NULL;
    _dataBytes = (uint8_t*)[_data bytes];
    _length = [_data length];

    if ([_data length] < TRAILER_SIZE) {
        return nil;
    }
    if (memcmp((void*)[_data bytes], "bplist", 6) != 0) {
        EbrDebugLog("Not a plist file\n");
        return nil;
    }

    EbrDebugLog("got %d bytes\n", _length);

    //@try
    _readHeader();

    uint64_t offset = _trailerTopObject + strlen(MAGIC FORMAT);
    result = _readObjectAtOffset(&offset);

    return [result autorelease];
}