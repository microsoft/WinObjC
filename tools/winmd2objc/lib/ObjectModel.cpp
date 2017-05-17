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
#include <ObjectModel.h>
#include <MetadataScope.h>

using namespace std;

//#include <utility.h>
//#include <WexTestClass.h>
//
//#define LOGFILE_OUTPUT(ftm, ...)                            \
//    {                                                           \
//        String output = L"<DebugOutput>";                       \
//        output += EscapeXml(String().Format(ftm, __VA_ARGS__)); \
//        output += L"</DebugOutput>";                            \
//        WEX::Logging::Log::Xml(output);                                       \
//    }

namespace ObjectModel {
class DecodeMetadata : public Visitor {
    MetaDataConvert* _converter;
    wstring _currentNameSpace;

    ULONG GetMethodSigSize(PCCOR_SIGNATURE signature);
    ULONG DecodeEncodeSig(PCCOR_SIGNATURE signature,
                          ULONG signatureLength,
                          mdParamDef parameterToken = mdTokenNil,
                          bool returnParameter = false,
                          shared_ptr<ObjectModel::Symbol>* sym = nullptr);
    ULONG DecodeEncodeFieldSigs(PCCOR_SIGNATURE signature, ULONG signatureLength, ObjectModel::FieldInfo& elementInfo);
    ULONG DecodeEncodeMethodSigs(mdMethodDef methodTokenm,
                                 PCCOR_SIGNATURE signature,
                                 ULONG signatureLength,
                                 ObjectModel::MemberInfo& memberInfo);
    ULONG DecodeEncodeTypeSpecSigs(PCCOR_SIGNATURE signature, ULONG signatureLength, shared_ptr<ObjectModel::Symbol>* sym = nullptr);
    void NameFromToken(mdToken token, bool nameForParameter = true, shared_ptr<ObjectModel::Symbol>* sym = nullptr);
    void DecodeMetadata::DecodeParamAttrs(ULONG attrs, ObjectModel::ParameterInfo& paramInfo);

public:
    DecodeMetadata(MetaDataConvert* converter, const wstring& currentNameSpace)
        : _converter(converter),
          _currentNameSpace(currentNameSpace)

    {
    }

    virtual void Visit(const shared_ptr<NameSpace>& nameSpace) {
        for (auto it = nameSpace->Enums.begin(); it != nameSpace->Enums.end(); it++) {
            (*it)->Visit(this);
        }
        for (auto it = nameSpace->Structs.begin(); it != nameSpace->Structs.end(); it++) {
            (*it)->Visit(this);
        }
        for (auto it = nameSpace->Delegates.begin(); it != nameSpace->Delegates.end(); it++) {
            (*it)->Visit(this);
        }
        for (auto it = nameSpace->Interfaces.begin(); it != nameSpace->Interfaces.end(); it++) {
            (*it)->Visit(this);
        }
        for (auto it = nameSpace->RuntimeClasses.begin(); it != nameSpace->RuntimeClasses.end(); it++) {
            (*it)->Visit(this);
        }
        for (auto it = nameSpace->ApiContracts.begin(); it != nameSpace->ApiContracts.end(); it++) {
            (*it)->Visit(this);
        }
        for (auto it = nameSpace->AttributeDefs.begin(); it != nameSpace->AttributeDefs.end(); it++) {
            (*it)->Visit(this);
        }
    }

    virtual void Visit(const shared_ptr<Enum>& e) {
        if (e->Category & ObjectModel::TypeCategory::WinRtGeneric) {
            return;
        }
        PopulateAttributes(e->Token, e->Attributes);

        wchar_t name[MaxTypeNameLen];
        name[0] = 0;
        ULONG nameLen = 0;
        DWORD attrs = 0;
        PCCOR_SIGNATURE sig;
        ULONG sigLen;
        UVCP_CONSTANT constValue;
        ULONG constValueLen;

        e->FlagsEnum = HasAttribute(e->Token, L"System.FlagsAttribute");
        size_t maxNameLen = 0;
        CMetadataFieldEnumerator enumFields(_converter->Scope(), e->Token);
        for (auto it = enumFields.begin(); it != enumFields.end(); ++it) {
            _converter->Scope()
                ->GetFieldProps(*it, nullptr, name, MaxTypeNameLen, &nameLen, &attrs, &sig, &sigLen, nullptr, &constValue, &constValueLen);

            // Gather any types defined in the enumeration
            if (IsFdSpecialName(attrs)) {
                ObjectModel::FieldInfo specialTypeInfo;
                DecodeEncodeFieldSigs(sig, sigLen, specialTypeInfo);
                specialTypeInfo.ElementName = name;
                specialTypeInfo.IsPublic = IsFdPublic(attrs);
                e->SpecialNameFieldInfo.push_back(std::move(specialTypeInfo));
            } else {
                ObjectModel::Enum::EnumerationLabel enumerationLabel = { name, *(unsigned int const*)constValue };
                if (maxNameLen < enumerationLabel.EnumerationName.length()) {
                    maxNameLen = enumerationLabel.EnumerationName.length();
                }
                PopulateAttributes(*it, enumerationLabel.Attributes);
                enumerationLabel.IsPublic = IsFdPublic(attrs);
                enumerationLabel.HasDefault = (IsFdHasDefault(attrs) != 0);
                enumerationLabel.IsStatic = (IsFdStatic(attrs) != 0);
                enumerationLabel.IsLiteral = (IsFdLiteral(attrs) != 0);
                e->EnumerationLabels.push_back(std::move(enumerationLabel));
            }
        }
        e->MaxElementNameLen = maxNameLen;
    }

    virtual void Visit(const shared_ptr<Struct>& s) {
        if (s->Category & ObjectModel::TypeCategory::WinRtGeneric) {
            return;
        }
        PopulateAttributes(s->Token, s->Attributes);
        PopulateFields(s->Token, s->Fields);
    }

    virtual void Visit(const shared_ptr<Delegate>& d) {
        if (d->Category & ObjectModel::TypeCategory::WinRtGeneric) {
            return;
        }
        PopulateAttributes(d->Token, d->Attributes);
        //                        EmitCustomAttributes(d.Token, false);

        PopulateMembers(d->Token, d->Members);
    }

    bool HasAttribute(mdToken token, const wchar_t* attributeName) {
        const void* attributeValue = nullptr;
        ULONG attributeLen = 0;
        _converter->Scope()->GetCustomAttributeByName(token, attributeName, &attributeValue, &attributeLen);
        if (attributeLen != 0) {
            return true;
        }
        return false;
    }

    void PopulateAttributes(mdToken token, multimap<const wstring, shared_ptr<Attribute>>& attributes) {
        if (!IsNilToken(token)) {
            wchar_t name[MaxTypeNameLen];
            name[0] = 0;

            CMetadataAttributeEnumerator enumAttribs(_converter->Scope(), token, 0);
            for (auto it = enumAttribs.begin(); it != enumAttribs.end(); ++it) {
                auto attribute = make_shared<Attribute>(L"", mdTokenNil, nullptr, _converter->FileName());
                if (_converter->GetCustomAttributeInformation(*it, attribute)) {
                    attributes.insert(std::move(make_pair(attribute->Name, attribute)));
                }
            }
        }
    }

