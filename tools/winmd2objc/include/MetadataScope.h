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

#pragma once

//
//  Common metadata tokens.
//
const PCWSTR c_pszMscorlib_Name = L"mscorlib";
const PCWSTR c_pszWinrtBase_Name = L"Windows.Foundation";
const PCWSTR c_pszSystem_Name = L"System";
const PCWSTR c_pszWinrtBase_File = L"Windows.Foundation.winmd";
const PCWSTR c_pszSystem_Enum_Name = L"System.Enum";
const PCWSTR c_pszSystem_ValueType_Name = L"System.ValueType";
const PCWSTR c_pszSystem_Attribute_Name = L"System.Attribute";
const PCWSTR c_pszSystem_Object_Name = L"System.Object";
const PCWSTR c_pszSystem_Type_Name = L"System.Type";
const PCWSTR c_pszSystem_Guid_Name = L"System.Guid";
const PCWSTR c_pszSystem_MulticastDelegate_Name = L"System.MulticastDelegate";
const PCWSTR c_pszModule_Name = L"<Module>";
const PCWSTR c_pszDllExtension = L".dll";
const USHORT c_Sha1_Hash_Algorithm =
    0x8004; // ECMA 335 II.23.1.1 - Used for Crypto purposes, but is the only supported option in the protocol.

const PCWSTR c_pszExtensionSeparator = L".";

const size_t c_cchTypeNameMax = 512;
const size_t c_carAssemblyRefDef = 10;
const size_t c_ctkInterfaceImplDef = 128;
const size_t c_ctkTypeEnumDef = 128;
const size_t c_ctkFieldEnumDef = 128;

const size_t c_cchMethodNameMax = 128;
const size_t c_cchFieldNameMax = 128;

// Numerical id for the common metadata tokens
enum TOKEN_ID {
    MSCORLIB = 0,
    SYSTEM_ENUM,
    SYSTEM_VALUETYPE,
    SYSTEM_MULTICASTDELEGATE,
    SYSTEM_ATTRIBUTE,
    SYSTEM_OBJECT,
    SYSTEM_TYPE,
    SYSTEM_GUID,
    MODULE,

    // Make this member as the last element.
    TOKEN_MAX,
};

// Needs to be in sync with latest version from COM\inc\metadata\WinMDVerString.h
enum class MetadataFormatVersion { UnknownVersion, WindowsRuntime1_2, WindowsRuntime1_3, WindowsRuntime1_4 };

//  A Metadata Scope describes a metadata file, either for input or
//  output.
//
//  It contains a pointer to an IMetadataEmit and IMetadataImport
//  object scoped to the relevant input file, a symbol table for the
//  types defined in the file and a set of partially resolved types.
//
class CMetadataScope {
public:
    enum class ScopeType {
        ReadOnly,
        ReadWrite,
    };

    CMetadataScope(const std::wstring& strFileName) : _fWindowsFoundation(false), _tkAssemblyWriter(mdTokenNil), _strFileName(strFileName) {
        ZeroMemory(_rgtkCommonTokensReader, sizeof(_rgtkCommonTokensReader));
        ZeroMemory(_rgtkCommonTokensWriter, sizeof(_rgtkCommonTokensWriter));
    }
    ~CMetadataScope() {
    }

    bool CreateScope(ScopeType stScope);
    void CloseEnum(__in HCORENUM hce) {
        _spReader->CloseEnum(hce);
    }
    bool EnumTypeDefs(__inout HCORENUM* hce,
                      __out_ecount_part(cTypes, *pcTypeDefs) mdTypeDef* rgTypeDef,
                      ULONG cTypes,
                      __out ULONG* pcTypeDefs);
    bool EnumTypeRefs(__inout HCORENUM* hce,
                      __out_ecount_part(cTypes, *pcTypeRefs) mdTypeRef* rgTypeRef,
                      ULONG cTypes,
                      __out ULONG* pcTypeRefs);
    bool EnumFields(__inout HCORENUM* hce,
                    __in mdTypeDef tkType,
                    __out_ecount_part(cTypes, *pcFieldDefs) mdFieldDef* rgFieldDef,
                    __in ULONG cTypes,
                    __out ULONG* pcFieldDefs);
    bool EnumEvents(__inout HCORENUM* hce,
                    __in mdTypeDef tkType,
                    __out_ecount_part(cTypes, *pcEvents) mdEvent* rgEvents,
                    __in ULONG cTypes,
                    __out ULONG* pcEvents);
    bool EnumMethods(__inout HCORENUM* hce,
                     __in mdTypeDef tkType,
                     __out_ecount_part(cTypes, *pcMethodDefs) mdMethodDef* rgMethodDef,
                     __in ULONG cTypes,
                     __out ULONG* pcMethodDefs);
    bool EnumMethodSemantics(__inout HCORENUM* phEnum,
                             __in mdMethodDef mb,
                             __out_ecount_part(cMax, *pcEventProp) mdToken rEventProp[],
                             __in ULONG cMax,
                             __out ULONG* pcEventProp);
    bool EnumMethodImpls(__inout HCORENUM* phEnum,
                         __in mdTypeDef td,
                         __out_ecount_part(cMax, *pcEventProp) mdToken rMethodBody[],
                         __out_ecount_part(cMax, *pcEventProp) mdToken rMethodDecl[],
                         __in ULONG cMax,
                         __out ULONG* pcEventProp);
    bool EnumGenericParams(__inout HCORENUM* phEnum,
                           __in mdToken tk,
                           __out_ecount_part(cMax, *pcGenericParams) mdGenericParam rGenericParams[],
                           __in ULONG cMax,
                           __out ULONG* pcGenericParams);
    void GetGenericParamProps(__in mdGenericParam gp,
                              __in ULONG* pulParamSeq,
                              __out_opt DWORD* pdwParamFlags,
                              __out_opt mdToken* ptOwner,
                              __out_opt DWORD* reserved,
                              __out_ecount_part_opt(cchName, *pchName) LPWSTR wzname,
                              ULONG cchName,
                              __out_opt ULONG* pchName);

