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

// WindowsSecurityCryptographyCertificates_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsNetworking_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsStorageStreams_priv.h"
static ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificateFactory> WSCCICertificateFactory_inst();
ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics2>
WSCCICertificateEnrollmentManagerStatics2_inst();
ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics>
WSCCICertificateEnrollmentManagerStatics_inst();
ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics3>
WSCCICertificateEnrollmentManagerStatics3_inst();
ComPtr<ABI::Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics2> WSCCIKeyAttestationHelperStatics2_inst();
ComPtr<ABI::Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics> WSCCIKeyAttestationHelperStatics_inst();
ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificateStoresStatics> WSCCICertificateStoresStatics_inst();
ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificateStoresStatics2> WSCCICertificateStoresStatics2_inst();
ComPtr<ABI::Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics>
WSCCIStandardCertificateStoreNamesStatics_inst();
ComPtr<ABI::Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics> WSCCIKeyAlgorithmNamesStatics_inst();
ComPtr<ABI::Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics2> WSCCIKeyAlgorithmNamesStatics2_inst();
ComPtr<ABI::Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics2> WSCCIKeyStorageProviderNamesStatics2_inst();
ComPtr<ABI::Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics> WSCCIKeyStorageProviderNamesStatics_inst();
static ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory> WSCCICmsAttachedSignatureFactory_inst();
ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureStatics> WSCCICmsAttachedSignatureStatics_inst();
static ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory> WSCCICmsDetachedSignatureFactory_inst();
ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureStatics> WSCCICmsDetachedSignatureStatics_inst();

id RTProxiedIterableNSArray_WSCCCertificate_create(IInspectable* val);
id RTProxiedIterableNSArray_WSCCCmsSignerInfo_create(IInspectable* val);
id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val);
id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_WSCCCertificate_create(IInspectable* val);
id RTProxiedNSArray_WSCCCmsSignerInfo_create(IInspectable* val);
id RTProxiedNSMutableArray_NSString_create(IInspectable* val);
id RTProxiedNSMutableArray_WSCCCertificate_create(IInspectable* val);

@class RTProxiedIterableNSArray_WSCCCertificate, RTProxiedIterableNSArray_WSCCCmsSignerInfo, RTProxiedNSArray_C_UInt8,
    RTProxiedNSArray_NSString;
@class RTProxiedNSArray_WSCCCertificate, RTProxiedNSArray_WSCCCmsSignerInfo, RTProxiedNSMutableArray_NSString,
    RTProxiedNSMutableArray_WSCCCertificate;
