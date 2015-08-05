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
#include "Foundation/NSString.h"
#include "Foundation/NSStream.h"
#include "NSSocket.h"
#include "NSInputStream_socket.h"
#include "NSOutputStream_socket.h"

@implementation NSStream : NSObject
    +(void) /* use typed version */ initialize {
        
    }

    -(unsigned) streamStatus {
        return _status;
    }

    /* annotate with type */ -(void) close {
        if ( fp ) {
            EbrFclose(fp);
            fp = NULL;
        }
        _status = NSStreamStatusClosed;
    }

    -(void) dealloc {
        if ( fp ) {
            EbrFclose(fp);
            fp = NULL;
        }
        _data = nil;

        [super dealloc];
    }

    /* annotate with type */ +(void) getStreamsToHost:(id)host port:(int)port inputStream:(NSInputStream **)inputStreamp outputStream:(NSOutputStream **)outputStreamp {
        id socket = [[[NSSocket alloc] initTCPStream] autorelease];
        id error;
        BOOL                   immediate;
        id input;
        id output;

        if((error=[socket connectToHost:host port:port immediate:&immediate])!=nil) {
            *inputStreamp=nil;
            *outputStreamp=nil;
            return;
        }

        *inputStreamp=input=[[[NSInputStream_socket alloc] initWithSocket:socket streamStatus:NSStreamStatusNotOpen] autorelease];
        *outputStreamp=output=[[[NSOutputStream_socket alloc] initWithSocket:socket streamStatus:NSStreamStatusNotOpen] autorelease];
    }

    
@end

