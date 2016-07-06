//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <Foundation/NSURLProtocol.h>
#import <Foundation/NSHTTPURLResponse.h>

#include <COMIncludes.h>
#import <wrl/client.h>
#import <wrl/wrappers/corewrappers.h>
#import <Windows.Foundation.Collections.h>
#import <Windows.Web.Http.h>
#import <Windows.Web.Http.Filters.h>
#import <Windows.Storage.Streams.h>
#import <Windows.System.Threading.h>
#include <COMIncludes_end.h>
#import <mutex>

#import "Starboard/SmartTypes.h"
#import "ErrorHandling.h"
#import "StringHelpers.h"
#import "CollectionHelpers.h"
#import "WRLHelpers.h"
#import "LoggingNative.h"
#import "RawBuffer.h"
#import "NSURLProtocolInternal.h"

#pragma region Types and Namespaces
using namespace Microsoft::WRL;
using namespace Windows::Foundation;
using namespace ABI::Windows::Web::Http;
using namespace ABI::Windows::Web::Http::Filters;
using namespace ABI::Windows::Web::Http::Headers;
using namespace ABI::Windows::Storage::Streams;

using ABI::Windows::Foundation::IReference;
using ABI::Windows::Foundation::Collections::IMap;
using ABI::Windows::Foundation::Collections::IKeyValuePair;
using ABI::Windows::Foundation::IAsyncOperationWithProgress;
using ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler;
using ABI::Windows::Foundation::IUriRuntimeClass;
using ABI::Windows::Foundation::IUriRuntimeClassFactory;

using AsyncHttpOperation = IAsyncOperationWithProgress<HttpResponseMessage*, HttpProgress>;
#define MakeHttpCompletedCallback                                                                       \
    ::Microsoft::WRL::Callback<                                                                         \
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::ClassicCom>, \
                                     IAsyncOperationWithProgressCompletedHandler<HttpResponseMessage*, HttpProgress>>>
#pragma endregion

static size_t kHTTPContentBufferSize = 16384;
static const wchar_t TAG[] = L"NSURLProtocol (HTTP)";

namespace {
#pragma region WinRT Initialization
// To reduce the number of live HttpClient instances in the case of parallel requests, we vend the current one iff it exists.
// They're all set up in the same way, and they are not stateful, so we can get away with this.
static ComPtr<IHttpClient> _getHttpClient() {
    static WeakRef weakHttpClient;
    static std::mutex mutex;
    std::lock_guard<std::mutex> lock(mutex);
    ComPtr<IHttpClient> httpClient;
    weakHttpClient.As(&httpClient);
    if (httpClient) {
        return httpClient;
    }

    ComPtr<IHttpClientFactory> httpClientFactory;
    THROW_NS_IF_FAILED(
        GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_Web_Http_HttpClient).Get(), &httpClientFactory));

    ComPtr<IHttpFilter> httpFilter;
    ComPtr<IHttpBaseProtocolFilter> filter;
    ActivateInstance(Wrappers::HStringReference(RuntimeClass_Windows_Web_Http_Filters_HttpBaseProtocolFilter).Get(), &filter);
    THROW_NS_IF_FAILED(filter.As(&httpFilter));

    THROW_NS_IF_FAILED(filter->put_AllowUI(false));
    THROW_NS_IF_FAILED(filter->put_AllowAutoRedirect(false));

    ComPtr<IHttpCacheControl> cacheControl;
    THROW_NS_IF_FAILED(filter->get_CacheControl(&cacheControl));

    // VSO 6693027: Update this to use NoCache so that we get full control.
    THROW_NS_IF_FAILED(cacheControl->put_ReadBehavior(HttpCacheReadBehavior::HttpCacheReadBehavior_MostRecent));

    // IHttpBaseProtocolFilter3: because the vtable of IHttpBaseProtocolFilter could not be extended.
    ComPtr<IHttpBaseProtocolFilter3> filter3;
    THROW_NS_IF_FAILED(filter.As(&filter3));
    THROW_NS_IF_FAILED(filter3->put_CookieUsageBehavior(HttpCookieUsageBehavior::HttpCookieUsageBehavior_NoCookies));

    THROW_NS_IF_FAILED(httpClientFactory->Create(httpFilter.Get(), &httpClient));
    httpClient.AsWeak(&weakHttpClient);
    return httpClient;
}
#pragma endregion

