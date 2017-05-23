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

#include "Precompiled.h"
#include <MetaHost.h>
#include <MetadataScope.h>
#include <WinMDVerString.h>
#include <assert.h>

using namespace std;
using namespace Microsoft::WRL;

// Hard-coded the mscorlib strong name
const BYTE CMetadataScope::s_mscorlibStrongNameBlob[] = { 0xb7, 0x7a, 0x5c, 0x56, 0x19, 0x34, 0xe0, 0x89 };

// A generic assembly metadata struct.
const ASSEMBLYMETADATA CMetadataScope::s_genericMetadata = {
    // usMajorVersion - Unspecified major version
    0xFF,
    // usMinorVersion - Unspecified minor version
    0xFF,
    // usRevisionNumber - Unspecified revision number
    0xFF,
    // usBuildNumber - Unspecified build number
    0xFF,
    // szLocale - locale indepedence
    nullptr,
    // cbLocale
    0,
    // rProcessor - Processor independence
    nullptr,
    // ulProcessor
    0,
    // rOS - OS independence
    nullptr,
    // ulOS
    0,
};

//  Ensure that the metadata reader exists for this scope.
bool CMetadataScope::EnsureMetadataReader(PCWSTR pszFileName) {
    HRESULT hr;
    CComPtr<IUnknown> spUnk;

    hr = _spDispenser->OpenScope(pszFileName, ofRead | ofNoTransform, IID_IMetaDataAssemblyImport, &spUnk);
    if (FAILED(hr)) {
        if (hr == HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND) || hr == HRESULT_FROM_WIN32(ERROR_BAD_PATHNAME)) {
            return false;
        }

        throw CMetadataFormatError(this, hr);
    }
    hr = spUnk->QueryInterface(IID_IMetaDataImport2, reinterpret_cast<void**>(&_spReader));
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
    hr = _spReader->QueryInterface(IID_IMetaDataAssemblyImport, reinterpret_cast<void**>(&_spAssemblyReader));
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
    return true;
}

//  Ensure that the metadata writer exists for this scope.
bool CMetadataScope::EnsureMetadataWriter() {
    HRESULT hr;
    CComPtr<IUnknown> spUnk;

    CComVariant varVersion(WINMD_VERSION_STRING);
    hr = _spDispenser->SetOption(MetaDataRuntimeVersion, &varVersion);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }

    // Disable the optimization for local TypeRef tokens
    CComVariant varPreserveLocalRefs(MDPreserveLocalTypeRef, VT_UI4);
    hr = _spDispenser->SetOption(MetaDataPreserveLocalRefs, &varPreserveLocalRefs);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }

    hr = _spDispenser->DefineScope(CLSID_CorMetaDataRuntime, 0, IID_IMetaDataAssemblyEmit, &spUnk);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
    hr = spUnk->QueryInterface(IID_IMetaDataEmit2, reinterpret_cast<void**>(&_spWriter));
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
    hr = _spWriter->QueryInterface(IID_IMetaDataAssemblyEmit, reinterpret_cast<void**>(&_spAssemblyWriter));
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
    return true;
}

HMODULE MsCorEEModule = nullptr;
typedef HRESULT(STDAPICALLTYPE* ClrCoCreateInstanceFunc)(REFCLSID rclsid, REFIID riid, LPVOID* ppv);
ClrCoCreateInstanceFunc ClrGetCreateInstance = nullptr;

//  Create the metadata scope on the specified file.  Open it for
//  read-only or read/write mode.
bool CMetadataScope::CreateScope(ScopeType scScope) {
    HRESULT hr = E_FAIL;
    bool fReturnValue;

    {
        ComPtr<ICLRMetaHost> pMetaHost;
        ComPtr<ICLRRuntimeInfo> pRuntime;
        WCHAR wszClrVersion[] = L"v4.0.30319";

        if (MsCorEEModule == nullptr) {
            MsCorEEModule = ::LoadLibraryEx(L"mscoree.dll", NULL, 0);
            if (MsCorEEModule == nullptr) {
                throw HRESULT_FROM_WIN32(GetLastError());
            }
        }
        if (MsCorEEModule != nullptr && ClrGetCreateInstance == nullptr) {
            ClrGetCreateInstance = (ClrCoCreateInstanceFunc)GetProcAddress(MsCorEEModule, "CLRCreateInstance");
            if (ClrGetCreateInstance == nullptr) {
                throw HRESULT_FROM_WIN32(GetLastError());
            }
        }

        if (ClrGetCreateInstance != nullptr) {
            hr = ClrGetCreateInstance(CLSID_CLRMetaHost, IID_ICLRMetaHost, (void**)&pMetaHost);
            if (SUCCEEDED(hr)) {
                hr = pMetaHost->GetRuntime(wszClrVersion, IID_ICLRRuntimeInfo, (void**)&pRuntime);
                if (SUCCEEDED(hr)) {
                    hr = pRuntime->GetInterface(CLSID_CorMetaDataDispenser,
                                                IID_IMetaDataDispenserEx,
                                                reinterpret_cast<void**>(&_spDispenser));
                }
            }
        } else {
            hr = E_FAIL;
        }
    }
    //  We couldn't get the metadata dispenser using the current CLR mechanisms, try the legacy
    //  APIs.
    if (FAILED(hr) && FAILED(CoCreateInstance(CLSID_CorMetaDataDispenser,
                                              NULL,
                                              CLSCTX_INPROC,
                                              IID_IMetaDataDispenserEx,
                                              reinterpret_cast<void**>(&_spDispenser)))) {
        throw CMetadataFormatError(this, hr);
    }

    //
    //  For a read-only metadata file, we just want to ensure that the
    //  reader exists - the writer APIs don't need to be present.
    //
    if (scScope == ScopeType::ReadOnly) {
        fReturnValue = EnsureMetadataReader(_strFileName.c_str());
    } else {
        //
        //  If we're opening the metadata scope for read/write access,
        //  create a metadata emitter on the the file as well.
        //
        fReturnValue = EnsureMetadataWriter();
        if (fReturnValue) {
            hr = _spWriter->QueryInterface(IID_IMetaDataImport, reinterpret_cast<void**>(&_spReader));
            if (FAILED(hr)) {
                throw CMetadataFormatError(this, hr);
            }
            hr = _spReader->QueryInterface(IID_IMetaDataAssemblyImport, reinterpret_cast<void**>(&_spAssemblyReader));
            if (FAILED(hr)) {
                throw CMetadataFormatError(this, hr);
            }

            wstring strAssemblyFileName(_strFileName);
            size_t posEnd = strAssemblyFileName.find_last_of(c_pszExtensionSeparator);

            // WINDOWS#83329-2010/08/02-WAYNEZEN,
            // The path has to be removed from the assembly name as well.
            size_t posBegin = strAssemblyFileName.find_last_of('\\');
            if (posBegin == string::npos) {
                // No backslash found. Start from the beginning then.
                posBegin = 0;
            } else {
                // Otherwise start right after the last backslash.
                posBegin++;
            }

            wstring strAssemblyName = strAssemblyFileName.substr(posBegin, posEnd - posBegin);

            hr = _spAssemblyWriter->DefineAssembly(nullptr,
                                                   0, // Strong Name Token
                                                   c_Sha1_Hash_Algorithm, // Encryption algorithm
                                                   strAssemblyName.c_str(), // Assembly name
                                                   &s_genericMetadata, // Metainformation
                                                   c_WinRTAssemblyFlags, // Windows Runtime Metadata.
                                                   &_tkAssemblyWriter); // Assembly Writer token.
            if (FAILED(hr)) {
                throw CMetadataFormatError(this, hr);
            }

            hr = _spWriter->SetModuleProps(_strFileName.c_str());
            if (FAILED(hr)) {
                throw CMetadataFormatError(this, hr);
            }

            //
            //  Ensure that we have a metadata token created for
            //  mscorlib and for Windows.Foundation if necessary.
            //
            GetCommonTokenWriter(MSCORLIB);
        }
    }
    return fReturnValue;
}

//
//  Wrapper around IMetadataImport::EnumTypeDefs.
//  Returns: true if we should continue enumerating, false if we're
//  done.
//
//  If the API fails, we throw an exception.
//
bool CMetadataScope::EnumTypeDefs(__inout HCORENUM* hce,
                                  __out_ecount_part(cTypes, *pcTypeDefs) mdTypeDef* rgTypeDef,
                                  ULONG cTypes,
                                  __out ULONG* pcTypeDefs) {
    HRESULT hr = _spReader->EnumTypeDefs(hce, rgTypeDef, cTypes, pcTypeDefs);
    if (hr == S_FALSE) {
        return false;
    }
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
    return true;
}

//
//  Wrapper around IMetadataImport::EnumTypeDefs.
//  Returns: true if we should continue enumerating, false if we're
//  done.
//
//  If the API fails, we throw an exception.
//
bool CMetadataScope::EnumTypeRefs(__inout HCORENUM* hce,
                                  __out_ecount_part(cTypes, *pcTypeRefs) mdTypeRef* rgTypeRef,
                                  ULONG cTypes,
                                  __out ULONG* pcTypeRefs) {
    HRESULT hr = _spReader->EnumTypeRefs(hce, rgTypeRef, cTypes, pcTypeRefs);
    if (hr == S_FALSE) {
        return false;
    }
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
    return true;
}
bool CMetadataScope::EnumGenericParams(__inout HCORENUM* phEnum,
                                       __in mdToken tk,
                                       __out_ecount_part(cMax, *pcGenericParams) mdGenericParam rgGenericParams[],
                                       __in ULONG cMax,
                                       __out ULONG* pcGenericParams) {
    HRESULT hr = _spReader->EnumGenericParams(phEnum, tk, rgGenericParams, cMax, pcGenericParams);
    if (hr == S_FALSE) {
        return false;
    }
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
    return true;
}
//
bool CMetadataScope::EnumMethods(__inout HCORENUM* hce,
                                 __in mdTypeDef tkType,
                                 __out_ecount_part(cMethods, *pcMethodDefs) mdMethodDef* rgMethodDef,
                                 __in ULONG cMethods,
                                 __out ULONG* pcMethodDefs) {
    HRESULT hr = _spReader->EnumMethods(hce, tkType, rgMethodDef, cMethods, pcMethodDefs);
    if (hr == S_FALSE) {
        return false;
    }
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
    return true;
}

