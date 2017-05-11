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
#include <TypeInfo.h>
#include <Misc.h>

using namespace std;
using namespace ObjectModel;

namespace {
map<wstring, wstring> gBasicTypes = { { L"Enum", L"Basic" }, // TODO: BK: this is wrong and will die in the ObjcC case.
                                      { L"Windows.Foundation.EventRegistrationToken", L"EventRegistrationToken" },
                                      { L"Windows.Foundation.HResult", L"Basic<HRESULT>" },
                                      { L"Windows.Foundation.AsyncStatus", L"Basic<AsyncStatus>" } };

inline wstring getBasicType(const wstring& s) {
    auto it = gBasicTypes.find(s);
    return (it != gBasicTypes.end()) ? it->second : s;
}
}

wstring getObjcConvertor(const wstring& type) {
    return L"_makeObjcFrom<" + getBasicType(type) + L">";
}

wstring getWRLConvertor(const wstring& type) {
    return L"MakeWRLFrom" + getBasicType(type);
}

bool replaceAll(wstring& in, const wstring& chars, const wstring& with) {
    bool replaced = false;
    while (true) {
        size_t offs = in.find(chars);
        if (offs == wstring::npos)
            break;

        in.replace(offs, chars.length(), with);
        replaced = true;
    }
    return replaced;
}

wstring getObjType(const wstring& s) {
    wstring prefix;
    size_t idx = s.find('`');
    if (idx != wstring::npos) {
        prefix = s.substr(0, idx);
    } else {
        prefix = s;
    }

    idx = prefix.rfind('.');
    if (idx != wstring::npos) {
        prefix = prefix.substr(idx + 1);
    }

    return prefix;
}

wstring getObjInitials(const wstring& sInput) {
    wstring s = getObjType(sInput);
    wstring res;
    for (size_t i = 1; i < s.size(); i++) {
        if (s[i] >= L'A' && s[i] <= L'Z')
            res += s[i];
    }
    return res + L"_";
}

wstring replace(wstring in, const wstring& chars, const wstring& with) {
    replaceAll(in, chars, with);
    return in;
}

wstring baseType(const wstring& in) {
    wstring res;

    // No comments, please.
    size_t idx = in.find(L" /*");
    if (idx != std::string::npos) {
        res = in.substr(0, idx);
    } else {
        res = in;
    }

    size_t len = res.size();
    if (len <= 2)
        return in;

    if (res.substr(len - 2) == L" *") {
        return res.substr(0, len - 2);
    } else if (res.substr(len - 1) == L"*") {
        return res.substr(0, len - 1);
    }

    return res;
}

wstring getDesc(const WinrtType& pti) {
    wstring msg;

    if (pti.container == ContainerType::C_Array) {
        msg = L"C array parameter ";
    } else if (pti.container == ContainerType::Iterable) {
        msg = L"Iterable container parameter ";
    } else if (pti.container != ContainerType::None) {
        msg = L"Container parameter ";
    }

    msg = msg + L"(type " + pti.wrlFullName() + L") ";
    return msg;
}

void CheckSupportedParam(const ParameterInfo& p, const WinrtType& pti) {
    if (p.IsInParam && !pti.asInputSupported) {
        throw wstring(getDesc(pti) + p.Name + L" cannot be marshaled as an input argument.");
    }
    if (p.IsOutParam && !pti.asOutputSupported) {
        throw wstring(getDesc(pti) + p.Name + L" cannot be marshaled as an output argument.");
    }
}

void CheckSupportedArrayType(const ParameterInfo& p, const WinrtType& pti) {
    CheckSupportedParam(p, pti);

    if (p.Type->Category == TypeCategory::WinRtArray) {
        auto arr = dynamic_pointer_cast<Array>(p.Type);
        if (!arr)
            throw wstring(L"Internal error processing array argument.");

        /*
        if (arr->Type->Name == L"GUID") {
            wstring typeName = L"WinRT_Array<" + arr->Type->Name + L">"; // TODO: this is completely the wrong type name.
            throw wstring(L"Can't marshal output array of type ") + typeName;
        }
        */

        if (p.IsOutParam) {
            if (arr->ArrayCategory != Array::ReceiveArray) {
                if (arr->ArrayCategory == Array::FillArray) {
                    if (!pti.isCArray()) {
                        throw wstring(L"Only C style fill arrays are currently supported.");
                    }
                } else {
                    throw wstring(L"Only receive and fill arrays are currently supported.");
                }
            }
        } else {
            if (!pti.isCArray()) {
                wstring typeName = L"WinRT_Array<" + arr->Type->Name + L">"; // TODO: this is completely the wrong type name.
                throw wstring(L"Can't marshal array input type ") + typeName;
            }
        }

        if (p.Type->PointerKind != ElementPointerKind::ByRef && !pti.isCArray()) {
            throw wstring(L"Unknown array pointer type -- possibly an input/output hybrid array.");
        }
    }
}

