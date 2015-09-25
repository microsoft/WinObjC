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

#include <winsock2.h>

#include "Starboard.h"
#include "Foundation/NSMutableString.h"
#include "Foundation/NSURLProtocol.h"
#include "NSURLProtocol_http.h"
#include "Foundation/NSMutableArray.h"
#include "Foundation/NSNumber.h"
#include "Foundation/NSMutableData.h"
#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSRunLoop.h"
#include "Foundation/NSTimer.h"
#include "Foundation/NSStream.h"
#include "Foundation/NSError.h"
#include "Foundation/NSHTTPURLResponse.h"
#include "Foundation/NSDate.h"
#include "NSRunLoopSource.h"
#include "Foundation/NSThread.h"
#include "Foundation/NSURL.h"
#include "Foundation/NSHTTPCookie.h"
#include "Foundation/NSHTTPCookieStorage.h"
#include "Foundation/NSURLAuthenticationChallenge.h"

#include "NSInputStream_socket.h"
#include "NSOutputStream_socket.h"

#include "NSSelectInputSource.h"
#include "NSSSLHandler.h"

#include "NSURLProtocolInternal.h"

#include <openssl/err.h>
#include <openssl/ssl.h>

#include <curl/curl.h>
#include <curl/multi.h>

#undef LOAD_DYLIBS

@interface NSURLProtocolTimerThread : NSObject {
@public
    idretain _socketTimeout;
    CURLM* multi;
    HashMap<int, id>* _monitoringSockets;
    std::deque<CURL*>* _easyHandles;
    std::deque<id>* _queuedRequests;
}
@end

static size_t header_callback(void* ptr, size_t size, size_t nmemb, NSURLProtocol_http* session) {
    assert(size == 1);
    char* lineEnd = ((char*)ptr) + size * nmemb;
    if (memcmp(ptr, "HTTP/", 5) == 0) {
        session->_headers.attach([NSMutableDictionary new]);
        char* pStatusStart = (char*)ptr;
        char* pVersionStart = pStatusStart;
        while (pVersionStart < lineEnd && *pVersionStart != '/')
            pVersionStart++;
        if (pVersionStart < lineEnd)
            pVersionStart++;
        char* pVersionEnd = pVersionStart;
        while (pVersionEnd < lineEnd && *pVersionEnd != ' ')
            pVersionEnd++;
        char* pStatusEnd = pVersionEnd;
        while (pStatusEnd < lineEnd && *pStatusEnd != 10 && *pStatusEnd != 13)
            pStatusEnd++;

        session->_statusLine.attach([[NSString alloc] initWithBytes:pStatusStart
                                                             length:pStatusEnd - pStatusStart
                                                           encoding:NSUTF8StringEncoding]);
        session->_statusVersion.attach([[NSString alloc] initWithBytes:pVersionStart
                                                                length:pVersionEnd - pVersionStart
                                                              encoding:NSUTF8StringEncoding]);
    } else if (memchr(ptr, ':', size * nmemb) != NULL) {
        char* pHeaderStart = (char*)ptr;
        char* pHeaderEnd = pHeaderStart;
        while (pHeaderEnd < lineEnd && *pHeaderEnd != ':')
            pHeaderEnd++;
        char* pValueStart = pHeaderEnd + 1;
        while (pValueStart < lineEnd && *pValueStart == ' ')
            pValueStart++;
        char* pValueEnd = pValueStart;
        while (pValueEnd < lineEnd && *pValueEnd != 10 && *pValueEnd != 13)
            pValueEnd++;

        id headerName = [[NSString alloc] initWithBytes:pHeaderStart
                                                 length:pHeaderEnd - pHeaderStart
                                               encoding:NSUTF8StringEncoding];
        id headerValue =
            [[NSString alloc] initWithBytes:pValueStart length:pValueEnd - pValueStart encoding:NSUTF8StringEncoding];
        [session->_headers setObject:headerValue forKey:headerName];

        //  Process cookies
        if ([session->_request HTTPShouldHandleCookies]) {
            if ([headerName caseInsensitiveCompare:@"set-cookie"] == 0 ||
                [headerName caseInsensitiveCompare:@"set-cookie2"] == 0) {
                id headerPair = [NSDictionary dictionaryWithObject:headerValue forKey:[headerName lowercaseString]];
                id url = session->_curURL;
                id cookies = [NSHTTPCookie cookiesWithResponseHeaderFields:headerPair forURL:url];
                [[NSHTTPCookieStorage sharedHTTPCookieStorage] setCookies:cookies forURL:url mainDocumentURL:url];
            }
        }

        [headerName release];
        [headerValue release];
    } else {
        char* curPos = (char*)ptr;
        while (curPos < lineEnd && (*curPos == ' ' || *curPos == 13 || *curPos == 10))
            curPos++;
        assert(curPos == lineEnd);

        int code = 0;
        double contentLength = 0;
        curl_easy_getinfo(session->curl, CURLINFO_RESPONSE_CODE, &code);
        curl_easy_getinfo(session->curl, CURLINFO_CONTENT_LENGTH_DOWNLOAD, &contentLength);

        if (code != 301 && code != 302 && code != 303 && code != 100) {
            id response = [[NSHTTPURLResponse alloc] initWithURL:(id)session->_curURL
                                                      statusCode:code
                                                         headers:(id)session->_headers
                                           expectedContentLength:(int)contentLength];
            [response setStatusLine:(id)session->_statusLine];
            [response setStatusVersion:(id)session->_statusVersion];
            AddEvent(session, didReceiveResponse, response, nil, 0);
            [response release];
        }
    }

    return size * nmemb;
}

