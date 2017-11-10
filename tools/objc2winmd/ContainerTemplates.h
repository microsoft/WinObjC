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

#include <memory>
#include "ClangObjectModel.h"

namespace ContainerTemplates {
std::string generateHeterogeneousCreators(std::shared_ptr<ClangObjectModel::ComponentInfo> comp);
std::string _generateHeterogeneousCreatorForObjC(std::shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info);
std::string _generateHeterogeneousCreatorForRT(std::shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info);

// ObjC Wrapper declarations.
std::string generateObjCWrapperDeclaration(std::shared_ptr<ClangObjectModel::ComponentInfo> comp);
std::string _generateObjCWrapperMethodDeclarations(std::shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info);
std::string _generateObjCWrapperMethodDeclarationsForNSArray(std::shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info);
std::string _generateObjCWrapperMethodDeclarationsForNSDictionary(std::shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info);

// ObjC Wrapper definitions.
std::string generateObjCWrapperDefinition(std::shared_ptr<ClangObjectModel::ComponentInfo> comp);
std::string _generateObjCWrapperMethodDefinitions(std::shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info);
std::string _generateObjCWrapperMethodDefinitionsForNSArray(std::shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info);
std::string _generateObjCWrapperMethodDefinitionsForNSDictionary(std::shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info);
std::string _generateObjCWrapperMethodDefinitionsForNSDictionaryKeyEnumerator(
    std::shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info);
std::string generateObjCMarshallingMethods(std::shared_ptr<ClangObjectModel::ComponentInfo> comp);
std::string _generateObjCMarshallingForPropertyValueTypes(
    std::set<std::shared_ptr<ClangObjectModel::TypeInfo>, ClangObjectModel::TypeInfo> types,
    std::string inspectableObject,
    std::string objectName);
std::string _generateObjCMarshallingForInterfaceTypes(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo,
                                                      std::string inspectableObject,
                                                      std::string objectName);
std::string _generateObjCMarshallingForContainerTypes(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo,
                                                      std::string inspectableObject,
                                                      std::string objectName);

// RT Wrapper declarations.
std::string generateRTWrapperDeclaration(std::shared_ptr<ClangObjectModel::ComponentInfo> comp);
std::string _generateRTWrapperMethodDeclarations(std::shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info);
std::string _generateRTWrapperMethodDeclarationForNSArray(std::shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info);
std::string _generateRTWrapperMethodDeclarationForNSDictionary(std::shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info);

// RT Wrapper definitions.
std::string generateRTWrapperDefinitions(std::shared_ptr<ClangObjectModel::ComponentInfo> comp);
std::string _generateRTWrapperMethodDefinitions(std::shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info);
std::string _generateRTWrapperMethodDefinitionsForNSArray(std::shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info);
std::string _generateRTWrapperMethodDefinitionsForNSDictionary(std::shared_ptr<ClangObjectModel::HeterogeneousContainerInfo> info);
std::string generateRTMarshallingMethods(std::shared_ptr<ClangObjectModel::ComponentInfo> comp);
std::string _generateRTMarshallingForPropertyValueTypes(
    std::set<std::shared_ptr<ClangObjectModel::TypeInfo>, ClangObjectModel::TypeInfo> types, std::string objectName);
std::string _generateRTMarshallingForInterfaceTypes(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo, std::string objectName);
std::string _generateRTMarshallingForContainerTypes(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo, std::string objectName);
}