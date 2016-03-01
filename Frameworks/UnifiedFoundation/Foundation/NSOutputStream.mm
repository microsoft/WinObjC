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
#include "Foundation/NSStream.h"
#include "Foundation/NSMutableData.h"
#include "Foundation/NSNumber.h"
#include "Foundation/NSOutputStream.h"
#include "NSStreamInternal.h"

@interface NSOutputStream () {
    NSString* _filename;
    unsigned _append;
    NSMutableData* _data;
}
@end

@implementation NSOutputStream

/**
 @Status Interoperable
*/
+ (instancetype)outputStreamToFileAtPath:(NSString*)file append:(BOOL)append {
    id ret = [self alloc];

    [ret initToFileAtPath:file append:append];

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)outputStreamToMemory {
    id ret = [self alloc];

    [ret initToMemory];

    return [ret autorelease];
}

/**
 @Status Stub
*/
+ (instancetype)outputStreamToBuffer:(uint8_t*)buffer capacity:(NSUInteger)capacity {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
+ (instancetype)outputStreamWithURL:(NSURL*)url append:(BOOL)shouldAppend {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Interoperable
*/
- (instancetype)initToFileAtPath:(NSString*)file append:(BOOL)append {
    _append = append;

    _filename = file;
    EbrDebugLog("NSOutputStream opening %s\n", [file UTF8String]);

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initToMemory {
    _data = [NSMutableData new];

    return self;
}

/**
 @Status Stub
*/
- (instancetype)initToBuffer:(uint8_t*)buffer capacity:(NSUInteger)capacity {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
- (instancetype)initWithURL:(NSURL*)url append:(BOOL)shouldAppend {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Interoperable
*/
- (NSInteger)write:(const uint8_t*)buf maxLength:(NSUInteger)maxLength {
    if (_data) {
        [_data appendBytes:buf length:maxLength];

        return maxLength;
    } else {
        return EbrFwrite(const_cast<uint8_t*>(buf), 1, maxLength, fp);
    }
}

- (id)_setAppend:(BOOL)append {
    _append = append;
    return 0;
}

/**
 @Status Interoperable
*/
- (id)propertyForKey:(id)key {
    if ([key isEqualToString:@"NSStreamFileCurrentOffsetKey"]) {
        if (_data) {
            return [NSNumber numberWithInteger:[_data length]];
        } else {
            return [NSNumber numberWithInteger:(int)EbrFtell(fp)];
        }
    } else if ([key isEqualToString:@"NSStreamDataWrittenToMemoryStreamKey"]) {
        if (_data) {
            return _data;
        } else {
            assert(0);
        }
    } else {
        assert(0);
    }
    return 0;
}

/**
 @Status Interoperable
*/
- (BOOL)setProperty:(id)prop forKey:(id)key {
    if ([key isEqualToString:@"NSStreamFileCurrentOffsetKey"]) {
        if (_data) {
            [_data setLength:[prop intValue]];
        } else {
            assert(0);
        }
    } else {
        assert(0);
    }
    return 0;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    [_data release];
    [super dealloc];
}

/**
 @Status Caveat
 @Notes Always returns YES
*/
- (BOOL)hasSpaceAvailable {
    return YES;
}

/**
 @Status Interoperable
*/
- (void) /* use typed version */ open {
    if (_data) {
        _status = NSStreamStatusOpen;
    } else {
        char* mode = const_cast<char*>("wb");

        if (_append) {
            mode = const_cast<char*>("ab");
        }
        EbrDebugLog("Opening %s for writing\n", [_filename UTF8String]);
        fp = EbrFopen([_filename UTF8String], mode);
        if (!fp) {
            EbrDebugLog("Open of %s failed\n", [_filename UTF8String]);
            _status = NSStreamStatusNotOpen;
        } else {
            _status = NSStreamStatusOpen;
        }
    }
}

@end