bool isFillArray(const ParameterInfo& p) {
    if (p.Type->Category == TypeCategory::WinRtArray && p.IsOutParam) {
        if (auto a = dynamic_pointer_cast<Array>(p.Type)) {
            return (a->ArrayCategory == Array::FillArray);
        }
    }
    return false;
}

void splitString(const wstring& s, vector<wstring>& words, const wstring& separators) {
    words.resize(0);

    size_t idx = s.find_first_not_of(separators);
    while (idx != wstring::npos) {
        size_t idx2 = s.find_first_of(separators, idx);
        wstring word = s.substr(idx, (idx2 != wstring::npos) ? (idx2 - idx) : wstring::npos);
        words.push_back(word);
        idx = s.find_first_not_of(separators, idx2);
    }
}

bool badForMacros(const wstring& s) {
    return s.find(L',') != wstring::npos;
}

// TODO: BK: this is a little sub-par.
wstring mangledNameForTypedef(const wstring& input) {
    wstring res;
    vector<wstring> words;

    splitString(input, words, L" \r\n\t\v\f<>(),:;");
    for (const auto& w : words) {
        if (w == L"ABI" || w == L"Windows" || w == L"Foundation" || w == L"Collections")
            continue;

        if (!res.empty())
            res += L"_";
        res += w;
    }
    replaceAll(res, L"*", L"Ptr");

    return res;
}

wstring getObjCName(const wstring& name) {
    static const unordered_set<wstring> reserved = {
        // From here (because we can't trust the user to not call their property "dynamic_cast"):
        // http://en.cppreference.com/w/cpp/keyword

        L"alignas",
        L"alignof",
        L"and",
        L"and_eq",
        L"asm",
        L"auto",
        L"bitand",
        L"bitor",
        L"bool",
        L"break",
        L"case",
        L"catch",
        L"char",
        L"char16_t",
        L"char32_t",
        L"class",
        L"compl",
        L"concept",
        L"const",
        L"constexpr",
        L"const_cast",
        L"continue",
        L"decltype",
        L"default",
        L"delete",
        L"do",
        L"double",
        L"dynamic_cast",
        L"else",
        L"enum",
        L"explicit",
        L"export",
        L"extern",
        L"false",
        L"float",
        L"for",
        L"friend",
        L"goto",
        L"if",
        L"inline",
        L"int",
        L"long",
        L"mutable",
        L"namespace",
        L"new",
        L"noexcept",
        L"not",
        L"not_eq",
        L"nullptr",
        L"operator",
        L"or",
        L"or_eq",
        L"private",
        L"protected",
        L"public",
        L"register",
        L"reinterpret_cast",
        L"requires",
        L"return",
        L"short",
        L"signed",
        L"sizeof",
        L"static",
        L"static_assert",
        L"static_cast",
        L"struct",
        L"switch",
        L"template",
        L"this",
        L"thread_local",
        L"throw",
        L"true",
        L"try",
        L"typedef",
        L"typeid",
        L"typename",
        L"union",
        L"unsigned",
        L"using",
        L"virtual",
        L"void",
        L"volatile",
        L"wchar_t",
        L"while",
        L"xor",
        L"xor_eq",

        // We can't call our methods and properpties the same things as NSObject methods since
        // they have nothing to do with one-another and can override with different types, which
        // is very very bad. So recognize this case and rename them:

        // NSObject functions:
        L"alloc",
        L"release",
        L"dealloc",
        L"mutableCopy",
        L"copy",
        L"copyWithZone",
        L"allocWithZone",
        L"isEqual",
        L"isProxy",
        L"zone",
        L"retain",
        L"release",
        L"retainCount",
        L"autorelease",
        L"performSelector",
        L"self",
        L"load",
        L"initialize",
        L"finalize",
        L"version",
        L"setVersion",

        L"performSelector",
        L"cancelPreviousPerformRequestsWithTarget",
        L"instancesRespondToSelector",
        L"methodSignatureForSelector",
        L"methodForSelector"
        L"instanceMethodSignatureForSelector",
        L"instanceMethodForSelector",
        L"doesNotRecognizeSelector",
        L"resolveClassMethod",
        L"resolveInstanceMethod",
        L"forwardingTargetForSelector",
        L"forwardInvocation",

        L"performSelector",
        L"performSelectorOnMainThread",
        L"performSelectorInBackground",

        // NSObject properties:
        L"description",
        L"hash",
        L"debugDescription",
        L"superclass",
    };

    wstring ret = name;
    ret[0] = towlower(ret[0]);

    if (reserved.find(ret) != reserved.end()) {
        ret[0] = towupper(ret[0]);
    }

    return ret;
}

wstring getOverloadedName(const shared_ptr<MemberInfo>& info) {
    auto msgName = info->Name;

    // If this function is overloaded, we need to use the overloaded name since there's no overloaded
    // methods based on parameter types in objc:
    auto overloadAttr = info->Attributes.find(L"Windows.Foundation.Metadata.OverloadAttribute");
    if (overloadAttr != info->Attributes.end()) {
        msgName = overloadAttr->second->FixedParameters[0].StringValue;
    }

    return msgName;
}

