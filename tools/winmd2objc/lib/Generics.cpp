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

// Generic typeinfo code.
//
#include "Precompiled.h"
#include <TypeInfo.h>
#include <Misc.h>
#include <Generics.h>
#include <ShimTracker.h>

using namespace std;
using namespace ObjectModel;

namespace {
wstring _GetWRLCreatorFunctionName(const WinrtContainerInfo& ci, const WinrtType& t, wstring& tpWRL) {
    wstring wrlCreatorT;
    if (ci.type == ContainerType::Nullable) {
        const auto& tp = t.templateParams[0];
        wrlCreatorT = ci.toWrlFunc + L"<" + tp.aggregateWrlType() + L">";
    } else {
        wstring tp;
        tpWRL.clear();
        for (auto curp : t.templateParams) {
            if (!tp.empty()) {
                tp += L", ";
            }

            if (!tpWRL.empty()) {
                tpWRL += L", ";
            }

            // Container of container(s) requires the convertor function, and for container of basic types we supply a default dummy
            // convertor function.
            if (curp.isContainer()) {
                tp += curp.containerInfo().classnameStart + L", " + curp.aggregateWrlType() + L', ' + baseType(curp.getFullObjcTypename()) +
                      L"_create";
            } else {
                tp += baseType(curp.getFullObjcTypename()) + L", " + curp.aggregateWrlType();
            }

            tpWRL += L"typename ABI::Windows::Foundation::Internal::GetLogicalType<" + curp.aggregateWrlType() + L">::type";
        }
        wrlCreatorT = ci.toWrlFunc + L"<" + tp + L">";
    }

    return wrlCreatorT;
}

wstring _GetWRLCreatorFunctionName(const WinrtContainerInfo& ci, const WinrtType& t) {
    wstring tpWRL;
    return _GetWRLCreatorFunctionName(ci, t, tpWRL);
}

class SingleObjArrayConvertor : public SingleObjContainerConvertor {
public:
    virtual wstring getContainer(const WinrtContainerInfo& ci, wstring templateArg) const {
        return ci.wrlInterface + L"<" + templateArg + L">";
    }

    virtual wstring getImplClassContainer(const WinrtContainerInfo& ci, wstring templateArg) const {
        return getContainer(ci, templateArg);
    }

    virtual wstring implementation(const WinrtType& t, ShimTracker& shims, bool inheritedType) override {
        auto ci = t.containerInfo();
        const auto& it = t.templateParams[0];
        wstring wrlT = shims.getTypedefName(it.wrlFullName());
        wstring templateT = shims.getTypedefName(it.wrlFullName(false));
        wstring objcT;
        wstring objcCreatorT;
        wstring wrlCreatorT;

        if (it.isContainer()) {
            objcT = it.containerInfo().classnameStart;
            objcCreatorT = baseType(it.getFullObjcTypename()) + L"_create";
            wrlCreatorT = _GetWRLCreatorFunctionName(ci, t);
        } else {
            objcT = baseType(it.getFullObjcTypename());
            objcCreatorT = L"dummyObjCCreator";
            wrlCreatorT = L"dummyWRLCreator";
        }

        return wstring(L"{\n") + ci.fullImplClassName + L"<" + wrlT + L", " + getImplClassContainer(ci, templateT) + L", " + objcT + L", " +
               templateT + L", " + objcCreatorT + L"," + wrlCreatorT + L"> _array;\n}\n" +
               (inheritedType ? ci.implInheritedMacro : ci.implMacro) + L"(self.comObj, " + objcT + L", " + wrlT + L", " + templateT + L")";
    }

    wstring instantiator(const WinrtType& t, ShimTracker& shims) {
        // Note variable name of "val" comes from the prototype above.
        auto ci = t.containerInfo();
        const auto& it = t.templateParams[0];
        wstring wrlT = shims.getTypedefName(it.wrlFullName());
        wstring templateT = shims.getTypedefName(it.wrlFullName(false));
        wstring objcT;
        wstring objcCreatorT;
        wstring wrlCreatorT;

        if (it.isContainer()) {
            objcT = it.containerInfo().classnameStart;
            objcCreatorT = baseType(it.getFullObjcTypename()) + L"_create";
            wrlCreatorT = _GetWRLCreatorFunctionName(ci, t);
        } else {
            objcT = baseType(it.getFullObjcTypename());
            objcCreatorT = L"dummyObjCCreator";
            wrlCreatorT = L"dummyWRLCreator";
        }

        return wstring(L"std::unique_ptr<") + ci.parentInterface + L"> adapter = std::make_unique<" + ci.adapterName + L"<" +
               getContainer(ci, templateT) + L",\n    " + ci.implClassName + L"<" + wrlT + L", " + getImplClassContainer(ci, templateT) +
               L", " + objcT + L", " + templateT + L", " + objcCreatorT + L", " + wrlCreatorT + L">>>(val);\n" + L"    return [[[" +
               ci.implInheritedName + L" alloc] initWithAdapter:std::move(adapter)] autorelease]";
    }
};
SingleObjArrayConvertor singleArrayConv;

class ObsArrayConvertor : public SingleObjArrayConvertor {
public:
    virtual wstring getImplClassContainer(const WinrtContainerInfo& ci, wstring templateT) const override {
        return L"IVector<" + templateT + L">";
    }
};
ObsArrayConvertor obsArrayConvertor;

class CArrayConvertor : public SingleObjArrayConvertor {
public:
    virtual wstring prototype(const WinrtType& t) override {
        return wstring(L"id ") + t.getFullObjcTypename() + L"_create(UINT32 size, " + t.wrlFullName() + L" val)";
    }