static size_t write_callback(void* ptr, size_t size, size_t nmemb, NSURLProtocol_http* session) {
    id data = [[NSData alloc] initWithBytes:ptr length:size * nmemb];
    AddEvent(session, didReceiveData, data, nil, 0);
    [data release];
    return size * nmemb;
}

static size_t readput_callback(void* ptr, size_t size, size_t nmemb, NSURLProtocol_http* session) {
    int toCopy = size * nmemb;
    if (toCopy > session->_putDataLeft)
        toCopy = session->_putDataLeft;

    memcpy(ptr, session->_putData, toCopy);
    session->_putData += toCopy;
    session->_putDataLeft -= toCopy;

    return toCopy;
}

static STACK_OF(X509_INFO) * cert_stack;

static CURLcode sslsetcertfunc(CURL* curl, void* sslctx, void* parm) {
    SSL_CTX* ctx = (SSL_CTX*)sslctx;

    //  Add certs to the SSL connection
    X509_INFO* info;
    X509_STORE* store = SSL_CTX_get_cert_store(ctx);
    for (int i = 0; i < sk_X509_INFO_num(cert_stack); ++i) {
        info = sk_X509_INFO_value(cert_stack, i);
        if (info->x509) {
            X509_STORE_add_cert(store, info->x509);
        }
        if (info->crl) {
            X509_STORE_add_crl(store, info->crl);
        }
    }

    //  Disable use ECDH ciphers - OpenSSL doesn't have
    //  all the needed curves
    SSL_CTX_set_cipher_list(ctx, "DEFAULT:!kEECDH");

    return CURLE_OK;
}

@implementation NSURLProtocolTimerThread : NSObject
+ (void)initialize {
    /*
    char *zCert;
    BIO *mem;

    EbrFile *fp = EbrFopen("/etc/cacert.pem", "rb");
    if ( !fp ) {
    EbrDebugLog("Error opening /etc/cacert.pem!\n");
    return self;
    }
    EbrFseek(fp, 0, SEEK_END);
    int len = EbrFtell(fp);
    zCert = (char *) malloc(len);
    EbrFseek(fp, 0, SEEK_SET);
    len = EbrFread(zCert, 1, len, fp);
    EbrFclose(fp);

    mem = BIO_new(BIO_s_mem());
    BIO_puts(mem, zCert);

    cert_stack = PEM_X509_INFO_read_bio(mem, NULL, NULL, NULL);
    BIO_free(mem);
    */
}