    bool EnumCustomAttributes(__inout HCORENUM* hce,
                              mdTypeDef tkType,
                              mdToken tkElement,
                              __out_ecount_part(cAttributes, *pcAttributes) mdCustomAttribute* rgAttributes,
                              ULONG cAttributes,
                              __out ULONG* pcAttributes);
    bool EnumParams(__inout HCORENUM* hce,
                    mdMethodDef tkMethod,
                    __out_ecount_part(cParams, *pcParams) mdParamDef* rgParams,
                    ULONG cParams,
                    __out ULONG* pcParams);
    bool EnumInterfaceImpls(__inout HCORENUM* phEnum,
                            __in mdTypeDef td,
                            __out_ecount_part(cMax, *pcImpls) mdInterfaceImpl rImpls[],
                            __in ULONG cMax,
                            __out ULONG* pcImpls);
    bool EnumProperties(__inout HCORENUM* phEnum,
                        __in mdTypeDef td,
                        __out_ecount_part(cMax, *pcProperties) mdProperty rProperties[],
                        __in ULONG cMax,
                        __out ULONG* pcProperties);
    bool EnumGenericParamConstraints(__inout HCORENUM* phEnum,
                                     __in mdGenericParam tk,
                                     __out_ecount_part(cMax, *pcGenericParamConstraints)
                                         mdGenericParamConstraint rGenericParamConstraints[],
                                     __in ULONG cMax,
                                     __out ULONG* pcGenericParamConstraints);

    bool EnumAssemblyRefs(_Inout_ HCORENUM* hce,
                          _Out_writes_to_(cAssemblyRefs, *pcAssemblyRefs) mdAssemblyRef* rgAssemblyRefs,
                          _In_ ULONG cAssemblyRefs,
                          _Out_opt_ ULONG* pcAssemblyRefs);

    bool EnumExportedTypes(_Inout_ HCORENUM* hce,
                           _Out_writes_to_(cMax, *pcTokens) mdExportedType* rgExportedTypes,
                           _In_ ULONG cMax,
                           _Out_opt_ ULONG* pcTokens);

    bool EnumFiles(_Inout_ HCORENUM* hce, _Out_writes_to_(cMax, *pcTokens) mdFile* rgFiles, _In_ ULONG cMax, _Out_opt_ ULONG* pcTokens);

    bool EnumManifestResources(_Inout_ HCORENUM* hce,
                               _Out_writes_to_(cMax, *pcTokens) mdManifestResource* rgManifestResources,
                               _In_ ULONG cMax,
                               _Out_opt_ ULONG* pcTokens);

    void GetVersionString(_Out_writes_to_opt_(ccBufSize, *pccBufSize) LPWSTR pwzBuf, // [OUT] Put version string here.
                          DWORD ccBufSize, // [IN] size of the buffer, in wide chars
                          DWORD* pccBufSize); // [OUT] Size of the version string, wide chars, including terminating nul.

    bool FindTypeDefByName(__in PCWSTR szTypeDef, // [IN] Name of the Type.
                           __in mdToken tkEnclosingClass, // [IN] TypeDef/TypeRef for Enclosing class.
                           __out mdTypeDef* ptd); // [OUT] Put the TypeDef token here.

