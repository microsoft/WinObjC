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

// Define a set of helper classes for enumrating metadata symbols and doing RAII cleanup.
// Inspired by CMetadataEnumerator used in mdmerge.exe
#pragma once
#include <cor.h>
#include <comdef.h>
#include <utility>
#include <vector>
#include <string>
#include <WRL/client.h>

namespace Metadata {
namespace Error {
struct MetadataError {
    MetadataError(const std::wstring& what, HRESULT hr) : what_(what.c_str()), hr_(hr) {
    }
    MetadataError(const wchar_t* what, HRESULT hr) : what_(what), hr_(hr) {
    }
#pragma warning(push)
#pragma warning(disable : 4702) // disable: unreachable code
    HRESULT Result() const {
        return hr_;
    }
#pragma warning(pop)
    const wchar_t* What() const {
        return what_;
    }

private:
    const wchar_t* what_;
    HRESULT hr_;
};
}
}
template <class metadataType, class TImport>
class CMetadataEnumeratorT {
    class iterator : public std::iterator<std::input_iterator_tag, metadataType> {
    public:
        iterator(__in CMetadataEnumeratorT* pEnumerator) : _pEnumerator(pEnumerator), _iTypeCurrent(0) {
            _fContinueIterating = _pEnumerator->Enumerate(&_pEnumerator->_hce, _tkTypes, ARRAYSIZE(_tkTypes), &_cTypes);
        }

        iterator() : _pEnumerator(nullptr), _fContinueIterating(false) {
        }

        //  Note that this only works when comparing against
        //  the iterator returned by CRuntimeImplementsEnumerator.end().  It is
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
                _fContinueIterating = _pEnumerator->Enumerate(&_pEnumerator->_hce, _tkTypes, _countof(_tkTypes), &_cTypes);
                _iTypeCurrent = 0;
            }
            return (*this);
        }

        metadataType operator*() {
            return (_tkTypes[_iTypeCurrent]);
        }

    private:
        CMetadataEnumeratorT* _pEnumerator;
        bool _fContinueIterating;
        size_t _iTypeCurrent;
        ULONG _cTypes;
        metadataType _tkTypes[8];
    };

public:
    iterator begin() {
        return iterator(this);
    }
    iterator end() {
        return iterator();
    }

    CMetadataEnumeratorT(__in TImport* pMetaDataReader) : _spMetaDataImport(pMetaDataReader), _hce(nullptr) {
    }

    virtual ~CMetadataEnumeratorT() {
        if (_hce != nullptr) {
            _spMetaDataImport->CloseEnum(_hce);
            _hce = nullptr;
        }
    }

protected:
    bool Enumerate(__inout HCORENUM* hce,
                   __out_ecount_part(cTypes, *pcTypeDefs) metadataType* rgTypeDef,
                   ULONG cTypes,
                   __out ULONG* pcTypeDefs) {
        bool fRet = false;

        HRESULT hr = _Enumerate(hce, rgTypeDef, cTypes, pcTypeDefs);

        if (FAILED(hr)) {
            *pcTypeDefs = 0; // Reset the out parameter.
            throw Metadata::Error::MetadataError(L"error enumerating tokens", hr);
        } else if (hr == S_OK) {
            fRet = true;
        }

        return fRet;
    }

    virtual HRESULT _Enumerate(__inout HCORENUM* hce,
                               __out_ecount_part(cTypes, *pcTypeDefs) metadataType* rgTypeDef,
                               ULONG cTypes,
                               __out ULONG* pcTypeDefs) = 0;

    Microsoft::WRL::ComPtr<TImport> _spMetaDataImport;

private:
    HCORENUM _hce;
};

// Enumerators based on IMetaDataImport2
template <class metadataType>
class CTypeEnumeratorT : public CMetadataEnumeratorT<metadataType, IMetaDataImport2> {
public:
    CTypeEnumeratorT(__in IMetaDataImport2* pMetaDataImport) : CMetadataEnumeratorT(pMetaDataImport) {
    }

    virtual ~CTypeEnumeratorT() {
    }
};

// Enumerators based on IMetaDataAssemblyImport
template <class metadataType>
class CAssemblyEnumeratorT : public CMetadataEnumeratorT<metadataType, IMetaDataAssemblyImport> {
public:
    CAssemblyEnumeratorT(__in IMetaDataAssemblyImport* pMetaDataAssemblyImport) : CMetadataEnumeratorT(pMetaDataAssemblyImport) {
    }

    virtual ~CAssemblyEnumeratorT() {
    }
};

