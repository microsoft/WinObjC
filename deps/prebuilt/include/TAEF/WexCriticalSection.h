//----------------------------------------------------------------------------------------------------------------------
/// \file
/// <summary>
/// An automatically-initialized critical section and its corresponding lock class.
/// 
/// </summary>
// Copyright (c) Microsoft Corporation.  All Rights Reserved.
//----------------------------------------------------------------------------------------------------------------------
#pragma once
#include "Wex.Common.h"

#include "WexAssert.h"

#include <Windows.h> // For the CRITICAL_SECTION definition

namespace WEX { namespace Common
{
    class CriticalSection
    {
    friend class CriticalSectionLock;

    public:
        typedef CriticalSectionLock Lock;

        CriticalSection()
        {
            ::ZeroMemory(&m_criticalSection, sizeof(CRITICAL_SECTION));

            // Note: A structured exception may be raised here in low memory situations on xp/win2k3 or lower systems,
            // but we are choosing not to handle it.  This simplifes the API by ensuring it is a 'non-throwing' critical section.
            #pragma prefast(suppress:__WARNING_PROBE_NO_TRY, "Intentionally not handling structured exception.")
            ::InitializeCriticalSection(&m_criticalSection); 
        }

        ~CriticalSection()
        {
            ::DeleteCriticalSection(&m_criticalSection);
        }

    private:
        void Enter()
        {
            // _Acquires_lock_ is not practical for an RAII lock class since if you use _Acquires_lock_ and put the class
            // in an generic container like std::unique_ptr, the analyzer will make you put _Acquires_lock_ on the container's
            // constructor. However, since the container is generic, it shouldn't be placed there since it would then apply
            // to every template argument.
            // The preprocessor is used to suppress since #pragma prefast(suppress) is not working here.
#if !defined(_PREFAST_)
            // Note: A structured exception may be raised here in low memory situations on win2k or lower systems,
            // but we are choosing not to handle it.  This simplifes the API by ensuring it is a 'non-throwing' critical section.
            ::EnterCriticalSection(&m_criticalSection);
#endif
        }

        void Leave()
        {
#if !defined(_PREFAST_)
            ::LeaveCriticalSection(&m_criticalSection);
#endif
        }

        PCRITICAL_SECTION GetCriticalSection()
        {
            return &m_criticalSection;
        }

        CriticalSection(const CriticalSection&); // not implemented
        CriticalSection& operator=(const CriticalSection&); // not implemented

        CRITICAL_SECTION m_criticalSection;
    };

    class CriticalSectionLock
    {
        friend class ConditionVariable;
    public:
        explicit CriticalSectionLock(CriticalSection& criticalSection)
            : m_pCriticalSection(&criticalSection)
        {
            criticalSection.Enter();
        }

#if !defined(_MSC_VER) || (_MSC_VER >= 1600)
        CriticalSectionLock(CriticalSectionLock&& other)
            : m_pCriticalSection(other.m_pCriticalSection)
        {
            other.m_pCriticalSection = nullptr;
        }
#endif

        ~CriticalSectionLock()
        {
            if (m_pCriticalSection)
            {
                m_pCriticalSection->Leave();
            }
        }

    private:
        CriticalSectionLock(const CriticalSectionLock&);
        CriticalSectionLock& operator=(const CriticalSectionLock&);

        PCRITICAL_SECTION GetCriticalSection()
        {
            return m_pCriticalSection->GetCriticalSection();
        }

        CriticalSection* m_pCriticalSection;
    };
}/* namespace Common */}/* namespace WEX */
