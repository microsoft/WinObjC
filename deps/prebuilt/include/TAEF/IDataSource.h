//----------------------------------------------------------------------------------------------------------------------
/// \file
/// <summary>COM interfaces for developing custom data sources.</summary>
// Copyright (c) Microsoft Corporation.  All Rights Reserved.
//----------------------------------------------------------------------------------------------------------------------
#pragma once

#include <OaIdl.h> // for SAFEARRAY
#include <Unknwn.h> // for IUnknown
#include <WinNT.h> // for HRESULT
#include <WTypes.h> // for BSTR

#pragma push_macro("_COM_Outptr_result_maybenull_ ")

#if !defined(_COM_Outptr_result_maybenull_ )
#define _COM_Outptr_result_maybenull_ 
#endif

namespace WEX { namespace TestExecution
{
    struct __declspec(novtable) __declspec(uuid("A6F2A98F-1122-4C1C-B3F6-AD6AF2ECB137")) IDataRow abstract : public IUnknown
    {
        virtual HRESULT STDMETHODCALLTYPE GetTestData(BSTR pszName, _COM_Outptr_result_maybenull_ SAFEARRAY** ppData) = 0;
        virtual HRESULT STDMETHODCALLTYPE GetMetadataNames(_COM_Outptr_result_maybenull_ SAFEARRAY** ppMetadataNames) = 0;
        virtual HRESULT STDMETHODCALLTYPE GetMetadata(BSTR pszName, _COM_Outptr_result_maybenull_ SAFEARRAY** ppData) = 0;
        virtual HRESULT STDMETHODCALLTYPE GetName(_COM_Outptr_result_maybenull_ BSTR* ppszRowName) = 0;
    };

    struct __declspec(novtable) __declspec(uuid("C49E4CD3-89DE-42DC-8737-A6867DE2E8B3")) IDataSource abstract : public IUnknown
    {
        virtual HRESULT STDMETHODCALLTYPE Advance(_COM_Outptr_result_maybenull_ IDataRow** ppDataRow) = 0;
        virtual HRESULT STDMETHODCALLTYPE Reset() = 0;
        virtual HRESULT STDMETHODCALLTYPE GetTestDataNames(_COM_Outptr_result_maybenull_ SAFEARRAY** ppTestDataNames) = 0;
        virtual HRESULT STDMETHODCALLTYPE GetTestDataType(BSTR pszName, _COM_Outptr_result_maybenull_ BSTR* ppszTypeName) = 0;
    };
}/* namespace TestExecution */}/* namespace WEX */

#pragma pop_macro("_COM_Outptr_result_maybenull_ ")
