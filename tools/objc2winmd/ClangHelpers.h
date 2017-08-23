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

#include <string>
#include <set>
#include <map>
#include <vector>
#include <memory>
#include <clang-c\Index.h>

namespace ClangObjectModel {
struct ComponentInfo;
struct ParameterInfo;
struct TypeInfo;
struct MethodInfo;
struct InterfaceInfo;
class MetaDataComments;
struct AsyncClassInfo;
}

namespace ClangHelpers {
typedef std::pair<std::string, std::string> header_argfile;
struct SDKParameters {
    std::string rootNameSpace;
    std::map<std::string, header_argfile> SDKHeaderArgMap;
};

struct SourceLocationInfo {
    std::string fileName;
    unsigned int line;
    unsigned int column;
    unsigned int offset;
};

std::string GetCursorSpelling(const CXCursor cursor);
std::string GetTypeKindSpelling(const CXTypeKind typeKind);
std::string GetTypeSpelling(const CXType type);
std::string GetCursorResultTypeSpelling(const CXCursor cursor);
std::string GetCursorTypeSpelling(const CXCursor cursor);
std::string GetMethodSpelling(const CXCursor cursor);
std::string GetDisplayName(const CXCursor cursor);
std::string GetRawCommentText(const CXCursor cursor);
std::string GetCursorFileName(const CXCursor cursor);
std::string GetCursorSDKName(const CXCursor cursor);
std::string GetSource(const CXCursor cursor);
std::shared_ptr<SourceLocationInfo> GetSourceLocation(const CXSourceLocation sourceLocation);
std::shared_ptr<SourceLocationInfo> GetSourceStartingLocation(const CXCursor cursor);
std::string GetString(CXString cxString);
std::string generateDelegateName(std::vector<std::shared_ptr<ClangObjectModel::TypeInfo>>& params);
void updateParamInfoWithMetaData(std::shared_ptr<ClangObjectModel::MetaDataComments> metaData,
                                 size_t lineNumber,
                                 std::shared_ptr<ClangObjectModel::ParameterInfo>& param);
void updateDelegateInfo(std::shared_ptr<ClangObjectModel::ParameterInfo>& param, std::shared_ptr<ClangObjectModel::MethodInfo>& methodInfo);
bool checkForAsync(std::shared_ptr<ClangObjectModel::ParameterInfo>& param);
std::string getResolvedAsyncImplName(const std::shared_ptr<ClangObjectModel::AsyncClassInfo>& asyncInfo,
                                     std::string prefix = "",
                                     bool forIDL = false);
std::string getSynthesizedAsyncClassPropertyName(std::shared_ptr<ClangObjectModel::TypeInfo>& typeInfo);
std::string generateAsyncClassImplName(std::shared_ptr<ClangObjectModel::AsyncClassInfo>& asyncInfo, const std::string& sdkHeaderFile);
void updateAsyncClassInfo(std::shared_ptr<ClangObjectModel::ParameterInfo>& param,
                          std::shared_ptr<ClangObjectModel::MethodInfo>& methodInfo);
bool isInterface(const std::string& typeSpelling);
bool isProtocol(const std::string& typeSpelling);
bool isDelegateCallbackProtocol(const std::string& typeSpelling);
bool isCursorFromProjectHeaders(const CXCursor cursor);
std::string generateResolvedTypeName(const std::string& symbolName,
                                     const std::string& sdkName,
                                     bool forIDL = false,
                                     const std::string prefixStr = "ABI");
std::string generateNamespaceString(const std::string& sdkName, const std::string& separator);

std::string getEnumTypeName(std::string spelling);
std::string generateMethodNameWithParameterType(std::shared_ptr<ClangObjectModel::MethodInfo>& method);
void fixMethodNameConflicts(std::vector<std::shared_ptr<ClangObjectModel::MethodInfo>>& methods);
std::string getDelegateParamNameListForWinRT(std::shared_ptr<ClangObjectModel::ParameterInfo> paramInfo);
std::shared_ptr<ClangObjectModel::InterfaceInfo> getInterfaceImplementingProtocol(const std::string& protocolName);
std::string generateCallToIslandWoodInit();

// The input is the entire string which the user provided for possible types i.e. everything between
// ClangObjectModel::possibleTypesStartSymbol and ClangObjectModel::possibleTypesEndSymbol.
// This method will split it into complete types e.g.: Assuming possibleTypesStartSymbol = '[' and possibleTypesEndSymbol = ']'.
// Input: "int|NSArray<[int | float | NSArray<[MyInterface* | int]>]>|char"
// Output[0]: int
// Output[1]: NSArray<[int | float | NSArray<[MyInterface* | int]>]>
// Output[2]: char
std::vector<std::string> tokenize_CompleteTypes(const std::string& possibleTypes);
} // namespace ClangHelpers
