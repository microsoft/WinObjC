//******************************************************************************
//
// Copyright (c) Microsoft Corporation. All rights reserved.
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

#include "stdafx.h"
#include <sstream>
#include <string>

extern "C" const std::string g_commonConvertors;
extern ClangObjectModel::GlobalData g_globalData;
extern "C" const std::string g_winrtClassPrefix;
extern std::string generateABIBoundaryStart();
extern std::string generateABIBoundaryEnd();

using namespace std;

namespace ContainerTemplates {

static const std::string objCInterfacePrefix = "RTProxied";
static const std::string objCHeterogeneousWrapperPrefix = "RTProxiedHeterogeneous";
static const std::string objCHeterogeneousWrapperSuffix = "Base";
static const std::string rtClassPrefix = "ObjCProxied";
static const std::string keyEnumeratorSuffix = "KeyEnumerator";
static const std::string objCMarshallingHelperPrefix = "_ObjCMarshallingHelperFor";
static const std::string rtMarshallingHelperPrefix = "_RTMarshallingHelperFor";
// Maps the WinRT (IDL) type to the pair <Getter method for IPropertyValue, PropertyType>
// ToDo: Add DateTimeArray support.
map<string, pair<string, string>> PropertyValueConvertor =
    { { "boolean", { "GetBoolean", "PropertyType_Boolean" } },
      { "BYTE", { "GetUInt8", "PropertyType_UInt8" } },
      { "WCHAR", { "GetChar16", "PropertyType_Char16" } },
      { "UINT8", { "GetUInt8", "PropertyType_UInt8" } },
      { "UINT16", { "GetChar16", "PropertyType_UInt16" } },
      { "UINT32", { "GetUInt32", "PropertyType_UInt32" } },
      { "UINT64", { "GetUInt64", "PropertyType_UInt64" } },
      { "INT16", { "GetChar16", "PropertyType_Int16" } },
      { "INT32", { "GetInt32", "PropertyType_Int32" } },
      { "INT64", { "GetInt64", "PropertyType_Int64" } },
      { "FLOAT", { "GetSingle", "PropertyType_Single" } },
      { "DOUBLE", { "GetDouble", "PropertyType_Double" } },
      { "HSTRING", { "GetString", "PropertyType_String" } },

      { "IVectorView<BYTE>", { "GetUInt8Array", "PropertyType_UInt8Array" } },
      { "IVectorView<INT16>", { "GetChar16Array", "PropertyType_Int16Array" } },
      { "IVectorView<UINT16>", { "GetChar16Array", "PropertyType_UInt16Array" } },
      { "IVectorView<INT32>", { "GetInt32Array", "PropertyType_Int32Array" } },
      { "IVectorView<UINT32>", { "GetUInt32Array", "PropertyType_UInt32Array" } },
      { "IVectorView<INT64>", { "GetInt64Array", "PropertyType_Int64Array" } },
      { "IVectorView<UINT16>", { "GetUInt32Array", "PropertyType_UInt64Array" } },
      { "IVectorView<FLOAT>", { "GetSingleArray", "PropertyType_SingleArray" } },
      { "IVectorView<DOUBLE>", { "GetDoubleArray", "PropertyType_DoubleArray" } },
      { "IVectorView<UINT16>", { "GetChar16Array", "PropertyType_Char16Array" } },
      { "IVectorView<boolean>", { "GetBooleanArray", "PropertyType_BooleanArray" } },
      { "IVectorView<HSTRING>", { "GetStringArray", "PropertyType_StringArray" } },
      { "IVectorView<IInspectable*>", { "GetInspectableArray", "PropertyType_InspectableArray" } } };

map<string, string> NSNumberToPropertyValue =
    { { "bool", "CreateBoolean" },          { "BOOL", "CreateBoolean" },        { "char", "CreateUInt8" },
      { "wchar_t", "CreateUInt16" },        { "unsigned char", "CreateUInt8" }, { "short", "CreateInt16" },
      { "unsigned short", "CreateUInt16" }, { "int", "CreateInt32" },           { "unsigned int", "CreateUInt32" },
      { "float", "CreateSingle" },          { "double", "CreateDouble" },       { "NSInteger", "CreateInt32" },
      { "NSUInteger", "CreateUInt32" },     { "long", "CreateInt32" },          { "unsigned long", "CreateUInt32" },
      { "long long", "CreateInt64" },       { "INT16", "CreateInt16" },         { "INT32", "CreateInt32" },
      { "INT64", "CreateInt64" },           { "UINT16", "CreateUInt16" },       { "UINT32", "CreateUInt32" },
      { "UINT64", "CreateUInt64" } };

std::string generateObjCWrapperDeclaration(std::shared_ptr<ClangObjectModel::ComponentInfo> comp) {
    stringstream ss, ssPrefix;

    for (auto containerMap : comp->heterogeneousContainers) {
        auto info = containerMap.second;

        if (info->objCContainerName == "NSDictionary") {
            // We need to generate the key enumerator as well.
            ss << "@interface " << objCInterfacePrefix << info->name << keyEnumeratorSuffix << " : NSEnumerator {" << endl;
            ss << "ComPtr<IInspectable> comObj;" << endl;
            ss << "ComPtr<IIterator<IKeyValuePair<IInspectable*, IInspectable*>*>> iterator;" << endl;
            ss << "ComPtr<IIterable<IKeyValuePair<IInspectable*, IInspectable*>*>> iterable;" << endl;
            ss << "}" << endl;
            ss << "- (ComPtr<IInspectable>)getInternalComObj;" << endl;
            ss << "- (instancetype)initWithComObj:(ComPtr<IInspectable>)com;" << endl;
            ss << "- (id)nextObject;" << endl;
            ss << "@end" << endl;
            ss << endl;
        }

        // The ObjC wrapper.
        ss << "@interface " << objCInterfacePrefix << info->name << " : " << info->objCContainerName << " {" << endl;
        ss << "    ComPtr<IInspectable> comObj;" << endl;
        ss << "}" << endl;
        ss << ContainerTemplates::_generateObjCWrapperMethodDeclarations(info) << endl;
        ss << "@end" << endl << endl;
    }

    return ssPrefix.str() + ss.str();
}

std::string _generateObjCWrapperMethodDeclarations(std::shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info) {
    stringstream ss;
    ss << "- (ComPtr<IInspectable>)getInternalComObj;" << endl;
    ss << "- (instancetype)initWithComObj:(ComPtr<IInspectable>)com;" << endl;
    if (info->objCContainerName == "NSArray") {
        ss << _generateObjCWrapperMethodDeclarationsForNSArray(info);
    } else if (info->objCContainerName == "NSDictionary") {
        ss << _generateObjCWrapperMethodDeclarationsForNSDictionary(info);
    }

    return ss.str();
}

std::string _generateObjCWrapperMethodDeclarationsForNSArray(std::shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info) {
    stringstream ss;
    ss << "- (unsigned int)count;" << endl;
    ss << "- (id)objectAtIndex:(unsigned int)idx;" << endl;
    return ss.str();
}

std::string _generateObjCWrapperMethodDeclarationsForNSDictionary(std::shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info) {
    stringstream ss;
    ss << "- (id)objectForKey:(id)obj;" << endl;
    ss << "- (id)keyEnumerator;" << endl;
    ss << "- (unsigned int)count;" << endl;
    return ss.str();
}

std::string generateRTWrapperDeclaration(std::shared_ptr<ClangObjectModel::ComponentInfo> comp) {
    stringstream ss;
    stringstream ssInterfaceDecl;

    std::string namespaceName = ClangHelpers::generateNamespaceString(g_globalData.currentComponent->getSDKName(), "{\nnamespace ");
    ss << "namespace " << namespaceName << " {" << std::endl;

    for (auto containerMap : comp->heterogeneousContainers) {
        auto info = containerMap.second;
        std::string rtClassName = rtClassPrefix + info->name;

        // The RT creator method.
        ss << "ComPtr<IInspectable> " << info->toWRLConvertor << "(id obj);" << endl << endl;

        // The ObjC creator method.
        ss << "id " << info->toObjCConvertor << "(ComPtr<IInspectable> rtObj);" << endl << endl;

        ssInterfaceDecl << "class " + rtClassName + " : public RuntimeClass<" << info->wrlContainerName << "<" << info->wrlTemplateParams
                        << ">>, public GetInnerObject {" << endl;
        ssInterfaceDecl << "    InspectableClass(L\"" + rtClassName + "\", BaseTrust)" << endl;
        ssInterfaceDecl << "protected:" << endl;
        ssInterfaceDecl << "StrongId<id> _proxiedObj;" << endl << endl;
        ssInterfaceDecl << "public:" << endl;
        ssInterfaceDecl << ContainerTemplates::_generateRTWrapperMethodDeclarations(info) << endl;
        ssInterfaceDecl << "};" << endl << endl;
    }

    ss << ssInterfaceDecl.str();

    ss << "}" << endl;
    // Add as many closing bracket as there are opening brackets in namespaceName
    int count = std::count(namespaceName.begin(), namespaceName.end(), '{');
    for (int i = 0; i < count; i++) {
        ss << "}" << std::endl;
    }
    return ss.str();
}
std::string _generateRTWrapperMethodDeclarations(std::shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info) {
    stringstream ss;
    ss << "    explicit " << rtClassPrefix << info->name << "(id obj);" << endl;
    ss << "    ~" << rtClassPrefix << info->name << "();" << endl;
    ss << "    id getInnerObject() override;" << endl << endl;
    if (info->objCContainerName == "NSArray") {
        ss << _generateRTWrapperMethodDeclarationForNSArray(info);
    } else if (info->objCContainerName == "NSDictionary") {
        ss << _generateRTWrapperMethodDeclarationForNSDictionary(info);
    }

    return ss.str();
}

std::string _generateRTWrapperMethodDeclarationForNSArray(std::shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info) {
    stringstream ss;
    ss << "    virtual HRESULT STDMETHODCALLTYPE get_Size(unsigned int* size) override;" << endl;
    ss << "    virtual HRESULT STDMETHODCALLTYPE GetAt(unsigned int index, IInspectable** item) override;" << endl;
    ss << "    virtual HRESULT STDMETHODCALLTYPE IndexOf(IInspectable* value, unsigned int* index, boolean* found) override;" << endl;
    ss << "    virtual HRESULT STDMETHODCALLTYPE GetMany(unsigned int startIndex, unsigned int capacity, IInspectable** values, "
          "unsigned int* actual) override;"
       << endl;

    return ss.str();
}

std::string _generateRTWrapperMethodDeclarationForNSDictionary(std::shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info) {
    stringstream ss;
    ss << "    virtual HRESULT STDMETHODCALLTYPE get_Size(unsigned int* size) override;" << endl;
    ss << "    virtual HRESULT STDMETHODCALLTYPE Lookup(IInspectable* key, IInspectable** value) override;" << endl;
    ss << "    virtual HRESULT STDMETHODCALLTYPE HasKey(IInspectable* key, boolean* found) override;" << endl;
    ss << "    virtual HRESULT STDMETHODCALLTYPE Split(IMapView<IInspectable*, IInspectable*>** firstPartition, "
       << "IMapView<IInspectable*, IInspectable*>** secondPartition) override;" << endl;

    return ss.str();
}

std::string generateHeterogeneousCreators(std::shared_ptr<ClangObjectModel::ComponentInfo> comp) {
    stringstream ss;
    for (auto containerMap : comp->heterogeneousContainers) {
        auto info = containerMap.second;
        ss << _generateHeterogeneousCreatorForObjC(info);
        ss << _generateHeterogeneousCreatorForRT(info);
    }

    return ss.str();
}

std::string _generateHeterogeneousCreatorForObjC(std::shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info) {
    stringstream ss;

    ss << "id " << info->toObjCConvertor << "(ComPtr<IInspectable> rtObj) {" << endl;
    ss << "    id __returnObj;" << endl;
    ss << "    Microsoft::WRL::Wrappers::HString runtimeClassName;" << endl;
    ss << "    THROW_NS_IF_FAILED(rtObj->GetRuntimeClassName(runtimeClassName.GetAddressOf()));" << endl;
    ss << "    UINT32 length;" << endl;
    ss << "    const wchar_t* str = WindowsGetStringRawBuffer(runtimeClassName.Get(), &length);" << endl;
    ss << "    if (wcscmp(str, L\"" << rtClassPrefix << info->name << "\") == 0) {" << endl;

    std::string resolvedType =
        ClangHelpers::generateResolvedTypeName(rtClassPrefix + info->name, g_globalData.currentComponent->getSDKName(), false, "");

    ss << "        " << resolvedType << "* cls = static_cast<" << resolvedType << "*>(rtObj.Get());" << endl;
    ss << "        __returnObj = cls->getInnerObject();" << endl;
    ss << "    } else {" << endl;
    ss << "        __returnObj = [[[" << objCInterfacePrefix << info->name << " alloc] initWithComObj:rtObj] autorelease];" << endl;
    ss << "    }" << endl;
    ss << "    return __returnObj;" << endl;
    ss << "}" << endl;

    return ss.str();
}

std::string _generateHeterogeneousCreatorForRT(std::shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info) {
    stringstream ss;
    ss << "ComPtr<IInspectable> " << info->toWRLConvertor << "(id obj) {" << endl;
    ss << "    if ([obj respondsToSelector:@selector(getInternalComObj)]) {" << endl;
    ss << "        return [obj getInternalComObj];" << endl;
    ss << "    }" << endl;
    ss << endl;

    std::string resolvedType =
        ClangHelpers::generateResolvedTypeName(rtClassPrefix + info->name, g_globalData.currentComponent->getSDKName(), false, "");

    ss << "    return Make<" << resolvedType << ">(obj);" << endl;
    ss << "}" << endl;

    return ss.str();
}

std::string generateObjCWrapperDefinition(std::shared_ptr<ClangObjectModel::ComponentInfo> comp) {
    stringstream ss;
    bool dictionaryBaseRequired = false;
    bool arrayBaseRequired = false;
    for (auto containerMap : comp->heterogeneousContainers) {
        auto info = containerMap.second;

        if (info->objCContainerName == "NSDictionary") {
            // generate implementation for key enumerator.
            ss << "@implementation " << objCInterfacePrefix << info->name << keyEnumeratorSuffix << endl;
            ss << _generateObjCWrapperMethodDefinitionsForNSDictionaryKeyEnumerator(info);
            ss << "@end" << endl;
            ss << endl;
        }

        ss << "@implementation " << objCInterfacePrefix << info->name << endl;
        ss << _generateObjCWrapperMethodDefinitions(info);
        ss << "@end" << endl << endl;
    }

    return ss.str();
}

string _generateObjCWrapperMethodDefinitionsForNSDictionaryKeyEnumerator(shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info) {
    stringstream ss;
    ss << "-(ComPtr<IInspectable>)getInternalComObj {" << endl;
    ss << "    return self->comObj;" << endl;
    ss << "}" << endl;
    ss << endl;
    ss << "-(instancetype)initWithComObj:(ComPtr<IInspectable>)com {" << endl;
    ss << "    if (self = [super init]) {" << endl;
    ss << "        self->comObj = com;" << endl;
    ss << "        ComPtr<IMapView<IInspectable*, IInspectable*>> mv;" << endl;
    ss << "        THROW_NS_IF_FAILED(com.As(&mv));" << endl;
    ss << "        if (SUCCEEDED(mv.As(&iterable))) {" << endl;
    ss << "            iterable->First(&iterator);" << endl;
    ss << "        }" << endl;
    ss << "    }" << endl;
    ss << "    return self;" << endl;
    ss << "}" << endl;
    ss << endl;
    string inspectableObject = "keyRaw";
    ss << "-(id)nextObject {" << endl;
    ss << "    boolean hasCurrent;" << endl;
    ss << "    if (iterable == nullptr) {" << endl;
    ss << "        return nil;" << endl;
    ss << "    }" << endl;
    ss << "    iterator->get_HasCurrent(&hasCurrent);" << endl;
    ss << "    if (!hasCurrent) {" << endl;
    ss << "        return nil;" << endl;
    ss << "    }" << endl;
    ss << "    ComPtr<IKeyValuePair<IInspectable*, IInspectable*>> curPair;" << endl;
    ss << "    iterator->get_Current(&curPair);" << endl;
    ss << "    IInspectable* " << inspectableObject << ";" << endl;
    ss << "    curPair->get_Key(&" << inspectableObject << ");" << endl;
    ss << "    iterator->MoveNext(&hasCurrent);" << endl;
    // convert keyRaw to objc and return it.
    string objCMarshallingHelperName = objCMarshallingHelperPrefix + rtClassPrefix + info->name;
    objCMarshallingHelperName =
        ClangHelpers::generateResolvedTypeName(objCMarshallingHelperName, g_globalData.currentComponent->getSDKName(), false, "");
    ss << "    return " << objCMarshallingHelperName << "(" << inspectableObject << ");" << endl;
    ss << "}" << endl;
    return ss.str();
}

std::string _generateObjCWrapperMethodDefinitions(std::shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info) {
    stringstream ss;
    ss << "- (ComPtr<IInspectable>)getInternalComObj {" << endl;
    ss << "    return self->comObj;" << endl;
    ss << "}" << endl << endl;

    ss << "- (instancetype)initWithComObj:(ComPtr<IInspectable>)com {" << endl;
    ss << "    if (self = [super init]) {" << endl;
    ss << "        self->comObj = com;" << endl;
    ss << "    }" << endl;
    ss << "    return self;" << endl;
    ss << "}" << endl << endl;

    if (info->objCContainerName == "NSArray") {
        ss << _generateObjCWrapperMethodDefinitionsForNSArray(info);
    } else if (info->objCContainerName == "NSDictionary") {
        ss << _generateObjCWrapperMethodDefinitionsForNSDictionary(info);
    }
    return ss.str();
}

std::string generateObjCMarshallingMethods(std::shared_ptr<ClangObjectModel::ComponentInfo> comp) {
    stringstream ss;
    for (auto containerMap : comp->heterogeneousContainers) {
        auto info = containerMap.second;
        string inspectableObject = "inspectableObject";
        string methodName = objCMarshallingHelperPrefix + rtClassPrefix + info->name;
        ss << "id " << methodName << "(ComPtr<IInspectable> " << inspectableObject << ") {" << endl;
        int numericPrefix = 1;
        string objectName = inspectableObject + ::to_string(numericPrefix++);

        // First take care of native types.
        set<std::shared_ptr<ClangObjectModel::TypeInfo>, ClangObjectModel::TypeInfo> types;
        types.insert(info->typesInfo.begin(), info->typesInfo.end());
        types.insert(info->valueTypesInfo.begin(), info->valueTypesInfo.end());
        ss << _generateObjCMarshallingForPropertyValueTypes(types, inspectableObject, objectName);
        for (auto typeInfo : types) {
            if (typeInfo->isNativeType()) {
                // NSArray of native types.
                // Already taken care of above.
                continue;
            }

            objectName = inspectableObject + ::to_string(numericPrefix++);
            if (typeInfo->isInterface()) {
                // NSArray of interfaces.
                ss << _generateObjCMarshallingForInterfaceTypes(typeInfo, inspectableObject, objectName);
            } else if (typeInfo->isContainer()) {
                ss << _generateObjCMarshallingForContainerTypes(typeInfo, inspectableObject, objectName);
            } else if (typeInfo->isEnumType()) {
                Helpers::Errors::WriteError(nullptr, "Unsupported type in heterogeneous containers", false);
            }
        }
        ss << "    return nil;" << endl;
        ss << "}" << endl;
        ss << endl;
    }
    return ss.str();
}

string _generateObjCMarshallingForPropertyValueTypes(std::set<shared_ptr<ClangObjectModel::TypeInfo>, ClangObjectModel::TypeInfo> types,
                                                     string inspectableObject,
                                                     string objectName) {
    stringstream ssPrefix, ssBody, ss;
    ssPrefix << "    ComPtr<IPropertyValue> " << objectName << ";" << endl;
    ssPrefix << "    if (SUCCEEDED(" << inspectableObject << ".As(&" << objectName << "))) {" << endl;
    ssPrefix << "        PropertyType type;" << endl;
    ssPrefix << "        if (FAILED(" << objectName << "->get_Type(&type))) {" << endl;
    ssPrefix << "            return nil;" << endl;
    ssPrefix << "        }" << endl;
    ssPrefix << endl;
    ssPrefix << "        switch(type) {" << endl;

    for (auto typeInfo : types) {
        // How the types are mapped in PropertyValue:
        // IVectorView<IInspectable> => Heterogeneous array.
        // IVectorView<BasicTypes> => Array of basic type.
        string wrlName = TypeConvertor::WinrtType(typeInfo, true);
        auto it = PropertyValueConvertor.find(Helpers::baseType(wrlName, true));
        if (it == PropertyValueConvertor.end()) {
            continue;
        }

        string getterMethod = it->second.first;
        string propertyType = it->second.second;
        ssBody << "            case " << propertyType << ": {" << endl;
        if (typeInfo->getTypeSpelling() == "NSArray") {
            // This is an array of homegeneous types.
            ssBody << "                id _returnObj = " << TypeConvertor::GetObjCTypeCreatorName(typeInfo) << "(" << objectName
                   << ".Get());" << endl;
        } else if (typeInfo->isHeterogeneous) {
            // This is an array of heterogeneous types.
            string convertor = TypeConvertor::GetObjCTypeCreatorName(typeInfo) + "(" + objectName + ".Get())";
            convertor = ClangHelpers::generateResolvedTypeName(convertor, g_globalData.currentComponent->getSDKName(), false, "");
            ssBody << "                id _returnObj = " << convertor << ";" << endl;
        } else {
            ssBody << "                " << wrlName << " value;" << endl;
            ssBody << "                THROW_NS_IF_FAILED(" << objectName << "->" << getterMethod << "(&value));" << endl;
            ssBody << "                id _returnObj = ToObjcConvertor<" << typeInfo->getTypeSpelling() << ", " << wrlName
                   << ", dummyObjCCreator>::convert(value);" << endl;
        }
        // Release memory for HSTRING.
        if (wrlName == "HSTRING") {
            ssBody << "                WindowsDeleteString(value);" << endl;
        }

        ssBody << "                return _returnObj;" << endl;
        ssBody << "            }" << endl;

        // Char in C# is 16 bits, but a char from ObjC will map to a byte.
        // Handle this special case here.
        if (wrlName == "BYTE") {
            ssBody << "            case PropertyType_Char16: {" << endl;
            ssBody << "                WCHAR value;" << endl;
            ssBody << "                THROW_NS_IF_FAILED(" << objectName << "->GetChar16(&value));" << endl;
            ssBody << "                return ToObjcConvertor<wchar_t, WCHAR, dummyObjCCreator>::convert(value);" << endl;
            ssBody << "            }" << endl;
        }
    }

    if (ssBody.rdbuf()->in_avail() != 0) {
        ssBody << "            default:" << endl;
        ssBody << "                return nil;" << endl;
        ssBody << "        }" << endl << "    }" << endl;
        ss << ssPrefix.str() << ssBody.str() << endl;
    }

    return ss.str();
}

std::string _generateObjCMarshallingForInterfaceTypes(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo,
                                                      string inspectableObject,
                                                      std::string objectName) {
    stringstream ss;
    auto ifaceInfo = g_globalData.interfaceMap.find(Helpers::Trim(Helpers::baseType(typeInfo->getTypeSpelling())));
    std::string resolvedType =
        ClangHelpers::generateResolvedTypeName("I" + TypeConvertor::WinrtType(typeInfo, true), ifaceInfo->second->getSDKName(), false);

    ss << "    ComPtr<" << resolvedType << "> " << objectName << ";" << endl;
    ss << "    if (SUCCEEDED(" << inspectableObject << ".As(&" << objectName << "))) {" << endl;
    ss << "        return " << TypeConvertor::GetObjCTypeCreatorName(typeInfo) << "(" << objectName << ".Get());" << endl;
    ss << "    }" << endl;
    return ss.str();
}

std::string _generateObjCMarshallingForContainerTypes(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo,
                                                      string inspectableObject,
                                                      std::string objectName) {
    stringstream ss;

    ss << "    ComPtr<" << Helpers::baseType(TypeConvertor::WinrtType(typeInfo, true), true) << "> " << objectName << ";" << endl;
    ss << "    if (SUCCEEDED(" << inspectableObject << ".As(&" << objectName << "))) {" << endl;
    std::string convertorName = ClangHelpers::generateResolvedTypeName(TypeConvertor::GetObjCTypeCreatorName(typeInfo),
                                                                       g_globalData.currentComponent->getSDKName(),
                                                                       false,
                                                                       "");
    ss << "        return " << convertorName << "(" << objectName << ".Get());" << endl;
    ss << "    }" << endl;
    return ss.str();
}

std::string _generateObjCWrapperMethodDefinitionsForNSArray(std::shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info) {
    stringstream ss;
    ss << "- (unsigned int)count {" << endl;
    ss << "    ComPtr<IVectorView<IInspectable*>> array;" << endl;
    ss << "    unsigned int res = 0;" << endl;
    ss << "    if (SUCCEEDED(self->comObj.As(&array))) {" << endl;
    ss << "        THROW_NS_IF_FAILED(array->get_Size(&res));" << endl;
    ss << "    } else {" << endl;
    ss << "        ComPtr<IPropertyValue> propValueArr;" << endl;
    ss << "        THROW_NS_IF_FAILED(self->comObj.As(&propValueArr));" << endl;
    ss << "        void* ptr;" << endl;
    ss << "        getPropertyValueArrayInfo(propValueArr, res, &ptr);" << endl;
    ss << "        CoTaskMemFree(ptr);" << endl;
    ss << "    }" << endl;
    ss << "    return res;" << endl;
    ss << "}" << endl << endl;

    string inspectableObject = "obj";
    ss << "- (id)objectAtIndex:(unsigned int)index {" << endl;
    ss << "    ComPtr<IVectorView<IInspectable*>> array;" << endl;
    ss << "    ComPtr<IInspectable> " << inspectableObject << ";" << endl;
    ss << "    if (SUCCEEDED(self->comObj.As(&array))) {" << endl;
    ss << "        THROW_NS_IF_FAILED(array->GetAt(index, " << inspectableObject << ".GetAddressOf()));" << endl;
    ss << "    } else {" << endl;
    ss << "        ComPtr<IPropertyValue> propValueArr;" << endl;
    ss << "        THROW_NS_IF_FAILED(self->comObj.As(&propValueArr));" << endl;
    ss << "        void* ptr;" << endl;
    ss << "        unsigned int res;" << endl;
    ss << "        getPropertyValueArrayInfo(propValueArr, res, &ptr);" << endl;
    ss << "        if (index >= res) {" << endl;
    ss << "            THROW_NS_HR(E_BOUNDS);" << endl;
    ss << "        }" << endl;
    ss << "        " << inspectableObject << " = ((IInspectable**)ptr)[index];" << endl;
    ss << "        CoTaskMemFree(ptr);" << endl;
    ss << "    }" << endl;

    // Generate objC marshalling code for each type.
    string objCMarshallingHelperName = objCMarshallingHelperPrefix + rtClassPrefix + info->name;
    objCMarshallingHelperName =
        ClangHelpers::generateResolvedTypeName(objCMarshallingHelperName, g_globalData.currentComponent->getSDKName(), false, "");
    ss << "    return " << objCMarshallingHelperName << "(" << inspectableObject << ");" << endl;
    ss << "}" << endl << endl;
    return ss.str();
}

std::string _generateObjCWrapperMethodDefinitionsForNSDictionary(std::shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info) {
    stringstream ss;
    ss << "- (unsigned int)count {" << endl;
    ss << "    ComPtr<IMapView<IInspectable*, IInspectable*>> dictionary;" << endl;
    ss << "    THROW_NS_IF_FAILED(self->comObj.As(&dictionary));" << endl;
    ss << "    unsigned int res = 0;" << endl;
    ss << "    THROW_NS_IF_FAILED(dictionary->get_Size(&res));" << endl;
    ss << "    return res;" << endl;
    ss << "}" << endl << endl;

    string objectName = "key";
    string rtObjectName = "item";
    ss << "- (id)objectForKey:(id)" << objectName << " {" << endl;
    ss << "    ComPtr<IMapView<IInspectable*, IInspectable*>> dictionary;" << endl;
    ss << "    THROW_NS_IF_FAILED(self->comObj.As(&dictionary));" << endl;
    ss << "    ComPtr<IInspectable> _comObj;" << endl;
    ss << "    ComPtr<ABI::Windows::Foundation::IPropertyValueStatics> inst;" << endl;
    ss << "    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference"
          "(L\"Windows.Foundation.PropertyValue\").Get(), &inst));"
       << endl;
    // Convert key to WinRT type.
    // First check if key is of native types.
    string rtMarshallingHelperName = rtMarshallingHelperPrefix + rtClassPrefix + info->name;
    rtMarshallingHelperName =
        ClangHelpers::generateResolvedTypeName(rtMarshallingHelperName, g_globalData.currentComponent->getSDKName(), false, "");
    ss << "    _comObj = " << rtMarshallingHelperName << "(" << objectName << ");" << endl;
    ss << "    if (_comObj == nullptr) {" << endl;
    ss << "        // Failed to find a suitable conversion for key" << endl;
    ss << "        return nil;" << endl;
    ss << "    }" << endl;

    // Now call lookup on dictionary.
    string inspectableObject = "val";
    ss << "    ComPtr<IInspectable> " << inspectableObject << ";" << endl;
    ss << "    THROW_NS_IF_FAILED(dictionary->Lookup(_comObj.Get(), " << inspectableObject << ".GetAddressOf()));" << endl;

    // Now convert val to ObjC
    string objCMarshallingHelperName = objCMarshallingHelperPrefix + rtClassPrefix + info->name;
    objCMarshallingHelperName =
        ClangHelpers::generateResolvedTypeName(objCMarshallingHelperName, g_globalData.currentComponent->getSDKName(), false, "");
    ss << "    return " << objCMarshallingHelperName << "(" << inspectableObject << ");" << endl;
    ss << "}" << endl;
    ss << endl;
    ss << "- (id)keyEnumerator {" << endl;
    string keyEnumeratorName = objCInterfacePrefix + info->name + keyEnumeratorSuffix;
    ss << "    return [[[" << keyEnumeratorName << " alloc] initWithComObj:self->comObj] autorelease];" << endl;
    ss << "}" << endl;
    return ss.str();
}

std::string generateRTWrapperDefinitions(std::shared_ptr<ClangObjectModel::ComponentInfo> comp) {
    stringstream ss;
    for (auto containerMap : comp->heterogeneousContainers) {
        auto info = containerMap.second;
        ss << _generateRTWrapperMethodDefinitions(info);
    }

    return ss.str();
}

std::string _generateRTWrapperMethodDefinitions(std::shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info) {
    stringstream ss;

    // Constructor
    ss << rtClassPrefix << info->name << "::" << rtClassPrefix << info->name << "(id obj) {" << endl;
    ss << "    _proxiedObj = obj;" << endl;
    ss << "}" << endl;

    ss << endl;

    // Destructor
    ss << rtClassPrefix << info->name << "::~" << rtClassPrefix << info->name << "() {" << endl;
    ss << "    _proxiedObj = nil;" << endl;
    ss << "}" << endl;

    ss << endl;

    // Getter for proxied inner object.
    ss << "id " << rtClassPrefix << info->name << "::getInnerObject() {" << endl;
    ss << "    return _proxiedObj.get();" << endl;
    ss << "}" << endl;

    ss << endl;

    if (info->objCContainerName == "NSArray") {
        ss << _generateRTWrapperMethodDefinitionsForNSArray(info);
    } else if (info->objCContainerName == "NSDictionary") {
        ss << _generateRTWrapperMethodDefinitionsForNSDictionary(info);
    }

    return ss.str();
}

string generateRTMarshallingMethods(std::shared_ptr<ClangObjectModel::ComponentInfo> comp) {
    stringstream ss;
    for (auto containerMap : comp->heterogeneousContainers) {
        auto info = containerMap.second;
        const string objectName = "obj";
        ss << "ComPtr<IInspectable> " << rtMarshallingHelperPrefix << rtClassPrefix << info->name << "(id " << objectName << ") {" << endl;
        ss << "    if ([" << objectName << " respondsToSelector:@selector(getInternalComObj)]) {" << endl;
        ss << "        return [" << objectName << " getInternalComObj];" << endl;
        ss << "    }" << endl;
        ss << "    ComPtr<ABI::Windows::Foundation::IPropertyValueStatics> inst;" << endl;
        ss << "    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference"
              "(L\"Windows.Foundation.PropertyValue\").Get(), &inst));"
           << endl;
        set<shared_ptr<ClangObjectModel::TypeInfo>, ClangObjectModel::TypeInfo> types;
        types.insert(info->typesInfo.begin(), info->typesInfo.end());
        types.insert(info->valueTypesInfo.begin(), info->valueTypesInfo.end());
        ss << _generateRTMarshallingForPropertyValueTypes(types, objectName);
        for (auto typeInfo : types) {
            auto it = NSNumberToPropertyValue.find(typeInfo->getTypeSpelling());
            if (it != NSNumberToPropertyValue.end()) {
                continue;
            }

            if (typeInfo->isInterface()) {
                // NSArray of interfaces.
                ss << _generateRTMarshallingForInterfaceTypes(typeInfo, objectName);
            } else if (typeInfo->isContainer()) {
                ss << _generateRTMarshallingForContainerTypes(typeInfo, objectName);
            } else if (typeInfo->isEnumType()) {
                Helpers::Errors::WriteError(nullptr, "Unsupported type in heterogeneous containers", false);
            }
        }
        ss << "    return nullptr;" << endl;
        ss << "}" << endl;
        ss << endl;
    }
    return ss.str();
}

string _generateRTMarshallingForPropertyValueTypes(set<shared_ptr<ClangObjectModel::TypeInfo>, ClangObjectModel::TypeInfo> types,
                                                   string objectName) {
    stringstream ss;

    bool hasNSNumber = false;
    bool hasNSString = false;
    for (auto typeInfo : types) {
        if (Helpers::Trim(Helpers::baseType(typeInfo->getTypeSpelling())) == "NSString") {
            hasNSString = true;
        }

        auto it = NSNumberToPropertyValue.find(typeInfo->getTypeSpelling());
        if (it == NSNumberToPropertyValue.end()) {
            continue;
        }

        hasNSNumber = true;
    }

    if (hasNSNumber) {
        ss << "    if ([" << objectName << " isKindOfClass:[NSNumber class]]) {" << endl;
        ss << "        return " << g_commonConvertors << "::convertNSNumberToPropertyValue(" << objectName << ");" << endl;
        ss << "    }" << endl;
    }

    if (hasNSString) {
        ss << "    if ([" << objectName << " isKindOfClass:[NSString class]]) {" << endl;
        ss << "        return " << g_commonConvertors << "::convertNSStringToPropertyValue(" << objectName << ");" << endl;
        ss << "    }" << endl;
        ss << endl;
    }

    return ss.str();
}

string _generateRTMarshallingForInterfaceTypes(shared_ptr<ClangObjectModel::TypeInfo> typeInfo, string objectName) {
    stringstream ss;
    string ifaceName = Helpers::Trim(Helpers::baseType(typeInfo->getTypeSpelling()));
    auto iface = g_globalData.interfaceMap.find(ifaceName);
    if (iface == g_globalData.interfaceMap.end()) {
        Helpers::Errors::WriteError(nullptr, "Invalid interface type found", false);
    }

    ss << "    if ([" << objectName << " isKindOfClass:[" << Helpers::Trim(Helpers::baseType(typeInfo->getTypeSpelling())) << " class]]) {"
       << endl;
    ss << "        return " << TypeConvertor::GetWRLTypeCreatorName(typeInfo) << "(" << objectName << ");" << endl;
    ss << "    }" << endl;
    ss << endl;
    return ss.str();
}

string _generateRTMarshallingForContainerTypes(shared_ptr<ClangObjectModel::TypeInfo> typeInfo, string objectName) {
    stringstream ss;

    string objCInterfaceName;
    if (typeInfo->isHeterogeneous) {
        auto it = g_globalData.currentComponent->heterogeneousContainers.find(typeInfo->getTypeSpelling(true));
        objCInterfaceName = it->second->objCContainerName;
    } else {
        objCInterfaceName = typeInfo->getTypeSpelling(true);
    }

    ss << "    if ([" << objectName << " isKindOfClass:[" << objCInterfaceName << " class]]) {" << endl;
    ss << "        return " << TypeConvertor::GetWRLTypeCreatorName(typeInfo) << "(" << objectName << ");" << endl;
    ss << "    }" << endl;
    ss << endl;
    return ss.str();
}

std::string _generateRTWrapperMethodDefinitionsForNSDictionary(std::shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info) {
    stringstream ss;
    string rtClassName = rtClassPrefix + info->name;
    string objCMarshallingHelperName = objCMarshallingHelperPrefix + rtClassPrefix + info->name;
    objCMarshallingHelperName =
        ClangHelpers::generateResolvedTypeName(objCMarshallingHelperName, g_globalData.currentComponent->getSDKName(), false, "");

    string rtMarshallingHelperName = rtMarshallingHelperPrefix + rtClassPrefix + info->name;
    rtMarshallingHelperName =
        ClangHelpers::generateResolvedTypeName(rtMarshallingHelperName, g_globalData.currentComponent->getSDKName(), false, "");

    // get_Size
    ss << "STDMETHODIMP " << rtClassName << "::get_Size(unsigned int* size) {" << endl;
    ss << generateABIBoundaryStart();
    ss << "    *size = [_proxiedObj count];" << endl;
    ss << "    return S_OK;" << endl;
    ss << generateABIBoundaryEnd();
    ss << "}" << endl;
    ss << endl;

    // Lookup
    string inspectableObject = "key";
    ss << "STDMETHODIMP " << rtClassName << "::Lookup(IInspectable*" << inspectableObject << ", IInspectable** value) {" << endl;
    ss << "    return ExceptionBoundary([&]() {" << endl;
    // Convert key to objc
    ss << "        id objCKey = " << objCMarshallingHelperName << "(" << inspectableObject << ");" << endl;
    ss << "        id objCVal = [_proxiedObj objectForKey:objCKey];" << endl;
    // Convert objCVal to RT
    ss << "        *value = " << rtMarshallingHelperName << "(objCVal).Detach();" << endl;
    ss << "        return S_OK;" << endl;
    ss << "    });" << endl;
    ss << "}" << endl;
    ss << endl;

    // HasKey
    ss << "STDMETHODIMP " << rtClassName << "::HasKey(IInspectable* key, boolean* found) {" << endl;
    ss << "    return ExceptionBoundary([&]() {" << endl;
    // Convert key to objc
    ss << "        id objCKey = " << objCMarshallingHelperName << "(" << inspectableObject << ");" << endl;
    ss << "        id objCVal = [_proxiedObj objectForKey:objCKey];" << endl;
    ss << "        *found = (objCVal != nil);" << endl;
    ss << "        return S_OK;" << endl;
    ss << "    });" << endl;
    ss << "}" << endl;
    ss << endl;

    // Split
    ss << "STDMETHODIMP " << rtClassName << "::Split(IMapView<IInspectable*, IInspectable*>** firstPartition," << endl;
    ss << "    IMapView<IInspectable*, IInspectable*>** secondPartition) {" << endl;
    ss << "    return ExceptionBoundary([&]() {" << endl;
    ss << "        return E_NOTIMPL;" << endl;
    ss << "    });" << endl;
    ss << "}" << endl;
    ss << endl;
    return ss.str();
}

std::string _generateRTWrapperMethodDefinitionsForNSArray(std::shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info) {
    stringstream ss;

    // get_Size
    ss << "STDMETHODIMP " << rtClassPrefix << info->name << "::get_Size(unsigned int* size) {" << endl;
    ss << generateABIBoundaryStart();
    ss << "    *size = [_proxiedObj count];" << endl;
    ss << "    return S_OK;";
    ss << generateABIBoundaryEnd();
    ss << "}" << endl;

    ss << endl;

    // GetAt
    string rtObjectName = "item";
    ss << "STDMETHODIMP " << rtClassPrefix << info->name << "::GetAt(unsigned int index, IInspectable** " << rtObjectName << ") {" << endl;
    ss << generateABIBoundaryStart();
    ss << "    if (_proxiedObj == nil) {" << endl;
    ss << "        return E_FAIL;" << endl;
    ss << "    }" << endl;
    ss << endl;
    string objectName = "obj";
    ss << "    id " << objectName << " = [_proxiedObj objectAtIndex:index];" << endl;
    // Generate marshalling code for each type.
    // First take care of native types.
    string rtMarshallingHelperName = rtMarshallingHelperPrefix + rtClassPrefix + info->name;
    rtMarshallingHelperName =
        ClangHelpers::generateResolvedTypeName(rtMarshallingHelperName, g_globalData.currentComponent->getSDKName(), false, "");
    ss << "    *" << rtObjectName << " = " << rtMarshallingHelperName << "(" << objectName << ").Detach();" << endl;
    ss << "    return S_OK;" << endl;
    ss << generateABIBoundaryEnd();
    ss << "}" << endl;

    ss << endl;

    // IndexOf
    ss << "STDMETHODIMP " << rtClassPrefix << info->name << "::IndexOf(IInspectable* value, unsigned int* index, boolean* found) {" << endl;
    ss << generateABIBoundaryStart();
    ss << "    if (_proxiedObj == nil) {" << endl;
    ss << "        *found = false;" << endl;
    ss << "        return S_OK;" << endl;
    ss << "    }" << endl;
    ss << endl;
    ss << "    NSUInteger idx = NSNotFound;" << endl;
    string inspectableObject = "_comObj";
    ss << "    ComPtr<IInspectable> " << inspectableObject << " = value;" << endl;
    // First convert inspectableObject to ObjC.
    objectName = "obj";
    string objCMarshallingHelperName = objCMarshallingHelperPrefix + rtClassPrefix + info->name;
    objCMarshallingHelperName =
        ClangHelpers::generateResolvedTypeName(objCMarshallingHelperName, g_globalData.currentComponent->getSDKName(), false, "");
    ss << "    id " << objectName << " = " << objCMarshallingHelperName << "(" << inspectableObject << ");" << endl;
    // Now call into the proxied object with this ObjC object.
    ss << "    idx = [_proxiedObj indexOfObject:" << objectName << "];" << endl;
    ss << "    if (idx == NSNotFound) {" << endl;
    ss << "        *found = false;" << endl;
    ss << "    } else {" << endl;
    ss << "        *found = true;" << endl;
    ss << "        *index = idx;" << endl;
    ss << "    }" << endl;
    ss << endl;
    ss << "    return S_OK;" << endl;
    ss << generateABIBoundaryEnd();
    ss << "}" << endl << endl;

    // GetMany
    ss << "STDMETHODIMP " << rtClassPrefix << info->name << "::GetMany(unsigned int startIndex,\n"
                                                            "    unsigned int capacity,\n"
                                                            "    IInspectable** values,\n"
                                                            "    unsigned int* actual) {"
       << endl;
    ss << generateABIBoundaryStart();
    ss << "    unsigned int count = [_proxiedObj count];" << endl;
    ss << "    if (startIndex >= count) {" << endl;
    ss << "        *actual = 0;" << endl;
    ss << "        return S_OK;" << endl;
    ss << "    }" << endl;
    ss << endl;
    ss << "    unsigned int end = capacity < (count - startIndex) ? capacity : (count - startIndex);" << endl;
    ss << "    for (unsigned int i = 0; i < end; i++) {" << endl;
    ss << "        RETURN_IF_FAILED(GetAt(startIndex+i, &values[i]));" << endl;
    ss << "    }" << endl;
    ss << endl;
    ss << "    *actual = end;" << endl;
    ss << "    return S_OK;" << endl;
    ss << generateABIBoundaryEnd();
    ss << "}" << endl;
    return ss.str();
}
}