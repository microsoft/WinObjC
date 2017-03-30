// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Web.Http.Headers.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Networking.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.Globalization.1.h"
#include "Windows.Web.Http.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Web::Http::Headers {

struct __declspec(uuid("9a586b89-d5d0-4fbe-bd9d-b5b3636811b4")) __declspec(novtable) IHttpCacheDirectiveHeaderValueCollection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MaxAge(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> ** value) = 0;
    virtual HRESULT __stdcall put_MaxAge(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> * value) = 0;
    virtual HRESULT __stdcall get_MaxStale(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> ** value) = 0;
    virtual HRESULT __stdcall put_MaxStale(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> * value) = 0;
    virtual HRESULT __stdcall get_MinFresh(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> ** value) = 0;
    virtual HRESULT __stdcall put_MinFresh(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> * value) = 0;
    virtual HRESULT __stdcall get_SharedMaxAge(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> ** value) = 0;
    virtual HRESULT __stdcall put_SharedMaxAge(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> * value) = 0;
    virtual HRESULT __stdcall abi_ParseAdd(hstring input) = 0;
    virtual HRESULT __stdcall abi_TryParseAdd(hstring input, bool * succeeded) = 0;
};

struct __declspec(uuid("393361af-0f7d-4820-9fdd-a2b956eeaeab")) __declspec(novtable) IHttpChallengeHeaderValue : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Parameters(Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue> ** value) = 0;
    virtual HRESULT __stdcall get_Scheme(hstring * value) = 0;
    virtual HRESULT __stdcall get_Token(hstring * value) = 0;
};

struct __declspec(uuid("ca9e5f81-aee0-4353-a10b-e625babd64c2")) __declspec(novtable) IHttpChallengeHeaderValueCollection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ParseAdd(hstring input) = 0;
    virtual HRESULT __stdcall abi_TryParseAdd(hstring input, bool * succeeded) = 0;
};

struct __declspec(uuid("c452c451-d99c-40aa-9399-90eeb98fc613")) __declspec(novtable) IHttpChallengeHeaderValueFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateFromScheme(hstring scheme, Windows::Web::Http::Headers::IHttpChallengeHeaderValue ** challengeHeaderValue) = 0;
    virtual HRESULT __stdcall abi_CreateFromSchemeWithToken(hstring scheme, hstring token, Windows::Web::Http::Headers::IHttpChallengeHeaderValue ** challengeHeaderValue) = 0;
};

struct __declspec(uuid("f3d38a72-fc01-4d01-a008-fcb7c459d635")) __declspec(novtable) IHttpChallengeHeaderValueStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Parse(hstring input, Windows::Web::Http::Headers::IHttpChallengeHeaderValue ** challengeHeaderValue) = 0;
    virtual HRESULT __stdcall abi_TryParse(hstring input, Windows::Web::Http::Headers::IHttpChallengeHeaderValue ** challengeHeaderValue, bool * succeeded) = 0;
};

struct __declspec(uuid("cb4af27a-4e90-45eb-8dcd-fd1408f4c44f")) __declspec(novtable) IHttpConnectionOptionHeaderValue : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Token(hstring * value) = 0;
};

struct __declspec(uuid("e4f56c1d-5142-4e00-8e0f-019509337629")) __declspec(novtable) IHttpConnectionOptionHeaderValueCollection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ParseAdd(hstring input) = 0;
    virtual HRESULT __stdcall abi_TryParseAdd(hstring input, bool * succeeded) = 0;
};

struct __declspec(uuid("d93ccc1e-0b7d-4c3f-a58d-a2a1bdeabc0a")) __declspec(novtable) IHttpConnectionOptionHeaderValueFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring token, Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValue ** connectionOptionHeaderValue) = 0;
};

struct __declspec(uuid("aaa75d37-a946-4b1f-85af-48b68b3c50bd")) __declspec(novtable) IHttpConnectionOptionHeaderValueStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Parse(hstring input, Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValue ** connectionOptionHeaderValue) = 0;
    virtual HRESULT __stdcall abi_TryParse(hstring input, Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValue ** connectionOptionHeaderValue, bool * succeeded) = 0;
};

struct __declspec(uuid("bcf7f92a-9376-4d85-bccc-9f4f9acab434")) __declspec(novtable) IHttpContentCodingHeaderValue : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ContentCoding(hstring * value) = 0;
};

struct __declspec(uuid("7d221721-a6db-436e-8e83-91596192819c")) __declspec(novtable) IHttpContentCodingHeaderValueCollection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ParseAdd(hstring input) = 0;
    virtual HRESULT __stdcall abi_TryParseAdd(hstring input, bool * succeeded) = 0;
};

struct __declspec(uuid("c53d2bd7-332b-4350-8510-2e67a2289a5a")) __declspec(novtable) IHttpContentCodingHeaderValueFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring contentCoding, Windows::Web::Http::Headers::IHttpContentCodingHeaderValue ** contentCodingHeaderValue) = 0;
};

struct __declspec(uuid("94d8602e-f9bf-42f7-aa46-ed272a41e212")) __declspec(novtable) IHttpContentCodingHeaderValueStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Parse(hstring input, Windows::Web::Http::Headers::IHttpContentCodingHeaderValue ** contentCodingHeaderValue) = 0;
    virtual HRESULT __stdcall abi_TryParse(hstring input, Windows::Web::Http::Headers::IHttpContentCodingHeaderValue ** contentCodingHeaderValue, bool * succeeded) = 0;
};

struct __declspec(uuid("94531cd5-8b13-4d73-8651-f76b38f88495")) __declspec(novtable) IHttpContentCodingWithQualityHeaderValue : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ContentCoding(hstring * value) = 0;
    virtual HRESULT __stdcall get_Quality(Windows::Foundation::IReference<double> ** value) = 0;
};

struct __declspec(uuid("7c0d753e-e899-4378-b5c8-412d820711cc")) __declspec(novtable) IHttpContentCodingWithQualityHeaderValueCollection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ParseAdd(hstring input) = 0;
    virtual HRESULT __stdcall abi_TryParseAdd(hstring input, bool * succeeded) = 0;
};

struct __declspec(uuid("c45eee1a-c553-46fc-ade2-d75c1d53df7b")) __declspec(novtable) IHttpContentCodingWithQualityHeaderValueFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateFromValue(hstring contentCoding, Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValue ** contentCodingWithQualityHeaderValue) = 0;
    virtual HRESULT __stdcall abi_CreateFromValueWithQuality(hstring contentCoding, double quality, Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValue ** contentCodingWithQualityHeaderValue) = 0;
};

struct __declspec(uuid("e8c9357c-8f89-4801-8e75-4c9abfc3de71")) __declspec(novtable) IHttpContentCodingWithQualityHeaderValueStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Parse(hstring input, Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValue ** contentCodingWithQualityHeaderValue) = 0;
    virtual HRESULT __stdcall abi_TryParse(hstring input, Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValue ** contentCodingWithQualityHeaderValue, bool * succeeded) = 0;
};

struct __declspec(uuid("f2a2eedc-2629-4b49-9908-96a168e9365e")) __declspec(novtable) IHttpContentDispositionHeaderValue : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DispositionType(hstring * value) = 0;
    virtual HRESULT __stdcall put_DispositionType(hstring value) = 0;
    virtual HRESULT __stdcall get_FileName(hstring * value) = 0;
    virtual HRESULT __stdcall put_FileName(hstring value) = 0;
    virtual HRESULT __stdcall get_FileNameStar(hstring * value) = 0;
    virtual HRESULT __stdcall put_FileNameStar(hstring value) = 0;
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall put_Name(hstring value) = 0;
    virtual HRESULT __stdcall get_Parameters(Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue> ** value) = 0;
    virtual HRESULT __stdcall get_Size(Windows::Foundation::IReference<uint64_t> ** value) = 0;
    virtual HRESULT __stdcall put_Size(Windows::Foundation::IReference<uint64_t> * value) = 0;
};

struct __declspec(uuid("9915bbc4-456c-4e81-8295-b2ab3cbcf545")) __declspec(novtable) IHttpContentDispositionHeaderValueFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring dispositionType, Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue ** contentDispositionHeaderValue) = 0;
};

struct __declspec(uuid("29c56067-5a37-46e4-b074-c5177d69ca66")) __declspec(novtable) IHttpContentDispositionHeaderValueStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Parse(hstring input, Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue ** contentDispositionHeaderValue) = 0;
    virtual HRESULT __stdcall abi_TryParse(hstring input, Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue ** contentDispositionHeaderValue, bool * succeeded) = 0;
};

