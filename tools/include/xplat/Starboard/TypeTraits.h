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

#include <type_traits>

namespace TypeTraits {
template <typename>
struct IsBlock : std::false_type {};

#if defined(__OBJC__)
template <typename Ret, typename... Args>
struct IsBlock<Ret (^)(Args...)> : std::true_type {};

// since templated argument packs can't expand variadic "..."s, we need a separate specialization
// for variadic blocks.
template <typename Ret, typename... Args>
struct IsBlock<Ret (^)(Args..., ...)> : std::true_type {};

// MakeObjcPointer conditionally applies pointer semantics to Objective-C class types without damaging
// id or block pointers.
template <typename TObj>
class MakeObjcPointer {
    using _decayed = typename std::decay<TObj>::type;
    using _type = typename std::conditional<IsBlock<_decayed>::value, _decayed, typename std::remove_pointer<_decayed>::type*>::type;

public:
    static_assert(std::is_convertible<_type, id>::value, "MakeObjcPointer can't wrap non-Objective-C types.");
    using type = _type;
};
#endif
}
