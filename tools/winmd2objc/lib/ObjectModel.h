//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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
#include "MetadataScope.h"
#include <unordered_set>

const unsigned int MaxEnums = 128;
const unsigned int MaxTypeNameLen = 1024;

namespace ObjectModel {
enum TypeCategory {
    None = 0x0000,
    WinRtClass = 0x0001,
    WinRtInterface = 0x0002,
    WinRtEnum = 0x0003,
    WinRtStruct = 0x0004,
    WinRtDelegate = 0x0005,
    WinRtEvent = 0x0006,
    WinRtGenericParam = 0x0007,
    WinRtAttribute = 0x0008,
    WinRtNameSpace = 0x0009,
    WinRtApiContract = 0x000a,
    WinRtFundamental = 0x000b,
    WinRtArray = 0x000c,
    InvalidType = 0x000d, // used when we try to decode something that we didn't expect
    WinRtAttributeDef = 0x000e,
    UnresolvedType = 0x000f,
    WinRtCustomModifier = 0x0010,
    WinRtGeneric = 0x2000,
    WinRtByRef = 0x4000,
};

// ECMA II.23.2 Blobs and signatures
// In an specific set of cases, these modifiers are used to
// identify the type of pointer the element (eg enum, struct)
enum class ElementPointerKind {
    Unknown,
    ByRef, // ELEMENT_TYPE_BYREF
    Native, // ELEMENT_TYPE_PTR
};

// ECMA II.23.2.7 CustomMod (Custom Modifier)
enum class CustomModifierKind {
    Unknown,
    Optional,
    Required,
};

// See http://msdn.microsoft.com/en-us/library/bfft1t3c.aspx for the full list of value types
// When processing the metadata, use CorElementType to determine the kind.
enum class ElementTypeKind { Unknown, Value, String, Class };

class Visitor;
struct Symbol;
struct UnresolvedSymbol;
struct NameSpace;
struct BasicType;
struct Enum;
struct Attribute;
struct AttributeDef;
struct Struct;
struct Delegate;
struct Interface;
struct RuntimeClass;
struct ApiContract;
struct Array;
struct Generic;
struct GenericParam;
struct CustomAttributeParamInfo;
struct CustomModifier;

class Visitor {
public:
    Visitor() {
    }

public:
    virtual void Visit(const shared_ptr<NameSpace>&) {
    }

    virtual void Visit(const shared_ptr<Enum>&) {
    }

    virtual void Visit(const shared_ptr<Attribute>&) {
    }

    virtual void Visit(const shared_ptr<AttributeDef>&) {
    }

    virtual void Visit(const shared_ptr<Struct>&) {
    }

    virtual void Visit(const shared_ptr<Delegate>&) {
    }

    virtual void Visit(const shared_ptr<Interface>&) {
    }

    virtual void Visit(const shared_ptr<RuntimeClass>&) {
    }

    virtual void Visit(const shared_ptr<ApiContract>&) {
    }

    virtual void Visit(const shared_ptr<Array>&) {
    }

    virtual void Visit(const shared_ptr<Generic>&) {
    }

    virtual void Visit(const shared_ptr<GenericParam>&) {
    }

    virtual void Visit(const shared_ptr<BasicType>&) {
    }

    virtual void Visit(const shared_ptr<UnresolvedSymbol>&) {
    }

    virtual void Visit(const shared_ptr<CustomModifier>&) {
    }
};

struct RawType {
    mdToken tdef;
    wstring typeName;
    DWORD attrs;
    wstring extendsTypeName;
    ObjectModel::TypeCategory typeCategory;
    RawType(mdToken tkType, const wstring& name, DWORD dwAttrs, const wstring& extendsName, ObjectModel::TypeCategory category)
        : tdef(tkType), typeName(name), attrs(dwAttrs), extendsTypeName(extendsName), typeCategory(category) {
    }
};

// Contains information about a field in a Struct or Enum type
struct FieldInfo {
    shared_ptr<Symbol> ElementType;
    wstring ElementName;
    multimap<const wstring, shared_ptr<Attribute>> Attributes;
    bool IsPublic;
    bool HasFieldMarshalTableRow;
};

struct Symbol {
    wstring Name;
    wstring SourceFileName;
    mdToken Token;
    TypeCategory Category;
    shared_ptr<ObjectModel::RawType> RawType;
    multimap<const wstring, shared_ptr<CustomModifier>> CustomModifiers;
    bool IsPublic;
    ElementPointerKind PointerKind;
    ElementTypeKind TypeKind;

