/*
* Copyright (c) Microsoft Corporation.  All Rights Reserved.
*
* Provides typedefs for commonly used types, and template utilities and helpers for working with C++ types
*          
*/
#pragma once

#include <specstrings.h>

#pragma push_macro("_Return_type_success_")

#if !defined(_Return_type_success_)
#define _Return_type_success_(s)
#endif

typedef _Return_type_success_(return >= 0) long HRESULT;
typedef int BOOL;
typedef long LONG;
typedef unsigned long DWORD;
typedef DWORD ULONG;
typedef void* HANDLE;
typedef unsigned long (__stdcall *LPHANDLER_FUNCTION_EX)(unsigned long control, unsigned long eventType, void* pEventData, void* pContext);

#pragma pop_macro("_Return_type_success_")

namespace WEX { namespace Common
{
    struct NullType{};
    struct EmptyType{};
    struct TerminatorType{};

    template <class T, class U>
    class Conversion
    {
        typedef char SmallSize;
        struct BigSize 
        { 
            SmallSize a[2]; 
        };

        static SmallSize Test(const U&);
        static BigSize Test(...);
        static const T& MakeT();

    public:
        static const bool exists = (sizeof(Test(MakeT()))) == (sizeof(SmallSize));
        static const bool sameType = false;
    };

    template <>
    class Conversion<void, void>
    {
    public:
        static const bool exists = true;
        static const bool sameType = true;
    };

    template <typename T1, typename T2>
    class AreSameType
    {
    public:
        static const bool value = false;
    };

    template <typename T>
    class AreSameType<T, T>
    {
    public:
        static const bool value = true;
    };

    template <typename T>
    class MakeReference
    {
    public:
        typedef T& Result;
    };

    template <typename T>
    class MakeReference<T&>
    {
    public:
        typedef T& Result;
    };

    template <>
    class MakeReference<NullType>
    {
    public:
        typedef NullType Result;
    };

    template <typename T>
    class RemoveReference
    {
    public:
        typedef T Result;
    };

    template <typename T>
    class RemoveReference<T&>
    {
    public:
        typedef T Result;
    };

    template<typename T>
    struct MakeConst
    {
        typedef const T Type;
    };

    template<typename T>
    struct MakeConst<T&>
    {
        typedef const T& Type;
    };

    template<typename T>
    struct MakeConst<T*>
    {
        typedef const T* Type;
    };

    template<typename T>
    struct RemoveConst
    {
        typedef T Type;
    };

    template<typename T>
    struct RemoveConst<const T>
    {
        typedef T Type;
    };

    template<typename T>
    struct RemoveConst<T&>
    {
        typedef T& Type;
    };

    template<typename T>
    struct RemoveConst<const T&>
    {
        typedef T& Type;
    };

    template<typename T>
    struct RemoveConst<T*>
    {
        typedef T* Type;
    };

    template<typename T>
    struct RemoveConst<const T*>
    {
        typedef T* Type;
    };

    template<typename T>
    class AlignedStorageFactory
    {
        template<size_t Size, size_t Align>
        struct Storage;

        template<size_t Size>
        struct Storage<Size, 0>
        {
        protected:
            __declspec(align(1)) unsigned char m_raw[Size];
        };

        template<size_t Size>
        struct Storage<Size, 1>
        {
        protected:
            __declspec(align(1)) unsigned char m_raw[Size];
        };

        template<size_t Size>
        struct Storage<Size, 2>
        {
        protected:
            __declspec(align(2)) unsigned char m_raw[Size];
        };

        template<size_t Size>
        struct Storage<Size, 4>
        {
        protected:
            __declspec(align(4)) unsigned char m_raw[Size];
        };

        template<size_t Size>
        struct Storage<Size, 8>
        {
        protected:
            __declspec(align(8)) unsigned char m_raw[Size];
        };

        template<size_t Size>
        struct Storage<Size, 16>
        {
        protected:
            __declspec(align(16)) unsigned char m_raw[Size];
        };

        template<size_t Size>
        struct Storage<Size, 32>
        {
        protected:
            __declspec(align(32)) unsigned char m_raw[Size];
        };

        template<size_t Size>
        struct Storage<Size, 64>
        {
        protected:
            __declspec(align(64)) unsigned char m_raw[Size];
        };

        template<size_t Size>
        struct Storage<Size, 128>
        {
        protected:
            __declspec(align(128)) unsigned char m_raw[Size];
        };

        template<size_t Size>
        struct Storage<Size, 256>
        {
        protected:
            __declspec(align(256)) unsigned char m_raw[Size];
        };

        // not implemented
        AlignedStorageFactory();

    public:
        typedef Storage<sizeof(T), __alignof(T)> Type;
    };
} /* namespace Common */ } /* namespace WEX */
