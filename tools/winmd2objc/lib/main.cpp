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
#include <DepResolution.h>
#include <CommandLine.h>
#include <CodeGen.h>
#include <Misc.h>
#include <Conversion.h>
#include <objbase.h>

using namespace std;
using namespace ObjectModel;

typedef pair<map<wstring, pair<wstring, vector<shared_ptr<NameSpace>>>>, map<wstring, wstring>> ModuleGraphType;
void _exitIfDirectoryNotCreated(const wstring& path) {
    if (!PathFileExistsW(path.c_str())) {
        wprintf(L"Failed to create directory: %s", path.c_str());
        exit(-1);
    }
}

void _deleteDirectoryContents(const wstring& path) {
    wstring deleteDirectoryContents = L"del /s /q " + path;
    wstring deleteDirectories = L"for /D %p in (" + path + L"*) do rmdir \"%p\" /s /q";
    _wsystem(deleteDirectoryContents.c_str());
    _wsystem(deleteDirectories.c_str());
}

void _createDirectoryStructure(const wstring& path) {
    wstring createCommand = L"mkdir " + path;
    _wsystem(createCommand.c_str());
    _exitIfDirectoryNotCreated(path);

    wstring projectDirectoryPath = path + g_projectsDirectory;
    createCommand = L"mkdir " + projectDirectoryPath;
    _wsystem(createCommand.c_str());
    _exitIfDirectoryNotCreated(projectDirectoryPath);

    wstring nugetProjectDirectory = path + g_projectsDirectory + g_nugetProjectDirectory;
    createCommand = L"mkdir " + nugetProjectDirectory;
    _wsystem(createCommand.c_str());
    _exitIfDirectoryNotCreated(nugetProjectDirectory);

    wstring srcDirectoryPath = path + g_srcDirectory;
    createCommand = L"mkdir " + srcDirectoryPath;
    _wsystem(createCommand.c_str());
    _exitIfDirectoryNotCreated(srcDirectoryPath);
}

void handleNsDomArg(wstring type, MetaDataConvert::NamespaceDomain& nsDom) {
    bool isNs = false;
    bool exclude = false;
    if (*type.rbegin() == L'*') {
        isNs = true;
        type = type.substr(0, type.length() - 1);
    }
    if (type[0] == L'^') {
        exclude = true;
        type = type.substr(1);
    }

    if (isNs) {
        if (exclude) {
            nsDom.rejectNs.insert(type);
        } else {
            nsDom.incNs.insert(type);
        }
    } else {
        if (exclude) {
            nsDom.rejectTypes.insert(type);
        } else {
            nsDom.incTypes.insert(type);
        }
    }
}