    Symbol(TypeCategory category, const wstring& name, mdToken token, shared_ptr<ObjectModel::RawType> type, const wstring& sourceFileName)
        : Category(category),
          Name(name),
          SourceFileName(sourceFileName),
          Token(token),
          RawType(type),
          PointerKind(ElementPointerKind::Unknown),
          TypeKind(ElementTypeKind::Unknown) {
        if (type == nullptr) {
            IsPublic = true;
        } else {
            IsPublic = IsTdPublic(type->attrs);
        }
    }
    Symbol() {
    }
    virtual ~Symbol() {
    }
    virtual void Visit(Visitor* /*visitor*/) = 0;
};

struct UnresolvedSymbol : Symbol, enable_shared_from_this<UnresolvedSymbol> {
    UnresolvedSymbol(const wstring& name,
                     mdToken token,
                     shared_ptr<ObjectModel::RawType>& type,
                     const wstring& sourceFileName,
                     TypeCategory category = TypeCategory::UnresolvedType)
        : Symbol(category, name, token, type, sourceFileName) {
    }
    virtual void Visit(Visitor* visitor) {
        visitor->Visit(shared_from_this());
    }
};
struct BasicType : Symbol, enable_shared_from_this<BasicType> {
    BasicType(const wstring& name, const wstring& sourceFileName, TypeCategory category = TypeCategory::None)
        : Symbol(category, name, mdTokenNil, nullptr, sourceFileName) {
    }
    virtual void Visit(Visitor* visitor) {
        visitor->Visit(shared_from_this());
    }
};

struct Attribute : Symbol, enable_shared_from_this<Attribute> {
    Attribute(const wstring& name, mdToken token, shared_ptr<ObjectModel::RawType> type, const wstring& sourceFileName)
        : Symbol(TypeCategory::WinRtAttribute, name, token, type, sourceFileName) {
    }
    virtual void Visit(Visitor* visitor) {
        visitor->Visit(shared_from_this());
    }
    vector<CustomAttributeParamInfo> FixedParameters;
    unordered_map<wstring, ObjectModel::CustomAttributeParamInfo> NamedParameters;
};

struct CustomModifier : Symbol, enable_shared_from_this<CustomModifier> {
    CustomModifier(CustomModifierKind kind, const wstring& sourceFileName)
        : Symbol(TypeCategory::WinRtCustomModifier, L"", mdTokenNil, nullptr, sourceFileName), Kind(kind) {
    }
    virtual void Visit(Visitor* visitor) {
        visitor->Visit(shared_from_this());
    }

    CustomModifierKind Kind;

    // ECMA II.7.1.1 modreq and modopt
    // "Each modifer associates a type reference with an item in the signature"
    // This type represents the type reference, eg System.Runtime.CompilerServices.IsConst
    shared_ptr<Symbol> Type;
};

struct Enum : Symbol, enable_shared_from_this<Enum> {
    Enum(const wstring& name, mdToken token, shared_ptr<ObjectModel::RawType> type, const wstring& sourceFileName)
        : Symbol(TypeCategory::WinRtEnum, name, token, type, sourceFileName), FlagsEnum(false), MaxElementNameLen(0) {
    }
    virtual void Visit(Visitor* visitor) {
        visitor->Visit(shared_from_this());
    }