    virtual wstring call(const WinrtType& t, const wstring& param) override {
        return baseType(t.getFullObjcTypename()) + L"_create(" + param + L"Len, " + param + L")";
    }

    virtual wstring implementation(const WinrtType& t, ShimTracker& shims, bool inheritedType) override {
        auto ci = t.containerInfo();
        const auto& it = t.templateParams[0];
        wstring wrlT = shims.getTypedefName(it.wrlFullName());
        wstring containerT = L"IVector<void*>";
        wstring templateT = shims.getTypedefName(it.wrlFullName(false));

        wstring objcT;
        wstring objcCreatorT;
        if (it.isContainer()) {
            objcT = it.containerInfo().classnameStart;
            objcCreatorT = baseType(it.getFullObjcTypename()) + L"_create";
        } else {
            objcT = baseType(it.getFullObjcTypename());
            objcCreatorT = L"dummyObjCCreator";
        }

        return wstring(L"{\n    ") + ci.fullImplClassName + L"<" + wrlT + L", " + objcT + L", " + objcCreatorT + L"> _array;\n}\n" +
               (inheritedType ? ci.implInheritedMacro : ci.implMacro) + L"(nullptr, " + objcT + L", " + wrlT + L", " + templateT + L")";
    }

    virtual wstring instantiator(const WinrtType& t, ShimTracker& shims) override {
        // Note variable name of "val" and "size" comes from the prototype above.
        auto ci = t.containerInfo();
        const auto& it = t.templateParams[0];
        wstring wrlT = shims.getTypedefName(it.wrlFullName());
        wstring containerT = L"IVector<void*>";

        wstring objcT;
        wstring objcCreatorT;
        if (it.isContainer()) {
            objcT = it.containerInfo().classnameStart;
            objcCreatorT = baseType(it.getFullObjcTypename()) + L"_create";
        } else {
            objcT = baseType(it.getFullObjcTypename());
            objcCreatorT = L"dummyObjCCreator";
        }

        return wstring(L"std::unique_ptr<") + ci.parentInterface + L"> adapter = std::make_unique<" + ci.adapterName + L"<" + wrlT + L", " +
               ci.implClassName + L"<" + wrlT + L", " + objcT + L", " + objcCreatorT + L">>>(size, val);\n" + L"    return [[[" +
               ci.implInheritedName + L" alloc] initWithAdapter:std::move(adapter)] autorelease]";
    }
};
CArrayConvertor cArrayConv;

class MapConvertor : public SingleObjContainerConvertor {
public:
    virtual wstring getContainer(const WinrtContainerInfo& ci, wstring wrlK, wstring wrlVT) const {
        return ci.wrlInterface + L"<" + wrlK + L", " + wrlVT + L">";
    }

    virtual wstring getImplClassContainer(const WinrtContainerInfo& ci, wstring wrlK, wstring wrlVT) const {
        return getContainer(ci, wrlK, wrlVT);
    }

    virtual wstring implementation(const WinrtType& t, ShimTracker& shims, bool inheritedType) override {
        const auto& ci = t.containerInfo();
        const auto& keyType = t.templateParams[0];
        const auto& valueType = t.templateParams[1];
        wstring wrlK = shims.getTypedefName(keyType.wrlFullName());
        wstring wrlKT = shims.getTypedefName(keyType.wrlFullName(false));
        wstring wrlV = shims.getTypedefName(valueType.wrlFullName());
        wstring wrlVT = shims.getTypedefName(valueType.wrlFullName(false));
        wstring objcK;
        wstring objcV;
        wstring objcCreatorK;
        wstring objcCreatorV;
        wstring wrlCreatorK;
        wstring wrlCreatorV;

        if (keyType.isContainer()) {
            objcK = keyType.containerInfo().classnameStart;
            objcCreatorK = baseType(keyType.getFullObjcTypename()) + L"_create";
            wrlCreatorK = _GetWRLCreatorFunctionName(keyType.containerInfo(), keyType);
        } else {
            objcK = baseType(keyType.getFullObjcTypename());
            objcCreatorK = L"dummyObjCCreator";
            wrlCreatorK = L"dummyWRLCreator";
        }

        if (valueType.isContainer()) {
            objcV = valueType.containerInfo().classnameStart;
            objcCreatorV = baseType(valueType.getFullObjcTypename()) + L"_create";
            wrlCreatorV = _GetWRLCreatorFunctionName(valueType.containerInfo(), valueType);
        } else {
            objcV = baseType(valueType.getFullObjcTypename());
            objcCreatorV = L"dummyObjCCreator";
            wrlCreatorV = L"dummyWRLCreator";
        }

        return wstring(L"{\n    ") + ci.fullImplClassName + L"<" + wrlKT + L"," + wrlK + L", " + wrlVT + L", " + wrlV + L", " + objcK +
               L", " + objcV + L", " + getImplClassContainer(ci, wrlK, wrlVT) + L", " + objcCreatorK + L", " + objcCreatorV + L", " +
               wrlCreatorK + L", " + wrlCreatorV + L"> _map;\n}\n" + (inheritedType ? ci.implInheritedMacro : ci.implMacro) +
               L"(self.comObj, " + baseType(t.getFullObjcTypename()) + L", " + wrlK + L", " + wrlKT + L", " + wrlV + L", " + wrlVT + L", " +
               objcK + L", " + objcV + L")";
    }

