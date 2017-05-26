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

// WindowsSecurityAuthenticationWebProvider_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsSecurityCryptographyCore_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsSecurityAuthenticationWebCore_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsSecurityCredentials_priv.h"
#include "WindowsWebHttp_priv.h"
#include "WindowsSecurityAuthenticationWeb_priv.h"
static ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebProviderTokenResponseFactory>
WSAWPIWebProviderTokenResponseFactory_inst();
static ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountClientViewFactory> WSAWPIWebAccountClientViewFactory_inst();
ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountManagerStatics2> WSAWPIWebAccountManagerStatics2_inst();
ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountScopeManagerStatics> WSAWPIWebAccountScopeManagerStatics_inst();
ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountMapManagerStatics> WSAWPIWebAccountMapManagerStatics_inst();
ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountManagerStatics> WSAWPIWebAccountManagerStatics_inst();

id RTProxiedNSArray_WSAWPWebAccountClientView_create(IInspectable* val);
id RTProxiedNSArray_WSCWebAccount_create(IInspectable* val);
id RTProxiedNSArray_WWHHttpCookie_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_NSString_create(IInspectable* val);
id RTProxiedNSMutableArray_WSAWPWebProviderTokenResponse_create(IInspectable* val);
id RTProxiedNSMutableArray_WWHHttpCookie_create(IInspectable* val);

@class RTProxiedNSArray_WSAWPWebAccountClientView, RTProxiedNSArray_WSCWebAccount, RTProxiedNSArray_WWHHttpCookie,
    RTProxiedNSDictionary_NSString_NSString;
@class RTProxiedNSMutableArray_WSAWPWebProviderTokenResponse, RTProxiedNSMutableArray_WWHHttpCookie;