    // Contains information about a static field in an enumeration
    // Special name fields are internally stored in a FieldInfo struct
    struct EnumerationLabel {
        wstring EnumerationName;
        unsigned int EnumerationValue;
        multimap<const wstring, shared_ptr<Attribute>> Attributes;
        bool IsPublic;
        bool HasDefault;
        bool IsStatic;
        bool IsLiteral;
    };

    vector<FieldInfo> SpecialNameFieldInfo;
    vector<EnumerationLabel> EnumerationLabels;
    multimap<const wstring, shared_ptr<Attribute>> Attributes;
    bool FlagsEnum;
    size_t MaxElementNameLen;
};

struct Struct : Symbol, enable_shared_from_this<Struct> {
    Struct(const wstring& name, mdToken token, shared_ptr<ObjectModel::RawType> type, const wstring& sourceFileName)
        : Symbol(TypeCategory::WinRtStruct, name, token, type, sourceFileName) {
    }
    virtual void Visit(Visitor* visitor) {
        visitor->Visit(shared_from_this());
    }
    vector<FieldInfo> Fields;
    multimap<const wstring, shared_ptr<Attribute>> Attributes;
};

struct ApiContract : Symbol, enable_shared_from_this<ApiContract> {
    PCCOR_SIGNATURE Signature;

    ApiContract(const wstring& name, mdToken token, shared_ptr<ObjectModel::RawType> type, const wstring& sourceFileName)
        : Symbol(TypeCategory::WinRtApiContract, name, token, type, sourceFileName) {
    }
    virtual void Visit(Visitor* visitor) {
        visitor->Visit(shared_from_this());
    }
    UINT32 ContractVersion;
    multimap<const wstring, shared_ptr<Attribute>> Attributes;
};

struct ParameterInfo {
    wstring Name;
    shared_ptr<Symbol> Type;
    multimap<const wstring, shared_ptr<Attribute>> Attributes;
    bool HasParamTableRow;
    bool HasDefault;
    bool HasFieldMarshalTableRow;
    bool IsOptional;
    bool IsInParam;
    bool IsOutParam;
    bool IsVoid;
    ParameterInfo(const wstring& name)
        : Name(name),
          HasDefault(false),
          HasParamTableRow(false),
          HasFieldMarshalTableRow(false),
          IsOptional(false),
          IsInParam(false),
          IsOutParam(false),
          IsVoid(false) {
    }
    ParameterInfo()
        : HasDefault(false),
          HasParamTableRow(false),
          HasFieldMarshalTableRow(false),
          IsOptional(false),
          IsInParam(false),
          IsOutParam(false),
          IsVoid(false) {
    }
};

struct CustomAttributeParamInfo {
    CustomAttributeParamInfo() : StringValue(L""), SignedIntValue(0), DoubleValue(0), Type(nullptr) {
    }

    bool operator!=(const CustomAttributeParamInfo& rhs) const {
        return !(*this == rhs);
    }

    bool operator==(const CustomAttributeParamInfo& rhs) const {
        if (Type->Name != rhs.Type->Name) {
            return false;
        }

        switch (ElementType) {
            case ELEMENT_TYPE_I1:
            case ELEMENT_TYPE_U1:
            case ELEMENT_TYPE_I2:
            case ELEMENT_TYPE_U2:
            case ELEMENT_TYPE_I4:
            case ELEMENT_TYPE_U4:
            case ELEMENT_TYPE_I8:
            case ELEMENT_TYPE_U8:
            case ELEMENT_TYPE_BOOLEAN:
            case SERIALIZATION_TYPE_ENUM:
                return (rhs.SignedIntValue == SignedIntValue);
                break;

            case SERIALIZATION_TYPE_TYPE:
            case ELEMENT_TYPE_STRING:
                return (rhs.StringValue == StringValue);
                break;

            case ELEMENT_TYPE_R4:
            case ELEMENT_TYPE_R8:
                return (rhs.DoubleValue == DoubleValue);
                break;

            default:
                return false;
                break;
        };

        return false;
    }

