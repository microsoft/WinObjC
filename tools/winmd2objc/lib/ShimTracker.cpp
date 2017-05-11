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
#include <ShimTracker.h>
#include <WinrtType.h>
#include <Generics.h>
#include <Misc.h>

using namespace std;

ShimTracker::ShimTracker(map<wstring, wstring>& map) : namespaceMap(map) {
}

void ShimTracker::dumpAndReset(const wstring& ns, FILE* outHeader, FILE* outImpl, FILE* cheatHeader) {
    inGeneration = true;

    dumpForwardDecls(outHeader, outImpl, cheatHeader);

    for (const auto& p : referencedClasses) {
        auto name = p.first;
        auto type = p.second;

        if (!type.isContainer() || type.toObjc->isBuiltin())
            continue;

        auto moduleName = namespaceMap[ns];
        if (generatedShims.find(moduleName) == generatedShims.end()) {
            generatedShims[moduleName] = {};
        }

        if (generatedShims.at(moduleName).find(name) != generatedShims.at(moduleName).end())
            continue;
        generatedShims.at(moduleName).insert(name);

        const auto& ci = type.containerInfo();
        auto c = type.toObjc;

        fwprintf(outImpl, L"%s {\n", c->prototype(type).c_str());
        fwprintf(outImpl, L"    %s;\n", c->instantiator(type, *this).c_str());
        fwprintf(outImpl, L"}\n\n");
    }

    for (const auto& delShim : delegateShims) {
        const auto& className = delShim.first.c_str();

        auto typeInfo = delShim.second.type;

        wstring wrlArgs, delegateArgs, callArgs;
        size_t curr = 0;
        for (const auto& arg : typeInfo.templateParams) {
            if (delegateArgs.size()) {
                wrlArgs += L", ";
                delegateArgs += L", ";
                callArgs += L", ";
            }

            auto name = L"arg" + std::to_wstring(curr++);
            wrlArgs += arg.wrlFullName() + L" " + name;
            delegateArgs += arg.getObjcType();
            callArgs += arg.toObjc->call(arg, name);
        }

        if (delShim.second.returnType.size()) {
            if (wrlArgs.size())
                wrlArgs += L", ";
            wrlArgs += delShim.second.returnType;
        }

        fwprintf(cheatHeader, L"#ifndef __%s__DEFINED\n#define __%s__DEFINED\n", className, className);
        fwprintf(cheatHeader,
                 L"class %s : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, %s> {\n",
                 className,
                 typeInfo.wrlFullName(true, true).c_str());
        fwprintf(cheatHeader, L"    void (^_delegate)(%s);\npublic:\n", delegateArgs.c_str());
        fwprintf(cheatHeader, L"    %s(void (^del)(%s)) : _delegate([del copy]) {}\n", className, delegateArgs.c_str());
        fwprintf(cheatHeader, L"    ~%s() { [_delegate release]; }\n", className);

        // This is required for CTL conformance.
        fwprintf(cheatHeader, L"    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {\n");
        fwprintf(cheatHeader, L"        *trustLevel = BaseTrust;\n");
        fwprintf(cheatHeader, L"        return S_OK;\n");
        fwprintf(cheatHeader, L"    }\n");

        fwprintf(cheatHeader, L"    virtual HRESULT STDMETHODCALLTYPE Invoke(%s) override {\n", wrlArgs.c_str());
        fwprintf(cheatHeader, L"        @autoreleasepool {\n");
        fwprintf(cheatHeader, L"            _delegate(%s);\n", callArgs.c_str());
        fwprintf(cheatHeader, L"            return 0;\n");
        fwprintf(cheatHeader, L"        };\n");
        fwprintf(cheatHeader, L"    }\n");
        fwprintf(cheatHeader, L"};\n#endif\n\n");
    }

    // Typedef shims .. stupid macros.  Note this should always be last.
    if (!typedefShims.empty())
        fwprintf(cheatHeader, L"\n");
    for (auto p : typedefShims) {
        fwprintf(cheatHeader, L"typedef %s %s;\n", p.second.c_str(), p.first.c_str());
    }

    inGeneration = false;

    delegateShims.clear();
    referencedClasses.clear();
    typedefShims.clear();
}

void ShimTracker::dumpForwardDecls(FILE* outHeader, FILE* outImpl, FILE* cheatHeader) {
    // Create function prototypes if needed.
    if (!referencedClasses.empty())
        fwprintf(cheatHeader, L"\n");
    bool haveProto = false;
    for (auto p : referencedClasses) {
        if (!p.second.toObjc || p.second.toObjc->isBuiltin())
            continue;
        wstring proto = p.second.toObjc->prototype(p.second);
        if (!proto.empty()) {
            haveProto = true;
            fwprintf(cheatHeader, L"%s;\n", proto.c_str());
        }
    }

    // class forward references.
    size_t width = 0;
    if (!referencedClasses.empty() && haveProto)
        fwprintf(cheatHeader, L"\n");

    for (auto p : referencedClasses) {
        auto c = p.first;
        auto ti = p.second;

        if (!ti.isContainer() && !ti.isFundamentalType && !ti.isValueType && !ti.isEnumType)
            continue;

        size_t idx = c.find(L'<'); // strip protocols.
        if (idx != wstring::npos)
            c = c.substr(0, idx);

        if (!width) {
            fwprintf(cheatHeader, L"@class %s", c.c_str());
        } else {
            fwprintf(cheatHeader, L", %s", c.c_str());
        }

        width += c.size();
        if (width >= 120) {
            width = 0;
            fwprintf(cheatHeader, L";\n");
        }
    }
    if (width)
        fwprintf(cheatHeader, L";\n");
    fwprintf(cheatHeader, L"\n");
}

wstring ShimTracker::getTypedefName(const wstring& type) {
    assert(type.find(L"/*") == wstring::npos); // This means you are probably passing in an objc type here.

    if (!badForMacros(type))
        return type;

    wstring newType = mangledNameForTypedef(type);
    auto it = typedefShims.find(newType);
    if (it != typedefShims.end()) {
        assert(it->second == type); // Need to change mangling "algorithm" if you hit this.
    }
    typedefShims[newType] = type;

    return newType;
}

void ShimTracker::addref(const WinrtType& t) {
    if (inGeneration) {
        assert(!"this is a very bad time to add class refs.");
        return;
    }

    if (t.isValueType || t.isFundamentalType || t.isEnumType)
        return;

    wstring fullname = t.getFullObjcTypename();

    if (referencedClasses.find(fullname) == referencedClasses.end()) {
        WinrtType t2 = t;
        referencedClasses[fullname] = t2;
        for (auto tp : t.templateParams)
            addref(tp);
    }
}