    void PopulateInterfaceImplInfo(mdToken tdef, vector<InterfaceImplInfo>& interfaceImplInfo) {
        CMetadataInterfaceImplEnumerator iiEnum(_converter->Scope(), tdef);
        for (auto it = iiEnum.begin(); it != iiEnum.end(); ++it) {
            mdToken implementsToken;
            _converter->Scope()->GetInterfaceImplProps(*it, nullptr, &implementsToken);
            shared_ptr<Symbol> symbol;
            NameFromToken(implementsToken, false, &symbol);
            InterfaceImplInfo interfaceImpl = { symbol };
            PopulateAttributes(*it, interfaceImpl.Attributes);
            interfaceImplInfo.push_back(std::move(interfaceImpl));
        }
    }

    void PopulateMembers(mdToken tdef, map<mdToken, shared_ptr<MemberInfo>>& members) {
        CMetadataMethodEnumerator enumMethods(_converter->Scope(), tdef);
        for (auto it = enumMethods.begin(); it != enumMethods.end(); ++it) {
            wchar_t name[MaxTypeNameLen];
            name[0] = 0;
            ULONG nameLen = 0;
            DWORD attrs = 0;
            PCCOR_SIGNATURE sig;
            ULONG sigLen;

            _converter->Scope()->GetMemberProps(
                *it, nullptr, name, MaxTypeNameLen, &nameLen, &attrs, &sig, &sigLen, nullptr, nullptr, nullptr, nullptr, nullptr);

            auto memberInfo = make_shared<MemberInfo>();
            memberInfo->Name = name;
            PopulateAttributes(*it, memberInfo->Attributes);
            memberInfo->IsPublic = IsMdPublic(attrs);
            memberInfo->IsStatic = (IsMdStatic(attrs) != 0);
            memberInfo->IsProtected = (IsMdFamily(attrs) != 0);
            memberInfo->IsCtor = IsMdInstanceInitializerW(attrs, name);
            memberInfo->IsHideBySig = (IsMdHideBySig(attrs) != 0);
            memberInfo->IsSpecialName = (IsMdSpecialName(attrs) != 0);
            memberInfo->IsRtSpecialName = (IsMdRTSpecialName(attrs) != 0);

            if (HasAttribute(*it, L"Windows.Foundation.Metadata.OverloadAttribute")) {
                memberInfo->HasOverload = true;
            }
            if (HasAttribute(*it, L"Windows.Foundation.Metadata.DefaultOverloadAttribute")) {
                memberInfo->HasDefaultOverload = true;
            }

            DecodeEncodeMethodSigs(*it, sig, sigLen, *memberInfo);

            members.insert(std::move(std::make_pair(*it, std::move(memberInfo))));
        }
    }

    void PopulateFields(mdToken tdef, vector<FieldInfo>& fields) {
        CMetadataFieldEnumerator enumFields(_converter->Scope(), tdef);
        for (auto it = enumFields.begin(); it != enumFields.end(); ++it) {
            wchar_t name[MaxTypeNameLen];
            name[0] = 0;
            ULONG nameLen = 0;
            DWORD attrs = 0;
            PCCOR_SIGNATURE sig;
            ULONG sigLen;
            UVCP_CONSTANT constValue;
            ULONG constValueLen;
            PCCOR_SIGNATURE marshalSig;
            ULONG marshalSigLen = 0;

            _converter->Scope()
                ->GetFieldProps(*it, nullptr, name, MaxTypeNameLen, &nameLen, &attrs, &sig, &sigLen, nullptr, &constValue, &constValueLen);

            ObjectModel::FieldInfo fieldInfo;
            fieldInfo.ElementName = name;
            fieldInfo.IsPublic = IsFdPublic(attrs);
            fieldInfo.HasFieldMarshalTableRow = _converter->Scope()->GetFieldMarshal(*it, &marshalSig, &marshalSigLen);
            PopulateAttributes(*it, fieldInfo.Attributes);
            DecodeEncodeFieldSigs(sig, sigLen, fieldInfo);
            if (!IsFdSpecialName(attrs)) {
                // Add to Fields
                fields.push_back(std::move(fieldInfo));
            }
        }
    }

    void GetEvents(mdToken token, vector<shared_ptr<EventInfo>>& info) {
        CMetadataEventEnumerator eventEnum(_converter->Scope(), token);
        for (auto it = eventEnum.begin(); it != eventEnum.end(); ++it) {
            mdMethodDef eventAdd = mdTokenNil;
            mdMethodDef eventRemove = mdTokenNil;
            wchar_t name[MaxTypeNameLen];
            name[0] = 0;
            ULONG nameLen = 0;
            _converter->Scope()->GetEventProps(
                *it, nullptr, name, MaxTypeNameLen, &nameLen, nullptr, nullptr, &eventAdd, &eventRemove, nullptr, nullptr, 0, nullptr);
            {
                auto event = make_shared<EventInfo>();
                event->Name = name;
                if (eventAdd != mdTokenNil) {
                    event->Adder.Token = eventAdd;
                }
                if (eventRemove != mdTokenNil) {
                    event->Remover.Token = eventRemove;
                }
                info.push_back(std::move(event));
            }
        }
    }

    void GetProperties(mdToken token, vector<shared_ptr<PropertyInfo>>& info) {
        CMetadataPropertyEnumerator propertyEnum(_converter->Scope(), token);
        for (auto it = propertyEnum.begin(); it != propertyEnum.end(); ++it) {
            mdMethodDef propertyGet = mdTokenNil;
            mdMethodDef propertySet = mdTokenNil;
            mdMethodDef other[128];
            ULONG otherCount = 0;
            wchar_t name[MaxTypeNameLen];
            name[0] = 0;
            ULONG nameLen = 0;

            _converter->Scope()->GetPropertyProps(*it,
                                                  nullptr,
                                                  name,
                                                  MaxTypeNameLen,
                                                  &nameLen,
                                                  nullptr,
                                                  nullptr,
                                                  nullptr,
                                                  nullptr,
                                                  nullptr,
                                                  nullptr,
                                                  &propertySet,
                                                  &propertyGet,
                                                  other,
                                                  128,
                                                  &otherCount);
            {
                auto property(std::make_shared<PropertyInfo>());
                property->Name = name;
                if (propertyGet != mdTokenNil) {
                    property->Getter.Token = propertyGet;
                }
                if (propertySet != mdTokenNil) {
                    property->Setter.Token = propertySet;
                }
                info.push_back(std::move(property));
            }
        }
    }

    void HandleEventMethods(vector<shared_ptr<EventInfo>>& info, map<mdToken, shared_ptr<MemberInfo>>& members) {
        for (auto it : info) {
            auto adderMember = members.find(it->Adder.Token);
            if (adderMember != members.end()) {
                it->Adder.Info = adderMember->second;
            }

            auto removerMember = members.find(it->Remover.Token);
            if (removerMember != members.end()) {
                it->Remover.Info = removerMember->second;
            }
        }
    }

    void HandlePropertyMethods(vector<shared_ptr<PropertyInfo>>& info, map<mdToken, shared_ptr<MemberInfo>>& members) {
        for (auto it : info) {
            auto getterMember = members.find(it->Getter.Token);
            if (getterMember != members.end()) {
                it->Getter.Info = getterMember->second;
            }

            auto setterMember = members.find(it->Setter.Token);
            if (setterMember != members.end()) {
                it->Setter.Info = setterMember->second;
            }
        }
    }

