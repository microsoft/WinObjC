/* Copyright (c) 2006-2007 Christopher J. W. Lloyd <cjwl@objc.net>

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
#include "Foundation/NSStream.h"
#include "Foundation/NSDate.h"
#include "NSSSLHandler.h"
#include "NSOutputStream_socket.h"
#include "NSSelectInputSource.h"
#include "NSSelectSet.h"
#include "NSStreamInternal.h"

static BOOL socketHasSpaceAvailable(id socket) {
    NSSelectSet* selectSet = [[[NSSelectSet alloc] init] autorelease];
    NSSelectSet* outputSet;

    [selectSet addObjectForWrite:socket];
    if ([selectSet waitForSelectWithOutputSet:&outputSet beforeDate:[NSDate date]] == nil) {
        return [outputSet containsObjectForWrite:socket];
    }

    return NO;
}

@implementation NSOutputStream_socket : NSStream
- (id)initWithSocket:(id)socket streamStatus:(DWORD)status {
    _delegate = self;
    _error = nil;
    _status = status;
    _socket = [socket retain];
    _inputSource = nil;
    return self;
}

- (id)setDelegate:(id)delegate {
    _delegate = delegate;
    if (_delegate == nil) {
        _delegate = self;
    }

    return self;
}

- (id)scheduleInRunLoop:(id)runLoop forMode:(id)mode {
    if (_inputSource == nil) {
        _inputSource = [[NSSelectInputSource alloc] initWithSocket:_socket];
        [_inputSource setDelegate:self];
        [_inputSource setSelectEventMask:NSSelectWriteEvent];
    }

    [runLoop addInputSource:_inputSource forMode:mode];

    return self;
}

- (id)open {
    if (_status == NSStreamStatusNotOpen) {
        _status = NSStreamStatusOpening;
    }

    return self;
}

- (id)close {
    [_socket close];
    return self;
}

- (id)_triggerWrite {
    [_inputSource setSelectEventMask:[_inputSource selectEventMask] | NSSelectWriteEvent];

    return self;
}

- (id)selectInputSource:(id)inputSource selectEvent:(DWORD)selectEvent {
    NSStreamEvent event;

    switch (_status) {
        case NSStreamStatusOpening:
            _status = NSStreamStatusOpen;
            event = NSStreamEventOpenCompleted;
            break;

        case NSStreamStatusOpen: {
            id sslHandler = [_socket sslHandler];
            bool done = true;

            if (sslHandler != nil) {
                [sslHandler setOutputStream:self];
                [sslHandler runHandshakeIfNeeded:_socket];
                done = ![sslHandler isHandshaking];
            }

            if (![self hasSpaceAvailable] || !done) {
                event = NSStreamEventNone;
            } else {
                event = NSStreamEventHasSpaceAvailable;
            }

            [_inputSource setSelectEventMask:[_inputSource selectEventMask] & ~NSSelectWriteEvent];
        } break;

        case NSStreamStatusAtEnd:
            event = NSStreamEventEndEncountered;
            break;

        default:
            event = NSStreamEventNone;
            break;
    }

    if (event != NSStreamEventNone && [_delegate respondsToSelector:@selector(stream:handleEvent:)]) {
        [_delegate stream:self handleEvent:event];
    }

    return self;
}

- (id)removeFromRunLoop:(id)runLoop forMode:(id)mode {
    if (_inputSource != nil) {
        [runLoop removeInputSource:_inputSource forMode:mode];
    }

    return self;
}

- (BOOL)hasSpaceAvailable {
    if (_status == NSStreamStatusOpen) {
        id sslHandler = [_socket sslHandler];

        if (sslHandler == nil) {
            return socketHasSpaceAvailable(_socket);
        } else {
            if ([sslHandler writeBytesAvailable] == 0) {
                return YES;
            } else if (socketHasSpaceAvailable(_socket)) {
                [sslHandler transferOneBufferFromSSLToSocket:_socket];
            }
        }
    }

    return NO;
}

- (int)write:(uint8_t*)buffer maxLength:(unsigned)length {
    if (_status != NSStreamStatusOpen && _status != NSStreamStatusOpening) {
        return -1;
    }

    NSSSLHandler* sslHandler = [_socket sslHandler];

    if (sslHandler == nil) {
        [_inputSource setSelectEventMask:[_inputSource selectEventMask] | NSSelectWriteEvent];
        return [_socket write:buffer maxLength:length];
    } else {
        [sslHandler runHandshakeIfNeeded:_socket];

        NSInteger check = [sslHandler writePlaintext:buffer maxLength:length];

        if (check != length) {
            EbrDebugLog("failure writePlaintext:%d=%d", length, check);
        }

        [sslHandler runWithSocket:_socket];
        [_inputSource setSelectEventMask:[_inputSource selectEventMask] | NSSelectWriteEvent];

        return check;
    }
}

- (id)setProperty:(id)prop forKey:(id)key {
    if ([key isEqualToString:(NSString*)kCFStreamPropertySSLSettings]) {
        return [_socket setSSLProperties:prop];
    }

    assert(0);
    return NO;
}

- (void)dealloc {
    [_inputSource setDelegate:nil];
    [super dealloc];
}

@end
