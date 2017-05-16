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

#include "ObjectModel.h"
#include "precompiled.h"

void ResolveAssemblyRefs(shared_ptr<MetaDataConvert> convert,
                         wstring fileName,
                         wstring dir,
                         map<wstring, shared_ptr<MetaDataConvert>>& mdMap,
                         map<wstring, shared_ptr<ObjectModel::Symbol>>& symMap,
                         unordered_set<shared_ptr<MetaDataConvert>>& loadedDeps,
                         const MetaDataConvert::NamespaceDomain& nsDom);

// Collapses namespace collisions into a single canonical NameSpace
// (ie. multiple WinMD files define types in the same namespace)
class NamespaceCollector : public ObjectModel::Visitor {
    map<wstring, shared_ptr<ObjectModel::NameSpace>>& _namespaces;

public:
    NamespaceCollector(map<wstring, shared_ptr<ObjectModel::NameSpace>>& namespaces) : _namespaces(namespaces) {
    }

    virtual void Visit(const shared_ptr<ObjectModel::NameSpace>& ns);
};