struct __declspec(uuid("40612a44-47ae-4b7e-9124-69628b64aa18")) __declspec(novtable) IHttpContentHeaderCollection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ContentDisposition(Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue ** value) = 0;
    virtual HRESULT __stdcall put_ContentDisposition(Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue * value) = 0;
    virtual HRESULT __stdcall get_ContentEncoding(Windows::Web::Http::Headers::IHttpContentCodingHeaderValueCollection ** value) = 0;
    virtual HRESULT __stdcall get_ContentLanguage(Windows::Web::Http::Headers::IHttpLanguageHeaderValueCollection ** value) = 0;
    virtual HRESULT __stdcall get_ContentLength(Windows::Foundation::IReference<uint64_t> ** value) = 0;
    virtual HRESULT __stdcall put_ContentLength(Windows::Foundation::IReference<uint64_t> * value) = 0;
    virtual HRESULT __stdcall get_ContentLocation(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall put_ContentLocation(Windows::Foundation::IUriRuntimeClass * value) = 0;
    virtual HRESULT __stdcall get_ContentMD5(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall put_ContentMD5(Windows::Storage::Streams::IBuffer * value) = 0;
    virtual HRESULT __stdcall get_ContentRange(Windows::Web::Http::Headers::IHttpContentRangeHeaderValue ** value) = 0;
    virtual HRESULT __stdcall put_ContentRange(Windows::Web::Http::Headers::IHttpContentRangeHeaderValue * value) = 0;
    virtual HRESULT __stdcall get_ContentType(Windows::Web::Http::Headers::IHttpMediaTypeHeaderValue ** value) = 0;
    virtual HRESULT __stdcall put_ContentType(Windows::Web::Http::Headers::IHttpMediaTypeHeaderValue * value) = 0;
    virtual HRESULT __stdcall get_Expires(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall put_Expires(Windows::Foundation::IReference<Windows::Foundation::DateTime> * value) = 0;
    virtual HRESULT __stdcall get_LastModified(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall put_LastModified(Windows::Foundation::IReference<Windows::Foundation::DateTime> * value) = 0;
    virtual HRESULT __stdcall abi_Append(hstring name, hstring value) = 0;
    virtual HRESULT __stdcall abi_TryAppendWithoutValidation(hstring name, hstring value, bool * succeeded) = 0;
};

struct __declspec(uuid("04d967d3-a4f6-495c-9530-8579fcba8aa9")) __declspec(novtable) IHttpContentRangeHeaderValue : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FirstBytePosition(Windows::Foundation::IReference<uint64_t> ** value) = 0;
    virtual HRESULT __stdcall get_LastBytePosition(Windows::Foundation::IReference<uint64_t> ** value) = 0;
    virtual HRESULT __stdcall get_Length(Windows::Foundation::IReference<uint64_t> ** value) = 0;
    virtual HRESULT __stdcall get_Unit(hstring * value) = 0;
    virtual HRESULT __stdcall put_Unit(hstring value) = 0;
};

struct __declspec(uuid("3f5bd691-a03c-4456-9a6f-ef27ecd03cae")) __declspec(novtable) IHttpContentRangeHeaderValueFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateFromLength(uint64_t length, Windows::Web::Http::Headers::IHttpContentRangeHeaderValue ** contentRangeHeaderValue) = 0;
    virtual HRESULT __stdcall abi_CreateFromRange(uint64_t from, uint64_t to, Windows::Web::Http::Headers::IHttpContentRangeHeaderValue ** contentRangeHeaderValue) = 0;
    virtual HRESULT __stdcall abi_CreateFromRangeWithLength(uint64_t from, uint64_t to, uint64_t length, Windows::Web::Http::Headers::IHttpContentRangeHeaderValue ** contentRangeHeaderValue) = 0;
};

struct __declspec(uuid("80a346ca-174c-4fae-821c-134cd294aa38")) __declspec(novtable) IHttpContentRangeHeaderValueStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Parse(hstring input, Windows::Web::Http::Headers::IHttpContentRangeHeaderValue ** contentRangeHeaderValue) = 0;
    virtual HRESULT __stdcall abi_TryParse(hstring input, Windows::Web::Http::Headers::IHttpContentRangeHeaderValue ** contentRangeHeaderValue, bool * succeeded) = 0;
};

struct __declspec(uuid("cbd46217-4b29-412b-bd90-b3d814ab8e1b")) __declspec(novtable) IHttpCookiePairHeaderValue : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall get_Value(hstring * value) = 0;
    virtual HRESULT __stdcall put_Value(hstring value) = 0;
};

struct __declspec(uuid("f3f44350-581e-4ecc-9f59-e507d04f06e6")) __declspec(novtable) IHttpCookiePairHeaderValueCollection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ParseAdd(hstring input) = 0;
    virtual HRESULT __stdcall abi_TryParseAdd(hstring input, bool * succeeded) = 0;
};

struct __declspec(uuid("635e326f-146f-4f56-aa21-2cb7d6d58b1e")) __declspec(novtable) IHttpCookiePairHeaderValueFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateFromName(hstring name, Windows::Web::Http::Headers::IHttpCookiePairHeaderValue ** cookiePairHeaderValue) = 0;
    virtual HRESULT __stdcall abi_CreateFromNameWithValue(hstring name, hstring value, Windows::Web::Http::Headers::IHttpCookiePairHeaderValue ** cookiePairHeaderValue) = 0;
};

struct __declspec(uuid("6e866d48-06af-4462-8158-99388d5dca81")) __declspec(novtable) IHttpCookiePairHeaderValueStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Parse(hstring input, Windows::Web::Http::Headers::IHttpCookiePairHeaderValue ** cookiePairHeaderValue) = 0;
    virtual HRESULT __stdcall abi_TryParse(hstring input, Windows::Web::Http::Headers::IHttpCookiePairHeaderValue ** cookiePairHeaderValue, bool * succeeded) = 0;
};

struct __declspec(uuid("c34cc3cb-542e-4177-a6c7-b674ce193fbf")) __declspec(novtable) IHttpCredentialsHeaderValue : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Parameters(Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue> ** value) = 0;
    virtual HRESULT __stdcall get_Scheme(hstring * value) = 0;
    virtual HRESULT __stdcall get_Token(hstring * value) = 0;
};

struct __declspec(uuid("f21d9e91-4d1c-4182-bfd1-34470a62f950")) __declspec(novtable) IHttpCredentialsHeaderValueFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateFromScheme(hstring scheme, Windows::Web::Http::Headers::IHttpCredentialsHeaderValue ** credentialsHeaderValue) = 0;
    virtual HRESULT __stdcall abi_CreateFromSchemeWithToken(hstring scheme, hstring token, Windows::Web::Http::Headers::IHttpCredentialsHeaderValue ** credentialsHeaderValue) = 0;
};

struct __declspec(uuid("a69b2be6-ce8c-4443-a35a-1b727b131036")) __declspec(novtable) IHttpCredentialsHeaderValueStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Parse(hstring input, Windows::Web::Http::Headers::IHttpCredentialsHeaderValue ** credentialsHeaderValue) = 0;
    virtual HRESULT __stdcall abi_TryParse(hstring input, Windows::Web::Http::Headers::IHttpCredentialsHeaderValue ** credentialsHeaderValue, bool * succeeded) = 0;
};

struct __declspec(uuid("eafcaa6a-c4dc-49e2-a27d-043adf5867a3")) __declspec(novtable) IHttpDateOrDeltaHeaderValue : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Date(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall get_Delta(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> ** value) = 0;
};

struct __declspec(uuid("7c2659a8-6672-4e90-9a9a-f39766f7f576")) __declspec(novtable) IHttpDateOrDeltaHeaderValueStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Parse(hstring input, Windows::Web::Http::Headers::IHttpDateOrDeltaHeaderValue ** dateOrDeltaHeaderValue) = 0;
    virtual HRESULT __stdcall abi_TryParse(hstring input, Windows::Web::Http::Headers::IHttpDateOrDeltaHeaderValue ** dateOrDeltaHeaderValue, bool * succeeded) = 0;
};

struct __declspec(uuid("4ce585cd-3a99-43af-a2e6-ec232fea9658")) __declspec(novtable) IHttpExpectationHeaderValue : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall get_Value(hstring * value) = 0;
    virtual HRESULT __stdcall put_Value(hstring value) = 0;
    virtual HRESULT __stdcall get_Parameters(Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue> ** value) = 0;
};

struct __declspec(uuid("e78521b3-a0e2-4ac4-9e66-79706cb9fd58")) __declspec(novtable) IHttpExpectationHeaderValueCollection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ParseAdd(hstring input) = 0;
    virtual HRESULT __stdcall abi_TryParseAdd(hstring input, bool * succeeded) = 0;
};