bool CMetadataScope::EnumAssemblyRefs(_Inout_ HCORENUM* hce,
                                      _Out_writes_to_(cAssemblyRefs, *pcAssemblyRefs) mdAssemblyRef* rgAssemblyRefs,
                                      _In_ ULONG cAssemblyRefs,
                                      _Out_opt_ ULONG* pcAssemblyRefs) {
    HRESULT hr = _spAssemblyReader->EnumAssemblyRefs(hce, rgAssemblyRefs, cAssemblyRefs, pcAssemblyRefs);
    if (hr == S_FALSE) {
        return false;
    }

    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }

    return true;
}

bool CMetadataScope::EnumExportedTypes(_Inout_ HCORENUM* hce,
                                       _Out_writes_to_(cMax, *pcTokens) mdExportedType* rgExportedTypes,
                                       _In_ ULONG cMax,
                                       _Out_opt_ ULONG* pcTokens) {
    HRESULT hr = _spAssemblyReader->EnumExportedTypes(hce, rgExportedTypes, cMax, pcTokens);
    if (hr == S_FALSE) {
        return false;
    }
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
    return true;
}

bool CMetadataScope::EnumFiles(_Inout_ HCORENUM* hce,
                               _Out_writes_to_(cMax, *pcTokens) mdFile* rgFiles,
                               _In_ ULONG cMax,
                               _Out_opt_ ULONG* pcTokens) {
    HRESULT hr = _spAssemblyReader->EnumFiles(hce, rgFiles, cMax, pcTokens);
    if (hr == S_FALSE) {
        return false;
    }
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
    return true;
}

bool CMetadataScope::EnumManifestResources(_Inout_ HCORENUM* hce,
                                           _Out_writes_to_(cMax, *pcTokens) mdManifestResource* rgManifestResources,
                                           _In_ ULONG cMax,
                                           _Out_opt_ ULONG* pcTokens) {
    HRESULT hr = _spAssemblyReader->EnumManifestResources(hce, rgManifestResources, cMax, pcTokens);
    if (hr == S_FALSE) {
        return false;
    }
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
    return true;
}

//
bool CMetadataScope::EnumMethodImpls(__inout HCORENUM* hce,
                                     __in mdTypeDef tkType,
                                     __out_ecount_part(cMethods, *pcMethodDefs) mdToken* rgMethodBody,
                                     __out_ecount_part(cMethods, *pcMethodDefs) mdToken* rgMethodDecl,
                                     __in ULONG cMethods,
                                     __out ULONG* pcMethodDefs) {
    HRESULT hr = _spReader->EnumMethodImpls(hce, tkType, rgMethodBody, rgMethodDecl, cMethods, pcMethodDefs);
    if (hr == S_FALSE) {
        return false;
    }
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
    return true;
}
//
bool CMetadataScope::EnumFields(__inout HCORENUM* hce,
                                __in mdTypeDef tkType,
                                __out_ecount_part(cFields, *pcFields) mdFieldDef* rgFields,
                                __in ULONG cFields,
                                __out ULONG* pcFields) {
    HRESULT hr = _spReader->EnumFields(hce, tkType, rgFields, cFields, pcFields);
    if (hr == S_FALSE) {
        return false;
    }
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
    return true;
}

//
//  Wrapper around IMetadataImport::EnumInterfaceImpls
//  Returns: true if we should continue enumerating, false if we're
//  done.
//
//  If the API fails, we throw an exception.
//
bool CMetadataScope::EnumInterfaceImpls(__inout HCORENUM* hce,
                                        __in mdTypeDef td,
                                        __out_ecount_part(cTypes, *pcTypeDefs) mdInterfaceImpl* rgTypeDef,
                                        __in ULONG cTypes,
                                        __out ULONG* pcTypeDefs) {
    HRESULT hr = _spReader->EnumInterfaceImpls(hce, td, rgTypeDef, cTypes, pcTypeDefs);
    if (hr == S_FALSE) {
        return false;
    }
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
    return true;
}

//
//  Wrapper around IMetadataImport::EnumCustomAttributes
//  Returns: true if we should continue enumerating, false if we're
//  done.
//
//  If the API fails, we throw an exception.
//
bool CMetadataScope::EnumCustomAttributes(__inout HCORENUM* hce,
                                          mdTypeDef tkType,
                                          mdToken tkElement,
                                          __out_ecount_part(cAttributes, *pcAttributes) mdCustomAttribute* rgAttributes,
                                          ULONG cAttributes,
                                          __out ULONG* pcAttributes) {
    HRESULT hr = _spReader->EnumCustomAttributes(hce, tkType, tkElement, rgAttributes, cAttributes, pcAttributes);
    if (hr == S_FALSE) {
        return false;
    }
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
    return true;
}

//
//  Wrapper around IMetadataImport::EnumParams
//  Returns: true if we should continue enumerating, false if we're
//  done.
//
//  If the API fails, we throw an exception.
//
bool CMetadataScope::EnumParams(__inout HCORENUM* hce,
                                mdMethodDef tkMethod,
                                __out_ecount_part(cParams, *pcParams) mdCustomAttribute* rgParams,
                                ULONG cParams,
                                __out ULONG* pcParams) {
    HRESULT hr = _spReader->EnumParams(hce, tkMethod, rgParams, cParams, pcParams);
    if (hr == S_FALSE) {
        return false;
    }
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
    return true;
}

//
//  Wrapper around IMetadataImport::EnumProperties
//  Returns: true if we should continue enumerating, false if we're
//  done.
//
//  If the API fails, we throw an exception.
//
bool CMetadataScope::EnumProperties(__inout HCORENUM* hce,
                                    __in mdTypeDef td,
                                    __out_ecount_part(cMax, *pcProperties) mdProperty rProperties[],
                                    __in ULONG cMax,
                                    __out ULONG* pcProperties) {
    HRESULT hr = _spReader->EnumProperties(hce, td, rProperties, cMax, pcProperties);
    if (hr == S_FALSE) {
        return false;
    }
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
    return true;
}

//
//  Wrapper around IMetadataImport::EnumEvents
//  Returns: true if we should continue enumerating, false if we're
//  done.
//
//  If the API fails, we throw an exception.
//
bool CMetadataScope::EnumEvents(__inout HCORENUM* hce,
                                __in mdTypeDef td,
                                __out_ecount_part(cMax, *pcEvents) mdEvent rEvents[],
                                __in ULONG cMax,
                                __out ULONG* pcEvents) {
    HRESULT hr = _spReader->EnumEvents(hce, td, rEvents, cMax, pcEvents);
    if (hr == S_FALSE) {
        return false;
    }
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
    return true;
}
//
//  Wrapper around IMetadataImport::EnumMethodSemantics
//  Returns: true if we should continue enumerating, false if we're
//  done.
//
//  If the API fails, we throw an exception.
//
bool CMetadataScope::EnumMethodSemantics(__inout HCORENUM* hce,
                                         __in mdMethodDef tkMethod,
                                         __out_ecount_part(cMax, *pcEventProp) mdToken* rgEventProp,
                                         __in ULONG cMax,
                                         __out ULONG* pcEventProp) {
    HRESULT hr = _spReader->EnumMethodSemantics(hce, tkMethod, rgEventProp, cMax, pcEventProp);
    if (hr == S_FALSE) {
        return false;
    }
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
    return true;
}

//
//  Wrapper around IMetadataImport::DefineField
//  Returns: true if we should continue enumerating, false if we're
//  done.
//
//  If the API fails, we throw an exception.
//
void CMetadataScope::DefineField(__in mdTypeDef td,
                                 __in PCWSTR szName,
                                 __in DWORD dwFieldFlags,
                                 __in_bcount(cbSigBlob) PCCOR_SIGNATURE pvSigBlob,
                                 __in ULONG cbSigBlob,
                                 __in DWORD dwCPlusTypeFlag,
                                 __in_bcount(cchValue) void const* pValue,
                                 __in ULONG cchValue,
                                 __out mdFieldDef* pmd) {
    HRESULT hr = _spWriter->DefineField(td, szName, dwFieldFlags, pvSigBlob, cbSigBlob, dwCPlusTypeFlag, pValue, cchValue, pmd);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}

void CMetadataScope::DefineProperty(__in mdTypeDef td,
                                    __in PCWSTR szProperty,
                                    __in DWORD dwPropFlags,
                                    __in PCCOR_SIGNATURE pvSig,
                                    __in ULONG cbSig,
                                    __in DWORD dwCPlusTypeFlag,
                                    __in_bcount(cchValue) void const* pValue,
                                    __in ULONG cchValue,
                                    __in mdMethodDef mdSetter,
                                    __in mdMethodDef mdGetter,
                                    __in mdMethodDef rmdOtherMethods[],
                                    __out mdProperty* pmdProp) {
    HRESULT hr = _spWriter->DefineProperty(
        td, szProperty, dwPropFlags, pvSig, cbSig, dwCPlusTypeFlag, pValue, cchValue, mdSetter, mdGetter, rmdOtherMethods, pmdProp);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}

void CMetadataScope::DefineEvent(__in mdTypeDef td,
                                 __in PCWSTR szEvent,
                                 __in DWORD dwEventFlags,
                                 __in mdToken tkEventType,
                                 __in mdMethodDef mdAddOn,
                                 __in mdMethodDef mdRemoveOn,
                                 __in mdMethodDef mdFireOn,
                                 __in mdMethodDef rmdOtherMethods[],
                                 __out mdEvent* pmdProp) {
    HRESULT hr = _spWriter->DefineEvent(td, szEvent, dwEventFlags, tkEventType, mdAddOn, mdRemoveOn, mdFireOn, rmdOtherMethods, pmdProp);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}

