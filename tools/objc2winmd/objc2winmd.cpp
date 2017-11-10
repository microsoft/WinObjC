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
#include <clang-c/Index.h>
#include <iostream>

CXChildVisitResult ASTVisitor(CXCursor cursor, CXCursor parent, CXClientData client_data);
CXChildVisitResult IsForwardDeclarationVisitor(CXCursor cursor, CXCursor parent, CXClientData client_data);
void HandleClassRef(CXCursor cursor, std::shared_ptr<ClangObjectModel::ComponentInfo>& component);
void HandleProtocolRef(CXCursor cursor, std::shared_ptr<ClangObjectModel::ComponentInfo>& component);

extern "C" unsigned int g_MaxErrors = 1;
extern "C" const std::string g_winrtClassPrefix = "RT";
ClangHelpers::SDKParameters g_sdkParameters;
ClangObjectModel::GlobalData g_globalData;
extern "C" const string g_commonConvertors = "CommonConvertors";
extern "C" const string g_NSDateConvertor = "NSDateConvertor";
extern "C" const string g_NSURLConvertor = "NSURLConvertor";
extern "C" const string g_notificationCenter = "NotificationCenter";
extern "C" const std::string g_copyrightNotice =
    "//******************************************************************************\n"
    "//\n"
    "// Copyright (c) Microsoft Corporation. All rights reserved.\n"
    "//\n"
    "// This code is licensed under the MIT License (MIT).\n"
    "//\n"
    "// THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n"
    "// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n"
    "// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n"
    "// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n"
    "// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n"
    "// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN\n"
    "// THE SOFTWARE.\n"
    "//\n"
    "//******************************************************************************\n\n";

std::string getFullContainerName(std::string name) {
    return "Windows.Foundation.Collections." + name;
}

std::string generateRTFactoryName(const std::shared_ptr<ClangObjectModel::InterfaceInfo> iface) {
    std::string rtFactoryName = g_winrtClassPrefix + iface->name;
    if (iface->isActivatableStaticOnlyFactory()) {
        rtFactoryName += "Statics";
    } else {
        rtFactoryName += "Factory";
    }
    return rtFactoryName;
}

std::string generateFactoryMethodName(const std::string& objCSelectorName) {
    std::vector<std::string> tokens;
    Helpers::splitString(objCSelectorName, tokens, ":");
    std::string ret;

    for (auto s : tokens) {
        if (ret.size() > 0) {
            ret += "_";
        }

        ret += s;
    }

    return "CreateInstance_" + ret;
}

//
// These functions work on objective c types and do conversions:
//

std::string generateDelegateParamList(const std::vector<std::shared_ptr<ClangObjectModel::TypeInfo>>& delegateParams,
                                      bool includeIdlDecorations = true) {
    std::string paramList;

    if (delegateParams.size() > 0) {
        paramList =
            Helpers::addSeparators(delegateParams,
                                   [&](const std::shared_ptr<ClangObjectModel::TypeInfo> t) {
                                       std::string typeName;
                                       if (includeIdlDecorations) {
                                           if (t->hasBaseWinRTRepresentation()) {
                                               typeName = TypeConvertor::WinrtType(t, true, true);
                                           } else {
                                               typeName = TypeConvertor::WinrtType(t, false, true);
                                               if (ClangHelpers::isInterface(t->getTypeSpelling())) {
                                                   typeName = ClangHelpers::generateResolvedTypeName(typeName, t->getSDKName(), true);
                                               }
                                           }
                                       } else {
                                           // This needs to stay objective C type.
                                           // This is the input argument to the wrapper block which gets passed to objective C land.
                                           // (The wrapper block internally calls into the user provided closure/lambda)
                                           if (t->isHeterogeneous) {
                                               auto it =
                                                   g_globalData.currentComponent->heterogeneousContainers.find(t->getTypeSpelling(true));
                                               typeName = it->second->objCContainerName;
                                           } else {
                                               typeName = t->getTypeSpelling();
                                           }
                                           if (t->isContainer()) {
                                               typeName += "*";
                                           }
                                       }

                                       typeName += " ";
                                       std::string parameter = typeName + t->getTypeName();
                                       if (includeIdlDecorations) {
                                           parameter = t->annotation + " " + parameter;
                                       }
                                       return parameter;
                                   },
                                   ", ");
    }

    return paramList;
}

// We're expecting our type to be coming in as a winRT type and we want to map into ObjC to
// call down to the library implementation:
std::string marshalToObjC(const std::shared_ptr<ClangObjectModel::ParameterInfo> paramInfo) {
    if (paramInfo->typeInfo->typeKind == CXType_BlockPointer) {
        string delegateParamNameListForWinRT = ClangHelpers::getDelegateParamNameListForWinRT(paramInfo);
        std::string blockType = "^(" + generateDelegateParamList(paramInfo->delegateParams, false) + ")";
        if (paramInfo->marshallDelegateAsAsync) {
            if (paramInfo->asyncInfo->returnTypes.size() < 2) {
                return blockType + " { spAsyncWorker->setResult(" + delegateParamNameListForWinRT + ");}";
            } else {
                string resolvedImplName =
                    ClangHelpers::generateResolvedTypeName(paramInfo->asyncInfo->implName, paramInfo->asyncInfo->sdkName, false, "");
                string localVarName = "_" + paramInfo->asyncInfo->implName;
                return blockType + " { spAsyncWorker->setResult(^" + resolvedImplName + "*() {ComPtr<" + resolvedImplName + "> " +
                       localVarName + " = Make<" + resolvedImplName + ">(); (" + localVarName + ".Get())->Init(" +
                       delegateParamNameListForWinRT + "); return " + localVarName + ".Detach();}());}";
            }
        } else {
            string comPtrType = ClangHelpers::generateDelegateName(paramInfo->delegateParams);
            comPtrType = ClangHelpers::generateResolvedTypeName("I" + comPtrType, paramInfo->typeInfo->getSDKName(), false);
            string comPtrName = "_" + paramInfo->typeInfo->getTypeName();
            return blockType + " { " + "ComPtr<" + comPtrType + "> " + comPtrName + "; " + comPtrName + ".Attach(" +
                   paramInfo->typeInfo->getTypeName() + "); " + "THROW_NS_IF_FAILED(" + comPtrName + "->Invoke(" +
                   delegateParamNameListForWinRT + ")); }";
        }
    }

    if (paramInfo->typeInfo->isContainer()) {
        return TypeConvertor::GetObjCTypeCreatorName(paramInfo->typeInfo) + "(" + paramInfo->typeInfo->getTypeName() + ")";
    }

    if (paramInfo->typeInfo->getTypeSpelling() == "NSString*" || paramInfo->typeInfo->getTypeSpelling() == "NSString *") {
        return "hstrToNSStr(" + paramInfo->typeInfo->getTypeName() + ")";
    }

    if (paramInfo->typeInfo->isNSDateType()) {
        return g_commonConvertors + "::convertWinRTToNSDate(" + paramInfo->typeInfo->getTypeName() + ")";
    }

    if (paramInfo->typeInfo->isNSURLType()) {
        return g_commonConvertors + "::convertWinRT" + paramInfo->typeInfo->getTypeSpelling(true) + "ToNSURL(" +
               paramInfo->typeInfo->getTypeName() + ")";
    }

    if (paramInfo->typeInfo->getSymbolKind() == ClangObjectModel::JSONType) {
        return g_commonConvertors + "::convertPropertySetToNSDictionary(" + paramInfo->typeInfo->getTypeName() + ")";
    }

    if (ClangHelpers::isInterface(paramInfo->typeInfo->getTypeSpelling())) {
        // we have an interface

        // TODO: Find a better way to do this.
        // Casting an interface to the runtime class is unsafe, but we are well aware that we just have one instantiation of the interface.
        // Also, this hack works because getInnerObject is non-virtual.
        std::string resolvedType =
            ClangHelpers::generateResolvedTypeName(g_winrtClassPrefix + TypeConvertor::WinrtType(paramInfo->typeInfo, true),
                                                   paramInfo->typeInfo->getSDKName(),
                                                   false,
                                                   "");
        return "((" + resolvedType + "*)" + paramInfo->typeInfo->getTypeName() + ")->getInnerObject()";
    }

    // Do not change this order, every delegateCallbackProtocol is a protocol but not the other way around.
    if (ClangHelpers::isDelegateCallbackProtocol(paramInfo->typeInfo->getTypeSpelling())) {
        return "[[" + Helpers::Trim(Helpers::baseType(paramInfo->typeInfo->getTypeSpelling(), true)) + " alloc] initWith:" +
               paramInfo->typeInfo->getTypeName() + "]";
    } else if (ClangHelpers::isProtocol(paramInfo->typeInfo->getTypeSpelling())) {
        return "dynamic_cast<GetInnerObject*>(" + paramInfo->typeInfo->getTypeName() + ")->getInnerObject()";
    }

    if (paramInfo->typeInfo->typeKind == CXType_Enum) {
        return "(" + paramInfo->typeInfo->getTypeSpelling() + ")" + paramInfo->typeInfo->getTypeName();
    }

    return paramInfo->typeInfo->getTypeName();
}

std::string marshalWinRTToObjcInLocalVar(const std::shared_ptr<ClangObjectModel::ParameterInfo> paramInfo) {
    return "id " + paramInfo->typeInfo->generateObjcLocalVarName() + " = " + marshalToObjC(paramInfo);
}

string getParamList(std::vector<shared_ptr<ClangObjectModel::ParameterInfo>>& params, bool generateForIDL) {
    return Helpers::addSeparators(
        params,
        [&](const std::shared_ptr<ClangObjectModel::ParameterInfo> p) {
            std::string parameter;
            if (p->typeInfo->typeKind == CXType_BlockPointer) {
                parameter = ClangHelpers::generateDelegateName(p->delegateParams) + "* " + p->typeInfo->getTypeName();
                string prefix = (generateForIDL ? "" : "I");
                parameter = ClangHelpers::generateResolvedTypeName(prefix + parameter, p->typeInfo->getSDKName(), generateForIDL);
            } else {
                parameter = TypeConvertor::WinrtType(p->typeInfo, p->typeInfo->hasBaseWinRTRepresentation(), generateForIDL);

                if (ClangHelpers::isInterface(p->typeInfo->getTypeSpelling()) || ClangHelpers::isProtocol(p->typeInfo->getTypeSpelling())) {
                    parameter = ClangHelpers::generateResolvedTypeName("I" + parameter, p->typeInfo->getSDKName(), generateForIDL);
                }
                parameter += " " + p->typeInfo->getTypeName();
            }

            if (generateForIDL) {
                parameter = p->typeInfo->annotation + " " + parameter;
            }
            return parameter;
        },
        ", ",
        [&](auto val) {
            bool fGenerateParam = true;
            if (val->typeInfo->typeKind == CXType_BlockPointer && val->marshallDelegateAsAsync) {
                fGenerateParam = false;
            }
            return fGenerateParam;
        });
}

std::string generateParamList(const std::shared_ptr<ClangObjectModel::MethodInfo> method,
                              bool generateForIDL,
                              bool generateReturnType = true,
                              bool generateForFactory = false) {
    // The first parameter is the name:
    std::string paramList;

    if (method->params.size() > 0) {
        paramList = getParamList(method->params, generateForIDL);
    }

    // Generate return param:
    std::string asyncReturnParam;
    if (method->isAsync) {
        string resolvedImplNameForIDL;
        string resolvedImplNameForRuntime;
        std::shared_ptr<ClangObjectModel::TypeInfo> retType;
        for (const auto& p : method->params) {
            if (p->marshallDelegateAsAsync) {
                if (generateForIDL) {
                    resolvedImplNameForIDL = ClangHelpers::getResolvedAsyncImplName(p->asyncInfo, "", true);
                    if (!resolvedImplNameForIDL.empty()) {
                        asyncReturnParam =
                            "[out] [retval] Windows.Foundation.IAsyncOperation<" + resolvedImplNameForIDL + ">** __returnValue";
                    } else {
                        asyncReturnParam = "[out] [retval] Windows.Foundation.IAsyncAction** __returnValue";
                    }
                } else {
                    resolvedImplNameForRuntime = ClangHelpers::getResolvedAsyncImplName(p->asyncInfo, "", false);
                    if (!resolvedImplNameForRuntime.empty()) {
                        asyncReturnParam = "ABI::Windows::Foundation::IAsyncOperation<" + resolvedImplNameForRuntime + ">** __returnValue";
                    } else {
                        asyncReturnParam = "ABI::Windows::Foundation::IAsyncAction** __returnValue";
                    }
                }
                break;
            }
        }
    }

    string returnParam;
    if (generateReturnType) {
        if (!asyncReturnParam.empty()) {
            method->returnType->typeInfo->setTypeName("__originalReturnValue");
            method->returnType->typeInfo->annotation = "[out]";
        }
        string returnVar = method->returnType->typeInfo->getTypeName();

        std::string prefix = generateForFactory ? "" : "I";
        if (method->returnType->typeInfo->typeKind != CXType_Void) {
            returnParam = TypeConvertor::WinrtType(method->returnType->typeInfo,
                                                   method->returnType->typeInfo->hasBaseWinRTRepresentation(),
                                                   generateForIDL);
            if (ClangHelpers::isInterface(method->returnType->typeInfo->getTypeSpelling()) ||
                ClangHelpers::isProtocol(method->returnType->typeInfo->getTypeSpelling())) {
                returnParam = ClangHelpers::generateResolvedTypeName(prefix + returnParam,
                                                                     method->returnType->typeInfo->getSDKName(),
                                                                     generateForIDL);
            }
            returnParam += "* " + returnVar;

            if (generateForIDL) {
                returnParam = method->returnType->typeInfo->annotation + " " + returnParam;
            }

            if (!asyncReturnParam.empty()) {
                returnParam = returnParam + ", " + asyncReturnParam;
            }
        }
    }

    if (returnParam.empty()) {
        returnParam = asyncReturnParam;
    }

    if (paramList.size() && returnParam.size()) {
        paramList += ", " + returnParam;
    } else if (returnParam.size()) {
        paramList = returnParam;
    }

    return paramList;
}

std::string generateEnums(const std::shared_ptr<ClangObjectModel::TypeInfo>& typeInfo) {
    stringstream ss;

    ss << "[version(1.0)]" << std::endl;
    ss << "[v1_enum]" << std::endl;
    ss << "enum " << typeInfo->getTypeSpelling() << "{" << std::endl;
    std::string enumConstantDecl = "";
    for (auto item : typeInfo->enumConstants) {
        if (!enumConstantDecl.empty()) {
            enumConstantDecl += ",\n";
        }

        enumConstantDecl += "    " + item.first + " = " + std::to_string(item.second);
    }

    ss << enumConstantDecl << std::endl << "};" << std::endl;

    return ss.str();
}

std::string generateInterfaceIdl(const std::string& IDLInterfaceName,
                                 const std::string& prefix,
                                 const std::string& suffix,
                                 const std::vector<std::shared_ptr<ClangObjectModel::MethodInfo>>& methods,
                                 bool isInitMethod = false) {
    stringstream ss;

    ss << Helpers::annotate("uuid", Helpers::newUuid());
    ss << Helpers::annotate("version", "1.0");
    ss << "interface " << prefix << IDLInterfaceName << suffix << " : IInspectable {" << std::endl;

    for (const auto& method : methods) {
        std::string methodName;
        if (isInitMethod) {
            methodName = generateFactoryMethodName(method->objectiveCSelector);
        } else {
            methodName = method->getMethodNameForIdl();
        }

        ss << "    " << method->idlAnnotation << "HRESULT " << methodName << "(" << generateParamList(method, true, true, isInitMethod)
           << ");" << std::endl;
    }

    ss << "}" << std::endl << std::endl;

    return ss.str();
}