    bool FindTypeRef(__in mdToken tkResolutionScope, // [IN] Name of the Type.
                     __in PCWSTR szTypeRef, // [IN] TypeDef/TypeRef for Enclosing class.
                     __out mdTypeRef* ptr); // [OUT] Put the TypeDef token here.

    void GetCustomAttributeProps(__in mdCustomAttribute cv,
                                 __out_opt mdToken* ptkObj,
                                 __out_opt mdToken* ptkType,
                                 __out_opt void const** ppBlob,
                                 __out_opt ULONG* pcbSize);
    void GetTypeDefProps(__in mdTypeDef td, // [IN] TypeDef token for inquiry.
                         __out_ecount_part_opt(cchTypeDef, *pchTypeDef) PWSTR szTypeDef, // [OUT] Put name here.
                         __in ULONG cchTypeDef, // [IN] size of name buffer in wide chars.
                         __out_opt ULONG* pchTypeDef, // [OUT] put size of name (wide chars) here.
                         __out_opt DWORD* pdwTypeDefFlags, // [OUT] Put flags here.
                         __out_opt mdToken* ptkExtends); // [OUT] Put base class TypeDef/TypeRef here.
    void SetTypeDefProps(_In_ mdTypeDef td, __in DWORD dwTypeDefFlags, __in mdToken tkExtends, __in mdToken rtkImplements[]);
    void GetTypeRefProps(_In_ mdTypeRef tr, // [IN] TypeRef token.
                         _Out_opt_ mdToken* ptkResolutionScope, // [OUT] Resolution scope, ModuleRef or AssemblyRef.
                         _Out_writes_to_opt_(cchName, *pchName) LPWSTR szName, // [OUT] Name of the TypeRef.
                         _In_ ULONG cchName, // [IN] Size of buffer.
                         _Out_opt_ ULONG* pchName); // [OUT] Size of Name.
    void GetFieldProps(__in mdFieldDef mb,
                       __out_opt mdTypeDef* pClass,
                       __out_ecount_part_opt(cchField, *pchField) PWSTR szField,
                       __in ULONG cchField,
                       __out_opt ULONG* pchField,
                       __out_opt DWORD* pdwAttr,
                       __out_opt PCCOR_SIGNATURE* ppvSigBlob,
                       __out_opt ULONG* pcbSigBlob,
                       __out_opt DWORD* pdwCPlusTypeFlag,
                       __out_opt UVCP_CONSTANT* ppValue,
                       __out_opt ULONG* pcchValue);
    void GetMethodProps(__in mdMethodDef mb,
                        __out_opt mdTypeDef* pClass,
                        __out_ecount_part_opt(cchMethod, *pchMethod) PWSTR szMethod,
                        __in ULONG cchMethod,
                        __out_opt ULONG* pchMethod,
                        __out_opt DWORD* pdwAttr,
                        __out_opt PCCOR_SIGNATURE* ppvSigBlob,
                        __out_opt ULONG* pcbSigBlob,
                        __out_opt ULONG* pulCodeRVA,
                        __out_opt DWORD* pdwImplFlags);
    void GetParamProps(__in mdParamDef tk,
                       __out_opt mdMethodDef* pmd,
                       __out_opt ULONG* pulSequence,
                       __out_ecount_part_opt(cchName, *pchName) PWSTR szName,
                       __in ULONG cchName,
                       __out_opt ULONG* pchName,
                       __out_opt DWORD* pdwAttr,
                       __out_opt DWORD* pdwCPlusTypeFlag,
                       __out_opt UVCP_CONSTANT* ppValue,
                       __out_opt ULONG* pcchValue);
    bool GetFieldMarshal(__in mdToken tk,
                         __out_bcount_part_opt(*pcbNativeType, *pcbNativeType) PCCOR_SIGNATURE* ppvNativeType,
                         __out_opt ULONG* pcbNativeType);
    void SetFieldMarshal(__in mdToken tk, __in_ecount(cbNativeType) PCCOR_SIGNATURE pvNativeType, __in ULONG cbNativeType);

    void GetMethodSemantics(__in mdToken tk, __in mdToken tkEventProp, __out_opt DWORD* pdwSemanticsFlags);

    void GetMemberRefProps(__in mdMemberRef mr,
                           __out_opt mdToken* ptk,
                           __out_ecount_part_opt(cchMember, *pchMember) PWSTR szMember,
                           __in ULONG cchMember,
                           __out_opt ULONG* pchMember,
                           __out_opt PCCOR_SIGNATURE* ppvSigBlob,
                           __out_opt ULONG* pbSig);
    void GetMemberProps(__in mdToken mb, // The member for which to get props.
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
                        __out_opt ULONG* pcchValue); // [OUT] size of constant string in chars, 0 for non-strings.

