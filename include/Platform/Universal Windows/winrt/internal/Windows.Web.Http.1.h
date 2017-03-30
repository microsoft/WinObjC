// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Web.Http.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Networking.Sockets.0.h"
#include "Windows.Security.Cryptography.Certificates.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Web.Http.Filters.0.h"
#include "Windows.Web.Http.Headers.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Storage.Streams.1.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Security.Cryptography.Certificates.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Web::Http {

struct HttpProgress
{
    winrt::Windows::Web::Http::HttpProgressStage Stage;
    uint64_t BytesSent;
    Windows::Foundation::IReference<uint64_t> * TotalBytesToSend;
    uint64_t BytesReceived;
    Windows::Foundation::IReference<uint64_t> * TotalBytesToReceive;
    uint32_t Retries;
};

}

namespace Windows::Web::Http {

struct HttpProgress
{
    Windows::Web::Http::HttpProgressStage Stage;
    uint64_t BytesSent;
    Windows::Foundation::IReference<uint64_t> TotalBytesToSend;
    uint64_t BytesReceived;
    Windows::Foundation::IReference<uint64_t> TotalBytesToReceive;
    uint32_t Retries;
};

}

namespace impl {

template <> struct traits<Windows::Web::Http::HttpProgress>
{
    using abi = ABI::Windows::Web::Http::HttpProgress;
};

}

namespace ABI::Windows::Web::Http {

struct __declspec(uuid("bc20c193-c41f-4ff7-9123-6435736eadc2")) __declspec(novtable) IHttpBufferContentFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateFromBuffer(Windows::Storage::Streams::IBuffer * content, Windows::Web::Http::IHttpContent ** bufferContent) = 0;
    virtual HRESULT __stdcall abi_CreateFromBufferWithOffset(Windows::Storage::Streams::IBuffer * content, uint32_t offset, uint32_t count, Windows::Web::Http::IHttpContent ** bufferContent) = 0;
};

struct __declspec(uuid("7fda1151-3574-4880-a8ba-e6b1e0061f3d")) __declspec(novtable) IHttpClient : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_DeleteAsync(Windows::Foundation::IUriRuntimeClass * uri, Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetAsync(Windows::Foundation::IUriRuntimeClass * uri, Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetWithOptionAsync(Windows::Foundation::IUriRuntimeClass * uri, winrt::Windows::Web::Http::HttpCompletionOption completionOption, Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetBufferAsync(Windows::Foundation::IUriRuntimeClass * uri, Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IBuffer, Windows::Web::Http::HttpProgress> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetInputStreamAsync(Windows::Foundation::IUriRuntimeClass * uri, Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IInputStream, Windows::Web::Http::HttpProgress> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetStringAsync(Windows::Foundation::IUriRuntimeClass * uri, Windows::Foundation::IAsyncOperationWithProgress<hstring, Windows::Web::Http::HttpProgress> ** operation) = 0;
    virtual HRESULT __stdcall abi_PostAsync(Windows::Foundation::IUriRuntimeClass * uri, Windows::Web::Http::IHttpContent * content, Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> ** operation) = 0;
    virtual HRESULT __stdcall abi_PutAsync(Windows::Foundation::IUriRuntimeClass * uri, Windows::Web::Http::IHttpContent * content, Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> ** operation) = 0;
    virtual HRESULT __stdcall abi_SendRequestAsync(Windows::Web::Http::IHttpRequestMessage * request, Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> ** operation) = 0;
    virtual HRESULT __stdcall abi_SendRequestWithOptionAsync(Windows::Web::Http::IHttpRequestMessage * request, winrt::Windows::Web::Http::HttpCompletionOption completionOption, Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> ** operation) = 0;
    virtual HRESULT __stdcall get_DefaultRequestHeaders(Windows::Web::Http::Headers::IHttpRequestHeaderCollection ** value) = 0;
};

struct __declspec(uuid("c30c4eca-e3fa-4f99-afb4-63cc65009462")) __declspec(novtable) IHttpClientFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Web::Http::Filters::IHttpFilter * filter, Windows::Web::Http::IHttpClient ** client) = 0;
};

struct __declspec(uuid("6b14a441-fba7-4bd2-af0a-839de7c295da")) __declspec(novtable) IHttpContent : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Headers(Windows::Web::Http::Headers::IHttpContentHeaderCollection ** value) = 0;
    virtual HRESULT __stdcall abi_BufferAllAsync(Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t> ** operation) = 0;
    virtual HRESULT __stdcall abi_ReadAsBufferAsync(Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IBuffer, uint64_t> ** operation) = 0;
    virtual HRESULT __stdcall abi_ReadAsInputStreamAsync(Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IInputStream, uint64_t> ** operation) = 0;
    virtual HRESULT __stdcall abi_ReadAsStringAsync(Windows::Foundation::IAsyncOperationWithProgress<hstring, uint64_t> ** operation) = 0;
    virtual HRESULT __stdcall abi_TryComputeLength(uint64_t * length, bool * succeeded) = 0;
    virtual HRESULT __stdcall abi_WriteToStreamAsync(Windows::Storage::Streams::IOutputStream * outputStream, Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t> ** operation) = 0;
};

struct __declspec(uuid("1f5488e2-cc2d-4779-86a7-88f10687d249")) __declspec(novtable) IHttpCookie : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall get_Domain(hstring * value) = 0;
    virtual HRESULT __stdcall get_Path(hstring * value) = 0;
    virtual HRESULT __stdcall get_Expires(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall put_Expires(Windows::Foundation::IReference<Windows::Foundation::DateTime> * value) = 0;
    virtual HRESULT __stdcall get_HttpOnly(bool * value) = 0;
    virtual HRESULT __stdcall put_HttpOnly(bool value) = 0;
    virtual HRESULT __stdcall get_Secure(bool * value) = 0;
    virtual HRESULT __stdcall put_Secure(bool value) = 0;
    virtual HRESULT __stdcall get_Value(hstring * value) = 0;
    virtual HRESULT __stdcall put_Value(hstring value) = 0;
};

struct __declspec(uuid("6a0585a9-931c-4cd1-a96d-c21701785c5f")) __declspec(novtable) IHttpCookieFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring name, hstring domain, hstring path, Windows::Web::Http::IHttpCookie ** cookie) = 0;
};

