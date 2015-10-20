/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

// Original - Christopher Lloyd <cjwl@objc.net>

#include "Starboard.h"
#include "Foundation/NSString.h"
#include "Foundation/NSMutableData.h"
#include "Foundation/NSDictionary.h"
#include "Foundation/NSNumber.h"
#include "Foundation/NSDate.h"
#include "NSPropertyListWriter_binary.h"
#include "CoreFoundation/CFDictionary.h"
#include "Foundation/NSMutableArray.h"
#include <limits>

#define NSNotFound 0x7fffffff

#define RELEASE(object) [object release]
#define RETAIN(object) [object retain]
#define DESTROY(object) [object release]
#define AUTORELEASE(object) [object autorelease]
#define ASSIGN(a, b) (a) = RETAIN(b)

WORD NSSwapHostShortToBig(WORD val) {
    return ((val & 0xFF) << 8) | (val >> 8);
}

unsigned __int64 NSSwapHostLongLongToBig(unsigned __int64 val) {
    union {
        unsigned long long word;
        uint8_t bytes[8];
    } value, result;

    value.word = val;

    result.bytes[0] = value.bytes[7];
    result.bytes[1] = value.bytes[6];
    result.bytes[2] = value.bytes[5];
    result.bytes[3] = value.bytes[4];
    result.bytes[4] = value.bytes[3];
    result.bytes[5] = value.bytes[2];
    result.bytes[6] = value.bytes[1];
    result.bytes[7] = value.bytes[0];

    return result.word;
}

NSSwappedFloat NSSwapHostFloatToBig(float val) {
    DWORD ret = NSSwapHostIntToBig(*((DWORD*)&val));

    return *((NSSwappedFloat*)&ret);
}

NSSwappedDouble NSSwapHostDoubleToBig(double val) {
    unsigned __int64 ret = NSSwapHostLongLongToBig(*((unsigned __int64*)&val));

    return *((NSSwappedDouble*)&ret);
}

void storeReversed(void* pos, unsigned value, unsigned width) {
    for (unsigned i = 0; i < width; ++i) {
        char* curr = ((char*)pos) + i;
        *curr = (value >> ((width - i - 1) * 8)) & 0xFF;
    }
}

void appendBytes(NSPropertyListWriter_Binary* self, const void* data, int len) {
    while (self->outBufLen + len > self->outBufMaxLen) {
        self->outBufMaxLen += 64000;

        self->outBuf = (char*)EbrRealloc(self->outBuf, self->outBufMaxLen);
    }

    memcpy(&self->outBuf[self->outBufLen], data, len);
    self->outBufLen += len;
}

@implementation NSPropertyListWriter_Binary : NSObject

+ (void)serializePropertyList:(id)aPropertyList intoData:(NSMutableData*)destination {
    NSPropertyListWriter_Binary* gen = [[NSPropertyListWriter_Binary alloc] initWithPropertyList:aPropertyList intoData:destination];
    [gen generate];
    RELEASE(gen);
}

- (NSPropertyListWriter_Binary*)initWithPropertyList:(id)aPropertyList intoData:(NSMutableData*)destination {
    ASSIGN(root, aPropertyList);
    ASSIGN(_dest, destination);
    [_dest setLength:0];

    return self;
}

- (void)dealloc {
    DESTROY(root);
    [self cleanup];
    DESTROY(_dest);
    if (outBuf)
        EbrFree(outBuf);
    [super dealloc];
}

- (NSMutableData*)data {
    return _dest;
}

- (void)setup {
    [_dest setLength:0];
    if (index_size == 1) {
        table_size = 256;
    } else if (index_size == 2) {
        table_size = 256 * 256;
    } else if (index_size == 3) {
        table_size = 256 * 256 * 256;
    } else if (index_size == 4) {
        table_size = std::numeric_limits<unsigned int>::max();
    }

    table = (unsigned int*)EbrMalloc(table_size * sizeof(int));

    objectsToDoList = [[NSMutableArray alloc] init];
    _objList = CFDictionaryCreateMutable(NULL, 10, &kCFTypeDictionaryKeyCallBacks, NULL);

    [objectsToDoList addObject:root];
    CFDictionarySetValue(_objList, (const void*)root, 0);
}