static void queueEasyHandle(NSURLProtocolTimerThread* self, CURL* curl, NSURLProtocol_http* protocol) {
    const char* pURL = [[protocol->_curURL absoluteString] UTF8String];

    curl_easy_setopt(curl, CURLOPT_PRIVATE, protocol);
    // curl_easy_setopt(curl, CURLOPT_SSL_CTX_FUNCTION, sslsetcertfunc);

    curl_easy_setopt(curl, CURLOPT_URL, pURL);
#ifndef NO_ERROR_PRINT
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
#endif
    curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, header_callback);
    curl_easy_setopt(curl, CURLOPT_HEADERDATA, protocol);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, protocol);
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, (long)[protocol->_request timeoutInterval]);
    protocol->curl = curl;

    //  Set headers
    id allHeaders = [protocol->_request allHTTPHeaderFields];
    for (id headerName in allHeaders) {
        if ([headerName caseInsensitiveCompare:@"Accept-Encoding"] == 0)
            continue;

        id headerValue = [protocol->_request valueForHTTPHeaderField:headerName];
        id combined = [NSString stringWithFormat:@"%@: %@", headerName, headerValue];
        const char* pUTF = [combined UTF8String];
        protocol->_requestHeaders = curl_slist_append(protocol->_requestHeaders, pUTF);
    }

    if ([[protocol->_request HTTPMethod] isEqualToString:@"POST"]) {
        curl_easy_setopt(curl, CURLOPT_POST, 1);
        protocol->_requestHeaders = curl_slist_append(protocol->_requestHeaders, "Expect:");

        id body = [protocol->_request HTTPBody];
        NSInputStream* bodyStream = [protocol->_request HTTPBodyStream];
        if (body != nil && [body length] > 0) {
            char* pBytes = (char*)[body bytes];

            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, [body bytes]);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, [body length]);
        } else if (bodyStream != nil) {
            [bodyStream open];

            //  Read the input data
            uint8_t* pData = (uint8_t*)EbrMalloc(16384);
            DWORD iDataLen = 0, iMaxLen = 16384;

            while ([bodyStream hasBytesAvailable]) {
                if (iDataLen + 16384 > iMaxLen) {
                    iMaxLen += 16384;
                    pData = (uint8_t*)EbrRealloc(pData, iMaxLen);
                }
                DWORD amtRead = [bodyStream read:pData + iDataLen maxLength:iMaxLen - iDataLen];
                iDataLen += amtRead;
            }

            [bodyStream close];
            id data = [NSData dataWithBytes:pData length:iDataLen];
            EbrFree(pData);

            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, [data bytes]);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, [data length]);
        }
    } else if ([[protocol->_request HTTPMethod] isEqualToString:@"GET"]) {
    } else if ([[protocol->_request HTTPMethod] isEqualToString:@"PUT"]) {
        // protocol->_requestHeaders = curl_slist_append(protocol->_requestHeaders, "Expect:");

        id body = [protocol->_request HTTPBody];
        NSInputStream* bodyStream = [protocol->_request HTTPBodyStream];
        if (body != nil && [body length] > 0 && bodyStream == nil) {
            protocol->_putData = (char*)[body bytes];
            protocol->_putDataLeft = [body length];

            curl_easy_setopt(curl, CURLOPT_PUT, 1);
            curl_easy_setopt(curl, CURLOPT_INFILESIZE, protocol->_putDataLeft);
            curl_easy_setopt(curl, CURLOPT_READFUNCTION, readput_callback);
            curl_easy_setopt(curl, CURLOPT_READDATA, protocol);
        } else if (bodyStream != nil) {
            [bodyStream open];

            //  Read the input data
            uint8_t* pData = (uint8_t*)EbrMalloc(16384);
            DWORD iDataLen = 0, iMaxLen = 16384;

            while ([bodyStream hasBytesAvailable]) {
                if (iDataLen + 16384 >= iMaxLen) {
                    iMaxLen += 16384;
                    pData = (uint8_t*)EbrRealloc(pData, iMaxLen);
                }
                DWORD amtRead = [bodyStream read:pData + iDataLen maxLength:iMaxLen - iDataLen];
                iDataLen += amtRead;
                if (amtRead == 0)
                    break;
            }

            [bodyStream close];
            id data = [NSData dataWithBytes:pData length:iDataLen];
            EbrFree(pData);

            protocol->_putData = (char*)[data bytes];
            protocol->_putDataLeft = [data length];
            curl_easy_setopt(curl, CURLOPT_PUT, 1);
            curl_easy_setopt(curl, CURLOPT_INFILESIZE, protocol->_putDataLeft);
            curl_easy_setopt(curl, CURLOPT_READFUNCTION, readput_callback);
            curl_easy_setopt(curl, CURLOPT_READDATA, protocol);
        } else {
            protocol->_putData = "";
            protocol->_putDataLeft = 0;

            curl_easy_setopt(curl, CURLOPT_PUT, 1);
            curl_easy_setopt(curl, CURLOPT_INFILESIZE, protocol->_putDataLeft);
            curl_easy_setopt(curl, CURLOPT_READFUNCTION, readput_callback);
            curl_easy_setopt(curl, CURLOPT_READDATA, protocol);
        }
    } else {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, [[protocol->_request HTTPMethod] UTF8String]);
    }
    if (protocol->_requestHeaders) {
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, protocol->_requestHeaders);
    }

    //  Cookies
    if ([protocol->_request HTTPShouldHandleCookies]) {
        id cs = [NSHTTPCookieStorage sharedHTTPCookieStorage];
        id cdict = [NSHTTPCookie requestHeaderFieldsWithCookies:[cs cookiesForURL:(id)protocol->_curURL]];
        if ([cdict count] > 1) {
            EbrDebugLog("Too many cookies!");
            assert(0);
        }
        for (id curHeader in cdict) {
            id value = [cdict objectForKey:curHeader];
            const char* pCookieStr = [value UTF8String];
            curl_easy_setopt(curl, CURLOPT_COOKIE, pCookieStr);
        }
    }
    if (protocol->_sendRawResponses) {
        curl_easy_setopt(curl, CURLOPT_HTTP_CONTENT_DECODING, 0);
    } else {
        curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "gzip,deflate");
        curl_easy_setopt(curl, CURLOPT_HTTP_CONTENT_DECODING, 1);
    }

    curl_multi_add_handle(self->multi, curl);
}