    shared_ptr<ObjectModel::BasicType> Type;
    wstring StringValue;
    LONGLONG SignedIntValue;
    double DoubleValue;
    ULONG ElementType;
};

struct MemberInfo {
    wstring Name;
    vector<ParameterInfo> Parameters;
    ParameterInfo ReturnParameter;
    multimap<const wstring, shared_ptr<Attribute>> Attributes;
    shared_ptr<MemberInfo> MethodImpl;
    shared_ptr<Symbol> MethodImplType;
    bool IsPublic;
    bool IsStatic;
    bool IsProtected;
    bool IsCtor;
    size_t InParamCount;
    size_t OutParamCount;
    bool HasOverload;
    bool HasDefaultOverload;
    bool IsHideBySig;
    bool IsSpecialName; // this is meaningful for custom attribute methods
    bool IsRtSpecialName; // this is meaningful for custom attribute methods
    MemberInfo()
        : InParamCount(0),
          OutParamCount(0),
          HasOverload(false),
          HasDefaultOverload(false),
          IsPublic(false),
          IsStatic(false),
          IsProtected(false),
          IsCtor(false),
          IsHideBySig(false),
          IsSpecialName(false),
          IsRtSpecialName(false) {
    }
};

struct Delegate : Symbol, enable_shared_from_this<Delegate> {
    PCCOR_SIGNATURE Signature;

    Delegate(
        const wstring& name, mdToken token, shared_ptr<ObjectModel::RawType> type, const wstring& sourceFileName, PCCOR_SIGNATURE signature)
        : Symbol(TypeCategory::WinRtDelegate, name, token, type, sourceFileName), Signature(signature) {
    }
    virtual void Visit(Visitor* visitor) {
        visitor->Visit(shared_from_this());
    }
    map<mdToken, shared_ptr<MemberInfo>> Members;
    multimap<const wstring, shared_ptr<Attribute>> Attributes;
};

struct InterfaceImplInfo {
    shared_ptr<Symbol> Type;
    multimap<const wstring, shared_ptr<Attribute>> Attributes;
};

struct MethodRef {
    mdToken Token;
    shared_ptr<MemberInfo> Info;
};

struct EventInfo {
    wstring Name;
    MethodRef Adder;
    MethodRef Remover;
};

struct PropertyInfo {
    wstring Name;
    MethodRef Getter;
    MethodRef Setter;
};

struct Interface : Symbol, enable_shared_from_this<Interface> {
    Interface(const wstring& name, mdToken token, shared_ptr<ObjectModel::RawType> type, const wstring& sourceFileName)
        : Symbol(TypeCategory::WinRtInterface, name, token, type, sourceFileName), IsExclusiveTo(false) {
    }
    virtual void Visit(Visitor* visitor) {
        visitor->Visit(shared_from_this());
    }
    map<mdToken, shared_ptr<MemberInfo>> Members;
    vector<InterfaceImplInfo> InterfaceImplements;
    vector<shared_ptr<EventInfo>> Events;
    vector<shared_ptr<PropertyInfo>> Properties;
    multimap<const wstring, shared_ptr<Attribute>> Attributes;
    bool IsExclusiveTo;
};

struct RuntimeClass : Symbol, enable_shared_from_this<RuntimeClass> {
    RuntimeClass(const wstring& name, mdToken token, shared_ptr<ObjectModel::RawType> type, const wstring& sourceFileName)
        : Symbol(TypeCategory::WinRtClass, name, token, type, sourceFileName),
          Extends(std::move(new ObjectModel::BasicType(L"", sourceFileName))),
          IsSealed(IsTdSealed(type->attrs) != 0),
          IsActivatable(false),
          IsComposable(false),
          IsAbstract(IsTdAbstract(type->attrs) != 0) {
    }
    virtual void Visit(Visitor* visitor) {
        visitor->Visit(shared_from_this());
    }