void CMetadataScope::DefineCustomAttribute(__in mdToken tkObj,
                                           __in mdToken tkType,
                                           __in_bcount(cbCustomAttribute) void const* pCustomAttribute,
                                           __in ULONG cbCustomAttribute,
                                           __out mdCustomAttribute* pcv) {
    HRESULT hr = _spWriter->DefineCustomAttribute(tkObj, tkType, pCustomAttribute, cbCustomAttribute, pcv);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}

//
//  Wrapper around IMetadataImport::DefineMethod
//  Returns: true if we should continue enumerating, false if we're
//  done.
//
//  If the API fails, we throw an exception.
//
void CMetadataScope::DefineMethod(__in mdTypeDef td,
                                  __in PCWSTR szName,
                                  __in DWORD dwMethodFlags,
                                  __in PCCOR_SIGNATURE pvSigBlob,
                                  __in ULONG cbSigBlob,
                                  __in ULONG ulCodeRVA,
                                  __in DWORD dwImplFlags,
                                  __out mdMethodDef* pmd) {
    HRESULT hr = _spWriter->DefineMethod(td, szName, dwMethodFlags, pvSigBlob, cbSigBlob, ulCodeRVA, dwImplFlags, pmd);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}

//
//  Wrapper around IMetadataImport::DefineMethodImpl
//  Returns: true if we should continue enumerating, false if we're
//  done.
//
//  If the API fails, we throw an exception.
//
void CMetadataScope::DefineMethodImpl(__in mdTypeDef td, __in mdToken tkMethodBody, __in mdToken tkMethodDecl) {
    HRESULT hr = _spWriter->DefineMethodImpl(td, tkMethodBody, tkMethodDecl);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}

void CMetadataScope::DefineParam(__in mdMethodDef md,
                                 __in ULONG ulParamSeq,
                                 __in PCWSTR szName,
                                 __in DWORD dwParamFlags,
                                 __in DWORD dwCPlusTypeFlag,
                                 __in_bcount(cchValue) void const* pValue,
                                 __in ULONG cchValue,
                                 __out mdParamDef* ppd) {
    HRESULT hr = _spWriter->DefineParam(md, ulParamSeq, szName, dwParamFlags, dwCPlusTypeFlag, pValue, cchValue, ppd);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}

void CMetadataScope::DefineGenericParam(__in mdToken tk,
                                        __in ULONG ulParamSeq,
                                        __in DWORD dwParamFlags,
                                        __in LPCWSTR szname,
                                        __in DWORD reserved,
                                        __in mdToken rtkConstraints[],
                                        __out mdGenericParam* pgp) {
    HRESULT hr = _spWriter->DefineGenericParam(tk, ulParamSeq, dwParamFlags, szname, reserved, rtkConstraints, pgp);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}

bool CMetadataScope::GetCustomAttributeByName(mdToken tkObj, // [IN] Object with Custom Attribute.
                                              LPCWSTR szName, // [IN] Name of desired Custom Attribute.
                                              const void** ppData, // [OUT] Put pointer to data here.
                                              ULONG* pcbData) // [OUT] Put size of data here.
{
    HRESULT hr = _spReader->GetCustomAttributeByName(tkObj, szName, ppData, pcbData);
    if (FAILED(hr)) {
        if (hr == CLDB_E_RECORD_NOTFOUND) {
            return false;
        }
        throw CMetadataFormatError(this, hr);
    }
    if (hr == S_FALSE) // GetCustomAttributeByName returns S_FALSE if the attribute is not found.
    {
        return false;
    }
    return true;
}

bool CMetadataScope::GetParamForMethodIndex( // S_OK or error.
    mdMethodDef md, // [IN] Method token.
    ULONG ulParamSeq, // [IN] Parameter sequence.
    mdParamDef* ppd) // [IN] Put Param token here.
{
    *ppd = mdTokenNil;

    HRESULT hr = _spReader->GetParamForMethodIndex(md, ulParamSeq, ppd);
    if (hr == CLDB_E_RECORD_NOTFOUND) {
        return false;
    } else if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
    return true;
}

void CMetadataScope::GetNameFromToken(mdToken tk, MDUTF8CSTR* pszUtf8NamePtr) {
    HRESULT hr = _spReader->GetNameFromToken(tk, pszUtf8NamePtr);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}

//
//  Wrapper around IMetadataImport::GetScopeProps
//
void CMetadataScope::GetScopeProps(_Out_writes_to_opt_(cchName, *pchName) LPWSTR szName, // [OUT] Put the name here.
                                   ULONG cchName, // [IN] Size of name buffer in wide chars.
                                   ULONG* pchName, // [OUT] Put size of name (wide chars) here.
                                   GUID* pmvid) // [OUT, OPTIONAL] Put MVID here.
{
    HRESULT hr = _spReader->GetScopeProps(szName, cchName, pchName, pmvid);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}

//
//  Wrapper around IMetadataImport::GetTypeDefProps
//  Returns: Nothing.
//
//  If the API fails, we throw an exception.
//
void CMetadataScope::GetTypeDefProps(__in mdTypeDef td,
                                     __out_ecount_part_opt(cchTypeDef, *pchTypeDef) PWSTR szTypeDef,
                                     __in ULONG cchTypeDef,
                                     __out_opt ULONG* pchTypeDef,
                                     __out_opt DWORD* pdwTypeDefFlags,
                                     __out_opt mdToken* ptkExtends)

{
    HRESULT hr = _spReader->GetTypeDefProps(td, szTypeDef, cchTypeDef, pchTypeDef, pdwTypeDefFlags, ptkExtends);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}

//
//  Wrapper around IMetadataImport::GetTypeDefProps
//  Returns: Nothing.
//
//  If the API fails, we throw an exception.
//
void CMetadataScope::GetTypeRefProps(_In_ mdTypeRef tr, // [IN] TypeRef token.
                                     _Out_opt_ mdToken* ptkResolutionScope, // [OUT] Resolution scope, ModuleRef or AssemblyRef.
                                     _Out_writes_to_opt_(cchName, *pchName) LPWSTR szName, // [OUT] Name of the TypeRef.
                                     _In_ ULONG cchName, // [IN] Size of buffer.
                                     _Out_opt_ ULONG* pchName) // [OUT] Size of Name.
{
    HRESULT hr = _spReader->GetTypeRefProps(tr, ptkResolutionScope, szName, cchName, pchName);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}

//
//  Wrapper around IMetadataImport::GetTypeDefProps
//  Returns: Nothing.
//
//  If the API fails, we throw an exception.
//
void CMetadataScope::GetCustomAttributeProps(__in mdCustomAttribute cv,
                                             __out_opt mdToken* ptkObj,
                                             __out_opt mdToken* ptkType,
                                             __out_opt void const** ppBlob,
                                             __out_opt ULONG* pcbSize) {
    HRESULT hr = _spReader->GetCustomAttributeProps(cv, ptkObj, ptkType, ppBlob, pcbSize);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}
void CMetadataScope::SetTypeDefProps(__in mdTypeDef td, __in DWORD dwTypeDefFlags, __in mdToken tkExtends, __in mdToken rtkImplements[]) {
    HRESULT hr = _spWriter->SetTypeDefProps(td, dwTypeDefFlags, tkExtends, rtkImplements);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}

//  Wrapper around IMetadataImport::GetFieldProps
//  Returns: Nothing.
//
//  If the API fails, we throw an exception.
//
void CMetadataScope::GetFieldProps(__in mdFieldDef mb,
                                   __out_opt mdTypeDef* pClass,
                                   __out_ecount_part_opt(cchField, *pchField) PWSTR szField,
                                   __in ULONG cchField,
                                   __out_opt ULONG* pchField,
                                   __out_opt DWORD* pdwAttr,
                                   __out_opt PCCOR_SIGNATURE* ppvSigBlob,
                                   __out_opt ULONG* pcbSigBlob,
                                   __out_opt DWORD* pdwCPlusTypeFlag,
                                   __out_opt UVCP_CONSTANT* ppValue,
                                   __out_opt ULONG* pcchValue) {
    HRESULT hr =
        _spReader
            ->GetFieldProps(mb, pClass, szField, cchField, pchField, pdwAttr, ppvSigBlob, pcbSigBlob, pdwCPlusTypeFlag, ppValue, pcchValue);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}
void CMetadataScope::GetMethodProps(__in mdMethodDef mb,
                                    __out_opt mdTypeDef* pClass,
                                    __out_ecount_part_opt(cchMethod, *pchMethod) PWSTR szMethod,
                                    __in ULONG cchMethod,
                                    __out_opt ULONG* pchMethod,
                                    __out_opt DWORD* pdwAttr,
                                    __out_opt PCCOR_SIGNATURE* ppvSigBlob,
                                    __out_opt ULONG* pcbSigBlob,
                                    __out_opt ULONG* pulCodeRVA,
                                    __out_opt DWORD* pdwImplFlags) {
    HRESULT hr =
        _spReader->GetMethodProps(mb, pClass, szMethod, cchMethod, pchMethod, pdwAttr, ppvSigBlob, pcbSigBlob, pulCodeRVA, pdwImplFlags);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}

void CMetadataScope::GetParamProps(__in mdParamDef tk,
                                   __out_opt mdMethodDef* pmd,
                                   __out_opt ULONG* pulSequence,
                                   __out_ecount_part_opt(cchName, *pchName) PWSTR szName,
                                   __in ULONG cchName,
                                   __out_opt ULONG* pchName,
                                   __out_opt DWORD* pdwAttr,
                                   __out_opt DWORD* pdwCPlusTypeFlag,
                                   __out_opt UVCP_CONSTANT* ppValue,
                                   __out_opt ULONG* pcchValue) {
    HRESULT hr = _spReader->GetParamProps(tk, pmd, pulSequence, szName, cchName, pchName, pdwAttr, pdwCPlusTypeFlag, ppValue, pcchValue);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}