    virtual wstring instantiator(const WinrtType& t, ShimTracker& shims) {
        // Note variable name of "val" comes from the prototype above.
        const auto& keyType = t.templateParams[0];
        const auto& valueType = t.templateParams[1];
        wstring wrlK = shims.getTypedefName(keyType.wrlFullName());
        wstring wrlKT = shims.getTypedefName(keyType.wrlFullName(false));
        wstring wrlV = shims.getTypedefName(valueType.wrlFullName());
        wstring wrlVT = shims.getTypedefName(valueType.wrlFullName(false));
        wstring objcK;
        wstring objcV;
        wstring objcCreatorK;
        wstring objcCreatorV;
        wstring wrlCreatorK;
        wstring wrlCreatorV;

        if (keyType.isContainer()) {
            objcK = keyType.containerInfo().classnameStart;
            objcCreatorK = baseType(keyType.getFullObjcTypename()) + L"_create";
            wrlCreatorK = _GetWRLCreatorFunctionName(keyType.containerInfo(), keyType);
        } else {
            objcK = baseType(keyType.getFullObjcTypename());
            objcCreatorK = L"dummyObjCCreator";
            wrlCreatorK = L"dummyWRLCreator";
        }

        if (valueType.isContainer()) {
            objcV = valueType.containerInfo().classnameStart;
            objcCreatorV = baseType(valueType.getFullObjcTypename()) + L"_create";
            wrlCreatorV = _GetWRLCreatorFunctionName(valueType.containerInfo(), valueType);
        } else {
            objcV = baseType(valueType.getFullObjcTypename());
            objcCreatorV = L"dummyObjCCreator";
            wrlCreatorV = L"dummyWRLCreator";
        }

        const auto& ci = t.containerInfo();
        wstring keyEnumeratorAdapterTypeT = wstring(L"DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<") + wrlKT + L"," + wrlK +
                                            L"," + objcK + L", " + wrlVT + L">>";

        wstring baseTypeT = ci.implClassName + L"<" + wrlKT + L"," + wrlK + L", " + wrlVT + L", " + wrlV + L", " + objcK + L", " + objcV +
                            L", " + getImplClassContainer(ci, wrlK, wrlVT) + L", " + objcCreatorK + L", " + objcCreatorV + L", " +
                            wrlCreatorK + L", " + wrlCreatorV + L">";

        return wstring(L"std::unique_ptr<") + ci.parentInterface + L"> adapter = std::make_unique<" + ci.adapterName + L"<" +
               getContainer(ci, wrlK, wrlVT) + L",\n" + L"        " + keyEnumeratorAdapterTypeT + L", \n" + L"        " + baseTypeT +
               L">>(val);\n" + L"    return [[[" + ci.implInheritedName + L" alloc] initWithAdapter:std::move(adapter)] autorelease]";
    }
};
MapConvertor mapConv;

class ObservableMapConvertor : public MapConvertor {
    virtual wstring getImplClassContainer(const WinrtContainerInfo& ci, wstring wrlK, wstring wrlVT) const override {
        return L"IMap<" + wrlK + L", " + wrlVT + L">";
    }
};
ObservableMapConvertor obsMapConv;

class KeyValueConvertor : public SingleObjContainerConvertor {
    wstring instantiator(const WinrtType& t, ShimTracker& shims) {
        // Note variable name of "val" comes from the prototype above.
        const auto& ktype = t.templateParams[0];
        const auto& vtype = t.templateParams[1];
        const auto& ci = t.containerInfo();

        wstring wrlK = shims.getTypedefName(ktype.wrlFullName());
        wstring wrlKT = shims.getTypedefName(ktype.wrlFullName(false));
        wstring wrlV = shims.getTypedefName(vtype.wrlFullName());
        wstring wrlVT = shims.getTypedefName(vtype.wrlFullName(false));
        wstring objcK;
        wstring objcV;
        wstring objcCreatorK;
        wstring objcCreatorV;

        if (ktype.isContainer()) {
            objcK = ktype.containerInfo().classnameStart;
            objcCreatorK = baseType(ktype.getFullObjcTypename()) + L"_create";
        } else {
            objcK = baseType(ktype.getFullObjcTypename());
            objcCreatorK = L"dummyObjCCreator";
        }

        if (vtype.isContainer()) {
            objcV = vtype.containerInfo().classnameStart;
            objcCreatorV = baseType(vtype.getFullObjcTypename()) + L"_create";
        } else {
            objcV = baseType(vtype.getFullObjcTypename());
            objcCreatorV = L"dummyObjCCreator";
        }

        wstring baseTypeT = ci.implClassName + L"<" + wrlK + L", " + wrlKT + L", " + wrlV + L", " + wrlVT + L", " + objcK + L", " + objcV +
                            L", " + objcCreatorK + L", " + objcCreatorV + L">";

        return wstring(L"std::unique_ptr<") + ci.parentInterface + L"> adapter = std::make_unique<" + ci.adapterName + L"<" + baseTypeT +
               L">>();\n" + L"    return _createRtProxyWithAdapter<" + ci.implInheritedName + L", " + ci.parentInterface +
               L">(val, std::move(adapter));\n";
    }