    void GetGenericParamConstraintProps(__in mdGenericParamConstraint gpc,
                                        __out_opt mdGenericParam* ptGenericParam,
                                        __out_opt mdToken* ptkConstraintType);

    void GetPropertyProps(__in mdProperty prop,
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
                          __deref_out_range(0, cMax) __maybenull ULONG* pcOtherMethod);

    void GetEventProps(__in mdEvent ev,
                       __out_opt mdTypeDef* pClass,
                       __out_ecount_part_opt(cchEvent, *pchEvent) PWSTR szEvent,
                       __in ULONG cchEvent,
                       __deref_out_range(0, cchEvent) __maybenull ULONG* pchEvent,
                       __out_opt DWORD* pdwEventFlags,
                       __out_opt mdToken* ptkEventType,
                       __out_opt mdMethodDef* pmdAddOn,
                       __out_opt mdMethodDef* pmdRemoveOn,
                       __out_opt mdMethodDef* pmdFire,
                       __out_ecount_part_opt(cMax, *pcOtherMethod) mdMethodDef rmdOtherMethod[],
                       __in ULONG cMax,
                       __deref_out_range(0, cMax) __maybenull ULONG* pcOtherMethod);

    void GetScopeProps(_Out_writes_to_opt_(cchName, *pchName) LPWSTR szName, // [OUT] Put the name here.
                       ULONG cchName, // [IN] Size of name buffer in wide chars.
                       ULONG* pchName, // [OUT] Put size of name (wide chars) here.
                       GUID* pmvid); // [OUT, OPTIONAL] Put MVID here.
    void GetTokenFromTypeSpec(__in PCCOR_SIGNATURE pvSig, __in ULONG cbSig, __out mdTypeSpec* ptypespec);
    void GetTypeSpecFromToken(__in mdTypeSpec typespec, __out PCCOR_SIGNATURE* ppvSig, __out ULONG* pcbSig);

    void GetInterfaceImplProps(__in mdInterfaceImpl tkIimpl, __out_opt mdTypeDef* tkClass, __out_opt mdToken* tkInterface);
    void DefineCustomAttribute(__in mdToken tkObj,
                               __in mdToken tkType,
                               __in_bcount(cbCustomAttribute) void const* pCustomAttribute,
                               __in ULONG cbCustomAttribute,
                               __out mdCustomAttribute* pcv);
    void DefineTypeDef(
        __in PCWSTR pszTypeDef, __in DWORD dwTypeDefFlags, __in mdToken tkExtends, __in_opt mdToken rtkImplements[], __out mdTypeDef* ptd);
    void DefineTypeRefByName(__in mdToken tkResolutionScope, __in PCWSTR pszTypeDef, __out mdTypeRef* ptd);
    void DefineField(__in mdTypeDef td,
                     __in PCWSTR szName,
                     __in DWORD dwFieldFlags,
                     __in_bcount(cbSigBlob) PCCOR_SIGNATURE pvSigBlob,
                     __in ULONG cbSigBlob,
                     DWORD __in dwCPlusTypeFlag,
                     __in_bcount(cchValue) void const* pValue,
                     __in ULONG cchValue,
                     __out mdFieldDef* pmd);
    void DefineMethod(__in mdTypeDef td,
                      __in PCWSTR szName,
                      __in DWORD dwMethodFlags,
                      __in PCCOR_SIGNATURE pvSigBlob,
                      __in ULONG cbSigBlob,
                      __in ULONG ulCodeRVA,
                      __in DWORD dwImplFlags,
                      __out mdMethodDef* pmd);
    void DefineMethodImpl(__in mdTypeDef td, __in mdToken tkBody, __in mdToken tkDecl);
    void DefineParam(__in mdMethodDef md,
                     __in ULONG ulParamSeq,
                     __in PCWSTR szName,
                     __in DWORD dwParamFlags,
                     __in DWORD dwCPlusTypeFlag,
                     __in_bcount(cchValue) void const* pValue,
                     __in ULONG cchValue,
                     __out mdParamDef* ppd);
    void DefineProperty(__in mdTypeDef td,
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
                        __out mdProperty* pmdProp);
    void DefineEvent(__in mdTypeDef td,
                     __in PCWSTR szEvent,
                     __in DWORD dwEventFlags,
                     __in mdToken tkEventType,
                     __in mdMethodDef mdAddOn,
                     __in mdMethodDef mdRemoveOn,
                     __in mdMethodDef mdFireOn,
                     __in mdMethodDef rmdOtherMethods[],
                     __out mdEvent* pmdProp);
    void DefineGenericParam(__in mdToken tk,
                            __in ULONG ulParamSeq,
                            __in DWORD dwParamFlags,
                            __in LPCWSTR szname,
                            __in DWORD reserved,
                            __in mdToken rtkConstraints[],
                            __out mdGenericParam* pgp);