std::string generateInterfaceForAsyncClassIdl(const std::string& IDLInterfaceName,
                                              const std::string& prefix,
                                              const std::vector<std::shared_ptr<ClangObjectModel::MethodInfo>>& methods) {
    stringstream ss;

    ss << Helpers::annotate("uuid", Helpers::newUuid());
    ss << Helpers::annotate("version", "1.0");
    ss << "interface " << prefix << IDLInterfaceName << " : IInspectable {" << std::endl;

    for (const auto& method : methods) {
        std::string methodName = method->getMethodNameForIdl();
        ss << "    " << method->idlAnnotation << "HRESULT " << methodName << "(" << generateParamList(method, true, true, false) << ");"
           << std::endl;
    }

    ss << "}" << std::endl << std::endl;

    return ss.str();
}

std::string generateAsyncClassIdl(const std::shared_ptr<ClangObjectModel::InterfaceInfo> iface) {
    stringstream ss;

    ss << generateInterfaceForAsyncClassIdl(iface->name, "I", iface->instanceMethods);

    // Now generate the runtime class:
    ss << "[marshaling_behavior(agile)]" << std::endl;
    ss << "[threading(both)]" << std::endl;
    ss << Helpers::annotate("version", "1.0");
    ss << "runtimeclass " << iface->GetIdlRuntimeClassName() << " {" << std::endl;
    string fullyQualifiedName = ClangHelpers::generateResolvedTypeName("I" + iface->name, iface->getSDKName(), true);
    ss << "    [default] interface " << fullyQualifiedName << ";" << std::endl;
    ss << "}" << std::endl << std::endl;

    return ss.str();
}

std::string generateClassIdl(const std::shared_ptr<ClangObjectModel::InterfaceInfo> iface) {
    stringstream ss;

    ss << generateInterfaceIdl(iface->name, "I", "", iface->instanceMethods, false);

    if (iface->parameterizedInitMethods.size() > 0) {
        ss << generateInterfaceIdl(iface->name, "I", "Factory", iface->parameterizedInitMethods, true);
    }

    if (iface->classMethods.size() > 0) {
        ss << generateInterfaceIdl(iface->name, "I", "Statics", iface->classMethods);
    }

    // Now generate the runtime class:
    // Note: The following is required by anything that subclasses windows.ui.xaml.controls.contentcontrol
    // However, it is "good practice" to put on all runtimeclasses even though it doesn't effect runtime behaviour.
    ss << "[marshaling_behavior(agile)]" << std::endl;
    ss << "[threading(both)]" << std::endl;

    if (iface->hasDefaultInitializer) {
        ss << Helpers::annotate("activatable", "1.0");
    }

    if (iface->parameterizedInitMethods.size() > 0) {
        ss << Helpers::annotate("activatable", "I" + iface->name + "Factory, 1.0");
    }

    if (iface->classMethods.size() > 0) {
        ss << Helpers::annotate("static", "I" + iface->name + "Statics, 1.0");
    }

    string composableRuntimeClass;
    // If the interface derives from a UIElement (something in objCSuperClasses), we create a composable class that
    // derives from Xaml.Controls.ContentControl instead of implementing an IUIElement WinRT Interface.
    std::shared_ptr<ClangObjectModel::InterfaceInfo> uiElementInterface = iface->GetUIElementBaseClass();
    if (uiElementInterface != nullptr) {
        composableRuntimeClass = " : " + uiElementInterface->GetIdlRuntimeClassName();
    }

    ss << Helpers::annotate("version", "1.0");
    ss << "runtimeclass " << iface->GetIdlRuntimeClassName() << composableRuntimeClass << " {" << std::endl;

    std::shared_ptr<ClangObjectModel::InterfaceInfo> interfaceIter = iface;

    while (interfaceIter != nullptr && interfaceIter != uiElementInterface) {
        string defaultInterface = (iface->name == interfaceIter->name ? "[default] " : "");
        string fullyQualifiedName = ClangHelpers::generateResolvedTypeName("I" + interfaceIter->name, interfaceIter->getSDKName(), true);
        ss << "    " << defaultInterface << "interface " << fullyQualifiedName << ";" << std::endl;

        for (const auto& protocol : interfaceIter->getProtocolsImplemented()) {
            fullyQualifiedName = ClangHelpers::generateResolvedTypeName("I" + protocol->name, protocol->getSDKName(), true);
            ss << "    interface " << fullyQualifiedName << ";" << std::endl;
        }

        interfaceIter = interfaceIter->GetBaseClass();
    }

    ss << "}" << std::endl << std::endl;

    return ss.str();
}

std::string generateClassIdl(const std::shared_ptr<ClangObjectModel::ProtocolInfo> protocol) {
    stringstream ss;
    ss << generateInterfaceIdl(protocol->name, "I", "", protocol->instanceMethods, false);
    return ss.str();
}

void dumpFile(const std::string& name, const std::string& data, const std::string& path) {
    std::string outputFile = path + "\\" + name;
    FILE* f;
    // TODO: include wil macros.
    errno_t err = fopen_s(&f, outputFile.c_str(), "w");
    if (err != 0) {
        printf("Failed to open output file %s", outputFile.c_str());
        exit(-1);
    }
    fwrite(data.c_str(), 1, data.size(), f);
    fclose(f);
}

std::string generateDelegateIdl(const std::shared_ptr<ClangObjectModel::DelegateInfo> delegateInfo) {
    stringstream ss;

    ss << Helpers::annotate("uuid", Helpers::newUuid());
    ss << Helpers::annotate("version", "1.0");
    ss << "delegate" << std::endl;
    ss << "HRESULT " << delegateInfo->name << "(" + generateDelegateParamList(delegateInfo->params) + ");" << std::endl;
    return ss.str();
}

std::string generateIAsyncOperationSpecialization() {
    stringstream ss;
    for (const auto& asyncClass : g_globalData.currentComponent->asyncClasses) {
        if (asyncClass->returnTypes.size() != 0) {
            if (ClangHelpers::isInterface(asyncClass->implName)) {
                ss << "declare {" << std::endl;
                ss << "    interface Windows.Foundation.IAsyncOperation<" << Helpers::baseType(asyncClass->implName) << "*>;" << std::endl;
                ss << "}" << std::endl;
            }
        }
    }

    return ss.str();
}

std::string generateAppDelegateDecl() {
    stringstream ss;

    ss << "#import <Foundation/Foundation.h>\n";
    ss << "#import <UIKit/UIKit.h>\n\n";
    ss << "@interface _" << g_globalData.applicationDelegateInfo->ifaceInfo->name << " : NSObject<UIApplicationDelegate>\n";
    ss << "@end\n";

    return ss.str();
}

std::string generateObjCSelectorSignature(const std::shared_ptr<ClangObjectModel::MethodInfo> methodInfo) {
    std::string signature = methodInfo->objectiveCSignature;
    size_t pos = signature.find(';');
    if (pos != signature.npos) {
        signature = signature.substr(0, pos);
    }
    return Helpers::replace(signature, ";", "");
}

std::string generateAppDelegateCreator() {
    std::string appDelegateCreator;
    if (g_globalData.applicationDelegateInfo->allocatorMethod == nullptr &&
        g_globalData.applicationDelegateInfo->initializerMethod == nullptr) {
        // use [[interface alloc] init]
        appDelegateCreator = "[[" + g_globalData.applicationDelegateInfo->ifaceInfo->name + " alloc] init]";
    } else if (g_globalData.applicationDelegateInfo->allocatorMethod != nullptr &&
               g_globalData.applicationDelegateInfo->initializerMethod != nullptr) {
        if (g_globalData.applicationDelegateInfo->allocatorMethod != g_globalData.applicationDelegateInfo->initializerMethod) {
            // use [[interface allocatorMethod] initializerMethod]
            appDelegateCreator = "[[" + g_globalData.applicationDelegateInfo->ifaceInfo->name + " " +
                                 g_globalData.applicationDelegateInfo->allocatorMethod->name + "] " +
                                 g_globalData.applicationDelegateInfo->initializerMethod->name + "]";
        } else {
            appDelegateCreator = "[" + g_globalData.applicationDelegateInfo->ifaceInfo->name + " " +
                                 g_globalData.applicationDelegateInfo->allocatorMethod->name + "]";
        }

    } else if (g_globalData.applicationDelegateInfo->allocatorMethod != nullptr) {
        // use [[interface allocatorMethod] init]
        appDelegateCreator = "[[" + g_globalData.applicationDelegateInfo->ifaceInfo->name + " " +
                             g_globalData.applicationDelegateInfo->allocatorMethod->name + "] init]";
    } else {
        // use [[interface alloc] initializerMethod]
        appDelegateCreator = "[[" + g_globalData.applicationDelegateInfo->ifaceInfo->name + " alloc] " +
                             g_globalData.applicationDelegateInfo->initializerMethod->name + "]";
    }

    return appDelegateCreator;
}

std::string generateMsgSendUsingLocals(const std::shared_ptr<ClangObjectModel::MethodInfo> method) {
    if (method->params.size() == 0) {
        return method->name;
    }

    std::string msgSend;

    // get the method selectors.
    std::vector<std::string> tokens;
    tokenize(method->objectiveCSelector, tokens, ":", "", "\"", "", "\\", false, true);
    assert(tokens.size() == method->params.size());

    // Generate msg send.
    for (unsigned int i = 0; i < method->params.size(); i++) {
        std::string value = method->params[i]->typeInfo->generateObjcLocalVarName();

        if (i > 0) {
            msgSend += " ";
        }
        msgSend += tokens[i] + ":" + value;
    }

    return msgSend;
}

std::string generateMsgSend(const std::shared_ptr<ClangObjectModel::MethodInfo> method, bool pureObjC = false) {
    if (method->params.size() == 0) {
        return method->name;
    }

    std::string msgSend;

    // get the method selectors.
    std::vector<std::string> tokens;
    tokenize(method->objectiveCSelector, tokens, ":", "", "\"", "", "\\", false, true);
    assert(tokens.size() == method->params.size());

    for (unsigned int i = 0; i < method->params.size(); i++) {
        std::string value = pureObjC ? method->params[i]->typeInfo->getTypeName() : marshalToObjC(method->params[i]);

        if (i > 0) {
            msgSend += " ";
        }
        msgSend += tokens[i] + ":" + value;
    }

    return msgSend;
}

std::string generateObjCSelectorCall(const std::shared_ptr<ClangObjectModel::MethodInfo> methodInfo) {
    stringstream ss;
    ss << "[" << generateAppDelegateCreator() << " " << generateMsgSend(methodInfo, true) << "];";
    return ss.str();
}

std::string generateAppDelegateMethodImpl() {
    stringstream ss;

    for (const auto methodInfo : g_globalData.applicationDelegateInfo->ifaceInfo->instanceMethods) {
        // Generate signature
        ss << generateObjCSelectorSignature(methodInfo) << " {\n";
        ss << "    return " << generateObjCSelectorCall(methodInfo) << "\n";
        ss << "}\n\n";
    }

    for (const auto methodInfo : g_globalData.applicationDelegateInfo->ifaceInfo->classMethods) {
        // Generate signature
        ss << generateObjCSelectorSignature(methodInfo) << "{\n";
        ss << "    return " << generateObjCSelectorCall(methodInfo) << "\n";
        ss << "}\n\n";
    }

    return ss.str();
}

std::string generateAppDelegateImpl() {
    stringstream ss;
    ss << "#import <" << g_globalData.applicationDelegateInfo->ifaceInfo->getSDKName() << "/"
       << g_globalData.applicationDelegateInfo->ifaceInfo->SDKHeaderFile << ".h>" << endl;
    ss << "#import \"" << g_sdkParameters.rootNameSpace << "_" << g_globalData.applicationDelegateInfo->ifaceInfo->name << ".h\"" << endl
       << endl;
    ss << "@implementation _" << g_globalData.applicationDelegateInfo->ifaceInfo->name << "\n\n";
    ss << generateAppDelegateMethodImpl();
    ss << "@end\n";

    return ss.str();
}

std::string generateIdl(const std::shared_ptr<ClangObjectModel::ComponentInfo> component) {
    stringstream ss;

    for (const auto& dep : ClangObjectModel::GlobalData::defaultDependentIdls) {
        ss << "import \"" << dep << "\";" << std::endl;
    }

    for (auto& iface : component->ifaces) {
        if (iface.second->DerivesFromUIElement()) {
            ss << "import \"" << iface.second->GetUIElementBaseClass()->GetIdlFileName() << "\";" << std::endl;
            break;
        }
    }

    std::string additionalIncludes;
    for (const auto& ref : component->referencedIDLs) {
        if (ClangObjectModel::GlobalData::defaultDependentIdls.find(ref) != ClangObjectModel::GlobalData::defaultDependentIdls.end()) {
            continue;
        }

        ss << "import \"" << ref << "\";" << std::endl;
        std::string header = ref.substr(0, ref.rfind(".idl"));
        std::string headerNameInclude = "#include \\\"" + header + ".h\\\"";

        // Forward declaration in headers get transformed to import in IDL.
        // So our IDLs are not immune to cyclic dependencies. The problem we encounter because of this is:
        // If there are three files a.idl, b.idl and c.idl such that:
        // a.idl has:
        // import "b.idl";
        // import "c.idl";
        //
        // b.idl has:
        // import "a.idl";
        // import "c.idl";
        //
        // We see that the generated a.h and b.h files do not contain any include reference for c.h.
        // This causes undefined symbol errors.
        // To solve this, we use cpp_quote to include the headers.
        // This has a benign effect of duplicate header inclusion in the generated .h file.
        // But the headers have #pragma once and so this is harmless.
        additionalIncludes += "cpp_quote(\"" + headerNameInclude + "\")\n";
    }

    ss << std::endl;

    // Additional imports to ensure that all required headers are included
    if (!additionalIncludes.empty()) {
        ss << additionalIncludes << std::endl;
    }

    ss << "namespace " << ClangHelpers::generateNamespaceString(component->getSDKName(), ".") << " {" << std::endl << std::endl;

    for (const auto& ref : component->referencedInterfaces) {
        // The format of referencedInterfaces is:
        // "SDKName.HeaderFileName.InterfaceName"
        std::string name;
        size_t pos1 = ref.find_last_of(".");
        size_t pos2 = ref.find_last_of(".", pos1 - 1);
        // Everything after pos1 is the name of the interface:
        name = ref.substr(pos1 + 1, ref.length() - pos1 - 1);
        ss << "interface " << ref.substr(0, pos2 + 1) + "I" + name << ";" << std::endl;
        ss << "runtimeclass " << name << ";" << std::endl;
    }

    for (const auto& ref : component->referencedProtocols) {
        // The format of referencedProtocols is:
        // "SDKName.HeaderFileName.ProtocolName"
        std::string name;
        size_t pos1 = ref.find_last_of(".");
        size_t pos2 = ref.find_last_of(".", pos1 - 1);
        // Everything after pos1 is the name of the interface:
        name = ref.substr(pos1 + 1, ref.length() - pos1 - 1);
        ss << "interface " << ref.substr(0, pos2 + 1) + "I" + name << ";" << std::endl;
    }

    // forward declarations
    for (const auto& ifaceMap : component->ifaces) {
        auto iface = ifaceMap.second;
        ss << "interface I" << iface->name << ";" << std::endl;
        ss << "runtimeclass " << iface->GetIdlRuntimeClassName() << ";" << std::endl;
        if (iface->parameterizedInitMethods.size() > 0) {
            ss << "interface I" << iface->name << "Factory;" << std::endl;
        }
        if (iface->classMethods.size() > 0) {
            ss << "interface I" << iface->name << "Statics;" << std::endl;
        }
    }

    for (const auto& protocolMap : component->protocols) {
        auto protocol = protocolMap.second;
        ss << "interface I" << protocol->name << ";" << std::endl;
    }

    ss << std::endl;

    // Generate component level Enums
    for (const auto enumItem : component->enums) {
        ss << generateEnums(enumItem.second) << std::endl;
    }

    // Generate delegate declarations.
    for (const auto delMap : component->delegates) {
        ss << generateDelegateIdl(delMap.second) << std::endl;
    }

    for (const auto& asyncClass : component->asyncClasses) {
        if (asyncClass->synthesizedInterface != nullptr) {
            ss << generateAsyncClassIdl(asyncClass->synthesizedInterface);
        }
    }

    // Specialize IAsyncOperation for generated runtime classes only
    ss << generateIAsyncOperationSpecialization() << std::endl;

    for (const auto& protocolMap : component->protocols) {
        ss << generateClassIdl(protocolMap.second);
    }

    for (const auto& ifaceMap : component->ifaces) {
        ss << generateClassIdl(ifaceMap.second);
    }

    ss << "}" << std::endl << std::endl;

    return ss.str();
}

