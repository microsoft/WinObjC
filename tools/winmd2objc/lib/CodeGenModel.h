#pragma once

#include "Misc.h"

#include <string>
#include <vector>

using std::wstring;
using std::vector;

// If property or method name begins with the memory management identifier tokens like 'alloc', 'new', 'copy'
// then ARC is going to generate code to manage memory assuming that these return a +1 ref count object.
// So we return annotations which notify ARC that these do not return +1 ref count objects.
inline wstring _getClangAnnotationsForARC(wstring name) {
    if (name.find(L"new") == 0 || name.find(L"alloc") == 0 || name.find(L"copy") == 0) {
        return L"__attribute__ ((ns_returns_not_retained))";
    }

    return L"";
}

// Intersperse [separator] between each element of [data] that passes [filter], using [transform] to convert to a string type
template <typename Container, typename TransformFn>
static wstring addSeparators(const Container& data,
                             const TransformFn& transform,
                             const wstring& separator = L", ",
                             function<bool(const typename Container::value_type&)> filter = [](auto val) { return true; }) {
    auto first = find_if(begin(data), end(data), filter);
    if (first == end(data)) {
        return L"";
    }

    wstringstream ss;
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
    virtual wstring emit() = 0;
};

namespace ObjC {
struct MethodSig : Stmt {
    // name:(type)var
    struct NameTypeVar {
        wstring name, type, var;
    };

    vector<NameTypeVar> _nameTypeVar;
    wstring _returnType;
    bool _hasArgs, _staticMethod;
    bool _needsARCAnnotation;

    // No args:
    MethodSig(bool staticMethod, const wstring& returnType, const wstring& name, bool needsARCAnnotation = false)
        : _returnType(returnType), _staticMethod(staticMethod), _hasArgs(false), _needsARCAnnotation(needsARCAnnotation) {
        _nameTypeVar.push_back({ name, L"", L"" });
    }

    MethodSig(bool staticMethod, const wstring& returnType, const vector<NameTypeVar>& nameTypeVar, bool needsARCAnnotation = false)
        : _returnType(returnType),
          _nameTypeVar(nameTypeVar),
          _hasArgs(true),
          _staticMethod(staticMethod),
          _needsARCAnnotation(needsARCAnnotation) {
        if (nameTypeVar.empty()) {
            throw invalid_argument("parameters list must not be empty!");
        }
    }

    wstring emit() override {
        wstring parameters;

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
            wstring annotation = _getClangAnnotationsForARC(parameters);
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
    ProtocolDecl(const wstring& name, const vector<wstring>& protocols = {}) : _name(name), _protocols(protocols) {
    }

    wstring emit() override {
        return formatString(L"@protocol %s%s", _name.c_str(), generateProtocolList().c_str());
    }

protected:
    wstring _name;
    vector<wstring> _protocols;

    wstring generateProtocolList() {
        wstring protocols = addSeparators(_protocols, identity<wstring>());
        if (!protocols.empty()) {
            protocols = formatString(L" <%s>", protocols.c_str());
        }
        return protocols;
    }
};

// This should eventually be merged with ClassDefn but currently they're fed from different places.
class ClassDecl : public ProtocolDecl {
    wstring _parent;
    wstring _exportDefine;

public:
    ClassDecl(const wstring& name, const wstring& parent, const wstring& exportDefine, const vector<wstring>& protocols = {})
        : ProtocolDecl(name, protocols), _parent(parent), _exportDefine(exportDefine) {
    }

    wstring emit() override {
        return formatString(L"%s\n@interface %s : %s%s",
                            _exportDefine.c_str(),
                            _name.c_str(),
                            _parent.c_str(),
                            generateProtocolList().c_str());
    }
};
}
