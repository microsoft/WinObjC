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

#include <unordered_map>
#include <unordered_set>
#include <map>
#include <memory>
#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <clang-c\Index.h>

namespace ClangObjectModel {
// Forward declarations.
struct ComponentInfo;
struct AsyncClassInfo;
class MetaDataComments;
struct ProtocolInfo;
struct ApplicationDelegateInfo;
struct HeterogeneousContainerInfo;

enum SymbolKind { Unknown, NativeType, ContainerType, IntefaceType, EnumType, JSONType };

const std::string MetaDataType_IgnoreDecl = "ignoredecl";
const std::string MetaDataType_ReturnType = "returntype";
const std::string MetaDataType_Parameter = "parameter#";
const std::string MetaDataType_BlockParameter = "blockparameter#";
const std::string MetaDataType_Property = "propertyis";
const std::string MetaDataType_Async = "asyncmethod";
const std::string MetaDataType_ApplicationDelegate = "applicationdelegate";
const std::string MetaDataType_DelegateCallbackProtocol = "delegatecallbackprotocol";
const std::string MetaDataType_DelegateAllocator = "delegateallocator";
const std::string MetaDataType_DelegateInitializer = "delegateinitializer";
const std::string MetaDataType_DelegateAllocatorAndInitializer = "delegateallocatorandinitializer";
const std::string MetaDataType_GeneratesNotification = "generatesnotification";
const std::string MetaDataType_PossibleTypes = "possibletypes";
const char possibleTypesStartSymbol = '[';
const char possibleTypesEndSymbol = ']';
const char possibleTypesSeparator = '|';

struct Symbol {
    std::string SDKname;
    std::string SDKHeaderFile;
    virtual std::string getSDKName();
};

struct TypeInfo : public Symbol, public std::enable_shared_from_this<TypeInfo> {
private:
    std::string _typeSpelling;
    enum IDType { Invalid, IsAProtocol, NotAProtocol };
    std::string _name;
    IDType _idType = Invalid;

public:
    CXTypeKind typeKind;
    std::string annotation;
    std::string wrlName;

    CXCursor cursor;
    std::shared_ptr<ClangHelpers::SourceLocationInfo> sourceLocation;
    bool isHeterogeneous = false;
    ClangObjectModel::SymbolKind cachedSymbolKind = ClangObjectModel::SymbolKind::Unknown;

    // template params for generics
    std::vector<std::shared_ptr<TypeInfo>> templateParams;

    // map for enum constants, mapping the enum constant name to its value
    std::map<std::string, int> enumConstants;

    // Methods.
    // Some types such as ObjC containers, JSON, NSError are marshalled as WinRT containers.
    // These have no pure base type representation and are always marshalled as a single pointer by default.
    // Therefore, for these we request baseType so that an additional pointer indirection is not added by TypeConvertor::WinRTType method.
    bool hasBaseWinRTRepresentation();

    bool isContainer();
    bool isInterface();
    bool isProtocol();
    bool isNativeType();
    bool isComType();
    bool isVoidType(bool base = false);
    bool isEnumType();
    bool isNSDateType();
    bool isNSURLType();

    SymbolKind getSymbolKind();
    bool isIdWithProtocolConformance();
    std::string getSDKName() override;
    void setTypeSpelling(const std::string& spelling);
    std::string getTypeSpelling(bool baseType = false);
    std::string getTypeSpellingLowerCase(bool baseType = false);
    void setTypeName(const std::string& nameString);
    std::string getTypeName();
    void ResolveReturnType(const std::string& metadata);
    void ResolveParameterType(const std::string& metadata);
    static std::shared_ptr<ClangObjectModel::TypeInfo> CloneTypeInfo(const std::shared_ptr<ClangObjectModel::TypeInfo>& info);