- (void)cleanup {
    DESTROY(objectsToDoList);
    [(id)_objList release];
    if (table != NULL) {
        EbrFree(table);
        table = NULL;
    }
}

- (void)writeObjects {
    id object;
    const char* prefix = "bplist00";

    appendBytes(self, prefix, strlen(prefix));

    while ([objectsToDoList count] != 0) {
        object = [objectsToDoList objectAtIndex:0];
        [self storeObject:object];
        [objectsToDoList removeObjectAtIndex:0];
    }
}

-(void) markOffset:(unsigned int)offset for:(id)object {
    unsigned int oid = 0;

    if (!CFDictionaryGetValueIfPresent(_objList, (void*)object, (const void**)&oid)) {
        assert(0);
        //[NSException raise: NSGenericException
        // format: @"Unknown object %@.", object];
    }

    if (oid >= table_size) {
        assert(0);
        //[NSException raise: NSRangeException
        // format: @"Object table index out of bounds %d.", oid];
    }

    table[oid] = offset;
}

- (void)writeObjectTable {
    table_start = outBufLen;

    if (table_start < 0xFF)
        offset_size = 1;
    else if (table_start < 0xFFFF)
        offset_size = 2;
    else if (table_start < 0xFFFFFF)
        offset_size = 3;
    else
        offset_size = 4;

    unsigned len = CFDictionaryGetCount(_objList);
    unsigned size = offset_size * len;

    unsigned char* buffer = (unsigned char*)EbrMalloc(size);
    int bufpos = 0;

    for (unsigned i = 0; i < len; i++) {
        int curOffset = table[i];

        if (offset_size == 4) {
            buffer[bufpos++] = (curOffset >> 24) & 0xFF;
            buffer[bufpos++] = (curOffset >> 16) & 0xFF;
            buffer[bufpos++] = (curOffset >> 8) & 0xFF;
            buffer[bufpos++] = curOffset & 0xFF;
        } else if (offset_size == 3) {
            buffer[bufpos++] = (curOffset >> 16) & 0xFF;
            buffer[bufpos++] = (curOffset >> 8) & 0xFF;
            buffer[bufpos++] = curOffset & 0xFF;
        } else if (offset_size == 2) {
            buffer[bufpos++] = (curOffset >> 8) & 0xFF;
            buffer[bufpos++] = curOffset & 0xFF;
        } else {
            buffer[bufpos++] = curOffset & 0xFF;
        }
    }

    appendBytes(self, buffer, size);
    EbrFree(buffer);
}

- (void)writeMetaData {
    unsigned char meta[32] = { 0 };

    meta[6] = offset_size;
    meta[7] = index_size;

    storeReversed(meta + 12, CFDictionaryGetCount(_objList), 4);
    storeReversed(meta + 28, table_start, 4);

    appendBytes(self, meta, 32);
}

- (unsigned)indexForObject:(id)object {
    unsigned index = 0;

    if (!CFDictionaryGetValueIfPresent(_objList, (void*)object, (const void**)&index)) {
        index = CFDictionaryGetCount(_objList);
        CFDictionarySetValue(_objList, (const void*)object, (void*)index);
        [objectsToDoList addObject:object];
    }

    return index;
}

- (void)storeIndex:(int)index {
    if (index_size == 1) {
        unsigned char oid;

        oid = index;
        appendBytes(self, &oid, 1);
    } else if (index_size == 2) {
        unsigned short oid;

        oid = NSSwapHostShortToBig(index);
        appendBytes(self, &oid, 2);
    } else if (index_size == 4) {
        unsigned int oid;

        oid = NSSwapHostIntToBig(index);
        appendBytes(self, &oid, 4);
    } else {
        //[NSException raise: NSGenericException
        //  format: @"Unknown table size %d", index_size];
    }
}

- (void)storeCount:(int)count {
    unsigned char code;

    if (count < 256) {
        unsigned char c;

        code = 0x10;
        appendBytes(self, &code, 1);
        c = count;
        appendBytes(self, &c, 1);
    } else if (count < 256 * 256) {
        unsigned short c;

        code = 0x11;
        appendBytes(self, &code, 1);
        c = count;
        c = NSSwapHostShortToBig(c);
        appendBytes(self, &c, 2);
    } else {
        code = 0x13;
        appendBytes(self, &code, 1);
        count = NSSwapHostIntToBig(count);
        appendBytes(self, &count, 4);
    }
}