#pragma region Bridging Helpers
static ComPtr<IHttpRequestMessage> _requestMessageForNS(NSURLRequest* nsRequest) {
    ComPtr<IHttpMethodFactory> httpMethodFactory;
    ComPtr<IHttpMethod> httpMethod;
    THROW_IF_FAILED(GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_Web_Http_HttpMethod).Get(), &httpMethodFactory));
    THROW_IF_FAILED(httpMethodFactory->Create(Strings::NarrowToWide<HSTRING>(nsRequest.HTTPMethod).Get(), &httpMethod));

    ComPtr<IActivationFactory> activationFactory;
    ComPtr<IUriRuntimeClassFactory> uriFactory;
    ComPtr<IUriRuntimeClass> uri;
    THROW_IF_FAILED(GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_Foundation_Uri).Get(), &activationFactory));
    THROW_IF_FAILED(activationFactory.As(&uriFactory));
    THROW_IF_FAILED(uriFactory->CreateUri(Strings::NarrowToWide<HSTRING>([nsRequest.URL absoluteString]).Get(), &uri));

    ComPtr<IHttpRequestMessageFactory> httpRequestMessageFactory;
    ComPtr<IHttpRequestMessage> httpRequestMessage;
    THROW_IF_FAILED(GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_Web_Http_HttpRequestMessage).Get(),
                                         &httpRequestMessageFactory));
    THROW_IF_FAILED(httpRequestMessageFactory->Create(httpMethod.Get(), uri.Get(), &httpRequestMessage));

    ComPtr<IHttpRequestHeaderCollection> requestMessageHeaders;
    THROW_IF_FAILED(httpRequestMessage->get_Headers(&requestMessageHeaders));

    NSMutableDictionary* headers = [[[nsRequest allHTTPHeaderFields] mutableCopy] autorelease];

    if ([nsRequest HTTPShouldHandleCookies]) {
        NSArray* cookies = [[NSHTTPCookieStorage sharedHTTPCookieStorage] cookiesForURL:nsRequest.URL];
        [headers addEntriesFromDictionary:[NSHTTPCookie requestHeaderFieldsWithCookies:cookies]];
    }

    NSMutableDictionary* rejectedRequestHeaders = [NSMutableDictionary dictionary];
    for (NSString* header in [headers keyEnumerator]) {
        NSString* value = [headers objectForKey:header];

        boolean added = false;
        THROW_IF_FAILED(requestMessageHeaders->TryAppendWithoutValidation(Strings::NarrowToWide<HSTRING>(header).Get(),
                                                                          Strings::NarrowToWide<HSTRING>(value).Get(),
                                                                          &added));
        if (!added) {
            // Windows::Web::Http will reject certain headers that it believes to be content-only.
            // We'll have to try to add them to the content header set later, iff there is content.
            [rejectedRequestHeaders setObject:value forKey:header];
        }
    }

    NSData* requestBody = nsRequest.HTTPBody;
    if (nsRequest.HTTPBodyStream) {
        // VSO 6693048: Properly support streaming bodies instead of flattening the data up front.
        NSInputStream* bodyStream = nsRequest.HTTPBodyStream;
        std::vector<uint8_t> flattenedBodyStream(kHTTPContentBufferSize);
        ptrdiff_t offset = 0;
        while ([bodyStream hasBytesAvailable]) {
            ptrdiff_t read = [bodyStream read:flattenedBodyStream.data() + offset maxLength:flattenedBodyStream.capacity() - offset];
            if (read == 0) {
                break;
            }

            offset += read;
            if (offset > flattenedBodyStream.capacity()) {
                flattenedBodyStream.reserve(flattenedBodyStream.capacity() + kHTTPContentBufferSize);
            }
        }
        [bodyStream close];

        requestBody = [NSData dataWithBytes:flattenedBodyStream.data() length:offset];
    }

    ComPtr<IHttpContent> httpContent;
    if (requestBody) {
        ComPtr<IBuffer> bodyBuffer;
        THROW_IF_FAILED(BufferFromRawData(bodyBuffer.GetAddressOf(),
                                          reinterpret_cast<unsigned char*>(const_cast<void*>([requestBody bytes])),
                                          [requestBody length]));

        ComPtr<IHttpBufferContentFactory> httpBufferContentFactory;
        THROW_IF_FAILED(GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_Web_Http_HttpBufferContent).Get(),
                                             &httpBufferContentFactory));
        THROW_IF_FAILED(httpBufferContentFactory->CreateFromBuffer(bodyBuffer.Get(), &httpContent));
        THROW_IF_FAILED(httpRequestMessage->put_Content(httpContent.Get()));
    }

    if (httpContent && [rejectedRequestHeaders count] > 0) {
        ComPtr<IHttpContentHeaderCollection> contentHeaders;
        THROW_IF_FAILED(httpContent->get_Headers(&contentHeaders));
        for (NSString* header in [rejectedRequestHeaders keyEnumerator]) {
            NSString* value = [rejectedRequestHeaders objectForKey:header];

            boolean added = false;
            THROW_IF_FAILED(contentHeaders->TryAppendWithoutValidation(Strings::NarrowToWide<HSTRING>(header).Get(),
                                                                       Strings::NarrowToWide<HSTRING>(value).Get(),
                                                                       &added));
            if (!added) {
                TraceWarning(TAG, L"Rejecting unacceptable content header \"%hs\".", [header UTF8String]);
            }
        }
    }

    return httpRequestMessage;
}
#pragma endregion
}