    virtual wstring implementation(const WinrtType& t, ShimTracker& shims, bool inheritedType) override {
        const auto& ktype = t.templateParams[0];
        const auto& vtype = t.templateParams[1];
        const auto& ci = t.containerInfo();

        wstring wrlK = shims.getTypedefName(ktype.wrlFullName());
        wstring wrlKT = shims.getTypedefName(ktype.wrlFullName(false));
        wstring wrlV = shims.getTypedefName(vtype.wrlFullName());
        wstring wrlVT = shims.getTypedefName(vtype.wrlFullName(false));
        wstring objcK;
        wstring objcV;
        wstring objcCreatorK;
        wstring objcCreatorV;

        if (ktype.isContainer()) {
            objcK = ktype.containerInfo().classnameStart;
            objcCreatorK = baseType(ktype.getFullObjcTypename()) + L"_create";
        } else {
            objcK = baseType(ktype.getFullObjcTypename());
            objcCreatorK = L"dummyObjCCreator";
        }

        if (vtype.isContainer()) {
            objcV = vtype.containerInfo().classnameStart;
            objcCreatorV = baseType(vtype.getFullObjcTypename()) + L"_create";
        } else {
            objcV = baseType(vtype.getFullObjcTypename());
            objcCreatorV = L"dummyObjCCreator";
        }

        return wstring(L"{\n    ") + ci.fullImplClassName + L"<" + wrlK + L", " + wrlKT + L", " + wrlV + L", " + wrlVT + L", " + objcK +
               L", " + objcV + L", " + objcCreatorK + L", " + objcCreatorV + L"> kvp;\n}\n" +
               (inheritedType ? ci.implInheritedMacro : ci.implMacro) + L"(self.comObj, " + wrlK + L", " + wrlKT + L", " + wrlV + L", " +
               wrlVT + L", " + objcK + L", " + objcV + L")";
    }
};
KeyValueConvertor kvConv;

class NullableConvertor : public SingleObjConvertor {
    virtual bool isBuiltin() const override {
        return true;
    }
    virtual wstring call(const WinrtType& t, const wstring& paramName) override {
        const auto& tp = t.templateParams[0];
        return L"MakeFromNullable<" + baseType(tp.getFullObjcTypename()) + L", " + tp.aggregateWrlType() + L">::convert(" + paramName +
               L")";
    }
};
NullableConvertor nullableConv;

WinrtContainerInfo errorInfo{ ContainerType::None,
                              L"#error bad container type",
                              L"#error bad container type",
                              L"#error bad container type",
                              L"#error bad container type",
                              L"#error bad container type",
                              L"#error bad container type",
                              L"#error bad container type",
                              L"#error bad container type",
                              L"#error bad container type",
                              false,
                              false,
                              false,
                              false,
                              NULL,
                              0,
                              L"#error bad container type",
                              L"#error bad container type",
                              L"#error bad container type",
                              L"#error bad container type",
                              L"#error bad container type" };

// TODO: BK: this whole mess should be in dot notation.
std::map<ContainerType, const WinrtContainerInfo*>
    containerInfos{ { ContainerType::C_Array, new WinrtContainerInfo{ ContainerType::C_Array,
                                                                      L"",
                                                                      L"",
                                                                      L"RTProxiedNSArray_C",
                                                                      L"NSArray*",
                                                                      L"id<NSFastEnumeration>",
                                                                      L"CArrayAdapter",
                                                                      L"INTEROP_IMPL_C_ARRAY",
                                                                      L"#error not supported",
                                                                      L"ConvertToCArray",
                                                                      true,
                                                                      false,
                                                                      true,
                                                                      true,
                                                                      &cArrayConv,
                                                                      1,
                                                                      L"CArrayAdapterObj",
                                                                      L"RTProxiedNSArray",
                                                                      L"RTProxiedNSArrayFull",
                                                                      L"RTCArrayObj",
                                                                      L"RTCArrayObj" } },
                    { ContainerType::Array, new WinrtContainerInfo{ ContainerType::Array,
                                                                    L"Vector",
                                                                    L"IVector",
                                                                    L"RTProxiedNSMutableArray",
                                                                    L"NSMutableArray*",
                                                                    L"id<NSFastEnumeration>",
                                                                    L"MutableArrayAdapter",
                                                                    L"INTEROP_IMPL_VECTOR",
                                                                    L"INTEROP_IMPL_VECTOR_FULL",
                                                                    L"ConvertToVector",
                                                                    true,
                                                                    true,
                                                                    true,
                                                                    true,
                                                                    &singleArrayConv,
                                                                    1,
                                                                    L"MutableArrayAdapterObj",
                                                                    L"RTProxiedNSMutableArray",
                                                                    L"RTProxiedNSMutableArrayFull",
                                                                    L"RTMutableArrayObj",
                                                                    L"RTMutableArrayObj" } },
                    { ContainerType::ArrayView, new WinrtContainerInfo{ ContainerType::ArrayView,
                                                                        L"VectorView",
                                                                        L"IVectorView",
                                                                        L"RTProxiedNSArray",
                                                                        L"NSArray*",
                                                                        L"id<NSFastEnumeration>",
                                                                        L"ArrayAdapter",
                                                                        L"INTEROP_IMPL_VECTORVIEW",
                                                                        L"INTEROP_IMPL_VECTORVIEW_FULL",
                                                                        L"ConvertToVectorView",
                                                                        true,
                                                                        true,
                                                                        true,
                                                                        true,
                                                                        &singleArrayConv,
                                                                        1,
                                                                        L"ArrayAdapterObj",
                                                                        L"RTProxiedNSArray",
                                                                        L"RTProxiedNSArrayFull",
                                                                        L"RTArrayObj",
                                                                        L"RTArrayObj" } },
                    { ContainerType::ObservableArray, new WinrtContainerInfo{ ContainerType::ObservableArray,
                                                                              L"ObservableVector",
                                                                              L"IObservableVector",
                                                                              L"RTProxiedObservableNSMutableArray",
                                                                              L"NSMutableArray<RTObservableCollection>*",
                                                                              L"id<NSFastEnumeration>",
                                                                              L"ObservableArrayAdapter",
                                                                              L"INTEROP_IMPL_OBSVECTOR",
                                                                              L"INTEROP_IMPL_OBSVECTOR_FULL",
                                                                              L"#error not implemented",
                                                                              true,
                                                                              true,
                                                                              false,
                                                                              true,
                                                                              &obsArrayConvertor,
                                                                              1,
                                                                              L"ObservableArrayAdapterObj",
                                                                              L"RTProxiedObservableNSMutableArray",
                                                                              L"RTProxiedObservableNSMutableArray",
                                                                              L"RTObservableArrayObj",
                                                                              L"RTObservableArrayObjFull" } },
                    { ContainerType::Map, new WinrtContainerInfo{ ContainerType::Map,
                                                                  L"Map",
                                                                  L"IMap",
                                                                  L"RTProxiedNSMutableDictionary",
                                                                  L"NSMutableDictionary*",
                                                                  L"NSDictionary*",
                                                                  L"MutableDictionaryAdapter",
                                                                  L"INTEROP_IMPL_MAP_INITWITH",
                                                                  L"INTEROP_IMPL_MAP",
                                                                  L"ConvertToMap",
                                                                  true,
                                                                  true,
                                                                  true,
                                                                  true,
                                                                  &mapConv,
                                                                  2,
                                                                  L"MutableDictionaryAdapterObj",
                                                                  L"RTProxiedNSMutableDictionary",
                                                                  L"RTProxiedNSMutableDictionary",
                                                                  L"RTMapObj",
                                                                  L"RTMapObj" } },
                    { ContainerType::MapView, new WinrtContainerInfo{ ContainerType::MapView,
                                                                      L"MapView",
                                                                      L"IMapView",
                                                                      L"RTProxiedNSDictionary",
                                                                      L"NSDictionary*",
                                                                      L"NSDictionary*",
                                                                      L"DictionaryAdapter",
                                                                      L"INTEROP_IMPL_MAPVIEW_INITWITH",
                                                                      L"INTEROP_IMPL_MAPVIEW",
                                                                      L"ConvertToMapView",
                                                                      true,
                                                                      true,
                                                                      true,
                                                                      true,
                                                                      &mapConv,
                                                                      2,
                                                                      L"DictionaryAdapterObj",
                                                                      L"RTProxiedNSDictionary",
                                                                      L"RTProxiedNSDictionary",
                                                                      L"RTMapViewObj",
                                                                      L"RTMapViewObj" } },
                    { ContainerType::ObservableMap, new WinrtContainerInfo{ ContainerType::ObservableMap,
                                                                            L"ObservableMap",
                                                                            L"IObservableMap",
                                                                            L"RTProxiedObservableNSMutableDictionary",
                                                                            L"NSMutableDictionary<RTObservableCollection>*",
                                                                            L"NSDictionary*",
                                                                            L"ObservableDictionaryAdapter",
                                                                            L"INTEROP_IMPL_OBSMAP",
                                                                            L"INTEROP_IMPL_OBSMAP_FULL",
                                                                            L"#error not implemented",
                                                                            true,
                                                                            true,
                                                                            false,
                                                                            true,
                                                                            &obsMapConv,
                                                                            2,
                                                                            L"ObservableDictionaryAdapterObj",
                                                                            L"RTProxiedObservableNSMutableDictionary",
                                                                            L"RTProxiedObservableNSMutableDictionary",
                                                                            L"RTObservableMapObj",
                                                                            L"RTObservableMapObjFull" } },
                    { ContainerType::Iterable, new WinrtContainerInfo{ ContainerType::Iterable,
                                                                       L"Vector",
                                                                       L"IIterable",
                                                                       L"RTProxiedIterableNSArray",
                                                                       L"id<NSFastEnumeration>",
                                                                       L"id<NSFastEnumeration>",
                                                                       L"IterableArrayAdapter",
                                                                       L"INTEROP_IMPL_ITERABLE",
                                                                       L"INTEROP_IMPL_ITERABLE_FULL",
                                                                       L"ConvertToIterable",
                                                                       true,
                                                                       false,
                                                                       true,
                                                                       true,
                                                                       &singleArrayConv,
                                                                       1,
                                                                       L"IterableArrayAdapterObj",
                                                                       L"RTProxiedIterableNSArray",
                                                                       L"RTProxiedIterableNSArrayFull",
                                                                       L"RTIterableObj",
                                                                       L"RTIterableObj" } },
                    { ContainerType::KeyValuePair, new WinrtContainerInfo{ ContainerType::KeyValuePair,
                                                                           L"KeyValuePair",
                                                                           L"IKeyValuePair",
                                                                           L"RTProxiedKeyValuePair",
                                                                           L"RTKeyValuePair*",
                                                                           L"RTKeyValuePair*",
                                                                           L"KeyValuePairAdapter",
                                                                           L"INTEROP_IMPL_KVP",
                                                                           L"#error not applicable",
                                                                           L"#error not implemented",
                                                                           false,
                                                                           false,
                                                                           false,
                                                                           true,
                                                                           &kvConv,
                                                                           2,
                                                                           L"KeyValuePairAdapterObj",
                                                                           L"RTProxiedKeyValuePair",
                                                                           L"RTProxiedKeyValuePair",
                                                                           L"RTKeyValuePairObj",
                                                                           L"RTKeyValuePairObj" } },
                    { ContainerType::Nullable, new WinrtContainerInfo{ ContainerType::Nullable,
                                                                       L"BoxedObj",
                                                                       L"IReference",
                                                                       L"Nullable",
                                                                       L"id",
                                                                       L"id",
                                                                       L"",
                                                                       L"",
                                                                       L"",
                                                                       L"BuildNullable",
                                                                       false,
                                                                       false,
                                                                       true,
                                                                       true,
                                                                       &nullableConv,
                                                                       1,
                                                                       L"",
                                                                       L"",
                                                                       L"",
                                                                       L"",
                                                                       L"" } } };

bool HandleContainerCommon(const shared_ptr<ObjectModel::Symbol>& type,
                           const vector<shared_ptr<ObjectModel::Symbol>>& params,
                           WinrtType& ret,
                           const WinrtContainerInfo& info,
                           const SymbolTable& types,
                           ShimTracker& shims) {
    if (params.size() != info.subtypes) {
        throw L"Generic of type " + info.wrlTemplate + L" has a bad number of template parameters.";
    }

    ret.setObjcType(info.objcType);
    ret.setWrlType(info.wrlInterface, info.wrlTemplate);
    ret.isValueType = false;
    ret.isFundamentalType = false;
    ret.isEnumType = false;
    ret.container = info.type;
    ret.asInputSupported = info.asInputParam;
    ret.asOutputSupported = info.asOutputParam;

    // build template params, and description for decorated typename.
    wstring cmtTypes;
    for (auto p : params) {
        auto type = winrtTypeInfo(p, types, shims, true);
        ret.templateParams.push_back(type);
        if (!cmtTypes.empty())
            cmtTypes += L", ";
        cmtTypes += type.getObjcType();
    }

    // Sometimes we'll have nested comments with collections of collection, so make the nested comments
    // into templates! Wretched hack but amusingly correct!
    replaceAll(cmtTypes, L"/*", L"<");
    replaceAll(cmtTypes, L"*/", L">");

    ret.subtypeComment = cmtTypes;

    ret.toObjc = info.objcConvertor;

    if (info.type == ContainerType::Nullable) { // TODO: don't special case this.
        ret.convertFnWrl = [=](wstring p, bool setter = false) {
            wstring wrlConvertorFunc = _GetWRLCreatorFunctionName(info, ret);
            const auto& tp = ret.templateParams[0];
            return wrlConvertorFunc + L"(" + p + L")";
        };
    } else {
        ret.convertFnWrl = [=](wstring p, bool setter = false) {
            wstring tpWRL;
            wstring wrlConvertorFunc = _GetWRLCreatorFunctionName(info, ret, tpWRL);
            return L"static_cast<" + info.wrlInterface + L"<" + tpWRL + L">*>(" + wrlConvertorFunc + L"(" + p + L")" +
                   (setter ? L".Detach()" : L".Get()") + L")";
        };
    }

    assert(ret.toObjc);
    return true;
}
}

