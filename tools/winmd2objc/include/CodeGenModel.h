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

#include "Misc.h"

#include <vector>
#include <string>

// If property or method name begins with the memory management identifier tokens like 'alloc', 'new', 'copy'
// then ARC is going to generate code to manage memory assuming that these return a +1 ref count object.
// So we return annotations which notify ARC that these do not return +1 ref count objects.
inline std::wstring _getClangAnnotationsForARC(std::wstring name) {
    if (name.find(L"new") == 0 || name.find(L"alloc") == 0 || name.find(L"copy") == 0) {
        return L"__attribute__ ((ns_returns_not_retained))";
    }

    return L"";
}

// Intersperse [separator] between each element of [data] that passes [filter], using [transform] to convert to a string type
template <typename Container, typename TransformFn>
static std::wstring addSeparators(const Container& data,
                                  const TransformFn& transform,
                                  const std::wstring& separator = L", ",
                                  std::function<bool(const typename Container::value_type&)> filter = [](auto val) { return true; }) {
    auto first = find_if(begin(data), end(data), filter);
    if (first == end(data)) {
        return L"";
    }

    std::wstringstream ss;
    ss << transform(*first);
    for_each(next(first), end(data), [&](const auto& val) {
        if (filter(val)) {
            ss << separator << transform(val);
        }
    });
    return ss.str();
}

// Eventually we may want to compose and construct a tree of these to easily just generating the source
// files but we aren't there yet.
class Stmt {
public:
    virtual ~Stmt() {
    }
    virtual std::wstring emit() = 0;
};

namespace ObjC {
struct MethodSig : Stmt {
    // name:(type)var
    struct NameTypeVar {
        std::wstring name, type, var;
    };

    std::vector<NameTypeVar> _nameTypeVar;
    std::wstring _returnType;
    bool _hasArgs, _staticMethod;
    bool _needsARCAnnotation;

    // No args:
    MethodSig(bool staticMethod, const std::wstring& returnType, const std::wstring& name, bool needsARCAnnotation = false)
        : _returnType(returnType), _staticMethod(staticMethod), _hasArgs(false), _needsARCAnnotation(needsARCAnnotation) {
        _nameTypeVar.push_back({ name, L"", L"" });
    }

    MethodSig(bool staticMethod,
              const std::wstring& returnType,
              const std::vector<NameTypeVar>& nameTypeVar,
              bool needsARCAnnotation = false)
        : _returnType(returnType),
          _nameTypeVar(nameTypeVar),
          _hasArgs(true),
          _staticMethod(staticMethod),
          _needsARCAnnotation(needsARCAnnotation) {
        if (nameTypeVar.empty()) {
            throw std::invalid_argument("parameters list must not be empty!");
        }
    }

    std::wstring emit() override {
        std::wstring parameters;

        if (_hasArgs) {
            parameters =
                addSeparators(_nameTypeVar, [](const NameTypeVar& ntv) { return ntv.name + L":(" + ntv.type + L")" + ntv.var; }, L" ");
        } else {
            assert(_nameTypeVar.size() == 1);
            parameters = _nameTypeVar[0].name;
        }

        wchar_t blip = _staticMethod ? L'+' : L'-'; // Does this guy have a name?

        // Get ARC related clang annotations.
        if (_needsARCAnnotation) {
            std::wstring annotation = _getClangAnnotationsForARC(parameters);
            if (annotation.length()) {
                parameters += L" " + annotation;
            }
        }

        return formatString(L"%c (%s)%s", blip, _returnType.c_str(), parameters.c_str());
    }
};

struct ObjCMethodDefn : Stmt {};

class ProtocolDecl : public Stmt {
public:
    ProtocolDecl(const std::wstring& name, const std::vector<std::wstring>& protocols = {}) : _name(name), _protocols(protocols) {
    }

    std::wstring emit() override {
        return formatString(L"@protocol %s%s", _name.c_str(), generateProtocolList().c_str());
    }

protected:
    std::wstring _name;
    std::vector<std::wstring> _protocols;

    std::wstring generateProtocolList() {
        std::wstring protocols = addSeparators(_protocols, std::identity<std::wstring>());
        if (!protocols.empty()) {
            protocols = formatString(L" <%s>", protocols.c_str());
        }
        return protocols;
    }
};

// This should eventually be merged with ClassDefn but currently they're fed from different places.
class ClassDecl : public ProtocolDecl {
    std::wstring _parent;
    std::wstring _exportDefine;

public:
    ClassDecl(const std::wstring& name,
              const std::wstring& parent,
              const std::wstring& exportDefine,
              const std::vector<std::wstring>& protocols = {})
        : ProtocolDecl(name, protocols), _parent(parent), _exportDefine(exportDefine) {
    }

    std::wstring emit() override {
        return formatString(L"%s\n@interface %s : %s%s",
                            _exportDefine.c_str(),
                            _name.c_str(),
                            _parent.c_str(),
                            generateProtocolList().c_str());
    }
};
}
