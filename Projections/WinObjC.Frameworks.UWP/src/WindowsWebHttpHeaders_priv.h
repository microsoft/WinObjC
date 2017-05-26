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

// WindowsWebHttpHeaders_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsWebHttp_priv.h"
#include "WindowsNetworking_priv.h"
#include "WindowsGlobalization_priv.h"
static ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentDispositionHeaderValueFactory>
WWHHIHttpContentDispositionHeaderValueFactory_inst();
ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentDispositionHeaderValueStatics> WWHHIHttpContentDispositionHeaderValueStatics_inst();
static ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentRangeHeaderValueFactory> WWHHIHttpContentRangeHeaderValueFactory_inst();
ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentRangeHeaderValueStatics> WWHHIHttpContentRangeHeaderValueStatics_inst();
static ComPtr<ABI::Windows::Web::Http::Headers::IHttpMediaTypeHeaderValueFactory> WWHHIHttpMediaTypeHeaderValueFactory_inst();
ComPtr<ABI::Windows::Web::Http::Headers::IHttpMediaTypeHeaderValueStatics> WWHHIHttpMediaTypeHeaderValueStatics_inst();
static ComPtr<ABI::Windows::Web::Http::Headers::IHttpCredentialsHeaderValueFactory> WWHHIHttpCredentialsHeaderValueFactory_inst();
ComPtr<ABI::Windows::Web::Http::Headers::IHttpCredentialsHeaderValueStatics> WWHHIHttpCredentialsHeaderValueStatics_inst();
ComPtr<ABI::Windows::Web::Http::Headers::IHttpDateOrDeltaHeaderValueStatics> WWHHIHttpDateOrDeltaHeaderValueStatics_inst();
static ComPtr<ABI::Windows::Web::Http::Headers::IHttpNameValueHeaderValueFactory> WWHHIHttpNameValueHeaderValueFactory_inst();
ComPtr<ABI::Windows::Web::Http::Headers::IHttpNameValueHeaderValueStatics> WWHHIHttpNameValueHeaderValueStatics_inst();
static ComPtr<ABI::Windows::Web::Http::Headers::IHttpChallengeHeaderValueFactory> WWHHIHttpChallengeHeaderValueFactory_inst();
ComPtr<ABI::Windows::Web::Http::Headers::IHttpChallengeHeaderValueStatics> WWHHIHttpChallengeHeaderValueStatics_inst();
static ComPtr<ABI::Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValueFactory> WWHHIHttpConnectionOptionHeaderValueFactory_inst();
ComPtr<ABI::Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValueStatics> WWHHIHttpConnectionOptionHeaderValueStatics_inst();
static ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentCodingHeaderValueFactory> WWHHIHttpContentCodingHeaderValueFactory_inst();
ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentCodingHeaderValueStatics> WWHHIHttpContentCodingHeaderValueStatics_inst();
static ComPtr<ABI::Windows::Web::Http::Headers::IHttpCookiePairHeaderValueFactory> WWHHIHttpCookiePairHeaderValueFactory_inst();
ComPtr<ABI::Windows::Web::Http::Headers::IHttpCookiePairHeaderValueStatics> WWHHIHttpCookiePairHeaderValueStatics_inst();
static ComPtr<ABI::Windows::Web::Http::Headers::IHttpExpectationHeaderValueFactory> WWHHIHttpExpectationHeaderValueFactory_inst();
ComPtr<ABI::Windows::Web::Http::Headers::IHttpExpectationHeaderValueStatics> WWHHIHttpExpectationHeaderValueStatics_inst();
static ComPtr<ABI::Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValueFactory>
WWHHIHttpLanguageRangeWithQualityHeaderValueFactory_inst();
ComPtr<ABI::Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValueStatics>
WWHHIHttpLanguageRangeWithQualityHeaderValueStatics_inst();
static ComPtr<ABI::Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValueFactory>
WWHHIHttpMediaTypeWithQualityHeaderValueFactory_inst();
ComPtr<ABI::Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValueStatics>
WWHHIHttpMediaTypeWithQualityHeaderValueStatics_inst();
static ComPtr<ABI::Windows::Web::Http::Headers::IHttpProductHeaderValueFactory> WWHHIHttpProductHeaderValueFactory_inst();
ComPtr<ABI::Windows::Web::Http::Headers::IHttpProductHeaderValueStatics> WWHHIHttpProductHeaderValueStatics_inst();
static ComPtr<ABI::Windows::Web::Http::Headers::IHttpProductInfoHeaderValueFactory> WWHHIHttpProductInfoHeaderValueFactory_inst();
ComPtr<ABI::Windows::Web::Http::Headers::IHttpProductInfoHeaderValueStatics> WWHHIHttpProductInfoHeaderValueStatics_inst();
static ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValueFactory>
WWHHIHttpContentCodingWithQualityHeaderValueFactory_inst();
ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValueStatics>
WWHHIHttpContentCodingWithQualityHeaderValueStatics_inst();
static ComPtr<ABI::Windows::Web::Http::Headers::IHttpTransferCodingHeaderValueFactory> WWHHIHttpTransferCodingHeaderValueFactory_inst();
ComPtr<ABI::Windows::Web::Http::Headers::IHttpTransferCodingHeaderValueStatics> WWHHIHttpTransferCodingHeaderValueStatics_inst();

id RTProxiedNSMutableArray_WWHHHttpNameValueHeaderValue_create(IInspectable* val);

@class Nullable_Double, Nullable_UInt32, Nullable_UInt64, Nullable_WFDateTime, Nullable_WFTimeSpan,
    RTProxiedNSMutableArray_WWHHHttpNameValueHeaderValue;