    std::unordered_map<std::string, std::shared_ptr<ClangObjectModel::TypeInfo>> objCCreatorFunc;
    // Cache an unique ObjC Creator function with the given methodName.
    // If removeMethod parameter is provided it is removed from the objcCreatorFunc map.
    void updateObjCCreatorFunctionName(std::string methodName,
                                       const std::shared_ptr<ClangObjectModel::TypeInfo>& typeInfo,
                                       std::string removeMethod = "");

    std::string generateObjcLocalVarName() {
        return "__" + getTypeSpelling(true);
    }
    std::string generateMemberVarName() {
        return "_" + getTypeSpelling(true);
    }

    // if the syntax is for a container (e.g. NSArray<NSString *>*), this function will set the type spelling of this object
    // to be NSArray, and add child TypeInfo nodes (templateParams) for the types it contains.
    // if the syntax is for protocol conformance (e.g. id<MyProtocol>), this function will set the type spelling to be the protocol.
    void handleGenericTypes();

    //  Comparator used when inserting this type in a std::set.
    bool operator()(const std::shared_ptr<TypeInfo>& t1, const std::shared_ptr<TypeInfo>& t2);

private:
    void _resolveType(const std::string& metadata);
    void _updateSymbolReferencesForComponent(bool isProtocol);
};

struct ParameterInfo : public Symbol {
    std::shared_ptr<TypeInfo> typeInfo;
    CXCursor cursor;
    // TBD: return type of delegates is difficult to extract from AST.
    // But delegates as parameters rarely have return types.
    std::vector<std::shared_ptr<TypeInfo>> delegateParams;
    bool marshallDelegateAsAsync;
    std::shared_ptr<AsyncClassInfo> asyncInfo;
    std::shared_ptr<ClangObjectModel::MetaDataComments> paramMetaData;

    std::string getSDKName() override;

    ParameterInfo();

    static std::shared_ptr<ClangObjectModel::ParameterInfo> CloneParameterInfo(
        const std::shared_ptr<ClangObjectModel::ParameterInfo>& info);
};

struct MethodInfo : public Symbol {
    std::string name;
    std::string displayName;
    std::string objectiveCSelector;
    std::string objectiveCSignature;
    std::shared_ptr<ParameterInfo> returnType;
    std::vector<std::shared_ptr<ParameterInfo>> params;

    bool isAsync = false;
    std::string methodNameForIDL;
    std::string idlAnnotation;
    std::string methodNameForRuntimeClass;
    bool isUnavailable = false;
    bool isSynthesizedProperty = false;

    // this is set when the API is generated in response to the type of 'id' type.
    bool isPolymorphic = false;

    // Overloaded in C++ sense i.e. arguments are different (return type may or may not be different).
    bool isOverloaded = false;

    // The IDL attribute "overload" requires a method name, this method name needs to be different for methods
    // which vary only in their return type. We use this parameter to add a suffix to the method name when the
    // return type changes, such that we get a different name for the method for the different return types while
    // argument types remaining the same.
    // e.g. Foo([in] int a, [in] int b, [out] [retval] int** c);
    //      Foo([in] int a, [in] float b, [out] [retval] float** c);
    // we get (blank spaces are added to make it easier to read):
    // [default_overload][overload("Foo")] Foo([in] int a, [in] int b, [out] [retval] int** b);
    // [overload("Foo")]                   Foo1([in] int a, [in] float b, [out] [retval] int** b);
    // [default_overload][overload("Foo1")]Foo2([in] int a, [in] int b, [out] [retval] float** b);
    // [overload("Foo1")]                  Foo3([in] int a, [in] float b, [out] [retval] float** b);
    int returnTypePolymorphId = 0;

    // If there are n overloaded methods with method name "Foo", the first amongst these (or at least one amongst these)
    // needs to be marked with IDL attribute "[default_overload]".
    // This variable is used to keep track of the first method amongst methods with the same overloaded method name.
    // The first one among them is marked with "[default_overload]" attribute.
    bool needsDefaultOverload = false;

    static std::shared_ptr<ClangObjectModel::MethodInfo> CloneMethodInfo(const std::shared_ptr<MethodInfo>& info);

