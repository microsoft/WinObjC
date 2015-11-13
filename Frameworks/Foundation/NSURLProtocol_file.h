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
- (id)initWithRequest:(id)request cachedResponse:(id)response client:(id)client;
- (id)startLoading;
- (id)stopLoading;
- (id)statusVersion:(id)versionStr;
- (id)scheduleInRunLoop:(id)runLoop forMode:(id)mode;
- (id)_doFileLoad;
- (id)unscheduleFromRunLoop:(id)runLoop forMode:(id)mode;
+ (BOOL)canInitWithRequest:(id)request;
@end