    virtual void Visit(const shared_ptr<Interface>& iface) {
        if (iface->Category & ObjectModel::TypeCategory::WinRtGeneric) {
            return;
        }
        GetEvents(iface->Token, iface->Events);
        GetProperties(iface->Token, iface->Properties);
        PopulateAttributes(iface->Token, iface->Attributes);
        //                        EmitCustomAttributes(iface.Token, false);
        iface->IsExclusiveTo = HasAttribute(iface->Token, L"Windows.Foundation.Metadata.ExclusiveToAttribute");

        PopulateInterfaceImplInfo(iface->Token, iface->InterfaceImplements);
        PopulateMembers(iface->Token, iface->Members);
        HandleEventMethods(iface->Events, iface->Members);
        HandlePropertyMethods(iface->Properties, iface->Members);
    }

    virtual void Visit(const shared_ptr<RuntimeClass>& r) {
        if (r->Category & ObjectModel::TypeCategory::WinRtGeneric) {
            return;
        }
        PopulateAttributes(r->Token, r->Attributes);
        GetEvents(r->Token, r->Events);
        GetProperties(r->Token, r->Properties);
        //                        EmitCustomAttributes(r.Token, false);

        PopulateInterfaceImplInfo(r->Token, r->InterfaceImplements);

        if (HasAttribute(r->Token, L"Windows.Foundation.Metadata.ActivatableAttribute")) {
            r->IsActivatable = true;
        }
        if (HasAttribute(r->Token, L"Windows.Foundation.Metadata.ComposableAttribute")) {
            r->IsComposable = true;
        }

        PopulateMembers(r->Token, r->Members);
        HandleEventMethods(r->Events, r->Members);
        HandlePropertyMethods(r->Properties, r->Members);

        CMetadataMethodImplEnumerator enumMethodImpl(_converter->Scope(), r->Token);
        for (auto it = enumMethodImpl.begin(); it != enumMethodImpl.end(); ++it) {
            mdToken tkMethodBody = (*it).first; // The method implementation in the implementation class.
            mdToken tkMethodDecl = (*it).second; // The method declaration in this class.

            //    If this member is the source of the methodimpl table row, hook up its
            //    implementation type.
            if (r->Members[tkMethodBody] != nullptr) {
                mdToken tkMemberClass = mdTokenNil;
                wchar_t rgchMemberName[MaxTypeNameLen];
                ULONG nameLen = 0;
                PCCOR_SIGNATURE sig = nullptr;
                ULONG sigLen = 0;
                if (TypeFromToken(tkMethodDecl) == mdtMemberRef) {
                    _converter->Scope()->GetMemberRefProps(
                        tkMethodDecl, &tkMemberClass, rgchMemberName, ARRAYSIZE(rgchMemberName), &nameLen, &sig, &sigLen);
                } else if (TypeFromToken(tkMethodDecl) == mdtMethodDef) {
                    _converter->Scope()->GetMemberProps(tkMethodDecl,
                                                        &tkMemberClass,
                                                        rgchMemberName,
                                                        ARRAYSIZE(rgchMemberName),
                                                        &nameLen,
                                                        nullptr,
                                                        &sig,
                                                        &sigLen,
                                                        nullptr,
                                                        nullptr,
                                                        nullptr,
                                                        nullptr,
                                                        nullptr);
                }
                //
                //    Ok, we now have the class which contains the implementation.  The
                //    next step is to figure out which member in that class implements
                //    this method.
                //
                auto memberInfoRef = make_shared<MemberInfo>();
                memberInfoRef->Name = rgchMemberName; // Remember the method name on the destination type.
                DecodeEncodeMethodSigs(mdTokenNil, sig, sigLen, *memberInfoRef);

                //    Remember the name of the type which implements the method.
                NameFromToken(tkMemberClass, false, &r->Members[tkMethodBody]->MethodImplType);
                r->Members[tkMethodBody]->MethodImpl = std::move(memberInfoRef);
            }
        }
    }

    virtual void Visit(const shared_ptr<AttributeDef>& attrDef) {
        if (attrDef->Category & ObjectModel::TypeCategory::WinRtGeneric) {
            return;
        }

        PopulateAttributes(attrDef->Token, attrDef->Attributes);
        PopulateMembers(attrDef->Token, attrDef->Members);
        PopulateFields(attrDef->Token, attrDef->Fields);

        attrDef->IsPublic = IsTdPublic(attrDef->RawType->attrs);
    }

    virtual void Visit(const shared_ptr<Array>&) {
    }

    virtual void Visit(const shared_ptr<Generic>& /*generic*/) {
    }

    virtual void Visit(const shared_ptr<BasicType>&) {
    }
};

//  Generate a generic specialization name for the generic type implType given the typespec
//  description contained in typeSpec.  The typeSpec allows us to find the actual types which
//  correspond to the generic types listed in the implType.
wstring GenerateGenericSpecializationName(const shared_ptr<ObjectModel::Generic>& implType,
                                          const shared_ptr<ObjectModel::Generic>& typeSpec) {
    wstringstream ssTypeName;
    ssTypeName << implType->Type->Name << L"<";
    for (auto it = implType->Parameters.begin(); it != implType->Parameters.end(); it++) {
        if ((*it)->Category == ObjectModel::WinRtGenericParam) {
            shared_ptr<ObjectModel::GenericParam> param = static_pointer_cast<ObjectModel::GenericParam>((*it));
            ssTypeName << typeSpec->Parameters[param->ParamIndex]->Name;
        } else {
            ssTypeName << (*it)->Name;
        }

        //  If we're not done, add in a comma.
        if (it + 1 != implType->Parameters.end()) {
            ssTypeName << L",";
        }
    }
    ssTypeName << L">";
    return ssTypeName.str();
}

//  Returns true if the types are equal, false if they are not.
//
//  Note that when comparing typespecs, the left type is always the method type and the
//  right type is always the methodimpl type (and thus may be a generic).

//
//  When comparing two types, the first thing you want to do is to check for null (void) types.
//  After that, two types are equal iff their names are equal.  It's that simple.  There are
//  two special cases that need to be considered.
//
//  The first is when you're comparing a type and a generic.  In that case, if you have a
//  generic specialization available for the type on the left, calculate the name of the
//  generic substituting the generic params for the corresponding types in the typespec.
//
//  The second case happens when you compare a type with a generic parameter.  In that case, if
//  you have a generic specialization, simply use the type from the generic specialization
//  instead.
//
//  Note that we won't have to recurse on generics - that's because even if an entry in the
//  typespec is a generic, it's a specific generic specialization and you can use the name of
//  that specialization in the replacement.
//
bool CompareTypes(const shared_ptr<ObjectModel::Symbol>& left,
                  const shared_ptr<ObjectModel::Symbol>& right,
                  const shared_ptr<ObjectModel::Generic>& typeSpec) {
    //  Check for null types - if both left and right are the same pointer (or if both are null
    //  (void)), it's a match.
    if (left == right) {
        return true;
    }
    //  If either is null, they don't match (we know that they're not both null.
    if (left == nullptr || right == nullptr) {
        return false;
    }

    //  Pull out the left and right names.
    wstring leftTypeName(left->Name);
    wstring rightTypeName(right->Name);

    //  If the implementation type is a generic, find the corresponding parameter in the
    //  typespec specification (in the genericImpl)
    if (typeSpec != nullptr) {
        if (right->Category == ObjectModel::WinRtGeneric) {
            rightTypeName = GenerateGenericSpecializationName(static_pointer_cast<ObjectModel::Generic>(right), typeSpec);
        }

        if (right->Category == ObjectModel::WinRtGenericParam) {
            rightTypeName = typeSpec->Parameters[static_pointer_cast<ObjectModel::GenericParam>(right)->ParamIndex]->Name;
        }
    }
    return (leftTypeName == rightTypeName);
}
} // namespace ObjectModel