@interface NSURLProtocol_WinHTTP : NSURLProtocol {
    ComPtr<AsyncHttpOperation> _httpRequestOperation;
    ComPtr<IHttpClient> _httpClient;
}
@property (assign, atomic) bool cancelled;
@end

@implementation NSURLProtocol_WinHTTP
+ (void)load {
    [NSURLProtocol registerClass:self];
}

+ (BOOL)canInitWithRequest:(id)request {
    id scheme = [[request URL] scheme];
    return [scheme isEqualToString:@"http"] || [scheme isEqualToString:@"https"];
}

- (instancetype)initWithRequest:(NSURLRequest*)request
                 cachedResponse:(NSCachedURLResponse*)cachedResponse
                         client:(id<NSURLProtocolClient>)client {
    if (self = [super initWithRequest:request cachedResponse:cachedResponse client:client]) {
        _httpClient = _getHttpClient();
    }
    return self;
}

template <typename R, typename... Args>
static std::function<R(Args...)> bindObjC(id instance, SEL _cmd) {
    StrongId<NSObject> strongInstance(instance);
    return [strongInstance, _cmd](Args... args) -> R {
        // args are not perfectly forwarded here, as objc_msgSend will not know what to do with them.
        return ((R (*)(id, SEL, Args...))objc_msgSend)(strongInstance, _cmd, args...);
    };
}

- (void)startLoading {
    @synchronized(self) {
        if (_httpRequestOperation) {
            return;
        }

        NSError* error = nil;
        try {
            auto httpRequestMessage = _requestMessageForNS(_request);
            THROW_IF_FAILED(_httpClient->SendRequestWithOptionAsync(httpRequestMessage.Get(),
                                                                    HttpCompletionOption::HttpCompletionOption_ResponseHeadersRead,
                                                                    &_httpRequestOperation));

            StrongId<NSURLProtocol_WinHTTP> strongSelf(self);
            auto handler = MakeHttpCompletedCallback(
                bindObjC<HRESULT, AsyncHttpOperation*, AsyncStatus>(self, @selector(_asyncHttpOperation:completedWithStatus:)));
            THROW_IF_FAILED(_httpRequestOperation->put_Completed(handler.Get()));
        }
        CATCH_POPULATE_NSERROR(&error);

        if (error) {
            [self _propagateErrorToClient:error];
        }
    }
}

- (void)stopLoading {
    @synchronized(self) {
        if (!_httpRequestOperation) {
            return;
        }

        self.cancelled = true;

        ComPtr<IAsyncInfo> asyncInfo;
        if (_httpRequestOperation && !FAILED(_httpRequestOperation.As(&asyncInfo))) {
            AsyncStatus status = AsyncStatus::Error; // assume it is in an error state unless it tells us otherwise.
            asyncInfo->get_Status(&status);
            if (status == AsyncStatus::Started) {
                asyncInfo->Cancel(); // we don't care if this fails.
            }
            _httpRequestOperation.Detach();
        }
    }
}