    bool GetCustomAttributeByName(mdToken tkObj, // [IN] Object with Custom Attribute.
                                  LPCWSTR szName, // [IN] Name of desired Custom Attribute.
                                  const void** ppData, // [OUT] Put pointer to data here.
                                  ULONG* pcbData); // [OUT] Put size of data here.
    bool GetParamForMethodIndex(mdMethodDef md, // [IN] Method token.
                                ULONG ulParamSeq, // [IN] Parameter sequence.
                                mdParamDef* ppd); // [IN] Put Param token here.
    void GetNameFromToken(mdToken tk, MDUTF8CSTR* pszUtf8NamePtr);

    void FindMethod(
        __in mdTypeDef td, __in PCWSTR szName, __in_opt PCCOR_SIGNATURE pvSigBlob, __in ULONG cbSigBlob, __out mdMethodDef* pmb);

    bool GetClassLayout(__in mdTypeDef td,
                        __out DWORD* pdwPackSize,
                        __out COR_FIELD_OFFSET rFieldOffset[],
                        __in ULONG cMax,
                        __out ULONG* pcFieldOffset,
                        __out ULONG* pulClassSize);

    std::wstring GetTypeName(mdToken tkType);
#if DBG
    std::wstring TypeNameFromTypeSpecBlob(__in_bcount(cbSignature) const BYTE* pbSignature, __in ULONG cbSignature, __out ULONG& cbUsed);
#endif

    // Retrieve the token for an enclosing type
    mdToken GetNestingType(_In_ mdTypeDef td);

    // Retrieve the token for common metadata types
    mdToken GetCommonTokenReader(TOKEN_ID id);
    mdToken GetCommonTokenWriter(TOKEN_ID id);

    mdToken EnsureMember(const std::wstring& strAssemblyName,
                         const std::wstring& strTypeName,
                         PCWSTR pszMethodName,
                         PCCOR_SIGNATURE pbSig,
                         ULONG cbSig,
                         bool fAllowLocalTypeRef);
    mdToken EnsureMember(mdToken tkType, PCWSTR pszMethodName, PCCOR_SIGNATURE pbMethodSig, ULONG cbMethodSig);

    // Retrieve the token for a specified metadata type
    mdToken GetTokenForType(__in const PCWSTR pszType);

    //  Returns if the specified type token is a foundation type or not.
    bool IsKnownReferenceType(mdToken tkType, __out TOKEN_ID* pAssemblyToken);
    mdAssemblyRef GetAssemblyRefToken(const std::wstring& strAssemblyName);
    std::wstring GetTypeRefAssembly(mdToken tkType);
    std::wstring GetCurrentAssembly();
    mdAssembly GetAssemblyFromScope();
    void GetAssemblyProps(_In_ mdAssembly mda,
                          _Outptr_opt_result_buffer_(*pcbPublicKey) const void** ppbPublicKey,
                          _Out_opt_ ULONG* pcbPublicKey,
                          _Out_opt_ ULONG* pulHashAlgId,
                          _Out_writes_to_opt_(cchName, *pchName) LPWSTR szName,
                          _In_ ULONG cchName,
                          _Out_opt_ ULONG* pchName,
                          _Out_opt_ ASSEMBLYMETADATA* pMetadata,
                          _Out_opt_ DWORD* pdwAssemblyFlags);

    void GetAssemblyRefProps(_In_ mdAssemblyRef mda,
                             _Outptr_opt_result_buffer_(*pcbPublicKey) const void** ppbPublicKey,
                             _Out_opt_ ULONG* pcbPublicKey,
                             _Out_writes_to_opt_(cchName, *pchName) LPWSTR szName,
                             _In_ ULONG cchName,
                             _Out_opt_ ULONG* pchName,
                             _Out_opt_ ASSEMBLYMETADATA* pMetadata,
                             _Outptr_opt_result_buffer_(*pcbHashValue) const void** ppbHashValue,
                             _Out_opt_ ULONG* pcbHashValue,
                             _Out_opt_ DWORD* pdwAssemblyFlags);

    const std::wstring& FileName() {
        return _strFileName;
    }
    bool IsReadOnly() const {
        return _spWriter == nullptr;
    } // Read-only scopes have no writer.

    // Return the module token from the current scope. This module token is used for defining local TypeRef.
    HRESULT GetModuleFromCurrentScope(__out mdToken* pToken) {
        return _spReader->GetModuleFromScope(pToken);
    }

#ifdef MDMERGE_DRT // DRT only functions
    HRESULT GetTypeRefScopeToken(mdTypeRef tkTypeRef, __out mdToken* ptkScope) {
        *ptkScope = mdTokenNil;
        return _spReader->GetTypeRefProps(tkTypeRef, ptkScope, nullptr, 0, nullptr);
    }
#endif
    // Check if a type is retargetable.
    static bool IsRedirectedType(const std::wstring& strTypeName);

