//----------------------------------------------------------------------------------------------------------------------
/// \file
/// <summary> API and data types for using data in data driven native tests </summary>
// Copyright (c) Microsoft Corporation.  All Rights Reserved.
//----------------------------------------------------------------------------------------------------------------------
#pragma once
#include "TE.Common.h"
#include "WexDebug.h"

#pragma push_macro("SEALED")
#undef SEALED

#if _MSC_VER >= 1800
# define SEALED final
#elif _MSC_VER >= 1400
# define SEALED sealed
#elif defined(_MSC_VER)
# define SEALED
#else
# define SEALED final
#endif

#pragma push_macro("_In_z_")
#pragma push_macro("_Outptr_")

#if !defined(_In_z_)
#define _In_z_
#endif

#if !defined(_Outptr_)
#define _Outptr_
#endif

// Forward define 'IStream'
typedef interface IStream IStream;

namespace WEX { namespace TestExecution
{
    class TestDataArrayPrivate;

    /// <summary>
    ///  A helper class to work with arrays in data driven testing
    /// </summary>
    /// \code
    /// Example:
    ///
    ///  TestDataArray<int> sizes;
    ///  if (SUCCEEDED(TestData::TryGetValue(L"size", sizes)))
    ///  {
    ///      size_t count = sizes.GetSize();
    ///      for (size_t i = 0; i < count; ++i)
    ///      {
    ///          Log::Comment(String().Format(L"Size[%d] retrieved was %d", i, sizes[i]));
    ///      }
    ///  }
    /// \endcode
    template <typename T>
    class TECOMMON_API TestDataArray SEALED
    {
        friend class TestDataArrayPrivate;

    public:
        TestDataArray();
        ~TestDataArray();
        const size_t GetSize() const;
        T& operator[](size_t index);
        const T& operator[](size_t index) const;

    private:
        void Allocate(size_t elements);
        TestDataArray(const TestDataArray<T>& other);
        TestDataArray<T>& operator=(TestDataArray<T>& other);
        void Free();
        T* Detach();

        /// \internal
        /// we need a way to get an address because operator& is overloaded
        TestDataArray<T>* This() {return this;}

        size_t m_size;
        T* m_p;
    };

    namespace Private
    {
        /// \internal
        /// WEX::TestExecution::Private::TestData must be a templatized *class* so that we can dll export explicit 
        /// instantiations.
        template <typename T>
        class TECOMMON_API TestData SEALED
        {
        public:
            /// Tries to get the requested value in the requested format
            static HRESULT __stdcall TryGetValue(_In_z_ const wchar_t* pszString, T& result);
            /// TestDataArray specific TestData implementation
            static HRESULT __stdcall TryGetValue(_In_z_ const wchar_t* pszString, TestDataArray<T>& results);

            #ifdef TECOMMON_EXPORTS
            static HRESULT __stdcall TryGetValue(_In_z_ const __wchar_t* pszString, T& result);
            static HRESULT __stdcall TryGetValue(_In_z_ const __wchar_t* pszString, TestDataArray<T>& results);
            #endif
        };

        class TECOMMON_API XmlTestData SEALED
        {
        public:
            static HRESULT __stdcall TryGetValue(_In_z_ const wchar_t* pszString, _Outptr_ IStream** result);

            #ifdef TECOMMON_EXPORTS
            static HRESULT __stdcall TryGetValue(_In_z_ const __wchar_t* pszString, _Outptr_ IStream** result);
            #endif
        };

        template <typename T1, typename T2>
        class AreSameType
        {
        public:
            static const bool value = false;
        };

        template <typename T1>
        class AreSameType<T1, T1>
        {
        public:
            static const bool value = true;
        };
    }

    /// <summary>
    ///  Data driven test data retrival class
    /// </summary>
    /// \internal
    /// WEX::TestExecution::TestData provides templatized *methods* to allow compiler type inference, and simply routes 
    /// the call to the matching WEX::TestExecution::Private::TestData<T> instantiation.
    class TestData
    {
    public:

