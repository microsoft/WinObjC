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
#include "NSSelectInputSource.h"

@implementation NSSelectInputSource : NSInputSource
    /* annotate with type */ -(id) initWithSocket:(id)socket {
       _socket= [socket retain];
       _delegate=nil;
       _eventMask=0;
       _isValid = YES;
       return self;
    }

    /* annotate with type */ -(id) initWithDescriptor:(int)descriptor {
        _descriptor = descriptor;
       _delegate=nil;
       _eventMask=0;
       _isValid = YES;
       return self;
    }

    -(void) dealloc {
        [_socket release];
        [super dealloc];
    }

    /* annotate with type */ -(id) socket {
        return _socket;
    }

    -(int) descriptor {
        if ( _socket ) {
            return [_socket descriptor];
        }

        return _descriptor;
    }

    -(BOOL) isValid {
        return _isValid;
    }

    -(void) invalidate {
        _isValid=NO;
        _delegate=nil;
    }

    /* annotate with type */ -(id) delegate {
        return _delegate;
    }

    /* annotate with type */ -(id) setDelegate:(id)object {
        _delegate=object;
        return self;
    }

    -(NSSelectEventMask) selectEventMask {
        return _eventMask;
    }

    /* annotate with type */ -(id) setSelectEventMask:(DWORD)eventMask {
        _eventMask=eventMask;

        return self;
    }

    -(BOOL) processImmediateEvents:(DWORD)selectEvent {
       if((selectEvent&=_eventMask)==0)
            return NO;

       [_delegate selectInputSource:self selectEvent:selectEvent];
       return YES;
    }

    
@end

