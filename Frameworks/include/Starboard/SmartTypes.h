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

#include "Starboard/TypeTraits.h"

#if defined(__OBJC__)
#include <Foundation/Foundation.h>
#endif

#if defined(__cplusplus)

extern "C" id objc_storeStrong(id* object, id value); // Forward decl for non-objc.h users.

// Puzzlingly, this checks whether ARC is enabled instead of whether the compiler supports it.
#if !__has_feature(objc_arc)

// The lifetime traits herein expose behaviour analogous to the Objective-C ARC runtime support methods.
// They're intended to be used in concert with AutoId<>, below, to provide ownership semantics.

// Unsafe - a direct non-refcounting store of a refcountable object.
struct LifetimeUnsafe {
    inline static id store(id* destination, id value) {
        *destination = value;
        return value;
    }
};

// Retain - a retaining/releasing store of a refcountable object.
//  - Releases the refcounted value at the destination while never allowing
//    *destination to hold a non-owning reference.
struct LifetimeRetain {
    inline static id store(id* destination, id value) {
        // objc_storeStrong(&x, nil) will release the value at x.
        // This is in line with the implementation of ARC.
        return objc_storeStrong(destination, value);
    }
};

template <typename TObj, typename TLifetimeTraits = LifetimeRetain>
class AutoId {
private:
    using TObjPointer = typename TypeTraits::MakeObjcPointer<TObj>::type;

    template <typename TOther>
    using TCanConvertFrom = std::is_convertible<typename TypeTraits::MakeObjcPointer<TObj>::type, TObjPointer>;

    template <typename TOther>
    using TCanConvertTo = std::is_convertible<TObjPointer, typename TypeTraits::MakeObjcPointer<TObj>::type>;

    id _val = reinterpret_cast<id>(0);

public:
    AutoId() : _val(nil) {
    }

#ifdef nil // apparently necessary for the decltype, but not the other uses in this file...
    explicit AutoId(const decltype(nil)& val): _val(nil) {
        FAIL_FAST_IF(val != nil);
    }
#endif

    explicit AutoId(const TObjPointer& val) : _val(nil) {
        TLifetimeTraits::store(&_val, val);
    }

    explicit AutoId(const typename std::enable_if<!std::is_same<TObjPointer, id>::value, id>::type& val) : _val(nil) {
        TLifetimeTraits::store(&_val, val);
    }

    template <typename Any, typename = typename std::enable_if<TCanConvertFrom<Any>::value>::type>
    AutoId(const Any& val) : _val(nil) {
        TLifetimeTraits::store(&_val, val);
    }

    // Cross-lifetime copy initialization is okay iff the object types are convertible: the type of
    // other must be convertable to our type.
    template <typename TOtherObj, typename TOtherLifetime, typename = typename std::enable_if<TCanConvertFrom<TOtherObj>::value>::type>
    AutoId(const AutoId<TOtherObj, TOtherLifetime>& other)
        : _val(nil) {
        TLifetimeTraits::store(&_val, other._val);
    }

    AutoId(const AutoId<TObj, TLifetimeTraits>& other) : _val(nil) {
        TLifetimeTraits::store(&_val, other._val);
    }

    // We can only move from the same lifetime, and only with convertible objects.
    template <typename TOtherObj, typename TOtherLifetime, typename = typename std::enable_if<TCanConvertFrom<TOtherObj>::value>::type>
    AutoId(AutoId<TOtherObj, TOtherLifetime>&& other) {
        static_assert(std::is_same<TLifetimeTraits, TOtherLifetime>::value, "AutoId can only move from another AutoId&& with the same lifetime.");
    }

    AutoId(AutoId<TObj, TLifetimeTraits>&& other) {
        _val = other._val;
        other._val = nil;
    }

    ~AutoId() {
        TLifetimeTraits::store(&_val, nil);
    }

    // operator Any() here allows an instance of AutoId<X> to be passed as any type to which X* can convert, such as:
    // void t(NSString* x);
    // AutoId<NSMutableString> y;
    // t(y); // <-- y is convertible to NSString*, and this call succeeds.
    // and
    // NSString* x() { return AutoId<NSString*>(); }
    template <typename Any, typename = typename std::enable_if<TCanConvertTo<Any>::value>::type>
    explicit operator Any() const {
        return reinterpret_cast<Any>(_val);
    }

    // The id conversion operator is primarily used when an AutoId<> is the destination of a message.
    operator id() const {
        return _val;
    }

    explicit operator bool() const {
        return _val != nil;
    }

    // The attach function assumes ownership of an already-refcounted object.
    void attach(id val) {
        if (_val == val) {
            return;
        }

        TLifetimeTraits::store(&_val, nil);
        _val = val;
    }

    // The detach function disavows ownership of a refcounted object, returning to the caller both
    // the value and the burden of its memory management.
    TObjPointer detach() {
        TObjPointer val = _val;
        _val = nil;
        return val;
    }

    // Each of the copy and move assignment operators and constructors requires two specializations:
    // Any object type, any lifetime
    // Same object, same lifetime.
    // Without the second, MSVC and clang will generate a direct value copy for
    // AutoId<id> x, y; x = y;
    // thus breaking the refcounting on the contents of x.
    //
    // The cross-lifetime copy assignment operator and constructor allow for a retaining AutoId to take a +1
    // refcount on another weakly-held AutoId's value, or for a weak AutoId to hold a weak reference
    // to a retaining AutoId's value.
    template <typename TOtherObj, typename TOtherLifetime, typename = typename std::enable_if<TCanConvertFrom<TOtherObj>::value>::type>
    AutoId<TObj, TLifetimeTraits>& operator=(const AutoId<TOtherObj, TOtherLifetime>& other) {
        TLifetimeTraits::store(&_val, other._val);
        return *this;
    }

