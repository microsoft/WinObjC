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

#include "precompiled.h"
#include "ObjectModel.h"

void ResolveAssemblyRefs(std::shared_ptr<MetaDataConvert> convert,
                         std::wstring fileName,
                         std::wstring dir,
                         std::map<std::wstring, std::shared_ptr<MetaDataConvert>>& mdMap,
                         std::map<std::wstring, std::shared_ptr<ObjectModel::Symbol>>& symMap,
                         std::unordered_set<std::shared_ptr<MetaDataConvert>>& loadedDeps,
                         const MetaDataConvert::NamespaceDomain& nsDom);

// Collapses namespace collisions into a single canonical NameSpace
// (ie. multiple WinMD files define types in the same namespace)
class NamespaceCollector : public ObjectModel::Visitor {
    std::map<std::wstring, std::shared_ptr<ObjectModel::NameSpace>>& _namespaces;

public:
    NamespaceCollector(std::map<std::wstring, std::shared_ptr<ObjectModel::NameSpace>>& namespaces) : _namespaces(namespaces) {
    }

    virtual void Visit(const std::shared_ptr<ObjectModel::NameSpace>& ns);
};