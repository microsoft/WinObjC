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

class WinrtType;
namespace ObjectModel {
struct ParameterInfo;
}

wstring getObjcConvertor(const wstring& type);
wstring getWRLConvertor(const wstring& type);

wstring replace(wstring in, const wstring& chars, const wstring& with);
bool replaceAll(wstring& in, const wstring& chars, const wstring& with);

wstring getObjType(const wstring& s);
wstring getObjInitials(const wstring& sInput);

// Return the real full name of the WRL function, including overloading:
wstring getOverloadedName(const shared_ptr<MemberInfo>& info);

wstring getObjCName(const wstring& name);
wstring baseObjCMsgName(const shared_ptr<MemberInfo>& info);

wstring baseType(const wstring& s);

wstring getDesc(const WinrtType& pti);
void CheckSupportedArrayType(const ParameterInfo& p, const WinrtType& pti);
bool isFillArray(const ParameterInfo& p);

void splitString(const wstring& s, vector<wstring>& words, const wstring& separators);
bool badForMacros(const wstring& s);
wstring mangledNameForTypedef(const wstring& input);

// Get namespace from a symbol name from the winmd:
// Foo.Bar.Baz`1<A,B,C> -> Foo.Bar
wstring getTypeNamespace(const wstring& name);

bool isGenericInterface(const shared_ptr<Interface>& i);

std::wstring formatString(const wchar_t* format, ...);

static void writeHelper(FILE* out, const wchar_t* str) {
    fwprintf(out, L"%s", str);
}
static void writeHelper(FILE* out, const char* str) {
    fprintf(out, "%s", str);
}
static void writeHelper(FILE* out, const wstring& str) {
    fwprintf(out, str.c_str());
}

wstring trim(const wstring& str, bool removePointer = false);

template <typename T, typename... Rest>
void write(FILE* out, const T& val, Rest&... rest) {
    writeHelper(out, val);
    write(out, rest...);
}
static void write(FILE* out) {
}

wstring getSolutionFileNameFromWinmdFile(const wstring& winmdFile);
wstring getSolutionFileNameFromNamespace(const shared_ptr<NameSpace>& ns);
wstring getGUIDAsString();
void capitalizeFirstLetter(wstring& str);
