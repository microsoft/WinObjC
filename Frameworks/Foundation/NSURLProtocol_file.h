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

#include "Foundation/NSURLProtocol.h"

@interface NSURLProtocol_file : NSURLProtocol {
@public
    id _modes;
    id _path;
    EbrFile* fpIn;
}
/* annotate with type */ -(id)initWithRequest : (id)request cachedResponse : (id)response client : (id)client;
/* annotate with type */ -(id)startLoading;
/* annotate with type */ -(id)stopLoading;
/* annotate with type */ -(id)statusVersion : (id)versionStr;
/* annotate with type */ -(id)scheduleInRunLoop : (id)runLoop forMode : (id)mode;
/* annotate with type */ -(id)_doFileLoad;
/* annotate with type */ -(id)unscheduleFromRunLoop : (id)runLoop forMode : (id)mode;
+ (BOOL)canInitWithRequest:(id)request;
@end