- (void)storeData:(id)data {
    unsigned int len;
    unsigned char code;

    len = [data length];

    if (len < 0x0F) {
        code = 0x40 + len;
        appendBytes(self, &code, 1);
        appendBytes(self, (char*)[data bytes], [data length]);
    } else {
        code = 0x4F;
        appendBytes(self, &code, 1);
        [self storeCount:len];
        appendBytes(self, (char*)[data bytes], [data length]);
    }
}

- (void)storeString:(NSString*)string {
    BOOL ascii = YES;
    unsigned char code;
    unsigned int i;

    unsigned len = [string length];

    /*
    for (i = 0; i < len; i++)
    {
    WORD uchar = [string characterAtIndex:i];
    if (uchar > 127)
    {
    ascii = NO;
    break;
    }
    }
    */

    if (ascii) {
        if (len < 0x0F) {
            code = 0x50 + len;
            appendBytes(self, &code, 1);
            appendBytes(self, (char*)[string UTF8String], len);
        } else {
            code = 0x5F;
            appendBytes(self, &code, 1);
            [self storeCount:len];
            appendBytes(self, (char*)[string UTF8String], len);
        }
    } else {
        if (len < 0x0F) {
            WORD* buffer = (WORD*)EbrMalloc((len + 1) * 2);

            code = 0x60 + len;
            appendBytes(self, &code, 1);
            [string getCharacters:buffer];
            for (unsigned int i = 0; i < len; i++) {
                buffer[i] = NSSwapHostShortToBig(buffer[i]);
            }
            appendBytes(self, buffer, len * sizeof(WORD));
            EbrFree(buffer);
        } else {
            WORD* buffer;

            code = 0x6F;
            appendBytes(self, &code, 1);
            buffer = (WORD*)EbrMalloc(sizeof(WORD) * (len + 1));
            [self storeCount:len];
            [string getCharacters:buffer];
            for (i = 0; i < len; i++) {
                buffer[i] = NSSwapHostShortToBig(buffer[i]);
            }
            appendBytes(self, buffer, sizeof(WORD) * len);
            EbrFree(buffer);
        }
    }
}

- (void)storeNumber:(NSNumber*)number {
    unsigned char code;

    const char* type = (const char*)[number objCType];

    switch (*type) {
        case 'c':
        case 'C':
        case 's':
        case 'S':
        case 'i':
        case 'I':
        case 'l':
        case 'L':
        case 'q':
        case 'Q': {
            unsigned long long val;

            [number _copyInt64Value:&val];

            // FIXME: We need a better way to determine boolean values!
            if ((val == 0) && ((*type == 'c') || (*type == 'C'))) {
                code = 0x08;
                appendBytes(self, &code, 1);
            } else if ((val == 1) && ((*type == 'c') || (*type == 'C'))) {
                code = 0x09;
                appendBytes(self, &code, 1);
            } else if (val < 256) {
                unsigned char cval;

                code = 0x10;
                appendBytes(self, &code, 1);
                cval = (unsigned char)val;
                appendBytes(self, &cval, 1);
            } else if (val < 256 * 256) {
                unsigned short sval;

                code = 0x11;
                appendBytes(self, &code, 1);
                sval = NSSwapHostShortToBig((WORD)([number unsignedShortValue]));
                appendBytes(self, &sval, 2);
            } else if (val <= std::numeric_limits<unsigned int>::max()) {
                unsigned int ival;

                code = 0x12;
                appendBytes(self, &code, 1);
                ival = NSSwapHostIntToBig([number unsignedIntValue]);
                appendBytes(self, &ival, 4);
            } else {
                unsigned long long lval;

                code = 0x13;
                appendBytes(self, &code, 1);
                [number _copyInt64Value:&lval];
                lval = NSSwapHostLongLongToBig(lval);
                appendBytes(self, &lval, 8);
            }

            break;
        }

        case 'f': {
            NSSwappedFloat val = NSSwapHostFloatToBig([number floatValue]);

            code = 0x22;
            appendBytes(self, &code, 1);
            appendBytes(self, &val, sizeof(float));
            break;
        }

        case 'd': {
            NSSwappedDouble val = NSSwapHostDoubleToBig([number doubleValue]);

            code = 0x23;
            appendBytes(self, &code, 1);
            appendBytes(self, &val, sizeof(double));
            break;
        }

        default:
            //[NSException raise: NSGenericException
            // format: @"Attempt to store number with unknown ObjC type"];
            assert(0);
            break;
    }
}