const WinrtContainerInfo& getContainerInfo(ContainerType ct) {
    auto it = containerInfos.find(ct);
    if (it == containerInfos.end())
        return errorInfo;

    return *(it->second);
}

const WinrtContainerInfo& getContainerInfo(const wstring& typeName) {
    wstring ot = getObjType(typeName);
    for (auto p : containerInfos) {
        if (p.second->wrlInterface == ot) {
            return *(p.second);
        }
    }
    return errorInfo;
}

bool HandleInheritedContainerDecl(const std::shared_ptr<Generic>& gen, DeclState& clsState, FILE* outHeader) {
    if (!gen)
        return false;

    const WinrtContainerInfo& ci = getContainerInfo(gen->Name);
    if (ci.isSupportedInheritable) {
        if (ci.type == ContainerType::ArrayView || isArray(ci.type)) {
            if (clsState.find(L"VView") == clsState.end()) {
                clsState.insert(L"VView");
                fwprintf(outHeader,
                         L"%s\n",
                         L"- (unsigned int)count;\n"
                         L"- (id)objectAtIndex:(unsigned)idx;\n"
                         L"- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state\n"
                         L"                                  objects:(id __unsafe_unretained [])buffer\n"
                         L"                                    count:(NSUInteger)len;\n");
            }
        }

        if (isArray(ci.type)) {
            if (clsState.find(L"Vec") == clsState.end()) {
                clsState.insert(L"Vec");
                fwprintf(outHeader,
                         L"%s\n",
                         L"- (void)insertObject: (id)obj atIndex: (NSUInteger)idx;\n"
                         L"- (void)removeObjectAtIndex: (NSUInteger)idx;\n"
                         L"- (void)replaceObjectAtIndex: (NSUInteger)idx withObject: (id)obj;\n"
                         L"- (void)addObject: (id)obj;\n"
                         L"- (void)removeLastObject;\n");
                if (isObservable(ci.type)) {
                    fwprintf(outHeader,
                             L"- (EventRegistrationToken)addObserver: (RTCollectionListener)receiver;\n"
                             L"- (void)removeObserver: (EventRegistrationToken)receiverToken;\n");
                }
            }
        }

        /* Dictionary TODO:
           -(unsigned) countByEnumeratingWithState:(NSFastEnumerationState *)state objects:(id *)stackBuf count:(unsigned)maxCount;
           -(NSEnumerator*) objectEnumerator;
           -(void) enumerateKeysAndObjectsUsingBlock:(id)block;
        */

        if (ci.type == ContainerType::MapView || isMap(ci.type)) {
            if (clsState.find(L"MView") == clsState.end()) {
                clsState.insert(L"MView");
                fwprintf(outHeader,
                         L"%s\n",
                         L"- (id)objectForKey: (id)key;\n"
                         L"- (NSArray*)allKeys;\n"
                         L"- (NSArray*)allKeysForObject: (id)obj;\n"
                         L"- (NSArray*)allValues;\n"
                         L"- (id)keyEnumerator;\n"
                         L"- (unsigned int)count;\n");
            }
        }

        if (isMap(ci.type)) {
            if (clsState.find(L"Map") == clsState.end()) {
                clsState.insert(L"Map");
                fwprintf(outHeader,
                         L"-(void)setObject: (id)obj forKey: (id)key;\n"
                         L"-(void)setObject:(id)object forKeyedSubscript:(id)key;\n"
                         L"-(void)removeObjectForKey: (id)key;\n"
                         L"-(void)removeAllObjects;\n"
                         L"-(void)removeObjectsForKeys:(NSArray*)keys;\n"
                         L"-(void)addEntriesFromDictionary:(NSDictionary*)otherDict;\n"
                         L"-(void)addEntriesFromDictionaryNoReplace:(NSDictionary*)otherDict;\n"
                         L"-(void)setDictionary: (NSDictionary*)dict;\n");
                if (isObservable(ci.type)) {
                    fwprintf(outHeader,
                             L"-(EventRegistrationToken)addObserver: (RTCollectionListener)receiver;\n"
                             L"-(void)removeObserver: (EventRegistrationToken)receiverToken;\n");
                }
            }
        }
    }
    return true;
}

