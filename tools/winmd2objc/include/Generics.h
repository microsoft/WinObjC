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

class ShimTracker;
class ToObjcTypeConvertor;

struct WinrtContainerInfo {
    ContainerType type;
    std::wstring wrlTemplate; // for actual implementation.
    std::wstring wrlInterface; // for ABI interface.
    std::wstring classnameStart;
    std::wstring objcType; // type for output args & return values.  eg NSMutableArray

    // type acceptable for input params.  eg an id<NSFastEnum>
    // will work where an NSMutableArray would be a better output type.
    std::wstring objcInputType;

    std::wstring parentInterface; // superclass for the adapter of this class.
    std::wstring implMacro; // standard type decl.
    std::wstring implInheritedMacro; // used when subclassing from wrlTemplate.
    std::wstring toWrlFunc;
    bool isInheritable; // suppress warnings when inheriting.
    bool isSupportedInheritable; // can actually inherit (subset of above).
    bool asInputParam;
    bool asOutputParam;
    ToObjcTypeConvertor* objcConvertor;
    size_t subtypes;
    std::wstring adapterName; // The internal adapter for this type, inherits from parentInterface.
    std::wstring implName; // The name of the interface.
    std::wstring implInheritedName; // The name of the interface for inherited containers.
    std::wstring implClassName; // The name of the class which provides method implementations.
    std::wstring fullImplClassName; // The name of the class which provides full method implementations.
};

typedef std::set<std::wstring> DeclState;

const WinrtContainerInfo& getContainerInfo(ContainerType ct);
const WinrtContainerInfo& getContainerInfo(const std::wstring& typeName);

bool HandleInheritedContainerDecl(const std::shared_ptr<ObjectModel::Generic>& cls, DeclState& clsState, FILE* outHeader);

bool HandleInheritedContainerImpl(const std::shared_ptr<ObjectModel::RuntimeClass>& cls,
                                  const std::shared_ptr<ObjectModel::Generic>& interfaceCls,
                                  const SymbolTable& types,
                                  ShimTracker& shims,
                                  FILE* outImpl);

bool HandleContainer(const std::shared_ptr<ObjectModel::Generic>& gen, WinrtType& ret, const SymbolTable& types, ShimTracker& shims);
bool HandleCArray(const std::shared_ptr<ObjectModel::Symbol>& type, WinrtType& ret, const SymbolTable& types, ShimTracker& shims);

// TODO: C array interface here -- need typename and inner type.  (Maybe do this with gen above, too
//       ie, convert the parameter types first, then call HandleContainer() as it is now).

bool HandleTypedDelegates(const std::shared_ptr<ObjectModel::Generic>& gen,
                          const std::wstring& typeName,
                          WinrtType& ret,
                          const SymbolTable& types,
                          ShimTracker& shims);