        /// <summary>
        ///  Data driven test data retrival API for basic types
        /// </summary>
        template <typename T>
        static HRESULT __stdcall TryGetValue(_In_z_ const wchar_t* pszString, T& result)
        {
            COMPILE_TIME_CHECK_V2((Private::AreSameType<int, T>::value || Private::AreSameType<size_t, T>::value || Private::AreSameType<bool, T>::value ||
                                Private::AreSameType<float, T>::value || Private::AreSameType<double, T>::value || Private::AreSameType<DWORD, T>::value ||
                                Private::AreSameType<__int64, T>::value || Private::AreSameType<unsigned __int64, T>::value || Private::AreSameType<unsigned int, T>::value ||
                                Private::AreSameType<WEX::Common::String, T>::value || Private::AreSameType<WEX::Common::NoThrowString, T>::value),
                                "Attempt to use TestData::TryGetValue with an unsupported type", 
                                Attempt_to_use_TestData_TryGetValue_with_an_unsupported_type);
            return Private::TestData<T>::TryGetValue(pszString, result);
        }

        static HRESULT __stdcall TryGetValue(_In_z_ const wchar_t* pszString, _Outptr_ IStream** result)
        {
            return Private::XmlTestData::TryGetValue(pszString, result);
        }

        /// <summary>
        ///  Data driven test data retrival API for array types
        /// </summary>
        template<typename T>
        static HRESULT __stdcall TryGetValue(_In_z_ const wchar_t* pszString, TestDataArray<T>& results)
        {
            COMPILE_TIME_CHECK_V2((Private::AreSameType<int, T>::value || Private::AreSameType<size_t, T>::value || Private::AreSameType<bool, T>::value ||
                                Private::AreSameType<float, T>::value || Private::AreSameType<double, T>::value || Private::AreSameType<DWORD, T>::value ||
                                Private::AreSameType<__int64, T>::value || Private::AreSameType<unsigned __int64, T>::value || Private::AreSameType<unsigned int, T>::value ||
                                Private::AreSameType<WEX::Common::String, T>::value || Private::AreSameType<WEX::Common::NoThrowString, T>::value),
                                "Attempt to use TestData::TryGetValue with an unsupported type for TestDataArray", 
                                Attempt_to_use_TestData_TryGetValue_with_an_unsupported_type_for_TestDataArray);
            return Private::TestData<T>::TryGetValue(pszString, results);
        }

        #ifdef TECOMMON_EXPORTS
        template <typename T>
        static HRESULT __stdcall TryGetValue(_In_z_ const __wchar_t* pszString, T& result)
        {
            COMPILE_TIME_CHECK_V2((Private::AreSameType<int, T>::value || Private::AreSameType<size_t, T>::value || Private::AreSameType<bool, T>::value ||
                                Private::AreSameType<float, T>::value || Private::AreSameType<double, T>::value || Private::AreSameType<DWORD, T>::value ||
                                Private::AreSameType<__int64, T>::value || Private::AreSameType<unsigned __int64, T>::value || Private::AreSameType<unsigned int, T>::value ||
                                Private::AreSameType<WEX::Common::String, T>::value || Private::AreSameType<WEX::Common::NoThrowString, T>::value),
                                "Attempt to use TestData::TryGetValue with an unsupported type", 
                                Attempt_to_use_TestData_TryGetValue_with_an_unsupported_type);
            return Private::TestData<T>::TryGetValue(pszString, result);
        }

        static HRESULT __stdcall TryGetValue(_In_z_ const __wchar_t* pszString, _Outptr_ IStream** result)
        {
            return Private::XmlTestData::TryGetValue(pszString, result);
        }

        /// <summary>
        ///  Data driven test data retrival API for array types
        /// </summary>
        template<typename T>
        static HRESULT __stdcall TryGetValue(_In_z_ const __wchar_t* pszString, TestDataArray<T>& results)
        {
            COMPILE_TIME_CHECK_V2((Private::AreSameType<int, T>::value || Private::AreSameType<size_t, T>::value || Private::AreSameType<bool, T>::value ||
                                Private::AreSameType<float, T>::value || Private::AreSameType<double, T>::value || Private::AreSameType<DWORD, T>::value ||
                                Private::AreSameType<__int64, T>::value || Private::AreSameType<unsigned __int64, T>::value || Private::AreSameType<unsigned int, T>::value ||
                                Private::AreSameType<WEX::Common::String, T>::value || Private::AreSameType<WEX::Common::NoThrowString, T>::value),
                                "Attempt to use TestData::TryGetValue with an unsupported type for TestDataArray", 
                                Attempt_to_use_TestData_TryGetValue_with_an_unsupported_type_for_TestDataArray);
            return Private::TestData<T>::TryGetValue(pszString, results);
        }
        #endif
    };
} /* TestExecution */ } /* namespace WEX */

#pragma pop_macro("_In_z_")
#pragma pop_macro("_Outptr_")
#pragma pop_macro("SEALED")
