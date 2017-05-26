//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

// WindowsWebHttpHeaders.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Web.Http.Headers.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsWebHttpHeaders.h"
#include "WindowsWebHttpHeaders_priv.h"

@implementation WWHHHttpContentHeaderCollection {
    RTMapObj<HSTRING,
             HSTRING,
             HSTRING,
             HSTRING,
             NSString,
             NSString,
             IMap<HSTRING, HSTRING>,
             dummyObjCCreator,
             dummyObjCCreator,
             dummyWRLCreator,
             dummyWRLCreator>
        _map;
}
INTEROP_IMPL_MAP(self.comObj, RTProxiedNSMutableDictionary_NSString_NSString, HSTRING, HSTRING, HSTRING, HSTRING, NSString, NSString)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentHeaderCollection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Web.Http.Headers.HttpContentHeaderCollection").Get(), &out));
    return [_createRtProxy<WWHHHttpContentHeaderCollection>(out.Get()) retain];
}

- (WWHHHttpContentDispositionHeaderValue*)contentDisposition {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentDisposition(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpContentDispositionHeaderValue>(unmarshalledReturn.Get());
}

- (void)setContentDisposition:(WWHHHttpContentDispositionHeaderValue*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->put_ContentDisposition(
        _getRtInterface<ABI::Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue>(value).Get()));
}

