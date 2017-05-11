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
#include <DepResolution.h>

using namespace std;
using namespace ObjectModel;

void ResolveAssemblyRefs(shared_ptr<MetaDataConvert> convert,
                         wstring fileName,
                         wstring dir,
                         map<wstring, shared_ptr<MetaDataConvert>>& mdMap,
                         map<wstring, shared_ptr<Symbol>>& symMap,
                         unordered_set<shared_ptr<MetaDataConvert>>& loadedDeps,
                         const MetaDataConvert::NamespaceDomain& nsDom) {
    // Resolve further references
    HCORENUM refEnum = NULL;
    mdAssemblyRef refs[32];
    ULONG nRefs;
    convert->Scope()->EnumAssemblyRefs(&refEnum, refs, 32, &nRefs);

    loadedDeps.insert(convert);

    for (unsigned int i = 0; i < nRefs; i++) {
        wchar_t refName[1024];
        wchar_t refNameVersion[4];
        ASSEMBLYMETADATA mData = { 0 };
        convert->Scope()->GetAssemblyRefProps(refs[i], NULL, NULL, refName, 1023, NULL, &mData, NULL, NULL, NULL);
        wstring refFileName;
        if (dir != L"" && *dir.rbegin() != L'\\') {
            dir += L'\\';
        }

        refFileName = dir + refName + L"\\" + _itow(mData.usMajorVersion, refNameVersion, 10) + L"." +
                      _itow(mData.usMinorVersion, refNameVersion, 10) + L"." + _itow(mData.usBuildNumber, refNameVersion, 10) + L"." +
                      _itow(mData.usRevisionNumber, refNameVersion, 10) + L"\\" + refName + L".winmd";

        if (!PathFileExistsW(refFileName.c_str())) {
            // Fallback to looking in the same directory
            refFileName = dir + refName + L".winmd";
        }

        if (!PathFileExistsW(refFileName.c_str())) {
            wprintf(L"Reference not found: %s\n", refName);
            continue;
        }

        std::transform(refFileName.begin(), refFileName.end(), refFileName.begin(), ::tolower);
        if (mdMap.find(refFileName) == mdMap.end()) {
            wprintf(L"Attempt to load dependent winmd: %s ... ", refFileName.c_str());

            shared_ptr<MetaDataConvert> refConvert(new MetaDataConvert(refFileName, symMap));
            mdMap[refFileName] = refConvert;
            try {
                HRESULT refHr = refConvert->ConvertMetaData(nsDom);
                if (FAILED(refHr)) {
                    wprintf(L"Failed! (hr=0x%08X)\n", refHr);
                } else {
                    // depMap[scope].push_back(wstring(refName) + L".h>);

                    wprintf(L"Success!\n");
                    // Comment this out, if you don't want to recurse the entire dep tree.
                    ResolveAssemblyRefs(refConvert, refFileName, dir, mdMap, symMap, loadedDeps, nsDom);
                }
            } catch (exception e) {
                printf("Failed! (e=\"%s\")\n", e.what());
            }
        }
    }
}

void NamespaceCollector::Visit(const shared_ptr<NameSpace>& ns) {
    shared_ptr<NameSpace>& curNs = _namespaces[ns->Name];

    // Big TODO here, we need to know if CustomAttrs, etc, are unique to the namespace.
    if (!curNs) {
        curNs = shared_ptr<NameSpace>(new NameSpace(*ns));
        return;
    }

    // We're making the assumption here that any interfaces, structs, delegates, etc. can only be defined in one contract.
    for (auto item : ns->RuntimeClasses) {
        curNs->RuntimeClasses.push_back(item);
    }
    for (auto item : ns->Interfaces) {
        curNs->Interfaces.push_back(item);
    }
    for (auto item : ns->Delegates) {
        curNs->Delegates.push_back(item);
    }
    for (auto item : ns->Enums) {
        curNs->Enums.push_back(item);
    }
    for (auto item : ns->Structs) {
        curNs->Structs.push_back(item);
    }
}