std::string generateFactoryMethodBody(const std::shared_ptr<ClangObjectModel::MethodInfo> methodInfo,
                                      const std::shared_ptr<ClangObjectModel::InterfaceInfo> iface,
                                      const std::string paramName) {
    stringstream ss;

    ss << "        *" << paramName << " = Make<" << ClangHelpers::generateNamespaceString(iface->getSDKName(), "::")
       << "::" << g_winrtClassPrefix << iface->name << ">(";
    std::string argNameList;
    for (const auto& param : methodInfo->params) {
        if (argNameList.size() > 0) {
            argNameList.append(", ");
        }

        argNameList.append(param->typeInfo->getTypeName());
    }
    ss << argNameList << ").Detach();" << std::endl;
    ss << "        return *" << paramName << " != nullptr ? S_OK : E_OUTOFMEMORY;" << std::endl;
    return ss.str();
}

std::string generateABIBoundaryStart() {
    std::stringstream ss;
    ss << "    return ExceptionBoundary([&]() {" << endl;
    return ss.str();
}

std::string generateABIBoundaryEnd() {
    std::stringstream ss;
    ss << "    });" << endl;
    return ss.str();
}

std::string generateClassFactory(const std::shared_ptr<ClangObjectModel::InterfaceInfo> iface) {
    stringstream ss;

    auto classNameStr = "RuntimeClass_" + ClangHelpers::generateNamespaceString(iface->getSDKName(), "_") + "_" + iface->name;

    // The class factory:
    std::string factoryName = generateRTFactoryName(iface);

    std::string interfaceNames = "";

    if (iface->classMethods.size() > 0) {
        interfaceNames += ClangHelpers::generateResolvedTypeName("I" + iface->name + "Statics", iface->getSDKName());
    }
    if (iface->parameterizedInitMethods.size() > 0) {
        if (interfaceNames.size() > 0) {
            interfaceNames += ", ";
        }
        interfaceNames += ClangHelpers::generateResolvedTypeName("I" + iface->name + "Factory", iface->getSDKName());
    }

    ss << "class " << factoryName << " : public ActivationFactory<" << interfaceNames << "> {" << std::endl;

    // Add the comment for the hack to correctly expose Nil as a class type instead of a nullptr.
    ss << std::endl;
    if (iface->parameterizedInitMethods.size() != 0 || iface->classMethods.size() != 0) {
        ss << "// Runtime.h defines Nil as ((Class)_OBJC_NULL_PTR), which results in an error for InspectableClassStatic" << std::endl;
        ss << "// which expects Nil as a CPP class. If Nil is undefined, the push and pop below are NOP." << std::endl;
        ss << "#pragma push_macro(\"Nil\")" << std::endl;
        ss << "#undef Nil" << std::endl;
        ss << "    InspectableClassStatic(" << classNameStr << ", BaseTrust)" << std::endl;
        ss << "#pragma pop_macro(\"Nil\")" << std::endl;
    }
    ss << std::endl << "public:" << std::endl;

    ss << "    " << factoryName << "() {" << std::endl;
    ss << "    }" << std::endl << std::endl;

    std::string paramName = iface->name;

    if (iface->hasDefaultInitializer) {
        // default constructor:
        std::string runtimeClass = ClangHelpers::generateResolvedTypeName(g_winrtClassPrefix + Helpers::baseType(iface->name, true),
                                                                          iface->getSDKName(),
                                                                          false,
                                                                          "");
        std::string ABIInterface =
            ClangHelpers::generateResolvedTypeName("I" + Helpers::baseType(iface->name, true), iface->getSDKName(), false);

        std::transform(paramName.begin(), paramName.end(), paramName.begin(), ::tolower);
        ss << "    STDMETHODIMP ActivateInstance(IInspectable** " << paramName << ") override {" << std::endl;
        ss << generateABIBoundaryStart();
        ss << ClangHelpers::generateCallToIslandWoodInit();
        ss << "        return MakeAndInitialize<" << runtimeClass << ">(" << paramName << ");" << endl;
        ss << generateABIBoundaryEnd();
        ss << "    }" << std::endl;

        ss << std::endl;
    }

    // parameterized constructors
    for (const auto& method : iface->parameterizedInitMethods) {
        ss << "    STDMETHODIMP " << generateFactoryMethodName(method->objectiveCSelector) << "(" << generateParamList(method, false, false)
           << ", " << ClangHelpers::generateResolvedTypeName("I" + iface->name, iface->getSDKName()) << "** " << paramName << ") override {"
           << std::endl;
        ss << generateABIBoundaryStart();
        ss << ClangHelpers::generateCallToIslandWoodInit();
        ss << generateFactoryMethodBody(method, iface, paramName);
        ss << generateABIBoundaryEnd();
        ss << "    }" << std::endl;
    }

    for (const auto& method : iface->classMethods) {
        ss << "    STDMETHODIMP " << method->getMethodNameForRuntimeClass() << "(" << generateParamList(method, false) << ") override {"
           << std::endl;

        bool usesDelegateProtocols = false;
        for (unsigned int i = 0; i < method->params.size(); i++) {
            auto it = iface->usedDelegateTypes.find(method->params[i]->typeInfo->getTypeSpelling());
            if (it != iface->usedDelegateTypes.end()) {
                usesDelegateProtocols = true;
                break;
            }
        }

        // code to initialize local vars, if any.
        std::stringstream localVarsCode;

        // code to save vars, if any.
        std::stringstream saveVarsCode;

        // code to set the return variable.
        std::string returnVarCode;

        if (usesDelegateProtocols) {
            if (!method->returnType->typeInfo->isInterface()) {
                Helpers::Errors::WriteError(nullptr, "Marshalling delegates is not supported.", false);
            } else {
                std::vector<std::shared_ptr<ClangObjectModel::TypeInfo>> localVarsToSave;
                for (unsigned int i = 0; i < method->params.size(); i++) {
                    auto it = iface->usedDelegateTypes.find(method->params[i]->typeInfo->getTypeSpelling());
                    if (it != iface->usedDelegateTypes.end()) {
                        localVarsToSave.push_back(method->params[i]->typeInfo);
                    }
                    // Code for marshalling an objective-C type to local var..
                    localVarsCode << "         " + marshalWinRTToObjcInLocalVar(method->params[i]) << ";" << endl;
                }
                string callStr = "[" + iface->name + " " + generateMsgSendUsingLocals(method) + "]";

                // TODO: Make this more robust and avoid name collisions.
                string tempVar = "_temp";
                localVarsCode << "        auto " << tempVar << " = "
                              << TypeConvertor::getWRLConvertorFuncForType(method->returnType->typeInfo, callStr) + ";" << endl;
                if (!localVarsToSave.empty()) {
                    for (const auto& typeInfo : localVarsToSave) {
                        saveVarsCode << tempVar + "->" + typeInfo->generateMemberVarName() + " = " + typeInfo->generateObjcLocalVarName()
                                     << ";" << endl;
                    }
                }
                returnVarCode = "        *" + method->returnType->typeInfo->getTypeName() + " = " + tempVar + ";";
            }

        } else if (method->returnType->typeInfo->typeKind != CXType_Void) {
            string callStr = "[" + iface->name + " " + generateMsgSend(method) + "]";
            returnVarCode = "*" + method->returnType->typeInfo->getTypeName() + " = ";
            returnVarCode = returnVarCode + TypeConvertor::getWRLConvertorFuncForType(method->returnType->typeInfo, callStr) + ";";
        } else {
            string callStr = "[" + iface->name + " " + generateMsgSend(method) + "]";
            returnVarCode = callStr + ";";
        }

        ss << generateABIBoundaryStart();
        ss << ClangHelpers::generateCallToIslandWoodInit();
        ss << localVarsCode.str() << std::endl;
        ss << saveVarsCode.str() << std::endl;
        ss << "        " << returnVarCode << std::endl;
        ss << "        return S_OK;" << std::endl;
        ss << generateABIBoundaryEnd();
        ss << "    }" << std::endl;
    }

    ss << "};" << std::endl;

    return ss.str();
}

string generateAsyncClassInitMethod(const shared_ptr<ClangObjectModel::AsyncClassInfo>& asyncInfo) {
    stringstream ss;

    string paramsString = Helpers::addSeparators(asyncInfo->returnTypes, [&](const std::shared_ptr<ClangObjectModel::TypeInfo> t) {
        std::string parameter;
        if (t->typeKind == CXType_BlockPointer) {
            Helpers::Errors::WriteError(nullptr, "Block within another block is not yet supported", false);
        } else {
            parameter = TypeConvertor::WinrtType(t, t->hasBaseWinRTRepresentation());

            if (ClangHelpers::isInterface(t->getTypeSpelling()) || ClangHelpers::isProtocol(t->getTypeSpelling())) {
                parameter = ClangHelpers::generateResolvedTypeName("I" + parameter, t->getSDKName());
            }
            parameter += " " + t->getTypeName();
        }

        return parameter;
    });

    ss << "    public:" << endl;
    ss << "    void Init(" << paramsString << ") {" << endl;
    for (auto item : asyncInfo->returnTypes) {
        if (item->isComType()) {
            ss << "        "
               << "_" << ClangHelpers::getSynthesizedAsyncClassPropertyName(item) << ".Attach(" << item->getTypeName() << ");" << endl;
        } else {
            ss << "        "
               << "_" << ClangHelpers::getSynthesizedAsyncClassPropertyName(item) << " = " << item->getTypeName() << ";" << endl;
        }
    }
    ss << "    }" << endl;
    ss << endl;
    return ss.str();
}

string generateAsyncClassInstanceMethod(shared_ptr<ClangObjectModel::MethodInfo> method) {
    stringstream ss;

    ss << "    STDMETHODIMP " << method->getMethodNameForRuntimeClass() << "(" << generateParamList(method, false) << ") override {"
       << std::endl;
    // getter method.
    if (method->returnType->typeInfo->isComType()) {
        string varName = "_" + ClangHelpers::getSynthesizedAsyncClassPropertyName(method->returnType->typeInfo);
        ss << "        auto comPtr" << varName << " = " << varName << ";" << endl;
        ss << "        *" << method->returnType->typeInfo->getTypeName() << " = comPtr" << varName << ".Detach();" << endl;
    } else {
        ss << "        *" << method->returnType->typeInfo->getTypeName() << " = _"
           << ClangHelpers::getSynthesizedAsyncClassPropertyName(method->returnType->typeInfo) << ";" << endl;
    }
    ss << "        return S_OK;" << endl;
    ss << "    }" << endl;
    ss << endl;
    return ss.str();
}

std::string generateInstanceMethod(const std::string classNamePrefix, std::shared_ptr<ClangObjectModel::MethodInfo> method) {
    std::stringstream ss;

    ss << "STDMETHODIMP " << classNamePrefix << method->getMethodNameForRuntimeClass() << "(" << generateParamList(method, false) << ") {"
       << std::endl;
    ss << generateABIBoundaryStart();

    // Run through all its parameters, for any delegate type we need to increment its reference count as ObjC blocks do not
    // capture non-ObjC types. This count will be decremented after the delegate is invoked.
    for (auto param : method->params) {
        if (param->delegateParams.size() && !param->marshallDelegateAsAsync) {
            // This is a delegate parameter.
            string comPtrType = ClangHelpers::generateDelegateName(param->delegateParams);
            comPtrType = ClangHelpers::generateResolvedTypeName("I" + comPtrType, param->typeInfo->getSDKName(), false);
            string comPtrName = "comPtr_" + param->typeInfo->getTypeName();
            ss << "    // This is a workaround for clang bug wherein non-objC types are not captured by ObjC blocks." << endl;
            ss << "    // The incremented ref count will be decremented when we actually invoke the input delegate" << endl;
            ss << "    ComPtr<" << comPtrType << "> " << comPtrName << " = " << param->typeInfo->getTypeName() << ";" << endl;
            ss << "    " << comPtrName << ".Detach();" << endl;
        }
    }
    std::string returnInfo;
    if (method->returnType->typeInfo->typeKind != CXType_Void) {
        returnInfo = "*" + method->returnType->typeInfo->getTypeName() + " = ";
    }

    std::string objCCall = "";
    if (!method->isAsync) {
        std::string callString = "[_obj " + generateMsgSend(method) + "]";
        objCCall = TypeConvertor::getWRLConvertorFuncForType(method->returnType->typeInfo, callString);
        if (!objCCall.empty()) {
            ss << "    " << returnInfo << objCCall << ";" << std::endl;
            ss << "    return S_OK;" << std::endl;
        } else {
            ss << "    return E_NOTIMPL;" << std::endl;
        }
    } else {
        std::shared_ptr<ClangObjectModel::AsyncClassInfo> asyncInfo;
        for (const auto& p : method->params) {
            if (p->marshallDelegateAsAsync) {
                asyncInfo = p->asyncInfo;
                break;
            }
        }

        if (asyncInfo == nullptr) {
            Helpers::Errors::WriteError(nullptr, "No async info found", false);
        }

        ss << "    *__returnValue = nullptr;" << std::endl;
        ss << "    ComPtr<" << asyncInfo->name.c_str() << "> spAsyncWorker = Make<" << asyncInfo->name.c_str() << ">();" << std::endl;
        string callString = "[_obj " + generateMsgSend(method) + "]";
        if (returnInfo.empty()) {
            ss << "    " << callString << ";" << endl;
        } else {
            string objCCall = TypeConvertor::getWRLConvertorFuncForType(method->returnType->typeInfo, callString);
            ss << "    " << returnInfo << objCCall << ";" << endl;
        }
        ss << "    *__returnValue = spAsyncWorker.Detach();" << std::endl;
        ss << "    return S_OK;" << std::endl;
    }
    ss << generateABIBoundaryEnd();
    ss << "}" << std::endl;
    return ss.str();
}