    /* Updates the generated method name for IDL and the runtime class to the passed in name.
    */
    void UpdateMethodNameForIDLAndRuntimeClass(const std::string& newRuntimeName);

    /* Updates the generated method name for IDL and the runtime class to the passed in idl and runtime class name respectively.
    */
    void UpdateMethodNameForIDLAndRuntimeClass(const std::string& nameForIDL, const std::string& nameForRuntimeClass);

    std::string getMethodNameForIdl() {
        std::string nameForIDL = this->methodNameForIDL.empty() ? this->name : this->methodNameForIDL;
        nameForIDL[0] = ::toupper(nameForIDL[0]);
        return nameForIDL;
    }

    std::string getMethodNameForRuntimeClass() {
        std::string nameForRuntimeClass = this->methodNameForRuntimeClass.empty() ? this->name : this->methodNameForRuntimeClass;
        const std::string get = "get_";
        const std::string put = "put_";
        if (nameForRuntimeClass.compare(0, get.length(), get) == 0) {
            nameForRuntimeClass[get.length()] = toupper(nameForRuntimeClass[get.length()]);
        } else if (nameForRuntimeClass.compare(0, put.length(), put) == 0) {
            nameForRuntimeClass[put.length()] = toupper(nameForRuntimeClass[put.length()]);
        } else {
            nameForRuntimeClass[0] = toupper(nameForRuntimeClass[0]);
        }
        return nameForRuntimeClass;
    }
};

struct PropertyInfo : public Symbol {
private:
    std::string _name;

public:
    std::shared_ptr<ClangObjectModel::MethodInfo> getter;
    std::shared_ptr<ClangObjectModel::MethodInfo> setter;
    std::shared_ptr<ClangObjectModel::MetaDataComments> metadata;
    PropertyInfo(const std::string& propertyName,
                 const std::string& getterName,
                 const std::string& setterName,
                 std::shared_ptr<ClangObjectModel::MetaDataComments> metaData);
    void setPropertyName(const std::string& nameString);
    std::string getPropertyName();
};

struct DelegateInfo {
    std::string name;
    std::shared_ptr<TypeInfo> returnType;
    std::vector<std::shared_ptr<TypeInfo>> params;
};

struct AsyncClassInfo {
    std::string name;
    std::string implName;
    std::string sdkName;
    std::vector<std::shared_ptr<TypeInfo>> returnTypes;
    std::shared_ptr<InterfaceInfo> synthesizedInterface;
    bool operator()(const std::shared_ptr<ClangObjectModel::AsyncClassInfo>& info1,
                    const std::shared_ptr<ClangObjectModel::AsyncClassInfo>& info2) const;

    static std::shared_ptr<ClangObjectModel::AsyncClassInfo> CloneAsyncClassInfo(
        const std::shared_ptr<ClangObjectModel::AsyncClassInfo>& info);
};

struct InterfaceInfo : public Symbol {
    std::string name;
    std::vector<std::shared_ptr<MethodInfo>> instanceMethods;
    std::vector<std::shared_ptr<MethodInfo>> parameterizedInitMethods;
    std::vector<std::shared_ptr<MethodInfo>> classMethods;
    std::vector<std::shared_ptr<PropertyInfo>> properties;

    void AddProtocolsImplemented(const std::string& protocolName);
    std::vector<std::shared_ptr<ProtocolInfo>> getProtocolsImplemented();

    bool hasDefaultInitializer = true;
    bool isApplicationDelegate = false;

    // We only need a static factory and there is no need for an ActivatableClassFactory.
    // This can happen when we have class methods but no constructors.
    // We may or may not have instance methods.
    inline bool isActivatableStaticOnlyFactory() {
        return !hasDefaultInitializer && (parameterizedInitMethods.size() == 0) && (classMethods.size() > 0);
    }

    void SetSuperClassFromCursor(CXCursor cursor);