    std::shared_ptr<ObjectModel::BasicType> Extends;
    map<mdToken, shared_ptr<MemberInfo>> Members;
    vector<InterfaceImplInfo> InterfaceImplements;
    vector<shared_ptr<EventInfo>> Events;
    vector<shared_ptr<PropertyInfo>> Properties;
    multimap<const wstring, shared_ptr<Attribute>> Attributes;
    bool IsSealed;
    bool IsActivatable;
    bool IsComposable;
    bool IsAbstract;
};

struct AttributeDef : Symbol, enable_shared_from_this<AttributeDef> {
    AttributeDef(const wstring& name, mdToken token, shared_ptr<ObjectModel::RawType> type, const wstring& sourceFileName)
        : Symbol(TypeCategory::WinRtAttributeDef, name, token, type, sourceFileName) {
    }
    virtual void Visit(Visitor* visitor) {
        visitor->Visit(shared_from_this());
    }
    multimap<const wstring, shared_ptr<Attribute>> Attributes;
    vector<FieldInfo> Fields;
    map<mdToken, shared_ptr<MemberInfo>> Members;

    bool IsPublic;
};

struct NameSpace : Symbol, enable_shared_from_this<NameSpace> {
    NameSpace() {
    }
    NameSpace(
        TypeCategory category, const wstring& name, mdToken token, shared_ptr<ObjectModel::RawType> type, const wstring& sourceFileName)
        : Symbol(category, name, token, type, sourceFileName) {
    }

    virtual void Visit(Visitor* visitor) {
        visitor->Visit(shared_from_this());
    }

    vector<shared_ptr<Enum>> Enums;
    vector<shared_ptr<Struct>> Structs;
    vector<shared_ptr<Interface>> Interfaces;
    vector<shared_ptr<Delegate>> Delegates;
    vector<shared_ptr<RuntimeClass>> RuntimeClasses;
    vector<shared_ptr<AttributeDef>> AttributeDefs;
    vector<shared_ptr<ApiContract>> ApiContracts;
};

struct Array : public Symbol, enable_shared_from_this<Array> {
    Array(const wstring& name, mdToken token, const wstring& sourceFileName)
        : Symbol(TypeCategory::WinRtArray, name, token, nullptr, sourceFileName) {
    }
    virtual void Visit(Visitor* visitor) {
        visitor->Visit(shared_from_this());
    }
    enum ArrayCategory {
        InArray,
        FillArray,
        ReceiveArray,
    };
    shared_ptr<Symbol> Type;
    ArrayCategory ArrayCategory;
};

struct Generic : public Symbol, enable_shared_from_this<Generic> {
    Generic() = delete;

    Generic(const wstring& sourceFileName) : Symbol(TypeCategory::WinRtGeneric, L"", mdTokenNil, nullptr, sourceFileName) {
    }
    virtual void Visit(Visitor* visitor) {
        visitor->Visit(shared_from_this());
    }
    shared_ptr<Symbol> Type;
    vector<shared_ptr<Symbol>> Parameters;
    multimap<const wstring, shared_ptr<Attribute>> Attributes;
};

struct GenericParam : public Symbol, enable_shared_from_this<GenericParam> {
    GenericParam(const wchar_t* paramName, int paramIndex, const wstring& sourceFileName)
        : Symbol(TypeCategory::WinRtGenericParam, paramName, mdTokenNil, nullptr, sourceFileName), ParamIndex(paramIndex) {
    }
    virtual void Visit(Visitor* visitor) {
        visitor->Visit(shared_from_this());
    }
    int ParamIndex;
};

//  Returns true if the types are equal, false if they are not.
bool CompareTypes(const shared_ptr<ObjectModel::Symbol>& left,
                  const shared_ptr<ObjectModel::Symbol>& right,
                  const shared_ptr<ObjectModel::Generic>& genericImpl);
} // namespace ObjectModel