static void processQueue(NSURLProtocolTimerThread* self) {
    if (self->_easyHandles->size() == 0)
        return;
    if (self->_queuedRequests->size() == 0)
        return;

    CURL* curURL = self->_easyHandles->front();
    self->_easyHandles->pop_front();
    id request = self->_queuedRequests->front();
    self->_queuedRequests->pop_front();

    queueEasyHandle(self, curURL, request);
}

static void processMultiCompletions(NSURLProtocolTimerThread* self) {
    for (;;) {
        int left = 0;
        CURLMsg* msg = curl_multi_info_read(self->multi, &left);
        if (!msg)
            break;

        if (msg->msg == CURLMSG_DONE) {
            NSURLProtocol_http* session;
            CURL* curl = msg->easy_handle;
            curl_easy_getinfo(msg->easy_handle, CURLINFO_PRIVATE, &session);
            session->curl = NULL;
            if (msg->data.result == CURLE_OK) {
                int code = 0;
                curl_easy_getinfo(msg->easy_handle, CURLINFO_RESPONSE_CODE, &code);

                char* pRedirect = NULL;
                curl_easy_getinfo(msg->easy_handle, CURLINFO_REDIRECT_URL, &pRedirect);
                if (pRedirect != NULL) {
                    //  Send a redirect notification
                    double contentLength = 0;
                    curl_easy_getinfo(session->curl, CURLINFO_CONTENT_LENGTH_DOWNLOAD, &contentLength);

                    id redirectURL = [NSURL URLWithString:[NSString stringWithCString:pRedirect]];
                    id response = [[NSHTTPURLResponse alloc] initWithURL:(id)redirectURL
                                                              statusCode:code
                                                                 headers:(id)session->_headers
                                                   expectedContentLength:(int)contentLength];
                    [response setStatusLine:(id)session->_statusLine];
                    [response setStatusVersion:(id)session->_statusVersion];

                    id redirectRequest = [session->_request mutableCopy];
                    [redirectRequest setURL:redirectURL];
                    [redirectRequest setHTTPBody:nil];
                    [redirectRequest setHTTPMethod:@"GET"];
                    AddEvent(session, didReceiveRedirect, redirectRequest, response, 0);
                    [redirectRequest release];
                    [response release];
                } else {
                    if (0 && code == 401) { /* [blamb: TODO finish HTTP authentication] */
                        //  Authentication challenge
                        AddEvent(session, didReceiveAuthChallenge, nil, nil, 0);
                    } else {
                        AddEvent(session, didFinish, nil, nil, 0);
                    }
                }
            } else {
                EbrDebugLog("Curl error = %d\n", msg->data.result);
                id error = [NSError errorWithDomain:NSPOSIXErrorDomain code:STARBOARD_ENOTCONN userInfo:nil];
                AddEvent(session, didFinishWithError, error, nil, 0);
            }
            curl_multi_remove_handle(self->multi, curl);
            curl_easy_reset(curl);
            self->_easyHandles->push_front(curl);
        }
    }

    processQueue(self);
}

