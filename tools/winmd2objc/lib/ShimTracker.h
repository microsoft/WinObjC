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

#include "TypeInfo.h"

struct DelegateShimInfo {
    WinrtType type;
    wstring returnType;
};

class ShimTracker {
    bool inGeneration = false;
    map<wstring, set<wstring>> generatedShims;
    map<wstring, wstring> typedefShims;
    map<wstring, WinrtType> referencedClasses;
    map<wstring, wstring>& namespaceMap;

public:
    ShimTracker(map<wstring, wstring>& map);

protected:
    void dumpForwardDecls(FILE* outHeader, FILE* outImpl, FILE* cheatHeader);

public:
    map<wstring, DelegateShimInfo> delegateShims;

    void dumpAndReset(const wstring& ns, FILE* outHeader, FILE* outImpl, FILE* cheatHeader);

    void addref(const WinrtType& t);

    wstring getTypedefName(const wstring& type);
};
