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

#include "Starboard.h"
#include "Foundation/NSString.h"
#include "Foundation/NSStream.h"
#include "NSSocket.h"
#include "NSInputStream_socket.h"
#include "NSOutputStream_socket.h"
#include "NSStreamInternal.h"

@implementation NSStream

+ (void)initialize {
}

- (unsigned)streamStatus {
    return _status;
}

- (void)close {
    if (fp) {
        EbrFclose(fp);
        fp = NULL;
    }
    _status = NSStreamStatusClosed;
}

- (void)dealloc {
    if (fp) {
        EbrFclose(fp);
        fp = NULL;
    }
    _data = nil;

    [super dealloc];
}

+ (void)getStreamsToHost:(id)host
                    port:(int)port
             inputStream:(NSInputStream**)inputStreamp
            outputStream:(NSOutputStream**)outputStreamp {
    id socket = [[[NSSocket alloc] initTCPStream] autorelease];
    id error;
    BOOL immediate;
    id input;
    id output;

    if ((error = [socket connectToHost:host port:port immediate:&immediate]) != nil) {
        *inputStreamp = nil;
        *outputStreamp = nil;
        return;
    }

    *inputStreamp = input =
        [[[NSInputStream_socket alloc] initWithSocket:socket streamStatus:NSStreamStatusNotOpen] autorelease];
    *outputStreamp = output =
        [[[NSOutputStream_socket alloc] initWithSocket:socket streamStatus:NSStreamStatusNotOpen] autorelease];
}

@end