    // We only support subclassing from a select few UI framework classes (e.g. UIButton) defined in objCSuperClasses.
    // When an Obj-C interface derives from a UI element, we translate the Obj-c Interface into a
    // Winrt runtimeclass that derives from Windows::UI::Xaml::Controls::ContentControl.
    // returns true if the base class for this interface derives from one of the supported UI framework classes (e.g. UIButton).
    // returns false otherwise
    bool DerivesFromUIElement();

    // The framework base class (e.g. UIButton) this interface derives from.
    // returns nullptr if the base class is not a framework base class.
    std::shared_ptr<InterfaceInfo> GetUIElementBaseClass();

    // Returns the base class for the interface.
    // reports an error is the base class is unknown.
    std::shared_ptr<InterfaceInfo> GetBaseClass();

    // Thd idl runtime class name if different than the interface name for interfaces that derive from UIElements (e.g. UIButton)
    std::string GetIdlRuntimeClassName();
    std::string GetIdlFileName();
    std::string GetWinrtClassName();

    InterfaceInfo() {
    }

    InterfaceInfo(const std::string& name) : name(name) {
    }

    InterfaceInfo(const std::string& name,
                  const std::string& winrtName,
                  const std::string& idlRuntimeClassName,
                  const std::string& idlFileName)
        : name(name), _winrtName(winrtName), _idlRuntimeClassName(idlRuntimeClassName), _idlFileName(idlFileName) {
    }

    std::unordered_map<std::string, std::shared_ptr<ClangObjectModel::TypeInfo>> usedDelegateTypes;

private:
    std::string _winrtName;
    std::string _idlRuntimeClassName;
    std::string _idlFileName;
    std::string _superClass;
    std::shared_ptr<ClangHelpers::SourceLocationInfo> _superClassSourceLocation;
    std::vector<std::string> _protocolsImplemented;
};

struct ProtocolInfo : public Symbol {
    std::string name;
    std::string implHeaderName;
    std::vector<std::shared_ptr<MethodInfo>> instanceMethods;
    std::vector<std::shared_ptr<MethodInfo>> classMethods;
    std::vector<std::shared_ptr<PropertyInfo>> properties;

    ProtocolInfo(const std::string& name) : name(name) {
    }
};

// The kind describes whether it is metadata for return type or for parameters.
// We have the tag ReturnType for return type description and Parameter#n for parameters.
// The n is the number of the parameter.
const int Len_MetaDataKind = 10;

// This gives the offset at which the block parameters start.
// Block parameter carry the tag: BlockParameter#n where n is the number of the parameter.
const int Offset_StartBlockParam = 12;

// Offset at which the block parameter number is specified, for which the metadata is provided.
const int Offset_BlockParamNumber = 15;

class MetaDataComments {
private:
    struct MetaData {
        std::string metaDataType; // ReturnType or Parameter#,             or PropertyIs, or IgnoreDecl or BlockParameter or AsyncMethod
        int parameterNumber; //    -1,     or Parameter number,       or    -1,      or   -1
        int blockParamNumber; //    -1,     or Block parameter number, or    -1,      or   -1

        // CXCursor_Spelling.
        // In case of heterogeneous types this will create a pair mapping the generated type name to the contained types.
        // e.g. PossibleTypes:NSArray<int>:NSArray<float>, will generate the vector:
        // types[0] = NSArray, {int, float}.
        // and PossibleTypes:NSArray<int>:NSSet<float>, will generate the vector:
        // typesSpelling[0] = NSArray<int>, {},
        // typesSpelling[1] = NSSet<float>, {}
        // We need random access, so this needs to be a vector.
        std::vector<std::string> typesSpelling;
    };

    std::vector<MetaData> _metaDataInfo;

    // This flag is used to notify the parser that it is suppose to merge all similar container types into one heterogeneous type.
    bool forceHeterogeneousContainerGeneration;

    void _processRawComments(const std::string& rawComments);