MetaDataConvert::MetaDataConvert(_In_ wstring filename, map<wstring, shared_ptr<ObjectModel::Symbol>>& fqnMap)
    : _fileName(filename), _fqnMap(fqnMap), _scope(new CMetadataScope(filename)) {
}

HRESULT MetaDataConvert::ConvertMetaData(const MetaDataConvert::NamespaceDomain& nsDom) {
    HRESULT hr = S_OK;

    if (!_scope->CreateScope(CMetadataScope::ScopeType::ReadOnly)) {
        return E_FAIL;
    }

    // Determine the version of the winmd file
    wchar_t szVersionString[128];
    DWORD cchVersionString;
    _scope->GetVersionString(szVersionString, ARRAYSIZE(szVersionString), &cchVersionString);
    _scope->DetermineMetadataFormatVersion(szVersionString);

    // Collect unique namespaces in the WinMD
    EnumerateTypeDefs(&MetaDataConvert::CollectNamespaces);

    // Remove wayward namespaces
    if (nsDom.incNs.size()) {
        auto oldNamespaces = _namespaces;
        for (auto it : oldNamespaces) {
            bool remove = true;
            for (auto ns : nsDom.incNs) {
                if (it.first.substr(0, ns.length()) == ns) {
                    remove = false;
                    break;
                }
            }
            if (remove) {
                _namespaces.erase(it.first);
            }
        }
    }
    if (nsDom.rejectNs.size()) {
        auto oldNamespaces = _namespaces;
        for (auto ns : nsDom.rejectNs) {
            for (auto it : oldNamespaces) {
                if (it.first.substr(0, ns.length()) == ns) {
                    _namespaces.erase(it.first);
                }
            }
        }
    }

    for (auto it = _namespaces.begin(); it != _namespaces.end(); it++) {
        // Decode Metadata for types in namespace
        {
            ObjectModel::DecodeMetadata decodeVisitor(this, it->first);
            it->second->Visit(&decodeVisitor);
        }
    }

    // Remove wayward types
    for (auto type : nsDom.rejectTypes) {
        _fqnMap.erase(type);
    }
    auto oldTypes = _fqnMap;
    if (nsDom.incTypes.size()) {
        for (auto type : oldTypes) {
            if (nsDom.incTypes.find(type.first) == nsDom.incTypes.end()) {
                _fqnMap.erase(type.first);
            }
        }
    }

    return hr;
}

void MetaDataConvert::VisitNamespaces(ObjectModel::Visitor* visitor) {
    for (auto it = _namespaces.begin(); it != _namespaces.end(); it++) {
        it->second->Visit(visitor);
    }
}

