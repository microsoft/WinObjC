/* Copyright (c) 2008 Christopher J. W. Lloyd

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
#include "NSURLConnectionState.h"
#include "Foundation/NSRunLoop.h"
#include "Foundation/NSDate.h"
#include "NSRunLoopSource.h"

@implementation NSURLConnectionState : NSObject
- (id)init {
    _isRunning = YES;
    _error = nil;
    _wakeUp.attach([NSRunLoopSource new]);
    [_wakeUp setSourceDelegate:(id)self selector:@selector(_doneWakeup)];
    return self;
}

- (id)dealloc {
    [_error release];
    _wakeUp = nil;
    [super dealloc];
    return self;
}

- (BOOL)isRunning {
    return _isRunning;
}

- (id)receiveAllDataInMode:(id)mode {
    [[NSRunLoop currentRunLoop] addInputSource:(id)_wakeUp forMode:mode];

    while ([self isRunning]) {
        [[NSRunLoop currentRunLoop] runMode:mode beforeDate:[NSDate distantFuture]];
    }

    [[NSRunLoop currentRunLoop] removeInputSource:(id)_wakeUp forMode:mode];

    return self;
}

- (id)connection:(id)connection didReceiveData:(id)data {
    return self;
}

- (id)setError:(id)error {
    _error = [error retain];
    return self;
}

- (id)error {
    return _error;
}

- (id)_doneWakeup {
    return self;
}

- (id)connection:(id)connection didFailWithError:(id)error {
    _isRunning = NO;
    _error = [error retain];
    [_wakeUp _trigger];

    return self;
}

- (id)connectionDidFinishLoading:(id)connection {
    _isRunning = NO;
    [_wakeUp _trigger];
    return self;
}

@end
