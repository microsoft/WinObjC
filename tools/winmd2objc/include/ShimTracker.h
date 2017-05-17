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

#include "TypeInfo.h"

struct DelegateShimInfo {
    WinrtType type;
    std::wstring returnType;
};

class ShimTracker {
    bool inGeneration = false;
    std::map<std::wstring, std::set<std::wstring>> generatedShims;
    std::map<std::wstring, std::wstring> typedefShims;
    std::map<std::wstring, WinrtType> referencedClasses;
    std::map<std::wstring, std::wstring>& namespaceMap;

public:
    ShimTracker(std::map<std::wstring, std::wstring>& map);

protected:
    void dumpForwardDecls(FILE* outHeader, FILE* outImpl, FILE* cheatHeader);

public:
    std::map<std::wstring, DelegateShimInfo> delegateShims;

    void dumpAndReset(const std::wstring& ns, FILE* outHeader, FILE* outImpl, FILE* cheatHeader);

    void addref(const WinrtType& t);

    std::wstring getTypedefName(const std::wstring& type);
};
