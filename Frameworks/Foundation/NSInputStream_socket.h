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

#pragma once

@interface NSInputStream_socket : NSStream {
@public
    id _delegate;
    id _error;
    id _socket;
    id _inputSource;
}
- (int)read:(uint8_t*)buffer maxLength:(DWORD)maxLength;
- (BOOL)hasBytesAvailable;
- (void)dealloc;
/* annotate with type */ -(id)initWithSocket : (id)socket streamStatus : (DWORD)status;
/* annotate with type */ -(id)setDelegate : (id)delegate;
/* annotate with type */ -(id)open;
/* annotate with type */ -(id)close;
/* annotate with type */ -(id)scheduleInRunLoop : (id)runLoop forMode : (id)mode;
/* annotate with type */ -(id)removeFromRunLoop : (id)runLoop forMode : (id)mode;
/* annotate with type */ -(id)selectInputSource : (id)inputSource selectEvent : (DWORD)selectEvent;
/* annotate with type */ -(id)setProperty : (id)prop forKey : (id)key;
@end