namespace ObjectModel {
ULONG DecodeMetadata::DecodeEncodeSig(PCCOR_SIGNATURE signature,
                                      ULONG signatureLength,
                                      mdParamDef parameterToken,
                                      bool returnParameter,
                                      shared_ptr<ObjectModel::Symbol>* sym) {
    if (sym == nullptr) {
        DebugBreak();
    }

    CorElementType elementType = static_cast<CorElementType>(signature[0]);
    ULONG bytesUsed = 1;
    bool isOutParam = false;

    //  If we have a param token, check to see if it's null.
    if (parameterToken != mdTokenNil) {
        ULONG attrs = 0;
        _converter->Scope()->GetParamProps(parameterToken, nullptr, nullptr, nullptr, 0, nullptr, &attrs, nullptr, nullptr, nullptr);
        if (IsPdOut(attrs)) {
            isOutParam = true;
        }
    }

    switch (elementType) {
        case ELEMENT_TYPE_VOID: {
            if (returnParameter) {
                *sym = nullptr;
                break;
            }
        }
        case ELEMENT_TYPE_BOOLEAN:
        case ELEMENT_TYPE_CHAR:
        case ELEMENT_TYPE_I1:
        case ELEMENT_TYPE_U1:
        case ELEMENT_TYPE_I2:
        case ELEMENT_TYPE_U2:
        case ELEMENT_TYPE_I4:
        case ELEMENT_TYPE_U4:
        case ELEMENT_TYPE_I8:
        case ELEMENT_TYPE_U8:
        case ELEMENT_TYPE_R4:
        case ELEMENT_TYPE_R8: {
            shared_ptr<ObjectModel::Symbol> symbol(
                new ObjectModel::BasicType(IntrinsicTypeMap[elementType], _converter->FileName(), TypeCategory::WinRtFundamental));
            symbol->TypeKind = ElementTypeKind::Value;
            *sym = (std::move(symbol));
        } break;
        case ELEMENT_TYPE_STRING: {
            shared_ptr<ObjectModel::Symbol> symbol(
                new ObjectModel::BasicType(IntrinsicTypeMap[elementType], _converter->FileName(), TypeCategory::WinRtFundamental));
            symbol->TypeKind = ElementTypeKind::String;
            *sym = (std::move(symbol));
        } break;
        case ELEMENT_TYPE_OBJECT: {
            *sym = std::move(shared_ptr<ObjectModel::BasicType>(new ObjectModel::BasicType(L"System.Object", _converter->FileName())));
        } break;

        case ELEMENT_TYPE_ARRAY: {
            shared_ptr<ObjectModel::Array> arrayType(new ObjectModel::Array(L"", mdTokenNil, _converter->FileName()));
            if (returnParameter || isOutParam) {
                arrayType->ArrayCategory = ObjectModel::Array::ArrayCategory::FillArray;
            } else {
                arrayType->ArrayCategory = ObjectModel::Array::ArrayCategory::InArray;
            }

            // Decode the type
            bytesUsed += DecodeEncodeSig(signature + bytesUsed, signatureLength, mdTokenNil, returnParameter, &arrayType->Type);

            // Decode the rank
            ULONG rank;
            bytesUsed += CorSigUncompressData(signature + bytesUsed, &rank);

            // Decode all the dimension sizes
            ULONG numSizes;
            bytesUsed += CorSigUncompressData(signature + bytesUsed, &numSizes);
            for (ULONG i = 0; i < numSizes; i++) {
                ULONG size;
                bytesUsed += CorSigUncompressData(signature + bytesUsed, &size);
            }

            // Decode all the dimension lower bounds
            ULONG numLoBounds;
            bytesUsed += CorSigUncompressData(signature + bytesUsed, &numLoBounds);
            for (ULONG i = 0; i < numLoBounds; i++) {
                int loBound;
                bytesUsed += CorSigUncompressSignedInt(signature + bytesUsed, &loBound);
            }

            // Invalidate the type. The info parsed above will be discarded; we just needed to go through the motions to get the correct
            // bytesUsed.
            shared_ptr<ObjectModel::BasicType> tmpSym(
                new ObjectModel::BasicType(L"ELEMENT_TYPE_ARRAY", _converter->FileName(), ObjectModel::TypeCategory::InvalidType));
            *sym = std::move(tmpSym);
        } break;
        case ELEMENT_TYPE_SZARRAY: {
            shared_ptr<ObjectModel::Array> arrayType(new ObjectModel::Array(L"", mdTokenNil, _converter->FileName()));
            if (returnParameter || isOutParam) {
                arrayType->ArrayCategory = ObjectModel::Array::ArrayCategory::FillArray;
            } else {
                arrayType->ArrayCategory = ObjectModel::Array::ArrayCategory::InArray;
            }

            bytesUsed += DecodeEncodeSig(signature + bytesUsed, signatureLength, mdTokenNil, returnParameter, &arrayType->Type);
            *sym = std::move(arrayType);
        } break;

        case ELEMENT_TYPE_VALUETYPE:
        case ELEMENT_TYPE_CLASS: {
            mdToken token;
            ULONG bytesUsedTemp = CorSigUncompressToken(signature + bytesUsed, &token);
            bytesUsed += bytesUsedTemp;
            NameFromToken(token, true, sym);

            if (elementType == ELEMENT_TYPE_VALUETYPE) {
                (*sym)->TypeKind = ElementTypeKind::Value;
            } else {
                (*sym)->TypeKind = ElementTypeKind::Class;
            }

        } break;

        case ELEMENT_TYPE_CMOD_REQD:
        case ELEMENT_TYPE_CMOD_OPT: {
            // Custom Modifiers
            // Example of format: ELEMENT_TYPE_CUSTOMMOD_OPT TYPEREF1 ELEMENT_TYPE_CUSTOMMOD_OPT TYPEREF2 ELEMENT_TYPE_VALUE_TYPE (or other
            // like ELEMENT_TYPE_CLASS)
            // A custom modifier is associated with a Type (the last one in the format).
            // In some cases there might be something in the middle (last MOD_OPT and Type) which is processed when hitting the type (eg,
            // ELEMENT_TYPE_PINNED).
            // Upon hitting ELEMENT_TYPE_CMOD_OPT, process them all, process the Type and return the Type with all the custom modifiers

            // ECMA II.23.2.10 Param
            // There can be multiple Custom Modifiers, for example in parameters
            multimap<const wstring, shared_ptr<CustomModifier>> customModifiers;
            CorElementType currentElementType = elementType;

            do {
                mdToken token = mdTokenNil;

                shared_ptr<CustomModifier> customModifierSymbol(make_shared<CustomModifier>((currentElementType == ELEMENT_TYPE_CMOD_OPT) ?
                                                                                                CustomModifierKind::Optional :
                                                                                                CustomModifierKind::Required,
                                                                                            _converter->FileName()));

                bytesUsed += CorSigUncompressToken(signature + bytesUsed, &token);
                NameFromToken(token, true, &customModifierSymbol->Type);

                customModifiers.emplace(std::move(make_pair(customModifierSymbol->Type->Name, customModifierSymbol)));

                currentElementType = static_cast<CorElementType>((bytesUsed + signature)[0]);
            } while ((currentElementType == ELEMENT_TYPE_CMOD_OPT) || (currentElementType == ELEMENT_TYPE_CMOD_REQD));

            bytesUsed += DecodeEncodeSig(signature + bytesUsed, signatureLength, mdTokenNil, returnParameter, sym);

            (*sym)->CustomModifiers = std::move(customModifiers);

            break;
        }
        case ELEMENT_TYPE_I:
        case ELEMENT_TYPE_U: {
            shared_ptr<ObjectModel::Symbol> symbol(
                new ObjectModel::BasicType(IntrinsicTypeMap[ELEMENT_TYPE_STRING + 2 + (elementType - ELEMENT_TYPE_I)],
                                           _converter->FileName(),
                                           ObjectModel::TypeCategory::InvalidType));
            *sym = (std::move(symbol));
        } break;

        case ELEMENT_TYPE_END:
        case ELEMENT_TYPE_SENTINEL: {
            shared_ptr<ObjectModel::BasicType> tmpSym(
                new ObjectModel::BasicType(L"End/Sentinel", _converter->FileName(), ObjectModel::TypeCategory::InvalidType));
            *sym = std::move(tmpSym);
        } break;

        case ELEMENT_TYPE_VAR:
        case ELEMENT_TYPE_MVAR: {
            wchar_t buf[128];
            ULONG val;
            bytesUsed += CorSigUncompressData(signature + bytesUsed, &val);
            _ultow_s(val, buf, 10);
            shared_ptr<ObjectModel::Symbol> symbol(new ObjectModel::GenericParam(buf, val, _converter->FileName()));
            *sym = (std::move(symbol));
        } break;

        case ELEMENT_TYPE_GENERICINST: {
            //  Parse the generic instance.  Also calculate the name of the generic instance,
            //  this will later be used to compare type names.
            wstringstream strGenericName;
            shared_ptr<ObjectModel::Generic> genericSym(new ObjectModel::Generic(_converter->FileName()));
            bytesUsed += DecodeEncodeSig(signature + bytesUsed, signatureLength, mdTokenNil, false, &genericSym->Type);
            strGenericName << genericSym->Type->Name << L"<";

            ULONG argcnt = static_cast<ULONG>(signature[bytesUsed]);
            bytesUsed++;
            for (ULONG i = 0; i < argcnt; i++) {
                shared_ptr<ObjectModel::Symbol> genericArgument;
                bytesUsed += DecodeEncodeSig(signature + bytesUsed, signatureLength, mdTokenNil, false, &genericArgument);
                strGenericName << genericArgument->Name;
                genericSym->Parameters.push_back(std::move(genericArgument));
                if (i + 1 < argcnt) {
                    strGenericName << L",";
                }
            }
            strGenericName << L">";
            genericSym->Name = std::move(strGenericName.str());
            *sym = std::move(genericSym);
        } break;

        case ELEMENT_TYPE_PTR: {
            bytesUsed += DecodeEncodeSig(signature + bytesUsed, signatureLength, mdTokenNil, false, sym);

            (*sym)->PointerKind = ElementPointerKind::Native;
        } break;

        case ELEMENT_TYPE_BYREF: {
            bytesUsed += DecodeEncodeSig(signature + bytesUsed, signatureLength, mdTokenNil, false, sym);
            if ((*sym)->Category == TypeCategory::WinRtArray) {
                reinterpret_cast<Array*>((*sym).get())->ArrayCategory = Array::ArrayCategory::ReceiveArray;
            }

            (*sym)->PointerKind = ElementPointerKind::ByRef;
        } break;

        case ELEMENT_TYPE_INTERNAL:
        case ELEMENT_TYPE_PINNED: {
            bytesUsed += DecodeEncodeSig(signature + bytesUsed, signatureLength, mdTokenNil, false, sym);
        } break;
        case ELEMENT_TYPE_FNPTR: {
            bytesUsed += GetMethodSigSize(signature + bytesUsed);
            shared_ptr<ObjectModel::BasicType> tmpSym(
                new ObjectModel::BasicType(L"FunctionPointer", _converter->FileName(), ObjectModel::TypeCategory::InvalidType));
            *sym = std::move(tmpSym);
        } break;
        default: {
            // we have no idea what we saw here, so gracefully mark it as such
            shared_ptr<ObjectModel::BasicType> tmpSym(
                new ObjectModel::BasicType(L"UnknownType", _converter->FileName(), ObjectModel::TypeCategory::InvalidType));
            *sym = std::move(tmpSym);
        } break;
    }

    return bytesUsed;
}

ULONG DecodeMetadata::DecodeEncodeFieldSigs(PCCOR_SIGNATURE signature, ULONG signatureLength, ObjectModel::FieldInfo& elementInfo) {
    ULONG bytesUsed = 1;

    bytesUsed += DecodeEncodeSig(signature + bytesUsed, signatureLength, mdTokenNil, false, &elementInfo.ElementType);

    return bytesUsed;
}

void DecodeMetadata::DecodeParamAttrs(ULONG attrs, ObjectModel::ParameterInfo& paramInfo) {
    paramInfo.IsOutParam = (IsPdOut(attrs) != 0);
    paramInfo.IsInParam = (IsPdIn(attrs) != 0);
    paramInfo.IsOptional = (IsPdOptional(attrs) != 0);
    paramInfo.HasDefault = (IsPdHasDefault(attrs) != 0);
}

// Determines the length of a method's signature
// This is useful for skipping over a method signature in the case of function pointers
//
// Arguments:
//    signature: the signature object to use to determine the length of the sig
//
// Returns:
//    the length of the method signature
ULONG DecodeMetadata::GetMethodSigSize(PCCOR_SIGNATURE signature) {
    ULONG bytesUsed = 1;
    ULONG paramCount = 0;
    shared_ptr<ObjectModel::Symbol> spDummy(nullptr);

    bytesUsed += CorSigUncompressData(signature + bytesUsed, &paramCount);
    bytesUsed += DecodeEncodeSig(signature + bytesUsed, 0, mdTokenNil, false, &spDummy);

    for (unsigned int n = 0; n < paramCount; n++) {
        bytesUsed += DecodeEncodeSig(signature + bytesUsed, 0, mdTokenNil, false, &spDummy);
    }

    return bytesUsed;
}

ULONG DecodeMetadata::DecodeEncodeMethodSigs(mdMethodDef methodToken,
                                             PCCOR_SIGNATURE signature,
                                             ULONG signatureLength,
                                             ObjectModel::MemberInfo& memberInfo) {
    ULONG bytesUsed = 1;

    // BYTE callingConvention = signature[0];

    ULONG paramCount = 0;
    ULONG bytesUsedTemp = CorSigUncompressData(signature + bytesUsed, &paramCount);

    bytesUsed += bytesUsedTemp;

    mdParamDef paramToken = mdTokenNil;

    if (!IsNilToken(methodToken)) {
        _converter->Scope()->GetParamForMethodIndex(methodToken, 0, &paramToken);
    }

    // Return Type
    if (!IsNilToken(paramToken)) {
        wchar_t name[MaxTypeNameLen];
        name[0] = 0;
        ULONG nameLen = 0;
        PCCOR_SIGNATURE marshalSig;
        ULONG marshalSigLen = 0;

        ULONG attrs = 0;
        _converter->Scope()->GetParamProps(paramToken, nullptr, nullptr, name, MaxTypeNameLen, &nameLen, &attrs, nullptr, nullptr, nullptr);
        memberInfo.ReturnParameter.Name = name;
        memberInfo.ReturnParameter.HasFieldMarshalTableRow = _converter->Scope()->GetFieldMarshal(paramToken, &marshalSig, &marshalSigLen);

        DecodeParamAttrs(attrs, memberInfo.ReturnParameter);
    }
    memberInfo.ReturnParameter.IsOutParam = true;

    bytesUsed += DecodeEncodeSig(signature + bytesUsed, signatureLength, paramToken, true, &memberInfo.ReturnParameter.Type);
    memberInfo.ReturnParameter.IsVoid = (memberInfo.ReturnParameter.Type == nullptr);

    //  Resize the parameters vector so we don't reallocate on every parameter.
    memberInfo.Parameters.reserve(paramCount);

    // Parameters
    for (unsigned int n = 0; n < paramCount; n++) {
        wchar_t name[MaxTypeNameLen];
        name[0] = 0;
        ULONG nameLen = 0;
        ULONG attrs = 0;
        bool hasParamTableRow = false;

        if (!IsNilToken(methodToken)) {
            _converter->Scope()->GetParamForMethodIndex(methodToken, n + 1, &paramToken);
            if (!IsNilToken(paramToken)) {
                _converter->Scope()
                    ->GetParamProps(paramToken, nullptr, nullptr, name, MaxTypeNameLen, &nameLen, &attrs, nullptr, nullptr, nullptr);
                hasParamTableRow = true;
            }
        }

        ParameterInfo parameterInfo(name);
        parameterInfo.HasParamTableRow = hasParamTableRow;

        if (!IsNilToken(paramToken)) {
            PCCOR_SIGNATURE marshalSig;
            ULONG marshalSigLen = 0;

            PopulateAttributes(paramToken, parameterInfo.Attributes);
            parameterInfo.HasFieldMarshalTableRow = _converter->Scope()->GetFieldMarshal(paramToken, &marshalSig, &marshalSigLen);
        }
        DecodeParamAttrs(attrs, parameterInfo);

        bytesUsed += DecodeEncodeSig(signature + bytesUsed, signatureLength, paramToken, false, &parameterInfo.Type);
        parameterInfo.IsVoid = false;

        //  If this is an in parameter, account for it.
        //  There's one strange exception to the "in parameter" rule: For the purposes of
        //  overload detection, an out parameter which matches the FillArray pattern will also
        //  count as an "in" parameter.
        if (IsPdIn(attrs) ||
            (IsPdOut(attrs) && parameterInfo.Type != nullptr && (parameterInfo.Type->Category == WinRtArray) &&
             (static_pointer_cast<ObjectModel::Array>(parameterInfo.Type)->ArrayCategory == ObjectModel::Array::FillArray))) {
            memberInfo.InParamCount += 1;
        } else if (IsPdOut(attrs)) {
            memberInfo.OutParamCount += 1;
        }

        memberInfo.Parameters.push_back(std::move(parameterInfo));
    }

    return bytesUsed;
}

ULONG DecodeMetadata::DecodeEncodeTypeSpecSigs(PCCOR_SIGNATURE signature, ULONG signatureLength, shared_ptr<ObjectModel::Symbol>* sym) {
    ULONG bytesUsed = 0;
    bytesUsed += DecodeEncodeSig(signature + bytesUsed, signatureLength, mdTokenNil, false, sym);
    return bytesUsed;
}

void DecodeMetadata::NameFromToken(mdToken token, bool nameForParameter, shared_ptr<ObjectModel::Symbol>* sym) {
    if (TypeFromToken(token) == mdtTypeSpec) {
        PCCOR_SIGNATURE sig;
        ULONG sigLen;

        _converter->Scope()->GetTypeSpecFromToken(token, &sig, &sigLen);
        DecodeEncodeTypeSpecSigs(sig, sigLen, sym);
        return;
    }
    _converter->NameFromToken(token, nameForParameter, sym);
}
} // namespace ObjectModel

