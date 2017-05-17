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

#include "WinrtType.h"
#include "CodeGenModel.h"

struct ReturnHandler {
    std::wstring returnVal;
    std::wstring returnType;
    std::wstring wrlType;
    std::wstring wrlBaseType;
    bool needsARCAnnotation = false;
    // Params to add to the message signature (for callbacks since we aren't returning them):
    std::vector<ObjC::MethodSig::NameTypeVar> newParams;

    std::wstring header;
    std::wstring footer;
};

class ShimTracker;

// These are dumb text conversions to find the equivalent names in our implementations:
std::wstring midlToWrlType(const std::wstring& midlType);
std::wstring mapNamespacedType(const std::wstring& midlType);

bool basicTypeToWinrt(std::wstring& wrtType, const std::wstring& basicType);

ReturnHandler handleReturnType(const std::shared_ptr<ObjectModel::MemberInfo>& memberInfo, const SymbolTable& _types, ShimTracker& _shims);
WinrtType winrtTypeInfo(const std::shared_ptr<ObjectModel::Symbol>& internalType,
                        const SymbolTable& types,
                        ShimTracker& shims,
                        bool box = false);

bool winrtTypeInfoBasic(const std::wstring& typeName, WinrtType* out);

inline bool hasPrefix(const std::wstring& str, const std::wstring& prefix) {
    if (prefix.length() <= str.length()) {
        return str.substr(0, prefix.length()) == prefix;
    }
    return false;
}
