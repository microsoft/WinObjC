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
#include <algorithm>
#include <memory>
#include <iostream>

using namespace std;

extern ClangHelpers::SDKParameters g_sdkParameters;
extern ClangObjectModel::GlobalData g_globalData;

namespace ClangObjectModel {

std::unordered_map<std::string, std::shared_ptr<ClangObjectModel::InterfaceInfo>> GlobalData::synthesizedInterfaceMap;

std::unordered_map<std::string, std::shared_ptr<ClangObjectModel::InterfaceInfo>> GlobalData::objCSuperClasses = {
    { "UIButton",
      std::make_shared<ClangObjectModel::InterfaceInfo>("UIButton",
                                                        "ABI::Windows::UI::Xaml::Controls::ContentControl",
                                                        "Windows.UI.Xaml.Controls.ContentControl",
                                                        "windows.ui.xaml.controls.idl") }
};

const set<std::string> GlobalData::defaultDependentIdls = { "inspectable.idl", "windows.foundation.idl" };

std::unordered_map<std::string, std::shared_ptr<ClangObjectModel::InterfaceInfo>> GlobalData::_objCFrameworkInterfaces =
    { { "nsdate",
        std::make_shared<ClangObjectModel::InterfaceInfo>("NSDate",
                                                          "ABI::Windows::Foundation::DateTime",
                                                          "Windows.Foundation.DateTime",
                                                          "windows.foundation.idl") },

      // Our AST parser will convert NSURL to either StorageFile or URI or both.
      { "storagefile",
        std::make_shared<ClangObjectModel::InterfaceInfo>("NSURL",
                                                          "ABI::Windows::Storage::IStorageFile*",
                                                          "Windows.Storage.StorageFile*",
                                                          "windows.storage.idl") },
      { "uri",
        std::make_shared<ClangObjectModel::InterfaceInfo>("NSURL",
                                                          "ABI::Windows::Foundation::IUriRuntimeClass*",
                                                          "Windows.Foundation.Uri*",
                                                          "windows.foundation.idl") } };

// maps the container name to number of template types for it.
// e.g. array has a single tempate type.
//      dictionary is a key-value pair.
static std::map<std::string, int> supportedHeterogeneousTypes = { { "NSArray", 1 }, { "NSDictionary", 2 } };

static std::set<std::string> idlKeywords = {
    // This is not an exhaustive list of IDL keywords, this set just represents names which have a high
    // probability (ad-hoc) of collision.
    // If we ever encounter a name which is not allowed in IDL it will be added here on
    // a case-by-case basis.
    "aggregatable", "allocate", "annotate", "appobject", "arrays", "async", "delegate", "interface", "source",
    "range",        "proxy",    "ptr",      "ref",       "shape",  "small", "version",  "in",        "properties"
};

string MetaDataComments::_parseTemplateArgumentTypes(const std::string& line,
                                                     const std::string typeString,
                                                     const std::string& objCContainerName) {
    auto it = supportedHeterogeneousTypes.find(objCContainerName);
    if (it == supportedHeterogeneousTypes.end()) {
        return typeString;
    }

    int expectedNumberOfTemplateArguments = it->second;

    // Get the entire string between '<' and '>'
    vector<string> templateTypes = Helpers::getStringBetweenSymbols(typeString, '<', '>', true);

    // Check if the templateTypes provided require a heterogeneous container.
    size_t pos = templateTypes[0].find(possibleTypesStartSymbol);
    if (pos == templateTypes[0].npos) {
        // Non-heterogeneous type
        return typeString;
    }

    vector<string> valueTypes;
    if (expectedNumberOfTemplateArguments == 2) {
        // separate key types and value types if they exist.
        templateTypes = Helpers::separateKeyAndValueTypes(templateTypes[0], pos);
        if (pos == templateTypes[0].npos) {
            Helpers::Errors::WriteError(nullptr, "Invalid metadata provided: " + line, false);
        }

        valueTypes.push_back(templateTypes[1]);
        templateTypes.pop_back();
    }

    // Heterogeneous type
    // We return the name of the generated heterogeneous container.
    // Step1: Tokenize everything between possibleTypesStartSymbol and possibleTypesEndSymbol as COMPLETE individual types.
    // e.g. NSDictionary<[int|NSArray<[int | float]>], [NSArray<[MyInterface* | int]>|char]> should be tokenized as:
    // KeyTypes:
    // int
    // NSArray<[int | float]>
    // ValueTypes:
    // NSArray<[MyInterface* | int]>
    // char
    vector<string> possibleKeyTypes =
        Helpers::getStringBetweenSymbols(templateTypes[0], possibleTypesStartSymbol, possibleTypesEndSymbol, true);
    possibleKeyTypes = ClangHelpers::tokenize_CompleteTypes(possibleKeyTypes[0]);
    if (possibleKeyTypes.size() == 0) {
        Helpers::Errors::WriteError(nullptr, "Invalid metadata provided: " + line, false);
    }

    vector<string> possibleValueTypes;
    if (expectedNumberOfTemplateArguments == 2) {
        possibleValueTypes = Helpers::getStringBetweenSymbols(valueTypes[0], possibleTypesStartSymbol, possibleTypesEndSymbol, true);
        possibleValueTypes = ClangHelpers::tokenize_CompleteTypes(possibleValueTypes[0]);

        if (possibleValueTypes.size() == 0) {
            Helpers::Errors::WriteError(nullptr, "Invalid metadata provided: " + line, false);
        }
    }

    // Step2: Get the parsed/processed names for each complete type.
    auto uniqueKeyTypes = _parsePossibleTypes(line, possibleKeyTypes, true);
    vector<string> keyTypeSpellings(uniqueKeyTypes.begin(), uniqueKeyTypes.end());

    set<string> uniqueValueTypes;
    vector<string> valueTypeSpellings;
    if (expectedNumberOfTemplateArguments == 2) {
        uniqueValueTypes = _parsePossibleTypes(line, possibleValueTypes, true);
        valueTypeSpellings.assign(uniqueValueTypes.begin(), uniqueValueTypes.end());
    }

    // Step3: Generate HeterogeneousContainerInfo for this type.
    // Check if we have a heterogeneous container which can take care of all the current required types.
    // Note: this does not take care of the scenario when the current type is a super-set of the an existing heterogeneous container.
    // ToDo: Handle above case to reduce memory footprint.
    for (auto containerMap : g_globalData.currentComponent->heterogeneousContainers) {
        bool allTypesAreHandled = true;
        auto heterogeneousInfo = containerMap.second;
        for (auto expectedType : keyTypeSpellings) {
            if (heterogeneousInfo->types.find(expectedType) == heterogeneousInfo->types.end()) {
                allTypesAreHandled = false;
                break;
            }
        }

        if (!allTypesAreHandled) {
            continue;
        }

        for (auto expectedType : valueTypeSpellings) {
            if (heterogeneousInfo->valueTypes.find(expectedType) == heterogeneousInfo->valueTypes.end()) {
                allTypesAreHandled = false;
                break;
            }
        }

        if (allTypesAreHandled) {
            // All types are taken care of by a previous Heterogeneous container, so no need to create a new type.
            // We will be using the previously generated heterogeneous container for the current heterogeneous type.
            return containerMap.first;
        }
    }

    // None of the previously generated heterogeneous container types can handle all the required types.
    // Here we create a new heterogeneous container type which can handle all of them.
    string name = g_globalData.currentComponent->getSDKName() + g_globalData.currentComponent->SDKHeaderFile + "HeterogeneousContainer" +
                  objCContainerName + to_string(g_globalData.currentComponent->heterogeneousContainers.size());
    shared_ptr<HeterogeneousContainerInfo> info = make_shared<HeterogeneousContainerInfo>();
    info->name = name;
    info->objCContainerName = objCContainerName;
    auto ci = TypeConvertor::GetContainerInfo(objCContainerName);
    info->wrlContainerName = ci->WRLName;
    if (expectedNumberOfTemplateArguments == 2) {
        info->wrlTemplateParams = "IInspectable*, IInspectable*";
    } else {
        info->wrlTemplateParams = "IInspectable*";
    }
    info->types.clear();
    info->types.insert(keyTypeSpellings.begin(), keyTypeSpellings.end());
    info->valueTypes.insert(valueTypeSpellings.begin(), valueTypeSpellings.end());

    // Make sure we generate the necessary typeInfo values for each contained type and
    // have the necessary ObjC convertors generated.
    for (auto typeName : info->types) {
        auto typeInfo = make_shared<ClangObjectModel::TypeInfo>();
        typeInfo->setTypeSpelling(typeName);
        typeInfo->ResolveParameterType(typeName);
        info->typesInfo.push_back(std::move(typeInfo));
    }
    for (auto typeName : info->valueTypes) {
        auto typeInfo = make_shared<ClangObjectModel::TypeInfo>();
        typeInfo->setTypeSpelling(typeName);
        typeInfo->ResolveParameterType(typeName);
        info->valueTypesInfo.push_back(std::move(typeInfo));
    }

    info->toObjCConvertor = "_Get" + info->name + "ForObjC";
    info->toWRLConvertor = "_Get" + info->name + "ForRT";

    g_globalData.currentComponent->heterogeneousContainers.insert({ info->name, info });

    // Step4: Return the name of the generated HeterogenerousContainer
    return info->name;
}

string MetaDataComments::_getContainerTypeSpellingForSet(const std::string& line, const std::string typeString) {
    return _parseTemplateArgumentTypes(line, typeString, "NSSet");
}

string MetaDataComments::_getContainerTypeSpellingForDictionary(const std::string& line, const std::string typeString) {
    return _parseTemplateArgumentTypes(line, typeString, "NSDictionary");
}

string MetaDataComments::_getContainerTypeSpellingForArray(const std::string& line, const std::string typeString) {
    return _parseTemplateArgumentTypes(line, typeString, "NSArray");
}

string MetaDataComments::_getContainerTypeSpelling(const std::string& line, const std::string typeString) {
    // typeString is of container type e.g. NSArray<int> or NSArray<[int | float]> etc.

    string containerName = Helpers::getContainerName(typeString);

    if (containerName == "NSArray") {
        return _getContainerTypeSpellingForArray(line, typeString);
    } else if (containerName == "NSDictionary") {
        return _getContainerTypeSpellingForDictionary(line, typeString);
    } else if (containerName == "NSSet") {
        return _getContainerTypeSpellingForSet(line, typeString);
    }

    // Could be an object with protocol conformance e.g. id<Protocol>
    return typeString;
}

string MetaDataComments::_getTypeSpelling(const std::string& line, const std::string typeString) {
    // typeString could be a simple type like 'int' or a container type like 'NSArray<...>'
    if (TypeConvertor::isGeneric(typeString)) {
        // typeString is of container type.
        return _getContainerTypeSpelling(line, typeString);
    } else {
        return typeString;
    }
}

set<string> MetaDataComments::_parsePossibleTypes(const string& line, vector<string> types, bool isWithinHeterogeneousContainer) {
    set<string> ret;
    // At this time we have types spellings as provided by user in vector 'types'.

    vector<string> typesCopy(types.begin(), types.end());
    types.clear();
    map<string, string> typeMap;
    // Merge similar types
    size_t count = typesCopy.size();
    for (size_t i = 0; i < count; i++) {
        if (!TypeConvertor::isGeneric(typesCopy[i])) {
            types.push_back(typesCopy[i]);
            continue;
        }

        string containerName = Helpers::getContainerName(typesCopy[i]);
        if (supportedHeterogeneousTypes.find(containerName) == supportedHeterogeneousTypes.end()) {
            types.push_back(typesCopy[i]);
            continue;
        }

        // Get everything between '<' and '>'
        vector<string> templateTypes = Helpers::getStringBetweenSymbols(typesCopy[i], '<', '>', true);

        // If this is a dictionary then there are two sets of possible types:
        // one for key and the other for value.
        size_t pos;
        vector<string> valueTypes;
        templateTypes = Helpers::separateKeyAndValueTypes(templateTypes[0], pos);
        if (pos != templateTypes[0].npos) {
            valueTypes.push_back(templateTypes[1]);
            templateTypes.pop_back();
        }

        // Get everything between possibleTypesStartSymbol and possibleTypesEndSymbol
        templateTypes = Helpers::getStringBetweenSymbols(templateTypes[0], possibleTypesStartSymbol, possibleTypesEndSymbol, true);
        if (valueTypes.size()) {
            valueTypes = Helpers::getStringBetweenSymbols(valueTypes[0], possibleTypesStartSymbol, possibleTypesEndSymbol, true);
        }

        if ((templateTypes[0].find(possibleTypesSeparator) == templateTypes[0].npos) && !isWithinHeterogeneousContainer &&
            ((valueTypes.size() == 0) || (valueTypes[0].find(possibleTypesSeparator) == valueTypes[0].npos))) {
            // This is a normal container and so should not be merged with our heterogeneous container.
            types.push_back(typesCopy[i]);
            continue;
        }

        auto it = typeMap.find(containerName);
        if (it != typeMap.end()) {
            string templateString = it->second;
            if (!templateString.empty()) {
                templateString = string(" ") + possibleTypesSeparator + " " + templateString;
            }
            templateString = templateTypes[0] + templateString;

            if (valueTypes.size()) {
                templateString = templateString + " " + possibleTypesSeparator + " " + valueTypes[0];
            }

            it->second = templateString;
        } else {
            if (valueTypes.size()) {
                typeMap.insert({ containerName, templateTypes[0] + ", " + valueTypes[0] });
            } else {
                typeMap.insert({ containerName, templateTypes[0] });
            }
        }
    }

    auto typeMapIt = typeMap.begin();
    while (typeMapIt != typeMap.end()) {
        if (typeMapIt->second.length()) {
            if (typeMapIt->second.find(possibleTypesSeparator) != typeMapIt->second.npos) {
                size_t pos;
                vector<string> keyValueTypes = Helpers::separateKeyAndValueTypes(typeMapIt->second, pos);
                if (pos != typeMapIt->second.npos) {
                    string keyTypes = keyValueTypes[0];
                    string valueTypes = keyValueTypes[1];
                    typeMapIt->second = keyTypes + "], [" + valueTypes;
                }
                types.push_back(typeMapIt->first + "<[" + typeMapIt->second + "]>");
            } else {
                types.push_back(typeMapIt->first + "<" + typeMapIt->second + ">");
            }
        } else {
            types.push_back(typeMapIt->first);
        }

        typeMapIt++;
    }

    auto it = types.begin();
    while (it != types.end()) {
        string typeSpelling = _getTypeSpelling(line, *it);
        ret.insert(typeSpelling);
        it++;
    }

    return ret;
}

void MetaDataComments::_parseTypes(const string& line, vector<string>& argInfo, size_t startId, MetaDataComments::MetaData& info) {
    size_t lastId = argInfo.size() - 1;
    if (startId > lastId) {
        Helpers::Errors::WriteError(nullptr, "Incorrect metadata provided", false);
    }

    // Each entry of argInfo could be a simple type type like 'int' or a container type like 'NSArray<...>'
    std::string nextToken = argInfo[startId];

    size_t count = argInfo.size();
    std::transform(argInfo[startId].begin(), argInfo[startId].end(), nextToken.begin(), ::tolower);
    auto it = argInfo.begin();
    std::advance(it, startId);
    if (nextToken == MetaDataType_PossibleTypes) {
        std::advance(it, 1);
    } else if (count - startId == 1) {
        // There is just one type.
        // Check if the type provided requires a heterogeneous container.
        bool isHeterogeneous = false;
        for (size_t i = startId; i < count; i++) {
            size_t pos = argInfo[i].find(possibleTypesStartSymbol);
            if (pos != argInfo[i].npos) {
                isHeterogeneous = true;
                break;
            }
        }

        if (!isHeterogeneous) {
            info.typesSpelling.push_back(argInfo[startId]);
            return;
        }
    }

    vector<string> types(it, argInfo.end());
    auto uniqueTypes = _parsePossibleTypes(line, types, forceHeterogeneousContainerGeneration);
    info.typesSpelling.assign(uniqueTypes.begin(), uniqueTypes.end());
}

void MetaDataComments::_processRawComments(const std::string& rawComments) {
    std::vector<std::string> lines;
    tokenize(rawComments, lines, "\r\n", "", "\"", "", "", false, false);
    for (auto line : lines) {
        Helpers::replaceAll(line, "/**", "");
        Helpers::replaceAll(line, "/*!", "");
        Helpers::replaceAll(line, "*/", "");
        if (line == "") {
            continue;
        }

        // We need the default string for typespelling as our applyMetaData function
        // loops through the typespellings, with an empty set no metadata will be applied.
        MetaData info = { "", -1, -1, {} };
        std::vector<std::string> argInfo;
        argInfo.clear();
        tokenize(line, argInfo, ":\r\n\\", "", "\"", "", "", false, false);
        if (argInfo.size() == 0) {
            continue;
        }

        std::string metaDataFor = argInfo[0];
        // Remove anything after '#'
        size_t pos = metaDataFor.find('#');
        if (pos != metaDataFor.npos) {
            metaDataFor = metaDataFor.substr(0, pos + 1);
        }

        std::transform(metaDataFor.begin(), metaDataFor.end(), metaDataFor.begin(), ::tolower);

        info.metaDataType = metaDataFor;
        if (metaDataFor == MetaDataType_ReturnType) {
            _parseTypes(line, argInfo, 1, info);
            _metaDataInfo.push_back(info);
        } else if (metaDataFor == MetaDataType_ApplicationDelegate || metaDataFor == MetaDataType_DelegateAllocator ||
                   metaDataFor == MetaDataType_DelegateInitializer || metaDataFor == MetaDataType_DelegateAllocatorAndInitializer) {
            info.typesSpelling.push_back("");
            _metaDataInfo.push_back(info);
        } else if (metaDataFor == MetaDataType_Parameter) {
            std::stringstream stream;
            stream << argInfo[0].substr(Len_MetaDataKind);
            stream >> info.parameterNumber;

            // Convert to zero based.
            info.parameterNumber--;

            std::string tag = argInfo[1].substr(0, std::min<int>(Offset_BlockParamNumber, argInfo[1].length()));
            std::transform(tag.begin(), tag.end(), tag.begin(), ::tolower);
            if (tag == MetaDataType_BlockParameter) {
                stream.clear();
                stream << argInfo[1].substr(Offset_BlockParamNumber);
                stream >> info.blockParamNumber;

                // Convert to zero based.
                info.blockParamNumber--;

                _parseTypes(line, argInfo, 2, info);
            } else {
                _parseTypes(line, argInfo, 1, info);
            }
            _metaDataInfo.push_back(info);
        } else if (metaDataFor == MetaDataType_Property) {
            _parseTypes(line, argInfo, 1, info);
            _metaDataInfo.push_back(info);
        } else if (metaDataFor == MetaDataType_IgnoreDecl) {
            _metaDataInfo.push_back(info);
        } else if (metaDataFor == MetaDataType_BlockParameter) {
            // Typedef declaration for blocks
            std::stringstream stream;
            stream << argInfo[0].substr(Offset_BlockParamNumber);
            stream >> info.blockParamNumber;

            // Convert to zero based.
            info.blockParamNumber--;

            _parseTypes(line, argInfo, 1, info);
            _metaDataInfo.push_back(info);
        } else if (metaDataFor == MetaDataType_Async) {
            info.typesSpelling.push_back("");
            _metaDataInfo.push_back(info);
        } else if (metaDataFor == MetaDataType_DelegateCallbackProtocol) {
            info.typesSpelling.push_back("");
            _metaDataInfo.push_back(info);
        } else if (metaDataFor == MetaDataType_GeneratesNotification) {
            _parseTypes(line, argInfo, 1, info);
            g_globalData.requiresNSNotificationMarshalling = true;
            for (auto typeSpelling : info.typesSpelling) {
                g_globalData.notifications.insert(typeSpelling);
            }
        }
    }
}

MetaDataComments::MetaDataComments(CXCursor cursor, bool forceHeterogeneous) : forceHeterogeneousContainerGeneration(forceHeterogeneous) {
    std::string rawCommentsText = ClangHelpers::GetRawCommentText(cursor);
    if (rawCommentsText != "") {
        _processRawComments(rawCommentsText);
    }
}

size_t MetaDataComments::getMetaDataSize() {
    return _metaDataInfo.size();
}

std::string MetaDataComments::getMetaDataType(size_t index) {
    if (index >= _metaDataInfo.size()) {
        return "";
    }

    return _metaDataInfo[index].metaDataType;
}

void MetaDataComments::setMetaDataType(size_t index, const std::string& metaDataType) {
    if (index >= _metaDataInfo.size()) {
        return;
    }

    _metaDataInfo[index].metaDataType = metaDataType;
}

// Returns -1 in case we do not have this field
int MetaDataComments::getParameterNumber(size_t index) {
    if (index >= _metaDataInfo.size()) {
        return -1;
    }

    return _metaDataInfo[index].parameterNumber;
}

string MetaDataComments::getReturnMetaData(int index) {
    for (size_t i = 0; i < getMetaDataSize(); i++) {
        std::string metaDataFor = getMetaDataType(i);

        if (metaDataFor == ClangObjectModel::MetaDataType_ReturnType) {
            return getTypes(i)[index];
            break;
        }
    }

    return "";
}

string MetaDataComments::getParameterMetaData(int parameterNumber, int index) {
    for (size_t i = 0; i < getMetaDataSize(); i++) {
        std::string metaDataFor = getMetaDataType(i);

        if (metaDataFor == ClangObjectModel::MetaDataType_Parameter) {
            if (parameterNumber == getParameterNumber(i)) {
                return getTypes(i)[index];
                break;
            }
        }
    }

    return "";
}

string MetaDataComments::getBlockParameterMetaData(int parameterNumber, int blockParameterNumber, int index) {
    for (size_t i = 0; i < getMetaDataSize(); i++) {
        std::string metaDataFor = getMetaDataType(i);

        if (metaDataFor == ClangObjectModel::MetaDataType_Parameter) {
            if (parameterNumber == getParameterNumber(i)) {
                if (blockParameterNumber == getBlockParameterNumber(i)) {
                    return getTypes(i)[index];
                    break;
                }
            }
        }
    }
    return "";
}

bool MetaDataComments::blockParameterHasMetaData(int parameterNumber, int blockParameterNumber) {
    bool hasMetaData = false;
    for (size_t i = 0; i < getMetaDataSize(); i++) {
        if (getMetaDataType(i) == ClangObjectModel::MetaDataType_Parameter) {
            if (parameterNumber == getParameterNumber(i)) {
                if (blockParameterNumber == getBlockParameterNumber(i)) {
                    hasMetaData = true;
                    break;
                }
            }
        }
    }

    return hasMetaData;
}

bool MetaDataComments::blockParameterHasMetaData(int blockParameterNumber) {
    bool hasMetaData = false;
    for (size_t i = 0; i < getMetaDataSize(); i++) {
        if (getMetaDataType(i) == ClangObjectModel::MetaDataType_BlockParameter) {
            if (blockParameterNumber == getBlockParameterNumber(i)) {
                hasMetaData = true;
                break;
            }
        }
    }

    return hasMetaData;
}

bool MetaDataComments::parameterHasMetaData(int parameterNumber) {
    bool hasMetaData = false;
    for (size_t i = 0; i < getMetaDataSize(); i++) {
        if (getMetaDataType(i) == ClangObjectModel::MetaDataType_Parameter) {
            hasMetaData = true;
            break;
        }
    }

    return hasMetaData;
}

bool MetaDataComments::hasAsyncMetaData() {
    bool hasAsyncMetaData = false;

    for (size_t i = 0; i < getMetaDataSize(); i++) {
        std::string metaDataFor = getMetaDataType(i);

        if (metaDataFor == ClangObjectModel::MetaDataType_Async) {
            hasAsyncMetaData = true;
            break;
        }
    }
    return hasAsyncMetaData;
}

void MetaDataComments::setParameterNumber(size_t index, int number) {
    if (index >= _metaDataInfo.size()) {
        return;
    }

    _metaDataInfo[index].parameterNumber = number;
}

// Returns -1 in case we do not have this field
int MetaDataComments::getBlockParameterNumber(size_t index) {
    if (index >= _metaDataInfo.size()) {
        return -1;
    }

    return _metaDataInfo[index].blockParamNumber;
}

void MetaDataComments::setBlockParameterNumber(size_t index, int number) {
    if (index >= _metaDataInfo.size()) {
        return;
    }

    _metaDataInfo[index].blockParamNumber = number;
}

vector<string> MetaDataComments::getTypes(size_t index) {
    if (index >= _metaDataInfo.size()) {
        return {};
    }

    return _metaDataInfo[index].typesSpelling;
}

void MetaDataComments::setTypes(size_t index, vector<string> types) {
    if (index >= _metaDataInfo.size()) {
        return;
    }

    _metaDataInfo[index].typesSpelling = types;
}

bool MetaDataComments::isIgnoredType() {
    size_t size = getMetaDataSize();
    for (size_t i = 0; i < size; i++) {
        if (getMetaDataType(i) == MetaDataType_IgnoreDecl) {
            return true;
        }
    }

    return false;
}

bool MetaDataComments::isApplicationDelegate() {
    size_t size = getMetaDataSize();
    for (size_t i = 0; i < size; i++) {
        if (getMetaDataType(i) == MetaDataType_ApplicationDelegate) {
            return true;
        }
    }
    return false;
}

bool MetaDataComments::isDelegateCallbackProtocol() {
    size_t size = getMetaDataSize();
    for (size_t i = 0; i < size; i++) {
        if (getMetaDataType(i) == MetaDataType_DelegateCallbackProtocol) {
            return true;
        }
    }
    return false;
}

void MetaDataComments::appendMetaData(const std::string& type, int paramNumber, int blockNumber, vector<string>& types) {
    MetaData info = { type, paramNumber, blockNumber, std::move(types) };
    _metaDataInfo.push_back(info);
}

map<string, shared_ptr<HeterogeneousContainerInfo>>::iterator ComponentInfo::getHeterogeneousContainerInfo(
    std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo) {
    auto it = heterogeneousContainers.find(typeInfo->getTypeSpelling());
    if (it == heterogeneousContainers.end()) {
        Helpers::Errors::WriteError(typeInfo->sourceLocation, "Failed to find heterogeneous container information", false);
    }

    return it;
}

void ComponentInfo::clearAll() {
    delegates.clear();
    asyncClasses.clear();
    typedefDecl.clear();
    referencedInterfaces.clear();
    referencedProtocols.clear();
}

void addObjcCreatorFuncsFromType(std::shared_ptr<ClangObjectModel::TypeInfo> typeInfo,
                                 std::unordered_map<std::string, std::shared_ptr<ClangObjectModel::TypeInfo>>& objCCreatorFuncs) {
    for (const auto& funcs : typeInfo->objCCreatorFunc) {
        objCCreatorFuncs.insert({ funcs.first, funcs.second });
    }

    for (const auto& templateParam : typeInfo->templateParams) {
        addObjcCreatorFuncsFromType(templateParam, objCCreatorFuncs);
    }
}

void addObjcCreatorFuncsFromParameter(std::shared_ptr<ClangObjectModel::ParameterInfo> paramInfo,
                                      std::unordered_map<std::string, std::shared_ptr<ClangObjectModel::TypeInfo>>& objCCreatorFuncs) {
    addObjcCreatorFuncsFromType(paramInfo->typeInfo, objCCreatorFuncs);

    for (const auto& delegateParam : paramInfo->delegateParams) {
        addObjcCreatorFuncsFromType(delegateParam, objCCreatorFuncs);
    }
}

void addObjcCreatorFuncsFromMethods(std::vector<std::shared_ptr<ClangObjectModel::MethodInfo>>& methods,
                                    std::unordered_map<std::string, std::shared_ptr<ClangObjectModel::TypeInfo>>& objCCreatorFuncs) {
    for (const auto& method : methods) {
        for (const auto& param : method->params) {
            addObjcCreatorFuncsFromParameter(param, objCCreatorFuncs);
        }
        addObjcCreatorFuncsFromParameter(method->returnType, objCCreatorFuncs);
    }
}

// This function returns all the types (TypeInfo) that have ObjcCreatorFuncs in the component.
std::unordered_map<std::string, std::shared_ptr<ClangObjectModel::TypeInfo>> ComponentInfo::getObjcCreatorFuncs() {
    std::unordered_map<std::string, std::shared_ptr<ClangObjectModel::TypeInfo>> objCCreatorFuncs;
    for (auto& heterogeneousIt : heterogeneousContainers) {
        for (auto& typeIt : heterogeneousIt.second->typesInfo) {
            addObjcCreatorFuncsFromType(typeIt, objCCreatorFuncs);
        }

        for (auto& typeIt : heterogeneousIt.second->valueTypesInfo) {
            addObjcCreatorFuncsFromType(typeIt, objCCreatorFuncs);
        }
    }

    for (const auto& iface : this->ifaces) {
        addObjcCreatorFuncsFromMethods(iface.second->instanceMethods, objCCreatorFuncs);
        addObjcCreatorFuncsFromMethods(iface.second->classMethods, objCCreatorFuncs);
        addObjcCreatorFuncsFromMethods(iface.second->parameterizedInitMethods, objCCreatorFuncs);

        for (const auto& protocols : iface.second->getProtocolsImplemented()) {
            std::unordered_map<std::string, std::shared_ptr<ClangObjectModel::TypeInfo>> protocolObjCCreatorFuncs;
            addObjcCreatorFuncsFromMethods(protocols->instanceMethods, protocolObjCCreatorFuncs);
            for (const auto& func : protocolObjCCreatorFuncs) {
                // For Protocols, we need to adjust the ObjcCreatorName to be contain the name of the
                // class that implements the protocol.
                objCCreatorFuncs.insert({ TypeConvertor::GetObjCTypeCreatorName(func.second), func.second });
            }
        }
    }

    return std::move(objCCreatorFuncs);
}

template <class T>
void AddOrUpdateReference(const std::string& referencedSymbol,
                          bool isInterface,
                          std::shared_ptr<ClangObjectModel::ComponentInfo>& component,
                          std::unordered_map<std::string, std::shared_ptr<T>>& resolvedSymbolsMap,
                          std::unordered_multimap<std::string, std::shared_ptr<ClangObjectModel::ComponentInfo>>& unresolvedSymbols) {
    // baseType is the symbol without any pointers (*).  Eg. if referencedSymbol=Foo * then baseType=Foo
    string baseType = Helpers::Trim(Helpers::baseType(referencedSymbol));

    // search this name in our resolved interfaces from other SDKs
    auto it = resolvedSymbolsMap.find(baseType);
    if (it == resolvedSymbolsMap.end()) {
        // We have not seen this interface in any SDK.  Leave it as unresolved.
        unresolvedSymbols.insert({ baseType, component });
    } else {
        std::string namespaceString = ClangHelpers::generateNamespaceString(it->second->getSDKName(), ".");

        if (component->SDKHeaderFile != it->second->SDKHeaderFile) {
            // We've visited this interface in another SDK. Add it to our dependent IDLs
            component->referencedIDLs.insert(namespaceString + "." + it->second->SDKHeaderFile + ".idl");
        }

        if (isInterface) {
            component->referencedInterfaces.insert(namespaceString + "." + it->second->SDKHeaderFile + "." + baseType);
        } else {
            component->referencedProtocols.insert(namespaceString + "." + it->second->SDKHeaderFile + "." + baseType);
        }
    }
}

void ComponentInfo::AddReferenceToInterface(const std::string& interfaceName) {
    AddOrUpdateReference<ClangObjectModel::InterfaceInfo>(interfaceName,
                                                          true,
                                                          shared_from_this(),
                                                          g_globalData.interfaceMap,
                                                          g_globalData.unresolvedInterfaces);
}

void ComponentInfo::AddReferenceToProtocol(const std::string& protocolName) {
    AddOrUpdateReference<ClangObjectModel::ProtocolInfo>(protocolName,
                                                         false,
                                                         shared_from_this(),
                                                         g_globalData.protocolMap,
                                                         g_globalData.unresolvedProtocols);
}

void TypeInfo::updateObjCCreatorFunctionName(std::string methodName,
                                             const std::shared_ptr<ClangObjectModel::TypeInfo>& typeInfo,
                                             std::string removeMethod) {
    if (!removeMethod.empty()) {
        // With id type marshalling we generate new typeInfo for the method parameters.
        // This makes any previous typeInfo data in per ComponentInfo storage redundant and incorrect.
        // We remove any previous typeInfo based ObjC creator functions.
        auto it = objCCreatorFunc.find(removeMethod);
        if (it != objCCreatorFunc.end()) {
            objCCreatorFunc.erase(it);
        }
    }

    if (!methodName.empty()) {
        objCCreatorFunc.insert({ methodName, typeInfo });
    }
}

std::string Symbol::getSDKName() {
    return this->SDKname;
}

std::string TypeInfo::getSDKName() {
    string sdkName = this->SDKname;
    // downcast is necessary
    if (ClangHelpers::isInterface(this->getTypeSpelling())) {
        auto it = g_globalData.interfaceMap.find(Helpers::baseType(this->getTypeSpelling()));
        if (it == g_globalData.interfaceMap.end()) {
            std::string err = "Unresolved symbol referenced: " + this->getTypeSpelling();
            Helpers::Errors::WriteError(nullptr, err.c_str(), true);
        }

        sdkName = it->second->SDKname;
    }

    return sdkName;
}

std::string ParameterInfo::getSDKName() {
    return this->typeInfo->getSDKName();
}

void TypeInfo::setTypeSpelling(const std::string& spelling) {
    _typeSpelling = spelling;
    if (isNSDateType()) {
        g_globalData.requiresNSDateMarshalling = true;
    } else if (_stricmp(_typeSpelling.c_str(), "jsontype") == 0) {
        _typeSpelling = "id";
        g_globalData.requiresJSONMarshalling = true;
        cachedSymbolKind = ClangObjectModel::JSONType;
    } else if (isNSURLType()) {
        std::shared_ptr<ClangObjectModel::InterfaceInfo> iface = g_globalData.GetObjCFrameworkInterfaces(this->_typeSpelling);
        string refIdlFile = iface->GetIdlFileName();
        g_globalData.currentComponent->referencedIDLs.insert(refIdlFile);
        g_globalData.requiresNSURLMarshalling = true;
    }
}

string TypeInfo::getTypeSpelling(bool baseType) {
    if (baseType) {
        return Helpers::Trim(Helpers::baseType(_typeSpelling, true));
    }

    return _typeSpelling;
}

string TypeInfo::getTypeSpellingLowerCase(bool baseType) {
    string typeString = getTypeSpelling(baseType);
    string retString = typeString;

    ::transform(typeString.begin(), typeString.end(), retString.begin(), ::tolower);
    return retString;
}

void TypeInfo::setTypeName(const string& nameString) {
    string baseName = Helpers::Trim(nameString);
    if (idlKeywords.find(baseName) != idlKeywords.end()) {
        baseName = "_" + baseName + "_";
    }

    _name = baseName;
}

string TypeInfo::getTypeName() {
    return _name;
}

bool TypeInfo::operator()(const std::shared_ptr<TypeInfo>& t1, const std::shared_ptr<TypeInfo>& t2) {
    return (strcmp(t1->getTypeSpelling(true).c_str(), t2->getTypeSpelling(true).c_str()) < 0);
}

ClangObjectModel::SymbolKind TypeInfo::getSymbolKind() {
    if (cachedSymbolKind != ClangObjectModel::SymbolKind::Unknown) {
        return cachedSymbolKind;
    }

    if (isNativeType()) {
        cachedSymbolKind = ClangObjectModel::SymbolKind::NativeType;
    } else if (isContainer()) {
        cachedSymbolKind = ClangObjectModel::SymbolKind::ContainerType;
    } else if (isInterface()) {
        cachedSymbolKind = ClangObjectModel::SymbolKind::IntefaceType;
    } else if (isEnumType()) {
        cachedSymbolKind = ClangObjectModel::SymbolKind::EnumType;
    }

    return cachedSymbolKind;
}

bool TypeInfo::hasBaseWinRTRepresentation() {
    if (isContainer() || getTypeSpelling(true) == "NSError" || getSymbolKind() == JSONType) {
        return true;
    }

    return false;
}

bool TypeInfo::isContainer() {
    if (TypeConvertor::GetContainerInfo(_typeSpelling) != nullptr || isHeterogeneous) {
        return true;
    }

    return false;
}

bool TypeInfo::isInterface() {
    return ClangHelpers::isInterface(this->_typeSpelling);
}

bool TypeInfo::isProtocol() {
    return ClangHelpers::isProtocol(this->_typeSpelling);
}

bool TypeInfo::isEnumType() {
    if (typeKind == CXType_Enum) {
        return true;
    }

    return false;
}

bool TypeInfo::isNSDateType() {
    string baseType = Helpers::Trim(Helpers::baseType(_typeSpelling, true));

    auto frameworkInterface = g_globalData.GetObjCFrameworkInterfaces(baseType);
    if (frameworkInterface != nullptr && frameworkInterface->name == "NSDate") {
        return true;
    }
    return false;
}

bool TypeInfo::isNSURLType() {
    string baseType = Helpers::Trim(Helpers::baseType(_typeSpelling, true));

    auto frameworkInterface = g_globalData.GetObjCFrameworkInterfaces(baseType);
    if (frameworkInterface != nullptr && frameworkInterface->name == "NSURL") {
        return true;
    }
    return false;
}

bool TypeInfo::isNativeType() {
    string baseType = Helpers::Trim(Helpers::baseType(_typeSpelling, true));
    if (TypeConvertor::NativeTypeMap.find(baseType) != TypeConvertor::NativeTypeMap.end()) {
        return true;
    }

    return false;
}

bool TypeInfo::isComType() {
    if (isNativeType() || isVoidType() || isEnumType()) {
        return false;
    }

    return true;
}

bool TypeInfo::isVoidType(bool base) {
    string baseType = _typeSpelling;
    if (base) {
        baseType = Helpers::Trim(Helpers::baseType(_typeSpelling, true));
    }

    if (baseType == "void") {
        return true;
    }

    return false;
}

bool TypeInfo::isIdWithProtocolConformance() {
    bool isProtocol = false;

    switch (_idType) {
        case IsAProtocol:
            isProtocol = true;
            break;

        case NotAProtocol:
            isProtocol = false;
            break;

        default: {
            std::string protocolName = TypeConvertor::GetProtocolFromId(_typeSpelling);
            if (!protocolName.empty()) {
                _idType = IsAProtocol;
                isProtocol = true;
            } else {
                _idType = NotAProtocol;
                isProtocol = false;
            }
            break;
        }
    }

    return isProtocol;
}

void TypeInfo::_updateSymbolReferencesForComponent(bool isProtocol) {
    if (this->isNativeType() || this->isContainer() || this->isEnumType() || this->isNSDateType() || this->isNSURLType()) {
        return;
    }

    if (isProtocol) {
        g_globalData.currentComponent->AddReferenceToProtocol(this->_typeSpelling);
    } else {
        g_globalData.currentComponent->AddReferenceToInterface(this->_typeSpelling);
    }
}

void TypeInfo::handleGenericTypes() {
    bool isProtocol = false;
    // Update the typespelling of this TypeInfo.
    if (this->isContainer() && !this->isHeterogeneous) {
        std::string spelling = this->_typeSpelling;
        TypeConvertor::SetContainerTypeInfo(shared_from_this(), spelling);
        if (TypeConvertor::isGeneric(spelling)) {
            this->updateObjCCreatorFunctionName(TypeConvertor::GetObjCTypeCreatorName(shared_from_this()), shared_from_this());
        }
    } else if (this->isIdWithProtocolConformance()) {
        isProtocol = true;
        this->_typeSpelling = TypeConvertor::GetProtocolFromId(this->_typeSpelling) + "*";
    }

    _updateSymbolReferencesForComponent(isProtocol);
}

void TypeInfo::_resolveType(const string& metadata) {
    if (metadata.length() > 0) {
        this->setTypeSpelling(metadata);
        if (g_globalData.currentComponent->heterogeneousContainers.find(metadata) !=
            g_globalData.currentComponent->heterogeneousContainers.end()) {
            isHeterogeneous = true;
        }
    }

    handleGenericTypes();
}

void TypeInfo::ResolveReturnType(const string& metadata) {
    _resolveType(metadata);
}

void TypeInfo::ResolveParameterType(const string& metadata) {
    _resolveType(metadata);
}

std::shared_ptr<ClangObjectModel::TypeInfo> TypeInfo::CloneTypeInfo(const std::shared_ptr<ClangObjectModel::TypeInfo>& info) {
    auto ret = make_shared<ClangObjectModel::TypeInfo>();
    ret->annotation = info->annotation;
    ret->cursor = info->cursor;
    ret->setTypeName(info->getTypeName());
    ret->SDKHeaderFile = info->SDKHeaderFile;
    ret->SDKname = info->SDKname;
    for (size_t i = 0; i < info->templateParams.size(); i++) {
        ret->templateParams.push_back(std::move(ClangObjectModel::TypeInfo::CloneTypeInfo(info->templateParams[i])));
    }
    ret->isHeterogeneous = info->isHeterogeneous;
    ret->cachedSymbolKind = info->cachedSymbolKind;
    ret->typeKind = info->typeKind;
    ret->setTypeSpelling(info->getTypeSpelling());
    ret->wrlName = info->wrlName;
    ret->sourceLocation = info->sourceLocation;
    return ret;
}

bool AsyncClassInfo::operator()(const std::shared_ptr<ClangObjectModel::AsyncClassInfo>& info1,
                                const std::shared_ptr<ClangObjectModel::AsyncClassInfo>& info2) const {
    return (info1->name < info2->name);
}

std::shared_ptr<ClangObjectModel::AsyncClassInfo> AsyncClassInfo::CloneAsyncClassInfo(
    const std::shared_ptr<ClangObjectModel::AsyncClassInfo>& info) {
    auto ret = make_shared<ClangObjectModel::AsyncClassInfo>();
    ret->name = info->name;
    ret->implName = info->name;
    ret->sdkName = info->sdkName;
    ret->synthesizedInterface = info->synthesizedInterface;
    size_t count = info->returnTypes.size();
    for (size_t i = 0; i < count; i++) {
        ret->returnTypes.push_back(std::move(ClangObjectModel::TypeInfo::CloneTypeInfo(info->returnTypes[i])));
    }

    return ret;
}

ParameterInfo::ParameterInfo() {
}

std::shared_ptr<ClangObjectModel::ParameterInfo> ParameterInfo::CloneParameterInfo(
    const std::shared_ptr<ClangObjectModel::ParameterInfo>& info) {
    auto ret = make_shared<ClangObjectModel::ParameterInfo>();
    if (info->asyncInfo) {
        ret->asyncInfo = std::move(ClangObjectModel::AsyncClassInfo::CloneAsyncClassInfo(info->asyncInfo));
    }

    ret->cursor = info->cursor;
    for (size_t i = 0; i < info->delegateParams.size(); i++) {
        ret->delegateParams.push_back(std::move(ClangObjectModel::TypeInfo::CloneTypeInfo(info->delegateParams[i])));
    }
    ret->marshallDelegateAsAsync = info->marshallDelegateAsAsync;
    ret->SDKHeaderFile = info->SDKHeaderFile;
    ret->SDKname = info->SDKname;
    if (info->typeInfo) {
        ret->typeInfo = std::move(ClangObjectModel::TypeInfo::CloneTypeInfo(info->typeInfo));
    }

    return ret;
}

std::shared_ptr<ClangObjectModel::MethodInfo> MethodInfo::CloneMethodInfo(const std::shared_ptr<MethodInfo>& info) {
    auto ret = make_shared<ClangObjectModel::MethodInfo>();
    ret->isAsync = info->isAsync;
    ret->name = info->name;
    ret->displayName = info->displayName;
    ret->objectiveCSelector = info->objectiveCSelector;
    ret->objectiveCSignature = info->objectiveCSignature;
    ret->isSynthesizedProperty = info->isSynthesizedProperty;
    ret->isPolymorphic = info->isPolymorphic;
    ret->isOverloaded = info->isOverloaded;
    ret->returnTypePolymorphId = info->returnTypePolymorphId;
    ret->needsDefaultOverload = info->needsDefaultOverload;

    for (size_t i = 0; i < info->params.size(); i++) {
        ret->params.push_back(std::move(ClangObjectModel::ParameterInfo::CloneParameterInfo(info->params[i])));
    }

    if (info->returnType) {
        ret->returnType = std::move(ClangObjectModel::ParameterInfo::CloneParameterInfo(info->returnType));
    }
    ret->SDKHeaderFile = info->SDKHeaderFile;
    ret->SDKname = info->SDKname;
    ret->methodNameForIDL = info->methodNameForIDL;
    ret->idlAnnotation = info->idlAnnotation;
    ret->methodNameForRuntimeClass = info->methodNameForRuntimeClass;

    return ret;
}

void MethodInfo::UpdateMethodNameForIDLAndRuntimeClass(const std::string& newRuntimeName) {
    this->methodNameForIDL = newRuntimeName;
    this->methodNameForRuntimeClass = newRuntimeName;
}

void MethodInfo::UpdateMethodNameForIDLAndRuntimeClass(const std::string& nameForIDL, const std::string& nameForRuntimeClass) {
    this->methodNameForIDL = nameForIDL;
    this->methodNameForRuntimeClass = nameForRuntimeClass;
}

PropertyInfo::PropertyInfo(const std::string& propertyName,
                           const std::string& getterName,
                           const std::string& setterName,
                           std::shared_ptr<ClangObjectModel::MetaDataComments> metaData) {
    std::shared_ptr<ClangObjectModel::MethodInfo> getter;
    std::shared_ptr<ClangObjectModel::MethodInfo> setter;

    this->_name = propertyName;

    this->getter = make_shared<MethodInfo>();
    this->getter->name = getterName;
    this->getter->methodNameForIDL = propertyName;
    this->getter->methodNameForRuntimeClass = "get_" + propertyName;
    this->getter->idlAnnotation = "[propget]";

    this->setter = make_shared<MethodInfo>();
    this->setter->name = setterName;
    this->setter->methodNameForIDL = propertyName;
    this->setter->methodNameForRuntimeClass = "put_" + propertyName;
    this->setter->idlAnnotation = "[propput]";

    this->metadata = metaData;
}

void PropertyInfo::setPropertyName(const string& nameString) {
    string baseName = Helpers::Trim(nameString);
    if (idlKeywords.find(baseName) != idlKeywords.end()) {
        baseName = "_" + baseName + "_";
    }

    _name = baseName;
}

string PropertyInfo::getPropertyName() {
    return _name;
}

void InterfaceInfo::AddProtocolsImplemented(const std::string& protocolName) {
    this->_protocolsImplemented.push_back(protocolName);
}

std::vector<std::shared_ptr<ProtocolInfo>> InterfaceInfo::getProtocolsImplemented() {
    std::vector<std::shared_ptr<ProtocolInfo>> protocols;

    for (const auto& protocolName : this->_protocolsImplemented) {
        bool found = false;
        for (const auto& component : g_globalData.components) {
            auto protocolIter = g_globalData.protocolMap.find(protocolName);
            if (protocolIter != g_globalData.protocolMap.end()) {
                protocols.push_back(protocolIter->second);
                found = true;
                break;
            }
        }
        if (!found) {
            Helpers::Errors::Throw_On_Error_Msg(-1, "Could not find protocol: " + protocolName);
        }
    }
    return protocols;
}

void InterfaceInfo::SetSuperClassFromCursor(CXCursor cursor) {
    this->_superClass = ClangHelpers::GetCursorSpelling(cursor);
    this->_superClassSourceLocation = ClangHelpers::GetSourceStartingLocation(cursor);
}

std::string InterfaceInfo::GetIdlRuntimeClassName() {
    return (this->_idlRuntimeClassName.empty() ? this->name : this->_idlRuntimeClassName);
}

std::string InterfaceInfo::GetIdlFileName() {
    return (this->_idlFileName.empty() ? this->name : this->_idlFileName);
}

std::string InterfaceInfo::GetWinrtClassName() {
    return (this->_winrtName.empty() ? this->name : this->_winrtName);
}

std::shared_ptr<InterfaceInfo> InterfaceInfo::GetBaseClass() {
    if (this->_superClass.empty() || this->_superClass == "NSObject") {
        return nullptr;
    }

    std::string baseClass = this->_superClass;
    auto baseClassInterface = g_globalData.interfaceMap.find(this->_superClass);
    if (baseClassInterface != g_globalData.interfaceMap.end()) {
        return baseClassInterface->second;
    }

    auto frameworkInterface = g_globalData.objCSuperClasses.find(this->_superClass);
    if (frameworkInterface != g_globalData.objCSuperClasses.end()) {
        return frameworkInterface->second;
    }

    std::stringstream error;
    error << "Unknown super class:" << this->_superClass << endl;
    Helpers::Errors::WriteError(this->_superClassSourceLocation, error.str(), false);
    return nullptr;
}

bool InterfaceInfo::DerivesFromUIElement() {
    if (this->_superClass == "NSObject") {
        return false;
    }

    if (GetUIElementBaseClass() != nullptr) {
        return true;
    }
    return false;
}

std::shared_ptr<InterfaceInfo> InterfaceInfo::GetUIElementBaseClass() {
    std::string baseClass = this->_superClass;

    // First find the base class in any user defined classes.
    auto userDefinedBaseClassInterface = g_globalData.interfaceMap.find(this->_superClass);
    while (userDefinedBaseClassInterface != g_globalData.interfaceMap.end()) {
        baseClass = userDefinedBaseClassInterface->second->_superClass;
        userDefinedBaseClassInterface = g_globalData.interfaceMap.find(userDefinedBaseClassInterface->second->_superClass);
    }

    // Then check the framework packages.
    auto frameworkInterface = g_globalData.objCSuperClasses.find(baseClass);
    if (frameworkInterface != g_globalData.objCSuperClasses.end()) {
        return frameworkInterface->second;
    }

    return nullptr;
}

std::shared_ptr<ClangObjectModel::InterfaceInfo> GlobalData::GetObjCFrameworkInterfaces(const std::string& objcType) {
    string baseType = Helpers::Trim(Helpers::baseType(objcType, true));
    string lowerCaseBaseType = baseType;
    transform(baseType.begin(), baseType.end(), lowerCaseBaseType.begin(), ::tolower);

    auto it = _objCFrameworkInterfaces.find(lowerCaseBaseType);
    if (it != _objCFrameworkInterfaces.end()) {
        return it->second;
    }
    return nullptr;
}

} // namespace ClangObjectModel