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

@implementation NSOutputStream : NSStream
+ (id)outputStreamToFileAtPath:(id)file append:(BOOL)append {
    id ret = [self alloc];

    [ret initToFileAtPath:file append:append];

    return [ret autorelease];
}

+ (id)outputStreamToMemory {
    id ret = [self alloc];

    [ret initToMemory];

    return [ret autorelease];
}

- (id)initToFileAtPath:(id)file append:(BOOL)append {
    _append = append;

    filename = file;
    EbrDebugLog("NSOutputStream opening %s\n", [file UTF8String]);

    return self;
}

- (id)initToMemory {
    data = [NSMutableData new];

    return self;
}

- (NSInteger)write:(char*)buf maxLength:(NSUInteger)maxLength {
    if (data) {
        [data appendBytes:buf length:maxLength];

        return maxLength;
    } else {
        return EbrFwrite(buf, 1, maxLength, fp);
    }
}

- (id)_setAppend:(BOOL)append {
    _append = append;
    return 0;
}

- (void)scheduleInRunLoop:(id)runLoop forMode:(id)mode {
}

- (id)propertyForKey:(id)key {
    if ([key isEqualToString:@"NSStreamFileCurrentOffsetKey"]) {
        if (data) {
            return [NSNumber numberWithInteger:[data length]];
        } else {
            return [NSNumber numberWithInteger:(int)EbrFtell(fp)];
        }
    } else if ([key isEqualToString:@"NSStreamDataWrittenToMemoryStreamKey"]) {
        if (data) {
            return data;
        } else {
            assert(0);
        }
    } else {
        assert(0);
    }
    return 0;
}

- (BOOL)setProperty:(id)prop forKey:(id)key {
    if ([key isEqualToString:@"NSStreamFileCurrentOffsetKey"]) {
        if (data) {
            [data setLength:[prop intValue]];
        } else {
            assert(0);
        }
    } else {
        assert(0);
    }
    return 0;
}

- (void)dealloc {
    [data release];
    [super dealloc];
}

- (BOOL)hasSpaceAvailable {
    return YES;
}

- (void) /* use typed version */ open {
    if (data) {
        _status = NSStreamStatusOpen;
    } else {
        char* mode = "wb";

        if (_append)
            mode = "ab";

        EbrDebugLog("Opening %s for writing\n", [filename UTF8String]);
        fp = EbrFopen([filename UTF8String], mode);
        if (!fp) {
            EbrDebugLog("Open of %s failed\n", [filename UTF8String]);
            _status = NSStreamStatusNotOpen;
        } else {
            _status = NSStreamStatusOpen;
        }
    }
}

@end