std::string generateClass(const std::shared_ptr<ClangObjectModel::InterfaceInfo> iface) {
    stringstream ss;

    std::string classNamePrefix = g_winrtClassPrefix + iface->name + "::";

    if (iface->hasDefaultInitializer) {
        // default constructor:
        ss << classNamePrefix << g_winrtClassPrefix << iface->name << "() {" << std::endl;
        ss << "    _obj = [[" << iface->name << " alloc] init];" << std::endl;
        ss << "}" << std::endl;
    }

    // default make:
    ss << classNamePrefix << g_winrtClassPrefix << iface->name << "(" << iface->name << "* obj) {" << std::endl;
    ss << "    _obj = [obj retain];" << std::endl;
    ss << "}" << std::endl;

    // default destructor
    ss << classNamePrefix << "~" << g_winrtClassPrefix << iface->name << "() {" << std::endl;
    ss << "    [_obj release];" << std::endl;
    for (const auto& typeInfo : iface->usedDelegateTypes) {
        ss << "    [" << typeInfo.second->generateMemberVarName() << " release];" << std::endl;
    }
    ss << "}" << std::endl;

    // default accessor for inner object
    ss << "id " << classNamePrefix << "getInnerObject() {" << std::endl;
    ss << "    return _obj;" << std::endl;
    ss << "}" << std::endl;

    // parameterized constructors if any:
    if (iface->parameterizedInitMethods.size() > 0) {
        for (const auto& method : iface->parameterizedInitMethods) {
            ss << classNamePrefix << g_winrtClassPrefix << iface->name << "(" << generateParamList(method, false, false) << ") {"
               << std::endl;
            ss << "    _obj = [[" << iface->name << " alloc] " << generateMsgSend(method) << "];" << std::endl;
            ss << "}" << std::endl;
        }
    }

    // For composable objects RuntimeClassInitialize is where we create the composable COM object.
    if (iface->DerivesFromUIElement()) {
        // NOTE: The following is very specific to UI elements which all will derive from Windows.UI.Xaml.Controls.ContentControl;
        ss << "STDMETHODIMP " << classNamePrefix << "RuntimeClassInitialize() {" << std::endl;
        ss << "    ComPtr<ABI::Windows::UI::Xaml::Controls::IContentControlFactory> baseFactory;" << std::endl;
        ss << "    ComPtr<IInspectable> inner;" << std::endl;
        ss << "    ComPtr<IInspectable> thisInspectable;" << endl;
        ss << "    ComPtr<ABI::Windows::UI::Xaml::Controls::IContentControl> instance;" << std::endl;
        ss << "    "
              "RETURN_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HStringReference(RuntimeClass_Windows_UI_Xaml_Controls_"
              "ContentControl).Get(), &baseFactory));"
           << std::endl;
        ss << "    RETURN_IF_FAILED(QueryInterface(IID_PPV_ARGS(&thisInspectable)));" << endl;
        ss << "    RETURN_IF_FAILED(baseFactory->CreateInstance(thisInspectable.Get(), &inner, &instance));" << endl;
        ss << "    RETURN_IF_FAILED(SetComposableBasePointers(inner.Get(), nullptr));" << std::endl;
        ss << "    auto xamlComObj = [[_obj xamlElement] comObj];" << std::endl;

        ss << "    // Anchor point in WinRT is (0,0) whereas, in ObjC it is (0.5, 0.5)." << endl;
        ss << "    // This results in UI elements being rendered at wrong place." << endl;
        ss << "    // We call setAnchorPoint on the UI element to fix this." << endl;
        ss << "    [_obj.layer setAnchorPoint:CGPointMake(0,0)];" << endl;

        ss << "    RETURN_IF_FAILED(instance->put_Content(xamlComObj.Get()));" << std::endl;

        ss << "    //Save a WeakRef of the Com object with the objective-c object." << endl;
        ss << "    WeakRef _weakRef;" << endl;
        ss << "    Microsoft::WRL::AsWeak(this, &_weakRef);" << endl;
        ss << "    WeakRefWrapper* _weakRefWrapper = [[[WeakRefWrapper alloc] init] autorelease];" << endl;
        ss << "    _weakRefWrapper.weakRefComObj = _weakRef;" << endl;
        ss << "    [_obj setWeakRefWrapper : _weakRefWrapper];" << endl;

        ss << "    return S_OK;" << std::endl;
        ss << "}" << std::endl;
    }

    std::shared_ptr<ClangObjectModel::InterfaceInfo> interfaceIter = iface;
    while (interfaceIter != nullptr) {
        ss << "// " << ClangHelpers::generateResolvedTypeName("I" + interfaceIter->name, interfaceIter->getSDKName()) << std::endl;
        for (const auto& method : interfaceIter->instanceMethods) {
            ss << generateInstanceMethod(classNamePrefix, method);
        }

        for (const auto& protocol : interfaceIter->getProtocolsImplemented()) {
            ss << "// " << ClangHelpers::generateResolvedTypeName("I" + protocol->name, protocol->getSDKName()) << std::endl;
            for (const auto& method : protocol->instanceMethods) {
                ss << generateInstanceMethod(classNamePrefix, method);
            }
        }

        interfaceIter = interfaceIter->GetBaseClass();
    }

    ss << std::endl;
    ss << generateClassFactory(iface) << std::endl;

    std::string factoryName = generateRTFactoryName(iface);
    if (iface->isActivatableStaticOnlyFactory()) {
        // Just some class methods without any constructors
        ss << "ActivatableStaticOnlyFactory(" << factoryName << ")" << std::endl;
    } else {
        ss << "ActivatableClassWithFactory(" << g_winrtClassPrefix << iface->name << ", " << factoryName << ")" << std::endl;
    }

    return ss.str();
}

std::string generateObjCCreatorFunctions(
    const std::unordered_map<std::string, std::shared_ptr<ClangObjectModel::TypeInfo>>& creatorFuncMap) {
    stringstream ss;
    stringstream forwardDeclareStream;

    for (auto ifaceInfo : g_globalData.currentComponent->ifaces) {
        std::string rtName = g_winrtClassPrefix + ifaceInfo.first;
        ss << "id _GetObjCFor" << rtName << "(IInspectable* val) {\n";
        ss << "    " << rtName << "* _cls = reinterpret_cast<" << rtName << "*>(val);\n";
        ss << "    return _cls->getInnerObject();\n";
        ss << "}\n\n";

        std::string runtimeClass = ClangHelpers::generateResolvedTypeName(g_winrtClassPrefix + Helpers::baseType(ifaceInfo.first, true),
                                                                          ifaceInfo.second->getSDKName(),
                                                                          false,
                                                                          "");
        std::string ABIInterface =
            ClangHelpers::generateResolvedTypeName("I" + Helpers::baseType(ifaceInfo.first, true), ifaceInfo.second->getSDKName(), false);

        ss << "ComPtr<IInspectable> _Get" << rtName << "ForObjC(id obj) {\n";
        // NOTE: We need to cast the runtime class to an interface before casting to IInspectable.
        // All Winrt interfaces derive from IInspectable.  When a runtime class implements/subclasses 2 or more interfaces, we have a
        // diamond problem as both interfaces
        // derive from IInspectable.
        ss << "    ComPtr<" << ABIInterface << "> temp = Make<" + runtimeClass + ">(obj);" << std::endl;
        ss << "    return temp;" << std::endl;
        ss << "}\n\n";
    }

    for (const auto& creatorFunc : creatorFuncMap) {
        std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo = creatorFunc.second;
        const TypeConvertor::ContainerTypeInfo* ci = TypeConvertor::GetContainerInfo(typeInfo->getTypeSpelling());
        if (ci) {
            // forward declare the creator methods.
            forwardDeclareStream << "id " << creatorFunc.first << "(IInspectable* val);" << std::endl;

            ss << "id " << creatorFunc.first << "(IInspectable* val) {" << std::endl;
            TypeConvertor::ToObjCTypeConvertor* convertor = ci->toObjCConvertor;
            if (convertor) {
                ss << convertor->instantiator(typeInfo) << std::endl;
            }
            ss << "}" << std::endl << std::endl;
        } else {
            throw std::invalid_argument("Creator functions are to be used only for containers");
        }
    }

    return forwardDeclareStream.str() + "\n" + ss.str();
}

std::string generateHeterogeneousContainerDeclarations(const std::shared_ptr<ClangObjectModel::ComponentInfo>& component) {
    stringstream ss;
    ss << g_copyrightNotice;
    ss << "#pragma once" << std::endl << std::endl;
    ss << "#import <UWP/ObjCHelpers.h>" << std::endl;

    // Generate the declaration for ObjC creator and the interface definition for the heterogeneous container types.
    ss << ContainerTemplates::generateObjCWrapperDeclaration(component) << endl << endl;
    ss << ContainerTemplates::generateRTWrapperDeclaration(component) << endl;

    return ss.str();
}

std::string generateHeaders(const std::shared_ptr<ClangObjectModel::InterfaceInfo>& iface) {
    stringstream ss;
    ss << g_copyrightNotice;
    ss << "#pragma once" << std::endl << std::endl;

    // ComIncludes are required as the generated headers require 'interface' as a type declaration.
    ss << "#include <ComIncludes.h>" << std::endl;
    ss << "#include \"" << ClangHelpers::generateNamespaceString(g_globalData.currentComponent->getSDKName(), ".") << "."
       << g_globalData.currentComponent->SDKHeaderFile << ".h\"" << std::endl;
    ss << "#include <ComIncludes_End.h>" << std::endl;
    ss << "#import <" << iface->getSDKName() << "/" << g_globalData.currentComponent->SDKHeaderFile << ".h>" << std::endl << std::endl;

    ss << "#include \"" << g_sdkParameters.rootNameSpace << ".h\"" << std::endl;

    std::string namespaceName = ClangHelpers::generateNamespaceString(g_globalData.currentComponent->getSDKName(), "{\nnamespace ");

    ss << "namespace " << namespaceName << " {" << std::endl;

    // dump all forward declarations
    std::string decl = "";
    for (auto ifaceMap : g_globalData.currentComponent->ifaces) {
        if (ifaceMap.first == iface->name) {
            continue;
        }

        decl = g_winrtClassPrefix + ifaceMap.first;
        ss << "class " << decl << ";" << std::endl;
    }

    auto classNameStr =
        "RuntimeClass_" + ClangHelpers::generateNamespaceString(g_globalData.currentComponent->getSDKName(), "_") + "_" + iface->name;

    // forward declare the ObjC Creator function for this interface.
    ss << "id _GetObjCFor" << g_winrtClassPrefix << iface->name << "(IInspectable* val);\n";

    // forward declare the WRL Creator function for this interface.
    ss << "ComPtr<IInspectable> _Get" << g_winrtClassPrefix << iface->name << "ForObjC(id obj);\n\n";

    string implementedInterfaces;
    std::shared_ptr<ClangObjectModel::InterfaceInfo> interfaceIter = iface;
    while (interfaceIter != nullptr && (g_globalData.objCSuperClasses.find(interfaceIter->name) == g_globalData.objCSuperClasses.end())) {
        implementedInterfaces += (implementedInterfaces.empty() ? "" : ", ") +
                                 ClangHelpers::generateResolvedTypeName("I" + interfaceIter->name, interfaceIter->getSDKName());

        for (const auto& protocol : interfaceIter->getProtocolsImplemented()) {
            implementedInterfaces += ", " + ClangHelpers::generateResolvedTypeName("I" + protocol->name, protocol->getSDKName());
        }

        interfaceIter = interfaceIter->GetBaseClass();
    }

    // The class:
    ss << "class " << g_winrtClassPrefix << iface->name << " : public RuntimeClass<" << implementedInterfaces
       << (iface->DerivesFromUIElement() ? ", ComposableBase<>" : "") << ">, public GetInnerObject {" << std::endl;
    ss << "    " << iface->name << "* _obj;" << std::endl;

    ss << "    InspectableClass(" << classNameStr << ", BaseTrust)" << std::endl;

    ss << "public:" << std::endl;

    for (const auto& typeInfo : iface->usedDelegateTypes) {
        ss << "    id " << typeInfo.second->generateMemberVarName() << ";" << std::endl;
    }

    if (iface->hasDefaultInitializer) {
        // default constructor:
        ss << "    " << g_winrtClassPrefix << iface->name << "();" << std::endl;
    }

    // default make: This is used for marshalling the objC instance,
    // by creating the runtime class instance from Objective C instance.
    ss << "    " << g_winrtClassPrefix << iface->name << "(" << iface->name << "* obj);" << std::endl;

    // default destructor
    ss << "    ~" << g_winrtClassPrefix << iface->name << "();" << std::endl;

    // default accessor for inner object
    ss << "    id getInnerObject() override;" << std::endl;

    if (iface->DerivesFromUIElement()) {
        ss << "    STDMETHODIMP RuntimeClassInitialize();" << std::endl;
    }

    // parameterized constructors if any:
    if (iface->parameterizedInitMethods.size() > 0) {
        for (const auto& method : iface->parameterizedInitMethods) {
            ss << "    " << g_winrtClassPrefix << iface->name << "(" << generateParamList(method, false, false) << ");" << std::endl;
        }
    }

    interfaceIter = iface;
    while (interfaceIter != nullptr) {
        ss << "    // " << ClangHelpers::generateResolvedTypeName("I" + interfaceIter->name, interfaceIter->getSDKName()) << std::endl;
        for (const auto& method : interfaceIter->instanceMethods) {
            ss << "    STDMETHODIMP " << method->getMethodNameForRuntimeClass() << "(" << generateParamList(method, false) << ") override;"
               << std::endl;
        }

        for (const auto& protocol : interfaceIter->getProtocolsImplemented()) {
            ss << "    // " << ClangHelpers::generateResolvedTypeName("I" + protocol->name, protocol->getSDKName()) << std::endl;
            for (const auto& method : protocol->instanceMethods) {
                ss << "    STDMETHODIMP " << method->getMethodNameForRuntimeClass() << "(" << generateParamList(method, false)
                   << ") override;" << std::endl;
            }
        }

        interfaceIter = interfaceIter->GetBaseClass();
    }

    ss << "};" << std::endl;
    ss << "}" << std::endl;

    // Add as many closing bracket as there are opening brackets in namespaceName
    int count = std::count(namespaceName.begin(), namespaceName.end(), '{');

    for (int i = 0; i < count; i++) {
        ss << "}" << std::endl;
    }
    return ss.str();
}

string generateObjCDelegateCallbackDeclaration(shared_ptr<ClangObjectModel::ProtocolInfo> delegateCallback) {
    stringstream ss;

    ss << "#import <Foundation/Foundation.h>" << endl;
    ss << "#import <" << delegateCallback->getSDKName() << "/" << delegateCallback->SDKHeaderFile << ".h>" << endl;
    ss << endl;
    string resolvedName = ClangHelpers::generateResolvedTypeName("I" + delegateCallback->name, delegateCallback->getSDKName());
    ss << "@interface " << delegateCallback->name << " : NSObject<" << delegateCallback->name << "> {" << endl;
    ss << "    ComPtr<" << resolvedName << "> comObj;" << endl;
    ss << "}" << endl;
    ss << "- (instancetype)initWith:(ComPtr<" << resolvedName << ">)obj;" << endl;
    ss << "- (ComPtr<" << resolvedName << ">)getInternalComObj;" << endl;
    ss << "@end" << endl;
    ss << endl;

    return ss.str();
}

string generateObjCDelegateCallbackDefinitions() {
    stringstream ss;

    for (auto delMap : g_globalData.currentComponent->delegateCallbackProtocolsMap) {
        string resolvedName = ClangHelpers::generateResolvedTypeName("I" + delMap.first, g_globalData.currentComponent->getSDKName());
        ss << "@implementation " << delMap.first << endl;
        ss << "- (instancetype)initWith:(ComPtr<" << resolvedName << ">)obj {" << endl;
        ss << "    if (self = [super init]) {" << endl;
        ss << "        comObj = obj;" << endl;
        ss << "    }" << endl;
        ss << "    return self;" << endl;
        ss << "}" << endl;
        ss << endl;
        ss << "- (ComPtr<" << resolvedName << ">)getInternalComObj {" << endl;
        ss << "    return comObj;" << endl;
        ss << "}" << endl;
        ss << endl;

        for (auto instMethod : delMap.second->instanceMethods) {
            string objCMethodSignature = instMethod->objectiveCSignature;
            size_t pos = objCMethodSignature.find(";");
            objCMethodSignature = objCMethodSignature.substr(0, pos);
            string returnValue = "";
            string returnParam = "";
            bool hasReturnType = (instMethod->returnType->typeInfo->typeKind != CXType_Void);

            ss << objCMethodSignature << " {" << endl;
            if (hasReturnType) {
                returnValue = "__winRTReturnValue";
                returnParam = ", &" + returnValue;
                ss << "    " << TypeConvertor::WinrtType(instMethod->returnType->typeInfo) << " " << returnValue << ";" << endl;
            }
            vector<string> parameters;

            string parameterList;
            for (unsigned int i = 0; i < instMethod->params.size(); i++) {
                const auto& param = instMethod->params[i];

                // Get a WRL object for the objective-c object and assign it to a temp.
                string temp = "__" + param->typeInfo->getTypeName();
                ss << "    auto " << temp << " = "
                   << TypeConvertor::getWRLConvertorFuncForType(param->typeInfo, param->typeInfo->getTypeName()) << ";" << endl;

                bool paramDerivesFromUIElement = false;
                string paramTypeName = param->typeInfo->getTypeSpelling(true);
                auto paramIface = g_globalData.interfaceMap.find(paramTypeName);
                if (paramIface != g_globalData.interfaceMap.end() && paramIface->second->DerivesFromUIElement()) {
                    paramDerivesFromUIElement = true;
                }

                // Build up the parameter list for the callback.
                parameterList += temp;
                if (paramDerivesFromUIElement) {
                    parameterList += ".Get()";
                }
                if (i < instMethod->params.size() - 1) {
                    parameterList += ", ";
                }
            }

            ss << "    comObj->" << instMethod->getMethodNameForRuntimeClass() << "(" << parameterList << returnParam << ");" << endl;

            if (hasReturnType) {
                instMethod->returnType->typeInfo->setTypeName(returnValue);
                ss << "    return " << marshalToObjC(instMethod->returnType) << ";" << endl;
            }

            ss << "}" << endl;
            ss << endl;
        }

        ss << "@end" << endl;
    }
    return ss.str();
}