struct __declspec(uuid("7a431780-cd4f-4e57-a84a-5b0a53d6bb96")) __declspec(novtable) IHttpCookieManager : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SetCookie(Windows::Web::Http::IHttpCookie * cookie, bool * replaced) = 0;
    virtual HRESULT __stdcall abi_SetCookieWithThirdParty(Windows::Web::Http::IHttpCookie * cookie, bool thirdParty, bool * replaced) = 0;
    virtual HRESULT __stdcall abi_DeleteCookie(Windows::Web::Http::IHttpCookie * cookie) = 0;
    virtual HRESULT __stdcall abi_GetCookies(Windows::Foundation::IUriRuntimeClass * uri, Windows::Foundation::Collections::IVectorView<Windows::Web::Http::HttpCookie> ** value) = 0;
};

struct __declspec(uuid("43f0138c-2f73-4302-b5f3-eae9238a5e01")) __declspec(novtable) IHttpFormUrlEncodedContentFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>> * content, Windows::Web::Http::IHttpContent ** formUrlEncodedContent) = 0;
};

struct __declspec(uuid("728d4022-700d-4fe0-afa5-40299c58dbfd")) __declspec(novtable) IHttpMethod : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Method(hstring * value) = 0;
};

struct __declspec(uuid("3c51d10d-36d7-40f8-a86d-e759caf2f83f")) __declspec(novtable) IHttpMethodFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring method, Windows::Web::Http::IHttpMethod ** httpMethod) = 0;
};

struct __declspec(uuid("64d171f0-d99a-4153-8dc6-d68cc4cce317")) __declspec(novtable) IHttpMethodStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Delete(Windows::Web::Http::IHttpMethod ** value) = 0;
    virtual HRESULT __stdcall get_Get(Windows::Web::Http::IHttpMethod ** value) = 0;
    virtual HRESULT __stdcall get_Head(Windows::Web::Http::IHttpMethod ** value) = 0;
    virtual HRESULT __stdcall get_Options(Windows::Web::Http::IHttpMethod ** value) = 0;
    virtual HRESULT __stdcall get_Patch(Windows::Web::Http::IHttpMethod ** value) = 0;
    virtual HRESULT __stdcall get_Post(Windows::Web::Http::IHttpMethod ** value) = 0;
    virtual HRESULT __stdcall get_Put(Windows::Web::Http::IHttpMethod ** value) = 0;
};

