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

#include "CodeGenModel.h"
#include "WinrtType.h"

struct ReturnHandler {
    wstring returnVal;
    wstring returnType;
    wstring wrlType;
    wstring wrlBaseType;
    bool needsARCAnnotation = false;
    // Params to add to the message signature (for callbacks since we aren't returning them):
    vector<ObjC::MethodSig::NameTypeVar> newParams;

    wstring header;
    wstring footer;
};

class ShimTracker;

// These are dumb text conversions to find the equivalent names in our implementations:
wstring midlToWrlType(const wstring& midlType);
wstring mapNamespacedType(const wstring& midlType);

bool basicTypeToWinrt(wstring& wrtType, const wstring& basicType);

ReturnHandler handleReturnType(const shared_ptr<MemberInfo>& memberInfo, const SymbolTable& _types, ShimTracker& _shims);
WinrtType winrtTypeInfo(const shared_ptr<ObjectModel::Symbol>& internalType,
                        const SymbolTable& types,
                        ShimTracker& shims,
                        bool box = false);

bool winrtTypeInfoBasic(const wstring& typeName, WinrtType* out);

inline bool hasPrefix(const wstring& str, const wstring& prefix) {
    if (prefix.length() <= str.length()) {
        return str.substr(0, prefix.length()) == prefix;
    }
    return false;
}
