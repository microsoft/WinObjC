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
#include <iostream>

extern ClangObjectModel::GlobalData g_globalData;
extern ClangHelpers::SDKParameters g_sdkParameters;
extern "C" const std::string g_winrtClassPrefix;
extern "C" const string g_commonConvertors;

namespace TypeConvertor {
string ToObjCTypeConvertor::instantiator(const std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo) {
    return typeInfo->getTypeSpelling() + "()";
}

string _ArrayToNSArrayConvertor::instantiator(const std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo) {
    const TypeConvertor::ContainerTypeInfo* ci = GetContainerInfo(typeInfo->getTypeSpelling());
    auto tp = typeInfo->templateParams[0];
    string objCConvertorFunc = GetObjCTypeCreatorName(tp);
    string wrlConvertorFunc = GetWRLTypeCreatorName(tp);

    // The symbol val used below is the argument to the creator function
    // e.g. id RTProxiedNSArrayFull_int_create(IInspectable* val);
    string nullCheck =
        "    if (val == nullptr) {\n"
        "        return nil;\n"
        "    }\n";
    return nullCheck + "    std::unique_ptr<" + ci->adapterObjBase + "> adapter = std::make_unique<" + ci->adapterObj + "<" +
           GetWRLTypeNameForContainerTemplates(typeInfo) + ",\n    " + ci->implClassName + "<" +
           GetWRLTypeNameForContainerTemplates(tp, true, false) + ", " + GetWRLTypeNameForContainerTemplates(typeInfo) + ", " +
           GetObjCTypeName(tp) + ", " + GetWRLTypeNameForContainerTemplates(tp, true, false) + ", " + objCConvertorFunc + ", " +
           wrlConvertorFunc + ">>>(val);\n" + "    return [[[" + ci->objCProxyName +
           " alloc] initWithAdapter:std::move(adapter)] autorelease];";
}

string _MapViewToNSDictionaryConvertor::instantiator(const std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo) {
    const TypeConvertor::ContainerTypeInfo* ci = GetContainerInfo(typeInfo->getTypeSpelling());
    auto keyT = typeInfo->templateParams[0];
    auto valT = typeInfo->templateParams[1];
    string keyObjCConvertorFunc = GetObjCTypeCreatorName(keyT);
    string valObjCConvertorFunc = GetObjCTypeCreatorName(valT);
    string keyWRLConvertorFunc = GetWRLTypeCreatorName(keyT);
    string valWRLConvertorFunc = GetWRLTypeCreatorName(valT);

    string wrlK = GetWRLTypeNameForContainerTemplates(keyT, true, false);
    string wrlV = GetWRLTypeNameForContainerTemplates(valT, true, false);
    string objcK = GetObjCTypeName(keyT);
    string objcV = GetObjCTypeName(valT);

    string keyEnumeratorAdapterTypeT =
        string("DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<") + wrlK + "," + wrlK + "," + objcK + ", " + wrlV + ">>";

    string baseTypeT = ci->implClassName + "<" + wrlK + "," + wrlK + ", " + wrlV + ", " + wrlV + ", " + objcK + ", " + objcV + ", " +
                       GetWRLTypeNameForContainerTemplates(typeInfo) + ", " + keyObjCConvertorFunc + ", " + valObjCConvertorFunc + ", " +
                       keyWRLConvertorFunc + ", " + valWRLConvertorFunc + ">";

    // The symbol val used below is the argument to the creator function
    string nullCheck =
        "    if (val == nullptr) {\n"
        "        return nil;\n"
        "    }\n";
    return nullCheck + "    std::unique_ptr<" + ci->adapterObjBase + "> adapter = std::make_unique<" + ci->adapterObj + "<" +
           GetWRLTypeNameForContainerTemplates(typeInfo) + ",\n    " + keyEnumeratorAdapterTypeT + ",\n    " + baseTypeT + ">>(val);\n" +
           "    return [[[" + ci->objCProxyName + " alloc] initWithAdapter:std::move(adapter)] autorelease];";
}

const TypeConvertor::ContainerTypeInfo* GetContainerInfo(const std::string& objcType) {
    // For container type strip out the generics and pointer
    vector<string> spellings;
    Helpers::splitString(objcType, spellings, "< *", true);
    if (spellings.size() > 0) {
        auto containerIt = TypeConvertor::ContainerTypeMap.find(spellings[0]);
        if (containerIt != TypeConvertor::ContainerTypeMap.end()) {
            return &(containerIt->second);
        }
    }

    return nullptr;
}

// objcType: some objective-c type.
// output: if objctype is id<protocol> then output is protocol.
//        else output is an empty string
std::string TypeConvertor::GetProtocolFromId(const std::string& objcType) {
    // NOTE: It is assumed the objcType come from libclang.  Libclang will clean up the string for us and remove any extraneous white space.
    // We can also assume the string is properly formatted
    std::string protocolName;

    size_t startIdx = 0;
    size_t endIdx = 0;
    if (isGeneric(objcType, &startIdx, &endIdx)) {
        protocolName = objcType.substr(startIdx + 1, (endIdx - startIdx - 1));
    }
    return protocolName;
}

string WinRTNativeType(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo) {
    std::string objcType = typeInfo->getTypeSpelling();
    string suffix = Helpers::getPointerSuffix(objcType);

    if (typeInfo->isVoidType(true) && !suffix.empty()) {
        // There is an attempt to marshal a pointer to void, which is not allowed.
        Helpers::Errors::WriteError(typeInfo->sourceLocation, "Cannot marshall pointer to void", false);
    }

    string baseObjCType = Helpers::Trim(Helpers::baseType(objcType, true));
    auto it = TypeConvertor::NativeTypeMap.find(baseObjCType);
    if (it != TypeConvertor::NativeTypeMap.end()) {
        string returnType = it->second;
        if (baseObjCType != "NSString") {
            returnType += suffix;
        }

        return returnType;
    }

    stringstream errorMsg;
    errorMsg << "Don't know how to marshall " << objcType << ".  Assuming int." << std::endl;
    Helpers::Errors::WriteError(typeInfo->sourceLocation, errorMsg.str(), true);
    return "int";
}

// objc type name -> winrt/idl type name
string WinrtType(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo, bool baseType, bool forIDL) {
    if (typeInfo->getSymbolKind() == ClangObjectModel::JSONType || typeInfo->getTypeSpelling(true) == "NSError") {
        string wrlName = "IMapView<HSTRING, IInspectable*>*";
        if (!baseType) {
            wrlName += "*";
        }
        return wrlName;
    }

    if (typeInfo->isHeterogeneous) {
        auto it = g_globalData.currentComponent->getHeterogeneousContainerInfo(typeInfo);
        string wrlName = it->second->wrlContainerName + "<" + it->second->wrlTemplateParams + ">*";
        if (!baseType) {
            wrlName += "*";
        }
        return wrlName;
    }

    if (typeInfo->typeKind == CXType_Enum) {
        return "enum " + ClangHelpers::generateResolvedTypeName(typeInfo->getTypeSpelling(), typeInfo->getSDKName(), forIDL);
    }

    if (typeInfo->isInterface() || typeInfo->isProtocol()) {
        std::string ret = typeInfo->getTypeSpelling();
        if (baseType) {
            ret = Helpers::baseType(ret);
        }
        return ret;
    }

    if (typeInfo->isContainer()) {
        return WinRTContainerType(typeInfo, baseType, forIDL);
    }

    if (typeInfo->isNSDateType() || typeInfo->isNSURLType()) {
        auto frameworkInterface = g_globalData.GetObjCFrameworkInterfaces(typeInfo->getTypeSpelling());
        return (forIDL ? frameworkInterface->GetIdlRuntimeClassName() : frameworkInterface->GetWinrtClassName());
    }

    if (ClangHelpers::isDelegateCallbackProtocol(typeInfo->getTypeSpelling(true))) {
        return "[(" + typeInfo->getTypeSpelling(true) + "*)" + typeInfo->getTypeName() + " getInternalComObj].Detach()";
    }

    return WinRTNativeType(typeInfo);
}

string WinRTTemplateType(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo, bool forIDL) {
    if (typeInfo->isContainer()) {
        return WinRTContainerType(typeInfo, true, forIDL);
    }

    std::string type = TypeConvertor::WinrtType(typeInfo, false, forIDL);
    if (ClangHelpers::isInterface(typeInfo->getTypeSpelling())) {
        if (typeInfo->SDKname.empty()) {
            // template params could have an empty SDKName because of forward declarations of interfaces.
            // When this method is called we expect to have resolved all our symbols.
            auto it = g_globalData.interfaceMap.find(Helpers::baseType(typeInfo->getTypeSpelling()));
            if (it == g_globalData.interfaceMap.end()) {
                std::string err = "Unresolved symbol detected: " + typeInfo->getTypeSpelling();
                throw std::invalid_argument(err.c_str());
            }

            typeInfo->SDKname = it->second->getSDKName();
        }

        type = ClangHelpers::generateResolvedTypeName("I" + type, typeInfo->getSDKName(), forIDL);
    }

    return type;
}
string WinRTTemplateParams(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo, bool forIDL) {
    string templateParams;
    for (auto p : typeInfo->templateParams) {
        if (templateParams.size() > 0) {
            templateParams += ", ";
        }

        templateParams += WinRTTemplateType(p, forIDL);
    }

    return templateParams;
}
string WinRTContainerType(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo, bool baseType, bool forIDL) {
    string wrlContainerType = typeInfo->wrlName;

    string templateParams = "";
    if (typeInfo->templateParams.size() == 0) {
        templateParams = "int";
        stringstream errorMsg;
        errorMsg << "The type the " << typeInfo->getTypeSpelling() << "container holds is unknown. ";
        errorMsg << "Containers must be strongly typed for a WinRT component.  Please add annotations to the method or generics to the API "
                    "definition. ";
        errorMsg << "Assuming " << wrlContainerType + "<" + templateParams + ">" << std::endl;
        Helpers::Errors::WriteError(typeInfo->sourceLocation, errorMsg.str(), true);

    } else {
        templateParams = WinRTTemplateParams(typeInfo, forIDL);
    }

    wrlContainerType = wrlContainerType + "<" + templateParams + ">*";
    if (!baseType) {
        wrlContainerType += "*";
    }

    return wrlContainerType;
}

void SetTemplateTypeInfo(std::vector<std::shared_ptr<ClangObjectModel::TypeInfo>>& templateParams, const std::string& metadata) {
    string templateString = metadata;
    vector<string> words;

    while (templateString.length() > 0) {
        words.clear();
        size_t idx = templateString.find_first_not_of("<,> *");
        templateString = templateString.substr(idx);

        Helpers::splitString(templateString, words, "<>,", true);
        templateParams.push_back(make_shared<ClangObjectModel::TypeInfo>());
        // If type is container call SetContainerTypeInfo(typeInfo, metadata).
        if (TypeConvertor::GetContainerInfo(words[0]) != nullptr) {
            int count = 1;
            idx = templateString.find_first_of('<');
            if (idx == templateString.npos) {
                std::string err = "Invalid type: " + templateString;
                throw std::invalid_argument(err.c_str());
            }

            // Match '<' with the corresponding '>' symbol, and get the index where '>' symbol was found.
            // Everything in between is the template argument.
            for (size_t i = idx + 1; i < templateString.length(); i++) {
                if (templateString[i] == '<') {
                    count++;
                } else if (templateString[i] == '>') {
                    count--;
                    if (count == 0) {
                        idx = i;
                        break;
                    }
                }
            }

            if (idx == templateString.length()) {
                std::string err = "Invalid type: " + templateString;
                throw std::invalid_argument(err.c_str());
            }

            string containerString = templateString.substr(0, idx + 1);
            idx = templateString.find_first_not_of(" ,<>*", idx + 1);
            if (idx == templateString.npos) {
                templateString = "";
            } else {
                templateString = templateString.substr(idx);
            }
            TypeConvertor::SetContainerTypeInfo(templateParams.back(), containerString);
        } else {
            std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo = templateParams.back();
            typeInfo->setTypeSpelling(words[0]);
            if (ClangHelpers::isInterface(Helpers::Trim(Helpers::baseType(typeInfo->getTypeSpelling())))) {
                typeInfo->wrlName = Helpers::Trim(Helpers::baseType(typeInfo->getTypeSpelling()));
                g_globalData.currentComponent->AddReferenceToInterface(typeInfo->getTypeSpelling());
            } else {
                typeInfo->wrlName = TypeConvertor::WinRTNativeType(typeInfo);
            }

            size_t idx = templateString.find_first_of(',');
            if (idx == templateString.npos) {
                break;
            }
            templateString = templateString.substr(idx + 1);
        }
    }
}

void SetContainerTypeInfo(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo, const std::string& metadata) {
    // extract container type.
    string containerName = Helpers::getContainerName(metadata);

    // set typeInfo->wrlname.
    typeInfo->wrlName = TypeConvertor::GetContainerTypeNameForABI(containerName);
    typeInfo->setTypeSpelling(containerName);

    // get substring between first '<' and last '>'
    size_t idx1;
    size_t idx2;
    if (!isGeneric(metadata, &idx1, &idx2)) {
        return;
    }

    // extract teplate params from substring.
    string templateString = metadata.substr(idx1 + 1, (idx2 - idx1 - 1));

    // clear out any previous template meta data information.
    typeInfo->templateParams.clear();
    SetTemplateTypeInfo(typeInfo->templateParams, templateString);
    typeInfo->updateObjCCreatorFunctionName(TypeConvertor::GetObjCTypeCreatorName(typeInfo), typeInfo);
}

std::string GetObjCTypeName(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo, bool pureObjCName) {
    if (typeInfo->isHeterogeneous) {
        return typeInfo->getTypeSpelling();
    } else if (typeInfo->isContainer()) {
        const TypeConvertor::ContainerTypeInfo* ci = GetContainerInfo(typeInfo->getTypeSpelling());
        return (pureObjCName ? ci->ObjCName : ci->objCProxyName);
    }

    return Helpers::baseType(typeInfo->getTypeSpelling());
}

string GetWRLTypeNameForContainerTemplates(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo, bool interfaceType, bool baseType) {
    string wrlName = typeInfo->wrlName;
    if (ClangHelpers::isInterface(wrlName)) {
        string prefix = interfaceType ? "I" : "";
        wrlName = ClangHelpers::generateResolvedTypeName(prefix + typeInfo->wrlName, typeInfo->getSDKName());
        if (!baseType) {
            wrlName += "*";
        }
    }

    if (typeInfo->isHeterogeneous) {
        auto it = g_globalData.currentComponent->heterogeneousContainers.find(typeInfo->getTypeSpelling(true));
        if (it == g_globalData.currentComponent->heterogeneousContainers.end()) {
            Helpers::Errors::WriteError(nullptr, "Cannot find heterogeneous container info", false);
        }
        wrlName = it->second->wrlContainerName + "<" + it->second->wrlTemplateParams + ">";
        if (!baseType) {
            wrlName += "*";
        }
    }

    if (typeInfo->isContainer()) {
        string tp = "";
        for (auto p : typeInfo->templateParams) {
            if (tp.size() > 0) {
                tp += ", ";
            }

            if (p->isContainer()) {
                tp += GetWRLTypeNameForContainerTemplates(p, interfaceType, false);
            } else {
                if (ClangHelpers::isInterface(p->wrlName)) {
                    string prefix = interfaceType ? "I" : "";
                    tp += ClangHelpers::generateResolvedTypeName(prefix + p->wrlName, p->getSDKName()) + "*";
                } else {
                    tp += p->wrlName;
                }
            }
        }

        wrlName += "<" + tp + ">";
        if (!baseType) {
            wrlName += "*";
        }
    }

    return wrlName;
}

string GetContainerTypeNameForABI(const std::string& objcType) {
    const ContainerTypeInfo* containerInfo = TypeConvertor::GetContainerInfo(objcType);
    if (containerInfo) {
        return containerInfo->WRLName;
    } else {
        // Check if this is heterogeneous container
        auto it = g_globalData.currentComponent->heterogeneousContainers.find(objcType);
        if (it != g_globalData.currentComponent->heterogeneousContainers.end()) {
            return it->second->wrlContainerName;
        }
    }
    return "";
}

string _GetObjCTypeCreatorName(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo, bool pureObjCName) {
    if (typeInfo->isHeterogeneous) {
        return typeInfo->getTypeSpelling();
    } else if (typeInfo->isContainer()) {
        string containedTypes = "";
        for (auto t : typeInfo->templateParams) {
            if (!containedTypes.empty()) {
                containedTypes += "And";
            }
            containedTypes += _GetObjCTypeCreatorName(t);
        }
        return GetObjCTypeName(typeInfo, pureObjCName) + "Of" + containedTypes;
    }

    return Helpers::baseType(typeInfo->getTypeSpelling());
}

std::string getWRLConvertorFuncForType(const std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo, const std::string& callString) {
    std::string convertor;
    if (typeInfo->isHeterogeneous) {
        auto it = g_globalData.currentComponent->getHeterogeneousContainerInfo(typeInfo);
        convertor =
            ClangHelpers::generateResolvedTypeName(it->second->toWRLConvertor, g_globalData.currentComponent->getSDKName(), false, "");
        return "static_cast<" + it->second->wrlContainerName + "<" + it->second->wrlTemplateParams + ">*>(" + convertor + "(" + callString +
               ").Detach())";
    } else if (typeInfo->isContainer()) {
        const TypeConvertor::ContainerTypeInfo* containerInfo = TypeConvertor::GetContainerInfo(typeInfo->getTypeSpelling());
        convertor = TypeConvertor::GetWRLTypeCreatorName(typeInfo);
        string tp;
        for (auto p : typeInfo->templateParams) {
            if (!tp.empty()) {
                tp += ", ";
            }

            tp += TypeConvertor::GetWRLTypeNameForContainerTemplates(p, true, false);
        }
        return "static_cast<" + containerInfo->WRLName + "<" + tp + ">*>(" + convertor + "(" + callString + ").Detach())";

    } else if (ClangHelpers::isInterface(typeInfo->getTypeSpelling())) {
        string ifaceName = typeInfo->getTypeSpelling(true);
        auto iface = g_globalData.interfaceMap.find(ifaceName);
        if (iface == g_globalData.interfaceMap.end()) {
            std::string err = "Unknown interface: " + ifaceName;
            Helpers::Errors::WriteError(nullptr, err, false);
        }

        if (iface->second->DerivesFromUIElement()) {
            std::string runtimeClass = ClangHelpers::generateResolvedTypeName(g_winrtClassPrefix + typeInfo->getTypeSpelling(true),
                                                                              typeInfo->getSDKName(),
                                                                              false,
                                                                              "");
            std::string ABIInterface =
                ClangHelpers::generateResolvedTypeName("I" + typeInfo->getTypeSpelling(true), typeInfo->getSDKName(), false);

            string tempObjcObject = "_" + typeInfo->getTypeName();
            string tempComObject = "_" + typeInfo->getTypeName() + "_comobj";

            stringstream ss;
            ss << endl;
            ss << "^ComPtr<" << ABIInterface << ">() {" << endl;
            ss << "id " << tempObjcObject << " = (" << callString << ");" << endl;
            ss << "if (" << tempObjcObject << " == nil) {" << endl;
            ss << "    return nullptr;" << endl;
            ss << "}" << endl;

            ss << "ComPtr<" << ABIInterface << "> " << tempComObject << ";" << endl;
            ss << "WeakRefWrapper* _weakRefWrapper = [" << tempObjcObject << " weakRefWrapper];" << endl;
            ss << "if (_weakRefWrapper == nil) {" << endl;
            ss << "    THROW_NS_IF_FAILED(MakeAndInitialize<" << runtimeClass << ">(" << tempComObject << ".GetAddressOf()));" << endl;
            ss << "} else {" << endl;
            ss << "    WeakRef weakRef = _weakRefWrapper.weakRefComObj;" << endl;
            ss << "    weakRef.As(&" << tempComObject << ");" << endl;
            ss << "}" << endl;
            ss << "return " << tempComObject << ";" << endl;

            ss << "}()";
            return ss.str();
        } else {
            std::string resolvedType = ClangHelpers::generateResolvedTypeName(g_winrtClassPrefix + typeInfo->getTypeSpelling(true),
                                                                              typeInfo->getSDKName(),
                                                                              false,
                                                                              "");
            string temp = "_" + typeInfo->getTypeName();
            stringstream ss;
            ss << endl;
            ss << "^" << resolvedType << "*() {" << endl;
            ss << "id " << temp << " = (" << callString << ");" << endl;
            ss << "return " << temp << " != nil ? Make<" << resolvedType << ">(_" << typeInfo->getTypeName() << ").Detach() : nullptr;"
               << endl;
            ss << "}()";
            return ss.str();
        }

    } else if (TypeConvertor::WinrtType(typeInfo, true) == "HSTRING") {
        return "nsStrToHstr(" + callString + ").Detach()";
    } else if (typeInfo->typeKind == CXType_Enum) {
        return "(" + ClangHelpers::generateResolvedTypeName(typeInfo->getTypeSpelling(), typeInfo->getSDKName()) + ")" + callString;
    } else if (typeInfo->isNSDateType()) {
        return g_commonConvertors + "::convertNSDateToWinRT(" + callString + ")";
    } else if (typeInfo->getSymbolKind() == ClangObjectModel::JSONType) {
        return "static_cast<IMapView<HSTRING, IInspectable*>*>(" + g_commonConvertors + "::convertNSDictionaryToPropertySet(" + callString +
               ").Detach())";
    } else if (typeInfo->isNSURLType()) {
        if (typeInfo->getTypeSpellingLowerCase(true) == "uri") {
            return g_commonConvertors + "::convertNSURLToWinRTUri(" + callString + ").Detach()";
        } else {
            // Converting NSURL back to StorageFile is not yet supported.
            return "";
        }
    } else if (typeInfo->isIdWithProtocolConformance()) {
        // Find the first public interface which implements this protocol, and return its RT wrapper.
        auto iface = ClangHelpers::getInterfaceImplementingProtocol(typeInfo->getTypeSpelling(true));
        if (iface == nullptr) {
            // This is our ObjC delegate callback protocol.
            // The WinRT object is the internalComObj.
            return "[(" + typeInfo->getTypeSpelling(true) + "*)" + callString + " getInternalComObj].Detach()";
        } else {
            std::string resolvedType =
                ClangHelpers::generateResolvedTypeName(g_winrtClassPrefix + Helpers::Trim(Helpers::baseType(iface->name, true)),
                                                       iface->getSDKName(),
                                                       false,
                                                       "");
            return "Make<" + resolvedType + ">(" + callString + ").Detach()";
        }
    } else if (typeInfo->getTypeSpelling(true) == "NSError") {
        return "static_cast<IMapView<HSTRING, IInspectable*>*>(" + g_commonConvertors + "::convertNSErrorToPropertySet(" + callString +
               ").Detach())";
    } else if (typeInfo->isNativeType() && !typeInfo->isVoidType()) {
        return "(" + WinRTNativeType(typeInfo) + ")" + callString;
    }

    return callString;
}

std::string GeneratePolymorphicName(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo) {
    if (typeInfo->isContainer()) {
        string containedTypes = "";
        for (auto t : typeInfo->templateParams) {
            containedTypes += "_";
            containedTypes += GeneratePolymorphicName(t);
        }
        const TypeConvertor::ContainerTypeInfo* ci = GetContainerInfo(typeInfo->getTypeSpelling());
        return ci->WRLName + containedTypes;
    }

    return Helpers::baseType(typeInfo->getTypeSpelling());
}

string GetWRLTypeCreatorName(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo) {
    const ContainerTypeInfo* containerInfo = GetContainerInfo(typeInfo->getTypeSpelling());
    if (containerInfo) {
        std::string convertor = containerInfo->toWRLConvertor;
        string tp = "";
        string objCCreators;
        string wrlCreators;
        for (auto p : typeInfo->templateParams) {
            if (tp.size() > 0) {
                tp += ", ";
            }

            tp += TypeConvertor::GetObjCTypeName(p) + ", " + GetWRLTypeNameForContainerTemplates(p, true, false);

            if (!objCCreators.empty()) {
                objCCreators += ", ";
            }

            if (!wrlCreators.empty()) {
                wrlCreators += ", ";
            }

            objCCreators += TypeConvertor::GetObjCTypeCreatorName(p);
            wrlCreators += TypeConvertor::GetWRLTypeCreatorName(p);
        }

        convertor += "<" + tp + ", " + objCCreators + ", " + wrlCreators + ">";
        return convertor;
    } else if (ClangHelpers::isInterface(typeInfo->getTypeSpelling())) {
        auto ifaceInfo = g_globalData.interfaceMap.find(Helpers::Trim(Helpers::baseType(typeInfo->getTypeSpelling())));
        if (ifaceInfo == g_globalData.interfaceMap.end()) {
            Helpers::Errors::WriteError(nullptr, "Interface definition not found", false);
        }
        return ClangHelpers::generateNamespaceString(ifaceInfo->second->getSDKName(), "::") + "::" + "_Get" + g_winrtClassPrefix +
               Helpers::Trim(Helpers::baseType(typeInfo->getTypeSpelling())) + "ForObjC";
    } else if (typeInfo->isHeterogeneous) {
        std::string convertor;
        auto it = g_globalData.currentComponent->getHeterogeneousContainerInfo(typeInfo);
        return ClangHelpers::generateResolvedTypeName(it->second->toWRLConvertor, g_globalData.currentComponent->getSDKName(), false, "");
    }

    return "dummyWRLCreator";
}

string GetObjCTypeCreatorName(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo) {
    if (typeInfo->isHeterogeneous) {
        auto it = g_globalData.currentComponent->getHeterogeneousContainerInfo(typeInfo);
        return it->second->toObjCConvertor;
    } else if (typeInfo->isContainer()) {
        return g_globalData.currentComponent->SDKHeaderFile + _GetObjCTypeCreatorName(typeInfo) + "_create";
    } else if (ClangHelpers::isInterface(typeInfo->getTypeSpelling())) {
        auto ifaceInfo = g_globalData.interfaceMap.find(Helpers::Trim(Helpers::baseType(typeInfo->getTypeSpelling())));
        if (ifaceInfo == g_globalData.interfaceMap.end()) {
            Helpers::Errors::WriteError(nullptr, "Interface definition not found", false);
        }

        return ClangHelpers::generateNamespaceString(ifaceInfo->second->getSDKName(), "::") + "::" + "_GetObjCFor" + g_winrtClassPrefix +
               Helpers::Trim(Helpers::baseType(typeInfo->getTypeSpelling()));
    }

    return "dummyObjCCreator";
}

bool isGeneric(const std::string& typeSpelling, size_t* firstIdx, size_t* lastIdx) {
    size_t idx1 = typeSpelling.find_first_of('<');

    if (idx1 == typeSpelling.npos) {
        return false;
    }

    size_t idx2 = typeSpelling.find_last_of('>');
    if (idx2 == typeSpelling.npos) {
        std::string err = "Invalid argument: " + typeSpelling;
        Helpers::Errors::WriteError(nullptr, err.c_str(), false);
    }

    if (firstIdx) {
        *firstIdx = idx1;
    }

    if (lastIdx) {
        *lastIdx = idx2;
    }

    return true;
}
}