//
//  Wrapper around IMetadataEmit::GetFieldMarshal.
//
//  Note that this function is different from the other wrapper
//  functions.  Since the field marshal table isn't present for all
//  parameters, this returns true if the field marshal signature was
//  successfully retrieved, false otherwise.
//
bool CMetadataScope::GetFieldMarshal(__in mdToken tk,
                                     __out_bcount_part_opt(*pcbNativeType, *pcbNativeType) PCCOR_SIGNATURE* ppvNativeType,
                                     __out_opt ULONG* pcbNativeType) {
    HRESULT hr = _spReader->GetFieldMarshal(tk, ppvNativeType, pcbNativeType);
    if (FAILED(hr)) {
        if (hr == CLDB_E_RECORD_NOTFOUND) {
            return false;
        }
        throw CMetadataFormatError(this, hr);
    }
    return true;
}

void CMetadataScope::SetFieldMarshal(__in mdToken tk, __in_ecount(cbNativeType) PCCOR_SIGNATURE pvNativeType, __in ULONG cbNativeType) {
    HRESULT hr = _spWriter->SetFieldMarshal(tk, pvNativeType, cbNativeType);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}

void CMetadataScope::GetMethodSemantics(__in mdToken tk, __in mdToken tkEventProp, __out_opt DWORD* pdwSemanticsFlags) {
    HRESULT hr = _spReader->GetMethodSemantics(tk, tkEventProp, pdwSemanticsFlags);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}

void CMetadataScope::GetMemberRefProps(__in mdMemberRef mr,
                                       __out_opt mdToken* ptk,
                                       __out_ecount_part_opt(cchMember, *pchMember) PWSTR szMember,
                                       __in ULONG cchMember,
                                       __out_opt ULONG* pchMember,
                                       __out_opt PCCOR_SIGNATURE* ppvSigBlob,
                                       __out_opt ULONG* pbSig) {
    HRESULT hr = _spReader->GetMemberRefProps(mr, ptk, szMember, cchMember, pchMember, ppvSigBlob, pbSig);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}

void CMetadataScope::GetMemberProps(__in mdToken mb, // The member for which to get props.
                                    __in mdTypeDef* pClass, // Put member's class here.
                                    __out_ecount_part_opt(cchMember, *pchMember) LPWSTR szMember, // Put member's name here.
                                    __in ULONG cchMember, // Size of szMember buffer in wide chars.
                                    __out_opt ULONG* pchMember, // Put actual size here
                                    __out_opt DWORD* pdwAttr, // Put flags here.
                                    __out_opt PCCOR_SIGNATURE* ppvSigBlob, // [OUT] point to the blob value of meta data
                                    __out_opt ULONG* pcbSigBlob, // [OUT] actual size of signature blob
                                    __out_opt ULONG* pulCodeRVA, // [OUT] codeRVA
                                    __out_opt DWORD* pdwImplFlags, // [OUT] Impl. Flags
                                    __out_opt DWORD* pdwCPlusTypeFlag, // [OUT] flag for value type. selected ELEMENT_TYPE_*
                                    __out_opt UVCP_CONSTANT* ppValue, // [OUT] constant value
                                    __out_opt ULONG* pcchValue) // [OUT] size of constant string in chars, 0 for non-strings.
{
    HRESULT hr = _spReader->GetMemberProps(mb,
                                           pClass,
                                           szMember,
                                           cchMember,
                                           pchMember,
                                           pdwAttr,
                                           ppvSigBlob,
                                           pcbSigBlob,
                                           pulCodeRVA,
                                           pdwImplFlags,
                                           pdwCPlusTypeFlag,
                                           ppValue,
                                           pcchValue);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}

void CMetadataScope::GetPropertyProps(__in mdProperty prop,
                                      __out_opt mdTypeDef* pClass,
                                      __out_ecount_part_opt(cchProperty, *pchProperty) PWSTR szProperty,
                                      __in ULONG cchProperty,
                                      __deref_out_range(0, cchProperty) __maybenull ULONG* pchProperty,
                                      __out_opt DWORD* pdwPropFlags,
                                      __out_opt PCCOR_SIGNATURE* ppvSig,
                                      __out_opt ULONG* pbSig,
                                      __out_opt DWORD* pdwCPlusTypeFlag,
                                      __out_opt UVCP_CONSTANT* ppDefaultValue,
                                      __out_opt ULONG* pcchDefaultValue,
                                      __out_opt mdMethodDef* pmdSetter,
                                      __out_opt mdMethodDef* pmdGetter,
                                      __out_ecount_part_opt(cMax, *pcOtherMethod) mdMethodDef rmdOtherMethod[],
                                      __in ULONG cMax,
                                      __deref_out_range(0, cMax) __maybenull ULONG* pcOtherMethod) {
    HRESULT hr = _spReader->GetPropertyProps(prop,
                                             pClass,
                                             szProperty,
                                             cchProperty,
                                             pchProperty,
                                             pdwPropFlags,
                                             ppvSig,
                                             pbSig,
                                             pdwCPlusTypeFlag,
                                             ppDefaultValue,
                                             pcchDefaultValue,
                                             pmdSetter,
                                             pmdGetter,
                                             rmdOtherMethod,
                                             cMax,
                                             pcOtherMethod);
    if (FAILED(hr)) {
        __analysis_assume(*pcOtherMethod <= cMax);
        __analysis_assume(*pchProperty <= cchProperty);
        throw CMetadataFormatError(this, hr);
    }
}

void CMetadataScope::GetEventProps(__in mdEvent ev,
                                   __out_opt mdTypeDef* pClass,
                                   __out_ecount_part_opt(cchEvent, *pchEvent) PWSTR szEvent,
                                   __in ULONG cchEvent,
                                   __deref_out_range(0, cchProperty) __maybenull ULONG* pchEvent,
                                   __out_opt DWORD* pdwEventFlags,
                                   __out_opt mdToken* ptkEventType,
                                   __out_opt mdMethodDef* pmdAddOn,
                                   __out_opt mdMethodDef* pmdRemoveOn,
                                   __out_opt mdMethodDef* pmdFire,
                                   __out_ecount_part_opt(cMax, *pcOtherMethod) mdMethodDef rmdOtherMethod[],
                                   __in ULONG cMax,
                                   __deref_out_range(0, cMax) __maybenull ULONG* pcOtherMethod) {
    HRESULT hr = _spReader->GetEventProps(ev,
                                          pClass,
                                          szEvent,
                                          cchEvent,
                                          pchEvent,
                                          pdwEventFlags,
                                          ptkEventType,
                                          pmdAddOn,
                                          pmdRemoveOn,
                                          pmdFire,
                                          rmdOtherMethod,
                                          cMax,
                                          pcOtherMethod);
    if (FAILED(hr)) {
        __analysis_assume(*pcOtherMethod <= cMax);
        __analysis_assume(*pchEvent <= cchEvent);
        throw CMetadataFormatError(this, hr);
    }
}

// Wrapper around IMetadataEmit::GetTokenFromTypeSpec
void CMetadataScope::GetTokenFromTypeSpec(__in PCCOR_SIGNATURE pvSig, __in ULONG cbSig, __out mdTypeSpec* ptypespec) {
    HRESULT hr = _spWriter->GetTokenFromTypeSpec(pvSig, cbSig, ptypespec);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}

void CMetadataScope::GetTypeSpecFromToken(__in mdTypeSpec typespec, __out PCCOR_SIGNATURE* ppvSig, __out ULONG* pcbSig) {
    HRESULT hr = _spReader->GetTypeSpecFromToken(typespec, ppvSig, pcbSig);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}

//
//  Wrapper around IMetadataImport::GetInterfaceImplProps
//  Returns: Nothing.
//
//  If the API fails, we throw an exception.
//
void CMetadataScope::GetInterfaceImplProps(__in mdInterfaceImpl tkIimpl, __out_opt mdTypeDef* ptkClass, __out_opt mdToken* ptkIface)

{
    HRESULT hr = _spReader->GetInterfaceImplProps(tkIimpl, ptkClass, ptkIface);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}

void CMetadataScope::GetGenericParamProps(__in mdGenericParam gp,
                                          __in ULONG* pulParamSeq,
                                          __out_opt DWORD* pdwParamFlags,
                                          __out_opt mdToken* ptOwner,
                                          __out_opt DWORD* reserved,
                                          __out_ecount_part_opt(cchName, *pchName) LPWSTR wzname,
                                          ULONG cchName,
                                          __out_opt ULONG* pchName) {
    HRESULT hr = _spReader->GetGenericParamProps(gp, pulParamSeq, pdwParamFlags, ptOwner, reserved, wzname, cchName, pchName);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}

//  Wrapper around IMetadataEmit::DefineTypeDef
//  Returns: Nothing.
//
//  If the API fails, we throw an exception.
//
void CMetadataScope::DefineTypeDef(
    __in PCWSTR pszTypeDef, __in DWORD dwTypeDefFlags, __in mdToken tkExtends, __in_opt mdToken rtkImplements[], __out mdTypeDef* ptd) {
    HRESULT hr = _spWriter->DefineTypeDef(pszTypeDef, dwTypeDefFlags, tkExtends, rtkImplements, ptd);

    if (SUCCEEDED(hr) && IsRedirectedType(wstring(pszTypeDef))) {
        // Now we want to define a companion TypeRef for this TypeDef.
        mdToken tkModule = mdTokenNil;
        HRESULT hr;
        if (FAILED(hr = GetModuleFromCurrentScope((&tkModule)))) {
            throw CMetadataFormatError(this, hr);
        }

        mdToken tkTypeRef;
        if (FAILED(hr = _spWriter->DefineTypeRefByName(tkModule, pszTypeDef, &tkTypeRef))) {
            throw CMetadataFormatError(this, hr);
        }
    }

    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}