- (WWHHHttpContentCodingHeaderValueCollection*)contentEncoding {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentCodingHeaderValueCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentEncoding(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpContentCodingHeaderValueCollection>(unmarshalledReturn.Get());
}

- (WWHHHttpLanguageHeaderValueCollection*)contentLanguage {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpLanguageHeaderValueCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentLanguage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpLanguageHeaderValueCollection>(unmarshalledReturn.Get());
}

- (id /* uint64_t */)contentLength {
    ComPtr<IReference<uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentLength(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<uint64_t, uint64_t>::convert(unmarshalledReturn.Get());
}

- (void)setContentLength:(id /* uint64_t */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->put_ContentLength(BuildNullable<uint64_t>(value)));
}

- (WFUri*)contentLocation {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentLocation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setContentLocation:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->put_ContentLocation(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (RTObject<WSSIBuffer>*)contentMD5 {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentMD5(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)setContentMD5:(RTObject<WSSIBuffer>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->put_ContentMD5(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(value).Get()));
}

- (WWHHHttpContentRangeHeaderValue*)contentRange {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentRangeHeaderValue> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentRange(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpContentRangeHeaderValue>(unmarshalledReturn.Get());
}

- (void)setContentRange:(WWHHHttpContentRangeHeaderValue*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentHeaderCollection>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ContentRange(_getRtInterface<ABI::Windows::Web::Http::Headers::IHttpContentRangeHeaderValue>(value).Get()));
}

- (WWHHHttpMediaTypeHeaderValue*)contentType {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpMediaTypeHeaderValue> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentType(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpMediaTypeHeaderValue>(unmarshalledReturn.Get());
}

- (void)setContentType:(WWHHHttpMediaTypeHeaderValue*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentHeaderCollection>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ContentType(_getRtInterface<ABI::Windows::Web::Http::Headers::IHttpMediaTypeHeaderValue>(value).Get()));
}

- (id /* WFDateTime* */)expires {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Expires(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (void)setExpires:(id /* WFDateTime* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->put_Expires(BuildNullable<ABI::Windows::Foundation::DateTime>(value)));
}

- (id /* WFDateTime* */)lastModified {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastModified(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (void)setLastModified:(id /* WFDateTime* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->put_LastModified(BuildNullable<ABI::Windows::Foundation::DateTime>(value)));
}

- (void)append:(NSString*)name value:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->Append(nsStrToHstr(name).Get(), nsStrToHstr(value).Get()));
}

- (BOOL)tryAppendWithoutValidation:(NSString*)name value:(NSString*)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->TryAppendWithoutValidation(nsStrToHstr(name).Get(), nsStrToHstr(value).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpRequestHeaderCollection {
    RTMapObj<HSTRING,
             HSTRING,
             HSTRING,
             HSTRING,
             NSString,
             NSString,
             IMap<HSTRING, HSTRING>,
             dummyObjCCreator,
             dummyObjCCreator,
             dummyWRLCreator,
             dummyWRLCreator>
        _map;
}
INTEROP_IMPL_MAP(self.comObj, RTProxiedNSMutableDictionary_NSString_NSString, HSTRING, HSTRING, HSTRING, HSTRING, NSString, NSString)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WWHHHttpMediaTypeWithQualityHeaderValueCollection*)accept {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValueCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Accept(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpMediaTypeWithQualityHeaderValueCollection>(unmarshalledReturn.Get());
}

- (WWHHHttpContentCodingWithQualityHeaderValueCollection*)acceptEncoding {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValueCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_AcceptEncoding(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpContentCodingWithQualityHeaderValueCollection>(unmarshalledReturn.Get());
}

- (WWHHHttpLanguageRangeWithQualityHeaderValueCollection*)acceptLanguage {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValueCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_AcceptLanguage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpLanguageRangeWithQualityHeaderValueCollection>(unmarshalledReturn.Get());
}

- (WWHHHttpCredentialsHeaderValue*)authorization {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpCredentialsHeaderValue> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Authorization(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpCredentialsHeaderValue>(unmarshalledReturn.Get());
}

- (void)setAuthorization:(WWHHHttpCredentialsHeaderValue*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_Authorization(_getRtInterface<ABI::Windows::Web::Http::Headers::IHttpCredentialsHeaderValue>(value).Get()));
}

- (WWHHHttpCacheDirectiveHeaderValueCollection*)cacheControl {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpCacheDirectiveHeaderValueCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_CacheControl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpCacheDirectiveHeaderValueCollection>(unmarshalledReturn.Get());
}

- (WWHHHttpConnectionOptionHeaderValueCollection*)connection {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValueCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Connection(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpConnectionOptionHeaderValueCollection>(unmarshalledReturn.Get());
}

- (WWHHHttpCookiePairHeaderValueCollection*)cookie {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpCookiePairHeaderValueCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Cookie(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpCookiePairHeaderValueCollection>(unmarshalledReturn.Get());
}

- (id /* WFDateTime* */)date {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Date(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (void)setDate:(id /* WFDateTime* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->put_Date(BuildNullable<ABI::Windows::Foundation::DateTime>(value)));
}

- (WWHHHttpExpectationHeaderValueCollection*)expect {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpExpectationHeaderValueCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Expect(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpExpectationHeaderValueCollection>(unmarshalledReturn.Get());
}

- (NSString*)from {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_From(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setFrom:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->put_From(nsStrToHstr(value).Get()));
}

- (WNHostName*)host {
    ComPtr<ABI::Windows::Networking::IHostName> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Host(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNHostName>(unmarshalledReturn.Get());
}

- (void)setHost:(WNHostName*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->put_Host(_getRtInterface<ABI::Windows::Networking::IHostName>(value).Get()));
}

- (id /* WFDateTime* */)ifModifiedSince {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_IfModifiedSince(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (void)setIfModifiedSince:(id /* WFDateTime* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->put_IfModifiedSince(BuildNullable<ABI::Windows::Foundation::DateTime>(value)));
}

- (id /* WFDateTime* */)ifUnmodifiedSince {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_IfUnmodifiedSince(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (void)setIfUnmodifiedSince:(id /* WFDateTime* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->put_IfUnmodifiedSince(BuildNullable<ABI::Windows::Foundation::DateTime>(value)));
}

- (id /* unsigned int */)maxForwards {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxForwards(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

- (void)setMaxForwards:(id /* unsigned int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxForwards(BuildNullable<unsigned int>(value)));
}

- (WWHHHttpCredentialsHeaderValue*)proxyAuthorization {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpCredentialsHeaderValue> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProxyAuthorization(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpCredentialsHeaderValue>(unmarshalledReturn.Get());
}

- (void)setProxyAuthorization:(WWHHHttpCredentialsHeaderValue*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ProxyAuthorization(_getRtInterface<ABI::Windows::Web::Http::Headers::IHttpCredentialsHeaderValue>(value).Get()));
}

- (WFUri*)referer {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Referer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setReferer:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->put_Referer(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (WWHHHttpTransferCodingHeaderValueCollection*)transferEncoding {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpTransferCodingHeaderValueCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransferEncoding(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpTransferCodingHeaderValueCollection>(unmarshalledReturn.Get());
}

- (WWHHHttpProductInfoHeaderValueCollection*)userAgent {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpProductInfoHeaderValueCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_UserAgent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpProductInfoHeaderValueCollection>(unmarshalledReturn.Get());
}

- (void)append:(NSString*)name value:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->Append(nsStrToHstr(name).Get(), nsStrToHstr(value).Get()));
}

- (BOOL)tryAppendWithoutValidation:(NSString*)name value:(NSString*)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->TryAppendWithoutValidation(nsStrToHstr(name).Get(), nsStrToHstr(value).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpResponseHeaderCollection {
    RTMapObj<HSTRING,
             HSTRING,
             HSTRING,
             HSTRING,
             NSString,
             NSString,
             IMap<HSTRING, HSTRING>,
             dummyObjCCreator,
             dummyObjCCreator,
             dummyWRLCreator,
             dummyWRLCreator>
        _map;
}
INTEROP_IMPL_MAP(self.comObj, RTProxiedNSMutableDictionary_NSString_NSString, HSTRING, HSTRING, HSTRING, HSTRING, NSString, NSString)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpResponseHeaderCollection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (id /* WFTimeSpan* */)age {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpResponseHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Age(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (void)setAge:(id /* WFTimeSpan* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpResponseHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->put_Age(BuildNullable<ABI::Windows::Foundation::TimeSpan>(value)));
}

- (WWHHHttpMethodHeaderValueCollection*)allow {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpMethodHeaderValueCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpResponseHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Allow(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpMethodHeaderValueCollection>(unmarshalledReturn.Get());
}

- (WWHHHttpCacheDirectiveHeaderValueCollection*)cacheControl {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpCacheDirectiveHeaderValueCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpResponseHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_CacheControl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpCacheDirectiveHeaderValueCollection>(unmarshalledReturn.Get());
}

- (WWHHHttpConnectionOptionHeaderValueCollection*)connection {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValueCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpResponseHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Connection(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpConnectionOptionHeaderValueCollection>(unmarshalledReturn.Get());
}

- (id /* WFDateTime* */)date {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpResponseHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Date(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (void)setDate:(id /* WFDateTime* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpResponseHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->put_Date(BuildNullable<ABI::Windows::Foundation::DateTime>(value)));
}

- (WFUri*)location {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpResponseHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Location(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setLocation:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpResponseHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->put_Location(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (WWHHHttpChallengeHeaderValueCollection*)proxyAuthenticate {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpChallengeHeaderValueCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpResponseHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProxyAuthenticate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpChallengeHeaderValueCollection>(unmarshalledReturn.Get());
}

- (WWHHHttpDateOrDeltaHeaderValue*)retryAfter {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpDateOrDeltaHeaderValue> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpResponseHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_RetryAfter(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpDateOrDeltaHeaderValue>(unmarshalledReturn.Get());
}

- (void)setRetryAfter:(WWHHHttpDateOrDeltaHeaderValue*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpResponseHeaderCollection>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_RetryAfter(_getRtInterface<ABI::Windows::Web::Http::Headers::IHttpDateOrDeltaHeaderValue>(value).Get()));
}

- (WWHHHttpTransferCodingHeaderValueCollection*)transferEncoding {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpTransferCodingHeaderValueCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpResponseHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransferEncoding(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpTransferCodingHeaderValueCollection>(unmarshalledReturn.Get());
}

- (WWHHHttpChallengeHeaderValueCollection*)wwwAuthenticate {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpChallengeHeaderValueCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpResponseHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_WwwAuthenticate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpChallengeHeaderValueCollection>(unmarshalledReturn.Get());
}

- (void)append:(NSString*)name value:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpResponseHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->Append(nsStrToHstr(name).Get(), nsStrToHstr(value).Get()));
}

- (BOOL)tryAppendWithoutValidation:(NSString*)name value:(NSString*)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpResponseHeaderCollection>(self);
    THROW_NS_IF_FAILED(_comInst->TryAppendWithoutValidation(nsStrToHstr(name).Get(), nsStrToHstr(value).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpContentDispositionHeaderValue

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentDispositionHeaderValueFactory>
WWHHIHttpContentDispositionHeaderValueFactory_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentDispositionHeaderValueFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Web.Http.Headers.HttpContentDispositionHeaderValue").Get(), &inst));
    return inst;
}

+ (WWHHHttpContentDispositionHeaderValue*)make:(NSString*)dispositionType {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpContentDispositionHeaderValueFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(dispositionType).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHHttpContentDispositionHeaderValue>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentDispositionHeaderValueStatics> WWHHIHttpContentDispositionHeaderValueStatics_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentDispositionHeaderValueStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Web.Http.Headers.HttpContentDispositionHeaderValue").Get(), &inst));
    return inst;
}

+ (WWHHHttpContentDispositionHeaderValue*)parse:(NSString*)input {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpContentDispositionHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Parse(nsStrToHstr(input).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpContentDispositionHeaderValue>(unmarshalledReturn.Get());
}

+ (BOOL)tryParse:(NSString*)input contentDispositionHeaderValue:(WWHHHttpContentDispositionHeaderValue**)contentDispositionHeaderValue {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue> contentDispositionHeaderValueOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = WWHHIHttpContentDispositionHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->TryParse(nsStrToHstr(input).Get(), contentDispositionHeaderValueOutUnmarshaled.GetAddressOf(), &unmarshalledReturn));
    *contentDispositionHeaderValue =
        _createRtProxy<WWHHHttpContentDispositionHeaderValue>(contentDispositionHeaderValueOutUnmarshaled.Get());
    return (BOOL)unmarshalledReturn;
}

- (NSString*)dispositionType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_DispositionType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDispositionType:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->put_DispositionType(nsStrToHstr(value).Get()));
}

- (NSString*)fileName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_FileName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setFileName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->put_FileName(nsStrToHstr(value).Get()));
}

- (NSString*)fileNameStar {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_FileNameStar(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setFileNameStar:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->put_FileNameStar(nsStrToHstr(value).Get()));
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->put_Name(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* WWHHHttpNameValueHeaderValue* */)parameters {
    ComPtr<IVector<ABI::Windows::Web::Http::Headers::HttpNameValueHeaderValue*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Parameters(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WWHHHttpNameValueHeaderValue_create(unmarshalledReturn.Get());
}

- (id /* uint64_t */)size {
    ComPtr<IReference<uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Size(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<uint64_t, uint64_t>::convert(unmarshalledReturn.Get());
}

- (void)setSize:(id /* uint64_t */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->put_Size(BuildNullable<uint64_t>(value)));
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpContentCodingHeaderValueCollection {
    RTMutableArrayObj<ABI::Windows::Web::Http::Headers::IHttpContentCodingHeaderValue*,
                      IVector<ABI::Windows::Web::Http::Headers::HttpContentCodingHeaderValue*>,
                      WWHHHttpContentCodingHeaderValue,
                      ABI::Windows::Web::Http::Headers::HttpContentCodingHeaderValue*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj,
                         WWHHHttpContentCodingHeaderValue,
                         ABI::Windows::Web::Http::Headers::IHttpContentCodingHeaderValue*,
                         ABI::Windows::Web::Http::Headers::HttpContentCodingHeaderValue*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentCodingHeaderValueCollection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)parseAdd:(NSString*)input {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentCodingHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->ParseAdd(nsStrToHstr(input).Get()));
}

- (BOOL)tryParseAdd:(NSString*)input {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentCodingHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->TryParseAdd(nsStrToHstr(input).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpLanguageHeaderValueCollection {
    RTMutableArrayObj<ABI::Windows::Globalization::ILanguage*,
                      IVector<ABI::Windows::Globalization::Language*>,
                      WGLanguage,
                      ABI::Windows::Globalization::Language*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj, WGLanguage, ABI::Windows::Globalization::ILanguage*, ABI::Windows::Globalization::Language*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpLanguageHeaderValueCollection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)parseAdd:(NSString*)input {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpLanguageHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->ParseAdd(nsStrToHstr(input).Get()));
}

- (BOOL)tryParseAdd:(NSString*)input {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpLanguageHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->TryParseAdd(nsStrToHstr(input).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpContentRangeHeaderValue

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentRangeHeaderValue> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentRangeHeaderValueFactory> WWHHIHttpContentRangeHeaderValueFactory_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentRangeHeaderValueFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Web.Http.Headers.HttpContentRangeHeaderValue").Get(), &inst));
    return inst;
}

+ (WWHHHttpContentRangeHeaderValue*)makeFromLength:(uint64_t)length {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentRangeHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpContentRangeHeaderValueFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromLength(length, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHHttpContentRangeHeaderValue>(unmarshalledReturn.Get()) retain];
}

+ (WWHHHttpContentRangeHeaderValue*)makeFromRange:(uint64_t)from to:(uint64_t)to {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentRangeHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpContentRangeHeaderValueFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromRange(from, to, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHHttpContentRangeHeaderValue>(unmarshalledReturn.Get()) retain];
}

+ (WWHHHttpContentRangeHeaderValue*)makeFromRangeWithLength:(uint64_t)from to:(uint64_t)to length:(uint64_t)length {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentRangeHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpContentRangeHeaderValueFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromRangeWithLength(from, to, length, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHHttpContentRangeHeaderValue>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentRangeHeaderValueStatics> WWHHIHttpContentRangeHeaderValueStatics_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentRangeHeaderValueStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Web.Http.Headers.HttpContentRangeHeaderValue").Get(), &inst));
    return inst;
}

+ (WWHHHttpContentRangeHeaderValue*)parse:(NSString*)input {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentRangeHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpContentRangeHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Parse(nsStrToHstr(input).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpContentRangeHeaderValue>(unmarshalledReturn.Get());
}

+ (BOOL)tryParse:(NSString*)input contentRangeHeaderValue:(WWHHHttpContentRangeHeaderValue**)contentRangeHeaderValue {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentRangeHeaderValue> contentRangeHeaderValueOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = WWHHIHttpContentRangeHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->TryParse(nsStrToHstr(input).Get(), contentRangeHeaderValueOutUnmarshaled.GetAddressOf(), &unmarshalledReturn));
    *contentRangeHeaderValue = _createRtProxy<WWHHHttpContentRangeHeaderValue>(contentRangeHeaderValueOutUnmarshaled.Get());
    return (BOOL)unmarshalledReturn;
}

- (id /* uint64_t */)firstBytePosition {
    ComPtr<IReference<uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentRangeHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstBytePosition(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<uint64_t, uint64_t>::convert(unmarshalledReturn.Get());
}

- (id /* uint64_t */)lastBytePosition {
    ComPtr<IReference<uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentRangeHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastBytePosition(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<uint64_t, uint64_t>::convert(unmarshalledReturn.Get());
}

- (id /* uint64_t */)length {
    ComPtr<IReference<uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentRangeHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Length(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<uint64_t, uint64_t>::convert(unmarshalledReturn.Get());
}

- (NSString*)unit {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentRangeHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Unit(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setUnit:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentRangeHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->put_Unit(nsStrToHstr(value).Get()));
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpMediaTypeHeaderValue

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpMediaTypeHeaderValue> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Web::Http::Headers::IHttpMediaTypeHeaderValueFactory> WWHHIHttpMediaTypeHeaderValueFactory_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpMediaTypeHeaderValueFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.Headers.HttpMediaTypeHeaderValue").Get(),
                                                       &inst));
    return inst;
}

+ (WWHHHttpMediaTypeHeaderValue*)make:(NSString*)mediaType {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpMediaTypeHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpMediaTypeHeaderValueFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(mediaType).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHHttpMediaTypeHeaderValue>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Web::Http::Headers::IHttpMediaTypeHeaderValueStatics> WWHHIHttpMediaTypeHeaderValueStatics_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpMediaTypeHeaderValueStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.Headers.HttpMediaTypeHeaderValue").Get(),
                                                       &inst));
    return inst;
}

+ (WWHHHttpMediaTypeHeaderValue*)parse:(NSString*)input {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpMediaTypeHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpMediaTypeHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Parse(nsStrToHstr(input).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpMediaTypeHeaderValue>(unmarshalledReturn.Get());
}

+ (BOOL)tryParse:(NSString*)input mediaTypeHeaderValue:(WWHHHttpMediaTypeHeaderValue**)mediaTypeHeaderValue {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpMediaTypeHeaderValue> mediaTypeHeaderValueOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = WWHHIHttpMediaTypeHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->TryParse(nsStrToHstr(input).Get(), mediaTypeHeaderValueOutUnmarshaled.GetAddressOf(), &unmarshalledReturn));
    *mediaTypeHeaderValue = _createRtProxy<WWHHHttpMediaTypeHeaderValue>(mediaTypeHeaderValueOutUnmarshaled.Get());
    return (BOOL)unmarshalledReturn;
}

- (NSString*)charSet {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpMediaTypeHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_CharSet(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCharSet:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpMediaTypeHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->put_CharSet(nsStrToHstr(value).Get()));
}

- (NSString*)mediaType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpMediaTypeHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setMediaType:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpMediaTypeHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->put_MediaType(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* WWHHHttpNameValueHeaderValue* */)parameters {
    ComPtr<IVector<ABI::Windows::Web::Http::Headers::HttpNameValueHeaderValue*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpMediaTypeHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Parameters(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WWHHHttpNameValueHeaderValue_create(unmarshalledReturn.Get());
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpMediaTypeWithQualityHeaderValueCollection {
    RTMutableArrayObj<ABI::Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue*,
                      IVector<ABI::Windows::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValue*>,
                      WWHHHttpMediaTypeWithQualityHeaderValue,
                      ABI::Windows::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValue*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj,
                         WWHHHttpMediaTypeWithQualityHeaderValue,
                         ABI::Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue*,
                         ABI::Windows::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValue*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValueCollection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)parseAdd:(NSString*)input {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->ParseAdd(nsStrToHstr(input).Get()));
}

- (BOOL)tryParseAdd:(NSString*)input {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->TryParseAdd(nsStrToHstr(input).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpContentCodingWithQualityHeaderValueCollection {
    RTMutableArrayObj<ABI::Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValue*,
                      IVector<ABI::Windows::Web::Http::Headers::HttpContentCodingWithQualityHeaderValue*>,
                      WWHHHttpContentCodingWithQualityHeaderValue,
                      ABI::Windows::Web::Http::Headers::HttpContentCodingWithQualityHeaderValue*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj,
                         WWHHHttpContentCodingWithQualityHeaderValue,
                         ABI::Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValue*,
                         ABI::Windows::Web::Http::Headers::HttpContentCodingWithQualityHeaderValue*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValueCollection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)parseAdd:(NSString*)input {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->ParseAdd(nsStrToHstr(input).Get()));
}

- (BOOL)tryParseAdd:(NSString*)input {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->TryParseAdd(nsStrToHstr(input).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpLanguageRangeWithQualityHeaderValueCollection {
    RTMutableArrayObj<ABI::Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValue*,
                      IVector<ABI::Windows::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValue*>,
                      WWHHHttpLanguageRangeWithQualityHeaderValue,
                      ABI::Windows::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValue*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj,
                         WWHHHttpLanguageRangeWithQualityHeaderValue,
                         ABI::Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValue*,
                         ABI::Windows::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValue*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValueCollection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)parseAdd:(NSString*)input {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->ParseAdd(nsStrToHstr(input).Get()));
}

- (BOOL)tryParseAdd:(NSString*)input {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->TryParseAdd(nsStrToHstr(input).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpCredentialsHeaderValue

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpCredentialsHeaderValue> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Web::Http::Headers::IHttpCredentialsHeaderValueFactory> WWHHIHttpCredentialsHeaderValueFactory_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpCredentialsHeaderValueFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.Headers.HttpCredentialsHeaderValue").Get(),
                                                       &inst));
    return inst;
}

+ (WWHHHttpCredentialsHeaderValue*)makeFromScheme:(NSString*)scheme {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpCredentialsHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpCredentialsHeaderValueFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromScheme(nsStrToHstr(scheme).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHHttpCredentialsHeaderValue>(unmarshalledReturn.Get()) retain];
}

+ (WWHHHttpCredentialsHeaderValue*)makeFromSchemeWithToken:(NSString*)scheme token:(NSString*)token {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpCredentialsHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpCredentialsHeaderValueFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateFromSchemeWithToken(nsStrToHstr(scheme).Get(), nsStrToHstr(token).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHHttpCredentialsHeaderValue>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Web::Http::Headers::IHttpCredentialsHeaderValueStatics> WWHHIHttpCredentialsHeaderValueStatics_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpCredentialsHeaderValueStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.Headers.HttpCredentialsHeaderValue").Get(),
                                                       &inst));
    return inst;
}

+ (WWHHHttpCredentialsHeaderValue*)parse:(NSString*)input {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpCredentialsHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpCredentialsHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Parse(nsStrToHstr(input).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpCredentialsHeaderValue>(unmarshalledReturn.Get());
}

+ (BOOL)tryParse:(NSString*)input credentialsHeaderValue:(WWHHHttpCredentialsHeaderValue**)credentialsHeaderValue {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpCredentialsHeaderValue> credentialsHeaderValueOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = WWHHIHttpCredentialsHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->TryParse(nsStrToHstr(input).Get(), credentialsHeaderValueOutUnmarshaled.GetAddressOf(), &unmarshalledReturn));
    *credentialsHeaderValue = _createRtProxy<WWHHHttpCredentialsHeaderValue>(credentialsHeaderValueOutUnmarshaled.Get());
    return (BOOL)unmarshalledReturn;
}

- (NSMutableArray* /* WWHHHttpNameValueHeaderValue* */)parameters {
    ComPtr<IVector<ABI::Windows::Web::Http::Headers::HttpNameValueHeaderValue*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpCredentialsHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Parameters(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WWHHHttpNameValueHeaderValue_create(unmarshalledReturn.Get());
}

- (NSString*)scheme {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpCredentialsHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Scheme(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)token {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpCredentialsHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Token(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpCacheDirectiveHeaderValueCollection {
    RTMutableArrayObj<ABI::Windows::Web::Http::Headers::IHttpNameValueHeaderValue*,
                      IVector<ABI::Windows::Web::Http::Headers::HttpNameValueHeaderValue*>,
                      WWHHHttpNameValueHeaderValue,
                      ABI::Windows::Web::Http::Headers::HttpNameValueHeaderValue*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj,
                         WWHHHttpNameValueHeaderValue,
                         ABI::Windows::Web::Http::Headers::IHttpNameValueHeaderValue*,
                         ABI::Windows::Web::Http::Headers::HttpNameValueHeaderValue*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpCacheDirectiveHeaderValueCollection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (id /* WFTimeSpan* */)maxAge {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpCacheDirectiveHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxAge(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (void)setMaxAge:(id /* WFTimeSpan* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpCacheDirectiveHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxAge(BuildNullable<ABI::Windows::Foundation::TimeSpan>(value)));
}

- (id /* WFTimeSpan* */)maxStale {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpCacheDirectiveHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxStale(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (void)setMaxStale:(id /* WFTimeSpan* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpCacheDirectiveHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxStale(BuildNullable<ABI::Windows::Foundation::TimeSpan>(value)));
}

- (id /* WFTimeSpan* */)minFresh {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpCacheDirectiveHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinFresh(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (void)setMinFresh:(id /* WFTimeSpan* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpCacheDirectiveHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->put_MinFresh(BuildNullable<ABI::Windows::Foundation::TimeSpan>(value)));
}

- (id /* WFTimeSpan* */)sharedMaxAge {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpCacheDirectiveHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_SharedMaxAge(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (void)setSharedMaxAge:(id /* WFTimeSpan* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpCacheDirectiveHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->put_SharedMaxAge(BuildNullable<ABI::Windows::Foundation::TimeSpan>(value)));
}

- (void)parseAdd:(NSString*)input {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpCacheDirectiveHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->ParseAdd(nsStrToHstr(input).Get()));
}

- (BOOL)tryParseAdd:(NSString*)input {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpCacheDirectiveHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->TryParseAdd(nsStrToHstr(input).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpConnectionOptionHeaderValueCollection {
    RTMutableArrayObj<ABI::Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValue*,
                      IVector<ABI::Windows::Web::Http::Headers::HttpConnectionOptionHeaderValue*>,
                      WWHHHttpConnectionOptionHeaderValue,
                      ABI::Windows::Web::Http::Headers::HttpConnectionOptionHeaderValue*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj,
                         WWHHHttpConnectionOptionHeaderValue,
                         ABI::Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValue*,
                         ABI::Windows::Web::Http::Headers::HttpConnectionOptionHeaderValue*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValueCollection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)parseAdd:(NSString*)input {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->ParseAdd(nsStrToHstr(input).Get()));
}

- (BOOL)tryParseAdd:(NSString*)input {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->TryParseAdd(nsStrToHstr(input).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpCookiePairHeaderValueCollection {
    RTMutableArrayObj<ABI::Windows::Web::Http::Headers::IHttpCookiePairHeaderValue*,
                      IVector<ABI::Windows::Web::Http::Headers::HttpCookiePairHeaderValue*>,
                      WWHHHttpCookiePairHeaderValue,
                      ABI::Windows::Web::Http::Headers::HttpCookiePairHeaderValue*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj,
                         WWHHHttpCookiePairHeaderValue,
                         ABI::Windows::Web::Http::Headers::IHttpCookiePairHeaderValue*,
                         ABI::Windows::Web::Http::Headers::HttpCookiePairHeaderValue*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpCookiePairHeaderValueCollection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)parseAdd:(NSString*)input {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpCookiePairHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->ParseAdd(nsStrToHstr(input).Get()));
}

- (BOOL)tryParseAdd:(NSString*)input {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpCookiePairHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->TryParseAdd(nsStrToHstr(input).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpExpectationHeaderValueCollection {
    RTMutableArrayObj<ABI::Windows::Web::Http::Headers::IHttpExpectationHeaderValue*,
                      IVector<ABI::Windows::Web::Http::Headers::HttpExpectationHeaderValue*>,
                      WWHHHttpExpectationHeaderValue,
                      ABI::Windows::Web::Http::Headers::HttpExpectationHeaderValue*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj,
                         WWHHHttpExpectationHeaderValue,
                         ABI::Windows::Web::Http::Headers::IHttpExpectationHeaderValue*,
                         ABI::Windows::Web::Http::Headers::HttpExpectationHeaderValue*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpExpectationHeaderValueCollection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)parseAdd:(NSString*)input {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpExpectationHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->ParseAdd(nsStrToHstr(input).Get()));
}

- (BOOL)tryParseAdd:(NSString*)input {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpExpectationHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->TryParseAdd(nsStrToHstr(input).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpTransferCodingHeaderValueCollection {
    RTMutableArrayObj<ABI::Windows::Web::Http::Headers::IHttpTransferCodingHeaderValue*,
                      IVector<ABI::Windows::Web::Http::Headers::HttpTransferCodingHeaderValue*>,
                      WWHHHttpTransferCodingHeaderValue,
                      ABI::Windows::Web::Http::Headers::HttpTransferCodingHeaderValue*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj,
                         WWHHHttpTransferCodingHeaderValue,
                         ABI::Windows::Web::Http::Headers::IHttpTransferCodingHeaderValue*,
                         ABI::Windows::Web::Http::Headers::HttpTransferCodingHeaderValue*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpTransferCodingHeaderValueCollection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)parseAdd:(NSString*)input {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpTransferCodingHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->ParseAdd(nsStrToHstr(input).Get()));
}

- (BOOL)tryParseAdd:(NSString*)input {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpTransferCodingHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->TryParseAdd(nsStrToHstr(input).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpProductInfoHeaderValueCollection {
    RTMutableArrayObj<ABI::Windows::Web::Http::Headers::IHttpProductInfoHeaderValue*,
                      IVector<ABI::Windows::Web::Http::Headers::HttpProductInfoHeaderValue*>,
                      WWHHHttpProductInfoHeaderValue,
                      ABI::Windows::Web::Http::Headers::HttpProductInfoHeaderValue*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj,
                         WWHHHttpProductInfoHeaderValue,
                         ABI::Windows::Web::Http::Headers::IHttpProductInfoHeaderValue*,
                         ABI::Windows::Web::Http::Headers::HttpProductInfoHeaderValue*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpProductInfoHeaderValueCollection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)parseAdd:(NSString*)input {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpProductInfoHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->ParseAdd(nsStrToHstr(input).Get()));
}

- (BOOL)tryParseAdd:(NSString*)input {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpProductInfoHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->TryParseAdd(nsStrToHstr(input).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpMethodHeaderValueCollection {
    RTMutableArrayObj<ABI::Windows::Web::Http::IHttpMethod*,
                      IVector<ABI::Windows::Web::Http::HttpMethod*>,
                      WWHHttpMethod,
                      ABI::Windows::Web::Http::HttpMethod*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj, WWHHttpMethod, ABI::Windows::Web::Http::IHttpMethod*, ABI::Windows::Web::Http::HttpMethod*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpMethodHeaderValueCollection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)parseAdd:(NSString*)input {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpMethodHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->ParseAdd(nsStrToHstr(input).Get()));
}

- (BOOL)tryParseAdd:(NSString*)input {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpMethodHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->TryParseAdd(nsStrToHstr(input).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpChallengeHeaderValueCollection {
    RTMutableArrayObj<ABI::Windows::Web::Http::Headers::IHttpChallengeHeaderValue*,
                      IVector<ABI::Windows::Web::Http::Headers::HttpChallengeHeaderValue*>,
                      WWHHHttpChallengeHeaderValue,
                      ABI::Windows::Web::Http::Headers::HttpChallengeHeaderValue*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj,
                         WWHHHttpChallengeHeaderValue,
                         ABI::Windows::Web::Http::Headers::IHttpChallengeHeaderValue*,
                         ABI::Windows::Web::Http::Headers::HttpChallengeHeaderValue*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpChallengeHeaderValueCollection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)parseAdd:(NSString*)input {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpChallengeHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->ParseAdd(nsStrToHstr(input).Get()));
}

- (BOOL)tryParseAdd:(NSString*)input {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpChallengeHeaderValueCollection>(self);
    THROW_NS_IF_FAILED(_comInst->TryParseAdd(nsStrToHstr(input).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpDateOrDeltaHeaderValue

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpDateOrDeltaHeaderValue> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Web::Http::Headers::IHttpDateOrDeltaHeaderValueStatics> WWHHIHttpDateOrDeltaHeaderValueStatics_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpDateOrDeltaHeaderValueStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.Headers.HttpDateOrDeltaHeaderValue").Get(),
                                                       &inst));
    return inst;
}

+ (WWHHHttpDateOrDeltaHeaderValue*)parse:(NSString*)input {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpDateOrDeltaHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpDateOrDeltaHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Parse(nsStrToHstr(input).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpDateOrDeltaHeaderValue>(unmarshalledReturn.Get());
}

+ (BOOL)tryParse:(NSString*)input dateOrDeltaHeaderValue:(WWHHHttpDateOrDeltaHeaderValue**)dateOrDeltaHeaderValue {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpDateOrDeltaHeaderValue> dateOrDeltaHeaderValueOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = WWHHIHttpDateOrDeltaHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->TryParse(nsStrToHstr(input).Get(), dateOrDeltaHeaderValueOutUnmarshaled.GetAddressOf(), &unmarshalledReturn));
    *dateOrDeltaHeaderValue = _createRtProxy<WWHHHttpDateOrDeltaHeaderValue>(dateOrDeltaHeaderValueOutUnmarshaled.Get());
    return (BOOL)unmarshalledReturn;
}

- (id /* WFDateTime* */)date {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpDateOrDeltaHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Date(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (id /* WFTimeSpan* */)delta {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpDateOrDeltaHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Delta(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpNameValueHeaderValue

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpNameValueHeaderValue> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Web::Http::Headers::IHttpNameValueHeaderValueFactory> WWHHIHttpNameValueHeaderValueFactory_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpNameValueHeaderValueFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.Headers.HttpNameValueHeaderValue").Get(),
                                                       &inst));
    return inst;
}

+ (WWHHHttpNameValueHeaderValue*)makeFromName:(NSString*)name {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpNameValueHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpNameValueHeaderValueFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromName(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHHttpNameValueHeaderValue>(unmarshalledReturn.Get()) retain];
}

+ (WWHHHttpNameValueHeaderValue*)makeFromNameWithValue:(NSString*)name value:(NSString*)value {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpNameValueHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpNameValueHeaderValueFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateFromNameWithValue(nsStrToHstr(name).Get(), nsStrToHstr(value).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHHttpNameValueHeaderValue>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Web::Http::Headers::IHttpNameValueHeaderValueStatics> WWHHIHttpNameValueHeaderValueStatics_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpNameValueHeaderValueStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.Headers.HttpNameValueHeaderValue").Get(),
                                                       &inst));
    return inst;
}

+ (WWHHHttpNameValueHeaderValue*)parse:(NSString*)input {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpNameValueHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpNameValueHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Parse(nsStrToHstr(input).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpNameValueHeaderValue>(unmarshalledReturn.Get());
}

+ (BOOL)tryParse:(NSString*)input nameValueHeaderValue:(WWHHHttpNameValueHeaderValue**)nameValueHeaderValue {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpNameValueHeaderValue> nameValueHeaderValueOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = WWHHIHttpNameValueHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->TryParse(nsStrToHstr(input).Get(), nameValueHeaderValueOutUnmarshaled.GetAddressOf(), &unmarshalledReturn));
    *nameValueHeaderValue = _createRtProxy<WWHHHttpNameValueHeaderValue>(nameValueHeaderValueOutUnmarshaled.Get());
    return (BOOL)unmarshalledReturn;
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpNameValueHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpNameValueHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setValue:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpNameValueHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->put_Value(nsStrToHstr(value).Get()));
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpChallengeHeaderValue

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpChallengeHeaderValue> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Web::Http::Headers::IHttpChallengeHeaderValueFactory> WWHHIHttpChallengeHeaderValueFactory_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpChallengeHeaderValueFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.Headers.HttpChallengeHeaderValue").Get(),
                                                       &inst));
    return inst;
}

+ (WWHHHttpChallengeHeaderValue*)makeFromScheme:(NSString*)scheme {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpChallengeHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpChallengeHeaderValueFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromScheme(nsStrToHstr(scheme).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHHttpChallengeHeaderValue>(unmarshalledReturn.Get()) retain];
}

+ (WWHHHttpChallengeHeaderValue*)makeFromSchemeWithToken:(NSString*)scheme token:(NSString*)token {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpChallengeHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpChallengeHeaderValueFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateFromSchemeWithToken(nsStrToHstr(scheme).Get(), nsStrToHstr(token).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHHttpChallengeHeaderValue>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Web::Http::Headers::IHttpChallengeHeaderValueStatics> WWHHIHttpChallengeHeaderValueStatics_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpChallengeHeaderValueStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.Headers.HttpChallengeHeaderValue").Get(),
                                                       &inst));
    return inst;
}

+ (WWHHHttpChallengeHeaderValue*)parse:(NSString*)input {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpChallengeHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpChallengeHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Parse(nsStrToHstr(input).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpChallengeHeaderValue>(unmarshalledReturn.Get());
}

+ (BOOL)tryParse:(NSString*)input challengeHeaderValue:(WWHHHttpChallengeHeaderValue**)challengeHeaderValue {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpChallengeHeaderValue> challengeHeaderValueOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = WWHHIHttpChallengeHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->TryParse(nsStrToHstr(input).Get(), challengeHeaderValueOutUnmarshaled.GetAddressOf(), &unmarshalledReturn));
    *challengeHeaderValue = _createRtProxy<WWHHHttpChallengeHeaderValue>(challengeHeaderValueOutUnmarshaled.Get());
    return (BOOL)unmarshalledReturn;
}

- (NSMutableArray* /* WWHHHttpNameValueHeaderValue* */)parameters {
    ComPtr<IVector<ABI::Windows::Web::Http::Headers::HttpNameValueHeaderValue*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpChallengeHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Parameters(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WWHHHttpNameValueHeaderValue_create(unmarshalledReturn.Get());
}

- (NSString*)scheme {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpChallengeHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Scheme(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)token {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpChallengeHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Token(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpConnectionOptionHeaderValue

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValue> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValueFactory>
WWHHIHttpConnectionOptionHeaderValueFactory_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValueFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Web.Http.Headers.HttpConnectionOptionHeaderValue").Get(), &inst));
    return inst;
}

+ (WWHHHttpConnectionOptionHeaderValue*)make:(NSString*)token {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpConnectionOptionHeaderValueFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(token).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHHttpConnectionOptionHeaderValue>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValueStatics> WWHHIHttpConnectionOptionHeaderValueStatics_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValueStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Web.Http.Headers.HttpConnectionOptionHeaderValue").Get(), &inst));
    return inst;
}

+ (WWHHHttpConnectionOptionHeaderValue*)parse:(NSString*)input {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpConnectionOptionHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Parse(nsStrToHstr(input).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpConnectionOptionHeaderValue>(unmarshalledReturn.Get());
}

+ (BOOL)tryParse:(NSString*)input connectionOptionHeaderValue:(WWHHHttpConnectionOptionHeaderValue**)connectionOptionHeaderValue {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValue> connectionOptionHeaderValueOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = WWHHIHttpConnectionOptionHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->TryParse(nsStrToHstr(input).Get(), connectionOptionHeaderValueOutUnmarshaled.GetAddressOf(), &unmarshalledReturn));
    *connectionOptionHeaderValue = _createRtProxy<WWHHHttpConnectionOptionHeaderValue>(connectionOptionHeaderValueOutUnmarshaled.Get());
    return (BOOL)unmarshalledReturn;
}

- (NSString*)token {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Token(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpContentCodingHeaderValue

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentCodingHeaderValue> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentCodingHeaderValueFactory> WWHHIHttpContentCodingHeaderValueFactory_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentCodingHeaderValueFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Web.Http.Headers.HttpContentCodingHeaderValue").Get(), &inst));
    return inst;
}

+ (WWHHHttpContentCodingHeaderValue*)make:(NSString*)contentCoding {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentCodingHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpContentCodingHeaderValueFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(contentCoding).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHHttpContentCodingHeaderValue>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentCodingHeaderValueStatics> WWHHIHttpContentCodingHeaderValueStatics_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentCodingHeaderValueStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Web.Http.Headers.HttpContentCodingHeaderValue").Get(), &inst));
    return inst;
}

+ (WWHHHttpContentCodingHeaderValue*)parse:(NSString*)input {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentCodingHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpContentCodingHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Parse(nsStrToHstr(input).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpContentCodingHeaderValue>(unmarshalledReturn.Get());
}

+ (BOOL)tryParse:(NSString*)input contentCodingHeaderValue:(WWHHHttpContentCodingHeaderValue**)contentCodingHeaderValue {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentCodingHeaderValue> contentCodingHeaderValueOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = WWHHIHttpContentCodingHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->TryParse(nsStrToHstr(input).Get(), contentCodingHeaderValueOutUnmarshaled.GetAddressOf(), &unmarshalledReturn));
    *contentCodingHeaderValue = _createRtProxy<WWHHHttpContentCodingHeaderValue>(contentCodingHeaderValueOutUnmarshaled.Get());
    return (BOOL)unmarshalledReturn;
}

- (NSString*)contentCoding {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentCodingHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentCoding(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpCookiePairHeaderValue

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpCookiePairHeaderValue> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Web::Http::Headers::IHttpCookiePairHeaderValueFactory> WWHHIHttpCookiePairHeaderValueFactory_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpCookiePairHeaderValueFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.Headers.HttpCookiePairHeaderValue").Get(),
                                                       &inst));
    return inst;
}

+ (WWHHHttpCookiePairHeaderValue*)makeFromName:(NSString*)name {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpCookiePairHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpCookiePairHeaderValueFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromName(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHHttpCookiePairHeaderValue>(unmarshalledReturn.Get()) retain];
}

+ (WWHHHttpCookiePairHeaderValue*)makeFromNameWithValue:(NSString*)name value:(NSString*)value {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpCookiePairHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpCookiePairHeaderValueFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateFromNameWithValue(nsStrToHstr(name).Get(), nsStrToHstr(value).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHHttpCookiePairHeaderValue>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Web::Http::Headers::IHttpCookiePairHeaderValueStatics> WWHHIHttpCookiePairHeaderValueStatics_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpCookiePairHeaderValueStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.Headers.HttpCookiePairHeaderValue").Get(),
                                                       &inst));
    return inst;
}

+ (WWHHHttpCookiePairHeaderValue*)parse:(NSString*)input {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpCookiePairHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpCookiePairHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Parse(nsStrToHstr(input).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpCookiePairHeaderValue>(unmarshalledReturn.Get());
}

+ (BOOL)tryParse:(NSString*)input cookiePairHeaderValue:(WWHHHttpCookiePairHeaderValue**)cookiePairHeaderValue {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpCookiePairHeaderValue> cookiePairHeaderValueOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = WWHHIHttpCookiePairHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->TryParse(nsStrToHstr(input).Get(), cookiePairHeaderValueOutUnmarshaled.GetAddressOf(), &unmarshalledReturn));
    *cookiePairHeaderValue = _createRtProxy<WWHHHttpCookiePairHeaderValue>(cookiePairHeaderValueOutUnmarshaled.Get());
    return (BOOL)unmarshalledReturn;
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpCookiePairHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpCookiePairHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setValue:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpCookiePairHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->put_Value(nsStrToHstr(value).Get()));
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpExpectationHeaderValue

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpExpectationHeaderValue> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Web::Http::Headers::IHttpExpectationHeaderValueFactory> WWHHIHttpExpectationHeaderValueFactory_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpExpectationHeaderValueFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.Headers.HttpExpectationHeaderValue").Get(),
                                                       &inst));
    return inst;
}

+ (WWHHHttpExpectationHeaderValue*)makeFromName:(NSString*)name {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpExpectationHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpExpectationHeaderValueFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromName(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHHttpExpectationHeaderValue>(unmarshalledReturn.Get()) retain];
}

+ (WWHHHttpExpectationHeaderValue*)makeFromNameWithValue:(NSString*)name value:(NSString*)value {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpExpectationHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpExpectationHeaderValueFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateFromNameWithValue(nsStrToHstr(name).Get(), nsStrToHstr(value).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHHttpExpectationHeaderValue>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Web::Http::Headers::IHttpExpectationHeaderValueStatics> WWHHIHttpExpectationHeaderValueStatics_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpExpectationHeaderValueStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.Headers.HttpExpectationHeaderValue").Get(),
                                                       &inst));
    return inst;
}

+ (WWHHHttpExpectationHeaderValue*)parse:(NSString*)input {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpExpectationHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpExpectationHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Parse(nsStrToHstr(input).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpExpectationHeaderValue>(unmarshalledReturn.Get());
}

+ (BOOL)tryParse:(NSString*)input expectationHeaderValue:(WWHHHttpExpectationHeaderValue**)expectationHeaderValue {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpExpectationHeaderValue> expectationHeaderValueOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = WWHHIHttpExpectationHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->TryParse(nsStrToHstr(input).Get(), expectationHeaderValueOutUnmarshaled.GetAddressOf(), &unmarshalledReturn));
    *expectationHeaderValue = _createRtProxy<WWHHHttpExpectationHeaderValue>(expectationHeaderValueOutUnmarshaled.Get());
    return (BOOL)unmarshalledReturn;
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpExpectationHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpExpectationHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setValue:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpExpectationHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->put_Value(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* WWHHHttpNameValueHeaderValue* */)parameters {
    ComPtr<IVector<ABI::Windows::Web::Http::Headers::HttpNameValueHeaderValue*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpExpectationHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Parameters(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WWHHHttpNameValueHeaderValue_create(unmarshalledReturn.Get());
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpLanguageRangeWithQualityHeaderValue

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValue> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValueFactory>
WWHHIHttpLanguageRangeWithQualityHeaderValueFactory_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValueFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Web.Http.Headers.HttpLanguageRangeWithQualityHeaderValue").Get(), &inst));
    return inst;
}

+ (WWHHHttpLanguageRangeWithQualityHeaderValue*)makeFromLanguageRange:(NSString*)languageRange {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpLanguageRangeWithQualityHeaderValueFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromLanguageRange(nsStrToHstr(languageRange).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHHttpLanguageRangeWithQualityHeaderValue>(unmarshalledReturn.Get()) retain];
}

+ (WWHHHttpLanguageRangeWithQualityHeaderValue*)makeFromLanguageRangeWithQuality:(NSString*)languageRange quality:(double)quality {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpLanguageRangeWithQualityHeaderValueFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateFromLanguageRangeWithQuality(nsStrToHstr(languageRange).Get(), quality, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHHttpLanguageRangeWithQualityHeaderValue>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValueStatics>
WWHHIHttpLanguageRangeWithQualityHeaderValueStatics_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValueStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Web.Http.Headers.HttpLanguageRangeWithQualityHeaderValue").Get(), &inst));
    return inst;
}

+ (WWHHHttpLanguageRangeWithQualityHeaderValue*)parse:(NSString*)input {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpLanguageRangeWithQualityHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Parse(nsStrToHstr(input).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpLanguageRangeWithQualityHeaderValue>(unmarshalledReturn.Get());
}

+ (BOOL)tryParse:(NSString*)input
    languageRangeWithQualityHeaderValue:(WWHHHttpLanguageRangeWithQualityHeaderValue**)languageRangeWithQualityHeaderValue {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValue> languageRangeWithQualityHeaderValueOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = WWHHIHttpLanguageRangeWithQualityHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TryParse(nsStrToHstr(input).Get(),
                                          languageRangeWithQualityHeaderValueOutUnmarshaled.GetAddressOf(),
                                          &unmarshalledReturn));
    *languageRangeWithQualityHeaderValue =
        _createRtProxy<WWHHHttpLanguageRangeWithQualityHeaderValue>(languageRangeWithQualityHeaderValueOutUnmarshaled.Get());
    return (BOOL)unmarshalledReturn;
}

- (NSString*)languageRange {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_LanguageRange(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (id /* double */)quality {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Quality(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpMediaTypeWithQualityHeaderValue

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValueFactory>
WWHHIHttpMediaTypeWithQualityHeaderValueFactory_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValueFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Web.Http.Headers.HttpMediaTypeWithQualityHeaderValue").Get(), &inst));
    return inst;
}

+ (WWHHHttpMediaTypeWithQualityHeaderValue*)makeFromMediaType:(NSString*)mediaType {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpMediaTypeWithQualityHeaderValueFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromMediaType(nsStrToHstr(mediaType).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHHttpMediaTypeWithQualityHeaderValue>(unmarshalledReturn.Get()) retain];
}

+ (WWHHHttpMediaTypeWithQualityHeaderValue*)makeFromMediaTypeWithQuality:(NSString*)mediaType quality:(double)quality {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpMediaTypeWithQualityHeaderValueFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromMediaTypeWithQuality(nsStrToHstr(mediaType).Get(), quality, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHHttpMediaTypeWithQualityHeaderValue>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValueStatics>
WWHHIHttpMediaTypeWithQualityHeaderValueStatics_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValueStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Web.Http.Headers.HttpMediaTypeWithQualityHeaderValue").Get(), &inst));
    return inst;
}

+ (WWHHHttpMediaTypeWithQualityHeaderValue*)parse:(NSString*)input {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpMediaTypeWithQualityHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Parse(nsStrToHstr(input).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpMediaTypeWithQualityHeaderValue>(unmarshalledReturn.Get());
}

+ (BOOL)tryParse:(NSString*)input
    mediaTypeWithQualityHeaderValue:(WWHHHttpMediaTypeWithQualityHeaderValue**)mediaTypeWithQualityHeaderValue {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue> mediaTypeWithQualityHeaderValueOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = WWHHIHttpMediaTypeWithQualityHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->TryParse(nsStrToHstr(input).Get(), mediaTypeWithQualityHeaderValueOutUnmarshaled.GetAddressOf(), &unmarshalledReturn));
    *mediaTypeWithQualityHeaderValue =
        _createRtProxy<WWHHHttpMediaTypeWithQualityHeaderValue>(mediaTypeWithQualityHeaderValueOutUnmarshaled.Get());
    return (BOOL)unmarshalledReturn;
}

- (NSString*)charSet {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_CharSet(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCharSet:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->put_CharSet(nsStrToHstr(value).Get()));
}

- (NSString*)mediaType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setMediaType:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->put_MediaType(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* WWHHHttpNameValueHeaderValue* */)parameters {
    ComPtr<IVector<ABI::Windows::Web::Http::Headers::HttpNameValueHeaderValue*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Parameters(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WWHHHttpNameValueHeaderValue_create(unmarshalledReturn.Get());
}

- (id /* double */)quality {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Quality(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (void)setQuality:(id /* double */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->put_Quality(BuildNullable<double>(value)));
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpProductHeaderValue

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpProductHeaderValue> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Web::Http::Headers::IHttpProductHeaderValueFactory> WWHHIHttpProductHeaderValueFactory_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpProductHeaderValueFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.Headers.HttpProductHeaderValue").Get(),
                                                       &inst));
    return inst;
}

+ (WWHHHttpProductHeaderValue*)makeFromName:(NSString*)productName {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpProductHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpProductHeaderValueFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromName(nsStrToHstr(productName).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHHttpProductHeaderValue>(unmarshalledReturn.Get()) retain];
}

+ (WWHHHttpProductHeaderValue*)makeFromNameWithVersion:(NSString*)productName productVersion:(NSString*)productVersion {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpProductHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpProductHeaderValueFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromNameWithVersion(nsStrToHstr(productName).Get(),
                                                           nsStrToHstr(productVersion).Get(),
                                                           unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHHttpProductHeaderValue>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Web::Http::Headers::IHttpProductHeaderValueStatics> WWHHIHttpProductHeaderValueStatics_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpProductHeaderValueStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.Headers.HttpProductHeaderValue").Get(),
                                                       &inst));
    return inst;
}

+ (WWHHHttpProductHeaderValue*)parse:(NSString*)input {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpProductHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpProductHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Parse(nsStrToHstr(input).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpProductHeaderValue>(unmarshalledReturn.Get());
}

+ (BOOL)tryParse:(NSString*)input productHeaderValue:(WWHHHttpProductHeaderValue**)productHeaderValue {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpProductHeaderValue> productHeaderValueOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = WWHHIHttpProductHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TryParse(nsStrToHstr(input).Get(), productHeaderValueOutUnmarshaled.GetAddressOf(), &unmarshalledReturn));
    *productHeaderValue = _createRtProxy<WWHHHttpProductHeaderValue>(productHeaderValueOutUnmarshaled.Get());
    return (BOOL)unmarshalledReturn;
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpProductHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)Version {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpProductHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Version(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpProductInfoHeaderValue

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpProductInfoHeaderValue> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Web::Http::Headers::IHttpProductInfoHeaderValueFactory> WWHHIHttpProductInfoHeaderValueFactory_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpProductInfoHeaderValueFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.Headers.HttpProductInfoHeaderValue").Get(),
                                                       &inst));
    return inst;
}

+ (WWHHHttpProductInfoHeaderValue*)makeFromComment:(NSString*)productComment {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpProductInfoHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpProductInfoHeaderValueFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromComment(nsStrToHstr(productComment).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHHttpProductInfoHeaderValue>(unmarshalledReturn.Get()) retain];
}

+ (WWHHHttpProductInfoHeaderValue*)makeFromNameWithVersion:(NSString*)productName productVersion:(NSString*)productVersion {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpProductInfoHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpProductInfoHeaderValueFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromNameWithVersion(nsStrToHstr(productName).Get(),
                                                           nsStrToHstr(productVersion).Get(),
                                                           unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHHttpProductInfoHeaderValue>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Web::Http::Headers::IHttpProductInfoHeaderValueStatics> WWHHIHttpProductInfoHeaderValueStatics_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpProductInfoHeaderValueStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.Headers.HttpProductInfoHeaderValue").Get(),
                                                       &inst));
    return inst;
}

+ (WWHHHttpProductInfoHeaderValue*)parse:(NSString*)input {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpProductInfoHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpProductInfoHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Parse(nsStrToHstr(input).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpProductInfoHeaderValue>(unmarshalledReturn.Get());
}

+ (BOOL)tryParse:(NSString*)input productInfoHeaderValue:(WWHHHttpProductInfoHeaderValue**)productInfoHeaderValue {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpProductInfoHeaderValue> productInfoHeaderValueOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = WWHHIHttpProductInfoHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->TryParse(nsStrToHstr(input).Get(), productInfoHeaderValueOutUnmarshaled.GetAddressOf(), &unmarshalledReturn));
    *productInfoHeaderValue = _createRtProxy<WWHHHttpProductInfoHeaderValue>(productInfoHeaderValueOutUnmarshaled.Get());
    return (BOOL)unmarshalledReturn;
}

- (WWHHHttpProductHeaderValue*)product {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpProductHeaderValue> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpProductInfoHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Product(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpProductHeaderValue>(unmarshalledReturn.Get());
}

- (NSString*)comment {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpProductInfoHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Comment(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpContentCodingWithQualityHeaderValue

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValue> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValueFactory>
WWHHIHttpContentCodingWithQualityHeaderValueFactory_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValueFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Web.Http.Headers.HttpContentCodingWithQualityHeaderValue").Get(), &inst));
    return inst;
}

+ (WWHHHttpContentCodingWithQualityHeaderValue*)makeFromValue:(NSString*)contentCoding {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpContentCodingWithQualityHeaderValueFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromValue(nsStrToHstr(contentCoding).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHHttpContentCodingWithQualityHeaderValue>(unmarshalledReturn.Get()) retain];
}

+ (WWHHHttpContentCodingWithQualityHeaderValue*)makeFromValueWithQuality:(NSString*)contentCoding quality:(double)quality {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpContentCodingWithQualityHeaderValueFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromValueWithQuality(nsStrToHstr(contentCoding).Get(), quality, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHHttpContentCodingWithQualityHeaderValue>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValueStatics>
WWHHIHttpContentCodingWithQualityHeaderValueStatics_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValueStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Web.Http.Headers.HttpContentCodingWithQualityHeaderValue").Get(), &inst));
    return inst;
}

+ (WWHHHttpContentCodingWithQualityHeaderValue*)parse:(NSString*)input {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpContentCodingWithQualityHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Parse(nsStrToHstr(input).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpContentCodingWithQualityHeaderValue>(unmarshalledReturn.Get());
}

+ (BOOL)tryParse:(NSString*)input
    contentCodingWithQualityHeaderValue:(WWHHHttpContentCodingWithQualityHeaderValue**)contentCodingWithQualityHeaderValue {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValue> contentCodingWithQualityHeaderValueOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = WWHHIHttpContentCodingWithQualityHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TryParse(nsStrToHstr(input).Get(),
                                          contentCodingWithQualityHeaderValueOutUnmarshaled.GetAddressOf(),
                                          &unmarshalledReturn));
    *contentCodingWithQualityHeaderValue =
        _createRtProxy<WWHHHttpContentCodingWithQualityHeaderValue>(contentCodingWithQualityHeaderValueOutUnmarshaled.Get());
    return (BOOL)unmarshalledReturn;
}

- (NSString*)contentCoding {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentCoding(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (id /* double */)quality {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Quality(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHHttpTransferCodingHeaderValue

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpTransferCodingHeaderValue> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Web::Http::Headers::IHttpTransferCodingHeaderValueFactory> WWHHIHttpTransferCodingHeaderValueFactory_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpTransferCodingHeaderValueFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Web.Http.Headers.HttpTransferCodingHeaderValue").Get(), &inst));
    return inst;
}

+ (WWHHHttpTransferCodingHeaderValue*)make:(NSString*)input {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpTransferCodingHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpTransferCodingHeaderValueFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(input).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHHttpTransferCodingHeaderValue>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Web::Http::Headers::IHttpTransferCodingHeaderValueStatics> WWHHIHttpTransferCodingHeaderValueStatics_inst() {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpTransferCodingHeaderValueStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Web.Http.Headers.HttpTransferCodingHeaderValue").Get(), &inst));
    return inst;
}

+ (WWHHHttpTransferCodingHeaderValue*)parse:(NSString*)input {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpTransferCodingHeaderValue> unmarshalledReturn;
    auto _comInst = WWHHIHttpTransferCodingHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Parse(nsStrToHstr(input).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpTransferCodingHeaderValue>(unmarshalledReturn.Get());
}

+ (BOOL)tryParse:(NSString*)input transferCodingHeaderValue:(WWHHHttpTransferCodingHeaderValue**)transferCodingHeaderValue {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpTransferCodingHeaderValue> transferCodingHeaderValueOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = WWHHIHttpTransferCodingHeaderValueStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->TryParse(nsStrToHstr(input).Get(), transferCodingHeaderValueOutUnmarshaled.GetAddressOf(), &unmarshalledReturn));
    *transferCodingHeaderValue = _createRtProxy<WWHHHttpTransferCodingHeaderValue>(transferCodingHeaderValueOutUnmarshaled.Get());
    return (BOOL)unmarshalledReturn;
}

- (NSMutableArray* /* WWHHHttpNameValueHeaderValue* */)parameters {
    ComPtr<IVector<ABI::Windows::Web::Http::Headers::HttpNameValueHeaderValue*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpTransferCodingHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Parameters(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WWHHHttpNameValueHeaderValue_create(unmarshalledReturn.Get());
}

- (NSString*)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Headers::IHttpTransferCodingHeaderValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

id RTProxiedNSMutableArray_WWHHHttpNameValueHeaderValue_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Web::Http::Headers::HttpNameValueHeaderValue*>,
                                                RTMutableArrayObj<ABI::Windows::Web::Http::Headers::IHttpNameValueHeaderValue*,
                                                                  IVector<ABI::Windows::Web::Http::Headers::HttpNameValueHeaderValue*>,
                                                                  WWHHHttpNameValueHeaderValue,
                                                                  ABI::Windows::Web::Http::Headers::HttpNameValueHeaderValue*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