void MetaDataConvert::NameFromToken(mdToken token, bool nameForParameter, shared_ptr<ObjectModel::Symbol>* sym) {
    if (sym == nullptr) {
        DebugBreak();
    }
    if (IsNilToken(token)) {
        return;
    }

    if (TypeFromToken(token) == mdtTypeDef) {
        shared_ptr<ObjectModel::RawType> type;
        GetTypeInformation(token,
                           type); // This should always succeed because it's dealing with a typedef (and thus is within the winmd file).

        *sym = std::move(shared_ptr<ObjectModel::Symbol>(new ObjectModel::UnresolvedSymbol(type->typeName, token, type, _fileName)));
        if (!nameForParameter && (type->typeCategory & ObjectModel::TypeCategory::WinRtGeneric)) {
            shared_ptr<ObjectModel::Generic> typeGeneric(new ObjectModel::Generic(_fileName));
            typeGeneric->Type = std::move(*sym);
            *sym = std::move(typeGeneric);
        }
        return;
    } else if (TypeFromToken(token) == mdtTypeRef) {
        shared_ptr<ObjectModel::RawType> type;
        //  If we couldn't figure out the type information, it's probably because the type was an
        //  external typeref.
        if (!GetTypeInformation(token, type)) {
            mdToken resolutionScope;
            wchar_t name[MaxTypeNameLen];
            name[0] = 0;
            ULONG nameLen = 0;

            Scope()->GetTypeRefProps(token, &resolutionScope, name, MaxTypeNameLen, &nameLen);
            type =
                shared_ptr<ObjectModel::RawType>(new ObjectModel::RawType(token, name, 0, L"", ObjectModel::TypeCategory::UnresolvedType));
        }
        if (type->typeName.compare(L"System.Guid") == 0) {
            *sym = std::move(shared_ptr<ObjectModel::Symbol>(
                new ObjectModel::BasicType(L"GUID", _fileName, ObjectModel::TypeCategory::WinRtFundamental)));
            return;
        }

        *sym = std::move(shared_ptr<ObjectModel::Symbol>(new ObjectModel::UnresolvedSymbol(type->typeName, token, type, _fileName)));
        if (!nameForParameter && type->typeCategory & ObjectModel::TypeCategory::WinRtGeneric) {
            shared_ptr<ObjectModel::Generic> typeGeneric(new ObjectModel::Generic(_fileName));
            typeGeneric->Type = std::move(*sym);
            *sym = std::move(typeGeneric);
        }
        return;
    }
    return;
}