- (id)_socketTimeout {
    int running;
    curl_multi_socket_action(multi, CURL_SOCKET_TIMEOUT, 0, &running);
    processMultiCompletions(self);

    return self;
}

static int socket_callback(CURL* easy, curl_socket_t s, int what, NSURLProtocolTimerThread* session, void* socketp) {
    id runLoop = [NSRunLoop currentRunLoop];

    if (what == CURL_POLL_REMOVE) {
        id* val;
        if (session->_monitoringSockets->get((int)s, val)) {
            id selectInputSource = *val;
            session->_monitoringSockets->remove((int)s);
            [runLoop removeInputSource:(id)selectInputSource forMode:@"kCFRunLoopDefaultMode"];
        } else {
            assert(0);
        }
    } else {
        id* val;
        id selectInputSource;
        bool isNew = false;
        if (!session->_monitoringSockets->get((int)s, val)) {
            selectInputSource = [[NSSelectInputSource alloc] initWithDescriptor:(int)s];
            [selectInputSource setDelegate:session];
            isNew = true;
            session->_monitoringSockets->insert((int)s, selectInputSource);
        } else {
            selectInputSource = *val;
        }

        DWORD mask;

        switch (what) {
            case CURL_POLL_IN:
                mask = NSSelectReadEvent;
                break;

            case CURL_POLL_OUT:
                mask = NSSelectWriteEvent;
                break;

            case CURL_POLL_INOUT:
                mask = NSSelectReadEvent | NSSelectWriteEvent;
                break;
        }

        mask |= NSSelectExceptEvent;
        [selectInputSource setSelectEventMask:mask];
        if (isNew) {
            [runLoop addInputSource:(id)selectInputSource forMode:@"kCFRunLoopDefaultMode"];
            [selectInputSource release];
        }
    }

    return 0;
}

- (void)selectInputSource:(NSSelectInputSource*)source selectEvent:(DWORD)event {
    int actionMask = 0;
    if (event & NSSelectReadEvent) {
        actionMask |= CURL_CSELECT_IN;
    }
    if (event & NSSelectWriteEvent) {
        actionMask |= CURL_CSELECT_OUT;
    }
    if (event & NSSelectExceptEvent) {
        actionMask |= CURL_CSELECT_ERR;
    }

    int socket = [source descriptor];

    int running;
    curl_multi_socket_action(multi, socket, actionMask, &running);
    processMultiCompletions(self);
}

static int update_timeout(CURLM* multi, long timeout_ms, NSURLProtocolTimerThread* session) {
    [session->_socketTimeout setFireDate:[NSDate dateWithTimeIntervalSinceNow:((double)timeout_ms) / 1000.0]];
    return 0;
}

- (id)run {
    EbrSetCurrentThreadName("HTTP handler");
    EbrThreadMakeBackgroundExecutable();

    id runLoop = [NSRunLoop currentRunLoop];

    _socketTimeout =
        [NSTimer timerWithTimeInterval:60.0 target:self selector:@selector(_socketTimeout) userInfo:nil repeats:YES];
    [runLoop addTimer:(id)_socketTimeout forMode:@"kCFRunLoopDefaultMode"];
    [runLoop run];
    return self;
}

- (id)init {
    _monitoringSockets = new HashMap<int, id>();

    multi = curl_multi_init();

    curl_multi_setopt(multi, CURLMOPT_SOCKETFUNCTION, socket_callback);
    curl_multi_setopt(multi, CURLMOPT_SOCKETDATA, self);
    curl_multi_setopt(multi, CURLMOPT_TIMERFUNCTION, update_timeout);
    curl_multi_setopt(multi, CURLMOPT_TIMERDATA, self);

    _easyHandles = new std::deque<CURL*>();
    _queuedRequests = new std::deque<id>();

    for (int i = 0; i < 4; i++) {
        CURL* curl = curl_easy_init();
        _easyHandles->push_back(curl);
    }

    return self;
}

