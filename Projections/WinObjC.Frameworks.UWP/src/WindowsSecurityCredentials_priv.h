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

// WindowsSecurityCredentials_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundationCollections_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsSecurityCryptographyCore_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsSystem_priv.h"
static ComPtr<ABI::Windows::Security::Credentials::IWebAccountProviderFactory> WSCIWebAccountProviderFactory_inst();
static ComPtr<ABI::Windows::Security::Credentials::IWebAccountFactory> WSCIWebAccountFactory_inst();
ComPtr<ABI::Windows::Security::Credentials::IKeyCredentialManagerStatics> WSCIKeyCredentialManagerStatics_inst();
static ComPtr<ABI::Windows::Security::Credentials::ICredentialFactory> WSCICredentialFactory_inst();

id RTProxiedNSArray_WSCPasswordCredential_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_NSString_create(IInspectable* val);

@class RTProxiedNSArray_WSCPasswordCredential, RTProxiedNSDictionary_NSString_NSString;