    void _parseTypes(const std::string& line, std::vector<std::string>& argInfo, size_t startId, MetaDataComments::MetaData& info);
    std::set<std::string> _parsePossibleTypes(const std::string& line, std::vector<std::string> types, bool isWithinHeterogeneousContainer);
    std::string _getTypeSpelling(const std::string& line, const std::string typeString);
    std::string _getContainerTypeSpelling(const std::string& line, const std::string typeString);
    std::string _getContainerTypeSpellingForArray(const std::string& line, const std::string typeString);
    std::string _getContainerTypeSpellingForDictionary(const std::string& line, const std::string typeString);
    std::string _getContainerTypeSpellingForSet(const std::string& line, const std::string typeString);
    std::string _parseTemplateArgumentTypes(const std::string& line, const std::string typeString, const std::string& objCContainerName);

public:
    MetaDataComments(CXCursor cursor, bool forceHeterogeneous = false);
    size_t getMetaDataSize();
    std::string getMetaDataType(size_t index);
    void setMetaDataType(size_t index, const std::string& metaDataType);
    void setParameterNumber(size_t index, int number);
    void setBlockParameterNumber(size_t index, int number);
    std::vector<std::string> getTypes(size_t index);
    void setTypes(size_t index, std::vector<std::string> typeInfo);
    bool isIgnoredType();
    bool isApplicationDelegate();
    bool isDelegateCallbackProtocol();
    void appendMetaData(const std::string& type, int paramNumber, int blockNumber, std::vector<std::string>& spellings);

    // Returns -1 in case we do not have this field
    int getBlockParameterNumber(size_t index);
    // Returns -1 in case we do not have this field
    int getParameterNumber(size_t index);

    // Returns empty string if the return type, paramter, or block parameter does not have metdata.
    std::string getReturnMetaData(int index = 0);
    std::string getParameterMetaData(int parameterNumber, int index = 0);
    std::string getBlockParameterMetaData(int parameterNumber, int blockParameterNumber, int index = 0);
    bool parameterHasMetaData(int parameterNumber);
    bool blockParameterHasMetaData(int blockParameterNumber);
    bool blockParameterHasMetaData(int parameterNumber, int blockParameterNumber);
    bool hasAsyncMetaData();
};

struct HeterogeneousContainerInfo {
    std::string name;
    std::string objCContainerName;
    std::string wrlContainerName;
    std::string wrlTemplateParams;
    std::string toObjCConvertor;
    std::string toWRLConvertor;
    std::set<std::string> types;
    std::set<std::string> valueTypes;
    std::vector<std::shared_ptr<ClangObjectModel::TypeInfo>> typesInfo;
    std::vector<std::shared_ptr<ClangObjectModel::TypeInfo>> valueTypesInfo;
};

struct ComponentInfo : public Symbol, public std::enable_shared_from_this<ComponentInfo> {
    std::unordered_map<std::string, std::shared_ptr<ProtocolInfo>> protocols;
    std::unordered_map<std::string, std::shared_ptr<InterfaceInfo>> ifaces;

    std::unordered_map<std::string, std::shared_ptr<ClangObjectModel::DelegateInfo>> delegates;
    std::set<std::shared_ptr<ClangObjectModel::AsyncClassInfo>, ClangObjectModel::AsyncClassInfo> asyncClasses;
    std::unordered_map<std::string, std::shared_ptr<ClangObjectModel::ParameterInfo>> typedefDecl;

    // maps the delegate callback protocol to InterfaceInfo type.
    std::map<std::string, std::shared_ptr<ProtocolInfo>> delegateCallbackProtocolsMap;

    // maps the generated heterogeneous conainter name to its information.
    std::map<std::string, std::shared_ptr<HeterogeneousContainerInfo>> heterogeneousContainers;

    // These are component level (global) enums.
    std::map<std::string, std::shared_ptr<TypeInfo>> enums;

    // All other headers included in current TU will be placed here.
    // These will be imported in the IDL generated for the current TU.
    std::unordered_set<std::string> referencedIDLs;