// Generate the ObjC++ code that acts as the implementation of the runtime classes:
std::string generateClassBindings(const std::shared_ptr<ClangObjectModel::ComponentInfo> component) {
    stringstream ss;

    ss << g_copyrightNotice;

    ss << "#include <ComIncludes.h>" << std::endl;
    ss << "#include \"" << ClangHelpers::generateNamespaceString(component->getSDKName(), ".") << "." << component->SDKHeaderFile << ".h\""
       << std::endl;
    ss << "#include <windows.foundation.h>" << std::endl;
    ss << "#include <wrl.h>" << std::endl;
    ss << "#include <wrl/implements.h>" << std::endl;
    ss << "#include <wrl/async.h>" << std::endl;
    ss << "#include <wrl/module.h>" << std::endl;
    ss << "#include <ComIncludes_End.h>" << std::endl << std::endl;

    ss << "#import <UWP/ObjCHelpers.h>" << std::endl;
    ss << "#include \"" << g_sdkParameters.rootNameSpace << ".h\"" << std::endl;
    ss << "#import <" << component->getSDKName() << "/" << component->SDKHeaderFile << ".h>" << std::endl << std::endl;
    ss << "#include <Winstring.h>" << endl;

    set<string> headerNames;
    for (auto iface : component->ifaces) {
        std::string headerName =
            ClangHelpers::generateNamespaceString(component->getSDKName(), ".") + "." + component->SDKHeaderFile + "." + iface.first + ".h";
        headerNames.insert(headerName);
    }

    for (auto ifaceName : component->referencedInterfaces) {
        std::string headerName = ifaceName + ".h";
        headerNames.insert(headerName);
    }

    for (auto protocolName : component->referencedProtocols) {
        // We need to include the header of the interface which implements this protocol.
        // The format of referencedProtocols is:
        // "SDKName.HeaderFileName.ProtocolName"
        size_t pos1 = protocolName.find_last_of(".");
        size_t pos2 = protocolName.find_last_of(".", pos1 - 1);
        // Everything after pos1 is the name of the interface:
        protocolName = protocolName.substr(pos1 + 1, protocolName.length() - pos1 - 1);
        auto iface = ClangHelpers::getInterfaceImplementingProtocol(protocolName);
        string headerName;
        if (iface == nullptr) {
            // This is a delegate callback protocol.
            auto it = g_globalData.delegateCallbackProtocolsMap.find(protocolName);
            if (it == g_globalData.delegateCallbackProtocolsMap.end() || it->second->implHeaderName.empty()) {
                Helpers::Errors::WriteError(nullptr, "No marshalling code for delegate callback protocol" + protocolName, false);
            }
            headerName = it->second->implHeaderName;
        } else {
            headerName =
                ClangHelpers::generateNamespaceString(iface->getSDKName(), ".") + "." + iface->SDKHeaderFile + "." + iface->name + ".h";
        }
        headerNames.insert(headerName);
    }

    for (auto delegatePair : component->delegateCallbackProtocolsMap) {
        if (delegatePair.second->implHeaderName.empty()) {
            Helpers::Errors::WriteError(nullptr, "No marshalling code for delegate callback protocol" + delegatePair.first, false);
        }

        headerNames.insert(delegatePair.second->implHeaderName);
    }

    // Even the headers corresponding to referenced IDLs need to be included.
    for (auto ref : component->referencedIDLs) {
        if (ClangObjectModel::GlobalData::defaultDependentIdls.find(ref) != ClangObjectModel::GlobalData::defaultDependentIdls.end()) {
            continue;
        }
        string header = ref.substr(0, ref.rfind(".idl")) + ".h";
        headerNames.insert(header);
    }

    for (auto headerName : headerNames) {
        ss << "#import \"" << headerName << "\"" << std::endl;
    }

    if (component->heterogeneousContainers.size()) {
        std::string namespaceString = ClangHelpers::generateNamespaceString(component->getSDKName(), ".");
        ss << "#import \"" << namespaceString + "." + component->SDKHeaderFile + "._Containers.h\"\n";
    }

    ss << std::endl;

    ss << "using Microsoft::WRL::ActivationFactory;" << std::endl;
    ss << "using Microsoft::WRL::Make;" << std::endl;
    ss << "using Microsoft::WRL::RuntimeClass;" << std::endl;
    ss << std::endl;

    for (const auto& ifaceMap : component->ifaces) {
        if (ifaceMap.second->DerivesFromUIElement()) {
            auto iface = ifaceMap.second;
            ss << "@interface " << iface->name << "(ComObj)" << endl;
            ss << "    @property (nonatomic, retain) WeakRefWrapper* weakRefWrapper;" << endl;
            ss << "@end" << endl;
            ss << endl;
            ss << "@implementation " << iface->name << "(ComObj)" << endl;
            ss << "    - (void)setWeakRefWrapper:(WeakRefWrapper*)object { " << endl;
            ss << "        objc_setAssociatedObject(self, @selector(weakRefWrapper), object, OBJC_ASSOCIATION_RETAIN_NONATOMIC); " << endl;
            ss << "    }" << endl;
            ss << "    -(WeakRefWrapper*)weakRefWrapper { " << endl;
            ss << "        return objc_getAssociatedObject(self, @selector(weakRefWrapper));" << endl;
            ss << "    }" << endl;
            ss << "@end" << endl;
        }
    }

    if (g_globalData.currentComponent->delegateCallbackProtocolsMap.size()) {
        ss << generateObjCDelegateCallbackDefinitions() << endl;
    }

    ss << "namespace " << ClangHelpers::generateNamespaceString(component->getSDKName(), "{\nnamespace ") << " {" << std::endl;

    // forward declare any class factories we may be using
    for (const auto& ifaceMap : component->ifaces) {
        auto iface = ifaceMap.second;
        if (iface->classMethods.size() == 0 && iface->parameterizedInitMethods.size() == 0) {
            continue;
        }

        std::string name = generateRTFactoryName(ifaceMap.second);
        ss << "class " << name << ";" << std::endl;
    }

    ss << std::endl;

    // Generate our ObjC creator functions.
    std::unordered_map<std::string, std::shared_ptr<ClangObjectModel::TypeInfo>> objCCreatorFuncs = component->getObjcCreatorFuncs();
    ss << generateObjCCreatorFunctions(objCCreatorFuncs);

    // Generate our heterogeneous container type creators.
    ss << ContainerTemplates::generateHeterogeneousCreators(g_globalData.currentComponent);

    for (const auto& asyncClass : g_globalData.currentComponent->asyncClasses) {
        std::string asyncClassName = asyncClass->name;

        // Todo: there has to be a better way to do this.
        if (asyncClass->synthesizedInterface != nullptr) {
            auto synthesizedIface = asyncClass->synthesizedInterface;
            string className = synthesizedIface->GetWinrtClassName();
            string resolvedInterfaceName = ClangHelpers::generateResolvedTypeName("I" + className, synthesizedIface->getSDKName());
            ss << "class " << className << " : public RuntimeClass<" << resolvedInterfaceName << "> {" << endl;

            // generate the private member variables for the aggregated types.
            for (auto item : asyncClass->returnTypes) {
                string typeName = TypeConvertor::WinrtType(item, item->hasBaseWinRTRepresentation());
                if (item->isInterface()) {
                    typeName = ClangHelpers::generateResolvedTypeName("I" + typeName, item->getSDKName());
                }

                if (item->isComType()) {
                    typeName = "ComPtr<" + Helpers::baseType(typeName, true) + ">";
                }
                ss << "    " << typeName << " _" << ClangHelpers::getSynthesizedAsyncClassPropertyName(item) << ";" << endl;
            }
            ss << "    InspectableClass(L\"Windows.Foundation.IAsyncOperation<" << resolvedInterfaceName << "*>\", BaseTrust); "
               << std::endl;

            for (auto method : synthesizedIface->instanceMethods) {
                ss << generateAsyncClassInstanceMethod(method);
            }

            ss << generateAsyncClassInitMethod(asyncClass);

            ss << "};" << endl;
            ss << endl;
        } else {
            ss << "class " << asyncClassName << " : " << std::endl;
            ss << "    public RuntimeClass<" << std::endl;
            ss << "    IAsyncAction," << std::endl;
            ss << "    AsyncBase<IAsyncActionCompletedHandler>> {" << std::endl;
            ss << "        InspectableClass(InterfaceName_Windows_Foundation_IAsyncAction, BaseTrust);" << std::endl;
            ss << "public:" << std::endl;
            ss << "    " << asyncClassName << "()" << std::endl;
            ss << "    {" << std::endl;
            ss << "        Start();" << std::endl;
            ss << "    }" << std::endl;
            ss << "    IFACEMETHODIMP put_Completed(IAsyncActionCompletedHandler *pCompleteHandler) override" << std::endl;
            ss << "    {" << std::endl;
            ss << "        return AsyncBase::PutOnComplete(pCompleteHandler);" << std::endl;
            ss << "    }" << std::endl;
            ss << "    IFACEMETHODIMP get_Completed(IAsyncActionCompletedHandler **ppCompleteHandler) override" << std::endl;
            ss << "    {" << std::endl;
            ss << "        return AsyncBase::GetOnComplete(ppCompleteHandler);" << std::endl;
            ss << "    }" << std::endl;
            ss << "    void setResult()" << std::endl;
            ss << "    {" << std::endl;
            ss << "        FireCompletion();" << std::endl;
            ss << "    }" << std::endl;
            ss << "    IFACEMETHODIMP GetResults() override" << std::endl;
            ss << "    {" << std::endl;
            ss << "        return AsyncBase::CheckValidStateForResultsCall();" << std::endl;
            ss << "    }" << std::endl;
            ss << "    HRESULT OnStart() override" << std::endl;
            ss << "    {" << std::endl;
            ss << "        return S_OK;" << std::endl;
            ss << "    }" << std::endl;
            ss << "    void OnClose() override {}" << std::endl;
            ss << "    void OnCancel() override {}" << std::endl;
            ss << "};" << std::endl;
            ss << std::endl;
        }
    }

    for (const auto& ifaceMap : component->ifaces) {
        auto iface = ifaceMap.second;
        ss << generateClass(iface) << std::endl;
    }

    ss << ContainerTemplates::generateObjCMarshallingMethods(component);
    ss << ContainerTemplates::generateRTMarshallingMethods(component);
    ss << ContainerTemplates::generateRTWrapperDefinitions(component);

    ss << "}" << std::endl << "}" << std::endl;

    ss << ContainerTemplates::generateObjCWrapperDefinition(component);

    return ss.str();
}

bool isOutParameter(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo) {
    bool outParam = false;
    switch (typeInfo->typeKind) {
        case CXType_Pointer:
            outParam = true;
            break;
        case CXType_ObjCObjectPointer:
            outParam = false;
            break;
    }

    return outParam;
}

std::string generateAnnotations(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo) {
    std::string typeSpelling = typeInfo->getTypeSpelling();
    std::string annotation;

    if (isOutParameter(typeInfo)) {
        annotation = "[out]";
    } else {
        annotation = "[in]";
    }

    return annotation;
}

CXChildVisitResult DelegateVisitor(CXCursor cursor, CXCursor parent, CXClientData client_data) {
    std::shared_ptr<ClangObjectModel::ParameterInfo> param = *((std::shared_ptr<ClangObjectModel::ParameterInfo>*)client_data);
    CXCursorKind kind = clang_getCursorKind(cursor);
    std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo;

    switch (kind) {
        case CXCursor_ParmDecl:
            // These are the delegate parameters.
            typeInfo = make_shared<ClangObjectModel::TypeInfo>();
            typeInfo->setTypeName(ClangHelpers::GetCursorSpelling(cursor));
            typeInfo->setTypeSpelling(ClangHelpers::GetCursorTypeSpelling(cursor));

            if (typeInfo->getTypeName() == "") {
                typeInfo->setTypeName("d" + std::to_string(param->delegateParams.size()));
            }
            typeInfo->cursor = cursor;
            typeInfo->SDKname = ClangHelpers::GetCursorSDKName(cursor);
            typeInfo->typeKind = clang_getCursorType(cursor).kind;
            typeInfo->annotation = generateAnnotations(typeInfo);
            if (typeInfo->getTypeSpelling(true) == "NSURL") {
                if (!param->paramMetaData->blockParameterHasMetaData(param->delegateParams.size())) {
                    param->paramMetaData->appendMetaData(ClangObjectModel::MetaDataType_BlockParameter,
                                                         -1,
                                                         param->delegateParams.size(),
                                                         vector<string>({ "StorageFile", "Uri" }));
                }
            }
            param->delegateParams.push_back(std::move(typeInfo));
            break;
    }

    return CXChildVisit_Continue;
}

CXChildVisitResult MethodDeclVisitor(CXCursor cursor, CXCursor parent, CXClientData client_data) {
    std::shared_ptr<ClangObjectModel::MethodInfo> methodInfo = *((std::shared_ptr<ClangObjectModel::MethodInfo>*)client_data);

    CXCursorKind kind = clang_getCursorKind(cursor);
    switch (kind) {
        case CXCursor_ParmDecl: {
            std::shared_ptr<ClangObjectModel::ParameterInfo> param;

            std::string typeSpelling = ClangHelpers::GetCursorTypeSpelling(cursor);
            CXType type = clang_getCursorType(cursor);
            CXTypeKind typeKind = type.kind;
            CXTypeKind canonicalTypeKind = clang_getCanonicalType(type).kind;

            // modify the typespelling if this is an enum
            if (canonicalTypeKind == CXType_Enum) {
                typeSpelling = ClangHelpers::getEnumTypeName(typeSpelling);
            }

            auto it = g_globalData.currentComponent->typedefDecl.find(typeSpelling);
            if (typeKind == CXType_Typedef && it != g_globalData.currentComponent->typedefDecl.end()) {
                param = it->second;
            } else {
                param = make_shared<ClangObjectModel::ParameterInfo>();
                param->typeInfo = make_shared<ClangObjectModel::TypeInfo>();
                param->typeInfo->cursor = cursor;
                param->typeInfo->SDKname = ClangHelpers::GetCursorSDKName(cursor);
                param->typeInfo->setTypeSpelling(typeSpelling);
                param->typeInfo->typeKind = canonicalTypeKind;
            }

            param->typeInfo->setTypeName(ClangHelpers::GetCursorSpelling(cursor));
            param->typeInfo->sourceLocation = ClangHelpers::GetSourceStartingLocation(cursor);
            param->marshallDelegateAsAsync = false;

            if (param->typeInfo->typeKind == CXType_BlockPointer) {
                if (typeKind != CXType_Typedef) {
                    // Typedefs are already visited.
                    clang_visitChildren(param->typeInfo->cursor, DelegateVisitor, &param);
                }
            } else {
                param->typeInfo->annotation = generateAnnotations(param->typeInfo);
            }

            methodInfo->params.push_back(std::move(param));
        } break;
        case CXCursor_FirstAttr: {
            CXCursorKind kind = clang_getCursorKind(cursor);
            if (clang_isAttribute(kind)) {
                std::string source = ClangHelpers::GetSource(cursor);
                if (source == "unavailable" || source == "NS_UNAVAILABLE") {
                    methodInfo->isUnavailable = true;
                }
            }
        } break;
    }
    return CXChildVisit_Continue;
}