//  Wrapper around IMetadataEmit::DefineTypeRefByName
//  Returns: Nothing.
//
//  If the API fails, we throw an exception.
//
void CMetadataScope::DefineTypeRefByName(__in mdToken tkAssembly, __in PCWSTR pszTypeDef, __out mdTypeRef* ptd) {
    HRESULT hr = _spWriter->DefineTypeRefByName(tkAssembly, pszTypeDef, ptd);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}

//  Wrapper around IMetadataScope::GetVersionString which throws on
//  failure.
void CMetadataScope::GetVersionString(_Out_writes_to_opt_(ccBufSize, *pccBufSize) LPWSTR pwzBuf, // [OUT] Put version string here.
                                      DWORD ccBufSize, // [IN] size of the buffer, in wide chars
                                      DWORD* pccBufSize) // [OUT] Size of the version string, wide chars, including terminating nul.

{
    HRESULT hr = _spReader->GetVersionString(pwzBuf, ccBufSize, pccBufSize);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}

//  Retrieve a type definition by name. Returns true if the type was
//  found, false if not, throws an exception if any other return.
bool CMetadataScope::FindTypeDefByName(__in PCWSTR szTypeDef, // [IN] Name of the Type.
                                       __in mdToken tkEnclosingClass, // [IN] TypeDef/TypeRef for Enclosing class.
                                       __out mdTypeDef* ptd) // [OUT] Put the TypeDef token here.
{
    HRESULT hr = _spReader->FindTypeDefByName(szTypeDef, tkEnclosingClass, ptd);
    if (FAILED(hr)) {
        if (hr == CLDB_E_RECORD_NOTFOUND) {
            return false;
        }
        throw CMetadataFormatError(this, hr);
    }
    return true;
}

//  Retrieve a TypeRef by name within a given scope. Returns true if the type was
//  found, false if not, throws an exception if any other return.
bool CMetadataScope::FindTypeRef(__in mdToken tkResolutionScope, // [IN] Name of the Type.
                                 __in PCWSTR szTypeRef, // [IN] TypeDef/TypeRef for Enclosing class.
                                 __out mdTypeRef* ptr) // [OUT] Put the TypeDef token here.
{
    HRESULT hr = _spReader->FindTypeRef(tkResolutionScope, szTypeRef, ptr);
    if (FAILED(hr)) {
        if (hr == CLDB_E_RECORD_NOTFOUND) {
            return false;
        }
        throw CMetadataFormatError(this, hr);
    }
    return true;
}

void CMetadataScope::FindMethod(
    __in mdTypeDef td, __in PCWSTR szName, __in_opt PCCOR_SIGNATURE pvSigBlob, __in ULONG cbSigBlob, __out mdMethodDef* pmb) {
    HRESULT hr = _spReader->FindMethod(td, szName, pvSigBlob, cbSigBlob, pmb);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}

bool CMetadataScope::GetClassLayout(__in mdTypeDef td,
                                    __out DWORD* pdwPackSize,
                                    __out COR_FIELD_OFFSET rFieldOffset[],
                                    __in ULONG cMax,
                                    __out ULONG* pcFieldOffset,
                                    __out ULONG* pulClassSize) {
    HRESULT hr = _spReader->GetClassLayout(td, pdwPackSize, rFieldOffset, cMax, pcFieldOffset, pulClassSize);
    if (hr == CLDB_E_RECORD_NOTFOUND) {
        return false;
    } else if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
    return true;
}

//  Retrieve the name for the specified type.
//  Returns: String containing the type name for the specified token.
wstring CMetadataScope::GetTypeName(mdToken tkType) {
    wchar_t rgchTypeName[c_cchTypeNameMax];
    ULONG cchTypeName;
    HRESULT hr;
    if (TypeFromToken(tkType) == mdtTypeRef) {
        hr = _spReader->GetTypeRefProps(tkType, nullptr, rgchTypeName, ARRAYSIZE(rgchTypeName), &cchTypeName);
        if (FAILED(hr)) {
            DebugBreak();
            throw CMetadataFormatError(this, hr);
        }
    } else if (TypeFromToken(tkType) == mdtTypeDef) {
        hr = _spReader->GetTypeDefProps(tkType, rgchTypeName, ARRAYSIZE(rgchTypeName), &cchTypeName, nullptr, nullptr);
        if (FAILED(hr)) {
            DebugBreak();
            throw CMetadataFormatError(this, hr);
        }
    } else {
        DebugBreak();
        throw CMetadataFormatError(this, E_FAIL);
    }
    return wstring(rgchTypeName);
}

#if DBG
wstring CMetadataScope::TypeNameFromTypeSpecBlob(__in_bcount(cbSignature) const BYTE* pbSignature,
                                                 __in ULONG cbSignature,
                                                 __out ULONG& cbUsed) {
    cbUsed = 0;
    if (cbSignature < 3) {
        throw CMetadataFormatError(this, HRESULT_FROM_WIN32(ERROR_CORRUPT_SYSTEM_FILE));
    }

    if (pbSignature[0] != ELEMENT_TYPE_GENERICINST || (pbSignature[1] != ELEMENT_TYPE_CLASS && pbSignature[1] != ELEMENT_TYPE_VALUETYPE)) {
        throw CMetadataFormatError(this, HRESULT_FROM_WIN32(ERROR_CORRUPT_SYSTEM_FILE));
    }
    pbSignature += 2; // Skip over the preamble.
    cbSignature -= 2;
    cbUsed += 2;

    DWORD cbTypeSpec;
    mdToken tkGenericType;
    HRESULT hr = CorSigUncompressToken(pbSignature, cbSignature, &tkGenericType, &cbTypeSpec);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
    pbSignature += cbTypeSpec;
    cbSignature -= cbTypeSpec;
    cbUsed += cbTypeSpec;
    wstring strType(GetTypeName(tkGenericType));

    strType += L"<";
    ULONG cParams;
    hr = CorSigUncompressData(pbSignature, cbSignature, &cParams, &cbTypeSpec);
    pbSignature += cbTypeSpec;
    cbSignature -= cbTypeSpec;
    cbUsed += cbTypeSpec;
    for (size_t i = 0; i < cParams; i += 1) {
        if (cbSignature != 0) {
            switch (pbSignature[0]) {
                case ELEMENT_TYPE_GENERICINST: {
                    ULONG cbUsedGeneric;
                    strType += TypeNameFromTypeSpecBlob(pbSignature, cbSignature, cbUsedGeneric);
                    pbSignature += cbUsedGeneric;
                    cbSignature -= cbUsedGeneric;
                    cbUsed += cbUsedGeneric;
                    break;
                }
                case ELEMENT_TYPE_CLASS: {
                    mdToken tkClass;
                    pbSignature += 1;
                    cbSignature -= 1;
                    cbUsed += 1;
                    hr = CorSigUncompressToken(pbSignature, cbSignature, &tkClass, &cbTypeSpec);
                    pbSignature += cbTypeSpec;
                    cbSignature -= cbTypeSpec;
                    cbUsed += cbTypeSpec;
                    strType += GetTypeName(tkClass);
                    break;
                }
                case ELEMENT_TYPE_STRING:
                    strType += L"string";
                    pbSignature += 1;
                    cbSignature -= 1;
                    cbUsed += 1;
                    break;
                case ELEMENT_TYPE_U4:
                    strType += L"u4";
                    pbSignature += 1;
                    cbSignature -= 1;
                    cbUsed += 1;
                    break;
                default:
                    break;
            }
            if (i + 1 < cParams) {
                strType += L",";
            }
        }
    }
    strType += L">";
    return strType;
}
#endif

// CMetadataScope::GetCommonTokenWriter
//  Return:
//      The token for a valid common type
mdToken CMetadataScope::GetCommonTokenWriter(TOKEN_ID id) {
    // We should never see an id out of this range.
    _ASSERT((0 <= id) && (id < TOKEN_MAX));

    // Lazy creation
    if (IsNilToken(_rgtkCommonTokensWriter[id])) {
        _rgtkCommonTokensWriter[id] = EnsureCommonTokenWriter(id);
    }

    return _rgtkCommonTokensWriter[id];
}