void startWinmdConversion(int argc, wchar_t** argv) {
    bool verify = false;
    MetaDataConvert::NamespaceDomain nsDom;
    CommandLineOptions options;

    wprintf(L"Microsoft (R) Objective-C Projections Generator\n");
    wprintf(L"Copyright (c) Microsoft Corporation. All rights reserved.\n");

    if (!parseCommandLine(argc, argv, options)) {
        _exit(1);
    }

    wstring solutionFileName;
    auto val = options.optMap[L"name"];
    if (options.optMap[L"name"].size() == 0) {
        solutionFileName = getSolutionFileNameFromWinmdFile(options.metaDataFileInfo.first);
    } else {
        solutionFileName = options.optMap[L"name"][0];
    }
    CommandLineInfo::Initialize(options, solutionFileName);

    wstring outputDirectory = g_defaultOutputDirectory;
    if (options.optMap[L"output"].size() > 0) {
        outputDirectory = options.optMap[L"output"][0];
    } else {
        wprintf(L"output directory is set to:: %s\n You can specify a output directory via -output option", outputDirectory);
    }

    replaceAll(outputDirectory, L"/", L"\\");
    if (outputDirectory[outputDirectory.length() - 1] != L'\\') {
        outputDirectory += L"\\";
    }
    outputDirectory += solutionFileName + L"\\";
    wstring outputProjectDirectory = outputDirectory + g_projectsDirectory;
    wstring outputSrcDirectory = outputDirectory + g_srcDirectory;

    if (options.optMap[L"r"].size()) {
        wstring responseFile = options.optMap[L"r"][0];
        FILE* respFile = _wfopen(responseFile.c_str(), L"r");

        if (!respFile) {
            wprintf(L"Could not open response file: %s!\n", responseFile.c_str());
            _exit(0);
        }

        wchar_t buff[2048];

        while (fgetws(buff, 2048, respFile)) {
            wstring wbuff(buff);
            wbuff = wbuff.substr(0, wbuff.find_last_not_of(L" \t\n") + 1);
            handleNsDomArg(wbuff, nsDom);
        }

        fclose(respFile);
    }

    _deleteDirectoryContents(outputDirectory);
    _createDirectoryStructure(outputDirectory);

    // Loading all the files fills out the type lookup map
    map<wstring, shared_ptr<Symbol>> symMap;
    map<wstring, shared_ptr<MetaDataConvert>> mdMap;
    unordered_set<shared_ptr<MetaDataConvert>> loadedDeps;
    wstring& metaDataFileName = options.metaDataFileInfo.first;
    std::transform(metaDataFileName.begin(), metaDataFileName.end(), metaDataFileName.begin(), ::tolower);
    if (!PathFileExistsW(metaDataFileName.c_str())) {
        wprintf(L"Source not found: %s\n", metaDataFileName.c_str());
        exit(1);
    }

    shared_ptr<MetaDataConvert> convert(new MetaDataConvert(metaDataFileName, symMap));

    // After this stage convert will have all the namespaces in the current src file.
    // Each of the namespace has all the information about the symbols in it.
    HRESULT hr = convert->ConvertMetaData(nsDom);

    if (FAILED(hr)) {
        wprintf(L"Failed to read metadata\n");
        exit(1);
    }

    mdMap[metaDataFileName] = convert;

    // Resolve further references
    wstring metaDataReferenceDirectory;
    if (options.optMap[L"i"].size()) {
        metaDataReferenceDirectory = options.optMap[L"i"][0];
    }
    ResolveAssemblyRefs(convert, metaDataFileName, metaDataReferenceDirectory, mdMap, symMap, loadedDeps, nsDom);

    for (auto& referFile : options.optMap[L"refer"]) {
        shared_ptr<MetaDataConvert> metaDataConvert(new MetaDataConvert(referFile, symMap));

        // After this stage convert will have all the namespaces in the current src file.
        // Each of the namespace has all the information about the symbols in it.
        HRESULT hr = metaDataConvert->ConvertMetaData(nsDom);
    }

    map<wstring, shared_ptr<NameSpace>> convertedNamespaces;

    // TODO: Single winmd via commandline
    for (auto refConvert : loadedDeps) {
        NamespaceCollector n(convertedNamespaces);
        refConvert->VisitNamespaces(&n);
    }

    // clang-format off
    // At this stage convertedNamespaces containes a copy of all the namespaces from all the loadedDeps.
    // maps is a pair:
    // maps.first: This is a map, mapping project name (ObjCUWP_X_X) to pair {Project GUID, Array of namespaces in this project(contributors)}
    // maps.second: This is a map, mapping the original namespace name to the merged namespace name.
    ModuleGraphType maps;
    if (options.metaDataFileInfo.second) {
        size_t pos = options.metaDataFileInfo.first.find_last_of(L".");
        wstring mergedName = options.metaDataFileInfo.first.substr(0, pos);
        pos = mergedName.find_last_of(L"\\");
        mergedName = mergedName.substr(pos + 1);
        capitalizeFirstLetter(mergedName);
        vector<shared_ptr<ObjectModel::NameSpace>> namespaceArray;
        for (auto& nsInfo : convertedNamespaces) {
            namespaceArray.push_back(nsInfo.second);
            maps.second.insert({ nsInfo.first, moduleNameFromNamespace(mergedName) });
        }

        maps.first.insert({ moduleNameFromNamespace(mergedName), {getGUIDAsString(), namespaceArray } });
    } else {
        maps = generateModuleGraph(symMap, convertedNamespaces, options.metaDataFileInfo.second);
    }
    // clang-format on

    Visitor* v = GetGeneratorVisitor(symMap, outputSrcDirectory, maps.second);

    for (auto ns : convertedNamespaces) {
        v->Visit(ns.second);
    }

    for (const auto& module : maps.first) {
        generateDefExports(module.second.second, outputSrcDirectory + L"\\" + module.first + L"_export.def", module.first);

        if (options.optMap.find(L"p") != options.optMap.end()) {
            generateVCXProj(
                module, outputProjectDirectory + module.first, symMap, maps.first, maps.second, options.optMap[L"nuget"], solutionFileName);
        }
    }
    generatePropsFileForPackageable(outputDirectory, solutionFileName);
    generateTargetsFileForPackageable(outputDirectory, solutionFileName);

    wstring nugetProjectGUID = generateNugetProject(maps.first, outputProjectDirectory + L"Nuget\\", solutionFileName, solutionFileName);
    pair<wstring, wstring> nugetInfo({ solutionFileName, nugetProjectGUID });

    generateSolutionFile(maps.first, outputDirectory, solutionFileName, nugetInfo);

    delete v;

    _exit(0); // Don't call destructors; Needlessly slow.
}
