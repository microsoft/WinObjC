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

#include "NSInputSource.h"

enum { NSSelectReadEvent = 0x01, NSSelectWriteEvent = 0x02, NSSelectExceptEvent = 0x04 };
typedef int NSSelectEventMask;

@interface NSSelectInputSource : NSInputSource {
@public
    id _socket;
    int _descriptor;
    id _delegate;
    NSSelectEventMask _eventMask;
    BOOL _isValid;
}
- (void)dealloc;
- (int)descriptor;
- (BOOL)isValid;
- (void)invalidate;
- (NSSelectEventMask)selectEventMask;
- (BOOL)processImmediateEvents:(DWORD)selectEvent;
/* annotate with type */ -(id)initWithSocket : (id)socket;
/* annotate with type */ -(id)initWithDescriptor : (int)descriptor;
/* annotate with type */ -(id)socket;
/* annotate with type */ -(id)delegate;
/* annotate with type */ -(id)setDelegate : (id)object;
/* annotate with type */ -(id)setSelectEventMask : (DWORD)eventMask;
@end