struct __declspec(uuid("4ea275cb-d53e-4868-8856-1e21a5030dc0")) __declspec(novtable) IHttpExpectationHeaderValueFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateFromName(hstring name, Windows::Web::Http::Headers::IHttpExpectationHeaderValue ** expectationHeaderValue) = 0;
    virtual HRESULT __stdcall abi_CreateFromNameWithValue(hstring name, hstring value, Windows::Web::Http::Headers::IHttpExpectationHeaderValue ** expectationHeaderValue) = 0;
};

struct __declspec(uuid("3019abe2-cfe5-473b-a57f-fba5b14eb257")) __declspec(novtable) IHttpExpectationHeaderValueStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Parse(hstring input, Windows::Web::Http::Headers::IHttpExpectationHeaderValue ** expectationHeaderValue) = 0;
    virtual HRESULT __stdcall abi_TryParse(hstring input, Windows::Web::Http::Headers::IHttpExpectationHeaderValue ** expectationHeaderValue, bool * succeeded) = 0;
};

struct __declspec(uuid("9ebd7ca3-8219-44f6-9902-8c56dfd3340c")) __declspec(novtable) IHttpLanguageHeaderValueCollection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ParseAdd(hstring input) = 0;
    virtual HRESULT __stdcall abi_TryParseAdd(hstring input, bool * succeeded) = 0;
};

struct __declspec(uuid("7256e102-0080-4db4-a083-7de7b2e5ba4c")) __declspec(novtable) IHttpLanguageRangeWithQualityHeaderValue : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LanguageRange(hstring * languageRange) = 0;
    virtual HRESULT __stdcall get_Quality(Windows::Foundation::IReference<double> ** value) = 0;
};

struct __declspec(uuid("885d5abd-4b4f-480a-89ce-8aedcee6e3a0")) __declspec(novtable) IHttpLanguageRangeWithQualityHeaderValueCollection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ParseAdd(hstring input) = 0;
    virtual HRESULT __stdcall abi_TryParseAdd(hstring input, bool * succeeded) = 0;
};

struct __declspec(uuid("7bb83970-780f-4c83-9fe4-dc3087f6bd55")) __declspec(novtable) IHttpLanguageRangeWithQualityHeaderValueFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateFromLanguageRange(hstring languageRange, Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValue ** languageRangeWithQualityHeaderValue) = 0;
    virtual HRESULT __stdcall abi_CreateFromLanguageRangeWithQuality(hstring languageRange, double quality, Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValue ** languageRangeWithQualityHeaderValue) = 0;
};

struct __declspec(uuid("2541e146-f308-46f5-b695-42f54024ec68")) __declspec(novtable) IHttpLanguageRangeWithQualityHeaderValueStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Parse(hstring input, Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValue ** languageRangeWithQualityHeaderValue) = 0;
    virtual HRESULT __stdcall abi_TryParse(hstring input, Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValue ** languageRangeWithQualityHeaderValue, bool * succeeded) = 0;
};

struct __declspec(uuid("16b28533-e728-4fcb-bdb0-08a431a14844")) __declspec(novtable) IHttpMediaTypeHeaderValue : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CharSet(hstring * value) = 0;
    virtual HRESULT __stdcall put_CharSet(hstring value) = 0;
    virtual HRESULT __stdcall get_MediaType(hstring * value) = 0;
    virtual HRESULT __stdcall put_MediaType(hstring value) = 0;
    virtual HRESULT __stdcall get_Parameters(Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue> ** value) = 0;
};

struct __declspec(uuid("bed747a8-cd17-42dd-9367-ab9c5b56dd7d")) __declspec(novtable) IHttpMediaTypeHeaderValueFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring mediaType, Windows::Web::Http::Headers::IHttpMediaTypeHeaderValue ** mediaTypeHeaderValue) = 0;
};

struct __declspec(uuid("e04d83df-1d41-4d8c-a2de-6fd2ed87399b")) __declspec(novtable) IHttpMediaTypeHeaderValueStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Parse(hstring input, Windows::Web::Http::Headers::IHttpMediaTypeHeaderValue ** mediaTypeHeaderValue) = 0;
    virtual HRESULT __stdcall abi_TryParse(hstring input, Windows::Web::Http::Headers::IHttpMediaTypeHeaderValue ** mediaTypeHeaderValue, bool * succeeded) = 0;
};

struct __declspec(uuid("188d5e32-76be-44a0-b1cd-2074bded2dde")) __declspec(novtable) IHttpMediaTypeWithQualityHeaderValue : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CharSet(hstring * value) = 0;
    virtual HRESULT __stdcall put_CharSet(hstring value) = 0;
    virtual HRESULT __stdcall get_MediaType(hstring * value) = 0;
    virtual HRESULT __stdcall put_MediaType(hstring value) = 0;
    virtual HRESULT __stdcall get_Parameters(Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue> ** value) = 0;
    virtual HRESULT __stdcall get_Quality(Windows::Foundation::IReference<double> ** value) = 0;
    virtual HRESULT __stdcall put_Quality(Windows::Foundation::IReference<double> * value) = 0;
};

struct __declspec(uuid("3c0c6b73-1342-4587-a056-18d02ff67165")) __declspec(novtable) IHttpMediaTypeWithQualityHeaderValueCollection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ParseAdd(hstring input) = 0;
    virtual HRESULT __stdcall abi_TryParseAdd(hstring input, bool * succeeded) = 0;
};

struct __declspec(uuid("4c6d20f4-9457-44e6-a323-d122b958780b")) __declspec(novtable) IHttpMediaTypeWithQualityHeaderValueFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateFromMediaType(hstring mediaType, Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue ** mediaTypeWithQualityHeaderValue) = 0;
    virtual HRESULT __stdcall abi_CreateFromMediaTypeWithQuality(hstring mediaType, double quality, Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue ** mediaTypeWithQualityHeaderValue) = 0;
};

struct __declspec(uuid("5b070cd9-b560-4fc8-9835-7e6c0a657b24")) __declspec(novtable) IHttpMediaTypeWithQualityHeaderValueStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Parse(hstring input, Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue ** mediaTypeWithQualityHeaderValue) = 0;
    virtual HRESULT __stdcall abi_TryParse(hstring input, Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue ** mediaTypeWithQualityHeaderValue, bool * succeeded) = 0;
};

struct __declspec(uuid("43bc3ff4-6119-4adf-938c-34bfffcf92ed")) __declspec(novtable) IHttpMethodHeaderValueCollection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ParseAdd(hstring input) = 0;
    virtual HRESULT __stdcall abi_TryParseAdd(hstring input, bool * succeeded) = 0;
};

struct __declspec(uuid("d8ba7463-5b9a-4d1b-93f9-aa5b44ecfddf")) __declspec(novtable) IHttpNameValueHeaderValue : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall get_Value(hstring * value) = 0;
    virtual HRESULT __stdcall put_Value(hstring value) = 0;
};

struct __declspec(uuid("770e2267-cbf8-4736-a925-93fbe10c7ca8")) __declspec(novtable) IHttpNameValueHeaderValueFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateFromName(hstring name, Windows::Web::Http::Headers::IHttpNameValueHeaderValue ** nameValueHeaderValue) = 0;
    virtual HRESULT __stdcall abi_CreateFromNameWithValue(hstring name, hstring value, Windows::Web::Http::Headers::IHttpNameValueHeaderValue ** nameValueHeaderValue) = 0;
};

struct __declspec(uuid("ffd4030f-1130-4152-8659-256909a9d115")) __declspec(novtable) IHttpNameValueHeaderValueStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Parse(hstring input, Windows::Web::Http::Headers::IHttpNameValueHeaderValue ** nameValueHeaderValue) = 0;
    virtual HRESULT __stdcall abi_TryParse(hstring input, Windows::Web::Http::Headers::IHttpNameValueHeaderValue ** nameValueHeaderValue, bool * succeeded) = 0;
};

struct __declspec(uuid("f4feee03-ebd4-4160-b9ff-807c5183b6e6")) __declspec(novtable) IHttpProductHeaderValue : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall get_Version(hstring * value) = 0;
};

struct __declspec(uuid("611aa4f5-82bc-42fb-977b-dc00536e5e86")) __declspec(novtable) IHttpProductHeaderValueFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateFromName(hstring productName, Windows::Web::Http::Headers::IHttpProductHeaderValue ** productHeaderValue) = 0;
    virtual HRESULT __stdcall abi_CreateFromNameWithVersion(hstring productName, hstring productVersion, Windows::Web::Http::Headers::IHttpProductHeaderValue ** productHeaderValue) = 0;
};

struct __declspec(uuid("90c33e29-befc-4337-be62-49f097975f53")) __declspec(novtable) IHttpProductHeaderValueStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Parse(hstring input, Windows::Web::Http::Headers::IHttpProductHeaderValue ** productHeaderValue) = 0;
    virtual HRESULT __stdcall abi_TryParse(hstring input, Windows::Web::Http::Headers::IHttpProductHeaderValue ** productHeaderValue, bool * succeeded) = 0;
};