bool HandleInheritedContainerImpl(const shared_ptr<RuntimeClass>& cls,
                                  const shared_ptr<Generic>& interfaceCls,
                                  const SymbolTable& types,
                                  ShimTracker& shims,
                                  FILE* outImpl) {
    WinrtType iti;
    try {
        iti = winrtTypeInfo(interfaceCls, types, shims);
    } catch (const wstring& why) {
        fwprintf(outImpl,
                 L"// error: (%s) could not generate container subclass for class %s\n",
                 why.c_str(),
                 mapNamespacedType(cls->Name).c_str());
        return false;
    }

    if (!iti.isContainer())
        return true;

    fwprintf(outImpl, L" %s\n\n", iti.toObjc->implementation(iti, shims, true).c_str());
    return true;
}

bool HandleContainer(const shared_ptr<ObjectModel::Generic>& gen, WinrtType& ret, const SymbolTable& types, ShimTracker& shims) {
    const WinrtContainerInfo& info = getContainerInfo(gen->Name);
    if (info.type == ContainerType::None)
        return false;
    return HandleContainerCommon(gen, gen->Parameters, ret, info, types, shims);
}

bool HandleCArray(const std::shared_ptr<Symbol>& type, WinrtType& ret, const SymbolTable& types, ShimTracker& shims) {
    const WinrtContainerInfo* info = containerInfos[ContainerType::C_Array];
    bool res = HandleContainerCommon(type, { type }, ret, *info, types, shims);
    ret.setWrlType(ret.templateParams[0].wrlFullName() + L"*");
    return res;
}

