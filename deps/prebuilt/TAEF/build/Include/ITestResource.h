/*
* Copyright (c) Microsoft Corporation. All rights reserved.
*
*/
#pragma once
#include "unknwn.h"

namespace WEX { namespace TestExecution
{
    namespace TestResourceProperty
    {
        // the following are reserved and must have property for any TestResource definition
        static const wchar_t c_szName[] = L"Name";
        static const wchar_t c_szId[] = L"Id";
        static const wchar_t c_szGuid[] = L"GUID";
        static const wchar_t c_szType[] = L"Type";
    }

    struct __declspec(novtable) __declspec(uuid("79098e4c-b78d-434b-854d-2b59f5c4acc5")) ITestResource : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetGuid(GUID* pGuid) = 0;
        virtual HRESULT STDMETHODCALLTYPE SetGuid(GUID guid) = 0;
        virtual HRESULT STDMETHODCALLTYPE GetValue(BSTR name, BSTR* pValue) = 0;
        virtual HRESULT STDMETHODCALLTYPE SetValue(BSTR name, BSTR value) = 0;
    };
} /*namespace TestExecution*/ } /*namespace WEX*/