- (id)addHTTPRequest:(NSURLProtocol_http*)request {
    [request retain];
    _queuedRequests->push_back(request);
    processQueue(self);
    return self;
}

- (id)cancelHTTPRequest:(NSURLProtocol_http*)request {
    std::deque<id>::iterator cur = _queuedRequests->begin();
    while (cur != _queuedRequests->end()) {
        if (*cur == request) {
            _queuedRequests->erase(cur);
            break;
        }
        cur++;
    }
    if (request->curl != NULL) {
        curl_multi_remove_handle(multi, request->curl);
        curl_easy_reset(request->curl);
        _easyHandles->push_front(request->curl);
        processQueue(self);
    }
    AddEvent(request, didCancel, nil, nil, 0);

    return self;
}

@end

static id g_multiHandler, g_multiThread;

void AddEvent(NSURLProtocol_http* self, URLEventType type, id obj1, id obj2, int error) {
    EbrLockEnter(self->_eventsLock);
    URLEvent e;
    e.type = type;
    e.obj1 = [obj1 retain];
    e.obj2 = [obj2 retain];
    e.error = error;
    self->_events->push_back(e);
    EbrLockLeave(self->_eventsLock);
    [self->_newEventSignal _trigger];
}

@implementation NSURLProtocol_http
- (id)_processEvents {
    for (;;) {
        URLEvent e;

        EbrLockEnter(_eventsLock);
        if (_events->size() == 0) {
            EbrLockLeave(_eventsLock);
            break;
        }
        e = _events->front();
        _events->pop_front();
        EbrLockLeave(_eventsLock);

        switch (e.type) {
            case didReceiveResponse:
                if (!_hasCancelled)
                    [_client URLProtocol:self
                        didReceiveResponse:e.obj1
                        cacheStoragePolicy:NSURLCacheStorageAllowedInMemoryOnly];
                [e.obj1 autorelease];
                break;

            case didReceiveData:
                if (!_hasCancelled)
                    [_client URLProtocol:self didLoadData:e.obj1];
                [e.obj1 release];
                break;

            case didReceiveRedirect:
                if (!_hasCancelled) {
                    EbrDebugLog("Redirect to %s?\n", [[[e.obj2 URL] absoluteString] UTF8String]);
                    id newRequest = [_client URLProtocol:self willSendRequest:e.obj1 redirectResponse:e.obj2];
                    if (newRequest == nil) {
                        if (!_hasCancelled) {
                            _isFinished = TRUE;
                            id userInfo = [NSDictionary dictionaryWithObject:@"Connection timed out"
                                                                      forKey:@"NSLocalizedDescriptionKey"];
                            id error = [NSError errorWithDomain:@"NSURLErrorDomain" code:1234 userInfo:userInfo];

                            [_client URLProtocol:self didFailWithError:error];
                            [self autorelease];
                        }
                    } else {
                        _request = newRequest;
                        _curURL = [_request URL];
                        [g_multiHandler performSelector:@selector(addHTTPRequest:)
                                               onThread:g_multiThread
                                             withObject:self
                                          waitUntilDone:FALSE];
                        [self autorelease];
                    }
                }
                [e.obj1 release];
                [e.obj2 release];
                break;

            case didFinish:
                if (!_hasCancelled) {
                    _isFinished = TRUE;
                    EbrDebugLog("Sending did finish\n");
                    [_client URLProtocolDidFinishLoading:self];
                    [self autorelease];
                }
                break;

            case didFinishWithError:
                if (!_hasCancelled) {
                    _isFinished = TRUE;
                    id error;
                    if (e.obj1 == nil) {
                        id userInfo = [NSDictionary dictionaryWithObject:@"Connection timed out"
                                                                  forKey:@"NSLocalizedDescriptionKey"];
                        error = [NSError errorWithDomain:@"NSURLErrorDomain" code:1234 userInfo:userInfo];
                        EbrDebugLog("Sending did fail - no error\n");
                    } else {
                        EbrDebugLog("Sending did fail\n");
                        error = e.obj1;
                    }

                    [_client URLProtocol:self didFailWithError:error];
                    [self autorelease];
                    [e.obj1 release];
                }
                break;

            case didCancel:
                assert(_hasCancelled == TRUE);
                [self autorelease];
                break;

            case didReceiveAuthChallenge:
                if (!_hasCancelled) {
                    EbrDebugLog("Auth challenge\n");
                    id challenge = [NSURLAuthenticationChallenge new];
                    [challenge setSender:self];
                    [_client URLProtocol:self didReceiveAuthenticationChallenge:challenge];
                }
                break;
        }
    }
    return self;
}

