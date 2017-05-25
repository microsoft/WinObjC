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

#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include "ObjectModel.h"
#include "CommandLine.h"

const std::wstring g_defaultOutputDirectory = L"..\\..\\..\\Projections\\";
const std::wstring g_projectsDirectory = L"projects\\";
const std::wstring g_srcDirectory = L"src\\";
const std::wstring g_nugetProjectDirectory = L"Nuget\\";

class CommandLineInfo {
    static std::wstring _solutionName;
    static CommandLineOptions _options;

    CommandLineInfo() = delete;
    CommandLineInfo(const CommandLineInfo&) = delete;
    void operator=(const CommandLineInfo&) = delete;

public:
    static void Initialize(CommandLineOptions& options, const std::wstring solutionName);

    static bool IsReferenceFile(const std::wstring& file);

    static std::wstring GetAdditionalIncludePaths();

    static std::wstring GetSolutionName();
};

namespace ObjectModel {
struct Symbol;
class Visitor;
}

template <typename RuntimeClassOrInterface>
std::wstring getDefaultInterfaceName(const std::shared_ptr<RuntimeClassOrInterface> cls, FILE* outputFile);
void generateDefExports(const std::vector<std::shared_ptr<ObjectModel::NameSpace>>& namespaces,
                        const std::wstring& fileName,
                        const std::wstring& moduleName);
void generateVCXProj(const std::pair<std::wstring, std::pair<std::wstring, std::vector<std::shared_ptr<ObjectModel::NameSpace>>>>& module,
                     const std::wstring& directoryPath,
                     const std::map<std::wstring, std::shared_ptr<ObjectModel::Symbol>>& types,
                     const std::map<std::wstring, std::pair<std::wstring, std::vector<std::shared_ptr<ObjectModel::NameSpace>>>>& moduleMap,
                     const std::map<std::wstring, std::wstring>& namespaceMap,
                     const std::vector<std::wstring>& nugetDependencies,
                     const std::wstring& solutionName);
void generatePropsFileForPackageable(const std::wstring& outputDirectory, const std::wstring& solutionFileName);
void generateTargetsFileForPackageable(const std::wstring& outputDirectory, const std::wstring& solutionFileName);
void generateSolutionFile(
    const std::map<std::wstring, std::pair<std::wstring, std::vector<std::shared_ptr<ObjectModel::NameSpace>>>>& moduleMap,
    const std::wstring& outputDirectory,
    const std::wstring& solutionFileName,
    const std::pair<std::wstring, std::wstring>& nugetInfo);

// Returns the GUID of the generated nuget project.
std::wstring generateNugetProject(
    const std::map<std::wstring, std::pair<std::wstring, std::vector<std::shared_ptr<ObjectModel::NameSpace>>>>& moduleMap,
    const std::wstring& outputDirectory,
    const std::wstring& nugetPackageId,
    const std::wstring& solutionName);

ObjectModel::Visitor* GetGeneratorVisitor(std::map<std::wstring, std::shared_ptr<ObjectModel::Symbol>>& symMap,
                                          const std::wstring& outDir,
                                          std::map<std::wstring, std::wstring>& namespaceMap);

std::pair<std::map<std::wstring, std::pair<std::wstring, std::vector<std::shared_ptr<ObjectModel::NameSpace>>>>,
          std::map<std::wstring, std::wstring>>
generateModuleGraph(const std::map<std::wstring, std::shared_ptr<ObjectModel::Symbol>>& types,
                    const std::map<std::wstring, std::shared_ptr<ObjectModel::NameSpace>>& convertedNamespaces,
                    bool merge);
std::wstring moduleNameFromNamespace(const std::wstring ns);