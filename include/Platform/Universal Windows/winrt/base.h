// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include <restrictederrorinfo.h>
#include <winstring.h>

#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <cstddef>
#include <iterator>
#include <map>
#include <memory>
#include <new>
#include <string>
#include <stdexcept>
#include <tuple>
#include <type_traits>
#include <utility>
#include <unordered_map>
#include <vector>

#ifdef _RESUMABLE_FUNCTIONS_SUPPORTED
#define WINRT_ASYNC
#include <ctxtcall.h>
#include <experimental/resumable>
#endif

extern "C"
{
    HRESULT __stdcall WINRT_GetRestrictedErrorInfo(IRestrictedErrorInfo ** info);
    HRESULT __stdcall WINRT_RoGetActivationFactory(HSTRING classId, const GUID & iid, void ** factory);
    HRESULT __stdcall WINRT_RoInitialize(uint32_t type);
    BOOL    __stdcall WINRT_RoOriginateError(HRESULT error, HSTRING message);
    void    __stdcall WINRT_RoUninitialize();
    HRESULT __stdcall WINRT_SetRestrictedErrorInfo(IRestrictedErrorInfo * info);
}

#ifdef _M_IX86
#pragma comment(linker, "/alternatename:_WINRT_GetRestrictedErrorInfo@4=_GetRestrictedErrorInfo@4")
#pragma comment(linker, "/alternatename:_WINRT_RoGetActivationFactory@12=_RoGetActivationFactory@12")
#pragma comment(linker, "/alternatename:_WINRT_RoInitialize@4=_RoInitialize@4")
#pragma comment(linker, "/alternatename:_WINRT_RoOriginateError@8=_RoOriginateError@8")
#pragma comment(linker, "/alternatename:_WINRT_RoUninitialize@0=_RoUninitialize@0")
#pragma comment(linker, "/alternatename:_WINRT_SetRestrictedErrorInfo@4=_SetRestrictedErrorInfo@4")
#else
#pragma comment(linker, "/alternatename:WINRT_GetRestrictedErrorInfo=GetRestrictedErrorInfo")
#pragma comment(linker, "/alternatename:WINRT_RoGetActivationFactory=RoGetActivationFactory")
#pragma comment(linker, "/alternatename:WINRT_RoInitialize=RoInitialize")
#pragma comment(linker, "/alternatename:WINRT_RoOriginateError=RoOriginateError")
#pragma comment(linker, "/alternatename:WINRT_RoUninitialize=RoUninitialize")
#pragma comment(linker, "/alternatename:WINRT_SetRestrictedErrorInfo=SetRestrictedErrorInfo")
#endif

#ifdef _DEBUG

#include <assert.h>

#define WINRT_DEBUG
#define WINRT_ASSERT assert
#define WINRT_VERIFY WINRT_ASSERT
#define WINRT_VERIFY_(result, expression) WINRT_ASSERT(result == expression)

template <typename ... Args>
void WINRT_TRACE(const char * const message, Args ... args) noexcept
{
    char buffer[1024]{};
    snprintf(buffer, sizeof(buffer), message, args ...);
    OutputDebugStringA(buffer);
}

#else

#define WINRT_ASSERT __noop
#define WINRT_VERIFY(expression) (expression)
#define WINRT_VERIFY_(result, expression) (expression)
#define WINRT_TRACE __noop

#endif

#ifndef WINRT_EXPORT
#define WINRT_EXPORT
#endif

#if defined(__clang__) || defined(__INTELLISENSE__)
#define WINRT_EBO
#else
#define WINRT_EBO __declspec(empty_bases)
#endif

#ifdef _WIN64
#define WINRT_64
#endif

#if defined(_MSC_VER) && _ITERATOR_DEBUG_LEVEL != 0
#define WINRT_CHECKED_ITERATORS
#endif

#ifndef FORMAT_MESSAGE_ALLOCATE_BUFFER
#define FORMAT_MESSAGE_ALLOCATE_BUFFER 0x00000100
#endif

#ifndef __IAgileReference_INTERFACE_DEFINED__
#define WINRT_NO_AGILE_REFERENCE
#endif

#if NTDDI_VERSION > NTDDI_WINBLUE

#define WINRT_NUMERICS
#define _WINDOWS_NUMERICS_NAMESPACE_ winrt::Windows::Foundation::Numerics
#define _WINDOWS_NUMERICS_BEGIN_NAMESPACE_ namespace winrt::Windows::Foundation::Numerics
#define _WINDOWS_NUMERICS_END_NAMESPACE_

#ifdef __clang__
#define _XM_NO_INTRINSICS_
#endif

// If this include fails it means that you're targeting an older platform version. Please use 10.0.14393.0 or later.
#include <WindowsNumerics.impl.h>

#ifdef __clang__
#undef _XM_NO_INTRINSICS_
#endif

#undef _WINDOWS_NUMERICS_NAMESPACE_
#undef _WINDOWS_NUMERICS_BEGIN_NAMESPACE_
#undef _WINDOWS_NUMERICS_END_NAMESPACE_

namespace winrt::ABI::Windows::Foundation::Numerics {

    using float2 = winrt::Windows::Foundation::Numerics::float2;
    using float3 = winrt::Windows::Foundation::Numerics::float3;
    using float4 = winrt::Windows::Foundation::Numerics::float4;
    using float3x2 = winrt::Windows::Foundation::Numerics::float3x2;
    using float4x4 = winrt::Windows::Foundation::Numerics::float4x4;
    using plane = winrt::Windows::Foundation::Numerics::plane;
    using quaternion = winrt::Windows::Foundation::Numerics::quaternion;

}

#endif

#define WINRT_SHIM(Type) (*(abi<Type> **)&static_cast<const Type &>(static_cast<const D &>(*this)))