+ (BOOL)canInitWithRequest:(id)request {
    id scheme = [[request URL] scheme];

    if ([scheme isEqualToString:@"http"])
        return YES;
    if ([scheme isEqualToString:@"https"])
        return YES;

    return NO;
}

- (id)initWithRequest:(id)request cachedResponse:(id)response client:(id)client {
    [super initWithRequest:request cachedResponse:response client:client];

    _newEventSignal.attach([NSRunLoopSource new]);
    [_newEventSignal setSourceDelegate:self selector:@selector(_processEvents)];
    _events = new std::deque<URLEvent>();
    EbrLockInit(&_eventsLock);
    _modes = [[NSMutableArray arrayWithObject:@"kCFRunLoopDefaultMode"] retain];
    _runLoops = [NSMutableArray new];
    _request.attach([request copy]);

    _curURL = [request URL];

    return self;
}

+ (id)initialize {
    curl_global_init(CURL_GLOBAL_ALL);

    if (g_multiHandler == nil) {
        g_multiHandler = [NSURLProtocolTimerThread new];
        g_multiThread = [[NSThread alloc] initWithTarget:g_multiHandler selector:@selector(run) object:nil];
        [g_multiThread start];
    }

    return self;
}

- (id)startLoading {
    if (_hasStarted) {
        return self;
    }
    _hasStarted = TRUE;
    if ([_runLoops count] == 0) {
        [_runLoops addObject:[NSRunLoop currentRunLoop]];
    }

    for (id curRunLoop in _runLoops) {
        for (id curMode in _modes) {
            [curRunLoop addInputSource:(id)_newEventSignal forMode:curMode];
        }
    }

    [g_multiHandler performSelector:@selector(addHTTPRequest:)
                           onThread:g_multiThread
                         withObject:self
                      waitUntilDone:FALSE];

    return self;
}

- (id)stopLoading {
    if (_isFinished)
        return self;
    if (_hasCancelled)
        return self;

    _hasCancelled = TRUE;
    [g_multiHandler performSelector:@selector(cancelHTTPRequest:)
                           onThread:g_multiThread
                         withObject:self
                      waitUntilDone:FALSE];
    return self;
}

- (id)scheduleInRunLoop:(id)runLoop forMode:(id)mode {
    if (_hasStarted)
        return self;

    [_modes addObject:mode];
    [_runLoops addObject:runLoop];
    return self;
}

- (id)unscheduleFromRunLoop:(id)runLoop forMode:(id)mode {
    if (_hasStarted)
        return self;

    [_modes removeObject:mode];
    [_runLoops removeObject:runLoop];

    return self;
}

- (void)dealloc {
    for (id curRunLoop in _runLoops) {
        for (id curMode in _modes) {
            [curRunLoop removeInputSource:(id)_newEventSignal forMode:curMode];
        }
    }

    [_modes release];
    [_runLoops release];
    delete _events;
    EbrLockDestroy(_eventsLock);
    _newEventSignal = nil;
    _headers = nil;
    _curURL = nil;
    _request = nil;
    _statusLine = nil;
    _statusVersion = nil;

    if (_requestHeaders) {
        curl_slist_free_all(_requestHeaders);
        _requestHeaders = NULL;
    }
    curl = NULL;

    [super dealloc];
}

- (id)_setSendRawResponses:(BOOL)raw {
    _sendRawResponses = raw;
    return 0;
}

- (id)retain {
    return [super retain];
}

- (void)release {
    [super release];
}

- (id)continueWithoutCredentialForAuthenticationChallenge:(id)challenge {
    return self;
}

@end