//  Metadata enumerator specialized to enumerate methods.
class CMethodEnumerator : public CTypeEnumeratorT<mdMethodDef> {
public:
    CMethodEnumerator(__in IMetaDataImport2* pMetaDataReader, mdTypeDef tkType)
        : CTypeEnumeratorT<mdMethodDef>(pMetaDataReader), _tkType(tkType) {
    }

protected:
    __override HRESULT _Enumerate(__inout HCORENUM* hce,
                                  __out_ecount_part(cMethods, *pcMethods) mdMethodDef* rgMethods,
                                  ULONG cMethods,
                                  __out ULONG* pcMethods) {
        return _spMetaDataImport->EnumMethods(hce, _tkType, rgMethods, cMethods, pcMethods);
    }

private:
    mdTypeDef _tkType;
};

//  Metadata enumerator specialized to enumerate custom attribute.
class CMethodParameterEnumerator : public CTypeEnumeratorT<mdParamDef> {
public:
    CMethodParameterEnumerator(__in IMetaDataImport2* pMetaDataReader, mdMethodDef tkMethod)
        : CTypeEnumeratorT<mdParamDef>(pMetaDataReader), _tkMethod(tkMethod) {
    }

protected:
    __override HRESULT _Enumerate(__inout HCORENUM* hce,
                                  __out_ecount_part(cParams, *pcParams) mdMethodDef* rgParams,
                                  ULONG cParams,
                                  __out ULONG* pcParams) {
        return _spMetaDataImport->EnumParams(hce, _tkMethod, rgParams, cParams, pcParams);
    }

private:
    mdMethodDef _tkMethod;
};

//  Metadata enumerator specialized to enumerate custom attribute.
class CTypeFieldEnumerator : public CTypeEnumeratorT<mdFieldDef> {
public:
    CTypeFieldEnumerator(__in IMetaDataImport2* pMetaDataReader, mdMethodDef tkType)
        : CTypeEnumeratorT<mdParamDef>(pMetaDataReader), _tkType(tkType) {
    }

protected:
    __override HRESULT _Enumerate(__inout HCORENUM* hce,
                                  __out_ecount_part(cFields, *pcFields) mdMethodDef* rgFields,
                                  ULONG cFields,
                                  __out ULONG* pcFields) {
        return _spMetaDataImport->EnumFields(hce, _tkType, rgFields, cFields, pcFields);
    };

private:
    mdTypeDef _tkType;
};

//  Metadata enumerator specialized to enumerate interface implements
//  elements.
class CInterfaceImplEnumerator : public CTypeEnumeratorT<mdInterfaceImpl> {
public:
    CInterfaceImplEnumerator(__in IMetaDataImport2* pMetaDataReader, mdTypeDef tkType)
        : CTypeEnumeratorT<mdInterfaceImpl>(pMetaDataReader), _tkType(tkType) {
    }

protected:
    __override HRESULT _Enumerate(__inout HCORENUM* hce,
                                  __out_ecount_part(cIfImpl, *pcIfImpl) mdInterfaceImpl* rgIfImpl,
                                  ULONG cIfImpl,
                                  __out ULONG* pcIfImpl) {
        return _spMetaDataImport->EnumInterfaceImpls(hce, _tkType, rgIfImpl, cIfImpl, pcIfImpl);
    }

private:
    mdTypeDef _tkType;
};

//  Metadata enumerator specialized to enumerate custom attributes
class CCustomAttributeEnumerator : public CTypeEnumeratorT<mdCustomAttribute> {
public:
    CCustomAttributeEnumerator(__in IMetaDataImport2* pMetaDataReader, mdTypeDef tkType)
        : CTypeEnumeratorT<mdCustomAttribute>(pMetaDataReader), _tkType(tkType) {
    }

protected:
    __override HRESULT _Enumerate(__inout HCORENUM* hce,
                                  __out_ecount_part(cAttributes, *pcAttributes) mdMethodDef* rgAttributes,
                                  ULONG cAttributes,
                                  __out ULONG* pcAttributes) {
        return _spMetaDataImport->EnumCustomAttributes(hce, _tkType, 0, rgAttributes, cAttributes, pcAttributes);
    }

private:
    mdTypeDef _tkType;
};

//  Metadata enumerator specialized to enumerate properties
//  elements.
class CPropertyEnumerator : public CTypeEnumeratorT<mdProperty> {
public:
    CPropertyEnumerator(__in IMetaDataImport2* pMetaDataReader, mdTypeDef tkType)
        : CTypeEnumeratorT<mdProperty>(pMetaDataReader), _tkType(tkType) {
    }

protected:
    __override HRESULT _Enumerate(__inout HCORENUM* hce,
                                  __out_ecount_part(cProperties, *pcProperties) mdInterfaceImpl* rgProperties,
                                  ULONG cProperties,
                                  __out ULONG* pcProperties) {
        return _spMetaDataImport->EnumProperties(hce, _tkType, rgProperties, cProperties, pcProperties);
    }

private:
    mdTypeDef _tkType;
};

