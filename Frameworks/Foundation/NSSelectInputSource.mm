/* Copyright (c) 2007 Christopher J. W. Lloyd

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
#include "NSSelectInputSource.h"

@implementation NSSelectInputSource : NSInputSource
- (id)initWithSocket:(id)socket {
    _socket = [socket retain];
    _delegate = nil;
    _eventMask = 0;
    _isValid = YES;
    return self;
}

- (id)initWithDescriptor:(int)descriptor {
    _descriptor = descriptor;
    _delegate = nil;
    _eventMask = 0;
    _isValid = YES;
    return self;
}

- (void)dealloc {
    [_socket release];
    [super dealloc];
}

- (id)socket {
    return _socket;
}

- (int)descriptor {
    if (_socket) {
        return [_socket descriptor];
    }

    return _descriptor;
}

- (BOOL)isValid {
    return _isValid;
}

- (void)invalidate {
    _isValid = NO;
    _delegate = nil;
}

- (id)delegate {
    return _delegate;
}

- (id)setDelegate:(id)object {
    _delegate = object;
    return self;
}

- (NSSelectEventMask)selectEventMask {
    return _eventMask;
}

- (id)setSelectEventMask:(DWORD)eventMask {
    _eventMask = eventMask;

    return self;
}

- (BOOL)processImmediateEvents:(DWORD)selectEvent {
    if ((selectEvent &= _eventMask) == 0) {
        return NO;
    }

    [_delegate selectInputSource:self selectEvent:selectEvent];
    return YES;
}

@end
