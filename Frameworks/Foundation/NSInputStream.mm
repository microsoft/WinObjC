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
#include "Foundation/NSString.h"
#include "Foundation/NSInputStream.h"
#include "NSStreamInternal.h"

#ifdef WIN32
#include <io.h>
#elif defined(WINPHONE)
#else
//#include <unistd.h>
#endif

@implementation NSInputStream : NSStream
+ (id)inputStreamWithFileAtPath:(id)file {
    NSInputStream* ret = [self alloc];

    ret->filename = file;
    if (EbrAccess([file UTF8String], 0) != 0) {
        EbrDebugLog("Open failed\n");
        return nil;
    }

    return ret;
}

+ (id)inputStreamWithData:(id)data {
    id ret = [self alloc];

    return [[ret initWithData:data] autorelease];
}

- (id)initWithData:(id)data {
    _data = data;

    return self;
}

- (id)initWithFileAtPath:(id)file {
    if (file == nil) {
        EbrDebugLog("initWithFileAtPath: nil!\n");
        return nil;
    }

    filename = file;
    EbrDebugLog("NSInputStream opening %s\n", [file UTF8String]);
    if (EbrAccess([file UTF8String], 0) != 0) {
        EbrDebugLog("Open failed\n");
        return nil;
    }

    return self;
}

- (int)read:(char*)buf maxLength:(unsigned)maxLength {
    if (_data == nil) {
        int ret = EbrFread(buf, 1, maxLength, fp);

        if (EbrFeof(fp)) {
            _status = NSStreamStatusAtEnd;
        }

        return ret;
    } else {
        int toRead = [_data length] - curPos;

        assert(toRead >= 0);
        if (toRead > (int)maxLength)
            toRead = (int)maxLength;

        char* pBytes = (char*)[_data bytes];
        memcpy(buf, pBytes + curPos, toRead);
        curPos += toRead;

        return toRead;
    }
}

- (BOOL)hasBytesAvailable {
    if (_data == nil) {
        if (!fp) {
            return FALSE;
        }

        if (EbrFeof(fp)) {
            return FALSE;
        } else {
            return TRUE;
        }
    } else {
        if ([_data length] > curPos) {
            return TRUE;
        } else {
            return FALSE;
        }
    }
}

- (id) /* use typed version */ open {
    if (_data == nil) {
        EbrDebugLog("Opening %s\n", [filename UTF8String]);
        fp = EbrFopen([filename UTF8String], "rb");
        if (!fp) {
            EbrDebugLog("Open of %s failed\n", [filename UTF8String]);
            _status = NSStreamStatusNotOpen;
        } else {
            _status = NSStreamStatusOpen;
        }
    } else {
        _status = NSStreamStatusOpen;
    }

    return self;
}

- (id)scheduleInRunLoop:(id)runLoop forMode:(id)mode {
    return 0;
}

@end
