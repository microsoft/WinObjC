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

#ifndef __cplusplus
#pragma error CFCppBase is designed for C++ consumers only.
#endif

/*
 * CoreFoundation::CppBase is a templated base class that resolves
 * the issues inherent in creating CF types with C++ members:
 * - CF does not use new/delete, so member constructors must be called manually.
 * - Inheritance is somewhat fiddly and difficult to pull off.
 *
 * Details:
 * CppBase<NewCFType, NewCFTypeImpl[, parent]>
 * NewCFType: The name of the CF type inheriting CppBase.
 * NewCFTypeImpl: The inner struct or class containing NewCFType's members.
 * parent: Optional parent CF type that also derives CppBase.
 *
 * The Impl's lifetime is managed automatically.
 * It can be accessed by reference via .Impl().
 *
 * Use:
 * struct CFXImpl {
 *     // implementation details for CFX go in here.
 *     int a;
 * };
 *
 * struct CFX: CoreFoundation::CppBase<CFX, CFXImpl> { };
 * // Do not populate CFX with any members. Helper functions are okay.
 *
 * CF_EXPORT CFXGetTypeID() {
 *     return CFX::GetTypeID();
 * }
 *
 * CF_EXPORT CFXCreate(CFAllocatorRef allocator) {
 *     return CFX::CreateInstance(allocator);
 * }
 *
 * CF_EXPORT CFXGetA(CFXRef x) {
 *     return x->Impl().a;
 *     // or, with the appropriate helper function,
 *     return x->A();
 * }
 */

#include <CFRuntime.h>

#include <type_traits>
#include <typeinfo>
#include <new>

namespace CoreFoundation {
namespace Details {
struct Nothing {};

template <typename P>
struct CppBaseImpl : P {};

template <>
struct CppBaseImpl<Details::Nothing> : __CFRuntimeBase {
    static inline void _CFInit(CFTypeRef cf) {
    }
    static inline void _CFFinalize(CFTypeRef cf) {
    }
};
}

template <typename T, typename TImpl, typename _Parent = Details::Nothing>
struct CppBase : Details::CppBaseImpl<_Parent> {
private:
    using Parent = Details::CppBaseImpl<_Parent>;

protected:
    static void _CFInit(CFTypeRef cf) {
        Parent::_CFInit(cf);

        T* t = reinterpret_cast<T*>(const_cast<void*>(cf));
        new (std::addressof(t->_impl)) TImpl();
    }

    static void _CFFinalize(CFTypeRef cf) {
        T* t = reinterpret_cast<T*>(const_cast<void*>(cf));
        t->_impl.~TImpl();

        Parent::_CFFinalize(cf);
    }

public:
    static CFTypeID GetTypeID() {
        static __CFRuntimeClass _cls{
            0, // Version
            typeid(T).name(), // Class Name
            &_CFInit, // Init
            nullptr, // Copy (ill-defined for CF)
            &_CFFinalize, // Finalize
            nullptr, // Equals
            nullptr, // Hash
            nullptr, // Copy Description
            nullptr, // Copy Debug Description
        };
        static CFTypeID _id = _CFRuntimeRegisterClass(&_cls);
        return _id;
    }

    static T* CreateInstance(CFAllocatorRef allocator = kCFAllocatorDefault) {
        return reinterpret_cast<T*>(
            const_cast<void*>(_CFRuntimeCreateInstance(allocator, GetTypeID(), sizeof(T) - sizeof(__CFRuntimeBase), nullptr)));
    }

    TImpl _impl;

    inline TImpl& Impl() {
        return _impl;
    }
};
}
