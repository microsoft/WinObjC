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
#include "NSURLConnectionState.h"
#include "Foundation/NSRunLoop.h"
#include "Foundation/NSDate.h"
#include "NSRunLoopSource.h"

@implementation NSURLConnectionState : NSObject
    /* annotate with type */ -(id) init {
        _isRunning=YES;
        _error=nil;
        _wakeUp.attach([NSRunLoopSource new]);
        [_wakeUp setSourceDelegate:(id) self selector:@selector(_doneWakeup)];
        return self;
    }

    /* annotate with type */ -(id) dealloc {
        [_error release];
        _wakeUp = nil;
        [super dealloc];
        return self;
    }

    -(BOOL) isRunning {
        return _isRunning;
    }

    /* annotate with type */ -(id) receiveAllDataInMode:(id)mode {
        [[NSRunLoop currentRunLoop] addInputSource:(id) _wakeUp forMode:mode];

        while (  [self isRunning] ) {
            [[NSRunLoop currentRunLoop] runMode:mode beforeDate:[NSDate distantFuture]];
        }

        [[NSRunLoop currentRunLoop] removeInputSource:(id) _wakeUp forMode:mode];

        return self;
    }

    /* annotate with type */ -(id) connection:(id)connection didReceiveData:(id)data {
        return self;
    }

    /* annotate with type */ -(id) setError:(id)error {
        _error = [error retain];
        return self;
    }

    /* annotate with type */ -(id) error {
        return _error;
    }

    /* annotate with type */ -(id) _doneWakeup {
        return self;
    }

    /* annotate with type */ -(id) connection:(id)connection didFailWithError:(id)error {
        _isRunning=NO;
        _error=[error retain];
        [_wakeUp _trigger];

        return self;
    }

    /* annotate with type */ -(id) connectionDidFinishLoading:(id)connection {
        _isRunning=NO;
        [_wakeUp _trigger];
        return self;
    }


    
@end

