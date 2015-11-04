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
#include "Foundation/NSError.h"
#include "Foundation/NSString.h"

@implementation NSData : NSObject

/**
 @Status Stub
*/
- (NSString*)base64EncodedStringWithOptions:(NSDataBase64EncodingOptions)options {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
- (id)initWithBase64EncodedString:(NSString*)base64String options:(NSDataBase64DecodingOptions)options {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Interoperable
*/
+ (instancetype)dataWithData:(NSData*)data {
    return [[[self alloc] initWithData:data] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)data {
    return [[[self alloc] init] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)dataWithBytes:(const void*)bytes length:(unsigned)length {
    NSData* newObj = [self alloc];
    NSData* pNewObj = (NSData*)newObj;

    pNewObj->_bytes = (uint8_t*)malloc(length);
    pNewObj->_freeWhenDone = TRUE;
    memcpy(pNewObj->_bytes, bytes, length);
    pNewObj->_length = length;

    return [newObj autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)dataWithBytesNoCopy:(void*)bytes length:(unsigned)length {
    return [[[self alloc] initWithBytesNoCopy:(void*)bytes length:length freeWhenDone:TRUE] autorelease];
}

/**
 @Status Caveat
 @Notes The CRT used between Islandwood and the application must match if freeWhenDone=TRUE
*/
+ (instancetype)dataWithBytesNoCopy:(void*)bytes length:(unsigned)length freeWhenDone:(BOOL)free {
    return [[[self alloc] initWithBytesNoCopy:(void*)bytes length:length freeWhenDone:free] autorelease];
}

- (instancetype)init {
    return [self initWithBytes:"" length:0];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithData:(NSData*)data {
    return [self initWithBytes:[data bytes] length:[data length]];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithBytes:(const void*)bytes length:(unsigned)length {
    _bytes = (uint8_t*)malloc(length);
    _freeWhenDone = TRUE;
    memcpy(_bytes, bytes, length);
    _length = length;

    return self;
}

- (void)encodeWithCoder:(NSCoder*)coder {
    [coder encodeBytes:_bytes length:_length forKey:@"NS.data"];
}

- (instancetype)initWithCoder:(NSCoder*)coder {
    NSData* nsData = [coder decodeObjectForKey:@"NS.data"];

    return [self initWithData:nsData];
}

/**
 @Status Caveat
 @Notes The CRT used between Islandwood and the application must match if freeWhenDone=TRUE
*/
- (instancetype)initWithBytesNoCopy:(void*)bytes length:(unsigned)length freeWhenDone:(BOOL)freeWhenDone {
    _bytes = (uint8_t*)bytes;
    _length = length;
    _freeWhenDone = freeWhenDone;

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithBytesNoCopy:(void*)bytes length:(unsigned)length {
    _bytes = (uint8_t*)bytes;
    _length = length;
    _freeWhenDone = TRUE;

    return self;
}

/**
 @Status Interoperable
*/
- (void)getBytes:(void*)dest {
    memcpy(dest, _bytes, _length);
}

/**
 @Status Interoperable
*/
- (void)getBytes:(void*)dest length:(unsigned)length {
    if (length > _length) {
        length = _length;
    }
    memcpy(dest, _bytes, length);
}

/**
 @Status Interoperable
*/
- (void)getBytes:(void*)dest range:(NSRange)range {
    assert(range.location + range.length <= _length);

    memcpy(dest, &_bytes[range.location], range.length);
}

/**
 @Status Caveat
 @Notes File is not mapped; defers to initWithContentsOfFile:
*/
- (instancetype)initWithContentsOfMappedFile:(NSString*)filename {
    EbrDebugLog("Not actually mapping file ...\n");
    return [self initWithContentsOfFile:filename];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithContentsOfFile:(NSString*)filename {
    if (filename == nil) {
        return nil;
    }

    char* fname = (char*)[filename UTF8String];

    EbrDebugLog("NSData opening %s\n", fname);
    EbrFile* fpIn = EbrFopen(fname, "rb");
    if (fpIn) {
        EbrFseek(fpIn, 0, SEEK_END);
        _length = EbrFtell(fpIn);
        EbrFseek(fpIn, 0, SEEK_SET);

        _bytes = (uint8_t*)malloc(_length);
        _freeWhenDone = TRUE;
        _length = EbrFread(_bytes, 1, _length, fpIn);
        EbrFclose(fpIn);
    } else {
        EbrDebugLog("NSData couldn't open %s for read\n", fname);
        _bytes = NULL;
        _length = 0;
        return nil;
    }

    return self;
}

/**
 @Status Caveat
 @Notes atomically parameter not supported
*/
- (BOOL)writeToFile:(NSString*)filename atomically:(BOOL)atomically {
    char* fname = (char*)[filename UTF8String];

    EbrDebugLog("NSData writing %s (%d bytes)\n", fname, _length);
    if (!fname) {
        EbrDebugLog("Filename is null!\n");
        return FALSE;
    }
    EbrFile* fpOut = EbrFopen((const char*)fname, "wb");
    if (fpOut) {
        EbrFwrite(_bytes, 1, _length, fpOut);
        EbrFclose(fpOut);

        return TRUE;
    } else {
        EbrDebugLog("NSData couldn't open %s for write\n", fname);
        return FALSE;
    }
}

/**
 @Status Caveat
 @Notes Only file:// URLs supported. atomically parameter not supported.
*/
- (BOOL)writeToURL:(NSURL*)url atomically:(BOOL)atomically {
    if (![url isFileURL]) {
        EbrDebugLog("-[NSData::writeToURL]: Only file: URLs are supported. (%s)", [[url absoluteString] UTF8String]);
        return NO;
    }
    return [self writeToFile:[url path] atomically:atomically];
}

/**
 @Status Caveat
 @Notes options parameter not supported
*/
- (BOOL)writeToFile:(NSString*)filename options:(unsigned)options error:(NSError**)error {
    char* fname = (char*)[filename UTF8String];

    EbrDebugLog("NSData writing %s (%d bytes)\n", fname, _length);
    EbrFile* fpOut = EbrFopen((const char*)fname, "wb");
    if (fpOut) {
        EbrFwrite(_bytes, 1, _length, fpOut);
        EbrFclose(fpOut);

        return TRUE;
    } else {
        EbrDebugLog("NSData couldn't open %s for write (with options)\n", fname);
        return FALSE;
    }
}

/**
 @Status Interoperable
*/
+ (instancetype)dataWithContentsOfFile:(NSString*)filename {
    return [[[self alloc] initWithContentsOfFile:filename] autorelease];
}

/**
 @Status Caveat
 @Notes File is not mapped; defers to initWithContentsOfFile:
*/
+ (instancetype)dataWithContentsOfMappedFile:(NSString*)filename {
    return [[[self alloc] initWithContentsOfMappedFile:filename] autorelease];
}

/**
 @Status Caveat
 @Notes options parameter not supported
*/
- (instancetype)initWithContentsOfFile:(NSString*)filename options:(unsigned)options error:(NSError**)error {
    if (filename == nil) {
        if (error) {
            *error = [NSError errorWithDomain:@"NSData" code:100 userInfo:nil];
        }
        return nil;
    }

    char* fname = (char*)[filename UTF8String];

    EbrDebugLog("NSData extended-opening %s\n", fname);
    EbrFile* fpIn = EbrFopen(fname, "rb");
    if (fpIn) {
        EbrFseek(fpIn, 0, SEEK_END);
        _length = EbrFtell(fpIn);
        EbrFseek(fpIn, 0, SEEK_SET);

        _bytes = (uint8_t*)malloc(_length);
        _freeWhenDone = TRUE;
        _length = EbrFread(_bytes, 1, _length, fpIn);
        EbrFclose(fpIn);
    } else {
        EbrDebugLog("NSData couldn't open %s for read (extended)\n", fname);
        _bytes = NULL;
        _length = 0;
        if (error) {
            *error = [NSError errorWithDomain:@"NSData" code:100 userInfo:nil];
        }
        return nil;
    }

    return self;
}

/**
 @Status Caveat
 @Notes options parameter not supported
*/
+ (instancetype)dataWithContentsOfFile:(NSString*)filename options:(unsigned)options error:(NSError**)error {
    return [[[self alloc] initWithContentsOfFile:filename options:options error:error] autorelease];
}

/**
 @Status Caveat
 @Notes options parameter not supported
*/
+ (instancetype)dataWithContentsOfURL:(NSURL*)url options:(unsigned)options error:(NSError**)error {
    id ret = [self alloc];
    return [[ret initWithContentsOfURL:url options:options error:error] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)dataWithContentsOfURL:(NSURL*)url {
    id ret = [self alloc];
    return [[ret initWithContentsOfURL:url] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithContentsOfURL:(NSURL*)url {
    return [self initWithContentsOfURL:url options:0 error:NULL];
}

/**
 @Status Caveat
 @Notes options parameter not supported
*/
- (instancetype)initWithContentsOfURL:(NSURL*)url options:(unsigned)options error:(NSError**)error {
    EbrDebugLog("initWithContentsOfURL: %s\n", [[url absoluteString] UTF8String]);

    if ([url isFileURL]) {
        return [self initWithContentsOfFile:[url path] options:options error:error];
    }

    NSURLRequest* request = [NSURLRequest requestWithURL:url];
    id response; // what type is this?
    NSData* data = [NSURLConnection sendSynchronousRequest:request returningResponse:&response error:error];

    return [self initWithData:data];
}

/**
 @Status Interoperable
*/
- (instancetype)subdataWithRange:(NSRange)range {
    return [NSData dataWithBytes:_bytes + range.location length:range.length];
}

- (id)copyWithZone:(NSZone*)zone {
    return [self retain];
}

- (NSMutableData*)mutableCopyWithZone:(void**)zone {
    return [[NSMutableData alloc] initWithData:self];
}

/**
 @Status Interoperable
*/
- (BOOL)isEqualToData:(NSData*)data {
    NSData* other = (NSData*)data;
    if (_length != other->_length) {
        return false;
    }
    return memcmp(_bytes, other->_bytes, _length) == 0;
}

- (BOOL)isEqual:(id)objAddr {
    if (objAddr == self) {
        return TRUE;
    }
    if (objAddr != nil && [objAddr isKindOfClass:[NSData class]]) {
        return [self isEqualToData:objAddr];
    }

    return FALSE;
}

/**
 @Status Interoperable
*/
- (NSString*)description {
    const char* hex = "0123456789abcdef";
    const char* bytes = (const char*)[self bytes];
    NSUInteger length = [self length];
    NSUInteger pos = 0, i;
    char* cString;

    cString = (char*)malloc(1 + length * 2 + (length / 4) + 1);

    cString[pos++] = '<';
    for (i = 0; i < length;) {
        unsigned char byte = bytes[i];

        cString[pos++] = hex[byte >> 4];
        cString[pos++] = hex[byte & 0x0F];
        i++;

        if ((i % 4) == 0 && i < length) {
            cString[pos++] = ' ';
        }
    }
    cString[pos++] = '>';

    NSString* ret = [[[NSString alloc] initWithBytes:cString length:pos encoding:NSUTF8StringEncoding] autorelease];
    free(cString);

    return ret;
}

/**
 @Status Interoperable
*/
- (const void*)bytes {
    return _bytes;
}

/**
 @Status Interoperable
*/
- (unsigned)length {
    return _length;
}

- (void)dealloc {
    if (_freeWhenDone) {
        free(_bytes);
    }

    [super dealloc];
}

@end