    bool DetermineMetadataFormatVersion(std::wstring wstrFormatVersion);

    MetadataFormatVersion GetMetadataFormatVersion() {
        return _metadataFormatVersion;
    }

private:
    const std::wstring _strFileName;
    CComPtr<IMetaDataDispenserEx> _spDispenser;
    CComPtr<IMetaDataEmit2> _spWriter;
    CComPtr<IMetaDataAssemblyEmit> _spAssemblyWriter;
    CComPtr<IMetaDataImport2> _spReader;
    CComPtr<IMetaDataAssemblyImport> _spAssemblyReader;
    mdAssembly _tkAssemblyWriter;
    bool _fWindowsFoundation;
    bool EnsureMetadataReader(PCWSTR pszFileName);
    bool EnsureMetadataWriter();

    mdToken _rgtkCommonTokensReader[TOKEN_MAX];
    mdToken _rgtkCommonTokensWriter[TOKEN_MAX];
    std::map<std::wstring, mdToken> _maptkAssemblyRefs;

    // Ensure a common token
    mdToken EnsureCommonTokenReader(TOKEN_ID id);
    mdToken EnsureCommonTokenWriter(TOKEN_ID id);

    static const BYTE s_mscorlibStrongNameBlob[];
    static const BYTE s_WinMDStrongNameBlob[];
    static const ASSEMBLYMETADATA s_genericMetadata;
    static const ASSEMBLYMETADATA s_WinMDMetadata;
    MetadataFormatVersion _metadataFormatVersion;
};

//  Templated base class for metadata enumeration.  Encapsulates all
//  the logic for managing enumerating metadata constructs in an STL
//  style iterator.
//
//  To create a new iterator type, derive a new class from the
//  CMetadataEnumerator class and provide a single "Enumerate" method
//  which calls the unmanaged metadata enumeration API to enumerate
//  elements.
//
//  To use, simply declare an iterator then use the STL "begin()" and
//  "end()" methods to enumerate the elements in the array.  This is an
//  "input iterator" so it can only be traversed linearly in a forwards
//  direction.
//
template <class metadataType>
class CMetadataEnumerator {
    class iterator : public std::iterator<std::input_iterator_tag, metadataType> {
    public:
        iterator(CMetadataEnumerator<metadataType>* pEnumerator) : _pEnumerator(pEnumerator), _iTypeCurrent(0) {
            _fContinueIterating = _pEnumerator->Enumerate(&_pEnumerator->_hce, _tkTypes, ARRAYSIZE(_tkTypes), &_cTypes);
        }
        iterator() : _pEnumerator(nullptr), _fContinueIterating(false) {
        }

        iterator(const iterator& other)
            : _fContinueIterating(other._fContinueIterating), _iTypeCurrent(other._iTypeCurrent), _pEnumerator(other._pEnumerator) {
            CopyMemory(_tkTypes, other._tkTypes, sizeof(_tkTypes));
        }

        //  Note that this only works when comparing against
        //  the iterator returned by CMetadataIterator.end().  It is
        //  not a general purpose operator ==.
        bool operator==(const iterator& it) {
            return (_fContinueIterating == it._fContinueIterating);
        }
        bool operator!=(const iterator& it) {
            return !(*this == it);
        }
        iterator& operator++() {
            _iTypeCurrent += 1;
            if (_iTypeCurrent == _cTypes) {
                _fContinueIterating = _pEnumerator->Enumerate(&_pEnumerator->_hce, _tkTypes, ARRAYSIZE(_tkTypes), &_cTypes);
                _iTypeCurrent = 0;
            }
            return (*this);
        }

        metadataType operator*() {
            return (_tkTypes[_iTypeCurrent]);
        }

    private:
        CMetadataEnumerator<metadataType>* _pEnumerator;
        bool _fContinueIterating;
        size_t _iTypeCurrent;
        ULONG _cTypes;
        metadataType _tkTypes[c_ctkTypeEnumDef];
    };

public:
    iterator begin() {
        return iterator(this);
    }
    iterator end() {
        return iterator();
    }

    CMetadataEnumerator(const std::shared_ptr<CMetadataScope> spScope) : _spMetadataScope(spScope), _hce(nullptr) {
    }