struct __declspec(uuid("1b1a8732-4c35-486a-966f-646489198e4d")) __declspec(novtable) IHttpProductInfoHeaderValue : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Product(Windows::Web::Http::Headers::IHttpProductHeaderValue ** value) = 0;
    virtual HRESULT __stdcall get_Comment(hstring * value) = 0;
};

struct __declspec(uuid("877df74a-d69b-44f8-ad4f-453af9c42ed0")) __declspec(novtable) IHttpProductInfoHeaderValueCollection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ParseAdd(hstring input) = 0;
    virtual HRESULT __stdcall abi_TryParseAdd(hstring input, bool * succeeded) = 0;
};

struct __declspec(uuid("24220fbe-eabe-4464-b460-ec010b7c41e2")) __declspec(novtable) IHttpProductInfoHeaderValueFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateFromComment(hstring productComment, Windows::Web::Http::Headers::IHttpProductInfoHeaderValue ** productInfoHeaderValue) = 0;
    virtual HRESULT __stdcall abi_CreateFromNameWithVersion(hstring productName, hstring productVersion, Windows::Web::Http::Headers::IHttpProductInfoHeaderValue ** productInfoHeaderValue) = 0;
};

struct __declspec(uuid("db7fd857-327a-4e73-81e5-7059a302b042")) __declspec(novtable) IHttpProductInfoHeaderValueStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Parse(hstring input, Windows::Web::Http::Headers::IHttpProductInfoHeaderValue ** productInfoHeaderValue) = 0;
    virtual HRESULT __stdcall abi_TryParse(hstring input, Windows::Web::Http::Headers::IHttpProductInfoHeaderValue ** productInfoHeaderValue, bool * succeeded) = 0;
};

struct __declspec(uuid("af40329b-b544-469b-86b9-ac3d466fea36")) __declspec(novtable) IHttpRequestHeaderCollection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Accept(Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValueCollection ** value) = 0;
    virtual HRESULT __stdcall get_AcceptEncoding(Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValueCollection ** value) = 0;
    virtual HRESULT __stdcall get_AcceptLanguage(Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValueCollection ** value) = 0;
    virtual HRESULT __stdcall get_Authorization(Windows::Web::Http::Headers::IHttpCredentialsHeaderValue ** value) = 0;
    virtual HRESULT __stdcall put_Authorization(Windows::Web::Http::Headers::IHttpCredentialsHeaderValue * value) = 0;
    virtual HRESULT __stdcall get_CacheControl(Windows::Web::Http::Headers::IHttpCacheDirectiveHeaderValueCollection ** value) = 0;
    virtual HRESULT __stdcall get_Connection(Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValueCollection ** value) = 0;
    virtual HRESULT __stdcall get_Cookie(Windows::Web::Http::Headers::IHttpCookiePairHeaderValueCollection ** value) = 0;
    virtual HRESULT __stdcall get_Date(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall put_Date(Windows::Foundation::IReference<Windows::Foundation::DateTime> * value) = 0;
    virtual HRESULT __stdcall get_Expect(Windows::Web::Http::Headers::IHttpExpectationHeaderValueCollection ** value) = 0;
    virtual HRESULT __stdcall get_From(hstring * value) = 0;
    virtual HRESULT __stdcall put_From(hstring value) = 0;
    virtual HRESULT __stdcall get_Host(Windows::Networking::IHostName ** value) = 0;
    virtual HRESULT __stdcall put_Host(Windows::Networking::IHostName * value) = 0;
    virtual HRESULT __stdcall get_IfModifiedSince(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall put_IfModifiedSince(Windows::Foundation::IReference<Windows::Foundation::DateTime> * value) = 0;
    virtual HRESULT __stdcall get_IfUnmodifiedSince(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall put_IfUnmodifiedSince(Windows::Foundation::IReference<Windows::Foundation::DateTime> * value) = 0;
    virtual HRESULT __stdcall get_MaxForwards(Windows::Foundation::IReference<uint32_t> ** value) = 0;
    virtual HRESULT __stdcall put_MaxForwards(Windows::Foundation::IReference<uint32_t> * value) = 0;
    virtual HRESULT __stdcall get_ProxyAuthorization(Windows::Web::Http::Headers::IHttpCredentialsHeaderValue ** value) = 0;
    virtual HRESULT __stdcall put_ProxyAuthorization(Windows::Web::Http::Headers::IHttpCredentialsHeaderValue * value) = 0;
    virtual HRESULT __stdcall get_Referer(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall put_Referer(Windows::Foundation::IUriRuntimeClass * value) = 0;
    virtual HRESULT __stdcall get_TransferEncoding(Windows::Web::Http::Headers::IHttpTransferCodingHeaderValueCollection ** value) = 0;
    virtual HRESULT __stdcall get_UserAgent(Windows::Web::Http::Headers::IHttpProductInfoHeaderValueCollection ** value) = 0;
    virtual HRESULT __stdcall abi_Append(hstring name, hstring value) = 0;
    virtual HRESULT __stdcall abi_TryAppendWithoutValidation(hstring name, hstring value, bool * succeeded) = 0;
};

struct __declspec(uuid("7a990969-fa3f-41ed-aac6-bf957975c16b")) __declspec(novtable) IHttpResponseHeaderCollection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Age(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> ** value) = 0;
    virtual HRESULT __stdcall put_Age(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> * value) = 0;
    virtual HRESULT __stdcall get_Allow(Windows::Web::Http::Headers::IHttpMethodHeaderValueCollection ** value) = 0;
    virtual HRESULT __stdcall get_CacheControl(Windows::Web::Http::Headers::IHttpCacheDirectiveHeaderValueCollection ** value) = 0;
    virtual HRESULT __stdcall get_Connection(Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValueCollection ** value) = 0;
    virtual HRESULT __stdcall get_Date(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall put_Date(Windows::Foundation::IReference<Windows::Foundation::DateTime> * value) = 0;
    virtual HRESULT __stdcall get_Location(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall put_Location(Windows::Foundation::IUriRuntimeClass * value) = 0;
    virtual HRESULT __stdcall get_ProxyAuthenticate(Windows::Web::Http::Headers::IHttpChallengeHeaderValueCollection ** value) = 0;
    virtual HRESULT __stdcall get_RetryAfter(Windows::Web::Http::Headers::IHttpDateOrDeltaHeaderValue ** value) = 0;
    virtual HRESULT __stdcall put_RetryAfter(Windows::Web::Http::Headers::IHttpDateOrDeltaHeaderValue * value) = 0;
    virtual HRESULT __stdcall get_TransferEncoding(Windows::Web::Http::Headers::IHttpTransferCodingHeaderValueCollection ** value) = 0;
    virtual HRESULT __stdcall get_WwwAuthenticate(Windows::Web::Http::Headers::IHttpChallengeHeaderValueCollection ** value) = 0;
    virtual HRESULT __stdcall abi_Append(hstring name, hstring value) = 0;
    virtual HRESULT __stdcall abi_TryAppendWithoutValidation(hstring name, hstring value, bool * succeeded) = 0;
};

struct __declspec(uuid("436f32f9-3ded-42bd-b38a-5496a2511ce6")) __declspec(novtable) IHttpTransferCodingHeaderValue : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Parameters(Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue> ** value) = 0;
    virtual HRESULT __stdcall get_Value(hstring * value) = 0;
};

struct __declspec(uuid("202c8c34-2c03-49b8-9665-73e27cb2fc79")) __declspec(novtable) IHttpTransferCodingHeaderValueCollection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ParseAdd(hstring input) = 0;
    virtual HRESULT __stdcall abi_TryParseAdd(hstring input, bool * succeeded) = 0;
};

struct __declspec(uuid("bb62dffc-e361-4f08-8e4f-c9e723de703b")) __declspec(novtable) IHttpTransferCodingHeaderValueFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring input, Windows::Web::Http::Headers::IHttpTransferCodingHeaderValue ** transferCodingHeaderValue) = 0;
};

struct __declspec(uuid("6ab8892a-1a98-4d32-a906-7470a9875ce5")) __declspec(novtable) IHttpTransferCodingHeaderValueStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Parse(hstring input, Windows::Web::Http::Headers::IHttpTransferCodingHeaderValue ** transferCodingHeaderValue) = 0;
    virtual HRESULT __stdcall abi_TryParse(hstring input, Windows::Web::Http::Headers::IHttpTransferCodingHeaderValue ** transferCodingHeaderValue, bool * succeeded) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Web::Http::Headers::HttpCacheDirectiveHeaderValueCollection> { using default_interface = Windows::Web::Http::Headers::IHttpCacheDirectiveHeaderValueCollection; };
