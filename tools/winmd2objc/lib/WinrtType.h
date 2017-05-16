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

enum class ContainerType {
    None,
    C_Array,
    Array,
    ArrayView,
    ObservableArray,
    Map,
    MapView,
    ObservableMap,
    Iterable,
    KeyValuePair,
    Nullable
};

inline bool isContainer(ContainerType ct) {
    return ct != ContainerType::None;
}
inline bool isCArray(ContainerType ct) {
    return ct == ContainerType::C_Array;
}
inline bool isMapView(ContainerType ct) {
    return ct == ContainerType::MapView;
}
inline bool isArrayView(ContainerType ct) {
    return ct == ContainerType::ArrayView;
}

inline bool isCollection(ContainerType ct) {
    return ((ct != ContainerType::None) && (ct != ContainerType::KeyValuePair) && (ct != ContainerType::Nullable));
}

inline bool isMutable(ContainerType ct) {
    return ((ct == ContainerType::C_Array) || (ct == ContainerType::Array) || (ct == ContainerType::ObservableArray) ||
            (ct == ContainerType::Map) || (ct == ContainerType::ObservableMap));
}

inline bool isObservable(ContainerType ct) {
    return ((ct == ContainerType::ObservableArray) || (ct == ContainerType::ObservableMap));
}

inline bool isArray(ContainerType ct) {
    return ((ct == ContainerType::Array) || (ct == ContainerType::ObservableArray));
}

inline bool isMap(ContainerType ct) {
    return ((ct == ContainerType::Map) || (ct == ContainerType::ObservableMap));
}

struct WinrtContainerInfo;
class ToObjcTypeConvertor;
class WinrtType {
    wstring objcType;

    wstring wrlName; // ABI type for this type.
    wstring templateType; // Logical type, basically different only for templated stuff.

public:
    wstring getObjcType(bool decoratedName = true) const;

    void setObjcType(const wstring& s);
    void setWrlType(const wstring& wrlName, const wstring& templateName);
    inline void setWrlType(const wstring& name) {
        setWrlType(name, name);
    }

    void setBasicType(const wstring& s); // ints and so forth.

    // These two are used for containers.  The input type is the type acceptable as an input param,
    // which may be different than the objcType.  Ie, objcType=NSMutableArray, objcInputType=id<NSFastEnumeration>.
    // And the full objc typename is the actual class that implements this particular type.
    wstring getObjcInputType(shared_ptr<Symbol> type) const; // decorated.

    wstring getFullObjcTypename(bool convert = false) const; // you should never need the default arg.

    wstring wrlFullName(bool interfaceType = true, bool baseType = false) const;

    bool isValueType = true;
    bool isFundamentalType = true;
    bool isEnumType = false;
    ContainerType container = ContainerType::None;

    bool asInputSupported = true;
    bool asOutputSupported = true;

    // Convert from WRL type -> ObjC type
    ToObjcTypeConvertor* toObjc = NULL;

    // Convert from ObjC type -> WRL type
    std::function<wstring(wstring, bool)> convertFnWrl = [](wstring p, bool setter = false) { return p; };

    wstring subtypeComment; // which subtypes are in a container.  used for documenting.

    // Template parameters for generics
    std::vector<WinrtType> templateParams;

    wstring getObjcClass() const;

    // Convenience functions.
    bool isContainer() const {
        return ::isContainer(container);
    }
    bool isCollection() const {
        return ::isCollection(container);
    } // ie, array/map of some type.
    bool isCArray() const {
        return ::isCArray(container);
    }
    bool isMutable() const {
        return ::isMutable(container);
    }
    bool isObservable() const {
        return ::isObservable(container);
    }
    bool isArray() const {
        return ::isArray(container);
    }
    bool isArrayView() const {
        return ::isArrayView(container);
    }
    bool isMap() const {
        return ::isMap(container);
    }
    bool isMapView() const {
        return ::isMapView(container);
    }
    bool isIInspectableType() const {
        return !(isValueType || isEnumType || isCArray());
    }
    wstring wrlRawName() const {
        return wrlName;
    }

    inline const WinrtContainerInfo& containerInfo() const;

    bool isInheritable() const;
    bool isSupportedInheritable() const;

    wstring aggregateWrlType() const;
};

class ShimTracker;

class ToObjcTypeConvertor {
    ToObjcTypeConvertor(const ToObjcTypeConvertor&);
    ToObjcTypeConvertor& operator=(const ToObjcTypeConvertor&);

protected:
    inline ToObjcTypeConvertor() {
    }

public:
    virtual ~ToObjcTypeConvertor();
    static ToObjcTypeConvertor* builtinFor(const wstring& conversion, bool func);

    virtual bool isBuiltin() const {
        return false;
    }

    // Call this func to get a code snipped that converts paramName to an ObjC type, a la toWrlFunc.  (default impl does nothing).
    virtual wstring call(const WinrtType& t, const wstring& paramName) {
        return paramName;
    }

    // Various bits of code that are needed for types that need shims.
    virtual wstring prototype(const WinrtType& t) {
        return L"";
    }

    virtual wstring instantiator(const WinrtType& t) {
        return t.getObjcType() + L"()";
    }

    virtual wstring instantiator(const WinrtType& t, ShimTracker& shims) {
        return t.getObjcType() + L"()";
    }

    virtual wstring supportCode(const WinrtType& t, ShimTracker& shims) {
        return L"";
    } // ie, key enumerators for maps.

    virtual wstring implementation(const WinrtType& t, ShimTracker& shims, bool inheritedType = false) {
        return L"";
    }
};

class SingleObjConvertor : public ToObjcTypeConvertor {
public:
    virtual wstring prototype(const WinrtType& t) override;
    virtual wstring call(const WinrtType& t, const wstring& param) override;
    virtual wstring instantiator(const WinrtType& t) override;
};

class SingleObjContainerConvertor : public SingleObjConvertor {
public:
    virtual wstring prototype(const WinrtType& t) override;
};

class NilConvertor : public ToObjcTypeConvertor {
public:
    virtual bool isBuiltin() const {
        return true;
    }
    virtual wstring call(const WinrtType& t, const wstring& param) override {
        return L"nil";
    }
};

extern SingleObjConvertor singleObjConv;
extern NilConvertor nilConv;