wstring baseObjCMsgName(const shared_ptr<MemberInfo>& info) {
    auto msgName = getOverloadedName(info);

    if (info->IsSpecialName) {
        if (info->Name.find(L"get_") == 0) {
            // The name of getters are just the property name:
            msgName = info->Name.substr(4);
        } else if (info->Name.find(L"put_") == 0) {
            // The name of setters are set[Name]
            msgName = L"set" + info->Name.substr(4);
        } else if (info->Name.find(L"set_") == 0) {
            // The name of setters are set[Name]
            // winmd has the setter as set_[name] for WinRT components generated from C++ projects.
            // For Objective C we need to change these to set[Name].
            msgName = L"set" + info->Name.substr(4);
            msgName[3] = towupper(msgName[3]);
        } else if (info->Name.find(L"add_") == 0) {
            // Adding events are add[Name]Event
            msgName = L"add" + info->Name.substr(4) + L"Event";
        } else if (info->Name.find(L"remove_") == 0) {
            // Adding events are remove[Name]Event
            msgName = L"remove" + info->Name.substr(7) + L"Event";
        }
    }

    // Make sure first letter is lower-case and we don't conflict with reserved names:
    msgName = getObjCName(msgName);

    return msgName;
}

std::wstring formatString(const wchar_t* format, ...) {
    va_list arguments, arguments2;
    va_start(arguments, format);
    va_copy(arguments2, arguments);
    size_t size = _vscwprintf(format, arguments);
    va_end(arguments);
    std::wstring ret(size + 1, '\0');
    _vsnwprintf_s(&ret[0], size + 1, size, format, arguments2);
    va_end(arguments2);

    // _vsnwprintf_s is keen about putting null terminators on here but this increases the length with an extra null
    // term causing formatString(L"abc") != L"abc"
    ret.resize(size);
    return ret;
}

wstring getTypeNamespace(const wstring& name) {
    wstring ret = name;
    size_t lastNsTok = 0;
    if ((lastNsTok = name.find_first_of(L'`')) != wstring::npos) {
        ret = ret.substr(0, lastNsTok);
    }
    lastNsTok = ret.find_last_of(L'.');
    return lastNsTok == wstring::npos ? L"" : ret.substr(0, lastNsTok);
}

bool isGenericInterface(const shared_ptr<Interface>& i) {
    return i->Name.find(L'`') != wstring::npos;
}

wstring trim(const wstring& spelling, bool removePointer) {
    wstring str = spelling;
    size_t pos = str.find_first_not_of(L" \t");
    if (pos == str.npos) {
        return L"";
    }

    str = str.substr(pos);
    pos = str.find_last_not_of(L" \t");
    str = str.substr(0, pos + 1);

    if (removePointer) {
        pos = str.find_last_not_of(L"* ");
        if (pos != str.npos) {
            str = str.substr(0, pos + 1);
        }
    }
    return str;
}

wstring getSolutionFileNameFromWinmdFile(const wstring& winmdFile) {
    // Find last of '\\'
    size_t pos = winmdFile.find_last_of(L"\\");
    if (pos == winmdFile.npos) {
        return winmdFile;
    }

    wstring fileName = winmdFile.substr(pos + 1);
    // Find last of '.' in fileName
    pos = fileName.find_last_of(L".");
    if (pos == fileName.npos) {
        wprintf(L"Invalid input file specified");
        _exit(1);
    }

    // Get rid of the extension and return.
    return fileName.substr(0, pos);
}

wstring getSolutionFileNameFromNamespace(const shared_ptr<NameSpace>& ns) {
    return getSolutionFileNameFromWinmdFile(ns->SourceFileName);
}

wstring getGUIDAsString() {
    GUID guid;
    HRESULT result = CoCreateGuid(&guid);

    // Convert the GUID to a string
    wchar_t guidAsString[39];
    wsprintf(guidAsString,
             L"{%08lX-%04hX-%04hX-%02hX%02hX-%02hX%02hX%02hX%02hX%02hX%02hX}",
             guid.Data1,
             guid.Data2,
             guid.Data3,
             guid.Data4[0],
             guid.Data4[1],
             guid.Data4[2],
             guid.Data4[3],
             guid.Data4[4],
             guid.Data4[5],
             guid.Data4[6],
             guid.Data4[7]);

    return guidAsString;
}

void capitalizeFirstLetter(wstring& str) {
    if (str.length() == 0) {
        return;
    }

    str[0] = toupper(str[0]);
    size_t pos = 0;
    while (1) {
        pos = str.find('.', pos);
        if (pos == str.npos || pos == str.length() - 1) {
            break;
        }

        str[pos + 1] = toupper(str[pos + 1]);
        pos++;
    }
}