    // All interfaces/protocols referenced in the current component.
    // If the interface/protocols is not in the current component, the header will be #included in the generated .mm file.
    std::unordered_set<std::string> referencedInterfaces;
    std::unordered_set<std::string> referencedProtocols;

    std::map<std::string, std::shared_ptr<HeterogeneousContainerInfo>>::iterator getHeterogeneousContainerInfo(
        std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo);
    void clearAll();

    // Get all the ObjcCreatorFuncs for this component.
    std::unordered_map<std::string, std::shared_ptr<ClangObjectModel::TypeInfo>> getObjcCreatorFuncs();

    // Adds a reference to the interface name.  The reference is used for #import/#include in the generate idl and mm files.
    void AddReferenceToInterface(const std::string& interfaceName);
    void AddReferenceToProtocol(const std::string& protocolName);
};

struct ApplicationDelegateInfo {
    std::shared_ptr<ClangObjectModel::InterfaceInfo> ifaceInfo;
    std::shared_ptr<ClangObjectModel::MethodInfo> allocatorMethod;
    std::shared_ptr<ClangObjectModel::MethodInfo> initializerMethod;
};

struct GlobalData {
    std::shared_ptr<ClangObjectModel::ComponentInfo> currentComponent;
    std::vector<std::shared_ptr<ClangObjectModel::ComponentInfo>> components;

    // Maps interface name to the components which reference the interface
    std::unordered_multimap<std::string, std::shared_ptr<ClangObjectModel::ComponentInfo>> unresolvedInterfaces;

    // Maps protocol name to the components which reference the protocol
    std::unordered_multimap<std::string, std::shared_ptr<ClangObjectModel::ComponentInfo>> unresolvedProtocols;

    // Map of all the interfaces in the SDK, this does not include the synthesized interfaces generated
    // as a wrapper for IAsyncOperation TResult argument.
    std::unordered_map<std::string, std::shared_ptr<ClangObjectModel::InterfaceInfo>> interfaceMap;

    // Map of all synthesized interfaces generated for the SDK async methods.
    static std::unordered_map<std::string, std::shared_ptr<ClangObjectModel::InterfaceInfo>> synthesizedInterfaceMap;

    // Map or all the protocols in the SDK.
    std::unordered_map<std::string, std::shared_ptr<ClangObjectModel::ProtocolInfo>> protocolMap;

    std::map<std::string, std::shared_ptr<ClangObjectModel::ProtocolInfo>> delegateCallbackProtocolsMap;

    // These are all the enums we have found.
    std::map<std::string, std::shared_ptr<TypeInfo>> enums;

    std::shared_ptr<ClangObjectModel::ApplicationDelegateInfo> applicationDelegateInfo;

    bool requiresJSONMarshalling = false;
    bool requiresNSDateMarshalling = false;
    bool requiresNSURLMarshalling = false;
    bool requiresNSNotificationMarshalling = false;

    std::set<std::string> notifications;

    // Map of ObjC framework interfaces (e.g. UIButton) that middleware can subclass from
    static std::unordered_map<std::string, std::shared_ptr<ClangObjectModel::InterfaceInfo>> objCSuperClasses;

    // Returns the InterfaceInfo for the Objc framework interface (e.g. NSDate) if it is supproted.  Otherwise nullptr.
    // The supported framework interfaces are in the ObjCFrameworkInterfaces map.
    // Arguments:
    // objcType: The typeInfo which has the ObjC type information and for which a WRL name is requested.
    std::shared_ptr<ClangObjectModel::InterfaceInfo> GetObjCFrameworkInterfaces(const std::string& objcType);

    static const std::set<std::string> defaultDependentIdls;

private:
    // Map of ObjC framework interfaces that middleware can use and that we can project into WinRT.
    // E.g. NSDate is projected into WinRT as Windows.Foundation.DateTime.
    static std::unordered_map<std::string, std::shared_ptr<ClangObjectModel::InterfaceInfo>> _objCFrameworkInterfaces;
};
}