// Create a ClangObjectModel::MethodInfo entry for one particular combination of possible
// value types for arguments(or return types) having "id" as their type.
// The combination of possible types is provided in the input argument metaDataInfo.
// Arguments:
// methodRef: The original ClangObjectModel::MethodInfo, which will be overloaded based on the combination of data type values.
// methodInfo: The vector which stores all the generated ClangObjectModel::MethodInfo entries.
// metaDataInfo: Stores one particular combination for the possible type values for arguments and return types.
// polymorphNumber: The number of times the method (methodRef) is now overloaded.
void _applyMetaDataInfo(std::shared_ptr<ClangObjectModel::MethodInfo>& methodRef,
                        std::vector<std::shared_ptr<ClangObjectModel::MethodInfo>>& methodInfos,
                        std::shared_ptr<ClangObjectModel::MetaDataComments>& metaDataInfo,
                        int polymorphNumber) {
    std::shared_ptr<ClangObjectModel::MethodInfo> method = ClangObjectModel::MethodInfo::CloneMethodInfo(methodRef);

    if (!method->isSynthesizedProperty) {
        if (method->needsDefaultOverload) {
            method->idlAnnotation = "[default_overload]" + method->idlAnnotation;
        }

        if (method->isOverloaded) {
            string methodNameForIdl = method->getMethodNameForIdl();
            if (method->returnTypePolymorphId > 0) {
                methodNameForIdl += to_string(method->returnTypePolymorphId);
            }

            method->idlAnnotation += "[overload(\"" + methodNameForIdl + "\")]";
        }
    }

    method->isAsync = metaDataInfo->hasAsyncMetaData();

    if (polymorphNumber > 0) {
        std::string methodNameForRuntimeClass;
        if (method->isSynthesizedProperty) {
            methodNameForRuntimeClass = method->getMethodNameForRuntimeClass() + to_string(polymorphNumber);
            string methodNameForIDL = method->getMethodNameForIdl() + ::to_string(polymorphNumber);
            method->UpdateMethodNameForIDLAndRuntimeClass(methodNameForIDL, methodNameForRuntimeClass);
        } else {
            methodNameForRuntimeClass = method->name + to_string(polymorphNumber);
            method->UpdateMethodNameForIDLAndRuntimeClass(methodNameForRuntimeClass);
        }
    } else if (!method->isSynthesizedProperty) {
        method->UpdateMethodNameForIDLAndRuntimeClass(method->name);
    }

    method->returnType->typeInfo->ResolveReturnType(metaDataInfo->getReturnMetaData());

    for (size_t i = 0; i < method->params.size(); i++) {
        if (method->params[i]->delegateParams.size() > 0) {
            for (size_t j = 0; j < method->params[i]->delegateParams.size(); j++) {
                method->params[i]->delegateParams[j]->ResolveParameterType(metaDataInfo->getBlockParameterMetaData(i, j));
            }
        } else {
            method->params[i]->typeInfo->ResolveParameterType(metaDataInfo->getParameterMetaData(i));
        }
    }

    for (auto param : method->params) {
        if (param->typeInfo->typeKind == CXType_BlockPointer) {
            if (method->isAsync) {
                ClangHelpers::updateAsyncClassInfo(param, method);
            } else {
                ClangHelpers::updateDelegateInfo(param, method);
            }
        }
    }
    methodInfos.push_back(method);
}

// Here we recursively combine all possible values for all the types which may have multiple values.
// This produces a cross product of values for all the types, and for each such cross product, we create
// a ClangObjectModel::MethodInfo entry, which is our API surface for that combination of argument types.
// Arguments:
// methodRef: The original ClangObjectModel::MethodInfo, which will be overloaded based on the combination of data type values.
// methodInfo: The vector which stores all the generated ClangObjectModel::MethodInfo entries.
// metaDataInfo: The entire annotation (ClangObjectModel::MetaDataComments) provided on the ObjC declaration.
// info: Stores one particular combination for the possible type values for arguments and return types.
// currentMetatDataLine: The line number of the input annotation. Each annotation goes on a separate line.
// polymorphNumber: The number of times the method (methodRef) is now overloaded.
int applyMetaDataInfo(std::shared_ptr<ClangObjectModel::MethodInfo>& methodRef,
                      std::vector<std::shared_ptr<ClangObjectModel::MethodInfo>>& methodInfo,
                      std::shared_ptr<ClangObjectModel::MetaDataComments>& metaDataInfo,
                      std::shared_ptr<ClangObjectModel::MetaDataComments>& info,
                      bool isFromApplicationDelegate,
                      int currentMetaDataLine = 0,
                      int polymorphNumber = 0) {
    // We do not apply any metadata for methods from the delegate.
    // These are generated as is without any modifications.
    if (isFromApplicationDelegate) {
        std::string metaDataType = metaDataInfo->getMetaDataType(0);
        // We do not generate the allocators and initializers for application delegate interface.
        // We simply need to know the method name.
        if (metaDataType == ClangObjectModel::MetaDataType_DelegateAllocator) {
            g_globalData.applicationDelegateInfo->allocatorMethod = methodRef;
        } else if (metaDataType == ClangObjectModel::MetaDataType_DelegateInitializer) {
            g_globalData.applicationDelegateInfo->initializerMethod = methodRef;
        } else if (metaDataType == ClangObjectModel::MetaDataType_DelegateAllocatorAndInitializer) {
            g_globalData.applicationDelegateInfo->allocatorMethod = methodRef;
            g_globalData.applicationDelegateInfo->initializerMethod = methodRef;
        } else {
            methodInfo.push_back(methodRef);
        }
        return 0;
    }

    int totalMetaDataLines = metaDataInfo->getMetaDataSize();
    if (currentMetaDataLine == totalMetaDataLines) {
        // we have all the required info
        _applyMetaDataInfo(methodRef, methodInfo, info, polymorphNumber);
        methodRef->needsDefaultOverload = false;
        return polymorphNumber + 1;
    }

    int currentNumber = polymorphNumber;
    int count = metaDataInfo->getTypes(currentMetaDataLine).size();
    bool setReturnTypePolymorphId = false;

    if (count > 1) {
        methodRef->isPolymorphic = true;

        bool isMetaDataForReturnType =
            (metaDataInfo->getMetaDataType(currentMetaDataLine) == ClangObjectModel::MetaDataType_ReturnType) ||
            (metaDataInfo->hasAsyncMetaData() && metaDataInfo->getBlockParameterNumber(currentMetaDataLine) != -1);
        if (isMetaDataForReturnType) {
            setReturnTypePolymorphId = true;
        } else if (!methodRef->isOverloaded) {
            methodRef->isOverloaded = true;
            methodRef->needsDefaultOverload = true;
        }
    }

    for (int j = 0; j < count; j++) {
        if (setReturnTypePolymorphId) {
            methodRef->returnTypePolymorphId = j;
            if (methodRef->isOverloaded) {
                methodRef->needsDefaultOverload = true;
            }
        }

        info->setTypes(currentMetaDataLine, { metaDataInfo->getTypes(currentMetaDataLine)[j] });

        info->setMetaDataType(currentMetaDataLine, metaDataInfo->getMetaDataType(currentMetaDataLine));

        info->setParameterNumber(currentMetaDataLine, metaDataInfo->getParameterNumber(currentMetaDataLine));

        info->setBlockParameterNumber(currentMetaDataLine, metaDataInfo->getBlockParameterNumber(currentMetaDataLine));

        currentNumber =
            applyMetaDataInfo(methodRef, methodInfo, metaDataInfo, info, isFromApplicationDelegate, currentMetaDataLine + 1, currentNumber);
    }

    return currentNumber;
}

CXChildVisitResult EnumVisitor(CXCursor cursor, CXCursor parent, CXClientData client_data) {
    std::shared_ptr<ClangObjectModel::TypeInfo> enumInfo = *((std::shared_ptr<ClangObjectModel::TypeInfo>*)client_data);
    CXCursorKind kind = clang_getCursorKind(cursor);

    if (kind == CXCursor_EnumConstantDecl) {
        std::string constantName = ClangHelpers::GetCursorSpelling(cursor);

        long long value = clang_getEnumConstantDeclUnsignedValue(cursor);
        if (value & 0xFFFFFFFF00000000) {
            // ToDo: IDL enum constants are of type 'int' and cannot marshall enum values greater than 32 bit!!
            Helpers::Errors::WriteError(cursor, "Enums with 64bit values are not supported.\n", true);
        }

        int32_t constantValue = (int32_t)value;
        enumInfo->enumConstants.insert({ constantName, constantValue });
    } else if (kind == CXCursor_EnumDecl) {
        return CXChildVisit_Recurse;
    }

    return CXChildVisit_Continue;
}

void handleEnums(const CXCursor cursor, std::shared_ptr<ClangObjectModel::ComponentInfo>& component) {
    std::shared_ptr<ClangObjectModel::TypeInfo> enumInfo;
    std::string spelling = ClangHelpers::GetCursorSpelling(cursor);
    if (spelling.empty()) {
        // This is unnamed enum.
        // We handle it when we get the cursor with the typedef, else unnamed enums are of no use to us as they do not define any type.
        return;
    }
    auto it = g_globalData.enums.find(spelling);
    if (it != g_globalData.enums.end()) {
        enumInfo = it->second;
        if (enumInfo->enumConstants.size() &&
            (enumInfo->getSDKName() != component->getSDKName() || enumInfo->SDKHeaderFile != component->SDKHeaderFile)) {
            // With enums there is no partial declaration.
            // If we have the enum constants then this declaration was already handled.
            // The component in which this enum is defined becomes our referenced IDL.
            component->referencedIDLs.insert(ClangHelpers::generateNamespaceString(enumInfo->getSDKName(), ".") + "." +
                                             enumInfo->SDKHeaderFile + ".idl");
            return;
        }
    } else {
        enumInfo = make_shared<ClangObjectModel::TypeInfo>();
        enumInfo->setTypeSpelling(spelling);
        enumInfo->typeKind = CXType_Enum;
    }
    clang_visitChildren(cursor, EnumVisitor, &enumInfo);
    if (enumInfo->enumConstants.size() == 0) {
        // some weird libclang behavior for the expansion of NS_ENUM macro.
        // The same enum is reported in the AST multiple times, one is the actual enum declaration,
        // the second is the typedef declaration, and this is the third one with no constants.
        // We ignore the third one.
        return;
    }

    // Set this only when we have processed the actual enum declaration.
    enumInfo->SDKname = ClangHelpers::GetCursorSDKName(cursor);
    enumInfo->SDKHeaderFile = component->SDKHeaderFile;
    component->enums.insert({ enumInfo->getTypeSpelling(), enumInfo });
    if (it == g_globalData.enums.end()) {
        g_globalData.enums.insert({ enumInfo->getTypeSpelling(), enumInfo });
    }
}

void _parsePropertyDeclaration(const string& src, const string& propertyName, string& getterName, string& setterName) {
    // This could be simplified, but this is the best so far.
    std::regex regGetter(
        "(?:[\\(])(?:[a-zA-Z0-9_, =:]*)(?:getter{1})(?:[[:s:]]*)(?:={1})(?:[[:s:]]*)([a-zA-Z0-9_]+)(?:[a-zA-Z0-9_, =:]*)(?:[\\)])");
    std::smatch matchGetter;

    if (std::regex_search(src.begin(), src.end(), matchGetter, regGetter)) {
        getterName = matchGetter[1];
    } else {
        getterName = propertyName;
    }

    std::regex regSetter(
        "(?:[\\(])(?:[a-zA-Z0-9_, =:]*)(?:setter{1})(?:[[:s:]]*)(?:={1})(?:[[:s:]]*)([a-zA-Z0-9_]+)(?:[a-zA-Z0-9_, =:]*)(?:[\\)])");
    std::smatch matchSetter;
    if (std::regex_search(src.begin(), src.end(), matchSetter, regSetter)) {
        setterName = matchSetter[1];
    } else {
        setterName = propertyName;

        // capitalize first letter for the setter
        if (setterName[0] >= 'a' && setterName[0] <= 'z') {
            setterName[0] = setterName[0] - 'a' + 'A';
        }

        setterName = "set" + setterName;
    }
}

std::shared_ptr<ClangObjectModel::PropertyInfo> HandlePropertyDecl(CXCursor cursor) {
    std::string propertyName = ClangHelpers::GetCursorSpelling(cursor);
    std::string getterName;
    std::string setterName;
    string src = ClangHelpers::GetSource(cursor);

    // parse the property declaration to find if there are any custom getters and setters.
    _parsePropertyDeclaration(src, propertyName, getterName, setterName);

    // extract raw comment if any which will be used by the synthesized accessor methods.
    std::shared_ptr<ClangObjectModel::MetaDataComments> metadata = std::make_shared<ClangObjectModel::MetaDataComments>(cursor, true);

    std::shared_ptr<ClangObjectModel::PropertyInfo> propInfo =
        make_shared<ClangObjectModel::PropertyInfo>(propertyName, getterName, setterName, metadata);
    return propInfo;
}

std::shared_ptr<ClangObjectModel::MethodInfo> HandleMethodDecl(CXCursor cursor,
                                                               const std::string& interfaceOrProtocolName,
                                                               std::vector<std::shared_ptr<ClangObjectModel::PropertyInfo>>& properties,
                                                               std::shared_ptr<ClangObjectModel::MetaDataComments>& metaDataInfo) {
    std::shared_ptr<ClangObjectModel::MethodInfo> method;
    std::shared_ptr<ClangObjectModel::PropertyInfo> property;

    string methodName = ClangHelpers::GetMethodSpelling(cursor);
    cout << "\t\tTranslating " << methodName << std::endl;

    for (auto propInfo : properties) {
        if (methodName == propInfo->getter->name) {
            property = propInfo;
            method = propInfo->getter;
            method->isSynthesizedProperty = true;
            metaDataInfo = propInfo->metadata;
            if (metaDataInfo->getMetaDataType(0) != ClangObjectModel::MetaDataType_IgnoreDecl) {
                metaDataInfo->setMetaDataType(0, ClangObjectModel::MetaDataType_ReturnType);
            }
            break;
        }

        if (methodName == propInfo->setter->name) {
            property = propInfo;
            method = propInfo->setter;
            method->isSynthesizedProperty = true;
            metaDataInfo = propInfo->metadata;
            if (metaDataInfo->getMetaDataType(0) != ClangObjectModel::MetaDataType_IgnoreDecl) {
                metaDataInfo->setMetaDataType(0, ClangObjectModel::MetaDataType_Parameter);
                metaDataInfo->setParameterNumber(0, 0);
            }
            break;
        }
    }

    if (!property) {
        method = make_shared<ClangObjectModel::MethodInfo>();
        method->name = methodName;
        method->isSynthesizedProperty = false;
        metaDataInfo = std::make_shared<ClangObjectModel::MetaDataComments>(cursor);
    }

    if (metaDataInfo->isIgnoredType()) {
        return nullptr;
    }

    method->objectiveCSignature = ClangHelpers::GetSource(cursor);
    method->objectiveCSelector = ClangHelpers::GetCursorSpelling(cursor);
    method->SDKname = ClangHelpers::GetCursorSDKName(cursor);
    method->isAsync = false;
    method->displayName = ClangHelpers::GetDisplayName(cursor);

    std::string typeSpelling = ClangHelpers::GetCursorResultTypeSpelling(cursor);
    CXTypeKind typeKind = clang_getCursorResultType(cursor).kind;

    auto typedefIt = g_globalData.currentComponent->typedefDecl.find(typeSpelling);
    method->returnType = make_shared<ClangObjectModel::ParameterInfo>();
    method->returnType->typeInfo = make_shared<ClangObjectModel::TypeInfo>();
    if (typeKind == CXType_Typedef && typedefIt != g_globalData.currentComponent->typedefDecl.end()) {
        method->returnType->typeInfo->cursor = typedefIt->second->typeInfo->cursor;
        method->returnType->typeInfo->SDKname = typedefIt->second->typeInfo->getSDKName();
        method->returnType->typeInfo->setTypeSpelling(typedefIt->second->typeInfo->getTypeSpelling());
        method->returnType->typeInfo->typeKind = typedefIt->second->typeInfo->typeKind;
    } else {
        method->returnType->typeInfo->cursor = cursor;
        method->returnType->typeInfo->SDKname = ClangHelpers::GetCursorSDKName(cursor);
        method->returnType->typeInfo->setTypeSpelling(typeSpelling);
        method->returnType->typeInfo->typeKind = clang_getCursorResultType(cursor).kind;
        method->returnType->typeInfo->sourceLocation = ClangHelpers::GetSourceStartingLocation(cursor);
    }

    if (Helpers::Trim(method->returnType->typeInfo->getTypeSpelling()) == "instancetype") {
        method->returnType->typeInfo->setTypeSpelling(interfaceOrProtocolName + "*");
    }
    method->returnType->marshallDelegateAsAsync = false;
    method->returnType->typeInfo->setTypeName("__returnValue");
    method->returnType->typeInfo->annotation = "[out] [retval]";

    clang_visitChildren(cursor, MethodDeclVisitor, &method);

    if (method->returnType->typeInfo->getTypeSpelling(true) == "NSURL" && metaDataInfo->getReturnMetaData().empty()) {
        // There is no metadata for the return type.
        // Inject our custom metadata.
        metaDataInfo->appendMetaData(ClangObjectModel::MetaDataType_ReturnType, -1, -1, vector<string>({ "StorageFile", "Uri" }));
    }

    // Run through all through the parameters to check if there is any additional metadata info.
    for (size_t i = 0; i < method->params.size(); i++) {
        auto param = method->params[i];
        if (param->paramMetaData != nullptr) {
            int n = param->paramMetaData->getMetaDataSize();
            for (int line = 0; line < n; line++) {
                std::string type = ClangObjectModel::MetaDataType_Parameter;
                auto types = param->paramMetaData->getTypes(line);
                int blockNumber = param->paramMetaData->getBlockParameterNumber(line);
                metaDataInfo->appendMetaData(type, i, blockNumber, types);
            }
        }

        if (param->typeInfo->getTypeSpelling(true) == "NSURL" && !metaDataInfo->parameterHasMetaData(i)) {
            // There is no metadata on this parameter.
            // Inject our custom meta data.
            metaDataInfo->appendMetaData(ClangObjectModel::MetaDataType_Parameter, i, -1, vector<string>({ "StorageFile", "Uri" }));
        }
    }

    return method;
}

