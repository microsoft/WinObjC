//----------------------------------------------------------------------------------------------------------------------
/// \file
/// <summary>RunAs platform extensions for AppContainer and Tailored.</summary>
// Copyright (c) Microsoft Corporation.  All Rights Reserved.
//----------------------------------------------------------------------------------------------------------------------
#pragma once

#include "Wex.Common.h"
#include "WexString.h"

namespace WEX { namespace RunAsExtension
{
    struct ProcessInfo
    {
        ProcessInfo()
        : m_processHandle(0)
        , m_processId(0)
        {
        }

        ProcessInfo(HANDLE processHandle, unsigned long processId)
        : m_processHandle(processHandle)
        , m_processId(processId)
        {
        }

        void Reset()
        {
            m_processHandle = 0;
            m_processId = 0;
        }

        HANDLE m_processHandle;
        unsigned long m_processId;
    };
} /* namespace RunAsExtension */ } /* namespace WEX */

//
// CreateAppContainerProcess and its function type
//
extern "C"
WEX::RunAsExtension::ProcessInfo*
__stdcall
CreateAppContainerProcess(
    const WEX::Common::String& executableName,
    const WEX::Common::String& arguments,
    const WEX::Common::String& wpCapabilities);

typedef WEX::RunAsExtension::ProcessInfo*
(__stdcall *CreateAppContainerProcessFunction)(
    const WEX::Common::String& executableName,
    const WEX::Common::String& arguments,
    const WEX::Common::String& wpCapabilities);

//
// CreateTailoredProcess and its function type
//
extern "C"
WEX::RunAsExtension::ProcessInfo*
__stdcall
CreateTailoredProcess(
    const WEX::Common::String& arguments,
    const WEX::Common::String& packageFullName, 
    const WEX::Common::String& praid,
    const WEX::Common::String& debuggerString,
    const WEX::Common::String& host);

typedef WEX::RunAsExtension::ProcessInfo*
(__stdcall *CreateTailoredProcessFunction)(
    const WEX::Common::String& arguments,
    const WEX::Common::String& packageFullName, 
    const WEX::Common::String& praid,
    const WEX::Common::String& debuggerString,
    const WEX::Common::String& host);

//
// DeleteAppContainerProfile and its function type
//
extern "C"
HRESULT
__stdcall
ClearAppContainer(
    const WEX::Common::String& appContainerMoniker);

typedef HRESULT
(__stdcall *ClearAppContainerFunction)(
    const WEX::Common::String& appContainerMoniker);
