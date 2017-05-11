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
#include <WinrtType.h>
#include <TypeInfo.h>
#include <Generics.h>
#include <Misc.h>

using namespace std;
using namespace ObjectModel;

SingleObjConvertor singleObjConv;
NilConvertor nilConv;

namespace {
wstring mangledType(const wstring& nameIn) {
    wstring name = baseType(nameIn);
    if (name.find(L'<') != wstring::npos) {
        vector<wstring> entries;
        splitString(name, entries, L"<> ,()"); // paranoid separator choice, should just be interface impls.
        name = L"";
        for (auto s : entries) {
            if (!name.empty())
                name += L"_";
            name += s;
        }
    }
    return name;
}
}

void WinrtType::setObjcType(const wstring& s) {
    assert(objcType.empty());
    objcType = s;
}

void WinrtType::setWrlType(const wstring& wrl, const wstring& tname) {
    assert(wrlName.empty());
    wrlName = wrl;
    templateType = tname;
}

void WinrtType::setBasicType(const wstring& s) {
    assert(objcType.empty());
    setObjcType(s);
    wrlName = s;
    templateType = s;
}

wstring WinrtType::getObjcInputType(shared_ptr<Symbol> type) const {
    if (!isContainer())
        return objcType;

    if (isCArray()) {
        shared_ptr<Array> a = dynamic_pointer_cast<Array>(type);
        if (a && (a->ArrayCategory == Array::FillArray)) {
            return getFullObjcTypename();
        }
    }

    if (subtypeComment.empty()) {
        return containerInfo().objcInputType;
    } else {
        return containerInfo().objcInputType + L" /* " + subtypeComment + L" */";
    }
}

wstring WinrtType::getFullObjcTypename(bool convert) const {
    if (isContainer()) {
        wstring containedTypes;
        for (auto t : templateParams) {
            containedTypes += L"_";
            containedTypes += t.getFullObjcTypename(true);
        }
        wstring res = containerInfo().classnameStart + containedTypes;
        return res;
    }

    if (isValueType) {
        if (!convert)
            return getObjcType();

        wstring outName;
        if (basicTypeToWinrt(outName, wrlName))
            return outName;
    }

    if (convert) {
        return mangledType(objcType);
    } else {
        return baseType(objcType);
    }
}

wstring WinrtType::getObjcClass() const {
    if (isContainer()) {
        return containerInfo().classnameStart;
    } else {
        return baseType(objcType);
    }
}

wstring WinrtType::wrlFullName(bool interfaceType, bool baseType) const {
    if (isValueType || isEnumType || isCArray())
        return interfaceType ? wrlName : templateType;

    if (!isContainer()) {
        wstring name = interfaceType ? wrlName : templateType;
        if (baseType)
            return name;
        return name + L"*";
    }

    auto ci = containerInfo();

    wstring res = ci.wrlInterface + L"<";
    wstring next = L"";
    for (auto c : templateParams) {
        res = res + next + c.wrlFullName(false);
        next = L", ";
    }
    if (baseType) {
        res += L">";
    } else {
        res += L">*";
    }
    return res;
}

wstring WinrtType::getObjcType(bool decoratedName) const {
    if (!decoratedName || subtypeComment.empty()) {
        return objcType;
    }

    return objcType + L" /* " + subtypeComment + L" */";
}

const WinrtContainerInfo& WinrtType::containerInfo() const {
    return getContainerInfo(container);
}

wstring WinrtType::aggregateWrlType() const {
    wstring wrlType;
    if ((isValueType || isFundamentalType || isEnumType) && (templateType != L"bool")) {
        wrlType = templateType;
    } else {
        wrlType = L"ABI::Windows::Foundation::Internal::AggregateType<" + wrlFullName(false) + L", " + wrlFullName() + L">";
    }
    return wrlType;
}

bool WinrtType::isInheritable() const {
    return containerInfo().isInheritable;
}

bool WinrtType::isSupportedInheritable() const {
    return containerInfo().isSupportedInheritable;
}

ToObjcTypeConvertor::~ToObjcTypeConvertor() {
}

class BuiltinTypeConvertor : public ToObjcTypeConvertor {
    wstring builtin;
    bool func;

public:
    inline bool isFunc() const {
        return func;
    }

    BuiltinTypeConvertor(const wstring& builtin, bool func) : builtin(builtin), func(func), ToObjcTypeConvertor() {
    }

    virtual bool isBuiltin() const override {
        return true;
    }
    virtual wstring call(const WinrtType& t, const wstring& paramName) override {
        if (func) {
            return builtin + L"(" + paramName + L")";
        } else {
            return builtin + paramName;
        }
    }
};

ToObjcTypeConvertor* ToObjcTypeConvertor::builtinFor(const wstring& conversion, bool func) {
    static map<wstring, BuiltinTypeConvertor*> builtins;
    auto it = builtins.find(conversion);
    if (it != builtins.end()) {
        assert(it->second->isFunc() == func);
        return it->second;
    }

    BuiltinTypeConvertor* tc = new BuiltinTypeConvertor(conversion, func);
    builtins[conversion] = tc;
    return tc;
}

wstring SingleObjConvertor::prototype(const WinrtType& t) {
    return t.getObjcType() + L" " + t.getFullObjcTypename() + L"_create(" + t.wrlFullName() + L" val)";
}

wstring SingleObjConvertor::call(const WinrtType& t, const wstring& param) {
    return baseType(t.getFullObjcTypename()) + L"_create(" + param + L")";
}

wstring SingleObjConvertor::instantiator(const WinrtType& t) {
    // Note variable name of "val" comes from the prototype above.
    return wstring(L"[[") + t.getFullObjcTypename() + L" alloc] initWith: val]";
}

wstring SingleObjContainerConvertor::prototype(const WinrtType& t) {
    return L"id " + t.getFullObjcTypename() + L"_create(IInspectable*" + L" val)";
}
