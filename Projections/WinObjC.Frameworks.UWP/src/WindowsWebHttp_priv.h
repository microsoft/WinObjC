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

// WindowsWebHttp_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsNetworkingSockets_priv.h"
#include "WindowsSecurityCryptographyCertificates_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsWebHttpFilters_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsWebHttpHeaders_priv.h"
static ComPtr<ABI::Windows::Web::Http::IHttpRequestMessageFactory> WWHIHttpRequestMessageFactory_inst();
static ComPtr<ABI::Windows::Web::Http::IHttpResponseMessageFactory> WWHIHttpResponseMessageFactory_inst();
static ComPtr<ABI::Windows::Web::Http::IHttpClientFactory> WWHIHttpClientFactory_inst();
static ComPtr<ABI::Windows::Web::Http::IHttpCookieFactory> WWHIHttpCookieFactory_inst();
static ComPtr<ABI::Windows::Web::Http::IHttpMethodFactory> WWHIHttpMethodFactory_inst();
ComPtr<ABI::Windows::Web::Http::IHttpMethodStatics> WWHIHttpMethodStatics_inst();
static ComPtr<ABI::Windows::Web::Http::IHttpStringContentFactory> WWHIHttpStringContentFactory_inst();
static ComPtr<ABI::Windows::Web::Http::IHttpBufferContentFactory> WWHIHttpBufferContentFactory_inst();
static ComPtr<ABI::Windows::Web::Http::IHttpStreamContentFactory> WWHIHttpStreamContentFactory_inst();
static ComPtr<ABI::Windows::Web::Http::IHttpFormUrlEncodedContentFactory> WWHIHttpFormUrlEncodedContentFactory_inst();
static ComPtr<ABI::Windows::Web::Http::IHttpMultipartContentFactory> WWHIHttpMultipartContentFactory_inst();
static ComPtr<ABI::Windows::Web::Http::IHttpMultipartFormDataContentFactory> WWHIHttpMultipartFormDataContentFactory_inst();
@interface WWHHttpProgress (Internal)
+ (instancetype)createWith:(ABI::Windows::Web::Http::HttpProgress)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Web::Http::HttpProgress*)internalStruct;
@end
inline WWHHttpProgress* WWHHttpProgress_create(ABI::Windows::Web::Http::HttpProgress val) {
    return [WWHHttpProgress createWith:val];
}

id RTProxiedIterableNSArray_RTProxiedKeyValuePair_NSString_NSString_create(IInspectable* val);
id RTProxiedKeyValuePair_NSString_NSString_create(IInspectable* val);
id RTProxiedNSArray_WSCCCertificate_create(IInspectable* val);
id RTProxiedNSArray_WSCCChainValidationResult_create(IInspectable* val);
id RTProxiedNSMutableDictionary_NSString_RTObject_create(IInspectable* val);

@class Nullable_UInt64, Nullable_WFDateTime, RTProxiedIterableNSArray_RTProxiedKeyValuePair_NSString_NSString,
    RTProxiedKeyValuePair_NSString_NSString;
@class RTProxiedNSArray_WSCCCertificate, RTProxiedNSArray_WSCCChainValidationResult, RTProxiedNSMutableDictionary_NSString_RTObject;

typedef IKeyValuePair<HSTRING, HSTRING>* IKeyValuePair_HSTRING_HSTRING_Ptr;