    ~CMetadataEnumerator() {
        if (_hce != nullptr) {
            _spMetadataScope->CloseEnum(_hce);
            _hce = nullptr;
        }
    }

protected:
    std::shared_ptr<CMetadataScope> _spMetadataScope;

private:
    virtual bool Enumerate(__inout HCORENUM* hce,
                           __out_ecount_part(cTypes, *pcTypeDefs) metadataType* rgTypeDef,
                           ULONG cTypes,
                           __out ULONG* pcTypeDefs) = 0;
    HCORENUM _hce;
};

//  Metadata enumerator specialized to enumerate type definitions.
class CMetadataTypeDefEnumerator : public CMetadataEnumerator<mdTypeDef> {
public:
    CMetadataTypeDefEnumerator(std::shared_ptr<CMetadataScope> spScope) : CMetadataEnumerator<mdTypeDef>(spScope) {
    }

private:
    bool Enumerate(__inout HCORENUM* hce, __out_ecount_part(cTypes, *pcTypes) mdTypeDef* rgTypeDef, ULONG cTypes, __out ULONG* pcTypes);
};

//  Metadata enumerator specialized to enumerate struct and enum fields.
class CMetadataFieldEnumerator : public CMetadataEnumerator<mdFieldDef> {
public:
    CMetadataFieldEnumerator(std::shared_ptr<CMetadataScope> spScope, mdTypeDef tkType)
        : CMetadataEnumerator<mdFieldDef>(spScope), _tkType(tkType) {
    }

private:
    mdTypeDef _tkType;
    bool Enumerate(__inout HCORENUM* hce, __out_ecount_part(cFields, *pcFields) mdTypeDef* rgFields, ULONG cFields, __out ULONG* pcFields);
};

//  Metadata enumerator specialized to enumerate interface implements
//  elements.
class CMetadataInterfaceImplEnumerator : public CMetadataEnumerator<mdInterfaceImpl> {
public:
    CMetadataInterfaceImplEnumerator(std::shared_ptr<CMetadataScope> spScope, mdTypeDef tkType)
        : CMetadataEnumerator<mdInterfaceImpl>(spScope), _tkType(tkType) {
    }

private:
    mdTypeDef _tkType;
    bool Enumerate(__inout HCORENUM* hce,
                   __out_ecount_part(cIfImpl, *pcIfImpl) mdInterfaceImpl* rgTypeDef,
                   ULONG cIfImpl,
                   __out ULONG* pcIfImpl);
};

//  Metadata enumerator specialized to enumerate methods.
class CMetadataMethodEnumerator : public CMetadataEnumerator<mdMethodDef> {
public:
    CMetadataMethodEnumerator(std::shared_ptr<CMetadataScope> spScope, mdTypeDef tkType)
        : CMetadataEnumerator<mdMethodDef>(spScope), _tkType(tkType) {
    }

private:
    mdTypeDef _tkType;
    bool Enumerate(__inout HCORENUM* hce,
                   __out_ecount_part(cMethods, *pcMethods) mdMethodDef* rgMethods,
                   ULONG cMethods,
                   __out ULONG* pcMethods);
};

//  Metadata enumerator specialized to enumerate custom attribute.
class CMetadataAttributeEnumerator : public CMetadataEnumerator<mdCustomAttribute> {
public:
    CMetadataAttributeEnumerator(std::shared_ptr<CMetadataScope> spScope, mdTypeDef tkType, mdToken tkElement)
        : CMetadataEnumerator<mdCustomAttribute>(spScope), _tkType(tkType), _tkElement(tkElement) {
    }

private:
    mdTypeDef _tkType;
    mdToken _tkElement;
    bool Enumerate(__inout HCORENUM* hce,
                   __out_ecount_part(cAttributes, *pcAttributes) mdMethodDef* rgAttributes,
                   ULONG cAttributes,
                   __out ULONG* pcAttributes);
};

//  Metadata enumerator specialized to enumerate custom attribute.
class CMetadataParameterEnumerator : public CMetadataEnumerator<mdParamDef> {
public:
    CMetadataParameterEnumerator(std::shared_ptr<CMetadataScope> spScope, mdMethodDef tkMethod)
        : CMetadataEnumerator<mdParamDef>(spScope), _tkMethod(tkMethod) {
    }

private:
    mdMethodDef _tkMethod;
    bool Enumerate(__inout HCORENUM* hce, __out_ecount_part(cParams, *pcParams) mdParamDef* rgParams, ULONG cParams, __out ULONG* pcParams);
};

//  Metadata enumerator specialized to enumerate properties.
class CMetadataPropertyEnumerator : public CMetadataEnumerator<mdProperty> {
public:
    CMetadataPropertyEnumerator(std::shared_ptr<CMetadataScope> spScope, mdTypeDef tkType)
        : CMetadataEnumerator<mdProperty>(spScope), _tkType(tkType) {
    }

private:
    mdTypeDef _tkType;
    bool Enumerate(__inout HCORENUM* hce,
                   __out_ecount_part(cProperties, *pcProperties) mdProperty* rgProperties,
                   ULONG cProperties,
                   __out ULONG* pcProperties);
};