struct __declspec(uuid("df916aff-9926-4ac9-aaf1-e0d04ef09bb9")) __declspec(novtable) IHttpMultipartContent : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Add(Windows::Web::Http::IHttpContent * content) = 0;
};

struct __declspec(uuid("7eb42e62-0222-4f20-b372-47d5db5d33b4")) __declspec(novtable) IHttpMultipartContentFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateWithSubtype(hstring subtype, Windows::Web::Http::IHttpContent ** multipartContent) = 0;
    virtual HRESULT __stdcall abi_CreateWithSubtypeAndBoundary(hstring subtype, hstring boundary, Windows::Web::Http::IHttpContent ** multipartContent) = 0;
};

struct __declspec(uuid("64d337e2-e967-4624-b6d1-cf74604a4a42")) __declspec(novtable) IHttpMultipartFormDataContent : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Add(Windows::Web::Http::IHttpContent * content) = 0;
    virtual HRESULT __stdcall abi_AddWithName(Windows::Web::Http::IHttpContent * content, hstring name) = 0;
    virtual HRESULT __stdcall abi_AddWithNameAndFileName(Windows::Web::Http::IHttpContent * content, hstring name, hstring fileName) = 0;
};

struct __declspec(uuid("a04d7311-5017-4622-93a8-49b24a4fcbfc")) __declspec(novtable) IHttpMultipartFormDataContentFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateWithBoundary(hstring boundary, Windows::Web::Http::IHttpContent ** multipartFormDataContent) = 0;
};

struct __declspec(uuid("f5762b3c-74d4-4811-b5dc-9f8b4e2f9abf")) __declspec(novtable) IHttpRequestMessage : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Content(Windows::Web::Http::IHttpContent ** value) = 0;
    virtual HRESULT __stdcall put_Content(Windows::Web::Http::IHttpContent * value) = 0;
    virtual HRESULT __stdcall get_Headers(Windows::Web::Http::Headers::IHttpRequestHeaderCollection ** value) = 0;
    virtual HRESULT __stdcall get_Method(Windows::Web::Http::IHttpMethod ** value) = 0;
    virtual HRESULT __stdcall put_Method(Windows::Web::Http::IHttpMethod * value) = 0;
    virtual HRESULT __stdcall get_Properties(Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable> ** value) = 0;
    virtual HRESULT __stdcall get_RequestUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall put_RequestUri(Windows::Foundation::IUriRuntimeClass * value) = 0;
    virtual HRESULT __stdcall get_TransportInformation(Windows::Web::Http::IHttpTransportInformation ** value) = 0;
};

struct __declspec(uuid("5bac994e-3886-412e-aec3-52ec7f25616f")) __declspec(novtable) IHttpRequestMessageFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Web::Http::IHttpMethod * method, Windows::Foundation::IUriRuntimeClass * uri, Windows::Web::Http::IHttpRequestMessage ** httpRequestMessage) = 0;
};

struct __declspec(uuid("fee200fb-8664-44e0-95d9-42696199bffc")) __declspec(novtable) IHttpResponseMessage : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Content(Windows::Web::Http::IHttpContent ** value) = 0;
    virtual HRESULT __stdcall put_Content(Windows::Web::Http::IHttpContent * value) = 0;
    virtual HRESULT __stdcall get_Headers(Windows::Web::Http::Headers::IHttpResponseHeaderCollection ** value) = 0;
    virtual HRESULT __stdcall get_IsSuccessStatusCode(bool * value) = 0;
    virtual HRESULT __stdcall get_ReasonPhrase(hstring * value) = 0;
    virtual HRESULT __stdcall put_ReasonPhrase(hstring value) = 0;
    virtual HRESULT __stdcall get_RequestMessage(Windows::Web::Http::IHttpRequestMessage ** value) = 0;
    virtual HRESULT __stdcall put_RequestMessage(Windows::Web::Http::IHttpRequestMessage * value) = 0;
    virtual HRESULT __stdcall get_Source(winrt::Windows::Web::Http::HttpResponseMessageSource * value) = 0;
    virtual HRESULT __stdcall put_Source(winrt::Windows::Web::Http::HttpResponseMessageSource value) = 0;
    virtual HRESULT __stdcall get_StatusCode(winrt::Windows::Web::Http::HttpStatusCode * value) = 0;
    virtual HRESULT __stdcall put_StatusCode(winrt::Windows::Web::Http::HttpStatusCode value) = 0;
    virtual HRESULT __stdcall get_Version(winrt::Windows::Web::Http::HttpVersion * value) = 0;
    virtual HRESULT __stdcall put_Version(winrt::Windows::Web::Http::HttpVersion value) = 0;
    virtual HRESULT __stdcall abi_EnsureSuccessStatusCode(Windows::Web::Http::IHttpResponseMessage ** httpResponseMessage) = 0;
};