// CMetadataScope::EnsureCommonTokenWriter
//  Return:
//      The token once a common type is registered.
//      Otherwise, return mdTokenNil.
mdToken CMetadataScope::EnsureCommonTokenWriter(TOKEN_ID id) {
    mdToken token = mdTokenNil;

    switch (id) {
        case MSCORLIB: {
            BYTE* pPublicKeyBlob = nullptr;
            ULONG cbPublicKeyBlob = 0;
            PCWSTR assemblyName;
            DWORD dwAssemblyRefFlags;

            if (id == MSCORLIB) {
                assemblyName = c_pszMscorlib_Name;
                pPublicKeyBlob = const_cast<PBYTE>(s_mscorlibStrongNameBlob);
                cbPublicKeyBlob = sizeof(s_mscorlibStrongNameBlob);
                dwAssemblyRefFlags = afContentType_Default;
            } else {
                assemblyName = c_pszWinrtBase_Name;
                dwAssemblyRefFlags = c_WinRTAssemblyFlags;
            }

            // Define AssemblyRef for mscorlib.dll
            if (FAILED(_spAssemblyWriter->DefineAssemblyRef(
                    pPublicKeyBlob, cbPublicKeyBlob, assemblyName, &s_genericMetadata, nullptr, 0, dwAssemblyRefFlags, &token))) {
                token = mdTokenNil;
            }
            if (token != mdTokenNil) {
                //  Remember this assemblyref in the assembly ref table.
                _maptkAssemblyRefs[assemblyName] = token;
            }
            break;
        }
        case SYSTEM_ENUM: {
            // Define a TypeRef for System.Enum which resides in mscorlib assembly
            mdToken tokenMscorelib = GetCommonTokenWriter(MSCORLIB);
            if (FAILED(_spWriter->DefineTypeRefByName(tokenMscorelib, c_pszSystem_Enum_Name, &token))) {
                token = mdTokenNil;
            }
            break;
        }
        case SYSTEM_VALUETYPE: {
            // Define a TypeRef for System.Enum which resides in mscorlib assembly
            mdToken tokenMscorelib = GetCommonTokenWriter(MSCORLIB);
            if (FAILED(_spWriter->DefineTypeRefByName(tokenMscorelib, c_pszSystem_ValueType_Name, &token))) {
                token = mdTokenNil;
            }
            break;
        }
        case SYSTEM_MULTICASTDELEGATE: {
            // Define a TypeRef for System.Enum which resides in mscorlib assembly
            mdToken tokenMscorelib = GetCommonTokenWriter(MSCORLIB);
            if (FAILED(_spWriter->DefineTypeRefByName(tokenMscorelib, c_pszSystem_MulticastDelegate_Name, &token))) {
                token = mdTokenNil;
            }
            break;
        }
        case SYSTEM_ATTRIBUTE: {
            // Define a TypeRef for System.Attribute which resides in mscorlib assembly
            mdToken tokenMscorelib = GetCommonTokenWriter(MSCORLIB);
            if (FAILED(_spWriter->DefineTypeRefByName(tokenMscorelib, c_pszSystem_Attribute_Name, &token))) {
                token = mdTokenNil;
            }
            break;
        }
        case SYSTEM_OBJECT: {
            // Define a TypeRef for System.Object which resides in mscorlib assembly
            mdToken tokenMscorelib = GetCommonTokenWriter(MSCORLIB);
            if (FAILED(_spWriter->DefineTypeRefByName(tokenMscorelib, c_pszSystem_Object_Name, &token))) {
                token = mdTokenNil;
            }
            break;
        }
        case SYSTEM_TYPE: {
            // Define a TypeRef for System.Object which resides in mscorlib assembly
            mdToken tokenMscorelib = GetCommonTokenWriter(MSCORLIB);
            if (FAILED(_spWriter->DefineTypeRefByName(tokenMscorelib, c_pszSystem_Type_Name, &token))) {
                token = mdTokenNil;
            }
            break;
        }
        case SYSTEM_GUID: {
            // Define a TypeRef for System.Guid which resides in mscorlib assembly
            mdToken tokenMscorelib = GetCommonTokenWriter(MSCORLIB);
            if (FAILED(_spWriter->DefineTypeRefByName(tokenMscorelib, c_pszSystem_Guid_Name, &token))) {
                token = mdTokenNil;
            }
            break;
        }
        case MODULE: {
            // Define a TypeRef for System.Enum which resides in mscorlib assembly
            DefineTypeDef(c_pszModule_Name, 0, mdTokenNil, NULL, &token);
            break;
        }
    }

    return token;
}

// Retrieve the typedef token for an enclosing type
// Return:
//     The token for a type's enclosing type
mdToken CMetadataScope::GetNestingType(_In_ mdTypeDef td) {
    mdTypeDef tdEnclosingType;
    HRESULT hr = _spReader->GetNestedClassProps(td, &tdEnclosingType);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }

    return tdEnclosingType;
}

// CMetadataScope::GetCommonTokenReader
//  Return:
//      The token for a valid common type
mdToken CMetadataScope::GetCommonTokenReader(TOKEN_ID id) {
    // We should never see an id out of this range.
    _ASSERT((0 <= id) && (id < TOKEN_MAX));

    // Lazy creation
    if (_rgtkCommonTokensReader[id] == mdTokenNil) {
        _rgtkCommonTokensReader[id] = EnsureCommonTokenReader(id);
    }

    return _rgtkCommonTokensReader[id];
}

// CMetadataScope::EnsureCommonTokenReader
//  Return:
//      The token once a common type is registered.
//      Otherwise, return mdTokenNil.
mdToken CMetadataScope::EnsureCommonTokenReader(TOKEN_ID id) {
    mdToken token = mdTokenNil;
    HRESULT hr = S_OK;

    switch (id) {
        case MSCORLIB: {
            HCORENUM hce = nullptr;
            mdAssemblyRef rgar[c_carAssemblyRefDef];
            while (hr == S_OK) {
                ULONG cAssemblies;
                hr = _spAssemblyReader->EnumAssemblyRefs(&hce, rgar, ARRAYSIZE(rgar), &cAssemblies);
                if (hr == S_FALSE || cAssemblies == 0) {
                    break;
                }
                if (FAILED(hr)) {
                    throw CMetadataFormatError(this, hr);
                }

                //
                //    Look in the referenced assemblies for our known base types.
                //
                for (size_t i = 0; i < cAssemblies; i += 1) {
                    wchar_t rgchAssemblyName[128];
                    ULONG cchAssemblyName;
                    hr = _spAssemblyReader->GetAssemblyRefProps(rgar[i],
                                                                nullptr,
                                                                nullptr,
                                                                rgchAssemblyName,
                                                                ARRAYSIZE(rgchAssemblyName),
                                                                &cchAssemblyName,
                                                                nullptr,
                                                                nullptr,
                                                                nullptr,
                                                                nullptr);
                    if (FAILED(hr)) {
                        throw CMetadataFormatError(this, hr);
                    }
                    if (_wcsicmp(c_pszMscorlib_Name, rgchAssemblyName) == 0) {
                        if (id == MSCORLIB) {
                            token = rgar[i];
                            break;
                        }
                    }
                }
            }
            break;
        }
        case SYSTEM_ENUM: {
            mdToken tokenMscorelib = GetCommonTokenReader(MSCORLIB);
            // Define a TypeRef for System.Enum which resides in mscorlib assembly
            hr = _spReader->FindTypeRef(tokenMscorelib, c_pszSystem_Enum_Name, &token);
            if (FAILED(hr)) {
                token = mdTokenNil;
            }
            break;
        }
        case SYSTEM_VALUETYPE: {
            // Define a TypeRef for System.ValueType which resides in mscorlib assembly
            mdToken tokenMscorelib = GetCommonTokenReader(MSCORLIB);
            if (FAILED(_spReader->FindTypeRef(tokenMscorelib, c_pszSystem_ValueType_Name, &token))) {
                token = mdTokenNil;
            }
            break;
        }
        case SYSTEM_MULTICASTDELEGATE: {
            // Define a TypeRef for System.MulticastDelegate which resides in mscorlib assembly
            mdToken tokenMscorelib = GetCommonTokenReader(MSCORLIB);
            if (FAILED(_spReader->FindTypeRef(tokenMscorelib, c_pszSystem_MulticastDelegate_Name, &token))) {
                token = mdTokenNil;
            }
            break;
        }
        case SYSTEM_ATTRIBUTE: {
            // Define a TypeRef for System.Attribute which resides in mscorlib assembly
            mdToken tokenMscorelib = GetCommonTokenReader(MSCORLIB);
            if (FAILED(_spReader->FindTypeRef(tokenMscorelib, c_pszSystem_Attribute_Name, &token))) {
                token = mdTokenNil;
            }
            break;
        }
        case SYSTEM_OBJECT: {
            // Define a TypeRef for System.Object which resides in mscorlib assembly
            mdToken tokenMscorelib = GetCommonTokenReader(MSCORLIB);
            if (FAILED(_spReader->FindTypeRef(tokenMscorelib, c_pszSystem_Object_Name, &token))) {
                token = mdTokenNil;
            }
            break;
        }
        case SYSTEM_GUID: {
            // Define a TypeRef for System.Guid which resides in mscorlib assembly
            mdToken tokenMscorelib = GetCommonTokenReader(MSCORLIB);
            if (FAILED(_spReader->FindTypeRef(tokenMscorelib, c_pszSystem_Guid_Name, &token))) {
                token = mdTokenNil;
            }
            break;
        }
    }

    return token;
}

// Retrieve the token for a given assembly name
//  Return:
//      A valid metadata token when succeeded
//      Otherwise return mdTokenNil
mdAssemblyRef CMetadataScope::GetAssemblyRefToken(const wstring& strAssemblyName) {
    mdToken token;

    if (strAssemblyName == c_pszMscorlib_Name) {
        return GetCommonTokenReader(MSCORLIB);
    } else if (strAssemblyName == GetCurrentAssembly()) // It's us.
    {
        HRESULT hr;
        mdToken tkAssembly;
        if (SUCCEEDED(hr = _spAssemblyReader->GetAssemblyFromScope(&tkAssembly))) {
            return tkAssembly;
        } else {
            throw CMetadataFormatError(this, hr);
        }
    } else // Not one of our predefined tokens, look it up in the assembly defined token taple
    {
        auto iter = _maptkAssemblyRefs.find(strAssemblyName);
        if (iter == _maptkAssemblyRefs.end()) {
            // We haven't defined this assembly ref yet.

            // Define AssemblyRef
            if (SUCCEEDED(_spAssemblyWriter->DefineAssemblyRef(
                    nullptr, 0, strAssemblyName.c_str(), &(CMetadataScope::s_genericMetadata), nullptr, 0, c_WinRTAssemblyFlags, &token))) {
                // Add the new token to the map
                _maptkAssemblyRefs[strAssemblyName] = token;
            } else {
                // Fail. Just return mdTokenNil
                token = mdTokenNil;
            }
        } else {
            // Found it. Return the cached token.
            token = iter->second;
        }
    }

    return token;
}