//  Metadata enumerator specialized to enumerate events.
class CMetadataEventEnumerator : public CMetadataEnumerator<mdEvent> {
public:
    CMetadataEventEnumerator(std::shared_ptr<CMetadataScope> spScope, mdTypeDef tkType)
        : CMetadataEnumerator<mdProperty>(spScope), _tkType(tkType) {
    }

private:
    mdTypeDef _tkType;
    bool Enumerate(__inout HCORENUM* hce, __out_ecount_part(cEvents, *pcEvents) mdProperty* rgEvents, ULONG cEvents, __out ULONG* pcEvents);
};

//  Metadata enumerator specialized to enumerate type references.
class CMetadataTypeRefEnumerator : public CMetadataEnumerator<mdTypeRef> {
public:
    CMetadataTypeRefEnumerator(std::shared_ptr<CMetadataScope> spScope) : CMetadataEnumerator<mdTypeRef>(spScope) {
    }

private:
    bool Enumerate(__inout HCORENUM* hce,
                   __out_ecount_part(cTypes, *pcTypeRefs) mdTypeRef* rgTypeRef,
                   ULONG cTypes,
                   __out ULONG* pcTypeRefs);
};

//  Metadata enumerator specialized to enumerate generics.
class CMetadataGenericParamEnumerator : public CMetadataEnumerator<mdGenericParam> {
public:
    CMetadataGenericParamEnumerator(std::shared_ptr<CMetadataScope> spScope, mdToken tkType)
        : CMetadataEnumerator<mdGenericParam>(spScope), _tkType(tkType) {
    }

private:
    mdToken _tkType;
    bool Enumerate(__inout HCORENUM* hce,
                   __out_ecount_part(cParams, *pcParams) mdGenericParam* rgGenericParams,
                   ULONG cParams,
                   __out ULONG* pcParams);
};

//  Metadata enumerator specialized to enumerate generic constraints.
class CMetadataGenericConstraintEnumerator : public CMetadataEnumerator<mdGenericParamConstraint> {
public:
    CMetadataGenericConstraintEnumerator(std::shared_ptr<CMetadataScope> spScope, mdToken tkType)
        : CMetadataEnumerator<mdGenericParamConstraint>(spScope), _tkType(tkType) {
    }

private:
    mdToken _tkType;
    bool Enumerate(__inout HCORENUM* hce,
                   __out_ecount_part(cTypes, *pcGenericParamConstraints) mdGenericParamConstraint* rgGenericParamConstraintss,
                   ULONG cParamConstraintss,
                   __out ULONG* pcParamConstraints);
};

//  Metadata enumerator specialized to enumerate generic constraints.
class CMetadataMethodImplEnumerator : public CMetadataEnumerator<std::pair<mdToken, mdToken>> {
public:
    CMetadataMethodImplEnumerator(std::shared_ptr<CMetadataScope> spScope, mdToken tkType)
        : CMetadataEnumerator<std::pair<mdToken, mdToken>>(spScope), _tkType(tkType) {
    }

private:
    mdToken _tkType;
    bool Enumerate(__inout HCORENUM* hce,
                   __out_ecount_part(cmethodImpls, *pcmethodImpls) std::pair<mdToken, mdToken>* rgmethodImpl,
                   ULONG cmethodImpls,
                   __out ULONG* pcmethodImpls);
};

// Metadata enumerator specialized to enumerate assembly references.
class CMetadataAssemblyRefsEnumerator : public CMetadataEnumerator<mdAssemblyRef> {
public:
    CMetadataAssemblyRefsEnumerator(std::shared_ptr<CMetadataScope> spScope) : CMetadataEnumerator<mdAssemblyRef>(spScope) {
    }

private:
    mdToken _tkType;
    bool Enumerate(__inout HCORENUM* hce,
                   __out_ecount_part(cAssemblyRefs, *pcAssemblyRefs) mdAssemblyRef* rgAssemblyRefs,
                   ULONG cAssemblyRefs,
                   __out ULONG* pcAssemblyRefs);
};

class CMetadataFormatError : public std::exception {
public:
    CMetadataFormatError(CMetadataScope* spScope, HRESULT hr) : _strFileName(spScope->FileName()), _hr(hr) {
    }

    const std::wstring& FileName() {
        return _strFileName;
    }
    const HRESULT Error() {
        return _hr;
    }

private:
    std::wstring _strFileName;
    HRESULT _hr;
};