template <> struct traits<Windows::Web::Http::Headers::HttpChallengeHeaderValue> { using default_interface = Windows::Web::Http::Headers::IHttpChallengeHeaderValue; };
template <> struct traits<Windows::Web::Http::Headers::HttpChallengeHeaderValueCollection> { using default_interface = Windows::Web::Http::Headers::IHttpChallengeHeaderValueCollection; };
template <> struct traits<Windows::Web::Http::Headers::HttpConnectionOptionHeaderValue> { using default_interface = Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValue; };
template <> struct traits<Windows::Web::Http::Headers::HttpConnectionOptionHeaderValueCollection> { using default_interface = Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValueCollection; };
template <> struct traits<Windows::Web::Http::Headers::HttpContentCodingHeaderValue> { using default_interface = Windows::Web::Http::Headers::IHttpContentCodingHeaderValue; };
template <> struct traits<Windows::Web::Http::Headers::HttpContentCodingHeaderValueCollection> { using default_interface = Windows::Web::Http::Headers::IHttpContentCodingHeaderValueCollection; };
template <> struct traits<Windows::Web::Http::Headers::HttpContentCodingWithQualityHeaderValue> { using default_interface = Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValue; };
template <> struct traits<Windows::Web::Http::Headers::HttpContentCodingWithQualityHeaderValueCollection> { using default_interface = Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValueCollection; };
template <> struct traits<Windows::Web::Http::Headers::HttpContentDispositionHeaderValue> { using default_interface = Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue; };
template <> struct traits<Windows::Web::Http::Headers::HttpContentHeaderCollection> { using default_interface = Windows::Web::Http::Headers::IHttpContentHeaderCollection; };
template <> struct traits<Windows::Web::Http::Headers::HttpContentRangeHeaderValue> { using default_interface = Windows::Web::Http::Headers::IHttpContentRangeHeaderValue; };
template <> struct traits<Windows::Web::Http::Headers::HttpCookiePairHeaderValue> { using default_interface = Windows::Web::Http::Headers::IHttpCookiePairHeaderValue; };
template <> struct traits<Windows::Web::Http::Headers::HttpCookiePairHeaderValueCollection> { using default_interface = Windows::Web::Http::Headers::IHttpCookiePairHeaderValueCollection; };
template <> struct traits<Windows::Web::Http::Headers::HttpCredentialsHeaderValue> { using default_interface = Windows::Web::Http::Headers::IHttpCredentialsHeaderValue; };
template <> struct traits<Windows::Web::Http::Headers::HttpDateOrDeltaHeaderValue> { using default_interface = Windows::Web::Http::Headers::IHttpDateOrDeltaHeaderValue; };
template <> struct traits<Windows::Web::Http::Headers::HttpExpectationHeaderValue> { using default_interface = Windows::Web::Http::Headers::IHttpExpectationHeaderValue; };
template <> struct traits<Windows::Web::Http::Headers::HttpExpectationHeaderValueCollection> { using default_interface = Windows::Web::Http::Headers::IHttpExpectationHeaderValueCollection; };
template <> struct traits<Windows::Web::Http::Headers::HttpLanguageHeaderValueCollection> { using default_interface = Windows::Web::Http::Headers::IHttpLanguageHeaderValueCollection; };
template <> struct traits<Windows::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValue> { using default_interface = Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValue; };
template <> struct traits<Windows::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValueCollection> { using default_interface = Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValueCollection; };
template <> struct traits<Windows::Web::Http::Headers::HttpMediaTypeHeaderValue> { using default_interface = Windows::Web::Http::Headers::IHttpMediaTypeHeaderValue; };
template <> struct traits<Windows::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValue> { using default_interface = Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue; };
template <> struct traits<Windows::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValueCollection> { using default_interface = Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValueCollection; };
template <> struct traits<Windows::Web::Http::Headers::HttpMethodHeaderValueCollection> { using default_interface = Windows::Web::Http::Headers::IHttpMethodHeaderValueCollection; };
template <> struct traits<Windows::Web::Http::Headers::HttpNameValueHeaderValue> { using default_interface = Windows::Web::Http::Headers::IHttpNameValueHeaderValue; };
template <> struct traits<Windows::Web::Http::Headers::HttpProductHeaderValue> { using default_interface = Windows::Web::Http::Headers::IHttpProductHeaderValue; };
template <> struct traits<Windows::Web::Http::Headers::HttpProductInfoHeaderValue> { using default_interface = Windows::Web::Http::Headers::IHttpProductInfoHeaderValue; };
template <> struct traits<Windows::Web::Http::Headers::HttpProductInfoHeaderValueCollection> { using default_interface = Windows::Web::Http::Headers::IHttpProductInfoHeaderValueCollection; };
template <> struct traits<Windows::Web::Http::Headers::HttpRequestHeaderCollection> { using default_interface = Windows::Web::Http::Headers::IHttpRequestHeaderCollection; };
template <> struct traits<Windows::Web::Http::Headers::HttpResponseHeaderCollection> { using default_interface = Windows::Web::Http::Headers::IHttpResponseHeaderCollection; };
template <> struct traits<Windows::Web::Http::Headers::HttpTransferCodingHeaderValue> { using default_interface = Windows::Web::Http::Headers::IHttpTransferCodingHeaderValue; };
template <> struct traits<Windows::Web::Http::Headers::HttpTransferCodingHeaderValueCollection> { using default_interface = Windows::Web::Http::Headers::IHttpTransferCodingHeaderValueCollection; };

}