// Returns false if it fails to extract valid data from the CA signature, true otherwise.
bool MetaDataConvert::GetValueFromCustomAttributeSig(CustomAttributeParser& CA,
                                                     ULONG elemType,
                                                     ObjectModel::CustomAttributeParamInfo& parameter) {
    UINT8 u1 = 0;
    UINT16 u2 = 0;
    UINT32 u4 = 0;
    UINT64 u8 = 0;
    unsigned __int64 uI64;
    bool boolVal;
    double dblVal;

    bool ret = true;

    switch (elemType) {
        case ELEMENT_TYPE_I1:
        case ELEMENT_TYPE_U1:
            CA.GetU1(&u1);
            parameter.Type = std::make_shared<ObjectModel::BasicType>(IntrinsicTypeMap[elemType],
                                                                      _fileName,
                                                                      ObjectModel::TypeCategory::WinRtFundamental);
            parameter.SignedIntValue = u1;
            parameter.ElementType = elemType;
            break;
        case ELEMENT_TYPE_I2:
        case ELEMENT_TYPE_U2:
            CA.GetU2(&u2);
            parameter.Type = std::make_shared<ObjectModel::BasicType>(IntrinsicTypeMap[elemType],
                                                                      _fileName,
                                                                      ObjectModel::TypeCategory::WinRtFundamental);
            parameter.SignedIntValue = u2;
            parameter.ElementType = elemType;
            break;
        case ELEMENT_TYPE_BOOLEAN:
            CA.GetBool(&boolVal);
            parameter.Type = std::make_shared<ObjectModel::BasicType>(IntrinsicTypeMap[elemType],
                                                                      _fileName,
                                                                      ObjectModel::TypeCategory::WinRtFundamental);
            parameter.SignedIntValue = boolVal;
            parameter.ElementType = elemType;
            break;
        case ELEMENT_TYPE_I4:
        case ELEMENT_TYPE_U4:
            CA.GetU4(&u4);
            parameter.Type = std::make_shared<ObjectModel::BasicType>(IntrinsicTypeMap[elemType],
                                                                      _fileName,
                                                                      ObjectModel::TypeCategory::WinRtFundamental);
            parameter.SignedIntValue = u4;
            parameter.ElementType = elemType;
            break;
        case SERIALIZATION_TYPE_ENUM:
            CA.GetU4(&u4);
            parameter.Type = std::make_shared<ObjectModel::BasicType>(L"", _fileName, ObjectModel::TypeCategory::UnresolvedType);
            parameter.SignedIntValue = u4;
            parameter.ElementType = elemType;
            break;
        case SERIALIZATION_TYPE_TYPE: {
            wstring strVal = CA.GetWString();
            mdToken token = mdTokenNil;
            shared_ptr<ObjectModel::Symbol> tempParam;
            if (Scope()->FindTypeDefByName(strVal.c_str(), mdTokenNil, &token) && !IsNilToken(token)) {
                NameFromToken(token, false, &tempParam);
            } else {
                tempParam.reset(new ObjectModel::BasicType(strVal, _fileName));
            }
            parameter.Type = std::make_shared<ObjectModel::BasicType>(L"System.Type", _fileName, ObjectModel::TypeCategory::UnresolvedType);
            parameter.StringValue = std::move(tempParam->Name);
            parameter.ElementType = elemType;
        } break;
        case ELEMENT_TYPE_STRING: {
            wstring strVal = CA.GetWString();
            parameter.Type = std::make_shared<ObjectModel::BasicType>(IntrinsicTypeMap[elemType],
                                                                      _fileName,
                                                                      ObjectModel::TypeCategory::WinRtFundamental);
            parameter.StringValue = std::move(strVal);
            parameter.ElementType = elemType;
        } break;
        case ELEMENT_TYPE_I8:
        case ELEMENT_TYPE_U8:
            CA.GetU8(&u8);
            uI64 = u8;
            parameter.SignedIntValue = uI64;
            parameter.Type = std::make_shared<ObjectModel::BasicType>(IntrinsicTypeMap[elemType],
                                                                      _fileName,
                                                                      ObjectModel::TypeCategory::WinRtFundamental);
            parameter.ElementType = elemType;
            break;
        case ELEMENT_TYPE_R4:
            dblVal = CA.GetR4();
            parameter.DoubleValue = dblVal;
            parameter.Type = std::make_shared<ObjectModel::BasicType>(IntrinsicTypeMap[elemType],
                                                                      _fileName,
                                                                      ObjectModel::TypeCategory::WinRtFundamental);
            parameter.ElementType = elemType;
            break;
        case ELEMENT_TYPE_R8:
            dblVal = CA.GetR8();
            parameter.DoubleValue = dblVal;
            parameter.Type = std::make_shared<ObjectModel::BasicType>(IntrinsicTypeMap[elemType],
                                                                      _fileName,
                                                                      ObjectModel::TypeCategory::WinRtFundamental);
            parameter.ElementType = elemType;
            break;
        default:
            ret = false;
            break;
    }
    return ret;
}

