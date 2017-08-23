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
#include <fstream>
#include <iostream>

extern ClangObjectModel::GlobalData g_globalData;
extern ClangHelpers::SDKParameters g_sdkParameters;
extern "C" const std::string g_winrtClassPrefix;

namespace ClangHelpers {
std::set<std::string> cachedFileNames;

std::string GetString(CXString cxString) {
    const char* cstr = clang_getCString(cxString);
    if (cstr != nullptr) {
        std::string str(cstr);
        str = Helpers::Trim(str);
        return str;
    }

    return "";
}

std::string GetCursorSpelling(const CXCursor cursor) {
    CXString spelling = clang_getCursorSpelling(cursor);
    std::string name = GetString(spelling);
    clang_disposeString(spelling);
    return name;
}

std::string GetTypeKindSpelling(const CXTypeKind typeKind) {
    CXString spelling = clang_getTypeKindSpelling(typeKind);
    std::string name = GetString(spelling);
    clang_disposeString(spelling);
    return name;
}

std::string GetTypeSpelling(const CXType type) {
    CXString spelling = clang_getTypeSpelling(type);
    std::string name = GetString(spelling);
    clang_disposeString(spelling);
    return name;
}

std::string GetCursorResultTypeSpelling(const CXCursor cursor) {
    CXType type = clang_getCursorResultType(cursor);
    return GetTypeSpelling(type);
}

std::string GetCursorTypeSpelling(const CXCursor cursor) {
    CXType type = clang_getCursorType(cursor);
    return GetTypeSpelling(type);
}

std::string GetMethodSpelling(const CXCursor cursor) {
    std::string name = GetDisplayName(cursor);

    std::vector<std::string> tokens;
    tokenize(name, tokens, ":");
    name.clear();
    for (auto token : tokens) {
        if (name.empty()) {
            name = token;
            continue;
        }

        token[0] = ::toupper(token[0]);
        name += token;
    }

    return name;
}

std::string GetDisplayName(const CXCursor cursor) {
    CXString spelling = clang_getCursorDisplayName(cursor);
    std::string name = GetString(spelling);
    clang_disposeString(spelling);

    return name;
}

std::string GetRawCommentText(const CXCursor cursor) {
    CXString spelling = clang_Cursor_getRawCommentText(cursor);
    std::string name = GetString(spelling);
    clang_disposeString(spelling);
    return name;
}

std::string GetCursorFileName(const CXCursor cursor) {
    CXFile file;
    clang_getExpansionLocation(clang_getCursorLocation(cursor), &file, NULL, NULL, NULL);
    CXString fileName = clang_getFileName(file);
    std::string name = GetString(fileName);
    clang_disposeString(fileName);
    return name;
}

std::string GetCursorSDKName(const CXCursor cursor) {
    std::string fileName = GetCursorFileName(cursor);
    Helpers::replaceAll(fileName, "/", "\\");
    for (auto SDK : g_sdkParameters.SDKHeaderArgMap) {
        ClangHelpers::header_argfile& haPair = SDK.second;
        std::ifstream headerFile(haPair.first);
        std::string line;
        while (getline(headerFile, line)) {
            Helpers::replaceAll(line, "/", "\\");
            if (line == fileName) {
                return SDK.first;
            }
        }
    }
    return "";
}

std::string generateDelegateName(std::vector<std::shared_ptr<ClangObjectModel::TypeInfo>>& params) {
    std::string name = "block";
    for (auto p : params) {
        name += "_" + TypeConvertor::_GetObjCTypeCreatorName(p, true);
    }
    return name + "_void";
}

std::shared_ptr<SourceLocationInfo> GetSourceLocation(const CXSourceLocation sourceLocation) {
    std::shared_ptr<SourceLocationInfo> locationInfo = make_shared<SourceLocationInfo>();
    CXFile file;
    clang_getFileLocation(sourceLocation, &file, &locationInfo->line, &locationInfo->column, &locationInfo->offset);

    CXString cxFileName = clang_getFileName(file);
    locationInfo->fileName = GetString(cxFileName);
    clang_disposeString(cxFileName);

    return locationInfo;
}

std::shared_ptr<SourceLocationInfo> GetSourceStartingLocation(CXCursor cursor) {
    std::shared_ptr<SourceLocationInfo> locationInfo;
    CXSourceRange range = clang_getCursorExtent(cursor);
    if (!clang_Range_isNull(range)) {
        CXSourceLocation source = clang_getRangeStart(range);
        locationInfo = GetSourceLocation(source);
    }
    return locationInfo;
}

std::string GetSource(const CXCursor cursor) {
    std::string source;

    CXSourceRange range = clang_getCursorExtent(cursor);
    if (!clang_Range_isNull(range)) {
        CXSourceLocation start = clang_getRangeStart(range);
        CXSourceLocation end = clang_getRangeEnd(range);
        std::shared_ptr<SourceLocationInfo> startLocationInfo = GetSourceLocation(start);
        std::shared_ptr<SourceLocationInfo> endLocationInfo = GetSourceLocation(end);

        ifstream file(startLocationInfo->fileName);
        if (!file.is_open()) {
            stringstream errorMsg;
            errorMsg << "Failed to open file " << startLocationInfo->fileName;
            throw std::exception(errorMsg.str().c_str());
        }

        std::unique_ptr<char> buf(new char[endLocationInfo->offset - startLocationInfo->offset + 1]{});
        file.seekg(startLocationInfo->offset);
        file.read(buf.get(), endLocationInfo->offset - startLocationInfo->offset);
        source = buf.get();
    }
    return source;
}

void updateParamInfoWithMetaData(std::shared_ptr<ClangObjectModel::MetaDataComments> metaData,
                                 size_t lineNumber,
                                 std::shared_ptr<ClangObjectModel::ParameterInfo>& param) {
    std::shared_ptr<ClangObjectModel::TypeInfo> visitedType;

    if (param->delegateParams.size() > 0) {
        // The metadata is for ObjC block parameters
        int blockParamNumber = metaData->getBlockParameterNumber(lineNumber);
        if (blockParamNumber == -1 || blockParamNumber >= (int)param->delegateParams.size()) {
            std::string err = "Out of bounds block parameter specified in meta data: " + blockParamNumber;
            Helpers::Errors::WriteError(nullptr, err, false);
        }
        param->delegateParams[blockParamNumber]->ResolveParameterType(metaData->getTypes(lineNumber)[0]);
    } else {
        param->typeInfo->ResolveParameterType(metaData->getTypes(lineNumber)[0]);
    }
}

void updateDelegateInfo(std::shared_ptr<ClangObjectModel::ParameterInfo>& param,
                        std::shared_ptr<ClangObjectModel::MethodInfo>& methodInfo) {
    // Push delegate to global data.
    // this is required as we need the delegates to be declared before their use in interfaces.
    std::shared_ptr<ClangObjectModel::DelegateInfo> delegateInfo = make_shared<ClangObjectModel::DelegateInfo>();
    delegateInfo->returnType = make_shared<ClangObjectModel::TypeInfo>();
    delegateInfo->name = generateDelegateName(param->delegateParams);
    delegateInfo->params = param->delegateParams;
    delegateInfo->returnType->setTypeName("");
    delegateInfo->returnType->typeKind = CXType_Void;
    delegateInfo->returnType->setTypeSpelling("void");
    delegateInfo->returnType->cursor = param->typeInfo->cursor;
    g_globalData.currentComponent->delegates.insert({ delegateInfo->name, std::move(delegateInfo) });
    param->typeInfo->annotation = "[in]";
}

// TODO: for now we are using NSError to indicate an async func.  We should use annotations.
// or some heuristic (block has 1 return type that is not nserror).
bool checkForAsync(std::shared_ptr<ClangObjectModel::ParameterInfo>& param) {
    bool fAsync = false;
    for (const auto& p : param->delegateParams) {
        if (p->getTypeSpelling() == "NSError*" || p->getTypeSpelling() == "NSError *") {
            fAsync = true;
            param->marshallDelegateAsAsync = true;
            break;
        }
    }

    return fAsync;
}

string getResolvedAsyncImplName(const shared_ptr<ClangObjectModel::AsyncClassInfo>& asyncInfo, string prefix, bool forIDL) {
    string resolvedName;
    if (asyncInfo->returnTypes.size() == 0) {
        return "";
    }

    if (asyncInfo->returnTypes.size() == 1 && asyncInfo->returnTypes[0]->isNativeType()) {
        resolvedName = asyncInfo->implName;
    } else {
        resolvedName = generateResolvedTypeName(prefix + asyncInfo->implName, asyncInfo->sdkName, forIDL) + "*";
    }

    return resolvedName;
}

string _getAsyncClassImplArgumentTypeName(std::shared_ptr<ClangObjectModel::TypeInfo>& typeInfo) {
    if (typeInfo->isContainer()) {
        string containedTypes;
        for (auto t : typeInfo->templateParams) {
            if (!containedTypes.empty()) {
                containedTypes += "And";
            }
            containedTypes += _getAsyncClassImplArgumentTypeName(t);
        }
        const TypeConvertor::ContainerTypeInfo* containerInfo = TypeConvertor::GetContainerInfo(typeInfo->getTypeSpelling());
        assert(containerInfo != nullptr);
        return containerInfo->WRLName + "Of" + containedTypes;
    } else if (typeInfo->getTypeSpelling(true) == "NSError") {
        return "ErrorValue";
    } else if (typeInfo->getSymbolKind() == ClangObjectModel::JSONType) {
        return "PropertySet";
    }

    return TypeConvertor::WinrtType(typeInfo, true);
}

string _getAsyncClassImplName(std::shared_ptr<ClangObjectModel::AsyncClassInfo>& asyncInfo, const string& sdkHeaderFile) {
    string name;
    if (asyncInfo->returnTypes.size() == 0) {
        asyncInfo->name = "_AsyncActionImpl";
        return "";
    } else if (asyncInfo->returnTypes.size() == 1) {
        return TypeConvertor::WinrtType(asyncInfo->returnTypes[0], true);
    } else {
        for (auto p : asyncInfo->returnTypes) {
            if (!name.empty()) {
                name += "_";
            }
            name += _getAsyncClassImplArgumentTypeName(p);
        }
        return asyncInfo->sdkName + "_" + sdkHeaderFile + "_" + "AsyncResult_" + name;
    }

    return "";
}

string getSynthesizedAsyncClassPropertyName(shared_ptr<ClangObjectModel::TypeInfo>& typeInfo) {
    return _getAsyncClassImplArgumentTypeName(typeInfo) + "_" + typeInfo->getTypeName();
}

string generateAsyncClassImplName(std::shared_ptr<ClangObjectModel::AsyncClassInfo>& asyncInfo, const string& sdkHeaderFile) {
    auto retTypeInfo = asyncInfo->returnTypes;

    asyncInfo->implName = _getAsyncClassImplName(asyncInfo, sdkHeaderFile);

    if (retTypeInfo.size() > 1) {
        // Two or more parameters.
        // We have to generate an interface for this with the block parameters as properties.
        auto synthesizedIface = make_shared<ClangObjectModel::InterfaceInfo>();
        for (auto item : retTypeInfo) {
            // Create a property getter and setter method for this item.
            string propertyName = getSynthesizedAsyncClassPropertyName(item);
            auto getterMethod = make_shared<ClangObjectModel::MethodInfo>();
            getterMethod->name = propertyName;
            getterMethod->methodNameForIDL = propertyName;
            getterMethod->methodNameForRuntimeClass = "get_" + propertyName;
            getterMethod->idlAnnotation = "[propget]";
            getterMethod->returnType = make_shared<ClangObjectModel::ParameterInfo>();
            getterMethod->returnType->marshallDelegateAsAsync = false;
            getterMethod->returnType->typeInfo = ClangObjectModel::TypeInfo::CloneTypeInfo(item);
            getterMethod->returnType->typeInfo->annotation = "[out] [retval]";
            synthesizedIface->instanceMethods.push_back(getterMethod);
        }
        synthesizedIface->name = asyncInfo->implName;
        synthesizedIface->SDKname = asyncInfo->sdkName;
        asyncInfo->synthesizedInterface = synthesizedIface;
        ClangObjectModel::GlobalData::synthesizedInterfaceMap.insert({ synthesizedIface->name, synthesizedIface });
    }

    return asyncInfo->implName;
}

void updateAsyncClassInfo(std::shared_ptr<ClangObjectModel::ParameterInfo>& param,
                          std::shared_ptr<ClangObjectModel::MethodInfo>& methodInfo) {
    // Try to determine the return type
    param->marshallDelegateAsAsync = true;
    methodInfo->UpdateMethodNameForIDLAndRuntimeClass(methodInfo->getMethodNameForIdl() + "Async",
                                                      methodInfo->getMethodNameForRuntimeClass() + "Async");
    std::shared_ptr<ClangObjectModel::TypeInfo> retTypeInfo;
    std::vector<std::shared_ptr<ClangObjectModel::TypeInfo>> retTypes;
    std::shared_ptr<ClangObjectModel::AsyncClassInfo> asyncInfo = make_shared<ClangObjectModel::AsyncClassInfo>();
    for (const auto& p : param->delegateParams) {
        asyncInfo->returnTypes.push_back(p);
    }
    asyncInfo->sdkName = g_globalData.currentComponent->getSDKName();

    // Temporary unique name, right now we know nothing about the types this delegate uses.
    // So generate a name based only on the ObjC types.
    // Later we will replace with WinRT type name to make it easier for the winrt user.
    asyncInfo->implName = generateDelegateName(asyncInfo->returnTypes);
    asyncInfo->name = asyncInfo->implName;

    auto it = g_globalData.currentComponent->asyncClasses.find(asyncInfo);
    if (it != g_globalData.currentComponent->asyncClasses.end()) {
        // This type already exists.
        param->asyncInfo = *it;
    } else {
        param->asyncInfo = asyncInfo;
        g_globalData.currentComponent->asyncClasses.insert(asyncInfo);
    }
}

bool isInterface(const std::string& typeSpelling) {
    string baseType = Helpers::baseType(typeSpelling, true);
    if (g_globalData.interfaceMap.find(baseType) != g_globalData.interfaceMap.end()) {
        return true;
    }
    if (ClangObjectModel::GlobalData::synthesizedInterfaceMap.find(baseType) !=
        ClangObjectModel::GlobalData::synthesizedInterfaceMap.end()) {
        return true;
    }

    return false;
}

bool isProtocol(const std::string& typeSpelling) {
    bool isProtocol = false;

    string baseType = Helpers::Trim(Helpers::baseType(typeSpelling, true));
    auto it = g_globalData.protocolMap.find(baseType);
    if (it != g_globalData.protocolMap.end()) {
        isProtocol = true;
    }
    return isProtocol;
}

bool isDelegateCallbackProtocol(const std::string& typeSpelling) {
    bool isDelegateCallbackProtocol = false;

    string baseType = Helpers::Trim(Helpers::baseType(typeSpelling, true));
    auto it = g_globalData.delegateCallbackProtocolsMap.find(baseType);
    if (it != g_globalData.delegateCallbackProtocolsMap.end()) {
        isDelegateCallbackProtocol = true;
    }
    return isDelegateCallbackProtocol;
}

bool isCursorFromProjectHeaders(const CXCursor cursor) {
    if (cachedFileNames.size() == 0) {
        for (auto SDK : g_sdkParameters.SDKHeaderArgMap) {
            ClangHelpers::header_argfile& haPair = SDK.second;
            std::ifstream headerFile(haPair.first);
            std::string line;
            while (getline(headerFile, line)) {
                Helpers::replaceAll(line, "/", "\\");
                cachedFileNames.insert(line);
            }
        }
    }

    std::string fileName = GetCursorFileName(cursor);
    Helpers::replaceAll(fileName, "/", "\\");
    auto iter = cachedFileNames.find(fileName);
    if (iter != cachedFileNames.end()) {
        return true;
    }
    return false;
}

std::string generateResolvedTypeName(const std::string& symbolName, const std::string& sdkName, bool forIDL, const std::string prefixStr) {
    std::string separator;
    std::string prefix;
    if (!forIDL) {
        separator = "::";
        prefix = prefixStr == "" ? "" : prefixStr + "::";
    } else {
        separator = ".";
        prefix = "";
    }

    return prefix + generateNamespaceString(sdkName, separator) + separator + symbolName;
}

std::string generateNamespaceString(const std::string& sdkName, const std::string& separator) {
    std::string name = sdkName;
    if (sdkName == g_sdkParameters.rootNameSpace) {
        name = "_" + name;
    }

    return g_sdkParameters.rootNameSpace + separator + name;
}

std::string getEnumTypeName(std::string spelling) {
    spelling = Helpers::Trim(spelling);
    std::string enumPrefix = "enum ";
    if (spelling.find(enumPrefix) != 0) {
        return spelling;
    }

    return Helpers::Trim(spelling.substr(enumPrefix.size()));
}

std::string generateMethodNameWithParameterType(std::shared_ptr<ClangObjectModel::MethodInfo>& method) {
    std::vector<std::string> tokens;
    std::string displayName = method->displayName;

    // save empty tokens
    tokenize(displayName, tokens, ":", "", "\"", "", "\\", false, true);

    std::string name;
    size_t count = 0;
    for (auto token : tokens) {
        if (token.empty()) {
            token = "Unnamed";
        }
        token[0] = ::toupper(token[0]);
        std::string type = "";
        if (count < method->params.size() && method->params[count]->typeInfo->typeKind != CXType_BlockPointer) {
            type = Helpers::baseType(Helpers::Trim(method->params[count]->typeInfo->getTypeSpelling()));
            type[0] = ::toupper(type[0]);
        }
        count++;
        if (name.empty()) {
            name = token + type;
            continue;
        }

        name += token + type;
    }

    return name;
}

std::string _fixName(std::string name, std::set<std::string>& methodNames, std::shared_ptr<ClangObjectModel::MethodInfo>& method) {
    auto it = methodNames.find(name);
    if (it == methodNames.end()) {
        methodNames.insert(name);
        return name;
    }

    // There was a conflict.
    bool parameterTypeUsed = false;
    int numericPrefix = 0;
    std::string newName;
    do {
        if (!parameterTypeUsed) {
            // try to use parameter types.
            parameterTypeUsed = true;
            newName = ClangHelpers::generateMethodNameWithParameterType(method);
        } else {
            // try to use the numeric prefix.
            numericPrefix++;
            newName = method->getMethodNameForIdl() + std::to_string(numericPrefix);
        }
        it = methodNames.find(newName);
    } while (it != methodNames.end());

    return newName;
}

void _fixMethodNameConflicts(std::set<std::string>& methodNames, std::vector<std::shared_ptr<ClangObjectModel::MethodInfo>>& methods) {
    int totalMethods = methods.size();
    std::string name;
    for (int i = 0; i < totalMethods; i++) {
        if (methods[i]->isSynthesizedProperty || methods[i]->isPolymorphic) {
            continue;
        }

        name = _fixName(methods[i]->getMethodNameForIdl(), methodNames, methods[i]);
        methods[i]->UpdateMethodNameForIDLAndRuntimeClass(name);
    }
}

void fixMethodNameConflicts(std::vector<std::shared_ptr<ClangObjectModel::MethodInfo>>& methods) {
    // push all methods into a set, for any conflict change that method name by using the parameters.
    // Try to push it again into the set, if it still conflicts append a number at the end.
    std::set<std::string> methodNames;

    // we do not modify methods which are synthesized for properties or methods which were generated for 'id' types.
    for (auto method : methods) {
        if (!(method->isSynthesizedProperty || method->isPolymorphic)) {
            continue;
        }

        methodNames.insert(method->getMethodNameForIdl());
        methodNames.insert(method->getMethodNameForRuntimeClass());
    }

    _fixMethodNameConflicts(methodNames, methods);
}

string getDelegateParamNameListForWinRT(std::shared_ptr<ClangObjectModel::ParameterInfo> paramInfo) {
    return Helpers::addSeparators(paramInfo->delegateParams, [&](const std::shared_ptr<ClangObjectModel::TypeInfo> t) {
        return TypeConvertor::getWRLConvertorFuncForType(t, t->getTypeName());
    });
}

shared_ptr<ClangObjectModel::InterfaceInfo> getInterfaceImplementingProtocol(const std::string& protocolName) {
    string name = Helpers::Trim(Helpers::baseType(protocolName, true));
    if (g_globalData.delegateCallbackProtocolsMap.find(name) != g_globalData.delegateCallbackProtocolsMap.end()) {
        return nullptr;
    }

    // Find the first public interface which implements this protocol, and return its RT wrapper.
    for (auto ifacePair : g_globalData.interfaceMap) {
        auto protocols = ifacePair.second->getProtocolsImplemented();
        for (auto protocol : protocols) {
            if (Helpers::Trim(Helpers::baseType(protocol->name, true)) == name) {
                return ifacePair.second;
            }
        }
    }

    Helpers::Errors::WriteError(nullptr, "No interface found which implements protocol" + protocolName, false);

    return nullptr;
}

std::string generateCallToIslandWoodInit() {
    std::stringstream ss;
    ss << "        std::call_once(g_IslandwoodIsInitialized, []() {" << std::endl;
    string appDelegateName =
        g_globalData.applicationDelegateInfo != nullptr ? "L\"_" + g_globalData.applicationDelegateInfo->ifaceInfo->name + "\"" : "nullptr";
    ss << "            UIApplicationInitialize(nullptr, " + appDelegateName + ");" << std::endl;
    ss << "        });" << std::endl;
    return ss.str();
}

std::vector<std::string> tokenize_CompleteTypes(const std::string& possibleTypes) {
    vector<string> ret;
    size_t len = possibleTypes.length();
    size_t start = 0;
    size_t end = 0;
    int bracketCount = 0;
    for (size_t i = 0; i < len; i++) {
        switch (possibleTypes[i]) {
            case '>':
                bracketCount--;
                break;
            case ClangObjectModel::possibleTypesSeparator:
                if (bracketCount == 0) {
                    end = i;
                    string str = Helpers::Trim(possibleTypes.substr(start, end - start));
                    if (str.length()) {
                        ret.push_back(str);
                    }

                    start = i + 1;
                } else {
                    // We seem to be parsing a sub-type which is a container.
                    // simply continue.
                }
                break;

            case '<':
                bracketCount++;
                break;
        }
    }

    if (bracketCount) {
        return {};
    }

    if (start < len) {
        string str = Helpers::Trim(possibleTypes.substr(start, len - start));
        if (str.length()) {
            ret.push_back(str);
        }
    }

    return ret;
}
}