- (void)storeDate:(id)date {
    unsigned char code = 0x33;
    appendBytes(self, &code, 1);
    NSSwappedDouble out = NSSwapHostDoubleToBig([date timeIntervalSinceReferenceDate]);
    appendBytes(self, &out, sizeof(double));
}

- (void)storeArray:(id)array {
    unsigned char code;
    unsigned int i;

    unsigned len = [array count];

    if (len < 0x0F) {
        code = 0xA0 + len;
        appendBytes(self, &code, 1);
    } else {
        code = 0xAF;
        appendBytes(self, &code, 1);
        [self storeCount:len];
    }

    for (i = 0; i < len; i++) {
        id obj;
        unsigned int oid;

        obj = [array objectAtIndex:i];
        oid = [self indexForObject:obj];
        [self storeIndex:oid];
    }
}

- (void)storeDictionary:(id)dict {
    unsigned char code;
    unsigned int i;

    NSNumber* num = [dict objectForKey:@"CF$UID"];
    if (num != nil) {
        // Special dictionary from keyed encoding
        unsigned int index;

        index = [num intValue];
        if (index < 256) {
            unsigned char ci;

            code = 0x80;
            appendBytes(self, &code, 1);
            ci = (unsigned char)index;
            appendBytes(self, &ci, 1);
        } else {
            unsigned short si;

            code = 0x81;
            appendBytes(self, &code, 1);
            si = NSSwapHostShortToBig((unsigned short)index);
            appendBytes(self, &si, 2);
        }
    } else {
        unsigned int len = [dict count];
        NSArray* keys = [dict allKeys];
        NSMutableArray* objects = [NSMutableArray arrayWithCapacity:len];
        id key;

        for (i = 0; i < len; i++) {
            key = [keys objectAtIndex:i];
            [objects addObject:[dict objectForKey:key]];
        }

        if (len < 0x0F) {
            code = 0xD0 + len;
            appendBytes(self, &code, 1);
        } else {
            code = 0xDF;
            appendBytes(self, &code, 1);
            [self storeCount:len];
        }

        for (i = 0; i < len; i++) {
            id obj;
            unsigned int oid;

            obj = [keys objectAtIndex:i];
            oid = [self indexForObject:obj];
            [self storeIndex:oid];
        }

        for (i = 0; i < len; i++) {
            id obj;
            unsigned int oid;

            obj = [objects objectAtIndex:i];
            oid = [self indexForObject:obj];
            [self storeIndex:oid];
        }
    }
}

- (void)storeObject:(id)object {
[self markOffset:outBufLen for:object];

if ([object isKindOfClass:[NSString class]]) {
    [self storeString:object];
} else if ([object isKindOfClass:[NSData class]]) {
    [self storeData:object];
} else if ([object isKindOfClass:[NSNumber class]]) {
    [self storeNumber:object];
} else if ([object isKindOfClass:[NSDate class]]) {
    [self storeDate:object];
} else if ([object isKindOfClass:[NSArray class]]) {
    [self storeArray:object];
} else if ([object isKindOfClass:[NSDictionary class]]) {
    [self storeDictionary:object];
} else {
    EbrDebugLog("Unknown object class %s\n", object_getClassName(object));
}
}

- (void)generate {
    BOOL done = NO;

    index_size = 2;

    while (!done && (index_size <= 4)) {
        [self setup];
        [self writeObjects];
        done = YES;
    }

    [self writeObjectTable];
    [self writeMetaData];

    [_dest appendBytes:outBuf length:outBufLen];
}

@end