WINRT_EXPORT namespace winrt {

namespace impl
{
    template <typename T>
    struct traits
    {
        using abi = T;
    };
}

template <typename T>
using abi = typename impl::traits<T>::abi;

namespace impl
{
    template <typename T, typename Enable = void>
    struct accessors
    {
        static abi<T> get(const T & object) noexcept
        {
            return reinterpret_cast<const abi<T> &>(object);
        }

        static abi<T> * put(T & object) noexcept
        {
            return reinterpret_cast<abi<T> *>(&object);
        }

        static void copy_from(T & object, const abi<T> & value) noexcept
        {
            object = reinterpret_cast<const T &>(value);
        }

        static void copy_to(const T & object, abi<T> & value) noexcept
        {
            reinterpret_cast<T &>(value) = object;
        }

        static abi<T> detach(T & object) noexcept
        {
            abi<T> result{};
            reinterpret_cast<T &>(result) = std::move(object);
            return result;
        }
    };

    template <typename T>
    auto put_size_abi(T & object) noexcept
    {
        return accessors<T>::put_size(object);
    }
}

template <typename T>
auto get_abi(const T & object) noexcept
{
    return impl::accessors<T>::get(object);
}

template <typename T>
auto put_abi(T & object) noexcept
{
    return impl::accessors<T>::put(object);
}

template <typename T, typename V>
void attach_abi(T & object, V && value) noexcept
{
    impl::accessors<T>::attach(object, value);
}

template <typename T, typename V>
void copy_from_abi(T & object, V && value)
{
    impl::accessors<T>::copy_from(object, value);
}

template <typename T, typename V>
void copy_to_abi(const T & object, V & value)
{
    impl::accessors<T>::copy_to(object, value);
}

template <typename T>
auto detach_abi(T & object)
{
    return impl::accessors<std::decay_t<T>>::detach(object);
}

template <typename T>
auto detach_abi(T && object)
{
    return impl::accessors<T>::detach(object);
}

namespace impl
{
    template <typename T>
    struct handle_traits
    {
        using type = T;

        constexpr static type invalid() noexcept
        {
            return nullptr;
        }

        // static void close(type value) noexcept;
    };

    template <typename T>
    struct handle
    {
        using type = typename T::type;

        handle() noexcept = default;

        handle(type value) noexcept :
        m_value(value)
        {}

        handle(handle && other) noexcept :
            m_value(detach_abi(other))
        {}

        handle & operator=(handle && other) noexcept
        {
            if (this != &other)
            {
                attach_abi(*this, detach_abi(other));
            }

            return *this;
        }

        ~handle() noexcept
        {
            close();
        }

        void close() noexcept
        {
            if (*this)
            {
                T::close(m_value);
                m_value = T::invalid();
            }
        }

        explicit operator bool() const noexcept
        {
            return T::invalid() != m_value;
        }

        friend type impl_get(const handle & handle) noexcept
        {
            return handle.m_value;
        }

        friend type * impl_put(handle & handle) noexcept
        {
            WINRT_ASSERT(!handle);
            return &handle.m_value;
        }

        friend type impl_detach(handle & handle) noexcept
        {
            type value = handle.m_value;
            handle.m_value = T::invalid();
            return value;
        }

        friend void swap(handle & left, handle & right) noexcept
        {
            std::swap(left.m_value, right.m_value);
        }

    private:

        type m_value = T::invalid();
    };

    template <typename T>
    bool operator==(const handle<T> & left, const handle<T> & right) noexcept
    {
        return get_abi(left) == get_abi(right);
    }

    template <typename T>
    bool operator!=(const handle<T> & left, const handle<T> & right) noexcept
    {
        return !(left == right);
    }

    template <typename T>
    bool operator<(const handle<T> & left, const handle<T> & right) noexcept
    {
        return get_abi(left) < get_abi(right);
    }

    template <typename T>
    bool operator>(const handle<T> & left, const handle<T> & right) noexcept
    {
        return right < left;
    }

    template <typename T>
    bool operator<=(const handle<T> & left, const handle<T> & right) noexcept
    {
        return !(right < left);
    }

    template <typename T>
    bool operator>=(const handle<T> & left, const handle<T> & right) noexcept
    {
        return !(left < right);
    }

    template <typename T>
    struct accessors<handle<T>>
    {
        using type = typename handle<T>::type;

        static type get(const handle<T> & object) noexcept
        {
            return impl_get(object);
        }

        static type * put(handle<T> & object) noexcept
        {
            return impl_put(object);
        }

        static void attach(handle<T> & object, type value) noexcept
        {
            object.close();
            *put(object) = value;
        }

        static type detach(handle<T> & object) noexcept
        {
            return impl_detach(object);
        }
    };
}

namespace impl
{
    template <typename Base, typename Derived>
    constexpr bool is_base_of_v = std::is_base_of<Base, Derived>::value;

    template<typename T, typename U>
    constexpr bool is_same_v = std::is_same<T, U>::value;

    template<typename ...>
    struct disjunction : std::false_type {};

    template<typename B>
    struct disjunction<B> : B {};

    template<typename B1, typename ... Bn>
    struct disjunction<B1, Bn ...> : std::conditional_t<B1::value, B1, disjunction<Bn ...>> {};

    template<typename ... B>
    constexpr bool disjunction_v = disjunction<B ...>::value;

    template<typename ...>
    struct conjunction : std::true_type {};

    template<typename B>
    struct conjunction<B> : B {};

    template<typename B1, typename ... Bn>
    struct conjunction<B1, Bn ...> : std::conditional_t<B1::value, conjunction<Bn ...>, B1> {};

    template<typename ... B>
    constexpr bool conjunction_v = conjunction<B ...>::value;

    template<typename T>
    constexpr bool sequence_contains(T)
    {
        return false;
    }

    template<typename T, T First, T... Rest>
    constexpr bool sequence_contains(T value)
    {
        return (value == First) || sequence_contains<T, Rest...>(value);
    }
}

namespace ABI
{
    template <typename T>
    struct traits
    {
        using default_interface = T;
    };

    template <typename T>
    using default_interface = typename traits<T>::default_interface;

    template <typename T>
    using arg_in = std::conditional_t<impl::is_base_of_v< ::IUnknown, default_interface<T>>, default_interface<T> *, T>;

    template <typename T>
    using arg_out = std::conditional_t<impl::is_base_of_v< ::IUnknown, default_interface<T>>, default_interface<T> **, T *>;
}

namespace impl
{
    template <typename D, typename I = D>
    using consume = typename traits<I>::template consume<D>;

    template <typename D, typename I>
    struct require_one : consume<D, I>
    {
        operator I() const
        {
            const auto& d = *static_cast<const D*>(this);

            if (d)
            {
                return d.template as<I>();
            }

            return nullptr;
        }
    };

    template <typename D, typename ... I>
    struct WINRT_EBO require : impl::require_one<D, I> ...
    {};

    template <typename D, typename I>
    struct bases_one
    {
        operator I() const
        {
            const auto& d = *static_cast<const D*>(this);

            if (d)
            {
                return d.template as<I>();
            }

            return nullptr;
        }
    };

    template <typename D, typename ... I>
    struct WINRT_EBO bases : impl::bases_one<D, I> ...
    {};

    template <typename T>
    class no_ref : public T
    {
        unsigned long __stdcall AddRef() noexcept;
        unsigned long __stdcall Release() noexcept;
    };

    template <typename T>
    struct not_specialized_type
    {
        static constexpr bool value = false;
    };

    template <typename T>
    struct not_specialized
    {
        static_assert(not_specialized_type<T>::value,
                      "This generic interface has not been specialized. "
                      "Each distinct instantiation of this generic interface requires a corresponding UUID. "
                      "This UUID must be provided by a template specialization.");
    };

    template <typename T>
    using abi_arg_in = ABI::arg_in<abi<T>>;

    template <typename T>
    using abi_arg_out = ABI::arg_out<abi<T>>;

    template <typename T>
    using abi_default_interface = ABI::default_interface<abi<T>>;
}

template<HRESULT ... ValuesToIgnore>
__forceinline void check_hresult(HRESULT result);

namespace Windows::Foundation
{
    struct IUnknown;
}

template <typename T>
struct com_ptr
{
    using type = abi<T>;

    com_ptr(std::nullptr_t = nullptr) noexcept {}

    com_ptr(const com_ptr & other) noexcept :
    m_ptr(other.m_ptr)
    {
        addref();
    }

    template <typename U>
    com_ptr(const com_ptr<U> & other) noexcept :
    m_ptr(other.m_ptr)
    {
        addref();
    }

    template <typename U>
    com_ptr(com_ptr<U> && other) noexcept :
    m_ptr(other.m_ptr)
    {
        other.m_ptr = nullptr;
    }

    ~com_ptr() noexcept
    {
        release();
    }

    com_ptr & operator=(const com_ptr & other) noexcept
    {
        copy(other.m_ptr);
        return *this;
    }

    template <typename U>
    com_ptr & operator=(const com_ptr<U> & other) noexcept
    {
        copy(other.m_ptr);
        return *this;
    }

    template <typename U>
    com_ptr & operator=(com_ptr<U> && other) noexcept
    {
        if (m_ptr != other.m_ptr)
        {
            release();
            m_ptr = other.m_ptr;
            other.m_ptr = nullptr;
        }

        return *this;
    }

    explicit operator bool() const noexcept
    {
        return m_ptr != nullptr;
    }

    auto operator->() const noexcept
    {
        return static_cast<impl::no_ref<type> *>(m_ptr);
    }

    T & operator *() const noexcept
    {
        return *m_ptr;
    }

    friend type * impl_get(const com_ptr & object) noexcept
    {
        return object.m_ptr;
    }

    friend type ** impl_put(com_ptr & object) noexcept
    {
        WINRT_ASSERT(object.m_ptr == nullptr);
        return &object.m_ptr;
    }

    friend type * impl_detach(com_ptr & object) noexcept
    {
        type * temp = object.m_ptr;
        object.m_ptr = nullptr;
        return temp;
    }

    friend void swap(com_ptr & left, com_ptr & right) noexcept
    {
        std::swap(left.m_ptr, right.m_ptr);
    }

    template <typename U>
    auto as() const
    {
        std::conditional_t<impl::is_base_of_v<Windows::Foundation::IUnknown, U>, U, com_ptr<U>> temp = nullptr;
        check_hresult(m_ptr->QueryInterface(__uuidof(impl::abi_default_interface<U>), reinterpret_cast<void **>(put_abi(temp))));
        return temp;
    }

    template <typename U>
    auto try_as() const
    {
        std::conditional_t<impl::is_base_of_v<Windows::Foundation::IUnknown, U>, U, com_ptr<U>> temp = nullptr;
        m_ptr->QueryInterface(__uuidof(impl::abi_default_interface<U>), reinterpret_cast<void **>(put_abi(temp)));
        return temp;
    }

    void copy_from(type * other) noexcept
    {
        copy(other);
    }

    void copy_to(type ** other) const noexcept
    {
        addref();
        *other = m_ptr;
    }

private:

    void copy(type * other) noexcept
    {
        if (m_ptr != other)
        {
            release();
            m_ptr = other;
            addref();
        }
    }

    void addref() const noexcept
    {
        if (m_ptr)
        {
            m_ptr->AddRef();
        }
    }

    void release() noexcept
    {
        type * temp = m_ptr;

        if (temp)
        {
            m_ptr = nullptr;
            temp->Release();
        }
    }

    template <typename U>
    friend struct com_ptr;

    type * m_ptr = nullptr;
};

namespace impl
{
    template <typename T>
    struct accessors<com_ptr<T>>
    {
        static auto get(const com_ptr<T> & object) noexcept
        {
            return impl_get(object);
        }

        static auto put(com_ptr<T> & object) noexcept
        {
            return impl_put(object);
        }

        static void attach(com_ptr<T> & object, abi<T> * value) noexcept
        {
            object = nullptr;
            *put(object) = value;
        }

        static auto detach(com_ptr<T> & object) noexcept
        {
            return impl_detach(object);
        }
    };
}

template <typename T>
bool operator==(const com_ptr<T> & left, const com_ptr<T> & right) noexcept
{
    return get_abi(left) == get_abi(right);
}

template <typename T>
bool operator==(const com_ptr<T> & left, std::nullptr_t) noexcept
{
    return get_abi(left) == nullptr;
}

template <typename T>
bool operator==(std::nullptr_t, const com_ptr<T> & right) noexcept
{
    return nullptr == get_abi(right);
}

template <typename T>
bool operator!=(const com_ptr<T> & left, const com_ptr<T> & right) noexcept
{
    return !(left == right);
}

template <typename T>
bool operator!=(const com_ptr<T> & left, std::nullptr_t) noexcept
{
    return !(left == nullptr);
}

template <typename T>
bool operator!=(std::nullptr_t, const com_ptr<T> & right) noexcept
{
    return !(nullptr == right);
}

template <typename T>
bool operator<(const com_ptr<T> & left, const com_ptr<T> & right) noexcept
{
    return get_abi(left) < get_abi(right);
}

template <typename T>
bool operator>(const com_ptr<T> & left, const com_ptr<T> & right) noexcept
{
    return right < left;
}

template <typename T>
bool operator<=(const com_ptr<T> & left, const com_ptr<T> & right) noexcept
{
    return !(right < left);
}

template <typename T>
bool operator>=(const com_ptr<T> & left, const com_ptr<T> & right) noexcept
{
    return !(left < right);
}

namespace impl
{
    inline HSTRING duplicate_string(HSTRING other)
    {
        HSTRING result = nullptr;
        check_hresult(WindowsDuplicateString(other, &result));
        return result;
    }

    inline HSTRING create_string(const wchar_t * value, const uint32_t length)
    {
        HSTRING result = nullptr;
        check_hresult(WindowsCreateString(value, length, &result));
        return result;
    }

    inline bool embedded_null(HSTRING value) noexcept
    {
        BOOL result = 0;
        WINRT_VERIFY_(S_OK, WindowsStringHasEmbeddedNull(value, &result));
        return 0 != result;
    }

    struct hstring_traits : handle_traits<HSTRING>
    {
        static void close(type value) noexcept
        {
            WINRT_VERIFY_(S_OK, WindowsDeleteString(value));
        }
    };
}

struct hstring_view;

struct hstring
{
    using value_type = wchar_t;
    using size_type = uint32_t;
    using const_reference = const value_type &;
    using const_pointer = const value_type *;
    using const_iterator = const_pointer;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    hstring() noexcept = default;
    hstring(const hstring & value);
    hstring & operator=(const hstring & value);
    hstring(hstring && value) noexcept;
    hstring & operator=(hstring && value) noexcept;

    hstring(const std::wstring & value);
    hstring(hstring_view value);
    hstring(const wchar_t * value);
    hstring(const wchar_t * value, size_type size);

    void clear() noexcept;
    operator std::wstring() const;

    const_reference operator[](size_type pos) const noexcept;
    const_reference front() const noexcept;
    const_reference back() const noexcept;
    const_pointer data() const noexcept;
    const_pointer c_str() const noexcept;
    const_iterator begin() const noexcept;
    const_iterator cbegin() const noexcept;
    const_iterator end() const noexcept;
    const_iterator cend() const noexcept;
    const_reverse_iterator rbegin() const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator rend() const noexcept;
    const_reverse_iterator crend() const noexcept;
    bool empty() const noexcept;
    size_type size() const noexcept;

    friend HSTRING impl_get(const hstring & string) noexcept
    {
        return get_abi(string.m_handle);
    }

    friend HSTRING * impl_put(hstring & string) noexcept
    {
        return put_abi(string.m_handle);
    }

    friend HSTRING impl_detach(hstring & string) noexcept
    {
        return detach_abi(string.m_handle);
    }

    friend void swap(hstring & left, hstring & right) noexcept
    {
        swap(left.m_handle, right.m_handle);
    }

private:

    impl::handle<impl::hstring_traits> m_handle;
};

struct hstring_view
{
    using value_type = wchar_t;
    using size_type = uint32_t;
    using const_reference = const value_type &;
    using const_pointer = const value_type *;
    using const_iterator = const_pointer;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    hstring_view(const std::wstring & value) noexcept;
    hstring_view(const hstring & value) noexcept;
    hstring_view(const wchar_t * value) noexcept;
    explicit hstring_view(HSTRING value) noexcept;

    operator std::wstring() const;

    const_reference operator[](size_type pos) const noexcept;
    const_reference front() const noexcept;
    const_reference back() const noexcept;
    const_pointer data() const noexcept;
    const_pointer c_str() const noexcept;
    const_iterator begin() const noexcept;
    const_iterator cbegin() const noexcept;
    const_iterator end() const noexcept;
    const_iterator cend() const noexcept;
    const_reverse_iterator rbegin() const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator rend() const noexcept;
    const_reverse_iterator crend() const noexcept;
    bool empty() const noexcept;
    size_type size() const noexcept;

    friend HSTRING impl_get(hstring_view string) noexcept
    {
        return string.m_handle;
    }

private:

    hstring_view(const wchar_t * value, size_type size) noexcept;

    HSTRING m_handle;
    HSTRING_HEADER m_header;
};

namespace impl
{
    template <> struct traits<hstring>
    {
        using abi = HSTRING;
    };

    template <> struct accessors<hstring>
    {
        static HSTRING get(const hstring & object) noexcept
        {
            return impl_get(object);
        }

        static HSTRING * put(hstring & object) noexcept
        {
            return impl_put(object);
        }

        static void attach(hstring & object, HSTRING value) noexcept
        {
            object.clear();
            *put(object) = value;
        }

        static void copy_from(hstring & object, HSTRING value)
        {
            attach(object, duplicate_string(value));
        }

        static void copy_to(const hstring & object, HSTRING & value)
        {
            WINRT_ASSERT(value == nullptr);
            value = duplicate_string(get(object));
        }

        static HSTRING detach(hstring & object) noexcept
        {
            return impl_detach(object);
        }
    };

    template <> struct accessors<hstring_view>
    {
        static HSTRING get(hstring_view object) noexcept
        {
            return impl_get(object);
        }

        static HSTRING detach(hstring_view object)
        {
            return duplicate_string(get(object));
        }
    };

    template <> struct accessors<const wchar_t *>
    {
        static HSTRING detach(const wchar_t * const value)
        {
            return create_string(value, static_cast<uint32_t>(wcslen(value)));
        }
    };

    template <> struct accessors<std::wstring>
    {
        static HSTRING detach(const std::wstring & value)
        {
            return create_string(value.c_str(), static_cast<uint32_t>(value.size()));
        }
    };
}

inline bool embedded_null(hstring_view value) noexcept
{
    return impl::embedded_null(get_abi(value));
}

inline bool embedded_null(const hstring & value) noexcept
{
    return impl::embedded_null(get_abi(value));
}

// TODO: this must be removed. The ABI projection should just use HSTRING directly.
namespace ABI { using hstring = HSTRING; }

inline hstring::hstring(const hstring & value) :
    m_handle(impl::duplicate_string(get_abi(value.m_handle)))
{}

inline hstring & hstring::operator=(const hstring & value)
{
    m_handle = impl::duplicate_string(get_abi(value.m_handle));
    return *this;
}

inline hstring::hstring(hstring && value) noexcept :
m_handle(std::move(value.m_handle))
{}

inline hstring & hstring::operator=(hstring && value) noexcept
{
    m_handle = std::move(value.m_handle);
    return *this;
}

inline hstring::hstring(const std::wstring & value) :
    hstring(value.c_str(), static_cast<size_type>(value.size()))
{}

inline hstring::hstring(hstring_view value) :
    m_handle(impl::duplicate_string(get_abi(value)))
{}

inline hstring::hstring(const wchar_t * const value) :
    hstring(value, static_cast<size_type>(wcslen(value)))
{}

inline hstring::hstring(const wchar_t * const value, const size_type size) :
    m_handle(impl::create_string(value, size))
{}

inline void hstring::clear() noexcept
{
    m_handle.close();
}

inline hstring::operator std::wstring() const
{
    return std::wstring(begin(), end());
}

inline hstring::const_reference hstring::operator[](const size_type pos) const noexcept
{
    WINRT_ASSERT(pos < size());
    return *(begin() + pos);
}

inline hstring::const_reference hstring::front() const noexcept
{
    WINRT_ASSERT(!empty());
    return *begin();
}

inline hstring::const_reference hstring::back() const noexcept
{
    WINRT_ASSERT(!empty());
    return *(end() - 1);
}

inline hstring::const_pointer hstring::data() const noexcept
{
    return begin();
}

inline hstring::const_pointer hstring::c_str() const noexcept
{
    return begin();
}

inline hstring::const_iterator hstring::begin() const noexcept
{
    return WindowsGetStringRawBuffer(get_abi(m_handle), nullptr);
}

inline hstring::const_iterator hstring::cbegin() const noexcept
{
    return begin();
}

inline hstring::const_iterator hstring::end() const noexcept
{
    uint32_t length = 0;
    const_pointer buffer = WindowsGetStringRawBuffer(get_abi(m_handle), &length);
    return buffer + length;
}

inline hstring::const_iterator hstring::cend() const noexcept
{
    return end();
}

inline hstring::const_reverse_iterator hstring::rbegin() const noexcept
{
    return const_reverse_iterator(end());
}

inline hstring::const_reverse_iterator hstring::crbegin() const noexcept
{
    return rbegin();
}

inline hstring::const_reverse_iterator hstring::rend() const noexcept
{
    return const_reverse_iterator(begin());
}

inline hstring::const_reverse_iterator hstring::crend() const noexcept
{
    return rend();
}

inline bool hstring::empty() const noexcept
{
    return 0 == size();
}

inline hstring::size_type hstring::size() const noexcept
{
    return WindowsGetStringLen(get_abi(m_handle));
}

inline hstring_view::hstring_view(const std::wstring & value) noexcept :
hstring_view(value.c_str(), static_cast<size_type>(value.size()))
{}

inline hstring_view::hstring_view(const hstring & value) noexcept :
    m_handle(get_abi(value))
{}

inline hstring_view::hstring_view(const wchar_t * const value) noexcept :
    hstring_view(value, static_cast<size_type>(wcslen(value)))
{}

inline hstring_view::hstring_view(const wchar_t * const value, const size_type size) noexcept
{
    WINRT_VERIFY_(S_OK, WindowsCreateStringReference(value, size, &m_header, &m_handle));
}

inline hstring_view::hstring_view(HSTRING value) noexcept :
m_handle(value)
{}

inline hstring_view::operator std::wstring() const
{
    return std::wstring(begin(), end());
}

inline hstring_view::const_reference hstring_view::operator[](const size_type pos) const noexcept
{
    WINRT_ASSERT(pos < size());
    return *(begin() + pos);
}

inline hstring_view::const_reference hstring_view::front() const noexcept
{
    WINRT_ASSERT(!empty());
    return *begin();
}

inline hstring_view::const_reference hstring_view::back() const noexcept
{
    WINRT_ASSERT(!empty());
    return *(end() - 1);
}

inline hstring_view::const_pointer hstring_view::data() const noexcept
{
    return begin();
}

inline hstring_view::const_pointer hstring_view::c_str() const noexcept
{
    return begin();
}

inline hstring_view::const_iterator hstring_view::begin() const noexcept
{
    return WindowsGetStringRawBuffer(m_handle, nullptr);
}

inline hstring_view::const_iterator hstring_view::cbegin() const noexcept
{
    return begin();
}

inline hstring_view::const_iterator hstring_view::end() const noexcept
{
    uint32_t length = 0;
    const_pointer buffer = WindowsGetStringRawBuffer(m_handle, &length);

    return buffer + length;
}

inline hstring_view::const_iterator hstring_view::cend() const noexcept
{
    return end();
}

inline hstring_view::const_reverse_iterator hstring_view::rbegin() const noexcept
{
    return const_reverse_iterator(end());
}

inline hstring_view::const_reverse_iterator hstring_view::crbegin() const noexcept
{
    return rbegin();
}

inline hstring_view::const_reverse_iterator hstring_view::rend() const noexcept
{
    return const_reverse_iterator(begin());
}

inline hstring_view::const_reverse_iterator hstring_view::crend() const noexcept
{
    return rend();
}

inline bool hstring_view::empty() const noexcept
{
    return 0 == size();
}

inline hstring_view::size_type hstring_view::size() const noexcept
{
    return WindowsGetStringLen(m_handle);
}

inline bool operator==(hstring_view left, hstring_view right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(hstring_view left, const hstring & right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(const hstring & left, hstring_view right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(const hstring & left, const hstring & right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(hstring_view left, const wchar_t * const right) noexcept
{
    return std::equal(left.begin(), left.end(), right, right + wcslen(right));
}

inline bool operator==(const wchar_t * const left, hstring_view right) noexcept
{
    return std::equal(left, left + wcslen(left), right.begin(), right.end());
}

inline bool operator==(hstring_view left, const std::wstring & right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(const std::wstring & left, hstring_view right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(const hstring & left, const wchar_t * const right) noexcept
{
    return std::equal(left.begin(), left.end(), right, right + wcslen(right));
}

inline bool operator==(const wchar_t * const left, const hstring & right) noexcept
{
    return std::equal(left, left + wcslen(left), right.begin(), right.end());
}

inline bool operator==(const hstring & left, const std::wstring & right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator==(const std::wstring & left, const hstring & right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(hstring_view left, hstring_view right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(hstring_view left, const hstring & right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(const hstring & left, hstring_view right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(const hstring & left, const hstring & right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(hstring_view left, const wchar_t * const right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right, right + wcslen(right));
}

inline bool operator<(const wchar_t * const left, hstring_view right) noexcept
{
    return std::lexicographical_compare(left, left + wcslen(left), right.begin(), right.end());
}

inline bool operator<(hstring_view left, const std::wstring & right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(const std::wstring & left, hstring_view right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(const hstring & left, const wchar_t * const right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right, right + wcslen(right));
}

inline bool operator<(const wchar_t * const left, const hstring & right) noexcept
{
    return std::lexicographical_compare(left, left + wcslen(left), right.begin(), right.end());
}

inline bool operator<(const hstring & left, const std::wstring & right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator<(const std::wstring & left, const hstring & right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

inline bool operator!=(hstring_view left, hstring_view right) noexcept { return !(left == right); }
inline bool operator >(hstring_view left, hstring_view right) noexcept { return right < left; }
inline bool operator<=(hstring_view left, hstring_view right) noexcept { return !(right < left); }
inline bool operator>=(hstring_view left, hstring_view right) noexcept { return !(left < right); }

inline bool operator!=(hstring_view left, const wchar_t * const right) noexcept { return !(left == right); }
inline bool operator >(hstring_view left, const wchar_t * const right) noexcept { return right < left; }
inline bool operator<=(hstring_view left, const wchar_t * const right) noexcept { return !(right < left); }
inline bool operator>=(hstring_view left, const wchar_t * const right) noexcept { return !(left < right); }

inline bool operator!=(const wchar_t * const left, hstring_view right) noexcept { return !(left == right); }
inline bool operator >(const wchar_t * const left, hstring_view right) noexcept { return right < left; }
inline bool operator<=(const wchar_t * const left, hstring_view right) noexcept { return !(right < left); }
inline bool operator>=(const wchar_t * const left, hstring_view right) noexcept { return !(left < right); }

inline bool operator!=(hstring_view left, const std::wstring & right) noexcept { return !(left == right); }
inline bool operator >(hstring_view left, const std::wstring & right) noexcept { return right < left; }
inline bool operator<=(hstring_view left, const std::wstring & right) noexcept { return !(right < left); }
inline bool operator>=(hstring_view left, const std::wstring & right) noexcept { return !(left < right); }

inline bool operator!=(const std::wstring & left, hstring_view right) noexcept { return !(left == right); }
inline bool operator >(const std::wstring & left, hstring_view right) noexcept { return right < left; }
inline bool operator<=(const std::wstring & left, hstring_view right) noexcept { return !(right < left); }
inline bool operator>=(const std::wstring & left, hstring_view right) noexcept { return !(left < right); }

inline bool operator!=(hstring_view left, const hstring & right) noexcept { return !(left == right); }
inline bool operator >(hstring_view left, const hstring & right) noexcept { return right < left; }
inline bool operator<=(hstring_view left, const hstring & right) noexcept { return !(right < left); }
inline bool operator>=(hstring_view left, const hstring & right) noexcept { return !(left < right); }

inline bool operator!=(const hstring & left, hstring_view right) noexcept { return !(left == right); }
inline bool operator >(const hstring & left, hstring_view right) noexcept { return right < left; }
inline bool operator<=(const hstring & left, hstring_view right) noexcept { return !(right < left); }
inline bool operator>=(const hstring & left, hstring_view right) noexcept { return !(left < right); }

inline bool operator!=(const hstring & left, const hstring & right) noexcept { return !(left == right); }
inline bool operator >(const hstring & left, const hstring & right) noexcept { return right < left; }
inline bool operator<=(const hstring & left, const hstring & right) noexcept { return !(right < left); }
inline bool operator>=(const hstring & left, const hstring & right) noexcept { return !(left < right); }

inline bool operator!=(const hstring & left, const wchar_t * const right) noexcept { return !(left == right); }
inline bool operator >(const hstring & left, const wchar_t * const right) noexcept { return right < left; }
inline bool operator<=(const hstring & left, const wchar_t * const right) noexcept { return !(right < left); }
inline bool operator>=(const hstring & left, const wchar_t * const right) noexcept { return !(left < right); }

inline bool operator!=(const wchar_t * const left, const hstring & right) noexcept { return !(left == right); }
inline bool operator >(const wchar_t * const left, const hstring & right) noexcept { return right < left; }
inline bool operator<=(const wchar_t * const left, const hstring & right) noexcept { return !(right < left); }
inline bool operator>=(const wchar_t * const left, const hstring & right) noexcept { return !(left < right); }

inline bool operator!=(const hstring & left, const std::wstring & right) noexcept { return !(left == right); }
inline bool operator >(const hstring & left, const std::wstring & right) noexcept { return right < left; }
inline bool operator<=(const hstring & left, const std::wstring & right) noexcept { return !(right < left); }
inline bool operator>=(const hstring & left, const std::wstring & right) noexcept { return !(left < right); }

inline bool operator!=(const std::wstring & left, const hstring & right) noexcept { return !(left == right); }
inline bool operator >(const std::wstring & left, const hstring & right) noexcept { return right < left; }
inline bool operator<=(const std::wstring & left, const hstring & right) noexcept { return !(right < left); }
inline bool operator>=(const std::wstring & left, const hstring & right) noexcept { return !(left < right); }

namespace impl
{
    struct heap_traits : handle_traits<wchar_t *>
    {
        static void close(type value) noexcept
        {
            WINRT_VERIFY(HeapFree(GetProcessHeap(), 0, value));
        }
    };

    struct bstr_traits : handle_traits<BSTR>
    {
        static void close(type value) noexcept
        {
            SysFreeString(value);
        }
    };

    inline hstring trim_hresult_message(const wchar_t * const message, uint32_t size) noexcept
    {
        const wchar_t * back = message + size - 1;

        while (size && isspace(*back))
        {
            --size;
            --back;
        }

        hstring result;
        WindowsCreateString(message, size, put_abi(result));
        return result;
    }
}

struct hresult_error
{
    struct from_abi_t {};
    static constexpr from_abi_t from_abi{};

    hresult_error() noexcept = default;

    explicit hresult_error(const HRESULT code) noexcept :
    m_code(code)
    {
        WINRT_RoOriginateError(code, nullptr);
        WINRT_GetRestrictedErrorInfo(put_abi(m_info));
    }

    hresult_error(const HRESULT code, hstring_view message) noexcept :
    m_code(code)
    {
        WINRT_RoOriginateError(code, get_abi(message));
        WINRT_GetRestrictedErrorInfo(put_abi(m_info));
    }

    hresult_error(const HRESULT code, from_abi_t) noexcept :
    m_code(code)
    {
        WINRT_GetRestrictedErrorInfo(put_abi(m_info));
    }

    HRESULT code() const noexcept
    {
        return m_code;
    }

    hstring message() const noexcept
    {
        if (m_info)
        {
            HRESULT code = S_OK;
            impl::handle<impl::bstr_traits> fallback;
            impl::handle<impl::bstr_traits> message;
            impl::handle<impl::bstr_traits> unused;

            if (S_OK == m_info->GetErrorDetails(put_abi(fallback), &code, put_abi(message), put_abi(unused)))
            {
                if (code == m_code)
                {
                    if (message)
                    {
                        return impl::trim_hresult_message(get_abi(message), SysStringLen(get_abi(message)));
                    }
                    else
                    {
                        return impl::trim_hresult_message(get_abi(fallback), SysStringLen(get_abi(fallback)));
                    }
                }
            }
        }

        impl::handle<impl::heap_traits> message;

        const uint32_t size = FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                                             nullptr,
                                             m_code,
                                             MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                                             reinterpret_cast<wchar_t *>(put_abi(message)),
                                             0,
                                             nullptr);

        return impl::trim_hresult_message(get_abi(message), size);
    }

    HRESULT to_abi() const noexcept
    {
        WINRT_TRACE("winrt::hresult_error (0x%8X) %ls\n", code(), message().c_str());

        if (m_info)
        {
            WINRT_SetRestrictedErrorInfo(get_abi(m_info));
        }

        return m_code;
    }

private:

    HRESULT m_code = E_FAIL;
    com_ptr<IRestrictedErrorInfo> m_info;
};

struct hresult_access_denied : hresult_error
{
    hresult_access_denied() : hresult_error(E_ACCESSDENIED) {}
    hresult_access_denied(hstring_view message) : hresult_error(E_ACCESSDENIED, message) {}
    hresult_access_denied(from_abi_t) : hresult_error(E_ACCESSDENIED, from_abi) {}
};

struct hresult_wrong_thread : hresult_error
{
    hresult_wrong_thread() : hresult_error(RPC_E_WRONG_THREAD) {}
    hresult_wrong_thread(hstring_view message) : hresult_error(RPC_E_WRONG_THREAD, message) {}
    hresult_wrong_thread(from_abi_t) : hresult_error(RPC_E_WRONG_THREAD, from_abi) {}
};

struct hresult_not_implemented : hresult_error
{
    hresult_not_implemented() : hresult_error(E_NOTIMPL) {}
    hresult_not_implemented(hstring_view message) : hresult_error(E_NOTIMPL, message) {}
    hresult_not_implemented(from_abi_t) : hresult_error(E_NOTIMPL, from_abi) {}
};

struct hresult_invalid_argument : hresult_error
{
    hresult_invalid_argument() : hresult_error(E_INVALIDARG) {}
    hresult_invalid_argument(hstring_view message) : hresult_error(E_INVALIDARG, message) {}
    hresult_invalid_argument(from_abi_t) : hresult_error(E_INVALIDARG, from_abi) {}
};

struct hresult_out_of_bounds : hresult_error
{
    hresult_out_of_bounds() : hresult_error(E_BOUNDS) {}
    hresult_out_of_bounds(hstring_view message) : hresult_error(E_BOUNDS, message) {}
    hresult_out_of_bounds(from_abi_t) : hresult_error(E_BOUNDS, from_abi) {}
};

struct hresult_no_interface : hresult_error
{
    hresult_no_interface() : hresult_error(E_NOINTERFACE) {}
    hresult_no_interface(hstring_view message) : hresult_error(E_NOINTERFACE, message) {}
    hresult_no_interface(from_abi_t) : hresult_error(E_NOINTERFACE, from_abi) {}
};

struct hresult_disconnected : hresult_error
{
    hresult_disconnected() : hresult_error(RPC_E_DISCONNECTED) {}
    hresult_disconnected(hstring_view message) : hresult_error(RPC_E_DISCONNECTED, message) {}
    hresult_disconnected(from_abi_t) : hresult_error(RPC_E_DISCONNECTED, from_abi) {}
};

struct hresult_class_not_available : hresult_error
{
    hresult_class_not_available() : hresult_error(CLASS_E_CLASSNOTAVAILABLE) {}
    hresult_class_not_available(hstring_view message) : hresult_error(CLASS_E_CLASSNOTAVAILABLE, message) {}
    hresult_class_not_available(from_abi_t) : hresult_error(CLASS_E_CLASSNOTAVAILABLE, from_abi) {}
};

struct hresult_changed_state : hresult_error
{
    hresult_changed_state() : hresult_error(E_CHANGED_STATE) {}
    hresult_changed_state(hstring_view message) : hresult_error(E_CHANGED_STATE, message) {}
    hresult_changed_state(from_abi_t) : hresult_error(E_CHANGED_STATE, from_abi) {}
};

struct hresult_illegal_method_call : hresult_error
{
    hresult_illegal_method_call() : hresult_error(E_ILLEGAL_METHOD_CALL) {}
    hresult_illegal_method_call(hstring_view message) : hresult_error(E_ILLEGAL_METHOD_CALL, message) {}
    hresult_illegal_method_call(from_abi_t) : hresult_error(E_ILLEGAL_METHOD_CALL, from_abi) {}
};

struct hresult_illegal_state_change : hresult_error
{
    hresult_illegal_state_change() : hresult_error(E_ILLEGAL_STATE_CHANGE) {}
    hresult_illegal_state_change(hstring_view message) : hresult_error(E_ILLEGAL_STATE_CHANGE, message) {}
    hresult_illegal_state_change(from_abi_t) : hresult_error(E_ILLEGAL_STATE_CHANGE, from_abi) {}
};

struct hresult_illegal_delegate_assignment : hresult_error
{
    hresult_illegal_delegate_assignment() : hresult_error(E_ILLEGAL_DELEGATE_ASSIGNMENT) {}
    hresult_illegal_delegate_assignment(hstring_view message) : hresult_error(E_ILLEGAL_DELEGATE_ASSIGNMENT, message) {}
    hresult_illegal_delegate_assignment(from_abi_t) : hresult_error(E_ILLEGAL_DELEGATE_ASSIGNMENT, from_abi) {}
};

struct hresult_canceled : hresult_error
{
    hresult_canceled() : hresult_error(HRESULT_FROM_WIN32(ERROR_CANCELLED)) {}
    hresult_canceled(hstring_view message) : hresult_error(HRESULT_FROM_WIN32(ERROR_CANCELLED), message) {}
    hresult_canceled(from_abi_t) : hresult_error(HRESULT_FROM_WIN32(ERROR_CANCELLED), from_abi) {}
};

namespace impl
{
    [[noreturn]] inline __declspec(noinline) void throw_hresult(const HRESULT result)
    {
        if (result == E_OUTOFMEMORY)
        {
            throw std::bad_alloc();
        }

        if (result == E_ACCESSDENIED)
        {
            throw hresult_access_denied(hresult_error::from_abi);
        }

        if (result == RPC_E_WRONG_THREAD)
        {
            throw hresult_wrong_thread(hresult_error::from_abi);
        }

        if (result == E_NOTIMPL)
        {
            throw hresult_not_implemented(hresult_error::from_abi);
        }

        if (result == E_INVALIDARG)
        {
            throw hresult_invalid_argument(hresult_error::from_abi);
        }

        if (result == E_BOUNDS)
        {
            throw hresult_out_of_bounds(hresult_error::from_abi);
        }

        if (result == E_NOINTERFACE)
        {
            throw hresult_no_interface(hresult_error::from_abi);
        }

        if (result == RPC_E_DISCONNECTED)
        {
            throw hresult_disconnected(hresult_error::from_abi);
        }

        if (result == CLASS_E_CLASSNOTAVAILABLE)
        {
            throw hresult_class_not_available(hresult_error::from_abi);
        }

        if (result == E_CHANGED_STATE)
        {
            throw hresult_changed_state(hresult_error::from_abi);
        }

        if (result == E_ILLEGAL_METHOD_CALL)
        {
            throw hresult_illegal_method_call(hresult_error::from_abi);
        }

        if (result == E_ILLEGAL_STATE_CHANGE)
        {
            throw hresult_illegal_state_change(hresult_error::from_abi);
        }

        if (result == E_ILLEGAL_DELEGATE_ASSIGNMENT)
        {
            throw hresult_illegal_delegate_assignment(hresult_error::from_abi);
        }

        if (result == HRESULT_FROM_WIN32(ERROR_CANCELLED))
        {
            throw hresult_canceled(hresult_error::from_abi);
        }

        throw hresult_error(result, hresult_error::from_abi);
    }

    inline __declspec(noinline) HRESULT to_hresult() noexcept
    {
        HRESULT value = S_OK;

        try
        {
            throw;
        }
        catch (const hresult_error & e)
        {
            return e.to_abi();
        }
        catch (const std::bad_alloc &)
        {
            return E_OUTOFMEMORY;
        }
        catch (const std::out_of_range &)
        {
            value = E_BOUNDS;
        }
        catch (const std::invalid_argument &)
        {
            value = E_INVALIDARG;
        }
        catch (const std::exception &)
        {
            value = E_FAIL;
        }

        WINRT_RoOriginateError(value, nullptr);
        return value;
    }

}

[[noreturn]] inline void throw_last_error()
{
    impl::throw_hresult(HRESULT_FROM_WIN32(GetLastError()));
}

template<HRESULT... ValuesToIgnore>
__forceinline void check_hresult(const HRESULT result)
{
    if (!impl::sequence_contains<HRESULT, S_OK, ValuesToIgnore...>(result))
    {
        impl::throw_hresult(result);
    }
}

namespace impl
{
    struct lock
    {
        lock(const lock &) = delete;
        lock & operator=(const lock &) = delete;
        lock() noexcept = default;

        void enter() noexcept
        {
            AcquireSRWLockExclusive(&m_lock);
        }

        bool try_enter() noexcept
        {
            return 0 != TryAcquireSRWLockExclusive(&m_lock);
        }

        void exit() noexcept
        {
            ReleaseSRWLockExclusive(&m_lock);
        }

        PSRWLOCK get() noexcept
        {
            return &m_lock;
        }

    private:

        SRWLOCK m_lock{};
    };

    struct lock_guard
    {
        explicit lock_guard(lock & lock) noexcept :
        m_lock(lock)
        {
            m_lock.enter();
        }

        ~lock_guard() noexcept
        {
            m_lock.exit();
        }

    private:

        lock & m_lock;
    };

    struct condition_variable
    {
        condition_variable(condition_variable const &) = delete;
        condition_variable const & operator=(condition_variable const &) = delete;
        condition_variable() noexcept = default;

        template <typename T>
        void wait_while(lock & x, T predicate)
        {
            while (predicate())
            {
                WINRT_VERIFY(SleepConditionVariableSRW(&m_cv, x.get(), INFINITE, 0));
            }
        }

        void wake_one() noexcept
        {
            WakeConditionVariable(&m_cv);
        }

        void wake_all() noexcept
        {
            WakeAllConditionVariable(&m_cv);
        }

    private:

        CONDITION_VARIABLE m_cv{};
    };
}

namespace impl
{
#ifdef WINRT_CHECKED_ITERATORS

    template <typename T>
    using array_iterator = stdext::checked_array_iterator<T *>;

    template <typename T>
    auto make_array_iterator(T * data, uint32_t size, uint32_t index = 0) noexcept
    {
        return array_iterator<T>(data, size, index);
    }

#else

    template <typename T>
    using array_iterator = T *;

    template <typename T>
    auto make_array_iterator(T * data, uint32_t, uint32_t index = 0) noexcept
    {
        return data + index;
    }

#endif
}

template <typename T>
struct array_view
{
    using value_type = T;
    using size_type = uint32_t;
    using reference = value_type &;
    using const_reference = const value_type &;
    using pointer = value_type *;
    using const_pointer = const value_type *;
    using iterator = impl::array_iterator<value_type>;
    using const_iterator = impl::array_iterator<const value_type>;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    array_view() noexcept = default;

    array_view(pointer first, pointer last) noexcept :
    m_data(first),
        m_size(static_cast<size_type>(last - first))
    {}

    array_view(std::initializer_list<value_type> value) noexcept :
        array_view(value.begin(), static_cast<size_type>(value.size()))
    {}

    template <typename C, size_type N>
    array_view(C(&value)[N]) noexcept :
        array_view(value, N)
    {}

    template <typename C>
    array_view(std::vector<C> & value) noexcept :
        array_view(value.data(), static_cast<size_type>(value.size()))
    {}

    template <typename C>
    array_view(const std::vector<C> & value) noexcept :
        array_view(value.data(), static_cast<size_type>(value.size()))
    {}

    template <typename C, size_type N>
    array_view(std::array<C, N> & value) noexcept :
        array_view(value.data(), static_cast<size_type>(value.size()))
    {}

    template <typename C, size_type N>
    array_view(const std::array<C, N> & value) noexcept :
        array_view(value.data(), static_cast<size_type>(value.size()))
    {}

    reference operator[](const size_type pos) noexcept
    {
        WINRT_ASSERT(pos < size());
        return m_data[pos];
    }

    const_reference operator[](const size_type pos) const noexcept
    {
        WINRT_ASSERT(pos < size());
        return m_data[pos];
    }

    reference at(const size_type pos)
    {
        if (size() <= pos)
        {
            throw std::out_of_range("Invalid array subscript");
        }

        return m_data[pos];
    }

    const_reference at(const size_type pos) const
    {
        if (size() <= pos)
        {
            throw std::out_of_range("Invalid array subscript");
        }

        return m_data[pos];
    }

    reference front() noexcept
    {
        WINRT_ASSERT(m_size > 0);
        return *m_data;
    }

    const_reference front() const noexcept
    {
        WINRT_ASSERT(m_size > 0);
        return *m_data;
    }

    reference back() noexcept
    {
        WINRT_ASSERT(m_size > 0);
        return m_data[m_size - 1];
    }

    const_reference back() const noexcept
    {
        WINRT_ASSERT(m_size > 0);
        return m_data[m_size - 1];
    }

    pointer data() noexcept
    {
        return m_data;
    }

    const_pointer data() const noexcept
    {
        return m_data;
    }

    iterator begin() noexcept
    {
        return impl::make_array_iterator(m_data, m_size);
    }

    const_iterator begin() const noexcept
    {
        return impl::make_array_iterator<const value_type>(m_data, m_size);
    }

    const_iterator cbegin() const noexcept
    {
        return impl::make_array_iterator<const value_type>(m_data, m_size);
    }

    iterator end() noexcept
    {
        return impl::make_array_iterator(m_data, m_size, m_size);
    }

    const_iterator end() const noexcept
    {
        return impl::make_array_iterator<const value_type>(m_data, m_size, m_size);
    }

    const_iterator cend() const noexcept
    {
        return impl::make_array_iterator<const value_type>(m_data, m_size, m_size);
    }

    reverse_iterator rbegin() noexcept
    {
        return reverse_iterator(end());
    }

    const_reverse_iterator rbegin() const noexcept
    {
        return const_reverse_iterator(end());
    }

    const_reverse_iterator crbegin() const noexcept
    {
        return rbegin();
    }

    reverse_iterator rend() noexcept
    {
        return reverse_iterator(begin());
    }

    const_reverse_iterator rend() const noexcept
    {
        return const_reverse_iterator(begin());
    }

    const_reverse_iterator crend() const noexcept
    {
        return rend();
    }

    bool empty() const noexcept
    {
        return m_size == 0;
    }

    size_type size() const noexcept
    {
        return m_size;
    }

protected:

    array_view(pointer data, uint32_t size) :
        m_data(data),
        m_size(size)
    {}

    pointer m_data = nullptr;
    uint32_t m_size = 0;
};

template <typename T>
struct com_array : array_view<T>
{
    using typename array_view<T>::value_type;
    using typename array_view<T>::size_type;
    using typename array_view<T>::reference;
    using typename array_view<T>::const_reference;
    using typename array_view<T>::pointer;
    using typename array_view<T>::const_pointer;
    using typename array_view<T>::iterator;
    using typename array_view<T>::const_iterator;
    using typename array_view<T>::reverse_iterator;
    using typename array_view<T>::const_reverse_iterator;

    com_array(const com_array &) = delete;
    com_array & operator=(const com_array &) = delete;

    com_array() noexcept = default;

    explicit com_array(const size_type count) :
        com_array(count, value_type())
    {}

    com_array(const size_type count, const value_type & value)
    {
        alloc(count);
        std::uninitialized_fill_n(this->m_data, count, value);
    }

    template <typename InIt> com_array(InIt first, InIt last)
    {
        alloc(static_cast<size_type>(std::distance(first, last)));
        std::uninitialized_copy(first, last, this->begin());
    }

    explicit com_array(const std::vector<value_type> & value) :
        com_array(value.begin(), value.end())
    {}

    template <size_type N>
    explicit com_array(const std::array<value_type, N> & value) :
        com_array(value.begin(), value.end())
    {}

    template <size_type N>
    explicit com_array(const value_type(&value)[N]) :
        com_array(value, value + N)
    {}

    com_array(std::initializer_list<value_type> value) :
        com_array(value.begin(), value.end())
    {}

    com_array(com_array && other) noexcept :
        array_view<T>(other.m_data, other.m_size)
    {
        other.m_data = nullptr;
        other.m_size = 0;
    }

    com_array & operator=(com_array && other) noexcept
    {
        this->m_data = other.m_data;
        this->m_size = other.m_size;
        other.m_data = nullptr;
        other.m_size = 0;
        return *this;
    }

    ~com_array() noexcept
    {
        clear();
    }

    void clear() noexcept
    {
        if (this->m_data)
        {
            destruct(std::is_trivially_destructible<value_type>());
            CoTaskMemFree(this->m_data);
            this->m_data = nullptr;
            this->m_size = 0;
        }
    }

    friend impl::abi_arg_out<T> * impl_put(com_array & value) noexcept
    {
        WINRT_ASSERT(!value.m_data);
        return reinterpret_cast<impl::abi_arg_out<T> *>(&value.m_data);
    }

    friend auto impl_data(com_array & value) noexcept
    {
        return value.m_data;
    }

    friend void impl_put_size(com_array & value, const uint32_t size) noexcept
    {
        WINRT_ASSERT(value.m_data || (!value.m_data && size == 0));
        value.m_size = size;
    }

    friend auto impl_detach(com_array & value) noexcept
    {
        std::pair<uint32_t, impl::abi_arg_in<T> *> result(value.size(), *reinterpret_cast<impl::abi_arg_in<T> **>(&value));
        value.m_data = nullptr;
        value.m_size = 0;
        return result;
    }

    friend void swap(com_array & left, com_array & right) noexcept
    {
        std::swap(left.m_data, right.m_data);
        std::swap(left.m_size, right.m_size);
    }

private:

    void alloc(const size_type size)
    {
        WINRT_ASSERT(this->empty());

        if (0 != size)
        {
            this->m_data = static_cast<value_type *>(CoTaskMemAlloc(size * sizeof(value_type)));

            if (this->m_data == nullptr)
            {
                throw std::bad_alloc();
            }

            this->m_size = size;
        }
    }

    void destruct(std::true_type) noexcept
    {}

    void destruct(std::false_type) noexcept
    {
        for (value_type & v : *this)
        {
            v.~value_type();
        }
    }
};

template <typename T>
bool operator==(const array_view<T> & left, const array_view<T> & right) noexcept
{
    return std::equal(left.begin(), left.end(), right.begin(), right.end());
}

template <typename T>
bool operator<(const array_view<T> & left, const array_view<T> & right) noexcept
{
    return std::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}

template <typename T> bool operator!=(const array_view<T> & left, const array_view<T> & right) noexcept { return !(left == right); }
template <typename T> bool operator>(const array_view<T> & left, const array_view<T> & right) noexcept { return right < left; }
template <typename T> bool operator<=(const array_view<T> & left, const array_view<T> & right) noexcept { return !(right < left); }
template <typename T> bool operator>=(const array_view<T> & left, const array_view<T> & right) noexcept { return !(left < right); }

namespace impl
{
    template <typename T>
    struct array_size_proxy
    {
        array_size_proxy & operator=(const array_size_proxy &) = delete;

        array_size_proxy(com_array<T> & value) noexcept :
        m_value(value)
        {}

        ~array_size_proxy() noexcept
        {
            impl_put_size(m_value, m_size);
        }

        operator uint32_t * () noexcept
        {
            return &m_size;
        }

        operator unsigned long * () noexcept
        {
            return reinterpret_cast<unsigned long *>(&m_size);
        }

    private:

        com_array<T> & m_value;
        uint32_t m_size = 0;
    };

    template <typename T>
    struct com_array_proxy
    {
        com_array_proxy(uint32_t * size, abi_arg_out<T> * value) noexcept :
        m_size(size),
            m_value(value)
        {}

        ~com_array_proxy() noexcept
        {
            std::tie(*m_size, *m_value) = impl_detach(m_temp);
        }

        operator com_array<T> &() noexcept
        {
            return m_temp;
        }

        com_array_proxy(const com_array_proxy &) noexcept
        {
            WINRT_ASSERT(false);
        }

        com_array_proxy & operator=(const com_array_proxy &) noexcept
        {
            WINRT_ASSERT(false);
            return *this;
        }

    private:

        uint32_t * m_size;
        abi_arg_out<T> * m_value;
        com_array<T> m_temp;
    };

    template <typename T>
    struct accessors<com_array<T>>
    {
        static auto put(com_array<T> & object) noexcept
        {
            return impl_put(object);
        }

        static array_size_proxy<T> put_size(com_array<T> & object) noexcept
        {
            return array_size_proxy<T>(object);
        }

        static auto detach(com_array<T> & object) noexcept
        {
            return impl_detach(object);
        }

        static auto data(com_array<T> & object) noexcept
        {
            return impl_data(object);
        }
    };

    template <typename T>
    struct accessors<array_view<T>>
    {
        static auto get(array_view<T> object) noexcept
        {
            return reinterpret_cast<abi_arg_out<std::remove_const_t<T>>>(const_cast<std::remove_const_t<T> *>(object.data()));
        }
    };
}

template <typename T>
auto detach_abi(uint32_t * __valueSize, impl::abi_arg_out<T> * value) noexcept
{
    return impl::com_array_proxy<T>(__valueSize, value);
}

namespace Windows::Foundation
{
    enum class TrustLevel
    {
        BaseTrust,
        PartialTrust,
        FullTrust,
    };
}

namespace ABI::Windows::Foundation
{
    struct __declspec(uuid("af86e2e0-b12d-4c6a-9c5a-d7aa65101e90")) __declspec(novtable) IInspectable : IUnknown
    {
        virtual HRESULT __stdcall abi_GetIids(uint32_t * iidCount, GUID ** iids) = 0;
        virtual HRESULT __stdcall abi_GetRuntimeClassName(HSTRING * className) = 0;
        virtual HRESULT __stdcall abi_GetTrustLevel(winrt::Windows::Foundation::TrustLevel * trustLevel) = 0;
    };

    struct __declspec(uuid("00000035-0000-0000-c000-000000000046")) __declspec(novtable) IActivationFactory : IInspectable
    {
        virtual HRESULT __stdcall abi_ActivateInstance(IInspectable ** instance) = 0;
    };
}

namespace Windows::Foundation
{
    struct IUnknown
    {
        IUnknown() noexcept = default;
        IUnknown(std::nullptr_t) noexcept {}
        void * operator new(size_t) = delete;

        IUnknown(const IUnknown & other) noexcept :
        m_ptr(other.m_ptr)
        {
            impl_addref();
        }

        IUnknown(IUnknown && other) noexcept :
        m_ptr(other.m_ptr)
        {
            other.m_ptr = nullptr;
        }

        ~IUnknown() noexcept
        {
            impl_release();
        }

        IUnknown & operator=(const IUnknown & other) noexcept
        {
            impl_copy(other);
            return *this;
        }

        IUnknown & operator=(IUnknown && other) noexcept
        {
            impl_move(std::forward<IUnknown>(other));
            return *this;
        }

        explicit operator bool() const noexcept
        {
            return nullptr != m_ptr;
        }

        IUnknown & operator=(std::nullptr_t) noexcept
        {
            impl_release();
            return *this;
        }

        template <typename U>
        auto as() const
        {
            std::conditional_t<impl::is_base_of_v<IUnknown, U>, U, com_ptr<U>> temp = nullptr;
            check_hresult(m_ptr->QueryInterface(__uuidof(impl::abi_default_interface<U>), reinterpret_cast<void **>(put_abi(temp))));
            return temp;
        }

        template <typename U>
        auto try_as() const
        {
            std::conditional_t<impl::is_base_of_v<IUnknown, U>, U, com_ptr<U>> temp = nullptr;
            m_ptr->QueryInterface(__uuidof(impl::abi_default_interface<U>), reinterpret_cast<void **>(put_abi(temp)));
            return temp;
        }

        friend auto impl_get(const IUnknown & object) noexcept
        {
            return object.m_ptr;
        }

        friend auto impl_put(IUnknown & object) noexcept
        {
            WINRT_ASSERT(!object);
            return &object.m_ptr;
        }

        friend auto impl_detach(IUnknown & object) noexcept
        {
            auto temp = object.m_ptr;
            object.m_ptr = nullptr;
            return temp;
        }

        friend void swap(IUnknown & left, IUnknown & right) noexcept
        {
            std::swap(left.m_ptr, right.m_ptr);
        }

    protected:

        void impl_copy(::IUnknown * other) noexcept
        {
            if (m_ptr != other)
            {
                impl_release();
                m_ptr = other;
                impl_addref();
            }
        }

        void impl_copy(const IUnknown & other) noexcept
        {
            if (this != &other)
            {
                impl_release();
                m_ptr = other.m_ptr;
                impl_addref();
            }
        }

        void impl_move(IUnknown && other) noexcept
        {
            if (this != &other)
            {
                impl_release();
                m_ptr = other.m_ptr;
                other.m_ptr = nullptr;
            }
        }

        ::IUnknown * m_ptr = nullptr;

    private:

        void impl_addref() const noexcept
        {
            if (m_ptr)
            {
                m_ptr->AddRef();
            }
        }

        void impl_release() noexcept
        {
            auto temp = m_ptr;

            if (temp)
            {
                m_ptr = nullptr;
                temp->Release();
            }
        }
    };
}

namespace impl
{
    template <> struct traits<Windows::Foundation::IUnknown>
    {
        using abi = ::IUnknown;
    };

    template <typename T>
    struct accessors<T, std::enable_if_t<std::is_base_of<Windows::Foundation::IUnknown, T>::value>>
    {
        static auto get(const T & object) noexcept
        {
            return static_cast<abi_arg_in<T>>(impl_get(object));
        }

        static auto put(T & object) noexcept
        {
            return reinterpret_cast<abi_arg_out<T>>(impl_put(object));
        }

        static void attach(T & object, abi_arg_in<T> value) noexcept
        {
            object = nullptr;
            *put(object) = value;
        }

        static void copy_from(T & object, abi_arg_in<T> value) noexcept
        {
            object = nullptr;

            if (value)
            {
                value->AddRef();
                *put(object) = value;
            }
        }

        template <typename V>
        static void copy_to(const T & object, V & value) noexcept
        {
            if (object)
            {
                value = get(object);
                value->AddRef();
            }
            else
            {
                value = nullptr;
            }
        }

        static auto detach(T & object) noexcept
        {
            return static_cast<abi_arg_in<T>>(impl_detach(object));
        }
    };
}

namespace Windows::Foundation
{
    inline bool operator==(const IUnknown & left, const IUnknown & right) noexcept
    {
        return get_abi(left) == get_abi(right);
    }

    inline bool operator!=(const IUnknown & left, const IUnknown & right) noexcept
    {
        return !(left == right);
    }

    inline bool operator<(const IUnknown & left, const IUnknown & right) noexcept
    {
        return get_abi(left) < get_abi(right);
    }

    inline bool operator>(const IUnknown & left, const IUnknown & right) noexcept
    {
        return right < left;
    }

    inline bool operator<=(const IUnknown & left, const IUnknown & right) noexcept
    {
        return !(right < left);
    }

    inline bool operator>=(const IUnknown & left, const IUnknown & right) noexcept
    {
        return !(left < right);
    }
}

namespace Windows::Foundation
{
    struct IInspectable;
}

namespace impl
{
    template <> struct traits<Windows::Foundation::IInspectable>
    {
        using abi = ABI::Windows::Foundation::IInspectable;
    };
}

namespace Windows::Foundation
{
    struct IInspectable : IUnknown
    {
        IInspectable(std::nullptr_t = nullptr) noexcept {}
    };

    inline com_array<GUID> GetIids(const IInspectable & object)
    {
        com_array<GUID> value;
        check_hresult((*(abi<IInspectable> **)&object)->abi_GetIids(impl::put_size_abi(value), put_abi(value)));
        return value;
    }

    inline hstring GetRuntimeClassName(const IInspectable & object)
    {
        hstring value;
        check_hresult((*(abi<IInspectable> **)&object)->abi_GetRuntimeClassName(put_abi(value)));
        return value;
    }

    inline TrustLevel GetTrustLevel(const IInspectable & object)
    {
        TrustLevel value{};
        check_hresult((*(abi<IInspectable> **)&object)->abi_GetTrustLevel(&value));
        return value;
    }
}

namespace impl
{
    template <typename T, std::enable_if_t<!std::is_base_of<Windows::Foundation::IUnknown, T>::value> * = nullptr>
    T empty_value()
    {
        return {};
    }

    template <typename T, std::enable_if_t<std::is_base_of<Windows::Foundation::IUnknown, T>::value> * = nullptr>
    T empty_value()
    {
        return nullptr;
    }
}

namespace ABI::Windows::Foundation
{
    struct __declspec(uuid("00000037-0000-0000-C000-000000000046")) __declspec(novtable) IWeakReference : ::IUnknown
    {
        virtual HRESULT __stdcall abi_Resolve(const GUID & iid, IInspectable ** objectReference) = 0;

        template <typename Qi> HRESULT __stdcall abi_Resolve(Qi ** objectReference) noexcept
        {
            return abi_Resolve(__uuidof(Qi), reinterpret_cast<IInspectable **>(objectReference));
        }
    };

    struct __declspec(uuid("00000038-0000-0000-C000-000000000046")) __declspec(novtable) IWeakReferenceSource : ::IUnknown
    {
        virtual HRESULT __stdcall abi_GetWeakReference(IWeakReference ** weakReference) = 0;
    };
}

template <typename T>
struct weak_ref
{
    weak_ref(std::nullptr_t = nullptr) noexcept {}

    weak_ref(const T & object)
    {
        check_hresult(object.template as<ABI::Windows::Foundation::IWeakReferenceSource>()->abi_GetWeakReference(put_abi(m_ref)));
    }

    T get() const noexcept
    {
        T object = nullptr;
        m_ref->abi_Resolve(put_abi(object));
        return object;
    }

    explicit operator bool() const noexcept
    {
        return static_cast<bool>(m_ref);
    }

private:

    com_ptr<ABI::Windows::Foundation::IWeakReference> m_ref;
};

template <typename T>
weak_ref<T> make_weak(T const & object)
{
    return object;
}

#ifndef WINRT_NO_AGILE_REFERENCE

template <typename T>
struct agile_ref
{
    agile_ref(std::nullptr_t = nullptr) noexcept {}

    agile_ref(const T & object)
    {
#ifdef WINRT_DEBUG
        if (object.template try_as<IAgileObject>())
        {
            WINRT_TRACE("winrt::agile_ref - wrapping an agile object is unnecessary.\n");
        }
#endif

        check_hresult(RoGetAgileReference(AGILEREFERENCE_DEFAULT,
                                          __uuidof(impl::abi_default_interface<T>),
                                          winrt::get_abi(object),
                                          put_abi(m_ref)));
    }

    T get() const
    {
        T result = nullptr;
        check_hresult(m_ref->Resolve(put_abi(result)));
        return result;
    }

    explicit operator bool() const noexcept
    {
        return static_cast<bool>(m_ref);
    }

private:

    com_ptr<IAgileReference> m_ref;
};

template <typename T>
agile_ref<T> make_agile(const T & object)
{
    return object;
}

#endif

struct event_token
{
    int64_t value{};
};

inline bool operator==(const event_token & left, const event_token & right) noexcept
{
    return left.value == right.value;
}

struct auto_revoke_t {};
constexpr auto_revoke_t auto_revoke{};

template <typename I>
struct event_revoker
{
    using method_type = HRESULT(__stdcall abi<I>::*)(event_token);

    event_revoker() noexcept = default;
    event_revoker(const event_revoker &) = delete;
    event_revoker & operator=(const event_revoker &) = delete;
    event_revoker(event_revoker &&) = default;
    event_revoker & operator=(event_revoker &&) = default;

    event_revoker(const I & object, method_type method, event_token token) :
        m_object(object),
        m_method(method),
        m_token(token)
    {}

    ~event_revoker() noexcept
    {
        revoke();
    }

    void revoke() noexcept
    {
        if (!m_object)
        {
            return;
        }

        if (I object = m_object.get())
        {
            ((*get_abi(object)).*(m_method))(m_token);
        }

        m_object = nullptr;
    }

private:

    weak_ref<I> m_object;
    method_type m_method{};
    event_token m_token{};
};

template <typename I>
struct factory_event_revoker
{
    using method_type = HRESULT(__stdcall abi<I>::*)(event_token);

    factory_event_revoker() noexcept = default;
    factory_event_revoker(const factory_event_revoker &) = delete;
    factory_event_revoker & operator=(const factory_event_revoker &) = delete;
    factory_event_revoker(factory_event_revoker &&) = default;
    factory_event_revoker & operator=(factory_event_revoker &&) = default;

    factory_event_revoker(const I & object, method_type method, event_token token) :
        m_object(object),
        m_method(method),
        m_token(token)
    {}

    ~factory_event_revoker() noexcept
    {
        revoke();
    }

    void revoke() noexcept
    {
        if (!m_object)
        {
            return;
        }

        ((*get_abi(m_object)).*(m_method))(m_token);
        m_object = nullptr;
    }

private:

    I m_object;
    method_type m_method{};
    event_token m_token{};
};

namespace impl
{
    template <typename D, typename I, typename S, typename M>
    auto make_event_revoker(S source, M method, event_token token)
    {
        return event_revoker<I>(static_cast<const I &>(static_cast<const D &>(*source)), method, token);
    }
}

namespace impl
{
    template <typename T>
    struct event_array
    {
        using value_type = T;
        using reference = value_type &;
        using pointer = value_type *;
        using iterator = impl::array_iterator<value_type>;

        explicit event_array(const uint32_t count) noexcept : m_size(count)
        {
            std::uninitialized_fill_n(data(), count, value_type());
        }

        unsigned long AddRef() noexcept
        {
            return 1 + m_references.fetch_add(1, std::memory_order_relaxed);
        }

        unsigned long Release() noexcept
        {
            const uint32_t remaining = m_references.fetch_sub(1, std::memory_order_release) - 1;

            if (remaining == 0)
            {
                std::atomic_thread_fence(std::memory_order_acquire);
                this->~event_array();
                ::operator delete(static_cast<void*>(this));
            }

            return remaining;
        }

        reference back() noexcept
        {
            WINRT_ASSERT(m_size > 0);
            return *(data() + m_size - 1);
        }

        iterator begin() noexcept
        {
            return impl::make_array_iterator(data(), m_size);
        }

        iterator end() noexcept
        {
            return impl::make_array_iterator(data(), m_size, m_size);
        }

        uint32_t size() const noexcept
        {
            return m_size;
        }

        ~event_array() noexcept
        {
            for (reference element : *this)
            {
                element.~T();
            }
        }

    private:

        pointer data() noexcept
        {
            return reinterpret_cast<pointer>(this + 1);
        }

        std::atomic<uint32_t> m_references{ 1 };
        uint32_t m_size{ 0 };
    };

    template <typename T>
    auto make_event_array(const uint32_t capacity)
    {
        com_ptr<event_array<T>> instance;
        void* raw = ::operator new(sizeof(event_array<T>) + (sizeof(T) * capacity));
        *put_abi(instance) = new(raw) event_array<T>(capacity);
        return instance;
    }

    template <typename Traits>
    struct event : Traits
    {
        using delegate_type = typename Traits::delegate_type;

        event() = default;
        event(const event<Traits> &) = delete;
        event<Traits> & operator =(const event<Traits> &) = delete;

        explicit operator bool() const noexcept
        {
            return m_targets != nullptr;
        }

        event_token add(const delegate_type & delegate)
        {
            if (delegate == nullptr)
            {
                throw hresult_invalid_argument();
            }

            event_token token{};
            delegate_array temp_targets;

            {
                auto change_guard = this->get_change_guard();
                delegate_array new_targets = impl::make_event_array<storage_type>((!m_targets) ? 1 : m_targets->size() + 1);

                if (m_targets)
                {
                    std::copy_n(m_targets->begin(), m_targets->size(), new_targets->begin());
                }

                token.value = reinterpret_cast<int64_t>(get_abi(delegate));
                new_targets->back() = delegate;

                auto swap_guard = this->get_swap_guard();
                temp_targets = m_targets;
                m_targets = new_targets;
            }

            return token;
        }

        void remove(const event_token token)
        {
            delegate_array temp_targets;

            {
                auto change_guard = this->get_change_guard();

                if (!m_targets)
                {
                    return;
                }

                uint32_t available_slots = m_targets->size() - 1;
                delegate_array new_targets;
                bool removed = false;

                if (available_slots == 0)
                {
                    if (this->get_token(*m_targets->begin()) == token)
                    {
                        removed = true;
                    }
                }
                else
                {
                    new_targets = impl::make_event_array<storage_type>(available_slots);
                    auto new_iterator = new_targets->begin();

                    for (const storage_type & element : *m_targets)
                    {
                        if (!removed && token == this->get_token(element))
                        {
                            removed = true;
                            continue;
                        }

                        *new_iterator = element;
                        ++new_iterator;
                    }
                }

                if (removed)
                {
                    auto swap_guard = this->get_swap_guard();
                    temp_targets = m_targets;
                    m_targets = new_targets;
                }
            }
        }

        template<typename ...Arg>
        void operator()(const Arg & ... args)
        {
            delegate_array temp_targets;

            {
                auto swap_guard = this->get_swap_guard();
                temp_targets = m_targets;
            }

            if (temp_targets)
            {
                for (const storage_type & element : *temp_targets)
                {
                    bool remove_delegate = false;

                    try
                    {
                        this->invoke(element, args...);
                    }
                    catch (const hresult_error& e)
                    {
                        if (e.code() == JSCRIPT_E_CANTEXECUTE ||
                            e.code() == RPC_S_SERVER_UNAVAILABLE ||
                            e.code() == RPC_E_DISCONNECTED)
                        {
                            remove_delegate = true;
                        }
                    }

                    if (remove_delegate)
                    {
                        remove(this->get_token(element));
                    }
                }
            }
        }

    private:

        using storage_type = typename Traits::storage_type;
        using delegate_array = com_ptr<impl::event_array<storage_type>>;

        delegate_array m_targets;
    };

    struct no_lock_guard {};

    struct locked_event_traits
    {
        lock_guard get_swap_guard() noexcept
        {
            return lock_guard(m_swap);
        }

        lock_guard get_change_guard() noexcept
        {
            return lock_guard(m_change);
        }

    private:

        lock m_swap;
        lock m_change;
    };

    template <typename Delegate>
    struct single_threaded_event_traits
    {
        using delegate_type = Delegate;
        using storage_type = Delegate;

        template <typename ... Args>
        void invoke(const storage_type & delegate, const Args & ... args) const
        {
            delegate(args ...);
        }

        event_token get_token(const storage_type & delegate) const noexcept
        {
            return{ reinterpret_cast<int64_t>(get(delegate)) };
        }

        no_lock_guard get_swap_guard() const noexcept
        {
            return{};
        }

        no_lock_guard get_change_guard() const noexcept
        {
            return{};
        }
    };

#ifndef WINRT_NO_AGILE_REFERENCE

    template <typename Delegate>
    struct agile_event_traits : locked_event_traits
    {
        using delegate_type = Delegate;
        using storage_type = agile_ref<Delegate>;

        template <typename ... Args>
        void invoke(const storage_type & delegate, const Args & ... args) const
        {
            delegate.get()(args ...);
        }

        event_token get_token(const storage_type & delegate) const noexcept
        {
            return{ reinterpret_cast<int64_t>(get_abi(delegate.get())) };
        }
    };

#endif

    template <typename Delegate>
    struct non_agile_event_traits : locked_event_traits
    {
        using delegate_type = Delegate;
        using storage_type = Delegate;

        template <typename ... Args>
        void invoke(const storage_type & delegate, const Args & ... args) const
        {
            delegate(args ...);
        }

        event_token get_token(const storage_type & delegate) const noexcept
        {
            return{ reinterpret_cast<int64_t>(get_abi(delegate)) };
        }
    };
}

#ifndef WINRT_NO_AGILE_REFERENCE

template <typename Delegate>
using agile_event = impl::event<impl::agile_event_traits<Delegate>>;

#endif

template <typename Delegate>
using non_agile_event = impl::event<impl::non_agile_event_traits<Delegate>>;

template <typename Delegate>
using single_threaded_event = impl::event<impl::single_threaded_event_traits<Delegate>>;

namespace impl
{
    struct marker {};
}

struct non_agile : impl::marker {};
struct no_weak_ref : impl::marker {};

template <typename Interface>
struct cloaked : Interface {};

namespace impl
{
    template <typename T>
    struct uncloak
    {
        using type = T;
    };

    template <typename T>
    struct uncloak<cloaked<T>>
    {
        using type = T;
    };

    template <typename T>
    using uncloak_t = typename uncloak<T>::type;

    template <typename I>
    struct is_cloaked : std::negation<std::is_base_of<ABI::Windows::Foundation::IInspectable, abi<I>>> {};

    template <typename I>
    struct is_cloaked<cloaked<I>> : std::true_type {};

    template <typename I>
    constexpr bool is_cloaked_v = is_cloaked<I>::value;

    template <typename ... I>
    struct first_interface
    {
        using type = void;
    };

    template <typename First, typename ... Rest>
    struct first_interface<First, Rest ...>
    {
        using type = std::conditional_t<impl::is_base_of_v<impl::marker, First>, typename first_interface<Rest ...>::type, First>;
    };

    template <typename D, typename I>
    struct produce;

    template <typename D, typename I, typename Enable = void>
    struct producer;

    template <typename T>
    class has_composable
    {
        template <typename U> static constexpr bool get_value(typename U::composable *) { return true; }
        template <typename>   static constexpr bool get_value(...) { return false; }

    public:

        static constexpr bool value = get_value<T>(0);
    };

    template <typename T>
    void clear_abi(T *) noexcept
    {}

    template <typename T>
    void clear_abi(T ** value) noexcept
    {
        *value = nullptr;
    }
}

template <typename D, typename I>
D * from_abi(const I & from) noexcept
{
    return &static_cast<impl::produce<D, I> *>(get_abi(from))->shim();
}

template <typename I, typename D, std::enable_if_t<std::is_base_of<Windows::Foundation::IUnknown, I>::value> * = nullptr>
abi<I> * to_abi(impl::producer<D, I> const * from) noexcept
{
    return reinterpret_cast<abi<I> *>(const_cast<impl::producer<D, I> *>(from));
}

template <typename I, typename D, std::enable_if_t<std::is_base_of< ::IUnknown, I>::value> * = nullptr>
abi<I> * to_abi(impl::producer<D, I> const * from) noexcept
{
    return const_cast<impl::producer<D, I> *>(from);
}

template <typename D, typename I = typename D::first_interface, typename ... Args, std::enable_if_t<!impl::has_composable<D>::value> * = nullptr>
auto make(Args && ... args)
{
    std::conditional_t<impl::is_base_of_v<Windows::Foundation::IUnknown, I>, I, com_ptr<I>> instance = nullptr;
    *put_abi(instance) = to_abi<I>(new D(std::forward<Args>(args) ...));
    return instance;
}

template <typename D, typename I = typename D::first_interface, typename ... Args, std::enable_if_t<impl::has_composable<D>::value> * = nullptr>
auto make(Args && ... args)
{
    com_ptr<I> instance;
    *put_abi(instance) = new D(std::forward<Args>(args) ...);
    return instance.template as<typename D::composable>();
}

template <typename D, typename ... Args>
auto make_self(Args && ... args)
{
    com_ptr<D> instance;
    *put_abi(instance) = new D(std::forward<Args>(args) ...);
    return instance;
}

namespace impl
{
    template <typename D, typename I, typename H>
    auto make_delegate(H && handler)
    {
        I instance = nullptr;
        *put_abi(instance) = new D(std::forward<H>(handler));
        return instance;
    }

    template <typename D, typename I, typename Enable>
    struct producer
    {
        operator I() const noexcept
        {
            I result = nullptr;
            copy_from_abi(result, const_cast<produce<D, I> *>(&vtable));
            return result;
        }

    private:

        produce<D, I> vtable;
    };

    template <typename D, typename I>
    struct produce_base : abi<I>
    {
        D & shim() noexcept
        {
            return *static_cast<D *>(reinterpret_cast<producer<D, I> *>(this));
        }

        HRESULT __stdcall QueryInterface(const GUID & id, void ** object) noexcept override
        {
            return shim().QueryInterface(id, object);
        }

        unsigned long __stdcall AddRef() noexcept override
        {
            return shim().AddRef();
        }

        unsigned long __stdcall Release() noexcept override
        {
            return shim().Release();
        }

        HRESULT __stdcall abi_GetIids(uint32_t * count, GUID ** array) noexcept override
        {
            return shim().abi_GetIids(count, array);
        }

        HRESULT __stdcall abi_GetRuntimeClassName(HSTRING * name) noexcept override
        {
            return shim().abi_GetRuntimeClassName(name);
        }

        HRESULT __stdcall abi_GetTrustLevel(Windows::Foundation::TrustLevel * trustLevel) noexcept override
        {
            return shim().abi_GetTrustLevel(trustLevel);
        }
    };

    template <typename D, typename I>
    struct producer<D, I, std::enable_if_t<std::is_base_of< ::IUnknown, I>::value>> : abi<I>
    {};

    template <typename D, typename I>
    struct producer<D, I, std::enable_if_t<impl::is_base_of_v<marker, I>>>
    {};

    template <typename D>
    struct produce<D, Windows::Foundation::IInspectable> : produce_base<D, Windows::Foundation::IInspectable>
    {};

    template <bool Agile>
    struct weak_ref : ABI::Windows::Foundation::IWeakReference
    {
        weak_ref(::IUnknown * object, const uint32_t strong) :
            m_object(object),
            m_strong(strong)
        {
            WINRT_ASSERT(object);
        }

        HRESULT __stdcall QueryInterface(const GUID & id, void ** object) noexcept override
        {
            if (id == __uuidof(ABI::Windows::Foundation::IWeakReference) || id == __uuidof(::IUnknown))
            {
                *object = static_cast<ABI::Windows::Foundation::IWeakReference *>(this);
                m_weak.fetch_add(1, std::memory_order_relaxed);
                return S_OK;
            }

            if (Agile)
            {
                if (id == __uuidof(IAgileObject))
                {
                    *object = static_cast< ::IUnknown *>(this);
                    m_weak.fetch_add(1, std::memory_order_relaxed);
                    return S_OK;
                }

                if (id == __uuidof(IMarshal))
                {
                    com_ptr< ::IUnknown> marshaler;
                    const HRESULT hr = CoCreateFreeThreadedMarshaler(this, put_abi(marshaler));

                    if (hr != S_OK)
                    {
                        return hr;
                    }

                    return marshaler->QueryInterface(id, object);
                }
            }

            *object = nullptr;
            return E_NOINTERFACE;
        }

        unsigned long __stdcall AddRef() noexcept override
        {
            return 1 + m_weak.fetch_add(1, std::memory_order_relaxed);
        }

        unsigned long __stdcall Release() noexcept override
        {
            const uint32_t target = m_weak.fetch_sub(1, std::memory_order_relaxed) - 1;

            if (target == 0)
            {
                delete this;
            }

            return target;

        }

        HRESULT __stdcall abi_Resolve(const GUID & id, ABI::Windows::Foundation::IInspectable ** objectReference) noexcept override
        {
            uint32_t target = m_strong.load(std::memory_order_relaxed);

            while (true)
            {
                if (target == 0)
                {
                    *objectReference = nullptr;
                    return S_OK;
                }

                if (m_strong.compare_exchange_weak(target, target + 1, std::memory_order_acquire, std::memory_order_relaxed))
                {
                    HRESULT hr = m_object->QueryInterface(id, reinterpret_cast<void **>(objectReference));
                    m_strong.fetch_sub(1, std::memory_order_relaxed);
                    return hr;
                }
            }
        }

        void set_strong(const uint32_t count)
        {
            m_strong = count;
        }

        uint32_t increment_strong() noexcept
        {
            return 1 + m_strong.fetch_add(1, std::memory_order_relaxed);
        }

        uint32_t decrement_strong() noexcept
        {
            const uint32_t target = m_strong.fetch_sub(1, std::memory_order_release) - 1;

            if (target == 0)
            {
                Release();
            }

            return target;
        }

        ABI::Windows::Foundation::IWeakReferenceSource * get_source()
        {
            increment_strong();
            return &m_source;
        }

    private:

        struct weak_source : ABI::Windows::Foundation::IWeakReferenceSource
        {
            weak_ref * that() noexcept
            {
                return reinterpret_cast<weak_ref *>(reinterpret_cast<uint8_t *>(this) - offsetof(weak_ref, m_source));
            }

            HRESULT __stdcall QueryInterface(const GUID & id, void ** object) noexcept override
            {
                if (id == __uuidof(ABI::Windows::Foundation::IWeakReferenceSource))
                {
                    *object = static_cast<ABI::Windows::Foundation::IWeakReferenceSource *>(this);
                    that()->increment_strong();
                    return S_OK;
                }

                return that()->m_object->QueryInterface(id, object);
            }

            unsigned long __stdcall AddRef() noexcept override
            {
                return that()->increment_strong();
            }

            unsigned long __stdcall Release() noexcept override
            {
                return that()->m_object->Release();
            }

            HRESULT __stdcall abi_GetWeakReference(ABI::Windows::Foundation::IWeakReference ** weakReference) noexcept override
            {
                *weakReference = that();
                that()->AddRef();
                return S_OK;
            }
        };

        weak_source m_source;
        ::IUnknown * m_object{};
        std::atomic<uint32_t> m_strong{ 1 };
        std::atomic<uint32_t> m_weak{ 1 };
    };
}

template <typename D, typename ... I>
struct implements : impl::producer<D, impl::uncloak_t<I>> ...
{
    using first_interface = typename impl::first_interface<impl::uncloak_t<I> ...>::type;
    using IInspectable = Windows::Foundation::IInspectable;

    operator IInspectable() const noexcept
    {
        IInspectable result;
        copy_from_abi(result, find_inspectable<I ...>());
        return result;
    }

    HRESULT __stdcall QueryInterface(const GUID & id, void ** object) noexcept
    {
        return query_interface(id, object, is_weak_ref_source{});
    }

    unsigned long __stdcall AddRef() noexcept
    {
        return add_reference(is_weak_ref_source{});
    }

    unsigned long __stdcall Release() noexcept
    {
        const uint32_t target = subtract_reference();

        if (target == 0)
        {
            std::atomic_thread_fence(std::memory_order_acquire);
            delete static_cast<D *>(this);
        }

        return target;
    }

    struct abi_guard
    {
        abi_guard(D & derived) :
            m_derived(derived)
        {
            m_derived.abi_enter();
        }

        ~abi_guard()
        {
            m_derived.abi_exit();
        }

    private:

        D & m_derived;
    };

protected:

    implements(uint32_t references = 1) :
        m_references(references)
    {}

    HRESULT __stdcall abi_GetIids(uint32_t * count, GUID ** array) noexcept
    {
        *count = uncloaked_interfaces<I ...>();

        if (*count == 0)
        {
            *array = nullptr;
            return S_OK;
        }

        *array = static_cast<GUID *>(CoTaskMemAlloc(sizeof(GUID) * *count));

        if (*array == nullptr)
        {
            return E_OUTOFMEMORY;
        }

        copy_guids<I ...>(*array);
        return S_OK;
    }

    HRESULT __stdcall abi_GetRuntimeClassName(HSTRING * name) noexcept
    {
        try
        {
            *name = detach_abi(static_cast<D *>(this)->GetRuntimeClassName());
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }

    HRESULT __stdcall abi_GetTrustLevel(Windows::Foundation::TrustLevel * trustLevel) noexcept
    {
        try
        {
            *trustLevel = static_cast<D *>(this)->GetTrustLevel();
            return S_OK;
        }
        catch (...) { return impl::to_hresult(); }
    }

    uint32_t subtract_reference() noexcept
    {
        return subtract_reference(is_weak_ref_source{});
    }

private:

    void abi_enter() noexcept {}
    void abi_exit() noexcept {}

    using is_agile = std::negation<impl::disjunction<std::is_same<non_agile, I> ...>>;
    using is_factory = impl::disjunction<std::is_same<ABI::Windows::Foundation::IActivationFactory, abi<I>> ...>;
    using is_inspectable = impl::disjunction<std::is_base_of<ABI::Windows::Foundation::IInspectable, abi<I>> ...>;
    using is_weak_ref_source = impl::conjunction<is_inspectable, std::negation<is_factory>, std::negation<impl::disjunction<std::is_same<no_weak_ref, I> ...>>>;
    using weak_ref_t = impl::weak_ref<is_agile::value>;

    static_assert(!is_factory::value || (is_factory::value && is_agile::value), "winrt::implements - activation factories must be agile.");

    std::atomic<std::conditional_t<is_weak_ref_source::value, uintptr_t, uint32_t>> m_references;

    HRESULT query_interface(const GUID & id, void ** object, std::true_type) noexcept
    {
        static_assert(is_weak_ref_source::value, "This is only for weak ref support.");

        if (query_interface(id, object, std::false_type{}) == S_OK)
        {
            return S_OK;
        }

        if (id == __uuidof(ABI::Windows::Foundation::IWeakReferenceSource))
        {
            *object = make_weak_ref();
            return *object ? S_OK : E_OUTOFMEMORY;
        }

        return E_NOINTERFACE;
    }

    HRESULT query_interface(const GUID & id, void ** object, std::false_type) noexcept
    {
        *object = find_interface<impl::uncloak_t<I> ...>(id);

        if (*object != nullptr)
        {
            AddRef();
            return S_OK;
        }

        if (is_agile::value)
        {
            if (id == __uuidof(IAgileObject))
            {
                *object = get_unknown();
                AddRef();
                return S_OK;
            }

            if (id == __uuidof(IMarshal))
            {
                com_ptr< ::IUnknown> marshaler;
                const HRESULT hr = CoCreateFreeThreadedMarshaler(get_unknown(), put_abi(marshaler));

                if (hr != S_OK)
                {
                    return hr;
                }

                return marshaler->QueryInterface(id, object);
            }
        }

        if (is_inspectable::value)
        {
            if (id == __uuidof(ABI::Windows::Foundation::IInspectable))
            {
                *object = find_inspectable<I ...>();
                AddRef();
                return S_OK;
            }
        }

        if (id == __uuidof(::IUnknown))
        {
            *object = get_unknown();
            AddRef();
            return S_OK;
        }

        return E_NOINTERFACE;
    }

    uint32_t add_reference(std::false_type) noexcept
    {
        return 1 + m_references.fetch_add(1, std::memory_order_relaxed);
    }

    uint32_t subtract_reference(std::false_type) noexcept
    {
        return m_references.fetch_sub(1, std::memory_order_release) - 1;
    }

    uint32_t add_reference(std::true_type) noexcept
    {
        static_assert(is_weak_ref_source::value, "This is only for weak ref support.");
        uintptr_t count_or_pointer = m_references.load(std::memory_order_relaxed);

        while (true)
        {
            if (is_weak_ref(count_or_pointer))
            {
                return decode_weak_ref(count_or_pointer)->increment_strong();
            }

            const uintptr_t target = count_or_pointer + 1;

            if (m_references.compare_exchange_weak(count_or_pointer, target, std::memory_order_relaxed))
            {
                return static_cast<uint32_t>(target);
            }
        }
    }

    uint32_t subtract_reference(std::true_type) noexcept
    {
        static_assert(is_weak_ref_source::value, "This is only for weak ref support.");
        uintptr_t count_or_pointer = m_references.load(std::memory_order_relaxed);

        while (true)
        {
            if (is_weak_ref(count_or_pointer))
            {
                return decode_weak_ref(count_or_pointer)->decrement_strong();
            }

            const uintptr_t target = count_or_pointer - 1;

            if (m_references.compare_exchange_weak(count_or_pointer, target, std::memory_order_release, std::memory_order_relaxed))
            {
                return static_cast<uint32_t>(target);
            }
        }
    }

    ABI::Windows::Foundation::IWeakReferenceSource * make_weak_ref() noexcept
    {
        static_assert(is_weak_ref_source::value, "This is only for weak ref support.");
        uintptr_t count_or_pointer = m_references.load(std::memory_order_relaxed);

        if (is_weak_ref(count_or_pointer))
        {
            return decode_weak_ref(count_or_pointer)->get_source();
        }

        com_ptr<weak_ref_t> weak_ref;
        *put_abi(weak_ref) = new (std::nothrow) weak_ref_t(get_unknown(), static_cast<uint32_t>(count_or_pointer));

        if (!weak_ref)
        {
            return nullptr;
        }

        const uintptr_t encoding = encode_weak_ref(get_abi(weak_ref));

        while (true)
        {
            if (m_references.compare_exchange_weak(count_or_pointer, encoding, std::memory_order_acq_rel, std::memory_order_relaxed))
            {
                ABI::Windows::Foundation::IWeakReferenceSource * result = weak_ref->get_source();
                detach_abi(weak_ref);
                return result;
            }

            if (is_weak_ref(count_or_pointer))
            {
                return decode_weak_ref(count_or_pointer)->get_source();
            }

            weak_ref->set_strong(static_cast<uint32_t>(count_or_pointer));
        }
    }

    static bool is_weak_ref(const intptr_t value) noexcept
    {
        static_assert(is_weak_ref_source::value, "This is only for weak ref support.");
        return value < 0;
    }

    static weak_ref_t * decode_weak_ref(const uintptr_t value) noexcept
    {
        static_assert(is_weak_ref_source::value, "This is only for weak ref support.");
        return reinterpret_cast<weak_ref_t *>(value << 1);
    }

    static uintptr_t encode_weak_ref(weak_ref_t * value) noexcept
    {
        static_assert(is_weak_ref_source::value, "This is only for weak ref support.");
        constexpr uintptr_t pointer_flag = static_cast<uintptr_t>(1) << ((sizeof(uintptr_t) * 8) - 1);
        WINRT_ASSERT((reinterpret_cast<uintptr_t>(value) & 1) == 0);
        return (reinterpret_cast<uintptr_t>(value) >> 1) | pointer_flag;
    }

    template <int = 0>
    static constexpr uint32_t uncloaked_interfaces() noexcept
    {
        return 0;
    }

    template <typename First, typename ... Rest>
    static constexpr uint32_t uncloaked_interfaces() noexcept
    {
        return !impl::is_cloaked_v<First> + uncloaked_interfaces<Rest ...>();
    }

    template <int = 0>
    void copy_guids(GUID *) const noexcept
    {
    }

    template <typename First, typename ... Rest>
    void copy_guids(GUID * ids, std::enable_if_t<impl::is_cloaked_v<First>> * = nullptr) const noexcept
    {
        copy_guids<Rest ...>(ids);
    }

    template <typename First, typename ... Rest>
    void copy_guids(GUID * ids, std::enable_if_t<!impl::is_cloaked_v<First>> * = nullptr) const noexcept
    {
        *ids++ = __uuidof(abi<First>);
        copy_guids<Rest ...>(ids);
    }

    template <int = 0>
    ABI::Windows::Foundation::IInspectable * find_inspectable() const noexcept
    {
        return nullptr;
    }

    template <typename First, typename ... Rest>
    ABI::Windows::Foundation::IInspectable * find_inspectable(std::enable_if_t<impl::is_base_of_v<ABI::Windows::Foundation::IInspectable, abi<First>>> * = nullptr) const noexcept
    {
        return to_abi<First>(this);
    }

    template <typename First, typename ... Rest>
    ABI::Windows::Foundation::IInspectable * find_inspectable(std::enable_if_t<!impl::is_base_of_v<ABI::Windows::Foundation::IInspectable, abi<First>>> * = nullptr) const noexcept
    {
        return find_inspectable<Rest ...>();
    }

    template <int = 0>
    void * find_interface(const GUID &) const noexcept
    {
        return nullptr;
    }

    template <typename First, typename ... Rest>
    void * find_interface(const GUID & id, std::enable_if_t<impl::is_base_of_v<impl::marker, First>> * = nullptr) const noexcept
    {
        return find_interface<Rest ...>(id);
    }

    template <typename First, typename ... Rest>
    void * find_interface(const GUID & id, std::enable_if_t<!impl::is_base_of_v<impl::marker, First>> * = nullptr) const noexcept
    {
        if (id == __uuidof(abi<First>))
        {
            return to_abi<First>(this);
        }

        return find_interface<Rest ...>(id);
    }

    ::IUnknown * get_unknown() const noexcept
    {
        return to_abi<first_interface>(this);
    }

    hstring GetRuntimeClassName() const
    {
        throw hresult_not_implemented();
    }

    Windows::Foundation::TrustLevel GetTrustLevel() const noexcept
    {
        return Windows::Foundation::TrustLevel::BaseTrust;
    }

    template <typename D, typename I>
    friend struct impl::produce_base;

    template <typename D, typename I>
    friend struct impl::produce;
};

template <typename D, typename ... R>
struct overrides : implements<D, R ...>
{
    template <typename Qi>
    Qi as() const
    {
        return m_inner.as<Qi>();
    }

    HRESULT __stdcall QueryInterface(const GUID & id, void ** object) noexcept
    {
        HRESULT result = implements<D, R ...>::QueryInterface(id, object);

        if (result == E_NOINTERFACE)
        {
            result = get_abi(m_inner)->QueryInterface(id, object);
        }

        return result;
    }

protected:

    Windows::Foundation::IInspectable m_inner;
};

namespace Windows::Foundation
{

    struct IActivationFactory;

    template <typename D>
    struct WINRT_EBO impl_IActivationFactory
    {
        IInspectable ActivateInstance() const;
    };
}

namespace impl
{
    template <> struct traits<Windows::Foundation::IActivationFactory>
    {
        using abi = ABI::Windows::Foundation::IActivationFactory;
        template <typename D> using consume = Windows::Foundation::impl_IActivationFactory<D>;
    };

    template <typename D>
    struct produce<D, Windows::Foundation::IActivationFactory> : produce_base<D, Windows::Foundation::IActivationFactory>
    {
        HRESULT __stdcall abi_ActivateInstance(abi_arg_out<Windows::Foundation::IInspectable> instance) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *instance = detach_abi(this->shim().ActivateInstance());
                return S_OK;
            }
            catch (...)
            {
                *instance = nullptr;
                return impl::to_hresult();
            }
        }
    };

    template <typename Class, typename Interface>
    Interface get_agile_activation_factory()
    {
        hstring_view classId(impl::traits<Class>::name());

        Interface factory;
        check_hresult(WINRT_RoGetActivationFactory(get_abi(classId), __uuidof(abi<Interface>), reinterpret_cast<void **>(put_abi(factory))));

        if (!factory.template try_as<IAgileObject>())
        {
            return nullptr;
        }

        return factory;
    }

    template <typename Class, typename Interface>
    Interface get_activation_factory()
    {
        hstring_view classId(impl::traits<Class>::name());

        Interface factory;
        check_hresult(WINRT_RoGetActivationFactory(get_abi(classId), __uuidof(abi<Interface>), reinterpret_cast<void **>(put_abi(factory))));
        return factory;
    }
}

namespace Windows::Foundation
{
    struct IActivationFactory :
        IInspectable,
        impl::consume<IActivationFactory>
    {
        IActivationFactory(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename D>
    IInspectable impl_IActivationFactory<D>::ActivateInstance() const
    {
        IInspectable instance;
        check_hresult(WINRT_SHIM(IActivationFactory)->abi_ActivateInstance(put_abi(instance)));
        return instance;
    }

}

enum class apartment_type
{
    single_threaded,
    multi_threaded
};

inline void init_apartment(const apartment_type type = apartment_type::multi_threaded)
{
    check_hresult<S_FALSE>(WINRT_RoInitialize(static_cast<uint32_t>(type)));
}

inline void uninit_apartment() noexcept
{
    WINRT_RoUninitialize();
}

template <typename Class, typename Interface = Windows::Foundation::IActivationFactory>
Interface get_activation_factory()
{
    static Interface factory = impl::get_agile_activation_factory<Class, Interface>();

    if (!factory)
    {
        return impl::get_activation_factory<Class, Interface>();
    }

    return factory;
}

template <typename Class, typename Instance = Class>
Instance activate_instance()
{
    return get_activation_factory<Class>().ActivateInstance().template as<Instance>();
}

namespace ABI::Windows::Foundation
{
    template <typename T> struct EventHandler;
    template <typename TSender, typename TArgs> struct TypedEventHandler;

    template <typename T>
    struct __declspec(novtable) impl_EventHandler : IUnknown
    {
        virtual HRESULT __stdcall abi_Invoke(IInspectable * sender, arg_in<T> args) = 0;
    };

    template <typename TSender, typename TArgs>
    struct __declspec(novtable) impl_TypedEventHandler : IUnknown
    {
        virtual HRESULT __stdcall abi_Invoke(arg_in<TSender> sender, arg_in<TArgs> args) = 0;
    };

    template <typename T> struct EventHandler : impl::not_specialized<EventHandler<T>> {};
    template <typename TSender, typename TArgs> struct TypedEventHandler : impl::not_specialized<TypedEventHandler<TSender, TArgs>> {};
}

namespace Windows::Foundation
{
    template <typename T> struct EventHandler;
    template <typename TSender, typename TArgs> struct TypedEventHandler;
}

namespace impl
{
    template <typename T> struct traits<Windows::Foundation::EventHandler<T>>
    {
        using abi = ABI::Windows::Foundation::EventHandler<abi<T>>;
    };

    template <typename TSender, typename TArgs> struct traits<Windows::Foundation::TypedEventHandler<TSender, TArgs>>
    {
        using abi = ABI::Windows::Foundation::TypedEventHandler<abi<TSender>, abi<TArgs>>;
    };

    template <typename T, typename H>
    struct event_handler : implements<event_handler<T, H>, abi<Windows::Foundation::EventHandler<T>>>, H
    {
        event_handler(H && handler) : H(std::forward<H>(handler)) {}

        HRESULT __stdcall abi_Invoke(abi_arg_in<Windows::Foundation::IInspectable> sender, abi_arg_in<T> args) noexcept override
        {
            try
            {
                (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const T *>(&args));
                return S_OK;
            }
            catch (...) { return impl::to_hresult(); }
        }
    };

    template <typename TSender, typename TArgs, typename H>
    struct typed_event_handler : implements<typed_event_handler<TSender, TArgs, H>, abi<Windows::Foundation::TypedEventHandler<TSender, TArgs>>>, H
    {
        typed_event_handler(H && handler) : H(std::forward<H>(handler)) {}

        HRESULT __stdcall abi_Invoke(abi_arg_in<TSender> sender, abi_arg_in<TArgs> args) noexcept override
        {
            try
            {
                (*this)(*reinterpret_cast<const TSender *>(&sender), *reinterpret_cast<const TArgs *>(&args));
                return S_OK;
            }
            catch (...) { return impl::to_hresult(); }
        }
    };
}

namespace Windows::Foundation
{
    template <typename T>
    struct WINRT_EBO EventHandler : IUnknown
    {
        EventHandler(std::nullptr_t = nullptr) noexcept {}

        template <typename L>
        EventHandler(L handler) :
            EventHandler(impl::make_delegate<impl::event_handler<T, L>, EventHandler<T>>(std::forward<L>(handler)))
        {}

        template <typename F> EventHandler(F * handler) :
            EventHandler([=](auto && ... args) { handler(args ...); })
        {}

        template <typename O, typename M> EventHandler(O * object, M method) :
            EventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
        {}

        void operator()(const IInspectable & sender, const T & args) const
        {
            check_hresult((*(abi<EventHandler<T>> **)this)->abi_Invoke(get_abi(sender), get_abi(args)));
        }
    };

    template <typename TSender, typename TArgs>
    struct WINRT_EBO TypedEventHandler : IUnknown
    {
        TypedEventHandler(std::nullptr_t = nullptr) noexcept {}

        template <typename L>
        TypedEventHandler(L handler) :
            TypedEventHandler(impl::make_delegate<impl::typed_event_handler<TSender, TArgs, L>, TypedEventHandler<TSender, TArgs>>(std::forward<L>(handler)))
        {}

        template <typename F> TypedEventHandler(F * handler) :
            TypedEventHandler([=](auto && ... args) { handler(args ...); })
        {}

        template <typename O, typename M> TypedEventHandler(O * object, M method) :
            TypedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
        {}

        void operator()(const TSender & sender, const TArgs & args) const
        {
            check_hresult((*(abi<TypedEventHandler<TSender, TArgs>> **)this)->abi_Invoke(get_abi(sender), get_abi(args)));
        }
    };
}

namespace Windows::Foundation::Collections
{
    enum class CollectionChange
    {
        Reset,
        ItemInserted,
        ItemRemoved,
        ItemChanged,
    };
}

namespace impl
{
    template <typename T>
    class has_GetAt
    {
        template <typename U, typename = decltype(std::declval<U>().GetAt(0))> static constexpr bool get_value(int) { return true; }
        template <typename> static constexpr bool get_value(...) { return false; }

    public:

        static constexpr bool value = get_value<T>(0);
    };
}

namespace ABI::Windows::Foundation::Collections
{
    template <typename K, typename V> struct MapChangedEventHandler;
    template <typename T> struct VectorChangedEventHandler;

    template <typename T> struct IIterator;
    template <typename T> struct IIterable;
    template <typename K, typename V> struct IKeyValuePair;
    template <typename T> struct IVectorView;
    template <typename T> struct IVector;
    template <typename K, typename V> struct IMapView;
    template <typename K, typename V> struct IMap;
    template <typename K> struct IMapChangedEventArgs;
    template <typename K, typename V> struct IObservableMap;
    template <typename T> struct IObservableVector;

    struct __declspec(uuid("575933df-34fe-4480-af15-07691f3d5d9b")) __declspec(novtable) IVectorChangedEventArgs : IInspectable
    {
        virtual HRESULT __stdcall get_CollectionChange(winrt::Windows::Foundation::Collections::CollectionChange * value) = 0;
        virtual HRESULT __stdcall get_Index(uint32_t * value) = 0;
    };

    template <typename K, typename V>
    struct __declspec(novtable) impl_MapChangedEventHandler : IUnknown
    {
        virtual HRESULT __stdcall abi_Invoke(IObservableMap<K, V> * sender, IMapChangedEventArgs<K> * args) = 0;
    };

    template <typename T>
    struct __declspec(novtable) impl_VectorChangedEventHandler : IUnknown
    {
        virtual HRESULT __stdcall abi_Invoke(IObservableVector<T> * sender, IVectorChangedEventArgs * args) = 0;
    };

    template <typename T>
    struct __declspec(novtable) impl_IIterator : IInspectable
    {
        virtual HRESULT __stdcall get_Current(arg_out<T> current) = 0;
        virtual HRESULT __stdcall get_HasCurrent(bool * hasCurrent) = 0;
        virtual HRESULT __stdcall abi_MoveNext(bool * hasCurrent) = 0;
        virtual HRESULT __stdcall abi_GetMany(uint32_t capacity, arg_out<T> value, uint32_t * actual) = 0;
    };

    template <typename T>
    struct __declspec(novtable) impl_IIterable : IInspectable
    {
        virtual HRESULT __stdcall abi_First(IIterator<T> ** first) = 0;
    };

    template <typename K, typename V>
    struct __declspec(novtable) impl_IKeyValuePair : IInspectable
    {
        virtual HRESULT __stdcall get_Key(arg_out<K> key) = 0;
        virtual HRESULT __stdcall get_Value(arg_out<V> value) = 0;
    };

    template <typename T>
    struct __declspec(novtable) impl_IVectorView : IInspectable
    {
        virtual HRESULT __stdcall abi_GetAt(uint32_t index, arg_out<T> item) = 0;
        virtual HRESULT __stdcall get_Size(uint32_t * size) = 0;
        virtual HRESULT __stdcall abi_IndexOf(arg_in<T> value, uint32_t * index, bool * found) = 0;
        virtual HRESULT __stdcall abi_GetMany(uint32_t startIndex, uint32_t capacity, arg_out<T> value, uint32_t * actual) = 0;
    };

    template <typename T>
    struct __declspec(novtable) impl_IVector : IInspectable
    {
        virtual HRESULT __stdcall abi_GetAt(uint32_t index, arg_out<T> item) = 0;
        virtual HRESULT __stdcall get_Size(uint32_t * size) = 0;
        virtual HRESULT __stdcall abi_GetView(IVectorView<T> ** view) = 0;
        virtual HRESULT __stdcall abi_IndexOf(arg_in<T> value, uint32_t * index, bool * found) = 0;
        virtual HRESULT __stdcall abi_SetAt(uint32_t index, arg_in<T> item) = 0;
        virtual HRESULT __stdcall abi_InsertAt(uint32_t index, arg_in<T> item) = 0;
        virtual HRESULT __stdcall abi_RemoveAt(uint32_t index) = 0;
        virtual HRESULT __stdcall abi_Append(arg_in<T> item) = 0;
        virtual HRESULT __stdcall abi_RemoveAtEnd() = 0;
        virtual HRESULT __stdcall abi_Clear() = 0;
        virtual HRESULT __stdcall abi_GetMany(uint32_t startIndex, uint32_t capacity, arg_out<T> value, uint32_t * actual) = 0;
        virtual HRESULT __stdcall abi_ReplaceAll(uint32_t count, arg_out<T> value) = 0;

    };

    template <typename K, typename V>
    struct __declspec(novtable) impl_IMapView : IInspectable
    {
        virtual HRESULT __stdcall abi_Lookup(arg_in<K> key, arg_out<V> value) = 0;
        virtual HRESULT __stdcall get_Size(uint32_t * size) = 0;
        virtual HRESULT __stdcall abi_HasKey(arg_in<K> key, bool * found) = 0;
        virtual HRESULT __stdcall abi_Split(IMapView<K, V> ** firstPartition, IMapView<K, V> ** secondPartition) = 0;
    };

    template <typename K, typename V>
    struct __declspec(novtable) impl_IMap : IInspectable
    {
        virtual HRESULT __stdcall abi_Lookup(arg_in<K> key, arg_out<V> value) = 0;
        virtual HRESULT __stdcall get_Size(uint32_t * size) = 0;
        virtual HRESULT __stdcall abi_HasKey(arg_in<K> key, bool * found) = 0;
        virtual HRESULT __stdcall abi_GetView(IMapView<K, V> ** view) = 0;
        virtual HRESULT __stdcall abi_Insert(arg_in<K> key, arg_in<V> value, bool * replaced) = 0;
        virtual HRESULT __stdcall abi_Remove(arg_in<K> key) = 0;
        virtual HRESULT __stdcall abi_Clear() = 0;
    };

    template <typename K>
    struct __declspec(novtable) impl_IMapChangedEventArgs : IInspectable
    {
        virtual HRESULT __stdcall get_CollectionChange(winrt::Windows::Foundation::Collections::CollectionChange * value) = 0;
        virtual HRESULT __stdcall get_Key(arg_out<K> value) = 0;
    };

    template <typename K, typename V>
    struct __declspec(novtable) impl_IObservableMap : IInspectable
    {
        virtual HRESULT __stdcall add_MapChanged(MapChangedEventHandler<K, V> * handler, event_token * token) = 0;
        virtual HRESULT __stdcall remove_MapChanged(event_token token) = 0;
    };

    template <typename T>
    struct __declspec(novtable) impl_IObservableVector : IInspectable
    {
        virtual HRESULT __stdcall add_VectorChanged(VectorChangedEventHandler<T> * handler, event_token *  token) = 0;
        virtual HRESULT __stdcall remove_VectorChanged(event_token token) = 0;
    };

    template <typename K, typename V> struct MapChangedEventHandler : impl::not_specialized<MapChangedEventHandler<K, V>> {};
    template <typename T> struct VectorChangedEventHandler : impl::not_specialized <VectorChangedEventHandler<T>> {};
    template <typename T> struct IIterator : impl::not_specialized <IIterator<T>> {};
    template <typename T> struct IIterable : impl::not_specialized <IIterable<T>> {};
    template <typename K, typename V> struct IKeyValuePair : impl::not_specialized <IKeyValuePair<K, V>> {};
    template <typename T> struct IVectorView : impl::not_specialized <IVectorView<T>> {};
    template <typename T> struct IVector : impl::not_specialized <IVector<T>> {};
    template <typename K, typename V> struct IMapView : impl::not_specialized <IMapView<K, V>> {};
    template <typename K, typename V> struct IMap : impl::not_specialized <IMap<K, V>> {};
    template <typename K> struct IMapChangedEventArgs : impl::not_specialized <IMapChangedEventArgs<K>> {};
    template <typename K, typename V> struct IObservableMap : impl::not_specialized <IObservableMap<K, V>> {};
    template <typename T> struct IObservableVector : impl::not_specialized <IObservableVector<T>> {};
}

namespace Windows::Foundation::Collections
{
    template <typename K, typename V> struct MapChangedEventHandler;
    template <typename T> struct VectorChangedEventHandler;

    struct IVectorChangedEventArgs;
    template <typename T> struct IIterator;
    template <typename T> struct IIterable;
    template <typename K, typename V> struct IKeyValuePair;
    template <typename T> struct IVectorView;
    template <typename T> struct IVector;
    template <typename K, typename V> struct IMapView;
    template <typename K, typename V> struct IMap;
    template <typename K> struct IMapChangedEventArgs;
    template <typename K, typename V> struct IObservableMap;
    template <typename T> struct IObservableVector;

    template <typename D>
    struct WINRT_EBO impl_IVectorChangedEventArgs
    {
        CollectionChange CollectionChange() const;
        uint32_t Index() const;
    };

    template <typename D, typename T>
    struct impl_IIterator
    {
        T Current() const;
        bool HasCurrent() const;
        bool MoveNext() const;
        uint32_t GetMany(array_view<T> values) const;

        auto & operator++()
        {
            if (!MoveNext())
            {
                static_cast<D &>(*this) = nullptr;
            }

            return *this;
        }

        T operator *() const
        {
            return Current();
        }
    };

    template <typename D, typename T>
    struct impl_IIterable
    {
        IIterator<T> First() const;
    };

    template <typename D, typename K, typename V>
    struct impl_IKeyValuePair
    {
        K Key() const;
        V Value() const;

        bool operator==(const IKeyValuePair<K, V> & other) const
        {
            return Key() == other.Key() && Value() == other.Value();
        }

        bool operator!=(const IKeyValuePair<K, V> & other) const
        {
            return !(*this == other);
        }
    };

    template <typename D, typename T>
    struct impl_IVectorView
    {
        T GetAt(const uint32_t index) const;
        uint32_t Size() const;
        bool IndexOf(const T & value, uint32_t & index) const;
        uint32_t GetMany(uint32_t startIndex, array_view<T> values) const;
    };

    template <typename D, typename T>
    struct impl_IVector
    {
        T GetAt(const uint32_t index) const;
        uint32_t Size() const;
        IVectorView<T> GetView() const;
        bool IndexOf(const T & value, uint32_t & index) const;
        void SetAt(const uint32_t index, const T & value) const;
        void InsertAt(const uint32_t index, const T & value) const;
        void RemoveAt(const uint32_t index) const;
        void Append(const T & value) const;
        void RemoveAtEnd() const;
        void Clear() const;
        uint32_t GetMany(uint32_t startIndex, array_view<T> values) const;
        void ReplaceAll(array_view<const T> value) const;
    };

    template <typename D, typename K, typename V>
    struct impl_IMapView
    {
        V Lookup(const K & key) const;
        uint32_t Size() const;
        bool HasKey(const K & key) const;
        void Split(IMapView<K, V> & firstPartition, IMapView<K, V> & secondPartition);
    };

    template <typename D, typename K, typename V>
    struct impl_IMap
    {
        V Lookup(const K & key) const;
        uint32_t Size() const;
        bool HasKey(const K & key) const;
        IMapView<K, V> GetView() const;
        bool Insert(const K & key, const V & value) const;
        void Remove(const K & key) const;
        void Clear() const;
    };

    template <typename D, typename K>
    struct impl_IMapChangedEventArgs
    {
        CollectionChange CollectionChange() const;
        K Key() const;
    };

    template <typename D, typename K, typename V>
    struct impl_IObservableMap
    {
        event_token MapChanged(const MapChangedEventHandler<K, V> & handler) const;
        void MapChanged(const event_token cookie) const;

        using MapChanged_revoker = event_revoker<IObservableMap<K, V>>;

        MapChanged_revoker MapChanged(auto_revoke_t, const MapChangedEventHandler<K, V> & handler) const
        {
            return impl::make_event_revoker<D, IObservableMap<K, V>>(this, &abi<IObservableMap<K, V>>::remove_MapChanged, MapChanged(handler));
        }
    };

    template <typename D, typename T>
    struct impl_IObservableVector
    {
        event_token VectorChanged(const VectorChangedEventHandler<T> & handler) const;
        void VectorChanged(const event_token cookie) const;

        using VectorChanged_revoker = event_revoker<IObservableVector<T>>;

        VectorChanged_revoker VectorChanged(auto_revoke_t, const VectorChangedEventHandler<T> & handler) const
        {
            return impl::make_event_revoker<D, IObservableVector<T>>(this, &abi<IObservableVector<T>>::remove_VectorChanged, VectorChanged(handler));
        }
    };
}

namespace impl
{
    template <> struct traits<Windows::Foundation::Collections::IVectorChangedEventArgs>
    {
        using abi = ABI::Windows::Foundation::Collections::IVectorChangedEventArgs;
        template <typename D> using consume = Windows::Foundation::Collections::impl_IVectorChangedEventArgs<D>;
    };

    template <typename K, typename V> struct traits<Windows::Foundation::Collections::MapChangedEventHandler<K, V>>
    {
        using abi = ABI::Windows::Foundation::Collections::MapChangedEventHandler<abi<K>, abi<V>>;
    };

    template <typename T> struct traits<Windows::Foundation::Collections::VectorChangedEventHandler<T>>
    {
        using abi = ABI::Windows::Foundation::Collections::VectorChangedEventHandler<abi<T>>;
    };

    template <typename T> struct traits<Windows::Foundation::Collections::IIterator<T>>
    {
        using abi = ABI::Windows::Foundation::Collections::IIterator<abi<T>>;
        template <typename D> using consume = Windows::Foundation::Collections::impl_IIterator<D, T>;
    };

    template <typename T> struct traits<Windows::Foundation::Collections::IIterable<T>>
    {
        using abi = ABI::Windows::Foundation::Collections::IIterable<abi<T>>;
        template <typename D> using consume = Windows::Foundation::Collections::impl_IIterable<D, T>;
    };

    template <typename K, typename V> struct traits<Windows::Foundation::Collections::IKeyValuePair<K, V>>
    {
        using abi = ABI::Windows::Foundation::Collections::IKeyValuePair<abi<K>, abi<V>>;
        template <typename D> using consume = Windows::Foundation::Collections::impl_IKeyValuePair<D, K, V>;
    };

    template <typename T> struct traits<Windows::Foundation::Collections::IVectorView<T>>
    {
        using abi = ABI::Windows::Foundation::Collections::IVectorView<abi<T>>;
        template <typename D> using consume = Windows::Foundation::Collections::impl_IVectorView<D, T>;
    };

    template <typename T> struct traits<Windows::Foundation::Collections::IVector<T>>
    {
        using abi = ABI::Windows::Foundation::Collections::IVector<abi<T>>;
        template <typename D> using consume = Windows::Foundation::Collections::impl_IVector<D, T>;
    };

    template <typename K, typename V> struct traits<Windows::Foundation::Collections::IMapView<K, V>>
    {
        using abi = ABI::Windows::Foundation::Collections::IMapView<abi<K>, abi<V>>;
        template <typename D> using consume = Windows::Foundation::Collections::impl_IMapView<D, K, V>;
    };

    template <typename K, typename V> struct traits<Windows::Foundation::Collections::IMap<K, V>>
    {
        using abi = ABI::Windows::Foundation::Collections::IMap<abi<K>, abi<V>>;
        template <typename D> using consume = Windows::Foundation::Collections::impl_IMap<D, K, V>;
    };

    template <typename K> struct traits<Windows::Foundation::Collections::IMapChangedEventArgs<K>>
    {
        using abi = ABI::Windows::Foundation::Collections::IMapChangedEventArgs<abi<K>>;
        template <typename D> using consume = Windows::Foundation::Collections::impl_IMapChangedEventArgs<D, K>;
    };

    template <typename K, typename V> struct traits<Windows::Foundation::Collections::IObservableMap<K, V>>
    {
        using abi = ABI::Windows::Foundation::Collections::IObservableMap<abi<K>, abi<V>>;
        template <typename D> using consume = Windows::Foundation::Collections::impl_IObservableMap<D, K, V>;
    };

    template <typename T> struct traits<Windows::Foundation::Collections::IObservableVector<T>>
    {
        using abi = ABI::Windows::Foundation::Collections::IObservableVector<abi<T>>;
        template <typename D> using consume = Windows::Foundation::Collections::impl_IObservableVector<D, T>;
    };

    template <typename T>
    struct fast_iterator
    {
        using iterator_category = std::input_iterator_tag;
        using value_type = T;
        using difference_type = ptrdiff_t;
        using pointer = T *;
        using reference = T &;

        fast_iterator(const T & collection, const uint32_t index) noexcept :
        m_collection(&collection),
            m_index(index)
        {}

        fast_iterator & operator++() noexcept
        {
            ++m_index;
            return *this;
        }

        auto operator *() const
        {
            return m_collection->GetAt(m_index);
        }

        bool operator==(const fast_iterator & other) const noexcept
        {
            WINRT_ASSERT(m_collection == other.m_collection);
            return m_index == other.m_index;
        }

        bool operator!=(const fast_iterator & other) const noexcept
        {
            return !(*this == other);
        }

    private:

        const T * m_collection = nullptr;
        uint32_t m_index = 0;
    };
}

namespace Windows::Foundation::Collections
{
    template <typename T>
    struct WINRT_EBO VectorChangedEventHandler : IUnknown
    {
        VectorChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
        template <typename L> VectorChangedEventHandler(L handler);
        template <typename F> VectorChangedEventHandler(F * handler);
        template <typename O, typename M> VectorChangedEventHandler(O * object, M method);
        void operator()(const IObservableVector<T> & sender, const IVectorChangedEventArgs & args) const;
    };

    template <typename K, typename V>
    struct WINRT_EBO MapChangedEventHandler : IUnknown
    {
        MapChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
        template <typename L> MapChangedEventHandler(L handler);
        template <typename F> MapChangedEventHandler(F * handler);
        template <typename O, typename M> MapChangedEventHandler(O * object, M method);
        void operator()(const IObservableMap<K, V> & sender, const IMapChangedEventArgs<K> & args) const;
    };

    struct IVectorChangedEventArgs :
        IInspectable,
        impl::consume<IVectorChangedEventArgs>
    {
        IVectorChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename T>
    struct WINRT_EBO IIterator :
        IInspectable,
        impl::consume<IIterator<T>>
    {
        using iterator_category = std::input_iterator_tag;
        using value_type = T;
        using difference_type = ptrdiff_t;
        using pointer = T *;
        using reference = T &;

        IIterator(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename T>
    struct WINRT_EBO IIterable :
        IInspectable,
        impl::consume<IIterable<T>>
    {
        IIterable(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename K, typename V>
    struct WINRT_EBO IIterable<IKeyValuePair<K, V>> :
        IInspectable,
        impl::consume<IIterable<IKeyValuePair<K, V>>>
    {
        IIterable(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename K, typename V>
    struct WINRT_EBO IKeyValuePair :
        IInspectable,
        impl::consume<IKeyValuePair<K, V>>
    {
        IKeyValuePair(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename T>
    struct WINRT_EBO IVectorView :
        IInspectable,
        impl::consume<IVectorView<T>>,
        impl::require<IVectorView<T>, IIterable<T>>
    {
        IVectorView(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename T>
    struct WINRT_EBO IVector :
        IInspectable,
        impl::consume<IVector<T>>,
        impl::require<IVector<T>, IIterable<T>>
    {
        IVector(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename K, typename V>
    struct WINRT_EBO IMapView :
        IInspectable,
        impl::consume<IMapView<K, V>>,
        impl::require<IMapView<K, V>, IIterable<IKeyValuePair<K, V>>>
    {
        IMapView(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename K, typename V>
    struct WINRT_EBO IMap :
        IInspectable,
        impl::consume<IMap<K, V>>,
        impl::require<IMap<K, V>, IIterable<IKeyValuePair<K, V>>>
    {
        IMap(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename K>
    struct WINRT_EBO IMapChangedEventArgs :
        IInspectable,
        impl::consume<IMapChangedEventArgs<K>>
    {
        IMapChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename K, typename V>
    struct WINRT_EBO IObservableMap :
        IInspectable,
        impl::consume<IObservableMap<K, V>>,
        impl::require<IObservableMap<K, V>, IMap<K, V>, IIterable<IKeyValuePair<K, V>>>
    {
        IObservableMap(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename T>
    struct WINRT_EBO IObservableVector :
        IInspectable,
        impl::consume<IObservableVector<T>>,
        impl::require<IObservableVector<T>, IVector<T>, IIterable<T>>
    {
        IObservableVector(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename D>
    CollectionChange impl_IVectorChangedEventArgs<D>::CollectionChange() const
    {
        Collections::CollectionChange value{};
        check_hresult((*(abi<IVectorChangedEventArgs> **)&static_cast<const IVectorChangedEventArgs &>(static_cast<const D &>(*this)))->get_CollectionChange(&value));
        return value;
    }

    template <typename D>
    uint32_t impl_IVectorChangedEventArgs<D>::Index() const
    {
        uint32_t index = 0;
        check_hresult((*(abi<IVectorChangedEventArgs> **)&static_cast<const IVectorChangedEventArgs &>(static_cast<const D &>(*this)))->get_Index(&index));
        return index;
    }

    template <typename D, typename T>
    T impl_IIterator<D, T>::Current() const
    {
        T result = impl::empty_value<T>();
        check_hresult((*(abi<IIterator<T>> **)&static_cast<const IIterator<T> &>(static_cast<const D &>(*this)))->get_Current(put_abi(result)));
        return result;
    }

    template <typename D, typename T>
    bool impl_IIterator<D, T>::HasCurrent() const
    {
        bool temp = false;
        check_hresult((*(abi<IIterator<T>> **)&static_cast<const IIterator<T> &>(static_cast<const D &>(*this)))->get_HasCurrent(put_abi(temp)));
        return temp;
    }

    template <typename D, typename T>
    bool impl_IIterator<D, T>::MoveNext() const
    {
        bool temp = false;
        check_hresult((*(abi<IIterator<T>> **)&static_cast<const IIterator<T> &>(static_cast<const D &>(*this)))->abi_MoveNext(put_abi(temp)));
        return temp;
    }

    template <typename D, typename T>
    uint32_t impl_IIterator<D, T>::GetMany(array_view<T> values) const
    {
        uint32_t actual = 0;
        check_hresult((*(abi<IIterator<T>> **)&static_cast<const IIterator<T> &>(static_cast<const D &>(*this)))->abi_GetMany(values.size(), get_abi(values), &actual));
        return actual;
    }

    template <typename D, typename T>
    IIterator<T> impl_IIterable<D, T>::First() const
    {
        IIterator<T> iterator;
        check_hresult((*(abi<IIterable<T>> **)&static_cast<const IIterable<T> &>(static_cast<const D &>(*this)))->abi_First(put_abi(iterator)));
        return iterator;
    }

    template <typename D, typename K, typename V>
    K impl_IKeyValuePair<D, K, V>::Key() const
    {
        K result = impl::empty_value<K>();
        check_hresult((*(abi<IKeyValuePair<K, V>> **)&static_cast<const IKeyValuePair<K, V> &>(static_cast<const D &>(*this)))->get_Key(put_abi(result)));
        return result;
    }

    template <typename D, typename K, typename V>
    V impl_IKeyValuePair<D, K, V>::Value() const
    {
        V result = impl::empty_value<V>();
        check_hresult((*(abi<IKeyValuePair<K, V>> **)&static_cast<const IKeyValuePair<K, V> &>(static_cast<const D &>(*this)))->get_Value(put_abi(result)));
        return result;
    }

    template <typename D, typename T>
    T impl_IVectorView<D, T>::GetAt(const uint32_t index) const
    {
        T result = impl::empty_value<T>();
        check_hresult((*(abi<IVectorView<T>> **)&static_cast<const IVectorView<T> &>(static_cast<const D &>(*this)))->abi_GetAt(index, put_abi(result)));
        return result;
    }

    template <typename D, typename T>
    uint32_t impl_IVectorView<D, T>::Size() const
    {
        uint32_t size = 0;
        check_hresult((*(abi<IVectorView<T>> **)&static_cast<const IVectorView<T> &>(static_cast<const D &>(*this)))->get_Size(&size));
        return size;
    }

    template <typename D, typename T>
    bool impl_IVectorView<D, T>::IndexOf(const T & value, uint32_t & index) const
    {
        bool found = false;
        check_hresult((*(abi<IVectorView<T>> **)&static_cast<const IVectorView<T> &>(static_cast<const D &>(*this)))->abi_IndexOf(get_abi(value), &index, put_abi(found)));
        return found;
    }

    template <typename D, typename T>
    uint32_t impl_IVectorView<D, T>::GetMany(uint32_t startIndex, array_view<T> values) const
    {
        uint32_t actual = 0;
        check_hresult((*(abi<IVectorView<T>> **)&static_cast<const IVectorView<T> &>(static_cast<const D &>(*this)))->abi_GetMany(startIndex, values.size(), get_abi(values), &actual));
        return actual;
    }

    template <typename D, typename T>
    T impl_IVector<D, T>::GetAt(const uint32_t index) const
    {
        T result = impl::empty_value<T>();
        check_hresult((*(abi<IVector<T>> **)&static_cast<const IVector<T> &>(static_cast<const D &>(*this)))->abi_GetAt(index, put_abi(result)));
        return result;
    }

    template <typename D, typename T>
    uint32_t impl_IVector<D, T>::Size() const
    {
        uint32_t size = 0;
        check_hresult((*(abi<IVector<T>> **)&static_cast<const IVector<T> &>(static_cast<const D &>(*this)))->get_Size(&size));
        return size;
    }

    template <typename D, typename T>
    IVectorView<T> impl_IVector<D, T>::GetView() const
    {
        IVectorView<T> view;
        check_hresult((*(abi<IVector<T>> **)&static_cast<const IVector<T> &>(static_cast<const D &>(*this)))->abi_GetView(put_abi(view)));
        return view;
    }

    template <typename D, typename T>
    bool impl_IVector<D, T>::IndexOf(const T & value, uint32_t & index) const
    {
        bool found = false;
        check_hresult((*(abi<IVector<T>> **)&static_cast<const IVector<T> &>(static_cast<const D &>(*this)))->abi_IndexOf(get_abi(value), &index, put_abi(found)));
        return found;
    }

    template <typename D, typename T>
    void impl_IVector<D, T>::SetAt(const uint32_t index, const T & value) const
    {
        check_hresult((*(abi<IVector<T>> **)&static_cast<const IVector<T> &>(static_cast<const D &>(*this)))->abi_SetAt(index, get_abi(value)));
    }

    template <typename D, typename T>
    void impl_IVector<D, T>::InsertAt(const uint32_t index, const T & value) const
    {
        check_hresult((*(abi<IVector<T>> **)&static_cast<const IVector<T> &>(static_cast<const D &>(*this)))->abi_InsertAt(index, get_abi(value)));
    }

    template <typename D, typename T>
    void impl_IVector<D, T>::RemoveAt(const uint32_t index) const
    {
        check_hresult((*(abi<IVector<T>> **)&static_cast<const IVector<T> &>(static_cast<const D &>(*this)))->abi_RemoveAt(index));
    }

    template <typename D, typename T>
    void impl_IVector<D, T>::Append(const T & value) const
    {
        check_hresult((*(abi<IVector<T>> **)&static_cast<const IVector<T> &>(static_cast<const D &>(*this)))->abi_Append(get_abi(value)));
    }

    template <typename D, typename T>
    void impl_IVector<D, T>::RemoveAtEnd() const
    {
        check_hresult((*(abi<IVector<T>> **)&static_cast<const IVector<T> &>(static_cast<const D &>(*this)))->abi_RemoveAtEnd());
    }

    template <typename D, typename T>
    void impl_IVector<D, T>::Clear() const
    {
        check_hresult((*(abi<IVector<T>> **)&static_cast<const IVector<T> &>(static_cast<const D &>(*this)))->abi_Clear());
    }

    template <typename D, typename T>
    uint32_t impl_IVector<D, T>::GetMany(uint32_t startIndex, array_view<T> values) const
    {
        uint32_t actual = 0;
        check_hresult((*(abi<IVector<T>> **)&static_cast<const IVector<T> &>(static_cast<const D &>(*this)))->abi_GetMany(startIndex, values.size(), get_abi(values), &actual));
        return actual;
    }

    template <typename D, typename T>
    void impl_IVector<D, T>::ReplaceAll(array_view<const T> value) const
    {
        check_hresult((*(abi<IVector<T>> **)&static_cast<const IVector<T> &>(static_cast<const D &>(*this)))->abi_ReplaceAll(value.size(), get_abi(value)));
    }

    template <typename D, typename K, typename V>
    V impl_IMapView<D, K, V>::Lookup(const K & key) const
    {
        V result = impl::empty_value<V>();
        check_hresult((*(abi<IMapView<K, V>> **)&static_cast<const IMapView<K, V> &>(static_cast<const D &>(*this)))->abi_Lookup(get_abi(key), put_abi(result)));
        return result;
    }

    template <typename D, typename K, typename V>
    uint32_t impl_IMapView<D, K, V>::Size() const
    {
        uint32_t size = 0;
        check_hresult((*(abi<IMapView<K, V>> **)&static_cast<const IMapView<K, V> &>(static_cast<const D &>(*this)))->get_Size(&size));
        return size;
    }

    template <typename D, typename K, typename V>
    bool impl_IMapView<D, K, V>::HasKey(const K & key) const
    {
        bool found = false;
        check_hresult((*(abi<IMapView<K, V>> **)&static_cast<const IMapView<K, V> &>(static_cast<const D &>(*this)))->abi_HasKey(get_abi(key), put_abi(found)));
        return found;
    }

    template <typename D, typename K, typename V>
    void impl_IMapView<D, K, V>::Split(IMapView<K, V> & firstPartition, IMapView<K, V> & secondPartition)
    {
        check_hresult((*(abi<IMapView<K, V>> **)&static_cast<const IMapView<K, V> &>(static_cast<const D &>(*this)))->abi_Split(put_abi(firstPartition), put_abi(secondPartition)));
    }

    template <typename D, typename K, typename V>
    V impl_IMap<D, K, V>::Lookup(const K & key) const
    {
        V result = impl::empty_value<V>();
        check_hresult((*(abi<IMap<K, V>> **)&static_cast<const IMap<K, V> &>(static_cast<const D &>(*this)))->abi_Lookup(get_abi(key), put_abi(result)));
        return result;
    }

    template <typename D, typename K, typename V>
    uint32_t impl_IMap<D, K, V>::Size() const
    {
        uint32_t size = 0;
        check_hresult((*(abi<IMap<K, V>> **)&static_cast<const IMap<K, V> &>(static_cast<const D &>(*this)))->get_Size(&size));
        return size;
    }

    template <typename D, typename K, typename V>
    bool impl_IMap<D, K, V>::HasKey(const K & key) const
    {
        bool found = false;
        check_hresult((*(abi<IMap<K, V>> **)&static_cast<const IMap<K, V> &>(static_cast<const D &>(*this)))->abi_HasKey(get_abi(key), put_abi(found)));
        return found;
    }

    template <typename D, typename K, typename V>
    IMapView<K, V> impl_IMap<D, K, V>::GetView() const
    {
        IMapView<K, V> view;
        check_hresult((*(abi<IMap<K, V>> **)&static_cast<const IMap<K, V> &>(static_cast<const D &>(*this)))->abi_GetView(put_abi(view)));
        return view;
    }

    template <typename D, typename K, typename V>
    bool impl_IMap<D, K, V>::Insert(const K & key, const V & value) const
    {
        bool replaced = false;
        check_hresult((*(abi<IMap<K, V>> **)&static_cast<const IMap<K, V> &>(static_cast<const D &>(*this)))->abi_Insert(get_abi(key), get_abi(value), put_abi(replaced)));
        return replaced;
    }

    template <typename D, typename K, typename V>
    void impl_IMap<D, K, V>::Remove(const K & key) const
    {
        check_hresult((*(abi<IMap<K, V>> **)&static_cast<const IMap<K, V> &>(static_cast<const D &>(*this)))->abi_Remove(get_abi(key)));
    }

    template <typename D, typename K, typename V>
    void impl_IMap<D, K, V>::Clear() const
    {
        check_hresult((*(abi<IMap<K, V>> **)&static_cast<const IMap<K, V> &>(static_cast<const D &>(*this)))->abi_Clear());
    }

    template <typename D, typename K>
    CollectionChange impl_IMapChangedEventArgs<D, K>::CollectionChange() const
    {
        Collections::CollectionChange value{};
        check_hresult((*(abi<IMapChangedEventArgs<K>> **)&static_cast<const IMapChangedEventArgs<K> &>(static_cast<const D &>(*this)))->get_CollectionChange(&value));
        return value;
    }

    template <typename D, typename K>
    K impl_IMapChangedEventArgs<D, K>::Key() const
    {
        K result = impl::empty_value<K>();
        check_hresult((*(abi<IMapChangedEventArgs<K>> **)&static_cast<const IMapChangedEventArgs<K> &>(static_cast<const D &>(*this)))->get_Key(put_abi(result)));
        return result;
    }

    template <typename D, typename K, typename V>
    event_token impl_IObservableMap<D, K, V>::MapChanged(const MapChangedEventHandler<K, V> & handler) const
    {
        event_token cookie{};
        check_hresult((*(abi<IObservableMap<K, V>> **)&static_cast<const IObservableMap<K, V> &>(static_cast<const D &>(*this)))->add_MapChanged(get_abi(handler), &cookie));
        return cookie;
    }

    template <typename D, typename K, typename V>
    void impl_IObservableMap<D, K, V>::MapChanged(const event_token cookie) const
    {
        check_hresult((*(abi<IObservableMap<K, V>> **)&static_cast<const IObservableMap<K, V> &>(static_cast<const D &>(*this)))->remove_MapChanged(cookie));
    }

    template <typename D, typename T>
    event_token impl_IObservableVector<D, T>::VectorChanged(const VectorChangedEventHandler<T> & handler) const
    {
        event_token cookie{};
        check_hresult((*(abi<IObservableVector<T>> **)&static_cast<const IObservableVector<T> &>(static_cast<const D &>(*this)))->add_VectorChanged(get_abi(handler), &cookie));
        return cookie;
    }

    template <typename D, typename T>
    void impl_IObservableVector<D, T>::VectorChanged(const event_token cookie) const
    {
        check_hresult((*(abi<IObservableVector<T>> **)&static_cast<const IObservableVector<T> &>(static_cast<const D &>(*this)))->remove_VectorChanged(cookie));
    }
}

namespace impl
{
    template <typename K, typename V, typename H>
    struct map_changed_event_handler : implements<map_changed_event_handler<K, V, H>, abi<Windows::Foundation::Collections::MapChangedEventHandler<K, V>>>, H
    {
        map_changed_event_handler(H && handler) : H(std::forward<H>(handler)) {}

        HRESULT __stdcall abi_Invoke(abi_arg_in<Windows::Foundation::Collections::IObservableMap<K, V>> sender, abi_arg_in<Windows::Foundation::Collections::IMapChangedEventArgs<K>> args) noexcept override
        {
            try
            {
                (*this)(*reinterpret_cast<const Windows::Foundation::Collections::IObservableMap<K, V> *>(&sender), *reinterpret_cast<const Windows::Foundation::Collections::IMapChangedEventArgs<K> *>(&args));
                return S_OK;
            }
            catch (...) { return impl::to_hresult(); }
        }
    };

    template <typename T, typename H>
    struct vector_changed_event_handler : implements<vector_changed_event_handler<T, H>, abi<Windows::Foundation::Collections::VectorChangedEventHandler<T>>>, H
    {
        vector_changed_event_handler(H && handler) : H(std::forward<H>(handler)) {}

        HRESULT __stdcall abi_Invoke(abi_arg_in<Windows::Foundation::Collections::IObservableVector<T>> sender, abi_arg_in<Windows::Foundation::Collections::IVectorChangedEventArgs> args) noexcept override
        {
            try
            {
                (*this)(*reinterpret_cast<const Windows::Foundation::Collections::IObservableVector<T> *>(&sender), *reinterpret_cast<const Windows::Foundation::Collections::IVectorChangedEventArgs *>(&args));
                return S_OK;
            }
            catch (...) { return impl::to_hresult(); }
        }
    };
}

namespace Windows::Foundation::Collections
{
    template <typename K, typename V> template <typename L> MapChangedEventHandler<K, V>::MapChangedEventHandler(L handler) :
        MapChangedEventHandler(impl::make_delegate<impl::map_changed_event_handler<K, V, L>, MapChangedEventHandler<K, V>>(std::forward<L>(handler)))
    {}

    template <typename K, typename V> template <typename F> MapChangedEventHandler<K, V>::MapChangedEventHandler(F * handler) :
        MapChangedEventHandler([=](auto && ... args) { handler(args ...); })
    {}

    template <typename K, typename V> template <typename O, typename M> MapChangedEventHandler<K, V>::MapChangedEventHandler(O * object, M method) :
        MapChangedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
    {}

    template <typename K, typename V> void MapChangedEventHandler<K, V>::operator()(const IObservableMap<K, V> & sender, const IMapChangedEventArgs<K> & args) const
    {
        check_hresult((*(abi<MapChangedEventHandler<K, V>> **)this)->abi_Invoke(get_abi(sender), get_abi(args)));
    }

    template <typename T> template <typename L> VectorChangedEventHandler<T>::VectorChangedEventHandler(L handler) :
        VectorChangedEventHandler(impl::make_delegate<impl::vector_changed_event_handler<T, L>, VectorChangedEventHandler<T>>(std::forward<L>(handler)))
    {}

    template <typename T> template <typename F> VectorChangedEventHandler<T>::VectorChangedEventHandler(F * handler) :
        VectorChangedEventHandler([=](auto && ... args) { handler(args ...); })
    {}

    template <typename T> template <typename O, typename M> VectorChangedEventHandler<T>::VectorChangedEventHandler(O * object, M method) :
        VectorChangedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
    {}

    template <typename T> void VectorChangedEventHandler<T>::operator()(const IObservableVector<T> & sender, const IVectorChangedEventArgs & args) const
    {
        check_hresult((*(abi<VectorChangedEventHandler<T>> **)this)->abi_Invoke(get_abi(sender), get_abi(args)));
    }

    template <typename T, std::enable_if_t<!impl::has_GetAt<T>::value> * = nullptr>
    auto begin(const T & collection) -> decltype(collection.First())
    {
        auto result = collection.First();

        if (!result.HasCurrent())
        {
            return {};
        }

        return result;
    }

    template <typename T, std::enable_if_t<!impl::has_GetAt<T>::value> * = nullptr>
    auto end(const T & collection) -> decltype(collection.First())
    {
        collection;
        return {};
    }

    template <typename T, std::enable_if_t<impl::has_GetAt<T>::value> * = nullptr>
    impl::fast_iterator<T> begin(const T & collection) noexcept
    {
        return impl::fast_iterator<T>(collection, 0);
    }

    template <typename T, std::enable_if_t<impl::has_GetAt<T>::value> * = nullptr>
    impl::fast_iterator<T> end(const T & collection)
    {
        return impl::fast_iterator<T>(collection, collection.Size());
    }
}

namespace impl
{
    template <typename D>
    struct produce<D, Windows::Foundation::Collections::IVectorChangedEventArgs> : produce_base<D, Windows::Foundation::Collections::IVectorChangedEventArgs>
    {
        HRESULT __stdcall get_CollectionChange(Windows::Foundation::Collections::CollectionChange * value) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = this->shim().CollectionChange();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Index(uint32_t * value) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = this->shim().Index();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }
    };

    template <typename D, typename T>
    struct produce<D, Windows::Foundation::Collections::IIterator<T>> : produce_base<D, Windows::Foundation::Collections::IIterator<T>>
    {
        HRESULT __stdcall get_Current(abi_arg_out<T> current) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *current = detach_abi(this->shim().Current());
                return S_OK;
            }
            catch (...)
            {
                clear_abi(current);
                return to_hresult();
            }
        }

        HRESULT __stdcall get_HasCurrent(bool * hasCurrent) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *hasCurrent = this->shim().HasCurrent();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_MoveNext(bool * hasCurrent) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *hasCurrent = this->shim().MoveNext();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_GetMany(uint32_t capacity, abi_arg_out<T> value, uint32_t * actual) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *actual = this->shim().GetMany({ reinterpret_cast<T *>(value), reinterpret_cast<T *>(value) + capacity });
                return S_OK;
            }
            catch (...)
            {
                clear_abi(value);
                *actual = 0;
                return to_hresult();
            }
        }
    };

    template <typename D, typename T>
    struct produce<D, Windows::Foundation::Collections::IIterable<T>> : produce_base<D, Windows::Foundation::Collections::IIterable<T>>
    {
        HRESULT __stdcall abi_First(abi_arg_out<Windows::Foundation::Collections::IIterator<T>> first) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *first = detach_abi(this->shim().First());
                return S_OK;
            }
            catch (...)
            {
                *first = nullptr;
                return to_hresult();
            }
        }
    };

    template <typename D, typename K, typename V>
    struct produce<D, Windows::Foundation::Collections::IKeyValuePair<K, V>> : produce_base<D, Windows::Foundation::Collections::IKeyValuePair<K, V>>
    {
        HRESULT __stdcall get_Key(abi_arg_out<K> key) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *key = detach_abi(this->shim().Key());
                return S_OK;
            }
            catch (...)
            {
                clear_abi(key);
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Value(abi_arg_out<V> value) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().Value());
                return S_OK;
            }
            catch (...)
            {
                clear_abi(value);
                return to_hresult();
            }
        }
    };

    template <typename D, typename T>
    struct produce<D, Windows::Foundation::Collections::IVectorView<T>> : produce_base<D, Windows::Foundation::Collections::IVectorView<T>>
    {
        HRESULT __stdcall abi_GetAt(uint32_t index, abi_arg_out<T> item) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *item = detach_abi(this->shim().GetAt(index));
                return S_OK;
            }
            catch (...)
            {
                clear_abi(item);
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Size(uint32_t * size) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *size = this->shim().Size();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_IndexOf(abi_arg_in<T> value, uint32_t * index, bool * found) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *found = this->shim().IndexOf(*reinterpret_cast<const T *>(&value), *index);
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_GetMany(uint32_t startIndex, uint32_t capacity, abi_arg_out<T> value, uint32_t * actual) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *actual = this->shim().GetMany(startIndex, { reinterpret_cast<T *>(value), reinterpret_cast<T *>(value) + capacity });
                return S_OK;
            }
            catch (...)
            {
                clear_abi(value);
                *actual = 0;
                return to_hresult();
            }
        }
    };

    template <typename D, typename T>
    struct produce<D, Windows::Foundation::Collections::IVector<T>> : produce_base<D, Windows::Foundation::Collections::IVector<T>>
    {
        HRESULT __stdcall abi_GetAt(uint32_t index, abi_arg_out<T> item) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *item = detach_abi(this->shim().GetAt(index));
                return S_OK;
            }
            catch (...)
            {
                clear_abi(item);
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Size(uint32_t * size) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *size = this->shim().Size();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_GetView(abi_arg_out<Windows::Foundation::Collections::IVectorView<T>> view) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *view = detach_abi(this->shim().GetView());
                return S_OK;
            }
            catch (...)
            {
                *view = nullptr;
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_IndexOf(abi_arg_in<T> value, uint32_t * index, bool * found) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *found = this->shim().IndexOf(*reinterpret_cast<const T *>(&value), *index);
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_SetAt(uint32_t index, abi_arg_in<T> item) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().SetAt(index, *reinterpret_cast<const T *>(&item));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_InsertAt(uint32_t index, abi_arg_in<T> item) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().InsertAt(index, *reinterpret_cast<const T *>(&item));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_RemoveAt(uint32_t index) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().RemoveAt(index);
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_Append(abi_arg_in<T> item) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Append(*reinterpret_cast<const T *>(&item));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_RemoveAtEnd() noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().RemoveAtEnd();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_Clear() noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Clear();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_GetMany(uint32_t startIndex, uint32_t capacity, abi_arg_out<T> value, uint32_t * actual) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *actual = this->shim().GetMany(startIndex, { reinterpret_cast<T *>(value), reinterpret_cast<T *>(value) + capacity });
                return S_OK;
            }
            catch (...)
            {
                clear_abi(value);
                *actual = 0;
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_ReplaceAll(uint32_t count, abi_arg_out<T> item) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().ReplaceAll({ reinterpret_cast<T const *>(item), reinterpret_cast<T const *>(item) + count });
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }
    };

    template <typename D, typename K, typename V>
    struct produce<D, Windows::Foundation::Collections::IMapView<K, V>> : produce_base<D, Windows::Foundation::Collections::IMapView<K, V>>
    {
        HRESULT __stdcall abi_Lookup(abi_arg_in<K> key, abi_arg_out<V> value) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().Lookup(*reinterpret_cast<const K *>(&key)));
                return S_OK;
            }
            catch (...)
            {
                clear_abi(value);
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Size(uint32_t * size) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *size = this->shim().Size();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_HasKey(abi_arg_in<K> key, bool * found) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *found = this->shim().HasKey(*reinterpret_cast<const K *>(&key));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_Split(abi_arg_out<Windows::Foundation::Collections::IMapView<K, V>> firstPartition, abi_arg_out<Windows::Foundation::Collections::IMapView<K, V>> secondPartition) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Split(*reinterpret_cast<Windows::Foundation::Collections::IMapView<K, V> *>(firstPartition), *reinterpret_cast<Windows::Foundation::Collections::IMapView<K, V> *>(secondPartition));
                return S_OK;
            }
            catch (...)
            {
                *firstPartition = nullptr;
                *secondPartition = nullptr;
                return to_hresult();
            }
        }
    };

    template <typename D, typename K, typename V>
    struct produce<D, Windows::Foundation::Collections::IMap<K, V>> : produce_base<D, Windows::Foundation::Collections::IMap<K, V>>
    {
        HRESULT __stdcall abi_Lookup(abi_arg_in<K> key, abi_arg_out<V> value) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().Lookup(*reinterpret_cast<const K *>(&key)));
                return S_OK;
            }
            catch (...)
            {
                clear_abi(value);
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Size(uint32_t * size) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *size = this->shim().Size();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_HasKey(abi_arg_in<K> key, bool * found) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *found = this->shim().HasKey(*reinterpret_cast<const K *>(&key));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_GetView(abi_arg_out<Windows::Foundation::Collections::IMapView<K, V>> view) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *view = detach_abi(this->shim().GetView());
                return S_OK;
            }
            catch (...)
            {
                *view = nullptr;
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_Insert(abi_arg_in<K> key, abi_arg_in<V> value, bool * replaced) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *replaced = this->shim().Insert(*reinterpret_cast<const K *>(&key), *reinterpret_cast<const V *>(&value));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_Remove(abi_arg_in<K> key) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Remove(*reinterpret_cast<const K *>(&key));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_Clear() noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Clear();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }
    };

    template <typename D, typename K>
    struct produce<D, Windows::Foundation::Collections::IMapChangedEventArgs<K>> : produce_base<D, Windows::Foundation::Collections::IMapChangedEventArgs<K>>
    {
        HRESULT __stdcall get_CollectionChange(winrt::Windows::Foundation::Collections::CollectionChange * value) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = this->shim().CollectionChange();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Key(abi_arg_out<K> value) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().Key());
                return S_OK;
            }
            catch (...)
            {
                clear_abi(value);
                return to_hresult();
            }
        }
    };

    template <typename D, typename K, typename V>
    struct produce<D, Windows::Foundation::Collections::IObservableMap<K, V>> : produce_base<D, Windows::Foundation::Collections::IObservableMap<K, V>>
    {
        HRESULT __stdcall add_MapChanged(abi_arg_in<Windows::Foundation::Collections::MapChangedEventHandler<K, V>> handler, event_token * token) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *token = this->shim().MapChanged(*reinterpret_cast<const Windows::Foundation::Collections::MapChangedEventHandler<K, V> *>(&handler));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall remove_MapChanged(event_token token) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().MapChanged(token);
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }
    };

    template <typename D, typename T>
    struct produce<D, Windows::Foundation::Collections::IObservableVector<T>> : produce_base<D, Windows::Foundation::Collections::IObservableVector<T>>
    {
        HRESULT __stdcall add_VectorChanged(abi_arg_in<Windows::Foundation::Collections::VectorChangedEventHandler<T>> handler, event_token * token) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *token = this->shim().VectorChanged(*reinterpret_cast<const Windows::Foundation::Collections::VectorChangedEventHandler<T> *>(&handler));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall remove_VectorChanged(event_token token) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().VectorChanged(token);
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }
    };
}

namespace impl
{
    namespace wfc = Windows::Foundation::Collections;

    template <typename K, typename V>
    struct key_value_pair : implements<key_value_pair<K, V>, wfc::IKeyValuePair<K, V>>
    {
        explicit key_value_pair(std::pair<const K, V> const & value) : m_value(value)
        {}

        K Key() const
        {
            return m_value.first;
        }

        V Value() const
        {
            return m_value.second;
        }

    private:

        std::pair<const K, V> const m_value;
    };

    template <typename T>
    struct collection_traits
    {
        static T copy(T const & value)
        {
            return value;
        }

        template<typename InputIt, typename Size, typename OutputIt>
        static auto copy_n(InputIt first, Size count, OutputIt result)
        {
            return std::copy_n(first, count, result);
        }
    };

    template <typename K, typename V>
    struct collection_traits<wfc::IKeyValuePair<K, V>>
    {
        static auto copy(std::pair<const K, V> const & value)
        {
            return make<key_value_pair<K, V>>(value);
        }

        template<typename InputIt, typename Size, typename OutputIt>
        static auto copy_n(InputIt first, Size count, OutputIt result)
        {
            return std::transform(first, std::next(first, count), result, [](std::pair<const K, V> const & value)
            {
                return make<key_value_pair<K, V>>(value);
            });
        }
    };

    struct input_scope
    {
        void invalidate_scope() noexcept
        {
            m_invalid = true;
        }

        void check_scope() const
        {
            if (m_invalid)
            {
                throw hresult_illegal_method_call();
            }
        }

    private:

        bool m_invalid{};
    };
}

namespace impl
{
    template <typename T, typename Container>
    struct input_iterable : implements<input_iterable<T, Container>, non_agile, no_weak_ref, wfc::IIterable<T>>
    {
        static_assert(std::is_same_v<Container, std::remove_reference_t<Container>>, "Must be constructed with rvalue.");

        explicit input_iterable(Container && values) : m_values(std::forward<Container>(values))
        {
        }

        wfc::IIterator<T> First()
        {
            return make<iterator>(this);
        }

    private:

        Container const m_values;

        struct iterator : implements<iterator, non_agile, no_weak_ref, wfc::IIterator<T>>
        {
            explicit iterator(input_iterable<T, Container> * owner) noexcept :
            m_current(owner->m_values.begin()),
                m_end(owner->m_values.end())
            {
                m_owner.copy_from(owner);
            }

            T Current() const
            {
                if (m_current == m_end)
                {
                    throw hresult_out_of_bounds();
                }

                return collection_traits<T>::copy(*m_current);
            }

            bool HasCurrent() const noexcept
            {
                return m_current != m_end;
            }

            bool MoveNext() noexcept
            {
                if (m_current != m_end)
                {
                    ++m_current;
                }

                return HasCurrent();
            }

            uint32_t GetMany(array_view<T> values)
            {
                uint32_t actual = static_cast<uint32_t>(std::distance(m_current, m_end));

                if (actual > values.size())
                {
                    actual = values.size();
                }

                collection_traits<T>::copy_n(m_current, actual, values.begin());
                std::advance(m_current, actual);
                return actual;
            }

        private:

            com_ptr<input_iterable<T, Container>> m_owner;
            typename Container::const_iterator m_current;
            typename Container::const_iterator const m_end;
        };
    };

    template <typename T, typename InputIt>
    struct scoped_input_iterable : input_scope, implements<scoped_input_iterable<T, InputIt>, non_agile, no_weak_ref, wfc::IIterable<T>>
    {
        void abi_enter() const
        {
            check_scope();
        }

        scoped_input_iterable(InputIt first, InputIt last) : m_begin(first), m_end(last)
        {
        }

        wfc::IIterator<T> First()
        {
            return make<iterator>(this);
        }

    private:

        InputIt const m_begin;
        InputIt const m_end;

        struct iterator : implements<iterator, non_agile, no_weak_ref, wfc::IIterator<T>>
        {
            void abi_enter() const
            {
                m_owner->check_scope();
            }

            explicit iterator(scoped_input_iterable<T, InputIt> * owner) noexcept :
            m_current(owner->m_begin),
                m_end(owner->m_end)
            {
                m_owner.copy_from(owner);
            }

            T Current() const
            {
                if (m_current == m_end)
                {
                    throw hresult_out_of_bounds();
                }

                return collection_traits<T>::copy(*m_current);
            }

            bool HasCurrent() const noexcept
            {
                return m_current != m_end;
            }

            bool MoveNext() noexcept
            {
                if (m_current != m_end)
                {
                    ++m_current;
                }

                return HasCurrent();
            }

            uint32_t GetMany(array_view<T> values)
            {
                uint32_t actual = static_cast<uint32_t>(std::distance(m_current, m_end));

                if (actual > values.size())
                {
                    actual = values.size();
                }

                collection_traits<T>::copy_n(m_current, actual, values.begin());
                std::advance(m_current, actual);
                return actual;
            }

        private:

            com_ptr<scoped_input_iterable<T, InputIt>> m_owner;
            InputIt m_current;
            InputIt const m_end;
        };
    };

    template <typename T, typename Container>
    auto make_input_iterable(Container && values)
    {
        return make<input_iterable<T, Container>>(std::forward<Container>(values));
    }

    template <typename T, typename InputIt>
    auto make_scoped_input_iterable(InputIt first, InputIt last)
    {
        using interface_type = wfc::IIterable<T>;
        std::pair<interface_type, input_scope *> result;
        auto ptr = new scoped_input_iterable<T, InputIt>(first, last);
        *put_abi(result.first) = to_abi<interface_type>(ptr);
        result.second = ptr;
        return result;
    }
}

template <typename T>
struct iterable
{
    using value_type = T;
    using interface_type = Windows::Foundation::Collections::IIterable<value_type>;

    iterable(std::nullptr_t) noexcept
    {
    }

    iterable(iterable const & values) noexcept : m_owned(false)
    {
        attach_abi(m_pair.first, get_abi(values));
    }

    iterable(interface_type const & values) noexcept : m_owned(false)
    {
        attach_abi(m_pair.first, get_abi(values));
    }

    template <typename Collection, std::enable_if_t<std::is_convertible_v<Collection, interface_type>> * = nullptr>
    iterable(Collection const & values) noexcept : m_owned(true)
    {
        m_pair.first = values;
    }

    template <typename Allocator>
    iterable(std::vector<value_type, Allocator> && values) : m_pair(impl::make_input_iterable<value_type>(std::move(values)), nullptr)
    {
    }

    template <typename Allocator>
    iterable(std::vector<value_type, Allocator> const & values) : m_pair(impl::make_scoped_input_iterable<value_type>(values.begin(), values.end()))
    {
    }

    iterable(std::initializer_list<value_type> values) : m_pair(impl::make_scoped_input_iterable<value_type>(values.begin(), values.end()))
    {
    }

    template<class InputIt>
    iterable(InputIt first, InputIt last) : m_pair(impl::make_scoped_input_iterable<value_type>(first, last))
    {
    }

    ~iterable() noexcept
    {
        if (m_pair.second)
        {
            m_pair.second->invalidate_scope();
        }

        if (!m_owned)
        {
            detach_abi(m_pair.first);
        }
    }

private:

    std::pair<interface_type, impl::input_scope *> m_pair;
    bool m_owned{ true };
};

template <typename K, typename V>
struct iterable<Windows::Foundation::Collections::IKeyValuePair<K, V>>
{
    using value_type = Windows::Foundation::Collections::IKeyValuePair<K, V>;
    using interface_type = Windows::Foundation::Collections::IIterable<value_type>;

    iterable(std::nullptr_t) noexcept
    {
    }

    iterable(iterable const & values) noexcept : m_owned(false)
    {
        attach_abi(m_pair.first, get_abi(values));
    }

    iterable(interface_type const & values) noexcept : m_owned(false)
    {
        attach_abi(m_pair.first, get_abi(values));
    }

    template <typename Collection, std::enable_if_t<std::is_convertible_v<Collection, interface_type>> * = nullptr>
    iterable(Collection const & values) noexcept : m_owned(true)
    {
        m_pair.first = values;
    }

    template <typename Compare, typename Allocator>
    iterable(std::map<K, V, Compare, Allocator> && values) : m_pair(impl::make_input_iterable<value_type>(std::move(values)), nullptr)
    {
    }

    template <typename Compare, typename Allocator>
    iterable(std::map<K, V, Compare, Allocator> const & values) : m_pair(impl::make_scoped_input_iterable<value_type>(values.begin(), values.end()))
    {
    }

    template <typename Hash, typename KeyEqual, typename Allocator>
    iterable(std::unordered_map<K, V, Hash, KeyEqual, Allocator> && values) : m_pair(impl::make_input_iterable<value_type>(std::move(values)), nullptr)
    {
    }

    template <typename Hash, typename KeyEqual, typename Allocator>
    iterable(std::unordered_map<K, V, Hash, KeyEqual, Allocator> const & values) : m_pair(impl::make_scoped_input_iterable<value_type>(values.begin(), values.end()))
    {
    }

    iterable(std::initializer_list<std::pair<K const, V>> values) : m_pair(impl::make_scoped_input_iterable<value_type>(values.begin(), values.end()))
    {
    }

    template<class InputIt>
    iterable(InputIt first, InputIt last) : m_pair(impl::make_scoped_input_iterable<value_type>(first, last))
    {
    }

    ~iterable() noexcept
    {
        if (m_pair.second)
        {
            m_pair.second->invalidate_scope();
        }

        if (!m_owned)
        {
            detach_abi(m_pair.first);
        }
    }

private:

    std::pair<interface_type, impl::input_scope *> m_pair;
    bool m_owned{ true };
};

template <typename T>
auto get_abi(const iterable<T> & object) noexcept
{
    return *reinterpret_cast<abi<Windows::Foundation::Collections::IIterable<T>> **>(&const_cast<iterable<T> &>(object));
}

namespace impl
{
    template <typename T, typename Container>
    struct input_vector_view : implements<input_vector_view<T, Container>, non_agile, no_weak_ref, wfc::IVectorView<T>, wfc::IIterable<T>>
    {
        static_assert(std::is_same_v<Container, std::remove_reference_t<Container>>, "Must be constructed with rvalue.");

        explicit input_vector_view(Container && values) : m_values(std::forward<Container>(values))
        {
        }

        T GetAt(const uint32_t index) const
        {
            if (index >= Size())
            {
                throw hresult_out_of_bounds();
            }

            return m_values[index];
        }

        uint32_t Size() const noexcept
        {
            return static_cast<uint32_t>(m_values.size());
        }

        bool IndexOf(const T & value, uint32_t & index) const noexcept
        {
            index = static_cast<uint32_t>(std::find(m_values.begin(), m_values.end(), value) - m_values.begin());
            return index < m_values.size();
        }

        uint32_t GetMany(const uint32_t startIndex, array_view<T> values) const
        {
            if (startIndex >= Size())
            {
                return 0;
            }

            uint32_t actual = Size() - startIndex;

            if (actual > values.size())
            {
                actual = values.size();
            }

            std::copy_n(m_values.begin() + startIndex, actual, values.begin());
            return actual;
        }

        wfc::IIterator<T> First()
        {
            return make<iterator>(this);
        }

    private:

        Container const m_values;

        struct iterator : implements<iterator, non_agile, no_weak_ref, wfc::IIterator<T>>
        {
            explicit iterator(input_vector_view<T, Container> * owner) noexcept :
            m_current(owner->m_values.begin()),
                m_end(owner->m_values.end())
            {
                m_owner.copy_from(owner);
            }

            T Current() const
            {
                if (m_current == m_end)
                {
                    throw hresult_out_of_bounds();
                }

                return *m_current;
            }

            bool HasCurrent() const noexcept
            {
                return m_current != m_end;
            }

            bool MoveNext() noexcept
            {
                if (m_current != m_end)
                {
                    ++m_current;
                }

                return HasCurrent();
            }

            uint32_t GetMany(array_view<T> values)
            {
                uint32_t actual = static_cast<uint32_t>(std::distance(m_current, m_end));

                if (actual > values.size())
                {
                    actual = values.size();
                }

                std::copy_n(m_current, actual, values.begin());
                std::advance(m_current, actual);
                return actual;
            }

        private:

            com_ptr<input_vector_view<T, Container>> m_owner;
            typename Container::const_iterator m_current;
            typename Container::const_iterator const m_end;
        };
    };

    template <typename T, typename InputIt>
    struct scoped_input_vector_view : input_scope, implements<scoped_input_vector_view<T, InputIt>, non_agile, no_weak_ref, wfc::IVectorView<T>, wfc::IIterable<T>>
    {
        void abi_enter() const
        {
            check_scope();
        }

        scoped_input_vector_view(InputIt first, InputIt last) : m_begin(first), m_end(last)
        {
        }

        T GetAt(const uint32_t index) const
        {
            if (index >= Size())
            {
                throw hresult_out_of_bounds();
            }

            return *std::next(m_begin, index);
        }

        uint32_t Size() const noexcept
        {
            return static_cast<uint32_t>(std::distance(m_begin, m_end));
        }

        bool IndexOf(const T & value, uint32_t & index) const noexcept
        {
            index = static_cast<uint32_t>(std::find(m_begin, m_end, value) - m_begin);
            return index < Size();
        }

        uint32_t GetMany(const uint32_t startIndex, array_view<T> values) const
        {
            if (startIndex >= Size())
            {
                return 0;
            }

            uint32_t actual = Size() - startIndex;

            if (actual > values.size())
            {
                actual = values.size();
            }

            std::copy_n(m_begin + startIndex, actual, values.begin());
            return actual;
        }

        wfc::IIterator<T> First()
        {
            return make<iterator>(this);
        }

    private:

        InputIt const m_begin;
        InputIt const m_end;

        struct iterator : implements<iterator, non_agile, no_weak_ref, wfc::IIterator<T>>
        {
            void abi_enter() const
            {
                m_owner->check_scope();
            }

            explicit iterator(scoped_input_vector_view<T, InputIt> * owner) noexcept :
            m_current(owner->m_begin),
                m_end(owner->m_end)
            {
                m_owner.copy_from(owner);
            }

            T Current() const
            {
                if (m_current == m_end)
                {
                    throw hresult_out_of_bounds();
                }

                return *m_current;
            }

            bool HasCurrent() const noexcept
            {
                return m_current != m_end;
            }

            bool MoveNext() noexcept
            {
                if (m_current != m_end)
                {
                    ++m_current;
                }

                return HasCurrent();
            }

            uint32_t GetMany(array_view<T> values)
            {
                uint32_t actual = static_cast<uint32_t>(std::distance(m_current, m_end));

                if (actual > values.size())
                {
                    actual = values.size();
                }

                std::copy_n(m_current, actual, values.begin());
                std::advance(m_current, actual);
                return actual;
            }

        private:

            com_ptr<scoped_input_vector_view<T, InputIt>> m_owner;
            InputIt m_current;
            InputIt const m_end;
        };
    };

    template <typename T, typename InputIt>
    auto make_scoped_input_vector_view(InputIt first, InputIt last)
    {
        using interface_type = wfc::IVectorView<T>;
        std::pair<interface_type, input_scope *> result;
        auto ptr = new scoped_input_vector_view<T, InputIt>(first, last);
        *put_abi(result.first) = to_abi<interface_type>(ptr);
        result.second = ptr;
        return result;
    }
}

template <typename T>
struct vector_view
{
    using value_type = T;
    using interface_type = Windows::Foundation::Collections::IVectorView<value_type>;

    vector_view(std::nullptr_t) noexcept
    {
    }

    vector_view(vector_view const & values) noexcept : m_owned(false)
    {
        attach_abi(m_pair.first, get_abi(values));
    }

    vector_view(interface_type const & values) noexcept : m_owned(false)
    {
        attach_abi(m_pair.first, get_abi(values));
    }

    template <typename Collection, std::enable_if_t<std::is_convertible_v<Collection, interface_type>> * = nullptr>
    vector_view(Collection const & values) noexcept : m_owned(true)
    {
        m_pair.first = values;
    }

    template <typename Allocator>
    vector_view(std::vector<value_type, Allocator> && values) : m_pair(make<impl::input_vector_view<value_type, std::vector<value_type, Allocator>>>(std::move(values)), nullptr)
    {
    }

    template <typename Allocator>
    vector_view(std::vector<value_type, Allocator> const & values) : m_pair(impl::make_scoped_input_vector_view<value_type>(values.begin(), values.end()))
    {
    }

    vector_view(std::initializer_list<value_type> values) : m_pair(impl::make_scoped_input_vector_view<value_type>(values.begin(), values.end()))
    {
    }

    template<class InputIt>
    vector_view(InputIt first, InputIt last) : m_pair(impl::make_scoped_input_vector_view<value_type>(first, last))
    {
    }

    ~vector_view() noexcept
    {
        if (m_pair.second)
        {
            m_pair.second->invalidate_scope();
        }

        if (!m_owned)
        {
            detach_abi(m_pair.first);
        }
    }

private:

    std::pair<interface_type, impl::input_scope *> m_pair;
    bool m_owned{ true };
};

template <typename T>
auto get_abi(const vector_view<T> & object) noexcept
{
    return *reinterpret_cast<abi<Windows::Foundation::Collections::IVectorView<T>> **>(&const_cast<vector_view<T> &>(object));
}

namespace impl
{
    template <typename K, typename V, typename Container>
    struct input_map_view : implements<input_map_view<K, V, Container>, non_agile, no_weak_ref, wfc::IMapView<K, V>, wfc::IIterable<wfc::IKeyValuePair<K, V>>>
    {
        static_assert(std::is_same_v<Container, std::remove_reference_t<Container>>, "Must be constructed with rvalue.");

        using value_type = wfc::IKeyValuePair<K, V>;
        using interface_type = wfc::IMapView<K, V>;

        explicit input_map_view(Container && values) : m_values(std::forward<Container>(values))
        {
        }

        V Lookup(K const & key) const
        {
            auto pair = m_values.find(key);

            if (pair == m_values.end())
            {
                throw hresult_out_of_bounds();
            }

            return pair->second;
        }

        uint32_t Size() const noexcept
        {
            return static_cast<uint32_t>(m_values.size());
        }

        bool HasKey(K const & key) const noexcept
        {
            return m_values.find(key) != m_values.end();
        }

        void Split(interface_type & first, interface_type & second) const noexcept
        {
            first = nullptr;
            second = nullptr;
        }

        wfc::IIterator<value_type> First()
        {
            return make<iterator>(this);
        }

    private:

        Container const m_values;

        struct iterator : implements<iterator, non_agile, no_weak_ref, wfc::IIterator<value_type>>
        {
            explicit iterator(input_map_view<K, V, Container> * owner) noexcept :
            m_current(owner->m_values.begin()),
                m_end(owner->m_values.end())
            {
                m_owner.copy_from(owner);
            }

            value_type Current() const
            {
                if (m_current == m_end)
                {
                    throw hresult_out_of_bounds();
                }

                return collection_traits<value_type>::copy(*m_current);
            }

            bool HasCurrent() const noexcept
            {
                return m_current != m_end;
            }

            bool MoveNext() noexcept
            {
                if (m_current != m_end)
                {
                    ++m_current;
                }

                return HasCurrent();
            }

            uint32_t GetMany(array_view<value_type> values)
            {
                uint32_t actual = static_cast<uint32_t>(std::distance(m_current, m_end));

                if (actual > values.size())
                {
                    actual = values.size();
                }

                collection_traits<value_type>::copy_n(m_current, actual, values.begin());
                std::advance(m_current, actual);
                return actual;
            }

        private:

            com_ptr<input_map_view<K, V, Container>> m_owner;
            typename Container::const_iterator m_current;
            typename Container::const_iterator const m_end;
        };
    };

    template <typename K, typename V, typename Container>
    struct scoped_input_map_view : input_scope, implements<scoped_input_map_view<K, V, Container>, non_agile, no_weak_ref, wfc::IMapView<K, V>, wfc::IIterable<wfc::IKeyValuePair<K, V>>>
    {
        using value_type = wfc::IKeyValuePair<K, V>;
        using interface_type = wfc::IMapView<K, V>;

        void abi_enter() const
        {
            check_scope();
        }

        explicit scoped_input_map_view(Container const & values) : m_values(values)
        {
        }

        V Lookup(K const & key) const
        {
            auto pair = m_values.find(key);

            if (pair == m_values.end())
            {
                throw hresult_out_of_bounds();
            }

            return pair->second;
        }

        uint32_t Size() const noexcept
        {
            return static_cast<uint32_t>(m_values.size());
        }

        bool HasKey(K const & key) const noexcept
        {
            return m_values.find(key) != m_values.end();
        }

        void Split(interface_type & first, interface_type & second) const noexcept
        {
            first = nullptr;
            second = nullptr;
        }

        wfc::IIterator<value_type> First()
        {
            return make<iterator>(this);
        }

    private:

        Container const & m_values;

        struct iterator : implements<iterator, non_agile, no_weak_ref, wfc::IIterator<value_type>>
        {
            void abi_enter() const
            {
                m_owner->check_scope();
            }

            explicit iterator(scoped_input_map_view<K, V, Container> * owner) noexcept :
            m_current(owner->m_values.begin()),
                m_end(owner->m_values.end())
            {
                m_owner.copy_from(owner);
            }

            value_type Current() const
            {
                if (m_current == m_end)
                {
                    throw hresult_out_of_bounds();
                }

                return collection_traits<value_type>::copy(*m_current);
            }

            bool HasCurrent() const noexcept
            {
                return m_current != m_end;
            }

            bool MoveNext() noexcept
            {
                if (m_current != m_end)
                {
                    ++m_current;
                }

                return HasCurrent();
            }

            uint32_t GetMany(array_view<value_type> values)
            {
                uint32_t actual = static_cast<uint32_t>(std::distance(m_current, m_end));

                if (actual > values.size())
                {
                    actual = values.size();
                }

                collection_traits<value_type>::copy_n(m_current, actual, values.begin());
                std::advance(m_current, actual);
                return actual;
            }

        private:

            com_ptr<scoped_input_map_view<K, V, Container>> m_owner;
            typename Container::const_iterator m_current;
            typename Container::const_iterator const m_end;
        };
    };

    template <typename K, typename V, typename Container>
    auto make_input_map_view(Container && values)
    {
        return make<input_map_view<K, V, Container>>(std::forward<Container>(values));
    }

    template <typename K, typename V, typename Container>
    auto make_scoped_input_map_view(Container const & values)
    {
        using interface_type = wfc::IMapView<K, V>;
        std::pair<interface_type, input_scope *> result;
        auto ptr = new scoped_input_map_view<K, V, Container>(values);
        *put_abi(result.first) = to_abi<interface_type>(ptr);
        result.second = ptr;
        return result;
    }
}

template <typename K, typename V>
struct map_view
{
    using value_type = Windows::Foundation::Collections::IKeyValuePair<K, V>;
    using interface_type = Windows::Foundation::Collections::IMapView<K, V>;

    map_view(std::nullptr_t) noexcept
    {
    }

    map_view(map_view const & values) noexcept : m_owned(false)
    {
        attach_abi(m_pair.first, get_abi(values));
    }

    map_view(interface_type const & values) noexcept : m_owned(false)
    {
        attach_abi(m_pair.first, get_abi(values));
    }

    template <typename Collection, std::enable_if_t<std::is_convertible_v<Collection, interface_type>> * = nullptr>
    map_view(Collection const & values) noexcept : m_owned(true)
    {
        m_pair.first = values;
    }

    template <typename Compare, typename Allocator>
    map_view(std::map<K, V, Compare, Allocator> && values) : m_pair(impl::make_input_map_view<K, V>(std::move(values)), nullptr)
    {
    }

    template <typename Compare, typename Allocator>
    map_view(std::map<K, V, Compare, Allocator> const & values) : m_pair(impl::make_scoped_input_map_view<K, V>(values))
    {
    }

    template <typename Hash, typename KeyEqual, typename Allocator>
    map_view(std::unordered_map<K, V, Hash, KeyEqual, Allocator> && values) : m_pair(impl::make_input_map_view<K, V>(std::move(values)), nullptr)
    {
    }

    template <typename Hash, typename KeyEqual, typename Allocator>
    map_view(std::unordered_map<K, V, Hash, KeyEqual, Allocator> const & values) : m_pair(impl::make_scoped_input_map_view<K, V>(values))
    {
    }

    map_view(std::initializer_list<std::pair<K const, V>> values) : m_pair(impl::make_input_map_view<K, V>(std::map<K, V>(values)), nullptr)
    {
    }

    ~map_view() noexcept
    {
        if (m_pair.second)
        {
            m_pair.second->invalidate_scope();
        }

        if (!m_owned)
        {
            detach_abi(m_pair.first);
        }
    }

private:

    std::pair<interface_type, impl::input_scope *> m_pair;
    bool m_owned{ true };
};

template <typename K, typename V>
auto get_abi(const map_view<K, V> & object) noexcept
{
    return *reinterpret_cast<abi<Windows::Foundation::Collections::IMapView<K, V>> **>(&const_cast<map_view<K, V> &>(object));
}

namespace impl
{
    template <typename T, typename Container>
    struct single_threaded_vector : implements<single_threaded_vector<T, Container>, wfc::IVector<T>, wfc::IVectorView<T>, wfc::IIterable<T>>
    {
        static_assert(std::is_same_v<Container, std::remove_reference_t<Container>>, "Must be constructed with rvalue.");

        explicit single_threaded_vector(Container && values) : m_values(std::forward<Container>(values))
        {
        }

        T GetAt(const uint32_t index) const
        {
            if (index >= m_values.size())
            {
                throw hresult_out_of_bounds();
            }

            return m_values[index];
        }

        uint32_t Size() const noexcept
        {
            return static_cast<uint32_t>(m_values.size());
        }

        wfc::IVectorView<T> GetView()
        {
            return *this;
        }

        bool IndexOf(const T & value, uint32_t & index) const noexcept
        {
            index = static_cast<uint32_t>(std::find(m_values.begin(), m_values.end(), value) - m_values.begin());
            return index < m_values.size();
        }

        void SetAt(const uint32_t index, const T & value)
        {
            if (index >= m_values.size())
            {
                throw hresult_out_of_bounds();
            }

            ++m_version;
            m_values[index] = value;
        }

        void InsertAt(const uint32_t index, const T & value)
        {
            if (index > m_values.size())
            {
                throw hresult_out_of_bounds();
            }

            ++m_version;
            m_values.insert(m_values.begin() + index, value);
        }

        void RemoveAt(const uint32_t index)
        {
            if (index >= m_values.size())
            {
                throw hresult_out_of_bounds();
            }

            ++m_version;
            m_values.erase(m_values.begin() + index);
        }

        void Append(T const & value)
        {
            ++m_version;
            m_values.push_back(value);
        }

        void RemoveAtEnd()
        {
            if (m_values.empty())
            {
                throw hresult_out_of_bounds();
            }

            ++m_version;
            m_values.pop_back();
        }

        void Clear() noexcept
        {
            ++m_version;
            m_values.clear();
        }

        uint32_t GetMany(uint32_t const startIndex, array_view<T> values) const
        {
            if (startIndex >= m_values.size())
            {
                return 0;
            }

            uint32_t actual = static_cast<uint32_t>(m_values.size() - startIndex);

            if (actual > values.size())
            {
                actual = values.size();
            }

            std::copy_n(m_values.begin() + startIndex, actual, values.begin());
            return actual;
        }

        void ReplaceAll(array_view<const T> value)
        {
            ++m_version;
            m_values.assign(value.begin(), value.end());
        }

        wfc::IIterator<T> First()
        {
            return make<iterator>(this);
        }

    private:

        Container m_values;
        uint32_t m_version{};

        struct iterator : implements<iterator, wfc::IIterator<T>>
        {
            explicit iterator(single_threaded_vector<T, Container> * owner) noexcept :
            m_version(owner->m_version),
                m_current(owner->m_values.begin()),
                m_end(owner->m_values.end())
            {
                m_owner.copy_from(owner);
            }

            void abi_enter() const
            {
                if (m_version != m_owner->m_version)
                {
                    throw hresult_changed_state();
                }
            }

            T Current() const
            {
                if (m_current == m_end)
                {
                    throw hresult_out_of_bounds();
                }

                return *m_current;
            }

            bool HasCurrent() const noexcept
            {
                return m_current != m_end;
            }

            bool MoveNext() noexcept
            {
                if (m_current != m_end)
                {
                    ++m_current;
                }

                return HasCurrent();
            }

            uint32_t GetMany(array_view<T> values)
            {
                uint32_t actual = static_cast<uint32_t>(std::distance(m_current, m_end));

                if (actual > values.size())
                {
                    actual = values.size();
                }

                std::copy_n(m_current, actual, values.begin());
                std::advance(m_current, actual);
                return actual;
            }

        private:

            com_ptr<single_threaded_vector<T, Container>> m_owner;
            uint32_t const m_version;
            typename Container::const_iterator m_current;
            typename Container::const_iterator const m_end;
        };
    };
}

template <typename T, typename Allocator = std::allocator<T>>
Windows::Foundation::Collections::IVector<T> single_threaded_vector(std::vector<T, Allocator> && values = {})
{
    return make<impl::single_threaded_vector<T, std::vector<T, Allocator>>>(std::move(values));
}

namespace impl
{
    template <typename K, typename V, typename Container>
    struct single_threaded_map : implements<single_threaded_map<K, V, Container>, wfc::IMap<K, V>, wfc::IMapView<K, V>, wfc::IIterable<wfc::IKeyValuePair<K, V>>>
    {
        static_assert(std::is_same_v<Container, std::remove_reference_t<Container>>, "Must be constructed with rvalue.");

        using value_type = wfc::IKeyValuePair<K, V>;

        explicit single_threaded_map(Container && values) : m_values(std::forward<Container>(values))
        {
        }

        V Lookup(K const & key) const
        {
            auto pair = m_values.find(key);

            if (pair == m_values.end())
            {
                throw hresult_out_of_bounds();
            }

            return pair->second;
        }

        uint32_t Size() const noexcept
        {
            return static_cast<uint32_t>(m_values.size());
        }

        bool HasKey(K const & key) const noexcept
        {
            return m_values.find(key) != m_values.end();
        }

        wfc::IMapView<K, V> GetView() const
        {
            return *this;
        }

        bool Insert(const K & key, const V & value)
        {
            ++m_version;
            auto pair = m_values.insert_or_assign(key, value);
            return !pair.second;

        }

        void Remove(const K & key)
        {
            ++m_version;
            m_values.erase(key);
        }

        void Clear() noexcept
        {
            ++m_version;
            m_values.clear();
        }

        void Split(wfc::IMapView<K, V> & first, wfc::IMapView<K, V> & second) const noexcept
        {
            first = nullptr;
            second = nullptr;
        }

        wfc::IIterator<value_type> First()
        {
            return make<iterator>(this);
        }

    private:

        Container m_values;
        uint32_t m_version{};

        struct iterator : implements<iterator, wfc::IIterator<value_type>>
        {
            explicit iterator(single_threaded_map<K, V, Container> * owner) noexcept :
            m_version(owner->m_version),
                m_current(owner->m_values.begin()),
                m_end(owner->m_values.end())
            {
                m_owner.copy_from(owner);
            }

            void abi_enter() const
            {
                if (m_version != m_owner->m_version)
                {
                    throw hresult_changed_state();
                }
            }

            value_type Current() const
            {
                if (m_current == m_end)
                {
                    throw hresult_out_of_bounds();
                }

                return collection_traits<value_type>::copy(*m_current);
            }

            bool HasCurrent() const noexcept
            {
                return m_current != m_end;
            }

            bool MoveNext() noexcept
            {
                if (m_current != m_end)
                {
                    ++m_current;
                }

                return HasCurrent();
            }

            uint32_t GetMany(array_view<value_type> values)
            {
                uint32_t actual = static_cast<uint32_t>(std::distance(m_current, m_end));

                if (actual > values.size())
                {
                    actual = values.size();
                }

                collection_traits<value_type>::copy_n(m_current, actual, values.begin());
                std::advance(m_current, actual);
                return actual;
            }

        private:

            com_ptr<single_threaded_map<K, V, Container>> m_owner;
            uint32_t const m_version;
            typename Container::const_iterator m_current;
            typename Container::const_iterator const m_end;
        };
    };
}

template <typename K, typename V, typename Compare = std::less<K>, typename Allocator = std::allocator<std::pair<K const, V>>>
Windows::Foundation::Collections::IMap<K, V> single_threaded_map()
{
    return make<impl::single_threaded_map<K, V, std::map<K, V, Compare, Allocator>>>(std::map<K, V, Compare, Allocator>{});
}

template <typename K, typename V, typename Compare = std::less<K>, typename Allocator = std::allocator<std::pair<K const, V>>>
Windows::Foundation::Collections::IMap<K, V> single_threaded_map(std::map<K, V, Compare, Allocator> && values)
{
    return make<impl::single_threaded_map<K, V, std::map<K, V, Compare, Allocator>>>(std::move(values));
}

template <typename K, typename V, typename Hash = std::hash<K>, typename KeyEqual = std::equal_to<K>, typename Allocator = std::allocator<std::pair<const K, V>>>
Windows::Foundation::Collections::IMap<K, V> single_threaded_map(std::unordered_map<K, V, Hash, KeyEqual, Allocator> && values)
{
    return make<impl::single_threaded_map<K, V, std::unordered_map<K, V, Hash, KeyEqual, Allocator>>>(std::move(values));
}

namespace Windows::Foundation
{
    struct Point
    {
        float X;
        float Y;

        Point() noexcept = default;

        Point(float X, float Y) noexcept
            : X(X), Y(Y)
        {}

#ifdef WINRT_NUMERICS

        Point(const Numerics::float2 & value) noexcept
            : X(value.x), Y(value.y)
        {}

        operator Numerics::float2() const noexcept
        {
            return { X, Y };
        }

#endif
    };

    struct Size
    {
        float Width;
        float Height;

        Size() noexcept = default;

        Size(float Width, float Height) noexcept
            : Width(Width), Height(Height)
        {}

#ifdef WINRT_NUMERICS

        Size(const Numerics::float2 & value) noexcept
            : Width(value.x), Height(value.y)
        {}

        operator Numerics::float2() const noexcept
        {
            return { Width, Height };
        }

#endif
    };

    struct Rect
    {
        float X;
        float Y;
        float Width;
        float Height;
    };
}

namespace ABI::Windows::Foundation
{
    using Point = winrt::Windows::Foundation::Point;
    using Size = winrt::Windows::Foundation::Size;
    using Rect = winrt::Windows::Foundation::Rect;
}

namespace impl
{
    using filetime_period = std::ratio_multiply<std::ratio<100>, std::nano>;
}

struct clock;

namespace Windows::Foundation
{
    using TimeSpan = std::chrono::duration<int64_t, impl::filetime_period>;
    using DateTime = std::chrono::time_point<clock, TimeSpan>;
}

namespace ABI::Windows::Foundation
{
    using TimeSpan = winrt::Windows::Foundation::TimeSpan;
    using DateTime = winrt::Windows::Foundation::DateTime;
}

struct clock
{
    using rep = int64_t;
    using period = impl::filetime_period;
    using duration = Windows::Foundation::TimeSpan;
    using time_point = Windows::Foundation::DateTime;

    static constexpr bool is_steady = false;

    static time_point now() noexcept
    {
        FILETIME ft;
        ::GetSystemTimePreciseAsFileTime(&ft);
        return from_FILETIME(ft);
    }

    static time_t to_time_t(const time_point& time) noexcept
    {
        return std::chrono::duration_cast<time_t_duration>(time - time_t_epoch).count();
    }

    static time_point from_time_t(time_t time) noexcept
    {
        return time_t_epoch + time_t_duration{ time };
    }

    // FILETIME is identical to WinRT's DateTime, save for the fact that it's unsigned.
    // Detect mismatch, but this only matters for dates before 27000 BC or after 29000 AD.
    static FILETIME to_FILETIME(const time_point& time) noexcept
    {
        ULARGE_INTEGER ul;
        ul.QuadPart = time.time_since_epoch().count();
        WINRT_ASSERT(static_cast<int32_t>(ul.HighPart) >= 0);
        return FILETIME{ ul.LowPart, ul.HighPart };
    }

    static time_point from_FILETIME(const FILETIME& time) noexcept
    {
        ULARGE_INTEGER ul{ { time.dwLowDateTime, time.dwHighDateTime } };
        WINRT_ASSERT(static_cast<int32_t>(ul.HighPart) >= 0);
        return time_point{ duration{ ul.QuadPart } };
    }

private:

    // Define 00:00:00, Jan 1 1970 UTC in FILETIME units
    static constexpr time_point time_t_epoch{ duration{ 0x019DB1DED53E8000 } };
    using time_t_duration = std::chrono::duration<time_t>;
};

namespace Windows::Foundation
{
    enum class AsyncStatus
    {
        Started,
        Completed,
        Canceled,
        Error,
    };
}

namespace impl
{
    template <typename Async>
    void blocking_suspend(const Async & async)
    {
        if (async.Status() == Windows::Foundation::AsyncStatus::Completed)
        {
            return;
        }

        lock x;
        condition_variable cv;
        bool completed = false;

        async.Completed([&](const Async &, Windows::Foundation::AsyncStatus)
        {
            const lock_guard guard(x);
            completed = true;
            cv.wake_one();
        });

        const lock_guard guard(x);
        cv.wait_while(x, [&] { return !completed; });
    }
}

namespace ABI::Windows::Foundation
{
    struct AsyncActionCompletedHandler;
    template <typename TProgress> struct AsyncActionProgressHandler;
    template <typename TProgress> struct AsyncActionWithProgressCompletedHandler;
    template <typename TResult, typename TProgress> struct AsyncOperationProgressHandler;
    template <typename TResult, typename TProgress> struct AsyncOperationWithProgressCompletedHandler;
    template <typename TResult> struct AsyncOperationCompletedHandler;

    struct IAsyncInfo;
    struct IAsyncAction;
    template <typename TProgress> struct IAsyncActionWithProgress;
    template <typename TResult> struct IAsyncOperation;
    template <typename TResult, typename TProgress> struct IAsyncOperationWithProgress;

    struct __declspec(uuid("a4ed5c81-76c9-40bd-8be6-b1d90fb20ae7")) __declspec(novtable) AsyncActionCompletedHandler : IUnknown
    {
        virtual HRESULT __stdcall abi_Invoke(IAsyncAction * asyncInfo, winrt::Windows::Foundation::AsyncStatus asyncStatus) = 0;
    };

    template <typename TProgress>
    struct __declspec(novtable) impl_AsyncActionProgressHandler : IUnknown
    {
        virtual HRESULT __stdcall abi_Invoke(IAsyncActionWithProgress<TProgress> * asyncInfo, arg_in<TProgress> progressInfo) = 0;
    };

    template <typename TProgress>
    struct __declspec(novtable) impl_AsyncActionWithProgressCompletedHandler : IUnknown
    {
        virtual HRESULT __stdcall abi_Invoke(IAsyncActionWithProgress<TProgress> * asyncInfo, winrt::Windows::Foundation::AsyncStatus status) = 0;
    };

    template <typename TResult, typename TProgress>
    struct __declspec(novtable) impl_AsyncOperationProgressHandler : IUnknown
    {
        virtual HRESULT __stdcall abi_Invoke(IAsyncOperationWithProgress<TResult, TProgress> * asyncInfo, arg_in<TProgress> progressInfo) = 0;
    };

    template <typename TResult, typename TProgress>
    struct __declspec(novtable) impl_AsyncOperationWithProgressCompletedHandler : IUnknown
    {
        virtual HRESULT __stdcall abi_Invoke(IAsyncOperationWithProgress<TResult, TProgress> * asyncInfo, winrt::Windows::Foundation::AsyncStatus status) = 0;
    };

    template <typename TResult>
    struct __declspec(novtable) impl_AsyncOperationCompletedHandler : IUnknown
    {
        virtual HRESULT __stdcall abi_Invoke(IAsyncOperation<TResult> * asyncInfo, winrt::Windows::Foundation::AsyncStatus status) = 0;
    };

    struct __declspec(uuid("00000036-0000-0000-c000-000000000046")) __declspec(novtable) IAsyncInfo : IInspectable
    {
        virtual HRESULT __stdcall get_Id(uint32_t * id) = 0;
        virtual HRESULT __stdcall get_Status(winrt::Windows::Foundation::AsyncStatus * status) = 0;
        virtual HRESULT __stdcall get_ErrorCode(HRESULT * errorCode) = 0;
        virtual HRESULT __stdcall abi_Cancel() = 0;
        virtual HRESULT __stdcall abi_Close() = 0;
    };

    struct __declspec(uuid("5a648006-843a-4da9-865b-9d26e5dfad7b")) __declspec(novtable) IAsyncAction : IInspectable
    {
        virtual HRESULT __stdcall put_Completed(AsyncActionCompletedHandler * handler) = 0;
        virtual HRESULT __stdcall get_Completed(AsyncActionCompletedHandler ** handler) = 0;
        virtual HRESULT __stdcall abi_GetResults() = 0;
    };

    template <typename TProgress>
    struct __declspec(novtable) impl_IAsyncActionWithProgress : IInspectable
    {
        virtual HRESULT __stdcall put_Progress(AsyncActionProgressHandler<TProgress> * handler) = 0;
        virtual HRESULT __stdcall get_Progress(AsyncActionProgressHandler<TProgress> ** handler) = 0;
        virtual HRESULT __stdcall put_Completed(AsyncActionWithProgressCompletedHandler<TProgress> * handler) = 0;
        virtual HRESULT __stdcall get_Completed(AsyncActionWithProgressCompletedHandler<TProgress> ** handler) = 0;
        virtual HRESULT __stdcall abi_GetResults() = 0;
    };


    template <typename TResult>
    struct __declspec(novtable) impl_IAsyncOperation : IInspectable
    {
        virtual HRESULT __stdcall put_Completed(AsyncOperationCompletedHandler<TResult> * handler) = 0;
        virtual HRESULT __stdcall get_Completed(AsyncOperationCompletedHandler<TResult> ** handler) = 0;
        virtual HRESULT __stdcall abi_GetResults(arg_out<TResult> results) = 0;
    };

    template <typename TResult, typename TProgress>
    struct __declspec(novtable) impl_IAsyncOperationWithProgress : IInspectable
    {
        virtual HRESULT __stdcall put_Progress(AsyncOperationProgressHandler<TResult, TProgress> * handler) = 0;
        virtual HRESULT __stdcall get_Progress(AsyncOperationProgressHandler<TResult, TProgress> ** handler) = 0;
        virtual HRESULT __stdcall put_Completed(AsyncOperationWithProgressCompletedHandler<TResult, TProgress> * handler) = 0;
        virtual HRESULT __stdcall get_Completed(AsyncOperationWithProgressCompletedHandler<TResult, TProgress> ** handler) = 0;
        virtual HRESULT __stdcall abi_GetResults(arg_out<TResult> results) = 0;
    };

    template <typename TProgress> struct AsyncActionProgressHandler : impl::not_specialized<AsyncActionProgressHandler<TProgress>> {};
    template <typename TProgress> struct AsyncActionWithProgressCompletedHandler : impl::not_specialized<AsyncActionWithProgressCompletedHandler<TProgress>> {};
    template <typename TResult, typename TProgress> struct AsyncOperationProgressHandler : impl::not_specialized<AsyncOperationProgressHandler<TResult, TProgress>> {};
    template <typename TResult, typename TProgress> struct AsyncOperationWithProgressCompletedHandler : impl::not_specialized<AsyncOperationWithProgressCompletedHandler<TResult, TProgress>> {};
    template <typename TResult> struct AsyncOperationCompletedHandler : impl::not_specialized<AsyncOperationCompletedHandler<TResult>> {};
    template <typename TProgress> struct IAsyncActionWithProgress : impl::not_specialized<IAsyncActionWithProgress<TProgress>> {};
    template <typename TResult> struct IAsyncOperation : impl::not_specialized<IAsyncOperation<TResult>> {};
    template <typename TResult, typename TProgress> struct IAsyncOperationWithProgress : impl::not_specialized<IAsyncOperationWithProgress<TResult, TProgress>> {};
}

namespace Windows::Foundation
{
    struct AsyncActionCompletedHandler;
    template <typename TProgress> struct AsyncActionProgressHandler;
    template <typename TProgress> struct AsyncActionWithProgressCompletedHandler;
    template <typename TResult, typename TProgress> struct AsyncOperationProgressHandler;
    template <typename TResult, typename TProgress> struct AsyncOperationWithProgressCompletedHandler;
    template <typename TResult> struct AsyncOperationCompletedHandler;

    struct IAsyncInfo;
    struct IAsyncAction;
    template <typename TProgress> struct IAsyncActionWithProgress;
    template <typename TResult> struct IAsyncOperation;
    template <typename TResult, typename TProgress> struct IAsyncOperationWithProgress;

    template <typename D>
    struct WINRT_EBO impl_IAsyncInfo
    {
        uint32_t Id() const;
        AsyncStatus Status() const;
        HRESULT ErrorCode() const;
        void Cancel() const;
        void Close() const;
    };

    template <typename D>
    struct WINRT_EBO impl_IAsyncAction
    {
        void Completed(const AsyncActionCompletedHandler & handler) const;
        AsyncActionCompletedHandler Completed() const;
        void GetResults() const;
        void get() const;
    };

    template <typename D, typename TProgress>
    struct impl_IAsyncActionWithProgress
    {
        void Progress(const AsyncActionProgressHandler<TProgress> & handler) const;
        AsyncActionProgressHandler<TProgress> Progress() const;
        void Completed(const AsyncActionWithProgressCompletedHandler<TProgress> & handler) const;
        AsyncActionWithProgressCompletedHandler<TProgress> Completed() const;
        void GetResults() const;
        void get() const;
    };

    template <typename D, typename TResult>
    struct impl_IAsyncOperation
    {
        void Completed(const AsyncOperationCompletedHandler<TResult> & handler) const;
        AsyncOperationCompletedHandler<TResult> Completed() const;
        TResult GetResults() const;
        TResult get() const;
    };

    template <typename D, typename TResult, typename TProgress>
    struct impl_IAsyncOperationWithProgress
    {
        void Progress(const AsyncOperationProgressHandler<TResult, TProgress> & handler) const;
        AsyncOperationProgressHandler<TResult, TProgress> Progress() const;
        void Completed(const AsyncOperationWithProgressCompletedHandler<TResult, TProgress> & handler) const;
        AsyncOperationWithProgressCompletedHandler<TResult, TProgress> Completed() const;
        TResult GetResults() const;
        TResult get() const;
    };
}

namespace impl
{
    template <> struct traits<Windows::Foundation::AsyncActionCompletedHandler>
    {
        using abi = ABI::Windows::Foundation::AsyncActionCompletedHandler;
    };

    template <typename TProgress> struct traits<Windows::Foundation::AsyncActionProgressHandler<TProgress>>
    {
        using abi = ABI::Windows::Foundation::AsyncActionProgressHandler<abi<TProgress>>;
    };

    template <typename TProgress> struct traits<Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>>
    {
        using abi = ABI::Windows::Foundation::AsyncActionWithProgressCompletedHandler<abi<TProgress>>;
    };

    template <typename TResult, typename TProgress> struct traits<Windows::Foundation::AsyncOperationProgressHandler<TResult, TProgress>>
    {
        using abi = ABI::Windows::Foundation::AsyncOperationProgressHandler<abi<TResult>, abi<TProgress>>;
    };

    template <typename TResult, typename TProgress> struct traits<Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>>
    {
        using abi = ABI::Windows::Foundation::AsyncOperationWithProgressCompletedHandler<abi<TResult>, abi<TProgress>>;
    };

    template <typename TResult> struct traits<Windows::Foundation::AsyncOperationCompletedHandler<TResult>>
    {
        using abi = ABI::Windows::Foundation::AsyncOperationCompletedHandler<abi<TResult>>;
    };

    template <> struct traits<Windows::Foundation::IAsyncInfo>
    {
        using abi = ABI::Windows::Foundation::IAsyncInfo;
        template <typename D> using consume = Windows::Foundation::impl_IAsyncInfo<D>;
    };

    template <> struct traits<Windows::Foundation::IAsyncAction>
    {
        using abi = ABI::Windows::Foundation::IAsyncAction;
        template <typename D> using consume = Windows::Foundation::impl_IAsyncAction<D>;
    };

    template <typename TProgress> struct traits<Windows::Foundation::IAsyncActionWithProgress<TProgress>>
    {
        using abi = ABI::Windows::Foundation::IAsyncActionWithProgress<abi<TProgress>>;
        template <typename D> using consume = Windows::Foundation::impl_IAsyncActionWithProgress<D, TProgress>;
    };

    template <typename TResult> struct traits<Windows::Foundation::IAsyncOperation<TResult>>
    {
        using abi = ABI::Windows::Foundation::IAsyncOperation<abi<TResult>>;
        template <typename D> using consume = Windows::Foundation::impl_IAsyncOperation<D, TResult>;
    };

    template <typename TResult, typename TProgress> struct traits<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>
    {
        using abi = ABI::Windows::Foundation::IAsyncOperationWithProgress<abi<TResult>, abi<TProgress>>;
        template <typename D> using consume = Windows::Foundation::impl_IAsyncOperationWithProgress<D, TResult, TProgress>;
    };
}

namespace Windows::Foundation
{
    struct AsyncActionCompletedHandler : IUnknown
    {
        AsyncActionCompletedHandler(std::nullptr_t = nullptr) noexcept {}
        template <typename L> AsyncActionCompletedHandler(L handler);
        template <typename F> AsyncActionCompletedHandler(F * handler);
        template <typename O, typename M> AsyncActionCompletedHandler(O * object, M method);
        void operator()(const IAsyncAction & asyncInfo, AsyncStatus asyncStatus) const;
    };

    template <typename TProgress>
    struct WINRT_EBO AsyncActionProgressHandler : IUnknown
    {
        AsyncActionProgressHandler(std::nullptr_t = nullptr) noexcept {}
        template <typename L> AsyncActionProgressHandler(L handler);
        template <typename F> AsyncActionProgressHandler(F * handler);
        template <typename O, typename M> AsyncActionProgressHandler(O * object, M method);
        void operator()(const IAsyncActionWithProgress<TProgress> & sender, const TProgress & args) const;
    };

    template <typename TProgress>
    struct WINRT_EBO AsyncActionWithProgressCompletedHandler : IUnknown
    {
        AsyncActionWithProgressCompletedHandler(std::nullptr_t = nullptr) noexcept {}
        template <typename L> AsyncActionWithProgressCompletedHandler(L handler);
        template <typename F> AsyncActionWithProgressCompletedHandler(F * handler);
        template <typename O, typename M> AsyncActionWithProgressCompletedHandler(O * object, M method);
        void operator()(const IAsyncActionWithProgress<TProgress> & sender, const AsyncStatus args) const;
    };

    template <typename TResult, typename TProgress>
    struct WINRT_EBO AsyncOperationProgressHandler : IUnknown
    {
        AsyncOperationProgressHandler(std::nullptr_t = nullptr) noexcept {}
        template <typename L> AsyncOperationProgressHandler(L handler);
        template <typename F> AsyncOperationProgressHandler(F * handler);
        template <typename O, typename M> AsyncOperationProgressHandler(O * object, M method);
        void operator()(const IAsyncOperationWithProgress<TResult, TProgress> & sender, const TProgress & args) const;
    };

    template <typename TResult, typename TProgress>
    struct WINRT_EBO AsyncOperationWithProgressCompletedHandler : IUnknown
    {
        AsyncOperationWithProgressCompletedHandler(std::nullptr_t = nullptr) noexcept {}
        template <typename L> AsyncOperationWithProgressCompletedHandler(L handler);
        template <typename F> AsyncOperationWithProgressCompletedHandler(F * handler);
        template <typename O, typename M> AsyncOperationWithProgressCompletedHandler(O * object, M method);
        void operator()(const IAsyncOperationWithProgress<TResult, TProgress> & sender, const AsyncStatus args) const;
    };

    template <typename TResult>
    struct WINRT_EBO AsyncOperationCompletedHandler : IUnknown
    {
        AsyncOperationCompletedHandler(std::nullptr_t = nullptr) noexcept {}
        template <typename L> AsyncOperationCompletedHandler(L handler);
        template <typename F> AsyncOperationCompletedHandler(F * handler);
        template <typename O, typename M> AsyncOperationCompletedHandler(O * object, M method);
        void operator()(const IAsyncOperation<TResult> & sender, const AsyncStatus args) const;
    };

    struct IAsyncInfo :
        IUnknown,
        impl::consume<IAsyncInfo>
    {
        IAsyncInfo(std::nullptr_t = nullptr) noexcept {}
    };

    struct IAsyncAction :
        IInspectable,
        impl::consume<IAsyncAction>,
        impl::require<IAsyncAction, IAsyncInfo>
    {
        IAsyncAction(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename TProgress>
    struct WINRT_EBO IAsyncActionWithProgress :
        IInspectable,
        impl::consume<IAsyncActionWithProgress<TProgress>>,
        impl::require<IAsyncActionWithProgress<TProgress>, IAsyncInfo>
    {
        IAsyncActionWithProgress(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename TResult>
    struct WINRT_EBO IAsyncOperation :
        IInspectable,
        impl::consume<IAsyncOperation<TResult>>,
        impl::require<IAsyncOperation<TResult>, IAsyncInfo>
    {
        IAsyncOperation(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename TResult, typename TProgress>
    struct WINRT_EBO IAsyncOperationWithProgress :
        IInspectable,
        impl::consume<IAsyncOperationWithProgress<TResult, TProgress>>,
        impl::require<IAsyncOperationWithProgress<TResult, TProgress>, IAsyncInfo>
    {
        IAsyncOperationWithProgress(std::nullptr_t = nullptr) noexcept {}
    };

    template <typename D>
    uint32_t impl_IAsyncInfo<D>::Id() const
    {
        uint32_t id = 0;
        check_hresult((*(abi<IAsyncInfo> **)&static_cast<const IAsyncInfo &>(static_cast<const D &>(*this)))->get_Id(&id));
        return id;
    }

    template <typename D>
    AsyncStatus impl_IAsyncInfo<D>::Status() const
    {
        AsyncStatus status{};
        check_hresult((*(abi<IAsyncInfo> **)&static_cast<const IAsyncInfo &>(static_cast<const D &>(*this)))->get_Status(&status));
        return status;
    }

    template <typename D>
    HRESULT impl_IAsyncInfo<D>::ErrorCode() const
    {
        HRESULT code = S_OK;
        check_hresult((*(abi<IAsyncInfo> **)&static_cast<const IAsyncInfo &>(static_cast<const D &>(*this)))->get_ErrorCode(&code));
        return code;
    }

    template <typename D>
    void impl_IAsyncInfo<D>::Cancel() const
    {
        check_hresult((*(abi<IAsyncInfo> **)&static_cast<const IAsyncInfo &>(static_cast<const D &>(*this)))->abi_Cancel());
    }

    template <typename D>
    void impl_IAsyncInfo<D>::Close() const
    {
        check_hresult((*(abi<IAsyncInfo> **)&static_cast<const IAsyncInfo &>(static_cast<const D &>(*this)))->abi_Close());
    }

    template <typename D>
    void impl_IAsyncAction<D>::Completed(const AsyncActionCompletedHandler & handler) const
    {
        check_hresult((*(abi<IAsyncAction> **)&static_cast<const IAsyncAction &>(static_cast<const D &>(*this)))->put_Completed(winrt::get_abi(handler)));
    }

    template <typename D>
    AsyncActionCompletedHandler impl_IAsyncAction<D>::Completed() const
    {
        AsyncActionCompletedHandler handler{};
        check_hresult((*(abi<IAsyncAction> **)&static_cast<const IAsyncAction &>(static_cast<const D &>(*this)))->get_Completed(put_abi(handler)));
        return handler;
    }

    template <typename D>
    void impl_IAsyncAction<D>::GetResults() const
    {
        check_hresult((*(abi<IAsyncAction> **)&static_cast<const IAsyncAction &>(static_cast<const D &>(*this)))->abi_GetResults());
    }

    template <typename D>
    void impl_IAsyncAction<D>::get() const
    {
        impl::blocking_suspend(static_cast<const IAsyncAction &>(static_cast<const D &>(*this)));
        GetResults();
    }

    template <typename D, typename TProgress>
    void impl_IAsyncActionWithProgress<D, TProgress>::Progress(const AsyncActionProgressHandler<TProgress> & handler) const
    {
        check_hresult((*(abi<IAsyncActionWithProgress<TProgress>> **)&static_cast<const IAsyncActionWithProgress<TProgress> &>(static_cast<const D &>(*this)))->put_Progress(winrt::get_abi(handler)));
    }

    template <typename D, typename TProgress>
    AsyncActionProgressHandler<TProgress> impl_IAsyncActionWithProgress<D, TProgress>::Progress() const
    {
        AsyncActionProgressHandler<TProgress> handler;
        check_hresult((*(abi<IAsyncActionWithProgress<TProgress>> **)&static_cast<const IAsyncActionWithProgress<TProgress> &>(static_cast<const D &>(*this)))->get_Progress(put_abi(handler)));
        return handler;
    }

    template <typename D, typename TProgress>
    void impl_IAsyncActionWithProgress<D, TProgress>::Completed(const AsyncActionWithProgressCompletedHandler<TProgress> & handler) const
    {
        check_hresult((*(abi<IAsyncActionWithProgress<TProgress>> **)&static_cast<const IAsyncActionWithProgress<TProgress> &>(static_cast<const D &>(*this)))->put_Completed(winrt::get_abi(handler)));
    }

    template <typename D, typename TProgress>
    AsyncActionWithProgressCompletedHandler<TProgress> impl_IAsyncActionWithProgress<D, TProgress>::Completed() const
    {
        AsyncActionWithProgressCompletedHandler<TProgress> handler;
        check_hresult((*(abi<IAsyncActionWithProgress<TProgress>> **)&static_cast<const IAsyncActionWithProgress<TProgress> &>(static_cast<const D &>(*this)))->get_Completed(put_abi(handler)));
        return handler;
    }

    template <typename D, typename TProgress>
    void impl_IAsyncActionWithProgress<D, TProgress>::GetResults() const
    {
        check_hresult((*(abi<IAsyncActionWithProgress<TProgress>> **)&static_cast<const IAsyncActionWithProgress<TProgress> &>(static_cast<const D &>(*this)))->abi_GetResults());
    }

    template <typename D, typename TProgress>
    void impl_IAsyncActionWithProgress<D, TProgress>::get() const
    {
        impl::blocking_suspend(static_cast<const IAsyncActionWithProgress<TProgress> &>(static_cast<const D &>(*this)));
        GetResults();
    }

    template <typename D, typename TResult>
    void impl_IAsyncOperation<D, TResult>::Completed(const AsyncOperationCompletedHandler<TResult> & handler) const
    {
        check_hresult((*(abi<IAsyncOperation<TResult>> **)&static_cast<const IAsyncOperation<TResult> &>(static_cast<const D &>(*this)))->put_Completed(winrt::get_abi(handler)));
    }

    template <typename D, typename TResult>
    AsyncOperationCompletedHandler<TResult> impl_IAsyncOperation<D, TResult>::Completed() const
    {
        AsyncOperationCompletedHandler<TResult> temp;
        check_hresult((*(abi<IAsyncOperation<TResult>> **)&static_cast<const IAsyncOperation<TResult> &>(static_cast<const D &>(*this)))->get_Completed(put_abi(temp)));
        return temp;
    }

    template <typename D, typename TResult>
    TResult impl_IAsyncOperation<D, TResult>::GetResults() const
    {
        TResult result = impl::empty_value<TResult>();
        check_hresult((*(abi<IAsyncOperation<TResult>> **)&static_cast<const IAsyncOperation<TResult> &>(static_cast<const D &>(*this)))->abi_GetResults(put_abi(result)));
        return result;
    }

    template <typename D, typename TResult>
    TResult impl_IAsyncOperation<D, TResult>::get() const
    {
        impl::blocking_suspend(static_cast<const IAsyncOperation<TResult> &>(static_cast<const D &>(*this)));
        return GetResults();
    }

    template <typename D, typename TResult, typename TProgress>
    void impl_IAsyncOperationWithProgress<D, TResult, TProgress>::Progress(const AsyncOperationProgressHandler<TResult, TProgress> & handler) const
    {
        check_hresult((*(abi<IAsyncOperationWithProgress<TResult, TProgress>> **)&static_cast<const IAsyncOperationWithProgress<TResult, TProgress> &>(static_cast<const D &>(*this)))->put_Progress(winrt::get_abi(handler)));
    }

    template <typename D, typename TResult, typename TProgress>
    AsyncOperationProgressHandler<TResult, TProgress> impl_IAsyncOperationWithProgress<D, TResult, TProgress>::Progress() const
    {
        AsyncOperationProgressHandler<TResult, TProgress> handler;
        check_hresult((*(abi<IAsyncOperationWithProgress<TResult, TProgress>> **)&static_cast<const IAsyncOperationWithProgress<TResult, TProgress> &>(static_cast<const D &>(*this)))->get_Progress(put_abi(handler)));
        return handler;
    }

    template <typename D, typename TResult, typename TProgress>
    void impl_IAsyncOperationWithProgress<D, TResult, TProgress>::Completed(const AsyncOperationWithProgressCompletedHandler<TResult, TProgress> & handler) const
    {
        check_hresult((*(abi<IAsyncOperationWithProgress<TResult, TProgress>> **)&static_cast<const IAsyncOperationWithProgress<TResult, TProgress> &>(static_cast<const D &>(*this)))->put_Completed(winrt::get_abi(handler)));
    }

    template <typename D, typename TResult, typename TProgress>
    AsyncOperationWithProgressCompletedHandler<TResult, TProgress> impl_IAsyncOperationWithProgress<D, TResult, TProgress>::Completed() const
    {
        AsyncOperationWithProgressCompletedHandler<TResult, TProgress> handler;
        check_hresult((*(abi<IAsyncOperationWithProgress<TResult, TProgress>> **)&static_cast<const IAsyncOperationWithProgress<TResult, TProgress> &>(static_cast<const D &>(*this)))->get_Completed(put_abi(handler)));
        return handler;
    }

    template <typename D, typename TResult, typename TProgress>
    TResult impl_IAsyncOperationWithProgress<D, TResult, TProgress>::GetResults() const
    {
        TResult result = impl::empty_value<TResult>();
        check_hresult((*(abi<IAsyncOperationWithProgress<TResult, TProgress>> **)&static_cast<const IAsyncOperationWithProgress<TResult, TProgress> &>(static_cast<const D &>(*this)))->abi_GetResults(put_abi(result)));
        return result;
    }

    template <typename D, typename TResult, typename TProgress>
    TResult impl_IAsyncOperationWithProgress<D, TResult, TProgress>::get() const
    {
        impl::blocking_suspend(static_cast<const IAsyncOperationWithProgress<TResult, TProgress> &>(static_cast<const D &>(*this)));
        return GetResults();
    }
}

namespace impl
{
    template <typename H> struct async_action_completed_handler : implements<async_action_completed_handler<H>, abi<Windows::Foundation::AsyncActionCompletedHandler>>, H
    {
        async_action_completed_handler(H && handler) : H(std::forward<H>(handler)) {}

        HRESULT __stdcall abi_Invoke(abi_arg_in<Windows::Foundation::IAsyncAction> asyncInfo, Windows::Foundation::AsyncStatus asyncStatus) noexcept override
        {
            try
            {
                (*this)(*reinterpret_cast<const Windows::Foundation::IAsyncAction *>(&asyncInfo), asyncStatus);
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }
    };

    template <typename TProgress, typename H>
    struct async_action_progress_handler : implements<async_action_progress_handler<TProgress, H>, abi<Windows::Foundation::AsyncActionProgressHandler<TProgress>>>, H
    {
        async_action_progress_handler(H && handler) : H(std::forward<H>(handler)) {}

        HRESULT __stdcall abi_Invoke(abi_arg_in<Windows::Foundation::IAsyncActionWithProgress<TProgress>> sender, abi_arg_in<TProgress> args) noexcept override
        {
            try
            {
                (*this)(*reinterpret_cast<const Windows::Foundation::IAsyncActionWithProgress<TProgress> *>(&sender), *reinterpret_cast<const TProgress *>(&args));
                return S_OK;
            }
            catch (...) { return impl::to_hresult(); }
        }
    };

    template <typename TProgress, typename H>
    struct async_action_with_progress_completed_handler : implements<async_action_with_progress_completed_handler<TProgress, H>, abi<Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>>>, H
    {
        async_action_with_progress_completed_handler(H && handler) : H(std::forward<H>(handler)) {}

        HRESULT __stdcall abi_Invoke(abi_arg_in<Windows::Foundation::IAsyncActionWithProgress<TProgress>> sender, Windows::Foundation::AsyncStatus args) noexcept override
        {
            try
            {
                (*this)(*reinterpret_cast<const Windows::Foundation::IAsyncActionWithProgress<TProgress> *>(&sender), args);
                return S_OK;
            }
            catch (...) { return impl::to_hresult(); }
        }
    };

    template <typename TResult, typename TProgress, typename H>
    struct async_operation_progress_handler : implements<async_operation_progress_handler<TResult, TProgress, H>, abi<Windows::Foundation::AsyncOperationProgressHandler<TResult, TProgress>>>, H
    {
        async_operation_progress_handler(H && handler) : H(std::forward<H>(handler)) {}

        HRESULT __stdcall abi_Invoke(abi_arg_in<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>> sender, abi_arg_in<TProgress> args) noexcept override
        {
            try
            {
                (*this)(*reinterpret_cast<const Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress> *>(&sender), *reinterpret_cast<const TProgress *>(&args));
                return S_OK;
            }
            catch (...) { return impl::to_hresult(); }
        }
    };

    template <typename TResult, typename TProgress, typename H>
    struct async_operation_with_progress_completed_handler : implements<async_operation_with_progress_completed_handler<TResult, TProgress, H>, abi<Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>>>, H
    {
        async_operation_with_progress_completed_handler(H && handler) : H(std::forward<H>(handler)) {}

        HRESULT __stdcall abi_Invoke(abi_arg_in<Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>> sender, Windows::Foundation::AsyncStatus args) noexcept override
        {
            try
            {
                (*this)(*reinterpret_cast<const Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress> *>(&sender), args);
                return S_OK;
            }
            catch (...) { return impl::to_hresult(); }
        }
    };

    template <typename TResult, typename H>
    struct async_operation_completed_handler : implements<async_operation_completed_handler<TResult, H>, abi<Windows::Foundation::AsyncOperationCompletedHandler<TResult>>>, H
    {
        async_operation_completed_handler(H && handler) : H(std::forward<H>(handler)) {}

        HRESULT __stdcall abi_Invoke(abi_arg_in<Windows::Foundation::IAsyncOperation<TResult>> sender, Windows::Foundation::AsyncStatus args) noexcept override
        {
            try
            {
                (*this)(*reinterpret_cast<const Windows::Foundation::IAsyncOperation<TResult> *>(&sender), args);
                return S_OK;
            }
            catch (...) { return impl::to_hresult(); }
        }
    };
}

namespace Windows::Foundation
{
    template <typename L> AsyncActionCompletedHandler::AsyncActionCompletedHandler(L handler) :
        AsyncActionCompletedHandler(impl::make_delegate<impl::async_action_completed_handler<L>, AsyncActionCompletedHandler>(std::forward<L>(handler)))
    {}

    template <typename F> AsyncActionCompletedHandler::AsyncActionCompletedHandler(F * handler) :
        AsyncActionCompletedHandler([=](auto && ... args) { handler(args ...); })
    {}

    template <typename O, typename M> AsyncActionCompletedHandler::AsyncActionCompletedHandler(O * object, M method) :
        AsyncActionCompletedHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
    {}

    inline void AsyncActionCompletedHandler::operator()(const IAsyncAction & asyncInfo, const AsyncStatus asyncStatus) const
    {
        check_hresult((*(abi<AsyncActionCompletedHandler> **)this)->abi_Invoke(get_abi(asyncInfo), asyncStatus));
    }

    template <typename TProgress> template <typename L> AsyncActionProgressHandler<TProgress>::AsyncActionProgressHandler(L handler) :
        AsyncActionProgressHandler(impl::make_delegate<impl::async_action_progress_handler<TProgress, L>, AsyncActionProgressHandler>(std::forward<L>(handler)))
    {}

    template <typename TProgress> template <typename F> AsyncActionProgressHandler<TProgress>::AsyncActionProgressHandler(F * handler) :
        AsyncActionProgressHandler([=](auto && ... args) { handler(args ...); })
    {}

    template <typename TProgress> template <typename O, typename M> AsyncActionProgressHandler<TProgress>::AsyncActionProgressHandler(O * object, M method) :
        AsyncActionProgressHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
    {}

    template <typename TProgress> void AsyncActionProgressHandler<TProgress>::operator()(const IAsyncActionWithProgress<TProgress> & sender, const TProgress & args) const
    {
        check_hresult((*(abi<AsyncActionProgressHandler<TProgress>> **)this)->abi_Invoke(get_abi(sender), get_abi(args)));
    }

    template <typename TProgress> template <typename L> AsyncActionWithProgressCompletedHandler<TProgress>::AsyncActionWithProgressCompletedHandler(L handler) :
        AsyncActionWithProgressCompletedHandler(impl::make_delegate<impl::async_action_with_progress_completed_handler<TProgress, L>, AsyncActionWithProgressCompletedHandler<TProgress>>(std::forward<L>(handler)))
    {}

    template <typename TProgress> template <typename F> AsyncActionWithProgressCompletedHandler<TProgress>::AsyncActionWithProgressCompletedHandler(F * handler) :
        AsyncActionWithProgressCompletedHandler([=](auto && ... args) { handler(args ...); })
    {}

    template <typename TProgress> template <typename O, typename M> AsyncActionWithProgressCompletedHandler<TProgress>::AsyncActionWithProgressCompletedHandler(O * object, M method) :
        AsyncActionWithProgressCompletedHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
    {}

    template <typename TProgress> void AsyncActionWithProgressCompletedHandler<TProgress>::operator()(const IAsyncActionWithProgress<TProgress> & sender, const AsyncStatus args) const
    {
        check_hresult((*(abi<AsyncActionWithProgressCompletedHandler<TProgress>> **)this)->abi_Invoke(get_abi(sender), args));
    }

    template <typename TResult, typename TProgress> template <typename L> AsyncOperationProgressHandler<TResult, TProgress>::AsyncOperationProgressHandler(L handler) :
        AsyncOperationProgressHandler(impl::make_delegate<impl::async_operation_progress_handler<TResult, TProgress, L>, AsyncOperationProgressHandler<TResult, TProgress>>(std::forward<L>(handler)))
    {}

    template <typename TResult, typename TProgress> template <typename F> AsyncOperationProgressHandler<TResult, TProgress>::AsyncOperationProgressHandler(F * handler) :
        AsyncOperationProgressHandler([=](auto && ... args) { handler(args ...); })
    {}

    template <typename TResult, typename TProgress> template <typename O, typename M> AsyncOperationProgressHandler<TResult, TProgress>::AsyncOperationProgressHandler(O * object, M method) :
        AsyncOperationProgressHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
    {}

    template <typename TResult, typename TProgress> void AsyncOperationProgressHandler<TResult, TProgress>::operator()(const IAsyncOperationWithProgress<TResult, TProgress> & sender, const TProgress & args) const
    {
        check_hresult((*(abi<AsyncOperationProgressHandler<TResult, TProgress>> **)this)->abi_Invoke(get_abi(sender), get_abi(args)));
    }

    template <typename TResult, typename TProgress> template <typename L> AsyncOperationWithProgressCompletedHandler<TResult, TProgress>::AsyncOperationWithProgressCompletedHandler(L handler) :
        AsyncOperationWithProgressCompletedHandler(impl::make_delegate<impl::async_operation_with_progress_completed_handler<TResult, TProgress, L>, AsyncOperationWithProgressCompletedHandler<TResult, TProgress>>(std::forward<L>(handler)))
    {}

    template <typename TResult, typename TProgress> template <typename F> AsyncOperationWithProgressCompletedHandler<TResult, TProgress>::AsyncOperationWithProgressCompletedHandler(F * handler) :
        AsyncOperationWithProgressCompletedHandler([=](auto && ... args) { handler(args ...); })
    {}

    template <typename TResult, typename TProgress> template <typename O, typename M> AsyncOperationWithProgressCompletedHandler<TResult, TProgress>::AsyncOperationWithProgressCompletedHandler(O * object, M method) :
        AsyncOperationWithProgressCompletedHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
    {}

    template <typename TResult, typename TProgress> void AsyncOperationWithProgressCompletedHandler<TResult, TProgress>::operator()(const IAsyncOperationWithProgress<TResult, TProgress> & sender, const AsyncStatus args) const
    {
        check_hresult((*(abi<AsyncOperationWithProgressCompletedHandler<TResult, TProgress>> **)this)->abi_Invoke(get_abi(sender), args));
    }

    template <typename TResult> template <typename L> AsyncOperationCompletedHandler<TResult>::AsyncOperationCompletedHandler(L handler) :
        AsyncOperationCompletedHandler(impl::make_delegate<impl::async_operation_completed_handler<TResult, L>, AsyncOperationCompletedHandler<TResult>>(std::forward<L>(handler)))
    {}

    template <typename TResult> template <typename F> AsyncOperationCompletedHandler<TResult>::AsyncOperationCompletedHandler(F * handler) :
        AsyncOperationCompletedHandler([=](auto && ... args) { handler(args ...); })
    {}

    template <typename TResult> template <typename O, typename M> AsyncOperationCompletedHandler<TResult>::AsyncOperationCompletedHandler(O * object, M method) :
        AsyncOperationCompletedHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
    {}

    template <typename TResult> void AsyncOperationCompletedHandler<TResult>::operator()(const IAsyncOperation<TResult> & sender, const AsyncStatus args) const
    {
        check_hresult((*(abi<AsyncOperationCompletedHandler<TResult>> **)this)->abi_Invoke(get_abi(sender), args));
    }
}

namespace impl
{
    template <typename D>
    struct produce<D, Windows::Foundation::IAsyncAction> : produce_base<D, Windows::Foundation::IAsyncAction>
    {
        HRESULT __stdcall put_Completed(abi_arg_in<Windows::Foundation::AsyncActionCompletedHandler> handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Completed(*reinterpret_cast<const Windows::Foundation::AsyncActionCompletedHandler *>(&handler));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Completed(abi_arg_out<Windows::Foundation::AsyncActionCompletedHandler> handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *handler = detach_abi(this->shim().Completed());
                return S_OK;
            }
            catch (...)
            {
                *handler = nullptr;
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_GetResults() noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetResults();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }
    };

    template <typename D>
    struct produce<D, Windows::Foundation::IAsyncInfo> : produce_base<D, Windows::Foundation::IAsyncInfo>
    {
        HRESULT __stdcall get_Id(uint32_t * id) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *id = this->shim().Id();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Status(winrt::Windows::Foundation::AsyncStatus * status) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *status = this->shim().Status();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall get_ErrorCode(HRESULT * errorCode) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *errorCode = this->shim().ErrorCode();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_Cancel() noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Cancel();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_Close() noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Close();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }
    };

    template <typename D, typename TProgress>
    struct produce<D, Windows::Foundation::IAsyncActionWithProgress<TProgress>> : produce_base<D, Windows::Foundation::IAsyncActionWithProgress<TProgress>>
    {
        HRESULT __stdcall put_Progress(abi_arg_in<Windows::Foundation::AsyncActionProgressHandler<TProgress>> handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Progress(*reinterpret_cast<const Windows::Foundation::AsyncActionProgressHandler<TProgress> *>(&handler));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Progress(abi_arg_out<Windows::Foundation::AsyncActionProgressHandler<TProgress>> handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *handler = detach_abi(this->shim().Progress());
                return S_OK;
            }
            catch (...)
            {
                *handler = nullptr;
                return to_hresult();
            }
        }

        HRESULT __stdcall put_Completed(abi_arg_in<Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>> handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Completed(*reinterpret_cast<const Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress> *>(&handler));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Completed(abi_arg_out<Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>> handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *handler = detach_abi(this->shim().Completed());
                return S_OK;
            }
            catch (...)
            {
                *handler = nullptr;
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_GetResults() noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetResults();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }
    };

    template <typename D, typename TResult>
    struct produce<D, Windows::Foundation::IAsyncOperation<TResult>> : produce_base<D, Windows::Foundation::IAsyncOperation<TResult>>
    {
        HRESULT __stdcall put_Completed(abi_arg_in<Windows::Foundation::AsyncOperationCompletedHandler<TResult>> handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Completed(*reinterpret_cast<const Windows::Foundation::AsyncOperationCompletedHandler<TResult> *>(&handler));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Completed(abi_arg_out<Windows::Foundation::AsyncOperationCompletedHandler<TResult>> handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *handler = detach_abi(this->shim().Completed());
                return S_OK;
            }
            catch (...)
            {
                *handler = nullptr;
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_GetResults(abi_arg_out<TResult> results) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *results = detach_abi(this->shim().GetResults());
                return S_OK;
            }
            catch (...)
            {
                clear_abi(results);
                return to_hresult();
            }
        }
    };

    template <typename D, typename TResult, typename TProgress>
    struct produce<D, Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>> : produce_base<D, Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>
    {
        HRESULT __stdcall put_Progress(abi_arg_in<Windows::Foundation::AsyncOperationProgressHandler<TResult, TProgress>> handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Progress(*reinterpret_cast<const Windows::Foundation::AsyncOperationProgressHandler<TResult, TProgress> *>(&handler));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Progress(abi_arg_out<Windows::Foundation::AsyncOperationProgressHandler<TResult, TProgress>> handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *handler = detach_abi(this->shim().Progress());
                return S_OK;
            }
            catch (...)
            {
                *handler = nullptr;
                return to_hresult();
            }
        }

        HRESULT __stdcall put_Completed(abi_arg_in<Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>> handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Completed(*reinterpret_cast<const Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress> *>(&handler));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Completed(abi_arg_out<Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>> handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *handler = detach_abi(this->shim().Completed());
                return S_OK;
            }
            catch (...)
            {
                *handler = nullptr;
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_GetResults(abi_arg_out<TResult> results) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *results = detach_abi(this->shim().GetResults());
                return S_OK;
            }
            catch (...)
            {
                clear_abi(results);
                return to_hresult();
            }
        }
    };
}

#ifdef WINRT_ASYNC

namespace impl
{
    template <typename Async>
    struct await_adapter
    {
        const Async & async;

        bool await_ready() const
        {
            return async.Status() == Windows::Foundation::AsyncStatus::Completed;
        }

        void await_suspend(std::experimental::coroutine_handle<> handle) const
        {
            com_ptr<IContextCallback> context;
            check_hresult(CoGetObjectContext(__uuidof(context), reinterpret_cast<void **>(put_abi(context))));

            async.Completed([handle, context = std::move(context)](const auto &, Windows::Foundation::AsyncStatus)
            {
                ComCallData data = {};
                data.pUserDefined = handle.address();

                auto callback = [](ComCallData * data)
                {
                    std::experimental::coroutine_handle<>::from_address(data->pUserDefined)();
                    return S_OK;
                };

                check_hresult(context->ContextCallback(callback, &data, IID_ICallbackWithNoReentrancyToApplicationSTA, 5, nullptr));
            });
        }

        auto await_resume() const
        {
            return async.GetResults();
        }
    };
}

namespace Windows::Foundation
{
    inline impl::await_adapter<IAsyncAction> operator co_await(const IAsyncAction & async)
    {
        return{ async };
    }

    template <typename TProgress>
    impl::await_adapter<IAsyncActionWithProgress<TProgress>> operator co_await(const IAsyncActionWithProgress<TProgress> & async)
    {
        return{ async };
    }

    template <typename TResult>
    impl::await_adapter<IAsyncOperation<TResult>> operator co_await(const IAsyncOperation<TResult> & async)
    {
        return{ async };
    }

    template <typename TResult, typename TProgress>
    impl::await_adapter<IAsyncOperationWithProgress<TResult, TProgress>> operator co_await(const IAsyncOperationWithProgress<TResult, TProgress> & async)
    {
        return{ async };
    }
}

#endif

#ifdef WINRT_ASYNC

struct resume_background
{
    bool await_ready() const noexcept
    {
        return false;
    }

    void await_resume() const noexcept
    {
    }

    void await_suspend(std::experimental::coroutine_handle<> handle) const
    {
        auto callback = [](PTP_CALLBACK_INSTANCE, void * context)
        {
            std::experimental::coroutine_handle<>::from_address(context)();
        };

        if (!TrySubmitThreadpoolCallback(callback, handle.address(), nullptr))
        {
            throw_last_error();
        }
    }
};

struct thread_context
{
    thread_context()
    {
        check_hresult(CoGetObjectContext(__uuidof(m_context), reinterpret_cast<void **>(put_abi(m_context))));
    }

    bool await_ready() const noexcept
    {
        return false;
    }

    void await_resume() const noexcept
    {
    }

    void await_suspend(std::experimental::coroutine_handle<> handle) const
    {
        ComCallData data = {};
        data.pUserDefined = handle.address();

        auto callback = [](ComCallData * data)
        {
            std::experimental::coroutine_handle<>::from_address(data->pUserDefined)();
            return S_OK;
        };

        check_hresult(m_context->ContextCallback(callback, &data, IID_ICallbackWithNoReentrancyToApplicationSTA, 5, nullptr));
    }

private:

    com_ptr<IContextCallback> m_context;
};

struct resume_after
{
    explicit resume_after(Windows::Foundation::TimeSpan duration) noexcept :
    m_duration(duration)
    {
    }

    bool await_ready() const noexcept
    {
        return m_duration.count() <= 0;
    }

    void await_suspend(std::experimental::coroutine_handle<> handle)
    {
        m_timer = CreateThreadpoolTimer(callback, handle.address(), nullptr);

        if (!m_timer)
        {
            throw_last_error();
        }

        int64_t relative_count = -m_duration.count();
        SetThreadpoolTimer(get_abi(m_timer), reinterpret_cast<PFILETIME>(&relative_count), 0, 0);
    }

    void await_resume() const noexcept
    {
    }

private:

    static void __stdcall callback(PTP_CALLBACK_INSTANCE, void * context, PTP_TIMER) noexcept
    {
        std::experimental::coroutine_handle<>::from_address(context)();
    }

    struct timer_traits : impl::handle_traits<PTP_TIMER>
    {
        static void close(type value) noexcept
        {
            CloseThreadpoolTimer(value);
        }
    };

    impl::handle<timer_traits> m_timer;
    Windows::Foundation::TimeSpan m_duration;
};

struct resume_on_signal
{
    explicit resume_on_signal(HANDLE handle) noexcept :
    m_handle(handle)
    {}

    resume_on_signal(HANDLE handle, Windows::Foundation::TimeSpan timeout) noexcept :
        m_handle(handle),
        m_timeout(timeout)
    {}

    bool await_ready() const noexcept
    {
        return WaitForSingleObject(m_handle, 0) == WAIT_OBJECT_0;
    }

    void await_suspend(std::experimental::coroutine_handle<> resume)
    {
        m_resume = resume;
        m_wait = CreateThreadpoolWait(callback, this, nullptr);

        if (!m_wait)
        {
            throw_last_error();
        }

        int64_t relative_count = -m_timeout.count();
        PFILETIME file_time = relative_count != 0 ? reinterpret_cast<PFILETIME>(&relative_count) : nullptr;
        SetThreadpoolWait(get_abi(m_wait), m_handle, file_time);
    }

    bool await_resume() const noexcept
    {
        return m_result == WAIT_OBJECT_0;
    }

private:

    static void __stdcall callback(PTP_CALLBACK_INSTANCE, void * context, PTP_WAIT, TP_WAIT_RESULT result) noexcept
    {
        auto that = static_cast<resume_on_signal *>(context);
        that->m_result = result;
        that->m_resume();
    }

    struct wait_traits : impl::handle_traits<PTP_WAIT>
    {
        static void close(type value) noexcept
        {
            CloseThreadpoolWait(value);
        }
    };

    impl::handle<wait_traits> m_wait;
    Windows::Foundation::TimeSpan m_timeout{ 0 };
    HANDLE m_handle{};
    uint32_t m_result{};
    std::experimental::coroutine_handle<> m_resume{ nullptr };
};

struct awaitable_base
{
    static void __stdcall callback(PTP_CALLBACK_INSTANCE, void *, void * overlapped, ULONG result, ULONG_PTR, PTP_IO) noexcept
    {
        auto context = static_cast<awaitable_base *>(overlapped);
        context->m_result = result;
        context->m_resume();
    }

protected:

    OVERLAPPED m_overlapped{};
    uint32_t m_result{};
    std::experimental::coroutine_handle<> m_resume{ nullptr };
};

struct resumable_io
{
    resumable_io(HANDLE object) :
        m_io(CreateThreadpoolIo(object, awaitable_base::callback, nullptr, nullptr))
    {
        if (!m_io)
        {
            throw_last_error();
        }
    }

    template <typename F>
    auto start(F callback)
    {
        struct awaitable : awaitable_base, F
        {
            awaitable(PTP_IO io, F callback) noexcept :
            m_io(io),
                F(callback)
            {}

            bool await_ready() const noexcept
            {
                return false;
            }

            void await_suspend(std::experimental::coroutine_handle<> resume_handle)
            {
                m_resume = resume_handle;
                StartThreadpoolIo(m_io);

                try
                {
                    (*this)(m_overlapped);
                }
                catch (...)
                {
                    CancelThreadpoolIo(m_io);
                    throw;
                }
            }

            uint32_t await_resume() const
            {
                if (m_result != NO_ERROR && m_result != ERROR_HANDLE_EOF)
                {
                    throw hresult_error(HRESULT_FROM_WIN32(m_result));
                }

                return static_cast<uint32_t>(m_overlapped.InternalHigh);
            }

            PTP_IO m_io = nullptr;
        };

        return awaitable(get(), callback);
    }

    template <typename F>
    auto start_pending(F callback)
    {
        struct awaitable : awaitable_base, F
        {
            awaitable(PTP_IO io, F callback) noexcept :
            m_io(io),
                F(callback)
            {}

            bool await_ready() const noexcept
            {
                return false;
            }

            bool await_suspend(std::experimental::coroutine_handle<> resume_handle)
            {
                m_resume = resume_handle;
                StartThreadpoolIo(m_io);

                try
                {
                    const bool pending = (*this)(m_overlapped);

                    if (!pending)
                    {
                        CancelThreadpoolIo(m_io);
                    }

                    return pending;
                }
                catch (...)
                {
                    CancelThreadpoolIo(m_io);
                    throw;
                }
            }

            uint32_t await_resume() const
            {
                if (m_result != NO_ERROR && m_result != ERROR_HANDLE_EOF)
                {
                    throw hresult_error(HRESULT_FROM_WIN32(m_result));
                }

                return static_cast<uint32_t>(m_overlapped.InternalHigh);
            }

            PTP_IO m_io = nullptr;
        };

        return awaitable(get(), callback);
    }

    PTP_IO get() const noexcept
    {
        return winrt::get_abi(m_io);
    }

private:

    struct io_traits : impl::handle_traits<PTP_IO>
    {
        static void close(type value) noexcept
        {
            CloseThreadpoolIo(value);
        }
    };

    impl::handle<io_traits> m_io;
};

inline auto operator co_await(Windows::Foundation::TimeSpan duration)
{
    return resume_after(duration);
}

struct get_progress_token_t {};
constexpr get_progress_token_t get_progress_token{};

struct get_cancellation_token_t {};
constexpr get_cancellation_token_t get_cancellation_token{};

struct fire_and_forget {};

namespace impl
{
    template <typename Derived, typename AsyncInterface, typename CompletedHandler>
    struct promise_base : implements<Derived, AsyncInterface, Windows::Foundation::IAsyncInfo>
    {
        using AsyncStatus = Windows::Foundation::AsyncStatus;

        ~promise_base() noexcept
        {
            if (m_status == AsyncStatus::Error || m_status == AsyncStatus::Canceled)
            {
                reinterpret_cast<std::exception_ptr *>(&m_exception)->~exception_ptr();
            }
        }

        unsigned long __stdcall Release() noexcept
        {
            const uint32_t remaining = this->subtract_reference();

            if (remaining == 0)
            {
                std::atomic_thread_fence(std::memory_order_acquire);
                std::experimental::coroutine_handle<Derived>::from_promise(*static_cast<Derived *>(this)).destroy();
            }

            return remaining;
        }

        void Completed(const CompletedHandler & handler)
        {
            AsyncStatus status;

            {
                const lock_guard guard(m_lock);

                if (m_completed_assigned)
                {
                    throw winrt::hresult_illegal_delegate_assignment();
                }

                m_completed_assigned = true;

                if (m_status == AsyncStatus::Started)
                {
                    m_completed = handler;
                    return;
                }

                status = m_status;
            }

            if (handler)
            {
                handler(*this, status);
            }
        }

        CompletedHandler Completed() noexcept
        {
            const lock_guard guard(m_lock);
            return m_completed;
        }

        uint32_t Id() const noexcept
        {
            return 1;
        }

        AsyncStatus Status() noexcept
        {
            const lock_guard guard(m_lock);
            return m_status;
        }

        HRESULT ErrorCode() noexcept
        {
            try
            {
                const lock_guard guard(m_lock);

                if (m_status == AsyncStatus::Error)
                {
                    rethrow_exception(*reinterpret_cast<std::exception_ptr *>(&m_exception));
                }

                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        void Cancel() noexcept
        {
            const lock_guard guard(m_lock);

            if (m_status == AsyncStatus::Started)
            {
                m_status = AsyncStatus::Canceled;
            }
        }

        void Close()
        {
            const lock_guard guard(m_lock);

            if (m_status == AsyncStatus::Started)
            {
                throw winrt::hresult_illegal_state_change();
            }
        }

        AsyncInterface get_return_object() const noexcept
        {
            return *this;
        }

        std::experimental::suspend_never initial_suspend() const noexcept
        {
            return{};
        }

        struct final_suspend_type
        {
            promise_base * promise;

            bool await_ready() const noexcept
            {
                return false;
            }

            void await_resume() const noexcept
            {
            }

            bool await_suspend(std::experimental::coroutine_handle<>) const noexcept
            {
                const uint32_t remaining = promise->subtract_reference();

                if (remaining == 0)
                {
                    std::atomic_thread_fence(std::memory_order_acquire);
                }

                return remaining > 0;
            }
        };

        final_suspend_type final_suspend() noexcept
        {
            return{ this };
        }

        void set_exception(std::exception_ptr && exception)
        {
            CompletedHandler handler;
            AsyncStatus status;

            {
                const lock_guard guard(m_lock);
                WINRT_ASSERT(m_status == AsyncStatus::Started || m_status == AsyncStatus::Canceled);

                try
                {
                    rethrow_exception(exception);
                }
                catch (const winrt::hresult_canceled &)
                {
                    m_status = AsyncStatus::Canceled;
                }
                catch (...)
                {
                    m_status = AsyncStatus::Error;
                }

                new (&m_exception) std::exception_ptr(std::move(exception));
                handler = std::move(m_completed);
                status = m_status;
            }

            if (handler)
            {
                handler(*this, status);
            }
        }

    protected:

        std::aligned_union_t<0, std::exception_ptr> m_exception;
        lock m_lock;
        CompletedHandler m_completed;
        AsyncStatus m_status{ AsyncStatus::Started };
        bool m_completed_assigned{ false };
    };

    template <typename Promise>
    struct cancellation_token
    {
        cancellation_token(Promise * promise) noexcept :
        m_promise(promise)
        {
        }

        bool await_ready() const noexcept
        {
            return true;
        }

        void await_suspend(std::experimental::coroutine_handle<>) const noexcept
        {
        }

        cancellation_token<Promise> await_resume() const noexcept
        {
            return *this;
        }

        bool operator()() const noexcept
        {
            return m_promise->Status() == AsyncStatus::Canceled;
        }

    private:

        Promise * m_promise;
    };

    template <typename Promise, typename Progress>
    struct progress_token
    {
        progress_token(Promise * promise) noexcept :
        m_promise(promise)
        {
        }

        bool await_ready() const noexcept
        {
            return true;
        }

        void await_suspend(std::experimental::coroutine_handle<>) const noexcept
        {
        }

        progress_token<Promise, Progress> await_resume() const noexcept
        {
            return *this;
        }

        void operator()(const Progress & result)
        {
            m_promise->set_progress(result);
        }

    private:

        Promise * m_promise;
    };
}

#endif

namespace ABI::Windows::Foundation
{
    struct IPropertyValue;
    struct IPropertyValueStatics;
}

namespace Windows::Foundation
{
    struct IPropertyValue;
    struct IPropertyValueStatics;
    struct PropertyValue;

    enum class PropertyType
    {
        Empty = 0,
        UInt8 = 1,
        Int16 = 2,
        UInt16 = 3,
        Int32 = 4,
        UInt32 = 5,
        Int64 = 6,
        UInt64 = 7,
        Single = 8,
        Double = 9,
        Char16 = 10,
        Boolean = 11,
        String = 12,
        Inspectable = 13,
        DateTime = 14,
        TimeSpan = 15,
        Guid = 16,
        Point = 17,
        Size = 18,
        Rect = 19,
        OtherType = 20,
        UInt8Array = 1025,
        Int16Array = 1026,
        UInt16Array = 1027,
        Int32Array = 1028,
        UInt32Array = 1029,
        Int64Array = 1030,
        UInt64Array = 1031,
        SingleArray = 1032,
        DoubleArray = 1033,
        Char16Array = 1034,
        BooleanArray = 1035,
        StringArray = 1036,
        InspectableArray = 1037,
        DateTimeArray = 1038,
        TimeSpanArray = 1039,
        GuidArray = 1040,
        PointArray = 1041,
        SizeArray = 1042,
        RectArray = 1043,
        OtherTypeArray = 1044,
    };
}

namespace ABI::Windows::Foundation
{
    struct __declspec(uuid("4bd682dd-7554-40e9-9a9b-82654ede7e62")) __declspec(novtable) IPropertyValue : IInspectable
    {
        virtual HRESULT __stdcall get_Type(winrt::Windows::Foundation::PropertyType * value) = 0;
        virtual HRESULT __stdcall get_IsNumericScalar(bool * value) = 0;
        virtual HRESULT __stdcall abi_GetUInt8(uint8_t * value) = 0;
        virtual HRESULT __stdcall abi_GetInt16(int16_t * value) = 0;
        virtual HRESULT __stdcall abi_GetUInt16(uint16_t * value) = 0;
        virtual HRESULT __stdcall abi_GetInt32(int32_t * value) = 0;
        virtual HRESULT __stdcall abi_GetUInt32(uint32_t * value) = 0;
        virtual HRESULT __stdcall abi_GetInt64(int64_t * value) = 0;
        virtual HRESULT __stdcall abi_GetUInt64(uint64_t * value) = 0;
        virtual HRESULT __stdcall abi_GetSingle(float * value) = 0;
        virtual HRESULT __stdcall abi_GetDouble(double * value) = 0;
        virtual HRESULT __stdcall abi_GetChar16(wchar_t * value) = 0;
        virtual HRESULT __stdcall abi_GetBoolean(bool * value) = 0;
        virtual HRESULT __stdcall abi_GetString(hstring * value) = 0;
        virtual HRESULT __stdcall abi_GetGuid(GUID * value) = 0;
        virtual HRESULT __stdcall abi_GetDateTime(Windows::Foundation::DateTime * value) = 0;
        virtual HRESULT __stdcall abi_GetTimeSpan(Windows::Foundation::TimeSpan * value) = 0;
        virtual HRESULT __stdcall abi_GetPoint(Windows::Foundation::Point * value) = 0;
        virtual HRESULT __stdcall abi_GetSize(Windows::Foundation::Size * value) = 0;
        virtual HRESULT __stdcall abi_GetRect(Windows::Foundation::Rect * value) = 0;
        virtual HRESULT __stdcall abi_GetUInt8Array(uint32_t * __valueSize, uint8_t ** value) = 0;
        virtual HRESULT __stdcall abi_GetInt16Array(uint32_t * __valueSize, int16_t ** value) = 0;
        virtual HRESULT __stdcall abi_GetUInt16Array(uint32_t * __valueSize, uint16_t ** value) = 0;
        virtual HRESULT __stdcall abi_GetInt32Array(uint32_t * __valueSize, int32_t ** value) = 0;
        virtual HRESULT __stdcall abi_GetUInt32Array(uint32_t * __valueSize, uint32_t ** value) = 0;
        virtual HRESULT __stdcall abi_GetInt64Array(uint32_t * __valueSize, int64_t ** value) = 0;
        virtual HRESULT __stdcall abi_GetUInt64Array(uint32_t * __valueSize, uint64_t ** value) = 0;
        virtual HRESULT __stdcall abi_GetSingleArray(uint32_t * __valueSize, float ** value) = 0;
        virtual HRESULT __stdcall abi_GetDoubleArray(uint32_t * __valueSize, double ** value) = 0;
        virtual HRESULT __stdcall abi_GetChar16Array(uint32_t * __valueSize, wchar_t ** value) = 0;
        virtual HRESULT __stdcall abi_GetBooleanArray(uint32_t * __valueSize, bool ** value) = 0;
        virtual HRESULT __stdcall abi_GetStringArray(uint32_t * __valueSize, hstring ** value) = 0;
        virtual HRESULT __stdcall abi_GetInspectableArray(uint32_t * __valueSize, IInspectable *** value) = 0;
        virtual HRESULT __stdcall abi_GetGuidArray(uint32_t * __valueSize, GUID ** value) = 0;
        virtual HRESULT __stdcall abi_GetDateTimeArray(uint32_t * __valueSize, Windows::Foundation::DateTime ** value) = 0;
        virtual HRESULT __stdcall abi_GetTimeSpanArray(uint32_t * __valueSize, Windows::Foundation::TimeSpan ** value) = 0;
        virtual HRESULT __stdcall abi_GetPointArray(uint32_t * __valueSize, Windows::Foundation::Point ** value) = 0;
        virtual HRESULT __stdcall abi_GetSizeArray(uint32_t * __valueSize, Windows::Foundation::Size ** value) = 0;
        virtual HRESULT __stdcall abi_GetRectArray(uint32_t * __valueSize, Windows::Foundation::Rect ** value) = 0;
    };

    struct __declspec(uuid("629bdbc8-d932-4ff4-96b9-8d96c5c1e858")) __declspec(novtable) IPropertyValueStatics : IInspectable
    {
        virtual HRESULT __stdcall abi_CreateEmpty(IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateUInt8(uint8_t value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateInt16(int16_t value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateUInt16(uint16_t value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateInt32(int32_t value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateUInt32(uint32_t value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateInt64(int64_t value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateUInt64(uint64_t value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateSingle(float value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateDouble(double value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateChar16(wchar_t value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateBoolean(bool value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateString(hstring value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateInspectable(IInspectable * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateGuid(GUID value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateDateTime(Windows::Foundation::DateTime value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateTimeSpan(Windows::Foundation::TimeSpan value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreatePoint(Windows::Foundation::Point value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateSize(Windows::Foundation::Size value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateRect(Windows::Foundation::Rect value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateUInt8Array(uint32_t __valueSize, uint8_t * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateInt16Array(uint32_t __valueSize, int16_t * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateUInt16Array(uint32_t __valueSize, uint16_t * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateInt32Array(uint32_t __valueSize, int32_t * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateUInt32Array(uint32_t __valueSize, uint32_t * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateInt64Array(uint32_t __valueSize, int64_t * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateUInt64Array(uint32_t __valueSize, uint64_t * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateSingleArray(uint32_t __valueSize, float * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateDoubleArray(uint32_t __valueSize, double * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateChar16Array(uint32_t __valueSize, wchar_t * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateBooleanArray(uint32_t __valueSize, bool * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateStringArray(uint32_t __valueSize, hstring * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateInspectableArray(uint32_t __valueSize, IInspectable ** value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateGuidArray(uint32_t __valueSize, GUID * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateDateTimeArray(uint32_t __valueSize, Windows::Foundation::DateTime * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateTimeSpanArray(uint32_t __valueSize, Windows::Foundation::TimeSpan * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreatePointArray(uint32_t __valueSize, Windows::Foundation::Point * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateSizeArray(uint32_t __valueSize, Windows::Foundation::Size * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateRectArray(uint32_t __valueSize, Windows::Foundation::Rect * value, IInspectable ** propertyValue) = 0;
    };
}

namespace Windows::Foundation
{
    template <typename D>
    struct WINRT_EBO impl_IPropertyValue
    {
        Windows::Foundation::PropertyType Type() const;
        bool IsNumericScalar() const;
        uint8_t GetUInt8() const;
        int16_t GetInt16() const;
        uint16_t GetUInt16() const;
        int32_t GetInt32() const;
        uint32_t GetUInt32() const;
        int64_t GetInt64() const;
        uint64_t GetUInt64() const;
        float GetSingle() const;
        double GetDouble() const;
        wchar_t GetChar16() const;
        bool GetBoolean() const;
        hstring GetString() const;
        GUID GetGuid() const;
        Windows::Foundation::DateTime GetDateTime() const;
        Windows::Foundation::TimeSpan GetTimeSpan() const;
        Windows::Foundation::Point GetPoint() const;
        Windows::Foundation::Size GetSize() const;
        Windows::Foundation::Rect GetRect() const;
        void GetUInt8Array(com_array<uint8_t> & value) const;
        void GetInt16Array(com_array<int16_t> & value) const;
        void GetUInt16Array(com_array<uint16_t> & value) const;
        void GetInt32Array(com_array<int32_t> & value) const;
        void GetUInt32Array(com_array<uint32_t> & value) const;
        void GetInt64Array(com_array<int64_t> & value) const;
        void GetUInt64Array(com_array<uint64_t> & value) const;
        void GetSingleArray(com_array<float> & value) const;
        void GetDoubleArray(com_array<double> & value) const;
        void GetChar16Array(com_array<wchar_t> & value) const;
        void GetBooleanArray(com_array<bool> & value) const;
        void GetStringArray(com_array<hstring> & value) const;
        void GetInspectableArray(com_array<IInspectable> & value) const;
        void GetGuidArray(com_array<GUID> & value) const;
        void GetDateTimeArray(com_array<Windows::Foundation::DateTime> & value) const;
        void GetTimeSpanArray(com_array<Windows::Foundation::TimeSpan> & value) const;
        void GetPointArray(com_array<Windows::Foundation::Point> & value) const;
        void GetSizeArray(com_array<Windows::Foundation::Size> & value) const;
        void GetRectArray(com_array<Windows::Foundation::Rect> & value) const;
    };

    template <typename D>
    struct WINRT_EBO impl_IPropertyValueStatics
    {
        IInspectable CreateEmpty() const;
        IInspectable CreateUInt8(uint8_t value) const;
        IInspectable CreateInt16(int16_t value) const;
        IInspectable CreateUInt16(uint16_t value) const;
        IInspectable CreateInt32(int32_t value) const;
        IInspectable CreateUInt32(uint32_t value) const;
        IInspectable CreateInt64(int64_t value) const;
        IInspectable CreateUInt64(uint64_t value) const;
        IInspectable CreateSingle(float value) const;
        IInspectable CreateDouble(double value) const;
        IInspectable CreateChar16(wchar_t value) const;
        IInspectable CreateBoolean(bool value) const;
        IInspectable CreateString(hstring_view value) const;
        IInspectable CreateInspectable(const IInspectable & value) const;
        IInspectable CreateGuid(GUID value) const;
        IInspectable CreateDateTime(const Windows::Foundation::DateTime & value) const;
        IInspectable CreateTimeSpan(const Windows::Foundation::TimeSpan & value) const;
        IInspectable CreatePoint(const Windows::Foundation::Point & value) const;
        IInspectable CreateSize(const Windows::Foundation::Size & value) const;
        IInspectable CreateRect(const Windows::Foundation::Rect & value) const;
        IInspectable CreateUInt8Array(array_view<const uint8_t> value) const;
        IInspectable CreateInt16Array(array_view<const int16_t> value) const;
        IInspectable CreateUInt16Array(array_view<const uint16_t> value) const;
        IInspectable CreateInt32Array(array_view<const int32_t> value) const;
        IInspectable CreateUInt32Array(array_view<const uint32_t> value) const;
        IInspectable CreateInt64Array(array_view<const int64_t> value) const;
        IInspectable CreateUInt64Array(array_view<const uint64_t> value) const;
        IInspectable CreateSingleArray(array_view<const float> value) const;
        IInspectable CreateDoubleArray(array_view<const double> value) const;
        IInspectable CreateChar16Array(array_view<const wchar_t> value) const;
        IInspectable CreateBooleanArray(array_view<const bool> value) const;
        IInspectable CreateStringArray(array_view<const hstring> value) const;
        IInspectable CreateInspectableArray(array_view<const IInspectable> value) const;
        IInspectable CreateGuidArray(array_view<const GUID> value) const;
        IInspectable CreateDateTimeArray(array_view<const Windows::Foundation::DateTime> value) const;
        IInspectable CreateTimeSpanArray(array_view<const Windows::Foundation::TimeSpan> value) const;
        IInspectable CreatePointArray(array_view<const Windows::Foundation::Point> value) const;
        IInspectable CreateSizeArray(array_view<const Windows::Foundation::Size> value) const;
        IInspectable CreateRectArray(array_view<const Windows::Foundation::Rect> value) const;
    };
}

namespace impl
{
    template <> struct traits<Windows::Foundation::IPropertyValue>
    {
        using abi = ABI::Windows::Foundation::IPropertyValue;
        template <typename D> using consume = Windows::Foundation::impl_IPropertyValue<D>;
    };

    template <> struct traits<Windows::Foundation::IPropertyValueStatics>
    {
        using abi = ABI::Windows::Foundation::IPropertyValueStatics;
        template <typename D> using consume = Windows::Foundation::impl_IPropertyValueStatics<D>;
    };

    template <> struct traits<Windows::Foundation::PropertyValue>
    {
        static constexpr const wchar_t * name() noexcept { return L"Windows.Foundation.PropertyValue"; }
    };
}

namespace Windows::Foundation
{
    struct IPropertyValue :
        IInspectable,
        impl::consume<IPropertyValue>
    {
        IPropertyValue(std::nullptr_t = nullptr) noexcept {}
    };

    struct IPropertyValueStatics :
        IInspectable,
        impl::consume<IPropertyValueStatics>
    {
        IPropertyValueStatics(std::nullptr_t = nullptr) noexcept {}
    };

    struct PropertyValue
    {
        PropertyValue() = delete;
        static IInspectable CreateEmpty();
        static IInspectable CreateUInt8(uint8_t value);
        static IInspectable CreateInt16(int16_t value);
        static IInspectable CreateUInt16(uint16_t value);
        static IInspectable CreateInt32(int32_t value);
        static IInspectable CreateUInt32(uint32_t value);
        static IInspectable CreateInt64(int64_t value);
        static IInspectable CreateUInt64(uint64_t value);
        static IInspectable CreateSingle(float value);
        static IInspectable CreateDouble(double value);
        static IInspectable CreateChar16(wchar_t value);
        static IInspectable CreateBoolean(bool value);
        static IInspectable CreateString(hstring_view value);
        static IInspectable CreateInspectable(const IInspectable & value);
        static IInspectable CreateGuid(GUID value);
        static IInspectable CreateDateTime(const Windows::Foundation::DateTime & value);
        static IInspectable CreateTimeSpan(const Windows::Foundation::TimeSpan & value);
        static IInspectable CreatePoint(const Windows::Foundation::Point & value);
        static IInspectable CreateSize(const Windows::Foundation::Size & value);
        static IInspectable CreateRect(const Windows::Foundation::Rect & value);
        static IInspectable CreateUInt8Array(array_view<const uint8_t> value);
        static IInspectable CreateInt16Array(array_view<const int16_t> value);
        static IInspectable CreateUInt16Array(array_view<const uint16_t> value);
        static IInspectable CreateInt32Array(array_view<const int32_t> value);
        static IInspectable CreateUInt32Array(array_view<const uint32_t> value);
        static IInspectable CreateInt64Array(array_view<const int64_t> value);
        static IInspectable CreateUInt64Array(array_view<const uint64_t> value);
        static IInspectable CreateSingleArray(array_view<const float> value);
        static IInspectable CreateDoubleArray(array_view<const double> value);
        static IInspectable CreateChar16Array(array_view<const wchar_t> value);
        static IInspectable CreateBooleanArray(array_view<const bool> value);
        static IInspectable CreateStringArray(array_view<const hstring> value);
        static IInspectable CreateInspectableArray(array_view<const IInspectable> value);
        static IInspectable CreateGuidArray(array_view<const GUID> value);
        static IInspectable CreateDateTimeArray(array_view<const Windows::Foundation::DateTime> value);
        static IInspectable CreateTimeSpanArray(array_view<const Windows::Foundation::TimeSpan> value);
        static IInspectable CreatePointArray(array_view<const Windows::Foundation::Point> value);
        static IInspectable CreateSizeArray(array_view<const Windows::Foundation::Size> value);
        static IInspectable CreateRectArray(array_view<const Windows::Foundation::Rect> value);
    };
}

namespace impl
{
    template <typename D>
    struct produce<D, Windows::Foundation::IPropertyValue> : produce_base<D, Windows::Foundation::IPropertyValue>
    {
        HRESULT __stdcall get_Type(Windows::Foundation::PropertyType * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().Type());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall get_IsNumericScalar(bool * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().IsNumericScalar());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetUInt8(uint8_t * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetUInt8());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetInt16(int16_t * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetInt16());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetUInt16(uint16_t * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetUInt16());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetInt32(int32_t * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetInt32());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetUInt32(uint32_t * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetUInt32());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetInt64(int64_t * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetInt64());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetUInt64(uint64_t * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetUInt64());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetSingle(float * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetSingle());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetDouble(double * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetDouble());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetChar16(wchar_t * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetChar16());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetBoolean(bool * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetBoolean());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetString(abi_arg_out<hstring> value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetString());
                return S_OK;
            }
            catch (...)
            {
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetGuid(GUID * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetGuid());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetDateTime(abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetDateTime());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetTimeSpan(abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetTimeSpan());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetPoint(abi_arg_out<Windows::Foundation::Point> value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetPoint());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetSize(abi_arg_out<Windows::Foundation::Size> value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetSize());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetRect(abi_arg_out<Windows::Foundation::Rect> value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetRect());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetUInt8Array(uint32_t * __valueSize, abi_arg_out<uint8_t> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetUInt8Array(detach_abi<uint8_t>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetInt16Array(uint32_t * __valueSize, abi_arg_out<int16_t> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetInt16Array(detach_abi<int16_t>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetUInt16Array(uint32_t * __valueSize, abi_arg_out<uint16_t> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetUInt16Array(detach_abi<uint16_t>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetInt32Array(uint32_t * __valueSize, abi_arg_out<int32_t> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetInt32Array(detach_abi<int32_t>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetUInt32Array(uint32_t * __valueSize, abi_arg_out<uint32_t> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetUInt32Array(detach_abi<uint32_t>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetInt64Array(uint32_t * __valueSize, abi_arg_out<int64_t> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetInt64Array(detach_abi<int64_t>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetUInt64Array(uint32_t * __valueSize, abi_arg_out<uint64_t> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetUInt64Array(detach_abi<uint64_t>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetSingleArray(uint32_t * __valueSize, abi_arg_out<float> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetSingleArray(detach_abi<float>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetDoubleArray(uint32_t * __valueSize, abi_arg_out<double> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetDoubleArray(detach_abi<double>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetChar16Array(uint32_t * __valueSize, abi_arg_out<wchar_t> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetChar16Array(detach_abi<wchar_t>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetBooleanArray(uint32_t * __valueSize, abi_arg_out<bool> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetBooleanArray(detach_abi<bool>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetStringArray(uint32_t * __valueSize, abi_arg_out<hstring> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetStringArray(detach_abi<hstring>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetInspectableArray(uint32_t * __valueSize, abi_arg_out<Windows::Foundation::IInspectable> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetInspectableArray(detach_abi<Windows::Foundation::IInspectable>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetGuidArray(uint32_t * __valueSize, abi_arg_out<GUID> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetGuidArray(detach_abi<GUID>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetDateTimeArray(uint32_t * __valueSize, abi_arg_out<Windows::Foundation::DateTime> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetDateTimeArray(detach_abi<Windows::Foundation::DateTime>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetTimeSpanArray(uint32_t * __valueSize, abi_arg_out<Windows::Foundation::TimeSpan> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetTimeSpanArray(detach_abi<Windows::Foundation::TimeSpan>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetPointArray(uint32_t * __valueSize, abi_arg_out<Windows::Foundation::Point> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetPointArray(detach_abi<Windows::Foundation::Point>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetSizeArray(uint32_t * __valueSize, abi_arg_out<Windows::Foundation::Size> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetSizeArray(detach_abi<Windows::Foundation::Size>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetRectArray(uint32_t * __valueSize, abi_arg_out<Windows::Foundation::Rect> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetRectArray(detach_abi<Windows::Foundation::Rect>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }
    };

    template <typename D>
    struct produce<D, Windows::Foundation::IPropertyValueStatics> : produce_base<D, Windows::Foundation::IPropertyValueStatics>
    {
        HRESULT __stdcall abi_CreateEmpty(abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateEmpty());
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateUInt8(uint8_t value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateUInt8(value));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateInt16(int16_t value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateInt16(value));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateUInt16(uint16_t value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateUInt16(value));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateInt32(int32_t value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateInt32(value));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateUInt32(uint32_t value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateUInt32(value));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateInt64(int64_t value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateInt64(value));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateUInt64(uint64_t value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateUInt64(value));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateSingle(float value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateSingle(value));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateDouble(double value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateDouble(value));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateChar16(wchar_t value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateChar16(value));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateBoolean(bool value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateBoolean(value));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateString(abi_arg_in<hstring> value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateString(*reinterpret_cast<const hstring *>(&value)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateInspectable(abi_arg_in<Windows::Foundation::IInspectable> value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateInspectable(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateGuid(GUID value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateGuid(value));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateDateTime(abi_arg_in<Windows::Foundation::DateTime> value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateDateTime(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateTimeSpan(abi_arg_in<Windows::Foundation::TimeSpan> value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateTimeSpan(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreatePoint(abi_arg_in<Windows::Foundation::Point> value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreatePoint(*reinterpret_cast<const Windows::Foundation::Point *>(&value)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateSize(abi_arg_in<Windows::Foundation::Size> value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateSize(*reinterpret_cast<const Windows::Foundation::Size *>(&value)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateRect(abi_arg_in<Windows::Foundation::Rect> value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateRect(*reinterpret_cast<const Windows::Foundation::Rect *>(&value)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateUInt8Array(uint32_t __valueSize, abi_arg_in<uint8_t> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateUInt8Array(array_view<const uint8_t>(value, value + __valueSize)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateInt16Array(uint32_t __valueSize, abi_arg_in<int16_t> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateInt16Array(array_view<const int16_t>(value, value + __valueSize)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateUInt16Array(uint32_t __valueSize, abi_arg_in<uint16_t> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateUInt16Array(array_view<const uint16_t>(value, value + __valueSize)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateInt32Array(uint32_t __valueSize, abi_arg_in<int32_t> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateInt32Array(array_view<const int32_t>(value, value + __valueSize)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateUInt32Array(uint32_t __valueSize, abi_arg_in<uint32_t> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateUInt32Array(array_view<const uint32_t>(value, value + __valueSize)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateInt64Array(uint32_t __valueSize, abi_arg_in<int64_t> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateInt64Array(array_view<const int64_t>(value, value + __valueSize)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateUInt64Array(uint32_t __valueSize, abi_arg_in<uint64_t> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateUInt64Array(array_view<const uint64_t>(value, value + __valueSize)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateSingleArray(uint32_t __valueSize, abi_arg_in<float> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateSingleArray(array_view<const float>(value, value + __valueSize)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateDoubleArray(uint32_t __valueSize, abi_arg_in<double> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateDoubleArray(array_view<const double>(value, value + __valueSize)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateChar16Array(uint32_t __valueSize, abi_arg_in<wchar_t> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateChar16Array(array_view<const wchar_t>(value, value + __valueSize)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateBooleanArray(uint32_t __valueSize, abi_arg_in<bool> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateBooleanArray(array_view<const bool>(value, value + __valueSize)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateStringArray(uint32_t __valueSize, abi_arg_in<hstring> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateStringArray(*reinterpret_cast<const hstring *>(&value)));
                return S_OK;
            }
            catch (...)
            {
                *value = nullptr;
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateInspectableArray(uint32_t __valueSize, abi_arg_in<Windows::Foundation::IInspectable> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateInspectableArray(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value)));
                return S_OK;
            }
            catch (...)
            {
                *value = nullptr;
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateGuidArray(uint32_t __valueSize, abi_arg_in<GUID> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateGuidArray(array_view<const GUID>(value, value + __valueSize)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateDateTimeArray(uint32_t __valueSize, abi_arg_in<Windows::Foundation::DateTime> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateDateTimeArray(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateTimeSpanArray(uint32_t __valueSize, abi_arg_in<Windows::Foundation::TimeSpan> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateTimeSpanArray(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreatePointArray(uint32_t __valueSize, abi_arg_in<Windows::Foundation::Point> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreatePointArray(*reinterpret_cast<const Windows::Foundation::Point *>(&value)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateSizeArray(uint32_t __valueSize, abi_arg_in<Windows::Foundation::Size> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateSizeArray(*reinterpret_cast<const Windows::Foundation::Size *>(&value)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateRectArray(uint32_t __valueSize, abi_arg_in<Windows::Foundation::Rect> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateRectArray(*reinterpret_cast<const Windows::Foundation::Rect *>(&value)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }
    };
}

namespace Windows::Foundation
{
    template <typename D> Windows::Foundation::PropertyType impl_IPropertyValue<D>::Type() const
    {
        Windows::Foundation::PropertyType value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->get_Type(&value));
        return value;
    }

    template <typename D> bool impl_IPropertyValue<D>::IsNumericScalar() const
    {
        bool value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->get_IsNumericScalar(&value));
        return value;
    }

    template <typename D> uint8_t impl_IPropertyValue<D>::GetUInt8() const
    {
        uint8_t value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetUInt8(&value));
        return value;
    }

    template <typename D> int16_t impl_IPropertyValue<D>::GetInt16() const
    {
        int16_t value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetInt16(&value));
        return value;
    }

    template <typename D> uint16_t impl_IPropertyValue<D>::GetUInt16() const
    {
        uint16_t value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetUInt16(&value));
        return value;
    }

    template <typename D> int32_t impl_IPropertyValue<D>::GetInt32() const
    {
        int32_t value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetInt32(&value));
        return value;
    }

    template <typename D> uint32_t impl_IPropertyValue<D>::GetUInt32() const
    {
        uint32_t value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetUInt32(&value));
        return value;
    }

    template <typename D> int64_t impl_IPropertyValue<D>::GetInt64() const
    {
        int64_t value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetInt64(&value));
        return value;
    }

    template <typename D> uint64_t impl_IPropertyValue<D>::GetUInt64() const
    {
        uint64_t value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetUInt64(&value));
        return value;
    }

    template <typename D> float impl_IPropertyValue<D>::GetSingle() const
    {
        float value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetSingle(&value));
        return value;
    }

    template <typename D> double impl_IPropertyValue<D>::GetDouble() const
    {
        double value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetDouble(&value));
        return value;
    }

    template <typename D> wchar_t impl_IPropertyValue<D>::GetChar16() const
    {
        wchar_t value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetChar16(&value));
        return value;
    }

    template <typename D> bool impl_IPropertyValue<D>::GetBoolean() const
    {
        bool value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetBoolean(&value));
        return value;
    }

    template <typename D> hstring impl_IPropertyValue<D>::GetString() const
    {
        hstring value;
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetString(put_abi(value)));
        return value;
    }

    template <typename D> GUID impl_IPropertyValue<D>::GetGuid() const
    {
        GUID value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetGuid(&value));
        return value;
    }

    template <typename D> Windows::Foundation::DateTime impl_IPropertyValue<D>::GetDateTime() const
    {
        Windows::Foundation::DateTime value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetDateTime(put_abi(value)));
        return value;
    }

    template <typename D> Windows::Foundation::TimeSpan impl_IPropertyValue<D>::GetTimeSpan() const
    {
        Windows::Foundation::TimeSpan value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetTimeSpan(put_abi(value)));
        return value;
    }

    template <typename D> Windows::Foundation::Point impl_IPropertyValue<D>::GetPoint() const
    {
        Windows::Foundation::Point value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetPoint(put_abi(value)));
        return value;
    }

    template <typename D> Windows::Foundation::Size impl_IPropertyValue<D>::GetSize() const
    {
        Windows::Foundation::Size value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetSize(put_abi(value)));
        return value;
    }

    template <typename D> Windows::Foundation::Rect impl_IPropertyValue<D>::GetRect() const
    {
        Windows::Foundation::Rect value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetRect(put_abi(value)));
        return value;
    }

    template <typename D> void impl_IPropertyValue<D>::GetUInt8Array(com_array<uint8_t> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetUInt8Array(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetInt16Array(com_array<int16_t> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetInt16Array(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetUInt16Array(com_array<uint16_t> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetUInt16Array(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetInt32Array(com_array<int32_t> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetInt32Array(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetUInt32Array(com_array<uint32_t> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetUInt32Array(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetInt64Array(com_array<int64_t> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetInt64Array(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetUInt64Array(com_array<uint64_t> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetUInt64Array(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetSingleArray(com_array<float> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetSingleArray(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetDoubleArray(com_array<double> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetDoubleArray(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetChar16Array(com_array<wchar_t> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetChar16Array(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetBooleanArray(com_array<bool> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetBooleanArray(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetStringArray(com_array<hstring> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetStringArray(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetInspectableArray(com_array<Windows::Foundation::IInspectable> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetInspectableArray(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetGuidArray(com_array<GUID> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetGuidArray(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetDateTimeArray(com_array<Windows::Foundation::DateTime> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetDateTimeArray(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetTimeSpanArray(com_array<Windows::Foundation::TimeSpan> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetTimeSpanArray(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetPointArray(com_array<Windows::Foundation::Point> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetPointArray(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetSizeArray(com_array<Windows::Foundation::Size> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetSizeArray(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetRectArray(com_array<Windows::Foundation::Rect> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetRectArray(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateEmpty() const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateEmpty(put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateUInt8(uint8_t value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateUInt8(value, put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateInt16(int16_t value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateInt16(value, put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateUInt16(uint16_t value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateUInt16(value, put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateInt32(int32_t value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateInt32(value, put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateUInt32(uint32_t value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateUInt32(value, put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateInt64(int64_t value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateInt64(value, put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateUInt64(uint64_t value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateUInt64(value, put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateSingle(float value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateSingle(value, put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateDouble(double value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateDouble(value, put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateChar16(wchar_t value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateChar16(value, put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateBoolean(bool value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateBoolean(value, put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateString(hstring_view value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateString(get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateInspectable(const Windows::Foundation::IInspectable & value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateInspectable(get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateGuid(GUID value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateGuid(value, put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateDateTime(const Windows::Foundation::DateTime & value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateDateTime(get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateTimeSpan(const Windows::Foundation::TimeSpan & value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateTimeSpan(get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreatePoint(const Windows::Foundation::Point & value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreatePoint(get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateSize(const Windows::Foundation::Size & value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateSize(get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateRect(const Windows::Foundation::Rect & value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateRect(get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateUInt8Array(array_view<const uint8_t> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateUInt8Array(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateInt16Array(array_view<const int16_t> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateInt16Array(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateUInt16Array(array_view<const uint16_t> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateUInt16Array(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateInt32Array(array_view<const int32_t> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateInt32Array(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateUInt32Array(array_view<const uint32_t> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateUInt32Array(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateInt64Array(array_view<const int64_t> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateInt64Array(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateUInt64Array(array_view<const uint64_t> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateUInt64Array(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateSingleArray(array_view<const float> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateSingleArray(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateDoubleArray(array_view<const double> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateDoubleArray(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateChar16Array(array_view<const wchar_t> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateChar16Array(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateBooleanArray(array_view<const bool> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateBooleanArray(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateStringArray(array_view<const hstring> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateStringArray(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateInspectableArray(array_view<const Windows::Foundation::IInspectable> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateInspectableArray(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateGuidArray(array_view<const GUID> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateGuidArray(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateDateTimeArray(array_view<const Windows::Foundation::DateTime> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateDateTimeArray(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateTimeSpanArray(array_view<const Windows::Foundation::TimeSpan> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateTimeSpanArray(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreatePointArray(array_view<const Windows::Foundation::Point> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreatePointArray(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateSizeArray(array_view<const Windows::Foundation::Size> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateSizeArray(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateRectArray(array_view<const Windows::Foundation::Rect> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateRectArray(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateEmpty()
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateEmpty();
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateUInt8(uint8_t value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateUInt8(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateInt16(int16_t value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateInt16(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateUInt16(uint16_t value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateUInt16(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateInt32(int32_t value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateInt32(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateUInt32(uint32_t value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateUInt32(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateInt64(int64_t value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateInt64(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateUInt64(uint64_t value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateUInt64(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateSingle(float value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateSingle(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateDouble(double value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateDouble(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateChar16(wchar_t value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateChar16(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateBoolean(bool value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateBoolean(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateString(hstring_view value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateString(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateInspectable(const Windows::Foundation::IInspectable & value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateInspectable(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateGuid(GUID value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateGuid(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateDateTime(const Windows::Foundation::DateTime & value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateDateTime(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateTimeSpan(const Windows::Foundation::TimeSpan & value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateTimeSpan(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreatePoint(const Windows::Foundation::Point & value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreatePoint(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateSize(const Windows::Foundation::Size & value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateSize(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateRect(const Windows::Foundation::Rect & value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateRect(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateUInt8Array(array_view<const uint8_t> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateUInt8Array(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateInt16Array(array_view<const int16_t> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateInt16Array(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateUInt16Array(array_view<const uint16_t> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateUInt16Array(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateInt32Array(array_view<const int32_t> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateInt32Array(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateUInt32Array(array_view<const uint32_t> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateUInt32Array(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateInt64Array(array_view<const int64_t> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateInt64Array(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateUInt64Array(array_view<const uint64_t> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateUInt64Array(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateSingleArray(array_view<const float> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateSingleArray(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateDoubleArray(array_view<const double> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateDoubleArray(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateChar16Array(array_view<const wchar_t> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateChar16Array(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateBooleanArray(array_view<const bool> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateBooleanArray(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateStringArray(array_view<const hstring> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateStringArray(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateInspectableArray(array_view<const Windows::Foundation::IInspectable> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateInspectableArray(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateGuidArray(array_view<const GUID> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateGuidArray(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateDateTimeArray(array_view<const Windows::Foundation::DateTime> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateDateTimeArray(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateTimeSpanArray(array_view<const Windows::Foundation::TimeSpan> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateTimeSpanArray(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreatePointArray(array_view<const Windows::Foundation::Point> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreatePointArray(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateSizeArray(array_view<const Windows::Foundation::Size> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateSizeArray(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateRectArray(array_view<const Windows::Foundation::Rect> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateRectArray(value);
    }
}

namespace Windows::Foundation
{
    template <typename T> struct IReference;
}

namespace ABI::Windows::Foundation
{
    template <typename T> struct IReference : impl::not_specialized<IReference<T>> {};

    template <typename T>
    struct __declspec(novtable) impl_IReference : IInspectable
    {
        virtual HRESULT __stdcall get_Value(arg_out<T> value) = 0;
    };
}

namespace Windows::Foundation
{
    template <typename D, typename T> struct WINRT_EBO impl_IReference
    {
        T Value() const
        {
            T result{};
            check_hresult((*(abi<IReference<T>> **)&static_cast<const IReference<T> &>(static_cast<const D &>(*this)))->get_Value(put_abi(result)));
            return result;
        }
    };
}

namespace impl
{
    template <typename T> struct traits<Windows::Foundation::IReference<T>>
    {
        using abi = ABI::Windows::Foundation::IReference<abi<T>>;
        template <typename D> using consume = Windows::Foundation::impl_IReference<D, T>;
    };

    template <typename D, typename T>
    struct produce<D, Windows::Foundation::IReference<T>> : produce_base<D, Windows::Foundation::IReference<T>>
    {
        HRESULT __stdcall get_Value(abi_arg_out<T> value) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().Value());
                return S_OK;
            }
            catch (...)
            {
                clear_abi(value);
                return to_hresult();
            }
        }
    };

    template <typename T>
    struct reference : implements<reference<T>, Windows::Foundation::IReference<T>, Windows::Foundation::IPropertyValue>
    {
        reference(T const & value)
        {
            m_value = value;
        }

        T Value() const
        {
            return m_value;
        }

        Windows::Foundation::PropertyType Type() { throw hresult_not_implemented(); }
        bool IsNumericScalar() { throw hresult_not_implemented(); }
        uint8_t GetUInt8() { throw hresult_not_implemented(); }
        int16_t GetInt16() { throw hresult_not_implemented(); }
        uint16_t GetUInt16() { throw hresult_not_implemented(); }
        int32_t GetInt32() { throw hresult_not_implemented(); }
        uint32_t GetUInt32() { throw hresult_not_implemented(); }
        int64_t GetInt64() { throw hresult_not_implemented(); }
        uint64_t GetUInt64() { throw hresult_not_implemented(); }
        float GetSingle() { throw hresult_not_implemented(); }
        double GetDouble() { throw hresult_not_implemented(); }
        wchar_t GetChar16() { throw hresult_not_implemented(); }
        bool GetBoolean() { throw hresult_not_implemented(); }
        hstring GetString() { throw hresult_not_implemented(); }
        GUID GetGuid() { throw hresult_not_implemented(); }
        Windows::Foundation::DateTime GetDateTime() { throw hresult_not_implemented(); }
        Windows::Foundation::TimeSpan GetTimeSpan() { throw hresult_not_implemented(); }
        Windows::Foundation::Point GetPoint() { throw hresult_not_implemented(); }
        Windows::Foundation::Size GetSize() { throw hresult_not_implemented(); }
        Windows::Foundation::Rect GetRect() { throw hresult_not_implemented(); }
        void GetUInt8Array(com_array<uint8_t> &) { throw hresult_not_implemented(); }
        void GetInt16Array(com_array<int16_t> &) { throw hresult_not_implemented(); }
        void GetUInt16Array(com_array<uint16_t> &) { throw hresult_not_implemented(); }
        void GetInt32Array(com_array<int32_t> &) { throw hresult_not_implemented(); }
        void GetUInt32Array(com_array<uint32_t> &) { throw hresult_not_implemented(); }
        void GetInt64Array(com_array<int64_t> &) { throw hresult_not_implemented(); }
        void GetUInt64Array(com_array<uint64_t> &) { throw hresult_not_implemented(); }
        void GetSingleArray(com_array<float> &) { throw hresult_not_implemented(); }
        void GetDoubleArray(com_array<double> &) { throw hresult_not_implemented(); }
        void GetChar16Array(com_array<wchar_t> &) { throw hresult_not_implemented(); }
        void GetBooleanArray(com_array<bool> &) { throw hresult_not_implemented(); }
        void GetStringArray(com_array<hstring> &) { throw hresult_not_implemented(); }
        void GetInspectableArray(com_array<Windows::Foundation::IInspectable> &) { throw hresult_not_implemented(); }
        void GetGuidArray(com_array<GUID> &) { throw hresult_not_implemented(); }
        void GetDateTimeArray(com_array<Windows::Foundation::DateTime> &) { throw hresult_not_implemented(); }
        void GetTimeSpanArray(com_array<Windows::Foundation::TimeSpan> &) { throw hresult_not_implemented(); }
        void GetPointArray(com_array<Windows::Foundation::Point> &) { throw hresult_not_implemented(); }
        void GetSizeArray(com_array<Windows::Foundation::Size> &) { throw hresult_not_implemented(); }
        void GetRectArray(com_array<Windows::Foundation::Rect> &) { throw hresult_not_implemented(); }

    private:

        T m_value;
    };

    template <typename T>
    struct reference_traits
    {
        static Windows::Foundation::IInspectable make(T const & val) { return winrt::make<impl::reference<T>>(val); }
    };

    template <>
    struct reference_traits <uint8_t>
    {
        static Windows::Foundation::IInspectable make(uint8_t val) { return Windows::Foundation::PropertyValue::CreateUInt8(val); }
    };

    template <>
    struct reference_traits <uint16_t>
    {
        static Windows::Foundation::IInspectable make(uint16_t val) { return Windows::Foundation::PropertyValue::CreateUInt16(val); }
    };

    template <>
    struct reference_traits <int16_t>
    {
        static Windows::Foundation::IInspectable make(int16_t val) { return Windows::Foundation::PropertyValue::CreateInt16(val); }
    };

    template <>
    struct reference_traits <uint32_t>
    {
        static Windows::Foundation::IInspectable make(uint32_t val) { return Windows::Foundation::PropertyValue::CreateUInt32(val); }
    };

    template <>
    struct reference_traits <int32_t>
    {
        static Windows::Foundation::IInspectable make(int32_t val) { return Windows::Foundation::PropertyValue::CreateInt32(val); }
    };

    template <>
    struct reference_traits <uint64_t>
    {
        static Windows::Foundation::IInspectable make(uint64_t val) { return Windows::Foundation::PropertyValue::CreateUInt64(val); }
    };

    template <>
    struct reference_traits <int64_t>
    {
        static Windows::Foundation::IInspectable make(int64_t val) { return Windows::Foundation::PropertyValue::CreateInt64(val); }
    };

    template <>
    struct reference_traits <float>
    {
        static Windows::Foundation::IInspectable make(float val) { return Windows::Foundation::PropertyValue::CreateSingle(val); }
    };

    template <>
    struct reference_traits <double>
    {
        static Windows::Foundation::IInspectable make(double val) { return Windows::Foundation::PropertyValue::CreateDouble(val); }
    };

    template <>
    struct reference_traits <wchar_t>
    {
        static Windows::Foundation::IInspectable make(wchar_t val) { return Windows::Foundation::PropertyValue::CreateChar16(val); }
    };

    template <>
    struct reference_traits <bool>
    {
        static Windows::Foundation::IInspectable make(bool val) { return Windows::Foundation::PropertyValue::CreateBoolean(val); }
    };

    template <>
    struct reference_traits <hstring>
    {
        static Windows::Foundation::IInspectable make(hstring const & val) { return Windows::Foundation::PropertyValue::CreateString(val); }
    };

    template <>
    struct reference_traits <hstring_view>
    {
        static Windows::Foundation::IInspectable make(hstring_view val) { return Windows::Foundation::PropertyValue::CreateString(val); }
    };

    template <>
    struct reference_traits <Windows::Foundation::IInspectable>
    {
        static Windows::Foundation::IInspectable make(Windows::Foundation::IInspectable const & val) { return Windows::Foundation::PropertyValue::CreateInspectable(val); }
    };

    template <>
    struct reference_traits <GUID>
    {
        static Windows::Foundation::IInspectable make(GUID const & val) { return Windows::Foundation::PropertyValue::CreateGuid(val); }
    };

    template <>
    struct reference_traits <Windows::Foundation::DateTime>
    {
        static Windows::Foundation::IInspectable make(Windows::Foundation::DateTime val) { return Windows::Foundation::PropertyValue::CreateDateTime(val); }
    };

    template <>
    struct reference_traits <Windows::Foundation::TimeSpan>
    {
        static Windows::Foundation::IInspectable make(Windows::Foundation::TimeSpan val) { return Windows::Foundation::PropertyValue::CreateTimeSpan(val); }
    };

    template <>
    struct reference_traits  <Windows::Foundation::Point>
    {
        static Windows::Foundation::IInspectable make(Windows::Foundation::Point const & val) { return Windows::Foundation::PropertyValue::CreatePoint(val); }
    };

    template <>
    struct reference_traits <Windows::Foundation::Size>
    {
        static Windows::Foundation::IInspectable make(Windows::Foundation::Size const & val) { return Windows::Foundation::PropertyValue::CreateSize(val); }
    };

    template <>
    struct reference_traits <Windows::Foundation::Rect>
    {
        static Windows::Foundation::IInspectable make(Windows::Foundation::Rect const & val) { return Windows::Foundation::PropertyValue::CreateRect(val); }
    };
}

namespace Windows::Foundation
{
    template <typename T>
    struct WINRT_EBO IReference :
        IInspectable,
        impl::consume<IReference<T>>
    {
        IReference<T>(std::nullptr_t = nullptr) noexcept {}

        IReference<T>(T const & val)
        {
            this->m_ptr = detach_abi((impl::reference_traits<T>::make(val)).template as<abi<IReference<T>>>());
        }
    };
}

template <typename T>
using optional = Windows::Foundation::IReference<T>;

}

namespace std
{
    template <> struct hash<winrt::hstring>
    {
        size_t operator()(const winrt::hstring & value) const noexcept
        {
#ifdef WINRT_64
            const size_t fnv_offset_basis = 14695981039346656037ULL;
            const size_t fnv_prime = 1099511628211ULL;
#else
            const size_t fnv_offset_basis = 2166136261U;
            const size_t fnv_prime = 16777619U;
#endif

            uint32_t length = 0;

            const uint8_t * const buffer = reinterpret_cast<const uint8_t *>(WindowsGetStringRawBuffer(get_abi(value),
                                                                                                       &length));

            length *= sizeof(wchar_t);
            size_t result = fnv_offset_basis;

            for (size_t next = 0; next < length; ++next)
            {
                result ^= buffer[next];
                result *= fnv_prime;
            }

            return result;
        }
    };
}

#ifdef WINRT_ASYNC

namespace std::experimental {

template <typename ... Args>
struct coroutine_traits<winrt::fire_and_forget, Args ...>
{
    struct promise_type
    {
        winrt::fire_and_forget get_return_object() const noexcept
        {
            return{};
        }

        void return_void() const noexcept
        {
        }

        suspend_never initial_suspend() const noexcept
        {
            return{};
        }

        suspend_never final_suspend() const noexcept
        {
            return{};
        }
    };
};

template <typename ... Args>
struct coroutine_traits<winrt::Windows::Foundation::IAsyncAction, Args ...>
{
    struct promise_type : winrt::impl::promise_base<promise_type, winrt::Windows::Foundation::IAsyncAction,
        winrt::Windows::Foundation::AsyncActionCompletedHandler>
    {
        void GetResults()
        {
            const winrt::impl::lock_guard guard(this->m_lock);

            if (this->m_status == AsyncStatus::Completed)
            {
                return;
            }

            if (this->m_status == AsyncStatus::Error || this->m_status == AsyncStatus::Canceled)
            {
                rethrow_exception(*reinterpret_cast<exception_ptr *>(&this->m_exception));
            }

            WINRT_ASSERT(this->m_status == AsyncStatus::Started);
            throw winrt::hresult_illegal_method_call();
        }

        void return_void()
        {
            winrt::Windows::Foundation::AsyncActionCompletedHandler handler;
            winrt::Windows::Foundation::AsyncStatus status;

            {
                const winrt::impl::lock_guard guard(this->m_lock);

                if (this->m_status == AsyncStatus::Started)
                {
                    this->m_status = AsyncStatus::Completed;
                }
                else
                {
                    WINRT_ASSERT(this->m_status == AsyncStatus::Canceled);
                    new (&this->m_exception) exception_ptr(make_exception_ptr(winrt::hresult_canceled()));
                }

                handler = std::move(this->m_completed);
                status = this->m_status;
            }

            if (handler)
            {
                handler(*this, status);
            }
        }

        template <typename Expression>
        Expression && await_transform(Expression && expression)
        {
            if (this->Status() == AsyncStatus::Canceled)
            {
                throw winrt::hresult_canceled();
            }

            return forward<Expression>(expression);
        }

        winrt::impl::cancellation_token<promise_type> await_transform(winrt::get_cancellation_token_t) noexcept
        {
            return{ this };
        }
    };
};

template <typename TProgress, typename ... Args>
struct coroutine_traits<winrt::Windows::Foundation::IAsyncActionWithProgress<TProgress>, Args ...>
{
    struct promise_type : winrt::impl::promise_base<promise_type, winrt::Windows::Foundation::IAsyncActionWithProgress<TProgress>,
        winrt::Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>>
    {
        using ProgressHandler = winrt::Windows::Foundation::AsyncActionProgressHandler<TProgress>;

        void Progress(const ProgressHandler & handler)
        {
            const winrt::impl::lock_guard guard(this->m_lock);
            m_progress = handler;
        }

        ProgressHandler Progress()
        {
            const winrt::impl::lock_guard guard(this->m_lock);
            return m_progress;
        }

        void GetResults()
        {
            const winrt::impl::lock_guard guard(this->m_lock);

            if (this->m_status == AsyncStatus::Completed)
            {
                return;
            }

            if (this->m_status == AsyncStatus::Error || this->m_status == AsyncStatus::Canceled)
            {
                rethrow_exception(*reinterpret_cast<exception_ptr *>(&this->m_exception));
            }

            WINRT_ASSERT(this->m_status == AsyncStatus::Started);
            throw winrt::hresult_illegal_method_call();
        }

        void return_void()
        {
            winrt::Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress> handler;
            winrt::Windows::Foundation::AsyncStatus status;

            {
                const winrt::impl::lock_guard guard(this->m_lock);

                if (this->m_status == AsyncStatus::Started)
                {
                    this->m_status = AsyncStatus::Completed;
                }
                else
                {
                    WINRT_ASSERT(this->m_status == AsyncStatus::Canceled);
                    new (&this->m_exception) exception_ptr(make_exception_ptr(winrt::hresult_canceled()));
                }

                handler = std::move(this->m_completed);
                status = this->m_status;
            }

            if (handler)
            {
                handler(*this, status);
            }
        }

        void set_progress(const TProgress & result)
        {
            if (auto handler = Progress())
            {
                handler(*this, result);
            }
        }

        template <typename Expression>
        Expression && await_transform(Expression && expression)
        {
            if (this->Status() == AsyncStatus::Canceled)
            {
                throw winrt::hresult_canceled();
            }

            return forward<Expression>(expression);
        }

        winrt::impl::cancellation_token<promise_type> await_transform(winrt::get_cancellation_token_t) noexcept
        {
            return{ this };
        }

        winrt::impl::progress_token<promise_type, TProgress> await_transform(winrt::get_progress_token_t) noexcept
        {
            return{ this };
        }

        ProgressHandler m_progress;
    };
};

template <typename TResult, typename ... Args>
struct coroutine_traits<winrt::Windows::Foundation::IAsyncOperation<TResult>, Args ...>
{
    struct promise_type : winrt::impl::promise_base<promise_type, winrt::Windows::Foundation::IAsyncOperation<TResult>,
        winrt::Windows::Foundation::AsyncOperationCompletedHandler<TResult>>
    {
        TResult GetResults()
        {
            const winrt::impl::lock_guard guard(this->m_lock);

            if (this->m_status == AsyncStatus::Completed)
            {
                return m_result;
            }

            if (this->m_status == AsyncStatus::Error || this->m_status == AsyncStatus::Canceled)
            {
                rethrow_exception(*reinterpret_cast<exception_ptr *>(&this->m_exception));
            }

            WINRT_ASSERT(this->m_status == AsyncStatus::Started);
            throw winrt::hresult_illegal_method_call();
        }

        void return_value(const TResult & result)
        {
            winrt::Windows::Foundation::AsyncOperationCompletedHandler<TResult> handler;
            winrt::Windows::Foundation::AsyncStatus status;

            {
                const winrt::impl::lock_guard guard(this->m_lock);

                if (this->m_status == AsyncStatus::Started)
                {
                    this->m_status = AsyncStatus::Completed;
                    m_result = result;
                }
                else
                {
                    WINRT_ASSERT(this->m_status == AsyncStatus::Canceled);
                    new (&this->m_exception) exception_ptr(make_exception_ptr(winrt::hresult_canceled()));
                }

                handler = std::move(this->m_completed);
                status = this->m_status;
            }

            if (handler)
            {
                handler(*this, status);
            }
        }

        template <typename Expression>
        Expression && await_transform(Expression && expression)
        {
            if (this->Status() == AsyncStatus::Canceled)
            {
                throw winrt::hresult_canceled();
            }

            return forward<Expression>(expression);
        }

        winrt::impl::cancellation_token<promise_type> await_transform(winrt::get_cancellation_token_t) noexcept
        {
            return{ this };
        }

        TResult m_result{ winrt::impl::empty_value<TResult>() };
    };
};

template <typename TResult, typename TProgress, typename ... Args>
struct coroutine_traits<winrt::Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>, Args ...>
{
    struct promise_type : winrt::impl::promise_base<promise_type, winrt::Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>,
        winrt::Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>>
    {
        using ProgressHandler = winrt::Windows::Foundation::AsyncOperationProgressHandler<TResult, TProgress>;

        void Progress(const ProgressHandler & handler)
        {
            const winrt::impl::lock_guard guard(this->m_lock);
            m_progress = handler;
        }

        ProgressHandler Progress()
        {
            const winrt::impl::lock_guard guard(this->m_lock);
            return m_progress;
        }

        TResult GetResults()
        {
            const winrt::impl::lock_guard guard(this->m_lock);

            if (this->m_status == AsyncStatus::Completed)
            {
                return m_result;
            }

            if (this->m_status == AsyncStatus::Error || this->m_status == AsyncStatus::Canceled)
            {
                rethrow_exception(*reinterpret_cast<exception_ptr *>(&this->m_exception));
            }

            WINRT_ASSERT(this->m_status == AsyncStatus::Started);
            throw winrt::hresult_illegal_method_call();
        }

        void return_value(const TResult & result)
        {
            winrt::Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress> handler;
            winrt::Windows::Foundation::AsyncStatus status;

            {
                const winrt::impl::lock_guard guard(this->m_lock);

                if (this->m_status == AsyncStatus::Started)
                {
                    this->m_status = AsyncStatus::Completed;
                    m_result = result;
                }
                else
                {
                    WINRT_ASSERT(this->m_status == AsyncStatus::Canceled);
                    new (&this->m_exception) exception_ptr(make_exception_ptr(winrt::hresult_canceled()));
                }

                handler = std::move(this->m_completed);
                status = this->m_status;
            }

            if (handler)
            {
                handler(*this, status);
            }
        }

        void set_progress(const TProgress & result)
        {
            if (auto handler = Progress())
            {
                handler(*this, result);
            }
        }

        template <typename Expression>
        Expression && await_transform(Expression && expression)
        {
            if (this->Status() == AsyncStatus::Canceled)
            {
                throw winrt::hresult_canceled();
            }

            return forward<Expression>(expression);
        }

        winrt::impl::cancellation_token<promise_type> await_transform(winrt::get_cancellation_token_t) noexcept
        {
            return{ this };
        }

        winrt::impl::progress_token<promise_type, TProgress> await_transform(winrt::get_progress_token_t) noexcept
        {
            return{ this };
        }

        TResult m_result{ winrt::impl::empty_value<TResult>() };
        ProgressHandler m_progress;
    };
};

}

#endif