CXChildVisitResult ProtocolVisitor(CXCursor cursor, CXCursor parent, CXClientData client_data) {
    std::shared_ptr<ClangObjectModel::ProtocolInfo> protoInfo = *((std::shared_ptr<ClangObjectModel::ProtocolInfo>*)client_data);
    CXCursorKind kind = clang_getCursorKind(cursor);

    switch (kind) {
        case CXCursor_FirstRef:
        case CXCursor_ObjCClassRef:
            break;

        case CXCursor_ObjCPropertyDecl: {
            std::shared_ptr<ClangObjectModel::PropertyInfo> propInfo = HandlePropertyDecl(cursor);
            protoInfo->properties.push_back(propInfo);
        } break;

        case CXCursor_ObjCClassMethodDecl: {
            // NOTE: I think this should work.  We just need to test it.
            stringstream errorMsg;
            errorMsg << "class methods on Protocols is not currently supported: " << std::endl;
            Helpers::Errors::WriteError(cursor, errorMsg.str(), true);
        } break;

        case CXCursor_ObjCInstanceMethodDecl: {
            std::shared_ptr<ClangObjectModel::MetaDataComments> metaDataInfo;
            std::shared_ptr<ClangObjectModel::MethodInfo> method =
                HandleMethodDecl(cursor, protoInfo->name, protoInfo->properties, metaDataInfo);

            if (method == nullptr) {
                // method is ignored
                break;
            }

            bool isInitMethod = method->name.substr(0, 4) == "init";
            if (isInitMethod) {
                stringstream errorMsg;
                errorMsg << "init methods on Protocols is not currently supported: " << std::endl;
                Helpers::Errors::WriteError(cursor, errorMsg.str(), true);
            }

            applyMetaDataInfo(method,
                              protoInfo->instanceMethods,
                              metaDataInfo,
                              make_shared<ClangObjectModel::MetaDataComments>(*metaDataInfo),
                              false);
        } break;
    }

    return CXChildVisit_Continue;
}

CXChildVisitResult InterfaceVisitor(CXCursor cursor, CXCursor parent, CXClientData client_data) {
    std::shared_ptr<ClangObjectModel::InterfaceInfo> ifaceInfo = *((std::shared_ptr<ClangObjectModel::InterfaceInfo>*)client_data);
    CXCursorKind kind = clang_getCursorKind(cursor);
    std::string kindSpelling = ClangHelpers::GetString(clang_getCursorKindSpelling(kind));

    switch (kind) {
        case CXCursor_ObjCClassRef:
            break;

        case CXCursor_ObjCSuperClassRef: {
            ifaceInfo->SetSuperClassFromCursor(cursor);
            HandleClassRef(cursor, g_globalData.currentComponent);
            break;
        }

        case CXCursor_ObjCProtocolRef: {
            std::string protocolName = ClangHelpers::GetCursorSpelling(cursor);

            // Only handle protocols from our framework.
            CXCursor cursorRef = clang_getCursorReferenced(cursor);
            if (ClangHelpers::isCursorFromProjectHeaders(cursorRef)) {
                HandleProtocolRef(cursor, g_globalData.currentComponent);
                ifaceInfo->AddProtocolsImplemented(protocolName);
            }
            break;
        }

        case CXCursor_ObjCPropertyDecl: {
            std::shared_ptr<ClangObjectModel::PropertyInfo> propInfo = HandlePropertyDecl(cursor);
            ifaceInfo->properties.push_back(propInfo);
            break;
        }

        case CXCursor_ObjCInstanceMethodDecl:
        case CXCursor_ObjCClassMethodDecl: {
            std::shared_ptr<ClangObjectModel::MetaDataComments> metaDataInfo;
            std::shared_ptr<ClangObjectModel::MethodInfo> method =
                HandleMethodDecl(cursor, ifaceInfo->name, ifaceInfo->properties, metaDataInfo);

            if (method == nullptr) {
                // method is ignored
                break;
            }

            method->SDKHeaderFile = ifaceInfo->SDKHeaderFile;
            bool isInitMethod = method->name.substr(0, 4) == "init";
            if (isInitMethod) {
                if (method->params.size() == 0) {
                    if (method->isUnavailable) {
                        ifaceInfo->hasDefaultInitializer = false;
                    }
                    break;
                } else {
                    method->returnType->typeInfo->setTypeSpelling(ifaceInfo->name + "*");
                }
                applyMetaDataInfo(method,
                                  ifaceInfo->parameterizedInitMethods,
                                  metaDataInfo,
                                  make_shared<ClangObjectModel::MetaDataComments>(*metaDataInfo),
                                  ifaceInfo->isApplicationDelegate);
            } else {
                if (kind == CXCursor_ObjCInstanceMethodDecl) {
                    applyMetaDataInfo(method,
                                      ifaceInfo->instanceMethods,
                                      metaDataInfo,
                                      make_shared<ClangObjectModel::MetaDataComments>(*metaDataInfo),
                                      ifaceInfo->isApplicationDelegate);
                } else {
                    applyMetaDataInfo(method,
                                      ifaceInfo->classMethods,
                                      metaDataInfo,
                                      make_shared<ClangObjectModel::MetaDataComments>(*metaDataInfo),
                                      ifaceInfo->isApplicationDelegate);
                }
            }
            break;
        }
    }

    return CXChildVisit_Continue;
}

CXChildVisitResult InterfaceCategoryVisitor(CXCursor cursor, CXCursor parent, CXClientData client_data) {
    std::shared_ptr<ClangObjectModel::ComponentInfo> component = *((std::shared_ptr<ClangObjectModel::ComponentInfo>*)client_data);
    CXCursorKind kind = clang_getCursorKind(cursor);

    switch (kind) {
        case CXCursor_ObjCClassRef:
            std::string name = ClangHelpers::GetCursorSpelling(cursor);
            auto it = g_globalData.interfaceMap.find(name);
            if (it == g_globalData.interfaceMap.end()) {
                // This should never happen.
                // we cannot have an interface category before interface declaration.
                // Clang will report this as an error.
                stringstream errMsg;
                errMsg << "Could not find interface declaration for category " << name << ". Please inlcude the header for the category."
                       << std::endl;
                Helpers::Errors::WriteError(cursor, errMsg.str(), false);
            }

            clang_visitChildren(parent, InterfaceVisitor, &(it->second));
            break;
    }

    return CXChildVisit_Break;
}

void HandleTypedefDecl(CXCursor cursor) {
    CXCursor _cursor = cursor;
    std::string typedefSpelling = ClangHelpers::GetCursorTypeSpelling(_cursor);
    CXType underlyingType;
    CXType typedefType;
    CXTypeKind underlyingTypeKind;
    std::string underlyingTypeSpelling;

    std::shared_ptr<ClangObjectModel::ParameterInfo> param = std::make_shared<ClangObjectModel::ParameterInfo>();
    param->typeInfo = make_shared<ClangObjectModel::TypeInfo>();
    do {
        underlyingType = clang_getTypedefDeclUnderlyingType(_cursor);
        typedefType = clang_getCursorType(_cursor);
        underlyingTypeKind = underlyingType.kind;
        underlyingTypeSpelling = ClangHelpers::GetTypeSpelling(underlyingType);
        CXTypeKind canonicalTypeKind = clang_getCanonicalType(underlyingType).kind;

        if (canonicalTypeKind == CXType_Enum) {
            // This corresponds to type enum, check the actual declaration for unnamed enum.
            CXCursor declCursor = clang_getTypeDeclaration(underlyingType);
            string declSpelling = ClangHelpers::GetCursorSpelling(declCursor);
            if (declSpelling.empty()) {
                // This is the typedef corresponding to an unnamed enum.
                // Handle the enum here as we will have all the required information here.
                handleEnums(_cursor, g_globalData.currentComponent);
            }

            underlyingTypeSpelling = ClangHelpers::getEnumTypeName(underlyingTypeSpelling);
            auto it = g_globalData.enums.find(underlyingTypeSpelling);
            if (it != g_globalData.enums.end()) {
                param->typeInfo = it->second;
            } else {
                g_globalData.enums.insert({ underlyingTypeSpelling, param->typeInfo });
            }
            param->typeInfo->typeKind = CXType_Enum;
            break;
        } else {
            param->typeInfo->typeKind = underlyingTypeKind;
        }

        if (underlyingTypeKind != CXType_Typedef) {
            break;
        }

        auto it = g_globalData.currentComponent->typedefDecl.find(underlyingTypeSpelling);
        if (it == g_globalData.currentComponent->typedefDecl.end()) {
            stringstream errMsg;
            errMsg << "Typedef " << underlyingTypeSpelling << " used before it is defined. Please inlcude the header for the typedef."
                   << std::endl;
            Helpers::Errors::WriteError(cursor, errMsg.str(), false);
        }
        _cursor = it->second->typeInfo->cursor;
    } while (underlyingTypeKind == CXType_Typedef);

    param->typeInfo->setTypeSpelling(underlyingTypeSpelling);
    param->typeInfo->cursor = _cursor;

    auto metaDataInfo = std::make_shared<ClangObjectModel::MetaDataComments>(_cursor);
    param->paramMetaData = metaDataInfo;

    if (param->typeInfo->typeKind != CXType_Enum) {
        // This is set when we handle the enum declarations.
        param->typeInfo->SDKname = ClangHelpers::GetCursorSDKName(_cursor);
    }

    if (param->typeInfo->typeKind == CXType_BlockPointer) {
        clang_visitChildren(param->typeInfo->cursor, DelegateVisitor, &param);
    }

    g_globalData.currentComponent->typedefDecl.insert({ typedefSpelling, std::move(param) });
}

void HandleClassRef(CXCursor cursor, std::shared_ptr<ClangObjectModel::ComponentInfo>& component) {
    std::string ifaceName = ClangHelpers::GetCursorSpelling(cursor);
    component->AddReferenceToInterface(ifaceName);
}

void HandleProtocolRef(CXCursor cursor, std::shared_ptr<ClangObjectModel::ComponentInfo>& component) {
    std::string protocolName = ClangHelpers::GetCursorSpelling(cursor);
    component->AddReferenceToProtocol(protocolName);
}

void HandleReferences(CXCursor cursor, std::shared_ptr<ClangObjectModel::ComponentInfo>& component) {
    ClangObjectModel::MetaDataComments metaData(cursor);
    if (metaData.isIgnoredType()) {
        return;
    }

    std::shared_ptr<ClangObjectModel::InterfaceInfo> iface;
    std::string filePath;
    std::string ifaceName;
    std::string sdkName;
    CXCursorKind kind = clang_getCursorKind(cursor);
    switch (kind) {
        case CXCursor_ObjCClassRef: {
            // This needs to go to unresolved symbols as we do not know what is the IDL file name or the name of the
            // internal header which will declare this interface.
            HandleClassRef(cursor, component);
            break;
        }

        case CXCursor_EnumDecl: {
            filePath = ClangHelpers::GetCursorFileName(cursor);
            sdkName = ClangHelpers::GetCursorSDKName(cursor);
            char fname[_MAX_FNAME];
            Helpers::Errors::Throw_On_Error(_splitpath_s(filePath.c_str(), NULL, 0, NULL, 0, fname, _MAX_FNAME, NULL, 0));

            if (sdkName == component->getSDKName() && fname == component->SDKHeaderFile) {
                handleEnums(cursor, component);
            } else {
                component->referencedIDLs.insert(ClangHelpers::generateNamespaceString(sdkName, ".") + "." + fname + ".idl");
            }
        } break;
        case CXCursor_ObjCInterfaceDecl:
            HandleClassRef(cursor, component);
            break;
        case CXCursor_ObjCProtocolDecl:
        case CXCursor_ObjCProtocolRef:
            HandleProtocolRef(cursor, component);
            break;
        case CXCursor_TypedefDecl:
            HandleTypedefDecl(cursor);
            break;
    }
}

// Libclang has some weird (buggy?) behaviour with @class <interfaceName>.  The cursor for a forward decl is a ObjcInterfaceDecl instead of
// a ObjCClassRef
// In order to differentiate @class <interfacename> from a class with only a defualt initializer (e.g. @interface Foo{}), we need to visit
// the cursor's children,
// which will be ObjCClassRef's.
// If the cursor is a foward decl, the name of the ObjCClassRef will be the same as the parent's cursor.
// If the cursor is a @interface Foo{}, the name of the ObjCClassRef will be different than the parent's cursor (NSObject).
CXChildVisitResult IsForwardDeclarationVisitor(CXCursor cursor, CXCursor parent, CXClientData client_data) {
    bool* isForwardDeclaration = (bool*)client_data;

    std::string parentName = ClangHelpers::GetCursorSpelling(parent);
    std::string cursorName = ClangHelpers::GetCursorSpelling(cursor);
    CXCursorKind kind = clang_getCursorKind(cursor);

    switch (kind) {
        case CXCursor_ObjCClassRef: {
            if (parentName == cursorName) {
                *isForwardDeclaration = true;
                HandleClassRef(cursor, g_globalData.currentComponent);
                return CXChildVisit_Break;
            }
        } break;
        case CXCursor_ObjCProtocolRef: {
            if (parentName == cursorName) {
                *isForwardDeclaration = true;
                HandleProtocolRef(cursor, g_globalData.currentComponent);
                return CXChildVisit_Break;
            }
        } break;
    }
    return CXChildVisit_Continue;
}

void FixUnresolvedReferences(const std::string& referenceName,
                             bool isInterface,
                             std::unordered_multimap<std::string, std::shared_ptr<ClangObjectModel::ComponentInfo>> unresolvedMap) {
    auto it = unresolvedMap.equal_range(referenceName);
    auto componentIt = it.first;
    while (componentIt != it.second) {
        std::string namespaceString = ClangHelpers::generateNamespaceString(g_globalData.currentComponent->getSDKName(), ".");

        if (componentIt->second->SDKHeaderFile != g_globalData.currentComponent->SDKHeaderFile) {
            // put header file name in referencedIDLs
            componentIt->second->referencedIDLs.insert(namespaceString + "." + g_globalData.currentComponent->SDKHeaderFile + ".idl");
        }

        if (isInterface) {
            // generate the interface header name and put it in referencedInterfaces.
            componentIt->second->referencedInterfaces.insert(namespaceString + "." + g_globalData.currentComponent->SDKHeaderFile + "." +
                                                             referenceName);
        } else {
            // generate the interface header name and put it in referencedProtocols.
            componentIt->second->referencedProtocols.insert(namespaceString + "." + g_globalData.currentComponent->SDKHeaderFile + "." +
                                                            referenceName);
        }

        componentIt++;
    }
    unresolvedMap.erase(referenceName);
}