class MetaDataConvert {
    shared_ptr<CMetadataScope> _scope;
    std::map<std::wstring, std::shared_ptr<ObjectModel::NameSpace>> _namespaces;
    map<mdToken, shared_ptr<ObjectModel::RawType>> _resolvedTypes;
    map<const wstring, mdToken> _tokenFromType;
    map<wstring, shared_ptr<ObjectModel::Symbol>>& _fqnMap;
    wstring _fileName;

public:
    struct NamespaceDomain {
        unordered_set<wstring> rejectTypes;
        unordered_set<wstring> rejectNs;
        unordered_set<wstring> incTypes;
        unordered_set<wstring> incNs;
    };

    const shared_ptr<CMetadataScope>& Scope() {
        return _scope;
    }
    const wstring& FileName() {
        return _fileName;
    }

    MetaDataConvert(_In_ wstring filename, map<wstring, shared_ptr<ObjectModel::Symbol>>&);

    HRESULT ConvertMetaData(const MetaDataConvert::NamespaceDomain& nsDom = MetaDataConvert::NamespaceDomain());
    void NameFromToken(mdToken token, bool nameForParameter, shared_ptr<ObjectModel::Symbol>* sym);
    void VisitNamespaces(ObjectModel::Visitor* visitor);

    const wchar_t* GetNameSpaceFromFQN(const wchar_t* fqn) {
        return wcsrchr(fqn, '.');
    }

    void EnumerateTypeDefs(void (MetaDataConvert::*emiter)(mdTypeDef tdef)) {
        CMetadataTypeDefEnumerator tdEnum(_scope);

        for (auto it = tdEnum.begin(); it != tdEnum.end(); ++it) {
            (this->*emiter)(*it);
        }
    }

    //  Returns information about a token.  Returns true if information about the token could be
    //  retrieved, false otherwise.
    bool GetTypeInformation(mdToken token, shared_ptr<ObjectModel::RawType>& type) {
        if (token == mdTokenNil) {
            return false;
        }

        auto it = _resolvedTypes.find(token);
        if (it != _resolvedTypes.end()) {
            type = it->second;
            return true;
        }

        if (TypeFromToken(token) == mdtTypeRef) {
            wchar_t name[MaxTypeNameLen];
            name[0] = 0;
            ULONG nameLen = 0;
            mdToken resolutionScope;
            mdToken tDef;
            _scope->GetTypeRefProps(token, &resolutionScope, name, MaxTypeNameLen, &nameLen);

            //  Let's see if this is a self referential typeref. If it is, use the corresponding
            //  typedef, otherwise return false.
            auto tk = _tokenFromType.find(name);
            if (tk != _tokenFromType.end()) {
                token = tk->second;
            } else {
                if (_scope->FindTypeDefByName(name, mdTokenNil, &tDef)) {
                    token = tDef;
                    _tokenFromType.insert(std::move(pair<const wstring, mdToken>(name, token)));
                } else // This typeref isn't self referential, return false because we couldn't determine type information about it.
                {
                    return false;
                }
            }
        }

        wchar_t name[MaxTypeNameLen];
        name[0] = 0;
        ULONG nameLen = 0;
        mdToken extends;
        wchar_t extendsName[MaxTypeNameLen];
        extendsName[0] = 0;
        DWORD attrs;
        ObjectModel::TypeCategory typeCategory;

        _scope->GetTypeDefProps(token, name, MaxTypeNameLen, &nameLen, &attrs, &extends);

        if (!IsTdWindowsRuntime(attrs)) {
            typeCategory = ObjectModel::TypeCategory::None;
        } else if (IsTdInterface(attrs)) {
            typeCategory = ObjectModel::TypeCategory::WinRtInterface;
        } else {
            if (IsTdClass(attrs)) {
                typeCategory = ObjectModel::TypeCategory::WinRtClass;
                if (extends != mdTokenNil) {
                    mdToken ref = 0;
                    ULONG extendsNameLen = 0;
                    switch (TypeFromToken(extends)) {
                        case mdtTypeDef:
                            _scope->GetTypeDefProps(extends, extendsName, MaxTypeNameLen, &extendsNameLen, nullptr, nullptr);
                            break;
                        case mdtTypeRef:
                            _scope->GetTypeRefProps(extends, &ref, extendsName, MaxTypeNameLen, &extendsNameLen);
                            break;
                    }
                    if (extendsNameLen > 1) {
                        if (wcscmp(extendsName, L"System.Object") == 0) {
                            typeCategory = ObjectModel::TypeCategory::WinRtClass;
                        } else if (wcscmp(extendsName, L"System.Enum") == 0) {
                            typeCategory = ObjectModel::TypeCategory::WinRtEnum;
                        } else if (wcscmp(extendsName, L"System.ValueType") == 0) {
                            const void* pvData;
                            ULONG cbData;

                            if (_scope->GetCustomAttributeByName(token,
                                                                 L"Windows.Foundation.Metadata.ApiContractAttribute",
                                                                 &pvData,
                                                                 &cbData)) {
                                typeCategory = ObjectModel::TypeCategory::WinRtApiContract;
                            } else {
                                typeCategory = ObjectModel::TypeCategory::WinRtStruct;
                            }
                        } else if (wcscmp(extendsName, L"System.MulticastDelegate") == 0) {
                            typeCategory = ObjectModel::TypeCategory::WinRtDelegate;
                        } else if (wcscmp(extendsName, L"System.Attribute") == 0) {
                            typeCategory = ObjectModel::TypeCategory::WinRtAttributeDef;
                        }
                    }
                }
            } else {
                typeCategory = ObjectModel::TypeCategory::WinRtClass;
            }
        }
        if (wcschr(name, '`') != nullptr) {
            *reinterpret_cast<unsigned int*>(&typeCategory) |= ObjectModel::TypeCategory::WinRtGeneric;
        }

        type = shared_ptr<ObjectModel::RawType>(new ObjectModel::RawType(token, name, attrs, extendsName, typeCategory));

        //  Cache the return raw type so it can be looked up again.
        _resolvedTypes[token] = type;
        return true;
    }