namespace Windows::Web::Http::Headers {

template <typename D>
struct WINRT_EBO impl_IHttpCacheDirectiveHeaderValueCollection
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> MaxAge() const;
    void MaxAge(const optional<Windows::Foundation::TimeSpan> & value) const;
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> MaxStale() const;
    void MaxStale(const optional<Windows::Foundation::TimeSpan> & value) const;
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> MinFresh() const;
    void MinFresh(const optional<Windows::Foundation::TimeSpan> & value) const;
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> SharedMaxAge() const;
    void SharedMaxAge(const optional<Windows::Foundation::TimeSpan> & value) const;
    void ParseAdd(hstring_view input) const;
    bool TryParseAdd(hstring_view input) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpChallengeHeaderValue
{
    Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue> Parameters() const;
    hstring Scheme() const;
    hstring Token() const;
};

template <typename D>
struct WINRT_EBO impl_IHttpChallengeHeaderValueCollection
{
    void ParseAdd(hstring_view input) const;
    bool TryParseAdd(hstring_view input) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpChallengeHeaderValueFactory
{
    Windows::Web::Http::Headers::HttpChallengeHeaderValue CreateFromScheme(hstring_view scheme) const;
    Windows::Web::Http::Headers::HttpChallengeHeaderValue CreateFromSchemeWithToken(hstring_view scheme, hstring_view token) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpChallengeHeaderValueStatics
{
    Windows::Web::Http::Headers::HttpChallengeHeaderValue Parse(hstring_view input) const;
    bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpChallengeHeaderValue & challengeHeaderValue) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpConnectionOptionHeaderValue
{
    hstring Token() const;
};

template <typename D>
struct WINRT_EBO impl_IHttpConnectionOptionHeaderValueCollection
{
    void ParseAdd(hstring_view input) const;
    bool TryParseAdd(hstring_view input) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpConnectionOptionHeaderValueFactory
{
    Windows::Web::Http::Headers::HttpConnectionOptionHeaderValue Create(hstring_view token) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpConnectionOptionHeaderValueStatics
{
    Windows::Web::Http::Headers::HttpConnectionOptionHeaderValue Parse(hstring_view input) const;
    bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpConnectionOptionHeaderValue & connectionOptionHeaderValue) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpContentCodingHeaderValue
{
    hstring ContentCoding() const;
};

template <typename D>
struct WINRT_EBO impl_IHttpContentCodingHeaderValueCollection
{
    void ParseAdd(hstring_view input) const;
    bool TryParseAdd(hstring_view input) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpContentCodingHeaderValueFactory
{
    Windows::Web::Http::Headers::HttpContentCodingHeaderValue Create(hstring_view contentCoding) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpContentCodingHeaderValueStatics
{
    Windows::Web::Http::Headers::HttpContentCodingHeaderValue Parse(hstring_view input) const;
    bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpContentCodingHeaderValue & contentCodingHeaderValue) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpContentCodingWithQualityHeaderValue
{
    hstring ContentCoding() const;
    Windows::Foundation::IReference<double> Quality() const;
};

template <typename D>
struct WINRT_EBO impl_IHttpContentCodingWithQualityHeaderValueCollection
{
    void ParseAdd(hstring_view input) const;
    bool TryParseAdd(hstring_view input) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpContentCodingWithQualityHeaderValueFactory
{
    Windows::Web::Http::Headers::HttpContentCodingWithQualityHeaderValue CreateFromValue(hstring_view contentCoding) const;
    Windows::Web::Http::Headers::HttpContentCodingWithQualityHeaderValue CreateFromValueWithQuality(hstring_view contentCoding, double quality) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpContentCodingWithQualityHeaderValueStatics
{
    Windows::Web::Http::Headers::HttpContentCodingWithQualityHeaderValue Parse(hstring_view input) const;
    bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpContentCodingWithQualityHeaderValue & contentCodingWithQualityHeaderValue) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpContentDispositionHeaderValue
{
    hstring DispositionType() const;
    void DispositionType(hstring_view value) const;
    hstring FileName() const;
    void FileName(hstring_view value) const;
    hstring FileNameStar() const;
    void FileNameStar(hstring_view value) const;
    hstring Name() const;
    void Name(hstring_view value) const;
    Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue> Parameters() const;
    Windows::Foundation::IReference<uint64_t> Size() const;
    void Size(const optional<uint64_t> & value) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpContentDispositionHeaderValueFactory
{
    Windows::Web::Http::Headers::HttpContentDispositionHeaderValue Create(hstring_view dispositionType) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpContentDispositionHeaderValueStatics
{
    Windows::Web::Http::Headers::HttpContentDispositionHeaderValue Parse(hstring_view input) const;
    bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpContentDispositionHeaderValue & contentDispositionHeaderValue) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpContentHeaderCollection
{
    Windows::Web::Http::Headers::HttpContentDispositionHeaderValue ContentDisposition() const;
    void ContentDisposition(const Windows::Web::Http::Headers::HttpContentDispositionHeaderValue & value) const;
    Windows::Web::Http::Headers::HttpContentCodingHeaderValueCollection ContentEncoding() const;
    Windows::Web::Http::Headers::HttpLanguageHeaderValueCollection ContentLanguage() const;
    Windows::Foundation::IReference<uint64_t> ContentLength() const;
    void ContentLength(const optional<uint64_t> & value) const;
    Windows::Foundation::Uri ContentLocation() const;
    void ContentLocation(const Windows::Foundation::Uri & value) const;
    Windows::Storage::Streams::IBuffer ContentMD5() const;
    void ContentMD5(const Windows::Storage::Streams::IBuffer & value) const;
    Windows::Web::Http::Headers::HttpContentRangeHeaderValue ContentRange() const;
    void ContentRange(const Windows::Web::Http::Headers::HttpContentRangeHeaderValue & value) const;
    Windows::Web::Http::Headers::HttpMediaTypeHeaderValue ContentType() const;
    void ContentType(const Windows::Web::Http::Headers::HttpMediaTypeHeaderValue & value) const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> Expires() const;
    void Expires(const optional<Windows::Foundation::DateTime> & value) const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> LastModified() const;
    void LastModified(const optional<Windows::Foundation::DateTime> & value) const;
    void Append(hstring_view name, hstring_view value) const;
    bool TryAppendWithoutValidation(hstring_view name, hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpContentRangeHeaderValue
{
    Windows::Foundation::IReference<uint64_t> FirstBytePosition() const;
    Windows::Foundation::IReference<uint64_t> LastBytePosition() const;
    Windows::Foundation::IReference<uint64_t> Length() const;
    hstring Unit() const;
    void Unit(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpContentRangeHeaderValueFactory
{
    Windows::Web::Http::Headers::HttpContentRangeHeaderValue CreateFromLength(uint64_t length) const;
    Windows::Web::Http::Headers::HttpContentRangeHeaderValue CreateFromRange(uint64_t from, uint64_t to) const;
    Windows::Web::Http::Headers::HttpContentRangeHeaderValue CreateFromRangeWithLength(uint64_t from, uint64_t to, uint64_t length) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpContentRangeHeaderValueStatics
{
    Windows::Web::Http::Headers::HttpContentRangeHeaderValue Parse(hstring_view input) const;
    bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpContentRangeHeaderValue & contentRangeHeaderValue) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpCookiePairHeaderValue
{
    hstring Name() const;
    hstring Value() const;
    void Value(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpCookiePairHeaderValueCollection
{
    void ParseAdd(hstring_view input) const;
    bool TryParseAdd(hstring_view input) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpCookiePairHeaderValueFactory
{
    Windows::Web::Http::Headers::HttpCookiePairHeaderValue CreateFromName(hstring_view name) const;
    Windows::Web::Http::Headers::HttpCookiePairHeaderValue CreateFromNameWithValue(hstring_view name, hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpCookiePairHeaderValueStatics
{
    Windows::Web::Http::Headers::HttpCookiePairHeaderValue Parse(hstring_view input) const;
    bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpCookiePairHeaderValue & cookiePairHeaderValue) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpCredentialsHeaderValue
{
    Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue> Parameters() const;
    hstring Scheme() const;
    hstring Token() const;
};

template <typename D>
struct WINRT_EBO impl_IHttpCredentialsHeaderValueFactory
{
    Windows::Web::Http::Headers::HttpCredentialsHeaderValue CreateFromScheme(hstring_view scheme) const;
    Windows::Web::Http::Headers::HttpCredentialsHeaderValue CreateFromSchemeWithToken(hstring_view scheme, hstring_view token) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpCredentialsHeaderValueStatics
{
    Windows::Web::Http::Headers::HttpCredentialsHeaderValue Parse(hstring_view input) const;
    bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpCredentialsHeaderValue & credentialsHeaderValue) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpDateOrDeltaHeaderValue
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> Date() const;
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> Delta() const;
};

template <typename D>
struct WINRT_EBO impl_IHttpDateOrDeltaHeaderValueStatics
{
    Windows::Web::Http::Headers::HttpDateOrDeltaHeaderValue Parse(hstring_view input) const;
    bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpDateOrDeltaHeaderValue & dateOrDeltaHeaderValue) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpExpectationHeaderValue
{
    hstring Name() const;
    hstring Value() const;
    void Value(hstring_view value) const;
    Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue> Parameters() const;
};

template <typename D>
struct WINRT_EBO impl_IHttpExpectationHeaderValueCollection
{
    void ParseAdd(hstring_view input) const;
    bool TryParseAdd(hstring_view input) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpExpectationHeaderValueFactory
{
    Windows::Web::Http::Headers::HttpExpectationHeaderValue CreateFromName(hstring_view name) const;
    Windows::Web::Http::Headers::HttpExpectationHeaderValue CreateFromNameWithValue(hstring_view name, hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpExpectationHeaderValueStatics
{
    Windows::Web::Http::Headers::HttpExpectationHeaderValue Parse(hstring_view input) const;
    bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpExpectationHeaderValue & expectationHeaderValue) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpLanguageHeaderValueCollection
{
    void ParseAdd(hstring_view input) const;
    bool TryParseAdd(hstring_view input) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpLanguageRangeWithQualityHeaderValue
{
    hstring LanguageRange() const;
    Windows::Foundation::IReference<double> Quality() const;
};

template <typename D>
struct WINRT_EBO impl_IHttpLanguageRangeWithQualityHeaderValueCollection
{
    void ParseAdd(hstring_view input) const;
    bool TryParseAdd(hstring_view input) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpLanguageRangeWithQualityHeaderValueFactory
{
    Windows::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValue CreateFromLanguageRange(hstring_view languageRange) const;
    Windows::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValue CreateFromLanguageRangeWithQuality(hstring_view languageRange, double quality) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpLanguageRangeWithQualityHeaderValueStatics
{
    Windows::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValue Parse(hstring_view input) const;
    bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValue & languageRangeWithQualityHeaderValue) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpMediaTypeHeaderValue
{
    hstring CharSet() const;
    void CharSet(hstring_view value) const;
    hstring MediaType() const;
    void MediaType(hstring_view value) const;
    Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue> Parameters() const;
};

template <typename D>
struct WINRT_EBO impl_IHttpMediaTypeHeaderValueFactory
{
    Windows::Web::Http::Headers::HttpMediaTypeHeaderValue Create(hstring_view mediaType) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpMediaTypeHeaderValueStatics
{
    Windows::Web::Http::Headers::HttpMediaTypeHeaderValue Parse(hstring_view input) const;
    bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpMediaTypeHeaderValue & mediaTypeHeaderValue) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpMediaTypeWithQualityHeaderValue
{
    hstring CharSet() const;
    void CharSet(hstring_view value) const;
    hstring MediaType() const;
    void MediaType(hstring_view value) const;
    Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue> Parameters() const;
    Windows::Foundation::IReference<double> Quality() const;
    void Quality(const optional<double> & value) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpMediaTypeWithQualityHeaderValueCollection
{
    void ParseAdd(hstring_view input) const;
    bool TryParseAdd(hstring_view input) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpMediaTypeWithQualityHeaderValueFactory
{
    Windows::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValue CreateFromMediaType(hstring_view mediaType) const;
    Windows::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValue CreateFromMediaTypeWithQuality(hstring_view mediaType, double quality) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpMediaTypeWithQualityHeaderValueStatics
{
    Windows::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValue Parse(hstring_view input) const;
    bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValue & mediaTypeWithQualityHeaderValue) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpMethodHeaderValueCollection
{
    void ParseAdd(hstring_view input) const;
    bool TryParseAdd(hstring_view input) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpNameValueHeaderValue
{
    hstring Name() const;
    hstring Value() const;
    void Value(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpNameValueHeaderValueFactory
{
    Windows::Web::Http::Headers::HttpNameValueHeaderValue CreateFromName(hstring_view name) const;
    Windows::Web::Http::Headers::HttpNameValueHeaderValue CreateFromNameWithValue(hstring_view name, hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpNameValueHeaderValueStatics
{
    Windows::Web::Http::Headers::HttpNameValueHeaderValue Parse(hstring_view input) const;
    bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpNameValueHeaderValue & nameValueHeaderValue) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpProductHeaderValue
{
    hstring Name() const;
    hstring Version() const;
};

template <typename D>
struct WINRT_EBO impl_IHttpProductHeaderValueFactory
{
    Windows::Web::Http::Headers::HttpProductHeaderValue CreateFromName(hstring_view productName) const;
    Windows::Web::Http::Headers::HttpProductHeaderValue CreateFromNameWithVersion(hstring_view productName, hstring_view productVersion) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpProductHeaderValueStatics
{
    Windows::Web::Http::Headers::HttpProductHeaderValue Parse(hstring_view input) const;
    bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpProductHeaderValue & productHeaderValue) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpProductInfoHeaderValue
{
    Windows::Web::Http::Headers::HttpProductHeaderValue Product() const;
    hstring Comment() const;
};

template <typename D>
struct WINRT_EBO impl_IHttpProductInfoHeaderValueCollection
{
    void ParseAdd(hstring_view input) const;
    bool TryParseAdd(hstring_view input) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpProductInfoHeaderValueFactory
{
    Windows::Web::Http::Headers::HttpProductInfoHeaderValue CreateFromComment(hstring_view productComment) const;
    Windows::Web::Http::Headers::HttpProductInfoHeaderValue CreateFromNameWithVersion(hstring_view productName, hstring_view productVersion) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpProductInfoHeaderValueStatics
{
    Windows::Web::Http::Headers::HttpProductInfoHeaderValue Parse(hstring_view input) const;
    bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpProductInfoHeaderValue & productInfoHeaderValue) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpRequestHeaderCollection
{
    Windows::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValueCollection Accept() const;
    Windows::Web::Http::Headers::HttpContentCodingWithQualityHeaderValueCollection AcceptEncoding() const;
    Windows::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValueCollection AcceptLanguage() const;
    Windows::Web::Http::Headers::HttpCredentialsHeaderValue Authorization() const;
    void Authorization(const Windows::Web::Http::Headers::HttpCredentialsHeaderValue & value) const;
    Windows::Web::Http::Headers::HttpCacheDirectiveHeaderValueCollection CacheControl() const;
    Windows::Web::Http::Headers::HttpConnectionOptionHeaderValueCollection Connection() const;
    Windows::Web::Http::Headers::HttpCookiePairHeaderValueCollection Cookie() const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> Date() const;
    void Date(const optional<Windows::Foundation::DateTime> & value) const;
    Windows::Web::Http::Headers::HttpExpectationHeaderValueCollection Expect() const;
    hstring From() const;
    void From(hstring_view value) const;
    Windows::Networking::HostName Host() const;
    void Host(const Windows::Networking::HostName & value) const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> IfModifiedSince() const;
    void IfModifiedSince(const optional<Windows::Foundation::DateTime> & value) const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> IfUnmodifiedSince() const;
    void IfUnmodifiedSince(const optional<Windows::Foundation::DateTime> & value) const;
    Windows::Foundation::IReference<uint32_t> MaxForwards() const;
    void MaxForwards(const optional<uint32_t> & value) const;
    Windows::Web::Http::Headers::HttpCredentialsHeaderValue ProxyAuthorization() const;
    void ProxyAuthorization(const Windows::Web::Http::Headers::HttpCredentialsHeaderValue & value) const;
    Windows::Foundation::Uri Referer() const;
    void Referer(const Windows::Foundation::Uri & value) const;
    Windows::Web::Http::Headers::HttpTransferCodingHeaderValueCollection TransferEncoding() const;
    Windows::Web::Http::Headers::HttpProductInfoHeaderValueCollection UserAgent() const;
    void Append(hstring_view name, hstring_view value) const;
    bool TryAppendWithoutValidation(hstring_view name, hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpResponseHeaderCollection
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> Age() const;
    void Age(const optional<Windows::Foundation::TimeSpan> & value) const;
    Windows::Web::Http::Headers::HttpMethodHeaderValueCollection Allow() const;
    Windows::Web::Http::Headers::HttpCacheDirectiveHeaderValueCollection CacheControl() const;
    Windows::Web::Http::Headers::HttpConnectionOptionHeaderValueCollection Connection() const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> Date() const;
    void Date(const optional<Windows::Foundation::DateTime> & value) const;
    Windows::Foundation::Uri Location() const;
    void Location(const Windows::Foundation::Uri & value) const;
    Windows::Web::Http::Headers::HttpChallengeHeaderValueCollection ProxyAuthenticate() const;
    Windows::Web::Http::Headers::HttpDateOrDeltaHeaderValue RetryAfter() const;
    void RetryAfter(const Windows::Web::Http::Headers::HttpDateOrDeltaHeaderValue & value) const;
    Windows::Web::Http::Headers::HttpTransferCodingHeaderValueCollection TransferEncoding() const;
    Windows::Web::Http::Headers::HttpChallengeHeaderValueCollection WwwAuthenticate() const;
    void Append(hstring_view name, hstring_view value) const;
    bool TryAppendWithoutValidation(hstring_view name, hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpTransferCodingHeaderValue
{
    Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue> Parameters() const;
    hstring Value() const;
};

template <typename D>
struct WINRT_EBO impl_IHttpTransferCodingHeaderValueCollection
{
    void ParseAdd(hstring_view input) const;
    bool TryParseAdd(hstring_view input) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpTransferCodingHeaderValueFactory
{
    Windows::Web::Http::Headers::HttpTransferCodingHeaderValue Create(hstring_view input) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpTransferCodingHeaderValueStatics
{
    Windows::Web::Http::Headers::HttpTransferCodingHeaderValue Parse(hstring_view input) const;
    bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpTransferCodingHeaderValue & transferCodingHeaderValue) const;
};

}

namespace impl {

template <> struct traits<Windows::Web::Http::Headers::IHttpCacheDirectiveHeaderValueCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpCacheDirectiveHeaderValueCollection;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpCacheDirectiveHeaderValueCollection<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpChallengeHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpChallengeHeaderValue;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpChallengeHeaderValue<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpChallengeHeaderValueCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpChallengeHeaderValueCollection;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpChallengeHeaderValueCollection<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpChallengeHeaderValueFactory>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpChallengeHeaderValueFactory;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpChallengeHeaderValueFactory<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpChallengeHeaderValueStatics>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpChallengeHeaderValueStatics;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpChallengeHeaderValueStatics<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValue;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpConnectionOptionHeaderValue<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValueCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValueCollection;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpConnectionOptionHeaderValueCollection<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValueFactory>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValueFactory;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpConnectionOptionHeaderValueFactory<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValueStatics>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValueStatics;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpConnectionOptionHeaderValueStatics<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpContentCodingHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpContentCodingHeaderValue;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpContentCodingHeaderValue<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpContentCodingHeaderValueCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpContentCodingHeaderValueCollection;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpContentCodingHeaderValueCollection<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpContentCodingHeaderValueFactory>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpContentCodingHeaderValueFactory;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpContentCodingHeaderValueFactory<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpContentCodingHeaderValueStatics>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpContentCodingHeaderValueStatics;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpContentCodingHeaderValueStatics<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValue;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpContentCodingWithQualityHeaderValue<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValueCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValueCollection;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpContentCodingWithQualityHeaderValueCollection<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValueFactory>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValueFactory;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpContentCodingWithQualityHeaderValueFactory<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValueStatics>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValueStatics;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpContentCodingWithQualityHeaderValueStatics<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpContentDispositionHeaderValue<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpContentDispositionHeaderValueFactory>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpContentDispositionHeaderValueFactory;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpContentDispositionHeaderValueFactory<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpContentDispositionHeaderValueStatics>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpContentDispositionHeaderValueStatics;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpContentDispositionHeaderValueStatics<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpContentHeaderCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpContentHeaderCollection;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpContentHeaderCollection<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpContentRangeHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpContentRangeHeaderValue;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpContentRangeHeaderValue<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpContentRangeHeaderValueFactory>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpContentRangeHeaderValueFactory;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpContentRangeHeaderValueFactory<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpContentRangeHeaderValueStatics>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpContentRangeHeaderValueStatics;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpContentRangeHeaderValueStatics<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpCookiePairHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpCookiePairHeaderValue;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpCookiePairHeaderValue<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpCookiePairHeaderValueCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpCookiePairHeaderValueCollection;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpCookiePairHeaderValueCollection<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpCookiePairHeaderValueFactory>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpCookiePairHeaderValueFactory;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpCookiePairHeaderValueFactory<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpCookiePairHeaderValueStatics>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpCookiePairHeaderValueStatics;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpCookiePairHeaderValueStatics<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpCredentialsHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpCredentialsHeaderValue;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpCredentialsHeaderValue<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpCredentialsHeaderValueFactory>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpCredentialsHeaderValueFactory;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpCredentialsHeaderValueFactory<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpCredentialsHeaderValueStatics>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpCredentialsHeaderValueStatics;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpCredentialsHeaderValueStatics<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpDateOrDeltaHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpDateOrDeltaHeaderValue;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpDateOrDeltaHeaderValue<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpDateOrDeltaHeaderValueStatics>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpDateOrDeltaHeaderValueStatics;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpDateOrDeltaHeaderValueStatics<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpExpectationHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpExpectationHeaderValue;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpExpectationHeaderValue<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpExpectationHeaderValueCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpExpectationHeaderValueCollection;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpExpectationHeaderValueCollection<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpExpectationHeaderValueFactory>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpExpectationHeaderValueFactory;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpExpectationHeaderValueFactory<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpExpectationHeaderValueStatics>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpExpectationHeaderValueStatics;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpExpectationHeaderValueStatics<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpLanguageHeaderValueCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpLanguageHeaderValueCollection;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpLanguageHeaderValueCollection<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValue;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpLanguageRangeWithQualityHeaderValue<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValueCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValueCollection;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpLanguageRangeWithQualityHeaderValueCollection<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValueFactory>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValueFactory;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpLanguageRangeWithQualityHeaderValueFactory<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValueStatics>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValueStatics;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpLanguageRangeWithQualityHeaderValueStatics<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpMediaTypeHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpMediaTypeHeaderValue;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpMediaTypeHeaderValue<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpMediaTypeHeaderValueFactory>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpMediaTypeHeaderValueFactory;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpMediaTypeHeaderValueFactory<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpMediaTypeHeaderValueStatics>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpMediaTypeHeaderValueStatics;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpMediaTypeHeaderValueStatics<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpMediaTypeWithQualityHeaderValue<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValueCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValueCollection;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpMediaTypeWithQualityHeaderValueCollection<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValueFactory>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValueFactory;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpMediaTypeWithQualityHeaderValueFactory<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValueStatics>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValueStatics;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpMediaTypeWithQualityHeaderValueStatics<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpMethodHeaderValueCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpMethodHeaderValueCollection;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpMethodHeaderValueCollection<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpNameValueHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpNameValueHeaderValue;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpNameValueHeaderValue<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpNameValueHeaderValueFactory>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpNameValueHeaderValueFactory;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpNameValueHeaderValueFactory<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpNameValueHeaderValueStatics>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpNameValueHeaderValueStatics;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpNameValueHeaderValueStatics<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpProductHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpProductHeaderValue;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpProductHeaderValue<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpProductHeaderValueFactory>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpProductHeaderValueFactory;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpProductHeaderValueFactory<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpProductHeaderValueStatics>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpProductHeaderValueStatics;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpProductHeaderValueStatics<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpProductInfoHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpProductInfoHeaderValue;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpProductInfoHeaderValue<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpProductInfoHeaderValueCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpProductInfoHeaderValueCollection;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpProductInfoHeaderValueCollection<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpProductInfoHeaderValueFactory>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpProductInfoHeaderValueFactory;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpProductInfoHeaderValueFactory<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpProductInfoHeaderValueStatics>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpProductInfoHeaderValueStatics;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpProductInfoHeaderValueStatics<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpRequestHeaderCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpRequestHeaderCollection<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpResponseHeaderCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpResponseHeaderCollection;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpResponseHeaderCollection<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpTransferCodingHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpTransferCodingHeaderValue;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpTransferCodingHeaderValue<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpTransferCodingHeaderValueCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpTransferCodingHeaderValueCollection;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpTransferCodingHeaderValueCollection<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpTransferCodingHeaderValueFactory>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpTransferCodingHeaderValueFactory;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpTransferCodingHeaderValueFactory<D>;
};

template <> struct traits<Windows::Web::Http::Headers::IHttpTransferCodingHeaderValueStatics>
{
    using abi = ABI::Windows::Web::Http::Headers::IHttpTransferCodingHeaderValueStatics;
    template <typename D> using consume = Windows::Web::Http::Headers::impl_IHttpTransferCodingHeaderValueStatics<D>;
};

template <> struct traits<Windows::Web::Http::Headers::HttpCacheDirectiveHeaderValueCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpCacheDirectiveHeaderValueCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpCacheDirectiveHeaderValueCollection"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpChallengeHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpChallengeHeaderValue;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpChallengeHeaderValue"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpChallengeHeaderValueCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpChallengeHeaderValueCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpChallengeHeaderValueCollection"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpConnectionOptionHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpConnectionOptionHeaderValue;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpConnectionOptionHeaderValue"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpConnectionOptionHeaderValueCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpConnectionOptionHeaderValueCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpConnectionOptionHeaderValueCollection"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpContentCodingHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpContentCodingHeaderValue;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpContentCodingHeaderValue"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpContentCodingHeaderValueCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpContentCodingHeaderValueCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpContentCodingHeaderValueCollection"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpContentCodingWithQualityHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpContentCodingWithQualityHeaderValue;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpContentCodingWithQualityHeaderValue"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpContentCodingWithQualityHeaderValueCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpContentCodingWithQualityHeaderValueCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpContentCodingWithQualityHeaderValueCollection"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpContentDispositionHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpContentDispositionHeaderValue;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpContentDispositionHeaderValue"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpContentHeaderCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpContentHeaderCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpContentHeaderCollection"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpContentRangeHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpContentRangeHeaderValue;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpContentRangeHeaderValue"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpCookiePairHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpCookiePairHeaderValue;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpCookiePairHeaderValue"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpCookiePairHeaderValueCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpCookiePairHeaderValueCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpCookiePairHeaderValueCollection"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpCredentialsHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpCredentialsHeaderValue;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpCredentialsHeaderValue"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpDateOrDeltaHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpDateOrDeltaHeaderValue;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpDateOrDeltaHeaderValue"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpExpectationHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpExpectationHeaderValue;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpExpectationHeaderValue"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpExpectationHeaderValueCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpExpectationHeaderValueCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpExpectationHeaderValueCollection"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpLanguageHeaderValueCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpLanguageHeaderValueCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpLanguageHeaderValueCollection"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValue;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpLanguageRangeWithQualityHeaderValue"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValueCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValueCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpLanguageRangeWithQualityHeaderValueCollection"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpMediaTypeHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpMediaTypeHeaderValue;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpMediaTypeHeaderValue"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValue;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpMediaTypeWithQualityHeaderValue"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValueCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValueCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpMediaTypeWithQualityHeaderValueCollection"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpMethodHeaderValueCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpMethodHeaderValueCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpMethodHeaderValueCollection"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpNameValueHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpNameValueHeaderValue;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpNameValueHeaderValue"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpProductHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpProductHeaderValue;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpProductHeaderValue"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpProductInfoHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpProductInfoHeaderValue;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpProductInfoHeaderValue"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpProductInfoHeaderValueCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpProductInfoHeaderValueCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpProductInfoHeaderValueCollection"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpRequestHeaderCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpRequestHeaderCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpRequestHeaderCollection"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpResponseHeaderCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpResponseHeaderCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpResponseHeaderCollection"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpTransferCodingHeaderValue>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpTransferCodingHeaderValue;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpTransferCodingHeaderValue"; }
};

template <> struct traits<Windows::Web::Http::Headers::HttpTransferCodingHeaderValueCollection>
{
    using abi = ABI::Windows::Web::Http::Headers::HttpTransferCodingHeaderValueCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Headers.HttpTransferCodingHeaderValueCollection"; }
};

}

}
