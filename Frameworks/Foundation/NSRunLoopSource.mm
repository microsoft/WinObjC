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
#include "NSRunLoopSource.h"

@implementation NSRunLoopSource : NSInputSource
    +(NSRunLoopSource*) sourceWithContext:(CFRunLoopSourceContext *)ctx {
        NSRunLoopSource* ret = [[super alloc] init];

        ret->valid = TRUE;
        ret->sourceCtx = *ctx;

        return ret;
    }

    -(void) setSourceDelegate:(NSObject*)delegate selector:(SEL)selector {
        _sourceDelegate = delegate;
        _sel = selector;
    }

    -(NSObject*) init {
        EbrEventInit(&_signaledEvent);
        _destroyEvent = true;

        return self;
    }

    -(NSRunLoopSource*) initWithEvent:(EbrEvent)event {
        _signaledEvent = event;

        return self;
    }

    -(NSUInteger) priority {
        return _priority;
    }

    -(void) setPriority:(NSUInteger)priority {
        _priority = priority;
    }

    -(void) dealloc {
        if ( _destroyEvent ) EbrEventDestroy(_signaledEvent);

        [super dealloc];
    }

    -(void) fire {
        if ( _sourceDelegate != nil ) {
            [_sourceDelegate performSelector:_sel];
        }
    }

    -(void) _trigger {
        EbrEventSignal(_signaledEvent);
    }

    -(NSUInteger) eventHandle {
        return (NSUInteger) _signaledEvent;
    }

    
@end