    AutoId<TObj, TLifetimeTraits>& operator=(const AutoId<TObj, TLifetimeTraits>& other) {
        TLifetimeTraits::store(&_val, other._val);
        return *this;
    }

    // The move constructor and assignment operator disallow moving across lifetimes for reasons similar to the
    // copy allowing them: It isn't reasonable to inherit a +0 refcount in a refcounting container, and neither is
    // the converse.
    template <typename TOtherObj, typename TOtherLifetime, typename = typename std::enable_if<TCanConvertFrom<TOtherObj>::value>::type>
    AutoId<TObj, TLifetimeTraits>& operator=(AutoId<TOtherObj, TOtherLifetime>&& other) {
        static_assert(std::is_same<TLifetimeTraits, TOtherLifetime>::value, "AutoId can only move from another AutoId&& with the same lifetime.");
        return *this;
    }

    AutoId<TObj, TLifetimeTraits>& operator=(AutoId<TObj, TLifetimeTraits>&& other) {
        _val = other._val;
        other._val = nil;
        return *this;
    }

    template <typename Any, typename = typename std::enable_if</*std::is_pointer<Any>::value && */TCanConvertFrom<Any>::value>::type>
    AutoId<TObj, TLifetimeTraits>& operator=(const Any& val) {
        id idValue = (id)val;
        if (idValue == _val) {
            return *this;
        }

        TLifetimeTraits::store(&_val, idValue);
        return *this;
    }

    template <typename Any>
    bool operator!=(const Any& other) const {
        // Use a C-style cast here because we want static_cast behaviour for convertible types and
        // reinterpret_cast behaviour for pointer/value types that can't be converted.
        return (id)other != _val;
    }

    template <typename Any>
    bool operator==(const Any& other) const {
        // As above.
        return (id)other == _val;
    }

    TObjPointer operator->() {
        return _val;
    }

    // Since blocks are reference-counted, they can be stored in AutoIds.
    // This conditionally-enabled operator() provides block calling semantics to AutoIds wrapping blocks.
    template <typename... Args>
    auto operator()(Args... args) -> decltype(std::declval<TObjPointer>()(args...)) {
        return static_cast<TObjPointer>(_val)(std::forward<Args>(args)...);
    }

    template <typename TOtherObj, typename TOtherLifetime>
    friend class AutoId;
};

// This header can be included without objc.h, so it needs to blank these keywords if ARC is off.
#ifndef __unsafe_unretained
#define __unsafe_unretained
#endif

#ifndef __strong
#define __strong
#endif
#else // else(__has_feature(objc_arc))
struct LifetimeUnsafe {};
struct LifetimeRetain {};

template <typename, typename>
struct _AutoIdArcLifetimeName {};
template <typename TObjPointer>
struct _AutoIdArcLifetimeName<TObjPointer, LifetimeUnsafe> {
    using type = __unsafe_unretained TObjPointer;
};
template <typename TObjPointer>
struct _AutoIdArcLifetimeName<TObjPointer, LifetimeRetain> {
    using type = __strong TObjPointer;
};

template <typename TObj, typename TLifetimeTraits = LifetimeRetain>
using AutoId = typename _AutoIdArcLifetimeName<typename TypeTraits::MakeObjcPointer<TObj>::type, TLifetimeTraits>::type;
#endif // objc_arc

// These are temporary compatibility aliases.
template <typename TObj>
using idretaint = AutoId<TObj, LifetimeRetain>;
template <typename TObj>
using idretainp = AutoId<TObj, LifetimeRetain>;

#if defined(__OBJC__)
using idretain = AutoId<NSObject, LifetimeRetain>;
#else
using idretain = AutoId<id, LifetimeRetain>;
#endif

template <typename TObj>
using idtype = AutoId<TObj, LifetimeUnsafe>;

// StrongId and UnsafeId are lifetime-bound id-like types.
template <typename TObj = id>
using StrongId = AutoId<TObj, LifetimeRetain>;
template <typename TObj = id>
using UnsafeId = AutoId<TObj, LifetimeUnsafe>;

template <typename Any, typename TObj, typename TLifetimeTraits, typename = typename std::enable_if<std::is_pointer<Any>::value>::type>
bool operator==(const Any& other, const AutoId<TObj, TLifetimeTraits>& val) {
    return static_cast<id>(other) == static_cast<id>(val);
}

template <typename Any, typename TObj, typename TLifetimeTraits, typename = typename std::enable_if<std::is_pointer<Any>::value>::type>
bool operator!=(const Any& other, const AutoId<TObj, TLifetimeTraits>& val) {
    return static_cast<id>(other) != static_cast<id>(val);
}

#define idretaintype(type) AutoId<type>
#define idretainproto(type) AutoId<id<type>>

#else // else(!defined(__cplusplus))

#if defined(__OBJC__)
// legacy macros used in non-C++ source and header files.
// We can't ascribe to them any particularly sound lifetime semantics,
// so we have to let the runtime decide.
typedef __strong id idretain;
#define idretainproto(type) id<type>
#else
typedef id idretain;
#define idretainproto(type) idretain
#endif

#define idretaintype(type) idretain

#endif // __cplusplus
