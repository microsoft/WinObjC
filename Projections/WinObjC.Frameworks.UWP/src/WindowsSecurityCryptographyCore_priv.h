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

// WindowsSecurityCryptographyCore_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsStorageStreams_priv.h"
#include "WindowsSecurityCryptographyCertificates_priv.h"
ComPtr<ABI::Windows::Security::Cryptography::Core::IKeyDerivationParametersStatics2> WSCCIKeyDerivationParametersStatics2_inst();
ComPtr<ABI::Windows::Security::Cryptography::Core::IKeyDerivationParametersStatics> WSCCIKeyDerivationParametersStatics_inst();
ComPtr<ABI::Windows::Security::Cryptography::Core::IPersistedKeyProviderStatics> WSCCIPersistedKeyProviderStatics_inst();
ComPtr<ABI::Windows::Security::Cryptography::Core::ICryptographicEngineStatics2> WSCCICryptographicEngineStatics2_inst();
ComPtr<ABI::Windows::Security::Cryptography::Core::ICryptographicEngineStatics> WSCCICryptographicEngineStatics_inst();
ComPtr<ABI::Windows::Security::Cryptography::Core::IHashAlgorithmProviderStatics> WSCCIHashAlgorithmProviderStatics_inst();
ComPtr<ABI::Windows::Security::Cryptography::Core::IMacAlgorithmProviderStatics> WSCCIMacAlgorithmProviderStatics_inst();
ComPtr<ABI::Windows::Security::Cryptography::Core::IKeyDerivationAlgorithmProviderStatics>
WSCCIKeyDerivationAlgorithmProviderStatics_inst();
ComPtr<ABI::Windows::Security::Cryptography::Core::ISymmetricKeyAlgorithmProviderStatics> WSCCISymmetricKeyAlgorithmProviderStatics_inst();
ComPtr<ABI::Windows::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProviderStatics>
WSCCIAsymmetricKeyAlgorithmProviderStatics_inst();
ComPtr<ABI::Windows::Security::Cryptography::Core::IHashAlgorithmNamesStatics> WSCCIHashAlgorithmNamesStatics_inst();
ComPtr<ABI::Windows::Security::Cryptography::Core::IMacAlgorithmNamesStatics> WSCCIMacAlgorithmNamesStatics_inst();
ComPtr<ABI::Windows::Security::Cryptography::Core::ISymmetricAlgorithmNamesStatics> WSCCISymmetricAlgorithmNamesStatics_inst();
ComPtr<ABI::Windows::Security::Cryptography::Core::IAsymmetricAlgorithmNamesStatics> WSCCIAsymmetricAlgorithmNamesStatics_inst();
ComPtr<ABI::Windows::Security::Cryptography::Core::IAsymmetricAlgorithmNamesStatics2> WSCCIAsymmetricAlgorithmNamesStatics2_inst();
ComPtr<ABI::Windows::Security::Cryptography::Core::IEccCurveNamesStatics> WSCCIEccCurveNamesStatics_inst();
ComPtr<ABI::Windows::Security::Cryptography::Core::IKeyDerivationAlgorithmNamesStatics2> WSCCIKeyDerivationAlgorithmNamesStatics2_inst();
ComPtr<ABI::Windows::Security::Cryptography::Core::IKeyDerivationAlgorithmNamesStatics> WSCCIKeyDerivationAlgorithmNamesStatics_inst();

id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val);
id RTProxiedNSArray_NSString_create(IInspectable* val);

@class RTProxiedNSArray_C_UInt8, RTProxiedNSArray_NSString;