//  Metadata enumerator specialized to enumerate properties
//  elements.
class CEventEnumerator : public CTypeEnumeratorT<mdEvent> {
public:
    CEventEnumerator(__in IMetaDataImport2* pMetaDataReader, mdTypeDef tkType)
        : CTypeEnumeratorT<mdEvent>(pMetaDataReader), _tkType(tkType) {
    }

protected:
    __override HRESULT _Enumerate(__inout HCORENUM* hce,
                                  __out_ecount_part(cEvents, *pcEvents) mdProperty* rgEvents,
                                  ULONG cEvents,
                                  __out ULONG* pcEvents) {
        return _spMetaDataImport->EnumEvents(hce, _tkType, rgEvents, cEvents, pcEvents);
    }

private:
    mdTypeDef _tkType;
};

//  Metadata enumerator specialized to enumerate methodImpl
class CMethodImplEnumerator : public CTypeEnumeratorT<std::pair<mdToken, mdToken>> {
public:
    CMethodImplEnumerator(__in IMetaDataImport2* pMetaDataReader, mdToken tkType)
        : CTypeEnumeratorT<std::pair<mdToken, mdToken>>(pMetaDataReader), _tkType(tkType) {
    }

protected:
    __override HRESULT _Enumerate(__inout HCORENUM* hce,
                                  __out_ecount_part(cMethodImpls, *pcMethodImpls) std::pair<mdToken, mdToken>* rgMethodImpls,
                                  ULONG cMethodImpls,
                                  __out ULONG* pcMethodImpls) {
        std::vector<mdToken> rgMethodBody(cMethodImpls);
        std::vector<mdToken> rgMethodDecl(cMethodImpls);

        HRESULT hr;
        if (SUCCEEDED(
                hr = _spMetaDataImport->EnumMethodImpls(hce, _tkType, &rgMethodBody[0], &rgMethodDecl[0], cMethodImpls, pcMethodImpls))) {
            // oacr is confused since all functions in cor.h, which are published by DevDiv, miss SAL annotations.
            // However IMetaDataImport::EnumMethodImpls never returns something which will overrun the input buffer.
            __analysis_assume(*pcMethodImpls <= cMethodImpls);

            for (ULONG i = 0; i < *pcMethodImpls; i += 1) {
                rgMethodImpls[i].first = rgMethodBody[i];
                rgMethodImpls[i].second = rgMethodDecl[i];
            }
        }

        return hr;
    }

private:
    mdToken _tkType;
};

//  Metadata enumerator specialized to enumerate TypeRef
//  This class currently is only used in DRT.
class CTypeRefEnumerator : public CTypeEnumeratorT<mdTypeRef> {
public:
    CTypeRefEnumerator(__in IMetaDataImport2* pMetaDataReader) : CTypeEnumeratorT<mdTypeRef>(pMetaDataReader) {
    }

protected:
    __override HRESULT _Enumerate(__inout HCORENUM* hce,
                                  __out_ecount_part(cTypeRefs, *pcTypeRefs) mdTypeRef* rgTypeRefs,
                                  ULONG cTypeRefs,
                                  __out ULONG* pcTypeRefs) {
        return _spMetaDataImport->EnumTypeRefs(hce, rgTypeRefs, cTypeRefs, pcTypeRefs);
    }
};

//  Metadata enumerator specialized to enumerate MemberRef
//  This class currently is only used in DRT.
class CMemberRefEnumerator : public CTypeEnumeratorT<mdMemberRef> {
public:
    CMemberRefEnumerator(__in IMetaDataImport2* pMetaDataReader, mdToken tkType)
        : CTypeEnumeratorT<mdMemberRef>(pMetaDataReader), _tokenTypeRef(tkType) {
    }

protected:
    __override HRESULT _Enumerate(__inout HCORENUM* hce,
                                  __out_ecount_part(cMemberRefs, *pcMemberRefs) mdMemberRef* rgMemberRefs,
                                  ULONG cMemberRefs,
                                  __out ULONG* pcMemberRefs) {
        return _spMetaDataImport->EnumMemberRefs(hce, _tokenTypeRef, rgMemberRefs, cMemberRefs, pcMemberRefs);
    }

private:
    mdToken _tokenTypeRef;
};

//  Metadata enumerator specialized to enumerate assemblyRef
//  elements.
class CAssemblyRefEnumerator : public CAssemblyEnumeratorT<mdAssemblyRef> {
public:
    CAssemblyRefEnumerator(__in IMetaDataAssemblyImport* pMetaDataAssemblyImport)
        : CAssemblyEnumeratorT<mdAssemblyRef>(pMetaDataAssemblyImport) {
    }

protected:
    __override HRESULT _Enumerate(__inout HCORENUM* hce,
                                  __out_ecount_part(cAssemblyRef, *pcAssemblyRef) mdAssemblyRef* rgAssemblyRefs,
                                  ULONG cAssemblyRef,
                                  __out ULONG* pcAssemblyRef) {
        return _spMetaDataImport->EnumAssemblyRefs(hce, rgAssemblyRefs, cAssemblyRef, pcAssemblyRef);
    }
};