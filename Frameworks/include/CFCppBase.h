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
 * CppBase<NewType[, Parent]>
 * NewType: The name of the CF type deriving CppBase.
 * Parent: Optional parent CF type that also derives CppBase.
 *
 * Use:
 *
 * struct CFX: CoreFoundation::CppBase<CFX> {
 *     int a;
 * };
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
 *     return x->a;
 *     // or, with the appropriate helper function,
 *     return x->A();
 * }
 *
 * Use with Inheritance:
 *
 * struct CFSubX: CoreFoundation::CppBase<CFSubX, CFX> {
 *     // Optional Constructor
 *     // NOTE: This is a literal "Parent". CppBase provides it as a convenience.
 *     CFSubX(int test): Parent(...) { }
 * };
 *
 * // To pass arguments to the CFSubX constructor,
 * CFSubX::CreateInstance(kCFAllocatorDefault, 1024);
 */

#include <CFRuntime.h>

#include <type_traits>
#include <typeinfo>
#include <new>

namespace CoreFoundation {
template <typename T, typename TParent = __CFRuntimeBase>
struct CppBase : TParent {
protected:
    static void _CFFinalize(CFTypeRef cf) {
        T* t = reinterpret_cast<T*>(const_cast<void*>(cf));

        // Automatically calls ~CppBase() -> ~TParent()
        t->~T();
    }

    using Parent = CppBase;

    template <typename... Args>
    CppBase(Args&&... args) : TParent(std::forward<Args>(args)...) {
    }

public:
    static CFTypeID GetTypeID() {
        static __CFRuntimeClass _cls{
            0, // Version
            typeid(T).name(), // Class Name
            nullptr, // Init
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

    template <typename... Args>
    static T* CreateInstance(CFAllocatorRef allocator, Args&&... args) {
        static_assert(!std::is_polymorphic<T>::value,
                      "CoreFoundation::CppBase cannot be used with polymorphic types or classes bearing virtual functions.");
        static_assert(std::is_base_of<__CFRuntimeBase, T>::value,
                      "CoreFoundation::CppBase cannot be used with types that do not derive from __CFRuntimeBase.");
        T* ret = reinterpret_cast<T*>(
            const_cast<void*>(_CFRuntimeCreateInstance(allocator, T::GetTypeID(), sizeof(T) - sizeof(__CFRuntimeBase), nullptr)));

        // Technically, accessing any members of __CFRuntimeBase (which are set up by _CFRuntimeCreateInstance) after
        // new (ret) T() is undefined behaviour, since the constructor chain does not change them from their otherwise
        // "uninitialized" values.
        //
        // To work around that, we save the __CFRuntimeBase at the head of ret, call the constructor, and replace/reinitialize
        // it. As no constructor has been invoked on ret by the time we save temp, this is not ill-defined.
        __CFRuntimeBase temp = *reinterpret_cast<__CFRuntimeBase*>(ret);

        new (ret) T(std::forward<Args>(args)...);

        // This, however, may be ill-defined.
        *reinterpret_cast<__CFRuntimeBase*>(ret) = temp;

        return ret;
    }

    // Sad no-args version because you can't default the first param without defaulting the others,
    // and you can't default the last parameter after an argument pack as it will not substitute properly.
    static T* CreateInstance() {
        return CreateInstance(kCFAllocatorDefault);
    }
};
}