struct __declspec(uuid("52a8af99-f095-43da-b60f-7cfc2bc7ea2f")) __declspec(novtable) IHttpResponseMessageFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(winrt::Windows::Web::Http::HttpStatusCode statusCode, Windows::Web::Http::IHttpResponseMessage ** httpResponseMessage) = 0;
};

struct __declspec(uuid("f3e64d9d-f725-407e-942f-0eda189809f4")) __declspec(novtable) IHttpStreamContentFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateFromInputStream(Windows::Storage::Streams::IInputStream * content, Windows::Web::Http::IHttpContent ** streamContent) = 0;
};

struct __declspec(uuid("46649d5b-2e93-48eb-8e61-19677878e57f")) __declspec(novtable) IHttpStringContentFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateFromString(hstring content, Windows::Web::Http::IHttpContent ** stringContent) = 0;
    virtual HRESULT __stdcall abi_CreateFromStringWithEncoding(hstring content, winrt::Windows::Storage::Streams::UnicodeEncoding encoding, Windows::Web::Http::IHttpContent ** stringContent) = 0;
    virtual HRESULT __stdcall abi_CreateFromStringWithEncodingAndMediaType(hstring content, winrt::Windows::Storage::Streams::UnicodeEncoding encoding, hstring mediaType, Windows::Web::Http::IHttpContent ** stringContent) = 0;
};

struct __declspec(uuid("70127198-c6a7-4ed0-833a-83fd8b8f178d")) __declspec(novtable) IHttpTransportInformation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ServerCertificate(Windows::Security::Cryptography::Certificates::ICertificate ** value) = 0;
    virtual HRESULT __stdcall get_ServerCertificateErrorSeverity(winrt::Windows::Networking::Sockets::SocketSslErrorSeverity * value) = 0;
    virtual HRESULT __stdcall get_ServerCertificateErrors(Windows::Foundation::Collections::IVectorView<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> ** value) = 0;
    virtual HRESULT __stdcall get_ServerIntermediateCertificates(Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> ** value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Web::Http::HttpBufferContent> { using default_interface = Windows::Web::Http::IHttpContent; };
template <> struct traits<Windows::Web::Http::HttpClient> { using default_interface = Windows::Web::Http::IHttpClient; };
template <> struct traits<Windows::Web::Http::HttpCookie> { using default_interface = Windows::Web::Http::IHttpCookie; };
template <> struct traits<Windows::Web::Http::HttpCookieCollection> { using default_interface = Windows::Foundation::Collections::IVectorView<Windows::Web::Http::HttpCookie>; };
template <> struct traits<Windows::Web::Http::HttpCookieManager> { using default_interface = Windows::Web::Http::IHttpCookieManager; };
template <> struct traits<Windows::Web::Http::HttpFormUrlEncodedContent> { using default_interface = Windows::Web::Http::IHttpContent; };
template <> struct traits<Windows::Web::Http::HttpMethod> { using default_interface = Windows::Web::Http::IHttpMethod; };
template <> struct traits<Windows::Web::Http::HttpMultipartContent> { using default_interface = Windows::Web::Http::IHttpContent; };
template <> struct traits<Windows::Web::Http::HttpMultipartFormDataContent> { using default_interface = Windows::Web::Http::IHttpContent; };
template <> struct traits<Windows::Web::Http::HttpRequestMessage> { using default_interface = Windows::Web::Http::IHttpRequestMessage; };
template <> struct traits<Windows::Web::Http::HttpResponseMessage> { using default_interface = Windows::Web::Http::IHttpResponseMessage; };
template <> struct traits<Windows::Web::Http::HttpStreamContent> { using default_interface = Windows::Web::Http::IHttpContent; };
template <> struct traits<Windows::Web::Http::HttpStringContent> { using default_interface = Windows::Web::Http::IHttpContent; };
template <> struct traits<Windows::Web::Http::HttpTransportInformation> { using default_interface = Windows::Web::Http::IHttpTransportInformation; };

}

