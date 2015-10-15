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

#include "zlib.h"
//#define CURL_STATICLIB

#include "Hash.h"

#include <deque>
typedef void CURL;

#undef interface

typedef enum {
    didReceiveResponse,
    didReceiveData,
    didReceiveRedirect,
    didReceiveAuthChallenge,
    didFinish,
    didFinishWithError,
    didCancel,
} URLEventType;

typedef struct {
    URLEventType type;
    id obj1, obj2;
    int error;
} URLEvent;

@interface NSURLProtocol_http : NSURLProtocol {
@public
    id _modes;
    id _runLoops;

    idretain _statusVersion;
    idretain _statusLine;
    idretain _headers;
    idretain _curURL;
    char* _putData;
    int _putDataLeft;
    CURL* curl;

    BOOL _sendRawResponses;
    BOOL _hasStarted, _hasCancelled, _isFinished;

    struct curl_slist* _requestHeaders;
    idretain _newEventSignal;
    std::deque<URLEvent>* _events;
    EbrLock _eventsLock;
}
- (void)selectInputSource:(NSSelectInputSource*)source selectEvent:(DWORD)event;
- (void)dealloc;
- (id)retain;
- (void)release;
/* annotate with type */ -(id)_socketTimeout;
/* annotate with type */ -(id)run;
/* annotate with type */ -(id)init;
/* annotate with type */ -(id)addHTTPRequest : (NSURLProtocol_http*)request;
/* annotate with type */ -(id)cancelHTTPRequest : (NSURLProtocol_http*)request;
/* annotate with type */ -(id)_processEvents;
/* annotate with type */ -(id)initWithRequest : (id)request cachedResponse : (id)response client : (id)client;
/* annotate with type */ -(id)startLoading;
/* annotate with type */ -(id)stopLoading;
/* annotate with type */ -(id)scheduleInRunLoop : (id)runLoop forMode : (id)mode;
/* annotate with type */ -(id)unscheduleFromRunLoop : (id)runLoop forMode : (id)mode;
/* annotate with type */ -(id)_setSendRawResponses : (BOOL)raw;
/* annotate with type */ -(id)continueWithoutCredentialForAuthenticationChallenge : (id)challenge;
/* annotate with type */ +(id)initialize;
/* annotate with type */ +(id)initialize;
+ (BOOL)canInitWithRequest:(id)request;
@end

void AddEvent(NSURLProtocol_http* self, URLEventType type, id obj1, id obj2, int error);