    void AddTypeToNamespace(shared_ptr<ObjectModel::NameSpace>& nameSpace, mdTypeDef tdef) {
        shared_ptr<ObjectModel::RawType> type;
        GetTypeInformation(tdef, type);
        if (nameSpace->Name.length() > type->typeName.length()) {
            DebugBreak();
        }

        switch (type->typeCategory & ~ObjectModel::TypeCategory::WinRtGeneric) {
            case ObjectModel::TypeCategory::None:
                break;
            case ObjectModel::TypeCategory::WinRtClass: {
                auto rc(std::make_shared<ObjectModel::RuntimeClass>(type->typeName.c_str(), tdef, type, _fileName));
                if (type->extendsTypeName.length() != 0 && type->extendsTypeName.compare(L"System.Object") != 0) {
                    rc->Extends = std::make_shared<ObjectModel::BasicType>(type->extendsTypeName, _fileName);
                }
                nameSpace->RuntimeClasses.push_back(rc);
                _fqnMap[type->typeName] = rc;
            } break;
            case ObjectModel::TypeCategory::WinRtDelegate: {
                auto del = std::make_shared<ObjectModel::Delegate>(type->typeName.c_str(), tdef, type, _fileName, nullptr);
                nameSpace->Delegates.push_back(del);
                _fqnMap[type->typeName] = del;
            } break;
            case ObjectModel::TypeCategory::WinRtInterface: {
                auto iface = shared_ptr<ObjectModel::Interface>(new ObjectModel::Interface(type->typeName.c_str(), tdef, type, _fileName));
                nameSpace->Interfaces.push_back(iface);
                _fqnMap[type->typeName] = iface;
            } break;
            case ObjectModel::TypeCategory::WinRtStruct: {
                auto structure = shared_ptr<ObjectModel::Struct>(new ObjectModel::Struct(type->typeName.c_str(), tdef, type, _fileName));
                nameSpace->Structs.push_back(structure);
                _fqnMap[type->typeName] = structure;
            } break;
            case ObjectModel::TypeCategory::WinRtEnum: {
                auto enumeration = shared_ptr<ObjectModel::Enum>(new ObjectModel::Enum(type->typeName.c_str(), tdef, type, _fileName));
                nameSpace->Enums.push_back(enumeration);
                _fqnMap[type->typeName] = enumeration;
            } break;
            case ObjectModel::TypeCategory::WinRtAttributeDef: {
                auto attrDef =
                    shared_ptr<ObjectModel::AttributeDef>(new ObjectModel::AttributeDef(type->typeName.c_str(), tdef, type, _fileName));
                nameSpace->AttributeDefs.push_back(attrDef);
                _fqnMap[type->typeName] = attrDef;
            } break;
            case ObjectModel::TypeCategory::WinRtApiContract: {
                auto contract = make_shared<ObjectModel::ApiContract>(type->typeName.c_str(), tdef, type, _fileName);
                nameSpace->ApiContracts.push_back(contract);
                _fqnMap[type->typeName] = contract;
            } break;
        }
    }