namespace Windows::Web::Http {

template <typename D>
struct WINRT_EBO impl_IHttpBufferContentFactory
{
    Windows::Web::Http::HttpBufferContent CreateFromBuffer(const Windows::Storage::Streams::IBuffer & content) const;
    Windows::Web::Http::HttpBufferContent CreateFromBufferWithOffset(const Windows::Storage::Streams::IBuffer & content, uint32_t offset, uint32_t count) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpClient
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> DeleteAsync(const Windows::Foundation::Uri & uri) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> GetAsync(const Windows::Foundation::Uri & uri) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> GetAsync(const Windows::Foundation::Uri & uri, Windows::Web::Http::HttpCompletionOption completionOption) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IBuffer, Windows::Web::Http::HttpProgress> GetBufferAsync(const Windows::Foundation::Uri & uri) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IInputStream, Windows::Web::Http::HttpProgress> GetInputStreamAsync(const Windows::Foundation::Uri & uri) const;
    Windows::Foundation::IAsyncOperationWithProgress<hstring, Windows::Web::Http::HttpProgress> GetStringAsync(const Windows::Foundation::Uri & uri) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> PostAsync(const Windows::Foundation::Uri & uri, const Windows::Web::Http::IHttpContent & content) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> PutAsync(const Windows::Foundation::Uri & uri, const Windows::Web::Http::IHttpContent & content) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> SendRequestAsync(const Windows::Web::Http::HttpRequestMessage & request) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> SendRequestAsync(const Windows::Web::Http::HttpRequestMessage & request, Windows::Web::Http::HttpCompletionOption completionOption) const;
    Windows::Web::Http::Headers::HttpRequestHeaderCollection DefaultRequestHeaders() const;
};

template <typename D>
struct WINRT_EBO impl_IHttpClientFactory
{
    Windows::Web::Http::HttpClient Create(const Windows::Web::Http::Filters::IHttpFilter & filter) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpContent
{
    Windows::Web::Http::Headers::HttpContentHeaderCollection Headers() const;
    Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t> BufferAllAsync() const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IBuffer, uint64_t> ReadAsBufferAsync() const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IInputStream, uint64_t> ReadAsInputStreamAsync() const;
    Windows::Foundation::IAsyncOperationWithProgress<hstring, uint64_t> ReadAsStringAsync() const;
    bool TryComputeLength(uint64_t & length) const;
    Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t> WriteToStreamAsync(const Windows::Storage::Streams::IOutputStream & outputStream) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpCookie
{
    hstring Name() const;
    hstring Domain() const;
    hstring Path() const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> Expires() const;
    void Expires(const optional<Windows::Foundation::DateTime> & value) const;
    bool HttpOnly() const;
    void HttpOnly(bool value) const;
    bool Secure() const;
    void Secure(bool value) const;
    hstring Value() const;
    void Value(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpCookieFactory
{
    Windows::Web::Http::HttpCookie Create(hstring_view name, hstring_view domain, hstring_view path) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpCookieManager
{
    bool SetCookie(const Windows::Web::Http::HttpCookie & cookie) const;
    bool SetCookie(const Windows::Web::Http::HttpCookie & cookie, bool thirdParty) const;
    void DeleteCookie(const Windows::Web::Http::HttpCookie & cookie) const;
    Windows::Web::Http::HttpCookieCollection GetCookies(const Windows::Foundation::Uri & uri) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpFormUrlEncodedContentFactory
{
    Windows::Web::Http::HttpFormUrlEncodedContent Create(iterable<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>> content) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpMethod
{
    hstring Method() const;
};

template <typename D>
struct WINRT_EBO impl_IHttpMethodFactory
{
    Windows::Web::Http::HttpMethod Create(hstring_view method) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpMethodStatics
{
    Windows::Web::Http::HttpMethod Delete() const;
    Windows::Web::Http::HttpMethod Get() const;
    Windows::Web::Http::HttpMethod Head() const;
    Windows::Web::Http::HttpMethod Options() const;
    Windows::Web::Http::HttpMethod Patch() const;
    Windows::Web::Http::HttpMethod Post() const;
    Windows::Web::Http::HttpMethod Put() const;
};

template <typename D>
struct WINRT_EBO impl_IHttpMultipartContent
{
    void Add(const Windows::Web::Http::IHttpContent & content) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpMultipartContentFactory
{
    Windows::Web::Http::HttpMultipartContent CreateWithSubtype(hstring_view subtype) const;
    Windows::Web::Http::HttpMultipartContent CreateWithSubtypeAndBoundary(hstring_view subtype, hstring_view boundary) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpMultipartFormDataContent
{
    void Add(const Windows::Web::Http::IHttpContent & content) const;
    void Add(const Windows::Web::Http::IHttpContent & content, hstring_view name) const;
    void Add(const Windows::Web::Http::IHttpContent & content, hstring_view name, hstring_view fileName) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpMultipartFormDataContentFactory
{
    Windows::Web::Http::HttpMultipartFormDataContent CreateWithBoundary(hstring_view boundary) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpRequestMessage
{
    Windows::Web::Http::IHttpContent Content() const;
    void Content(const Windows::Web::Http::IHttpContent & value) const;
    Windows::Web::Http::Headers::HttpRequestHeaderCollection Headers() const;
    Windows::Web::Http::HttpMethod Method() const;
    void Method(const Windows::Web::Http::HttpMethod & value) const;
    Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable> Properties() const;
    Windows::Foundation::Uri RequestUri() const;
    void RequestUri(const Windows::Foundation::Uri & value) const;
    Windows::Web::Http::HttpTransportInformation TransportInformation() const;
};

template <typename D>
struct WINRT_EBO impl_IHttpRequestMessageFactory
{
    Windows::Web::Http::HttpRequestMessage Create(const Windows::Web::Http::HttpMethod & method, const Windows::Foundation::Uri & uri) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpResponseMessage
{
    Windows::Web::Http::IHttpContent Content() const;
    void Content(const Windows::Web::Http::IHttpContent & value) const;
    Windows::Web::Http::Headers::HttpResponseHeaderCollection Headers() const;
    bool IsSuccessStatusCode() const;
    hstring ReasonPhrase() const;
    void ReasonPhrase(hstring_view value) const;
    Windows::Web::Http::HttpRequestMessage RequestMessage() const;
    void RequestMessage(const Windows::Web::Http::HttpRequestMessage & value) const;
    Windows::Web::Http::HttpResponseMessageSource Source() const;
    void Source(Windows::Web::Http::HttpResponseMessageSource value) const;
    Windows::Web::Http::HttpStatusCode StatusCode() const;
    void StatusCode(Windows::Web::Http::HttpStatusCode value) const;
    Windows::Web::Http::HttpVersion Version() const;
    void Version(Windows::Web::Http::HttpVersion value) const;
    Windows::Web::Http::HttpResponseMessage EnsureSuccessStatusCode() const;
};

template <typename D>
struct WINRT_EBO impl_IHttpResponseMessageFactory
{
    Windows::Web::Http::HttpResponseMessage Create(Windows::Web::Http::HttpStatusCode statusCode) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpStreamContentFactory
{
    Windows::Web::Http::HttpStreamContent CreateFromInputStream(const Windows::Storage::Streams::IInputStream & content) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpStringContentFactory
{
    Windows::Web::Http::HttpStringContent CreateFromString(hstring_view content) const;
    Windows::Web::Http::HttpStringContent CreateFromStringWithEncoding(hstring_view content, Windows::Storage::Streams::UnicodeEncoding encoding) const;
    Windows::Web::Http::HttpStringContent CreateFromStringWithEncodingAndMediaType(hstring_view content, Windows::Storage::Streams::UnicodeEncoding encoding, hstring_view mediaType) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpTransportInformation
{
    Windows::Security::Cryptography::Certificates::Certificate ServerCertificate() const;
    Windows::Networking::Sockets::SocketSslErrorSeverity ServerCertificateErrorSeverity() const;
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> ServerCertificateErrors() const;
    Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> ServerIntermediateCertificates() const;
};

}

namespace impl {

template <> struct traits<Windows::Web::Http::IHttpBufferContentFactory>
{
    using abi = ABI::Windows::Web::Http::IHttpBufferContentFactory;
    template <typename D> using consume = Windows::Web::Http::impl_IHttpBufferContentFactory<D>;
};

template <> struct traits<Windows::Web::Http::IHttpClient>
{
    using abi = ABI::Windows::Web::Http::IHttpClient;
    template <typename D> using consume = Windows::Web::Http::impl_IHttpClient<D>;
};

template <> struct traits<Windows::Web::Http::IHttpClientFactory>
{
    using abi = ABI::Windows::Web::Http::IHttpClientFactory;
    template <typename D> using consume = Windows::Web::Http::impl_IHttpClientFactory<D>;
};

template <> struct traits<Windows::Web::Http::IHttpContent>
{
    using abi = ABI::Windows::Web::Http::IHttpContent;
    template <typename D> using consume = Windows::Web::Http::impl_IHttpContent<D>;
};

template <> struct traits<Windows::Web::Http::IHttpCookie>
{
    using abi = ABI::Windows::Web::Http::IHttpCookie;
    template <typename D> using consume = Windows::Web::Http::impl_IHttpCookie<D>;
};

template <> struct traits<Windows::Web::Http::IHttpCookieFactory>
{
    using abi = ABI::Windows::Web::Http::IHttpCookieFactory;
    template <typename D> using consume = Windows::Web::Http::impl_IHttpCookieFactory<D>;
};

template <> struct traits<Windows::Web::Http::IHttpCookieManager>
{
    using abi = ABI::Windows::Web::Http::IHttpCookieManager;
    template <typename D> using consume = Windows::Web::Http::impl_IHttpCookieManager<D>;
};

template <> struct traits<Windows::Web::Http::IHttpFormUrlEncodedContentFactory>
{
    using abi = ABI::Windows::Web::Http::IHttpFormUrlEncodedContentFactory;
    template <typename D> using consume = Windows::Web::Http::impl_IHttpFormUrlEncodedContentFactory<D>;
};

template <> struct traits<Windows::Web::Http::IHttpMethod>
{
    using abi = ABI::Windows::Web::Http::IHttpMethod;
    template <typename D> using consume = Windows::Web::Http::impl_IHttpMethod<D>;
};

template <> struct traits<Windows::Web::Http::IHttpMethodFactory>
{
    using abi = ABI::Windows::Web::Http::IHttpMethodFactory;
    template <typename D> using consume = Windows::Web::Http::impl_IHttpMethodFactory<D>;
};

template <> struct traits<Windows::Web::Http::IHttpMethodStatics>
{
    using abi = ABI::Windows::Web::Http::IHttpMethodStatics;
    template <typename D> using consume = Windows::Web::Http::impl_IHttpMethodStatics<D>;
};

template <> struct traits<Windows::Web::Http::IHttpMultipartContent>
{
    using abi = ABI::Windows::Web::Http::IHttpMultipartContent;
    template <typename D> using consume = Windows::Web::Http::impl_IHttpMultipartContent<D>;
};

template <> struct traits<Windows::Web::Http::IHttpMultipartContentFactory>
{
    using abi = ABI::Windows::Web::Http::IHttpMultipartContentFactory;
    template <typename D> using consume = Windows::Web::Http::impl_IHttpMultipartContentFactory<D>;
};

template <> struct traits<Windows::Web::Http::IHttpMultipartFormDataContent>
{
    using abi = ABI::Windows::Web::Http::IHttpMultipartFormDataContent;
    template <typename D> using consume = Windows::Web::Http::impl_IHttpMultipartFormDataContent<D>;
};

template <> struct traits<Windows::Web::Http::IHttpMultipartFormDataContentFactory>
{
    using abi = ABI::Windows::Web::Http::IHttpMultipartFormDataContentFactory;
    template <typename D> using consume = Windows::Web::Http::impl_IHttpMultipartFormDataContentFactory<D>;
};

template <> struct traits<Windows::Web::Http::IHttpRequestMessage>
{
    using abi = ABI::Windows::Web::Http::IHttpRequestMessage;
    template <typename D> using consume = Windows::Web::Http::impl_IHttpRequestMessage<D>;
};

template <> struct traits<Windows::Web::Http::IHttpRequestMessageFactory>
{
    using abi = ABI::Windows::Web::Http::IHttpRequestMessageFactory;
    template <typename D> using consume = Windows::Web::Http::impl_IHttpRequestMessageFactory<D>;
};

template <> struct traits<Windows::Web::Http::IHttpResponseMessage>
{
    using abi = ABI::Windows::Web::Http::IHttpResponseMessage;
    template <typename D> using consume = Windows::Web::Http::impl_IHttpResponseMessage<D>;
};

template <> struct traits<Windows::Web::Http::IHttpResponseMessageFactory>
{
    using abi = ABI::Windows::Web::Http::IHttpResponseMessageFactory;
    template <typename D> using consume = Windows::Web::Http::impl_IHttpResponseMessageFactory<D>;
};

template <> struct traits<Windows::Web::Http::IHttpStreamContentFactory>
{
    using abi = ABI::Windows::Web::Http::IHttpStreamContentFactory;
    template <typename D> using consume = Windows::Web::Http::impl_IHttpStreamContentFactory<D>;
};

template <> struct traits<Windows::Web::Http::IHttpStringContentFactory>
{
    using abi = ABI::Windows::Web::Http::IHttpStringContentFactory;
    template <typename D> using consume = Windows::Web::Http::impl_IHttpStringContentFactory<D>;
};

template <> struct traits<Windows::Web::Http::IHttpTransportInformation>
{
    using abi = ABI::Windows::Web::Http::IHttpTransportInformation;
    template <typename D> using consume = Windows::Web::Http::impl_IHttpTransportInformation<D>;
};

template <> struct traits<Windows::Web::Http::HttpBufferContent>
{
    using abi = ABI::Windows::Web::Http::HttpBufferContent;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.HttpBufferContent"; }
};

template <> struct traits<Windows::Web::Http::HttpClient>
{
    using abi = ABI::Windows::Web::Http::HttpClient;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.HttpClient"; }
};

template <> struct traits<Windows::Web::Http::HttpCookie>
{
    using abi = ABI::Windows::Web::Http::HttpCookie;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.HttpCookie"; }
};

template <> struct traits<Windows::Web::Http::HttpCookieCollection>
{
    using abi = ABI::Windows::Web::Http::HttpCookieCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.HttpCookieCollection"; }
};

template <> struct traits<Windows::Web::Http::HttpCookieManager>
{
    using abi = ABI::Windows::Web::Http::HttpCookieManager;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.HttpCookieManager"; }
};

template <> struct traits<Windows::Web::Http::HttpFormUrlEncodedContent>
{
    using abi = ABI::Windows::Web::Http::HttpFormUrlEncodedContent;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.HttpFormUrlEncodedContent"; }
};

template <> struct traits<Windows::Web::Http::HttpMethod>
{
    using abi = ABI::Windows::Web::Http::HttpMethod;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.HttpMethod"; }
};

template <> struct traits<Windows::Web::Http::HttpMultipartContent>
{
    using abi = ABI::Windows::Web::Http::HttpMultipartContent;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.HttpMultipartContent"; }
};

template <> struct traits<Windows::Web::Http::HttpMultipartFormDataContent>
{
    using abi = ABI::Windows::Web::Http::HttpMultipartFormDataContent;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.HttpMultipartFormDataContent"; }
};

template <> struct traits<Windows::Web::Http::HttpRequestMessage>
{
    using abi = ABI::Windows::Web::Http::HttpRequestMessage;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.HttpRequestMessage"; }
};

template <> struct traits<Windows::Web::Http::HttpResponseMessage>
{
    using abi = ABI::Windows::Web::Http::HttpResponseMessage;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.HttpResponseMessage"; }
};

template <> struct traits<Windows::Web::Http::HttpStreamContent>
{
    using abi = ABI::Windows::Web::Http::HttpStreamContent;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.HttpStreamContent"; }
};

template <> struct traits<Windows::Web::Http::HttpStringContent>
{
    using abi = ABI::Windows::Web::Http::HttpStringContent;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.HttpStringContent"; }
};

template <> struct traits<Windows::Web::Http::HttpTransportInformation>
{
    using abi = ABI::Windows::Web::Http::HttpTransportInformation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.HttpTransportInformation"; }
};

}

}