//  Looks up the specified token in the metadata file.
//
//  First look to see if it's a type ref in the foundation metadata
//  file (a common case).
//   Next look to see if it's a typeref in mscorlib (the CLR base
//  types).
//  Next look to see if there's a type def with the specified name.
//  Finally see if there's a typeref in any of the other scopes.
//
mdToken CMetadataScope::GetTokenForType(__in PCWSTR pszTypeName) {
    mdToken tkReturns = mdTokenNil;

    HRESULT hr = _spReader->FindTypeDefByName(pszTypeName, mdTokenNil, &tkReturns);
    if (SUCCEEDED(hr)
        // Only do the redirection when we are operating in the destination scope.
        &&
        (_spWriter != nullptr) && IsRedirectedType(wstring(pszTypeName))) {
        HRESULT hr;
        mdToken tkModule = mdTokenNil;
        if (FAILED(hr = GetModuleFromCurrentScope((&tkModule)))) {
            throw CMetadataFormatError(this, hr);
        }

        // Now find the local TypeRef for a retargetable type def
        if (!FindTypeRef(tkModule, pszTypeName, &tkReturns)) {
            // We should always see the companion TypeRef.
            assert(FALSE);
        }
    }
    if (FAILED(hr)) {
        hr = _spReader->FindTypeRef(GetCommonTokenReader(MSCORLIB), pszTypeName, &tkReturns);
    }
    if (FAILED(hr)) {
        hr = _spReader->FindTypeRef(mdTokenNil, pszTypeName, &tkReturns);
    }

    return tkReturns;
}

//  Returns the assembly name for the specified typeref token.
wstring CMetadataScope::GetTypeRefAssembly(mdToken tkType) {
    HRESULT hr;
    mdToken tkScope;
    wchar_t rgchAssemblyName[c_cchTypeNameMax];
    ULONG cbAssemblyName;

    rgchAssemblyName[0] = L'\0';
    hr = _spReader->GetTypeRefProps(tkType, &tkScope, nullptr, 0, nullptr);
    if (SUCCEEDED(hr)) {
        if (TypeFromToken(tkScope) == mdtAssemblyRef) {
            hr = _spAssemblyReader->GetAssemblyRefProps(tkScope,
                                                        nullptr,
                                                        nullptr,
                                                        rgchAssemblyName,
                                                        ARRAYSIZE(rgchAssemblyName),
                                                        &cbAssemblyName,
                                                        nullptr,
                                                        nullptr,
                                                        nullptr,
                                                        nullptr);
        } else if (TypeFromToken(tkScope) == mdtModuleRef) {
            hr = _spReader->GetModuleRefProps(tkScope, rgchAssemblyName, ARRAYSIZE(rgchAssemblyName), &cbAssemblyName);
        } else if (TypeFromToken(tkScope) == mdtTypeRef) {
            hr = _spReader->GetTypeRefProps(tkScope, &tkScope, nullptr, 0, nullptr);
            if (SUCCEEDED(hr) && TypeFromToken(tkScope) == mdtAssemblyRef) {
                hr = _spAssemblyReader->GetAssemblyRefProps(tkScope,
                                                            nullptr,
                                                            nullptr,
                                                            rgchAssemblyName,
                                                            ARRAYSIZE(rgchAssemblyName),
                                                            &cbAssemblyName,
                                                            nullptr,
                                                            nullptr,
                                                            nullptr,
                                                            nullptr);
            }
        } else {
            mdToken tkModule = mdTokenNil;
            if (SUCCEEDED(hr = GetModuleFromCurrentScope((&tkModule)))) {
                if (tkScope == tkModule) {
                    // This is a local TypeRef. Return the current assembly name.
                    return GetCurrentAssembly();
                }
            }
        }

        if (FAILED(hr)) {
            //  We failed, ensure that the assembly name is empty.
            rgchAssemblyName[0] = L'\0';
        }
    }
    return wstring(rgchAssemblyName);
}

wstring CMetadataScope::GetCurrentAssembly() {
    mdAssembly tokeAssembly;
    wstring strAssemblyName;

    assert(_spAssemblyReader != nullptr);

    // Get the assembly in the current scope.
    if (SUCCEEDED(_spAssemblyReader->GetAssemblyFromScope(&tokeAssembly))) {
        wchar_t rgchAssemblyName[c_cchTypeNameMax];

        if (SUCCEEDED(_spAssemblyReader->GetAssemblyProps(
                tokeAssembly, nullptr, nullptr, nullptr, rgchAssemblyName, ARRAYSIZE(rgchAssemblyName), nullptr, nullptr, nullptr))) {
            strAssemblyName = rgchAssemblyName;
        }
    }

    return strAssemblyName;
}

// Returns the assembly token associated with the current scope
mdAssembly CMetadataScope::GetAssemblyFromScope() {
    HRESULT hr = S_OK;
    mdAssembly tkCurrentAssembly;

    assert(_spAssemblyReader != nullptr);
    hr = _spAssemblyReader->GetAssemblyFromScope(&tkCurrentAssembly);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }

    return tkCurrentAssembly;
}

void CMetadataScope::GetAssemblyProps(_In_ mdAssembly mda,
                                      _Outptr_opt_result_buffer_(*pcbPublicKey) const void** ppbPublicKey,
                                      _Out_opt_ ULONG* pcbPublicKey,
                                      _Out_opt_ ULONG* pulHashAlgId,
                                      _Out_writes_to_opt_(cchName, *pchName) LPWSTR szName,
                                      _In_ ULONG cchName,
                                      _Out_opt_ ULONG* pchName,
                                      _Out_opt_ ASSEMBLYMETADATA* pMetadata,
                                      _Out_opt_ DWORD* pdwAssemblyFlags) {
    HRESULT hr = S_OK;
    assert(_spAssemblyReader != nullptr);
    hr = _spAssemblyReader
             ->GetAssemblyProps(mda, ppbPublicKey, pcbPublicKey, pulHashAlgId, szName, cchName, pchName, pMetadata, pdwAssemblyFlags);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}

void CMetadataScope::GetAssemblyRefProps(_In_ mdAssemblyRef mda,
                                         _Outptr_opt_result_buffer_(*pcbPublicKey) const void** ppbPublicKey,
                                         _Out_opt_ ULONG* pcbPublicKey,
                                         _Out_writes_to_opt_(cchName, *pchName) LPWSTR szName,
                                         _In_ ULONG cchName,
                                         _Out_opt_ ULONG* pchName,
                                         _Out_opt_ ASSEMBLYMETADATA* pMetadata,
                                         _Outptr_opt_result_buffer_(*pcbHashValue) const void** ppbHashValue,
                                         _Out_opt_ ULONG* pcbHashValue,
                                         _Out_opt_ DWORD* pdwAssemblyFlags) {
    HRESULT hr = S_OK;
    assert(_spAssemblyReader != nullptr);
    hr = _spAssemblyReader->GetAssemblyRefProps(
        mda, ppbPublicKey, pcbPublicKey, szName, cchName, pchName, pMetadata, ppbHashValue, pcbHashValue, pdwAssemblyFlags);
    if (FAILED(hr)) {
        throw CMetadataFormatError(this, hr);
    }
}

//  Returns true if the type token is located in the Windows.Foundation
//  metadata file, false otherwise.
bool CMetadataScope::IsKnownReferenceType(mdToken tkType, __out TOKEN_ID* pAssemblyToken) {
    bool fIsFoundationType = false;
    *pAssemblyToken = TOKEN_MAX;
    if (TypeFromToken(tkType) == mdtTypeRef) {
        mdToken tkScope;
        HRESULT hr = _spReader->GetTypeRefProps(tkType, &tkScope, nullptr, 0, nullptr);
        if (SUCCEEDED(hr)) {
            if (TypeFromToken(tkScope) == mdtAssemblyRef) {
                wchar_t rgchAssemblyName[128];
                ULONG cchAssemblyName;
                hr = _spAssemblyReader->GetAssemblyRefProps(tkScope,
                                                            nullptr,
                                                            0,
                                                            rgchAssemblyName,
                                                            ARRAYSIZE(rgchAssemblyName),
                                                            &cchAssemblyName,
                                                            nullptr,
                                                            nullptr,
                                                            nullptr,
                                                            nullptr);
                if (SUCCEEDED(hr)) {
                    if (_wcsicmp(c_pszMscorlib_Name, rgchAssemblyName) == 0) {
                        fIsFoundationType = true;
                        *pAssemblyToken = MSCORLIB;
                    }
                }
            }
        }
    }
    return fIsFoundationType;
}

mdToken CMetadataScope::EnsureMember(const wstring& strAssemblyName,
                                     const wstring& strTypeName,
                                     PCWSTR pszMethodName,
                                     PCCOR_SIGNATURE pbMethodSig,
                                     ULONG cbMethodSig,
                                     bool fAllowLocalTypeRef) {
    mdToken tkType = mdTokenNil;

    //  Create an assemblyref token for this assembly if needed,
    //  otherwise return an existing assemblyref token.
    mdToken tkAssembly = GetAssemblyRefToken(strAssemblyName);
    if (!IsNilToken(tkAssembly) && TypeFromToken(tkAssembly) == mdtAssemblyRef) {
        _spReader->FindTypeRef(tkAssembly, strTypeName.c_str(), &tkType); // Note: Ignoring error.
    } else {
        //  It's possible that this custom attribute name is defined in
        //  the current assembly.  If so, use that.
        FindTypeDefByName(strTypeName.c_str(), mdTokenNil, &tkType);

        // Check if we have to redirect a TypeDef to a local TypeRef
        if (fAllowLocalTypeRef && !IsNilToken(tkType) && IsRedirectedType(strTypeName)) {
            // If we find a redirectable TypeDef, we need to reference it as a local TypeRef instead of the TypeDef directly.
            HRESULT hr;
            if (FAILED(hr = GetModuleFromCurrentScope((&tkAssembly)))) {
                throw CMetadataFormatError(this, hr);
            }

            // Mark tkType as mdTokenNil. So the corresponding TypeRef can be defined later.
            tkType = mdTokenNil;
        }
    }

    if (IsNilToken(tkType)) {
        //  Now that we've found the assembly, we need to create a
        //  typeref for the custom attribute. Note this could be a local TypeRef too.
        HRESULT hr = _spWriter->DefineTypeRefByName(tkAssembly, strTypeName.c_str(), &tkType);
        if (FAILED(hr)) {
            throw CMetadataFormatError(this, hr);
        }
    }
    return EnsureMember(tkType, pszMethodName, pbMethodSig, cbMethodSig);
}