    void CollectNamespaces(mdTypeDef tdef) {
        wchar_t name[MaxTypeNameLen];
        name[0] = 0;
        ULONG nameLen = 0;
        DWORD attrs = 0;
        mdToken extends;
        wchar_t extendsName[MaxTypeNameLen];
        extendsName[0] = 0;

        _scope->GetTypeDefProps(tdef, name, MaxTypeNameLen, &nameLen, &attrs, &extends);
        // Skip Nested types and non-WinRT types
        if ((attrs & tdVisibilityMask) > tdPublic || !IsTdWindowsRuntime(attrs)) {
            return;
        }

        // Determine the namespace. If there is not one, set it to an empty string.
        wstring nameSpace;
        const wchar_t* lastDot = GetNameSpaceFromFQN(name);
        if (nullptr == lastDot) {
            nameSpace = wstring(L"");
        } else {
            nameSpace = wstring((const wchar_t*)name, lastDot);
        }

        if (_namespaces.find(nameSpace) == _namespaces.end()) {
            shared_ptr<ObjectModel::NameSpace> ns(
                new ObjectModel::NameSpace(ObjectModel::WinRtNameSpace, nameSpace, mdTokenNil, nullptr, _fileName));
            _namespaces[nameSpace] = ns;
        }
        auto ns = _namespaces.find(nameSpace);
        AddTypeToNamespace(ns->second, tdef);
    }

    HRESULT DecodeEncodeSignatures(CorTokenType tokenType,
                                   ULONG signatureColumn,
                                   ULONG (MetaDataConvert::*decoder)(PCCOR_SIGNATURE, ULONG, std::vector<std::wstring>& signatureBlob));
    bool GetValueFromCustomAttributeSig(CustomAttributeParser& CA, ULONG elemType, ObjectModel::CustomAttributeParamInfo& parameter);
    bool GetCustomAttributeInformation(mdCustomAttribute token, shared_ptr<ObjectModel::Attribute> attribute);
};

struct MultiFileObjectModel {
public:
    map<wstring, shared_ptr<ObjectModel::Symbol>> _fqnMap;

    MultiFileObjectModel(vector<wstring> filenames);
    void VisitNamespaces(ObjectModel::Visitor* visitor);
    map<const wstring, shared_ptr<MetaDataConvert>> _perFileModels;
};

static const wchar_t* IntrinsicTypeMap[] = {
    // Keep this list in the same order as CorElementType enumeration order
    // The initial entries are indexed on the enum
    L"END",
    L"void",
    L"Boolean",
    L"Char16",

    L"Int8",
    L"UInt8",

    L"Int16",
    L"UInt16",

    L"Int32",
    L"UInt32",

    L"Int64",
    L"UInt64",

    L"Single",
    L"Double",

    L"String",
    // END CorElementType enumeration order

    // Object should be the first entry after String
    L"IInspectable*",
    L"IntPtr",
    L"UIntPtr",
};