- (HRESULT)_asyncHttpOperation:(AsyncHttpOperation*)pOperation completedWithStatus:(AsyncStatus)status {
    if (status == AsyncStatus::Canceled) {
        return S_OK;
    }

    NSError* error = nil;
    try {
        ComPtr<AsyncHttpOperation> operation(pOperation);
        ComPtr<IAsyncInfo> asyncInfo;
        THROW_IF_FAILED(operation.As(&asyncInfo));

        if (status == AsyncStatus::Error) {
            HRESULT hr = S_OK;
            THROW_IF_FAILED(asyncInfo->get_ErrorCode(&hr));
            THROW_HR(hr);
        } else if (status != AsyncStatus::Completed) {
            THROW_HR(E_UNEXPECTED);
        }

        ComPtr<IHttpResponseMessage> responseMessage;
        THROW_IF_FAILED(operation->GetResults(&responseMessage));

        HttpStatusCode statusCode;
        THROW_IF_FAILED(responseMessage->get_StatusCode(&statusCode));
        HttpVersion httpVersion;
        THROW_IF_FAILED(responseMessage->get_Version(&httpVersion));

        ComPtr<IHttpResponseHeaderCollection> headerCollection;
        THROW_IF_FAILED(responseMessage->get_Headers(&headerCollection));
        ComPtr<IMap<HSTRING, HSTRING>> headerMap;
        THROW_IF_FAILED(headerCollection.As(&headerMap));

        if ([_request HTTPShouldHandleCookies]) {
            NSHTTPCookieStorage* cookieStorage = [NSHTTPCookieStorage sharedHTTPCookieStorage];
            NSMutableDictionary* collectedCookies = [NSMutableDictionary dictionary];
            int index = 0;
            // VSO 6693060: NSHTTPCookie does not support "Set-Cookie x=y; Path=/, a=b; Path=/ -- multiple cookies separated with ','.
            // A response may contain multiple Set-Cookie headers, but inserting them into a dictionary will necessarily
            // flatten them into a single entry. We need to accumulate each cookie separately so that we can provide the
            // lot of them to NSHTTPCookie's initializer.
            HRESULT hr =
                WRLHelpers::ForEach(headerMap.Get(),
                                    [&collectedCookies, &index](const ComPtr<IKeyValuePair<HSTRING, HSTRING>>& pair, boolean* stop) {
                                        Wrappers::HString key;
                                        RETURN_IF_FAILED(pair->get_Key(key.GetAddressOf()));
                                        unsigned int keyLength = 0;
                                        const wchar_t* rawKey = key.GetRawBuffer(&keyLength);
                                        if (_wcsnicmp(rawKey, L"set-cookie", _countof("set-cookie") - 1) !=
                                            0) { // we want every set-cookie/set-cookie2 header, regardless of case.
                                            return S_OK;
                                        }

                                        Wrappers::HString value;
                                        RETURN_IF_FAILED(pair->get_Value(value.GetAddressOf()));
                                        [collectedCookies setObject:Strings::WideToNSString(value.Get())
                                                             forKey:[NSString stringWithFormat:@"%d", ++index]];
                                        return S_OK;
                                    });
            THROW_IF_FAILED(hr);

            NSArray* cookies = [NSHTTPCookie cookiesWithResponseHeaderFields:collectedCookies forURL:[_request URL]];
            [cookieStorage setCookies:cookies forURL:[_request URL] mainDocumentURL:nil];
        }

        NSMutableDictionary* nsHeaders = [NSMutableDictionary dictionary];
        NSDictionary* responseHeaders;
        THROW_IF_FAILED(Collections::WRLToNSCollection(headerMap, &responseHeaders));
        [nsHeaders addEntriesFromDictionary:responseHeaders];

        ComPtr<IHttpContent> content;
        responseMessage->get_Content(&content); // Not guarding this: it would be valid for there to be no content.

        uint64_t contentLength = 0;
        if (content) {
            ComPtr<IHttpContentHeaderCollection> contentHeaderCollection;
            THROW_IF_FAILED(content->get_Headers(&contentHeaderCollection));
            THROW_IF_FAILED(contentHeaderCollection.As(&headerMap));
            NSDictionary* contentHeaders = nil;
            THROW_IF_FAILED(Collections::WRLToNSCollection(headerMap, &contentHeaders));

            ComPtr<IReference<uint64_t>> contentLengthRef;
            THROW_IF_FAILED(contentHeaderCollection->get_ContentLength(&contentLengthRef));
            if (contentLengthRef) {
                THROW_IF_FAILED(contentLengthRef->get_Value(&contentLength));
            }

            [nsHeaders addEntriesFromDictionary:contentHeaders];
        }

        NSString* httpVersionStr;
        switch (httpVersion) {
            case HttpVersion_Http10:
                httpVersionStr = @"HTTP/1.0";
                break;
            case HttpVersion_Http11:
                httpVersionStr = @"HTTP/1.1";
                break;
            case HttpVersion_Http20:
                httpVersionStr = @"HTTP/2.0";
                break;
            default:
                httpVersionStr = nil;
        }
        NSHTTPURLResponse* nsResponse =
            [[[NSHTTPURLResponse alloc] initWithURL:[_request URL] statusCode:statusCode HTTPVersion:httpVersionStr headerFields:nsHeaders]
                autorelease];

        if (statusCode >= 300 && statusCode <= 399) { // redirect code
            ComPtr<IUriRuntimeClass> uri;
            THROW_IF_FAILED(headerCollection->get_Location(&uri));
            if (!uri) {
                THROW_HR(E_UNEXPECTED);
            }

            Wrappers::HString uriString;
            THROW_IF_FAILED(uri->get_AbsoluteUri(uriString.GetAddressOf()));

            // The location header can specify a relative or absolute URL: attempt to join it with the request URL.
            NSURL* targetUrl = [NSURL URLWithString:Strings::WideToNSString(uriString.Get()) relativeToURL:[_request URL]];
            NSURLRequest* req = [NSURLRequest requestWithURL:targetUrl];
            [_client URLProtocol:self wasRedirectedToRequest:req redirectResponse:nsResponse];
            // After a redirect, NSURLProtocol ceases to exist: we could redirect to a completely different one.
            return S_OK;
        } else {
            [_client URLProtocol:self didReceiveResponse:nsResponse cacheStoragePolicy:NSURLCacheStorageNotAllowed];
        }

        if (content) {
            [self retain]; // we could be cancelled mid-operation, but we need to retain the ability to clean up.
            dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0),
                           ^{
                               [self _consumeDataStreamForIHttpContent:content.Get()];
                               [self release];
                           });
        }

        return S_OK;
    }
    CATCH_POPULATE_NSERROR(&error);

    if (error) {
        [self _propagateErrorToClient:error];
    }

    return S_OK;
}