mdToken CMetadataScope::EnsureMember(mdToken tkType, PCWSTR pszMethodName, PCCOR_SIGNATURE pbMethodSig, ULONG cbMethodSig) {
    mdToken tkCtor = mdTokenNil;

    // Find the TypeDef of the attribute's Constructor in the imported
    // scope.  If we found it, we're done, otherwise we need to define
    // a memberref with the specified signature.
    HRESULT hr;
    if (TypeFromToken(tkType) != mdtTypeDef) {
        hr = _spReader->FindMemberRef(tkType, pszMethodName, pbMethodSig, cbMethodSig, &tkCtor);
    } else {
        hr = _spReader->FindMember(tkType, pszMethodName, pbMethodSig, cbMethodSig, &tkCtor);
    }

    if (FAILED(hr)) {
        if (hr == CLDB_E_RECORD_NOTFOUND) {
            //  We should never be in a situation where a member lookup
            //  on a typedef fails.
            assert(TypeFromToken(tkType) != mdtTypeDef);
            hr = _spWriter->DefineMemberRef(tkType, pszMethodName, pbMethodSig, cbMethodSig, &tkCtor);
            if (FAILED(hr)) {
                throw CMetadataFormatError(this, hr);
            }
        } else {
            throw CMetadataFormatError(this, hr);
        }
    }
    return tkCtor;
}

bool CMetadataScope::IsRedirectedType(const wstring& /*strTypeName*/) {
    // All types are redirectable.
    return true;
}

//
//  Metadata enumerator: Enumerate type defs
//
bool CMetadataTypeDefEnumerator::Enumerate(__inout HCORENUM* hce,
                                           __out_ecount_part(cTypes, *pcTypeDefs) mdTypeDef* rgTypeDef,
                                           ULONG cTypes,
                                           __out ULONG* pcTypeDefs) {
    return _spMetadataScope->EnumTypeDefs(hce, rgTypeDef, cTypes, pcTypeDefs);
};

//
//  Metadata enumerator: Enumerate Interface Implements
//
bool CMetadataInterfaceImplEnumerator::Enumerate(__inout HCORENUM* hce,
                                                 __out_ecount_part(cIfImpl, *pcIfImpl) mdInterfaceImpl* rgIfImpl,
                                                 ULONG cIfImpl,
                                                 __out ULONG* pcIfImpl) {
    return _spMetadataScope->EnumInterfaceImpls(hce, _tkType, rgIfImpl, cIfImpl, pcIfImpl);
};

//
//  Metadata enumerator: Enumerate fields
//
bool CMetadataFieldEnumerator::Enumerate(__inout HCORENUM* hce,
                                         __out_ecount_part(cFields, *pcFields) mdMethodDef* rgFields,
                                         ULONG cFields,
                                         __out ULONG* pcFields) {
    return _spMetadataScope->EnumFields(hce, _tkType, rgFields, cFields, pcFields);
};

//
//  Metadata enumerator: Enumerate methods
//
bool CMetadataMethodEnumerator::Enumerate(__inout HCORENUM* hce,
                                          __out_ecount_part(cMethods, *pcMethods) mdMethodDef* rgMethods,
                                          ULONG cMethods,
                                          __out ULONG* pcMethods) {
    return _spMetadataScope->EnumMethods(hce, _tkType, rgMethods, cMethods, pcMethods);
};

//
//  Metadata enumerator: Enumerate custom attributes
//
bool CMetadataAttributeEnumerator::Enumerate(__inout HCORENUM* hce,
                                             __out_ecount_part(cAttributes, *pcAttributes) mdCustomAttribute* rgAttributes,
                                             ULONG cAttributes,
                                             __out ULONG* pcAttributes) {
    return _spMetadataScope->EnumCustomAttributes(hce, _tkType, _tkElement, rgAttributes, cAttributes, pcAttributes);
}

//
//  Metadata enumerator: Enumerate parameters
//
bool CMetadataParameterEnumerator::Enumerate(__inout HCORENUM* hce,
                                             __out_ecount_part(cParams, *pcParams) mdParamDef* rgParams,
                                             ULONG cParams,
                                             __out ULONG* pcParams) {
    return _spMetadataScope->EnumParams(hce, _tkMethod, rgParams, cParams, pcParams);
}

//
//  Metadata enumerator: Enumerate properties
//
bool CMetadataPropertyEnumerator::Enumerate(__inout HCORENUM* hce,
                                            __out_ecount_part(cProperties, *pcProperties) mdProperty* rgProperties,
                                            ULONG cProperties,
                                            __out ULONG* pcProperties) {
    return _spMetadataScope->EnumProperties(hce, _tkType, rgProperties, cProperties, pcProperties);
}

//
//  Metadata enumerator: Enumerate events
//
bool CMetadataEventEnumerator::Enumerate(__inout HCORENUM* hce,
                                         __out_ecount_part(cEvents, *pcEvents) mdProperty* rgEvents,
                                         ULONG cEvents,
                                         __out ULONG* pcEvents) {
    return _spMetadataScope->EnumEvents(hce, _tkType, rgEvents, cEvents, pcEvents);
}

//
//  Metadata enumerator: Enumerate typerefs
//
bool CMetadataTypeRefEnumerator::Enumerate(__inout HCORENUM* hce,
                                           __out_ecount_part(cEvents, *pcEvents) mdProperty* rgEvents,
                                           ULONG cEvents,
                                           __out ULONG* pcEvents) {
    return _spMetadataScope->EnumTypeRefs(hce, rgEvents, cEvents, pcEvents);
}

//
//  Metadata enumerator: Enumerate generic params
//
bool CMetadataGenericParamEnumerator::Enumerate(__inout HCORENUM* hce,
                                                __out_ecount_part(cGenericParams, *pcGenericParams) mdProperty* rgGenericParams,
                                                ULONG cGenericParams,
                                                __out ULONG* pcGenericParams) {
    return _spMetadataScope->EnumGenericParams(hce, _tkType, rgGenericParams, cGenericParams, pcGenericParams);
}

//
//  Metadata enumerator: Assembly refs
//
bool CMetadataAssemblyRefsEnumerator::Enumerate(__inout HCORENUM* hce,
                                                __out_ecount_part(cAssemblyRefs, *pcAssemblyRefs) mdAssemblyRef* rgAssemblyRefs,
                                                ULONG cAssemblyRefs,
                                                __out ULONG* pcAssemblyRefs) {
    return _spMetadataScope->EnumAssemblyRefs(hce, rgAssemblyRefs, cAssemblyRefs, pcAssemblyRefs);
}

//
//  Metadata enumerator: Enumerate interface impl rows
//
bool CMetadataMethodImplEnumerator::Enumerate(__inout HCORENUM* hce,
                                              __out_ecount_part(cMethodImpls, *pcMethodImpls) pair<mdToken, mdToken>* rgMethodImpls,
                                              ULONG cMethodImpls,
                                              __out ULONG* pcMethodImpls) {
    vector<mdToken> rgMethodBody(cMethodImpls);
    vector<mdToken> rgMethodDecl(cMethodImpls);

    bool fResult = _spMetadataScope->EnumMethodImpls(hce, _tkType, &rgMethodBody[0], &rgMethodDecl[0], cMethodImpls, pcMethodImpls);
    if (fResult) {
        for (ULONG i = 0; i < *pcMethodImpls; i += 1) {
            rgMethodImpls[i].first = rgMethodBody[i];
            rgMethodImpls[i].second = rgMethodDecl[i];
        }
    }
    return fResult;
}

// Matches the winmd metadata format string to an enumeration label. This allows code
// to check against an enumeration instead of relying on string comparison later.
//
// Returns:
//    false: the string was not matched with a valid metadata format string

bool CMetadataScope::DetermineMetadataFormatVersion(std::wstring wstrFormatVersion) {
    // g_ExpectedWinMdVersionStrings is defined in %ROOT%\com\inc\metadata\WinMDVerString.h.
    // Whenever a new metadata format is introduced, the following should happen in winmdvt:
    //   1. MetadataFormatVersion should be updated with a new enum label
    //   2. The "strToEnumMapping" below array should be updated with the new values.

    struct StringToEnumMapping {
        std::wstring str;
        MetadataFormatVersion value;
    };

    StringToEnumMapping strToEnumMapping[] = {
        { g_ExpectedWinMdVersionStrings[0], MetadataFormatVersion::WindowsRuntime1_2 },
        { g_ExpectedWinMdVersionStrings[1], MetadataFormatVersion::WindowsRuntime1_3 },
        { g_ExpectedWinMdVersionStrings[2], MetadataFormatVersion::WindowsRuntime1_4 },
    };

    assert(ARRAYSIZE(strToEnumMapping) == ARRAYSIZE(g_ExpectedWinMdVersionStrings));

    bool fFoundValidVersion = false;
    for (size_t i = 0; i < ARRAYSIZE(g_ExpectedWinMdVersionStrings); ++i) {
        if (wstrFormatVersion == strToEnumMapping[i].str) {
            _metadataFormatVersion = strToEnumMapping[i].value;
            fFoundValidVersion = true;
            break;
        }
    }

    if (!fFoundValidVersion) {
        // We may have had a version string that had extra "stuff" on the end of the metadata format string (";CLR").
        // We want to try again with just the expected prefix of the format verion string to decide if we found a
        // good WinMD or not.
        std::wstring wstrPrefixed = wstrFormatVersion.substr(0, wstrFormatVersion.find(L';'));
        if (wstrPrefixed.length() != wstrFormatVersion.length()) {
            // We recurse only if attempting to take the substring from 0 to the first ';' was successful (i.e., there
            // was a ';' in the string).
            fFoundValidVersion = DetermineMetadataFormatVersion(wstrPrefixed);
        }
    }

    return fFoundValidVersion;
}
