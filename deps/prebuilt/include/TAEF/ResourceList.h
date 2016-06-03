/*
* Copyright (c) Microsoft Corporation. All rights reserved.
*
*
*/
#pragma once
#include "TE.Common.h"
#include "ITestResource.h"

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

#pragma push_macro("_In_")
#pragma push_macro("_Outptr_")

#if !defined(_In_)
#define _In_
#endif

#if !defined(_Outptr_)
#define _Outptr_
#endif

namespace WEX { namespace TestExecution
{
    class ResourceListImpl;

    // Interface to add TestResources to the list in the BuildResourceList implementation
    class TECOMMON_API ResourceList SEALED
    {
        friend struct ResourceListFactory;
        UNIT_TEST_CLASS(WEX::UnitTests::TestResourceDataSourceTests);
        UNIT_TEST_CLASS(WEX::UnitTests::DynamicTreeTests);

    public:
        HRESULT Add(_In_ ITestResource* pTestResource);
        ULONG Count();
        HRESULT Item(ULONG index, _Outptr_ ITestResource** ppTestResource);

    private:
        ResourceList();
        ~ResourceList();
        ResourceList(const ResourceList&); // non-implemented
        ResourceList& operator=(const ResourceList&); // non-implemented
    };

    // Class to retrieve the TestResources for the current invocation of the test method in concern.
    class TECOMMON_API Resources SEALED
    {
    public:
        static ULONG __stdcall Count();
        static HRESULT __stdcall Item(size_t index, _Outptr_ ITestResource** ppTestResource);

    private:
        Resources(){};
        ~Resources(){};
        Resources(const Resources&); // non-implemented
        Resources& operator=(const Resources&); // non-implemented
    };

    // Internal definition for BuildResourceList
    typedef HRESULT (__cdecl *BuildResourceListFunction)(ResourceList&);
} /*namespace TestExecution*/ } /*namespace WEX*/

// dll-exported function that users implement for each TestResource dependent test module - should be out of all namespaces
extern "C" __declspec(dllexport) HRESULT __cdecl BuildResourceList(WEX::TestExecution::ResourceList& resouceList);

#pragma pop_macro("SEALED")
#pragma pop_macro("_In_")
#pragma pop_macro("_Outptr_")