CXChildVisitResult ASTVisitor(CXCursor cursor, CXCursor parent, CXClientData client_data) {
    std::string spelling = ClangHelpers::GetCursorSpelling(cursor);
    std::string fileName = ClangHelpers::GetCursorFileName(cursor);

    std::shared_ptr<ClangObjectModel::ComponentInfo> component = *((std::shared_ptr<ClangObjectModel::ComponentInfo>*)client_data);
    if (!ClangHelpers::isCursorFromProjectHeaders(cursor)) {
        return CXChildVisit_Continue;
    }

    if (!clang_Location_isFromMainFile(clang_getCursorLocation(cursor))) {
        // These will be added as references
        HandleReferences(cursor, component);
        return CXChildVisit_Continue;
    }

    // Note: GetCursorSpelling will be empty for an Extension, which we do not expect to see in public headers.
    std::cout << "\tTranslating " << spelling << " in " << fileName << std::endl;

    CXCursorKind kind = clang_getCursorKind(cursor);
    ClangObjectModel::MetaDataComments metaData(cursor);
    if (metaData.isIgnoredType()) {
        return CXChildVisit_Continue;
    }

    switch (kind) {
        case CXCursor_EnumDecl:
            handleEnums(cursor, component);
            break;

        case CXCursor_ObjCProtocolDecl: {
            std::string protocolName = ClangHelpers::GetCursorSpelling(cursor);

            bool isForwardDecl = false;
            clang_visitChildren(cursor, IsForwardDeclarationVisitor, &isForwardDecl);

            if (!isForwardDecl) {
                std::shared_ptr<ClangObjectModel::ProtocolInfo> protocol = make_shared<ClangObjectModel::ProtocolInfo>(protocolName);

                protocol->SDKname = ClangHelpers::GetCursorSDKName(cursor);
                protocol->SDKHeaderFile = component->SDKHeaderFile;

                // TODO: get protocols inheritance hierarchy
                clang_visitChildren(cursor, ProtocolVisitor, &protocol);

                ClangHelpers::fixMethodNameConflicts(protocol->instanceMethods);
                g_globalData.protocolMap.insert({ protocol->name, protocol });
                component->protocols.insert({ protocol->name, protocol });

                FixUnresolvedReferences(protocolName, false, g_globalData.unresolvedProtocols);

                if (metaData.isDelegateCallbackProtocol()) {
                    protocol->implHeaderName = ClangHelpers::generateNamespaceString(protocol->getSDKName(), ".") + "." +
                                               protocol->SDKHeaderFile + "." + protocol->name + ".h";
                    component->delegateCallbackProtocolsMap.insert({ protocol->name, protocol });
                    g_globalData.delegateCallbackProtocolsMap.insert({ protocol->name, protocol });
                }
            }
        } break;

        case CXCursor_ObjCInterfaceDecl: {
            std::string ifaceName = ClangHelpers::GetCursorSpelling(cursor);
            bool isForwardDecl = false;
            clang_visitChildren(cursor, IsForwardDeclarationVisitor, &isForwardDecl);
            if (!isForwardDecl) {
                std::shared_ptr<ClangObjectModel::InterfaceInfo> iface = make_shared<ClangObjectModel::InterfaceInfo>(ifaceName);
                iface->isApplicationDelegate = metaData.isApplicationDelegate();
                if (iface->isApplicationDelegate) {
                    g_globalData.applicationDelegateInfo = make_shared<ClangObjectModel::ApplicationDelegateInfo>();
                }

                if (component->ifaces.find(iface->name) == component->ifaces.end()) {
                    iface->SDKname = ClangHelpers::GetCursorSDKName(cursor);
                    iface->SDKHeaderFile = component->SDKHeaderFile;

                    clang_visitChildren(cursor, InterfaceVisitor, &iface);

                    ClangHelpers::fixMethodNameConflicts(iface->instanceMethods);

                    if (iface->isApplicationDelegate) {
                        g_globalData.applicationDelegateInfo->ifaceInfo = std::move(iface);
                    } else {
                        g_globalData.interfaceMap.insert({ iface->name, iface });
                        component->ifaces.insert({ iface->name, std::move(iface) });
                        FixUnresolvedReferences(ifaceName, true, g_globalData.unresolvedInterfaces);
                    }
                }
            }
        } break;

        case CXCursor_ObjCCategoryDecl:
            clang_visitChildren(cursor, InterfaceCategoryVisitor, &component);
            break;

        case CXCursor_TypedefDecl:
            HandleTypedefDecl(cursor);
            break;
    }
    return CXChildVisit_Continue;
}

#ifdef DEBUG
CXChildVisitResult DumpAST(CXCursor cursor, CXCursor parent, CXClientData client_data) {
    int recurse = (int)client_data;
    std::string spelling = ClangHelpers::GetCursorSpelling(cursor);
    std::string fileName = ClangHelpers::GetCursorFileName(cursor);
    CXType type = clang_getCursorType(cursor);
    std::string typeSpelling = ClangHelpers::GetTypeSpelling(type);

    CXCursorKind kind = clang_getCursorKind(cursor);
    std::cout << std::string(recurse, ' ') << fileName << ", " << spelling << ", " << kind << ", " << typeSpelling << ", " << std::endl;
    recurse = recurse + 1;
    clang_visitChildren(cursor, DumpAST, (CXClientData)recurse);
    recurse = recurse - 1;
    return CXChildVisit_Continue;
}
#endif

// TODO: Eventually we will want to extend this to all methods (instance, init, etc).
void FindInterfacesUsingDelegateCallbacks() {
    for (const auto& comp : g_globalData.components) {
        for (const auto& iface : comp->ifaces) {
            for (const auto& method : iface.second->classMethods) {
                for (const auto& param : method->params) {
                    string typeName = param->typeInfo->getTypeSpelling(true);
                    auto it = g_globalData.delegateCallbackProtocolsMap.find(typeName);
                    if (it != g_globalData.delegateCallbackProtocolsMap.end()) {
                        iface.second->usedDelegateTypes.insert({ param->typeInfo->getTypeSpelling(), param->typeInfo });
                    }
                }
            }
        }
    }
}

void runTests(std::string outputDir) {
    for (auto SDK : g_sdkParameters.SDKHeaderArgMap) {
        std::string sdkName = SDK.first;
        ClangHelpers::header_argfile& haPair = SDK.second;

        ifstream argFile(haPair.second);
        std::string s((istreambuf_iterator<char>(argFile)), istreambuf_iterator<char>());
        vector<std::string> clangArgs;
        tokenize(s, clangArgs, " \n", "", "\"", "", "", false, false);

        vector<const char*> clangArgs1;
        for_each(clangArgs.begin(), clangArgs.end(), [&clangArgs1](std::string& s) {
            if (s != "-MD" && s != "-MMD") {
                clangArgs1.push_back(s.c_str());
            }
        });

        ifstream headerFile(haPair.first);
        std::string line;

        while (getline(headerFile, line)) {
            CXIndex idx = clang_createIndex(1, 1);
            CXTranslationUnit tu;
            tu = clang_parseTranslationUnit(idx, line.c_str(), clangArgs1.data(), clangArgs1.size(), 0, 0, 0);
            size_t count = clang_getNumDiagnostics(tu);
            for (size_t i = 0; i < count; i++) {
                CXDiagnostic diagnostic = clang_getDiagnostic(tu, i);
                CXDiagnosticSeverity severity = clang_getDiagnosticSeverity(diagnostic);
                if (severity >= CXDiagnostic_Error) {
                    CXSourceLocation locn = clang_getDiagnosticLocation(diagnostic);
                    CXCursor cursor = clang_getCursor(tu, locn);
                    ClangObjectModel::MetaDataComments metaData(cursor);
                    if (metaData.isIgnoredType()) {
                        clang_disposeDiagnostic(diagnostic);
                        continue;
                    }
                    CXString diagInfo = clang_getDiagnosticSpelling(diagnostic);
                    string diagInfoStr = ClangHelpers::GetString(diagInfo);
                    clang_disposeString(diagInfo);
                    Helpers::Errors::WriteError(ClangHelpers::GetSourceLocation(locn), diagInfoStr, false);
                }
                clang_disposeDiagnostic(diagnostic);
            }

            CXCursor cursor = clang_getTranslationUnitCursor(tu);
            std::shared_ptr<ClangObjectModel::ComponentInfo> component = make_shared<ClangObjectModel::ComponentInfo>();
            g_globalData.currentComponent = component;
            component->SDKname = sdkName;
            char drive[_MAX_DRIVE];
            char dir[_MAX_DIR];
            char fname[_MAX_FNAME];
            char ext[_MAX_EXT];
            errno_t err = _splitpath_s(line.c_str(), drive, dir, fname, ext);
            if (err != 0) {
                // TODO: Use wil
                stringstream error;
                error << "_splitpath_s returned: " << err;
                throw new exception(error.str().c_str());
            }
            component->SDKHeaderFile = fname;
            std::cout << "Translating " << line << std::endl;
            clang_visitChildren(cursor, ASTVisitor, &component);
            g_globalData.components.push_back(component);
#ifdef DEBUG
            int recurse = 0;
            clang_visitChildren(cursor, DumpAST, (CXClientData)recurse);
#endif
            clang_disposeTranslationUnit(tu);
            clang_disposeIndex(idx);
        }
    }

    FindInterfacesUsingDelegateCallbacks();

    if (g_globalData.applicationDelegateInfo) {
        dumpFile(g_sdkParameters.rootNameSpace + "_" + g_globalData.applicationDelegateInfo->ifaceInfo->name + ".mm",
                 generateAppDelegateImpl(),
                 outputDir);
        dumpFile(g_sdkParameters.rootNameSpace + "_" + g_globalData.applicationDelegateInfo->ifaceInfo->name + ".h",
                 generateAppDelegateDecl(),
                 outputDir);
    }

    std::string rootNamespace = ClangHelpers::generateNamespaceString("", "");

    // Generate NSNotificationCenter marshalling code.
    if (g_globalData.requiresNSNotificationMarshalling) {
        dumpFile(rootNamespace + "._" + g_notificationCenter + ".idl", CommonCodeGenerator::generateNSNotificationCenterIDL(), outputDir);
        dumpFile(rootNamespace + "._" + g_notificationCenter + ".mm",
                 CommonCodeGenerator::generateNSNotificationCenterDefinitions(),
                 outputDir);
    }

    dumpFile(g_sdkParameters.rootNameSpace + ".h", CommonCodeGenerator::generateCommonHeader(), outputDir);
    dumpFile(g_sdkParameters.rootNameSpace + ".mm", CommonCodeGenerator::generateCommonImplementation(), outputDir);

    for (auto delPair : g_globalData.delegateCallbackProtocolsMap) {
        string fileName = ClangHelpers::generateNamespaceString(delPair.second->getSDKName(), ".") + "." + delPair.second->SDKHeaderFile +
                          "." + delPair.second->name + ".h";
        dumpFile(fileName, generateObjCDelegateCallbackDeclaration(delPair.second), outputDir);
    }

    for (auto comp : g_globalData.components) {
        g_globalData.currentComponent = comp;
        if (comp->ifaces.size() > 0 || comp->protocols.size() > 0 || comp->enums.size() > 0) {
            // Fix async class implementor names.
            // We are not aware of the header and SDK names when we generate the name, so we fix the name here.
            vector<shared_ptr<ClangObjectModel::AsyncClassInfo>> asyncClassesArray(comp->asyncClasses.begin(), comp->asyncClasses.end());
            for (auto& asyncClass : asyncClassesArray) {
                if (asyncClass->returnTypes.size() == 0) {
                    asyncClass->name = "_AsyncActionImpl";
                } else {
                    asyncClass->sdkName = comp->getSDKName();
                    ClangHelpers::generateAsyncClassImplName(asyncClass, comp->SDKHeaderFile);
                    string classType = ClangHelpers::getResolvedAsyncImplName(asyncClass);
                    string interfaceType = ClangHelpers::getResolvedAsyncImplName(asyncClass, "I");
                    string templateString = classType + ", " + interfaceType;
                    asyncClass->name = "ObjCAsync::AsyncOperationImpl<" + templateString + ">";
                }
            }
            comp->asyncClasses.clear();
            comp->asyncClasses.insert(asyncClassesArray.begin(), asyncClassesArray.end());

            std::string namespaceString = ClangHelpers::generateNamespaceString(comp->getSDKName(), ".");
            dumpFile(namespaceString + "." + comp->SDKHeaderFile + ".idl", generateIdl(comp), outputDir);
            dumpFile(namespaceString + "." + comp->SDKHeaderFile + ".mm", generateClassBindings(comp), outputDir);
            for (auto iface : comp->ifaces) {
                dumpFile(namespaceString + "." + comp->SDKHeaderFile + "." + iface.first + ".h", generateHeaders(iface.second), outputDir);
            }
            if (comp->heterogeneousContainers.size()) {
                dumpFile(namespaceString + "." + comp->SDKHeaderFile + "._Containers.h",
                         generateHeterogeneousContainerDeclarations(comp),
                         outputDir);
            }
        }
        comp->clearAll();
    }
}

void Usage() {
    printf("obj2winmd -r <root name space> -o <output directory> SDK.header SDK.args");
    exit(-1);
}

int main(int argc, char** argv) {
    std::string outputDir;

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (_stricmp(arg.c_str(), "-o") == 0 && i + 1 < argc) {
            i++;
            outputDir = argv[i];
            continue;
        }

        if (_stricmp(arg.c_str(), "-r") == 0 && i + 1 < argc) {
            i++;
            g_sdkParameters.rootNameSpace = argv[i];
            continue;
        }

        if (_stricmp(arg.c_str(), "-MaxErrors") == 0 && i + 1 < argc) {
            i++;
            try {
                g_MaxErrors = std::stoul(argv[i]);
            } catch (std::invalid_argument) {
                Usage();
            } catch (std::out_of_range) {
                Usage();
            }

            continue;
        }

        // Must be a sdk.args or sdk.headers file.  Extract the sdk name
        // Convert all backslashes to forward slashes
        Helpers::replaceAll(arg, "\\", "/");
        size_t indexSlash = arg.find_last_of("/");
        size_t indexPeriod = arg.find_last_of('.');

        if (indexPeriod == -1 || (indexSlash != -1 && indexPeriod <= indexSlash)) {
            Usage();
        }

        size_t startPos = (indexSlash == -1 ? 0 : indexSlash + 1);
        size_t count = indexPeriod - startPos;
        std::string sdkName(arg, startPos, count);
        if (sdkName.empty()) {
            Usage();
        }

        std::string argFile;
        std::string headerFile;
        size_t index = arg.find(".args");
        if (index != -1) {
            argFile = arg;
        } else {
            index = arg.find(".headers");
            if (index != -1) {
                headerFile = arg;
            }
        }

        auto it = g_sdkParameters.SDKHeaderArgMap.find(sdkName);
        if (it == g_sdkParameters.SDKHeaderArgMap.end()) {
            ClangHelpers::header_argfile haPair(headerFile, argFile);
            g_sdkParameters.SDKHeaderArgMap[sdkName] = haPair;
        } else {
            ClangHelpers::header_argfile& haPair = it->second;
            if (haPair.first.empty()) {
                haPair.first = headerFile;
            } else {
                haPair.second = argFile;
            }
        }
    }

    if (g_sdkParameters.rootNameSpace.empty() || g_sdkParameters.SDKHeaderArgMap.size() == 0 || outputDir.empty()) {
        Usage();
    }

    runTests(outputDir);
    int retCode = 0;
    if (Helpers::Errors::GetErrorCount()) {
        retCode = -1;
    }
    return retCode;
}
