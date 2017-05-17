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

class WinrtType;
namespace ObjectModel {
struct ParameterInfo;
}

std::wstring getObjcConvertor(const std::wstring& type);
std::wstring getWRLConvertor(const std::wstring& type);

std::wstring replace(std::wstring in, const std::wstring& chars, const std::wstring& with);
bool replaceAll(std::wstring& in, const std::wstring& chars, const std::wstring& with);

std::wstring getObjType(const std::wstring& s);
std::wstring getObjInitials(const std::wstring& sInput);

// Return the real full name of the WRL function, including overloading:
std::wstring getOverloadedName(const std::shared_ptr<ObjectModel::MemberInfo>& info);

std::wstring getObjCName(const std::wstring& name);
std::wstring baseObjCMsgName(const std::shared_ptr<ObjectModel::MemberInfo>& info);

std::wstring baseType(const std::wstring& s);

std::wstring getDesc(const WinrtType& pti);
void CheckSupportedArrayType(const ObjectModel::ParameterInfo& p, const WinrtType& pti);
bool isFillArray(const ObjectModel::ParameterInfo& p);

void splitString(const std::wstring& s, std::vector<std::wstring>& words, const std::wstring& separators);
bool badForMacros(const std::wstring& s);
std::wstring mangledNameForTypedef(const std::wstring& input);

// Get namespace from a symbol name from the winmd:
// Foo.Bar.Baz`1<A,B,C> -> Foo.Bar
std::wstring getTypeNamespace(const std::wstring& name);

bool isGenericInterface(const std::shared_ptr<ObjectModel::Interface>& i);

std::wstring formatString(const wchar_t* format, ...);

static void writeHelper(FILE* out, const wchar_t* str) {
    fwprintf(out, L"%s", str);
}
static void writeHelper(FILE* out, const char* str) {
    fprintf(out, "%s", str);
}
static void writeHelper(FILE* out, const std::wstring& str) {
    fwprintf(out, str.c_str());
}

std::wstring trim(const std::wstring& str, bool removePointer = false);

template <typename T, typename... Rest>
void write(FILE* out, const T& val, Rest&... rest) {
    writeHelper(out, val);
    write(out, rest...);
}
static void write(FILE* out) {
}

std::wstring getSolutionFileNameFromWinmdFile(const std::wstring& winmdFile);
std::wstring getSolutionFileNameFromNamespace(const std::shared_ptr<ObjectModel::NameSpace>& ns);
std::wstring getGUIDAsString();
void capitalizeFirstLetter(std::wstring& str);