typedef LPCSTR LPCUTF8;
bool MetaDataConvert::GetCustomAttributeInformation(mdCustomAttribute token, shared_ptr<ObjectModel::Attribute> attribute) {
    const BYTE* pValue; // The custom value.
    ULONG cbValue; // Length of the custom value.
    mdToken tkObj; // Attributed object.
    mdToken tkType; // Type of the custom attribute.
    mdToken tk; // For name lookup.
    LPCUTF8 pMethName = 0; // Name of custom attribute ctor, if any.
    PCCOR_SIGNATURE pSig = 0; // Signature of ctor.
    ULONG cbSig; // Size of the signature.
    WCHAR rcName[MAX_CLASS_NAME]; // Name of the type.

    Scope()->GetCustomAttributeProps( // S_OK or error.
        token, // The attribute.
        &tkObj, // The attributed object
        &tkType, // The attributes type.
        (const void**)&pValue, // Put pointer to data here.
        &cbValue); // Put size here.

    // Get the name of the memberref or methoddef.
    tk = tkType;
    rcName[0] = L'\0';
    // Get the member name, and the parent token.
    switch (TypeFromToken(tk)) {
        case mdtMemberRef:
            Scope()->GetNameFromToken(tk, &pMethName);
            Scope()->GetMemberRefProps(tk, &tk, 0, 0, 0, &pSig, &cbSig);
            break;
        case mdtMethodDef:
            Scope()->GetNameFromToken(tk, &pMethName);
            Scope()->GetMethodProps(tk, &tk, 0, 0, 0, 0, &pSig, &cbSig, 0, 0);
            break;
    } // switch

    // Get the type name.
    switch (TypeFromToken(tk)) {
        case mdtTypeDef:
            Scope()->GetTypeDefProps(tk, rcName, MAX_CLASS_NAME, 0, 0, 0);
            break;
        case mdtTypeRef:
            Scope()->GetTypeRefProps(tk, 0, rcName, MAX_CLASS_NAME, 0);
            break;
    } // switch

    attribute->Name = rcName;

    if (pSig) { // Interpret the signature.
        //<TODO> all sig elements </TODO>
        PCCOR_SIGNATURE ps = pSig;
        ULONG cb;
        ULONG ulData;
        ULONG cParams;
        CustomAttributeParser CA(pValue, cbValue);
        CA.ValidateProlog();

        // Get the calling convention.
        cb = CorSigUncompressData(ps, &ulData);
        ps += cb;
        // Get the count of params.
        cb = CorSigUncompressData(ps, &cParams);
        ps += cb;
        // Get the return value.
        cb = CorSigUncompressData(ps, &ulData);
        ps += cb;
        if (ulData == ELEMENT_TYPE_VOID) {
            try {
                // For each fixed param...
                for (ULONG i = 0; i < cParams; ++i) { // Get the next param type.
                    cb = CorSigUncompressData(ps, &ulData);
                    ps += cb;
                    wchar_t enumName[MaxTypeNameLen];
                    ULONG chName = 0;
                    if (ulData == ELEMENT_TYPE_VALUETYPE) {
                        // The only value type that we accept are enums. Decompress the TypeDefOrRefOrSpecEncoded from
                        // the sig.
                        mdToken typeToken;
                        cb = CorSigUncompressToken(ps, &typeToken);
                        memset(enumName, 0, MaxTypeNameLen * sizeof(wchar_t));

                        // retrieve the name of the enum
                        if (TypeFromToken(typeToken) == mdtTypeRef) {
                            _scope->GetTypeRefProps(typeToken, nullptr, enumName, MaxTypeNameLen, &chName);
                        } else {
                            _scope->GetTypeDefProps(typeToken, enumName, MaxTypeNameLen, &chName, nullptr, nullptr);
                        }

                        ps += cb;
                        ulData = SERIALIZATION_TYPE_ENUM;
                    } else if (ulData == ELEMENT_TYPE_CLASS) {
                        // The only class type that we accept is System.Type. Decompress the TypeDefOrRefOrSpecEncoded
                        // from the sig.
                        // Possible TODO: verify that the decompressed token corresponds to the System.Type typeref.
                        mdToken typeToken;
                        cb = CorSigUncompressToken(ps, &typeToken);
                        ps += cb;
                        ulData = SERIALIZATION_TYPE_TYPE;
                    }

                    ObjectModel::CustomAttributeParamInfo parameter;
                    parameter.Type = std::make_shared<ObjectModel::BasicType>(L"", _fileName, ObjectModel::TypeCategory::UnresolvedType);
                    if (GetValueFromCustomAttributeSig(CA, ulData, parameter)) {
                        if (chName > 0) {
                            parameter.Type->Name = enumName;
                        }
                        attribute->FixedParameters.push_back(std::move(parameter));
                    } else {
                        // Failed to get the value. Invalidate the attribute.
                        attribute->Category = ObjectModel::TypeCategory::InvalidType;
                    }
                }

                // Now that we've parsed out all of the fixed arguments, we parse the named arguments.
                UINT16 numNamed;
                CA.GetU2(&numNamed);
                for (ULONG i = 0; i < numNamed; i++) {
                    // This must be 0x53, indicating a field. ECMA 335 also allows it to be 0x54 to indicate a property, but there
                    // are no legal scenarios for this in winmd files. (ECMA 335 Partition II 23.3)
                    UINT8 fieldMarker;
                    CA.GetU1(&fieldMarker);
                    if (fieldMarker == 0x53) {
                        UINT8 fieldType;
                        CA.GetU1(&fieldType);

                        ObjectModel::CustomAttributeParamInfo parameter;
                        parameter.Type =
                            std::make_shared<ObjectModel::BasicType>(L"", _fileName, ObjectModel::TypeCategory::UnresolvedType);
                        wstring enumName = L"";
                        // An Enum parameter has the name of the Enum as part of the field type.
                        if (fieldType == SERIALIZATION_TYPE_ENUM) {
                            enumName = CA.GetWString();
                        }

                        wstring fieldName = CA.GetWString();
                        if (GetValueFromCustomAttributeSig(CA, fieldType, parameter)) {
                            if (!enumName.empty()) {
                                parameter.Type->Name = std::move(enumName);
                            }

                            if (attribute->NamedParameters.count(fieldName) == 0) {
                                attribute->NamedParameters.insert(std::move(std::make_pair(fieldName, parameter)));
                            } else {
                                // Multiple parameters with the same name. Invalidate the attribute.
                                attribute->Category = ObjectModel::TypeCategory::InvalidType;
                            }
                        } else {
                            // Failed to get the value. Invalidate the attribute.
                            attribute->Category = ObjectModel::TypeCategory::InvalidType;
                        }
                    } else {
                        // Malformed blob. Invalidate the attribute.
                        attribute->Category = ObjectModel::TypeCategory::InvalidType;
                    }
                }

                // After parsing the fixed and named parameters, we should have consumed the entire custom attribute blob. Confirm.
                if (CA.BytesLeft() != 0) {
                    // Malformed blob. Invalidate the attribute.
                    attribute->Category = ObjectModel::TypeCategory::InvalidType;
                }
            } catch (HRESULT) {
                // Caught error. Invalidate the attribute.
                attribute->Category = ObjectModel::TypeCategory::InvalidType;
            }
        }
    }
    return true;
}

MultiFileObjectModel::MultiFileObjectModel(vector<wstring> filenames) {
    for (auto file = filenames.begin(); file != filenames.end(); ++file) {
        _perFileModels[*file] = shared_ptr<MetaDataConvert>(new MetaDataConvert(*file, _fqnMap));
    }

    for (auto pfModel = _perFileModels.begin(); pfModel != _perFileModels.end(); ++pfModel) {
        pfModel->second->ConvertMetaData();
    }
}

void MultiFileObjectModel::VisitNamespaces(ObjectModel::Visitor* visitor) {
    for (auto pfModel = _perFileModels.begin(); pfModel != _perFileModels.end(); ++pfModel) {
        pfModel->second->VisitNamespaces(visitor);
    }
}