// Handle typed event handlers:
bool HandleTypedDelegates(const std::shared_ptr<ObjectModel::Generic>& gen,
                          const wstring& typeName,
                          WinrtType& ret,
                          const SymbolTable& types,
                          ShimTracker& shims) {
    if (hasPrefix(typeName, L"Windows.Foundation.TypedEventHandler`")) {
        auto senderTypeInfo = winrtTypeInfo(gen->Parameters[0], types, shims);
        auto resultTypeInfo = winrtTypeInfo(gen->Parameters[1], types, shims);

        auto mangledSender = replace(gen->Parameters[0]->Name, L".", L"_");
        auto mangledResult = replace(gen->Parameters[1]->Name, L".", L"_");

        ret.templateParams.push_back(senderTypeInfo);
        ret.templateParams.push_back(resultTypeInfo);

        ret.setObjcType(L"void(^)(" + senderTypeInfo.getObjcType() + L", " + resultTypeInfo.getObjcType() + L")");
        ret.setWrlType(L"ABI::Windows::Foundation::ITypedEventHandler<" + senderTypeInfo.wrlFullName(false) + L", " +
                       resultTypeInfo.wrlFullName(false) + L">");
        ret.isValueType = false;

        wstring className = L"ITypedEventHandler_" + mangledSender + L"_" + mangledResult;
        ret.convertFnWrl = [className](const wstring& n, bool setter = false) {
            return L"Make<" + className + L">(" + n + L")" + (setter ? L".Detach()" : L".Get()");
        };

        // Generate the binding gunk:
        if (shims.delegateShims.find(className) == shims.delegateShims.end()) {
            shims.addref(ret);
            DelegateShimInfo i = { ret };
            shims.delegateShims[className] = i;
        }

        return true;
    } else if (hasPrefix(typeName, L"Windows.Foundation.EventHandler`")) {
        auto resultTypeInfo = winrtTypeInfo(gen->Parameters[0], types, shims);
        auto mangledResult = replace(gen->Parameters[0]->Name, L".", L"_");

        // Our first parameter is a sender, encoded as an IInspecatble:
        WinrtType inspectableType;
        if (!winrtTypeInfoBasic(L"System.Object", &inspectableType))
            assert(!"No System.Object?!");

        ret.templateParams.push_back(inspectableType);
        ret.templateParams.push_back(resultTypeInfo);

        ret.setObjcType(L"void(^)(RTObject*, " + resultTypeInfo.getObjcType() + L")");
        ret.setWrlType(L"ABI::Windows::Foundation::IEventHandler<" + resultTypeInfo.wrlFullName(false) + L">");
        ret.isValueType = false;

        wstring className = L"EventHandler_" + mangledResult;
        ret.convertFnWrl = [className](const wstring& n, bool setter = false) {
            return L"Make<" + className + L">(" + n + L")" + (setter ? L".Detach()" : L".Get()");
        };

        // Generate the binding gunk:
        if (shims.delegateShims.find(className) == shims.delegateShims.end()) {
            shims.addref(ret);
            DelegateShimInfo i = { ret };
            shims.delegateShims[className] = i;
        }

        return true;
    }
    return false;
}
