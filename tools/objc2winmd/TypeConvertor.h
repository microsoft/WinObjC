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

#pragma once

#include <map>
#include <string>

namespace TypeConvertor {
class ToObjCTypeConvertor {
    ToObjCTypeConvertor(const ToObjCTypeConvertor&) = delete;
    ToObjCTypeConvertor& operator=(const ToObjCTypeConvertor&) = delete;

protected:
    ToObjCTypeConvertor() {
    }

public:
    virtual ~ToObjCTypeConvertor(){};

    virtual std::string instantiator(const std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo);
    static ToObjCTypeConvertor* getInstance() {
        static ToObjCTypeConvertor _obj;
        return &_obj;
    }
};

class _ArrayToNSArrayConvertor : public ToObjCTypeConvertor {
public:
    virtual std::string instantiator(const std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo) override;
    static _ArrayToNSArrayConvertor* getInstance() {
        static _ArrayToNSArrayConvertor _obj;
        return &_obj;
    }
};

class _IterableToNSSetConvertor : public _ArrayToNSArrayConvertor {
public:
    static _IterableToNSSetConvertor* getInstance() {
        static _IterableToNSSetConvertor _obj;
        return &_obj;
    }

    // TBD: Support for NSSet as input.
    // This requires enumerator support added to our proxy in RTHelpers.h.
    // Fortunately, FBSDK/Login does not take this type as input.
    // Using this convertor will generate code that compiles, but if ObjC land calls for enumerator
    // we will crash on method not found.
};

class _MapViewToNSDictionaryConvertor : public ToObjCTypeConvertor {
public:
    virtual std::string instantiator(const std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo) override;
    static _MapViewToNSDictionaryConvertor* getInstance() {
        static _MapViewToNSDictionaryConvertor _obj;
        return &_obj;
    }
};

struct ContainerTypeInfo {
    std::string ObjCName;
    std::string WRLName;
    std::string toWRLConvertor;
    TypeConvertor::ToObjCTypeConvertor* toObjCConvertor;
    std::string adapterObjBase;
    std::string adapterObj;
    std::string objCProxyName;
    std::string implClassName;
};

void SetContainerTypeInfo(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo, const std::string& metadata);
std::string WinRTContainerType(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo, bool baseType = false, bool forIDL = false);
std::string WinRTTemplateParams(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo, bool forIDL = false);
const TypeConvertor::ContainerTypeInfo* GetContainerInfo(const std::string& objcType);
std::string GetWRLTypeCreatorName(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo);
std::string GetObjCTypeCreatorName(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo);

// Returns the resolved Windows Runtime name for ObjC types.
// Arguments:
// typeInfo: The typeInfo which has the ObjC type information and for which a WRL name is requested.
// interfaceType: If set the typeInfo is assumed to be of type ObjC interface and the corresponding WinRT interface name will returned.
// baseType: If set this removes any pointer notations, e.g. NSArray<NSString*>* -> IVectorView<HSTRING>
// This method is used mainly to convert template arguments.
std::string GetWRLTypeNameForContainerTemplates(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo,
                                                bool interfaceType = true,
                                                bool baseType = true);

// Returns the ObjC type name for Windows runtime type.
// Arguments:
// typeInfo: The typeInfo which has the WinRT type information and for which ObjC name is requested.
// pureObjCName: Used for containers or types for which we may have proxies in ObjC. e.g. NSArray proxy is called RTProxiedNSArrayFull.
//               If pureObjCName is set then we return the actual ObjC type, else we return the proxy name.
std::string GetObjCTypeName(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo, bool pureObjCName = false);

// Internal method.
// Returns the ObjC type creator function name.
// Aguments:
// typeInfo: The typeInfo for container for which we need to generate the creator functions.
// pureObjCName: Used for containers or types for which we may have proxies in ObjC. e.g. NSArray proxy is called RTProxiedNSArrayFull.
//               If pureObjCName is set then we return the actual ObjC type, else we return the proxy name.
std::string _GetObjCTypeCreatorName(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo, bool pureObjCName = false);

std::string GeneratePolymorphicName(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo);
std::string WinrtType(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo, bool baseType = false, bool forIDL = false);

// Returns the container name for ABI
// e.g. IVectorView, IVector etc.without any template parameters.
// To get a complete type name with template parameters use GetWRLTypeNameForContainerTemplates.
std::string GetContainerTypeNameForABI(const std::string& objcType);

std::string WinRTNativeType(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo);
std::string WinRTTemplateType(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo, bool forIDL = false);
void SetTemplateTypeInfo(std::vector<std::shared_ptr<ClangObjectModel::TypeInfo>>& templateParams, const std::string& metadata);
std::string getWRLConvertorFuncForType(const std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo, const std::string& callString);

// If generic syntax is found then firstIdx and lastIdx will contain location at which '<' and '>' were found
// in typespelling respective. If the location is not required pass null for these parameters.
bool isGeneric(const std::string& typeSpelling, size_t* firstIdx = nullptr, size_t* lastIdx = nullptr);

std::string GetProtocolFromId(const std::string& objcType);

// This maps fundamental types from ObjC(++) into the equivalent IDL type (used also in the code bindings):
const std::map<std::string, std::string> NativeTypeMap = {
    { "bool", "boolean" },          { "BOOL", "boolean" },       { "char", "BYTE" },
    { "wchar_t", "WCHAR" },         { "unsigned char", "BYTE" }, { "short", "INT16" },
    { "unsigned short", "UINT16" }, { "int", "INT32" },          { "unsigned int", "UINT32" },
    { "float", "FLOAT" },           { "double", "DOUBLE" },      { "NSInteger", "INT32" },
    { "NSUInteger", "UINT32" },     { "long", "INT32" },         { "unsigned long", "UINT32" },
    { "long long", "INT64" },       { "void", "void" },          { "NSString", "HSTRING" },
    { "INT16", "INT16" },           { "INT32", "INT32" },        { "INT64", "INT64" },
    { "UINT16", "UINT16" },         { "UINT32", "UINT32" },      { "UINT64", "UINT64" },
}; // nativeTypeMap

const std::map<std::string, ContainerTypeInfo> ContainerTypeMap = { { "NSSet",
                                                                      { "NSSet",
                                                                        "IIterable",
                                                                        "ConvertToIterable",
                                                                        _IterableToNSSetConvertor::getInstance(),
                                                                        "IterableArrayAdapter",
                                                                        "IterableArrayAdapterObj",
                                                                        "RTProxiedIterableNSArrayFull",
                                                                        "RTIterableObj" } },

                                                                    { "NSArray",
                                                                      { "NSArray",
                                                                        "IVectorView",
                                                                        "ConvertToVectorView",
                                                                        _ArrayToNSArrayConvertor::getInstance(),
                                                                        "ArrayAdapter",
                                                                        "ArrayAdapterObj",
                                                                        "RTProxiedNSArrayFull",
                                                                        "RTArrayObj" } },

                                                                    { "NSMutableArray",
                                                                      { "NSMutableArray",
                                                                        "IVector",
                                                                        "ConvertToVector",
                                                                        _ArrayToNSArrayConvertor::getInstance(),
                                                                        "MutableArrayAdapter",
                                                                        "MutableArrayAdapterObj",
                                                                        "RTProxiedNSMutableArrayFull",
                                                                        "RTMutableArrayObj" } },

                                                                    { "NSDictionary",
                                                                      { "NSDictionary",
                                                                        "IMapView",
                                                                        "ConvertToMapView",
                                                                        _MapViewToNSDictionaryConvertor::getInstance(),
                                                                        "DictionaryAdapter",
                                                                        "DictionaryAdapterObj",
                                                                        "RTProxiedNSDictionary",
                                                                        "RTMapViewObj" } },

                                                                    { "NSMutableDictionary",
                                                                      { "NSMutableDictionary",
                                                                        "IMap",
                                                                        "ConvertToMap",
                                                                        _MapViewToNSDictionaryConvertor::getInstance(),
                                                                        "MutableDictionaryAdapter",
                                                                        "MutableDictionaryAdapterObj",
                                                                        "RTProxiedNSMutableDictionary",
                                                                        "RTMapObj" } } }; // ContainerTypeMap

} // namespace TypeConvertor