- (void)_propagateErrorToClient:(NSError*)error {
    [_client URLProtocol:self didFailWithError:error];
}

- (void)_didFinishLoading {
    [_client URLProtocolDidFinishLoading:self];
}

- (void)_consumeDataStreamForIHttpContent:(IHttpContent*)pHttpContent {
    ComPtr<IHttpContent> httpContent(pHttpContent);
    id strongSelf = self;
    NSError* error = nil;
    try {
        ComPtr<IInputStream> stream;
        WRLHelpers::AwaitProgressCompleteHelper<IInputStream*,
                                                uint64_t>([&](IAsyncOperationWithProgress<IInputStream*, uint64_t>** operation) {
            return httpContent->ReadAsInputStreamAsync(operation);
        }, stream.ReleaseAndGetAddressOf());

        std::vector<unsigned char> buffer(kHTTPContentBufferSize);
        ComPtr<IBuffer> rawDataBuffer;
        THROW_IF_FAILED(BufferFromRawData(rawDataBuffer.GetAddressOf(), buffer.data(), buffer.size()));
        ComPtr<IBuffer> outputBuffer;

        while (true) {
            if ([strongSelf cancelled]) {
                return;
            }

            HRESULT hr =
                WRLHelpers::AwaitProgressCompleteHelper<IBuffer*,
                                                        uint32_t>([&](IAsyncOperationWithProgress<IBuffer*, uint32_t>** operation) {
                    return stream->ReadAsync(rawDataBuffer.Get(), buffer.size(), InputStreamOptions::InputStreamOptions_Partial, operation);
                }, outputBuffer.ReleaseAndGetAddressOf());
            THROW_IF_FAILED(hr);

            if ([strongSelf cancelled]) { // double check on cancel after a long-running async operation.
                return;
            }

            unsigned int length = 0;
            THROW_IF_FAILED(outputBuffer->get_Length(&length));
            if (length == 0) {
                break;
            }

            ComPtr<IBufferByteAccess> comByteAccess;
            THROW_IF_FAILED(outputBuffer.As(&comByteAccess));
            unsigned char* pOutputBuffer = nullptr;
            THROW_IF_FAILED(comByteAccess->Buffer(&pOutputBuffer));

            // We're opting to take a copy of the buffer here, as NSURLProtocol's consumer can legally expect the data
            // to remain valid long after the connection is gone. Eventually, it would be very nice to have an IBuffer-backed
            // NSData.
            [_client URLProtocol:strongSelf didLoadData:[NSData dataWithBytes:pOutputBuffer length:length]];
        }

        [strongSelf _didFinishLoading];
    }
    CATCH_POPULATE_NSERROR(&error);

    if (error) {
        [strongSelf _propagateErrorToClient:error];
    }
}
@end